#include "CDonkeyRole.h"

// Definitions for class CDonkeyRole

// address=[0x1400540]
// Decompiled from int __cdecl CDonkeyRole::New(int a1)
class CPersistence * __cdecl CDonkeyRole::New(std::istream & a1) {
  
  if ( operator new(0x7Cu) )
    return CDonkeyRole::CDonkeyRole(a1);
  else
    return 0;
}


// address=[0x152bdb0]
// Decompiled from int __thiscall CDonkeyRole::GetTradingState(CDonkeyRole *this)
enum CDonkeyRole::TIntTraderState  CDonkeyRole::GetTradingState(void) {
  
  return this->m_iTradingState;
}


// address=[0x152be10]
// Decompiled from bool __thiscall CDonkeyRole::IsNeutralTrader(CDonkeyRole *this)
bool  CDonkeyRole::IsNeutralTrader(void) {
  
  return this->m_bIsNeutralTrader;
}


// address=[0x152be70]
// Decompiled from void __thiscall CDonkeyRole::MemHomePosition(CDonkeyRole *this)
void  CDonkeyRole::MemHomePosition(void) {
  
  CSettler *SettlerPtr; // eax

  SettlerPtr = CSettlerMgr::GetSettlerPtr(&g_cSettlerMgr, this->m_iTraderSettlerId);
  this->m_iStartPosition = IEntity::PackedXY(SettlerPtr);
}


// address=[0x1569d40]
// Decompiled from CWalkingNormal *__thiscall CDonkeyRole::InitWalking(CDonkeyRole *this, IEntity *a2)
class CWalking *  CDonkeyRole::InitWalking(class CSettler * a2) {
  
  int v2; // eax
  CWalkingNormal *v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId(a2);
  v4 = CWalking::Create(0, v2);
  v4->InitB(v4, -1, 0);
  return v4;
}


// address=[0x1569d80]
// Decompiled from void __thiscall CDonkeyRole::LogicUpdateJob(CDonkeyRole *this, struct CSettler *_pSettler)
void  CDonkeyRole::LogicUpdateJob(class CSettler * _pSettler) {
  
  int v2; // eax
  IEntity *v3; // eax
  IEntity *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp+0h] [ebp-10h]
  CVehicle *v8; // [esp+4h] [ebp-Ch]

  if ( IEntity::FlagBits(_pSettler, ENTITY_FLAG_Selected) || IEntity::FlagBits(_pSettler, (EntityFlag)1024) )
    this->FillDialog(this, 1);
  switch ( this->m_iTask )
  {
    case 6:
      IMovingEntity::SetDistance(_pSettler, 0);
      this->Go(this, _pSettler);
      if ( !IEntity::FlagBits(_pSettler, ENTITY_FLAG_Registered) && debug && DEBUG_FLAGS[dword_41520AC] )
      {
        v2 = IEntity::ID(_pSettler);
        BBSupportTracePrintF(0, "LogicUpdateJob - Go - not registered donkey %u", v2);
      }
      break;
    case 0x15:
    case 0x16:
      goto LABEL_28;
    case 0x17:
      if ( !this->m_uDestinationEntityID
        && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 364, "m_uDestinationEntityID > 0") == 1 )
      {
        __debugbreak();
      }
      v3 = CMapObjectMgr::EntityPtr(this->m_uDestinationEntityID);
      if ( IEntity::ObjType(v3) != CATAPULT_OBJ )
      {
        v4 = CMapObjectMgr::EntityPtr(this->m_uDestinationEntityID);
        if ( IEntity::ObjType(v4) != SHIP_OBJ
          && BBSupportDbgReport(
               2,
               "MapObjects\\Settler\\DonkeyRole.cpp",
               367,
               "(g_pMapObjectMgr->EntityPtr( m_uDestinationEntityID ))->ObjType() == CATAPULT_OBJ || (g_pMapObjectMgr->En"
               "tityPtr( m_uDestinationEntityID ))->ObjType() == SHIP_OBJ") == 1 )
        {
          __debugbreak();
        }
      }
      v8 = CVehicleMgr::operator[](this->m_uDestinationEntityID);
      v8->GoodArrived(v8, this->m_uGood, this->m_iCargoAmount);
      v5 = IEntity::ID(_pSettler);
      v8->Detach(v8, v5);
      this->m_uDestinationEntityID = 0;
      this->m_iCargoAmount = 0;
      CDonkeyRole::SetFree(this);
      CDonkeyRole::TryToGoHome(this);
      CDonkeyRole::SetJobType(this, 0);
      if ( !IEntity::FlagBits(_pSettler, ENTITY_FLAG_Registered) && debug && DEBUG_FLAGS[dword_41520AC] )
      {
        v6 = IEntity::ID(_pSettler);
        BBSupportTracePrintF(0, "LogicUpdateJob - LoadGood ready - not registered settler %u", v6);
      }
      break;
    case 0x20:
      v7 = this->m_uCycleFrames / 2;
      this->m_iWalkspeed -= v7;
      if ( this->m_iWalkspeed < v7 )
      {
        if ( this->m_iDepartBuildingID )
        {
          this->m_iTargetBuildingID = this->m_iDepartBuildingID;
          this->m_iDepartBuildingID = 0;
        }
LABEL_28:
        this->GetNextJob(this, _pSettler);
      }
      else
      {
        CDonkeyRole::DropGoods(this, _pSettler);
        IAnimatedEntity::RegisterForLogicUpdate(_pSettler, v7 - 1);
      }
      break;
    default:
      CTrace::Print("LogicUpdateJob Donkey - unknown task %u", this->m_iTask);
      break;
  }
  if ( this->m_iTask != this->m_uCurrentTask
    && (this->m_iTargetCardID || this->m_bGoingHome)
    && this->m_uCurrentTask == 6 )
  {
    CDonkeyRole::DonkeyArrived(this);
  }
  this->m_uCurrentTask = this->m_iTask;
}


// address=[0x156a0d0]
// Decompiled from void __fastcall CDonkeyRole::UpdateJob(CDonkeyRole *this, int a2, struct CSettler *_pSettler)
void  CDonkeyRole::UpdateJob(class CSettler * a2) {
  
  char v3; // al

  if ( this->m_iTask == 32 )
  {
    v3 = IAnimatedEntity::Frame(_pSettler);
    IAnimatedEntity::SetFrame(_pSettler, this->m_uTick + v3);
    if ( IAnimatedEntity::Frame(_pSettler) >= this->m_uCycleFrames )
      IAnimatedEntity::SetFrame(_pSettler, 0);
  }
}


// address=[0x156a130]
// Decompiled from void __stdcall CDonkeyRole::PostLoadInit(IEntity *a1)
void  CDonkeyRole::PostLoadInit(class CSettler * a1) {
  
  CWarMap::AddEntity(a1);
}


// address=[0x156a150]
// Decompiled from void __thiscall CDonkeyRole::InitFlee(CDonkeyRole *this, struct CSettler *a2, int a3)
void  CDonkeyRole::InitFlee(class CSettler * a2, int a3) {
  
  ;
}


