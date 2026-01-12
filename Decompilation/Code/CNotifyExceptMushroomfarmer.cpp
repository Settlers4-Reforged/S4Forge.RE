#include "CNotifyExceptMushroomfarmer.h"

// Definitions for class CNotifyExceptMushroomfarmer

// address=[0x1508120]
// Decompiled from CNotifyExceptMushroomfarmer *__thiscall CNotifyExceptMushroomfarmer::CNotifyExceptMushroomfarmer(
        CNotifyExceptMushroomfarmer *this)

 CNotifyExceptMushroomfarmer::CNotifyExceptMushroomfarmer(void) {
  
  INotifyFilter::INotifyFilter(this);
  *(_DWORD *)this = &CNotifyExceptMushroomfarmer::_vftable_;
  return this;
}


// address=[0x1508190]
// Decompiled from bool __thiscall CNotifyExceptMushroomfarmer::NotifyEntity(CNotifyExceptMushroomfarmer *this, struct IEntity *a2)

bool  CNotifyExceptMushroomfarmer::NotifyEntity(class IEntity const &) {
  
  return IEntity::ObjType((unsigned __int8 *)a2) != 1 || IEntity::Type((unsigned __int16 *)a2) != 53;
}


