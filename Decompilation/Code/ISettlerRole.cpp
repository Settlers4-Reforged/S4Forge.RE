#include "ISettlerRole.h"

// Definitions for class ISettlerRole

// address=[0x1351b50]
// Decompiled from int __thiscall ISettlerRole::GetTask(ISettlerRole *this)
int  ISettlerRole::GetTask(void)const {
  
  return *((char *)this + 4);
}


// address=[0x1563710]
// Decompiled from ISettlerRole *__thiscall ISettlerRole::~ISettlerRole(ISettlerRole *this)
 ISettlerRole::~ISettlerRole(void) {
  
  ISettlerRole *result; // eax

  result = this;
  *(_DWORD *)this = &ISettlerRole::_vftable_;
  return result;
}


// address=[0x15637d0]
// Decompiled from void *__thiscall ISettlerRole::ClearGroupFlagBits(std::_Ref_count_base *this, const struct type_info *a2)
int  ISettlerRole::ClearGroupFlagBits(int) {
  
  return 0;
}


// address=[0x15637f0]
// Decompiled from int __thiscall ISettlerRole::Decrease(ISettlerRole *this, int a2)
int  ISettlerRole::Decrease(int) {
  
  return a2;
}


// address=[0x1563810]
// Decompiled from int __thiscall ISettlerRole::GetGroupFlags(ISettlerRole *this)
int  ISettlerRole::GetGroupFlags(void)const {
  
  return 0;
}


// address=[0x1563840]
// Decompiled from int __thiscall ISettlerRole::GetWarriorBehavior(ISettlerRole *this)
class CWarriorBehavior *  ISettlerRole::GetWarriorBehavior(void) {
  
  return 0;
}


// address=[0x1563850]
// Decompiled from int __thiscall ISettlerRole::HomeEntityId(ISettlerRole *this)
int  ISettlerRole::HomeEntityId(void)const {
  
  return *((unsigned __int16 *)this + 16);
}


// address=[0x1563930]
// Decompiled from char __thiscall ISettlerRole::IsUnEmployed(ISettlerRole *this)
bool  ISettlerRole::IsUnEmployed(void)const {
  
  return 0;
}


// address=[0x1563940]
// Decompiled from ISettlerRole *__thiscall ISettlerRole::SetBuilding(ISettlerRole *this, __int16 a2)
void  ISettlerRole::SetBuilding(int) {
  
  ISettlerRole *result; // eax

  result = this;
  *((_WORD *)this + 16) = a2;
  return result;
}


// address=[0x15639a0]
// Decompiled from ISettlerRole *__thiscall ISettlerRole::SetEntity(ISettlerRole *this, __int16 a2)
void  ISettlerRole::SetEntity(int) {
  
  ISettlerRole *result; // eax

  result = this;
  *((_WORD *)this + 17) = a2;
  return result;
}


// address=[0x15639e0]
// Decompiled from void *__thiscall ISettlerRole::SetGroupFlagBits(std::_Ref_count_base *this, const struct type_info *a2)
int  ISettlerRole::SetGroupFlagBits(int) {
  
  return 0;
}


// address=[0x1563a00]
// Decompiled from void *__thiscall ISettlerRole::SetGroupFlags(std::_Ref_count_base *this, const struct type_info *a2)
int  ISettlerRole::SetGroupFlags(int) {
  
  return 0;
}


// address=[0x1563a20]
// Decompiled from void __thiscall ISettlerRole::UpdateJob(ISettlerRole *this, struct CSettler *a2)
void  ISettlerRole::UpdateJob(class CSettler *) {
  
  ;
}


// address=[0x15671a0]
// Decompiled from int __thiscall ISettlerRole::SourcePileId(ISettlerRole *this)
int  ISettlerRole::SourcePileId(void)const {
  
  return *((unsigned __int16 *)this + 10);
}


// address=[0x15897e0]
// Decompiled from ISettlerRole *__thiscall ISettlerRole::ISettlerRole(ISettlerRole *this)
 ISettlerRole::ISettlerRole(void) {
  
  CPersistence::CPersistence(this);
  *(_DWORD *)this = &ISettlerRole::_vftable_;
  *((_BYTE *)this + 4) = 0;
  *((_BYTE *)this + 5) = 0;
  *((_BYTE *)this + 6) = 1;
  *((_BYTE *)this + 7) = 1;
  *((_WORD *)this + 4) = 0;
  *((_BYTE *)this + 10) = 1;
  *((_BYTE *)this + 11) = 0;
  *((_BYTE *)this + 12) = 0;
  *((_WORD *)this + 7) = 0;
  *((_WORD *)this + 8) = 0;
  *((_WORD *)this + 9) = 0;
  *((_WORD *)this + 10) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_WORD *)this + 16) = 0;
  *((_WORD *)this + 17) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  return this;
}


