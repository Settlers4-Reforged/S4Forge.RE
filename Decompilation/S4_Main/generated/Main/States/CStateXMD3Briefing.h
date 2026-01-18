#ifndef CSTATEXMD3BRIEFING_H
#define CSTATEXMD3BRIEFING_H

#include "defines.h"

class CStateXMD3Briefing : public CGuiGameState {
public:
    // address=[0x14cca70]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14ccbd0]
     CStateXMD3Briefing(void *);

    // address=[0x14cd0b0]
    virtual  ~CStateXMD3Briefing(void);

    // address=[0x14cd110]
    virtual bool  Perform(void);

    // address=[0x14cd280]
    virtual bool  OnEvent(class CEvn_Event & a2);

    // address=[0x14cd770]
    static void __cdecl InitBriefingTexts(int a1, int a2);

    // address=[0x14cdf50]
    virtual bool  CanProcessInvites(void);

private:
    // address=[0x14ccaf0]
    void  PaintMap(bool a1);

};


#endif // CSTATEXMD3BRIEFING_H
