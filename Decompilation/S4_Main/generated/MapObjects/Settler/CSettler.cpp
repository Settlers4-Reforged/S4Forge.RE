#include "all_headers.h"

// Definitions for class CSettler

// address=[0x130f340]
// Decompiled from int __thiscall CSettler::Role(CSettler *this)
class ISettlerRole &  CSettler::Role(void) {
  
  return std::auto_ptr<ISettlerRole>::operator*(&this[1].entityId);
}


// address=[0x1401bc0]
// Decompiled from int __cdecl CSettler::New(int a1)
static class CPersistence * __cdecl CSettler::New(std::istream &) {
  
  if ( CSettler::operator new(0x68u) )
    return CSettler::CSettler(a1);
  else
    return 0;
}


// address=[0x1439aa0]
// Decompiled from int __thiscall CSettler::GetNextSettlerType(CSettler *this)
int  CSettler::GetNextSettlerType(void) {
  
  int v1; // eax

  v1 = std::auto_ptr<ISettlerRole>::operator->((_DWORD *)this + 25);
  return (*(int (__thiscall **)(int, CSettler *, int))(*(_DWORD *)v1 + 112))(v1, this, v1);
}


// address=[0x1439e70]
// Decompiled from int __thiscall CSettler::SetNextSettlerType(CSettler *this, int a2)
bool  CSettler::SetNextSettlerType(int) {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = std::auto_ptr<ISettlerRole>::operator->((_DWORD *)this + 25);
  return (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 116))(v3, a2);
}


// address=[0x1439f80]
// Decompiled from bool __thiscall CSettler::Strike(CSettler *this)
bool  CSettler::Strike(void)const {
  
  return IEntity::FlagBits(this, (EntityFlag)0x1000u) == 0;
}


// address=[0x15081e0]
// Decompiled from int __thiscall CSettler::SetFree(CSettler *this)
void  CSettler::SetFree(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  v2 = std::auto_ptr<ISettlerRole>::operator->(&this[1].entityId);
  return (*(int (__thiscall **)(int, CSettler *, int))(*(_DWORD *)v2 + 64))(v2, this, -1);
}


// address=[0x1513ad0]
// Decompiled from int __thiscall CSettler::SetBuilding(CSettler *this, int a2)
void  CSettler::SetBuilding(int) {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = std::auto_ptr<ISettlerRole>::operator->((_DWORD *)this + 25);
  return (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 48))(v3, a2);
}


// address=[0x1513b30]
// Decompiled from int __thiscall CSettler::SetOffset(CSettler *this, float a2, float a3)
void  CSettler::SetOffset(float,float) {
  
  int result; // eax

  *(float *)(std::auto_ptr<ISettlerRole>::operator->((_DWORD *)this + 25) + 36) = a2;
  result = std::auto_ptr<ISettlerRole>::operator->((_DWORD *)this + 25);
  *(float *)(result + 40) = a3;
  return result;
}


// address=[0x157d1f0]
// Decompiled from int __thiscall CSettler::Delete(int this)
void  CSettler::Delete(void) {
  
  _anonymous_namespace_::_GetFileInfoByHandleEx *v1; // eax
  int v2; // eax
  int LastLogicUpdateTick; // eax
  int v4; // eax
  int v5; // eax
  int result; // eax
  int v7; // [esp-Ch] [ebp-2Ch]
  int v8; // [esp-8h] [ebp-28h]
  int v9; // [esp-4h] [ebp-24h]
  int v10; // [esp+0h] [ebp-20h]
  const char *v11; // [esp+4h] [ebp-1Ch]
  int v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  bool v16; // [esp+1Fh] [ebp-1h]

  *(_DWORD *)(this + 20) &= ~0x10000000u;
  if ( IEntity::Type((unsigned __int16 *)this) < 67
    && !IEntity::WarriorType()
    && !IEntity::FlagBits((_DWORD *)this, OnBoard) )
  {
    *(_DWORD *)(this + 20) |= 0x10000000u;
  }
  IEntity::RemoveFromMapObjectLayerIfNecessary(this);
  v1 = IEntity::WarMapNode((CPropertySet *)this);
  if ( CWarMapNode::IsInWarMap(v1) )
  {
    v2 = IEntity::EntityId((unsigned __int16 *)this);
    CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, v2, 3, (struct tagVARIANT *)&stru_37B13E0);
    CWarMap::RemoveEntity((CPropertySet *)this);
  }
  v9 = IEntity::ID();
  LastLogicUpdateTick = IAnimatedEntity::GetLastLogicUpdateTick((CPaneContainer *)this);
  CMapObjectMgr::UnRegisterFromLogicUpdate(g_pMapObjectMgr, LastLogicUpdateTick, v9);
  v13 = std::auto_ptr<ISettlerRole>::operator->((_DWORD *)(this + 100));
  (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v13 + 64))(v13, this, -1);
  if ( IEntity::Type((unsigned __int16 *)this) < 67 )
  {
    v16 = 1;
    if ( !IEntity::WarriorType() )
    {
      v12 = CSettler::Role(this);
      v16 = (*(int (__thiscall **)(int))(*(_DWORD *)v12 + 72))(v12) == 18;
    }
    if ( v16 && (IEntity::Flags((_DWORD *)this) & 0x100) != 0 )
    {
      v11 = CGameData::Rand(g_pGameData);
      if ( (unsigned int)v11 >= CRandom16::PercentValue(0x21u) )
      {
        if ( (unsigned int)v11 >= CRandom16::PercentValue(0x42u) )
          v14 = 3;
        else
          v14 = 2;
      }
      else
      {
        v14 = 1;
      }
      v10 = CLogic::Effects((DWORD *)g_pLogic);
      v8 = IEntity::OwnerId((unsigned __int8 *)this);
      v7 = IEntity::Y((void *)this);
      v4 = IEntity::X((_DWORD *)this);
      (*(void (__thiscall **)(int, int, int, int, int, int, _DWORD))(*(_DWORD *)v10 + 20))(v10, v14, 41, v4, v7, v8, 0);
    }
  }
  v5 = IEntity::EntityId((unsigned __int16 *)this);
  CSettlerMgr::CheckOutSettler((CSettlerMgr *)g_cSettlerMgr, v5);
  result = this;
  *(_DWORD *)(this + 20) &= ~0x10000000u;
  return result;
}


// address=[0x157d3f0]
// Decompiled from int __thiscall CSettler::LogicUpdate(CSettler *this)
void  CSettler::LogicUpdate(void) {
  
  int result; // eax
  int v2; // [esp+0h] [ebp-Ch]
  int v3; // [esp+4h] [ebp-8h]

  result = IEntity::FlagBits(this, (EntityFlag)&unk_4000000);
  if ( result )
    return result;
  if ( IEntity::FlagBits(this, (EntityFlag)0x80u) )
  {
    IEntity::ClearFlagBits(this, (EntityFlag)0x80u);
    v3 = std::auto_ptr<ISettlerRole>::operator->((_DWORD *)this + 25);
    result = (*(int (__thiscall **)(int, CSettler *))(*(_DWORD *)v3 + 60))(v3, this);
    if ( (_BYTE)result )
      return result;
  }
  if ( IAnimatedEntity::ProcessAllEvents(this) )
    return IEntity::FlagBits(this, Registered);
  v2 = std::auto_ptr<ISettlerRole>::operator->((_DWORD *)this + 25);
  (*(void (__thiscall **)(int, CSettler *))(*(_DWORD *)v2 + 24))(v2, this);
  return IEntity::FlagBits(this, Registered);
}


// address=[0x157d4b0]
// Decompiled from void *__thiscall CSettler::GetGfxInfos(int this)
struct SGfxObjectInfo *  CSettler::GetGfxInfos(void) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // [esp-4h] [ebp-7Ch]
  int SettlerInfo; // [esp+8h] [ebp-70h]
  int v12; // [esp+Ch] [ebp-6Ch]
  int v13; // [esp+14h] [ebp-64h]
  int v14; // [esp+18h] [ebp-60h]
  unsigned int SettlerJobFrameCount; // [esp+20h] [ebp-58h]
  int v16; // [esp+24h] [ebp-54h]
  int v17; // [esp+28h] [ebp-50h]
  char v18; // [esp+30h] [ebp-48h]
  int v19; // [esp+34h] [ebp-44h]
  int v20; // [esp+3Ch] [ebp-3Ch]
  int v21; // [esp+40h] [ebp-38h]
  int v22; // [esp+44h] [ebp-34h]
  unsigned int v23; // [esp+48h] [ebp-30h]
  int v24; // [esp+4Ch] [ebp-2Ch]
  signed int v25; // [esp+50h] [ebp-28h]
  int v26; // [esp+54h] [ebp-24h]
  int LocalPlayerId; // [esp+58h] [ebp-20h]
  char v28; // [esp+60h] [ebp-18h]
  unsigned int v29; // [esp+64h] [ebp-14h]
  signed int v30; // [esp+68h] [ebp-10h]
  unsigned int v31; // [esp+6Ch] [ebp-Ch]

  if ( IEntity::FlagBits((_DWORD *)this, (EntityFlag)&unk_4000000) )
    return 0;
  if ( !IEntity::IsVisible((_DWORD *)this) )
    return 0;
  if ( (unsigned __int8)CInputProcessor::IsBoxSelection(&g_cInputProcessor) )
    IAnimatedEntity::BoxSelection();
  std::auto_ptr<ISettlerRole>::operator->((_DWORD *)(this + 100));
  ISettlerRole::Update((CMFCCaptionButton *)this);
  v29 = IEntity::Race((_BYTE *)this);
  if ( IEntity::FlagBits((_DWORD *)this, (EntityFlag)0x10000000u) )
  {
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    v17 = CAlliances::AllianceId(LocalPlayerId);
    v2 = IEntity::OwnerId((unsigned __int8 *)this);
    if ( CAlliances::AllianceId(v2) == v17 )
    {
      v3 = IEntity::OwnerId((unsigned __int8 *)this);
      v28 = CPlayerManager::Color(v3);
      v31 = *(unsigned __int16 *)(this + 38);
      v30 = *(unsigned __int8 *)(this + 36);
    }
    else
    {
      v4 = IEntity::PackedXY(this);
      v16 = CWorldManager::Index(v4);
      v26 = ITiling::OwnerId(v16);
      if ( v26 )
      {
        v28 = CPlayerManager::Color(v26);
        v29 = CPlayerManager::Race(v26);
      }
      else
      {
        v28 = CPlayerManager::Color(LocalPlayerId);
        v29 = CPlayerManager::Race(LocalPlayerId);
      }
      if ( *(_WORD *)(this + 38) == 303 || *(_WORD *)(this + 38) == 304 )
      {
        if ( v26 )
          v23 = 44;
        else
          v23 = 300;
        v31 = v23;
        v14 = *(unsigned __int8 *)(this + 36);
        SettlerJobFrameCount = CGfxManager::GetSettlerJobFrameCount(
                                 (CGfxManager *)g_pGfxManager,
                                 v29,
                                 *(unsigned __int16 *)(this + 38),
                                 2u);
        v25 = CGfxManager::GetSettlerJobFrameCount((CGfxManager *)g_pGfxManager, v29, v23, 2u);
        v30 = v14 - (int)(SettlerJobFrameCount - v25) / 2;
        if ( v30 >= 0 )
        {
          if ( v30 >= v25 )
            v30 = v25 - 1;
        }
        else
        {
          v30 = 0;
        }
      }
      else
      {
        if ( v26 )
          v22 = *(unsigned __int8 *)(CSettler::Role(this) + 11) + 1;
        else
          v22 = 298;
        v31 = v22;
        v30 = *(unsigned __int8 *)(this + 36);
      }
    }
  }
  else
  {
    if ( IEntity::FlagBits((_DWORD *)this, (EntityFlag)0x8000000u)
      && ((v21 = CSettler::Role(this), (*(int (__thiscall **)(int))(*(_DWORD *)v21 + 72))(v21) == 7)
       || (v20 = CSettler::Role(this), (*(int (__thiscall **)(int))(*(_DWORD *)v20 + 72))(v20) == 23))
      && IEntity::Race((_BYTE *)this) != 3 )
    {
      v13 = CPlayerManager::GetLocalPlayerId();
      v12 = CAlliances::PlayerAllyBits(v13);
      v5 = IEntity::OwnerId((unsigned __int8 *)this);
      if ( (v12 & CAlliances::PlayerAllyBits(v5)) == 0 )
        return 0;
      switch ( IEntity::Type((unsigned __int16 *)this) )
      {
        case 29:
        case 30:
        case 31:
          v31 = 229;
          break;
        case 32:
        case 33:
        case 34:
          v31 = 241;
          break;
        case 35:
        case 36:
        case 37:
          v31 = 257;
          break;
        case 38:
        case 39:
        case 40:
          v31 = 268;
          break;
        case 41:
        case 42:
        case 43:
          v31 = 277;
          break;
        case 44:
          v31 = 286;
          break;
        case 61:
        case 62:
        case 63:
          v31 = 343;
          break;
        default:
          v31 = *(unsigned __int16 *)(this + 38);
          break;
      }
    }
    else
    {
      v31 = *(unsigned __int16 *)(this + 38);
    }
    v6 = IEntity::OwnerId((unsigned __int8 *)this);
    v28 = CPlayerManager::Color(v6);
    v30 = *(unsigned __int8 *)(this + 36);
  }
  v7 = IEntity::EntityId((unsigned __int16 *)this);
  if ( v7 == IHJBMgr::GetHJBEntityId() && (unsigned __int8)IHJBMgr::LocalIsHJBGfxLoaded() )
    v29 = 5;
  CGfxManager::GetSettlerGfxInfo(
    (CGfxManager *)g_pGfxManager,
    (struct SGfxObjectInfo *)&IEntity::m_sGfxInfo,
    v29,
    v31,
    v30,
    *(char *)(this + 68));
  if ( IEntity::FlagBits((_DWORD *)this, (EntityFlag)0x800u) )
  {
    byte_40FE51D = -1;
    dword_40FE268 = (int)*(float *)(std::auto_ptr<ISettlerRole>::operator->((_DWORD *)(this + 100)) + 36);
    dword_40FE26C = (int)*(float *)(std::auto_ptr<ISettlerRole>::operator->((_DWORD *)(this + 100)) + 40);
  }
  else
  {
    byte_40FE51D = *(_BYTE *)(this + 68);
    dword_40FE268 = 0;
    dword_40FE26C = 0;
  }
  byte_40FE266 = 0;
  if ( IEntity::FlagBits((_DWORD *)this, Selected) )
  {
    v8 = std::auto_ptr<ISettlerRole>::operator->((_DWORD *)(this + 100));
    byte_40FE266 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v8 + 108))(v8, this);
    v10 = IEntity::Type((unsigned __int16 *)this);
    v9 = IEntity::Race((_BYTE *)this);
    SettlerInfo = CSettlerMgr::GetSettlerInfo(v9, v10);
    v24 = *(unsigned __int8 *)(SettlerInfo + 2);
    if ( *(_BYTE *)(SettlerInfo + 2) )
    {
      v19 = *(unsigned __int8 *)(this + 33);
      if ( v19 > v24
        && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 1050, "iLivePoints <= iMaxLivePoints") == 1 )
      {
        __debugbreak();
      }
      byte_40FE264 = 9 - 7 * v19 / v24;
    }
  }
  else if ( IEntity::FlagBits((_DWORD *)this, (EntityFlag)0x400u) )
  {
    if ( IEntity::FlagBits((_DWORD *)this, (EntityFlag)0x400u) )
      v18 = 91;
    else
      v18 = 0;
    byte_40FE266 = v18;
  }
  if ( IEntity::FlagBits((_DWORD *)this, (EntityFlag)&dword_ECC2A8[53078]) )
  {
    if ( IEntity::FlagBits((_DWORD *)this, (EntityFlag)0x100000u) )
    {
      byte_40FE265 = 32;
    }
    else if ( IEntity::FlagBits((_DWORD *)this, (EntityFlag)0x200000u) )
    {
      byte_40FE265 = 35;
    }
    else if ( IEntity::FlagBits((_DWORD *)this, (EntityFlag)0x400000u) )
    {
      byte_40FE265 = 33;
    }
    else
    {
      byte_40FE265 = 34;
    }
  }
  byte_40FE51C = *(_BYTE *)(this + 69);
  byte_40FE51A = IEntity::IsVisible((_DWORD *)this);
  byte_40FE51B = v28;
  byte_40FE518 = *(_BYTE *)(this + 10);
  return &IEntity::m_sGfxInfo;
}


