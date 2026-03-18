#if FALSE
#include "CAITaskForceEx.h"

// Definitions for class CAITaskForceEx

// address=[0x132a540]
// Decompiled from void __thiscall CAITaskForceEx::ClearWaypoints(CAITaskForceEx *this)
void  CAITaskForceEx::ClearWaypoints(void) {
  
  this->m_iWaypointsXY[0] = -1;
  this->m_iWaypointsXY[1] = -1;
  this->m_iWaypointsXY[2] = -1;
}


// address=[0x132a590]
// Decompiled from void __thiscall CAITaskForceEx::PopWaypoint(CAITaskForceEx *this)
void  CAITaskForceEx::PopWaypoint(void) {
  
  this->m_iWaypointsXY[0] = this->m_iWaypointsXY[1];
  this->m_iWaypointsXY[1] = this->m_iWaypointsXY[2];
  this->m_iWaypointsXY[2] = -1;
}


// address=[0x132a600]
// Decompiled from bool __thiscall CAITaskForceEx::CheckWaypoint(CAITaskForceEx *this)
bool  CAITaskForceEx::CheckWaypoint(void) {
  
  int iX; // [esp+4h] [ebp-20h]
  int iY; // [esp+8h] [ebp-1Ch]
  int iSectorId; // [esp+Ch] [ebp-18h]
  int a1; // [esp+10h] [ebp-14h] BYREF
  int a2; // [esp+14h] [ebp-10h] BYREF
  int uWaypoint; // [esp+1Ch] [ebp-8h]

  uWaypoint = CAITaskForceEx::WaypointXY(this);
  if ( uWaypoint <= 0 )
    return 0;
  iX = IAIEnvironment::UnpackXFast(uWaypoint);
  iY = IAIEnvironment::UnpackYFast(uWaypoint);
  iSectorId = IAIEnvironment::WorldSectorId(iX, iY);
  if ( iSectorId <= 0 )
    return 0;
  a1 = 0;
  a2 = 0;
  return CAITaskForce::GetPositionOfFirstEntity(this, &a1, &a2) && iSectorId == IAIEnvironment::WorldSectorId(a1, a2);
}


// address=[0x132a6c0]
// Decompiled from char __thiscall CAITaskForceEx::CheckDestination(CAITaskForceEx *this)
bool  CAITaskForceEx::CheckDestination(void) {
  
  int v1; // eax
  int iDestXY; // eax MAPDST
  int v4; // eax
  int v6; // eax
  int iDestX; // [esp+0h] [ebp-1Ch] BYREF
  int v8; // [esp+4h] [ebp-18h] BYREF
  BOOL v9; // [esp+8h] [ebp-14h]
  BOOL v10; // [esp+Ch] [ebp-10h]
  int NearestNoneBlockedPosition; // [esp+10h] [ebp-Ch]

  if ( (CAITaskForce::Flags(this) & 0x2000) == 0 )
    return 1;
  if ( this->m_iDestinationXY < 0 )
    this->m_iDestinationXY = CAITaskForce::CmdGoal(this);
  if ( this->m_iDestinationXY < 0 )
    return 0;
  if ( !IAIEnvironment::WorldInWorldPackedXY(this->m_iDestinationXY)
    && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 501, "g_pAIEnv->WorldInWorldPackedXY(m_iDestinationXY)") == 1 )
  {
    __debugbreak();
  }
  if ( !IAIEnvironment::WorldIsBlockedLandPackedXY(this->m_iDestinationXY) )
    return 1;
  v1 = CAITaskForce::CmdGoal(this);
  if ( !IAIEnvironment::WorldInWorldPackedXY(v1)
    && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 507, "g_pAIEnv->WorldInWorldPackedXY(CmdGoal())") == 1 )
  {
    __debugbreak();
  }
  LOWORD(iDestXY) = CAITaskForce::CmdGoal(this);
  iDestX = IAIEnvironment::UnpackXFast(iDestXY);
  iDestXY = CAITaskForce::CmdGoal(this);
  v8 = IAIEnvironment::UnpackYFast(iDestXY);
  NearestNoneBlockedPosition = IAIEnvironment::GetNearestNoneBlockedPosition(&iDestX, &v8);
  v10 = NearestNoneBlockedPosition >= 0;
  v9 = NearestNoneBlockedPosition < 16;
  if ( v9 && v10 )                              // aka, position is blocked -> set new position
  {
    v4 = IAIEnvironment::PackXYFast(iDestX, v8);
    this->m_iDestinationXY = v4;
    return 1;
  }
  else
  {
    v6 = CAITaskForce::CmdGoal(this);
    this->m_iDestinationXY = v6;
    return 0;
  }
}


