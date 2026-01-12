#include "CTradePileRole.h"

// Definitions for class CTradePileRole

// address=[0x14023e0]
// Decompiled from int __cdecl CTradePileRole::New(int a1)
static class CPersistence * __cdecl CTradePileRole::New(std::istream &) {
  
  if ( operator new(0x14u) )
    return CTradePileRole::CTradePileRole(a1);
  else
    return 0;
}


// address=[0x1560480]
// Decompiled from int __cdecl CTradePileRole::Load(int a1)
static class CTradePileRole * __cdecl CTradePileRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CTradePileRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x1561a70]
// Decompiled from char __thiscall CTradePileRole::Increase(CTradePileRole *this, struct CPile *a2, int a3)
void  CTradePileRole::Increase(class CPile *,int) {
  
  int BuildingId; // eax
  CBuilding *v4; // eax
  int TradeRoleType; // eax
  int v6; // eax
  unsigned __int16 *v7; // eax
  int v8; // eax
  int v9; // esi
  int v11; // [esp-8h] [ebp-10h]
  int v12; // [esp-4h] [ebp-Ch]

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Pile\\TradePileRole.cpp", 226, "_pPile") == 1 )
    __debugbreak();
  if ( CTradePileRole::GetTradeRoleType(this) == 1 || CTradePileRole::GetTradeRoleType(this) == 3 )
  {
    v12 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 60))(a2);
    BuildingId = CPile::GetBuildingId(a2);
    v4 = (CBuilding *)CBuildingMgr::operator[](BuildingId);
    CBuilding::GoodArrive(v4, v12);
  }
  TradeRoleType = CTradePileRole::GetTradeRoleType(this);
  if ( TradeRoleType != 2 )
    return TradeRoleType;
  v11 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 60))(a2);
  v6 = CPile::GetBuildingId(a2);
  v7 = (unsigned __int16 *)CBuildingMgr::operator[](v6);
  v8 = IEntity::Type(v7);
  CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 17, v8, v11, 1);
  v9 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 40))(a2) - a3;
  TradeRoleType = CPile::AmountLeaving(a2);
  if ( v9 != TradeRoleType )
    return TradeRoleType;
  LOBYTE(TradeRoleType) = CPile::GetOfferFlag(a2);
  if ( (_BYTE)TradeRoleType )
    return TradeRoleType;
  CPile::Offer(a2, 1, 0);
  LOBYTE(TradeRoleType) = (unsigned __int8)CPile::SetOfferFlag(a2, 1);
  return TradeRoleType;
}


// address=[0x1561b70]
// Decompiled from CPile *__thiscall CTradePileRole::Decrease(CTradePileRole *this, struct CPile *a2, int a3)
void  CTradePileRole::Decrease(class CPile *,int) {
  
  int BuildingId; // eax
  int v4; // eax
  CPile *result; // eax
  CTradingBuildingRole *v6; // [esp+0h] [ebp-Ch]
  unsigned __int8 *BuildingPtr; // [esp+4h] [ebp-8h]

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Pile\\TradePileRole.cpp", 270, "_pPile") == 1 )
    __debugbreak();
  if ( CTradePileRole::GetTradeRoleType(this) == 1 )
  {
    BuildingId = CPile::GetBuildingId(a2);
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, BuildingId);
    v6 = (CTradingBuildingRole *)CBuilding::Role(BuildingPtr);
    v4 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 60))(a2);
    CTradingBuildingRole::GoodLeft(v6, v4);
    if ( !(*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 40))(a2)
      && !CTradePileRole::GetExpectedAmount(this)
      && !CPile::AmountComing(a2) )
    {
      if ( CPile::GetOfferFlag(a2) )
      {
        CPile::CancelOffer(a2, 0, 0);
        CPile::SetOfferFlag(a2, 0);
      }
      *((_DWORD *)this + 2) = 0;
      CPile::SetGoodType(a2, 0);
    }
  }
  result = this;
  if ( *((_DWORD *)this + 2) != 4 )
    return result;
  result = (CPile *)(*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 40))(a2);
  if ( (int)result > 0 )
    return result;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 2) = 0;
  return CPile::SetGoodType(a2, 0);
}


