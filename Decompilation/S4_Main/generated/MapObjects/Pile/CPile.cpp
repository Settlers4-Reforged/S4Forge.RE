#include "CPile.h"

// Definitions for class CPile

// address=[0x12fd290]
// Decompiled from bool __thiscall CPile::GoodAvailable(CPile *this)
bool  CPile::GoodAvailable(void)const {
  
  return this->m_uAmount > (int)this->m_uAmountLeaving;
}


// address=[0x1401580]
// Decompiled from CPile *__cdecl CPile::New(struct std::istream *a1)
class CPersistence * __cdecl CPile::New(std::istream & a1) {
  
  CPile *v3; // [esp+Ch] [ebp-10h]

  v3 = (CPile *)CPile::operator new(0x7Cu);
  if ( v3 )
    return CPile::CPile(v3, a1);
  else
    return 0;
}


// address=[0x1439a40]
// Decompiled from int __thiscall CPile::AmountComing(CPile *this)
int  CPile::AmountComing(void)const {
  
  return this->m_uAmountComing;
}


// address=[0x1470870]
// Decompiled from int __thiscall CPile::AmountLeaving(CPile *this)
int  CPile::AmountLeaving(void)const {
  
  return this->m_uAmountLeaving;
}


// address=[0x14708e0]
// Decompiled from bool __thiscall CPile::ChangeGoodTypeUnforseen(CPile *this, int a2)
bool  CPile::ChangeGoodTypeUnforseen(int a2) {
  
  struct IPileRole *v2; // eax

  v2 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
  return v2->ChangeGoodTypeUnforseen(v2, this, a2);
}


// address=[0x14e8150]
// Decompiled from bool __thiscall CPile::IsPatchPile(CPile *this)
bool  CPile::IsPatchPile(void)const {
  
  return this->byte49 == 1;
}


// address=[0x14e8190]
// Decompiled from int __thiscall CPile::NumberOfAvailableGoods(CPile *this)
int  CPile::NumberOfAvailableGoods(void)const {
  
  if ( this->m_uAmount < (int)this->m_uAmountLeaving
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\mapobjects\\pile\\Pile.h",
         288,
         "m_uAmount >= m_uAmountLeaving") == 1 )
  {
    __debugbreak();
  }
  return this->m_uAmount - this->m_uAmountLeaving;
}


// address=[0x151fa90]
// Decompiled from int __thiscall CPile::GetRoleType(CPile *this)
int  CPile::GetRoleType(void)const {
  
  return this->m_uPileRole;
}


// address=[0x151fab0]
// Decompiled from int __thiscall CPile::Role(CPile *this)
class IPileRole &  CPile::Role(void) {
  
  return std::auto_ptr<IPileRole>::operator*(this);
}


// address=[0x151fad0]
// Decompiled from void __thiscall CPile::SetGoodType(CPile *this, char a2)
void  CPile::SetGoodType(int a2) {
  
  this->m_uGood = a2;
}


// address=[0x152f210]
// Decompiled from bool __thiscall CPile::HasSpace(CPile *this)
bool  CPile::HasSpace(void)const {
  
  return this->m_uAmountComing + this->m_uAmount < 8;
}


// address=[0x155b300]
// Decompiled from void __thiscall CPile::OfferCompletePileIfPossible(CPile *this, _DWORD *a2)
void  CPile::OfferCompletePileIfPossible(int a2) {
  
  CPile::Offer(this, -1, a2);
}


// address=[0x155b340]
// Decompiled from void __thiscall CPile::SetOfferFlag(CPile *this, BYTE a2)
void  CPile::SetOfferFlag(bool a2) {
  
  this->m_bOfferFlag = a2;
}


// address=[0x155b360]
// Decompiled from void __thiscall CPile::SetRoleType(CPile *this, unsigned __int8 a2)
void  CPile::SetRoleType(int a2) {
  
  this->m_uPileRole = a2;
}


// address=[0x155b7d0]
// Decompiled from int __thiscall CPile::GetBuildingId(CPile *this)
int  CPile::GetBuildingId(void)const {
  
  if ( this->m_uPileRole == 3
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\mapobjects\\pile\\Pile.h",
         280,
         "m_uPileRole != IPileRole::PILE_ANYWHERE") == 1 )
  {
    __debugbreak();
  }
  return this->m_uBuildingId;
}


// address=[0x155b820]
// Decompiled from BYTE __thiscall CPile::GetOfferFlag(CPile *this)
bool  CPile::GetOfferFlag(void)const {
  
  return this->m_bOfferFlag;
}


// address=[0x155b840]
// Decompiled from bool __thiscall CPile::IsInOfferList(IEntity *this)
bool  CPile::IsInOfferList(void)const {
  
  return IEntity::FlagBits(this, ENTITY_FLAG_Offered) != 0;
}


// address=[0x155bda0]
// Decompiled from void __thiscall CPile::Delete(CPile *this)
void  CPile::Delete(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  unsigned int LastLogicUpdateTick; // eax
  int v6; // eax
  int v7; // eax
  int m_nEntityId; // [esp-4h] [ebp-38h]
  const char *spGoodName; // [esp-4h] [ebp-38h]
  CEntityEvent v10; // [esp+4h] [ebp-30h] BYREF
  const struct CEntityEvent *v11; // [esp+1Ch] [ebp-18h]
  const struct CEntityEvent *v12; // [esp+20h] [ebp-14h]
  int v14; // [esp+30h] [ebp-4h]

  v1 = IEntity::WorldIdx(this);
  CWorldManager::SetPileId(v1, 0);
  v2 = IEntity::WorldIdx(this);
  CWorldManager::SetMoveCostsBits(v2, 2);
  v3 = IEntity::WorldIdx(this);
  CWorldManager::ClearFlagBits(v3, 2);
  v4 = IEntity::EntityId(this);
  v12 = CEntityEvent::CEntityEvent(&v10, 9u, 0, v4, 0, 0);
  v11 = v12;
  v14 = 0;
  CPileObserverList::NotifyAndDetachAllObservers((CPileObserverList *)&this->m_cPileObserverList, v12);
  v14 = -1;
  CEntityEvent::~CEntityEvent(&v10);
  m_nEntityId = this->m_nEntityId;
  LastLogicUpdateTick = IAnimatedEntity::GetLastLogicUpdateTick(this);
  CMapObjectMgr::UnRegisterFromLogicUpdate(g_pMapObjectMgr, LastLogicUpdateTick, m_nEntityId);
  v6 = IEntity::ID(this);
  CPileMgr::CheckOutPile((CPileMgr *)&g_cPileMgr, v6);
  if ( debug )
  {
    if ( DEBUG_FLAGS[dword_4152058] )
    {
      spGoodName = s_sGoodTypeMap[(unsigned __int8)this->m_uGood].m_sName;
      v7 = IEntity::ID(this);
      BBSupportTracePrintF(0, "Pile %u deleted goodType %s", v7, spGoodName);
    }
  }
}


