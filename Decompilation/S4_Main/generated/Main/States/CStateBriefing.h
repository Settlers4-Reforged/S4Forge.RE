#ifndef CSTATEBRIEFING_H
#define CSTATEBRIEFING_H

#include "defines.h"

class CStateBriefing : public CGuiGameState {
public:
    // address=[0x14a1d50]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14a1eb0]
     CStateBriefing(void *);

    // address=[0x14a2240]
    virtual  ~CStateBriefing(void);

    // address=[0x14a22c0]
    virtual bool  Perform(void);

    // address=[0x14a2390]
    virtual bool  OnEvent(class CEvn_Event & a2);

    // address=[0x14a2c20]
    static void __cdecl InitBriefingTexts(int a1, int a2);

private:
    // address=[0x14a1dd0]
    void  PaintMap(bool a2);

};


#endif // CSTATEBRIEFING_H
