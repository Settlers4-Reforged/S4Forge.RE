#include "CAIConfigIntEx.h"

// Definitions for class CAIConfigIntEx

// address=[0x131e810]
// Decompiled from CAIConfigIntEx *__thiscall CAIConfigIntEx::CAIConfigIntEx(CAIConfigIntEx *this, const char *a2, int a3, int a4, int a5)
 CAIConfigIntEx::CAIConfigIntEx(char const * a2, int a3, int a4, int a5) {
  
  int v6; // [esp+4h] [ebp-Ch]
  int v7; // [esp+8h] [ebp-8h]

  if ( a5 == 0x80000000 )
  {
    if ( a4 == 0x80000000 )
      v7 = a3;
    else
      v7 = a4;
    v6 = v7;
  }
  else
  {
    v6 = a5;
  }
  if ( a4 == 0x80000000 )
    TStaticConfigIntArray<3>::TStaticConfigIntArray<3>(off_366E0C8, a2, a3, a3, v6);
  else
    TStaticConfigIntArray<3>::TStaticConfigIntArray<3>(off_366E0C8, a2, a3, a4, v6);
  *(_DWORD *)this = &CAIConfigIntEx::_vftable_;
  *((_DWORD *)this + 5) = a2;
  return this;
}


// address=[0x131ea80]
// Decompiled from int __thiscall CAIConfigIntEx::~CAIConfigIntEx(CAIConfigIntEx *this)
 CAIConfigIntEx::~CAIConfigIntEx(void) {
  
  return TStaticConfigIntArray<3>::~TStaticConfigIntArray<3>(this, this);
}


// address=[0x131ecd0]
// Decompiled from int __thiscall CAIConfigIntEx::Name(CAIConfigIntEx *this)
char const *  CAIConfigIntEx::Name(void)const {
  
  return *((_DWORD *)this + 5);
}