// address=[0x155bed0]
// Decompiled from void __thiscall CPile::LogicUpdate(CPile *this)
void  CPile::LogicUpdate(void) {
  
  struct IPileRole *v1; // eax

  if ( !IAnimatedEntity::ProcessAllEvents(this) )
  {
    v1 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
    v1->LogicUpdate(v1, this);
  }
}


// address=[0x155bf10]
// Decompiled from struct SGfxObjectInfo *__thiscall CPile::GetGfxInfos(CPile *this)
struct SGfxObjectInfo *  CPile::GetGfxInfos(void) {
  
  memset(&IEntity::m_sGfxInfo, 0, sizeof(IEntity::m_sGfxInfo));
  if ( !this->m_uGood || (unsigned __int8)this->m_uGood >= (unsigned int)GOOD_MAX || !this->m_uAmount )
    return &IEntity::m_sGfxInfo;
  CGfxManager::GetPileGfxInfo(
    (int)&IEntity::m_sGfxInfo,
    (unsigned __int8)this->m_uGood,
    this->m_uAmount,
    (unsigned __int8)this->byte4A);
  IEntity::m_sGfxInfo.m_uObjType = this->m_uObjType;
  IEntity::m_sGfxInfo.m_bIsVisible = IEntity::IsVisible(this);
  return &IEntity::m_sGfxInfo;
}


// address=[0x155bfa0]
// Decompiled from void __thiscall CPile::GetPatchGfx(CPile *this, struct SGfxPatchObject *_pGfxPatchObject)
void  CPile::GetPatchGfx(struct SGfxPatchObject & _pGfxPatchObject) {
  
  if ( this->m_uGood && (unsigned __int8)this->m_uGood < 0x2Bu && this->m_uAmount )
  {
    CGfxManager::GetPatchPileGfxInfo(
      g_pGfxManager,
      _pGfxPatchObject,
      (unsigned __int8)this->m_uGood,
      this->m_uAmount,
      (unsigned __int8)this->byte4A);
  }
  else
  {
    _pGfxPatchObject->m_pGfxData = 0;
    _pGfxPatchObject->m_pPalData = 0;
  }
  _pGfxPatchObject->m_iOffsetX = (__int16)this->m_iOffsetX;
  _pGfxPatchObject->m_iOffsetY = (__int16)this->m_iOffsetY;
}


// address=[0x155c030]
// Decompiled from int __thiscall CPile::ChangeRole(CPile *this, int _iRoleType)
void  CPile::ChangeRole(int _iRoleType) {
  
  int v2; // eax
  CProductionPileRole *PileRole; // [esp+4h] [ebp-20h]
  _BYTE v5[4]; // [esp+8h] [ebp-1Ch] BYREF
  struct IPileRole *v6; // [esp+Ch] [ebp-18h]
  CBuilding *v7; // [esp+10h] [ebp-14h]
  int v9; // [esp+20h] [ebp-4h]

  if ( _iRoleType != 3
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 319, "_iRoleType == IPileRole::PILE_ANYWHERE") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uBuildingId )
  {
    v7 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_uBuildingId);
    v2 = IEntity::ID(this);
    v7->Detach(v2);
  }
  PileRole = CPileMgr::CreatePileRole(_iRoleType);
  std::auto_ptr<IPileRole>::auto_ptr<IPileRole>(PileRole);
  v9 = 0;
  std::auto_ptr<IPileRole>::operator=(v5);
  v6 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
  v6->Init(v6, this);
  v9 = -1;
  return std::auto_ptr<IPileRole>::~auto_ptr<IPileRole>(v5);
}


// address=[0x155c130]
// Decompiled from int __thiscall CPile::IncreaseUnforeseen(CPile *this, int _iAmount)
int  CPile::IncreaseUnforeseen(int _iAmount) {
  
  struct IPileRole *v3; // eax
  int iAvailableSpace; // [esp+4h] [ebp-8h]

  if ( (unsigned int)_iAmount > 8
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 486, "(_iAmount >= 0) && (_iAmount <= MAX_PILE_AMOUNT)") == 1 )
  {
    __debugbreak();
  }
  if ( _iAmount <= 0 )
    return 0;
  iAvailableSpace = 8 - this->m_uAmount - this->m_uAmountComing;
  if ( iAvailableSpace < 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 495, "iAvailableSpace >= 0") == 1 )
    __debugbreak();
  if ( _iAmount > iAvailableSpace
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 496, "_iAmount <= iAvailableSpace") == 1 )
  {
    __debugbreak();
  }
  if ( iAvailableSpace <= 0 )
    return 0;
  if ( _iAmount > iAvailableSpace )
    _iAmount = iAvailableSpace;
  this->m_uAmount += _iAmount;
  CPile::AdjustStatistic(this, _iAmount, 0);
  v3 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
  v3->Increase(v3, this, _iAmount);
  if ( this->m_uAmount > 8u
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 514, "m_uAmount <= MAX_PILE_AMOUNT") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uAmountComing + this->m_uAmount > 8
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 515, "m_uAmount + m_uAmountComing <= MAX_PILE_AMOUNT") == 1 )
  {
    __debugbreak();
  }
  return _iAmount;
}


