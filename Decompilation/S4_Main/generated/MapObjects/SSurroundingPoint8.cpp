#if FALSE
#include "SSurroundingPoint8.h"

// Definitions for class SSurroundingPoint8

// address=[0x132ee80]
// Decompiled from int __thiscall SSurroundingPoint8::X(SSurroundingPoint8 *this)
int  SSurroundingPoint8::X(void)const {
  
  return this->m_iX;
}


// address=[0x132eea0]
// Decompiled from int __thiscall SSurroundingPoint8::Y(SSurroundingPoint8 *this)
int  SSurroundingPoint8::Y(void)const {
  
  return this->m_iY;
}


// address=[0x15ddca0]
// Decompiled from const struct SPoint8 *__thiscall SSurroundingPoint8::Point(SSurroundingPoint8 *this)
struct SPoint8 const &  SSurroundingPoint8::Point(void)const {
  
  return (const struct SPoint8 *)this;
}


// address=[0x15ddcc0]
// Decompiled from int __thiscall SSurroundingPoint8::Radius(SSurroundingPoint8 *this)
int  SSurroundingPoint8::Radius(void)const {
  
  return (unsigned __int8)this->m_iRadius;
}


#endif // Already implemented
