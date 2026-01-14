#ifndef CINTERFACED3D_H
#define CINTERFACED3D_H

class CInterfaceD3D {
public:
    // address=[0x2f5f250]
    void  BlitCursor(void);

    // address=[0x2f5f390]
    bool  HasCameraWindowSurface(void)const;

    // address=[0x2f62860]
     CInterfaceD3D(void);

    // address=[0x2f62b00]
     ~CInterfaceD3D(void);

    // address=[0x2f63450]
    bool  InitCommon(void);

    // address=[0x2f643e0]
    bool  InitCommonV3(void);

    // address=[0x2f65300]
    bool  InitHardware(void);

    // address=[0x2f665f0]
    bool  InitSoftware(void);

    // address=[0x2f667c0]
    bool  BlitSurfaceToDIB(struct HWND__ *,struct HBITMAP__ *);

    // address=[0x2f668c0]
    bool  BlitSurfaceToWindow(void);

    // address=[0x2f66d00]
    void  BlitDIBToSurface(struct HWND__ *,int,int,struct IDirectDrawSurface4 *);

    // address=[0x2f66dc0]
    int  GetGradientFormat(void);

    // address=[0x2f66e00]
    static long __stdcall EnumModesCallback(struct _DDSURFACEDESC2 *,void *);

    // address=[0x2f66f40]
    static long __stdcall EnumModesCallbackOld(struct _DDSURFACEDESC *,void *);

    // address=[0x2f67080]
    bool  LoadTexturePageContents(void);

    // address=[0x2f67190]
    void  SetupViewport(int,int,int,int);

    // address=[0x2f67250]
    long  SetCustomClipper(class SurfaceClipper &);

    // address=[0x2f672a0]
    long  ClearCustomClipper(void);

    // address=[0x2f672d0]
    void  DeleteEngineData(void);

    // address=[0x2f67350]
    long  BeginLandscapeScene(void);

    // address=[0x2f673e0]
    long  EndLandscapeScene(void);

    // address=[0x2f67460]
    long  BeginObjectScene(void);

    // address=[0x2f674f0]
    long  EndObjectScene(void);

    // address=[0x2f67570]
    bool  CreateCameraWindowSurface(int,int);

    // address=[0x2f67660]
    void  DestroyCameraWindowSurface(void);

    // address=[0x2f676f0]
    long  SwitchLandscapeRenderTarget(bool);

    // address=[0x2f74fc0]
    int  GetGuiMemorySize(void);

    // address=[0x2f74fe0]
    void  SetGuiMemorySize(int);

    // address=[0x2f81fe0]
    void  InitTexturedLandscapeModule(void);

    // address=[0x2f82050]
    void  PreCalcTextureVertices(int);

    // address=[0x2f82260]
    void  InitTexturePtr(void);

    // address=[0x2f822a0]
    void  CalcTilingVerticesType1(int);

    // address=[0x2f823f0]
    void  CalcTilingVerticesType2(int);

    // address=[0x2f82540]
    int  AllocateEngineData(int);

    // address=[0x2f85f40]
    void  ChangeCurrentTexturePage(int);

    // address=[0x2f860c0]
    class CSurface *  GetLandscapeRenderTargetSurface(void);

    // address=[0x2f86180]
    void  RenderScene(bool);

    // address=[0x2f8a910]
    int  IsInterface7Available(bool &,struct HWND__ *);

    // address=[0x2f8b530]
    int  IsInterface3Available(struct HWND__ *);

    // address=[0x2f8bba0]
    bool  CanCreateEngine(bool);

    // address=[0x2f8bcc0]
    void  CleanUpCheckObjects(void);

    // address=[0x2f996f0]
    void  DecreaseCacheRetrys(void);

    // address=[0x2f99720]
    int  GetCacheRetrys(void);

};


#endif // CINTERFACED3D_H