// address=[0x157dae0]
// Decompiled from int __thiscall CSettler::GetPatchGfx(CSettler *this, struct SGfxPatchObject *a2)
void  CSettler::GetPatchGfx(struct SGfxPatchObject &) {
  
  int result; // eax
  unsigned int v3; // eax
  unsigned int v4; // [esp-Ch] [ebp-10h]
  unsigned int v5; // [esp-8h] [ebp-Ch]
  unsigned int v7; // [esp-4h] [ebp-8h]

  std::auto_ptr<ISettlerRole>::operator->((_DWORD *)this + 25);
  ISettlerRole::Update(this);
  result = IEntity::FlagBits(this, Visible);
  if ( !result )
    return result;
  v7 = *((char *)this + 68);
  v5 = *((unsigned __int8 *)this + 36);
  v4 = *((unsigned __int16 *)this + 19);
  v3 = IEntity::Race(this);
  CGfxManager::GetPatchSettlerGfxInfo((CGfxManager *)g_pGfxManager, a2, v3, v4, v5, v7);
  *((_DWORD *)a2 + 2) = (int)*(float *)(std::auto_ptr<ISettlerRole>::operator->((_DWORD *)this + 25) + 36);
  result = std::auto_ptr<ISettlerRole>::operator->((_DWORD *)this + 25);
  *((_DWORD *)a2 + 3) = (int)*(float *)(result + 40);
  return result;
}


// address=[0x157db70]
// Decompiled from _DWORD *__thiscall CSettler::NewRole(CSettler *this, int a2)
void  CSettler::NewRole(class std::auto_ptr<class ISettlerRole>) {
  
  int v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-1Ch] BYREF
  int v5; // [esp+8h] [ebp-18h]
  int v6; // [esp+Ch] [ebp-14h]
  int v8; // [esp+1Ch] [ebp-4h]

  v8 = 0;
  if ( IEntity::FlagBits(this, Died) )
  {
    BBSupportTracePrintF(0, "STOP this settler is dead");
    v8 = -1;
    return std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(&a2);
  }
  else
  {
    if ( !std::auto_ptr<ISettlerRole>::get(&this[1].entityId)
      && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 549, "m_pBehavior.get()!=NULL") == 1 )
    {
      __debugbreak();
    }
    IEntity::RemoveFromAllGroups();
    std::auto_ptr<ISettlerRole>::operator=(&a2);
    v6 = std::auto_ptr<ISettlerRole>::operator->(&this[1].entityId);
    (*(void (__thiscall **)(int, CSettler *))(*(_DWORD *)v6 + 44))(v6, this);
    v5 = std::auto_ptr<ISettlerRole>::operator->(&this[1].entityId);
    v3 = (*(int (__thiscall **)(int, CSettler *))(*(_DWORD *)v5 + 20))(v5, this);
    std::auto_ptr<CWalking>::auto_ptr<CWalking>(v3);
    std::auto_ptr<CWalking>::operator=(v4);
    std::auto_ptr<CWalking>::~auto_ptr<CWalking>(v4);
    v8 = -1;
    return std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(&a2);
  }
}


// address=[0x157dca0]
// Decompiled from int __thiscall CSettler::NewToDoList(_BYTE *this, int a2, __int16 a3)
void  CSettler::NewToDoList(class std::list<class CEntityTask,class std::allocator<class CEntityTask> > *,int) {
  
  int result; // eax
  int v4; // eax
  int v5; // [esp-4h] [ebp-30h]
  _BYTE v6[12]; // [esp+4h] [ebp-28h] BYREF
  int v7; // [esp+10h] [ebp-1Ch]
  int v8; // [esp+14h] [ebp-18h]
  int v9; // [esp+18h] [ebp-14h]
  _BYTE *v10; // [esp+1Ch] [ebp-10h]
  int v11; // [esp+28h] [ebp-4h]

  v10 = this;
  if ( IEntity::FlagBits(this, Died) )
    return BBSupportTracePrintF(0, "STOP this settler is dead");
  if ( a2 )
  {
    *((_WORD *)v10 + 36) = a3;
    *((_DWORD *)v10 + 21) = a2;
    v8 = std::list<CEntityTask>::begin(v6);
    v7 = v8;
    v11 = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=(v8);
    v11 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v6);
    v9 = std::auto_ptr<ISettlerRole>::operator->((_DWORD *)v10 + 25);
    return (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v9 + 40))(v9, v10);
  }
  else
  {
    v5 = IEntity::Type((unsigned __int16 *)v10);
    v4 = IEntity::Race(v10);
    result = CEntityToDoListMgr::SettlerJobList(v4, v5);
    if ( result )
      return CSettler::TakeWaitList(v10);
  }
  return result;
}


// address=[0x157dda0]
// Decompiled from int __thiscall CSettler::TakeWaitList(CSettler *this)
void  CSettler::TakeWaitList(void) {
  
  int v1; // eax
  int v2; // eax
  int v4; // [esp-8h] [ebp-Ch]
  int v5; // [esp-4h] [ebp-8h]

  v5 = IEntity::Type((unsigned __int16 *)this);
  v4 = IEntity::Type((unsigned __int16 *)this);
  v1 = IEntity::Race(this);
  v2 = CEntityToDoListMgr::SettlerJobList(v1, v4);
  return (*(int (__thiscall **)(CSettler *, int, int))(*(_DWORD *)this + 112))(this, v2, v5);
}


