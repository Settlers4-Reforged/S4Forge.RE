#ifndef CFSM_H
#define CFSM_H

#include "defines.h"

class CFsm {
public:
    // address=[0x1460490]
    int  CurrentState(void)const;

    // address=[0x2f05d80]
     CFsm(class IEventHandler * a2, int a3, int a4);

    // address=[0x2f05e40]
     ~CFsm(void);

    // address=[0x2f05e80]
    int  DefineTransition(int a2, int a3, int a4, int a5);

    // address=[0x2f05f00]
    int  Control(int a2, void * a3);

    // address=[0x2f06060]
    void  GenerateEvent(int a1, void * a2);

private:
    // address=[0x2f06080]
    void  InsertInQueue(int a1, void * a2);

    // address=[0x2f060f0]
    int  Hash(int a2, int a3);

    // address=[0x2f06170]
    int  Hash(int a2);

};


#endif // CFSM_H
