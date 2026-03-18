#if FALSE
#include "CTilesEx.h"

// Definitions for class CTilesEx

// address=[0x15e3040]
// Decompiled from void __cdecl CTilesEx::InitTiles(struct CLinkList *a1)
void __cdecl CTilesEx::InitTiles(class CLinkList & a1) {
  
  CTile *v1; // eax
  CTile *v2; // eax
  CTile *v3; // eax
  CTile *v4; // eax
  CTile *v5; // eax
  CTile *v6; // eax
  CTile *v7; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]
  int j; // [esp+8h] [ebp-4h]

  v1 = CTiles::TileEx(0);
  CTile::InitPseudoTile(v1, 0, a1);
  for ( i = 1; i <= 8; ++i )
  {
    v2 = CTiles::TileEx(i);
    CTile::InitPseudoTile(v2, i, a1);
  }
  v3 = CTiles::TileEx(9);
  CTile::InitPseudoTile(v3, 0, a1);
  v4 = CTiles::TileEx(9);
  CTile::SetType(v4, -3u);
  v5 = CTiles::TileEx(0x7FFF);
  CTile::InitPseudoTile(v5, 0, a1);
  v6 = CTiles::TileEx(0x7FFF);
  CTile::SetType(v6, 0xFFFFFFFE);
  for ( j = 10; j <= 32766; ++j )
  {
    v7 = CTiles::TileEx(j);
    CTile::SetType(v7, 0xFFFFFFFF);
    *(_DWORD *)&v7->m_iSectorId = j - 1;
    v7->m_uCenter = j + 1;
  }
  CTiles::TileEx(9)->m_uCenter = 10;
  *(_DWORD *)&CTiles::TileEx(10)->m_iSectorId = 9;
  CTiles::TileEx(32766)->m_uCenter = 0x7FFF;
  *(_DWORD *)&CTiles::TileEx(0x7FFF)->m_iSectorId = 32766;
  CTilesEx::m_iNumberOfUsedTiles = 0;
  CTilesEx::m_iLastUsedTileId = 9;
  CTilesEx::m_iTilesPushBackMode = 1;
  CTilesEx::m_iMaxUsedTiles = 0;
  CTilesEx::m_iCalcFreeListCounter = 0;
}


// address=[0x15e31c0]
// Decompiled from void __thiscall CTilesEx::DeactivateTilesPushBackMode(void *this)
void __cdecl CTilesEx::DeactivateTilesPushBackMode(void) {
  
  int v1; // [esp+0h] [ebp-4h]

  if ( CTilesEx::m_iTilesPushBackMode )
  {
    if ( CTilesEx::m_iLastUsedTileId == CTilesEx::m_iNumberOfUsedTiles + 9 )
    {
      v1 = CTilesEx::m_iLastUsedTileId + 1;
      CTiles::TileEx(9)->m_uCenter = v1;
      *(_DWORD *)&CTiles::TileEx(v1)->m_iSectorId = 9;
    }
    else
    {
      if ( BBSupportDbgReport(
             1,
             "Pathing\\TilesAndLinks.cpp",
             108,
             "CTiles::DeactivatePushBackMode(): Last used tile invalid!") == 1 )
        __debugbreak();
      CTilesEx::CalculateListOfFreeTiles();
    }
    CTilesEx::CalculateSquareTileLists();
    CTilesEx::m_iTilesPushBackMode = 0;
  }
}


// address=[0x15e3250]
// Decompiled from int CTilesEx::CalculateOwnerBits()
void __cdecl CTilesEx::CalculateOwnerBits(void) {
  
  return COwnerMapEx::CalculateOwnerBits();
}


