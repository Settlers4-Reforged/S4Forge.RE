#include "IPileRole.h"

// Definitions for class IPileRole

// address=[0x155b1e0]
// Decompiled from IPileRole *__thiscall IPileRole::~IPileRole(IPileRole *this)

 IPileRole::~IPileRole(void) {
  
  IPileRole *result; // eax

  result = this;
  *(_DWORD *)this = &IPileRole::_vftable_;
  return result;
}


// address=[0x155b280]
// Decompiled from char __thiscall IPileRole::ChangeGoodTypeUnforseen(IPileRole *this, struct CPile *a2, int a3)

bool  IPileRole::ChangeGoodTypeUnforseen(class CPile *,int) {
  
  return 0;
}


// address=[0x155b2c0]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall IPileRole::DecAmountComing(IPileRole *this, struct CPile *a2)

void  IPileRole::DecAmountComing(class CPile *) {
  
  ;
}


// address=[0x155b2d0]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall IPileRole::Empty(IPileRole *this, struct CPile *a2)

void  IPileRole::Empty(class CPile *) {
  
  ;
}


// address=[0x155b2e0]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall IPileRole::IncAmountComing(IPileRole *this, struct CPile *a2)

void  IPileRole::IncAmountComing(class CPile *) {
  
  ;
}


// address=[0x155b2f0]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall IPileRole::LogicUpdate(IPileRole *this, struct CPile *a2)

void  IPileRole::LogicUpdate(class CPile *) {
  
  ;
}


// address=[0x155b330]
// Decompiled from void __thiscall IPileRole::ReassessDistance(IPileRole *this, struct CPile *a2, int *a3)

void  IPileRole::ReassessDistance(class CPile *,int &) {
  
  ;
}


// address=[0x1560f00]
// Decompiled from void __thiscall IPileRole::Increase(IPileRole *this, struct CPile *a2, int a3)

