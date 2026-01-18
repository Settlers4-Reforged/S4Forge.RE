#include "CVWList.h"

// Definitions for class CVWList

// address=[0x1334ec0]
// Decompiled from CVWList *__thiscall CVWList::CVWList(CVWList *this, int a2, int a3, int a4)
 CVWList::CVWList(int a2, int a3, int a4) {
  
  CVWList::CalculateOverlappingSquares(this, a2, a3, a4);
  return this;
}


// address=[0x1335b10]
// Decompiled from int __thiscall CVWList::operator[](void *this, int a2)
struct CVWList::SVW const &  CVWList::operator[](int a2)const {
  
  return (int)this + 8 * a2 + 8;
}


// address=[0x1336840]
// Decompiled from int __thiscall CVWList::Size(CVWList *this)
int  CVWList::Size(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x15de830]
// Decompiled from CVWList *__thiscall CVWList::CalculateOverlappingSquares(CVWList *this, int a2, int a3, unsigned int a4)
void  CVWList::CalculateOverlappingSquares(int a2, int a3, int a4) {
  
  CVWList *result; // eax
  int v5; // [esp+8h] [ebp-18h]
  int v6; // [esp+Ch] [ebp-14h]
  int v7; // [esp+10h] [ebp-10h] BYREF
  int j; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  CVWList *v10; // [esp+1Ch] [ebp-4h]

  v10 = this;
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 161, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( a4 > 0x20 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 162, "(_iRadius >=0) && (_iRadius <= 32)") == 1 )
    __debugbreak();
  v5 = Squares::XYToVW((Squares *)a2);
  v6 = Squares::XYToVW((Squares *)a3);
  v7 = sub_15E1D20(v5, v6);
  for ( i = -2; i <= 2; ++i )
  {
    for ( j = -2; j <= 2; ++j )
    {
      if ( (unsigned __int8)sub_15E1E40(&v7, j, i, a2 & 0xF, a3 & 0xF, a4) )
        CVWList::PushEx(v10, &v7, j + v5, i + v6);
    }
  }
  *(_DWORD *)v10 = v7 & 0x1F;
  *((_DWORD *)v10 + 2 * *(_DWORD *)v10 + 2) = -1;
  result = v10;
  *((_DWORD *)v10 + 2 * *(_DWORD *)v10 + 3) = -1;
  return result;
}


// address=[0x15e2cf0]
// Decompiled from int __thiscall CVWList::PushEx(CVWList *this, int *a2, int a3, int a4)
void  CVWList::PushEx(int & a2, int a3, int a4) {
  
  int result; // eax

  *((_DWORD *)this + 2 * (*a2 & 0x1F) + 2) = a3;
  *((_DWORD *)this + 2 * (*a2 & 0x1F) + 3) = a4;
  result = *a2 + 1;
  *a2 = result;
  return result;
}


