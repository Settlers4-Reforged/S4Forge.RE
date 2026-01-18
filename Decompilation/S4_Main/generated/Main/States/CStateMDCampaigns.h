#ifndef CSTATEMDCAMPAIGNS_H
#define CSTATEMDCAMPAIGNS_H

#include "defines.h"

class CStateMDCampaigns : public CGuiGameState {
public:
    // address=[0x14c6f90]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14c7010]
     CStateMDCampaigns(void * a2);

    // address=[0x14c70b0]
    virtual  ~CStateMDCampaigns(void);

    // address=[0x14c7110]
    virtual bool  Perform(void);

    // address=[0x14c7260]
    virtual bool  OnEvent(class CEvn_Event & a2);

    // address=[0x14c76a0]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEMDCAMPAIGNS_H
