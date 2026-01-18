#ifndef ONLINEMANAGER_H
#define ONLINEMANAGER_H

#include "defines.h"

class OnlineManager {
public:
    // address=[0x16160f0]
    static void __cdecl Create(void);

    // address=[0x1616180]
    static void __cdecl Destroy(void);

    // address=[0x16161d0]
    static class OnlineManager * __cdecl GetInstance(void);

    // address=[0x16161e0]
    void  Update(void);

    // address=[0x1616210]
    void  CreateSession(class CGameType * a2);

    // address=[0x1616430]
    void  QuickMatch(class CGameType * a2);

    // address=[0x1616500]
    void  CloseSession(void);

    // address=[0x1616520]
    void  SetFreeSlotCount(int a2);

    // address=[0x1616540]
    void  JoinSession(unsigned __int64 &);

    // address=[0x16165c0]
    void  LeaveSession(void);

    // address=[0x16165e0]
    void  JoinSessionSucceeded(void);

    // address=[0x1616620]
    void  SetJoinAndDiscoveryOverride(bool);

    // address=[0x1616640]
    void  SearchForSessions(void);

    // address=[0x1616660]
    void  UpdateDiscoveredSessions(class std::list<struct SGameInfo,class std::allocator<struct SGameInfo> > & a2);

    // address=[0x1616c30]
    void  OnPeerJoined(void);

    // address=[0x1616c40]
    void  OnPeerGone(int a2);

    // address=[0x1616c60]
    void  OnHost(void);

    // address=[0x1616d00]
    void  OnSessionEnter(void);

    // address=[0x1616d70]
    void  OnSessionLost(void);

    // address=[0x1616db0]
    void  OnGameSetup(void);

    // address=[0x1616dd0]
    void  GetPlayerData(int a2, bool & a3, int & a4, int & a5, int & a6, int & a7, int & a8, int & a9, class String & a10);

    // address=[0x1616ec0]
    void  SendUnicastGameSetup(int a2, void * Src, unsigned long Size);

    // address=[0x1617140]
    void  SendUnicastPlayerMessage(int a2, char const * Str, int a4);

    // address=[0x16171e0]
    void  GetMessageCount(unsigned long & a2);

    // address=[0x1617200]
    bool  Receive(void * a2, int & a3, unsigned int & a4);

    // address=[0x16172f0]
    void  Send(unsigned long a2, void * Src, unsigned long Size);

    // address=[0x1617370]
    void  Send(void * Src, unsigned long Size);

    // address=[0x16173f0]
    bool  PendingSessionLost(void)const;

    // address=[0x1617410]
    void  ProcessPendingSessionLost(void);

    // address=[0x1617430]
    bool  PendingOnHost(void)const;

    // address=[0x1617450]
    void  ProcessPendingOnHost(void);

    // address=[0x1617470]
    int  GetLocalPeerId(void)const;

    // address=[0x16174a0]
    bool  IsLocalPeerId(int a2)const;

    // address=[0x16174d0]
    bool  IsLoggedIn(void)const;

    // address=[0x16174f0]
    bool  IsNATReady(void)const;

    // address=[0x1617510]
    bool  IsInSession(void)const;

    // address=[0x1617550]
    bool  IsHost(void)const;

    // address=[0x1617590]
    bool  IsQuickMatchFlow(void)const;

    // address=[0x16175b0]
    void  SetQuickMatchFlow(bool a2);

    // address=[0x16175d0]
    void  SetPrivate(bool a2);

    // address=[0x16175f0]
    bool  IsPrivate(void)const;

    // address=[0x1617610]
    bool  IsInviteFlow(void)const;

    // address=[0x1617630]
    void  SetInviteFlow(bool a2);

    // address=[0x1617650]
    void  OnOnlineError(void);

    // address=[0x1617670]
    bool  GetAndClearOnlineError(void);

    // address=[0x16176a0]
    void  OnAcceptInvite(void);

    // address=[0x161d910]
     ~OnlineManager(void);

private:
    // address=[0x16176d0]
    void  UpdatePlayerData(int a2, bool a3, int a4, int a5, int a6, int a7, int a8, char const * Str, char const * a10);

    // address=[0x1617790]
     OnlineManager(void);

    // address=[0x462b9a0]
    static class OnlineManager * m_instance;

};


#endif // ONLINEMANAGER_H
