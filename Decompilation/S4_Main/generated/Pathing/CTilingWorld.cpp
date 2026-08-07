#if FALSE
#include "CTilingWorld.h"

// Definitions for class CTilingWorld

// address=[0x15f5b60]
// Decompiled from int __cdecl CTilingWorld::WorldGroundType(int a1)
int __cdecl CTilingWorld::WorldGroundType(int a1) {
  
  return m_pWorldGfxMapElements[a1].m_uGroundType;
}


// address=[0x15f5bd0]
// Decompiled from BOOL __cdecl CTilingWorld::WorldInInnerWorld16(int a1, int a2)
bool __cdecl CTilingWorld::WorldInInnerWorld16(int a1, int a2) {
  
  return a2 - 16 < (unsigned int)(CTilingWorld::m_uWorldWidthHeight - 32) && a1 - 2 < (unsigned int)(CTilingWorld::m_uWorldWidthHeight - 16);
}


// address=[0x15f5c40]
// Decompiled from BOOL __cdecl CTilingWorld::WorldInInnerWorld1(int a1, int a2)
bool __cdecl CTilingWorld::WorldInInnerWorld1(int a1, int a2) {
  
  return a2 - 1 < (unsigned int)(CTilingWorld::m_uWorldWidthHeight - 2) && a1 - 1 < (unsigned int)(CTilingWorld::m_uWorldWidthHeight - 2);
}


// address=[0x15f5cb0]
// Decompiled from BOOL __cdecl CTilingWorld::WorldInInnerWorld2(int a1, int a2)
bool __cdecl CTilingWorld::WorldInInnerWorld2(int a1, int a2) {
  
  return a2 - 2 < (unsigned int)(CTilingWorld::m_uWorldWidthHeight - 4) && a1 - 2 < (unsigned int)(CTilingWorld::m_uWorldWidthHeight - 4);
}


// address=[0x15f5d20]
// Decompiled from BOOL __cdecl CTilingWorld::WorldInWorld(unsigned int a1, unsigned int a2)
bool __cdecl CTilingWorld::WorldInWorld(int a1, int a2) {
  
  return a2 < CTilingWorld::m_uWorldWidthHeight && a1 < CTilingWorld::m_uWorldWidthHeight;
}


// address=[0x15f5d80]
// Decompiled from BOOL __cdecl CTilingWorld::WorldInWorldPackedXY(int a1)
bool __cdecl CTilingWorld::WorldInWorldPackedXY(int a1) {
  
  return a1 >> 16 < (unsigned int)CTilingWorld::m_uWorldWidthHeight && (unsigned __int16)a1 < (unsigned int)CTilingWorld::m_uWorldWidthHeight;
}


// address=[0x15f5df0]
// Decompiled from int __cdecl CTilingWorld::WorldIndex(int a1)
int __cdecl CTilingWorld::WorldIndex(int a1) {
  
  return CTilingWorld::m_uWorldWidthHeight * (a1 >> 16) + (unsigned __int16)a1;
}


// address=[0x15f5e20]
// Decompiled from int __cdecl CTilingWorld::WorldIndex(int a1, int a2)
int __cdecl CTilingWorld::WorldIndex(int a1, int a2) {
  
  return a1 + a2 * CTilingWorld::m_uWorldWidthHeight;
}


// address=[0x15f5e40]
// Decompiled from bool __cdecl CTilingWorld::WorldIsBlockedLand(int a1)
bool __cdecl CTilingWorld::WorldIsBlockedLand(int a1) {
  
  return (*(_BYTE *)(a1 + CTilingWorld::m_pWorldFlagBitsLayer) & 1) != 0;
}


// address=[0x15f5e80]
// Decompiled from bool __cdecl CTilingWorld::WorldIsBuildingOrDecoObjectBitSet(int a1)
bool __cdecl CTilingWorld::WorldIsBuildingOrDecoObjectBitSet(int a1) {
  
  return (*(_BYTE *)(a1 + CTilingWorld::m_pWorldFlagBitsLayer) & 0x48) != 0;
}


// address=[0x15f5ec0]
// Decompiled from BOOL __cdecl CTilingWorld::WorldIsGroundTypeWater(int a1)
int __cdecl CTilingWorld::WorldIsGroundTypeWater(int a1) {
  
  return CLandscapeProperties::IsWater(a1);
}


