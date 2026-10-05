#include "CInterfaceD3D.h"

#include "Blitting.h"
#include "CBB/CBBSupport.h"
#include "CCacheManager.h"
#include "CSurface.h"
#include "CUploadCachePageManager.h"
#include "Framework.h"
#include "Gfx/CColorGradient.h"
#include "Gfx/GfxEngineSetup.h"
#include "Gfx/Render/SGfxRenderConfiguration.h"
#include "MapObjects/CHeightAndTypeTable.h"
#include "TRI.h"

#include <assert.h>

// Definitions for class CInterfaceD3D

class CSurfaceV7;
// address=[0x468a207]
bool s_bCursorIsFixed;

// address=[0x3e2e328]
bool s_bCursorIsVisible;

// address=[0x3e2e32c]
int s_iCurrentCursor;

// address=[0x3e2e330]
struct _DDCOLORKEY g_sColorKeyMagenta555;

// address=[0x3e2e338]
struct _DDCOLORKEY g_sColorKeyMagenta565;

// address=[0x3e2e340]
struct _DDCOLORKEY g_sColorKeyGui;
// address=[0x468a2e8]
struct _DDCOLORKEY g_sColorKeyBlack;

// address=[0x468a254]
HCURSOR s_hCursor;

// address=[0x468a258]
HCURSOR s_hCursorHandles[36];

// address=[0x4696870]
unsigned char *g_pSoftwareTexturePages;

// address=[0x468e3c0]
unsigned char **g_pTextureTable;

// address=[0x4689a70]
void *g_pDirectDraw;

// address=[0x468a7f8]
int *g_iDestSizeTable;

// address=[0x468aff8]
int *g_iCamDestSizeTable;

// address=[0x468b7f8]
int *g_pDestSizeTable;

// address=[0x468b7fc]
int *g_pZoomGradient;

// address=[0x3e2e378]
int g_iZoomGradient;

// address=[0x3e2e37c]
int g_iCamZoomGradient;

class CInterfaceD3D *D3DObjectPtr;

// address=[0x468b800]
bool(__cdecl *g_pfBlitSettler)(int, int, int, struct SGfxObjectInfo *);

// address=[0x468b804]
bool(__cdecl *g_pfBlitObject)(int, int, int, struct SGfxObjectInfo *);

// address=[0x468b808]
bool(__cdecl *g_pfBlitVehicle)(int, int, int, struct SGfxObjectInfo *);

// address=[0x468b80c]
bool(__cdecl *g_pfBlitBuilding)(int, int, int, struct SGfxObjectInfo *, int *, int &);

// address=[0x468b810]
bool(__cdecl *g_pfBlitBorderstone)(int, int, int, int);

// address=[0x468b814]
bool(__cdecl *g_pfBlitAccessoryIcon)(int, int, int, int);

// address=[0x468b818]
bool(__cdecl *g_pfBlitWave)(int, int, int, int, int);

// address=[0x468a2f0]
void *(__cdecl *g_pfForceReload)(int, bool, bool);

extern GFX_ENGINE_SETUP GfxEngineSetup{
    .sRenderSetup.m_bHardwareEnabled = 0,
    .sRenderSetup.m_bGuiOnly = 0,
    .sRenderSetup.m_bUseDD3Interface = 0,
    .sRenderSetup.m_iFlags = 2,
    .sRenderSetup.m_hWnd = 0,
    .sRenderSetup.m_uWidth = 800,
    .sRenderSetup.m_uHeight = 600,
    .sRenderSetup.m_uX = 0x32,
    .sRenderSetup.m_uY = 0x32,
    .sRenderSetup.m_iReserved1 = 0,
    .sRenderSetup.m_iReserved2 = 0,
    .iCamFollowX = 0,
    .iCamFollowY = 0,
    .iVertexSize = 0x180000,
    .iVertexHeight = 0x180000,
    .iCamVertexSize = 0x180000,
    .iCamVertexHeight = 0x180000,
    .iSizeOfMap = 0x100,
    .psMapElement = 0,
    .hOutputBitmap = 0,
    .iScrollOffsetX = 0,
    .iScrollOffsetY = 0,
    .iSoftOffsetX = 0,
    .iSoftOffsetY = 0,
    .iCurrentGfxMode = 0,
    .iWidthOfBorder = 0,
    .iCamWidthOfBorder = 0,
    .iCamScrollOffsetX = 0,
    .iCamScrollOffsetY = 0,
    .iCamSoftOffsetX = 0,
    .iCamSoftOffsetY = 0,
    .iCamX = 0,
    .iCamY = 0,
    .iCamWidth = 0,
    .iCamHeigth = 0,
    .pMiniMapHwnd = 0,
    .pObjectLayer = 0,
    .pDecoLayer = 0,
    .psSelectionRect = 0,
    .fZoomFactor = 1.0,
    .fCamZoomFactor = 1.0,
    .uSelectionColor = 0,
    .bUpdateCamLandscape = 1,
    .bLandscapeDeltaScroll = 1,
    .bUpdateLandscapeDelta = 0,
    .bDrawMiniMap = 0,
    .bUpdateLandscape = 0,
    .iMiniMapX = 6,
    .iMiniMapY = 6,
    .bMiniMapRefresh = 0,
    .bShowIconLayer = 0,
    .bHardwareObjects = 0,
    .iShowCachePage = 0,
};

// address=[0x2f5f250]
// Decompiled from void __thiscall CInterfaceD3D::BlitCursor(CInterfaceD3D *this)
void CInterfaceD3D::BlitCursor(void) {
    HRESULT hResult = this->m_cMoveCursor.Show(this->m_pFinalRenderSurface);
    if(hResult != 0) {
        WriteError(hResult, "BlitMoveCursor");
    }
    hResult = this->m_cZoomCursor.Show(this->m_pFinalRenderSurface);
    this->m_bRefreshTextureSurfaces = 1;
    if(hResult != 0) {
        WriteError(hResult, "BlitZoomCursor");
    }
}

// address=[0x2f5f390]
// Decompiled from bool __thiscall CInterfaceD3D::HasCameraWindowSurface(CInterfaceD3D *this)
bool CInterfaceD3D::HasCameraWindowSurface(void) const {

    return this->m_pLandscapeCameraRenderSurface != nullptr;
}

// address=[0x2f62860]
// Decompiled from CInterfaceD3D *__thiscall CInterfaceD3D::CInterfaceD3D(CInterfaceD3D *this)
CInterfaceD3D::CInterfaceD3D(void) : m_sClipper1(),
                                     m_sMinimapClipper(),
                                     m_cMoveCursor(),
                                     m_cZoomCursor() {

    unsigned int i; // [esp+4h] [ebp-14h]
    int j;          // [esp+4h] [ebp-14h]
    int k;          // [esp+4h] [ebp-14h]

    this->m_iCacheRetries = 2000;
    this->m_bRefreshTextureSurfaces = 0;
    this->m_bForceBlt = 0;
    this->m_bHiTextureQuality = 0;
    this->m_iGuiSurfaceSize = 0;
    this->m_iNumberOfCachedSurfaces = 0;
    this->m_bDisableRendering = 0;
    this->m_iLandscapeSceneLock = 0;
    this->m_iObjectSceneLock = 0;
    memset(this->m_bAvailableResolutions, 0, sizeof(this->m_bAvailableResolutions));
    this->m_bHardwareRuns = 0;
    this->m_bSoftwareRuns = 0;
    this->m_bEngineWasRebuilded = 1;
    GfxEngineSetup.iCurrentGfxMode = 0;
    for(i = 0;
        i < 14;
        ++i) {
        this->m_pDDGuiSurfaces[i] = nullptr;
    }
    CInterfaceD3D::InitTexturedLandscapeModule();
    this->m_pDDraw = nullptr;
    this->m_pDDraw7 = nullptr;
    this->m_pZoomCursorSurface = nullptr;
    this->m_pMoveCursorSurface = nullptr;
    this->m_pTmpSurface = nullptr;
    this->m_pMiniMapAreaSurface = nullptr;
    this->m_pMiniMapSurface = nullptr;
    this->m_pLandscapeSurface = nullptr;
    this->m_pLandscapeCameraRenderSurface = nullptr;
    this->m_pCurrentLandScapeRenderTarget = nullptr;
    this->m_pFinalRenderSurface = nullptr;
    this->m_pPrimarySurface = nullptr;
    this->m_pIDirect3D7 = nullptr;
    this->LandscapeDevice = nullptr;
    this->m_pObjectDevice = nullptr;
    this->D3DVertexPtr = nullptr;
    for(j = 0;
        j < 2;
        ++j) {
        this->m_pDDObjectSurfacePtr[j] = nullptr;
        this->m_pDDSourceObjectSurfacePtr[j] = nullptr;
        this->m_pcPictureManager[j] = nullptr;
    }
    for(k = 0;
        k < 180;
        ++k) {
        this->m_pCacheSurfaces[k] = nullptr;
        this->m_pCacheManagers[k] = nullptr;
    }
    BBSupportTracePrintF(1, "GFX ENGINE: DD interface successfully created!");
}

// address=[0x2f62b00]
// Decompiled from int __thiscall CInterfaceD3D::~CInterfaceD3D(CInterfaceD3D *this)
CInterfaceD3D::~CInterfaceD3D(void) {
    for(int i = 179;
        i >= 0;
        --i) {
        if(this->m_pCacheManagers[i] != nullptr) {
            if(this->m_pCacheManagers[i]->IsVideoSurfaceLocked() != 0) {
                this->m_pCacheManagers[i]->UnlockVideoSurface();
            }
            if(this->m_pCacheManagers[i]->IsSourceSurfaceLocked() != 0) {
                this->m_pCacheManagers[i]->UnlockSourceSurface();
            }
            CCachePageManager *v3 = this->m_pCacheManagers[i];
            if(v3 != nullptr) {
                delete v3;
            }
            this->m_pCacheManagers[i] = nullptr;
        }
        if(this->m_pCacheSurfaces[i] != nullptr) {
            this->m_pCacheSurfaces[i]->Release();
            this->m_pCacheSurfaces[i] = nullptr;
        }
    }
    for(int j = 1;
        j >= 0;
        --j) {
        if(this->m_pcPictureManager[j] != nullptr) {
            if(this->m_pcPictureManager[j]->IsVideoSurfaceLocked() != 0) {
                this->m_pcPictureManager[j]->UnlockVideoSurface();
            }
            if(this->m_pcPictureManager[j]->IsSourceSurfaceLocked() != 0) {
                this->m_pcPictureManager[j]->UnlockSourceSurface();
            }
            CUploadCachePageManager *v2 = this->m_pcPictureManager[j];
            if(v2 != nullptr) {
                delete v2;
            }
            this->m_pcPictureManager[j] = nullptr;
        }
        if(this->m_pDDSourceObjectSurfacePtr[j] != nullptr) {
            this->m_pDDSourceObjectSurfacePtr[j]->Release();
            CSurface *v15 = this->m_pDDSourceObjectSurfacePtr[j];
            if(v15 != nullptr) {
                delete v15;
            }
            this->m_pDDSourceObjectSurfacePtr[j] = nullptr;
        }
        if(this->m_pDDObjectSurfacePtr[j] != nullptr) {
            this->m_pDDObjectSurfacePtr[j]->Release();
            CSurface *v14 = this->m_pDDObjectSurfacePtr[j];
            if(v14 != nullptr) {
                delete v14;
            }
            this->m_pDDObjectSurfacePtr[j] = nullptr;
        }
    }
    if(s_bCursorIsFixed != 0) {
        ClipCursor(nullptr);
        s_bCursorIsFixed = 0;
    }
    if(s_bCursorIsVisible == 0) {
        ShowCursor(true);
        s_bCursorIsVisible = 1;
    }
    if(s_hCursor != nullptr) {
        SetClassLongA(GfxEngineSetup.sRenderSetup.m_hWnd, -12, (LONG)s_hCursor);
        SetCursor(s_hCursor);
        s_hCursor = nullptr;
    }
    this->m_sClipper1.ReleaseClipper();
    this->m_sMinimapClipper.ReleaseClipper();
    if(g_pSoftwareTexturePages != 0) {
        operator delete[]((void *)g_pSoftwareTexturePages);
        g_pSoftwareTexturePages = 0;
        for(int k = 0;
            k < 44;
            ++k) {
            g_pTextureTable[k] = 0;
        }
    }
    for(int m = 43;
        m >= 0;
        --m) {
        if(this->m_pDDTextureSurfaces[m] != nullptr) {
            this->m_pDDTextureSurfaces[m]->Release();
            CSurface *v13 = this->m_pDDTextureSurfaces[m];
            if(v13 != nullptr) {
                delete v13;
            }
            this->m_pDDTextureSurfaces[m] = nullptr;
        }
        g_pTextureTable[m] = 0;
    }
    for(int n = 14;
        n >= 0;
        --n) {
        if(this->m_pDDGuiSurfaces[n] != nullptr) {
            this->m_pDDGuiSurfaces[n]->Release();
            CSurface *v12 = this->m_pDDGuiSurfaces[n];
            if(v12 != nullptr) {
                delete v12;
            }
            this->m_pDDGuiSurfaces[n] = nullptr;
        }
    }
    this->m_sClipper1.ReleaseClipper();
    this->m_sMinimapClipper.ReleaseClipper();
    if(this->m_pObjectDevice != nullptr) {
        this->m_pObjectDevice->Release();
    }
    if(this->LandscapeDevice != nullptr) {
        this->LandscapeDevice->Release();
    }
    if(this->m_pZoomCursorSurface != nullptr) {
        this->m_pZoomCursorSurface->Release();
        CSurface *pZoomCursorSurface = this->m_pZoomCursorSurface;
        if(pZoomCursorSurface != nullptr) {
            delete pZoomCursorSurface;
        }
        this->m_pZoomCursorSurface = nullptr;
    }
    if(this->m_pMoveCursorSurface != nullptr) {
        this->m_pMoveCursorSurface->Release();
        CSurface *pMoveCursorSurface = this->m_pMoveCursorSurface;
        if(pMoveCursorSurface != nullptr) {
            delete pMoveCursorSurface;
        }
        this->m_pMoveCursorSurface = nullptr;
    }
    if(this->m_pLandscapeSurface != nullptr) {
        this->m_pLandscapeSurface->Release();
        CSurface *pLandscapeSurface = this->m_pLandscapeSurface;
        if(pLandscapeSurface != nullptr) {
            delete pLandscapeSurface;
        }
        this->m_pLandscapeSurface = nullptr;
    }
    CInterfaceD3D::DestroyCameraWindowSurface();
    if(this->m_pFinalRenderSurface != nullptr) {
        if(this->m_pFinalRenderSurface->IsBackBufferReference() == 0) {
            this->m_pFinalRenderSurface->Release();
        }
        CSurface *pFinalRenderSurface = this->m_pFinalRenderSurface;
        if(pFinalRenderSurface != nullptr) {
            delete pFinalRenderSurface;
        }
        this->m_pFinalRenderSurface = nullptr;
    }
    if(this->m_pMiniMapSurface != nullptr) {
        this->m_pMiniMapSurface->Release();
        CSurface *pMiniMapSurface = this->m_pMiniMapSurface;
        if(pMiniMapSurface != nullptr) {
            delete pMiniMapSurface;
        }
        this->m_pMiniMapSurface = nullptr;
    }
    if(this->m_pMiniMapAreaSurface != nullptr) {
        this->m_pMiniMapAreaSurface->Release();
        CSurface *pMiniMapAreaSurface = this->m_pMiniMapAreaSurface;
        if(pMiniMapAreaSurface != nullptr) {
            delete pMiniMapAreaSurface;
        }
        this->m_pMiniMapAreaSurface = nullptr;
    }
    if(this->m_pPrimarySurface != nullptr) {
        this->m_pPrimarySurface->Release();
        CSurface *pPrimarySurface = this->m_pPrimarySurface;
        if(pPrimarySurface != nullptr) {
            delete pPrimarySurface;
        }
        this->m_pPrimarySurface = nullptr;
    }
    if(this->m_pTmpSurface != nullptr) {
        CSurface *pTmpSurface = this->m_pTmpSurface;
        if(pTmpSurface != nullptr) {
            delete pTmpSurface;
        }
        this->m_pTmpSurface = nullptr;
    }
    if(this->m_pDDraw7 != nullptr) {
        this->m_pDDraw7->Release();
    }
    if(this->m_pIDirect3D7 != nullptr) {
        this->m_pIDirect3D7->Release();
    }
    this->m_pDDraw = nullptr;
    this->m_pDDraw7 = nullptr;
    this->m_pIDirect3D7 = nullptr;
    this->LandscapeDevice = nullptr;
    this->m_pObjectDevice = nullptr;
    CInterfaceD3D::DeleteEngineData();
    BBSupportTracePrintF(1, "GFX ENGINE: DD interface successfully destroyed!");
}

