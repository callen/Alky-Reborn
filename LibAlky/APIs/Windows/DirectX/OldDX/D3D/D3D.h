/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
 */

#ifndef __APIS_WINDOWS_DTHREED_DTHREED_H__
#define __APIS_WINDOWS_DTHREED_DTHREED_H__

#include <APIs/Windows/Windows.h>
#include <APIs/Windows/COM/COM.h>
#include <APIs/Windows/User32/User32.h>

#define MAKEFOURCC(a,b,c,d)  \
    ((DWORD)(BYTE)(a) | ((DWORD)(BYTE)(b) << 8) |  \
    ((DWORD)(BYTE)(c) << 16) | ((DWORD)(BYTE)(d) << 24 ))

typedef enum _D3DDEVTYPE {
    D3DDEVTYPE_HAL = 1,
    D3DDEVTYPE_REF = 2,
    D3DDEVTYPE_SW = 3,
    D3DDEVTYPE_FORCE_DWORD = 0xffffffff
} D3DDEVTYPE;

typedef enum _D3DFORMAT {
    D3DFMT_UNKNOWN = 0,
    D3DFMT_R8G8B8 = 20,
    D3DFMT_A8R8G8B8 = 21,
    D3DFMT_X8R8G8B8 = 22,
    D3DFMT_R5G6B5 = 23,
    D3DFMT_X1R5G5B5 = 24,
    D3DFMT_A1R5G5B5 = 25,
    D3DFMT_A4R4G4B4 = 26,
    D3DFMT_R3G3B2 = 27,
    D3DFMT_A8 = 28,
    D3DFMT_A8R3G3B2 = 29,
    D3DFMT_X4R4G4B4 = 30,
    D3DFMT_A2B10G10R10 = 31,
    D3DFMT_A8B8G8R8 = 32,
    D3DFMT_X8B8G8R8 = 33,
    D3DFMT_G16R16 = 34,
    D3DFMT_A2R10G10B10 = 35,
    D3DFMT_A16B16G16R16 = 36,
    D3DFMT_A8P8 = 40,
    D3DFMT_P8 = 41,
    D3DFMT_L8 = 50,
    D3DFMT_A8L8 = 51,
    D3DFMT_A4L4 = 52,
    D3DFMT_V8U8 = 60,
    D3DFMT_L6V5U5 = 61,
    D3DFMT_X8L8V8U8 = 62,
    D3DFMT_Q8W8V8U8 = 63,
    D3DFMT_V16U16 = 64,
    D3DFMT_A2W10V10U10 = 67,
    D3DFMT_UYVY = MAKEFOURCC('U','Y','V','Y'),
    D3DFMT_R8G8_B8G8 = MAKEFOURCC('R','G','B','G'),
    D3DFMT_YUY2 = MAKEFOURCC('Y','U','Y','2'),
    D3DFMT_G8R8_G8B8 = MAKEFOURCC('G','R','G','B'),
    D3DFMT_DXT1 = MAKEFOURCC('D','X','T','1'),
    D3DFMT_DXT2 = MAKEFOURCC('D','X','T','2'),
    D3DFMT_DXT3 = MAKEFOURCC('D','X','T','3'),
    D3DFMT_DXT4 = MAKEFOURCC('D','X','T','4'),
    D3DFMT_DXT5 = MAKEFOURCC('D','X','T','5'),
    D3DFMT_D16_LOCKABLE = 70,
    D3DFMT_D32 = 71,
    D3DFMT_D15S1 = 73,
    D3DFMT_D24S8 = 75,
    D3DFMT_D24X8 = 77,
    D3DFMT_D24X4S4 = 79,
    D3DFMT_D16 = 80,
    D3DFMT_L16 = 81,
    D3DFMT_D32F_LOCKABLE = 82,
    D3DFMT_D24FS8 = 83,
    D3DFMT_VERTEXDATA = 100,
    D3DFMT_INDEX16 = 101,
    D3DFMT_INDEX32 = 102,
    D3DFMT_Q16W16V16U16 = 110,
    D3DFMT_MULTI2_ARGB8 = MAKEFOURCC('M','E','T','1'),
    D3DFMT_R16F = 111,
    D3DFMT_G16R16F = 112,
    D3DFMT_A16B16G16R16F = 113,
    D3DFMT_R32F = 114,
    D3DFMT_G32R32F = 115,
    D3DFMT_A32B32G32R32F = 116,
    D3DFMT_CxV8U8 = 117,
    D3DFMT_FORCE_DWORD = 0xffffffff
} D3DFORMAT;

typedef enum _D3DRESOURCETYPE {
    D3DRTYPE_SURFACE = 1,
    D3DRTYPE_VOLUME = 2,
    D3DRTYPE_TEXTURE = 3,
    D3DRTYPE_VOLUMETEXTURE = 4,
    D3DRTYPE_CUBETEXTURE = 5,
    D3DRTYPE_VERTEXBUFFER = 6,
    D3DRTYPE_INDEXBUFFER = 7,
    D3DRTYPE_FORCE_DWORD = 0x7fffffff
} D3DRESOURCETYPE;

typedef enum _D3DMULTISAMPLE_TYPE {
    D3DMULTISAMPLE_NONE = 0,
    D3DMULTISAMPLE_NONMASKABLE = 1,
    D3DMULTISAMPLE_2_SAMPLES = 2,
    D3DMULTISAMPLE_3_SAMPLES = 3,
    D3DMULTISAMPLE_4_SAMPLES = 4,
    D3DMULTISAMPLE_5_SAMPLES = 5,
    D3DMULTISAMPLE_6_SAMPLES = 6,
    D3DMULTISAMPLE_7_SAMPLES = 7,
    D3DMULTISAMPLE_8_SAMPLES = 8,
    D3DMULTISAMPLE_9_SAMPLES = 9,
    D3DMULTISAMPLE_10_SAMPLES = 10,
    D3DMULTISAMPLE_11_SAMPLES = 11,
    D3DMULTISAMPLE_12_SAMPLES = 12,
    D3DMULTISAMPLE_13_SAMPLES = 13,
    D3DMULTISAMPLE_14_SAMPLES = 14,
    D3DMULTISAMPLE_15_SAMPLES = 15,
    D3DMULTISAMPLE_16_SAMPLES = 16,
    D3DMULTISAMPLE_FORCE_DWORD = 0xffffffff
} D3DMULTISAMPLE_TYPE;

typedef enum _D3DSWAPEFFECT {
    D3DSWAPEFFECT_DISCARD = 1,
    D3DSWAPEFFECT_FLIP = 2,
    D3DSWAPEFFECT_COPY = 3,
    D3DSWAPEFFECT_FORCE_DWORD = 0xFFFFFFFF
} D3DSWAPEFFECT;

typedef struct _D3DPRESENT_PARAMETERS_ {
    UINT BackBufferWidth, BackBufferHeight;
    D3DFORMAT BackBufferFormat;
    UINT BackBufferCount;
    D3DMULTISAMPLE_TYPE MultiSampleType;
    DWORD MultiSampleQuality;
    D3DSWAPEFFECT SwapEffect;
    HWND hDeviceWindow;
    BOOL Windowed;
    BOOL EnableAutoDepthStencil;
    D3DFORMAT AutoDepthStencilFormat;
    DWORD Flags;
    UINT FullScreen_RefreshRateInHz;
    UINT PresentationInterval;
} D3DPRESENT_PARAMETERS;

typedef enum _D3DTRANSFORMSTATETYPE {
    D3DTS_VIEW = 2,
    D3DTS_PROJECTION = 3,
    D3DTS_TEXTURE0 = 16,
    D3DTS_TEXTURE1 = 17,
    D3DTS_TEXTURE2 = 18,
    D3DTS_TEXTURE3 = 19,
    D3DTS_TEXTURE4 = 20,
    D3DTS_TEXTURE5 = 21,
    D3DTS_TEXTURE6 = 22,
    D3DTS_TEXTURE7 = 23,
    D3DTS_FORCE_DWORD = 0x7fffffff
} D3DTRANSFORMSTATETYPE;

typedef enum _D3DCULL {
    D3DCULL_NONE                = 1,
    D3DCULL_CW                  = 2,
    D3DCULL_CCW                 = 3,
    D3DCULL_FORCE_DWORD         = 0x7fffffff, /* force 32-bit size enum */
} D3DCULL;

