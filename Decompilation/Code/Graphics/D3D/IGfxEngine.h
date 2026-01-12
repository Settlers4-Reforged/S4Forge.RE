#ifndef IGFXENGINE_H
#define IGFXENGINE_H

class IGfxEngine {
public:
    // address=[0x2f5a390]
     IGfxEngine(void);

    // address=[0x2f5a460]
     ~IGfxEngine(void);

    // address=[0x2f5a500]
    void  SetWindowPosition(int,int);

    // address=[0x2f5a520]
    void  SetTickCounterAdress(unsigned int *);

    // address=[0x2f5a540]
    bool  SetTemporaryText(char *,int,int,int,int,int);

    // address=[0x2f5a5e0]
    void  SetTriangleSize(int);

    // address=[0x2f5a6d0]
    void  SetScrollOffsets(int,int);

    // address=[0x2f5a770]
    void  SetCameraMode(int);

    // address=[0x2f5a7d0]
    void  SetGfxLayerAccess(int,struct T_GFX_MAP_ELEMENT *);

    // address=[0x2f5a860]
    bool  SetPlayerColor(int,struct SGfxColor &);

    // address=[0x2f5a8e0]
    bool  GetPlayerColor(int,struct SGfxColor &);

    // address=[0x2f5a930]
    void  SetObjectLayerAccess(struct SGfxObjectInfo * (__cdecl*)(unsigned int,int),unsigned short *,unsigned short *);

    // address=[0x2f5a960]
    void  SetOwnerIDCallback(int (__cdecl*)(int));

    // address=[0x2f5a980]
    bool  PutLandscapeObject(int,void *,void *);

    // address=[0x2f5ae60]
    void  SetReloadCallback(void * (__cdecl*)(int,bool,bool));

    // address=[0x2f5ae80]
    void  SetGfxObject(struct SGfxObject *);

    // address=[0x2f5aec0]
    void  SetIndexWave1(int,int);

    // address=[0x2f5aef0]
    void  SetIndexWave2(int,int);

    // address=[0x2f5af20]
    void  SetIndexWave3(int,int);

    // address=[0x2f5af50]
    void  SetIndexWave4(int,int);

    // address=[0x2f5af80]
    void  SetIndexWave5(int,int);

    // address=[0x2f5afb0]
    void  SetIndexWave6(int,int);

    // address=[0x2f5afe0]
    void  SetIndexWave7(int,int);

    // address=[0x2f5b010]
    void  SetIndexWave8(int,int);

    // address=[0x2f5b040]
    void  SetIndexWave9(int,int);

    // address=[0x2f5b070]
    void  SetIndexWave10(int,int);

    // address=[0x2f5b0a0]
    void  SetIndexWave11(int,int);

    // address=[0x2f5b0d0]
    void  SetIndexWave12(int,int);

    // address=[0x2f5b100]
    void  SetIndexWave13(int,int);

    // address=[0x2f5b130]
    void  SetIndexWave14(int,int);

    // address=[0x2f5b160]
    void  SetIndexWave15(int,int);

    // address=[0x2f5b190]
    void  SetIndexWave16(int,int);

    // address=[0x2f5b1c0]
    void  SetIndexWave17(int,int);

    // address=[0x2f5b1f0]
    void  SetIndexWave18(int,int);

    // address=[0x2f5b220]
    void  SetIndexBorderstone(int,int);

    // address=[0x2f5b240]
    bool  EnableMiniMap(bool,int,int,struct HWND__ *);

    // address=[0x2f5b2f0]
    void  SetMiniMapColorCallback(struct SGfxColor * (__cdecl*)(unsigned int));

    // address=[0x2f5b310]
    bool  EnableCameraWindow(bool,int,int,int,int);

    // address=[0x2f5b390]
    void  SetCameraViewPosition(int,int);

    // address=[0x2f5b420]
    void  SetCameraTriangleSize(int);

    // address=[0x2f5b4e0]
    int  GetRenderHeight(int);

    // address=[0x2f5b510]
    void  SetIconCallbacks(void (__cdecl*)(int),unsigned char (__cdecl*)(int));

    // address=[0x2f5b530]
    bool  PutAccessoryIcon(int,void *,void *);

    // address=[0x2f5b570]
    bool  InitEngine(struct SGfxRenderConfiguration,bool,int &,int &,int &);

    // address=[0x2f5b7c0]
    bool  RebuildRenderEnvironment(struct SGfxRenderConfiguration);

    // address=[0x2f5b8e0]
    struct SGfxRenderConfiguration const &  GetCurrentRenderConfiguration(void)const;

    // address=[0x2f5b8f0]
    bool  RenderFrame(bool,bool);

    // address=[0x2f5c400]
    bool  BlitFrameToDIB(struct HBITMAP__ *);

    // address=[0x2f5c420]
    void  ForceMiniMapRefresh(void);

    // address=[0x2f5c440]
    void  DrawRectangle(struct tagRECT *,unsigned short);

