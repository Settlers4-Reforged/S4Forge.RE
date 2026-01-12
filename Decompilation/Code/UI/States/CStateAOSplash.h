#ifndef CSTATEAOSPLASH_H
#define CSTATEAOSPLASH_H

class CStateAOSplash : public CGuiGameState {
public:
    // address=[0x14a1980]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x14a1a00]
     CStateAOSplash(void *);

    // address=[0x14a1aa0]
    virtual  ~CStateAOSplash(void);

    // address=[0x14a1b30]
    virtual bool  Perform(void);

    // address=[0x14a1bd0]
    virtual bool  OnEvent(class CEvn_Event &);

};


#endif // CSTATEAOSPLASH_H
