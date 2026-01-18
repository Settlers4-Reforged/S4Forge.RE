#ifndef CY6R1X6_H
#define CY6R1X6_H

#include "defines.h"

class CY6R1X6 {
public:
    // address=[0x15d61f0]
    static int __cdecl DeltaX(int a1, int a2);

    // address=[0x15d6210]
    static int __cdecl DeltaY(int a1, int a2);

    // address=[0x15d6250]
    static int __cdecl Distance(int a1, int a2);

    // address=[0x15d6780]
    static int __cdecl NeighborRelPackedIdx(int a1);

    // address=[0x15d67a0]
    static int __cdecl PackedIdx(int a1);

    // address=[0x15d70b0]
    static bool __cdecl Valid(int a1);

    // address=[0x15d70e0]
    static int __cdecl WorldIdx(int a1);

    // address=[0x15d7180]
    static int __cdecl X(int a1);

    // address=[0x15d71c0]
    static int __cdecl Y(int a1);

};


#endif // CY6R1X6_H