typedef enum _D3DRENDERSTATETYPE {
    D3DRS_ZENABLE = 7,
    D3DRS_FILLMODE = 8,
    D3DRS_SHADEMODE = 9,
    D3DRS_ZWRITEENABLE = 14,
    D3DRS_ALPHATESTENABLE = 15,
    D3DRS_LASTPIXEL = 16,
    D3DRS_SRCBLEND = 19,
    D3DRS_DESTBLEND = 20,
    D3DRS_CULLMODE = 22,
    D3DRS_ZFUNC = 23,
    D3DRS_ALPHAREF = 24,
    D3DRS_ALPHAFUNC = 25,
    D3DRS_DITHERENABLE = 26,
    D3DRS_ALPHABLENDENABLE = 27,
    D3DRS_FOGENABLE = 28,
    D3DRS_SPECULARENABLE = 29,
    D3DRS_FOGCOLOR = 34,
    D3DRS_FOGTABLEMODE = 35,
    D3DRS_FOGSTART = 36,
    D3DRS_FOGEND = 37,
    D3DRS_FOGDENSITY = 38,
    D3DRS_RANGEFOGENABLE = 48,
    D3DRS_STENCILENABLE = 52,
    D3DRS_STENCILFAIL = 53,
    D3DRS_STENCILZFAIL = 54,
    D3DRS_STENCILPASS = 55,
    D3DRS_STENCILFUNC = 56,
    D3DRS_STENCILREF = 57,
    D3DRS_STENCILMASK = 58,
    D3DRS_STENCILWRITEMASK = 59,
    D3DRS_TEXTUREFACTOR = 60,
    D3DRS_WRAP0 = 128,
    D3DRS_WRAP1 = 129,
    D3DRS_WRAP2 = 130,
    D3DRS_WRAP3 = 131,
    D3DRS_WRAP4 = 132,
    D3DRS_WRAP5 = 133,
    D3DRS_WRAP6 = 134,
    D3DRS_WRAP7 = 135,
    D3DRS_CLIPPING = 136,
    D3DRS_LIGHTING = 137,
    D3DRS_AMBIENT = 139,
    D3DRS_FOGVERTEXMODE = 140,
    D3DRS_COLORVERTEX = 141,
    D3DRS_LOCALVIEWER = 142,
    D3DRS_NORMALIZENORMALS = 143,
    D3DRS_DIFFUSEMATERIALSOURCE = 145,
    D3DRS_SPECULARMATERIALSOURCE = 146,
    D3DRS_AMBIENTMATERIALSOURCE = 147,
    D3DRS_EMISSIVEMATERIALSOURCE = 148,
    D3DRS_VERTEXBLEND = 151,
    D3DRS_CLIPPLANEENABLE = 152,
    D3DRS_POINTSIZE = 154,
    D3DRS_POINTSIZE_MIN = 155,
    D3DRS_POINTSPRITEENABLE = 156,
    D3DRS_POINTSCALEENABLE = 157,
    D3DRS_POINTSCALE_A = 158,
    D3DRS_POINTSCALE_B = 159,
    D3DRS_POINTSCALE_C = 160,
    D3DRS_MULTISAMPLEANTIALIAS = 161,
    D3DRS_MULTISAMPLEMASK = 162,
    D3DRS_PATCHEDGESTYLE = 163,
    D3DRS_DEBUGMONITORTOKEN = 165,
    D3DRS_POINTSIZE_MAX = 166,
    D3DRS_INDEXEDVERTEXBLENDENABLE = 167,
    D3DRS_COLORWRITEENABLE = 168,
    D3DRS_TWEENFACTOR = 170,
    D3DRS_BLENDOP = 171,
    D3DRS_POSITIONDEGREE = 172,
    D3DRS_NORMALDEGREE = 173,
    D3DRS_SCISSORTESTENABLE = 174,
    D3DRS_SLOPESCALEDEPTHBIAS = 175,
    D3DRS_ANTIALIASEDLINEENABLE = 176,
    D3DRS_MINTESSELLATIONLEVEL = 178,
    D3DRS_MAXTESSELLATIONLEVEL = 179,
    D3DRS_ADAPTIVETESS_X = 180,
    D3DRS_ADAPTIVETESS_Y = 181,
    D3DRS_ADAPTIVETESS_Z = 182,
    D3DRS_ADAPTIVETESS_W = 183,
    D3DRS_ENABLEADAPTIVETESSELLATION = 184,
    D3DRS_TWOSIDEDSTENCILMODE = 185,
    D3DRS_CCW_STENCILFAIL = 186,
    D3DRS_CCW_STENCILZFAIL = 187,
    D3DRS_CCW_STENCILPASS = 188,
    D3DRS_CCW_STENCILFUNC = 189,
    D3DRS_COLORWRITEENABLE1 = 190,
    D3DRS_COLORWRITEENABLE2 = 191,
    D3DRS_COLORWRITEENABLE3 = 192,
    D3DRS_BLENDFACTOR = 193,
    D3DRS_SRGBWRITEENABLE = 194,
    D3DRS_DEPTHBIAS = 195,
    D3DRS_WRAP8 = 198,
    D3DRS_WRAP9 = 199,
    D3DRS_WRAP10 = 200,
    D3DRS_WRAP11 = 201,
    D3DRS_WRAP12 = 202,
    D3DRS_WRAP13 = 203,
    D3DRS_WRAP14 = 204,
    D3DRS_WRAP15 = 205,
    D3DRS_SEPARATEALPHABLENDENABLE = 206,
    D3DRS_SRCBLENDALPHA = 207,
    D3DRS_DESTBLENDALPHA = 208,
    D3DRS_BLENDOPALPHA = 209,
    D3DRS_FORCE_DWORD = 0x7fffffff
} D3DRENDERSTATETYPE;

typedef enum _D3DCMPFUNC {
    D3DCMP_NEVER                = 1,
    D3DCMP_LESS                 = 2,
    D3DCMP_EQUAL                = 3,
    D3DCMP_LESSEQUAL            = 4,
    D3DCMP_GREATER              = 5,
    D3DCMP_NOTEQUAL             = 6,
    D3DCMP_GREATEREQUAL         = 7,
    D3DCMP_ALWAYS               = 8,
    D3DCMP_FORCE_DWORD          = 0x7fffffff,
} D3DCMPFUNC;

typedef enum D3DFILLMODE {
    D3DFILL_POINT = 1,
    D3DFILL_WIREFRAME = 2,
    D3DFILL_SOLID = 3,
    D3DFILL_FORCE_DWORD = 0x7FFFFFFF,
} D3DFILLMODE,
 *LPD3DFILLMODE;

typedef enum D3DSHADEMODE {
    D3DSHADE_FLAT = 1,
    D3DSHADE_GOURAUD = 2,
    D3DSHADE_PHONG = 3,
    D3DSHADE_FORCE_DWORD = 0x7FFFFFFF,
} D3DSHADEMODE,
 *LPD3DSHADEMODE;

typedef enum D3DZBUFFERTYPE {
    D3DZB_FALSE = 0,
    D3DZB_TRUE = 1,
    D3DZB_USEW = 2,
    D3DZB_FORCE_DWORD = 0x7FFFFFFF,
} D3DZBUFFERTYPE,
 *LPD3DZBUFFERTYPE;

typedef enum _D3DFOGMODE {
    D3DFOG_NONE                 = 0,
    D3DFOG_EXP                  = 1,
    D3DFOG_EXP2                 = 2,
    D3DFOG_LINEAR               = 3,
    D3DFOG_FORCE_DWORD          = 0x7fffffff,
} D3DFOGMODE;

typedef enum _D3DTEXTURESTAGESTATETYPE
{
    D3DTSS_COLOROP        =  1, /* D3DTEXTUREOP - per-stage blending controls for color channels */
    D3DTSS_COLORARG1      =  2, /* D3DTA_* (texture arg) */
    D3DTSS_COLORARG2      =  3, /* D3DTA_* (texture arg) */
    D3DTSS_ALPHAOP        =  4, /* D3DTEXTUREOP - per-stage blending controls for alpha channel */
    D3DTSS_ALPHAARG1      =  5, /* D3DTA_* (texture arg) */
    D3DTSS_ALPHAARG2      =  6, /* D3DTA_* (texture arg) */
    D3DTSS_BUMPENVMAT00   =  7, /* float (bump mapping matrix) */
    D3DTSS_BUMPENVMAT01   =  8, /* float (bump mapping matrix) */
    D3DTSS_BUMPENVMAT10   =  9, /* float (bump mapping matrix) */
    D3DTSS_BUMPENVMAT11   = 10, /* float (bump mapping matrix) */
    D3DTSS_TEXCOORDINDEX  = 11, /* identifies which set of texture coordinates index this texture */
    D3DTSS_BUMPENVLSCALE  = 22, /* float scale for bump map luminance */
    D3DTSS_BUMPENVLOFFSET = 23, /* float offset for bump map luminance */
    D3DTSS_TEXTURETRANSFORMFLAGS = 24, /* D3DTEXTURETRANSFORMFLAGS controls texture transform */
    D3DTSS_COLORARG0      = 26, /* D3DTA_* third arg for triadic ops */
    D3DTSS_ALPHAARG0      = 27, /* D3DTA_* third arg for triadic ops */
    D3DTSS_RESULTARG      = 28, /* D3DTA_* arg for result (CURRENT or TEMP) */
    D3DTSS_CONSTANT       = 32, /* Per-stage constant D3DTA_CONSTANT */
    D3DTSS_FORCE_DWORD   = 0x7fffffff, /* force 32-bit size enum */
} D3DTEXTURESTAGESTATETYPE;

typedef enum _D3DSAMPLERSTATETYPE
{
    D3DSAMP_ADDRESSU       = 1,  /* D3DTEXTUREADDRESS for U coordinate */
    D3DSAMP_ADDRESSV       = 2,  /* D3DTEXTUREADDRESS for V coordinate */
    D3DSAMP_ADDRESSW       = 3,  /* D3DTEXTUREADDRESS for W coordinate */
    D3DSAMP_BORDERCOLOR    = 4,  /* D3DCOLOR */
    D3DSAMP_MAGFILTER      = 5,  /* D3DTEXTUREFILTER filter to use for magnification */
    D3DSAMP_MINFILTER      = 6,  /* D3DTEXTUREFILTER filter to use for minification */
    D3DSAMP_MIPFILTER      = 7,  /* D3DTEXTUREFILTER filter to use between mipmaps during minification */
    D3DSAMP_MIPMAPLODBIAS  = 8,  /* float Mipmap LOD bias */
    D3DSAMP_MAXMIPLEVEL    = 9,  /* DWORD 0..(n-1) LOD index of largest map to use (0 == largest) */
    D3DSAMP_MAXANISOTROPY  = 10, /* DWORD maximum anisotropy */
    D3DSAMP_SRGBTEXTURE    = 11, /* Default = 0 (which means Gamma 1.0,
                                   no correction required.) else correct for
                                   Gamma = 2.2 */
    D3DSAMP_ELEMENTINDEX   = 12, /* When multi-element texture is assigned to sampler, this
                                    indicates which element index to use.  Default = 0.  */
    D3DSAMP_DMAPOFFSET     = 13, /* Offset in vertices in the pre-sampled displacement map.
                                    Only valid for D3DDMAPSAMPLER sampler  */
    D3DSAMP_FORCE_DWORD   = 0x7fffffff, /* force 32-bit size enum */
} D3DSAMPLERSTATETYPE;

typedef enum _D3DCUBEMAP_FACES
{
    D3DCUBEMAP_FACE_POSITIVE_X     = 0,
    D3DCUBEMAP_FACE_NEGATIVE_X     = 1,
    D3DCUBEMAP_FACE_POSITIVE_Y     = 2,
    D3DCUBEMAP_FACE_NEGATIVE_Y     = 3,
    D3DCUBEMAP_FACE_POSITIVE_Z     = 4,
    D3DCUBEMAP_FACE_NEGATIVE_Z     = 5,
    
    D3DCUBEMAP_FACE_FORCE_DWORD    = 0x7fffffff
} D3DCUBEMAP_FACES;

