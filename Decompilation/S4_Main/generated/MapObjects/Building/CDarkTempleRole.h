#ifndef CDARKTEMPLEROLE_H
#define CDARKTEMPLEROLE_H

#include "defines.h"

class CDarkTempleRole : public IBuildingRole {
public:
    // address=[0x14002c0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14fd970]
    static class CDarkTempleRole * __cdecl Load(std::istream & a1);

    // address=[0x1508260]
     CDarkTempleRole(void);

    // address=[0x1508360]
    virtual void  LogicUpdate(class CBuilding * a2);

    // address=[0x15084c0]
    virtual void  FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3);

    // address=[0x1508510]
    virtual void  Init(class CBuilding * a2);

    // address=[0x1508610]
    virtual void  PostLoadInit(class CBuilding * a2);

    // address=[0x1508690]
    virtual bool  SettlerEnter(class CBuilding * a2, int a3);

    // address=[0x1508820]
    void  TakeOrder(int a2, int a3);

    // address=[0x15089c0]
    int  ProduceMushroomFarmer(class CBuilding * a2);

    // address=[0x15089f0]
     CDarkTempleRole(std::istream & a2);

    // address=[0x1508bd0]
    virtual void  Store(std::ostream & a2);

    // address=[0x1509b60]
    virtual  ~CDarkTempleRole(void);

    // address=[0x1509ef0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x1509f50]
    virtual void  FillDialog(class CBuilding * a2, bool a3);

    // address=[0x1509f60]
    virtual int  GetBuildingNeed(int a2)const;

    // address=[0x1509f80]
    virtual int  GetBuildingRole(void);

    // address=[0x1509fa0]
    virtual int  GetPileIdWithGood(int a2)const;

    // address=[0x1509fc0]
    virtual void  GoodArrive(int a2);

    // address=[0x3d8b128]
    static unsigned long m_iClassID;

private:
    // address=[0x1508ce0]
    void  Produce(class CBuilding * a2);

    // address=[0x1508f70]
    void  AttackEnemies(class CBuilding * a2);

    // address=[0x1509350]
    void  ShowFireRing(int a2, int a3, int a4, int a5);

    // address=[0x1509450]
    void  ServantManagement(class CBuilding * a2);

    // address=[0x15094f0]
    int  AddSettlerToWorld(int a2, int a3, int a4);

    // address=[0x1509f10]
    virtual void  ConvertEventIntoGoal(class CBuilding * a2, class CEntityEvent * a3);

    // address=[0x1509f20]
    virtual bool  CrushBuilding(void);

    // address=[0x1509fd0]
    virtual bool  TryCrushBuilding(void);

};


#endif // CDARKTEMPLEROLE_H
