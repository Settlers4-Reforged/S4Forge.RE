#ifndef CSTORAGEBUILDINGROLE_H
#define CSTORAGEBUILDINGROLE_H

class CStorageBuildingRole : public IBuildingRole {
public:
    // address=[0x1402160]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x14fdc70]
    static class CStorageBuildingRole * __cdecl Load(std::istream &);

    // address=[0x151cff0]
     CStorageBuildingRole(void);

    // address=[0x151d070]
     CStorageBuildingRole(std::istream &);

    // address=[0x151d1b0]
    virtual void  Store(std::ostream &);

    // address=[0x151d270]
    virtual void  Init(class CBuilding *);

    // address=[0x151d4f0]
    virtual void  PostLoadInit(class CBuilding *);

    // address=[0x151d540]
    virtual void  Switch(void);

    // address=[0x151d670]
    virtual void  LogicUpdate(class CBuilding *);

    // address=[0x151d6b0]
    virtual void  FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &);

    // address=[0x151d7a0]
    virtual void  FillDialog(class CBuilding *,bool);

    // address=[0x151d9e0]
    void  FillStorageSideBar(class CStorageSideBarInfo *,bool);

    // address=[0x151daf0]
    virtual int  GetPileIdWithGood(int)const;

    // address=[0x151dbf0]
    virtual void  GoodArrive(int);

    // address=[0x151dc00]
    int  GetNextFreePile(void);

    // address=[0x151dcc0]
    int  ReserveNextFreePile(int);

    // address=[0x151dd90]
    bool  ReserveFreePile(int,int);

    // address=[0x151de90]
    int  GetSpaceAmount(int);

    // address=[0x151dfa0]
    void  RegisterPilesAndStorageAtEcosector(int);

    // address=[0x151e180]
    void  ExecuteUnforseenGoodTypeChange(int,int,int);

    // address=[0x151e290]
    void  UnregisterPile(int);

    // address=[0x151e430]
    void  SwitchGood(int,int);

    // address=[0x151e690]
    void  NotifyChangeEcoSector(class CPile *,int,int);

    // address=[0x151f900]
    virtual  ~CStorageBuildingRole(void);

    // address=[0x151f9f0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x151fa50]
    virtual int  GetBuildingNeed(int)const;

    // address=[0x151fa70]
    virtual int  GetBuildingRole(void);

    // address=[0x3d8b7a0]
    static unsigned long m_iClassID;

private:
    // address=[0x151e870]
    int  NrSelectedStores(void);

    // address=[0x151e8c0]
    int  NrUsedPiles(void);

    // address=[0x151e970]
    void  CheckGoodToStore(void);

    // address=[0x151eb90]
    int  GetNextGoodToCheck(int);

    // address=[0x151ebf0]
    int  GetReservedPile(int);

    // address=[0x151ecc0]
    void  CheckEmptyPile(int);

    // address=[0x151ee00]
    virtual bool  CrushBuilding(void);

    // address=[0x151fa10]
    virtual void  ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *);

    // address=[0x151faf0]
    virtual bool  TryCrushBuilding(void);

};


#endif // CSTORAGEBUILDINGROLE_H
