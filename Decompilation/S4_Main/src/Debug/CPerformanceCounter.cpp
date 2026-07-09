#include "CPerformanceCounter.h"

// Definitions for class CPerformanceCounter

// address=[0x046851CC]
char s_spPerformanceTimeMsBuffer[44];
// address=[0x046851B0]
int s_bPerfFrequencyCalculated;
// address=[0x046851B8]
LARGE_INTEGER sPerfFrequencyQuery;
// address=[0x46851C0]
double s_dPerfFrequency;

// address=[0x2EFDE40]
void CalcPerfFrequency() {
    s_bPerfFrequencyCalculated = 1;
    QueryPerformanceFrequency(&sPerfFrequencyQuery);
    s_dPerfFrequency = 1.0 / static_cast<double>(sPerfFrequencyQuery.QuadPart) * 1000.0;
}

// address=[0x2efd660]
// Decompiled from CPerformanceCounter *__thiscall CPerformanceCounter::CPerformanceCounter(CPerformanceCounter *this)
CPerformanceCounter::CPerformanceCounter(void) {

    if(!s_bPerfFrequencyCalculated)
        CalcPerfFrequency();
    CPerformanceCounter::Clear();
}

// address=[0x2efd690]
// Decompiled from void __thiscall CPerformanceCounter::Start(CPerformanceCounter *this)
void CPerformanceCounter::Start(void) {
    this->uStartTickCount = GetTickCount();
    QueryPerformanceCounter(&this->sStartCounter);
}

// address=[0x2efd6c0]
// Decompiled from void __thiscall CPerformanceCounter::Measure(CPerformanceCounter *this)
void CPerformanceCounter::Measure(void) {

    QueryPerformanceCounter(&this->sMeasureCounter);
    this->uMeasureTickCount = GetTickCount();
}

// address=[0x2efd6f0]
// Decompiled from double __thiscall CPerformanceCounter::TimeMs(CPerformanceCounter *this)
double CPerformanceCounter::TimeMs(void) const {
    double v3 = static_cast<double>(this->sMeasureCounter.QuadPart - this->sStartCounter.QuadPart) * s_dPerfFrequency;
    double v2 = this->uMeasureTickCount - this->uStartTickCount;
    if(v3 - v2 >= 1000.0)
        return v2;
    else
        return v3;
}

// address=[0x2efd760]
// Decompiled from char *__thiscall CPerformanceCounter::TimeMsStr(CPerformanceCounter *this, int a2, int a3)
char const *CPerformanceCounter::TimeMsStr(int a2, int a3) const {
    if(a3 == 3 && a2 == 0) {
        double v3 = CPerformanceCounter::TimeMs();
        snprintf(s_spPerformanceTimeMsBuffer, 0x20u, "%.3f", v3);
        return s_spPerformanceTimeMsBuffer;
    }

    char Buffer[32]; // [esp+14h] [ebp-24h] BYREF
    snprintf(Buffer, 0x20u, "%%%i.%if", a2, a3);
    double v4 = CPerformanceCounter::TimeMs();
    snprintf(s_spPerformanceTimeMsBuffer, 0x20u, Buffer, v4);
    return s_spPerformanceTimeMsBuffer;
}

// address=[0x2efe090]
// Decompiled from void __thiscall CPerformanceCounter::Clear(CPerformanceCounter *this)
void CPerformanceCounter::Clear(void) {
    this->sStartCounter.QuadPart = 0LL;
    this->sMeasureCounter.QuadPart = 0LL;
}
