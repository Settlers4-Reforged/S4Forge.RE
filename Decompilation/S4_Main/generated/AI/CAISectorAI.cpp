#include "CAISectorAI.h"

// Definitions for class CAISectorAI

// address=[0x12fce30]
// Decompiled from int __thiscall CAISectorAI::BasePackedXY(CAISectorAI *this)
int  CAISectorAI::BasePackedXY(void)const {
  
  return IAIEnvironment::PackXYFast(*((_DWORD *)this + 62), *((_DWORD *)this + 63));
}


// address=[0x12fce60]
// Decompiled from _DWORD __thiscall CAISectorAI::BaseX(struct CAISectorAI *this)
int  CAISectorAI::BaseX(void)const {
  
  return *((_DWORD *)this + 62);
}


// address=[0x12fce80]
// Decompiled from int __thiscall CAISectorAI::BaseY(CAISectorAI *this)
int  CAISectorAI::BaseY(void)const {
  
  return *((_DWORD *)this + 63);
}


// address=[0x12fd4f0]
// Decompiled from int __thiscall CAISectorAI::PlayerAI(CAISectorAI *this)
class CAIPlayerAI &  CAISectorAI::PlayerAI(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x12fd5e0]
// Decompiled from int __thiscall CAISectorAI::SectorId(CAISectorAI *this)
int  CAISectorAI::SectorId(void)const {
  
  return *((_DWORD *)this + 65);
}


// address=[0x12fd750]
// Decompiled from char *__thiscall CAISectorAI::TaskForceGroup(CAISectorAI *this)
class CAITaskForceGroup &  CAISectorAI::TaskForceGroup(void) {
  
  return (char *)this + 92;
}


// address=[0x1303950]
// Decompiled from int __thiscall CAISectorAI::HeadquarterId(CAISectorAI *this)
int  CAISectorAI::HeadquarterId(void)const {
  
  return *((_DWORD *)this + 61);
}


// address=[0x1303990]
// Decompiled from int __thiscall CAISectorAI::Reservoir(_DWORD *this, int a2)
class CAITaskForce *  CAISectorAI::Reservoir(enum T_AI_WARRIOR_TYPE a2)const {
  
  return this[a2 + 8];
}


// address=[0x13195d0]
// Decompiled from int __cdecl CAISectorAI::CreateNormalSectorAI(pairNode *a1, int a2, int a3)
class CAISectorAI * __cdecl CAISectorAI::CreateNormalSectorAI(class CAIPlayerAI & a1, int a2, int a3) {
  
  int v3; // eax

  v3 = IAIEnvironment::PackXYFast(a2, a3);
  return CAISectorAI::CreateNormalSectorAI(a1, v3);
}


// address=[0x1320000]
// Decompiled from void __thiscall CAISectorAI::~CAISectorAI(CAISectorAI *this)
 CAISectorAI::~CAISectorAI(void) {
  
  *(_DWORD *)this = &CAISectorAI::_vftable_;
  CAITaskForceGroup::~CAITaskForceGroup((CAISectorAI *)((char *)this + 92));
  CAIEventQueue::~CAIEventQueue((CAISectorAI *)((char *)this + 8));
}


// address=[0x1320030]
// Decompiled from int __thiscall CAISectorAI::Load(CAISectorAI *this, struct IS4Chunk *a2)
void  CAISectorAI::Load(class IS4Chunk & a2) {
  
  int v3; // [esp+0h] [ebp-14h]
  int v4; // [esp+4h] [ebp-10h]
  void (__thiscall ***v5)(_DWORD, struct IS4Chunk *); // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]

  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517158400);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517158398);
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 2))((char *)this + 8, a2);
  v4 = (*(int (__thiscall **)(struct IS4Chunk *, _DWORD, int))(*(_DWORD *)a2 + 4))(a2, 0, 15);
  for ( i = 0; i < v4; ++i )
  {
    v3 = (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 8))(a2, v3);
    if ( v3 >= 0 )
    {
      v5 = (void (__thiscall ***)(_DWORD, struct IS4Chunk *))*((_DWORD *)this + i + 8);
      if ( !v5 && BBSupportDbgReport(2, "AI\\AI_SectorAI.cpp", 117, "pTaskForce != 0") == 1 )
        __debugbreak();
      (**v5)(v5, a2);
    }
  }
  (**((void (__thiscall ***)(char *, struct IS4Chunk *))this + 23))((char *)this + 92, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 32, 32);
  (**(void (__thiscall ***)(struct IS4Chunk *, char *, int))a2)(a2, (char *)this + 232, 32);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517158399);
}


