#ifndef CINVOKEEVENT_H
#define CINVOKEEVENT_H

#include "defines.h"

class CInvokeEvent : public IScheduleEntry {
public:
    // address=[0x2f4e930]
     CInvokeEvent(void);

    // address=[0x2f4e960]
     CInvokeEvent(enum BUILDING_TYPES a2);

    // address=[0x2f4e9e0]
    bool  AddInvokePosition(int a2, int a3);

    // address=[0x2f4ea20]
    bool  AddInvokePosition(int a2);

    // address=[0x2f4ea50]
    int  AddInvokePositionAroundResource(enum BUILDING_TYPES a2, int a3);

    // address=[0x2f4ed40]
    virtual  ~CInvokeEvent(void);

    // address=[0x2f4edc0]
    virtual bool  IsShooting(void);

    // address=[0x2f4ee10]
    virtual bool  action(void);

    // address=[0x2f4ef80]
    virtual bool  IsAlive(void);

    // address=[0x2f4efd0]
    virtual bool  WaitFor(void);

};


#endif // CINVOKEEVENT_H