typedef enum _D3DPOOL {
    D3DPOOL_DEFAULT = 0,
    D3DPOOL_MANAGED = 1,
    D3DPOOL_SYSTEMMEM = 2,
    D3DPOOL_SCRATCH = 3,
    D3DPOOL_FORCE_DWORD = 0x7fffffff
} D3DPOOL;

typedef enum _D3DPRIMITIVETYPE {
    D3DPT_POINTLIST = 1,
    D3DPT_LINELIST = 2,
    D3DPT_LINESTRIP = 3,
    D3DPT_TRIANGLELIST = 4,
    D3DPT_TRIANGLESTRIP = 5,
    D3DPT_TRIANGLEFAN = 6,
    D3DPT_FORCE_DWORD = 0x7fffffff
} D3DPRIMITIVETYPE;

typedef struct _D3DMATRIX {
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
} D3DMATRIX;

typedef struct _D3DRECT {
    LONG x1, y1;
    LONG x2, y2;
} D3DRECT;

#define MAX_DEVICE_IDENTIFIER_STRING	512

typedef struct _D3DADAPTER_IDENTIFIER9 {
	char Driver[MAX_DEVICE_IDENTIFIER_STRING];
	char Description[MAX_DEVICE_IDENTIFIER_STRING];
	char DeviceName[32];
	LARGE_INTEGER DriverVersion;
    DWORD VendorId;
    DWORD DeviceId;
    DWORD SubSysId;
    DWORD Revision;
    GUID DeviceIdentifier;
    DWORD WHQLLevel;
} D3DADAPTER_IDENTIFIER9;

typedef struct _D3DDISPLAYMODE {
	UINT Width;
	UINT Height;
	UINT RefreshRate;
	D3DFORMAT Format;
} D3DDISPLAYMODE;

typedef struct _D3DVSHADERCAPS2_0 {
	DWORD Caps;
	INT DynamicFlowControlDepth;
	INT NumTemps;
	INT StaticFlowControlDepth;
} D3DVSHADERCAPS2_0;

typedef struct _D3DPSHADERCAPS2_0 {
	DWORD Caps;
	INT DynamicFlowControlDepth;
	INT NumTemps;
	INT StaticFlowControlDepth;
	INT NumInstructionSlots;
} D3DPSHADERCAPS2_0;

typedef struct _D3DCAPS9 {
	D3DDEVTYPE DeviceType;
	UINT AdapterOrdinal;
	DWORD Caps;
	DWORD Caps2;
	DWORD Caps3;
	DWORD PresentationIntervals;
	DWORD CursorCaps;
	DWORD DevCaps;
	DWORD PrimitiveMiscCaps;
	DWORD RasterCaps;
	DWORD ZCmpCaps;
	DWORD SrcBlendCaps;
	DWORD DestBlendCaps;
	DWORD AlphaCmpCaps;
	DWORD ShadeCaps;
	DWORD TextureCaps;
	DWORD TextureFilterCaps;
	DWORD CubeTextureFilterCaps;
	DWORD VolumeTextureFilterCaps;
	DWORD TextureAddressCaps;
	DWORD VolumeTextureAddressCaps;
	DWORD LineCaps;
	DWORD MaxTextureWidth;
	DWORD MaxTextureHeight;
	DWORD MaxVolumeExtent;
	DWORD MaxTextureRepeat;
	DWORD MaxTextureAspectRatio;
	DWORD MaxAnisotropy;
	float MaxVertexW;
	float GuardBandLeft;
	float GuardBandTop;
	float GuardBandRight;
	float GuardBandBottom;
	float ExtentsAdjust;
	DWORD StencilCaps;
	DWORD FVFCaps;
	DWORD TextureOpCaps;
	DWORD MaxTextureBlendStages;
	DWORD MaxSimultaneousTextures;
	DWORD VertexProcessingCaps;
	DWORD MaxActiveLights;
	DWORD MaxUserClipPlanes;
	DWORD MaxVertexBlendMatrices;
	DWORD MaxVertexBlendMatrixIndex;
	float MaxPointSize;
	DWORD MaxPrimitiveCount;
	DWORD MaxVertexIndex;
	DWORD MaxStreams;
	DWORD MaxStreamStride;
	DWORD VertexShaderVersion;
	DWORD MaxVertexShaderConst;
	DWORD PixelShaderVersion;
	float PixelShader1xMaxValue;
	DWORD DevCaps2;
	float MaxNpatchTessellationLevel;
	DWORD Reserved5;
	UINT MasterAdapterOrdinal;
	UINT AdapterOrdinalInGroup;
	UINT NumberOfAdaptersInGroup;
	DWORD DeclTypes;
	DWORD NumSimultaneousRTs;
	DWORD StretchRectFilterCaps;
	D3DVSHADERCAPS2_0 VS20Caps;
	D3DPSHADERCAPS2_0 PS20Caps;
	DWORD VertexTextureFilterCaps;
	DWORD MaxVShaderInstructionsExecuted;
	DWORD MaxPShaderInstructionsExecuted;
	DWORD MaxVertexShader30InstructionSlots;
	DWORD MaxPixelShader30InstructionSlots;
} D3DCAPS9;

typedef struct D3DSURFACE_DESC {
    D3DFORMAT Format;
    D3DRESOURCETYPE Type;
    DWORD Usage;
    D3DPOOL Pool;
    D3DMULTISAMPLE_TYPE MultiSampleType;
    DWORD MultiSampleQuality;
    UINT Width;
    UINT Height;
} D3DSURFACE_DESC,
 *LPD3DSURFACE_DESC;

typedef struct D3DLOCKED_RECT {
    INT Pitch;
    unsigned char *pBits;
} D3DLOCKED_RECT,
 *LPD3DLOCKED_RECT;

typedef struct D3DVIEWPORT9 {
    DWORD X;
    DWORD Y;
    DWORD Width;
    DWORD Height;
    float MinZ;
    float MaxZ;
} D3DVIEWPORT9,
 *LPD3DVIEWPORT9;

typedef struct _D3DCOLORVALUE {
	union {
		float r, g, b, a;
		GLfloat value[4];
	};
} D3DCOLORVALUE;

#define D3DCOLORVALUE_NONZERO(val) (val[0] != 0.0f || val[1] != 0.0f || val[2] != 0.0f || val[3] != 0.0f)
#define D3DCOLORVALUE_EQUAL(a, b) \
( \
	a.value[0] == b.value[0] && \
	a.value[1] == b.value[1] && \
	a.value[2] == b.value[2] && \
	a.value[3] == b.value[3] \
)

typedef struct _D3DMATERIAL9 {
    D3DCOLORVALUE   Diffuse;        /* Diffuse color RGBA */
    D3DCOLORVALUE   Ambient;        /* Ambient color RGB */
    D3DCOLORVALUE   Specular;       /* Specular 'shininess' */
    D3DCOLORVALUE   Emissive;       /* Emissive color RGB */
    float           Power;          /* Sharpness if specular highlight */
} D3DMATERIAL9;

typedef enum _D3DLIGHTTYPE {
    D3DLIGHT_POINT          = 1,
    D3DLIGHT_SPOT           = 2,
    D3DLIGHT_DIRECTIONAL    = 3,
    D3DLIGHT_FORCE_DWORD    = 0x7fffffff, /* force 32-bit size enum */
} D3DLIGHTTYPE;

typedef struct _D3DVECTOR {
	union{
		float x, y, z;
		GLfloat vec[3];
	};
} D3DVECTOR;

typedef struct _D3DLIGHT9 {
    D3DLIGHTTYPE    Type;            /* Type of light source */
    D3DCOLORVALUE   Diffuse;         /* Diffuse color of light */
    D3DCOLORVALUE   Specular;        /* Specular color of light */
    D3DCOLORVALUE   Ambient;         /* Ambient color of light */
    D3DVECTOR       Position;         /* Position in world space */
    D3DVECTOR       Direction;        /* Direction in world space */
    float           Range;            /* Cutoff range */
    float           Falloff;          /* Falloff */
    float           Attenuation0;     /* Constant attenuation */
    float           Attenuation1;     /* Linear attenuation */
    float           Attenuation2;     /* Quadratic attenuation */
    float           Theta;            /* Inner angle of spotlight cone */
    float           Phi;              /* Outer angle of spotlight cone */
} D3DLIGHT9;

typedef DWORD D3DCOLOR;

/*
  3.  STDMETHOD(RegisterSoftwareDevice)(THIS_ void* pInitializeFunction) PURE;
  4.  STDMETHOD_(UINT, GetAdapterCount)(THIS) PURE;
  5.  STDMETHOD(GetAdapterIdentifier)(THIS_ UINT Adapter,DWORD Flags,D3DADAPTER_IDENTIFIER9* pIdentifier) PURE;
  6.  STDMETHOD_(UINT, GetAdapterModeCount)(THIS_ UINT Adapter,D3DFORMAT Format) PURE;
  7.  STDMETHOD(EnumAdapterModes)(THIS_ UINT Adapter,D3DFORMAT Format,UINT Mode,D3DDISPLAYMODE* pMode) PURE;
  8.  STDMETHOD(GetAdapterDisplayMode)(THIS_ UINT Adapter,D3DDISPLAYMODE* pMode) PURE;
  9.  STDMETHOD(CheckDeviceType)(THIS_ UINT Adapter,D3DDEVTYPE DevType,D3DFORMAT AdapterFormat,D3DFORMAT BackBufferFormat,BOOL bWindowed) PURE;
 10.  STDMETHOD(CheckDeviceFormat)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,DWORD Usage,D3DRESOURCETYPE RType,D3DFORMAT CheckFormat) PURE;
 11.  STDMETHOD(CheckDeviceMultiSampleType)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SurfaceFormat,BOOL Windowed,D3DMULTISAMPLE_TYPE MultiSampleType,DWORD* pQualityLevels) PURE;
 12.  STDMETHOD(CheckDepthStencilMatch)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,D3DFORMAT RenderTargetFormat,D3DFORMAT DepthStencilFormat) PURE;
 13.  STDMETHOD(CheckDeviceFormatConversion)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SourceFormat,D3DFORMAT TargetFormat) PURE;
 14.  STDMETHOD(GetDeviceCaps)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DCAPS9* pCaps) PURE;
 15.  STDMETHOD_(HMONITOR, GetAdapterMonitor)(THIS_ UINT Adapter) PURE;
 16.  STDMETHOD(CreateDevice)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DDevice9** ppReturnedDeviceInterface) PURE;
*/

