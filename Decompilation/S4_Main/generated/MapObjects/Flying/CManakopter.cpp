#include "CManakopter.h"

// Definitions for class CManakopter

// address=[0x1401120]
// Decompiled from int __cdecl CManakopter::New(int a1)
class CPersistence * __cdecl CManakopter::New(std::istream & a1) {
  
  if ( operator new(0x94u) )
    return CManakopter::CManakopter(a1);
  else
    return 0;
}


// address=[0x1552980]
// Decompiled from CManakopter *__thiscall CManakopter::CManakopter(CManakopter *this, int a2, __int64 a3, unsigned __int8 a4)
 CManakopter::CManakopter(int a2, int a3, int a4, int a4) {
  
  char v5; // [esp+30h] [ebp-28h]
  int v6; // [esp+34h] [ebp-24h]
  int v7; // [esp+38h] [ebp-20h]
  int v8; // [esp+3Ch] [ebp-1Ch]
  int v9; // [esp+40h] [ebp-18h]
  int v10; // [esp+44h] [ebp-14h]

  IFlyingEntity::IFlyingEntity(this, a2, 110, a3, SWORD2(a3));
  *(_DWORD *)this = &CManakopter::_vftable_;
  std::vector<CManakopter::CSettlerStatus>::vector<CManakopter::CSettlerStatus>();
  IEntity::SetOwnerId((IEntity *)this, a4);
  IEntity::SetRace((IEntity *)this, 3u);
  v10 = CLogic::Effects((DWORD *)g_pLogic);
  *((_DWORD *)this + 29) = (*(int (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v10 + 80))(
                             v10,
                             111,
                             *((_DWORD *)this + 18),
                             0);
  v9 = CLogic::Effects((DWORD *)g_pLogic);
  *((_DWORD *)this + 28) = (*(int (__thiscall **)(int, int, _DWORD, int))(*(_DWORD *)v9 + 80))(
                             v9,
                             109,
                             *((_DWORD *)this + 18),
                             1);
  v8 = CLogic::Effects((DWORD *)g_pLogic);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v8 + 84))(
    v8,
    *((_DWORD *)this + 29),
    LODWORD(FLOAT_N10_0),
    LODWORD(FLOAT_N50_0));
  v7 = CLogic::Effects((DWORD *)g_pLogic);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v7 + 84))(
    v7,
    *((_DWORD *)this + 28),
    LODWORD(FLOAT_N10_0),
    LODWORD(FLOAT_N50_0));
  v6 = CLogic::Effects((DWORD *)g_pLogic);
  (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)v6 + 56))(v6, *((_DWORD *)this + 18), 60);
  *((_DWORD *)this + 30) = 999;
  *((_DWORD *)this + 31) = 3;
  *((_DWORD *)this + 32) = 999;
  *((_DWORD *)this + 33) = -10;
  *((_DWORD *)this + 34) = -50;
  *((_WORD *)this + 6) = 1;
  if ( CStaticConfigVarInt::operator int(&CManakopter::s_iManakopterHitPoints) >= 256
    && BBSupportDbgReport(2, "mapobjects\\Manakopter.cpp", 77, "s_iManakopterHitPoints < 256") == 1 )
  {
    __debugbreak();
  }
  if ( CStaticConfigVarInt::operator int(&CManakopter::s_iManakopterHitPoints) >= 256 )
    v5 = -6;
  else
    v5 = CStaticConfigVarInt::operator int(&CManakopter::s_iManakopterHitPoints);
  *((_BYTE *)this + 33) = v5;
  IEntity::SetFlagBits(this, (EntityFlag)((char *)&loc_2020108 + 1));
  *((_DWORD *)this + 6) = Y16X16::PackXYFast(a3, SHIDWORD(a3));
  *((_DWORD *)this + 35) = -1;
  *((_DWORD *)this + 36) = -1;
  IEntity::AddToWarMap();
  IAnimatedEntity::RegisterForLogicUpdate(10);
  return this;
}


// address=[0x1552c00]
// Decompiled from int __thiscall CManakopter::GetGfxInfos(CManakopter *this)
struct SGfxObjectInfo *  CManakopter::GetGfxInfos(void) {
  
