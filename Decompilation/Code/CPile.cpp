#include "CPile.h"

// Definitions for class CPile

// address=[0x12fd290]
// Decompiled from bool __thiscall CPile::GoodAvailable(CPile *this)

bool  CPile::GoodAvailable(void)const {
  
  return *((unsigned __int8 *)this + 69) > (int)*((unsigned __int8 *)this + 70);
}


// address=[0x1401580]
// Decompiled from int __cdecl CPile::New(int a1)

static class CPersistence * __cdecl CPile::New(std::istream &) {
  
  if ( CPile::operator new(0x7Cu) )
    return CPile::CPile(a1);
  else
    return 0;
}


// address=[0x1439a40]
// Decompiled from int __thiscall CPile::AmountComing(CPile *this)

int  CPile::AmountComing(void)const {
  
  return *((unsigned __int8 *)this + 71);
}


// address=[0x1470870]
// Decompiled from int __thiscall CPile::AmountLeaving(CPile *this)

int  CPile::AmountLeaving(void)const {
  
  return *((unsigned __int8 *)this + 70);
}


// address=[0x14708e0]
// Decompiled from int __thiscall CPile::ChangeGoodTypeUnforseen(CPile *this, int a2)

bool  CPile::ChangeGoodTypeUnforseen(int) {
  
  int v2; // eax

  v2 = std::auto_ptr<IPileRole>::operator->();
  return (*(int (__thiscall **)(int, CPile *, int))(*(_DWORD *)v2 + 72))(v2, this, a2);
}


// address=[0x14e8150]
// Decompiled from bool __thiscall CPile::IsPatchPile(CPile *this)

bool  CPile::IsPatchPile(void)const {
  
  return *((_BYTE *)this + 73) == 1;
}


// address=[0x14e8190]
// Decompiled from int __thiscall CPile::NumberOfAvailableGoods(CPile *this)

int  CPile::NumberOfAvailableGoods(void)const {
  
  if ( *((unsigned __int8 *)this + 69) < (int)*((unsigned __int8 *)this + 70)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\mapobjects\\pile\\Pile.h",
         288,
         "m_uAmount >= m_uAmountLeaving") == 1 )
  {
    __debugbreak();
  }
  return *((unsigned __int8 *)this + 69) - *((unsigned __int8 *)this + 70);
}


// address=[0x151fa90]
// Decompiled from int __thiscall CPile::GetRoleType(CPile *this)

int  CPile::GetRoleType(void)const {
  
  return *((unsigned __int8 *)this + 72);
}


// address=[0x151fab0]
// Decompiled from int __thiscall CPile::Role(CPile *this)

class IPileRole &  CPile::Role(void) {
  
  return std::auto_ptr<IPileRole>::operator*(this);
}


// address=[0x151fad0]
// Decompiled from CPile *__thiscall CPile::SetGoodType(CPile *this, char a2)

void  CPile::SetGoodType(int) {
  
  CPile *result; // eax

  result = this;
  *((_BYTE *)this + 68) = a2;
  return result;
}


// address=[0x152f210]
// Decompiled from bool __thiscall CPile::HasSpace(CPile *this)

bool  CPile::HasSpace(void)const {
  
  return *((unsigned __int8 *)this + 71) + *((unsigned __int8 *)this + 69) < 8;
}


// address=[0x155b300]
// Decompiled from void __thiscall CPile::OfferCompletePileIfPossible(CPile *this, int a2)

void  CPile::OfferCompletePileIfPossible(int) {
  
  CPile::Offer(this, -1, a2);
}


// address=[0x155b340]
// Decompiled from CPile *__thiscall CPile::SetOfferFlag(CPile *this, bool a2)

void  CPile::SetOfferFlag(bool) {
  
  CPile *result; // eax

  result = this;
  *((_BYTE *)this + 80) = a2;
  return result;
}


// address=[0x155b360]
// Decompiled from CPile *__thiscall CPile::SetRoleType(CPile *this, char a2)

void  CPile::SetRoleType(int) {
  
  CPile *result; // eax

  result = this;
  *((_BYTE *)this + 72) = a2;
  return result;
}


// address=[0x155b7d0]
// Decompiled from int __thiscall CPile::GetBuildingId(CPile *this)

int  CPile::GetBuildingId(void)const {
  
  if ( *((_BYTE *)this + 72) == 3
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\mapobjects\\pile\\Pile.h",
         280,
         "m_uPileRole != IPileRole::PILE_ANYWHERE") == 1 )
  {
    __debugbreak();
  }
  return *((unsigned __int16 *)this + 41);
}


// address=[0x155b820]
// Decompiled from char __thiscall CPile::GetOfferFlag(CPile *this)

bool  CPile::GetOfferFlag(void)const {
  
  return *((_BYTE *)this + 80);
}


// address=[0x155b840]
// Decompiled from bool __thiscall CPile::IsInOfferList(CPile *this)

bool  CPile::IsInOfferList(void)const {
  
  return IEntity::FlagBits(this, Offered) != 0;
}


// address=[0x155bda0]
// Decompiled from void __thiscall CPile::Delete(CPile *this)

void  CPile::Delete(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int LastLogicUpdateTick; // eax
  int v6; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-38h]
  const char *v9; // [esp-4h] [ebp-38h]
  _BYTE v10[24]; // [esp+4h] [ebp-30h] BYREF
  const struct CEntityEvent *v11; // [esp+1Ch] [ebp-18h]
  const struct CEntityEvent *v12; // [esp+20h] [ebp-14h]
  CPaneContainer *v13; // [esp+24h] [ebp-10h]
  int v14; // [esp+30h] [ebp-4h]

  v13 = this;
  v1 = IEntity::WorldIdx();
  CWorldManager::SetPileId(v1, 0);
  v2 = IEntity::WorldIdx();
  CWorldManager::SetMoveCostsBits(v2, 2);
  v3 = IEntity::WorldIdx();
  CWorldManager::ClearFlagBits(v3, 2);
  v4 = IEntity::EntityId((unsigned __int16 *)v13);
  v12 = CEntityEvent::CEntityEvent((CEntityEvent *)v10, 9u, 0, v4, 0, 0);
  v11 = v12;
  v14 = 0;
  CPileObserverList::NotifyAndDetachAllObservers((CPaneContainer *)((char *)v13 + 88), v12);
  v14 = -1;
  CEntityEvent::~CEntityEvent(v10);
  v8 = *((unsigned __int16 *)v13 + 4);
  LastLogicUpdateTick = IAnimatedEntity::GetLastLogicUpdateTick(v13);
  CMapObjectMgr::UnRegisterFromLogicUpdate(g_pMapObjectMgr, LastLogicUpdateTick, v8);
  v6 = IEntity::ID();
  CPileMgr::CheckOutPile((CPileMgr *)&g_cPileMgr, v6);
  if ( debug )
  {
    if ( DEBUG_FLAGS[dword_4152058] )
    {
      v9 = (&off_37A3C2C)[2 * *((unsigned __int8 *)v13 + 68)];
      v7 = IEntity::ID();
      BBSupportTracePrintF(0, "Pile %u deleted goodType %s", v7, v9);
    }
  }
}


