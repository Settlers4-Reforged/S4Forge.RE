#include "OnlineManager.h"

#include "Main/CGameStateHandler.h"

// Definitions for class OnlineManager

// address=[0x16160f0]
// Decompiled from void OnlineManager::Create()
void __cdecl OnlineManager::Create(void) {
    if(!OnlineManager::m_instance) {
        OnlineManager::m_instance = new OnlineManager();
    }
}

// address=[0x1616180]
// Decompiled from void OnlineManager::Destroy()
void __cdecl OnlineManager::Destroy(void) {

    if(OnlineManager::m_instance) {
        delete(OnlineManager *)OnlineManager::m_instance;
        OnlineManager::m_instance = 0;
    }
}

// address=[0x16161d0]
// Decompiled from int OnlineManager::GetInstance()
class OnlineManager *__cdecl OnlineManager::GetInstance(void) {
    return OnlineManager::m_instance;
}

// address=[0x16161e0]
// Decompiled from int __thiscall OnlineManager::Update(OnlineManager *this)
void OnlineManager::Update(void) {
    return;
}

// address=[0x1616210]
// Decompiled from int __thiscall OnlineManager::CreateSession(OnlineManager *this, struct CGameType *a2)
void OnlineManager::CreateSession(class CGameType *a2) {
    return;
}

// address=[0x1616430]
// Decompiled from int __thiscall OnlineManager::QuickMatch(OnlineManager *this, struct CGameType *a2)
void OnlineManager::QuickMatch(class CGameType *a2) {
    return;
}

// address=[0x1616500]
// Decompiled from void OnlineManager::CloseSession()
void OnlineManager::CloseSession(void) {
    return;
}

// address=[0x1616520]
// Decompiled from void __thiscall OnlineManager::SetFreeSlotCount(OnlineManager *this, int a2)
void OnlineManager::SetFreeSlotCount(int a2) {
    return;
}

// address=[0x1616540]
// Decompiled from void __thiscall OnlineManager::JoinSession(OnlineManager *this, unsigned __int64 *a2)
void OnlineManager::JoinSession(unsigned __int64 &a2) {
    return;
}

// address=[0x16165c0]
// Decompiled from void __thiscall OnlineManager::LeaveSession(OnlineManager *this)
void OnlineManager::LeaveSession(void) {
    return;
}

// address=[0x16165e0]
// Decompiled from void __thiscall OnlineManager::JoinSessionSucceeded(OnlineManager *this)
void OnlineManager::JoinSessionSucceeded(void) {
    if(OnlineManager::IsInviteFlow())
        g_pNetworkEngine->OnJoinedFromInvite();
    else
        g_pNetworkEngine->StormJoinSessionSucceeded();
}

// address=[0x1616620]
// Decompiled from void __thiscall OnlineManager::SetJoinAndDiscoveryOverride(OnlineManager *this, bool a2)
void OnlineManager::SetJoinAndDiscoveryOverride(bool a2) {
    return;
}

// address=[0x1616640]
// Decompiled from void __thiscall OnlineManager::SearchForSessions(OnlineManager *this)
void OnlineManager::SearchForSessions(void) {
    return;
}

// address=[0x1616660]
// Decompiled from int __thiscall OnlineManager::UpdateDiscoveredSessions(void *this, int a2)
void OnlineManager::UpdateDiscoveredSessions(class std::list<struct SGameInfo, class std::allocator<struct SGameInfo>> &a2) {
    return;
}

// address=[0x1616c30]
// Decompiled from void __thiscall OnlineManager::OnPeerJoined(OnlineManager *this)
void OnlineManager::OnPeerJoined(void) {
    ;
}

// address=[0x1616c40]
// Decompiled from void __thiscall OnlineManager::OnPeerGone(OnlineManager *this, unsigned int a2)
void OnlineManager::OnPeerGone(int a2) {
    return;
}

// address=[0x1616c60]
// Decompiled from void __thiscall OnlineManager::OnHost(OnlineManager *this)
void OnlineManager::OnHost(void) {
    g_pNetworkEngine->StormOnHost();
}

