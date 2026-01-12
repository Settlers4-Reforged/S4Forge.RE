#include "CS4ErrorException.h"

// Definitions for class CS4ErrorException

// address=[0x1481190]
// Decompiled from CS4ErrorException *__thiscall CS4ErrorException::CS4ErrorException(
        CS4ErrorException *this,
        const struct CErrorMessageId *a2)

 CS4ErrorException::CS4ErrorException(class CErrorMessageId const &) {
  
  CBBException::CBBException(this);
  *(_DWORD *)this = &CS4ErrorException::_vftable_;
  CErrorMessageId::CErrorMessageId((CS4ErrorException *)((char *)this + 4), a2);
  return this;
}


// address=[0x1481200]
// Decompiled from char __thiscall CS4ErrorException::GetErrorMessage(CS4ErrorException *this, char *a2, unsigned int a3)

bool  CS4ErrorException::GetErrorMessage(char *,unsigned int) {
  
  int v4; // [esp+4h] [ebp-8h]
  unsigned int i; // [esp+8h] [ebp-4h]

  if ( !a2 )
    return 1;
  if ( !a3 )
    return 1;
  *a2 = 0;
  v4 = (**(int (__thiscall ***)(void *, char *))g_pErrorMessages)(g_pErrorMessages, (char *)this + 4);
  if ( !v4 )
    return 1;
  for ( i = 0; i < a3 - 1 || *(_BYTE *)(i + v4); ++i )
    a2[i] = *(_BYTE *)(i + v4);
  a2[i] = 0;
  return 1;
}


// address=[0x14813b0]
// Decompiled from CBBException *__thiscall CS4ErrorException::~CS4ErrorException(CS4ErrorException *this)

 CS4ErrorException::~CS4ErrorException(void) {
  
  return CBBException::~CBBException(this);
}


