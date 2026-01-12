#ifndef CSTATEMDCAMPAIGNVIKING_H
#define CSTATEMDCAMPAIGNVIKING_H

class CStateMDCampaignViking : public CGuiGameState {
public:
    // address=[0x14c7c10]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x14c7c90]
     CStateMDCampaignViking(void *);

    // address=[0x14c7d50]
    virtual  ~CStateMDCampaignViking(void);

    // address=[0x14c7db0]
    virtual bool  Perform(void);

    // address=[0x14c7e90]
    virtual bool  OnEvent(class CEvn_Event &);

    // address=[0x14c80d0]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEMDCAMPAIGNVIKING_H
