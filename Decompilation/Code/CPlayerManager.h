#ifndef CPLAYERMANAGER_H
#define CPLAYERMANAGER_H

class CPlayerManager : public IS4ChunkObject {
public:
    // address=[0x130f2c0]
    static int __cdecl Race(int);

    // address=[0x130f490]
    static bool __cdecl ValidUsedPlayerId(int);

    // address=[0x1314080]
    static int __cdecl LastPlayerId(void);

    // address=[0x13736c0]
    static int __cdecl GetLocalPlayerId(void);

    // address=[0x13736d0]
    static class CPlayerInfo const & __cdecl PlayerInfo(int);

    // address=[0x13919d0]
    static int __cdecl Color(int);

    // address=[0x1391a30]
    static int __cdecl NumberOfPlayers(void);

    // address=[0x14477c0]
    static class CPlayerGameData & __cdecl PlayerGameData(int);

    // address=[0x144fed0]
    static std::wstring __cdecl Name(int);

    // address=[0x1460650]
    static bool __cdecl IsAlive(int);

    // address=[0x147a320]
    static bool __cdecl IsAI(int);

    // address=[0x1486e90]
    static int __cdecl GetPlayerControl(int);

    // address=[0x14973a0]
    static void __cdecl Init(void);

    // address=[0x1497420]
    static int __cdecl AddPlayer(int,int,int,int,int,int,std::wstring,int);

    // address=[0x14976e0]
    static bool __cdecl Lock(void);

    // address=[0x1497790]
    static void __cdecl Done(void);

    // address=[0x14977b0]
    virtual void  Load(class IS4Chunk &);

    // address=[0x1497870]
    virtual void  Save(class IS4Chunk &);

    // address=[0x1497920]
    static void __cdecl PrintStats(void);

    // address=[0x1497a60]
    static signed char __cdecl GetLocalSlot(void);

    // address=[0x1498150]
     CPlayerManager(void);

    // address=[0x14aae50]
    static void __cdecl PlayerDied(int);

    // address=[0x14b4800]
    static int __cdecl PeerId(int);

    // address=[0x14b4930]
    static void __cdecl SetLocalPlayerId(int);

    // address=[0x14b4980]
    static void __cdecl SetPlayerControl(int,int);

    // address=[0x15c4d00]
    static int __cdecl IP(int);

private:
    // address=[0x402bd70]
    static int m_iInitialized;

    // address=[0x402bd74]
    static int m_iLocked;

    // address=[0x402bd78]
    static long m_lLocalIP;

    // address=[0x402bd7c]
    static int m_iNumberOfPlayer;

    // address=[0x402bd80]
    static int m_iLocalPlayer;

    // address=[0x402bdc8]
    static class CPlayerInfo * m_cPlayerInfos;

    // address=[0x402c008]
    static class CPlayerGameData * m_cPlayerGameData;

};


#endif // CPLAYERMANAGER_H