// address=[0x155c2a0]
// Decompiled from void __thiscall CPile::DecreaseUnforeseen(CPile *this, int _iAmount)
void  CPile::DecreaseUnforeseen(int _iAmount) {
  
  struct IPileRole *v2; // [esp+0h] [ebp-10h]
  struct IPileRole *v3; // [esp+4h] [ebp-Ch]
  int iAvailableGoods; // [esp+8h] [ebp-8h]

  if ( (unsigned int)_iAmount > 8
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 527, "(_iAmount >= 0) && (_iAmount <= MAX_PILE_AMOUNT)") == 1 )
  {
    __debugbreak();
  }
  if ( _iAmount > 0 )
  {
    iAvailableGoods = this->m_uAmount - this->m_uAmountLeaving;
    if ( iAvailableGoods < 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 536, "iAvailableGoods >= 0") == 1 )
      __debugbreak();
    if ( _iAmount > iAvailableGoods
      && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 537, "_iAmount <= iAvailableGoods") == 1 )
    {
      __debugbreak();
    }
    if ( iAvailableGoods > 0 )
    {
      if ( _iAmount > iAvailableGoods )
        _iAmount = iAvailableGoods;
      this->m_uAmount -= _iAmount;
      CPile::AdjustStatistic(this, -_iAmount, 0);
      v3 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
      v3->Decrease(v3, this, 1);
      if ( this->m_uAmount > 8u
        && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 555, "m_uAmount <= MAX_PILE_AMOUNT") == 1 )
      {
        __debugbreak();
      }
      if ( this->m_uAmountLeaving > (int)this->m_uAmount
        && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 556, "m_uAmountLeaving <= m_uAmount") == 1 )
      {
        __debugbreak();
      }
      if ( !this->m_uAmount )
      {
        this->m_uAmountLeaving = 0;
        v2 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
        v2->Empty(v2, this);
      }
    }
  }
}


// address=[0x155c430]
// Decompiled from bool __thiscall CPile::ForceAmountLeaving(CPile *this, int a2, int a3)
bool  CPile::ForceAmountLeaving(int a2, int a3) {
  
  int v3; // eax
  int v6; // [esp-Ch] [ebp-28h]
  int v7; // [esp-8h] [ebp-24h]
  int v8; // [esp-4h] [ebp-20h]
  CPileObserverList *pObservers; // [esp+8h] [ebp-14h]
  int v10; // [esp+10h] [ebp-Ch]
  CSettler *v11; // [esp+14h] [ebp-8h]
  int v13; // [esp+28h] [ebp+Ch]

  CPile::GoodAvailable(this);                   // NOTE: this actually just returns GoodAvailable! They added a hard early CPile::GoodAvailable() at the start. The rest is most likely just debug code the compiler left in
  v13 = 0;
  while ( 1 )
  {
    while ( CPile::GoodAvailable(this) )
      --v13;                                    // Not actually a while - probably an if(!G..A..). Broken output due to hacks to show this
    v10 = CPileObserverList::NumberOfObservers((CPileObserverList *)&this->m_cPileObserverList);
    if ( !v10 )
      break;
    pObservers = CPileObserverList::Observers((CPileObserverList *)&this->m_cPileObserverList);
    if ( !pObservers && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 596, "pObservers") == 1 )
      __debugbreak();
    while ( v10 > 0 )
    {
      v11 = (CSettler *)CMapObjectMgr::EntityPtr(pObservers->m_vPileObserver[0].m_iObserverId);
      if ( IEntity::ObjType(v11) == SETTLER_OBJ && IEntity::Type(v11) != SETTLER_THIEF )
      {
        v8 = IEntity::Y(this);
        v7 = IEntity::X(this);
        v6 = IEntity::Y(v11);
        v3 = IEntity::X(v11);
        if ( Grid::Distance(v3, v6, v7, v8) >= a2 )
        {
          CSettler::SetFree(v11);
          if ( CPile::GoodAvailable(this) )
            --v13;
        }
      }
    }
  }
  return v13 == 0;
}


// address=[0x155c580]
// Decompiled from void __thiscall CPile::SetBuildingId(CPile *this, int _iBuidingId)
void  CPile::SetBuildingId(int _iBuidingId) {
  
  int v2; // eax
  CBuilding *v3; // [esp+0h] [ebp-8h]

  if ( this->m_uPileRole == 3
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 343, "m_uPileRole != IPileRole::PILE_ANYWHERE") == 1 )
  {
    __debugbreak();
  }
  if ( _iBuidingId <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 344, "_iBuidingId > 0") == 1 )
    __debugbreak();
  v3 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, _iBuidingId);
  v2 = IEntity::EntityId(this);
  v3->Attach(v3, v2);
  if ( this->m_uBuildingId != _iBuidingId
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 349, "m_uBuildingId == _iBuidingId") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x155c640]
// Decompiled from void __thiscall CPile::Occupied(CPile *this, int _iNewEcoSectorId)
void  CPile::Occupied(int _iNewEcoSectorId) {
  
  struct CEcoSector *v2; // eax
  int v3; // eax
  int v4; // eax
  char v5; // al
  struct IPileRole *v6; // [esp+8h] [ebp-8h]

  if ( _iNewEcoSectorId <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 1176, "_iNewEcoSectorId > 0") == 1 )
    __debugbreak();
  v2 = CEcoSectorMgr::operator[](g_cESMgr, _iNewEcoSectorId);
  v3 = CEcoSector::Owner(v2);
  CPlayerManager::Race(v3);
  v4 = this->GetGoodType();
  v5 = CPileMgr::ConvertGoodType((CPileMgr *)&g_cPileMgr, v4);
  CPile::SetGoodType(this, v5);
  v6 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
  v6->Occupied(v6, this);
  CPile::AdjustStatistic(this, this->m_uAmount, _iNewEcoSectorId);
}


// address=[0x155c700]
// Decompiled from char __thiscall CPile::SetFree(CPile *this, int _iOldEcoSectorId)
bool  CPile::SetFree(int _iOldEcoSectorId) {
  
  struct IPileRole *v3; // [esp+4h] [ebp-8h]

  if ( _iOldEcoSectorId <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 1199, "_iOldEcoSectorId > 0") == 1 )
    __debugbreak();
  v3 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
  v3->SetFree(v3, this, _iOldEcoSectorId);
  CPile::AdjustStatistic(this, -this->m_uAmount, _iOldEcoSectorId);
  return 0;
}