// address=[0x156a160]
// Decompiled from int __thiscall CDonkeyRole::Decrease(CDonkeyRole *this, int a2)
int  CDonkeyRole::Decrease(int a2) {
  
  unsigned int v2; // eax
  std::list *v3; // eax
  CSettler *SettlerPtr; // [esp+0h] [ebp-8h]

  if ( !CDonkeyRole::HasLoadedSomething(this) || !this->m_iTraderSettlerId || this->m_iTask == 32 )
    return 0;
  SettlerPtr = CSettlerMgr::GetSettlerPtr(&g_cSettlerMgr, this->m_iTraderSettlerId);
  v2 = IEntity::Race(SettlerPtr);
  v3 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v2, 0xA2u);
  SettlerPtr->NewToDoList(SettlerPtr, (int)v3, 162);
  return 0;
}


// address=[0x156a1e0]
// Decompiled from void __thiscall CDonkeyRole::NextStep(CDonkeyRole *this)
void  CDonkeyRole::NextStep(void) {
  
  CSettler *SettlerPtr; // [esp+0h] [ebp-8h]

  if ( this->m_iTraderSettlerId )
  {
    SettlerPtr = CSettlerMgr::GetSettlerPtr(&g_cSettlerMgr, this->m_iTraderSettlerId);
    IAnimatedEntity::RegisterForLogicUpdate(SettlerPtr, 1);
  }
}


// address=[0x156a220]
// Decompiled from int __thiscall CDonkeyRole::GetGoodAmount(CDonkeyRole *this, int _iGood)
int  CDonkeyRole::GetGoodAmount(int _iGood) {
  
  int iTotal; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  iTotal = 0;
  for ( i = 0; i < 2; ++i )
  {
    if ( this->m_vGoodSlots[i].m_iGood == _iGood )
      iTotal += this->m_vGoodSlots[i].m_iAmount;
  }
  return iTotal;
}


// address=[0x156a280]
// Decompiled from int __thiscall CDonkeyRole::AddGood(CDonkeyRole *this, int _iGood, int _iAmount)
int  CDonkeyRole::AddGood(int _iGood, int _iAmount) {
  
  CSettler *SettlerPtr; // [esp+0h] [ebp-1Ch]
  int v5; // [esp+4h] [ebp-18h]
  int v6; // [esp+8h] [ebp-14h]
  int i; // [esp+18h] [ebp-4h]
  int j; // [esp+18h] [ebp-4h]

  for ( i = 0; i < 2; ++i )
  {
    if ( this->m_vGoodSlots[i].m_iGood == _iGood && this->m_vGoodSlots[i].m_iAmount != 8 )
    {
      if ( 8 - this->m_vGoodSlots[i].m_iAmount >= _iAmount )
        v6 = _iAmount;
      else
        v6 = 8 - this->m_vGoodSlots[i].m_iAmount;
      this->m_vGoodSlots[i].m_iAmount += v6;
      _iAmount -= v6;
    }
  }                                             // If amount left, try to fill new slot...
  if ( _iAmount )
  {
    for ( j = 0; j < 2; ++j )
    {
      if ( !this->m_vGoodSlots[j].m_iGood && _iAmount )
      {
        if ( _iAmount <= 8 )
          v5 = _iAmount;
        else
          v5 = 8;
        this->m_vGoodSlots[j].m_iAmount += v5;
        this->m_vGoodSlots[j].m_iGood = _iGood;
        this->m_iTotalAmount += v5;
        _iAmount -= v5;
      }
    }
  }
  SettlerPtr = CSettlerMgr::GetSettlerPtr(&g_cSettlerMgr, this->m_iTraderSettlerId);
  if ( IEntity::FlagBits(SettlerPtr, ENTITY_FLAG_Selected) || IEntity::FlagBits(SettlerPtr, (EntityFlag)1024) )
    this->FillDialog(this, 1);
  return _iAmount;
}


// address=[0x156a400]
// Decompiled from int __thiscall CDonkeyRole::RemoveGood(CDonkeyRole *this, int a2, int a3)
int  CDonkeyRole::RemoveGood(int a2, int a3) {
  
  CSettler *SettlerPtr; // [esp+4h] [ebp-14h]
  int m_iAmount; // [esp+8h] [ebp-10h]
  int i; // [esp+10h] [ebp-8h]

  if ( a3 < 0 )
    return 0;
  for ( i = 0; i < 2; ++i )
  {
    if ( this->m_vGoodSlots[i].m_iGood == a2 )
    {
      if ( this->m_vGoodSlots[i].m_iAmount >= a3 )
        m_iAmount = a3;
      else
        m_iAmount = this->m_vGoodSlots[i].m_iAmount;
      this->m_vGoodSlots[i].m_iAmount -= m_iAmount;
      if ( !this->m_vGoodSlots[i].m_iAmount )
        this->m_vGoodSlots[i].m_iGood = 0;
      a3 -= m_iAmount;
      this->m_iRemovedAmount += m_iAmount;
    }
  }
  SettlerPtr = CSettlerMgr::GetSettlerPtr(&g_cSettlerMgr, this->m_iTraderSettlerId);
  if ( IEntity::FlagBits(SettlerPtr, ENTITY_FLAG_Selected) || IEntity::FlagBits(SettlerPtr, (EntityFlag)1024) )
    this->FillDialog(this, 1);
  return a3;
}


// address=[0x156a520]
// Decompiled from char __thiscall CDonkeyRole::IsSpaceAvailable(CDonkeyRole *this, int _iGood)
bool  CDonkeyRole::IsSpaceAvailable(int _iGood) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 2; ++i )
  {
    if ( !this->m_vGoodSlots[i].m_iGood )
      return 1;
    if ( this->m_vGoodSlots[i].m_iGood == _iGood && 8 - this->m_vGoodSlots[i].m_iAmount > 0 )
      return 1;
  }
  return 0;
}


// address=[0x156a590]
// Decompiled from int __thiscall CDonkeyRole::GetAvailableSpace(CDonkeyRole *this, int _iGood)
int  CDonkeyRole::GetAvailableSpace(int _iGood) {
  
  int v3; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  v3 = 0;
  for ( i = 0; i < 2; ++i )
  {
    if ( this->m_vGoodSlots[i].m_iGood == _iGood && 8 - this->m_vGoodSlots[i].m_iAmount > 0 )
      v3 += 8 - this->m_vGoodSlots[i].m_iAmount;
  }
  return v3;
}


// address=[0x156a600]
// Decompiled from int __thiscall CDonkeyRole::GetAvailableSpace(CDonkeyRole *this)
int  CDonkeyRole::GetAvailableSpace(void) {
  
  int v2; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < 2; ++i )
  {
    if ( !this->m_vGoodSlots[i].m_iGood )
      v2 += 8;
  }
  return v2;
}


// address=[0x156a650]
// Decompiled from char __thiscall CDonkeyRole::IsFull(CDonkeyRole *this)
bool  CDonkeyRole::IsFull(void) {
  
  int v2; // [esp+0h] [ebp-10h]
  int i; // [esp+8h] [ebp-8h]
  int j; // [esp+Ch] [ebp-4h]

  if ( CDonkeyRole::IsNeutralTrader(this) )
  {
    v2 = 0;
    for ( i = 0; i < 2; ++i )
    {
      v2 += this->m_vGoodSlots[i].m_iAmount;
      if ( v2 >= 16 )
        return 1;
    }
    return 0;
  }
  else
  {
    for ( j = 0; j < 2; ++j )
    {
      if ( !this->m_vGoodSlots[j].m_iGood )
        return 0;
      if ( 8 - this->m_vGoodSlots[j].m_iAmount > 0 )
        return 0;
    }
    return 1;
  }
}


// address=[0x156a700]
// Decompiled from char __thiscall CDonkeyRole::HasLoadedSomething(CDonkeyRole *this)
bool  CDonkeyRole::HasLoadedSomething(void) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 2; ++i )
  {
    if ( this->m_vGoodSlots[i].m_iAmount )
      return 1;
  }
  return 0;
}


// address=[0x156a740]
// Decompiled from int __thiscall CDonkeyRole::DropGoods(CDonkeyRole *this, struct CSettler *a2)
void  CDonkeyRole::DropGoods(class CSettler * a2) {
  
  unsigned int v2; // eax
  unsigned int v4; // [esp-Ch] [ebp-20h]
  unsigned int v6; // [esp+4h] [ebp-10h]
  int j; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  for ( i = 0; i < 43; ++i )
  {
    for ( j = CDonkeyRole::GetGoodAmount(this, i); j; j -= v6 )
    {
      if ( j > 8 )
        v6 = 8;
      else
        v6 = j;
      v4 = IEntity::Y(a2);
      v2 = IEntity::X(a2);
      CPileMgr::SearchSpaceForGoods(&g_cPileMgr, v2, v4, i, v6);
      CDonkeyRole::RemoveGood(this, i, v6);
    }
  }
  return IEntity::ClearFlagBits(a2, ENTITY_FLAG_VulnerableMask);
}


// address=[0x156a7f0]
// Decompiled from char __thiscall CDonkeyRole::SetFree(CDonkeyRole *this)
bool  CDonkeyRole::SetFree(void) {
  
  unsigned int v1; // eax
  std::list *v2; // eax
  unsigned int v4; // [esp-8h] [ebp-10h]
  int v5; // [esp-4h] [ebp-Ch]
  struct CSettler *SettlerPtr; // [esp+4h] [ebp-4h]

  if ( !this->m_iTraderSettlerId )
    return 0;
  SettlerPtr = CSettlerMgr::GetSettlerPtr(&g_cSettlerMgr, this->m_iTraderSettlerId);
  if ( CDonkeyRole::HasLoadedSomething(this) )
    CDonkeyRole::DropGoods(this, SettlerPtr);
  v5 = IEntity::Type(SettlerPtr);
  v4 = IEntity::Type(SettlerPtr);
  v1 = IEntity::Race(SettlerPtr);
  v2 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v1, v4);
  SettlerPtr->NewToDoList(SettlerPtr, (int)v2, v5);
  return 0;
}


// address=[0x156a870]
// Decompiled from char __thiscall CDonkeyRole::HasLoadGood(CDonkeyRole *this, int _tPileType)
bool  CDonkeyRole::HasLoadGood(enum PILE_TYPES _tPileType) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 2; ++i )
  {
    if ( this->m_vGoodSlots[i].m_iAmount > 0 && this->m_vGoodSlots[i].m_iGood == _tPileType )
      return 1;
  }
  return 0;
}


// address=[0x156a8c0]
// Decompiled from void __thiscall CDonkeyRole::SetTargetBuildingID(CDonkeyRole *this, int a2)
void  CDonkeyRole::SetTargetBuildingID(int a2) {
  
  this->m_iTargetBuildingID = a2;
}


// address=[0x156a8e0]
// Decompiled from int __thiscall CDonkeyRole::GetTargetBuildingID(CDonkeyRole *this)
int  CDonkeyRole::GetTargetBuildingID(void) {
  
  return this->m_iTargetBuildingID;
}


// address=[0x156a900]
// Decompiled from void __thiscall CDonkeyRole::TargetBuildingDestroyed(CDonkeyRole *this)
void  CDonkeyRole::TargetBuildingDestroyed(void) {
  
  bool IsNeutralTrader; // al
  struct CBuilding *v2; // eax
  int v3; // eax
  CTradingBuildingRole *pBuildingRole; // [esp+4h] [ebp-14h] MAPDST
  CBuilding *BuildingPtr; // [esp+8h] [ebp-10h]
  CBuilding *v7; // [esp+Ch] [ebp-Ch]
  int a2; // [esp+10h] [ebp-8h]

  if ( this->m_bGoToTarget && this->m_iTargetBuildingID )
  {
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, this->m_iTargetBuildingID);
    pBuildingRole = (CTradingBuildingRole *)CBuilding::Role(BuildingPtr);
    CTradingBuildingRole::UnregisterIncomingTrader(pBuildingRole, this->m_iTraderSettlerId, 2);
  }
  CDonkeyRole::SetTargetBuildingID(this, 0);
  if ( this->m_iDepartBuildingID
    && (a2 = this->m_iDepartBuildingID, (v7 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a2)) != 0) )
  {
    CDonkeyRole::SetDepartBuildingID(this, 0);
    CDonkeyRole::SetTargetBuildingID(this, a2);
    pBuildingRole = (CTradingBuildingRole *)CBuilding::Role(v7);
    IsNeutralTrader = CDonkeyRole::IsNeutralTrader(this);
    CTradingBuildingRole::RegisterIncomingTrader(pBuildingRole, this->m_iTraderSettlerId, 2, IsNeutralTrader);
    v2 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, this->m_iTargetBuildingID);
    v3 = CBuilding::EnsignPackedXY(v2);
    CDonkeyRole::MoveToTarget(this, v3, 0);
  }
  else
  {
    CDonkeyRole::SetFree(this);
    CDonkeyRole::TryToGoHome(this);
    CDonkeyRole::SetJobType(this, 0);
  }
}


// address=[0x156aa30]
// Decompiled from void __thiscall CDonkeyRole::SetDepartBuildingID(CDonkeyRole *this, int a2)
void  CDonkeyRole::SetDepartBuildingID(int a2) {
  
  this->m_iDepartBuildingID = a2;
}


// address=[0x156aa50]
// Decompiled from int __thiscall CDonkeyRole::GetDepartBuildingID(CDonkeyRole *this)
int  CDonkeyRole::GetDepartBuildingID(void) {
  
  return this->m_iDepartBuildingID;
}


// address=[0x156aa70]
// Decompiled from void __thiscall CDonkeyRole::DepartBuildingDestroyed(CDonkeyRole *this)
void  CDonkeyRole::DepartBuildingDestroyed(void) {
  
  CTradingBuildingRole *v1; // [esp+0h] [ebp-10h]
  CBuilding *BuildingPtr; // [esp+4h] [ebp-Ch]
  int iDep; // [esp+8h] [ebp-8h]

  iDep = this->m_iDepartBuildingID;
  CDonkeyRole::SetDepartBuildingID(this, 0);
  if ( this->m_bGoToSource )
  {
    if ( !iDep && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1025, "iDep") == 1 )
      __debugbreak();
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, iDep);
    v1 = (CTradingBuildingRole *)CBuilding::Role(BuildingPtr);
    CTradingBuildingRole::UnregisterIncomingTrader(v1, this->m_iTraderSettlerId, 2);
  }
  if ( !CDonkeyRole::GetTargetBuildingID(this) )
  {
    CDonkeyRole::SetJobType(this, 0);
    CDonkeyRole::TryToGoHome(this);
  }
}


// address=[0x156ab10]
// Decompiled from void __thiscall CDonkeyRole::DonkeyArrived(CDonkeyRole *this)
void  CDonkeyRole::DonkeyArrived(void) {
  
  CPile *v1; // eax
  int m_iTraderSettlerId; // [esp-4h] [ebp-28h]
  CTradingBuildingRole *v3; // [esp+4h] [ebp-20h]
  CTradingBuildingRole *v4; // [esp+8h] [ebp-1Ch]
  struct CSettler *SettlerPtr; // [esp+Ch] [ebp-18h]
  IBuildingRole *v6; // [esp+10h] [ebp-14h]
  CCart *VehiclePtr; // [esp+14h] [ebp-10h]
  IEntity *pPile; // [esp+18h] [ebp-Ch]
  CBuilding *BuildingPtr; // [esp+1Ch] [ebp-8h]
  CBuilding *v10; // [esp+1Ch] [ebp-8h]
  CBuilding *v11; // [esp+1Ch] [ebp-8h]

  this->m_iRemovedAmount = 0;
  if ( this->m_bGoToSource )
  {
    if ( this->m_iDepartBuildingID )
    {
      BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, this->m_iDepartBuildingID);
      if ( BuildingPtr )
      {
        v6 = CBuilding::Role(BuildingPtr);
        CTradingBuildingRole::VehicleArrived((CTradingBuildingRole *)v6, this->m_iTraderSettlerId, 2);
      }
    }
    if ( this->m_bReturning && !this->m_uGood )
    {
      if ( !this->m_uSourcePileID
        && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1077, "m_uSourcePileID > 0") == 1 )
      {
        __debugbreak();
      }
      pPile = CMapObjectMgr::EntityPtr(this->m_uSourcePileID);
      if ( !pPile && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1079, "pPile != 0") == 1 )
        __debugbreak();
      if ( pPile->Amount() < this->m_iCargoAmount
        && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1080, "pPile->Amount() >= m_iCargoAmount") == 1 )
      {
        __debugbreak();
      }
      this->m_uGood = pPile->GetGoodType();
      m_iTraderSettlerId = this->m_iTraderSettlerId;
      v1 = CPileMgr::operator[](this->m_uSourcePileID);
      CPile::ChangeAmountAndDetach(v1, m_iTraderSettlerId);
      this->m_uSourcePileID = 0;
      SettlerPtr = CSettlerMgr::GetSettlerPtr(&g_cSettlerMgr, this->m_iTraderSettlerId);
      this->GetNextJob(this, SettlerPtr);
    }
  }
  if ( this->m_bGoToTarget )
  {
    if ( this->m_iTargetBuildingID )
    {
      v10 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, this->m_iTargetBuildingID);
      if ( v10 )
      {
        v4 = (CTradingBuildingRole *)CBuilding::Role(v10);
        CTradingBuildingRole::VehicleArrived(v4, this->m_iTraderSettlerId, 2);
      }
    }
    if ( this->m_iDepartBuildingID )
    {
      v11 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, this->m_iDepartBuildingID);
      if ( v11 )
      {
        v3 = (CTradingBuildingRole *)CBuilding::Role(v11);
        CTradingBuildingRole::VehicleArrivedAtTarget(v3, this->m_iTraderSettlerId, 2);
      }
    }
  }
  if ( this->m_iTargetCardID > 0 )
  {
    if ( !CMapObjectMgr::ValidEntityId(this->m_iTargetCardID)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Settler\\DonkeyRole.cpp",
           1125,
           "g_pMapObjectMgr->ValidEntityId((m_iTargetCardID))") == 1 )
    {
      __debugbreak();
    }
    VehiclePtr = (CCart *)CVehicleMgr::GetVehiclePtr(this->m_iTargetCardID);
    if ( !VehiclePtr )
    {
      this->m_iTargetCardID = 0;
      return;
    }
    if ( !j____RTDynamicCast(
            (void **)&VehiclePtr->__vftable,
            0,
            &CVehicle__RTTI_Type_Descriptor_,
            &CCart__RTTI_Type_Descriptor_,
            0)
      && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1138, "dynamic_cast<CCart*>(pVehicle)!=NULL") == 1 )
    {
      __debugbreak();
    }
    CCart::DonkeyArrived(VehiclePtr, this->m_iTraderSettlerId);
    this->m_iTargetCardID = 0;
  }
  if ( this->m_bGoingHome )
  {
    this->m_bGoingHome = 0;
    CDonkeyRole::SetFree(this);
  }
}


// address=[0x156ae00]
// Decompiled from void __thiscall CDonkeyRole::MoveToTarget(CDonkeyRole *this, int _iX, int _iY)
void  CDonkeyRole::MoveToTarget(int _iX, int _iY) {
  
  struct CSettler *SettlerPtr; // [esp+0h] [ebp-8h]

  if ( _iX )
  {
    if ( this->m_iTraderSettlerId )
    {
      SettlerPtr = CSettlerMgr::GetSettlerPtr(&g_cSettlerMgr, this->m_iTraderSettlerId);
      IMovingEntity::WalkToXY(SettlerPtr, _iX, _iY);
      this->m_iTask = 6;
      IMovingEntity::SetDisplacementCosts(SettlerPtr, 5);
      this->Go(this, SettlerPtr);
    }
  }
}


// address=[0x156ae70]
// Decompiled from int __thiscall CDonkeyRole::OwnerId(CDonkeyRole *this)
int  CDonkeyRole::OwnerId(void) {
  
  CSettler *pSettler; // [esp+4h] [ebp-4h]

  pSettler = CSettlerMgr::GetSettlerPtr(&g_cSettlerMgr, this->m_iTraderSettlerId);
  if ( !pSettler && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1221, "pSettler != NULL") == 1 )
    __debugbreak();
  if ( pSettler )
    return IEntity::OwnerId(pSettler);
  else
    return 0;
}


// address=[0x156aed0]
// Decompiled from void __thiscall CDonkeyRole::UpdateCatapultPosition(CDonkeyRole *this, int a2)
void  CDonkeyRole::UpdateCatapultPosition(int a2) {
  
  struct CSettler *SettlerPtr; // [esp+0h] [ebp-8h]

  if ( this->m_uDestinationEntityID )
  {
    SettlerPtr = CSettlerMgr::GetSettlerPtr(&g_cSettlerMgr, this->m_iTraderSettlerId);
    this->m_iDestinationPosition = a2;
    if ( this->m_bGoToTarget )
    {
      IMovingEntity::WalkToXY(SettlerPtr, this->m_iDestinationPosition, 0);
      this->Go(this, SettlerPtr);
    }
  }
}


// address=[0x156af40]
// Decompiled from void __thiscall CDonkeyRole::ComeToBuildUpCart(CDonkeyRole *this, int a2, unsigned int _iCardID)
void  CDonkeyRole::ComeToBuildUpCart(int a2, int _iCardID) {
  
  unsigned int v3; // eax
  std::list *v4; // eax
  CSettler *SettlerPtr; // [esp+0h] [ebp-8h]

  if ( !CMapObjectMgr::ValidEntityId(_iCardID)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1180, "g_pMapObjectMgr->ValidEntityId(_iCardID)") == 1 )
  {
    __debugbreak();
  }
  SettlerPtr = CSettlerMgr::GetSettlerPtr(&g_cSettlerMgr, this->m_iTraderSettlerId);
  v3 = IEntity::Race(SettlerPtr);
  v4 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v3, 0xEDu);
  SettlerPtr->NewToDoList(SettlerPtr, (int)v4, 237);
  this->TakeJob(this, SettlerPtr);
  CDonkeyRole::MoveToTarget(this, a2, 0);
  this->m_iTargetCardID = _iCardID;
  this->m_iJobType = 5;
}


