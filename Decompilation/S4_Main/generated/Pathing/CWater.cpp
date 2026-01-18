#include "CWater.h"

// Definitions for class CWater

// address=[0x15fc7f0]
// Decompiled from CWater *__thiscall CWater::CWater(CWater *this)
 CWater::CWater(void) {
  
  if ( CWater::m_iInstanceCounter
    && BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 876, "m_iInstanceCounter == 0") == 1 )
  {
    __debugbreak();
  }
  if ( CWater::m_iInitialized && BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 877, "!m_iInitialized") == 1 )
    __debugbreak();
  ++CWater::m_iInstanceCounter;
  return this;
}


// address=[0x15fc860]
// Decompiled from int __thiscall CWater::~CWater(CWater *this)
 CWater::~CWater(void) {
  
  int result; // eax

  if ( CWater::m_iInstanceCounter != 1
    && BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 889, "m_iInstanceCounter == 1") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  --CWater::m_iInstanceCounter;
  return result;
}


// address=[0x15fc8d0]
// Decompiled from int __cdecl CWater::Init(unsigned __int16 *a1)
void __cdecl CWater::Init(unsigned short * a1) {
  
  int result; // eax

  CWater::Done();
  CWaterFlags::Init(a1);
  result = CShipMap::Init();
  CWater::m_iInitialized = 1;
  return result;
}


// address=[0x15fc900]
// Decompiled from int CWater::Done()
void __cdecl CWater::Done(void) {
  
  int result; // eax

  if ( !CWater::m_iInitialized )
    return result;
  CShipMap::Done();
  result = CWaterFlags::Done();
  CWater::m_iInitialized = 0;
  return result;
}


// address=[0x15fc930]
// Decompiled from char __cdecl CWater::PlaceShip(int a1)
bool __cdecl CWater::PlaceShip(int a1) {
  
  int v2; // [esp+0h] [ebp-Ch]
  int v3; // [esp+4h] [ebp-8h]
  int v4; // [esp+8h] [ebp-4h]

  v3 = Y16X16::UnpackXFast(a1);
  v4 = Y16X16::UnpackYFast(a1);
  v2 = CWorldManager::Index(v3, v4);
  if ( !CWaterFlags::IsFreeWater(v2) )
    return 0;
  if ( !CShipMap::PlaceShip(a1) )
    return 0;
  CWaterFlags::PlaceShip(a1);
  return 1;
}


// address=[0x15fc9b0]
// Decompiled from bool __cdecl CWater::IsPlaceShipOk(int a1)
bool __cdecl CWater::IsPlaceShipOk(int a1) {
  
  int v2; // [esp+0h] [ebp-10h]
  int v3; // [esp+4h] [ebp-Ch]
  int v4; // [esp+8h] [ebp-8h]

  v2 = Y16X16::UnpackXFast(a1);
  v3 = Y16X16::UnpackYFast(a1);
  v4 = CWorldManager::Index(v2, v3);
  if ( !CWaterFlags::IsFreeWater(v4) )
    return 0;
  if ( CWorldManager::MapObjectId(v4) )
    BBSupportTracePrintF(1, " g_cWorld.MapObjectId(iWorldIdx)==0 failed");
  return CShipMap::GetEntryForPlaceShip(a1) != 0;
}


// address=[0x15fca50]
// Decompiled from char __cdecl CWater::RemoveShip(int a1)
bool __cdecl CWater::RemoveShip(int a1) {
  
  if ( !CShipMap::RemoveShip(a1) )
    return 0;
  CWaterFlags::RemoveShip(a1);
  return 1;
}


// address=[0x15fca80]
// Decompiled from char __cdecl CWater::MoveShip(int a1, int a2)
bool __cdecl CWater::MoveShip(int a1, int a2) {
  
  bool v3; // [esp+1h] [ebp-1h]

  if ( !CShipMap::InShipList(a2)
    && BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 1009, "g_cShipMap.InShipList(_iOldXY)") == 1 )
  {
    __debugbreak();
  }
  v3 = CWater::RemoveShip(a2);
  if ( !v3 && BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 1013, "bRemoved") == 1 )
    __debugbreak();
  if ( CShipMap::InShipList(a2)
    && BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 1014, "!g_cShipMap.InShipList(_iOldXY)") == 1 )
  {
    __debugbreak();
  }
  if ( CWater::PlaceShip(a1) )
  {
    if ( !CShipMap::InShipList(a1)
      && BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 1018, "g_cShipMap.InShipList(_iNewXY)") == 1 )
    {
      __debugbreak();
    }
    return 1;
  }
  else
  {
    if ( CShipMap::InShipList(a1)
      && BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 1024, "!g_cShipMap.InShipList(_iNewXY)") == 1 )
    {
      __debugbreak();
    }
    if ( v3 )
      CWater::PlaceShip(a2);
    if ( !CShipMap::InShipList(a2)
      && BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 1031, "g_cShipMap.InShipList(_iOldXY)") == 1 )
    {
      __debugbreak();
    }
    return 0;
  }
}


// address=[0x15fcbf0]
// Decompiled from bool __cdecl CWater::PlacePseudoShip(int a1)
bool __cdecl CWater::PlacePseudoShip(int a1) {
  
  int v2; // [esp+0h] [ebp-10h]
  int v3; // [esp+8h] [ebp-8h]
  int v4; // [esp+Ch] [ebp-4h]

  v3 = Y16X16::UnpackXFast(a1);
  v4 = Y16X16::UnpackYFast(a1);
  if ( !(unsigned __int8)CWorldManager::InWorld(v3, v4)
    && BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 1047, "g_cWorld.InWorld(iX, iY)") == 1 )
  {
    __debugbreak();
  }
  v2 = CWorldManager::Index(v3, v4);
  return CWorldManager::MapObjectId(v2) && CWater::PlaceShip(a1);
}


// address=[0x15fcca0]
// Decompiled from bool __cdecl CWater::RemovePseudoShip(int a1)
bool __cdecl CWater::RemovePseudoShip(int a1) {
  
  int v2; // [esp+0h] [ebp-10h]
  int v3; // [esp+8h] [ebp-8h]
  int v4; // [esp+Ch] [ebp-4h]

  v3 = Y16X16::UnpackXFast(a1);
  v4 = Y16X16::UnpackYFast(a1);
  if ( !(unsigned __int8)CWorldManager::InWorld(v3, v4)
    && BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 1069, "g_cWorld.InWorld(iX, iY)") == 1 )
  {
    __debugbreak();
  }
  v2 = CWorldManager::Index(v3, v4);
  return CWorldManager::MapObjectId(v2) && CWater::RemoveShip(a1);
}


// address=[0x4617a9c]
// [Decompilation failed for static int CWater::m_iInstanceCounter]

// address=[0x4617aa0]
// [Decompilation failed for static int CWater::m_iInitialized]

