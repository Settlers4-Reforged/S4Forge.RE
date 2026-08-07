#if FALSE
#include "CTradePileRole.h"

// Definitions for class CTradePileRole

// address=[0x14023e0]
// Decompiled from CTradePileRole *__cdecl CTradePileRole::New(int a1)
class CPersistence * __cdecl CTradePileRole::New(std::istream & a1) {
  
  CTradePileRole *C; // [esp+Ch] [ebp-10h]

  C = (CTradePileRole *)operator new(0x14u);
  if ( C )
  {
    return CTradePileRole::CTradePileRole(C, a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x1560480]
// Decompiled from int __cdecl CTradePileRole::Load(int a1)
class CTradePileRole * __cdecl CTradePileRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CTradePileRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x1561a70]
// Decompiled from void __thiscall CTradePileRole::Increase(CTradePileRole *this, struct CPile *_pPile, int a3)
void  CTradePileRole::Increase(class CPile * _pPile, int a3) {
  
  int BuildingId; // eax
  CBuilding *v4; // eax
  int v5; // eax
  CBuilding *v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // [esp-8h] [ebp-10h]
  int v10; // [esp-4h] [ebp-Ch]

  if ( !_pPile && BBSupportDbgReport(2, "MapObjects\\Pile\\TradePileRole.cpp", 226, "_pPile") == 1 )
  {
    __debugbreak();
  }
  if ( CTradePileRole::GetTradeRoleType(this) == 1 || CTradePileRole::GetTradeRoleType(this) == 3 )
  {
    v10 = _pPile->GetGoodType();
    BuildingId = CPile::GetBuildingId(_pPile);
    v4 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, BuildingId);
    CBuilding::GoodArrive(v4, v10);
  }
  if ( CTradePileRole::GetTradeRoleType(this) == 2 )
  {
    v9 = _pPile->GetGoodType();
    v5 = CPile::GetBuildingId(_pPile);
    v6 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, v5);
    v7 = IEntity::Type(v6);
    CGameScriptManager::SendGameEvent(g_pScriptMgr, 0x11u, v7, v9, 1);
    v8 = _pPile->Amount(_pPile) - a3;
    if ( v8 == CPile::AmountLeaving(_pPile) && !CPile::GetOfferFlag(_pPile) )
    {
      CPile::Offer(_pPile, 1, 0);
      CPile::SetOfferFlag(_pPile, 1u);
    }
  }
}


// address=[0x1561b70]
// Decompiled from void __thiscall CTradePileRole::Decrease(CTradePileRole *this, struct CPile *_pPile, int a3)
void  CTradePileRole::Decrease(class CPile * _pPile, int a3) {
  
  int BuildingId; // eax
  int v4; // eax
  CTradingBuildingRole *v5; // [esp+0h] [ebp-Ch]
  struct CBuilding *BuildingPtr; // [esp+4h] [ebp-8h]

  if ( !_pPile && BBSupportDbgReport(2, "MapObjects\\Pile\\TradePileRole.cpp", 270, "_pPile") == 1 )
  {
    __debugbreak();
  }
  if ( CTradePileRole::GetTradeRoleType(this) == 1 )
  {
    BuildingId = CPile::GetBuildingId(_pPile);
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, BuildingId);
    v5 = (CTradingBuildingRole *)CBuilding::Role(BuildingPtr);
    v4 = _pPile->GetGoodType();
    CTradingBuildingRole::GoodLeft(v5, v4);
    if ( !_pPile->Amount(_pPile) && !CTradePileRole::GetExpectedAmount(this) && !CPile::AmountComing(_pPile) )
    {
      if ( CPile::GetOfferFlag(_pPile) )
      {
        CPile::CancelOffer(_pPile, 0, 0);
        CPile::SetOfferFlag(_pPile, 0);
      }
      this->m_iTradeRoleType = 0;
      CPile::SetGoodType(_pPile, 0);
    }
  }
  if ( this->m_iTradeRoleType == 4 && _pPile->Amount(_pPile) <= 0 )
  {
    this->m_iReserveAmount = 0;
    this->m_iTradeRoleType = 0;
    CPile::SetGoodType(_pPile, 0);
  }
}