// address=[0x15e3260]
// Decompiled from void __cdecl CTilesEx::InsertTileIntoSquareList(int a1)
void __cdecl CTilesEx::InsertTileIntoSquareList(int a1) {
  
  CTile *iPrevTileId; // eax
  CTile *v2; // eax
  int v3; // [esp+0h] [ebp-18h]
  int v4; // [esp+4h] [ebp-14h]
  int m_uFirst; // [esp+8h] [ebp-10h]
  int m_uLast; // [esp+Ch] [ebp-Ch]
  CTile *rTile; // [esp+10h] [ebp-8h]
  SFirstLast *rFirstLast; // [esp+14h] [ebp-4h]

  rTile = CTiles::TileEx(a1);
  if ( !CTile::Used(rTile) && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 159, "rTile.Used()") == 1 )
    __debugbreak();
  v3 = CTile::CenterX(rTile);
  v4 = CTile::CenterY(rTile);
  rFirstLast = CTiles::SquareFirstLastXY(v3, v4);
  if ( rFirstLast->m_uFirst )
  {
    if ( !rFirstLast->m_uLast )
    {
      if ( BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 170, "rFirstLast.m_uLast != 0") == 1 )
        __debugbreak();
      rFirstLast->m_uLast = rFirstLast->m_uFirst;
    }
    if ( (CTile::Type(rTile) & 0x8000000) != 0 )
    {
      m_uLast = rFirstLast->m_uLast;
      iPrevTileId = CTiles::TileEx(m_uLast);
      if ( !CTile::Used(iPrevTileId)
        && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 181, "TileEx(iPrevTileId).Used()") == 1 )
      {
        __debugbreak();
      }
      if ( CTiles::TileEx(m_uLast)->m_uSquareNext )
      {
        if ( BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 182, "TileEx(iPrevTileId).m_uSquareNext == 0") == 1 )
          __debugbreak();
      }
      CTiles::TileEx(m_uLast)->m_uSquareNext = a1;
      rTile->m_uSquarePrev = m_uLast;
      rTile->m_uSquareNext = 0;
      rFirstLast->m_uLast = a1;
    }
    else
    {
      m_uFirst = rFirstLast->m_uFirst;
      v2 = CTiles::TileEx(m_uFirst);
      if ( !CTile::Used(v2)
        && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 197, "TileEx(iNextTileId).Used()") == 1 )
      {
        __debugbreak();
      }
      if ( CTiles::TileEx(m_uFirst)->m_uSquarePrev
        && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 198, "TileEx(iNextTileId).m_uSquarePrev == 0") == 1 )
      {
        __debugbreak();
      }
      CTiles::TileEx(m_uFirst)->m_uSquarePrev = a1;
      rTile->m_uSquarePrev = 0;
      rTile->m_uSquareNext = m_uFirst;
      rFirstLast->m_uFirst = a1;
    }
  }
  else
  {
    if ( rFirstLast->m_uLast && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 212, "rFirstLast.m_uLast == 0") == 1 )
      __debugbreak();
    rFirstLast->m_uFirst = a1;
    rFirstLast->m_uLast = a1;
    rTile->m_uSquarePrev = 0;
    rTile->m_uSquareNext = 0;
  }
}


// address=[0x15e34f0]
// Decompiled from void __cdecl CTilesEx::DeleteTileFromSquareList(int _iTileId)
void __cdecl CTilesEx::DeleteTileFromSquareList(int _iTileId) {
  
  CTile *rTilePrev; // eax
  CTile *rTileNext; // eax
  int iX; // [esp+0h] [ebp-10h]
  int iY; // [esp+4h] [ebp-Ch]
  struct SFirstLast *rFirstLast; // [esp+8h] [ebp-8h]
  CTile *rTile; // [esp+Ch] [ebp-4h]

  rTile = CTiles::TileEx(_iTileId);
  iX = CTile::CenterX(rTile);
  iY = CTile::CenterY(rTile);
  rFirstLast = CTiles::SquareFirstLastXY(iX, iY);
  if ( rTile->m_uSquarePrev )
  {
    rTilePrev = CTiles::TileEx(rTile->m_uSquarePrev);
    if ( !CTile::Used(rTilePrev)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 238, "TileEx(rTile.m_uSquarePrev).Used()") == 1 )
    {
      __debugbreak();
    }
    if ( CTiles::TileEx(rTile->m_uSquarePrev)->m_uSquareNext != _iTileId
      && BBSupportDbgReport(
           2,
           "Pathing\\TilesAndLinks.cpp",
           239,
           "TileEx(rTile.m_uSquarePrev).m_uSquareNext == _iTileId") == 1 )
    {
      __debugbreak();
    }
    CTiles::TileEx(rTile->m_uSquarePrev)->m_uSquareNext = rTile->m_uSquareNext;
  }
  else
  {
    if ( rFirstLast->m_uFirst != _iTileId
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 245, "rFirstLast.m_uFirst == _iTileId") == 1 )
    {
      __debugbreak();
    }
    rFirstLast->m_uFirst = rTile->m_uSquareNext;
  }
  if ( rTile->m_uSquareNext )
  {
    rTileNext = CTiles::TileEx(rTile->m_uSquareNext);
    if ( !CTile::Used(rTileNext)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 252, "TileEx(rTile.m_uSquareNext).Used()") == 1 )
    {
      __debugbreak();
    }
    if ( CTiles::TileEx(rTile->m_uSquareNext)->m_uSquarePrev != _iTileId
      && BBSupportDbgReport(
           2,
           "Pathing\\TilesAndLinks.cpp",
           253,
           "TileEx(rTile.m_uSquareNext).m_uSquarePrev == _iTileId") == 1 )
    {
      __debugbreak();
    }
    CTiles::TileEx(rTile->m_uSquareNext)->m_uSquarePrev = rTile->m_uSquarePrev;
  }
  else
  {
    if ( rFirstLast->m_uLast != _iTileId
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 259, "rFirstLast.m_uLast == _iTileId") == 1 )
    {
      __debugbreak();
    }
    rFirstLast->m_uLast = rTile->m_uSquarePrev;
  }
}


// address=[0x15e36f0]
// Decompiled from void __cdecl CTilesEx::CalculateListOfFreeTiles()
void __cdecl CTilesEx::CalculateListOfFreeTiles(void) {
  
  CTile *v0; // eax
  int v1; // [esp+0h] [ebp-10h]
  int v2; // [esp+4h] [ebp-Ch]
  int v3; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  v1 = 9;
  v3 = 9;
  *(_DWORD *)&CTiles::TileEx(9)->m_iSectorId = 0;
  for ( i = 10; i <= 32766; ++i )
  {
    v0 = CTiles::TileEx(i);
    if ( CTile::Used(v0) )
    {
      ++v2;
      v1 = i;
    }
    else
    {
      *(_DWORD *)&CTiles::TileEx(i)->m_iSectorId = v3;
      CTiles::TileEx(v3)->m_uCenter = i;
      v3 = i;
    }
  }
  CTiles::TileEx(v3)->m_uCenter = 0x7FFF;
  *(_DWORD *)&CTiles::TileEx(0x7FFF)->m_iSectorId = v3;
  CTiles::TileEx(0x7FFF)->m_uCenter = 0;
  CTilesEx::m_iNumberOfUsedTiles = v2;
  CTilesEx::m_iLastUsedTileId = v1;
  if ( v2 > CTilesEx::m_iMaxUsedTiles )
    CTilesEx::m_iMaxUsedTiles = CTilesEx::m_iNumberOfUsedTiles;
  ++CTilesEx::m_iCalcFreeListCounter;
}


// address=[0x15e3810]
// Decompiled from void CTilesEx::CalculateSquareTileLists()
void __cdecl CTilesEx::CalculateSquareTileLists(void) {
  
  CTile *v0; // eax
  int UsedTileId; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  memset(&CTiles::m_sSquareFirstLastTiles, 0, 0x4200u);
  UsedTileId = CTilesEx::LastUsedTileId();
  for ( i = 10; i <= UsedTileId; ++i )
  {
    v0 = CTiles::TileEx(i);
    if ( CTile::Used(v0) )
      CTilesEx::InsertTileIntoSquareList(i);
  }
}


// address=[0x15e3880]
// Decompiled from int __cdecl CTilesEx::PushTileUndef()
int __cdecl CTilesEx::PushTileUndef(void) {
  
  CTile *v1; // eax
  DWORD v2; // [esp+0h] [ebp-8h]
  signed int m_uCenter; // [esp+4h] [ebp-4h]

  if ( CTilesEx::m_iTilesPushBackMode
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 345, "!m_iTilesPushBackMode") == 1 )
  {
    __debugbreak();
  }
  if ( CTilesEx::m_iNumberOfUsedTiles < 32757
    || (CTrace::Print("CTiles::PushTileUndef(): Tile limit exceeded. Rebuilding list of free tiles!"),
        CTilesEx::CalculateListOfFreeTiles(),
        CTilesEx::m_iNumberOfUsedTiles < 32757) )
  {
    m_uCenter = CTiles::TileEx(9)->m_uCenter;
    if ( CTiles::IsValidRealTile(m_uCenter)
      || (CTrace::Print("CTiles::PushTileUndef(): Invalid free tile id. Rebuilding list of free tiles!"),
          CTilesEx::CalculateListOfFreeTiles(),
          m_uCenter = CTiles::TileEx(9)->m_uCenter,
          CTiles::IsValidRealTile(m_uCenter)) )
    {
      v2 = CTiles::TileEx(m_uCenter)->m_uCenter;
      CTiles::TileEx(v2)->m_iSectorId = 9;
      CTiles::TileEx(9)->m_uCenter = v2;
      v1 = CTiles::TileEx(m_uCenter);
      CTile::SetType(v1, 0);
      ++CTilesEx::m_iNumberOfUsedTiles;
      if ( m_uCenter > CTilesEx::m_iLastUsedTileId )
        CTilesEx::m_iLastUsedTileId = m_uCenter;
      if ( CTilesEx::m_iNumberOfUsedTiles > CTilesEx::m_iMaxUsedTiles )
        CTilesEx::m_iMaxUsedTiles = CTilesEx::m_iNumberOfUsedTiles;
      return m_uCenter;
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
// Decompiled from int __cdecl CTilesEx::PushTilesBackUndef(int _iCount)
int __cdecl CTilesEx::PushTilesBackUndef(int _iCount) {
  
  int v2; // [esp+0h] [ebp-4h]

  if ( !CTilesEx::m_iTilesPushBackMode
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 128, "m_iTilesPushBackMode") == 1 )
  {
    __debugbreak();
  }
  if ( _iCount + CTilesEx::m_iNumberOfUsedTiles > 32757
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 129, "m_iNumberOfUsedTiles + _iCount <= TILES_MAX_NUMBER") == 1 )
  {
    __debugbreak();
  }
  v2 = CTilesEx::m_iLastUsedTileId;
  CTilesEx::m_iNumberOfUsedTiles += _iCount;
  CTilesEx::m_iLastUsedTileId += _iCount;
  if ( CTilesEx::m_iNumberOfUsedTiles > CTilesEx::m_iMaxUsedTiles )
    CTilesEx::m_iMaxUsedTiles = CTilesEx::m_iNumberOfUsedTiles;
  return v2 + 1;
}


// address=[0x15e3ac0]
// Decompiled from int __cdecl CTilesEx::PushTile(int a1, int a2)
int __cdecl CTilesEx::PushTile(int a1, int a2) {
  
  CTile *v2; // eax
  struct CLinkList *v4; // [esp-4h] [ebp-Ch]
  int v5; // [esp+4h] [ebp-4h]

  v5 = CTilesEx::PushTileUndef();
  v4 = CLinks::LinkList(0);
  v2 = CTiles::TileEx(v5);
  CTile::Init(v2, a1, a2, v4);
  CTilesEx::InsertTileIntoSquareList(v5);
  if ( (a1 & 0xF) != 0 )
    COwnerMapEx::NotifyCreateTile(a2, a1 & 0xF);
  return v5;
}


