#include "CAIAgentGeologists.h"

// Definitions for class CAIAgentGeologists

// address=[0x1304250]
// Decompiled from unsigned int __thiscall CAIAgentGeologists::Execute(CAIAgentGeologists *this, unsigned int a2, unsigned int a3)

unsigned int  CAIAgentGeologists::Execute(unsigned int,unsigned int) {
  
  struct CAINormalSectorAI *v3; // eax
  struct CAINormalSectorAI *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  CAISectorAI *v14; // eax
  struct CAISectorAI *v15; // eax
  int v16; // eax
  int v18; // [esp-8h] [ebp-6Ch]
  _DWORD v19[4]; // [esp+0h] [ebp-64h] BYREF
  int v20; // [esp+10h] [ebp-54h]
  int v21; // [esp+14h] [ebp-50h]
  int v22; // [esp+18h] [ebp-4Ch]
  int v23; // [esp+1Ch] [ebp-48h]
  int v24; // [esp+20h] [ebp-44h]
  unsigned int v25; // [esp+24h] [ebp-40h]
  BOOL v26; // [esp+28h] [ebp-3Ch]
  BOOL v27; // [esp+2Ch] [ebp-38h]
  int v28; // [esp+30h] [ebp-34h]
  int v29; // [esp+34h] [ebp-30h]
  struct _Cnd_internal_imp_t *v30; // [esp+38h] [ebp-2Ch]
  pairNode *v31; // [esp+3Ch] [ebp-28h]
  int v32; // [esp+40h] [ebp-24h]
  int v33; // [esp+44h] [ebp-20h]
  int v34; // [esp+48h] [ebp-1Ch]
  struct _Mtx_internal_imp_t *v35; // [esp+4Ch] [ebp-18h] BYREF
  int i; // [esp+50h] [ebp-14h]
  CAINormalSectorAgent *v37; // [esp+54h] [ebp-10h]
  CAIEntityInfo *j; // [esp+58h] [ebp-Ch]
  struct _Cnd_internal_imp_t *v39; // [esp+5Ch] [ebp-8h] BYREF
  char v40; // [esp+63h] [ebp-1h]

  v37 = this;
  v31 = (struct CAINormalSectorAI *)((char *)CAINormalSectorAgent::SectorAI(this) + 2324);
  v3 = CAINormalSectorAgent::SectorAI(v37);
  v33 = CAISectorAI::Reservoir(v3, 7);
  if ( !v33 && BBSupportDbgReport(2, "AI\\AI_AgentsNormal.cpp", 291, "pReservoir != 0") == 1 )
    __debugbreak();
  for ( i = CAITaskForce::FirstEntity(v33); i; i = v20 )
  {
    v20 = CAIEntityInfo::Next(i);
    v32 = CAIEntityInfo::EntityId(i);
    v21 = IAIEnvironment::EntityType(v32);
    if ( v21 == 49 )
    {
      CAITaskForce::RemoveEntity(v33, v32);
      CAITaskForce::AddEntity(v31, v32, 0);
    }
  }
  if ( CAITaskForce::NumberOfEntities(v31) <= 0 )
    return CAIAgent::ExecuteResult(0, 0x80u);
  v25 = IAIEnvironment::TickCounter();
  v4 = CAINormalSectorAgent::SectorAI(v37);
  v5 = CAISectorAI::PlayerAI(v4);
  v22 = IAIEnvironment::AlliancesPlayerEnemyBits(*(_DWORD *)(v5 + 12));
  v28 = 0;
  for ( j = (CAIEntityInfo *)CAITaskForce::FirstEntity(v31); ; j = (CAIEntityInfo *)CAIEntityInfo::Next(j) )
  {
    v27 = j != 0;
    v26 = v28 < 10;
    if ( !v26 || !v27 )
      break;
    v34 = CAIEntityInfo::EntityId(j);
    v6 = CAIEntityInfo::TimeStamp(j);
    if ( v6 + 500 <= v25 || IAIEnvironment::MovingEntityIsWaiting(v34) )
    {
      CAIEntityInfo::SetTimeStamp(j, v25);
      v7 = IAIEnvironment::EntityPackedPosition(v34);
      CQuickScan::CQuickScan(v19, v7, 0xCu, 0x32u);
      v40 = 0;
      v23 = CQuickScan::CenterSectorId((CQuickScan *)v19);
LABEL_15:
      while ( !v40 && CQuickScan::NextPosition((CQuickScan *)v19, (int *)&v39, (int *)&v35) )
      {
        v24 = IAIEnvironment::WorldIndex((int)v39, (int)v35);
        if ( (unsigned __int8)IAIEnvironment::WorldIsScree(v39, v35) )
        {
          v8 = IAIEnvironment::WorldSectorId(v24);
          if ( v8 == v23 )
          {
            v9 = IAIEnvironment::WorldOwnerId(v24);
            v10 = IAIEnvironment::AlliancesPlayerBit(v9);
            if ( (v22 & v10) == 0 )
            {
              v40 = 1;
              break;
            }
          }
          v39 = (struct _Cnd_internal_imp_t *)((char *)v39 + 1);
          v30 = (struct _Cnd_internal_imp_t *)((char *)v39 + 12);
          if ( (int)v30 >= IAIEnvironment::WorldWidth() )
            v30 = (struct _Cnd_internal_imp_t *)(IAIEnvironment::WorldWidth() - 1);
          while ( (int)v39 <= (int)v30 )
          {
            v29 = IAIEnvironment::WorldIndex((int)v39, (int)v35);
            if ( IAIEnvironment::WorldIsScree(v29) )
            {
              v11 = IAIEnvironment::WorldSectorId(v29);
              if ( v11 == v23 )
              {
                v12 = IAIEnvironment::WorldOwnerId(v29);
                v13 = IAIEnvironment::AlliancesPlayerBit(v12);
                if ( (v22 & v13) == 0 )
                {
                  v40 = 1;
                  goto LABEL_15;
                }
              }
            }
            v39 = (struct _Cnd_internal_imp_t *)((char *)v39 + 1);
          }
        }
      }
      if ( v40 )
      {
        IAIEnvironment::MovingEntitySendMoveCommand(v34, (int)v39, (int)v35, 1);
      }
      else
      {
        v14 = CAINormalSectorAgent::SectorAI(v37);
        v18 = CAISectorAI::BaseY(v14);
        v15 = CAINormalSectorAgent::SectorAI(v37);
        v16 = CAISectorAI::BaseX(v15);
        IAIEnvironment::MovingEntitySendMoveCommand(v34, v16, v18, 0);
      }
      ++v28;
    }
  }
  return CAIAgent::ExecuteResult(0, 0);
}


// address=[0x1325aa0]
// Decompiled from CAIAgentGeologists *__thiscall CAIAgentGeologists::CAIAgentGeologists(CAIAgentGeologists *this)

 CAIAgentGeologists::CAIAgentGeologists(void) {
  
  CAINormalSectorAgent::CAINormalSectorAgent(this, "geologists");
  *(_DWORD *)this = &CAIAgentGeologists::_vftable_;
  return this;
}


// address=[0x1325c70]
// Decompiled from void __thiscall CAIAgentGeologists::~CAIAgentGeologists(CAIAgentGeologists *this)

 CAIAgentGeologists::~CAIAgentGeologists(void) {
  
  CAINormalSectorAgent::~CAINormalSectorAgent(this);
}