// address=[0x155c780]
// Decompiled from void __thiscall CPile::NotifyChangeEcoSector(CPile *this, int _iOldEcoSectorId, int _iNewEcoSectorId)
void  CPile::NotifyChangeEcoSector(int _iOldEcoSectorId, int _iNewEcoSectorId) {
  
  struct IPileRole *v3; // [esp+0h] [ebp-Ch]
  int m_uAmount; // [esp+4h] [ebp-8h]

  if ( _iOldEcoSectorId <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 1219, "_iOldEcoSectorId > 0") == 1 )
    __debugbreak();
  if ( _iNewEcoSectorId <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 1220, "_iNewEcoSectorId > 0") == 1 )
    __debugbreak();
  if ( _iOldEcoSectorId == _iNewEcoSectorId
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 1221, "_iOldEcoSectorId != _iNewEcoSectorId") == 1 )
  {
    __debugbreak();
  }
  m_uAmount = this->m_uAmount;
  CPile::AdjustStatistic(this, -m_uAmount, _iOldEcoSectorId);
  CPile::AdjustStatistic(this, m_uAmount, _iNewEcoSectorId);
  v3 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
  v3->NotifyChangeEcoSector(v3, this, _iOldEcoSectorId, _iNewEcoSectorId);
}


// address=[0x155c860]
// Decompiled from void __thiscall CPile::Offer(CPile *this, int a2, int _iEcoSectorId)
void  CPile::Offer(int a2, int _iEcoSectorId) {
  
  int v3; // eax
  struct CEcoSector *v4; // eax
  int v5; // [esp-8h] [ebp-Ch]
  int v6; // [esp-4h] [ebp-8h]

  if ( _iEcoSectorId < 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 762, "_iEcoSectorId >= 0") == 1 )
    __debugbreak();
  if ( !_iEcoSectorId )
  {
    v3 = IEntity::WorldIdx(this);
    _iEcoSectorId = CWorldManager::EcoSectorId(v3);
  }
  if ( _iEcoSectorId > 0 )
  {
    v6 = IEntity::EntityId(this);
    v5 = this->GetGoodType();
    v4 = CEcoSectorMgr::operator[](g_cESMgr, _iEcoSectorId);
    CEcoSector::SetGoodOffer(v4, v5, v6);
  }
}


// address=[0x155c8e0]
// Decompiled from void __thiscall CPile::CancelOffer(IEntity *this, int a2, int _iEcoSectorId)
void  CPile::CancelOffer(int a2, int _iEcoSectorId) {
  
  int v3; // eax
  CEcoSector *v4; // eax
  int v5; // [esp-8h] [ebp-Ch]
  int v6; // [esp-4h] [ebp-8h]

  if ( _iEcoSectorId < 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 792, "_iEcoSectorId >= 0") == 1 )
    __debugbreak();
  if ( !_iEcoSectorId )
  {
    v3 = IEntity::WorldIdx(this);
    _iEcoSectorId = CWorldManager::EcoSectorId(v3);
  }
  if ( _iEcoSectorId > 0 )
  {
    v6 = IEntity::EntityId(this);
    v5 = this->GetGoodType();
    v4 = CEcoSectorMgr::operator[](g_cESMgr, _iEcoSectorId);
    CEcoSector::GetPileOutOfOffer(v4, v5, v6);
  }
}


// address=[0x155c960]
// Decompiled from void __thiscall CPile::CancelCompleteOfferIfInOfferList(CPile *this, int a2)
void  CPile::CancelCompleteOfferIfInOfferList(int a2) {
  
  if ( CPile::IsInOfferList(this) )
    CPile::CancelOffer(this, -1, a2);
}


// address=[0x155c990]
// Decompiled from void __thiscall CPile::ChangeNumberOfOfferedGoodsInEcoSector(CPile *this, int a2, int a3)
void  CPile::ChangeNumberOfOfferedGoodsInEcoSector(int a2, int a3) {
  
  ;
}


// address=[0x155c9a0]
// Decompiled from int __thiscall CPile::CalcUrgent(CPile *this)
int  CPile::CalcUrgent(void)const {
  
  return 4000 * (16 - (this->m_uAmountComing + 2 * this->m_uAmount));
}


// address=[0x155c9d0]
// Decompiled from void __thiscall CPile::NotifyTargetDieAndDetachAllObservers(CPile *this)
void  CPile::NotifyTargetDieAndDetachAllObservers(void) {
  
  int v1; // eax
  CEntityEvent v2; // [esp+4h] [ebp-38h] BYREF
  const struct CEntityEvent *v3; // [esp+1Ch] [ebp-20h]
  const struct CEntityEvent *v4; // [esp+20h] [ebp-1Ch]
  struct IPileRole *v5; // [esp+24h] [ebp-18h]
  struct IPileRole *v6; // [esp+28h] [ebp-14h]
  int v8; // [esp+38h] [ebp-4h]

  v1 = IEntity::EntityId(this);
  v4 = CEntityEvent::CEntityEvent(&v2, 9u, 0, v1, 0, 0);
  v3 = v4;
  v8 = 0;
  CPileObserverList::NotifyAndDetachAllObservers((CPileObserverList *)&this->m_cPileObserverList, v4);
  v8 = -1;
  CEntityEvent::~CEntityEvent(&v2);
  if ( this->m_uAmountComing )
  {
    this->m_uAmountComing = 0;
    v6 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
    v6->DecAmountComing(v6, this);
  }
  if ( this->m_uAmountLeaving )
  {
    this->m_uAmountLeaving = 0;
    v5 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
    v5->DecAmountLeaving(v5, this);
  }
}


// address=[0x155cab0]
// Decompiled from unsigned int __cdecl CPile::operator new(unsigned int a1)
void * __cdecl CPile::operator new(unsigned int a1) {
  
  return CPileMgr::Alloc((CPileMgr *)&g_cPileMgr, a1);
}


// address=[0x155cad0]
// Decompiled from int __cdecl CPile::operator delete(_DWORD *a1)
void __cdecl CPile::operator delete(void * a1) {
  
  return CPileMgr::Dealloc((CPileMgr *)&g_cPileMgr, a1);
}


// address=[0x155cb10]
// Decompiled from void __thiscall CPile::Detach(CPile *this, int a2)
void  CPile::Detach(int a2) {
  
  int iDeltaAmount; // [esp+4h] [ebp-4h]

  iDeltaAmount = CPileObserverList::Detach((CPileObserverList *)&this->m_cPileObserverList, a2);
  if ( iDeltaAmount >= 0 )
  {
    if ( iDeltaAmount > 0 )
    {
      if ( iDeltaAmount != 1 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 919, "iDeltaAmount == 1") == 1 )
        __debugbreak();
      CPile::DecAmountComing(this);
    }
  }
  else
  {
    CPile::DecAmountLeaving(this, -iDeltaAmount);
  }
}


