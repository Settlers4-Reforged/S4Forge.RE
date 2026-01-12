#include "CWalkingCatapult.h"

// Definitions for class CWalkingCatapult

// address=[0x15f91a0]
// Decompiled from CWalkingCatapult *__thiscall CWalkingCatapult::CWalkingCatapult(CWalkingCatapult *this)

 CWalkingCatapult::CWalkingCatapult(void) {
  
  CWalkingBase::CWalkingBase(this, 3, 0);
  *(_DWORD *)this = &CWalkingCatapult::_vftable_;
  *((_DWORD *)this + 13) |= 0x200u;
  return this;
}


// address=[0x15faf70]
// Decompiled from CWalking *__thiscall CWalkingCatapult::~CWalkingCatapult(CWalkingCatapult *this)

 CWalkingCatapult::~CWalkingCatapult(void) {
  
  return CWalkingBase::~CWalkingBase(this);
}


// address=[0x15fb240]
// Decompiled from // MFC 3.1-14.0 32bit
int CWalkingCatapult::GetWalkingType()

enum T_WALKING_TYPE const  CWalkingCatapult::GetWalkingType(void) {
  
  return 3;
}


// address=[0x15f91e0]
// Decompiled from bool __thiscall CWalkingCatapult::IsNotBlocked(CWalkingCatapult *this, int a2)

bool  CWalkingCatapult::IsNotBlocked(int) {
  
  return (unsigned int)(CWorldManager::CatapultTileId(a2) - 1) < 0xBFFF;
}


// address=[0x15f9220]
// Decompiled from bool __thiscall CWalkingCatapult::IsNotOccupied(CWalkingCatapult *this, int a2)

bool  CWalkingCatapult::IsNotOccupied(int) {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = CWorldManager::Width(this);
  if ( CWorldManager::OccupyingEntityId(a2) )
    return 0;
  if ( CWorldManager::OccupyingEntityId(a2 + 1) )
    return 0;
  if ( CWorldManager::OccupyingEntityId(a2 + v3 + 1) )
    return 0;
  if ( CWorldManager::OccupyingEntityId(v3 + a2) )
    return 0;
  if ( CWorldManager::OccupyingEntityId(a2 - 1) )
    return 0;
  if ( CWorldManager::OccupyingEntityId(a2 - v3 - 1) )
    return 0;
  return CWorldManager::OccupyingEntityId(a2 - v3) == 0;
}


// address=[0x15f9300]
// Decompiled from char __thiscall CWalkingCatapult::FindPathAStar64(CWalkingCatapult *this, int a2, int a3, struct CDirCache *a4)

bool  CWalkingCatapult::FindPathAStar64(int,int,class CDirCache &) {
  
  int v5; // [esp+4h] [ebp-2Ch]
  int v6; // [esp+Ch] [ebp-24h]
  int v7; // [esp+14h] [ebp-1Ch]
  int j; // [esp+18h] [ebp-18h]
  int i; // [esp+1Ch] [ebp-14h]
  char Path; // [esp+23h] [ebp-Dh]
  _BYTE v11[8]; // [esp+24h] [ebp-Ch]

  v6 = CWorldManager::Index(a2);
  for ( i = 0; i < 6; ++i )
  {
    v7 = v6 + CWorldManager::NeighborRelIndex(i);
    if ( CWorldManager::MapObjectId(v7) == i + 1 )
    {
      v11[i] = 1;
      CWorldManager::SetMapObjectId(v7, 0);
    }
    else
    {
      if ( (unsigned int)i >= 6 )
        j____report_rangecheckfailure();
      v11[i] = 0;
    }
  }
  Path = CAStar64::FindPath((CAStar64 *)&g_cAStar64Catapult, a2, a3, a4);
  for ( j = 0; j < 6; ++j )
  {
    if ( v11[j] )
    {
      v5 = v6 + CWorldManager::NeighborRelIndex(j);
      CWorldManager::SetMapObjectId(v5, j + 1);
    }
  }
  return Path;
}


// address=[0x15f9420]
// Decompiled from int __thiscall CWalkingCatapult::IdleWalk(_DWORD *this, Y16X16 *a2, int a3)

