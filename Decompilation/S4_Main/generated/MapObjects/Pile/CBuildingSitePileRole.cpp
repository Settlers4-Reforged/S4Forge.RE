#if FALSE
#include "CBuildingSitePileRole.h"

// Definitions for class CBuildingSitePileRole

// address=[0x13ffdc0]
// Decompiled from void __cdecl CBuildingSitePileRole::New(struct std::_Facet_base *a1)
class CPersistence * __cdecl CBuildingSitePileRole::New(std::istream & a1) {
  
  CBuildingSitePileRole *C; // [esp+Ch] [ebp-10h]

  C = (CBuildingSitePileRole *)operator new(8u);
  if ( C )
  {
    CBuildingSitePileRole::CBuildingSitePileRole(C, (int)a1);
  }
}


// address=[0x155b3b0]
// Decompiled from void __thiscall CBuildingSitePileRole::Init(CBuildingSitePileRole *this, struct CPile *a2)
void  CBuildingSitePileRole::Init(class CPile * a2) {
  
  IPileRole::Init(this, a2);
  CPile::SetRoleType(a2, 5u);
  CPile::SetOfferFlag(a2, 0);
}


// address=[0x155b3e0]
// Decompiled from void __thiscall CBuildingSitePileRole::Increase(CBuildingSitePileRole *this, CPile *_pPile, int _iAmount)
void  CBuildingSitePileRole::Increase(class CPile * _pPile, int _iAmount) {
  
  int BuildingId; // eax
  CBuilding *v4; // eax
  int v5; // [esp-4h] [ebp-8h]

  if ( !_pPile && BBSupportDbgReport(2, "MapObjects\\Pile\\BuildingSitePileRole.cpp", 141, "_pPile != 0") == 1 )
  {
    __debugbreak();
  }
  if ( _iAmount <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\BuildingSitePileRole.cpp", 142, "_iAmount > 0") == 1 )
  {
    __debugbreak();
  }
  if ( CPile::IsInOfferList(_pPile) && BBSupportDbgReport(2, "MapObjects\\Pile\\BuildingSitePileRole.cpp", 144, "!_pPile->IsInOfferList()") == 1 )
  {
    __debugbreak();
  }
  if ( CPile::GetOfferFlag(_pPile) && BBSupportDbgReport(2, "MapObjects\\Pile\\BuildingSitePileRole.cpp", 145, "!_pPile->GetOfferFlag()") == 1 )
  {
    __debugbreak();
  }
  if ( !CPile::GetBuildingId(_pPile) && BBSupportDbgReport(2, "MapObjects\\Pile\\BuildingSitePileRole.cpp", 146, "_pPile->GetBuildingId() != 0") == 1 )
  {
    __debugbreak();
  }
  v5 = _pPile->GetGoodType();
  BuildingId = CPile::GetBuildingId(_pPile);
  v4 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, BuildingId);
  CBuilding::GoodArrive(v4, v5);
}


// address=[0x155b4f0]
// Decompiled from void __thiscall CBuildingSitePileRole::SubjectStopped(CBuildingSitePileRole *this, struct CPile *_pPile)
void  CBuildingSitePileRole::SubjectStopped(class CPile * _pPile) {
  
  if ( CPile::AmountLeaving(_pPile) && BBSupportDbgReport(2, "MapObjects\\Pile\\BuildingSitePileRole.cpp", 105, "_pPile->AmountLeaving() == 0") == 1 )
  {
    __debugbreak();
  }
  CPile::NotifyTargetDieAndDetachAllObservers(_pPile);
  CPile::SetOfferFlag(_pPile, 1u);
  CPile::OfferCompletePileIfPossible(_pPile, 0);
}


// address=[0x155b550]
// Decompiled from void __thiscall CBuildingSitePileRole::SubjectStarted(CBuildingSitePileRole *this, struct CPile *_pPile)
void  CBuildingSitePileRole::SubjectStarted(class CPile * _pPile) {
  
  if ( CPile::AmountComing(_pPile) && BBSupportDbgReport(2, "MapObjects\\Pile\\BuildingSitePileRole.cpp", 123, "_pPile->AmountComing() == 0") == 1 )
  {
    __debugbreak();
  }
  CPile::NotifyTargetDieAndDetachAllObservers(_pPile);
  CPile::CancelCompleteOfferIfInOfferList(_pPile, 0);
  CPile::SetOfferFlag(_pPile, 0);
}


// address=[0x155b5b0]
// Decompiled from CBuildingSitePileRole *__thiscall CBuildingSitePileRole::CBuildingSitePileRole(CBuildingSitePileRole *this, int a2)
 CBuildingSitePileRole::CBuildingSitePileRole(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  IPileRole::IPileRole(this, a2);
  v6 = 0;
  this->__vftable = (IPileRole_vtbl *)&CBuildingSitePileRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CBuildingSitePileRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v6 = -1;
  return this;
}


// address=[0x155b660]
// Decompiled from void __thiscall CBuildingSitePileRole::Store(CBuildingSitePileRole *this, struct std::ostream *a2)
void  CBuildingSitePileRole::Store(std::ostream & a2) {
  
  int v2; // [esp+0h] [ebp-8h] BYREF

  IPileRole::Store(this, a2);
  v2 = 1;
  operator^<unsigned int>(a2, &v2);
}


// address=[0x155b750]
// Decompiled from IPileRole *__thiscall CBuildingSitePileRole::~CBuildingSitePileRole(CBuildingSitePileRole *this)
 CBuildingSitePileRole::~CBuildingSitePileRole(void) {
  
  return IPileRole::~IPileRole(this);
}


// address=[0x155b7b0]
// Decompiled from int __thiscall CBuildingSitePileRole::ClassID(CBuildingSitePileRole *this)
unsigned long  CBuildingSitePileRole::ClassID(void)const {
  
  return CBuildingSitePileRole::m_iClassID;
}


// address=[0x1560380]
// Decompiled from int __cdecl CBuildingSitePileRole::Load(struct std::istream *a1)
class CBuildingSitePileRole * __cdecl CBuildingSitePileRole::Load(std::istream & a1) {
  
  void **v1; // eax

  v1 = (void **)CPersistence::New(a1);
  return j____RTDynamicCast(v1, 0, &CPersistence__RTTI_Type_Descriptor_, &CBuildingSitePileRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bbb8]
// [Decompilation failed for static unsigned long CBuildingSitePileRole::m_iClassID]

// address=[0x1560140]
// Decompiled from CBuildingSitePileRole *__thiscall CBuildingSitePileRole::CBuildingSitePileRole(CBuildingSitePileRole *this)
 CBuildingSitePileRole::CBuildingSitePileRole(void) {
  
  IPileRole::IPileRole(this);
  this->__vftable = (IPileRole_vtbl *)&CBuildingSitePileRole::_vftable_;
  return this;
}


#endif // Already implemented
