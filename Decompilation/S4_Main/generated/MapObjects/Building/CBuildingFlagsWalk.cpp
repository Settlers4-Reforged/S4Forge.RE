#include "all_headers.h"

// Definitions for class CBuildingFlagsWalk

// address=[0x14eaf90]
// Decompiled from CBuildingFlagsWalk *__thiscall CBuildingFlagsWalk::CBuildingFlagsWalk(  CBuildingFlagsWalk *this,  int a2,  int a3,  int a4,  int a5,  int a6)
 CBuildingFlagsWalk::CBuildingFlagsWalk(int,int,int,int,class std::vector<unsigned int,class std::allocator<unsigned int> > const &) {
  
  *(_DWORD *)this = a6;
  *((_DWORD *)this + 1) = a2 - a4 - 1;
  *((_DWORD *)this + 2) = a3 - a5;
  CBuildingFlagsWalk::Init(this);
  return this;
}


// address=[0x14eb380]
// Decompiled from int __thiscall CBuildingFlagsWalk::CurrentX(_DWORD *this)
int  CBuildingFlagsWalk::CurrentX(void)const {
  
  return this[5];
}


// address=[0x14eb3a0]
// Decompiled from int __thiscall CBuildingFlagsWalk::CurrentY(CBuildingFlagsWalk *this)
int  CBuildingFlagsWalk::CurrentY(void)const {
  
  return *((_DWORD *)this + 6);
}


// address=[0x14eb430]
// Decompiled from int __thiscall CBuildingFlagsWalk::Init(CBuildingFlagsWalk *this)
void  CBuildingFlagsWalk::Init(void) {
  
  int result; // eax

  *((_DWORD *)this + 5) = *((_DWORD *)this + 1);
  *((_DWORD *)this + 6) = *((_DWORD *)this + 2);
  result = std::vector<unsigned int>::size(*(_DWORD *)this);
  if ( result )
  {
    result = *(_DWORD *)std::vector<unsigned int>::operator[](0);
    *((_DWORD *)this + 3) = result;
  }
  else
  {
    *((_DWORD *)this + 3) = 0;
  }
  *((_DWORD *)this + 4) = 1;
  return result;
}


// address=[0x14eb5b0]
// Decompiled from char __thiscall CBuildingFlagsWalk::NextPosition(CBuildingFlagsWalk *this)
bool  CBuildingFlagsWalk::NextPosition(void) {
  
  int v2; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]

  while ( !*((_DWORD *)this + 3) )
  {
    if ( *((_DWORD *)this + 4) >= (unsigned int)std::vector<unsigned int>::size(*(_DWORD *)this) )
    {
      *((_DWORD *)this + 3) = 0;
      return 0;
    }
    *((_DWORD *)this + 5) = *((_DWORD *)this + 1);
    ++*((_DWORD *)this + 6);
    *((_DWORD *)this + 3) = *(_DWORD *)std::vector<unsigned int>::operator[](*((_DWORD *)this + 4));
    ++*((_DWORD *)this + 4);
  }
  v2 = *((_DWORD *)this + 5);
  for ( i = *((_DWORD *)this + 3); i >= 0; i *= 2 )
    ++v2;
  *((_DWORD *)this + 5) = v2 + 1;
  *((_DWORD *)this + 3) = 2 * i;
  return 1;
}