// address=[0x1616d00]
// Decompiled from INetworkEngine *__thiscall OnlineManager::OnSessionEnter(OnlineManager *this)
void OnlineManager::OnSessionEnter(void) {
    if(!OnlineManager::IsQuickMatchFlow(this))
        return g_pNetworkEngine->StormEnteredSession();

    bool bIsHost = false;
    g_pNetworkEngine->OnQuickMatched(false);
    return g_pNetworkEngine->StormEnteredSession();
}

// address=[0x1616d70]
// Decompiled from int __thiscall OnlineManager::OnSessionLost(OnlineManager *this)
void OnlineManager::OnSessionLost(void) {
    return;
}

// address=[0x1616db0]
// Decompiled from _BYTE *__thiscall OnlineManager::OnGameSetup(_BYTE *this)
void OnlineManager::OnGameSetup(void) {
    return;
}

// address=[0x1616dd0]
// Decompiled from void __thiscall OnlineManager::GetPlayerData(  OnlineManager *this,  int a2,  bool *a3,  int *a4,  int *a5,  int *a6,  int *a7,  int *a8,  int *a9,  struct String *a10)
void OnlineManager::GetPlayerData(int a2, bool &a3, int &a4, int &a5, int &a6, int &a7, int &a8, int &a9, class String &a10) {
    return;
}

// address=[0x1616ec0]
// Decompiled from int __thiscall OnlineManager::SendUnicastGameSetup(OnlineManager *this, int a2, void *Src, size_t Size)
void OnlineManager::SendUnicastGameSetup(int a2, void *Src, unsigned long Size) {
    return;
}

// address=[0x1617140]
// Decompiled from void __thiscall OnlineManager::SendUnicastPlayerMessage(  void *this,  int a2,  char *Str,  const struct storm::StormPlayerMessage *a4)
void OnlineManager::SendUnicastPlayerMessage(int a2, char const *Str, int a4) {
    return;
}

// address=[0x16171e0]
// Decompiled from unsigned int __thiscall OnlineManager::GetMessageCount(OnlineManager *this, unsigned int *a2)
void OnlineManager::GetMessageCount(unsigned long &a2) {
    return;
}

// address=[0x1617200]
// Decompiled from char __thiscall OnlineManager::Receive(OnlineManager *this, char *a2, void *a3, size_t *a4, _DWORD *a5)
bool OnlineManager::Receive(void *a2, int &a3, unsigned int &a4) {
    return false;
}

// address=[0x16172f0]
// Decompiled from void __thiscall OnlineManager::Send(OnlineManager *this, unsigned int a2, void *Src, size_t Size)
void OnlineManager::Send(unsigned long a2, void *Src, unsigned long Size) {
    return;
}

// address=[0x1617370]
// Decompiled from void __thiscall OnlineManager::Send(OnlineManager *this, void *Src, size_t Size)
void OnlineManager::Send(void *Src, unsigned long Size) {
    return;
}

// address=[0x16173f0]
// Decompiled from char __thiscall OnlineManager::PendingSessionLost(_BYTE *this)
bool OnlineManager::PendingSessionLost(void) const {
    return false;
}

// address=[0x1617410]
// Decompiled from _BYTE *__thiscall OnlineManager::ProcessPendingSessionLost(_BYTE *this)
void OnlineManager::ProcessPendingSessionLost(void) {
    return;
}

// address=[0x1617430]
// Decompiled from char __thiscall OnlineManager::PendingOnHost(_BYTE *this)
bool OnlineManager::PendingOnHost(void) const {
    return false;
}

// address=[0x1617450]
// Decompiled from _BYTE *__thiscall OnlineManager::ProcessPendingOnHost(_BYTE *this)
void OnlineManager::ProcessPendingOnHost(void) {
    return;
}

// address=[0x1617470]
// Decompiled from int __thiscall OnlineManager::GetLocalPeerId(OnlineManager *this)
int OnlineManager::GetLocalPeerId(void) const {
    return 0;
}

