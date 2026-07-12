#include "CVehicle.h"

// Definitions for class CVehicle

// address=[0x1351ab0]
// Decompiled from int __thiscall CVehicle::CurrentTask(CVehicle *this)
int  CVehicle::CurrentTask(void)const {
  
  return this->m_uCurrentTask;
}


// address=[0x153a430]
// Decompiled from void __thiscall CVehicle::CountCargo(CVehicle *this, struct ICargoCounter *a2)
void  CVehicle::CountCargo(class ICargoCounter & a2) {
  
  ;
}


// address=[0x153fda0]
// Decompiled from int __thiscall CVehicle::DeleteSelectable(CVehicle *this)
void  CVehicle::DeleteSelectable(void) {
  
  return IEntity::ClearFlagBits(this, EntityFlag_Selectable);
}


// address=[0x153fe70]
// Decompiled from _DWORD *__thiscall CVehicle::SetSelectable(CVehicle *this)
void  CVehicle::SetSelectable(void) {
  
  return IEntity::SetFlagBits(this, EntityFlag_Selectable);
}


// address=[0x159e900]
// Decompiled from int __thiscall CVehicle::GetMeetingPointXY(IEntity *this, int a2, int a3)
int const  CVehicle::GetMeetingPointXY(enum OBJ_TYPE a2, int a3) {
  
  return IEntity::PackedXY(this);
}


// address=[0x15a3c70]
// Decompiled from int __thiscall CVehicle::Loading(CVehicle *this)
int  CVehicle::Loading(void)const {
  
  return 1;
}


// address=[0x15a3c80]
// Decompiled from void __thiscall CVehicle::PostLoadInit(CVehicle *this)
void  CVehicle::PostLoadInit(void) {
  
  unsigned int v1; // eax
  int v2; // eax
  unsigned int m_nType; // [esp-4h] [ebp-8h]

  IEntity::PostLoadInit();
  m_nType = this->m_nType;
  v1 = IEntity::Race(this);
  this->m_pVehicleProperties = IVehicleInfoMgr::VehicleProperties(v1, m_nType);
  this->AddToWarMap(this);
  if ( IEntity::ObjType(this) == SHIP_OBJ )
  {
    v2 = IEntity::PackedXY(this);
    CWater::PlaceShip(v2);
  }
}


// address=[0x15a3ce0]
// Decompiled from void __thiscall CVehicle::AddToWarMap(IEntity *this)
void  CVehicle::AddToWarMap(void) {
  
  if ( IEntity::FlagBits(this, EntityFlag_Ready) )
    CWarMap::AddEntity(this);
}


// address=[0x15a3d10]
// Decompiled from void __thiscall CVehicle::GoodIsComming(CVehicle *this, int a2, int a3)
void  CVehicle::GoodIsComming(int a2, int a3) {
  
  ;
}


// address=[0x15a3d20]
// Decompiled from void __thiscall CVehicle::EntityOrderCanceled(CVehicle *this, int a2)
void  CVehicle::EntityOrderCanceled(int a2) {
  
  ;
}


// address=[0x15a3d30]
// Decompiled from void __thiscall CVehicle::EntityEnter(CVehicle *this, int a2)
void  CVehicle::EntityEnter(int a2) {
  
  ;
}


// address=[0x15a3d40]
// Decompiled from void __thiscall CVehicle::GoodArrived(CVehicle *this, int a2, int a3)
void  CVehicle::GoodArrived(int a2, int a3) {
  
  ;
}


// address=[0x15a3d50]
// Decompiled from void __thiscall CVehicle::SupplyCanceled(CVehicle *this, int a2, int a3)
void  CVehicle::SupplyCanceled(int a2, int a3) {
  
  ;
}


// address=[0x15a3d60]
// Decompiled from void __thiscall CVehicle::Delete(CVehicle *this)
void  CVehicle::Delete(void) {
  
  int v1; // eax
  unsigned int LastLogicUpdateTick; // eax
  int v3; // eax
  int v4; // eax
  int v5; // [esp-8h] [ebp-3Ch]
  int v6; // [esp-8h] [ebp-3Ch]
  int v7; // [esp-4h] [ebp-38h]
  CEntityEvent v8; // [esp+4h] [ebp-30h] BYREF
  const struct CEntityEvent *v9; // [esp+1Ch] [ebp-18h]
  const struct CEntityEvent *v10; // [esp+20h] [ebp-14h]
  int v12; // [esp+30h] [ebp-4h]

  CWarMap::RemoveEntity(this);
  if ( this->m_uPackedXY > 0 )
  {
    this->RemoveVehicle(this, this->m_uPackedXY);
    this->m_uPackedXY = 0;
  }
  v5 = IAnimatedEntity::AttackerPlayerId();
  v1 = IEntity::EntityId(this);
  v10 = CEntityEvent::CEntityEvent(&v8, 9u, 0, v1, v5, 0);
  v9 = v10;
  v12 = 0;
  CObserverList::NotifyAndDetachAllObservers((CObserverList *)&this[1].m_iFrame, v10);
  v12 = -1;
  CEntityEvent::~CEntityEvent(&v8);
  v7 = IEntity::ID(this);
  LastLogicUpdateTick = IAnimatedEntity::GetLastLogicUpdateTick(this);
  CMapObjectMgr::UnRegisterFromLogicUpdate(g_pMapObjectMgr, LastLogicUpdateTick, v7);
  v3 = IEntity::ID(this);
  CVehicleMgr::CheckOutVehicle((CVehicleMgr *)&g_cVehicleMgr, v3);
  v6 = IEntity::ID(this);
  v4 = IEntity::OwnerId(this);
  g_pAI->PostAIEvent(g_pAI, 23, v4, v6, 0);
}


// address=[0x15a3e80]
// Decompiled from void __thiscall CVehicle::FireMissile(CVehicle *this, int _iTargetId, int _iDestinationXY)
void  CVehicle::FireMissile(int _iTargetId, int _iDestinationXY) {
  
  int iXY; // eax MAPDST
  int iDstX2; // eax
  int iX; // eax
  int iIdx; // eax
  int iDstX; // [esp-10h] [ebp-50h]
  int iY; // [esp-10h] [ebp-50h]
  IEntity *rEntity; // [esp+0h] [ebp-40h]
  int iAlliance; // [esp+Ch] [ebp-34h]
  int iTileOwner; // [esp+10h] [ebp-30h]
  struct IFutureEvents *rFutureEvents; // [esp+14h] [ebp-2Ch]
  int iStrength; // [esp+1Ch] [ebp-24h]
  struct IEffects *pEffects; // [esp+28h] [ebp-18h] MAPDST
  int iOwner; // [esp+30h] [ebp-10h] MAPDST
  int iFireAnimationEnd; // [esp+34h] [ebp-Ch]
  int m_uDamage; // [esp+38h] [ebp-8h]
  int uDamage; // [esp+38h] [ebp-8h]

  if ( _iTargetId <= 0 && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 778, "_iTargetId > 0") == 1 )
    __debugbreak();
  if ( !CWorldManager::InWorldPackedXY(_iDestinationXY)
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 779, "g_cWorld.InWorldPackedXY( _iDestinationXY )") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::Race(this) == 1 )
  {
    if ( IEntity::Type(this) == CATAPULT_OBJ )
    {
      pEffects = CLogic::Effects(g_pLogic);
      iDstX = Y16X16::UnpackXFast(_iDestinationXY);
      iDstX2 = Y16X16::UnpackXFast(_iDestinationXY);// HUH?
      iFireAnimationEnd = pEffects->AddEffect(
                            pEffects,
                            EFFECT_VMAGIC_THORSHAMMER,
                            SOUND_NO_SOUND,
                            iDstX2,
                            iDstX,
                            1,
                            0,
                            1);
    }
    else
    {
      pEffects = CLogic::Effects(g_pLogic);
      iXY = IEntity::PackedXY(this);
      iFireAnimationEnd = pEffects->AddMissile(
                            pEffects,
                            this->m_pVehicleProperties->m_tMissileType,
                            iXY,
                            _iDestinationXY,
                            1,
                            0,
                            0);
    }
  }
  else
  {
    pEffects = CLogic::Effects(g_pLogic);
    iXY = IEntity::PackedXY(this);
    iFireAnimationEnd = pEffects->AddMissile(
                          pEffects,
                          this->m_pVehicleProperties->m_tMissileType,
                          iXY,
                          _iDestinationXY,
                          1,
                          0,
                          0);
  }
  if ( this->m_pVehicleProperties->m_iMissileFlightEffectId )
  {
    pEffects = CLogic::Effects(g_pLogic);
    iY = Y16X16::UnpackYFast(_iDestinationXY);
    iX = Y16X16::UnpackXFast(_iDestinationXY);
    pEffects->AddEffect(
      pEffects,
      this->m_pVehicleProperties->m_iMissileFlightEffectId,
      this->m_pVehicleProperties->m_tMissileFlightEffectSoundId,
      iX,
      iY,
      iFireAnimationEnd + 1,
      0,
      1);
  }
  rEntity = CMapObjectMgr::Entity(_iTargetId);
  m_uDamage = this->m_pVehicleProperties->m_uDamage;
  iOwner = IEntity::OwnerId(this);
  iXY = IEntity::PackedXY(this);
  iIdx = CWorldManager::Index(iXY);
  iTileOwner = ITiling::OwnerId(iIdx);
  iAlliance = CAlliances::AllianceId(iOwner);
  if ( iAlliance == CAlliances::AllianceId(iTileOwner) )
    iStrength = CStatistic::DefenceStrength256((CStatistic *)&g_cStatistic, iOwner);
  else
    iStrength = CStatistic::OffenceStrength256((CStatistic *)&g_cStatistic, iOwner);
  uDamage = ((iStrength * m_uDamage + 127) >> 8 == 0) + ((iStrength * m_uDamage + 127) >> 8);
  if ( IEntity::FlagBits(rEntity, EntityFlag_Ready) )
  {
    rFutureEvents = CLogic::FutureEvents(g_pLogic);
    iOwner = IEntity::OwnerId(this);
    (*(void (__thiscall **)(struct IFutureEvents *, int, int, int, int, int))(*(_DWORD *)rFutureEvents + 12))(
      rFutureEvents,
      2,
      iFireAnimationEnd + 1,
      _iTargetId,
      uDamage,
      iOwner);
  }
}


// address=[0x15a4130]
// Decompiled from void __thiscall CVehicle::Update(CVehicle *this)
void  CVehicle::Update(void) {
  
  unsigned int m_uWalkSteps; // [esp+4h] [ebp-14h]
  DWORD TickCounter; // [esp+8h] [ebp-10h]
  unsigned __int8 m_uCurrentTask; // [esp+Ch] [ebp-Ch]
  unsigned int uTick; // [esp+10h] [ebp-8h]

  TickCounter = CStateGame::GetTickCounter(g_pGame);
  uTick = TickCounter - this->m_uLastUpdateTick;
  if ( !uTick )
    return;
  this->m_uLastUpdateTick = TickCounter;
  if ( (unsigned __int8)CVehicle::IsTurning(this) )
  {
    uTick = CVehicle::TurnVehicle(this, uTick);
    if ( !uTick )
      return;
  }
  m_uCurrentTask = this->m_uCurrentTask;
  if ( m_uCurrentTask == 6 )
    goto LABEL_7;
  if ( m_uCurrentTask != 16 )
  {
    if ( m_uCurrentTask != 17 )
      return;
LABEL_7:
    if ( !CVehicle::IsMoving(this) )
      return;
    if ( !this->m_uCycleFrames && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 893, "m_uCycleFrames > 0") == 1 )
      __debugbreak();
    if ( (this->m_uWalkResult & 8) != 0
      && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 894, "( m_uWalkResult & WALK_RESULT_FLAG_DONT_MOVE ) == 0") == 1 )
    {
      __debugbreak();
    }
    if ( (this->m_iFlags & 0x40000) != 0 )
    {
      this->byte6C = (uTick + this->byte6C) % (2 * (unsigned int)this->m_uCycleFrames);
      this->m_iFrame = this->byte6C / 2;
    }
    else
    {
      this->m_iFrame = (uTick + this->m_iFrame) % this->m_uCycleFrames;
    }
    if ( !this->m_iDistance )
      BBSupportTracePrintF(0, "CVehicle::Update(): m_uDistance == 0!");
    if ( !this->m_uWalkSteps && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 917, "m_uWalkSteps > 0") == 1 )
      __debugbreak();
    if ( this->m_uWalkSteps )
      m_uWalkSteps = this->m_uWalkSteps;
    else
      m_uWalkSteps = 1;
    IMovingEntity::DecDistance(this, (uTick << 8) / m_uWalkSteps);
    return;
  }
  if ( !this->m_uCycleFrames && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 927, "m_uCycleFrames > 0") == 1 )
    __debugbreak();
  this->m_iFrame = (uTick + this->m_iFrame) % this->m_uCycleFrames;
}


// address=[0x15a4340]
// Decompiled from void __thiscall CVehicle::LogicUpdate(CVehicle *this)
void  CVehicle::LogicUpdate(void) {
  
  int v1; // eax

  CVehicle::Update(this);
  if ( IEntity::FlagBits(this, EntityFlag_Birth) )
  {
    if ( this->m_uMaterialSupplied < (int)this->word7E )
    {
      IAnimatedEntity::RegisterForLogicUpdate(this, 16);
    }
    else
    {
      v1 = IEntity::ID(this);
      CTrace::Print("Vehicle %u is complete done", v1);
      this->OnBuildReady(this);
    }
  }
  else
  {
    this->m_uWalkResult = 8;
    this->m_uTurnCounter = 0;
    this->m_iDistance = 0;
    CVehicle::ClearCallTakeJob();
    IAnimatedEntity::ProcessAllEvents(this);
    if ( CVehicle::CallTakeJob() )
      this->TakeJob(this);
    else
      this->VehicleLogicUpdate(this);
  }
}


// address=[0x15a4400]
// Decompiled from void __thiscall CVehicle::VehicleLogicUpdate(CVehicle *this)
void  CVehicle::VehicleLogicUpdate(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  struct CWalking *v5; // [esp+0h] [ebp-10h]
  struct CWalking *v6; // [esp+4h] [ebp-Ch]
  unsigned __int8 m_uCurrentTask; // [esp+8h] [ebp-8h]

  m_uCurrentTask = this->m_uCurrentTask;
  if ( m_uCurrentTask == 6 )
  {
    v5 = IMovingEntity::Walking(this);
    v3 = IEntity::PackedXY(this);
    v4 = v5->Walk(v5, v3);
    CVehicle::WalkDirAndRegister(this, v4, 1);
  }
  else if ( m_uCurrentTask == 17 )
  {
    v6 = IMovingEntity::Walking(this);
    v1 = IEntity::PackedXY(this);
    v2 = v6->IdleWalk((CWalkingBase *)v6, (Y16X16 *)v1, 0);
    CVehicle::WalkDirAndRegister(this, v2, 0);
  }
  else if ( BBSupportDbgReportF(
              1,
              "MapObjects\\Vehicle.cpp",
              1485,
              "CVehicle::VehicleLogicUpdate(): Invalid task %u!",
              this->m_uCurrentTask) == 1 )
  {
    __debugbreak();
  }
}


