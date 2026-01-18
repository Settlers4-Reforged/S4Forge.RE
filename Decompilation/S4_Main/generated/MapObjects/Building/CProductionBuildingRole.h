#ifndef CPRODUCTIONBUILDINGROLE_H
#define CPRODUCTIONBUILDINGROLE_H

#include "defines.h"

class CProductionBuildingRole : public IBuildingRole {
public:
    // address=[0x1401800]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14fca80]
     CProductionBuildingRole(void);

    // address=[0x14fccb0]
    virtual  ~CProductionBuildingRole(void);

    // address=[0x14fd140]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14fd520]
    virtual int  GetBuildingRole(void);

    // address=[0x14fdb70]
    static class CProductionBuildingRole * __cdecl Load(std::istream & a1);

    // address=[0x1516150]
    virtual void  LogicUpdate(class CBuilding * a2);

    // address=[0x1516390]
    virtual void  FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3);

    // address=[0x15166b0]
    virtual void  Init(class CBuilding * a2);

    // address=[0x15169a0]
    virtual void  PostLoadInit(class CBuilding * a2);

    // address=[0x15169d0]
    virtual void  LockPiles(class CBuilding * a2, bool a3);

    // address=[0x1516af0]
    virtual bool  SettlerEnter(class CBuilding * a2, int a3);

    // address=[0x1516de0]
    virtual int  GetBuildingNeed(int a2)const;

    // address=[0x1516e80]
    virtual int  GetPileIdWithGood(int a2)const;

    // address=[0x1516fc0]
    virtual void  GoodArrive(int a2);

    // address=[0x1516fd0]
    void  FillToolSideBar(class CAddToolSideBarInfo * a2, bool a3);

    // address=[0x1517210]
    void  FillWeaponSideBar(class CWeaponSideBarInfo * a2, bool a3);

    // address=[0x15173c0]
     CProductionBuildingRole(std::istream & a2);

    // address=[0x15175c0]
    virtual void  Store(std::ostream & a2);

    // address=[0x3d8b588]
    static unsigned long m_iClassID;

private:
    // address=[0x14fd230]
    virtual void  ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *);

    // address=[0x14fd2a0]
    virtual bool  CrushBuilding(void);

    // address=[0x14fde60]
    virtual bool  TryCrushBuilding(void);

    // address=[0x1517740]
    bool  HaveMaterial(class CBuilding * a2);

    // address=[0x15177c0]
    bool  HaveFreeSlotForProduct(class CBuilding *);

    // address=[0x1517840]
    bool  HaveProductionOrder(void);

    // address=[0x1517bb0]
    virtual void  FillDialog(class CBuilding * a2, bool a3);

    // address=[0x1577240]
    int  GetProductType(void)const;

};


#endif // CPRODUCTIONBUILDINGROLE_H