// address=[0x155bed0]
// Decompiled from int __thiscall CPile::LogicUpdate(CPile *this)

void  CPile::LogicUpdate(void) {
  
  int result; // eax
  int v2; // eax

  result = IAnimatedEntity::ProcessAllEvents(this);
  if ( (_BYTE)result )
    return result;
  v2 = std::auto_ptr<IPileRole>::operator->();
  return (*(int (__thiscall **)(int, CPile *))(*(_DWORD *)v2 + 40))(v2, this);
}


// address=[0x155bf10]
// Decompiled from void *__thiscall sub_195BF10(_BYTE *this)

struct SGfxObjectInfo *  CPile::GetGfxInfos(void) {
  
  j__memset(&IEntity::m_sGfxInfo, 0, 0x2D0u);
  if ( !this[68] || (unsigned __int8)this[68] >= 0x2Bu || !this[69] )
    return &IEntity::m_sGfxInfo;
  CGfxManager::GetPileGfxInfo(
    &IEntity::m_sGfxInfo,
    (unsigned __int8)this[68],
    (unsigned __int8)this[69],
    (unsigned __int8)this[74]);
  byte_40FE518 = this[10];
  byte_40FE51A = IEntity::IsVisible(this);
  return &IEntity::m_sGfxInfo;
}


// address=[0x155bfa0]
// Decompiled from CPile *__thiscall CPile::GetPatchGfx(CPile *this, struct SGfxPatchObject *a2)

void  CPile::GetPatchGfx(struct SGfxPatchObject &) {
  
  CPile *result; // eax

  if ( *((_BYTE *)this + 68) && *((unsigned __int8 *)this + 68) < 0x2Bu && *((_BYTE *)this + 69) )
  {
    CGfxManager::GetPatchPileGfxInfo(
      (CGfxManager *)g_pGfxManager,
      a2,
      *((unsigned __int8 *)this + 68),
      *((unsigned __int8 *)this + 69),
      *((unsigned __int8 *)this + 74));
  }
  else
  {
    *(_DWORD *)a2 = 0;
    *((_DWORD *)a2 + 1) = 0;
  }
  *((_DWORD *)a2 + 2) = *((__int16 *)this + 38);
  result = this;
  *((_DWORD *)a2 + 3) = *((__int16 *)this + 39);
  return result;
}


// address=[0x155c030]
// Decompiled from int __thiscall CPile::ChangeRole(CPile *this, int a2)

void  CPile::ChangeRole(int) {
  
  int v2; // eax
  struct IPileRole *PileRole; // [esp+4h] [ebp-20h]
  _BYTE v5[4]; // [esp+8h] [ebp-1Ch] BYREF
  int v6; // [esp+Ch] [ebp-18h]
  int v7; // [esp+10h] [ebp-14h]
  CPile *v8; // [esp+14h] [ebp-10h]
  int v9; // [esp+20h] [ebp-4h]

  v8 = this;
  if ( a2 != 3
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 319, "_iRoleType == IPileRole::PILE_ANYWHERE") == 1 )
  {
    __debugbreak();
  }
  if ( *((_WORD *)v8 + 41) )
  {
    v7 = CBuildingMgr::operator[](*((unsigned __int16 *)v8 + 41));
    v2 = IEntity::ID();
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 64))(v7, v2);
  }
  PileRole = CPileMgr::CreatePileRole(a2);
  std::auto_ptr<IPileRole>::auto_ptr<IPileRole>(PileRole);
  v9 = 0;
  std::auto_ptr<IPileRole>::operator=(v5);
  v6 = std::auto_ptr<IPileRole>::operator->();
  (*(void (__thiscall **)(int, CPile *))(*(_DWORD *)v6 + 36))(v6, v8);
  v9 = -1;
  return std::auto_ptr<IPileRole>::~auto_ptr<IPileRole>(v5);
}


// address=[0x155c130]
// Decompiled from int __thiscall CPile::IncreaseUnforeseen(CPile *this, int a2)

int  CPile::IncreaseUnforeseen(int) {
  
  int v3; // eax
  int v4; // [esp+4h] [ebp-8h]

  if ( (unsigned int)a2 > 8
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 486, "(_iAmount >= 0) && (_iAmount <= MAX_PILE_AMOUNT)") == 1 )
  {
    __debugbreak();
  }
  if ( a2 <= 0 )
    return 0;
  v4 = 8 - *((unsigned __int8 *)this + 69) - *((unsigned __int8 *)this + 71);
  if ( v4 < 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 495, "iAvailableSpace >= 0") == 1 )
    __debugbreak();
  if ( a2 > v4 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 496, "_iAmount <= iAvailableSpace") == 1 )
    __debugbreak();
  if ( v4 <= 0 )
    return 0;
  if ( a2 > v4 )
    a2 = v4;
  *((_BYTE *)this + 69) += a2;
  CPile::AdjustStatistic(this, a2, 0);
  v3 = std::auto_ptr<IPileRole>::operator->();
  (*(void (__thiscall **)(int, CPile *, int))(*(_DWORD *)v3 + 8))(v3, this, a2);
  if ( *((unsigned __int8 *)this + 69) > 8u
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 514, "m_uAmount <= MAX_PILE_AMOUNT") == 1 )
  {
    __debugbreak();
  }
  if ( *((unsigned __int8 *)this + 71) + *((unsigned __int8 *)this + 69) > 8
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 515, "m_uAmount + m_uAmountComing <= MAX_PILE_AMOUNT") == 1 )
  {
    __debugbreak();
  }
  return a2;
}


