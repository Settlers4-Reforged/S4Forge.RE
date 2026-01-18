#ifndef CDARKMUSHROOMFARMROLE_H
#define CDARKMUSHROOMFARMROLE_H

#include "defines.h"

class CDarkMushroomFarmRole : public IBuildingRole {
public:
    // address=[0x1400220]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x141da00]
    int  NumberOfAssociatedServants(void)const;

    // address=[0x14fc940]
     CDarkMushroomFarmRole(void);

    // address=[0x14fcbd0]
    virtual  ~CDarkMushroomFarmRole(void);

    // address=[0x14fd080]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14fd320]
    virtual int  GetBuildingNeed(int a2)const;

    // address=[0x14fd460]
    virtual int  GetBuildingRole(void);

    // address=[0x14fd5c0]
    virtual int  GetPileIdWithGood(int a2)const;

    // address=[0x14fd6e0]
    virtual void  GoodArrive(int a2);

    // address=[0x14fd930]
    static class CDarkMushroomFarmRole * __cdecl Load(std::istream & a1);

    // address=[0x1506a60]
    virtual void  LogicUpdate(class CBuilding * a2);

    // address=[0x1506f00]
    virtual void  FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3);

    // address=[0x1506fe0]
    virtual void  Init(class CBuilding * a2);

    // address=[0x15070d0]
    virtual void  PostLoadInit(class CBuilding * a2);

    // address=[0x1507130]
    virtual bool  SettlerEnter(class CBuilding * a2, int a3);

    // address=[0x1507180]
    virtual void  FillDialog(class CBuilding * a2, bool a3);

    // address=[0x1507190]
    bool  HarvestMushroom(class CBuilding * a2);

    // address=[0x15073a0]
    bool  PlantMushroom(class CBuilding * a2);

    // address=[0x1507740]
    void  AttachServant(class CBuilding * a2, int a3);

    // address=[0x15077c0]
    void  DetachServant(class CBuilding * a2, int a3);

    // address=[0x1507870]
    void  TellServantsToWork(class CBuilding * a2);

    // address=[0x1507a20]
     CDarkMushroomFarmRole(std::istream & a2);

    // address=[0x1507b70]
    virtual void  Store(std::ostream & a2);

    // address=[0x158e490]
    struct CBuildingInfoMgr::SBuildingInfos const *  GetBuildingInfo(void);

    // address=[0x3d8b124]
    static unsigned long m_iClassID;

protected:
    // address=[0x1507930]
    bool  IsDoorNeighborAndEnsignPosGreen(class CBuilding * a2);

private:
    // address=[0x14fd1e0]
    virtual void  ConvertEventIntoGoal(class CBuilding * a2, class CEntityEvent * a3);

    // address=[0x14fde10]
    virtual bool  TryCrushBuilding(void);

    // address=[0x1507c40]
    virtual bool  CrushBuilding(void);

};


#endif // CDARKMUSHROOMFARMROLE_H