  return 0;
}


// address=[0x1552c10]
// Decompiled from void __thiscall CManakopter::LogicUpdate(CPropertySet *this)
void  CManakopter::LogicUpdate(void) {
  
  int v1; // eax
  int v2; // eax
  char v3; // al
  int v4; // eax
  int v5; // eax
  int v6; // [esp+20h] [ebp-58h]
  _BYTE v7[4]; // [esp+28h] [ebp-50h] BYREF
  _BYTE v8[4]; // [esp+2Ch] [ebp-4Ch] BYREF
  int v9; // [esp+30h] [ebp-48h]
  int v10; // [esp+34h] [ebp-44h]
  int v11; // [esp+38h] [ebp-40h]
  int v12; // [esp+3Ch] [ebp-3Ch]
  int v13; // [esp+40h] [ebp-38h]
  int v14; // [esp+44h] [ebp-34h]
  int v15; // [esp+48h] [ebp-30h]
  int v16; // [esp+4Ch] [ebp-2Ch]
  int v17; // [esp+50h] [ebp-28h]
  int v18; // [esp+54h] [ebp-24h]
  int v19; // [esp+58h] [ebp-20h]
  int v20; // [esp+5Ch] [ebp-1Ch]
  int v21; // [esp+60h] [ebp-18h]
  int v22; // [esp+64h] [ebp-14h]
  int v23; // [esp+68h] [ebp-10h]
  int v24; // [esp+6Ch] [ebp-Ch] BYREF
  int v25; // [esp+70h] [ebp-8h] BYREF
  CPropertySet *v26; // [esp+74h] [ebp-4h]

  v26 = this;
  if ( !IEntity::FlagBits(this, (EntityFlag)&unk_4000000) )
  {
    v17 = 0;
    v18 = 0;
    v23 = CLogic::Effects((DWORD *)g_pLogic);
    (*(void (__thiscall **)(int, _DWORD, _BYTE *, int *, int *, _BYTE *))(*(_DWORD *)v23 + 52))(
      v23,
      *((_DWORD *)v26 + 18),
      v7,
      &v24,
      &v25,
      v8);
    v9 = *((_DWORD *)v26 + 6);
    v1 = Y16X16::PackXYFast(v24, v25);
    *((_DWORD *)v26 + 6) = v1;
    CWarMap::NotifyMove(v26, v9);
    if ( v24 == *((unsigned __int16 *)v26 + 38) && v25 == *((unsigned __int16 *)v26 + 39) )
    {
      if ( *((int *)v26 + 33) >= -10 && *((int *)v26 + 34) >= -50 )
      {
        IAnimatedEntity::RegisterForLogicUpdate(10);
        v6 = IEntity::Y(v26);
        v2 = IEntity::X(v26);
        if ( CWorldManager::FlagBits(v2, v6, 4u) )
        {
          v3 = CStaticConfigVarInt::operator int(&CManakopter::s_iManakopterHitPoints);
          *((_BYTE *)v26 + 33) = v3;
        }
      }
      else
      {
        *((_DWORD *)v26 + 34) += 5;
        v12 = CLogic::Effects((DWORD *)g_pLogic);
        (*(void (__thiscall **)(int, _DWORD, float, float))(*(_DWORD *)v12 + 84))(
          v12,
          *((_DWORD *)v26 + 29),
          (float)*((int *)v26 + 33),
          (float)*((int *)v26 + 34));
        v11 = CLogic::Effects((DWORD *)g_pLogic);
        (*(void (__thiscall **)(int, _DWORD, float, float))(*(_DWORD *)v11 + 84))(
          v11,
          *((_DWORD *)v26 + 28),
          (float)*((int *)v26 + 33),
          (float)*((int *)v26 + 34));
        IAnimatedEntity::RegisterForLogicUpdate(1);
        IFlyingEntity::ClearFlyingFlagBits(v26, 1);
      }
    }
    else if ( *((int *)v26 + 33) <= -10 && *((int *)v26 + 34) <= -200 )
    {
      if ( v25 != *((unsigned __int16 *)v26 + 39) )
      {
        if ( v25 <= *((unsigned __int16 *)v26 + 39) )
          v20 = 1;
        else
          v20 = -1;
        v18 = v20;
      }
      if ( v24 != *((unsigned __int16 *)v26 + 38) )
      {
        if ( v24 <= *((unsigned __int16 *)v26 + 38) )
          v19 = 1;
        else
          v19 = -1;
        v17 = v19;
      }
      v16 = CLogic::Effects((DWORD *)g_pLogic);
      v13 = (*(int (__thiscall **)(int, _DWORD, int, int, _DWORD))(*(_DWORD *)v16 + 60))(
              v16,
              *((_DWORD *)v26 + 18),
              v17 + v24,
              v18 + v25,
              0);
      v15 = CLogic::Effects((DWORD *)g_pLogic);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v15 + 88))(v15, *((_DWORD *)v26 + 29));
      v14 = CLogic::Effects((DWORD *)g_pLogic);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v14 + 88))(v14, *((_DWORD *)v26 + 28));
      if ( v13 )
        IAnimatedEntity::RegisterForLogicUpdate(v13);
    }
    else
    {
      *((_DWORD *)v26 + 34) -= 5;
      v22 = CLogic::Effects((DWORD *)g_pLogic);
      (*(void (__thiscall **)(int, _DWORD, float, float))(*(_DWORD *)v22 + 84))(
        v22,
        *((_DWORD *)v26 + 29),
        (float)*((int *)v26 + 33),
        (float)*((int *)v26 + 34));
      v21 = CLogic::Effects((DWORD *)g_pLogic);
      (*(void (__thiscall **)(int, _DWORD, float, float))(*(_DWORD *)v21 + 84))(
        v21,
        *((_DWORD *)v26 + 28),
        (float)*((int *)v26 + 33),
        (float)*((int *)v26 + 34));
      IAnimatedEntity::RegisterForLogicUpdate(1);
    }
    v10 = CLogic::Effects((DWORD *)g_pLogic);
    if ( (*(unsigned __int8 (__thiscall **)(int, _DWORD))(*(_DWORD *)v10 + 92))(v10, *((_DWORD *)v26 + 28)) )
    {
      if ( IFlyingEntity::FlyingFlagBits(v26, 1)
        && !CSoundManager::IsPlaying((CSoundManager *)g_pSoundManager, *((_DWORD *)v26 + 36)) )
      {
        CSoundManager::StopSound((CSoundManager *)g_pSoundManager, *((_DWORD *)v26 + 35));
        *((_DWORD *)v26 + 35) = -1;
        v4 = CSoundManager::PlayEnvironmentSound(g_pSoundManager, 99, v24, v25, 0);
        *((_DWORD *)v26 + 36) = v4;
      }
      if ( !IFlyingEntity::FlyingFlagBits(v26, 1)
        && !CSoundManager::IsPlaying((CSoundManager *)g_pSoundManager, *((_DWORD *)v26 + 35)) )
      {
        CSoundManager::StopSound((CSoundManager *)g_pSoundManager, *((_DWORD *)v26 + 36));
        *((_DWORD *)v26 + 36) = -1;
        v5 = CSoundManager::PlayEnvironmentSound(g_pSoundManager, 100, v24, v25, 1);
        *((_DWORD *)v26 + 35) = v5;
      }
    }
    else
    {
      if ( CSoundManager::IsPlaying((CSoundManager *)g_pSoundManager, *((_DWORD *)v26 + 35)) )
      {
        CSoundManager::StopSound((CSoundManager *)g_pSoundManager, *((_DWORD *)v26 + 35));
        *((_DWORD *)v26 + 35) = -1;
      }
      if ( CSoundManager::IsPlaying((CSoundManager *)g_pSoundManager, *((_DWORD *)v26 + 36)) )
      {
        CSoundManager::StopSound((CSoundManager *)g_pSoundManager, *((_DWORD *)v26 + 36));
        *((_DWORD *)v26 + 36) = -1;
      }
    }
  }
}


// address=[0x1553110]
// Decompiled from char __thiscall CManakopter::SettlerEnter(CManakopter *this, int a2)
bool  CManakopter::SettlerEnter(int a2) {
  
  int v3; // eax
  _BYTE v4[12]; // [esp+4h] [ebp-3Ch] BYREF
  int v5; // [esp+10h] [ebp-30h]
  int v6; // [esp+14h] [ebp-2Ch]
  int v7; // [esp+18h] [ebp-28h]
  int v8; // [esp+1Ch] [ebp-24h]
  int v9; // [esp+20h] [ebp-20h]
  int i; // [esp+24h] [ebp-1Ch]
  IFlyingEntity *v11; // [esp+28h] [ebp-18h]
  CPropertySet *SettlerPtr; // [esp+2Ch] [ebp-14h]
  char v13; // [esp+33h] [ebp-Dh]
  int v14; // [esp+3Ch] [ebp-4h]

  v11 = this;
  SettlerPtr = (CPropertySet *)CSettlerMgr::GetSettlerPtr(a2);
  if ( IEntity::Race(SettlerPtr) != 3
    && BBSupportDbgReport(2, "mapobjects\\Manakopter.cpp", 400, "pSettler->Race() == RACE_DARK") == 1 )
  {
    __debugbreak();
  }
  if ( !SettlerPtr && BBSupportDbgReport(2, "mapobjects\\Manakopter.cpp", 401, "pSettler != NULL") == 1 )
    __debugbreak();
  if ( !SettlerPtr || ((unsigned int)&unk_4000000 & IEntity::Flags(SettlerPtr)) != 0 )
    return 0;
  v7 = IEntity::Type((unsigned __int16 *)SettlerPtr);
  v8 = IEntity::UniqueId(SettlerPtr);
  v13 = 0;
  v9 = std::vector<CManakopter::CSettlerStatus>::size((char *)v11 + 96);
  for ( i = 0; i < v9; ++i )
  {
    if ( *(_DWORD *)(std::vector<CManakopter::CSettlerStatus>::operator[](i) + 4) == a2 )
    {
      v13 = 1;
      break;
    }
  }
  if ( v13 )
  {
    (*(void (__thiscall **)(CPropertySet *, _DWORD, const char *))(*(_DWORD *)SettlerPtr + 48))(
      SettlerPtr,
      0,
      "CManakopter::SettlerEnter(): Settler already on board");
  }
  else
  {
    v6 = CManakopter::CSettlerStatus::CSettlerStatus(v4, a2, v7, v8);
    v5 = v6;
    v14 = 0;
    std::vector<CManakopter::CSettlerStatus>::push_back(v6);
    v14 = -1;
    CManakopter::CSettlerStatus::~CSettlerStatus((CManakopter::CSettlerStatus *)v4);
  }
  CWarMap::RemoveEntity(SettlerPtr);
  v3 = IEntity::WorldIdx();
  CWorldManager::SetSettlerId(v3, 0);
  IEntity::SetFlagBits(SettlerPtr, EntityFlag_OnBoard);
  IFlyingEntity::SetFlyingFlagBits(v11, 4);
  IFlyingEntity::ClearFlyingFlagBits(v11, 2);
  if ( !*((_DWORD *)v11 + 30) && !*((_DWORD *)v11 + 31) && !*((_DWORD *)v11 + 32) )
    IFlyingEntity::SetFlyingFlagBits(v11, 8);
  return 1;
}


