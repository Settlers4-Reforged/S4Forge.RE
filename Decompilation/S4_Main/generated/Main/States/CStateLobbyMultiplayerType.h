#ifndef CSTATELOBBYMULTIPLAYERTYPE_H
#define CSTATELOBBYMULTIPLAYERTYPE_H

#include "defines.h"

class CStateLobbyMultiplayerType : public CGuiGameState {
public:
    // address=[0x14c0800]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14c0a50]
     CStateLobbyMultiplayerType(void * a2);

    // address=[0x14c0ac0]
    virtual  ~CStateLobbyMultiplayerType(void);

    // address=[0x14c0b40]
    virtual bool  Perform(void);

    // address=[0x14c0be0]
    virtual bool  OnEvent(class CEvn_Event & a2);

private:
    // address=[0x14c0880]
    bool  LaunchWebLobby(std::string a2);

};


#endif // CSTATELOBBYMULTIPLAYERTYPE_H
