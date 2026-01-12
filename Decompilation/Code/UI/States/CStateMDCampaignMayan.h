#ifndef CSTATEMDCAMPAIGNMAYAN_H
#define CSTATEMDCAMPAIGNMAYAN_H

class CStateMDCampaignMayan : public CGuiGameState {
public:
    // address=[0x14c65f0]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x14c6670]
     CStateMDCampaignMayan(void *);

    // address=[0x14c6730]
    virtual  ~CStateMDCampaignMayan(void);

    // address=[0x14c6790]
    virtual bool  Perform(void);

    // address=[0x14c6870]
    virtual bool  OnEvent(class CEvn_Event &);

    // address=[0x14c6ab0]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEMDCAMPAIGNMAYAN_H
