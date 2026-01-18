#include "LZBuffer.h"

// Definitions for class LZBuffer

// address=[0x2f2a330]
// Decompiled from LZBuffer *__thiscall LZBuffer::LZBuffer(LZBuffer *this)
 LZBuffer::LZBuffer(void) {
  
  *(_DWORD *)this = operator new[](0x10000u);
  memset((void *)(*(_DWORD *)this + 65280), 0, 0x100u);
  *((_DWORD *)this + 1) = 0;
  return this;
}


// address=[0x2f2a400]
// Decompiled from int __thiscall LZBuffer::~LZBuffer(void **this)
 LZBuffer::~LZBuffer(void) {
  
  return operator delete[](*this);
}


// address=[0x2f2a4a0]
// Decompiled from int __cdecl LZBuffer::_distance(unsigned __int16 a1)
int __cdecl LZBuffer::_distance(int a1) {
  
  return a1;
}


// address=[0x2f2a4b0]
// Decompiled from int __thiscall LZBuffer::_nMatch(LZBuffer *this, int a2, const unsigned __int8 *a3, int a4)
int  LZBuffer::_nMatch(int a2, unsigned char const * a3, int a4) {
  
  int v5; // [esp+4h] [ebp-14h]
  int k; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]
  int j; // [esp+14h] [ebp-4h]

  if ( a4 >= 0x10000 && BBSupportDbgReport(2, "Source\\compression\\lz.cpp", 64, "nLimit < LZBUFSIZE") == 1 )
    __debugbreak();
  if ( 0x10000 - a2 < a4 )
  {
    for ( i = a2; i < 0x10000; ++i )
    {
      if ( *(unsigned __int8 *)(*(_DWORD *)this + i) != a3[i - a2] )
        return i - a2;
    }
    v5 = 0x10000 - a2;
    for ( j = 0; j < a4 - (0x10000 - a2); ++j )
    {
      if ( *(unsigned __int8 *)(*(_DWORD *)this + j) != a3[j + v5] )
        return j + v5;
    }
    return a4;
  }
  else
  {
    for ( k = 0; k < a4; ++k )
    {
      if ( *(unsigned __int8 *)(*(_DWORD *)this + k + a2) != a3[k] )
        return k;
    }
    return a4;
  }
}


// address=[0x2f2a640]
// Decompiled from int __thiscall LZBuffer::_toBuf(LZBuffer *this, unsigned __int8 a2)
void  LZBuffer::_toBuf(unsigned char a2) {
  
  int result; // eax
  unsigned int v3; // [esp+0h] [ebp-8h]

  v3 = *((_DWORD *)this + 1);
  *((_DWORD *)this + 1) = v3 + 1;
  result = LZBuffer::_wrap(v3);
  *(_BYTE *)(*(_DWORD *)this + result) = a2;
  return result;
}


// address=[0x2f2a690]
// Decompiled from int __thiscall LZBuffer::_toBuf(int this, char *Src, size_t a3)
void  LZBuffer::_toBuf(unsigned char const * Src, unsigned int a3) {
  
  int result; // eax
  int v4; // [esp+8h] [ebp-8h]

  if ( a3 >= 0x10000
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\source\\compression\\_lz.h",
         128,
         "sz < LZBUFSIZE") == 1 )
  {
    __debugbreak();
  }
  v4 = LZBuffer::_wrap(*(_DWORD *)(this + 4));
  if ( (int)(a3 + v4) <= 0x10000 )
  {
    j__memcpy((void *)(v4 + *(_DWORD *)this), Src, a3);
  }
  else
  {
    j__memcpy((void *)(v4 + *(_DWORD *)this), Src, 0x10000 - v4);
    j__memcpy(*(void **)this, &Src[0x10000 - v4], a3 - (0x10000 - v4));
  }
  result = a3 + *(_DWORD *)(this + 4);
  *(_DWORD *)(this + 4) = result;
  return result;
}


// address=[0x2f2a920]
// Decompiled from int __cdecl LZBuffer::_wrap(unsigned __int16 a1)
int __cdecl LZBuffer::_wrap(unsigned long a1) {
  
  return a1;
}


// address=[0x2f2c400]
// Decompiled from void *__thiscall LZBuffer::_bufCpy(const void **this, char *a2, unsigned int a3, size_t a4)
void  LZBuffer::_bufCpy(unsigned char * a2, int a3, unsigned int a4) {
  
  int v6; // [esp+Ch] [ebp-4h]

  if ( a4 >= 0x10000
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\source\\compression\\_lz.h",
         144,
         "sz < LZBUFSIZE") == 1 )
  {
    __debugbreak();
  }
  v6 = LZBuffer::_wrap(a3);
  if ( (int)(a4 + v6) <= 0x10000 )
    return j__memcpy(a2, (char *)*this + v6, a4);
  j__memcpy(a2, (char *)*this + v6, 0x10000 - v6);
  return j__memcpy(&a2[0x10000 - v6], *this, a4 - (0x10000 - v6));
}