// address=[0x2f63450]
// Decompiled from char __thiscall CInterfaceD3D::InitCommon(CInterfaceD3D *this)
bool CInterfaceD3D::InitCommon(void) {
    IDirectDraw7 *pDDraw; // [esp+2Ch] [ebp-3Ch]
    bool bIs555;          // [esp+67h] [ebp-1h] BYREF

    BBSupportTracePrintF(1, "GFX ENGINE: Begin common init. Mode: Interface 7.");
    if(this->m_bHardwareRuns != 0 || this->m_bSoftwareRuns != 0) {
        BBSupportTracePrintF(1, "GFX ENGINE: INIT COMMON: Engine is already initialized!");
        return 1;
    }
    this->m_bHiTextureQuality = GfxEngineSetup.sRenderSetup.IsHQTextureSet();
    this->m_bForceBlt = !GfxEngineSetup.sRenderSetup.IsForceBlit();
    if(s_hCursor != nullptr) {
        SetClassLongA(GfxEngineSetup.sRenderSetup.m_hWnd, -12, (LONG)s_hCursor);
        SetCursor(s_hCursor);
        s_hCursor = nullptr;
    }
    s_bCursorIsVisible = 1;
    s_bCursorIsFixed = 0;
    s_iCurrentCursor = -1;
    s_hCursorHandles[0] = LoadCursorA(g_hInstance, (LPCSTR)0x65);
    s_hCursorHandles[1] = LoadCursorA(g_hInstance, (LPCSTR)0x66);
    s_hCursorHandles[2] = LoadCursorA(g_hInstance, (LPCSTR)0x6D);
    s_hCursorHandles[3] = LoadCursorA(g_hInstance, (LPCSTR)0x6E);
    s_hCursorHandles[4] = LoadCursorA(g_hInstance, (LPCSTR)0x6F);
    s_hCursorHandles[5] = LoadCursorA(g_hInstance, (LPCSTR)0x70);
    s_hCursorHandles[6] = LoadCursorA(g_hInstance, (LPCSTR)0x71);
    s_hCursorHandles[7] = LoadCursorA(g_hInstance, (LPCSTR)0x72);
    s_hCursorHandles[8] = LoadCursorA(g_hInstance, (LPCSTR)0x77);
    s_hCursorHandles[9] = LoadCursorA(g_hInstance, (LPCSTR)0x78);
    s_hCursorHandles[10] = LoadCursorA(g_hInstance, (LPCSTR)0x79);
    s_hCursorHandles[11] = LoadCursorA(g_hInstance, (LPCSTR)0x7A);
    s_hCursorHandles[12] = LoadCursorA(g_hInstance, (LPCSTR)0x7B);
    s_hCursorHandles[13] = LoadCursorA(g_hInstance, (LPCSTR)0x7C);
    s_hCursorHandles[14] = LoadCursorA(g_hInstance, (LPCSTR)0x7D);
    s_hCursorHandles[15] = LoadCursorA(g_hInstance, (LPCSTR)0x7E);
    s_hCursorHandles[16] = LoadCursorA(g_hInstance, (LPCSTR)0x7F);
    s_hCursorHandles[17] = LoadCursorA(g_hInstance, (LPCSTR)0x80);
    s_hCursorHandles[18] = LoadCursorA(g_hInstance, (LPCSTR)0x81);
    s_hCursorHandles[19] = LoadCursorA(g_hInstance, (LPCSTR)0x82);
    s_hCursorHandles[20] = LoadCursorA(g_hInstance, (LPCSTR)0x83);
    s_hCursorHandles[21] = LoadCursorA(g_hInstance, (LPCSTR)0x84);
    s_hCursorHandles[22] = LoadCursorA(g_hInstance, (LPCSTR)0x85);
    s_hCursorHandles[23] = LoadCursorA(g_hInstance, (LPCSTR)0x86);
    s_hCursorHandles[24] = LoadCursorA(g_hInstance, (LPCSTR)0x87);
    s_hCursorHandles[25] = LoadCursorA(g_hInstance, (LPCSTR)0x88);
    s_hCursorHandles[26] = LoadCursorA(g_hInstance, (LPCSTR)0x89);
    s_hCursorHandles[27] = LoadCursorA(g_hInstance, (LPCSTR)0x8B);
    s_hCursorHandles[28] = LoadCursorA(g_hInstance, (LPCSTR)0x8C);
    s_hCursorHandles[29] = LoadCursorA(g_hInstance, (LPCSTR)0x8D);
    s_hCursorHandles[30] = LoadCursorA(g_hInstance, (LPCSTR)0x8E);
    s_hCursorHandles[31] = LoadCursorA(g_hInstance, (LPCSTR)0x8F);
    s_hCursorHandles[32] = LoadCursorA(g_hInstance, (LPCSTR)0x90);
    s_hCursorHandles[33] = LoadCursorA(g_hInstance, (LPCSTR)0x91);
    s_hCursorHandles[34] = LoadCursorA(g_hInstance, (LPCSTR)0x92);
    s_hCursorHandles[35] = LoadCursorA(g_hInstance, (LPCSTR)0x93);
    for(int i = 0;
        i < 36;
        ++i) {
        if(s_hCursorHandles[i] == nullptr) {
            BBSupportTracePrintF(1, "GFX ENGINE: Couldn't create cursors!");
            return 0;
        }
    }
    GfxEngineSetup.bMiniMapRefresh = 1;
    this->m_pTmpSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
    if(this->m_pTmpSurface == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
    }
    if(g_pDirectDraw != nullptr) {
        this->m_pDDraw = static_cast<IDirectDraw7 *>(g_pDirectDraw);
    } else {
        HMODULE hModule = GetModuleHandleA("DDRAW");
        if(hModule == nullptr) {
            BBSupportTracePrintF(1, "GFX ENGINE: Direct Draw is not accessible!");
            return 0;
        }
        decltype(&::DirectDrawCreateEx) DirectDrawCreateEx = reinterpret_cast<decltype(&::DirectDrawCreateEx)>(GetProcAddress(hModule, "DirectDrawCreateEx"));
        if(DirectDrawCreateEx == nullptr) {
            BBSupportTracePrintF(1, "GFX ENGINE: DirectDrawCreateEx not found! Interface 7 or higher not available!");
            return 0;
        }
        int v24 = DirectDrawCreateEx(nullptr, reinterpret_cast<LPVOID *>(&this->m_pDDraw), IID_IDirectDraw7, nullptr);
        if(v24 != 0) {
            WriteError(v24, "CreateDirectDrawObject");
            return 0;
        }
        g_pDirectDraw = this->m_pDDraw;
    }

    HRESULT hResult = this->m_pDDraw->QueryInterface(IID_IDirectDraw7, reinterpret_cast<LPVOID *>(&this->m_pDDraw7));
    if(hResult != 0) {
        WriteError(hResult, "QueryInterface");
        return 0;
    }
    hResult = this->m_pDDraw7->SetCooperativeLevel(GfxEngineSetup.sRenderSetup.m_hWnd, 8);
    if(hResult != 0) {
        WriteError(hResult, "SetCooperativeLevel");
        return 0;
    }
    this->m_pPrimarySurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
    if(this->m_pPrimarySurface == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
    }

    if(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface) {
        pDDraw = this->m_pDDraw;
    } else {
        pDDraw = this->m_pDDraw7;
    }

    hResult = this->m_pPrimarySurface->CreateSurface(pDDraw, GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight, 1, 0, 0, GfxEngineSetup.iCurrentGfxMode == 1, 1, 0, 0);
    if(hResult != 0) {
        WriteError(hResult, "CreatePrimarySurface");
        return 0;
    }

    hResult = this->m_pPrimarySurface->GetPixelFormat(bIs555);
    if(hResult != 0) {
        WriteError(hResult, "RetrievePixelFormatFromPrimarySurface");
        return 0;
    }

    if(bIs555 != 0) {
        GfxEngineSetup.iCurrentGfxMode = 1;
    } else {
        GfxEngineSetup.iCurrentGfxMode = 2;
    }

    this->m_pMoveCursorSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
    if(this->m_pMoveCursorSurface == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
    }

    if(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface) {
        pDDraw = this->m_pDDraw;
    } else {
        pDDraw = this->m_pDDraw7;
    }

    hResult = this->m_pMoveCursorSurface->CreateSurface(pDDraw, 32, 32, 1, 0, 0, GfxEngineSetup.iCurrentGfxMode == 1, 0, 0, 0);
    if(hResult != 0) {
        WriteError(hResult, "CreateMoveCursorSurface");
        return 0;
    }

    if(GfxEngineSetup.iCurrentGfxMode == 1) {
        this->m_cMoveCursor.SetSurfacePtr(0x73u, this->m_pMoveCursorSurface, g_sColorKeyMagenta555.dwColorSpaceLowValue);
    } else {
        this->m_cMoveCursor.SetSurfacePtr(0x73u, this->m_pMoveCursorSurface, g_sColorKeyMagenta565.dwColorSpaceLowValue);
    }
    if(GfxEngineSetup.iCurrentGfxMode == 1) {
        this->m_pMoveCursorSurface->SetColorKey(8, &g_sColorKeyMagenta555);
    } else {
        this->m_pMoveCursorSurface->SetColorKey(8, &g_sColorKeyMagenta565);
    }
    this->m_pZoomCursorSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
    if(this->m_pZoomCursorSurface == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
    }
    if(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface) {
        pDDraw = this->m_pDDraw;
    } else {
        pDDraw = this->m_pDDraw7;
    }

    hResult = this->m_pZoomCursorSurface->CreateSurface(pDDraw, 32, 32, 1, 0, 0, GfxEngineSetup.iCurrentGfxMode == 1, 0, 0, 0);
    if(hResult != 0) {
        WriteError(hResult, "CreateZoomCursorSurface");
        return 0;
    }
    if(GfxEngineSetup.iCurrentGfxMode == 1) {
        this->m_cZoomCursor.SetSurfacePtr(0x74u, this->m_pZoomCursorSurface, g_sColorKeyMagenta555.dwColorSpaceLowValue);
    } else {
        this->m_cZoomCursor.SetSurfacePtr(0x74u, this->m_pZoomCursorSurface, g_sColorKeyMagenta565.dwColorSpaceLowValue);
    }
    if(GfxEngineSetup.iCurrentGfxMode == 1) {
        this->m_pZoomCursorSurface->SetColorKey(8, &g_sColorKeyMagenta555);
    } else {
        this->m_pZoomCursorSurface->SetColorKey(8, &g_sColorKeyMagenta565);
    }
    this->m_pMiniMapSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
    if(this->m_pMiniMapSurface == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
    }

    if(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface) {
        pDDraw = this->m_pDDraw;
    } else {
        pDDraw = this->m_pDDraw7;
    }

    hResult = this->m_pMiniMapSurface->CreateSurface(pDDraw, 240, 160, 1, 0, 0, GfxEngineSetup.iCurrentGfxMode == 1, 0, 0, 0);
    if(hResult != 0) {
        WriteError(hResult, "CreateMiniMapSurface");
        return 0;
    }
    this->m_pMiniMapSurface->ClearSurface(nullptr);
    this->m_pMiniMapSurface->SetColorKey(8, &g_sColorKeyBlack);
    this->m_pMiniMapAreaSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
    if(this->m_pMiniMapAreaSurface == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
    }

    if(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface) {
        pDDraw = this->m_pDDraw;
    } else {
        pDDraw = this->m_pDDraw7;
    }

    hResult = this->m_pMiniMapAreaSurface->CreateSurface(pDDraw, 240, 160, 1, 0, 0, GfxEngineSetup.iCurrentGfxMode == 1, 0, 0, 0);
    if(hResult != 0) {
        WriteError(hResult, "CreateMiniMapAreaSurface");
        return 0;
    }

    hResult = this->m_pMiniMapAreaSurface->ClearSurface(nullptr);
    if(hResult != 0) {
        WriteError(hResult, "ClearMiniMapSurface");
    }

    hResult = this->m_pMiniMapAreaSurface->SetColorKey(8, &g_sColorKeyBlack);
    if(hResult != 0) {
        WriteError(hResult, "SetMiniMapColorKey");
    }

    BBSupportTracePrintF(1, "GFX ENGINE: Size of render surface: %d x %d", GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight);
    this->m_pLandscapeSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
    if(this->m_pLandscapeSurface == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
    }

    if(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface) {
        pDDraw = this->m_pDDraw;
    } else {
        pDDraw = this->m_pDDraw7;
    }

    bool IsHardwareLandscapeEngine = GfxEngineSetup.sRenderSetup.IsHardwareLandscapeEngine();
    hResult = this->m_pLandscapeSurface->CreateSurface(pDDraw, GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight, 1, IsHardwareLandscapeEngine, 0, GfxEngineSetup.iCurrentGfxMode == 1, 0, 0, 0);
    if(hResult != 0) {
        WriteError(hResult, "CreateLandscapeSurface");
        return 0;
    }

    this->m_pCurrentLandScapeRenderTarget = this->m_pLandscapeSurface;
    this->m_pFinalRenderSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
    if(this->m_pFinalRenderSurface == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
    }

    if(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface) {
        pDDraw = this->m_pDDraw;
    } else {
        pDDraw = this->m_pDDraw7;
    }
    BOOL HardwareLandscapeEngine = GfxEngineSetup.sRenderSetup.IsHardwareLandscapeEngine();
    bool HardwareLandscapeEngine2 = GfxEngineSetup.sRenderSetup.IsHardwareLandscapeEngine();
    hResult = this->m_pFinalRenderSurface->CreateSurface(pDDraw, GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight, 1, HardwareLandscapeEngine2, 0, GfxEngineSetup.iCurrentGfxMode == 1, 0, HardwareLandscapeEngine, 0);
    if(hResult != 0) {
        WriteError(hResult, "CreateFinalRenderSurface");
        return 0;
    }

    hResult = this->m_sClipper1.InitClipper(this->m_pDDraw7);
    if(hResult != 0) {
        WriteError(hResult, "CreateClipper1");
        return 0;
    }

    hResult = this->m_sMinimapClipper.InitClipper(this->m_pDDraw7);
    if(hResult != 0) {
        WriteError(hResult, "Create Minimap Clipper");
        return 0;
    }

    hResult = this->m_sClipper1.SetClipWindow(GfxEngineSetup.sRenderSetup.m_hWnd);
    if(hResult != 0) {
        WriteError(hResult, "AssignClipper1");
        return 0;
    }
    auto pClipper = this->m_sClipper1.GetClipper();
    hResult = this->m_pPrimarySurface->SetClipper(pClipper);
    if(hResult != 0) {
        WriteError(hResult, "SetClipper1");
        return 0;
    }

    g_pDestSizeTable = g_iDestSizeTable;
    g_pZoomGradient = &g_iZoomGradient;
    BBSupportTracePrintF(1, "GFX ENGINE: Common init ok.");
    return 1;
}