// address=[0x1320160]
// Decompiled from int __thiscall CAISectorAI::Save(CAISectorAI *this, struct IS4Chunk *a2)
void  CAISectorAI::Save(class IS4Chunk & a2) {
  
  int v2; // eax
  int v4; // [esp+0h] [ebp-10h]
  pairNode *v5; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]

  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517158400);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517158398);
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 2) + 4))((char *)this + 8, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 15);
  for ( i = 0; i < 15; ++i )
  {
    v5 = (pairNode *)*((_DWORD *)this + i + 8);
    if ( v5 )
    {
      v2 = CAITaskForce::NumberOfEntities(v5);
      v4 = IAIEnvironment::ClipMin(v2, 0);
      (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, v4);
      (*(void (__thiscall **)(pairNode *, struct IS4Chunk *))(*(_DWORD *)v5 + 4))(v5, a2);
    }
    else
    {
      (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, -1);
    }
  }
  (*(void (__thiscall **)(char *, struct IS4Chunk *))(*((_DWORD *)this + 23) + 4))((char *)this + 92, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 32);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 232, 32);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517158399);
}


// address=[0x1320290]
// Decompiled from CAISectorAI *__thiscall CAISectorAI::Release(CAISectorAI *this)
void  CAISectorAI::Release(void) {
  
  CAISectorAI *result; // eax

  result = this;
  if ( this )
    return (CAISectorAI *)(*(int (__thiscall **)(CAISectorAI *, int))(*(_DWORD *)this + 16))(this, 1);
  return result;
}


// address=[0x13202d0]
// Decompiled from struct SAIExpansionInfo *__thiscall CAISectorAI::ExpansionCheck(  CAISectorAI *this,  int a2,  int a3,  int a4,  struct SAIExpansionInfo *a5)
void  CAISectorAI::ExpansionCheck(int a2, int a3, int a4, struct SAIExpansionInfo & a5) {
  
  struct SAIExpansionInfo *result; // eax

  result = a5;
  *(_DWORD *)a5 = 0;
  *((_DWORD *)a5 + 1) = 32;
  return result;
}


// address=[0x13202f0]
// Decompiled from int __stdcall CAISectorAI::RequestDivinePresent(int a1, int a2)
enum T_AI_PRESENT_REQUEST_RESULT  CAISectorAI::RequestDivinePresent(int a1, enum T_AI_PRESENT_REQUEST_PRIORITY a2) {
  
  return 0;
}


// address=[0x1320300]
// Decompiled from int __cdecl CAISectorAI::CreateNormalSectorAI(pairNode *a1, int a2)
class CAISectorAI * __cdecl CAISectorAI::CreateNormalSectorAI(class CAIPlayerAI & a1, int a2) {
  
  if ( CAIPlayerAI::Race(a1) == 3
    && BBSupportDbgReport(2, "AI\\AI_SectorAI.cpp", 204, "_rPlayerAI.Race() != RACE_DARK") == 1 )
  {
    __debugbreak();
  }
  if ( operator new(0x159Cu) )
    return CAINormalSectorAI::CAINormalSectorAI(a1, a2);
  else
    return 0;
}


// address=[0x13203b0]
// Decompiled from int __cdecl CAISectorAI::CreateDarkTribeSectorAI(pairNode *a1, int a2)
class CAISectorAI * __cdecl CAISectorAI::CreateDarkTribeSectorAI(class CAIPlayerAI & a1, int a2) {
  
  if ( CAIPlayerAI::Race(a1) != 3
    && BBSupportDbgReport(2, "AI\\AI_SectorAI.cpp", 216, "_rPlayerAI.Race() == RACE_DARK") == 1 )
  {
    __debugbreak();
  }
  if ( operator new(0x418u) )
    return CAIDarkTribeSectorAI::CAIDarkTribeSectorAI(a1, a2);
  else
    return 0;
}


// address=[0x1320460]
// Decompiled from int __thiscall CAISectorAI::CheckBasePosition(CAISectorAI *this)
void  CAISectorAI::CheckBasePosition(void) {
  
  int v1; // eax
  int result; // eax
  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]

  v1 = CAISectorAI::BaseWorldIdx(this);
  result = IAIEnvironment::WorldSectorId(v1);
  *((_DWORD *)this + 65) = result;
  if ( *((_DWORD *)this + 65) )
    return result;
  v4 = IAIEnvironment::WorldIndex(*((_DWORD *)this + 59), *((_DWORD *)this + 60));
  if ( IAIEnvironment::WorldIsBlockedLand(v4) )
  {
    *((_DWORD *)this + 62) = *((_DWORD *)this + 59);
    *((_DWORD *)this + 63) = *((_DWORD *)this + 60);
    IAIEnvironment::GetNearestNoneBlockedPosition((int *)this + 62, (int *)this + 63);
    *((_DWORD *)this + 64) = IAIEnvironment::WorldIndex(*((_DWORD *)this + 62), *((_DWORD *)this + 63));
    result = IAIEnvironment::WorldSectorId(*((_DWORD *)this + 64));
    *((_DWORD *)this + 65) = result;
  }
  else
  {
    v3 = IAIEnvironment::WorldSectorId(v4);
    if ( !v3 && BBSupportDbgReport(2, "AI\\AI_SectorAI.cpp", 465, "iSectorId != 0") == 1 )
      __debugbreak();
    *((_DWORD *)this + 62) = *((_DWORD *)this + 59);
    *((_DWORD *)this + 63) = *((_DWORD *)this + 60);
    result = v4;
    *((_DWORD *)this + 64) = v4;
    *((_DWORD *)this + 65) = v3;
  }
  return result;
}


