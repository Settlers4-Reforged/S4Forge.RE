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
    bool  GetPictureArea(float a2, float a3, int a4, int a5, int a6, int a7, int & a8, int & a9);

    // address=[0x2f87b30]
    long  EraseExtensionAreas(int a2, int a3, int a4, int a5, int a6, bool a7);

    // address=[0x2f87db0]
    bool  UploadData(long & a2);

    // address=[0x2f87ea0]
    bool  UploadDataAndRender(long & a2);

    // address=[0x2f88440]
    bool  ShowPageContent(long & a2);

    // address=[0x2f888b0]
    void  ReleaseData(void);

    // address=[0x2f888f0]
    long  RenderCacheObject(int a2, float a3, float a4, int a5, int a6, int a7, bool a8);

    // address=[0x2f89350]
    long  LockSourceSurface(int & a2, unsigned short * & a3);

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
    struct IDirectDrawSurface7 * m_pSurfaceB;
    struct IDirectDrawSurface7 * m_pSurfaceA;
    struct IDirect3DDevice7 * m_pDevice;
    _DWORD dwordC;
    _DWORD dword10;
    _DWORD dword14;
    _DWORD dword18;
    _BYTE[2016] gap1C;
    _DWORD dword7FC;
    _DWORD dword800;
    _DWORD dword804;
    _DWORD dword808;
    _DWORD dword80C;
    _DWORD dword810;
    _DWORD dword814;
    _BYTE byte818;
    _BYTE byte819;
    _DWORD dword81C;
    _DWORD dword820;

};


#endif // CCACHEPAGEMANAGER_H
