#ifndef CFARMBUILDINGROLE_H
#define CFARMBUILDINGROLE_H

#include "defines.h"

class CFarmBuildingRole : public IBuildingRole {
public:
    // address=[0x1400900]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14fc9a0]
     CFarmBuildingRole(void);

    // address=[0x14fcc10]
    virtual  ~CFarmBuildingRole(void);

    // address=[0x14fd0c0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14fd360]
    virtual int  GetBuildingNeed(int a2)const;

    // address=[0x14fd4a0]
    virtual int  GetBuildingRole(void);

    // address=[0x14fd600]
    virtual int  GetPileIdWithGood(int a2)const;

    // address=[0x14fd700]
    virtual void  GoodArrive(int a2);

    // address=[0x14fd9f0]
    static class CFarmBuildingRole * __cdecl Load(std::istream & a1);

    // address=[0x150a5e0]
    virtual void  LogicUpdate(class CBuilding * a2);

    // address=[0x150aa20]
    virtual void  FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3);

    // address=[0x150aae0]
    virtual void  Init(class CBuilding * a2);

    // address=[0x150add0]
    virtual void  PostLoadInit(class CBuilding * a2);

    // address=[0x150ae00]
    virtual void  LockPiles(class CBuilding * a2, bool a3);

    // address=[0x150ae60]
    virtual bool  SettlerEnter(class CBuilding * a2, int a3);

    // address=[0x150afa0]
    virtual void  FillDialog(class CBuilding * a2, bool a3);

    // address=[0x150b160]
     CFarmBuildingRole(std::istream & a2);

    // address=[0x150b220]
    virtual void  Store(std::ostream & a2);

    // address=[0x3d8b130]
    static unsigned long m_iClassID;

private:
    // address=[0x14fd200]
    virtual void  ConvertEventIntoGoal(class CBuilding * a1, class CEntityEvent * a2);

    // address=[0x14fd280]
    virtual bool  CrushBuilding(void);

    // address=[0x14fde30]
    virtual bool  TryCrushBuilding(void);

};


#endif // CFARMBUILDINGROLE_H