// address=[0x13205c0]
// Decompiled from char __thiscall CAISectorAI::EvaluateEnemyMilitaryBuilding(CAISectorAI *this, int a2, struct SAIEvalResults *a3)
bool  CAISectorAI::EvaluateEnemyMilitaryBuilding(int a2, struct SAIEvalResults & a3) {
  
  int v3; // eax
  const struct CAIResourceData *v5; // [esp+0h] [ebp-48h]
  int v6; // [esp+4h] [ebp-44h]
  int v8; // [esp+Ch] [ebp-3Ch]
  int v9; // [esp+10h] [ebp-38h]
  int v10; // [esp+14h] [ebp-34h]
  int v11; // [esp+18h] [ebp-30h]
  _BYTE v12[20]; // [esp+1Ch] [ebp-2Ch] BYREF
  int v13; // [esp+30h] [ebp-18h]
  _BYTE v14[12]; // [esp+34h] [ebp-14h] BYREF
  int v15; // [esp+40h] [ebp-8h]

  v11 = *(_DWORD *)(*((_DWORD *)this + 1) + 12);
  if ( a2 <= 0 && BBSupportDbgReport(2, "AI\\AI_SectorAI.cpp", 537, "_iBuildingId > 0") == 1 )
    __debugbreak();
  if ( IAIEnvironment::EntityOwnerId(a2) == v11
    && BBSupportDbgReport(2, "AI\\AI_SectorAI.cpp", 538, "g_pAIEnv->EntityOwnerId(_iBuildingId) != iPlayerId") == 1 )
  {
    __debugbreak();
  }
  v10 = IAIEnvironment::BuildingPackedEnsignPosition(a2);
  v3 = CAISectorAI::BasePackedXY(this);
  v6 = IAIEnvironment::CalculateRoughlyDistanceToEnemyPosition(v11, v3, v10);
  if ( v6 <= 0 )
  {
    *(_DWORD *)a3 = -1;
    *((_DWORD *)a3 + 1) = -1;
    *((_DWORD *)a3 + 2) = -1;
    return 0;
  }
  else
  {
    *(_DWORD *)a3 = -v6;
    v8 = IAIEnvironment::UnpackXFast(v10);
    v9 = IAIEnvironment::UnpackYFast(v10);
    CScanner::EvaluateFighters((struct SEvalFightersResult *)v12, v8, v9, 32, v11);
    CScanner::EvaluateTowers((struct SEvalTowersResult *)v14, v8, v9, 32, v11);
    *((_DWORD *)a3 + 1) = -v13 - v15;
    v5 = CAIResourceMap::ResourceDataXY(v8, v9);
    *((_DWORD *)a3 + 2) = CAIResourceEvalParams::Evalute9((CAIResourceEvalParams *)&unk_3D7A568, v5);
    return 1;
  }
}


// address=[0x1320740]
// Decompiled from int __thiscall CAISectorAI::EvaluateOwnMilitaryBuilding(pairNode **this, int a2, struct SAIDefenceEvalResult *a3)
void  CAISectorAI::EvaluateOwnMilitaryBuilding(int a2, struct SAIDefenceEvalResult & a3) {
  
  unsigned int v3; // eax
  int v4; // eax
  int v5; // edx
  int result; // eax
  _DWORD *v8; // [esp+4h] [ebp-38h]
  int v9; // [esp+8h] [ebp-34h]
  int v10; // [esp+Ch] [ebp-30h]
  int v11; // [esp+10h] [ebp-2Ch]
  int v12; // [esp+14h] [ebp-28h]
  CAIEntityInfo *EntityInfo; // [esp+1Ch] [ebp-20h]
  _BYTE v14[12]; // [esp+20h] [ebp-1Ch] BYREF
  int v15; // [esp+2Ch] [ebp-10h]
  int v16; // [esp+30h] [ebp-Ch]
  int v17; // [esp+34h] [ebp-8h]

  if ( a2 <= 0 && BBSupportDbgReport(2, "AI\\AI_SectorAI.cpp", 493, "_iBuildingId > 0") == 1 )
    __debugbreak();
  v8 = (_DWORD *)CBuildingMgr::operator[](a2);
  v12 = CBuilding::EnsignPackedXY(v8);
  v9 = Y16X16::UnpackXFast(v12);
  v10 = Y16X16::UnpackYFast(v12);
  v11 = CAIPlayerAI::PlayerId(this[1]);
  IAIEnvironment::EvaluateOwnerMap(v11, v9, v10, a3);
  CScanner::EvaluateFighters((struct SEvalFightersResult *)v14, v9, v10, 32, v11);
  *((_DWORD *)a3 + 8) = v15;
  *((_DWORD *)a3 + 9) = v17;
  EntityInfo = (CAIEntityInfo *)IAIEnvironment::EntityGetEntityInfo(a2, 1u);
  if ( !EntityInfo && BBSupportDbgReport(2, "AI\\AI_SectorAI.cpp", 517, "pEntityInfo != 0") == 1 )
    __debugbreak();
  v3 = IAIEnvironment::TickCounter();
  CAIEntityInfo::SetTimeStamp(EntityInfo, v3);
  v4 = CAIEntityInfo::ExtendedInfo(EntityInfo, 0);
  *(_DWORD *)(v4 + 8) = v15;
  *(_DWORD *)(v4 + 12) = v16;
  v5 = v4;
  result = v17;
  *(_DWORD *)(v5 + 16) = v17;
  return result;
}


