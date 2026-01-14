#include "all_headers.h"

// Definitions for class CSectorSpiralWalk

// address=[0x13061f0]
// Decompiled from CSectorSpiralWalk *__thiscall CSectorSpiralWalk::CSectorSpiralWalk(  CSectorSpiralWalk *this,  int a2,  int a3,  int a4,  int a5)
 CSectorSpiralWalk::CSectorSpiralWalk(int,int,int,int) {
  
  CSpiralWalk::CSpiralWalk(this, a2, a3, a4);
  *((_DWORD *)this + 4) = a5;
  return this;
}


// address=[0x1306790]
// Decompiled from char __thiscall CSectorSpiralWalk::NextXY(CSectorSpiralWalk *this, int *a2, int *a3)
bool  CSectorSpiralWalk::NextXY(int &,int &) {
  
  while ( CSpiralWalk::NextXY(this, a2, a3) )
  {
    if ( CWorldManager::SectorId(*a2, *a3) == *((_DWORD *)this + 4) )
      return 1;
  }
  return 0;
}


