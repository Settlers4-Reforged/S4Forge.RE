#include "CAI_Ecosector_Grid_Iterator.h"

// Definitions for class CAI_Ecosector_Grid_Iterator

// address=[0x1339930]
// Decompiled from CAI_Ecosector_Grid_Iterator *__thiscall CAI_Ecosector_Grid_Iterator::CAI_Ecosector_Grid_Iterator(  CAI_Ecosector_Grid_Iterator *this)
 CAI_Ecosector_Grid_Iterator::CAI_Ecosector_Grid_Iterator(void) {
  
  CAI_Ecosector_Grid_Iterator::CESGI::CESGI(this);
  j__memset(this, 0, 0xA10u);
  return this;
}


// address=[0x1339960]
// Decompiled from void __thiscall CAI_Ecosector_Grid_Iterator::~CAI_Ecosector_Grid_Iterator(CAI_Ecosector_Grid_Iterator *this)
 CAI_Ecosector_Grid_Iterator::~CAI_Ecosector_Grid_Iterator(void) {
  
  ;
}


// address=[0x1339970]
// Decompiled from void *__thiscall CAI_Ecosector_Grid_Iterator::Init(CAI_Ecosector_Grid_Iterator *this, int a2)
void  CAI_Ecosector_Grid_Iterator::Init(int) {
  
  int v2; // ecx

  *(_DWORD *)this = a2;
  *((_BYTE *)this + 6) = CWorldManager::Width(a2) / 16;
  *((_BYTE *)this + 7) = CWorldManager::Height(v2, this) / 16;
  CAI_Ecosector_Grid_Iterator::FindStartPoint(this);
  TStaticFIFO<unsigned short,1024>::Init((char *)this + 520);
  TStaticFIFO<unsigned short,1024>::Push((char *)this + 4);
  return j__memset((char *)this + 8, 0, 0x200u);
}


// address=[0x13399f0]
// Decompiled from int __thiscall CAI_Ecosector_Grid_Iterator::IsEnd(CAI_Ecosector_Grid_Iterator *this)
bool  CAI_Ecosector_Grid_Iterator::IsEnd(void) {
  
  return TStaticFIFO<unsigned short,1024>::Empty((char *)this + 520, this);
}


// address=[0x1339a10]
// Decompiled from int __thiscall CAI_Ecosector_Grid_Iterator::GetNext(CAI_Ecosector_Grid_Iterator *this)
int  CAI_Ecosector_Grid_Iterator::GetNext(void) {
  
  int v2; // [esp+0h] [ebp-2Ch]
  int v3; // [esp+4h] [ebp-28h]
  int v4; // [esp+8h] [ebp-24h]
  int v5; // [esp+Ch] [ebp-20h]
  int v6; // [esp+10h] [ebp-1Ch]
  int v8; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+1Ch] [ebp-10h]
  int v10; // [esp+20h] [ebp-Ch]
  int v11; // [esp+20h] [ebp-Ch]
  __int16 v12; // [esp+24h] [ebp-8h] BYREF
  __int16 v13; // [esp+26h] [ebp-6h] BYREF
  __int16 v14; // [esp+28h] [ebp-4h] BYREF
  __int16 v15; // [esp+2Ah] [ebp-2h] BYREF

  v3 = CEcoSectorMgr::EntryPtr((CEcoSectorMgr *)g_cESMgr, *(_DWORD *)this);
  if ( !v3 )
    return -1;
  v2 = CEcoSector::Owner(v3);
  v5 = COwnerMap::OwnerBit(v2);
  if ( (unsigned __int8)CAI_Ecosector_Grid_Iterator::IsEnd(this) )
    return -1;
  v4 = *(unsigned __int16 *)TStaticFIFO<unsigned short,1024>::Top((char *)this + 520, v2);
  TStaticFIFO<unsigned short,1024>::Pop((char *)this + 520);
  v6 = (v4 & 0xFF00) >> 8;
  v8 = (unsigned __int8)v4 + 1;
  if ( v8 < *((unsigned __int8 *)this + 6) )
  {
    if ( (v5 & COwnerMap::OwnerBits1VW(v8, v6)) != 0 && !CAI_Ecosector_Grid_Iterator::IsChecked(this, v8, v6) )
    {
      v15 = v8 + ((_WORD)v6 << 8);
      TStaticFIFO<unsigned short,1024>::Push(&v15);
    }
    CAI_Ecosector_Grid_Iterator::SetChecked(this, v8, v6);
  }
  v9 = (unsigned __int8)v4 - 1;
  if ( v9 > -1 )
  {
    if ( (v5 & COwnerMap::OwnerBits1VW(v9, v6)) != 0 && !CAI_Ecosector_Grid_Iterator::IsChecked(this, v9, v6) )
    {
      v14 = v9 + ((_WORD)v6 << 8);
      TStaticFIFO<unsigned short,1024>::Push(&v14);
    }
    CAI_Ecosector_Grid_Iterator::SetChecked(this, v9, v6);
  }
  v10 = v6 + 1;
  if ( v6 + 1 < *((unsigned __int8 *)this + 7) )
  {
    if ( (v5 & COwnerMap::OwnerBits1VW((unsigned __int8)v4, v10)) != 0
      && !CAI_Ecosector_Grid_Iterator::IsChecked(this, (unsigned __int8)v4, v10) )
    {
      v13 = (unsigned __int8)v4 + ((_WORD)v10 << 8);
      TStaticFIFO<unsigned short,1024>::Push(&v13);
    }
    CAI_Ecosector_Grid_Iterator::SetChecked(this, (unsigned __int8)v4, v10);
  }
  v11 = v6 - 1;
  if ( v6 - 1 <= -1 )
    return v4;
  if ( (v5 & COwnerMap::OwnerBits1VW((unsigned __int8)v4, v11)) != 0
    && !CAI_Ecosector_Grid_Iterator::IsChecked(this, (unsigned __int8)v4, v11) )
  {
    v12 = (unsigned __int8)v4 + ((_WORD)v11 << 8);
    TStaticFIFO<unsigned short,1024>::Push(&v12);
  }
  CAI_Ecosector_Grid_Iterator::SetChecked(this, (unsigned __int8)v4, v11);
  return v4;
}