// address=[0x15898a0]
// Decompiled from int __thiscall ISettlerRole::Go(ISettlerRole *this, struct CSettler *a2)
void  ISettlerRole::Go(class CSettler *) {
  
  int v3; // eax
  int v4; // eax
  int v5; // [esp+4h] [ebp-8h]

  *((_BYTE *)this + 5) = CSettler::Walk(a2);
  if ( (*((_BYTE *)this + 5) & 0x20) != 0 )
    return (*(int (__thiscall **)(ISettlerRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
  if ( (*((_BYTE *)this + 5) & 0x40) != 0 )
    return (*(int (__thiscall **)(ISettlerRole *, struct CSettler *, int))(*(_DWORD *)this + 64))(this, a2, -1);
  if ( (*((_BYTE *)this + 5) & 0xFu) >= 6 )
    return IAnimatedEntity::RegisterForLogicUpdate(1);
  *((_BYTE *)a2 + 69) = -1;
  *((_BYTE *)this + 6) = 9;
  if ( IEntity::Type((unsigned __int16 *)a2) != 1 && IEntity::Type((unsigned __int16 *)a2) != 60 )
    return IAnimatedEntity::RegisterForLogicUpdate(*((char *)this + 6));
  v3 = IEntity::PackedXY(a2);
  v4 = CWorldManager::Index(v3);
  v5 = CWorldManager::MoveCostsBits(v4);
  if ( v5 == 1 )
  {
    *((_BYTE *)this + 6) = 8;
  }
  else if ( !v5 )
  {
    *((_BYTE *)this + 6) = 7;
  }
  return IAnimatedEntity::RegisterForLogicUpdate(*((char *)this + 6));
}


// address=[0x15899a0]
// Decompiled from int __thiscall ISettlerRole::LogicUpdate(ISettlerRole *this, struct CSettler *a2)
void  ISettlerRole::LogicUpdate(class CSettler *) {
  
  int v2; // eax
  int v3; // eax
  unsigned int v5; // eax
  int v6; // [esp+0h] [ebp-20h]
  int v7; // [esp+0h] [ebp-20h]
  unsigned int v8; // [esp+4h] [ebp-1Ch]
  int v9; // [esp+10h] [ebp-10h]
  int v10; // [esp+14h] [ebp-Ch]
  int v11; // [esp+18h] [ebp-8h]

  if ( *((_BYTE *)this + 4) != 17 )
    return (*(int (__thiscall **)(ISettlerRole *, struct CSettler *))(*(_DWORD *)this + 28))(this, a2);
  *((_BYTE *)a2 + 69) = 0;
  *((_BYTE *)this + 7) = 1;
  v11 = std::auto_ptr<CWalking>::operator->(v6);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v11 + 8))(v11, -1, 0);
  v10 = std::auto_ptr<CWalking>::operator->(v7);
  v2 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v10 + 12))(v10, *((_DWORD *)a2 + 6));
  *((_BYTE *)this + 5) = CSettler::WalkDir(a2, v2);
  v8 = *((_BYTE *)this + 5) & 0xF;
  if ( v8 >= 6 )
  {
    *((_BYTE *)a2 + 36) = 0;
    v5 = CStateGame::Rand(g_pGame);
    return IAnimatedEntity::RegisterForLogicUpdate(v5 % 4 + 1);
  }
  else
  {
    v3 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator*((char *)a2 + 88);
    *((_BYTE *)this + 7) = *(_BYTE *)(std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator->(
                                        (char *)a2 + 88,
                                        v3,
                                        v8)
                                    + 8);
    if ( !*((_BYTE *)this + 7)
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 191, "m_iCycleFrames > 0") == 1 )
    {
      __debugbreak();
    }
    if ( *((unsigned __int8 *)this + 7) > 1u )
      v9 = *((unsigned __int8 *)this + 7) - 1;
    else
      v9 = 1;
    if ( v9 <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 194, "iCycleFramesEx > 0") == 1 )
      __debugbreak();
    *((_BYTE *)a2 + 36) = 0;
    *((_BYTE *)a2 + 69) = -1;
    return IAnimatedEntity::RegisterForLogicUpdate(v9);
  }
}


