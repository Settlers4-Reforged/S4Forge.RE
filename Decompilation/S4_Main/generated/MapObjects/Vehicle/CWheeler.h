#ifndef CWHEELER_H
#define CWHEELER_H

class CWheeler : public CVehicle {
public:
    // address=[0x1539640]
    virtual  ~CWheeler(void);

    // address=[0x153fdc0]
    virtual void  FillDialog(bool);

    // address=[0x153feb0]
    virtual void  UnloadToPosition(int);

    // address=[0x159bb30]
    void  RemoveFromWorld(void);

    // address=[0x15afef0]
    virtual void  Delete(void);

    // address=[0x15aff90]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x15b0110]
    virtual void  ConvertEventIntoGoal(class CEntityEvent *);

    // address=[0x15b0480]
    int  RepairBuildingInRange(void);

    // address=[0x15b0560]
    void  RepairAt(int);

    // address=[0x15b0600]
    virtual void  SetObserverTarget(enum T_OBSERVER_TARGET,int);

    // address=[0x15b0680]
    virtual int  GetObserverTarget(enum T_OBSERVER_TARGET);

protected:
    // address=[0x153a640]
    virtual void  Unload(void);

    // address=[0x15b06b0]
     CWheeler(int,int,int,int,int,int,bool);

    // address=[0x15b07e0]
     CWheeler(std::istream &);

    // address=[0x15b08d0]
    virtual void  Store(std::ostream &);

    // address=[0x15b0950]
    virtual void  WalkDir(int);

    // address=[0x15b0af0]
    virtual void  PlaceVehicle(int);

    // address=[0x15b0ca0]
    virtual void  RemoveVehicle(int);

    // address=[0x15b0e20]
    virtual void  OnComeToFerry(int);

    // address=[0x37c1a4c]
    static int const REPAIT_BUILDING_SCAN_RANGE;

    // address=[0x37c1a50]
    static int const FULL_UPDATE_DELAY;

};


#endif // CWHEELER_H