// address=[0x155c2a0]
// Decompiled from CPile *__thiscall CPile::DecreaseUnforeseen(CPile *this, int a2)

void  CPile::DecreaseUnforeseen(int) {
  
  CPile *result; // eax
  int v3; // [esp+0h] [ebp-10h]
  int v4; // [esp+4h] [ebp-Ch]
  int v5; // [esp+8h] [ebp-8h]

  if ( (unsigned int)a2 > 8
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 527, "(_iAmount >= 0) && (_iAmount <= MAX_PILE_AMOUNT)") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  if ( a2 <= 0 )
    return result;
  v5 = *((unsigned __int8 *)this + 69) - *((unsigned __int8 *)this + 70);
  if ( v5 < 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 536, "iAvailableGoods >= 0") == 1 )
    __debugbreak();
  result = (CPile *)a2;
  if ( a2 > v5 )
  {
    result = (CPile *)BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 537, "_iAmount <= iAvailableGoods");
    if ( result == (CPile *)1 )
      __debugbreak();
  }
  if ( v5 <= 0 )
    return result;
  if ( a2 > v5 )
    a2 = v5;
  *((_BYTE *)this + 69) -= a2;
  CPile::AdjustStatistic(this, -a2, 0);
  v4 = std::auto_ptr<IPileRole>::operator->();
  (*(void (__thiscall **)(int, CPile *, int))(*(_DWORD *)v4 + 12))(v4, this, 1);
  if ( *((unsigned __int8 *)this + 69) > 8u
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 555, "m_uAmount <= MAX_PILE_AMOUNT") == 1 )
  {
    __debugbreak();
  }
  if ( *((unsigned __int8 *)this + 70) > (int)*((unsigned __int8 *)this + 69)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 556, "m_uAmountLeaving <= m_uAmount") == 1 )
  {
    __debugbreak();
  }
  result = this;
  if ( *((_BYTE *)this + 69) )
    return result;
  *((_BYTE *)this + 70) = 0;
  v3 = std::auto_ptr<IPileRole>::operator->();
  return (CPile *)(*(int (__thiscall **)(int, CPile *))(*(_DWORD *)v3 + 16))(v3, this);
}


// address=[0x155c430]
// Decompiled from int __thiscall CPile::ForceAmountLeaving(CPile *this, int a2, int a3)

bool  CPile::ForceAmountLeaving(int,int) {
  
  return CPile::GoodAvailable(this);
}


// address=[0x155c580]
// Decompiled from CPile *__thiscall CPile::SetBuildingId(CPile *this, int a2)

void  CPile::SetBuildingId(int) {
  
  int v2; // eax
  CPile *result; // eax
  int v4; // [esp+0h] [ebp-8h]

  if ( *((_BYTE *)this + 72) == 3
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 343, "m_uPileRole != IPileRole::PILE_ANYWHERE") == 1 )
  {
    __debugbreak();
  }
  if ( a2 <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 344, "_iBuidingId > 0") == 1 )
    __debugbreak();
  v4 = CBuildingMgr::operator[](a2);
  v2 = IEntity::EntityId((unsigned __int16 *)this);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 116))(v4, v2);
  result = this;
  if ( *((unsigned __int16 *)this + 41) == a2 )
    return result;
  result = (CPile *)BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 349, "m_uBuildingId == _iBuidingId");
  if ( result == (CPile *)1 )
    __debugbreak();
  return result;
}


// address=[0x155c640]
// Decompiled from void __thiscall CPile::Occupied(CPile *this, int a2)

void  CPile::Occupied(int) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  char v5; // al
  int v6; // [esp+4h] [ebp-Ch]
  int v7; // [esp+8h] [ebp-8h]

  if ( a2 <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 1176, "_iNewEcoSectorId > 0") == 1 )
    __debugbreak();
  v2 = CEcoSectorMgr::operator[](a2);
  v3 = CEcoSector::Owner(v2);
  v6 = CPlayerManager::Race(v3);
  v4 = (*(int (__thiscall **)(CPile *, int))(*(_DWORD *)this + 60))(this, v6);
  v5 = CPileMgr::ConvertGoodType((CPileMgr *)&g_cPileMgr, v4);
  CPile::SetGoodType(this, v5);
  v7 = std::auto_ptr<IPileRole>::operator->();
  (*(void (__thiscall **)(int, CPile *))(*(_DWORD *)v7 + 48))(v7, this);
  CPile::AdjustStatistic(this, *((unsigned __int8 *)this + 69), a2);
}


// address=[0x155c700]
// Decompiled from char __thiscall CPile::SetFree(CPile *this, int a2)

bool  CPile::SetFree(int) {
  
  int v3; // [esp+4h] [ebp-8h]

  if ( a2 <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 1199, "_iOldEcoSectorId > 0") == 1 )
    __debugbreak();
  v3 = std::auto_ptr<IPileRole>::operator->();
  (*(void (__thiscall **)(int, CPile *, int))(*(_DWORD *)v3 + 52))(v3, this, a2);
  CPile::AdjustStatistic(this, -*((unsigned __int8 *)this + 69), a2);
  return 0;
}


// address=[0x155c780]
// Decompiled from int __thiscall CPile::NotifyChangeEcoSector(CPile *this, int a2, int a3)

void  CPile::NotifyChangeEcoSector(int,int) {
  
  int v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+4h] [ebp-8h]

  if ( a2 <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 1219, "_iOldEcoSectorId > 0") == 1 )
    __debugbreak();
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 1220, "_iNewEcoSectorId > 0") == 1 )
    __debugbreak();
  if ( a2 == a3
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 1221, "_iOldEcoSectorId != _iNewEcoSectorId") == 1 )
  {
    __debugbreak();
  }
  v5 = *((unsigned __int8 *)this + 69);
  CPile::AdjustStatistic(this, -v5, a2);
  CPile::AdjustStatistic(this, v5, a3);
  v4 = std::auto_ptr<IPileRole>::operator->();
  return (*(int (__thiscall **)(int, CPile *, int, int))(*(_DWORD *)v4 + 56))(v4, this, a2, a3);
}


// address=[0x155c860]
// Decompiled from _DWORD *__thiscall CPile::Offer(CPile *this, int a2, int a3)

