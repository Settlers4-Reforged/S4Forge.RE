#ifndef CPILEMGR_H
#define CPILEMGR_H

#include "defines.h"

class CPileMgr {
public:
    // address=[0x12fd1f0]
    static class CPile * __cdecl GetPilePtr(int a1);

    // address=[0x1438a40]
    class CPile &  operator[](int a1);

    // address=[0x155e900]
     CPileMgr(void);

    // address=[0x155e930]
     ~CPileMgr(void);

    // address=[0x155e950]
    void  Clear(void);

    // address=[0x155e970]
    void  LoadPileData(class S4::CMapFile & a2, int a3);

    // address=[0x155ea20]
    int  AddPile(int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10);

    // address=[0x155ec40]
    void  DeletePile(int a2);

    // address=[0x155ed50]
    void  DeletePileUnforeseen(int a2);

    // address=[0x155ede0]
    int  GetNearestPile(int a2, int a3, int a4);

    // address=[0x155eef0]
    void  SearchSpaceForGoods(int a2, int a3, int a4, int a5);

    // address=[0x155f280]
    void  Store(class S4::CMapFile & a2);

    // address=[0x155f4c0]
    void  Load(class S4::CMapFile & a2);

    // address=[0x155f670]
    int  DbgCheckPiles(int a2);

    // address=[0x155f760]
    int  ConvertGoodType(int a2, int a3);

    // address=[0x155f820]
    static class IPileRole * __cdecl CreatePileRole(int a1);

private:
    // address=[0x155e750]
    void *  Alloc(unsigned int a2);

    // address=[0x155e7b0]
    void  Dealloc(void * a2);

    // address=[0x155fa90]
    void  TracePile(int a2);

    // address=[0x155fb30]
    static class IPileRole * __cdecl LoadPileRole(std::istream & a1, int a2);

    // address=[0x155fc30]
    void  CheckOutPile(int a2);

};


#endif // CPILEMGR_H
