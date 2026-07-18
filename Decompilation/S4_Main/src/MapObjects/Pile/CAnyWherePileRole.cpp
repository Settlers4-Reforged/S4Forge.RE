#include "CAnyWherePileRole.h"

#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "CPile.h"
#include "CPileMgr.h"

// Definitions for class CAnyWherePileRole

// address=[0x13ffaa0]
// Decompiled from void __cdecl CAnyWherePileRole::New(struct std::_Facet_base *a1)
class CPersistence *__cdecl CAnyWherePileRole::New(std::istream &a1) {
    return new CAnyWherePileRole(a1);
}

// address=[0x155af40]
// Decompiled from void __thiscall CAnyWherePileRole::Init(IPileRole *this, struct CPile *a2)
void CAnyWherePileRole::Init(class CPile *_pPile) {
    IPileRole::Init(_pPile);
    _pPile->ClearAllQueuedEvents();
    _pPile->SetRoleType(3u);
    _pPile->SetOfferFlag(1u);
    _pPile->SetFlagBits(ENTITY_FLAG_Visible);
    if(_pPile->Amount()) {
        _pPile->OfferCompletePileIfPossible(0);
        _pPile->RegisterForLogicUpdate(31);
    } else {
        g_cPileMgr.DeletePile(this->m_uPileId);
    }
}

// address=[0x155afc0]
// Decompiled from int __thiscall CAnyWherePileRole::LogicUpdate(CAnyWherePileRole *this, struct CPile *a2)
void CAnyWherePileRole::LogicUpdate(class CPile *_pPile) {
    _pPile->RequestSpaceIfPossible();
    _pPile->RegisterForLogicUpdate(31);
}

// address=[0x155afe0]
// Decompiled from void __thiscall CAnyWherePileRole::Empty(CAnyWherePileRole *this, IEntity *a2)
void CAnyWherePileRole::Empty(class CPile *_pPile) {
    g_cPileMgr.DeletePile(_pPile->EntityId());
}

// address=[0x155b000]
// Decompiled from char __thiscall CAnyWherePileRole::ChangeGoodTypeUnforseen(CAnyWherePileRole *this, struct CPile *a2, int a3)
bool CAnyWherePileRole::ChangeGoodTypeUnforseen(class CPile *a2, int a3) {
    return ExecuteChangeGoodTypeUnforseen(a2, a3);
}

// address=[0x155b020]
// Decompiled from void __thiscall CAnyWherePileRole::Occupied(CAnyWherePileRole *this, struct CPile *a2, _DWORD *a3)
void CAnyWherePileRole::Occupied(class CPile *_pPile, int a3) {
    _pPile->OfferCompletePileIfPossible(a3);
}

// address=[0x155b040]
// Decompiled from char __thiscall CAnyWherePileRole::SetFree(CAnyWherePileRole *this, CPile *a2, int a3)
bool CAnyWherePileRole::SetFree(class CPile *_pPile, int _iEcoSectorId) {
    _pPile->CancelCompleteOfferIfInOfferList(_iEcoSectorId);
    return 0;
}

// address=[0x155b060]
// Decompiled from CAnyWherePileRole *__thiscall CAnyWherePileRole::CAnyWherePileRole(CAnyWherePileRole *this, int a2)
CAnyWherePileRole::CAnyWherePileRole(std::istream &_rStream) : IPileRole(_rStream) {
    if(Serial::LoadVersion(_rStream) != 1) {
        BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CAnyWherePileRole");
        throw CS4InvalidMapException();
    }
}

// address=[0x155b110]
// Decompiled from int __thiscall CAnyWherePileRole::Store(struct CPersistence *this, struct std::ostream *a2)
void CAnyWherePileRole::Store(std::ostream &_rStream) {
    IPileRole::Store(_rStream);
    Serial::StoreVersion(_rStream, 1);
}

// address=[0x155b1c0]
// Decompiled from IPileRole *__thiscall CAnyWherePileRole::~CAnyWherePileRole(CAnyWherePileRole *this)
CAnyWherePileRole::~CAnyWherePileRole(void) = default;

// address=[0x155b2a0]
// Decompiled from int __thiscall CAnyWherePileRole::ClassID(CAnyWherePileRole *this)
unsigned long CAnyWherePileRole::ClassID(void) const {
    return CAnyWherePileRole::m_iClassID;
}

// address=[0x155b380]
// Decompiled from void __thiscall CAnyWherePileRole::SubjectDie(CAnyWherePileRole *this, struct CPile *a2, int a3)
void CAnyWherePileRole::SubjectDie(class CPile *a2, int a3) {

    ;
}

// address=[0x155b390]
// Decompiled from void __thiscall CAnyWherePileRole::SubjectStarted(CAnyWherePileRole *this, struct CPile *a2)
void CAnyWherePileRole::SubjectStarted(class CPile *a2) {

    ;
}

// address=[0x155b3a0]
// Decompiled from void __thiscall CAnyWherePileRole::SubjectStopped(CAnyWherePileRole *this, struct CPile *a2)
void CAnyWherePileRole::SubjectStopped(class CPile *a2) {

    ;
}

// address=[0x1560340]
// Decompiled from int __cdecl CAnyWherePileRole::Load(struct std::istream *a1)
class CAnyWherePileRole *__cdecl CAnyWherePileRole::Load(std::istream &a1) {
    return dynamic_cast<CAnyWherePileRole *>(CPersistence::New(a1));
}

// address=[0x3d8bbb4]
// [Decompilation failed for static unsigned long CAnyWherePileRole::m_iClassID]

// address=[0x1560110]
// Decompiled from CAnyWherePileRole *__thiscall CAnyWherePileRole::CAnyWherePileRole(CAnyWherePileRole *this)
CAnyWherePileRole::CAnyWherePileRole(void) : IPileRole() {
}
