#ifndef CFERRYSHIP_H
#define CFERRYSHIP_H

#include "defines.h"

class CFerryShip : public CShip {
public:
    // address=[0x14009a0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x1596310]
    virtual void  Delete(void);

    // address=[0x1596500]
    virtual int const  GetMeetingPointXY(enum OBJ_TYPE a2, int a3);

    // address=[0x15965f0]
    enum TFerryRequestResult  CFerryShip::Request(int a2);

    // address=[0x15969f0]
    virtual void  FillDialog(bool a2);

    // address=[0x1596e10]
    virtual void  VehicleLogicUpdate(void);

    // address=[0x15971a0]
    virtual void  Unload(void);

    // address=[0x1597330]
    bool  EmergencyReload(int a2);

    // address=[0x1597530]
    virtual void  EntityOrderCanceled(int a2);

    // address=[0x1597760]
    virtual void  EntityEnter(int a2);

    // address=[0x1597840]
    bool  CanLoad(int a2, int a3);

    // address=[0x15978d0]
    bool  AddEntityToFerry(int a2);

    // address=[0x1597aa0]
    virtual void  CountCargo(class ICargoCounter & a2);

    // address=[0x1597b50]
    static void * __cdecl operator new(unsigned int a1);

    // address=[0x1597b70]
    static void __cdecl operator delete(void * a1);

    // address=[0x1597bb0]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x1597bf0]
     CFerryShip(std::istream & a2);

    // address=[0x1597e50]
    virtual void  Store(std::ostream & a2);

    // address=[0x159ba90]
    virtual unsigned long  ClassID(void)const;

    // address=[0x159bae0]
    static int __cdecl GetCargoSize(int a1, int a2);

    // address=[0x3d8bfb0]
    static unsigned long m_iClassID;

protected:
    // address=[0x1598010]
     CFerryShip(int a2, int a3, int a4, int a5, int a6, int a7, bool a8);

    // address=[0x15980c0]
    virtual  ~CFerryShip(void);

private:
    // address=[0x15980f0]
    bool  OnShipArrived(void);

    // address=[0x1598140]
    bool  OnLoad(void);

    // address=[0x1598330]
    int  CalcDistanceToLand(int & a2, int & a3);

    // address=[0x1598440]
    bool  FindLoadPosition(int a2, int & a3, int & a4);

    // address=[0x15986b0]
    bool  FindUnLoadPosition(int a2, int & a3, int & a4);

    // address=[0x15988e0]
    bool  UnloadAt(int a2, int a3, int a4);

    // address=[0x1598a10]
    void  ClearCargo(void);

    // address=[0x1598b80]
    void  DeleteCargo(class CFerryShip::CCargo & a2);

    // address=[0x1598cf0]
    bool  HasRegisterdCargo(int a2);

    // address=[0x1598d50]
    virtual void  NotifyDetach(int a2);

    // address=[0x159bb10]
    enum TFerryJob  CFerryShip::GetFerryJob(void);

    // address=[0x159bb70]
    void  SetFerryJob(enum CFerryShip::TFerryJob a2);

};


#endif // CFERRYSHIP_H
