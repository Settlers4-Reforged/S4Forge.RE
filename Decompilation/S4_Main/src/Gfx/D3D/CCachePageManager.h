#ifndef CCACHEPAGEMANAGER_H
#define CCACHEPAGEMANAGER_H

#include "Gfx/SSmallRectangle.h"
#include "defines.h"

#include <d3dtypes.h>

class CCachePageManager {
  public:
    // address=[0x2f5f420]
    void SetCurrentZoomFactor(float a2);

    // address=[0x2f69960]
    bool IsSourceSurfaceLocked(void);

    // address=[0x2f69980]
    bool IsVideoSurfaceLocked(void);

    // address=[0x2f87760]
    CCachePageManager(struct IDirectDrawSurface7 *a2, struct IDirectDrawSurface7 *a3, struct IDirect3DDevice7 *a4);

    // address=[0x2f878f0]
    ~CCachePageManager(void);

    // address=[0x2f87940]
    bool GetPictureArea(float _fBlitX, float _fBlitY, int _iWidth, int _iHeight, int _iShading, int _iShifting, int &_iPosX, int &_iPosY);

    // address=[0x2f87b30]
    long EraseExtensionAreas(int _iIndex, int a3, int a4, int a5, int a6, bool a7);

    // address=[0x2f87db0]
    bool UploadData(long &_rResult);

    // address=[0x2f87ea0]
    bool UploadDataAndRender(long &_rResult);

    // address=[0x2f88440]
    bool ShowPageContent(long &_rResult);

    // address=[0x2f888b0]
    void ReleaseData(void);

    // address=[0x2f888f0]
    long RenderCacheObject(int _iIndex, float _fX, float _fY, int _iShading, int _iFlags, int _iShift, bool a8);

    // address=[0x2f89350]
    long LockSourceSurface(int &_rPitch, unsigned short *&_rSurface);

    // address=[0x2f89400]
    long LockVideoSurface(int &_rPitch, unsigned short *&_rSurface);

    // address=[0x2f894b0]
    long UnlockSourceSurface(void);

    // address=[0x2f89500]
    long UnlockVideoSurface(void);

    // address=[0x2f8a420]
    bool IsData(void);

    // address=[0x2f99770]
    int GetLastCacheObjectNr(void);

  protected:
    // address=[0x46c1698]
    static float sm_fZoomFactor;

    // address=[0x46c16a0]
    static float sm_fTextureCoordTable[512];

    static D3DTLVERTEX sm_sVertexList[576];

    // Type information members
  public:
    IDirectDrawSurface7 *m_pSystemTexture;
    IDirectDrawSurface7 *m_pVideoTexture;
    IDirect3DDevice7 *m_pRenderDevice;
    int m_iCurrentX;
    int m_iCurrentY;
    int m_iUploadWidth;
    int m_iUploadHeight;
    SSmallRectangle m_sRectangleList[96];
    POINTFLOAT m_sBlitPosition[96];
    int m_iShading[96];
    unsigned __int8 m_uShifting[96];
    int m_iNumberOfObjects;
    POINT m_sDestinationPoint;
    RECT m_sUploadRectangle;
    unsigned __int8 m_bSoureSurfaceIsLocked;
    unsigned __int8 m_bVideoSurfaceIsLocked;
    void *m_pRenderAdress;
    int m_iPitch;
};

#endif // CCACHEPAGEMANAGER_H