// address=[0x1561c90]
// Decompiled from void __thiscall CTradePileRole::Empty(CTradePileRole *this, struct CPile *a2)
void  CTradePileRole::Empty(class CPile * a2) {
  
  int v2; // eax
  int v3; // [esp-4h] [ebp-14h]
  CEcoSector *v4; // [esp+0h] [ebp-10h]
  CBuilding *v5; // [esp+4h] [ebp-Ch]
  int a1; // [esp+Ch] [ebp-4h]

  if ( !CTradePileRole::GetExpectedAmount(this) && !CPile::AmountComing(a2) )
  {
    if ( CPile::GetOfferFlag(a2) )
    {
      CPile::CancelOffer(a2, 0, 0);
      CPile::SetOfferFlag(a2, 0);
    }
    this->m_iTradeRoleType = 0;
    CPile::SetGoodType(a2, 0);
    a1 = CPile::GetBuildingId(a2);
    if ( a1 > 0 )
    {
      v5 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, a1);
      if ( IEntity::Type(v5) == BUILDING_STORAGEAREA )
      {
        v2 = CBuilding::EcoSectorId(v5);
        v4 = CEcoSectorMgr::operator[](g_cESMgr, v2);
        v3 = IEntity::EntityId(a2);
        CEcoSector::RegisterFreeStoragePile(v4, a1, v3);
      }
    }
  }
}


// address=[0x1561d60]
// Decompiled from void __thiscall CTradePileRole::Init(CTradePileRole *this, CPile *a2)
void  CTradePileRole::Init(class CPile * a2) {
  
  int v2; // eax

  if ( debug && DEBUG_FLAGS[s_iTradePileRoleDebugSection] )
  {
    v2 = IEntity::ID(a2);
    BBSupportTracePrintF(0, "Pile %u init as tradePile", v2);
  }
  this->m_uPileId = IEntity::ID(a2);
  CPile::SetRoleType(a2, 4u);
  IAnimatedEntity::SetNext(a2, 0);
  IAnimatedEntity::SetPrevious(a2, 0);
  CPile::SetOfferFlag(a2, 0);
  this->m_iTradeRoleType = 0;
}


// address=[0x1561de0]
// Decompiled from void __thiscall CTradePileRole::LogicUpdate(CTradePileRole *this, struct CPile *a2)
void  CTradePileRole::LogicUpdate(class CPile * a2) {
  
  int v2; // eax
  int BuildingId; // eax
  struct CBuilding *BuildingPtr; // eax
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // eax
  CEcoSector *v9; // eax
  __int16 v10; // [esp-8h] [ebp-18h]
  int v11; // [esp-4h] [ebp-14h]
  int v12; // [esp+4h] [ebp-Ch]
  struct CBuilding *v13; // [esp+8h] [ebp-8h]

  if ( (CTradePileRole::GetTradeRoleType(this) == 1 || CTradePileRole::GetTradeRoleType(this) == 3) && !CPile::GetOfferFlag(a2) )
  {
    if ( CTradePileRole::GetExpectedAmount(this) )
    {
      v2 = IEntity::WorldIdx(a2);
      v12 = CWorldManager::EcoSectorId(v2);
      BuildingId = CPile::GetBuildingId(a2);
      BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, BuildingId);
      if ( IEntity::FlagBits(BuildingPtr, (EntityFlag)4096) )
      {
        v11 = a2->GetGoodType();
        v10 = CPile::GetBuildingId(a2);
        CEcoSectorMgr::operator[](g_cESMgr, v12);
        CEcoSector::RequestGood(v10, v11);
      }
    }
    IAnimatedEntity::RegisterForLogicUpdate(a2, 31);
  }
  if ( CTradePileRole::GetTradeRoleType(this) == 2 )
  {
    v5 = CPile::GetBuildingId(a2);
    v13 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v5);
    if ( v13 && IEntity::Type(v13) != BUILDING_STORAGEAREA && IEntity::FlagBits(v13, (EntityFlag)4096) )
    {
      v6 = a2->Amount(a2);
      if ( v6 - CPile::AmountLeaving(a2) >= 1 )
      {
        v7 = IEntity::WorldIdx(a2);
        v8 = CWorldManager::EcoSectorId(v7);
        v9 = CEcoSectorMgr::operator[](g_cESMgr, v8);
        CEcoSector::RequestSpace(v9, a2);
      }
    }
    IAnimatedEntity::RegisterForLogicUpdate(a2, 31);
  }
}


// address=[0x1561f40]
// Decompiled from void __thiscall CTradePileRole::Occupied(CTradePileRole *this, struct CPile *a2, int a3)
void  CTradePileRole::Occupied(class CPile * a2, int a3) {
  
  int v3; // esi
  int v4; // esi
  int v5; // eax

  if ( CTradePileRole::GetTradeRoleType(this) == 1 )
  {
    v3 = a2->Amount(a2);
    if ( v3 > CPile::AmountLeaving(a2) && !CPile::GetOfferFlag(a2) )
    {
      v4 = a2->Amount(a2);
      v5 = CPile::AmountLeaving(a2);
      CPile::Offer(a2, v4 - v5, a3);
      CPile::SetOfferFlag(a2, 1u);
    }
  }
}


// address=[0x1561fc0]
// Decompiled from char __thiscall CTradePileRole::SetFree(CTradePileRole *this, CPile *a2, int a3)
bool  CTradePileRole::SetFree(class CPile * a2, int a3) {
  
  int v3; // esi
  int v4; // eax

  if ( CTradePileRole::GetTradeRoleType(this) == 1 )
  {
    v3 = a2->Amount(a2);
    if ( v3 == CPile::AmountLeaving(a2) )
    {
      if ( CPile::GetOfferFlag(a2) )
      {
        CPile::CancelOffer(a2, 0, 0);
        CPile::SetOfferFlag(a2, 0);
      }
    }
  }
  if ( CTradePileRole::GetTradeRoleType(this) != 2 )
  {
    return 0;
  }
  v4 = a2->Amount(a2);
  CPile::CancelOffer(a2, v4, a3);
  CPile::SetOfferFlag(a2, 0);
  return 0;
}


// address=[0x1562050]
// Decompiled from void __thiscall CTradePileRole::NotifyChangeEcoSector(CTradePileRole *this, struct CPile *a2, int a3, int a4)
void  CTradePileRole::NotifyChangeEcoSector(class CPile * a2, int a3, int a4) {
  
  int BuildingId; // eax
  CStorageBuildingRole *v5; // [esp+0h] [ebp-Ch]
  CBuilding *v6; // [esp+8h] [ebp-4h]

  IPileRole::NotifyChangeEcoSector(this, a2, a3, a4);
  BuildingId = CPile::GetBuildingId(a2);
  v6 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, BuildingId);
  if ( IEntity::Type(v6) == 34 )
  {
    v5 = (CStorageBuildingRole *)CBuilding::Role(v6);
    CStorageBuildingRole::NotifyChangeEcoSector(v5, a2, a3, a4);
  }
}


// address=[0x15620c0]
// Decompiled from void __thiscall CTradePileRole::SubjectDie(CTradePileRole *this, struct CPile *_pPile, int a1)
void  CTradePileRole::SubjectDie(class CPile * _pPile, int a1) {
  
  int v3; // eax
  int v4; // eax
  CStorageBuildingRole *v5; // [esp+4h] [ebp-8h]
  CBuilding *v6; // [esp+8h] [ebp-4h]

  if ( CPile::AmountLeaving(_pPile) && BBSupportDbgReport(2, "MapObjects\\Pile\\TradePileRole.cpp", 355, "_pPile->AmountLeaving() == 0") == 1 )
  {
    __debugbreak();
  }
  if ( CPile::AmountComing(_pPile) && BBSupportDbgReport(2, "MapObjects\\Pile\\TradePileRole.cpp", 356, "_pPile->AmountComing() == 0") == 1 )
  {
    __debugbreak();
  }
  if ( a1 > 0 )
  {
    v6 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, a1);
    if ( IEntity::Type(v6) == 34 )
    {
      v5 = (CStorageBuildingRole *)CBuilding::Role(v6);
      v3 = IEntity::ID(_pPile);
      CStorageBuildingRole::UnregisterPile(v5, v3);
    }
  }
  if ( CPile::GetOfferFlag(_pPile) == 1 && _pPile->Amount(_pPile) > 0 )
  {
    v4 = _pPile->Amount(_pPile);
    CPile::CancelOffer(_pPile, v4, 0);
    CPile::SetOfferFlag(_pPile, 0);
  }
  CPile::ChangeRole(_pPile, 3);
}


