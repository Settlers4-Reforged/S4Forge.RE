#include "CPile.h"

#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "CPileMgr.h"
#include "Debug/DebugFlags.h"
#include "Defines/Goods.h"
#include "Defines/Object.h"
#include "Defines/Roles.h"
#include "Defines/Settlers.h"
#include "Defines/World.h"
#include "IPileRole.h"
#include "Logic/CStatistic.h"
#include "Logic/Events/CEntityEvent.h"
#include "MapObjects/CMapObjectMgr.h"
#include "MapObjects/Settler/CSettler.h"
#include "Pathing/ITiling.h"
#include "World/CWorldManager.h"
#include "World/helper.h"

#include <iostream>
#include <memory>

// Definitions for class CPile

// address=[0x4152058]
int s_iPileDebugSection = GetAvailableSection();

// address=[0x12fd290]
// Decompiled from bool __thiscall CPile::GoodAvailable(CPile *this)
bool CPile::GoodAvailable(void) const {
    return this->m_uAmount > static_cast<int>(this->m_uAmountLeaving);
}

// address=[0x1401580]
// Decompiled from CPile *__cdecl CPile::New(struct std::istream *a1)
class CPersistence *__cdecl CPile::New(std::istream &_rStream) {
    return new CPile(_rStream);
}

// address=[0x1439a40]
// Decompiled from int __thiscall CPile::AmountComing(CPile *this)
int CPile::AmountComing(void) const {
    return this->m_uAmountComing;
}

// address=[0x1470870]
// Decompiled from int __thiscall CPile::AmountLeaving(CPile *this)
int CPile::AmountLeaving(void) const {
    return this->m_uAmountLeaving;
}

// address=[0x14708e0]
// Decompiled from bool __thiscall CPile::ChangeGoodTypeUnforseen(CPile *this, int a2)
bool CPile::ChangeGoodTypeUnforseen(int a2) {
    return this->m_pRole->ChangeGoodTypeUnforseen(this, a2);
}

// address=[0x14e8150]
// Decompiled from bool __thiscall CPile::IsPatchPile(CPile *this)
bool CPile::IsPatchPile(void) const {
    return this->m_bIsPatchPile == 1;
}

// address=[0x14e8190]
// Decompiled from int __thiscall CPile::NumberOfAvailableGoods(CPile *this)
int CPile::NumberOfAvailableGoods(void) const {
    BB_ASSERT(m_uAmount >= m_uAmountLeaving)
    return this->m_uAmount - this->m_uAmountLeaving;
}

// address=[0x151fa90]
// Decompiled from int __thiscall CPile::GetRoleType(CPile *this)
int CPile::GetRoleType(void) const {
    return this->m_uPileRole;
}

// address=[0x151fab0]
// Decompiled from int __thiscall CPile::Role(CPile *this)
class IPileRole &CPile::Role(void) {
    return *this->m_pRole;
}

// address=[0x151fad0]
// Decompiled from void __thiscall CPile::SetGoodType(CPile *this, char a2)
void CPile::SetGoodType(int a2) {
    this->m_uGood = a2;
}

// address=[0x152f210]
// Decompiled from bool __thiscall CPile::HasSpace(CPile *this)
bool CPile::HasSpace(void) const {

    return this->m_uAmountComing + this->m_uAmount < 8;
}

// address=[0x155b300]
// Decompiled from void __thiscall CPile::OfferCompletePileIfPossible(CPile *this, _DWORD *a2)
void CPile::OfferCompletePileIfPossible(int a2) {
    CPile::Offer(-1, a2);
}

// address=[0x155b340]
// Decompiled from void __thiscall CPile::SetOfferFlag(CPile *this, BYTE a2)
void CPile::SetOfferFlag(bool a2) {

    this->m_bOfferFlag = a2;
}

// address=[0x155b360]
// Decompiled from void __thiscall CPile::SetRoleType(CPile *this, unsigned __int8 a2)
void CPile::SetRoleType(int a2) {

    this->m_uPileRole = a2;
}

// address=[0x155b7d0]
// Decompiled from int __thiscall CPile::GetBuildingId(CPile *this)
int CPile::GetBuildingId(void) const {
    BB_ASSERT(m_uPileRole != IPileRole::PILE_ANYWHERE)
    return this->m_uBuildingId;
}

// address=[0x155b820]
// Decompiled from BYTE __thiscall CPile::GetOfferFlag(CPile *this)
bool CPile::GetOfferFlag(void) const {
    return this->m_bOfferFlag;
}

// address=[0x155b840]
// Decompiled from bool __thiscall CPile::IsInOfferList(IEntity *this)
bool CPile::IsInOfferList(void) const {
    return IEntity::FlagBits(ENTITY_FLAG_Offered) != 0;
}

// address=[0x155bda0]
// Decompiled from void __thiscall CPile::Delete(CPile *this)
void CPile::Delete(void) {
    CWorldManager::SetPileId(this->WorldIdx(), 0);
    CWorldManager::SetMoveCostsBits(this->WorldIdx(), 2);
    CWorldManager::ClearFlagBits(this->WorldIdx(), 2);

    this->m_cPileObserverList.NotifyAndDetachAllObservers(CEntityEvent(9u, 0, this->EntityId(), 0, 0));

    g_pMapObjectMgr->UnRegisterFromLogicUpdate(this->GetLastLogicUpdateTick(), this->m_iEntityId); // TODO: change to getter
    g_cPileMgr.CheckOutPile(ID());

    if(debug && DEBUG_FLAGS[s_iPileDebugSection]) {
        BBSupportTracePrintF(0, "Pile %u deleted goodType %s", this->ID(), s_sGoodDefines[this->m_uGood].m_spName);
    }
}

// address=[0x155bed0]
// Decompiled from void __thiscall CPile::LogicUpdate(CPile *this)
void CPile::LogicUpdate(void) {
    if(ProcessAllEvents())
        return;
    this->m_pRole->LogicUpdate(this);
}

// address=[0x155bf10]
// Decompiled from struct SGfxObjectInfo *__thiscall CPile::GetGfxInfos(CPile *this)
struct SGfxObjectInfo *CPile::GetGfxInfos(void) {

    memset(&IEntity::m_sGfxInfo, 0, sizeof(IEntity::m_sGfxInfo));

    if(!this->m_uGood || this->m_uGood >= GOOD_MAX || !this->m_uAmount)
        return &IEntity::m_sGfxInfo;

    g_pGfxManager->GetPileGfxInfo(
        &IEntity::m_sGfxInfo,
        this->m_uGood,
        this->m_uAmount,
        this->byte4A);
    IEntity::m_sGfxInfo.m_uObjType = this->m_uObjType;
    IEntity::m_sGfxInfo.m_bIsVisible = this->IsVisible();
    return &IEntity::m_sGfxInfo;
}

// address=[0x155bfa0]
// Decompiled from void __thiscall CPile::GetPatchGfx(CPile *this, struct SGfxPatchObject *_pGfxPatchObject)
void CPile::GetPatchGfx(SGfxPatchObject &_pGfxPatchObject) {

    if(this->m_uGood && (unsigned __int8)this->m_uGood < 0x2Bu && this->m_uAmount) {
        g_pGfxManager->GetPatchPileGfxInfo(
            _pGfxPatchObject,
            this->m_uGood,
            this->m_uAmount,
            this->byte4A);
    } else {
        _pGfxPatchObject.m_pGfxData = 0;
        _pGfxPatchObject.m_pPalData = 0;
    }
    _pGfxPatchObject.m_iOffsetX = this->m_iOffsetX;
    _pGfxPatchObject.m_iOffsetY = this->m_iOffsetY;
}

// address=[0x155c030]
// Decompiled from int __thiscall CPile::ChangeRole(CPile *this, int _iRoleType)
void CPile::ChangeRole(int _iRoleType) {
    BB_ASSERT(_iRoleType == IPileRole::PILE_ANYWHERE)

    if(this->m_uBuildingId) {
        g_cBuildingMgr[this->m_uBuildingId].Detach(ID());
    }

    std::unique_ptr<IPileRole> pPileRole(CPileMgr::CreatePileRole(_iRoleType));

    this->m_pRole = std::move(pPileRole);
    this->m_pRole->Init(this);
}

// address=[0x155c130]
// Decompiled from int __thiscall CPile::IncreaseUnforeseen(CPile *this, int _iAmount)
int CPile::IncreaseUnforeseen(int _iAmount) {
    BB_ASSERT((_iAmount >= 0) && (_iAmount <= MAX_PILE_AMOUNT))

    if(_iAmount <= 0)
        return 0;

    int iAvailableSpace = 8 - this->m_uAmount - this->m_uAmountComing;

    BB_ASSERT(iAvailableSpace >= 0)
    BB_ASSERT(_iAmount <= iAvailableSpace)

    if(iAvailableSpace <= 0)
        return 0;
    if(_iAmount > iAvailableSpace)
        _iAmount = iAvailableSpace;

    this->m_uAmount += _iAmount;
    CPile::AdjustStatistic(_iAmount, 0);
    this->m_pRole->Increase(this, _iAmount);
    BB_ASSERT(m_uAmount <= MAX_PILE_AMOUNT)
    BB_ASSERT(m_uAmount + m_uAmountComing <= MAX_PILE_AMOUNT)
    return _iAmount;
}

