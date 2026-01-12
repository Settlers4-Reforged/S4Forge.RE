#ifndef CSTATEVICTORYSCREEN_H
#define CSTATEVICTORYSCREEN_H

class CStateVictoryScreen : public CGuiGameState {
public:
    // address=[0x14cb770]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x14cb7f0]
     CStateVictoryScreen(void *);

    // address=[0x14cb890]
    virtual  ~CStateVictoryScreen(void);

    // address=[0x14cb920]
    virtual bool  Perform(void);

    // address=[0x14cb9c0]
    virtual bool  OnEvent(class CEvn_Event &);

};


#endif // CSTATEVICTORYSCREEN_H
