#ifndef CSTATEMD2BRIEFING_H
#define CSTATEMD2BRIEFING_H

class CStateMD2Briefing : public CGuiGameState {
public:
    // address=[0x14c30d0]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x14c3150]
     CStateMD2Briefing(void *);

    // address=[0x14c3320]
    virtual  ~CStateMD2Briefing(void);

    // address=[0x14c3380]
    virtual bool  Perform(void);

    // address=[0x14c3560]
    virtual bool  OnEvent(class CEvn_Event &);

    // address=[0x14c3e10]
    static void __cdecl InitBriefingTexts(int,int);

    // address=[0x14c4600]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEMD2BRIEFING_H
