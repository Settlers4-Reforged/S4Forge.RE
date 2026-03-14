#include "CAIEntityInfoTower.h"

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
  this->vftable = (CAIEntityInfoEx_vtbl *)&CAIEntityInfoTower::_vftable_;
  this->dword8 = 0;
  this->dwordC = 0;
  this->dword10 = 0;
  return this;
}