WINAPI void *Direct3DCreate9(
    UINT SDKVersion
);

WINAPI HRESULT IDirect3D9_Release(
    void *this_
);

WINAPI UINT IDirect3D9_GetAdapterCount(
    void *this_
);

WINAPI HRESULT IDirect3D9_GetAdapterIdentifier(
    void *this_,
    UINT Adapter,
    DWORD Flags,
    D3DADAPTER_IDENTIFIER9 *pIdentifier
);

WINAPI UINT IDirect3D9_GetAdapterModeCount(
    void *this_,
    UINT Adapter,
    D3DFORMAT Format
);

WINAPI HRESULT IDirect3D9_EnumAdapterModes(
    void *this_,
    UINT Adapter,
    D3DFORMAT Format,
    UINT Mode,
    D3DDISPLAYMODE *pMode
);

WINAPI HRESULT IDirect3D9_GetAdapterDisplayMode(
    void *this_,
    UINT Adapter,
    D3DDISPLAYMODE *pMode
);

WINAPI HRESULT IDirect3D9_CheckDeviceType(
    void *this_,
    UINT Adapter,
    D3DDEVTYPE DevType,
    D3DFORMAT AdapterFormat,
    D3DFORMAT BackBufferFormat,
    BOOL bWindowed
);

WINAPI HRESULT IDirect3D9_CheckDeviceFormat(
    void *this_,
    UINT Adapter,
    D3DDEVTYPE DeviceType,
    D3DFORMAT AdapterFormat,
    DWORD Usage,
    D3DRESOURCETYPE RType,
    D3DFORMAT CheckFormat
);

WINAPI HRESULT IDirect3D9_CheckDeviceMultiSampleType(
    void *this_,
    UINT Adapter,
    D3DDEVTYPE DeviceType,
    D3DFORMAT SurfaceFormat,
    BOOL Windowed,
    D3DMULTISAMPLE_TYPE MultiSampleType,
    DWORD* pQualityLevels
);

WINAPI HRESULT IDirect3D9_CheckDepthStencilMatch(
    void *this_,
    UINT Adapter,
    D3DDEVTYPE DeviceType,
    D3DFORMAT AdapterFormat,
    D3DFORMAT RenderTargetFormat,
    D3DFORMAT DepthStencilFormat
);

WINAPI HRESULT IDirect3D9_GetDeviceCaps(
    void *this_,
    UINT Adapter,
    D3DDEVTYPE DeviceType,
    D3DCAPS9 *pCaps
);

WINAPI HRESULT IDirect3D9_CreateDevice(
    void *this_,
    UINT Adapter,
    D3DDEVTYPE DeviceType,
    HWND hFocusWindow,
    DWORD BehaviorFlags,
    D3DPRESENT_PARAMETERS *pPresentationParameters,
    void** ppReturnedDeviceInterface
);