// address=[0x2f643e0]
// Decompiled from char __thiscall CInterfaceD3D::InitCommonV3(CInterfaceD3D *this)
bool CInterfaceD3D::InitCommonV3(void) {
    int iBitDepth;                // [esp+0h] [ebp-5Ch] BYREF
    DWORD iColorKeyValue;         // [esp+28h] [ebp-34h]
    IDirectDraw7 *pDDraw;         // [esp+2Ch] [ebp-30h] MAPDST
    DDCOLORKEY *pColorKeyMagenta; // [esp+34h] [ebp-28h] MAPDST
    DWORD dwColorSpaceLowValue;   // [esp+38h] [ebp-24h]
    HRESULT hResult;              // [esp+50h] [ebp-Ch]
    bool bIs555;                  // [esp+5Bh] [ebp-1h] BYREF

    BBSupportTracePrintF(1, "GFX ENGINE: Begin common init. Mode: Interface 3.");
    if(this->m_bHardwareRuns != 0 || this->m_bSoftwareRuns != 0) {
        BBSupportTracePrintF(1, "GFX ENGINE: INIT COMMON: Engine is already initialized!");
        return 1;
    }
    this->m_bHiTextureQuality = GfxEngineSetup.sRenderSetup.IsHQTextureSet();
    this->m_bForceBlt = 0;
    if(s_hCursor != nullptr) {
        SetClassLongA(GfxEngineSetup.sRenderSetup.m_hWnd, -12, (LONG)s_hCursor);
        SetCursor(s_hCursor);
        s_hCursor = nullptr;
    }
    s_bCursorIsVisible = 1;
    s_bCursorIsFixed = 0;
    s_iCurrentCursor = -1;
    s_hCursorHandles[0] = LoadCursorA(g_hInstance, (LPCSTR)0x65);
    s_hCursorHandles[1] = LoadCursorA(g_hInstance, (LPCSTR)0x66);
    s_hCursorHandles[2] = LoadCursorA(g_hInstance, (LPCSTR)0x6D);
    s_hCursorHandles[3] = LoadCursorA(g_hInstance, (LPCSTR)0x6E);
    s_hCursorHandles[4] = LoadCursorA(g_hInstance, (LPCSTR)0x6F);
    s_hCursorHandles[5] = LoadCursorA(g_hInstance, (LPCSTR)0x70);
    s_hCursorHandles[6] = LoadCursorA(g_hInstance, (LPCSTR)0x71);
    s_hCursorHandles[7] = LoadCursorA(g_hInstance, (LPCSTR)0x72);
    s_hCursorHandles[8] = LoadCursorA(g_hInstance, (LPCSTR)0x77);
    s_hCursorHandles[9] = LoadCursorA(g_hInstance, (LPCSTR)0x78);
    s_hCursorHandles[10] = LoadCursorA(g_hInstance, (LPCSTR)0x79);
    s_hCursorHandles[11] = LoadCursorA(g_hInstance, (LPCSTR)0x7A);
    s_hCursorHandles[12] = LoadCursorA(g_hInstance, (LPCSTR)0x7B);
    s_hCursorHandles[13] = LoadCursorA(g_hInstance, (LPCSTR)0x7C);
    s_hCursorHandles[14] = LoadCursorA(g_hInstance, (LPCSTR)0x7D);
    s_hCursorHandles[15] = LoadCursorA(g_hInstance, (LPCSTR)0x7E);
    s_hCursorHandles[16] = LoadCursorA(g_hInstance, (LPCSTR)0x7F);
    s_hCursorHandles[17] = LoadCursorA(g_hInstance, (LPCSTR)0x80);
    s_hCursorHandles[18] = LoadCursorA(g_hInstance, (LPCSTR)0x81);
    s_hCursorHandles[19] = LoadCursorA(g_hInstance, (LPCSTR)0x82);
    s_hCursorHandles[20] = LoadCursorA(g_hInstance, (LPCSTR)0x83);
    s_hCursorHandles[21] = LoadCursorA(g_hInstance, (LPCSTR)0x84);
    s_hCursorHandles[22] = LoadCursorA(g_hInstance, (LPCSTR)0x85);
    s_hCursorHandles[23] = LoadCursorA(g_hInstance, (LPCSTR)0x86);
    s_hCursorHandles[24] = LoadCursorA(g_hInstance, (LPCSTR)0x87);
    s_hCursorHandles[25] = LoadCursorA(g_hInstance, (LPCSTR)0x88);
    s_hCursorHandles[26] = LoadCursorA(g_hInstance, (LPCSTR)0x89);
    s_hCursorHandles[27] = LoadCursorA(g_hInstance, (LPCSTR)0x8B);
    s_hCursorHandles[28] = LoadCursorA(g_hInstance, (LPCSTR)0x8C);
    s_hCursorHandles[29] = LoadCursorA(g_hInstance, (LPCSTR)0x8D);
    s_hCursorHandles[30] = LoadCursorA(g_hInstance, (LPCSTR)0x8E);
    s_hCursorHandles[31] = LoadCursorA(g_hInstance, (LPCSTR)0x8F);
    s_hCursorHandles[32] = LoadCursorA(g_hInstance, (LPCSTR)0x90);
    s_hCursorHandles[33] = LoadCursorA(g_hInstance, (LPCSTR)0x91);
    s_hCursorHandles[34] = LoadCursorA(g_hInstance, (LPCSTR)0x92);
    s_hCursorHandles[35] = LoadCursorA(g_hInstance, (LPCSTR)0x93);
    for(int i = 0;
        i < 36;
        ++i) {
        if(s_hCursorHandles[i] == nullptr) {
            BBSupportTracePrintF(1, "GFX ENGINE: Couldn't create cursors!");
            return 0;
        }
    }
    GfxEngineSetup.bMiniMapRefresh = 1;
    this->m_pTmpSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
    if(this->m_pTmpSurface == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
    }
    if(g_pDirectDraw != nullptr) {
        this->m_pDDraw = static_cast<IDirectDraw7 *>(g_pDirectDraw);
    } else {
        hResult = DirectDrawCreate(nullptr, (LPDIRECTDRAW *)&this->m_pDDraw, nullptr);
        if(hResult != 0) {
            WriteError(hResult, "CreateDirectDrawObject");
            return 0;
        }
        g_pDirectDraw = this->m_pDDraw;
    }

    hResult = this->m_pDDraw->SetCooperativeLevel(GfxEngineSetup.sRenderSetup.m_hWnd, 8);
    if(hResult != 0) {
        WriteError(hResult, "SetCooperativeLevel");
        return 0;
    }

    this->m_pPrimarySurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
    if(this->m_pPrimarySurface == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
    }

    if(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface) {
        pDDraw = this->m_pDDraw;
    } else {
        pDDraw = this->m_pDDraw7;
    }
    hResult = this->m_pPrimarySurface->CreateSurface(pDDraw, GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight, 1, 0, 0, GfxEngineSetup.iCurrentGfxMode == 1, 1, 0, 0);
    if(hResult != 0) {
        WriteError(hResult, "CreatePrimarySurface");
        return 0;
    }

    hResult = this->m_pPrimarySurface->GetBitDepth(iBitDepth);
    if(hResult != 0) {
        WriteError(hResult, "RetrieveBitDepth");
        return 0;
    }

    if(iBitDepth != 16) {
        BBSupportTracePrintF(1, "GFX ENGINE: Primary surface is not 16 bit! Please switch your desktop to HiColor!");
        return 0;
    }

    hResult = this->m_pPrimarySurface->GetPixelFormat(bIs555);
    if(hResult != 0) {
        WriteError(hResult, "RetrievePixelFormatFromPrimarySurface");
        return 0;
    }

    if(bIs555 != 0) {
        GfxEngineSetup.iCurrentGfxMode = 1;
    } else {
        GfxEngineSetup.iCurrentGfxMode = 2;
    }
    this->m_pMoveCursorSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
    if(this->m_pMoveCursorSurface == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
    }
    if(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface) {
        pDDraw = this->m_pDDraw;
    } else {
        pDDraw = this->m_pDDraw7;
    }

    hResult = this->m_pMoveCursorSurface->CreateSurface(pDDraw, 32, 32, 1, 0, 0, GfxEngineSetup.iCurrentGfxMode == 1, 0, 0, 0);
    if(hResult != 0) {
        WriteError(hResult, "CreateMoveCursorSurface");
        return 0;
    }

    if(GfxEngineSetup.iCurrentGfxMode == 1) {
        dwColorSpaceLowValue = g_sColorKeyMagenta555.dwColorSpaceLowValue;
    } else {
        dwColorSpaceLowValue = g_sColorKeyMagenta565.dwColorSpaceLowValue;
    }
    this->m_cMoveCursor.SetSurfacePtr(0x73u, this->m_pMoveCursorSurface, dwColorSpaceLowValue);
    if(GfxEngineSetup.iCurrentGfxMode == 1) {
        pColorKeyMagenta = &g_sColorKeyMagenta555;
    } else {
        pColorKeyMagenta = &g_sColorKeyMagenta565;
    }
    this->m_pMoveCursorSurface->SetColorKey(8, pColorKeyMagenta);
    this->m_pZoomCursorSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
    if(this->m_pZoomCursorSurface == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
    }

    if(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface) {
        pDDraw = this->m_pDDraw;
    } else {
        pDDraw = this->m_pDDraw7;
    }
    hResult = this->m_pZoomCursorSurface->CreateSurface(pDDraw, 32, 32, 1, 0, 0, GfxEngineSetup.iCurrentGfxMode == 1, 0, 0, 0);
    if(hResult != 0) {
        WriteError(hResult, "CreationZoomCursorSurface");
        return 0;
    }

    if(GfxEngineSetup.iCurrentGfxMode == 1) {
        iColorKeyValue = g_sColorKeyMagenta555.dwColorSpaceLowValue;
    } else {
        iColorKeyValue = g_sColorKeyMagenta565.dwColorSpaceLowValue;
    }
    this->m_cZoomCursor.SetSurfacePtr(0x74u, this->m_pZoomCursorSurface, iColorKeyValue);
    if(GfxEngineSetup.iCurrentGfxMode == 1) {
        pColorKeyMagenta = &g_sColorKeyMagenta555;
    } else {
        pColorKeyMagenta = &g_sColorKeyMagenta565;
    }
    this->m_pZoomCursorSurface->SetColorKey(8, pColorKeyMagenta);
    this->m_pMiniMapSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
    if(this->m_pMiniMapSurface == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
    }

    if(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface) {
        pDDraw = this->m_pDDraw;
    } else {
        pDDraw = this->m_pDDraw7;
    }
    hResult = this->m_pMiniMapSurface->CreateSurface(pDDraw, 240, 160, 1, 0, 0, GfxEngineSetup.iCurrentGfxMode == 1, 0, 0, 0);
    if(hResult != 0) {
        WriteError(hResult, "CreateMiniMapSurface");
        return 0;
    }

    this->m_pMiniMapSurface->ClearSurface(nullptr);
    this->m_pMiniMapSurface->SetColorKey(8, &g_sColorKeyBlack);
    this->m_pMiniMapAreaSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
    if(this->m_pMiniMapAreaSurface == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
    }

    if(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface) {
        pDDraw = this->m_pDDraw;
    } else {
        pDDraw = this->m_pDDraw7;
    }
    hResult = this->m_pMiniMapAreaSurface->CreateSurface(pDDraw, 240, 160, 1, 0, 0, GfxEngineSetup.iCurrentGfxMode == 1, 0, 0, 0);
    if(hResult != 0) {
        WriteError(hResult, "CreateMiniMapAreaSurface");
        return 0;
    }

    hResult = this->m_pMiniMapAreaSurface->ClearSurface(nullptr);
    if(hResult != 0) {
        WriteError(hResult, "ClearMiniMapSurface");
    }
    hResult = this->m_pMiniMapAreaSurface->SetColorKey(8, &g_sColorKeyBlack);
    if(hResult != 0) {
        WriteError(hResult, "SetMiniMapColorKey");
    }

    BBSupportTracePrintF(1, "GFX ENGINE: Size of render surface: %d x %d", GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight);
    this->m_pLandscapeSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
    if(this->m_pLandscapeSurface == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
    }
    if(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface) {
        pDDraw = this->m_pDDraw;
    } else {
        pDDraw = this->m_pDDraw7;
    }
    bool IsHardwareLandscapeEngine = GfxEngineSetup.sRenderSetup.IsHardwareLandscapeEngine();
    hResult = this->m_pLandscapeSurface->CreateSurface(pDDraw, GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight, 1, IsHardwareLandscapeEngine, 0, GfxEngineSetup.iCurrentGfxMode == 1, 0, 0, 0);
    if(hResult != 0) {
        WriteError(hResult, "CreateLandscapeSurface");
        return 0;
    }

    this->m_pCurrentLandScapeRenderTarget = this->m_pLandscapeSurface;
    this->m_pFinalRenderSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
    if(this->m_pFinalRenderSurface == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
    }
    if(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface) {
        pDDraw = this->m_pDDraw;
    } else {
        pDDraw = this->m_pDDraw7;
    }

    hResult = this->m_pFinalRenderSurface->CreateSurface(pDDraw, GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight, 1, GfxEngineSetup.sRenderSetup.IsHardwareLandscapeEngine(), 0, GfxEngineSetup.iCurrentGfxMode == 1, 0, GfxEngineSetup.sRenderSetup.IsHardwareLandscapeEngine(), 0);
    if(hResult != 0) {
        WriteError(hResult, "CreateFinalRenderSurface");
        return 0;
    }

    hResult = this->m_sClipper1.InitClipper(this->m_pDDraw);
    if(hResult != 0) {
        WriteError(hResult, "CreateClipper1");
        return 0;
    }
    hResult = this->m_sMinimapClipper.InitClipper(this->m_pDDraw);
    if(hResult != 0) {
        WriteError(hResult, "Create Minimap Clipper");
        return 0;
    }
    hResult = this->m_sClipper1.SetClipWindow(GfxEngineSetup.sRenderSetup.m_hWnd);
    if(hResult != 0) {
        WriteError(hResult, "AssignClipper1");
        return 0;
    }
    auto *pClipper = this->m_sClipper1.GetClipper();
    hResult = this->m_pPrimarySurface->SetClipper(pClipper);
    if(hResult != 0) {
        WriteError(hResult, "SetClipper1");
        return 0;
    }
    g_pDestSizeTable = g_iDestSizeTable;
    g_pZoomGradient = &g_iZoomGradient;
    BBSupportTracePrintF(1, "GFX ENGINE: Common init ok.");
    return 1;
}

// address=[0x046F32C9]
bool s_bVehicleHousePageIsUsed;

// address=[0x47132D4]
int s_iCacheListCounter;

// address=[0x3e2e380]
int g_iZoomInit = 0x0FFFF0000;

// address=[0x2f92aa0]
// Decompiled from void InitRenderStates()
void __cdecl InitRenderStates(void) {

    s_bVehicleHousePageIsUsed = 0;
    s_iCacheListCounter = 0;
}