// address=[0x155c2a0]
// Decompiled from void __thiscall CPile::DecreaseUnforeseen(CPile *this, int _iAmount)
void CPile::DecreaseUnforeseen(int _iAmount) {

    BB_ASSERT((_iAmount >= 0) && (_iAmount <= MAX_PILE_AMOUNT))
    if(_iAmount > 0) {
        int iAvailableGoods = this->m_uAmount - this->m_uAmountLeaving;
        BB_ASSERT(iAvailableGoods >= 0)
        BB_ASSERT(_iAmount <= iAvailableGoods)

        if(iAvailableGoods > 0) {
            if(_iAmount > iAvailableGoods)
                _iAmount = iAvailableGoods;

            this->m_uAmount -= _iAmount;
            CPile::AdjustStatistic(-_iAmount, 0);
            this->m_pRole->Decrease(this, 1); // NOTE: decrease by just 1?

            BB_ASSERT(m_uAmount <= MAX_PILE_AMOUNT)
            BB_ASSERT(m_uAmountLeaving <= m_uAmount)

            if(!this->m_uAmount) {
                this->m_uAmountLeaving = 0;
                this->m_pRole->Empty(this);
            }
        }
    }
}

// address=[0x155c430]
// Decompiled from bool __thiscall CPile::ForceAmountLeaving(CPile *this, int a2, int a3)
bool CPile::ForceAmountLeaving(int a2, int a3) {

    return CPile::GoodAvailable();
    // NOTE: this actually just returns GoodAvailable! They added a hard early CPile::GoodAvailable() at the start. The rest is most likely just debug code the compiler left in

    int v13 = 0;
    while(1) {
        if(!CPile::GoodAvailable())
            --v13; // Not actually a while - probably an if(!G..A..). Broken output due to hacks to show this

        int iObservers = this->m_cPileObserverList.NumberOfObservers();
        if(!iObservers)
            break;
        SPileObserver const *pObservers = this->m_cPileObserverList.Observers();
        if(!pObservers && BBSupportDbgReport(2, "MapObjects\\Pile\\Pile.cpp", 596, "pObservers") == 1)
            __debugbreak();
        while(iObservers > 0) {
            IEntity *pEntity = CMapObjectMgr::EntityPtr(pObservers->m_iObserverId);
            if(pEntity->ObjType() == SETTLER_OBJ && pEntity->Type() != SETTLER_THIEF) {
                CSettler *pSettler = dynamic_cast<CSettler *>(pEntity);
                if(Grid::Distance(pEntity->X(), pEntity->Y(), this->X(), this->Y()) >= a2) {
                    pSettler->SetFree();
                    if(this->GoodAvailable())
                        --v13;
                }
            }
        }
    }
    return v13 == 0;
}

// address=[0x155c580]
// Decompiled from void __thiscall CPile::SetBuildingId(CPile *this, int _iBuidingId)
void CPile::SetBuildingId(int _iBuidingId) {
    BB_ASSERT(m_uPileRole != IPileRole::PILE_ANYWHERE)
    BB_ASSERT(_iBuidingId > 0)

    CBuilding &rBuilding = g_cBuildingMgr[_iBuidingId];
    rBuilding.Attach(this->EntityId());
    BB_ASSERT(m_uBuildingId == _iBuidingId)
}

// address=[0x155c640]
// Decompiled from void __thiscall CPile::Occupied(CPile *this, int _iNewEcoSectorId)
void CPile::Occupied(int _iNewEcoSectorId) {
    BB_ASSERT(_iNewEcoSectorId > 0)

    CEcoSector &v2 = g_cESMgr[_iNewEcoSectorId];
    int iTargetGoodType = g_cPileMgr.ConvertGoodType(this->GetGoodType(), CPlayerManager::Race(v2.Owner()));
    CPile::SetGoodType(iTargetGoodType);
    this->m_pRole->Occupied(this, _iNewEcoSectorId);
    CPile::AdjustStatistic(this->m_uAmount, _iNewEcoSectorId);
}

// address=[0x155c700]
// Decompiled from char __thiscall CPile::SetFree(CPile *this, int _iOldEcoSectorId)
bool CPile::SetFree(int _iOldEcoSectorId) {
    BB_ASSERT(_iOldEcoSectorId > 0)
    this->m_pRole->SetFree(this, _iOldEcoSectorId);
    CPile::AdjustStatistic(this->m_uAmount, -_iOldEcoSectorId);
    return false;
}