void  CPile::Offer(int,int) {
  
  _DWORD *result; // eax
  int v4; // eax
  unsigned __int16 *v5; // eax
  int v6; // [esp-8h] [ebp-Ch]
  int v7; // [esp-4h] [ebp-8h]

  if ( a3 < 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 762, "_iEcoSectorId >= 0") == 1 )
    __debugbreak();
  result = 0;
  if ( !a3 )
  {
    v4 = IEntity::WorldIdx();
    result = (_DWORD *)CWorldManager::EcoSectorId(v4);
    a3 = (int)result;
  }
  if ( a3 <= 0 )
    return result;
  v7 = IEntity::EntityId((unsigned __int16 *)this);
  v6 = (*(int (__thiscall **)(CPile *))(*(_DWORD *)this + 60))(this);
  v5 = (unsigned __int16 *)CEcoSectorMgr::operator[](a3);
  return CEcoSector::SetGoodOffer(v5, v6, v7);
}


// address=[0x155c8e0]
// Decompiled from void __thiscall CPile::CancelOffer(CPile *this, int a2, int a3)

void  CPile::CancelOffer(int,int) {
  
  int v3; // eax
  CEcoSector *v4; // eax
  int v5; // [esp-8h] [ebp-Ch]
  int v6; // [esp-4h] [ebp-8h]

  if ( a3 < 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 792, "_iEcoSectorId >= 0") == 1 )
    __debugbreak();
  if ( !a3 )
  {
    v3 = IEntity::WorldIdx();
    a3 = CWorldManager::EcoSectorId(v3);
  }
  if ( a3 > 0 )
  {
    v6 = IEntity::EntityId((unsigned __int16 *)this);
    v5 = (*(int (__thiscall **)(CPile *))(*(_DWORD *)this + 60))(this);
    v4 = (CEcoSector *)CEcoSectorMgr::operator[](a3);
    CEcoSector::GetPileOutOfOffer(v4, v5, v6);
  }
}


// address=[0x155c960]
// Decompiled from void __thiscall CPile::CancelCompleteOfferIfInOfferList(CPile *this, int a2)

void  CPile::CancelCompleteOfferIfInOfferList(int) {
  
  if ( CPile::IsInOfferList(this) )
    CPile::CancelOffer(this, -1, a2);
}


// address=[0x155c990]
// Decompiled from void __thiscall CPile::ChangeNumberOfOfferedGoodsInEcoSector(CPile *this, int a2, int a3)

void  CPile::ChangeNumberOfOfferedGoodsInEcoSector(int,int) {
  
  ;
}


// address=[0x155c9a0]
// Decompiled from int __thiscall CPile::CalcUrgent(CPile *this)

int  CPile::CalcUrgent(void)const {
  
  return 4000 * (16 - (*((unsigned __int8 *)this + 71) + 2 * *((unsigned __int8 *)this + 69)));
}


// address=[0x155c9d0]
// Decompiled from int __thiscall CPile::NotifyTargetDieAndDetachAllObservers(CPile *this)

void  CPile::NotifyTargetDieAndDetachAllObservers(void) {
  
  int v1; // eax
  int result; // eax
  _BYTE v3[24]; // [esp+4h] [ebp-38h] BYREF
  const struct CEntityEvent *v4; // [esp+1Ch] [ebp-20h]
  const struct CEntityEvent *v5; // [esp+20h] [ebp-1Ch]
  int v6; // [esp+24h] [ebp-18h]
  int v7; // [esp+28h] [ebp-14h]
  CPile *v8; // [esp+2Ch] [ebp-10h]
  int v9; // [esp+38h] [ebp-4h]

  v8 = this;
  v1 = IEntity::EntityId((unsigned __int16 *)this);
  v5 = CEntityEvent::CEntityEvent((CEntityEvent *)v3, 9u, 0, v1, 0, 0);
  v4 = v5;
  v9 = 0;
  CPileObserverList::NotifyAndDetachAllObservers((CPile *)((char *)v8 + 88), v5);
  v9 = -1;
  CEntityEvent::~CEntityEvent(v3);
  result = *((unsigned __int8 *)v8 + 71);
  if ( *((_BYTE *)v8 + 71) )
  {
    *((_BYTE *)v8 + 71) = 0;
    v7 = std::auto_ptr<IPileRole>::operator->();
    result = (*(int (__thiscall **)(int, CPile *))(*(_DWORD *)v7 + 32))(v7, v8);
  }
  if ( !*((_BYTE *)v8 + 70) )
    return result;
  *((_BYTE *)v8 + 70) = 0;
  v6 = std::auto_ptr<IPileRole>::operator->();
  return (*(int (__thiscall **)(int, CPile *))(*(_DWORD *)v6 + 24))(v6, v8);
}


// address=[0x155cab0]
// Decompiled from unsigned int __cdecl CPile::operator new(unsigned int a1)

static void * __cdecl CPile::operator new(unsigned int) {
  
  return CPileMgr::Alloc((CPileMgr *)&g_cPileMgr, a1);
}


// address=[0x155cad0]
// Decompiled from void __cdecl CPile::operator delete(void *a1)

static void __cdecl CPile::operator delete(void *) {
  
  CPileMgr::Dealloc((CPileMgr *)&g_cPileMgr, a1);
}


// address=[0x155cb10]
// Decompiled from void __thiscall CPile::Detach(CPile *this, int a2)

void  CPile::Detach(int) {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = CPileObserverList::Detach((CPile *)((char *)this + 88), a2);
  if ( v3 >= 0 )
  {
    if ( v3 > 0 )
    {
      if ( v3 != 1 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 919, "iDeltaAmount == 1") == 1 )
        __debugbreak();
      CPile::DecAmountComing(this);
    }
  }
  else
  {
    CPile::DecAmountLeaving(this, -v3);
  }
}


// address=[0x155cb80]
// Decompiled from void __thiscall CPile::ChangeAmountAndDetach(CPile *this, int a2)

void  CPile::ChangeAmountAndDetach(int) {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = CPileObserverList::Detach((CPile *)((char *)this + 88), a2);
  if ( v3 >= 0 )
  {
    if ( v3 > 0 )
    {
      if ( v3 != 1 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 941, "iDeltaAmount == 1") == 1 )
        __debugbreak();
      CPile::IncreaseEx(this, 1);
    }
  }
  else
  {
    CPile::DecreaseEx(this, -v3);
  }
}


