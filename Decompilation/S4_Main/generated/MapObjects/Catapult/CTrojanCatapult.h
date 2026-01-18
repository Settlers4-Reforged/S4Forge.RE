#ifndef CTROJANCATAPULT_H
#define CTROJANCATAPULT_H

#include "defines.h"

class CTrojanCatapult : public CCatapult {
public:
    // address=[0x1402660]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x153f150]
    static void * __cdecl operator new(unsigned int a1);

    // address=[0x153f170]
    static void __cdecl operator delete(void * a1);

    // address=[0x153f1b0]
     CTrojanCatapult(std::istream & a2);

    // address=[0x153f270]
    virtual void  Store(std::ostream & a2);

    // address=[0x153fae0]
    virtual  ~CTrojanCatapult(void);

    // address=[0x153fd60]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8b878]
    static unsigned long m_iClassID;

protected:
    // address=[0x153f2b0]
     CTrojanCatapult(int a2, int a3, int a4, int a5, int a6, int a7, bool a8);

};


#endif // CTROJANCATAPULT_H