// address=[0x15621c0]
// Decompiled from void __thiscall CTradePileRole::SubjectStopped(CTradePileRole *this, CPile *a2)
void  CTradePileRole::SubjectStopped(class CPile * a2) {
  
  int v2; // eax

  CPile::NotifyTargetDieAndDetachAllObservers(a2);
  if ( CTradePileRole::GetTradeRoleType(this) == 1 && a2->Amount(a2) > 0 && !CPile::GetOfferFlag(a2) )
  {
    v2 = a2->Amount(a2);
    CPile::Offer(a2, v2, 0);
    CPile::SetOfferFlag(a2, 1u);
  }
}


// address=[0x1562230]
// Decompiled from void __thiscall CTradePileRole::SubjectStarted(CTradePileRole *this, CPile *a2)
void  CTradePileRole::SubjectStarted(class CPile * a2) {
  
  int v2; // eax

  CPile::NotifyTargetDieAndDetachAllObservers(a2);
  if ( CTradePileRole::GetTradeRoleType(this) == 1 && CPile::GetOfferFlag(a2) )
  {
    v2 = a2->Amount(a2);
    CPile::CancelOffer(a2, v2, 0);
    CPile::SetOfferFlag(a2, 0);
  }
  IAnimatedEntity::RegisterForLogicUpdate(a2, 1);
}


// address=[0x1562290]
// Decompiled from char __thiscall CTradePileRole::ChangeGoodTypeUnforseen(CTradePileRole *this, struct CPile *a2, int a3)
bool  CTradePileRole::ChangeGoodTypeUnforseen(class CPile * a2, int a3) {
  
  int BuildingId; // eax
  int v4; // eax
  int v5; // eax
  CTradingBuildingRole *v7; // [esp+0h] [ebp-18h]
  CStorageBuildingRole *v8; // [esp+4h] [ebp-14h]
  int v10; // [esp+Ch] [ebp-Ch]
  CBuilding *v11; // [esp+10h] [ebp-8h]
  char v12; // [esp+17h] [ebp-1h]

  v10 = a2->GetGoodType();
  v12 = IPileRole::ExecuteChangeGoodTypeUnforseen(this, a2, a3);
  BuildingId = CPile::GetBuildingId(a2);
  v11 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, BuildingId);
  if ( IEntity::Type(v11) == 34 )
  {
    v8 = (CStorageBuildingRole *)CBuilding::Role(v11);
    v4 = IEntity::ID(a2);
    CStorageBuildingRole::ExecuteUnforseenGoodTypeChange(v8, v4, v10, a3);
  }
  if ( IEntity::Type(v11) != 33 )
  {
    return v12;
  }
  v7 = (CTradingBuildingRole *)CBuilding::Role(v11);
  v5 = IEntity::ID(a2);
  CTradingBuildingRole::ExecuteUnforseenGoodTypeChange(v7, v5, v10, a3);
  return v12;
}


// address=[0x1562340]
// Decompiled from void __thiscall CTradePileRole::SetTradeRoleType(CTradePileRole *this, int a2)
void  CTradePileRole::SetTradeRoleType(enum CTradePileRole::TRADEPILE_ROLE a2) {
  
  int v2; // esi
  int v3; // eax
  CPile *v4; // [esp+4h] [ebp-Ch]
  CPile *v6; // [esp+Ch] [ebp-4h]

  if ( this->m_iTradeRoleType == 4 )
  {
    this->m_iReserveAmount = 0;
  }
  this->m_iTradeRoleType = a2;
  if ( this->m_iTradeRoleType == 1 || this->m_iTradeRoleType == 3 )
  {
    v6 = CPileMgr::operator[](this->m_uPileId);
    if ( CPile::GetOfferFlag(v6) )
    {
      v2 = v6->Amount(v6);
      if ( v2 > CPile::AmountLeaving(v6) )
      {
        v3 = v6->Amount(v6);
        CPile::CancelOffer(v6, v3, 0);
        CPile::SetOfferFlag(v6, 0);
      }
    }
  }
  if ( this->m_iTradeRoleType == 2 )
  {
    v4 = CPileMgr::operator[](this->m_uPileId);
    if ( v4->Amount(v4) )
    {
      if ( !CPile::GetOfferFlag(v4) )
      {
        CPile::Offer(v4, 1, 0);
        CPile::SetOfferFlag(v4, 1u);
      }
    }
  }
}


