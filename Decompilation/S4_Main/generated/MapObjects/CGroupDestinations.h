#ifndef CGROUPDESTINATIONS_H
#define CGROUPDESTINATIONS_H

#include "defines.h"

class CGroupDestinations {
public:
    // address=[0x15507a0]
     CGroupDestinations(int a2, int a3, int a4, int a5, int a6);

    // address=[0x1552710]
    int  GetNextDestination(void);

protected:
    // address=[0x15509f0]
    static int __fastcall NormalSectorId(int a1, int a2);

    // address=[0x1550a10]
    static int __fastcall CatapultSectorId(int a1, int a2);

};


#endif // CGROUPDESTINATIONS_H
