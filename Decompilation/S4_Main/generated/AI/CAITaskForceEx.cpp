#include "CAITaskForceEx.h"

// Definitions for class CAITaskForceEx

// address=[0x132a540]
// Decompiled from CAITaskForceEx *__thiscall CAITaskForceEx::ClearWaypoints(CAITaskForceEx *this)
void  CAITaskForceEx::ClearWaypoints(void) {
  
  CAITaskForceEx *result; // eax

  *((_DWORD *)this + 21) = -1;
  result = this;
  *((_DWORD *)this + 22) = -1;
  *((_DWORD *)this + 23) = -1;
  return result;
}


// address=[0x132a590]
// Decompiled from int __thiscall CAITaskForceEx::PopWaypoint(CAITaskForceEx *this)
void  CAITaskForceEx::PopWaypoint(void) {
  
  int result; // eax

  *((_DWORD *)this + 21) = *((_DWORD *)this + 22);
  result = *((_DWORD *)this + 23);
  *((_DWORD *)this + 22) = result;
  *((_DWORD *)this + 23) = -1;
  return result;
}


// address=[0x132a600]
// Decompiled from bool __thiscall CAITaskForceEx::CheckWaypoint(CAITaskForceEx *this)
bool  CAITaskForceEx::CheckWaypoint(void) {
  
  struct _Cnd_internal_imp_t *v2; // [esp+4h] [ebp-20h]
  struct _Mtx_internal_imp_t *v3; // [esp+8h] [ebp-1Ch]
  int v4; // [esp+Ch] [ebp-18h]
  struct _Cnd_internal_imp_t *v5; // [esp+10h] [ebp-14h] BYREF
  struct _Mtx_internal_imp_t *v6; // [esp+14h] [ebp-10h] BYREF
  CAITaskForce *v7; // [esp+18h] [ebp-Ch]
  int v8; // [esp+1Ch] [ebp-8h]

  v7 = this;
  v8 = CAITaskForceEx::WaypointXY(this);
  if ( v8 <= 0 )
    return 0;
  v2 = (struct _Cnd_internal_imp_t *)IAIEnvironment::UnpackXFast(v8);
  v3 = (struct _Mtx_internal_imp_t *)IAIEnvironment::UnpackYFast(v8);
  v4 = IAIEnvironment::WorldSectorId((int)v2, (int)v3);
  if ( v4 <= 0 )
    return 0;
  v5 = 0;
  v6 = 0;
  return CAITaskForce::GetPositionOfFirstEntity(v7, (int *)&v5, (int *)&v6)
      && v4 == IAIEnvironment::WorldSectorId((int)v5, (int)v6);
}


// address=[0x132a6c0]
// Decompiled from char __thiscall CAITaskForceEx::CheckDestination(CAITaskForceEx *this)
bool  CAITaskForceEx::CheckDestination(void) {
  
  char v1; // al
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // eax
  int v8; // [esp+0h] [ebp-1Ch] BYREF
  int v9; // [esp+4h] [ebp-18h] BYREF
  BOOL v10; // [esp+8h] [ebp-14h]
  BOOL v11; // [esp+Ch] [ebp-10h]
  int NearestNoneBlockedPosition; // [esp+10h] [ebp-Ch]
  CUserToolsManager *v13; // [esp+14h] [ebp-8h]
  char v14; // [esp+1Bh] [ebp-1h]

  v13 = this;
  if ( (CAITaskForce::Flags(this) & 0x2000) == 0 )
    return 1;
  if ( *((int *)v13 + 20) < 0 )
    *((_DWORD *)v13 + 20) = CAITaskForce::CmdGoal(v13);
  if ( *((int *)v13 + 20) < 0 )
    return 0;
  if ( !IAIEnvironment::WorldInWorldPackedXY(*((_DWORD *)v13 + 20))
    && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 501, "g_pAIEnv->WorldInWorldPackedXY(m_iDestinationXY)") == 1 )
  {
    __debugbreak();
  }
  IAIEnvironment::WorldIsBlockedLandPackedXY(*((struct _iobuf **)v13 + 20));
  v14 = v1;
  if ( !v1 )
    return 1;
  v2 = CAITaskForce::CmdGoal(v13);
  if ( !IAIEnvironment::WorldInWorldPackedXY(v2)
    && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 507, "g_pAIEnv->WorldInWorldPackedXY(CmdGoal())") == 1 )
  {
    __debugbreak();
  }
  v3 = CAITaskForce::CmdGoal(v13);
  v8 = IAIEnvironment::UnpackXFast(v3);
  v4 = CAITaskForce::CmdGoal(v13);
  v9 = IAIEnvironment::UnpackYFast(v4);
  NearestNoneBlockedPosition = IAIEnvironment::GetNearestNoneBlockedPosition(&v8, &v9);
  v11 = NearestNoneBlockedPosition >= 0;
  v10 = NearestNoneBlockedPosition < 16;
  if ( v10 && v11 )
  {
    v5 = IAIEnvironment::PackXYFast(v8, v9);
    *((_DWORD *)v13 + 20) = v5;
    return 1;
  }
  else
  {
    v7 = CAITaskForce::CmdGoal(v13);
    *((_DWORD *)v13 + 20) = v7;
    return 0;
  }
}


// address=[0x132a840]
// Decompiled from char __thiscall CAITaskForceEx::FindWaypoints(CAITaskForceEx *this)
bool  CAITaskForceEx::FindWaypoints(void) {
  
  int v2; // eax
  int v3; // eax
  int v4; // [esp-4h] [ebp-80h]
  int v5; // [esp+0h] [ebp-7Ch]
  int v6; // [esp+4h] [ebp-78h]
  int Entity; // [esp+14h] [ebp-68h]
  int i; // [esp+18h] [ebp-64h]
  _BYTE v10[88]; // [esp+20h] [ebp-5Ch] BYREF

  CAITaskForceEx::ClearWaypoints(this);
  if ( !CAITaskForceEx::CheckDestination(this) )
    return 0;
  Entity = CAITaskForce::FirstEntity(this);
  if ( !Entity )
    return 0;
  v2 = CAIEntityInfo::EntityId(Entity);
  v6 = IAIEnvironment::EntityPackedPosition(v2);
  v4 = CAITaskForce::OwnerId(this) | 0x80;
  v3 = CAITaskForceEx::DestinationXY(this);
  if ( !CAStarTiling::FindPath(v6, v3, (struct CWaypoints *)v10, v4) )
    return 0;
  for ( i = 0; ((i < 3) & (CWaypoints::CachedWaypointsCount((pairNode *)v10) > 0)) != 0; ++i )
  {
    v5 = CWaypoints::Back(v10, v5);
    CWaypoints::PopBack(v10);
    *((_DWORD *)this + i + 21) = v5;
  }
  if ( *((int *)this + 21) < 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 590, "m_iWaypointsXY[0] >= 0") == 1 )
    __debugbreak();
  return 1;
}


// address=[0x132a990]
// Decompiled from char __thiscall CAITaskForceEx::SetDestinationXY(CAITaskForceEx *this, int a2)
bool  CAITaskForceEx::SetDestinationXY(int) {
  
  *((_DWORD *)this + 20) = a2;
  CAITaskForceEx::ClearWaypoints(this);
  return 1;
}


// address=[0x132a9b0]
// Decompiled from char __thiscall CAITaskForceEx::Execute(CAITaskForceEx *this)
void  CAITaskForceEx::Execute(void) {
  
  int v1; // eax
  int v2; // esi
  int v3; // eax
  int v4; // eax
  int v6; // [esp+Ch] [ebp-28h]
  int v7; // [esp+14h] [ebp-20h]
  int v8; // [esp+18h] [ebp-1Ch]
  int v9; // [esp+20h] [ebp-14h]
  int i; // [esp+24h] [ebp-10h]
  int Entity; // [esp+28h] [ebp-Ch]
  char Waypoints; // [esp+33h] [ebp-1h]

  CAITaskForce::SetWaitCounter(this, 8u);
  v1 = CAITaskForce::State(this);
  switch ( v1 )
  {
    case 0:
      LOBYTE(v1) = CAITaskForce::SetStatus(this, 1);
      return v1;
    case 100:
      goto LABEL_2;
    case 101:
      if ( (CAITaskForce::Flags(this) & 0x10000) != 0 )
      {
        v7 = CAITaskForce::NumberOfEntities(this) / 2;
        v8 = 128;
      }
      else
      {
        v7 = 0;
        v8 = 3;
      }
      v9 = 0;
      Entity = CAITaskForce::FirstEntity(this);
      break;
    case 102:
      CAITaskForceEx::FindWaypoints(this);
      CAITaskForceEx::InitGroupWalk(this);
      CAITaskForce::SetWaitCounter(this, 0x20u);
      CAITaskForce::SetState(this, 101);
      LOBYTE(v1) = (unsigned __int8)CAITaskForce::ClearStateFlagBit(this, 0x10000u);
      return v1;
    case 104:
      if ( !CAITaskForce::GoalIsEntity(this)
        && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 860, "GoalIsEntity()") == 1 )
      {
        __debugbreak();
      }
      v3 = CAITaskForce::CmdGoal(this);
      if ( (((unsigned int)&loc_1FFFFFF + 1) & IAIEnvironment::EntityFlags(v3)) == 0 )
        goto LABEL_34;
      v1 = CAITaskForce::FirstEntity(this);
      for ( i = v1; i; i = v1 )
      {
        CAIEntityInfo::EntityId(i);
        v1 = CAIEntityInfo::Next(i);
      }
      return v1;
    case 105:
      if ( !CAITaskForce::GoalIsEntity(this)
        && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 887, "GoalIsEntity()") == 1 )
      {
        __debugbreak();
      }
      v4 = CAITaskForce::CmdGoal(this);
      v1 = ((unsigned int)&loc_1FFFFFF + 1) & IAIEnvironment::EntityFlags(v4);
      if ( v1 )
        return v1;
      goto LABEL_34;
    case 106:
      LOBYTE(v1) = CAITaskForceEx::EscortInitWalk(this);
      if ( !(_BYTE)v1 )
