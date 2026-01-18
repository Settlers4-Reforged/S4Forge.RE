#ifndef CSTATECREDITS_H
#define CSTATECREDITS_H

#include "defines.h"

class CStateCredits : public CGuiGameState {
public:
    // address=[0x14a3fb0]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14a4160]
     CStateCredits(void * a2);

    // address=[0x14a41e0]
    virtual  ~CStateCredits(void);

    // address=[0x14a4330]
    virtual bool  Perform(void);

    // address=[0x14a43b0]
    virtual bool  OnEvent(class CEvn_Event & a2);

private:
    // address=[0x14a4030]
    void  SetupGUI(void);

};


#endif // CSTATECREDITS_H
