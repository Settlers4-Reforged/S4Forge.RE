#ifndef CSTATEMAINMENU_H
#define CSTATEMAINMENU_H

#include "defines.h"

class CStateMainMenu : public CGuiGameState {
public:
    // address=[0x14c16a0]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14c1740]
    static bool __cdecl PreLoadGame(std::wstring a1);

    // address=[0x14c1bc0]
     CStateMainMenu(void * a2);

    // address=[0x14c22a0]
    virtual  ~CStateMainMenu(void);

    // address=[0x14c2320]
    virtual bool  Perform(void);

    // address=[0x14c2420]
    virtual bool  OnEvent(class CEvn_Event & a2);

    // address=[0x14c2e20]
    virtual bool  CanProcessInvites(void);

private:
    // address=[0x14c1720]
    void  SetupGUI(void);

};


#endif // CSTATEMAINMENU_H
