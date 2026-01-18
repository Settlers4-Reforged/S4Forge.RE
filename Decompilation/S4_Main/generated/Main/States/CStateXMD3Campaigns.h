#ifndef CSTATEXMD3CAMPAIGNS_H
#define CSTATEXMD3CAMPAIGNS_H

#include "defines.h"

class CStateXMD3Campaigns : public CGuiGameState {
public:
    // address=[0x14cdf60]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14cdfe0]
     CStateXMD3Campaigns(void * a2);

    // address=[0x14ce120]
    virtual  ~CStateXMD3Campaigns(void);

    // address=[0x14ce180]
    virtual bool  Perform(void);

    // address=[0x14ce2b0]
    virtual bool  OnEvent(class CEvn_Event & a2);

    // address=[0x14ce6f0]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEXMD3CAMPAIGNS_H
