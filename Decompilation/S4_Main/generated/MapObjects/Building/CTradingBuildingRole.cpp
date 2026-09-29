#include "CTradingBuildingRole.h"

// Definitions for class CTradingBuildingRole

// address=[0x1402480]
// Decompiled from int __cdecl CTradingBuildingRole::New(int a1)
class CPersistence * __cdecl CTradingBuildingRole::New(std::istream & a1) {
  
  if ( operator new(0x2B4u) != 0 )
  {
    return ((_DWORD (__stdcall *)(int))CTradingBuildingRole::CTradingBuildingRole)(a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x14fdcb0]
// Decompiled from int __cdecl CTradingBuildingRole::Load(struct std::istream *a1)
class CTradingBuildingRole * __cdecl CTradingBuildingRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)((void **(__cdecl *)(struct std::istream *, struct TypeDescriptor *))CPersistence::New)(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CTradingBuildingRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x151fb00]
// Decompiled from CTradingBuildingRole *__thiscall CTradingBuildingRole::CTradingBuildingRole(CTradingBuildingRole *this)
 CTradingBuildingRole::CTradingBuildingRole(void) {
  
  CInternationalTrader *v2; // [esp+8h] [ebp-18h]
  CInternationalTrader *C; // [esp+Ch] [ebp-14h]

  IBuildingRole::IBuildingRole((IBuildingRole *)this);
  *(_DWORD *)this = &CTradingBuildingRole::_vftable_;
  std::vector<unsigned short>::vector<unsigned short>((char *)this + 608);
  std::vector<CTradingBuildingRole::STradersEx>::vector<CTradingBuildingRole::STradersEx>();
  *((_DWORD *)this + 157) = 0;
  *((_DWORD *)this + 158) = 0;
  *((_BYTE *)this + 636) = 0;
  *((_BYTE *)this + 637) = 0;
  *((_DWORD *)this + 160) = 0;
  *((_DWORD *)this + 161) = 0;
  *((_BYTE *)this + 648) = 0;
  *((_BYTE *)this + 649) = 0;
  *((_DWORD *)this + 163) = 0;
  *((_DWORD *)this + 164) = 0;
  *((_BYTE *)this + 660) = 0;
  *((_BYTE *)this + 661) = 0;
  *((_DWORD *)this + 166) = 0;
  *((_BYTE *)this + 624) = 0;
  ((void (__cdecl *)())std::vector<unsigned short>::clear)();
  *((_WORD *)this + 190) = 0;
  *((_WORD *)this + 191) = 0;
  C = (CInternationalTrader *)operator new(0xCu);
  if ( C != 0 )
  {
    v2 = CInternationalTrader::CInternationalTrader(C);
  }
  else
  {
    v2 = 0;
  }
  *((_DWORD *)this + 171) = v2;
  *((_DWORD *)this + 172) = 0;
  return this;
}


// address=[0x151fca0]
// Decompiled from int __thiscall CTradingBuildingRole::~CTradingBuildingRole(CTradingBuildingRole *this)
 CTradingBuildingRole::~CTradingBuildingRole(void) {
  
  *(_DWORD *)this = &CTradingBuildingRole::_vftable_;
  if ( *((_DWORD *)this + 171) == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 93, "m_pTrader!= NULL") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)this + 171) != 0 )
  {
    delete *((CInternationalTrader **)this + 171);
    *((_DWORD *)this + 171) = 0;
  }
  std::vector<CTradingBuildingRole::STradersEx>::~vector<CTradingBuildingRole::STradersEx>();
  std::vector<unsigned short>::~vector<unsigned short>((char *)this + 608);
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x151fd80]
// Decompiled from void __thiscall CTradingBuildingRole::LogicUpdate(CInternationalTrader **this, struct CBuilding *a2)
void  CTradingBuildingRole::LogicUpdate(class CBuilding * a2) {
  
  IEntity *v2; // eax
  unsigned __int8 *BuildingPtr; // [esp+0h] [ebp-Ch]
  char v4; // [esp+4h] [ebp-8h]

  if ( IEntity::FlagBits(a2, ENTITY_FLAG_Selected) != 0 )
  {
    (*((void (__thiscall **)(CInternationalTrader **, struct CBuilding *, int))*this + 22))(this, a2, 1);
    if ( *((_BYTE *)this + 624) == 0 )
    {
      CTradingBuildingRole::ShowTradeRoute((CTradingBuildingRole *)this);
      *((_BYTE *)this + 624) = 1;
    }
  }
  else if ( *((_BYTE *)this + 624) != 0 )
  {
    IGfxEngine::EnableIconLayer(g_pGfxEngine, 0);
    CWorldManager::ClearHelperObject();
    *((_BYTE *)this + 624) = 0;
  }
  v4 = *((_BYTE *)this + 4);
  switch ( v4 )
  {
    case 1:
      if ( *((_BYTE *)*(this + 94) + 478) != 0 )
      {
        if ( (*((unsigned __int8 (__thiscall **)(CInternationalTrader **, struct CBuilding *))*this + 30))(this, a2) != 0 )
        {
          *((_BYTE *)this + 4) = 3;
          *((_BYTE *)this + 5) = 0;
        }
      }
      else
      {
        *((_BYTE *)this + 4) = 3;
        *((_BYTE *)this + 5) = 0;
      }
      ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(14);
      break;
    case 2:
      *((_BYTE *)this + 5) = 0;
      *((_BYTE *)this + 4) = 3;
      ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(14);
      break;
    case 3:
      *((_BYTE *)this + 5) = 0;
      ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(14);
      break;
    default:
      break;
  }
  v2 = (IEntity *)((IEntity *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 3));
  if ( IEntity::FlagBits(v2, (EntityFlag)4096) != 0 )
  {
    if ( *(this + 171) != 0 )
    {
      BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
      CInternationalTrader::Trade(*(this + 171), (struct CBuilding *)BuildingPtr);
    }
    CTradingBuildingRole::TransportHandling((CTradingBuildingRole *)this, a2);
  }
}


// address=[0x151ff10]
// Decompiled from unsigned int __thiscall CTradingBuildingRole::FillGfxInfo(IBuildingRole *this, struct CBuilding *a2, struct SGfxObjectInfo *a3)
void  CTradingBuildingRole::FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3) {
  
  int v3; // eax
  int v4; // eax
  unsigned int result; // eax
  unsigned __int16 *v6; // eax
  int v7; // [esp-Ch] [ebp-1Ch]
  int v8; // [esp+0h] [ebp-10h]
  CPile *PilePtr; // [esp+4h] [ebp-Ch]
  unsigned int i; // [esp+8h] [ebp-8h]

  this->Update(this, a2);
  v7 = CBuilding::BuildingTypeEx(a2);
  v3 = IEntity::Race(a2);
  ((void (__stdcall *)(int, int, int, int, int))CGfxManager::GetBuildingGfxInfo)((int)a3, v3, v7, 1, (int)this->m_vPatchPairs);
  v4 = IEntity::OwnerId(a2);
  IBuildingRole::MiniFlag(this, a3, v4);
  v8 = 0;
  for ( i = 0;
        ;
        ++i )
  {
    result = std::vector<unsigned short>::size((char *)this + 608);
    if ( i >= result )
    {
      break;
    }
    v6 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
    PilePtr = CPileMgr::GetPilePtr(*v6);
    if ( PilePtr != 0 && CPile::IsPatchPile(PilePtr) )
    {
      CPile::GetPatchGfx(PilePtr, &a3->m_vPatchPiles[v8++]);
    }
  }
  return result;
}


// address=[0x1520000]
// Decompiled from void __thiscall CTradingBuildingRole::Init(CTradingBuildingRole *this, struct CBuilding *a2)
void  CTradingBuildingRole::Init(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // eax
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-34h]
  int v9; // [esp+0h] [ebp-30h]
  int v10; // [esp+4h] [ebp-2Ch]
  int v11; // [esp+8h] [ebp-28h]
  int v12; // [esp+Ch] [ebp-24h]
  int v13; // [esp+10h] [ebp-20h]
  int v14; // [esp+1Ch] [ebp-14h]
  int k; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  int j; // [esp+24h] [ebp-Ch]
  __int16 v19; // [esp+2Eh] [ebp-2h] BYREF

  IBuildingRole::InitCommon(a2);
  for ( i = 0;
        i < 9;
        ++i )
  {
    *((_BYTE *)this + i + 599) = IEntity::OwnerId(a2) == 1;
  }
  for ( j = 0;
        j < 43;
        ++j )
  {
    *((_BYTE *)this + j + 384) = 0;
    *((_BYTE *)this + j + 427) = 0;
    *((_BYTE *)this + j + 470) = 0;
    *((_BYTE *)this + j + 513) = 0;
    *((_BYTE *)this + j + 556) = 0;
  }
  *((_WORD *)this + 190) = 0;
  *((_WORD *)this + 191) = 0;
  for ( k = 0;
        k < *(char *)(*((_DWORD *)this + 94) + 57);
        ++k )
  {
    v2 = ((int (__stdcall *)())IEntity::WorldIdx)();
    v12 = *(char *)(*((_DWORD *)this + 94) + 16 * k + 60) + CWorldManager::X(v2);
    v3 = ((int (__stdcall *)())IEntity::WorldIdx)();
    v13 = *(char *)(*((_DWORD *)this + 94) + 16 * k + 61) + CWorldManager::Y(v3);
    v14 = CPileMgr::AddPile(&g_cPileMgr, v12, v13, 0, 0, *(char *)(*((_DWORD *)this + 94) + 16 * k + 63), *(char *)(*((_DWORD *)this + 94) + 16 * k + 64), *(char *)(*((_DWORD *)this + 94) + 16 * k + 65), *(_DWORD *)(*((_DWORD *)this + 94) + 16 * k + 68), *(_DWORD *)(*((_DWORD *)this + 94) + 16 * k + 72));
    v8 = ((int (__stdcall *)())IEntity::ID)();
    v4 = (unsigned __int8 *)CPileMgr::operator[](v14);
    CPile::SetBuildingId((CPile *)v4, v8);
    if ( *(_BYTE *)(*((_DWORD *)this + 94) + 16 * k + 65) == 1 )
    {
      v5 = (unsigned __int8 *)CPileMgr::operator[](v14);
      IEntity::ClearFlagBits((IEntity *)v5, ENTITY_FLAG_Visible);
    }
    if ( *(_BYTE *)(*((_DWORD *)this + 94) + 16 * k + 63) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 667, "m_pBuildingInfo->piles[p].type == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v19 = v14;
    ((void (__stdcall *)(__int16 *))std::vector<unsigned short>::push_back)(&v19);
  }
  if ( std::vector<unsigned short>::size((char *)this + 608) == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 672, "m_vTradePileId.size()>0") == 1 )
  {
    __debugbreak();
  }
  v6 = ((int (__stdcall *)())IEntity::WorldIdx)();
  v10 = *(char *)(*((_DWORD *)this + 94) + 42) + CWorldManager::X(v6);
  v7 = ((int (__stdcall *)())IEntity::WorldIdx)();
  v11 = *(char *)(*((_DWORD *)this + 94) + 43) + CWorldManager::Y(v7);
  v9 = Y16X16::PackXYFast(v10, v11);
  CBuilding::SetWorkingAreaPackedXY(a2, v9);
  *((_BYTE *)this + 4) = 1;
  if ( IEntity::FlagBits(a2, ENTITY_FLAG_Selected) != 0 )
  {
    (*(void (__thiscall **)(CTradingBuildingRole *, struct CBuilding *, _DWORD))(*(_DWORD *)this + 88))(this, a2, 0);
  }
  ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(14);
  if ( *((_DWORD *)this + 171) == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 693, "m_pTrader!=NULL") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)this + 171) != 0 )
  {
    CInternationalTrader::AddBuilding(*((CInternationalTrader **)this + 171), a2);
  }
}


// address=[0x15203b0]
// Decompiled from void __thiscall CTradingBuildingRole::PostLoadInit(CTradingBuildingRole *this, struct CBuilding *a2)
void  CTradingBuildingRole::PostLoadInit(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // [esp-4h] [ebp-8h]

  v3 = CBuilding::BuildingTypeEx(a2);
  v2 = IEntity::Race(a2);
  *((_DWORD *)this + 94) = CBuildingInfoMgr::GetBuildingInfo(v2, v3);
  if ( *((_DWORD *)this + 171) == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 299, "m_pTrader!=NULL") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)this + 171) != 0 )
  {
    CInternationalTrader::AddBuilding(*((CInternationalTrader **)this + 171), a2);
  }
}


// address=[0x1520430]
// Decompiled from int __thiscall CTradingBuildingRole::Switch(CTradingBuildingRole *this)
void  CTradingBuildingRole::Switch(void) {
  
  IEntity *v1; // eax
  unsigned __int8 *BuildingPtr; // eax
  int v3; // eax
  void *v4; // eax
  int v6; // [esp-4h] [ebp-Ch]
  int v7; // [esp+0h] [ebp-8h]

  IBuildingRole::Switch((unsigned __int16 *)this);
  v1 = (IEntity *)((IEntity *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 3));
  if ( IEntity::FlagBits(v1, (EntityFlag)4096) == 0 )
  {
    CTradingBuildingRole::CancelIncomingChargeTraders(this);
    CTradingBuildingRole::CancelIncomingDeliverTraders(this);
  }
  BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
  v3 = CBuilding::EnsignWorldIdx((CBuilding *)BuildingPtr);
  v7 = CWorldManager::EcoSectorId(v3);
  v6 = *((unsigned __int16 *)this + 3);
  v4 = (void *)((int (__stdcall *)(int))CEcoSectorMgr::operator[])(v7);
  return CEcoSector::CleanUpBuildingNeed(v4, v6);
}


// address=[0x15204c0]
// Decompiled from void __thiscall CTradingBuildingRole::NotifySelected(CTradingBuildingRole *this)
void  CTradingBuildingRole::NotifySelected(void) {
  
  IEntity *v1; // eax

  v1 = (IEntity *)((IEntity *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 3));
  if ( IEntity::FlagBits(v1, ENTITY_FLAG_Selected) != 0 )
  {
    if ( *((_BYTE *)this + 624) == 0 )
    {
      CTradingBuildingRole::ShowTradeRoute(this);
      *((_BYTE *)this + 624) = 1;
    }
  }
  else if ( *((_BYTE *)this + 624) != 0 )
  {
    IGfxEngine::EnableIconLayer(g_pGfxEngine, 0);
    CWorldManager::ClearHelperObject();
    *((_BYTE *)this + 624) = 0;
  }
}


// address=[0x1520540]
// Decompiled from int __thiscall CTradingBuildingRole::GetPileIdWithGood(CTradingBuildingRole *this, unsigned int a2)
int  CTradingBuildingRole::GetPileIdWithGood(int a2)const {
  
  unsigned __int8 *v3; // eax
  int v4; // eax
  unsigned __int16 *v5; // eax
  pairNode *v6; // [esp+0h] [ebp-18h]
  int v7; // [esp+4h] [ebp-14h]
  struct CPile *PilePtr; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  if ( a2 > 0x2A )
  {
    return 0;
  }
  v3 = (unsigned __int8 *)((unsigned __int8 *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 3));
  v4 = IEntity::OwnerId((IEntity *)v3);
  CPlayerManager::Race(v4);
  v7 = CPileMgr::ConvertGoodType(&g_cPileMgr, a2);
  for ( i = 0;
        i < *(char *)(*((_DWORD *)this + 94) + 57);
        ++i )
  {
    v5 = (unsigned __int16 *)((unsigned __int16 *(__stdcall *)(int))std::vector<unsigned short>::operator[])(i);
    PilePtr = CPileMgr::GetPilePtr(*v5);
    v6 = (pairNode *)CPile::Role(PilePtr);
    if ( ((int (__thiscall *)(struct CPile *))PilePtr->GetGoodType)(PilePtr) == v7 && CTradePileRole::GetExpectedAmount((CTradePileRole *)v6) != 0 )
    {
      return *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(int))std::vector<unsigned short>::operator[])(i);
    }
  }
  return 0;
}


// address=[0x1520630]
// Decompiled from int __thiscall CTradingBuildingRole::GetNumberOfFreePiles(CTradingBuildingRole *this)
int  CTradingBuildingRole::GetNumberOfFreePiles(void) {
  
  unsigned __int16 *v1; // eax
  CTradePileRole *v3; // [esp+0h] [ebp-14h]
  struct CPile *PilePtr; // [esp+4h] [ebp-10h]
  int v6; // [esp+Ch] [ebp-8h]
  signed int i; // [esp+10h] [ebp-4h]

  v6 = 0;
  for ( i = 0;
        i < *(char *)(*((_DWORD *)this + 94) + 57);
        ++i )
  {
    v1 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
    PilePtr = CPileMgr::GetPilePtr(*v1);
    v3 = (CTradePileRole *)CPile::Role(PilePtr);
    if ( CTradePileRole::GetTradeRoleType(v3) == 0 )
    {
      ++v6;
    }
  }
  return v6;
}


// address=[0x15206b0]
// Decompiled from char __thiscall CTradingBuildingRole::GoodArrive(_BYTE *this, int a2)
void  CTradingBuildingRole::GoodArrive(int a2) {
  
  char result; // al

  if ( (unsigned __int8)((_DWORD (__stdcall *)(int, int))CTradingBuildingRole::HasGoodState)(a2, 2) != 0 && (char)*(this + a2 + 384) > 0 && *(this + a2 + 384) != 100 )
  {
    --*(this + a2 + 384);
  }
  result = ((_DWORD (__stdcall *)(int, int))CTradingBuildingRole::HasGoodState)(a2, 8);
  if ( result != 0 )
  {
    result = *(this + a2 + 513) - 1;
    *(this + a2 + 513) = result;
  }
  return result;
}


// address=[0x1520740]
// Decompiled from void __thiscall CTradingBuildingRole::GoodLeft(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::GoodLeft(int a2) {
  
  ;
}


// address=[0x1520750]
// Decompiled from signed int __thiscall CTradingBuildingRole::ReservePileForGood(_DWORD *this, int a2, char a3)
void  CTradingBuildingRole::ReservePileForGood(int a2, int a3) {
  
  signed int result; // eax
  unsigned __int16 *v4; // eax
  CTradePileRole *v5; // [esp+0h] [ebp-10h]
  CPile *PilePtr; // [esp+8h] [ebp-8h]
  signed int i; // [esp+Ch] [ebp-4h]

  for ( i = 0;
        ;
        ++i )
  {
    result = *(char *)(*(this + 94) + 57);
    if ( i >= result )
    {
      break;
    }
    if ( *std::vector<unsigned short>::operator[](this + 152, i) == a2 )
    {
      v4 = std::vector<unsigned short>::operator[](this + 152, i);
      PilePtr = CPileMgr::GetPilePtr(*v4);
      if ( CPile::GetRoleType(PilePtr) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 464, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
      {
        __debugbreak();
      }
      v5 = (CTradePileRole *)CPile::Role(PilePtr);
      if ( CTradePileRole::GetTradeRoleType(v5) != 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 467, "rTradePileRole.GetTradeRoleType() == CTradePileRole::TRADEPILE_FREE") == 1 )
      {
        __debugbreak();
      }
      if ( ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr) != 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 468, "pPile->GetGoodType() == 0") == 1 )
      {
        __debugbreak();
      }
      CPile::SetGoodType(PilePtr, a3);
      CTradePileRole::SetTradeRoleType(v5, 1);
    }
  }
  return result;
}


// address=[0x1520880]
// Decompiled from int __thiscall CTradingBuildingRole::GetGoodSpaceAmount(CTradingBuildingRole *this, unsigned int a2)
int  CTradingBuildingRole::GetGoodSpaceAmount(int a2) {
  
  unsigned __int8 *v3; // eax
  int v4; // eax
  unsigned __int16 *v5; // eax
  int v6; // [esp+0h] [ebp-1Ch]
  pairNode *v7; // [esp+8h] [ebp-14h]
  signed int i; // [esp+10h] [ebp-Ch]
  CPile *PilePtr; // [esp+14h] [ebp-8h]
  int v11; // [esp+18h] [ebp-4h]
  int v12; // [esp+18h] [ebp-4h]
  int v13; // [esp+18h] [ebp-4h]

  v11 = 0;
  if ( a2 > 0x2A )
  {
    return 0;
  }
  v3 = (unsigned __int8 *)((unsigned __int8 *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 3));
  v4 = IEntity::OwnerId((IEntity *)v3);
  CPlayerManager::Race(v4);
  v6 = CPileMgr::ConvertGoodType(&g_cPileMgr, a2);
  for ( i = 0;
        i < *(char *)(*((_DWORD *)this + 94) + 57);
        ++i )
  {
    v5 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
    PilePtr = CPileMgr::GetPilePtr(*v5);
    if ( CPile::GetRoleType(PilePtr) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 504, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v7 = (pairNode *)CPile::Role(PilePtr);
    if ( ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr) == v6 )
    {
      v12 = v11 + 8 - CTradePileRole::GetExpectedAmount((CTradePileRole *)v7);
      v13 = v12 - PilePtr->Amount(PilePtr);
      v11 = v13 - CPile::AmountComing(PilePtr);
    }
    if ( CTradePileRole::GetTradeRoleType((CTradePileRole *)v7) == 0 || CTradePileRole::GetTradeRoleType((CTradePileRole *)v7) == 5 )
    {
      v11 += 8;
    }
  }
  return v11;
}


// address=[0x15209e0]
// Decompiled from char __thiscall CTradingBuildingRole::SettlerEnter(CTradingBuildingRole *this, struct CBuilding *a2, __int16 a3)
bool  CTradingBuildingRole::SettlerEnter(class CBuilding * a2, int a3) {
  
  *((_WORD *)this + 4) = a3;
  *((_BYTE *)this + 29) = 1;
  return 1;
}


// address=[0x1520a10]
// Decompiled from void __thiscall CTradingBuildingRole::VehicleArrived(CTradingBuildingRole *this, int a2, int a3)
void  CTradingBuildingRole::VehicleArrived(int a2, int a3) {
  
  if ( a3 == 1 )
  {
    CTradingBuildingRole::ShipArrived(this, a2);
  }
  if ( a3 == 2 )
  {
    CTradingBuildingRole::DonkeyArrived(this, a2);
  }
  if ( a3 == 3 )
  {
    CTradingBuildingRole::CartArrived(this, a2);
  }
}


// address=[0x1520a60]
// Decompiled from void __thiscall CTradingBuildingRole::VehicleArrivedAtTarget(CTradingBuildingRole *this, int a2, int a3)
void  CTradingBuildingRole::VehicleArrivedAtTarget(int a2, int a3) {
  
  if ( a3 == 1 )
  {
    CTradingBuildingRole::ShipArrivedAtTarget(this, a2);
  }
  if ( a3 == 2 )
  {
    CTradingBuildingRole::DonkeyArrivedAtTarget(this, a2);
  }
  if ( a3 == 3 )
  {
    CTradingBuildingRole::CartArrivedAtTarget(this, a2);
  }
}


// address=[0x1520ab0]
// Decompiled from void __thiscall CTradingBuildingRole::VehicleArriveCancel(CTradingBuildingRole *this, int a2, int a3)
void  CTradingBuildingRole::VehicleArriveCancel(int a2, int a3) {
  
  if ( a3 == 1 )
  {
    CTradingBuildingRole::ShipArriveCancel(this, a2);
  }
  if ( a3 == 2 )
  {
    CTradingBuildingRole::DonkeyArriveCancel(this, a2);
  }
  if ( a3 == 3 )
  {
    CTradingBuildingRole::CartArriveCancel(this, a2);
  }
}


// address=[0x1520b00]
// Decompiled from bool __thiscall CTradingBuildingRole::IsPossibleTradeTarget(CTradingBuildingRole *this, int a2)
bool  CTradingBuildingRole::IsPossibleTradeTarget(int a2) {
  
  int v3; // eax
  int v4; // eax
  Y16X16 *v5; // eax
  Y16X16 *v6; // eax
  int v7; // [esp-4h] [ebp-2Ch]
  int v8; // [esp-4h] [ebp-2Ch]
  int v9; // [esp+4h] [ebp-24h]
  int v10; // [esp+8h] [ebp-20h] BYREF
  int v11; // [esp+Ch] [ebp-1Ch] BYREF
  int v12; // [esp+10h] [ebp-18h] BYREF
  int v13; // [esp+14h] [ebp-14h] BYREF
  CTradingBuildingRole *v14; // [esp+18h] [ebp-10h]
  unsigned __int8 *v15; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 *BuildingPtr; // [esp+20h] [ebp-8h]
  unsigned __int8 *v17; // [esp+24h] [ebp-4h]

  v14 = this;
  v17 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(a2);
  if ( IEntity::ObjType((IEntity *)v17) != BUILDING_OBJ )
  {
    return 0;
  }
  BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)v14 + 3));
  v15 = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a2);
  if ( IEntity::FlagBits((IEntity *)v15, (EntityFlag)((char *)&loc_1FFFFFF + 1)) == 0 || IEntity::FlagBits((IEntity *)BuildingPtr, (EntityFlag)((char *)&loc_1FFFFFF + 1)) == 0 )
  {
    return 0;
  }
  v7 = IEntity::Y(BuildingPtr);
  v3 = IEntity::X(BuildingPtr);
  if ( !g_pFogging->IsPositionVisible(g_pFogging, v3, v7) )
  {
    return 0;
  }
  v8 = IEntity::Y(v17);
  v4 = IEntity::X(v17);
  if ( !g_pFogging->IsPositionVisible(g_pFogging, v4, v8) )
  {
    return 0;
  }
  if ( IEntity::Type((IEntity *)v17) == 32 && IEntity::Type((IEntity *)BuildingPtr) == 32 )
  {
    return 1;
  }
  if ( IEntity::Type((IEntity *)v17) != 32 && IEntity::Type((IEntity *)v17) != 33 )
  {
    return 0;
  }
  v5 = (Y16X16 *)CBuilding::EnsignPackedXY(BuildingPtr);
  Y16X16::UnpackXYFast((int)v5, &v12, &v13);
  v6 = (Y16X16 *)CBuilding::EnsignPackedXY(v15);
  Y16X16::UnpackXYFast((int)v6, &v10, &v11);
  v9 = CWorldManager::SectorId(v12, v13);
  return v9 == CWorldManager::SectorId(v10, v11);
}


// address=[0x1520c90]
// Decompiled from void __thiscall CTradingBuildingRole::SetTradeTarget(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::SetTradeTarget(int a2) {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax
  int v4; // eax
  int v5; // [esp+4h] [ebp-Ch]
  unsigned __int8 *BuildingPtr; // [esp+8h] [ebp-8h]

  v2 = (unsigned __int16 *)((unsigned __int16 *(__stdcall *)(int))CBuildingMgr::operator[])(a2);
  if ( IEntity::Type((IEntity *)v2) != 32 )
  {
    v3 = (unsigned __int16 *)((unsigned __int16 *(__stdcall *)(int))CBuildingMgr::operator[])(a2);
    if ( IEntity::Type((IEntity *)v3) != 33 && BBSupportDbgReportF(2, "MapObjects\\Building\\TradingBuilding.cpp", 894, "Target is no trading building!") == 1 )
    {
      __debugbreak();
    }
  }
  if ( *((_WORD *)this + 190) != 0 )
  {
    v5 = ((int (__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 190));
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v5 + 64))(v5, *((unsigned __int16 *)this + 3));
  }
  if ( *((unsigned __int16 *)this + 3) == a2 )
  {
    *((_WORD *)this + 190) = 0;
    CTradingBuildingRole::CancelIncomingChargeTraders(this);
    CTradingBuildingRole::SetNewTraderTarget((struct CWnd *)*((unsigned __int16 *)this + 190));
  }
  else
  {
    *((_WORD *)this + 190) = a2;
    CTradingBuildingRole::SetNewTraderTarget((struct CWnd *)*((unsigned __int16 *)this + 190));
    v4 = ((int (__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 190));
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 116))(v4, *((unsigned __int16 *)this + 3));
    BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
    if ( BuildingPtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 907, "pBulding!=NULL") == 1 )
    {
      __debugbreak();
    }
    if ( BuildingPtr != 0 && IEntity::IsSelected((IEntity *)BuildingPtr) )
    {
      CTradingBuildingRole::ShowTradeRoute(this);
    }
  }
}


// address=[0x1520e10]
// Decompiled from int __thiscall CTradingBuildingRole::GetTradeTargetID(CTradingBuildingRole *this)
int  CTradingBuildingRole::GetTradeTargetID(void) {
  
  return *((unsigned __int16 *)this + 190);
}


// address=[0x1520e30]
// Decompiled from void __thiscall CTradingBuildingRole::TransportGood(CTradingBuildingRole *this, int a2, int a3)
void  CTradingBuildingRole::TransportGood(int a2, int a3) {
  
  IEntity *v3; // eax
  IEntity *v4; // eax
  IEntity *v5; // eax

  if ( a3 != 0 )
  {
    if ( a3 == 100 )
    {
      CTradingBuildingRole::SetGoodState(this, a2, 2);
      *((_BYTE *)this + a2 + 384) = 100;
      *((_BYTE *)this + a2 + 427) = 100;
    }
    else if ( a3 <= 0 )
    {
      if ( a3 + *((char *)this + a2 + 384) >= 0 )
      {
        *((_BYTE *)this + a2 + 384) += a3;
        *((_BYTE *)this + a2 + 427) += a3;
        v5 = (IEntity *)((IEntity *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 3));
        if ( IEntity::FlagBits(v5, (EntityFlag)4096) == 0 && *((_BYTE *)this + a2 + 427) == 0 )
        {
          CTradingBuildingRole::ClearExpectedAmounts(this, a2);
        }
      }
      else
      {
        CTradingBuildingRole::ClearGoodState(this, a2, 2);
        *((_BYTE *)this + a2 + 384) = 0;
        *((_BYTE *)this + a2 + 427) = 0;
        v4 = (IEntity *)((IEntity *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 3));
        if ( IEntity::FlagBits(v4, (EntityFlag)4096) == 0 )
        {
          CTradingBuildingRole::ClearExpectedAmounts(this, a2);
        }
      }
    }
    else
    {
      CTradingBuildingRole::SetGoodState(this, a2, 2);
      if ( a3 + *((char *)this + a2 + 384) <= 100 )
      {
        *((_BYTE *)this + a2 + 384) += a3;
        *((_BYTE *)this + a2 + 427) += a3;
      }
      else
      {
        *((_BYTE *)this + a2 + 384) = 100;
        *((_BYTE *)this + a2 + 427) = 100;
      }
    }
  }
  else
  {
    CTradingBuildingRole::ClearGoodState(this, a2, 2);
    *((_BYTE *)this + a2 + 384) = 0;
    *((_BYTE *)this + a2 + 427) = 0;
    v3 = (IEntity *)((IEntity *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 3));
    if ( IEntity::FlagBits(v3, (EntityFlag)4096) == 0 )
    {
      CTradingBuildingRole::ClearExpectedAmounts(this, a2);
    }
  }
}


// address=[0x1521050]
// Decompiled from void __thiscall CTradingBuildingRole::TradeWith(CInternationalTrader **this, unsigned int a2)
void  CTradingBuildingRole::TradeWith(int a2) {
  
  int v2; // [esp+0h] [ebp-Ch]
  unsigned __int8 *BuildingPtr; // [esp+8h] [ebp-4h]

  if ( a2 > 8 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1243, "0<=_iPlayerId && _iPlayerId <PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( *(this + 171) != 0 )
  {
    BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
    if ( BuildingPtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1248, "pBuilding!=NULL") == 1 )
    {
      __debugbreak();
    }
    if ( BuildingPtr != 0 )
    {
      v2 = IEntity::OwnerId((IEntity *)BuildingPtr);
      CInternationalTrader::SwitchPlayerTradeStatus(*(this + 171), v2, a2);
    }
  }
}


// address=[0x1521100]
// Decompiled from unsigned __int8 *__thiscall CTradingBuildingRole::TradeGood(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::TradeGood(int a2) {
  
  unsigned __int8 *result; // eax
  int v3; // eax
  int v4; // [esp-4h] [ebp-18h]
  int v5; // [esp+0h] [ebp-14h]
  unsigned __int8 *v6; // [esp+8h] [ebp-Ch]
  int TradingStatus; // [esp+Ch] [ebp-8h]

  TradingStatus = CTradingBuildingRole::GetTradingStatus(this, *((char *)this + a2 + 470));
  if ( TradingStatus != 0 && TradingStatus != 4 && TradingStatus != 8 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1265, "OldStatus==0 || OldStatus == TRADING_IMPORT || OldStatus == TRADING_EXPORT") == 1 )
  {
    __debugbreak();
  }
  CTradingBuildingRole::ClearGoodState(this, a2, TradingStatus);
  if ( TradingStatus < 8 )
  {
    if ( TradingStatus != 0 )
    {
      CTradingBuildingRole::SetGoodState(this, a2, 8);
    }
    else
    {
      CTradingBuildingRole::SetGoodState(this, a2, 4);
    }
  }
  else
  {
    *((_BYTE *)this + a2 + 470) = 0;
  }
  v5 = *((char *)this + a2 + 470);
  if ( !CMapObjectMgr::ValidEntityId(*((unsigned __int16 *)this + 3)) && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1284, "g_pMapObjectMgr->ValidEntityId( m_uBuildingId )") == 1 )
  {
    __debugbreak();
  }
  if ( (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3)) == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1285, "g_cBuildingMgr.GetBuildingPtr(m_uBuildingId)!=NULL") == 1 )
  {
    __debugbreak();
  }
  result = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
  v6 = result;
  if ( result == 0 )
  {
    result = (unsigned __int8 *)BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1287, "pOwnerBuilding!=NULL");
    if ( result == (unsigned __int8 *)1 )
    {
      __debugbreak();
    }
  }
  if ( v6 != 0 )
  {
    v4 = CTradingBuildingRole::GetTradingStatus(this, v5);
    v3 = IEntity::OwnerId((IEntity *)v6);
    result = (unsigned __int8 *)CInternationalTrader::SetGoodStatus(*((_DWORD *)this + 171), v3, v6, a2, v4);
  }
  if ( TradingStatus != 0 )
  {
    return (unsigned __int8 *)CTradingBuildingRole::ClearTradingPiles(this, a2, TradingStatus);
  }
  return result;
}


// address=[0x15212b0]
// Decompiled from void __thiscall CTradingBuildingRole::ShowTradeRoute(CTradingBuildingRole *this)
void  CTradingBuildingRole::ShowTradeRoute(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // [esp-4h] [ebp-24h]
  int v6; // [esp-4h] [ebp-24h]
  int v7; // [esp-4h] [ebp-24h]
  int v8; // [esp-4h] [ebp-24h]
  IEntity *v9; // [esp+0h] [ebp-20h]
  int v10; // [esp+4h] [ebp-1Ch]
  int v11; // [esp+4h] [ebp-1Ch]
  int v12; // [esp+8h] [ebp-18h]
  int v13; // [esp+8h] [ebp-18h]
  IEntity *v14; // [esp+Ch] [ebp-14h]
  IEntity *v15; // [esp+10h] [ebp-10h]
  IEntity *v16; // [esp+14h] [ebp-Ch]
  Y16X16 *WorkingAreaPackedXY; // [esp+1Ch] [ebp-4h]
  Y16X16 *v19; // [esp+1Ch] [ebp-4h]

  if ( *((_WORD *)this + 190) != 0 )
  {
    v15 = (IEntity *)((IEntity *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 190));
    v16 = (IEntity *)((IEntity *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 3));
    if ( IEntity::Type(v16) == 32 && IEntity::Type(v15) == 32 )
    {
      WorkingAreaPackedXY = (Y16X16 *)CBuilding::GetWorkingAreaPackedXY(v16);
      v10 = CBuilding::GetWorkingAreaPackedXY(v15);
      v12 = 256;
    }
    else
    {
      WorkingAreaPackedXY = (Y16X16 *)CBuilding::EnsignPackedXY(v16);
      v10 = CBuilding::EnsignPackedXY(v15);
      v12 = 0;
    }
    Y16X16::UnpackXYFast((int)WorkingAreaPackedXY, &CTradingBuildingRole::m_iLastX, &CTradingBuildingRole::m_iLastY);
    v5 = IEntity::Y(v16);
    v1 = IEntity::X(v16);
    CWorldManager::TraceLine(CTradingBuildingRole::m_iLastX, CTradingBuildingRole::m_iLastY, v1, v5);
    CAStarCallback::FindPath((int)WorkingAreaPackedXY, v10, (void (__cdecl *)(int, int))CTradingBuildingRole::PathCallback, v12);
    v6 = IEntity::Y(v15);
    v2 = IEntity::X(v15);
    CWorldManager::TraceLine(CTradingBuildingRole::m_iLastX, CTradingBuildingRole::m_iLastY, v2, v6);
    IGfxEngine::EnableIconLayer(g_pGfxEngine, 1);
  }
  if ( *((_WORD *)this + 191) != 0 )
  {
    v9 = (IEntity *)((IEntity *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 191));
    v14 = (IEntity *)((IEntity *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 3));
    if ( IEntity::Type(v14) == 32 && IEntity::Type(v9) == 32 )
    {
      v19 = (Y16X16 *)CBuilding::GetWorkingAreaPackedXY(v14);
      v11 = CBuilding::GetWorkingAreaPackedXY(v9);
      v13 = 256;
    }
    else
    {
      v19 = (Y16X16 *)CBuilding::EnsignPackedXY(v14);
      v11 = CBuilding::EnsignPackedXY(v9);
      v13 = 0;
    }
    Y16X16::UnpackXYFast((int)v19, &CTradingBuildingRole::m_iLastX, &CTradingBuildingRole::m_iLastY);
    v7 = IEntity::Y(v14);
    v3 = IEntity::X(v14);
    CWorldManager::TraceLine(CTradingBuildingRole::m_iLastX, CTradingBuildingRole::m_iLastY, v3, v7);
    CAStarCallback::FindPath((int)v19, v11, (void (__cdecl *)(int, int))CTradingBuildingRole::PathCallback, v13);
    v8 = IEntity::Y(v9);
    v4 = IEntity::X(v9);
    CWorldManager::TraceLine(CTradingBuildingRole::m_iLastX, CTradingBuildingRole::m_iLastY, v4, v8);
    IGfxEngine::EnableIconLayer(g_pGfxEngine, 1);
  }
}


// address=[0x1521500]
// Decompiled from signed int __thiscall CTradingBuildingRole::ClearExpectedAmounts(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::ClearExpectedAmounts(int a2) {
  
  signed int result; // eax
  unsigned __int16 *v3; // eax
  pairNode *v4; // [esp+0h] [ebp-10h]
  CPile *PilePtr; // [esp+4h] [ebp-Ch]
  signed int i; // [esp+Ch] [ebp-4h]

  for ( i = 0;
        ;
        ++i )
  {
    result = *(char *)(*((_DWORD *)this + 94) + 57);
    if ( i >= result )
    {
      break;
    }
    v3 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
    PilePtr = CPileMgr::GetPilePtr(*v3);
    if ( CPile::GetRoleType(PilePtr) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1043, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v4 = (pairNode *)CPile::Role(PilePtr);
    if ( CTradePileRole::GetExpectedAmount((CTradePileRole *)v4) != 0 && *((_BYTE *)this + a2 + 427) == 0 )
    {
      CTradePileRole::SetExpectedAmount(v4, 0);
    }
  }
  return result;
}


// address=[0x15215c0]
// Decompiled from char __thiscall CTradingBuildingRole::IsRegisteredAsIncomingTrader(CTradingBuildingRole *this, int a2, int a3)
bool  CTradingBuildingRole::IsRegisteredAsIncomingTrader(int a2, int a3) {
  
  unsigned int i; // [esp+4h] [ebp-4h]

  if ( a3 < 1 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1068, "_iType >= SHIP_TRANSPORT") == 1 )
  {
    __debugbreak();
  }
  if ( a3 > 3 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1069, "_iType <= CART_TRANSPORT") == 1 )
  {
    __debugbreak();
  }
  for ( i = 0;
        i < std::vector<CTradingBuildingRole::STradersEx>::size((char *)this + 668);
        ++i )
  {
    if ( *(_DWORD *)std::vector<CTradingBuildingRole::STradersEx>::operator[](i) == a2 && *(_DWORD *)(std::vector<CTradingBuildingRole::STradersEx>::operator[](i) + 4) == a3 )
    {
      return 1;
    }
  }
  return 0;
}


// address=[0x1521680]
// Decompiled from char __thiscall CTradingBuildingRole::RegisterIncomingTrader(CTradingBuildingRole *this, int a2, int a3, bool a4)
bool  CTradingBuildingRole::RegisterIncomingTrader(int a2, int a3, bool a4) {
  
  _DWORD v5[2]; // [esp+0h] [ebp-10h] BYREF
  bool v6; // [esp+8h] [ebp-8h]
  CTradingBuildingRole *v7; // [esp+Ch] [ebp-4h]

  v7 = this;
  if ( CTradingBuildingRole::IsRegisteredAsIncomingTrader(this, a2, a3) != 0 )
  {
    return 0;
  }
  v5[0] = a2;
  v5[1] = a3;
  v6 = a4;
  std::vector<CTradingBuildingRole::STradersEx>::push_back((int)v5);
  return 1;
}


// address=[0x15216d0]
// Decompiled from char __thiscall CTradingBuildingRole::UnregisterIncomingTrader(CTradingBuildingRole *this, int a2, int a3)
bool  CTradingBuildingRole::UnregisterIncomingTrader(int a2, int a3) {
  
  int v4; // eax
  _DWORD *v5; // esi
  _DWORD *v6; // eax
  int v7; // [esp+4h] [ebp-Ch]
  unsigned int i; // [esp+8h] [ebp-8h]

  if ( CTradingBuildingRole::IsRegisteredAsIncomingTrader(this, a2, a3) == 0 )
  {
    return 0;
  }
  v7 = -1;
  for ( i = 0;
        i < std::vector<CTradingBuildingRole::STradersEx>::size((char *)this + 668);
        ++i )
  {
    if ( *(_DWORD *)std::vector<CTradingBuildingRole::STradersEx>::operator[](i) == a2 )
    {
      v7 = i;
      break;
    }
  }
  if ( v7 == -1 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1126, "iIncomingPos != -1") == 1 )
  {
    __debugbreak();
  }
  v4 = std::vector<CTradingBuildingRole::STradersEx>::size((char *)this + 668);
  v5 = (_DWORD *)std::vector<CTradingBuildingRole::STradersEx>::operator[](v4 - 1);
  v6 = (_DWORD *)std::vector<CTradingBuildingRole::STradersEx>::operator[](v7);
  *v6 = *v5;
  v6[1] = v5[1];
  v6[2] = v5[2];
  std::vector<CTradingBuildingRole::STradersEx>::pop_back((char *)this + 668);
  return 1;
}


// address=[0x15217d0]
// Decompiled from int __thiscall CTradingBuildingRole::GetNrRegisteredIncomingTraders(CTradingBuildingRole *this, int a2, bool a3)
int  CTradingBuildingRole::GetNrRegisteredIncomingTraders(int a2, bool a3) {
  
  int v4; // [esp+0h] [ebp-Ch]
  unsigned int i; // [esp+8h] [ebp-4h]

  v4 = 0;
  for ( i = 0;
        i < std::vector<CTradingBuildingRole::STradersEx>::size((char *)this + 668);
        ++i )
  {
    if ( *(_DWORD *)(std::vector<CTradingBuildingRole::STradersEx>::operator[](i) + 4) == a2 && *(_BYTE *)(std::vector<CTradingBuildingRole::STradersEx>::operator[](i) + 8) == a3 )
    {
      ++v4;
    }
  }
  return v4;
}


// address=[0x1521860]
// Decompiled from int __thiscall CTradingBuildingRole::GetNextFreePile(_DWORD *this)
int  CTradingBuildingRole::GetNextFreePile(void) {
  
  unsigned __int16 *v1; // eax
  CTradePileRole *v3; // [esp+0h] [ebp-10h]
  struct CPile *PilePtr; // [esp+4h] [ebp-Ch]
  signed int i; // [esp+Ch] [ebp-4h]

  for ( i = 0;
        i < *(char *)(*(this + 94) + 57);
        ++i )
  {
    v1 = std::vector<unsigned short>::operator[](this + 152, i);
    PilePtr = CPileMgr::GetPilePtr(*v1);
    v3 = (CTradePileRole *)CPile::Role(PilePtr);
    if ( CTradePileRole::GetTradeRoleType(v3) == 0 )
    {
      return *std::vector<unsigned short>::operator[](this + 152, i);
    }
  }
  return 0;
}


// address=[0x15218f0]
// Decompiled from void __thiscall CTradingBuildingRole::ExecuteUnforseenGoodTypeChange(CTradingBuildingRole *this, int a2, int a3, int a4)
void  CTradingBuildingRole::ExecuteUnforseenGoodTypeChange(int a2, int a3, int a4) {
  
  CPile *PilePtr; // [esp+4h] [ebp-8h]
  pairNode *v6; // [esp+8h] [ebp-4h]

  if ( a3 != 0 )
  {
    PilePtr = CPileMgr::GetPilePtr(a2);
    if ( CPile::GetRoleType(PilePtr) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 413, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v6 = (pairNode *)CPile::Role(PilePtr);
    if ( CTradePileRole::GetExpectedAmount((CTradePileRole *)v6) != 0 )
    {
      *((_BYTE *)this + a3 + 384) += CTradePileRole::GetExpectedAmount((CTradePileRole *)v6);
      CTradePileRole::SetExpectedAmount(v6, 0);
    }
  }
}


// address=[0x1521990]
// Decompiled from _DWORD *__thiscall CTradingBuildingRole::FillDialog(int this, IEntity *a2, char a3)
void  CTradingBuildingRole::FillDialog(class CBuilding * a2, bool a3) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  unsigned __int16 *v7; // eax
  unsigned __int8 *v8; // eax
  unsigned __int16 *v9; // eax
  unsigned __int16 *v10; // eax
  unsigned __int16 *v11; // eax
  int v13; // [esp-8h] [ebp-58h]
  int v14; // [esp-8h] [ebp-58h]
  unsigned int v15; // [esp+4h] [ebp-4Ch]
  unsigned __int8 *v16; // [esp+8h] [ebp-48h]
  unsigned __int8 *v17; // [esp+Ch] [ebp-44h]
  unsigned __int8 *v18; // [esp+10h] [ebp-40h]
  CTradePileRole *v19; // [esp+1Ch] [ebp-34h]
  unsigned int i; // [esp+24h] [ebp-2Ch]
  CEvn_Event v22; // [esp+28h] [ebp-28h] BYREF
  int v23; // [esp+4Ch] [ebp-4h]

  CInfoExchange::Clear((CInfoExchange *)&g_cPortInfo);
  dword_3F1E570 = 5;
  byte_3F1E575 = IEntity::Race(a2);
  if ( IEntity::Type(a2) == 32 )
  {
    byte_3F1E574 = 32;
    byte_3F1E577 = 1;
    byte_3F1E578 = IEntity::FlagBits(a2, (EntityFlag)4096) != 0;
    byte_3F1E579 = 0;
    v3 = IEntity::OwnerId(a2);
    byte_3F1E57B = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, BUILDING_PORT, 0);
    v4 = IEntity::OwnerId(a2);
    byte_3F1E57C = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v4, BUILDING_PORT, 1u);
    byte_3F1E576 = *(_BYTE *)(this + 29);
    if ( *(_BYTE *)(this + 29) != 0 )
    {
      byte_3F1E57D = *(_BYTE *)(*(_DWORD *)(this + 376) + 478);
    }
  }
  else if ( IEntity::Type(a2) == 33 )
  {
    byte_3F1E574 = 33;
    byte_3F1E577 = 1;
    byte_3F1E578 = IEntity::FlagBits(a2, (EntityFlag)4096) != 0;
    byte_3F1E579 = 0;
    v13 = IEntity::Type(a2);
    v5 = IEntity::OwnerId(a2);
    byte_3F1E57B = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v5, (S4_BUILDING_ENUM)v13, 0);
    v14 = IEntity::Type(a2);
    v6 = IEntity::OwnerId(a2);
    byte_3F1E57C = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v6, (S4_BUILDING_ENUM)v14, 1u);
    byte_3F1E57D = 0;
  }
  for ( i = 0;
        i < std::vector<unsigned short>::size(this + 608);
        ++i )
  {
    v7 = std::vector<unsigned short>::operator[]((void *)(this + 608), i);
    v8 = (unsigned __int8 *)CPileMgr::operator[](*v7);
    v19 = (CTradePileRole *)CPile::Role(v8);
    if ( CTradePileRole::GetTradeRoleType(v19) == 5 )
    {
      byte_3F1E581[2 * i] += 30;
    }
    v9 = std::vector<unsigned short>::operator[]((void *)(this + 608), i);
    v18 = (unsigned __int8 *)CPileMgr::operator[](*v9);
    if ( (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v18 + 40))(v18) != 0 )
    {
      v10 = std::vector<unsigned short>::operator[]((void *)(this + 608), i);
      v17 = (unsigned __int8 *)CPileMgr::operator[](*v10);
      byte_3F1E581[2 * i] = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v17 + 40))(v17);
      v11 = std::vector<unsigned short>::operator[]((void *)(this + 608), i);
      v16 = (unsigned __int8 *)CPileMgr::operator[](*v11);
      byte_3F1E580[2 * i] = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v16 + 60))(v16);
    }
    if ( CTradePileRole::GetTradeRoleType(v19) == 3 )
    {
      byte_3F1E581[2 * i] += 10;
    }
    if ( CTradePileRole::GetTradeRoleType(v19) == 4 )
    {
      byte_3F1E581[2 * i] += 20;
    }
    if ( CTradePileRole::GetTradeRoleType(v19) == 0 )
    {
      byte_3F1E581[2 * i] += 40;
    }
    if ( CTradePileRole::GetTradeRoleType(v19) == 1 )
    {
      byte_3F1E581[2 * i] += 50;
    }
    if ( CTradePileRole::GetTradeRoleType(v19) == 2 )
    {
      byte_3F1E581[2 * i] += 60;
    }
  }
  v15 = 604;
  if ( a3 == 0 )
  {
    v15 = 602;
  }
  CEvn_Event::CEvn_Event(&v22, v15, 0, (unsigned int)&g_cPortInfo, 0);
  v23 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v22);
  v23 = -1;
  return CEvn_Event::~CEvn_Event(&v22);
}


// address=[0x1521d80]
// Decompiled from CTradingBuildingRole *__thiscall CTradingBuildingRole::FillTradeSideBar(CInternationalTrader **this, struct CPortGoodsTradeBarInfo *a2, bool a3)
void  CTradingBuildingRole::FillTradeSideBar(class CPortGoodsTradeBarInfo * a2, bool a3) {
  
  CTradingBuildingRole *result; // eax
  int v4; // eax
  int v5; // eax
  unsigned int v6; // [esp+4h] [ebp-38h]
  unsigned __int8 *BuildingPtr; // [esp+Ch] [ebp-30h]
  int i; // [esp+10h] [ebp-2Ch]
  int j; // [esp+10h] [ebp-2Ch]
  CEvn_Event v11; // [esp+14h] [ebp-28h] BYREF
  int v12; // [esp+38h] [ebp-4h]

  result = (CTradingBuildingRole *)this;
  if ( *(this + 171) == 0 )
  {
    result = (CTradingBuildingRole *)BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1315, "m_pTrader!=NULL");
    if ( result == (CTradingBuildingRole *)1 )
    {
      __debugbreak();
    }
  }
  if ( *(this + 171) != 0 )
  {
    *((_DWORD *)a2 + 1) = 13;
    BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
    if ( BuildingPtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1321, "pBuilding!=NULL") == 1 )
    {
      __debugbreak();
    }
    result = 0;
    if ( BuildingPtr != 0 )
    {
      memset((char *)a2 + 8, 0, 9u);
      for ( i = 1;
            i <= CPlayerManager::NumberOfPlayers();
            ++i )
      {
        v4 = IEntity::OwnerId((IEntity *)BuildingPtr);
        *((_BYTE *)a2 + i + 8) = CInternationalTrader::GetPlayerTradeStatus(*(this + 171), v4, i);
      }
      for ( j = 0;
            j < 43;
            ++j )
      {
        v5 = IEntity::OwnerId((IEntity *)BuildingPtr);
        *((_BYTE *)a2 + j + 17) = CInternationalTrader::GetGoodStatus(*(this + 171), v5, BuildingPtr, j);
      }
      v6 = 606;
      if ( !a3 )
      {
        v6 = 607;
      }
      CEvn_Event::CEvn_Event(&v11, v6, 0, (unsigned int)a2, 0);
      v12 = 0;
      if ( g_pEvnEngine == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1347, "g_pEvnEngine != NULL") == 1 )
      {
        __debugbreak();
      }
      if ( g_pEvnEngine != 0 )
      {
        IEventEngine::SendAMessage(g_pEvnEngine, &v11);
      }
      v12 = -1;
      return (CTradingBuildingRole *)CEvn_Event::~CEvn_Event(&v11);
    }
  }
  return result;
}


// address=[0x1521f70]
// Decompiled from _DWORD *__thiscall CTradingBuildingRole::FillGoodsOutSideBar(CTradingBuildingRole *this, struct CPortGoodsOutBarInfo *a2, bool a3)
void  CTradingBuildingRole::FillGoodsOutSideBar(class CPortGoodsOutBarInfo * a2, bool a3) {
  
  unsigned int v4; // [esp+4h] [ebp-34h]
  int i; // [esp+Ch] [ebp-2Ch]
  CEvn_Event v7; // [esp+10h] [ebp-28h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  *((_DWORD *)a2 + 1) = 14;
  memset((char *)a2 + 8, 0, 0x2Bu);
  for ( i = 0;
        i < 43;
        ++i )
  {
    if ( (unsigned __int8)CTradingBuildingRole::HasGoodState(this, i, 2) != 0 )
    {
      *((_BYTE *)a2 + i + 8) = *((_BYTE *)this + i + 427);
    }
  }
  v4 = 606;
  if ( !a3 )
  {
    v4 = 607;
  }
  CEvn_Event::CEvn_Event(&v7, v4, 0, (unsigned int)a2, 0);
  v8 = 0;
  if ( g_pEvnEngine == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1387, "g_pEvnEngine != NULL") == 1 )
  {
    __debugbreak();
  }
  if ( g_pEvnEngine != 0 )
  {
    IEventEngine::SendAMessage(g_pEvnEngine, &v7);
  }
  v8 = -1;
  return CEvn_Event::~CEvn_Event(&v7);
}


// address=[0x15220a0]
// Decompiled from unsigned __int8 *__thiscall CTradingBuildingRole::ChangeTradeStatus(CInternationalTrader **this, unsigned int a2, bool a3)
void  CTradingBuildingRole::ChangeTradeStatus(int a2, bool a3) {
  
  unsigned __int8 *result; // eax
  int v4; // [esp+0h] [ebp-Ch]
  unsigned __int8 *v5; // [esp+4h] [ebp-8h]

  if ( a2 > 8 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4690, "0<=_iPlayerID && _iPlayerID <PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  if ( *(this + 171) != 0 )
  {
    result = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
    v5 = result;
    if ( result == 0 )
    {
      result = (unsigned __int8 *)BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4695, "pBuilding!=NULL");
      if ( result == (unsigned __int8 *)1 )
      {
        __debugbreak();
      }
    }
    if ( v5 != 0 )
    {
      v4 = IEntity::OwnerId((IEntity *)v5);
      CInternationalTrader::SetPlayerTradeStatus(*(this + 171), v4, a2, a3);
      if ( !CInternationalTrader::TradeWithSomeone(*(this + 171), v4) )
      {
        ((void (__thiscall *)(CTradingBuildingRole *))CTradingBuildingRole::DisableTranding)((CTradingBuildingRole *)this);
      }
      return (unsigned __int8 *)((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
    }
  }
  return result;
}


// address=[0x1522180]
// Decompiled from int __cdecl CTradingBuildingRole::PathCallback(int a1, int a2)
void __cdecl CTradingBuildingRole::PathCallback(int a1, int a2) {
  
  int result; // eax

  CWorldManager::TraceLine(CTradingBuildingRole::m_iLastX, CTradingBuildingRole::m_iLastY, a1, a2);
  CTradingBuildingRole::m_iLastX = a1;
  CTradingBuildingRole::m_iLastY = a2;
  return result;
}


// address=[0x15221c0]
// Decompiled from char *__thiscall CTradingBuildingRole::CTradingBuildingRole(char *this, int a2)
 CTradingBuildingRole::CTradingBuildingRole(std::istream & a2) {
  
  char v3[4]; // [esp+4h] [ebp-54h] BYREF
  char v4[4]; // [esp+8h] [ebp-50h] BYREF
  char v5[4]; // [esp+Ch] [ebp-4Ch] BYREF
  _DWORD v6[2]; // [esp+10h] [ebp-48h] BYREF
  char v7; // [esp+18h] [ebp-40h]
  int v8; // [esp+1Ch] [ebp-3Ch] BYREF
  _DWORD v9[2]; // [esp+20h] [ebp-38h] BYREF
  int pExceptionObject; // [esp+28h] [ebp-30h] BYREF
  CInternationalTrader *v11; // [esp+2Ch] [ebp-2Ch]
  void *C; // [esp+30h] [ebp-28h]
  unsigned int v13; // [esp+34h] [ebp-24h] BYREF
  int i; // [esp+38h] [ebp-20h]
  unsigned int v15; // [esp+3Ch] [ebp-1Ch] BYREF
  int j; // [esp+40h] [ebp-18h]
  char *v17; // [esp+44h] [ebp-14h]
  char v18[4]; // [esp+48h] [ebp-10h] BYREF
  int v19; // [esp+54h] [ebp-4h]

  v17 = this;
  IBuildingRole::IBuildingRole((IBuildingRole *)this, (struct std::istream *)a2);
  v19 = 0;
  *(_DWORD *)v17 = &CTradingBuildingRole::_vftable_;
  std::vector<unsigned short>::vector<unsigned short>(v17 + 608);
  std::vector<CTradingBuildingRole::STradersEx>::vector<CTradingBuildingRole::STradersEx>();
  C = operator new(0xCu);
  LOBYTE(v19) = 3;
  if ( C != 0 )
  {
    v11 = CInternationalTrader::CInternationalTrader((CInternationalTrader *)C);
  }
  else
  {
    v11 = 0;
  }
  v9[1] = v11;
  LOBYTE(v19) = 2;
  *((_DWORD *)v17 + 171) = v11;
  *((_DWORD *)v17 + 172) = 0;
  operator^<unsigned int>(a2, &v15);
  for ( i = 0;
        i < 43;
        ++i )
  {
    v17[i + 427] = 0;
    v17[i + 513] = 0;
    v17[i + 556] = 0;
  }
  if ( v15 == 0 || v15 > 4 )
  {
    goto LABEL_23;
  }
  operator^<unsigned short>(a2, (unsigned __int16 *)v17 + 190);
  LoadArray<signed char>(a2, (int)(v17 + 384), 43);
  LoadArray<signed char>(a2, (int)(v17 + 427), 43);
  for ( j = 0;
        j < 8;
        operator^<bool>(a2, &v17[j++ + 599]) )
  {
    ;
  }
  LoadArray<signed char>(a2, (int)(v17 + 470), 43);
  operator^<unsigned int>(a2, &v13);
  for ( j = 0;
        j < v13;
        ++j )
  {
    operator^<unsigned short>(a2, (unsigned __int16 *)v18);
    ((void (__stdcall *)(char *))std::vector<unsigned short>::push_back)(v18);
  }
  operator^<int>((struct std::istream *)a2, (int *)v17 + 157);
  operator^<int>((struct std::istream *)a2, (int *)v17 + 158);
  operator^<bool>(a2, v17 + 636);
  operator^<bool>(a2, v17 + 637);
  operator^<int>((struct std::istream *)a2, (int *)v17 + 160);
  operator^<int>((struct std::istream *)a2, (int *)v17 + 161);
  operator^<bool>(a2, v17 + 648);
  operator^<bool>(a2, v17 + 649);
  operator^<int>((struct std::istream *)a2, (int *)v17 + 163);
  operator^<int>((struct std::istream *)a2, (int *)v17 + 164);
  operator^<bool>(a2, v17 + 660);
  operator^<bool>(a2, v17 + 661);
  operator^<int>((struct std::istream *)a2, (int *)v17 + 166);
  operator^<unsigned int>(a2, &v13);
  for ( j = 0;
        j < v13;
        ++j )
  {
    if ( v15 > 2 )
    {
      operator^<int>((struct std::istream *)a2, (int *)v3);
      operator^<int>((struct std::istream *)a2, (int *)v4);
      operator^<bool>(a2, v5);
      std::vector<CTradingBuildingRole::STradersEx>::push_back((int)v3);
    }
    else
    {
      operator^<int>((struct std::istream *)a2, &v8);
      operator^<int>((struct std::istream *)a2, v9);
      v6[0] = v8;
      v6[1] = v9[0];
      v7 = 0;
      std::vector<CTradingBuildingRole::STradersEx>::push_back((int)v6);
    }
  }
  if ( v15 == 1 )
  {
    *((_WORD *)v17 + 191) = 0;
  }
  else
  {
LABEL_23:
    if ( v15 < 2 )
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CTradingBuildingRole");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    operator^<unsigned short>(a2, (unsigned __int16 *)v17 + 191);
    if ( v15 >= 3 )
    {
      LoadArray<signed char>(a2, (int)(v17 + 513), 43);
      LoadArray<signed char>(a2, (int)(v17 + 556), 43);
    }
    if ( v15 >= 4 )
    {
      operator^<int>((struct std::istream *)a2, (int *)v17 + 172);
    }
  }
  return v17;
}


// address=[0x1522660]
// Decompiled from int __thiscall CTradingBuildingRole::Store(struct IBuildingRole *this, struct std::ostream *a2)
void  CTradingBuildingRole::Store(std::ostream & a2) {
  
  __int16 *v2; // eax
  int *v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp+0h] [ebp-10h] BYREF
  int v8; // [esp+4h] [ebp-Ch] BYREF
  int i; // [esp+8h] [ebp-8h]
  struct IBuildingRole *v10; // [esp+Ch] [ebp-4h]

  v10 = this;
  IBuildingRole::Store(this, a2);
  v7 = 4;
  operator^<unsigned int>(a2, (unsigned int *)&v7);
  operator^<unsigned short>(a2, (WORD *)&v10[1]);
  StoreArray<signed char>((int)a2, (int)&v10[1].m_uLogicState, 43u);
  StoreArray<signed char>((int)a2, (int)&v10[1].gap_24[11], 43u);
  for ( i = 0;
        i < 8;
        ++i )
  {
    operator^<bool>(a2, (bool *)&v10[1].m_vPatches[3].m_uTicks2 + i);
  }
  StoreArray<signed char>((int)a2, (int)&v10[1].m_vPatchPairs[1].m_iJobFrame + 2, 43u);
  v8 = std::vector<unsigned short>::size(&v10[1].m_vPatches[3].m_uSoundId);
  operator^<unsigned int>(a2, (unsigned int *)&v8);
  for ( i = 0;
        i < (unsigned int)v8;
        ++i )
  {
    v2 = (__int16 *)std::vector<unsigned short>::operator[](&v10[1].m_vPatches[3].m_uSoundId, i);
    operator^<unsigned short>(a2, (WORD *)v2);
  }
  operator^<int>(a2, (int *)&v10[1].m_vPatches[4].m_uSoundId);
  operator^<int>(a2, (int *)&v10[1].m_vPatches[4].m_uSoundRandomness);
  operator^<bool>(a2, (bool *)&v10[1].m_vPatches[5]);
  operator^<bool>(a2, (bool *)&v10[1].m_vPatches[5].m_uTicks);
  operator^<int>(a2, (int *)&v10[1].m_vPatches[5].m_uJob);
  operator^<int>(a2, (int *)&v10[1].m_vPatches[5].m_uDuration);
  operator^<bool>(a2, (bool *)&v10[1].m_vPatches[5].m_uSoundId);
  operator^<bool>(a2, (bool *)&v10[1].m_vPatches[5].m_uSoundId + 1);
  operator^<int>(a2, (int *)&v10[1].m_vPatches[5].m_uSoundRandomness);
  operator^<int>(a2, (int *)&v10[1].m_vPatches[6]);
  operator^<bool>(a2, (bool *)&v10[1].m_vPatches[6].m_uJob);
  operator^<bool>(a2, (bool *)&v10[1].m_vPatches[6].m_uJob + 1);
  operator^<int>(a2, (int *)&v10[1].m_vPatches[6].m_uDuration);
  v8 = std::vector<CTradingBuildingRole::STradersEx>::size(&v10[1].m_vPatches[6].m_uSoundId);
  operator^<unsigned int>(a2, (unsigned int *)&v8);
  for ( i = 0;
        i < (unsigned int)v8;
        ++i )
  {
    v3 = (int *)std::vector<CTradingBuildingRole::STradersEx>::operator[](i);
    operator^<int>(a2, v3);
    v4 = std::vector<CTradingBuildingRole::STradersEx>::operator[](i);
    operator^<int>(a2, (int *)(v4 + 4));
    v5 = std::vector<CTradingBuildingRole::STradersEx>::operator[](i);
    operator^<bool>(a2, (bool *)(v5 + 8));
  }
  operator^<unsigned short>(a2, (WORD *)&v10[1].__vftable + 1);
  StoreArray<signed char>((int)a2, (int)&v10[1].m_vPatchPairs[7].m_uJobId + 1, 43u);
  StoreArray<signed char>((int)a2, (int)&v10[1].m_vPatches[1], 43u);
  return operator^<int>(a2, (int *)&v10[1].m_vPatches[7].m_uSoundId);
}


// address=[0x152bcc0]
// Decompiled from int __thiscall CTradingBuildingRole::ClassID(CTradingBuildingRole *this)
unsigned long  CTradingBuildingRole::ClassID(void)const {
  
  return CTradingBuildingRole::m_iClassID;
}


// address=[0x152bd70]
// Decompiled from void *__thiscall CTradingBuildingRole::GetBuildingNeed(std::_Ref_count_base *this, const struct type_info *a2)
int  CTradingBuildingRole::GetBuildingNeed(int a2)const {
  
  return 0;
}


// address=[0x152bd90]
// Decompiled from int __thiscall CTradingBuildingRole::GetBuildingRole(CMFCVisualManagerWindows7 *this)
int  CTradingBuildingRole::GetBuildingRole(void) {
  
  return 13;
}


// address=[0x3d8b7a4]
// [Decompilation failed for static unsigned long CTradingBuildingRole::m_iClassID]

// address=[0x15229a0]
// Decompiled from char __thiscall CTradingBuildingRole::CheckTransport(CTradingBuildingRole *this, struct CBuilding *a2, unsigned int a3)
bool  CTradingBuildingRole::CheckTransport(class CBuilding * a2, int a3) {
  
  unsigned __int16 *v4; // eax
  int v5; // eax
  unsigned __int16 *v6; // eax
  int v7; // esi
  int v8; // esi
  int ExpectedAmount; // eax
  unsigned __int16 *v10; // eax
  int v11; // eax
  CEcoSector *v12; // eax
  int v13; // esi
  int v14; // esi
  int v15; // eax
  int RequestedAmount; // [esp+Ch] [ebp-44h]
  int v17; // [esp+14h] [ebp-3Ch]
  int v18; // [esp+18h] [ebp-38h]
  int v19; // [esp+1Ch] [ebp-34h]
  int v20; // [esp+24h] [ebp-2Ch]
  CTradePileRole *v21; // [esp+28h] [ebp-28h]
  int v22; // [esp+2Ch] [ebp-24h]
  int v23; // [esp+2Ch] [ebp-24h]
  pairNode *v24; // [esp+30h] [ebp-20h]
  pairNode *v25; // [esp+34h] [ebp-1Ch]
  signed int i; // [esp+3Ch] [ebp-14h]
  signed int j; // [esp+3Ch] [ebp-14h]
  signed int k; // [esp+3Ch] [ebp-14h]
  int v29; // [esp+40h] [ebp-10h]
  CPile *PilePtr; // [esp+48h] [ebp-8h]
  CPile *v32; // [esp+48h] [ebp-8h]
  CPile *v33; // [esp+48h] [ebp-8h]
  char v34; // [esp+4Fh] [ebp-1h]

  if ( a3 > 0x2A )
  {
    return 0;
  }
  if ( *((_BYTE *)this + a3 + 384) == 0 )
  {
    return 0;
  }
  CTradingBuildingRole::GetCurrentAmount(this, a3);
  RequestedAmount = CTradingBuildingRole::GetRequestedAmount(this, a3, 0);
  v29 = *((char *)this + a3 + 384) - CTradingBuildingRole::GetExpectedAmount(this, a3, 0) - RequestedAmount;
  if ( v29 <= 0 )
  {
    return 0;
  }
  for ( i = 0;
        i < *(char *)(*((_DWORD *)this + 94) + 57);
        ++i )
  {
    v4 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
    PilePtr = CPileMgr::GetPilePtr(*v4);
    if ( CPile::GetRoleType(PilePtr) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1535, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v21 = (CTradePileRole *)CPile::Role(PilePtr);
    if ( CTradePileRole::GetTradeRoleType(v21) == 2 && ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr) == a3 )
    {
      v5 = ((int (__stdcall *)())IEntity::WorldIdx)();
      if ( CWorldManager::EcoSectorId(v5) == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1545, "m_iESId != 0") == 1 )
      {
        __debugbreak();
      }
      if ( PilePtr->Amount(PilePtr) != 0 )
      {
        if ( (unsigned __int8)CTradingBuildingRole::HasGoodState(this, a3, 2) != 0 )
        {
          CTradePileRole::SetTradeRoleType(v21, 1);
        }
        if ( (unsigned __int8)CTradingBuildingRole::HasGoodState(this, a3, 8) != 0 )
        {
          CTradePileRole::SetTradeRoleType(v21, 3);
        }
        v20 = PilePtr->Amount(PilePtr) >= v29 ? v29 : PilePtr->Amount(PilePtr);
        if ( *((_BYTE *)this + a3 + 384) != 100 )
        {
          *((_BYTE *)this + a3 + 384) -= v20;
          v29 -= v20;
        }
        ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
        if ( (unsigned __int8)CTradingBuildingRole::HasGoodState(this, a3, 2) != 0 && ((int)CTradingBuildingRole::GetNrDeliveryPilesOfGood(this, a3) >= 3 || *((_BYTE *)this + a3 + 384) == 0) )
        {
          return 1;
        }
      }
    }
  }
  if ( v29 == 0 )
  {
    return 1;
  }
  if ( (unsigned __int8)CTradingBuildingRole::HasGoodState(this, a3, 2) != 0 && (int)CTradingBuildingRole::GetNrDeliveryPilesOfGood(this, a3) >= 3 )
  {
    return 0;
  }
  for ( j = 0;
        j < *(char *)(*((_DWORD *)this + 94) + 57);
        ++j )
  {
    v6 = std::vector<unsigned short>::operator[]((char *)this + 608, j);
    v32 = CPileMgr::GetPilePtr(*v6);
    if ( CPile::GetRoleType(v32) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1595, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v24 = (pairNode *)CPile::Role(v32);
    if ( (CTradePileRole::GetTradeRoleType((CTradePileRole *)v24) == 1 || CTradePileRole::GetTradeRoleType((CTradePileRole *)v24) == 3) && ((int (__thiscall *)(CPile *))v32->GetGoodType)(v32) == a3 )
    {
      v7 = 8 - v32->Amount(v32);
      v8 = v7 - CPile::AmountComing(v32);
      v22 = v8 - CTradePileRole::GetExpectedAmount((CTradePileRole *)v24);
      v19 = v29 >= v22 ? v22 : v29;
      if ( v19 != 0 )
      {
        ExpectedAmount = CTradePileRole::GetExpectedAmount((CTradePileRole *)v24);
        CTradePileRole::SetExpectedAmount(v24, (struct CPaneDivider *)(v19 + ExpectedAmount));
        ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
        v29 -= v19;
      }
    }
  }
  if ( v29 == 0 )
  {
    return 1;
  }
  if ( (unsigned __int8)CTradingBuildingRole::HasGoodState(this, a3, 2) != 0 && (int)CTradingBuildingRole::GetNrDeliveryPilesOfGood(this, a3) >= 3 )
  {
    return 0;
  }
  v34 = 0;
  for ( k = 0;
        k < *(char *)(*((_DWORD *)this + 94) + 57);
        ++k )
  {
    v10 = std::vector<unsigned short>::operator[]((char *)this + 608, k);
    v33 = CPileMgr::GetPilePtr(*v10);
    if ( CPile::GetRoleType(v33) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1633, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v25 = (pairNode *)CPile::Role(v33);
    if ( CTradePileRole::GetTradeRoleType((CTradePileRole *)v25) == 0 )
    {
      v11 = ((int (__stdcall *)())IEntity::WorldIdx)();
      v18 = CWorldManager::EcoSectorId(v11);
      if ( v18 == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1642, "m_iESId != 0") == 1 )
      {
        __debugbreak();
      }
      v12 = (CEcoSector *)((int (__stdcall *)(int))CEcoSectorMgr::operator[])(v18);
      if ( CEcoSector::GetGoodOffer(v12, a3) != 0 )
      {
        v13 = 8 - v33->Amount(v33);
        v14 = v13 - CPile::AmountComing(v33);
        v23 = v14 - CTradePileRole::GetExpectedAmount((CTradePileRole *)v25);
        v17 = v29 >= v23 ? v23 : v29;
        if ( v17 != 0 )
        {
          if ( ((int (__thiscall *)(CPile *))v33->GetGoodType)(v33) != 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1653, "pPile->GetGoodType() == 0") == 1 )
          {
            __debugbreak();
          }
          CPile::SetGoodType(v33, a3);
          if ( (unsigned __int8)CTradingBuildingRole::HasGoodState(this, a3, 2) != 0 )
          {
            CTradePileRole::SetTradeRoleType(v25, 1);
          }
          else
          {
            CTradePileRole::SetTradeRoleType(v25, 3);
          }
          v15 = CTradePileRole::GetExpectedAmount((CTradePileRole *)v25);
          CTradePileRole::SetExpectedAmount(v25, (struct CPaneDivider *)(v17 + v15));
          ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
          v34 = 1;
          if ( *((_BYTE *)this + a3 + 384) != 100 )
          {
            v29 -= v17;
          }
          if ( (int)CTradingBuildingRole::GetNrDeliveryPilesOfGood(this, a3) >= 3 || *((_BYTE *)this + a3 + 384) == 0 )
          {
            return 1;
          }
        }
      }
    }
  }
  return v34;
}


// address=[0x1522fe0]
// Decompiled from int __thiscall CTradingBuildingRole::GetCurrentAmount(CTradingBuildingRole *this, unsigned int a2)
int  CTradingBuildingRole::GetCurrentAmount(int a2) {
  
  unsigned __int16 *v3; // eax
  CTradePileRole *v4; // [esp+0h] [ebp-14h]
  int v6; // [esp+8h] [ebp-Ch]
  signed int i; // [esp+Ch] [ebp-8h]
  CPile *PilePtr; // [esp+10h] [ebp-4h]

  v6 = 0;
  if ( a2 > 0x2A )
  {
    return 0;
  }
  for ( i = 0;
        i < *(char *)(*((_DWORD *)this + 94) + 57);
        ++i )
  {
    v3 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
    PilePtr = CPileMgr::GetPilePtr(*v3);
    if ( CPile::GetRoleType(PilePtr) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1705, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v4 = (CTradePileRole *)CPile::Role(PilePtr);
    if ( (CTradePileRole::GetTradeRoleType(v4) == 1 || CTradePileRole::GetTradeRoleType(v4) == 3) && ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr) == a2 )
    {
      v6 += PilePtr->Amount(PilePtr);
    }
  }
  return v6;
}


// address=[0x15230e0]
// Decompiled from int __thiscall CTradingBuildingRole::GetRequestedAmount(CTradingBuildingRole *this, unsigned int a2, bool a3)
int  CTradingBuildingRole::GetRequestedAmount(int a2, bool a3) {
  
  unsigned __int16 *v4; // eax
  CTradePileRole *v5; // [esp+0h] [ebp-18h]
  int v6; // [esp+4h] [ebp-14h]
  signed int i; // [esp+Ch] [ebp-Ch]
  CPile *PilePtr; // [esp+10h] [ebp-8h]
  bool v10; // [esp+17h] [ebp-1h]

  v6 = 0;
  if ( a2 > 0x2A )
  {
    return 0;
  }
  if ( *((_BYTE *)this + a2 + 384) == 0 && *((_BYTE *)this + a2 + 513) == 0 )
  {
    return 0;
  }
  for ( i = 0;
        i < *(char *)(*((_DWORD *)this + 94) + 57);
        ++i )
  {
    v4 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
    PilePtr = CPileMgr::GetPilePtr(*v4);
    if ( CPile::GetRoleType(PilePtr) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1854, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v5 = (CTradePileRole *)CPile::Role(PilePtr);
    if ( a3 )
    {
      v10 = CTradePileRole::GetTradeRoleType(v5) == 3;
    }
    else
    {
      v10 = CTradePileRole::GetTradeRoleType(v5) == 1;
    }
    if ( v10 && ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr) == a2 )
    {
      v6 += CPile::AmountComing(PilePtr);
    }
  }
  return v6;
}


// address=[0x1523220]
// Decompiled from int __thiscall CTradingBuildingRole::GetExpectedAmount(CTradingBuildingRole *this, unsigned int a2, bool a3)
int  CTradingBuildingRole::GetExpectedAmount(int a2, bool a3) {
  
  unsigned __int16 *v4; // eax
  int v6; // [esp+4h] [ebp-14h]
  pairNode *v7; // [esp+8h] [ebp-10h]
  CPile *PilePtr; // [esp+Ch] [ebp-Ch]
  signed int i; // [esp+10h] [ebp-8h]
  bool v10; // [esp+17h] [ebp-1h]

  v6 = 0;
  if ( a2 > 0x2A )
  {
    return 0;
  }
  for ( i = 0;
        i < *(char *)(*((_DWORD *)this + 94) + 57);
        ++i )
  {
    v4 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
    PilePtr = CPileMgr::GetPilePtr(*v4);
    if ( CPile::GetRoleType(PilePtr) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1907, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v7 = (pairNode *)CPile::Role(PilePtr);
    if ( a3 )
    {
      v10 = CTradePileRole::GetTradeRoleType((CTradePileRole *)v7) == 3;
    }
    else
    {
      v10 = CTradePileRole::GetTradeRoleType((CTradePileRole *)v7) == 1;
    }
    if ( v10 && ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr) == a2 )
    {
      v6 += CTradePileRole::GetExpectedAmount((CTradePileRole *)v7);
    }
  }
  return v6;
}


// address=[0x1523330]
// Decompiled from int __thiscall CTradingBuildingRole::GetExpectedAmountForAllPikes(_DWORD *this, unsigned int a2)
int  CTradingBuildingRole::GetExpectedAmountForAllPikes(int a2) {
  
  unsigned __int16 *v3; // eax
  pairNode *v4; // [esp+0h] [ebp-14h]
  int v6; // [esp+8h] [ebp-Ch]
  CPile *PilePtr; // [esp+Ch] [ebp-8h]
  signed int i; // [esp+10h] [ebp-4h]

  v6 = 0;
  if ( a2 > 0x2A )
  {
    return 0;
  }
  for ( i = 0;
        i < *(char *)(*(this + 94) + 57);
        ++i )
  {
    v3 = std::vector<unsigned short>::operator[](this + 152, i);
    PilePtr = CPileMgr::GetPilePtr(*v3);
    if ( CPile::GetRoleType(PilePtr) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1955, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v4 = (pairNode *)CPile::Role(PilePtr);
    if ( ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr) == a2 )
    {
      v6 += CTradePileRole::GetExpectedAmount((CTradePileRole *)v4);
    }
  }
  return v6;
}


// address=[0x1523400]
// Decompiled from int __thiscall CTradingBuildingRole::GetGoodAmount(_DWORD *this, unsigned int a2)
int  CTradingBuildingRole::GetGoodAmount(int a2) {
  
  unsigned __int16 *v3; // eax
  int v4; // eax
  int v6; // [esp+8h] [ebp-Ch]
  signed int i; // [esp+Ch] [ebp-8h]
  CPile *PilePtr; // [esp+10h] [ebp-4h]

  v6 = 0;
  if ( a2 > 0x2A )
  {
    return 0;
  }
  for ( i = 0;
        i < *(char *)(*(this + 94) + 57);
        ++i )
  {
    v3 = std::vector<unsigned short>::operator[](this + 152, i);
    PilePtr = CPileMgr::GetPilePtr(*v3);
    if ( CPile::GetRoleType(PilePtr) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1812, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v4 = CPile::Role(PilePtr);
    if ( ((int (__thiscall *)(CPile *, int))PilePtr->GetGoodType)(PilePtr, v4) == a2 )
    {
      v6 += PilePtr->Amount(PilePtr);
    }
  }
  return v6;
}


// address=[0x15234e0]
// Decompiled from int __thiscall CTradingBuildingRole::GetExportGoodAmount(CTradingBuildingRole *this, unsigned int a2)
int  CTradingBuildingRole::GetExportGoodAmount(int a2) {
  
  unsigned __int16 *v3; // eax
  CTradePileRole *v4; // [esp+0h] [ebp-18h]
  int v5; // [esp+4h] [ebp-14h]
  int v6; // [esp+8h] [ebp-10h]
  signed int i; // [esp+10h] [ebp-8h]
  CPile *PilePtr; // [esp+14h] [ebp-4h]

  v6 = 0;
  if ( a2 > 0x2A )
  {
    return 0;
  }
  for ( i = 0;
        i < *(char *)(*((_DWORD *)this + 94) + 57);
        ++i )
  {
    v3 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
    PilePtr = CPileMgr::GetPilePtr(*v3);
    if ( CPile::GetRoleType(PilePtr) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1742, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v4 = (CTradePileRole *)CPile::Role(PilePtr);
    v5 = ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr);
    if ( (unsigned __int8)CTradingBuildingRole::HasGoodState(this, v5, 8) != 0 && CTradePileRole::GetTradeRoleType(v4) == 3 && ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr) == a2 )
    {
      v6 += PilePtr->Amount(PilePtr);
    }
  }
  return v6;
}


// address=[0x15235f0]
// Decompiled from int __thiscall CTradingBuildingRole::GetExportResGoodAmount(CTradingBuildingRole *this, unsigned int a2)
int  CTradingBuildingRole::GetExportResGoodAmount(int a2) {
  
  unsigned __int16 *v3; // eax
  CTradePileRole *v4; // [esp+0h] [ebp-18h]
  int v5; // [esp+4h] [ebp-14h]
  int v6; // [esp+8h] [ebp-10h]
  signed int i; // [esp+10h] [ebp-8h]
  CPile *PilePtr; // [esp+14h] [ebp-4h]

  v6 = 0;
  if ( a2 > 0x2A )
  {
    return 0;
  }
  for ( i = 0;
        i < *(char *)(*((_DWORD *)this + 94) + 57);
        ++i )
  {
    v3 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
    PilePtr = CPileMgr::GetPilePtr(*v3);
    if ( CPile::GetRoleType(PilePtr) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 1773, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v4 = (CTradePileRole *)CPile::Role(PilePtr);
    v5 = ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr);
    if ( (unsigned __int8)CTradingBuildingRole::HasGoodState(this, v5, 8) != 0 && CTradePileRole::GetTradeRoleType(v4) == 4 && ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr) == a2 )
    {
      v6 += PilePtr->Amount(PilePtr);
    }
  }
  return v6;
}


// address=[0x1523700]
// Decompiled from void __thiscall CTradingBuildingRole::CheckTradingStatus(CInternationalTrader **this)
void  CTradingBuildingRole::CheckTradingStatus(void) {
  
  bool CanWalk; // [esp+6h] [ebp-2h]

  if ( *((_WORD *)this + 191) != 0 )
  {
    CanWalk = CInternationalTrader::CanWalk(*(this + 171), *((unsigned __int16 *)this + 3), *((unsigned __int16 *)this + 191));
    if ( !CInternationalTrader::CheckGoodMatch(*(this + 171), *((unsigned __int16 *)this + 3), *((unsigned __int16 *)this + 191)) || !CanWalk )
    {
      ((void (__thiscall *)(CTradingBuildingRole *))CTradingBuildingRole::DisableTranding)((CTradingBuildingRole *)this);
    }
  }
}


// address=[0x1523780]
// Decompiled from unsigned __int8 *__thiscall CTradingBuildingRole::CheckPiles(CTradingBuildingRole *this)
void  CTradingBuildingRole::CheckPiles(void) {
  
  unsigned __int8 *result; // eax
  unsigned __int16 *v2; // eax
  int v3; // [esp+0h] [ebp-18h]
  unsigned __int8 *v4; // [esp+4h] [ebp-14h]
  signed int i; // [esp+8h] [ebp-10h]
  CTradePileRole *v7; // [esp+10h] [ebp-8h]
  CPile *PilePtr; // [esp+14h] [ebp-4h]

  result = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
  v4 = result;
  if ( result == 0 )
  {
    result = (unsigned __int8 *)BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 2005, "pBuilding!=NULL");
    if ( result == (unsigned __int8 *)1 )
    {
      __debugbreak();
    }
  }
  if ( v4 != 0 )
  {
    v3 = IEntity::OwnerId((IEntity *)v4);
    for ( i = 0;
          ;
          ++i )
    {
      result = (unsigned __int8 *)*(char *)(*((_DWORD *)this + 94) + 57);
      if ( i >= (int)result )
      {
        break;
      }
      v2 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
      PilePtr = CPileMgr::GetPilePtr(*v2);
      if ( CPile::GetRoleType(PilePtr) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 2013, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
      {
        __debugbreak();
      }
      v7 = (CTradePileRole *)CPile::Role(PilePtr);
      if ( ((int (__thiscall *)(CPile *, int))PilePtr->Amount)(PilePtr, v3) == 0 && CTradePileRole::GetTradeRoleType(v7) == 2 )
      {
        CTradePileRole::SetTradeRoleType(v7, 0);
        ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
        CPile::SetGoodType(PilePtr, 0);
      }
      if ( CTradePileRole::GetTradeRoleType(v7) == 0 && PilePtr->Amount(PilePtr) > 0 && *((_WORD *)this + 191) == 0 )
      {
        CTradePileRole::SetTradeRoleType(v7, 2);
      }
      if ( PilePtr->Amount(PilePtr) != 0 && *((_BYTE *)this + ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr) + 427) == 0 && CTradePileRole::GetTradeRoleType(v7) == 1 )
      {
        CTradePileRole::SetTradeRoleType(v7, 2);
        ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
      }
    }
  }
  return result;
}


// address=[0x1523930]
// Decompiled from void __thiscall CTradingBuildingRole::SetNewTraderTarget(int this, struct CWnd *a2)
void  CTradingBuildingRole::SetNewTraderTarget(int a2) {
  
  int *v2; // eax
  int v3; // [esp+0h] [ebp-34h]
  int v4; // [esp+4h] [ebp-30h]
  CDonkeyRole *v5; // [esp+8h] [ebp-2Ch]
  unsigned __int8 *v6; // [esp+Ch] [ebp-28h]
  CTransportShip *v7; // [esp+10h] [ebp-24h]
  unsigned __int8 *SettlerPtr; // [esp+14h] [ebp-20h]
  struct CVehicle *v9; // [esp+18h] [ebp-1Ch]
  CDonkeyRole *v10; // [esp+1Ch] [ebp-18h]
  CTransportShip *VehiclePtr; // [esp+20h] [ebp-14h]
  struct CVehicle *v12; // [esp+28h] [ebp-Ch]
  unsigned int i; // [esp+2Ch] [ebp-8h]

  for ( i = 0;
        i < std::vector<CTradingBuildingRole::STradersEx>::size(this + 668);
        ++i )
  {
    v2 = (int *)std::vector<CTradingBuildingRole::STradersEx>::operator[](i);
    v3 = *v2;
    v4 = v2[1];
    switch ( v4 )
    {
      case 1:
        VehiclePtr = (CTransportShip *)CVehicleMgr::GetVehiclePtr(v3);
        if ( !CTransportShip::IsNeutralTrader(VehiclePtr) && CTransportShip::GetJobType(VehiclePtr) == 2 )
        {
          CTransportShip::SetTargetHarbourID(VehiclePtr, (int)a2);
        }
        break;
      case 2:
        SettlerPtr = ((unsigned __int8 *(__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(v3);
        v10 = (CDonkeyRole *)CSettler::Role((CSettler *)SettlerPtr);
        if ( !CDonkeyRole::IsNeutralTrader(v10) && CDonkeyRole::GetJobType(v10) == 2 )
        {
          CDonkeyRole::SetTargetBuildingID(v10, (int)a2);
        }
        break;
      case 3:
        v12 = (struct CVehicle *)CVehicleMgr::GetVehiclePtr(v3);
        if ( v12 != 0 )
        {
          if ( CCart::GetJobType((CCart *)v12) == 2 )
          {
            CCart::SetTargetBuildingID((CMFCPopupMenu *)v12, a2);
          }
        }
        else
        {
          CTradingBuildingRole::UnregisterIncomingTrader((CTradingBuildingRole *)this, v3, v4);
        }
        break;
      default:
        break;
    }
  }
  if ( *(_BYTE *)(this + 636) != 0 )
  {
    v7 = (CTransportShip *)CVehicleMgr::GetVehiclePtr(*(_DWORD *)(this + 632));
    CTransportShip::SetTargetHarbourID(v7, (int)a2);
  }
  else if ( *(_BYTE *)(this + 660) != 0 )
  {
    v9 = (struct CVehicle *)CVehicleMgr::GetVehiclePtr(*(_DWORD *)(this + 656));
    if ( v9 != 0 )
    {
      CCart::SetTargetBuildingID((CMFCPopupMenu *)v9, a2);
    }
  }
  else if ( *(_BYTE *)(this + 648) != 0 )
  {
    v6 = ((unsigned __int8 *(__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(*(_DWORD *)(this + 644));
    v5 = (CDonkeyRole *)CSettler::Role((CSettler *)v6);
    CDonkeyRole::SetTargetBuildingID(v5, (int)a2);
  }
}


// address=[0x1523b20]
// Decompiled from int __thiscall CTradingBuildingRole::GetTargetBuildingAvailableSpace(CTradingBuildingRole *this, int a2, unsigned int a3)
int  CTradingBuildingRole::GetTargetBuildingAvailableSpace(int a2, int a3) {
  
  CTradingBuildingRole *v4; // [esp+4h] [ebp-8h]
  unsigned __int8 *BuildingPtr; // [esp+8h] [ebp-4h]

  if ( a2 == 0 )
  {
    return 0;
  }
  BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a2);
  v4 = (CTradingBuildingRole *)CBuilding::Role((CBuilding *)BuildingPtr);
  return CTradingBuildingRole::GetGoodSpaceAmount(v4, a3);
}


// address=[0x1523b70]
// Decompiled from char __thiscall CTradingBuildingRole::RequestVehicle(CTradingBuildingRole *this, struct CBuilding *a2, bool a3)
bool  CTradingBuildingRole::RequestVehicle(class CBuilding * a2, bool a3) {
  
  int v4; // [esp+8h] [ebp-24h]
  int v5; // [esp+Ch] [ebp-20h]
  int v6; // [esp+10h] [ebp-1Ch]
  int TargetBuildingID; // [esp+14h] [ebp-18h]
  int v8; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *BuildingPtr; // [esp+20h] [ebp-Ch]
  char v12; // [esp+2Bh] [ebp-1h]

  v12 = 0;
  if ( (int)CTradingBuildingRole::CalcNrExportGoods(this, a3) <= 0 )
  {
    return 0;
  }
  if ( !a3 )
  {
    v8 = 0;
    for ( i = 0;
          i < 43;
          ++i )
    {
      v8 += *((char *)this + i + 427);
    }
    if ( v8 <= 0 )
    {
      return 0;
    }
  }
  TargetBuildingID = CTradingBuildingRole::GetTargetBuildingID(this, a3);
  if ( TargetBuildingID != 0 )
  {
    BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, TargetBuildingID);
    v6 = IEntity::Type((IEntity *)BuildingPtr);
    v5 = IEntity::Type(a2);
    if ( v6 == 32 && v5 == 32 )
    {
      if ( CTradingBuildingRole::RequestTradeShip(this, a2, (struct CBuilding *)BuildingPtr, a3) )
      {
        return 1;
      }
    }
    else if ( v6 == 33 || v5 == 33 )
    {
      if ( a3 )
      {
        if ( CTradingBuildingRole::RequestDonkey(this, a2, (struct CBuilding *)BuildingPtr, a3) )
        {
          return 1;
        }
      }
      else
      {
        v4 = CTradingBuildingRole::CalcNrExportGoods(this, 0);
        if ( v4 != 0 )
        {
          if ( v4 <= 16 )
          {
            if ( CTradingBuildingRole::RequestDonkey(this, a2, (struct CBuilding *)BuildingPtr, 0) )
            {
              return 1;
            }
            else if ( CTradingBuildingRole::RequestCart(this, a2, (struct CBuilding *)BuildingPtr, 0) )
            {
              return 1;
            }
          }
          else if ( CTradingBuildingRole::RequestCart(this, a2, (struct CBuilding *)BuildingPtr, 0) )
          {
            return 1;
          }
          else if ( CTradingBuildingRole::GetNrRegisteredIncomingTraders(this, 3, 0) == 0 && CTradingBuildingRole::RequestDonkey(this, a2, (struct CBuilding *)BuildingPtr, 0) )
          {
            return 1;
          }
        }
      }
    }
  }
  return v12;
}


// address=[0x1523d60]
// Decompiled from bool __thiscall CTradingBuildingRole::IsVehicleRequested(CTradingBuildingRole *this, struct CBuilding *a2, bool a3)
bool  CTradingBuildingRole::IsVehicleRequested(class CBuilding * a2, bool a3) {
  
  int v5; // [esp+4h] [ebp-18h]
  int v6; // [esp+8h] [ebp-14h]
  unsigned __int8 *BuildingPtr; // [esp+10h] [ebp-Ch]
  char v9; // [esp+1Bh] [ebp-1h]

  if ( a2 == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 2251, "_pBuilding!=NULL") == 1 )
  {
    __debugbreak();
  }
  if ( a2 == 0 )
  {
    return 0;
  }
  v9 = 0;
  if ( a3 )
  {
    BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 191));
  }
  else
  {
    BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 190));
  }
  if ( BuildingPtr != 0 )
  {
    v6 = IEntity::Type((IEntity *)BuildingPtr);
    v5 = IEntity::Type(a2);
    if ( v6 == 32 && v5 == 32 )
    {
      return CTradingBuildingRole::GetNrRegisteredIncomingTraders(this, 1, a3) != 0;
    }
    else if ( v6 == 33 || v5 == 33 )
    {
      return CTradingBuildingRole::GetNrRegisteredIncomingTraders(this, 3, a3) != 0 || CTradingBuildingRole::GetNrRegisteredIncomingTraders(this, 2, a3) != 0;
    }
  }
  return v9;
}


// address=[0x1523e90]
// Decompiled from bool __thiscall CTradingBuildingRole::IsVehicleAtBuilding(CTradingBuildingRole *this, unsigned __int16 *a2)
bool  CTradingBuildingRole::IsVehicleAtBuilding(class CBuilding * a2) {
  
  unsigned __int8 *BuildingPtr; // [esp+0h] [ebp-14h]
  int v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch]
  char v7; // [esp+13h] [ebp-1h]

  v7 = 0;
  if ( *((_WORD *)this + 190) != 0 )
  {
    BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 190));
    v5 = IEntity::Type((IEntity *)BuildingPtr);
    v4 = IEntity::Type((IEntity *)a2);
    if ( v5 == 32 && v4 == 32 )
    {
      return CTradingBuildingRole::IsShipInHarbour(this, (struct CBuilding *)a2);
    }
    else if ( (v5 == 33 || v4 == 33) && (CTradingBuildingRole::IsDonkeyAtBuilding(this, (struct CBuilding *)a2) || CTradingBuildingRole::IsCartAtBuilding(this, (struct CBuilding *)a2)) )
    {
      return 1;
    }
  }
  return v7;
}


// address=[0x1523f50]
// Decompiled from void __thiscall CTradingBuildingRole::LoadVehicle(CTradingBuildingRole *this)
void  CTradingBuildingRole::LoadVehicle(void) {
  
  int v2; // [esp+4h] [ebp-4h]

  v2 = CTradingBuildingRole::DetermineTransportType(this);
  if ( v2 != 0 )
  {
    if ( v2 == 1 )
    {
      CTradingBuildingRole::LoadShip(this);
    }
    if ( v2 == 2 )
    {
      CTradingBuildingRole::LoadDonkey(this);
    }
    if ( v2 == 3 )
    {
      CTradingBuildingRole::LoadCart(this);
    }
  }
}


// address=[0x1523fa0]
// Decompiled from char __thiscall CTradingBuildingRole::IsLoadingFinished(CTradingBuildingRole *this)
bool  CTradingBuildingRole::IsLoadingFinished(void) {
  
  unsigned __int16 *v2; // eax
  int v3; // eax
  CEcoSector *v4; // eax
  int GoodOffer; // esi
  int v6; // [esp-4h] [ebp-48h]
  int v7; // [esp+4h] [ebp-40h]
  CDonkeyRole *v8; // [esp+8h] [ebp-3Ch]
  CDonkeyRole *v10; // [esp+10h] [ebp-34h]
  int v11; // [esp+14h] [ebp-30h]
  unsigned __int8 *v12; // [esp+18h] [ebp-2Ch]
  unsigned __int8 *SettlerPtr; // [esp+1Ch] [ebp-28h]
  pairNode *v14; // [esp+20h] [ebp-24h]
  signed int i; // [esp+24h] [ebp-20h]
  CCart *v16; // [esp+28h] [ebp-1Ch]
  int v17; // [esp+2Ch] [ebp-18h]
  int v18; // [esp+30h] [ebp-14h]
  int v19; // [esp+30h] [ebp-14h]
  CTransportShip *VehiclePtr; // [esp+34h] [ebp-10h]
  CPile *PilePtr; // [esp+38h] [ebp-Ch]
  char v23; // [esp+41h] [ebp-3h]
  char IsNeutralTrader; // [esp+42h] [ebp-2h]
  char IsSpaceAvailable; // [esp+43h] [ebp-1h]

  VehiclePtr = 0;
  v16 = 0;
  IsNeutralTrader = 0;
  v23 = 1;
  v18 = 0;
  if ( *((_BYTE *)this + 636) == 0 && *((_BYTE *)this + 648) == 0 && *((_BYTE *)this + 660) == 0 )
  {
    return 0;
  }
  if ( *((_BYTE *)this + 636) != 0 )
  {
    VehiclePtr = (CTransportShip *)CVehicleMgr::GetVehiclePtr(*((_DWORD *)this + 158));
    if ( VehiclePtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 2394, "pShip") == 1 )
    {
      __debugbreak();
    }
    if ( VehiclePtr != 0 )
    {
      IsNeutralTrader = CTransportShip::IsNeutralTrader(VehiclePtr);
      if ( CTransportShip::IsFull(VehiclePtr) )
      {
        return 1;
      }
    }
  }
  else if ( *((_BYTE *)this + 648) != 0 )
  {
    if ( !CMapObjectMgr::ValidEntityId(*((_DWORD *)this + 161)) && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 2405, "g_pMapObjectMgr->ValidEntityId(m_iDonkeyId)") == 1 )
    {
      __debugbreak();
    }
    SettlerPtr = ((unsigned __int8 *(__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(*((_DWORD *)this + 161));
    if ( SettlerPtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 2407, "pDonkey!=NULL") == 1 )
    {
      __debugbreak();
    }
    if ( IEntity::Type((IEntity *)SettlerPtr) != 60 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 2409, "pDonkey->Type() == SETTLER_DONKEY") == 1 )
    {
      __debugbreak();
    }
    v10 = (CDonkeyRole *)CSettler::Role((CSettler *)SettlerPtr);
    IsNeutralTrader = CDonkeyRole::IsNeutralTrader(v10);
    if ( CDonkeyRole::IsFull(v10) != 0 )
    {
      return 1;
    }
  }
  else if ( *((_BYTE *)this + 660) != 0 )
  {
    v16 = (CCart *)CVehicleMgr::GetVehiclePtr(*((_DWORD *)this + 164));
    if ( v16 == 0 )
    {
      *((_DWORD *)this + 164) = 0;
      *((_BYTE *)this + 660) = 0;
      return 0;
    }
    IsNeutralTrader = CCart::IsNeutralTrader(v16);
    if ( CCart::IsFull(v16) != 0 )
    {
      return 1;
    }
  }
  if ( IsNeutralTrader != 0 )
  {
    v11 = *((unsigned __int16 *)this + 191);
  }
  else
  {
    v11 = *((unsigned __int16 *)this + 190);
  }
  for ( i = 0;
        i < *(char *)(*((_DWORD *)this + 94) + 57);
        ++i )
  {
    v2 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
    PilePtr = CPileMgr::GetPilePtr(*v2);
    if ( CPile::GetRoleType(PilePtr) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 2445, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v17 = ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr);
    v14 = (pairNode *)CPile::Role(PilePtr);
    if ( CTradePileRole::GetTradeRoleType((CTradePileRole *)v14) == 1 && *((_BYTE *)this + v17 + 470) != 0 && *((_BYTE *)this + v17 + 427) != 0 )
    {
      IsSpaceAvailable = 1;
      if ( *((_BYTE *)this + 636) != 0 )
      {
        if ( VehiclePtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 2457, "pShip") == 1 )
        {
          __debugbreak();
        }
        if ( VehiclePtr != 0 )
        {
          IsSpaceAvailable = CTransportShip::IsSpaceAvailable(VehiclePtr, v17);
        }
      }
      else if ( *((_BYTE *)this + 648) != 0 )
      {
        v12 = ((unsigned __int8 *(__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(*((_DWORD *)this + 161));
        if ( v12 == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 2465, "pDonkey!=NULL") == 1 )
        {
          __debugbreak();
        }
        if ( v12 != 0 )
        {
          v8 = (CDonkeyRole *)CSettler::Role((CSettler *)v12);
          IsSpaceAvailable = CDonkeyRole::IsSpaceAvailable(v8, v17);
        }
      }
      else if ( *((_BYTE *)this + 660) != 0 )
      {
        IsSpaceAvailable = CCart::IsSpaceAvailable(v16, v17);
      }
      if ( IsSpaceAvailable != 0 && CTradingBuildingRole::GetTargetBuildingAvailableSpace(this, v11, v17) != 0 )
      {
        v19 = v18 + PilePtr->Amount(PilePtr);
        v18 = v19 + CPile::AmountComing(PilePtr);
        if ( CTradePileRole::GetExpectedAmount((CTradePileRole *)v14) != 0 )
        {
          v3 = ((int (__stdcall *)())IEntity::WorldIdx)();
          v7 = CWorldManager::EcoSectorId(v3);
          v6 = ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr);
          v4 = (CEcoSector *)((int (__stdcall *)(int))CEcoSectorMgr::operator[])(v7);
          GoodOffer = CEcoSector::GetGoodOffer(v4, v6);
          if ( GoodOffer >= CTradePileRole::GetExpectedAmount((CTradePileRole *)v14) )
          {
            v18 += CTradePileRole::GetExpectedAmount((CTradePileRole *)v14);
          }
        }
      }
    }
  }
  if ( v18 != 0 )
  {
    return 0;
  }
  return v23;
}


// address=[0x1524470]
// Decompiled from void __thiscall CTradingBuildingRole::SendVehicle(CTradingBuildingRole *this)
void  CTradingBuildingRole::SendVehicle(void) {
  
  int v2; // [esp+4h] [ebp-4h]

  v2 = CTradingBuildingRole::DetermineTransportType(this);
  if ( v2 != 0 )
  {
    if ( v2 == 1 )
    {
      CTradingBuildingRole::SendShip(this);
    }
    if ( v2 == 2 )
    {
      CTradingBuildingRole::SendDonkey(this);
    }
    if ( v2 == 3 )
    {
      CTradingBuildingRole::SendCart(this);
    }
  }
}


// address=[0x15244c0]
// Decompiled from void __thiscall CTradingBuildingRole::UnloadVehicle(CTradingBuildingRole *this)
void  CTradingBuildingRole::UnloadVehicle(void) {
  
  if ( *((_BYTE *)this + 637) != 0 )
  {
    CTradingBuildingRole::UnloadShip(this);
  }
  if ( *((_BYTE *)this + 649) != 0 )
  {
    CTradingBuildingRole::UnloadDonkey(this);
  }
  if ( *((_BYTE *)this + 661) != 0 )
  {
    CTradingBuildingRole::UnloadCart(this);
  }
}


// address=[0x1524510]
// Decompiled from unsigned __int8 *__thiscall CTradingBuildingRole::TransportHandling(CTradingBuildingRole *this, struct CBuilding *a2)
void  CTradingBuildingRole::TransportHandling(class CBuilding * a2) {
  
  unsigned __int8 *result; // eax
  IEntity *v3; // eax
  int RequestedAmount; // [esp+0h] [ebp-10h]
  int CurrentAmount; // [esp+4h] [ebp-Ch]
  signed int i; // [esp+8h] [ebp-8h]

  if ( a2 == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 2568, "_pBuilding") == 1 )
  {
    __debugbreak();
  }
  result = (unsigned __int8 *)IEntity::FlagBits(a2, (EntityFlag)4096);
  if ( result != 0 && ((unsigned __int8)CBuilding::HaveInhabitant() != 0 || (result = (unsigned __int8 *)IEntity::Type(a2)) == (unsigned __int8 *)33) )
  {
    for ( i = 0;
          i < 43;
          ++i )
    {
      if ( *((_BYTE *)this + i + 470) != 0 )
      {
        CTradingBuildingRole::CheckTransport(this, a2, i);
        CTradingBuildingRole::CheckTradingTransport(this, a2, i);
        if ( *((_WORD *)this + 190) != 0 )
        {
          CurrentAmount = CTradingBuildingRole::GetCurrentAmount(this, i);
          RequestedAmount = CTradingBuildingRole::GetRequestedAmount(this, i, 0);
          if ( CurrentAmount > 0 || RequestedAmount > 0 )
          {
            v3 = (IEntity *)((IEntity *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 190));
            if ( IEntity::FlagBits(v3, (EntityFlag)4096) != 0 && !CTradingBuildingRole::IsVehicleRequested(this, a2, 0) )
            {
              CTradingBuildingRole::RequestVehicle(this, a2, 0);
            }
          }
        }
      }
    }
    CTradingBuildingRole::LoadVehicle(this);
    if ( CTradingBuildingRole::IsLoadingFinished(this) != 0 )
    {
      CTradingBuildingRole::SendVehicle(this);
    }
    CTradingBuildingRole::CheckTradingStatus((CInternationalTrader **)this);
    CTradingBuildingRole::UnloadVehicle(this);
    return (unsigned __int8 *)CTradingBuildingRole::CheckPiles(this);
  }
  return result;
}


