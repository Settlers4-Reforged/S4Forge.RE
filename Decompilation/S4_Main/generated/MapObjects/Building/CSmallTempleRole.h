#ifndef CSMALLTEMPLEROLE_H
#define CSMALLTEMPLEROLE_H

#include "defines.h"

class CSmallTempleRole : public IBuildingRole {
public:
    // address=[0x1401ee0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14fcb40]
     CSmallTempleRole(void);

    // address=[0x14fcd40]
    virtual  ~CSmallTempleRole(void);

    // address=[0x14fd1a0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14fd420]
    virtual int  GetBuildingNeed(int a2)const;

    // address=[0x14fd580]
    virtual int  GetBuildingRole(void);

    // address=[0x14fd6c0]
    virtual int  GetPileIdWithGood(int a2)const;

    // address=[0x14fd760]
    virtual void  GoodArrive(int a2);

    // address=[0x14fdc30]
    static class CSmallTempleRole * __cdecl Load(std::istream & a1);

    // address=[0x151bf20]
    virtual void  LogicUpdate(class CBuilding * a2);

    // address=[0x151c130]
    virtual void  FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3);

    // address=[0x151c320]
    virtual void  Init(class CBuilding * a2);

    // address=[0x151c5b0]
    virtual void  PostLoadInit(class CBuilding * a2);

    // address=[0x151c5e0]
    virtual bool  SettlerEnter(class CBuilding * a2, int a3);

    // address=[0x151c890]
    virtual void  FillDialog(class CBuilding * a2, bool a3);

    // address=[0x151ca80]
    virtual void  LockPiles(class CBuilding * a2, bool a3);

    // address=[0x151cb10]
     CSmallTempleRole(std::istream & a2);

    // address=[0x151cbf0]
    virtual void  Store(std::ostream & a2);

    // address=[0x3d8b79c]
    static unsigned long m_iClassID;

private:
    // address=[0x14fd260]
    virtual void  ConvertEventIntoGoal(class CBuilding * a2, class CEntityEvent * a3);

    // address=[0x14fd2c0]
    virtual bool  CrushBuilding(void);

    // address=[0x14fde90]
    virtual bool  TryCrushBuilding(void);

    // address=[0x151cc50]
    bool  HaveMaterial(class CBuilding * a2);

};


#endif // CSMALLTEMPLEROLE_H