// address=[0x1561c90]
// Decompiled from char __thiscall CTradePileRole::Empty(CTradePileRole *this, struct CPile *a2)
void  CTradePileRole::Empty(class CPile *) {
  
  int ExpectedAmount; // eax
  int v3; // eax
  int v4; // eax
  CEcoSector *v6; // [esp+0h] [ebp-10h]
  unsigned __int16 *v7; // [esp+4h] [ebp-Ch]
  int v9; // [esp+Ch] [ebp-4h]

  ExpectedAmount = CTradePileRole::GetExpectedAmount(this);
  if ( ExpectedAmount )
    return ExpectedAmount;
  ExpectedAmount = CPile::AmountComing(a2);
  if ( ExpectedAmount )
    return ExpectedAmount;
  if ( CPile::GetOfferFlag(a2) )
  {
    CPile::CancelOffer(a2, 0, 0);
    CPile::SetOfferFlag(a2, 0);
  }
  *((_DWORD *)this + 2) = 0;
  CPile::SetGoodType(a2, 0);
  ExpectedAmount = CPile::GetBuildingId(a2);
  v9 = ExpectedAmount;
  if ( ExpectedAmount <= 0 )
    return ExpectedAmount;
  v7 = (unsigned __int16 *)CBuildingMgr::operator[](ExpectedAmount);
  ExpectedAmount = IEntity::Type(v7);
  if ( ExpectedAmount != 34 )
    return ExpectedAmount;
  v3 = CBuilding::EcoSectorId(v7);
  v6 = (CEcoSector *)CEcoSectorMgr::operator[](v3);
  v4 = IEntity::EntityId((unsigned __int16 *)a2);
  LOBYTE(ExpectedAmount) = CEcoSector::RegisterFreeStoragePile(v6, v9, v4);
  return ExpectedAmount;
}


// address=[0x1561d60]
// Decompiled from CPile *__thiscall CTradePileRole::Init(CTradePileRole *this, struct CPile *a2)
void  CTradePileRole::Init(class CPile *) {
  
  int v2; // eax
  CPile *result; // eax

  if ( debug && DEBUG_FLAGS[dword_415208C] )
  {
    v2 = IEntity::ID();
    BBSupportTracePrintF(0, "Pile %u init as tradePile", v2);
  }
  *((_WORD *)this + 2) = IEntity::ID();
  CPile::SetRoleType(a2, 4);
  IAnimatedEntity::SetNext(a2, 0);
  IAnimatedEntity::SetPrevious(a2, 0);
  result = CPile::SetOfferFlag(a2, 0);
  *((_DWORD *)this + 2) = 0;
  return result;
}


// address=[0x1561de0]
// Decompiled from int __thiscall CTradePileRole::LogicUpdate(CTradePileRole *this, struct CPile *a2)
void  CTradePileRole::LogicUpdate(class CPile *) {
  
  int v2; // eax
  int BuildingId; // eax
  unsigned __int8 *BuildingPtr; // eax
  int result; // eax
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax
  CEcoSector *v10; // eax
  __int16 v11; // [esp-8h] [ebp-18h]
  int v12; // [esp-4h] [ebp-14h]
  int v13; // [esp+4h] [ebp-Ch]
  unsigned __int8 *v14; // [esp+8h] [ebp-8h]

  if ( (CTradePileRole::GetTradeRoleType(this) == 1 || CTradePileRole::GetTradeRoleType(this) == 3)
    && !CPile::GetOfferFlag(a2) )
  {
    if ( CTradePileRole::GetExpectedAmount(this) )
    {
      v2 = IEntity::WorldIdx();
      v13 = CWorldManager::EcoSectorId(v2);
      BuildingId = CPile::GetBuildingId(a2);
      BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, BuildingId);
      if ( IEntity::FlagBits(BuildingPtr, (EntityFlag)0x1000u) )
      {
        v12 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 60))(a2);
        v11 = CPile::GetBuildingId(a2);
        CEcoSectorMgr::operator[](v13);
        CEcoSector::RequestGood(v11, v12);
      }
    }
    IAnimatedEntity::RegisterForLogicUpdate(31);
  }
  result = CTradePileRole::GetTradeRoleType(this);
  if ( result != 2 )
    return result;
  v6 = CPile::GetBuildingId(a2);
  v14 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v6);
  if ( !v14 || IEntity::Type((unsigned __int16 *)v14) == 34 || !IEntity::FlagBits(v14, (EntityFlag)0x1000u) )
    return IAnimatedEntity::RegisterForLogicUpdate(31);
  v7 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 40))(a2);
  if ( v7 - CPile::AmountLeaving(a2) < 1 )
    return IAnimatedEntity::RegisterForLogicUpdate(31);
  v8 = IEntity::WorldIdx();
  v9 = CWorldManager::EcoSectorId(v8);
  v10 = (CEcoSector *)CEcoSectorMgr::operator[](v9);
  CEcoSector::RequestSpace(v10, a2);
  return IAnimatedEntity::RegisterForLogicUpdate(31);
}


