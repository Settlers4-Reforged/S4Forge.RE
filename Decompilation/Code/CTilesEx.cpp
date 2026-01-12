#include "CTilesEx.h"

// Definitions for class CTilesEx

// address=[0x15e3040]
// Decompiled from int **__cdecl CTilesEx::InitTiles(struct CLinkList *a1)

static void __cdecl CTilesEx::InitTiles(class CLinkList &) {
  
  int **v1; // eax
  int **v2; // eax
  int **v3; // eax
  int **v4; // eax
  int **v5; // eax
  int **v6; // eax
  int **result; // eax
  CTile *v8; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]
  int j; // [esp+8h] [ebp-4h]

  v1 = CTiles::TileEx(0);
  CTile::InitPseudoTile((CTile *)v1, 0, a1);
  for ( i = 1; i <= 8; ++i )
  {
    v2 = CTiles::TileEx(i);
    CTile::InitPseudoTile((CTile *)v2, i, a1);
  }
  v3 = CTiles::TileEx(9);
  CTile::InitPseudoTile((CTile *)v3, 0, a1);
  v4 = CTiles::TileEx(9);
  CTile::SetType((CTile *)v4, 0xFFFFFFFD);
  v5 = CTiles::TileEx(0x7FFF);
  CTile::InitPseudoTile((CTile *)v5, 0, a1);
  v6 = CTiles::TileEx(0x7FFF);
  CTile::SetType((CTile *)v6, 0xFFFFFFFE);
  for ( j = 10; j <= 32766; ++j )
  {
    v8 = (CTile *)CTiles::TileEx(j);
    CTile::SetType(v8, 0xFFFFFFFF);
    v8->ecoSectorId = j - 1;
    v8->center = j + 1;
  }
  CTiles::TileEx(9)[2] = (int *)10;
  CTiles::TileEx(10)[1] = (int *)9;
  CTiles::TileEx(32766)[2] = _enc_textbss_begin + 28671;
  result = CTiles::TileEx(0x7FFF);
  result[1] = _enc_textbss_begin + 28670;
  CTilesEx::m_iNumberOfUsedTiles = 0;
  CTilesEx::m_iLastUsedTileId = 9;
  CTilesEx::m_iTilesPushBackMode = 1;
  CTilesEx::m_iMaxUsedTiles = 0;
  CTilesEx::m_iCalcFreeListCounter = 0;
  return result;
}


// address=[0x15e31c0]
// Decompiled from void __thiscall CTilesEx::DeactivateTilesPushBackMode(void *this)

static void __cdecl CTilesEx::DeactivateTilesPushBackMode(void) {
  
  int *v2; // [esp+0h] [ebp-4h]

  if ( CTilesEx::m_iTilesPushBackMode )
  {
    if ( CTilesEx::m_iLastUsedTileId == CTilesEx::m_iNumberOfUsedTiles + 9 )
    {
      v2 = (int *)(CTilesEx::m_iLastUsedTileId + 1);
      CTiles::TileEx(9)[2] = v2;
      CTiles::TileEx((int)v2)[1] = (int *)9;
    }
    else
    {
      if ( BBSupportDbgReport(
             1,
             "Pathing\\TilesAndLinks.cpp",
             108,
             "CTiles::DeactivatePushBackMode(): Last used tile invalid!") == 1 )
        __debugbreak();
      CTilesEx::CalculateListOfFreeTiles(0, this);
    }
    CTilesEx::CalculateSquareTileLists();
    CTilesEx::m_iTilesPushBackMode = 0;
  }
}


// address=[0x15e3250]
// Decompiled from // MFC 3.1-14.0 32bit
int CTilesEx::CalculateOwnerBits()

static void __cdecl CTilesEx::CalculateOwnerBits(void) {
  
  return COwnerMapEx::CalculateOwnerBits();
}


// address=[0x15e3260]
// Decompiled from __int16 __cdecl CTilesEx::InsertTileIntoSquareList(int a1)

static void __cdecl CTilesEx::InsertTileIntoSquareList(int) {
  
  int **v1; // eax
  __int16 result; // ax
  int **v3; // eax
  int v4; // [esp+0h] [ebp-18h]
  int v5; // [esp+4h] [ebp-14h]
  int v6; // [esp+8h] [ebp-10h]
  int v7; // [esp+Ch] [ebp-Ch]
  CTile *v8; // [esp+10h] [ebp-8h]
  struct CTiles::SFirstLast *LastXY; // [esp+14h] [ebp-4h]

  v8 = (CTile *)CTiles::TileEx(a1);
  if ( !CTile::Used(v8) && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 159, "rTile.Used()") == 1 )
    __debugbreak();
  v4 = CTile::CenterX(v8);
  v5 = CTile::CenterY(v8);
  LastXY = CTiles::SquareFirstLastXY(v4, v5);
  if ( *(_WORD *)LastXY )
  {
    if ( !*((_WORD *)LastXY + 1) )
    {
      if ( BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 170, "rFirstLast.m_uLast != 0") == 1 )
        __debugbreak();
      *((_WORD *)LastXY + 1) = *(_WORD *)LastXY;
    }
    if ( (CTile::Type(v8, v4) & 0x8000000) != 0 )
    {
      v7 = *((unsigned __int16 *)LastXY + 1);
      v1 = CTiles::TileEx(v7);
      if ( !CTile::Used((CTile *)v1)
        && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 181, "TileEx(iPrevTileId).Used()") == 1 )
      {
        __debugbreak();
      }
      if ( *((_WORD *)CTiles::TileEx(v7) + 7) )
      {
        if ( BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 182, "TileEx(iPrevTileId).m_uSquareNext == 0") == 1 )
          __debugbreak();
      }
      *((_WORD *)CTiles::TileEx(v7) + 7) = a1;
      v8->field_C = v7;
      v8->nextSquareTile = 0;
      result = (__int16)LastXY;
      *((_WORD *)LastXY + 1) = a1;
    }
    else
    {
      v6 = *(unsigned __int16 *)LastXY;
      v3 = CTiles::TileEx(v6);
      if ( !CTile::Used((CTile *)v3)
        && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 197, "TileEx(iNextTileId).Used()") == 1 )
      {
        __debugbreak();
      }
      if ( *((_WORD *)CTiles::TileEx(v6) + 6)
        && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 198, "TileEx(iNextTileId).m_uSquarePrev == 0") == 1 )
      {
        __debugbreak();
      }
      *((_WORD *)CTiles::TileEx(v6) + 6) = a1;
      v8->field_C = 0;
      result = v6;
      v8->nextSquareTile = v6;
      *(_WORD *)LastXY = a1;
    }
  }
  else
  {
    if ( *((_WORD *)LastXY + 1)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 212, "rFirstLast.m_uLast == 0") == 1 )
    {
      __debugbreak();
    }
    *(_WORD *)LastXY = a1;
    *((_WORD *)LastXY + 1) = a1;
    v8->field_C = 0;
    result = 0;
    v8->nextSquareTile = 0;
  }
  return result;
}


// address=[0x15e34f0]
// Decompiled from int **__cdecl CTilesEx::DeleteTileFromSquareList(int a1)

static void __cdecl CTilesEx::DeleteTileFromSquareList(int) {
  
  int **v1; // eax
  int **v2; // eax
  int **result; // eax
  int v4; // [esp+0h] [ebp-10h]
  int v5; // [esp+4h] [ebp-Ch]
  struct CTiles::SFirstLast *LastXY; // [esp+8h] [ebp-8h]
  CTile *v7; // [esp+Ch] [ebp-4h]

  v7 = (CTile *)CTiles::TileEx(a1);
  v4 = CTile::CenterX(v7);
  v5 = CTile::CenterY(v7);
  LastXY = CTiles::SquareFirstLastXY(v4, v5);
  if ( v7->field_C )
  {
    v1 = CTiles::TileEx(v7->field_C);
    if ( !CTile::Used((CTile *)v1)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 238, "TileEx(rTile.m_uSquarePrev).Used()") == 1 )
    {
      __debugbreak();
    }
    if ( *((unsigned __int16 *)CTiles::TileEx(v7->field_C) + 7) != a1
      && BBSupportDbgReport(
           2,
           "Pathing\\TilesAndLinks.cpp",
           239,
           "TileEx(rTile.m_uSquarePrev).m_uSquareNext == _iTileId") == 1 )
    {
      __debugbreak();
    }
    *((_WORD *)CTiles::TileEx(v7->field_C) + 7) = v7->nextSquareTile;
  }
  else
  {
    if ( *(unsigned __int16 *)LastXY != a1
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 245, "rFirstLast.m_uFirst == _iTileId") == 1 )
    {
      __debugbreak();
    }
    *(_WORD *)LastXY = v7->nextSquareTile;
  }
  if ( v7->nextSquareTile )
  {
    v2 = CTiles::TileEx(v7->nextSquareTile);
    if ( !CTile::Used((CTile *)v2)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 252, "TileEx(rTile.m_uSquareNext).Used()") == 1 )
    {
      __debugbreak();
    }
    if ( *((unsigned __int16 *)CTiles::TileEx(v7->nextSquareTile) + 6) != a1
      && BBSupportDbgReport(
           2,
           "Pathing\\TilesAndLinks.cpp",
           253,
           "TileEx(rTile.m_uSquareNext).m_uSquarePrev == _iTileId") == 1 )
    {
      __debugbreak();
    }
    result = CTiles::TileEx(v7->nextSquareTile);
    *((_WORD *)result + 6) = v7->field_C;
  }
  else
  {
    if ( *((unsigned __int16 *)LastXY + 1) != a1
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 259, "rFirstLast.m_uLast == _iTileId") == 1 )
    {
      __debugbreak();
    }
    result = (int **)LastXY;
    *((_WORD *)LastXY + 1) = v7->field_C;
  }
  return result;
}


// address=[0x15e36f0]
// Decompiled from int CTilesEx::CalculateListOfFreeTiles()

static void __cdecl CTilesEx::CalculateListOfFreeTiles(void) {
  
  int **v0; // eax
  int v2; // [esp+0h] [ebp-10h]
  int v3; // [esp+4h] [ebp-Ch]
  int v4; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v3 = 0;
  v2 = 9;
  v4 = 9;
  CTiles::TileEx(9)[1] = 0;
  for ( i = 10; i <= 32766; ++i )
  {
    v0 = CTiles::TileEx(i);
    if ( CTile::Used((CTile *)v0) )
    {
      ++v3;
      v2 = i;
    }
    else
    {
      CTiles::TileEx(i)[1] = (int *)v4;
      CTiles::TileEx(v4)[2] = (int *)i;
      v4 = i;
    }
  }
  CTiles::TileEx(v4)[2] = _enc_textbss_begin + 28671;
  CTiles::TileEx(0x7FFF)[1] = (int *)v4;
  CTiles::TileEx(0x7FFF)[2] = 0;
  CTilesEx::m_iNumberOfUsedTiles = v3;
  CTilesEx::m_iLastUsedTileId = v2;
  if ( v3 > CTilesEx::m_iMaxUsedTiles )
    CTilesEx::m_iMaxUsedTiles = CTilesEx::m_iNumberOfUsedTiles;
  return ++CTilesEx::m_iCalcFreeListCounter;
}


// address=[0x15e3810]
// Decompiled from int CTilesEx::CalculateSquareTileLists()

static void __cdecl CTilesEx::CalculateSquareTileLists(void) {
  
  int result; // eax
  int **v1; // eax
  int v2; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  j__memset(CTiles::m_sSquareFirstLastTiles, 0, sizeof(CTiles::m_sSquareFirstLastTiles));
  result = CTilesEx::LastUsedTileId();
  v2 = result;
  for ( i = 10; i <= v2; ++i )
  {
    v1 = CTiles::TileEx(i);
    if ( CTile::Used((CTile *)v1) )
      CTilesEx::InsertTileIntoSquareList(i);
    result = i + 1;
  }
  return result;
}


// address=[0x15e3880]
// Decompiled from int *CTilesEx::PushTileUndef()

static int __cdecl CTilesEx::PushTileUndef(void) {
  
  int v0; // ecx
  int v2; // ecx
  int **v3; // eax
  int *v4; // [esp+0h] [ebp-8h]
  int *v5; // [esp+4h] [ebp-4h]

  if ( CTilesEx::m_iTilesPushBackMode
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 345, "!m_iTilesPushBackMode") == 1 )
  {
    __debugbreak();
  }
  if ( CTilesEx::m_iNumberOfUsedTiles < 32757
    || (CTrace::Print("CTiles::PushTileUndef(): Tile limit exceeded. Rebuilding list of free tiles!"),
        CTilesEx::CalculateListOfFreeTiles(v0),
        CTilesEx::m_iNumberOfUsedTiles < 32757) )
  {
    v5 = CTiles::TileEx(9)[2];
    if ( CTiles::IsValidRealTile(v5)
      || (CTrace::Print("CTiles::PushTileUndef(): Invalid free tile id. Rebuilding list of free tiles!"),
          CTilesEx::CalculateListOfFreeTiles(v2),
          v5 = CTiles::TileEx(9)[2],
          CTiles::IsValidRealTile(v5)) )
    {
      v4 = CTiles::TileEx((int)v5)[2];
      CTiles::TileEx((int)v4)[1] = (int *)9;
      CTiles::TileEx(9)[2] = v4;
      v3 = CTiles::TileEx((int)v5);
      CTile::SetType((CTile *)v3, 0);
      ++CTilesEx::m_iNumberOfUsedTiles;
      if ( (int)v5 > CTilesEx::m_iLastUsedTileId )
        CTilesEx::m_iLastUsedTileId = (int)v5;
      if ( CTilesEx::m_iNumberOfUsedTiles > CTilesEx::m_iMaxUsedTiles )
        CTilesEx::m_iMaxUsedTiles = CTilesEx::m_iNumberOfUsedTiles;
      return v5;
    }
    else
    {
      if ( BBSupportDbgReport(1, "Pathing\\TilesAndLinks.cpp", 381, "Tiling: No free tile found!") == 1 )
        __debugbreak();
      return 0;
    }
  }
  else
  {
    if ( BBSupportDbgReport(1, "Pathing\\TilesAndLinks.cpp", 359, "Tiling: Out of tiles!") == 1 )
      __debugbreak();
    return 0;
  }
}


// address=[0x15e3a10]
// Decompiled from int __cdecl CTilesEx::PushTilesBackUndef(int a1)

static int __cdecl CTilesEx::PushTilesBackUndef(int) {
  
  int v2; // [esp+0h] [ebp-4h]

  if ( !CTilesEx::m_iTilesPushBackMode
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 128, "m_iTilesPushBackMode") == 1 )
  {
    __debugbreak();
  }
  if ( a1 + CTilesEx::m_iNumberOfUsedTiles > 32757
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 129, "m_iNumberOfUsedTiles + _iCount <= TILES_MAX_NUMBER") == 1 )
  {
    __debugbreak();
  }
  v2 = CTilesEx::m_iLastUsedTileId;
  CTilesEx::m_iNumberOfUsedTiles += a1;
  CTilesEx::m_iLastUsedTileId += a1;
  if ( CTilesEx::m_iNumberOfUsedTiles > CTilesEx::m_iMaxUsedTiles )
    CTilesEx::m_iMaxUsedTiles = CTilesEx::m_iNumberOfUsedTiles;
  return v2 + 1;
}


// address=[0x15e3ac0]
// Decompiled from int *__cdecl CTilesEx::PushTile(DWORD a1, DWORD a2)

static int __cdecl CTilesEx::PushTile(int,int) {
  
  int **v2; // eax
  struct CLinkList *v4; // [esp-4h] [ebp-Ch]
  int *v5; // [esp+4h] [ebp-4h]

  v5 = CTilesEx::PushTileUndef();
  v4 = CLinks::LinkList(0);
  v2 = CTiles::TileEx((int)v5);
  CTile::Init((CTile *)v2, a1, a2, v4);
  CTilesEx::InsertTileIntoSquareList((int)v5);
  if ( (a1 & 0xF) != 0 )
    COwnerMapEx::NotifyCreateTile(a2, a1 & 0xF);
  return v5;
}


// address=[0x15e3b30]
// Decompiled from int *__cdecl CTilesEx::DuplicateTile(int a1)

static int __cdecl CTilesEx::DuplicateTile(int) {
  
  int **v1; // eax
  struct CLinkList *v2; // eax
  int *v4; // [esp+0h] [ebp-8h]
  int **v5; // [esp+4h] [ebp-4h]

  v4 = CTilesEx::PushTileUndef();
  v5 = CTiles::TileEx((int)v4);
  v1 = CTiles::TileEx(a1);
  *v5 = *v1;
  v5[1] = v1[1];
  v5[2] = v1[2];
  v5[3] = v1[3];
  v5[4] = v1[4];
  v2 = CLinks::LinkList(0);
  CTile::SetLinkList((CTile *)v5, v2);
  CTile::SetSize((CTile *)v5, 0);
  CTilesEx::InsertTileIntoSquareList((int)v4);
  return v4;
}


// address=[0x15e3bb0]
// Decompiled from int __cdecl CTilesEx::DeleteTile(int *a1)

static void __cdecl CTilesEx::DeleteTile(int) {
  
  int result; // eax
  int v2; // eax
  int **v3; // eax
  int *v4; // [esp+0h] [ebp-10h]
  int v5; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  CTile *v7; // [esp+Ch] [ebp-4h]

  if ( CTilesEx::IsValidUsedTile(a1) )
  {
    v7 = (CTile *)CTiles::TileEx((int)a1);
    CTilesEx::DeleteTileFromSquareList((int)a1);
    v5 = CTile::OwnerId(v7);
    if ( v5 )
    {
      v2 = CTile::CenterXY(v7);
      COwnerMapEx::NotifyDeleteTile(v2, v5);
    }
    CTile::SetType(v7, 0xFFFFFFFF);
    v4 = CTiles::TileEx(9)[2];
    CTiles::TileEx(9)[2] = a1;
    v7->ecoSectorId = 9;
    v7->center = (DWORD)v4;
    CTiles::TileEx((int)v4)[1] = a1;
    if ( --CTilesEx::m_iNumberOfUsedTiles < 0 )
      CTilesEx::CalculateListOfFreeTiles(a1);
    result = CTilesEx::m_iLastUsedTileId;
    if ( (int *)CTilesEx::m_iLastUsedTileId == a1 )
    {
      for ( i = (int)a1 - 1; ; --i )
      {
        v3 = CTiles::TileEx(i);
        result = CTile::Unused((CTile *)v3);
        if ( !(_BYTE)result )
          break;
      }
      CTilesEx::m_iLastUsedTileId = i;
    }
  }
  else
  {
    if ( !"CTilesEx::DeleteTile(): Not a used real tile!" )
      return 0;
    if ( BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 484, "!\"CTilesEx::DeleteTile(): Not a used real tile!\"") == 1 )
      __debugbreak();
    return 0;
  }
  return result;
}


// address=[0x15e7050]
// Decompiled from bool __cdecl CTilesEx::IsUsedRealTile(int a1)

static bool __cdecl CTilesEx::IsUsedRealTile(int) {
  
  int **v1; // eax
  char v3; // [esp+0h] [ebp-4h]

  v3 = 0;
  if ( !CTiles::IsValidRealTile(a1) )
    return v3;
  v1 = CTiles::TileEx(a1);
  if ( CTile::Used((CTile *)v1) )
    return 1;
  return v3;
}


// address=[0x15e71c0]
// Decompiled from bool __cdecl CTilesEx::IsValidUsedTile(int a1)

static bool __cdecl CTilesEx::IsValidUsedTile(int) {
  
  int **v1; // eax
  char v3; // [esp+0h] [ebp-4h]

  v3 = 0;
  if ( !CTiles::IsValidRealTile(a1) )
    return v3;
  v1 = CTiles::TileEx(a1);
  if ( CTile::Used((CTile *)v1) )
    return 1;
  return v3;
}


// address=[0x15e7220]
// Decompiled from int CTilesEx::LastUsedTileId()

static int __cdecl CTilesEx::LastUsedTileId(void) {
  
  return CTilesEx::m_iLastUsedTileId;
}


// address=[0x15f5230]
// Decompiled from int CTilesEx::NumberOfUsedTiles()

static int __cdecl CTilesEx::NumberOfUsedTiles(void) {
  
  return CTilesEx::m_iNumberOfUsedTiles;
}


// address=[0x4237888]
// [Decompilation failed for static int CTilesEx::m_iNumberOfUsedTiles]

// address=[0x423788c]
// [Decompilation failed for static int CTilesEx::m_iLastUsedTileId]

// address=[0x4237890]
// [Decompilation failed for static int CTilesEx::m_iMaxUsedTiles]

// address=[0x4237894]
// [Decompilation failed for static int CTilesEx::m_iTilesPushBackMode]

// address=[0x4237898]
// [Decompilation failed for static int CTilesEx::m_iCalcFreeListCounter]

