#ifndef CSHIP_H
#define CSHIP_H

#include "defines.h"

class CShip : public CVehicle {
public:
    // address=[0x159d4e0]
    virtual void  VehicleLogicUpdate(void);

    // address=[0x159d5c0]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x159d7c0]
    static int __cdecl FindBoardingLocation(class std::vector<unsigned short,class std::allocator<unsigned short> > const & a1, int a2, struct SBoardingInfo & a3);

    // address=[0x159d950]
    static int __cdecl FindBoardingLocation(int a1, int a2, struct SBoardingInfo & a3);

    // address=[0x159e8f0]
    virtual void  FillDialog(bool a2);

    // address=[0x159e940]
    virtual void  Unload(void);

protected:
    // address=[0x159dbb0]
     CShip(int a2, int a3, int a4, int a5, int a6, int a7, bool a8);

    // address=[0x159dc80]
    virtual  ~CShip(void);

    // address=[0x159dca0]
     CShip(std::istream & a2);

    // address=[0x159dd60]
    virtual void  Store(std::ostream & a2);

    // address=[0x159ddb0]
    virtual void  TakeJob(void);

    // address=[0x159df50]
    virtual void  WalkDir(int a2);

    // address=[0x159e070]
    virtual void  PlaceVehicle(int a2);

    // address=[0x159e150]
    virtual void  RemoveVehicle(int a2);

    // address=[0x159e260]
    int  RepairBuildingInRange(void);

    // address=[0x159e340]
    void  RepairAt(int a2);

    // address=[0x159e3e0]
    int  GetHealthDisplayID(void);

    // address=[0x37bd380]
    static int const SHIPYARD_SCAN_RANGE;

    // address=[0x37bd384]
    static int const FULL_UPDATE_DELAY;

};


#endif // CSHIP_H
