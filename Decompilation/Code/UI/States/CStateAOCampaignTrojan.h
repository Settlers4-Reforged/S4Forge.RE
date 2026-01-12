#ifndef CSTATEAOCAMPAIGNTROJAN_H
#define CSTATEAOCAMPAIGNTROJAN_H

class CStateAOCampaignTrojan : public CGuiGameState {
public:
    // address=[0x14a0fc0]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x14a1040]
     CStateAOCampaignTrojan(void *);

    // address=[0x14a1100]
    virtual  ~CStateAOCampaignTrojan(void);

    // address=[0x14a1160]
    virtual bool  Perform(void);

    // address=[0x14a1240]
    virtual bool  OnEvent(class CEvn_Event &);

    // address=[0x14a14a0]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEAOCAMPAIGNTROJAN_H
