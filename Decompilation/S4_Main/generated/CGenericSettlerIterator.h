#ifndef CGENERICSETTLERITERATOR_H
#define CGENERICSETTLERITERATOR_H

class CGenericSettlerIterator {
public:
    // address=[0x1315360]
    bool  Init(int,int,int);

    // address=[0x13153d0]
    int  FirstSettler(void);

    // address=[0x1315450]
    int  NextSettler(void);

    // address=[0x1315520]
    int  NextSettlerIfCurrentIsNotValid(void);

    // address=[0x1315560]
    int  NextSettlerOrFirstIfCurrentIsEndOfList(void);

    // address=[0x13171b0]
     CGenericSettlerIterator(void);

};


#endif // CGENERICSETTLERITERATOR_H
