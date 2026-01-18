#ifndef CMAPGENERATORHOST_H
#define CMAPGENERATORHOST_H

#include "defines.h"

class CMapGeneratorHost : public IMapGeneratorHost {
public:
    // address=[0x1498520]
    virtual void  Init(int a2);

    // address=[0x1498680]
    virtual void  UpdateGroundInformation(void);

    // address=[0x1498720]
    virtual bool  SetObject(int a2, int a3, int a4);

    // address=[0x1498b10]
    virtual void  SetPlayerStartPosition(int a2, int a3, int a4);

    // address=[0x1498b50]
     CMapGeneratorHost(struct SRandomMapParams const &);

    // address=[0x1498c30]
    virtual  ~CMapGeneratorHost(void);

    // address=[0x1498c80]
    void  CleanUp(void);

    // address=[0x1498d20]
    void  ClearRandomMapInfo(void);

    // address=[0x1498d70]
    void  UploadChunks(class S4::CMapFile & a2);

    // address=[0x1498e00]
    void  RefreshShading(int a2);

    // address=[0x14991b0]
    virtual struct SEditorElementMap *  GetEditorLayer(void);

    // address=[0x14991d0]
    virtual struct T_GFX_MAP_ELEMENT *  GetGfxLayer(void);

    // address=[0x14991f0]
    virtual int __stdcall GetInterfaceVersion(void);

    // address=[0x1499200]
    virtual int  GetMapWidthHeight(void);

    // address=[0x1499220]
    virtual bool  IsEditorHost(void);

    // address=[0x149a7a0]
    struct SRandomMapInfo const *  GetRandomMapInfo(void)const;

};


#endif // CMAPGENERATORHOST_H
