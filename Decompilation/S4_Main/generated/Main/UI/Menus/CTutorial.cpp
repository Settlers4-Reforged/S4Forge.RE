#include "all_headers.h"

// Definitions for class CTutorial

// address=[0x147d690]
// Decompiled from CTutorial *__thiscall CTutorial::Init(CTutorial *this)
void  CTutorial::Init(void) {
  
  CTutorial *result; // eax

  TBitArray<2956>::SetArray(&unk_3F44AE0);
  IGuiEngine::SetDlgToIgnore((IGuiEngine *)g_pGUIEngine, 36, 1);
  IGuiEngine::SetCtrlStatusCallback((IGuiEngine *)g_pGUIEngine, (bool (__cdecl *)(int, int, int, bool, int))sub_147E0F0);
  CTutorial::RefreshGUIControlStatus(this);
  IEventEngine::RegisterHandle(g_pEvnEngine, (struct IEvn_Handle *)&g_cTutorial);
  IGuiEngine::SetDlgToIgnore((IGuiEngine *)g_pGUIEngine, 36, 1);
  IGuiEngine::SetCtrlStatusCallback((IGuiEngine *)g_pGUIEngine, (bool (__cdecl *)(int, int, int, bool, int))sub_147E140);
  CTutorial::EnableAllGUIControls(this);
  result = this;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  return result;
}


// address=[0x147d720]
// Decompiled from bool __thiscall CTutorial::Kill(CTutorial *this)
void  CTutorial::Kill(void) {
  
  *((_DWORD *)this + 1) = 0;
  CTutorial::EnableAllGUIControls(this);
  CTutorial::RefreshGUIControlStatus(this);
  IGuiEngine::SetDlgToIgnore((IGuiEngine *)g_pGUIEngine, 36, 0);
  IGuiEngine::SetCtrlStatusCallback((IGuiEngine *)g_pGUIEngine, 0);
  return IEventEngine::UnRegisterHandle(g_pEvnEngine, (struct IEvn_Handle *)&g_cTutorial);
}


// address=[0x147d780]
// Decompiled from int __thiscall CTutorial::RefreshGUIControlStatus(CTutorial *this)
void  CTutorial::RefreshGUIControlStatus(void) {
  
  return IGuiEngine::RefreshAllSurfaces(g_pGUIEngine);
}


// address=[0x147d7a0]
// Decompiled from int __thiscall CTutorial::EnableGUIControl(CTutorial *this, int a2)
void  CTutorial::EnableGUIControl(int) {
  
  return sub_147E0A0(a2);
}


// address=[0x147d7c0]
// Decompiled from int __thiscall CTutorial::DisableGUIControl(CTutorial *this, int a2)
void  CTutorial::DisableGUIControl(int) {
  
  return sub_147E0A0(a2);
}


// address=[0x147d7e0]
// Decompiled from int __thiscall CTutorial::EnableAllGUIControls(CTutorial *this)
void  CTutorial::EnableAllGUIControls(void) {
  
  sub_147DFE0(this);
  sub_147E030();
  return sub_147E090();
}


// address=[0x147d800]
// Decompiled from int __thiscall CTutorial::DisableAllGUIControls(CTutorial *this)
void  CTutorial::DisableAllGUIControls(void) {
  
  sub_147DFE0(this);
  sub_147E030();
  sub_147E080();
  sub_147DFF0(36);
  sub_147DFF0(37);
  sub_147DFF0(57);
  sub_147E040(4);
  sub_147E040(6);
  sub_147E040(9);
  sub_147E040(14);
  sub_147E040(15);
  sub_147E0A0(610);
  sub_147E0A0(1021);
  sub_147E0A0(1022);
  sub_147E0A0(1023);
  sub_147E0A0(612);
  sub_147E0A0(611);
  sub_147E0A0(930);
  sub_147E0A0(1070);
  sub_147E0A0(1071);
  sub_147E0A0(1072);
  sub_147E0A0(1711);
  return sub_147E0A0(1712);
}


