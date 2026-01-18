#ifndef CSTATELOBBYCONNECT_H
#define CSTATELOBBYCONNECT_H

#include "defines.h"

class CStateLobbyConnect : public CGuiGameState {
public:
    // address=[0x14b6970]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14b69f0]
     CStateLobbyConnect(void * a2);

    // address=[0x14b6ca0]
    virtual  ~CStateLobbyConnect(void);

    // address=[0x14b6d40]
    virtual bool  Perform(void);

    // address=[0x14b70b0]
    virtual bool  OnEvent(class CEvn_Event & a2);

private:
    // address=[0x40306d8]
    static unsigned int m_uiSearchIP;

};


#endif // CSTATELOBBYCONNECT_H
