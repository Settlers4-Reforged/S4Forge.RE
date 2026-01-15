#include "CSettlerSpiralWalk.h"

// Definitions for class CSettlerSpiralWalk

// address=[0x1470530]
// Decompiled from CSettlerSpiralWalk *__thiscall CSettlerSpiralWalk::CSettlerSpiralWalk(CSettlerSpiralWalk *this, int a2, int a3, int a4)
 CSettlerSpiralWalk::CSettlerSpiralWalk(int,int,int) {
  
  CSpiralWalk::CSpiralWalk(this, a2, a3, a4);
  return this;
}


// address=[0x1470940]
// Decompiled from int __thiscall CSettlerSpiralWalk::CurrentX(_DWORD *this)
int  CSettlerSpiralWalk::CurrentX(void)const {
  
  return this[4];
}


// address=[0x1470960]
// Decompiled from int __thiscall CSettlerSpiralWalk::CurrentY(_DWORD *this)
int  CSettlerSpiralWalk::CurrentY(void)const {
  
  return this[5];
}


// address=[0x1513a40]
// Decompiled from char __thiscall CSettlerSpiralWalk::NextSettlerId(CSettlerSpiralWalk *this, int *a2)
bool  CSettlerSpiralWalk::NextSettlerId(int &) {
  
  int v3; // [esp+0h] [ebp-14h]
  int v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch] BYREF
  int v6; // [esp+Ch] [ebp-8h] BYREF
  _DWORD *v7; // [esp+10h] [ebp-4h]

  v7 = this;
  while ( CSpiralWalk::NextXY(v7, &v6, &v5) )
  {
    v3 = CWorldManager::Index(v6, v5);
    v4 = CWorldManager::SettlerId(v3);
    if ( v4 )
    {
      v7[4] = v6;
      v7[5] = v5;
      *a2 = v4;
      return 1;
    }
  }
  return 0;
}


