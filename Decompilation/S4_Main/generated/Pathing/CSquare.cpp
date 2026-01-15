#include "CSquare.h"

// Definitions for class CSquare

// address=[0x15f0a60]
// Decompiled from int __thiscall CSquare::InitAndFillTypeMapNormal(CSquare *this, int a2, int a3)
void  CSquare::InitAndFillTypeMapNormal(int,int) {
  
  int result; // eax
  int v4; // esi
  int v5; // [esp+4h] [ebp-28h]
  int v6; // [esp+8h] [ebp-24h]
  int v7; // [esp+Ch] [ebp-20h]
  unsigned int v8; // [esp+14h] [ebp-18h]
  int j; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  int v11; // [esp+20h] [ebp-Ch]
  bool IsBlockedLand; // [esp+2Bh] [ebp-1h]

  CSquare::Init(this, a2, a3);
  result = CSquare::TileTypeXY(a2, a3);
  v5 = result;
  for ( i = 0; i < 16; ++i )
  {
    result = CTilingWorld::WorldIndex(a2, i + a3);
    v11 = result;
    for ( j = 0; j < 16; ++j )
    {
      v7 = ITiling::OwnerId(v11);
      v6 = CTilingWorld::WorldGroundType(v11);
      v4 = CTile::TileType(v7);
      v8 = v5 | CLandscapeProperties::TileType((CLandscapeProperties *)&g_cLandscapeProperties, v6) | v4;
      if ( (v8 & 0x10000000) != 0 )
      {
        IsBlockedLand = CTilingWorld::WorldIsBlockedLand(v11);
      }
      else
      {
        if ( (v8 & 0x20000000) == 0
          && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 885, "iTileType & TILE_TYPE_IS_WATER") == 1 )
        {
          __debugbreak();
        }
        ++*((_DWORD *)this + 2);
        if ( (CWaterFlags::WaterFlags(v11) & 0x400) != 0 )
        {
          IsBlockedLand = 0;
          v8 = (unsigned int)&unk_4000000 | v8 & 0xDFFFFFFF;
        }
        else
        {
          IsBlockedLand = (CWaterFlags::WaterFlags(v11) & 0x300) != 0;
        }
      }
      if ( IsBlockedLand )
      {
        ++*((_DWORD *)this + 3);
        result = CSquare::Index(j, i);
        *((_DWORD *)this + result + 6) = -1;
      }
      else
      {
        result = CSquare::Index(j, i);
        *((_DWORD *)this + result + 6) = v8;
      }
      ++v11;
    }
  }
  return result;
}


// address=[0x15f0c40]
// Decompiled from int __thiscall CSquare::InitAndFillTypeMapCatapult(CSquare *this, int a2, int a3)
void  CSquare::InitAndFillTypeMapCatapult(int,int) {
  
  int result; // eax
  int v4; // [esp+0h] [ebp-28h]
  int v5; // [esp+4h] [ebp-24h]
  int v6; // [esp+8h] [ebp-20h]
  int m; // [esp+10h] [ebp-18h]
  int k; // [esp+14h] [ebp-14h]
  int v10; // [esp+18h] [ebp-10h]
  int j; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  char v13; // [esp+25h] [ebp-3h]
  char v14; // [esp+26h] [ebp-2h]
  char v15; // [esp+27h] [ebp-1h]

  CSquare::Init(this, a2, a3);
  result = CSquare::TileTypeXY(a2, a3) | 0x8000000;
  v4 = result;
  for ( i = 0; i < 16; ++i )
  {
    result = CTilingWorld::WorldIndex(a2, i + a3);
    v10 = result;
    v13 = 0;
    v14 = 1;
    for ( j = 0; j < 16; ++j )
    {
      if ( CTilingWorld::WorldIsBlockedLand(v10) )
      {
        v13 = 1;
        v14 = 1;
        *((_DWORD *)this + CSquare::Index(j, i) + 6) = -1;
      }
      else
      {
        v15 = 0;
        if ( v13 )
        {
          v15 = 1;
        }
        else if ( v14 )
        {
          for ( k = 1; k < 19; ++k )
          {
            v6 = v10 + CTilingWorld::WorldSurroundingRelIndex(k);
            if ( CTilingWorld::WorldIsBlockedLand(v6) )
            {
              v15 = 1;
              break;
            }
          }
        }
        else
        {
          for ( m = 0; m < 5; ++m )
          {
            v5 = v10 + CTilingWorld::WorldSurroundingRelIndex(dword_37E1FCC[m]);
            if ( CTilingWorld::WorldIsBlockedLand(v5) )
            {
              v15 = 1;
              break;
            }
          }
        }
        v13 = 0;
        if ( v15 )
        {
          v14 = 1;
          *((_DWORD *)this + CSquare::Index(j, i) + 6) = -1;
        }
        else
        {
          v14 = 0;
          *((_DWORD *)this + CSquare::Index(j, i) + 6) = v4;
        }
      }
      result = ++v10;
    }
  }
  return result;
}


// address=[0x15f3ef0]
// Decompiled from CSquare *__thiscall CSquare::CSquare(CSquare *this)
 CSquare::CSquare(void) {
  
  _vec_ctor_no((char *)this + 3096, 0x100u, 0x80u, (void *(__thiscall *)(void *))CAreaList::CAreaList);
  return this;
}