// address=[0x155cbf0]
// Decompiled from void __thiscall CPile::AttachAndIncAmountLeaving(unsigned __int16 *this, int a2, int a3, int a4)

void  CPile::AttachAndIncAmountLeaving(int,int,enum T_OBSERVER_TARGET) {
  
  int v4; // eax

  if ( (a3 < 1 || a3 > 8)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 966, "(_iAmount >= 1) && (_iAmount <= 8)") == 1 )
  {
    __debugbreak();
  }
  if ( a4 != 2
    && a4 != 3
    && a4 != 4
    && BBSupportDbgReport(
         2,
         "MapObjects\\Pile\\Pile.cpp",
         967,
         "(_tTargetType == OBSERVER_TARGET_PILE_SRC) || (_tTargetType == OBSERVER_TARGET_PILE_SRC_2) || (_tTargetType == "
         "OBSERVER_TARGET_PILE_SRC_3)") == 1 )
  {
    __debugbreak();
  }
  v4 = IEntity::EntityId(this);
  CPileObserverList::Attach(this + 44, a4, v4, a2, -a3);
  CPile::IncAmountLeaving((CPile *)this, a3);
}


// address=[0x155cc90]
// Decompiled from void __thiscall CPile::AttachAndIncAmountComing(CPile *this, int a2)

void  CPile::AttachAndIncAmountComing(int) {
  
  int v2; // eax

  v2 = IEntity::EntityId((unsigned __int16 *)this);
  CPileObserverList::Attach((char *)this + 88, 1, v2, a2, 1);
  CPile::IncAmountComing(this);
}


// address=[0x155ccd0]
// Decompiled from void __thiscall CPile::Notify(CPile *this, const struct CEntityEvent *a2)

void  CPile::Notify(class CEntityEvent const &)const {
  
  CPileObserverList::NotifyAllObservers((CPile *)((char *)this + 88), a2);
}


// address=[0x155ccf0]
// Decompiled from int __thiscall CPile::SetObserverTarget(int this, int a2, int a3)

void  CPile::SetObserverTarget(enum T_OBSERVER_TARGET,int) {
  
  int result; // eax
  int v4; // eax
  int v5; // [esp+0h] [ebp-Ch]

  if ( a2 )
  {
    if ( BBSupportDbgReport(1, "MapObjects\\Pile\\Pile.cpp", 1027, "CPile::SetObserverTarget(): Invalid target type!") == 1 )
      __debugbreak();
    return 0;
  }
  else if ( a3 <= 0 )
  {
    *(_DWORD *)(this + 20) &= ~0x20u;
    result = *(unsigned __int16 *)(this + 82);
    if ( *(_WORD *)(this + 82) )
    {
      if ( CPile::GetRoleType((CPile *)this) == 3
        && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 1011, "GetRoleType() != IPileRole::PILE_ANYWHERE") == 1 )
      {
        __debugbreak();
      }
      CPile::NotifyTargetDieAndDetachAllObservers((CPile *)this);
      v5 = *(unsigned __int16 *)(this + 82);
      *(_WORD *)(this + 82) = 0;
      v4 = std::auto_ptr<IPileRole>::operator->();
      return (*(int (__thiscall **)(int, int, int))(*(_DWORD *)v4 + 60))(v4, this, v5);
    }
  }
  else
  {
    if ( *(_WORD *)(this + 82) && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 997, "m_uBuildingId == 0") == 1 )
      __debugbreak();
    if ( !CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a3)
      && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 998, "g_cBuildingMgr.GetBuildingPtr(_iTargetId) != 0") == 1 )
    {
      __debugbreak();
    }
    if ( CPile::GetRoleType((CPile *)this) == 3
      && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 999, "GetRoleType() != IPileRole::PILE_ANYWHERE") == 1 )
    {
      __debugbreak();
    }
    *(_WORD *)(this + 82) = a3;
    result = *(_DWORD *)(this + 20) | 0x20;
    *(_DWORD *)(this + 20) = result;
  }
  return result;
}


// address=[0x155ce70]
// Decompiled from int __thiscall CPile::GetObserverTarget(unsigned __int16 *this, int a2)

int  CPile::GetObserverTarget(enum T_OBSERVER_TARGET) {
  
  if ( a2 )
    return 0;
  else
    return this[41];
}


// address=[0x155ce90]
// Decompiled from void __thiscall CPile::RequestSpaceIfPossible(CPile *this)

void  CPile::RequestSpaceIfPossible(void) {
  
  int v1; // eax
  CEcoSector *v2; // eax
  int v3; // [esp-4h] [ebp-Ch]
  int v4; // [esp+0h] [ebp-8h]

  v3 = IEntity::Y(this);
  v1 = IEntity::X(this);
  v4 = CWorldManager::EcoSectorId(v1, v3);
  if ( v4 > 0 )
  {
    if ( (unsigned __int8)CPile::GoodAvailable(this) )
    {
      v2 = (CEcoSector *)CEcoSectorMgr::operator[](v4);
      CEcoSector::RequestSpace(v2, this);
    }
  }
}


