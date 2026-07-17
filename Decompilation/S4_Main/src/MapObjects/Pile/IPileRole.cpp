#include "IPileRole.h"

#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "CPile.h"
#include "MapObjects/IEntity.h"

#include <iostream>
#include <typeinfo>

// Definitions for class IPileRole

// address=[0x155b1e0]
// Decompiled from IPileRole *__thiscall IPileRole::~IPileRole(IPileRole *this)
IPileRole::~IPileRole(void) = default;

// address=[0x155b280]
// Decompiled from char __thiscall IPileRole::ChangeGoodTypeUnforseen(IPileRole *this, struct CPile *a2, int a3)
bool IPileRole::ChangeGoodTypeUnforseen(class CPile *a2, int a3) {

    return 0;
}

// address=[0x155b2c0]
// Decompiled from void __thiscall IPileRole::DecAmountComing(IPileRole *this, struct CPile *a2)
void IPileRole::DecAmountComing(class CPile *a2) {

    ;
}

// address=[0x155b2d0]
// Decompiled from void __thiscall IPileRole::Empty(IPileRole *this, struct CPile *a2)
void IPileRole::Empty(class CPile *a2) {

    ;
}

// address=[0x155b2e0]
// Decompiled from void __thiscall IPileRole::IncAmountComing(IPileRole *this, struct CPile *a2)
void IPileRole::IncAmountComing(class CPile *a2) {

    ;
}

// address=[0x155b2f0]
// Decompiled from void __thiscall IPileRole::LogicUpdate(IPileRole *this, struct CPile *a2)
void IPileRole::LogicUpdate(class CPile *a2) {

    ;
}

// address=[0x155b330]
// Decompiled from void __thiscall IPileRole::ReassessDistance(IPileRole *this, struct CPile *a2, int *a3)
void IPileRole::ReassessDistance(class CPile *a2, int &a3) {

    ;
}

// address=[0x1560f00]
// Decompiled from void __thiscall IPileRole::Increase(IPileRole *this, struct CPile *a2, int a3)
void IPileRole::Increase(CPile *_pPile, int _iAmount) {
    BB_ASSERT(_iAmount > 0)

    BB_ASSERT(_pPile->NumberOfAvailableGoods() > 0)
    if(_pPile->IsInOfferList()) {
        BB_ASSERT(_pPile->GetOfferFlag())
    } else if(_pPile->GetOfferFlag()) {
        _pPile->Offer(_iAmount, 0);
    }
}