// address=[0x1589b30]
// Decompiled from void __thiscall ISettlerRole::Update(_WORD *this, CMFCCaptionButton *a2)
void  ISettlerRole::Update(class CSettler *) {
  
  __int16 TickCounter; // si
  int v3; // eax
  int v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // [esp-8h] [ebp-34h]
  int v8; // [esp-4h] [ebp-30h]
  int v9; // [esp+4h] [ebp-28h] BYREF
  unsigned __int8 v10; // [esp+8h] [ebp-24h]
  char v11; // [esp+9h] [ebp-23h]
  int v12; // [esp+Ch] [ebp-20h]
  int v13; // [esp+10h] [ebp-1Ch]
  unsigned int v14; // [esp+14h] [ebp-18h]
  int v15; // [esp+18h] [ebp-14h]
  unsigned int v16; // [esp+1Ch] [ebp-10h]
  unsigned int v17; // [esp+20h] [ebp-Ch]
  int v18; // [esp+24h] [ebp-8h]
  _WORD *v19; // [esp+28h] [ebp-4h]

  v19 = this;
  TickCounter = CStateGame::GetTickCounter(g_pGame);
  v19[4] = TickCounter - IAnimatedEntity::LastUpdateTick(a2);
  if ( v19[4] )
  {
    v3 = CStateGame::GetTickCounter(g_pGame);
    IAnimatedEntity::SetLastUpdateTick(a2, v3);
    v18 = *((char *)v19 + 4) - 1;
    switch ( v18 )
    {
      case 0:
      case 2:
      case 12:
      case 15:
      case 24:
      case 27:
      case 28:
      case 29:
      case 30:
        if ( *((_BYTE *)v19 + 10) )
        {
          *((_BYTE *)a2 + 36) = ((unsigned __int16)v19[4] + IAnimatedEntity::Frame(a2)) % *((unsigned __int8 *)v19 + 7);
        }
        else
        {
          v14 = *((unsigned __int8 *)v19 + 7);
          v17 = *((unsigned __int8 *)a2 + 36);
          v16 = (unsigned __int16)v19[4] % v14;
          if ( v17 < v16 )
            *((_BYTE *)a2 + 36) = (v14 + v17 - v16) % *((unsigned __int8 *)v19 + 7);
          else
            *((_BYTE *)a2 + 36) = v17 - v16;
        }
        CEntityToDoListMgr::GetJobSoundInfo(*((unsigned __int16 *)a2 + 19), (struct SJobSoundInfo *)&v9);
        if ( v9 > 0 && v11 == *((_BYTE *)a2 + 36) )
        {
          if ( v10 == 100 || (v4 = v10, v4 >= j__rand() % 100) )
          {
            v8 = IEntity::Y(a2);
            v5 = IEntity::X(a2);
            if ( (*(unsigned __int8 (__thiscall **)(void *, int, int))(*(_DWORD *)g_pFogging + 32))(g_pFogging, v5, v8) )
            {
              v7 = IEntity::Y(a2);
              v6 = IEntity::X(a2);
              CSoundManager::PlayEnvironmentSound(g_pSoundManager, v9, v6, v7, 0);
            }
          }
        }
        v12 = IEntity::WarriorType();
        if ( ((1 << v12) & 0x3C) != 0 )
          CLogic::SetWarAction(g_pLogic);
        break;
      case 5:
        if ( (*((_BYTE *)v19 + 5) & 8) != 0 )
        {
          *((_BYTE *)a2 + 36) = 0;
        }
        else
        {
          *((_BYTE *)a2 + 36) = ((unsigned __int16)v19[4] + *((unsigned __int8 *)a2 + 36))
                              % *((unsigned __int8 *)v19 + 7);
          if ( !*((_BYTE *)a2 + 36) )
            *((_BYTE *)a2 + 36) = 1;
          IMovingEntity::DecDistance(a2, ((unsigned __int16)v19[4] << 8) / *((char *)v19 + 6));
        }
        break;
      case 16:
        if ( (*((_BYTE *)v19 + 5) & 8) != 0 )
        {
          *((_BYTE *)a2 + 36) = 0;
        }
        else
        {
          *((_BYTE *)a2 + 36) = ((unsigned __int16)v19[4] + *((unsigned __int8 *)a2 + 36))
                              % *((unsigned __int8 *)v19 + 7);
          if ( !*((_BYTE *)a2 + 36) )
            *((_BYTE *)a2 + 36) = 1;
          if ( *((unsigned __int8 *)v19 + 7) > 1u )
            v15 = *((unsigned __int8 *)v19 + 7) - 1;
          else
            v15 = 1;
          v13 = v15;
          IMovingEntity::DecDistance(a2, ((unsigned __int16)v19[4] << 8) / v15);
        }
        break;
      default:
        (*(void (__thiscall **)(_WORD *, CMFCCaptionButton *))(*(_DWORD *)v19 + 32))(v19, a2);
        break;
    }
  }
}


// address=[0x1589e30]
// Decompiled from int __thiscall ISettlerRole::NewDestination(ISettlerRole *this, struct CSettler *a2, int a3, int a4)
void  ISettlerRole::NewDestination(class CSettler *,int,int) {
  
  int result; // eax

  *((_DWORD *)this + 7) = IEntity::PackedXY(a2);
  result = a3;
  *((_DWORD *)this + 6) = a3;
  return result;
}


// address=[0x1589e60]
// Decompiled from int __thiscall ISettlerRole::NewDestination(ISettlerRole *this, struct CSettler *a2, int a3, int a4, int a5)
void  ISettlerRole::NewDestination(class CSettler *,int,int,int) {
  
  int result; // eax

  *((_DWORD *)this + 7) = IEntity::PackedXY(a2);
  result = Y16X16::PackXYFast(a3, a4);
  *((_DWORD *)this + 6) = result;
  return result;
}


// address=[0x1589ea0]
// Decompiled from char __thiscall ISettlerRole::SearchPosition(int this, _DWORD *a2, int a3)
bool  ISettlerRole::SearchPosition(class CSettler *,int) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp-8h] [ebp-4Ch]
  int v8; // [esp-8h] [ebp-4Ch]
  int v9; // [esp-8h] [ebp-4Ch]
  int v10; // [esp+14h] [ebp-30h]
  int v11; // [esp+18h] [ebp-2Ch]
  int v12; // [esp+20h] [ebp-24h]
  int v13; // [esp+24h] [ebp-20h]
  int (__cdecl *v14)(int, int, _DWORD); // [esp+28h] [ebp-1Ch]
  int v15; // [esp+2Ch] [ebp-18h]
  int v17; // [esp+34h] [ebp-10h]
  int v18; // [esp+38h] [ebp-Ch]
  int v19; // [esp+3Ch] [ebp-8h]
  char v20; // [esp+43h] [ebp-1h]

  v20 = 0;
  v17 = 0;
  v11 = IEntity::X(a2);
  v10 = IEntity::Y(a2);
  v7 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::Race(a2);
  CSettlerMgr::GetSettlerInfo(v3, v7);
  v12 = *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](a3) + 5);
  v8 = IEntity::Type((unsigned __int16 *)a2);
  v4 = IEntity::Race(a2);
  CSettlerMgr::GetSettlerInfo(v4, v8);
  v13 = *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](a3) + 6);
  v9 = IEntity::Type((unsigned __int16 *)a2);
  v5 = IEntity::Race(a2);
  CSettlerMgr::GetSettlerInfo(v5, v9);
  v14 = *(int (__cdecl **)(int, int, _DWORD))std::vector<CSettlerMgr::SSearchInfos>::operator[](a3);
  if ( !v14 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 594, "pSearchFkt != 0") == 1 )
    __debugbreak();
  while ( v17 < 500 )
  {
    v18 = v11 + CSpiralOffsets::DeltaX(v17);
    v19 = v10 + CSpiralOffsets::DeltaY(v17);
    if ( (unsigned __int8)CWorldManager::InWorld(v18, v19) )
    {
      v15 = v14(v18, v19, 0);
      if ( v15 > 0 )
      {
        *(_DWORD *)(this + 24) = Y16X16::PackXYFast(v12 + v18, v13 + v19);
        *(_WORD *)(this + 34) = v15;
        return 1;
      }
      if ( v15 < 0 )
      {
        *(_DWORD *)(this + 24) = Y16X16::PackXYFast(v12 + v18, v13 + v19);
        *(_WORD *)(this + 34) = 0;
        return 1;
      }
    }
    ++v17;
  }
  return v20;
}


// address=[0x158a0a0]
// Decompiled from char __thiscall ISettlerRole::ESChanged(ISettlerRole *this, struct CSettler *a2)
bool  ISettlerRole::ESChanged(class CSettler *) {
  
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int v6; // [esp-4h] [ebp-24h]
  int v7; // [esp+4h] [ebp-1Ch]
  CEcoSector *v8; // [esp+Ch] [ebp-14h]
  ISettlerRole *v10; // [esp+14h] [ebp-Ch]
  char v12; // [esp+1Fh] [ebp-1h]

  if ( this != (ISettlerRole *)CSettler::Role(a2)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 998, "pDbgOrgThis == pDbgOrgRole") == 1 )
  {
    __debugbreak();
  }
  if ( (*(int (__thiscall **)(ISettlerRole *))(*(_DWORD *)this + 72))(this) == 18
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 999, "pDbgOrgThis->GetSettlerRole() != FLEE_ROLE") == 1 )
  {
    __debugbreak();
  }
  v12 = (*(int (__thiscall **)(ISettlerRole *, struct CSettler *, int))(*(_DWORD *)this + 64))(this, a2, -1);
  v10 = (ISettlerRole *)CSettler::Role(a2);
  if ( v12 )
  {
    if ( v10 == this
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 1009, "pDbgRoleAfterFree != pDbgOrgThis") == 1 )
    {
      __debugbreak();
    }
    if ( (*(int (__thiscall **)(ISettlerRole *))(*(_DWORD *)v10 + 72))(v10) != 18
      && BBSupportDbgReport(
           2,
           "MapObjects\\Settler\\SettlerRole.cpp",
           1010,
           "pDbgRoleAfterFree->GetSettlerRole() == FLEE_ROLE") == 1 )
    {
      __debugbreak();
    }
  }
  else
  {
    if ( v10 != this
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 1014, "pDbgRoleAfterFree == pDbgOrgThis") == 1 )
    {
      __debugbreak();
    }
    v6 = IEntity::Y(a2);
    v2 = IEntity::X(a2);
    v7 = CWorldManager::EcoSectorId(v2, v6);
    v8 = (CEcoSector *)CEcoSectorMgr::EntryPtr((CEcoSectorMgr *)g_cESMgr, v7);
    if ( v8 )
    {
      v3 = CEcoSector::Owner(v8);
      if ( v3 == IEntity::OwnerId((unsigned __int8 *)a2) )
      {
        v4 = IEntity::Type((unsigned __int16 *)a2);
        CEcoSector::ChangeNrOfSettler(v8, v4, 1);
      }
    }
  }
  return 0;
}


