#include "CAINormalPlayerAI.h"

// Definitions for class CAINormalPlayerAI

// address=[0x131a540]
// Decompiled from CAINormalPlayerAI *__thiscall CAINormalPlayerAI::CAINormalPlayerAI(CAINormalPlayerAI *this, int a2)

 CAINormalPlayerAI::CAINormalPlayerAI(int) {
  
  CAIPlayerAI::CAIPlayerAI(this, a2, 0);
  *(_DWORD *)this = CAINormalPlayerAI::_vftable_;
  *((_DWORD *)this + 1) = &CAINormalPlayerAI::`vftable';
  return this;
}


// address=[0x131a580]
// Decompiled from int __thiscall CAINormalPlayerAI::Load(CAINormalPlayerAI *this, struct IS4Chunk *a2)

void  CAINormalPlayerAI::Load(class IS4Chunk &) {
  
  int v3; // [esp+0h] [ebp-14h]
  int NormalSectorAI; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]

  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517215744);
  if ( (*(int (__thiscall **)(struct IS4Chunk *, _DWORD, int))(*(_DWORD *)a2 + 4))(a2, 0, 1) )
  {
    CAIPlayerAI::Load(this, a2);
    (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517215742);
    v3 = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
    for ( i = 0; i < v3; ++i )
    {
      NormalSectorAI = CAISectorAI::CreateNormalSectorAI((CAINormalPlayerAI *)((char *)this - 4), 0);
      (*(void (__thiscall **)(int, struct IS4Chunk *))(*(_DWORD *)NormalSectorAI + 20))(NormalSectorAI, a2);
      TAIStaticPtrVector<CAISectorAI,8>::PushBack(NormalSectorAI);
    }
  }
  else
  {
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 8))((char *)this - 4);
  }
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1517215743);
}


// address=[0x131a670]
// Decompiled from int __thiscall CAINormalPlayerAI::Save(CAINormalPlayerAI *this, struct IS4Chunk *a2)

void  CAINormalPlayerAI::Save(class IS4Chunk &) {
  
  int v3; // [esp+0h] [ebp-10h]
  int v4; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517215744);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 1);
  CAIPlayerAI::Save(this, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517215742);
  v4 = TAIStaticPtrVector<CAISectorAI,8>::Size((char *)this + 68);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, v4);
  for ( i = 0; i < v4; ++i )
  {
    v3 = TAIStaticPtrVector<CAISectorAI,8>::operator[](i);
    (*(void (__thiscall **)(int, struct IS4Chunk *))(*(_DWORD *)v3 + 24))(v3, a2);
  }
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1517215743);
}


// address=[0x131a730]
// Decompiled from int __thiscall CAINormalPlayerAI::Init(CAINormalPlayerAI *this)

void  CAINormalPlayerAI::Init(void) {
  
  CAIPlayerAI::Init(this);
  CAIPlayerAI::FillGeneralReservoir(this);
  return CAIPlayerAI::ScanForNewSectors(this);
}