// address=[0x157dde0]
// Decompiled from int __thiscall CSettler::TakeAnimList(CSettler *this, int a2)
void  CSettler::TakeAnimList(int) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v6; // [esp-4h] [ebp-18h]
  int v7; // [esp-4h] [ebp-18h]
  int v8; // [esp+0h] [ebp-14h]
  int v9; // [esp+4h] [ebp-10h]
  int v10; // [esp+8h] [ebp-Ch]
  int SettlerInfo; // [esp+Ch] [ebp-8h]

  v6 = IEntity::Type((unsigned __int16 *)this);
  v2 = IEntity::Race(this);
  SettlerInfo = CSettlerMgr::GetSettlerInfo(v2, v6);
  v8 = std::vector<unsigned short>::size(SettlerInfo + 24);
  if ( (a2 < 0 || a2 >= v8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\Settler.cpp",
         804,
         "(_iAnimListIndex >= 0) && (_iAnimListIndex < iNumberOfAnimLists)") == 1 )
  {
    __debugbreak();
  }
  v10 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](a2);
  v3 = IEntity::Race(this);
  v9 = CEntityToDoListMgr::SettlerJobList(v3, v10);
  if ( v9 )
    return (*(int (__thiscall **)(CSettler *, int, int))(*(_DWORD *)this + 112))(this, v9, v10);
  v7 = IEntity::Type((unsigned __int16 *)this);
  v4 = IEntity::Race(this);
  if ( BBSupportDbgReportF(
         2,
         "MapObjects\\Settler\\Settler.cpp",
         810,
         "No work list -> Data Wizard! Race %d, SettlerType %d",
         v4,
         v7) == 1 )
    __debugbreak();
  return (*(int (__thiscall **)(CSettler *, int, int))(*(_DWORD *)this + 112))(this, v9, v10);
}


// address=[0x157ded0]
// Decompiled from int __thiscall CSettler::AttachToBuilding(CSettler *this, int a2)
void  CSettler::AttachToBuilding(int) {
  
  int v2; // eax
  int result; // eax
  int v4; // [esp+0h] [ebp-8h]

  if ( *(_WORD *)(std::auto_ptr<ISettlerRole>::operator->((_DWORD *)this + 25) + 32)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 1388, "m_pBehavior->m_uHomeEntityId == 0") == 1 )
  {
    __debugbreak();
  }
  v4 = CBuildingMgr::operator[](a2);
  v2 = IEntity::EntityId((unsigned __int16 *)this);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 116))(v4, v2);
  result = IEntity::FlagBits(this, Attached);
  if ( result )
    return result;
  result = BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 1397, "FlagBits(ENTITY_FLAG_ATTACHED) != 0");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x157df70]
// Decompiled from int __thiscall CSettler::CheckFlee(CSettler *this, int a2)
void  CSettler::CheckFlee(int) {
  
  return IEntity::WarriorType();
}


// address=[0x157df90]
// Decompiled from void __thiscall CSettler::ChangeType(IEntity *this, unsigned int newSettlerType, char a3, char a4)
void  CSettler::ChangeType(int,bool,bool) {
  
  int worldIdx; // eax
  int sectorOwner; // esi MAPDST
  int v8; // eax
  int owner; // eax
  int HJBPlayerId; // esi
  struct CFrameWnd *v12; // eax
  unsigned int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int race; // eax MAPDST
  CSettlerMgr::SSettlerInfos *settlerInfo; // eax MAPDST
  int v20; // eax
  int v21; // [esp-Ch] [ebp-60h]
  int v22; // [esp-8h] [ebp-5Ch]
  int type; // [esp-4h] [ebp-58h] MAPDST BYREF
  int aiEvent; // [esp-4h] [ebp-58h] SPLIT
  int *v25; // [esp+8h] [ebp-4Ch]
  int *p_type; // [esp+Ch] [ebp-48h]
  unsigned int v27; // [esp+10h] [ebp-44h]
  struct ISettlerRole *v28; // [esp+14h] [ebp-40h]
  int v29; // [esp+18h] [ebp-3Ch]
  int v31; // [esp+20h] [ebp-34h] BYREF
  struct ISettlerRole *v32; // [esp+24h] [ebp-30h]
  void *C; // [esp+28h] [ebp-2Ch]
  unsigned int unk_5; // [esp+30h] [ebp-24h]
  int role; // [esp+34h] [ebp-20h] MAPDST
  struct ISettlerRole *SettlerRole; // [esp+38h] [ebp-1Ch]
  int v38; // [esp+3Ch] [ebp-18h]
  unsigned __int16 *ecoSector; // [esp+40h] [ebp-14h]
  int v41; // [esp+50h] [ebp-4h]

  if ( IEntity::FlagBits(this, Died) )
  {
    BBSupportTracePrintF(0, "STOP this settler is dead");
  }
  else
  {
    if ( IEntity::Type(this) == newSettlerType
      && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 577, "Type() != _iNewSettlerType") == 1 )
    {
      __debugbreak();
    }
    if ( IEntity::FlagBits(this, Offered)
      && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 579, "!FlagBits(ENTITY_FLAG_OFFERED)") == 1 )
    {
      __debugbreak();
    }
    role = CSettler::Role((CSettler *)this);
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)role + 72))(role) == 18
      && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 580, "Role().GetSettlerRole() != FLEE_ROLE") == 1 )
    {
      __debugbreak();
    }
    worldIdx = IEntity::WorldIdx();
    v38 = CWorldManager::EcoSectorId(worldIdx);
    if ( !v38 && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 583, "iESId != 0") == 1 )
      __debugbreak();
    if ( v38 )
    {
      ecoSector = (unsigned __int16 *)CEcoSectorMgr::operator[](g_cESMgr, v38);
      sectorOwner = CEcoSector::Owner(ecoSector);
      if ( sectorOwner != IEntity::OwnerId(this)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 587, "rEcoSector.Owner() == OwnerId()") == 1 )
      {
        __debugbreak();
      }
      sectorOwner = CEcoSector::Owner(ecoSector);
      if ( sectorOwner == IEntity::OwnerId(this) )
      {
        if ( newSettlerType == 1 )
        {
          type = IEntity::Type(this);
          race = IEntity::Race(this);
          settlerInfo = CSettlerMgr::GetSettlerInfo(race, type);
          unk_5 = settlerInfo->unk_5;
          if ( unk_5 )
          {
            v21 = IEntity::Y(this);
            v8 = IEntity::X(this);
            CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v8, v21, unk_5, 1u);
          }
          if ( IEntity::WarriorType() )
            CSettlerMgr::DetachSettler((int *)g_cSettlerMgr, (unsigned __int8 *)this);
        }
        type = IEntity::Type(this);
        owner = IEntity::OwnerId(this);
        CSettlerMgr::DecNumberOfSettler((CSettlerMgr *)g_cSettlerMgr, owner, type);
        if ( !IEntity::WarriorType() )
        {
          type = IEntity::Type(this);
          CEcoSector::ChangeNrOfSettler((CEcoSector *)ecoSector, type, -1);
        }
        role = CSettler::Role((CSettler *)this);
        if ( (*(int (__thiscall **)(int))(*(_DWORD *)role + 72))(role) == 19 )
          CSettler::SetFree((CSettler *)this);
        v27 = IEntity::Type(this);
        CWarMap::RemoveEntity(this);
        this->type = newSettlerType;
        v29 = CSettlerMgr::SettlerWarriorType(this->type);
        *(_DWORD *)&this->warriorType &= 0xFFFFFFF0;
        *(_DWORD *)&this->warriorType |= v29;
        *(_DWORD *)&this->warriorType &= ~0x10000000u;
        CWarMap::AddEntity(this);
        SettlerRole = 0;
        if ( IHJBMgr::GetHJBPlayerId()
          && (HJBPlayerId = IHJBMgr::GetHJBPlayerId(), HJBPlayerId == IEntity::OwnerId(this))
          && !IHJBMgr::GetHJBEntityId()
          && newSettlerType == 44 )
        {
          v12 = (struct CFrameWnd *)IEntity::EntityId(this);
          IHJBMgr::SetHJBEntityId(v12);
          C = operator new(0x80u);
          v41 = 0;
          if ( C )
            v32 = (struct ISettlerRole *)CHJBRole::CHJBRole(C);
          else
            v32 = 0;
          v28 = v32;
          v41 = -1;
          SettlerRole = v32;
        }
        else
        {
          v13 = IEntity::Race(this);
          SettlerRole = CSettlerMgr::CreateSettlerRole((CSettlerMgr *)g_cSettlerMgr, v13, newSettlerType);
        }
        std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(&v31, (int)SettlerRole);
        v41 = 1;
        type = v14;
        p_type = &type;
        v25 = std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(&type, &v31);
        CSettler::NewRole(this, type);
        if ( a3 )
          CSettler::TakeWaitList(this);
        type = IEntity::Type(this);
        v15 = IEntity::OwnerId(this);
        CSettlerMgr::IncNumberOfSettler((CSettlerMgr *)g_cSettlerMgr, v15, type);
        if ( IEntity::WarriorType() )
        {
          CSettlerMgr::AttachSettler((CSettlerMgr *)g_cSettlerMgr, this);
          if ( IEntity::FlagBits(this, (EntityFlag)0x400u) )
          {
            IEntity::ClearFlagBits(this, (EntityFlag)0x400u);
            IEntity::SetFlagBits(this, Selected);
          }
        }
        else
        {
          type = 1;
          v16 = IEntity::Type(this);
          CEcoSector::ChangeNrOfSettler((CEcoSector *)ecoSector, v16, type);
          if ( a4 )
          {
            type = IEntity::EntityId(this);
            v17 = IEntity::Type(this);
            CEcoSector::SetSettlerOffer(ecoSector, v17, type);
          }
        }
        type = IEntity::Type(this);
        race = IEntity::Race(this);
        settlerInfo = CSettlerMgr::GetSettlerInfo(race, type);
        this->health = settlerInfo->maxHitpoints;
        aiEvent = CAIEvent::Pack(v27, newSettlerType);
        v22 = IEntity::ID(this);
        v20 = IEntity::OwnerId(this);
        (*(void (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(
          off_3D7A3D8,
          22,
          v20,
          v22,
          aiEvent);
        v41 = -1;
        std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(&v31);
      }
    }
  }
}