// address=[0x15e3b30]
// Decompiled from int __cdecl CTilesEx::DuplicateTile(int a1)
int __cdecl CTilesEx::DuplicateTile(int a1) {
  
  struct CLinkList *v1; // eax
  int v3; // [esp+0h] [ebp-8h]
  CTile *v4; // [esp+4h] [ebp-4h]

  v3 = CTilesEx::PushTileUndef();
  v4 = CTiles::TileEx(v3);
  *v4 = *CTiles::TileEx(a1);
  v1 = CLinks::LinkList(0);
  CTile::SetLinkList(v4, v1);
  CTile::SetSize(v4, 0);
  CTilesEx::InsertTileIntoSquareList(v3);
  return v3;
}


// address=[0x15e3bb0]
// Decompiled from void __cdecl CTilesEx::DeleteTile(int a1)
void __cdecl CTilesEx::DeleteTile(int a1) {
  
  int v1; // eax
  CTile *v2; // eax
  DWORD m_uCenter; // [esp+0h] [ebp-10h]
  int v4; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  CTile *v6; // [esp+Ch] [ebp-4h]

  if ( CTilesEx::IsValidUsedTile(a1) )
  {
    v6 = CTiles::TileEx(a1);
    CTilesEx::DeleteTileFromSquareList(a1);
    v4 = CTile::OwnerId(v6);
    if ( v4 )
    {
      v1 = CTile::CenterXY(v6);
      COwnerMapEx::NotifyDeleteTile(v1, v4);
    }
    CTile::SetType(v6, 0xFFFFFFFF);
    m_uCenter = CTiles::TileEx(9)->m_uCenter;
    CTiles::TileEx(9)->m_uCenter = a1;
    *(_DWORD *)&v6->m_iSectorId = 9;
    v6->m_uCenter = m_uCenter;
    *(_DWORD *)&CTiles::TileEx(m_uCenter)->m_iSectorId = a1;
    if ( --CTilesEx::m_iNumberOfUsedTiles < 0 )
      CTilesEx::CalculateListOfFreeTiles();
    if ( CTilesEx::m_iLastUsedTileId == a1 )
    {
      for ( i = a1 - 1; ; --i )
      {
        v2 = CTiles::TileEx(i);
        if ( !CTile::Unused(v2) )
          break;
      }
      CTilesEx::m_iLastUsedTileId = i;
    }
  }
  else if ( "CTilesEx::DeleteTile(): Not a used real tile!" )
  {
    if ( BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 484, "!\"CTilesEx::DeleteTile(): Not a used real tile!\"") == 1 )
      __debugbreak();
  }
}


// address=[0x15e7050]
// Decompiled from char __cdecl CTilesEx::IsUsedRealTile(int a1)
bool __cdecl CTilesEx::IsUsedRealTile(int a1) {
  
  CTile *v1; // eax
  char v3; // [esp+0h] [ebp-4h]

  v3 = 0;
  if ( !CTiles::IsValidRealTile(a1) )
    return v3;
  v1 = CTiles::TileEx(a1);
  if ( CTile::Used(v1) )
    return 1;
  return v3;
}


// address=[0x15e71c0]
// Decompiled from char __cdecl CTilesEx::IsValidUsedTile(int a1)
bool __cdecl CTilesEx::IsValidUsedTile(int a1) {
  
  CTile *v1; // eax
  char v3; // [esp+0h] [ebp-4h]

  v3 = 0;
  if ( !CTiles::IsValidRealTile(a1) )
    return v3;
  v1 = CTiles::TileEx(a1);
  if ( CTile::Used(v1) )
    return 1;
  return v3;
}


// address=[0x15e7220]
// Decompiled from int CTilesEx::LastUsedTileId()
int __cdecl CTilesEx::LastUsedTileId(void) {
  
  return CTilesEx::m_iLastUsedTileId;
}


// address=[0x15f5230]
// Decompiled from int CTilesEx::NumberOfUsedTiles()
int __cdecl CTilesEx::NumberOfUsedTiles(void) {
  
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

#endif // Already implemented
