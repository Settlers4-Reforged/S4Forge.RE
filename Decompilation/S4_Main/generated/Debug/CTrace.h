#ifndef CTRACE_H
#define CTRACE_H

#include "defines.h"

class CTrace {
public:
    // address=[0x14d3520]
     CTrace(char const * a2);

    // address=[0x14d3540]
     CTrace(class CTrace const & a2);

    // address=[0x14d3560]
    virtual  ~CTrace(void);

    // address=[0x14d3580]
    class CTrace &  operator=(class CTrace const & a2);

    // address=[0x14d35a0]
    static void __cdecl Print(char const * Format, ... a2);

    // address=[0x14d3610]
    static void __cdecl TextEinfuegen(char const * Format, ... a2);

private:
    // address=[0x14d3680]
    void  TraceInitObject(char const * a2);

    // address=[0x14d36e0]
    void  TracePrintHeader(void);

};


#endif // CTRACE_H
