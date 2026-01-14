#include "all_headers.h"

// Definitions for class CAIPlayerAI

// address=[0x12fd510]
// Decompiled from int __thiscall CAIPlayerAI::PlayerId(pairNode *this)
int  CAIPlayerAI::PlayerId(void)const {
  
  return *((_DWORD *)this + 3);
}


// address=[0x1306930]
// Decompiled from int __thiscall CAIPlayerAI::Race(CAIPlayerAI *this)
int  CAIPlayerAI::Race(void)const {
  
  return *((_DWORD *)this + 4);
}


// address=[0x13175a0]
// Decompiled from int __thiscall CAIPlayerAI::Execute(CAIPlayerAI *this)
void  CAIPlayerAI::Execute(void) {
  
  int result; // eax
  int v2; // [esp+0h] [ebp-14h]
  int v3; // [esp+4h] [ebp-10h]
  int v4; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]

  v2 = IAIEnvironment::TickCounter();
  CAIPlayerAI::CalculateSectorAndEcoSectorIds(this);
  CAIPlayerAI::ProcessEvents(this);
  CAIPlayerAI::MoveEntitiesToSectorReservoirs(this);
  (*(void (__thiscall **)(char *, int, int))(*((_DWORD *)this + 7) + 4))((char *)this + 28, v2, 511);
  result = TAIStaticPtrVector<CAISectorAI,8>::Size((char *)this + 72);
  v3 = result;
  for ( i = 0; i < v3; ++i )
  {
    v4 = TAIStaticPtrVector<CAISectorAI,8>::operator[](i);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(v4);
    if ( TAIStaticPtrVector<CAISectorAI,8>::Size((char *)this + 72) != v3
      && BBSupportDbgReport(2, "AI\\AI_PlayerAI.cpp", 853, "m_cSectorAIs.Size() == iNumberOfSectorAIs") == 1 )
    {
      __debugbreak();
    }
    result = i + 1;
  }
  return result;
}


// address=[0x1317660]
// Decompiled from int __thiscall CAIPlayerAI::Release(CAIPlayerAI *this)
void  CAIPlayerAI::Release(void) {
  
  return TAIStaticObjectMemoryPool<CAIPlayerAI,692,9>::Delete(this);
}


// address=[0x1317680]
// Decompiled from void __thiscall CAIPlayerAI::PostAIEvent(CAIPlayerAI *this, int a2, int a3, int a4, int a5)
void  CAIPlayerAI::PostAIEvent(int,int,int,int) {
  
  CAIEventQueue::PostAIEvent((CAIPlayerAI *)((char *)this + 108), a2, a3, a4, a5);
}


// address=[0x13176b0]
// Decompiled from CAIPlayerAI *__thiscall CAIPlayerAI::CAIPlayerAI(CAIPlayerAI *this, int a2, bool a3)
 CAIPlayerAI::CAIPlayerAI(int,bool) {
  
  IAIUnknown::IAIUnknown(this);
  IS4ChunkObject::IS4ChunkObject((CAIPlayerAI *)((char *)this + 4));
  *(_DWORD *)this = CAIPlayerAI::_vftable_;
  *((_DWORD *)this + 1) = &CAIPlayerAI::`vftable';
  *((_BYTE *)this + 8) = a3;
  *((_DWORD *)this + 3) = a2;
  *((_DWORD *)this + 4) = IAIEnvironment::PlayerRace(a2);
  *((_DWORD *)this + 5) = *(&off_3D7A4E0 + *((_DWORD *)this + 4));
  *((_DWORD *)this + 6) = *(&off_3D7A50C + *((_DWORD *)this + 4));
  CAIScheduler::CAIScheduler((CAIPlayerAI *)((char *)this + 28));
  TAIStaticPtrVector<CAISectorAI,8>::TAIStaticPtrVector<CAISectorAI,8>((char *)this + 72);
  CAIEventQueue::CAIEventQueue((CAIPlayerAI *)((char *)this + 108));
  CAITaskForceReservoir::CAITaskForceReservoir((CAIPlayerAI *)((char *)this + 132), a2);
  CAITaskForceReservoir::CAITaskForceReservoir((CAIPlayerAI *)((char *)this + 212), a2);
  CAITaskForceReservoir::CAITaskForceReservoir((CAIPlayerAI *)((char *)this + 292), a2);
  CAITaskForceReservoir::CAITaskForceReservoir((CAIPlayerAI *)((char *)this + 372), a2);
  CAITaskForceReservoir::CAITaskForceReservoir((CAIPlayerAI *)((char *)this + 452), a2);
  CAIAgentGlobalSuicideMission::CAIAgentGlobalSuicideMission((CAIPlayerAI *)((char *)this + 532), "global suicide");
  CAITaskForceSquad::CAITaskForceSquad((char *)this + 572, a2, 4, 0);
  CAIAgentPlayerBase::AttachPlayerAI((CAIPlayerAI *)((char *)this + 532), this);
  CAIScheduler::AddAgent((CAIPlayerAI *)((char *)this + 28), (CAIPlayerAI *)((char *)this + 532), 0x96u, 0x100u, 8u);
  return this;
}


// address=[0x1317870]
// Decompiled from void __thiscall CAIPlayerAI::~CAIPlayerAI(CAIPlayerAI *this)
 CAIPlayerAI::~CAIPlayerAI(void) {
  
  int v2; // [esp+0h] [ebp-4h]

  *(_DWORD *)this = CAIPlayerAI::_vftable_;
  *((_DWORD *)this + 1) = &CAIPlayerAI::`vftable';
  CAITaskForceSquad::~CAITaskForceSquad((CAIPlayerAI *)((char *)this + 572));
  CAIAgentGlobalSuicideMission::~CAIAgentGlobalSuicideMission((CAIPlayerAI *)((char *)this + 532));
  CAITaskForceReservoir::~CAITaskForceReservoir((CAIPlayerAI *)((char *)this + 452));
  CAITaskForceReservoir::~CAITaskForceReservoir((CAIPlayerAI *)((char *)this + 372));
  CAITaskForceReservoir::~CAITaskForceReservoir((CAIPlayerAI *)((char *)this + 292));
  CAITaskForceReservoir::~CAITaskForceReservoir((CAIPlayerAI *)((char *)this + 212));
  CAITaskForceReservoir::~CAITaskForceReservoir((CAIPlayerAI *)((char *)this + 132));
  CAIEventQueue::~CAIEventQueue((CAIPlayerAI *)((char *)this + 108));
  TAIStaticPtrVector<CAISectorAI,8>::~TAIStaticPtrVector<CAISectorAI,8>(this);
  CAIScheduler::~CAIScheduler((CAIScheduler *)(v2 + 28));
}


// address=[0x1317920]
// Decompiled from void __thiscall CAIPlayerAI::Init(CAIPlayerAI *this)
void  CAIPlayerAI::Init(void) {
  
  ;
}


// address=[0x1317930]
// Decompiled from CAIDarkTribePlayerAI *__cdecl CAIPlayerAI::CreatePlayerAI(int a1, struct IS4Chunk *a2)
static class CAIPlayerAI * __cdecl CAIPlayerAI::CreatePlayerAI(int,class IS4Chunk *) {
  
  void *Memory; // [esp+8h] [ebp-30h]
  void *v4; // [esp+10h] [ebp-28h]
  CAIDarkTribePlayerAI *v5; // [esp+18h] [ebp-20h]
  CAIDarkTribePlayerAI *v6; // [esp+1Ch] [ebp-1Ch]
  CAINormalPlayerAI *v7; // [esp+20h] [ebp-18h]
  CAINormalPlayerAI *v8; // [esp+24h] [ebp-14h]
  CAIDarkTribePlayerAI *v9; // [esp+28h] [ebp-10h]

  if ( IAIEnvironment::PlayerRace(a1) == 3 )
  {
    Memory = (void *)TAIStaticMemoryPool<692,9>::AllocateMemory(692);
    v6 = (CAIDarkTribePlayerAI *)operator new(0x2B4u, Memory);
    if ( v6 )
      v5 = CAIDarkTribePlayerAI::CAIDarkTribePlayerAI(v6, a1);
    else
      v5 = 0;
    v9 = v5;
  }
  else
  {
    v4 = (void *)TAIStaticMemoryPool<692,9>::AllocateMemory(684);
    v8 = (CAINormalPlayerAI *)operator new(0x2ACu, v4);
    if ( v8 )
      v7 = CAINormalPlayerAI::CAINormalPlayerAI(v8, a1);
    else
      v7 = 0;
    v9 = v7;
  }
  if ( !v9 && BBSupportDbgReport(2, "AI\\AI_PlayerAI.cpp", 238, "pPlayerAI != 0") == 1 )
    __debugbreak();
  if ( a2 )
    (**((void (__thiscall ***)(int, struct IS4Chunk *))v9 + 1))((int)v9 + 4, a2);
  else
    (*(void (__thiscall **)(CAIDarkTribePlayerAI *))(*(_DWORD *)v9 + 8))(v9);
  return v9;
}


// address=[0x1317a90]
// Decompiled from int __thiscall CAIPlayerAI::DbgPrint(CAIPlayerAI *this)
void  CAIPlayerAI::DbgPrint(void) {
  
  int result; // eax
  int v2; // eax
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    result = TAIStaticPtrVector<CAISectorAI,8>::Size((char *)this + 72);
    if ( i >= result )
      break;
    v2 = TAIStaticPtrVector<CAISectorAI,8>::operator[](i);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v2 + 32))(v2, v2);
  }
  return result;
}


// address=[0x1317ae0]
// Decompiled from int __thiscall CAIPlayerAI::GetNumberOfOwnBuildings(pairNode *this, int a2, unsigned int a3)
int  CAIPlayerAI::GetNumberOfOwnBuildings(int,int) {
  
  int v3; // eax

  v3 = CAIPlayerAI::PlayerId(this);
  return IAIEnvironment::BuildingGetNumberOfBuildings(v3, a2, a3);
}


// address=[0x1317b10]
// Decompiled from int __thiscall CAIPlayerAI::GetNumberOfOwnVehicles(pairNode *this, int a2, int a3)
int  CAIPlayerAI::GetNumberOfOwnVehicles(int,int) {
  
  int v3; // eax

  v3 = CAIPlayerAI::PlayerId(this);
  return IAIEnvironment::VehicleGetNumberOfVehicles(v3, a2, a3);
}


// address=[0x1317b40]
// Decompiled from int __thiscall CAIPlayerAI::MoveEntitiesToSectorReservoirs(CAIPlayerAI *this)
void  CAIPlayerAI::MoveEntitiesToSectorReservoirs(void) {
  
  int result; // eax
  int v2; // [esp+0h] [ebp-18h]
  int v3; // [esp+4h] [ebp-14h] BYREF
  CAIPlayerAI *v4; // [esp+8h] [ebp-10h]
  int v5; // [esp+Ch] [ebp-Ch]
  unsigned int v6; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  v4 = this;
  result = CAITaskForce::FirstEntity((char *)this + 132);
  for ( i = result; i; i = v2 )
  {
    v2 = CAIEntityInfo::Next(i);
    v5 = CAIEntityInfo::EntityId(i);
    IAIEnvironment::EntityGetWarriorTypeAndSectorId(v5, &v6, &v3);
    if ( !v6 && BBSupportDbgReport(2, "AI\\AI_PlayerAI.cpp", 821, "tWarriorType != AI_WARRIOR_TYPE_NONE") == 1 )
      __debugbreak();
    result = CAIPlayerAI::AddEntityToSectorReservoir(v4, v5, v6, v3);
  }
  return result;
}


// address=[0x1317bd0]
// Decompiled from int __thiscall CAIPlayerAI::ScanForNewSectors(CAIPlayerAI *this)
void  CAIPlayerAI::ScanForNewSectors(void) {
  
  int result; // eax
  int v2; // eax
  CAISectorAI *v3; // eax
  int v4; // eax
  int NormalSectorAI; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  _BYTE v10[4]; // [esp+0h] [ebp-54h] BYREF
  _BYTE v11[4]; // [esp+4h] [ebp-50h] BYREF
  _BYTE v12[4]; // [esp+8h] [ebp-4Ch] BYREF
  int v13; // [esp+Ch] [ebp-48h] BYREF
  int v14; // [esp+10h] [ebp-44h] BYREF
  int v15; // [esp+14h] [ebp-40h] BYREF
  int v16; // [esp+18h] [ebp-3Ch] BYREF
  int i; // [esp+1Ch] [ebp-38h]
  struct _Cnd_internal_imp_t *v18; // [esp+20h] [ebp-34h] BYREF
  struct _Mtx_internal_imp_t *v19; // [esp+24h] [ebp-30h] BYREF
  pairNode *v20; // [esp+28h] [ebp-2Ch]
  _BYTE v21[36]; // [esp+2Ch] [ebp-28h] BYREF

  v20 = this;
  TStaticArray<int,8>::TStaticArray<int,8>(v21);
  result = TAIStaticPtrVector<CAISectorAI,8>::Size((char *)v20 + 72);
  if ( result >= 8 )
    return result;
  for ( i = 0; ; ++i )
  {
    v2 = TAIStaticPtrVector<CAISectorAI,8>::Size((char *)v20 + 72);
    if ( i >= v2 )
      break;
    v3 = (CAISectorAI *)TAIStaticPtrVector<CAISectorAI,8>::operator[](i);
    v13 = CAISectorAI::SectorId(v3);
    TStaticArray<int,8>::PushBack(&v13);
  }
  v4 = CAIPlayerAI::PlayerId(v20);
  CAIBuildingEnsignPositionIterator::CAIBuildingEnsignPositionIterator((CAIBuildingEnsignPositionIterator *)v12, v4, 48);
  while ( CAIBuildingEnsignPositionIterator::NextXY((CAIBuildingEnsignPositionIterator *)v12, (int *)&v18, (int *)&v19) )
  {
    v16 = IAIEnvironment::WorldSectorId((int)v18, (int)v19);
    if ( !(unsigned __int8)TStaticArray<int,8>::SearchBackwards(&v16) )
    {
      TStaticArray<int,8>::PushBack(&v16);
      NormalSectorAI = CAISectorAI::CreateNormalSectorAI(v20, (int)v18, (int)v19);
      TAIStaticPtrVector<CAISectorAI,8>::PushBack(NormalSectorAI);
      result = TAIStaticPtrVector<CAISectorAI,8>::Size((char *)v20 + 72);
      if ( result >= 8 )
        return result;
    }
  }
  v6 = CAIPlayerAI::PlayerId(v20);
  CAIBuildingEnsignPositionIterator::CAIBuildingEnsignPositionIterator((CAIBuildingEnsignPositionIterator *)v11, v6, 47);
  while ( CAIBuildingEnsignPositionIterator::NextXY((CAIBuildingEnsignPositionIterator *)v11, (int *)&v18, (int *)&v19) )
  {
    v15 = IAIEnvironment::WorldSectorId((int)v18, (int)v19);
    if ( !(unsigned __int8)TStaticArray<int,8>::SearchBackwards(&v15) )
    {
      TStaticArray<int,8>::PushBack(&v15);
      v7 = CAISectorAI::CreateNormalSectorAI(v20, (int)v18, (int)v19);
      TAIStaticPtrVector<CAISectorAI,8>::PushBack(v7);
      result = TAIStaticPtrVector<CAISectorAI,8>::Size((char *)v20 + 72);
      if ( result >= 8 )
        return result;
    }
  }
  v8 = CAIPlayerAI::PlayerId(v20);
  CAIBuildingEnsignPositionIterator::CAIBuildingEnsignPositionIterator((CAIBuildingEnsignPositionIterator *)v10, v8, 46);
  while ( 1 )
  {
    result = CAIBuildingEnsignPositionIterator::NextXY(
               (CAIBuildingEnsignPositionIterator *)v10,
               (int *)&v18,
               (int *)&v19);
    if ( !(_BYTE)result )
      break;
    v14 = IAIEnvironment::WorldSectorId((int)v18, (int)v19);
    if ( !(unsigned __int8)TStaticArray<int,8>::SearchBackwards(&v14) )
    {
      TStaticArray<int,8>::PushBack(&v14);
      v9 = CAISectorAI::CreateNormalSectorAI(v20, (int)v18, (int)v19);
      TAIStaticPtrVector<CAISectorAI,8>::PushBack(v9);
      result = TAIStaticPtrVector<CAISectorAI,8>::Size((char *)v20 + 72);
      if ( result >= 8 )
        break;
    }
  }
  return result;
}


// address=[0x1317e10]
// Decompiled from int __thiscall CAIPlayerAI::Load(CAIPlayerAI *this, struct IS4Chunk *a2)
void  CAIPlayerAI::Load(class IS4Chunk &) {
  
  unsigned int v3; // [esp+0h] [ebp-8h]

  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517223936);
  v3 = (*(int (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1, 2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517223934);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 26))((char *)this + 104, a2);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 32))((char *)this + 128, a2);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 52))((char *)this + 208, a2);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 72))((char *)this + 288, a2);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 92))((char *)this + 368, a2);
  if ( v3 < 2 )
    return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517223935);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 112))((char *)this + 448, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 132) + 12))((char *)this + 528, a2);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 142))((char *)this + 568, a2);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517223935);
}


// address=[0x1317f40]
// Decompiled from int __thiscall CAIPlayerAI::Save(CAIPlayerAI *this, struct IS4Chunk *a2)
void  CAIPlayerAI::Save(class IS4Chunk &) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517223936);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517223934);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 26) + 4))((char *)this + 104, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 32) + 4))((char *)this + 128, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 52) + 4))((char *)this + 208, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 72) + 4))((char *)this + 288, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 92) + 4))((char *)this + 368, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 112) + 4))((char *)this + 448, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 132) + 16))((char *)this + 528, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 142) + 4))((char *)this + 568, a2);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517223935);
}


// address=[0x1318070]
// Decompiled from pairNode *__thiscall CAIPlayerAI::ProcessEvents(CAIPlayerAI *this)
void  CAIPlayerAI::ProcessEvents(void) {
  
  pairNode *result; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // [esp-Ch] [ebp-90h]
  int v14; // [esp-8h] [ebp-8Ch]
  int v15; // [esp-4h] [ebp-88h]
  int v16; // [esp+0h] [ebp-84h] BYREF
  int v17; // [esp+4h] [ebp-80h] BYREF
  CAISectorAI *v18; // [esp+8h] [ebp-7Ch]
  int v19; // [esp+Ch] [ebp-78h]
  int v20; // [esp+10h] [ebp-74h]
  int v21; // [esp+14h] [ebp-70h]
  int v22; // [esp+18h] [ebp-6Ch]
  int v23; // [esp+1Ch] [ebp-68h]
  int v24; // [esp+20h] [ebp-64h]
  int v25; // [esp+24h] [ebp-60h]
  __int64 v26; // [esp+28h] [ebp-5Ch]
  unsigned int v27; // [esp+30h] [ebp-54h]
  unsigned int v28; // [esp+34h] [ebp-50h]
  int v29; // [esp+38h] [ebp-4Ch] BYREF
  BOOL v30; // [esp+3Ch] [ebp-48h]
  BOOL v31; // [esp+40h] [ebp-44h]
  __int64 v32; // [esp+44h] [ebp-40h]
  int v33; // [esp+4Ch] [ebp-38h]
  int v34; // [esp+50h] [ebp-34h]
  int v35; // [esp+54h] [ebp-30h]
  int v36; // [esp+58h] [ebp-2Ch]
  int v37; // [esp+5Ch] [ebp-28h]
  int v38; // [esp+60h] [ebp-24h]
  unsigned int v39; // [esp+64h] [ebp-20h] BYREF
  int v40; // [esp+68h] [ebp-1Ch]
  int v41; // [esp+6Ch] [ebp-18h]
  int j; // [esp+70h] [ebp-14h]
  bool v43; // [esp+77h] [ebp-Dh]
  int v44; // [esp+78h] [ebp-Ch]
  pairNode *i; // [esp+7Ch] [ebp-8h]
  pairNode *v46; // [esp+80h] [ebp-4h]

  v46 = this;
  v24 = TAIStaticPtrVector<CAISectorAI,8>::Size((char *)this + 72);
  result = CAIEventQueue::PeekAIEvent((pairNode *)((char *)v46 + 108), 1);
  for ( i = result; i; i = result )
  {
    v44 = 0;
    v2 = CAIEvent::Type(i);
    v41 = v2 - 18;
    switch ( v2 )
    {
      case 18:
        v23 = CAIEvent::Data1(i);
        v37 = CAIEvent::Data2(i);
        v3 = CAIPlayerAI::PlayerId(v46);
        if ( v23 != v3 && BBSupportDbgReport(2, "AI\\AI_PlayerAI.cpp", 561, "iPlayerId == PlayerId()") == 1 )
          __debugbreak();
        if ( v37 <= 0 && BBSupportDbgReport(2, "AI\\AI_PlayerAI.cpp", 562, "iEntityId > 0") == 1 )
          __debugbreak();
        if ( IAIEnvironment::EntityWarriorType(v37) )
          CAITaskForce::AddEntity((char *)v46 + 372, v37, 0);
        break;
      case 19:
        v22 = CAIEvent::Data1(i);
        v34 = CAIEvent::Data2(i);
        v4 = CAIPlayerAI::PlayerId(v46);
        if ( v22 == v4 && IAIEnvironment::EntityWarriorType(v34) )
          CAITaskForce::AddEntity((char *)v46 + 132, v34, 0);
        break;
      case 20:
        v21 = CAIEvent::Data1(i);
        v40 = CAIEvent::Data2(i);
        v33 = CAIEvent::Data3(i);
        v5 = CAIPlayerAI::PlayerId(v46);
        if ( v21 != v5 && BBSupportDbgReport(2, "AI\\AI_PlayerAI.cpp", 596, "iPlayerId == PlayerId()") == 1 )
          __debugbreak();
        if ( v40 <= 0 && BBSupportDbgReport(2, "AI\\AI_PlayerAI.cpp", 597, "iEntityId > 0") == 1 )
          __debugbreak();
        v44 = IAIEnvironment::EntitySectorId(v40);
        if ( v33 != 1 || v44 <= 0 || CAIPlayerAI::ExistsSectorAI(v46, v44) )
        {
          if ( v33 == 2 || v44 <= 0 )
          {
            v44 = -1;
            CAITaskForce::AddEntity((char *)v46 + 132, v40, 0);
          }
        }
        else
        {
          CAITaskForce::AddEntity((char *)v46 + 452, v40, 0);
          v44 = -1;
        }
        break;
      case 21:
      case 22:
        v20 = CAIEvent::Data1(i);
        v36 = CAIEvent::Data2(i);
        v6 = CAIPlayerAI::PlayerId(v46);
        if ( v20 != v6 && BBSupportDbgReport(2, "AI\\AI_PlayerAI.cpp", 629, "iPlayerId == PlayerId()") == 1 )
          __debugbreak();
        if ( v36 <= 0 && BBSupportDbgReport(2, "AI\\AI_PlayerAI.cpp", 630, "iEntityId > 0") == 1 )
          __debugbreak();
        if ( IAIEnvironment::EntityWarriorType(v36) )
          CAITaskForce::AddEntity((char *)v46 + 132, v36, 0);
        break;
      case 25:
        v38 = CAIEvent::Data2(i);
        v19 = CAIEvent::Data3(i);
        IAIEnvironment::EntityGetWarriorTypeAndSectorId(v38, &v39, &v29);
        HIDWORD(v32) = v39 == 10;
        LODWORD(v32) = v39 == 11;
        if ( v32 )
        {
          if ( v19 == 1 )
            CAITaskForce::AddEntity((char *)v46 + 292, v38, 0);
          else
            CAITaskForce::AddEntity((char *)v46 + 212, v38, 0);
        }
        else
        {
          v31 = v39 != 0;
          v30 = v29 > 0;
          if ( v30 && v31 )
            CAIPlayerAI::AddEntityToSectorReservoir(v46, v38, v39, v29);
        }
        break;
      case 28:
        if ( *((_BYTE *)v46 + 8) )
        {
          v44 = -1;
        }
        else
        {
          v35 = CAIEvent::Data2(i);
          v7 = CAIEvent::Data3(i);
          v27 = CAIEvent::UnpackA(v7);
          v8 = CAIEvent::Data3(i);
          v28 = CAIEvent::UnpackB(v8);
          if ( v35 == 8 || v35 == 13 )
          {
            if ( !IAIEnvironment::WorldInWorld(v27, v28)
              && BBSupportDbgReport(2, "AI\\AI_PlayerAI.cpp", 692, "g_pAIEnv->WorldInWorld(iTargetX, iTargetY)") == 1 )
            {
              __debugbreak();
            }
            v44 = -1;
            v43 = v35 == 8;
            CAIPlayerAI::MoveNewWarShips(v46, v27, v28, v35 == 8);
          }
          else
          {
            CAIPlayerAI::MoveToSuicideSquad(v46);
            if ( CAITaskForce::GetPositionOfFirstEntity((pairNode *)((char *)v46 + 572), &v16, &v17) )
            {
              v9 = IAIEnvironment::TickCounter();
              CAIAgent::UpdateScheduleTimeIfLess((pairNode *)((char *)v46 + 532), v9);
            }
          }
        }
        break;
      case 29:
        if ( !*((_BYTE *)v46 + 8) )
          v44 = -1;
        break;
      default:
        break;
    }
    if ( v44 >= 0 )
    {
      for ( j = 0; j < v24; ++j )
      {
        v18 = (CAISectorAI *)TAIStaticPtrVector<CAISectorAI,8>::operator[](j);
        v10 = CAISectorAI::SectorId(v18);
        HIDWORD(v26) = v10 == v44;
        LODWORD(v26) = v44 == 0;
        if ( v26 )
        {
          v25 = TAIStaticPtrVector<CAISectorAI,8>::operator[](j);
          v15 = CAIEvent::Data3(i);
          v14 = CAIEvent::Data2(i);
          v13 = CAIEvent::Data1(i);
          v11 = CAIEvent::Type(i);
          (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v25 + 28))(v25, v11, v13, v14, v15);
        }
        v12 = TAIStaticPtrVector<CAISectorAI,8>::Size((char *)v46 + 72);
        if ( v12 != v24
          && BBSupportDbgReport(2, "AI\\AI_PlayerAI.cpp", 729, "m_cSectorAIs.Size() == iSectorAINumber") == 1 )
        {
          __debugbreak();
        }
      }
    }
    result = CAIEventQueue::PeekAIEvent((pairNode *)((char *)v46 + 108), 1);
  }
  return result;
}


// address=[0x1318660]
// Decompiled from int __thiscall CAIPlayerAI::CalculateSectorAndEcoSectorIds(CAIPlayerAI *this)
void  CAIPlayerAI::CalculateSectorAndEcoSectorIds(void) {
  
  int result; // eax
  CAISectorAI *v2; // eax
  int v3; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  result = TAIStaticPtrVector<CAISectorAI,8>::Size((char *)this + 72);
  v3 = result;
  for ( i = 0; i < v3; ++i )
  {
    v2 = (CAISectorAI *)TAIStaticPtrVector<CAISectorAI,8>::operator[](i);
    CAISectorAI::CalculateSectorIdAndEcoSectorIds(v2);
    if ( TAIStaticPtrVector<CAISectorAI,8>::Size((char *)this + 72) != v3
      && BBSupportDbgReport(2, "AI\\AI_PlayerAI.cpp", 423, "m_cSectorAIs.Size() == iSectorAINumber") == 1 )
    {
      __debugbreak();
    }
    result = i + 1;
  }
  return result;
}


// address=[0x13186e0]
// Decompiled from int __thiscall CAIPlayerAI::FillGeneralReservoir(CAIPlayerAI *this)
int  CAIPlayerAI::FillGeneralReservoir(void) {
  
  int v2; // [esp+0h] [ebp-24h]
  int EntityInfo; // [esp+4h] [ebp-20h]
  int v4; // [esp+8h] [ebp-1Ch]
  int v5; // [esp+Ch] [ebp-18h]
  int *k; // [esp+10h] [ebp-14h]
  int *i; // [esp+14h] [ebp-10h]
  int m; // [esp+18h] [ebp-Ch]
  int j; // [esp+1Ch] [ebp-8h]

  v5 = 0;
  for ( i = (int *)*((_DWORD *)this + 5); *i; ++i )
  {
    for ( j = IAIEnvironment::SettlerGetFirstReadyAndCheckedOutSettlerId(*((_DWORD *)this + 3), *i);
          j;
          j = IAIEnvironment::SettlerGetNextReadyAndCheckedOutSettlerId(j) )
    {
      EntityInfo = IAIEnvironment::EntityGetEntityInfo(j, 0);
      if ( !EntityInfo || !CAIEntityInfo::TaskForce(EntityInfo) )
      {
        CAITaskForce::AddEntity((char *)this + 132, j, 0);
        ++v5;
      }
    }
  }
  v4 = 0;
  for ( k = (int *)*((_DWORD *)this + 6); *k; ++k )
  {
    for ( m = IAIEnvironment::VehicleGetFirstReadyAndCheckedOutVehicleId(*((_DWORD *)this + 3), *k);
          m;
          m = IAIEnvironment::VehicleGetNextReadyAndCheckedOutVehicleId(m) )
    {
      v2 = IAIEnvironment::EntityGetEntityInfo(m, 0);
      if ( !v2 || !CAIEntityInfo::TaskForce(v2) )
      {
        CAITaskForce::AddEntity((char *)this + 132, m, 0);
        ++v4;
      }
    }
  }
  return v4 + v5;
}


// address=[0x1318820]
// Decompiled from int __thiscall CAIPlayerAI::AddEntityToSectorReservoir(char *this, int a2, int a3, int a4)
void  CAIPlayerAI::AddEntityToSectorReservoir(int,enum T_AI_WARRIOR_TYPE,int) {
  
  int result; // eax
  int v5; // eax
  CAISectorAI *v6; // [esp+0h] [ebp-10h]
  int v7; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  if ( !a3 && BBSupportDbgReport(2, "AI\\AI_PlayerAI.cpp", 434, "_tWarriorType != AI_WARRIOR_TYPE_NONE") == 1 )
    __debugbreak();
  if ( a4 <= 0 && BBSupportDbgReport(2, "AI\\AI_PlayerAI.cpp", 435, "_iSectorId > 0") == 1 )
    __debugbreak();
  v7 = TAIStaticPtrVector<CAISectorAI,8>::Size(this + 72);
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= v7 )
      break;
    v6 = (CAISectorAI *)TAIStaticPtrVector<CAISectorAI,8>::operator[](i);
    if ( CAISectorAI::SectorId(v6) == a4 )
    {
      v5 = TAIStaticPtrVector<CAISectorAI,8>::operator[](i);
      return CAISectorAI::AddEntityToReservoir(v5, a2, a3);
    }
    if ( TAIStaticPtrVector<CAISectorAI,8>::Size(this + 72) != v7
      && BBSupportDbgReport(2, "AI\\AI_PlayerAI.cpp", 450, "m_cSectorAIs.Size() == iSectorAINumber") == 1 )
    {
      __debugbreak();
    }
  }
  return result;
}


