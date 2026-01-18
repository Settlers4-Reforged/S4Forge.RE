#ifndef CRESIDENCEBUILDINGROLE_H
#define CRESIDENCEBUILDINGROLE_H

#include "defines.h"

class CResidenceBuildingRole : public IBuildingRole {
public:
    // address=[0x1401940]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14fcae0]
     CResidenceBuildingRole(void);

    // address=[0x14fcd00]
    virtual  ~CResidenceBuildingRole(void);

    // address=[0x14fd160]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14fd3e0]
    virtual int  GetBuildingNeed(int a2)const;

    // address=[0x14fd540]
    virtual int  GetBuildingRole(void);

    // address=[0x14fd680]
    virtual int  GetPileIdWithGood(int a2)const;

    // address=[0x14fd740]
    virtual void  GoodArrive(int a2);

    // address=[0x14fdbb0]
    static class CResidenceBuildingRole * __cdecl Load(std::istream & a1);

    // address=[0x1518780]
    virtual void  LogicUpdate(class CBuilding * a2);

    // address=[0x1518af0]
    virtual void  FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3);

    // address=[0x1518b40]
    virtual void  Init(class CBuilding * a2);

    // address=[0x1518c80]
    virtual void  PostLoadInit(class CBuilding * a2);

    // address=[0x1518cb0]
    virtual void  FillDialog(class CBuilding * a2, bool a3);

    // address=[0x1518e10]
    int  ReturnRemainingSettlers(void);

    // address=[0x1518e50]
     CResidenceBuildingRole(std::istream & a2);

    // address=[0x1518f10]
    virtual void  Store(std::ostream & a2);

    // address=[0x3d8b58c]
    static unsigned long m_iClassID;

private:
    // address=[0x14fd240]
    virtual void  ConvertEventIntoGoal(class CBuilding * a2, class CEntityEvent * a3);

    // address=[0x14fde70]
    virtual bool  TryCrushBuilding(void);

    // address=[0x1518f60]
    virtual bool  CrushBuilding(void);

};


#endif // CRESIDENCEBUILDINGROLE_H