// address=[0x1561f40]
// Decompiled from char __thiscall CTradePileRole::Occupied(CTradePileRole *this, struct CPile *a2, int a3)
void  CTradePileRole::Occupied(class CPile *,int) {
  
  int TradeRoleType; // eax
  int v4; // esi
  int v5; // esi
  int v6; // eax

  TradeRoleType = CTradePileRole::GetTradeRoleType(this);
  if ( TradeRoleType != 1 )
    return TradeRoleType;
  v4 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 40))(a2);
  TradeRoleType = CPile::AmountLeaving(a2);
  if ( v4 <= TradeRoleType )
    return TradeRoleType;
  LOBYTE(TradeRoleType) = CPile::GetOfferFlag(a2);
  if ( (_BYTE)TradeRoleType )
    return TradeRoleType;
  v5 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 40))(a2);
  v6 = CPile::AmountLeaving(a2);
  CPile::Offer(a2, v5 - v6, a3);
  LOBYTE(TradeRoleType) = (unsigned __int8)CPile::SetOfferFlag(a2, 1);
  return TradeRoleType;
}


// address=[0x1561fc0]
// Decompiled from char __thiscall CTradePileRole::SetFree(CTradePileRole *this, struct CPile *a2, int a3)
bool  CTradePileRole::SetFree(class CPile *,int) {
  
  int v3; // esi
  int v4; // eax

  if ( CTradePileRole::GetTradeRoleType(this) == 1 )
  {
    v3 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 40))(a2);
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
    return 0;
  v4 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 40))(a2);
  CPile::CancelOffer(a2, v4, a3);
  CPile::SetOfferFlag(a2, 0);
  return 0;
}


// address=[0x1562050]
// Decompiled from char __thiscall CTradePileRole::NotifyChangeEcoSector(CTradePileRole *this, struct CPile *a2, int a3, int a4)
void  CTradePileRole::NotifyChangeEcoSector(class CPile *,int,int) {
  
  int BuildingId; // eax
  int v5; // eax
  CStorageBuildingRole *v6; // eax
  unsigned __int16 *v8; // [esp+8h] [ebp-4h]

  IPileRole::NotifyChangeEcoSector(this, a2, a3, a4);
  BuildingId = CPile::GetBuildingId(a2);
  v8 = (unsigned __int16 *)CBuildingMgr::operator[](BuildingId);
  v5 = IEntity::Type(v8);
  if ( v5 != 34 )
    return v5;
  v6 = (CStorageBuildingRole *)CBuilding::Role(v8);
  LOBYTE(v5) = CStorageBuildingRole::NotifyChangeEcoSector(v6, a2, a3, a4);
  return v5;
}


// address=[0x15620c0]
// Decompiled from int __thiscall CTradePileRole::SubjectDie(CTradePileRole *this, struct CPile *a2, int a3)
void  CTradePileRole::SubjectDie(class CPile *,int) {
  
  int v3; // eax
  int v4; // eax
  CStorageBuildingRole *v7; // [esp+4h] [ebp-8h]
  unsigned __int16 *v8; // [esp+8h] [ebp-4h]

  if ( CPile::AmountLeaving(a2)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\TradePileRole.cpp", 355, "_pPile->AmountLeaving() == 0") == 1 )
  {
    __debugbreak();
  }
  if ( CPile::AmountComing(a2)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\TradePileRole.cpp", 356, "_pPile->AmountComing() == 0") == 1 )
  {
    __debugbreak();
  }
  if ( a3 > 0 )
  {
    v8 = (unsigned __int16 *)CBuildingMgr::operator[](a3);
    if ( IEntity::Type(v8) == 34 )
    {
      v7 = (CStorageBuildingRole *)CBuilding::Role(v8);
      v3 = IEntity::ID();
      CStorageBuildingRole::UnregisterPile(v7, v3);
    }
  }
  if ( CPile::GetOfferFlag(a2) != 1
    || (*(int (__thiscall **)(struct CPile *, CTradePileRole *))(*(_DWORD *)a2 + 40))(a2, this) <= 0 )
  {
    return CPile::ChangeRole(a2, 3);
  }
  v4 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 40))(a2);
  CPile::CancelOffer(a2, v4, 0);
  CPile::SetOfferFlag(a2, 0);
  return CPile::ChangeRole(a2, 3);
}