// address=[0x15a44b0]
// Decompiled from bool __thiscall CVehicle::IsUnEmployed(CVehicle *this)
bool  CVehicle::IsUnEmployed(void)const {
  
  return (this->m_uCurrentTask == 17 || !this->m_uCurrentTask)
      && IEntity::FlagBits(this, (EntityFlag)((char *)&loc_1FFFFFF + 1));
}


// address=[0x15a4500]
// Decompiled from void __thiscall CVehicle::IncreaseAmmo(CVehicle *this, int a2)
void  CVehicle::IncreaseAmmo(int a2) {
  
  int iNewAmmo; // [esp+4h] [ebp-10h]

  if ( a2 > 0 )
  {
    if ( a2 + (unsigned int)this->m_iAmmo > this->m_pVehicleProperties->m_uMaxAmmo )
      iNewAmmo = this->m_pVehicleProperties->m_uMaxAmmo;
    else
      LOBYTE(iNewAmmo) = a2 + this->m_iAmmo;
    this->m_iAmmo = iNewAmmo;
  }
}


// address=[0x15a4560]
// Decompiled from int __thiscall CVehicle::BuildingProgress(CVehicle *this)
int  CVehicle::BuildingProgress(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  this->m_iBuildingProgress = (float)(this->word7E + this->m_uMaterialSupplied) / 100.0;
  if ( this->m_iBuildingProgress == 0.0 )
    this->m_iBuildingProgress = FLOAT_1_0;
  v2 = (int)(float)(100.0 - (float)((float)(this->word7E - this->m_uMaterialSupplied) / this->m_iBuildingProgress));
  if ( v2 > 100 )
    v2 = 100;
  if ( v2 < 0 )
    return 0;
  return v2;
}


// address=[0x15a4610]
// Decompiled from void __thiscall CVehicle::InitBuildingSite(CVehicle *this)
void  CVehicle::InitBuildingSite(void) {
  
  unsigned int v1; // eax
  BYTE *v2; // eax
  unsigned int v3; // [esp-4h] [ebp-Ch]

  IEntity::ClearFlagBits(this, EntityFlag_Ready);
  IEntity::SetFlagBits(this, EntityFlag_Birth|EntityFlag_Visible);
  this->word78 = 0;
  this->m_uBoardsNeed = 0;
  this->word7A = 0;
  this->m_uIronNeed = 0;
  this->word82 = 0;
  this->word7E = 0;
  this->m_uMaterialSupplied = 0;
  this->word84 = 0;
  this->word80 = 0;
  v3 = IEntity::Type(this);
  v1 = IEntity::Race(this);
  v2 = (BYTE *)IVehicleInfoMgr::VehicleProperties(v1, v3);
  this->word78 = *v2;
  this->m_uBoardsNeed = this->word78;
  this->word7A = v2[4];
  this->m_uIronNeed = this->word7A;
  this->word82 = 1;
  this->word7E = this->word82 * (this->word7A + this->word78);
  this->word80 = 65534 / this->word7E;
}


// address=[0x15a4730]
// Decompiled from void __thiscall CVehicle::OnBuildReady(CVehicle *this)
void  CVehicle::OnBuildReady(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // esi
  int v5; // eax
  int LocalPlayerId; // eax
  int v7; // [esp-10h] [ebp-28h]
  int v8; // [esp-Ch] [ebp-24h]
  int v9; // [esp-8h] [ebp-20h]
  int v10; // [esp-8h] [ebp-20h]
  int v11; // [esp-8h] [ebp-20h]
  int v12; // [esp-4h] [ebp-1Ch]
  int v13; // [esp-4h] [ebp-1Ch]
  int v14; // [esp-4h] [ebp-1Ch]
  int v15; // [esp+8h] [ebp-10h]
  int v16; // [esp+Ch] [ebp-Ch]
  T_S4_GUI v17; // [esp+10h] [ebp-8h]

  v15 = IEntity::OwnerId(this);
  v16 = IEntity::Type(this);
  if ( !IEntity::FlagBits(this, EntityFlag_Birth)
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 477, "FlagBits(ENTITY_FLAG_BIRTH) != 0") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::FlagBits(this, EntityFlag_Ready)
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 478, "FlagBits(ENTITY_FLAG_READY) == 0") == 1 )
  {
    __debugbreak();
  }
  v12 = IEntity::EntityId(this);
  v9 = IEntity::Type(this);
  v1 = IEntity::OwnerId(this);
  CVehicleMgr::DetachVehicle((CVehicleMgr *)&g_cVehicleMgr, v1, v9, v12);
  IEntity::ClearFlagBits(this, EntityFlag_Birth);
  if ( word_4158D1C[18 * v15 + 1 + 3 * v16] )
    --word_4158D1C[18 * v15 + 1 + 3 * v16];
  ++word_4158D1C[18 * v15 + 2 + 3 * v16];
  IEntity::SetFlagBits(this, (EntityFlag)this->m_pVehicleProperties->m_uDefaultFlags);
  IEntity::SetFlagBits(this, EntityFlag_Ready|EntityFlag_VulnerableMask|EntityFlag_Visible);
  v13 = IEntity::EntityId(this);
  v10 = IEntity::Type(this);
  v2 = IEntity::OwnerId(this);
  CVehicleMgr::AttachVehicle((CVehicleMgr *)&g_cVehicleMgr, v2, v10, v13);
  CWarMap::AddEntity(this);
  this->TakeJob(this);
  v11 = IEntity::Type(this);
  v3 = IEntity::OwnerId(this);
  CStatistic::AddProducedVehicle((CStatistic *)&g_cStatistic, v3, v11, 1);
  v4 = IEntity::OwnerId(this);
  if ( v4 == CPlayerManager::GetLocalPlayerId() )
  {
    v17 = 0;
    switch ( IEntity::Type(this) )
    {
      case 1:
        v17 = GUI_MSG_WARSHIP;
        break;
      case 2:
        v17 = GUI_MSG_FERRY;
        break;
      case 3:
        v17 = GUI_MSG_GOODSTRANSP;
        break;
      case 4:
        if ( IEntity::Race(this) )
        {
          if ( IEntity::Race(this) == 1 )
          {
            v17 = GUI_MSG_THOR;
          }
          else if ( IEntity::Race(this) == 2 )
          {
            v17 = GUI_MSG_FIRESPIT;
          }
          else if ( IEntity::Race(this) == 4 )
          {
            v17 = AO_GUI_MSG_BALIST;
          }
          else
          {
            v17 = GUI_MSG_CATAPULT;
          }
        }
        else
        {
          v17 = GUI_MSG_CATAPULT;
        }
        break;
      default:
        v14 = IEntity::Type(this);
        v5 = IEntity::Race(this);
        CTrace::Print("Workshopbuildingrole: Text message for this vehicle Race %u, Type %u not implemented", v5, v14);
        break;
    }
    if ( v17 )
    {
      v8 = IEntity::Y(this);
      v7 = IEntity::X(this);
      LocalPlayerId = CPlayerManager::GetLocalPlayerId();
      CTextMsgHandler::AddTextMsg(v17, LocalPlayerId, v7, v8, 0, 0);
    }
  }
}


// address=[0x15a4a20]
// Decompiled from char __thiscall CVehicle::NeedForBuildingMaterial(CVehicle *this, int a2)
bool  CVehicle::NeedForBuildingMaterial(int a2) {
  
  if ( a2 == GOOD_BOARD )
  {
    if ( this->m_uBoardsNeed )
      return 1;
  }
  else if ( a2 == GOOD_IRONBAR && this->m_uIronNeed )
  {
    return 1;
  }
  return 0;
}


// address=[0x15a4a70]
// Decompiled from void __thiscall CVehicle::AddBuildingMaterial(CVehicle *this, int a2)
void  CVehicle::AddBuildingMaterial(int a2) {
  
  if ( a2 == GOOD_BOARD )
  {
    if ( !this->m_uBoardsNeed && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 437, "m_uBoardsNeed > 0") == 1 )
      __debugbreak();
    --this->m_uBoardsNeed;
    ++this->m_uMaterialSupplied;
  }
  else if ( a2 == GOOD_IRONBAR )
  {
    if ( !this->m_uIronNeed && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 446, "m_uIronNeed > 0") == 1 )
      __debugbreak();
    --this->m_uIronNeed;
    ++this->m_uMaterialSupplied;
  }
}


// address=[0x15a4b30]
// Decompiled from void __thiscall CVehicle::Attach(CVehicle *this, int a2)
void  CVehicle::Attach(int a2) {
  
  void *v2; // eax

  v2 = (void *)IEntity::EntityId(this);
  CObserverList::Attach((CObserverList *)&this->m_cObserverList, v2, a2);
}


// address=[0x15a4b60]
// Decompiled from void __thiscall CVehicle::Detach(CVehicle *this, int a2)
void  CVehicle::Detach(int a2) {
  
  CVehicle::DetachWithoutNotify(this, a2);
  this->NotifyDetach(this, a2);
}


// address=[0x15a4b90]
// Decompiled from int __thiscall CVehicle::Notify(CVehicle *this, const struct CEntityEvent *a2)
void  CVehicle::Notify(class CEntityEvent const & a2)const {
  
  return CObserverList::NotifyAllObservers(&this->m_cObserverList, (int)a2);
}


// address=[0x15a4bb0]
// Decompiled from void __thiscall CVehicle::Decrease(CVehicle *this, int a2)
void  CVehicle::Decrease(int a2) {
  
  struct IEffects *v2; // eax
  int v3; // [esp+0h] [ebp-1Ch]
  int v4; // [esp+4h] [ebp-18h]
  int v5; // [esp+Ch] [ebp-10h]
  int v6; // [esp+10h] [ebp-Ch]
  int m_uArmor; // [esp+14h] [ebp-8h]

  if ( a2 > 0 )
  {
    m_uArmor = this->m_pVehicleProperties->m_uArmor;
    if ( a2 <= m_uArmor )
      v6 = 1;
    else
      v6 = a2 - m_uArmor;
    if ( v6 <= 1 )
      v5 = 1;
    else
      v5 = v6 / 2;
    v3 = IEntity::X(this);
    v4 = IEntity::Y(this);
    IEntity::Decrease(this, v5);
    if ( !this->Amount(this) )
    {
      v2 = CLogic::Effects((DWORD *)g_pLogic);
      v2->AddEffect(v2, EFFECT_DESTROYSMALL, SOUND_AMB_ATTACKSMALLBUILDING, v3, v4, 0, 0, 0);
    }
  }
}


// address=[0x15a4c80]
// Decompiled from int __thiscall CVehicle::GetGroupFlags(CVehicle *this)
int  CVehicle::GetGroupFlags(void)const {
  
  return this->m_uGroupFlags;
}


// address=[0x15a4ca0]
// Decompiled from void __thiscall CVehicle::SetGroupFlagBits(CVehicle *this, unsigned int _iFlagBits)
int  CVehicle::SetGroupFlagBits(int _iFlagBits) {
  
  if ( _iFlagBits >= 0x10000
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1568, "(_iFlagBits >= 0) && (_iFlagBits <= 0xFFFF)") == 1 )
  {
    __debugbreak();
  }
  this->m_uGroupFlags |= _iFlagBits;
}


// address=[0x15a4d00]
// Decompiled from int __thiscall CVehicle::ClearGroupFlagBits(CVehicle *this, unsigned int _iFlagBits)
int  CVehicle::ClearGroupFlagBits(int _iFlagBits) {
  
  if ( _iFlagBits >= 0x10000
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1575, "(_iFlagBits >= 0) && (_iFlagBits <= 0xFFFF)") == 1 )
  {
    __debugbreak();
  }
  this->m_uGroupFlags &= ~(_WORD)_iFlagBits;
  return this->m_uGroupFlags;
}


// address=[0x15a7a40]
// Decompiled from void __thiscall CVehicle::FillDialog(CVehicle *this, bool a2)
void  CVehicle::FillDialog(bool a2) {
  
  ;
}


// address=[0x153a460]
// Decompiled from unsigned int __thiscall CVehicle::GetCurrentTaskPtr(CVehicle *this)
class CEntityTask *  CVehicle::GetCurrentTaskPtr(void) {
  
  if ( this->m_uCurrentTaskIdx1 )
    return std::vector<CEntityTask>::operator[](&this->m_vTasks, (unsigned __int8)this->m_uCurrentTaskIdx1 - 1);
  else
    return 0;
}


// address=[0x153a530]
// Decompiled from bool __thiscall CVehicle::IsTurning(CVehicle *this)
bool  CVehicle::IsTurning(void)const {
  
  return this->m_uTurnCounter != 0;
}


// address=[0x153a620]
// Decompiled from int __thiscall CVehicle::TurnDirEx(CVehicle *this)
unsigned int  CVehicle::TurnDirEx(void)const {
  
  return this->m_uTurningDir & 0x7F;
}


// address=[0x153fe00]
// Decompiled from bool __thiscall CVehicle::ReadyToFire(CVehicle *this, DWORD a2)
bool  CVehicle::ReadyToFire(unsigned int a2)const {
  
  return a2 >= this->m_uReadyToFireTick;
}


// address=[0x153fe40]
// Decompiled from int __thiscall CVehicle::RegisterNewTask(CVehicle *this, unsigned int arg0, unsigned int a2)
void  CVehicle::RegisterNewTask(unsigned int a2, unsigned int a3) {
  
  this->m_uCurrentTask = arg0;
  return IAnimatedEntity::RegisterForLogicUpdate(this, a2);
}


// address=[0x153fe90]
// Decompiled from int __thiscall CVehicle::TurnCounter(CVehicle *this)
unsigned int  CVehicle::TurnCounter(void)const {
  
  return this->m_uTurnCounter;
}


// address=[0x15a4d60]
// Decompiled from CVehicle *__thiscall CVehicle::CVehicle(  CVehicle *this,  int _iX,  int _iY,  int _iOwnerId,  int a5,  WORD a6,  DWORD a7,  bool a8)
 CVehicle::CVehicle(int _iX, int _iY, int _iOwnerId, int a5, int a6, int a7, bool a8) {
  
  CPlayerInfo *v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v13; // [esp+4h] [ebp-20h] BYREF
  int v14; // [esp+8h] [ebp-1Ch]
  DWORD v15; // [esp+Ch] [ebp-18h]
  unsigned int a1; // [esp+10h] [ebp-14h]
  int v18; // [esp+20h] [ebp-4h]

  IMovingEntity::IMovingEntity(this, a5);
  v18 = 0;
  this->__vftable = (CVehicle_vtbl *)&CVehicle::_vftable_;
  this->m_uGroupFlags = 0;
  this->m_iBuildingProgress = 0.0;
  std::vector<CEntityTask>::vector<CEntityTask>();
  CObserverList::CObserverList(&this->m_cObserverList);
  LOBYTE(v18) = 2;
  if ( !CWorldManager::InInnerWorld1(_iX, _iY)
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 110, "g_cWorld.InInnerWorld1(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( !CPlayerManager::ValidUsedPlayerId(_iOwnerId)
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 111, "g_cPlayerMgr.ValidUsedPlayerId(_iOwnerId)") == 1 )
  {
    __debugbreak();
  }
  v8 = CPlayerManager::PlayerInfo(_iOwnerId);
  a1 = CPlayerInfo::Race(v8);
  this->m_nType = a6;
  this->m_pVehicleProperties = IVehicleInfoMgr::VehicleProperties(a1, this->m_nType);
  this->m_uObjType = this->m_pVehicleProperties->m_uObjectType;
  IEntity::SetOwnerId(this, _iOwnerId);
  IEntity::SetRace(this, a1);
  v15 = a7;
  if ( a7 == -1 )
    v15 = CStateGame::Rand(g_pGame) % 6;
  v9 = Y16X16::PackXYFast(_iX, _iY);
  IMovingEntity::SetPositionAndDir(this, v9, v15);
  IMovingEntity::SetDisplacementCosts(this, 10);
  if ( a8 )
  {
    CVehicle::InitBuildingSite(this);
    this->m_iJobPart = CGfxManager::GetVehicleFirstJob(g_pGfxManager, a1, this->m_nType);
    this->m_uCycleFrames = CGfxManager::GetVehicleFrameCount(g_pGfxManager, a1, this->m_iJobPart);
    if ( !this->m_uCycleFrames && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 139, "m_uCycleFrames > 0") == 1 )
      __debugbreak();
    IAnimatedEntity::RegisterForLogicUpdate(this, 16);
  }
  else
  {
    IEntity::SetFlagBits(this, (EntityFlag)this->m_pVehicleProperties->m_uDefaultFlags);
    IEntity::SetFlagBits(this, EntityFlag_Ready|EntityFlag_VulnerableMask|EntityFlag_Visible);
  }
  this->m_iDistance = 0;
  this->m_iLivePoints = this->m_pVehicleProperties->m_uHitpoints;
  this->m_iJobPart = CGfxManager::GetVehicleFirstJob(g_pGfxManager, a1, this->m_nType);
  this->m_uCycleFrames = CGfxManager::GetVehicleFrameCount(g_pGfxManager, a1, this->m_iJobPart);
  if ( !this->m_uCycleFrames && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 161, "m_uCycleFrames > 0") == 1 )
    __debugbreak();
  IEntity::SetFlagBits(this, (EntityFlag)this->m_pVehicleProperties->m_tWarriorType);
  v10 = IEntity::OwnerId(this);
  v11 = CWalking::Create(this->m_pVehicleProperties->m_uU14, v10);
  std::auto_ptr<CWalking>::auto_ptr<CWalking>(&v13, v11);
  LOBYTE(v18) = 3;
  std::auto_ptr<CWalking>::operator=(&v13);
  v14 = std::auto_ptr<CWalking>::operator->(&this->m_pWalkin);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v14 + 8))(v14, -1, 0);
  this->m_uWalkResult = 8;
  this->m_uTurnCounter = 0;
  this->m_uTurningDir = 0;
  this->m_uCurrentTask = 0;
  this->byte6C = 0;
  this->m_uWalkSteps = this->m_pVehicleProperties->m_iWalkSteps;
  if ( !this->m_uWalkSteps && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 181, "m_uWalkSteps > 0") == 1 )
    __debugbreak();
  if ( this->m_uWalkSteps >= 0x20u && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 182, "m_uWalkSteps < 32") == 1 )
    __debugbreak();
  this->m_iAmmo = 0;
  this->m_uCurrentTaskIdx1 = 0;
  this->byte71 = 0;
  this->m_uReadyToFireTick = 0;
  std::vector<CEntityTask>::clear();
  LOBYTE(v18) = 2;
  std::auto_ptr<CWalking>::~auto_ptr<CWalking>(&v13);
  return this;
}


// address=[0x15a5160]
// Decompiled from int __thiscall CVehicle::~CVehicle(CVehicle *this)
 CVehicle::~CVehicle(void) {
  
  this->__vftable = (CVehicle_vtbl *)&CVehicle::_vftable_;
  CObserverList::~CObserverList((CObserverList *)&this->m_cObserverList);
  std::vector<CEntityTask>::~vector<CEntityTask>(&this->m_vTasks);
  return IMovingEntity::~IMovingEntity(this);
}


// address=[0x15a51a0]
// Decompiled from CVehicle *__thiscall CVehicle::CVehicle(CVehicle *this, int a2)
 CVehicle::CVehicle(std::istream & a2) {
  
  int v2; // eax
  unsigned int iTaskCount; // [esp+4h] [ebp-20h] BYREF
  unsigned int i; // [esp+Ch] [ebp-18h]
  unsigned int v6; // [esp+10h] [ebp-14h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  IMovingEntity::IMovingEntity(this, a2);
  v8 = 0;
  this->__vftable = (CVehicle_vtbl *)&CVehicle::_vftable_;
  std::vector<CEntityTask>::vector<CEntityTask>();
  CObserverList::CObserverList((CObserverList *)&this->m_cObserverList, a2);
  LOBYTE(v8) = 2;
  operator^<unsigned int>(a2, &v6);
  if ( v6 )
  {
    operator^<unsigned char>(a2, &this->m_uWalkResult);
    operator^<unsigned char>(a2, &this->m_uTurnCounter);
    operator^<unsigned char>(a2, &this->m_uTurningDir);
    operator^<unsigned char>(a2, &this->m_uCurrentTask);
    operator^<unsigned char>(a2, &this->byte6C);
    operator^<unsigned char>(a2, &this->m_uCycleFrames);
    operator^<unsigned char>(a2, &this->m_uWalkSteps);
    operator^<unsigned char>(a2, &this->m_iAmmo);
    operator^<unsigned char>(a2, &this->m_uCurrentTaskIdx1);
    operator^<unsigned char>(a2, &this->byte71);
    operator^<unsigned int>(a2, &this->m_uReadyToFireTick);
    operator^<bool>(a2, &CVehicle::m_bCallTakeJob);
    operator^<unsigned char>(a2, &this->word78);
    operator^<unsigned char>(a2, &this->m_uBoardsNeed);
    operator^<unsigned char>(a2, &this->word7A);
    operator^<unsigned char>(a2, &this->m_uIronNeed);
    operator^<unsigned short>(a2, &this->m_uMaterialSupplied);
    operator^<unsigned short>(a2, &this->word7E);
    operator^<unsigned short>(a2, &this->word80);
    operator^<unsigned short>(a2, &this->word82);
    operator^<unsigned short>(a2, &this->word84);
    operator^<float>(a2, &this->m_iBuildingProgress);
    operator^<unsigned char>(a2, &this->m_iDistance);
    operator^<unsigned int>(a2, &iTaskCount);
    for ( i = 0; i < iTaskCount; ++i )
    {
      v2 = CEntityTask::Load(a2);
      std::vector<CEntityTask>::push_back(v2);
    }
  }
  if ( v6 >= 2 )
    operator^<unsigned short>(a2, &this->m_uGroupFlags);
  return this;
}


// address=[0x15a54a0]
// Decompiled from void __thiscall CVehicle::Store(CVehicle *this, struct std::ostream *a1)
void  CVehicle::Store(std::ostream & a1) {
  
  _BYTE v2[12]; // [esp+4h] [ebp-40h] BYREF
  _BYTE v3[12]; // [esp+10h] [ebp-34h] BYREF
  std::_Iterator_base12 *v4; // [esp+1Ch] [ebp-28h]
  std::_Iterator_base12 *v5; // [esp+20h] [ebp-24h]
  int v6; // [esp+24h] [ebp-20h] BYREF
  int v7; // [esp+28h] [ebp-1Ch] BYREF
  int v8; // [esp+2Ch] [ebp-18h]
  char v10; // [esp+37h] [ebp-Dh]
  int v11; // [esp+40h] [ebp-4h]

  IMovingEntity::Store((CSettler *)this, a1);
  CObserverList::Store(&this->m_cObserverList, a1);
  v7 = 2;
  operator^<unsigned int>(a1, &v7);
  operator^<unsigned char>(a1, &this->m_uWalkResult);
  operator^<unsigned char>(a1, &this->m_uTurnCounter);
  operator^<unsigned char>(a1, &this->m_uTurningDir);
  operator^<unsigned char>(a1, &this->m_uCurrentTask);
  operator^<unsigned char>(a1, &this->byte6C);
  operator^<unsigned char>(a1, &this->m_uCycleFrames);
  operator^<unsigned char>(a1, &this->m_uWalkSteps);
  operator^<unsigned char>(a1, &this->m_iAmmo);
  operator^<unsigned char>(a1, &this->m_uCurrentTaskIdx1);
  operator^<unsigned char>(a1, &this->byte71);
  operator^<unsigned int>(a1, (int *)&this->m_uReadyToFireTick);
  operator^<bool>(a1, &CVehicle::m_bCallTakeJob);
  operator^<unsigned char>(a1, &this->word78);
  operator^<unsigned char>(a1, &this->m_uBoardsNeed);
  operator^<unsigned char>(a1, &this->word7A);
  operator^<unsigned char>(a1, &this->m_uIronNeed);
  operator^<unsigned short>(a1, &this->m_uMaterialSupplied);
  operator^<unsigned short>(a1, &this->word7E);
  operator^<unsigned short>(a1, &this->word80);
  operator^<unsigned short>(a1, &this->word82);
  operator^<unsigned short>(a1, &this->word84);
  operator^<float>((int)a1, &this->m_iBuildingProgress);
  operator^<unsigned char>(a1, &this->m_iDistance);
  v6 = std::vector<CEntityTask>::size(&this->m_vTasks);
  operator^<unsigned int>(a1, &v6);
  std::vector<CEntityTask>::begin(v3);
  v11 = 0;
  while ( 1 )
  {
    v5 = (std::_Iterator_base12 *)std::vector<CEntityTask>::end(v2);
    v4 = v5;
    LOBYTE(v11) = 1;
    v10 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CEntityTask>>>::operator!=(v5);
    LOBYTE(v11) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityTask>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityTask>>>(v2);
    if ( !v10 )
      break;
    v8 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityTask>>>::operator->(v3);
    (*(void (__thiscall **)(int, struct std::ostream *))(*(_DWORD *)v8 + 4))(v8, a1);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityTask>>>::operator++(v3);
  }
  v11 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityTask>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityTask>>>(v3);
  operator^<unsigned short>(a1, &this->m_uGroupFlags);
}


// address=[0x15a57a0]
// Decompiled from void __thiscall CVehicle::GetTurnGfxInfo(CVehicle *this)
void  CVehicle::GetTurnGfxInfo(void) {
  
  unsigned int iRace; // [esp+0h] [ebp-20h]
  unsigned int iGfxId; // [esp+10h] [ebp-10h]
  int iTurnId; // [esp+14h] [ebp-Ch]
  int iTurnDir; // [esp+18h] [ebp-8h]

  iRace = IEntity::Race(this);
  iTurnDir = CVehicle::TurnDirEx(this);
  iTurnId = g_sVehicleDirExInfos[iTurnDir].m_uTurnId;
  if ( iTurnId )
    iGfxId = this->m_pVehicleProperties->m_uTurnGfx + iTurnId - 1;
  else
    iGfxId = this->m_pVehicleProperties->m_uBaseGfx;
  CGfxManager::GetVehicleGfxInfo(
    g_pGfxManager,
    &IEntity::m_sGfxInfo,
    iRace,
    iGfxId,
    g_sVehicleDirExInfos[iTurnDir].m_iDir,
    g_sVehicleDirExInfos[iTurnDir].m_iFrame,
    0,
    0);
  IEntity::m_sGfxInfo.m_pPatchGfxData = 0;
}


// address=[0x15a5850]
// Decompiled from unsigned int __thiscall CVehicle::InitTurn(CVehicle *this, int a2)
unsigned int  CVehicle::InitTurn(int a2) {
  
  int v3; // [esp+0h] [ebp-24h]
  int m_iDirection; // [esp+4h] [ebp-20h]
  int v5; // [esp+10h] [ebp-14h]
  unsigned int v6; // [esp+14h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-8h]
  unsigned int v9; // [esp+1Ch] [ebp-8h]
  bool v10; // [esp+23h] [ebp-1h]

  m_iDirection = this->m_iDirection;
  v5 = a2 - m_iDirection;
  if ( a2 == m_iDirection )
  {
    this->m_uTurnCounter = 0;
    return 0;
  }
  else
  {
    this->m_iDirection = a2;
    if ( v5 <= 0 )
      v10 = v5 < -3;
    else
      v10 = v5 <= 3;
    v3 = g_sVehicleDirInfos[a2];
    v8 = g_sVehicleDirInfos[m_iDirection];
    if ( v10 )
    {
      v9 = (v8 + 1) % 0x10u;
      this->m_uTurningDir = v9 | 0x80;
    }
    else
    {
      v9 = (v8 + 15) % 0x10u;
      this->m_uTurningDir = v9;
    }
    v6 = j__abs(v9 - v3);
    if ( v6 > 8 )
      v6 = 16 - v6;
    this->m_uTurnCounter = v6;
    return v6;
  }
}


// address=[0x15a5960]
// Decompiled from int __thiscall CVehicle::TurnVehicle(CVehicle *this, unsigned int a2)
unsigned int  CVehicle::TurnVehicle(unsigned int a2) {
  
  int v3; // [esp+10h] [ebp-10h]
  unsigned int m_uTurnCounter; // [esp+14h] [ebp-Ch]

  if ( a2 > this->m_uTurnCounter )
    m_uTurnCounter = this->m_uTurnCounter;
  else
    m_uTurnCounter = a2;
  this->m_uTurnCounter -= m_uTurnCounter;
  if ( (this->m_uTurningDir & 0x80) != 0 )
    v3 = m_uTurnCounter;
  else
    v3 = -m_uTurnCounter;
  this->m_uTurningDir = this->m_uTurningDir & 0x80 | (((this->m_uTurningDir & 0x7Fu) + v3 + 16) % 0x10);
  return a2 - m_uTurnCounter;
}


// address=[0x15a5a00]
// Decompiled from void __thiscall CVehicle::TakeJobPart(CVehicle *this, int a2)
void  CVehicle::TakeJobPart(unsigned int a2) {
  
  unsigned int v2; // [esp+0h] [ebp-8h]

  v2 = IEntity::Race(this);
  this->m_iJobPart = a2;
  this->m_iFrame = 0;
  this->byte6C = 0;
  this->m_uCycleFrames = CGfxManager::GetVehicleFrameCount(g_pGfxManager, v2, a2);
  if ( !this->m_uCycleFrames && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1084, "m_uCycleFrames > 0") == 1 )
    __debugbreak();
}


