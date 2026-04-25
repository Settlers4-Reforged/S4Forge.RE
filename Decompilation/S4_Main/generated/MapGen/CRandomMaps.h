#ifndef CRANDOMMAPS_H
#define CRANDOMMAPS_H

#include "defines.h"

class CRandomMaps : public IRandomMaps {
public:
    // address=[0x1499230]
     CRandomMaps(void);

    // address=[0x1499280]
    virtual  ~CRandomMaps(void);

    // address=[0x14992d0]
    virtual void  CleanUp(void);

    // address=[0x14993a0]
    virtual class S4::CMapFile *  GetRandomMapFile(void);

    // address=[0x14993c0]
    virtual void  InitRandomMap(struct SRandomMapParams & a2);

    // address=[0x1499500]
    virtual bool  GenerateRandomMap(void);

    // address=[0x1499540]
    virtual bool  GetParamsFromMapKey(struct SRandomMapParams * a2, std::wstring const & a3);

    // address=[0x1499570]
    virtual bool  GetParamsFromMapKey(struct SRandomMapParams * a1, wchar_t const * Source);

    // address=[0x1499640]
    virtual void  GetMapKeyFromParams(struct SRandomMapParams * a2, std::wstring & a3);

    // address=[0x14996d0]
    virtual void  GetMapKeyFromParams(struct SRandomMapParams * a2, wchar_t * a3);

    // address=[0x1499710]
    virtual bool  IsRandomMapFileName(wchar_t const * String, std::wstring * a2);

    // address=[0x1499870]
    virtual bool  IsRandomMapFileName(std::wstring const & a2, std::wstring * a3);

    // address=[0x14998c0]
    virtual void  GenerateRandomMapFileName(std::wstring & a1, wchar_t const * String);

    // address=[0x14999b0]
    virtual void  GenerateRandomMapFileName(std::wstring & a1, std::wstring const & a2);

    // address=[0x1499a50]
    virtual void  GenerateRandomMapFileName(std::wstring & a2, struct SRandomMapParams const & a3);

    // address=[0x1499b10]
    virtual void  AdjustRandomMapFileName(std::wstring & a2);

    // address=[0x1499d90]
    virtual unsigned short const *  GetPreviewData(void);

    // address=[0x1499dc0]
    virtual struct SRandomMapInfo const *  GetRandomMapInfo(void);

};


#endif // CRANDOMMAPS_H
