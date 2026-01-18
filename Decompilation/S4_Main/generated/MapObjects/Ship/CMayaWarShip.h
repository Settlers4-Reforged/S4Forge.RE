#ifndef CMAYAWARSHIP_H
#define CMAYAWARSHIP_H

#include "defines.h"

class CMayaWarShip : public CWarShip {
public:
    // address=[0x1401300]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x15a19e0]
     CMayaWarShip(std::istream & a2);

    // address=[0x15a1aa0]
    virtual void  Store(std::ostream & a2);

    // address=[0x15a2400]
    virtual  ~CMayaWarShip(void);

    // address=[0x15a26a0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8bfe8]
    static unsigned long m_iClassID;

protected:
    // address=[0x15a1ae0]
     CMayaWarShip(int a2, int a3, int a4, int a5, int a6, int a7, bool a8);

private:
    // address=[0x15a2660]
    virtual int const  AmmoPerPile(void);

};


#endif // CMAYAWARSHIP_H
