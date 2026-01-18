#ifndef CROMANWARSHIP_H
#define CROMANWARSHIP_H

#include "defines.h"

class CRomanWarShip : public CWarShip {
public:
    // address=[0x1401a80]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x15a1890]
     CRomanWarShip(std::istream & a2);

    // address=[0x15a1950]
    virtual void  Store(std::ostream & a2);

    // address=[0x15a2420]
    virtual  ~CRomanWarShip(void);

    // address=[0x15a26c0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8bfe4]
    static unsigned long m_iClassID;

protected:
    // address=[0x15a1990]
     CRomanWarShip(int a2, int a3, int a4, int a5, int a6, int a7, bool a8);

};


#endif // CROMANWARSHIP_H
