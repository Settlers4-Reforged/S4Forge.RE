#if FALSE
#include "CAIRegion.h"

// Definitions for class CAIRegion

// address=[0x1311ef0]
// Decompiled from bool __thiscall CAIRegion::Used(CAIRegion *this)
bool  CAIRegion::Used(void)const {
  
  return this->m_iUses > 0;
}


// address=[0x13115f0]
// Decompiled from void __thiscall CAIRegion::Load(CAIRegion *this, struct IS4Chunk *a2)
void  CAIRegion::Load(class IS4Chunk & a2) {
  
  this->dword0 = a2->LoadUnsigned32_(a2);
  this->dword4 = a2->LoadUnsigned32_(a2);
  this->m_iUses = a2->LoadUnsigned32_(a2);
}


// address=[0x1311640]
// Decompiled from void __thiscall CAIRegion::Save(CAIRegion *this, struct IS4Chunk *a2)
void  CAIRegion::Save(class IS4Chunk & a2) {
  
  a2->SaveUnsigned32(this->dword0);
  a2->SaveUnsigned32(this->dword4);
  a2->SaveUnsigned32(this->m_iUses);
}


// address=[0x1311c80]
// Decompiled from void __thiscall CAIRegion::Clear(CAIRegion *this)
void  CAIRegion::Clear(void) {
  
  CAIRegion::DefineRegion(this, 0, 0, 0);
}


// address=[0x1311ca0]
// Decompiled from void __thiscall CAIRegion::DefineRegion(CAIRegion *this, int a2, int a3, int a4)
void  CAIRegion::DefineRegion(int a2, int a3, int a4) {
  
  this->dword0 = a2;
  this->dword4 = a3;
  this->m_iUses = a4;
}


#endif // Already implemented
