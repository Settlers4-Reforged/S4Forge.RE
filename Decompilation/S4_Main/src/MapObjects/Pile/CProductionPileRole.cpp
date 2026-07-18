#include "CProductionPileRole.h"

#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "CPile.h"
#include "Defines/World.h"
#include "Logic/CStatistic.h"
#include "Pathing/ITiling.h"
#include "World/CWorldManager.h"

#include <iostream>

// Definitions for class CProductionPileRole

class CEcoSector;

// address=[0x14018a0]
// Decompiled from void __cdecl CProductionPileRole::New(struct std::_Facet_base *a1)
class CPersistence *__cdecl CProductionPileRole::New(std::istream &_rStream) {
    return new CProductionPileRole(_rStream);
}

// address=[0x1560240]
// Decompiled from void __thiscall CProductionPileRole::~CProductionPileRole(CProductionPileRole *this)
CProductionPileRole::~CProductionPileRole(void) = default;

// address=[0x1560300]
// Decompiled from int __thiscall CProductionPileRole::ClassID(CProductionPileRole *this)
unsigned long CProductionPileRole::ClassID(void) const {

    return CProductionPileRole::m_iClassID;
}

// address=[0x1560400]
// Decompiled from int __cdecl CProductionPileRole::Load(int a1)
class CProductionPileRole *__cdecl CProductionPileRole::Load(std::istream &_rStream) {
    return dynamic_cast<class CProductionPileRole *>(CPersistence::New(_rStream));
}

// address=[0x15615d0]
// Decompiled from void __thiscall CProductionPileRole::Init(CProductionPileRole *this, struct CPile *a2)
void CProductionPileRole::Init(class CPile *_pPile) {

    int v3; // eax

    IPileRole::Init(_pPile);
    _pPile->SetRoleType(PILE_PRODUCTION);
    _pPile->SetOfferFlag(1u);
    _pPile->OfferCompletePileIfPossible(0);
    _pPile->RegisterForLogicUpdate(31);

    BB_ASSERT(g_cWorld.FlagBits(_pPile->WorldIdx(), FLAG_BUILDING) != 0)
    BB_ASSERT(g_cWorld.EcoSectorId(_pPile->WorldIdx()) > 0)
}

// address=[0x1561680]
// Decompiled from int __thiscall CProductionPileRole::LogicUpdate(CProductionPileRole *this, struct CPile *a2)
void CProductionPileRole::LogicUpdate(class CPile *_pPile) {
    if(_pPile->NumberOfAvailableGoods() < 2) {
        _pPile->RegisterForLogicUpdate(31);
        return;
    }

    g_cEcoSectorMgr[g_cWorld.EcoSectorId(_pPile->WorldIdx())].RequestSpace(_pPile);
    _pPile->RegisterForLogicUpdate(31);
}

// address=[0x15616d0]
// Decompiled from void __thiscall CProductionPileRole::Increase(CProductionPileRole *this, struct CPile *a2, int a3)
void CProductionPileRole::Increase(class CPile *_pPile, int _iAmount) {

    int v3; // eax
    int v4; // eax
    int v5; // [esp+0h] [ebp-8h]

    IPileRole::Increase(_pPile, _iAmount);
    BB_ASSERT(_iAmount >= 0)

    if(_iAmount > 0) {
        g_cStatistic.AddProducedGoods(ITiling::OwnerId(_pPile->WorldIdx()), _pPile->GetGoodType(), _iAmount);
    }
}

// address=[0x1561750]
// Decompiled from void __thiscall CProductionPileRole::ReassessDistance(CProductionPileRole *this, struct CPile *a2, int *a3)
void CProductionPileRole::ReassessDistance(class CPile *_pPile, int &_rDistance) {
    _rDistance /= 2;
}

// address=[0x1561770]
// Decompiled from _DWORD *__thiscall CProductionPileRole::CProductionPileRole(_DWORD *this, int a2)
CProductionPileRole::CProductionPileRole(std::istream &_rStream) : IPileRole(_rStream) {

    unsigned int iFileFormatVersion;
    _rStream >> iFileFormatVersion;
    if(iFileFormatVersion != 1) {
        BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CProductionPileRole");
        throw CS4InvalidMapException();
    }
}

// address=[0x1561820]
// Decompiled from int __thiscall CProductionPileRole::Store(void *this, struct std::ostream *a2)
void CProductionPileRole::Store(std::ostream &_rStream) {

    IPileRole::Store(_rStream);

    unsigned int iFileFormatVersion = 1;
    _rStream << iFileFormatVersion;
}

// address=[0x3d8be98]
// [Decompilation failed for static unsigned long CProductionPileRole::m_iClassID]

// address=[0x15601a0]
// Decompiled from CProductionPileRole *__thiscall CProductionPileRole::CProductionPileRole(CProductionPileRole *this)
CProductionPileRole::CProductionPileRole(void) : IPileRole() {
}
