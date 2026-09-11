#include "CNotifyExceptMushroomfarmer.h"

// Definitions for class CNotifyExceptMushroomfarmer

// address=[0x1508120]
// Decompiled from CNotifyExceptMushroomfarmer *__thiscall CNotifyExceptMushroomfarmer::CNotifyExceptMushroomfarmer(CNotifyExceptMushroomfarmer *this)
 CNotifyExceptMushroomfarmer::CNotifyExceptMushroomfarmer(void) {
  
  INotifyFilter::INotifyFilter(this);
  *(_DWORD *)this = &CNotifyExceptMushroomfarmer::_vftable_;
  return this;
}


// address=[0x1508190]
// Decompiled from bool __thiscall CNotifyExceptMushroomfarmer::NotifyEntity(CNotifyExceptMushroomfarmer *this, struct IEntity *a2)
bool  CNotifyExceptMushroomfarmer::NotifyEntity(class IEntity const & a2) {
  
  return IEntity::ObjType(a2) != SETTLER_OBJ || IEntity::Type(a2) != 53;
}