// address=[0x1562440]
// Decompiled from int __thiscall CTradePileRole::GetTradeRoleType(CTradePileRole *this)
int  CTradePileRole::GetTradeRoleType(void) {
  
  return this->m_iTradeRoleType;
}


// address=[0x1562460]
// Decompiled from void __thiscall CTradePileRole::SetExpectedAmount(CTradePileRole *this, int a2)
void  CTradePileRole::SetExpectedAmount(int a2) {
  
  this->m_iExpectedAmount = a2;
}


// address=[0x1562480]
// Decompiled from int __thiscall CTradePileRole::GetExpectedAmount(CTradePileRole *this)
int  CTradePileRole::GetExpectedAmount(void) {
  
  return this->m_iExpectedAmount;
}


// address=[0x15624a0]
// Decompiled from void __thiscall CTradePileRole::IncAmoutLeaving(CTradePileRole *this, struct CPile *a2)
void  CTradePileRole::IncAmoutLeaving(class CPile * a2) {
  
  int v2; // esi

  if ( CTradePileRole::GetTradeRoleType(this) == 2 )
  {
    v2 = a2->Amount(a2);
    if ( v2 == CPile::AmountLeaving(a2) )
    {
      if ( CPile::GetOfferFlag(a2) )
      {
        CPile::CancelOffer(a2, 0, 0);
        CPile::SetOfferFlag(a2, 0);
      }
    }
  }
}


// address=[0x1562500]
// Decompiled from void __thiscall CTradePileRole::DecAmountLeaving(CTradePileRole *this, struct CPile *a2)
void  CTradePileRole::DecAmountLeaving(class CPile * a2) {
  
  int v2; // esi

  if ( CTradePileRole::GetTradeRoleType(this) == 2 )
  {
    v2 = a2->Amount(a2);
    if ( v2 == CPile::AmountLeaving(a2) && !CPile::GetOfferFlag(a2) )
    {
      CPile::Offer(a2, 0, 0);
      CPile::SetOfferFlag(a2, 1u);
    }
  }
}


// address=[0x1562560]
// Decompiled from void __thiscall CTradePileRole::IncAmountComing(CTradePileRole *this, struct CPile *a2)
void  CTradePileRole::IncAmountComing(class CPile * a2) {
  
  if ( this->m_iExpectedAmount > 0 )
  {
    --this->m_iExpectedAmount;
  }
}


// address=[0x1562590]
// Decompiled from void __thiscall CTradePileRole::DecAmountComing(CTradePileRole *this, struct CPile *a2)
void  CTradePileRole::DecAmountComing(class CPile * a2) {
  
  int v2; // esi

  v2 = 8 - a2->Amount(a2);
  if ( this->m_iExpectedAmount < v2 - CPile::AmountComing(a2) )
  {
    ++this->m_iExpectedAmount;
  }
}


