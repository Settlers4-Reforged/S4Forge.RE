#include "ITiling.h"

// Definitions for class ITiling

// address=[0x12fcea0]
// Decompiled from int __cdecl ITiling::CatapultSectorId(int a1)

static int __cdecl ITiling::CatapultSectorId(int) {
  
  int v1; // eax
  CTile *v2; // eax

  v1 = ITiling::CatapultTileId(a1);
  v2 = (CTile *)ITiling::Tile(v1);
  return CTile::SectorId(v2);
}


// address=[0x12fced0]
// Decompiled from int __cdecl ITiling::CatapultTileId(int a1)

static int __cdecl ITiling::CatapultTileId(int) {
  
  if ( (unsigned __int16)(*(&ITiling::m_pTileIds + 1))[a1] >= 0x8000u )
    return 0;
  else
    return (unsigned __int16)(*(&ITiling::m_pTileIds + 1))[a1];
}


// address=[0x12fd780]
// Decompiled from CTile *__cdecl ITiling::Tile(int a1)

static class CTile const & __cdecl ITiling::Tile(int) {
  
  return &CTiles::m_cTiles[a1];
}


// address=[0x13066a0]
// Decompiled from int __cdecl ITiling::FirstTileOfSquareVW(int a1, int a2)

static int __cdecl ITiling::FirstTileOfSquareVW(int,int) {
  
  return (unsigned __int16)CTiles::m_sSquareFirstLastTiles[128 * a2 + 128 + 2 * a1];
}


// address=[0x130eb10]
// Decompiled from int __cdecl ITiling::EcoSectorId(int a1)

static int __cdecl ITiling::EcoSectorId(int) {
  
  int v1; // eax
  const struct CTile *v2; // eax

  v1 = ITiling::NormalTileId(a1);
  v2 = ITiling::Tile(v1);
  return CTile::EcoSectorId(v2);
}


// address=[0x130f210]
// Decompiled from int __cdecl ITiling::NormalTileId(int a1)

static int __cdecl ITiling::NormalTileId(int) {
  
  return (unsigned __int16)ITiling::m_pTileIds[a1];
}


// address=[0x130f270]
// Decompiled from int __cdecl ITiling::OwnerId(int a1)

static int __cdecl ITiling::OwnerId(int) {
  
  int v1; // eax
  CTile *v2; // eax

  v1 = ITiling::NormalTileId(a1);
  v2 = (CTile *)ITiling::Tile(v1);
  return CTile::OwnerId(v2);
}


// address=[0x130f360]
// Decompiled from int __cdecl ITiling::SectorId(int a1)

static int __cdecl ITiling::SectorId(int) {
  
  int v1; // eax
  CTile *v2; // eax

  v1 = ITiling::NormalTileId(a1);
  v2 = ITiling::Tile(v1);
  return CTile::SectorId(v2);
}


// address=[0x1351c50]
// Decompiled from int __cdecl ITiling::NumberOfWaterElementsDiv2XY(Squares *a1, Squares *a2)

static int __cdecl ITiling::NumberOfWaterElementsDiv2XY(int,int) {
  
  int v2; // esi

  v2 = (Squares::XYToVW(a2) + 1) << 6;
  return (unsigned __int8)ITiling::m_uSquareNumberOfWaterElementsDiv2[v2 + Squares::XYToVW(a1)];
}


// address=[0x14e0060]
// Decompiled from int __cdecl ITiling::NumberOfWaterElementsDiv2VW(int a1, int a2)

static int __cdecl ITiling::NumberOfWaterElementsDiv2VW(int,int) {
  
  return (unsigned __int8)ITiling::m_uSquareNumberOfWaterElementsDiv2[64 * a2 + 64 + a1];
}


// address=[0x15f3f60]
// Decompiled from ITiling *__thiscall ITiling::ITiling(ITiling *this)

 ITiling::ITiling(void) {
  
  *(_DWORD *)this = ITiling::_vftable_;
  return this;
}


// address=[0x15f5240]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
int __cdecl ITiling::OwnerPseudoTileId(int a1)

static int __cdecl ITiling::OwnerPseudoTileId(int) {
  
  return a1;
}


// address=[0x4236800]
// [Decompilation failed for static unsigned short * * ITiling::m_pTileIds]

// address=[0x4236808]
// [Decompilation failed for static unsigned char (* ITiling::m_uSquareNumberOfWaterElementsDiv2)[64]]

