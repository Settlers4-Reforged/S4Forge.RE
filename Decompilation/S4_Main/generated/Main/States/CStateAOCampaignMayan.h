#ifndef CSTATEAOCAMPAIGNMAYAN_H
#define CSTATEAOCAMPAIGNMAYAN_H

class CStateAOCampaignMayan : public CGuiGameState {
public:
    // address=[0x149f9f0]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x149fa70]
     CStateAOCampaignMayan(void *);

    // address=[0x149fb30]
    virtual  ~CStateAOCampaignMayan(void);

    // address=[0x149fb90]
    virtual bool  Perform(void);

    // address=[0x149fc70]
    virtual bool  OnEvent(class CEvn_Event &);

    // address=[0x149feb0]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEAOCAMPAIGNMAYAN_H
