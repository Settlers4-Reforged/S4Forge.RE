#ifndef CMAINPROBLEMSOLVEEVENT_H
#define CMAINPROBLEMSOLVEEVENT_H

#include "defines.h"

class CMainProblemSolveEvent : public IScheduleEntry {
public:
    // address=[0x2f4dcc0]
     CMainProblemSolveEvent(int a2, int a3, int a4, int a5, int a6, int a7);

    // address=[0x2f4dd90]
    virtual  ~CMainProblemSolveEvent(void);

    // address=[0x2f4de10]
    virtual bool  IsShooting(void);

    // address=[0x2f4deb0]
    virtual bool  action(void);

    // address=[0x2f4e2a0]
    virtual bool  IsAlive(void);

    // address=[0x2f4e330]
    virtual bool  WaitFor(void);

};


#endif // CMAINPROBLEMSOLVEEVENT_H
