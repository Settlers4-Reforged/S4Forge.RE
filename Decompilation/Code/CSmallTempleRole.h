#ifndef CSMALLTEMPLEROLE_H
#define CSMALLTEMPLEROLE_H

class CSmallTempleRole : public IBuildingRole {
public:
    // address=[0x1401ee0]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x14fcb40]
     CSmallTempleRole(void);

    // address=[0x14fcd40]
    virtual  ~CSmallTempleRole(void);

    // address=[0x14fd1a0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14fd420]
    virtual int  GetBuildingNeed(int)const;

    // address=[0x14fd580]
    virtual int  GetBuildingRole(void);

    // address=[0x14fd6c0]
    virtual int  GetPileIdWithGood(int)const;

    // address=[0x14fd760]
    virtual void  GoodArrive(int);

    // address=[0x14fdc30]
    static class CSmallTempleRole * __cdecl Load(std::istream &);

    // address=[0x151bf20]
    virtual void  LogicUpdate(class CBuilding *);

    // address=[0x151c130]
    virtual void  FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &);

    // address=[0x151c320]
    virtual void  Init(class CBuilding *);

    // address=[0x151c5b0]
    virtual void  PostLoadInit(class CBuilding *);

    // address=[0x151c5e0]
    virtual bool  SettlerEnter(class CBuilding *,int);

    // address=[0x151c890]
    virtual void  FillDialog(class CBuilding *,bool);

    // address=[0x151ca80]
    virtual void  LockPiles(class CBuilding *,bool);

    // address=[0x151cb10]
     CSmallTempleRole(std::istream &);

    // address=[0x151cbf0]
    virtual void  Store(std::ostream &);

    // address=[0x3d8b79c]
    static unsigned long m_iClassID;

private:
    // address=[0x14fd260]
    virtual void  ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *);

    // address=[0x14fd2c0]
    virtual bool  CrushBuilding(void);

    // address=[0x14fde90]
    virtual bool  TryCrushBuilding(void);

    // address=[0x151cc50]
    bool  HaveMaterial(class CBuilding *);

};


#endif // CSMALLTEMPLEROLE_H