// address=[0x15621c0]
// Decompiled from char __thiscall CTradePileRole::SubjectStopped(CTradePileRole *this, struct CPile *a2)
void  CTradePileRole::SubjectStopped(class CPile *) {
  
  int TradeRoleType; // eax
  int v3; // eax

  CPile::NotifyTargetDieAndDetachAllObservers(a2);
  TradeRoleType = CTradePileRole::GetTradeRoleType(this);
  if ( TradeRoleType != 1 )
    return TradeRoleType;
  TradeRoleType = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 40))(a2);
  if ( TradeRoleType <= 0 )
    return TradeRoleType;
  LOBYTE(TradeRoleType) = CPile::GetOfferFlag(a2);
  if ( (_BYTE)TradeRoleType )
    return TradeRoleType;
  v3 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 40))(a2);
  CPile::Offer(a2, v3, 0);
  LOBYTE(TradeRoleType) = (unsigned __int8)CPile::SetOfferFlag(a2, 1);
  return TradeRoleType;
}


// address=[0x1562230]
// Decompiled from int __thiscall CTradePileRole::SubjectStarted(CTradePileRole *this, struct CPile *a2)
void  CTradePileRole::SubjectStarted(class CPile *) {
  
  int v2; // eax

  CPile::NotifyTargetDieAndDetachAllObservers(a2);
  if ( CTradePileRole::GetTradeRoleType(this) != 1 || !CPile::GetOfferFlag(a2) )
    return IAnimatedEntity::RegisterForLogicUpdate(1);
  v2 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 40))(a2);
  CPile::CancelOffer(a2, v2, 0);
  CPile::SetOfferFlag(a2, 0);
  return IAnimatedEntity::RegisterForLogicUpdate(1);
}


// address=[0x1562290]
// Decompiled from bool __thiscall CTradePileRole::ChangeGoodTypeUnforseen(CTradePileRole *this, struct CPile *a2, int a3)
bool  CTradePileRole::ChangeGoodTypeUnforseen(class CPile *,int) {
  
  int BuildingId; // eax
  int v4; // eax
  int v5; // eax
  CTradingBuildingRole *v7; // [esp+0h] [ebp-18h]
  CStorageBuildingRole *v8; // [esp+4h] [ebp-14h]
  int v10; // [esp+Ch] [ebp-Ch]
  unsigned __int16 *v11; // [esp+10h] [ebp-8h]
  bool v12; // [esp+17h] [ebp-1h]

  v10 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 60))(a2);
  v12 = IPileRole::ExecuteChangeGoodTypeUnforseen(this, a2, a3);
  BuildingId = CPile::GetBuildingId(a2);
  v11 = (unsigned __int16 *)CBuildingMgr::operator[](BuildingId);
  if ( IEntity::Type(v11) == 34 )
  {
    v8 = (CStorageBuildingRole *)CBuilding::Role(v11);
    v4 = IEntity::ID();
    CStorageBuildingRole::ExecuteUnforseenGoodTypeChange(v8, v4, v10, a3);
  }
  if ( IEntity::Type(v11) != 33 )
    return v12;
  v7 = (CTradingBuildingRole *)CBuilding::Role(v11);
  v5 = IEntity::ID();
  CTradingBuildingRole::ExecuteUnforseenGoodTypeChange(v7, v5, v10, a3);
  return v12;
}


