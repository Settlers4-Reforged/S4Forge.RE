#if FALSE
#include "CTiles.h"

// Definitions for class CTiles

// address=[0x15e7130]
// Decompiled from bool __cdecl CTiles::IsValidRealTile(int a1)
bool __cdecl CTiles::IsValidRealTile(int a1) {
  
  return (unsigned int)(a1 - 10) <= 0x7FF4;
}


// address=[0x15f4960]
// Decompiled from bool __cdecl CTiles::IsValidPseudoTile(int a1)
bool __cdecl CTiles::IsValidPseudoTile(int a1) {
  
  return (unsigned int)a1 < 0xA;
}


// address=[0x15f4990]
// Decompiled from bool __cdecl CTiles::IsValidTileId(int a1)
bool __cdecl CTiles::IsValidTileId(int a1) {
  
  return (unsigned int)a1 <= 0x7FFE;
}


// address=[0x15e7450]
// Decompiled from struct SFirstLast *__cdecl CTiles::SquareFirstLastXY(int a1, int a2)
struct CTiles::SFirstLast & __cdecl CTiles::SquareFirstLastXY(int a1, int a2) {
  
  int v2; // esi

  v2 = (Squares::XYToVW(a2) + 1) << 8;
  return (struct SFirstLast *)((char *)&CTiles::m_sSquareFirstLastTiles + 4 * Squares::XYToVW(a1) + v2);
}


// address=[0x15e7490]
// Decompiled from CTile *__cdecl CTiles::TileEx(int a1)
class CTile & __cdecl CTiles::TileEx(int a1) {
  
  return &CTiles::m_cTiles[a1];
}


// address=[0x4192600]
// [Decompilation failed for static class CTile * CTiles::m_cTiles]

// address=[0x4232600]
// [Decompilation failed for static struct CTiles::SFirstLast (* CTiles::m_sSquareFirstLastTiles)[64]]

#endif // Already implemented