// address=[0x1320890]
// Decompiled from pairNode *__thiscall CAISectorAI::MoveOneDefendingFighterToReservoir(_DWORD *this, int a2, int a3, char a4)
void  CAISectorAI::MoveOneDefendingFighterToReservoir(int a2, enum T_AI_WARRIOR_TYPE a3, bool a4) {
  
  pairNode *result; // eax
  int v5; // eax
  struct CAITaskForce *TaskForceGroupMemberOfSameClass; // [esp+0h] [ebp-3370h]
  pairNode *v8; // [esp+14h] [ebp-335Ch]
  CAITaskForce *i; // [esp+18h] [ebp-3358h]
  _BYTE v10[13136]; // [esp+1Ch] [ebp-3354h] BYREF

  result = (pairNode *)CAISectorAI::Reservoir(this, a3);
  v8 = result;
  if ( !result )
    return result;
  if ( a4 )
  {
    result = (pairNode *)CAITaskForce::NumberOfEntities(result);
    if ( (int)result > 0 )
      return result;
  }
  CAIChambers::CAIChambers((CAIChambers *)v10, a2);
  CAIChambers::Clear((CAIChambers *)v10);
  v5 = CAISectorAI::TaskForceGroup(this);
  for ( i = (CAITaskForce *)CAITaskForceGroup::FirstTaskForce(v5, 2); i; i = TaskForceGroupMemberOfSameClass )
  {
    TaskForceGroupMemberOfSameClass = CAITaskForce::NextTaskForceGroupMemberOfSameClass(i);
    if ( CAITaskForce::Type(i) == 5 )
      CAIChambers::PushTaskForceEx((CAIChambers *)v10, i, 1 << a3);
  }
  CAIChambers::First((CAIChambers *)v10);
  result = (pairNode *)CAIChambers::Current((CAIChambers *)v10);
  if ( (int)result > 0 )
    return (pairNode *)CAITaskForce::AddEntity(v8, (int)result, 0);
  return result;
}


