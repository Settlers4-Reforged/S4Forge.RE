#ifndef CLOOKOUTTOWERROLE_H
#define CLOOKOUTTOWERROLE_H

class CLookoutTowerRole : public IBuildingRole {
public:
    // address=[0x1401080]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x14fca00]
     CLookoutTowerRole(void);

    // address=[0x14fcc50]
    virtual  ~CLookoutTowerRole(void);

    // address=[0x14fd100]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14fd3a0]
    virtual int  GetBuildingNeed(int)const;

    // address=[0x14fd4e0]
    virtual int  GetBuildingRole(void);

    // address=[0x14fd640]
    virtual int  GetPileIdWithGood(int)const;

    // address=[0x14fd720]
    virtual void  GoodArrive(int);

    // address=[0x14fda70]
    static class CLookoutTowerRole * __cdecl Load(std::istream &);

    // address=[0x150c280]
    virtual void  LogicUpdate(class CBuilding *);

    // address=[0x150c410]
    virtual void  FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &);

    // address=[0x150c470]
    virtual void  Init(class CBuilding *);

    // address=[0x150c4d0]
    virtual void  PostLoadInit(class CBuilding *);

    // address=[0x150c500]
    virtual bool  SettlerEnter(class CBuilding *,int);

    // address=[0x150c560]
    virtual void  FillDialog(class CBuilding *,bool);

    // address=[0x150c6a0]
     CLookoutTowerRole(std::istream &);

    // address=[0x150c760]
    virtual void  Store(std::ostream &);

    // address=[0x3d8b138]
    static unsigned long m_iClassID;

private:
    // address=[0x14fd220]
    virtual void  ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *);

    // address=[0x14fd290]
    virtual bool  CrushBuilding(void);

    // address=[0x14fde50]
    virtual bool  TryCrushBuilding(void);

};


#endif // CLOOKOUTTOWERROLE_H
