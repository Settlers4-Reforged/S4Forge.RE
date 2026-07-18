#include "CStoragePileRole.h"

#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "CPile.h"

#include <iostream>

// Definitions for class CStoragePileRole

// address=[0x1402200]
// Decompiled from void __cdecl CStoragePileRole::New(struct std::_Facet_base *a1)
class CPersistence *__cdecl CStoragePileRole::New(std::istream &_rStream) {
    return new CStoragePileRole(_rStream);
}

// address=[0x1560260]
// Decompiled from void __thiscall CStoragePileRole::~CStoragePileRole(CStoragePileRole *this)
CStoragePileRole::~CStoragePileRole(void) = default;

// address=[0x1560320]
// Decompiled from int __thiscall CStoragePileRole::ClassID(CStoragePileRole *this)
unsigned long CStoragePileRole::ClassID(void) const {

    return CStoragePileRole::m_iClassID;
}

// address=[0x1560440]
// Decompiled from int __cdecl CStoragePileRole::Load(int a1)
class CStoragePileRole *__cdecl CStoragePileRole::Load(std::istream &_rStream) {
    return dynamic_cast<CStoragePileRole *>(CPersistence::New(_rStream));
}

// address=[0x1561900]
// Decompiled from void __thiscall CStoragePileRole::Init(CStoragePileRole *this, struct CPile *a2)
void CStoragePileRole::Init(class CPile *_pPile) {
    IPileRole::Init(_pPile);
    _pPile->SetRoleType(2);
    _pPile->SetOfferFlag(1);
    _pPile->OfferCompletePileIfPossible(0);
}

// address=[0x1561940]
// Decompiled from _DWORD *__thiscall CStoragePileRole::CStoragePileRole(_DWORD *this, int a2)
CStoragePileRole::CStoragePileRole(std::istream &_rStream) : IPileRole(_rStream) {

    unsigned int iFileFormatVersion;
    _rStream >> iFileFormatVersion;
    if(iFileFormatVersion != 1) {
        BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CStoragePileRole");
        throw CS4InvalidMapException();
    }
}

// address=[0x15619f0]
// Decompiled from int __thiscall CStoragePileRole::Store(void *this, struct std::ostream *a2)
void CStoragePileRole::Store(std::ostream &_rStream) {

    IPileRole::Store(_rStream);
    unsigned int iFileFormatVersion = 1;
    _rStream << iFileFormatVersion;
}

// address=[0x3d8be9c]
// [Decompilation failed for static unsigned long CStoragePileRole::m_iClassID]

// address=[0x15601d0]
// Decompiled from CStoragePileRole *__thiscall CStoragePileRole::CStoragePileRole(CStoragePileRole *this)
CStoragePileRole::CStoragePileRole(void) : IPileRole() {
}