// address=[0x1318920]
// Decompiled from int __thiscall CAIPlayerAI::MoveNewWarShips(CAIPlayerAI *this, int a2, int a3, bool a4)
void  CAIPlayerAI::MoveNewWarShips(int,int,bool) {
  
  int result; // eax
  int v5; // [esp+0h] [ebp-10h]
  int v6; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  result = CAITaskForce::FirstEntity((char *)this + 292);
  for ( i = result; i; i = v5 )
  {
    v5 = CAIEntityInfo::Next(i);
    v6 = CAIEntityInfo::EntityId(i);
    IAIEnvironment::MovingEntitySendMoveCommand(v6, a2, a3, 1);
    if ( a4 )
      IAIEnvironment::VehicleSendQueuedVanishCommand(v6);
    result = (*(int (__thiscall **)(char *, int))(*((_DWORD *)this + 73) + 24))((char *)this + 292, i);
  }
  return result;
}


// address=[0x13189b0]
// Decompiled from char __thiscall CAIPlayerAI::ExistsSectorAI(CAIPlayerAI *this, int a2)
bool  CAIPlayerAI::ExistsSectorAI(int) {
  
  CAISectorAI *v3; // [esp+0h] [ebp-10h]
  int v4; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  v4 = TAIStaticPtrVector<CAISectorAI,8>::Size((char *)this + 72);
  for ( i = 0; i < v4; ++i )
  {
    v3 = (CAISectorAI *)TAIStaticPtrVector<CAISectorAI,8>::operator[](i);
    if ( CAISectorAI::SectorId(v3) == a2 )
      return 1;
  }
  return 0;
}


// address=[0x1318a10]
// Decompiled from int __thiscall CAIPlayerAI::MoveToSuicideSquad(CAIPlayerAI *this)
void  CAIPlayerAI::MoveToSuicideSquad(void) {
  
  int result; // eax
  int v2; // [esp+4h] [ebp-18h]
  unsigned int v3; // [esp+8h] [ebp-14h] BYREF
  int v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+10h] [ebp-Ch] BYREF
  int i; // [esp+14h] [ebp-8h]
  CAIPlayerAI *v7; // [esp+18h] [ebp-4h]

  v7 = this;
  TAIStaticPtrVector<CAISectorAI,8>::Size((char *)this + 72);
  result = CAITaskForce::FirstEntity((char *)v7 + 452);
  for ( i = result; i; i = v2 )
  {
    v2 = CAIEntityInfo::Next(i);
    v4 = CAIEntityInfo::EntityId(i);
    IAIEnvironment::EntityGetWarriorTypeAndSectorId(v4, &v3, &v5);
    if ( CAIPlayerAI::ExistsSectorAI(v7, v5) )
      result = CAIPlayerAI::AddEntityToSectorReservoir(v7, v4, v3, v5);
    else
      result = (*(int (__thiscall **)(char *, int, _DWORD))(*((_DWORD *)v7 + 143) + 20))((char *)v7 + 572, i, 0);
  }
  return result;
}


