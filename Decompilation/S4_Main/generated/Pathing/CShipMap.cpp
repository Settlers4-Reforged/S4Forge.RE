#include "all_headers.h"

// Definitions for class CShipMap

// address=[0x15fd4f0]
// Decompiled from char __cdecl CShipMap::InShipList(int a1)
static bool __cdecl CShipMap::InShipList(int) {
  
  Squares *v1; // eax
  Squares *v2; // eax
  int v4; // [esp+0h] [ebp-10h]
  int v5; // [esp+4h] [ebp-Ch]
  int (*v6)[4]; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a1)
    && BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 348, "g_cWorld.InWorldPackedXY(_iXY)") == 1 )
  {
    __debugbreak();
  }
  v1 = (Squares *)Y16X16::UnpackXFast(a1);
  v4 = Squares::XYToVW(v1);
  v2 = (Squares *)Y16X16::UnpackYFast(a1);
  v5 = Squares::XYToVW(v2);
  v6 = CShipMap::ShipListVW(v4, v5);
  for ( i = 0; i < 4; ++i )
  {
    if ( (*v6)[i] == a1 )
      return 1;
    if ( !(*v6)[i] )
      return 0;
  }
  return 0;
}


// address=[0x15fe7e0]
// Decompiled from char *__cdecl CShipMap::ShipListVW(int a1, int a2)
static int (& __cdecl CShipMap::ShipListVW(int,int))[4] {
  
  return (char *)&CShipMap::m_tShipLists + 1024 * a2 + 16 * a1 + 1024;
}


// address=[0x15fd1e0]
// Decompiled from void *CShipMap::Init()
static void __cdecl CShipMap::Init(void) {
  
  void *result; // eax

  result = memset(&CShipMap::m_tShipLists, 0, 0x10800u);
  CShipMap::m_iInitialized = 1;
  return result;
}


// address=[0x15fd210]
// Decompiled from void CShipMap::Done()
static void __cdecl CShipMap::Done(void) {
  
  CShipMap::m_iInitialized = 0;
}


// address=[0x15fd220]
// Decompiled from char __cdecl CShipMap::PlaceShip(int a1)
static bool __cdecl CShipMap::PlaceShip(int) {
  
  int *EntryForPlaceShip; // [esp+0h] [ebp-4h]

  EntryForPlaceShip = CShipMap::GetEntryForPlaceShip(a1);
  if ( !EntryForPlaceShip )
    return 0;
  if ( *EntryForPlaceShip )
  {
    if ( BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 227, "*pShipMapEntry == 0") == 1 )
      __debugbreak();
  }
  *EntryForPlaceShip = a1;
  return 1;
}


// address=[0x15fd280]
// Decompiled from int *__cdecl CShipMap::GetEntryForPlaceShip(int a1)
static int * __cdecl CShipMap::GetEntryForPlaceShip(int) {
  
  Squares *v1; // eax
  Squares *v2; // eax
  int (*v4)[4]; // [esp+0h] [ebp-10h]
  int i; // [esp+4h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-8h]
  int v7; // [esp+Ch] [ebp-4h]

  v1 = (Squares *)Y16X16::UnpackXFast(a1);
  v7 = Squares::XYToVW(v1);
  v2 = (Squares *)Y16X16::UnpackYFast(a1);
  v6 = Squares::XYToVW(v2);
  v4 = CShipMap::ShipListVW(v7, v6);
  for ( i = 0; i < 3; ++i )
  {
    if ( !(*v4)[i] )
      return &(*v4)[i];
  }
  if ( (*v4)[3] )
    return 0;
  if ( (*CShipMap::ShipListVW(v7, v6 - 1))[3] )
    return 0;
  if ( (*CShipMap::ShipListVW(v7, v6 + 1))[3] )
    return 0;
  if ( v7 > 0 )
  {
    if ( (*CShipMap::ShipListVW(v7 - 1, v6 - 1))[3] )
      return 0;
    if ( (*CShipMap::ShipListVW(v7 - 1, v6))[3] )
      return 0;
  }
  if ( v7 >= 63 )
    return &(*v4)[3];
  if ( (*CShipMap::ShipListVW(v7 + 1, v6))[3] )
    return 0;
  if ( (*CShipMap::ShipListVW(v7 + 1, v6 + 1))[3] )
    return 0;
  else
    return &(*v4)[3];
}


// address=[0x15fd420]
// Decompiled from char __cdecl CShipMap::RemoveShip(int a1)
static bool __cdecl CShipMap::RemoveShip(int) {
  
  Squares *v1; // eax
  Squares *v2; // eax
  int v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch]
  int (*v6)[4]; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v1 = (Squares *)Y16X16::UnpackXFast(a1);
  v4 = Squares::XYToVW(v1);
  v2 = (Squares *)Y16X16::UnpackYFast(a1);
  v5 = Squares::XYToVW(v2);
  v6 = CShipMap::ShipListVW(v4, v5);
  for ( i = 0; ; ++i )
  {
    if ( i >= 4 )
      return 0;
    if ( (*v6)[i] == a1 )
      break;
    if ( !(*v6)[i] )
      return 0;
  }
  while ( i < 3 && (*v6)[i + 1] )
  {
    (*v6)[i] = (*v6)[i + 1];
    ++i;
  }
  (*v6)[i] = 0;
  return 1;
}


// address=[0x4617aac]
// [Decompilation failed for static int CShipMap::m_iInitialized]

// address=[0x4617ab0]
// [Decompilation failed for static int (* CShipMap::m_tShipLists)[64][4]]