/*
'   3.  STDMETHOD(TestCooperativeLevel)(THIS) PURE;
'   4.  STDMETHOD_(UINT, GetAvailableTextureMem)(THIS) PURE;
'   5.  STDMETHOD(EvictManagedResources)(THIS) PURE;
'   6.  STDMETHOD(GetDirect3D)(THIS_ IDirect3D9** ppD3D9) PURE;
'   7.  STDMETHOD(GetDeviceCaps)(THIS_ D3DCAPS9* pCaps) PURE;
'   8.  STDMETHOD(GetDisplayMode)(THIS_ UINT iSwapChain,D3DDISPLAYMODE* pMode) PURE;
'   9.  STDMETHOD(GetCreationParameters)(THIS_ D3DDEVICE_CREATION_PARAMETERS *pParameters) PURE;
'  10.  STDMETHOD(SetCursorProperties)(THIS_ UINT XHotSpot,UINT YHotSpot,IDirect3DSurface9* pCursorBitmap) PURE;
'  11.  STDMETHOD_(void, SetCursorPosition)(THIS_ int X,int Y,DWORD Flags) PURE;
'  12.  STDMETHOD_(BOOL, ShowCursor)(THIS_ BOOL bShow) PURE;
'  13.  STDMETHOD(CreateAdditionalSwapChain)(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DSwapChain9** pSwapChain) PURE;
'  14.  STDMETHOD(GetSwapChain)(THIS_ UINT iSwapChain,IDirect3DSwapChain9** pSwapChain) PURE;
'  15.  STDMETHOD_(UINT, GetNumberOfSwapChains)(THIS) PURE;
'  16.  STDMETHOD(Reset)(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters) PURE;
'  17.  STDMETHOD(Present)(THIS_ CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion) PURE;
'  18.  STDMETHOD(GetBackBuffer)(THIS_ UINT iSwapChain,UINT iBackBuffer,D3DBACKBUFFER_TYPE Type,IDirect3DSurface9** ppBackBuffer) PURE;
'  19.  STDMETHOD(GetRasterStatus)(THIS_ UINT iSwapChain,D3DRASTER_STATUS* pRasterStatus) PURE;
'  20.  STDMETHOD(SetDialogBoxMode)(THIS_ BOOL bEnableDialogs) PURE;
'  21.  STDMETHOD_(void, SetGammaRamp)(THIS_ UINT iSwapChain,DWORD Flags,CONST D3DGAMMARAMP* pRamp) PURE;
'  22.  STDMETHOD_(void, GetGammaRamp)(THIS_ UINT iSwapChain,D3DGAMMARAMP* pRamp) PURE;
'  23.  STDMETHOD(CreateTexture)(THIS_ UINT Width,UINT Height,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DTexture9** ppTexture,HANDLE* pSharedHandle) PURE;
'  24.  STDMETHOD(CreateVolumeTexture)(THIS_ UINT Width,UINT Height,UINT Depth,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DVolumeTexture9** ppVolumeTexture,HANDLE* pSharedHandle) PURE;
'  25.  STDMETHOD(CreateCubeTexture)(THIS_ UINT EdgeLength,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DCubeTexture9** ppCubeTexture,HANDLE* pSharedHandle) PURE;
'  26.  STDMETHOD(CreateVertexBuffer)(THIS_ UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,IDirect3DVertexBuffer9** ppVertexBuffer,HANDLE* pSharedHandle) PURE;
'  27.  STDMETHOD(CreateIndexBuffer)(THIS_ UINT Length,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DIndexBuffer9** ppIndexBuffer,HANDLE* pSharedHandle) PURE;
'  28.  STDMETHOD(CreateRenderTarget)(THIS_ UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Lockable,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle) PURE;
'  29.  STDMETHOD(CreateDepthStencilSurface)(THIS_ UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Discard,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle) PURE;
'  30.  STDMETHOD(UpdateSurface)(THIS_ IDirect3DSurface9* pSourceSurface,CONST RECT* pSourceRect,IDirect3DSurface9* pDestinationSurface,CONST POINT* pDestPoint) PURE;
'  31.  STDMETHOD(UpdateTexture)(THIS_ IDirect3DBaseTexture9* pSourceTexture,IDirect3DBaseTexture9* pDestinationTexture) PURE;
'  32.  STDMETHOD(GetRenderTargetData)(THIS_ IDirect3DSurface9* pRenderTarget,IDirect3DSurface9* pDestSurface) PURE;
'  33.  STDMETHOD(GetFrontBufferData)(THIS_ UINT iSwapChain,IDirect3DSurface9* pDestSurface) PURE;
'  34.  STDMETHOD(StretchRect)(THIS_ IDirect3DSurface9* pSourceSurface,CONST RECT* pSourceRect,IDirect3DSurface9* pDestSurface,CONST RECT* pDestRect,D3DTEXTUREFILTERTYPE Filter) PURE;
'  35.  STDMETHOD(ColorFill)(THIS_ IDirect3DSurface9* pSurface,CONST RECT* pRect,D3DCOLOR color) PURE;
'  36.  STDMETHOD(CreateOffscreenPlainSurface)(THIS_ UINT Width,UINT Height,D3DFORMAT Format,D3DPOOL Pool,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle) PURE;
'  37.  STDMETHOD(SetRenderTarget)(THIS_ DWORD RenderTargetIndex,IDirect3DSurface9* pRenderTarget) PURE;
'  38.  STDMETHOD(GetRenderTarget)(THIS_ DWORD RenderTargetIndex,IDirect3DSurface9** ppRenderTarget) PURE;
'  39.  STDMETHOD(SetDepthStencilSurface)(THIS_ IDirect3DSurface9* pNewZStencil) PURE;
'  40.  STDMETHOD(GetDepthStencilSurface)(THIS_ IDirect3DSurface9** ppZStencilSurface) PURE;
'  41.  STDMETHOD(BeginScene)(THIS) PURE;
'  42.  STDMETHOD(EndScene)(THIS) PURE;
'  43.  STDMETHOD(Clear)(THIS_ DWORD Count,CONST D3DRECT* pRects,DWORD Flags,D3DCOLOR Color,float Z,DWORD Stencil) PURE;
'  44.  STDMETHOD(SetTransform)(THIS_ D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix) PURE;
'  45.  STDMETHOD(GetTransform)(THIS_ D3DTRANSFORMSTATETYPE State,D3DMATRIX* pMatrix) PURE;
'  46.  STDMETHOD(MultiplyTransform)(THIS_ D3DTRANSFORMSTATETYPE,CONST D3DMATRIX*) PURE;
'  47.  STDMETHOD(SetViewport)(THIS_ CONST D3DVIEWPORT9* pViewport) PURE;
'  48.  STDMETHOD(GetViewport)(THIS_ D3DVIEWPORT9* pViewport) PURE;
'  49.  STDMETHOD(SetMaterial)(THIS_ CONST D3DMATERIAL9* pMaterial) PURE;
'  50.  STDMETHOD(GetMaterial)(THIS_ D3DMATERIAL9* pMaterial) PURE;
'  51.  STDMETHOD(SetLight)(THIS_ DWORD Index,CONST D3DLIGHT9*) PURE;
'  52.  STDMETHOD(GetLight)(THIS_ DWORD Index,D3DLIGHT9*) PURE;
'  53.  STDMETHOD(LightEnable)(THIS_ DWORD Index,BOOL Enable) PURE;
'  54.  STDMETHOD(GetLightEnable)(THIS_ DWORD Index,BOOL* pEnable) PURE;
'  55.  STDMETHOD(SetClipPlane)(THIS_ DWORD Index,CONST float* pPlane) PURE;
'  56.  STDMETHOD(GetClipPlane)(THIS_ DWORD Index,float* pPlane) PURE;
'  57.  STDMETHOD(SetRenderState)(THIS_ D3DRENDERSTATETYPE State,DWORD Value) PURE;
'  58.  STDMETHOD(GetRenderState)(THIS_ D3DRENDERSTATETYPE State,DWORD* pValue) PURE;
'  59.  STDMETHOD(CreateStateBlock)(THIS_ D3DSTATEBLOCKTYPE Type,IDirect3DStateBlock9** ppSB) PURE;
'  60.  STDMETHOD(BeginStateBlock)(THIS) PURE;
'  61.  STDMETHOD(EndStateBlock)(THIS_ IDirect3DStateBlock9** ppSB) PURE;
'  62.  STDMETHOD(SetClipStatus)(THIS_ CONST D3DCLIPSTATUS9* pClipStatus) PURE;
'  63.  STDMETHOD(GetClipStatus)(THIS_ D3DCLIPSTATUS9* pClipStatus) PURE;
'  64.  STDMETHOD(GetTexture)(THIS_ DWORD Stage,IDirect3DBaseTexture9** ppTexture) PURE;
'  65.  STDMETHOD(SetTexture)(THIS_ DWORD Stage,IDirect3DBaseTexture9* pTexture) PURE;
'  66.  STDMETHOD(GetTextureStageState)(THIS_ DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD* pValue) PURE;
'  67.  STDMETHOD(SetTextureStageState)(THIS_ DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD Value) PURE;
'  68.  STDMETHOD(GetSamplerState)(THIS_ DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD* pValue) PURE;
'  69.  STDMETHOD(SetSamplerState)(THIS_ DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD Value) PURE;
'  70.  STDMETHOD(ValidateDevice)(THIS_ DWORD* pNumPasses) PURE;
'  71.  STDMETHOD(SetPaletteEntries)(THIS_ UINT PaletteNumber,CONST PALETTEENTRY* pEntries) PURE;
'  72.  STDMETHOD(GetPaletteEntries)(THIS_ UINT PaletteNumber,PALETTEENTRY* pEntries) PURE;
'  73.  STDMETHOD(SetCurrentTexturePalette)(THIS_ UINT PaletteNumber) PURE;
'  74.  STDMETHOD(GetCurrentTexturePalette)(THIS_ UINT *PaletteNumber) PURE;
'  75.  STDMETHOD(SetScissorRect)(THIS_ CONST RECT* pRect) PURE;
'  76.  STDMETHOD(GetScissorRect)(THIS_ RECT* pRect) PURE;
'  77.  STDMETHOD(SetSoftwareVertexProcessing)(THIS_ BOOL bSoftware) PURE;
'  78.  STDMETHOD_(BOOL, GetSoftwareVertexProcessing)(THIS) PURE;
'  79.  STDMETHOD(SetNPatchMode)(THIS_ float nSegments) PURE;
'  80.  STDMETHOD_(float, GetNPatchMode)(THIS) PURE;
'  81.  STDMETHOD(DrawPrimitive)(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount) PURE;
'  82.  STDMETHOD(DrawIndexedPrimitive)(THIS_ D3DPRIMITIVETYPE,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount) PURE;
'  83.  STDMETHOD(DrawPrimitiveUP)(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT PrimitiveCount,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride) PURE;
'  84.  STDMETHOD(DrawIndexedPrimitiveUP)(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertices,UINT PrimitiveCount,CONST void* pIndexData,D3DFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride) PURE;
'  85.  STDMETHOD(ProcessVertices)(THIS_ UINT SrcStartIndex,UINT DestIndex,UINT VertexCount,IDirect3DVertexBuffer9* pDestBuffer,IDirect3DVertexDeclaration9* pVertexDecl,DWORD Flags) PURE;
'  86.  STDMETHOD(CreateVertexDeclaration)(THIS_ CONST D3DVERTEXELEMENT9* pVertexElements,IDirect3DVertexDeclaration9** ppDecl) PURE;
'  87.  STDMETHOD(SetVertexDeclaration)(THIS_ IDirect3DVertexDeclaration9* pDecl) PURE;
'  88.  STDMETHOD(GetVertexDeclaration)(THIS_ IDirect3DVertexDeclaration9** ppDecl) PURE;
'  89.  STDMETHOD(SetFVF)(THIS_ DWORD FVF) PURE;
'  90.  STDMETHOD(GetFVF)(THIS_ DWORD* pFVF) PURE;
'  91.  STDMETHOD(CreateVertexShader)(THIS_ CONST DWORD* pFunction,IDirect3DVertexShader9** ppShader) PURE;
'  92.  STDMETHOD(SetVertexShader)(THIS_ IDirect3DVertexShader9* pShader) PURE;
'  93.  STDMETHOD(GetVertexShader)(THIS_ IDirect3DVertexShader9** ppShader) PURE;
'  94.  STDMETHOD(SetVertexShaderConstantF)(THIS_ UINT StartRegister,CONST float* pConstantData,UINT Vector4fCount) PURE;
'  95.  STDMETHOD(GetVertexShaderConstantF)(THIS_ UINT StartRegister,float* pConstantData,UINT Vector4fCount) PURE;
'  96.  STDMETHOD(SetVertexShaderConstantI)(THIS_ UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount) PURE;
'  97.  STDMETHOD(GetVertexShaderConstantI)(THIS_ UINT StartRegister,int* pConstantData,UINT Vector4iCount) PURE;
'  98.  STDMETHOD(SetVertexShaderConstantB)(THIS_ UINT StartRegister,CONST BOOL* pConstantData,UINT  BoolCount) PURE;
'  99.  STDMETHOD(GetVertexShaderConstantB)(THIS_ UINT StartRegister,BOOL* pConstantData,UINT BoolCount) PURE;
' 100.  STDMETHOD(SetStreamSource)(THIS_ UINT StreamNumber,IDirect3DVertexBuffer9* pStreamData,UINT OffsetInBytes,UINT Stride) PURE;
' 101.  STDMETHOD(GetStreamSource)(THIS_ UINT StreamNumber,IDirect3DVertexBuffer9** ppStreamData,UINT* pOffsetInBytes,UINT* pStride) PURE;
' 102.  STDMETHOD(SetStreamSourceFreq)(THIS_ UINT StreamNumber,UINT Setting) PURE;
' 103.  STDMETHOD(GetStreamSourceFreq)(THIS_ UINT StreamNumber,UINT* pSetting) PURE;
' 104.  STDMETHOD(SetIndices)(THIS_ IDirect3DIndexBuffer9* pIndexData) PURE;
' 105.  STDMETHOD(GetIndices)(THIS_ IDirect3DIndexBuffer9** ppIndexData) PURE;
' 106.  STDMETHOD(CreatePixelShader)(THIS_ CONST DWORD* pFunction,IDirect3DPixelShader9** ppShader) PURE;
' 107.  STDMETHOD(SetPixelShader)(THIS_ IDirect3DPixelShader9* pShader) PURE;
' 108.  STDMETHOD(GetPixelShader)(THIS_ IDirect3DPixelShader9** ppShader) PURE;
' 109.  STDMETHOD(SetPixelShaderConstantF)(THIS_ UINT StartRegister,CONST float* pConstantData,UINT Vector4fCount) PURE;
' 110.  STDMETHOD(GetPixelShaderConstantF)(THIS_ UINT StartRegister,float* pConstantData,UINT Vector4fCount) PURE;
' 111.  STDMETHOD(SetPixelShaderConstantI)(THIS_ UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount) PURE;
' 112.  STDMETHOD(GetPixelShaderConstantI)(THIS_ UINT StartRegister,int* pConstantData,UINT Vector4iCount) PURE;
' 113.  STDMETHOD(SetPixelShaderConstantB)(THIS_ UINT StartRegister,CONST BOOL* pConstantData,UINT  BoolCount) PURE;
' 114.  STDMETHOD(GetPixelShaderConstantB)(THIS_ UINT StartRegister,BOOL* pConstantData,UINT BoolCount) PURE;
' 115.  STDMETHOD(DrawRectPatch)(THIS_ UINT Handle,CONST float* pNumSegs,CONST D3DRECTPATCH_INFO* pRectPatchInfo) PURE;
' 116.  STDMETHOD(DrawTriPatch)(THIS_ UINT Handle,CONST float* pNumSegs,CONST D3DTRIPATCH_INFO* pTriPatchInfo) PURE;
' 117.  STDMETHOD(DeletePatch)(THIS_ UINT Handle) PURE;
' 118.  STDMETHOD(CreateQuery)(THIS_ D3DQUERYTYPE Type,IDirect3DQuery9** ppQuery) PURE;
*/

WINAPI HRESULT IDirect3DDevice9_Release(
    void *this_
);

WINAPI HRESULT IDirect3DDevice9_GetDeviceCaps(
    void *this_,
    D3DCAPS9 *pCaps
);

WINAPI HRESULT IDirect3DDevice9_Present(
    void *this_,
    RECT *pSourceRect,
    RECT *pDestRect,
    HWND hDestWindowOverride,
    RGNDATA *pDirtyRegion
);

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
);

