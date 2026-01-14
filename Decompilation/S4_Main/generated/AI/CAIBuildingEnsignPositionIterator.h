#ifndef CAIBUILDINGENSIGNPOSITIONITERATOR_H
#define CAIBUILDINGENSIGNPOSITIONITERATOR_H

class CAIBuildingEnsignPositionIterator {
public:
    // address=[0x130d390]
     CAIBuildingEnsignPositionIterator(int,int);

    // address=[0x130d3c0]
    bool  NextXY(int &,int &);

    // address=[0x130d420]
    bool  NextWorldIdx(int &);

};


#endif // CAIBUILDINGENSIGNPOSITIONITERATOR_H
