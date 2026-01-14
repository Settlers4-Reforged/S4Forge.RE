#ifndef CFLYINGMGR_H
#define CFLYINGMGR_H

class CFlyingMgr {
public:
    // address=[0x1303860]
    int  GetNumberOfEntities(int,int);

    // address=[0x150ddc0]
    int  GetFirstEntityId(int,int);

    // address=[0x154f490]
     CFlyingMgr(void);

    // address=[0x154f4b0]
    bool  AddFlyingEntity(int,int,int,int,bool);

    // address=[0x154f5c0]
    void  DeleteFlyingEntity(int);

    // address=[0x154f6a0]
    class IFlyingEntity *  GetEntityPtr(int);

    // address=[0x154f6f0]
    class CManakopter *  GetManakopterPtr(int);

    // address=[0x154f740]
    void  AttachFlyingEntity(int,int,int);

    // address=[0x154f820]
    void  DetachFlyingEntity(int,int,int);

    // address=[0x154f960]
    void  CheckOutFlyingEntity(int);

    // address=[0x154f9d0]
    int  GetNearestEntity(int,int,int,int,int);

    // address=[0x154fb10]
    void  Store(class S4::CMapFile &);

    // address=[0x154fe90]
    void  Load(class S4::CMapFile &);

    // address=[0x1550170]
    void  Clear(void);

    // address=[0x15506f0]
    class IFlyingEntity &  operator[](int);

};


#endif // CFLYINGMGR_H
