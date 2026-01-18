#ifndef IGFXENGINE_H
#define IGFXENGINE_H

#include "defines.h"

class IGfxEngine {
public:
    // address=[0x2f5a390]
     IGfxEngine(void);

    // address=[0x2f5a460]
     ~IGfxEngine(void);

    // address=[0x2f5a500]
    void  SetWindowPosition(int a2, int a3);

    // address=[0x2f5a520]
    void  SetTickCounterAdress(unsigned int * a2);

    // address=[0x2f5a540]
    bool  SetTemporaryText(char * Str, int a2, int a3, int a4, int a5, int a6);

    // address=[0x2f5a5e0]
    void  SetTriangleSize(int a2);

    // address=[0x2f5a6d0]
    void  SetScrollOffsets(int a2, int a3);

    // address=[0x2f5a770]
    void  SetCameraMode(int a2);

    // address=[0x2f5a7d0]
    void  SetGfxLayerAccess(int a2, struct T_GFX_MAP_ELEMENT * a3);

    // address=[0x2f5a860]
    bool  SetPlayerColor(int a1, struct SGfxColor & a2);

    // address=[0x2f5a8e0]
    bool  GetPlayerColor(int a2, struct SGfxColor & a3);

    // address=[0x2f5a930]
    void  SetObjectLayerAccess(struct SGfxObjectInfo * (__cdecl*)(unsigned int,int) a2, unsigned short * a3, unsigned short * a4);

    // address=[0x2f5a960]
    void  SetOwnerIDCallback(int (__cdecl*)(int) a2);

    // address=[0x2f5a980]
    bool  PutLandscapeObject(int a2, void * a3, void * a4);

    // address=[0x2f5ae60]
    void  SetReloadCallback(void * (__cdecl*)(int,bool,bool) a2);

    // address=[0x2f5ae80]
    void  SetGfxObject(struct SGfxObject * Src);

    // address=[0x2f5aec0]
    void  SetIndexWave1(int a2, int a3);

    // address=[0x2f5aef0]
    void  SetIndexWave2(int a2, int a3);

    // address=[0x2f5af20]
    void  SetIndexWave3(int a2, int a3);

    // address=[0x2f5af50]
    void  SetIndexWave4(int a2, int a3);

    // address=[0x2f5af80]
    void  SetIndexWave5(int a2, int a3);

    // address=[0x2f5afb0]
    void  SetIndexWave6(int a2, int a3);

    // address=[0x2f5afe0]
    void  SetIndexWave7(int a2, int a3);

    // address=[0x2f5b010]
    void  SetIndexWave8(int a2, int a3);

    // address=[0x2f5b040]
    void  SetIndexWave9(int a2, int a3);

    // address=[0x2f5b070]
    void  SetIndexWave10(int a2, int a3);

    // address=[0x2f5b0a0]
    void  SetIndexWave11(int a2, int a3);

    // address=[0x2f5b0d0]
    void  SetIndexWave12(int a2, int a3);

    // address=[0x2f5b100]
    void  SetIndexWave13(int a2, int a3);

    // address=[0x2f5b130]
    void  SetIndexWave14(int a2, int a3);

    // address=[0x2f5b160]
    void  SetIndexWave15(int a2, int a3);

    // address=[0x2f5b190]
    void  SetIndexWave16(int a2, int a3);

    // address=[0x2f5b1c0]
    void  SetIndexWave17(int a1, int a2);

    // address=[0x2f5b1f0]
    void  SetIndexWave18(int a1, int a2);

    // address=[0x2f5b220]
    void  SetIndexBorderstone(int a2, int a3);

    // address=[0x2f5b240]
    bool  EnableMiniMap(bool a2, int a3, int a4, struct HWND__ * a5);

    // address=[0x2f5b2f0]
    void  SetMiniMapColorCallback(struct SGfxColor * (__cdecl*)(unsigned int) a2);