// address=[0x155cb80]
// Decompiled from void __thiscall CPile::ChangeAmountAndDetach(CPile *this, int a2)
void  CPile::ChangeAmountAndDetach(int a2) {
  
  int iDeltaAmount; // [esp+4h] [ebp-4h]

  iDeltaAmount = CPileObserverList::Detach((CPileObserverList *)&this->m_cPileObserverList, a2);
  if ( iDeltaAmount >= 0 )
  {
    if ( iDeltaAmount > 0 )
    {
      if ( iDeltaAmount != 1 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 941, "iDeltaAmount == 1") == 1 )
        __debugbreak();
      CPile::IncreaseEx(this, 1);
    }
  }
  else
  {
    CPile::DecreaseEx(this, -iDeltaAmount);
  }
}


// address=[0x155cbf0]
// Decompiled from void __thiscall CPile::AttachAndIncAmountLeaving(CPile *this, int a2, int _iAmount, int _tTargetType)
void  CPile::AttachAndIncAmountLeaving(int a2, int _iAmount, enum T_OBSERVER_TARGET _tTargetType) {
  
  int v4; // eax

  if ( (_iAmount < 1 || _iAmount > 8)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 966, "(_iAmount >= 1) && (_iAmount <= 8)") == 1 )
  {
    __debugbreak();
  }
  if ( _tTargetType != 2
    && _tTargetType != 3
    && _tTargetType != 4
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
  CPileObserverList::Attach((CPileObserverList *)&this->m_cPileObserverList, _tTargetType, v4, a2, -_iAmount);
  CPile::IncAmountLeaving(this, _iAmount);
}


// address=[0x155cc90]
// Decompiled from void __thiscall CPile::AttachAndIncAmountComing(CPile *this, int _iAmount)
void  CPile::AttachAndIncAmountComing(int _iAmount) {
  
  int v2; // eax

  v2 = IEntity::EntityId(this);
  CPileObserverList::Attach((CPileObserverList *)&this->m_cPileObserverList, 1, v2, _iAmount, 1);
  CPile::IncAmountComing(this);
}


// address=[0x155ccd0]
// Decompiled from int __thiscall CPile::Notify(CPile *this, const struct CEntityEvent *a2)
void  CPile::Notify(class CEntityEvent const & a2)const {
  
  return CPileObserverList::NotifyAllObservers((CPileObserverList *)&this->m_cPileObserverList, a2);
}


// address=[0x155ccf0]
// Decompiled from void __thiscall CPile::SetObserverTarget(CPile *this, int _tTargetType, int _iTargetId)
void  CPile::SetObserverTarget(enum T_OBSERVER_TARGET _tTargetType, int _iTargetId) {
  
  struct IPileRole *v3; // eax
  int m_uBuildingId; // [esp+0h] [ebp-Ch]

  if ( _tTargetType )
  {
    if ( BBSupportDbgReport(1, "MapObjects\\Pile\\Pile.cpp", 1027, "CPile::SetObserverTarget(): Invalid target type!") == 1 )
      __debugbreak();
  }
  else if ( _iTargetId <= 0 )
  {
    this->m_iFlags &= ~0x20u;
    if ( this->m_uBuildingId )
    {
      if ( CPile::GetRoleType(this) == 3
        && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 1011, "GetRoleType() != IPileRole::PILE_ANYWHERE") == 1 )
      {
        __debugbreak();
      }
      CPile::NotifyTargetDieAndDetachAllObservers(this);
      m_uBuildingId = this->m_uBuildingId;
      this->m_uBuildingId = 0;
      v3 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
      ((void (__thiscall *)(struct IPileRole *, CPile *, int))v3->j_?SubjectDie@IPileRole@@UAEXPAVCPile@@H@Z)(
        v3,
        this,
        m_uBuildingId);
    }
  }
  else
  {
    if ( this->m_uBuildingId && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 997, "m_uBuildingId == 0") == 1 )
      __debugbreak();
    if ( !CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, _iTargetId)
      && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 998, "g_cBuildingMgr.GetBuildingPtr(_iTargetId) != 0") == 1 )
    {
      __debugbreak();
    }
    if ( CPile::GetRoleType(this) == 3
      && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 999, "GetRoleType() != IPileRole::PILE_ANYWHERE") == 1 )
    {
      __debugbreak();
    }
    this->m_uBuildingId = _iTargetId;
    this->m_iFlags |= 0x20u;
  }
}


// address=[0x155ce70]
// Decompiled from int __thiscall CPile::GetObserverTarget(CPile *this, int a2)
int  CPile::GetObserverTarget(enum T_OBSERVER_TARGET a2) {
  
  if ( a2 )
    return 0;
  else
    return this->m_uBuildingId;
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
      v2 = CEcoSectorMgr::operator[](g_cESMgr, v4);
      CEcoSector::RequestSpace(v2, this);
    }
  }
}