// address=[0x157e450]
// Decompiled from int __thiscall CSettler::ChangeTypeComeToBuilding(CSettler *this, int a2, int a3)
void  CSettler::ChangeTypeComeToBuilding(int,int) {
  
  int result; // eax
  _BYTE v4[24]; // [esp+4h] [ebp-30h] BYREF
  CEntityEvent *v5; // [esp+1Ch] [ebp-18h]
  CEntityEvent *v6; // [esp+20h] [ebp-14h]
  CPropertySet *v7; // [esp+24h] [ebp-10h]
  int v8; // [esp+30h] [ebp-4h]

  v7 = this;
  result = IEntity::FlagBits(this, (EntityFlag)&unk_4000000);
  if ( result )
    return result;
  CSettler::ChangeType(v7, a2, 1, 0);
  CSettler::SetBuilding(v7, a3);
  v6 = CEntityEvent::CEntityEvent((CEntityEvent *)v4, 1u, 0, a3, 0, 0);
  v5 = v6;
  v8 = 0;
  (*(void (__thiscall **)(CPropertySet *, CEntityEvent *))(*(_DWORD *)v7 + 80))(v7, v6);
  v8 = -1;
  return CEntityEvent::~CEntityEvent(v4);
}


// address=[0x157e500]
// Decompiled from unsigned int __cdecl CSettler::operator new(unsigned int a1)
static void * __cdecl CSettler::operator new(unsigned int) {
  
  return CSettlerMgr::Alloc((CSettlerMgr *)g_cSettlerMgr, a1);
}


// address=[0x157e520]
// Decompiled from void __cdecl CSettler::operator delete(void *a1)
static void __cdecl CSettler::operator delete(void *) {
  
  CSettlerMgr::Dealloc((CSettlerMgr *)g_cSettlerMgr, a1);
}


// address=[0x157e560]
// Decompiled from int __thiscall CSettler::SetObserverTarget(_DWORD *this, int a2, int a3)
void  CSettler::SetObserverTarget(enum T_OBSERVER_TARGET,int) {
  
  int v3; // eax
  int result; // eax
  unsigned int v5; // ecx

  v3 = std::auto_ptr<ISettlerRole>::operator->(this + 25);
  result = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)v3 + 80))(v3, a2, a3);
  if ( a2 )
    return result;
  result = (int)this;
  if ( a3 <= 0 )
    v5 = this[5] & 0xFFFFFFDF;
  else
    v5 = this[5] | 0x20;
  this[5] = v5;
  return result;
}


// address=[0x157e5c0]
// Decompiled from int __thiscall CSettler::GetObserverTarget(_DWORD *this, int a2)
int  CSettler::GetObserverTarget(enum T_OBSERVER_TARGET) {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = std::auto_ptr<ISettlerRole>::operator->(this + 25);
  return (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 84))(v3, a2);
}


// address=[0x157e5f0]
// Decompiled from int __thiscall CSettler::Increase(IEntity *this, int a2)
int  CSettler::Increase(int) {
  
  int v3; // [esp+8h] [ebp-14h]
  int v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+10h] [ebp-Ch]
  int maxHitpoints; // [esp+14h] [ebp-8h]

  v3 = IEntity::Race(this);
  v4 = IEntity::Type(this);
  maxHitpoints = CSettlerMgr::GetSettlerInfo(v3, v4)->maxHitpoints;
  if ( a2 >= 0 )
  {
    v5 = a2 + this->health;
    if ( v5 > maxHitpoints )
      this->health = maxHitpoints;
    else
      this->health = v5;
  }
  else
  {
    this->health = maxHitpoints;
  }
  return this->health;
}


// address=[0x157e680]
// Decompiled from int __thiscall CSettler::MarkSourcePile2AsUnused(CSettler *this)
void  CSettler::MarkSourcePile2AsUnused(void) {
  
  int v1; // eax

  v1 = std::auto_ptr<ISettlerRole>::operator->((_DWORD *)this + 25);
  return ISettlerRole::MarkPileAsUnused(v1, 3);
}


// address=[0x157e6a0]
// Decompiled from int __thiscall CSettler::MarkSourcePile3AsUnused(CSettler *this)
void  CSettler::MarkSourcePile3AsUnused(void) {
  
  int v1; // eax

  v1 = std::auto_ptr<ISettlerRole>::operator->((_DWORD *)this + 25);
  return ISettlerRole::MarkPileAsUnused(v1, 4);
}


// address=[0x157e6c0]
// Decompiled from int __thiscall CSettler::MaxHitpoints(CSettler *this)
int  CSettler::MaxHitpoints(void)const {
  
  int race; // [esp+4h] [ebp-Ch]
  int type; // [esp+8h] [ebp-8h]

  race = IEntity::Race(this);
  type = IEntity::Type(this);
  return CSettlerMgr::GetSettlerInfo(race, type)->maxHitpoints;
}


