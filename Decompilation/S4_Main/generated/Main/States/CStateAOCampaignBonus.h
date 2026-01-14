#ifndef CSTATEAOCAMPAIGNBONUS_H
#define CSTATEAOCAMPAIGNBONUS_H

class CStateAOCampaignBonus : public CGuiGameState {
public:
    // address=[0x149f580]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x149f600]
     CStateAOCampaignBonus(void *);

    // address=[0x149f6c0]
    virtual  ~CStateAOCampaignBonus(void);

    // address=[0x149f720]
    virtual bool  Perform(void);

    // address=[0x149f7c0]
    virtual bool  OnEvent(class CEvn_Event &);

};


#endif // CSTATEAOCAMPAIGNBONUS_H