// address=[0x1560fc0]
// Decompiled from void __thiscall IPileRole::Decrease(IPileRole *this, struct CPile *a2, int a3)
void IPileRole::Decrease(class CPile *_pPile, int _iAmount) {

    if(_iAmount <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\PileRole.cpp", 150, "_iAmount > 0") == 1)
        __debugbreak();
    if(_pPile->IsInOfferList()) {
        BB_ASSERT(_pPile->GetOfferFlag())
        if(_pPile->NumberOfAvailableGoods() <= 0)
            _pPile->CancelOffer(_iAmount, 0);
    }
}

// address=[0x1561050]
// Decompiled from void __thiscall IPileRole::IncAmoutLeaving(IPileRole *this, struct CPile *a2)
void IPileRole::IncAmoutLeaving(class CPile *_pPile) {

    if(_pPile->IsInOfferList()) {
        BB_ASSERT(_pPile->GetOfferFlag())
        if(_pPile->NumberOfAvailableGoods() <= 0)
            _pPile->CancelOffer(0, 0);
    }
}

// address=[0x15610b0]
// Decompiled from void __thiscall IPileRole::DecAmountLeaving(IPileRole *this, struct CPile *a2)
void IPileRole::DecAmountLeaving(class CPile *_pPile) {

    BB_ASSERT(_pPile->NumberOfAvailableGoods() > 0)

    if(_pPile->IsInOfferList()) {
        BB_ASSERT(_pPile->GetOfferFlag())
    } else if(_pPile->GetOfferFlag()) {
        _pPile->Offer(0, 0);
    }
}

// address=[0x1561140]
// Decompiled from int __thiscall IPileRole::Init(IPileRole *this, struct CPile *a2)
void IPileRole::Init(class CPile *_pPile) {
    this->m_uPileId = _pPile->EntityId();
}

// address=[0x1561160]
// Decompiled from int __thiscall IPileRole::Occupied(IPileRole *this, struct CPile *a2, int a3)
void IPileRole::Occupied(class CPile *a2, int a3) {
    BB_REPORT("IPileRole::Occupied() called!")
}

// address=[0x1561190]
// Decompiled from char __thiscall IPileRole::SetFree(IPileRole *this, struct CPile *a2, int a3)
bool IPileRole::SetFree(class CPile *_pPile, int a3) {
    BBSupportTracePrintF(0, "IPileRole::SetFree(): pile %i, (%i, %i), role %s, building %i", _pPile->EntityId(), _pPile->X(), _pPile->Y(), typeid(*this).name(), _pPile->BuildingId());
    BB_REPORT("IPileRole::SetFree() called!")
    return 0;
}

// address=[0x1561210]
// Decompiled from void __thiscall IPileRole::NotifyChangeEcoSector(IPileRole *this, struct CPile *a2, int a3, int a4)
void IPileRole::NotifyChangeEcoSector(class CPile *_pPile, int a3, int a4) {
    if(_pPile->IsInOfferList()) {
        _pPile->CancelOffer(-1, a3);
        _pPile->Offer(-1, a4);
    }
}

// address=[0x1561250]
// Decompiled from int __thiscall IPileRole::SubjectDie(IPileRole *this, struct CPile *a2, int a3)
void IPileRole::SubjectDie(class CPile *_pPile, int a3) {
    BB_ASSERT(_pPile->GetBuildingId() == 0)
    BB_ASSERT(_pPile->FlagBits(ENTITY_FLAG_ATTACHED) == 0)
    BB_ASSERT(_pPile->GetRoleType() != IPileRole::PILE_ANYWHERE)
    BB_ASSERT(_pPile->AmountLeaving() == 0)
    BB_ASSERT(_pPile->AmountComing() == 0)

    _pPile->CancelCompleteOfferIfInOfferList(0);
    _pPile->ChangeRole(IPileRole::PILE_ANYWHERE);
}

// address=[0x1561350]
// Decompiled from void __thiscall IPileRole::SubjectStopped(IPileRole *this, struct CPile *a2)
void IPileRole::SubjectStopped(class CPile *a2) {

    ;
}

// address=[0x1561360]
// Decompiled from void __thiscall IPileRole::SubjectStarted(IPileRole *this, struct CPile *a2)
void IPileRole::SubjectStarted(class CPile *a2) {

    ;
}

// address=[0x1561370]
// Decompiled from _DWORD *__thiscall IPileRole::IPileRole(_DWORD *this, int a2)
IPileRole::IPileRole(std::istream &_rStream) : CPersistence() {
    int iFileFormatVersion;
    _rStream >> iFileFormatVersion;
    if(iFileFormatVersion != 1) {
        BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for IPileRole");
        throw CS4InvalidMapException();
    }
    _rStream >> this->m_uPileId;
}

// address=[0x15613f0]
// Decompiled from int __thiscall IPileRole::Store(struct CPersistence *this, struct std::ostream *a2)
void IPileRole::Store(std::ostream &_rStream) {

    CPersistence::Store(_rStream);
    unsigned int iFileFormatVersion = 1;
    _rStream << iFileFormatVersion;
    _rStream << this->m_uPileId;
}

// address=[0x1561440]
// Decompiled from char __thiscall IPileRole::ExecuteChangeGoodTypeUnforseen(IPileRole *this, struct CPile *a2, int a3)
bool IPileRole::ExecuteChangeGoodTypeUnforseen(class CPile *_pPile, int a3) {
    return _pPile->ExecuteChangeGoodTypeUnforseen(a3);
}

// address=[0x1560200]
// Decompiled from IPileRole *__thiscall IPileRole::IPileRole(IPileRole *this)
IPileRole::IPileRole(void) : CPersistence() {
    this->m_uPileId = 0;
}