// address=[0x15f4660]
// Decompiled from int __cdecl CSquare::Index(int a1, int a2)
static int __cdecl CSquare::Index(int,int) {
  
  return a1 + 16 * a2;
}


// address=[0x15f48f0]
// Decompiled from bool __thiscall CSquare::IsPureWaterSquare(CSquare *this)
bool  CSquare::IsPureWaterSquare(void)const {
  
  return *((_DWORD *)this + 2) == 256;
}


// address=[0x15f59e0]
// Decompiled from int __cdecl CSquare::TileTypeXY(int a1, int a2)
static int __cdecl CSquare::TileTypeXY(int,int) {
  
  return (((a2 >> 4) & 1) << 23) | (((a1 >> 4) & 1) << 22);
}


// address=[0x15f5ae0]
// Decompiled from int __thiscall CSquare::WaterCount(CSquare *this)
int  CSquare::WaterCount(void)const {
  
  return *((_DWORD *)this + 2);
}


// address=[0x15f0e20]
// Decompiled from void __thiscall CSquare::ConnectAreas(CSquare *this, int a2, int a3)
void  CSquare::ConnectAreas(int,int) {
  
  int v3; // [esp+0h] [ebp-20h]
  int v4; // [esp+4h] [ebp-1Ch]
  int v5; // [esp+8h] [ebp-18h]
  int i; // [esp+Ch] [ebp-14h]
  int v7; // [esp+10h] [ebp-10h]
  int v8; // [esp+14h] [ebp-Ch]
  int v9; // [esp+18h] [ebp-8h]

  v8 = *((_DWORD *)this + a2 + 518);
  v9 = *((_DWORD *)this + a3 + 518);
  if ( v9 < 0 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 788, "iComponent2 >= 0") == 1 )
    __debugbreak();
  if ( v8 >= 0 )
  {
    if ( v8 != v9 )
    {
      if ( v8 < v9 )
      {
        v5 = v8;
        v7 = v9;
      }
      else
      {
        v5 = v9;
        v7 = v8;
      }
      v3 = TStaticArray<int,63>::Count((char *)this + 256 * v7 + 3096);
      for ( i = 0; i < v3; ++i )
      {
        v4 = *(_DWORD *)TStaticArray<int,63>::operator[](i);
        *((_DWORD *)this + v4 + 518) = v5;
        CAreaList::PushBack((CSquare *)((char *)this + 256 * v5 + 3096), v4);
      }
      if ( v7 < *((_DWORD *)this + 5) )
        TStaticArray<int,63>::Init((CSquare *)((char *)this + 256 * v7 + 3096));
      else
        --*((_DWORD *)this + 5);
    }
  }
  else
  {
    *((_DWORD *)this + a2 + 518) = v9;
    CAreaList::PushBack((CSquare *)((char *)this + 256 * v9 + 3096), a2);
  }
}


// address=[0x15f0f90]
// Decompiled from int __thiscall CSquare::CalcComponentTileIndices(CSquare *this, int a2)
void  CSquare::CalcComponentTileIndices(int) {
  
  int result; // eax
  int i; // [esp+0h] [ebp-8h]

  *((_DWORD *)this + 8966) = 0;
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= *((_DWORD *)this + 5) )
      break;
    if ( (unsigned __int8)TStaticArray<int,63>::Empty((char *)this + 256 * i + 3096) )
    {
      *((_DWORD *)this + i + 8967) = 0;
    }
    else
    {
      *((_DWORD *)this + i + 8967) = *((_DWORD *)this + 8966) + a2;
      ++*((_DWORD *)this + 8966);
    }
  }
  return result;
}


// address=[0x15f4140]
// Decompiled from void __thiscall CSquare::AddComponentIfNecessary(CSquare *this, int a2)
void  CSquare::AddComponentIfNecessary(int) {
  
  if ( *((int *)this + a2 + 518) < 0 )
    CSquare::AddComponet(this, a2);
}


// address=[0x15f4180]
// Decompiled from CSquare *__thiscall CSquare::AddComponet(CSquare *this, int a2)
void  CSquare::AddComponet(int) {
  
  CSquare *result; // eax

  *((_DWORD *)this + a2 + 518) = *((_DWORD *)this + 5);
  CAreaList::InitOne((CSquare *)((char *)this + 256 * *((_DWORD *)this + 5) + 3096), a2);
  result = this;
  ++*((_DWORD *)this + 5);
  return result;
}


// address=[0x15f4a00]
// Decompiled from int __thiscall CSquare::NewArea(CSquare *this, int a2)
int  CSquare::NewArea(int) {
  
  int v2; // ecx

  *((_DWORD *)this + *((_DWORD *)this + 4) + 646) = a2;
  *((_DWORD *)this + *((_DWORD *)this + 4) + 518) = -1;
  v2 = *((_DWORD *)this + 4);
  *((_DWORD *)this + 4) = v2 + 1;
  return v2;
}


// address=[0x15f47c0]
// Decompiled from CSquare *__thiscall CSquare::Init(CSquare *this, int a2, int a3)
void  CSquare::Init(int,int) {
  
  CSquare *result; // eax

  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  result = this;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  return result;
}