// address=[0x16174a0]
// Decompiled from bool __thiscall OnlineManager::IsLocalPeerId(OnlineManager *this, int a2)
bool OnlineManager::IsLocalPeerId(int a2) const {
    return a2 == this->GetLocalPeerId();
}

// address=[0x16174d0]
// Decompiled from bool __thiscall OnlineManager::IsLoggedIn(OnlineManager *this)
bool OnlineManager::IsLoggedIn(void) const {
    return false;
}

// address=[0x16174f0]
// Decompiled from bool __thiscall OnlineManager::IsNATReady(OnlineManager *this)
bool OnlineManager::IsNATReady(void) const {
    return false;
}

// address=[0x1617510]
// Decompiled from bool __thiscall OnlineManager::IsInSession(OnlineManager *this)
bool OnlineManager::IsInSession(void) const {
    return false;
}

// address=[0x1617550]
// Decompiled from bool __thiscall OnlineManager::IsHost(void *this)
bool OnlineManager::IsHost(void) const {
    return false;
}

// address=[0x1617590]
// Decompiled from char __thiscall OnlineManager::IsQuickMatchFlow(OnlineManager *this)
bool OnlineManager::IsQuickMatchFlow(void) const {
    return false;
}

// address=[0x16175b0]
// Decompiled from OnlineManager *__thiscall OnlineManager::SetQuickMatchFlow(OnlineManager *this, bool a2)
void OnlineManager::SetQuickMatchFlow(bool a2) {
    return;
}

// address=[0x16175d0]
// Decompiled from OnlineManager *__thiscall OnlineManager::SetPrivate(OnlineManager *this, bool a2)
void OnlineManager::SetPrivate(bool a2) {
    return;
}

// address=[0x16175f0]
// Decompiled from char __thiscall OnlineManager::IsPrivate(OnlineManager *this)
bool OnlineManager::IsPrivate(void) const {
    return false;
}

// address=[0x1617610]
// Decompiled from char __thiscall OnlineManager::IsInviteFlow(OnlineManager *this)
bool OnlineManager::IsInviteFlow(void) const {
    return false;
}

// address=[0x1617630]
// Decompiled from OnlineManager *__thiscall OnlineManager::SetInviteFlow(OnlineManager *this, bool a2)
void OnlineManager::SetInviteFlow(bool a2) {
    return;
}

// address=[0x1617650]
// Decompiled from OnlineManager *__thiscall OnlineManager::OnOnlineError(OnlineManager *this)
void OnlineManager::OnOnlineError(void) {
    return;
}

// address=[0x1617670]
// Decompiled from char __thiscall OnlineManager::GetAndClearOnlineError(OnlineManager *this)
bool OnlineManager::GetAndClearOnlineError(void) {
    return false;
}

// address=[0x16176a0]
// Decompiled from int __thiscall OnlineManager::OnAcceptInvite(OnlineManager *this)
void OnlineManager::OnAcceptInvite(void) {
    if(CGameStateHandler::CanProcessInvites())
        return CGameStateHandler::Switch(CStateMainMenu::DynamicCreateFunc, 18);
}

// address=[0x161d910]
// Decompiled from int __thiscall OnlineManager::~OnlineManager(OnlineManager *this)
OnlineManager::~OnlineManager(void) = default;

// address=[0x16176d0]
// Decompiled from void __thiscall OnlineManager::UpdatePlayerData(  OnlineManager *this,  int a2,  bool a3,  int a4,  int a5,  int a6,  int a7,  int a8,  char *Str,  char *a10)
void OnlineManager::UpdatePlayerData(int a2, bool a3, int a4, int a5, int a6, int a7, int a8, char const *Str, char const *a10) {
    return;
}

// address=[0x1617790]
// Decompiled from OnlineManager *__thiscall OnlineManager::OnlineManager(OnlineManager *this)
OnlineManager::OnlineManager(void) {
    return;
}

// address=[0x462b9a0]
// [Decompilation failed for static class OnlineManager * OnlineManager::m_instance]
