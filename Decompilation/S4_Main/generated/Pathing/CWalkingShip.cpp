#include "all_headers.h"

// Definitions for class CWalkingShip

// address=[0x15f9850]
// Decompiled from CWalkingShip *__thiscall CWalkingShip::CWalkingShip(CWalkingShip *this)
 CWalkingShip::CWalkingShip(void) {
  
  CWalkingBase::CWalkingBase(this, 4, 0);
  *(_DWORD *)this = &CWalkingShip::_vftable_;
  *((_DWORD *)this + 13) |= 0x100u;
  return this;
}


// address=[0x15fafb0]
// Decompiled from CWalking *__thiscall CWalkingShip::~CWalkingShip(CWalkingShip *this)
 CWalkingShip::~CWalkingShip(void) {
  
  return CWalkingBase::~CWalkingBase(this);
}


// address=[0x15fb270]
// Decompiled from int CWalkingShip::GetWalkingType()
enum T_WALKING_TYPE const  CWalkingShip::GetWalkingType(void) {
  
  return 4;
}


// address=[0x15f9890]
// Decompiled from bool __thiscall CWalkingShip::IsNotBlocked(CWalkingShip *this, int a2)
bool  CWalkingShip::IsNotBlocked(int) {
  
  return !CWaterFlags::IsBlockedWater(a2);
}


// address=[0x15f98d0]
// Decompiled from bool __thiscall CWalkingShip::IsNotOccupied(CWalkingShip *this, int a2)
bool  CWalkingShip::IsNotOccupied(int) {
  
  return (CWaterFlags::WaterFlags(a2) & 0x800) == 0;
}


// address=[0x15f9910]
// Decompiled from char __thiscall CWalkingShip::FindPathAStar64(CWalkingShip *this, int a2, int a3, struct CDirCache *a4)
bool  CWalkingShip::FindPathAStar64(int,int,class CDirCache &) {
  
  char Path; // [esp+5h] [ebp-3h]

  if ( !CWater::RemoveShip(a2) && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 2213, "bRemoved") == 1 )
    __debugbreak();
  Path = CAStar64::FindPath((CAStar64 *)&g_cAStar64Ship, a2, a3, a4);
  if ( !CWater::PlaceShip(a2) && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 2219, "bPlaced") == 1 )
    __debugbreak();
  return Path;
}


