#ifndef CMANAKOPTERHALLROLE_H
#define CMANAKOPTERHALLROLE_H

#include "defines.h"

class CManakopterHallRole : public IBuildingRole {
public:
    // address=[0x14011c0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14fdab0]
    static class CManakopterHallRole * __cdecl Load(std::istream & a1);

    // address=[0x150c8f0]
     CManakopterHallRole(std::istream & a2);

    // address=[0x150ca90]
    virtual void  Store(std::ostream & a2);

    // address=[0x150cb90]
     CManakopterHallRole(void);

    // address=[0x150cc40]
    virtual  ~CManakopterHallRole(void);

    // address=[0x150cc60]
    virtual void  LogicUpdate(class CBuilding * a2);

    // address=[0x150d170]
    virtual void  FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3);

    // address=[0x150d2b0]
    virtual void  PostLoadInit(class CBuilding * a2);

    // address=[0x150d2e0]
    virtual void  Init(class CBuilding * a2);

    // address=[0x150d3b0]
    virtual bool  SettlerEnter(class CBuilding * a2, int a3);

    // address=[0x150d3f0]
    virtual void  GoodArrive(int a2);

    // address=[0x150d4c0]
    virtual void  FillDialog(class CBuilding *,bool);

    // address=[0x150d4d0]
    int  GetMostRequiredGood(void);

    // address=[0x150d570]
    void  TeleportGoods(int a2, int a3);

    // address=[0x150d640]
    bool  TryMakingManakopter(class CBuilding * a2);

    // address=[0x150d6f0]
    bool  CheatIfRequired(class CBuilding * a2);

    // address=[0x150dd40]
    virtual unsigned long  ClassID(void)const;

    // address=[0x150dd80]
    virtual int  GetBuildingNeed(int a2)const;

    // address=[0x150dda0]
    virtual int  GetBuildingRole(void);

    // address=[0x150de40]
    virtual int  GetPileIdWithGood(int a2)const;

    // address=[0x3d8b13c]
    static unsigned long m_iClassID;

private:
    // address=[0x150dd60]
    virtual void  ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *);

    // address=[0x150dd70]
    virtual bool  CrushBuilding(void);

    // address=[0x150de60]
    virtual bool  TryCrushBuilding(void);

    // address=[0x40f2290]
    static class CAIConfigInt s_iRequiredMana;

    // address=[0x40f229c]
    static class CAIConfigInt s_iRequiredBoard;

    // address=[0x40f22a8]
    static class CAIConfigInt s_iRequiredIron;

};


#endif // CMANAKOPTERHALLROLE_H