// address=[0x147d910]
// Decompiled from int __thiscall CTutorial::SetWorldTutorialCursor(CTutorial *this, int a2, int a3)
void  CTutorial::SetWorldTutorialCursor(int,int) {
  
  IEffects *v3; // eax
  int v4; // eax
  int result; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( *((_DWORD *)this + 2) )
  {
    v6 = *((_DWORD *)this + 2);
    v3 = (IEffects *)CLogic::Effects((DWORD *)g_pLogic);
    IEffects::DeleteMovingEffect(v3, v6);
  }
  v4 = CLogic::Effects((DWORD *)g_pLogic);
  result = (*(int (__thiscall **)(int, int, int, int))(*(_DWORD *)v4 + 40))(v4, 57, a2, a3);
  *((_DWORD *)this + 2) = result;
  return result;
}


// address=[0x147d970]
// Decompiled from CTutorial *__thiscall CTutorial::DeleteWorldTutorialCursor(CTutorial *this)
void  CTutorial::DeleteWorldTutorialCursor(void) {
  
  CTutorial *result; // eax
  IEffects *v2; // eax
  unsigned int v3; // [esp-4h] [ebp-8h]

  result = this;
  if ( !*((_DWORD *)this + 2) )
    return result;
  v3 = *((_DWORD *)this + 2);
  v2 = (IEffects *)CLogic::Effects((DWORD *)g_pLogic);
  IEffects::DeleteMovingEffect(v2, v3);
  result = this;
  *((_DWORD *)this + 2) = 0;
  return result;
}


// address=[0x147e520]
// Decompiled from CTutorial *__thiscall CTutorial::CTutorial(CTutorial *this)
 CTutorial::CTutorial(void) {
  
  IEvn_Handle::IEvn_Handle(this);
  *(_DWORD *)this = &CTutorial::_vftable_;
  return this;
}


// address=[0x160d980]
// Decompiled from int __thiscall CTutorial::CurrentZoomFactor(CTutorial *this)
int  CTutorial::CurrentZoomFactor(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x147d9b0]
// Decompiled from char __thiscall CTutorial::OnEvent(CTutorial *this, struct CEvn_Event *a2)
bool  CTutorial::OnEvent(class CEvn_Event &) {
  
  char result; // al
  int v3; // eax
  int v4; // eax
  int SelectedBuilding; // eax
  int v6; // eax
  int v7; // eax
  unsigned int event; // [esp+4h] [ebp-4h]

  event = a2->event;
  if ( event > 0x192 )
  {
    if ( event > 0x1389 )
    {
      if ( event != 5003 )
        return 0;
      SelectedBuilding = CTutorial::GetSelectedBuilding(this);
      CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 12, SelectedBuilding);
    }
    else
    {
      if ( event != 5001 )
      {
        switch ( event )
        {
          case 0x193u:
            v7 = CTutorial::GetSelectedBuilding(this);
            CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 14, v7);
            return 0;
          case 0x195u:
            if ( !a2->wparam )
              return 0;
            v4 = CTutorial::GetSelectedBuilding(this);
            CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 10, v4);
            return 0;
          case 0x197u:
            v3 = CTutorial::GetSelectedBuilding(this);
            CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 11, v3);
            return 0;
          case 0x199u:
LABEL_32:
            CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 16, 1061);
            return 0;
          case 0x1A3u:
            CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 0x14u);
            return 0;
          case 0x1ACu:
            CGameScriptManager::SetGlobal(
              (CGameScriptManager *)g_pScriptMgr,
              "gActiveMenu",
              byte_3F1E908 + 8 * a2->event);
            return 0;
          case 0x1ADu:
          case 0x1AEu:
          case 0x1AFu:
          case 0x1B0u:
          case 0x1B1u:
          case 0x1B2u:
          case 0x1C1u:
          case 0x1C2u:
          case 0x1C3u:
          case 0x1C4u:
          case 0x1C5u:
          case 0x1C6u:
          case 0x1C7u:
          case 0x1C8u:
          case 0x1C9u:
          case 0x1CAu:
          case 0x1CBu:
            CGameScriptManager::SetGlobal((CGameScriptManager *)g_pScriptMgr, "gActiveMenu", 8 * a2->event);
            CGameScriptManager::SendGameEvent(
              (CGameScriptManager *)g_pScriptMgr,
              19,
              8 * a2->event,
              a2->wparam,
              a2->lparam);
            return 0;
          case 0x1B5u:
            CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 8, a2->lparam);
            return 0;
          case 0x1CEu:
            CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 0x15u, a2->wparam, a2->lparam);
            return 0;
          case 0x25Au:
            goto LABEL_35;
          case 0x25Du:
