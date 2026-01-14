#include "all_headers.h"

// Definitions for class CAreaList

// address=[0x15f3e80]
// Decompiled from CAreaList *__thiscall CAreaList::CAreaList(CAreaList *this)
 CAreaList::CAreaList(void) {
  
  TStaticArray<int,63>::TStaticArray<int,63>(this);
  return this;
}


// address=[0x15f4860]
// Decompiled from int __thiscall CAreaList::InitOne(CAreaList *this, int a2)
void  CAreaList::InitOne(int) {
  
  int result; // eax

  result = a2;
  *((_DWORD *)this + 1) = a2;
  *(_DWORD *)this = 1;
  return result;
}


// address=[0x15f55c0]
// Decompiled from int __thiscall CAreaList::PushBack(CAreaList *this, int a2)
void  CAreaList::PushBack(int) {
  
  if ( *(int *)this >= 63 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 575, "m_iSize < AREA_LIST_MAX") == 1 )
    __debugbreak();
  return TStaticArray<int,63>::PushBack(&a2);
}