// address=[0x155c780]
// Decompiled from void __thiscall CPile::NotifyChangeEcoSector(CPile *this, int _iOldEcoSectorId, int _iNewEcoSectorId)
void CPile::NotifyChangeEcoSector(int _iOldEcoSectorId, int _iNewEcoSectorId) {
    BB_ASSERT(_iOldEcoSectorId > 0)
    BB_ASSERT(_iNewEcoSectorId > 0)
    BB_ASSERT(_iOldEcoSectorId != _iNewEcoSectorId)

    int uAmount = this->m_uAmount;
    CPile::AdjustStatistic(-uAmount, _iOldEcoSectorId);
    CPile::AdjustStatistic(uAmount, _iNewEcoSectorId);
    this->m_pRole->NotifyChangeEcoSector(this, _iOldEcoSectorId, _iNewEcoSectorId);
}

// address=[0x155c860]
// Decompiled from void __thiscall CPile::Offer(CPile *this, int a2, int _iEcoSectorId)
void CPile::Offer(int a2, int _iEcoSectorId) {

    BB_ASSERT(_iEcoSectorId >= 0)

    if(!_iEcoSectorId)
        _iEcoSectorId = CWorldManager::EcoSectorId(WorldIdx());

    if(_iEcoSectorId <= 0)
        return;

    g_cESMgr[_iEcoSectorId].SetGoodOffer(GetGoodType(), EntityId());
}

// address=[0x155c8e0]
// Decompiled from void __thiscall CPile::CancelOffer(IEntity *this, int a2, int _iEcoSectorId)
void CPile::CancelOffer(int a2, int _iEcoSectorId) {
    BB_ASSERT(_iEcoSectorId >= 0)

    if(!_iEcoSectorId)
        _iEcoSectorId = CWorldManager::EcoSectorId(WorldIdx());

    if(_iEcoSectorId <= 0)
        return;

    g_cESMgr[_iEcoSectorId].GetPileOutOfOffer(GetGoodType(), EntityId());
}

// address=[0x155c960]
// Decompiled from void __thiscall CPile::CancelCompleteOfferIfInOfferList(CPile *this, int a2)
void CPile::CancelCompleteOfferIfInOfferList(int _iEcoSectorId) {
    if(CPile::IsInOfferList())
        CPile::CancelOffer(-1, _iEcoSectorId);
}

// address=[0x155c990]
// Decompiled from void __thiscall CPile::ChangeNumberOfOfferedGoodsInEcoSector(CPile *this, int a2, int a3)
void CPile::ChangeNumberOfOfferedGoodsInEcoSector(int a2, int a3) {

    ;
}

// address=[0x155c9a0]
// Decompiled from int __thiscall CPile::CalcUrgent(CPile *this)
int CPile::CalcUrgent(void) const {

    return 4000 * ((MAX_PILE_AMOUNT * 2) - (this->m_uAmountComing + 2 * this->m_uAmount));
}

// address=[0x155c9d0]
// Decompiled from void __thiscall CPile::NotifyTargetDieAndDetachAllObservers(CPile *this)
void CPile::NotifyTargetDieAndDetachAllObservers(void) {
    m_cPileObserverList.NotifyAndDetachAllObservers(CEntityEvent(9u, 0, EntityId(), 0, 0));

    if(this->m_uAmountComing) {
        this->m_uAmountComing = 0;
        this->m_pRole->DecAmountComing(this);
    }

    if(this->m_uAmountLeaving) {
        this->m_uAmountLeaving = 0;
        this->m_pRole->DecAmountLeaving(this);
    }
}

// address=[0x155cab0]
// Decompiled from unsigned int __cdecl CPile::operator new(unsigned int a1)
void *__cdecl CPile::operator new(unsigned int a1) {
    return g_cPileMgr.Alloc(a1);
}

// address=[0x155cad0]
// Decompiled from int __cdecl CPile::operator delete(_DWORD *a1)
void __cdecl CPile::operator delete(void *a1) {
    return g_cPileMgr.Dealloc(a1);
}

// address=[0x155cb10]
// Decompiled from void __thiscall CPile::Detach(CPile *this, int a2)
void CPile::Detach(int a2) {
    int iDeltaAmount = m_cPileObserverList.Detach(a2);
    if(iDeltaAmount < 0) {
        CPile::DecAmountLeaving(-iDeltaAmount);
        return;
    }

    if(iDeltaAmount > 0) {
        BB_ASSERT(iDeltaAmount == 1)

        CPile::DecAmountComing();
    }
}

