#include "all_headers.h"

// Definitions for class CSpiralWalk

// address=[0x1306230]
// Decompiled from CSpiralWalk *__thiscall CSpiralWalk::CSpiralWalk(CSpiralWalk *this, int a2, int a3, int a4)
 CSpiralWalk::CSpiralWalk(int,int,int) {
  
  *((_DWORD *)this + 1) = a2;
  *((_DWORD *)this + 2) = a3;
  *((_DWORD *)this + 3) = CSpiralOffsets::Last(a4);
  *(_DWORD *)this = 0;
  return this;
}


// address=[0x1306800]
// Decompiled from char __thiscall CSpiralWalk::NextXY(_DWORD *this, int *a2, int *a3)
bool  CSpiralWalk::NextXY(int &,int &) {
  
  int v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+4h] [ebp-8h]

  while ( *this <= this[3] )
  {
    v5 = this[1] + CSpiralOffsets::DeltaX(*this);
    v4 = this[2] + CSpiralOffsets::DeltaY(*this);
    ++*this;
    if ( (unsigned __int8)CWorldManager::InWorld(v5, v4) )
    {
      *a2 = v5;
      *a3 = v4;
      return 1;
    }
  }
  return 0;
}


// address=[0x1509f30]
// Decompiled from int __thiscall CSpiralWalk::CurrentRadius(CSpiralWalk *this)
int  CSpiralWalk::CurrentRadius(void)const {
  
  return CSpiralOffsets::Radius(*(_DWORD *)this);
}