// address=[0x132a840]
// Decompiled from char __thiscall CAITaskForceEx::FindWaypoints(CAITaskForceEx *this)
bool  CAITaskForceEx::FindWaypoints(void) {
  
  int v2; // eax
  int iDestXY; // eax
  __int16 iOwner; // [esp-4h] [ebp-80h]
  int v5; // [esp+0h] [ebp-7Ch]
  int iXY; // [esp+4h] [ebp-78h]
  struct CAIEntityInfo *Entity; // [esp+14h] [ebp-68h]
  int i; // [esp+18h] [ebp-64h]
  CWaypoints v10; // [esp+20h] [ebp-5Ch] BYREF

  CAITaskForceEx::ClearWaypoints(this);
  if ( !CAITaskForceEx::CheckDestination(this) )
    return 0;
  Entity = CAITaskForce::FirstEntity(this);
  if ( !Entity )
    return 0;
  v2 = CAIEntityInfo::EntityId(Entity);
  iXY = IAIEnvironment::EntityPackedPosition(v2);
  iOwner = CAITaskForce::OwnerId(this) | 0x80;
  iDestXY = CAITaskForceEx::DestinationXY(this);
  if ( !CAStarTiling::FindPath(iXY, iDestXY, &v10, iOwner) )
    return 0;
  for ( i = 0; ((i < 3) & (CWaypoints::CachedWaypointsCount(&v10) > 0)) != 0; ++i )
  {
    v5 = CWaypoints::Back(&v10);
    CWaypoints::PopBack(&v10);
    this->m_iWaypointsXY[i] = v5;
  }
  if ( this->m_iWaypointsXY[0] < 0
    && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 590, "m_iWaypointsXY[0] >= 0") == 1 )
  {
    __debugbreak();
  }
  return 1;
}


// address=[0x132a990]
// Decompiled from char __thiscall CAITaskForceEx::SetDestinationXY(CAITaskForceEx *this, int a2)
bool  CAITaskForceEx::SetDestinationXY(int a2) {
  
  this->m_iDestinationXY = a2;
  CAITaskForceEx::ClearWaypoints(this);
  return 1;
}