// address=[0x155cb80]
// Decompiled from void __thiscall CPile::ChangeAmountAndDetach(CPile *this, int a2)
void CPile::ChangeAmountAndDetach(int a2) {

    int iDeltaAmount = m_cPileObserverList.Detach(a2);
    if(iDeltaAmount < 0) {
        CPile::DecreaseEx(-iDeltaAmount);
        return;
    }

    if(iDeltaAmount > 0) {
        BB_ASSERT(iDeltaAmount == 1)
        CPile::IncreaseEx(1);
    }
}

// address=[0x155cbf0]
// Decompiled from void __thiscall CPile::AttachAndIncAmountLeaving(CPile *this, int a2, int _iAmount, int _tTargetType)
void CPile::AttachAndIncAmountLeaving(int a2, int _iAmount, enum T_OBSERVER_TARGET _tTargetType) {
    BB_ASSERT((_iAmount >= 1) && (_iAmount <= MAX_PILE_AMOUNT))
    BB_ASSERT((_tTargetType == OBSERVER_TARGET_PILE_SRC) || (_tTargetType == OBSERVER_TARGET_PILE_SRC_2) || (_tTargetType == OBSERVER_TARGET_PILE_SRC_3))
    m_cPileObserverList.Attach(_tTargetType, EntityId(), a2, -_iAmount);
    CPile::IncAmountLeaving(_iAmount);
}

// address=[0x155cc90]
// Decompiled from void __thiscall CPile::AttachAndIncAmountComing(CPile *this, int _iAmount)
void CPile::AttachAndIncAmountComing(int _iAmount) {
    this->m_cPileObserverList.Attach(OBSERVER_TARGET_SECONDARY, EntityId(), _iAmount, 1);
    CPile::IncAmountComing();
}

// address=[0x155ccd0]
// Decompiled from int __thiscall CPile::Notify(CPile *this, const struct CEntityEvent *a2)
void CPile::Notify(class CEntityEvent const &a2) const {
    m_cPileObserverList.NotifyAllObservers(a2);
}

// address=[0x155ccf0]
// Decompiled from void __thiscall CPile::SetObserverTarget(CPile *this, int _tTargetType, int _iTargetId)
void CPile::SetObserverTarget(enum T_OBSERVER_TARGET _tTargetType, int _iTargetId) {
    if(_tTargetType) {
        BB_REPORT("CPile::SetObserverTarget(): Invalid target type!")
        return;
    }

    if(_iTargetId <= 0) {
        this->m_iFlags &= ~0x20u;
        if(this->m_uBuildingId) {
            BB_ASSERT(GetRoleType() != IPileRole::PILE_ANYWHERE)

            CPile::NotifyTargetDieAndDetachAllObservers();
            int uBuildingId = this->m_uBuildingId;
            this->m_uBuildingId = 0;
            this->m_pRole->SubjectDie(this, uBuildingId);
        }
    } else {
        BB_ASSERT(m_uBuildingId == 0)
        BB_ASSERT(g_cBuildingMgr.GetBuildingPtr(_iTargetId) != 0)

        BB_ASSERT(GetRoleType() != IPileRole::PILE_ANYWHERE)
        this->m_uBuildingId = _iTargetId;
        this->m_iFlags |= 0x20u;
    }
}

// address=[0x155ce70]
// Decompiled from int __thiscall CPile::GetObserverTarget(CPile *this, int a2)
int CPile::GetObserverTarget(enum T_OBSERVER_TARGET a2) {
    if(a2)
        return 0;
    else
        return this->m_uBuildingId;
}

// address=[0x155ce90]
// Decompiled from void __thiscall CPile::RequestSpaceIfPossible(CPile *this)
void CPile::RequestSpaceIfPossible(void) {
    int iEcoSector = CWorldManager::EcoSectorId(X(), Y());
    if(iEcoSector > 0) {
        if(CPile::GoodAvailable()) {
            g_cESMgr[iEcoSector].RequestSpace(this);
        }
    }
}

// address=[0x155d7c0]
// Decompiled from CPile *__thiscall CPile::CPile(CPile *this, struct std::istream *_rStream)
CPile::CPile(std::istream &_rStream) : IAnimatedEntity(_rStream), m_cPileObserverList() {

    unsigned int fileFormatVersion; // [esp+Ch] [ebp-1Ch] BYREF
    _rStream >> fileFormatVersion;
    if(fileFormatVersion != 1) {
        BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CPile");
        throw CS4InvalidMapException();
    }
    _rStream >> this->m_uGood;
    _rStream >> this->m_uAmount;
    _rStream >> this->m_uAmountLeaving;
    _rStream >> this->m_uAmountComing;
    _rStream >> this->m_uPileRole;
    _rStream >> this->m_bIsPatchPile;
    _rStream >> this->byte4A;
    _rStream >> this->m_iOffsetX;
    _rStream >> this->m_iOffsetY;
    _rStream >> this->m_uBuildingId;
    _rStream >> this->m_bOfferFlag;
    std::unique_ptr<IPileRole> iPileRole(CPileMgr::LoadPileRole(_rStream, this->m_uPileRole));
    this->m_pRole = std::move(iPileRole);

    static_assert(std::is_same_v<decltype(this->m_uGood), unsigned char>, "must be same type");
    static_assert(std::is_same_v<decltype(this->m_uAmount), unsigned char>, "must be same type");
    static_assert(std::is_same_v<decltype(this->m_uAmountLeaving), unsigned char>, "must be same type");
    static_assert(std::is_same_v<decltype(this->m_uAmountComing), unsigned char>, "must be same type");
    static_assert(std::is_same_v<decltype(this->m_uPileRole), unsigned char>, "must be same type");
    static_assert(std::is_same_v<decltype(this->m_bIsPatchPile), unsigned char>, "must be same type");
    static_assert(std::is_same_v<decltype(this->byte4A), unsigned char>, "must be same type");
    static_assert(std::is_same_v<decltype(this->m_iOffsetX), short>, "must be same type");
    static_assert(std::is_same_v<decltype(this->m_iOffsetY), short>, "must be same type");
    static_assert(std::is_same_v<decltype(this->m_uBuildingId), unsigned short>, "must be same type");
    static_assert(std::is_same_v<decltype(this->m_bOfferFlag), bool>, "must be same type");
}

// address=[0x155d9a0]
// Decompiled from void __thiscall CPile::Store(CPile *this, struct std::ostream *_rStream)
void CPile::Store(std::ostream &_rStream) {
    IAnimatedEntity::Store(_rStream);
    this->m_cPileObserverList.Store(_rStream);
    unsigned int fileFormatVersion = 1;
    _rStream << fileFormatVersion;
    _rStream << this->m_uGood;
    _rStream << this->m_uAmount;
    _rStream << this->m_uAmountLeaving;
    _rStream << this->m_uAmountComing;
    _rStream << this->m_uPileRole;
    _rStream << this->m_bIsPatchPile;
    _rStream << this->byte4A;
    _rStream << this->m_iOffsetX;
    _rStream << this->m_iOffsetY;
    _rStream << this->m_uBuildingId;
    _rStream << this->m_bOfferFlag;
    this->m_pRole->Store(_rStream);
}

// address=[0x155e770]
// Decompiled from int __thiscall CPile::Amount(CPile *this)
int CPile::Amount(void) const {
    return this->m_uAmount;
}

// address=[0x155e790]
// Decompiled from int __thiscall CPile::ClassID(CPile *this)
unsigned long CPile::ClassID(void) const {

    return CPile::m_iClassID;
}

// address=[0x155e7d0]
// Decompiled from int __thiscall CPile::GetGoodType(CPile *this)
int CPile::GetGoodType(void) const {

    return this->m_uGood;
}

// address=[0x15604c0]
// Decompiled from void __thiscall CPile::ReassessDistance(CPile *this, int *a2)
void CPile::ReassessDistance(int &a2) {
    this->m_pRole->ReassessDistance(this, a2);
}

// address=[0x15615b0]
// Decompiled from int __thiscall CPile::BuildingId(CPile *this)
int CPile::BuildingId(void) const {

    return this->m_uBuildingId;
}

// address=[0x3d8bbc0]
// [Decompilation failed for static unsigned long CPile::m_iClassID]

// address=[0x155cef0]
// Decompiled from void __thiscall CPile::IncreaseEx(CPile *this, int _iAmount)
void CPile::IncreaseEx(int _iAmount) {
    BB_ASSERT((_iAmount >= 1) && (_iAmount <= MAX_PILE_AMOUNT))
    int iFreeSpace = 8 - this->m_uAmount;
    int iAmountComing = this->m_uAmountComing;

    BB_ASSERT(iFreeSpace >= 0)
    BB_ASSERT(iAmountComing <= iFreeSpace)
    if(iFreeSpace < 0) {
        iFreeSpace = 0;
        this->m_uAmount = 8;
    }

    BB_ASSERT(_iAmount <= iFreeSpace)
    BB_ASSERT(_iAmount <= iAmountComing)
    if(_iAmount > iFreeSpace)
        _iAmount = iFreeSpace;
    if(_iAmount > iAmountComing)
        _iAmount = iAmountComing;

    BB_ASSERT(_iAmount >= 0)
    BB_ASSERT(_iAmount <= iFreeSpace)
    BB_ASSERT(_iAmount <= iAmountComing)
    if(_iAmount > 0) {
        this->m_uAmount += _iAmount;
        this->m_uAmountComing -= _iAmount;
        CPile::AdjustStatistic(_iAmount, 0);
        this->m_pRole->Increase(this, _iAmount);
        BB_ASSERT(m_uAmount <= MAX_PILE_AMOUNT)
        BB_ASSERT(m_uAmountComing <= MAX_PILE_AMOUNT)
        BB_ASSERT(m_uAmount + m_uAmountComing <= MAX_PILE_AMOUNT)
    }
}

