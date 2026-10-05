#ifndef CINTERFACED3D_H
#define CINTERFACED3D_H

#include "CCachePageManager.h"
#include "Gfx/CFixCursor.h"
#include "SurfaceClipper.h"
#include "defines.h"

#include <d3d.h>
#include <ddraw.h>

// address=[0x2f608c0]
void __cdecl WriteError(int, const char *);

// address=[0x4689be0]
extern class CInterfaceD3D *D3DObjectPtr;

class CUploadCachePageManager;
class CInterfaceD3D {
  public:
    // address=[0x2f5f250]
    void BlitCursor(void);

    // address=[0x2f5f390]
    bool HasCameraWindowSurface(void) const;

    // address=[0x2f62860]
    CInterfaceD3D(void);

    // address=[0x2f62b00]
    ~CInterfaceD3D(void);

    // address=[0x2f63450]
    bool InitCommon(void);

    // address=[0x2f643e0]
    bool InitCommonV3(void);

    // address=[0x2f65300]
    bool InitHardware(void);

    // address=[0x2f665f0]
    bool InitSoftware(void);

    // address=[0x2f667c0]
    bool BlitSurfaceToDIB(struct HWND__ *hWnd, struct HBITMAP__ *h);

    // address=[0x2f668c0]
    bool BlitSurfaceToWindow(void);

    // address=[0x2f66d00]
    void BlitDIBToSurface(struct HWND__ *_hWnd, int _uWidth, int _uHeight, struct IDirectDrawSurface4 *_pDDSurface);

    // address=[0x2f66dc0]
    int GetGradientFormat(void);

    // address=[0x2f66e00]
    static long __stdcall EnumModesCallback(struct _DDSURFACEDESC2 *a1, void *a2);

    // address=[0x2f66f40]
    static long __stdcall EnumModesCallbackOld(struct _DDSURFACEDESC *a1, void *a2);

    // address=[0x2f67080]
    bool LoadTexturePageContents(void);

    // address=[0x2f67190]
    void SetupViewport(int a2, int a3, int a4, int a5);

    // address=[0x2f67250]
    long SetCustomClipper(class SurfaceClipper &_rClipper);

    // address=[0x2f672a0]
    long ClearCustomClipper(void);

    // address=[0x2f672d0]
    void DeleteEngineData(void);

    // address=[0x2f67350]
    long BeginLandscapeScene(void);

    // address=[0x2f673e0]
    long EndLandscapeScene(void);

    // address=[0x2f67460]
    long BeginObjectScene(void);

    // address=[0x2f674f0]
    long EndObjectScene(void);

    // address=[0x2f67570]
    bool CreateCameraWindowSurface(int a2, int a3);

    // address=[0x2f67660]
    void DestroyCameraWindowSurface(void);

    // address=[0x2f676f0]
    long SwitchLandscapeRenderTarget(bool _bToCamera);

    // address=[0x2f74fc0]
    int GetGuiMemorySize(void);

    // address=[0x2f74fe0]
    void SetGuiMemorySize(int a2);

    // address=[0x2f81fe0]
    void InitTexturedLandscapeModule(void);

    // address=[0x2f82050]
    void PreCalcTextureVertices(int a2);

    // address=[0x2f82260]
    void InitTexturePtr(void);

    // address=[0x2f822a0]
    void CalcTilingVerticesType1(int _LandscapeType);

    // address=[0x2f823f0]
    void CalcTilingVerticesType2(int _LandscapeType);

    // address=[0x2f82540]
    int AllocateEngineData(int _iVertexCount);

    // address=[0x2f85f40]
    void ChangeCurrentTexturePage(int a2);

    // address=[0x2f860c0]
    class CSurface *GetLandscapeRenderTargetSurface(void);

    // address=[0x2f86180]
    void RenderScene(bool _bCleanVertexBuffer);

    // address=[0x2f8a910]
    int IsInterface7Available(bool &_rSuccess, struct HWND__ *a3);

    // address=[0x2f8b530]
    int IsInterface3Available(struct HWND__ *a2);

    // address=[0x2f8bba0]
    bool CanCreateEngine(bool _bUseV3);

    // address=[0x2f8bcc0]
    void CleanUpCheckObjects(void);

    // address=[0x2f996f0]
    void DecreaseCacheRetrys(void);

    // address=[0x2f99720]
    int GetCacheRetrys(void);

    // Type information members
  public:
    _D3DTLVERTEX *D3DVertexPtr;
    IDirectDraw7 *m_pDDraw;
    SurfaceClipper m_sClipper1;
    SurfaceClipper m_sMinimapClipper;
    IDirect3D7 *m_pIDirect3D7;
    IDirect3DDevice7 *LandscapeDevice;
    IDirect3DDevice7 *m_pObjectDevice;
    D3DVIEWPORT7 m_sViewport;
    IDirectDraw7 *m_pDDraw7;
    CSurface *m_pLandscapeSurface;
    CSurface *m_pLandscapeCameraRenderSurface;
    CSurface *m_pCurrentLandScapeRenderTarget;
    CSurface *m_pFinalRenderSurface;
    CSurface *m_pTmpSurface;
    CSurface *m_pPrimarySurface;
    CSurface *m_pDDTextureSurfaces[44];
    CSurface *m_pDDObjectSurfacePtr[2];
    CSurface *m_pDDSourceObjectSurfacePtr[2];
    CSurface *m_pMiniMapSurface;
    CSurface *m_pMiniMapAreaSurface;
    CSurface *m_pDDGuiSurfaces[14];
    CSurface *m_pMoveCursorSurface;
    CSurface *m_pZoomCursorSurface;
    LPDIRECTDRAWSURFACE7 m_pCacheSurfaces[180];
    int m_iNumberOfCachedSurfaces;
    CCachePageManager *m_pCacheManagers[180];
    unsigned __int8 m_bSoftwareRuns;
    unsigned __int8 m_bHardwareRuns;
    unsigned __int8 m_bAvailableResolutions[5];
    unsigned __int8 m_bEngineWasRebuilded;
    CUploadCachePageManager *m_pcPictureManager[2];
    int m_iObjectSceneLock;
    int m_iLandscapeSceneLock;
    int m_iGuiSurfaceSize;
    int m_iSurfaceSize;
    int m_iCacheRetries;
    unsigned __int8 m_bDisableRendering;
    unsigned __int8 m_bHiTextureQuality;
    unsigned __int8 m_bForceBlt;
    unsigned __int8 m_bRefreshTextureSurfaces;
    CFixCursor m_cMoveCursor;
    CFixCursor m_cZoomCursor;
};

#endif // CINTERFACED3D_H
