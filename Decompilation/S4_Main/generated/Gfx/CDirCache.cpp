#include "all_headers.h"

// Definitions for class CDirCache

// address=[0x15d6690]
// Decompiled from CDirCache *__thiscall CDirCache::Init(CDirCache *this)
void  CDirCache::Init(void) {
  
  CDirCache *result; // eax

  result = this;
  *(_BYTE *)this = 0;
  *((_BYTE *)this + 1) = 15;
  return result;
}


// address=[0x15d69a0]
// Decompiled from int __thiscall CDirCache::PushBack(CDirCache *this, char a2)
void  CDirCache::PushBack(int) {
  
  int result; // eax

  *(_BYTE *)this += *(unsigned __int8 *)this < 0x10u;
  *((_BYTE *)this + 1) = CDirCache::IncWrap(*((_BYTE *)this + 1));
  result = *((unsigned __int8 *)this + 1);
  *((_BYTE *)this + result + 2) = a2;
  return result;
}


// address=[0x15faff0]
// Decompiled from int __thiscall CDirCache::operator[](_BYTE *this, char a2)
int  CDirCache::operator[](int) {
  
  return (unsigned __int8)this[((this[1] - a2) & 0xF) + 2];
}


// address=[0x15fb1a0]
// Decompiled from int __thiscall CDirCache::Back(CDirCache *this)
int  CDirCache::Back(void)const {
  
  return *((unsigned __int8 *)this + *((unsigned __int8 *)this + 1) + 2);
}


// address=[0x15fb1c0]
// Decompiled from int __thiscall CDirCache::Count(CDirCache *this)
int  CDirCache::Count(void)const {
  
  return *(unsigned __int8 *)this;
}


// address=[0x15fb520]
// Decompiled from int __thiscall CDirCache::PopBack(CDirCache *this)
void  CDirCache::PopBack(void) {
  
  int result; // eax

  if ( !*(_BYTE *)this
    && BBSupportDbgReport(2, "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\pathing\\AStar.h", 397, string__63) == 1 )
  {
    __debugbreak();
  }
  --*(_BYTE *)this;
  LOBYTE(result) = CDirCache::DecWrap(*((_BYTE *)this + 1));
  *((_BYTE *)this + 1) = result;
  return result;
}


// address=[0x15d6600]
// Decompiled from int __cdecl CDirCache::IncWrap(char a1)
static unsigned char __cdecl CDirCache::IncWrap(unsigned char) {
  
  return (a1 + 1) & 0xF;
}


// address=[0x15fb1e0]
// Decompiled from int __cdecl CDirCache::DecWrap(char a1)
static unsigned char __cdecl CDirCache::DecWrap(unsigned char) {
  
  return (a1 - 1) & 0xF;
}


