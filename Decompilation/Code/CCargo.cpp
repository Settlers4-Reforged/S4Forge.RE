#include "CCargo.h"

// Definitions for class CCargo

// address=[0x159af90]
// Decompiled from CFerryShip::CCargo *__thiscall CFerryShip::CCargo::CCargo(
        CFerryShip::CCargo *this,
        const struct CFerryShip::CCargo *a2)

 CFerryShip::CCargo::CCargo(class CFerryShip::CCargo const &) {
  
  *(_DWORD *)this = *(_DWORD *)a2;
  *((_DWORD *)this + 1) = *((_DWORD *)a2 + 1);
  *((_DWORD *)this + 2) = *((_DWORD *)a2 + 2);
  *((_DWORD *)this + 3) = *((_DWORD *)a2 + 3);
  *((_DWORD *)this + 4) = *((_DWORD *)a2 + 4);
  *((_BYTE *)this + 20) = *((_BYTE *)a2 + 20);
  *((_BYTE *)this + 21) = *((_BYTE *)a2 + 21);
  return this;
}


// address=[0x159b010]
// Decompiled from CFerryShip::CCargo *__thiscall CFerryShip::CCargo::CCargo(CFerryShip::CCargo *this, int a2, int a3, int a4, int a5)

 CFerryShip::CCargo::CCargo(int,int,int,int) {
  
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  *((_DWORD *)this + 2) = a4;
  *((_DWORD *)this + 3) = a5;
  *((_DWORD *)this + 4) = 0;
  *((_BYTE *)this + 20) = 0;
  *((_BYTE *)this + 21) = 0;
  return this;
}


// address=[0x159b070]
// Decompiled from CFerryShip::CCargo *__thiscall CFerryShip::CCargo::CCargo(CFerryShip::CCargo *this)

 CFerryShip::CCargo::CCargo(void) {
  
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_BYTE *)this + 20) = 0;
  *((_BYTE *)this + 21) = 0;
  return this;
}


// address=[0x159bab0]
// Decompiled from int __thiscall CFerryShip::CCargo::GetCargoSize(CFerryShip::CCargo *this)

int  CFerryShip::CCargo::GetCargoSize(void) {
  
  return CFerryShip::GetCargoSize(*(_DWORD *)this, *((_DWORD *)this + 1));
}


