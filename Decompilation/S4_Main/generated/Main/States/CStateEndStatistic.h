#ifndef CSTATEENDSTATISTIC_H
#define CSTATEENDSTATISTIC_H

#include "defines.h"

class CStateEndStatistic : public CGuiGameState {
public:
    // address=[0x14a4c30]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14a4cb0]
     CStateEndStatistic(void *);

    // address=[0x14a4dc0]
    virtual  ~CStateEndStatistic(void);

    // address=[0x14a4e40]
    virtual bool  Perform(void);

    // address=[0x14a4ee0]
    virtual bool  OnEvent(class CEvn_Event & a2);

};


#endif // CSTATEENDSTATISTIC_H
