#include "CSquareVisited.h"

// Definitions for class CSquareVisited

// address=[0x15f1030]
// Decompiled from CSquareVisited *__thiscall CSquareVisited::CSquareVisited(CSquareVisited *this)
 CSquareVisited::CSquareVisited(void) {
  
  *((_BYTE *)this + 12) = 0;
  memset((char *)this + 13, 255, 0x240u);
  return this;
}


// address=[0x15f1070]
// Decompiled from void __thiscall CSquareVisited::Init(CSquareVisited *this, int a2, int a3)
void  CSquareVisited::Init(int a2, int a3) {
  
  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]

  v4 = (a2 & 0xFFFFFFF0) - 1;
  v3 = (a3 & 0xFFFFFFF0) - 1;
  *(_DWORD *)this = Y16X16::PackXYFast(v4, v3);
  *((_DWORD *)this + 1) = CTilingWorld::WorldIndex(v4, v3);
  *((_DWORD *)this + 2) = 32 * (a3 - v3) + a2 - v4;
  CSquareVisited::ClearArray(this);
}


// address=[0x15f4030]
// Decompiled from bool __thiscall CSquareVisited::operator[](unsigned __int8 *this, int a2)
bool  CSquareVisited::operator[](int a2)const {
  
  return this[a2 + 13] == this[12];
}


// address=[0x15f4280]
// Decompiled from int __thiscall CSquareVisited::ClearArray(CSquareVisited *this)
void  CSquareVisited::ClearArray(void) {
  
  int result; // eax

  *(_DWORD *)((char *)this + 4 * *((unsigned __int8 *)this + 12) + 13) = -1;
  result = *((unsigned __int8 *)this + 12) >= 0x8Fu ? 0 : *((unsigned __int8 *)this + 12) + 1;
  *((_BYTE *)this + 12) = result;
  return result;
}


// address=[0x15f4820]
// Decompiled from void __thiscall CSquareVisited::Init(CSquareVisited *this, int a2)
void  CSquareVisited::Init(int a2) {
  
  int v2; // eax
  int v3; // [esp-4h] [ebp-8h]

  v3 = Y16X16::UnpackYFast(a2);
  v2 = Y16X16::UnpackXFast(a2);
  CSquareVisited::Init(this, v2, v3);
}


// address=[0x15f49e0]
// Decompiled from int __cdecl CSquareVisited::NeighborRelIndex(int a1)
int __cdecl CSquareVisited::NeighborRelIndex(int a1) {
  
  return dword_37E0190[a1];
}


// address=[0x15f56c0]
// Decompiled from char *__thiscall CSquareVisited::Set(CSquareVisited *this, int a2)
void  CSquareVisited::Set(int a2) {
  
  char *result; // eax

  result = (char *)this + a2;
  *((_BYTE *)this + a2 + 13) = *((_BYTE *)this + 12);
  return result;
}


// address=[0x15f57a0]
// Decompiled from char __thiscall CSquareVisited::SetIfNotVisited(CSquareVisited *this, int a2)
bool  CSquareVisited::SetIfNotVisited(int a2) {
  
  if ( *((unsigned __int8 *)this + a2 + 13) == *((unsigned __int8 *)this + 12) )
    return 0;
  *((_BYTE *)this + a2 + 13) = *((_BYTE *)this + 12);
  return 1;
}


// address=[0x15f5920]
// Decompiled from int __thiscall CSquareVisited::StartIndex(CSquareVisited *this)
int  CSquareVisited::StartIndex(void)const {
  
  return *((_DWORD *)this + 2);
}


// address=[0x15f5b80]
// Decompiled from int __thiscall CSquareVisited::WorldIdx(CSquareVisited *this, int a2)
int  CSquareVisited::WorldIdx(int a2)const {
  
  return *((_DWORD *)this + 1) + CTilingWorld::WorldIndex(a2 % 32, a2 / 32);
}


// address=[0x15f5f40]
// Decompiled from int __thiscall CSquareVisited::WorldPackedXYIndex(CSquareVisited *this, int a2)
int  CSquareVisited::WorldPackedXYIndex(int a2)const {
  
  int v2; // esi
  Y16X16 *v4; // [esp+8h] [ebp-4h]

  v4 = (Y16X16 *)(a2 - *(_DWORD *)this);
  if ( !Y16X16::XYNotNegative(v4)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 1171, "Y16X16::XYNotNegative(iPackedXY)") == 1 )
  {
    __debugbreak();
  }
  v2 = Y16X16::UnpackXFast((int)v4);
  return v2 + 32 * Y16X16::UnpackYFast((int)v4);
}