WINAPI HRESULT IDirect3DDevice9_CreateCubeTexture(
	void *this_,
	UINT EdgeLength,
	UINT Levels,
	DWORD Usage,
	D3DFORMAT Format,
	D3DPOOL Pool,
	void **ppCubeTexture,
	HANDLE *pSharedHandle
);

WINAPI HRESULT IDirect3DDevice9_CreateVertexBuffer(
    void *this_,
    UINT Length,
    DWORD Usage,
    DWORD FVF,
    D3DPOOL Pool,
    void** ppVertexBuffer,
    HANDLE* pSharedHandle
);

WINAPI HRESULT IDirect3DDevice9_GetRenderTarget(
	void *this_,
	DWORD RenderTargetIndex,
	void **ppRenderTarget
);

WINAPI HRESULT IDirect3DDevice9_GetDepthStencilSurface(
	void *this_,
	void **ppZStencilSurface
);

WINAPI HRESULT IDirect3DDevice9_BeginScene(
    void *this_
);

WINAPI HRESULT IDirect3DDevice9_EndScene(
    void *this_
);

WINAPI HRESULT IDirect3DDevice9_Clear(
    void *this_,
    DWORD Count,
    const D3DRECT *pRects,
    DWORD Flags,
    D3DCOLOR Color,
    float Z,
    DWORD Stencil
);

WINAPI HRESULT IDirect3DDevice9_SetTransform(
    void *this_,
    D3DTRANSFORMSTATETYPE State,
    D3DMATRIX* pMatrix
);

WINAPI HRESULT IDirect3DDevice9_SetViewport(
    void *this_,
    CONST D3DVIEWPORT9 *pViewport
);

WINAPI HRESULT IDirect3DDevice9_SetMaterial(
	void *this_,
	CONST D3DMATERIAL9 *pMaterial
);

WINAPI HRESULT IDirect3DDevice9_SetLight(
	void *this_,
	DWORD Index,
	CONST D3DLIGHT9 *pLight
);

WINAPI HRESULT IDirect3DDevice9_LightEnable(
	void *this_,
	DWORD Index,
	BOOL Enable
);

WINAPI HRESULT IDirect3DDevice9_SetRenderState(
    void *this_,
    D3DRENDERSTATETYPE State,
    DWORD Value
);

WINAPI HRESULT IDirect3DDevice9_SetTexture(
	void *this_,
	DWORD Stage,
	void *pTexture
);

WINAPI HRESULT IDirect3DDevice9_SetTextureStageState(
    void *this_,
    DWORD Stage,
    D3DTEXTURESTAGESTATETYPE Type,
    DWORD Value
);

WINAPI HRESULT IDirect3DDevice9_SetSamplerState(
    void *this_,
    DWORD Sampler,
    D3DSAMPLERSTATETYPE Type,
    DWORD Value
);

WINAPI HRESULT IDirect3DDevice9_DrawPrimitive(
    void *this_,
    D3DPRIMITIVETYPE PrimitiveType,
    UINT StartVertex,
    UINT PrimitiveCount
);

WINAPI HRESULT IDirect3DDevice9_SetFVF(
    void *this_,
    DWORD fvf
);

WINAPI HRESULT IDirect3DDevice9_CreateVertexShader(
	void *this_,
	CONST DWORD *pFunction,
	void **ppShader
);

WINAPI HRESULT IDirect3DDevice9_SetStreamSource(
    void *this_,
    UINT StreamNumber,
    void *pStreamData,
    UINT OffsetInBytes,
    UINT Stride
);

WINAPI HRESULT IDirect3DDevice9_CreatePixelShader(
	void *this_,
	CONST DWORD *pFunction,
	void **ppShader
);

/* IDirect3DResource9 methods */

WINAPI HRESULT IDirect3DResource9_Release(
    void *this_
);

WINAPI D3DRESOURCETYPE IDirect3DResource9_GetType(
    void *this_
);

/*
'  IDirect3DResource9 methods
'  3.  STDMETHOD(GetDevice)(THIS_ IDirect3DDevice9** ppDevice) PURE;
'  4.  STDMETHOD(SetPrivateData)(THIS_ REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) PURE;
'  5.  STDMETHOD(GetPrivateData)(THIS_ REFGUID refguid,void* pData,DWORD* pSizeOfData) PURE;
'  6.  STDMETHOD(FreePrivateData)(THIS_ REFGUID refguid) PURE;
'  7.  STDMETHOD_(DWORD, SetPriority)(THIS_ DWORD PriorityNew) PURE;
'  8.  STDMETHOD_(DWORD, GetPriority)(THIS) PURE;
'  9.  STDMETHOD_(void, PreLoad)(THIS) PURE;
' 10.  STDMETHOD_(D3DRESOURCETYPE, GetType)(THIS) PURE;

' IDirect3DVertexBuffer9 methods
' 11.  STDMETHOD(Lock)(THIS_ UINT OffsetToLock,UINT SizeToLock,void** ppbData,DWORD Flags) PURE;
' 12.  STDMETHOD(Unlock)(THIS) PURE;
' 13.  STDMETHOD(GetDesc)(THIS_ D3DVERTEXBUFFER_DESC *pDesc) PURE;
*/

WINAPI HRESULT IDirect3DVertexBuffer9_Release(
    void *this_
);

WINAPI HRESULT IDirect3DVertexBuffer9_Lock(
    void *this_,
    UINT OffsetToLock,
    UINT SizeToLock,
    void** ppbData,
    DWORD Flags
);

WINAPI HRESULT IDirect3DVertexBuffer9_Unlock(
    void *this_
);

/*
'  3.  STDMETHOD(GetDevice)(THIS_ IDirect3DDevice9** ppDevice) PURE;
'  4.  STDMETHOD(SetPrivateData)(THIS_ REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) PURE;
'  5.  STDMETHOD(GetPrivateData)(THIS_ REFGUID refguid,void* pData,DWORD* pSizeOfData) PURE;
'  6.  STDMETHOD(FreePrivateData)(THIS_ REFGUID refguid) PURE;
'  7.  STDMETHOD_(DWORD, SetPriority)(THIS_ DWORD PriorityNew) PURE;
'  8.  STDMETHOD_(DWORD, GetPriority)(THIS) PURE;
'  9.  STDMETHOD_(void, PreLoad)(THIS) PURE;
' 10.  STDMETHOD_(D3DRESOURCETYPE, GetType)(THIS) PURE;

'    *** IDirect3DSurface9 methods ***

' 11.  STDMETHOD(GetContainer)(THIS_ REFIID riid,void** ppContainer) PURE;
' 12.  STDMETHOD(GetDesc)(THIS_ D3DSURFACE_DESC *pDesc) PURE;
' 13.  STDMETHOD(LockRect)(THIS_ D3DLOCKED_RECT* pLockedRect,CONST RECT* pRect,DWORD Flags) PURE;
' 14.  STDMETHOD(UnlockRect)(THIS) PURE;
' 15.  STDMETHOD(GetDC)(THIS_ HDC *phdc) PURE;
' 16.  STDMETHOD(ReleaseDC)(THIS_ HDC hdc) PURE;
*/

WINAPI HRESULT IDirect3DSurface9_Init(
	void *this_,
	UINT Width,
	UINT Height,
	D3DFORMAT Format
);

WINAPI HRESULT IDirect3DSurface9_Release(
    void *this_
);

WINAPI HRESULT IDirect3DSurface9_GetDesc(
    void *this_,
    D3DSURFACE_DESC *pDesc
);

WINAPI HRESULT IDirect3DSurface9_LockRect(
    void *this_,
    D3DLOCKED_RECT *pLockedRect,
    CONST RECT *pRect,
    DWORD Flags
);

WINAPI HRESULT IDirect3DSurface9_UnlockRect(
    void *this_
);

/*
STDMETHOD_(void, PreLoad)(THIS) PURE;
STDMETHOD_(D3DRESOURCETYPE, GetType)(THIS) PURE;
STDMETHOD_(DWORD, SetLOD)(THIS_ DWORD LODNew) PURE;
STDMETHOD_(DWORD, GetLOD)(THIS) PURE;
STDMETHOD_(DWORD, GetLevelCount)(THIS) PURE;
STDMETHOD(SetAutoGenFilterType)(THIS_ D3DTEXTUREFILTERTYPE FilterType) PURE;
STDMETHOD_(D3DTEXTUREFILTERTYPE, GetAutoGenFilterType)(THIS) PURE;
STDMETHOD_(void, GenerateMipSubLevels)(THIS) PURE;

STDMETHOD(GetLevelDesc)(THIS_ UINT Level,D3DSURFACE_DESC *pDesc) PURE;
STDMETHOD(GetSurfaceLevel)(THIS_ UINT Level,IDirect3DSurface9** ppSurfaceLevel) PURE;
STDMETHOD(LockRect)(THIS_ UINT Level,D3DLOCKED_RECT* pLockedRect,CONST RECT* pRect,DWORD Flags) PURE;
STDMETHOD(UnlockRect)(THIS_ UINT Level) PURE;
STDMETHOD(AddDirtyRect)(THIS_ CONST RECT* pDirtyRect) PURE;
*/

WINAPI HRESULT IDirect3DTexture9_Init(
	void *this_,
	UINT Width,
	UINT Height,
	UINT Levels,
	D3DFORMAT Format
);

WINAPI HRESULT IDirect3DTexture9_Release(
    void *this_
);

WINAPI D3DRESOURCETYPE IDirect3DTexture9_GetType(
    void *this_
);

WINAPI DWORD IDirect3DTexture9_GetLOD(
    void *this_
);

WINAPI HRESULT IDirect3DTexture9_GetSurfaceLevel(
    void *this_,
    UINT Level,
    void **ppSurfaceLevel
);

/*
STDMETHOD(GetLevelDesc)(THIS_ UINT Level,D3DSURFACE_DESC *pDesc) PURE;
STDMETHOD(GetCubeMapSurface)(THIS_ D3DCUBEMAP_FACES FaceType,UINT Level,IDirect3DSurface9** ppCubeMapSurface) PURE;
STDMETHOD(LockRect)(THIS_ D3DCUBEMAP_FACES FaceType,UINT Level,D3DLOCKED_RECT* pLockedRect,CONST RECT* pRect,DWORD Flags) PURE;
STDMETHOD(UnlockRect)(THIS_ D3DCUBEMAP_FACES FaceType,UINT Level) PURE;
STDMETHOD(AddDirtyRect)(THIS_ D3DCUBEMAP_FACES FaceType,CONST RECT* pDirtyRect) PURE;
*/

