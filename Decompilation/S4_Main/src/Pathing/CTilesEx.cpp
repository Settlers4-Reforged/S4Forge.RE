#include "CTilesEx.h"

#include "CLinks.h"
#include "CTile.h"
#include "CTiles.h"
#include "CBB/CBBSupport.h"
#include "Debug/CTrace.h"
#include "MapObjects/COwnerMapEx.h"

// Definitions for class CTilesEx

// address=[0x15e3040]
// Decompiled from void __cdecl CTilesEx::InitTiles(struct CLinkList *a1)
void __cdecl CTilesEx::InitTiles(class CLinkList &a1) {
  // [esp+4h] [ebp-8h]
  // [esp+8h] [ebp-4h]

  CTiles::TileEx(0).InitPseudoTile(0, a1);
  for(int i = 1; i <= 8; ++i) {
    CTiles::TileEx(i).InitPseudoTile(i, a1);
  }

  CTiles::TileEx(9).InitPseudoTile(0, a1);
  CTiles::TileEx(9).SetType(-3);
  CTiles::TileEx(0x7FFF).InitPseudoTile(0, a1);
  CTiles::TileEx(0x7FFF).SetType(-2);
  for(int16_t j = 10; j <= 32766; ++j) {
    CTile &v7 = CTiles::TileEx(j);
    v7.SetType(-1);
    v7.m_iSectorId = j - 1;
    v7.m_iEcoSectorId = 0;
    v7.m_uCenter = j + 1;
  }
  CTiles::TileEx(9).m_uCenter = 10;
  CTiles::TileEx(10).m_iSectorId = 9;
  CTiles::TileEx(10).m_iEcoSectorId = 0;
  CTiles::TileEx(32766).m_uCenter = 0x7FFF;
  CTiles::TileEx(0x7FFF).m_iSectorId = 32766;
  CTiles::TileEx(0x7FFF).m_iEcoSectorId = 0;
  CTilesEx::m_iNumberOfUsedTiles = 0;
  CTilesEx::m_iLastUsedTileId = 9;
  CTilesEx::m_iTilesPushBackMode = 1;
  CTilesEx::m_iMaxUsedTiles = 0;
  CTilesEx::m_iCalcFreeListCounter = 0;
}


// address=[0x15e31c0]
// Decompiled from void __thiscall CTilesEx::DeactivateTilesPushBackMode(void *this)
void __cdecl CTilesEx::DeactivateTilesPushBackMode(void) {
  // [esp+0h] [ebp-4h]

  if(CTilesEx::m_iTilesPushBackMode) {
    if(CTilesEx::m_iLastUsedTileId == CTilesEx::m_iNumberOfUsedTiles + 9) {
      int v2 = CTilesEx::m_iLastUsedTileId + 1;
      CTiles::TileEx(9).m_uCenter = v2;
      CTiles::TileEx(v2).m_iSectorId = 9;
      CTiles::TileEx(v2).m_iEcoSectorId = 0;
    } else {
      if(BBSupportDbgReport(
           1,
           "Pathing\\TilesAndLinks.cpp",
           108,
           "CTiles::DeactivatePushBackMode(): Last used tile invalid!") == 1)
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
  CTile &rTile = CTiles::TileEx(a1);
  if(!rTile.Used() && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 159, "rTile.Used()") == 1)
    __debugbreak();

  CTiles::SFirstLast &rFirstLast = CTiles::SquareFirstLastXY(rTile.CenterX(), rTile.CenterY());
  if(rFirstLast.m_uFirst) {
    if(!rFirstLast.m_uLast) {
      if(BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 170, "rFirstLast.m_uLast != 0") == 1)
        __debugbreak();
      rFirstLast.m_uLast = rFirstLast.m_uFirst;
    }
    if((rTile.Type() & 0x8000000) != 0) {
      int iPrevTileId = rFirstLast.m_uLast;
      if(!CTiles::TileEx(iPrevTileId).Used()
         && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 181, "TileEx(iPrevTileId).Used()") == 1) {
        __debugbreak();
      }
      if(CTiles::TileEx(iPrevTileId).m_uSquareNext) {
        if(BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 182, "TileEx(iPrevTileId).m_uSquareNext == 0") == 1)
          __debugbreak();
      }
      CTiles::TileEx(iPrevTileId).m_uSquareNext = a1;
      rTile.m_uSquarePrev = iPrevTileId;
      rTile.m_uSquareNext = 0;
      rFirstLast.m_uLast = a1;
    } else {
      int iNextTileId = rFirstLast.m_uFirst;
      if(!CTiles::TileEx(iNextTileId).Used()
         && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 197, "TileEx(iNextTileId).Used()") == 1) {
        __debugbreak();
      }
      if(CTiles::TileEx(iNextTileId).m_uSquarePrev
         && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 198, "TileEx(iNextTileId).m_uSquarePrev == 0") == 1) {
        __debugbreak();
      }
      CTiles::TileEx(iNextTileId).m_uSquarePrev = a1;
      rTile.m_uSquarePrev = 0;
      rTile.m_uSquareNext = iNextTileId;
      rFirstLast.m_uFirst = a1;
    }
  } else {
    if(rFirstLast.m_uLast && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 212, "rFirstLast.m_uLast == 0") == 1)
      __debugbreak();
    rFirstLast.m_uFirst = a1;
    rFirstLast.m_uLast = a1;
    rTile.m_uSquarePrev = 0;
    rTile.m_uSquareNext = 0;
  }
}


// address=[0x15e34f0]
// Decompiled from void __cdecl CTilesEx::DeleteTileFromSquareList(int _iTileId)
void __cdecl CTilesEx::DeleteTileFromSquareList(int _iTileId) {
  CTile &rTile = CTiles::TileEx(_iTileId);

  CTiles::SFirstLast &rFirstLast = CTiles::SquareFirstLastXY(rTile.CenterX(), rTile.CenterY());
  if(rTile.m_uSquarePrev) {
    if(!CTiles::TileEx(rTile.m_uSquarePrev).Used()
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 238, "TileEx(rTile.m_uSquarePrev).Used()") == 1) {
      __debugbreak();
    }
    if(CTiles::TileEx(rTile.m_uSquarePrev).m_uSquareNext != _iTileId
       && BBSupportDbgReport(
         2,
         "Pathing\\TilesAndLinks.cpp",
         239,
         "TileEx(rTile.m_uSquarePrev).m_uSquareNext == _iTileId") == 1) {
      __debugbreak();
    }
    CTiles::TileEx(rTile.m_uSquarePrev).m_uSquareNext = rTile.m_uSquareNext;
  } else {
    if(rFirstLast.m_uFirst != _iTileId
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 245, "rFirstLast.m_uFirst == _iTileId") == 1) {
      __debugbreak();
    }
    rFirstLast.m_uFirst = rTile.m_uSquareNext;
  }
  if(rTile.m_uSquareNext) {
    if(!CTiles::TileEx(rTile.m_uSquareNext).Used()
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 252, "TileEx(rTile.m_uSquareNext).Used()") == 1) {
      __debugbreak();
    }
    if(CTiles::TileEx(rTile.m_uSquareNext).m_uSquarePrev != _iTileId
       && BBSupportDbgReport(
         2,
         "Pathing\\TilesAndLinks.cpp",
         253,
         "TileEx(rTile.m_uSquareNext).m_uSquarePrev == _iTileId") == 1) {
      __debugbreak();
    }
    CTiles::TileEx(rTile.m_uSquareNext).m_uSquarePrev = rTile.m_uSquarePrev;
  } else {
    if(rFirstLast.m_uLast != _iTileId
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 259, "rFirstLast.m_uLast == _iTileId") == 1) {
      __debugbreak();
    }
    rFirstLast.m_uLast = rTile.m_uSquarePrev;
  }
}


// address=[0x15e36f0]
// Decompiled from void __cdecl CTilesEx::CalculateListOfFreeTiles()
void __cdecl CTilesEx::CalculateListOfFreeTiles(void) {
  CTile *v0; // eax
  // [esp+0h] [ebp-10h]
  // [esp+4h] [ebp-Ch]
  // [esp+8h] [ebp-8h]
  // [esp+Ch] [ebp-4h]

  int v2 = 0;
  int v1 = 9;
  int v3 = 9;
  CTiles::TileEx(9).m_iSectorId = 0;
  CTiles::TileEx(9).m_iEcoSectorId = 0;

  for(int16_t i = 10; i <= 32766; ++i) {
    if(CTiles::TileEx(i).Used()) {
      ++v2;
      v1 = i;
    } else {
      CTiles::TileEx(i).m_iSectorId = v3;
      CTiles::TileEx(9).m_iEcoSectorId = 0;
      CTiles::TileEx(v3).m_uCenter = i;
      v3 = i;
    }
  }
  CTiles::TileEx(v3).m_uCenter = 0x7FFF;
  CTiles::TileEx(0x7FFF).m_iSectorId = v3;
  CTiles::TileEx(0x7FFF).m_iEcoSectorId = 0;
  CTiles::TileEx(0x7FFF).m_uCenter = 0;
  CTilesEx::m_iNumberOfUsedTiles = v2;
  CTilesEx::m_iLastUsedTileId = v1;
  if(v2 > CTilesEx::m_iMaxUsedTiles)
    CTilesEx::m_iMaxUsedTiles = CTilesEx::m_iNumberOfUsedTiles;
  ++CTilesEx::m_iCalcFreeListCounter;
}


// address=[0x15e3810]
// Decompiled from void CTilesEx::CalculateSquareTileLists()
void __cdecl CTilesEx::CalculateSquareTileLists(void) {
  CTile *v0; // eax
  // [esp+0h] [ebp-8h]
  // [esp+4h] [ebp-4h]

  memset(CTiles::m_sSquareFirstLastTiles, 0, 0x4200u);
  int UsedTileId = CTilesEx::LastUsedTileId();
  for(int i = 10; i <= UsedTileId; ++i) {
    if(CTiles::TileEx(i).Used())
      CTilesEx::InsertTileIntoSquareList(i);
  }
}


// address=[0x15e3880]
// Decompiled from int __cdecl CTilesEx::PushTileUndef()
int __cdecl CTilesEx::PushTileUndef(void) {
  CTile *v1; // eax
  // [esp+0h] [ebp-8h]
  // [esp+4h] [ebp-4h]

  if(CTilesEx::m_iTilesPushBackMode
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 345, "!m_iTilesPushBackMode") == 1) {
    __debugbreak();
  }
  if(CTilesEx::m_iNumberOfUsedTiles < 32757
     || (CTrace::Print("CTiles::PushTileUndef(): Tile limit exceeded. Rebuilding list of free tiles!"),
         CTilesEx::CalculateListOfFreeTiles(),
         CTilesEx::m_iNumberOfUsedTiles < 32757)) {
    signed int m_uCenter = CTiles::TileEx(9).m_uCenter;
    if(CTiles::IsValidRealTile(m_uCenter)
       || (CTrace::Print("CTiles::PushTileUndef(): Invalid free tile id. Rebuilding list of free tiles!"),
           CTilesEx::CalculateListOfFreeTiles(),
           m_uCenter = CTiles::TileEx(9).m_uCenter,
           CTiles::IsValidRealTile(m_uCenter))) {
      DWORD v2 = CTiles::TileEx(m_uCenter).m_uCenter;
      CTiles::TileEx(v2).m_iSectorId = 9;
      CTiles::TileEx(9).m_uCenter = v2;
      CTiles::TileEx(m_uCenter).SetType(0);
      ++CTilesEx::m_iNumberOfUsedTiles;
      if(m_uCenter > CTilesEx::m_iLastUsedTileId)
        CTilesEx::m_iLastUsedTileId = m_uCenter;
      if(CTilesEx::m_iNumberOfUsedTiles > CTilesEx::m_iMaxUsedTiles)
        CTilesEx::m_iMaxUsedTiles = CTilesEx::m_iNumberOfUsedTiles;
      return m_uCenter;
    } else {
      if(BBSupportDbgReport(1, "Pathing\\TilesAndLinks.cpp", 381, "Tiling: No free tile found!") == 1)
        __debugbreak();
      return 0;
    }
  } else {
    if(BBSupportDbgReport(1, "Pathing\\TilesAndLinks.cpp", 359, "Tiling: Out of tiles!") == 1)
      __debugbreak();
    return 0;
  }
}


// address=[0x15e3a10]
// Decompiled from int __cdecl CTilesEx::PushTilesBackUndef(int _iCount)
int __cdecl CTilesEx::PushTilesBackUndef(int _iCount) {
  // [esp+0h] [ebp-4h]

  if(!CTilesEx::m_iTilesPushBackMode
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 128, "m_iTilesPushBackMode") == 1) {
    __debugbreak();
  }
  if(_iCount + CTilesEx::m_iNumberOfUsedTiles > 32757
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 129, "m_iNumberOfUsedTiles + _iCount <= TILES_MAX_NUMBER") == 1) {
    __debugbreak();
  }
  int v2 = CTilesEx::m_iLastUsedTileId;
  CTilesEx::m_iNumberOfUsedTiles += _iCount;
  CTilesEx::m_iLastUsedTileId += _iCount;
  if(CTilesEx::m_iNumberOfUsedTiles > CTilesEx::m_iMaxUsedTiles)
    CTilesEx::m_iMaxUsedTiles = CTilesEx::m_iNumberOfUsedTiles;
  return v2 + 1;
}


// address=[0x15e3ac0]
// Decompiled from int __cdecl CTilesEx::PushTile(int a1, int a2)
int __cdecl CTilesEx::PushTile(int a1, int a2) {
  int               v5 = CTilesEx::PushTileUndef();
  struct CLinkList &v4 = CLinks::LinkList(0);
  CTiles::TileEx(v5).Init(a1, a2, v4);
  CTilesEx::InsertTileIntoSquareList(v5);
  if((a1 & 0xF) != 0)
    COwnerMapEx::NotifyCreateTile(a2, a1 & 0xF);
  return v5;
}


// address=[0x15e3b30]
// Decompiled from int __cdecl CTilesEx::DuplicateTile(int a1)
int __cdecl CTilesEx::DuplicateTile(int a1) {
  // eax
  // [esp+0h] [ebp-8h]

  int    v3 = CTilesEx::PushTileUndef();
  CTile &v4 = CTiles::TileEx(v3);
  v4 = CTiles::TileEx(a1);
  struct CLinkList &v1 = CLinks::LinkList(0);
  v4.SetLinkList(v1);
  v4.SetSize(0);
  CTilesEx::InsertTileIntoSquareList(v3);
  return v3;
}


// address=[0x15e3bb0]
// Decompiled from void __cdecl CTilesEx::DeleteTile(int a1)
void __cdecl CTilesEx::DeleteTile(int a1) {
  if(CTilesEx::IsValidUsedTile(a1)) {
    CTile &v6 = CTiles::TileEx(a1);
    CTilesEx::DeleteTileFromSquareList(a1);
    int v4 = v6.OwnerId();
    if(v4) {
      COwnerMapEx::NotifyDeleteTile(v6.CenterXY(), v4);
    }
    v6.SetType(0xFFFFFFFF);
    DWORD m_uCenter = CTiles::TileEx(9).m_uCenter;
    CTiles::TileEx(9).m_uCenter = a1;
    v6.m_iSectorId = 9;
    v6.m_iEcoSectorId = 0;
    v6.m_uCenter = m_uCenter;
    CTiles::TileEx(m_uCenter).m_iSectorId = a1;
    CTiles::TileEx(m_uCenter).m_iEcoSectorId = 0;
    if(--CTilesEx::m_iNumberOfUsedTiles < 0)
      CTilesEx::CalculateListOfFreeTiles();
    if(CTilesEx::m_iLastUsedTileId == a1) {
      int i;
      for(i = a1 - 1; ; --i) {
        if(!CTiles::TileEx(i).Unused())
          break;
      }
      CTilesEx::m_iLastUsedTileId = i;
    }
  } else if("CTilesEx::DeleteTile(): Not a used real tile!") {
    if(BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 484, "!\"CTilesEx::DeleteTile(): Not a used real tile!\"") == 1)
      __debugbreak();
  }
}


// address=[0x15e7050]
// Decompiled from char __cdecl CTilesEx::IsUsedRealTile(int a1)
bool __cdecl CTilesEx::IsUsedRealTile(int a1) {
  char v3 = 0;
  if(!CTiles::IsValidRealTile(a1))
    return v3;
  if(CTiles::TileEx(a1).Used())
    return 1;
  return v3;
}


// address=[0x15e71c0]
// Decompiled from char __cdecl CTilesEx::IsValidUsedTile(int a1)
bool __cdecl CTilesEx::IsValidUsedTile(int a1) {
  char v3 = 0;
  if(!CTiles::IsValidRealTile(a1))
    return v3;

  if(CTiles::TileEx(a1).Used())
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

