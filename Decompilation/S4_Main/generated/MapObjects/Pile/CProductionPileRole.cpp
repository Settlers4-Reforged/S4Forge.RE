#include "CProductionPileRole.h"

// Definitions for class CProductionPileRole

// address=[0x14018a0]
// Decompiled from void __cdecl CProductionPileRole::New(struct std::_Facet_base *a1)
class CPersistence * __cdecl CProductionPileRole::New(std::istream & a1) {
  
  if ( operator new(8u) )
    CProductionPileRole::CProductionPileRole(a1);
}


// address=[0x1560240]
// Decompiled from void __thiscall CProductionPileRole::~CProductionPileRole(CProductionPileRole *this)
 CProductionPileRole::~CProductionPileRole(void) {
  
  IPileRole::~IPileRole(this);
}


// address=[0x1560300]
// Decompiled from int __thiscall CProductionPileRole::ClassID(CProductionPileRole *this)
unsigned long  CProductionPileRole::ClassID(void)const {
  
  return CProductionPileRole::m_iClassID;
}


// address=[0x1560400]
// Decompiled from int __cdecl CProductionPileRole::Load(int a1)
class CProductionPileRole * __cdecl CProductionPileRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CProductionPileRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x15615d0]
// Decompiled from int __thiscall CProductionPileRole::Init(CProductionPileRole *this, struct CPile *a2)
void  CProductionPileRole::Init(class CPile * a2) {
  
  int v2; // eax
  int v3; // eax
  int result; // eax

  IPileRole::Init(this, a2);
  CPile::SetRoleType(a2, 0);
  CPile::SetOfferFlag(a2, 1);
  CPile::OfferCompletePileIfPossible(a2, 0);
  IAnimatedEntity::RegisterForLogicUpdate(31);
  v2 = IEntity::WorldIdx();
  if ( !CWorldManager::FlagBits(v2, 8u)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Pile\\ProductionPileRole.cpp",
         94,
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
             "MapObjects\\Pile\\ProductionPileRole.cpp",
             95,
             "g_cWorld.EcoSectorId(_pPile->WorldIdx()) > 0");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x1561680]
// Decompiled from int __thiscall CProductionPileRole::LogicUpdate(CProductionPileRole *this, struct CPile *a2)
void  CProductionPileRole::LogicUpdate(class CPile * a2) {
  
  int v2; // eax
  int v3; // eax
  CEcoSector *v4; // eax

  if ( CPile::NumberOfAvailableGoods(a2) < 2 )
    return IAnimatedEntity::RegisterForLogicUpdate(31);
  v2 = IEntity::WorldIdx();
  v3 = CWorldManager::EcoSectorId(v2);
  v4 = (CEcoSector *)CEcoSectorMgr::operator[](v3);
  CEcoSector::RequestSpace(v4, a2);
  return IAnimatedEntity::RegisterForLogicUpdate(31);
}


// address=[0x15616d0]
// Decompiled from void __thiscall CProductionPileRole::Increase(CProductionPileRole *this, struct CPile *a2, int a3)
void  CProductionPileRole::Increase(class CPile * a2, int a3) {
  
  int v3; // eax
  int v4; // eax
  int v5; // [esp+0h] [ebp-8h]

  IPileRole::Increase(this, a2, a3);
  if ( a3 < 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\ProductionPileRole.cpp", 142, "_iAmount >= 0") == 1 )
    __debugbreak();
  if ( a3 > 0 )
  {
    v3 = IEntity::WorldIdx();
    v5 = ITiling::OwnerId(v3);
    v4 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 60))(a2);
    CStatistic::AddProducedGoods((CStatistic *)&g_cStatistic, v5, v4, a3);
  }
}


// address=[0x1561750]
// Decompiled from int __thiscall CProductionPileRole::ReassessDistance(CProductionPileRole *this, struct CPile *a2, int *a3)
void  CProductionPileRole::ReassessDistance(class CPile * a2, int & a3) {
  
  int result; // eax

  result = *a3 / 2;
  *a3 = result;
  return result;
}


// address=[0x1561770]
// Decompiled from _DWORD *__thiscall CProductionPileRole::CProductionPileRole(_DWORD *this, int a2)
 CProductionPileRole::CProductionPileRole(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IPileRole::IPileRole(a2);
  v6 = 0;
  *v5 = &CProductionPileRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CProductionPileRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v6 = -1;
  return v5;
}


// address=[0x1561820]
// Decompiled from int __thiscall CProductionPileRole::Store(void *this, struct std::ostream *a2)
void  CProductionPileRole::Store(std::ostream & a2) {
  
  int v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[1] = (int)this;
  IPileRole::Store(a2);
  v3[0] = 1;
  return operator^<unsigned int>(a2, v3);
}


// address=[0x3d8be98]
// [Decompilation failed for static unsigned long CProductionPileRole::m_iClassID]

// address=[0x15601a0]
// Decompiled from CProductionPileRole *__thiscall CProductionPileRole::CProductionPileRole(CProductionPileRole *this)
 CProductionPileRole::CProductionPileRole(void) {
  
  IPileRole::IPileRole(this);
  *(_DWORD *)this = &CProductionPileRole::_vftable_;
  return this;
}