// address=[0x13209e0]
// Decompiled from int __thiscall CAISectorAI::FindInnerPoint(pairNode **this, int a2)
int  CAISectorAI::FindInnerPoint(int a2) {
  
  _BYTE v3[20]; // [esp+4h] [ebp-8Ch] BYREF
  int v4; // [esp+18h] [ebp-78h]
  int v5; // [esp+1Ch] [ebp-74h]
  int v6; // [esp+20h] [ebp-70h]
  int v7; // [esp+24h] [ebp-6Ch]
  int v8; // [esp+28h] [ebp-68h]
  struct _Mtx_internal_imp_t *v9; // [esp+2Ch] [ebp-64h]
  struct _Cnd_internal_imp_t *v10; // [esp+30h] [ebp-60h]
  int v11; // [esp+34h] [ebp-5Ch]
  int v12; // [esp+38h] [ebp-58h]
  BOOL v13; // [esp+3Ch] [ebp-54h]
  BOOL v14; // [esp+40h] [ebp-50h]
  BOOL v15; // [esp+44h] [ebp-4Ch]
  pairNode **v16; // [esp+48h] [ebp-48h]
  int v17; // [esp+4Ch] [ebp-44h] BYREF
  int v18; // [esp+50h] [ebp-40h] BYREF
  int v19; // [esp+54h] [ebp-3Ch]
  int v20; // [esp+58h] [ebp-38h]
  int j; // [esp+5Ch] [ebp-34h]
  int v22; // [esp+60h] [ebp-30h]
  struct _Cnd_internal_imp_t *v23; // [esp+64h] [ebp-2Ch]
  struct _Mtx_internal_imp_t *v24; // [esp+68h] [ebp-28h]
  int i; // [esp+6Ch] [ebp-24h]
  int k; // [esp+70h] [ebp-20h]
  _DWORD v27[6]; // [esp+74h] [ebp-1Ch] BYREF

  v16 = this;
  v10 = (struct _Cnd_internal_imp_t *)IAIEnvironment::UnpackXFast(a2);
  v9 = (struct _Mtx_internal_imp_t *)IAIEnvironment::UnpackYFast(a2);
  v4 = CAIPlayerAI::PlayerId(v16[1]);
  v8 = CAISectorAI::SectorId((CAISectorAI *)v16);
  memset(v27, 0, sizeof(v27));
  for ( i = 0; i < 6; ++i )
  {
    v19 = 0;
    v7 = g_sNeighborPoints[2 * i];
    v6 = dword_37D8C0C[2 * i];
    v23 = v10;
    v24 = v9;
    for ( j = 0; j < 8; ++j )
    {
      v23 = (struct _Cnd_internal_imp_t *)((char *)v23 + v7);
      v24 = (struct _Mtx_internal_imp_t *)((char *)v24 + v6);
      if ( !IAIEnvironment::WorldInWorld(v23, v24) )
        break;
      v5 = IAIEnvironment::WorldOwnerId(v23, v24);
      if ( v5 != v4 )
        break;
      v20 = IAIEnvironment::WorldSectorId((int)v23, (int)v24);
      v15 = v20 != 0;
      v14 = v20 != v8;
      if ( v14 && v15 )
        break;
      v13 = v20 != 0;
      v19 += v13 + 1;
    }
    v27[i] = v19;
  }
  v22 = -1;
  v11 = 0;
  for ( k = 0; k < 6; ++k )
  {
    if ( (int)v27[k] > 0 )
    {
      v12 = v27[(k + 1) % 6] + v27[(k + 5) % 6] + 4 * v27[k];
      if ( v12 > v11 )
      {
        v11 = v12;
        v22 = k;
      }
    }
  }
  if ( v22 >= 0
    && (v17 = (int)v10 + 6 * g_sNeighborPoints[2 * v22],
        v18 = (int)v9 + 6 * dword_37D8C0C[2 * v22],
        CSectorSpiralWalk::CSectorSpiralWalk((CSectorSpiralWalk *)v3, v17, v18, 8, v8),
        CSectorSpiralWalk::NextXY((CSectorSpiralWalk *)v3, &v17, &v18)) )
  {
    return IAIEnvironment::PackXYFast(v17, v18);
  }
  else
  {
    return a2;
  }
}


// address=[0x1320c90]
// Decompiled from int __thiscall CAISectorAI::MoveFightersToReservoir(CAISectorAI *this, struct CAITaskForce *a2)
void  CAISectorAI::MoveFightersToReservoir(class CAITaskForce * a2) {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-14h]
  unsigned int v5; // [esp+8h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  if ( !a2 && BBSupportDbgReport(2, "AI\\AI_SectorAI.cpp", 732, "_pSquad != 0") == 1 )
    __debugbreak();
  result = CAITaskForce::FirstEntity(a2);
  for ( i = result; i; i = v3 )
  {
    v3 = CAIEntityInfo::Next(i);
    v6 = CAIEntityInfo::EntityId(i);
    v5 = IAIEnvironment::EntityWarriorType(v6);
    result = CAISectorAI::AddEntityToReservoir(this, v6, v5);
  }
  return result;
}


// address=[0x1320d20]
// Decompiled from int __thiscall CAISectorAI::RecruitNearestFighterForTaskForce(_DWORD *this, void *a2, int a3, int a4, int a5)
int  CAISectorAI::RecruitNearestFighterForTaskForce(class CAITaskForce * a2, int a3, enum T_AI_WARRIOR_TYPE a4, int a5) {
  
  int v5; // eax
  int v7; // [esp+Ch] [ebp-18h]
  int v8; // [esp+10h] [ebp-14h]
  int v9; // [esp+14h] [ebp-10h]
  int v10; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  int v12; // [esp+20h] [ebp-4h]

  v7 = CAISectorAI::Reservoir(this, a4);
  if ( !v7 )
    return 0;
  v10 = 0;
  v8 = 9999;
  for ( i = CAITaskForce::FirstEntity(v7); i; i = CAIEntityInfo::Next(i) )
  {
    v12 = CAIEntityInfo::EntityId(i);
    v5 = IAIEnvironment::EntityPackedPosition(v12);
    v9 = IAIEnvironment::GridDistancePackedXY(v5, a3);
    if ( v9 <= 8 )
    {
      CAITaskForce::AddEntity(a2, v12, 0);
      return v12;
    }
    if ( v9 < v8 )
    {
      v8 = v9;
      v10 = v12;
    }
  }
  if ( v8 > a5 || v10 == 0 )
    return 0;
  CAITaskForce::AddEntity(a2, v10, 0);
  return v10;
}


