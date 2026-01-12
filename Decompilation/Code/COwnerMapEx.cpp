#include "COwnerMapEx.h"

// Definitions for class COwnerMapEx

// address=[0x15de0a0]
// Decompiled from int COwnerMapEx::CalculateOwnerBits()

static void __cdecl COwnerMapEx::CalculateOwnerBits(void) {
  
  int v0; // ecx
  Squares *v1; // eax
  int v2; // edx
  int v3; // ecx
  Squares *v4; // eax
  char v5; // bl
  int result; // eax
  char v7; // bl
  int v8; // [esp+4h] [ebp-18h]
  int v9; // [esp+8h] [ebp-14h]
  int m; // [esp+Ch] [ebp-10h]
  int k; // [esp+10h] [ebp-Ch]
  int j; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  COwnerMap::ClearOwnerBits();
  v1 = (Squares *)CWorldManager::Width(v0);
  v8 = Squares::XYToVW(v1);
  v4 = (Squares *)CWorldManager::Height(v3, v2);
  v9 = Squares::XYToVW(v4);
  for ( i = 0; i < v9; ++i )
  {
    for ( j = 0; j < v8; ++j )
    {
      v5 = COwnerMapExEx::CalculateOwnerBits1(j, i);
      *COwnerMap::OwnerBits1VWRef(j, i) = v5;
    }
  }
  for ( k = 0; ; ++k )
  {
    result = k;
    if ( k >= v9 )
      break;
    for ( m = 0; m < v8; ++m )
    {
      v7 = COwnerMapExEx::CalculateOwnerBits9(m, k);
      *COwnerMap::OwnerBits9VWRef(m, k) = v7;
    }
  }
  return result;
}


// address=[0x15de190]
// Decompiled from void __cdecl COwnerMapEx::NotifyCreateTile(int a1, int a2)

static void __cdecl COwnerMapEx::NotifyCreateTile(int,int) {
  
  Squares *v2; // eax
  Squares *v3; // eax
  char *v4; // [esp+0h] [ebp-34h]
  char *v5; // [esp+4h] [ebp-30h]
  char *v6; // [esp+8h] [ebp-2Ch]
  char *v7; // [esp+Ch] [ebp-28h]
  char *v8; // [esp+10h] [ebp-24h]
  char *v9; // [esp+14h] [ebp-20h]
  char *v10; // [esp+18h] [ebp-1Ch]
  char *v11; // [esp+1Ch] [ebp-18h]
  char *v12; // [esp+20h] [ebp-14h]
  char *v13; // [esp+24h] [ebp-10h]
  int v14; // [esp+28h] [ebp-Ch]
  int v15; // [esp+2Ch] [ebp-8h]
  int v16; // [esp+30h] [ebp-4h]

  if ( a2 )
  {
    v14 = COwnerMap::OwnerBit(a2);
    v2 = (Squares *)Y16X16::UnpackXFast(a1);
    v16 = Squares::XYToVW(v2);
    v3 = (Squares *)Y16X16::UnpackYFast(a1);
    v15 = Squares::XYToVW(v3);
    if ( (v14 & COwnerMap::OwnerBits1VW(v16, v15)) == 0 )
    {
      v13 = COwnerMap::OwnerBits1VWRef(v16, v15);
      *v13 |= v14;
      v12 = COwnerMap::OwnerBits9VWRef(v16, v15 - 1);
      *v12 |= v14;
      v11 = COwnerMap::OwnerBits9VWRef(v16, v15);
      *v11 |= v14;
      v10 = COwnerMap::OwnerBits9VWRef(v16, v15 + 1);
      *v10 |= v14;
      if ( v16 > 0 )
      {
        v9 = COwnerMap::OwnerBits9VWRef(v16 - 1, v15 - 1);
        *v9 |= v14;
        v8 = COwnerMap::OwnerBits9VWRef(v16 - 1, v15);
        *v8 |= v14;
        v7 = COwnerMap::OwnerBits9VWRef(v16 - 1, v15 + 1);
        *v7 |= v14;
      }
      if ( v16 < 63 )
      {
        v6 = COwnerMap::OwnerBits9VWRef(v16 + 1, v15 - 1);
        *v6 |= v14;
        v5 = COwnerMap::OwnerBits9VWRef(v16 + 1, v15);
        *v5 |= v14;
        v4 = COwnerMap::OwnerBits9VWRef(v16 + 1, v15 + 1);
        *v4 |= v14;
      }
    }
  }
}


// address=[0x15de380]
// Decompiled from void __cdecl COwnerMapEx::NotifyDeleteTile(int a1, int a2)

static void __cdecl COwnerMapEx::NotifyDeleteTile(int,int) {
  
  Squares *v2; // eax
  Squares *v3; // eax
  int v4; // eax
  int v5; // [esp+0h] [ebp-18h]
  char *v6; // [esp+4h] [ebp-14h]
  struct CTile *v7; // [esp+8h] [ebp-10h]
  int i; // [esp+Ch] [ebp-Ch]
  int v9; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h]

  if ( a2 )
  {
    v2 = (Squares *)Y16X16::UnpackXFast(a1);
    v10 = Squares::XYToVW(v2);
    v3 = (Squares *)Y16X16::UnpackYFast(a1);
    v9 = Squares::XYToVW(v3);
    v5 = 16 << a2;
    for ( i = ITiling::FirstTileOfSquareVW(v10, v9); i; i = CTile::NextSquareTile(v7) )
    {
      v7 = (struct CTile *)ITiling::Tile(i);
      v4 = CTile::Type(v7, v5);
      if ( (v5 & v4) != 0 )
        return;
    }
    v6 = COwnerMap::OwnerBits1VWRef(v10, v9);
    *v6 &= ~(unsigned __int8)COwnerMap::OwnerBit(a2);
    COwnerMapExEx::CalculateOwnerBits9(v10, v9 - 1);
    COwnerMapExEx::CalculateOwnerBits9(v10, v9);
    COwnerMapExEx::CalculateOwnerBits9(v10, v9 + 1);
    if ( v10 > 0 )
    {
      COwnerMapExEx::CalculateOwnerBits9(v10 - 1, v9 - 1);
      COwnerMapExEx::CalculateOwnerBits9(v10 - 1, v9);
      COwnerMapExEx::CalculateOwnerBits9(v10 - 1, v9 + 1);
    }
    if ( v10 < 63 )
    {
      COwnerMapExEx::CalculateOwnerBits9(v10 + 1, v9 - 1);
      COwnerMapExEx::CalculateOwnerBits9(v10 + 1, v9);
      COwnerMapExEx::CalculateOwnerBits9(v10 + 1, v9 + 1);
    }
  }
}