// address=[0x1524690]
// Decompiled from unsigned int __thiscall CTradingBuildingRole::CancelIncomingChargeTraders(CTradingBuildingRole *this)
void  CTradingBuildingRole::CancelIncomingChargeTraders(void) {
  
  unsigned int result; // eax
  int *v2; // eax
  int v3; // [esp+0h] [ebp-2Ch]
  int v4; // [esp+4h] [ebp-28h]
  unsigned __int8 *SettlerPtr; // [esp+Ch] [ebp-20h]
  unsigned __int8 *v6; // [esp+10h] [ebp-1Ch]
  CCart *v7; // [esp+18h] [ebp-14h]
  CDonkeyRole *v8; // [esp+1Ch] [ebp-10h]
  CTransportShip *VehiclePtr; // [esp+20h] [ebp-Ch]
  unsigned int i; // [esp+28h] [ebp-4h]

  for ( i = 0;
        ;
        ++i )
  {
    result = std::vector<CTradingBuildingRole::STradersEx>::size((char *)this + 668);
    if ( i >= result )
    {
      break;
    }
    v2 = (int *)std::vector<CTradingBuildingRole::STradersEx>::operator[](i);
    v3 = *v2;
    v4 = v2[1];
    switch ( v4 )
    {
      case 1:
        v6 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(v3);
        if ( IEntity::ObjType((IEntity *)v6) == SHIP_OBJ )
        {
          VehiclePtr = (CTransportShip *)CVehicleMgr::GetVehiclePtr(v3);
          if ( VehiclePtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 2641, "pShip != NULL") == 1 )
          {
            __debugbreak();
          }
          if ( VehiclePtr != 0 )
          {
            if ( CTransportShip::GetJobType(VehiclePtr) == 2 )
            {
              CTransportShip::DepartHarbourDestroyed((IEntity *)VehiclePtr);
              CTransportShip::TargetHarbourDestroyed(VehiclePtr);
              CTradingBuildingRole::UnregisterIncomingTrader(this, v3, 1);
              --i;
            }
            if ( CTransportShip::IsNeutralTrader(VehiclePtr) )
            {
              CTradingBuildingRole::UnregisterIncomingTrader(this, v3, 1);
              --i;
            }
          }
        }
        break;
      case 2:
        SettlerPtr = ((unsigned __int8 *(__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(v3);
        v8 = (CDonkeyRole *)CSettler::Role((CSettler *)SettlerPtr);
        if ( CDonkeyRole::GetJobType(v8) == 2 )
        {
          CDonkeyRole::DepartBuildingDestroyed(v8);
          CDonkeyRole::TargetBuildingDestroyed(v8);
          CTradingBuildingRole::UnregisterIncomingTrader(this, v3, v4);
          --i;
        }
        if ( CDonkeyRole::IsNeutralTrader(v8) )
        {
          CTradingBuildingRole::UnregisterIncomingTrader(this, v3, v4);
          CDonkeyRole::SetJobType(v8, 1);
          CDonkeyRole::GoToHomeTradingBuilding(v8);
          --i;
        }
        break;
      case 3:
        v7 = (CCart *)CVehicleMgr::GetVehiclePtr(v3);
        if ( v7 != 0 && CCart::GetJobType(v7) == 2 )
        {
          CCart::DepartBuildingDestroyed(v7);
          CCart::TargetBuildingDestroyed(v7);
          CTradingBuildingRole::UnregisterIncomingTrader(this, v3, v4);
          --i;
        }
        break;
      default:
        break;
    }
  }
  return result;
}


// address=[0x15248b0]
// Decompiled from unsigned int __thiscall CTradingBuildingRole::CancelIncomingDeliverTraders(CTradingBuildingRole *this)
void  CTradingBuildingRole::CancelIncomingDeliverTraders(void) {
  
  unsigned int result; // eax
  int *v2; // eax
  int v3; // [esp+0h] [ebp-28h]
  int v4; // [esp+4h] [ebp-24h]
  unsigned __int8 *SettlerPtr; // [esp+Ch] [ebp-1Ch]
  CDonkeyRole *v6; // [esp+10h] [ebp-18h]
  CTransportShip *VehiclePtr; // [esp+14h] [ebp-14h]
  CCart *v8; // [esp+1Ch] [ebp-Ch]
  unsigned int i; // [esp+24h] [ebp-4h]

  for ( i = 0;
        ;
        ++i )
  {
    result = std::vector<CTradingBuildingRole::STradersEx>::size((char *)this + 668);
    if ( i >= result )
    {
      break;
    }
    v2 = (int *)std::vector<CTradingBuildingRole::STradersEx>::operator[](i);
    v3 = *v2;
    v4 = v2[1];
    switch ( v4 )
    {
      case 1:
        VehiclePtr = (CTransportShip *)CVehicleMgr::GetVehiclePtr(v3);
        if ( CTransportShip::GetJobType(VehiclePtr) == 1 )
        {
          CTransportShip::TargetHarbourDestroyed(VehiclePtr);
          CTradingBuildingRole::UnregisterIncomingTrader(this, v3, 1);
          --i;
        }
        break;
      case 2:
        SettlerPtr = ((unsigned __int8 *(__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(v3);
        v6 = (CDonkeyRole *)CSettler::Role((CSettler *)SettlerPtr);
        if ( CDonkeyRole::GetJobType(v6) == 1 )
        {
          CDonkeyRole::TargetBuildingDestroyed(v6);
          CTradingBuildingRole::UnregisterIncomingTrader(this, v3, v4);
          --i;
        }
        break;
      case 3:
        v8 = (CCart *)CVehicleMgr::GetVehiclePtr(v3);
        if ( v8 != 0 )
        {
          if ( CCart::GetJobType(v8) == 1 )
          {
            CCart::TargetBuildingDestroyed(v8);
            CTradingBuildingRole::UnregisterIncomingTrader(this, v3, v4);
            --i;
          }
        }
        else
        {
          CTradingBuildingRole::UnregisterIncomingTrader(this, v3, v4);
        }
        break;
      default:
        break;
    }
  }
  return result;
}


// address=[0x1524a20]
// Decompiled from void __thiscall CTradingBuildingRole::CancelLoadingVehicle(CTradingBuildingRole *this)
void  CTradingBuildingRole::CancelLoadingVehicle(void) {
  
  IEntity *v1; // eax
  CDonkeyRole *v2; // [esp+0h] [ebp-18h]
  unsigned __int8 *SettlerPtr; // [esp+4h] [ebp-14h]
  CCart *v4; // [esp+8h] [ebp-10h]
  CTransportShip *VehiclePtr; // [esp+Ch] [ebp-Ch]
  bool v7; // [esp+17h] [ebp-1h]

  v7 = 0;
  if ( *((_WORD *)this + 190) != 0 )
  {
    v1 = (IEntity *)((IEntity *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 190));
    v7 = IEntity::FlagBits(v1, (EntityFlag)&loc_3000000) != 0;
  }
  if ( *((_BYTE *)this + 636) != 0 )
  {
    if ( v7 )
    {
      CTradingBuildingRole::SendShip(this);
    }
    else
    {
      VehiclePtr = (CTransportShip *)CVehicleMgr::GetVehiclePtr(*((_DWORD *)this + 158));
      CTransportShip::TryToGoHome((Y16X16 **)VehiclePtr);
    }
  }
  else if ( *((_BYTE *)this + 660) != 0 )
  {
    if ( v7 )
    {
      CTradingBuildingRole::SendCart(this);
    }
    else
    {
      v4 = (CCart *)CVehicleMgr::GetVehiclePtr(*((_DWORD *)this + 164));
      CCart::TryToGoHome(v4);
    }
  }
  else if ( *((_BYTE *)this + 648) != 0 )
  {
    if ( v7 )
    {
      CTradingBuildingRole::SendDonkey(this);
    }
    else
    {
      SettlerPtr = ((unsigned __int8 *(__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(*((_DWORD *)this + 161));
      v2 = (CDonkeyRole *)CSettler::Role((CSettler *)SettlerPtr);
      CDonkeyRole::SetFree(v2);
    }
  }
}


// address=[0x1524b40]
// Decompiled from int __thiscall CTradingBuildingRole::GetVehicleAtBuildingFreeSpaceGood(int this, int a2)
int  CTradingBuildingRole::GetVehicleAtBuildingFreeSpaceGood(int a2) {
  
  CDonkeyRole *v3; // eax
  CCart *v4; // [esp+0h] [ebp-14h]
  unsigned __int8 *SettlerPtr; // [esp+8h] [ebp-Ch]
  CTransportShip *VehiclePtr; // [esp+Ch] [ebp-8h]

  if ( *(_BYTE *)(this + 636) != 0 )
  {
    VehiclePtr = (CTransportShip *)CVehicleMgr::GetVehiclePtr(*(_DWORD *)(this + 632));
    return CTransportShip::GetAvailableSpace(VehiclePtr, a2);
  }
  else if ( *(_BYTE *)(this + 648) != 0 )
  {
    SettlerPtr = ((unsigned __int8 *(__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(*(_DWORD *)(this + 644));
    v3 = (CDonkeyRole *)CSettler::Role((CSettler *)SettlerPtr);
    return CDonkeyRole::GetAvailableSpace(v3, a2);
  }
  else if ( *(_BYTE *)(this + 660) != 0 )
  {
    v4 = (CCart *)CVehicleMgr::GetVehiclePtr(*(_DWORD *)(this + 656));
    return CCart::GetAvailableSpace(v4, a2);
  }
  else
  {
    return 0;
  }
}


// address=[0x1524c00]
// Decompiled from int __thiscall CTradingBuildingRole::GetVehicleAtBuildingFreeSpace(int this)
int  CTradingBuildingRole::GetVehicleAtBuildingFreeSpace(void) {
  
  CCart *v2; // [esp+0h] [ebp-14h]
  CDonkeyRole *v3; // [esp+4h] [ebp-10h]
  unsigned __int8 *SettlerPtr; // [esp+8h] [ebp-Ch]
  CTransportShip *VehiclePtr; // [esp+Ch] [ebp-8h]

  if ( *(_BYTE *)(this + 636) != 0 )
  {
    VehiclePtr = (CTransportShip *)CVehicleMgr::GetVehiclePtr(*(_DWORD *)(this + 632));
    return CTransportShip::GetAvailableSpace(VehiclePtr);
  }
  else if ( *(_BYTE *)(this + 648) != 0 )
  {
    SettlerPtr = ((unsigned __int8 *(__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(*(_DWORD *)(this + 644));
    v3 = (CDonkeyRole *)CSettler::Role((CSettler *)SettlerPtr);
    return CDonkeyRole::GetAvailableSpace(v3);
  }
  else if ( *(_BYTE *)(this + 660) != 0 )
  {
    v2 = (CCart *)CVehicleMgr::GetVehiclePtr(*(_DWORD *)(this + 656));
    return CCart::GetAvailableSpace(v2);
  }
  else
  {
    return 0;
  }
}


// address=[0x1524cb0]
// Decompiled from CTradingBuildingRole *__thiscall CTradingBuildingRole::ClearRegisterTargetBuildings(CTradingBuildingRole *this)
void  CTradingBuildingRole::ClearRegisterTargetBuildings(void) {
  
  int BuildingID; // eax
  CTradingBuildingRole *result; // eax
  CTradingBuildingRole *v3; // [esp+0h] [ebp-Ch]
  unsigned __int8 *BuildingPtr; // [esp+4h] [ebp-8h]

  if ( *((_WORD *)this + 191) != 0 )
  {
    BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 191));
    if ( BuildingPtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4775, "pBuilding!=NULL") == 1 )
    {
      __debugbreak();
    }
    if ( BuildingPtr != 0 )
    {
      v3 = (CTradingBuildingRole *)CBuilding::Role((CBuilding *)BuildingPtr);
      BuildingID = CTradingBuildingRole::GetBuildingID(this);
      CTradingBuildingRole::DeteachTradingBuilding(v3, BuildingID);
    }
  }
  result = this;
  *((_WORD *)this + 190) = 0;
  return result;
}


// address=[0x1524d40]
// Decompiled from CTradingBuildingRole *__thiscall CTradingBuildingRole::DeteachTradingBuilding(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::DeteachTradingBuilding(int a2) {
  
  CTradingBuildingRole *result; // eax

  if ( *((unsigned __int16 *)this + 191) != a2 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4790, "m_uTargetTradingBuilding== iTradingBuildingID") == 1 )
  {
    __debugbreak();
  }
  result = this;
  if ( *((unsigned __int16 *)this + 191) == a2 )
  {
    result = this;
    *((_WORD *)this + 191) = 0;
  }
  return result;
}


// address=[0x1524da0]
// Decompiled from void __thiscall CTradingBuildingRole::SetTradingBuildingID(CTradingBuildingRole *this, unsigned int a2)
void  CTradingBuildingRole::SetTradingBuildingID(int a2) {
  
  int v2; // eax
  int TickCounter; // [esp-4h] [ebp-10h]
  unsigned __int8 *BuildingPtr; // [esp+4h] [ebp-8h]

  if ( !CMapObjectMgr::ValidEntityId(a2) && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4800, "g_pMapObjectMgr->ValidEntityId(_iTargetBuilding )") == 1 )
  {
    __debugbreak();
  }
  CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
  TickCounter = CGameData::GetTickCounter(g_pGameData);
  v2 = ((int (__stdcall *)())IEntity::ID)();
  BBSupportTracePrintF(0, "SetTradungBuilding %d for building %d at tick %d", a2, v2, TickCounter);
  if ( *((_WORD *)this + 191) == 0 )
  {
    *((_WORD *)this + 191) = a2;
    BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
    if ( BuildingPtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4813, "pBuilding!= NULL") == 1 )
    {
      __debugbreak();
    }
    if ( BuildingPtr != 0 && IEntity::IsSelected((IEntity *)BuildingPtr) )
    {
      CTradingBuildingRole::ShowTradeRoute(this);
    }
  }
}


// address=[0x1524ea0]
// Decompiled from char __thiscall CTradingBuildingRole::RequestTradeShip(CTradingBuildingRole *this, struct CBuilding *a2, struct CBuilding *a3, bool a4)
bool  CTradingBuildingRole::RequestTradeShip(class CBuilding * a2, class CBuilding * a3, bool a4) {
  
  int WorkingAreaPackedXY; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // [esp-8h] [ebp-54h]
  int v13; // [esp-4h] [ebp-50h]
  CEntityEvent v14; // [esp+4h] [ebp-48h] BYREF
  CEntityEvent *v15; // [esp+1Ch] [ebp-30h]
  CEntityEvent *v16; // [esp+20h] [ebp-2Ch]
  CTradingBuildingRole *v17; // [esp+24h] [ebp-28h]
  int ShipIDInHarbour; // [esp+28h] [ebp-24h]
  BOOL v19; // [esp+2Ch] [ebp-20h]
  CTransportShip *NearestEntity; // [esp+30h] [ebp-1Ch]
  CTradingBuildingRole *v21; // [esp+34h] [ebp-18h]
  CTransportShip *v22; // [esp+38h] [ebp-14h]
  bool v23; // [esp+3Fh] [ebp-Dh]
  int v24; // [esp+48h] [ebp-4h]

  v21 = this;
  if ( IEntity::Type(a2) != 32 )
  {
    return 1;
  }
  if ( a4 )
  {
    v17 = (CTradingBuildingRole *)CBuilding::Role(a3);
    if ( CTradingBuildingRole::IsShipRequested(v17) )
    {
      return 1;
    }
  }
  if ( CTradingBuildingRole::GetNrRegisteredIncomingTraders(v21, 1, a4) != 0 )
  {
    return 0;
  }
  NearestEntity = 0;
  v19 = CTradingBuildingRole::IsTradeShipInHarbour(v21, a2) && CTradingBuildingRole::IsShipInHarbour(v21, a2);
  v23 = v19;
  if ( v19 )
  {
    ShipIDInHarbour = CTradingBuildingRole::GetShipIDInHarbour(v21, a2);
    if ( ShipIDInHarbour != 0 )
    {
      NearestEntity = (CTransportShip *)CMapObjectMgr::EntityPtr(ShipIDInHarbour);
    }
  }
  else
  {
    WorkingAreaPackedXY = CBuilding::GetWorkingAreaPackedXY(a2);
    v13 = Y16X16::UnpackYFast(WorkingAreaPackedXY);
    v6 = CBuilding::GetWorkingAreaPackedXY(a2);
    v12 = Y16X16::UnpackXFast(v6);
    v7 = IEntity::OwnerId(a2);
    NearestEntity = (CTransportShip *)CTransportMgr::GetNearestEntity(2, 3, v7, v12, v13);
  }
  if ( NearestEntity == 0 )
  {
    return 0;
  }
  v22 = NearestEntity;
  if ( CTransportShip::GetJobType(NearestEntity) != 0 )
  {
    return 0;
  }
  v8 = ((int (__stdcall *)())IEntity::ID)();
  CTransportShip::SetDepartHarbourID(v22, v8);
  v9 = ((int (__stdcall *)())IEntity::ID)();
  CTransportShip::SetTargetHarbourID(v22, v9);
  CTransportShip::SetJobType(v22, 2);
  v10 = ((int (__stdcall *)())IEntity::ID)();
  CTradingBuildingRole::RegisterIncomingTrader(v21, v10, 1, a4);
  CTransportShip::MemHomePosition(v22);
  CTransportShip::SetGoToSource(v22, 1);
  CTransportShip::SetGoToTarget(v22, 0);
  v11 = CBuilding::GetWorkingAreaPackedXY(a2);
  v16 = CEntityEvent::CEntityEvent(&v14, 0x11u, 13, 0, v11, 0);
  v15 = v16;
  v24 = 0;
  (*(void (__thiscall **)(CTransportShip *, CEntityEvent *))(*(_DWORD *)v22 + 80))(v22, v16);
  v24 = -1;
  CEntityEvent::~CEntityEvent(&v14);
  CTransportShip::SetNeutralTraderStatus(v22, a4);
  ++*((_DWORD *)v21 + 172);
  return 1;
}


// address=[0x15250e0]
// Decompiled from int __thiscall CTradingBuildingRole::GetShipIDInHarbour(CTradingBuildingRole *this, struct CBuilding *a2)
int  CTradingBuildingRole::GetShipIDInHarbour(class CBuilding * a2) {
  
  Y16X16 *WorkingAreaPackedXY; // eax
  int v3; // eax
  unsigned __int16 *VehiclePtr; // [esp+0h] [ebp-14h]
  Squares *v6; // [esp+4h] [ebp-10h] BYREF
  Squares *v7; // [esp+8h] [ebp-Ch] BYREF
  int EntityIdXY; // [esp+Ch] [ebp-8h]
  CTradingBuildingRole *v9; // [esp+10h] [ebp-4h]

  v9 = this;
  WorkingAreaPackedXY = (Y16X16 *)CBuilding::GetWorkingAreaPackedXY(a2);
  Y16X16::UnpackXYFast((int)WorkingAreaPackedXY, (int *)&v6, (int *)&v7);
  if ( CWarMap::NumberOfEntitiesXY(1, v6, v7) != 0 )
  {
    EntityIdXY = CWarMap::FirstEntityIdXY(1, v6, v7);
    if ( EntityIdXY == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 2999, "iEntityID != 0") == 1 )
    {
      __debugbreak();
    }
    VehiclePtr = (unsigned __int16 *)CVehicleMgr::GetVehiclePtr(EntityIdXY);
    if ( VehiclePtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3001, "pVehicle != NULL") == 1 )
    {
      __debugbreak();
    }
    v3 = IEntity::Type((IEntity *)VehiclePtr);
    if ( CTradingBuildingRole::IsShip(v9, v3) )
    {
      return EntityIdXY;
    }
  }
  if ( *((_DWORD *)v9 + 160) != 0 )
  {
    return *((_DWORD *)v9 + 160);
  }
  if ( *((_DWORD *)v9 + 158) != 0 )
  {
    return *((_DWORD *)v9 + 158);
  }
  return 0;
}


// address=[0x15251e0]
// Decompiled from char __thiscall CTradingBuildingRole::IsShipInHarbour(CTradingBuildingRole *this, struct CBuilding *a2)
bool  CTradingBuildingRole::IsShipInHarbour(class CBuilding * a2) {
  
  Y16X16 *WorkingAreaPackedXY; // eax
  int v4; // eax
  unsigned __int16 *VehiclePtr; // [esp+0h] [ebp-14h]
  int EntityIdXY; // [esp+4h] [ebp-10h]
  Squares *v7; // [esp+8h] [ebp-Ch] BYREF
  Squares *v8; // [esp+Ch] [ebp-8h] BYREF
  CTradingBuildingRole *v9; // [esp+10h] [ebp-4h]

  v9 = this;
  WorkingAreaPackedXY = (Y16X16 *)CBuilding::GetWorkingAreaPackedXY(a2);
  Y16X16::UnpackXYFast((int)WorkingAreaPackedXY, (int *)&v7, (int *)&v8);
  if ( *((_DWORD *)v9 + 160) != 0 || *((_DWORD *)v9 + 158) != 0 )
  {
    return 1;
  }
  if ( CWarMap::NumberOfEntitiesXY(1, v7, v8) != 0 )
  {
    EntityIdXY = CWarMap::FirstEntityIdXY(1, v7, v8);
    if ( EntityIdXY == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3039, "iEntityID != 0") == 1 )
    {
      __debugbreak();
    }
    VehiclePtr = (unsigned __int16 *)CVehicleMgr::GetVehiclePtr(EntityIdXY);
    if ( VehiclePtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3041, "pVehicle != NULL") == 1 )
    {
      __debugbreak();
    }
    v4 = IEntity::Type((IEntity *)VehiclePtr);
    if ( CTradingBuildingRole::IsShip(v9, v4) )
    {
      return 1;
    }
  }
  return 0;
}


// address=[0x15252d0]
// Decompiled from bool __thiscall CTradingBuildingRole::IsTradeShipInHarbour(CTradingBuildingRole *this, struct CBuilding *a2)
bool  CTradingBuildingRole::IsTradeShipInHarbour(class CBuilding * a2) {
  
  Y16X16 *WorkingAreaPackedXY; // eax
  unsigned __int16 *VehiclePtr; // [esp+4h] [ebp-10h]
  int EntityIdXY; // [esp+8h] [ebp-Ch]
  Squares *v6; // [esp+Ch] [ebp-8h] BYREF
  Squares *v7; // [esp+10h] [ebp-4h] BYREF

  WorkingAreaPackedXY = (Y16X16 *)CBuilding::GetWorkingAreaPackedXY(a2);
  Y16X16::UnpackXYFast((int)WorkingAreaPackedXY, (int *)&v6, (int *)&v7);
  if ( CWarMap::NumberOfEntitiesXY(1, v6, v7) == 0 )
  {
    return 0;
  }
  EntityIdXY = CWarMap::FirstEntityIdXY(1, v6, v7);
  if ( EntityIdXY == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3067, "iEntityID != 0") == 1 )
  {
    __debugbreak();
  }
  VehiclePtr = (unsigned __int16 *)CVehicleMgr::GetVehiclePtr(EntityIdXY);
  if ( VehiclePtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3069, "pVehicle != NULL") == 1 )
  {
    __debugbreak();
  }
  return IEntity::Type((IEntity *)VehiclePtr) == 3;
}


// address=[0x15253a0]
// Decompiled from bool __thiscall CTradingBuildingRole::IsShip(CTradingBuildingRole *this, int a2)
bool  CTradingBuildingRole::IsShip(int a2) {
  
  return a2 == 1 || a2 == 2 || a2 == 3;
}


// address=[0x15253d0]
// Decompiled from void __thiscall CTradingBuildingRole::StartLoadingShip(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::StartLoadingShip(int a2) {
  
  CTransportShip *VehiclePtr; // [esp+0h] [ebp-8h]

  *((_BYTE *)this + 636) = 1;
  *((_DWORD *)this + 158) = a2;
  VehiclePtr = (CTransportShip *)CVehicleMgr::GetVehiclePtr(a2);
  CTransportShip::SetJobType(VehiclePtr, 4);
}


// address=[0x1525410]
// Decompiled from void __thiscall CTradingBuildingRole::StartUnloadingShip(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::StartUnloadingShip(int a2) {
  
  CTransportShip *VehiclePtr; // [esp+0h] [ebp-8h]

  *((_BYTE *)this + 637) = 1;
  *((_DWORD *)this + 160) = a2;
  VehiclePtr = (CTransportShip *)CVehicleMgr::GetVehiclePtr(a2);
  CTransportShip::SetJobType(VehiclePtr, 3);
}


// address=[0x1525450]
// Decompiled from struct CVehicle *__thiscall CTradingBuildingRole::LoadShip(struct CVehicle *this)
void  CTradingBuildingRole::LoadShip(void) {
  
  struct CVehicle *result; // eax
  unsigned __int16 *v2; // eax
  int v3; // esi
  int v4; // eax
  unsigned __int8 *BuildingPtr; // eax
  unsigned __int8 *v6; // [esp+8h] [ebp-58h]
  CTradingBuildingRole *v7; // [esp+10h] [ebp-50h]
  int TotalExportedGoodAmount; // [esp+14h] [ebp-4Ch]
  int v9; // [esp+18h] [ebp-48h]
  bool v10; // [esp+1Ch] [ebp-44h]
  int v11; // [esp+30h] [ebp-30h]
  int v12; // [esp+34h] [ebp-2Ch]
  int v13; // [esp+38h] [ebp-28h]
  signed int i; // [esp+3Ch] [ebp-24h]
  int v15; // [esp+40h] [ebp-20h]
  CTradePileRole *v16; // [esp+44h] [ebp-1Ch]
  int ReserveAmount; // [esp+48h] [ebp-18h]
  CPile *PilePtr; // [esp+4Ch] [ebp-14h]
  CMFCBaseTabCtrl *v19; // [esp+50h] [ebp-10h]
  unsigned int v20; // [esp+54h] [ebp-Ch]
  bool v22; // [esp+5Fh] [ebp-1h]
  char v23; // [esp+5Fh] [ebp-1h]
  char v24; // [esp+5Fh] [ebp-1h]

  result = this;
  if ( *((_BYTE *)this + 636) != 0 )
  {
    if ( (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, HIWORD(this->m_iUniqueId)) == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3140, "pBuilding") == 1 )
    {
      __debugbreak();
    }
    result = (struct CVehicle *)CVehicleMgr::GetVehiclePtr(*((_DWORD *)this + 158));
    v19 = (CMFCBaseTabCtrl *)result;
    if ( result == 0 )
    {
      result = (struct CVehicle *)BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3144, "pShip");
      if ( result == (struct CVehicle *)1 )
      {
        __debugbreak();
      }
    }
    if ( v19 != 0 )
    {
      for ( i = 0;
            ;
            ++i )
      {
        result = this;
        if ( i >= *(char *)(*((_DWORD *)this + 94) + 57) )
        {
          break;
        }
        v2 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
        PilePtr = CPileMgr::GetPilePtr(*v2);
        v16 = (CTradePileRole *)CPile::Role(PilePtr);
        v20 = ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr);
        v3 = PilePtr->Amount(PilePtr);
        v12 = v3 - CPile::AmountLeaving(PilePtr);
        if ( CTransportShip::IsNeutralTrader(v19) )
        {
          v13 = *((unsigned __int16 *)this + 191);
          v15 = *((char *)this + v20 + 556);
        }
        else
        {
          v13 = *((unsigned __int16 *)this + 190);
          v15 = *((char *)this + v20 + 427);
        }
        if ( v15 > 0 && v12 > 0 && CTradingBuildingRole::GetTargetBuildingAvailableSpace((CTradingBuildingRole *)this, v13, v20) != 0 )
        {
          v22 = 0;
          if ( CTransportShip::IsNeutralTrader(v19) )
          {
            if ( CTransportShip::GetTradingState(v19) == 1 )
            {
              v22 = CTradePileRole::GetTradeRoleType(v16) == 3;
            }
            if ( CTransportShip::GetTradingState(v19) == 2 )
            {
              v22 = CTradePileRole::GetTradeRoleType(v16) == 4;
            }
            v4 = ((int (__stdcall *)())IEntity::ID)();
            v24 = CInternationalTrader::CheckGoodMatch(*((_DWORD *)this + 171), v4, v13, v20) & v22;
            v10 = CTradingBuildingRole::GetExportGoodAmount((CTradingBuildingRole *)this, v20) == 16 || CTradingBuildingRole::GetExportResGoodAmount((CTradingBuildingRole *)this, v20) == 16 || (unsigned __int8)CTransportShip::HasLoadGood(v19, v20) != 0;
            v23 = v10 & v24;
          }
          else
          {
            v23 = CTradePileRole::GetTradeRoleType(v16) == 1;
          }
          if ( v23 != 0 && CTransportShip::IsSpaceAvailable(v19, v20) && !CTransportShip::IsFull(v19) )
          {
            if ( v12 >= v15 )
            {
              v9 = v15;
            }
            else
            {
              v9 = v12;
            }
            ReserveAmount = v9;
            if ( CTradePileRole::GetTradeRoleType(v16) == 4 )
            {
              ReserveAmount = CTradePileRole::GetReserveAmount(v16);
            }
            if ( CTradePileRole::GetTradeRoleType(v16) == 3 )
            {
              BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 191));
              TotalExportedGoodAmount = CTradingBuildingRole::GetTotalExportedGoodAmount((CTradingBuildingRole *)this, (struct CBuilding *)BuildingPtr);
              if ( TotalExportedGoodAmount < ReserveAmount )
              {
                ReserveAmount = TotalExportedGoodAmount;
              }
            }
            v11 = ReserveAmount - CTransportShip::AddGood((IEntity *)v19, v20, ReserveAmount);
            CPile::DecreaseUnforeseen(PilePtr, v11);
            if ( PilePtr->Amount(PilePtr) != 0 && !CTransportShip::IsNeutralTrader(v19) )
            {
              CTradePileRole::SetTradeRoleType(v16, 3);
            }
            if ( !CTransportShip::IsNeutralTrader(v19) && *((_BYTE *)this + v20 + 427) != 100 )
            {
              *((_BYTE *)this + v20 + 427) -= v11;
            }
            if ( CTransportShip::IsNeutralTrader(v19) )
            {
              *((_BYTE *)this + v20 + 556) -= v11;
              if ( CTransportShip::GetTradingState(v19) == 1 )
              {
                v6 = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 191));
                v7 = (CTradingBuildingRole *)CBuilding::Role((CBuilding *)v6);
                CTradingBuildingRole::ReserveExportPile(v7, HIWORD(this->m_iUniqueId), v20, ReserveAmount);
                CTradingBuildingRole::ReserveImportPile(v7, ReserveAmount);
                CTradingBuildingRole::ReserveImportPile((CTradingBuildingRole *)this, ReserveAmount);
              }
            }
          }
        }
      }
    }
  }
  return result;
}


// address=[0x15258e0]
// Decompiled from unsigned __int8 *__thiscall CTradingBuildingRole::SendShip(CTradingBuildingRole *this)
void  CTradingBuildingRole::SendShip(void) {
  
  unsigned __int8 *result; // eax
  bool IsNeutralTrader; // al
  bool v3; // al
  unsigned int BuildingID; // eax
  CTradingBuildingRole *v5; // [esp+0h] [ebp-14h]
  int TargetBuildingID; // [esp+4h] [ebp-10h]
  unsigned __int8 *v7; // [esp+8h] [ebp-Ch]
  CTransportShip *VehiclePtr; // [esp+Ch] [ebp-8h]

  result = (unsigned __int8 *)this;
  if ( *((_DWORD *)this + 158) != 0 )
  {
    VehiclePtr = (CTransportShip *)CVehicleMgr::GetVehiclePtr(*((_DWORD *)this + 158));
    IsNeutralTrader = CTransportShip::IsNeutralTrader(VehiclePtr);
    TargetBuildingID = CTradingBuildingRole::GetTargetBuildingID(this, IsNeutralTrader);
    result = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, TargetBuildingID);
    v7 = result;
    if ( result == 0 )
    {
      result = (unsigned __int8 *)BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3270, "pBuilding!=NULL");
      if ( result == (unsigned __int8 *)1 )
      {
        __debugbreak();
      }
    }
    if ( v7 != 0 )
    {
      v5 = (CTradingBuildingRole *)CBuilding::Role((CBuilding *)v7);
      v3 = CTransportShip::IsNeutralTrader(VehiclePtr);
      CTradingBuildingRole::RegisterIncomingTrader(v5, *((_DWORD *)this + 158), 1, v3);
      CTransportShip::SetJobType(VehiclePtr, 1);
      BuildingID = CTradingBuildingRole::GetBuildingID(this);
      CTransportShip::SetHomeID(VehiclePtr, BuildingID);
      CTransportShip::MoveToTarget(VehiclePtr);
      result = (unsigned __int8 *)this;
      *((_DWORD *)this + 158) = 0;
      *((_BYTE *)this + 636) = 0;
    }
  }
  return result;
}


