#ifndef CSTATEAOCAMPAIGNVIKING_H
#define CSTATEAOCAMPAIGNVIKING_H

class CStateAOCampaignViking : public CGuiGameState {
public:
    // address=[0x14a14b0]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x14a1530]
     CStateAOCampaignViking(void *);

    // address=[0x14a15f0]
    virtual  ~CStateAOCampaignViking(void);

    // address=[0x14a1650]
    virtual bool  Perform(void);

    // address=[0x14a1730]
    virtual bool  OnEvent(class CEvn_Event &);

    // address=[0x14a1970]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEAOCAMPAIGNVIKING_H
