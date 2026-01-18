#ifndef CMAYACATAPULT_H
#define CMAYACATAPULT_H

#include "defines.h"

class CMayaCatapult : public CCatapult {
public:
    // address=[0x1401260]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x153ed00]
    static void * __cdecl operator new(unsigned int a1);

    // address=[0x153ed20]
    static void __cdecl operator delete(void * a1);

    // address=[0x153ed60]
     CMayaCatapult(std::istream & a2);

    // address=[0x153ee20]
    virtual void  Store(std::ostream & a2);

    // address=[0x153faa0]
    virtual  ~CMayaCatapult(void);

    // address=[0x153fd20]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8b83c]
    static unsigned long m_iClassID;

protected:
    // address=[0x153ee60]
     CMayaCatapult(int a2, int a3, int a4, int a5, int a6, int a7, bool a8);

private:
    // address=[0x153fd00]
    virtual int const  AmmoPerPile(void);

};


#endif // CMAYACATAPULT_H