// address=[0x156b000]
// Decompiled from void __thiscall CDonkeyRole::SetJobType(CDonkeyRole *this, int _iJobType)
void  CDonkeyRole::SetJobType(int _iJobType) {
  
  CSettler *v2; // [esp+0h] [ebp-8h]
  CSettler *SettlerPtr; // [esp+0h] [ebp-8h]

  if ( _iJobType )
  {
    if ( _iJobType == 3 || _iJobType == 4 )
    {
      SettlerPtr = CSettlerMgr::GetSettlerPtr(&g_cSettlerMgr, this->m_iTraderSettlerId);
      IMovingEntity::SetDisplacementCosts(SettlerPtr, 10);
    }
  }
  else
  {
    if ( this->m_iTargetBuildingID )
      CDonkeyRole::SetTargetBuildingID(this, 0);
    v2 = CSettlerMgr::GetSettlerPtr(&g_cSettlerMgr, this->m_iTraderSettlerId);
    IMovingEntity::SetDisplacementCosts(v2, 5);
  }
  this->m_iJobType = _iJobType;
}


// address=[0x156b080]
// Decompiled from int __thiscall CDonkeyRole::GetJobType(CDonkeyRole *this)
int  CDonkeyRole::GetJobType(void) {
  
  return this->m_iJobType;
}


// address=[0x156b0a0]
// Decompiled from void __thiscall CDonkeyRole::SetGoToSource(CDonkeyRole *this, bool a2)
void  CDonkeyRole::SetGoToSource(bool a2) {
  
  this->m_bGoToSource = a2;
}


// address=[0x156b0c0]
// Decompiled from void __thiscall CDonkeyRole::SetGoToTarget(CDonkeyRole *this, bool a2)
void  CDonkeyRole::SetGoToTarget(bool a2) {
  
  this->m_bGoToTarget = a2;
}


// address=[0x156b0e0]
// Decompiled from void __thiscall CDonkeyRole::GetNextJob(CDonkeyRole *this, struct CSettler *a2)
void  CDonkeyRole::GetNextJob(class CSettler * a2) {
  
  IMovingEntity::IncToDoListIter(a2);
  if ( IMovingEntity::IsEndIter(a2) )
    CDonkeyRole::SetFree(this);
  else
    this->TakeJob(this, a2);
}


// address=[0x156b120]
// Decompiled from _DWORD *__thiscall CDonkeyRole::FillDialog(CDonkeyRole *this, bool a2)
void  CDonkeyRole::FillDialog(bool a2) {
  
  unsigned int v3; // [esp+4h] [ebp-34h]
  int i; // [esp+Ch] [ebp-2Ch]
  CEvn_Event v6; // [esp+10h] [ebp-28h] BYREF
  int v7; // [esp+34h] [ebp-4h]

  CInfoExchange::Clear(&g_cVehicleLoadInfo);
  for ( i = 0; i < 2; ++i )
  {
    g_cVehicleLoadInfo.m_vSlots[i].m_iGood = this->m_vGoodSlots[i].m_iGood;
    g_cVehicleLoadInfo.m_vSlots[i].m_iAmount = this->m_vGoodSlots[i].m_iAmount;
  }
  g_cVehicleLoadInfo.m_iUnknown = 24;
  v3 = 604;
  if ( !a2 )
    v3 = 602;
  CEvn_Event::CEvn_Event(&v6, v3, 0, (unsigned int)&g_cVehicleLoadInfo, 0);
  v7 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v6);
  v7 = -1;
  return CEvn_Event::~CEvn_Event(&v6);
}


// address=[0x156b210]
// Decompiled from void __thiscall CDonkeyRole::SetNeutralTraderStatus(CDonkeyRole *this, bool a2)
void  CDonkeyRole::SetNeutralTraderStatus(bool a2) {
  
  CSettler *pDonkey; // [esp+0h] [ebp-8h]

  pDonkey = CSettlerMgr::GetSettlerPtr(&g_cSettlerMgr, this->m_iTraderSettlerId);
  if ( !pDonkey && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1606, "pDonkey!=NULL") == 1 )
    __debugbreak();
  if ( pDonkey )
  {
    if ( a2 )
    {
      IEntity::ClearFlagBits(pDonkey, ENTITY_FLAG_VulnerableMask);
      if ( !this->m_iTradingState || this->m_iTradingState == 2 )
      {
        this->m_iTradingState = 1;
        this->m_bIsNeutralTrader = a2;
        return;
      }
      if ( this->m_iTradingState == 1 )
      {
        this->m_iTradingState = 2;
        this->m_bIsNeutralTrader = a2;
        return;
      }
    }
    else
    {
      this->m_iTradingState = 0;
    }
    this->m_bIsNeutralTrader = a2;
  }
}


// address=[0x156b2d0]
// Decompiled from void __thiscall CDonkeyRole::ClearNeutralTraderStatus(CDonkeyRole *this)
void  CDonkeyRole::ClearNeutralTraderStatus(void) {
  
  this->m_bIsNeutralTrader = 0;
  this->m_iTradingState = 0;
}


// address=[0x156b2f0]
// Decompiled from void __thiscall CDonkeyRole::TryToGoHome(CDonkeyRole *this)
void  CDonkeyRole::TryToGoHome(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int v5; // [esp-4h] [ebp-10h]
  struct CSettler *SettlerPtr; // [esp+4h] [ebp-8h]

  if ( this->m_iTraderSettlerId )
  {
    SettlerPtr = CSettlerMgr::GetSettlerPtr(&g_cSettlerMgr, this->m_iTraderSettlerId);
    v5 = Y16X16::UnpackYFast(this->m_iStartPosition);
    v1 = Y16X16::UnpackXFast(this->m_iStartPosition);
    v2 = CWorldManager::Index(v1, v5);
    v3 = CWorldManager::EcoSectorId(v2);
    v4 = IEntity::WorldIdx(SettlerPtr);
    if ( v3 == CWorldManager::EcoSectorId(v4) )
    {
      CDonkeyRole::SetFree(this);
      IAnimatedEntity::SetFrame(SettlerPtr, 1u);
      IMovingEntity::WalkToXY(SettlerPtr, this->m_iStartPosition, 0);
      this->m_iTask = 6;
      IMovingEntity::SetDisplacementCosts(SettlerPtr, 5);
      this->Go(this, SettlerPtr);
      this->m_bGoingHome = 1;
    }
  }
}


// address=[0x156b3c0]
// Decompiled from void __thiscall CDonkeyRole::GoToHomeTradingBuilding(CDonkeyRole *this)
void  CDonkeyRole::GoToHomeTradingBuilding(void) {
  
  struct CBuilding *BuildingPtr; // eax
  struct CBuilding *v2; // eax
  int m_iDepartBuildingID; // [esp+0h] [ebp-10h]
  CSettler *pSettler; // [esp+4h] [ebp-Ch]
  int m_iStartPosition; // [esp+8h] [ebp-8h]

  pSettler = CSettlerMgr::GetSettlerPtr(&g_cSettlerMgr, this->m_iTraderSettlerId);
  if ( !pSettler && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1258, "pSettler!=NULL") == 1 )
    __debugbreak();
  if ( pSettler )
  {
    m_iStartPosition = this->m_iStartPosition;
    if ( this->m_iTradingState == 1 && this->m_iDepartBuildingID )
    {
      BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, this->m_iDepartBuildingID);
      m_iStartPosition = CBuilding::EnsignPackedXY(BuildingPtr);
    }
    if ( this->m_iTradingState == 2 )
    {
      if ( this->m_iTargetBuildingID )
      {
        v2 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, this->m_iTargetBuildingID);
        m_iStartPosition = CBuilding::EnsignPackedXY(v2);
      }
    }
    IMovingEntity::WalkToXY(pSettler, m_iStartPosition, 0);
    m_iDepartBuildingID = this->m_iDepartBuildingID;
    this->m_iDepartBuildingID = this->m_iTargetBuildingID;
    this->m_iTargetBuildingID = m_iDepartBuildingID;
    CDonkeyRole::ClearNeutralTraderStatus(this);
    this->m_bGoingHome = 1;
  }
}


