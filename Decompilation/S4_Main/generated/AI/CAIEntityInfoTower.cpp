#include "all_headers.h"

// Definitions for class CAIEntityInfoTower

// address=[0x130ad10]
// Decompiled from CAIEntityInfoEx *__thiscall CAIEntityInfoTower::~CAIEntityInfoTower(CAIEntityInfoTower *this)
 CAIEntityInfoTower::~CAIEntityInfoTower(void) {
  
  return CAIEntityInfoEx::~CAIEntityInfoEx(this);
}


// address=[0x130aba0]
// Decompiled from CAIEntityInfoTower *__thiscall CAIEntityInfoTower::CAIEntityInfoTower(CAIEntityInfoTower *this)
 CAIEntityInfoTower::CAIEntityInfoTower(void) {
  
  CAIEntityInfoEx::CAIEntityInfoEx(this, 0);
  *(_DWORD *)this = &CAIEntityInfoTower::_vftable_;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  return this;
}


