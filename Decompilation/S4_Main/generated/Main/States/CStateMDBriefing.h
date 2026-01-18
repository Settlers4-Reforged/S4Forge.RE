#ifndef CSTATEMDBRIEFING_H
#define CSTATEMDBRIEFING_H

#include "defines.h"

class CStateMDBriefing : public CGuiGameState {
public:
    // address=[0x14c4dc0]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14c4e40]
     CStateMDBriefing(void * a2);

    // address=[0x14c5090]
    virtual  ~CStateMDBriefing(void);

    // address=[0x14c50f0]
    virtual bool  Perform(void);

    // address=[0x14c52d0]
    virtual bool  OnEvent(class CEvn_Event & a2);

    // address=[0x14c5b70]
    static void __cdecl InitBriefingTexts(int a1, int a2);

    // address=[0x14c65e0]
    virtual bool  CanProcessInvites(void);

};


#endif // CSTATEMDBRIEFING_H