// address=[0x155d180]
// Decompiled from void __thiscall CPile::DecreaseEx(CPile *this, int _iAmount)
void CPile::DecreaseEx(int _iAmount) {
    BB_ASSERT((_iAmount >= 1) && (_iAmount <= MAX_PILE_AMOUNT))

    int iCurrentAmount = this->m_uAmount;
    int iAmountLeaving = this->m_uAmountLeaving;

    BB_ASSERT(iAmountLeaving <= iCurrentAmount)
    BB_ASSERT(_iAmount <= iCurrentAmount)
    BB_ASSERT(_iAmount <= iAmountLeaving)
    BB_ASSERT(iAmountLeaving <= iCurrentAmount)

    if(_iAmount > iCurrentAmount)
        _iAmount = iCurrentAmount;
    if(_iAmount > iAmountLeaving)
        _iAmount = iAmountLeaving;

    this->m_uAmount -= _iAmount;
    this->m_uAmountLeaving -= _iAmount;
    CPile::AdjustStatistic(-_iAmount, 0);
    this->m_pRole->Decrease(this, _iAmount);

    if(!this->m_uAmount) {
        this->m_uAmountLeaving = 0;
        this->m_pRole->Empty(this);
    }

    BB_ASSERT(m_uAmount <= MAX_PILE_AMOUNT)
    BB_ASSERT(m_uAmountLeaving <= m_uAmount)
}

// address=[0x155d370]
// Decompiled from int __thiscall CPile::Increase(CPile *this, int a2)
int CPile::Increase(int a2) {
    BB_REPORT("CPile::Increase() called!")
    return 0;
}

// address=[0x155d3a0]
// Decompiled from int __thiscall CPile::Decrease(CPile *this, int a2)
void CPile::Decrease(int a2) {
    BB_REPORT("CPile::Decrease() called!")
}

// address=[0x155d3d0]
// Decompiled from void __thiscall CPile::IncAmountLeaving(CPile *this, int _iAmount)
void CPile::IncAmountLeaving(int _iAmount) {
    BB_ASSERT(_iAmount > 0)
    BB_ASSERT(m_uAmountLeaving < m_uAmount)
    for(int i = 0; i < _iAmount; ++i) {
        ++this->m_uAmountLeaving;
        this->m_pRole->IncAmoutLeaving(this);
    }
}

// address=[0x155d480]
// Decompiled from void __thiscall CPile::DecAmountLeaving(CPile *this, int _iAmount)
void CPile::DecAmountLeaving(int _iAmount) {
    BB_ASSERT(_iAmount >= 1)
    int iAmountLeaving = this->m_uAmountLeaving;
    BB_ASSERT(iAmountLeaving >= _iAmount)
    if(_iAmount > iAmountLeaving)
        _iAmount = iAmountLeaving;
    for(int i = 0; i < _iAmount; ++i) {
        --this->m_uAmountLeaving;
        this->m_pRole->DecAmountLeaving(this);
    }
}

// address=[0x155d540]
// Decompiled from void __thiscall CPile::IncAmountComing(CPile *this)
void CPile::IncAmountComing(void) {

    // [esp+0h] [ebp-8h]

    BB_ASSERT((m_uAmount + m_uAmountComing) < MAX_PILE_AMOUNT)
    ++this->m_uAmountComing;
    this->m_pRole->IncAmountComing(this);
}

// address=[0x155d5b0]
// Decompiled from void __thiscall CPile::DecAmountComing(CPile *this)
void CPile::DecAmountComing(void) {

    // [esp+0h] [ebp-8h]

    if(this->m_uAmountComing == 0)
        BB_REPORTF("AmountComing=0 ! %u", this->m_iEntityId)

    --this->m_uAmountComing;
    this->m_pRole->DecAmountComing(this);
}

