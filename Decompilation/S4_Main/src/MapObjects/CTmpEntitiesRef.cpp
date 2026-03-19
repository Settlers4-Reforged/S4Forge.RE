#include "CTmpEntitiesRef.h"

#include "CMapObjectMgr.h"

// Definitions for class CTmpEntitiesRef

// address=[0x132e5e0]
// Decompiled from CTmpEntitiesRef *__thiscall CTmpEntitiesRef::CTmpEntitiesRef(CTmpEntitiesRef *this)
CTmpEntitiesRef::CTmpEntitiesRef(void) {
    this->m_pTmpEntity = CMapObjectMgr::EntityPtr(0);
}


// address=[0x132e6b0]
// Decompiled from int __stdcall CTmpEntitiesRef::operator[](int a1)
class IEntity &CTmpEntitiesRef::operator[](int a1) const {
    return *CMapObjectMgr::EntityPtr(a1);
}


