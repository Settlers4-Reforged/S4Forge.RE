#ifndef CWORKUPBUILDINGROLE_H
#define CWORKUPBUILDINGROLE_H

class CWorkUpBuildingRole : public IBuildingRole {
public:
    // address=[0x1402980]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x14e66b0]
    virtual  ~CWorkUpBuildingRole(void);

    // address=[0x14fcb70]
     CWorkUpBuildingRole(void);

    // address=[0x14fd1c0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14fd5a0]
    virtual int  GetBuildingRole(void);

    // address=[0x14fdcf0]
    static class CWorkUpBuildingRole * __cdecl Load(std::istream &);

    // address=[0x152f370]
    virtual void  LogicUpdate(class CBuilding *);

    // address=[0x152f610]
    virtual void  FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &);

    // address=[0x152f8e0]
    virtual void  Init(class CBuilding *);

    // address=[0x152fb80]
    virtual void  PostLoadInit(class CBuilding *);

    // address=[0x152fbe0]
    virtual bool  SettlerEnter(class CBuilding *,int);

    // address=[0x152feb0]
    virtual int  GetBuildingNeed(int)const;

    // address=[0x152ff50]
    virtual int  GetPileIdWithGood(int)const;

    // address=[0x1530070]
    virtual void  GoodArrive(int);

    // address=[0x1530080]
    virtual void  LockPiles(class CBuilding *,bool);

    // address=[0x1530120]
     CWorkUpBuildingRole(std::istream &);

    // address=[0x15302d0]
    virtual void  Store(std::ostream &);

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
    bool  HaveMaterial(class CBuilding *);

    // address=[0x1530410]
    virtual void  FillDialog(class CBuilding *,bool);

};


#endif // CWORKUPBUILDINGROLE_H
