#include "OnlineManager.h"

// Definitions for class OnlineManager

// address=[0x16160f0]
// Decompiled from void OnlineManager::Create()
static void __cdecl OnlineManager::Create(void) {
  
  int v0; // [esp+8h] [ebp-14h]

  if ( !OnlineManager::m_instance )
  {
    if ( operator new(0x58u) )
      v0 = OnlineManager::OnlineManager();
    else
      v0 = 0;
    OnlineManager::m_instance = v0;
  }
}


// address=[0x1616180]
// Decompiled from void OnlineManager::Destroy()
static void __cdecl OnlineManager::Destroy(void) {
  
  if ( OnlineManager::m_instance )
  {
    OnlineManager::`scalar deleting destructor'((OnlineManager *)OnlineManager::m_instance, 1u);
    OnlineManager::m_instance = 0;
  }
}


// address=[0x16161d0]
// Decompiled from int OnlineManager::GetInstance()
static class OnlineManager * __cdecl OnlineManager::GetInstance(void) {
  
  return OnlineManager::m_instance;
}


// address=[0x16161e0]
// Decompiled from int __thiscall OnlineManager::Update(OnlineManager *this)
void  OnlineManager::Update(void) {
  
  bool IsNATReady; // al
  int Instance; // [esp+4h] [ebp-4h]

  Instance = UPlay::UPlayManager::GetInstance();
  IsNATReady = OnlineManager::IsNATReady(this);
  return (*(int (__thiscall **)(int, bool))(*(_DWORD *)Instance + 56))(Instance, IsNATReady);
}


// address=[0x1616210]
// Decompiled from int __thiscall OnlineManager::CreateSession(OnlineManager *this, struct CGameType *a2)
void  OnlineManager::CreateSession(class CGameType *) {
  
  wchar_t *v2; // eax
  int v3; // eax
  wchar_t *v4; // eax
  _DWORD *v5; // eax
  char v7; // [esp-68h] [ebp-124h]
  BOOL IsPrivate; // [esp-64h] [ebp-120h]
  int v9; // [esp-60h] [ebp-11Ch] BYREF
  int v10; // [esp-5Ch] [ebp-118h]
  int v11; // [esp-58h] [ebp-114h]
  int v12; // [esp-54h] [ebp-110h]
  int v13; // [esp-50h] [ebp-10Ch]
  int v14; // [esp-4Ch] [ebp-108h]
  int v15; // [esp-48h] [ebp-104h]
  int v16; // [esp-44h] [ebp-100h] BYREF
  int v17; // [esp-40h] [ebp-FCh]
  int v18; // [esp-3Ch] [ebp-F8h]
  int v19; // [esp-38h] [ebp-F4h]
  int v20; // [esp-34h] [ebp-F0h]
  int v21; // [esp-30h] [ebp-ECh]
  int v22; // [esp-2Ch] [ebp-E8h]
  int v23; // [esp-28h] [ebp-E4h]
  int v24; // [esp-24h] [ebp-E0h]
  int v25; // [esp-20h] [ebp-DCh] BYREF
  int v26; // [esp-1Ch] [ebp-D8h]
  int v27; // [esp-18h] [ebp-D4h]
  int v28; // [esp-14h] [ebp-D0h]
  int v29; // [esp-10h] [ebp-CCh]
  int v30; // [esp-Ch] [ebp-C8h]
  int v31; // [esp-8h] [ebp-C4h]
  int MPSavegameID; // [esp-4h] [ebp-C0h]
  int v33; // [esp+0h] [ebp-BCh]
  int v34; // [esp+4h] [ebp-B8h]
  int v35; // [esp+Ch] [ebp-B0h]
  int *v36; // [esp+10h] [ebp-ACh]
  int v37; // [esp+14h] [ebp-A8h]
  int *v38; // [esp+18h] [ebp-A4h]
  int v39; // [esp+1Ch] [ebp-A0h]
  int v40; // [esp+20h] [ebp-9Ch]
  int v41; // [esp+24h] [ebp-98h]
  int v42; // [esp+28h] [ebp-94h]
  int v43; // [esp+2Ch] [ebp-90h]
  int v44; // [esp+30h] [ebp-8Ch]
  int v45; // [esp+34h] [ebp-88h]
  OnlineManager *v46; // [esp+38h] [ebp-84h]
  int v47[7]; // [esp+3Ch] [ebp-80h] BYREF
  int v48[7]; // [esp+58h] [ebp-64h] BYREF
  _BYTE v49[28]; // [esp+90h] [ebp-2Ch] BYREF
  int v50; // [esp+B8h] [ebp-4h]

  v46 = this;
  std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>((wchar_t *)&word_3821DEC);
  v50 = 0;
  if ( *((_BYTE *)a2 + 696) )
  {
    v2 = (wchar_t *)std::wstring::c_str((struct CGameType *)((char *)a2 + 704));
    v45 = std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(v2);
    std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::operator=(v45);
    std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::~basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(
      v33,
      v34);
    v44 = std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::rfind(
            (wchar_t *)L"\\",
            std::basic_string_wchar_t_std::char_traits_wchar_t__storm::Allocator_wchar_t_1092620295___::npos);
    v43 = std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::substr(
            (int)v48,
            v44 + 1,
            std::basic_string_wchar_t_std::char_traits_wchar_t__storm::Allocator_wchar_t_1092620295___::npos);
    std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::operator=(v43);
    std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::~basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(
      v33,
      v34);
    v3 = std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::length(v49);
    v42 = std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::substr(
            (int)v47,
            0,
            v3 - 4);
    std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::operator=(v42);
    std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::~basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(
      v33,
      v34);
  }
  MPSavegameID = CGameType::GetMPSavegameID(a2);
  v38 = &v25;
  v41 = std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(v49);
  v37 = v41;
  LOBYTE(v50) = 1;
  v24 = *((_DWORD *)a2 + 175);
  v23 = *((_DWORD *)a2 + 28);
  v4 = (wchar_t *)std::wstring::c_str((struct CGameType *)((char *)a2 + 28));
  v36 = &v16;
  v40 = std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(v4);
  v35 = v40;
  LOBYTE(v50) = 2;
  v5 = std::wstring::c_str(a2);
  v39 = storm::CStringConvertToUtf8(
          &v9,
          (int)v5,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          MPSavegameID,
          v33,
          v34,
          (int)&v9,
          v35,
          (int)v36,
          v37,
          (int)v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          (int)v46);
  v34 = v39;
  LOBYTE(v50) = 3;
  IsPrivate = OnlineManager::IsPrivate(v46);
  v7 = *((_BYTE *)v46 + 80);
  StormManager::GetInstance();
  LOBYTE(v50) = 0;
  StormManager::CreateSession(
    v7,
    IsPrivate,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    MPSavegameID);
  v50 = -1;
  return std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::~basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(
           v33,
           v34);
}


// address=[0x1616430]
// Decompiled from int __thiscall OnlineManager::QuickMatch(OnlineManager *this, struct CGameType *a2)
void  OnlineManager::QuickMatch(class CGameType *) {
  
  wchar_t *v2; // eax
  _DWORD *v3; // eax
  int v5; // [esp-Ch] [ebp-6Ch]
  int v6; // [esp-8h] [ebp-68h]
  int v7; // [esp-4h] [ebp-64h]
  void *v8; // [esp+8h] [ebp-58h]
  _BYTE v9[28]; // [esp+34h] [ebp-2Ch] BYREF
  int v10; // [esp+5Ch] [ebp-4h]

  v7 = *((_DWORD *)a2 + 175);
  v6 = *((_DWORD *)a2 + 28);
  v2 = (wchar_t *)std::wstring::c_str((struct CGameType *)((char *)a2 + 28));
  v10 = 0;
  v5 = std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(v2);
  v3 = std::wstring::c_str(a2);
  v8 = storm::CStringConvertToUtf8(v9, (int)v3);
  LOBYTE(v10) = 1;
  StormManager::GetInstance();
  StormManager::QuickMatch(v8, v5, v6, v7);
  LOBYTE(v10) = 0;
  std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::~basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>(v9);
  v10 = -1;
  return std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::~basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>();
}


// address=[0x1616500]
// Decompiled from void OnlineManager::CloseSession()
void  OnlineManager::CloseSession(void) {
  
  StormManager *Instance; // eax

  Instance = (StormManager *)StormManager::GetInstance();
  StormManager::CloseSession(Instance);
}


// address=[0x1616520]
// Decompiled from void __thiscall OnlineManager::SetFreeSlotCount(OnlineManager *this, int a2)
void  OnlineManager::SetFreeSlotCount(int) {
  
  StormManager *Instance; // eax

  Instance = (StormManager *)StormManager::GetInstance();
  StormManager::SetFreeSlotCount(Instance, a2);
}


// address=[0x1616540]
// Decompiled from void __thiscall OnlineManager::JoinSession(OnlineManager *this, unsigned __int64 *a2)
void  OnlineManager::JoinSession(unsigned __int64 &) {
  
  StormManager *Instance; // eax
  struct GUID v3; // [esp+4h] [ebp-20h] BYREF
  OnlineManager *v4; // [esp+14h] [ebp-10h]
  int v5; // [esp+20h] [ebp-4h]

  v4 = this;
  storm::GUID::GUID((storm::GUID *)&v3, *a2);
  v5 = 0;
  Instance = (StormManager *)StormManager::GetInstance();
  StormManager::JoinSession(Instance, &v3);
  v5 = -1;
  storm::GUID::~GUID((storm::GUID *)&v3);
}


// address=[0x16165c0]
// Decompiled from void __thiscall OnlineManager::LeaveSession(OnlineManager *this)
void  OnlineManager::LeaveSession(void) {
  
  StormManager *Instance; // eax

  Instance = (StormManager *)StormManager::GetInstance();
  StormManager::LeaveSession(Instance);
}


// address=[0x16165e0]
// Decompiled from void __thiscall OnlineManager::JoinSessionSucceeded(OnlineManager *this)
void  OnlineManager::JoinSessionSucceeded(void) {
  
  if ( (unsigned __int8)OnlineManager::IsInviteFlow(this) )
    INetworkEngine::OnJoinedFromInvite((CGameHost **)g_pNetworkEngine);
  else
    INetworkEngine::StormJoinSessionSucceeded((INetworkEngine *)g_pNetworkEngine);
}


// address=[0x1616620]
// Decompiled from void __thiscall OnlineManager::SetJoinAndDiscoveryOverride(OnlineManager *this, bool a2)
void  OnlineManager::SetJoinAndDiscoveryOverride(bool) {
  
  StormManager *Instance; // eax

  Instance = (StormManager *)StormManager::GetInstance();
  StormManager::SetJoinAndDiscoveryOverride(Instance, a2);
}


// address=[0x1616640]
// Decompiled from void __thiscall OnlineManager::SearchForSessions(OnlineManager *this)
void  OnlineManager::SearchForSessions(void) {
  
  StormManager *Instance; // eax

  Instance = (StormManager *)StormManager::GetInstance();
  StormManager::SearchForSessions(Instance);
}


// address=[0x1616660]
// Decompiled from int __thiscall OnlineManager::UpdateDiscoveredSessions(void *this, int a2)
void  OnlineManager::UpdateDiscoveredSessions(class std::list<struct SGameInfo,class std::allocator<struct SGameInfo> > &) {
  
  int v2; // eax
  int v3; // eax
  const wchar_t *v4; // eax
  const wchar_t *v5; // eax
  storm::GUID *SessionGUID; // eax
  int v8; // [esp-4h] [ebp-538h]
  int v9; // [esp+0h] [ebp-534h]
  int v10; // [esp+0h] [ebp-534h]
  int v11; // [esp+0h] [ebp-534h]
  int v12; // [esp+0h] [ebp-534h]
  int v13; // [esp+0h] [ebp-534h]
  int v14; // [esp+0h] [ebp-534h]
  int v15; // [esp+0h] [ebp-534h]
  int v16; // [esp+0h] [ebp-534h]
  int v17; // [esp+0h] [ebp-534h]
  int v18; // [esp+0h] [ebp-534h]
  int v19; // [esp+0h] [ebp-534h]
  int v20[4]; // [esp+4h] [ebp-530h] BYREF
  _DWORD v21[3]; // [esp+14h] [ebp-520h] BYREF
  void *v22; // [esp+20h] [ebp-514h]
  _DWORD v23[3]; // [esp+24h] [ebp-510h] BYREF
  int v24; // [esp+30h] [ebp-504h] BYREF
  int v25; // [esp+34h] [ebp-500h]
  BOOL v26; // [esp+38h] [ebp-4FCh]
  int v27; // [esp+3Ch] [ebp-4F8h] BYREF
  int *v28; // [esp+40h] [ebp-4F4h]
  CDaoIndexFieldInfo *v29; // [esp+44h] [ebp-4F0h]
  _DWORD v30[4]; // [esp+48h] [ebp-4ECh] BYREF
  _DWORD v31[16]; // [esp+58h] [ebp-4DCh] BYREF
  _DWORD Destination[133]; // [esp+98h] [ebp-49Ch] BYREF
  char v33; // [esp+2ACh] [ebp-288h]
  int SaveId; // [esp+2B4h] [ebp-280h]
  bool v35; // [esp+2B8h] [ebp-27Ch]
  int TickCount; // [esp+2BCh] [ebp-278h]
  char v37; // [esp+2C1h] [ebp-273h]
  unsigned __int64 v38; // [esp+2C8h] [ebp-26Ch] BYREF
  wchar_t v39[256]; // [esp+2D0h] [ebp-264h] BYREF
  _BYTE v40[28]; // [esp+4D0h] [ebp-64h] BYREF
  _BYTE v41[28]; // [esp+4ECh] [ebp-48h] BYREF
  _BYTE v42[28]; // [esp+508h] [ebp-2Ch] BYREF
  int v43; // [esp+530h] [ebp-4h]

  v22 = this;
  StormManager::GetInstance();
  StormManager::GetDiscoveredSessions(v20);
  v43 = 0;
  std::list<SGameInfo>::clear(v9, v20[0]);
  v28 = v20;
  std::vector<storm::ISimpleMatchmakingStrategy::SessionInfo *,storm::Allocator<storm::ISimpleMatchmakingStrategy::SessionInfo *,1092677632>>::begin(v23);
  LOBYTE(v43) = 1;
  std::vector<storm::ISimpleMatchmakingStrategy::SessionInfo *,storm::Allocator<storm::ISimpleMatchmakingStrategy::SessionInfo *,1092677632>>::end(v21);
  LOBYTE(v43) = 2;
  while ( (unsigned __int8)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<storm::ISimpleMatchmakingStrategy::SessionInfo *>>>::operator!=((std::_Iterator_base12 *)v21) )
  {
    v25 = *(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<storm::ISimpleMatchmakingStrategy::SessionInfo *>>>::operator*(v23);
    v29 = (CDaoIndexFieldInfo *)j____RTDynamicCast(
                                  *(void ***)(v25 + 16),
                                  0,
                                  &storm::echo::SessionDescriptor__RTTI_Type_Descriptor_,
                                  &GameSessionDescriptor__RTTI_Type_Descriptor_,
                                  0);
    if ( v29 )
    {
      storm::echo::SessionDescriptor::GetSessionName(v29);
      v2 = std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::c_str(v10, v20[0]);
      storm::CStringConvertToUtf16(
        v40,
        v2,
        v11,
        v20[0],
        v20[1],
        v20[2],
        v20[3],
        v21[0],
        v21[1],
        v21[2],
        v22,
        v23[0],
        v23[1],
        v23[2],
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30[0],
        v30[1],
        v30[2],
        v30[3],
        v31[0],
        v31[1],
        v31[2],
        v31[3],
        v31[4],
        v31[5],
        v31[6],
        v31[7],
        v31[8],
        v31[9],
        v31[10],
        v31[11],
        v31[12],
        v31[13],
        v31[14],
        v31[15],
        Destination[0]);
      LOBYTE(v43) = 3;
      v3 = std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::c_str(28, v12);
      MyWStrNCopy((int)v31, v3, v8);
      (*(void (__thiscall **)(CDaoIndexFieldInfo *, int *))(*(_DWORD *)v29 + 28))(v29, &v27);
      (*(void (__thiscall **)(CDaoIndexFieldInfo *, int *))(*(_DWORD *)v29 + 36))(v29, &v24);
      Destination[132] = v27 - v24;
      Destination[131] = v27;
      TickCount = GameSessionDescriptor::GetTickCount(v29);
      std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(
        v13,
        v20[0]);
      LOBYTE(v43) = 4;
      GameSessionDescriptor::GetMapName(v41);
      v4 = (const wchar_t *)std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::c_str(
                              v14,
                              v20[0]);
      j__wcscpy((wchar_t *)Destination, v4);
      std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(
        v15,
        v20[0]);
      LOBYTE(v43) = 5;
      GameSessionDescriptor::GetSaveFile(v42);
      v26 = (unsigned __int8)std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::empty(v42) == 0;
      v35 = v26;
      v5 = (const wchar_t *)std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::c_str(
                              v16,
                              v20[0]);
      j__wcscpy(v39, v5);
      SaveId = GameSessionDescriptor::GetSaveId(v29);
      v37 = 0;
      v33 = 0;
      SessionGUID = (storm::GUID *)storm::echo::SessionDescriptor::GetSessionGUID(v29);
      storm::GUID::Get(SessionGUID, &v38);
      std::list<SGameInfo>::push_back(v30);
      LOBYTE(v43) = 4;
      std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::~basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(
        v17,
        v20[0]);
      LOBYTE(v43) = 3;
      std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::~basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(
        v18,
        v20[0]);
      LOBYTE(v43) = 2;
      std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::~basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(
        v19,
        v20[0]);
    }
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<storm::ISimpleMatchmakingStrategy::SessionInfo *>>>::operator++(v23);
  }
  LOBYTE(v43) = 1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<storm::ISimpleMatchmakingStrategy::SessionInfo *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<storm::ISimpleMatchmakingStrategy::SessionInfo *>>>(v21);
  LOBYTE(v43) = 0;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<storm::ISimpleMatchmakingStrategy::SessionInfo *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<storm::ISimpleMatchmakingStrategy::SessionInfo *>>>(v23);
  v43 = -1;
  return std::vector<storm::ISimpleMatchmakingStrategy::SessionInfo *,storm::Allocator<storm::ISimpleMatchmakingStrategy::SessionInfo *,1092677632>>::~vector<storm::ISimpleMatchmakingStrategy::SessionInfo *,storm::Allocator<storm::ISimpleMatchmakingStrategy::SessionInfo *,1092677632>>(
           v10,
           v20[0]);
}


// address=[0x1616c30]
// Decompiled from void __thiscall OnlineManager::OnPeerJoined(OnlineManager *this)
void  OnlineManager::OnPeerJoined(void) {
  
  ;
}


// address=[0x1616c40]
// Decompiled from void __thiscall OnlineManager::OnPeerGone(OnlineManager *this, unsigned int a2)
void  OnlineManager::OnPeerGone(int) {
  
  INetworkEngine::StormOnPeerGone((CGameHost **)g_pNetworkEngine, a2);
}


// address=[0x1616c60]
// Decompiled from void __thiscall OnlineManager::OnHost(OnlineManager *this)
void  OnlineManager::OnHost(void) {
  
  _DWORD *v1; // eax
  void *v2; // [esp+4h] [ebp-38h]
  _BYTE v3[28]; // [esp+10h] [ebp-2Ch] BYREF
  int v4; // [esp+38h] [ebp-4h]

  *((_BYTE *)this + 82) = 1;
  INetworkEngine::StormOnHost((CGameHost **)g_pNetworkEngine);
  v1 = std::wstring::c_str((_Cnd_internal_imp_t *)&unk_4030720);
  v2 = storm::CStringConvertToUtf8(v3, (int)v1);
  v4 = 0;
  StormManager::GetInstance();
  StormManager::UpdateSessionName((unsigned int)v2);
  v4 = -1;
  std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::~basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>(v3);
}


// address=[0x1616d00]
// Decompiled from INetworkEngine *__thiscall OnlineManager::OnSessionEnter(OnlineManager *this)
void  OnlineManager::OnSessionEnter(void) {
  
  int Instance; // eax
  int HostPeerId; // esi
  int v3; // eax
  bool v5; // [esp+Bh] [ebp-1h]

  if ( !(unsigned __int8)OnlineManager::IsQuickMatchFlow(this) )
    return INetworkEngine::StormEnteredSession((INetworkEngine *)g_pNetworkEngine);
  Instance = StormManager::GetInstance();
  HostPeerId = StormManager::GetHostPeerId(Instance);
  v3 = StormManager::GetInstance();
  v5 = HostPeerId == StormManager::GetLocalPeerId(v3);
  INetworkEngine::OnQuickMatched((CGameHost **)g_pNetworkEngine, v5);
  return INetworkEngine::StormEnteredSession((INetworkEngine *)g_pNetworkEngine);
}


// address=[0x1616d70]
// Decompiled from int __thiscall OnlineManager::OnSessionLost(OnlineManager *this)
void  OnlineManager::OnSessionLost(void) {
  
  _BYTE v2[20]; // [esp+0h] [ebp-1Ch] BYREF
  int v3; // [esp+14h] [ebp-8h]
  OnlineManager *v4; // [esp+18h] [ebp-4h]

  v4 = this;
  *((_BYTE *)this + 83) = 1;
  v3 = std::queue<OnlineManager::GameMessage>::queue<OnlineManager::GameMessage,std::deque<OnlineManager::GameMessage>>(v2);
  std::queue<OnlineManager::GameMessage>::operator=(v3);
  return std::queue<OnlineManager::GameMessage>::~queue<OnlineManager::GameMessage,std::deque<OnlineManager::GameMessage>>(v2);
}


// address=[0x1616db0]
// Decompiled from _BYTE *__thiscall OnlineManager::OnGameSetup(_BYTE *this)
void  OnlineManager::OnGameSetup(void) {
  
  _BYTE *result; // eax

  result = this;
  this[81] = 1;
  return result;
}


// address=[0x1616dd0]
// Decompiled from void __thiscall OnlineManager::GetPlayerData(  OnlineManager *this,  int a2,  bool *a3,  int *a4,  int *a5,  int *a6,  int *a7,  int *a8,  int *a9,  struct String *a10)
void  OnlineManager::GetPlayerData(int,bool &,int &,int &,int &,int &,int &,int &,class String &) {
  
  char *v10; // eax
  int v11; // [esp-4h] [ebp-48h]
  int v12; // [esp+4h] [ebp-40h]
  int v13; // [esp+10h] [ebp-34h] BYREF
  int v14; // [esp+14h] [ebp-30h]
  _BYTE v15[28]; // [esp+18h] [ebp-2Ch] BYREF
  int v16; // [esp+40h] [ebp-4h]

  v13 = a2;
  v14 = std::map<unsigned long,OnlineManager::PlayerMessage,std::less<unsigned long>,storm::Allocator<std::pair<unsigned long const,OnlineManager::PlayerMessage>,1092657155>>::operator[](&v13);
  *a3 = *(_BYTE *)v14;
  *a4 = *(_DWORD *)(v14 + 4);
  *a5 = *(_DWORD *)(v14 + 8);
  *a6 = *(_DWORD *)(v14 + 12);
  *a7 = *(_DWORD *)(v14 + 16);
  *a8 = 0;
  *a9 = *(_DWORD *)(v14 + 20);
  v10 = (char *)std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::c_str(-1);
  v12 = String::String(v10, v11);
  v16 = 0;
  String::operator=(a10, v12);
  v16 = -1;
  String::~String((String *)v15);
}


// address=[0x1616ec0]
// Decompiled from int __thiscall OnlineManager::SendUnicastGameSetup(OnlineManager *this, int a2, void *Src, size_t Size)
void  OnlineManager::SendUnicastGameSetup(int,void *,unsigned long) {
  
  int Instance; // eax
  int v5; // eax
  const char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  StormManager *v9; // eax
  char v11; // [esp-50h] [ebp-1A4h]
  int v12; // [esp-4Ch] [ebp-1A0h]
  int v13; // [esp-48h] [ebp-19Ch]
  int v14; // [esp-44h] [ebp-198h]
  int v15; // [esp-40h] [ebp-194h]
  int v16; // [esp-3Ch] [ebp-190h]
  char v17; // [esp-38h] [ebp-18Ch] BYREF
  int v18; // [esp-34h] [ebp-188h]
  int v19; // [esp-30h] [ebp-184h]
  int v20; // [esp-2Ch] [ebp-180h]
  int v21; // [esp-28h] [ebp-17Ch]
  int v22; // [esp-24h] [ebp-178h]
  int v23; // [esp-20h] [ebp-174h]
  _DWORD v24[5]; // [esp-1Ch] [ebp-170h] BYREF
  unsigned int v25; // [esp-8h] [ebp-15Ch]
  const char *v26; // [esp-4h] [ebp-158h]
  int v27; // [esp+0h] [ebp-154h]
  _BYTE v28[12]; // [esp+4h] [ebp-150h] BYREF
  _BYTE v29[12]; // [esp+10h] [ebp-144h] BYREF
  int v30; // [esp+1Ch] [ebp-138h]
  char *v31; // [esp+20h] [ebp-134h]
  int v32; // [esp+24h] [ebp-130h]
  void *v33; // [esp+28h] [ebp-12Ch]
  int v34; // [esp+2Ch] [ebp-128h]
  _DWORD v35[2]; // [esp+30h] [ebp-124h] BYREF
  std::_Iterator_base12 *v36; // [esp+38h] [ebp-11Ch]
  int v37; // [esp+3Ch] [ebp-118h] BYREF
  int LocalPeerId; // [esp+40h] [ebp-114h]
  OnlineManager *v39; // [esp+44h] [ebp-110h]
  char v40; // [esp+4Bh] [ebp-109h]
  int v41; // [esp+4Ch] [ebp-108h]
  _BYTE v42[244]; // [esp+50h] [ebp-104h] BYREF
  int v43; // [esp+150h] [ebp-4h]

  v39 = this;
  Instance = StormManager::GetInstance();
  LocalPeerId = StormManager::GetLocalPeerId(Instance);
  v37 = LocalPeerId;
  std::_Tree<std::_Tmap_traits<unsigned long,OnlineManager::PlayerMessage,std::less<unsigned long>,storm::Allocator<std::pair<unsigned long const,OnlineManager::PlayerMessage>,1092657155>,0>>::find(
    v29,
    &v37);
  v43 = 0;
  v36 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned long,OnlineManager::PlayerMessage,std::less<unsigned long>,storm::Allocator<std::pair<unsigned long const,OnlineManager::PlayerMessage>,1092657155>,0>>::end(v28);
  v35[1] = v36;
  LOBYTE(v43) = 1;
  v40 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,OnlineManager::PlayerMessage>>>>::operator!=(v36);
  LOBYTE(v43) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,OnlineManager::PlayerMessage>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,OnlineManager::PlayerMessage>>>>(v28);
  if ( v40 )
  {
    v35[0] = LocalPeerId;
    v41 = std::map<unsigned long,OnlineManager::PlayerMessage,std::less<unsigned long>,storm::Allocator<std::pair<unsigned long const,OnlineManager::PlayerMessage>,1092657155>>::operator[](v35);
    v5 = std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::c_str(v27);
    v6 = (const char *)std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::c_str(v5);
    OnlineManager::UpdatePlayerData(
      v39,
      LocalPeerId,
      *(_BYTE *)v41,
      *(_DWORD *)(v41 + 4),
      *(_DWORD *)(v41 + 8),
      *(_DWORD *)(v41 + 12),
      *(_DWORD *)(v41 + 16),
      *(_DWORD *)(v41 + 20),
      v6,
      v26);
    storm::StormGameSetupMessage::StormGameSetupMessage((storm::StormGameSetupMessage *)v42);
    LOBYTE(v43) = 2;
    v7 = (char *)std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::c_str(v27);
    v33 = v24;
    v34 = std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>(v7);
    v32 = v34;
    LOBYTE(v43) = 3;
    v8 = (char *)std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::c_str(v24[0]);
    v31 = &v17;
    v30 = std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>(v8);
    v16 = *(_DWORD *)(v41 + 20);
    v15 = *(_DWORD *)(v41 + 16);
    v14 = *(_DWORD *)(v41 + 12);
    v13 = *(_DWORD *)(v41 + 8);
    v12 = *(_DWORD *)(v41 + 4);
    v11 = *(_BYTE *)v41;
    LOBYTE(v43) = 2;
    storm::StormGameSetupMessage::SetPlayer(
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24[0],
      v24[1],
      v24[2],
      v24[3],
      v24[4],
      v25,
      v26);
    storm::StormGameSetupMessage::SetBufferData(Src, Size);
    v26 = v42;
    v25 = a2;
    v9 = (StormManager *)StormManager::GetInstance();
    StormManager::SendUnicastGameSetupMessage(v9, v25, (const struct storm::StormGameSetupMessage *)v26);
    LOBYTE(v43) = 0;
    storm::StormGameSetupMessage::~StormGameSetupMessage((storm::StormGameSetupMessage *)v42);
  }
  v43 = -1;
  return std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,OnlineManager::PlayerMessage>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,OnlineManager::PlayerMessage>>>>(v29);
}


// address=[0x1617140]
// Decompiled from void __thiscall OnlineManager::SendUnicastPlayerMessage(  void *this,  int a2,  char *Str,  const struct storm::StormPlayerMessage *a4)
void  OnlineManager::SendUnicastPlayerMessage(int,char const *,int) {
  
  StormManager *Instance; // eax
  char v5; // [esp-20h] [ebp-84h] BYREF
  int v6; // [esp-1Ch] [ebp-80h]
  int v7; // [esp-18h] [ebp-7Ch]
  int v8; // [esp-14h] [ebp-78h]
  int v9; // [esp-10h] [ebp-74h]
  int v10; // [esp-Ch] [ebp-70h]
  unsigned int v11; // [esp-8h] [ebp-6Ch]
  const struct storm::StormPlayerMessage *v12; // [esp-4h] [ebp-68h]
  int v13; // [esp+4h] [ebp-60h]
  char *v14; // [esp+8h] [ebp-5Ch]
  void *v15; // [esp+Ch] [ebp-58h]
  _BYTE v16[68]; // [esp+10h] [ebp-54h] BYREF
  int v17; // [esp+60h] [ebp-4h]

  v15 = this;
  storm::StormPlayerMessage::StormPlayerMessage((storm::StormPlayerMessage *)v16);
  v17 = 0;
  v12 = a4;
  v14 = &v5;
  v13 = std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>(Str);
  storm::StormPlayerMessage::SetPlayer(v5, v6, v7, v8, v9, v10, v11, v12);
  v12 = (const struct storm::StormPlayerMessage *)v16;
  v11 = a2;
  Instance = (StormManager *)StormManager::GetInstance();
  StormManager::SendUnicastPlayerMessage(Instance, v11, v12);
  v17 = -1;
  storm::StormPlayerMessage::~StormPlayerMessage((storm::StormPlayerMessage *)v16);
}


// address=[0x16171e0]
// Decompiled from unsigned int __thiscall OnlineManager::GetMessageCount(OnlineManager *this, unsigned int *a2)
void  OnlineManager::GetMessageCount(unsigned long &) {
  
  unsigned int result; // eax

  result = std::queue<OnlineManager::GameMessage>::size((char *)this + 12, this);
  *a2 = result;
  return result;
}


// address=[0x1617200]
// Decompiled from char __thiscall OnlineManager::Receive(char *this, void *a2, size_t *a3, _DWORD *a4)
bool  OnlineManager::Receive(void *,int &,unsigned int &) {
  
  int v5; // [esp+0h] [ebp-2Ch]
  const unsigned __int8 *Src; // [esp+Ch] [ebp-20h]
  storm::DataBuffer *v7; // [esp+14h] [ebp-18h]

  std::unique_lock<std::mutex>::unique_lock<std::mutex>(this + 32);
  if ( std::queue<OnlineManager::GameMessage>::size(this + 12) )
  {
    v7 = (storm::DataBuffer *)std::queue<OnlineManager::GameMessage>::front(this + 12);
    Src = storm::DataBuffer::Get(v7);
    *a3 = storm::DataBuffer::GetBufferSizeInByte(v7);
    *a4 = *((_DWORD *)v7 + 8);
    j__memcpy(a2, Src, *a3);
    std::queue<OnlineManager::GameMessage>::pop(this + 12);
    std::unique_lock<std::mutex>::~unique_lock<std::mutex>(v5);
    return 1;
  }
  else
  {
    std::unique_lock<std::mutex>::~unique_lock<std::mutex>(v5);
    return 0;
  }
}


// address=[0x16172f0]
// Decompiled from void __thiscall OnlineManager::Send(OnlineManager *this, unsigned int a2, void *Src, size_t Size)
void  OnlineManager::Send(unsigned long,void *,unsigned long) {
  
  StormManager *Instance; // eax
  _BYTE v5[36]; // [esp+4h] [ebp-34h] BYREF
  OnlineManager *v6; // [esp+28h] [ebp-10h]
  int v7; // [esp+34h] [ebp-4h]

  v6 = this;
  storm::StormMessage::StormMessage((storm::StormMessage *)v5);
  v7 = 0;
  storm::StormMessage::SetBufferData(Src, Size);
  Instance = (StormManager *)StormManager::GetInstance();
  StormManager::SendUnicastMessage(Instance, a2, (const struct storm::StormMessage *)v5);
  v7 = -1;
  storm::StormMessage::~StormMessage((CMapStringToString::CPair *)v5);
}


// address=[0x1617370]
// Decompiled from void __thiscall OnlineManager::Send(OnlineManager *this, void *Src, size_t Size)
void  OnlineManager::Send(void *,unsigned long) {
  
  StormManager *Instance; // eax
  _BYTE v4[36]; // [esp+4h] [ebp-34h] BYREF
  OnlineManager *v5; // [esp+28h] [ebp-10h]
  int v6; // [esp+34h] [ebp-4h]

  v5 = this;
  storm::StormMessage::StormMessage((storm::StormMessage *)v4);
  v6 = 0;
  storm::StormMessage::SetBufferData(Src, Size);
  Instance = (StormManager *)StormManager::GetInstance();
  StormManager::SendBroadcastMessage(Instance, (const struct storm::StormMessage *)v4);
  v6 = -1;
  storm::StormMessage::~StormMessage((CMapStringToString::CPair *)v4);
}


// address=[0x16173f0]
// Decompiled from char __thiscall OnlineManager::PendingSessionLost(_BYTE *this)
bool  OnlineManager::PendingSessionLost(void)const {
  
  return this[83];
}


// address=[0x1617410]
// Decompiled from _BYTE *__thiscall OnlineManager::ProcessPendingSessionLost(_BYTE *this)
void  OnlineManager::ProcessPendingSessionLost(void) {
  
  _BYTE *result; // eax

  result = this;
  this[83] = 0;
  return result;
}


// address=[0x1617430]
// Decompiled from char __thiscall OnlineManager::PendingOnHost(_BYTE *this)
bool  OnlineManager::PendingOnHost(void)const {
  
  return this[82];
}


// address=[0x1617450]
// Decompiled from _BYTE *__thiscall OnlineManager::ProcessPendingOnHost(_BYTE *this)
void  OnlineManager::ProcessPendingOnHost(void) {
  
  _BYTE *result; // eax

  result = this;
  this[82] = 0;
  return result;
}


// address=[0x1617470]
// Decompiled from int __thiscall OnlineManager::GetLocalPeerId(OnlineManager *this)
int  OnlineManager::GetLocalPeerId(void)const {
  
  int Instance; // eax

  if ( !OnlineManager::IsInSession(this) )
    return 0;
  Instance = StormManager::GetInstance();
  return StormManager::GetLocalPeerId(Instance);
}


// address=[0x16174a0]
// Decompiled from bool __thiscall OnlineManager::IsLocalPeerId(OnlineManager *this, int a2)
bool  OnlineManager::IsLocalPeerId(int)const {
  
  return a2 == OnlineManager::GetLocalPeerId(this);
}


// address=[0x16174d0]
// Decompiled from bool __thiscall OnlineManager::IsLoggedIn(OnlineManager *this)
bool  OnlineManager::IsLoggedIn(void)const {
  
  StormManager *Instance; // eax

  Instance = (StormManager *)StormManager::GetInstance();
  return StormManager::IsLoggedIn(Instance);
}


// address=[0x16174f0]
// Decompiled from bool __thiscall OnlineManager::IsNATReady(OnlineManager *this)
bool  OnlineManager::IsNATReady(void)const {
  
  StormManager *Instance; // eax

  Instance = (StormManager *)StormManager::GetInstance();
  return StormManager::IsNATReady(Instance);
}


// address=[0x1617510]
// Decompiled from bool __thiscall OnlineManager::IsInSession(OnlineManager *this)
bool  OnlineManager::IsInSession(void)const {
  
  int Instance; // eax

  Instance = StormManager::GetInstance();
  return StormManager::GetSessionState(Instance, this) != 2;
}


// address=[0x1617550]
// Decompiled from bool __thiscall OnlineManager::IsHost(void *this)
bool  OnlineManager::IsHost(void)const {
  
  int Instance; // eax

  Instance = StormManager::GetInstance();
  return StormManager::GetSessionState(Instance, this) == 0;
}


// address=[0x1617590]
// Decompiled from char __thiscall OnlineManager::IsQuickMatchFlow(OnlineManager *this)
bool  OnlineManager::IsQuickMatchFlow(void)const {
  
  return *((_BYTE *)this + 85);
}


// address=[0x16175b0]
// Decompiled from OnlineManager *__thiscall OnlineManager::SetQuickMatchFlow(OnlineManager *this, bool a2)
void  OnlineManager::SetQuickMatchFlow(bool) {
  
  OnlineManager *result; // eax

  result = this;
  *((_BYTE *)this + 85) = a2;
  return result;
}


// address=[0x16175d0]
// Decompiled from OnlineManager *__thiscall OnlineManager::SetPrivate(OnlineManager *this, bool a2)
void  OnlineManager::SetPrivate(bool) {
  
  OnlineManager *result; // eax

  result = this;
  *((_BYTE *)this + 87) = a2;
  return result;
}


// address=[0x16175f0]
// Decompiled from char __thiscall OnlineManager::IsPrivate(OnlineManager *this)
bool  OnlineManager::IsPrivate(void)const {
  
  return *((_BYTE *)this + 87);
}


// address=[0x1617610]
// Decompiled from char __thiscall OnlineManager::IsInviteFlow(OnlineManager *this)
bool  OnlineManager::IsInviteFlow(void)const {
  
  return *((_BYTE *)this + 86);
}


// address=[0x1617630]
// Decompiled from OnlineManager *__thiscall OnlineManager::SetInviteFlow(OnlineManager *this, bool a2)
void  OnlineManager::SetInviteFlow(bool) {
  
  OnlineManager *result; // eax

  result = this;
  *((_BYTE *)this + 86) = a2;
  return result;
}


// address=[0x1617650]
// Decompiled from OnlineManager *__thiscall OnlineManager::OnOnlineError(OnlineManager *this)
void  OnlineManager::OnOnlineError(void) {
  
  OnlineManager *result; // eax

  result = this;
  *((_BYTE *)this + 84) = 1;
  return result;
}


// address=[0x1617670]
// Decompiled from char __thiscall OnlineManager::GetAndClearOnlineError(OnlineManager *this)
bool  OnlineManager::GetAndClearOnlineError(void) {
  
  if ( !*((_BYTE *)this + 84) )
    return 0;
  *((_BYTE *)this + 84) = 0;
  return 1;
}


// address=[0x16176a0]
// Decompiled from int __thiscall OnlineManager::OnAcceptInvite(OnlineManager *this)
void  OnlineManager::OnAcceptInvite(void) {
  
  int result; // eax

  result = (unsigned __int8)CGameStateHandler::CanProcessInvites();
  if ( (_BYTE)result )
    return CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 18);
  return result;
}


// address=[0x161d910]
// Decompiled from int __thiscall OnlineManager::~OnlineManager(OnlineManager *this)
 OnlineManager::~OnlineManager(void) {
  
  std::mutex::~mutex((OnlineManager *)((char *)this + 32));
  std::queue<OnlineManager::GameMessage>::~queue<OnlineManager::GameMessage,std::deque<OnlineManager::GameMessage>>((char *)this + 12);
  return std::map<unsigned long,OnlineManager::PlayerMessage,std::less<unsigned long>,storm::Allocator<std::pair<unsigned long const,OnlineManager::PlayerMessage>,1092657155>>::~map<unsigned long,OnlineManager::PlayerMessage,std::less<unsigned long>,storm::Allocator<std::pair<unsigned long const,OnlineManager::PlayerMessage>,1092657155>>(this);
}


// address=[0x16176d0]
// Decompiled from void __thiscall OnlineManager::UpdatePlayerData(  OnlineManager *this,  int a2,  bool a3,  int a4,  int a5,  int a6,  int a7,  int a8,  char *Str,  char *a10)
void  OnlineManager::UpdatePlayerData(int,bool,int,int,int,int,int,char const *,char const *) {
  
  int v10; // [esp+8h] [ebp-64h] BYREF
  bool v11[4]; // [esp+Ch] [ebp-60h] BYREF
  int v12; // [esp+10h] [ebp-5Ch]
  int v13; // [esp+14h] [ebp-58h]
  int v14; // [esp+18h] [ebp-54h]
  int v15; // [esp+1Ch] [ebp-50h]
  int v16; // [esp+20h] [ebp-4Ch]
  int v17; // [esp+68h] [ebp-4h]

  OnlineManager::PlayerMessage::PlayerMessage((OnlineManager::PlayerMessage *)v11);
  v17 = 0;
  v11[0] = a3;
  v12 = a4;
  v13 = a5;
  v14 = a6;
  v15 = a7;
  v16 = a8;
  std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::operator=(Str);
  std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::operator=(a10);
  v10 = a2;
  std::map<unsigned long,OnlineManager::PlayerMessage,std::less<unsigned long>,storm::Allocator<std::pair<unsigned long const,OnlineManager::PlayerMessage>,1092657155>>::operator[](&v10);
  OnlineManager::PlayerMessage::operator=(v11);
  v17 = -1;
  OnlineManager::PlayerMessage::~PlayerMessage((OnlineManager::PlayerMessage *)v11);
}


// address=[0x1617790]
// Decompiled from OnlineManager *__thiscall OnlineManager::OnlineManager(OnlineManager *this)
 OnlineManager::OnlineManager(void) {
  
  std::map<unsigned long,OnlineManager::PlayerMessage,std::less<unsigned long>,storm::Allocator<std::pair<unsigned long const,OnlineManager::PlayerMessage>,1092657155>>::map<unsigned long,OnlineManager::PlayerMessage,std::less<unsigned long>,storm::Allocator<std::pair<unsigned long const,OnlineManager::PlayerMessage>,1092657155>>(this);
  std::queue<OnlineManager::GameMessage>::queue<OnlineManager::GameMessage,std::deque<OnlineManager::GameMessage>>((char *)this + 12);
  std::mutex::mutex((OnlineManager *)((char *)this + 32));
  *((_BYTE *)this + 80) = 1;
  *((_BYTE *)this + 81) = 0;
  *((_BYTE *)this + 82) = 0;
  *((_BYTE *)this + 83) = 0;
  *((_BYTE *)this + 84) = 0;
  *((_BYTE *)this + 85) = 0;
  *((_BYTE *)this + 86) = 0;
  *((_BYTE *)this + 87) = 0;
  return this;
}


// address=[0x462b9a0]
// [Decompilation failed for static class OnlineManager * OnlineManager::m_instance]