// address=[0x15259d0]
// Decompiled from void __thiscall CTradingBuildingRole::UnloadShip(CTradingBuildingRole *this)
void  CTradingBuildingRole::UnloadShip(void) {
  
  int v1; // esi
  bool IsNeutralTrader; // al
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // [esp-Ch] [ebp-48h]
  int v10; // [esp+4h] [ebp-38h]
  unsigned __int8 *BuildingPtr; // [esp+8h] [ebp-34h]
  unsigned int v12; // [esp+Ch] [ebp-30h]
  bool v13; // [esp+10h] [ebp-2Ch]
  int GoodAmount; // [esp+18h] [ebp-24h]
  unsigned __int8 *v15; // [esp+1Ch] [ebp-20h]
  unsigned __int8 *v16; // [esp+1Ch] [ebp-20h]
  int v17; // [esp+20h] [ebp-1Ch]
  int v18; // [esp+24h] [ebp-18h]
  int v19; // [esp+24h] [ebp-18h]
  int i; // [esp+28h] [ebp-14h]
  signed int j; // [esp+2Ch] [ebp-10h]
  unsigned __int8 *VehiclePtr; // [esp+30h] [ebp-Ch]

  v18 = 0;
  if ( *((_DWORD *)this + 160) != 0 )
  {
    BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
    VehiclePtr = (unsigned __int8 *)CVehicleMgr::GetVehiclePtr(*((_DWORD *)this + 160));
    v13 = false;
    if ( CTransportShip::IsNeutralTrader((CTransportShip *)VehiclePtr) )
    {
      v1 = IEntity::OwnerId((IEntity *)VehiclePtr);
      if ( v1 != IEntity::OwnerId((IEntity *)BuildingPtr) )
      {
        v13 = true;
      }
    }
    for ( i = 0;
          i < 43;
          ++i )
    {
      GoodAmount = CTransportShip::GetGoodAmount((CTransportShip *)VehiclePtr, i);
      if ( GoodAmount != 0 )
      {
        IsNeutralTrader = CTransportShip::IsNeutralTrader((CTransportShip *)VehiclePtr);
        v10 = CTradingBuildingRole::AddGood(this, i, GoodAmount, IsNeutralTrader);
        CTransportShip::RemoveGood((IEntity *)VehiclePtr, i, GoodAmount - v10);
      }
      v18 += CTransportShip::GetGoodAmount((CTransportShip *)VehiclePtr, i);
    }
    if ( v18 != 0 )
    {
      v19 = 0;
      v15 = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
      for ( j = 0;
            j < 43;
            ++j )
      {
        v17 = CTransportShip::GetGoodAmount((CTransportShip *)VehiclePtr, j);
        if ( v17 != 0 && CTradingBuildingRole::GetGoodSpaceAmount(this, j) == 0 )
        {
          while ( v17 != 0 )
          {
            if ( v17 > 8 )
            {
              v12 = 8;
            }
            else
            {
              v12 = v17;
            }
            v5 = CBuilding::EnsignPackedXY(v15);
            v9 = Y16X16::UnpackYFast(v5);
            v6 = CBuilding::EnsignPackedXY(v15);
            v7 = Y16X16::UnpackXFast(v6);
            CPileMgr::SearchSpaceForGoods(&g_cPileMgr, v7, v9, j, v12);
            CTransportShip::RemoveGood((IEntity *)VehiclePtr, j, v12);
            v17 -= v12;
          }
        }
        v19 += CTransportShip::GetGoodAmount((CTransportShip *)VehiclePtr, j);
      }
      if ( v19 == 0 )
      {
        CTransportShip::SetJobType((CTransportShip *)VehiclePtr, 0);
        *((_DWORD *)this + 160) = 0;
        *((_BYTE *)this + 637) = 0;
        v16 = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
        if ( v13 )
        {
          CTradingBuildingRole::TransportHandling(this, (struct CBuilding *)v16);
        }
        else
        {
          v8 = ((int (__stdcall *)())IEntity::ID)();
          CTradingBuildingRole::UnregisterIncomingTrader(this, v8, 1);
          CTransportShip::TryToGoHome((Y16X16 **)VehiclePtr);
        }
      }
    }
    else
    {
      *((_DWORD *)this + 160) = 0;
      *((_BYTE *)this + 637) = 0;
      if ( v13 )
      {
        v3 = ((int (__stdcall *)())IEntity::ID)();
        CTradingBuildingRole::UnregisterIncomingTrader(this, v3, 1);
        CTransportShip::SetJobType((CTransportShip *)VehiclePtr, 0);
        v4 = ((int (__stdcall *)())IEntity::ID)();
        CTradingBuildingRole::StartLoadIntTraderShip(this, v4);
      }
      else
      {
        CTradingBuildingRole::CancelIncomingChargeTraders(this);
        CTransportShip::SetJobType((CTransportShip *)VehiclePtr, 0);
        --*((_DWORD *)this + 172);
        CTransportShip::TryToGoHome((Y16X16 **)VehiclePtr);
      }
    }
  }
}


// address=[0x1525cc0]
// Decompiled from void __thiscall CTradingBuildingRole::ShipArrived(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::ShipArrived(int a2) {
  
  CMFCBaseTabCtrl *VehiclePtr; // [esp+4h] [ebp-8h]

  if ( (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3)) == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3396, "pBuilding") == 1 )
  {
    __debugbreak();
  }
  VehiclePtr = (CMFCBaseTabCtrl *)CVehicleMgr::GetVehiclePtr(a2);
  CTradingBuildingRole::UnregisterIncomingTrader(this, a2, 1);
  if ( CTransportShip::GetJobType(VehiclePtr) == 2 )
  {
    if ( CTransportShip::IsNeutralTrader(VehiclePtr) && CTransportShip::GetTradingState(VehiclePtr) == 2 )
    {
      --*((_DWORD *)this + 172);
    }
    CTradingBuildingRole::StartLoadingShip(this, a2);
  }
  else if ( CTransportShip::GetJobType(VehiclePtr) == 1 )
  {
    CTradingBuildingRole::StartUnloadingShip(this, a2);
  }
}


// address=[0x1525d90]
// Decompiled from void __thiscall CTradingBuildingRole::ShipArrivedAtTarget(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::ShipArrivedAtTarget(int a2) {
  
  ;
}


// address=[0x1525da0]
// Decompiled from bool __thiscall CTradingBuildingRole::ShipArriveCancel(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::ShipArriveCancel(int a2) {
  
  return CTradingBuildingRole::UnregisterIncomingTrader(this, a2, 1);
}


// address=[0x1525dc0]
// Decompiled from bool __thiscall CTradingBuildingRole::IsShipRequested(CTradingBuildingRole *this)
bool  CTradingBuildingRole::IsShipRequested(void) {
  
  return *((_DWORD *)this + 172) > 0;
}


// address=[0x1525df0]
// Decompiled from char __thiscall CTradingBuildingRole::RequestDonkey(CTradingBuildingRole *this, struct CBuilding *a2, struct CBuilding *a3, bool a4)
bool  CTradingBuildingRole::RequestDonkey(class CBuilding * a2, class CBuilding * a3, bool a4) {
  
  int v4; // eax
  int v5; // eax
  int v6; // eax
  Y16X16 *v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v13; // [esp-8h] [ebp-60h]
  int v14; // [esp-4h] [ebp-5Ch]
  CEntityEvent v15; // [esp+4h] [ebp-54h] BYREF
  int v16; // [esp+1Ch] [ebp-3Ch]
  _BYTE v17[4]; // [esp+20h] [ebp-38h] BYREF
  int v18[2]; // [esp+24h] [ebp-34h] BYREF
  CEntityEvent *v19; // [esp+2Ch] [ebp-2Ch]
  unsigned __int8 *BuildingPtr; // [esp+30h] [ebp-28h]
  int DonkeyIDAtBuilding; // [esp+34h] [ebp-24h]
  struct IMovingEntity *v22; // [esp+38h] [ebp-20h]
  struct IMovingEntity *NearestEntity; // [esp+3Ch] [ebp-1Ch]
  CTradingBuildingRole *v24; // [esp+40h] [ebp-18h]
  CMFCToolBarImages *v25; // [esp+44h] [ebp-14h]
  int v27; // [esp+54h] [ebp-4h]

  v24 = this;
  if ( CTradingBuildingRole::GetNrRegisteredIncomingTraders(this, 2, a4) != 0 )
  {
    return 1;
  }
  NearestEntity = 0;
  if ( CTradingBuildingRole::IsDonkeyAtBuilding(v24, a2) )
  {
    DonkeyIDAtBuilding = CTradingBuildingRole::GetDonkeyIDAtBuilding(v24, a2);
    if ( DonkeyIDAtBuilding != 0 )
    {
      NearestEntity = (struct IMovingEntity *)CMapObjectMgr::EntityPtr(DonkeyIDAtBuilding);
    }
  }
  else
  {
    v4 = CBuilding::EnsignPackedXY(a2);
    v14 = Y16X16::UnpackYFast(v4);
    v5 = CBuilding::EnsignPackedXY(a2);
    v13 = Y16X16::UnpackXFast(v5);
    v6 = IEntity::OwnerId(a2);
    NearestEntity = (struct IMovingEntity *)CTransportMgr::GetNearestEntity(1, 60, v6, v13, v14);
  }
  if ( NearestEntity == 0 )
  {
    return 0;
  }
  v22 = NearestEntity;
  v25 = (CMFCToolBarImages *)CSettler::Role((CSettler *)NearestEntity);
  if ( CDonkeyRole::GetJobType((CDonkeyRole *)v25) == 0 )
  {
    v7 = (Y16X16 *)CBuilding::EnsignPackedXY(a2);
    Y16X16::UnpackXYFast((int)v7, (int *)v17, v18);
    v8 = ((int (__stdcall *)())IEntity::ID)();
    CDonkeyRole::SetDepartBuildingID((CDonkeyRole *)v25, v8);
    v9 = ((int (__stdcall *)())IEntity::ID)();
    CDonkeyRole::SetTargetBuildingID((CDonkeyRole *)v25, v9);
    CDonkeyRole::SetJobType((CDonkeyRole *)v25, 2);
    CDonkeyRole::MemHomePosition((CDonkeyRole *)v25);
    v10 = ((int (__stdcall *)())IEntity::ID)();
    CTradingBuildingRole::RegisterIncomingTrader(v24, v10, 2, a4);
    v11 = ((int (__stdcall *)())IEntity::ID)();
    v19 = CEntityEvent::CEntityEvent(&v15, 0xAu, 0, 0, 0, v11);
    v18[1] = (int)v19;
    v27 = 0;
    v22->j_?SetEvent@IAnimatedEntity@@UAEXABVCEntityEvent@@@Z((unsigned __int16 *)v22, (int)v19);
    v27 = -1;
    CEntityEvent::~CEntityEvent(&v15);
    CDonkeyRole::SetNeutralTraderStatus((CDonkeyRole *)v25, a4);
    if ( *((_WORD *)v24 + 191) != 0 )
    {
      BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)v24 + 191));
      if ( BuildingPtr != 0 )
      {
        v16 = (int)CBuilding::Role((CBuilding *)BuildingPtr);
      }
    }
  }
  return 1;
}


// address=[0x1525ff0]
// Decompiled from bool __thiscall CTradingBuildingRole::IsDonkeyAtBuilding(CTradingBuildingRole *this, struct CBuilding *a2)
bool  CTradingBuildingRole::IsDonkeyAtBuilding(class CBuilding * a2) {
  
  Y16X16 *v2; // eax
  unsigned __int8 *v4; // [esp+4h] [ebp-14h]
  unsigned __int8 *SettlerPtr; // [esp+8h] [ebp-10h]
  int v6; // [esp+Ch] [ebp-Ch] BYREF
  int v7; // [esp+10h] [ebp-8h] BYREF
  int v8; // [esp+14h] [ebp-4h]

  v2 = (Y16X16 *)CBuilding::EnsignPackedXY(a2);
  Y16X16::UnpackXYFast((int)v2, &v6, &v7);
  if ( CWorldManager::MapObjectId(v6, v7) == 0 )
  {
    return 0;
  }
  v8 = CWorldManager::MapObjectId(v6, v7);
  if ( v8 == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3546, "iEntityID != 0") == 1 )
  {
    __debugbreak();
  }
  v4 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(v8);
  if ( IEntity::ObjType((IEntity *)v4) != SETTLER_OBJ )
  {
    return 0;
  }
  SettlerPtr = ((unsigned __int8 *(__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(v8);
  if ( SettlerPtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3551, "pSettler != NULL") == 1 )
  {
    __debugbreak();
  }
  return IEntity::Type((IEntity *)SettlerPtr) == 60;
}


// address=[0x15260d0]
// Decompiled from int __thiscall CTradingBuildingRole::GetDonkeyIDAtBuilding(CTradingBuildingRole *this, struct CBuilding *a2)
int  CTradingBuildingRole::GetDonkeyIDAtBuilding(class CBuilding * a2) {
  
  Y16X16 *v2; // eax
  unsigned __int8 *v4; // [esp+4h] [ebp-14h]
  unsigned __int8 *SettlerPtr; // [esp+8h] [ebp-10h]
  int v6; // [esp+Ch] [ebp-Ch] BYREF
  int v7; // [esp+10h] [ebp-8h] BYREF
  int v8; // [esp+14h] [ebp-4h]

  v2 = (Y16X16 *)CBuilding::EnsignPackedXY(a2);
  Y16X16::UnpackXYFast((int)v2, &v6, &v7);
  if ( CWorldManager::MapObjectId(v6, v7) == 0 )
  {
    return 0;
  }
  v8 = CWorldManager::MapObjectId(v6, v7);
  if ( v8 == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3581, "iEntityID != 0") == 1 )
  {
    __debugbreak();
  }
  v4 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(v8);
  if ( IEntity::ObjType((IEntity *)v4) != SETTLER_OBJ )
  {
    return 0;
  }
  SettlerPtr = ((unsigned __int8 *(__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(v8);
  if ( SettlerPtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3586, "pSettler != NULL") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::Type((IEntity *)SettlerPtr) == 60 )
  {
    return v8;
  }
  else
  {
    return 0;
  }
}


// address=[0x15261b0]
// Decompiled from void __thiscall CTradingBuildingRole::StartLoadingDonkey(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::StartLoadingDonkey(int a2) {
  
  CDonkeyRole *v2; // [esp+0h] [ebp-Ch]
  unsigned __int8 *SettlerPtr; // [esp+4h] [ebp-8h]

  *((_BYTE *)this + 648) = 1;
  *((_DWORD *)this + 161) = a2;
  SettlerPtr = ((unsigned __int8 *(__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(a2);
  if ( IEntity::Type((IEntity *)SettlerPtr) != 60 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3611, "pSettler->Type() == SETTLER_DONKEY") == 1 )
  {
    __debugbreak();
  }
  v2 = (CDonkeyRole *)CSettler::Role((CSettler *)SettlerPtr);
  CDonkeyRole::SetJobType(v2, 4);
}


// address=[0x1526230]
// Decompiled from void __thiscall CTradingBuildingRole::StartUnloadingDonkey(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::StartUnloadingDonkey(int a2) {
  
  CDonkeyRole *v2; // [esp+0h] [ebp-Ch]
  unsigned __int8 *SettlerPtr; // [esp+4h] [ebp-8h]

  *((_BYTE *)this + 649) = 1;
  *((_DWORD *)this + 163) = a2;
  SettlerPtr = ((unsigned __int8 *(__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(a2);
  if ( IEntity::Type((IEntity *)SettlerPtr) != 60 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3628, "pSettler->Type() == SETTLER_DONKEY") == 1 )
  {
    __debugbreak();
  }
  v2 = (CDonkeyRole *)CSettler::Role((CSettler *)SettlerPtr);
  CDonkeyRole::SetJobType(v2, 3);
}


// address=[0x15262b0]
// Decompiled from CTradingBuildingRole *__thiscall CTradingBuildingRole::LoadDonkey(CTradingBuildingRole *this)
void  CTradingBuildingRole::LoadDonkey(void) {
  
  CTradingBuildingRole *result; // eax
  unsigned __int16 *v2; // eax
  int v3; // esi
  int v4; // eax
  unsigned __int8 *BuildingPtr; // eax
  unsigned __int8 *v6; // [esp+8h] [ebp-5Ch]
  CTradingBuildingRole *v7; // [esp+10h] [ebp-54h]
  int TotalExportedGoodAmount; // [esp+14h] [ebp-50h]
  int v9; // [esp+18h] [ebp-4Ch]
  bool v10; // [esp+1Ch] [ebp-48h]
  unsigned __int8 *SettlerPtr; // [esp+30h] [ebp-34h]
  int v12; // [esp+34h] [ebp-30h]
  int v13; // [esp+38h] [ebp-2Ch]
  int v14; // [esp+3Ch] [ebp-28h]
  signed int i; // [esp+40h] [ebp-24h]
  int v16; // [esp+44h] [ebp-20h]
  CTradePileRole *v17; // [esp+48h] [ebp-1Ch]
  int ReserveAmount; // [esp+4Ch] [ebp-18h]
  CPile *PilePtr; // [esp+50h] [ebp-14h]
  CDonkeyRole *v20; // [esp+54h] [ebp-10h]
  int v21; // [esp+58h] [ebp-Ch]
  bool v23; // [esp+63h] [ebp-1h]
  char v24; // [esp+63h] [ebp-1h]
  char v25; // [esp+63h] [ebp-1h]

  result = this;
  if ( *((_BYTE *)this + 648) != 0 )
  {
    if ( (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3)) == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3651, "pBuilding") == 1 )
    {
      __debugbreak();
    }
    for ( i = 0;
          ;
          ++i )
    {
      result = this;
      if ( i >= *(char *)(*((_DWORD *)this + 94) + 57) )
      {
        break;
      }
      v2 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
      PilePtr = CPileMgr::GetPilePtr(*v2);
      v17 = (CTradePileRole *)CPile::Role(PilePtr);
      v21 = ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr);
      v3 = PilePtr->Amount(PilePtr);
      v13 = v3 - CPile::AmountLeaving(PilePtr);
      SettlerPtr = ((unsigned __int8 *(__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(*((_DWORD *)this + 161));
      if ( IEntity::Type((IEntity *)SettlerPtr) != 60 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3664, "pSettler->Type() == SETTLER_DONKEY") == 1 )
      {
        __debugbreak();
      }
      v20 = (CDonkeyRole *)CSettler::Role((CSettler *)SettlerPtr);
      if ( CDonkeyRole::IsNeutralTrader(v20) )
      {
        v14 = *((unsigned __int16 *)this + 191);
        v16 = *((char *)this + v21 + 556);
      }
      else
      {
        v14 = *((unsigned __int16 *)this + 190);
        v16 = *((char *)this + v21 + 427);
      }
      if ( v16 > 0 && v13 > 0 && CTradingBuildingRole::GetTargetBuildingAvailableSpace(this, v14, v21) != 0 )
      {
        v23 = 0;
        if ( CDonkeyRole::IsNeutralTrader(v20) )
        {
          if ( CDonkeyRole::GetTradingState(v20) == 1 )
          {
            v23 = CTradePileRole::GetTradeRoleType(v17) == 3;
          }
          if ( CDonkeyRole::GetTradingState(v20) == 2 )
          {
            v23 = CTradePileRole::GetTradeRoleType(v17) == 4;
          }
          v4 = ((int (__stdcall *)())IEntity::ID)();
          v25 = CInternationalTrader::CheckGoodMatch(*((_DWORD *)this + 171), v4, v14, v21) & v23;
          v10 = CTradingBuildingRole::GetExportGoodAmount(this, v21) == 16 || CTradingBuildingRole::GetExportResGoodAmount(this, v21) == 16 || CDonkeyRole::HasLoadGood(v20, v21) != 0;
          v24 = v10 & v25;
        }
        else
        {
          v24 = CTradePileRole::GetTradeRoleType(v17) == 1;
        }
        if ( v24 != 0 && CDonkeyRole::IsSpaceAvailable(v20, v21) != 0 )
        {
          if ( v13 >= v16 )
          {
            v9 = v16;
          }
          else
          {
            v9 = v13;
          }
          ReserveAmount = v9;
          if ( CTradePileRole::GetTradeRoleType(v17) == 4 )
          {
            ReserveAmount = CTradePileRole::GetReserveAmount(v17);
          }
          if ( CTradePileRole::GetTradeRoleType(v17) == 3 )
          {
            BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 191));
            TotalExportedGoodAmount = CTradingBuildingRole::GetTotalExportedGoodAmount(this, (struct CBuilding *)BuildingPtr);
            if ( TotalExportedGoodAmount < ReserveAmount )
            {
              ReserveAmount = TotalExportedGoodAmount;
            }
          }
          v12 = ReserveAmount - CDonkeyRole::AddGood(v20, v21, ReserveAmount);
          CPile::DecreaseUnforeseen(PilePtr, v12);
          if ( !CDonkeyRole::IsNeutralTrader(v20) && *((_BYTE *)this + v21 + 427) != 100 )
          {
            *((_BYTE *)this + v21 + 427) -= v12;
          }
          if ( CDonkeyRole::IsNeutralTrader(v20) )
          {
            *((_BYTE *)this + v21 + 556) -= v12;
            if ( CDonkeyRole::GetTradingState(v20) == 1 )
            {
              v6 = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 191));
              v7 = (CTradingBuildingRole *)CBuilding::Role((CBuilding *)v6);
              CTradingBuildingRole::ReserveExportPile(v7, *((unsigned __int16 *)this + 3), v21, ReserveAmount);
              CTradingBuildingRole::ReserveImportPile(v7, ReserveAmount);
              CTradingBuildingRole::ReserveImportPile(this, ReserveAmount);
            }
            if ( CTradePileRole::GetTradeRoleType(v17) == 4 && PilePtr->Amount(PilePtr) > 0 )
            {
              CTradePileRole::SetTradeRoleType(v17, 3);
            }
          }
        }
      }
    }
  }
  return result;
}


// address=[0x1526730]
// Decompiled from CTradingBuildingRole *__thiscall CTradingBuildingRole::SendDonkey(CTradingBuildingRole *this)
void  CTradingBuildingRole::SendDonkey(void) {
  
  CTradingBuildingRole *result; // eax
  char IsNeutralTrader; // al
  int TargetBuildingID; // [esp+0h] [ebp-10h]
  unsigned __int8 *SettlerPtr; // [esp+4h] [ebp-Ch]
  CMFCToolBarImages *v5; // [esp+8h] [ebp-8h]

  result = this;
  if ( *((_DWORD *)this + 161) != 0 )
  {
    SettlerPtr = ((unsigned __int8 *(__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(*((_DWORD *)this + 161));
    if ( IEntity::Type((IEntity *)SettlerPtr) != 60 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3779, "pSettler->Type() == SETTLER_DONKEY") == 1 )
    {
      __debugbreak();
    }
    v5 = (CMFCToolBarImages *)CSettler::Role((CSettler *)SettlerPtr);
    IsNeutralTrader = CDonkeyRole::IsNeutralTrader((CDonkeyRole *)v5);
    TargetBuildingID = CTradingBuildingRole::GetTargetBuildingID(this, IsNeutralTrader);
    CDonkeyRole::SetTargetBuildingID((CDonkeyRole *)v5, TargetBuildingID);
    CDonkeyRole::SetDepartBuildingID((CDonkeyRole *)v5, *((unsigned __int16 *)this + 3));
    CDonkeyRole::SetJobType((CDonkeyRole *)v5, 1);
    CDonkeyRole::NextStep((CDonkeyRole *)v5);
    *((_DWORD *)this + 161) = 0;
    result = this;
    *((_BYTE *)this + 648) = 0;
  }
  return result;
}


// address=[0x1526800]
// Decompiled from void __thiscall CTradingBuildingRole::UnloadDonkey(CTradingBuildingRole *this)
void  CTradingBuildingRole::UnloadDonkey(void) {
  
  int v1; // esi
  char IsNeutralTrader; // al
  int v3; // eax
  int v4; // eax
  int v5; // [esp-Ch] [ebp-48h]
  int v6; // [esp+4h] [ebp-38h]
  unsigned int v7; // [esp+8h] [ebp-34h]
  bool v8; // [esp+Ch] [ebp-30h]
  int GoodAmount; // [esp+14h] [ebp-28h]
  unsigned __int8 *BuildingPtr; // [esp+18h] [ebp-24h]
  unsigned __int8 *v11; // [esp+18h] [ebp-24h]
  int v12; // [esp+1Ch] [ebp-20h]
  unsigned __int8 *SettlerPtr; // [esp+20h] [ebp-1Ch]
  int v14; // [esp+24h] [ebp-18h]
  int v15; // [esp+24h] [ebp-18h]
  int i; // [esp+28h] [ebp-14h]
  int j; // [esp+2Ch] [ebp-10h]
  CDonkeyRole *v19; // [esp+34h] [ebp-8h]

  BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
  if ( BuildingPtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3802, "pBuilding !=NULL") == 1 )
  {
    __debugbreak();
  }
  v14 = 0;
  if ( *((_DWORD *)this + 163) != 0 )
  {
    SettlerPtr = ((unsigned __int8 *(__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(*((_DWORD *)this + 163));
    if ( IEntity::Type((IEntity *)SettlerPtr) != 60 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3812, "pSettler->Type() == SETTLER_DONKEY") == 1 )
    {
      __debugbreak();
    }
    v19 = (CDonkeyRole *)CSettler::Role((CSettler *)SettlerPtr);
    v8 = false;
    if ( CDonkeyRole::IsNeutralTrader(v19) )
    {
      v1 = IEntity::OwnerId((IEntity *)BuildingPtr);
      if ( v1 != CDonkeyRole::OwnerId(v19) )
      {
        v8 = true;
      }
    }
    for ( i = 0;
          i < 43;
          ++i )
    {
      GoodAmount = CDonkeyRole::GetGoodAmount(v19, i);
      if ( GoodAmount != 0 )
      {
        IsNeutralTrader = CDonkeyRole::IsNeutralTrader(v19);
        v6 = CTradingBuildingRole::AddGood(this, i, GoodAmount, IsNeutralTrader);
        CDonkeyRole::RemoveGood(v19, i, GoodAmount - v6);
      }
      v14 += CDonkeyRole::GetGoodAmount(v19, i);
    }
    if ( v14 != 0 )
    {
      v15 = 0;
      for ( j = 0;
            j < 43;
            ++j )
      {
        v12 = CDonkeyRole::GetGoodAmount(v19, j);
        if ( v12 != 0 && CTradingBuildingRole::GetGoodSpaceAmount(this, j) == 0 )
        {
          while ( v12 != 0 )
          {
            if ( v12 > 8 )
            {
              v7 = 8;
            }
            else
            {
              v7 = v12;
            }
            v5 = IEntity::Y(SettlerPtr);
            v4 = IEntity::X(SettlerPtr);
            CPileMgr::SearchSpaceForGoods(&g_cPileMgr, v4, v5, j, v7);
            CDonkeyRole::RemoveGood(v19, j, v7);
            v12 -= v7;
          }
        }
        v15 += CDonkeyRole::GetGoodAmount(v19, j);
      }
      if ( v15 == 0 )
      {
        CDonkeyRole::SetJobType(v19, 0);
        CDonkeyRole::NextStep(v19);
        *((_DWORD *)this + 163) = 0;
        *((_BYTE *)this + 649) = 0;
        v11 = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
        if ( v8 )
        {
          CTradingBuildingRole::TransportHandling(this, (struct CBuilding *)v11);
        }
        else
        {
          CDonkeyRole::TryToGoHome(v19);
        }
      }
    }
    else
    {
      ((void (__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(*((_DWORD *)this + 163));
      *((_DWORD *)this + 163) = 0;
      *((_BYTE *)this + 649) = 0;
      if ( v8 && *((_WORD *)this + 191) != 0 )
      {
        CDonkeyRole::SetJobType(v19, 0);
        CDonkeyRole::NextStep(v19);
        v3 = ((int (__stdcall *)())IEntity::ID)();
        CTradingBuildingRole::StartLoadIntTraderDonkey(this, v3);
      }
      else
      {
        CDonkeyRole::SetJobType(v19, 0);
        CDonkeyRole::NextStep(v19);
        CDonkeyRole::TryToGoHome(v19);
      }
    }
  }
}


// address=[0x1526b20]
// Decompiled from void __thiscall CTradingBuildingRole::DonkeyArrived(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::DonkeyArrived(int a2) {
  
  CDonkeyRole *v2; // [esp+4h] [ebp-10h]
  unsigned __int8 *BuildingPtr; // [esp+8h] [ebp-Ch]
  unsigned __int8 *SettlerPtr; // [esp+Ch] [ebp-8h]

  SettlerPtr = ((unsigned __int8 *(__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(a2);
  if ( IEntity::Type((IEntity *)SettlerPtr) != 60 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3903, "pDonkey->Type() == SETTLER_DONKEY") == 1 )
  {
    __debugbreak();
  }
  v2 = (CDonkeyRole *)CSettler::Role((CSettler *)SettlerPtr);
  CTradingBuildingRole::UnregisterIncomingTrader(this, a2, 2);
  if ( CDonkeyRole::GetJobType(v2) == 2 )
  {
    BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
    if ( BuildingPtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 3913, "pBuilding") == 1 )
    {
      __debugbreak();
    }
    if ( a2 == CTradingBuildingRole::GetDonkeyIDAtBuilding(this, (struct CBuilding *)BuildingPtr) )
    {
      CTradingBuildingRole::StartLoadingDonkey(this, a2);
    }
  }
  else if ( CDonkeyRole::GetJobType(v2) == 1 )
  {
    CTradingBuildingRole::StartUnloadingDonkey(this, a2);
  }
}


// address=[0x1526c10]
// Decompiled from void __thiscall CTradingBuildingRole::DonkeyArrivedAtTarget(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::DonkeyArrivedAtTarget(int a2) {
  
  ;
}


// address=[0x1526c20]
// Decompiled from CTradingBuildingRole *__thiscall CTradingBuildingRole::DonkeyArriveCancel(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::DonkeyArriveCancel(int a2) {
  
  CTradingBuildingRole *result; // eax

  CTradingBuildingRole::UnregisterIncomingTrader(this, a2, 2);
  *((_DWORD *)this + 161) = 0;
  *((_BYTE *)this + 648) = 0;
  result = this;
  *((_DWORD *)this + 163) = 0;
  return result;
}


// address=[0x1526c60]
// Decompiled from char __thiscall CTradingBuildingRole::RequestCart(CTradingBuildingRole *this, struct CBuilding *a2, struct CBuilding *a3, bool a4)
bool  CTradingBuildingRole::RequestCart(class CBuilding * a2, class CBuilding * a3, bool a4) {
  
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v10; // eax
  int v11; // eax
  struct CWnd *v12; // eax
  int v13; // eax
  int v14; // [esp-Ch] [ebp-B8h]
  int v15; // [esp-Ch] [ebp-B8h]
  int v16; // [esp-8h] [ebp-B4h]
  int v17; // [esp-4h] [ebp-B0h]
  CEntityEvent v18; // [esp+4h] [ebp-A8h] BYREF
  CEntityEvent *v19; // [esp+1Ch] [ebp-90h]
  CEntityEvent *v20; // [esp+20h] [ebp-8Ch]
  BOOL v21; // [esp+24h] [ebp-88h]
  BOOL v22; // [esp+28h] [ebp-84h]
  int CartIDAtBuilding; // [esp+2Ch] [ebp-80h]
  CCart *NearestEntity; // [esp+30h] [ebp-7Ch]
  CTradingBuildingRole *v25; // [esp+34h] [ebp-78h]
  bool IsCartAtBuilding; // [esp+3Bh] [ebp-71h]
  CMFCPopupMenu *v27; // [esp+3Ch] [ebp-70h]
  bool v28; // [esp+43h] [ebp-69h]
  struct CWaypoints v29; // [esp+44h] [ebp-68h] BYREF
  int v30; // [esp+A8h] [ebp-4h]

  v25 = this;
  if ( CTradingBuildingRole::GetNrRegisteredIncomingTraders(this, 3, a4) != 0 || *((_DWORD *)v25 + 164) != 0 )
  {
    return 0;
  }
  IsCartAtBuilding = CTradingBuildingRole::IsCartAtBuilding(v25, a2);
  if ( IsCartAtBuilding )
  {
    CartIDAtBuilding = CTradingBuildingRole::GetCartIDAtBuilding(v25, a2);
    if ( CartIDAtBuilding != 0 )
    {
      NearestEntity = (CCart *)CMapObjectMgr::EntityPtr(CartIDAtBuilding);
    }
  }
  else
  {
    v4 = CBuilding::EnsignPackedXY(a2);
    v17 = Y16X16::UnpackYFast(v4);
    v5 = CBuilding::EnsignPackedXY(a2);
    v16 = Y16X16::UnpackXFast(v5);
    v6 = IEntity::OwnerId(a2);
    NearestEntity = (CCart *)CTransportMgr::GetNearestEntity(4, 5, v6, v16, v17);
  }
  if ( NearestEntity == 0 )
  {
    return 0;
  }
  v27 = (CMFCPopupMenu *)NearestEntity;
  if ( CCart::GetJobType(NearestEntity) != 0 )
  {
    return 0;
  }
  v14 = IEntity::PackedXY(a2);
  v7 = IEntity::PackedXY((IEntity *)v27);
  v22 = CAStarTiling::FindPath(v7, v14, &v29, 2) != 0;
  v15 = IEntity::PackedXY(a3);
  v8 = IEntity::PackedXY(a2);
  v21 = CAStarTiling::FindPath(v8, v15, &v29, 2) != 0;
  v28 = v21 || v22;
  if ( !v21 && !v22 )
  {
    return 0;
  }
  v10 = ((int (__stdcall *)())IEntity::ID)();
  CTradingBuildingRole::RegisterIncomingTrader(v25, v10, 3, a4);
  v11 = ((int (__stdcall *)())IEntity::ID)();
  CCart::SetDepartBuildingID((CCart *)v27, v11);
  v12 = (struct CWnd *)((int (__stdcall *)())IEntity::ID)();
  CCart::SetTargetBuildingID(v27, v12);
  CCart::SetJobType((CCart *)v27, 2);
  if ( IsCartAtBuilding )
  {
    CCart::SetGoToSource((CCart *)v27, 0);
    CCart::CartArrived((CCart *)v27);
    CCart::SetNeutralTraderStatus((CCart *)v27, a4);
  }
  else
  {
    CCart::MemHomePosition((CCart *)v27);
    CCart::SetGoToSource((CCart *)v27, 1);
    CCart::SetGoToTarget((CCart *)v27, 0);
    v13 = CBuilding::EnsignPackedXY(a2);
    v20 = CEntityEvent::CEntityEvent(&v18, 0x11u, 13, 0, v13, 0);
    v19 = v20;
    v30 = 0;
    (*(void (__thiscall **)(CMFCPopupMenu *, CEntityEvent *))(*(_DWORD *)v27 + 80))(v27, v20);
    v30 = -1;
    CEntityEvent::~CEntityEvent(&v18);
    CCart::SetNeutralTraderStatus((CCart *)v27, a4);
  }
  return 1;
}


// address=[0x1526f10]
// Decompiled from bool __thiscall CTradingBuildingRole::IsCartAtBuilding(CTradingBuildingRole *this, struct CBuilding *a2)
bool  CTradingBuildingRole::IsCartAtBuilding(class CBuilding * a2) {
  
  return CTradingBuildingRole::GetCartIDAtBuilding(this, a2) != 0;
}


// address=[0x1526f40]
// Decompiled from int __thiscall CTradingBuildingRole::GetCartIDAtBuilding(CTradingBuildingRole *this, struct CBuilding *a2)
int  CTradingBuildingRole::GetCartIDAtBuilding(class CBuilding * a2) {
  
  Y16X16 *v3; // eax
  unsigned __int8 *v4; // [esp+0h] [ebp-18h]
  unsigned __int16 *VehiclePtr; // [esp+4h] [ebp-14h]
  int v6; // [esp+8h] [ebp-10h] BYREF
  int v7; // [esp+Ch] [ebp-Ch] BYREF
  CTradingBuildingRole *v8; // [esp+10h] [ebp-8h]
  int v9; // [esp+14h] [ebp-4h]

  v8 = this;
  if ( *((_DWORD *)this + 164) != 0 )
  {
    return *((_DWORD *)v8 + 164);
  }
  v3 = (Y16X16 *)CBuilding::EnsignPackedXY(a2);
  Y16X16::UnpackXYFast((int)v3, &v6, &v7);
  if ( CWorldManager::MapObjectId(v6, v7) == 0 )
  {
    return 0;
  }
  v9 = CWorldManager::MapObjectId(v6, v7);
  if ( v9 == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4072, "iEntityID != 0") == 1 )
  {
    __debugbreak();
  }
  v4 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(v9);
  if ( IEntity::ObjType((IEntity *)v4) != CATAPULT_OBJ )
  {
    return 0;
  }
  VehiclePtr = (unsigned __int16 *)CVehicleMgr::GetVehiclePtr(v9);
  if ( VehiclePtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4077, "pVehicle != NULL") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::Type((IEntity *)VehiclePtr) == 5 )
  {
    return v9;
  }
  else
  {
    return 0;
  }
}


// address=[0x1527040]
// Decompiled from void __thiscall CTradingBuildingRole::StartLoadingCart(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::StartLoadingCart(int a2) {
  
  CCart *VehiclePtr; // [esp+0h] [ebp-8h]

  *((_BYTE *)this + 660) = 1;
  *((_DWORD *)this + 164) = a2;
  VehiclePtr = (CCart *)CVehicleMgr::GetVehiclePtr(a2);
  CCart::SetJobType(VehiclePtr, 4);
}


// address=[0x1527080]
// Decompiled from void __thiscall CTradingBuildingRole::StartUnloadingCart(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::StartUnloadingCart(int a2) {
  
  CCart *VehiclePtr; // [esp+0h] [ebp-8h]

  *((_BYTE *)this + 661) = 1;
  *((_DWORD *)this + 166) = a2;
  VehiclePtr = (CCart *)CVehicleMgr::GetVehiclePtr(a2);
  CCart::SetJobType(VehiclePtr, 3);
}


// address=[0x15270c0]
// Decompiled from CTradingBuildingRole *__thiscall CTradingBuildingRole::LoadCart(CTradingBuildingRole *this)
void  CTradingBuildingRole::LoadCart(void) {
  
  CTradingBuildingRole *result; // eax
  unsigned __int16 *v2; // eax
  int v3; // esi
  CTradePileRole *v4; // [esp+8h] [ebp-2Ch]
  int v5; // [esp+10h] [ebp-24h]
  CCart *VehiclePtr; // [esp+18h] [ebp-1Ch]
  int v7; // [esp+1Ch] [ebp-18h]
  int v8; // [esp+20h] [ebp-14h]
  signed int i; // [esp+24h] [ebp-10h]
  CPile *PilePtr; // [esp+28h] [ebp-Ch]
  int v11; // [esp+2Ch] [ebp-8h]

  if ( (struct CVehicle *)CVehicleMgr::GetVehiclePtr(*((_DWORD *)this + 164)) == 0 )
  {
    *((_BYTE *)this + 660) = 0;
  }
  result = this;
  if ( *((_BYTE *)this + 660) != 0 )
  {
    if ( (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3)) == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4144, "pBuilding") == 1 )
    {
      __debugbreak();
    }
    VehiclePtr = (CCart *)CVehicleMgr::GetVehiclePtr(*((_DWORD *)this + 164));
    for ( i = 0;
          ;
          ++i )
    {
      result = *((CTradingBuildingRole **)this + 94);
      if ( i >= *((char *)result + 57) )
      {
        break;
      }
      v2 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
      PilePtr = CPileMgr::GetPilePtr(*v2);
      v4 = (CTradePileRole *)CPile::Role(PilePtr);
      v11 = ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr);
      v3 = PilePtr->Amount(PilePtr);
      v8 = v3 - CPile::AmountLeaving(PilePtr);
      if ( CTradePileRole::GetTradeRoleType(v4) == 1 && *((_BYTE *)this + v11 + 470) == 2 && *((char *)this + v11 + 427) > 0 && v8 > 0 && CTradingBuildingRole::GetTargetBuildingAvailableSpace(this, *((unsigned __int16 *)this + 190), v11) != 0 && CCart::IsSpaceAvailable(VehiclePtr, v11) != 0 )
      {
        if ( v8 >= *((char *)this + v11 + 427) )
        {
          v7 = *((char *)this + v11 + 427);
        }
        else
        {
          v7 = v8;
        }
        v5 = v7 - CCart::AddGood(VehiclePtr, v11, v7);
        CPile::DecreaseUnforeseen(PilePtr, v5);
        result = (CTradingBuildingRole *)*((char *)this + v11 + 427);
        if ( result != (CTradingBuildingRole *)100 )
        {
          result = (CTradingBuildingRole *)((char *)this + v11);
          *((_BYTE *)this + v11 + 427) -= v5;
        }
        return result;
      }
    }
  }
  return result;
}


// address=[0x15272e0]
// Decompiled from CTradingBuildingRole *__thiscall CTradingBuildingRole::SendCart(CTradingBuildingRole *this)
void  CTradingBuildingRole::SendCart(void) {
  
  CTradingBuildingRole *result; // eax
  int v2; // eax
  char IsNeutralTrader; // al
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp-Ch] [ebp-90h]
  int v8; // [esp-Ch] [ebp-90h]
  CTradingBuildingRole *v9; // [esp+0h] [ebp-84h]
  unsigned int v10; // [esp+4h] [ebp-80h]
  unsigned __int8 *BuildingPtr; // [esp+10h] [ebp-74h]
  int GoodAmount; // [esp+14h] [ebp-70h]
  int i; // [esp+1Ch] [ebp-68h]
  CCart *VehiclePtr; // [esp+20h] [ebp-64h]
  _BYTE v16[88]; // [esp+28h] [ebp-5Ch] BYREF

  result = this;
  if ( *((_DWORD *)this + 164) != 0 )
  {
    VehiclePtr = (CCart *)CVehicleMgr::GetVehiclePtr(*((_DWORD *)this + 164));
    BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 190));
    v7 = CBuilding::EnsignPackedXY(BuildingPtr);
    v2 = IEntity::PackedXY(VehiclePtr);
    if ( CAStarTiling::FindPath(v2, v7, (struct CWaypoints *)v16, 2) != 0 )
    {
      v9 = (CTradingBuildingRole *)CBuilding::Role((CBuilding *)BuildingPtr);
      IsNeutralTrader = CCart::IsNeutralTrader(VehiclePtr);
      CTradingBuildingRole::RegisterIncomingTrader(v9, *((_DWORD *)this + 164), 3, IsNeutralTrader);
      CCart::SetJobType(VehiclePtr, 1);
      CCart::MoveToTarget(VehiclePtr);
      ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
    }
    else
    {
      for ( i = 0;
            i < 43;
            ++i )
      {
        GoodAmount = CCart::GetGoodAmount(VehiclePtr, i);
        if ( GoodAmount != 0 && CTradingBuildingRole::GetGoodSpaceAmount(this, i) == 0 )
        {
          while ( GoodAmount != 0 )
          {
            if ( GoodAmount > 8 )
            {
              v10 = 8;
            }
            else
            {
              v10 = GoodAmount;
            }
            v4 = CBuilding::EnsignPackedXY(BuildingPtr);
            v8 = Y16X16::UnpackYFast(v4);
            v5 = CBuilding::EnsignPackedXY(BuildingPtr);
            v6 = Y16X16::UnpackXFast(v5);
            CPileMgr::SearchSpaceForGoods(&g_cPileMgr, v6, v8, i, v10);
            CCart::RemoveGood(VehiclePtr, i, v10);
            GoodAmount -= v10;
          }
        }
      }
      CCart::TryToGoHome(VehiclePtr);
    }
    result = this;
    *((_DWORD *)this + 164) = 0;
    *((_BYTE *)this + 660) = 0;
  }
  return result;
}


// address=[0x15274c0]
// Decompiled from void __thiscall CTradingBuildingRole::UnloadCart(CTradingBuildingRole *this)
void  CTradingBuildingRole::UnloadCart(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // [esp-Ch] [ebp-38h]
  int v5; // [esp+0h] [ebp-2Ch]
  unsigned int v6; // [esp+4h] [ebp-28h]
  int GoodAmount; // [esp+Ch] [ebp-20h]
  unsigned __int8 *BuildingPtr; // [esp+10h] [ebp-1Ch]
  int v9; // [esp+14h] [ebp-18h]
  int v10; // [esp+18h] [ebp-14h]
  int v11; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  int j; // [esp+20h] [ebp-Ch]
  CCart *VehiclePtr; // [esp+28h] [ebp-4h]

  v10 = 0;
  if ( *((_DWORD *)this + 166) != 0 )
  {
    VehiclePtr = (CCart *)CVehicleMgr::GetVehiclePtr(*((_DWORD *)this + 166));
    BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
    if ( VehiclePtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4252, "pVehicle!=NULL") == 1 )
    {
      __debugbreak();
    }
    if ( VehiclePtr != 0 )
    {
      if ( BuildingPtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4253, "pBuilding!=NULL") == 1 )
      {
        __debugbreak();
      }
      if ( BuildingPtr != 0 )
      {
        CCart::ClearNeutralTraderStatus(VehiclePtr);
        for ( i = 0;
              i < 43;
              v10 += CCart::GetGoodAmount(VehiclePtr, i++) )
        {
          GoodAmount = CCart::GetGoodAmount(VehiclePtr, i);
          if ( GoodAmount != 0 )
          {
            v5 = CTradingBuildingRole::AddGood(this, i, GoodAmount, 0);
            CCart::RemoveGood(VehiclePtr, i, GoodAmount - v5);
          }
        }
        if ( v10 == 0 )
        {
          goto LABEL_27;
        }
        v11 = 0;
        for ( j = 0;
              j < 43;
              v11 += CCart::GetGoodAmount(VehiclePtr, j++) )
        {
          v9 = CCart::GetGoodAmount(VehiclePtr, j);
          if ( v9 != 0 && CTradingBuildingRole::GetGoodSpaceAmount(this, j) == 0 )
          {
            while ( v9 != 0 )
            {
              if ( v9 > 8 )
              {
                v6 = 8;
              }
              else
              {
                v6 = v9;
              }
              v1 = CBuilding::EnsignPackedXY(BuildingPtr);
              v4 = Y16X16::UnpackYFast(v1);
              v2 = CBuilding::EnsignPackedXY(BuildingPtr);
              v3 = Y16X16::UnpackXFast(v2);
              CPileMgr::SearchSpaceForGoods(&g_cPileMgr, v3, v4, j, v6);
              CCart::RemoveGood(VehiclePtr, j, v6);
              v9 -= v6;
            }
          }
        }
        if ( v11 == 0 )
        {
LABEL_27:
          CCart::SetJobType(VehiclePtr, 0);
          *((_DWORD *)this + 166) = 0;
          *((_BYTE *)this + 661) = 0;
          CCart::TryToGoHome(VehiclePtr);
        }
      }
    }
  }
}


// address=[0x1527720]
// Decompiled from void __thiscall CTradingBuildingRole::CartArrived(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::CartArrived(int a2) {
  
  CCart *VehiclePtr; // [esp+4h] [ebp-8h]

  if ( (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3)) == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4326, "pBuilding") == 1 )
  {
    __debugbreak();
  }
  VehiclePtr = (CCart *)CVehicleMgr::GetVehiclePtr(a2);
  CTradingBuildingRole::UnregisterIncomingTrader(this, a2, 3);
  if ( CCart::GetJobType(VehiclePtr) == 2 )
  {
    CTradingBuildingRole::StartLoadingCart(this, a2);
  }
  else if ( CCart::GetJobType(VehiclePtr) == 1 )
  {
    CTradingBuildingRole::StartUnloadingCart(this, a2);
  }
}


// address=[0x15277c0]
// Decompiled from void __thiscall CTradingBuildingRole::CartArrivedAtTarget(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::CartArrivedAtTarget(int a2) {
  
  ;
}


// address=[0x15277d0]
// Decompiled from bool __thiscall CTradingBuildingRole::CartArriveCancel(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::CartArriveCancel(int a2) {
  
  return CTradingBuildingRole::UnregisterIncomingTrader(this, a2, 3);
}


// address=[0x15277f0]
// Decompiled from int __thiscall CTradingBuildingRole::AddGood(CTradingBuildingRole *this, int a2, int a3, bool a4)
int  CTradingBuildingRole::AddGood(int a2, int a3, bool a4) {
  
  unsigned __int8 *v4; // eax
  int v5; // eax
  unsigned __int16 *v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // esi
  unsigned __int16 *v11; // eax
  int v12; // [esp+Ch] [ebp-50h]
  int v13; // [esp+14h] [ebp-48h]
  int v14; // [esp+18h] [ebp-44h]
  int v15; // [esp+20h] [ebp-3Ch]
  bool v16; // [esp+24h] [ebp-38h]
  int v17; // [esp+28h] [ebp-34h]
  int v18; // [esp+2Ch] [ebp-30h]
  pairNode *v19; // [esp+30h] [ebp-2Ch]
  int m; // [esp+3Ch] [ebp-20h]
  int j; // [esp+44h] [ebp-18h]
  CTradePileRole *v23; // [esp+48h] [ebp-14h]
  signed int i; // [esp+50h] [ebp-Ch]
  signed int k; // [esp+50h] [ebp-Ch]
  CPile *PilePtr; // [esp+54h] [ebp-8h]
  CPile *v28; // [esp+54h] [ebp-8h]

  v4 = (unsigned __int8 *)((unsigned __int8 *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 3));
  v5 = IEntity::OwnerId((IEntity *)v4);
  CPlayerManager::Race(v5);
  v13 = CPileMgr::ConvertGoodType(&g_cPileMgr, a2);
  for ( i = 0;
        i < *(char *)(*((_DWORD *)this + 94) + 57);
        ++i )
  {
    v6 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
    PilePtr = CPileMgr::GetPilePtr(*v6);
    if ( CPile::GetRoleType(PilePtr) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4386, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v19 = (pairNode *)CPile::Role(PilePtr);
    if ( ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr) == v13 && !a4 )
    {
      if ( CTradePileRole::GetTradeRoleType((CTradePileRole *)v19) == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4393, "rTradePileRole.GetTradeRoleType() != CTradePileRole::TRADEPILE_FREE") == 1 )
      {
        __debugbreak();
      }
      v7 = ((int (__stdcall *)())IEntity::WorldIdx)();
      CWorldManager::EcoSectorId(v7);
      v8 = 8 - PilePtr->Amount(PilePtr);
      v9 = v8 - CPile::AmountComing(PilePtr);
      v18 = v9 - CTradePileRole::GetExpectedAmount((CTradePileRole *)v19);
      v17 = a3 >= v18 ? v18 : a3;
      if ( v17 != 0 )
      {
        for ( j = 0;
              j < v17;
              ++j )
        {
          CPile::IncreaseUnforeseen(PilePtr, 1);
        }
        ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
        return a3 - v17;
      }
    }
  }
  for ( k = 0;
        ;
        ++k )
  {
    if ( k >= *(char *)(*((_DWORD *)this + 94) + 57) )
    {
      return a3;
    }
    v11 = std::vector<unsigned short>::operator[]((char *)this + 608, k);
    v28 = CPileMgr::GetPilePtr(*v11);
    if ( CPile::GetRoleType(v28) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4417, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v16 = (v23 = (CTradePileRole *)CPile::Role(v28), !a4) && CTradePileRole::GetTradeRoleType(v23) == 0 || a4 && (CTradePileRole::GetTradeRoleType(v23) == 5 || CTradePileRole::GetTradeRoleType(v23) == 1) || a4 && *((_WORD *)this + 191) == 0 && CTradePileRole::GetTradeRoleType(v23) == 0;
    v12 = 8 - v28->Amount(v28);
    v15 = a3 <= 8 ? a3 : 8;
    if ( v12 >= v15 && v16 && v28->Amount(v28) == 0 )
    {
      v14 = a3 >= 8 ? 8 : a3;
      if ( v14 != 0 )
      {
        break;
      }
    }
  }
  if ( ((int (__thiscall *)(CPile *))v28->GetGoodType)(v28) != 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4446, "pPile->GetGoodType() == 0") == 1 )
  {
    __debugbreak();
  }
  CPile::SetGoodType(v28, v13);
  CTradePileRole::SetTradeRoleType(v23, 2);
  for ( m = 0;
        m < v14;
        ++m )
  {
    CPile::IncreaseUnforeseen(v28, 1);
  }
  ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
  return a3 - v14;
}


// address=[0x1527be0]
// Decompiled from int __thiscall CTradingBuildingRole::GetNrDeliveryPilesOfGood(CTradingBuildingRole *this, int a2)
int  CTradingBuildingRole::GetNrDeliveryPilesOfGood(int a2) {
  
  unsigned __int16 *v2; // eax
  CTradePileRole *v4; // [esp+0h] [ebp-14h]
  int v6; // [esp+8h] [ebp-Ch]
  CPile *PilePtr; // [esp+Ch] [ebp-8h]
  signed int i; // [esp+10h] [ebp-4h]

  v6 = 0;
  for ( i = 0;
        i < *(char *)(*((_DWORD *)this + 94) + 57);
        ++i )
  {
    v2 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
    PilePtr = CPileMgr::GetPilePtr(*v2);
    if ( CPile::GetRoleType(PilePtr) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4483, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v4 = (CTradePileRole *)CPile::Role(PilePtr);
    if ( (CTradePileRole::GetTradeRoleType(v4) == 1 || CTradePileRole::GetTradeRoleType(v4) == 3) && ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr) == a2 )
    {
      ++v6;
    }
  }
  return v6;
}


// address=[0x1527cc0]
// Decompiled from int __thiscall CTradingBuildingRole::CalcNrExportGoods(CTradingBuildingRole *this, bool a2)
int  CTradingBuildingRole::CalcNrExportGoods(bool a2) {
  
  CTradingBuildingRole *v3; // [esp+0h] [ebp-18h]
  unsigned __int8 *BuildingPtr; // [esp+4h] [ebp-14h]
  int ExportGoodAmount; // [esp+8h] [ebp-10h]
  int v6; // [esp+Ch] [ebp-Ch]
  signed int i; // [esp+14h] [ebp-4h]

  BuildingPtr = 0;
  if ( *((_WORD *)this + 190) != 0 )
  {
    BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 190));
  }
  v6 = 0;
  for ( i = 0;
        i < 43;
        ++i )
  {
    if ( a2 )
    {
      ExportGoodAmount = CTradingBuildingRole::GetExportGoodAmount(this, i);
    }
    else
    {
      ExportGoodAmount = *((char *)this + i + 427);
    }
    if ( ExportGoodAmount > 0 )
    {
      if ( BuildingPtr != 0 )
      {
        v3 = (CTradingBuildingRole *)CBuilding::Role((CBuilding *)BuildingPtr);
        if ( CTradingBuildingRole::GetGoodSpaceAmount(v3, i) != 0 )
        {
          if ( a2 )
          {
            if ( (unsigned __int8)CTradingBuildingRole::HasGoodState(this, i, 8) != 0 )
            {
              v6 += *((char *)this + i + 427);
            }
          }
          else if ( (unsigned __int8)CTradingBuildingRole::HasGoodState(this, i, 2) != 0 )
          {
            v6 += *((char *)this + i + 427);
          }
        }
      }
      else
      {
        v6 += ExportGoodAmount;
      }
    }
  }
  return v6;
}


