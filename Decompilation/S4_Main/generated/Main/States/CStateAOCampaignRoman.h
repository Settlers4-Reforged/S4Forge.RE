#ifndef CSTATEAOCAMPAIGNROMAN_H
#define CSTATEAOCAMPAIGNROMAN_H

#include "defines.h"

class CStateAOCampaignRoman : public CGuiGameState {
public:
    // address=[0x149fec0]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x149ff40]
     CStateAOCampaignRoman(void *);

    // address=[0x14a0000]
    virtual  ~CStateAOCampaignRoman(void);

    // address=[0x14a0060]
    virtual bool  Perform(void);

    // address=[0x14a0140]
    virtual bool  OnEvent(class CEvn_Event & a2);

    // address=[0x14a0380]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEAOCAMPAIGNROMAN_H
