#include "CTiling.h"

// Definitions for class CTiling

// address=[0x15e7bb0]
// Decompiled from int CTiling::BlockBorder()
static void __cdecl CTiling::BlockBorder(void) {
  
  int result; // eax
  int v1; // [esp+0h] [ebp-10h]
  int v2; // [esp+4h] [ebp-Ch]
  int v3; // [esp+8h] [ebp-8h]
  int v4; // [esp+8h] [ebp-8h]
  int v5; // [esp+8h] [ebp-8h]
  int v6; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]
  int j; // [esp+Ch] [ebp-4h]
  int k; // [esp+Ch] [ebp-4h]
  int m; // [esp+Ch] [ebp-4h]

  v2 = CTilingWorld::WorldWidthHeight();
  v1 = CTilingWorld::WorldIndex(0, 1);
  v3 = 0;
  for ( i = 0; i < v2; ++i )
    CTilingWorld::WorldSetBlockedLandFlag(v3++);
  v4 = CTilingWorld::WorldIndex(0, v2 - 1);
  for ( j = 0; j < v2; ++j )
    CTilingWorld::WorldSetBlockedLandFlag(v4++);
  v5 = 0;
  for ( k = 0; k < v2; ++k )
  {
    CTilingWorld::WorldSetBlockedLandFlag(v5);
    v5 += v1;
  }
  v6 = CTilingWorld::WorldIndex(v2 - 1, 0);
  for ( m = 0; ; ++m )
  {
    result = m;
    if ( m >= v2 )
      break;
    CTilingWorld::WorldSetBlockedLandFlag(v6);
    v6 += v1;
  }
  return result;
}


// address=[0x15e7cd0]
// Decompiled from int CTiling::PrepareReCalculate()
static void __cdecl CTiling::PrepareReCalculate(void) {
  
  CTile *v0; // eax
  __int16 v1; // ax
  int v3; // [esp+0h] [ebp-14h]
  int v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v5 = CTilingWorld::WorldWidthHeight();
  for ( i = 0; i < v5 * v5; ++i )
  {
    v4 = ITiling::NormalTileId(i);
    v0 = (CTile *)ITiling::Tile(v4);
    v3 = CTile::OwnerId(v0);
    v1 = ITiling::OwnerPseudoTileId(v3);
    CTiling::SetNormalTileId(i, v1);
  }
  j__memset(*(&ITiling::m_pTileIds + 1), 0, 2 * v5);
  return CTiling::ClearBorderstoneBits(v3, v4);
}


// address=[0x15e7d80]
// Decompiled from void CTiling::CalcSquareComponents()
static void __cdecl CTiling::CalcSquareComponents(void) {
  
  int v0; // [esp+14h] [ebp-38h]
  int v1; // [esp+20h] [ebp-2Ch]
  int v2; // [esp+24h] [ebp-28h]
  int v3; // [esp+28h] [ebp-24h]
  int v4; // [esp+2Ch] [ebp-20h]
  int v5; // [esp+30h] [ebp-1Ch]
  int i; // [esp+34h] [ebp-18h]
  int v7; // [esp+38h] [ebp-14h]
  int v8; // [esp+3Ch] [ebp-10h]
  int k; // [esp+40h] [ebp-Ch]
  int j; // [esp+44h] [ebp-8h]
  int v11; // [esp+48h] [ebp-4h]

  v8 = -1;
  for ( i = 0; i < 16; ++i )
  {
    v5 = dword_42F7C68[CSquare::Index(i, 0)];
    if ( v5 >= 0 )
    {
      if ( v8 >= 0 )
      {
        if ( v5 != dword_42F7C68[CSquare::Index(i - 1, 0)] )
        {
          CSquare::AddComponet((CSquare *)&dword_42F7C50, v8);
          v8 = CSquare::NewArea((CSquare *)&dword_42F7C50, v5);
        }
      }
      else
      {
        v8 = CSquare::NewArea((CSquare *)&dword_42F7C50, v5);
      }
      dword_42F8068[CSquare::Index(i, 0)] = v8;
    }
    else
    {
      if ( v8 >= 0 )
      {
        CSquare::AddComponet((CSquare *)&dword_42F7C50, v8);
        v8 = -1;
      }
      dword_42F8068[CSquare::Index(i, 0)] = -1;
    }
  }
  if ( v8 >= 0 )
    CSquare::AddComponet((CSquare *)&dword_42F7C50, v8);
  for ( j = 1; j < 16; ++j )
  {
    v4 = dword_42F7C68[CSquare::Index(0, j)];
    if ( v4 >= 0 )
    {
      if ( v4 == dword_42F7C68[CSquare::Index(0, j - 1)] )
        v11 = dword_42F8068[CSquare::Index(0, j - 1)];
      else
        v11 = CSquare::NewArea((CSquare *)&dword_42F7C50, v4);
      dword_42F8068[CSquare::Index(0, j)] = v11;
    }
    else
    {
      v11 = -1;
      dword_42F8068[CSquare::Index(0, j)] = -1;
    }
    for ( k = 1; k < 16; ++k )
    {
      v7 = dword_42F7C68[CSquare::Index(k, j)];
      if ( v7 >= 0 )
      {
        v3 = dword_42F8068[CSquare::Index(k - 1, j - 1)];
        v2 = dword_42F8068[CSquare::Index(k, j - 1)];
        v1 = dword_42F7C68[CSquare::Index(k - 1, j - 1)];
        v0 = dword_42F7C68[CSquare::Index(k, j - 1)];
        if ( v11 >= 0 )
        {
          if ( v7 != dword_42F7C68[CSquare::Index(k - 1, j)] )
          {
            CSquare::AddComponentIfNecessary((CSquare *)&dword_42F7C50, v11);
            v11 = CSquare::NewArea((CSquare *)&dword_42F7C50, v7);
          }
          if ( v11 != v3 && v7 == v1 )
          {
            CSquare::ConnectAreas((CSquare *)&dword_42F7C50, v11, v3);
          }
          else if ( v11 != v2 && v7 == v0 )
          {
            CSquare::ConnectAreas((CSquare *)&dword_42F7C50, v11, v2);
          }
        }
        else if ( v7 == v1 )
        {
          v11 = v3;
        }
        else if ( v7 == v0 )
        {
          v11 = v2;
        }
        else
        {
          v11 = CSquare::NewArea((CSquare *)&dword_42F7C50, v7);
        }
        dword_42F8068[CSquare::Index(k, j)] = v11;
      }
      else
      {
        if ( v11 >= 0 )
        {
          CSquare::AddComponentIfNecessary((CSquare *)&dword_42F7C50, v11);
          v11 = -1;
        }
        dword_42F8068[CSquare::Index(k, j)] = -1;
      }
    }
    if ( v11 >= 0 )
      CSquare::AddComponentIfNecessary((CSquare *)&dword_42F7C50, v11);
  }
}


// address=[0x15e81a0]
// Decompiled from int __cdecl CTiling::CalcSquareTiles(int a1)
static void __cdecl CTiling::CalcSquareTiles(enum T_TILING_TYPE) {
  
  int v1; // eax
  int v2; // eax
  int result; // eax
  int **v4; // eax
  int **v5; // eax
  int **v6; // eax
  DWORD v7; // [esp+0h] [ebp-34h]
  int v8; // [esp+4h] [ebp-30h]
  int v9; // [esp+8h] [ebp-2Ch]
  int v10; // [esp+Ch] [ebp-28h]
  int v11; // [esp+10h] [ebp-24h]
  int v12; // [esp+14h] [ebp-20h]
  int v13; // [esp+18h] [ebp-1Ch]
  int v14; // [esp+1Ch] [ebp-18h]
  int v15; // [esp+1Ch] [ebp-18h]
  int v16; // [esp+20h] [ebp-14h] BYREF
  int v17; // [esp+24h] [ebp-10h]
  int j; // [esp+28h] [ebp-Ch]
  int i; // [esp+2Ch] [ebp-8h]
  int k; // [esp+30h] [ebp-4h]

  v10 = CTilesEx::LastUsedTileId() + 1;
  CSquare::CalcComponentTileIndices((CSquare *)&dword_42F7C50, v10);
  CTilesEx::PushTilesBackUndef(dword_4300868);
  BB::ZeroMemPtr(&unk_4300A6C, 0x400u);
  v1 = CTilingWorld::WorldIndex(dword_42F7C50, dword_42F7C54);
  CTileIdRef::CTileIdRef(&v16, a1, v1);
  for ( i = 0; i < 16; ++i )
  {
    for ( j = 0; j < 16; ++j )
    {
      v12 = dword_42F8068[CSquare::Index(j, i)];
      if ( v12 >= 0 )
      {
        v11 = dword_42F8468[v12];
        CTileIdRef::SetTileId((CTileIdRef *)&v16, dword_430086C[v11]);
        CCenter::Add((CCenter *)((char *)&unk_4300A6C + 8 * v11), j, i);
      }
      CTileIdRef::operator++(&v16);
    }
    v2 = CTilingWorld::WorldIndex(-16, 1);
    CTileIdRef::operator+=(&v16, v2);
  }
  for ( k = 0; ; ++k )
  {
    result = k;
    if ( k >= dword_42F7C64 )
      break;
    if ( !(unsigned __int8)TStaticArray<int,63>::Empty((char *)&unk_42F8868 + 256 * k) )
    {
      v13 = CCenter::Count((CCenter *)((char *)&unk_4300A6C + 8 * k));
      v8 = CCenter::X((CCenter *)((char *)&unk_4300A6C + 8 * k));
      v9 = CCenter::Y((CCenter *)((char *)&unk_4300A6C + 8 * k));
      v14 = Y16X16::PackXYFast(dword_42F7C50 + v8 / v13, dword_42F7C54 + v9 / v13);
      v17 = dword_430086C[k];
      v7 = dword_42F8668[*(_DWORD *)TStaticArray<int,63>::operator[](0)];
      v15 = CTiling::SearchForNearestTileElement(v14, v17, a1);
      v4 = CTiles::TileEx(v17);
      CTile::SetType((CTile *)v4, v7);
      v5 = CTiles::TileEx(v17);
      CTile::SetCenterXY((CTile *)v5, v15);
      v6 = CTiles::TileEx(v17);
      CTile::SetSize((CTile *)v6, v13);
    }
  }
  return result;
}


// address=[0x15f3f30]
// Decompiled from CTiling *__thiscall CTiling::CTiling(CTiling *this)
 CTiling::CTiling(void) {
  
  ITiling::ITiling(this);
  *(_DWORD *)this = &CTiling::_vftable_;
  return this;
}


// address=[0x15f4600]
// Decompiled from int __cdecl CTiling::GetTilingType(int a1)
static enum T_TILING_TYPE __cdecl CTiling::GetTilingType(int) {
  
  return CTile::TilingType(&CTiles::m_cTiles[a1]);
}


// address=[0x15f58b0]
// Decompiled from __int16 __cdecl CTiling::SetTileId(int a1, int a2, __int16 a3)
static void __cdecl CTiling::SetTileId(enum T_TILING_TYPE,int,int) {
  
  __int16 result; // ax

  result = a3;
  (&ITiling::m_pTileIds)[a1][a2] = a3;
  return result;
}


// address=[0x15f5940]
// Decompiled from int __cdecl CTiling::TileId(int a1, int a2)
static int __cdecl CTiling::TileId(enum T_TILING_TYPE,int) {
  
  return (unsigned __int16)(&ITiling::m_pTileIds)[a1][a2];
}


// address=[0x15e83e0]
// Decompiled from int __cdecl CTiling::SearchForNearestTileElement(int a1, int a2, int a3)
static int __cdecl CTiling::SearchForNearestTileElement(int,int,enum T_TILING_TYPE) {
  
  int v4; // [esp+0h] [ebp-30h]
  int v5; // [esp+4h] [ebp-2Ch]
  int v6; // [esp+8h] [ebp-28h]
  int v7; // [esp+Ch] [ebp-24h]
  int v8; // [esp+10h] [ebp-20h]
  unsigned int v9; // [esp+14h] [ebp-1Ch]
  unsigned int v10; // [esp+18h] [ebp-18h]
  _BYTE v11[4]; // [esp+1Ch] [ebp-14h] BYREF
  int v12; // [esp+20h] [ebp-10h]
  int v13; // [esp+24h] [ebp-Ch]
  int j; // [esp+28h] [ebp-8h]
  int i; // [esp+2Ch] [ebp-4h]

  if ( !CTilingWorld::WorldInWorldPackedXY(a1)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2016, "WorldInWorldPackedXY(_iStartPackedXY)") == 1 )
  {
    __debugbreak();
  }
  CTileIdRef::CTileIdRef(v11, a3, 0);
  v6 = CTilingWorld::WorldIndex(a1);
  if ( CTileIdRef::TileId((CTileIdRef *)v11, v6) == a2 )
    return a1;
  v13 = Y16X16::UnpackXFast(a1);
  v12 = Y16X16::UnpackYFast(a1);
  if ( CTilingWorld::WorldInInnerWorld16(v13, v12) )
  {
    for ( i = 1; i < SurroundingHexPointsCount(15); ++i )
    {
      v7 = v13 + g_sSurroundingHexPoints8[4 * i];
      v8 = v12 + byte_37D8D91[4 * i];
      v5 = CTilingWorld::WorldIndex(v7, v8);
      if ( CTileIdRef::TileId((CTileIdRef *)v11, v5) == a2 )
        return Y16X16::PackXYFast(v7, v8);
    }
  }
  else
  {
    for ( j = 1; j < SurroundingHexPointsCount(15); ++j )
    {
      v9 = v13 + g_sSurroundingHexPoints8[4 * j];
      v10 = v12 + byte_37D8D91[4 * j];
      if ( CTilingWorld::WorldInWorld(v9, v10) )
      {
        v4 = CTilingWorld::WorldIndex(v9, v10);
        if ( CTileIdRef::TileId((CTileIdRef *)v11, v4) == a2 )
          return Y16X16::PackXYFast(v9, v10);
      }
    }
  }
  if ( !"CTiling::SearchForNearestTileElement failed!" )
    return a1;
  if ( BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2061, "!\"CTiling::SearchForNearestTileElement failed!\"") == 1 )
    __debugbreak();
  return a1;
}


// address=[0x15e85d0]
// Decompiled from void CTiling::CalcAllTiles()
static void __cdecl CTiling::CalcAllTiles(void) {
  
  int v0; // esi
  int v1; // eax
  int v2; // eax
  int v3; // [esp+0h] [ebp-2Ch]
  int v4; // [esp+4h] [ebp-28h]
  int **v5; // [esp+10h] [ebp-1Ch]
  unsigned int v6; // [esp+18h] [ebp-14h]
  int k; // [esp+1Ch] [ebp-10h]
  int v8; // [esp+20h] [ebp-Ch]
  Squares *j; // [esp+24h] [ebp-8h]
  Squares *i; // [esp+28h] [ebp-4h]

  CTilesAndLinks::InitTiles();
  CTiling::m_iNumberOfWaterElements = 0;
  j__memset(CTiling::m_iNumberOfOwnedElements, 0, sizeof(CTiling::m_iNumberOfOwnedElements));
  j__memset(ITiling::m_uSquareNumberOfWaterElementsDiv2, 0, sizeof(ITiling::m_uSquareNumberOfWaterElementsDiv2));
  v8 = CTilingWorld::WorldWidthHeight();
  for ( i = 0; (int)i < v8; i = (Squares *)((char *)i + 16) )
  {
    for ( j = 0; (int)j < v8; j = (Squares *)((char *)j + 16) )
    {
      CTiling::CalcSquarePrepareNormal(j, i);
      CTiling::CalcSquareComponents();
      CTiling::CalcSquareTiles(0);
      v6 = CSquare::WaterCount((CSquare *)&dword_42F7C50);
      CTiling::m_iNumberOfWaterElements += v6;
      v0 = (Squares::XYToVW(i) + 1) << 6;
      v1 = Squares::XYToVW(j);
      ITiling::m_uSquareNumberOfWaterElementsDiv2[v0 + v1] += v6 >> 1;
      if ( !CSquare::IsPureWaterSquare((CSquare *)&dword_42F7C50) )
      {
        CTiling::CalcSquarePrepareCatapult(j, i);
        CTiling::CalcSquareComponents();
        CTiling::CalcSquareTiles(1);
      }
    }
  }
  CTilesEx::DeactivateTilesPushBackMode(i);
  for ( k = 0; k < v8 * v8; ++k )
  {
    v4 = ITiling::NormalTileId(k);
    v5 = CTiles::TileEx(v4);
    if ( (CTile::Type(v5, v3) & 0x10000000) != 0 )
    {
      v2 = CTile::OwnerId((CTile *)v5);
      ++CTiling::m_iNumberOfOwnedElements[v2];
    }
  }
}


// address=[0x15e8780]
// Decompiled from int CTiling::CalcAllTileLinks()
static void __cdecl CTiling::CalcAllTileLinks(void) {
  
  int v0; // eax
  int v1; // eax
  int **v2; // eax
  struct CLinkList *v4; // [esp-4h] [ebp-68h]
  int UsedTileId; // [esp+Ch] [ebp-58h]
  int v6; // [esp+1Ch] [ebp-48h]
  char *v7; // [esp+20h] [ebp-44h]
  unsigned int v8; // [esp+24h] [ebp-40h]
  int j; // [esp+28h] [ebp-3Ch]
  char *v10; // [esp+2Ch] [ebp-38h]
  int m; // [esp+30h] [ebp-34h]
  int k; // [esp+34h] [ebp-30h]
  int i; // [esp+38h] [ebp-2Ch]
  int v14; // [esp+3Ch] [ebp-28h]
  int v15; // [esp+40h] [ebp-24h]
  int v16; // [esp+44h] [ebp-20h]
  int v17; // [esp+48h] [ebp-1Ch]
  int v18; // [esp+4Ch] [ebp-18h]
  int n; // [esp+50h] [ebp-14h]

  v8 = CTilesEx::LastUsedTileId() + 1;
  v10 = (char *)operator new[](v8 << 8);
  if ( v10 )
  {
    `vector constructor iterator'(
      v10,
      0x100u,
      v8,
      (void *(__thiscall *)(void *))CIntLinkList::`default constructor closure');
    v7 = v10;
  }
  else
  {
    v7 = 0;
  }
  v6 = CTilingWorld::WorldWidthHeight() - 1;
  for ( i = 0; i < v6; ++i )
  {
    v18 = CTilingWorld::WorldIndex(0, i);
    for ( j = 0; j < v6; ++j )
    {
      v17 = ITiling::NormalTileId(v18);
      if ( CTiles::IsValidRealTile(v17) )
      {
        for ( k = 0; k < 3; ++k )
        {
          v0 = CTilingWorld::WorldNeighborRelIndex(k);
          v16 = ITiling::NormalTileId(v18 + v0);
          if ( ((v16 != v17) & CTiles::IsValidRealTile(v16)) != 0
            && !CIntLinkList::SearchBackwards((CIntLinkList *)&v7[256 * v17], v16) )
          {
            CIntLinkList::PushBack((CIntLinkList *)&v7[256 * v17], v16);
            CIntLinkList::PushBack((CIntLinkList *)&v7[256 * v16], v17);
          }
        }
      }
      v15 = ITiling::CatapultTileId(v18);
      if ( CTiles::IsValidRealTile(v15) )
      {
        for ( m = 0; m < 3; ++m )
        {
          v1 = CTilingWorld::WorldNeighborRelIndex(m);
          v14 = ITiling::CatapultTileId(v18 + v1);
          if ( ((v14 != v15) & CTiles::IsValidRealTile(v14)) != 0
            && !CIntLinkList::SearchBackwards((CIntLinkList *)&v7[256 * v15], v14) )
          {
            CIntLinkList::PushBack((CIntLinkList *)&v7[256 * v15], v14);
            CIntLinkList::PushBack((CIntLinkList *)&v7[256 * v14], v15);
          }
        }
      }
      ++v18;
    }
  }
  CLinks::InitLinks();
  UsedTileId = CTilesEx::LastUsedTileId();
  for ( n = 10; n <= UsedTileId; ++n )
  {
    CIntLinkList::SetOwnerTileId((CIntLinkList *)&v7[256 * n], n);
    v4 = CLinks::PushLinksBack((const struct CIntLinkList *)&v7[256 * n]);
    v2 = CTiles::TileEx(n);
    CTile::SetLinkList((CTile *)v2, v4);
  }
  CLinks::DeactivateLinksPushBackMode();
  return operator delete[](v7);
}


// address=[0x15e8aa0]
// Decompiled from void __cdecl CTiling::CalcSectorIds(bool a1)
static void __cdecl CTiling::CalcSectorIds(bool) {
  
  int **v1; // eax
  int **v2; // eax
  int **v3; // eax
  int **v4; // eax
  int **v5; // eax
  int **v6; // eax
  int **v7; // eax
  int **v8; // eax
  int v9; // [esp+0h] [ebp-34h]
  int EcoSector; // [esp+0h] [ebp-34h]
  int v11; // [esp+4h] [ebp-30h]
  int CatapultSector; // [esp+10h] [ebp-24h]
  bool v13; // [esp+18h] [ebp-1Ch]
  int v14; // [esp+1Ch] [ebp-18h]
  int UsedTileId; // [esp+24h] [ebp-10h]
  int k; // [esp+28h] [ebp-Ch]
  int i; // [esp+2Ch] [ebp-8h]
  int j; // [esp+30h] [ebp-4h]

  CSectors::Init((CSectors *)&CTiling::m_cSectors);
  CTiling::NotifyInitEcoSectors(a1);
  UsedTileId = CTilesEx::LastUsedTileId();
  for ( i = 10; i <= UsedTileId; ++i )
  {
    v1 = CTiles::TileEx(i);
    v14 = -!CTile::Used((CTile *)v1);
    v2 = CTiles::TileEx(i);
    CTile::SetSectorId((CTile *)v2, v14);
    v3 = CTiles::TileEx(i);
    CTile::SetEcoSectorId((CTile *)v3, v14);
  }
  for ( j = 10; j <= UsedTileId; ++j )
  {
    v4 = CTiles::TileEx(j);
    v13 = ((unsigned int)&unk_4000000 & CTile::Type(v4, v9)) == 0;
    v5 = CTiles::TileEx(j);
    if ( CTile::SectorId((CTile *)v5) == 0 && v13 )
    {
      v6 = CTiles::TileEx(j);
      if ( (CTile::Type(v6, v9) & 0x8000000) != 0 )
        CatapultSector = CTiling::NotifyCreateCatapultSector();
      else
        CatapultSector = CTiling::NotifyCreateSector();
      CTiling::WalkTilesChangeSector(j, CatapultSector);
    }
  }
  for ( k = 10; k <= UsedTileId; ++k )
  {
    v7 = CTiles::TileEx(k);
    v11 = CTile::OwnerId((CTile *)v7);
    v8 = CTiles::TileEx(k);
    if ( CTile::EcoSectorId((CTile *)v8) == 0 && v11 != 0 )
    {
      EcoSector = CTiling::NotifyCreateEcoSector(v11, a1);
      CTiling::WalkTilesChangeEcoSector(k, EcoSector);
    }
  }
}


// address=[0x15e8ca0]
// Decompiled from int __cdecl CTiling::CalcNotifyAll(bool a1)
static void __cdecl CTiling::CalcNotifyAll(bool) {
  
  int result; // eax
  CTile *v2; // eax
  CTile *v3; // eax
  int v4; // [esp+4h] [ebp-14h]
  int v5; // [esp+8h] [ebp-10h]
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v7 = CTilingWorld::WorldWidthHeight();
  result = v7 * v7;
  for ( i = 0; i < v7 * v7; ++i )
  {
    v6 = ITiling::NormalTileId(i);
    v2 = (CTile *)ITiling::Tile(v6);
    v5 = CTile::SectorId(v2);
    v3 = (CTile *)ITiling::Tile(v6);
    result = CTile::EcoSectorId(v3);
    v4 = result;
    if ( v5 )
    {
      result = CSectors::IncSectorSize((CSectors *)&CTiling::m_cSectors, v5);
      if ( v4 )
        CTiling::NotifyChangeEcoSector(i, 0, v4, a1);
    }
  }
  return result;
}


// address=[0x15e8d50]
// Decompiled from int __cdecl CTiling::CalcTileLinks(int a1)
static void __cdecl CTiling::CalcTileLinks(int) {
  
  int v1; // eax
  struct CLinkList *v2; // eax
  const struct CLinkList *v3; // eax
  int v5; // [esp-4h] [ebp-10Ch]
  CTile *v6; // [esp+0h] [ebp-108h]
  _BYTE v7[256]; // [esp+4h] [ebp-104h] BYREF

  if ( !CTilesEx::IsUsedRealTile(a1)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2171, "IsUsedRealTile(_iTileId)") == 1 )
  {
    __debugbreak();
  }
  v6 = (CTile *)CTiles::TileEx(a1);
  CIntLinkList::CIntLinkList((CIntLinkList *)v7, 0);
  v5 = CTile::CenterXY(v6);
  v1 = CTile::TilingType(v6);
  CTiling::CalcIntLinkList(v7, v1, v5);
  v2 = CTilesAndLinks::PushLinks((const struct CIntLinkList *)v7);
  CTile::SetLinkList(v6, v2);
  v3 = (const struct CLinkList *)CTile::LinkList(v6);
  return CTilesAndLinks::AddLinkList(v3);
}


// address=[0x15e8e20]
// Decompiled from int __cdecl CTiling::RecalcTileLinks(int a1)
static void __cdecl CTiling::RecalcTileLinks(int) {
  
  int v1; // eax
  CLinkList *v2; // eax
  struct CLinkList *v3; // eax
  struct CLinkList *v4; // eax
  const struct CLinkList *v5; // eax
  int v7; // [esp-4h] [ebp-10Ch]
  CTile *v8; // [esp+0h] [ebp-108h]
  _BYTE v9[256]; // [esp+4h] [ebp-104h] BYREF

  if ( !CTilesEx::IsUsedRealTile(a1)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2195, "IsUsedRealTile(_iTileId)") == 1 )
  {
    __debugbreak();
  }
  v8 = (CTile *)CTiles::TileEx(a1);
  CIntLinkList::CIntLinkList((CIntLinkList *)v9, 0);
  v7 = CTile::CenterXY(v8);
  v1 = CTile::TilingType(v8);
  CTiling::CalcIntLinkList(v9, v1, v7);
  v2 = (CLinkList *)CTile::LinkList(v8);
  if ( CLinkList::OwnerTileId(v2) != a1
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2202, "rTile.LinkList().OwnerTileId() == _iTileId") == 1 )
  {
    __debugbreak();
  }
  v3 = (struct CLinkList *)CTile::LinkList(v8);
  CTilesAndLinks::DeleteLinkList(v3);
  v4 = CTilesAndLinks::PushLinks((const struct CIntLinkList *)v9);
  CTile::SetLinkList(v8, v4);
  v5 = (const struct CLinkList *)CTile::LinkList(v8);
  return CTilesAndLinks::AddLinkList(v5);
}


// address=[0x15e8f40]
// Decompiled from void __cdecl CTiling::ChangeTileIds(int a1, int a2, int a3)
static void __cdecl CTiling::ChangeTileIds(enum T_TILING_TYPE,int,int) {
  
  struct CTile *v3; // eax
  int **v4; // eax
  int **v5; // eax
  int v6; // [esp-4h] [ebp-428h]
  int v7; // [esp-4h] [ebp-428h]
  int v8; // [esp+0h] [ebp-424h]
  int v9; // [esp+4h] [ebp-420h]
  int v10; // [esp+8h] [ebp-41Ch] BYREF
  int v11; // [esp+Ch] [ebp-418h]
  _BYTE v12[4]; // [esp+10h] [ebp-414h] BYREF
  int i; // [esp+14h] [ebp-410h]
  _BYTE v14[1032]; // [esp+18h] [ebp-40Ch] BYREF

  v3 = (struct CTile *)ITiling::Tile(a3);
  if ( a1 != CTile::TilingType(v3)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2219, "_tTilingType == Tile(_iNewTileId).TilingType()") == 1 )
  {
    __debugbreak();
  }
  CTileIdRef::CTileIdRef(v12, a1, 0);
  v9 = CTileIdRef::TileId((CTileIdRef *)v12, a2);
  TLimitedFIFO<int,256>::TLimitedFIFO<int,256>(v14);
  TLimitedFIFO<int,256>::Push(&a2);
  CTileIdRef::SetTileId((CTileIdRef *)v12, a2, a3);
  v11 = 1;
  while ( !(unsigned __int8)TLimitedFIFO<int,256>::Empty(v14) )
  {
    v8 = *(_DWORD *)TLimitedFIFO<int,256>::Top(v14);
    TLimitedFIFO<int,256>::Pop(v14);
    for ( i = 0; i < 6; ++i )
    {
      v10 = v8 + CTilingWorld::WorldNeighborRelIndex(i);
      if ( CTileIdRef::TileId((CTileIdRef *)v12, v10) == v9 )
      {
        CTileIdRef::SetTileId((CTileIdRef *)v12, v10, a3);
        TLimitedFIFO<int,256>::Push(&v10);
        ++v11;
      }
    }
  }
  v6 = -v11;
  v4 = CTiles::TileEx(v9);
  CTile::ChangeSize((CTile *)v4, v6);
  v7 = v11;
  v5 = CTiles::TileEx(a3);
  CTile::ChangeSize((CTile *)v5, v7);
}


// address=[0x15e9100]
// Decompiled from int *__cdecl CTiling::SplitTile(int a1, int a2)
static int __cdecl CTiling::SplitTile(enum T_TILING_TYPE,int) {
  
  int **v2; // eax
  int v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+4h] [ebp-8h]
  int *v6; // [esp+8h] [ebp-4h]

  v5 = CTilingWorld::WorldIndex(a2);
  v4 = CTiling::TileId(a1, v5);
  v6 = CTilesEx::DuplicateTile(v4);
  CTiling::ChangeTileIds(a1, v5, (int)v6);
  v2 = CTiles::TileEx((int)v6);
  CTile::SetCenterXY((CTile *)v2, a2);
  CTiling::CalcTileLinks((int)v6);
  return v6;
}


// address=[0x15e9180]
// Decompiled from char __cdecl CTiling::CheckBorderLink(int a1, int a2)
static bool __cdecl CTiling::CheckBorderLink(int,int) {
  
  struct CTile *v2; // eax
  int v4; // eax
  int v5; // [esp+0h] [ebp-940h]
  int v6; // [esp+4h] [ebp-93Ch]
  int v7; // [esp+8h] [ebp-938h]
  int started; // [esp+Ch] [ebp-934h] BYREF
  int v9; // [esp+10h] [ebp-930h]
  int v10; // [esp+14h] [ebp-92Ch]
  int v11; // [esp+18h] [ebp-928h] BYREF
  int v12; // [esp+1Ch] [ebp-924h]
  _BYTE v13[4]; // [esp+20h] [ebp-920h] BYREF
  int v14; // [esp+24h] [ebp-91Ch]
  int v15; // [esp+28h] [ebp-918h]
  int i; // [esp+2Ch] [ebp-914h]
  char v17; // [esp+33h] [ebp-90Dh]
  _BYTE v18[2312]; // [esp+34h] [ebp-90Ch] BYREF

  if ( !CTilingWorld::WorldInWorldPackedXY(a1)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2283, "WorldInWorldPackedXY(_iStartXY)") == 1 )
  {
    __debugbreak();
  }
  v9 = CTilingWorld::WorldIndex(a1);
  v2 = (struct CTile *)ITiling::Tile(a2);
  v10 = CTile::TilingType(v2);
  CTileIdRef::CTileIdRef(v13, v10, 0);
  v5 = CTileIdRef::TileId((CTileIdRef *)v13, v9);
  CSquareVisited::Init((CSquareVisited *)&unk_4300E70, a1);
  TLimitedFIFO<int,576>::TLimitedFIFO<int,576>(v18);
  started = CSquareVisited::StartIndex((CSquareVisited *)&unk_4300E70);
  TLimitedFIFO<int,576>::Push(&started);
  while ( !(unsigned __int8)TLimitedFIFO<int,576>::Empty(v18) )
  {
    v15 = *(_DWORD *)TLimitedFIFO<int,576>::Top(v18);
    TLimitedFIFO<int,576>::Pop(v18);
    v14 = 0;
    v17 = 1;
    v7 = CSquareVisited::WorldIdx((CSquareVisited *)&unk_4300E70, v15);
    if ( CSquareVisited::SetIfNotVisited((CSquareVisited *)&unk_4300E70, v15) )
    {
      for ( i = 0; i < 6; ++i )
      {
        v6 = v7 + CTilingWorld::WorldNeighborRelIndex(i);
        v12 = CTileIdRef::TileId((CTileIdRef *)v13, v6);
        if ( v12 == a2 )
          return 1;
        if ( v12 == v5 )
        {
          v4 = CSquareVisited::NeighborRelIndex(i);
          v11 = v15 + v4;
          if ( !(unsigned __int8)CSquareVisited::operator[](v15 + v4) )
          {
            TLimitedFIFO<int,576>::Push(&v11);
            ++v14;
          }
        }
        else
        {
          v17 = 0;
        }
      }
      if ( v17 )
        TLimitedFIFO<int,576>::UndoPush(v14);
    }
  }
  return 0;
}


// address=[0x15e93e0]
// Decompiled from void CTiling::NUpdateLinksAndCheckTileSpliting()
static void __cdecl CTiling::NUpdateLinksAndCheckTileSpliting(void) {
  
  int v0; // eax
  int v1; // [esp+0h] [ebp-10h]
  bool v2; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  int v4; // [esp+Ch] [ebp-4h]

  if ( !dword_42CF98C && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3798, "NeighborAnalysis::s_iInitialized") == 1 )
    __debugbreak();
  if ( !dword_42CF990 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3799, "NeighborAnalysis::s_iOldInitialized") == 1 )
    __debugbreak();
  if ( dword_4502118 == 1 )
  {
    for ( i = 0; i <= dword_45020DC; ++i )
    {
      v4 = dword_45020E0[i];
      v2 = v4 != dword_4502110;
      if ( (v2 & CTiles::IsValidRealTile(v4)) != 0 )
      {
        v1 = dword_4300E6C + Y16X16::NeighborModifier((Y16X16 *)dword_45020F8[i]);
        v0 = CTilingWorld::WorldIndex(v1);
        if ( CTiling::TileId(dword_42CF9A4, v0) != v4
          && BBSupportDbgReport(
               2,
               "Pathing\\Tiling.cpp",
               3823,
               "TileId(NeighborAnalysis::s_tTilingType, WorldIndex(iNeighborXY)) == iNeighborTileId") == 1 )
        {
          __debugbreak();
        }
        if ( CTiling::CheckBorderLink(v1, dword_4502110) )
        {
          if ( !CTiling::DbgCheckTileLink(v4, dword_4502110)
            && BBSupportDbgReport(
                 2,
                 "Pathing\\Tiling.cpp",
                 3834,
                 "DbgCheckTileLink(iNeighborTileId, NeighborAnalysis::s_iOldTileId)") == 1 )
          {
            __debugbreak();
          }
        }
        else
        {
          if ( CTiling::DbgCheckTileLink(v4, dword_4502110)
            && BBSupportDbgReport(
                 2,
                 "Pathing\\Tiling.cpp",
                 3827,
                 "!DbgCheckTileLink(iNeighborTileId, NeighborAnalysis::s_iOldTileId)") == 1 )
          {
            __debugbreak();
          }
          CTilesAndLinks::DeleteLink(dword_4502110, v4);
          CTilesAndLinks::DeleteLink(v4, dword_4502110);
        }
      }
    }
  }
  else if ( dword_4502118 > 1 )
  {
    CTiling::NCheckTileSplit(0);
    NeighborAnalysis::ReInit();
  }
}


// address=[0x15e95e0]
// Decompiled from int __cdecl CTiling::CalcIntLinkList(CIntLinkList *a1, int a2, int a3)
static int __cdecl CTiling::CalcIntLinkList(class CIntLinkList &,enum T_TILING_TYPE,int) {
  
  int v3; // eax
  int v4; // eax
  int v6; // [esp+0h] [ebp-440h]
  int v7; // [esp+4h] [ebp-43Ch]
  int started; // [esp+8h] [ebp-438h] BYREF
  int v9; // [esp+Ch] [ebp-434h]
  _BYTE v10[4]; // [esp+10h] [ebp-430h] BYREF
  int v11; // [esp+14h] [ebp-42Ch]
  int v12; // [esp+18h] [ebp-428h]
  int v13; // [esp+1Ch] [ebp-424h] BYREF
  int v14; // [esp+20h] [ebp-420h]
  int v15; // [esp+24h] [ebp-41Ch]
  int v16; // [esp+28h] [ebp-418h]
  int v17; // [esp+2Ch] [ebp-414h]
  int i; // [esp+30h] [ebp-410h]
  _BYTE v19[1032]; // [esp+34h] [ebp-40Ch] BYREF

  v15 = Y16X16::UnpackXFast(a3);
  v16 = Y16X16::UnpackYFast(a3);
  if ( !CTilingWorld::WorldInWorld(v15, v16)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 1241, "WorldInWorld(iX, iY)") == 1 )
  {
    __debugbreak();
  }
  v9 = CTilingWorld::WorldIndex(v15, v16);
  CTileIdRef::CTileIdRef(v10, a2, 0);
  v14 = CTileIdRef::TileId((CTileIdRef *)v10, v9);
  if ( !CTilesEx::IsUsedRealTile(v14)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 1249, "IsUsedRealTile(iTileId)") == 1 )
  {
    __debugbreak();
  }
  CIntLinkList::Init(a1, v14);
  CSquareVisited::Init((CSquareVisited *)&unk_4300E70, v15, v16);
  TStaticFIFO<int,256>::TStaticFIFO<int,256>(v19);
  started = CSquareVisited::StartIndex((CSquareVisited *)&unk_4300E70);
  TStaticFIFO<int,256>::Push(&started);
  v3 = CSquareVisited::StartIndex((CSquareVisited *)&unk_4300E70);
  CSquareVisited::Set((CSquareVisited *)&unk_4300E70, v3);
  v12 = 1;
  while ( !(unsigned __int8)TStaticFIFO<int,256>::Empty(v19) )
  {
    v11 = *(_DWORD *)TStaticFIFO<int,256>::Top(v19);
    TStaticFIFO<int,256>::Pop(v19);
    v7 = CSquareVisited::WorldIdx((CSquareVisited *)&unk_4300E70, v11);
    for ( i = 0; i < 6; ++i )
    {
      v4 = CSquareVisited::NeighborRelIndex(i);
      v13 = v11 + v4;
      v6 = v7 + CTilingWorld::WorldNeighborRelIndex(i);
      if ( !(unsigned __int8)CSquareVisited::operator[](v13) )
      {
        CSquareVisited::Set((CSquareVisited *)&unk_4300E70, v13);
        v17 = CTileIdRef::TileId((CTileIdRef *)v10, v6);
        if ( v17 == v14 )
        {
          ++v12;
          TStaticFIFO<int,256>::Push(&v13);
        }
        else if ( CTiles::IsValidRealTile(v17) && !CIntLinkList::SearchBackwards(a1, v17) )
        {
          CIntLinkList::PushBack(a1, v17);
        }
      }
    }
  }
  return v12;
}


// address=[0x15e98c0]
// Decompiled from _BYTE *CTiling::NCheckTileSplit()
static void __cdecl CTiling::NCheckTileSplit(void) {
  
  _BYTE *result; // eax
  char v1; // bl
  char v2; // bl
  int v3; // [esp+4h] [ebp-3Ch]
  int v4; // [esp+8h] [ebp-38h]
  int v5; // [esp+Ch] [ebp-34h]
  _BYTE *v6; // [esp+14h] [ebp-2Ch]
  _BYTE *v7; // [esp+18h] [ebp-28h]
  char *v8; // [esp+1Ch] [ebp-24h]
  int k; // [esp+28h] [ebp-18h]
  int i; // [esp+30h] [ebp-10h]
  int j; // [esp+30h] [ebp-10h]

  CTiling::RecalcTileLinks(dword_4502110);
  result = (_BYTE *)CSquareVisited::WorldPackedXYIndex((CSquareVisited *)&unk_4300E70, dword_4300E6C);
  v7 = result;
  for ( i = 0; i < 6; ++i )
  {
    v6 = &v7[CSquareVisited::NeighborRelIndex(i)];
    v1 = CSquareVisited::operator[](v6);
    result = (_BYTE *)TBoolArray<6>::operator[](i);
    *result = v1;
  }
  for ( j = 0; j < 6; ++j )
  {
    if ( ((dword_45020C4[j] == dword_4502110) & (*(_BYTE *)TBoolArray<6>::operator[](j) == 0)) != 0 )
    {
      v5 = dword_4300E6C + Y16X16::NeighborModifier((Y16X16 *)j);
      CTiling::SplitTile(dword_42CF9A4, v5);
      v4 = CSquareVisited::WorldPackedXYIndex((CSquareVisited *)&unk_4300E70, dword_4300E6C);
      for ( k = 0; k < 6; ++k )
      {
        v3 = v4 + CSquareVisited::NeighborRelIndex(k);
        v8 = (char *)TBoolArray<6>::operator[](k);
        v2 = *v8;
        *v8 = CSquareVisited::operator[](v3) | v2;
      }
    }
    result = (_BYTE *)(j + 1);
  }
  return result;
}


// address=[0x15e9a60]
// Decompiled from void CTiling::NCheckSectorSplit()
static void __cdecl CTiling::NCheckSectorSplit(void) {
  
  int **v0; // eax
  int **v1; // eax
  int Sector; // [esp+0h] [ebp-58h]
  int v3; // [esp+4h] [ebp-54h]
  int **v4; // [esp+8h] [ebp-50h]
  int v5; // [esp+Ch] [ebp-4Ch]
  int v6; // [esp+10h] [ebp-48h]
  int j; // [esp+14h] [ebp-44h]
  int v8; // [esp+18h] [ebp-40h]
  int v9; // [esp+1Ch] [ebp-3Ch]
  int i; // [esp+20h] [ebp-38h]
  int k; // [esp+20h] [ebp-38h]
  _DWORD v12[6]; // [esp+24h] [ebp-34h]
  int v13[6]; // [esp+3Ch] [ebp-1Ch]

  if ( !dword_42CF98C && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3274, "NeighborAnalysis::s_iInitialized") == 1 )
    __debugbreak();
  v8 = -1;
  v9 = -1;
  for ( i = 0; i <= dword_45020DC; ++i )
  {
    v6 = dword_45020E0[i];
    v4 = CTiles::TileEx(v6);
    if ( CTile::SectorId((CTile *)v4) <= 0 )
    {
      v9 = -1;
    }
    else
    {
      if ( v9 < 0 )
      {
        for ( j = i - 2; j >= 0; --j )
        {
          if ( dword_45020E0[j] == v6 )
          {
            v9 = v12[j];
            break;
          }
        }
      }
      if ( v9 < 0 )
      {
        v9 = ++v8;
        v13[v8] = v6;
      }
    }
    v12[i] = v9;
  }
  if ( v8 > 0 )
  {
    v0 = CTiles::TileEx(v13[0]);
    v3 = CTile::SectorId((CTile *)v0);
    TBitArray<32768>::ClearArray(&unk_45010C0);
    CTiling::WalkTilesSetVisited(v13[0]);
    for ( k = 1; k <= v8; ++k )
    {
      v5 = v13[k];
      v1 = CTiles::TileEx(v5);
      if ( CTile::SectorId((CTile *)v1) == v3 && !(unsigned __int8)TBitArray<32768>::operator[](v5) )
      {
        Sector = CTiling::NotifyCreateSector(Sector);
        CTiling::WalkTilesChangeSector(v5, Sector);
      }
    }
  }
}


// address=[0x15e9c30]
// Decompiled from void __cdecl CTiling::NCalcNewTileId(DWORD a1)
static void __cdecl CTiling::NCalcNewTileId(int) {
  
  struct CTile *v1; // eax
  int **v2; // eax
  BOOL v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]
  int *v6; // [esp+8h] [ebp-4h]

  if ( !dword_42CF98C && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3643, "NeighborAnalysis::s_iInitialized") == 1 )
    __debugbreak();
  if ( (a1 & 0x3FE000) != 0
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3644, "(_iNewTileType & ~TILE_TYPE_EQUAL_MASK) == 0") == 1 )
  {
    __debugbreak();
  }
  v6 = 0;
  for ( i = 0; i <= dword_45020DC; ++i )
  {
    v4 = dword_45020E0[i];
    v1 = (struct CTile *)ITiling::Tile(v4);
    if ( (CTile::Type(v1, v4) & 0xFFC01FFF) == a1 )
    {
      v6 = (int *)v3;
      break;
    }
  }
  if ( v6 )
  {
    CTiling::SetTileId(dword_42CF9A4, dword_45020C0, (__int16)v6);
    NeighborAnalysis::InitNew((NeighborAnalysis *)a1, v6, 0, v3);
  }
  else
  {
    v6 = CTilesEx::PushTile(a1, dword_4300E6C);
    CTiling::SetTileId(dword_42CF9A4, dword_45020C0, (__int16)v6);
    CTiling::CalcTileLinks((int)v6);
    NeighborAnalysis::InitNew((NeighborAnalysis *)a1, v6, 1, v3);
  }
  v2 = CTiles::TileEx((int)v6);
  CTile::ChangeSize((CTile *)v2, 1);
}


// address=[0x15e9d80]
// Decompiled from void __cdecl CTiling::NCheckSectorMerge(int a1)
static void __cdecl CTiling::NCheckSectorMerge(int) {
  
  int **v1; // eax
  int v2; // [esp+0h] [ebp-Ch]
  int v3; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i <= dword_45020DC; ++i )
  {
    v3 = dword_45020E0[i];
    if ( v3 )
    {
      v1 = CTiles::TileEx(v3);
      v2 = CTile::SectorId((CTile *)v1);
      if ( v2 != a1 )
      {
        CTiling::WalkTilesChangeSector(v3, a1);
        CTiling::NotifyDeleteSector(v2);
      }
    }
  }
}


// address=[0x15e9e00]
// Decompiled from void __cdecl CTiling::NCheckEcoSectorJoin(int a1)
static void __cdecl CTiling::NCheckEcoSectorJoin(int) {
  
  int **v1; // eax
  int **v2; // eax
  int **v3; // eax
  int **v4; // eax
  int v5; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]
  int EcoSector; // [esp+8h] [ebp-4h]

  if ( !dword_42CF98C && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3697, "NeighborAnalysis::s_iInitialized") == 1 )
    __debugbreak();
  if ( !dword_42CF994 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3698, "NeighborAnalysis::s_iNewInitialized") == 1 )
    __debugbreak();
  if ( a1 )
  {
    v7 = 0;
    for ( i = 0; i <= dword_45020DC; ++i )
    {
      v5 = dword_45020E0[i];
      v1 = CTiles::TileEx(v5);
      if ( CTile::OwnerId((CTile *)v1) == a1 )
      {
        v2 = CTiles::TileEx(v5);
        v7 = CTile::EcoSectorId((CTile *)v2);
        break;
      }
    }
    if ( v7 )
    {
      v4 = CTiles::TileEx(dword_4502124);
      CTile::SetEcoSectorId((CTile *)v4, v7);
      CTiling::NotifyChangeEcoSector(dword_45020C0, 0, v7, 1);
      CTiling::NCheckEcoSectorMerge(a1, v7);
    }
    else
    {
      EcoSector = CTiling::NotifyCreateEcoSector(a1, 1);
      v3 = CTiles::TileEx(dword_4502124);
      CTile::SetEcoSectorId((CTile *)v3, EcoSector);
      CTiling::NotifyChangeEcoSector(dword_45020C0, 0, EcoSector, 1);
    }
  }
}


// address=[0x15e9f60]
// Decompiled from void CTiling::NCheckSectorAndEcoSectorDelete()
static void __cdecl CTiling::NCheckSectorAndEcoSectorDelete(void) {
  
  int **v0; // eax
  int **v1; // eax
  int **v2; // eax
  int **v3; // eax
  int v4; // [esp+0h] [ebp-20h]
  int v5; // [esp+4h] [ebp-1Ch]
  int v6; // [esp+Ch] [ebp-14h]
  int i; // [esp+18h] [ebp-8h]
  char v8; // [esp+1Eh] [ebp-2h]
  char v9; // [esp+1Fh] [ebp-1h]

  if ( !dword_42CF98C && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3580, "NeighborAnalysis::s_iInitialized") == 1 )
    __debugbreak();
  if ( !dword_42CF990 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3581, "NeighborAnalysis::s_iOldInitialized") == 1 )
    __debugbreak();
  v0 = CTiles::TileEx(dword_4502110);
  v5 = CTile::SectorId((CTile *)v0);
  v1 = CTiles::TileEx(dword_4502110);
  v4 = CTile::EcoSectorId((CTile *)v1);
  v9 = 1;
  v8 = dword_4502114 != 0;
  for ( i = 0; i <= dword_45020DC; ++i )
  {
    v6 = dword_45020E0[i];
    v2 = CTiles::TileEx(v6);
    v9 &= CTile::SectorId((CTile *)v2) != v5;
    v3 = CTiles::TileEx(v6);
    v8 &= CTile::EcoSectorId((CTile *)v3) != v4;
  }
  if ( v9 )
    CTiling::NotifyDeleteSector(v5);
  if ( v8 )
    CTiling::NotifyDeleteEcoSector(v4);
}


// address=[0x15ea0d0]
// Decompiled from void CTiling::NRemoveElementFromTile()
static void __cdecl CTiling::NRemoveElementFromTile(void) {
  
  int v0; // esi
  int v1; // eax
  Y16X16 *v2; // [esp+4h] [ebp-8h]
  int **v3; // [esp+8h] [ebp-4h]

  if ( !dword_42CF98C && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3108, "NeighborAnalysis::s_iInitialized") == 1 )
    __debugbreak();
  if ( !dword_42CF990 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3109, "NeighborAnalysis::s_iOldInitialized") == 1 )
    __debugbreak();
  if ( dword_4502118 <= 0
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3110, "NeighborAnalysis::s_iOldTileChangeCount > 0") == 1 )
  {
    __debugbreak();
  }
  v3 = CTiles::TileEx(dword_4502110);
  if ( CTile::CenterXY(v3) == dword_4300E6C )
  {
    v2 = (Y16X16 *)dword_45020F8[dword_450211C];
    v0 = CTile::CenterXY(v3);
    v1 = Y16X16::NeighborModifier(v2);
    CTile::SetCenterXY((CTile *)v3, v1 + v0);
  }
}


// address=[0x15ea1b0]
// Decompiled from void __cdecl CTiling::NCheckEcoSectorSplit(int a1)
static void __cdecl CTiling::NCheckEcoSectorSplit(int) {
  
  int **v1; // eax
  int **v2; // eax
  int **v3; // eax
  int **v4; // eax
  int v5; // [esp+0h] [ebp-9Ch]
  int EcoSector; // [esp+4h] [ebp-98h]
  int v7; // [esp+8h] [ebp-94h]
  int v8; // [esp+Ch] [ebp-90h]
  int v9; // [esp+10h] [ebp-8Ch]
  int n; // [esp+14h] [ebp-88h]
  int v11; // [esp+18h] [ebp-84h]
  int v12; // [esp+1Ch] [ebp-80h]
  int j; // [esp+20h] [ebp-7Ch]
  int m; // [esp+24h] [ebp-78h]
  int v15; // [esp+28h] [ebp-74h]
  int v16; // [esp+2Ch] [ebp-70h]
  int v17; // [esp+30h] [ebp-6Ch]
  int i; // [esp+34h] [ebp-68h]
  int k; // [esp+34h] [ebp-68h]
  _DWORD v20[6]; // [esp+38h] [ebp-64h]
  _DWORD v21[6]; // [esp+50h] [ebp-4Ch]
  _DWORD v22[6]; // [esp+68h] [ebp-34h]
  int v23[6]; // [esp+80h] [ebp-1Ch]

  if ( !dword_42CF98C && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3131, "NeighborAnalysis::s_iInitialized") == 1 )
    __debugbreak();
  if ( !a1 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3132, "_iOldOwnerId != 0") == 1 )
    __debugbreak();
  v15 = -1;
  v16 = -1;
  for ( i = 0; i <= dword_45020DC; ++i )
  {
    v12 = dword_45020E0[i];
    v1 = CTiles::TileEx(v12);
    if ( CTile::OwnerId((CTile *)v1) == a1 )
    {
      v2 = CTiles::TileEx(v12);
      if ( !CTile::EcoSectorId((CTile *)v2)
        && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3156, "TileEx(iNeighborTileId).EcoSectorId() != 0") == 1 )
      {
        __debugbreak();
      }
      if ( v16 < 0 )
      {
        for ( j = i - 2; j >= 0; --j )
        {
          if ( dword_45020E0[j] == v12 )
          {
            v16 = v20[j];
            break;
          }
        }
      }
      if ( v16 < 0 )
      {
        v16 = ++v15;
        v23[v15] = v12;
      }
    }
    else
    {
      v16 = -1;
    }
    v20[i] = v16;
  }
  if ( v15 > 0 )
  {
    TBitArray<32768>::ClearArray(&unk_45010C0);
    v3 = CTiles::TileEx(v23[0]);
    v5 = CTile::EcoSectorId((CTile *)v3);
    v21[0] = v23[0];
    v22[0] = CTiling::WalkTilesEcoSectorSetVisitedAndCountSize(v23[0]);
    v17 = 0;
    for ( k = 1; k <= v15; ++k )
    {
      v11 = v23[k];
      v4 = CTiles::TileEx(v11);
      if ( CTile::EcoSectorId((CTile *)v4) == v5 && !(unsigned __int8)TBitArray<32768>::operator[](v11) )
      {
        v21[++v17] = v11;
        v22[v17] = CTiling::WalkTilesEcoSectorSetVisitedAndCountSize(v11);
      }
    }
    if ( v17 > 0 )
    {
      TBitArray<32768>::ClearArray(&unk_45010C0);
      v8 = 0;
      v9 = v22[0];
      for ( m = 1; m <= v17; ++m )
      {
        if ( v9 < v22[m] )
        {
          v9 = v22[m];
          v8 = m;
        }
      }
      v21[v8] = 0;
      for ( n = 0; n <= v17; ++n )
      {
        v7 = v21[n];
        if ( v7 > 0 )
        {
          EcoSector = CTiling::NotifyCreateEcoSector(a1, 1);
          CTiling::WalkTilesChangeEcoSectorAndNotify(v7, EcoSector);
          CTiling::NotifyEcoSectorSplit(v5, EcoSector);
        }
      }
    }
  }
}


// address=[0x15ea530]
// Decompiled from void CTiling::NCheckEcoSectorDelete()
static void __cdecl CTiling::NCheckEcoSectorDelete(void) {
  
  int **v0; // eax
  int **v1; // eax
  int v2; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  if ( !dword_42CF98C && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3615, "NeighborAnalysis::s_iInitialized") == 1 )
    __debugbreak();
  if ( !dword_42CF990 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3616, "NeighborAnalysis::s_iOldInitialized") == 1 )
    __debugbreak();
  v0 = CTiles::TileEx(dword_4502110);
  v2 = CTile::EcoSectorId((CTile *)v0);
  if ( v2 )
  {
    for ( i = 0; i <= dword_45020DC; ++i )
    {
      v1 = CTiles::TileEx(dword_45020E0[i]);
      if ( CTile::EcoSectorId((CTile *)v1) == v2 )
        return;
    }
    CTiling::NotifyDeleteEcoSector(v2);
  }
}


// address=[0x15ea600]
// Decompiled from int __cdecl CTiling::NCheckEcoSectorMerge(int a1, int a2)
static void __cdecl CTiling::NCheckEcoSectorMerge(int,int) {
  
  int **v2; // eax
  int **v3; // eax
  int result; // eax
  int **v5; // eax
  int **v6; // eax
  int **v7; // eax
  int v8; // [esp+4h] [ebp-10h]
  int v9; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  if ( !dword_42CF994 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3436, "NeighborAnalysis::s_iNewInitialized") == 1 )
    __debugbreak();
  v11 = dword_4502124;
  v8 = CTile::TileTypeToOwnerId(dword_4502120);
  if ( v11 <= 0 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3441, "iTileId > 0") == 1 )
    __debugbreak();
  if ( v8 <= 0 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3442, "iOwnerId > 0") == 1 )
    __debugbreak();
  v2 = CTiles::TileEx(v11);
  if ( CTile::OwnerId((CTile *)v2) != v8
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3443, "TileEx(iTileId).OwnerId() == iOwnerId") == 1 )
  {
    __debugbreak();
  }
  v3 = CTiles::TileEx(v11);
  result = CTile::EcoSectorId((CTile *)v3);
  if ( result != a2 )
  {
    result = BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3444, "TileEx(iTileId).EcoSectorId() == _iEcoSectorId");
    if ( result == 1 )
      __debugbreak();
  }
  for ( i = 0; i <= dword_45020DC; ++i )
  {
    v9 = dword_45020E0[i];
    v5 = CTiles::TileEx(v9);
    if ( CTile::OwnerId((CTile *)v5) == a1 )
    {
      v6 = CTiles::TileEx(v9);
      if ( CTile::EcoSectorId((CTile *)v6) != a2 )
      {
        a2 = CTiling::MergeEcoSectors(v11, v9);
        v7 = CTiles::TileEx(v11);
        if ( CTile::EcoSectorId((CTile *)v7) != a2
          && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3458, "TileEx(iTileId).EcoSectorId() == _iEcoSectorId") == 1 )
        {
          __debugbreak();
        }
      }
    }
    result = i + 1;
  }
  return result;
}


// address=[0x15ea7c0]
// Decompiled from void CTiling::NCheckSectorJoin()
static void __cdecl CTiling::NCheckSectorJoin(void) {
  
  int **v0; // eax
  int **v1; // eax
  int **v2; // eax
  __int16 Sector; // [esp-4h] [ebp-10h]
  int v4; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h]

  if ( !dword_42CF98C && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3751, "NeighborAnalysis::s_iInitialized") == 1 )
    __debugbreak();
  if ( !dword_42CF994 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3752, "NeighborAnalysis::s_iNewInitialized") == 1 )
    __debugbreak();
  v6 = 0;
  for ( i = 0; i <= dword_45020DC; ++i )
  {
    v4 = dword_45020E0[i];
    if ( v4 )
    {
      v0 = CTiles::TileEx(v4);
      v6 = CTile::SectorId((CTile *)v0);
      break;
    }
  }
  if ( v6 )
  {
    v2 = CTiles::TileEx(dword_4502124);
    CTile::SetSectorId((CTile *)v2, v6);
    CTiling::NCheckSectorMerge(v6);
  }
  else
  {
    Sector = CTiling::NotifyCreateSector(v4);
    v1 = CTiles::TileEx(dword_4502124);
    CTile::SetSectorId((CTile *)v1, Sector);
  }
}


// address=[0x15ea8c0]
// Decompiled from int CTiling::NCheckTileMerge()
static void __cdecl CTiling::NCheckTileMerge(void) {
  
  int result; // eax
  int **v1; // eax
  CLinkList *v2; // eax
  int v3; // esi
  int **v4; // eax
  int v5; // eax
  int v6; // esi
  int v7; // [esp-4h] [ebp-50h]
  int v8; // [esp+0h] [ebp-4Ch]
  int v9; // [esp+0h] [ebp-4Ch]
  CTile v10; // [esp+4h] [ebp-48h] BYREF
  int v11; // [esp+18h] [ebp-34h]
  BOOL v12; // [esp+1Ch] [ebp-30h]
  BOOL v13; // [esp+20h] [ebp-2Ch]
  int v14; // [esp+24h] [ebp-28h]
  int v15; // [esp+28h] [ebp-24h]
  BOOL v16; // [esp+2Ch] [ebp-20h]
  BOOL v17; // [esp+30h] [ebp-1Ch]
  int v18; // [esp+34h] [ebp-18h]
  CTile *v19; // [esp+38h] [ebp-14h]
  int j; // [esp+3Ch] [ebp-10h]
  int i; // [esp+40h] [ebp-Ch]
  int v22; // [esp+44h] [ebp-8h]
  int v23; // [esp+48h] [ebp-4h]

  if ( !dword_42CF98C && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3473, "NeighborAnalysis::s_iInitialized") == 1 )
    __debugbreak();
  if ( !dword_42CF994 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3474, "NeighborAnalysis::s_iNewInitialized") == 1 )
    __debugbreak();
  v22 = dword_4502124;
  v19 = (CTile *)CTiles::TileEx(dword_4502124);
  result = CTile::Type(v19, v8) & 0xFFC01FFF;
  v15 = result;
  for ( i = 0; i <= dword_45020DC; ++i )
  {
    v23 = dword_45020E0[i];
    v17 = v23 != 0;
    v16 = v23 != v22;
    result = v16 && v17;
    if ( v16 && v17 )
    {
      v1 = CTiles::TileEx(v23);
      v14 = CTile::Type(v1, v9);
      if ( (v14 & 0xFFC01FFF) == v15 )
      {
        CTiling::MergeTiles(v22, v23);
        result = v22;
        dword_45020E0[i] = v22;
        if ( i != dword_45020DC )
        {
          result = dword_45020E4[i];
          if ( result == v23 )
          {
            result = BBSupportDbgReport(
                       2,
                       "Pathing\\Tiling.cpp",
                       3519,
                       "(i == NeighborAnalysis::s_iLastTileArea) || (NeighborAnalysis::s_iTileAreaTileIds[i + 1] != iNeighborTileId)");
            if ( result == 1 )
              __debugbreak();
          }
        }
        for ( j = i + 2; j <= dword_45020DC; ++j )
        {
          if ( dword_45020E0[j] == v23 )
            dword_45020E0[j] = v22;
          result = j + 1;
        }
      }
      else
      {
        v7 = v23;
        v2 = (CLinkList *)CTile::LinkList(v19);
        LOBYTE(result) = CLinkList::SearchForLinkTileId(v2, v7);
        if ( !(_BYTE)result )
        {
          CTilesAndLinks::AddLink(v22, v23);
          CTilesAndLinks::AddLink(v23, v22);
          v10 = *(CTile *)CTiles::TileEx(v23);
          v3 = CTile::SectorId(v19);
          if ( v3 != CTile::SectorId(&v10) && CTile::SectorId(v19) && CTile::SectorId(&v10) )
            CTiling::MergeSectors(v22, v23);
          v18 = CTile::TileTypeToOwnerId(v15);
          v11 = CTile::TileTypeToOwnerId(v14);
          v4 = CTiles::TileEx(v22);
          v5 = CTile::OwnerId((CTile *)v4);
          if ( v18 != v5
            && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3558, "iNewOwnerId == TileEx(iNewTileId).OwnerId()") == 1 )
          {
            __debugbreak();
          }
          result = 0;
          v13 = v18 != 0;
          v12 = v18 == v11;
          if ( v12 && v13 )
          {
            v6 = CTile::EcoSectorId(v19);
            result = CTile::EcoSectorId(&v10);
            if ( v6 != result )
              result = CTiling::MergeEcoSectors(v22, v23);
          }
        }
      }
    }
  }
  return result;
}


// address=[0x15eabd0]
// Decompiled from int __cdecl CTiling::MergeTiles(int a1, int *a2)
static void __cdecl CTiling::MergeTiles(int,int) {
  
  int v2; // esi
  int v3; // esi
  int v4; // esi
  int v5; // eax
  int **v7; // [esp+4h] [ebp-8h]
  int **v8; // [esp+8h] [ebp-4h]

  if ( !CTiles::IsValidRealTile(a1)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2774, "IsValidRealTile(_iRemainingTileId)") == 1 )
  {
    __debugbreak();
  }
  if ( !CTiles::IsValidRealTile(a2)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2775, "IsValidRealTile(_iToBeDeletedTileId)") == 1 )
  {
    __debugbreak();
  }
  v7 = CTiles::TileEx(a1);
  v8 = CTiles::TileEx((int)a2);
  v2 = CTile::SectorId((CTile *)v7);
  if ( v2 != CTile::SectorId((CTile *)v8) )
  {
    if ( !CTile::SectorId((CTile *)v7)
      && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2784, "rRemainingTile.SectorId() != 0") == 1 )
    {
      __debugbreak();
    }
    if ( !CTile::SectorId((CTile *)v8)
      && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2785, "rToBeDeletedTile.SectorId() != 0") == 1 )
    {
      __debugbreak();
    }
    CTiling::MergeSectors(a1, a2);
  }
  v3 = CTile::EcoSectorId((CTile *)v7);
  if ( v3 != CTile::EcoSectorId((CTile *)v8) )
  {
    if ( !CTile::EcoSectorId((CTile *)v7)
      && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2794, "rRemainingTile.EcoSectorId() != 0") == 1 )
    {
      __debugbreak();
    }
    if ( !CTile::EcoSectorId((CTile *)v8)
      && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2795, "rToBeDeletedTile.EcoSectorId() != 0") == 1 )
    {
      __debugbreak();
    }
    v4 = CTile::OwnerId((CTile *)v7);
    if ( v4 != CTile::OwnerId((CTile *)v8)
      && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2797, "rRemainingTile.OwnerId() == rToBeDeletedTile.OwnerId()") == 1 )
    {
      __debugbreak();
    }
    CTiling::MergeEcoSectors(a1, a2);
  }
  CTiling::WalkTileChangeTileId(a2, a1);
  v5 = CTile::Size((CTile *)v8);
  CTile::ChangeSize((CTile *)v7, v5);
  CTile::SetSize((CTile *)v8, 0);
  CTilesAndLinks::MergeTileLinkLists(a1, (int)a2);
  return CTilesAndLinks::DeleteTile(a2);
}


// address=[0x15eade0]
// Decompiled from void __cdecl CTiling::MergeSectors(int a1, int a2)
static void __cdecl CTiling::MergeSectors(int,int) {
  
  int **v2; // eax
  int **v3; // eax
  int v4; // [esp+0h] [ebp-8h]
  int v5; // [esp+4h] [ebp-4h]

  v2 = CTiles::TileEx(a1);
  v5 = CTile::SectorId((CTile *)v2);
  v3 = CTiles::TileEx(a2);
  v4 = CTile::SectorId((CTile *)v3);
  CTiling::WalkTilesChangeSector(a2, v5);
  CTiling::NotifyDeleteSector(v4);
}


// address=[0x15eae40]
// Decompiled from int __cdecl CTiling::MergeEcoSectors(int a1, int a2)
static int __cdecl CTiling::MergeEcoSectors(int,int) {
  
  int **v2; // eax
  int **v3; // eax
  int v5; // [esp+0h] [ebp-18h]
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h]
  int v8; // [esp+14h] [ebp-4h]

  v2 = CTiles::TileEx(a1);
  v7 = CTile::EcoSectorId((CTile *)v2);
  v3 = CTiles::TileEx(a2);
  v8 = CTile::EcoSectorId((CTile *)v3);
  v6 = CTiling::EcoSectorSizeEx(v7);
  if ( v6 > CTiling::EcoSectorSizeEx(v8) )
  {
    a1 = a2;
    v5 = v7;
    v7 = v8;
    v8 = v5;
  }
  CTiling::NotifyEcoSectorMerge(v8, v7);
  CTiling::WalkTilesChangeEcoSectorAndNotify(a1, v8);
  CTiling::NotifyEcoSectorsMerged(v8, v7);
  CTiling::NotifyDeleteEcoSector(v7);
  return v8;
}


// address=[0x15eaf00]
// Decompiled from int __cdecl CTiling::WalkTileChangeTileId(int a1, int a2)
static void __cdecl CTiling::WalkTileChangeTileId(int,int) {
  
  int TilingType; // esi
  const struct CTile *v3; // eax
  int v4; // eax
  struct CTile *v5; // eax
  int v6; // eax
  int result; // eax
  int v8; // eax
  int v9; // [esp+8h] [ebp-420h] BYREF
  int v10; // [esp+Ch] [ebp-41Ch] BYREF
  int v11; // [esp+10h] [ebp-418h]
  _BYTE v12[4]; // [esp+14h] [ebp-414h] BYREF
  int i; // [esp+18h] [ebp-410h]
  _BYTE v14[1032]; // [esp+1Ch] [ebp-40Ch] BYREF

  TilingType = CTiling::GetTilingType(a1);
  if ( TilingType != CTiling::GetTilingType(a2)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2644, "GetTilingType(_iTileId) == GetTilingType(_iNewTileId)") == 1 )
  {
    __debugbreak();
  }
  v3 = ITiling::Tile(a1);
  v4 = CTile::CenterXY(v3);
  v10 = CTilingWorld::WorldIndex(v4);
  v5 = (struct CTile *)ITiling::Tile(a1);
  v6 = CTile::TilingType(v5);
  CTileIdRef::CTileIdRef(v12, v6, 0);
  if ( CTileIdRef::TileId((CTileIdRef *)v12, v10) != a1
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2649, "cTileIdsRef.TileId(iStartWorldIdx) == _iTileId") == 1 )
  {
    __debugbreak();
  }
  TStaticFIFO<int,256>::TStaticFIFO<int,256>(v14);
  TStaticFIFO<int,256>::Push(&v10);
  while ( 1 )
  {
    result = TStaticFIFO<int,256>::Empty(v14);
    if ( (_BYTE)result )
      break;
    v11 = *(_DWORD *)TStaticFIFO<int,256>::Top(v14);
    TStaticFIFO<int,256>::Pop(v14);
    if ( CTileIdRef::TileId((CTileIdRef *)v12, v11) == a1 )
    {
      CTileIdRef::SetTileId((CTileIdRef *)v12, v11, a2);
      for ( i = 0; i < 6; ++i )
      {
        v8 = CTilingWorld::WorldNeighborRelIndex(i);
        v9 = v11 + v8;
        if ( CTileIdRef::TileId((CTileIdRef *)v12, v11 + v8) == a1 )
          TStaticFIFO<int,256>::Push(&v9);
      }
    }
  }
  return result;
}


// address=[0x15eb0e0]
// Decompiled from int __cdecl CTiling::WalkTileNotifyEcoSectorChange(int a1, int a2, int a3)
static void __cdecl CTiling::WalkTileNotifyEcoSectorChange(int,int,int) {
  
  int **v3; // eax
  int v4; // eax
  int **v5; // eax
  int v6; // eax
  int v7; // eax
  int result; // eax
  int v9; // eax
  int v10; // eax
  int v11; // [esp+4h] [ebp-42Ch]
  int started; // [esp+8h] [ebp-428h] BYREF
  int v13; // [esp+Ch] [ebp-424h]
  int v14; // [esp+10h] [ebp-420h]
  int v15; // [esp+14h] [ebp-41Ch] BYREF
  int v16; // [esp+18h] [ebp-418h]
  int v17; // [esp+1Ch] [ebp-414h]
  int i; // [esp+20h] [ebp-410h]
  _BYTE v19[1032]; // [esp+24h] [ebp-40Ch] BYREF

  if ( !CTilesEx::IsUsedRealTile(a1)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2597, "IsUsedRealTile(_iTileId)") == 1 )
  {
    __debugbreak();
  }
  if ( a2 == a3 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2598, "_iOldEcoSectorId != _iNewEcoSectorId") == 1 )
    __debugbreak();
  v3 = CTiles::TileEx(a1);
  v4 = CTile::CenterXY(v3);
  v13 = Y16X16::UnpackXFast(v4);
  v5 = CTiles::TileEx(a1);
  v6 = CTile::CenterXY(v5);
  v14 = Y16X16::UnpackYFast(v6);
  CSquareVisited::Init((CSquareVisited *)&unk_4300E70, v13, v14);
  TStaticFIFO<int,256>::TStaticFIFO<int,256>(v19);
  started = CSquareVisited::StartIndex((CSquareVisited *)&unk_4300E70);
  TStaticFIFO<int,256>::Push(&started);
  v7 = CSquareVisited::StartIndex((CSquareVisited *)&unk_4300E70);
  CSquareVisited::Set((CSquareVisited *)&unk_4300E70, v7);
  while ( 1 )
  {
    result = TStaticFIFO<int,256>::Empty(v19);
    if ( (_BYTE)result )
      break;
    v17 = *(_DWORD *)TStaticFIFO<int,256>::Top(v19);
    TStaticFIFO<int,256>::Pop(v19);
    v16 = CSquareVisited::WorldIdx((CSquareVisited *)&unk_4300E70, v17);
    CTiling::NotifyChangeEcoSector(v16, a2, a3, 1);
    for ( i = 0; i < 6; ++i )
    {
      v9 = CSquareVisited::NeighborRelIndex(i);
      v15 = v17 + v9;
      v10 = CTilingWorld::WorldNeighborRelIndex(i);
      v11 = v16 + v10;
      if ( CSquareVisited::SetIfNotVisited((CSquareVisited *)&unk_4300E70, v15) && ITiling::NormalTileId(v11) == a1 )
        TStaticFIFO<int,256>::Push(&v15);
    }
  }
  return result;
}


// address=[0x15eb310]
// Decompiled from int __cdecl CTiling::WalkTilesSetVisited(int a1)
static void __cdecl CTiling::WalkTilesSetVisited(int) {
  
  int **v1; // eax
  int result; // eax
  int v3; // eax
  int **v4; // eax
  int v5; // eax
  int v6; // [esp+0h] [ebp-20024h]
  int v7; // [esp+0h] [ebp-20024h]
  int **v8; // [esp+4h] [ebp-20020h]
  int v9; // [esp+8h] [ebp-2001Ch] BYREF
  int v10; // [esp+Ch] [ebp-20018h]
  unsigned __int8 *v11; // [esp+10h] [ebp-20014h]
  int i; // [esp+14h] [ebp-20010h]
  _BYTE v13[131080]; // [esp+18h] [ebp-2000Ch] BYREF

  if ( !CTiles::IsValidRealTile(a1)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2355, "IsValidRealTile(_iStartTileId)") == 1 )
  {
    __debugbreak();
  }
  v1 = CTiles::TileEx(a1);
  v7 = CTile::Type(v1, v6) & 0x3C000000;
  TLimitedFIFO<int,32768>::TLimitedFIFO<int,32768>(v13);
  TLimitedFIFO<int,32768>::Push(&a1);
  TBitArray<32768>::SetIfNotSet(a1);
  while ( 1 )
  {
    result = (unsigned __int8)TLimitedFIFO<int,32768>::Empty(v13);
    if ( (_BYTE)result )
      break;
    v10 = *(_DWORD *)TLimitedFIFO<int,32768>::Top(v13);
    TLimitedFIFO<int,32768>::Pop(v13);
    v8 = CTiles::TileEx(v10);
    v11 = (unsigned __int8 *)CTile::LinkList(v8);
    for ( i = 0; ; ++i )
    {
      v3 = CLinkList::Size(v11);
      if ( i >= v3 )
        break;
      v9 = *(unsigned __int16 *)CLinkList::operator[](v11, i);
      v4 = CTiles::TileEx(v9);
      v5 = CTile::Type(v4, v7);
      if ( (v7 & v5) != 0 )
      {
        if ( (unsigned __int8)TBitArray<32768>::SetIfNotSet(v10) )
          TLimitedFIFO<int,32768>::Push(&v9);
      }
    }
  }
  return result;
}


// address=[0x15eb4b0]
// Decompiled from int __cdecl CTiling::WalkTilesChangeSector(int a1, int a2)
static void __cdecl CTiling::WalkTilesChangeSector(int,int) {
  
  int **v2; // eax
  int **v3; // eax
  int result; // eax
  int v5; // eax
  int v6; // eax
  int **v7; // eax
  int v8; // eax
  int v9; // [esp+0h] [ebp-20028h]
  int v10; // [esp+0h] [ebp-20028h]
  int v11; // [esp+4h] [ebp-20024h]
  int v12; // [esp+8h] [ebp-20020h] BYREF
  unsigned __int8 *v13; // [esp+Ch] [ebp-2001Ch]
  int v14; // [esp+10h] [ebp-20018h]
  int **v15; // [esp+14h] [ebp-20014h]
  int i; // [esp+18h] [ebp-20010h]
  _BYTE v17[131080]; // [esp+1Ch] [ebp-2000Ch] BYREF

  if ( !CTiles::IsValidRealTile(a1)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2398, "IsValidRealTile(_iStartTileId)") == 1 )
  {
    __debugbreak();
  }
  v2 = CTiles::TileEx(a1);
  v14 = CTile::SectorId((CTile *)v2);
  v3 = CTiles::TileEx(a1);
  v10 = CTile::Type(v3, v9) & 0x3C000000;
  if ( v14 == a2 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2403, "iOldSectorId != _iNewSectorId") == 1 )
    __debugbreak();
  TStaticList<int,32768>::TStaticList<int,32768>(v17);
  TStaticList<int,32768>::PushBack(&a1);
  while ( 1 )
  {
    result = TStaticList<int,32768>::Empty(v17);
    if ( (_BYTE)result )
      break;
    v11 = *(_DWORD *)TStaticList<int,32768>::Front(v17);
    TStaticList<int,32768>::PopFront(v17);
    v15 = CTiles::TileEx(v11);
    v5 = CTile::SectorId((CTile *)v15);
    if ( v5 == v14 )
    {
      CTile::SetSectorId((CTile *)v15, a2);
      v13 = (unsigned __int8 *)CTile::LinkList(v15);
      for ( i = 0; ; ++i )
      {
        v6 = CLinkList::Size(v13);
        if ( i >= v6 )
          break;
        v12 = *(unsigned __int16 *)CLinkList::operator[](v13, i);
        v7 = CTiles::TileEx(v12);
        v8 = CTile::Type(v7, v10);
        if ( (v10 & v8) != 0 )
          TStaticList<int,32768>::PushBack(&v12);
      }
    }
  }
  return result;
}


// address=[0x15eb690]
// Decompiled from int __cdecl CTiling::WalkTilesSectorSetVisited(int a1)
static void __cdecl CTiling::WalkTilesSectorSetVisited(int) {
  
  int **v1; // eax
  int result; // eax
  int v3; // eax
  int **v4; // eax
  int v5; // eax
  int **v6; // [esp+0h] [ebp-20024h]
  int v7; // [esp+4h] [ebp-20020h] BYREF
  int v8; // [esp+8h] [ebp-2001Ch]
  unsigned __int8 *v9; // [esp+Ch] [ebp-20018h]
  int v10; // [esp+10h] [ebp-20014h]
  int i; // [esp+14h] [ebp-20010h]
  _BYTE v12[131080]; // [esp+18h] [ebp-2000Ch] BYREF

  if ( !CTiles::IsValidRealTile(a1)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2499, "IsValidRealTile(_iStartTileId)") == 1 )
  {
    __debugbreak();
  }
  v1 = CTiles::TileEx(a1);
  v8 = CTile::SectorId((CTile *)v1);
  if ( !v8 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2503, "iSectorId != 0") == 1 )
    __debugbreak();
  TLimitedFIFO<int,32768>::TLimitedFIFO<int,32768>(v12);
  TLimitedFIFO<int,32768>::Push(&a1);
  while ( 1 )
  {
    result = (unsigned __int8)TLimitedFIFO<int,32768>::Empty(v12);
    if ( (_BYTE)result )
      break;
    v10 = *(_DWORD *)TLimitedFIFO<int,32768>::Top(v12);
    TLimitedFIFO<int,32768>::Pop(v12);
    if ( (unsigned __int8)TBitArray<32768>::SetIfNotSet(v10) )
    {
      v6 = CTiles::TileEx(v10);
      v9 = (unsigned __int8 *)CTile::LinkList(v6);
      for ( i = 0; ; ++i )
      {
        v3 = CLinkList::Size(v9);
        if ( i >= v3 )
          break;
        v7 = *(unsigned __int16 *)CLinkList::operator[](v9, i);
        v4 = CTiles::TileEx(v7);
        v5 = CTile::SectorId((CTile *)v4);
        if ( v5 == v8 )
          TLimitedFIFO<int,32768>::Push(&v7);
      }
    }
  }
  return result;
}


// address=[0x15eb840]
// Decompiled from int __cdecl CTiling::WalkTilesEcoSectorSetVisited(int a1)
static void __cdecl CTiling::WalkTilesEcoSectorSetVisited(int) {
  
  int **v1; // eax
  int result; // eax
  int v3; // eax
  int **v4; // eax
  int v5; // eax
  int **v6; // [esp+0h] [ebp-20024h]
  int v7; // [esp+4h] [ebp-20020h] BYREF
  int v8; // [esp+8h] [ebp-2001Ch]
  unsigned __int8 *v9; // [esp+Ch] [ebp-20018h]
  int v10; // [esp+10h] [ebp-20014h]
  int i; // [esp+14h] [ebp-20010h]
  _BYTE v12[131080]; // [esp+18h] [ebp-2000Ch] BYREF

  if ( !CTiles::IsValidRealTile(a1)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2450, "IsValidRealTile(_iStartTileId)") == 1 )
  {
    __debugbreak();
  }
  v1 = CTiles::TileEx(a1);
  v8 = CTile::EcoSectorId((CTile *)v1);
  if ( !v8 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2454, "iEcoSectorId != 0") == 1 )
    __debugbreak();
  TLimitedFIFO<int,32768>::TLimitedFIFO<int,32768>(v12);
  TLimitedFIFO<int,32768>::Push(&a1);
  while ( 1 )
  {
    result = (unsigned __int8)TLimitedFIFO<int,32768>::Empty(v12);
    if ( (_BYTE)result )
      break;
    v10 = *(_DWORD *)TLimitedFIFO<int,32768>::Top(v12);
    TLimitedFIFO<int,32768>::Pop(v12);
    if ( (unsigned __int8)TBitArray<32768>::SetIfNotSet(v10) )
    {
      v6 = CTiles::TileEx(v10);
      v9 = (unsigned __int8 *)CTile::LinkList(v6);
      for ( i = 0; ; ++i )
      {
        v3 = CLinkList::Size(v9);
        if ( i >= v3 )
          break;
        v7 = *(unsigned __int16 *)CLinkList::operator[](v9, i);
        v4 = CTiles::TileEx(v7);
        v5 = CTile::EcoSectorId((CTile *)v4);
        if ( v5 == v8 )
          TLimitedFIFO<int,32768>::Push(&v7);
      }
    }
  }
  return result;
}


// address=[0x15eb9f0]
// Decompiled from int __cdecl CTiling::WalkTilesEcoSectorSetVisitedAndCountSize(int a1)
static int __cdecl CTiling::WalkTilesEcoSectorSetVisitedAndCountSize(int) {
  
  int **v1; // eax
  int **v2; // eax
  int **v3; // eax
  int i; // eax
  int **v5; // eax
  int **v6; // eax
  int **v7; // eax
  int **v8; // eax
  int **v10; // [esp+0h] [ebp-2002Ch]
  int v11; // [esp+4h] [ebp-20028h]
  unsigned __int8 *v12; // [esp+8h] [ebp-20024h]
  int v13; // [esp+Ch] [ebp-20020h]
  int v14; // [esp+10h] [ebp-2001Ch]
  int v15; // [esp+14h] [ebp-20018h]
  int v16; // [esp+18h] [ebp-20014h]
  int v17; // [esp+1Ch] [ebp-20010h] BYREF
  _BYTE v18[131080]; // [esp+20h] [ebp-2000Ch] BYREF

  if ( !CTiles::IsValidRealTile(a1)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2542, "IsValidRealTile(_iStartTileId)") == 1 )
  {
    __debugbreak();
  }
  v1 = CTiles::TileEx(a1);
  v14 = CTile::Size((CTile *)v1);
  v2 = CTiles::TileEx(a1);
  v15 = CTile::OwnerId((CTile *)v2);
  v3 = CTiles::TileEx(a1);
  v11 = CTile::EcoSectorId((CTile *)v3);
  if ( v15 <= 0 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2549, "iOwnerId > 0") == 1 )
    __debugbreak();
  if ( v11 <= 0 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2550, "iEcoSectorId > 0") == 1 )
    __debugbreak();
  TLimitedFIFO<int,32768>::TLimitedFIFO<int,32768>(v18);
  TLimitedFIFO<int,32768>::Push(&a1);
  while ( !(unsigned __int8)TLimitedFIFO<int,32768>::Empty(v18) )
  {
    v13 = *(_DWORD *)TLimitedFIFO<int,32768>::Top(v18);
    TLimitedFIFO<int,32768>::Pop(v18);
    if ( (unsigned __int8)TBitArray<32768>::SetIfNotSet(v13) )
    {
      v10 = CTiles::TileEx(v13);
      v12 = (unsigned __int8 *)CTile::LinkList(v10);
      v16 = 0;
      for ( i = CLinkList::Size(v12); v16 < i; i = CLinkList::Size(v12) )
      {
        v17 = *(unsigned __int16 *)CLinkList::operator[](v12, v16);
        v5 = CTiles::TileEx(v17);
        if ( CTile::EcoSectorId((CTile *)v5) == v11 )
        {
          v6 = CTiles::TileEx(v17);
          if ( CTile::OwnerId((CTile *)v6) != v15
            && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2573, "TileEx(iLinkTileId).OwnerId() == iOwnerId") == 1 )
          {
            __debugbreak();
          }
          v7 = CTiles::TileEx(v17);
          v14 += CTile::Size((CTile *)v7);
          TLimitedFIFO<int,32768>::Push(&v17);
        }
        else
        {
          v8 = CTiles::TileEx(v17);
          if ( CTile::OwnerId((CTile *)v8) == v15
            && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2581, "TileEx(iLinkTileId).OwnerId() != iOwnerId") == 1 )
          {
            __debugbreak();
          }
        }
        ++v16;
      }
    }
  }
  return v14;
}


// address=[0x15ebcb0]
// Decompiled from int __cdecl CTiling::WalkTilesChangeEcoSector(int a1, int a2)
static void __cdecl CTiling::WalkTilesChangeEcoSector(int,int) {
  
  int **v2; // eax
  int **v3; // eax
  int result; // eax
  int *v5; // eax
  int v6; // eax
  int v7; // eax
  int **v8; // eax
  int v9; // eax
  int v10; // [esp+0h] [ebp-20024h] BYREF
  int v11; // [esp+4h] [ebp-20020h]
  unsigned __int8 *v12; // [esp+8h] [ebp-2001Ch]
  int v13; // [esp+Ch] [ebp-20018h]
  int **v14; // [esp+10h] [ebp-20014h]
  int i; // [esp+14h] [ebp-20010h]
  _BYTE v16[131080]; // [esp+18h] [ebp-2000Ch] BYREF

  if ( !CTiles::IsValidRealTile(a1)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2685, "IsValidRealTile(_iStartTileId)") == 1 )
  {
    __debugbreak();
  }
  v2 = CTiles::TileEx(a1);
  v11 = CTile::OwnerId((CTile *)v2);
  v3 = CTiles::TileEx(a1);
  v13 = CTile::EcoSectorId((CTile *)v3);
  if ( !v11 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2690, "iOwnerId != 0") == 1 )
    __debugbreak();
  if ( v13 == a2 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2691, "iOldEcoSectorId != _iNewEcoSectorId") == 1 )
    __debugbreak();
  TLimitedFIFO<int,32768>::TLimitedFIFO<int,32768>(v16);
  TLimitedFIFO<int,32768>::Push(&a1);
  while ( 1 )
  {
    result = (unsigned __int8)TLimitedFIFO<int,32768>::Empty(v16);
    if ( (_BYTE)result )
      break;
    v5 = (int *)TLimitedFIFO<int,32768>::Top(v16);
    v14 = CTiles::TileEx(*v5);
    TLimitedFIFO<int,32768>::Pop(v16);
    v6 = CTile::EcoSectorId((CTile *)v14);
    if ( v6 == v13 )
    {
      CTile::SetEcoSectorId((CTile *)v14, a2);
      v12 = (unsigned __int8 *)CTile::LinkList(v14);
      for ( i = 0; ; ++i )
      {
        v7 = CLinkList::Size(v12);
        if ( i >= v7 )
          break;
        v10 = *(unsigned __int16 *)CLinkList::operator[](v12, i);
        v8 = CTiles::TileEx(v10);
        v9 = CTile::OwnerId((CTile *)v8);
        if ( v9 == v11 )
          TLimitedFIFO<int,32768>::Push(&v10);
      }
    }
  }
  return result;
}


// address=[0x15ebea0]
// Decompiled from int __cdecl CTiling::WalkTilesChangeEcoSectorAndNotify(int a1, int a2)
static void __cdecl CTiling::WalkTilesChangeEcoSectorAndNotify(int,int) {
  
  int **v2; // eax
  int **v3; // eax
  int result; // eax
  int v5; // eax
  int v6; // eax
  int **v7; // eax
  int v8; // eax
  int v9; // [esp+0h] [ebp-20028h] BYREF
  int v10; // [esp+4h] [ebp-20024h]
  unsigned __int8 *v11; // [esp+8h] [ebp-20020h]
  int v12; // [esp+Ch] [ebp-2001Ch]
  int **v13; // [esp+10h] [ebp-20018h]
  int v14; // [esp+14h] [ebp-20014h]
  int i; // [esp+18h] [ebp-20010h]
  _BYTE v16[131080]; // [esp+1Ch] [ebp-2000Ch] BYREF

  if ( !CTiles::IsValidRealTile(a1)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2728, "IsValidRealTile(_iStartTileId)") == 1 )
  {
    __debugbreak();
  }
  v2 = CTiles::TileEx(a1);
  v10 = CTile::OwnerId((CTile *)v2);
  v3 = CTiles::TileEx(a1);
  v14 = CTile::EcoSectorId((CTile *)v3);
  if ( !v10 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2733, "iOwnerId != 0") == 1 )
    __debugbreak();
  if ( v14 == a2 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 2734, "iOldEcoSectorId != _iNewEcoSectorId") == 1 )
    __debugbreak();
  TLimitedFIFO<int,32768>::TLimitedFIFO<int,32768>(v16);
  TLimitedFIFO<int,32768>::Push(&a1);
  while ( 1 )
  {
    result = (unsigned __int8)TLimitedFIFO<int,32768>::Empty(v16);
    if ( (_BYTE)result )
      break;
    v12 = *(_DWORD *)TLimitedFIFO<int,32768>::Top(v16);
    TLimitedFIFO<int,32768>::Pop(v16);
    v13 = CTiles::TileEx(v12);
    v5 = CTile::EcoSectorId((CTile *)v13);
    if ( v5 == v14 )
    {
      CTile::SetEcoSectorId((CTile *)v13, a2);
      CTiling::WalkTileNotifyEcoSectorChange(v12, v14, a2);
      v11 = (unsigned __int8 *)CTile::LinkList(v13);
      for ( i = 0; ; ++i )
      {
        v6 = CLinkList::Size(v11);
        if ( i >= v6 )
          break;
        v9 = *(unsigned __int16 *)CLinkList::operator[](v11, i);
        v7 = CTiles::TileEx(v9);
        v8 = CTile::OwnerId((CTile *)v7);
        if ( v8 == v10 )
          TLimitedFIFO<int,32768>::Push(&v9);
      }
    }
  }
  return result;
}


// address=[0x15ec0c0]
// Decompiled from int __cdecl CTiling::CalculateBorderstoneBit(unsigned int a1, unsigned int a2)
static void __cdecl CTiling::CalculateBorderstoneBit(int,int) {
  
  int v3; // [esp+0h] [ebp-18h]
  int v4; // [esp+8h] [ebp-10h]
  int v5; // [esp+Ch] [ebp-Ch]
  int v6; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  if ( !CTilingWorld::WorldInWorld(a1, a2)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 401, "WorldInWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  v6 = CTilingWorld::WorldIndex(a1, a2);
  if ( !CTilingWorld::WorldInInnerWorld1(a1, a2) )
    return CTilingWorld::WorldClearGfxBorderstoneBit(v6);
  v5 = ITiling::OwnerId(v6);
  if ( v5 > 0 )
  {
    for ( i = 0; i < 6; ++i )
    {
      v4 = v6 + CTilingWorld::WorldSortedNeighborRelIndex(i);
      if ( ITiling::OwnerId(v4) != v5 )
      {
        v3 = CTilingWorld::WorldGroundType(v4);
        if ( !CTilingWorld::WorldIsGroundTypeWater(v3) )
          return CTilingWorld::WorldSetGfxBorderstoneBit(v6);
      }
    }
  }
  return CTilingWorld::WorldClearGfxBorderstoneBit(v6);
}


// address=[0x15ec1c0]
// Decompiled from int __cdecl CTiling::CalculateBorderstoneBits7(unsigned int a1, unsigned int a2)
static void __cdecl CTiling::CalculateBorderstoneBits7(int,int) {
  
  int result; // eax
  int i; // [esp+8h] [ebp-4h]

  if ( !CTilingWorld::WorldInInnerWorld1(a1, a2)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 441, "WorldInInnerWorld1(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  result = CTiling::CalculateBorderstoneBit(a1, a2);
  for ( i = 0; i < 6; ++i )
  {
    CTiling::CalculateBorderstoneBit(g_sNeighborPoints[2 * i] + a1, dword_37D8C0C[2 * i] + a2);
    result = i + 1;
  }
  return result;
}


// address=[0x15ec260]
// Decompiled from int CTiling::ClearBorderstoneBits()
static void __cdecl CTiling::ClearBorderstoneBits(void) {
  
  int result; // eax
  int v1; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v1 = CTilingWorld::WorldWidthHeight();
  result = v1 * v1;
  for ( i = 0; i < v1 * v1; ++i )
    result = CTilingWorld::WorldClearGfxBorderstoneBit(i);
  return result;
}


// address=[0x15ec2b0]
// Decompiled from char *CTiling::CalculateBorderstoneBits()
static void __cdecl CTiling::CalculateBorderstoneBits(void) {
  
  Squares *v0; // eax
  char *result; // eax
  signed int v2; // [esp+8h] [ebp-1Ch]
  signed int v3; // [esp+Ch] [ebp-18h]
  int v4; // [esp+10h] [ebp-14h]
  signed int m; // [esp+14h] [ebp-10h]
  signed int k; // [esp+18h] [ebp-Ch]
  Squares *i; // [esp+1Ch] [ebp-8h]
  Squares *j; // [esp+20h] [ebp-4h]

  v0 = (Squares *)CTilingWorld::WorldWidthHeight();
  result = (char *)Squares::XYToVW(v0);
  v4 = (int)result;
  for ( i = 0; (int)i < v4; i = (Squares *)((char *)i + 1) )
  {
    for ( j = 0; (int)j < v4; j = (Squares *)((char *)j + 1) )
    {
      if ( COwnerMap::OwnerBits1VW(j, i) )
      {
        v2 = Squares::VWToXY(j);
        v3 = Squares::VWToXY(i);
        for ( k = v3; k < v3 + 16; ++k )
        {
          for ( m = v2; m < v2 + 16; ++m )
            CTiling::CalculateBorderstoneBit(m, k);
        }
      }
    }
    result = (char *)i + 1;
  }
  return result;
}


// address=[0x15ec3a0]
// Decompiled from char __cdecl CTiling::BlockedLandSurroundingCheck(int a1, int a2)
static void __cdecl CTiling::BlockedLandSurroundingCheck(int,int) {
  
  Grid *v2; // eax
  __int16 v3; // ax
  Grid *v4; // eax
  Grid *v6; // [esp+0h] [ebp-40B0h]
  int v7; // [esp+4h] [ebp-40ACh] BYREF
  Grid *v8; // [esp+8h] [ebp-40A8h]
  int v9; // [esp+Ch] [ebp-40A4h] BYREF
  Grid *v10; // [esp+10h] [ebp-40A0h]
  int v11; // [esp+14h] [ebp-409Ch]
  int v12; // [esp+18h] [ebp-4098h]
  int v13; // [esp+1Ch] [ebp-4094h]
  BOOL v14; // [esp+20h] [ebp-4090h]
  BOOL v15; // [esp+24h] [ebp-408Ch]
  int v16; // [esp+28h] [ebp-4088h]
  int v17; // [esp+2Ch] [ebp-4084h]
  BOOL v18; // [esp+30h] [ebp-4080h]
  BOOL v19; // [esp+34h] [ebp-407Ch]
  BOOL v20; // [esp+38h] [ebp-4078h]
  int v21; // [esp+3Ch] [ebp-4074h]
  int v22; // [esp+40h] [ebp-4070h]
  BOOL v23; // [esp+44h] [ebp-406Ch]
  BOOL v24; // [esp+48h] [ebp-4068h]
  int v25; // [esp+4Ch] [ebp-4064h]
  unsigned int v26; // [esp+50h] [ebp-4060h]
  unsigned int v27; // [esp+54h] [ebp-405Ch]
  int v28; // [esp+58h] [ebp-4058h]
  int v29; // [esp+5Ch] [ebp-4054h]
  int v30; // [esp+60h] [ebp-4050h]
  int v31; // [esp+64h] [ebp-404Ch]
  int j; // [esp+68h] [ebp-4048h]
  int v33; // [esp+6Ch] [ebp-4044h]
  unsigned int v34; // [esp+70h] [ebp-4040h]
  unsigned int v35; // [esp+74h] [ebp-403Ch]
  int v36; // [esp+78h] [ebp-4038h]
  int k; // [esp+7Ch] [ebp-4034h]
  int v38; // [esp+80h] [ebp-4030h]
  int v39; // [esp+84h] [ebp-402Ch]
  int v40; // [esp+88h] [ebp-4028h]
  int i; // [esp+8Ch] [ebp-4024h]
  int v42; // [esp+90h] [ebp-4020h]
  Grid *v43; // [esp+94h] [ebp-401Ch]
  Grid *v44; // [esp+98h] [ebp-4018h]
  char v49; // [esp+A2h] [ebp-400Eh]
  bool v50; // [esp+A3h] [ebp-400Dh]
  _BYTE v51[16392]; // [esp+A4h] [ebp-400Ch] BYREF

  if ( !CTilingWorld::WorldInInnerWorld1(a1, a2)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 6007, "WorldInInnerWorld1(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  v25 = CTilingWorld::WorldIndex(a1, a2);
  v44 = (Grid *)ITiling::OwnerId(v25);
  if ( CTilingWorld::WorldIsBlockedLand(v25)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 6012, "!WorldIsBlockedLand(iWorldIdx0)") == 1 )
  {
    __debugbreak();
  }
  LOBYTE(v2) = 0;
  if ( (int)v44 <= 0 )
  {
    v2 = (Grid *)BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 6013, "iOwnerId > 0");
    if ( v2 == (Grid *)1 )
      __debugbreak();
  }
  v39 = -1;
  v33 = 0;
  for ( i = 0; i < 6; ++i )
  {
    v16 = v25 + CTilingWorld::WorldNeighborRelIndex(i);
    LOBYTE(v2) = CTilingWorld::WorldIsBlockedLand(v16);
    v49 = (char)v2;
    if ( (_BYTE)v2 )
    {
      ++v33;
      LOBYTE(v2) = CTilingWorld::WorldIsWater(v16);
      v12 = (unsigned __int8)v2;
      if ( !(_BYTE)v2 )
      {
        LOBYTE(v2) = i;
        v39 = i;
      }
    }
  }
  v24 = v39 >= 0;
  v23 = v33 < 6;
  if ( !v23 || !v24 )
    return (char)v2;
  v50 = 0;
  v40 = 1;
  v43 = (Grid *)Grid::TurnRight((Grid *)v39);
  LOBYTE(v2) = a1;
  v30 = a1;
  v29 = a2;
  for ( j = 0; j < 0x40000; ++j )
  {
    v22 = g_sNeighborPoints[2 * (_DWORD)v43] + v30;
    v21 = dword_37D8C0C[2 * (_DWORD)v43] + v29;
    v31 = CTilingWorld::WorldIndex(v22, v21);
    if ( CTilingWorld::WorldIsBlockedLand(v31) )
    {
      LOBYTE(v2) = CTilingWorld::WorldIsWater(v31);
      v11 = (unsigned __int8)v2;
      if ( (_BYTE)v2 )
        break;
      ++v40;
      v2 = (Grid *)Grid::TurnRight(v43);
      v43 = v2;
    }
    else
    {
      v2 = (Grid *)ITiling::OwnerId(v31);
      v6 = v2;
      if ( v2 != v44 )
        break;
      --v40;
      v43 = (Grid *)Grid::TurnLeft(v43);
      v30 = v22;
      v29 = v21;
      LOBYTE(v2) = v22;
      v20 = v22 == a1;
      v19 = v21 == a2;
      if ( v19 && v20 )
      {
        v18 = v40 < 0;
        LOBYTE(v2) = v40 < 0;
        v50 = v40 < 0;
        break;
      }
    }
  }
  if ( !v50 )
    return (char)v2;
  v42 = v39;
  v27 = a1;
  v26 = a2;
  do
  {
    while ( 1 )
    {
      v35 = g_sNeighborPoints[2 * v42] + v27;
      v34 = dword_37D8C0C[2 * v42] + v26;
      v36 = CTilingWorld::WorldIndex(v35, v34);
      if ( !CTilingWorld::WorldIsBlockedLand(v36) )
        break;
      if ( CTilingWorld::WorldIsWater(v36)
        && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 6123, "!WorldIsWater(iCheckWorldIdx)") == 1 )
      {
        __debugbreak();
      }
      v10 = (Grid *)ITiling::OwnerId(v36);
      if ( v10 != v44 )
      {
        TStaticFIFO<int,4096>::TStaticFIFO<int,4096>(v51, v6);
        v9 = Y16X16::PackXYFast(v35, v34);
        TStaticFIFO<int,4096>::Push(&v9);
        while ( !(unsigned __int8)TStaticFIFO<int,4096>::Empty(v51) )
        {
          v28 = *(_DWORD *)TStaticFIFO<int,4096>::Top(v51);
          TStaticFIFO<int,4096>::Pop(v51);
          v13 = Y16X16::UnpackXFast(v28);
          v17 = Y16X16::UnpackYFast(v28);
          v38 = CTilingWorld::WorldIndex(v13, v17);
          if ( CTilingWorld::WorldIsBlockedLand(v38) && !CTilingWorld::WorldIsWater(v38) )
          {
            v8 = (Grid *)ITiling::OwnerId(v38);
            if ( v8 != v44 )
            {
              v3 = ITiling::OwnerPseudoTileId((int)v44);
              CTiling::SetNormalTileId(v38, v3);
              (*(void (__thiscall **)(void *, int, int, Grid *))(*(_DWORD *)g_pFogging + 28))(g_pFogging, v13, v17, v44);
              for ( k = 0; k < 6; ++k )
              {
                v7 = Y16X16::g_iNeighborY16X16Modifiers[k] + v28;
                TStaticFIFO<int,4096>::Push(&v7);
              }
            }
          }
        }
      }
      CTiling::CalculateBorderstoneBits7(v35, v34);
      v42 = Grid::TurnRight((Grid *)v42);
    }
    v4 = (Grid *)ITiling::OwnerId(v36);
    if ( v4 != v44 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 6179, "OwnerId(iCheckWorldIdx) == iOwnerId") == 1 )
      __debugbreak();
    v42 = Grid::TurnLeft((Grid *)v42);
    v27 = v35;
    v26 = v34;
    v15 = v35 == a1;
    v14 = v34 == a2;
    LOBYTE(v2) = v14 && v15;
  }
  while ( !v14 || !v15 );
  return (char)v2;
}


// address=[0x15ecb50]
// Decompiled from int __thiscall CTiling::Init(  CTiling *this,  int a2,  struct T_GFX_MAP_ELEMENT *a3,  unsigned __int8 *a4,  unsigned __int16 *a5,  unsigned __int16 *a6,  unsigned __int8 *a7,  bool a8)
void  CTiling::Init(int,struct T_GFX_MAP_ELEMENT *,unsigned char *,unsigned short *,unsigned short *,unsigned char *,bool) {
  
  double v8; // st7
  int result; // eax
  _BYTE v10[24]; // [esp+14h] [ebp-34h] BYREF
  int v11; // [esp+2Ch] [ebp-1Ch]
  int v12; // [esp+30h] [ebp-18h]
  int j; // [esp+34h] [ebp-14h]
  int i; // [esp+38h] [ebp-10h]
  int k; // [esp+3Ch] [ebp-Ch]
  CTiling *v16; // [esp+40h] [ebp-8h]

  v16 = this;
  if ( !a5 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3921, "_pNormalTileIds != 0") == 1 )
    __debugbreak();
  if ( !a6 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3922, "_pCatapultTileIds != 0") == 1 )
    __debugbreak();
  (*(void (__thiscall **)(CTiling *))(*(_DWORD *)v16 + 4))(v16);
  CTilingWorld::WorldInterfaceInit(a2, a3, a4, a7);
  ITiling::m_pTileIds = (__int16 *)a5;
  *(&ITiling::m_pTileIds + 1) = (__int16 *)a6;
  v12 = a2 * a2;
  for ( i = 0; i < v12; ++i )
  {
    if ( !CTiles::IsValidPseudoTile(a5[i])
      && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3939, "CTiling::IsValidPseudoTile(_pNormalTileIds[i])") == 1 )
    {
      __debugbreak();
    }
  }
  for ( j = 0; j < v12; ++j )
  {
    if ( a6[j] && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3944, "_pCatapultTileIds[j] == 0") == 1 )
      __debugbreak();
  }
  (*(void (__thiscall **)(CTiling *, _DWORD))(*(_DWORD *)v16 + 80))(v16, 0);
  v11 = a2 * a2;
  for ( k = 0; k < v11; ++k )
  {
    if ( CTilingWorld::WorldIsWater(k) )
      CTilingWorld::WorldSetBlockedLandFlag(k);
  }
  CTiling::BlockBorder();
  (*(void (__thiscall **)(void *, struct T_GFX_MAP_ELEMENT *, unsigned __int8 *))(*(_DWORD *)g_pFogging + 8))(
    g_pFogging,
    a3,
    a7);
  CWater::Init(a6);
  CPerformanceCounter::CPerformanceCounter((CPerformanceCounter *)v10);
  CPerformanceCounter::Start((CPerformanceCounter *)v10);
  CTiling::CalcAllTiles();
  CTiling::CalcAllTileLinks();
  CTiling::CalcSectorIds(a8);
  CTiling::CalcNotifyAll(a8);
  CTilesEx::CalculateOwnerBits();
  CTiling::CalculateBorderstoneBits();
  CPerformanceCounter::Measure((CPerformanceCounter *)v10);
  v8 = CPerformanceCounter::TimeMs((CPerformanceCounter *)v10);
  BBSupportTracePrintF(0, "CTiling::Init(): %.3f ms", v8);
  CProfile::Clear((CProfile *)&unk_42F79B0);
  CProfile::Clear((CProfile *)&unk_42F7A58);
  CProfile::Clear((CProfile *)&unk_42F7B00);
  CProfile::Clear((CProfile *)&unk_42F7BA8);
  if ( (*(int (__thiscall **)(CTiling *, _DWORD))(*(_DWORD *)v16 + 72))(v16, 0)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3994, "DbgCheckTiling() == 0") == 1 )
  {
    __debugbreak();
  }
  if ( CTiling::DbgCheckTileSizes(0)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3995, "DbgCheckTileSizes() == 0") == 1 )
  {
    __debugbreak();
  }
  if ( CTiling::DbgCheckSectors(0) && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3996, "DbgCheckSectors() == 0") == 1 )
    __debugbreak();
  result = CTiling::DbgCheckEcoSectors(0);
  if ( result )
  {
    result = BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 3997, "DbgCheckEcoSectors() == 0");
    if ( result == 1 )
      __debugbreak();
  }
  CTiling::m_iInitialized = 1;
  return result;
}


// address=[0x15ece80]
// Decompiled from void __thiscall CTiling::Done(CTiling *this)
void  CTiling::Done(void) {
  
  const char *v1; // eax
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax

  if ( CTiling::m_iInitialized )
  {
    (*(void (__thiscall **)(CTiling *, _DWORD))(*(_DWORD *)this + 72))(this, 0);
    CTiling::DbgCheckTileSizes(0);
    CTiling::DbgCheckSectors(0);
    CTiling::DbgCheckEcoSectors(0);
    BBSupportTracePrintF(0, "CTiling::Done()...");
    BBSupportTracePrintF(
      0,
      "  Maximal number of used tiles was %i (%.1f%%).",
      CTilesEx::m_iMaxUsedTiles,
      (double)CTilesEx::m_iMaxUsedTiles / 32757.0 * 100.0);
    BBSupportTracePrintF(0, "  CalculateListOfFreeTiles() was called %i times.", CTilesEx::m_iCalcFreeListCounter);
    v1 = CProfile::InfoStr((CProfile *)&unk_42F79B0);
    BBSupportTracePrintF(0, "  SetBlockedLand():   %s", v1);
    v2 = CProfile::InfoStr((CProfile *)&unk_42F7A58);
    BBSupportTracePrintF(0, "  ClearBlockedLand(): %s", v2);
    v3 = CProfile::InfoStr((CProfile *)&unk_42F7B00);
    BBSupportTracePrintF(0, "  ChangeOwner():      %s", v3);
    v4 = CProfile::InfoStr((CProfile *)&unk_42F7BA8);
    BBSupportTracePrintF(0, "  Update():           %s", v4);
    CTiling::m_iInitialized = 0;
    (*(void (__thiscall **)(void *))(*(_DWORD *)g_pFogging + 12))(g_pFogging);
    CWater::Done();
    ITiling::m_pTileIds = 0;
    *(&ITiling::m_pTileIds + 1) = 0;
    CTilingWorld::WorldInterfaceDone(4, 0);
  }
}


// address=[0x15ecfe0]
// Decompiled from int __thiscall CTiling::Update(CTiling *this)
void  CTiling::Update(void) {
  
  if ( CTiling::m_iInitialized )
  {
    CProfile::Begin((CProfile *)&unk_42F7BA8);
    CTilesAndLinks::LinksGarbageCollection(16);
    CProfile::End((CProfile *)&unk_42F7BA8);
  }
  else if ( BBSupportDbgReport(1, "Pathing\\Tiling.cpp", 4076, "CTiling::Update(): Not initialized!") == 1 )
  {
    __debugbreak();
  }
  return (*(int (__thiscall **)(void *, CTiling *))(*(_DWORD *)g_pFogging + 20))(g_pFogging, this);
}


// address=[0x15ed050]
// Decompiled from void __thiscall CTiling::SetBlockedLand(CTiling *this, unsigned int a2, unsigned int a3)
void  CTiling::SetBlockedLand(int,int) {
  
  int v3; // eax
  unsigned int v4; // [esp+0h] [ebp-14h]
  unsigned int v5; // [esp+4h] [ebp-10h]
  int v7; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  if ( byte_42CF998 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4093, "!s_bTilingInModification") == 1 )
    __debugbreak();
  byte_42CF998 = 1;
  if ( CTilingWorld::WorldInInnerWorld2(a2, a3) )
  {
    v7 = CTilingWorld::WorldIndex(a2, a3);
    if ( CTilingWorld::WorldIsBlockedLand(v7) )
    {
      byte_42CF998 = 0;
    }
    else
    {
      if ( CTilingWorld::WorldIsWater(v7)
        && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4117, "!WorldIsWater(iWorldIdx)") == 1 )
      {
        __debugbreak();
      }
      v3 = ITiling::NormalTileId(v7);
      if ( !CTiles::IsValidRealTile(v3)
        && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4118, "IsValidRealTile(NormalTileId(iWorldIdx))") == 1 )
      {
        __debugbreak();
      }
      CProfile::Begin((CProfile *)&unk_42F79B0);
      CTilingWorld::WorldSetBlockedLandFlag(v7);
      CTiling::SetBlockingEx(this, 0, a2, a3);
      for ( i = 0; i < 19; ++i )
      {
        v4 = a2 + CSpiralOffsets::DeltaX(i);
        v5 = a3 + CSpiralOffsets::DeltaY(i);
        CTiling::SetBlockingEx(this, 1, v4, v5);
      }
      CTiling::CalculateBorderstoneBits7(a2, a3);
      CProfile::End((CProfile *)&unk_42F79B0);
      byte_42CF998 = 0;
    }
  }
  else
  {
    if ( BBSupportDbgReport(
           1,
           "Pathing\\Tiling.cpp",
           4099,
           "CTiling::SetBlockedLand(): (X, Y) must be in inner inner world!") == 1 )
      __debugbreak();
    byte_42CF998 = 0;
  }
}


// address=[0x15ed210]
// Decompiled from int __stdcall sub_19ED210(int a1, int a2)
void  CTiling::SetBlockedWater(int,int) {
  
  int result; // eax
  int v3; // [esp+4h] [ebp-4h]

  if ( byte_42CF998 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4156, "!s_bTilingInModification") == 1 )
    __debugbreak();
  byte_42CF998 = 1;
  if ( (unsigned __int8)CTilingWorld::WorldInInnerWorld2(a1, a2) )
  {
    v3 = CTilingWorld::WorldIndex(a1, a2);
    result = (unsigned __int8)CWaterFlags::IsBlockedWater(v3);
    if ( (_BYTE)result )
    {
      byte_42CF998 = 0;
    }
    else
    {
      if ( !(unsigned __int8)CTilingWorld::WorldIsWater(v3)
        && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4180, "WorldIsWater(iWorldIdx)") == 1 )
      {
        __debugbreak();
      }
      CWaterFlags::SetWaterFlagBits(v3, 512);
      result = CTiling::SetBlockingEx(0, a1, a2);
      byte_42CF998 = 0;
    }
  }
  else
  {
    result = BBSupportDbgReport(
               1,
               "Pathing\\Tiling.cpp",
               4162,
               "CTiling::SetBlockedWater(): (X, Y) must be in inner inner world!");
    if ( result == 1 )
      __debugbreak();
    byte_42CF998 = 0;
  }
  return result;
}


// address=[0x15ed320]
// Decompiled from void __thiscall CTiling::ClearBlockedLand(CTiling *this, unsigned int a2, unsigned int a3)
void  CTiling::ClearBlockedLand(int,int) {
  
  int v3; // [esp+0h] [ebp-28h]
  int v4; // [esp+4h] [ebp-24h]
  int v5; // [esp+8h] [ebp-20h]
  unsigned int v7; // [esp+10h] [ebp-18h]
  unsigned int v8; // [esp+14h] [ebp-14h]
  int v9; // [esp+18h] [ebp-10h]
  int j; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  char v12; // [esp+27h] [ebp-1h]

  if ( byte_42CF998 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4277, "!s_bTilingInModification") == 1 )
    __debugbreak();
  byte_42CF998 = 1;
  if ( CTilingWorld::WorldInInnerWorld2(a2, a3) )
  {
    v9 = CTilingWorld::WorldIndex(a2, a3);
    if ( CTilingWorld::WorldIsWater(v9) )
    {
      byte_42CF998 = 0;
    }
    else if ( CTilingWorld::WorldIsBlockedLand(v9) )
    {
      CProfile::Begin((CProfile *)&unk_42F7A58);
      CTilingWorld::WorldClearBlockedLandFlag(v9);
      CTiling::ClearBlockingEx(this, 0, a2, a3);
      for ( i = 0; i < 19; ++i )
      {
        v7 = a2 + CSpiralOffsets::DeltaX(i);
        v8 = a3 + CSpiralOffsets::DeltaY(i);
        v12 = 0;
        for ( j = 0; j < 19; ++j )
        {
          v4 = v7 + CSpiralOffsets::DeltaX(j);
          v5 = v8 + CSpiralOffsets::DeltaY(j);
          v3 = CTilingWorld::WorldIndex(v4, v5);
          if ( CTilingWorld::WorldIsBlockedLand(v3) )
          {
            v12 = 1;
            break;
          }
        }
        if ( !v12 )
          CTiling::ClearBlockingEx(this, 1, v7, v8);
      }
      CTiling::CalculateBorderstoneBits7(a2, a3);
      CProfile::End((CProfile *)&unk_42F7A58);
      byte_42CF998 = 0;
    }
    else
    {
      byte_42CF998 = 0;
    }
  }
  else
  {
    if ( BBSupportDbgReport(
           1,
           "Pathing\\Tiling.cpp",
           4283,
           "CTiling::ClearBlockedLand(): (X, Y) must be in inner inner world!") == 1 )
      __debugbreak();
    byte_42CF998 = 0;
  }
}


// address=[0x15ed510]
// Decompiled from char __thiscall CTiling::ClearBlockedWater(CTiling *this, int a2, int a3)
void  CTiling::ClearBlockedWater(int,int) {
  
  int v3; // eax
  int v6; // [esp+4h] [ebp-4h]

  if ( byte_42CF998 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4366, "!s_bTilingInModification") == 1 )
    __debugbreak();
  byte_42CF998 = 1;
  if ( CTilingWorld::WorldInInnerWorld2(a2, a3) )
  {
    v6 = CTilingWorld::WorldIndex(a2, a3);
    LOBYTE(v3) = CWaterFlags::IsWater(v6);
    if ( (_BYTE)v3 )
    {
      if ( !CTilingWorld::WorldIsWater(v6)
        && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4390, "WorldIsWater(iWorldIdx)") == 1 )
      {
        __debugbreak();
      }
      v3 = CWaterFlags::WaterFlags(v6) & 0x200;
      if ( v3 )
      {
        CWaterFlags::ClearWaterFlagBits(v6, 512);
        LOBYTE(v3) = CWaterFlags::IsFreeWater(v6);
        if ( (_BYTE)v3 )
          LOBYTE(v3) = CTiling::ClearBlockingEx(this, 0, a2, a3);
        byte_42CF998 = 0;
      }
      else
      {
        byte_42CF998 = 0;
      }
    }
    else
    {
      byte_42CF998 = 0;
    }
  }
  else
  {
    v3 = BBSupportDbgReport(
           1,
           "Pathing\\Tiling.cpp",
           4372,
           "CTiling::ClearBlockedWater(): (X, Y) must be in inner inner world!");
    if ( v3 == 1 )
      __debugbreak();
    byte_42CF998 = 0;
  }
  return v3;
}


// address=[0x15ed660]
// Decompiled from void __thiscall CTiling::ChangeOwner(CTiling *this, unsigned int a2, unsigned int a3, int a4)
void  CTiling::ChangeOwner(int,int,int) {
  
  int **v4; // eax
  int **v5; // eax
  __int16 v6; // ax
  int v7; // eax
  int **v8; // eax
  int **v9; // eax
  int **v10; // eax
  int v11; // eax
  int **v12; // eax
  int **v13; // eax
  int v14; // eax
  NeighborAnalysis *v16; // [esp+0h] [ebp-1Ch]
  __int16 v17; // [esp+4h] [ebp-18h]
  DWORD v18; // [esp+8h] [ebp-14h]
  int v19; // [esp+Ch] [ebp-10h]
  int v20; // [esp+10h] [ebp-Ch]
  NeighborAnalysis *v21; // [esp+14h] [ebp-8h]

  if ( byte_42CF998 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4499, "!s_bTilingInModification") == 1 )
    __debugbreak();
  byte_42CF998 = 1;
  if ( !CTilingWorld::WorldInInnerWorld1(a2, a3)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4503, "WorldInInnerWorld1(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( !CTiling::IsValidOwnerId(a4)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4504, "IsValidOwnerId(_iNewOwnerId)") == 1 )
  {
    __debugbreak();
  }
  v20 = CTilingWorld::WorldIndex(a2, a3);
  v21 = (NeighborAnalysis *)ITiling::NormalTileId(v20);
  v4 = CTiles::TileEx((int)v21);
  v19 = CTile::OwnerId((CTile *)v4);
  v5 = CTiles::TileEx((int)v21);
  v17 = CTile::SectorId((CTile *)v5);
  if ( v19 == a4 )
  {
    byte_42CF998 = 0;
  }
  else
  {
    --CTiling::m_iNumberOfOwnedElements[v19];
    ++CTiling::m_iNumberOfOwnedElements[a4];
    if ( CTilingWorld::WorldIsBlockedLand(v20) )
    {
      if ( !CTilingWorld::WorldIsWater(v20) )
      {
        CProfile::Begin((CProfile *)&unk_42F7B00);
        v6 = ITiling::OwnerPseudoTileId(a4);
        CTiling::SetNormalTileId(v20, v6);
        CTiling::CalculateBorderstoneBits7(a2, a3);
        (*(void (__thiscall **)(void *, unsigned int, unsigned int, int))(*(_DWORD *)g_pFogging + 28))(
          g_pFogging,
          a2,
          a3,
          a4);
        CProfile::End((CProfile *)&unk_42F7B00);
      }
      byte_42CF998 = 0;
    }
    else
    {
      if ( !CTiles::IsValidRealTile(v21)
        && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4570, "IsValidRealTile(iOldTileId)") == 1 )
      {
        __debugbreak();
      }
      if ( !CTilesEx::IsValidUsedTile(v21)
        && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4571, "IsValidUsedTile(iOldTileId)") == 1 )
      {
        __debugbreak();
      }
      CProfile::Begin((CProfile *)&unk_42F7B00);
      v7 = CTilingWorld::WorldGroundType(v20);
      v18 = CTiling::TileType(a4, v7, a2, a3);
      NeighborAnalysis::Init(0, a2, a3);
      NeighborAnalysis::InitOld(v21, v19, this);
      CTiling::SetNormalTileId(v20, 0);
      v8 = CTiles::TileEx((int)v21);
      CTile::ChangeSize((CTile *)v8, -1);
      v9 = CTiles::TileEx((int)v21);
      if ( CTile::EcoSectorId((CTile *)v9) )
      {
        v10 = CTiles::TileEx((int)v21);
        v11 = CTile::EcoSectorId((CTile *)v10);
        CTiling::NotifyChangeEcoSector(v20, v11, 0, 1);
      }
      if ( dword_4502118 )
      {
        CTiling::NRemoveElementFromTile();
      }
      else
      {
        CTiling::NCheckEcoSectorDelete();
        CTilesAndLinks::DeleteTile((int *)v21);
      }
      if ( dword_45020DC >= 3 )
      {
        CTiling::NUpdateLinksAndCheckTileSpliting();
        if ( v19 )
          CTiling::NCheckEcoSectorSplit(v19);
      }
      CTiling::NCalcNewTileId(v18);
      if ( dword_4502128 )
      {
        v12 = CTiles::TileEx(dword_4502124);
        CTile::SetSectorId((CTile *)v12, v17);
        CTiling::NCheckEcoSectorJoin(a4);
      }
      else
      {
        if ( a4 )
        {
          v13 = CTiles::TileEx(dword_4502124);
          v14 = CTile::EcoSectorId((CTile *)v13);
          CTiling::NotifyChangeEcoSector(v20, 0, v14, 1);
        }
        CTiling::NCheckTileMerge();
      }
      CTiling::DbgCheckTileLinkList(dword_4502124, -1);
      NeighborAnalysis::Done(v16);
      CTiling::CalculateBorderstoneBits7(a2, a3);
      CTiling::BlockedLandSurroundingCheck(a2, a3);
      (*(void (__thiscall **)(void *, unsigned int, unsigned int, int))(*(_DWORD *)g_pFogging + 28))(
        g_pFogging,
        a2,
        a3,
        a4);
      CProfile::End((CProfile *)&unk_42F7B00);
      byte_42CF998 = 0;
    }
  }
}


// address=[0x15eda70]
// Decompiled from void __thiscall CTiling::SetBlockingEx(void *this, int a2, unsigned int a3, unsigned int a4)
void  CTiling::SetBlockingEx(enum T_TILING_TYPE,int,int) {
  
  CTile *v4; // eax
  __int16 v5; // ax
  int **v6; // eax
  int **v7; // eax
  NeighborAnalysis *v9; // [esp+0h] [ebp-14h]
  int v10; // [esp+4h] [ebp-10h]
  int v11; // [esp+8h] [ebp-Ch]
  int v12; // [esp+Ch] [ebp-8h]
  NeighborAnalysis *v13; // [esp+10h] [ebp-4h]

  if ( !CTilingWorld::WorldInWorld(a3, a4)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4200, "WorldInWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  v11 = CTilingWorld::WorldIndex(a3, a4);
  v13 = (NeighborAnalysis *)CTiling::TileId(a2, v11);
  if ( CTiles::IsValidRealTile(v13) )
  {
    if ( !CTilingWorld::WorldInInnerWorld1(a3, a4)
      && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4210, "WorldInInnerWorld1(_iX, _iY)") == 1 )
    {
      __debugbreak();
    }
    if ( !CTiles::IsValidRealTile(v13)
      && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4211, "IsValidRealTile(iOldTileId)") == 1 )
    {
      __debugbreak();
    }
    v4 = (CTile *)ITiling::Tile((int)v13);
    v12 = CTile::OwnerId(v4);
    if ( a2
      && v12
      && BBSupportDbgReport(
           2,
           "Pathing\\Tiling.cpp",
           4215,
           "(_tTilingType == TILING_TYPE_NORMAL) || (iOldOwnerId == 0)") == 1 )
    {
      __debugbreak();
    }
    NeighborAnalysis::Init(a2, a3, a4);
    NeighborAnalysis::InitOld(v13, v12, this);
    v5 = ITiling::OwnerPseudoTileId(v12);
    CTiling::SetTileId(a2, v11, v5);
    v6 = CTiles::TileEx((int)v13);
    CTile::ChangeSize((CTile *)v6, -1);
    if ( v12 )
    {
      if ( !CTilingWorld::WorldInWorld(a3, a4)
        && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4232, "WorldInWorld(_iX, _iY)") == 1 )
      {
        __debugbreak();
      }
      if ( v11 != CTilingWorld::WorldIndex(a3, a4)
        && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4233, "iWorldIdx == WorldIndex(_iX, _iY)") == 1 )
      {
        __debugbreak();
      }
      v7 = CTiles::TileEx((int)v13);
      v10 = CTile::EcoSectorId((CTile *)v7);
      CTiling::NotifyChangeEcoSector(v11, v10, 0, 1);
    }
    if ( dword_4502118 )
    {
      CTiling::NRemoveElementFromTile();
    }
    else
    {
      CTiling::NCheckSectorAndEcoSectorDelete();
      CTilesAndLinks::DeleteTile((int *)v13);
    }
    if ( dword_45020DC >= 3 )
    {
      CTiling::NUpdateLinksAndCheckTileSpliting();
      CTiling::NCheckSectorSplit();
      if ( v12 )
        CTiling::NCheckEcoSectorSplit(v12);
    }
    NeighborAnalysis::Done(v9);
  }
}


// address=[0x15edcf0]
// Decompiled from void __thiscall CTiling::ClearBlockingEx(NeighborAnalysis *this, int a2, unsigned int a3, unsigned int a4)
void  CTiling::ClearBlockingEx(enum T_TILING_TYPE,int,int) {
  
  int v4; // eax
  int **v5; // eax
  int v6; // eax
  DWORD v8; // [esp+4h] [ebp-10h]
  unsigned int v9; // [esp+8h] [ebp-Ch]
  int v10; // [esp+Ch] [ebp-8h]

  if ( !CTilingWorld::WorldInWorld(a3, a4)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4422, "WorldInWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  v10 = CTilingWorld::WorldIndex(a3, a4);
  v9 = CTiling::TileId(a2, v10);
  if ( CTiles::IsValidPseudoTile(v9) )
  {
    if ( !CTilingWorld::WorldInInnerWorld1(a3, a4)
      && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4434, "WorldInInnerWorld1(_iX, _iY)") == 1 )
    {
      __debugbreak();
    }
    if ( v9 > 8
      && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4438, "(iOwnerId >= 0) && (iOwnerId <= TILES_OWNER_LAST)") == 1 )
    {
      __debugbreak();
    }
    if ( a2
      && v9
      && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4439, "(_tTilingType == TILING_TYPE_NORMAL) || (iOwnerId == 0)") == 1 )
    {
      __debugbreak();
    }
    NeighborAnalysis::Init(a2, a3, a4);
    if ( a2 )
    {
      v8 = CSquare::TileTypeXY(a3, a4) | 0x8000000;
    }
    else
    {
      v4 = CTilingWorld::WorldGroundType(v10);
      v8 = CTiling::TileType(v9, v4, a3, a4);
    }
    CTiling::NCalcNewTileId(v8);
    if ( dword_4502128 )
    {
      CTiling::NCheckSectorJoin();
      if ( v9 )
        CTiling::NCheckEcoSectorJoin(v9);
    }
    else
    {
      if ( v9 )
      {
        v5 = CTiles::TileEx(dword_4502124);
        v6 = CTile::EcoSectorId((CTile *)v5);
        CTiling::NotifyChangeEcoSector(v10, 0, v6, 1);
      }
      CTiling::NCheckTileMerge();
    }
    NeighborAnalysis::Done(this);
  }
}


// address=[0x15eded0]
// Decompiled from int __thiscall CTiling::SectorSize(CTiling *this, int a2)
int  CTiling::SectorSize(int)const {
  
  int v3; // [esp+4h] [ebp-4h]

  if ( a2 < 0 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4742, "_iSectorId >= 0") == 1 )
    __debugbreak();
  if ( a2 >= 0x8000 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4743, "_iSectorId < SECTORS_MAX") == 1 )
    __debugbreak();
  v3 = CSectors::SectorSize((CSectors *)&CTiling::m_cSectors, a2);
  if ( v3 < 0 )
    return 0;
  return v3;
}


// address=[0x15edf50]
// Decompiled from int __thiscall CTiling::EcoSectorSize(CTiling *this, int a2)
int  CTiling::EcoSectorSize(int)const {
  
  if ( a2 < 0 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4762, "_iEcoSectorId >= 0") == 1 )
    __debugbreak();
  if ( a2 >= 0x4000 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4763, "_iEcoSectorId < TILING_ECO_SECTOR_MAX") == 1 )
    __debugbreak();
  if ( (unsigned int)a2 >= 0x4000 )
    return 0;
  if ( CTiling::m_iEcoSectorSizes[a2] < 0 )
    return 0;
  else
    return CTiling::m_iEcoSectorSizes[a2];
}


// address=[0x15edff0]
// Decompiled from int __thiscall CTiling::EcoSectorPackedPosition(CTiling *this, int a2)
int  CTiling::EcoSectorPackedPosition(int)const {
  
  int v2; // eax
  int v3; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // [esp-4h] [ebp-2Ch]
  int v10; // [esp-4h] [ebp-2Ch]
  int v11; // [esp-4h] [ebp-2Ch]
  int UsedTileId; // [esp+4h] [ebp-24h]
  int v14; // [esp+8h] [ebp-20h]
  int v15; // [esp+Ch] [ebp-1Ch]
  int v16; // [esp+10h] [ebp-18h]
  int **v17; // [esp+14h] [ebp-14h]
  int **v18; // [esp+18h] [ebp-10h]
  int **v19; // [esp+1Ch] [ebp-Ch]
  int j; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]

  if ( (unsigned int)(a2 - 1) >= 0x3FFF || CTiling::m_iEcoSectorSizes[a2] <= 0 )
    return 0;
  v14 = (unsigned __int16)CTiling::m_uEcoSectorAnyTileIds[a2];
  if ( !CTiles::IsValidRealTile(v14)
    || (v19 = CTiles::TileEx(v14), !CTile::Used((CTile *)v19))
    || CTile::EcoSectorId((CTile *)v19) != a2 )
  {
    UsedTileId = CTilesEx::LastUsedTileId(this);
    if ( CTiling::m_iEcoSectorTileIdIterator < 10 || CTiling::m_iEcoSectorTileIdIterator > UsedTileId )
      CTiling::m_iEcoSectorTileIdIterator = 10;
    for ( i = CTiling::m_iEcoSectorTileIdIterator; i <= UsedTileId; ++i )
    {
      v18 = CTiles::TileEx(i);
      if ( CTile::Used((CTile *)v18) )
      {
        v16 = CTile::EcoSectorId((CTile *)v18);
        if ( v16 > 0 )
        {
          if ( v16 >= 0x4000
            && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4820, "iTileEcoSectorId < TILING_ECO_SECTOR_MAX") == 1 )
          {
            __debugbreak();
          }
          CTiling::m_uEcoSectorAnyTileIds[v16] = i;
          if ( v16 == a2 )
          {
            CTiling::m_iEcoSectorTileIdIterator = i;
            v10 = CTile::CenterY((CTile *)v18);
            v5 = CTile::CenterX((CTile *)v18);
            v6 = CTilingWorld::WorldIndex(v5, v10);
            if ( ITiling::EcoSectorId(v6) != a2
              && BBSupportDbgReport(
                   2,
                   "Pathing\\Tiling.cpp",
                   4828,
                   "EcoSectorId(WorldIndex(rTile.CenterX(), rTile.CenterY())) == _iEcoSectorId") == 1 )
            {
              __debugbreak();
            }
            return CTile::CenterXY(v18);
          }
        }
      }
    }
    for ( j = 10; j <= CTiling::m_iEcoSectorTileIdIterator; ++j )
    {
      v17 = CTiles::TileEx(j);
      if ( CTile::Used((CTile *)v17) )
      {
        v15 = CTile::EcoSectorId((CTile *)v17);
        if ( v15 > 0 )
        {
          if ( v15 >= 0x4000
            && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 4848, "iTileEcoSectorId < TILING_ECO_SECTOR_MAX") == 1 )
          {
            __debugbreak();
          }
          CTiling::m_uEcoSectorAnyTileIds[v15] = j;
          if ( v15 == a2 )
          {
            CTiling::m_iEcoSectorTileIdIterator = j;
            v11 = CTile::CenterY((CTile *)v17);
            v7 = CTile::CenterX((CTile *)v17);
            v8 = CTilingWorld::WorldIndex(v7, v11);
            if ( ITiling::EcoSectorId(v8) != a2
              && BBSupportDbgReport(
                   2,
                   "Pathing\\Tiling.cpp",
                   4856,
                   "EcoSectorId(WorldIndex(rTile.CenterX(), rTile.CenterY())) == _iEcoSectorId") == 1 )
            {
              __debugbreak();
            }
            return CTile::CenterXY(v17);
          }
        }
      }
    }
    CTiling::m_iEcoSectorTileIdIterator = 10;
    if ( BBSupportDbgReportF(
           1,
           "Pathing\\Tiling.cpp",
           4867,
           "CTiling::EcoSectorPackedPosition(): Eco-sector %i size > 0, but no tile found!",
           a2) == 1 )
      __debugbreak();
    return 0;
  }
  v9 = CTile::CenterY((CTile *)v19);
  v2 = CTile::CenterX((CTile *)v19);
  v3 = CTilingWorld::WorldIndex(v2, v9);
  if ( ITiling::EcoSectorId(v3) != a2
    && BBSupportDbgReport(
         2,
         "Pathing\\Tiling.cpp",
         4796,
         "EcoSectorId(WorldIndex(rCurrentTile.CenterX(), rCurrentTile.CenterY())) == _iEcoSectorId") == 1 )
  {
    __debugbreak();
  }
  return CTile::CenterXY(v19);
}


// address=[0x15ee310]
// Decompiled from int __thiscall CTiling::NumberOfWorldElements(CTiling *this)
int  CTiling::NumberOfWorldElements(void)const {
  
  int v3; // [esp+8h] [ebp-4h]

  v3 = CTilingWorld::WorldNumberOfElements();
  if ( v3 <= 0 )
    return 1;
  else
    return v3;
}


// address=[0x15ee340]
// Decompiled from int __thiscall CTiling::NumberOfLandElements(CTiling *this)
int  CTiling::NumberOfLandElements(void)const {
  
  return CTilingWorld::WorldNumberOfElements() - CTiling::m_iNumberOfWaterElements;
}


// address=[0x15ee360]
// Decompiled from int __thiscall CTiling::NumberOfWaterElements(CTiling *this)
int  CTiling::NumberOfWaterElements(void)const {
  
  return CTiling::m_iNumberOfWaterElements;
}


// address=[0x15ee370]
// Decompiled from int __thiscall CTiling::NumberOfOwnedLandElements(CTiling *this, unsigned int a2)
int  CTiling::NumberOfOwnedLandElements(int)const {
  
  if ( a2 >= 9 )
    return 0;
  else
    return CTiling::m_iNumberOfOwnedElements[a2];
}


// address=[0x15ee3a0]
// Decompiled from char __thiscall CTiling::AreNeighborSquaresConnectedViaLand(CTiling *this, int a2, int a3, int a4, int a5)
bool  CTiling::AreNeighborSquaresConnectedViaLand(int,int,int,int) {
  
  int j; // eax
  unsigned __int16 *v6; // eax
  CTiling *v8; // [esp+0h] [ebp-34h]
  int v9; // [esp+8h] [ebp-2Ch]
  Squares *v10; // [esp+Ch] [ebp-28h]
  Squares *v11; // [esp+10h] [ebp-24h]
  unsigned __int8 *v12; // [esp+20h] [ebp-14h]
  int i; // [esp+24h] [ebp-10h]
  struct CTile *v14; // [esp+28h] [ebp-Ch]
  CTile *v15; // [esp+2Ch] [ebp-8h]
  int v16; // [esp+30h] [ebp-4h]

  v8 = this;
  for ( i = ITiling::FirstTileOfSquareVW(a2, a3); i; i = CTile::NextSquareTile(v14) )
  {
    v14 = (struct CTile *)ITiling::Tile(i);
    if ( (CTile::Type(v14, (int)v8) & 0x10000000) != 0 )
    {
      v12 = (unsigned __int8 *)CTile::LinkList(v14);
      v16 = 0;
      for ( j = CLinkList::Size(v12); v16 < j; j = CLinkList::Size(v12) )
      {
        v6 = (unsigned __int16 *)CLinkList::operator[](v12, v16);
        v15 = (CTile *)ITiling::Tile(*v6);
        if ( (CTile::Type(v15, (int)v8) & 0x10000000) != 0 )
        {
          v11 = (Squares *)CTile::CenterX(v15);
          v10 = (Squares *)CTile::CenterY(v15);
          v9 = Squares::XYToVW(v11);
          if ( Squares::XYToVW(v10) == a5 && v9 == a4 )
            return 1;
        }
        ++v16;
      }
    }
  }
  return 0;
}


// address=[0x15ee4e0]
// Decompiled from char __thiscall CTiling::CheckFlagBits(  CTiling *this,  unsigned int a2,  unsigned int a3,  unsigned int a4,  const unsigned int *a5,  unsigned int a6)
bool  CTiling::CheckFlagBits(int,int,unsigned int,unsigned int const *,unsigned int) {
  
  unsigned int v6; // ecx
  const unsigned int *v7; // esi
  _DWORD *v8; // edi
  unsigned __int16 v9; // ax
  int v10; // edx
  unsigned int v11; // ebx
  unsigned int v12; // ebx
  unsigned int v13; // ebx
  unsigned int v14; // ebx
  unsigned int v15; // ebx
  unsigned int v16; // ebx
  unsigned int v17; // ebx
  unsigned int v18; // ebx
  int v20; // [esp+10h] [ebp-10h]
  int v21; // [esp+14h] [ebp-Ch]
  char v22; // [esp+1Fh] [ebp-1h]

  if ( !CTilingWorld::WorldInWorld(a2, a3)
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 5019, "WorldInWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( !a4 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 5020, "_uNumberOfLines > 0") == 1 )
    __debugbreak();
  if ( a4 > 0x20 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 5021, "_uNumberOfLines <= 32") == 1 )
    __debugbreak();
  if ( !a5 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 5022, "_pLineCheckMasks != 0") == 1 )
    __debugbreak();
  if ( a6 > 0xFF && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 5023, "_uIllegalFlagBits <= 0xFF") == 1 )
    __debugbreak();
  if ( !a6 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 5024, "_uIllegalFlagBits != 0") == 1 )
    __debugbreak();
  v22 = 0;
  v20 = CTilingWorld::WorldWidthHeight();
  v21 = CTilingWorld::WorldIndex(a2, a3) + CTilingWorld::m_pWorldFlagBitsLayer;
  __asm { pushaw }
  v6 = a4;
  v7 = a5;
  v8 = (_DWORD *)v21;
  LOBYTE(v9) = a6;
  HIBYTE(v9) = a6;
  v10 = v9 | (v9 << 16);
  while ( 1 )
  {
    v11 = *v7;
    if ( *v7 )
    {
      if ( (*v8 & v10 & dword_37E0FE8[v11 >> 28]) != 0 )
        break;
      v12 = 16 * v11;
      if ( v12 )
      {
        if ( (v8[1] & v10 & dword_37E0FE8[v12 >> 28]) != 0 )
          break;
        v13 = 16 * v12;
        if ( v13 )
        {
          if ( (v8[2] & v10 & dword_37E0FE8[v13 >> 28]) != 0 )
            break;
          v14 = 16 * v13;
          if ( v14 )
          {
            if ( (v8[3] & v10 & dword_37E0FE8[v14 >> 28]) != 0 )
              break;
            v15 = 16 * v14;
            if ( v15 )
            {
              if ( (v8[4] & v10 & dword_37E0FE8[v15 >> 28]) != 0 )
                break;
              v16 = 16 * v15;
              if ( v16 )
              {
                if ( (v8[5] & v10 & dword_37E0FE8[v16 >> 28]) != 0 )
                  break;
                v17 = 16 * v16;
                if ( v17 )
                {
                  if ( (v8[6] & v10 & dword_37E0FE8[v17 >> 28]) != 0 )
                    break;
                  v18 = 16 * v17;
                  if ( v18 )
                  {
                    if ( (v8[7] & v10 & dword_37E0FE8[v18 >> 28]) != 0 )
                      break;
                  }
                }
              }
            }
          }
        }
      }
    }
    ++v7;
    v8 = (_DWORD *)((char *)v8 + v20);
    if ( !--v6 )
    {
      v22 = 1;
      break;
    }
  }
  __asm { popaw }
  return v22;
}


// address=[0x15ee720]
// Decompiled from int __cdecl CTiling::DbgCheckTileLinkList(int a1, int a2)
static int __cdecl CTiling::DbgCheckTileLinkList(int,int) {
  
  const struct CTile *v2; // eax
  struct CTile *v3; // eax
  int v4; // eax
  int **v5; // eax
  int **v6; // eax
  int v8; // [esp-4h] [ebp-14Ch]
  int v9; // [esp+0h] [ebp-148h]
  unsigned int v10; // [esp+0h] [ebp-148h]
  int v11; // [esp+8h] [ebp-140h]
  int v12; // [esp+Ch] [ebp-13Ch]
  int **v13; // [esp+10h] [ebp-138h]
  CLinkList *v14; // [esp+14h] [ebp-134h]
  int v15; // [esp+18h] [ebp-130h]
  int j; // [esp+1Ch] [ebp-12Ch]
  int v17; // [esp+20h] [ebp-128h]
  int i; // [esp+24h] [ebp-124h]
  int v19; // [esp+28h] [ebp-120h]
  int v20; // [esp+2Ch] [ebp-11Ch]
  void *v21; // [esp+30h] [ebp-118h]
  int v22; // [esp+34h] [ebp-114h]
  int v23; // [esp+38h] [ebp-110h]
  char v24; // [esp+3Fh] [ebp-109h]
  int v25; // [esp+40h] [ebp-108h]
  _BYTE v26[256]; // [esp+44h] [ebp-104h] BYREF

  v25 = 0;
  if ( !CTilesEx::IsUsedRealTile(a1) )
    return v25;
  v13 = CTiles::TileEx(a1);
  v14 = (CLinkList *)CTile::LinkList(v13);
  v15 = CTile::Type(v13, v9);
  v20 = 0;
  v19 = 0;
  v21 = (void *)(v15 & 0x3C000000);
  if ( (v15 & 0x3C000000u) > 0x10000000 )
  {
    if ( v21 != (void *)0x20000000 )
      goto LABEL_13;
    v20 = 0x8000000;
    v19 = 402653184;
  }
  else if ( v21 == (void *)0x10000000 )
  {
    v20 = 0x8000000;
    v19 = 671088640;
  }
  else if ( v21 == &unk_4000000 )
  {
    v20 = 0x8000000;
    v19 = 0x8000000;
  }
  else
  {
    if ( v21 != (void *)0x8000000 )
    {
LABEL_13:
      BBSupportTracePrintF(0, "  DbgCheckTileLinkList(): Tile %i has an invalid tile type %0x08!", a1, v15);
      goto LABEL_14;
    }
    v20 = 872415232;
    v19 = 872415232;
  }
LABEL_14:
  CIntLinkList::CIntLinkList((CIntLinkList *)v26, 0);
  v2 = ITiling::Tile(a1);
  v8 = CTile::CenterXY(v2);
  v3 = (struct CTile *)ITiling::Tile(a1);
  v4 = CTile::TilingType(v3);
  CTiling::CalcIntLinkList(v26, v4, v8);
  v12 = CIntLinkList::Size((CIntLinkList *)v26);
  for ( i = 0; i < v12; ++i )
  {
    v17 = *(_DWORD *)CIntLinkList::operator[](v26, i);
    v24 = CLinkList::SearchForLinkTileId(v14, v17);
    if ( v17 == a2 )
    {
      if ( v24 )
      {
        ++v25;
        BBSupportTracePrintF(
          0,
          "  DbgCheckTileLinkList(): Link to tile %i should not be in link list of tile %i!",
          v17,
          a1);
      }
    }
    else if ( !v24 )
    {
      ++v25;
      BBSupportTracePrintF(0, "  DbgCheckTileLinkList(): Link to tile %i not in link list of tile %i!", v17, a1);
    }
  }
  v10 = v15 & 0xFFC01FFF;
  v11 = CLinkList::Size((unsigned __int8 *)v14);
  for ( j = 0; j < v11; ++j )
  {
    v23 = *(unsigned __int16 *)CLinkList::operator[](v14, j);
    if ( CTiles::IsValidRealTile(v23) )
    {
      v5 = CTiles::TileEx(v23);
      if ( CTile::Used((CTile *)v5) )
      {
        v6 = CTiles::TileEx(v23);
        v22 = CTile::Type(v6, v10);
        if ( (v22 & 0x3C000000) != 0 )
        {
          if ( (v22 & 0xFFC01FFF) == v10 )
          {
            ++v25;
            BBSupportTracePrintF(
              0,
              "DbgCheckTileLinkList(): Tile %i in link list of tile %i has the same tile type!",
              v23,
              a1);
          }
          if ( (v20 & v22) != 0 )
          {
            ++v25;
            BBSupportTracePrintF(
              0,
              "DbgCheckTileLinkList(): Tile %i in link list of tile %i has an invalid tile type 0x%08x!",
              v23,
              a1,
              v22);
          }
          else if ( (v19 & v22) != 0 )
          {
            ++v25;
            BBSupportTracePrintF(
              0,
              "DbgCheckTileLinkList(): Tile %i in link list of tile %i has an weird tile type 0x%08x!",
              v23,
              a1,
              v22);
          }
        }
        else
        {
          ++v25;
          BBSupportTracePrintF(
            0,
            "DbgCheckTileLinkList(): Tile %i in link list of tile %i has an invalid tile type 0x%08x!",
            v23,
            a1,
            v22);
        }
      }
      else
      {
        ++v25;
        BBSupportTracePrintF(0, "  DbgCheckTileLinkList(): Link to unused tile %i in link list of tile %i!", v23, a1);
      }
    }
    else
    {
      ++v25;
      BBSupportTracePrintF(
        0,
        "  DbgCheckTileLinkList(): Tile %i in link list of tile %i is not a valid real tile!",
        v23,
        a1);
    }
    if ( !CIntLinkList::SearchBackwards((CIntLinkList *)v26, v23) )
    {
      ++v25;
      BBSupportTracePrintF(0, "  DbgCheckTileLinkList(): Invalid link to tile %i in link list of tile %i!", v23, a1);
    }
  }
  return v25;
}


// address=[0x15eec10]
// Decompiled from char __cdecl CTiling::DbgCheckTileLink(int a1, int a2)
static bool __cdecl CTiling::DbgCheckTileLink(int,int) {
  
  const struct CTile *v2; // eax
  struct CTile *v3; // eax
  int v4; // eax
  int v6; // [esp-4h] [ebp-108h]
  _BYTE v7[256]; // [esp+0h] [ebp-104h] BYREF

  CIntLinkList::CIntLinkList((CIntLinkList *)v7, 0);
  v2 = ITiling::Tile(a1);
  v6 = CTile::CenterXY(v2);
  v3 = (struct CTile *)ITiling::Tile(a1);
  v4 = CTile::TilingType(v3);
  CTiling::CalcIntLinkList(v7, v4, v6);
  return CIntLinkList::SearchBackwards((CIntLinkList *)v7, a2);
}


// address=[0x15eec90]
// Decompiled from void __thiscall CTiling::DbgPrintTilingInfo(CTiling *this, int a2)
void  CTiling::DbgPrintTilingInfo(int) {
  
  ;
}


// address=[0x15eeca0]
// Decompiled from int __thiscall CTiling::DbgCheckTiling(CTiling *this, char a2)
int  CTiling::DbgCheckTiling(int) {
  
  int v2; // eax
  int **v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  char *v13; // eax
  char *v14; // eax
  unsigned __int16 *v15; // eax
  int v16; // eax
  int UsedTileId; // eax
  int **v18; // eax
  int **v19; // eax
  int **v20; // eax
  int **v21; // eax
  int v22; // eax
  int v23; // ecx
  CLink *v24; // eax
  CLink *v25; // eax
  CLink *v26; // eax
  CLink *v27; // eax
  CLinkList *v28; // eax
  CLinkList *v29; // eax
  const struct CLinkList *v30; // eax
  CLink *v31; // eax
  CLink *v32; // eax
  int v34; // [esp+0h] [ebp-310A0h]
  int v35; // [esp+8h] [ebp-31098h]
  CTiling *v36; // [esp+Ch] [ebp-31094h]
  int v37; // [esp+14h] [ebp-3108Ch]
  __int64 v38; // [esp+1Ch] [ebp-31084h]
  int v39; // [esp+24h] [ebp-3107Ch]
  int v40; // [esp+2Ch] [ebp-31074h]
  int v41; // [esp+30h] [ebp-31070h]
  int v42; // [esp+34h] [ebp-3106Ch]
  int v43; // [esp+38h] [ebp-31068h]
  int v44; // [esp+3Ch] [ebp-31064h]
  int v45; // [esp+40h] [ebp-31060h]
  int m; // [esp+44h] [ebp-3105Ch]
  int v47; // [esp+48h] [ebp-31058h]
  int v48; // [esp+4Ch] [ebp-31054h]
  unsigned int v49; // [esp+50h] [ebp-31050h]
  int v50; // [esp+54h] [ebp-3104Ch]
  int ii; // [esp+58h] [ebp-31048h]
  int n; // [esp+5Ch] [ebp-31044h]
  CTile *v53; // [esp+60h] [ebp-31040h]
  int v54; // [esp+64h] [ebp-3103Ch]
  int v55; // [esp+68h] [ebp-31038h]
  int jj; // [esp+6Ch] [ebp-31034h]
  CLinkList *v57; // [esp+70h] [ebp-31030h]
  int v58; // [esp+74h] [ebp-3102Ch]
  const struct CLinkList *v59; // [esp+78h] [ebp-31028h]
  bool v60; // [esp+7Eh] [ebp-31022h]
  bool v61; // [esp+7Fh] [ebp-31021h]
  int j; // [esp+80h] [ebp-31020h]
  int i; // [esp+84h] [ebp-3101Ch]
  int kk; // [esp+88h] [ebp-31018h]
  int Free; // [esp+8Ch] [ebp-31014h]
  bool IsBlockedWater; // [esp+93h] [ebp-3100Dh]
  int k; // [esp+94h] [ebp-3100Ch]
  int v68; // [esp+98h] [ebp-31008h]
  _BYTE v69[32768]; // [esp+9Ch] [ebp-31004h] BYREF
  _BYTE v70[4096]; // [esp+809Ch] [ebp-29004h] BYREF
  _BYTE v71[32768]; // [esp+909Ch] [ebp-28004h] BYREF
  _DWORD v72[32768]; // [esp+1109Ch] [ebp-20004h] BYREF

  v36 = this;
  BBSupportTracePrintF(1, "CTiling::DbgCheckTiling()...");
  v68 = 0;
  v48 = 0;
  v41 = 9;
  v37 = 1;
  BB::ZeroMemPtr(v72, 0x20000u);
  TBitArray<262144>::ClearArray(v71);
  TBitArray<262144>::ClearArray(v69);
  v40 = CTilingWorld::WorldWidthHeight();
  for ( i = 0; i < v40; ++i )
  {
    for ( j = 0; j < v40; ++j )
    {
      v2 = CTilingWorld::WorldIndex(j, i);
      v58 = ITiling::NormalTileId(v2);
      if ( CTiles::IsValidTileId(v58 < 0) )
      {
        v3 = CTiles::TileEx(v58);
        if ( CTile::Used((CTile *)v3) )
        {
          v4 = CTilingWorld::WorldIndex(j, i);
          if ( CTilingWorld::WorldIsWater(v4) )
          {
            v5 = CTilingWorld::WorldIndex(j, i);
            IsBlockedWater = CWaterFlags::IsBlockedWater(v5);
            v6 = CTilingWorld::WorldIndex(j, i);
            if ( (CWaterFlags::WaterFlags(v6) & 0x400) != 0 )
              IsBlockedWater = 0;
          }
          else
          {
            v7 = CTilingWorld::WorldIndex(j, i);
            IsBlockedWater = CTilingWorld::WorldIsBlockedLand(v7);
          }
          if ( IsBlockedWater )
          {
            if ( !CTiles::IsValidPseudoTile(v58) )
            {
              ++v68;
              BBSupportTracePrintF(1, "  Blocked Element (%i, %i) has none pseudo tile id %i!", j, i, v58);
            }
          }
          else if ( !CTiles::IsValidRealTile(v58) )
          {
            ++v68;
            BBSupportTracePrintF(1, "  Free Element (%i, %i) has invalid tile id %i!", j, i, v58);
          }
          ++v72[v58];
        }
        else
        {
          ++v68;
          BBSupportTracePrintF(1, "  Element (%i, %i) has an unused tile id %i!", j, i, v58);
        }
      }
      else
      {
        ++v68;
        BBSupportTracePrintF(1, "  Element (%i, %i) has invalid tile id %i!", j, i, v58);
      }
      v8 = CTilingWorld::WorldIndex(j, i);
      v42 = ITiling::CatapultTileId(v8);
      if ( CTiles::IsValidRealTile(v42) )
        ++v72[v42];
    }
  }
  for ( k = 10; k <= 32766; ++k )
  {
    v53 = (CTile *)CTiles::TileEx(k);
    if ( CTile::Used(v53) )
    {
      ++v48;
      v41 = k;
      if ( v72[k] )
      {
        if ( (CTile::Type(v53, (int)v36) & 0x8000000) == 0 )
        {
          v9 = CTile::CenterXY(v53);
          v10 = CTilingWorld::WorldIndex(v9);
          if ( ITiling::NormalTileId(v10) == k )
          {
            v68 += CTiling::DbgCheckTileLinkList(k, -1);
          }
          else
          {
            ++v68;
            BBSupportTracePrintF(1, "  Center of tile %i belongs not to tile!", k);
          }
        }
      }
      else
      {
        ++v68;
        BBSupportTracePrintF(1, "  Tile %i has zero elements!", k);
      }
      v59 = (const struct CLinkList *)CTile::LinkList(v53);
      v57 = (CLinkList *)CTile::LinkList(v53);
      if ( (unsigned __int8)CLinks::IsValidUsedLinkList(v57) )
      {
        v39 = CLinks::LinksId(v59);
        TBitArray<262144>::Set(v39);
        if ( CLinkList::Marker(v57) == 253 )
        {
          if ( CLinkList::Size((unsigned __int8 *)v59) <= 62 )
          {
            for ( m = 0; m < CLinkList::Size((unsigned __int8 *)v59) + 2; ++m )
              TBitArray<262144>::Set(m + v39);
            if ( CLinkList::OwnerTileId(v59) != k )
            {
              ++v68;
              v11 = CLinkList::OwnerTileId(v59);
              BBSupportTracePrintF(1, "  Tile %i, LinkList 0x%08x: Invalid owner tile id (%i)!", k, v57, v11);
            }
            for ( n = 0; n < CLinkList::Size((unsigned __int8 *)v59); ++n )
            {
              v49 = *(unsigned __int16 *)CLinkList::operator[](v59, n);
              if ( CTiles::IsValidTileId(v49) && v49 )
              {
                if ( !CTilesEx::IsUsedRealTile(v49) )
                {
                  ++v68;
                  BBSupportTracePrintF(
                    1,
                    "  Tile %i, LinkList 0x%08x.%i: Not a used real tile id (%i)!",
                    k,
                    v57,
                    n,
                    v49);
                }
              }
              else
              {
                ++v68;
                v12 = CTile::Type(v53, (int)v57);
                BBSupportTracePrintF(
                  1,
                  "  Tile %i (%08x), LinkList 0x%08x.%i: Invalid link tile id (%i)!",
                  k,
                  v12,
                  v34,
                  n,
                  v49);
              }
            }
            v55 = CLinkList::Size((unsigned __int8 *)v59);
            if ( (v55 & 1) != 0 )
            {
              v13 = CLinkList::Link(v59, v55);
              if ( !CLink::Unused((CLink *)v13) )
              {
                ++v68;
                BBSupportTracePrintF(1, "  Tile %i, LinkList 0x%08x.%i: Not marked as free!", k, v57, v55);
              }
              ++v55;
            }
            v14 = CLinkList::Link(v59, v55);
            if ( !CLink::PrevLinkIsLastOne((CLink *)v14) )
            {
              ++v68;
              v15 = (unsigned __int16 *)CLinkList::operator[](v59, v55);
              BBSupportTracePrintF(1, "  Tile %i, LinkList 0x%08x: Invalid next link tile id (%i)!", k, v57, *v15);
            }
          }
          else
          {
            ++v68;
            BBSupportTracePrintF(1, "  Tile %i, LinkList 0x%08x: Count greater LINK_LIST_MAX (%i)!", k, v57, 62);
          }
        }
        else
        {
          ++v68;
          BBSupportTracePrintF(1, "  Tile %i, LinkList 0x%08x: Invalid first entry marker!", k, v57);
        }
      }
      else
      {
        ++v68;
        BBSupportTracePrintF(1, "  Tile %i, LinkList 0x%08x: Invalid link list!", k, v57);
      }
    }
  }
  v47 = 32757 - v48;
  if ( CTilesEx::NumberOfUsedTiles() != v48 )
  {
    ++v68;
    v16 = CTilesEx::NumberOfUsedTiles();
    BBSupportTracePrintF(1, "  NumberOfUsedTiles() [%i] invalid!", v16);
  }
  if ( CTilesEx::LastUsedTileId(v36) != v41 )
  {
    ++v68;
    UsedTileId = CTilesEx::LastUsedTileId(v41);
    BBSupportTracePrintF(1, "  LastUsedTileId() [%i, should be %i] invalid!", UsedTileId, v35);
  }
  TBitArray<32768>::ClearArray(v70);
  v45 = -1;
  Free = 9;
  while ( Free != 0x7FFF )
  {
    ++v45;
    TBitArray<32768>::Set(Free);
    v50 = Free;
    v18 = CTiles::TileEx(Free);
    Free = CTile::NextFree((CTile *)v18);
    HIDWORD(v38) = Free < 10;
    LODWORD(v38) = Free > 0x7FFF;
    if ( v38 )
    {
      ++v68;
      BBSupportTracePrintF(1, "  Free Tile %i: Invalid next free tile (%i)!", v50, Free);
      break;
    }
    v19 = CTiles::TileEx(Free);
    if ( CTile::Used((CTile *)v19) )
    {
      ++v68;
      BBSupportTracePrintF(1, "  Free Tile %i: Next free tile (%i) is used!", v50, Free);
      break;
    }
    if ( (unsigned __int8)TBitArray<32768>::operator[](Free) )
    {
      ++v68;
      BBSupportTracePrintF(1, "  Free Tile %i: Already visited (endless loop in list of free tiles)!", Free);
      break;
    }
    v20 = CTiles::TileEx(Free);
    if ( CTile::PrevFree((CTile *)v20) != v50 )
    {
      ++v68;
      v21 = CTiles::TileEx(Free);
      v22 = CTile::PrevFree((CTile *)v21);
      BBSupportTracePrintF(1, "  Free Tile %i: Prev free tile (%i) invalid (!= %i)!", Free, v22, v50);
    }
  }
  if ( v45 != v47 )
  {
    ++v68;
    BBSupportTracePrintF(1, "  Invalid number of free tiles (%i, should be %i)!", v45, v47);
    BBSupportTracePrintF(1, "  Rebuilding list of free tiles...");
    CTilesEx::CalculateListOfFreeTiles(v23);
  }
  BBSupportTracePrintF(1, "  Used tiles: %i; free tiles: %i (%.1f%%).", v48, v47, (double)v47 / 32757.0 * 100.0);
  v44 = 0;
  v43 = 0;
  for ( ii = 2; ii <= 262141; ++ii )
  {
    v24 = CLinks::Link(ii);
    v44 += CLink::Used(v24);
    v25 = CLinks::Link(ii);
    v43 += CLink::Unused(v25);
  }
  v54 = 0;
  for ( jj = 2; jj <= 262141; jj += 2 )
  {
    v26 = CLinks::Link(jj);
    v60 = CLink::Unused(v26);
    v27 = CLinks::Link(jj + 1);
    v61 = CLink::Unused(v27);
    if ( v61 && v60 )
      v54 += 2;
    else
      v37 = jj;
    if ( !v61 && v60 )
    {
      ++v68;
      BBSupportTracePrintF(1, "  Link %i is unused, but link %i is not!", jj, jj + 1);
    }
  }
  for ( kk = 2; kk <= 262141; ++kk )
  {
    if ( (unsigned __int8)TBitArray<262144>::operator[](kk) )
    {
      v28 = CLinks::LinkList(kk);
      if ( CLinkList::Marker(v28) != 253 )
      {
        ++v68;
        BBSupportTracePrintF(1, "  Link %i not marked as first entry!", kk);
      }
    }
    else
    {
      v29 = CLinks::LinkList(kk);
      if ( CLinkList::Marker(v29) == 253 )
      {
        ++v68;
        BBSupportTracePrintF(1, "  Link %i marked as first entry!", kk);
        v30 = CLinks::LinkList(kk);
        CTiling::DbgPrintLinkList(v30);
      }
    }
    if ( (unsigned __int8)TBitArray<262144>::operator[](kk) )
    {
      v31 = CLinks::Link(kk);
      if ( !CLink::Used(v31) )
      {
        ++v68;
        BBSupportTracePrintF(1, "  Link %i not used!", kk);
      }
    }
    else
    {
      v32 = CLinks::Link(kk);
      if ( !CLink::Unused(v32) )
      {
        ++v68;
        BBSupportTracePrintF(1, "  Link %i not unused!", kk);
      }
    }
  }
  BBSupportTracePrintF(
    1,
    "  Used links: %i; unusable links: %i; free links: %i (%.1f%%), garbage free links: %i.",
    v44,
    v43 - v54,
    v54,
    (double)v54 / 262140.0 * 100.0,
    v54 - (262140 - v37));
  if ( v68 )
  {
    if ( v68 == 1 )
      BBSupportTracePrintF(1, "  1 error found!!");
    else
      BBSupportTracePrintF(1, "  %i errors found!!", v68);
  }
  else
  {
    BBSupportTracePrintF(1, "  No errors found.");
  }
  if ( (a2 & 1) != 0 )
    v68 += CTiling::DbgCheckSectors(0);
  return v68;
}


// address=[0x15efc00]
// Decompiled from int __thiscall CTiling::DbgReCalculate(CTiling *this, int a2)
void  CTiling::DbgReCalculate(int) {
  
  int v3; // [esp+0h] [ebp-1Ch]
  int v4; // [esp+4h] [ebp-18h]
  int v5; // [esp+8h] [ebp-14h]
  __int16 *v6; // [esp+Ch] [ebp-10h]
  int v7; // [esp+10h] [ebp-Ch]
  int v8; // [esp+14h] [ebp-8h]

  if ( !CTiling::m_iInitialized && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 5645, "m_iInitialized") == 1 )
    __debugbreak();
  CTiling::PrepareReCalculate();
  v3 = CTilingWorld::m_uWorldWidthHeight;
  v4 = CTilingWorld::m_pWorldGfxMapElements;
  v5 = CTilingWorld::m_pWorldFlagBitsLayer;
  v8 = CTilingWorld::m_pWorldFogLayer;
  v6 = ITiling::m_pTileIds;
  v7 = (int)*(&ITiling::m_pTileIds + 1);
  (*(void (__thiscall **)(CTiling *))(*(_DWORD *)this + 4))(this);
  return (**(int (__thiscall ***)(CTiling *, int, int, int, __int16 *, int, int, int))this)(
           this,
           v3,
           v4,
           v5,
           v6,
           v7,
           v8,
           1);
}


// address=[0x15efcc0]
// Decompiled from int __thiscall CTiling::DbgCheckBlocking(CTiling *this, int a2)
void  CTiling::DbgCheckBlocking(int) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int result; // eax
  int v11; // eax
  int v12; // [esp+10h] [ebp-30h]
  int v13; // [esp+14h] [ebp-2Ch]
  int v14; // [esp+18h] [ebp-28h]
  int v15; // [esp+1Ch] [ebp-24h]
  int v16; // [esp+20h] [ebp-20h]
  int v17; // [esp+24h] [ebp-1Ch]
  int n; // [esp+28h] [ebp-18h]
  int m; // [esp+2Ch] [ebp-14h]
  int k; // [esp+30h] [ebp-10h]
  int j; // [esp+34h] [ebp-Ch]
  int i; // [esp+38h] [ebp-8h]
  int v23; // [esp+3Ch] [ebp-4h]

  v23 = CTilingWorld::WorldWidthHeight();
  BBSupportTracePrintF(0, "CTiling::DbgCheckBlocking()...");
  BBSupportTracePrintF(0, "  Map size is %i x %i.", v23, v23);
  for ( i = 0; i < v23; ++i )
  {
    v2 = CTilingWorld::WorldIndex(i, 0);
    if ( !CTilingWorld::WorldIsWater(v2) )
      BBSupportTracePrintF(0, "  Error: (%4i, %4i) is not water!", i, 0);
    v3 = CTilingWorld::WorldIndex(i, 1);
    if ( !CTilingWorld::WorldIsWater(v3) )
      BBSupportTracePrintF(0, "  Error: (%4i, %4i) is not water!", i, 1);
    v4 = CTilingWorld::WorldIndex(i, v23 - 2);
    if ( !CTilingWorld::WorldIsWater(v4) )
      BBSupportTracePrintF(0, "  Error: (%4i, %4i) is not water!", i, v23 - 2);
    v5 = CTilingWorld::WorldIndex(i, v23 - 1);
    if ( !CTilingWorld::WorldIsWater(v5) )
      BBSupportTracePrintF(0, "  Error: (%4i, %4i) is not water!", i, v23 - 1);
  }
  for ( j = 0; j < v23; ++j )
  {
    v6 = CTilingWorld::WorldIndex(0, j);
    if ( !CTilingWorld::WorldIsWater(v6) )
      BBSupportTracePrintF(0, "  Error: (%4i, %4i) is not water!", 0, j);
    v7 = CTilingWorld::WorldIndex(1, j);
    if ( !CTilingWorld::WorldIsWater(v7) )
      BBSupportTracePrintF(0, "  Error: (%4i, %4i) is not water!", 1, j);
    v8 = CTilingWorld::WorldIndex(v23 - 2, j);
    if ( !CTilingWorld::WorldIsWater(v8) )
      BBSupportTracePrintF(0, "  Error: (%4i, %4i) is not water!", v23 - 2, j);
    v9 = CTilingWorld::WorldIndex(v23 - 1, j);
    if ( !CTilingWorld::WorldIsWater(v9) )
      BBSupportTracePrintF(0, "  Error: (%4i, %4i) is not water!", v23 - 1, j);
  }
  for ( k = 2; ; ++k )
  {
    result = v23 - 2;
    if ( k >= v23 - 2 )
      break;
    for ( m = 2; m < v23 - 2; ++m )
    {
      v13 = CTilingWorld::WorldIndex(m, k);
      if ( CTilingWorld::WorldIsWater(v13) )
      {
        if ( !CTilingWorld::WorldIsBlockedLand(v13) )
          BBSupportTracePrintF(0, "  Error: (%4i, %4i) is water, but not blocked!", m, k);
      }
      else if ( CTilingWorld::WorldIsBlockedLand(v13) )
      {
        v14 = 0;
        v15 = 0;
        v16 = 0;
        for ( n = 0; n < 6; ++n )
        {
          v12 = CTilingWorld::WorldIndex(g_sNeighborPoints[2 * n] + m, dword_37D8C0C[2 * n] + k);
          if ( CTilingWorld::WorldIsBlockedLand(v12) )
          {
            ++v14;
          }
          else if ( CTilingWorld::WorldIsBuildingOrDecoObjectBitSet(v12) )
          {
            ++v15;
          }
          else
          {
            v17 = CTilingWorld::WorldGroundType(v13) & 0xF0;
            if ( v17 != 16 && v17 != 64 && v17 != 144 && v17 != 32 )
              ++v16;
          }
        }
        v11 = v16 + v15 + v14;
        if ( v11 != 6 )
          BBSupportTracePrintF(
            0,
            "  Warning: (%4i, %4i) is blocked, but not all neighbors (%i) are \"reserved\" (%i blocked, %i building / dec"
            "o, %i not possible).",
            m,
            k,
            6 - v11,
            v14,
            v15,
            v16);
      }
    }
  }
  return result;
}


// address=[0x15f00e0]
// Decompiled from int __cdecl CTiling::DbgPrintLinkList(const struct CLinkList *a1)
static void __cdecl CTiling::DbgPrintLinkList(class CLinkList const &) {
  
  unsigned __int16 *v1; // eax
  unsigned __int16 *v2; // eax
  int v3; // eax
  int v5; // [esp-10h] [ebp-2018h]
  int v6; // [esp-Ch] [ebp-2014h]
  int v7; // [esp-8h] [ebp-2010h]
  int i; // [esp+0h] [ebp-2008h]
  char Destination[4096]; // [esp+4h] [ebp-2004h] BYREF
  char Source[4096]; // [esp+1004h] [ebp-1004h] BYREF

  memset(Source, 0, sizeof(Source));
  if ( CLinkList::Size((unsigned __int8 *)a1) > 0 )
  {
    v1 = (unsigned __int16 *)CLinkList::operator[](a1, 0);
    j___snprintf(Source, 0x1000u, ", links: %i", *v1);
    for ( i = 1; i < CLinkList::Size((unsigned __int8 *)a1); ++i )
    {
      j__strncpy(Destination, Source, 0x1000u);
      v2 = (unsigned __int16 *)CLinkList::operator[](a1, i);
      j___snprintf(Source, 0x1000u, "%s, %i", Destination, *v2);
    }
  }
  v7 = CLinkList::OwnerTileId(a1);
  v6 = CLinkList::Size((unsigned __int8 *)a1);
  v5 = CLinkList::Marker(a1);
  v3 = CLinks::LinksId(a1);
  return BBSupportTracePrintF(0, "LinkList 0x%08x (%i): 0x%02x, cnt %i, owner %i%s", a1, v3, v5, v6, v7, Source);
}


// address=[0x15f0220]
// Decompiled from int CTiling::DbgCheckSectors()
static int __cdecl CTiling::DbgCheckSectors(int) {
  
  int v0; // eax
  int **v1; // eax
  int UsedTileId; // [esp+0h] [ebp-40040h]
  struct CTile *v4; // [esp+4h] [ebp-4003Ch]
  int v5; // [esp+8h] [ebp-40038h]
  const char *v6; // [esp+10h] [ebp-40030h]
  int v7; // [esp+14h] [ebp-4002Ch]
  _DWORD *v8; // [esp+1Ch] [ebp-40024h]
  int v9; // [esp+20h] [ebp-40020h]
  int v10; // [esp+24h] [ebp-4001Ch]
  int j; // [esp+28h] [ebp-40018h]
  int i; // [esp+2Ch] [ebp-40014h]
  int v13; // [esp+30h] [ebp-40010h]
  int v14; // [esp+34h] [ebp-4000Ch]
  int k; // [esp+38h] [ebp-40008h]
  _DWORD v16[65536]; // [esp+3Ch] [ebp-40004h] BYREF

  v14 = 0;
  v13 = 0;
  BBSupportTracePrintF(0, "CTiling::DbgCheckSectors()...");
  v9 = CTilingWorld::WorldWidthHeight();
  v7 = v9 * v9;
  j__memset(v16, 0, sizeof(v16));
  for ( i = 0; i < v7; ++i )
  {
    v0 = ITiling::NormalTileId(i);
    v1 = CTiles::TileEx(v0);
    v8 = &v16[CTile::SectorId((CTile *)v1)];
    ++*v8;
  }
  for ( j = 1; j < 0x10000; ++j )
  {
    if ( v16[j] )
      ++v13;
  }
  v5 = v7 - v16[0];
  if ( v13 == 1 )
    v6 = (const char *)&unk_37DDF37;
  else
    v6 = "s";
  if ( v5 == 1 )
    BBSupportTracePrintF(0, "  %i element%s in %i sector%s.", 1, (const char *)&unk_37DDF4E, v13, v6);
  else
    BBSupportTracePrintF(0, "  %i element%s in %i sector%s.", v5, "s", v13, v6);
  v10 = 0;
  TBitArray<32768>::ClearArray(&unk_45010C0);
  UsedTileId = CTilesEx::LastUsedTileId();
  for ( k = 10; k <= UsedTileId; ++k )
  {
    if ( !(unsigned __int8)TBitArray<32768>::operator[](k) )
    {
      v4 = (struct CTile *)ITiling::Tile(k);
      if ( CTile::SectorId(v4) )
      {
        if ( !CTile::TilingType(v4) )
        {
          ++v10;
          CTiling::WalkTilesSectorSetVisited(k);
        }
      }
    }
  }
  if ( v10 != v13 )
  {
    v14 = 1;
    BBSupportTracePrintF(0, "  Number of walks differs!");
  }
  if ( v14 )
    BBSupportTracePrintF(0, "  1 error found!!");
  else
    BBSupportTracePrintF(0, "  No errors found.");
  return v14;
}


// address=[0x15f0520]
// Decompiled from int CTiling::DbgCheckEcoSectors()
static int __cdecl CTiling::DbgCheckEcoSectors(int) {
  
  int v0; // eax
  int **v1; // eax
  int **v2; // eax
  int UsedTileId; // [esp+4h] [ebp-4003Ch]
  int v5; // [esp+8h] [ebp-40038h]
  const char *v6; // [esp+10h] [ebp-40030h]
  int v7; // [esp+14h] [ebp-4002Ch]
  _DWORD *v8; // [esp+18h] [ebp-40028h]
  int v9; // [esp+1Ch] [ebp-40024h]
  int v10; // [esp+20h] [ebp-40020h]
  int i; // [esp+24h] [ebp-4001Ch]
  int v12; // [esp+28h] [ebp-40018h]
  int v13; // [esp+2Ch] [ebp-40014h]
  int k; // [esp+30h] [ebp-40010h]
  int j; // [esp+34h] [ebp-4000Ch]
  int v16; // [esp+38h] [ebp-40008h]
  _DWORD v17[65536]; // [esp+3Ch] [ebp-40004h] BYREF

  v16 = 0;
  v12 = 0;
  BBSupportTracePrintF(0, "CTiling::DbgCheckEcoSectors()...");
  v9 = CTilingWorld::WorldWidthHeight();
  v7 = v9 * v9;
  j__memset(v17, 0, sizeof(v17));
  for ( i = 0; i < v7; ++i )
  {
    v0 = ITiling::NormalTileId(i);
    v1 = CTiles::TileEx(v0);
    v8 = &v17[CTile::EcoSectorId((CTile *)v1)];
    ++*v8;
  }
  for ( j = 1; j < 0x4000; ++j )
  {
    v13 = v17[j];
    if ( v13 )
      ++v12;
    else
      v13 = -1;
    if ( CTiling::m_iEcoSectorSizes[j] != v13 )
    {
      ++v16;
      BBSupportTracePrintF(
        0,
        "  Invalid size for eco-sector %i (size is %i, should be %i)!",
        j,
        CTiling::m_iEcoSectorSizes[j],
        v13);
    }
  }
  v5 = v7 - v17[0];
  if ( v12 == 1 )
    v6 = (const char *)&unk_37DDF4F;
  else
    v6 = "s";
  if ( v5 == 1 )
    BBSupportTracePrintF(0, "  %i element%s in %i eco-sector%s.", 1, (const char *)&unk_37DDF63, v12, v6);
  else
    BBSupportTracePrintF(0, "  %i element%s in %i eco-sector%s.", v5, "s", v12, v6);
  v10 = 0;
  TBitArray<32768>::ClearArray(&unk_45010C0);
  UsedTileId = CTilesEx::LastUsedTileId();
  for ( k = 10; k <= UsedTileId; ++k )
  {
    if ( !(unsigned __int8)TBitArray<32768>::operator[](k) )
    {
      v2 = CTiles::TileEx(k);
      if ( CTile::EcoSectorId((CTile *)v2) )
      {
        ++v10;
        CTiling::WalkTilesEcoSectorSetVisited(k);
      }
    }
  }
  if ( v10 != v12 )
  {
    ++v16;
    BBSupportTracePrintF(0, "  Number of walks differs!");
  }
  if ( v16 )
  {
    if ( v16 == 1 )
      BBSupportTracePrintF(0, "  1 error found!!");
    else
      BBSupportTracePrintF(0, "  %i errors found!!", v16);
  }
  else
  {
    BBSupportTracePrintF(0, "  No errors found.");
  }
  return v16;
}


// address=[0x15f0870]
// Decompiled from int CTiling::DbgCheckTileSizes()
static int __cdecl CTiling::DbgCheckTileSizes(int) {
  
  int v0; // eax
  int UsedTileId; // [esp+0h] [ebp-40024h]
  int v3; // [esp+4h] [ebp-40020h]
  int v4; // [esp+8h] [ebp-4001Ch]
  int v5; // [esp+Ch] [ebp-40018h]
  int **v6; // [esp+10h] [ebp-40014h]
  int v7; // [esp+14h] [ebp-40010h]
  int i; // [esp+18h] [ebp-4000Ch]
  int j; // [esp+1Ch] [ebp-40008h]
  _DWORD v10[65536]; // [esp+20h] [ebp-40004h] BYREF

  v7 = 0;
  BBSupportTracePrintF(0, "CTiling::DbgCheckTileSizes()...");
  j__memset(v10, 0, sizeof(v10));
  v3 = CTilingWorld::WorldNumberOfElements();
  for ( i = 0; i < v3; ++i )
  {
    v5 = ITiling::NormalTileId(i);
    v4 = ITiling::CatapultTileId(i);
    ++v10[v5];
    ++v10[v4];
  }
  UsedTileId = CTilesEx::LastUsedTileId();
  for ( j = 10; j <= UsedTileId; ++j )
  {
    v6 = CTiles::TileEx(j);
    if ( CTile::Used((CTile *)v6) && CTile::Size((CTile *)v6) != v10[j] )
    {
      ++v7;
      v0 = CTile::Size((CTile *)v6);
      BBSupportTracePrintF(0, "  Size of tile %i is wrong (size is %i, Size() returns %i)!", j, v10[j], v0);
    }
  }
  if ( v7 )
    BBSupportTracePrintF(0, "  %i error(s) found!!", v7);
  else
    BBSupportTracePrintF(0, "  No errors found.");
  return v7;
}


// address=[0x15f41e0]
// Decompiled from void __cdecl CTiling::CalcSquarePrepareCatapult(int a1, int a2)
static void __cdecl CTiling::CalcSquarePrepareCatapult(int,int) {
  
  CSquare::InitAndFillTypeMapCatapult((CSquare *)&dword_42F7C50, a1, a2);
}


// address=[0x15f4200]
// Decompiled from void __cdecl CTiling::CalcSquarePrepareNormal(int a1, int a2)
static void __cdecl CTiling::CalcSquarePrepareNormal(int,int) {
  
  CSquare::InitAndFillTypeMapNormal((CSquare *)&dword_42F7C50, a1, a2);
}


// address=[0x15f4390]
// Decompiled from int __cdecl CTiling::EcoSectorSizeEx(int a1)
static int __cdecl CTiling::EcoSectorSizeEx(int) {
  
  int v2; // [esp+0h] [ebp-4h]

  if ( (a1 <= 0 || a1 >= 0x4000)
    && BBSupportDbgReport(
         2,
         "Pathing\\Tiling.cpp",
         274,
         "(_iEcoSectorId > 0) && (_iEcoSectorId < TILING_ECO_SECTOR_MAX)") == 1 )
  {
    __debugbreak();
  }
  v2 = CTiling::m_iEcoSectorSizes[a1];
  if ( v2 <= 0 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 278, "iSize > 0") == 1 )
    __debugbreak();
  return v2;
}


// address=[0x15f4930]
// Decompiled from bool __cdecl CTiling::IsValidOwnerId(unsigned int a1)
static bool __cdecl CTiling::IsValidOwnerId(int) {
  
  return a1 <= 8;
}


// address=[0x15f4a90]
// Decompiled from void __cdecl CTiling::NotifyChangeEcoSector(int a1, int a2, int a3, bool a4)
static void __cdecl CTiling::NotifyChangeEcoSector(int,int,int,bool) {
  
  if ( a2 == a3 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 195, "_iOldEcoSectorId != _iNewEcoSectorId") == 1 )
    __debugbreak();
  if ( ITiling::EcoSectorId(a1) != a3
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 196, "EcoSectorId(_iWorldIdx) == _iNewEcoSectorId") == 1 )
  {
    __debugbreak();
  }
  if ( (a2 >= 0x4000 || a2 < 0)
    && BBSupportDbgReport(
         2,
         "Pathing\\Tiling.cpp",
         198,
         "(_iOldEcoSectorId >= 0) & (_iOldEcoSectorId < TILING_ECO_SECTOR_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 >= 0x4000 || a3 < 0)
    && BBSupportDbgReport(
         2,
         "Pathing\\Tiling.cpp",
         199,
         "(_iNewEcoSectorId >= 0) & (_iNewEcoSectorId < TILING_ECO_SECTOR_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( (unsigned __int16)word_43010C0[a1] != a2
    && BBSupportDbgReport(
         2,
         "Pathing\\Tiling.cpp",
         201,
         "s_uDbgTilingWorldEcoSectorIds[_iWorldIdx] == _iOldEcoSectorId") == 1 )
  {
    __debugbreak();
  }
  if ( a2 )
  {
    if ( --CTiling::m_iEcoSectorSizes[a2] < 0
      && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 207, "m_iEcoSectorSizes[_iOldEcoSectorId] >= 0") == 1 )
    {
      __debugbreak();
    }
  }
  if ( a3 )
    ++CTiling::m_iEcoSectorSizes[a3];
  word_43010C0[a1] = a3;
  if ( a4 )
    CEcoSectorMgr::NotifyChangeEcoSector(g_cESMgr, a1, a2, a3);
}


// address=[0x15f4ce0]
// Decompiled from int CTiling::NotifyCreateCatapultSector()
static int __cdecl CTiling::NotifyCreateCatapultSector(void) {
  
  return CSectors::NewSector((CSectors *)&CTiling::m_cSectors, 8u);
}


// address=[0x15f4d00]
// Decompiled from int __cdecl CTiling::NotifyCreateEcoSector(int a1, bool a2)
static int __cdecl CTiling::NotifyCreateEcoSector(int,bool) {
  
  int EcoSector; // [esp+0h] [ebp-4h]

  if ( a1 <= 0 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 148, "_iOwnerId > 0") == 1 )
    __debugbreak();
  if ( a2 )
    EcoSector = CEcoSectorMgr::NotifyCreateEcoSector((CEcoSectorMgr *)g_cESMgr, a1);
  else
    EcoSector = ++CTiling::m_iInitLastEcoSectorId;
  if ( (EcoSector <= 0 || EcoSector >= 0x4000)
    && BBSupportDbgReport(
         2,
         "Pathing\\Tiling.cpp",
         163,
         "(iNewEcoSectorId > 0) && (iNewEcoSectorId < TILING_ECO_SECTOR_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( CTiling::m_iEcoSectorSizes[EcoSector] != -1
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 164, "m_iEcoSectorSizes[iNewEcoSectorId] == -1") == 1 )
  {
    __debugbreak();
  }
  CTiling::m_iEcoSectorSizes[EcoSector] = 0;
  return EcoSector;
}


// address=[0x15f4e10]
// Decompiled from int CTiling::NotifyCreateSector()
static int __cdecl CTiling::NotifyCreateSector(void) {
  
  return CSectors::NewSector((CSectors *)&CTiling::m_cSectors, 2u);
}


// address=[0x15f4e30]
// Decompiled from void __cdecl CTiling::NotifyDeleteEcoSector(int a1)
static void __cdecl CTiling::NotifyDeleteEcoSector(int) {
  
  if ( a1 <= 0 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 178, (const char *)&dword_366FF60[1]) == 1 )
    __debugbreak();
  if ( a1 >= 0x4000 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 179, "_iEcoSectorId < TILING_ECO_SECTOR_MAX") == 1 )
    __debugbreak();
  if ( CTiling::m_iEcoSectorSizes[a1]
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 181, "m_iEcoSectorSizes[_iEcoSectorId] == 0") == 1 )
  {
    __debugbreak();
  }
  CTiling::m_iEcoSectorSizes[a1] = -1;
  CEcoSectorMgr::NotifyDeleteEcoSector((CEcoSectorMgr *)g_cESMgr, a1);
}


// address=[0x15f4f00]
// Decompiled from CSectors *__cdecl CTiling::NotifyDeleteSector(CSectors *a1)
static void __cdecl CTiling::NotifyDeleteSector(int) {
  
  return CSectors::DeleteSector((CSectors *)&CTiling::m_cSectors, a1);
}


// address=[0x15f4f20]
// Decompiled from CEcoSectorMgr *__cdecl CTiling::NotifyEcoSectorMerge(int a1, int a2)
static void __cdecl CTiling::NotifyEcoSectorMerge(int,int) {
  
  return CEcoSectorMgr::NotifyEcoSectorMerge((CEcoSectorMgr *)g_cESMgr, a1, a2);
}


// address=[0x15f4f40]
// Decompiled from unsigned int __cdecl CTiling::NotifyEcoSectorSplit(signed int a1, signed int a2)
static void __cdecl CTiling::NotifyEcoSectorSplit(int,int) {
  
  if ( (a1 <= 0 || a1 >= 0x4000)
    && BBSupportDbgReport(
         2,
         "Pathing\\Tiling.cpp",
         230,
         "(_iEcoSectorId > 0) && (_iEcoSectorId < TILING_ECO_SECTOR_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( (a2 <= 0 || a2 >= 0x4000)
    && BBSupportDbgReport(
         2,
         "Pathing\\Tiling.cpp",
         231,
         "(_iCreatedEcoSectorId > 0) && (_iCreatedEcoSectorId < TILING_ECO_SECTOR_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( a1 == a2 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 232, "_iEcoSectorId != _iCreatedEcoSectorId") == 1 )
    __debugbreak();
  if ( CTiling::m_iEcoSectorSizes[a1] <= 0
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 234, "m_iEcoSectorSizes[_iEcoSectorId] > 0") == 1 )
  {
    __debugbreak();
  }
  if ( CTiling::m_iEcoSectorSizes[a2] <= 0
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 235, "m_iEcoSectorSizes[_iCreatedEcoSectorId] > 0") == 1 )
  {
    __debugbreak();
  }
  return CEcoSectorMgr::SeparateEconomy((CEcoSectorMgr *)g_cESMgr, a1, a2);
}


// address=[0x15f5080]
// Decompiled from _DWORD *__cdecl CTiling::NotifyEcoSectorsMerged(int a1, int a2)
static void __cdecl CTiling::NotifyEcoSectorsMerged(int,int) {
  
  if ( (a1 <= 0 || a1 >= 0x4000)
    && BBSupportDbgReport(
         2,
         "Pathing\\Tiling.cpp",
         257,
         "(_iEcoSectorId > 0) && (_iEcoSectorId < TILING_ECO_SECTOR_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( (a2 <= 0 || a2 >= 0x4000)
    && BBSupportDbgReport(
         2,
         "Pathing\\Tiling.cpp",
         258,
         "(_iEmptiedEcoSectorId > 0) && (_iEmptiedEcoSectorId < TILING_ECO_SECTOR_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( a1 == a2 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 259, "_iEcoSectorId != _iEmptiedEcoSectorId") == 1 )
    __debugbreak();
  if ( CTiling::m_iEcoSectorSizes[a1] <= 0
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 261, "m_iEcoSectorSizes[_iEcoSectorId] > 0") == 1 )
  {
    __debugbreak();
  }
  if ( CTiling::m_iEcoSectorSizes[a2]
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 262, "m_iEcoSectorSizes[_iEmptiedEcoSectorId] == 0") == 1 )
  {
    __debugbreak();
  }
  return CEcoSectorMgr::ConnectEconomy((CEcoSectorMgr *)g_cESMgr, a1, a2);
}


// address=[0x15f51c0]
// Decompiled from void *CTiling::NotifyInitEcoSectors()
static void __cdecl CTiling::NotifyInitEcoSectors(bool) {
  
  CTiling::m_iInitLastEcoSectorId = 0;
  j__memset(CTiling::m_iEcoSectorSizes, 255, sizeof(CTiling::m_iEcoSectorSizes));
  CTiling::m_iEcoSectorTileIdIterator = 0;
  j__memset(CTiling::m_uEcoSectorAnyTileIds, 0, sizeof(CTiling::m_uEcoSectorAnyTileIds));
  return j__memset(word_43010C0, 0, 0x200000u);
}


// address=[0x15f57f0]
// Decompiled from int __cdecl CTiling::SetNormalTileId(int a1, __int16 a2)
static void __cdecl CTiling::SetNormalTileId(int,int) {
  
  int result; // eax

  result = a1;
  ITiling::m_pTileIds[a1] = a2;
  return result;
}


// address=[0x15f5980]
// Decompiled from int __cdecl CTiling::TileType(int a1, int a2, int a3, int a4)
static int __cdecl CTiling::TileType(int,int,int,int) {
  
  int v4; // esi
  int v5; // esi

  v4 = CTile::TileType(a1);
  v5 = CLandscapeProperties::TileType((CLandscapeProperties *)&g_cLandscapeProperties, a2) | v4;
  return v5 | CSquare::TileTypeXY(a3, a4);
}


// address=[0x423789c]
// [Decompilation failed for static int CTiling::m_iInitialized]

// address=[0x42378a0]
// [Decompilation failed for static int CTiling::m_iInitLastEcoSectorId]

// address=[0x42378a4]
// [Decompilation failed for static int CTiling::m_iNumberOfWaterElements]

// address=[0x42378a8]
// [Decompilation failed for static int * CTiling::m_iNumberOfOwnedElements]

// address=[0x42378cc]
// [Decompilation failed for static int CTiling::m_iEcoSectorTileIdIterator]

// address=[0x42378d0]
// [Decompilation failed for static int * CTiling::m_iEcoSectorSizes]

// address=[0x42478d0]
// [Decompilation failed for static unsigned short * CTiling::m_uEcoSectorAnyTileIds]

// address=[0x42cf9a8]
// [Decompilation failed for static class CSectors CTiling::m_cSectors]

