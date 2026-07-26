#if FALSE
#include "CTmpEntitiesRef.h"

// Definitions for class CTmpEntitiesRef

// address=[0x132e5e0]
// Decompiled from CTmpEntitiesRef *__thiscall CTmpEntitiesRef::CTmpEntitiesRef(CTmpEntitiesRef *this)
 CTmpEntitiesRef::CTmpEntitiesRef(void) {
  
  *(_DWORD *)this = CMapObjectMgr::EntityPtr(0);
  return this;
}


// address=[0x132e6b0]
// Decompiled from struct IEntity *__thiscall CTmpEntitiesRef::operator[](CTmpEntitiesRef *this, int a2)
class IEntity &  CTmpEntitiesRef::operator[](int a1)const {
  
  return CMapObjectMgr::EntityPtr(a2);
}


#endif // Already implemented
