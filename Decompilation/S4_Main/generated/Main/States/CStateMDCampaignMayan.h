#ifndef CSTATEMDCAMPAIGNMAYAN_H
#define CSTATEMDCAMPAIGNMAYAN_H

#include "defines.h"

class CStateMDCampaignMayan : public CGuiGameState {
public:
    // address=[0x14c65f0]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14c6670]
     CStateMDCampaignMayan(void * a2);

    // address=[0x14c6730]
    virtual  ~CStateMDCampaignMayan(void);

    // address=[0x14c6790]
    virtual bool  Perform(void);

    // address=[0x14c6870]
    virtual bool  OnEvent(class CEvn_Event & a2);

    // address=[0x14c6ab0]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEMDCAMPAIGNMAYAN_H
