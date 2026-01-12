#include "COwnerMapExEx.h"

// Definitions for class COwnerMapExEx

// address=[0x15de510]
// Decompiled from int __cdecl COwnerMapExEx::CalculateOwnerBits1(int a1, int a2)

static int __cdecl COwnerMapExEx::CalculateOwnerBits1(int,int) {
  
  int v2; // eax
  struct CTile *v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v5 = 0;
  for ( i = ITiling::FirstTileOfSquareVW(a1, a2); i; i = CTile::NextSquareTile(v4) )
  {
    v4 = (struct CTile *)ITiling::Tile(i);
    v2 = CTile::OwnerId(v4);
    v5 |= COwnerMap::OwnerBit(v2);
  }
  return v5;
}


// address=[0x15de570]
// Decompiled from int __cdecl COwnerMapExEx::CalculateOwnerBits9(int a1, int a2)

static int __cdecl COwnerMapExEx::CalculateOwnerBits9(int,int) {
  
  int v2; // esi
  int v3; // esi
  int v4; // esi
  int v5; // esi
  int v6; // esi
  int v7; // esi
  int v9; // [esp+4h] [ebp-4h]

  v2 = COwnerMap::OwnerBits1VW(a1, a2 - 1);
  v3 = COwnerMap::OwnerBits1VW(a1, a2) | v2;
  v9 = COwnerMap::OwnerBits1VW(a1, a2 + 1) | v3;
  if ( a1 > 0 )
  {
    v4 = COwnerMap::OwnerBits1VW(a1 - 1, a2 - 1);
    v5 = COwnerMap::OwnerBits1VW(a1 - 1, a2) | v4;
    v9 |= COwnerMap::OwnerBits1VW(a1 - 1, a2 + 1) | v5;
  }
  if ( a1 >= 63 )
    return v9;
  v6 = COwnerMap::OwnerBits1VW(a1 + 1, a2 - 1);
  v7 = COwnerMap::OwnerBits1VW(a1 + 1, a2) | v6;
  return v9 | COwnerMap::OwnerBits1VW(a1 + 1, a2 + 1) | v7;
}


