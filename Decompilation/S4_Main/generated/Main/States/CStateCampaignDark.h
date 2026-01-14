#ifndef CSTATECAMPAIGNDARK_H
#define CSTATECAMPAIGNDARK_H

class CStateCampaignDark : public CGuiGameState {
public:
    // address=[0x14a3ac0]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x14a3b40]
     CStateCampaignDark(void *);

    // address=[0x14a3be0]
    virtual  ~CStateCampaignDark(void);

    // address=[0x14a3c60]
    virtual bool  Perform(void);

    // address=[0x14a3d00]
    virtual bool  OnEvent(class CEvn_Event &);

};


#endif // CSTATECAMPAIGNDARK_H
