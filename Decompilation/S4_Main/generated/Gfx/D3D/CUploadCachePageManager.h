#ifndef CUPLOADCACHEPAGEMANAGER_H
#define CUPLOADCACHEPAGEMANAGER_H

class CUploadCachePageManager {
public:
    // address=[0x2f69830]
     CUploadCachePageManager(struct IDirectDrawSurface7 *,struct IDirectDrawSurface7 *,struct IDirect3DDevice7 *);

    // address=[0x2f69860]
     ~CUploadCachePageManager(void);

    // address=[0x2f89550]
    int  IsAlreadyStored(int);

    // address=[0x2f99850]
    void  StoreGfxId(int,int);

};


#endif // CUPLOADCACHEPAGEMANAGER_H