// address=[0x1553300]
// Decompiled from char *__thiscall CManakopter::UnloadSettlers(CManakopter *this)
void  CManakopter::UnloadSettlers(void) {
  
  int v1; // eax
  int v2; // esi
  int v3; // esi
  char *result; // eax
  int v5; // [esp+0h] [ebp-78h]
  int v6; // [esp+4h] [ebp-74h]
  _BYTE v7[24]; // [esp+8h] [ebp-70h] BYREF
  _BYTE v8[24]; // [esp+20h] [ebp-58h] BYREF
  CEntityEvent *v9; // [esp+38h] [ebp-40h]
  CEntityEvent *v10; // [esp+3Ch] [ebp-3Ch]
  CEntityEvent *v11; // [esp+40h] [ebp-38h]
  CEntityEvent *v12; // [esp+44h] [ebp-34h]
  int v13; // [esp+48h] [ebp-30h]
  int v14; // [esp+4Ch] [ebp-2Ch]
  int v15; // [esp+50h] [ebp-28h]
  int v16; // [esp+54h] [ebp-24h]
  int v17; // [esp+58h] [ebp-20h]
  int v18; // [esp+5Ch] [ebp-1Ch]
  int *v19; // [esp+60h] [ebp-18h]
  unsigned __int8 *SettlerPtr; // [esp+64h] [ebp-14h]
  char *i; // [esp+68h] [ebp-10h]
  int v22; // [esp+74h] [ebp-4h]

  for ( i = (char *)this;
        !(unsigned __int8)std::vector<CManakopter::CSettlerStatus>::empty(i + 96);
        std::vector<CManakopter::CSettlerStatus>::pop_back(i + 96) )
  {
    v19 = (int *)std::vector<CManakopter::CSettlerStatus>::back(v5, v6);
    v16 = v19[1];
    v15 = *v19;
    SettlerPtr = CSettlerMgr::GetSettlerPtr(v16);
    if ( SettlerPtr )
    {
      v1 = IEntity::UniqueId(SettlerPtr);
      if ( v1 == v15 )
      {
        v18 = (i[82] + 3) % 6 + 8;
        v2 = IEntity::X(i);
        v13 = CSpiralOffsets::DeltaX(v18) + v2;
        v3 = IEntity::Y(i);
        v14 = CSpiralOffsets::DeltaY(v18) + v3;
        v17 = Y16X16::PackXYFast(v13, v14);
        v12 = CEntityEvent::CEntityEvent((CEntityEvent *)v8, 0x19u, 0, 0, v17, 0);
        v11 = v12;
        v22 = 0;
        (*(void (__thiscall **)(unsigned __int8 *, CEntityEvent *))(*(_DWORD *)SettlerPtr + 80))(SettlerPtr, v12);
        v22 = -1;
        CEntityEvent::~CEntityEvent(v8);
        v10 = CEntityEvent::CEntityEvent((CEntityEvent *)v7, 0x11u, 13, 0, v17, 0);
        v9 = v10;
        v22 = 1;
        (*(void (__thiscall **)(unsigned __int8 *, CEntityEvent *))(*(_DWORD *)SettlerPtr + 80))(SettlerPtr, v10);
        v22 = -1;
        CEntityEvent::~CEntityEvent(v7);
      }
    }
  }
  std::vector<CManakopter::CSettlerStatus>::clear(v5, v6);
  IFlyingEntity::ClearFlyingFlagBits((IFlyingEntity *)i, 8);
  IFlyingEntity::ClearFlyingFlagBits((IFlyingEntity *)i, 4);
  IFlyingEntity::SetFlyingFlagBits((IFlyingEntity *)i, 2);
  *((_DWORD *)i + 30) = 999;
  *((_DWORD *)i + 31) = 3;
  result = i;
  *((_DWORD *)i + 32) = 999;
  return result;
}


