#ifndef CSTATELOBBYGAMESETTINGS_H
#define CSTATELOBBYGAMESETTINGS_H

#include "defines.h"

class CStateLobbyGameSettings : public CGuiGameState {
public:
    // address=[0x14b7f10]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14b7f90]
     CStateLobbyGameSettings(void * a2);

    // address=[0x14b84f0]
    virtual  ~CStateLobbyGameSettings(void);

    // address=[0x14b85e0]
    virtual bool  Perform(void);

    // address=[0x14b8890]
    virtual bool  OnEvent(class CEvn_Event & a2);

    // address=[0x14b9490]
    virtual void  UpdatePlayerList(bool);

    // address=[0x14b9b30]
    void  PrintChatLine(unsigned short const * String, unsigned short const * Source);

    // address=[0x14b9ca0]
    static int __cdecl CompileUserFlags(void);

    // address=[0x14ba340]
    static bool __cdecl CopyDefaultUserFlags(void);

    // address=[0x14ba670]
    static void __cdecl DrawMap(unsigned short * a1, unsigned short * a2, unsigned int a3, int a4, int a5);

    // address=[0x14babf0]
    void  PaintMap(void);

    // address=[0x14badb0]
    void  TransitionToHost(void);

protected:
    // address=[0x14bae60]
    virtual void  CreateLobbyGameInfo(class CLanLobbyGameSettings & a2, std::wstring & a3);

private:
    // address=[0x14baf80]
    void  CreateRandomGoods(void);

    // address=[0x14bb1c0]
    bool  CheckDoubleEconomyGood(int a2);

    // address=[0x14bb220]
    bool  ReadUserflagFiles(void);

    // address=[0x14bb450]
    void  ClearFlagnameList(void);

    // address=[0x14bb4a0]
    void  SetupGUI(void);

    // address=[0x14bb540]
    bool  CheckContinue(void);

    // address=[0x14bb630]
    bool  CheckReady(void);

    // address=[0x14bb870]
    void  SetBackButtonState(void);

    // address=[0x14bb8f0]
    void  UserflagChanged(int a2, int a3);

    // address=[0x14bbbc0]
    void  SetRandomRaces(void);

};


#endif // CSTATELOBBYGAMESETTINGS_H
