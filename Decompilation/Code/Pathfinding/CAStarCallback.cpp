#include "CAStarCallback.h"

// Definitions for class CAStarCallback

// address=[0x15d4a90]
// Decompiled from int __cdecl CAStarCallback::FindPath(int a1, int a2, void (__cdecl *a3)(int, int), int a4)

static int __cdecl CAStarCallback::FindPath(int,int,void (__cdecl*)(int,int),int) {
  
  int v5; // [esp+0h] [ebp-7Ch]
  int v6; // [esp+4h] [ebp-78h]
  int v7; // [esp+8h] [ebp-74h]
  int v8; // [esp+Ch] [ebp-70h]
  int v9; // [esp+14h] [ebp-68h]
  int v10; // [esp+18h] [ebp-64h]
  _BYTE v11[88]; // [esp+20h] [ebp-5Ch] BYREF

  if ( (int)CAStarTiling::FindPath(a1, a2, (struct CWaypoints *)v11, a4) <= 0 )
    return 0;
  v10 = 1;
  v7 = Y16X16::UnpackXFast(a1);
  v8 = Y16X16::UnpackYFast(a1);
  a3(v7, v8);
  CWaypoints::GoalCached((CWaypoints *)v11);
  while ( CWaypoints::CachedWaypointsCount((pairNode *)v11) > 0 )
  {
    v9 = CWaypoints::Back(v11, v5);
    CWaypoints::PopBack(v11);
    v5 = Y16X16::UnpackXFast(v9);
    v6 = Y16X16::UnpackYFast(v9);
    a3(v5, v6);
  }
  return v10;
}