// address=[0x2f65300]
// Decompiled from char __thiscall CInterfaceD3D::InitHardware(CInterfaceD3D *this)
bool CInterfaceD3D::InitHardware(void) {

    int v2;                                               // eax
    IDirectDrawSurface7 *pLandscapeSurface;               // eax
    IDirectDrawSurface7 *pFinalRenderSurface;             // eax
    struct IDirectDrawSurface7 *pDefaultLandscapeTexture; // eax
    struct IDirectDrawSurface7 *pDefaultObjectTexture;    // eax
    int GradientFormat;                                   // eax
    IDirectDrawSurface7 *v8;                              // eax
    IDirectDrawSurface7 *v9;                              // [esp+ACh] [ebp-170h]
    IDirect3DDevice7 *pObjectDevice;                      // [esp+B0h] [ebp-16Ch]
    IDirect3DDevice7 **v11;                               // [esp+B4h] [ebp-168h]
    IDirect3DDevice7 **v12;                               // [esp+B4h] [ebp-168h]
    DWORD v13;                                            // [esp+C0h] [ebp-15Ch] BYREF
    CCachePageManager *pCacheManager;                     // [esp+C8h] [ebp-154h]
    CCachePageManager *v16;                               // [esp+CCh] [ebp-150h]
    BOOL v17;                                             // [esp+D0h] [ebp-14Ch]
    CUploadCachePageManager *pUploadCachePageManager;     // [esp+D4h] [ebp-148h] MAPDST
    void *C;                                              // [esp+D8h] [ebp-144h]
    DWORD iFilterSetting;                                 // [esp+E0h] [ebp-13Ch] MAPDST
    IDirectDraw7 *pDDraw;                                 // [esp+ECh] [ebp-130h] MAPDST
    int Number;                                           // [esp+F0h] [ebp-12Ch]
    unsigned int uAvailableVidMemory;                     // [esp+F4h] [ebp-128h] BYREF
    int v27;                                              // [esp+F8h] [ebp-124h]
    int iTextureVertexCount;                              // [esp+FCh] [ebp-120h]
    bool v30;                                             // [esp+107h] [ebp-115h]
    int i;                                                // [esp+108h] [ebp-114h]
    HRESULT hResult;                                      // [esp+10Ch] [ebp-110h] MAPDST
    DDSCAPS2 sCaps;                                       // [esp+1FCh] [ebp-20h] BYREF
    int exceptionBlock;                                   // [esp+218h] [ebp-4h]

    BBSupportTracePrintF(1, "GFX ENGINE: Begin hardware init.");
    if(this->m_bHardwareRuns != 0 || this->m_bSoftwareRuns != 0) {
        BBSupportTracePrintF(1, "GFX ENGINE: INIT HARDWARE: Engine is already initialized!");
        return 1;
    }
    g_cHeightAndTypeTable.InitShadeTables();
    hResult = this->m_pDDraw7->QueryInterface(IID_IDirect3D7, (LPVOID *)&this->m_pIDirect3D7);
    if(hResult != 0) {
        WriteError(hResult, "QueryD3DInterface");
        return 0;
    }

    D3DObjectPtr->AllocateEngineData(256);
    iTextureVertexCount = 256;
    if(D3DObjectPtr->m_bHiTextureQuality == 0 && GfxEngineSetup.sRenderSetup.IsHardwareLandscapeEngine()) {
        iTextureVertexCount /= 2;
    }
    CInterfaceD3D::PreCalcTextureVertices(iTextureVertexCount);
    for(i = 0;
        i < 44;
        ++i) {
        this->m_pDDTextureSurfaces[i] = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
        if(this->m_pDDTextureSurfaces[i] == nullptr) {
            BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
            return 0;
        }

        if(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface) {
            pDDraw = this->m_pDDraw;
        } else {
            pDDraw = this->m_pDDraw7;
        }

        hResult = this->m_pDDTextureSurfaces[i]->CreateSurface(pDDraw, iTextureVertexCount, iTextureVertexCount, 1, 1, 1, GfxEngineSetup.iCurrentGfxMode == 1, 0, 0, 0);
        if(hResult != 0) {
            WriteError(hResult, "CreateLandscapeTextureSurface");
            return 0;
        }
    }

    if(GfxEngineSetup.bHardwareObjects != 0) {
        for(i = 0;
            i < 2;
            ++i) {
            this->m_pDDObjectSurfacePtr[i] = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
            if(this->m_pDDObjectSurfacePtr[i] == nullptr) {
                BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
                return 0;
            }
            if(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface) {
                pDDraw = this->m_pDDraw;
            } else {
                pDDraw = this->m_pDDraw7;
            }
            hResult = this->m_pDDObjectSurfacePtr[i]->CreateSurface(pDDraw, 512, 512, 1, 0, 1, 2, 0, 0, 0);
            if(hResult != 0) {
                WriteError(hResult, "CreateObjectTextureSurface");
                return 0;
            }
        }
        for(i = 0;
            i < 2;
            ++i) {
            this->m_pDDSourceObjectSurfacePtr[i] = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
            if(this->m_pDDSourceObjectSurfacePtr[i] == nullptr) {
                BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
                return 0;
            }
            if(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface) {
                pDDraw = this->m_pDDraw;
            } else {
                pDDraw = this->m_pDDraw7;
            }
            hResult = this->m_pDDSourceObjectSurfacePtr[i]->CreateSurface(pDDraw, 512, 512, 0, 0, 1, 2, 0, 0, 0);
            if(hResult != 0) {
                WriteError(hResult, "CreateObjectTextureSystemMemory");
                return 0;
            }
        }
    }
    pLandscapeSurface = static_cast<IDirectDrawSurface7 *>(this->m_pLandscapeSurface->GetSurfacePtr());
    hResult = this->m_pIDirect3D7->CreateDevice(IID_IDirect3DHALDevice, pLandscapeSurface, &this->LandscapeDevice); //
    if(hResult != 0) {
        WriteError(hResult, "CreateLandscapeRenderDevice");
        return 0;
    }
    pFinalRenderSurface = static_cast<IDirectDrawSurface7 *>(this->m_pFinalRenderSurface->GetSurfacePtr());
    hResult = this->m_pIDirect3D7->CreateDevice(IID_IDirect3DHALDevice, pFinalRenderSurface, &this->m_pObjectDevice); // m_pObjectDevice
    if(hResult != 0) {
        WriteError(hResult, "CreateObjectRenderDevice");
        return 0;
    }
    this->m_sViewport.dwX = 0;
    this->m_sViewport.dwY = 0;
    this->m_sViewport.dwWidth = GfxEngineSetup.sRenderSetup.m_uWidth;
    this->m_sViewport.dwHeight = GfxEngineSetup.sRenderSetup.m_uHeight;
    this->m_sViewport.dvMinZ = 0.0;
    this->m_sViewport.dvMaxZ = 1.0;
    hResult = this->LandscapeDevice->SetViewport(&this->m_sViewport);
    if(hResult != 0) {
        WriteError(hResult, "SetLandscapeViewport");
        return 0;
    }
    hResult = this->m_pObjectDevice->SetViewport(&this->m_sViewport);
    if(hResult != 0) {
        WriteError(hResult, "SetObjectViewport");
        return 0;
    }
    pDefaultLandscapeTexture = static_cast<IDirectDrawSurface7 *>(this->m_pDDTextureSurfaces[0]->GetSurfacePtr());
    hResult = this->LandscapeDevice->SetTexture(0, pDefaultLandscapeTexture);
    if(hResult != 0) {
        WriteError(hResult, "SetDefaultLandscapeTexture");
        return 0;
    }
    hResult = this->LandscapeDevice->SetRenderState(D3DRENDERSTATE_CULLMODE, 1);
    if(hResult != 0) {
        WriteError(hResult, "SetCulling");
        return 0;
    }
    hResult = this->LandscapeDevice->SetRenderState(D3DRENDERSTATE_TEXTUREPERSPECTIVE, 0);
    if(hResult != 0) {
        WriteError(hResult, "SetTextureCorrecture");
        return 0;
    }
    hResult = this->LandscapeDevice->SetRenderState(D3DRENDERSTATE_ZENABLE, 0);
    if(hResult != 0) {
        WriteError(hResult, "DisableZBuffer");
        return 0;
    }
    hResult = this->LandscapeDevice->SetRenderState(D3DRENDERSTATE_LOCALVIEWER, 0);
    if(hResult != 0) {
        WriteError(hResult, "DisableCameraView");
        return 0;
    }
    hResult = this->LandscapeDevice->SetTextureStageState(0, D3DTSS_ADDRESS, 1);
    if(hResult != 0) {
        WriteError(hResult, "SetTextureAdressMode");
        return 0;
    }
    hResult = this->LandscapeDevice->SetRenderState(D3DRENDERSTATE_SHADEMODE, 2);
    if(hResult != 0) {
        WriteError(hResult, "SetLandscapeShading");
        return 0;
    }
    hResult = this->LandscapeDevice->SetRenderState(D3DRENDERSTATE_SPECULARENABLE, 1);
    if(hResult != 0) {
        WriteError(hResult, "SetLandscapeLighting");
        return 0;
    }
    if(GfxEngineSetup.bHardwareObjects != 0) {
        InitRenderStates();
        pDefaultObjectTexture = static_cast<IDirectDrawSurface7 *>(this->m_pDDObjectSurfacePtr[0]->GetSurfacePtr());
        hResult = this->m_pObjectDevice->SetTexture(0, pDefaultObjectTexture);
        if(hResult != 0) {
            WriteError(hResult, "SetDefaultObjectTexture");
            return 0;
        }
        hResult = this->m_pObjectDevice->SetRenderState(D3DRENDERSTATE_SHADEMODE, 1);
        if(hResult != 0) {
            WriteError(hResult, "SetObjectShading");
            return 0;
        }
        hResult = this->m_pObjectDevice->SetRenderState(D3DRENDERSTATE_SPECULARENABLE, 0);
        if(hResult != 0) {
            WriteError(hResult, "SetObjectLighting");
            return 0;
        }
        hResult = this->m_pObjectDevice->SetRenderState(D3DRENDERSTATE_ALPHABLENDENABLE, 1);
        if(hResult != 0) {
            WriteError(hResult, "EnableAlphaBlending");
            return 0;
        }
        hResult = this->m_pObjectDevice->SetRenderState(D3DRENDERSTATE_SRCBLEND, 5);
        if(hResult != 0) {
            WriteError(hResult, "SetSourceBlend");
            return 0;
        }
        hResult = this->m_pObjectDevice->SetRenderState(D3DRENDERSTATE_DESTBLEND, 6);
        if(hResult != 0) {
            WriteError(hResult, "SetDestBlend");
            return 0;
        }
        if(GfxEngineSetup.sRenderSetup.IsFiltering()) {
            iFilterSetting = D3DFILTER_LINEAR;
        } else {
            iFilterSetting = D3DFILTER_NEAREST;
        }
        hResult = this->m_pObjectDevice->SetTextureStageState(0, D3DTSS_MAGFILTER, iFilterSetting);
        if(hResult != 0) {
            WriteError(hResult, "SetObjectFiltering");
            return 0;
        }
        if(GfxEngineSetup.sRenderSetup.IsFiltering()) {
            iFilterSetting = D3DFILTER_LINEAR;
        } else {
            iFilterSetting = D3DFILTER_NEAREST;
        }
        hResult = this->m_pObjectDevice->SetTextureStageState(0, D3DTSS_MINFILTER, iFilterSetting);
        if(hResult != 0) {
            WriteError(hResult, "SetObjectFiltering");
            return 0;
        }
        g_cCacheManager.Reset();
        for(i = 0;
            i < 8;
            ++i) {
            g_cColorGradient.SetupGradients(i, g_cColorGradient.m_vPlayerColors[i + 1], 2);
        }
        g_pfBlitSettler = BlitSettlerHardware;
        g_pfBlitObject = BlitObjectHardware;
        g_pfBlitVehicle = BlitVehicleHardware;
        g_pfBlitBuilding = BlitBuildingHardware;
        g_pfBlitBorderstone = BlitBorderstoneHardware;
        g_pfBlitAccessoryIcon = BlitAccessoryIconHardware;
        g_pfBlitWave = BlitWaveHardware;
    } else {
        for(i = 0;
            i < 8;
            ++i) {
            GradientFormat = CInterfaceD3D::GetGradientFormat();
            g_cColorGradient.SetupGradients(i, g_cColorGradient.m_vPlayerColors[i + 1], GradientFormat);
        }
        g_pfBlitSettler = BlitSettler;
        g_pfBlitObject = BlitObject;
        g_pfBlitVehicle = BlitVehicle;
        g_pfBlitBuilding = BlitBuilding;
        g_pfBlitBorderstone = BlitBorderstone;
        g_pfBlitAccessoryIcon = BlitAccessoryIcon;
        g_pfBlitWave = BlitWave;
    }
    if(GfxEngineSetup.bHardwareObjects != 0) {
        for(i = 0;
            i < 2;
            ++i) {
            this->m_pcPictureManager[i] = new CUploadCachePageManager(static_cast<struct IDirectDrawSurface7 *>(this->m_pDDObjectSurfacePtr[i]->GetSurfacePtr()), static_cast<struct IDirectDrawSurface7 *>(this->m_pDDSourceObjectSurfacePtr[i]->GetSurfacePtr()), this->m_pObjectDevice);
            if(this->m_pcPictureManager[i] == nullptr) {
                BBSupportTracePrintF(1, "GFX ENGINE: No memory to create PictureManager");
                return 0;
            }
        }
        this->m_pcPictureManager[0]->SetCurrentZoomFactor(GfxEngineSetup.fZoomFactor);
        memset(&sCaps, 0, sizeof(sCaps));
        sCaps.dwCaps = DDSCAPS_TEXTURE;
        hResult = this->m_pDDraw7->GetAvailableVidMem(&sCaps, &v13, reinterpret_cast<LPDWORD>(&uAvailableVidMemory));
        if(hResult != 0) {
            WriteError(hResult, "GetVideoMemory");
            return 0;
        }
        v27 = uAvailableVidMemory;
        BBSupportTracePrintF(1, "GFX ENGINE: Available vid mem for cache is %d", uAvailableVidMemory);
        v27 -= 1100000;
        v27 -= 50000;
        this->m_iNumberOfCachedSurfaces = 0;
        if(v27 > 0) {
            CSurfaceDescription cSurfaceDescr{};
            cSurfaceDescr.m_sSurfaceDescription.dwFlags = 4103;
            cSurfaceDescr.m_sSurfaceDescription.ddsCaps.dwCaps = 20480;
            cSurfaceDescr.m_sSurfaceDescription.dwWidth = 512;
            cSurfaceDescr.m_sSurfaceDescription.dwHeight = 512;
            cSurfaceDescr.m_sSurfaceDescription.ddpfPixelFormat.dwFlags = 65;
            cSurfaceDescr.m_sSurfaceDescription.ddpfPixelFormat.dwFourCC = 0;

            cSurfaceDescr.m_sSurfaceDescription.ddpfPixelFormat.dwRGBBitCount = 16;
            cSurfaceDescr.m_sSurfaceDescription.ddpfPixelFormat.dwRBitMask = 0xF000;
            cSurfaceDescr.m_sSurfaceDescription.ddpfPixelFormat.dwGBitMask = 0x0F00;
            cSurfaceDescr.m_sSurfaceDescription.ddpfPixelFormat.dwBBitMask = 0x00F0;
            cSurfaceDescr.m_sSurfaceDescription.ddpfPixelFormat.dwRGBAlphaBitMask = 0xF000;
            for(this->m_iNumberOfCachedSurfaces = uAvailableVidMemory != 1674288;
                uAvailableVidMemory != 1674288 && this->m_iNumberOfCachedSurfaces < 180;
                ++this->m_iNumberOfCachedSurfaces) {
                hResult = this->m_pDDraw7->CreateSurface(&cSurfaceDescr.m_sSurfaceDescription, &this->m_pCacheSurfaces[this->m_iNumberOfCachedSurfaces], nullptr);
                v30 = true;
                if(hResult != 0) {
                    if(hResult == DDERR_OUTOFVIDEOMEMORY) {
                        BBSupportTracePrintF(1, "GFX ENGINE: %d cache surfaces created. Running out of video mem!", this->m_iNumberOfCachedSurfaces);
                        break;
                    }
                    WriteError(hResult, "CreateCacheSurfaces");
                    return 0;
                }
                hResult = this->m_pDDraw7->GetAvailableVidMem(&sCaps, &v13, reinterpret_cast<LPDWORD>(&uAvailableVidMemory));
                if(hResult != 0) {
                    WriteError(hResult, "GetVideoMemory");
                    return 0;
                }
                if(uAvailableVidMemory == 1674288) {
                    v30 = false;
                }

                exceptionBlock = -1;
                this->m_pCacheManagers[this->m_iNumberOfCachedSurfaces] = new CCachePageManager(this->m_pCacheSurfaces[this->m_iNumberOfCachedSurfaces], nullptr, this->m_pObjectDevice);
                if(this->m_pCacheManagers[this->m_iNumberOfCachedSurfaces] == nullptr) {
                    BBSupportTracePrintF(1, "GFX ENGINE: Out of memory while creating CacheManager");
                    return 0;
                }
            }
        }
        g_iZoomGradient = GfxEngineSetup.iVertexSize / 24;
        g_iZoomInit = -65536;
        if(D3DObjectPtr->m_pcPictureManager[0] != nullptr) {
            D3DObjectPtr->m_pcPictureManager[0]->SetCurrentZoomFactor(GfxEngineSetup.fZoomFactor);
        }
    }
    D3DObjectPtr->m_bHardwareRuns = 1;
    BBSupportTracePrintF(1, "GFX ENGINE: Hardware init ok.");
    return 1;
}

