#ifndef CASTAR64_H
#define CASTAR64_H

#include "defines.h"

class CAStar64 {
public:
    // address=[0x15d3820]
    bool  FindPath(int a2, int a3, class CDirCache & a4);

    // address=[0x15d5ea0]
     CAStar64(void);

protected:
    // address=[0x15d6de0]
    static int __cdecl SettlerDisplacementCosts(int a1, int a2);

    // address=[0x15d7130]
    static int __cdecl WorldMoveCosts(int a1);

    // address=[0x15d7150]
    static int __cdecl WorldMoveCostsNoRoad(int a1);

};


#endif // CASTAR64_H
