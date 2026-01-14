#include "all_headers.h"

// Definitions for class CDarkConvert

// address=[0x15413d0]
// Decompiled from int __cdecl CDarkConvert::GetGreenObject(int a1)
static int __cdecl CDarkConvert::GetGreenObject(int) {
  
  int i; // [esp+0h] [ebp-4h]

  for ( i = 0; CDarkConvert::m_aiConvTable[2 * i]; ++i )
  {
    if ( CDarkConvert::m_aiConvTable[2 * i + 1] == a1 )
      return CDarkConvert::m_aiConvTable[2 * i];
  }
  return 0;
}


// address=[0x1541430]
// Decompiled from int __cdecl CDarkConvert::GetDarkObject(int a1)
static int __cdecl CDarkConvert::GetDarkObject(int) {
  
  int i; // [esp+0h] [ebp-4h]

  for ( i = 0; CDarkConvert::m_aiConvTable[2 * i]; ++i )
  {
    if ( CDarkConvert::m_aiConvTable[2 * i] == a1 )
      return CDarkConvert::m_aiConvTable[2 * i + 1];
  }
  return 0;
}


// address=[0x3d8b890]
// [Decompilation failed for static int (* CDarkConvert::m_aiConvTable)[2]]

