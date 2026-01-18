#include "CRCTable.h"

// Definitions for class CRCTable

// address=[0x13e4be0]
// Decompiled from _DWORD *__thiscall cdm_crc::CRCGenerator<16,32773,0,0,1,1>::CRCTable::CRCTable(_DWORD *this)
 cdm_crc::CRCGenerator<16,32773,0,0,1,1>::CRCTable::CRCTable(void) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 256; ++i )
    this[i] = cdm_crc::CRCGenerator<16,32773,0,0,1,1>::CRCTable::CalcTableEntry(i);
  return this;
}


// address=[0x13e56b0]
// Decompiled from int __thiscall cdm_crc::CRCGenerator<16,32773,0,0,1,1>::CRCTable::operator[](_DWORD *this, int a2)
unsigned long  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::CRCTable::operator[](int a2)const {
  
  return this[a2];
}


// address=[0x13e6470]
// Decompiled from int __stdcall cdm_crc::CRCGenerator<16,32773,0,0,1,1>::CRCTable::CalcTableEntry(int a1)
unsigned long  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::CRCTable::CalcTableEntry(int a1) {
  
  int v2; // [esp+4h] [ebp-10h]
  int i; // [esp+8h] [ebp-Ch]
  int v4; // [esp+Ch] [ebp-8h]
  int v5; // [esp+10h] [ebp-4h]
  int v6; // [esp+10h] [ebp-4h]

  v4 = cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Reflect(a1, 8);
  v2 = cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Bitmask(15);
  v5 = v4 << 8;
  for ( i = 0; i < 8; ++i )
  {
    if ( (v2 & v5) != 0 )
      v5 = (2 * v5) ^ 0x8005;
    else
      v5 *= 2;
  }
  v6 = cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Reflect(v5, 16);
  return v6 & cdm_crc::CRCGenerator<16,32773,0,0,1,1>::WidthMask(16);
}


