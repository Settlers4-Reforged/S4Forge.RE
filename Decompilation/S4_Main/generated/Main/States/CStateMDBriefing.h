#ifndef CSTATEMDBRIEFING_H
#define CSTATEMDBRIEFING_H

class CStateMDBriefing : public CGuiGameState {
public:
    // address=[0x14c4dc0]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x14c4e40]
     CStateMDBriefing(void *);

    // address=[0x14c5090]
    virtual  ~CStateMDBriefing(void);

    // address=[0x14c50f0]
    virtual bool  Perform(void);

    // address=[0x14c52d0]
    virtual bool  OnEvent(class CEvn_Event &);

    // address=[0x14c5b70]
    static void __cdecl InitBriefingTexts(int,int);

    // address=[0x14c65e0]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEMDBRIEFING_H
