#ifndef CSTATETUTORIAL_H
#define CSTATETUTORIAL_H

#include "defines.h"

class CStateTutorial : public CGuiGameState {
public:
    // address=[0x14cadc0]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14cae40]
     CStateTutorial(void * a2);

    // address=[0x14caed0]
    virtual  ~CStateTutorial(void);

    // address=[0x14caf50]
    virtual bool  Perform(void);

    // address=[0x14caff0]
    virtual bool  OnEvent(class CEvn_Event & a2);

};


#endif // CSTATETUTORIAL_H
