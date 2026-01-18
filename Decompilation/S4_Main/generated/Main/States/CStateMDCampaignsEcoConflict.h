#ifndef CSTATEMDCAMPAIGNSECOCONFLICT_H
#define CSTATEMDCAMPAIGNSECOCONFLICT_H

#include "defines.h"

class CStateMDCampaignsEcoConflict : public CGuiGameState {
public:
    // address=[0x14c76b0]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14c7730]
     CStateMDCampaignsEcoConflict(void * a2);

    // address=[0x14c7820]
    virtual  ~CStateMDCampaignsEcoConflict(void);

    // address=[0x14c7880]
    virtual bool  Perform(void);

    // address=[0x14c7960]
    virtual bool  OnEvent(class CEvn_Event & a2);

    // address=[0x14c7c00]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEMDCAMPAIGNSECOCONFLICT_H