WINAPI HRESULT IDirect3DCubeTexture9_Init(
    void *this_,
    UINT EdgeLength,
    UINT Levels,
    D3DFORMAT Format
);

WINAPI HRESULT IDirect3DCubeTexture9_Release(
    void *this_
);

WINAPI HRESULT IDirect3DCubeTexture9_GetCubeMapSurface(
    void *this_,
    D3DCUBEMAP_FACES FaceType,
    UINT Level,
    void **ppCubeMapSurface
);

#define D3DFVF_RESERVED0    0x01
#define D3DFVF_POSITION_MASK    0x4000E
#define D3DFVF_XYZ  0x02
#define D3DFVF_XYZRHW   0x04
#define D3DFVF_XYZB1    0x06
#define D3DFVF_XYZB2    0x08
#define D3DFVF_XYZB3    0x0a
#define D3DFVF_XYZB4    0x0c
#define D3DFVF_XYZB5    0x0e
#define D3DFVF_XYZW 0x4002
#define D3DFVF_NORMAL   0x10
#define D3DFVF_PSIZE    0x20
#define D3DFVF_DIFFUSE  0x40
#define D3DFVF_SPECULAR 0x80
#define D3DFVF_TEXCOUNT_MASK    0xf00
#define D3DFVF_TEXCOUNT_SHIFT   8
#define D3DFVF_TEX0 0x0000
#define D3DFVF_TEX1 0x0100
#define D3DFVF_TEX2 0x0200
#define D3DFVF_TEX3 0x0300
#define D3DFVF_TEX4 0x0400
#define D3DFVF_TEX5 0x0500
#define D3DFVF_TEX6 0x0600
#define D3DFVF_TEX7 0x0700
#define D3DFVF_TEX8 0x0800
#define D3DFVF_TEXCOORDSIZE1(i) (D3DFVF_TEXTUREFORMAT1 << (i * 2 + 16))
#define D3DFVF_TEXCOORDSIZE2(i) (D3DFVF_TEXTUREFORMAT2)
#define D3DFVF_TEXCOORDSIZE3(i) (D3DFVF_TEXTUREFORMAT3 << (i * 2 + 16))
#define D3DFVF_TEXCOORDSIZE4(i) (D3DFVF_TEXTUREFORMAT4 << (i * 2 + 16))
#define D3DFVF_TEXTUREFORMAT1   3
#define D3DFVF_TEXTUREFORMAT2   0
#define D3DFVF_TEXTUREFORMAT3   1
#define D3DFVF_TEXTUREFORMAT4   2
#define D3DFVF_LASTBETA_UBYTE4  0x1000
#define D3DFVF_LASTBETA_D3DCOLOR    0x8000
#define D3DFVF_RESERVED2    0x6000

#define D3DCLEAR_TARGET 0x01
#define D3DCLEAR_ZBUFFER    0x02
#define D3DCLEAR_STENCIL    0x04

#define D3DTS_WORLDMATRIX(index)    (D3DTRANSFORMSTATETYPE)(index + 256)
#define D3DTS_WORLD D3DTS_WORLDMATRIX(0)
#define D3DTS_WORLD1    D3DTS_WORLDMATRIX(1)
#define D3DTS_WORLD2    D3DTS_WORLDMATRIX(2)
#define D3DTS_WORLD3    D3DTS_WORLDMATRIX(3)

