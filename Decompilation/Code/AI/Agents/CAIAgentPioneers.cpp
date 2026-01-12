#include "CAIAgentPioneers.h"

// Definitions for class CAIAgentPioneers

// address=[0x1304df0]
// Decompiled from CAIAgentPioneers *__thiscall CAIAgentPioneers::CAIAgentPioneers(CAIAgentPioneers *this)
 CAIAgentPioneers::CAIAgentPioneers(void) {
  
  CAINormalSectorAgent::CAINormalSectorAgent(this, "unknown normal sector");
  *(_DWORD *)this = &CAIAgentPioneers::_vftable_;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  return this;
}


// address=[0x1304e40]
// Decompiled from unsigned int __thiscall CAIAgentPioneers::Execute(CAIAgentPioneers *this, unsigned int a2, unsigned int a3)
unsigned int  CAIAgentPioneers::Execute(unsigned int,unsigned int) {
  
  struct CAINormalSectorAI *v3; // eax
  pairNode *v4; // eax
  unsigned int v5; // eax
  struct CAINormalSectorAI *v7; // eax
  CAISectorAI *v8; // eax
  int v9; // eax
  struct CAINormalSectorAI *v10; // eax
  pairNode *v11; // eax
  int v12; // eax
  struct CAISectorAI *v13; // eax
  int v14; // eax
  CAISectorAI *v15; // eax
  int v16; // eax
  int v17; // eax
  _BYTE v18[20]; // [esp+0h] [ebp-58h] BYREF
  int v19; // [esp+14h] [ebp-44h]
  int v20; // [esp+18h] [ebp-40h]
  int v21; // [esp+1Ch] [ebp-3Ch]
  int Value; // [esp+20h] [ebp-38h]
  int v23; // [esp+24h] [ebp-34h]
  int v24; // [esp+28h] [ebp-30h]
  int v25; // [esp+2Ch] [ebp-2Ch] BYREF
  int v26; // [esp+30h] [ebp-28h] BYREF
  int Entity; // [esp+34h] [ebp-24h]
  int v28; // [esp+38h] [ebp-20h]
  int v29; // [esp+3Ch] [ebp-1Ch]
  unsigned int v30; // [esp+40h] [ebp-18h]
  pairNode *v31; // [esp+44h] [ebp-14h]
  int i; // [esp+48h] [ebp-10h]
  CAIEntityInfo *j; // [esp+4Ch] [ebp-Ch]
  CAIAgent *v34; // [esp+50h] [ebp-8h]
  char v35; // [esp+57h] [ebp-1h]

  v34 = this;
  v3 = CAINormalSectorAgent::SectorAI(this);
  v4 = (pairNode *)CAISectorAI::PlayerAI(v3);
  v23 = CAIPlayerAI::PlayerId(v4);
  Value = CAIPlayersScriptVars::GetValue(g_cAIPlayersScriptVars, v23, 18);
  if ( Value > 0 )
  {
    v31 = (struct CAINormalSectorAI *)((char *)CAINormalSectorAgent::SectorAI(v34) + 2644);
    v7 = CAINormalSectorAgent::SectorAI(v34);
    v29 = CAISectorAI::Reservoir(v7, 7);
    if ( !v29 && BBSupportDbgReport(2, "AI\\AI_AgentsNormal.cpp", 1015, "pReservoir != 0") == 1 )
      __debugbreak();
    for ( i = CAITaskForce::FirstEntity(v29); i; i = v20 )
    {
      v20 = CAIEntityInfo::Next(i);
      v28 = CAIEntityInfo::EntityId(i);
      v21 = IAIEnvironment::EntityType(v28);
      if ( v21 == 47 )
      {
        CAITaskForce::RemoveEntity(v29, v28);
        CAITaskForce::AddEntity(v31, v28, 2);
      }
    }
    if ( CAITaskForce::NumberOfEntities(v31) <= 0 )
    {
      *((_DWORD *)v34 + 10) = 0;
      *((_DWORD *)v34 + 11) = 0;
      *((_DWORD *)v34 + 12) = 0;
      return CAIAgent::ExecuteResult(0, 0x80u);
    }
    else
    {
      v30 = IAIEnvironment::TickCounter();
      v35 = 0;
      if ( *((int *)v34 + 10) > 0
        && *((int *)v34 + 11) > 0
        && *((_DWORD *)v34 + 12)
        && *((_DWORD *)v34 + 12) + 1400 > v30 )
      {
        v8 = CAINormalSectorAgent::SectorAI(v34);
        v9 = CAISectorAI::SectorId(v8);
        CSectorSpiralWalk::CSectorSpiralWalk(
          (CSectorSpiralWalk *)v18,
          *((_DWORD *)v34 + 10),
          *((_DWORD *)v34 + 11),
          8,
          v9);
        if ( CSectorSpiralWalk::NextXY((CSectorSpiralWalk *)v18, (int *)v34 + 10, (int *)v34 + 11) )
        {
          v10 = CAINormalSectorAgent::SectorAI(v34);
          v11 = (pairNode *)CAISectorAI::PlayerAI(v10);
          v12 = CAIPlayerAI::PlayerId(v11);
          v19 = IAIEnvironment::AlliancesAllianceId(v12);
          if ( (int)CInfluMap::EnemyValueXY(*((_DWORD *)v34 + 10), *((_DWORD *)v34 + 11), v19) >= 16 )
            v35 = 1;
        }
        else
        {
          v35 = 1;
        }
      }
      else
      {
        v35 = 1;
      }
      if ( v35 )
      {
        *((_DWORD *)v34 + 12) = 0;
        v13 = CAINormalSectorAgent::SectorAI(v34);
        v14 = CAISectorAI::BaseX(v13);
        *((_DWORD *)v34 + 10) = v14;
        v15 = CAINormalSectorAgent::SectorAI(v34);
        v16 = CAISectorAI::BaseY(v15);
        *((_DWORD *)v34 + 11) = v16;
        if ( CAIAgentPioneers::FindWorkPosition(v34, (int *)v34 + 10, (int *)v34 + 11) )
        {
          *((_DWORD *)v34 + 12) = v30;
        }
        else
        {
          Entity = CAITaskForce::FirstEntity(v31);
          if ( Entity )
          {
            v17 = CAIEntityInfo::EntityId(Entity);
            IAIEnvironment::EntityGetPosition(v17, &v26, &v25);
            if ( CAIAgentPioneers::FindWorkPosition(v34, &v26, &v25) )
            {
              *((_DWORD *)v34 + 10) = v26;
              *((_DWORD *)v34 + 11) = v25;
              *((_DWORD *)v34 + 12) = v30;
            }
          }
        }
      }
      for ( j = (CAIEntityInfo *)CAITaskForce::FirstEntity(v31); j; j = (CAIEntityInfo *)CAIEntityInfo::Next(j) )
      {
        v24 = CAIEntityInfo::EntityId(j);
        if ( v35 || IAIEnvironment::MovingEntityIsWaiting(v24) )
        {
          CAIEntityInfo::SetTimeStamp(j, v30);
          IAIEnvironment::MovingEntitySendMoveCommand(v24, *((_DWORD *)v34 + 10), *((_DWORD *)v34 + 11), 1);
        }
      }
      return CAIAgent::ExecuteResult(0, 0);
    }
  }
  else
  {
    v5 = CAIAgent::DefaultExecutionDelay(v34);
    return CAIAgent::ExecuteResult(4 * v5, 1u);
  }
}


