#ifndef CBUILDINGSITEROLE_H
#define CBUILDINGSITEROLE_H

class CBuildingSiteRole : public IBuildingRole {
public:
    // address=[0x13ffe60]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x1447610]
    bool  HaveBoardPriority(void)const;

    // address=[0x1447630]
    bool  HaveBuilderPriority(void)const;

    // address=[0x1447650]
    bool  HaveDiggerPriority(void)const;

    // address=[0x1447670]
    bool  HavePriority(void)const;

    // address=[0x1447690]
    bool  HaveStonePriority(void)const;

    // address=[0x14476b0]
    int  MaxNeededBuilder(void)const;

    // address=[0x14476d0]
    int  MaxNeededDigger(void)const;

    // address=[0x14fd8b0]
    static class CBuildingSiteRole * __cdecl Load(std::istream &);

    // address=[0x1501250]
     CBuildingSiteRole(void);

    // address=[0x15013e0]
    virtual void  Init(class CBuilding *);

    // address=[0x1501570]
    virtual void  LogicUpdate(class CBuilding *);

    // address=[0x1501eb0]
    virtual void  PostLoadInit(class CBuilding *);

    // address=[0x1501f60]
    virtual void  FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &);

    // address=[0x1502120]
    virtual void  GoodArrive(int);

    // address=[0x1502140]
    virtual bool  SettlerEnter(class CBuilding *,int);

    // address=[0x1502170]
    virtual int  GetBuildingNeed(int)const;

    // address=[0x15021c0]
    virtual int  GetPileIdWithGood(int)const;

    // address=[0x1502220]
    int  HaveBuildingMaterial(void);

    // address=[0x15022d0]
    void  SetDiggingInfos(int,int);

    // address=[0x1502350]
    int  BuildingProgress(void);

    // address=[0x1502460]
    virtual void  SwitchPriority(void);

    // address=[0x1502510]
    virtual void  FillDialog(class CBuilding *,bool);

    // address=[0x1502ac0]
    void  GetBuilderPos(struct SBuilderPos &);

    // address=[0x1502c30]
    void  AddWork(int);

    // address=[0x1502de0]
     CBuildingSiteRole(std::istream &);

    // address=[0x1503150]
    virtual void  Store(std::ostream &);

    // address=[0x1506140]
    virtual  ~CBuildingSiteRole(void);

    // address=[0x15063b0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x1506420]
    virtual int  GetBuildingRole(void);

    // address=[0x1506480]
    virtual void  InhabitantFlee(int);

    // address=[0x3d8b11c]
    static unsigned long m_iClassID;

private:
    // address=[0x1503410]
    int  GetEcoSectorId(void);

    // address=[0x1503440]
    virtual bool  CrushBuilding(void);

    // address=[0x15035e0]
    virtual void  Switch(void);

    // address=[0x1503780]
    void  CheckDeactivateUrgentBoards(int);

    // address=[0x15037d0]
    void  CheckDeactivateUrgentStones(int);

    // address=[0x1503820]
    void  CheckDeactivateUrgentBuilder(int);

    // address=[0x1503890]
    void  CheckDeactivateUrgentDigger(int);

    // address=[0x15038f0]
    void  CheckDeactivatePriority(int);

    // address=[0x15039a0]
    void  CheckActivateUrgentBoards(int);

    // address=[0x1503a80]
    void  CheckActivateUrgentStones(int);

    // address=[0x1503b60]
    void  CheckActivateUrgentBuilder(int);

    // address=[0x1503c40]
    void  CheckActivateUrgentDigger(int);

    // address=[0x1503d50]
    void  OrderDigger(class CBuilding *);

    // address=[0x1503e40]
    void  DiggingIsReady(int);

    // address=[0x1503eb0]
    void  TidyUp(class CEntityEvent &);

    // address=[0x1503f10]
    void  NotifyDeliverPiles(class CEntityEvent &);

    // address=[0x1503fd0]
    void  OrderBuilder(class CBuilding *);

    // address=[0x15040d0]
    void  OrderMaterial(class CBuilding *);

    // address=[0x1504360]
    void  BuildingDone(class CBuilding *);

    // address=[0x1504510]
    void  DeleteStakes(class CBuilding *);

    // address=[0x15046e0]
    void  BuilderLeft(int);

    // address=[0x15047d0]
    virtual void  ReturnBuildingMaterial(class CBuilding *);

    // address=[0x1504960]
    void  PrepareGround(class CBuilding *);

    // address=[0x15063d0]
    virtual void  ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *);

    // address=[0x1506430]
    int  GetEcoSectorId(class CBuilding *);

    // address=[0x1506490]
    int  NeedBoards(void)const;

    // address=[0x1506510]
    int  NeedGold(void)const;

    // address=[0x1506590]
    int  NeedStone(void)const;

    // address=[0x15067d0]
    virtual bool  TryCrushBuilding(void);

};


#endif // CBUILDINGSITEROLE_H