// address=[0x132a9b0]
// Decompiled from void __thiscall CAITaskForceEx::Execute(CAITaskForceEx *this)
void  CAITaskForceEx::Execute(void) {
  
  DWORD v1; // esi
  int v2; // eax
  int v3; // eax
  int v4; // [esp+Ch] [ebp-28h]
  int v5; // [esp+14h] [ebp-20h]
  int v6; // [esp+18h] [ebp-1Ch]
  int v7; // [esp+20h] [ebp-14h]
  CAIEntityInfo *i; // [esp+24h] [ebp-10h]
  CAIEntityInfo *Entity; // [esp+28h] [ebp-Ch]
  char Waypoints; // [esp+33h] [ebp-1h]

  CAITaskForce::SetWaitCounter(this, 8u);
  switch ( CAITaskForce::State(this) )
  {
    case 0:
      CAITaskForce::SetStatus(this, 1);
      return;
    case 100:
      goto LABEL_2;
    case 101:
      if ( (CAITaskForce::Flags(this) & 0x10000) != 0 )
      {
        v5 = CAITaskForce::NumberOfEntities(this) / 2;
        v6 = 128;
      }
      else
      {
        v5 = 0;
        v6 = 3;
      }
      v7 = 0;
      Entity = CAITaskForce::FirstEntity(this);
      break;
    case 102:
      CAITaskForceEx::FindWaypoints(this);
      CAITaskForceEx::InitGroupWalk(this);
      CAITaskForce::SetWaitCounter(this, 0x20u);
      CAITaskForce::SetState(this, 101);
      CAITaskForce::ClearStateFlagBit(this, 0x10000u);
      return;
    case 104:
      if ( !CAITaskForce::GoalIsEntity(this)
        && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 860, "GoalIsEntity()") == 1 )
      {
        __debugbreak();
      }
      v2 = CAITaskForce::CmdGoal(this);
      if ( (IAIEnvironment::EntityFlags(v2) & 0x2000000) == 0 )
        goto LABEL_34;
      for ( i = CAITaskForce::FirstEntity(this); i; i = CAIEntityInfo::Next(i) )
        CAIEntityInfo::EntityId(i);
      return;
    case 105:
      if ( !CAITaskForce::GoalIsEntity(this)
        && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 887, "GoalIsEntity()") == 1 )
      {
        __debugbreak();
      }
      v3 = CAITaskForce::CmdGoal(this);
      if ( (IAIEnvironment::EntityFlags(v3) & 0x2000000) != 0 )
        return;
      goto LABEL_34;
    case 106:
      if ( !CAITaskForceEx::EscortInitWalk(this) )
LABEL_34:
        CAITaskForce::SetState(this, 0);
      return;
    default:
      return;
  }
  while ( Entity )
  {
    v4 = CAIEntityInfo::EntityId(Entity);
    if ( IAIEnvironment::MovingEntityWalkingState(v4) >= v6 && ++v7 >= v5 )
      return;
    Entity = CAIEntityInfo::Next(Entity);
  }
  CAITaskForce::SetStateFlagBit(this, 0x10000u);
  v1 = CAITaskForceEx::WaypointXY(this);
  if ( v1 == CAITaskForceEx::DestinationXY(this) )
  {
    CAITaskForceEx::ClearWaypoints(this);
    CAITaskForce::ActivateNextState(this);
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
      CAITaskForce::SetWaitCounter(this, 0x20u);
    }
    else
    {
LABEL_2:
      CAITaskForce::ActivateNextState(this);
    }
  }
}


// address=[0x132ace0]
// Decompiled from void __thiscall CAITaskForceEx::InitWalk(CAITaskForceEx *this, bool a2)
void  CAITaskForceEx::InitWalk(bool a2) {
  
  bool i; // al
  int v3; // [esp+0h] [ebp-2Ch]
  int v4; // [esp+4h] [ebp-28h]
  int v5; // [esp+8h] [ebp-24h]
  int iSectorId; // [esp+Ch] [ebp-20h]
  unsigned int v7; // [esp+10h] [ebp-1Ch]
  unsigned int v8; // [esp+14h] [ebp-18h]
  CAIEntityInfo *Entity; // [esp+1Ch] [ebp-10h]
  int iY0; // [esp+20h] [ebp-Ch]
  int iX0; // [esp+24h] [ebp-8h]
  int v13; // [esp+28h] [ebp-4h]

  Entity = CAITaskForce::FirstEntity(this);
  if ( Entity && (int)CAITaskForceEx::WaypointXY(this) > 0 )
  {
    iX0 = CAITaskForceEx::WaypointX(this);
    iY0 = CAITaskForceEx::WaypointY(this);
    if ( !IAIEnvironment::WorldInWorld(iX0, iY0)
      && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 631, "g_pAIEnv->WorldInWorld(iX0, iY0)") == 1 )
    {
      __debugbreak();
    }
    if ( IAIEnvironment::WorldIsBlockedLand(iX0, iY0)
      && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 632, "!g_pAIEnv->WorldIsBlockedLand(iX0, iY0)") == 1 )
    {
      __debugbreak();
    }
    iSectorId = IAIEnvironment::WorldSectorId(iX0, iY0);
    if ( iSectorId <= 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 636, "iSectorId > 0") == 1 )
      __debugbreak();
    v13 = 0;
    while ( Entity )
    {
      v7 = iX0 + 2 * SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * v13]);
      v8 = iY0 + 2 * SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * v13]);
      for ( i = IAIEnvironment::WorldInWorld(v7, v8);
            !i || IAIEnvironment::WorldSectorId(v7, v8) != iSectorId;
            i = IAIEnvironment::WorldInWorld(v7, v8) )
      {
        if ( v13 < 37 )
          v5 = v13 + 1;
        else
          v5 = 0;
        v13 = v5;
        v7 = iX0 + 2 * SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * v5]);
        v8 = iY0 + 2 * SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * v5]);
      }
      if ( v13 < 37 )
        v4 = v13 + 1;
      else
        v4 = 0;
      v13 = v4;
      v3 = CAIEntityInfo::EntityId(Entity);
      IAIEnvironment::MovingEntitySendMoveCommand(v3, v7, v8, a2);
      Entity = CAIEntityInfo::Next(Entity);
    }
  }
}


