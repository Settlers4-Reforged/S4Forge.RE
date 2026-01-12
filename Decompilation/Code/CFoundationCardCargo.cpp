#include "CFoundationCardCargo.h"

// Definitions for class CFoundationCardCargo

// address=[0x1539190]
// Decompiled from CCart::CFoundationCardCargo *__thiscall CCart::CFoundationCardCargo::CFoundationCardCargo(
        CCart::CFoundationCardCargo *this,
        const struct CCart::CFoundationCardCargo *a2)

 CCart::CFoundationCardCargo::CFoundationCardCargo(class CCart::CFoundationCardCargo const &) {
  
  *(_DWORD *)this = *(_DWORD *)a2;
  *((_DWORD *)this + 1) = *((_DWORD *)a2 + 1);
  *((_DWORD *)this + 2) = *((_DWORD *)a2 + 2);
  *((_DWORD *)this + 3) = *((_DWORD *)a2 + 3);
  *((_DWORD *)this + 4) = *((_DWORD *)a2 + 4);
  return this;
}


// address=[0x15391f0]
// Decompiled from CCart::CFoundationCardCargo *__thiscall CCart::CFoundationCardCargo::CFoundationCardCargo(
        CCart::CFoundationCardCargo *this,
        int a2,
        int a3,
        int a4,
        int a5)

 CCart::CFoundationCardCargo::CFoundationCardCargo(int,int,int,int) {
  
  *(_DWORD *)this = a3;
  *((_DWORD *)this + 1) = a2;
  *((_DWORD *)this + 2) = a4;
  *((_DWORD *)this + 3) = a5;
  *((_DWORD *)this + 4) = 0;
  return this;
}


// address=[0x1539240]
// Decompiled from CCart::CFoundationCardCargo *__thiscall CCart::CFoundationCardCargo::CFoundationCardCargo(
        CCart::CFoundationCardCargo *this)

 CCart::CFoundationCardCargo::CFoundationCardCargo(void) {
  
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  return this;
}