    // address=[0x2f5b310]
    bool  EnableCameraWindow(bool a2, int a3, int a4, int a5, int a6);

    // address=[0x2f5b390]
    void  SetCameraViewPosition(int a2, int a3);

    // address=[0x2f5b420]
    void  SetCameraTriangleSize(int a2);

    // address=[0x2f5b4e0]
    int  GetRenderHeight(int a2);

    // address=[0x2f5b510]
    void  SetIconCallbacks(void (__cdecl*)(int) a2, unsigned char (__cdecl*)(int) a3);

    // address=[0x2f5b530]
    bool  PutAccessoryIcon(int a2, void * a3, void * a4);

    // address=[0x2f5b570]
    bool  InitEngine(struct SGfxRenderConfiguration a2, bool a3, int & a4, int & a5, int & a6);

    // address=[0x2f5b7c0]
    bool  RebuildRenderEnvironment(struct SGfxRenderConfiguration a2);

    // address=[0x2f5b8e0]
    struct SGfxRenderConfiguration const &  GetCurrentRenderConfiguration(void)const;

    // address=[0x2f5b8f0]
    bool  RenderFrame(bool a2, bool a3);

    // address=[0x2f5c400]
    bool  BlitFrameToDIB(struct HBITMAP__ * h);

    // address=[0x2f5c420]
    void  ForceMiniMapRefresh(void);

    // address=[0x2f5c440]
    void  DrawRectangle(struct tagRECT * a2, unsigned short a3);

    // address=[0x2f5c460]
    void  EnableIconLayer(bool a2);

    // address=[0x2f5c480]
    void  UpdateWorldPosition(int a2, int a2);

    // address=[0x2f5c540]
    void  UpdateWorldPosition(int a2);

    // address=[0x2f5c5f0]
    void  RenderCursor(void);

    // address=[0x2f5c610]
    void  ConvertMapPositionToWorldScreenOffsets(int a2, int a3, float & a4, float & a4);

    // address=[0x2f5c6d0]
    void  ConvertMapPositionToWorldScreenOffsets(int a1, int a2, int & a3, int & a4);

    // address=[0x2f5c760]
    bool  CanChangeGround(int a2, int a3, int a4);

    // address=[0x2f5c7a0]
    void  SetDarkLand(int a2, int a3, bool a4);

    // address=[0x2f5c810]
    void  SetFoggingFadingStep(int a2);

    // address=[0x2f5c8a0]
    void  SetFoggingUpdateMode(int a2);

    // address=[0x2f5c8c0]
    void  SetFoggingRange(int a2, int a3);

    // address=[0x2f5c950]
    bool  IsInitialized(void);

    // address=[0x2f5c980]
    bool  IsHardwareEngine(void);

    // address=[0x2f5c9b0]
    bool  Use4444Palettes(void);

    // address=[0x2f5c9e0]
    bool  IsGuiMode(void);

    // address=[0x2f5c9f0]
    bool  IsGfxEngineRebuilded(void);

    // address=[0x2f5ca30]
    int  GetGfxMode(void);

    // address=[0x2f5ca40]
    static unsigned short __cdecl ConvertRgbToHicol(int a1, int a2, int a3);

    // address=[0x2f5cae0]
    int  GetOutputWidth(void);

    // address=[0x2f5caf0]
    int  GetOutputHeight(void);

    // address=[0x2f5cb00]
    int  GetClosestMapPoint(int a2, int a3);

    // address=[0x2f5cb30]
    int  GetClosestMapPoint(int a2, int a3, int & a4, int & a5);

    // address=[0x2f5cb60]
    int  GetClosestMapPointOutsideMap(int a1, int a2, int & a3, int & a4);

    // address=[0x2f5cb90]
    static int __cdecl GetScreenOffsetsByMapIndices(int a1, int a2, int & a3, int & a4);

    // address=[0x2f5cc10]
    static int __cdecl GetScreenOffsetsByMapIndices(int a1, int & a2, int & a3);

