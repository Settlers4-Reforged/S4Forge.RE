#ifndef CROMANCATAPULT_H
#define CROMANCATAPULT_H

#include "defines.h"

class CRomanCatapult : public CCatapult {
public:
    // address=[0x14019e0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x153eb50]
    static void * __cdecl operator new(unsigned int a1);

    // address=[0x153eb70]
    static void __cdecl operator delete(void * a1);

    // address=[0x153ebb0]
     CRomanCatapult(std::istream & a2);

    // address=[0x153ec70]
    virtual void  Store(std::ostream & a2);

    // address=[0x153fac0]
    virtual  ~CRomanCatapult(void);

    // address=[0x153fd40]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8b838]
    static unsigned long m_iClassID;

protected:
    // address=[0x153ecb0]
     CRomanCatapult(int a2, int a3, int a4, int a5, int a6, int a7, bool a8);

};


#endif // CROMANCATAPULT_H
