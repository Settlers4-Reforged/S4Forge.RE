#ifndef CSTATEAOCAMPAIGNSSETTLE_H
#define CSTATEAOCAMPAIGNSSETTLE_H

#include "defines.h"

class CStateAOCampaignsSettle : public CGuiGameState {
public:
    // address=[0x14a0af0]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14a0b70]
     CStateAOCampaignsSettle(void *);

    // address=[0x14a0c30]
    virtual  ~CStateAOCampaignsSettle(void);

    // address=[0x14a0c90]
    virtual bool  Perform(void);

    // address=[0x14a0d70]
    virtual bool  OnEvent(class CEvn_Event & a2);

    // address=[0x14a0fb0]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEAOCAMPAIGNSSETTLE_H
