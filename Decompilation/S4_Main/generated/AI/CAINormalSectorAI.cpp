#include "CAINormalSectorAI.h"

// Definitions for class CAINormalSectorAI

// address=[0x1323250]
// Decompiled from std::bad_function_call *__thiscall CAINormalSectorAI::CAINormalSectorAI(  std::bad_function_call *this,  pairNode *a2,  int a3)
 CAINormalSectorAI::CAINormalSectorAI(class CAIPlayerAI & a2, int a3) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v8; // [esp+4h] [ebp-20h]
  int v9; // [esp+8h] [ebp-1Ch] BYREF
  int v10; // [esp+Ch] [ebp-18h] BYREF
  int i; // [esp+10h] [ebp-14h]
  std::bad_function_call *v12; // [esp+14h] [ebp-10h]
  int v13; // [esp+20h] [ebp-4h]

  v12 = this;
  CAISectorAI::CAISectorAI(this);
  v13 = 0;
  *(_DWORD *)v12 = &CAINormalSectorAI::_vftable_;
  CAIGoalCache::CAIGoalCache((std::bad_function_call *)((char *)v12 + 264));
  CAIGoalCache::CAIGoalCache((std::bad_function_call *)((char *)v12 + 660));
  CAIGoalCache::CAIGoalCache((std::bad_function_call *)((char *)v12 + 1056));
  CAIGoalCache::CAIGoalCache((std::bad_function_call *)((char *)v12 + 1452));
  CAIGoalCache::CAIGoalCache((std::bad_function_call *)((char *)v12 + 1848));
  CAITaskForceReservoir::CAITaskForceReservoir((std::bad_function_call *)((char *)v12 + 2244), *((_DWORD *)a2 + 3));
  LOBYTE(v13) = 1;
  CAITaskForceReservoir::CAITaskForceReservoir((std::bad_function_call *)((char *)v12 + 2324), *((_DWORD *)a2 + 3));
  LOBYTE(v13) = 2;
  CAITaskForceReservoir::CAITaskForceReservoir((std::bad_function_call *)((char *)v12 + 2404), *((_DWORD *)a2 + 3));
  LOBYTE(v13) = 3;
  CAITaskForceReservoir::CAITaskForceReservoir((std::bad_function_call *)((char *)v12 + 2484), *((_DWORD *)a2 + 3));
  LOBYTE(v13) = 4;
  CAITaskForceReservoir::CAITaskForceReservoir((std::bad_function_call *)((char *)v12 + 2564), *((_DWORD *)a2 + 3));
  LOBYTE(v13) = 5;
  CAITaskForceReservoir::CAITaskForceReservoir((std::bad_function_call *)((char *)v12 + 2644), *((_DWORD *)a2 + 3));
  LOBYTE(v13) = 6;
  CAITaskForceReservoir::CAITaskForceReservoir((std::bad_function_call *)((char *)v12 + 2724), *((_DWORD *)a2 + 3));
  CAIAgentAttack::CAIAgentAttack((std::bad_function_call *)((char *)v12 + 2804));
  CAIAgentEvalDefence::CAIAgentEvalDefence((std::bad_function_call *)((char *)v12 + 2884));
  CAIAgentEvalOffence::CAIAgentEvalOffence((std::bad_function_call *)((char *)v12 + 2928));
  CAIAgentGeologists::CAIAgentGeologists((std::bad_function_call *)((char *)v12 + 2968));
  CAIAgentGardeners::CAIAgentGardeners((std::bad_function_call *)((char *)v12 + 3008));
  CAIAgentIntruderCombat::CAIAgentIntruderCombat((std::bad_function_call *)((char *)v12 + 3048));
  CAIAgentMovingHome::CAIAgentMovingHome((std::bad_function_call *)((char *)v12 + 3092));
  CAIAgentPioneers::CAIAgentPioneers((std::bad_function_call *)((char *)v12 + 3132));
  CAIAgentRecruitment::CAIAgentRecruitment((std::bad_function_call *)((char *)v12 + 3204));
  CAIAgentSuicideMissions::CAIAgentSuicideMissions((std::bad_function_call *)((char *)v12 + 3248));
  CAIAgentSquads::CAIAgentSquads((std::bad_function_call *)((char *)v12 + 3288));
  CAIAgentThieves::CAIAgentThieves((std::bad_function_call *)((char *)v12 + 3328));
  CAIAgentTowerOccupation::CAIAgentTowerOccupation((std::bad_function_call *)((char *)v12 + 3368));
  CMilitaryBuildingIterator::CMilitaryBuildingIterator((std::bad_function_call *)((char *)v12 + 3408));
  CMilitaryBuildingIterator::CMilitaryBuildingIterator((std::bad_function_call *)((char *)v12 + 3444));
  TAIStaticPtrVector<CAIEcoSectorAIEx,512>::TAIStaticPtrVector<CAIEcoSectorAIEx,512>((char *)v12 + 3480);
  LOBYTE(v13) = 21;
  if ( CAIPlayerAI::Race(a2) == 3
    && BBSupportDbgReport(2, "AI\\AI_SectorAINormal.cpp", 289, "_rPlayerAI.Race() != RACE_DARK") == 1 )
  {
    __debugbreak();
  }
  v8 = CAIPlayerAI::PlayerId(a2);
  v3 = IAIEnvironment::AlliancesPlayerBit(v8);
  CMilitaryBuildingIterator::Init((std::bad_function_call *)((char *)v12 + 3408), v3);
  v4 = IAIEnvironment::AlliancesPlayerEnemyBits(v8);
  CMilitaryBuildingIterator::Init((std::bad_function_call *)((char *)v12 + 3444), v4);
  CAINormalSectorAI::AttachAgentEx(v12, (std::bad_function_call *)((char *)v12 + 2804), 0x64u, 0x100u, 8u);
  CAINormalSectorAI::AttachAgentEx(v12, (std::bad_function_call *)((char *)v12 + 2884), 5u, 0x100u, 8u);
  CAINormalSectorAI::AttachAgentEx(v12, (std::bad_function_call *)((char *)v12 + 2928), 0xAu, 0x100u, 8u);
  CAINormalSectorAI::AttachAgentEx(v12, (std::bad_function_call *)((char *)v12 + 3008), 0x64u, 0x100u, 8u);
  CAINormalSectorAI::AttachAgentEx(v12, (std::bad_function_call *)((char *)v12 + 2968), 0x64u, 0x100u, 8u);
  CAINormalSectorAI::AttachAgentEx(v12, (std::bad_function_call *)((char *)v12 + 3048), 0x25u, 0x100u, 8u);
  CAINormalSectorAI::AttachAgentEx(v12, (std::bad_function_call *)((char *)v12 + 3092), 0x64u, 0x100u, 8u);
  CAINormalSectorAI::AttachAgentEx(v12, (std::bad_function_call *)((char *)v12 + 3132), 0x64u, 0x100u, 8u);
  CAINormalSectorAI::AttachAgentEx(v12, (std::bad_function_call *)((char *)v12 + 3204), 0xFAu, 0x100u, 8u);
  CAINormalSectorAI::AttachAgentEx(v12, (std::bad_function_call *)((char *)v12 + 3248), 0x64u, 0x100u, 8u);
  CAINormalSectorAI::AttachAgentEx(v12, (std::bad_function_call *)((char *)v12 + 3288), 0x64u, 0x100u, 8u);
  CAINormalSectorAI::AttachAgentEx(v12, (std::bad_function_call *)((char *)v12 + 3328), 0x64u, 0x100u, 8u);
  CAINormalSectorAI::AttachAgentEx(v12, (std::bad_function_call *)((char *)v12 + 3368), 0x96u, 0x100u, 8u);
  for ( i = 0; i <= 14; ++i )
  {
    *((_DWORD *)v12 + i + 8) = CAITaskForces::CreateTaskForce(v8, 1);
    if ( !*((_DWORD *)v12 + i + 8)
      && BBSupportDbgReport(2, "AI\\AI_SectorAINormal.cpp", 321, "m_pReservoir[i] != 0") == 1 )
    {
      __debugbreak();
    }
  }
  if ( a3 <= 0 )
    return v12;
  v9 = IAIEnvironment::UnpackXFast(a3);
  v10 = IAIEnvironment::UnpackYFast(a3);
  *((_DWORD *)v12 + 58) = 0;
  *((_DWORD *)v12 + 59) = v9;
  *((_DWORD *)v12 + 60) = v10;
  IAIEnvironment::GetNearestNoneBlockedPosition(&v9, &v10);
  *((_DWORD *)v12 + 62) = v9;
  *((_DWORD *)v12 + 63) = v10;
  v5 = IAIEnvironment::WorldIndex(v9, v10);
  *((_DWORD *)v12 + 64) = v5;
  v6 = IAIEnvironment::WorldSectorId(*((_DWORD *)v12 + 64));
  *((_DWORD *)v12 + 65) = v6;
  CAINormalSectorAI::ScanForNewEcoSectors(v12);
  return v12;
}


// address=[0x13237a0]
// Decompiled from void __thiscall CAINormalSectorAI::Load(CAINormalSectorAI *this, struct IS4Chunk *a2)
void  CAINormalSectorAI::Load(class IS4Chunk & a2) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517150208);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1, 1);
  CAISectorAI::Load(this, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517158398);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 66))((char *)this + 264, a2);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 165))((char *)this + 660, a2);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 264))((char *)this + 1056, a2);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 363))((char *)this + 1452, a2);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 462))((char *)this + 1848, a2);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 561))((char *)this + 2244, a2);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 581))((char *)this + 2324, a2);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 601))((char *)this + 2404, a2);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 621))((char *)this + 2484, a2);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 641))((char *)this + 2564, a2);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 661))((char *)this + 2644, a2);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 681))((char *)this + 2724, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 701) + 12))((char *)this + 2804, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 721) + 12))((char *)this + 2884, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 732) + 12))((char *)this + 2928, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 742) + 12))((char *)this + 2968, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 752) + 12))((char *)this + 3008, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 762) + 12))((char *)this + 3048, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 773) + 12))((char *)this + 3092, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 783) + 12))((char *)this + 3132, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 801) + 12))((char *)this + 3204, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 812) + 12))((char *)this + 3248, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 822) + 12))((char *)this + 3288, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 832) + 12))((char *)this + 3328, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 842) + 12))((char *)this + 3368, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517150207);
  CAISectorAI::CheckBasePosition(this);
  CAINormalSectorAI::ScanForNewEcoSectors(this);
}


// address=[0x1323ab0]
// Decompiled from int __thiscall CAINormalSectorAI::Save(CAINormalSectorAI *this, struct IS4Chunk *a2)
void  CAINormalSectorAI::Save(class IS4Chunk & a2) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517150208);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 1);
  CAISectorAI::Save(this, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517158398);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 66) + 4))((char *)this + 264, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 165) + 4))((char *)this + 660, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 264) + 4))((char *)this + 1056, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 363) + 4))((char *)this + 1452, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 462) + 4))((char *)this + 1848, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 561) + 4))((char *)this + 2244, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 581) + 4))((char *)this + 2324, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 601) + 4))((char *)this + 2404, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 621) + 4))((char *)this + 2484, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 641) + 4))((char *)this + 2564, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 661) + 4))((char *)this + 2644, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 681) + 4))((char *)this + 2724, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 701) + 16))((char *)this + 2804, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 721) + 16))((char *)this + 2884, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 732) + 16))((char *)this + 2928, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 742) + 16))((char *)this + 2968, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 752) + 16))((char *)this + 3008, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 762) + 16))((char *)this + 3048, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 773) + 16))((char *)this + 3092, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 783) + 16))((char *)this + 3132, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 801) + 16))((char *)this + 3204, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 812) + 16))((char *)this + 3248, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 822) + 16))((char *)this + 3288, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 832) + 16))((char *)this + 3328, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 842) + 16))((char *)this + 3368, a2);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517150207);
}


// address=[0x1323dc0]
// Decompiled from int __thiscall CAINormalSectorAI::PostAIEvent(CAINormalSectorAI *this, int a2, int a3, int a4, int a5)
void  CAINormalSectorAI::PostAIEvent(int a2, int a3, int a4, int a5) {
  
  int result; // eax
  CAIEcoSectorAIEx *v6; // eax
  int v7; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  CAIEventQueue::PostAIEvent((CAINormalSectorAI *)((char *)this + 8), a2, a3, a4, a5);
  result = TAIStaticPtrVector<CAIEcoSectorAIEx,512>::Size((char *)this + 3480);
  v7 = result;
  for ( i = 0; i < v7; ++i )
  {
    v6 = (CAIEcoSectorAIEx *)TAIStaticPtrVector<CAIEcoSectorAIEx,512>::operator[](i);
    CAIEcoSectorAIEx::PostAIEvent(v6, a2, a3, a4, a5);
    result = TAIStaticPtrVector<CAIEcoSectorAIEx,512>::Size((char *)this + 3480);
    if ( result != v7 )
    {
      result = BBSupportDbgReport(2, "AI\\AI_SectorAINormal.cpp", 525, "m_cEcoSectorAIs.Size() == iEcoSectorAINumber");
      if ( result == 1 )
        __debugbreak();
    }
  }
  return result;
}


// address=[0x1323e80]
// Decompiled from void __thiscall CAINormalSectorAI::Execute(CAINormalSectorAI *this)
void  CAINormalSectorAI::Execute(void) {
  
  CAIPlayerScriptVars *v1; // eax
  CAIEcoSectorAIEx *v2; // eax
  int v3; // [esp+0h] [ebp-14h]
  int v4; // [esp+4h] [ebp-10h]
  int i; // [esp+8h] [ebp-Ch]
  int j; // [esp+Ch] [ebp-8h]

  CAISectorAI::ProcessEvents(this);
  v3 = TAIStaticPtrVector<CAIEcoSectorAIEx,512>::Size((char *)this + 3480);
  v1 = (CAIPlayerScriptVars *)CAIPlayersScriptVars::operator[](*(_DWORD *)(*((_DWORD *)this + 1) + 12));
  if ( (CAIPlayerScriptVars::Flags(v1) & 1) != 0 )
  {
    for ( i = 0; i < v3; ++i )
    {
      v2 = (CAIEcoSectorAIEx *)TAIStaticPtrVector<CAIEcoSectorAIEx,512>::operator[](i);
      CAIEcoSectorAIEx::ClearEventQueue(v2);
    }
  }
  else
  {
    for ( j = 0; j < v3; ++j )
    {
      v4 = TAIStaticPtrVector<CAIEcoSectorAIEx,512>::operator[](j);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(v4);
    }
  }
}


// address=[0x1323f40]
// Decompiled from char __thiscall CAINormalSectorAI::ProcessEvent(int this, pairNode *a2)
bool  CAINormalSectorAI::ProcessEvent(class CAIEvent const * a2) {
  
  char result; // al
  int v3; // eax
  int v4; // eax
  pairNode *v5; // eax
  int v6; // eax
  int v7; // [esp+14h] [ebp-78h]
  int v8; // [esp+18h] [ebp-74h]
  int v9; // [esp+1Ch] [ebp-70h]
  int UniqueId; // [esp+20h] [ebp-6Ch]
  unsigned int v11; // [esp+24h] [ebp-68h]
  int v12; // [esp+28h] [ebp-64h]
  int v13; // [esp+2Ch] [ebp-60h]
  int v14; // [esp+30h] [ebp-5Ch]
  int v15; // [esp+34h] [ebp-58h]
  int v16; // [esp+40h] [ebp-4Ch]
  int v17; // [esp+4Ch] [ebp-40h]
  int v18; // [esp+54h] [ebp-38h]
  int v19; // [esp+58h] [ebp-34h]
  int v20; // [esp+5Ch] [ebp-30h]
  int EconomyAIIndex; // [esp+60h] [ebp-2Ch]
  int v22; // [esp+64h] [ebp-28h]
  int v23; // [esp+68h] [ebp-24h]
  int v24; // [esp+6Ch] [ebp-20h]
  int TargetForSuicideMission; // [esp+74h] [ebp-18h]
  int v26; // [esp+78h] [ebp-14h]
  int i; // [esp+80h] [ebp-Ch]
  struct CAITaskForce *TaskForce; // [esp+84h] [ebp-8h]

  if ( !a2 && BBSupportDbgReport(2, "AI\\AI_SectorAINormal.cpp", 536, "_pEvent != 0") == 1 )
    __debugbreak();
  switch ( CAIEvent::Type(a2) )
  {
    case 3:
      v8 = CAIEvent::Data3(a2);
      if ( v8 == *(_DWORD *)(CAISectorAI::PlayerAI(this) + 12) )
      {
        v7 = CAIEvent::Data2(a2);
        CAIEvent::Data1(a2);
        v6 = CAISectorAI::PlayerAI(this);
        (*(void (__thiscall **)(int, int, _DWORD, int, int))(*(_DWORD *)this + 28))(
          this,
          31,
          *(_DWORD *)(v6 + 12),
          v7,
          10);
      }
      result = 1;
      break;
    case 0xD:
      v14 = CAIEvent::Data2(a2);
      v15 = CAIEvent::Data3(a2);
      CAINormalSectorAI::CreateNewEcoSectorAIIfNecessaryAndMeaningful((CAINormalSectorAI *)this, v14, v15);
      result = 1;
      break;
    case 0xE:
      CAIEvent::Data2(a2);
      CAIEvent::Data3(a2);
      CAINormalSectorAI::DeleteInvalidEcoSectorAIs((CAINormalSectorAI *)this);
      result = 1;
      break;
    case 0x10:
      v3 = CAIEvent::Data2(a2);
      v26 = CAIEvent::UnpackA(v3);
      v4 = CAIEvent::Data2(a2);
      v12 = CAIEvent::UnpackB(v4);
      v13 = CAIEvent::Data3(a2);
      if ( IAIEnvironment::EcoSectorCheckId(v12, v13) )
      {
        CAINormalSectorAI::DeleteInvalidEcoSectorAIs((CAINormalSectorAI *)this);
        EconomyAIIndex = CAINormalSectorAI::GetEconomyAIIndex((CAINormalSectorAI *)this, v26);
        if ( EconomyAIIndex >= 0 )
        {
          v5 = (pairNode *)TAIStaticPtrVector<CAIEcoSectorAIEx,512>::operator[](EconomyAIIndex);
          v11 = CAIEcoSectorAIEx::CreationTime(v5);
          if ( v11 < IAIEnvironment::TickCounter() )
          {
            UniqueId = IAIEnvironment::EcoSectorGetUniqueId(v26);
            CAINormalSectorAI::DeleteEcoSectorAI((CAINormalSectorAI *)this, v26);
            CAINormalSectorAI::CreateNewEcoSectorAIIfNecessaryAndMeaningful((CAINormalSectorAI *)this, v26, UniqueId);
          }
        }
      }
      result = 1;
      break;
    case 0x14:
      v9 = CAIEvent::Data2(a2);
      CAITaskForce::AddEntity((void *)(this + 2484), v9, 0);
      result = 1;
      break;
    case 0x1B:
      goto LABEL_6;
    case 0x1C:
      v22 = CAIEvent::Data2(a2);
      if ( CAITaskForce::NumberOfEntities((pairNode *)(this + 2484)) > 0 )
      {
        if ( v22 == 9 )
          v23 = 4;
        else
          v23 = 3;
        TaskForce = CAITaskForceGroup::CreateTaskForce((CAITaskForceGroup *)(this + 92), v23);
        if ( !TaskForce && BBSupportDbgReport(2, "AI\\AI_SectorAINormal.cpp", 580, "pSquad != 0") == 1 )
          __debugbreak();
        for ( i = CAITaskForce::FirstEntity(this + 2484); i; i = v16 )
        {
          v16 = CAIEntityInfo::Next(i);
          v17 = CAIEntityInfo::EntityId(i);
          if ( ((1 << IAIEnvironment::EntityWarriorType(v17)) & 0x1C) != 0 )
            (*(void (__thiscall **)(struct CAITaskForce *, int, _DWORD))(*(_DWORD *)TaskForce + 20))(TaskForce, i, 0);
        }
        if ( CAITaskForce::NumberOfEntities(TaskForce) <= 0 )
        {
          if ( TaskForce )
            (*(void (__thiscall **)(struct CAITaskForce *, int))(*(_DWORD *)TaskForce + 8))(TaskForce, 1);
        }
        else
        {
          CAINormalSectorAI::EvaluateNextEnemyMilitaryBuilding((CAINormalSectorAI *)this);
          TargetForSuicideMission = 0;
          if ( v22 == 9 )
            TargetForSuicideMission = CAINormalSectorAI::FindTargetForSuicideMission(TaskForce);
          if ( TargetForSuicideMission <= 0 )
          {
            CAINormalSectorAI::MoveSquadHome((CAINormalSectorAI *)this, TaskForce);
          }
          else
          {
            (*(void (__thiscall **)(struct CAITaskForce *, int, int, _DWORD))(*(_DWORD *)TaskForce + 32))(
              TaskForce,
              4,
              TargetForSuicideMission,
              0);
            CAISectorAI::AwakeAgent((struct CAIAgent *)(this + 3248));
          }
        }
      }
      result = 1;
      break;
    case 0x1F:
      v24 = CAIEvent::Data2(a2);
      v20 = IAIEnvironment::EntityOwnerId(v24);
      CAIGoalCache::Insert((CAIGoalCache *)(this + 1452), v24, 0x7FFFFFFF);
      CAIAgentAttack::AttackNow((CAIAgentAttack *)(this + 2804), v20, 10);
LABEL_6:
      v18 = CAIEvent::Data2(a2);
      v19 = CAIEvent::Data3(a2);
      CAIAgentAttack::AttackNow((CAIAgentAttack *)(this + 2804), v18, v19);
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}


// address=[0x1324390]
// Decompiled from void __thiscall CAINormalSectorAI::AttachAgentEx(  CAINormalSectorAI *this,  struct CAINormalSectorAgent *a2,  unsigned int a3,  unsigned int a4,  unsigned int a5)
void  CAINormalSectorAI::AttachAgentEx(class CAINormalSectorAgent & a2, unsigned int a3, unsigned int a4, unsigned int a5) {
  
  CAINormalSectorAgent::AttachSectorAI(a2, this);
  CAIScheduler::AddAgent((CAIScheduler *)(*((_DWORD *)this + 1) + 28), a2, a3, a4, a5);
}


// address=[0x13243d0]
// Decompiled from void __thiscall CAINormalSectorAI::DbgPrint(pairNode **this)
void  CAINormalSectorAI::DbgPrint(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // [esp-Ch] [ebp-14h]
  int v4; // [esp-8h] [ebp-10h]
  int v5; // [esp-4h] [ebp-Ch]
  int i; // [esp+0h] [ebp-8h]

  v5 = CAISectorAI::SectorId((CAISectorAI *)this);
  v4 = CAISectorAI::BaseY((CAISectorAI *)this);
  v3 = CAISectorAI::BaseX((struct CAISectorAI *)this);
  v1 = CAIPlayerAI::PlayerId(this[1]);
  IAIEnvironment::DbgTracePrintF("SectorAI player %i, base ( %4i, %4i ), sector %i", v1, v3, v4, v5);
  CAIGoalCache::DbgPrint((CAIGoalCache *)(this + 66), "Defence goal 'Influ'");
  CAIGoalCache::DbgPrint((CAIGoalCache *)(this + 165), "Defence goal 'Owner'");
  CAIGoalCache::DbgPrint((CAIGoalCache *)(this + 264), "Offence goal 'Dist'");
  CAIGoalCache::DbgPrint((CAIGoalCache *)(this + 363), "Offence goal 'Influ'");
  CAIGoalCache::DbgPrint((CAIGoalCache *)(this + 462), "Offence goal 'Res'");
  for ( i = 0; i <= 14; ++i )
  {
    if ( this[i + 8] )
    {
      v2 = CAITaskForce::NumberOfEntities(this[i + 8]);
      IAIEnvironment::DbgTracePrintF("Reservoir %i: %i entities.", i, v2);
    }
  }
}


// address=[0x13244c0]
// Decompiled from void __thiscall CAINormalSectorAI::OccupationCheck(pairNode **this, int a2)
void  CAINormalSectorAI::OccupationCheck(int a2) {
  
  int v2; // eax
  int v3; // [esp-8h] [ebp-2Ch]
  int InnerPoint; // [esp+0h] [ebp-24h]
  CPropertySet *v5; // [esp+4h] [ebp-20h]
  _DWORD *v6; // [esp+8h] [ebp-1Ch]
  CAIEntityInfo *v7; // [esp+Ch] [ebp-18h]
  int v8; // [esp+10h] [ebp-14h]
  CPropertySet *EntityInfo; // [esp+18h] [ebp-Ch]
  int v11; // [esp+1Ch] [ebp-8h]
  int v12; // [esp+1Ch] [ebp-8h]

  if ( a2 <= 0 && BBSupportDbgReport(2, "AI\\AI_SectorAINormal.cpp", 66, "_iBuildingId > 0") == 1 )
    __debugbreak();
  v6 = (_DWORD *)CBuildingMgr::operator[](a2);
  EntityInfo = (CPropertySet *)IAIEnvironment::EntityGetEntityInfo(a2, 1u);
  if ( !EntityInfo && BBSupportDbgReport(2, "AI\\AI_SectorAINormal.cpp", 72, "pBuildingEntityInfo != 0") == 1 )
    __debugbreak();
  if ( (unsigned __int8)CBuilding::HaveInhabitant() )
  {
    CAIEntityInfo::SetTargetId(EntityInfo, 0);
  }
  else
  {
    v11 = CAIEntityInfo::TargetId(EntityInfo);
    if ( v11 > 0 )
    {
      v7 = (CAIEntityInfo *)IAIEnvironment::EntityGetEntityInfo(v11, 0);
      if ( !v7 || CAIEntityInfo::TargetId(v7) != a2 )
        v11 = 0;
    }
    if ( !v11 )
    {
      v8 = CBuilding::EnsignPackedXY(v6);
      CAISectorAI::MoveOneDefendingFighterToReservoir(this, v8, 2, 1);
      v12 = CAISectorAI::RecruitNearestFighterForTaskForce(this, this + 641, v8, 2, 9999);
      if ( v12 > 0 )
      {
        CAIEntityInfo::SetTargetId(EntityInfo, v12);
        v5 = (CPropertySet *)IAIEnvironment::EntityGetEntityInfo(v12, 1u);
        if ( !v5 && BBSupportDbgReport(2, "AI\\AI_SectorAINormal.cpp", 108, "pOccupationEntityInfo != 0") == 1 )
          __debugbreak();
        CAIEntityInfo::SetTargetId(v5, a2);
        InnerPoint = CAISectorAI::FindInnerPoint(this, v8);
        v3 = IAIEnvironment::UnpackYFast(InnerPoint);
        v2 = IAIEnvironment::UnpackXFast(InnerPoint);
        IAIEnvironment::MovingEntitySendMoveCommand(v12, v2, v3, 1);
      }
    }
  }
}


// address=[0x1324670]
// Decompiled from int __thiscall CAINormalSectorAI::FindTargetForSuicideMission(char *this, pairNode *a2)
int  CAINormalSectorAI::FindTargetForSuicideMission(class CAITaskForce * a2) {
  
  pairNode *v3; // eax
  int v4; // eax
  CAIGoal *v5; // eax
  int v6; // [esp+0h] [ebp-34h] BYREF
  int v7; // [esp+4h] [ebp-30h]
  int v8; // [esp+8h] [ebp-2Ch] BYREF
  int v9; // [esp+Ch] [ebp-28h] BYREF
  char *v11; // [esp+14h] [ebp-20h]
  int v12; // [esp+18h] [ebp-1Ch]
  CAIGoalCache *v13; // [esp+1Ch] [ebp-18h]
  int v14; // [esp+20h] [ebp-14h] BYREF
  int v15; // [esp+24h] [ebp-10h] BYREF
  int v16; // [esp+28h] [ebp-Ch]
  int v17; // [esp+2Ch] [ebp-8h]
  bool v18; // [esp+32h] [ebp-2h]
  bool v19; // [esp+33h] [ebp-1h]

  v11 = this;
  if ( !a2 && BBSupportDbgReport(2, "AI\\AI_SectorAINormal.cpp", 1724, "_pSquad != 0") == 1 )
    __debugbreak();
  if ( CAITaskForce::Class(a2) != 2
    && BBSupportDbgReport(2, "AI\\AI_SectorAINormal.cpp", 1725, "_pSquad->Class() == AI_TASK_FORCE_CLASS_SQUAD") == 1 )
  {
    __debugbreak();
  }
  if ( !CAITaskForce::NumberOfEntities(a2) )
    return 0;
  v12 = (*(int (__thiscall **)(pairNode *, int))(*(_DWORD *)a2 + 16))(a2, 2);
  if ( v12 < 0 && BBSupportDbgReport(2, "AI\\AI_SectorAINormal.cpp", 1736, "iNumberOfSwordsman >= 0") == 1 )
    __debugbreak();
  if ( v12 <= 0 )
    return 0;
  CAITaskForce::GetPositionOfFirstEntity(a2, &v14, &v15);
  if ( (v14 < 0 || v15 < 0)
    && BBSupportDbgReport(2, "AI\\AI_SectorAINormal.cpp", 1748, "(iSquadX >= 0) && (iSquadY >= 0)") == 1 )
  {
    __debugbreak();
  }
  v17 = 0;
  v16 = 0x4000;
  v19 = CAITaskForce::Command(a2) == 4 && CAITaskForce::IsGoalValid(a2, 1);
  v18 = v19;
  if ( v19 )
  {
    v17 = CAITaskForce::CmdGoal(a2);
    if ( v17 <= 0 && BBSupportDbgReport(2, "AI\\AI_SectorAINormal.cpp", 1759, "iGoalId > 0") == 1 )
      __debugbreak();
    if ( IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(v17, 12) )
    {
      IAIEnvironment::BuildingGetEnsignPosition(v17, &v8, &v9);
      v16 = IAIEnvironment::GridDistance(v8 - v14, v9 - v15);
    }
  }
  if ( v16 > 10 )
  {
    v3 = (pairNode *)CAISectorAI::PlayerAI(v11);
    v4 = CAIPlayerAI::PlayerId(v3);
    if ( CScanner::FindNearestEnemyTowerInSector((struct SFindNearestResult *)&v6, v14, v15, 32, v4) )
    {
      if ( v6 <= 0 && BBSupportDbgReport(2, "AI\\AI_SectorAINormal.cpp", 1778, "sResult.m_iEntityId > 0") == 1 )
        __debugbreak();
      if ( !IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(v6, 12)
        && BBSupportDbgReport(
             2,
             "AI\\AI_SectorAINormal.cpp",
             1779,
             "g_pAIEnv->EntityIsAliveAndOfGivenWarriorType(sResult.m_iEntityId, AI_WARRIOR_TYPE_TOWER_BUILDING)") == 1 )
      {
        __debugbreak();
      }
      if ( v7 < v16 - 10 )
      {
        v17 = v6;
        v16 = v7;
      }
    }
  }
  if ( v17 > 0 )
    return v17;
  v13 = (CAIGoalCache *)(v11 + 1452);
  CAIGoalCache::DeleteInvalidGoalsIfNecessary((CAIGoalCache *)(v11 + 1452));
  if ( (int)CAIGoalCache::NumberOfCachedGoals(v13) > 0 )
  {
    v5 = CAIGoalCache::Goal(v13, 0);
    v17 = CAIGoal::EntityId(v5);
  }
  if ( !IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(v17, 12) )
    return 0;
  return v17;
}


// address=[0x1324930]
// Decompiled from void __thiscall CAINormalSectorAI::MoveSquadHome(CAINormalSectorAI *this, struct CAITaskForce *a2)
void  CAINormalSectorAI::MoveSquadHome(class CAITaskForce * a2) {
  
  int v2; // eax

  if ( !a2 && BBSupportDbgReport(2, "AI\\AI_SectorAINormal.cpp", 1841, "_pSquad != 0") == 1 )
    __debugbreak();
  if ( CAITaskForce::Class(a2) != 2
    && BBSupportDbgReport(2, "AI\\AI_SectorAINormal.cpp", 1842, "_pSquad->Class() == AI_TASK_FORCE_CLASS_SQUAD") == 1 )
  {
    __debugbreak();
  }
  CAITaskForce::ChangeType(a2, 3);
  v2 = CAISectorAI::BasePackedXY(this);
  (*(void (__thiscall **)(struct CAITaskForce *, int, int, _DWORD))(*(_DWORD *)a2 + 32))(a2, 1, v2, 0);
  CAISectorAI::AwakeAgent((CAINormalSectorAI *)((char *)this + 3092));
}


// address=[0x1324cf0]
// Decompiled from char __thiscall CAINormalSectorAI::EvaluateNextEnemyMilitaryBuilding(CAINormalSectorAI *this)
void  CAINormalSectorAI::EvaluateNextEnemyMilitaryBuilding(void) {
  
  int Building; // eax
  pairNode *v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  _DWORD *v6; // eax
  int v7; // eax
  _DWORD *v8; // eax
  int v9; // eax
  int v11; // [esp-4h] [ebp-38h]
  int v12; // [esp+Ch] [ebp-28h]
  int v13; // [esp+18h] [ebp-1Ch]
  int v15; // [esp+20h] [ebp-14h]
  int v16[3]; // [esp+24h] [ebp-10h] BYREF

  v12 = CAISectorAI::SectorId(this);
  if ( v12 )
  {
    v15 = CBuildingIteratorBase::BuildingId((CAINormalSectorAI *)((char *)this + 3464));
    if ( !v15
      || !IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(v15, 12)
      || (v2 = (pairNode *)CAISectorAI::PlayerAI(this),
          v11 = CAIPlayerAI::PlayerId(v2),
          v3 = IAIEnvironment::EntityOwnerId(v15),
          LOBYTE(Building) = IAIEnvironment::AlliancesAllied(v3, v11),
          (_BYTE)Building) )
    {
      Building = CGenericBuildingIterator::FirstBuilding((CAINormalSectorAI *)((char *)this + 3444));
      v15 = Building;
    }
    v13 = 0;
    while ( v13 < 10 && v15 != 0 )
    {
      ++v13;
      v4 = CBuildingMgr::operator[](v15);
      v5 = CBuilding::EnsignWorldIdx(v4);
      if ( IAIEnvironment::WorldSectorId(v5) == v12 && IAIEnvironment::EntityIsReady(v15) )
      {
        v6 = (_DWORD *)CBuildingMgr::operator[](v15);
        v7 = CBuilding::EnsignPackedXY(v6);
        Y16X16::UnpackXFast(v7);
        v8 = (_DWORD *)CBuildingMgr::operator[](v15);
        v9 = CBuilding::EnsignPackedXY(v8);
        Y16X16::UnpackYFast(v9);
        v13 += 13;
        if ( CAISectorAI::EvaluateEnemyMilitaryBuilding(this, v15, (struct SAIEvalResults *)v16) )
        {
          CAIGoalCache::Insert((CAINormalSectorAI *)((char *)this + 1056), v15, v16[0]);
          CAIGoalCache::Insert((CAINormalSectorAI *)((char *)this + 1452), v15, v16[1]);
          CAIGoalCache::Insert((CAINormalSectorAI *)((char *)this + 1848), v15, v16[2]);
        }
      }
      Building = CGenericBuildingIterator::NextBuilding((CAINormalSectorAI *)((char *)this + 3444));
      v15 = Building;
    }
  }
  else
  {
    if ( BBSupportDbgReport(
           1,
           "AI\\AI_SectorAINormal.cpp",
           215,
           "CAINormalSectorAI::EvaluateNextEnemyMilitaryBuilding(): SectorId() == NO_SECTOR!") == 1 )
      __debugbreak();
    LOBYTE(Building) = 0;
  }
  return Building;
}


// address=[0x1324f20]
// Decompiled from char __thiscall CAINormalSectorAI::EvaluateNextOwnMilitaryBuilding(CAINormalSectorAI *this)
bool  CAINormalSectorAI::EvaluateNextOwnMilitaryBuilding(void) {
  
  int v2; // esi
  pairNode *v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp+18h] [ebp-54h]
  int v8; // [esp+1Ch] [ebp-50h]
  int v9; // [esp+28h] [ebp-44h]
  int v10; // [esp+2Ch] [ebp-40h]
  char v12; // [esp+37h] [ebp-35h]
  int Building; // [esp+38h] [ebp-34h]
  char v14; // [esp+3Fh] [ebp-2Dh]
  _DWORD v15[9]; // [esp+40h] [ebp-2Ch] BYREF
  int v16; // [esp+64h] [ebp-8h]

  v8 = CAISectorAI::SectorId(this);
  if ( v8 )
  {
    v12 = 0;
    Building = CBuildingIteratorBase::BuildingId((CAINormalSectorAI *)((char *)this + 3428));
    if ( Building )
    {
      if ( !IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(Building, 12)
        || (v2 = IAIEnvironment::EntityOwnerId(Building),
            v3 = (pairNode *)CAISectorAI::PlayerAI(this),
            v2 != CAIPlayerAI::PlayerId(v3)) )
      {
        Building = CGenericBuildingIterator::FirstBuilding((CAINormalSectorAI *)((char *)this + 3408));
      }
    }
    else
    {
      v12 = 1;
      Building = CGenericBuildingIterator::FirstBuilding((CAINormalSectorAI *)((char *)this + 3408));
    }
    v10 = 0;
    v14 = 0;
    while ( v10 < 50 && Building != 0 )
    {
      ++v10;
      v4 = CBuildingMgr::operator[](Building);
      v5 = CBuilding::EnsignWorldIdx(v4);
      if ( IAIEnvironment::WorldSectorId(v5) == v8 )
      {
        v10 += 10;
        CAISectorAI::EvaluateOwnMilitaryBuilding((pairNode **)this, Building, (struct SAIDefenceEvalResult *)v15);
        v9 = v16;
        if ( v16 >= 4095 )
          v7 = 4095;
        else
          v7 = v16;
        CAIGoalCache::Insert((CAINormalSectorAI *)((char *)this + 264), Building, v7 + ((4 * v16 - v15[8]) << 12));
        CAIGoalCache::Insert((CAINormalSectorAI *)((char *)this + 660), Building, 4 * v15[7] - v15[3]);
        v14 |= v9 > 0;
        CAINormalSectorAI::OccupationCheck((pairNode **)this, Building);
        Building = CGenericBuildingIterator::NextBuilding((CAINormalSectorAI *)((char *)this + 3408));
      }
    }
    if ( !v14 )
      return v12;
    v6 = IAIEnvironment::TickCounter();
    CAIAgent::UpdateScheduleTimeIfLess((CAINormalSectorAI *)((char *)this + 3288), v6 + 15);
    return v12;
  }
  else
  {
    if ( BBSupportDbgReport(
           1,
           "AI\\AI_SectorAINormal.cpp",
           133,
           "CAINormalSectorAI::EvaluateNextEnemyMilitaryBuilding(): SectorId() == 0!") == 1 )
      __debugbreak();
    return 0;
  }
}


// address=[0x1325170]
// Decompiled from int __thiscall CAINormalSectorAI::PostAIEventToAllEcoSectorAIs(CAINormalSectorAI *this, int a2, int a3, int a4, int a5)
void  CAINormalSectorAI::PostAIEventToAllEcoSectorAIs(int a2, int a3, int a4, int a5) {
  
  int result; // eax
  CAIEcoSectorAIEx *v6; // eax
  int v7; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  result = TAIStaticPtrVector<CAIEcoSectorAIEx,512>::Size((char *)this + 3480);
  v7 = result;
  for ( i = 0; i < v7; ++i )
  {
    v6 = (CAIEcoSectorAIEx *)TAIStaticPtrVector<CAIEcoSectorAIEx,512>::operator[](i);
    CAIEcoSectorAIEx::PostAIEvent(v6, a2, a3, a4, a5);
    if ( TAIStaticPtrVector<CAIEcoSectorAIEx,512>::Size((char *)this + 3480) != v7
      && BBSupportDbgReport(2, "AI\\AI_SectorAINormal.cpp", 506, "m_cEcoSectorAIs.Size() == iEcoSectorAINumber") == 1 )
    {
      __debugbreak();
    }
    result = i + 1;
  }
  return result;
}


// address=[0x1325d10]
// Decompiled from void __thiscall CAINormalSectorAI::~CAINormalSectorAI(CAINormalSectorAI *this)
 CAINormalSectorAI::~CAINormalSectorAI(void) {
  
  int v1; // [esp+0h] [ebp-4h]

  TAIStaticPtrVector<CAIEcoSectorAIEx,512>::~TAIStaticPtrVector<CAIEcoSectorAIEx,512>(this);
  CAIAgentTowerOccupation::~CAIAgentTowerOccupation((CAIAgentTowerOccupation *)(v1 + 3368));
  CAIAgentThieves::~CAIAgentThieves((CAIAgentThieves *)(v1 + 3328));
  CAIAgentSquads::~CAIAgentSquads((CAIAgentSquads *)(v1 + 3288));
  CAIAgentSuicideMissions::~CAIAgentSuicideMissions((CAIAgentSuicideMissions *)(v1 + 3248));
  CAIAgentRecruitment::~CAIAgentRecruitment((CAIAgentRecruitment *)(v1 + 3204));
  CAIAgentPioneers::~CAIAgentPioneers((CAIAgentPioneers *)(v1 + 3132));
  CAIAgentMovingHome::~CAIAgentMovingHome((CAIAgentMovingHome *)(v1 + 3092));
  CAIAgentIntruderCombat::~CAIAgentIntruderCombat((CAIAgentIntruderCombat *)(v1 + 3048));
  CAIAgentGardeners::~CAIAgentGardeners((CAIAgentGardeners *)(v1 + 3008));
  CAIAgentGeologists::~CAIAgentGeologists((CAIAgentGeologists *)(v1 + 2968));
  CAIAgentEvalOffence::~CAIAgentEvalOffence((CAIAgentEvalOffence *)(v1 + 2928));
  CAIAgentEvalDefence::~CAIAgentEvalDefence((CAIAgentEvalDefence *)(v1 + 2884));
  CAIAgentAttack::~CAIAgentAttack((CAIAgentAttack *)(v1 + 2804));
  CAITaskForceReservoir::~CAITaskForceReservoir((CAITaskForceReservoir *)(v1 + 2724));
  CAITaskForceReservoir::~CAITaskForceReservoir((CAITaskForceReservoir *)(v1 + 2644));
  CAITaskForceReservoir::~CAITaskForceReservoir((CAITaskForceReservoir *)(v1 + 2564));
  CAITaskForceReservoir::~CAITaskForceReservoir((CAITaskForceReservoir *)(v1 + 2484));
  CAITaskForceReservoir::~CAITaskForceReservoir((CAITaskForceReservoir *)(v1 + 2404));
  CAITaskForceReservoir::~CAITaskForceReservoir((CAITaskForceReservoir *)(v1 + 2324));
  CAITaskForceReservoir::~CAITaskForceReservoir((CAITaskForceReservoir *)(v1 + 2244));
  CAISectorAI::~CAISectorAI((CAISectorAI *)v1);
}


// address=[0x13261a0]
// Decompiled from char __thiscall CAINormalSectorAI::IsNormalPlayerSector(CAINormalSectorAI *this)
bool  CAINormalSectorAI::IsNormalPlayerSector(void)const {
  
  return 1;
}


// address=[0x13249d0]
// Decompiled from int __thiscall CAINormalSectorAI::GetEconomyAIIndex(CAINormalSectorAI *this, int a2)
int  CAINormalSectorAI::GetEconomyAIIndex(int a2) {
  
  CAIEcoSectorAIEx *v2; // eax
  int v4; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  v4 = TAIStaticPtrVector<CAIEcoSectorAIEx,512>::Size((char *)this + 3480);
  for ( i = 0; i < v4; ++i )
  {
    v2 = (CAIEcoSectorAIEx *)TAIStaticPtrVector<CAIEcoSectorAIEx,512>::operator[](i);
    if ( CAIEcoSectorAIEx::EcoSectorId(v2) == a2 )
      return i;
  }
  return -1;
}


// address=[0x1324a40]
// Decompiled from char __thiscall CAINormalSectorAI::IsEcoSectorAIActive(CAINormalSectorAI *this, int a2)
bool  CAINormalSectorAI::IsEcoSectorAIActive(int a2) {
  
  CAIEcoSectorAIEx *v2; // eax
  int v4; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  v4 = TAIStaticPtrVector<CAIEcoSectorAIEx,512>::Size((char *)this + 3480);
  for ( i = 0; i < v4; ++i )
  {
    v2 = (CAIEcoSectorAIEx *)TAIStaticPtrVector<CAIEcoSectorAIEx,512>::operator[](i);
    if ( CAIEcoSectorAIEx::EcoSectorId(v2) == a2 )
      return 1;
  }
  return 0;
}


// address=[0x1324aa0]
// Decompiled from bool __thiscall CAINormalSectorAI::IsEcoSectorAIMeaningful(CAINormalSectorAI *this, int a2)
bool  CAINormalSectorAI::IsEcoSectorAIMeaningful(int a2) {
  
  pairNode *v2; // eax
  int v4; // [esp+4h] [ebp-Ch]

  v4 = IAIEnvironment::EcoSectorOwnerId(a2);
  v2 = (pairNode *)CAISectorAI::PlayerAI(this);
  if ( CAIPlayerAI::PlayerId(v2) == v4 )
    return IAIEnvironment::EcoSectorNumberOfPossibleCarriers(a2) >= 5;
  BBSupportTracePrintF(3, "### CAINormalSectorAI::IsEcoSectorAIMeaningful(): Invalid eco-sector owner! ###");
  return 0;
}


// address=[0x1324b10]
// Decompiled from char __thiscall CAINormalSectorAI::DeleteEcoSectorAI(CAINormalSectorAI *this, int a2)
bool  CAINormalSectorAI::DeleteEcoSectorAI(int a2) {
  
  int EconomyAIIndex; // [esp+4h] [ebp-4h]

  EconomyAIIndex = CAINormalSectorAI::GetEconomyAIIndex(this, a2);
  if ( EconomyAIIndex < 0 )
    return 0;
  TAIStaticPtrVector<CAIEcoSectorAIEx,512>::Release(EconomyAIIndex);
  return 1;
}