// address=[0x132aef0]
// Decompiled from void __thiscall CAITaskForceEx::InitGroupWalk(CAITaskForceEx *this)
void  CAITaskForceEx::InitGroupWalk(void) {
  
  bool v2; // [esp+7h] [ebp-1h]

  v2 = CAITaskForce::Class(this) != 6;
  CAITaskForceEx::InitWalk(this, v2);
}


// address=[0x132af30]
// Decompiled from char __thiscall CAITaskForceEx::FindSneakUpPosition(CAITaskForceEx *this)
bool  CAITaskForceEx::FindSneakUpPosition(void) {
  
  int v2; // eax
  __int16 iOwnerId; // ax
  int v4; // eax
  int v5; // [esp+4h] [ebp-88h]
  char v6; // [esp+8h] [ebp-84h]
  int iXY; // [esp+Ch] [ebp-80h]
  int iDestXY; // [esp+14h] [ebp-78h] MAPDST
  CAIEntityInfo *Entity; // [esp+18h] [ebp-74h]
  int v11; // [esp+20h] [ebp-6Ch]
  int v12; // [esp+24h] [ebp-68h]
  char v14; // [esp+2Fh] [ebp-5Dh]
  struct CWaypoints v15; // [esp+30h] [ebp-5Ch] BYREF

  this->SetDestinationXY(this, -1);
  Entity = CAITaskForce::FirstEntity(this);
  if ( !Entity )
    return 0;
  if ( !CAITaskForce::GoalIsPosition(this)
    && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 281, "GoalIsPosition()") == 1 )
  {
    __debugbreak();
  }
  v2 = CAIEntityInfo::EntityId(Entity);
  iXY = IAIEnvironment::EntityPackedPosition(v2);
  iDestXY = CAITaskForce::CmdGoal(this);
  iOwnerId = CAITaskForce::OwnerId(this);
  if ( !CAStarTiling::FindPath(iDestXY, iXY, &v15, iOwnerId | 0xA0) )
    return 0;
  if ( CWaypoints::CachedWaypointsCount(&v15) <= 0 )
    return 0;
  v12 = 0;
  v4 = CAITaskForce::OwnerId(this);
  v5 = IAIEnvironment::AlliancesPlayerEnemyBits(v4);
  v14 = 0;
  while ( CWaypoints::CachedWaypointsCount(&v15) > 0 )
  {
    v11 = CWaypoints::Back(&v15);
    CWaypoints::PopBack(&v15);
    v12 += IAIEnvironment::GridDistancePackedXY(iDestXY, v11);
    iDestXY = v11;
    v6 = IAIEnvironment::WorldOwnerIdPackedXY(v11);
    if ( (IAIEnvironment::AlliancesPlayerBit(v6) & v5) == 0 )
    {
      if ( v14 )
      {
        if ( v12 > 45 )
          break;
      }
      else
      {
        v14 = 1;
      }
    }
  }
  if ( v12 <= 0 )
    return 0;
  this->SetDestinationXY(this, iDestXY);
  return 1;
}


