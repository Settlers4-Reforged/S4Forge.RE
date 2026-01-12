#include "CPlayerIterator.h"

// Definitions for class CPlayerIterator

// address=[0x1314f30]
// Decompiled from bool __thiscall CPlayerIterator::Init(CPlayerIterator *this, int a2)

bool  CPlayerIterator::Init(int) {
  
  int v3; // [esp+4h] [ebp-14h]
  int v4; // [esp+8h] [ebp-10h]
  int j; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  v4 = IAIEnvironment::AlliancesPlayerBit(1);
  for ( i = 1; i <= 8; ++i )
  {
    if ( (v4 & a2) != 0 )
    {
      *((_DWORD *)this + 1) = i;
      break;
    }
    v4 *= 2;
  }
  v3 = IAIEnvironment::AlliancesPlayerBit(8);
  for ( j = 8; j >= 1; --j )
  {
    if ( (v3 & a2) != 0 )
    {
      *((_DWORD *)this + 2) = j;
      return *((_DWORD *)this + 1) != 0;
    }
    v3 >>= 1;
  }
  return *((_DWORD *)this + 1) != 0;
}


// address=[0x1315000]
// Decompiled from int __thiscall CPlayerIterator::FirstPlayer(CPlayerIterator *this)

int  CPlayerIterator::FirstPlayer(void) {
  
  *((_DWORD *)this + 3) = *((_DWORD *)this + 1);
  *((_DWORD *)this + 4) = IAIEnvironment::AlliancesPlayerBit(*((_DWORD *)this + 1));
  return *((_DWORD *)this + 1);
}


// address=[0x1315040]
// Decompiled from int __thiscall CPlayerIterator::NextPlayer(CPlayerIterator *this)

int  CPlayerIterator::NextPlayer(void) {
  
  int v2; // [esp+8h] [ebp-Ch]
  int v3; // [esp+Ch] [ebp-8h]

  v3 = *((_DWORD *)this + 3);
  v2 = *((_DWORD *)this + 4);
  while ( v3 < *((_DWORD *)this + 2) )
  {
    ++v3;
    v2 *= 2;
    if ( (v2 & *(_DWORD *)this) != 0 )
    {
      *((_DWORD *)this + 3) = v3;
      *((_DWORD *)this + 4) = v2;
      return v3;
    }
  }
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = IAIEnvironment::AlliancesPlayerBit(0);
  return 0;
}


// address=[0x13172b0]
// Decompiled from CPlayerIterator *__thiscall CPlayerIterator::CPlayerIterator(CPlayerIterator *this)

 CPlayerIterator::CPlayerIterator(void) {
  
  return this;
}


// address=[0x1317440]
// Decompiled from int __thiscall CPlayerIterator::PlayerId(pairNode *this)

int  CPlayerIterator::PlayerId(void)const {
  
  return *((_DWORD *)this + 3);
}


