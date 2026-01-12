#ifndef CSTATEAOBRIEFING_H
#define CSTATEAOBRIEFING_H

class CStateAOBriefing : public CGuiGameState {
public:
    // address=[0x149d9d0]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x149da50]
     CStateAOBriefing(void *);

    // address=[0x149dea0]
    virtual  ~CStateAOBriefing(void);

    // address=[0x149df00]
    virtual bool  Perform(void);

    // address=[0x149e0f0]
    virtual bool  OnEvent(class CEvn_Event &);

    // address=[0x149e9b0]
    static void __cdecl InitBriefingTexts(int,int);

    // address=[0x149f4f0]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEAOBRIEFING_H
