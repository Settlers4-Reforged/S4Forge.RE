#include "CAIRegion.h"

// Definitions for class CAIRegion

// address=[0x1311ef0]
// Decompiled from bool __thiscall CAIRegion::Used(CAIRegion *this)
bool  CAIRegion::Used(void)const {
  
  return *((_DWORD *)this + 2) > 0;
}


// address=[0x13115f0]
// Decompiled from int __thiscall CAIRegion::Load(CAIRegion *this, struct IS4Chunk *a2)
void  CAIRegion::Load(class IS4Chunk & a2) {
  
  int result; // eax

  *(_DWORD *)this = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 1) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  result = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 2) = result;
  return result;
}


// address=[0x1311640]
// Decompiled from int __thiscall CAIRegion::Save(CAIRegion *this, struct IS4Chunk *a2)
void  CAIRegion::Save(class IS4Chunk & a2) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *(_DWORD *)this);
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 1));
  return (*(int (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 2));
}


// address=[0x1311c80]
// Decompiled from void __thiscall CAIRegion::Clear(CAIRegion *this)
void  CAIRegion::Clear(void) {
  
  CAIRegion::DefineRegion(this, 0, 0, 0);
}


// address=[0x1311ca0]
// Decompiled from int __thiscall CAIRegion::DefineRegion(CAIRegion *this, int a2, int a3, int a4)
void  CAIRegion::DefineRegion(int a2, int a3, int a4) {
  
  int result; // eax

  *(_DWORD *)this = a2;
  result = a3;
  *((_DWORD *)this + 1) = a3;
  *((_DWORD *)this + 2) = a4;
  return result;
}


