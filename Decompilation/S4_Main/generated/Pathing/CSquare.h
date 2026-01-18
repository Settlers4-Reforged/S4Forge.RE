#ifndef CSQUARE_H
#define CSQUARE_H

#include "defines.h"

class CSquare {
public:
    // address=[0x15f0a60]
    void  InitAndFillTypeMapNormal(int a2, int a3);

    // address=[0x15f0c40]
    void  InitAndFillTypeMapCatapult(int a2, int a3);

    // address=[0x15f3ef0]
     CSquare(void);

    // address=[0x15f4660]
    static int __cdecl Index(int a1, int a2);

    // address=[0x15f48f0]
    bool  IsPureWaterSquare(void)const;

    // address=[0x15f59e0]
    static int __cdecl TileTypeXY(int a1, int a2);

    // address=[0x15f5ae0]
    int  WaterCount(void)const;

protected:
    // address=[0x15f0e20]
    void  ConnectAreas(int a2, int a3);

    // address=[0x15f0f90]
    void  CalcComponentTileIndices(int a2);

    // address=[0x15f4140]
    void  AddComponentIfNecessary(int a2);

    // address=[0x15f4180]
    void  AddComponet(int a2);

    // address=[0x15f4a00]
    int  NewArea(int a2);

private:
    // address=[0x15f47c0]
    void  Init(int a2, int a3);

};


#endif // CSQUARE_H
