#ifndef CPERFORMANCECOUNTER_H
#define CPERFORMANCECOUNTER_H

#include "defines.h"

class CPerformanceCounter {
public:
    // address=[0x2efd660]
     CPerformanceCounter(void);

    // address=[0x2efd690]
    void  Start(void);

    // address=[0x2efd6c0]
    void  Measure(void);

    // address=[0x2efd6f0]
    double  TimeMs(void)const;

    // address=[0x2efd760]
    char const *  TimeMsStr(int a2, int a3)const;

    // address=[0x2efe090]
    void  Clear(void);

    // Type information members
public:
    LARGE_INTEGER sStartCounter;
    LARGE_INTEGER sMeasureCounter;
    _DWORD uStartTickCount;
    _DWORD uMeasureTickCount;

};


#endif // CPERFORMANCECOUNTER_H
