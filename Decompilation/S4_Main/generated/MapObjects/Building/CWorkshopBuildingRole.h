#ifndef CWORKSHOPBUILDINGROLE_H
#define CWORKSHOPBUILDINGROLE_H

#include "defines.h"

class CWorkshopBuildingRole : public IBuildingRole {
public:
    // address=[0x1402a20]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14fdd30]
    static class CWorkshopBuildingRole * __cdecl Load(std::istream & a1);

    // address=[0x152cc10]
     CWorkshopBuildingRole(void);

    // address=[0x152cc90]
    virtual void  LogicUpdate(class CBuilding * a2);

    // address=[0x152cff0]
    virtual void  FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3);

    // address=[0x152d260]
    virtual void  Init(class CBuilding * a2);

    // address=[0x152d540]
    virtual void  PostLoadInit(class CBuilding * a2);

    // address=[0x152d610]
    virtual bool  SettlerEnter(class CBuilding * a2, int a3);

    // address=[0x152d940]
    virtual int  GetBuildingNeed(int a2)const;

    // address=[0x152d9e0]
    virtual int  GetPileIdWithGood(int a2)const;

    // address=[0x152da90]
    virtual bool  HasShipAmmo(int a2)const;

    // address=[0x152db10]
    virtual int  GetPileIdWithNeedForGood(int a2)const;

    // address=[0x152dbd0]
    virtual void  GoodArrive(int a2);

    // address=[0x152dbe0]
    bool  HaveStillOrders(void)const;

    // address=[0x152dc20]
    bool  HaveSpecialOrder(int a2)const;

    // address=[0x152dc70]
    virtual void  LockPiles(class CBuilding * a2, bool a3);

    // address=[0x152dd10]
    void  TakeOrder(int a2, int a3);

    // address=[0x152dde0]
    void  FillAddVehicleSideBar(class CAddVehicleBarInfo * a2, bool a3);

    // address=[0x152dfd0]
    bool  CancelCurrentProduction(void);

    // address=[0x152e100]
     CWorkshopBuildingRole(std::istream & a2);

    // address=[0x152e2b0]
    virtual void  Store(std::ostream & a2);

    // address=[0x152f150]
    virtual  ~CWorkshopBuildingRole(void);

    // address=[0x152f1c0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x152f1f0]
    virtual int  GetBuildingRole(void);

    // address=[0x3d8b814]
    static unsigned long m_iClassID;

private:
    // address=[0x152e3f0]
    virtual bool  CrushBuilding(void);

    // address=[0x152e4a0]
    bool  HaveMaterial(class CBuilding * a2);

    // address=[0x152e510]
    bool  HaveProductionOrder(void);

    // address=[0x152e5c0]
    void  GetPositionForNewVehicle(class CBuilding * a2, int & a3, int & a4);

    // address=[0x152e610]
    int  GetDirectionForNewVehicle(class CBuilding * a2);

    // address=[0x152e6c0]
    bool  IsSpaceForVehicleAvailable(class CBuilding * a2, int a3);

    // address=[0x152e710]
    virtual void  FillDialog(class CBuilding * a2, bool a3);

    // address=[0x152e980]
    void  Clear(void);

    // address=[0x152f1e0]
    virtual void  ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *);

    // address=[0x152f260]
    virtual bool  TryCrushBuilding(void);

};


#endif // CWORKSHOPBUILDINGROLE_H
