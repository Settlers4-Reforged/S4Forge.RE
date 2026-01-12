#include "CTilingWorld.h"

// Definitions for class CTilingWorld

// address=[0x15f5b60]
// Decompiled from int __cdecl CTilingWorld::WorldGroundType(int a1)
static int __cdecl CTilingWorld::WorldGroundType(int) {
  
  return *(unsigned __int8 *)(CTilingWorld::m_pWorldGfxMapElements + 4 * a1 + 1);
}


// address=[0x15f5bd0]
// Decompiled from BOOL __cdecl CTilingWorld::WorldInInnerWorld16(int a1, int a2)
static bool __cdecl CTilingWorld::WorldInInnerWorld16(int,int) {
  
  return a2 - 16 < (unsigned int)(CTilingWorld::m_uWorldWidthHeight - 32)
      && a1 - 2 < (unsigned int)(CTilingWorld::m_uWorldWidthHeight - 16);
}


// address=[0x15f5c40]
// Decompiled from BOOL __cdecl CTilingWorld::WorldInInnerWorld1(int a1, int a2)
static bool __cdecl CTilingWorld::WorldInInnerWorld1(int,int) {
  
  return a2 - 1 < (unsigned int)(CTilingWorld::m_uWorldWidthHeight - 2)
      && a1 - 1 < (unsigned int)(CTilingWorld::m_uWorldWidthHeight - 2);
}


// address=[0x15f5cb0]
// Decompiled from BOOL __cdecl CTilingWorld::WorldInInnerWorld2(int a1, int a2)
static bool __cdecl CTilingWorld::WorldInInnerWorld2(int,int) {
  
  return a2 - 2 < (unsigned int)(CTilingWorld::m_uWorldWidthHeight - 4)
      && a1 - 2 < (unsigned int)(CTilingWorld::m_uWorldWidthHeight - 4);
}


// address=[0x15f5d20]
// Decompiled from BOOL __cdecl CTilingWorld::WorldInWorld(unsigned int a1, unsigned int a2)
static bool __cdecl CTilingWorld::WorldInWorld(int,int) {
  
  return a2 < CTilingWorld::m_uWorldWidthHeight && a1 < CTilingWorld::m_uWorldWidthHeight;
}


// address=[0x15f5d80]
// Decompiled from BOOL __cdecl CTilingWorld::WorldInWorldPackedXY(int a1)
static bool __cdecl CTilingWorld::WorldInWorldPackedXY(int) {
  
  return a1 >> 16 < (unsigned int)CTilingWorld::m_uWorldWidthHeight
      && (unsigned __int16)a1 < (unsigned int)CTilingWorld::m_uWorldWidthHeight;
}


// address=[0x15f5df0]
// Decompiled from int __cdecl CTilingWorld::WorldIndex(int a1)
static int __cdecl CTilingWorld::WorldIndex(int) {
  
  return CTilingWorld::m_uWorldWidthHeight * (a1 >> 16) + (unsigned __int16)a1;
}


// address=[0x15f5e20]
// Decompiled from int __cdecl CTilingWorld::WorldIndex(int a1, int a2)
static int __cdecl CTilingWorld::WorldIndex(int,int) {
  
  return a1 + a2 * CTilingWorld::m_uWorldWidthHeight;
}


// address=[0x15f5e40]
// Decompiled from bool __cdecl CTilingWorld::WorldIsBlockedLand(int a1)
static bool __cdecl CTilingWorld::WorldIsBlockedLand(int) {
  
  return (*(_BYTE *)(a1 + CTilingWorld::m_pWorldFlagBitsLayer) & 1) != 0;
}


// address=[0x15f5e80]
// Decompiled from bool __cdecl CTilingWorld::WorldIsBuildingOrDecoObjectBitSet(int a1)
static bool __cdecl CTilingWorld::WorldIsBuildingOrDecoObjectBitSet(int) {
  
  return (*(_BYTE *)(a1 + CTilingWorld::m_pWorldFlagBitsLayer) & 0x48) != 0;
}


// address=[0x15f5ec0]
// Decompiled from BOOL __cdecl CTilingWorld::WorldIsGroundTypeWater(int a1)
static int __cdecl CTilingWorld::WorldIsGroundTypeWater(int) {
  
  return CLandscapeProperties::IsWater(a1);
}


// address=[0x15f5ee0]
// Decompiled from bool __cdecl CTilingWorld::WorldIsWater(int a1)
static bool __cdecl CTilingWorld::WorldIsWater(int) {
  
  return CLandscapeProperties::IsWater(*(unsigned __int8 *)(CTilingWorld::m_pWorldGfxMapElements + 4 * a1 + 1));
}


// address=[0x15f5f10]
// Decompiled from int __cdecl CTilingWorld::WorldNeighborRelIndex(int a1)
static int __cdecl CTilingWorld::WorldNeighborRelIndex(int) {
  
  return CTilingWorld::m_iWorldNeighborRelIndices[a1];
}


