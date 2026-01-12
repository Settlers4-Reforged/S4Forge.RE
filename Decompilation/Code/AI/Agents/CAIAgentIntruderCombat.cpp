#include "CAIAgentIntruderCombat.h"

// Definitions for class CAIAgentIntruderCombat

// address=[0x1304730]
// Decompiled from CAIAgentIntruderCombat *__thiscall CAIAgentIntruderCombat::CAIAgentIntruderCombat(CAIAgentIntruderCombat *this)

 CAIAgentIntruderCombat::CAIAgentIntruderCombat(void) {
  
  CAINormalSectorAgent::CAINormalSectorAgent(this, "intruder combat");
  *(_DWORD *)this = &CAIAgentIntruderCombat::_vftable_;
  *((_DWORD *)this + 10) = 0;
  return this;
}


// address=[0x1304760]
// Decompiled from unsigned int __thiscall CAIAgentIntruderCombat::Execute(CAIAgentIntruderCombat *this, unsigned int a2, unsigned int a3)

unsigned int  CAIAgentIntruderCombat::Execute(unsigned int,unsigned int) {
  
  struct CAINormalSectorAI *v3; // eax
  pairNode *v4; // eax
  int v5; // eax
  int IntruderType; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  struct CAINormalSectorAI *v10; // eax
  int v12; // [esp-Ch] [ebp-4Ch]
  int v13; // [esp-8h] [ebp-48h]
  unsigned int v14; // [esp-4h] [ebp-44h]
  CAIEntityInfo *v15; // [esp+0h] [ebp-40h]
  CPropertySet *v16; // [esp+Ch] [ebp-34h]
  int v17; // [esp+10h] [ebp-30h]
  int v18; // [esp+14h] [ebp-2Ch]
  int v19; // [esp+18h] [ebp-28h]
  int v20; // [esp+1Ch] [ebp-24h] BYREF
  int v21; // [esp+20h] [ebp-20h] BYREF
  int v22; // [esp+24h] [ebp-1Ch]
  CAITaskForce *v23; // [esp+28h] [ebp-18h]
  int v24; // [esp+2Ch] [ebp-14h]
  CAIEntityInfo *j; // [esp+30h] [ebp-10h]
  CAINormalSectorAgent *v26; // [esp+34h] [ebp-Ch]
  CPropertySet *i; // [esp+38h] [ebp-8h]
  int v28; // [esp+3Ch] [ebp-4h]

  v26 = this;
  v3 = CAINormalSectorAgent::SectorAI(this);
  v4 = (pairNode *)CAISectorAI::PlayerAI(v3);
  v18 = CAIPlayerAI::PlayerId(v4);
  v23 = (struct CAINormalSectorAI *)((char *)CAINormalSectorAgent::SectorAI(v26) + 2404);
  v28 = 0;
  for ( i = (CPropertySet *)CAITaskForce::LastEntity(v23); i; i = v16 )
  {
    v16 = (CPropertySet *)CAIEntityInfo::Prev(i);
    v24 = CAIEntityInfo::TargetId(i);
    if ( v24 )
    {
      v22 = -1;
      if ( IAIEnvironment::EntityIsAlive(v24) )
      {
        IAIEnvironment::EntityGetPosition(v24, &v20, &v21);
        v22 = CScanner::IsNearMyLand(v18, v20, v21);
      }
      if ( v22 < 0 )
      {
        CAIEntityInfo::SetTargetId(i, 0);
        v24 = 0;
      }
      else
      {
        v13 = v21;
        v12 = v20;
        v5 = CAIEntityInfo::EntityId(i);
        IAIEnvironment::MovingEntitySendMoveCommand(v5, v12, v13, 1);
      }
    }
    if ( !v24 )
    {
      v17 = CAIEntityInfo::EntityId(i);
      CAITaskForce::AddEntity(v23, v17, 2);
      ++v28;
    }
  }
  IntruderType = CAIAgentIntruderCombat::HuntNextIntruderType(v26);
  v28 -= IntruderType;
  v7 = CAIAgentIntruderCombat::HuntNextIntruderType(v26);
  v28 -= v7;
  v8 = CAIAgentIntruderCombat::HuntNextIntruderType(v26);
  v28 -= v8;
  if ( v28 > 0 )
  {
    for ( j = (CAIEntityInfo *)CAITaskForce::FirstEntity(v23); j; j = v15 )
    {
      v15 = (CAIEntityInfo *)CAIEntityInfo::Next(j);
      if ( !CAIEntityInfo::TargetId(j) )
      {
        v9 = CAIEntityInfo::EntityId(j);
        CAIAgentIntruderCombat::MoveHunterHome(v26, v9);
        v19 = CAIEntityInfo::EntityId(j);
        v14 = IAIEnvironment::EntityWarriorType(v19);
        v10 = CAINormalSectorAgent::SectorAI(v26);
        CAISectorAI::AddEntityToReservoir(v10, v19, v14);
      }
    }
  }
  return CAIAgent::ExecuteResult(0, 0);
}


