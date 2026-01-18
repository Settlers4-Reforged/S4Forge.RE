#ifndef CTROJANWARSHIP_H
#define CTROJANWARSHIP_H

#include "defines.h"

class CTrojanWarShip : public CWarShip {
public:
    // address=[0x1402700]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x15a1d70]
     CTrojanWarShip(std::istream & a2);

    // address=[0x15a1e30]
    virtual void  Store(std::ostream & a2);

    // address=[0x15a2440]
    virtual  ~CTrojanWarShip(void);

    // address=[0x15a26e0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8bff0]
    static unsigned long m_iClassID;

protected:
    // address=[0x15a1e70]
     CTrojanWarShip(int a2, int a3, int a4, int a5, int a6, int a7, bool a8);

};


#endif // CTROJANWARSHIP_H
