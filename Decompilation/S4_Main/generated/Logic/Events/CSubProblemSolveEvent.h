#ifndef CSUBPROBLEMSOLVEEVENT_H
#define CSUBPROBLEMSOLVEEVENT_H

#include "defines.h"

class CSubProblemSolveEvent : public IScheduleEntry {
public:
    // address=[0x2f4e360]
     CSubProblemSolveEvent(class CSiedlerAI * a2, int a3, int a4, int a5, int a6, int a7, int a8, class COptimizeOptions * a9);

    // address=[0x2f4e470]
    virtual  ~CSubProblemSolveEvent(void);

    // address=[0x2f4e4c0]
    virtual bool  IsShooting(void);

    // address=[0x2f4e550]
    virtual bool  action(void);

    // address=[0x2f4e8b0]
    virtual bool  IsAlive(void);

    // address=[0x2f4e8f0]
    virtual bool  WaitFor(void);

};


#endif // CSUBPROBLEMSOLVEEVENT_H