// address=[0x155d7c0]
// Decompiled from char *__thiscall CPile::CPile(char *this, int a2)

 CPile::CPile(std::istream &) {
  
  int PileRole; // [esp+4h] [ebp-24h]
  int v4; // [esp+Ch] [ebp-1Ch] BYREF
  char v5[4]; // [esp+10h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+14h] [ebp-14h] BYREF
  char *v7; // [esp+18h] [ebp-10h]
  int v8; // [esp+24h] [ebp-4h]

  v7 = this;
  IAnimatedEntity::IAnimatedEntity(a2);
  v8 = 0;
  *(_DWORD *)v7 = &CPile::_vftable_;
  std::auto_ptr<IPileRole>::auto_ptr<IPileRole>(0);
  LOBYTE(v8) = 1;
  CPileObserverList::CPileObserverList(a2);
  operator^<unsigned int>(a2, &v4);
  if ( v4 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CPile");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, v7 + 68);
  operator^<unsigned char>(a2, v7 + 69);
  operator^<unsigned char>(a2, v7 + 70);
  operator^<unsigned char>(a2, v7 + 71);
  operator^<unsigned char>(a2, v7 + 72);
  operator^<unsigned char>(a2, v7 + 73);
  operator^<unsigned char>(a2, v7 + 74);
  operator^<short>(a2, v7 + 76);
  operator^<short>(a2, v7 + 78);
  operator^<unsigned short>(a2, v7 + 82);
  operator^<bool>(a2, v7 + 80);
  PileRole = CPileMgr::LoadPileRole(a2, (unsigned __int8)v7[72]);
  std::auto_ptr<IPileRole>::auto_ptr<IPileRole>(PileRole);
  std::auto_ptr<IPileRole>::operator=(v5);
  std::auto_ptr<IPileRole>::~auto_ptr<IPileRole>(v5);
  v8 = -1;
  return v7;
}


// address=[0x155d9a0]
// Decompiled from int __thiscall CPile::Store(__int16 *this, struct std::ostream *a2)

void  CPile::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-Ch] BYREF
  int v4; // [esp+4h] [ebp-8h]
  __int16 *v5; // [esp+8h] [ebp-4h]

  v5 = this;
  IAnimatedEntity::Store(a2);
  CPileObserverList::Store(a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<unsigned char>(a2, (int)(v5 + 34));
  operator^<unsigned char>(a2, (int)v5 + 69);
  operator^<unsigned char>(a2, (int)(v5 + 35));
  operator^<unsigned char>(a2, (int)v5 + 71);
  operator^<unsigned char>(a2, (int)(v5 + 36));
  operator^<unsigned char>(a2, (int)v5 + 73);
  operator^<unsigned char>(a2, (int)(v5 + 37));
  operator^<short>((int)a2, v5 + 38);
  operator^<short>((int)a2, v5 + 39);
  operator^<unsigned short>((int)a2, v5 + 41);
  operator^<bool>((int)a2, (int)(v5 + 40));
  v4 = std::auto_ptr<IPileRole>::operator->();
  return (*(int (__thiscall **)(int, struct std::ostream *))(*(_DWORD *)v4 + 4))(v4, a2);
}


// address=[0x155e770]
// Decompiled from int __thiscall CPile::Amount(CPile *this)

int  CPile::Amount(void)const {
  
  return *((unsigned __int8 *)this + 69);
}


// address=[0x155e790]
// Decompiled from int __thiscall CPile::ClassID(CPile *this)

unsigned long  CPile::ClassID(void)const {
  
  return CPile::m_iClassID;
}


// address=[0x155e7d0]
// Decompiled from int __thiscall CPile::GetGoodType(CPile *this)

int  CPile::GetGoodType(void)const {
  
  return *((unsigned __int8 *)this + 68);
}


// address=[0x15604c0]
// Decompiled from int __thiscall CPile::ReassessDistance(CPile *this, int *a2)

void  CPile::ReassessDistance(int &) {
  
  int v2; // eax

  v2 = std::auto_ptr<IPileRole>::operator->();
  return (*(int (__thiscall **)(int, CPile *, int *))(*(_DWORD *)v2 + 44))(v2, this, a2);
}


// address=[0x15615b0]
// Decompiled from int __thiscall CPile::BuildingId(CPile *this)

int  CPile::BuildingId(void)const {
  
  return *((unsigned __int16 *)this + 41);
}


// address=[0x3d8bbc0]
// [Decompilation failed for static unsigned long CPile::m_iClassID]

// address=[0x155cef0]
// Decompiled from int __thiscall CPile::IncreaseEx(CPile *this, int a2)

void  CPile::IncreaseEx(int) {
  
  int result; // eax
  int v3; // eax
  int v4; // [esp+4h] [ebp-Ch]
  int v5; // [esp+8h] [ebp-8h]

  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 375, "(_iAmount >= 1) && (_iAmount <= MAX_PILE_AMOUNT)") == 1 )
  {
    __debugbreak();
  }
  v5 = 8 - *((unsigned __int8 *)this + 69);
  v4 = *((unsigned __int8 *)this + 71);
  if ( v5 < 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 380, "iFreeSpace >= 0") == 1 )
    __debugbreak();
  if ( v4 > v5 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 381, "iAmountComing <= iFreeSpace") == 1 )
    __debugbreak();
  if ( v5 < 0 )
  {
    v5 = 0;
    *((_BYTE *)this + 69) = 8;
  }
  if ( a2 > v5 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 390, "_iAmount <= iFreeSpace") == 1 )
    __debugbreak();
  if ( a2 > v4 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 391, "_iAmount <= iAmountComing") == 1 )
    __debugbreak();
  if ( a2 > v5 )
    a2 = v5;
  if ( a2 > v4 )
    a2 = v4;
  if ( a2 < 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 403, "_iAmount >= 0") == 1 )
    __debugbreak();
  if ( a2 > v5 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 404, "_iAmount <= iFreeSpace") == 1 )
    __debugbreak();
  result = a2;
  if ( a2 > v4 )
  {
    result = BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 405, "_iAmount <= iAmountComing");
    if ( result == 1 )
      __debugbreak();
  }
  if ( a2 <= 0 )
    return result;
  *((_BYTE *)this + 69) += a2;
  *((_BYTE *)this + 71) -= a2;
  CPile::AdjustStatistic(this, a2, 0);
  v3 = std::auto_ptr<IPileRole>::operator->();
  (*(void (__thiscall **)(int, CPile *, int))(*(_DWORD *)v3 + 8))(v3, this, a2);
  if ( *((unsigned __int8 *)this + 69) > 8u
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 419, "m_uAmount <= MAX_PILE_AMOUNT") == 1 )
  {
    __debugbreak();
  }
  if ( *((unsigned __int8 *)this + 71) > 8u
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 420, "m_uAmountComing <= MAX_PILE_AMOUNT") == 1 )
  {
    __debugbreak();
  }
  result = *((unsigned __int8 *)this + 71);
  if ( result + *((unsigned __int8 *)this + 69) <= 8 )
    return result;
  result = BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 421, "m_uAmount + m_uAmountComing <= MAX_PILE_AMOUNT");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x155d180]
// Decompiled from int __thiscall CPile::DecreaseEx(CPile *this, int a2)

