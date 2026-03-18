#include "SPoint.h"

// Definitions for class SPoint

// address=[0x15ddb00]
// Decompiled from SPoint *__thiscall SPoint::operator=(SPoint *this, SPoint8 *a2)
struct SPoint &  SPoint::operator=(struct SPoint8 const & a2) {
  
  this->x = a2->x;
  this->y = a2->y;
  return this;
}


// address=[0x15ddb40]
// Decompiled from BOOL __thiscall SPoint::operator==(SPoint *this, SPoint *a2)
bool  SPoint::operator==(struct SPoint const & a2)const {
  
  return this->y == a2->y && this->x == a2->x;
}


// address=[0x15ddbb0]
// Decompiled from int __thiscall SPoint::operator*(SPoint *this, SPoint *a2)
int  SPoint::operator*(struct SPoint const & a2)const {
  
  return a2->y * this->y + a2->x * this->x;
}


// address=[0x15ddce0]
// Decompiled from int __thiscall SPoint::X(SPoint *this)
int  SPoint::X(void)const {
  
  return this->x;
}


// address=[0x15ddd00]
// Decompiled from int __thiscall SPoint::Y(SPoint *this)
int  SPoint::Y(void)const {
  
  return this->y;
}


// address=[0x15ddd20]
// Decompiled from SPoint *__thiscall SPoint::Zero(SPoint *this)
struct SPoint &  SPoint::Zero(void) {
  
  this->x = 0;
  this->y = 0;
  return this;
}