// address=[0x158a230]
// Decompiled from char __thiscall ISettlerRole::SetFree(ISettlerRole *this, struct CSettler *a2, int a3)
bool  ISettlerRole::SetFree(class CSettler *,int) {
  
  unsigned __int8 *v3; // eax
  CBuilding *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // esi
  int v10; // eax
  unsigned __int16 *v11; // eax
  int v12; // ecx
  int v14; // [esp-8h] [ebp-44h]
  int v15[6]; // [esp-4h] [ebp-40h] BYREF
  int v16; // [esp+14h] [ebp-28h]
  _BYTE v17[4]; // [esp+18h] [ebp-24h] BYREF
  _AFX_OLE_STATE *v18; // [esp+1Ch] [ebp-20h]
  _AFX_OLE_STATE *v19; // [esp+20h] [ebp-1Ch]
  struct IEntity *v20; // [esp+24h] [ebp-18h]
  ISettlerRole *v21; // [esp+28h] [ebp-14h]
  char v22; // [esp+2Fh] [ebp-Dh]
  int v23; // [esp+38h] [ebp-4h]

  v21 = this;
  ISettlerRole::DetachFromPile(this, a2, 1, 0);
  ISettlerRole::DetachFromPile(v21, a2, 2, 0);
  ISettlerRole::DetachFromPile(v21, a2, 3, 0);
  ISettlerRole::DetachFromPile(v21, a2, 4, 0);
  if ( *((_WORD *)v21 + 16) )
  {
    if ( !IEntity::FlagBits(a2, Attached)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Settler\\SettlerRole.cpp",
           798,
           "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED )") == 1 )
    {
      __debugbreak();
    }
    v3 = (unsigned __int8 *)CMapObjectMgr::Entity(*((unsigned __int16 *)v21 + 16));
    if ( IEntity::ObjType(v3) == 8 )
    {
      v15[0] = IEntity::ID();
      v4 = (CBuilding *)CBuildingMgr::operator[](*((unsigned __int16 *)v21 + 16));
      CBuilding::InhabitantFlee(v4, v15[0]);
    }
    v20 = CMapObjectMgr::Entity(*((unsigned __int16 *)v21 + 16));
    v5 = IEntity::ID();
    ((void (__thiscall *)(struct IEntity *, int))v20->lpVtbl[1].Relationships)(v20, v5);
    *((_WORD *)v21 + 16) = 0;
  }
  if ( IEntity::FlagBits(a2, Attached)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SettlerRole.cpp",
         808,
         "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED ) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)v21 + 6) )
  {
    v15[0] = 32;
    v6 = CWorldManager::Index(*((_DWORD *)v21 + 6));
    CWorldManager::ClearFlagBits(v6, 32);
  }
  v7 = IEntity::WorldIdx();
  CWorldManager::EcoSectorId(v7);
  if ( IEntity::WarriorType() )
    goto LABEL_22;
  v8 = IEntity::WorldIdx();
  v9 = CWorldManager::OwnerId(v8);
  if ( v9 == IEntity::OwnerId((unsigned __int8 *)a2) )
  {
    v10 = IEntity::WorldIdx();
    v16 = CWorldManager::EcoSectorId(v10);
    if ( !IEntity::FlagBits(a2, Offered) )
    {
      v15[0] = IEntity::ID();
      v14 = IEntity::Type((unsigned __int16 *)a2);
      v11 = (unsigned __int16 *)CEcoSectorMgr::operator[](v16);
      CEcoSector::SetSettlerOffer(v11, v14, v15[0]);
    }
LABEL_22:
    CSettler::TakeWaitList(a2);
    return 0;
  }
  v19 = (_AFX_OLE_STATE *)operator new(0x2Cu);
  v23 = 0;
  if ( v19 )
    v18 = CFleeRole::CFleeRole(v19);
  else
    v18 = 0;
  v15[5] = (int)v18;
  std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(v18);
  v23 = 1;
  v15[0] = v12;
  v15[4] = (int)v15;
  v15[3] = std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(v17);
  CSettler::NewRole(a2, v15[0]);
  v22 = 1;
  v23 = -1;
  std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(v17);
  return v22;
}


// address=[0x158a4d0]
// Decompiled from int __thiscall ISettlerRole::SetObserverTarget(_WORD *this, int a2, __int16 a3)
void  ISettlerRole::SetObserverTarget(enum T_OBSERVER_TARGET,int) {
  
  int result; // eax

  result = a2;
  if ( a2 )
  {
    if ( a2 == 2 )
    {
      result = (int)this;
      this[10] = a3;
    }
    else
    {
      result = BBSupportDbgReport(
                 1,
                 "MapObjects\\Settler\\SettlerRole.cpp",
                 749,
                 "ISettlerRole::SetObserverTarget(): Invalid target type!");
      if ( result == 1 )
        __debugbreak();
    }
  }
  else
  {
    this[16] = a3;
  }
  return result;
}


// address=[0x158a530]
// Decompiled from int __thiscall ISettlerRole::GetObserverTarget(unsigned __int16 *this, int a2)
int  ISettlerRole::GetObserverTarget(enum T_OBSERVER_TARGET) {
  
  if ( !a2 )
    return this[16];
  if ( a2 == 2 )
    return this[10];
  return 0;
}


// address=[0x158a570]
// Decompiled from char *__thiscall ISettlerRole::ISettlerRole(char *this, int a2)
 ISettlerRole::ISettlerRole(std::istream &) {
  
  int pExceptionObject; // [esp+0h] [ebp-Ch] BYREF
  unsigned int v4; // [esp+4h] [ebp-8h] BYREF
  char *v5; // [esp+8h] [ebp-4h]

  v5 = this;
  CPersistence::CPersistence(this);
  *(_DWORD *)v5 = &ISettlerRole::_vftable_;
  operator^<unsigned int>(a2, &v4);
  if ( v4 )
  {
    operator^<signed char>(a2, v5 + 4);
    operator^<unsigned char>(a2, v5 + 5);
    operator^<signed char>(a2, v5 + 6);
    operator^<unsigned char>(a2, v5 + 7);
    operator^<unsigned short>(a2, v5 + 8);
    operator^<unsigned char>(a2, v5 + 10);
    operator^<unsigned char>(a2, v5 + 11);
    operator^<short>(a2, v5 + 14);
    operator^<short>(a2, v5 + 16);
    operator^<unsigned short>(a2, v5 + 18);
    operator^<int>(a2, (int)(v5 + 24));
    operator^<int>(a2, (int)(v5 + 28));
    operator^<unsigned short>(a2, v5 + 32);
    operator^<unsigned short>(a2, v5 + 34);
    operator^<float>(a2, v5 + 36);
    operator^<float>(a2, v5 + 40);
  }
  if ( v4 >= 2 )
  {
    operator^<unsigned short>(a2, v5 + 20);
    operator^<unsigned char>(a2, v5 + 12);
  }
  if ( v4 && v4 < 3 )
    return v5;
  BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for ISettlerRole");
  pExceptionObject = 0;
  CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
  _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  return v5;
}


