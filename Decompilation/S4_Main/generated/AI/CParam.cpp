#include "CParam.h"

// Definitions for class CParam

// address=[0x2f3e8a0]
// Decompiled from CParam *__thiscall CParam::CParam(CParam *this)
 CParam::CParam(void) {
  
  CDynListEntry::CDynListEntry(this);
  *(_DWORD *)this = &CParam::_vftable_;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  return this;
}


// address=[0x2f3e8f0]
// Decompiled from CParam *__thiscall CParam::CParam(CParam *this, int a2, int a3, int a4, int a5)
 CParam::CParam(int a2, int a3, int a4, int a5) {
  
  CDynListEntry::CDynListEntry(this);
  *(_DWORD *)this = &CParam::_vftable_;
  *((_DWORD *)this + 3) = a2;
  *((_DWORD *)this + 4) = a3;
  *((_DWORD *)this + 5) = a4;
  *((_DWORD *)this + 6) = a5;
  return this;
}


// address=[0x2f3e940]
// Decompiled from CParam *__thiscall CParam::CParam(CParam *this, struct CParam *a2)
 CParam::CParam(class CParam *) {
  
  CDynListEntry::CDynListEntry(this);
  *(_DWORD *)this = &CParam::_vftable_;
  *((_DWORD *)this + 3) = *((_DWORD *)a2 + 3);
  *((_DWORD *)this + 4) = *((_DWORD *)a2 + 4);
  *((_DWORD *)this + 5) = *((_DWORD *)a2 + 5);
  *((_DWORD *)this + 6) = *((_DWORD *)a2 + 6);
  return this;
}


// address=[0x2f3e9a0]
// Decompiled from void __thiscall CParam::~CParam(CParam *this)
 CParam::~CParam(void) {
  
  *(_DWORD *)this = &CParam::_vftable_;
  CDynListEntry::~CDynListEntry(this);
}


// address=[0x2f3e9c0]
// Decompiled from _DWORD *__thiscall CParam::SetParameter(_DWORD *this, int a2, int a3, int a4, int a5)
void  CParam::SetParameter(int a2, int a3, int a4, int a5) {
  
  _DWORD *result; // eax

  this[3] = a2;
  this[4] = a3;
  this[5] = a4;
  result = this;
  this[6] = a5;
  return result;
}


// address=[0x2f3ea00]
// Decompiled from _DWORD *__thiscall CParam::SetParameterX(_DWORD *this, _DWORD *a2, _DWORD *a3)
void  CParam::SetParameterX(int a2, int a3) {
  
  _DWORD *result; // eax

  result = a2;
  switch ( (unsigned int)a2 )
  {
    case 1u:
      result = this;
      this[3] = a3;
      break;
    case 2u:
      result = a3;
      this[4] = a3;
      break;
    case 3u:
      this[5] = a3;
      break;
    case 4u:
      result = this;
      this[6] = a3;
      break;
    default:
      return result;
  }
  return result;
}


// address=[0x2f3ea70]
// Decompiled from BOOL __thiscall CParam::ParamAreEqual(CParam *this, struct CParam *a2)
int  CParam::ParamAreEqual(class CParam * a2) {
  
  return *((_DWORD *)this + 3) == *((_DWORD *)a2 + 3)
      && *((_DWORD *)this + 4) == *((_DWORD *)a2 + 4)
      && *((_DWORD *)this + 5) == *((_DWORD *)a2 + 5)
      && *((_DWORD *)this + 6) == *((_DWORD *)a2 + 6);
}


