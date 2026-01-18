#ifndef CSTATEAOCAMPAIGNS_H
#define CSTATEAOCAMPAIGNS_H

#include "defines.h"

class CStateAOCampaigns : public CGuiGameState {
public:
    // address=[0x14a0390]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14a0410]
     CStateAOCampaigns(void *);

    // address=[0x14a04a0]
    virtual  ~CStateAOCampaigns(void);

    // address=[0x14a0500]
    virtual bool  Perform(void);

    // address=[0x14a0650]
    virtual bool  OnEvent(class CEvn_Event & a2);

    // address=[0x14a0aa0]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEAOCAMPAIGNS_H