// address=[0x13062a0]
// Decompiled from void __thiscall CAIAgentIntruderCombat::~CAIAgentIntruderCombat(CAIAgentIntruderCombat *this)

 CAIAgentIntruderCombat::~CAIAgentIntruderCombat(void) {
  
  CAINormalSectorAgent::~CAINormalSectorAgent(this);
}


// address=[0x1304940]
// Decompiled from int __thiscall CAIAgentIntruderCombat::MoveHunterHome(CAIAgentIntruderCombat *this, int a2)

void  CAIAgentIntruderCombat::MoveHunterHome(int) {
  
  struct CAINormalSectorAI *v2; // eax
  pairNode *v3; // eax
  struct CAISectorAI *v4; // eax
  CAISectorAI *v5; // eax
  int v7; // [esp+0h] [ebp-1Ch] BYREF
  int v8; // [esp+4h] [ebp-18h] BYREF
  int v9; // [esp+8h] [ebp-14h]
  int v10; // [esp+Ch] [ebp-10h] BYREF
  int v11; // [esp+10h] [ebp-Ch] BYREF
  int NearestOwnTowerInSector; // [esp+14h] [ebp-8h]
  CAINormalSectorAgent *v13; // [esp+18h] [ebp-4h]

  v13 = this;
  v2 = CAINormalSectorAgent::SectorAI(this);
  v3 = (pairNode *)CAISectorAI::PlayerAI(v2);
  v9 = CAIPlayerAI::PlayerId(v3);
  v4 = CAINormalSectorAgent::SectorAI(v13);
  v10 = CAISectorAI::BaseX(v4);
  v5 = CAINormalSectorAgent::SectorAI(v13);
  v11 = CAISectorAI::BaseY(v5);
  IAIEnvironment::EntityGetPosition(a2, &v7, &v8);
  NearestOwnTowerInSector = CScanner::FindNearestOwnTowerInSector(v7, v8, 32, v9);
  if ( NearestOwnTowerInSector > 0 )
    IAIEnvironment::BuildingGetEnsignPosition(NearestOwnTowerInSector, &v10, &v11);
  return IAIEnvironment::MovingEntitySendMoveCommand(a2, v10, v11, 0);
}


// address=[0x13049f0]
// Decompiled from int __thiscall CAIAgentIntruderCombat::HuntNextIntruderType(CAIAgentIntruderCombat *this)

int  CAIAgentIntruderCombat::HuntNextIntruderType(void) {
  
  unsigned int v1; // eax

  v1 = *((_DWORD *)this + 10) + 1;
  *((_DWORD *)this + 10) = v1;
  if ( v1 >= 6 )
    *((_DWORD *)this + 10) = 0;
  return CAIAgentIntruderCombat::HuntIntruders(this, dword_3D7A000[*((_DWORD *)this + 10)]);
}


// address=[0x1304a40]
// Decompiled from int __thiscall CAIAgentIntruderCombat::HuntIntruders(CAIAgentIntruderCombat *this, int a2)