// address=[0x13062c0]
// Decompiled from void __thiscall CAIAgentPioneers::~CAIAgentPioneers(CAIAgentPioneers *this)
 CAIAgentPioneers::~CAIAgentPioneers(void) {
  
  CAINormalSectorAgent::~CAINormalSectorAgent(this);
}


// address=[0x13051a0]
// Decompiled from char __thiscall CAIAgentPioneers::FindWorkPosition(CAIAgentPioneers *this, int *a2, int *a3)
bool  CAIAgentPioneers::FindWorkPosition(int &,int &) {
  
  Squares *v4; // eax
  struct CAINormalSectorAI *v5; // eax
  pairNode *v6; // eax
  int v7; // esi
  int v8; // [esp+10h] [ebp-70h]
  int v9; // [esp+14h] [ebp-6Ch]
  int v10; // [esp+18h] [ebp-68h]
  int v11; // [esp+1Ch] [ebp-64h]
  int v12; // [esp+20h] [ebp-60h]
  __int64 v13; // [esp+24h] [ebp-5Ch]
  int v14; // [esp+2Ch] [ebp-54h]
  int v15; // [esp+30h] [ebp-50h]
  Grid *v16; // [esp+34h] [ebp-4Ch]
  int v17; // [esp+38h] [ebp-48h]
  int j; // [esp+3Ch] [ebp-44h]
  int i; // [esp+40h] [ebp-40h]
  _BYTE v21[52]; // [esp+48h] [ebp-38h] BYREF

  v14 = IAIEnvironment::WorldSectorId(*a2, *a3);
  if ( !v14 )
    return 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0x7FFFFFFF;
  v12 = Squares::XYToVW((Squares *)*a2);
  v11 = Squares::XYToVW((Squares *)*a3);
  v4 = (Squares *)IAIEnvironment::WorldWidth();
  v10 = Squares::XYToVW(v4);
  v5 = CAINormalSectorAgent::SectorAI(this);
  v6 = (pairNode *)CAISectorAI::PlayerAI(v5);
  v15 = CAIPlayerAI::PlayerId(v6);
  v8 = IAIEnvironment::AlliancesPlayerAllyBits(v15);
  v9 = IAIEnvironment::AlliancesPlayerEnemyBits(v15);
  *((_DWORD *)this + 14) = IAIEnvironment::AlliancesAllianceId(v15);
  *((_DWORD *)this + 13) = v14;
  v7 = IAIEnvironment::WorldWidth();
  if ( v7 != IAIEnvironment::WorldHeight()
    && BBSupportDbgReport(2, "AI\\AI_AgentsNormal.cpp", 929, "g_pAIEnv->WorldWidth() == g_pAIEnv->WorldHeight()") == 1 )
  {
    __debugbreak();
  }
  memset(v21, 0, 0x31u);
  for ( i = 0; i < 49; ++i )
  {
    v16 = (Grid *)(dword_3D7A030[2 * i] + v12);
    v17 = dword_3D7A034[2 * i] + v11;
    if ( Grid::InQuadrat(v16, v17, v10) )
    {
      if ( (v9 & COwnerMap::OwnerBits1VW(v16, v17)) == 0 )
      {
        v21[i] = 1;
        if ( (v8 & COwnerMap::OwnerBits9VW(v16, v17)) != 0 )
          CAIAgentPioneers::CheckSquare(this, v16, v17);
      }
    }
    else
    {
      v21[i] = 1;
    }
  }
  HIDWORD(v13) = *((_DWORD *)this + 15) <= 0;
  LODWORD(v13) = *((_DWORD *)this + 17) > 20;
  if ( v13 )
  {
    for ( j = 0; j < 49; ++j )
    {
      if ( !v21[j] )
        CAIAgentPioneers::CheckSquare(this, dword_3D7A030[2 * j] + v12, dword_3D7A034[2 * j] + v11);
    }
  }
  if ( *((int *)this + 15) <= 0 )
    return 0;
  *a2 = *((_DWORD *)this + 15);
  *a3 = *((_DWORD *)this + 16);
  return 1;
}


// address=[0x1305440]
// Decompiled from char __thiscall CAIAgentPioneers::CheckSquare(CAIAgentPioneers *this, int a2, int a3)
bool  CAIAgentPioneers::CheckSquare(int,int) {
  
  int v4; // [esp+8h] [ebp-10h]
  int i; // [esp+Ch] [ebp-Ch]
  struct CTile *v6; // [esp+10h] [ebp-8h]

  for ( i = ITiling::FirstTileOfSquareVW(a2, a3); ; i = CTile::NextSquareTile(v6) )
  {
    if ( !i )
      return 0;
    v6 = (struct CTile *)ITiling::Tile(i);
    if ( CTile::SectorId(v6) == *((_DWORD *)this + 13) && !CTile::OwnerId(v6) )
      break;
  }
  v4 = CInfluMap::EnemyValueVW(a2, a3, *((_DWORD *)this + 14));
  if ( v4 >= *((_DWORD *)this + 17) )
    return 1;
  *((_DWORD *)this + 17) = v4;
  *((_DWORD *)this + 15) = CTile::CenterX(v6);
  *((_DWORD *)this + 16) = CTile::CenterY(v6);
  return 1;
}