void  IPileRole::Increase(class CPile *,int) {
  
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\PileRole.cpp", 123, "_iAmount > 0") == 1 )
    __debugbreak();
  if ( CPile::NumberOfAvailableGoods(a2) <= 0
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileRole.cpp", 124, "_pPile->NumberOfAvailableGoods() > 0") == 1 )
  {
    __debugbreak();
  }
  if ( CPile::IsInOfferList(a2) )
  {
    if ( !CPile::GetOfferFlag(a2)
      && BBSupportDbgReport(2, "MapObjects\\Pile\\PileRole.cpp", 128, "_pPile->GetOfferFlag()") == 1 )
    {
      __debugbreak();
    }
  }
  else if ( CPile::GetOfferFlag(a2) )
  {
    CPile::Offer(a2, a3, 0);
  }
}


// address=[0x1560fc0]
// Decompiled from void __thiscall IPileRole::Decrease(IPileRole *this, struct CPile *a2, int a3)

void  IPileRole::Decrease(class CPile *,int) {
  
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\PileRole.cpp", 150, "_iAmount > 0") == 1 )
    __debugbreak();
  if ( CPile::IsInOfferList(a2) )
  {
    if ( !CPile::GetOfferFlag(a2)
      && BBSupportDbgReport(2, "MapObjects\\Pile\\PileRole.cpp", 154, "_pPile->GetOfferFlag()") == 1 )
    {
      __debugbreak();
    }
    if ( CPile::NumberOfAvailableGoods(a2) <= 0 )
      CPile::CancelOffer(a2, a3, 0);
  }
}


// address=[0x1561050]
// Decompiled from void __thiscall IPileRole::IncAmoutLeaving(IPileRole *this, struct CPile *a2)

void  IPileRole::IncAmoutLeaving(class CPile *) {
  
  if ( CPile::IsInOfferList(a2) )
  {
    if ( !CPile::GetOfferFlag(a2)
      && BBSupportDbgReport(2, "MapObjects\\Pile\\PileRole.cpp", 79, "_pPile->GetOfferFlag()") == 1 )
    {
      __debugbreak();
    }
    if ( CPile::NumberOfAvailableGoods(a2) <= 0 )
      CPile::CancelOffer(a2, 0, 0);
  }
}


// address=[0x15610b0]
// Decompiled from void __thiscall IPileRole::DecAmountLeaving(IPileRole *this, struct CPile *a2)

void  IPileRole::DecAmountLeaving(class CPile *) {
  
  if ( CPile::NumberOfAvailableGoods(a2) <= 0
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileRole.cpp", 98, "_pPile->NumberOfAvailableGoods() > 0") == 1 )
  {
    __debugbreak();
  }
  if ( CPile::IsInOfferList(a2) )
  {
    if ( !CPile::GetOfferFlag(a2)
      && BBSupportDbgReport(2, "MapObjects\\Pile\\PileRole.cpp", 109, "_pPile->GetOfferFlag()") == 1 )
    {
      __debugbreak();
    }
  }
  else if ( CPile::GetOfferFlag(a2) )
  {
    CPile::Offer(a2, 0, 0);
  }
}


// address=[0x1561140]
// Decompiled from int __thiscall IPileRole::Init(IPileRole *this, struct CPile *a2)

void  IPileRole::Init(class CPile *) {
  
  int result; // eax

  result = IEntity::EntityId((unsigned __int16 *)a2);
  *((_WORD *)this + 2) = result;
  return result;
}


// address=[0x1561160]
// Decompiled from int __thiscall IPileRole::Occupied(IPileRole *this, struct CPile *a2, int a3)

void  IPileRole::Occupied(class CPile *,int) {
  
  if ( BBSupportDbgReport(1, "MapObjects\\Pile\\PileRole.cpp", 194, "IPileRole::Occupied() called!") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x1561190]
// Decompiled from char __thiscall IPileRole::SetFree(IPileRole *this, struct CPile *a2, int a3)

bool  IPileRole::SetFree(class CPile *,int) {
  
  void *v3; // eax
  int v4; // eax
  int v6; // [esp-10h] [ebp-14h]
  int v7; // [esp-Ch] [ebp-10h]
  const char *v8; // [esp-8h] [ebp-Ch]
  int v9; // [esp-4h] [ebp-8h]

  v9 = CPile::BuildingId(a2);
  v3 = (void *)j____RTtypeid(this);
  v8 = (const char *)type_info::name(v3);
  v7 = IEntity::Y(a2);
  v6 = IEntity::X(a2);
  v4 = IEntity::EntityId((unsigned __int16 *)a2);
  BBSupportTracePrintF(0, "IPileRole::SetFree(): pile %i, (%i, %i), role %s, building %i", v4, v6, v7, v8, v9);
  if ( BBSupportDbgReport(1, "MapObjects\\Pile\\PileRole.cpp", 207, "IPileRole::SetFree() called!") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x1561210]
// Decompiled from void __thiscall IPileRole::NotifyChangeEcoSector(IPileRole *this, struct CPile *a2, int a3, int a4)

void  IPileRole::NotifyChangeEcoSector(class CPile *,int,int) {
  
  if ( CPile::IsInOfferList(a2) )
  {
    CPile::CancelOffer(a2, -1, a3);
    CPile::Offer(a2, -1, a4);
  }
}


// address=[0x1561250]
// Decompiled from int __thiscall IPileRole::SubjectDie(IPileRole *this, struct CPile *a2, int a3)

void  IPileRole::SubjectDie(class CPile *,int) {
  
  if ( CPile::GetBuildingId(a2)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileRole.cpp", 220, "_pPile->GetBuildingId() == 0") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::FlagBits(a2, Attached)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileRole.cpp", 221, "_pPile->FlagBits(ENTITY_FLAG_ATTACHED) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( CPile::GetRoleType(a2) == 3
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileRole.cpp", 222, "_pPile->GetRoleType() != IPileRole::PILE_ANYWHERE") == 1 )
  {
    __debugbreak();
  }
  if ( CPile::AmountLeaving(a2)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileRole.cpp", 224, "_pPile->AmountLeaving() == 0") == 1 )
  {
    __debugbreak();
  }
  if ( CPile::AmountComing(a2)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileRole.cpp", 225, "_pPile->AmountComing() == 0") == 1 )
  {
    __debugbreak();
  }
  CPile::CancelCompleteOfferIfInOfferList(a2, 0);
  return CPile::ChangeRole(a2, 3);
}


// address=[0x1561350]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall IPileRole::SubjectStopped(IPileRole *this, struct CPile *a2)

void  IPileRole::SubjectStopped(class CPile *) {
  
  ;
}


// address=[0x1561360]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall IPileRole::SubjectStarted(IPileRole *this, struct CPile *a2)

void  IPileRole::SubjectStarted(class CPile *) {
  
  ;
}


// address=[0x1561370]
// Decompiled from _DWORD *__thiscall IPileRole::IPileRole(_DWORD *this, int a2)

 IPileRole::IPileRole(std::istream &) {
  
  int v3; // [esp+4h] [ebp-Ch] BYREF
  int pExceptionObject; // [esp+8h] [ebp-8h] BYREF
  _DWORD *v5; // [esp+Ch] [ebp-4h]

  v5 = this;
  CPersistence::CPersistence(this);
  *v5 = &IPileRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for IPileRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned short>(a2, v5 + 1);
  return v5;
}


// address=[0x15613f0]
// Decompiled from int __thiscall IPileRole::Store(struct CPersistence *this, struct std::ostream *a2)

void  IPileRole::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct CPersistence *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  CPersistence::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  return operator^<unsigned short>((int)a2, (__int16 *)v4 + 2);
}


// address=[0x1561440]
// Decompiled from char __thiscall IPileRole::ExecuteChangeGoodTypeUnforseen(IPileRole *this, struct CPile *a2, int a3)

bool  IPileRole::ExecuteChangeGoodTypeUnforseen(class CPile *,int) {
  
  return CPile::ExecuteChangeGoodTypeUnforseen(a2, a3);
}


// address=[0x1560200]
// Decompiled from IPileRole *__thiscall IPileRole::IPileRole(IPileRole *this)

 IPileRole::IPileRole(void) {
  
  CPersistence::CPersistence(this);
  *(_DWORD *)this = &IPileRole::_vftable_;
  *((_WORD *)this + 2) = 0;
  return this;
}


