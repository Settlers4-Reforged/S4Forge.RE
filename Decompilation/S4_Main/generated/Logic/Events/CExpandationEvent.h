#ifndef CEXPANDATIONEVENT_H
#define CEXPANDATIONEVENT_H

#include "defines.h"

class CExpandationEvent : public IScheduleEntry {
public:
    // address=[0x2f51d40]
     CExpandationEvent(int a2, int a3, int a4);

    // address=[0x2f51de0]
     CExpandationEvent(int a2, class CSchedule * a3);

    // address=[0x2f520f0]
    virtual  ~CExpandationEvent(void);

    // address=[0x2f52180]
    virtual bool  IsShooting(void a2);

    // address=[0x2f52680]
    virtual bool  action(void);

    // address=[0x2f52730]
    virtual bool  IsAlive(void);

    // address=[0x2f52740]
    virtual bool  WaitFor(void);

};


#endif // CEXPANDATIONEVENT_H