// address=[0x1320e20]
// Decompiled from void __thiscall CAISectorAI::RecruitFightersForSquad(_DWORD *this, void *a2, int a3, int a4, int a5)
void  CAISectorAI::RecruitFightersForSquad(class CAITaskForce * a2, int a3, enum T_AI_WARRIOR_TYPE a4, int a5) {
  
  int v5; // eax
  struct CAITaskForce *v6; // [esp+Ch] [ebp-335Ch]
  int i; // [esp+10h] [ebp-3358h]
  _BYTE v8[13136]; // [esp+14h] [ebp-3354h] BYREF

  if ( a5 > 0 )
  {
    v6 = (struct CAITaskForce *)CAISectorAI::Reservoir(this, a4);
    if ( v6 )
    {
      CAIChambers::CAIChambers((CAIChambers *)v8, a3);
      CAIChambers::Clear((CAIChambers *)v8);
      CAIChambers::PushTaskForce((CAIChambers *)v8, v6);
      CAIChambers::First((CAIChambers *)v8);
      for ( i = 0; ((i < a5) & (CAIChambers::Current((CAIChambers *)v8) >= 0)) != 0; ++i )
      {
        v5 = CAIChambers::Current((CAIChambers *)v8);
        CAITaskForce::AddEntity(a2, v5, 0);
        CAIChambers::Next((CAIChambers *)v8);
      }
    }
  }
}


// address=[0x1320f50]
// Decompiled from void __thiscall CAISectorAI::AutoRecruitFightersForSquad(CAISectorAI *this, struct CAITaskForce *a2, int a3, int a4)
void  CAISectorAI::AutoRecruitFightersForSquad(class CAITaskForce * a2, int a3, int a4) {
  
  pairNode *v4; // eax
  pairNode *v5; // eax
  pairNode *v6; // eax
  pairNode *v7; // eax
  int v8; // [esp+0h] [ebp-34h]
  int v9; // [esp+4h] [ebp-30h]
  int v10; // [esp+8h] [ebp-2Ch]
  int v11; // [esp+Ch] [ebp-28h]
  int v12; // [esp+10h] [ebp-24h]
  int v13; // [esp+18h] [ebp-1Ch]
  int v14; // [esp+1Ch] [ebp-18h]
  int v15; // [esp+20h] [ebp-14h]
  int v16; // [esp+24h] [ebp-10h]
  int v17; // [esp+28h] [ebp-Ch]
  int v19; // [esp+30h] [ebp-4h]

  v12 = (*(int (__thiscall **)(struct CAITaskForce *, int))(*(_DWORD *)a2 + 16))(a2, 2);
  v11 = (*(int (__thiscall **)(struct CAITaskForce *, int))(*(_DWORD *)a2 + 16))(a2, 3);
  v10 = (*(int (__thiscall **)(struct CAITaskForce *, int))(*(_DWORD *)a2 + 16))(a2, 4);
  v9 = (*(int (__thiscall **)(struct CAITaskForce *, int))(*(_DWORD *)a2 + 16))(a2, 5);
  v4 = (pairNode *)CAISectorAI::Reservoir(this, 2);
  v15 = CAITaskForce::NumberOfEntities(v4);
  v5 = (pairNode *)CAISectorAI::Reservoir(this, 3);
  v14 = CAITaskForce::NumberOfEntities(v5);
  v6 = (pairNode *)CAISectorAI::Reservoir(this, 4);
  v13 = CAITaskForce::NumberOfEntities(v6);
  v7 = (pairNode *)CAISectorAI::Reservoir(this, 5);
  v8 = CAITaskForce::NumberOfEntities(v7);
  if ( a4 > v14 + v15 )
    a4 = v14 + v15;
  v19 = (a4 - (v11 - v12 / 2)) / 2;
  if ( v19 < 0 )
    v19 = 0;
  v17 = a4 - v19;
  if ( v19 <= v15 )
  {
    if ( v17 > v14 )
    {
      v19 = a4 - v14;
      v17 = v14;
    }
    CAISectorAI::RecruitFightersForSquad(this, a2, a3, 2, v19);
  }
  else
  {
    v17 = a4 - v15;
    CAISectorAI::RecruitFightersForSquad(this, a2, a3, 2, v15);
  }
  CAISectorAI::RecruitFightersForSquad(this, a2, a3, 3, v17);
  v16 = (v11 + v12) / 6 - v10;
  if ( v16 > 0 && v13 > 0 )
  {
    if ( v16 > 4 )
      v16 = 4;
    if ( v16 > v13 )
      v16 = v13;
    CAISectorAI::RecruitFightersForSquad(this, a2, a3, 4, v16);
  }
  if ( v9 < 1 && v8 >= 1 )
    CAISectorAI::RecruitNearestFighterForTaskForce(this, a2, a3, 5, 9999);
}