// address=[0x156b4b0]
// Decompiled from CDonkeyRole *__thiscall CDonkeyRole::CDonkeyRole(CDonkeyRole *this, struct std::istream *a1)
 CDonkeyRole::CDonkeyRole(std::istream & a2) {
  
  int a2; // [esp+4h] [ebp-20h] BYREF
  int pExceptionObject; // [esp+8h] [ebp-1Ch] BYREF
  int i; // [esp+Ch] [ebp-18h]
  unsigned int v6; // [esp+10h] [ebp-14h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  ISettlerRole::ISettlerRole(this, a1);
  v8 = 0;
  this->__vftable = (CDonkeyRole_vtbl *)&CDonkeyRole::_vftable_;
  this->m_iRemovedAmount = 0;
  this->m_iTotalAmount = 0;
  this->m_iTradingState = 0;
  this->m_bGoingHome = 0;
  operator^<unsigned int>(a1, &v6);
  if ( !v6 || v6 > 5 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CDonkeyRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a1, &this->m_uCurrentTask);
  operator^<bool>(a1, &this->m_bReturning);
  operator^<bool>(a1, &this->m_bGoToSource);
  operator^<bool>(a1, &this->m_bGoToTarget);
  operator^<int>(a1, &this->m_iTraderSettlerId);
  operator^<int>(a1, &this->m_iTargetBuildingID);
  operator^<int>(a1, &this->m_iDepartBuildingID);
  operator^<int>(a1, &this->m_iTargetCardID);
  operator^<int>(a1, &this->m_iJobType);
  operator^<int>(a1, &this->m_iCargoAmount);
  operator^<unsigned char>(a1, &this->m_uGood);
  operator^<unsigned short>(a1, &this->m_uSourcePileID);
  operator^<unsigned short>(a1, &this->m_uDestinationEntityID);
  for ( i = 0; i < 2; ++i )
  {
    operator^<int>(a1, &this->m_vGoodSlots[i].m_iAmount);
    operator^<int>(a1, &this->m_vGoodSlots[i].m_iU8);
    operator^<int>(a1, &this->m_vGoodSlots[i].m_iGood);
  }
  if ( v6 == 2 )
    operator^<bool>(a1, &this->m_bIsNeutralTrader);
  if ( v6 >= 3 )
  {
    operator^<bool>(a1, &this->m_bIsNeutralTrader);
    operator^<int>(a1, &this->m_iRemovedAmount);
  }
  if ( v6 >= 4 )
  {
    operator^<int>(a1, &a2);
    this->m_iTradingState = a2;
  }
  if ( v6 == 5 )
    operator^<bool>(a1, &this->m_bGoingHome);
  return this;
}


// address=[0x156b770]
// Decompiled from void __thiscall CDonkeyRole::Store(CDonkeyRole *this, struct std::ostream *_rStream)
void  CDonkeyRole::Store(std::ostream & _rStream) {
  
  int m_iTradingState; // [esp+0h] [ebp-10h] BYREF
  unsigned int v3; // [esp+4h] [ebp-Ch] BYREF
  int i; // [esp+8h] [ebp-8h]

  ISettlerRole::Store(this, _rStream);
  v3 = 5;
  operator^<unsigned int>(_rStream, &v3);
  operator^<unsigned char>(_rStream, &this->m_uCurrentTask);
  operator^<bool>(_rStream, &this->m_bReturning);
  operator^<bool>(_rStream, &this->m_bGoToSource);
  operator^<bool>(_rStream, &this->m_bGoToTarget);
  operator^<int>(_rStream, &this->m_iTraderSettlerId);
  operator^<int>(_rStream, &this->m_iTargetBuildingID);
  operator^<int>(_rStream, &this->m_iDepartBuildingID);
  operator^<int>(_rStream, &this->m_iTargetCardID);
  operator^<int>(_rStream, &this->m_iJobType);
  operator^<int>(_rStream, &this->m_iCargoAmount);
  operator^<unsigned char>(_rStream, &this->m_uGood);
  operator^<unsigned short>(_rStream, &this->m_uSourcePileID);
  operator^<unsigned short>(_rStream, &this->m_uDestinationEntityID);
  for ( i = 0; i < 2; ++i )
  {
    operator^<int>(_rStream, &this->m_vGoodSlots[i].m_iAmount);
    operator^<int>(_rStream, &this->m_vGoodSlots[i].m_iU8);
    operator^<int>(_rStream, &this->m_vGoodSlots[i].m_iGood);
  }
  operator^<bool>(_rStream, &this->m_bIsNeutralTrader);
  operator^<int>(_rStream, &this->m_iRemovedAmount);
  m_iTradingState = this->m_iTradingState;
  operator^<int>(_rStream, &m_iTradingState);
  operator^<bool>(_rStream, &this->m_bGoingHome);
}


// address=[0x156cdf0]
// Decompiled from int __thiscall CDonkeyRole::ClassID(CDonkeyRole *this)
unsigned long  CDonkeyRole::ClassID(void)const {
  
  return CDonkeyRole::m_iClassID;
}


// address=[0x156ce10]
// Decompiled from int __thiscall CDonkeyRole::GetSettlerRole(CDonkeyRole *this)
int  CDonkeyRole::GetSettlerRole(void)const {
  
  return 20;
}


// address=[0x156ce30]
// Decompiled from bool __thiscall CDonkeyRole::IsUnEmployed(CDonkeyRole *this)
bool  CDonkeyRole::IsUnEmployed(void)const {
  
  return this->m_iJobType == 0;
}


// address=[0x1588540]
// Decompiled from int __cdecl CDonkeyRole::Load(struct std::istream *a1)
class CDonkeyRole * __cdecl CDonkeyRole::Load(std::istream & a1) {
  
  void **v1; // eax