// address=[0x15f5ee0]
// Decompiled from bool __cdecl CTilingWorld::WorldIsWater(int a1)
bool __cdecl CTilingWorld::WorldIsWater(int a1) {
  
  return CLandscapeProperties::IsWater(*(unsigned __int8 *)(m_pWorldGfxMapElements + 4 * a1 + 1));
}


// address=[0x15f5f10]
// Decompiled from int __cdecl CTilingWorld::WorldNeighborRelIndex(int a1)
int __cdecl CTilingWorld::WorldNeighborRelIndex(int a1) {
  
  return CTilingWorld::m_iWorldNeighborRelIndices[a1];
}


// address=[0x15f5f30]
// Decompiled from int CTilingWorld::WorldNumberOfElements()
int __cdecl CTilingWorld::WorldNumberOfElements(void) {
  
  return CTilingWorld::m_uWorldSize;
}


// address=[0x15f6030]
// Decompiled from int __cdecl CTilingWorld::WorldSortedNeighborRelIndex(int a1)
int __cdecl CTilingWorld::WorldSortedNeighborRelIndex(int a1) {
  
  return CTilingWorld::m_iWorldSortedNeighborRelIndices[a1];
}


// address=[0x15f6050]
// Decompiled from int __cdecl CTilingWorld::WorldSurroundingRelIndex(int a1)
int __cdecl CTilingWorld::WorldSurroundingRelIndex(int a1) {
  
  return CTilingWorld::m_iWorldSurroundingRelIndices[a1];
}


// address=[0x15f6070]
// Decompiled from int CTilingWorld::WorldWidthHeight()
int __cdecl CTilingWorld::WorldWidthHeight(void) {
  
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
// Decompiled from void __cdecl CTilingWorld::WorldInterfaceInit(int _iWorldWidthHeight, struct T_GFX_MAP_ELEMENT *_pGfxMapElements, unsigned __int8 *_pFlagBitsLayer, unsigned __int8 *_pFogLayer)
void __cdecl CTilingWorld::WorldInterfaceInit(int _iWorldWidthHeight, struct T_GFX_MAP_ELEMENT * _pGfxMapElements, unsigned char * _pFlagBitsLayer, unsigned char * _pFogLayer) {
  
  int v4; // esi
  int v5; // [esp+4h] [ebp-Ch]
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( _iWorldWidthHeight < 16 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 317, "_iWorldWidthHeight >= Squares::SQUARE_WIDTH_HEIGHT") == 1 )
  {
    __debugbreak();
  }
  if ( _iWorldWidthHeight > 1024 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 318, "_iWorldWidthHeight <= Squares::SQUARE_MAX_SUPPORTED_MAP_WIDTH_HEIGHT") == 1 )
  {
    __debugbreak();
  }
  if ( _iWorldWidthHeight % 16 && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 319, "(_iWorldWidthHeight % Squares::SQUARE_WIDTH_HEIGHT) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( !_pGfxMapElements && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 321, "_pGfxMapElements != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !_pFlagBitsLayer && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 322, "_pFlagBitsLayer != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !_pFogLayer && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 323, "_pFogLayer != 0") == 1 )
  {
    __debugbreak();
  }
  CTilingWorld::WorldInterfaceDone();
  CTilingWorld::m_uWorldWidthHeight = _iWorldWidthHeight;
  CTilingWorld::m_uWorldSize = _iWorldWidthHeight * _iWorldWidthHeight;
  m_pWorldGfxMapElements = _pGfxMapElements;
  CTilingWorld::m_pWorldFlagBitsLayer = _pFlagBitsLayer;
  CTilingWorld::m_pWorldFogLayer = _pFogLayer;
  for ( i = 0;
        i < 6;
        ++i )
  {
    v5 = g_sNeighborPoints[i].x + g_sNeighborPoints[i].y * _iWorldWidthHeight;
    CTilingWorld::m_iWorldNeighborRelIndices[i] = v5;
    dword_42CF910[i] = v5;
  }
  CTilingWorld::m_iWorldSortedNeighborRelIndices[0] = -_iWorldWidthHeight - 1;
  CTilingWorld::m_iWorldSortedNeighborRelIndices[1] = -_iWorldWidthHeight;
  CTilingWorld::m_iWorldSortedNeighborRelIndices[2] = -1;
  CTilingWorld::m_iWorldSortedNeighborRelIndices[3] = 1;
  CTilingWorld::m_iWorldSortedNeighborRelIndices[4] = _iWorldWidthHeight;
  CTilingWorld::m_iWorldSortedNeighborRelIndices[5] = _iWorldWidthHeight + 1;
  if ( CTilingWorld::m_iWorldSortedNeighborRelIndices[0] >= CTilingWorld::m_iWorldSortedNeighborRelIndices[1] && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 351, "m_iWorldSortedNeighborRelIndices[0] < m_iWorldSortedNeighborRelIndices[1]") == 1 )
  {
    __debugbreak();
  }
  if ( CTilingWorld::m_iWorldSortedNeighborRelIndices[1] >= CTilingWorld::m_iWorldSortedNeighborRelIndices[2] && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 352, "m_iWorldSortedNeighborRelIndices[1] < m_iWorldSortedNeighborRelIndices[2]") == 1 )
  {
    __debugbreak();
  }
  if ( CTilingWorld::m_iWorldSortedNeighborRelIndices[2] >= CTilingWorld::m_iWorldSortedNeighborRelIndices[3] && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 353, "m_iWorldSortedNeighborRelIndices[2] < m_iWorldSortedNeighborRelIndices[3]") == 1 )
  {
    __debugbreak();
  }
  if ( CTilingWorld::m_iWorldSortedNeighborRelIndices[3] >= CTilingWorld::m_iWorldSortedNeighborRelIndices[4] && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 354, "m_iWorldSortedNeighborRelIndices[3] < m_iWorldSortedNeighborRelIndices[4]") == 1 )
  {
    __debugbreak();
  }
  if ( CTilingWorld::m_iWorldSortedNeighborRelIndices[4] >= CTilingWorld::m_iWorldSortedNeighborRelIndices[5] && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 355, "m_iWorldSortedNeighborRelIndices[4] < m_iWorldSortedNeighborRelIndices[5]") == 1 )
  {
    __debugbreak();
  }
  for ( j = 0;
        j < 19;
        ++j )
  {
    v4 = CSpiralOffsets::DeltaX(j);
    CTilingWorld::m_iWorldSurroundingRelIndices[j] = _iWorldWidthHeight * CSpiralOffsets::DeltaY(j) + v4;
  }
  CTilingWorld::m_iWorldInterfaceInitialized = 1;
}


