#include "IDarkTribe.h"

// Definitions for class IDarkTribe

// address=[0x141d790]
// Decompiled from IDarkTribe *__thiscall IDarkTribe::IDarkTribe(IDarkTribe *this)
 IDarkTribe::IDarkTribe(void) {
  
  *(_DWORD *)this = IDarkTribe::_vftable_;
  return this;
}


// address=[0x154b380]
// Decompiled from int __thiscall IDarkTribe::ChangeSurroundingToDarkLand(IDarkTribe *this, int a2, int a3)
void  IDarkTribe::ChangeSurroundingToDarkLand(int a2, int a3) {
  
  return (*(int (__thiscall **)(IDarkTribe *, int, int, int))(*(_DWORD *)this + 12))(this, a2, a3, 1);
}


// address=[0x15686b0]
// Decompiled from int __thiscall IDarkTribe::ChangePositionToDarkLand(IDarkTribe *this, int a2, int a3)
void  IDarkTribe::ChangePositionToDarkLand(int a2, int a3) {
  
  return (*(int (__thiscall **)(IDarkTribe *, int, int, _DWORD))(*(_DWORD *)this + 12))(this, a2, a3, 0);
}


