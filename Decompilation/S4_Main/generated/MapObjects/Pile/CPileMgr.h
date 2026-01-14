#ifndef CPILEMGR_H
#define CPILEMGR_H

class CPileMgr {
public:
    // address=[0x12fd1f0]
    static class CPile * __cdecl GetPilePtr(int);

    // address=[0x1438a40]
    class CPile &  operator[](int);

    // address=[0x155e900]
     CPileMgr(void);

    // address=[0x155e930]
     ~CPileMgr(void);

    // address=[0x155e950]
    void  Clear(void);

    // address=[0x155e970]
    void  LoadPileData(class S4::CMapFile &,int);

    // address=[0x155ea20]
    int  AddPile(int,int,int,int,int,int,int,int,int);

    // address=[0x155ec40]
    void  DeletePile(int);

    // address=[0x155ed50]
    void  DeletePileUnforeseen(int);

    // address=[0x155ede0]
    int  GetNearestPile(int,int,int);

    // address=[0x155eef0]
    void  SearchSpaceForGoods(int,int,int,int);

    // address=[0x155f280]
    void  Store(class S4::CMapFile &);

    // address=[0x155f4c0]
    void  Load(class S4::CMapFile &);

    // address=[0x155f670]
    int  DbgCheckPiles(int);

    // address=[0x155f760]
    int  ConvertGoodType(int,int);

    // address=[0x155f820]
    static class IPileRole * __cdecl CreatePileRole(int);

private:
    // address=[0x155e750]
    void *  Alloc(unsigned int);

    // address=[0x155e7b0]
    void  Dealloc(void *);

    // address=[0x155fa90]
    void  TracePile(int);

    // address=[0x155fb30]
    static class IPileRole * __cdecl LoadPileRole(std::istream &,int);

    // address=[0x155fc30]
    void  CheckOutPile(int);

};


#endif // CPILEMGR_H