// address=[0x1321110]
// Decompiled from void __thiscall CAISectorAI::SearchHeadquarter(struct CAISectorAI *this)
void  CAISectorAI::SearchHeadquarter(void) {
  
  int v1; // [esp+8h] [ebp-68h]
  int v2; // [esp+Ch] [ebp-64h]
  int v3; // [esp+10h] [ebp-60h]
  int v4; // [esp+14h] [ebp-5Ch]
  int v5; // [esp+18h] [ebp-58h]
  int v6; // [esp+1Ch] [ebp-54h]
  _DWORD v8[6]; // [esp+24h] [ebp-4Ch] BYREF
  _DWORD v9[6]; // [esp+3Ch] [ebp-34h] BYREF
  _DWORD v10[6]; // [esp+54h] [ebp-1Ch] BYREF

  v3 = CAISectorAI::BaseX(this);
  v4 = CAISectorAI::BaseY(this);
  v6 = CAISectorAI::SectorId(this);
  if ( !v6 && BBSupportDbgReport(2, "AI\\AI_SectorAI.cpp", 346, "iSectorId != 0") == 1 )
    __debugbreak();
  v2 = 0x4000;
  v1 = 0x4000;
  v5 = 0x4000;
  if ( IAIEnvironment::BuildingSearchNearestBuildingInSector(
         *(_DWORD *)(*((_DWORD *)this + 1) + 12),
         46,
         v3,
         v4,
         v6,
         (struct SAIBuildingSearchResult *)v10) )
  {
    v2 = 4 * v10[5];
  }
  if ( IAIEnvironment::BuildingSearchNearestBuildingInSector(
         *(_DWORD *)(*((_DWORD *)this + 1) + 12),
         47,
         v3,
         v4,
         v6,
         (struct SAIBuildingSearchResult *)v9) )
  {
    v1 = 2 * v9[5];
  }
  if ( IAIEnvironment::BuildingSearchNearestBuildingInSector(
         *(_DWORD *)(*((_DWORD *)this + 1) + 12),
         48,
         v3,
         v4,
         v6,
         (struct SAIBuildingSearchResult *)v8) )
  {
    v5 = v8[5];
  }
  if ( v2 < v5 && v2 < v1 )
  {
    CAISectorAI::SetBasePosition(this, v10[3], v10[4]);
    CAISectorAI::SetHeadquarterId(this, v10[0]);
  }
  else if ( v1 >= v5 )
  {
    if ( v5 >= 0x4000 )
    {
      CAISectorAI::SetHeadquarterId(this, 0);
    }
    else
    {
      CAISectorAI::SetBasePosition(this, v8[3], v8[4]);
      CAISectorAI::SetHeadquarterId(this, v8[0]);
    }
  }
  else
  {
    CAISectorAI::SetBasePosition(this, v9[3], v9[4]);
    CAISectorAI::SetHeadquarterId(this, v9[0]);
  }
}


// address=[0x13212e0]
// Decompiled from int __thiscall CAISectorAI::CalculateSectorIdAndEcoSectorIds(CAISectorAI *this)
void  CAISectorAI::CalculateSectorIdAndEcoSectorIds(void) {
  
  return CAISectorAI::CheckBasePosition(this);
}


// address=[0x1321300]
// Decompiled from int __thiscall CAISectorAI::DeleteEmptyTaskForces(void *this, int a2)
void  CAISectorAI::DeleteEmptyTaskForces(enum T_AI_TASK_FORCE_CLASS a2) {
  
  int v2; // eax
  int result; // eax
  struct CAITaskForce *TaskForceGroupMemberOfSameClass; // [esp+0h] [ebp-Ch]
  pairNode *i; // [esp+8h] [ebp-4h]

  v2 = CAISectorAI::TaskForceGroup(this);
  result = CAITaskForceGroup::FirstTaskForce(v2, a2);
  for ( i = (pairNode *)result; i; i = TaskForceGroupMemberOfSameClass )
  {
    if ( CAITaskForce::Class(i) != a2
      && BBSupportDbgReport(2, "AI\\AI_SectorAI.cpp", 433, "pTaskForce->Class() == _tTaskForceClass") == 1 )
    {
      __debugbreak();
    }
    TaskForceGroupMemberOfSameClass = CAITaskForce::NextTaskForceGroupMemberOfSameClass(i);
    result = CAITaskForce::NumberOfEntities(i);
    if ( !result )
    {
      if ( CAITaskForce::FirstEntity(i) )
      {
        if ( BBSupportDbgReport(2, "AI\\AI_SectorAI.cpp", 439, "pTaskForce->FirstEntity() == 0") == 1 )
          __debugbreak();
      }
      result = (*(int (__thiscall **)(pairNode *))(*(_DWORD *)i + 12))(i);
    }
  }
  return result;
}


// address=[0x13213c0]
// Decompiled from int __thiscall CAISectorAI::AddEntityToReservoir(CAISectorAI *this, int a2)
void  CAISectorAI::AddEntityToReservoir(int a2) {
  
  unsigned int v2; // eax

  if ( a2 <= 0 && BBSupportDbgReport(2, "AI\\AI_SectorAI.cpp", 248, "_iEntityId > 0") == 1 )
    __debugbreak();
  v2 = IAIEnvironment::EntityWarriorType(a2);
  return CAISectorAI::AddEntityToReservoir(this, a2, v2);
}


