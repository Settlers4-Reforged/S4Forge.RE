#if FALSE
#include "CPerformanceCounter.h"

// Definitions for class CPerformanceCounter

// address=[0x2efd660]
// Decompiled from CPerformanceCounter *__thiscall CPerformanceCounter::CPerformanceCounter(CPerformanceCounter *this)
 CPerformanceCounter::CPerformanceCounter(void) {
  
  if ( !s_bPerfFrequencyCalculated )
  {
    CalcPerfFrequency();
  }
  CPerformanceCounter::Clear(this);
  return this;
}


// address=[0x2efd690]
// Decompiled from void __thiscall CPerformanceCounter::Start(CPerformanceCounter *this)
void  CPerformanceCounter::Start(void) {
  
  this->uStartTickCount = GetTickCount();
  QueryPerformanceCounter(&this->sStartCounter);
}


// address=[0x2efd6c0]
// Decompiled from void __thiscall CPerformanceCounter::Measure(CPerformanceCounter *this)
void  CPerformanceCounter::Measure(void) {
  
  QueryPerformanceCounter(&this->sMeasureCounter);
  this->uMeasureTickCount = GetTickCount();
}


// address=[0x2efd6f0]
// Decompiled from double __thiscall CPerformanceCounter::TimeMs(CPerformanceCounter *this)
double  CPerformanceCounter::TimeMs(void)const {
  
  double v2; // [esp+4h] [ebp-14h]
  double v3; // [esp+Ch] [ebp-Ch]

  v3 = (double)(this->sMeasureCounter.QuadPart - this->sStartCounter.QuadPart) * s_dPerfFrequency;
  v2 = (double)(this->uMeasureTickCount - this->uStartTickCount);
  if ( v3 - v2 >= 1000.0 )
  {
    return v2;
  }
  else
  {
    return v3;
  }
}


// address=[0x2efd760]
// Decompiled from char *__thiscall CPerformanceCounter::TimeMsStr(CPerformanceCounter *this, int a2, int a3)
char const *  CPerformanceCounter::TimeMsStr(int a2, int a3)const {
  
  double v3; // st7
  double v4; // st7
  char Buffer[32]; // [esp+14h] [ebp-24h] BYREF

  if ( a3 == 3 && a2 == 0 )
  {
    v3 = CPerformanceCounter::TimeMs(this);
    snprintf(s_spPerformanceTimeMsBuffer, 0x20u, "%.3f", v3);
  }
  else
  {
    snprintf(Buffer, 0x20u, "%%%i.%if", a2, a3);
    v4 = CPerformanceCounter::TimeMs(this);
    snprintf(s_spPerformanceTimeMsBuffer, 0x20u, Buffer, v4);
  }
  return s_spPerformanceTimeMsBuffer;
}


// address=[0x2efe090]
// Decompiled from void __thiscall CPerformanceCounter::Clear(CPerformanceCounter *this)
void  CPerformanceCounter::Clear(void) {
  
  this->sStartCounter.QuadPart = 0LL;
  this->sMeasureCounter.QuadPart = 0LL;
}


#endif // Already implemented
