#include "CBuildingSitePileRole.h"

#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "CPile.h"

#include <iostream>

// Definitions for class CBuildingSitePileRole

// address=[0x13ffdc0]
// Decompiled from void __cdecl CBuildingSitePileRole::New(struct std::_Facet_base *a1)
class CPersistence *__cdecl CBuildingSitePileRole::New(std::istream &a1) {
    return new CBuildingSitePileRole(a1);
}

// address=[0x155b3b0]
// Decompiled from void __thiscall CBuildingSitePileRole::Init(CBuildingSitePileRole *this, struct CPile *a2)
void CBuildingSitePileRole::Init(class CPile *_pPile) {
    IPileRole::Init(_pPile);
    _pPile->SetRoleType(5u);
    _pPile->SetOfferFlag(0);
}

// address=[0x155b3e0]
// Decompiled from void __thiscall CBuildingSitePileRole::Increase(CBuildingSitePileRole *this, CPile *_pPile, int _iAmount)
void CBuildingSitePileRole::Increase(CPile *_pPile, int _iAmount) {
    BB_ASSERT(_pPile != 0)
    BB_ASSERT(_iAmount > 0)
    BB_ASSERT(!_pPile->IsInOfferList())
    BB_ASSERT(!_pPile->GetOfferFlag())
    BB_ASSERT(_pPile->GetBuildingId() != 0)
    g_cBuildingMgr[_pPile->GetBuildingId()].GoodArrive(_pPile->GetGoodType());
}

// address=[0x155b4f0]
// Decompiled from void __thiscall CBuildingSitePileRole::SubjectStopped(CBuildingSitePileRole *this, struct CPile *_pPile)
void CBuildingSitePileRole::SubjectStopped(class CPile *_pPile) {
    BB_ASSERT(_pPile->AmountLeaving() == 0)
    _pPile->NotifyTargetDieAndDetachAllObservers();
    _pPile->SetOfferFlag(1u);
    _pPile->OfferCompletePileIfPossible(0);
}

// address=[0x155b550]
// Decompiled from void __thiscall CBuildingSitePileRole::SubjectStarted(CBuildingSitePileRole *this, struct CPile *_pPile)
void CBuildingSitePileRole::SubjectStarted(class CPile *_pPile) {
    BB_ASSERT(_pPile->AmountComing() == 0)
    _pPile->NotifyTargetDieAndDetachAllObservers();
    _pPile->CancelCompleteOfferIfInOfferList(0);
    _pPile->SetOfferFlag(0);
}

// address=[0x155b5b0]
// Decompiled from CBuildingSitePileRole *__thiscall CBuildingSitePileRole::CBuildingSitePileRole(CBuildingSitePileRole *this, int a2)
CBuildingSitePileRole::CBuildingSitePileRole(std::istream &_rStream) : IPileRole(_rStream) {
    unsigned int iFileFormatVersion;
    _rStream >> iFileFormatVersion;
    if(iFileFormatVersion != 1) {
        BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CBuildingSitePileRole");
        throw CS4InvalidMapException();
    }
}

// address=[0x155b660]
// Decompiled from void __thiscall CBuildingSitePileRole::Store(CBuildingSitePileRole *this, struct std::ostream *a2)
void CBuildingSitePileRole::Store(std::ostream &_rStream) {
    IPileRole::Store(_rStream);
    unsigned int iFileFormatVersion = 1;
    _rStream << iFileFormatVersion;
}

// address=[0x155b750]
// Decompiled from IPileRole *__thiscall CBuildingSitePileRole::~CBuildingSitePileRole(CBuildingSitePileRole *this)
CBuildingSitePileRole::~CBuildingSitePileRole(void) = default;

// address=[0x155b7b0]
// Decompiled from int __thiscall CBuildingSitePileRole::ClassID(CBuildingSitePileRole *this)
unsigned long CBuildingSitePileRole::ClassID(void) const {
    return CBuildingSitePileRole::m_iClassID;
}

// address=[0x1560380]
// Decompiled from int __cdecl CBuildingSitePileRole::Load(struct std::istream *a1)
class CBuildingSitePileRole *__cdecl CBuildingSitePileRole::Load(std::istream &_rStream) {
    return (CBuildingSitePileRole *)CPersistence::New(_rStream);
}

// address=[0x3d8bbb8]
// [Decompilation failed for static unsigned long CBuildingSitePileRole::m_iClassID]

// address=[0x1560140]
// Decompiled from CBuildingSitePileRole *__thiscall CBuildingSitePileRole::CBuildingSitePileRole(CBuildingSitePileRole *this)
CBuildingSitePileRole::CBuildingSitePileRole(void) : IPileRole() {
}
