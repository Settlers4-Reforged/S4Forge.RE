#ifndef CSQUARE_H
#define CSQUARE_H

class CSquare {
public:
    // address=[0x15f0a60]
    void  InitAndFillTypeMapNormal(int,int);

    // address=[0x15f0c40]
    void  InitAndFillTypeMapCatapult(int,int);

    // address=[0x15f3ef0]
     CSquare(void);

    // address=[0x15f4660]
    static int __cdecl Index(int,int);

    // address=[0x15f48f0]
    bool  IsPureWaterSquare(void)const;

    // address=[0x15f59e0]
    static int __cdecl TileTypeXY(int,int);

    // address=[0x15f5ae0]
    int  WaterCount(void)const;

protected:
    // address=[0x15f0e20]
    void  ConnectAreas(int,int);

    // address=[0x15f0f90]
    void  CalcComponentTileIndices(int);

    // address=[0x15f4140]
    void  AddComponentIfNecessary(int);

    // address=[0x15f4180]
    void  AddComponet(int);

    // address=[0x15f4a00]
    int  NewArea(int);

private:
    // address=[0x15f47c0]
    void  Init(int,int);

};


#endif // CSQUARE_H
