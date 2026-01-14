#ifndef CLANLOBBY_H
#define CLANLOBBY_H

class CLanLobby {
public:
    // address=[0x15c9580]
    static bool __cdecl ConnectPlayer(struct SConnectGameInfoFromClient &,int);

    // address=[0x15c9860]
    static bool __cdecl DisconnectPlayerPeerId(unsigned int,int);

    // address=[0x15c9930]
    static void __cdecl RedrawPlayerList(void);

    // address=[0x15c99a0]
    static void __cdecl ChangeData(struct SLobbyChange *);

    // address=[0x15c9a00]
    static void __cdecl ChangeSlots(struct SLobbyChange *);

    // address=[0x15c9a60]
    static void __cdecl Communicate(int,void *);

private:
    // address=[0x15c4dc0]
    static void __cdecl SetGameHost(class CGameHost *);

    // address=[0x15c90d0]
    static bool __cdecl StartWaitGameDlg(bool);

    // address=[0x15c90e0]
    static bool __cdecl EndWaitGameDlg(void);

    // address=[0x15c90f0]
    static void __cdecl RedrawGameList(void);

    // address=[0x15c94f0]
    static void __cdecl RedrawMap(void);

    // address=[0x15c9530]
    static void __cdecl PrintChatLine(unsigned short const *,unsigned short const *);

    // address=[0x415b8f8]
    static class CGameHost * m_pGameHost;

    // address=[0x415b8fc]
    static bool m_bHost;

};


#endif // CLANLOBBY_H
