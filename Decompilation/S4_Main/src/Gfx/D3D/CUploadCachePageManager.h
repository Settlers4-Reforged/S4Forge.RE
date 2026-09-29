#ifndef CUPLOADCACHEPAGEMANAGER_H
#define CUPLOADCACHEPAGEMANAGER_H

#include "CCachePageManager.h"
#include "defines.h"

class CUploadCachePageManager : CCachePageManager {
  public:
    // address=[0x2f69830]
    CUploadCachePageManager(struct IDirectDrawSurface7 *a2, struct IDirectDrawSurface7 *a3, struct IDirect3DDevice7 *a4);

    // address=[0x2f69860]
    ~CUploadCachePageManager(void);

    // address=[0x2f89550]
    int IsAlreadyStored(int _iGfxId);

    // address=[0x2f99850]
    void StoreGfxId(int _iPage, int _iGfxId);

    // Type information members
  public:
    int m_iGfxIds[96]; // TODO: check if 96 is actual value!
};

#endif // CUPLOADCACHEPAGEMANAGER_H
