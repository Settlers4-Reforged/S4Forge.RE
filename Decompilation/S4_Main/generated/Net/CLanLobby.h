#ifndef CLANLOBBY_H
#define CLANLOBBY_H

#include "defines.h"

class CLanLobby {
public:
    // address=[0x15c9580]
    static bool __cdecl ConnectPlayer(struct SConnectGameInfoFromClient & String, int a2);

    // address=[0x15c9860]
    static bool __cdecl DisconnectPlayerPeerId(unsigned int a1, int a2);

    // address=[0x15c9930]
    static void __cdecl RedrawPlayerList(void);

    // address=[0x15c99a0]
    static void __cdecl ChangeData(struct SLobbyChange * Src);

    // address=[0x15c9a00]
    static void __cdecl ChangeSlots(struct SLobbyChange * Src);

    // address=[0x15c9a60]
    static void __cdecl Communicate(int a1, void * a2);

private:
    // address=[0x15c4dc0]
    static void __cdecl SetGameHost(class CGameHost * a1);

    // address=[0x15c90d0]
    static bool __cdecl StartWaitGameDlg(bool);

    // address=[0x15c90e0]
    static bool __cdecl EndWaitGameDlg(void);

    // address=[0x15c90f0]
    static void __cdecl RedrawGameList(void);

    // address=[0x15c94f0]
    static void __cdecl RedrawMap(void);

    // address=[0x15c9530]
    static void __cdecl PrintChatLine(unsigned short const * String, unsigned short const * Source);

    // address=[0x415b8f8]
    static class CGameHost * m_pGameHost;

    // address=[0x415b8fc]
    static bool m_bHost;

};


#endif // CLANLOBBY_H
