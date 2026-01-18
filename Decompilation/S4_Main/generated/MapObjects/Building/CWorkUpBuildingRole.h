#ifndef CWORKUPBUILDINGROLE_H
#define CWORKUPBUILDINGROLE_H

#include "defines.h"

class CWorkUpBuildingRole : public IBuildingRole {
public:
    // address=[0x1402980]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14e66b0]
    virtual  ~CWorkUpBuildingRole(void);

    // address=[0x14fcb70]
     CWorkUpBuildingRole(void);

    // address=[0x14fd1c0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14fd5a0]
    virtual int  GetBuildingRole(void);

    // address=[0x14fdcf0]
    static class CWorkUpBuildingRole * __cdecl Load(std::istream & a1);

    // address=[0x152f370]
    virtual void  LogicUpdate(class CBuilding * a2);

    // address=[0x152f610]
    virtual void  FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3);

    // address=[0x152f8e0]
    virtual void  Init(class CBuilding * a2);

    // address=[0x152fb80]
    virtual void  PostLoadInit(class CBuilding * a2);

    // address=[0x152fbe0]
    virtual bool  SettlerEnter(class CBuilding * a2, int a3);

    // address=[0x152feb0]
    virtual int  GetBuildingNeed(int a2)const;

    // address=[0x152ff50]
    virtual int  GetPileIdWithGood(int a2)const;

    // address=[0x1530070]
    virtual void  GoodArrive(int a2);

    // address=[0x1530080]
    virtual void  LockPiles(class CBuilding * a2, bool a3);

    // address=[0x1530120]
     CWorkUpBuildingRole(std::istream & a2);

    // address=[0x15302d0]
    virtual void  Store(std::ostream & a2);

    // address=[0x3d8b830]
    static unsigned long m_iClassID;

protected:
    // address=[0x14e67a0]
    virtual void  ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *);

    // address=[0x14e68f0]
    virtual bool  TryCrushBuilding(void);

    // address=[0x1530390]
    virtual bool  CrushBuilding(void);

    // address=[0x15303a0]
    bool  HaveMaterial(class CBuilding * a2);

    // address=[0x1530410]
    virtual void  FillDialog(class CBuilding * a2, bool a3);

};


#endif // CWORKUPBUILDINGROLE_H