// address=[0x15f5f30]
// Decompiled from int CTilingWorld::WorldNumberOfElements()
static int __cdecl CTilingWorld::WorldNumberOfElements(void) {
  
  return CTilingWorld::m_uWorldSize;
}


// address=[0x15f6030]
// Decompiled from int __cdecl CTilingWorld::WorldSortedNeighborRelIndex(int a1)
static int __cdecl CTilingWorld::WorldSortedNeighborRelIndex(int) {
  
  return CTilingWorld::m_iWorldSortedNeighborRelIndices[a1];
}


// address=[0x15f6050]
// Decompiled from int __cdecl CTilingWorld::WorldSurroundingRelIndex(int a1)
static int __cdecl CTilingWorld::WorldSurroundingRelIndex(int) {
  
  return CTilingWorld::m_iWorldSurroundingRelIndices[a1];
}


// address=[0x15f6070]
// Decompiled from int CTilingWorld::WorldWidthHeight()
static int __cdecl CTilingWorld::WorldWidthHeight(void) {
  
  return CTilingWorld::m_uWorldWidthHeight;
}


// address=[0x42cf8e0]
// [Decompilation failed for static int CTilingWorld::m_iWorldInterfaceInitialized]

// address=[0x42cf8e4]
// [Decompilation failed for static unsigned int CTilingWorld::m_uWorldWidthHeight]

// address=[0x42cf8e8]
// [Decompilation failed for static unsigned int CTilingWorld::m_uWorldSize]

// address=[0x42cf8ec]
// [Decompilation failed for static struct T_GFX_MAP_ELEMENT * CTilingWorld::m_pWorldGfxMapElements]

// address=[0x42cf8f0]
// [Decompilation failed for static unsigned char * CTilingWorld::m_pWorldFlagBitsLayer]

// address=[0x42cf8f4]
// [Decompilation failed for static unsigned char * CTilingWorld::m_pWorldFogLayer]

// address=[0x42cf8f8]
// [Decompilation failed for static int * CTilingWorld::m_iWorldNeighborRelIndices]

// address=[0x42cf928]
// [Decompilation failed for static int * CTilingWorld::m_iWorldSortedNeighborRelIndices]

// address=[0x42cf940]
// [Decompilation failed for static int * CTilingWorld::m_iWorldSurroundingRelIndices]

// address=[0x15e75d0]
// Decompiled from int __cdecl CTilingWorld::WorldInterfaceInit(  int a1,  struct T_GFX_MAP_ELEMENT *a2,  unsigned __int8 *a3,  unsigned __int8 *a4)
static void __cdecl CTilingWorld::WorldInterfaceInit(int,struct T_GFX_MAP_ELEMENT *,unsigned char *,unsigned char *) {
  
  int v4; // ecx
  int v5; // edx
  int result; // eax
  int v7; // esi
  int v8; // [esp+4h] [ebp-Ch]
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( a1 < 16
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 317, "_iWorldWidthHeight >= Squares::SQUARE_WIDTH_HEIGHT") == 1 )
  {
    __debugbreak();
  }
  if ( a1 > 1024
    && BBSupportDbgReport(
         2,
         "Pathing\\Tiling.cpp",
         318,
         "_iWorldWidthHeight <= Squares::SQUARE_MAX_SUPPORTED_MAP_WIDTH_HEIGHT") == 1 )
  {
    __debugbreak();
  }
  if ( a1 % 16
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 319, "(_iWorldWidthHeight % Squares::SQUARE_WIDTH_HEIGHT) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( !a2 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 321, "_pGfxMapElements != 0") == 1 )
    __debugbreak();
  v4 = 0;
  if ( !a3 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 322, "_pFlagBitsLayer != 0") == 1 )
    __debugbreak();
  v5 = 0;
  if ( !a4 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 323, "_pFogLayer != 0") == 1 )
    __debugbreak();
  CTilingWorld::WorldInterfaceDone(v4, v5);
  CTilingWorld::m_uWorldWidthHeight = a1;
  CTilingWorld::m_uWorldSize = a1 * a1;
  CTilingWorld::m_pWorldGfxMapElements = (int)a2;
  CTilingWorld::m_pWorldFlagBitsLayer = (int)a3;
  CTilingWorld::m_pWorldFogLayer = (int)a4;
  for ( i = 0; i < 6; ++i )
  {
    v8 = g_sNeighborPoints[2 * i] + dword_37D8C0C[2 * i] * a1;
    CTilingWorld::m_iWorldNeighborRelIndices[i] = v8;
    dword_42CF910[i] = v8;
  }
  CTilingWorld::m_iWorldSortedNeighborRelIndices[0] = -a1 - 1;
  CTilingWorld::m_iWorldSortedNeighborRelIndices[1] = -a1;
  CTilingWorld::m_iWorldSortedNeighborRelIndices[2] = -1;
  CTilingWorld::m_iWorldSortedNeighborRelIndices[3] = 1;
  CTilingWorld::m_iWorldSortedNeighborRelIndices[4] = a1;
  CTilingWorld::m_iWorldSortedNeighborRelIndices[5] = a1 + 1;
  if ( CTilingWorld::m_iWorldSortedNeighborRelIndices[0] >= CTilingWorld::m_iWorldSortedNeighborRelIndices[1]
    && BBSupportDbgReport(
         2,
         "Pathing\\Tiling.cpp",
         351,
         "m_iWorldSortedNeighborRelIndices[0] < m_iWorldSortedNeighborRelIndices[1]") == 1 )
  {
    __debugbreak();
  }
  if ( CTilingWorld::m_iWorldSortedNeighborRelIndices[1] >= CTilingWorld::m_iWorldSortedNeighborRelIndices[2]
    && BBSupportDbgReport(
         2,
         "Pathing\\Tiling.cpp",
         352,
         "m_iWorldSortedNeighborRelIndices[1] < m_iWorldSortedNeighborRelIndices[2]") == 1 )
  {
    __debugbreak();
  }
  if ( CTilingWorld::m_iWorldSortedNeighborRelIndices[2] >= CTilingWorld::m_iWorldSortedNeighborRelIndices[3]
    && BBSupportDbgReport(
         2,
         "Pathing\\Tiling.cpp",
         353,
         "m_iWorldSortedNeighborRelIndices[2] < m_iWorldSortedNeighborRelIndices[3]") == 1 )
  {
    __debugbreak();
  }
  if ( CTilingWorld::m_iWorldSortedNeighborRelIndices[3] >= CTilingWorld::m_iWorldSortedNeighborRelIndices[4]
    && BBSupportDbgReport(
         2,
         "Pathing\\Tiling.cpp",
         354,
         "m_iWorldSortedNeighborRelIndices[3] < m_iWorldSortedNeighborRelIndices[4]") == 1 )
  {
    __debugbreak();
  }
  if ( CTilingWorld::m_iWorldSortedNeighborRelIndices[4] >= CTilingWorld::m_iWorldSortedNeighborRelIndices[5]
    && BBSupportDbgReport(
         2,
         "Pathing\\Tiling.cpp",
         355,
         "m_iWorldSortedNeighborRelIndices[4] < m_iWorldSortedNeighborRelIndices[5]") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  for ( j = 0; j < 19; ++j )
  {
    v7 = CSpiralOffsets::DeltaX(j);
    CTilingWorld::m_iWorldSurroundingRelIndices[j] = a1 * CSpiralOffsets::DeltaY(j) + v7;
    result = j + 1;
  }
  CTilingWorld::m_iWorldInterfaceInitialized = 1;
  return result;
}