  v1 = (void **)CPersistence::New(a1);
  return j____RTDynamicCast(v1, 0, &CPersistence__RTTI_Type_Descriptor_, &CDonkeyRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8beb4]
// [Decompilation failed for static unsigned long CDonkeyRole::m_iClassID]

// address=[0x156b950]
// Decompiled from CDonkeyRole *__thiscall CDonkeyRole::CDonkeyRole(CDonkeyRole *this)
 CDonkeyRole::CDonkeyRole(void) {
  
  int i; // [esp+0h] [ebp-8h]

  ISettlerRole::ISettlerRole(this);
  this->__vftable = (CDonkeyRole_vtbl *)&CDonkeyRole::_vftable_;
  this->m_iTargetCardID = 0;
  this->m_iCargoAmount = 0;
  this->m_bIsNeutralTrader = 0;
  this->m_iRemovedAmount = 0;
  this->m_iTotalAmount = 0;
  this->m_iTradingState = 0;
  this->m_bGoingHome = 0;
  this->m_uCurrentTask = 0;
  for ( i = 0; i < 2; ++i )
  {
    this->m_vGoodSlots[i].m_iGood = 0;
    this->m_vGoodSlots[i].m_iAmount = 0;
  }
  this->m_iDepartBuildingID = 0;
  this->m_iTargetBuildingID = 0;
  this->m_uDestinationEntityID = 0;
  this->m_uSourcePileID = 0;
  this->m_iJobType = 0;
  this->m_bGoToSource = 0;
  this->m_bGoToTarget = 0;
  return this;
}


// address=[0x156ba30]
// Decompiled from ISettlerRole *__thiscall CDonkeyRole::~CDonkeyRole(CDonkeyRole *this)
 CDonkeyRole::~CDonkeyRole(void) {
  
  *(_DWORD *)this = &CDonkeyRole::_vftable_;
  return ISettlerRole::~ISettlerRole(this);
}


// address=[0x156ba50]
// Decompiled from void __thiscall CDonkeyRole::TakeJob(CDonkeyRole *this, struct CSettler *_pSettler)
void  CDonkeyRole::TakeJob(class CSettler * _pSettler) {
  
  CEntityTask *ActualTask; // eax
  DWORD v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  struct CBuilding *BuildingPtr; // eax
  int v8; // eax
  IEntity *v9; // eax
  int v10; // eax
  bool IsNeutralTrader; // al
  int v12; // eax
  int v13; // eax
  int v14; // [esp+0h] [ebp-18h]
  IBuildingRole *v15; // [esp+8h] [ebp-10h]
  CBuilding *v16; // [esp+Ch] [ebp-Ch]

  ActualTask = IMovingEntity::GetActualTask(_pSettler);
  ISettlerRole::InitCommonTaskValues(this, _pSettler, ActualTask);
  switch ( this->m_iTask )
  {
    case 0xA:
      IAnimatedEntity::SetFrame(_pSettler, 1u);
      v14 = this->m_iDestinationOffsetX + Y16X16::UnpackXFast(this->m_iDestinationPosition);
      v13 = Y16X16::UnpackYFast(this->m_iDestinationPosition);
      this->m_iDestinationPosition = Y16X16::PackXYFast(v14, this->m_iDestinationOffsetY + v13);
      CDonkeyRole::MoveToTarget(this, this->m_iDestinationPosition, 0);
      this->m_bGoToTarget = 1;
      break;
    case 0xE:
      CDonkeyRole::TryToGoHome(this);
      break;
    case 0x11:
      IMovingEntity::SetDisplacementCosts(_pSettler, 0);
      v3 = CStateGame::Rand(g_pGame);
      IAnimatedEntity::RegisterForLogicUpdate(_pSettler, v3 % 0x10 + 1);
      break;
    case 0x12:
      if ( debug && DEBUG_FLAGS[s_iDebugDonkeyRoleEventSection] )
      {
        v6 = IEntity::ID(_pSettler);
        BBSupportTracePrintF(0, "Carier %u TakeJob go to source pile", v6);
      }
      this->m_iStartPosition = IEntity::PackedXY(_pSettler);
      this->m_bGoToSource = 1;
      this->m_bGoToTarget = 0;
      if ( this->m_iDepartBuildingID )
      {
        BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, this->m_iDepartBuildingID);
        v8 = CBuilding::EnsignPackedXY(BuildingPtr);
        CDonkeyRole::MoveToTarget(this, v8, 0);
      }
      else if ( this->m_uSourcePileID )
      {
        v9 = CMapObjectMgr::EntityPtr(this->m_uSourcePileID);
        v10 = IEntity::PackedXY(v9);
        CDonkeyRole::MoveToTarget(this, v10, 4096);
      }
      break;
    case 0x13:
      this->m_bGoToSource = 0;
      this->m_bGoToTarget = 1;
      if ( this->m_iTargetBuildingID )
      {
        v16 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, this->m_iTargetBuildingID);
        v15 = CBuilding::Role(v16);
        IsNeutralTrader = CDonkeyRole::IsNeutralTrader(this);
        CTradingBuildingRole::RegisterIncomingTrader(
          (CTradingBuildingRole *)v15,
          this->m_iTraderSettlerId,
          2,
          IsNeutralTrader);
        v12 = CBuilding::EnsignPackedXY(v16);
        CDonkeyRole::MoveToTarget(this, v12, 0);
        if ( CDonkeyRole::HasLoadedSomething(this) )
        {
          if ( !CDonkeyRole::IsNeutralTrader(this) )
            IEntity::SetFlagBits(_pSettler, ENTITY_FLAG_VulnerableMask);
        }
      }
      break;
    case 0x15:
      if ( debug && DEBUG_FLAGS[s_iDebugDonkeyRoleEventSection] )
      {
        v4 = IEntity::ID(_pSettler);
        BBSupportTracePrintF(0, "Carier %u TakeJob put_good", v4);
      }
      IMovingEntity::SetDisplacementCosts(_pSettler, 10);
      IEntity::ClearFlagBits(_pSettler, ENTITY_FLAG_VulnerableMask);
      CDonkeyRole::DonkeyArrived(this);
      break;
    case 0x16:
      if ( debug && DEBUG_FLAGS[s_iDebugDonkeyRoleEventSection] )
      {
        v5 = IEntity::ID(_pSettler);
        BBSupportTracePrintF(0, "Carier %u TakeJob get_good", v5);
      }
      IMovingEntity::SetDisplacementCosts(_pSettler, 10);
      CDonkeyRole::DonkeyArrived(this);
      break;
    case 0x17:
      IMovingEntity::SetDisplacementCosts(_pSettler, 10);
      IAnimatedEntity::RegisterForLogicUpdate(_pSettler, this->m_iWalkspeed);
      break;
    case 0x20:
      IAnimatedEntity::RegisterForLogicUpdate(_pSettler, this->m_iWalkspeed / 2 - 1);
      break;
    default:
      CTrace::Print("Donkey TakeJob - unknown job");
      IAnimatedEntity::RegisterForLogicUpdate(_pSettler, 3);
      break;
  }
}


// address=[0x156bdd0]
// Decompiled from void __thiscall CDonkeyRole::Init(CDonkeyRole *this, IEntity *_pSettler)
void  CDonkeyRole::Init(class CSettler * _pSettler) {
  
  if ( IEntity::FlagBits(_pSettler, ENTITY_FLAG_ATTACHED)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 255, "!_pSettler->FlagBits( ENTITY_FLAG_ATTACHED )") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uHomeEntityId
    && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 256, "!m_uHomeEntityId") == 1 )
  {
    __debugbreak();
  }
  this->m_iTraderSettlerId = IEntity::ID(_pSettler);
  CWarMap::AddEntity(_pSettler);
  IEntity::ClearFlagBits(_pSettler, ENTITY_FLAG_VulnerableMask|ENTITY_FLAG_Selectable|ENTITY_FLAG_Selected);
  IEntity::SetFlagBits(_pSettler, (EntityFlag)0x4000);
  this->m_iDepartBuildingID = 0;
  this->m_iTargetBuildingID = 0;
  this->m_iJobType = 0;
}