void  CPile::DecreaseEx(int) {
  
  int v2; // eax
  int result; // eax
  int v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-8h]

  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 432, "(_iAmount >= 1) && (_iAmount <= MAX_PILE_AMOUNT)") == 1 )
  {
    __debugbreak();
  }
  v6 = *((unsigned __int8 *)this + 69);
  v5 = *((unsigned __int8 *)this + 70);
  if ( v5 > v6 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 437, "iAmountLeaving <= iCurrentAmount") == 1 )
    __debugbreak();
  if ( a2 > v6 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 439, "_iAmount <= iCurrentAmount") == 1 )
    __debugbreak();
  if ( a2 > v5 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 440, "_iAmount <= iAmountLeaving") == 1 )
    __debugbreak();
  if ( v5 > v6 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 442, "iAmountLeaving <= iCurrentAmount") == 1 )
    __debugbreak();
  if ( a2 > v6 )
    a2 = v6;
  if ( a2 > v5 )
    a2 = v5;
  *((_BYTE *)this + 69) -= a2;
  *((_BYTE *)this + 70) -= a2;
  CPile::AdjustStatistic(this, -a2, 0);
  v4 = std::auto_ptr<IPileRole>::operator->();
  (*(void (__thiscall **)(int, CPile *, int))(*(_DWORD *)v4 + 12))(v4, this, 1);
  if ( !*((_BYTE *)this + 69) )
  {
    *((_BYTE *)this + 70) = 0;
    v2 = std::auto_ptr<IPileRole>::operator->();
    (*(void (__thiscall **)(int, CPile *))(*(_DWORD *)v2 + 16))(v2, this);
  }
  if ( *((unsigned __int8 *)this + 69) > 8u
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 470, "m_uAmount <= MAX_PILE_AMOUNT") == 1 )
  {
    __debugbreak();
  }
  result = *((unsigned __int8 *)this + 69);
  if ( *((unsigned __int8 *)this + 70) <= result )
    return result;
  result = BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 471, "m_uAmountLeaving <= m_uAmount");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x155d370]
// Decompiled from int __thiscall CPile::Increase(CPile *this, int a2)

int  CPile::Increase(int) {
  
  if ( BBSupportDbgReport(1, "MapObjects\\Pile\\Pile.cpp", 647, "CPile::Increase() called!") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x155d3a0]
// Decompiled from int __thiscall CPile::Decrease(CPile *this, int a2)

void  CPile::Decrease(int) {
  
  if ( BBSupportDbgReport(1, "MapObjects\\Pile\\Pile.cpp", 659, "CPile::Decrease() called!") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x155d3d0]
// Decompiled from CPile *__thiscall CPile::IncAmountLeaving(CPile *this, int a2)

void  CPile::IncAmountLeaving(int) {
  
  CPile *result; // eax
  int v3; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]

  if ( a2 <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 670, "_iAmount > 0") == 1 )
    __debugbreak();
  result = this;
  if ( *((unsigned __int8 *)this + 70) >= (int)*((unsigned __int8 *)this + 69) )
  {
    result = (CPile *)BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 671, "m_uAmountLeaving < m_uAmount");
    if ( result == (CPile *)1 )
      __debugbreak();
  }
  for ( i = 0; i < a2; ++i )
  {
    ++*((_BYTE *)this + 70);
    v3 = std::auto_ptr<IPileRole>::operator->();
    (*(void (__thiscall **)(int, CPile *))(*(_DWORD *)v3 + 20))(v3, this);
    result = (CPile *)(i + 1);
  }
  return result;
}


// address=[0x155d480]
// Decompiled from int __thiscall CPile::DecAmountLeaving(CPile *this, int a2)

void  CPile::DecAmountLeaving(int) {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-10h]
  int i; // [esp+4h] [ebp-Ch]
  int v5; // [esp+8h] [ebp-8h]

  if ( a2 < 1 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 690, "_iAmount >= 1") == 1 )
    __debugbreak();
  v5 = *((unsigned __int8 *)this + 70);
  result = v5;
  if ( v5 < a2 )
  {
    result = BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 694, "iAmountLeaving >= _iAmount");
    if ( result == 1 )
      __debugbreak();
  }
  if ( a2 > v5 )
  {
    result = v5;
    a2 = v5;
  }
  for ( i = 0; i < a2; ++i )
  {
    --*((_BYTE *)this + 70);
    v3 = std::auto_ptr<IPileRole>::operator->();
    result = (*(int (__thiscall **)(int, CPile *))(*(_DWORD *)v3 + 24))(v3, this);
  }
  return result;
}


// address=[0x155d540]
// Decompiled from int __thiscall CPile::IncAmountComing(CPile *this)

void  CPile::IncAmountComing(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  if ( *((unsigned __int8 *)this + 71) + *((unsigned __int8 *)this + 69) >= 8
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 716, "(m_uAmount + m_uAmountComing) < MAX_PILE_AMOUNT") == 1 )
  {
    __debugbreak();
  }
  ++*((_BYTE *)this + 71);
  v2 = std::auto_ptr<IPileRole>::operator->();
  return (*(int (__thiscall **)(int, CPile *))(*(_DWORD *)v2 + 28))(v2, this);
}


// address=[0x155d5b0]
// Decompiled from int __thiscall CPile::DecAmountComing(CPile *this)

void  CPile::DecAmountComing(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  if ( !*((_BYTE *)this + 71)
    && BBSupportDbgReportF(2, "MapObjects\\Pile\\Pile.cpp", 733, "AmountComing=0 ! %u", *((unsigned __int16 *)this + 4)) == 1 )
  {
    __debugbreak();
  }
  --*((_BYTE *)this + 71);
  v2 = std::auto_ptr<IPileRole>::operator->();
  return (*(int (__thiscall **)(int, CPile *))(*(_DWORD *)v2 + 32))(v2, this);
}


// address=[0x155d620]
// Decompiled from void __thiscall CPile::AdjustStatistic(CPile *this, int a2, int a3)

