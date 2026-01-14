#include "all_headers.h"

// Definitions for class CAIDarkTribeSectorAI

// address=[0x1303820]
// Decompiled from int __thiscall CAIDarkTribeSectorAI::EconomyAI(CAIDarkTribeSectorAI *this)
class IAIDarkTribeEcoAI *  CAIDarkTribeSectorAI::EconomyAI(void)const {
  
  return *((_DWORD *)this + 261);
}


// address=[0x1322250]
// Decompiled from void __thiscall CAIDarkTribeSectorAI::~CAIDarkTribeSectorAI(CAIDarkTribeSectorAI *this)
 CAIDarkTribeSectorAI::~CAIDarkTribeSectorAI(void) {
  
  *(_DWORD *)this = &CAIDarkTribeSectorAI::_vftable_;
  if ( *((_DWORD *)this + 261) )
  {
    (***((void (__thiscall ****)(_DWORD))this + 261))(*((_DWORD *)this + 261));
    *((_DWORD *)this + 261) = 0;
  }
  CAIEventQueue::~CAIEventQueue((CAIDarkTribeSectorAI *)((char *)this + 1020));
  CAITaskForceReservoir::~CAITaskForceReservoir((CAIDarkTribeSectorAI *)((char *)this + 940));
  CAITaskForceReservoir::~CAITaskForceReservoir((CAIDarkTribeSectorAI *)((char *)this + 860));
  CAITaskForceReservoir::~CAITaskForceReservoir((CAIDarkTribeSectorAI *)((char *)this + 780));
  CAITaskForceReservoir::~CAITaskForceReservoir((CAIDarkTribeSectorAI *)((char *)this + 700));
  CAITaskForceReservoir::~CAITaskForceReservoir((CAIDarkTribeSectorAI *)((char *)this + 620));
  CAIAgentDarkTribeManakopterHalls::~CAIAgentDarkTribeManakopterHalls((CAIDarkTribeSectorAI *)((char *)this + 576));
  CAIAgentDarkTribeSquadManager::~CAIAgentDarkTribeSquadManager((CAIDarkTribeSectorAI *)((char *)this + 532));
  CAIAgentDarkTribeManakopters::~CAIAgentDarkTribeManakopters((CAIDarkTribeSectorAI *)((char *)this + 492));
  CAIAgentDarkTribeShamans::~CAIAgentDarkTribeShamans((CAIDarkTribeSectorAI *)((char *)this + 452));
  CAIAgentDarkTribeRecruitment::~CAIAgentDarkTribeRecruitment((CAIDarkTribeSectorAI *)((char *)this + 412));
  CAIAgentDarkTribeMushroomFarms::~CAIAgentDarkTribeMushroomFarms((CAIDarkTribeSectorAI *)((char *)this + 372));
  CAIAgentDarkTribeDarkGardeners::~CAIAgentDarkTribeDarkGardeners((CAIDarkTribeSectorAI *)((char *)this + 332));
  CAIAgentDarkTribeAttack::~CAIAgentDarkTribeAttack((CAIDarkTribeSectorAI *)((char *)this + 264));
  CAISectorAI::~CAISectorAI(this);
}


// address=[0x1322390]
// Decompiled from int __thiscall CAIDarkTribeSectorAI::Load(CAIDarkTribeSectorAI *this, struct IS4Chunk *a2)
void  CAIDarkTribeSectorAI::Load(class IS4Chunk &) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517154304);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1, 1);
  CAISectorAI::Load(this, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517158398);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 66) + 12))((char *)this + 264, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 83) + 12))((char *)this + 332, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 93) + 12))((char *)this + 372, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 103) + 12))((char *)this + 412, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 113) + 12))((char *)this + 452, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 133) + 12))((char *)this + 532, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 123) + 12))((char *)this + 492, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 144) + 12))((char *)this + 576, a2);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517154303);
}


