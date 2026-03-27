#include "SSaveData.h"

// Definitions for class SSaveData

// address=[0x16a7170]
// Decompiled from bool __thiscall TSparseMap<unsigned char>::SSaveData::IsBufferEnd(TSparseMap::SSaveData *this)
bool  TSparseMap<unsigned char>::SSaveData::IsBufferEnd(void)const {
  
  return !LOBYTE(this->m_iData) && this->m_iX == -1 && this->m_iY == -1;
}


// address=[0x16a7850]
// Decompiled from void __thiscall TSparseMap<unsigned char>::SSaveData::SetAsBufferEnd(TSparseMap::SSaveData *this)
void  TSparseMap<unsigned char>::SSaveData::SetAsBufferEnd(void) {
  
  LOBYTE(this->m_iData) = 0;
  this->m_iX = -1;
  this->m_iY = -1;
}