// address=[0x15a5a80]
// Decompiled from char __thiscall CVehicle::NewDestination(CVehicle *this, int a2, int a3, char _iFlags)
bool  CVehicle::NewDestination(int a2, int a3, int _iFlags) {
  
  CEntityTask *v5; // eax
  char v6; // al
  int v7; // eax
  int v8; // esi
  CEntityTask *v9; // eax
  CEntityTask *v10; // eax
  CEntityTask *v11; // eax
  unsigned __int8 v12; // al
  CEntityTask *v13; // eax
  unsigned int m_uCurrentTaskIdx1; // esi
  CEntityTask v15; // [esp+4h] [ebp-B8h] BYREF
  CEntityTask v16; // [esp+1Ch] [ebp-A0h] BYREF
  CEntityTask v17; // [esp+34h] [ebp-88h] BYREF
  CEntityTask v18; // [esp+4Ch] [ebp-70h] BYREF
  CEntityTask v19; // [esp+64h] [ebp-58h] BYREF
  _BYTE v20[32]; // [esp+7Ch] [ebp-40h] BYREF
  int v21; // [esp+9Ch] [ebp-20h]
  unsigned int v22; // [esp+A0h] [ebp-1Ch]
  IEntity *v23; // [esp+A4h] [ebp-18h] BYREF
  int v24; // [esp+A8h] [ebp-14h]
  int v25; // [esp+ACh] [ebp-10h]
  int VehicleFrameCount; // [esp+B0h] [ebp-Ch]
  DWORD m_iJob; // [esp+B4h] [ebp-8h]

  m_iJob = this->m_pVehicleProperties->m_iJob;
  v22 = IEntity::Race(this);
  VehicleFrameCount = CGfxManager::GetVehicleFrameCount(g_pGfxManager, v22, m_iJob);
  if ( (_iFlags & 1) != 0 )
  {
    if ( !this->byte71 )
    {
      if ( (_iFlags & 2) == 0 )
      {
        std::vector<CEntityTask>::clear();
        this->m_uCurrentTaskIdx1 = 0;
      }
      v11 = CEntityTask::CEntityTask(&v16, 8u, m_iJob, -1, -1, -1, VehicleFrameCount, -1, 1, 1, 0, 0, 0, 0);
      std::vector<CEntityTask>::push_back(v11);
      v12 = std::vector<CEntityTask>::size(&this->m_vTasks);
      this->byte71 = v12;
    }
    v13 = CEntityTask::CEntityTask(&v15, 8u, m_iJob, a2, a3, -1, VehicleFrameCount, -1, 1, 1, 0, 0, 0, 0);
    std::vector<CEntityTask>::push_back(v13);
  }
  else
  {
    if ( (_iFlags & 2) != 0 )
    {
      if ( this->byte71 )
        return 0;
    }
    else
    {
      std::vector<CEntityTask>::clear();
      this->m_uCurrentTaskIdx1 = 0;
      this->byte71 = 0;
    }
    if ( (_iFlags & 4) != 0 )
      v24 = 6;
    else
      v24 = 7;
    v21 = v24;
    if ( (_iFlags & 0x10) != 0 )
    {
      if ( (_iFlags & 4) != 0
        && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1277, "( _iFlags & COMMAND_FLAG_GOTO ) == 0") == 1 )
      {
        __debugbreak();
      }
      v5 = CEntityTask::CEntityTask(&v19, 0x24u, m_iJob, 0, 0, -1, VehicleFrameCount, -1, 1, 1, 0, 0, 0, 0);
      std::vector<CEntityTask>::push_back(v5);
    }
    else
    {
      v25 = 0;
      if ( this->m_uObjType == Ship && (_iFlags & 4) != 0 )
      {
        v6 = IEntity::OwnerId(this);
        v7 = CAlliances::PlayerBit(v6);
        CWarriorEntitySpiralWalk::CWarriorEntitySpiralWalk((CWarriorEntitySpiralWalk *)v20, a2, a3, 10, v7, 3072);
        while ( CWarriorEntitySpiralWalk::NextEntity((CWarriorEntitySpiralWalk *)v20, &v23) )
        {
          v8 = IEntity::ID(v23);
          if ( v8 != IEntity::ID(this) )
          {
            v25 = IEntity::ID(v23);
            break;
          }
        }
      }
      if ( v25 )
      {
        v10 = CEntityTask::CEntityTask(&v17, 0xAu, m_iJob, 0, 0, -1, VehicleFrameCount, -1, 1, 1, 0, v25, 0, 0);
        std::vector<CEntityTask>::push_back(v10);
      }
      else
      {
        v9 = CEntityTask::CEntityTask(&v18, v21, m_iJob, a2, a3, -1, VehicleFrameCount, -1, 1, 1, 0, 0, 0, 0);
        std::vector<CEntityTask>::push_back(v9);
      }
    }
  }
  if ( !std::vector<CEntityTask>::size(&this->m_vTasks)
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1403, "m_vTasks.size() > 0") == 1 )
  {
    __debugbreak();
  }
  m_uCurrentTaskIdx1 = this->m_uCurrentTaskIdx1;
  if ( m_uCurrentTaskIdx1 > std::vector<CEntityTask>::size(&this->m_vTasks)
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1404, "m_uCurrentTaskIdx1 <= m_vTasks.size()") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uCurrentTaskIdx1 )
    return 0;
  this->m_uCurrentTaskIdx1 = 1;
  return 1;
}


// address=[0x15a5dc0]
// Decompiled from int __thiscall CVehicle::GetNextJob(CVehicle *this)
void  CVehicle::GetNextJob(void) {
  
  unsigned int m_uCurrentTaskIdx1; // esi

  m_uCurrentTaskIdx1 = this->m_uCurrentTaskIdx1;
  if ( m_uCurrentTaskIdx1 < std::vector<CEntityTask>::size(&this->m_vTasks) )
  {
    ++this->m_uCurrentTaskIdx1;
  }
  else
  {
    this->m_uCurrentTaskIdx1 = this->byte71;
    if ( !this->byte71 )
      std::vector<CEntityTask>::clear();
  }
  return this->TakeJob(this);
}


// address=[0x15a5e30]
// Decompiled from void __thiscall CVehicle::DetachWithoutNotify(CVehicle *this, int a2)
void  CVehicle::DetachWithoutNotify(int a2) {
  
  CObserverList::Detach((CObserverList *)&this->m_cObserverList, a2);
}


// address=[0x15a5e50]
// Decompiled from void __thiscall CVehicle::SetReadyToFireTick(CVehicle *this, unsigned int a2)
void  CVehicle::SetReadyToFireTick(unsigned int a2) {
  
  this->m_uReadyToFireTick = this->m_pVehicleProperties->m_uReadyToFireDelay + a2;
}


// address=[0x15a5e70]
// Decompiled from bool __thiscall CVehicle::EnoughAmmo(CVehicle *this)
bool  CVehicle::EnoughAmmo(void)const {
  
  return this->m_iAmmo != 0;
}


// address=[0x15a5ea0]
// Decompiled from int __thiscall CVehicle::AmmoAmount(CVehicle *this)
unsigned int  CVehicle::AmmoAmount(void)const {
  
  return this->m_iAmmo;
}


// address=[0x15a5ec0]
// Decompiled from void __thiscall CVehicle::DecreaseAmmo(CVehicle *this)
void  CVehicle::DecreaseAmmo(void) {
  
  if ( this->m_iAmmo )
    --this->m_iAmmo;
}


// address=[0x15a5ef0]
// Decompiled from void __thiscall CVehicle::AttackTarget(CVehicle *this, int _iTargetId)
void  CVehicle::AttackTarget(int _iTargetId) {
  
  int v2; // eax
  unsigned int TickCounter; // eax
  int v4; // [esp-4h] [ebp-24h]
  unsigned int v5; // [esp+0h] [ebp-20h]
  int v6; // [esp+4h] [ebp-1Ch]
  int v7; // [esp+8h] [ebp-18h]
  int v8; // [esp+10h] [ebp-10h]
  struct IFutureEvents *v9; // [esp+14h] [ebp-Ch]
  IEntity *v10; // [esp+18h] [ebp-8h]

  if ( !_iTargetId && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1096, "_iTargetId != 0") == 1 )
    __debugbreak();
  v10 = CMapObjectMgr::Entity(_iTargetId);
  if ( IEntity::WarriorType(v10) == AI_WARRIOR_TYPE_NONE
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1100, "rTargetEntity.WarriorType() != WARRIOR_TYPE_NONE") == 1 )
  {
    __debugbreak();
  }
  if ( !IEntity::FlagBits(v10, EntityFlag_Ready)
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1101, "rTargetEntity.FlagBits( ENTITY_FLAG_READY ) != 0") == 1 )
  {
    __debugbreak();
  }
  v4 = IEntity::PackedXY(v10);
  v2 = IEntity::PackedXY(this);
  v8 = Y16X16::DirectionFast(v2, v4);
  v5 = this->m_pVehicleProperties->m_uUAttackTurnRelated + CVehicle::InitTurn(this, v8);
  v6 = IEntity::ID(this);
  v7 = IEntity::PackedXY(v10);
  v9 = CLogic::FutureEvents(g_pLogic);
  (*(void (__thiscall **)(struct IFutureEvents *, int, unsigned int, int, int, int))(*(_DWORD *)v9 + 12))(
    v9,
    6,
    v5,
    v6,
    _iTargetId,
    v7);
  TickCounter = CStateGame::GetTickCounter(g_pGame);
  CVehicle::SetReadyToFireTick(this, TickCounter);
  this->DecreaseAmmo(this);
}


