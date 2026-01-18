#ifndef CSTATEAOCAMPAIGNVIKING_H
#define CSTATEAOCAMPAIGNVIKING_H

#include "defines.h"

class CStateAOCampaignViking : public CGuiGameState {
public:
    // address=[0x14a14b0]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14a1530]
     CStateAOCampaignViking(void * a2);

    // address=[0x14a15f0]
    virtual  ~CStateAOCampaignViking(void);

    // address=[0x14a1650]
    virtual bool  Perform(void);

    // address=[0x14a1730]
    virtual bool  OnEvent(class CEvn_Event & a2);

    // address=[0x14a1970]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEAOCAMPAIGNVIKING_H
