#ifndef CGATHERBUILDINGROLE_H
#define CGATHERBUILDINGROLE_H

#include "defines.h"

class CGatherBuildingRole : public IBuildingRole {
public:
    // address=[0x1400c20]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14fc9d0]
     CGatherBuildingRole(void);

    // address=[0x14fcc30]
    virtual  ~CGatherBuildingRole(void);

    // address=[0x14fd0e0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14fd380]
    virtual int  GetBuildingNeed(int a2)const;

    // address=[0x14fd4c0]
    virtual int  GetBuildingRole(void);

    // address=[0x14fd620]
    virtual int  GetPileIdWithGood(int a2)const;

    // address=[0x14fd710]
    virtual void  GoodArrive(int a2);

    // address=[0x14fda30]
    static class CGatherBuildingRole * __cdecl Load(std::istream & a1);

    // address=[0x150b5b0]
    virtual void  LogicUpdate(class CBuilding * a2);

    // address=[0x150b910]
    virtual void  FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3);

    // address=[0x150b9c0]
    virtual void  Init(class CBuilding * a2);

    // address=[0x150bbc0]
    virtual void  PostLoadInit(class CBuilding * a2);

    // address=[0x150bc50]
    virtual bool  SettlerEnter(class CBuilding * a2, int a3);

    // address=[0x150bd10]
    virtual void  FillDialog(class CBuilding * a2, bool a3);

    // address=[0x150bed0]
     CGatherBuildingRole(std::istream & a2);

    // address=[0x150bf90]
    virtual void  Store(std::ostream & a2);

    // address=[0x3d8b134]
    static unsigned long m_iClassID;

private:
    // address=[0x14fd210]
    virtual void  ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *);

    // address=[0x14fde40]
    virtual bool  TryCrushBuilding(void);

    // address=[0x150bfe0]
    virtual bool  CrushBuilding(void);

};


#endif // CGATHERBUILDINGROLE_H
