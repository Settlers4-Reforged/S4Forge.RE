#if FALSE
#include "CDirCache.h"

// Definitions for class CDirCache

// address=[0x15d6690]
// Decompiled from void __thiscall CDirCache::Init(CDirCache *this)
void  CDirCache::Init(void) {
  
  this->m_iCount = 0;
  this->m_iPointer = 15;
}


// address=[0x15d69a0]
// Decompiled from void __thiscall CDirCache::PushBack(CDirCache *this, BYTE a2)
void  CDirCache::PushBack(int a2) {
  
  this->m_iCount += this->m_iCount < 16u;
  this->m_iPointer = CDirCache::IncWrap(this->m_iPointer);
  this->m_aValues[this->m_iPointer] = a2;
}


// address=[0x15faff0]
// Decompiled from int __thiscall CDirCache::operator[](CDirCache *this, char a2)
int  CDirCache::operator[](int a2) {
  
  return this->m_aValues[(this->m_iPointer - a2) & 0xF];
}


// address=[0x15fb1a0]
// Decompiled from int __thiscall CDirCache::Back(CDirCache *this)
int  CDirCache::Back(void)const {
  
  return this->m_iPointer[this->m_iPointer[0] + 1];
}


// address=[0x15fb1c0]
// Decompiled from int __thiscall CDirCache::Count(CDirCache *this)
int  CDirCache::Count(void)const {
  
  return this->m_iCount;
}


// address=[0x15fb520]
// Decompiled from void __thiscall CDirCache::PopBack(CDirCache *this)
void  CDirCache::PopBack(void) {
  
  if ( !this->m_iCount
    && BBSupportDbgReport(2, "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\pathing\\AStar.h", 397, string__63) == 1 )
  {
    __debugbreak();
  }
  --this->m_iCount;
  this->m_iPointer = CDirCache::DecWrap(this->m_iPointer);
}


// address=[0x15d6600]
// Decompiled from int __cdecl CDirCache::IncWrap(char a1)
unsigned char __cdecl CDirCache::IncWrap(unsigned char a1) {
  
  return (a1 + 1) & 0xF;
}


// address=[0x15fb1e0]
// Decompiled from int __cdecl CDirCache::DecWrap(char a1)
unsigned char __cdecl CDirCache::DecWrap(unsigned char a1) {
  
  return (a1 - 1) & 0xF;
}


#endif // Already implemented
