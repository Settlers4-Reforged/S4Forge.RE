#ifndef CDARKTEMPLEROLE_H
#define CDARKTEMPLEROLE_H

class CDarkTempleRole : public IBuildingRole {
public:
    // address=[0x14002c0]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x14fd970]
    static class CDarkTempleRole * __cdecl Load(std::istream &);

    // address=[0x1508260]
     CDarkTempleRole(void);

    // address=[0x1508360]
    virtual void  LogicUpdate(class CBuilding *);

    // address=[0x15084c0]
    virtual void  FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &);

    // address=[0x1508510]
    virtual void  Init(class CBuilding *);

    // address=[0x1508610]
    virtual void  PostLoadInit(class CBuilding *);

    // address=[0x1508690]
    virtual bool  SettlerEnter(class CBuilding *,int);

    // address=[0x1508820]
    void  TakeOrder(int,int);

    // address=[0x15089c0]
    int  ProduceMushroomFarmer(class CBuilding *);

    // address=[0x15089f0]
     CDarkTempleRole(std::istream &);

    // address=[0x1508bd0]
    virtual void  Store(std::ostream &);

    // address=[0x1509b60]
    virtual  ~CDarkTempleRole(void);

    // address=[0x1509ef0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x1509f50]
    virtual void  FillDialog(class CBuilding *,bool);

    // address=[0x1509f60]
    virtual int  GetBuildingNeed(int)const;

    // address=[0x1509f80]
    virtual int  GetBuildingRole(void);

    // address=[0x1509fa0]
    virtual int  GetPileIdWithGood(int)const;

    // address=[0x1509fc0]
    virtual void  GoodArrive(int);

    // address=[0x3d8b128]
    static unsigned long m_iClassID;

private:
    // address=[0x1508ce0]
    void  Produce(class CBuilding *);

    // address=[0x1508f70]
    void  AttackEnemies(class CBuilding *);

    // address=[0x1509350]
    void  ShowFireRing(int,int,int,int);

    // address=[0x1509450]
    void  ServantManagement(class CBuilding *);

    // address=[0x15094f0]
    int  AddSettlerToWorld(int,int,int);

    // address=[0x1509f10]
    virtual void  ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *);

    // address=[0x1509f20]
    virtual bool  CrushBuilding(void);

    // address=[0x1509fd0]
    virtual bool  TryCrushBuilding(void);

};


#endif // CDARKTEMPLEROLE_H
