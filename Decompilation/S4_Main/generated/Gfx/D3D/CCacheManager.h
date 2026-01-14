#ifndef CCACHEMANAGER_H
#define CCACHEMANAGER_H

class CCacheManager {
public:
    // address=[0x2f895b0]
     CCacheManager(void);

    // address=[0x2f895d0]
    void  Reset(void);

    // address=[0x2f89600]
    void  SetCacheInfos(int,int,int);

    // address=[0x2f99740]
    int  GetEntryIdx(int);

    // address=[0x2f99790]
    int  GetSurfaceIdx(int);

    // address=[0x2f997c0]
    int  GetUsedCacheTextures(void);

    // address=[0x2f997e0]
    bool  IsGfxCached(int);

    // address=[0x2f99830]
    void  SetUsedCacheTextures(int);

};


#endif // CCACHEMANAGER_H
