#include "CRandom16.h"

// Definitions for class CRandom16

// address=[0x12fd540]
// Decompiled from unsigned int __thiscall CRandom16::Rand(CRandom16 *this)
unsigned int CRandom16::Rand(void) {
  ++this->m_uIteration;
  this->m_uSeed = 1812433253 * this->m_uSeed + 1;
  return HIWORD(this->m_uSeed);
}


// address=[0x1301600]
// Decompiled from unsigned int __cdecl CRandom16::PercentValue(unsigned int a1)
unsigned int __cdecl CRandom16::PercentValue(unsigned int a1) {
  return (a1 << 16) / 0x64;
}


// address=[0x130a490]
// Decompiled from int __thiscall CRandom16::GetNumberOfRandCalls(CRandom16 *this)
unsigned int CRandom16::GetNumberOfRandCalls(void) const {
  return this->m_uIteration;
}


// address=[0x1311d70]
// Decompiled from int __thiscall CRandom16::GetSeed(CRandom16 *this)
unsigned int CRandom16::GetSeed(void) const {
  return this->m_uSeed;
}


// address=[0x13613b0]
// Decompiled from CRandom16 *__thiscall CRandom16::CRandom16(CRandom16 *this, int a2)
CRandom16::CRandom16(unsigned int a2) {
  this->m_uSeed = a2;
  this->m_uIteration = 0;
}