// address=[0x156be90]
// Decompiled from void __thiscall CDonkeyRole::ConvertEventIntoGoal(CDonkeyRole *this, CSettler *a2, struct CEntityEvent *a3)
void  CDonkeyRole::ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3) {
  
  int v3; // eax
  int v4; // eax
  IEntity *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  std::list *v10; // eax
  int v11; // eax
  T_SETTLER_OBJ_TYPE v12; // eax
  unsigned int v13; // eax
  std::list *v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // [esp-4h] [ebp-3Ch]
  CVehicle *v20; // [esp+0h] [ebp-38h]
  DWORD v21; // [esp+4h] [ebp-34h]
  CBuilding *v22; // [esp+8h] [ebp-30h]
  CBuilding *v23; // [esp+Ch] [ebp-2Ch]
  CVehicle *v24; // [esp+10h] [ebp-28h]
  CPile *v25; // [esp+14h] [ebp-24h]
  CPile *v26; // [esp+18h] [ebp-20h]
  int iPileAmount; // [esp+1Ch] [ebp-1Ch]
  T_SETTLER_OBJ_TYPE v28; // [esp+20h] [ebp-18h]
  CPile *v29; // [esp+28h] [ebp-10h]
  CVehicle *v30; // [esp+2Ch] [ebp-Ch]
  int iAmount; // [esp+30h] [ebp-8h]

  switch ( a3->m_iEvent )
  {
    case 7:
    case 9:
      if ( debug && DEBUG_FLAGS[s_iDebugDonkeyRoleEventSection] )
      {
        v3 = IEntity::ID(a2);
        BBSupportTracePrintF(0, "Donkey %u order canceled - target die", v3);
      }
      if ( this->m_bReturning )
      {
        if ( a3->m_iDataA == this->m_uSourcePileID )
        {
          v26 = CPileMgr::operator[](this->m_uSourcePileID);
          v4 = IEntity::ID(a2);
          v26->Detach(v4);
          this->m_uSourcePileID = 0;
        }
        if ( a3->m_iDataA == this->m_uDestinationEntityID )
        {
          v5 = CMapObjectMgr::EntityPtr(this->m_uDestinationEntityID);
          v28 = IEntity::ObjType(v5);
          if ( v28 == SHIP_OBJ || v28 == CATAPULT_OBJ )
          {
            v24 = CVehicleMgr::operator[](this->m_uDestinationEntityID);
            v7 = IEntity::ID(a2);
            v24->Detach(v24, v7);
          }
          else if ( v28 == PILE_OBJ )
          {
            v25 = CPileMgr::operator[](this->m_uDestinationEntityID);
            v6 = IEntity::ID(a2);
            v25->Detach(v6);
          }
          this->m_uDestinationEntityID = 0;
          CDonkeyRole::TryToGoHome(this);
        }
        this->m_bReturning = 0;
      }
      else if ( a3->m_iDataA == this->m_iTargetBuildingID )
      {
        CDonkeyRole::TargetBuildingDestroyed(this);
      }
      else if ( a3->m_iDataA == this->m_iDepartBuildingID )
      {
        CDonkeyRole::DepartBuildingDestroyed(this);
        IAnimatedEntity::RegisterForLogicUpdate(a2, 1);
      }
      goto LABEL_57;
    case 0xA:
      if ( debug && DEBUG_FLAGS[s_iDebugDonkeyRoleEventSection] )
      {
        v8 = IEntity::ID(a2);
        BBSupportTracePrintF(0, "Donkey %u TRANSPORT_GOOD", v8);
      }
      this->m_bReturning = 0;
      this->m_bGoingHome = 0;
      if ( this->m_iDepartBuildingID && this->m_iTargetBuildingID )
      {
        v23 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iDepartBuildingID);
        v22 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_iTargetBuildingID);
        if ( IEntity::FlagBits(v23, ENTITY_FLAG_AliveMask) && IEntity::FlagBits(v22, ENTITY_FLAG_AliveMask) )
        {
          v9 = IEntity::Race(a2);
          v10 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v9, 0xA3u);
          a2->NewToDoList(a2, (int)v10, 163);
        }
        else
        {
          if ( debug && DEBUG_FLAGS[s_iDebugDonkeyRoleEventSection] )
          {
            v11 = IEntity::ID(a2);
            BBSupportTracePrintF(0, "WARNING: Donkey %u CONV TRANSPORT_GOOD cancled!", v11);
          }
          if ( !IEntity::FlagBits(v23, ENTITY_FLAG_AliveMask) )
            CDonkeyRole::DepartBuildingDestroyed(this);
          if ( !IEntity::FlagBits(v22, ENTITY_FLAG_AliveMask) )
            CDonkeyRole::TargetBuildingDestroyed(this);
        }
      }
      goto LABEL_57;
    case 0xB:
      this->m_bGoToTarget = 0;
      if ( CDonkeyRole::GetJobType(this) && CDonkeyRole::GetJobType(this) != 5 )
      {
        v20 = CVehicleMgr::operator[](a3->m_iDataC);
        v20->EntityOrderCanceled(v20, this->m_uAttachedSettlerId);
LABEL_57:
        if ( IEntity::FlagBits(a2, ENTITY_FLAG_Registered) || !debug )
          return;
        if ( !DEBUG_FLAGS[dword_41520AC] )
          return;
        v18 = IEntity::ID(a2);
        BBSupportTracePrintF(0, "ConvertEvent- not registered settler %u", v18);
        return;
      }
      this->m_uSourcePileID = a3->m_iDataB;
      this->m_uDestinationEntityID = a3->m_iDataC;
      iAmount = a3->m_iDataA;
      this->m_uGood = 0;
      v29 = CPileMgr::operator[](this->m_uSourcePileID);
      v30 = CVehicleMgr::operator[](this->m_uDestinationEntityID);
      iPileAmount = v29->Amount(v29);
      if ( (iAmount <= 0 || iPileAmount < iAmount)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\DonkeyRole.cpp", 1535, "(iAmount>0) && (iPileAmount >= iAmount)") == 1 )
      {
        __debugbreak();
      }
      if ( iPileAmount < iAmount )
        iAmount = iPileAmount;
      if ( !iAmount )
        return;
      v19 = IEntity::ID(a2);
      v12 = IEntity::ObjType(a2);
      v21 = v30->GetMeetingPointXY(v30, v12, v19);
      if ( IEntity::FlagBits(v30, ENTITY_FLAG_AliveMask) && v21 )
      {
        ISettlerRole::NewDestination(this, a2, v21, 0);
        v13 = IEntity::Race(a2);
        v14 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v13, 0xA4u);
        a2->NewToDoList(a2, (int)v14, 164);
        v15 = IEntity::ID(a2);
        CPile::AttachAndIncAmountLeaving(v29, v15, iAmount, 2);
        this->m_iCargoAmount = iAmount;
        v16 = IEntity::ID(a2);
        v30->Attach(v30, v16);
        v17 = v29->GetGoodType();
        v30->GoodIsComming(v30, v17);
        this->m_bReturning = 1;
        CDonkeyRole::SetJobType(this, 1);
      }
      else
      {
        CDonkeyRole::SetFree(this);
      }
      goto LABEL_57;
    default:
      if ( !IEntity::FlagBits(a2, ENTITY_FLAG_Registered) )
      {
        CTrace::Print("ConvertEventIntoGoal DonkeyRole - unknown event %u", a3->m_iEvent);
        IAnimatedEntity::RegisterForLogicUpdate(a2, 1);
      }
      goto LABEL_57;
  }
}