// address=[0x15e7960]
// Decompiled from void CTilingWorld::WorldInterfaceDone()
static void __cdecl CTilingWorld::WorldInterfaceDone(void) {
  
  if ( CTilingWorld::m_iWorldInterfaceInitialized )
  {
    CTilingWorld::m_iWorldInterfaceInitialized = 0;
    CTilingWorld::m_uWorldWidthHeight = 0;
    CTilingWorld::m_uWorldSize = 0;
    CTilingWorld::m_pWorldGfxMapElements = 0;
    CTilingWorld::m_pWorldFlagBitsLayer = 0;
  }
}


// address=[0x15f5b00]
// Decompiled from int __cdecl CTilingWorld::WorldClearBlockedLandFlag(int a1)
static void __cdecl CTilingWorld::WorldClearBlockedLandFlag(int) {
  
  int result; // eax

  result = a1 + CTilingWorld::m_pWorldFlagBitsLayer;
  *(_BYTE *)(a1 + CTilingWorld::m_pWorldFlagBitsLayer) &= ~1u;
  return result;
}


// address=[0x15f5b30]
// Decompiled from int __cdecl CTilingWorld::WorldClearGfxBorderstoneBit(int a1)
static void __cdecl CTilingWorld::WorldClearGfxBorderstoneBit(int) {
  
  int result; // eax

  result = a1;
  *(_BYTE *)(CTilingWorld::m_pWorldGfxMapElements + 4 * a1 + 3) &= ~0x80u;
  return result;
}


// address=[0x15f5fd0]
// Decompiled from int __cdecl CTilingWorld::WorldSetBlockedLandFlag(int a1)
static void __cdecl CTilingWorld::WorldSetBlockedLandFlag(int) {
  
  int result; // eax

  result = a1 + CTilingWorld::m_pWorldFlagBitsLayer;
  *(_BYTE *)(a1 + CTilingWorld::m_pWorldFlagBitsLayer) |= 1u;
  return result;
}


// address=[0x15f6000]
// Decompiled from int __cdecl CTilingWorld::WorldSetGfxBorderstoneBit(int a1)
static void __cdecl CTilingWorld::WorldSetGfxBorderstoneBit(int) {
  
  int result; // eax

  result = a1;
  *(_BYTE *)(CTilingWorld::m_pWorldGfxMapElements + 4 * a1 + 3) |= 0x80u;
  return result;
}