// address=[0x1339c80]
// Decompiled from int __thiscall CAI_Ecosector_Grid_Iterator::FindStartPoint(CAI_Ecosector_Grid_Iterator *this)
void  CAI_Ecosector_Grid_Iterator::FindStartPoint(void) {
  
  int result; // eax
  int TileOfSquareVW; // [esp+0h] [ebp-18h]
  int v3; // [esp+4h] [ebp-14h]
  int v4; // [esp+8h] [ebp-10h]
  unsigned __int8 j; // [esp+16h] [ebp-2h]
  unsigned __int8 i; // [esp+17h] [ebp-1h]

  result = CEcoSectorMgr::EntryPtr((CEcoSectorMgr *)g_cESMgr, *(_DWORD *)this);
  if ( !result )
    return result;
  v4 = CEcoSector::Owner(result);
  v3 = COwnerMap::OwnerBit(v4);
  for ( i = 0; ; ++i )
  {
    result = *((unsigned __int8 *)this + 6);
    if ( i >= result )
      break;
    for ( j = 0; j < (int)*((unsigned __int8 *)this + 7); ++j )
    {
      if ( (v3 & COwnerMap::OwnerBits1VW(i, j)) != 0 )
      {
        TileOfSquareVW = ITiling::FirstTileOfSquareVW(i, j);
        if ( CAI_Ecosector_Grid_Iterator::IsMyTile(this, TileOfSquareVW) )
        {
          result = j << 8;
          *((_WORD *)this + 2) = result + i;
          return result;
        }
      }
    }
  }
  return result;
}


// address=[0x1339d60]
// Decompiled from bool __thiscall CAI_Ecosector_Grid_Iterator::IsMyTile(CAI_Ecosector_Grid_Iterator *this, int a2)
bool  CAI_Ecosector_Grid_Iterator::IsMyTile(int) {
  
  int SquareTile; // [esp+4h] [ebp-8h]
  struct CTile *v5; // [esp+8h] [ebp-4h]

  v5 = (struct CTile *)ITiling::Tile(a2);
  if ( CTile::TilingType(v5) )
    return 0;
  if ( CTile::EcoSectorId(v5) == *(_DWORD *)this )
    return 1;
  SquareTile = CTile::NextSquareTile(v5);
  return SquareTile && CAI_Ecosector_Grid_Iterator::IsMyTile(this, SquareTile);
}


// address=[0x1339fe0]
// Decompiled from bool __thiscall CAI_Ecosector_Grid_Iterator::IsChecked(CAI_Ecosector_Grid_Iterator *this, int a2, int a3)
bool  CAI_Ecosector_Grid_Iterator::IsChecked(int,int) {
  
  return ((1 << (a2 & 7)) & *((unsigned __int8 *)this + 8 * a3 + (a2 >> 3) + 8)) != 0;
}


// address=[0x133a0f0]
// Decompiled from int __thiscall CAI_Ecosector_Grid_Iterator::SetChecked(CAI_Ecosector_Grid_Iterator *this, int a2, int a3)
void  CAI_Ecosector_Grid_Iterator::SetChecked(int,int) {
  
  int result; // eax

  result = (1 << (a2 & 7)) | *((unsigned __int8 *)this + 8 * a3 + (a2 >> 3) + 8);
  *((_BYTE *)this + 8 * a3 + (a2 >> 3) + 8) = result;
  return result;
}


