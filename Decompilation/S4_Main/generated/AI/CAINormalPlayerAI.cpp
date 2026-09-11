#include "CAINormalPlayerAI.h"

// Definitions for class CAINormalPlayerAI

// address=[0x131a540]
// Decompiled from CAINormalPlayerAI *__thiscall CAINormalPlayerAI::CAINormalPlayerAI(CAINormalPlayerAI *this, int a2)
 CAINormalPlayerAI::CAINormalPlayerAI(int a2) {
  
  CAIPlayerAI::CAIPlayerAI((CAIPlayerAI *)this, a2, 0);
  *(_DWORD *)this = CAINormalPlayerAI::_vftable_;
  *((_DWORD *)this + 1) = &CAINormalPlayerAI::`vftable';
  return this;
}


// address=[0x131a580]
// Decompiled from int __thiscall CAINormalPlayerAI::Load(CAIPlayerAI *this, struct IS4Chunk *a2)
void  CAINormalPlayerAI::Load(class IS4Chunk & a2) {
  
  int v3; // [esp+0h] [ebp-14h]
  int NormalSectorAI; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]

  ((void (__thiscall *)(struct IS4Chunk *, int))a2->LoadSignature)(a2, -1517215744);
  if ( ((int (__thiscall *)(struct IS4Chunk *, _DWORD, int))a2->LoadUnsigned32)(a2, 0, 1) != 0 )
  {
    CAIPlayerAI::Load(this, a2);
    ((void (__thiscall *)(struct IS4Chunk *, int))a2->LoadSignature)(a2, -1517215742);
    v3 = a2->LoadUnsigned32_(a2);
    for ( i = 0;
          i < v3;
          ++i )
    {
      NormalSectorAI = CAISectorAI::CreateNormalSectorAI((pairNode *)((char *)this - 4), 0);
      (*(void (__thiscall **)(int, struct IS4Chunk *))(*(_DWORD *)NormalSectorAI + 20))(NormalSectorAI, a2);
      ((void (__stdcall *)(int))TAIStaticPtrVector<CAISectorAI,8>::PushBack)(NormalSectorAI);
    }
  }
  else
  {
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 8))((char *)this - 4);
  }
  return ((int (__thiscall *)(struct IS4Chunk *, int))a2->LoadSignature)(a2, -1517215743);
}


// address=[0x131a670]
// Decompiled from int __thiscall CAINormalPlayerAI::Save(CAIPlayerAI *this, struct IS4Chunk *a2)
void  CAINormalPlayerAI::Save(class IS4Chunk & a2) {
  
  int v3; // [esp+0h] [ebp-10h]
  int v4; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  ((void (__thiscall *)(struct IS4Chunk *, int))a2->SaveSignature)(a2, -1517215744);
  ((void (__thiscall *)(struct IS4Chunk *, int))a2->SaveUnsigned32)(a2, 1);
  CAIPlayerAI::Save(this, a2);
  ((void (__thiscall *)(struct IS4Chunk *, int))a2->SaveSignature)(a2, -1517215742);
  v4 = TAIStaticPtrVector<CAISectorAI,8>::Size(&this->m_cScheduler.m_pFirstAgent);
  ((void (__thiscall *)(struct IS4Chunk *, int))a2->SaveUnsigned32)(a2, v4);
  for ( i = 0;
        i < v4;
        ++i )
  {
    v3 = ((int (__stdcall *)(int))TAIStaticPtrVector<CAISectorAI,8>::operator[])(i);
    (*(void (__thiscall **)(int, struct IS4Chunk *))(*(_DWORD *)v3 + 24))(v3, a2);
  }
  return ((int (__thiscall *)(struct IS4Chunk *, int))a2->SaveSignature)(a2, -1517215743);
}


// address=[0x131a730]
// Decompiled from int __thiscall CAINormalPlayerAI::Init(CAIPlayerAI *this)
void  CAINormalPlayerAI::Init(void) {
  
  CAIPlayerAI::Init(this);
  CAIPlayerAI::FillGeneralReservoir(this);
  return CAIPlayerAI::ScanForNewSectors(this);
}