// address=[0x132b0f0]
// Decompiled from void __thiscall CAITaskForceEx::Load(CAITaskForceEx *this, struct IS4Chunk *a2)
void  CAITaskForceEx::Load(class IS4Chunk & a2) {
  
  a2->LoadSignature(-1516371456);
  a2->LoadUnsigned32(1, 1);
  CAITaskForce::Load(this, a2);
  a2->LoadSignature(-1516371454);
  this->m_iDestinationXY = a2->LoadUnsigned32_(a2);
  a2->LoadUnsigned32(12, 12);
  a2->Load(this->m_iWaypointsXY, 12);
  a2->LoadSignature(-1516371455);
}


// address=[0x132b190]
// Decompiled from void __thiscall CAITaskForceEx::Save(CAITaskForceEx *this, struct IS4Chunk *a2)
void  CAITaskForceEx::Save(class IS4Chunk & a2) {
  
  a2->SaveSignature(-1516371456);
  a2->SaveUnsigned32(1);
  CAITaskForce::Save(this, a2);
  a2->SaveSignature(-1516371454);
  a2->SaveUnsigned32(this->m_iDestinationXY);
  a2->SaveUnsigned32(12);
  a2->Save(&this->m_iWaypointsXY, 0xCu);
  a2->SaveSignature(-1516371455);
}


// address=[0x132e950]
// Decompiled from int __thiscall CAITaskForceEx::DestinationX(CAITaskForceEx *this)
int  CAITaskForceEx::DestinationX(void)const {
  
  return IAIEnvironment::UnpackXFast(*((_DWORD *)this + 20));
}


// address=[0x132e970]
// Decompiled from int __thiscall CAITaskForceEx::DestinationXY(CAITaskForceEx *this)
int  CAITaskForceEx::DestinationXY(void)const {
  
  return this->m_iDestinationXY;
}


// address=[0x132e990]
// Decompiled from int __thiscall CAITaskForceEx::DestinationY(CAITaskForceEx *this)
int  CAITaskForceEx::DestinationY(void)const {
  
  return IAIEnvironment::UnpackYFast(this->m_iDestinationXY);
}


// address=[0x132ed00]
// Decompiled from bool __thiscall CAITaskForceEx::WaypointAvailable(CAITaskForceEx *this)
bool  CAITaskForceEx::WaypointAvailable(void)const {
  
  return this->m_iWaypointsXY >= 0;
}


// address=[0x132ed40]
// Decompiled from int __thiscall CAITaskForceEx::WaypointX(CAITaskForceEx *this)
int  CAITaskForceEx::WaypointX(void)const {
  
  return IAIEnvironment::UnpackXFast(*((_DWORD *)this + 21));
}