    // address=[0x2f5c460]
    void  EnableIconLayer(bool);

    // address=[0x2f5c480]
    void  UpdateWorldPosition(int,int);

    // address=[0x2f5c540]
    void  UpdateWorldPosition(int);

    // address=[0x2f5c5f0]
    void  RenderCursor(void);

    // address=[0x2f5c610]
    void  ConvertMapPositionToWorldScreenOffsets(int,int,float &,float &);

    // address=[0x2f5c6d0]
    void  ConvertMapPositionToWorldScreenOffsets(int,int,int &,int &);

    // address=[0x2f5c760]
    bool  CanChangeGround(int,int,int);

    // address=[0x2f5c7a0]
    void  SetDarkLand(int,int,bool);

    // address=[0x2f5c810]
    void  SetFoggingFadingStep(int);

    // address=[0x2f5c8a0]
    void  SetFoggingUpdateMode(int);

    // address=[0x2f5c8c0]
    void  SetFoggingRange(int,int);

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
    static unsigned short __cdecl ConvertRgbToHicol(int,int,int);

    // address=[0x2f5cae0]
    int  GetOutputWidth(void);

    // address=[0x2f5caf0]
    int  GetOutputHeight(void);

    // address=[0x2f5cb00]
    int  GetClosestMapPoint(int,int);

    // address=[0x2f5cb30]
    int  GetClosestMapPoint(int,int,int &,int &);

    // address=[0x2f5cb60]
    int  GetClosestMapPointOutsideMap(int,int,int &,int &);

    // address=[0x2f5cb90]
    static int __cdecl GetScreenOffsetsByMapIndices(int,int,int &,int &);

    // address=[0x2f5cc10]
    static int __cdecl GetScreenOffsetsByMapIndices(int,int &,int &);

    // address=[0x2f5cca0]
    float  GetCurrentZoomFactor(void);

    // address=[0x2f5ccc0]
    void  ShowCachePage(int,int);

    // address=[0x2f5cd20]
    void  SetWidthOfLeftGuiBorder(int);

    // address=[0x2f5f850]
    void  LockCursorShape(bool);

    // address=[0x2f5f870]
    void  SetCursorShape(bool,int);

    // address=[0x2f5f950]
    void  FixCursor(bool,bool);

    // address=[0x2f5fa70]
    int  GetCursorShape(void);

    // address=[0x2f5faa0]
    bool  IsCursorVisible(void);

    // address=[0x2f5fab0]
    bool  IsCursorFixed(void);

    // address=[0x2f5fac0]
    bool  IsResolutionPossible(int);

    // address=[0x2f5fe60]
    bool  CheckRenderConfiguration(struct SGfxRenderConfiguration);

    // address=[0x2f601f0]
    bool  ShowFrame(void);

    // address=[0x2f60260]
    bool  SolidColorFillGuiSurface(int,unsigned char,unsigned char,unsigned char);

    // address=[0x2f603b0]
    bool  SolidColorFillGuiSurface(int,unsigned char,unsigned char,unsigned char,struct tagRECT);

    // address=[0x2f699c0]
    bool  RenderObject(int,int,struct SGfxObjectInfo *,int,int);

    // address=[0x2f69c10]
    bool  RenderResource(int,int,void *,void *,void *,int);

    // address=[0x2f69ec0]
    void  SetEffectSystemInterfacePtr(class IGfxEffects *);

    // address=[0x2f72f10]
    void  EnableDebugValueCallback(int (__cdecl*)(int,int));

    // address=[0x2f72f30]
    void  EnableDebugStringCallback(char * (__cdecl*)(void));

    // address=[0x2f72f50]
    int  CreateGuiSurface(int,struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION *);

    // address=[0x2f73220]
    int  CreateGuiSurface(struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION *);

    // address=[0x2f732a0]
    bool  DestroyGuiSurface(int);

    // address=[0x2f73390]
    bool  SetVisibilityOfGuiSurface(int,bool);

    // address=[0x2f733f0]
    bool  SetGuiSurfaceDestinationPosition(int,int,int);

    // address=[0x2f73480]
    bool  SetGuiSurfaceDestinationRect(int,struct tagRECT const &);

    // address=[0x2f734f0]
    bool  GetGuiSurfaceDestinationRect(int,struct tagRECT &);

    // address=[0x2f73570]
    bool  GetGuiSurfaceDescription(int,struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION &);

    // address=[0x2f735c0]
    unsigned short *  BeginWriteToSurface(int,unsigned int &);

    // address=[0x2f73770]
    bool  EndWriteToSurface(int);

    // address=[0x2f737f0]
    bool  GetGuiSurfaceDC(int,struct HDC__ * *);

    // address=[0x2f73980]
    bool  ReleaseGuiSurfaceDC(int,struct HDC__ *);

    // address=[0x2f73a10]
    bool  SetGuiSurfaceClipRect(struct tagRECT const &);

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