    // address=[0x2f5cca0]
    float  GetCurrentZoomFactor(void);

    // address=[0x2f5ccc0]
    void  ShowCachePage(int a2, int a3);

    // address=[0x2f5cd20]
    void  SetWidthOfLeftGuiBorder(int a2);

    // address=[0x2f5f850]
    void  LockCursorShape(bool a2);

    // address=[0x2f5f870]
    void  SetCursorShape(bool a2, int a3);

    // address=[0x2f5f950]
    void  FixCursor(bool,bool);

    // address=[0x2f5fa70]
    int  GetCursorShape(void);

    // address=[0x2f5faa0]
    bool  IsCursorVisible(void);

    // address=[0x2f5fab0]
    bool  IsCursorFixed(void);

    // address=[0x2f5fac0]
    bool  IsResolutionPossible(int a2);

    // address=[0x2f5fe60]
    bool  CheckRenderConfiguration(struct SGfxRenderConfiguration a2);

    // address=[0x2f601f0]
    bool  ShowFrame(void);

    // address=[0x2f60260]
    bool  SolidColorFillGuiSurface(int a2, unsigned char a3, unsigned char a4, unsigned char a5);

    // address=[0x2f603b0]
    bool  SolidColorFillGuiSurface(int a2, unsigned char a3, unsigned char a4, unsigned char a5, struct tagRECT a6);

    // address=[0x2f699c0]
    bool  RenderObject(int a2, int a3, struct SGfxObjectInfo * a4, int a5, int a5);

    // address=[0x2f69c10]
    bool  RenderResource(int a2, int a3, void * a4, void * a5, void * a6, int a6);

    // address=[0x2f69ec0]
    void  SetEffectSystemInterfacePtr(class IGfxEffects * a2);

    // address=[0x2f72f10]
    void  EnableDebugValueCallback(int (__cdecl*)(int,int) a2);

    // address=[0x2f72f30]
    void  EnableDebugStringCallback(char * (__cdecl*)(void) a2);

    // address=[0x2f72f50]
    int  CreateGuiSurface(int a2, struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION * a3);

    // address=[0x2f73220]
    int  CreateGuiSurface(struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION * a2);

    // address=[0x2f732a0]
    bool  DestroyGuiSurface(int a2);

    // address=[0x2f73390]
    bool  SetVisibilityOfGuiSurface(int a2, bool a3);

    // address=[0x2f733f0]
    bool  SetGuiSurfaceDestinationPosition(int a2, int a3, int a4);

    // address=[0x2f73480]
    bool  SetGuiSurfaceDestinationRect(int a2, struct tagRECT const & a3);

    // address=[0x2f734f0]
    bool  GetGuiSurfaceDestinationRect(int a1, struct tagRECT & a2);

    // address=[0x2f73570]
    bool  GetGuiSurfaceDescription(int a2, struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION & a3);

    // address=[0x2f735c0]
    unsigned short *  BeginWriteToSurface(int a2, unsigned int & a3);

    // address=[0x2f73770]
    bool  EndWriteToSurface(int a2);

    // address=[0x2f737f0]
    bool  GetGuiSurfaceDC(int a2, struct HDC__ * * a3);

    // address=[0x2f73980]
    bool  ReleaseGuiSurfaceDC(int a2, struct HDC__ * a3);

    // address=[0x2f73a10]
    bool  SetGuiSurfaceClipRect(struct tagRECT const & Src);

    // address=[0x2f73b20]
    void  ClearGuiSurfaceClipRect(void);

private:
    // address=[0x2f5cd40]
    bool  IsHardwareRenderingAvailable(void);

    // address=[0x2f5cf10]
    bool  IsSoftwareRenderingAvailable(void);

    // address=[0x2f60510]
    bool  SetRenderEnvironment(void);

};


#endif // IGFXENGINE_H
