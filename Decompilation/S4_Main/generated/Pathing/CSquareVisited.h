#ifndef CSQUAREVISITED_H
#define CSQUAREVISITED_H

#include "defines.h"

class CSquareVisited {
public:
    // address=[0x15f1030]
     CSquareVisited(void);

    // address=[0x15f1070]
    void  Init(int a2, int a3);

    // address=[0x15f4030]
    bool  operator[](int a2)const;

    // address=[0x15f4280]
    void  ClearArray(void);

    // address=[0x15f4820]
    void  Init(int a2);

    // address=[0x15f49e0]
    static int __cdecl NeighborRelIndex(int a1);

    // address=[0x15f56c0]
    void  Set(int a2);

    // address=[0x15f57a0]
    bool  SetIfNotVisited(int a2);

    // address=[0x15f5920]
    int  StartIndex(void)const;

    // address=[0x15f5b80]
    int  WorldIdx(int a2)const;

    // address=[0x15f5f40]
    int  WorldPackedXYIndex(int a2)const;

};


#endif // CSQUAREVISITED_H