// address=[0x1527df0]
// Decompiled from int __thiscall CTradingBuildingRole::GetPileIDWithGoodToTransport(_DWORD *this)
int  CTradingBuildingRole::GetPileIDWithGoodToTransport(void) {
  
  unsigned __int16 *v1; // eax
  int v2; // esi
  pairNode *v4; // [esp+4h] [ebp-10h]
  signed int i; // [esp+Ch] [ebp-8h]
  CPile *PilePtr; // [esp+10h] [ebp-4h]

  for ( i = 0;
        i < *(char *)(*(this + 94) + 57);
        ++i )
  {
    v1 = std::vector<unsigned short>::operator[](this + 152, i);
    PilePtr = CPileMgr::GetPilePtr(*v1);
    if ( CPile::GetRoleType(PilePtr) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4581, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v4 = (pairNode *)CPile::Role(PilePtr);
    if ( CTradePileRole::GetTradeRoleType((CTradePileRole *)v4) == 1 )
    {
      v2 = PilePtr->Amount(PilePtr);
      if ( CTradePileRole::GetExpectedAmount((CTradePileRole *)v4) + v2 != 0 )
      {
        return ((int (__stdcall *)())IEntity::ID)();
      }
    }
  }
  return 0;
}


// address=[0x1527ec0]
// Decompiled from int __thiscall CTradingBuildingRole::CalcNrAvaibleGood(char *this, int a2)
int  CTradingBuildingRole::CalcNrAvaibleGood(bool a2) {
  
  int v3; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v3 = 0;
  for ( i = 0;
        i < 43;
        ++i )
  {
    v3 += this[i + 384] - this[i + 427];
  }
  return v3;
}


// address=[0x1527f20]
// Decompiled from char __thiscall CTradingBuildingRole::CrushBuilding(CInternationalTrader **this)
bool  CTradingBuildingRole::CrushBuilding(void) {
  
  unsigned __int8 *v1; // eax
  int v2; // eax
  void *v3; // eax
  int v5; // [esp-4h] [ebp-10h]
  int v6; // [esp+0h] [ebp-Ch]
  unsigned __int8 *BuildingPtr; // [esp+4h] [ebp-8h]

  ((void (__thiscall *)(CTradingBuildingRole *))CTradingBuildingRole::DisableTranding)((CTradingBuildingRole *)this);
  CTradingBuildingRole::CancelIncomingChargeTraders((CTradingBuildingRole *)this);
  CTradingBuildingRole::CancelIncomingDeliverTraders((CTradingBuildingRole *)this);
  CTradingBuildingRole::CancelLoadingVehicle((CTradingBuildingRole *)this);
  if ( *(this + 171) != 0 )
  {
    BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
    CInternationalTrader::RemoveBuilding(*(this + 171), (struct CBuilding *)BuildingPtr);
  }
  CTradingBuildingRole::ClearRegisterTargetBuildings((CTradingBuildingRole *)this);
  v1 = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
  v2 = CBuilding::EnsignWorldIdx((CBuilding *)v1);
  v6 = CWorldManager::EcoSectorId(v2);
  v5 = *((unsigned __int16 *)this + 3);
  v3 = (void *)((int (__stdcall *)(int))CEcoSectorMgr::operator[])(v6);
  CEcoSector::CleanUpBuildingNeed(v3, v5);
  return 1;
}


// address=[0x1527fd0]
// Decompiled from int __thiscall CTradingBuildingRole::ConvertEventIntoGoal(CTradingBuildingRole *this, struct CBuilding *a2, struct CEntityEvent *a3)
void  CTradingBuildingRole::ConvertEventIntoGoal(class CBuilding * a2, class CEntityEvent * a3) {
  
  if ( a3->m_iEvent == 9 && a3->m_iDataA == *((unsigned __int16 *)this + 190) )
  {
    *((_WORD *)this + 190) = 0;
    CTradingBuildingRole::CancelIncomingChargeTraders(this);
    ((void (__thiscall *)(CTradingBuildingRole *))CTradingBuildingRole::DisableTranding)(this);
  }
  return ((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(14);
}


// address=[0x1528020]
// Decompiled from int __thiscall CTradingBuildingRole::DetermineTransportType(CTradingBuildingRole *this)
int  CTradingBuildingRole::DetermineTransportType(void) {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax
  int v4; // [esp+0h] [ebp-10h]
  unsigned __int8 *BuildingPtr; // [esp+8h] [ebp-8h]

  if ( *((_WORD *)this + 190) == 0 && *((_WORD *)this + 191) == 0 )
  {
    return 0;
  }
  v4 = 0;
  BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
  if ( BuildingPtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4658, "pBuilding") == 1 )
  {
    __debugbreak();
  }
  if ( BuildingPtr == 0 )
  {
    return 0;
  }
  if ( CTradingBuildingRole::GetCartIDAtBuilding(this, (struct CBuilding *)BuildingPtr) != 0 )
  {
    return 3;
  }
  if ( CTradingBuildingRole::GetDonkeyIDAtBuilding(this, (struct CBuilding *)BuildingPtr) != 0 )
  {
    return 2;
  }
  if ( IEntity::Type((IEntity *)BuildingPtr) == 32 )
  {
    if ( *((_WORD *)this + 190) != 0 )
    {
      v2 = (unsigned __int16 *)((unsigned __int16 *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 190));
      if ( IEntity::Type((IEntity *)v2) == 32 )
      {
        return 1;
      }
    }
    if ( *((_WORD *)this + 191) != 0 )
    {
      v3 = (unsigned __int16 *)((unsigned __int16 *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 191));
      if ( IEntity::Type((IEntity *)v3) == 32 )
      {
        return 1;
      }
    }
  }
  return v4;
}


// address=[0x1528150]
// Decompiled from int __thiscall CTradingBuildingRole::GetTargetBuildingID(CTradingBuildingRole *this, bool a2)
int  CTradingBuildingRole::GetTargetBuildingID(bool a2) {
  
  if ( a2 )
  {
    return *((unsigned __int16 *)this + 191);
  }
  else
  {
    return *((unsigned __int16 *)this + 190);
  }
}


// address=[0x1528180]
// Decompiled from char __thiscall CTradingBuildingRole::StartLoadIntTraderDonkey(CTradingBuildingRole *this, unsigned int a2)
void  CTradingBuildingRole::StartLoadIntTraderDonkey(int a2) {
  
  int JobType; // eax
  int DepartBuildingID; // eax
  int v4; // eax
  char IsNeutralTrader; // [esp-4h] [ebp-40h]
  CEntityEvent v7; // [esp+4h] [ebp-38h] BYREF
  CEntityEvent *v8; // [esp+1Ch] [ebp-20h]
  CEntityEvent *v9; // [esp+20h] [ebp-1Ch]
  unsigned __int8 *SettlerPtr; // [esp+24h] [ebp-18h]
  CTradingBuildingRole *v11; // [esp+28h] [ebp-14h]
  CMFCToolBarImages *v12; // [esp+2Ch] [ebp-10h]
  int v13; // [esp+38h] [ebp-4h]

  v11 = this;
  if ( !CMapObjectMgr::ValidEntityId(a2) && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4712, "g_pMapObjectMgr->ValidEntityId(iEntityID)") == 1 )
  {
    __debugbreak();
  }
  if ( *((_WORD *)v11 + 191) == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4713, "m_uTargetTradingBuilding!=0") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)v11 + 161) = a2;
  *((_BYTE *)v11 + 648) = 1;
  SettlerPtr = ((unsigned __int8 *(__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(a2);
  v12 = (CMFCToolBarImages *)CSettler::Role((CSettler *)SettlerPtr);
  JobType = CDonkeyRole::GetJobType((CDonkeyRole *)v12);
  if ( JobType == 0 )
  {
    DepartBuildingID = CDonkeyRole::GetDepartBuildingID(v12);
    CDonkeyRole::SetTargetBuildingID((CDonkeyRole *)v12, DepartBuildingID);
    CDonkeyRole::SetDepartBuildingID((CDonkeyRole *)v12, *((unsigned __int16 *)v11 + 3));
    CDonkeyRole::SetJobType((CDonkeyRole *)v12, 2);
    IsNeutralTrader = CDonkeyRole::IsNeutralTrader((CDonkeyRole *)v12);
    v4 = ((int (__stdcall *)())IEntity::ID)();
    CTradingBuildingRole::RegisterIncomingTrader(v11, v4, 2, IsNeutralTrader);
    v9 = CEntityEvent::CEntityEvent(&v7, 0xAu, 0, 0, 0, *((unsigned __int16 *)v11 + 3));
    v8 = v9;
    v13 = 0;
    (*(void (__thiscall **)(unsigned __int8 *, CEntityEvent *))(*(_DWORD *)SettlerPtr + 80))(SettlerPtr, v9);
    v13 = -1;
    CEntityEvent::~CEntityEvent(&v7);
    LOBYTE(JobType) = ((char (__thiscall *)(CDonkeyRole *, bool))CDonkeyRole::SetNeutralTraderStatus)((CDonkeyRole *)v12, 1);
  }
  return JobType;
}


// address=[0x1528300]
// Decompiled from void __thiscall CTradingBuildingRole::StartLoadIntTraderShip(CTradingBuildingRole *this, unsigned int a2)
void  CTradingBuildingRole::StartLoadIntTraderShip(int a2) {
  
  int DepartHarbourID; // eax
  int v3; // eax
  bool IsNeutralTrader; // [esp-4h] [ebp-Ch]
  CTransportShip *VehiclePtr; // [esp+4h] [ebp-4h]

  if ( !CMapObjectMgr::ValidEntityId(a2) && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4747, "g_pMapObjectMgr->ValidEntityId(iEntityID)") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)this + 158) = a2;
  *((_BYTE *)this + 636) = 1;
  VehiclePtr = (CTransportShip *)CVehicleMgr::GetVehiclePtr(a2);
  if ( CTransportShip::GetJobType(VehiclePtr) == 0 )
  {
    DepartHarbourID = CTransportShip::GetDepartHarbourID(VehiclePtr);
    CTransportShip::SetTargetHarbourID(VehiclePtr, DepartHarbourID);
    CTransportShip::SetDepartHarbourID(VehiclePtr, *((unsigned __int16 *)this + 3));
    CTransportShip::SetJobType(VehiclePtr, 2);
    IsNeutralTrader = CTransportShip::IsNeutralTrader(VehiclePtr);
    v3 = ((int (__stdcall *)())IEntity::ID)();
    CTradingBuildingRole::RegisterIncomingTrader(this, v3, 1, IsNeutralTrader);
    CTransportShip::SetNeutralTraderStatus(VehiclePtr, 1);
  }
}


// address=[0x15283d0]
// Decompiled from signed int __thiscall CTradingBuildingRole::ReserveExportPile(CTradingBuildingRole *this, int a2, int a3, int a4)
void  CTradingBuildingRole::ReserveExportPile(int a2, int a3, int a4) {
  
  signed int result; // eax
  unsigned __int16 *v5; // eax
  CTradePileRole *v7; // [esp+4h] [ebp-Ch]
  signed int i; // [esp+8h] [ebp-8h]
  struct CPile *PilePtr; // [esp+Ch] [ebp-4h]

  for ( i = 0;
        ;
        ++i )
  {
    result = *(char *)(*((_DWORD *)this + 94) + 57);
    if ( i >= result )
    {
      break;
    }
    v5 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
    PilePtr = CPileMgr::GetPilePtr(*v5);
    if ( PilePtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4828, "pPile!=NULL") == 1 )
    {
      __debugbreak();
    }
    v7 = (CTradePileRole *)CPile::Role(PilePtr);
    if ( CTradePileRole::GetTradeRoleType(v7) == 3 && a4 > 0 && PilePtr->Amount(PilePtr) > 0 )
    {
      CTradePileRole::SetTradeRoleType(v7, 4);
      a4 -= CTradePileRole::ReservesGood(v7, a4, a3, PilePtr);
    }
  }
  return result;
}


// address=[0x15284b0]
// Decompiled from signed int __thiscall CTradingBuildingRole::ReserveImportPile(CTradingBuildingRole *this, int a2)
void  CTradingBuildingRole::ReserveImportPile(int a2) {
  
  signed int result; // eax
  unsigned __int16 *v3; // eax
  CTradePileRole *v4; // [esp+0h] [ebp-10h]
  struct CPile *PilePtr; // [esp+4h] [ebp-Ch]
  signed int i; // [esp+Ch] [ebp-4h]

  for ( i = 0;
        ;
        ++i )
  {
    result = *(char *)(*((_DWORD *)this + 94) + 57);
    if ( i >= result )
    {
      break;
    }
    if ( a2 > 0 )
    {
      v3 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
      PilePtr = CPileMgr::GetPilePtr(*v3);
      if ( PilePtr == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4860, "pPile!=NULL") == 1 )
      {
        __debugbreak();
      }
      v4 = (CTradePileRole *)CPile::Role(PilePtr);
      if ( CTradePileRole::GetTradeRoleType(v4) == 0 )
      {
        CTradePileRole::SetTradeRoleType(v4, 5);
        a2 -= 8;
      }
    }
  }
  return result;
}


// address=[0x1528560]
// Decompiled from int __thiscall CTradingBuildingRole::CalcExportedGoods(_DWORD *this)
int  CTradingBuildingRole::CalcExportedGoods(void) {
  
  unsigned __int16 *v1; // eax
  CTradePileRole *v3; // [esp+0h] [ebp-14h]
  int v5; // [esp+8h] [ebp-Ch]
  struct CPile *PilePtr; // [esp+Ch] [ebp-8h]
  signed int i; // [esp+10h] [ebp-4h]

  v5 = 0;
  for ( i = 0;
        i < *(char *)(*(this + 94) + 57);
        ++i )
  {
    v1 = std::vector<unsigned short>::operator[](this + 152, i);
    PilePtr = CPileMgr::GetPilePtr(*v1);
    v3 = (CTradePileRole *)CPile::Role(PilePtr);
    if ( CTradePileRole::GetTradeRoleType(v3) == 3 )
    {
      v5 += ((int (__thiscall *)(struct CPile *, CTradePileRole *))PilePtr->Amount)(PilePtr, v3);
    }
  }
  return v5;
}


// address=[0x15285f0]
// Decompiled from int __thiscall CTradingBuildingRole::GetTotalExportedGoodAmount(CTradingBuildingRole *this, struct CBuilding *a2)
int  CTradingBuildingRole::GetTotalExportedGoodAmount(class CBuilding * a2) {
  
  int *v3; // eax
  int v4; // edx
  unsigned __int16 *v5; // eax
  int v6; // eax
  int v7; // eax
  _BYTE v8[16]; // [esp+4h] [ebp-6Ch] BYREF
  _BYTE v9[12]; // [esp+14h] [ebp-5Ch] BYREF
  _BYTE v10[12]; // [esp+20h] [ebp-50h] BYREF
  _BYTE v11[12]; // [esp+2Ch] [ebp-44h] BYREF
  int v12; // [esp+38h] [ebp-38h]
  int v13; // [esp+3Ch] [ebp-34h]
  int v14; // [esp+40h] [ebp-30h]
  int v15; // [esp+44h] [ebp-2Ch]
  std::_Iterator_base12 *v16; // [esp+48h] [ebp-28h]
  std::_Iterator_base12 *v17; // [esp+4Ch] [ebp-24h]
  int v18; // [esp+50h] [ebp-20h]
  struct CPile *PilePtr; // [esp+54h] [ebp-1Ch]
  signed int i; // [esp+58h] [ebp-18h]
  CTradingBuildingRole *v21; // [esp+5Ch] [ebp-14h]
  char v22; // [esp+63h] [ebp-Dh]
  int v23; // [esp+6Ch] [ebp-4h]

  v21 = this;
  if ( a2 == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4891, "pBuilding!=NULL") == 1 )
  {
    __debugbreak();
  }
  if ( a2 == 0 )
  {
    return 0;
  }
  if ( *((_DWORD *)v21 + 171) == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 4893, "m_pTrader!=NULL") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)v21 + 171) == 0 )
  {
    return 0;
  }
  v18 = 0;
  CInternationalTrader::GetExportGoodList((int)v8, a2);
  v23 = 0;
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::begin((int)v11);
  LOBYTE(v23) = 1;
  while ( 1 )
  {
    v17 = (std::_Iterator_base12 *)std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::end((int)v9);
    v16 = v17;
    LOBYTE(v23) = 2;
    v22 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator!=(v17);
    LOBYTE(v23) = 1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v9);
    if ( v22 == 0 )
    {
      break;
    }
    v3 = (int *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator*(v11);
    v4 = v3[1];
    v12 = *v3;
    v13 = v4;
    v15 = (int)CBuilding::Role(a2);
    for ( i = 0;
          i < *(char *)(*((_DWORD *)v21 + 94) + 57);
          ++i )
    {
      v5 = std::vector<unsigned short>::operator[]((void *)(v15 + 608), i);
      PilePtr = CPileMgr::GetPilePtr(*v5);
      v6 = ((int (__thiscall *)(struct CPile *))PilePtr->GetGoodType)(PilePtr);
      if ( v6 == v13 )
      {
        v7 = PilePtr->Amount(PilePtr);
        v18 += v7;
      }
    }
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::operator++((int)v10, 0);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v10);
  }
  LOBYTE(v23) = 0;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>>>(v11);
  v14 = v18;
  v23 = -1;
  std::vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>::~vector<CInternationalTrader::CPlayerTradeInfo::TGoodInfo>();
  return v14;
}


// address=[0x15287e0]
// Decompiled from int __fastcall CTradingBuildingRole::DisableTranding(CTradingBuildingRole *this)
void  CTradingBuildingRole::DisableTranding(void) {
  
  int result; // eax
  int v2; // eax
  CBuilding *v3; // eax
  unsigned __int8 *v4; // eax
  int v5; // eax
  void *v6; // eax
  unsigned __int16 *v7; // eax
  int v8; // [esp-4h] [ebp-24h]
  int v9; // [esp-4h] [ebp-24h]
  int v10; // [esp+0h] [ebp-20h]
  int v11; // [esp+4h] [ebp-1Ch]
  unsigned __int8 *BuildingPtr; // [esp+8h] [ebp-18h]
  int v13; // [esp+Ch] [ebp-14h]
  signed int i; // [esp+10h] [ebp-10h]
  CPile *PilePtr; // [esp+14h] [ebp-Ch]
  CTradePileRole *v16; // [esp+18h] [ebp-8h]

  result = (int)this;
  if ( *((_WORD *)this + 191) != 0 )
  {
    BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
    v8 = *((unsigned __int16 *)this + 191);
    v2 = ((int (__stdcall *)())IEntity::ID)();
    BBSupportTracePrintF(0, "Disable trading for building %d with Building %d", v2, v8);
    v3 = (CBuilding *)((CBuilding *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 191));
    v10 = (int)CBuilding::Role(v3);
    CTradingBuildingRole::CancelLoadingVehicle(this);
    CTradingBuildingRole::CancelIncomingChargeTraders(this);
    CTradingBuildingRole::CancelIncomingDeliverTraders(this);
    *((_WORD *)this + 191) = 0;
    CTradingBuildingRole::ShowTradeRoute(this);
    v4 = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
    v5 = CBuilding::EnsignWorldIdx((CBuilding *)v4);
    v11 = CWorldManager::EcoSectorId(v5);
    v9 = *((unsigned __int16 *)this + 3);
    v6 = (void *)((int (__stdcall *)(int))CEcoSectorMgr::operator[])(v11);
    CEcoSector::CleanUpBuildingNeed(v6, v9);
    for ( i = 0;
          ;
          ++i )
    {
      result = *(char *)(*((_DWORD *)this + 94) + 57);
      if ( i >= result )
      {
        break;
      }
      v7 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
      PilePtr = CPileMgr::GetPilePtr(*v7);
      v16 = (CTradePileRole *)CPile::Role(PilePtr);
      if ( CTradePileRole::GetTradeRoleType(v16) == 3 )
      {
        CPile::NotifyTargetDieAndDetachAllObservers(PilePtr);
      }
      if ( CTradePileRole::GetTradeRoleType(v16) == 3 || CTradePileRole::GetTradeRoleType(v16) == 4 || CTradePileRole::GetTradeRoleType(v16) == 5 )
      {
        if ( ((int (__thiscall *)(CPile *, int, int, unsigned __int8 *))PilePtr->Amount)(PilePtr, v10, v11, BuildingPtr) <= 0 )
        {
          CTradePileRole::SetTradeRoleType(v16, 0);
        }
        else
        {
          CTradePileRole::SetTradeRoleType(v16, 1);
        }
        v13 = ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr);
        CTradingBuildingRole::ClearGoodState(this, v13, 8);
        CTradingBuildingRole::ClearGoodState(this, v13, 4);
        *((_BYTE *)this + v13 + 513) = 0;
        *((_BYTE *)this + v13 + 556) = 0;
        *((_DWORD *)this + 172) = 0;
      }
    }
  }
  return result;
}


// address=[0x15289e0]
// Decompiled from int __thiscall CTradingBuildingRole::GetMaxTradingGoodAmount(CTradingBuildingRole *this)
int const  CTradingBuildingRole::GetMaxTradingGoodAmount(void) {
  
  return 16;
}


// address=[0x15289f0]
// Decompiled from int __thiscall CTradingBuildingRole::RequestTradingGood(CTradingBuildingRole *this, unsigned int a2)
void  CTradingBuildingRole::RequestTradingGood(enum PILE_TYPES a2) {
  
  int result; // eax
  int v3; // esi
  char v4; // [esp+4h] [ebp-Ch]
  int v5; // [esp+8h] [ebp-8h]

  v5 = *((char *)this + a2 + 556) + CTradingBuildingRole::GetExportGoodAmount(this, a2);
  result = CTradingBuildingRole::GetMaxTradingGoodAmount(this);
  if ( v5 < result )
  {
    v4 = CTradingBuildingRole::GetMaxTradingGoodAmount(this) - v5;
    *((_BYTE *)this + a2 + 513) = v4;
    CTradingBuildingRole::SetGoodState(this, a2, 8);
    *((_BYTE *)this + a2 + 556) += v4;
    v3 = *((char *)this + a2 + 556);
    result = CTradingBuildingRole::GetMaxTradingGoodAmount(this);
    if ( v3 > result )
    {
      result = BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 5027, "m_vTradingGoodTransportAmount[ _GoodType ] <= GetMaxTradingGoodAmount()");
      if ( result == 1 )
      {
        __debugbreak();
      }
    }
  }
  return result;
}


// address=[0x1528ab0]
// Decompiled from char __thiscall CTradingBuildingRole::CheckTradingTransport(CTradingBuildingRole *this, struct CBuilding *a2, unsigned int a3)
bool  CTradingBuildingRole::CheckTradingTransport(class CBuilding * a2, int a3) {
  
  unsigned __int16 *v4; // eax
  int v5; // eax
  CEcoSector *v6; // eax
  int v7; // esi
  int v8; // esi
  int ExpectedAmount; // eax
  int RequestedAmount; // [esp+8h] [ebp-30h]
  int v11; // [esp+10h] [ebp-28h]
  int v12; // [esp+14h] [ebp-24h]
  int v13; // [esp+18h] [ebp-20h]
  signed int i; // [esp+20h] [ebp-18h]
  pairNode *v15; // [esp+24h] [ebp-14h]
  int v16; // [esp+28h] [ebp-10h]
  CPile *PilePtr; // [esp+30h] [ebp-8h]
  char v19; // [esp+37h] [ebp-1h]

  if ( a3 > 0x2A || *((_BYTE *)this + a3 + 513) == 0 )
  {
    return 0;
  }
  CTradingBuildingRole::GetCurrentAmount(this, a3);
  RequestedAmount = CTradingBuildingRole::GetRequestedAmount(this, a3, 1);
  v16 = *((char *)this + a3 + 513) - CTradingBuildingRole::GetExpectedAmount(this, a3, 1) - RequestedAmount;
  if ( v16 <= 0 )
  {
    return 0;
  }
  v19 = 0;
  for ( i = 0;
        i < *(char *)(*((_DWORD *)this + 94) + 57);
        ++i )
  {
    v4 = std::vector<unsigned short>::operator[]((char *)this + 608, i);
    PilePtr = CPileMgr::GetPilePtr(*v4);
    if ( CPile::GetRoleType(PilePtr) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 5074, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v15 = (pairNode *)CPile::Role(PilePtr);
    if ( CTradePileRole::GetTradeRoleType((CTradePileRole *)v15) == 0 )
    {
      v5 = ((int (__stdcall *)())IEntity::WorldIdx)();
      v13 = CWorldManager::EcoSectorId(v5);
      if ( v13 == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 5083, "m_iESId != 0") == 1 )
      {
        __debugbreak();
      }
      if ( v13 != 0 )
      {
        v6 = (CEcoSector *)((int (__stdcall *)(int))CEcoSectorMgr::operator[])(v13);
        if ( CEcoSector::GetGoodOffer(v6, a3) != 0 )
        {
          v7 = 8 - PilePtr->Amount(PilePtr);
          v8 = v7 - CPile::AmountComing(PilePtr);
          v12 = v8 - CTradePileRole::GetExpectedAmount((CTradePileRole *)v15);
          if ( v16 >= v12 )
          {
            v11 = v12;
          }
          else
          {
            v11 = v16;
          }
          if ( v11 != 0 && ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr) == 0 )
          {
            CPile::SetGoodType(PilePtr, a3);
            CTradePileRole::SetTradeRoleType(v15, 3);
            ExpectedAmount = CTradePileRole::GetExpectedAmount((CTradePileRole *)v15);
            CTradePileRole::SetExpectedAmount(v15, (struct CPaneDivider *)(v11 + ExpectedAmount));
            ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
            v19 = 1;
            v16 -= v11;
          }
        }
      }
    }
  }
  return v19;
}


// address=[0x1528d00]
// Decompiled from int __thiscall CTradingBuildingRole::ClearTradingPiles(_DWORD *this, int a2, int a3)
void  CTradingBuildingRole::ClearTradingPiles(int a2, enum TGOOD_STATUS a3) {
  
  int result; // eax
  unsigned __int16 *v4; // eax
  int v5; // [esp+0h] [ebp-14h]
  CPaneContainer *v6; // [esp+4h] [ebp-10h]
  signed int i; // [esp+Ch] [ebp-8h]
  CPile *PilePtr; // [esp+10h] [ebp-4h]

  if ( a3 != 4 && a3 != 8 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 5116, "_ForStatus == TRADING_IMPORT || _ForStatus == TRADING_EXPORT") == 1 )
  {
    __debugbreak();
  }
  for ( i = 0;
        ;
        ++i )
  {
    result = *(this + 94);
    if ( i >= *(char *)(result + 57) )
    {
      break;
    }
    v4 = std::vector<unsigned short>::operator[](this + 152, i);
    PilePtr = CPileMgr::GetPilePtr(*v4);
    if ( CPile::GetRoleType(PilePtr) != 4 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 5121, "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v6 = (CPaneContainer *)CPile::Role(PilePtr);
    if ( a3 == 8 && CTradePileRole::GetTradeRoleType((CTradePileRole *)v6) == 3 )
    {
      v5 = ((int (__thiscall *)(CPile *))PilePtr->GetGoodType)(PilePtr);
      if ( v5 == a2 )
      {
        CPile::NotifyTargetDieAndDetachAllObservers(PilePtr);
        CTradePileRole::SetTradeRoleType(v6, 2);
        *((_BYTE *)this + v5 + 556) = 0;
        *((_BYTE *)this + v5 + 513) = 0;
        CTradePileRole::SetExpectedAmount(v6, 0);
      }
    }
    if ( a3 == 4 )
    {
      CTradePileRole::GetTradeRoleType((CTradePileRole *)v6);
    }
  }
  return result;
}


// address=[0x1528e30]
// Decompiled from char *__thiscall CTradingBuildingRole::SetGoodState(_BYTE *this, unsigned int a2, char a3)
void  CTradingBuildingRole::SetGoodState(int a2, enum TGOOD_STATUS a3) {
  
  char *result; // eax

  if ( a2 >= 0x2C )
  {
    return result;
  }
  result = &this[a2];
  this[a2 + 470] |= a3;
  return result;
}


// address=[0x1528e70]
// Decompiled from char *__thiscall CTradingBuildingRole::ClearGoodState(_BYTE *this, int a2, char a3)
void  CTradingBuildingRole::ClearGoodState(int a2, enum TGOOD_STATUS a3) {
  
  char *result; // eax

  result = &this[a2];
  this[a2 + 470] &= ~a3;
  return result;
}


// address=[0x1528ea0]
// Decompiled from bool __thiscall CTradingBuildingRole::HasGoodState(char *this, int a2, int a3)
bool  CTradingBuildingRole::HasGoodState(int a2, enum TGOOD_STATUS a3) {
  
  return (a3 & this[a2 + 470]) != 0;
}


// address=[0x1528ee0]
// Decompiled from int __stdcall CTradingBuildingRole::GetTradingStatus(char a1)
enum TGOOD_STATUS  CTradingBuildingRole::GetTradingStatus(int a1) {
  
  char v2; // [esp+7h] [ebp-1h]

  v2 = a1 & 0xFC;
  if ( (a1 & 4) == 0 && (a1 & 8) == 0 && v2 != 0 && BBSupportDbgReport(2, "MapObjects\\Building\\TradingBuilding.cpp", 5170, "((tmpStatus & TRADING_IMPORT)!=0) || ((tmpStatus & TRADING_EXPORT)!=0) || (tmpStatus ==0)") == 1 )
  {
    __debugbreak();
  }
  return v2;
}


// address=[0x152bd30]
// Decompiled from int __thiscall CTradingBuildingRole::GetBuildingID(CTradingBuildingRole *this)
int  CTradingBuildingRole::GetBuildingID(void) {
  
  CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
  return ((int (__stdcall *)())IEntity::ID)();
}


// address=[0x152bed0]
// Decompiled from char __thiscall CTradingBuildingRole::TryCrushBuilding(CTradingBuildingRole *this)
bool  CTradingBuildingRole::TryCrushBuilding(void) {
  
  return 1;
}


// address=[0x40f22bc]
// [Decompilation failed for static int CTradingBuildingRole::m_iLastX]

// address=[0x40f22c0]
// [Decompilation failed for static int CTradingBuildingRole::m_iLastY]

