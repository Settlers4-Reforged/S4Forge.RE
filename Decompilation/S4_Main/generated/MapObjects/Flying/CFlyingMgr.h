#ifndef CFLYINGMGR_H
#define CFLYINGMGR_H

#include "defines.h"

class CFlyingMgr {
public:
    // address=[0x1303860]
    int  GetNumberOfEntities(int a2, int a3);

    // address=[0x150ddc0]
    int  GetFirstEntityId(int a2, int a3);

    // address=[0x154f490]
     CFlyingMgr(void);

    // address=[0x154f4b0]
    bool  AddFlyingEntity(int a2, int a3, int a4, int a5, bool a5);

    // address=[0x154f5c0]
    void  DeleteFlyingEntity(int a2);

    // address=[0x154f6a0]
    class IFlyingEntity *  GetEntityPtr(int a2);

    // address=[0x154f6f0]
    class CManakopter *  GetManakopterPtr(int a2);

    // address=[0x154f740]
    void  AttachFlyingEntity(int a2, int a3, int a4);

    // address=[0x154f820]
    void  DetachFlyingEntity(int a2, int a3, int a4);

    // address=[0x154f960]
    void  CheckOutFlyingEntity(int a2);

    // address=[0x154f9d0]
    int  GetNearestEntity(int a2, int a3, int a4, int a5, int a6);

    // address=[0x154fb10]
    void  Store(class S4::CMapFile & a2);

    // address=[0x154fe90]
    void  Load(class S4::CMapFile & a2);

    // address=[0x1550170]
    void  Clear(void);

    // address=[0x15506f0]
    class IFlyingEntity &  operator[](int a1);

};


#endif // CFLYINGMGR_H