// address=[0x158a740]
// Decompiled from int __thiscall ISettlerRole::Store(struct CPersistence *this, struct std::ostream *a2)
void  ISettlerRole::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct CPersistence *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  CPersistence::Store(this, a2);
  v3 = 2;
  operator^<unsigned int>(a2, &v3);
  operator^<signed char>(a2, (char *)v4 + 4);
  operator^<unsigned char>(a2, (int)v4 + 5);
  operator^<signed char>(a2, (char *)v4 + 6);
  operator^<unsigned char>(a2, (int)v4 + 7);
  operator^<unsigned short>((int)a2, (__int16 *)v4 + 4);
  operator^<unsigned char>(a2, (int)v4 + 10);
  operator^<unsigned char>(a2, (int)v4 + 11);
  operator^<short>((int)a2, (__int16 *)v4 + 7);
  operator^<short>((int)a2, (__int16 *)v4 + 8);
  operator^<unsigned short>((int)a2, (__int16 *)v4 + 9);
  operator^<int>((int)a2, (int *)v4 + 6);
  operator^<int>((int)a2, (int *)v4 + 7);
  operator^<unsigned short>((int)a2, (__int16 *)v4 + 16);
  operator^<unsigned short>((int)a2, (__int16 *)v4 + 17);
  operator^<float>(a2, (char *)v4 + 36);
  operator^<float>(a2, (char *)v4 + 40);
  operator^<unsigned short>((int)a2, (__int16 *)v4 + 10);
  return operator^<unsigned char>(a2, (int)v4 + 12);
}


// address=[0x158a8d0]
// Decompiled from int __thiscall ISettlerRole::GetKindOfSelection(ISettlerRole *this, struct CSettler *a2)
int  ISettlerRole::GetKindOfSelection(class CSettler *)const {
  
  return 1;
}


// address=[0x158a8f0]
// Decompiled from int __thiscall ISettlerRole::MarkPileAsUnused(void *this, int a2)
void  ISettlerRole::MarkPileAsUnused(enum T_OBSERVER_TARGET) {
  
  int result; // eax

  if ( a2 )
  {
    if ( (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 84))(this, a2)
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 923, "GetObserverTarget(_tObserverTarget) == 0") == 1 )
    {
      __debugbreak();
    }
    (*(void (__thiscall **)(void *, int, int))(*(_DWORD *)this + 80))(this, a2, 0xFFFF);
    if ( (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 84))(this, a2) != 0xFFFF
      && BBSupportDbgReport(
           2,
           "MapObjects\\Settler\\SettlerRole.cpp",
           927,
           "GetObserverTarget(_tObserverTarget) == ENTITY_ID_UNUSED") == 1 )
    {
      __debugbreak();
    }
    return 0;
  }
  else
  {
    result = BBSupportDbgReportF(
               1,
               "MapObjects\\Settler\\SettlerRole.cpp",
               931,
               "ISettlerRole::MarkPileAsUnused(): Invalid type %i!",
               0);
    if ( result == 1 )
      __debugbreak();
  }
  return result;
}


// address=[0x158a9c0]
// Decompiled from int __thiscall ISettlerRole::DetachFromPile(void *this, unsigned __int16 *a2, int a3, char a4)
void  ISettlerRole::DetachFromPile(class CSettler *,enum T_OBSERVER_TARGET,bool) {
  
  int result; // eax
  unsigned __int8 *v5; // [esp+0h] [ebp-10h]
  int v6; // [esp+4h] [ebp-Ch]
  int v7; // [esp+8h] [ebp-8h]

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 943, "_pSettler != 0") == 1 )
    __debugbreak();
  if ( a3 )
  {
    result = (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 84))(this, a3);
    v7 = result;
    if ( result )
    {
      if ( result == 0xFFFF )
        return (*(int (__thiscall **)(void *, int, _DWORD))(*(_DWORD *)this + 80))(this, a3, 0);
      v6 = IEntity::EntityId(a2);
      if ( v6 <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 955, "iSettlerId > 0") == 1 )
        __debugbreak();
      v5 = CPileMgr::operator[](v7);
      if ( a4 )
        CPile::ChangeAmountAndDetach((CPile *)v5, v6);
      else
        (*(void (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v5 + 64))(v5, v6);
      if ( !(*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 84))(this, a3) )
        return (*(int (__thiscall **)(void *, int, _DWORD))(*(_DWORD *)this + 80))(this, a3, 0);
      if ( BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\SettlerRole.cpp",
             968,
             "GetObserverTarget(_tObserverTarget) == 0") == 1 )
        __debugbreak();
      return (*(int (__thiscall **)(void *, int, _DWORD))(*(_DWORD *)this + 80))(this, a3, 0);
    }
    else if ( a4 )
    {
      result = BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 975, "!_bChangeAmount");
      if ( result == 1 )
        __debugbreak();
    }
  }
  else
  {
    result = BBSupportDbgReportF(
               1,
               "MapObjects\\Settler\\SettlerRole.cpp",
               980,
               "ISettlerRole::DetachFromPile(): Invalid type %i!",
               0);
    if ( result == 1 )
      __debugbreak();
  }
  return result;
}


