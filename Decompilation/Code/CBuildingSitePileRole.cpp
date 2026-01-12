#include "CBuildingSitePileRole.h"

// Definitions for class CBuildingSitePileRole

// address=[0x13ffdc0]
// Decompiled from void __cdecl CBuildingSitePileRole::New(struct std::_Facet_base *a1)
static class CPersistence * __cdecl CBuildingSitePileRole::New(std::istream &) {
  
  if ( operator new(8u) )
    CBuildingSitePileRole::CBuildingSitePileRole(a1);
}


// address=[0x155b3b0]
// Decompiled from CPile *__thiscall CBuildingSitePileRole::Init(CBuildingSitePileRole *this, struct CPile *a2)
void  CBuildingSitePileRole::Init(class CPile *) {
  
  IPileRole::Init(this, a2);
  CPile::SetRoleType(a2, 5);
  return CPile::SetOfferFlag(a2, 0);
}


// address=[0x155b3e0]
// Decompiled from int __thiscall CBuildingSitePileRole::Increase(CBuildingSitePileRole *this, struct CPile *a2, int a3)
void  CBuildingSitePileRole::Increase(class CPile *,int) {
  
  int BuildingId; // eax
  CBuilding *v4; // eax
  int v6; // [esp-4h] [ebp-8h]

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Pile\\BuildingSitePileRole.cpp", 141, "_pPile != 0") == 1 )
    __debugbreak();
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\BuildingSitePileRole.cpp", 142, "_iAmount > 0") == 1 )
    __debugbreak();
  if ( CPile::IsInOfferList(a2)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\BuildingSitePileRole.cpp", 144, "!_pPile->IsInOfferList()") == 1 )
  {
    __debugbreak();
  }
  if ( CPile::GetOfferFlag(a2)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\BuildingSitePileRole.cpp", 145, "!_pPile->GetOfferFlag()") == 1 )
  {
    __debugbreak();
  }
  if ( !CPile::GetBuildingId(a2)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\BuildingSitePileRole.cpp", 146, "_pPile->GetBuildingId() != 0") == 1 )
  {
    __debugbreak();
  }
  v6 = (*(int (__thiscall **)(struct CPile *, CBuildingSitePileRole *))(*(_DWORD *)a2 + 60))(a2, this);
  BuildingId = CPile::GetBuildingId(a2);
  v4 = (CBuilding *)CBuildingMgr::operator[](BuildingId);
  return CBuilding::GoodArrive(v4, v6);
}


// address=[0x155b4f0]
// Decompiled from void __thiscall CBuildingSitePileRole::SubjectStopped(CBuildingSitePileRole *this, struct CPile *a2)
void  CBuildingSitePileRole::SubjectStopped(class CPile *) {
  
  if ( CPile::AmountLeaving(a2)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\BuildingSitePileRole.cpp", 105, "_pPile->AmountLeaving() == 0") == 1 )
  {
    __debugbreak();
  }
  CPile::NotifyTargetDieAndDetachAllObservers(a2);
  CPile::SetOfferFlag(a2, 1);
  CPile::OfferCompletePileIfPossible(a2, 0);
}


// address=[0x155b550]
// Decompiled from CPile *__thiscall CBuildingSitePileRole::SubjectStarted(CBuildingSitePileRole *this, struct CPile *a2)
void  CBuildingSitePileRole::SubjectStarted(class CPile *) {
  
  if ( CPile::AmountComing(a2)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\BuildingSitePileRole.cpp", 123, "_pPile->AmountComing() == 0") == 1 )
  {
    __debugbreak();
  }
  CPile::NotifyTargetDieAndDetachAllObservers(a2);
  CPile::CancelCompleteOfferIfInOfferList(a2, 0);
  return CPile::SetOfferFlag(a2, 0);
}


// address=[0x155b5b0]
// Decompiled from _DWORD *__thiscall CBuildingSitePileRole::CBuildingSitePileRole(_DWORD *this, int a2)
 CBuildingSitePileRole::CBuildingSitePileRole(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IPileRole::IPileRole(a2);
  v6 = 0;
  *v5 = &CBuildingSitePileRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CBuildingSitePileRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v6 = -1;
  return v5;
}


// address=[0x155b660]
// Decompiled from int __thiscall CBuildingSitePileRole::Store(void *this, struct std::ostream *a2)
void  CBuildingSitePileRole::Store(std::ostream &) {
  
  int v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[1] = (int)this;
  IPileRole::Store(a2);
  v3[0] = 1;
  return operator^<unsigned int>(a2, v3);
}


// address=[0x155b750]
// Decompiled from void __thiscall CBuildingSitePileRole::~CBuildingSitePileRole(CBuildingSitePileRole *this)
 CBuildingSitePileRole::~CBuildingSitePileRole(void) {
  
  IPileRole::~IPileRole(this);
}


// address=[0x155b7b0]
// Decompiled from int __thiscall CBuildingSitePileRole::ClassID(CBuildingSitePileRole *this)
unsigned long  CBuildingSitePileRole::ClassID(void)const {
  
  return CBuildingSitePileRole::m_iClassID;
}


// address=[0x1560380]
// Decompiled from int __cdecl CBuildingSitePileRole::Load(int a1)
static class CBuildingSitePileRole * __cdecl CBuildingSitePileRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CBuildingSitePileRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bbb8]
// [Decompilation failed for static unsigned long CBuildingSitePileRole::m_iClassID]

// address=[0x1560140]
// Decompiled from CBuildingSitePileRole *__thiscall CBuildingSitePileRole::CBuildingSitePileRole(CBuildingSitePileRole *this)
 CBuildingSitePileRole::CBuildingSitePileRole(void) {
  
  IPileRole::IPileRole(this);
  *(_DWORD *)this = &CBuildingSitePileRole::_vftable_;
  return this;
}


