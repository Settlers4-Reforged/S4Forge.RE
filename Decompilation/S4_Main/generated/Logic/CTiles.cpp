#include "CTiles.h"

// Definitions for class CTiles

// address=[0x15e7130]
// Decompiled from bool __cdecl CTiles::IsValidRealTile(int a1)
static bool __cdecl CTiles::IsValidRealTile(int) {
  
  return (unsigned int)(a1 - 10) <= 0x7FF4;
}


// address=[0x15f4960]
// Decompiled from bool __cdecl CTiles::IsValidPseudoTile(unsigned int a1)
static bool __cdecl CTiles::IsValidPseudoTile(int) {
  
  return a1 < 0xA;
}


// address=[0x15f4990]
// Decompiled from bool __cdecl CTiles::IsValidTileId(unsigned int a1)
static bool __cdecl CTiles::IsValidTileId(int) {
  
  return a1 <= 0x7FFE;
}


// address=[0x15e7450]
// Decompiled from char *__cdecl CTiles::SquareFirstLastXY(Squares *a1, Squares *a2)
static struct CTiles::SFirstLast & __cdecl CTiles::SquareFirstLastXY(int,int) {
  
  int v2; // esi

  v2 = (Squares::XYToVW(a2) + 1) << 8;
  return (char *)&CTiles::m_sSquareFirstLastTiles[2 * Squares::XYToVW(a1)] + v2;
}


// address=[0x15e7490]
// Decompiled from int **__cdecl CTiles::TileEx(int a1)
static class CTile & __cdecl CTiles::TileEx(int) {
  
  return &(&CTiles::m_cTiles)[5 * a1];
}


// address=[0x4192600]
// [Decompilation failed for static class CTile * CTiles::m_cTiles]

// address=[0x4232600]
// [Decompilation failed for static struct CTiles::SFirstLast (* CTiles::m_sSquareFirstLastTiles)[64]]

