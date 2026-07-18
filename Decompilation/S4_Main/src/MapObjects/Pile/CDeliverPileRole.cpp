#include "CDeliverPileRole.h"

#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "Defines/World.h"
#include "MapObjects/Pile/CPile.h"
#include "World/CWorldManager.h"

#include <iostream>

// Definitions for class CDeliverPileRole

// address=[0x1400400]
// Decompiled from void __cdecl CDeliverPileRole::New(struct std::_Facet_base *a1)
class CPersistence *__cdecl CDeliverPileRole::New(std::istream &a1) {
    return new CDeliverPileRole(a1);
}

// address=[0x155b880]
// Decompiled from void __thiscall CDeliverPileRole::Init(CDeliverPileRole *this, struct CPile *_pPile)
void CDeliverPileRole::Init(class CPile *_pPile) {
    IPileRole::Init(_pPile);
    _pPile->SetRoleType(PILE_DELIVER);
    _pPile->SetOfferFlag(1u);
    BB_ASSERT(g_cWorld.FlagBits(_pPile->WorldIdx(), FLAG_BUILDING) != 0)
    BB_ASSERT(g_cWorld.EcoSectorId(_pPile->WorldIdx()) > 0)
}

// address=[0x155b920]
// Decompiled from void __thiscall CDeliverPileRole::LogicUpdate(CDeliverPileRole *this, struct CPile *a2)
void CDeliverPileRole::LogicUpdate(class CPile *_pPile) {
    int v3;             // eax
    int v4;             // eax
    int v5;             // eax
    __int16 BuildingId; // [esp-8h] [ebp-10h]
    int v7;             // [esp-4h] [ebp-Ch]
                        // [esp+4h] [ebp-4h]

    if(_pPile->GetOfferFlag())
        return;

    if(!_pPile->HasSpace()) {
        _pPile->RegisterForLogicUpdate(31);
        return;
    }

    BB_ASSERT(g_cWorld.FlagBits(_pPile->WorldIdx(), FLAG_BUILDING))

    int iEcoSectorId = CWorldManager::EcoSectorId(_pPile->WorldIdx());
    if(!iEcoSectorId) {
        BB_REPORTF("iEcoSectorId != 0: Flagbits %x", CWorldManager::FlagBits(_pPile->WorldIdx(), 0xFFu))
    }
    if(iEcoSectorId) {
        g_cESMgr[iEcoSectorId].RequestGood(_pPile->GetBuildingId(), _pPile->GetGoodType());
        _pPile->RegisterForLogicUpdate(31);
    }
}

// address=[0x155ba20]
// Decompiled from void __thiscall CDeliverPileRole::Increase(CDeliverPileRole *this, struct CPile *_pPile, int _iAmount)
void CDeliverPileRole::Increase(class CPile *_pPile, int _iAmount) {

    int BuildingId; // eax
                    // eax
                    // [esp+4h] [ebp-4h]

    BB_ASSERT(_pPile != 0)
    BB_ASSERT(_iAmount > 0)
    BB_ASSERT(_pPile->GetBuildingId() != 0)
    class CBuilding *pBuilding = g_cBuildingMgr.GetBuildingPtr(_pPile->GetBuildingId());
    if(pBuilding) {
        pBuilding->GoodArrive(_pPile->GetGoodType());
    }
}

// address=[0x155bae0]
// Decompiled from void __thiscall CDeliverPileRole::SubjectStopped(CDeliverPileRole *this, CPile *a2)
void CDeliverPileRole::SubjectStopped(class CPile *_pPile) {

    _pPile->NotifyTargetDieAndDetachAllObservers();
    _pPile->SetOfferFlag(1u);
    _pPile->OfferCompletePileIfPossible(0);
}

// address=[0x155bb10]
// Decompiled from void __thiscall CDeliverPileRole::SubjectStarted(CDeliverPileRole *this, CPile *a2)
void CDeliverPileRole::SubjectStarted(class CPile *_pPile) {
    _pPile->NotifyTargetDieAndDetachAllObservers();
    _pPile->CancelCompleteOfferIfInOfferList(0);
    _pPile->SetOfferFlag(0);
    _pPile->RegisterForLogicUpdate(31);
}

// address=[0x155bb50]
// Decompiled from CDeliverPileRole *__thiscall CDeliverPileRole::CDeliverPileRole(CDeliverPileRole *this, int a2)
CDeliverPileRole::CDeliverPileRole(std::istream &_rStream) : IPileRole(_rStream) {
    int iFileFormatVersion;
    _rStream >> iFileFormatVersion;
    if(iFileFormatVersion != 1) {
        BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CDeliverPileRole");
        throw CS4InvalidMapException();
    }
}

// address=[0x155bc00]
// Decompiled from int __thiscall CDeliverPileRole::Store(CDeliverPileRole *this, struct std::ostream *a2)
void CDeliverPileRole::Store(std::ostream &_rStream) {
    IPileRole::Store(_rStream);
    int iFileFormatVersion = 1;
    _rStream << iFileFormatVersion;
}

// address=[0x155bd20]
// Decompiled from IPileRole *__thiscall CDeliverPileRole::~CDeliverPileRole(CDeliverPileRole *this)
CDeliverPileRole::~CDeliverPileRole(void) = default;

// address=[0x155bd80]
// Decompiled from int __thiscall CDeliverPileRole::ClassID(CDeliverPileRole *this)
unsigned long CDeliverPileRole::ClassID(void) const {
    return CDeliverPileRole::m_iClassID;
}

// address=[0x15603c0]
// Decompiled from int __cdecl CDeliverPileRole::Load(struct std::istream *a1)
class CDeliverPileRole *__cdecl CDeliverPileRole::Load(std::istream &a1) {
    return dynamic_cast<CDeliverPileRole *>(CPersistence::New(a1));
}

// address=[0x3d8bbbc]
// [Decompilation failed for static unsigned long CDeliverPileRole::m_iClassID]

// address=[0x1560170]
// Decompiled from CDeliverPileRole *__thiscall CDeliverPileRole::CDeliverPileRole(CDeliverPileRole *this)
CDeliverPileRole::CDeliverPileRole(void) : IPileRole() {
}