// address=[0x15534e0]
// Decompiled from void __thiscall CManakopter::Attach(CManakopter *this, int a2)
void  CManakopter::Attach(int a2) {
  
  IFlyingEntity::SetFlyingFlagBits(this, 4);
  IFlyingEntity::ClearFlyingFlagBits(this, 2);
  IFlyingEntity::Attach(this, a2);
}


// address=[0x1553510]
// Decompiled from void __thiscall CManakopter::Delete(CManakopter *this)
void  CManakopter::Delete(void) {
  
  int v1; // eax
  IEffects *v2; // eax
  IEffects *v3; // eax
  IEffects *v4; // eax
  int v5; // eax
  int v6; // [esp-10h] [ebp-28h]
  unsigned int v7; // [esp-4h] [ebp-1Ch]
  unsigned int v8; // [esp-4h] [ebp-1Ch]
  unsigned int v9; // [esp-4h] [ebp-1Ch]
  int v10; // [esp+0h] [ebp-18h]
  int v11; // [esp+4h] [ebp-14h]
  int v12; // [esp+4h] [ebp-14h]
  int v13; // [esp+8h] [ebp-10h]
  unsigned __int8 *SettlerPtr; // [esp+Ch] [ebp-Ch]
  int *v15; // [esp+10h] [ebp-8h]

  v1 = IEntity::ID();
  CTrace::Print("Manakopter: Delete for %i called!", v1);
  while ( !(unsigned __int8)std::vector<CManakopter::CSettlerStatus>::empty((char *)this + 96) )
  {
    v15 = (int *)std::vector<CManakopter::CSettlerStatus>::back(v10, v11);
    v13 = v15[1];
    v10 = *v15;
    SettlerPtr = CSettlerMgr::GetSettlerPtr(v13);
    if ( SettlerPtr )
    {
      if ( IEntity::UniqueId(SettlerPtr) == v10 )
        CMapObjectMgr::Kill(v13, 0);
    }
    std::vector<CManakopter::CSettlerStatus>::pop_back((char *)this + 96);
  }
  std::vector<CManakopter::CSettlerStatus>::clear(v10, v11);
  v7 = *((_DWORD *)this + 18);
  v2 = (IEffects *)CLogic::Effects((DWORD *)g_pLogic);
  IEffects::DeleteMovingEffect(v2, v7);
  v8 = *((_DWORD *)this + 28);
  v3 = (IEffects *)CLogic::Effects((DWORD *)g_pLogic);
  IEffects::DeleteMovingEffect(v3, v8);
  v9 = *((_DWORD *)this + 29);
  v4 = (IEffects *)CLogic::Effects((DWORD *)g_pLogic);
  IEffects::DeleteMovingEffect(v4, v9);
  if ( g_pSoundManager )
  {
    CSoundManager::StopSound((CSoundManager *)g_pSoundManager, *((_DWORD *)this + 36));
    CSoundManager::StopSound((CSoundManager *)g_pSoundManager, *((_DWORD *)this + 35));
  }
  v12 = CLogic::Effects((DWORD *)g_pLogic);
  v6 = IEntity::Y(this);
  v5 = IEntity::X(this);
  (*(void (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v12 + 16))(
    v12,
    114,
    101,
    v5,
    v6,
    0,
    0,
    0);
  IFlyingEntity::Delete(this);
}


// address=[0x1553670]
// Decompiled from void __thiscall CManakopter::Decrease(CManakopter *this, int a2)
void  CManakopter::Decrease(int a2) {
  
  int v3; // [esp+4h] [ebp-8h]
  int v4; // [esp+8h] [ebp-4h]

  if ( a2 > 0 )
  {
    v4 = CStaticConfigVarInt::operator int(&CManakopter::s_iManakopterArmor);
    if ( a2 <= v4 )
      v3 = 1;
    else
      v3 = a2 - v4;
    IEntity::Decrease((int)this, v3);
  }
}


// address=[0x15536c0]
// Decompiled from _DWORD *__thiscall CManakopter::CManakopter(_DWORD *this, int a2)
 CManakopter::CManakopter(std::istream & a2) {
  
  _BYTE v3[4]; // [esp+4h] [ebp-34h] BYREF
  _BYTE v4[4]; // [esp+8h] [ebp-30h] BYREF
  int v5; // [esp+Ch] [ebp-2Ch]
  int v6; // [esp+10h] [ebp-28h] BYREF
  _DWORD v7[2]; // [esp+14h] [ebp-24h] BYREF
  int v8; // [esp+1Ch] [ebp-1Ch] BYREF
  int pExceptionObject; // [esp+20h] [ebp-18h] BYREF
  unsigned int i; // [esp+24h] [ebp-14h]
  _DWORD *v11; // [esp+28h] [ebp-10h]
  int v12; // [esp+34h] [ebp-4h]

  v11 = this;
  IFlyingEntity::IFlyingEntity(this, a2);
  v12 = 0;
  *v11 = &CManakopter::_vftable_;
  std::vector<CManakopter::CSettlerStatus>::vector<CManakopter::CSettlerStatus>();
  LOBYTE(v12) = 1;
  operator^<unsigned int>(a2, &v8);
  v7[1] = v8;
  if ( v8 != 2 )
  {
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned int>(a2, v7);
  for ( i = 0; i < v7[0]; ++i )
  {
    CManakopter::CSettlerStatus::CSettlerStatus((CManakopter::CSettlerStatus *)v3);
    LOBYTE(v12) = 2;
    operator^<int>(a2, (int)v3);
    operator^<int>(a2, (int)v4);
    operator^<int>(a2, (int)&v6);
    v5 = v6;
    std::vector<CManakopter::CSettlerStatus>::push_back(v3);
    LOBYTE(v12) = 1;
    CManakopter::CSettlerStatus::~CSettlerStatus((CManakopter::CSettlerStatus *)v3);
  }
  operator^<unsigned int>(a2, v11 + 28);
  operator^<unsigned int>(a2, v11 + 29);
  operator^<int>(a2, (int)(v11 + 30));
  operator^<int>(a2, (int)(v11 + 31));
  operator^<int>(a2, (int)(v11 + 32));
  operator^<int>(a2, (int)(v11 + 33));
  operator^<int>(a2, (int)(v11 + 34));
  operator^<int>(a2, (int)(v11 + 35));
  operator^<int>(a2, (int)(v11 + 36));
  IEntity::AddToWarMap();
  v12 = -1;
  return v11;
}


// address=[0x15538c0]
// Decompiled from int __thiscall CManakopter::Store(char *this, struct std::ostream *a2)
void  CManakopter::Store(std::ostream & a2) {
  
  const struct CManakopter::CSettlerStatus *v2; // eax
  int v4; // [esp+4h] [ebp-2Ch] BYREF
  int v5[2]; // [esp+8h] [ebp-28h] BYREF
  int v6; // [esp+10h] [ebp-20h] BYREF
  int v7; // [esp+14h] [ebp-1Ch] BYREF
  int v8; // [esp+18h] [ebp-18h] BYREF
  unsigned int i; // [esp+1Ch] [ebp-14h]
  int *v10; // [esp+20h] [ebp-10h]
  int v11; // [esp+2Ch] [ebp-4h]

  v10 = (int *)this;
  IFlyingEntity::Store(this, a2);
  v7 = 2;
  operator^<unsigned int>(a2, &v7);
  v8 = std::vector<CManakopter::CSettlerStatus>::size(v10 + 24);
  operator^<unsigned int>(a2, &v8);
  for ( i = 0; i < v8; ++i )
  {
    v2 = (const struct CManakopter::CSettlerStatus *)std::vector<CManakopter::CSettlerStatus>::operator[](i);
    CManakopter::CSettlerStatus::CSettlerStatus((CManakopter::CSettlerStatus *)&v4, v2);
    v11 = 0;
    operator^<int>((int)a2, &v4);
    operator^<int>((int)a2, v5);
    v6 = v5[1];
    operator^<int>((int)a2, &v6);
    v11 = -1;
    CManakopter::CSettlerStatus::~CSettlerStatus((CManakopter::CSettlerStatus *)&v4);
  }
  operator^<unsigned int>(a2, v10 + 28);
  operator^<unsigned int>(a2, v10 + 29);
  operator^<int>((int)a2, v10 + 30);
  operator^<int>((int)a2, v10 + 31);
  operator^<int>((int)a2, v10 + 32);
  operator^<int>((int)a2, v10 + 33);
  operator^<int>((int)a2, v10 + 34);
  operator^<int>((int)a2, v10 + 35);
  return operator^<int>((int)a2, v10 + 36);
}


// address=[0x1554b30]
// Decompiled from void __thiscall CManakopter::~CManakopter(CManakopter *this)
 CManakopter::~CManakopter(void) {
  
  IFlyingEntity *v1; // [esp+0h] [ebp-4h]

  std::vector<CManakopter::CSettlerStatus>::~vector<CManakopter::CSettlerStatus>(this);
  IFlyingEntity::~IFlyingEntity(v1);
}


// address=[0x1554fc0]
// Decompiled from int __thiscall CManakopter::ClassID(CManakopter *this)
unsigned long  CManakopter::ClassID(void)const {
  
  return CManakopter::m_iClassID;
}


// address=[0x3d8bba0]
// [Decompilation failed for static unsigned long CManakopter::m_iClassID]

// address=[0x4105360]
// [Decompilation failed for static class CAIConfigInt CManakopter::s_iManakopterHitPoints]

// address=[0x410536c]
// [Decompilation failed for static class CAIConfigInt CManakopter::s_iManakopterArmor]