// address=[0x13224d0]
// Decompiled from int __thiscall CAIDarkTribeSectorAI::Save(CAIDarkTribeSectorAI *this, struct IS4Chunk *a2)
void  CAIDarkTribeSectorAI::Save(class IS4Chunk &) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517154304);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 1);
  CAISectorAI::Save(this, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517158398);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 66) + 16))((char *)this + 264, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 83) + 16))((char *)this + 332, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 93) + 16))((char *)this + 372, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 103) + 16))((char *)this + 412, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 113) + 16))((char *)this + 452, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 133) + 16))((char *)this + 532, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 123) + 16))((char *)this + 492, a2);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 144) + 16))((char *)this + 576, a2);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517154303);
}


// address=[0x1322610]
// Decompiled from void __thiscall CAIDarkTribeSectorAI::PostAIEvent(CAIDarkTribeSectorAI *this, int a2, int a3, int a4, int a5)
void  CAIDarkTribeSectorAI::PostAIEvent(int,int,int,int) {
  
  CAIEventQueue::PostAIEvent((CAIDarkTribeSectorAI *)((char *)this + 8), a2, a3, a4, a5);
  CAIEventQueue::PostAIEvent((CAIDarkTribeSectorAI *)((char *)this + 1020), a2, a3, a4, a5);
}


// address=[0x1322660]
// Decompiled from int __thiscall CAIDarkTribeSectorAI::Execute(CAIDarkTribeSectorAI *this)
void  CAIDarkTribeSectorAI::Execute(void) {
  
  CAISectorAI::ProcessEvents(this);
  return (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 261) + 4))(*((_DWORD *)this + 261));
}


// address=[0x1322690]
// Decompiled from char __thiscall CAIDarkTribeSectorAI::FindMushroomFarm(  CAIDarkTribeSectorAI *this,  struct _Cnd_internal_imp_t **a2,  struct _Mtx_internal_imp_t **a3,  int a4,  int a5)
bool  CAIDarkTribeSectorAI::FindMushroomFarm(int &,int &,int,int) {
  
  pairNode *v6; // eax
  int v7; // eax
  pairNode *v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  char *v12; // [esp-4h] [ebp-4Ch]
  int v13; // [esp+4h] [ebp-44h]
  int v14; // [esp+10h] [ebp-38h]
  int v15; // [esp+14h] [ebp-34h]
  int v16; // [esp+18h] [ebp-30h]
  struct _Cnd_internal_imp_t *v17; // [esp+1Ch] [ebp-2Ch]
  struct _Mtx_internal_imp_t *v18; // [esp+20h] [ebp-28h]
  int v19; // [esp+24h] [ebp-24h]
  int v20; // [esp+28h] [ebp-20h]
  int v21; // [esp+2Ch] [ebp-1Ch]
  struct _Mtx_internal_imp_t *v23; // [esp+34h] [ebp-14h] BYREF
  int i; // [esp+38h] [ebp-10h]
  int v25; // [esp+3Ch] [ebp-Ch]
  struct _Cnd_internal_imp_t *v26; // [esp+40h] [ebp-8h] BYREF
  signed int v27; // [esp+44h] [ebp-4h]

  v17 = *a2;
  v18 = *a3;
  v19 = IAIEnvironment::WorldSectorId((int)*a2, (int)*a3);
  if ( v19 <= 0 )
    return 0;
  v6 = (pairNode *)CAISectorAI::PlayerAI(this);
  v7 = CAIPlayerAI::PlayerId(v6);
  v16 = IAIEnvironment::AlliancesAllianceId(v7);
  v20 = 0;
  v13 = -1048576;
  v8 = (pairNode *)CAISectorAI::PlayerAI(this);
  v9 = CAIPlayerAI::PlayerId(v8);
  for ( i = IAIEnvironment::BuildingGetFirstBuildingId(v9, 49); i; i = IAIEnvironment::BuildingGetNextBuildingOfSameType(i) )
  {
    IAIEnvironment::BuildingGetEnsignPosition(i, (int *)&v26, (int *)&v23);
    if ( IAIEnvironment::WorldSectorId((int)v26, (int)v23) == v19 )
    {
      v21 = IAIEnvironment::GridDistance(v26 - v17, v23 - v18);
      v14 = CInfluMap::AllyValueXY(v26, v23, v16);
      v15 = CInfluMap::EnemyValueXY(v26, v23, v16);
      v10 = CAISectorAI::BaseY(this);
      v12 = (char *)v26 - v10;
      v11 = CAISectorAI::BaseX(this);
      v25 = IAIEnvironment::GridDistance((char *)v26 - v11, v12);
      v27 = IAIEnvironment::Rand() % 0x20u - v21 - v14 / 2 + 4 * v15 - v25 / 8;
      if ( v21 < a4 )
        v27 -= 8 * (a4 - v21);
      if ( v14 <= 16 && v15 > 0 )
      {
        v27 += 50;
        if ( v25 < 50 )
          v27 += 50 - v25;
      }
      if ( v25 > a5 )
        v27 -= 32 * (v25 - a5);
      if ( v27 > v13 )
      {
        v13 = v27;
        v20 = i;
      }
    }
  }
  if ( !v20 )
    return 0;
  IAIEnvironment::BuildingGetEnsignPosition(v20, (int *)a2, (int *)a3);
  return 1;
}


// address=[0x1323210]
// Decompiled from void __thiscall CAIDarkTribeSectorAI::DbgPrint(CAIDarkTribeSectorAI *this)
void  CAIDarkTribeSectorAI::DbgPrint(void) {
  
  ;
}


// address=[0x1323240]
// Decompiled from char __thiscall CAIDarkTribeSectorAI::IsNormalPlayerSector(CAIDarkTribeSectorAI *this)
bool  CAIDarkTribeSectorAI::IsNormalPlayerSector(void)const {
  
  return 0;
}


// address=[0x1321d50]
// Decompiled from std::bad_function_call *__thiscall CAIDarkTribeSectorAI::CAIDarkTribeSectorAI(  std::bad_function_call *this,  pairNode *a2,  int a3)
 CAIDarkTribeSectorAI::CAIDarkTribeSectorAI(class CAIPlayerAI &,int) {
  
  struct IAIDarkTribeEcoAI *EcoAI; // eax
  _DWORD v5[2]; // [esp+4h] [ebp-18h] BYREF
  std::bad_function_call *v6; // [esp+Ch] [ebp-10h]
  int v7; // [esp+18h] [ebp-4h]

  v6 = this;
  CAISectorAI::CAISectorAI(this);
  v7 = 0;
  *(_DWORD *)v6 = &CAIDarkTribeSectorAI::_vftable_;
  CAIAgentDarkTribeAttack::CAIAgentDarkTribeAttack((std::bad_function_call *)((char *)v6 + 264));
  CAIAgentDarkTribeDarkGardeners::CAIAgentDarkTribeDarkGardeners((std::bad_function_call *)((char *)v6 + 332));
  CAIAgentDarkTribeMushroomFarms::CAIAgentDarkTribeMushroomFarms((std::bad_function_call *)((char *)v6 + 372));
  CAIAgentDarkTribeRecruitment::CAIAgentDarkTribeRecruitment((std::bad_function_call *)((char *)v6 + 412));
  CAIAgentDarkTribeShamans::CAIAgentDarkTribeShamans((std::bad_function_call *)((char *)v6 + 452));
  CAIAgentDarkTribeManakopters::CAIAgentDarkTribeManakopters((std::bad_function_call *)((char *)v6 + 492));
  CAIAgentDarkTribeSquadManager::CAIAgentDarkTribeSquadManager((std::bad_function_call *)((char *)v6 + 532));
  CAIAgentDarkTribeManakopterHalls::CAIAgentDarkTribeManakopterHalls((std::bad_function_call *)((char *)v6 + 576));
  LOBYTE(v7) = 8;
  CAITaskForceReservoir::CAITaskForceReservoir((std::bad_function_call *)((char *)v6 + 620), *((_DWORD *)a2 + 3));
  LOBYTE(v7) = 9;
  CAITaskForceReservoir::CAITaskForceReservoir((std::bad_function_call *)((char *)v6 + 700), *((_DWORD *)a2 + 3));
  LOBYTE(v7) = 10;
  CAITaskForceReservoir::CAITaskForceReservoir((std::bad_function_call *)((char *)v6 + 780), *((_DWORD *)a2 + 3));
  LOBYTE(v7) = 11;
  CAITaskForceReservoir::CAITaskForceReservoir((std::bad_function_call *)((char *)v6 + 860), *((_DWORD *)a2 + 3));
  LOBYTE(v7) = 12;
  CAITaskForceReservoir::CAITaskForceReservoir((std::bad_function_call *)((char *)v6 + 940), *((_DWORD *)a2 + 3));
  CAIEventQueue::CAIEventQueue((std::bad_function_call *)((char *)v6 + 1020));
  LOBYTE(v7) = 14;
  if ( CAIPlayerAI::Race(a2) != 3
    && BBSupportDbgReport(2, "AI\\AI_SectorAIDark.cpp", 51, "_rPlayerAI.Race() == RACE_DARK") == 1 )
  {
    __debugbreak();
  }
  CAIDarkTribeSectorAI::AttachAgentEx(v6, (std::bad_function_call *)((char *)v6 + 412), 0x64u, 0x100u, 8u);
  CAIDarkTribeSectorAI::AttachAgentEx(v6, (std::bad_function_call *)((char *)v6 + 332), 0x64u, 0x100u, 8u);
  CAIDarkTribeSectorAI::AttachAgentEx(v6, (std::bad_function_call *)((char *)v6 + 452), 0x64u, 0x100u, 8u);
  CAIDarkTribeSectorAI::AttachAgentEx(v6, (std::bad_function_call *)((char *)v6 + 492), 0x64u, 0x100u, 8u);
  CAIDarkTribeSectorAI::AttachAgentEx(v6, (std::bad_function_call *)((char *)v6 + 532), 0x64u, 0x100u, 8u);
  CAIDarkTribeSectorAI::AttachAgentEx(v6, (std::bad_function_call *)((char *)v6 + 372), 0x64u, 0x100u, 8u);
  CAIDarkTribeSectorAI::AttachAgentEx(v6, (std::bad_function_call *)((char *)v6 + 264), 0x64u, 0x100u, 8u);
  CAIDarkTribeSectorAI::AttachAgentEx(v6, (std::bad_function_call *)((char *)v6 + 576), 0x64u, 0x100u, 8u);
  *((_DWORD *)v6 + 11) = (char *)v6 + 620;
  *((_DWORD *)v6 + 15) = (char *)v6 + 700;
  *((_DWORD *)v6 + 10) = (char *)v6 + 940;
  *((_DWORD *)v6 + 12) = (char *)v6 + 780;
  *((_DWORD *)v6 + 17) = (char *)v6 + 860;
  if ( a3 <= 0 )
    return v6;
  *((_DWORD *)v6 + 58) = a3;
  *((_DWORD *)v6 + 61) = a3;
  if ( IAIEnvironment::EntityObjectType(a3) != 8
    && BBSupportDbgReport(
         2,
         "AI\\AI_SectorAIDark.cpp",
         75,
         "g_pAIEnv->EntityObjectType(_iHeadquarterId) == BUILDING_OBJ") == 1 )
  {
    __debugbreak();
  }
  if ( IAIEnvironment::EntityType(a3) != 50
    && IAIEnvironment::EntityType(a3) != 51
    && BBSupportDbgReport(
         2,
         "AI\\AI_SectorAIDark.cpp",
         76,
         "(g_pAIEnv->EntityType(_iHeadquarterId) == BUILDING_DARKTEMPLE) || (g_pAIEnv->EntityType(_iHeadquarterId) == BUILDING_FORTRESS)") == 1 )
  {
    __debugbreak();
  }
  IAIEnvironment::EntityGetPosition(a3, (int *)v6 + 59, (int *)v6 + 60);
  IAIEnvironment::BuildingGetEnsignPosition(a3, (int *)v6 + 62, (int *)v6 + 63);
  if ( !IAIEnvironment::WorldInWorld(*((_DWORD *)v6 + 59), *((_DWORD *)v6 + 60))
    && BBSupportDbgReport(
         2,
         "AI\\AI_SectorAIDark.cpp",
         81,
         "g_pAIEnv->WorldInWorld(m_sHeadquarterData.m_iOriginalBaseX, m_sHeadquarterData.m_iOriginalBaseY)") == 1 )
  {
    __debugbreak();
  }
  if ( !IAIEnvironment::WorldInWorld(*((_DWORD *)v6 + 62), *((_DWORD *)v6 + 63))
    && BBSupportDbgReport(
         2,
         "AI\\AI_SectorAIDark.cpp",
         82,
         "g_pAIEnv->WorldInWorld(m_sHeadquarterData.m_iCurrentBaseX, m_sHeadquarterData.m_iCurrentBaseY)") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)v6 + 64) = IAIEnvironment::WorldIndex(*((_DWORD *)v6 + 62), *((_DWORD *)v6 + 63));
  *((_DWORD *)v6 + 65) = IAIEnvironment::WorldSectorId(*((_DWORD *)v6 + 64));
  if ( *((int *)v6 + 65) <= 0
    && BBSupportDbgReport(2, "AI\\AI_SectorAIDark.cpp", 87, "m_sHeadquarterData.m_iCurrentSectorId > 0") == 1 )
  {
    __debugbreak();
  }
  v5[0] = CAIPlayerAI::PlayerId(a2);
  v5[1] = a3;
  EcoAI = IAIDarkTribeEcoAI::CreateEcoAI((const struct SAIDarkTribeEcoAIParams *)v5);
  *((_DWORD *)v6 + 261) = EcoAI;
  if ( !*((_DWORD *)v6 + 261) && BBSupportDbgReport(2, "AI\\AI_SectorAIDark.cpp", 98, "m_pEcoAI != 0") == 1 )
    __debugbreak();
  return v6;
}


