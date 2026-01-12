#include "LZHLDecoderStat.h"

// Definitions for class LZHLDecoderStat

// address=[0x2f2b470]
// Decompiled from LZHLDecoderStat *__thiscall LZHLDecoderStat::LZHLDecoderStat(LZHLDecoderStat *this)

 LZHLDecoderStat::LZHLDecoderStat(void) {
  
  HuffStat::HuffStat(this);
  *((_DWORD *)this + 33) = operator new[](0x224u);
  qmemcpy(*((void **)this + 33), &LZHLDecoderStat::symbolTable0, 0x224u);
  qmemcpy((char *)this + 4, &LZHLDecoderStat::groupTable0, 0x80u);
  return this;
}


// address=[0x2f2b510]
// Decompiled from int __thiscall LZHLDecoderStat::~LZHLDecoderStat(void **this)

 LZHLDecoderStat::~LZHLDecoderStat(void) {
  
  operator delete[](this[33]);
  return HuffStat::~HuffStat(this);
}


// address=[0x3e2d7d8]
// [Decompilation failed for static struct LZHLDecoderStat::Group * LZHLDecoderStat::groupTable0]

// address=[0x3e2d858]
// [Decompilation failed for static short * LZHLDecoderStat::symbolTable0]