LABEL_34:
        LOBYTE(v1) = (unsigned __int8)CAITaskForce::SetState(this, 0);
      return v1;
    default:
      return v1;
  }
  while ( Entity )
  {
    v6 = CAIEntityInfo::EntityId(Entity);
    if ( IAIEnvironment::MovingEntityWalkingState(v6) >= v8 )
    {
      LOBYTE(v1) = ++v9;
      if ( v9 >= v7 )
        return v1;
    }
    Entity = CAIEntityInfo::Next(Entity);
  }
  CAITaskForce::SetStateFlagBit(this, 0x10000u);
  v2 = CAITaskForceEx::WaypointXY(this);
  if ( v2 == CAITaskForceEx::DestinationXY(this) )
  {
    CAITaskForceEx::ClearWaypoints(this);
    LOBYTE(v1) = (unsigned __int8)CAITaskForce::ActivateNextState(this);
  }
  else
  {
    Waypoints = 1;
    CAITaskForceEx::PopWaypoint(this);
    if ( !CAITaskForceEx::CheckWaypoint(this) )
      Waypoints = CAITaskForceEx::FindWaypoints(this);
    if ( Waypoints )
    {
      CAITaskForceEx::InitGroupWalk(this);
      LOBYTE(v1) = CAITaskForce::SetWaitCounter(this, 0x20u);
    }
    else
    {
LABEL_2:
      LOBYTE(v1) = (unsigned __int8)CAITaskForce::ActivateNextState(this);
    }
  }
  return v1;
}


// address=[0x132ace0]
// Decompiled from int __thiscall CAITaskForceEx::InitWalk(CAITaskForceEx *this, bool a2)
void  CAITaskForceEx::InitWalk(bool) {
  
  int result; // eax
  bool i; // al
  int v4; // [esp+0h] [ebp-2Ch]
  int v5; // [esp+4h] [ebp-28h]
  int v6; // [esp+8h] [ebp-24h]
  int v7; // [esp+Ch] [ebp-20h]
  struct _Cnd_internal_imp_t *v8; // [esp+10h] [ebp-1Ch]
  struct _Mtx_internal_imp_t *v9; // [esp+14h] [ebp-18h]
  int v11; // [esp+1Ch] [ebp-10h]
  struct _Mtx_internal_imp_t *v12; // [esp+20h] [ebp-Ch]
  struct _Cnd_internal_imp_t *v13; // [esp+24h] [ebp-8h]
  int v14; // [esp+28h] [ebp-4h]

  result = CAITaskForce::FirstEntity(this);
  v11 = result;
  if ( !result )
    return result;
  result = CAITaskForceEx::WaypointXY(this);
  if ( result <= 0 )
    return result;
  v13 = (struct _Cnd_internal_imp_t *)CAITaskForceEx::WaypointX(this);
  v12 = (struct _Mtx_internal_imp_t *)CAITaskForceEx::WaypointY(this);
  if ( !IAIEnvironment::WorldInWorld(v13, v12)
    && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 631, "g_pAIEnv->WorldInWorld(iX0, iY0)") == 1 )
  {
    __debugbreak();
  }
  if ( (unsigned __int8)IAIEnvironment::WorldIsBlockedLand(v13, v12)
    && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 632, "!g_pAIEnv->WorldIsBlockedLand(iX0, iY0)") == 1 )
  {
    __debugbreak();
  }
  result = IAIEnvironment::WorldSectorId((int)v13, (int)v12);
  v7 = result;
  if ( result <= 0 )
  {
    result = BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 636, "iSectorId > 0");
    if ( result == 1 )
      __debugbreak();
  }
  v14 = 0;
  while ( v11 )
  {
    v8 = (struct _Cnd_internal_imp_t *)((char *)v13 + 2 * SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * v14]));
    v9 = (struct _Mtx_internal_imp_t *)((char *)v12 + 2 * SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * v14]));
    for ( i = IAIEnvironment::WorldInWorld(v8, v9);
          !i || IAIEnvironment::WorldSectorId((int)v8, (int)v9) != v7;
          i = IAIEnvironment::WorldInWorld(v8, v9) )
    {
      if ( v14 < 37 )
        v6 = v14 + 1;
      else
        v6 = 0;
      v14 = v6;
      v8 = (struct _Cnd_internal_imp_t *)((char *)v13 + 2 * SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * v6]));
      v9 = (struct _Mtx_internal_imp_t *)((char *)v12 + 2 * SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * v6]));
    }
    if ( v14 < 37 )
      v5 = v14 + 1;
    else
      v5 = 0;
    v14 = v5;
    v4 = CAIEntityInfo::EntityId(v11);
    IAIEnvironment::MovingEntitySendMoveCommand(v4, (int)v8, (int)v9, a2);
    result = CAIEntityInfo::Next(v11);
    v11 = result;
  }
  return result;
}


// address=[0x132aef0]
// Decompiled from int __thiscall CAITaskForceEx::InitGroupWalk(CAITaskForceEx *this)
void  CAITaskForceEx::InitGroupWalk(void) {
  
  bool v3; // [esp+7h] [ebp-1h]

  v3 = CAITaskForce::Class(this) != 6;
  return CAITaskForceEx::InitWalk(this, v3);
}


// address=[0x132af30]
// Decompiled from char __thiscall CAITaskForceEx::FindSneakUpPosition(CAITaskForceEx *this)
bool  CAITaskForceEx::FindSneakUpPosition(void) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // [esp+0h] [ebp-8Ch]
  int v6; // [esp+4h] [ebp-88h]
  int v7; // [esp+Ch] [ebp-80h]
  int v8; // [esp+10h] [ebp-7Ch]
  int v9; // [esp+14h] [ebp-78h]
  int Entity; // [esp+18h] [ebp-74h]
  struct _iobuf *v11; // [esp+1Ch] [ebp-70h]
  struct _iobuf *v12; // [esp+20h] [ebp-6Ch]
  int v13; // [esp+24h] [ebp-68h]
  char v15; // [esp+2Fh] [ebp-5Dh]
  _BYTE v16[88]; // [esp+30h] [ebp-5Ch] BYREF

  (*(void (__thiscall **)(CAITaskForceEx *, int))(*(_DWORD *)this + 44))(this, -1);
  Entity = CAITaskForce::FirstEntity(this);
  if ( !Entity )
    return 0;
  if ( !CAITaskForce::GoalIsPosition(this)
    && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 281, "GoalIsPosition()") == 1 )
  {
    __debugbreak();
  }
  v2 = CAIEntityInfo::EntityId(Entity);
  v7 = IAIEnvironment::EntityPackedPosition(v2);
  v9 = CAITaskForce::CmdGoal(this);
  v8 = CAITaskForce::OwnerId(this) | 0xA0;
  if ( !CAStarTiling::FindPath(v9, v7, (struct CWaypoints *)v16, v8) )
    return 0;
  if ( CWaypoints::CachedWaypointsCount((pairNode *)v16) <= 0 )
    return 0;
  v13 = 0;
  v11 = (struct _iobuf *)v9;
  v3 = CAITaskForce::OwnerId(this);
  v6 = IAIEnvironment::AlliancesPlayerEnemyBits(v3);
  v15 = 0;
  while ( CWaypoints::CachedWaypointsCount((pairNode *)v16) > 0 )
  {
    v12 = (struct _iobuf *)CWaypoints::Back(v16, v5);
    CWaypoints::PopBack(v16);
    v13 += IAIEnvironment::GridDistancePackedXY(v11, v12);
    v11 = v12;
    IAIEnvironment::WorldOwnerIdPackedXY(v12);
    v5 = IAIEnvironment::AlliancesPlayerBit(v4);
    if ( (v5 & v6) == 0 )
    {
      if ( v15 )
      {
        if ( v13 > 45 )
          break;
      }
      else
      {
        v15 = 1;
      }
    }
  }
  if ( v13 <= 0 )
    return 0;
  (*(void (__thiscall **)(CAITaskForceEx *, struct _iobuf *))(*(_DWORD *)this + 44))(this, v11);
  return 1;
}


// address=[0x132b0f0]
// Decompiled from int __thiscall CAITaskForceEx::Load(CAITaskForceEx *this, struct IS4Chunk *a2)
void  CAITaskForceEx::Load(class IS4Chunk &) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516371456);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1, 1);
  CAITaskForce::Load(this, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516371454);
  *((_DWORD *)this + 20) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 12, 12);
  (**(void (__thiscall ***)(struct IS4Chunk *, char *, int))a2)(a2, (char *)this + 84, 12);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516371455);
}


// address=[0x132b190]
// Decompiled from int __thiscall CAITaskForceEx::Save(CAITaskForceEx *this, struct IS4Chunk *a2)
void  CAITaskForceEx::Save(class IS4Chunk &) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516371456);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 1);
  CAITaskForce::Save(this, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516371454);
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 20));
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 12);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 84, 12);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516371455);
}


// address=[0x132e950]
// Decompiled from int __thiscall CAITaskForceEx::DestinationX(CAITaskForceEx *this)
int  CAITaskForceEx::DestinationX(void)const {
  
  return IAIEnvironment::UnpackXFast(*((_DWORD *)this + 20));
}


// address=[0x132e970]
// Decompiled from int __thiscall CAITaskForceEx::DestinationXY(CAITaskForceEx *this)
int  CAITaskForceEx::DestinationXY(void)const {
  
  return *((_DWORD *)this + 20);
}


// address=[0x132e990]
// Decompiled from int __thiscall CAITaskForceEx::DestinationY(CAITaskForceEx *this)
int  CAITaskForceEx::DestinationY(void)const {
  
  return IAIEnvironment::UnpackYFast(*((_DWORD *)this + 20));
}


// address=[0x132ed00]
// Decompiled from bool __thiscall CAITaskForceEx::WaypointAvailable(CAITaskForceEx *this)
bool  CAITaskForceEx::WaypointAvailable(void)const {
  
  return *((_DWORD *)this + 21) >= 0;
}


// address=[0x132ed40]
// Decompiled from int __thiscall CAITaskForceEx::WaypointX(CAITaskForceEx *this)
int  CAITaskForceEx::WaypointX(void)const {
  
  return IAIEnvironment::UnpackXFast(*((_DWORD *)this + 21));
}


// address=[0x132ed70]
// Decompiled from int __thiscall CAITaskForceEx::WaypointXY(CAITaskForceEx *this)
int  CAITaskForceEx::WaypointXY(void)const {
  
  return *((_DWORD *)this + 21);
}


// address=[0x132ed90]
// Decompiled from int __thiscall CAITaskForceEx::WaypointY(CAITaskForceEx *this)
int  CAITaskForceEx::WaypointY(void)const {
  
  return IAIEnvironment::UnpackYFast(*((_DWORD *)this + 21));
}


// address=[0x13192a0]
// Decompiled from void __thiscall CAITaskForceEx::~CAITaskForceEx(CAITaskForceEx *this)
 CAITaskForceEx::~CAITaskForceEx(void) {
  
  *(_DWORD *)this = CAITaskForceEx::_vftable_;
  CAITaskForce::~CAITaskForce(this);
}


// address=[0x132a140]
// Decompiled from _DWORD *__thiscall CAITaskForceEx::CAITaskForceEx(_DWORD *this, int a2, int a3, int a4, int a5)
 CAITaskForceEx::CAITaskForceEx(int,enum T_AI_TASK_FORCE_CLASS,enum T_AI_TASK_FORCE_TYPE,int) {
  
  CAITaskForce::CAITaskForce((int)this, a2, a3, a4, a5);
  *this = CAITaskForceEx::_vftable_;
  return this;
}


