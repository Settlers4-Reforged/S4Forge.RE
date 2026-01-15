#include "SSquadValue.h"

// Definitions for class SSquadValue

// address=[0x1301060]
// Decompiled from bool __thiscall SSquadValue::operator<(_DWORD *this, int a2)
bool  SSquadValue::operator<(struct SSquadValue const &)const {
  
  return this[1] < *(_DWORD *)(a2 + 4);
}


// address=[0x1301570]
// Decompiled from SSquadValue *__thiscall SSquadValue::MaxItem(SSquadValue *this)
void  SSquadValue::MaxItem(void) {
  
  SSquadValue *result; // eax

  result = this;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0x7FFFFFFF;
  return result;
}


