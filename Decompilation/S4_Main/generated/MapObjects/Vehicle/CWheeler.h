#ifndef CWHEELER_H
#define CWHEELER_H

#include "defines.h"

class CWheeler : public CVehicle {
public:
    // address=[0x1539640]
    virtual  ~CWheeler(void);

    // address=[0x153fdc0]
    virtual void  FillDialog(bool a2);

    // address=[0x153feb0]
    virtual void  UnloadToPosition(int a2);

    // address=[0x159bb30]
    void  RemoveFromWorld(void);

    // address=[0x15afef0]
    virtual void  Delete(void);

    // address=[0x15aff90]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x15b0110]
    virtual void  ConvertEventIntoGoal(class CEntityEvent * a2);

    // address=[0x15b0480]
    int  RepairBuildingInRange(void);

    // address=[0x15b0560]
    void  RepairAt(int a2);

    // address=[0x15b0600]
    virtual void  SetObserverTarget(enum T_OBSERVER_TARGET a2, int a3);

    // address=[0x15b0680]
    virtual int  GetObserverTarget(enum T_OBSERVER_TARGET a2);

protected:
    // address=[0x153a640]
    virtual void  Unload(void);

    // address=[0x15b06b0]
     CWheeler(int a2, int a3, int a4, int a5, int a6, int a7, bool a8);

    // address=[0x15b07e0]
     CWheeler(std::istream & a2);

    // address=[0x15b08d0]
    virtual void  Store(std::ostream & a2);

    // address=[0x15b0950]
    virtual void  WalkDir(int a2);

    // address=[0x15b0af0]
    virtual void  PlaceVehicle(int a2);

    // address=[0x15b0ca0]
    virtual void  RemoveVehicle(int a2);

    // address=[0x15b0e20]
    virtual void  OnComeToFerry(int a2);

    // address=[0x37c1a4c]
    static int const REPAIT_BUILDING_SCAN_RANGE;

    // address=[0x37c1a50]
    static int const FULL_UPDATE_DELAY;

};


#endif // CWHEELER_H
