#include "CAIAgentDarkTribeMushroomFarms.h"

// Definitions for class CAIAgentDarkTribeMushroomFarms

// address=[0x1301d60]
// Decompiled from unsigned int __thiscall CAIAgentDarkTribeMushroomFarms::Execute(  CAIAgentDarkTribeMushroomFarms *this,  unsigned int a2,  unsigned int a3)
unsigned int  CAIAgentDarkTribeMushroomFarms::Execute(unsigned int,unsigned int) {
  
  CAISectorAI *v3; // eax
  struct CAIDarkTribeSectorAI *v4; // eax
  pairNode *v5; // eax
  CAIDarkTribeSectorAI *v6; // eax
  CAIDarkTribeSectorAI *v7; // eax
  struct IAIDarkTribeEcoAI *v8; // eax
  int v9; // eax
  int v10; // esi
  unsigned int v12; // [esp+4h] [ebp-2Ch]
  int Value; // [esp+8h] [ebp-28h]
  int v14; // [esp+Ch] [ebp-24h]
  struct IAIDarkTribeEcoAI *v15; // [esp+14h] [ebp-1Ch]
  int NumberOfBuildings; // [esp+1Ch] [ebp-14h]
  int v17; // [esp+20h] [ebp-10h]
  int v18; // [esp+24h] [ebp-Ch]
  int v19; // [esp+28h] [ebp-8h]

  if ( !a2 )
    return CAIAgent::ExecuteResult(0, 0);
  v3 = CAIDarkTribeSectorAgent::SectorAI(this);
  v14 = CAISectorAI::HeadquarterId(v3);
  if ( !IAIEnvironment::EntityIsAlive(v14) )
    return CAIAgent::ExecuteResult(0, 0);
  v4 = CAIDarkTribeSectorAgent::SectorAI(this);
  v5 = (pairNode *)CAISectorAI::PlayerAI(v4);
  v19 = CAIPlayerAI::PlayerId(v5);
  NumberOfBuildings = IAIEnvironment::BuildingGetNumberOfBuildings(v19, 49, 2u);
  if ( NumberOfBuildings <= 0 )
    return CAIAgent::ExecuteResult(0x3E8u, 0);
  Value = CAIPlayersScriptVars::GetValue(g_cAIPlayersScriptVars, v19, 12);
  v18 = CAIPlayersScriptVars::GetValue(g_cAIPlayersScriptVars, v19, 13);
  if ( v18 <= 0 )
    v17 = 0;
  else
    v17 = Value + v18 * a2 / 0xC4E0;
  if ( v17 && NumberOfBuildings >= v17 )
    return CAIAgent::ExecuteResult(0, 0);
  v6 = CAIDarkTribeSectorAgent::SectorAI(this);
  v15 = CAIDarkTribeSectorAI::EconomyAI(v6);
  if ( !(*(unsigned __int8 (__thiscall **)(struct IAIDarkTribeEcoAI *, int))(*(_DWORD *)v15 + 16))(v15, 49) )
    return CAIAgent::ExecuteResult(0, 0);
  v7 = CAIDarkTribeSectorAgent::SectorAI(this);
  v8 = CAIDarkTribeSectorAI::EconomyAI(v7);
  if ( !(*(unsigned __int8 (__thiscall **)(struct IAIDarkTribeEcoAI *, int))(*(_DWORD *)v8 + 20))(v8, 49) )
    return CAIAgent::ExecuteResult(0, 0);
  v9 = CStaticConfigVarInt::operator int(&g_cAIDarkTribeMushroomFarmCreationDelay);
  v10 = 14 * sub_1303080(v9, 1, 3600);
  v12 = IAIEnvironment::Rand() % 0x80u + v10;
  return CAIAgent::ExecuteResult(v12, 0);
}


// address=[0x1322e10]
// Decompiled from CAIAgentDarkTribeMushroomFarms *__thiscall CAIAgentDarkTribeMushroomFarms::CAIAgentDarkTribeMushroomFarms(  CAIAgentDarkTribeMushroomFarms *this)
 CAIAgentDarkTribeMushroomFarms::CAIAgentDarkTribeMushroomFarms(void) {
  
  CAIDarkTribeSectorAgent::CAIDarkTribeSectorAgent(this, "mushroom farms");
  *(_DWORD *)this = &CAIAgentDarkTribeMushroomFarms::_vftable_;
  return this;
}


// address=[0x1322f40]
// Decompiled from void __thiscall CAIAgentDarkTribeMushroomFarms::~CAIAgentDarkTribeMushroomFarms(CAIAgentDarkTribeMushroomFarms *this)
 CAIAgentDarkTribeMushroomFarms::~CAIAgentDarkTribeMushroomFarms(void) {
  
  CAIDarkTribeSectorAgent::~CAIDarkTribeSectorAgent(this);
}


