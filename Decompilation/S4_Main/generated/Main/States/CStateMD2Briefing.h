#ifndef CSTATEMD2BRIEFING_H
#define CSTATEMD2BRIEFING_H

#include "defines.h"

class CStateMD2Briefing : public CGuiGameState {
public:
    // address=[0x14c30d0]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14c3150]
     CStateMD2Briefing(void *);

    // address=[0x14c3320]
    virtual  ~CStateMD2Briefing(void);

    // address=[0x14c3380]
    virtual bool  Perform(void);

    // address=[0x14c3560]
    virtual bool  OnEvent(class CEvn_Event & a2);

    // address=[0x14c3e10]
    static void __cdecl InitBriefingTexts(int a1, int a2);

    // address=[0x14c4600]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEMD2BRIEFING_H