// address=[0x2f665f0]
// Decompiled from char __thiscall CInterfaceD3D::InitSoftware(CInterfaceD3D *this)
bool CInterfaceD3D::InitSoftware(void) {

    // eax
    // [esp+8h] [ebp-4h]
    // [esp+8h] [ebp-4h]

    BBSupportTracePrintF(1, "GFX ENGINE: Begin software init.");
    if(this->m_bHardwareRuns != 0 || this->m_bSoftwareRuns != 0) {
        BBSupportTracePrintF(1, "GFX ENGINE: INIT SOFTWARE: Engine is already initialized!");
        return 1;
    } else {
        if(GfxEngineSetup.iCurrentGfxMode == 1) {
            _TRI_init_engine(1365);
        } else {
            _TRI_init_engine(1381);
        }
        g_cHeightAndTypeTable.InitShadeTables();
        D3DObjectPtr->AllocateEngineData(256);
        g_pSoftwareTexturePages = new unsigned char[0x2C0000u];
        if(g_pSoftwareTexturePages != 0) {
            for(int i = 0;
                i < 44;
                ++i) {
                g_pTextureTable[i] = g_pSoftwareTexturePages + (i << 16);
            }
            CInterfaceD3D::InitTexturePtr();
            for(int j = 0;
                j < 8;
                ++j) {
                int GradientFormat = CInterfaceD3D::GetGradientFormat();
                g_cColorGradient.SetupGradients(j, g_cColorGradient.m_vPlayerColors[j + 1], GradientFormat);
            }
            CInterfaceD3D::PreCalcTextureVertices(256);
            g_pfBlitSettler = BlitSettler;
            g_pfBlitObject = BlitObject;
            g_pfBlitVehicle = BlitVehicle;
            g_pfBlitBuilding = BlitBuilding;
            g_pfBlitBorderstone = BlitBorderstone;
            g_pfBlitAccessoryIcon = BlitAccessoryIcon;
            g_pfBlitWave = BlitWave;
            this->m_bSoftwareRuns = 1;
            BBSupportTracePrintF(1, "GFX ENGINE: Software init ok.");
            return 1;
        } else {
            BBSupportTracePrintF(1, "GFX ENGINE: Out of memory while allocating texture pages in system memory.");
            return 0;
        }
    }
}

// address=[0x2f667c0]
// Decompiled from char __thiscall CInterfaceD3D::BlitSurfaceToDIB(CInterfaceD3D *this, HWND hWnd, HGDIOBJ h)
bool CInterfaceD3D::BlitSurfaceToDIB(struct HWND__ *hWnd, struct HBITMAP__ *h) {
    HDC hdcSrc;
    HRESULT hResult = this->m_pFinalRenderSurface->GetDC(&hdcSrc);
    if(hResult == DDERR_SURFACELOST) {
        BBSupportTracePrintF(1, "GFX ENGINE: Blit to DIB failed! (Case 1)");
        return 0;
    } else {
        if(hResult != 0) {
            BBSupportTracePrintF(1, "GFX ENGINE: Blit to DIB failed! (Case 2)");
        }
        HDC hdc = GetDC(hWnd);
        HDC CompatibleDC = CreateCompatibleDC(hdc);
        SelectObject(CompatibleDC, h);
        if(!BitBlt(CompatibleDC, 0, 0, GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight, hdcSrc, 0, 0, SRCCOPY)) {
            BBSupportTracePrintF(1, "GFX ENGINE: Blit to DIB failed! (Case 3)");
        }
        this->m_pFinalRenderSurface->ReleaseDC(hdcSrc);
        ReleaseDC(hWnd, hdc);
        DeleteDC(CompatibleDC);
        return 1;
    }
}

// address=[0x468a2f8]
CBlitFX g_cBlitFX{};

// address=[0x2f668c0]
// Decompiled from char __thiscall CInterfaceD3D::BlitSurfaceToWindow(CInterfaceD3D *this)
bool CInterfaceD3D::BlitSurfaceToWindow(void) {
    int surfaceWidth;     // [esp+0h] [ebp-5Ch] BYREF
    int surfaceHeight;    // [esp+4h] [ebp-58h] BYREF
    int v8;               // [esp+10h] [ebp-4Ch]
    tagRECT v10;          // [esp+18h] [ebp-44h] BYREF
    tagRECT v11;          // [esp+28h] [ebp-34h] BYREF
    tagRECT sMiniMapRect; // [esp+48h] [ebp-14h] BYREF

    HRESULT hResult = 0;
    if(GfxEngineSetup.sRenderSetup.IsEditorMode()) {
        if(this->m_pDDGuiSurfaces[0] != nullptr && this->m_pPrimarySurface != nullptr) {
            v11.left = GfxEngineSetup.sRenderSetup.m_uX;
            v11.top = GfxEngineSetup.sRenderSetup.m_uY;
            v11.right = GfxEngineSetup.sRenderSetup.m_uWidth + GfxEngineSetup.sRenderSetup.m_uX;
            v11.bottom = GfxEngineSetup.sRenderSetup.m_uHeight + GfxEngineSetup.sRenderSetup.m_uY;
            _DDBLTFX *BlitStructPtr = g_cBlitFX.GetBlitStructPtr();
            hResult = this->m_pPrimarySurface->Blt(&v11, this->m_pDDGuiSurfaces[0], nullptr, 512, BlitStructPtr);
        }
        if(GfxEngineSetup.bDrawMiniMap != 0 && this->m_pMiniMapAreaSurface != nullptr && this->m_pPrimarySurface != nullptr) {
            hResult = -1;
            sMiniMapRect = g_sMiniMapRect;
            RECT sMiniMapSize = g_sMiniMapSize;
            D3DObjectPtr->m_pPrimarySurface->GetSurfaceSize(surfaceWidth, surfaceHeight);
            sMiniMapSize.right -= sMiniMapSize.left;
            sMiniMapSize.bottom -= sMiniMapSize.top;
            sMiniMapSize.left = 0;
            sMiniMapSize.top = 0;
            if(sMiniMapRect.bottom > surfaceHeight) {
                v8 = sMiniMapRect.bottom - surfaceHeight;
                sMiniMapRect.bottom = surfaceHeight;
                sMiniMapSize.bottom -= v8;
            }
            if(sMiniMapRect.right > surfaceWidth) {
                v8 = sMiniMapRect.right - surfaceWidth;
                sMiniMapRect.right = surfaceWidth;
                sMiniMapSize.right -= v8;
            }
            if(sMiniMapRect.top < 0) {
                v8 = abs(sMiniMapRect.top);
                sMiniMapRect.top += v8;
                sMiniMapSize.top += v8;
            }
            if(sMiniMapRect.left < 0) {
                v8 = abs(sMiniMapRect.left);
                sMiniMapRect.left += v8;
                sMiniMapSize.left += v8;
            }
            if(sMiniMapRect.top <= surfaceHeight || sMiniMapRect.left <= surfaceWidth) {
                hResult = CInterfaceD3D::SetCustomClipper(this->m_sMinimapClipper);
                if(hResult != 0) {
                    WriteError(hResult, "SetClipper2");
                    return 0;
                }
                hResult = D3DObjectPtr->m_pPrimarySurface->Blt(&sMiniMapRect, D3DObjectPtr->m_pMiniMapSurface, &sMiniMapSize, 0x8000, nullptr);
                if(hResult == 0) {
                    hResult = D3DObjectPtr->m_pPrimarySurface->Blt(&sMiniMapRect, D3DObjectPtr->m_pMiniMapAreaSurface, &sMiniMapSize, 0x8000, nullptr);
                }
            }
            hResult = CInterfaceD3D::ClearCustomClipper();
            if(hResult != 0) {
                WriteError(hResult, "SetClipper1");
                return 0;
            }
        }
    } else if(this->m_pFinalRenderSurface != nullptr && this->m_pPrimarySurface != nullptr) {
        v10.left = GfxEngineSetup.sRenderSetup.m_uX;
        v10.top = GfxEngineSetup.sRenderSetup.m_uY;
        v10.right = GfxEngineSetup.sRenderSetup.m_uWidth + GfxEngineSetup.sRenderSetup.m_uX;
        v10.bottom = GfxEngineSetup.sRenderSetup.m_uHeight + GfxEngineSetup.sRenderSetup.m_uY;
        _DDBLTFX *v3 = g_cBlitFX.GetBlitStructPtr();
        hResult = this->m_pPrimarySurface->Blt(&v10, this->m_pFinalRenderSurface, nullptr, 512, v3);
    }
    switch(hResult) {
    case 0:
        return 1;
    case -2005532222:
        hResult = this->m_pPrimarySurface->Restore();
        if(hResult != 0) {
            WriteError(hResult, "RestorePrimarySurface");
        }
        if(hResult == -2005532085) {
            BBSupportTracePrintF(1, "GFX ENGINE: Stop rendering because of inaccessability of primary surface!");
            this->m_bDisableRendering = 1;
        }
        break;
    case -2005532447:
        WriteError(DDERR_NOEXCLUSIVEMODE, "Exclusive mode down! Stop rendering...");
        this->m_bDisableRendering = 1;
        break;
    default:
        WriteError(hResult, "PrimarySurfaceBlit");
        break;
    }
    return 0;
}

// address=[0x2f66d00]
// Decompiled from BOOL __stdcall CInterfaceD3D::BlitDIBToSurface(HWND _hWnd, int _uWidth, int _uHeight, IDirectDrawSurface4 *_pDDSurface)
void CInterfaceD3D::BlitDIBToSurface(struct HWND__ *_hWnd, int _uWidth, int _uHeight, struct IDirectDrawSurface4 *_pDDSurface) {
    HDC v6;
    _pDDSurface->GetDC(&v6);
    HDC hdc = GetDC(_hWnd);
    HDC hdcSrc = CreateCompatibleDC(hdc);
    SelectObject(hdcSrc, GfxEngineSetup.hOutputBitmap);
    if(!BitBlt(v6, 0, 0, _uWidth, _uHeight, hdcSrc, 0, 0, SRCCOPY)) {
        BBSupportTracePrintF(1, "GFX ENGINE: Blit to Surface failed!");
    }
    _pDDSurface->ReleaseDC(v6);
    ReleaseDC(_hWnd, hdc);
    DeleteDC(hdcSrc);
}

// address=[0x2f66dc0]
// Decompiled from int __thiscall CInterfaceD3D::GetGradientFormat(CInterfaceD3D *this)
int CInterfaceD3D::GetGradientFormat(void) {

    if(this->m_bHardwareRuns != 0) {
        return 2;
    } else {
        return GfxEngineSetup.iCurrentGfxMode == 1;
    }
}

// address=[0x2f66e00]
// Decompiled from int __stdcall CInterfaceD3D::EnumModesCallback(struct _DDSURFACEDESC2 *a1, void *a2)
long __stdcall CInterfaceD3D::EnumModesCallback(struct _DDSURFACEDESC2 *a1, void *a2) {

    if(a1 == nullptr) {
        return 0;
    }
    if(a1->ddpfPixelFormat.dwRGBBitCount <= 0x10) {
        return 1;
    }
    if(a1->dwWidth == 640 && a1->dwHeight == 480) {
        D3DObjectPtr->m_bAvailableResolutions[0] = 1;
        return 1;
    } else if(a1->dwWidth == 800 && a1->dwHeight == 600) {
        D3DObjectPtr->m_bAvailableResolutions[1] = 1;
        return 1;
    } else if(a1->dwWidth == 1024 && a1->dwHeight == 768) {
        D3DObjectPtr->m_bAvailableResolutions[2] = 1;
        return 1;
    } else if(a1->dwWidth == 1280 && a1->dwHeight == 1024) {
        D3DObjectPtr->m_bAvailableResolutions[3] = 1;
        return 1;
    } else if(a1->dwWidth == 1600 && a1->dwHeight == 1200) {
        D3DObjectPtr->m_bAvailableResolutions[4] = 1;
        return 1;
    } else {
        return 1;
    }
}

// address=[0x2f66f40]
// Decompiled from int __stdcall CInterfaceD3D::EnumModesCallbackOld(_DDSURFACEDESC *a1, int a2)
long __stdcall CInterfaceD3D::EnumModesCallbackOld(struct _DDSURFACEDESC *a1, void *a2) {

    if(a1 == nullptr) {
        return 0;
    }
    if(a1->ddpfPixelFormat.dwRGBBitCount <= 0x10) {
        return 1;
    }
    if(a1->dwWidth == 640 && a1->dwHeight == 480) {
        D3DObjectPtr->m_bAvailableResolutions[0] = 1;
        return 1;
    } else if(a1->dwWidth == 800 && a1->dwHeight == 600) {
        D3DObjectPtr->m_bAvailableResolutions[1] = 1;
        return 1;
    } else if(a1->dwWidth == 1024 && a1->dwHeight == 768) {
        D3DObjectPtr->m_bAvailableResolutions[2] = 1;
        return 1;
    } else if(a1->dwWidth == 1280 && a1->dwHeight == 1024) {
        D3DObjectPtr->m_bAvailableResolutions[3] = 1;
        return 1;
    } else if(a1->dwWidth == 1600 && a1->dwHeight == 1200) {
        D3DObjectPtr->m_bAvailableResolutions[4] = 1;
        return 1;
    } else {
        return 1;
    }
}

// address=[0x468e470]
unsigned __int8 g_uColorPalettes[44][768];

// address=[0x468e3b0]
unsigned char *g_pLuminanceTablesStart;

// address=[0x468e3AC]
unsigned __int8 *g_pLuminanceTablesMemory;

bool __cdecl ReadTextureBitmap(int iSurfaceNumber, char *pData, bool bHiCol, bool bHQ) {
    unsigned int iPitch; // [esp+0h] [ebp-Ch] BYREF
    void *pTextureData;  // [esp+4h] [ebp-8h] BYREF
    int v7;              // [esp+8h] [ebp-4h]

    if(bHiCol) {
        v7 = D3DObjectPtr->m_pDDTextureSurfaces[iSurfaceNumber]->Lock(iPitch, pTextureData, 0);
        if(v7 != 0) {
            WriteError(v7, "LockTextureSurfaceForContentLoad");
            return false;
        }
        if(bHQ) {
            memcpy(pTextureData, pData, 0x20000u);
        } else {
            memcpy(pTextureData, pData, 0x8000u);
        }
        v7 = D3DObjectPtr->m_pDDTextureSurfaces[iSurfaceNumber]->Unlock();
        if(v7 != 0) {
            WriteError(v7, "UnlockTextureSurfaceForContentLoad");
            return false;
        }
    } else {
        memcpy((void *)(g_pSoftwareTexturePages + (iSurfaceNumber << 16)), pData, 0x10000u);
        memcpy(g_uColorPalettes[iSurfaceNumber], pData + 0x10000, sizeof(g_uColorPalettes[iSurfaceNumber]));
    }
    return true;
}

char __cdecl ReadTextureBitmapSet(bool _bHiColor, bool _bHQMode, bool _bIs555, int _iNumberOfPages) {
    unsigned __int8 *pGfxData; // [esp+0h] [ebp-18h]
    int k;                     // [esp+4h] [ebp-14h]
    int j;                     // [esp+8h] [ebp-10h]
    int i;                     // [esp+Ch] [ebp-Ch]
    unsigned __int8 *pGfxFile; // [esp+10h] [ebp-8h]
    char v10;                  // [esp+17h] [ebp-1h]

    if(g_pfForceReload == nullptr) {
        return 0;
    }
    pGfxFile = static_cast<unsigned __int8 *>(g_pfForceReload(1, _bHQMode, _bIs555));
    if(pGfxFile == nullptr) {
        return 0;
    }
    if(pGfxFile[3] != _iNumberOfPages) {
        return 0;
    }
    v10 = 1;
    while(*((_DWORD *)pGfxFile + 1) != 0 && ((*(_WORD *)pGfxFile & 2) != 0 && _bHiColor || (*(_WORD *)pGfxFile & 2) == 0 && !_bHiColor)) {
        pGfxFile += *((_DWORD *)pGfxFile + 1) + 8;
    }
    if(*((_DWORD *)pGfxFile + 1) == 0 && ((*(_WORD *)pGfxFile & 2) != 0 && _bHiColor || (*(_WORD *)pGfxFile & 2) == 0 && !_bHiColor)) {
        return 0;
    }
    pGfxData = pGfxFile + 8;
    if(_bHiColor) {
        if(_bHQMode) {
            for(i = 0;
                i < _iNumberOfPages;
                ++i) {
                if(!ReadTextureBitmap(i, (char *)&pGfxData[0x20000 * i], true, _bHQMode)) {
                    v10 = 0;
                    break;
                }
            }
        } else {
            for(j = 0;
                j < _iNumberOfPages;
                ++j) {
                if(!ReadTextureBitmap(j, (char *)&pGfxData[0x8000 * j], true, false)) {
                    v10 = 0;
                    break;
                }
            }
        }
    } else {
        for(k = 0;
            k < _iNumberOfPages;
            ++k) {
            if(!ReadTextureBitmap(k, (char *)&pGfxData[0x10300 * k], false, true)) {
                v10 = 0;
                break;
            }
        }
    }
    g_pfForceReload(0, true, GfxEngineSetup.iCurrentGfxMode == 1);
    return v10;
}

