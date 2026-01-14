#ifndef CCACHEPAGEMANAGER_H
#define CCACHEPAGEMANAGER_H

class CCachePageManager {
public:
    // address=[0x2f5f420]
    void  SetCurrentZoomFactor(float);

    // address=[0x2f69960]
    bool  IsSourceSurfaceLocked(void);

    // address=[0x2f69980]
    bool  IsVideoSurfaceLocked(void);

    // address=[0x2f87760]
     CCachePageManager(struct IDirectDrawSurface7 *,struct IDirectDrawSurface7 *,struct IDirect3DDevice7 *);

    // address=[0x2f878f0]
     ~CCachePageManager(void);

    // address=[0x2f87940]
    bool  GetPictureArea(float,float,int,int,int,int,int &,int &);

    // address=[0x2f87b30]
    long  EraseExtensionAreas(int,int,int,int,int,bool);

    // address=[0x2f87db0]
    bool  UploadData(long &);

    // address=[0x2f87ea0]
    bool  UploadDataAndRender(long &);

    // address=[0x2f88440]
    bool  ShowPageContent(long &);

    // address=[0x2f888b0]
    void  ReleaseData(void);

    // address=[0x2f888f0]
    long  RenderCacheObject(int,float,float,int,int,int,bool);

    // address=[0x2f89350]
    long  LockSourceSurface(int &,unsigned short * &);

    // address=[0x2f89400]
    long  LockVideoSurface(int &,unsigned short * &);

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

};


#endif // CCACHEPAGEMANAGER_H
