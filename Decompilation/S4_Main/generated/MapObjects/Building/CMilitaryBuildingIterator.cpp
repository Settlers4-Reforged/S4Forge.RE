#include "CMilitaryBuildingIterator.h"

// Definitions for class CMilitaryBuildingIterator

// address=[0x1325bc0]
// Decompiled from CMilitaryBuildingIterator *__thiscall CMilitaryBuildingIterator::CMilitaryBuildingIterator(  CMilitaryBuildingIterator *this)
 CMilitaryBuildingIterator::CMilitaryBuildingIterator(void) {
  
  CGenericBuildingIterator::CGenericBuildingIterator(this);
  return this;
}


// address=[0x1326170]
// Decompiled from char __thiscall CMilitaryBuildingIterator::Init(CMilitaryBuildingIterator *this, int a2)
void  CMilitaryBuildingIterator::Init(int a2) {
  
  return CGenericBuildingIterator::Init(this, a2, 46, 48);
}