void  CPile::AdjustStatistic(int,int) {
  
  int v3; // eax
  CEcoSector *v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+4h] [ebp-8h]

  if ( (a2 < -8 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Pile\\Pile.cpp",
         1132,
         "(_iDeltaAmount >= -MAX_PILE_AMOUNT) && (_iDeltaAmount <= MAX_PILE_AMOUNT)") == 1 )
  {
    __debugbreak();
  }
  if ( a2 )
  {
    if ( a3 <= 0 )
    {
      v3 = IEntity::WorldIdx();
      a3 = ITiling::EcoSectorId(v3);
    }
    if ( a3 > 0 )
    {
      v4 = (CEcoSector *)CEcoSectorMgr::operator[](a3);
      CEcoSector::ChangeNumberOfGoodsPile(v4, *((unsigned __int8 *)this + 68), a2);
      v5 = CEcoSector::Owner(v4);
      if ( v5 <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 1155, "iOwnerId > 0") == 1 )
        __debugbreak();
      if ( a2 <= 0 )
        CStatistic::DecGood((CStatistic *)&g_cStatistic, v5, *((unsigned __int8 *)this + 68), -a2);
      else
        CStatistic::AddGood((CStatistic *)&g_cStatistic, v5, *((unsigned __int8 *)this + 68), a2);
    }
  }
}


// address=[0x155d720]
// Decompiled from char __thiscall CPile::ExecuteChangeGoodTypeUnforseen(CPile *this, int a2)

bool  CPile::ExecuteChangeGoodTypeUnforseen(int) {
  
  int v3; // [esp+0h] [ebp-8h]

  if ( a2 <= 0 || a2 >= 43 )
    return 0;
  if ( (*(int (__thiscall **)(CPile *))(*(_DWORD *)this + 60))(this) == a2 )
    return 0;
  CPile::NotifyTargetDieAndDetachAllObservers(this);
  v3 = *((unsigned __int8 *)this + 69);
  CPile::CancelCompleteOfferIfInOfferList(this, 0);
  CPile::AdjustStatistic(this, -v3, 0);
  CPile::SetGoodType(this, a2);
  CPile::AdjustStatistic(this, v3, 0);
  if ( CPile::GetOfferFlag(this) )
    CPile::OfferCompletePileIfPossible(this, 0);
  return 1;
}


// address=[0x155dae0]
// Decompiled from int __thiscall CPile::CPile(
        int this,
        int a2,
        int a3,
        unsigned int a4,
        int a5,
        char a6,
        int a7,
        char a8,
        char a9,
        __int16 a10,
        __int16 a11)

 CPile::CPile(int,int,int,int,class std::auto_ptr<class IPileRole>,int,int,int,int,int) {
  
  int v11; // eax
  int v13; // [esp-4h] [ebp-20h]
  int v14; // [esp+4h] [ebp-18h]
  int v15; // [esp+8h] [ebp-14h]

  IAnimatedEntity::IAnimatedEntity((IAnimatedEntity *)this, a7);
  *(_DWORD *)this = &CPile::_vftable_;
  std::auto_ptr<IPileRole>::auto_ptr<IPileRole>(&a6);
  CPileObserverList::CPileObserverList((CPileObserverList *)(this + 88));
  if ( CWorldManager::FlagBits(a2, a3, 1u)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 81, "g_cWorld.FlagBits(_iX, _iY, FLAG_BLOCKED_LAND) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( a4 >= 0x2B
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 82, "static_cast<unsigned int>(_iGood) < GOOD_MAX") == 1 )
  {
    __debugbreak();
  }
  *(_BYTE *)(this + 10) = 16;
  *(_BYTE *)(this + 68) = a4;
  *(_BYTE *)(this + 69) = a5;
  *(_BYTE *)(this + 70) = 0;
  *(_BYTE *)(this + 71) = 0;
  *(_BYTE *)(this + 72) = 0;
  *(_BYTE *)(this + 73) = a9;
  *(_BYTE *)(this + 74) = a8;
  *(_WORD *)(this + 76) = a10;
  *(_WORD *)(this + 78) = a11;
  *(_WORD *)(this + 82) = 0;
  IEntity::SetFlagBits((_DWORD *)this, (EntityFlag)0x1100u);
  IEntity::ClearFlagBits((_DWORD *)this, Registered);
  v15 = CWorldManager::Index(a2, a3);
  IEntity::SetPosition((IEntity *)this, a2, a3);
  v13 = a7;
  v11 = IEntity::WorldIdx();
  CWorldManager::SetPileId(v11, v13);
  CWorldManager::SetMoveCostsBits(v15, 7);
  CWorldManager::SetFlagBits(v15, 2u);
  CPile::AdjustStatistic((CPile *)this, a5, 0);
  v14 = std::auto_ptr<IPileRole>::operator->();
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v14 + 36))(v14, this);
  std::auto_ptr<IPileRole>::~auto_ptr<IPileRole>(&a6);
  return this;
}


// address=[0x155dcc0]
// Decompiled from void __thiscall CPile::~CPile(CPile *this)

 CPile::~CPile(void) {
  
  *(_DWORD *)this = &CPile::_vftable_;
  std::auto_ptr<IPileRole>::~auto_ptr<IPileRole>((char *)this + 84);
  IAnimatedEntity::~IAnimatedEntity(this);
}


// address=[0x155dcf0]
// Decompiled from _DWORD *__thiscall CPile::ConvertEventIntoGoal(CPile *this, struct CEntityEvent *a2)

void  CPile::ConvertEventIntoGoal(class CEntityEvent *) {
  
  int v2; // eax
  int v3; // eax
  int v5; // [esp+4h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-8h]

  v6 = *((_DWORD *)a2 + 1);
  switch ( v6 )
  {
    case 7:
      v5 = std::auto_ptr<IPileRole>::operator->();
      (*(void (__thiscall **)(int, CPile *))(*(_DWORD *)v5 + 64))(v5, this);
      break;
    case 8:
      v2 = std::auto_ptr<IPileRole>::operator->();
      (*(void (__thiscall **)(int, CPile *))(*(_DWORD *)v2 + 68))(v2, this);
      break;
    case 9:
      v3 = IEntity::EntityId((unsigned __int16 *)this);
      CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, v3, 0, 0);
      CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, *((_DWORD *)a2 + 3), 0, 0);
      if ( BBSupportDbgReport(
             1,
             "MapObjects\\Pile\\Pile.cpp",
             894,
             "CPile::ConvertEventIntoGoal(): Illegal event TARGET_DIE!") == 1 )
        __debugbreak();
      break;
  }
  return IEntity::SetFlagBits(this, (EntityFlag)0x80000000);
}


