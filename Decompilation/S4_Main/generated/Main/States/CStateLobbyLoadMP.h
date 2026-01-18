#ifndef CSTATELOBBYLOADMP_H
#define CSTATELOBBYLOADMP_H

#include "defines.h"

class CStateLobbyLoadMP : public CStateLobbyGameSettings {
public:
    // address=[0x14bce60]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14bcee0]
     CStateLobbyLoadMP(void * a2);

    // address=[0x14bcfa0]
    virtual  ~CStateLobbyLoadMP(void);

    // address=[0x14bcfc0]
    virtual bool  Perform(void);

    // address=[0x14bd0b0]
    virtual bool  OnEvent(class CEvn_Event & a2);

protected:
    // address=[0x14bd0d0]
    virtual void  CreateLobbyGameInfo(class CLanLobbyGameSettings & a2, std::wstring & a3);

private:
    // address=[0x14bd200]
    void  UpdateGameTypeData(void);

};


#endif // CSTATELOBBYLOADMP_H
