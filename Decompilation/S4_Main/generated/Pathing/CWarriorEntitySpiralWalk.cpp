#include "CWarriorEntitySpiralWalk.h"

// Definitions for class CWarriorEntitySpiralWalk

// address=[0x1470560]
// Decompiled from CWarriorEntitySpiralWalk *__thiscall CWarriorEntitySpiralWalk::CWarriorEntitySpiralWalk(  CWarriorEntitySpiralWalk *this,  int a2,  int a3,  int a4,  int a5,  int a6)
 CWarriorEntitySpiralWalk::CWarriorEntitySpiralWalk(int a2, int a3, int a4, int a5, int a6) {
  
  CSettlerSpiralWalk::CSettlerSpiralWalk(this, a2, a3, a4);
  *((_DWORD *)this + 6) = a5;
  *((_DWORD *)this + 7) = a6;
  return this;
}


// address=[0x15e2d90]
// Decompiled from char __thiscall CWarriorEntitySpiralWalk::NextEntity(CWarriorEntitySpiralWalk *this, struct IEntity **a2)
bool  CWarriorEntitySpiralWalk::NextEntity(class IEntity * & a2) {
  
  int v2; // eax
  int v4; // [esp+0h] [ebp-18h]
  int v5; // [esp+Ch] [ebp-Ch] BYREF
  CSettlerSpiralWalk *v6; // [esp+10h] [ebp-8h]
  unsigned __int8 *v7; // [esp+14h] [ebp-4h]

  v6 = this;
  while ( CSettlerSpiralWalk::NextSettlerId(v6, &v5) )
  {
    v7 = (unsigned __int8 *)CMapObjectMgr::Entity(v5);
    if ( (((unsigned int)&loc_1FFFFFF + 1) & IEntity::Flags(v7)) != 0
      && (*((_DWORD *)v6 + 7) & (1 << IEntity::WarriorType())) != 0 )
    {
      v4 = IEntity::OwnerId(v7);
      v2 = CAlliances::PlayerBit(v4);
      if ( (*((_DWORD *)v6 + 6) & v2) != 0 )
      {
        *a2 = (struct IEntity *)v7;
        return 1;
      }
    }
  }
  return 0;
}


