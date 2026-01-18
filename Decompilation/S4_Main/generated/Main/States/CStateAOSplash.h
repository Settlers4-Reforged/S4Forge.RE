#ifndef CSTATEAOSPLASH_H
#define CSTATEAOSPLASH_H

#include "defines.h"

class CStateAOSplash : public CGuiGameState {
public:
    // address=[0x14a1980]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14a1a00]
     CStateAOSplash(void * a2);

    // address=[0x14a1aa0]
    virtual  ~CStateAOSplash(void);

    // address=[0x14a1b30]
    virtual bool  Perform(void);

    // address=[0x14a1bd0]
    virtual bool  OnEvent(class CEvn_Event & a2);

};


#endif // CSTATEAOSPLASH_H
