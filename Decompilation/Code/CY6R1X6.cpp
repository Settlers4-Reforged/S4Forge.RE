#include "CY6R1X6.h"

// Definitions for class CY6R1X6

// address=[0x15d61f0]
// Decompiled from int __cdecl CY6R1X6::DeltaX(char a1, char a2)

static int __cdecl CY6R1X6::DeltaX(int,int) {
  
  return (a2 & 0x3F) - (a1 & 0x3F);
}


// address=[0x15d6210]
// Decompiled from int __cdecl CY6R1X6::DeltaY(int a1, int a2)

static int __cdecl CY6R1X6::DeltaY(int,int) {
  
  return (a2 >> 7) - (a1 >> 7);
}


// address=[0x15d6250]
// Decompiled from int __cdecl CY6R1X6::Distance(int a1, int a2)

static int __cdecl CY6R1X6::Distance(int,int) {
  
  Grid *v3; // [esp+0h] [ebp-8h]
  int v4; // [esp+4h] [ebp-4h]

  v3 = (Grid *)CY6R1X6::DeltaX(a1, a2);
  v4 = CY6R1X6::DeltaY(a1, a2);
  return Grid::Distance(v3, v4);
}


// address=[0x15d6780]
// Decompiled from int __cdecl CY6R1X6::NeighborRelPackedIdx(int a1)

static int __cdecl CY6R1X6::NeighborRelPackedIdx(int) {
  
  return dword_37D7CF8[a1];
}


// address=[0x15d67a0]
// Decompiled from int __cdecl CY6R1X6::PackedIdx(int a1)

static int __cdecl CY6R1X6::PackedIdx(int) {
  
  int v2; // [esp+0h] [ebp-8h]

  v2 = Y16X16::UnpackXFast(a1);
  return v2 | (Y16X16::UnpackYFast(a1) << 7);
}


// address=[0x15d70b0]
// Decompiled from bool __cdecl CY6R1X6::Valid(int a1)

static bool __cdecl CY6R1X6::Valid(int) {
  
  return (a1 & 0xFFFFE040) == 0;
}


// address=[0x15d70e0]
// Decompiled from int __cdecl CY6R1X6::WorldIdx(int a1)

static int __cdecl CY6R1X6::WorldIdx(int) {
  
  int v2; // [esp+0h] [ebp-8h]
  int v3; // [esp+4h] [ebp-4h]

  v2 = CY6R1X6::X(a1);
  v3 = CY6R1X6::Y(a1);
  return CWorldManager::Index(v2, v3);
}


// address=[0x15d7180]
// Decompiled from int __cdecl CY6R1X6::X(char a1)

static int __cdecl CY6R1X6::X(int) {
  
  return a1 & 0x3F;
}


// address=[0x15d71c0]
// Decompiled from int __cdecl CY6R1X6::Y(int a1)

static int __cdecl CY6R1X6::Y(int) {
  
  return a1 >> 7;
}


