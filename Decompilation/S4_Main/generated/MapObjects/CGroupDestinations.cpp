#include "CGroupDestinations.h"

// Definitions for class CGroupDestinations

// address=[0x15507a0]
// Decompiled from CGroupDestinations *__thiscall CGroupDestinations::CGroupDestinations(  CGroupDestinations *this,  int a2,  int a3,  int a4,  char a5,  int a6)
 CGroupDestinations::CGroupDestinations(int a2, int a3, int a4, int a5, int a6) {
  
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  _DWORD v13[4]; // [esp+4h] [ebp-44h] BYREF
  int v14; // [esp+14h] [ebp-34h]
  int v15; // [esp+18h] [ebp-30h]
  int v16; // [esp+1Ch] [ebp-2Ch]
  int (__fastcall *v17)(int, int); // [esp+20h] [ebp-28h]
  int v18; // [esp+24h] [ebp-24h]
  int v19; // [esp+28h] [ebp-20h]
  int v20; // [esp+2Ch] [ebp-1Ch]
  int (__fastcall *v21)(int, int); // [esp+30h] [ebp-18h]
  int v22; // [esp+34h] [ebp-14h]
  int v23; // [esp+38h] [ebp-10h]
  int i; // [esp+3Ch] [ebp-Ch]
  CGroupDestinations *v25; // [esp+40h] [ebp-8h]
  char v26; // [esp+47h] [ebp-1h]

  v25 = this;
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\GroupMgr.cpp", 76, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  *(_DWORD *)v25 = 0;
  *((_DWORD *)v25 + 1) = 0;
  *((_DWORD *)v25 + 2) = Y16X16::PackXYFast(a2, a3);
  if ( (a5 & 2) != 0 )
    v17 = CGroupDestinations::CatapultSectorId;
  else
    v17 = CGroupDestinations::NormalSectorId;
  v21 = v17;
  v20 = v17(a2, a3);
  if ( a6 <= 0 )
  {
    v16 = 0;
  }
  else
  {
    v6 = Y16X16::UnpackYFast(a6);
    v7 = Y16X16::UnpackXFast(a6);
    v16 = v21(v7, v6);
  }
  v22 = v16;
  if ( v20 > 0 && v20 == v22 )
    goto LABEL_21;
  v26 = 0;
  if ( v22 > 0 && (a5 & 1) != 0 )
  {
    CSpiralWalk::CSpiralWalk((CSpiralWalk *)v13, a2, a3, 15);
    while ( CSpiralWalk::NextXY(v13, &a2, &a3) )
    {
      v15 = v21(a2, a3);
      if ( v15 == v22 )
      {
        v20 = v22;
        v26 = 1;
        break;
      }
    }
  }
  if ( !v26 )
    return v25;
  v8 = Y16X16::PackXYFast(a2, a3);
  *((_DWORD *)v25 + 2) = v8;
LABEL_21:
  if ( a4 <= 1 )
    return v25;
  if ( a4 > 100 )
    a4 = 100;
  v23 = 1;
  for ( i = 1; v23 < a4 && i < 100; ++i )
  {
    v9 = CSpiralOffsets::DeltaX(i);
    v18 = a2 + 2 * v9;
    v10 = CSpiralOffsets::DeltaY(i);
    v19 = a3 + 2 * v10;
    if ( (unsigned __int8)CWorldManager::InWorld(v18, v19) )
    {
      v14 = v21(v18, v19);
      if ( v14 == v20 )
      {
        v11 = Y16X16::PackXYFast(v18, v19);
        *((_DWORD *)v25 + v23++ + 2) = v11;
      }
    }
  }
  *(_DWORD *)v25 = v23 - 1;
  return v25;
}


// address=[0x1552710]
// Decompiled from int __thiscall CGroupDestinations::GetNextDestination(CGroupDestinations *this)
int  CGroupDestinations::GetNextDestination(void) {
  
  int v2; // [esp+0h] [ebp-Ch]
  int v3; // [esp+4h] [ebp-8h]

  v2 = *((_DWORD *)this + *((_DWORD *)this + 1) + 2);
  if ( *((_DWORD *)this + 1) < *(_DWORD *)this )
    v3 = *((_DWORD *)this + 1) + 1;
  else
    v3 = 0;
  *((_DWORD *)this + 1) = v3;
  return v2;
}


// address=[0x15509f0]
// Decompiled from int __fastcall CGroupDestinations::NormalSectorId(int a1, int a2)
int __fastcall CGroupDestinations::NormalSectorId(int a1, int a2) {
  
  return CWorldManager::SectorId(a1, a2);
}


// address=[0x1550a10]
// Decompiled from int __fastcall CGroupDestinations::CatapultSectorId(int a1, int a2)
int __fastcall CGroupDestinations::CatapultSectorId(int a1, int a2) {
  
  int v2; // eax

  v2 = CWorldManager::Index(a1, a2);
  return ITiling::CatapultSectorId(v2);
}