// address=[0x132b230]
// Decompiled from char __thiscall CAITaskForceEx::EscortInitWalk(CAITaskForceEx *this)
bool  CAITaskForceEx::EscortInitWalk(void) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp+0h] [ebp-2Ch]
  struct _Cnd_internal_imp_t *v8; // [esp+4h] [ebp-28h] BYREF
  struct _Mtx_internal_imp_t *v9; // [esp+8h] [ebp-24h] BYREF
  int v10; // [esp+Ch] [ebp-20h]
  struct _Cnd_internal_imp_t *v11; // [esp+10h] [ebp-1Ch]
  struct _Mtx_internal_imp_t *v12; // [esp+14h] [ebp-18h]
  int v13; // [esp+18h] [ebp-14h]
  CAITaskForce *v14; // [esp+1Ch] [ebp-10h]
  struct _Cnd_internal_imp_t *v15; // [esp+20h] [ebp-Ch] BYREF
  struct _Mtx_internal_imp_t *v16; // [esp+24h] [ebp-8h] BYREF
  CUserToolsManager *v17; // [esp+28h] [ebp-4h]

  v17 = this;
  v14 = (CAITaskForce *)CAITaskForce::AssociatedTaskForce(this);
  if ( !v14 )
  {
    (*(void (__thiscall **)(CUserToolsManager *, int))(*(_DWORD *)v17 + 44))(v17, -1);
    return 0;
  }
  if ( !CAITaskForce::GetPositionOfFirstEntity(v14, (int *)&v15, (int *)&v16) )
  {
    (*(void (__thiscall **)(CUserToolsManager *, int))(*(_DWORD *)v17 + 44))(v17, -1);
    return 0;
  }
  if ( !CAITaskForce::GetPositionOfFirstEntity(v17, (int *)&v8, (int *)&v9)
    || (v13 = IAIEnvironment::WorldSectorId((int)v8, (int)v9),
        v2 = IAIEnvironment::WorldSectorId((int)v15, (int)v16),
        v2 != v13) )
  {
    (*(void (__thiscall **)(CUserToolsManager *, int))(*(_DWORD *)v17 + 44))(v17, -1);
    return 0;
  }
  if ( (CAITaskForce::Flags(v17) & 0x8000000) != 0 )
  {
    CAITaskForce::ClearInternalFlagBit(v17, 0x8000000u);
    (*(void (__thiscall **)(CUserToolsManager *, int))(*(_DWORD *)v17 + 44))(v17, -1);
  }
  if ( (int)CAITaskForceEx::DestinationXY(v17) <= 0 )
    goto LABEL_17;
  v11 = (struct _Cnd_internal_imp_t *)CAITaskForceEx::DestinationX(v17);
  v12 = (struct _Mtx_internal_imp_t *)CAITaskForceEx::DestinationY(v17);
  v3 = IAIEnvironment::WorldSectorId((int)v11, (int)v12);
  if ( v3 != v13 )
    goto LABEL_17;
  v10 = IAIEnvironment::GridDistance(v15 - v11, v16 - v12);
  if ( v10 <= 6 )
    return 1;
  if ( v10 <= 12 )
  {
    v4 = CAITaskForce::OwnerId(v17);
    v7 = IAIEnvironment::AlliancesAllianceId(v4);
    if ( !CInfluMap::EnemyValueXY(v15, v16, v7) )
      return 1;
  }
LABEL_17:
  v5 = IAIEnvironment::PackXYFast(v15, v16);
  (*(void (__thiscall **)(CUserToolsManager *, int))(*(_DWORD *)v17 + 44))(v17, v5);
  v6 = CAITaskForceEx::DestinationXY(v17);
  *((_DWORD *)v17 + 21) = v6;
  CAITaskForceEx::InitWalk(v17, 1);
  return 1;
}


// address=[0x132eac0]
// Decompiled from int __thiscall CAITaskForceEx::SetCommandAndClearStuff(CAITaskForceEx *this, unsigned int a2, int a3, int a4)
void  CAITaskForceEx::SetCommandAndClearStuff(int,int,int) {
  
  CAITaskForce::SetCommand(this, a2, a3, a4);
  (*(void (__thiscall **)(CAITaskForceEx *, int))(*(_DWORD *)this + 44))(this, -1);
  CAITaskForce::SetNewStatusAndState(this, 1, 0, 0);
  return CAITaskForce::SetWaitCounter(this, 0);
}


