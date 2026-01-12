#include "CErrorMessages.h"

// Definitions for class CErrorMessages

// address=[0x14812a0]
// Decompiled from char *__thiscall CErrorMessages::GetErrorMessage(CErrorMessages *this, const struct CErrorMessageId *a2)

char const *  CErrorMessages::GetErrorMessage(class CErrorMessageId const &)const {
  
  int Id; // [esp+4h] [ebp-4h]

  Id = CErrorMessageId::GetId(a2);
  if ( Id != 1 )
    Id = 0;
  return off_3D89A44[2 * Id];
}


// address=[0x1481360]
// Decompiled from CErrorMessages *__thiscall CErrorMessages::CErrorMessages(CErrorMessages *this)

 CErrorMessages::CErrorMessages(void) {
  
  IErrorMessages::IErrorMessages(this);
  *(_DWORD *)this = &CErrorMessages::_vftable_;
  return this;
}