// address=[0x2f67080]
// Decompiled from char __thiscall CInterfaceD3D::LoadTexturePageContents(CInterfaceD3D *this)
bool CInterfaceD3D::LoadTexturePageContents(void) {

    // al
    // [esp-Ch] [ebp-18h]
    // [esp-8h] [ebp-14h]
    // [esp+4h] [ebp-8h]

    BBSupportTracePrintF(1, "GFX ENGINE: Read in all texture pages...");
    if(!GfxEngineSetup.sRenderSetup.IsHardwareLandscapeEngine()) {
        D3DObjectPtr->m_bHiTextureQuality = 1;
    }
    if(D3DObjectPtr == nullptr) {
        return 1;
    }

    if(ReadTextureBitmapSet(GfxEngineSetup.sRenderSetup.IsHardwareLandscapeEngine(), D3DObjectPtr->m_bHiTextureQuality, GfxEngineSetup.iCurrentGfxMode == 1, 44) == 0) {
        BBSupportTracePrintF(0, "GFX ENGINE: Error while loading texture set!");
        return 0;
    }
    if(GfxEngineSetup.sRenderSetup.IsHardwareLandscapeEngine()) {
        return 1;
    }
    BBSupportTracePrintF(1, "GFX ENGINE: Begin set up luminance tables.");
    for(int i = 0;
        i < 44;
        ++i) {
        _TRI_calculate_LUT_from_palette(g_uColorPalettes[i], &g_pLuminanceTablesStart[2048 * i]);
    }
    BBSupportTracePrintF(1, "GFX ENGINE: End set up luminance tables.");
    return 1;
}

// address=[0x2f67190]
// Decompiled from void __thiscall CInterfaceD3D::SetupViewport(CInterfaceD3D *this, DWORD a2, DWORD a3, DWORD a4, DWORD a5)
void CInterfaceD3D::SetupViewport(int a2, int a3, int a4, int a5) {

    // [esp+0h] [ebp-8h]
    // [esp+0h] [ebp-8h]

    this->m_sViewport.dwX = a2;
    this->m_sViewport.dwY = a3;
    this->m_sViewport.dwWidth = a4;
    this->m_sViewport.dwHeight = a5;
    if(this->LandscapeDevice != nullptr) {
        int v5 = this->LandscapeDevice->SetViewport(&this->m_sViewport);
        if(v5 != 0) {
            WriteError(v5, "SetLandscapeViewport");
        } else if(this->m_pObjectDevice != nullptr) {
            int v6 = this->m_pObjectDevice->SetViewport(&this->m_sViewport);
            if(v6 != 0) {
                WriteError(v6, "SetObjectViewport");
            }
        }
    }
}

// address=[0x2f67250]
// Decompiled from int __thiscall CInterfaceD3D::SetCustomClipper(CInterfaceD3D *this, struct SurfaceClipper *a2)
long CInterfaceD3D::SetCustomClipper(class SurfaceClipper &_rClipper) {
    if(_rClipper.GetClipper() == 0) {
        _wassert(L"clipper.GetClipper() != nullptr", L"MainGfxManager.cpp", 0x90Fu);
    }

    return this->m_pFinalRenderSurface->SetClipper(_rClipper.GetClipper());
}

// address=[0x2f672a0]
// Decompiled from int __thiscall CInterfaceD3D::ClearCustomClipper(CInterfaceD3D *this)
long CInterfaceD3D::ClearCustomClipper(void) {
    return this->m_pFinalRenderSurface->SetClipper(this->m_sClipper1.GetClipper());
}

// address=[0x0468E3B4]
_D3DTLVERTEX *g_pVertex;

// address=[0x0468E3B8]
D3DTLVERTEX *g_pVertexMax;

// address=[0x2f672d0]
// Decompiled from void __thiscall CInterfaceD3D::DeleteEngineData(CInterfaceD3D *this)
void CInterfaceD3D::DeleteEngineData(void) {

    if(this->D3DVertexPtr != nullptr) {
        operator delete[](this->D3DVertexPtr);
        this->D3DVertexPtr = nullptr;
        g_pVertexMax = nullptr;
        g_pVertex = nullptr;
    }
    if(g_pLuminanceTablesMemory != nullptr) {
        operator delete[](g_pLuminanceTablesMemory);
        g_pLuminanceTablesMemory = nullptr;
        g_pLuminanceTablesStart = nullptr;
    }
}

// address=[0x2f67350]
// Decompiled from int __thiscall CInterfaceD3D::BeginLandscapeScene(CInterfaceD3D *this)
long CInterfaceD3D::BeginLandscapeScene(void) {

    // [esp+0h] [ebp-8h]

    int v2 = -1;
    if(this->m_iLandscapeSceneLock != 0) {
        BBSupportTracePrintF(0, "GFX ENGINE: WARNING: LandscapeScene Lockcounter is %d instead of 0", this->m_iLandscapeSceneLock);
    } else {
        v2 = this->LandscapeDevice->BeginScene();
        if(v2 != 0) {
            WriteError(v2, "BeginLandscapeScene");
        }
        ++this->m_iLandscapeSceneLock;
    }
    return v2;
}

// address=[0x2f673e0]
// Decompiled from int __thiscall CInterfaceD3D::EndLandscapeScene(CInterfaceD3D *this)
long CInterfaceD3D::EndLandscapeScene(void) {

    // [esp+0h] [ebp-8h]

    if(this->m_iLandscapeSceneLock > 1) {
        BBSupportTracePrintF(0, "GFX ENGINE: WARNING: LandscapeScene Lockcounter is %d instead of 1", this->m_iLandscapeSceneLock);
    }
    int v2 = this->LandscapeDevice->EndScene();
    if(v2 != 0) {
        WriteError(v2, "EndLandscapeScene");
    }
    --this->m_iLandscapeSceneLock;
    return v2;
}

// address=[0x2f67460]
// Decompiled from int __thiscall CInterfaceD3D::BeginObjectScene(CInterfaceD3D *this)
long CInterfaceD3D::BeginObjectScene(void) {

    // [esp+0h] [ebp-8h]

    int v2 = -1;
    if(this->m_iObjectSceneLock != 0) {
        BBSupportTracePrintF(0, "GFX ENGINE: WARNING: ObjectScene Lockcounter is %d instead of 0", this->m_iObjectSceneLock);
    } else {
        v2 = this->m_pObjectDevice->BeginScene();
        if(v2 != 0) {
            WriteError(v2, "BeginObjectScene");
        }
        ++this->m_iObjectSceneLock;
    }
    return v2;
}

// address=[0x2f674f0]
// Decompiled from int __thiscall CInterfaceD3D::EndObjectScene(CInterfaceD3D *this)
long CInterfaceD3D::EndObjectScene(void) {

    // [esp+0h] [ebp-8h]

    if(this->m_iObjectSceneLock > 1) {
        BBSupportTracePrintF(0, "GFX ENGINE: WARNING: LandscapeScene Lockcounter is %d instead of 1", this->m_iObjectSceneLock);
    }
    int v2 = this->m_pObjectDevice->EndScene();
    if(v2 != 0) {
        WriteError(v2, "EndObjectScene");
    }
    --this->m_iObjectSceneLock;
    return v2;
}

// address=[0x2f67570]
// Decompiled from char __thiscall CInterfaceD3D::CreateCameraWindowSurface(CInterfaceD3D *this, int a2, int a3)
bool CInterfaceD3D::CreateCameraWindowSurface(int a2, int a3) {

    // al
    // [esp-10h] [ebp-20h]
    // [esp+0h] [ebp-10h]
    IDirectDraw7 *pDDraw; // [esp+4h] [ebp-Ch]

    CInterfaceD3D::DestroyCameraWindowSurface();
    this->m_pLandscapeCameraRenderSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
    if(this->m_pLandscapeCameraRenderSurface == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
    }

    if(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface) {
        pDDraw = this->m_pDDraw;
    } else {
        pDDraw = this->m_pDDraw7;
    }
    int hResult = this->m_pLandscapeCameraRenderSurface->CreateSurface(pDDraw, a2, a3, 1, GfxEngineSetup.sRenderSetup.IsHardwareLandscapeEngine(), 0, GfxEngineSetup.iCurrentGfxMode == 1, 0, 0, 0);
    if(hResult != 0) {
        WriteError(hResult, "CreateLandscapeSurface");
        return 0;
    }
    return 1;
}

// address=[0x2f67660]
// Decompiled from void __thiscall CInterfaceD3D::DestroyCameraWindowSurface(CInterfaceD3D *this)
void CInterfaceD3D::DestroyCameraWindowSurface(void) {

    if(this->m_pLandscapeCameraRenderSurface != nullptr) {
        if(this->m_pCurrentLandScapeRenderTarget == this->m_pLandscapeCameraRenderSurface) {
            _wassert(L"m_pCurrentLandScapeRenderTarget != m_pLandscapeCameraRenderSurface", L"MainGfxManager.cpp", 0x9D2u);
        }
        this->m_pLandscapeCameraRenderSurface->Release();
        if(this->m_pLandscapeCameraRenderSurface != nullptr) {
            delete this->m_pLandscapeCameraRenderSurface;
        }
        this->m_pLandscapeCameraRenderSurface = nullptr;
    }
}

// address=[0x2f676f0]
// Decompiled from int __thiscall CInterfaceD3D::SwitchLandscapeRenderTarget(CInterfaceD3D *this, bool a2)
long CInterfaceD3D::SwitchLandscapeRenderTarget(bool _bToCamera) {
    CSurface *renderTarget; // [esp+4h] [ebp-Ch]

    if(_bToCamera) {
        renderTarget = this->m_pLandscapeCameraRenderSurface;
    } else {
        renderTarget = this->m_pLandscapeSurface;
    }

    if(renderTarget == nullptr) {
        _wassert(L"renderTarget != nullptr", L"MainGfxManager.cpp", 0x9DDu);
    }
    if(GfxEngineSetup.sRenderSetup.IsHardwareLandscapeEngine()) {
        int hResult = renderTarget->SetAsRenderTarget(this->LandscapeDevice);
        if(hResult < 0) {
            return hResult;
        }
    }
    this->m_pCurrentLandScapeRenderTarget = renderTarget;
    return 0;
}

// address=[0x2f74fc0]
// Decompiled from int __thiscall CInterfaceD3D::GetGuiMemorySize(CInterfaceD3D *this)
int CInterfaceD3D::GetGuiMemorySize(void) {
    return this->m_iGuiSurfaceSize;
}

// address=[0x2f74fe0]
// Decompiled from void __thiscall CInterfaceD3D::SetGuiMemorySize(CInterfaceD3D *this, int a2)
void CInterfaceD3D::SetGuiMemorySize(int a2) {
    this->m_iGuiSurfaceSize = a2;
}

// address=[0x4697578]
int g_iLastUsedPage;

// address=[0x2f81fe0]
// Decompiled from void __thiscall CInterfaceD3D::InitTexturedLandscapeModule(CInterfaceD3D *this)
void CInterfaceD3D::InitTexturedLandscapeModule(void) {
    for(int i = 0;
        i < 44;
        ++i) {
        g_pTextureTable[i] = 0;
    }
    g_iLastUsedPage = 0;
    for(int j = 0;
        j < 44;
        ++j) {
        this->m_pDDTextureSurfaces[j] = nullptr;
    }
}

// address=[0x04696878]
struct TRIANGLE_CROSSING {
    float tu1;
    float tv1;
    float tu2;
    float tv2;
    float tu3;
    float tv3;
} PatternTripleVertices[4][4][6];

void __cdecl PreCalcTextureUVs(D3DTLVERTEX *a1, float a2, float a3, int a4) {
    D3DTLVERTEX *a1a; // [esp+Ch] [ebp+8h]
    D3DTLVERTEX *a1b; // [esp+Ch] [ebp+8h]
    D3DTLVERTEX *a1c; // [esp+Ch] [ebp+8h]
    D3DTLVERTEX *a1d; // [esp+Ch] [ebp+8h]
    D3DTLVERTEX *a1e; // [esp+Ch] [ebp+8h]
    D3DTLVERTEX *a1f; // [esp+Ch] [ebp+8h]
    float a3a;        // [esp+14h] [ebp+10h]

    switch(a4) {
    case 0:
        a3a = a3 + 1.0;
        a1->tu = (float)((float)(a2 * 0.25) + 0.125) + 0.0625;
        a1->tv = a3a * 0.25;
        a1a = a1 + 1;
        a1a->tu = (float)((float)(a2 * 0.25) + 0.125) - 0.0625;
        a1a->tv = a3a * 0.25;
        a1a[1].tu = (float)(a2 * 0.25) + 0.125;
        a1a[1].tv = (float)(a3a * 0.25) - 0.125;
        break;
    case 1:
        a1->tu = (float)(a2 * 0.25) + 0.125;
        a1->tv = (float)(a3 * 0.25) + 0.125;
        a1e = a1 + 1;
        a1e->tu = (float)(a2 * 0.25) + 0.0625;
        a1e->tv = (float)(a3 * 0.25) + 0.25;
        a1e[1].tu = a2 * 0.25;
        a1e[1].tv = (float)(a3 * 0.25) + 0.125;
        break;
    case 2:
        a1->tu = (float)(a2 * 0.25) + 0.125;
        a1->tv = (float)(a3 * 0.25) + 0.125;
        a1b = a1 + 1;
        a1b->tu = a2 * 0.25;
        a1b->tv = (float)(a3 * 0.25) + 0.125;
        a1b[1].tu = (float)(a2 * 0.25) + 0.0625;
        a1b[1].tv = a3 * 0.25;
        break;
    case 3:
        a1->tu = (float)((float)(a2 * 0.25) + 0.125) + 0.0625;
        a1->tv = a3 * 0.25;
        a1d = a1 + 1;
        a1d->tu = (float)(a2 * 0.25) + 0.125;
        a1d->tv = (float)(a3 * 0.25) + 0.125;
        a1d[1].tu = (float)((float)(a2 * 0.25) + 0.125) - 0.0625;
        a1d[1].tv = a3 * 0.25;
        break;
    case 4:
        a1->tu = (float)(a2 * 0.25) + 0.25;
        a1->tv = (float)(a3 * 0.25) + 0.125;
        a1c = a1 + 1;
        a1c->tu = (float)(a2 * 0.25) + 0.125;
        a1c->tv = (float)(a3 * 0.25) + 0.125;
        a1c[1].tu = (float)((float)(a2 * 0.25) + 0.125) + 0.0625;
        a1c[1].tv = a3 * 0.25;
        break;
    case 5:
        a1->tu = (float)(a2 * 0.25) + 0.25;
        a1->tv = (float)(a3 * 0.25) + 0.125;
        a1f = a1 + 1;
        a1f->tu = (float)((float)(a2 * 0.25) + 0.125) + 0.0625;
        a1f->tv = (float)(a3 * 0.25) + 0.25;
        a1f[1].tu = (float)(a2 * 0.25) + 0.125;
        a1f[1].tv = (float)(a3 * 0.25) + 0.125;
        break;
    default:
        return;
    }
}

