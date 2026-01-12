#ifndef CSTATEMD2CAMPAIGNS_H
#define CSTATEMD2CAMPAIGNS_H

class CStateMD2Campaigns : public CGuiGameState {
public:
    // address=[0x14c4610]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x14c4690]
     CStateMD2Campaigns(void *);

    // address=[0x14c47d0]
    virtual  ~CStateMD2Campaigns(void);

    // address=[0x14c4830]
    virtual bool  Perform(void);

    // address=[0x14c4960]
    virtual bool  OnEvent(class CEvn_Event &);

    // address=[0x14c4db0]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEMD2CAMPAIGNS_H
