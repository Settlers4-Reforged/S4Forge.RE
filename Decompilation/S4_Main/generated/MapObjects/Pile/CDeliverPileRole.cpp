#if FALSE
#include "CDeliverPileRole.h"

// Definitions for class CDeliverPileRole

// address=[0x1400400]
// Decompiled from void __cdecl CDeliverPileRole::New(struct std::_Facet_base *a1)
class CPersistence * __cdecl CDeliverPileRole::New(std::istream & a1) {
  
  CDeliverPileRole *C; // [esp+Ch] [ebp-10h]

  C = (CDeliverPileRole *)operator new(8u);
  if ( C )
  {
    CDeliverPileRole::CDeliverPileRole(C, (int)a1);
  }
}


// address=[0x155b880]
// Decompiled from void __thiscall CDeliverPileRole::Init(CDeliverPileRole *this, struct CPile *_pPile)
void  CDeliverPileRole::Init(class CPile * _pPile) {
  
  int v2; // eax
  int v3; // eax

  IPileRole::Init(this, _pPile);
  CPile::SetRoleType(_pPile, 1u);
  CPile::SetOfferFlag(_pPile, 1u);
  v2 = IEntity::WorldIdx(_pPile);
  if ( !CWorldManager::FlagBits(v2, 8u) && BBSupportDbgReport(2, "MapObjects\\Pile\\DeliverPileRole.cpp", 100, "g_cWorld.FlagBits(_pPile->WorldIdx(), FLAG_BUILDING) != 0") == 1 )
  {
    __debugbreak();
  }
  v3 = IEntity::WorldIdx(_pPile);
  if ( CWorldManager::EcoSectorId(v3) <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\DeliverPileRole.cpp", 101, "g_cWorld.EcoSectorId(_pPile->WorldIdx()) > 0") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x155b920]
// Decompiled from void __thiscall CDeliverPileRole::LogicUpdate(CDeliverPileRole *this, struct CPile *a2)
void  CDeliverPileRole::LogicUpdate(class CPile * a2) {
  
  int _pPile; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  __int16 BuildingId; // [esp-8h] [ebp-10h]
  int v7; // [esp-4h] [ebp-Ch]
  int iEcoSectorId; // [esp+4h] [ebp-4h]

  if ( !CPile::GetOfferFlag(a2) )
  {
    if ( !CPile::HasSpace(a2) )
    {
LABEL_11:
      IAnimatedEntity::RegisterForLogicUpdate(a2, 31);
      return;
    }
    _pPile = IEntity::WorldIdx(a2);
    if ( !CWorldManager::FlagBits(_pPile, 8u) && BBSupportDbgReport(2, "MapObjects\\Pile\\DeliverPileRole.cpp", 155, "g_cWorld.FlagBits( _pPile->WorldIdx(), FLAG_BUILDING )") == 1 )
    {
      __debugbreak();
    }
    v3 = IEntity::WorldIdx(a2);
    iEcoSectorId = CWorldManager::EcoSectorId(v3);
    if ( !iEcoSectorId )
    {
      v4 = IEntity::WorldIdx(a2);
      v5 = CWorldManager::FlagBits(v4, 0xFFu);
      if ( BBSupportDbgReportF(2, "MapObjects\\Pile\\DeliverPileRole.cpp", 158, "iEcoSectorId != 0: Flagbits %x", v5) == 1 )
      {
        __debugbreak();
      }
    }
    if ( iEcoSectorId )
    {
      v7 = a2->GetGoodType();
      BuildingId = CPile::GetBuildingId(a2);
      CEcoSectorMgr::operator[](g_cESMgr, iEcoSectorId);
      CEcoSector::RequestGood(BuildingId, v7);
      goto LABEL_11;
    }
  }
}


// address=[0x155ba20]
// Decompiled from void __thiscall CDeliverPileRole::Increase(CDeliverPileRole *this, struct CPile *_pPile, int _iAmount)
void  CDeliverPileRole::Increase(class CPile * _pPile, int _iAmount) {
  
  int BuildingId; // eax
  int v4; // eax
  struct CBuilding *BuildingPtr; // [esp+4h] [ebp-4h]

  if ( !_pPile && BBSupportDbgReport(2, "MapObjects\\Pile\\DeliverPileRole.cpp", 186, "_pPile != 0") == 1 )
  {
    __debugbreak();
  }
  if ( _iAmount <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\DeliverPileRole.cpp", 187, "_iAmount > 0") == 1 )
  {
    __debugbreak();
  }
  if ( !CPile::GetBuildingId(_pPile) && BBSupportDbgReport(2, "MapObjects\\Pile\\DeliverPileRole.cpp", 193, "_pPile->GetBuildingId() != 0") == 1 )
  {
    __debugbreak();
  }
  BuildingId = CPile::GetBuildingId(_pPile);
  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, BuildingId);
  if ( BuildingPtr )
  {
    v4 = _pPile->GetGoodType();
    CBuilding::GoodArrive(BuildingPtr, v4);
  }
}


// address=[0x155bae0]
// Decompiled from void __thiscall CDeliverPileRole::SubjectStopped(CDeliverPileRole *this, CPile *a2)
void  CDeliverPileRole::SubjectStopped(class CPile * a2) {
  
  CPile::NotifyTargetDieAndDetachAllObservers(a2);
  CPile::SetOfferFlag(a2, 1u);
  CPile::OfferCompletePileIfPossible(a2, 0);
}


// address=[0x155bb10]
// Decompiled from void __thiscall CDeliverPileRole::SubjectStarted(CDeliverPileRole *this, CPile *a2)
void  CDeliverPileRole::SubjectStarted(class CPile * a2) {
  
  CPile::NotifyTargetDieAndDetachAllObservers(a2);
  CPile::CancelCompleteOfferIfInOfferList(a2, 0);
  CPile::SetOfferFlag(a2, 0);
  IAnimatedEntity::RegisterForLogicUpdate(a2, 31);
}


// address=[0x155bb50]
// Decompiled from CDeliverPileRole *__thiscall CDeliverPileRole::CDeliverPileRole(CDeliverPileRole *this, int a2)
 CDeliverPileRole::CDeliverPileRole(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  IPileRole::IPileRole(this, a2);
  v6 = 0;
  this->__vftable = (IPileRole_vtbl *)&CDeliverPileRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CDeliverPileRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v6 = -1;
  return this;
}


// address=[0x155bc00]
// Decompiled from int __thiscall CDeliverPileRole::Store(CDeliverPileRole *this, struct std::ostream *a2)
void  CDeliverPileRole::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF

  IPileRole::Store(this, a2);
  v3 = 1;
  return operator^<unsigned int>(a2, &v3);
}


// address=[0x155bd20]
// Decompiled from IPileRole *__thiscall CDeliverPileRole::~CDeliverPileRole(CDeliverPileRole *this)
 CDeliverPileRole::~CDeliverPileRole(void) {
  
  return IPileRole::~IPileRole(this);
}


// address=[0x155bd80]
// Decompiled from int __thiscall CDeliverPileRole::ClassID(CDeliverPileRole *this)
unsigned long  CDeliverPileRole::ClassID(void)const {
  
  return CDeliverPileRole::m_iClassID;
}


// address=[0x15603c0]
// Decompiled from int __cdecl CDeliverPileRole::Load(struct std::istream *a1)
class CDeliverPileRole * __cdecl CDeliverPileRole::Load(std::istream & a1) {
  
  void **v1; // eax

  v1 = (void **)CPersistence::New(a1);
  return j____RTDynamicCast(v1, 0, &CPersistence__RTTI_Type_Descriptor_, &CDeliverPileRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bbbc]
// [Decompilation failed for static unsigned long CDeliverPileRole::m_iClassID]

// address=[0x1560170]
// Decompiled from CDeliverPileRole *__thiscall CDeliverPileRole::CDeliverPileRole(CDeliverPileRole *this)
 CDeliverPileRole::CDeliverPileRole(void) {
  
  IPileRole::IPileRole(this);
  *(_DWORD *)this = &CDeliverPileRole::_vftable_;
  return this;
}


#endif // Already implemented
