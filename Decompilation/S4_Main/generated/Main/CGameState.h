#ifndef CGAMESTATE_H
#define CGAMESTATE_H

#include "defines.h"

class CGameState {
public:
    // address=[0x13728e0]
    virtual bool  OnEvent(class CEvn_Event & a1);

    // address=[0x149d860]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x149d900]
     CGameState(void * a2);

    // address=[0x149d920]
    virtual  ~CGameState(void);

    // address=[0x149d980]
    virtual bool  CanProcessInvites(void);

    // address=[0x149d990]
    virtual bool  Perform(void);

    // address=[0x149f3c0]
     CGameState(void);

};


#endif // CGAMESTATE_H