// address=[0x155d7c0]
// Decompiled from CPile *__thiscall CPile::CPile(CPile *this, struct std::istream *_rStream)
 CPile::CPile(std::istream & _rStream) {
  
  int iPileRole; // [esp+4h] [ebp-24h]
  int fileFormatVersion; // [esp+Ch] [ebp-1Ch] BYREF
  char v5[4]; // [esp+10h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+14h] [ebp-14h] BYREF
  int exceptionBlock; // [esp+24h] [ebp-4h]

  IAnimatedEntity::IAnimatedEntity(this, _rStream);
  exceptionBlock = 0;
  this->__vftable = (IAnimatedEntity_vtbl *)&CPile::_vftable_;
  std::auto_ptr<IPileRole>::auto_ptr<IPileRole>(0);
  LOBYTE(exceptionBlock) = 1;
  CPileObserverList::CPileObserverList((CPileObserverList *)&this->m_cPileObserverList, (int)_rStream);
  operator^<unsigned int>(_rStream, &fileFormatVersion);
  if ( fileFormatVersion != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CPile");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(_rStream, &this->m_uGood);
  operator^<unsigned char>(_rStream, &this->m_uAmount);
  operator^<unsigned char>(_rStream, &this->m_uAmountLeaving);
  operator^<unsigned char>(_rStream, &this->m_uAmountComing);
  operator^<unsigned char>(_rStream, &this->m_uPileRole);
  operator^<unsigned char>(_rStream, &this->byte49);
  operator^<unsigned char>(_rStream, &this->byte4A);
  operator^<short>(_rStream, &this->m_iOffsetX);
  operator^<short>(_rStream, &this->m_iOffsetY);
  operator^<unsigned short>(_rStream, &this->m_uBuildingId);
  operator^<bool>(_rStream, &this->m_bOfferFlag);
  iPileRole = CPileMgr::LoadPileRole((int)_rStream, this->m_uPileRole);
  std::auto_ptr<IPileRole>::auto_ptr<IPileRole>(iPileRole);
  std::auto_ptr<IPileRole>::operator=(v5);
  std::auto_ptr<IPileRole>::~auto_ptr<IPileRole>(v5);
  exceptionBlock = -1;
  return this;
}


// address=[0x155d9a0]
// Decompiled from void __thiscall CPile::Store(CPile *this, struct std::ostream *_rStream)
void  CPile::Store(std::ostream & _rStream) {
  
  int v2; // [esp+0h] [ebp-Ch] BYREF
  struct IPileRole *v3; // [esp+4h] [ebp-8h]
  CPile *v4; // [esp+8h] [ebp-4h]

  v4 = this;
  IAnimatedEntity::Store(this, _rStream);
  CPileObserverList::Store((CPileObserverList *)&v4->m_cPileObserverList, _rStream);
  v2 = 1;
  operator^<unsigned int>(_rStream, &v2);
  operator^<unsigned char>(_rStream, &v4->m_uGood);
  operator^<unsigned char>(_rStream, &v4->m_uAmount);
  operator^<unsigned char>(_rStream, &v4->m_uAmountLeaving);
  operator^<unsigned char>(_rStream, &v4->m_uAmountComing);
  operator^<unsigned char>(_rStream, &v4->m_uPileRole);
  operator^<unsigned char>(_rStream, &v4->byte49);
  operator^<unsigned char>(_rStream, &v4->byte4A);
  operator^<short>(_rStream, &v4->m_iOffsetX);
  operator^<short>(_rStream, &v4->m_iOffsetY);
  operator^<unsigned short>(_rStream, &v4->m_uBuildingId);
  operator^<bool>(_rStream, &v4->m_bOfferFlag);
  v3 = std::auto_ptr<IPileRole>::operator->(v4->m_pRole);
  v3->Store(v3, _rStream);
}


// address=[0x155e770]
// Decompiled from int __thiscall CPile::Amount(CPile *this)
int  CPile::Amount(void)const {
  
  return this->m_uAmount;
}


// address=[0x155e790]
// Decompiled from int __thiscall CPile::ClassID(CPile *this)
unsigned long  CPile::ClassID(void)const {
  
  return CPile::m_iClassID;
}


// address=[0x155e7d0]
// Decompiled from int __thiscall CPile::GetGoodType(CPile *this)
int  CPile::GetGoodType(void)const {
  
  return this->m_uGood;
}


// address=[0x15604c0]
// Decompiled from void __thiscall CPile::ReassessDistance(CPile *this, int *a2)
void  CPile::ReassessDistance(int & a2) {
  
  struct IPileRole *v2; // eax

  v2 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
  v2->ReassessDistance(v2, this, a2);
}


// address=[0x15615b0]
// Decompiled from int __thiscall CPile::BuildingId(CPile *this)
int  CPile::BuildingId(void)const {
  
  return this->m_uBuildingId;
}


// address=[0x3d8bbc0]
// [Decompilation failed for static unsigned long CPile::m_iClassID]

// address=[0x155cef0]
// Decompiled from void __thiscall CPile::IncreaseEx(CPile *this, int _iAmount)
void  CPile::IncreaseEx(int _iAmount) {
  
  struct IPileRole *v2; // eax
  int iAmountComing; // [esp+4h] [ebp-Ch]
  int iFreeSpace; // [esp+8h] [ebp-8h]

  if ( (_iAmount < 1 || _iAmount > 8)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 375, "(_iAmount >= 1) && (_iAmount <= MAX_PILE_AMOUNT)") == 1 )
  {
    __debugbreak();
  }
  iFreeSpace = 8 - this->m_uAmount;
  iAmountComing = this->m_uAmountComing;
  if ( iFreeSpace < 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 380, "iFreeSpace >= 0") == 1 )
    __debugbreak();
  if ( iAmountComing > iFreeSpace
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 381, "iAmountComing <= iFreeSpace") == 1 )
  {
    __debugbreak();
  }
  if ( iFreeSpace < 0 )
  {
    iFreeSpace = 0;
    this->m_uAmount = 8;
  }
  if ( _iAmount > iFreeSpace && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 390, "_iAmount <= iFreeSpace") == 1 )
    __debugbreak();
  if ( _iAmount > iAmountComing
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 391, "_iAmount <= iAmountComing") == 1 )
  {
    __debugbreak();
  }
  if ( _iAmount > iFreeSpace )
    _iAmount = iFreeSpace;
  if ( _iAmount > iAmountComing )
    _iAmount = iAmountComing;
  if ( _iAmount < 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 403, "_iAmount >= 0") == 1 )
    __debugbreak();
  if ( _iAmount > iFreeSpace && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 404, "_iAmount <= iFreeSpace") == 1 )
    __debugbreak();
  if ( _iAmount > iAmountComing
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 405, "_iAmount <= iAmountComing") == 1 )
  {
    __debugbreak();
  }
  if ( _iAmount > 0 )
  {
    this->m_uAmount += _iAmount;
    this->m_uAmountComing -= _iAmount;
    CPile::AdjustStatistic(this, _iAmount, 0);
    v2 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
    v2->Increase(v2, this, _iAmount);
    if ( this->m_uAmount > 8u
      && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 419, "m_uAmount <= MAX_PILE_AMOUNT") == 1 )
    {
      __debugbreak();
    }
    if ( this->m_uAmountComing > 8u
      && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 420, "m_uAmountComing <= MAX_PILE_AMOUNT") == 1 )
    {
      __debugbreak();
    }
    if ( this->m_uAmountComing + this->m_uAmount > 8
      && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 421, "m_uAmount + m_uAmountComing <= MAX_PILE_AMOUNT") == 1 )
    {
      __debugbreak();
    }
  }
}


