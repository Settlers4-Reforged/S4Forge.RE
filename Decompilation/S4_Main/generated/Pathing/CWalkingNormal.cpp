#include "CWalkingNormal.h"

// Definitions for class CWalkingNormal

// address=[0x15f9070]
// Decompiled from CWalkingNormal *__thiscall CWalkingNormal::CWalkingNormal(CWalkingNormal *this, int a2)
 CWalkingNormal::CWalkingNormal(int a2) {
  
  CWalkingBase::CWalkingBase(this, 0, a2);
  *(_DWORD *)this = &CWalkingNormal::_vftable_;
  *((_DWORD *)this + 13) = *((_DWORD *)this + 13);
  return this;
}


// address=[0x15faf90]
// Decompiled from CWalking *__thiscall CWalkingNormal::~CWalkingNormal(CWalkingNormal *this)
 CWalkingNormal::~CWalkingNormal(void) {
  
  return CWalkingBase::~CWalkingBase(this);
}


// address=[0x15fb260]
// Decompiled from int CWalkingNormal::GetWalkingType()
enum T_WALKING_TYPE const  CWalkingNormal::GetWalkingType(void) {
  
  return 0;
}


