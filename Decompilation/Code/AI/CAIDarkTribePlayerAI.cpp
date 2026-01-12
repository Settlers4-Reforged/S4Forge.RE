#include "CAIDarkTribePlayerAI.h"

// Definitions for class CAIDarkTribePlayerAI

// address=[0x1319d30]
// Decompiled from CAIDarkTribePlayerAI *__thiscall CAIDarkTribePlayerAI::CAIDarkTribePlayerAI(CAIDarkTribePlayerAI *this, int a2)

 CAIDarkTribePlayerAI::CAIDarkTribePlayerAI(int) {
  
  CAIPlayerAI::CAIPlayerAI(this, a2, 1);
  *(_DWORD *)this = CAIDarkTribePlayerAI::_vftable_;
  *((_DWORD *)this + 1) = &CAIDarkTribePlayerAI::`vftable';
  return this;
}


// address=[0x1319d70]
// Decompiled from void __thiscall CAIDarkTribePlayerAI::Execute(CAIDarkTribePlayerAI *this)

void  CAIDarkTribePlayerAI::Execute(void) {
  
  int v1; // esi
  int v2; // eax
  CAISectorAI *v3; // eax
  double v4; // [esp+4h] [ebp-38h]
  int v5; // [esp+10h] [ebp-2Ch]
  int v6; // [esp+18h] [ebp-24h]
  int v7; // [esp+1Ch] [ebp-20h]
  unsigned int v8; // [esp+20h] [ebp-1Ch]
  int v9; // [esp+24h] [ebp-18h]
  int v10; // [esp+28h] [ebp-14h]
  int NumberOfBuildings; // [esp+2Ch] [ebp-10h]
  int v12; // [esp+34h] [ebp-8h]

  v8 = IAIEnvironment::TickCounter();
  if ( IAIEnvironment::EntityIsAlive(*((_DWORD *)this + 171))
    && (v1 = IAIEnvironment::EntityOwnerId(*((_DWORD *)this + 171)), v1 == CAIPlayerAI::PlayerId(this)) )
  {
    CAIPlayersScriptVars::operator[](*((_DWORD *)this + 3));
    v9 = CAIPlayerScriptVars::operator[](14);
    CAIPlayersScriptVars::operator[](*((_DWORD *)this + 3));
    v10 = CAIPlayerScriptVars::operator[](15);
    CAIPlayersScriptVars::operator[](*((_DWORD *)this + 3));
    v12 = CAIPlayerScriptVars::operator[](16);
    CAIPlayersScriptVars::operator[](*((_DWORD *)this + 3));
    v5 = CAIPlayerScriptVars::operator[](17);
    if ( (v9 > 0 || v10 > 0) && v12 > 0 )
    {
      if ( !(14 * v12) && BBSupportDbgReport(2, "AI\\AI_PlayerAIDark.cpp", 159, "uDelayInTicks > 0") == 1 )
        __debugbreak();
      if ( !(v8 % (14 * v12)) && IAIEnvironment::MagicCurrentManaAmount(*((_DWORD *)this + 3)) < v5 )
      {
        v2 = CAIPlayerAI::PlayerId(this);
        NumberOfBuildings = IAIEnvironment::BuildingGetNumberOfBuildings(v2, 49, 1u);
        if ( NumberOfBuildings < 0
          && BBSupportDbgReport(2, "AI\\AI_PlayerAIDark.cpp", 169, "iNumberOfMushroomFarms >= 0") == 1 )
        {
          __debugbreak();
        }
        v4 = sqrt<int>(NumberOfBuildings);
        IAIEnvironment::MagicIncreaseMana(*((_DWORD *)this + 3), v9 + v10 * (int)v4);
      }
    }
    v7 = TAIStaticPtrVector<CAISectorAI,8>::Size((char *)this + 72);
    if ( v7 > 0 )
    {
      if ( !TAIStaticPtrVector<CAISectorAI,8>::operator[](0)
        && BBSupportDbgReport(2, "AI\\AI_PlayerAIDark.cpp", 183, "m_cSectorAIs[0] != 0") == 1 )
      {
        __debugbreak();
      }
      v3 = (CAISectorAI *)TAIStaticPtrVector<CAISectorAI,8>::operator[](0);
      CAISectorAI::CheckBasePosition(v3);
    }
    CAIPlayerAI::ProcessEvents(this);
    CAIPlayerAI::MoveEntitiesToSectorReservoirs(this);
    (*(void (__thiscall **)(char *, unsigned int, int))(*((_DWORD *)this + 7) + 4))((char *)this + 28, v8, 511);
    if ( v7 > 0 )
    {
      if ( !TAIStaticPtrVector<CAISectorAI,8>::operator[](0)
        && BBSupportDbgReport(2, "AI\\AI_PlayerAIDark.cpp", 196, "m_cSectorAIs[0] != 0") == 1 )
      {
        __debugbreak();
      }
      v6 = TAIStaticPtrVector<CAISectorAI,8>::operator[](0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(v6);
    }
  }
  else
  {
    CAIEventQueue::Clear((CAIDarkTribePlayerAI *)((char *)this + 108));
  }
}


// address=[0x131a000]
// Decompiled from int __thiscall CAIDarkTribePlayerAI::Load(CAIDarkTribePlayerAI *this, struct IS4Chunk *a2)

void  CAIDarkTribePlayerAI::Load(class IS4Chunk &) {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-14h]
  int v4; // [esp+4h] [ebp-10h]
  int DarkTribeSectorAI; // [esp+8h] [ebp-Ch]
  char v7; // [esp+13h] [ebp-1h]

  v7 = 1;
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517219840);
  v4 = (*(int (__thiscall **)(struct IS4Chunk *, _DWORD, int))(*(_DWORD *)a2 + 4))(a2, 0, 2);
  if ( v4 )
  {
    CAIPlayerAI::Load(this, a2);
    (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517219838);
    *((_DWORD *)this + 170) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
    *((_DWORD *)this + 171) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
    if ( v4 != 1 )
    {
      v3 = (*(int (__thiscall **)(struct IS4Chunk *, _DWORD, int))(*(_DWORD *)a2 + 4))(a2, 0, 1);
      if ( v3 )
      {
        v7 = 0;
        DarkTribeSectorAI = CAISectorAI::CreateDarkTribeSectorAI(
                              (CAIDarkTribePlayerAI *)((char *)this - 4),
                              *((_DWORD *)this + 170));
        TAIStaticPtrVector<CAISectorAI,8>::PushBack(DarkTribeSectorAI);
        (*(void (__thiscall **)(int, struct IS4Chunk *))(*(_DWORD *)DarkTribeSectorAI + 20))(DarkTribeSectorAI, a2);
      }
    }
  }
  result = (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517219839);
  if ( v7 )
    return (*(int (__thiscall **)(char *, int))(*((_DWORD *)this - 1) + 8))((char *)this - 4, v3);
  return result;
}


// address=[0x131a120]
// Decompiled from int __thiscall CAIDarkTribePlayerAI::Save(CAIDarkTribePlayerAI *this, struct IS4Chunk *a2)

void  CAIDarkTribePlayerAI::Save(class IS4Chunk &) {
  
  int v3; // [esp+0h] [ebp-8h]

  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517219840);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 2);
  CAIPlayerAI::Save(this, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517219838);
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 170));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 171));
  if ( *((int *)this + 170) <= 0 || TAIStaticPtrVector<CAISectorAI,8>::Size((char *)this + 68) <= 0 )
  {
    (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, 0);
  }
  else
  {
    (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 1);
    v3 = TAIStaticPtrVector<CAISectorAI,8>::operator[](0);
    (*(void (__thiscall **)(int, struct IS4Chunk *))(*(_DWORD *)v3 + 24))(v3, a2);
  }
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517219839);
}


// address=[0x131a210]
// Decompiled from int __thiscall CAIDarkTribePlayerAI::Init(CAIDarkTribePlayerAI *this)

void  CAIDarkTribePlayerAI::Init(void) {
  
  int result; // eax
  int DarkTribeSectorAI; // [esp+0h] [ebp-18h]
  int NumberOfBuildings; // [esp+8h] [ebp-10h]
  int v4; // [esp+10h] [ebp-8h]

  CAIPlayerAI::Init(this);
  CAIPlayerAI::FillGeneralReservoir(this);
  if ( IAIEnvironment::PlayerRace(*((_DWORD *)this + 3)) != 3
    && BBSupportDbgReport(2, "AI\\AI_PlayerAIDark.cpp", 217, "iRace == RACE_DARK") == 1 )
  {
    __debugbreak();
  }
  NumberOfBuildings = IAIEnvironment::BuildingGetNumberOfBuildings(*((_DWORD *)this + 3), 50, 2u);
  if ( IAIEnvironment::BuildingGetNumberOfBuildings(*((_DWORD *)this + 3), 51, 2u) + NumberOfBuildings != 1
    && BBSupportDbgReport(2, "AI\\AI_PlayerAIDark.cpp", 222, "(iNumberOfDarkTemples + iNumberOfFortresses) == 1") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)this + 171) = IAIEnvironment::BuildingGetFirstBuildingId(*((_DWORD *)this + 3), 50);
  if ( *((_DWORD *)this + 171) )
  {
    *((_DWORD *)this + 172) = 50;
  }
  else
  {
    *((_DWORD *)this + 171) = IAIEnvironment::BuildingGetFirstBuildingId(*((_DWORD *)this + 3), 51);
    if ( *((_DWORD *)this + 171) )
      v4 = 51;
    else
      v4 = 0;
    *((_DWORD *)this + 172) = v4;
  }
  if ( *((_DWORD *)this + 171) )
  {
    DarkTribeSectorAI = CAISectorAI::CreateDarkTribeSectorAI(this, *((_DWORD *)this + 171));
    return TAIStaticPtrVector<CAISectorAI,8>::PushBack(DarkTribeSectorAI);
  }
  else
  {
    result = BBSupportDbgReport(
               1,
               "AI\\AI_PlayerAIDark.cpp",
               246,
               "CAIDarkTribePlayerAI::CAIDarkTribePlayerAI(): No dark temple or fortress found!");
    if ( result == 1 )
      __debugbreak();
  }
  return result;
}


