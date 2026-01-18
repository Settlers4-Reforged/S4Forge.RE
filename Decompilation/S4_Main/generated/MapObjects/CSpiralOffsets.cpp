#include "CSpiralOffsets.h"

// Definitions for class CSpiralOffsets

// address=[0x12fcfd0]
// Decompiled from int __cdecl CSpiralOffsets::DeltaX(int a1)
int __cdecl CSpiralOffsets::DeltaX(int a1) {
  
  return CSpiralOffsets::m_sOffsets[4 * a1];
}


// address=[0x12fcff0]
// Decompiled from int __cdecl CSpiralOffsets::DeltaY(int a1)
int __cdecl CSpiralOffsets::DeltaY(int a1) {
  
  return byte_3E39621[4 * a1];
}


// address=[0x1306680]
// Decompiled from int __cdecl CSpiralOffsets::First(int a1)
int __cdecl CSpiralOffsets::First(int a1) {
  
  return (unsigned __int16)CSpiralOffsets::m_sFirstLast[2 * a1];
}


// address=[0x1306730]
// Decompiled from int __cdecl CSpiralOffsets::Last(int a1)
int __cdecl CSpiralOffsets::Last(int a1) {
  
  return (unsigned __int16)word_3E394F2[2 * a1];
}


// address=[0x14fddb0]
// Decompiled from int __cdecl CSpiralOffsets::Radius(int a1)
int __cdecl CSpiralOffsets::Radius(int a1) {
  
  return (unsigned __int8)byte_3E39622[4 * a1];
}


// address=[0x1506400]
// Decompiled from int __cdecl CSpiralOffsets::Direction(int a1)
int __cdecl CSpiralOffsets::Direction(int a1) {
  
  return (unsigned __int8)byte_3E39623[4 * a1];
}


// address=[0x1568870]
// Decompiled from int __cdecl CSpiralOffsets::PseudoDistanceSquareEx(int a1, int a2)
int __cdecl CSpiralOffsets::PseudoDistanceSquareEx(int a1, int a2) {
  
  return 87 * a2 * 87 * a2 + (100 * a1 - 50 * a2) * (100 * a1 - 50 * a2);
}


// address=[0x16a74e0]
// Decompiled from int __cdecl CSpiralOffsets::MaxGridDistance(int a1)
int __cdecl CSpiralOffsets::MaxGridDistance(int a1) {
  
  return (unsigned __int8)CSpiralOffsets::m_uMaxDists[a1];
}


// address=[0x3e34770]
// [Decompilation failed for static unsigned char * CSpiralOffsets::m_uMaxDists]

// address=[0x3e394f0]
// [Decompilation failed for static struct CSpiralOffsets::SRadiusFirstLast * CSpiralOffsets::m_sFirstLast]

// address=[0x3e39620]
// [Decompilation failed for static struct CSpiralOffsets::SSprialOffset * CSpiralOffsets::m_sOffsets]