// address=[0x2f82050]
// Decompiled from void __thiscall CInterfaceD3D::PreCalcTextureVertices(CInterfaceD3D *this, int a2)
void CInterfaceD3D::PreCalcTextureVertices(int a2) {
    float fOffset = 0.001953125;
    if(!GfxEngineSetup.sRenderSetup.IsHardwareLandscapeEngine()) {
        fOffset = 0.0;
    }
    for(int i = 0;
        i < 4;
        ++i) {
        for(int j = 0;
            j < 4;
            ++j) {
            for(int k = 0;
                k < 6;
                ++k) {
                D3DTLVERTEX a1[3]{};

                PreCalcTextureUVs(a1, (float)j, (float)i, k);
                PatternTripleVertices[j][i][k].tu1 = a1[0].tu + fOffset;
                PatternTripleVertices[j][i][k].tv1 = a1[0].tv + fOffset;
                PatternTripleVertices[j][i][k].tu2 = a1[1].tu + fOffset;
                PatternTripleVertices[j][i][k].tv2 = a1[1].tv + fOffset;
                PatternTripleVertices[j][i][k].tu3 = a1[2].tu + fOffset;
                PatternTripleVertices[j][i][k].tv3 = a1[2].tv + fOffset;
            }
        }
    }
}

// address=[0x0468E3BC]
unsigned char *CurrentTexturePagePtr;

// address=[0x2f82260]
// Decompiled from int __thiscall CInterfaceD3D::InitTexturePtr(CInterfaceD3D *this)
void CInterfaceD3D::InitTexturePtr(void) {
    g_iLastUsedPage = 0;
    CurrentTexturePagePtr = g_pTextureTable[0];
    _TRI_palette_LUT = g_pLuminanceTablesStart;
}
// address=[0x0469757C]
float g_fPatternSuboffsetX;
// address=[0x04697580]
float g_fPatternSuboffsetY;
// address=[0x04697584]
int s_iDarkTribeElement;
// address=[0x04697588]
int g_iFogFadeStep;
// address=[0x0469758C]
int g_iUsedFogFadeStep;

// address=[0x03E2E708]
float g_fHalfLineOffset = 0.001953125f;

// address=[0x04696875]
bool g_bHalfLine;
// address=[0x04696876]
bool g_bSplitTriangle;
// address=[0x04696877]
bool s_bDirtyVertexBuffer;

// address=[0x03ACD240]
unsigned char TEXTURE_PAGE_MAP[256] = {
    0x0FF,
    0x0FF,
    0x0FF,
    0x0FF,
    0x0FF,
    0x0FF,
    0x0FF,
    4,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0x0FF,
    1,
    0,
    0x0FF,
    0x0FF,
    0,
    0x0FF,
    2,
    0x0FF,
    0,
    0,
    0x14,
    0x15,
    0,
    0,
    8,
    0x0FF,
    0,
    0x0FF,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    7,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0x0A,
    0x0FF,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0x0F,
    0x0FF,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0x0FF,
    0x0FF,
    0x0FF,
    0x0FF,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0x11,
    0x0FF,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0x0D,
    0x0FF,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    3,
    0,
    0,
    0,
    0,
    0,
};

// address=[0x2f822a0]
// Decompiled from void __thiscall CInterfaceD3D::CalcTilingVerticesType1(CInterfaceD3D *this, int _LandscapeType)
void CInterfaceD3D::CalcTilingVerticesType1(int _LandscapeType) {

    // [esp+4h] [ebp-4h]

    CInterfaceD3D::ChangeCurrentTexturePage(s_iDarkTribeElement + TEXTURE_PAGE_MAP[_LandscapeType]);
    float fPatternSuboffsetX = g_fPatternSuboffsetX;
    if(g_fPatternSuboffsetX + 0.125f <= 1.0) {
        g_pVertex->tu = g_fPatternSuboffsetX + 0.125f;
    } else if(g_bHalfLine != 0) {
        g_pVertex->tu = g_fHalfLineOffset + 1.0f;
        g_bSplitTriangle = 1;
    } else {
        g_pVertex->tu = g_fPatternSuboffsetX + 0.125f;
    }
    g_pVertex->tv = g_fPatternSuboffsetY + 0.125f;
    ++g_pVertex;
    g_pVertex->tu = fPatternSuboffsetX;
    g_pVertex->tv = g_fPatternSuboffsetY + 0.125f;
    ++g_pVertex;
    g_pVertex->tu = fPatternSuboffsetX + 0.0625f;
    g_pVertex->tv = g_fPatternSuboffsetY;
    g_pVertex -= 2;
}

// address=[0x2f823f0]
// Decompiled from void __thiscall CInterfaceD3D::CalcTilingVerticesType2(CInterfaceD3D *this, int _LandscapeType)
void CInterfaceD3D::CalcTilingVerticesType2(int _LandscapeType) {
    CInterfaceD3D::ChangeCurrentTexturePage(s_iDarkTribeElement + TEXTURE_PAGE_MAP[_LandscapeType]);
    float v3 = g_fPatternSuboffsetX + 0.1875f;
    float v2 = g_fPatternSuboffsetX;
    if(g_fPatternSuboffsetX + 0.1875f > 1.0) {
        if(g_bHalfLine) {
            v3 = v3 - 1.0;
            v2 = g_fPatternSuboffsetX - 1.0;
        } else {
            v3 = g_fHalfLineOffset + 1.0;
            g_bSplitTriangle = 1;
        }
    }
    g_pVertex->tu = v3;
    g_pVertex->tv = g_fPatternSuboffsetY;
    ++g_pVertex;
    g_pVertex->tu = v2 + 0.125;
    g_pVertex->tv = g_fPatternSuboffsetY + 0.125;
    ++g_pVertex;
    g_pVertex->tu = v2 + 0.0625;
    g_pVertex->tv = g_fPatternSuboffsetY;
    g_pVertex -= 2;
}

// address=[0x2f82540]
// Decompiled from int __thiscall CInterfaceD3D::AllocateEngineData(CInterfaceD3D *this, signed int _iVertexCount)
int CInterfaceD3D::AllocateEngineData(int _iVertexCount) {
    _D3DTLVERTEX *v3;
    if(this->D3DVertexPtr != nullptr) {
        CInterfaceD3D::DeleteEngineData();
    }

    this->D3DVertexPtr = new D3DTLVERTEX[_iVertexCount];
    if(this->D3DVertexPtr == nullptr) {
        BBSupportTracePrintF(0, "GFX ENGINE: Not enough memory to allocate vertices");
        return 0;
    }
    for(signed int i = 0;
        i < _iVertexCount;
        ++i) {
        this->D3DVertexPtr[i].sz = 0.89999998;
        this->D3DVertexPtr[i].rhw = 0.5;
    }
    if(this->D3DVertexPtr != nullptr) {
        g_pVertexMax = this->D3DVertexPtr + 240; // Why even bother with _iVertexCount, if it's hardcoded to 240 here?
    }
    if(GfxEngineSetup.sRenderSetup.IsHardwareLandscapeEngine()) {
        return 1;
    }
    g_pLuminanceTablesMemory = (unsigned __int8 *)operator new[](0x16800u);
    if(g_pLuminanceTablesMemory == nullptr) {
        BBSupportTracePrintF(0, "GFX ENGINE: Not enough memory to allocate luminance tables!");
        g_pLuminanceTablesStart = nullptr;
        return 0;
    }
    g_pLuminanceTablesStart = (unsigned __int8 *)((unsigned int)(g_pLuminanceTablesMemory + 2047) & 0xFFFFF800);
    return 1;
}

// address=[0x2f85f40]
// Decompiled from void __thiscall CInterfaceD3D::ChangeCurrentTexturePage(CInterfaceD3D *this, int a2)
void CInterfaceD3D::ChangeCurrentTexturePage(int a2) {

    // eax

    if(a2 != g_iLastUsedPage) {
        CInterfaceD3D::RenderScene(s_bDirtyVertexBuffer);
        g_iLastUsedPage = a2;
        if(GfxEngineSetup.sRenderSetup.IsHardwareLandscapeEngine()) {
            this->LandscapeDevice->SetTexture(0, static_cast<LPDIRECTDRAWSURFACE7>(this->m_pDDTextureSurfaces[g_iLastUsedPage]->GetSurfacePtr()));
        } else {
            CurrentTexturePagePtr = g_pTextureTable[g_iLastUsedPage];
            _TRI_palette_LUT = &g_pLuminanceTablesStart[2048 * g_iLastUsedPage];
        }
    }
}

// address=[0x2f860c0]
// Decompiled from CSurface *__thiscall CInterfaceD3D::GetLandscapeRenderTargetSurface(CInterfaceD3D *this)
class CSurface *CInterfaceD3D::GetLandscapeRenderTargetSurface(void) {
    return this->m_pCurrentLandScapeRenderTarget;
}

// address=[0x3E2E700]
bool g_bRenderSuccess;

// address=[0x2f86180]
// Decompiled from void __thiscall CInterfaceD3D::RenderScene(CInterfaceD3D *this, bool _bCleanVertexBuffer)
void CInterfaceD3D::RenderScene(bool _bCleanVertexBuffer) {
    if(GfxEngineSetup.sRenderSetup.IsHardwareLandscapeEngine()) {
        if(g_pVertex - this->D3DVertexPtr > 0) {
            if(_bCleanVertexBuffer) {
                for(_D3DTLVERTEX *i = this->D3DVertexPtr;
                    i < g_pVertex;
                    i += 3) {
                    i->sx = (float)GfxEngineSetup.iCamFollowX + i->sx;
                    i->sy = (float)GfxEngineSetup.iCamFollowY + i->sy;
                    i[1].sx = (float)GfxEngineSetup.iCamFollowX + i[1].sx;
                    i[1].sy = (float)GfxEngineSetup.iCamFollowY + i[1].sy;
                    i[2].sx = (float)GfxEngineSetup.iCamFollowX + i[2].sx;
                    i[2].sy = (float)GfxEngineSetup.iCamFollowY + i[2].sy;
                }
            }
            int v2 = this->LandscapeDevice->DrawPrimitive(D3DPT_TRIANGLELIST, D3DFVF_TLVERTEX, this->D3DVertexPtr, g_pVertex - this->D3DVertexPtr, 0);
            if(v2 != 0) {
                WriteError(v2, "DrawPrimitive");
                g_bRenderSuccess = 0;
            }
        }
    } else {
        for(_D3DTLVERTEX *pVertex = this->D3DVertexPtr;
            pVertex < g_pVertex;
            pVertex += 3) {
            _TRI_draw_triangle(pVertex, pVertex + 1, pVertex + 2, CurrentTexturePagePtr, 8);
        }
    }
    g_pVertex = this->D3DVertexPtr;
}

bool s_bDeviceIdentified;
DDDEVICEIDENTIFIER2 s_sDeviceIdentifier;
int s_iMaxTextureWidth;

struct STextureFormats {
    unsigned __int8 b555;
    unsigned __int8 b565;
    unsigned __int8 b4444;
    unsigned __int8 b1555;
};

bool __cdecl MemorySmallerThanWithOffset(unsigned int a1, int a2, unsigned __int64 a3) {
    return (unsigned __int64)a1 + a2 >= a3;
}

int __stdcall D3DEnumPixelFormatsCallback(struct _DDPIXELFORMAT *a1, STextureFormats *a2) {
    if((a1->dwFlags & 0xE0000) != 0) {
        return 1;
    }
    if(a1->dwFourCC != 0) {
        return 1;
    }
    if(a1->dwRGBBitCount != 16) {
        return 1;
    }
    if((a1->dwFlags & 1) != 0) {
        if(a1->dwRBitMask == 3840 && a1->dwGBitMask == 240 && a1->dwBBitMask == 15 && a1->dwRGBAlphaBitMask == 0xF000) {
            a2->b4444 = 1;
        }
        if(a1->dwRBitMask == 31744 && a1->dwGBitMask == 992 && a1->dwBBitMask == 31 && a1->dwRGBAlphaBitMask == 0x8000) {
            a2->b1555 = 1;
        }
    } else {
        if(a1->dwRBitMask == 31744 && a1->dwGBitMask == 992 && a1->dwBBitMask == 31 && a1->dwRGBAlphaBitMask == 0) {
            a2->b555 = 1;
        }
        if(a1->dwRBitMask == 63488 && a1->dwGBitMask == 2016 && a1->dwBBitMask == 31 && a1->dwRGBAlphaBitMask == 0) {
            a2->b565 = 1;
        }
    }
    return 1;
}

