#ifndef CCACHEMANAGER_H
#define CCACHEMANAGER_H

#include "defines.h"

class CCacheManager {
public:
    // address=[0x2f895b0]
     CCacheManager(void);

    // address=[0x2f895d0]
    void  Reset(void);

    // address=[0x2f89600]
    void  SetCacheInfos(int a2, int a3, int a4);

    // address=[0x2f99740]
    int  GetEntryIdx(int a2);

    // address=[0x2f99790]
    int  GetSurfaceIdx(int a2);

    // address=[0x2f997c0]
    int  GetUsedCacheTextures(void);

    // address=[0x2f997e0]
    bool  IsGfxCached(int a2);

    // address=[0x2f99830]
    void  SetUsedCacheTextures(int a2);

};


#endif // CCACHEMANAGER_H