// address=[0x1562340]
// Decompiled from char __thiscall CTradePileRole::SetTradeRoleType(int this, int a2)
void  CTradePileRole::SetTradeRoleType(enum CTradePileRole::TRADEPILE_ROLE) {
  
  int v2; // eax
  int v3; // esi
  int v4; // eax
  unsigned __int8 *v6; // [esp+4h] [ebp-Ch]
  unsigned __int8 *v8; // [esp+Ch] [ebp-4h]

  if ( *(_DWORD *)(this + 8) == 4 )
    *(_DWORD *)(this + 16) = 0;
  LOBYTE(v2) = a2;
  *(_DWORD *)(this + 8) = a2;
  if ( *(_DWORD *)(this + 8) == 1 || *(_DWORD *)(this + 8) == 3 )
  {
    v8 = CPileMgr::operator[](*(unsigned __int16 *)(this + 4));
    LOBYTE(v2) = CPile::GetOfferFlag((CPile *)v8);
    if ( (_BYTE)v2 )
    {
      v3 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v8 + 40))(v8);
      v2 = CPile::AmountLeaving((CPile *)v8);
      if ( v3 > v2 )
      {
        v4 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v8 + 40))(v8);
        CPile::CancelOffer((CPile *)v8, v4, 0);
        LOBYTE(v2) = (unsigned __int8)CPile::SetOfferFlag((CPile *)v8, 0);
      }
    }
  }
  if ( *(_DWORD *)(this + 8) != 2 )
    return v2;
  v6 = CPileMgr::operator[](*(unsigned __int16 *)(this + 4));
  v2 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v6 + 40))(v6);
  if ( !v2 )
    return v2;
  LOBYTE(v2) = CPile::GetOfferFlag((CPile *)v6);
  if ( (_BYTE)v2 )
    return v2;
  CPile::Offer((CPile *)v6, 1, 0);
  LOBYTE(v2) = (unsigned __int8)CPile::SetOfferFlag((CPile *)v6, 1);
  return v2;
}


// address=[0x1562440]
// Decompiled from int __thiscall CTradePileRole::GetTradeRoleType(CTradePileRole *this)
int  CTradePileRole::GetTradeRoleType(void) {
  
  return *((_DWORD *)this + 2);
}


// address=[0x1562460]
// Decompiled from void __thiscall CTradePileRole::SetExpectedAmount(CPaneContainer *this, struct CPaneDivider *a2)
void  CTradePileRole::SetExpectedAmount(int) {
  
  *((_DWORD *)this + 3) = a2;
}


// address=[0x1562480]
// Decompiled from int __thiscall CTradePileRole::GetExpectedAmount(pairNode *this)
int  CTradePileRole::GetExpectedAmount(void) {
  
  return *((_DWORD *)this + 3);
}


// address=[0x15624a0]
// Decompiled from char __thiscall CTradePileRole::IncAmoutLeaving(CTradePileRole *this, struct CPile *a2)
void  CTradePileRole::IncAmoutLeaving(class CPile *) {
  
  int TradeRoleType; // eax
  int v3; // esi

  TradeRoleType = CTradePileRole::GetTradeRoleType(this);
  if ( TradeRoleType != 2 )
    return TradeRoleType;
  v3 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 40))(a2);
  TradeRoleType = CPile::AmountLeaving(a2);
  if ( v3 != TradeRoleType )
    return TradeRoleType;
  LOBYTE(TradeRoleType) = CPile::GetOfferFlag(a2);
  if ( !(_BYTE)TradeRoleType )
    return TradeRoleType;
  CPile::CancelOffer(a2, 0, 0);
  LOBYTE(TradeRoleType) = (unsigned __int8)CPile::SetOfferFlag(a2, 0);
  return TradeRoleType;
}


// address=[0x1562500]
// Decompiled from char __thiscall CTradePileRole::DecAmountLeaving(CTradePileRole *this, struct CPile *a2)
void  CTradePileRole::DecAmountLeaving(class CPile *) {
  
  int TradeRoleType; // eax
  int v3; // esi

  TradeRoleType = CTradePileRole::GetTradeRoleType(this);
  if ( TradeRoleType != 2 )
    return TradeRoleType;
  v3 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 40))(a2);
  TradeRoleType = CPile::AmountLeaving(a2);
  if ( v3 != TradeRoleType )
    return TradeRoleType;
  LOBYTE(TradeRoleType) = CPile::GetOfferFlag(a2);
  if ( (_BYTE)TradeRoleType )
    return TradeRoleType;
  CPile::Offer(a2, 0, 0);
  LOBYTE(TradeRoleType) = (unsigned __int8)CPile::SetOfferFlag(a2, 1);
  return TradeRoleType;
}


// address=[0x1562560]
// Decompiled from CTradePileRole *__thiscall CTradePileRole::IncAmountComing(CTradePileRole *this, struct CPile *a2)
void  CTradePileRole::IncAmountComing(class CPile *) {
  
  CTradePileRole *result; // eax

  result = this;
  if ( *((int *)this + 3) <= 0 )
    return result;
  result = this;
  --*((_DWORD *)this + 3);
  return result;
}


