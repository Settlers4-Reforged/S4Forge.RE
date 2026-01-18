#ifndef CSIMPLEBUILDINGROLE_H
#define CSIMPLEBUILDINGROLE_H

#include "defines.h"

class CSimpleBuildingRole : public IBuildingRole {
public:
    // address=[0x1401da0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14fcb10]
     CSimpleBuildingRole(void);

    // address=[0x14fcd20]
    virtual  ~CSimpleBuildingRole(void);

    // address=[0x14fd180]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14fd400]
    virtual int  GetBuildingNeed(int a2)const;

    // address=[0x14fd560]
    virtual int  GetBuildingRole(void);

    // address=[0x14fd6a0]
    virtual int  GetPileIdWithGood(int a2)const;

    // address=[0x14fd750]
    virtual void  GoodArrive(int a2);

    // address=[0x14fdbf0]
    static class CSimpleBuildingRole * __cdecl Load(std::istream & a1);

    // address=[0x151ab50]
    virtual void  LogicUpdate(class CBuilding * a2);

    // address=[0x151b270]
    virtual void  FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3);

    // address=[0x151b340]
    virtual void  Init(class CBuilding * a2);

    // address=[0x151b420]
    virtual void  PostLoadInit(class CBuilding * a2);

    // address=[0x151b4d0]
    virtual bool  SettlerEnter(class CBuilding * a2, int a3);

    // address=[0x151b740]
    virtual void  FillDialog(class CBuilding * a2, bool a3);

    // address=[0x151ba20]
     CSimpleBuildingRole(std::istream & a2);

    // address=[0x151bae0]
    virtual void  Store(std::ostream & a2);

    // address=[0x3d8b798]
    static unsigned long m_iClassID;

private:
    // address=[0x14fd250]
    virtual void  ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *);

    // address=[0x14fd2b0]
    virtual bool  CrushBuilding(void);

    // address=[0x14fde80]
    virtual bool  TryCrushBuilding(void);

};


#endif // CSIMPLEBUILDINGROLE_H
