#ifndef CRANDOMMAPS_H
#define CRANDOMMAPS_H

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
    virtual void  InitRandomMap(struct SRandomMapParams &);

    // address=[0x1499500]
    virtual bool  GenerateRandomMap(void);

    // address=[0x1499540]
    virtual bool  GetParamsFromMapKey(struct SRandomMapParams *,std::wstring const &);

    // address=[0x1499570]
    virtual bool  GetParamsFromMapKey(struct SRandomMapParams *,wchar_t const *);

    // address=[0x1499640]
    virtual void  GetMapKeyFromParams(struct SRandomMapParams *,std::wstring &);

    // address=[0x14996d0]
    virtual void  GetMapKeyFromParams(struct SRandomMapParams *,wchar_t *);

    // address=[0x1499710]
    virtual bool  IsRandomMapFileName(wchar_t const *,std::wstring *);

    // address=[0x1499870]
    virtual bool  IsRandomMapFileName(std::wstring const &,std::wstring *);

    // address=[0x14998c0]
    virtual void  GenerateRandomMapFileName(std::wstring &,wchar_t const *);

    // address=[0x14999b0]
    virtual void  GenerateRandomMapFileName(std::wstring &,std::wstring const &);

    // address=[0x1499a50]
    virtual void  GenerateRandomMapFileName(std::wstring &,struct SRandomMapParams const &);

    // address=[0x1499b10]
    virtual void  AdjustRandomMapFileName(std::wstring &);

    // address=[0x1499d90]
    virtual unsigned short const *  GetPreviewData(void);

    // address=[0x1499dc0]
    virtual struct SRandomMapInfo const *  GetRandomMapInfo(void);

};


#endif // CRANDOMMAPS_H
