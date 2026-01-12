#include "CDeliverPileRole.h"

// Definitions for class CDeliverPileRole

// address=[0x1400400]
// Decompiled from void __cdecl CDeliverPileRole::New(struct std::_Facet_base *a1)

static class CPersistence * __cdecl CDeliverPileRole::New(std::istream &) {
  
  if ( operator new(8u) )
    CDeliverPileRole::CDeliverPileRole(a1);
}


// address=[0x155b880]
// Decompiled from int __thiscall CDeliverPileRole::Init(CDeliverPileRole *this, struct CPile *a2)

void  CDeliverPileRole::Init(class CPile *) {
  
  int v2; // eax
  int v3; // eax
  int result; // eax

  IPileRole::Init(this, a2);
  CPile::SetRoleType(a2, 1);
  CPile::SetOfferFlag(a2, 1);
  v2 = IEntity::WorldIdx();
  if ( !CWorldManager::FlagBits(v2, 8u)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Pile\\DeliverPileRole.cpp",
         100,
         "g_cWorld.FlagBits(_pPile->WorldIdx(), FLAG_BUILDING) != 0") == 1 )
  {
    __debugbreak();
  }
  v3 = IEntity::WorldIdx();
  result = CWorldManager::EcoSectorId(v3);
  if ( result > 0 )
    return result;
  result = BBSupportDbgReport(
             2,
             "MapObjects\\Pile\\DeliverPileRole.cpp",
             101,
             "g_cWorld.EcoSectorId(_pPile->WorldIdx()) > 0");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x155b920]
// Decompiled from int __thiscall CDeliverPileRole::LogicUpdate(CDeliverPileRole *this, struct CPile *a2)

void  CDeliverPileRole::LogicUpdate(class CPile *) {
  
  int result; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  unsigned int v6; // eax
  __int16 BuildingId; // [esp-8h] [ebp-10h]
  int v8; // [esp-4h] [ebp-Ch]
  int v10; // [esp+4h] [ebp-4h]

  result = (unsigned __int8)CPile::GetOfferFlag(a2);
  if ( (_BYTE)result )
    return result;
  if ( !CPile::HasSpace(a2) )
    return IAnimatedEntity::RegisterForLogicUpdate(31);
  v3 = IEntity::WorldIdx();
  if ( !CWorldManager::FlagBits(v3, 8u)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Pile\\DeliverPileRole.cpp",
         155,
         "g_cWorld.FlagBits( _pPile->WorldIdx(), FLAG_BUILDING )") == 1 )
  {
    __debugbreak();
  }
  v4 = IEntity::WorldIdx();
  v10 = CWorldManager::EcoSectorId(v4);
  if ( !v10 )
  {
    v5 = IEntity::WorldIdx();
    v6 = CWorldManager::FlagBits(v5, 0xFFFFFFFF);
    if ( BBSupportDbgReportF(2, "MapObjects\\Pile\\DeliverPileRole.cpp", 158, "iEcoSectorId != 0: Flagbits %x", v6) == 1 )
      __debugbreak();
  }
  result = 0;
  if ( !v10 )
    return result;
  v8 = (*(int (__thiscall **)(struct CPile *, CDeliverPileRole *))(*(_DWORD *)a2 + 60))(a2, this);
  BuildingId = CPile::GetBuildingId(a2);
  CEcoSectorMgr::operator[](v10);
  CEcoSector::RequestGood(BuildingId, v8);
  return IAnimatedEntity::RegisterForLogicUpdate(31);
}


// address=[0x155ba20]
// Decompiled from unsigned __int8 *__thiscall CDeliverPileRole::Increase(CDeliverPileRole *this, struct CPile *a2, int a3)

void  CDeliverPileRole::Increase(class CPile *,int) {
  
  int BuildingId; // eax
  unsigned __int8 *result; // eax
  int v5; // eax
  CBuilding *v7; // [esp+4h] [ebp-4h]

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Pile\\DeliverPileRole.cpp", 186, "_pPile != 0") == 1 )
    __debugbreak();
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\DeliverPileRole.cpp", 187, "_iAmount > 0") == 1 )
    __debugbreak();
  if ( !CPile::GetBuildingId(a2)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\DeliverPileRole.cpp", 193, "_pPile->GetBuildingId() != 0") == 1 )
  {
    __debugbreak();
  }
  BuildingId = CPile::GetBuildingId(a2);
  result = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, BuildingId);
  v7 = (CBuilding *)result;
  if ( !result )
    return result;
  v5 = (*(int (__thiscall **)(struct CPile *, CDeliverPileRole *))(*(_DWORD *)a2 + 60))(a2, this);
  return (unsigned __int8 *)CBuilding::GoodArrive(v7, v5);
}


// address=[0x155bae0]
// Decompiled from void __thiscall CDeliverPileRole::SubjectStopped(CDeliverPileRole *this, struct CPile *a2)

void  CDeliverPileRole::SubjectStopped(class CPile *) {
  
  CPile::NotifyTargetDieAndDetachAllObservers(a2);
  CPile::SetOfferFlag(a2, 1);
  CPile::OfferCompletePileIfPossible(a2, 0);
}


// address=[0x155bb10]
// Decompiled from int __thiscall CDeliverPileRole::SubjectStarted(CDeliverPileRole *this, struct CPile *a2)

void  CDeliverPileRole::SubjectStarted(class CPile *) {
  
  CPile::NotifyTargetDieAndDetachAllObservers(a2);
  CPile::CancelCompleteOfferIfInOfferList(a2, 0);
  CPile::SetOfferFlag(a2, 0);
  return IAnimatedEntity::RegisterForLogicUpdate(31);
}


// address=[0x155bb50]
// Decompiled from _DWORD *__thiscall CDeliverPileRole::CDeliverPileRole(_DWORD *this, int a2)

 CDeliverPileRole::CDeliverPileRole(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IPileRole::IPileRole(a2);
  v6 = 0;
  *v5 = &CDeliverPileRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CDeliverPileRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v6 = -1;
  return v5;
}


// address=[0x155bc00]
// Decompiled from int __thiscall CDeliverPileRole::Store(void *this, struct std::ostream *a2)

void  CDeliverPileRole::Store(std::ostream &) {
  
  int v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[1] = (int)this;
  IPileRole::Store(a2);
  v3[0] = 1;
  return operator^<unsigned int>(a2, v3);
}


// address=[0x155bd20]
// Decompiled from void __thiscall CDeliverPileRole::~CDeliverPileRole(CDeliverPileRole *this)

 CDeliverPileRole::~CDeliverPileRole(void) {
  
  IPileRole::~IPileRole(this);
}


// address=[0x155bd80]
// Decompiled from int __thiscall CDeliverPileRole::ClassID(CDeliverPileRole *this)

unsigned long  CDeliverPileRole::ClassID(void)const {
  
  return CDeliverPileRole::m_iClassID;
}


// address=[0x15603c0]
// Decompiled from int __cdecl CDeliverPileRole::Load(int a1)

static class CDeliverPileRole * __cdecl CDeliverPileRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CDeliverPileRole__RTTI_Type_Descriptor_, 1);
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