// address=[0x132ed70]
// Decompiled from DWORD __thiscall CAITaskForceEx::WaypointXY(CAITaskForceEx *this)
int  CAITaskForceEx::WaypointXY(void)const {
  
  return this->m_iWaypointsXY;
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
// Decompiled from CAITaskForceEx *__thiscall CAITaskForceEx::CAITaskForceEx(  CAITaskForceEx *this,  int iOwnerId,  int tClass,  int tType,  int iFlags)
 CAITaskForceEx::CAITaskForceEx(int iOwnerId, enum T_AI_TASK_FORCE_CLASS tClass, enum T_AI_TASK_FORCE_TYPE tType, int iFlags) {
  
  CAITaskForce::CAITaskForce(this, iOwnerId, tClass, tType, iFlags);
  this->__vftable = (CAITaskForceEx_vtbl *)CAITaskForceEx::_vftable_;
  return this;
}


// address=[0x132b230]
// Decompiled from char __thiscall CAITaskForceEx::EscortInitWalk(CAITaskForceEx *this)
bool  CAITaskForceEx::EscortInitWalk(void) {
  
  int iAssociatedSectorId; // eax
  int v3; // eax
  int iDestOwnerId; // eax
  int iXYAssociated; // eax
  int v6; // eax
  int iDestOwnerAllianceId; // [esp+0h] [ebp-2Ch]
  int iX; // [esp+4h] [ebp-28h] BYREF
  int iY; // [esp+8h] [ebp-24h] BYREF
  int v10; // [esp+Ch] [ebp-20h]
  int iDestX; // [esp+10h] [ebp-1Ch]
  int iDestY; // [esp+14h] [ebp-18h]
  int iThisSectorId; // [esp+18h] [ebp-14h]
  CAITaskForce *pAssociatedTaskForce; // [esp+1Ch] [ebp-10h]
  int iXAssociated; // [esp+20h] [ebp-Ch] BYREF
  int iYAssociated; // [esp+24h] [ebp-8h] BYREF

  pAssociatedTaskForce = CAITaskForce::AssociatedTaskForce(this);
  if ( !pAssociatedTaskForce )
  {
    this->SetDestinationXY(this, -1);
    return 0;
  }
  if ( !CAITaskForce::GetPositionOfFirstEntity(pAssociatedTaskForce, &iXAssociated, &iYAssociated) )
  {
    this->SetDestinationXY(this, -1);
    return 0;
  }
  if ( !CAITaskForce::GetPositionOfFirstEntity(this, &iX, &iY)
    || (iThisSectorId = IAIEnvironment::WorldSectorId(iX, iY),
        iAssociatedSectorId = IAIEnvironment::WorldSectorId(iXAssociated, iYAssociated),
        iAssociatedSectorId != iThisSectorId) )
  {
    this->SetDestinationXY(this, -1);
    return 0;
  }
  if ( (CAITaskForce::Flags(this) & 0x8000000) != 0 )
  {
    CAITaskForce::ClearInternalFlagBit(this, 0x8000000u);
    this->SetDestinationXY(this, -1);
  }
  if ( CAITaskForceEx::DestinationXY(this) <= 0 )
    goto LABEL_17;
  iDestX = CAITaskForceEx::DestinationX(this);
  iDestY = CAITaskForceEx::DestinationY(this);
  v3 = IAIEnvironment::WorldSectorId(iDestX, iDestY);
  if ( v3 != iThisSectorId )
    goto LABEL_17;
  v10 = IAIEnvironment::GridDistance(iXAssociated - iDestX, iYAssociated - iDestY);
  if ( v10 <= 6 )
    return 1;
  if ( v10 <= 12 )
  {
    iDestOwnerId = CAITaskForce::OwnerId(this);
    iDestOwnerAllianceId = IAIEnvironment::AlliancesAllianceId(iDestOwnerId);
    if ( !CInfluMap::EnemyValueXY(iXAssociated, iYAssociated, iDestOwnerAllianceId) )
      return 1;
  }
LABEL_17:
  iXYAssociated = IAIEnvironment::PackXYFast(iXAssociated, iYAssociated);
  this->SetDestinationXY(this, iXYAssociated);
  v6 = CAITaskForceEx::DestinationXY(this);
  this->m_iWaypointsXY = v6;
  CAITaskForceEx::InitWalk(this, 1);
  return 1;
}


// address=[0x132eac0]
// Decompiled from void __thiscall CAITaskForceEx::SetCommandAndClearStuff(CAITaskForceEx *this, unsigned int a2, int a3, int a4)
void  CAITaskForceEx::SetCommandAndClearStuff(int a2, int a3, int a4) {
  
  CAITaskForce::SetCommand(this, a2, a3, a4);
  this->SetDestinationXY(this, -1);
  CAITaskForce::SetNewStatusAndState(this, 1, 0, 0);
  CAITaskForce::SetWaitCounter(this, 0);
}


#endif // Already implemented
