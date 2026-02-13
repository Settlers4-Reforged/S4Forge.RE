#ifndef CSTRINGENGINE_H
#define CSTRINGENGINE_H

#include "defines.h"

extern class CStringEngine *g_pStringEngine;

class CStringEngine {
public:
    // address=[0x14ce700]
    static class CStringEngine * __cdecl CreateStringEngine(int a1);

    // address=[0x14cf320]
     CStringEngine(void);

    // address=[0x14cf340]
    virtual  ~CStringEngine(void);

    // purecall
    virtual char const *  GetString(int a2) = 0;
};


#endif // CSTRINGENGINE_H
