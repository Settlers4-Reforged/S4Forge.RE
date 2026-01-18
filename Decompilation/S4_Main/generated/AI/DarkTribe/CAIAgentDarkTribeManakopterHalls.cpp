#include "CAIAgentDarkTribeManakopterHalls.h"

// Definitions for class CAIAgentDarkTribeManakopterHalls

// address=[0x1302dc0]
// Decompiled from unsigned int __thiscall CAIAgentDarkTribeManakopterHalls::Execute(  CAIAgentDarkTribeManakopterHalls *this,  unsigned int a2,  unsigned int a3)
unsigned int  CAIAgentDarkTribeManakopterHalls::Execute(unsigned int,unsigned int) {
  
  struct CAIDarkTribeSectorAI *v3; // eax
  pairNode *v4; // eax
  void **v5; // eax
  int Value; // eax
  int v8; // [esp+0h] [ebp-24h]
  int v9; // [esp+4h] [ebp-20h]
  int NumberOfEntities; // [esp+Ch] [ebp-18h]
  CManakopterHallRole *v11; // [esp+14h] [ebp-10h]
  int v13; // [esp+1Ch] [ebp-8h]
  struct CBuilding *Building; // [esp+20h] [ebp-4h]

  if ( !a2 )
    return CAIAgent::ExecuteResult(0, 0);
  v3 = CAIDarkTribeSectorAgent::SectorAI(this);
  v4 = (pairNode *)CAISectorAI::PlayerAI(v3);
  v13 = CAIPlayerAI::PlayerId(v4);
  Building = (struct CBuilding *)CBuildingMgr::GetBuilding((CBuildingMgr *)g_cBuildingMgr, v13, 80);
  if ( !Building )
    return CAIAgent::ExecuteResult(0, 0);
  if ( !IEntity::FlagBits(Building, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
    return CAIAgent::ExecuteResult(0, 0);
  NumberOfEntities = CFlyingMgr::GetNumberOfEntities((CFlyingMgr *)g_cFlyingMgr, v13, 1);
  if ( CAIPlayersScriptVars::GetValue(g_cAIPlayersScriptVars, v13, 21) != 1
    && BBSupportDbgReport(2, "AI\\AI_AgentsDark.cpp", 907, "iManakopterLimit == 1") == 1 )
  {
    __debugbreak();
  }
  if ( NumberOfEntities )
    return CAIAgent::ExecuteResult(0, 0);
  v9 = *((_DWORD *)this + 10);
  v8 = CStateGame::GetTickCounter(g_pGame) / 0xEu - v9;
  if ( v8 <= CAIPlayersScriptVars::GetValue(g_cAIPlayersScriptVars, v13, 20) )
    return CAIAgent::ExecuteResult(0, 0);
  v5 = (void **)CBuilding::Role(Building);
  if ( !j____RTDynamicCast(v5, 0, &IBuildingRole__RTTI_Type_Descriptor_, &CManakopterHallRole__RTTI_Type_Descriptor_, 0)
    && BBSupportDbgReport(
         2,
         "AI\\AI_AgentsDark.cpp",
         928,
         "dynamic_cast<CManakopterHallRole*>(&(pManakopterHall->Role())) != 0") == 1 )
  {
    __debugbreak();
  }
  v11 = (CManakopterHallRole *)CBuilding::Role(Building);
  if ( CManakopterHallRole::TryMakingManakopter(v11, Building) )
  {
    *((_DWORD *)this + 10) = CStateGame::GetTickCounter(g_pGame) / 0xEu;
    Value = CAIPlayersScriptVars::GetValue(g_cAIPlayersScriptVars, v13, 20);
    return CAIAgent::ExecuteResult(14 * Value, 0);
  }
  CManakopterHallRole::CheatIfRequired(v11, Building);
  return CAIAgent::ExecuteResult(0, 0);
}


// address=[0x1302f80]
// Decompiled from int __thiscall CAIAgentDarkTribeManakopterHalls::Load(CAIAgentDarkTribeManakopterHalls *this, struct IS4Chunk *a2)
void  CAIAgentDarkTribeManakopterHalls::Load(class IS4Chunk & a2) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516302333);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1, 1);
  CAIAgent::Load(this, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516302331);
  *((_DWORD *)this + 10) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516302332);
}


// address=[0x1303000]
// Decompiled from int __thiscall CAIAgentDarkTribeManakopterHalls::Save(CAIAgentDarkTribeManakopterHalls *this, struct IS4Chunk *a2)
void  CAIAgentDarkTribeManakopterHalls::Save(class IS4Chunk & a2) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516302333);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 1);
  CAIAgent::Save(this, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516302331);
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 10));
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516302332);
}


// address=[0x1322da0]
// Decompiled from CAIAgentDarkTribeManakopterHalls *__thiscall CAIAgentDarkTribeManakopterHalls::CAIAgentDarkTribeManakopterHalls(  CAIAgentDarkTribeManakopterHalls *this)
 CAIAgentDarkTribeManakopterHalls::CAIAgentDarkTribeManakopterHalls(void) {
  
  CAIDarkTribeSectorAgent::CAIDarkTribeSectorAgent(this, "manakopterhalls");
  *(_DWORD *)this = &CAIAgentDarkTribeManakopterHalls::_vftable_;
  *((_DWORD *)this + 10) = 0;
  return this;
}


// address=[0x1322f00]
// Decompiled from void __thiscall CAIAgentDarkTribeManakopterHalls::~CAIAgentDarkTribeManakopterHalls(  CAIAgentDarkTribeManakopterHalls *this)
 CAIAgentDarkTribeManakopterHalls::~CAIAgentDarkTribeManakopterHalls(void) {
  
  CAIDarkTribeSectorAgent::~CAIDarkTribeSectorAgent(this);
}