// address=[0x15e7960]
// Decompiled from void CTilingWorld::WorldInterfaceDone()
void __cdecl CTilingWorld::WorldInterfaceDone(void) {
  
  if ( CTilingWorld::m_iWorldInterfaceInitialized )
  {
    CTilingWorld::m_iWorldInterfaceInitialized = 0;
    CTilingWorld::m_uWorldWidthHeight = 0;
    CTilingWorld::m_uWorldSize = 0;
    m_pWorldGfxMapElements = 0;
    CTilingWorld::m_pWorldFlagBitsLayer = 0;
  }
}


// address=[0x15f5b00]
// Decompiled from void __cdecl CTilingWorld::WorldClearBlockedLandFlag(int a1)
void __cdecl CTilingWorld::WorldClearBlockedLandFlag(int a1) {
  
  CTilingWorld::m_pWorldFlagBitsLayer[a1] &= ~1u;
}


// address=[0x15f5b30]
// Decompiled from void __cdecl CTilingWorld::WorldClearGfxBorderstoneBit(int a1)
void __cdecl CTilingWorld::WorldClearGfxBorderstoneBit(int a1) {
  
  m_pWorldGfxMapElements[a1].m_uGfxBits &= ~0x80u;
}


// address=[0x15f5fd0]
// Decompiled from void __cdecl CTilingWorld::WorldSetBlockedLandFlag(int a1)
void __cdecl CTilingWorld::WorldSetBlockedLandFlag(int a1) {
  
  CTilingWorld::m_pWorldFlagBitsLayer[a1] |= 1u;
}


// address=[0x15f6000]
// Decompiled from int __cdecl CTilingWorld::WorldSetGfxBorderstoneBit(int a1)
void __cdecl CTilingWorld::WorldSetGfxBorderstoneBit(int a1) {
  
  int result; // eax

  result = a1;
  m_pWorldGfxMapElements[a1].m_uGfxBits |= 0x80u;
  return result;
}


#endif // Already implemented
