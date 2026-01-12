#ifndef CSTATECAMPAIGN3X3_H
#define CSTATECAMPAIGN3X3_H

class CStateCampaign3X3 : public CGuiGameState {
public:
    // address=[0x14a3560]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x14a35e0]
     CStateCampaign3X3(void *);

    // address=[0x14a36d0]
    virtual  ~CStateCampaign3X3(void);

    // address=[0x14a3750]
    virtual bool  Perform(void);

    // address=[0x14a37f0]
    virtual bool  OnEvent(class CEvn_Event &);

};


#endif // CSTATECAMPAIGN3X3_H