// address=[0x15a6040]
// Decompiled from void __thiscall CVehicle::WalkDirAndRegister(CVehicle *this, int a2, bool a3)
void  CVehicle::WalkDirAndRegister(int a2, bool a3) {
  
  int v3; // eax
  DWORD iJob; // [esp+Ch] [ebp-10h]
  unsigned int v5; // [esp+10h] [ebp-Ch]

  this->WalkDir(this, a2);
  if ( (this->m_uWalkResult & 0x70) != 0 && a3 )
  {
    CVehicle::GetNextJob(this);
  }
  else
  {
    if ( this->m_uCurrentTask == 17 )
      v5 = 17;
    else
      v5 = 6;
    iJob = this->m_pVehicleProperties->m_iJob;
    if ( (this->m_uWalkResult & 0xFu) >= 6 )
    {
      if ( (this->m_uWalkResult & 8) == 0
        && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1158, "( m_uWalkResult & WALK_RESULT_FLAG_DONT_MOVE ) != 0") == 1 )
      {
        __debugbreak();
      }
      if ( this->m_uTurnCounter
        && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1159, "( m_uTurnCounter == 0 )") == 1 )
      {
        __debugbreak();
      }
      CVehicle::RegisterNewTaskAndTakeJobPartIfNecessary(this, v5, 1u, iJob);
    }
    else
    {
      if ( (this->m_uWalkResult & 8) != 0
        && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1150, "( m_uWalkResult & WALK_RESULT_FLAG_DONT_MOVE ) == 0") == 1 )
      {
        __debugbreak();
      }
      v3 = CVehicle::TurnCounter(this);
      CVehicle::RegisterNewTaskAndTakeJobPartIfNecessary(this, v5, this->m_uWalkSteps + v3, iJob);
    }
  }
}


// address=[0x15a61a0]
// Decompiled from void __thiscall CVehicle::InitCommonTaskValues(CVehicle *this, const struct CEntityTask *a2)
void  CVehicle::InitCommonTaskValues(class CEntityTask const * a2) {
  
  if ( a2 )
  {
    if ( *((char *)a2 + 6) >= 0 )
      this->m_iDirection = *((_BYTE *)a2 + 6);
    if ( *((_BYTE *)a2 + 20) )
      IEntity::SetFlagBits(this, EntityFlag_Visible);
    else
      IEntity::ClearFlagBits(this, EntityFlag_Visible);
    this->m_uCurrentTask = *((_BYTE *)a2 + 4);
    CVehicle::TakeJobPart(this, *((unsigned __int16 *)a2 + 7));
  }
  else
  {
    IEntity::SetFlagBits(this, EntityFlag_Visible);
    this->m_uCurrentTask = 17;
    CVehicle::TakeJobPart(this, *((_DWORD *)this->m_pVehicleProperties + 6));
  }
  this->m_uWalkResult = 8;
  this->m_uTurnCounter = 0;
  this->m_iDistance = 0;
}


// address=[0x15a6250]
// Decompiled from void __thiscall CVehicle::ConvertEventIntoGoal(CVehicle *this, struct CEntityEvent *a2)
void  CVehicle::ConvertEventIntoGoal(class CEntityEvent * a2) {
  
  char v2; // al
  char v3; // al
  int v4; // [esp+0h] [ebp-14h]
  int v5; // [esp+4h] [ebp-10h]
  int m_iEvent; // [esp+10h] [ebp-4h]

  m_iEvent = a2->m_iEvent;
  if ( m_iEvent == 13 )
  {
    v2 = CVehicle::NewDestination(this, a2->m_iDataB, a2->m_iDataC, a2->m_iDataA);
    CVehicle::NotifyCallTakeJob(v2);
  }
  else if ( m_iEvent == 17 && a2->m_iType == 13 )
  {
    v4 = Y16X16::UnpackXFast(a2->m_iDataB);
    v5 = Y16X16::UnpackYFast(a2->m_iDataB);
    v3 = CVehicle::NewDestination(this, v4, v5, a2->m_iDataA);
    CVehicle::NotifyCallTakeJob(v3);
  }
}


// address=[0x15a6300]
// Decompiled from void __thiscall CVehicle::MoveTo(CVehicle *this, int a2, int a3, int a4)
void  CVehicle::MoveTo(int a2, int a3, int a4) {
  
  int v4; // eax
  CEntityEvent v5; // [esp+4h] [ebp-30h] BYREF
  CEntityEvent *v6; // [esp+1Ch] [ebp-18h]
  CEntityEvent *v7; // [esp+20h] [ebp-14h]
  int v9; // [esp+30h] [ebp-4h]

  v4 = Y16X16::PackXYFast(a2, a3);
  v7 = CEntityEvent::CEntityEvent(&v5, 0x11u, 13, 0, v4, 0);
  v6 = v7;
  v9 = 0;
  this->SetEvent(this, v7);
  v9 = -1;
  CEntityEvent::~CEntityEvent(&v5);
}


// address=[0x15a7a20]
// Decompiled from bool CVehicle::CallTakeJob()
bool __cdecl CVehicle::CallTakeJob(void) {
  
  return CVehicle::m_bCallTakeJob;
}


// address=[0x15a7a30]
// Decompiled from void CVehicle::ClearCallTakeJob()
void __cdecl CVehicle::ClearCallTakeJob(void) {
  
  CVehicle::m_bCallTakeJob = 0;
}


// address=[0x15a7ae0]
// Decompiled from bool __thiscall CVehicle::IsMoving(CVehicle *this)
bool  CVehicle::IsMoving(void)const {
  
  return (this->m_uWalkResult & 8) == 0;
}


// address=[0x15a7b20]
// Decompiled from void __cdecl CVehicle::NotifyCallTakeJob(bool a1)
void __cdecl CVehicle::NotifyCallTakeJob(bool a1) {
  
  CVehicle::m_bCallTakeJob |= a1;
}


// address=[0x15a7b40]
// Decompiled from void __thiscall CVehicle::RegisterNewTaskAndTakeJobPartIfNecessary(  CVehicle *this,  unsigned int a2,  unsigned int a3,  int a4)
void  CVehicle::RegisterNewTaskAndTakeJobPartIfNecessary(unsigned int a2, unsigned int a3, unsigned int a4) {
  
  CVehicle::RegisterNewTask(this, a2, a3);
  CVehicle::TakeJobPartIfNecessary(this, a4);
}


// address=[0x15a7be0]
// Decompiled from void __thiscall CVehicle::TakeJobPartIfNecessary(CVehicle *this, int a2)
void  CVehicle::TakeJobPartIfNecessary(unsigned int a2) {
  
  if ( this->m_iJobPart != a2 )
    CVehicle::TakeJobPart(this, a2);
}


// address=[0x4158cfe]
// [Decompilation failed for static bool CVehicle::m_bCallTakeJob]

// address=[0x153a570]
// Decompiled from void __thiscall CVehicle::NotifyDetach(CVehicle *this, int a2)
void  CVehicle::NotifyDetach(int a2) {
  
  ;
}