int  CWalkingCatapult::IdleWalk(int,int) {
  
  int v4; // [esp+0h] [ebp-64h]
  int v5; // [esp+Ch] [ebp-58h]
  int v6; // [esp+10h] [ebp-54h]
  int v7; // [esp+14h] [ebp-50h]
  int v8; // [esp+18h] [ebp-4Ch]
  int v9; // [esp+1Ch] [ebp-48h]
  int v10; // [esp+20h] [ebp-44h]
  int v11; // [esp+24h] [ebp-40h]
  int v12; // [esp+28h] [ebp-3Ch]
  int v13; // [esp+30h] [ebp-34h]
  int v14; // [esp+34h] [ebp-30h]
  int v15; // [esp+38h] [ebp-2Ch]
  int v16; // [esp+3Ch] [ebp-28h]
  int v17; // [esp+40h] [ebp-24h]
  int v18; // [esp+44h] [ebp-20h]
  int v19; // [esp+48h] [ebp-1Ch]
  int v20; // [esp+4Ch] [ebp-18h]
  int k; // [esp+50h] [ebp-14h]
  int i; // [esp+54h] [ebp-10h]
  int j; // [esp+58h] [ebp-Ch]
  char v25; // [esp+62h] [ebp-2h]
  bool v26; // [esp+63h] [ebp-1h]

  v19 = Y16X16::UnpackXFast((int)a2);
  v18 = Y16X16::UnpackYFast((int)a2);
  if ( !CWorldManager::InInnerWorld1(v19, v18)
    && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 2009, "g_cWorld.InInnerWorld1(iCurrentX, iCurrentY)") == 1 )
  {
    __debugbreak();
  }
  if ( !CWorldManager::InInnerWorld1(v19, v18) )
    return 8;
  v16 = CWorldManager::Index(v19, v18);
  v26 = CWorldManager::MoveCostsBits(v16) >= 7;
  if ( !v26 )
  {
    for ( i = 0; i < 6; ++i )
    {
      v12 = v16 + CWorldManager::NeighborRelIndex(i);
      if ( CWorldManager::FlagBits(v12, 8u) && CWorldManager::MoveCostsBits(v12) >= 7 )
      {
        v26 = 1;
        break;
      }
    }
  }
  if ( v26 )
  {
    v9 = (*(int (__thiscall **)(_DWORD *, int))(*this + 28))(this, v16);
    if ( (this[12] & 0x20000) == 0 )
      this[7] = -1;
    this[12] &= ~0x20000u;
    if ( (unsigned __int8)CWorldManager::InWorldPackedXY(this[7]) )
    {
      v11 = CWorldManager::Index(this[7]);
      v10 = (*(int (__thiscall **)(_DWORD *, int))(*this + 28))(this, v11);
      if ( CWorldManager::MoveCostsBits(v11) == 7 || v10 <= 0 || v9 != v10 )
        this[7] = -1;
    }
    else
    {
      this[7] = -1;
    }
    if ( (int)this[7] < 0 )
    {
      v6 = Y16X16::UnpackXFast((int)a2);
      v5 = Y16X16::UnpackYFast((int)a2);
      v13 = -1;
      v7 = -1;
      for ( j = 0; j < SurroundingHexPointsCount(15); ++j )
      {
        v15 = v6 + SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * j]);
        v14 = v5 + SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * j]);
        if ( (unsigned __int8)CWorldManager::InWorld(v15, v14) )
        {
          v20 = CWorldManager::Index(v15, v14);
          if ( (*(int (__thiscall **)(_DWORD *, int))(*this + 28))(this, v20) == v9
            && CWorldManager::MoveCostsBits(v20) < 7
            && (*(unsigned __int8 (__thiscall **)(_DWORD *, int))(*this + 24))(this, v20) )
          {
            v25 = 1;
            for ( k = 1; k < 19; ++k )
            {
              v8 = v20 + CWorldManager::SurroundingHexPointRelIndex(k);
              if ( CWorldManager::FlagBits(v8, 8u) && CWorldManager::MoveCostsBits(v8) >= 7 )
              {
                v25 = 0;
                break;
              }
            }
            if ( v25 )
            {
              v13 = v15;
              v7 = v14;
              break;
            }
          }
        }
      }
      if ( v13 < 0 )
        return 8;
      this[7] = Y16X16::PackXYFast(v13, v7);
    }
    v17 = Y16X16::DirectionFast(a2, this[7]);
    v4 = CWorldManager::Index(g_sNeighborPoints[2 * v17] + v19, dword_37D8C0C[2 * v17] + v18);
    if ( !(*(unsigned __int8 (__thiscall **)(_DWORD *, int))(*this + 20))(this, v4) )
      return 8;
    return v17;
  }
  else
  {
    this[7] = -1;
    return 8;
  }
}


// address=[0x15f9810]
// Decompiled from int __thiscall CWalkingCatapult::SectorId(CWalkingCatapult *this, int a2)

int  CWalkingCatapult::SectorId(int) {
  
  return ITiling::CatapultSectorId(a2);
}


// address=[0x15f9830]
// Decompiled from int __thiscall CWalkingCatapult::TileId(CWalkingCatapult *this, int a2)

int  CWalkingCatapult::TileId(int) {
  
  return ITiling::CatapultTileId(a2);
}


