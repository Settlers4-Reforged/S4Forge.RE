#ifndef CMILITARYBUILDINGROLE_H
#define CMILITARYBUILDINGROLE_H

#include "defines.h"

class CMilitaryBuildingRole : public IBuildingRole {
public:
    // address=[0x14013a0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14fca30]
     CMilitaryBuildingRole(void);

    // address=[0x14fcc70]
    virtual  ~CMilitaryBuildingRole(void);

    // address=[0x14fd120]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14fd3c0]
    virtual int  GetBuildingNeed(int a2)const;

    // address=[0x14fd500]
    virtual int  GetBuildingRole(void);

    // address=[0x14fd660]
    virtual int  GetPileIdWithGood(int a2)const;

    // address=[0x14fd730]
    virtual void  GoodArrive(int a2);

    // address=[0x14fdaf0]
    static class CMilitaryBuildingRole * __cdecl Load(std::istream & a1);

    // address=[0x150de70]
    virtual void  LogicUpdate(class CBuilding * a2);

    // address=[0x150df40]
    virtual void  Update(class CBuilding * a2);

    // address=[0x150dfa0]
    virtual void  FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3);

    // address=[0x150e500]
    virtual void  Init(class CBuilding * a2);

    // address=[0x150e760]
    virtual void  PostLoadInit(class CBuilding * a2);

    // address=[0x150e860]
    virtual void  FillDialog(class CBuilding * a2, bool a3);

    // address=[0x150ebe0]
    bool  IncWishAndOrder(int a2, bool a3);

    // address=[0x150ed30]
    int  GetWish(int a2);

    // address=[0x150ed70]
    virtual int  Decrease(int a2);

    // address=[0x150edf0]
    bool  HaveFreeSlots(int a2);

    // address=[0x150ef80]
    virtual void  RemoveInhabitant(class CBuilding * a2);

    // address=[0x150f070]
    virtual void  InhabitantFlee(int a2);

    // address=[0x150f2c0]
    void  SetDoorInvincible(int a2);

    // address=[0x150f340]
     CMilitaryBuildingRole(std::istream & a2);

    // address=[0x150f5c0]
    virtual void  Store(std::ostream & a2);

    // address=[0x15e2cd0]
    class std::vector<unsigned short,class std::allocator<unsigned short> > const &  Inhabitants(void)const;

    // address=[0x160da00]
    int  GetNumberOfInhabitants(void)const;

    // address=[0x3d8b140]
    static unsigned long m_iClassID;

protected:
    // address=[0x150f7b0]
    virtual bool  TryCrushBuilding(void);

    // address=[0x150f830]
    virtual bool  CrushBuilding(void);

    // address=[0x150f8d0]
    virtual bool  SettlerEnter(class CBuilding * a2, int a3);

    // address=[0x150fd20]
    bool  FirstSettlerEnter(class CBuilding * a2, int a3);

    // address=[0x1510190]
    void  TowerGuardEnter(bool a2);

    // address=[0x15102d0]
    virtual void  KillInhabitant(class CBuilding * a2);

    // address=[0x15103f0]
    bool  SearchAttacker(class CBuilding * a2);

    // address=[0x1510430]
    void  ThrowOut(class CBuilding *);

    // address=[0x1510510]
    void  ThrowOutId(class CBuilding * a2);

    // address=[0x1510780]
    void  ThrowOutSettler(class CBuilding * a2, int a3);

    // address=[0x1510a30]
    void  FillAllSlots(void);

    // address=[0x1510a70]
    void  OrderWarrior(class CBuilding * a2);

    // address=[0x1510f30]
    void  MoveAfterAboveDoor(void);

    // address=[0x1511130]
    void  MoveAfterWindow(void);

    // address=[0x15112c0]
    void  InsertDoor(class CBuilding * a2, bool a3);

    // address=[0x15114b0]
    void  RemoveDoorIfNecessary(class CBuilding * a2);

    // address=[0x1511550]
    void  MakeInvisibleDoorVisible(class CBuilding * a2);

    // address=[0x15115e0]
    void  OnDoorKilled(void);

    // address=[0x1511670]
    void  OnTowerGuardKilled(void);

    // address=[0x15116c0]
    void  InsertTowerGuard(void);

    // address=[0x1511c50]
    void  CancelAllOrders(class CBuilding * a2);

    // address=[0x1511ce0]
    int  GetFirstFreeSlot(bool a2);

    // address=[0x1511da0]
    int  GetLastUsedSlot(bool a2, bool a3);

    // address=[0x1511e80]
    int  GetSlot(int a2);

    // address=[0x1511f30]
    virtual void  ConvertEventIntoGoal(class CBuilding * a2, class CEntityEvent * a3);

    // address=[0x15120d0]
    void  SetSettlerTowerInfo(class CSettler & a2, int Slot, int a4, bool a5);

    // address=[0x1512380]
    void  SetEffectDisplay(int a2, int a3);

    // address=[0x1513a10]
    bool  IsTopPosition(int a2);

private:
    // address=[0x1512500]
    virtual void  NotifyDetach(class CBuilding * a2, int a3);

};


#endif // CMILITARYBUILDINGROLE_H
