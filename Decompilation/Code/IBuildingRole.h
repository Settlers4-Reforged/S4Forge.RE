#ifndef IBUILDINGROLE_H
#define IBUILDINGROLE_H

class IBuildingRole : public CPersistence {
public:
    // address=[0x130f040]
    bool  HaveInhabitant(void)const;

    // address=[0x14e66e0]
    virtual  ~IBuildingRole(void);

    // address=[0x14e67d0]
    virtual int  GetPileIdWithNeedForGood(int)const;

    // address=[0x14e6800]
    virtual bool  HasShipAmmo(int)const;

    // address=[0x14e6820]
    virtual void  LockPiles(class CBuilding *,bool);

    // address=[0x14e6840]
    virtual void  NotifySelected(void);

    // address=[0x14e6850]
    virtual void  OrderInhabitantCancelled(class CBuilding *);

    // address=[0x14e68b0]
    virtual bool  SettlerEnter(class CBuilding *,int);

    // address=[0x14e68e0]
    virtual void  SwitchPriority(void);

    // address=[0x14fdee0]
     IBuildingRole(void);

    // address=[0x14fdfb0]
    virtual void  Update(class CBuilding *);

    // address=[0x14fe560]
    virtual void  Switch(void);

    // address=[0x14fe6b0]
    virtual void  InhabitantFlee(int);

    // address=[0x14fe750]
    virtual void  ReturnBuildingMaterial(class CBuilding *);

    // address=[0x14fe8d0]
    virtual void  RemoveInhabitant(class CBuilding *);

    // address=[0x14feaf0]
    virtual bool  SearchInWorkingArea(class CBuilding *,int);

    // address=[0x14ff140]
    virtual int  Decrease(int);

    // address=[0x14ff180]
    void  TakeJobTrigger(int);

    // address=[0x14ff580]
    void  PostLoadSetWaterFlags(class CBuilding *);

    // address=[0x14ff650]
     IBuildingRole(std::istream &);

    // address=[0x14ffaa0]
    virtual void  Store(std::ostream &);

protected:
    // address=[0x14ffe90]
    virtual void  KillInhabitant(class CBuilding *);

    // address=[0x14ffea0]
    void  InitCommon(class CBuilding *);

    // address=[0x14fff70]
    void  InitHousePatches(void);

    // address=[0x1500310]
    virtual bool  OrderInhabitant(class CBuilding *);

    // address=[0x15003d0]
    void  MiniFlag(struct SGfxObjectInfo &,int);

    // address=[0x1500590]
    void  WorkingAreaChanged(void);

    // address=[0x1500620]
    void  DetachWithoutNotify(class CBuilding *,int);

    // address=[0x40f21a4]
    static int m_iLastMiniFlagUpdateTick;

private:
    // address=[0x14e6830]
    virtual void  NotifyDetach(class CBuilding *,int);

};


#endif // IBUILDINGROLE_H