// address=[0x158ab30]
// Decompiled from int __thiscall ISettlerRole::GetNextSettlerType(ISettlerRole *this)
int  ISettlerRole::GetNextSettlerType(void) {
  
  return 0;
}


// address=[0x158ab40]
// Decompiled from char __thiscall ISettlerRole::SetNextSettlerType(ISettlerRole *this, int a2)
bool  ISettlerRole::SetNextSettlerType(int) {
  
  return 0;
}


// address=[0x158ab50]
// Decompiled from int __thiscall ISettlerRole::SettlerWalk(ISettlerRole *this, struct CSettler *a2)
int  ISettlerRole::SettlerWalk(class CSettler *) {
  
  return CSettler::Walk(a2);
}


// address=[0x158ab70]
// Decompiled from char __thiscall ISettlerRole::SearchRestingPlace(ISettlerRole *this, struct CSettler *a2, int a3)
bool  ISettlerRole::SearchRestingPlace(class CSettler *,int) {
  
  int v3; // esi
  int v6; // [esp+8h] [ebp-1Ch]
  int v7; // [esp+Ch] [ebp-18h]
  int v8; // [esp+10h] [ebp-14h]
  int v9; // [esp+14h] [ebp-10h]
  int v10; // [esp+18h] [ebp-Ch]
  int v11; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  if ( a3 <= 1 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 858, "_iDistance > 1") == 1 )
    __debugbreak();
  v7 = CSpiralOffsets::Last(a3);
  v6 = CSpiralOffsets::First(a3 - 1);
  v8 = IEntity::X(a2);
  v9 = IEntity::Y(a2);
  for ( i = v7; i >= v6; --i )
  {
    v10 = v8 + CSpiralOffsets::DeltaX(i);
    v11 = v9 + CSpiralOffsets::DeltaY(i);
    if ( (unsigned __int8)CWorldManager::InWorld(v10, v11) )
    {
      v3 = CWorldManager::EcoSectorId(v8, v9);
      if ( v3 == CWorldManager::EcoSectorId(v10, v11) && !CWorldManager::FlagBits(v10, v11, 0x77u) )
      {
        *((_DWORD *)this + 7) = Y16X16::PackXYFast(v10, v11);
        return 1;
      }
    }
  }
  return 0;
}


// address=[0x158aca0]
// Decompiled from char __thiscall ISettlerRole::CheckHome(ISettlerRole *this, struct CSettler *a2)
bool  ISettlerRole::CheckHome(class CSettler *) {
  
  if ( *((_WORD *)this + 16) )
    return 1;
  (*(void (__thiscall **)(ISettlerRole *, struct CSettler *, int))(*(_DWORD *)this + 64))(this, a2, -1);
  return 0;
}