// address=[0x155d620]
// Decompiled from void __thiscall CPile::AdjustStatistic(CPile *this, int _iDeltaAmount, int _iEcoSectorId)
void CPile::AdjustStatistic(int _iDeltaAmount, int _iEcoSectorId) {

    // eax
    // [esp+0h] [ebp-Ch]
    // [esp+4h] [ebp-8h]

    BB_ASSERT((_iDeltaAmount >= -MAX_PILE_AMOUNT) && (_iDeltaAmount <= MAX_PILE_AMOUNT))

    if(_iDeltaAmount) {
        if(_iEcoSectorId <= 0) {
            _iEcoSectorId = ITiling::EcoSectorId(WorldIdx());
        }

        if(_iEcoSectorId > 0) {
            CEcoSector &rES = g_cESMgr[_iEcoSectorId];
            rES.ChangeNumberOfGoodsPile(this->m_uGood, _iDeltaAmount);

            int iOwnerId = rES.Owner();
            BB_ASSERT(iOwnerId > 0)

            if(_iDeltaAmount <= 0)
                g_cStatistic.DecGood(iOwnerId, this->m_uGood, -_iDeltaAmount);
            else
                g_cStatistic.AddGood(iOwnerId, this->m_uGood, _iDeltaAmount);
        }
    }
}

// address=[0x155d720]
// Decompiled from bool __thiscall CPile::ExecuteChangeGoodTypeUnforseen(CPile *this, int a2)
bool CPile::ExecuteChangeGoodTypeUnforseen(int _iGood) {
    if(_iGood <= 0 || _iGood >= GOOD_MAX)
        return 0;
    if(this->GetGoodType() == _iGood)
        return 0;

    CPile::NotifyTargetDieAndDetachAllObservers();
    int iCurrentAmount = this->m_uAmount;
    CPile::CancelCompleteOfferIfInOfferList(0);
    CPile::AdjustStatistic(-iCurrentAmount, 0);
    CPile::SetGoodType(_iGood);
    CPile::AdjustStatistic(iCurrentAmount, 0);
    if(CPile::GetOfferFlag())
        CPile::OfferCompletePileIfPossible(0);
    return 1;
}

// address=[0x155dae0]
// Decompiled from CPile *__thiscall CPile::CPile(  CPile *this,  int _iX,  int _iY,  S4_GOOD_ENUM _iGood,  int _iAmount,  int _pRole,  int _iSlot,  char a8,  char a9,  __int16 _iOffsetX,  __int16 _iOffsetY)
CPile::CPile(int _iX, int _iY, int _iGood, int _iAmount, class std::unique_ptr<IPileRole> _pRole, int _iSlot, int a8, int a9, int _iOffsetX, int _iOffsetY) : IAnimatedEntity(_iSlot), m_pRole(std::move(_pRole)) {

    BB_ASSERT(g_cWorld.FlagBits(_iX, _iY, FLAG_BLOCKED_LAND) == 0)
    BB_ASSERT(static_cast<unsigned int>(_iGood) < GOOD_MAX)

    this->m_uObjType = Good;
    this->m_uGood = _iGood;
    this->m_uAmount = _iAmount;
    this->m_uAmountLeaving = 0;
    this->m_uAmountComing = 0;
    this->m_uPileRole = 0;
    this->m_bIsPatchPile = a9;
    this->byte4A = a8;
    this->m_iOffsetX = _iOffsetX;
    this->m_iOffsetY = _iOffsetY;
    this->m_uBuildingId = 0;
    IEntity::SetFlagBits((EntityFlag)4352);
    IEntity::ClearFlagBits(ENTITY_FLAG_Registered);
    int iIndex = CWorldManager::Index(_iX, _iY);
    IEntity::SetPosition(_iX, _iY);
    CWorldManager::SetPileId(WorldIdx(), _iSlot);
    CWorldManager::SetMoveCostsBits(iIndex, 7);
    CWorldManager::SetFlagBits(iIndex, 2u);
    CPile::AdjustStatistic(_iAmount, 0);
    this->m_pRole->Init(this);
}

// address=[0x155dcc0]
// Decompiled from int __thiscall CPile::~CPile(CPile *this)
CPile::~CPile(void) = default;

// address=[0x155dcf0]
// Decompiled from void __thiscall CPile::ConvertEventIntoGoal(CPile *this, struct CEntityEvent *a2)
void CPile::ConvertEventIntoGoal(class CEntityEvent *a2) {
    switch(a2->m_iEvent) {
    case 7:
        m_pRole->SubjectStopped(this);
        break;
    case 8:
        m_pRole->SubjectStarted(this);
        break;
    case 9:
        g_pMapObjectMgr->DbgPrintEntity(EntityId(), 0, 0);
        g_pMapObjectMgr->DbgPrintEntity(a2->m_iDataA, 0, 0);
        BB_REPORT("CPile::ConvertEventIntoGoal(): Illegal event TARGET_DIE!")
        break;
    default:
        break;
    }
    IEntity::SetFlagBits(0x80000000);
}