// address=[0x15f99b0]
// Decompiled from int __thiscall CWalkingShip::IdleWalk(CWalkingShip *this, Y16X16 *a2, int a3)
int  CWalkingShip::IdleWalk(int,int) {
  
  int v4; // [esp+8h] [ebp-B4h]
  int v5; // [esp+Ch] [ebp-B0h]
  int v6; // [esp+18h] [ebp-A4h]
  int v7; // [esp+1Ch] [ebp-A0h]
  int v8; // [esp+20h] [ebp-9Ch]
  int v9; // [esp+24h] [ebp-98h]
  int v10; // [esp+28h] [ebp-94h]
  int v11; // [esp+2Ch] [ebp-90h]
  int v12; // [esp+30h] [ebp-8Ch]
  BOOL v13; // [esp+34h] [ebp-88h]
  int v14; // [esp+40h] [ebp-7Ch]
  int DistanceToNearestShip; // [esp+44h] [ebp-78h]
  __int16 v16; // [esp+48h] [ebp-74h]
  int v17; // [esp+4Ch] [ebp-70h]
  int v18; // [esp+50h] [ebp-6Ch]
  int v19; // [esp+5Ch] [ebp-60h]
  int v20; // [esp+60h] [ebp-5Ch]
  int v21; // [esp+64h] [ebp-58h]
  int v22; // [esp+68h] [ebp-54h]
  int v23; // [esp+6Ch] [ebp-50h]
  int v24; // [esp+70h] [ebp-4Ch]
  int v25; // [esp+74h] [ebp-48h]
  __int16 v26; // [esp+78h] [ebp-44h]
  int v27; // [esp+7Ch] [ebp-40h]
  int v28; // [esp+80h] [ebp-3Ch]
  int j; // [esp+84h] [ebp-38h]
  int v30; // [esp+88h] [ebp-34h]
  unsigned int v31; // [esp+8Ch] [ebp-30h]
  signed int v32; // [esp+8Ch] [ebp-30h]
  unsigned __int8 v33; // [esp+92h] [ebp-2Ah]
  bool v34; // [esp+93h] [ebp-29h]
  int i; // [esp+94h] [ebp-28h]
  int k; // [esp+94h] [ebp-28h]
  int m; // [esp+94h] [ebp-28h]
  _DWORD v39[7]; // [esp+9Ch] [ebp-20h]

  v24 = 0;
  v25 = 0;
  v28 = 10;
  v27 = 0;
  v23 = CWorldManager::Index((int)a2);
  for ( i = 0; i < 6; ++i )
  {
    v4 = v23 + CWorldManager::NeighborRelIndex(i);
    v26 = CWaterFlags::WaterFlags(v4);
    if ( (v26 & 0x300) != 0 )
    {
      v39[i] = 11;
      ++v25;
    }
    else
    {
      v24 += (v26 & 0x800) != 0;
      v30 = (v26 & 0xF0) >> 4;
      v39[i] = v30;
      if ( v30 < v28 )
        v28 = (v26 & 0xF0) >> 4;
      if ( v30 > v27 )
        v27 = (v26 & 0xF0) >> 4;
    }
  }
  v39[6] = v39[0];
  v33 = 0;
  v34 = 0;
  if ( v28 >= v27 || v27 <= 0 )
  {
    if ( (CWaterFlags::WaterFlags(v23) & 0x1000) != 0 )
      v34 = v24 + v25 < 6;
  }
  else
  {
    v33 = 1;
  }
  if ( v34 )
  {
    v11 = CWorldManager::Index((int)a2);
    v12 = (*(int (__thiscall **)(CWalkingShip *, int))(*(_DWORD *)this + 28))(this, v11);
    if ( (*((_DWORD *)this + 12) & 0x20000) == 0 )
      *((_DWORD *)this + 7) = -1;
    *((_DWORD *)this + 12) &= ~0x20000u;
    if ( (unsigned __int8)CWorldManager::InWorldPackedXY(*((_DWORD *)this + 7)) )
    {
      v10 = CWorldManager::Index(*((_DWORD *)this + 7));
      v18 = (*(int (__thiscall **)(CWalkingShip *, int))(*(_DWORD *)this + 28))(this, v10);
      if ( (CWaterFlags::WaterFlags(v23) & 0x1000) != 0 || v18 <= 0 || v12 != v18 )
        *((_DWORD *)this + 7) = -1;
    }
    else
    {
      *((_DWORD *)this + 7) = -1;
    }
    if ( *((int *)this + 7) < 0 )
    {
      v9 = Y16X16::UnpackXFast((int)a2);
      v8 = Y16X16::UnpackYFast((int)a2);
      v20 = -1;
      v14 = -1;
      for ( j = 0; j < SurroundingHexPointsCount(15); ++j )
      {
        v22 = v9 + SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * j]);
        v21 = v8 + SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * j]);
        if ( (unsigned __int8)CWorldManager::InWorld(v22, v21) )
        {
          v17 = CWorldManager::Index(v22, v21);
          if ( (*(int (__thiscall **)(CWalkingShip *, int))(*(_DWORD *)this + 28))(this, v17) == v12 )
          {
            v16 = CWaterFlags::WaterFlags(v17);
            if ( (v16 & 0x1000) == 0 )
            {
              DistanceToNearestShip = CWaterFlags::WaterFlagsGetDistanceToNearestShip(v16);
              if ( DistanceToNearestShip == -1 || DistanceToNearestShip > 4 )
              {
                v20 = v22;
                v14 = v21;
                break;
              }
            }
          }
        }
      }
      if ( v20 < 0 )
        return 8;
      *((_DWORD *)this + 7) = Y16X16::PackXYFast(v20, v14);
    }
    v19 = Y16X16::DirectionFast(a2, *((_DWORD *)this + 7));
    v7 = Y16X16::UnpackXFast((int)a2);
    v6 = Y16X16::UnpackYFast((int)a2);
    v5 = CWorldManager::Index(g_sNeighborPoints[2 * v19] + v7, dword_37D8C0C[2 * v19] + v6);
    if ( (*(unsigned __int8 (__thiscall **)(CWalkingShip *, int))(*(_DWORD *)this + 20))(this, v5) )
    {
      *((_DWORD *)this + 12) |= 0x20000u;
      return v19;
    }
  }
  else
  {
    *((_DWORD *)this + 7) = -1;
  }
  if ( v34 | v33 )
  {
    v31 = 0;
    v13 = v39[5] == v28;
    for ( k = 0; k < 6; ++k )
    {
      if ( v39[k] == v28 )
      {
        v31 += v13 + (v39[k + 1] == 0) + 1;
        v39[k] = v31;
      }
      else
      {
        v39[k] = -1;
        v13 = 0;
      }
    }
    v32 = CStateGame::Rand(g_pGame) % v31;
    for ( m = 0; m < 6; ++m )
    {
      if ( v32 < v39[m] )
        return m;
    }
  }
  *((_DWORD *)this + 7) = -1;
  return 8;
}