// address=[0x1324b50]
// Decompiled from int __thiscall CAINormalSectorAI::DeleteInvalidEcoSectorAIs(CAINormalSectorAI *this)
void  CAINormalSectorAI::DeleteInvalidEcoSectorAIs(void) {
  
  int result; // eax
  CAIEcoSectorAIEx *v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v4 = 0;
  while ( 1 )
  {
    result = TAIStaticPtrVector<CAIEcoSectorAIEx,512>::Size((char *)this + 3480);
    if ( v4 >= result )
      break;
    v2 = (CAIEcoSectorAIEx *)TAIStaticPtrVector<CAIEcoSectorAIEx,512>::operator[](v4);
    if ( CAIEcoSectorAIEx::IsEcoSectorValid(v2) )
      ++v4;
    else
      TAIStaticPtrVector<CAIEcoSectorAIEx,512>::Release(v4);
  }
  return result;
}


// address=[0x1324bc0]
// Decompiled from char __thiscall CAINormalSectorAI::CreateNewEcoSectorAIIfNecessaryAndMeaningful(  CAINormalSectorAI *this,  int a2,  int a3)
void  CAINormalSectorAI::CreateNewEcoSectorAIIfNecessaryAndMeaningful(int a2, int a3) {
  
  int v3; // eax
  int SectorId; // esi
  CAIEcoSectorAIEx *EcoSectorAIEx; // eax

  LOBYTE(v3) = IAIEnvironment::EcoSectorCheckId(a2, a3);
  if ( !(_BYTE)v3 )
    return v3;
  CAINormalSectorAI::DeleteInvalidEcoSectorAIs(this);
  LOBYTE(v3) = CAINormalSectorAI::IsEcoSectorAIActive(this, a2);
  if ( (_BYTE)v3 )
    return v3;
  SectorId = IAIEnvironment::EcoSectorGetSectorId(a2);
  v3 = CAISectorAI::SectorId(this);
  if ( SectorId != v3 )
    return v3;
  LOBYTE(v3) = CAINormalSectorAI::IsEcoSectorAIMeaningful(this, a2);
  if ( !(_BYTE)v3 )
    return v3;
  EcoSectorAIEx = CAIEcoSectorAIEx::CreateEcoSectorAIEx(this, a2);
  LOBYTE(v3) = TAIStaticPtrVector<CAIEcoSectorAIEx,512>::PushBack(EcoSectorAIEx);
  return v3;
}


// address=[0x1324c60]
// Decompiled from void __thiscall CAINormalSectorAI::ScanForNewEcoSectors(CAINormalSectorAI *this)
void  CAINormalSectorAI::ScanForNewEcoSectors(void) {
  
  int v1; // eax
  CAIEcoSectorAIEx *EcoSectorAIEx; // eax
  void *v3; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  v3 = (void *)CAISectorAI::SectorId(this);
  IAIEnvironment::EcoSectorGetFirstEcoSectorInSector(v3);
  for ( i = v1; i > 0; i = IAIEnvironment::EcoSectorGetNextEcoSectorInSector((int)v3, i) )
  {
    if ( !CAINormalSectorAI::IsEcoSectorAIActive(this, i) && CAINormalSectorAI::IsEcoSectorAIMeaningful(this, i) )
    {
      EcoSectorAIEx = CAIEcoSectorAIEx::CreateEcoSectorAIEx(this, i);
      TAIStaticPtrVector<CAIEcoSectorAIEx,512>::PushBack(EcoSectorAIEx);
    }
  }
}


