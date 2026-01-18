#ifndef CEYECATCHERROLE_H
#define CEYECATCHERROLE_H

#include "defines.h"

class CEyeCatcherRole : public IBuildingRole {
public:
    // address=[0x1400860]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14fc970]
     CEyeCatcherRole(void);

    // address=[0x14fcbf0]
    virtual  ~CEyeCatcherRole(void);

    // address=[0x14fd0a0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14fd340]
    virtual int  GetBuildingNeed(int a2)const;

    // address=[0x14fd480]
    virtual int  GetBuildingRole(void);

    // address=[0x14fd5e0]
    virtual int  GetPileIdWithGood(int a2)const;

    // address=[0x14fd6f0]
    virtual void  GoodArrive(int a2);

    // address=[0x14fd9b0]
    static class CEyeCatcherRole * __cdecl Load(std::istream & a1);

    // address=[0x150a110]
    virtual void  LogicUpdate(class CBuilding * a2);

    // address=[0x150a120]
    virtual void  FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3);

    // address=[0x150a240]
    virtual void  Init(class CBuilding * a2);

    // address=[0x150a280]
    virtual void  PostLoadInit(class CBuilding * a2);

    // address=[0x150a2b0]
    virtual void  FillDialog(class CBuilding * a2, bool a3);

    // address=[0x150a400]
     CEyeCatcherRole(std::istream & a2);

    // address=[0x150a4b0]
    virtual void  Store(std::ostream & a2);

    // address=[0x3d8b12c]
    static unsigned long m_iClassID;

private:
    // address=[0x14fd1f0]
    virtual void  ConvertEventIntoGoal(class CBuilding * a2, class CEntityEvent * a3);

    // address=[0x14fd270]
    virtual bool  CrushBuilding(void);

    // address=[0x14fde20]
    virtual bool  TryCrushBuilding(void);

};


#endif // CEYECATCHERROLE_H
