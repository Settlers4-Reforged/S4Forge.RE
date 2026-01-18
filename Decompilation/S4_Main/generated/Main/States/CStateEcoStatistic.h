#ifndef CSTATEECOSTATISTIC_H
#define CSTATEECOSTATISTIC_H

#include "defines.h"

class CStateEcoStatistic : public CGuiGameState {
public:
    // address=[0x14a47b0]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14a4830]
     CStateEcoStatistic(void *);

    // address=[0x14a48c0]
    virtual  ~CStateEcoStatistic(void);

    // address=[0x14a4940]
    virtual bool  Perform(void);

    // address=[0x14a49e0]
    virtual bool  OnEvent(class CEvn_Event & a2);

};


#endif // CSTATEECOSTATISTIC_H