LABEL_30:
            *((_DWORD *)this + 1) = a2->lparam;
            CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 15, a2->lparam);
            return 0;
          case 0x275u:
            CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 16, 1712);
            return 0;
          case 0x276u:
            CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 16, 1711);
            return 0;
          default:
            return 0;
        }
      }
      v6 = CTutorial::GetSelectedBuilding(this);
      CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 13, v6);
    }
    return 0;
  }
  if ( event == 402 )
  {
LABEL_35:
    CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 16, 0);
    return 0;
  }
  switch ( event )
  {
    case 9u:
      if ( CTutorial::IsWarriorSelected(this) )
        CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 9u);
      return 0;
    case 0xBu:
      if ( a2->wparam != 32 || byte_3F44E66 )
        return 0;
      byte_3F44E66 = 1;
      CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 7u);
      result = 0;
      break;
    case 0x12u:
      goto LABEL_30;
    case 0x14u:
      if ( a2->wparam != 32 )
        return 0;
      byte_3F44E66 = 0;
      result = 0;
      break;
    case 0x6Au:
      CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 16, a2->wparam);
      goto LABEL_32;
    default:
      return 0;
  }
  return result;
}


// address=[0x147de30]
// Decompiled from char __thiscall CTutorial::IsWarriorSelected(CTutorial *this)
bool  CTutorial::IsWarriorSelected(void) {
  
  int v1; // eax
  unsigned int v2; // eax
  unsigned __int16 *v3; // eax
  _BYTE v5[16]; // [esp+4h] [ebp-2Ch] BYREF
  CTutorial *v6; // [esp+14h] [ebp-1Ch]
  unsigned int i; // [esp+1Ch] [ebp-14h]
  char v9; // [esp+22h] [ebp-Eh]
  char v10; // [esp+23h] [ebp-Dh]
  int v11; // [esp+2Ch] [ebp-4h]

  v6 = this;
  v1 = CInputProcessor::Selection();
  std::vector<unsigned short>::vector<unsigned short>(v1);
  v11 = 0;
  if ( std::vector<unsigned short>::size(v5) )
  {
    for ( i = 0; ; ++i )
    {
      v2 = std::vector<unsigned short>::size(v5);
      if ( i >= v2 )
        break;
      v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](i);
      if ( CSettlerMgr::GetSettlerPtr(*v3) )
      {
        v10 = 1;
        v11 = -1;
        std::vector<unsigned short>::~vector<unsigned short>(v5);
        return v10;
      }
    }
  }
  v9 = 0;
  v11 = -1;
  std::vector<unsigned short>::~vector<unsigned short>(v5);
  return v9;
}


// address=[0x147df00]
// Decompiled from int __thiscall CTutorial::GetSelectedBuilding(CTutorial *this)
int  CTutorial::GetSelectedBuilding(void) {
  
  int v1; // eax
  unsigned int v2; // eax
  unsigned __int16 *v3; // eax
  _BYTE v5[16]; // [esp+4h] [ebp-30h] BYREF
  CTutorial *v6; // [esp+14h] [ebp-20h]
  int v7; // [esp+18h] [ebp-1Ch]
  int v8; // [esp+1Ch] [ebp-18h]
  unsigned __int8 *BuildingPtr; // [esp+20h] [ebp-14h]
  unsigned int i; // [esp+24h] [ebp-10h]
  int v11; // [esp+30h] [ebp-4h]

  v6 = this;
  v1 = CInputProcessor::Selection();
  std::vector<unsigned short>::vector<unsigned short>(v1);
  v11 = 0;
  if ( std::vector<unsigned short>::size(v5) )
  {
    for ( i = 0; ; ++i )
    {
      v2 = std::vector<unsigned short>::size(v5);
      if ( i >= v2 )
        break;
      v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](i);
      BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *v3);
      if ( BuildingPtr )
      {
        v8 = IEntity::Type((unsigned __int16 *)BuildingPtr);
        v11 = -1;
        std::vector<unsigned short>::~vector<unsigned short>(v5);
        return v8;
      }
    }
  }
  v7 = 0;
  v11 = -1;
  std::vector<unsigned short>::~vector<unsigned short>(v5);
  return v7;
}


