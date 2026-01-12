#include "SSaveData.h"

// Definitions for class SSaveData

// address=[0x16a7170]
// Decompiled from bool __thiscall TSparseMap<unsigned char>::SSaveData::IsBufferEnd(_DWORD *this)

bool  TSparseMap<unsigned char>::SSaveData::IsBufferEnd(void)const {
  
  return !*(_BYTE *)this && this[1] == -1 && this[2] == -1;
}


// address=[0x16a7850]
// Decompiled from _DWORD *__thiscall TSparseMap<unsigned char>::SSaveData::SetAsBufferEnd(_DWORD *this)

void  TSparseMap<unsigned char>::SSaveData::SetAsBufferEnd(void) {
  
  _DWORD *result; // eax

  result = this;
  *(_BYTE *)this = 0;
  this[1] = -1;
  this[2] = -1;
  return result;
}