#define D3DCURSORCAPS_COLOR	1
#define D3DCURSORCAPS_LOWRES	2
#define D3DDEVCAPS_EXECUTESYSTEMMEMORY	0x10
#define D3DDEVCAPS_EXECUTEVIDEOMEMORY	0x20
#define D3DDEVCAPS_TLVERTEXSYSTEMMEMORY	0x40
#define D3DDEVCAPS_TLVERTEXVIDEOMEMORY	0x80
#define D3DDEVCAPS_TEXTURESYSTEMMEMORY	0x100
#define D3DDEVCAPS_TEXTUREVIDEOMEMORY	0x200
#define D3DDEVCAPS_DRAWPRIMTLVERTEX	0x400
#define D3DDEVCAPS_CANRENDERAFTERFLIP	0x800
#define D3DDEVCAPS_TEXTURENONLOCALVIDMEM	0x1000
#define D3DDEVCAPS_DRAWPRIMITIVES2	0x2000
#define D3DDEVCAPS_SEPARATETEXTUREMEMORIES	0x4000
#define D3DDEVCAPS_DRAWPRIMITIVES2EX	0x8000
#define D3DDEVCAPS_HWTRANSFORMANDLIGHT	0x10000
#define D3DDEVCAPS_CANBLTSYSTONONLOCAL	0x20000
#define D3DDEVCAPS_HWRASTERIZATION	0x80000
#define D3DDEVCAPS_PUREDEVICE	0x100000
#define D3DDEVCAPS_QUINTICRTPATCHES	0x200000
#define D3DDEVCAPS_RTPATCHES	0x400000
#define D3DDEVCAPS_RTPATCHHANDLEZERO	0x800000
#define D3DDEVCAPS_NPATCHES	0x1000000
#define D3DDEVCAPS2_STREAMOFFSET	0x01
#define D3DDEVCAPS2_DMAPNPATCH	0x02
#define D3DDEVCAPS2_ADAPTIVETESSRTPATCH	0x04
#define D3DDEVCAPS2_ADAPTIVETESSNPATCH	0x08
#define D3DDEVCAPS2_CAN_STRETCHRECT_FROM_TEXTURES	0x10
#define D3DDEVCAPS2_PRESAMPLEDDMAPNPATCH	0x20
#define D3DDEVCAPS2_VERTEXELEMENTSCANSHARESTREAMOFFSET	0x40
#define D3DFVFCAPS_TEXCOORDCOUNTMASK	0xFFFF
#define D3DFVFCAPS_DONOTSTRIPELEMENTS	0x80000
#define D3DFVFCAPS_PSIZE	0x100000
#define D3DLINECAPS_TEXTURE	0x01
#define D3DLINECAPS_ZTEST	0x02
#define D3DLINECAPS_BLEND	0x04
#define D3DLINECAPS_ALPHACMP	0x08
#define D3DLINECAPS_FOG	0x10
#define D3DLINECAPS_ANTIALIAS	0x20
#define D3DPBLENDCAPS_ZERO	0x01
#define D3DPBLENDCAPS_ONE	0x02
#define D3DPBLENDCAPS_SRCCOLOR	0x04
#define D3DPBLENDCAPS_INVSRCCOLOR	0x08
#define D3DPBLENDCAPS_SRCALPHA	0x10
#define D3DPBLENDCAPS_INVSRCALPHA	0x20
#define D3DPBLENDCAPS_DESTALPHA	0x40
#define D3DPBLENDCAPS_INVDESTALPHA	0x80
#define D3DPBLENDCAPS_DESTCOLOR	0x100
#define D3DPBLENDCAPS_INVDESTCOLOR	0x200
#define D3DPBLENDCAPS_SRCALPHASAT	0x400
#define D3DPBLENDCAPS_BOTHSRCALPHA	0x800
#define D3DPBLENDCAPS_BOTHINVSRCALPHA	0x1000
#define D3DPBLENDCAPS_BLENDFACTOR	0x2000
#define D3DPCMPCAPS_NEVER	0x01
#define D3DPCMPCAPS_LESS	0x02
#define D3DPCMPCAPS_EQUAL	0x04
#define D3DPCMPCAPS_LESSEQUAL	0x08
#define D3DPCMPCAPS_GREATER	0x10
#define D3DPCMPCAPS_NOTEQUAL	0x20
#define D3DPCMPCAPS_GREATEREQUAL	0x40
#define D3DPCMPCAPS_ALWAYS	0x80
#define D3DPMISCCAPS_MASKZ	0x02
#define D3DPMISCCAPS_CULLNONE	0x10
#define D3DPMISCCAPS_CULLCW	0x20
#define D3DPMISCCAPS_CULLCCW	0x40
#define D3DPMISCCAPS_COLORWRITEENABLE	0x80
#define D3DPMISCCAPS_CLIPPLANESCALEDPOINTS	0x100
#define D3DPMISCCAPS_CLIPTLVERTS	0x200
#define D3DPMISCCAPS_TSSARGTEMP	0x400
#define D3DPMISCCAPS_BLENDOP	0x800
#define D3DPMISCCAPS_NULLREFERENCE	0x1000
#define D3DPMISCCAPS_INDEPENDENTWRITEMASKS	0x4000
#define D3DPMISCCAPS_PERSTAGECONSTANT	0x8000
#define D3DPMISCCAPS_FOGANDSPECULARALPHA	0x10000
#define D3DPMISCCAPS_SEPARATEALPHABLEND	0x20000
#define D3DPMISCCAPS_MRTINDEPENDENTBITDEPTHS	0x40000
#define D3DPMISCCAPS_MRTPOSTPIXELSHADERBLENDING	0x80000
#define D3DPMISCCAPS_FOGVERTEXCLAMPED	0x100000
#define D3DPRASTERCAPS_DITHER	0x01
#define D3DPRASTERCAPS_ZTEST	0x10
#define D3DPRASTERCAPS_FOGVERTEX	0x80
#define D3DPRASTERCAPS_FOGTABLE	0x100
#define D3DPRASTERCAPS_MIPMAPLODBIAS	0x2000
#define D3DPRASTERCAPS_ZBUFFERLESSHSR	0x8000
#define D3DPRASTERCAPS_FOGRANGE	0x10000
#define D3DPRASTERCAPS_ANISOTROPY	0x20000
#define D3DPRASTERCAPS_WBUFFER	0x40000
#define D3DPRASTERCAPS_WFOG	0x100000
#define D3DPRASTERCAPS_ZFOG	0x200000
#define D3DPRASTERCAPS_COLORPERSPECTIVE	0x400000
#define D3DPRASTERCAPS_SCISSORTEST	0x1000000
#define D3DPRASTERCAPS_SLOPESCALEDEPTHBIAS	0x2000000
#define D3DPRASTERCAPS_DEPTHBIAS	0x4000000
#define D3DPRASTERCAPS_MULTISAMPLE_TOGGLE	0x8000000
#define D3DPRESENT_INTERVAL_DEFAULT	0x00
#define D3DPRESENT_INTERVAL_ONE	0x01
#define D3DPRESENT_INTERVAL_TWO	0x02
#define D3DPRESENT_INTERVAL_THREE	0x04
#define D3DPRESENT_INTERVAL_FOUR	0x08
#define D3DPRESENT_INTERVAL_IMMEDIATE	0x80000000L
#define D3DPSHADECAPS_COLORGOURAUDRGB	0x08
#define D3DPSHADECAPS_SPECULARGOURAUDRGB	0x200
#define D3DPSHADECAPS_ALPHAGOURAUDBLEND	0x4000
#define D3DPSHADECAPS_FOGGOURAUD	0x80000
#define D3DPTADDRESSCAPS_WRAP	0x01
#define D3DPTADDRESSCAPS_MIRROR	0x02
#define D3DPTADDRESSCAPS_CLAMP	0x04
#define D3DPTADDRESSCAPS_BORDER	0x08
#define D3DPTADDRESSCAPS_INDEPENDENTUV	0x10
#define D3DPTADDRESSCAPS_MIRRORONCE	0x20
#define D3DPTEXTURECAPS_PERSPECTIVE	0x01
#define D3DPTEXTURECAPS_POW2	0x02
#define D3DPTEXTURECAPS_ALPHA	0x04
#define D3DPTEXTURECAPS_SQUAREONLY	0x20
#define D3DPTEXTURECAPS_TEXREPEATNOTSCALEDBYSIZE	0x40
#define D3DPTEXTURECAPS_ALPHAPALETTE	0x80
#define D3DPTEXTURECAPS_NONPOW2CONDITIONAL	0x100
#define D3DPTEXTURECAPS_PROJECTED	0x400
#define D3DPTEXTURECAPS_CUBEMAP	0x800
#define D3DPTEXTURECAPS_VOLUMEMAP	0x2000
#define D3DPTEXTURECAPS_MIPMAP	0x4000
#define D3DPTEXTURECAPS_MIPVOLUMEMAP	0x8000
#define D3DPTEXTURECAPS_MIPCUBEMAP	0x10000
#define D3DPTEXTURECAPS_CUBEMAP_POW2	0x20000
#define D3DPTEXTURECAPS_VOLUMEMAP_POW2	0x40000
#define D3DPTEXTURECAPS_NOPROJECTEDBUMPENV	0x200000
#define D3DPTFILTERCAPS_MINFPOINT	0x100
#define D3DPTFILTERCAPS_MINFLINEAR	0x200
#define D3DPTFILTERCAPS_MINFANISOTROPIC	0x400
#define D3DPTFILTERCAPS_MINFPYRAMIDALQUAD	0x800
#define D3DPTFILTERCAPS_MINFGAUSSIANQUAD	0x1000
#define D3DPTFILTERCAPS_MIPFPOINT	0x10000
#define D3DPTFILTERCAPS_MIPFLINEAR	0x20000
#define D3DPTFILTERCAPS_MAGFPOINT	0x1000000
#define D3DPTFILTERCAPS_MAGFLINEAR	0x2000000
#define D3DPTFILTERCAPS_MAGFANISOTROPIC	0x4000000
#define D3DPTFILTERCAPS_MAGFPYRAMIDALQUAD	0x8000000
#define D3DPTFILTERCAPS_MAGFGAUSSIANQUAD	0x10000000
#define D3DSTENCILCAPS_KEEP	0x01
#define D3DSTENCILCAPS_ZERO	0x02
#define D3DSTENCILCAPS_REPLACE	0x04
#define D3DSTENCILCAPS_INCRSAT	0x08
#define D3DSTENCILCAPS_DECRSAT	0x10
#define D3DSTENCILCAPS_INVERT	0x20
#define D3DSTENCILCAPS_INCR	0x40
#define D3DSTENCILCAPS_DECR	0x80
#define D3DSTENCILCAPS_TWOSIDED	0x100
#define D3DTEXOPCAPS_DISABLE	0x01
#define D3DTEXOPCAPS_SELECTARG1	0x02
#define D3DTEXOPCAPS_SELECTARG2	0x04
#define D3DTEXOPCAPS_MODULATE	0x08
#define D3DTEXOPCAPS_MODULATE2X	0x10
#define D3DTEXOPCAPS_MODULATE4X	0x20
#define D3DTEXOPCAPS_ADD	0x40
#define D3DTEXOPCAPS_ADDSIGNED	0x80
#define D3DTEXOPCAPS_ADDSIGNED2X	0x100
#define D3DTEXOPCAPS_SUBTRACT	0x200
#define D3DTEXOPCAPS_ADDSMOOTH	0x400
#define D3DTEXOPCAPS_BLENDDIFFUSEALPHA	0x800
#define D3DTEXOPCAPS_BLENDTEXTUREALPHA	0x1000
#define D3DTEXOPCAPS_BLENDFACTORALPHA	0x2000
#define D3DTEXOPCAPS_BLENDTEXTUREALPHAPM	0x4000
#define D3DTEXOPCAPS_BLENDCURRENTALPHA	0x8000
#define D3DTEXOPCAPS_PREMODULATE	0x10000
#define D3DTEXOPCAPS_MODULATEALPHA_ADDCOLOR	0x20000
#define D3DTEXOPCAPS_MODULATECOLOR_ADDALPHA	0x40000
#define D3DTEXOPCAPS_MODULATEINVALPHA_ADDCOLOR	0x80000
#define D3DTEXOPCAPS_MODULATEINVCOLOR_ADDALPHA	0x100000
#define D3DTEXOPCAPS_BUMPENVMAP	0x200000
#define D3DTEXOPCAPS_BUMPENVMAPLUMINANCE	0x400000
#define D3DTEXOPCAPS_DOTPRODUCT3	0x800000
#define D3DTEXOPCAPS_MULTIPLYADD	0x1000000
#define D3DTEXOPCAPS_LERP	0x2000000
#define D3DVTXPCAPS_TEXGEN	0x01
#define D3DVTXPCAPS_MATERIALSOURCE7	0x02
#define D3DVTXPCAPS_DIRECTIONALLIGHTS	0x08
#define D3DVTXPCAPS_POSITIONALLIGHTS	0x10
#define D3DVTXPCAPS_LOCALVIEWER	0x20
#define D3DVTXPCAPS_TWEENING	0x40
#define D3DVTXPCAPS_TEXGEN_SPHEREMAP	0x100
#define D3DVTXPCAPS_NO_TEXGEN_NONLOCALVIEWER	0x200
#define D3DCAPS_READ_SCANLINE	0x20000
#define D3DCAPS2_FULLSCREENGAMMA	0x20000L
#define D3DCAPS2_CANCALIBRATEGAMMA	0x100000L
#define D3DCAPS2_RESERVED	0x2000000L
#define D3DCAPS2_CANMANAGERESOURCE	0x10000000L
#define D3DCAPS2_DYNAMICTEXTURES	0x20000000L
#define D3DCAPS2_CANAUTOGENMIPMAP	0x40000000L
#define D3DCAPS3_ALPHA_FULLSCREEN_FLIP_OR_DISCARD	0x20
#define D3DCAPS3_LINEAR_TO_SRGB_PRESENTATION	0x80
#define D3DCAPS3_COPY_TO_VIDMEM	0x100
#define D3DCAPS3_COPY_TO_SYSTEMMEM	0x200
#define D3DCAPS3_RESERVED	0x8000001fL
#define D3DDTCAPS_UBYTE4	0x01
#define D3DDTCAPS_UBYTE4N	0x02
#define D3DDTCAPS_SHORT2N	0x04
#define D3DDTCAPS_SHORT4N	0x08
#define D3DDTCAPS_USHORT2N	0x10
#define D3DDTCAPS_USHORT4N	0x20
#define D3DDTCAPS_UDEC3	0x40
#define D3DDTCAPS_DEC3N	0x80
#define D3DDTCAPS_FLOAT16_2	0x100
#define D3DDTCAPS_FLOAT16_4	0x200
#define D3DMIN30SHADERINSTRUCTIONS	512
#define D3DMAX30SHADERINSTRUCTIONS	32768
#define D3DPS20_MAX_DYNAMICFLOWCONTROLDEPTH	24
#define D3DPS20_MIN_DYNAMICFLOWCONTROLDEPTH	0
#define D3DPS20_MAX_NUMTEMPS	32
#define D3DPS20_MIN_NUMTEMPS	12
#define D3DPS20_MAX_STATICFLOWCONTROLDEPTH	4
#define D3DPS20_MIN_STATICFLOWCONTROLDEPTH	0
#define D3DPS20_MAX_NUMINSTRUCTIONSLOTS	512
#define D3DPS20_MIN_NUMINSTRUCTIONSLOTS	96
#define D3DPS20CAPS_ARBITRARYSWIZZLE	0x1
#define D3DPS20CAPS_GRADIENTINSTRUCTIONS	0x2
#define D3DPS20CAPS_PREDICATION	0x4
#define D3DPS20CAPS_NODEPENDENTREADLIMIT	0x8
#define D3DPS20CAPS_NOTEXINSTRUCTIONLIMIT	0x10
#define D3DVS20_MAX_DYNAMICFLOWCONTROLDEPTH	24
#define D3DVS20_MIN_DYNAMICFLOWCONTROLDEPTH	0
#define D3DVS20_MAX_NUMTEMPS	32
#define D3DVS20_MIN_NUMTEMPS	12
#define D3DVS20_MAX_STATICFLOWCONTROLDEPTH	4
#define D3DVS20_MIN_STATICFLOWCONTROLDEPTH	1
#define D3DVS20CAPS_PREDICATION	1

#endif
