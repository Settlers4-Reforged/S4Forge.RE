#include "COwnerMap.h"

// Definitions for class COwnerMap

// address=[0x13068b0]
// Decompiled from int __cdecl COwnerMap::OwnerBits1VW(int a1, int a2)

static int __cdecl COwnerMap::OwnerBits1VW(int,int) {
  
  return (unsigned __int8)COwnerMap::m_sOwnerBits[128 * a2 + 128 + 2 * a1];
}


// address=[0x13068d0]
// Decompiled from int __cdecl COwnerMap::OwnerBits9VW(int a1, int a2)

static int __cdecl COwnerMap::OwnerBits9VW(int,int) {
  
  return (unsigned __int8)byte_418FE61[128 * a2 + 128 + 2 * a1];
}


// address=[0x133a050]
// Decompiled from int __cdecl COwnerMap::OwnerBit(char a1)

static int __cdecl COwnerMap::OwnerBit(int) {
  
  return 1 << a1 >> 1;
}


// address=[0x1351d30]
// Decompiled from int __cdecl COwnerMap::OwnerBits1XY(Squares *a1, Squares *a2)

static int __cdecl COwnerMap::OwnerBits1XY(int,int) {
  
  int v2; // esi

  v2 = (Squares::XYToVW(a2) + 1) << 7;
  return (unsigned __int8)COwnerMap::m_sOwnerBits[2 * Squares::XYToVW(a1) + v2];
}


// address=[0x15afa20]
// Decompiled from int __cdecl COwnerMap::OwnerBits9XY(Squares *a1, Squares *a2)

static int __cdecl COwnerMap::OwnerBits9XY(int,int) {
  
  int v2; // esi

  v2 = (Squares::XYToVW(a2) + 1) << 7;
  return (unsigned __int8)byte_418FE61[2 * Squares::XYToVW(a1) + v2];
}


// address=[0x15de7d0]
// Decompiled from void *COwnerMap::ClearOwnerBits()

static void __cdecl COwnerMap::ClearOwnerBits(void) {
  
  return j__memset(COwnerMap::m_sOwnerBits, 0, 0x2100u);
}


// address=[0x15de7f0]
// Decompiled from char *__cdecl COwnerMap::OwnerBits1VWRef(int a1, int a2)

static unsigned char & __cdecl COwnerMap::OwnerBits1VWRef(int,int) {
  
  return &COwnerMap::m_sOwnerBits[128 * a2 + 128 + 2 * a1];
}


// address=[0x15de810]
// Decompiled from char *__cdecl COwnerMap::OwnerBits9VWRef(int a1, int a2)

static unsigned char & __cdecl COwnerMap::OwnerBits9VWRef(int,int) {
  
  return &byte_418FE61[128 * a2 + 128 + 2 * a1];
}


// address=[0x418fe60]
// [Decompilation failed for static struct COwnerMap::SOwnerBits (* COwnerMap::m_sOwnerBits)[64]]