// address=[0x13228d0]
// Decompiled from char __thiscall CAIDarkTribeSectorAI::ProcessEvent(_DWORD **this, pairNode *a2)
bool  CAIDarkTribeSectorAI::ProcessEvent(class CAIEvent const *) {
  
  int v3; // [esp+0h] [ebp-28h]
  int v4; // [esp+4h] [ebp-24h]
  int v5; // [esp+8h] [ebp-20h]
  int v6; // [esp+10h] [ebp-18h]
  int v7; // [esp+14h] [ebp-14h]
  int v8; // [esp+18h] [ebp-10h]
  int v9; // [esp+1Ch] [ebp-Ch]
  bool v11; // [esp+26h] [ebp-2h]

  if ( !a2 && BBSupportDbgReport(2, "AI\\AI_SectorAIDark.cpp", 241, "_pEvent != 0") == 1 )
    __debugbreak();
  v9 = CAIEvent::Type(a2);
  switch ( v9 )
  {
    case 20:
      v5 = CAIEvent::Data2(a2);
      CAISectorAI::AddEntityToReservoir((CAISectorAI *)this, v5);
      return 1;
    case 27:
      v8 = CAIEvent::Data2(a2);
      v6 = CAIEvent::Data3(a2);
      if ( v8 <= 0 )
        v7 = 0;
      else
        v7 = IAIEnvironment::AlliancesPlayerBit(v8);
      CAIAgentDarkTribeAttack::AttackWithShamans((CAIAgentDarkTribeAttack *)(this + 66), v7, v6, 1);
      return 1;
    case 29:
      v3 = CAIEvent::Data1(a2);
      v4 = CAIEvent::Data2(a2);
      v11 = CAIEvent::Data3(a2) != 0;
      (*(void (__thiscall **)(_DWORD *, int, int, bool))(*this[261] + 24))(this[261], v3, v4, v11);
      return 1;
    default:
      return 0;
  }
}


// address=[0x1322a00]
// Decompiled from void __thiscall CAIDarkTribeSectorAI::AttachAgentEx(  CAIDarkTribeSectorAI *this,  struct CAIDarkTribeSectorAgent *a2,  unsigned int a3,  unsigned int a4,  unsigned int a5)
void  CAIDarkTribeSectorAI::AttachAgentEx(class CAIDarkTribeSectorAgent &,unsigned int,unsigned int,unsigned int) {
  
  CAIDarkTribeSectorAgent::AttachSectorAI(a2, this);
  CAIScheduler::AddAgent((CAIScheduler *)(*((_DWORD *)this + 1) + 28), a2, a3, a4, a5);
}