// address=[0x155d180]
// Decompiled from void __thiscall CPile::DecreaseEx(CPile *this, int _iAmount)
void  CPile::DecreaseEx(int _iAmount) {
  
  struct IPileRole *v2; // eax
  struct IPileRole *v3; // [esp+4h] [ebp-10h]
  int iAmountLeaving; // [esp+8h] [ebp-Ch]
  int iCurrentAmount; // [esp+Ch] [ebp-8h]

  if ( (_iAmount < 1 || _iAmount > 8)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 432, "(_iAmount >= 1) && (_iAmount <= MAX_PILE_AMOUNT)") == 1 )
  {
    __debugbreak();
  }
  iCurrentAmount = this->m_uAmount;
  iAmountLeaving = this->m_uAmountLeaving;
  if ( iAmountLeaving > iCurrentAmount
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 437, "iAmountLeaving <= iCurrentAmount") == 1 )
  {
    __debugbreak();
  }
  if ( _iAmount > iCurrentAmount
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 439, "_iAmount <= iCurrentAmount") == 1 )
  {
    __debugbreak();
  }
  if ( _iAmount > iAmountLeaving
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 440, "_iAmount <= iAmountLeaving") == 1 )
  {
    __debugbreak();
  }
  if ( iAmountLeaving > iCurrentAmount
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 442, "iAmountLeaving <= iCurrentAmount") == 1 )
  {
    __debugbreak();
  }
  if ( _iAmount > iCurrentAmount )
    _iAmount = iCurrentAmount;
  if ( _iAmount > iAmountLeaving )
    _iAmount = iAmountLeaving;
  this->m_uAmount -= _iAmount;
  this->m_uAmountLeaving -= _iAmount;
  CPile::AdjustStatistic(this, -_iAmount, 0);
  v3 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
  v3->Decrease(v3, this, 1);
  if ( !this->m_uAmount )
  {
    this->m_uAmountLeaving = 0;
    v2 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
    v2->Empty(v2, this);
  }
  if ( this->m_uAmount > 8u
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 470, "m_uAmount <= MAX_PILE_AMOUNT") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uAmountLeaving > (int)this->m_uAmount
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 471, "m_uAmountLeaving <= m_uAmount") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x155d370]
// Decompiled from int __thiscall CPile::Increase(CPile *this, int a2)
int  CPile::Increase(int a2) {
  
  if ( BBSupportDbgReport(1, "MapObjects\\Pile\\Pile.cpp", 647, "CPile::Increase() called!") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x155d3a0]
// Decompiled from int __thiscall CPile::Decrease(CPile *this, int a2)
void  CPile::Decrease(int a2) {
  
  if ( BBSupportDbgReport(1, "MapObjects\\Pile\\Pile.cpp", 659, "CPile::Decrease() called!") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x155d3d0]
// Decompiled from void __thiscall CPile::IncAmountLeaving(CPile *this, int _iAmount)
void  CPile::IncAmountLeaving(int _iAmount) {
  
  struct IPileRole *v2; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]

  if ( _iAmount <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 670, "_iAmount > 0") == 1 )
    __debugbreak();
  if ( this->m_uAmountLeaving >= (int)this->m_uAmount
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 671, "m_uAmountLeaving < m_uAmount") == 1 )
  {
    __debugbreak();
  }
  for ( i = 0; i < _iAmount; ++i )
  {
    ++this->m_uAmountLeaving;
    v2 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
    v2->IncAmoutLeaving(v2, this);
  }
}


// address=[0x155d480]
// Decompiled from void __thiscall CPile::DecAmountLeaving(CPile *this, int _iAmount)
void  CPile::DecAmountLeaving(int _iAmount) {
  
  struct IPileRole *v2; // [esp+0h] [ebp-10h]
  int i; // [esp+4h] [ebp-Ch]
  int iAmountLeaving; // [esp+8h] [ebp-8h]

  if ( _iAmount < 1 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 690, "_iAmount >= 1") == 1 )
    __debugbreak();
  iAmountLeaving = this->m_uAmountLeaving;
  if ( iAmountLeaving < _iAmount
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 694, "iAmountLeaving >= _iAmount") == 1 )
  {
    __debugbreak();
  }
  if ( _iAmount > iAmountLeaving )
    _iAmount = iAmountLeaving;
  for ( i = 0; i < _iAmount; ++i )
  {
    --this->m_uAmountLeaving;
    v2 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
    v2->DecAmountLeaving(v2, this);
  }
}


// address=[0x155d540]
// Decompiled from void __thiscall CPile::IncAmountComing(CPile *this)
void  CPile::IncAmountComing(void) {
  
  struct IPileRole *v1; // [esp+0h] [ebp-8h]

  if ( this->m_uAmountComing + this->m_uAmount >= 8
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 716, "(m_uAmount + m_uAmountComing) < MAX_PILE_AMOUNT") == 1 )
  {
    __debugbreak();
  }
  ++this->m_uAmountComing;
  v1 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
  v1->IncAmountComing(v1, this);
}


// address=[0x155d5b0]
// Decompiled from void __thiscall CPile::DecAmountComing(CPile *this)
void  CPile::DecAmountComing(void) {
  
  struct IPileRole *v1; // [esp+0h] [ebp-8h]

  if ( !this->m_uAmountComing
    && BBSupportDbgReportF(2, "MapObjects\\Pile\\Pile.cpp", 733, "AmountComing=0 ! %u", this->m_nEntityId) == 1 )
  {
    __debugbreak();
  }
  --this->m_uAmountComing;
  v1 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
  v1->DecAmountComing(v1, this);
}


