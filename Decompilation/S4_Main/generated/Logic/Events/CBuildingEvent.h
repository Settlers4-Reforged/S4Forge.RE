#ifndef CBUILDINGEVENT_H
#define CBUILDINGEVENT_H

#include "defines.h"

class CBuildingEvent : public IScheduleEntry {
public:
    // address=[0x2f51210]
     CBuildingEvent(enum BUILDING_TYPES a2, int a3, int a4, int a5, int a6, int a7, enum T_BUILD_LEVEL a8);

    // address=[0x2f512c0]
    virtual  ~CBuildingEvent(void);

    // address=[0x2f512e0]
    virtual bool  IsShooting(void);

    // address=[0x2f516c0]
    virtual bool  action(void);

    // address=[0x2f51850]
    virtual bool  IsAlive(void);

    // address=[0x2f518b0]
    virtual bool  WaitFor(void);

};


#endif // CBUILDINGEVENT_H