// address=[0x15625e0]
// Decompiled from int __thiscall CTradePileRole::ReservesGood(CTradePileRole *this, int _iAmount, int a3, CPile *pPile)
int  CTradePileRole::ReservesGood(int _iAmount, enum PILE_TYPES a3, class CPile * pPile) {
  
  int v5; // eax
  int v6; // [esp+0h] [ebp-8h]

  if ( _iAmount < 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\TradePileRole.cpp", 689, "_iAmount >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( !pPile && BBSupportDbgReport(2, "MapObjects\\Pile\\TradePileRole.cpp", 690, "pPile!=NULL") == 1 )
  {
    __debugbreak();
  }
  if ( !pPile )
  {
    return _iAmount;
  }
  if ( CTradePileRole::GetTradeRoleType(this) != 4 && BBSupportDbgReport(2, "MapObjects\\Pile\\TradePileRole.cpp", 691, "this->GetTradeRoleType() == TRADEPILE_EXPORT_RESERVES") == 1 )
  {
    __debugbreak();
  }
  v5 = pPile->Amount(pPile);
  v6 = v5 - this->m_iReserveAmount;
  if ( v6 <= 0 )
  {
    return 0;
  }
  if ( v6 < _iAmount )
  {
    this->m_iReserveAmount = v5;
    return v6;
  }
  else
  {
    this->m_iReserveAmount += _iAmount;
    return _iAmount;
  }
}


// address=[0x15626d0]
// Decompiled from int __thiscall CTradePileRole::GetReserveAmount(CTradePileRole *this)
int  CTradePileRole::GetReserveAmount(void) {
  
  if ( this->m_iTradeRoleType != 4 && BBSupportDbgReport(2, "MapObjects\\Pile\\TradePileRole.cpp", 711, "m_iRoleType == TRADEPILE_EXPORT_RESERVES") == 1 )
  {
    __debugbreak();
  }
  return this->m_iReserveAmount;
}


// address=[0x1562710]
// Decompiled from CTradePileRole *__thiscall CTradePileRole::CTradePileRole(CTradePileRole *this, struct std::istream *a1)
 CTradePileRole::CTradePileRole(std::istream & a2) {
  
  int a2; // [esp+4h] [ebp-1Ch] BYREF
  int pExceptionObject; // [esp+8h] [ebp-18h] BYREF
  unsigned int v5; // [esp+Ch] [ebp-14h] BYREF
  int v7; // [esp+1Ch] [ebp-4h]

  IPileRole::IPileRole(this, (int)a1);
  v7 = 0;
  this->__vftable = (IPileRole_vtbl *)&CTradePileRole::_vftable_;
  this->m_iReserveAmount = 0;
  operator^<unsigned int>(a1, &v5);
  if ( v5 )
  {
    operator^<int>(a1, &a2);
    this->m_iTradeRoleType = a2;
    operator^<int>(a1, &this->m_iExpectedAmount);
    if ( v5 == 1 )
    {
      return this;
    }
  }
  if ( v5 < 2 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CTradePileRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<int>(a1, &this->m_iReserveAmount);
  return this;
}


// address=[0x1562810]
// Decompiled from void __thiscall CTradePileRole::Store(CTradePileRole *this, struct std::ostream *a2)
void  CTradePileRole::Store(std::ostream & a2) {
  
  int m_iTradeRoleType; // [esp+0h] [ebp-Ch] BYREF
  int v3; // [esp+4h] [ebp-8h] BYREF

  IPileRole::Store(this, a2);
  v3 = 2;
  operator^<unsigned int>(a2, &v3);
  m_iTradeRoleType = this->m_iTradeRoleType;
  operator^<int>(a2, &m_iTradeRoleType);
  operator^<int>(a2, &this->m_iExpectedAmount);
  operator^<int>(a2, &this->m_iReserveAmount);
}


// address=[0x1562d70]
// Decompiled from int __thiscall CTradePileRole::ClassID(CTradePileRole *this)
unsigned long  CTradePileRole::ClassID(void)const {
  
  return CTradePileRole::m_iClassID;
}


// address=[0x3d8bea0]
// [Decompilation failed for static unsigned long CTradePileRole::m_iClassID]

// address=[0x1562890]
// Decompiled from CTradePileRole *__thiscall CTradePileRole::CTradePileRole(CTradePileRole *this)
 CTradePileRole::CTradePileRole(void) {
  
  IPileRole::IPileRole(this);
  this->__vftable = (IPileRole_vtbl *)&CTradePileRole::_vftable_;
  this->m_iReserveAmount = 0;
  sub_1562940(s_iTradePileRoleDebugSection);
  this->m_iTradeRoleType = 0;
  this->m_iExpectedAmount = 0;
  return this;
}


// address=[0x1562920]
// Decompiled from IPileRole *__thiscall CTradePileRole::~CTradePileRole(CTradePileRole *this)
 CTradePileRole::~CTradePileRole(void) {
  
  this->__vftable = (IPileRole_vtbl *)&CTradePileRole::_vftable_;
  return IPileRole::~IPileRole(this);
}


#endif // Already implemented
