#ifndef CCACHEPAGEMANAGER_H
#define CCACHEPAGEMANAGER_H

#include "defines.h"

class CCachePageManager {
public:
    // address=[0x2f5f420]
    void  SetCurrentZoomFactor(float a2);

    // address=[0x2f69960]
    bool  IsSourceSurfaceLocked(void);

    // address=[0x2f69980]
    bool  IsVideoSurfaceLocked(void);

    // address=[0x2f87760]
     CCachePageManager(struct IDirectDrawSurface7 * a2, struct IDirectDrawSurface7 * a3, struct IDirect3DDevice7 * a4);

    // address=[0x2f878f0]
     ~CCachePageManager(void);

    // address=[0x2f87940]
    bool  GetPictureArea(float iBlitX, float iBlitY, int iWidth, int iHeight, int iShading, int iShifting, int & iPosX, int & iPosY);

    // address=[0x2f87b30]
    long  EraseExtensionAreas(int _iIndex, int a3, int a4, int a5, int a6, bool a7);

    // address=[0x2f87db0]
    bool  UploadData(long & hResult);

    // address=[0x2f87ea0]
    bool  UploadDataAndRender(long & a2);

    // address=[0x2f88440]
    bool  ShowPageContent(long & a2);

    // address=[0x2f888b0]
    void  ReleaseData(void);

    // address=[0x2f888f0]
    long  RenderCacheObject(int _iIndex, float _fX, float _fY, int _iShading, int _iFlags, int _iShift, bool a8);

    // address=[0x2f89350]
    long  LockSourceSurface(int & _rPitch, unsigned short * & _rRender);

    // address=[0x2f89400]
    long  LockVideoSurface(int & a2, unsigned short * & a3);

    // address=[0x2f894b0]
    long  UnlockSourceSurface(void);

    // address=[0x2f89500]
    long  UnlockVideoSurface(void);

    // address=[0x2f8a420]
    bool  IsData(void);

    // address=[0x2f99770]
    int  GetLastCacheObjectNr(void);

protected:
    // address=[0x46c1698]
    static float sm_fZoomFactor;

    // address=[0x46c16a0]
    static float * sm_fTextureCoordTable;

    // Type information members
public:
    IDirectDrawSurface7 * m_pSystemTexture;
    IDirectDrawSurface7 * m_pVideoTexture;
    IDirect3DDevice7 * m_pRenderDevice;
    int m_iCurrentX;
    int m_iCurrentY;
    int m_iUploadWidth;
    int m_iUploadHeight;
    SSmallRectangle[96] m_sRectangleList;
    tagPOINT[96] m_sBlitPosition;
    int[96] m_iShading;
    unsigned __int8[96] m_uShifting;
    int m_iNumberOfObjects;
    tagPOINT m_sDestinationPoint;
    tagRECT m_sUploadRectangle;
    unsigned __int8 m_bSoureSurfaceIsLocked;
    unsigned __int8 m_bVideoSurfaceIsLocked;
    void * m_pRenderAdress;
    int m_iPitch;

};


#endif // CCACHEPAGEMANAGER_H