// address=[0x157e700]
// Decompiled from _DWORD *__thiscall CSettler::CSettler(_DWORD *this, int a2)
 CSettler::CSettler(std::istream &) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  __int16 v6; // ax
  int v7; // eax
  int v8; // eax
  __int16 v9; // ax
  int v10; // eax
  int v11; // eax
  int v13; // [esp-8h] [ebp-78h]
  int v14; // [esp-4h] [ebp-74h]
  int v15; // [esp-4h] [ebp-74h]
  int v16; // [esp-4h] [ebp-74h]
  int v17; // [esp-4h] [ebp-74h]
  int v18; // [esp-4h] [ebp-74h]
  _BYTE v19[12]; // [esp+4h] [ebp-6Ch] BYREF
  _BYTE v20[12]; // [esp+10h] [ebp-60h] BYREF
  _BYTE v21[12]; // [esp+1Ch] [ebp-54h] BYREF
  int v22; // [esp+28h] [ebp-48h]
  int v23; // [esp+2Ch] [ebp-44h]
  int v24; // [esp+30h] [ebp-40h]
  int v25; // [esp+34h] [ebp-3Ch]
  int v26; // [esp+38h] [ebp-38h]
  int v27; // [esp+3Ch] [ebp-34h]
  int SettlerRole; // [esp+40h] [ebp-30h]
  int v29; // [esp+44h] [ebp-2Ch]
  int v30; // [esp+48h] [ebp-28h] BYREF
  _BYTE v31[4]; // [esp+4Ch] [ebp-24h] BYREF
  int v32; // [esp+50h] [ebp-20h]
  int pExceptionObject; // [esp+54h] [ebp-1Ch] BYREF
  _DWORD *v34; // [esp+58h] [ebp-18h]
  _WORD v35[3]; // [esp+5Ch] [ebp-14h] BYREF
  unsigned __int8 v36; // [esp+62h] [ebp-Eh] BYREF
  char v37; // [esp+63h] [ebp-Dh] BYREF
  int v38; // [esp+6Ch] [ebp-4h]

  v34 = this;
  IMovingEntity::IMovingEntity(this, a2);
  v38 = 0;
  *v34 = &CSettler::_vftable_;
  std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(0);
  LOBYTE(v38) = 1;
  v37 = 0;
  operator^<unsigned int>(a2, &v30);
  v29 = v30;
  if ( v30 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CSettler");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<short>(a2, v35);
  if ( v35[0] != -1 )
    operator^<unsigned char>(a2, &v37);
  operator^<unsigned char>(a2, &v36);
  SettlerRole = CSettlerMgr::LoadSettlerRole(a2, v36);
  std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(SettlerRole);
  LOBYTE(v38) = 2;
  std::auto_ptr<ISettlerRole>::operator=(v31);
  if ( v35[0] == -1 )
  {
    v9 = IEntity::Type((unsigned __int16 *)v34);
    *((_WORD *)v34 + 36) = v9;
    v18 = IEntity::Type((unsigned __int16 *)v34);
    v10 = IEntity::Race(v34);
    v11 = CEntityToDoListMgr::SettlerJobList(v10, v18);
    v34[21] = v11;
    v23 = std::list<CEntityTask>::begin(v19);
    v22 = v23;
    LOBYTE(v38) = 5;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=(v23);
    LOBYTE(v38) = 2;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v19);
  }
  else
  {
    *((_WORD *)v34 + 36) = v35[0];
    v14 = v35[0];
    v2 = IEntity::Race(v34);
    v3 = CEntityToDoListMgr::SettlerJobList(v2, v14);
    v34[21] = v3;
    if ( !v34[21] )
    {
      v15 = IEntity::Type((unsigned __int16 *)v34);
      v4 = IEntity::Race(v34);
      if ( BBSupportDbgReportF(
             2,
             "MapObjects\\Settler\\Settler.cpp",
             348,
             "No ToDoList -> Outdated Savegame? Race:%u, Type:%u",
             v4,
             v15) == 1 )
        __debugbreak();
    }
    if ( v34[21] )
    {
      v27 = std::list<CEntityTask>::begin(v21);
      v26 = v27;
      LOBYTE(v38) = 3;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=(v27);
      LOBYTE(v38) = 2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v21);
      while ( v37 )
      {
        std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v34 + 22);
        --v37;
      }
    }
    else
    {
      v16 = IEntity::ID();
      v13 = v35[0];
      v5 = IEntity::Race(v34);
      BBSupportTracePrintF(3, "Can't find doDoList for race=%d,id=%d, for EntityID = %d", v5, v13, v16);
      v6 = IEntity::Type((unsigned __int16 *)v34);
      *((_WORD *)v34 + 36) = v6;
      v17 = IEntity::Type((unsigned __int16 *)v34);
      v7 = IEntity::Race(v34);
      v8 = CEntityToDoListMgr::SettlerJobList(v7, v17);
      v34[21] = v8;
      v25 = std::list<CEntityTask>::begin(v20);
      v24 = v25;
      LOBYTE(v38) = 4;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=(v25);
      LOBYTE(v38) = 2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v20);
    }
  }
  v32 = std::auto_ptr<ISettlerRole>::operator->(v34 + 25);
  (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v32 + 12))(v32, v34);
  if ( !std::list<CEntityTask>::size((void *)v34[21])
    && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 377, "m_toDoList->size()>0") == 1 )
  {
    __debugbreak();
  }
  LOBYTE(v38) = 1;
  std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(v31);
  return v34;
}


// address=[0x157ea60]
// Decompiled from void __thiscall CSettler::Store(CSettler *this, struct std::ostream *a1)
void  CSettler::Store(std::ostream &) {
  
  _BYTE v2[12]; // [esp+4h] [ebp-44h] BYREF
  _BYTE v3[12]; // [esp+10h] [ebp-38h] BYREF
  std::_Iterator_base12 *v4; // [esp+1Ch] [ebp-2Ch]
  std::_Iterator_base12 *v5; // [esp+20h] [ebp-28h]
  int v6; // [esp+24h] [ebp-24h] BYREF
  int v7; // [esp+28h] [ebp-20h]
  int v8; // [esp+2Ch] [ebp-1Ch]
  int v9; // [esp+30h] [ebp-18h]
  CSettler *v10; // [esp+34h] [ebp-14h]
  char v11; // [esp+39h] [ebp-Fh]
  BYTE a2[10]; // [esp+3Ah] [ebp-Eh] BYREF
  int v13; // [esp+44h] [ebp-4h]

  v10 = this;
  IMovingEntity::Store(this, a1);
  v6 = 1;
  operator^<unsigned int>(a1, &v6);
  operator^<short>(a1, &v10->unk_48);
  if ( v10->unk_48 != -1 )
  {
    a2[1] = 0;
    std::list<CEntityTask>::begin((void *)v10->entityTasks, (int)v3);
    v13 = 0;
    while ( 1 )
    {
      v5 = (std::_Iterator_base12 *)std::list<CEntityTask>::end(v2);
      v4 = v5;
      LOBYTE(v13) = 1;
      v11 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=(v5);
      LOBYTE(v13) = 0;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v2);
      if ( !v11
        || (unsigned __int8)std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator==((std::_Iterator_base12 *)&v10->unk_58) )
      {
        break;
      }
      ++a2[1];
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v3);
    }
    v13 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v3);
    operator^<unsigned char>(a1, &a2[1]);
  }
  v9 = std::auto_ptr<ISettlerRole>::operator->(&v10->role);
  a2[0] = (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 72))(v9);
  if ( a2[0] == 23 )
  {
    v8 = std::auto_ptr<ISettlerRole>::get(&v10->role);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 132))(v8) )
      a2[0] = 24;
  }
  operator^<unsigned char>(a1, a2);
  v7 = std::auto_ptr<ISettlerRole>::operator->(&v10->role);
  (*(void (__cdecl **)(struct std::ostream *))(*(_DWORD *)v7 + 4))(a1);
}


// address=[0x157ff80]
// Decompiled from int __thiscall CSettler::ClassID(CSettler *this)
unsigned long  CSettler::ClassID(void)const {
  
  return CSettler::m_iClassID;
}


// address=[0x157ffa0]
// Decompiled from int __thiscall CSettler::ClearGroupFlagBits(CSettler *this, int a2)
int  CSettler::ClearGroupFlagBits(int) {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = std::auto_ptr<ISettlerRole>::operator->((_DWORD *)this + 25);
  return (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 104))(v3, a2);
}


