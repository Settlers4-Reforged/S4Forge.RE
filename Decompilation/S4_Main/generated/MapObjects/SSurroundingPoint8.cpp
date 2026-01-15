#include "SSurroundingPoint8.h"

// Definitions for class SSurroundingPoint8

// address=[0x132ee80]
// Decompiled from int __thiscall SSurroundingPoint8::X(SSurroundingPoint8 *this)
int  SSurroundingPoint8::X(void)const {
  
  return *(char *)this;
}


// address=[0x132eea0]
// Decompiled from int __thiscall SSurroundingPoint8::Y(SSurroundingPoint8 *this)
int  SSurroundingPoint8::Y(void)const {
  
  return *((char *)this + 1);
}


// address=[0x15ddca0]
// Decompiled from SSurroundingPoint8 *__thiscall SSurroundingPoint8::Point(SSurroundingPoint8 *this)
struct SPoint8 const &  SSurroundingPoint8::Point(void)const {
  
  return this;
}


// address=[0x15ddcc0]
// Decompiled from int __thiscall SSurroundingPoint8::Radius(SSurroundingPoint8 *this)
int  SSurroundingPoint8::Radius(void)const {
  
  return *((unsigned __int8 *)this + 2);
}


