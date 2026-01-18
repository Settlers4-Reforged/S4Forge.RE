#include "CPerformanceCounter.h"

// Definitions for class CPerformanceCounter

// address=[0x2efd660]
// Decompiled from CPerformanceCounter *__thiscall CPerformanceCounter::CPerformanceCounter(CPerformanceCounter *this)
 CPerformanceCounter::CPerformanceCounter(void) {
  
  if ( !dword_46851B0 )
    sub_2EFDE40();
  CPerformanceCounter::Clear(this);
  return this;
}


// address=[0x2efd690]
// Decompiled from BOOL __thiscall CPerformanceCounter::Start(LARGE_INTEGER *this)
void  CPerformanceCounter::Start(void) {
  
  this[2].LowPart = GetTickCount();
  return QueryPerformanceCounter(this);
}


// address=[0x2efd6c0]
// Decompiled from DWORD __thiscall CPerformanceCounter::Measure(LARGE_INTEGER *this)
void  CPerformanceCounter::Measure(void) {
  
  DWORD result; // eax

  QueryPerformanceCounter(this + 1);
  result = GetTickCount();
  this[2].HighPart = result;
  return result;
}


// address=[0x2efd6f0]
// Decompiled from double __thiscall CPerformanceCounter::TimeMs(CPerformanceCounter *this)
double  CPerformanceCounter::TimeMs(void)const {
  
  double v2; // [esp+4h] [ebp-14h]
  double v3; // [esp+Ch] [ebp-Ch]

  v3 = (double)(__int64)(*((_QWORD *)this + 1) - *(_QWORD *)this) * *(double *)&qword_46851C0;
  v2 = (double)(*((_DWORD *)this + 5) - *((_DWORD *)this + 4));
  if ( v3 - v2 >= 1000.0 )
    return v2;
  else
    return v3;
}


// address=[0x2efd760]
// Decompiled from char *__thiscall CPerformanceCounter::TimeMsStr(CPerformanceCounter *this, __int64 a2)
char const *  CPerformanceCounter::TimeMsStr(int a2, int a2)const {
  
  double v2; // st7
  double v3; // st7
  char Buffer[32]; // [esp+14h] [ebp-24h] BYREF

  if ( HIDWORD(a2) == 3 && (_DWORD)a2 == 0 )
  {
    v2 = CPerformanceCounter::TimeMs(this);
    j___snprintf(byte_46851CC, 0x20u, "%.3f", v2);
  }
  else
  {
    j___snprintf(Buffer, 0x20u, "%%%i.%if", (_DWORD)a2, HIDWORD(a2));
    v3 = CPerformanceCounter::TimeMs(this);
    j___snprintf(byte_46851CC, 0x20u, Buffer, v3);
  }
  return byte_46851CC;
}


// address=[0x2efe090]
// Decompiled from CPerformanceCounter *__thiscall CPerformanceCounter::Clear(CPerformanceCounter *this)
void  CPerformanceCounter::Clear(void) {
  
  CPerformanceCounter *result; // eax

  result = this;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  return result;
}