// address=[0x1580040]
// Decompiled from int __thiscall CSettler::GetGroupFlags(CSettler *this)
int  CSettler::GetGroupFlags(void)const {
  
  int v1; // eax

  v1 = std::auto_ptr<ISettlerRole>::operator->((_DWORD *)this + 25);
  return (*(int (__thiscall **)(int, CSettler *, int))(*(_DWORD *)v1 + 92))(v1, this, v1);
}


// address=[0x1580080]
// Decompiled from int __thiscall CSettler::GetWarriorBehavior(void *this)
class CWarriorBehavior *  CSettler::GetWarriorBehavior(void)const {
  
  int v2; // [esp+4h] [ebp-4h]

  v2 = ((_DWORD (__cdecl *)(_DWORD))std::auto_ptr<ISettlerRole>::operator->)(this);
  return (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 88))(v2);
}


// address=[0x15800c0]
// Decompiled from int __thiscall CSettler::IsUnEmployed(CSettler *this)
bool  CSettler::IsUnEmployed(void)const {
  
  int v1; // eax

  v1 = std::auto_ptr<ISettlerRole>::operator->((_DWORD *)this + 25);
  return (*(int (__thiscall **)(int, CSettler *, int))(*(_DWORD *)v1 + 76))(v1, this, v1);
}


// address=[0x1580130]
// Decompiled from int __thiscall CSettler::SetGroupFlagBits(CSettler *this, int a2)
int  CSettler::SetGroupFlagBits(int) {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = std::auto_ptr<ISettlerRole>::operator->((_DWORD *)this + 25);
  return (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 100))(v3, a2);
}


// address=[0x1580170]
// Decompiled from int __thiscall CSettler::SetGroupFlags(CSettler *this, int a2)
int  CSettler::SetGroupFlags(int) {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = std::auto_ptr<ISettlerRole>::operator->((_DWORD *)this + 25);
  return (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 96))(v3, a2);
}


// address=[0x3d8befc]
// [Decompilation failed for static unsigned long CSettler::m_iClassID]

// address=[0x157ec10]
// Decompiled from CSettler *__thiscall CSettler::CSettler(  CSettler *this,  int posX,  int posY,  int settlerType,  int player,  struct ISettlerRole *settlerRole,  int id)
 CSettler::CSettler(int,int,int,int,class std::auto_ptr<class ISettlerRole>,int) {
  
  CPlayerInfo *playerInfo; // eax
  unsigned __int8 race; // al
  int race2; // eax
  int worldIdx; // eax
  int v11; // eax
  int v13; // [esp+Ch] [ebp-24h] BYREF
  struct ISettlerRole *v14; // [esp+10h] [ebp-20h]
  int ecoSectorId; // [esp+18h] [ebp-18h]
  unsigned __int16 *ecoSector; // [esp+1Ch] [ebp-14h]
  int v19; // [esp+2Ch] [ebp-4h]

  v19 = 0;
  IMovingEntity::IMovingEntity(this, id);
  this->__vftable = (CSettler_vtbl *)&CSettler::_vftable_;
  std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(
    (auto_ptr_ISettlerRole *)&this->role,
    (auto_ptr_ISettlerRole *)&settlerRole);
  LOBYTE(v19) = 2;
  IMessageTracer::PushFormatedInts(
    g_pMsgTracer,
    "CSettler::CSettler(): entity id %u, player %u, settler type %u, position (%i, %i)",
    id,
    player,
    settlerType,
    posX,
    posY);
  this->unk_45 = 0;
  IEntity::SetPosition(this, posX, posY);
  this->objType = Settler;
  this->type = settlerType;
  this->someRandomNumber = (unsigned int)CGameData::Rand(g_pGameData) % 6;
  IEntity::SetOwnerId(this, player);
  playerInfo = CPlayerManager::PlayerInfo(player);
  race = CPlayerInfo::Race(playerInfo);
  IEntity::SetRace(this, race);
  race2 = IEntity::Race(this);
  this->health = CSettlerMgr::GetSettlerInfo(race2, settlerType)->maxHitpoints;
  IEntity::ClearFlagBits(this, (EntityFlag)0x2800u);
  IEntity::SetFlagBits(this, Ready|Visible|0x1000);
  *(_DWORD *)&this->warriorType |= CSettlerMgr::SettlerWarriorType(settlerType);
  if ( !IEntity::WarriorType() )
  {
    worldIdx = IEntity::WorldIdx();
    ecoSectorId = CWorldManager::EcoSectorId(worldIdx);
    if ( ecoSectorId )
    {
      ecoSector = (unsigned __int16 *)CEcoSectorMgr::operator[](g_cESMgr, ecoSectorId);
      if ( CEcoSector::Owner(ecoSector) == player )
      {
        CEcoSector::ChangeNrOfSettler((CEcoSector *)ecoSector, this->type, 1);
        if ( IEntity::Type(this) != 1 )
          CEcoSector::SetSettlerOffer(ecoSector, this->type, this->entityId);
      }
    }
  }
  if ( CWorldManager::MapObjectId(posX, posY)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\Settler.cpp", 112, "g_cWorld.MapObjectId(_iX, _iY) == 0") == 1 )
  {
    __debugbreak();
  }
  CWorldManager::SetSettlerId(posX, posY, this->entityId);
  IMovingEntity::SetDisplacementCosts(this, 0);
  settlerRole = std::auto_ptr<ISettlerRole>::operator->(&this->role);
  v11 = ((int (__thiscall *)(struct ISettlerRole *, CSettler *))settlerRole->__vftable[1].dtor)(settlerRole, this);
  std::auto_ptr<CWalking>::auto_ptr<CWalking>(&v13, v11);
  LOBYTE(v19) = 3;
  std::auto_ptr<CWalking>::operator=(&v13);
  v14 = std::auto_ptr<ISettlerRole>::operator->(&this->role);
  ((void (__thiscall *)(struct ISettlerRole *, CSettler *))v14->__vftable[2].PostLoadInit)(v14, this);
  CSettler::TakeWaitList(this);
  LOBYTE(v19) = 2;
  std::auto_ptr<CWalking>::~auto_ptr<CWalking>(&v13);
  v19 = -1;
  std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>((auto_ptr_ISettlerRole *)&settlerRole);
  return this;
}


// address=[0x157eec0]
// Decompiled from CSettler *__thiscall CSettler::CSettler(CSettler *this, __int16 a2, int a3)
 CSettler::CSettler(int,int) {
  
  IMovingEntity::IMovingEntity(this, a3);
  *(_DWORD *)this = &CSettler::_vftable_;
  std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(0);
  *((_BYTE *)this + 69) = 0;
  *((_BYTE *)this + 10) = 0;
  *((_WORD *)this + 6) = a2;
  IEntity::ClearFlagBits(this, VulnerableMask|Selectable|Visible|0x800);
  *((_DWORD *)this + 5) = *((_DWORD *)this + 5);
  *((_BYTE *)this + 70) = 5;
  return this;
}


// address=[0x157ef70]
// Decompiled from int __thiscall CSettler::CSettler(int this, int a2, int a3, int a4, char a5, int a6)
 CSettler::CSettler(int,int,int,class std::auto_ptr<class ISettlerRole>,int) {
  
  void *v6; // eax
  unsigned __int8 v7; // al
  int v8; // eax
  int v9; // eax
  int v10; // eax

  IMovingEntity::IMovingEntity((IMovingEntity *)this, a6);
  *(_DWORD *)this = &CSettler::_vftable_;
  std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(&a5);
  *(_BYTE *)(this + 69) = 0;
  IEntity::SetPosition((IEntity *)this, a2, a3);
  CWorldManager::SetSettlerId(a2, a3, a6);
  *(_BYTE *)(this + 10) = 1;
  *(_WORD *)(this + 12) = 69;
  IEntity::SetOwnerId((IEntity *)this, a4);
  v6 = (void *)CPlayerManager::PlayerInfo(a4);
  v7 = CPlayerInfo::Race(v6);
  IEntity::SetRace((IEntity *)this, v7);
  IEntity::ClearFlagBits((_DWORD *)this, (EntityFlag)0x22900u);
  IEntity::SetFlagBits((_DWORD *)this, (EntityFlag)((char *)&loc_200FFFD + 3));
  *(_DWORD *)(this + 20) |= 0xDu;
  *(_BYTE *)(this + 70) = 10;
  CWarMap::AddEntity((CPropertySet *)this);
  v8 = std::auto_ptr<ISettlerRole>::operator->((_DWORD *)(this + 100));
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 44))(v8, this);
  v9 = IEntity::Race((_BYTE *)this);
  v10 = CEntityToDoListMgr::SettlerJobList(v9, 1);
  CSettler::NewToDoList(v10, 1);
  std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(&a5);
  return this;
}