int  CAIAgentIntruderCombat::HuntIntruders(int) {
  
  struct CAINormalSectorAI *v2; // eax
  pairNode *v3; // eax
  CAISectorAI *v4; // eax
  struct CAINormalSectorAI *v5; // eax
  int v6; // eax
  _DWORD v8[10]; // [esp+0h] [ebp-B4h] BYREF
  int v9; // [esp+28h] [ebp-8Ch] BYREF
  int v10; // [esp+2Ch] [ebp-88h] BYREF
  int v11; // [esp+30h] [ebp-84h] BYREF
  int v12; // [esp+34h] [ebp-80h]
  int v13; // [esp+38h] [ebp-7Ch]
  int v14; // [esp+3Ch] [ebp-78h] BYREF
  int v15; // [esp+40h] [ebp-74h] BYREF
  int v16; // [esp+44h] [ebp-70h]
  int v17; // [esp+48h] [ebp-6Ch]
  CPropertySet *EntityInfo; // [esp+4Ch] [ebp-68h]
  __int64 v19; // [esp+50h] [ebp-64h]
  int v20; // [esp+58h] [ebp-5Ch]
  BOOL v21; // [esp+5Ch] [ebp-58h]
  BOOL v22; // [esp+60h] [ebp-54h]
  int v23; // [esp+64h] [ebp-50h]
  int v24; // [esp+68h] [ebp-4Ch]
  int v25; // [esp+6Ch] [ebp-48h]
  int v26; // [esp+70h] [ebp-44h]
  int v27; // [esp+74h] [ebp-40h]
  unsigned __int16 v28[2]; // [esp+78h] [ebp-3Ch] BYREF
  pairNode *v29; // [esp+7Ch] [ebp-38h]
  int v30; // [esp+80h] [ebp-34h]
  int v31; // [esp+84h] [ebp-30h]
  int v32; // [esp+88h] [ebp-2Ch]
  int v33; // [esp+8Ch] [ebp-28h]
  int v34; // [esp+90h] [ebp-24h]
  int v35; // [esp+94h] [ebp-20h]
  int v36; // [esp+98h] [ebp-1Ch] BYREF
  int v37; // [esp+9Ch] [ebp-18h] BYREF
  int k; // [esp+A0h] [ebp-14h]
  CAINormalSectorAgent *v39; // [esp+A4h] [ebp-10h]
  pairNode *j; // [esp+A8h] [ebp-Ch]
  CAIEntityInfo *i; // [esp+ACh] [ebp-8h]
  int v42; // [esp+B0h] [ebp-4h]

  v39 = this;
  v8[9] = 10;
  v8[8] = 40;
  v8[7] = 5;
  v8[6] = 30;
  v8[5] = 40;
  v27 = 0;
  v2 = CAINormalSectorAgent::SectorAI(this);
  v3 = (pairNode *)CAISectorAI::PlayerAI(v2);
  v26 = CAIPlayerAI::PlayerId(v3);
  v4 = CAINormalSectorAgent::SectorAI(v39);
  v17 = CAISectorAI::SectorId(v4);
  v29 = (struct CAINormalSectorAI *)((char *)CAINormalSectorAgent::SectorAI(v39) + 2404);
  CAIEnemySettlerInSectorIterator::CAIEnemySettlerInSectorIterator((CAIEnemySettlerInSectorIterator *)v8, v26, a2, v17);
  while ( CAIEnemySettlerInSectorIterator::NextEnemySettler(v8, (int *)v28) )
  {
    IAIEnvironment::EntityGetPosition(*(_DWORD *)v28, &v36, &v37);
    v16 = CScanner::IsNearMyLand(v26, v36, v37);
    if ( v16 >= 0 )
    {
      v42 = 0;
      v34 = 0;
      v35 = 0x4000;
      for ( i = (CAIEntityInfo *)CAITaskForce::FirstEntity(v29); i; i = (CAIEntityInfo *)CAIEntityInfo::Next(i) )
      {
        v25 = CAIEntityInfo::TargetId(i);
        if ( v25 )
        {
          if ( v25 == *(_DWORD *)v28 )
          {
            v42 = CAIEntityInfo::EntityId(i);
            break;
          }
        }
        else
        {
          v23 = CAIEntityInfo::EntityId(i);
          IAIEnvironment::EntityGetPosition(v23, &v14, &v15);
          v24 = IAIEnvironment::GridDistance(v36 - v14, v37 - v15);
          if ( v24 < v35 )
          {
            v35 = v24;
            v34 = v23;
          }
        }
      }
      if ( !v42 )
      {
        v22 = v34 != 0;
        v21 = v35 < 40;
        if ( v21 && v22 )
        {
          v42 = v34;
          ++v27;
        }
        else if ( CAITaskForce::NumberOfEntities(v29) < 10 )
        {
          v30 = 0;
          v31 = 0x4000;
          v5 = CAINormalSectorAgent::SectorAI(v39);
          v6 = CAISectorAI::TaskForceGroup(v5);
          for ( j = (pairNode *)CAITaskForceGroup::FirstTaskForce(v6, 2);
                j;
                j = CAITaskForce::NextTaskForceGroupMemberOfSameClass(j) )
          {
            v13 = CAITaskForce::Type(j);
            if ( v13 == 5 )
            {
              v12 = CAITaskForce::NumberOfEntities(j);
              if ( v12 > 5 )
              {
                v33 = 0;
                for ( k = CAITaskForce::FirstEntity(j); k; k = CAIEntityInfo::Next(k) )
                {
                  v20 = CAIEntityInfo::EntityId(k);
                  IAIEnvironment::EntityGetWarriorTypeAndPosition(v20, (enum T_AI_WARRIOR_TYPE *)&v11, &v9, &v10);
                  if ( v11 == 2 )
                  {
                    v32 = IAIEnvironment::GridDistance(v9 - v36, v10 - v37);
                    if ( v32 < v31 )
                    {
                      v31 = v32;
                      v30 = v20;
                    }
                    HIDWORD(v19) = ++v33 >= 5;
                    LODWORD(v19) = v32 < 30;
                    if ( v19 )
                      break;
                  }
                }
              }
            }
            if ( v31 < 40 )
              break;
          }
          if ( v30 > 0 )
          {
            v42 = v30;
            CAITaskForce::AddEntity(v29, v30, 1);
          }
        }
      }
      if ( v42 )
      {
        EntityInfo = (CPropertySet *)IAIEnvironment::EntityGetEntityInfo(v42, 0);
        if ( EntityInfo )
        {
          CAIEntityInfo::SetTargetId(EntityInfo, v28[0]);
          IAIEnvironment::MovingEntitySendMoveCommand(v42, v36, v37, 1);
        }
      }
    }
  }
  return v27;
}