// address=[0x155d620]
// Decompiled from void __thiscall CPile::AdjustStatistic(CPile *this, int _iDeltaAmount, int _iEcoSectorId)
void  CPile::AdjustStatistic(int _iDeltaAmount, int _iEcoSectorId) {
  
  int v3; // eax
  CEcoSector *v4; // [esp+0h] [ebp-Ch]
  int iOwnerId; // [esp+4h] [ebp-8h]

  if ( (_iDeltaAmount < -8 || _iDeltaAmount > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Pile\\Pile.cpp",
         1132,
         "(_iDeltaAmount >= -MAX_PILE_AMOUNT) && (_iDeltaAmount <= MAX_PILE_AMOUNT)") == 1 )
  {
    __debugbreak();
  }
  if ( _iDeltaAmount )
  {
    if ( _iEcoSectorId <= 0 )
    {
      v3 = IEntity::WorldIdx(this);
      _iEcoSectorId = ITiling::EcoSectorId(v3);
    }
    if ( _iEcoSectorId > 0 )
    {
      v4 = CEcoSectorMgr::operator[](g_cESMgr, _iEcoSectorId);
      CEcoSector::ChangeNumberOfGoodsPile(v4, this->m_uGood, _iDeltaAmount);
      iOwnerId = CEcoSector::Owner(v4);
      if ( iOwnerId <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 1155, "iOwnerId > 0") == 1 )
        __debugbreak();
      if ( _iDeltaAmount <= 0 )
        CStatistic::DecGood(&g_cStatistic, iOwnerId, this->m_uGood, -_iDeltaAmount);
      else
        CStatistic::AddGood(&g_cStatistic, iOwnerId, (S4_GOOD_ENUM)this->m_uGood, _iDeltaAmount);
    }
  }
}


// address=[0x155d720]
// Decompiled from bool __thiscall CPile::ExecuteChangeGoodTypeUnforseen(CPile *this, int a2)
bool  CPile::ExecuteChangeGoodTypeUnforseen(int a2) {
  
  int iCurrentAmount; // [esp+0h] [ebp-8h]

  if ( a2 <= 0 || a2 >= 43 )
    return 0;
  if ( this->GetGoodType() == a2 )
    return 0;
  CPile::NotifyTargetDieAndDetachAllObservers(this);
  iCurrentAmount = this->m_uAmount;
  CPile::CancelCompleteOfferIfInOfferList(this, 0);
  CPile::AdjustStatistic(this, -iCurrentAmount, 0);
  CPile::SetGoodType(this, a2);
  CPile::AdjustStatistic(this, iCurrentAmount, 0);
  if ( CPile::GetOfferFlag(this) )
    CPile::OfferCompletePileIfPossible(this, 0);
  return 1;
}


// address=[0x155dae0]
// Decompiled from CPile *__thiscall CPile::CPile(  CPile *this,  int _iX,  int _iY,  S4_GOOD_ENUM _iGood,  int _iAmount,  int _pRole,  int _iSlot,  char a8,  char a9,  __int16 _iOffsetX,  __int16 _iOffsetY)
 CPile::CPile(int _iX, int _iY, int _iGood, int _iAmount, class std::auto_ptr<class IPileRole> _pRole, int _iSlot, int a8, int a9, int _iOffsetX, int _iOffsetY) {
  
  int v11; // eax
  int v13; // [esp-4h] [ebp-20h]
  struct IPileRole *v14; // [esp+4h] [ebp-18h]
  int v15; // [esp+8h] [ebp-14h]

  IAnimatedEntity::IAnimatedEntity(this, _iSlot);
  this->__vftable = (IAnimatedEntity_vtbl *)&CPile::_vftable_;
  std::auto_ptr<IPileRole>::auto_ptr<IPileRole>(this->m_pRole, (int)&_pRole);
  CPileObserverList::CPileObserverList((CPileObserverList *)&this->m_cPileObserverList);
  if ( CWorldManager::FlagBits(_iX, _iY, 1u)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 81, "g_cWorld.FlagBits(_iX, _iY, FLAG_BLOCKED_LAND) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( _iGood >= (unsigned int)GOOD_MAX
    && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 82, "static_cast<unsigned int>(_iGood) < GOOD_MAX") == 1 )
  {
    __debugbreak();
  }
  this->m_uObjType = Good;
  this->m_uGood = _iGood;
  this->m_uAmount = _iAmount;
  this->m_uAmountLeaving = 0;
  this->m_uAmountComing = 0;
  this->m_uPileRole = 0;
  this->byte49 = a9;
  this->byte4A = a8;
  this->m_iOffsetX = _iOffsetX;
  this->m_iOffsetY = _iOffsetY;
  this->m_uBuildingId = 0;
  IEntity::SetFlagBits(this, (EntityFlag)4352);
  IEntity::ClearFlagBits(this, ENTITY_FLAG_Registered);
  v15 = CWorldManager::Index(_iX, _iY);
  IEntity::SetPosition(this, _iX, _iY);
  v13 = _iSlot;
  v11 = IEntity::WorldIdx(this);
  CWorldManager::SetPileId(v11, v13);
  CWorldManager::SetMoveCostsBits(v15, 7);
  CWorldManager::SetFlagBits(v15, 2u);
  CPile::AdjustStatistic(this, _iAmount, 0);
  v14 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
  v14->Init(v14, this);
  std::auto_ptr<IPileRole>::~auto_ptr<IPileRole>(&_pRole);
  return this;
}


// address=[0x155dcc0]
// Decompiled from int __thiscall CPile::~CPile(CPile *this)
 CPile::~CPile(void) {
  
  this->__vftable = (IAnimatedEntity_vtbl *)&CPile::_vftable_;
  std::auto_ptr<IPileRole>::~auto_ptr<IPileRole>(this->m_pRole);
  return IAnimatedEntity::~IAnimatedEntity(this);
}


// address=[0x155dcf0]
// Decompiled from void __thiscall CPile::ConvertEventIntoGoal(CPile *this, struct CEntityEvent *a2)
void  CPile::ConvertEventIntoGoal(class CEntityEvent * a2) {
  
  struct IPileRole *v2; // eax
  int v3; // eax
  struct IPileRole *v4; // [esp+4h] [ebp-Ch]
  int iEvent; // [esp+8h] [ebp-8h]

  iEvent = a2->m_iEvent;
  switch ( iEvent )
  {
    case 7:
      v4 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
      v4->SubjectStopped(v4, this);
      break;
    case 8:
      v2 = std::auto_ptr<IPileRole>::operator->(this->m_pRole);
      v2->SubjectStarted(v2, this);
      break;
    case 9:
      v3 = IEntity::EntityId(this);
      CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, v3, 0, 0);
      CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, a2->m_iDataA, 0, 0);
      if ( BBSupportDbgReport(
             1,
             "MapObjects\\Pile\\Pile.cpp",
             894,
             "CPile::ConvertEventIntoGoal(): Illegal event TARGET_DIE!") == 1 )
        __debugbreak();
      break;
  }
  IEntity::SetFlagBits(this, (EntityFlag)0x80000000);
}