// address=[0x157f0e0]
// Decompiled from void __thiscall CSettler::~CSettler(CSettler *this)
 CSettler::~CSettler(void) {
  
  *(_DWORD *)this = &CSettler::_vftable_;
  std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>((char *)this + 100);
  IMovingEntity::~IMovingEntity(this);
}


// address=[0x157f110]
// Decompiled from unsigned int __thiscall CSettler::Walk(CSettler *this)
int  CSettler::Walk(void) {
  
  int v2; // eax
  int v3; // eax
  int v4; // [esp+0h] [ebp-8h]

  if ( IEntity::FlagBits(this, Died) )
  {
    BBSupportTracePrintF(0, "STOP this settler is dead");
    return -1;
  }
  else if ( std::auto_ptr<CWalking>::get(&this->walking) )
  {
    v4 = std::auto_ptr<CWalking>::operator->(&this->walking);
    v2 = IEntity::PackedXY(this);
    v3 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v4 + 12))(v4, v2);
    return CSettler::WalkDir(this, v3);
  }
  else
  {
    return 72;
  }
}


// address=[0x157f190]
// Decompiled from unsigned int __thiscall CSettler::WalkDir(CSettler *this, int a2)
int  CSettler::WalkDir(int) {
  
  int v3; // esi
  int v4; // eax
  CWalking *v5; // eax
  int v6; // eax
  CWalking *v7; // eax
  int v8; // [esp-4h] [ebp-60h]
  int v9; // [esp-4h] [ebp-60h]
  int v10; // [esp+8h] [ebp-54h]
  int v11; // [esp+Ch] [ebp-50h]
  int TickCounter; // [esp+10h] [ebp-4Ch]
  int v13; // [esp+14h] [ebp-48h]
  int v14; // [esp+18h] [ebp-44h]
  int v15; // [esp+1Ch] [ebp-40h]
  int v16; // [esp+20h] [ebp-3Ch]
  int v17; // [esp+24h] [ebp-38h]
  int v18; // [esp+30h] [ebp-2Ch]
  int v19; // [esp+38h] [ebp-24h]
  int v20; // [esp+3Ch] [ebp-20h]
  int v21; // [esp+40h] [ebp-1Ch]
  int v22; // [esp+44h] [ebp-18h]
  int v23; // [esp+48h] [ebp-14h]
  Y16X16 *v24; // [esp+4Ch] [ebp-10h]
  int v25; // [esp+50h] [ebp-Ch]

  if ( IEntity::FlagBits(this, (EntityFlag)&unk_4000000) )
  {
    BBSupportTracePrintF(0, "STOP this settler is dead");
    return -1;
  }
  else
  {
    v24 = (Y16X16 *)(a2 & 0xF);
    if ( (unsigned int)v24 < 6 )
    {
      v22 = IEntity::PackedXY(this);
      v23 = CWorldManager::Index(v22);
      v3 = IEntity::PackedXY(this);
      v18 = Y16X16::NeighborModifier(v24) + v3;
      v19 = CWorldManager::Index(v18);
      TickCounter = CGameData::GetTickCounter(g_pGameData);
      v21 = IEntity::ID();
      v13 = IEntity::X(this);
      v14 = IEntity::Y(this);
      IEntity::WorldIdx();
      v15 = IEntity::OwnerId((unsigned __int8 *)this);
      v16 = IEntity::Race(this);
      v20 = CWorldManager::MapObjectId(v23);
      if ( v21 != v20 )
      {
        BBSupportTracePrintF(
          3,
          "CSettler::WalkDir(): Invalid world map object id: Tick %i, settler %i @ (%i, %i), world id %i, owner %i, race %i",
          TickCounter,
          v21,
          v13,
          v14,
          v20,
          v15,
          v16);
        CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, v21, 0, 0);
        CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, v20, 0, 0);
        if ( BBSupportDbgReport(
               1,
               "MapObjects\\Settler\\Settler.cpp",
               1254,
               "Invalid world map object id! Dietmar: I need the trace file.") == 1 )
          __debugbreak();
      }
      v25 = -1;
      if ( IMovingEntity::IsFree(this, v19) )
      {
        v25 = a2 & 0xF;
      }
      else
      {
        v4 = Grid::TurnLeft(v24);
        v8 = v23 + CWorldManager::NeighborRelIndex(v4);
        v5 = IMovingEntity::Walking(this);
        if ( CWalking::IsFree(v5, v8) )
        {
          v25 = -1;
        }
        else
        {
          v6 = Grid::TurnRight(v24);
          v9 = v23 + CWorldManager::NeighborRelIndex(v6);
          v7 = IMovingEntity::Walking(this);
          if ( CWalking::IsFree(v7, v9) )
            v25 = -1;
        }
      }
      if ( v25 < 0 )
      {
        return a2 | 0x88;
      }
      else
      {
        v11 = IEntity::EntityId((unsigned __int16 *)this);
        v17 = v23 + CWorldManager::NeighborRelIndex(v25);
        CWorldManager::SetSettlerId(v23, 0);
        CWorldManager::SetSettlerId(v17, v11);
        v10 = v22 + Y16X16::NeighborModifier((Y16X16 *)v25);
        IMovingEntity::SetPositionAndDir(this, v10, v25);
        CWarMap::NotifyMove(this, v22);
        *((_BYTE *)this + 69) = -1;
        if ( IEntity::Type((unsigned __int16 *)this) == 1 && (a2 & 0x10) == 0 )
          CWorldManager::IncreaseWalkCount(v17);
        return v25 | a2 & 0xFFFFFFF0;
      }
    }
    else
    {
      return a2;
    }
  }
}


// address=[0x157f570]
// Decompiled from int __thiscall sub_197F570(void *this, int a2)
void  CSettler::Decrease(int) {
  
  int v2; // eax
  int v4; // [esp+0h] [ebp-8h]
  int v5; // [esp+4h] [ebp-4h]

  v5 = std::auto_ptr<ISettlerRole>::operator->(this);
  v2 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v5 + 68))(v5, a2);
  return IEntity::Decrease(v4, v2);
}


// address=[0x157ffe0]
// Decompiled from int __thiscall CSettler::ConvertEventIntoGoal(CSettler *this, struct CEntityEvent *a2)
void  CSettler::ConvertEventIntoGoal(class CEntityEvent *) {
  
  int v2; // eax

  v2 = std::auto_ptr<ISettlerRole>::operator->((_DWORD *)this + 25);
  return (*(int (__thiscall **)(int, CSettler *, struct CEntityEvent *))(*(_DWORD *)v2 + 56))(v2, this, a2);
}