// address=[0x2f8a910]
// Decompiled from int __thiscall CInterfaceD3D::IsInterface7Available(CInterfaceD3D *this, bool *_rSuccess, HWND a3)
int CInterfaceD3D::IsInterface7Available(bool &_rSuccess, struct HWND__ *a3) {

    int v4;                              // eax
    IDirectDrawSurface7 *v5;             // eax
    IDirect3DDevice7 **v6;               // [esp+0h] [ebp-2B8h]
    int v7;                              // [esp+10h] [ebp-2A8h]
    int v8;                              // [esp+14h] [ebp-2A4h] BYREF
    int v9;                              // [esp+18h] [ebp-2A0h] BYREF
    BOOL v11;                            // [esp+20h] [ebp-298h]
    int v12;                             // [esp+24h] [ebp-294h] BYREF
    IDirectDraw7 *pDDraw;                // [esp+28h] [ebp-290h]
    HMODULE hModule;                     // [esp+30h] [ebp-288h]
    CSurface *m_pTmpSurface;             // [esp+34h] [ebp-284h]
    CSurface *m_pPrimarySurface;         // [esp+38h] [ebp-280h]
    STextureFormats sPixelFormats;       // [esp+3Ch] [ebp-27Ch] BYREF
    bool v19;                            // [esp+43h] [ebp-275h] BYREF
    HRESULT hResult;                     // [esp+44h] [ebp-274h]
    DDCAPS v22;                          // [esp+4Ch] [ebp-26Ch] BYREF
    D3DDEVICEDESC7 sHardwareCapabilitys; // [esp+1C8h] [ebp-F0h] BYREF

    _rSuccess = false;
    s_bDeviceIdentified = 0;
    if(g_pDirectDraw != nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: DirectDraw already loaded");
        return 3;
    }
    hModule = GetModuleHandleA("DDRAW");
    if(hModule == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Direct Draw is not accessible!");
        return 1;
    }
    auto DirectDrawCreateEx = reinterpret_cast<decltype(&::DirectDrawCreateEx)>(GetProcAddress(hModule, "DirectDrawCreateEx"));
    if(DirectDrawCreateEx == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: DirectDrawCreateEx not found! Interface 7 or higher not available!");
        return 2;
    }
    hResult = DirectDrawCreateEx(nullptr, reinterpret_cast<LPVOID *>(&this->m_pDDraw), IID_IDirectDraw7, nullptr);
    if(hResult != 0) {
        WriteError(hResult, "CreateDirectDrawObject");
        return 3;
    }
    g_pDirectDraw = this->m_pDDraw;
    hResult = this->m_pDDraw->QueryInterface(IID_IDirectDraw7, reinterpret_cast<LPVOID *>(&this->m_pDDraw7));
    if(hResult != 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        WriteError(hResult, "QueryInterface");
        return 4;
    }

    hResult = this->m_pDDraw7->GetDeviceIdentifier(&s_sDeviceIdentifier, 1);
    if(hResult == 0) {
        BBSupportTracePrintF(1, "GFX ENGINE: ---------------GfxAdapter Info---------------");
        BBSupportTracePrintF(1, "GFX ENGINE: ");
        BBSupportTracePrintF(1, "GFX ENGINE: Driver          : %s", s_sDeviceIdentifier.szDriver);
        BBSupportTracePrintF(1, "GFX ENGINE: Description     : %s", s_sDeviceIdentifier.szDescription);
        BBSupportTracePrintF(1, "GFX ENGINE: DriverVersion   : %d", s_sDeviceIdentifier.liDriverVersion.LowPart);
        BBSupportTracePrintF(1, "GFX ENGINE: Manufactorer    : %d", s_sDeviceIdentifier.dwVendorId);
        BBSupportTracePrintF(1, "GFX ENGINE: Chipset         : %d", s_sDeviceIdentifier.dwDeviceId);
        BBSupportTracePrintF(1, "GFX ENGINE: ChipsetRevision : %d", s_sDeviceIdentifier.dwRevision);
        BBSupportTracePrintF(1, "GFX ENGINE: BoardRevision   : %d", s_sDeviceIdentifier.dwSubSysId);
        BBSupportTracePrintF(1, "GFX ENGINE: Certification   : %d", s_sDeviceIdentifier.dwWHQLLevel);
        BBSupportTracePrintF(1, "GFX ENGINE: ");
        BBSupportTracePrintF(1, "GFX ENGINE: ---------------------------------------------");
        s_bDeviceIdentified = 1;
    }
    hResult = this->m_pDDraw7->SetCooperativeLevel(a3, 8);
    if(hResult != 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        WriteError(hResult, "SetCooperativeLevel");
        return 5;
    }
    hResult = this->m_pDDraw7->QueryInterface(IID_IDirect3D7, (LPVOID *)&this->m_pIDirect3D7);
    if(hResult != 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        WriteError(hResult, "QueryD3DInterface");
        return 6;
    }
    this->m_pPrimarySurface = CSurface::CreateSurfacePtr(false);
    if(this->m_pPrimarySurface == nullptr) {
        CInterfaceD3D::CleanUpCheckObjects();
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 7;
    }
    if(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface) {
        pDDraw = this->m_pDDraw;
    } else {
        pDDraw = this->m_pDDraw7;
    }
    hResult = this->m_pPrimarySurface->CreateSurface(pDDraw, 0, 0, 1, 0, 0, 0, 1, 0, 0);
    if(hResult != 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        WriteError(hResult, "CreatePrimarySurface");
        return 8;
    }
    hResult = this->m_pPrimarySurface->GetPixelFormat(v19);
    if(hResult != 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        WriteError(hResult, "RetrievePixelFormatFromPrimarySurface");
        return 9;
    }
    this->m_pTmpSurface = CSurface::CreateSurfacePtr(false);
    if(this->m_pTmpSurface == nullptr) {
        CInterfaceD3D::CleanUpCheckObjects();
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 10;
    }

    hResult = this->m_pTmpSurface->CreateSurface(this->m_pDDraw7, 32, 32, 1, 1, 0, v19, 0, 0, 0);
    if(hResult != 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        WriteError(hResult, "CreateTestSurface");
        return 7;
    }
    v12 = 16;
    hResult = this->m_pPrimarySurface->GetBitDepth(v12);
    if(hResult != 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        WriteError(hResult, "GetBitDepthWhileCapChecking");
        return 12;
    }
    hResult = this->m_pPrimarySurface->GetSurfaceSize(v9, v8);
    if(hResult != 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        WriteError(hResult, "GetSurfaceSizeWhileCapChecking");
        return 11;
    }
    v7 = v12 / 8 * v8 * v9;
    v22.dwSize = 380;
    hResult = this->m_pDDraw->GetCaps(&v22, nullptr);
    if(hResult != 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        WriteError(hResult, "GetCapabilities");
        return 11;
    }
    if(!MemorySmallerThanWithOffset(v22.dwVidMemTotal, v7, 0x7A1200u)) {
        CInterfaceD3D::CleanUpCheckObjects();
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough video memory available!");
        return 13;
    }
    if(((v22.dwCaps & 0x40) == 0 || (v22.dwCaps & 0x4000000) == 0) && ((v22.dwNLVBCaps & 0x40) == 0 || (v22.dwNLVBCaps & 0x4000000) == 0)) {
        CInterfaceD3D::CleanUpCheckObjects();
        BBSupportTracePrintF(1, "GFX ENGINE: Needed blit capabilities are not supported!");
        return 14;
    }
    if((v22.dwCaps & 0x400000) == 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        BBSupportTracePrintF(1, "GFX ENGINE: Color keying is not in all needed blit modes available!");
        return 15;
    }
    LPDIRECTDRAWSURFACE7 pTmpSurface = static_cast<LPDIRECTDRAWSURFACE7>(this->m_pTmpSurface->GetSurfacePtr());
    hResult = this->m_pIDirect3D7->CreateDevice(IID_IDirect3DHALDevice, pTmpSurface, &this->LandscapeDevice);
    if(hResult != 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        WriteError(hResult, "CreateCheckDevice");
        return 16;
    }
    sHardwareCapabilitys.dpcTriCaps.dwSize = 56;
    sHardwareCapabilitys.dpcLineCaps.dwSize = 56;
    hResult = this->LandscapeDevice->GetCaps(&sHardwareCapabilitys);
    if(hResult != 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        WriteError(hResult, "Get3dCaps");
        return 17;
    }
    if((sHardwareCapabilitys.dwDevCaps & 0x200) == 0 || (sHardwareCapabilitys.dwDevCaps & 0x400) == 0 || (sHardwareCapabilitys.dwDeviceRenderBitDepth & 0x400) == 0 || sHardwareCapabilitys.dwMinTextureWidth > 0x80 || sHardwareCapabilitys.dwMinTextureHeight > 0x80 || sHardwareCapabilitys.dwMaxTextureWidth < 0x100) {
        CInterfaceD3D::CleanUpCheckObjects();
        BBSupportTracePrintF(1, "GFX ENGINE: A needed basic capability for the hardware renderer is unsupported!");
        return 18;
    }
    v11 = sHardwareCapabilitys.dwMaxTextureWidth >= 0x200;
    _rSuccess = v11;
    if(s_sDeviceIdentifier.dwDeviceId == 15623) {
        _rSuccess = false;
        BBSupportTracePrintF(1, "GFX ENGINE: No HWO rendering with permedia2 chipset!");
    }
    s_iMaxTextureWidth = sHardwareCapabilitys.dwMaxTextureWidth;
    if((sHardwareCapabilitys.dpcTriCaps.dwDestBlendCaps & 4) == 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        BBSupportTracePrintF(1, "GFX ENGINE: Needed alpha blend capabilities for hardware rendering unsupported!");
        return 19;
    }
    sPixelFormats.b555 = 0;
    sPixelFormats.b565 = 0;
    sPixelFormats.b4444 = 0;
    sPixelFormats.b1555 = 0;
    hResult = this->LandscapeDevice->EnumTextureFormats(reinterpret_cast<LPD3DENUMPIXELFORMATSCALLBACK>(D3DEnumPixelFormatsCallback), &sPixelFormats);
    if(hResult != 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        _rSuccess = false;
        WriteError(hResult, "EnumerateTextureFormats");
        return 20;
    }
    if(sPixelFormats.b555 == 0 && sPixelFormats.b565 == 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        _rSuccess = false;
        BBSupportTracePrintF(1, "GFX ENGINE: The needed texture formats are not supported by the hardware!");
        return 21;
    }
    if(sPixelFormats.b4444 == 0) {
        _rSuccess = false;
        BBSupportTracePrintF(1, "GFX ENGINE: The needed 4444 format are not supported by the hardware!");
    }
    if(s_sDeviceIdentifier.dwDeviceId == 35362 || s_sDeviceIdentifier.dwDeviceId == 35347 || s_sDeviceIdentifier.dwDeviceId == 37122) {
        _rSuccess = false;
        CInterfaceD3D::CleanUpCheckObjects();
        BBSupportTracePrintF(1, "GFX ENGINE: Savage chipset detected!");
        return 26;
    }
    if(this->LandscapeDevice != nullptr) {
        this->LandscapeDevice->Release();
        this->LandscapeDevice = nullptr;
    }
    if(this->m_pPrimarySurface != nullptr) {
        this->m_pPrimarySurface->Release();
        m_pPrimarySurface = this->m_pPrimarySurface;
        if(m_pPrimarySurface != nullptr) {
            delete m_pPrimarySurface;
        }
        this->m_pPrimarySurface = nullptr;
    }
    if(this->m_pTmpSurface != nullptr) {
        this->m_pTmpSurface->Release();
        m_pTmpSurface = this->m_pTmpSurface;
        if(m_pTmpSurface != nullptr) {
            delete m_pTmpSurface;
        }
        this->m_pTmpSurface = nullptr;
    }
    if(this->m_pIDirect3D7 != nullptr) {
        this->m_pIDirect3D7->Release();
        this->m_pIDirect3D7 = nullptr;
    }
    if(this->m_pDDraw7 == nullptr) {
        return 0;
    }
    this->m_pDDraw7->Release();
    this->m_pDDraw7 = nullptr;
    return 0;
}

// address=[0x2f8b530]
// Decompiled from int __thiscall CInterfaceD3D::IsInterface3Available(CInterfaceD3D *this, HWND a2)
int CInterfaceD3D::IsInterface3Available(struct HWND__ *a2) {

    // eax
    // [esp+10h] [ebp-1A4h]
    int v5;     // [esp+14h] [ebp-1A0h] BYREF
    int v6;     // [esp+18h] [ebp-19Ch] BYREF
    int v7;     // [esp+1Ch] [ebp-198h] BYREF
                // [esp+20h] [ebp-194h]
                // [esp+24h] [ebp-190h]
    bool v10;   // [esp+2Bh] [ebp-189h] BYREF
                // [esp+2Ch] [ebp-188h]
    DDCAPS v13; // [esp+34h] [ebp-180h] BYREF

    s_bDeviceIdentified = 0;
    if(g_pDirectDraw != nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: DirectDraw already loaded");
        return 3;
    }
    HRESULT v11 = DirectDrawCreate(nullptr, (LPDIRECTDRAW *)&this->m_pDDraw, nullptr);
    if(v11 != 0) {
        WriteError(v11, "CreateDirectDrawObject");
        return 3;
    }
    g_pDirectDraw = this->m_pDDraw;
    v11 = this->m_pDDraw->SetCooperativeLevel(a2, 8);
    if(v11 != 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        WriteError(v11, "SetCooperativeLevel");
        return 5;
    }
    this->m_pPrimarySurface = CSurface::CreateSurfacePtr(true);
    if(this->m_pPrimarySurface == nullptr) {
        CInterfaceD3D::CleanUpCheckObjects();
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 10;
    }
    v11 = this->m_pPrimarySurface->CreateSurface(this->m_pDDraw, 0, 0, 1, 0, 0, 0, 1, 0, 0);
    if(v11 != 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        WriteError(v11, "CreatePrimarySurface");
        return 8;
    }
    v11 = this->m_pPrimarySurface->GetPixelFormat(v10);
    if(v11 != 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        WriteError(v11, "RetrievePixelFormatFromPrimarySurface");
        return 9;
    }
    this->m_pTmpSurface = CSurface::CreateSurfacePtr(true);
    if(this->m_pTmpSurface == nullptr) {
        CInterfaceD3D::CleanUpCheckObjects();
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 10;
    }
    v11 = this->m_pTmpSurface->CreateSurface(this->m_pDDraw, 32, 32, 1, 1, 0, v10, 0, 0, 0);
    if(v11 != 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        WriteError(v11, "CreateTestSurface");
        return 7;
    }
    v7 = 16;
    v11 = this->m_pPrimarySurface->GetBitDepth(v7);
    if(v11 != 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        WriteError(v11, "GetBitDepthWhileCapChecking");
        return 12;
    }
    v11 = this->m_pPrimarySurface->GetSurfaceSize(v6, v5);
    if(v11 != 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        WriteError(v11, "GetSurfaceSizeWhileCapChecking");
        return 12;
    }
    int v4 = v7 / 8 * v5 * v6;
    v13.dwSize = 380;
    v11 = this->m_pDDraw->GetCaps(&v13, nullptr);
    if(v11 != 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        WriteError(v11, "GetCapabilities");
        return 11;
    }
    if(!MemorySmallerThanWithOffset(v13.dwVidMemTotal, v4, 0x3D0900u)) {
        CInterfaceD3D::CleanUpCheckObjects();
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough video memory available!");
        return 13;
    }
    if(((v13.dwCaps & 0x40) == 0 || (v13.dwCaps & 0x4000000) == 0) && ((v13.dwNLVBCaps & 0x40) == 0 || (v13.dwNLVBCaps & 0x4000000) == 0)) {
        CInterfaceD3D::CleanUpCheckObjects();
        BBSupportTracePrintF(1, "GFX ENGINE: Needed blit capabilities are not supported!");
        return 14;
    }
    if((v13.dwCaps & 0x400000) == 0) {
        CInterfaceD3D::CleanUpCheckObjects();
        BBSupportTracePrintF(1, "GFX ENGINE: Color keying is not in all needed blit modes available!");
        return 15;
    }
    if(this->LandscapeDevice != nullptr) {
        this->LandscapeDevice->Release();
        this->LandscapeDevice = nullptr;
    }
    if(this->m_pPrimarySurface != nullptr) {
        this->m_pPrimarySurface->Release();
        CSurface *m_pPrimarySurface = this->m_pPrimarySurface;
        if(m_pPrimarySurface != nullptr) {
            delete m_pPrimarySurface;
        }
        this->m_pPrimarySurface = nullptr;
    }
    if(this->m_pTmpSurface != nullptr) {
        this->m_pTmpSurface->Release();
        CSurface *m_pTmpSurface = this->m_pTmpSurface;
        if(m_pTmpSurface != nullptr) {
            delete m_pTmpSurface;
        }
        this->m_pTmpSurface = nullptr;
    }
    if(this->m_pIDirect3D7 != nullptr) {
        this->m_pIDirect3D7->Release();
        this->m_pIDirect3D7 = nullptr;
    }
    if(this->m_pDDraw7 == nullptr) {
        return 0;
    }
    this->m_pDDraw7->Release();
    this->m_pDDraw7 = nullptr;
    return 0;
}

// address=[0x2f8bba0]
// Decompiled from char __thiscall CInterfaceD3D::CanCreateEngine(CInterfaceD3D *this, bool a2)
bool CInterfaceD3D::CanCreateEngine(bool _bUseV3) {

    // eax
    // [esp+14h] [ebp-14h]
    // [esp+24h] [ebp-4h]

    CSurface *pSurface = CSurface::CreateSurfacePtr(_bUseV3);
    if(pSurface == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
    }

    int v5 = pSurface->CreateSurface(this->m_pDDraw, 32, 32, 1, 1, 0, GfxEngineSetup.iCurrentGfxMode == 1, 0, 0, 0);
    if(v5 != 0) {
        WriteError(v5, "CanRebuildEngine");
        delete pSurface;
        return 0;
    }

    pSurface->Release();
    delete pSurface;
    return 1;
}

// address=[0x2f8bcc0]
// Decompiled from void __thiscall CInterfaceD3D::CleanUpCheckObjects(CInterfaceD3D *this)
void CInterfaceD3D::CleanUpCheckObjects(void) {

    if(this->LandscapeDevice != nullptr) {
        this->LandscapeDevice->Release();
        this->LandscapeDevice = nullptr;
    }
    if(this->m_pPrimarySurface != nullptr) {
        this->m_pPrimarySurface->Release();
        if(this->m_pPrimarySurface != nullptr) {
            delete m_pPrimarySurface;
        }
        this->m_pPrimarySurface = nullptr;
    }
    if(this->m_pTmpSurface != nullptr) {
        this->m_pTmpSurface->Release();
        if(this->m_pTmpSurface != nullptr) {
            delete m_pTmpSurface;
        }
        this->m_pTmpSurface = nullptr;
    }
    if(this->m_pIDirect3D7 != nullptr) {
        this->m_pIDirect3D7->Release();
        this->m_pIDirect3D7 = nullptr;
    }
    if(this->m_pDDraw7 != nullptr) {
        this->m_pDDraw7->Release();
        this->m_pDDraw7 = nullptr;
    }
    if(this->m_pDDraw != nullptr) {
        this->m_pDDraw->Release();
        this->m_pDDraw = nullptr;
        g_pDirectDraw = nullptr;
    }
}

// address=[0x2f996f0]
// Decompiled from void __thiscall CInterfaceD3D::DecreaseCacheRetrys(CInterfaceD3D *this)
void CInterfaceD3D::DecreaseCacheRetrys(void) {

    --this->m_iCacheRetries;
}

// address=[0x2f99720]
// Decompiled from int __thiscall CInterfaceD3D::GetCacheRetrys(CInterfaceD3D *this)
int CInterfaceD3D::GetCacheRetrys(void) {

    return this->m_iCacheRetries;
}
