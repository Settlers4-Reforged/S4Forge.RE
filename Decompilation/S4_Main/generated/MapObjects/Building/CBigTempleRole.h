#ifndef CBIGTEMPLEROLE_H
#define CBIGTEMPLEROLE_H

#include "defines.h"

class CBigTempleRole : public IBuildingRole {
public:
    // address=[0x13ffbe0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14e8200]
    virtual void  LogicUpdate(class CBuilding * a2);

    // address=[0x14e8350]
    virtual void  FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3);

    // address=[0x14e83a0]
    virtual void  Init(class CBuilding * a2);

    // address=[0x14e8400]
    virtual void  PostLoadInit(class CBuilding * a2);

    // address=[0x14e8430]
    virtual void  FillDialog(class CBuilding * a2, bool a3);

    // address=[0x14e8560]
     CBigTempleRole(std::istream & a2);

    // address=[0x14e8630]
    virtual void  Store(std::ostream & a2);

    // address=[0x14e8850]
    virtual  ~CBigTempleRole(void);

    // address=[0x14e88d0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14e8930]
    virtual int  GetBuildingNeed(int a2)const;

    // address=[0x14e8950]
    virtual int  GetBuildingRole(void);

    // address=[0x14e8970]
    virtual int  GetPileIdWithGood(int a2)const;

    // address=[0x14e8990]
    virtual void  GoodArrive(int a2);

    // address=[0x14fc8d0]
     CBigTempleRole(void);

    // address=[0x14fd870]
    static class CBigTempleRole * __cdecl Load(std::istream & a1);

    // address=[0x3d8b08c]
    static unsigned long m_iClassID;

private:
    // address=[0x14e8680]
    void  ThrowOutPriest(class CBuilding * a2);

    // address=[0x14e88f0]
    virtual void  ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *);

    // address=[0x14e8900]
    virtual bool  CrushBuilding(void);

    // address=[0x14e89a0]
    virtual bool  TryCrushBuilding(void);

};


#endif // CBIGTEMPLEROLE_H
