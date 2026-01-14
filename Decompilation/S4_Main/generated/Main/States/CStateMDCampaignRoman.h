#ifndef CSTATEMDCAMPAIGNROMAN_H
#define CSTATEMDCAMPAIGNROMAN_H

class CStateMDCampaignRoman : public CGuiGameState {
public:
    // address=[0x14c6ac0]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x14c6b40]
     CStateMDCampaignRoman(void *);

    // address=[0x14c6c00]
    virtual  ~CStateMDCampaignRoman(void);

    // address=[0x14c6c60]
    virtual bool  Perform(void);

    // address=[0x14c6d40]
    virtual bool  OnEvent(class CEvn_Event &);

    // address=[0x14c6f80]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEMDCAMPAIGNROMAN_H
