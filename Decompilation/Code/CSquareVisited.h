#ifndef CSQUAREVISITED_H
#define CSQUAREVISITED_H

class CSquareVisited {
public:
    // address=[0x15f1030]
     CSquareVisited(void);

    // address=[0x15f1070]
    void  Init(int,int);

    // address=[0x15f4030]
    bool  operator[](int)const;

    // address=[0x15f4280]
    void  ClearArray(void);

    // address=[0x15f4820]
    void  Init(int);

    // address=[0x15f49e0]
    static int __cdecl NeighborRelIndex(int);

    // address=[0x15f56c0]
    void  Set(int);

    // address=[0x15f57a0]
    bool  SetIfNotVisited(int);

    // address=[0x15f5920]
    int  StartIndex(void)const;

    // address=[0x15f5b80]
    int  WorldIdx(int)const;

    // address=[0x15f5f40]
    int  WorldPackedXYIndex(int)const;

};


#endif // CSQUAREVISITED_H