// address=[0x1321410]
// Decompiled from int __thiscall CAISectorAI::AddEntityToReservoir(void **this, int a2, int a3)
void  CAISectorAI::AddEntityToReservoir(int a2, enum T_AI_WARRIOR_TYPE a3) {
  
  int result; // eax

  if ( a2 <= 0 && BBSupportDbgReport(2, "AI\\AI_SectorAI.cpp", 260, "_iEntityId > 0") == 1 )
    __debugbreak();
  if ( a3 > 14 && BBSupportDbgReport(2, "AI\\AI_SectorAI.cpp", 261, "_tWarriorType <= AI_WARRIOR_TYPE_LAST") == 1 )
    __debugbreak();
  if ( IAIEnvironment::EntityWarriorType(a2) != a3
    && BBSupportDbgReport(2, "AI\\AI_SectorAI.cpp", 262, "g_pAIEnv->EntityWarriorType(_iEntityId) == _tWarriorType") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  if ( !a3 )
    return result;
  if ( this[a3 + 8] )
    return CAITaskForce::AddEntity(this[a3 + 8], a2, 0);
  return result;
}


// address=[0x1321b20]
// Decompiled from int __thiscall CAISectorAI::BaseWorldIdx(CAISectorAI *this)
int  CAISectorAI::BaseWorldIdx(void)const {
  
  return *((_DWORD *)this + 64);
}


// address=[0x1321c50]
// Decompiled from int __thiscall CAISectorAI::SetBasePosition(CAISectorAI *this, int a2, int a3)
void  CAISectorAI::SetBasePosition(int a2, int a3) {
  
  *((_DWORD *)this + 62) = a2;
  *((_DWORD *)this + 63) = a3;
  *((_DWORD *)this + 64) = IAIEnvironment::WorldIndex(a2, a3);
  *((_DWORD *)this + 65) = IAIEnvironment::WorldSectorId(*((_DWORD *)this + 65));
  if ( *((int *)this + 65) <= 0
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_SectorAI.h",
         147,
         "m_sHeadquarterData.m_iCurrentSectorId > 0") == 1 )
  {
    __debugbreak();
  }
  return 0;
}


// address=[0x1321d00]
// Decompiled from CAISectorAI *__thiscall CAISectorAI::SetHeadquarterId(CAISectorAI *this, int a2)
void  CAISectorAI::SetHeadquarterId(int a2) {
  
  CAISectorAI *result; // eax

  result = this;
  *((_DWORD *)this + 61) = a2;
  return result;
}


// address=[0x13260c0]
// Decompiled from void __cdecl CAISectorAI::AwakeAgent(struct CAIAgent *a1)
void __cdecl CAISectorAI::AwakeAgent(class CAIAgent & a1) {
  
  int v1; // esi
  unsigned int v2; // eax

  v1 = IAIEnvironment::TickCounter();
  v2 = CAIAgent::DefaultExecutionDelay(a1);
  CAIAgent::UpdateScheduleTimeIfLess(a1, v2 + v1);
}


// address=[0x131ff50]
// Decompiled from CAISectorAI *__thiscall CAISectorAI::CAISectorAI(CAISectorAI *this, pairNode *a2)
 CAISectorAI::CAISectorAI(class CAIPlayerAI & a2) {
  
  int v2; // eax

  IAISectorAI::IAISectorAI(this);
  *(_DWORD *)this = &CAISectorAI::_vftable_;
  *((_DWORD *)this + 1) = a2;
  CAIEventQueue::CAIEventQueue((CAISectorAI *)((char *)this + 8));
  v2 = CAIPlayerAI::PlayerId(a2);
  CAITaskForceGroup::CAITaskForceGroup((CAISectorAI *)((char *)this + 92), v2);
  memset((char *)this + 32, 0, 0x3Cu);
  memset((char *)this + 232, 0, 0x20u);
  return this;
}


// address=[0x13214d0]
// Decompiled from const struct CAIEvent *__thiscall CAISectorAI::ProcessEvents(CAISectorAI *this)
void  CAISectorAI::ProcessEvents(void) {
  
  const struct CAIEvent *result; // eax
  const struct CAIEvent *i; // [esp+0h] [ebp-8h]

  result = CAIEventQueue::PeekAIEvent((CAISectorAI *)((char *)this + 8), 1);
  for ( i = result; i; i = result )
  {
    (*(void (__thiscall **)(CAISectorAI *, const struct CAIEvent *))(*(_DWORD *)this + 40))(this, i);
    result = CAIEventQueue::PeekAIEvent((CAISectorAI *)((char *)this + 8), 1);
  }
  return result;
}


// address=[0x1321520]
// Decompiled from char __thiscall CAISectorAI::ProcessEvent(CAISectorAI *this, const struct CAIEvent *a2)
bool  CAISectorAI::ProcessEvent(class CAIEvent const * a2) {
  
  return 0;
}


