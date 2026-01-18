#ifndef CRESOURCEMANAGERTASK_H
#define CRESOURCEMANAGERTASK_H

#include "defines.h"

class CResourceManagerTask : public IScheduleEntry {
public:
    // address=[0x2f558c0]
     CResourceManagerTask(void);

    // address=[0x2f558e0]
     CResourceManagerTask(int a2);

    // address=[0x2f559a0]
    virtual  ~CResourceManagerTask(void);

    // address=[0x2f55a40]
    void  ClearBuildingPlaces(void);

    // address=[0x2f55a80]
    void  NewBuildingPlace(int a2, int a3, int a4);

    // address=[0x2f55b70]
    void  UpdateBuildingPlaces(void);

    // address=[0x2f55bd0]
    bool  AreaHasResource(int a2, int a3);

    // address=[0x2f55c50]
    int  FillRareBuildings(class CReserveEntry * a2, int a3);

    // address=[0x2f55ce0]
    virtual bool  IsShooting(void a2);

    // address=[0x2f56630]
    virtual bool  action(void);

    // address=[0x2f566e0]
    virtual bool  IsAlive(void);

    // address=[0x2f566f0]
    virtual bool  WaitFor(void);

};


#endif // CRESOURCEMANAGERTASK_H