// address=[0x1562590]
// Decompiled from int __thiscall CTradePileRole::DecAmountComing(CTradePileRole *this, struct CPile *a2)
void  CTradePileRole::DecAmountComing(class CPile *) {
  
  int v2; // esi
  int result; // eax

  v2 = 8 - (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 40))(a2);
  result = CPile::AmountComing(a2);
  if ( *((_DWORD *)this + 3) >= v2 - result )
    return result;
  result = *((_DWORD *)this + 3) + 1;
  *((_DWORD *)this + 3) = result;
  return result;
}


// address=[0x15625e0]
// Decompiled from int __thiscall CTradePileRole::ReservesGood(_DWORD *this, int a2, int a3, int a4)
int  CTradePileRole::ReservesGood(int,enum PILE_TYPES,class CPile *) {
  
  int v5; // eax
  int v6; // [esp+0h] [ebp-8h]

  if ( a2 < 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\TradePileRole.cpp", 689, "_iAmount >= 0") == 1 )
    __debugbreak();
  if ( !a4 && BBSupportDbgReport(2, "MapObjects\\Pile\\TradePileRole.cpp", 690, "pPile!=NULL") == 1 )
    __debugbreak();
  if ( !a4 )
    return a2;
  if ( CTradePileRole::GetTradeRoleType(this) != 4
    && BBSupportDbgReport(
         2,
         "MapObjects\\Pile\\TradePileRole.cpp",
         691,
         "this->GetTradeRoleType() == TRADEPILE_EXPORT_RESERVES") == 1 )
  {
    __debugbreak();
  }
  v5 = (*(int (__thiscall **)(int))(*(_DWORD *)a4 + 40))(a4);
  v6 = v5 - this[4];
  if ( v6 <= 0 )
    return 0;
  if ( v6 < a2 )
  {
    this[4] = v5;
    return v6;
  }
  else
  {
    this[4] += a2;
    return a2;
  }
}


// address=[0x15626d0]
// Decompiled from int __thiscall CTradePileRole::GetReserveAmount(CTradePileRole *this)
int  CTradePileRole::GetReserveAmount(void) {
  
  if ( *((_DWORD *)this + 2) != 4
    && BBSupportDbgReport(2, "MapObjects\\Pile\\TradePileRole.cpp", 711, "m_iRoleType == TRADEPILE_EXPORT_RESERVES") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 4);
}


// address=[0x1562710]
// Decompiled from _DWORD *__thiscall CTradePileRole::CTradePileRole(_DWORD *this, int a2)
 CTradePileRole::CTradePileRole(std::istream &) {
  
  int v3; // [esp+4h] [ebp-1Ch] BYREF
  int pExceptionObject; // [esp+8h] [ebp-18h] BYREF
  unsigned int v5; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v6; // [esp+10h] [ebp-10h]
  int v7; // [esp+1Ch] [ebp-4h]

  v6 = this;
  IPileRole::IPileRole(a2);
  v7 = 0;
  *v6 = &CTradePileRole::_vftable_;
  v6[4] = 0;
  operator^<unsigned int>(a2, &v5);
  if ( v5 )
  {
    operator^<int>(a2, (int)&v3);
    v6[2] = v3;
    operator^<int>(a2, (int)(v6 + 3));
    if ( v5 == 1 )
      return v6;
  }
  if ( v5 < 2 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CTradePileRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<int>(a2, (int)(v6 + 4));
  return v6;
}


// address=[0x1562810]
// Decompiled from int __thiscall CTradePileRole::Store(_DWORD *this, struct std::ostream *a2)
void  CTradePileRole::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-Ch] BYREF
  int v4; // [esp+4h] [ebp-8h] BYREF
  _DWORD *v5; // [esp+8h] [ebp-4h]

  v5 = this;
  IPileRole::Store(a2);
  v4 = 2;
  operator^<unsigned int>(a2, &v4);
  v3 = v5[2];
  operator^<int>((int)a2, &v3);
  operator^<int>((int)a2, v5 + 3);
  return operator^<int>((int)a2, v5 + 4);
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
  *(_DWORD *)this = &CTradePileRole::_vftable_;
  *((_DWORD *)this + 4) = 0;
  sub_1562940(dword_415208C);
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  return this;
}


// address=[0x1562920]
// Decompiled from void __thiscall CTradePileRole::~CTradePileRole(CTradePileRole *this)
 CTradePileRole::~CTradePileRole(void) {
  
  *(_DWORD *)this = &CTradePileRole::_vftable_;
  IPileRole::~IPileRole(this);
}