// address=[0x158ace0]
// Decompiled from int __thiscall ISettlerRole::InitCommonTaskValues(  ISettlerRole *this,  struct CSettler *a2,  const struct CEntityTask *a3)
void  ISettlerRole::InitCommonTaskValues(class CSettler *,class CEntityTask const &) {
  
  int v3; // eax
  const char *v5; // [esp-4h] [ebp-10h]
  IBuildingRole *v6; // [esp+0h] [ebp-Ch]
  unsigned __int8 *BuildingPtr; // [esp+4h] [ebp-8h]

  if ( !*((_BYTE *)a3 + 4)
    || *((_BYTE *)a3 + 4) == 1
    || *((_BYTE *)a3 + 4) == 29
    || *((_BYTE *)a3 + 4) == 2
    || *((_BYTE *)a3 + 4) == 5
    || *((_BYTE *)a3 + 4) == 4
    || *((_BYTE *)a3 + 4) == 30 )
  {
    IEntity::SetFlagBits(a2, (EntityFlag)0x800u);
    *((_BYTE *)a2 + 69) = 0;
    *((_WORD *)this + 7) = *((_WORD *)a3 + 5);
    *((_WORD *)this + 8) = *((_WORD *)a3 + 6);
  }
  else
  {
    IEntity::ClearFlagBits(a2, (EntityFlag)0x800u);
    *((_BYTE *)a2 + 69) = 0;
    *((_WORD *)this + 7) = *((_WORD *)a3 + 5);
    *((_WORD *)this + 8) = *((_WORD *)a3 + 6);
  }
  if ( *((char *)a3 + 6) >= 0 )
    *((_BYTE *)a2 + 68) = *((_BYTE *)a3 + 6);
  if ( *((_BYTE *)a3 + 20) )
    IEntity::SetFlagBits(a2, Visible);
  else
    IEntity::ClearFlagBits(a2, Visible);
  if ( *((_BYTE *)a3 + 9) )
  {
    if ( !*((_WORD *)this + 16)
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 493, "m_uHomeEntityId != 0") == 1 )
    {
      __debugbreak();
    }
    if ( *((_WORD *)this + 16) )
    {
      BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 16));
      if ( !BuildingPtr && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 498, "pBuilding != NULL") == 1 )
        __debugbreak();
      if ( BuildingPtr )
      {
        v6 = (IBuildingRole *)CBuilding::Role(BuildingPtr);
        IBuildingRole::TakeJobTrigger(v6, *((unsigned __int8 *)a3 + 9));
      }
    }
  }
  *((_BYTE *)this + 5) = 72;
  *((_BYTE *)this + 4) = *((_BYTE *)a3 + 4);
  *((_BYTE *)this + 6) = *((_BYTE *)a3 + 7);
  *((_BYTE *)this + 7) = *((_BYTE *)a3 + 8);
  if ( *((unsigned __int8 *)this + 7) <= 1u )
  {
    v5 = (&off_37B8064)[2 * *((unsigned __int16 *)a3 + 7)];
    v3 = IEntity::Type((unsigned __int16 *)a2);
    BBSupportTracePrintF(
      3,
      "ISettlerRole::InitCommonTaskValues(): Invalid number of frames (%i) for settler type %s, job %s!",
      *((unsigned __int8 *)this + 7),
      (&off_37B7E4C)[2 * v3],
      v5);
  }
  if ( !*((_BYTE *)this + 7)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 526, "m_iCycleFrames >= 1") == 1 )
  {
    __debugbreak();
  }
  if ( *((_WORD *)a3 + 8) )
    *((_WORD *)this + 17) = *((_WORD *)a3 + 8);
  if ( *((_BYTE *)a3 + 5) )
    *((_BYTE *)this + 11) = *((_BYTE *)a3 + 5);
  *((_BYTE *)a2 + 36) = 0;
  *((_WORD *)a2 + 19) = *((_WORD *)a3 + 7);
  *((_BYTE *)this + 10) = *((_BYTE *)a3 + 21);
  if ( *((_BYTE *)this + 10) )
    return IAnimatedEntity::SetFrame(0);
  else
    return IAnimatedEntity::SetFrame(*((_BYTE *)this + 7) - 1);
}


// address=[0x158afa0]
// Decompiled from int __thiscall ISettlerRole::NewDestinationEx(  void *this,  unsigned __int16 *a2,  void *a3,  __int16 a4,  __int16 a5,  char a6)
void  ISettlerRole::NewDestinationEx(class CSettler *,class std::list<class CEntityTask,class std::allocator<class CEntityTask> > &,int,int,int) {
  
  int v6; // eax
  unsigned int v7; // eax
  CEntityTask *v8; // eax
  CEntityTask *v9; // eax
  int result; // eax
  int v11; // [esp-4h] [ebp-50h]
  int v12[6]; // [esp+0h] [ebp-4Ch] BYREF
  _BYTE v13[24]; // [esp+18h] [ebp-34h] BYREF
  int v14; // [esp+30h] [ebp-1Ch]
  int ActualTask; // [esp+34h] [ebp-18h]
  void *v16; // [esp+38h] [ebp-14h]
  unsigned int SettlerJobFrameCount; // [esp+3Ch] [ebp-10h]
  BOOL v18; // [esp+40h] [ebp-Ch]
  int SettlerFirstJob; // [esp+44h] [ebp-8h]
  bool v20; // [esp+4Bh] [ebp-1h]

  v16 = this;
  if ( std::list<CEntityTask>::size(a3) )
  {
    ActualTask = IMovingEntity::GetActualTask(a2);
    v18 = *(unsigned __int8 *)(ActualTask + 4) == 17;
    v20 = v18;
    if ( !v18 && (a6 & 2) != 0 )
    {
      v14 = std::list<CEntityTask>::back();
      if ( *(_BYTE *)(v14 + 4) == 17 )
        std::list<CEntityTask>::pop_back();
    }
    else
    {
      std::list<CEntityTask>::clear();
    }
  }
  v11 = IEntity::Type(a2);
  v6 = IEntity::Race(a2);
  SettlerFirstJob = CGfxManager::GetSettlerFirstJob(v6, v11);
  v7 = IEntity::Race(a2);
  SettlerJobFrameCount = CGfxManager::GetSettlerJobFrameCount((CGfxManager *)g_pGfxManager, v7, SettlerFirstJob, 2u);
  v8 = CEntityTask::CEntityTask(
         (CEntityTask *)v13,
         7,
         SettlerFirstJob,
         a4,
         a5,
         -1,
         SettlerJobFrameCount,
         -1,
         1,
         1,
         0,
         0,
         0,
         0);
  std::list<CEntityTask>::push_back(v8);
  v9 = CEntityTask::CEntityTask(
         (CEntityTask *)v12,
         17,
         SettlerFirstJob,
         a6 & 1,
         0,
         -1,
         SettlerJobFrameCount,
         -1,
         1,
         1,
         0,
         0,
         0,
         0);
  std::list<CEntityTask>::push_back(v9);
  IMovingEntity::SetToDoList(a2, (int)a3);
  result = std::list<CEntityTask>::size(a3);
  if ( result != 2 )
    return result;
  IMovingEntity::ResetToDoList(v12[0]);
  return (*(int (__thiscall **)(void *, unsigned __int16 *))(*(_DWORD *)v16 + 40))(v16, a2);
}


