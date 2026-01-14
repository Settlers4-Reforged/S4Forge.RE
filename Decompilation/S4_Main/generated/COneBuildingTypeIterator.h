#ifndef CONEBUILDINGTYPEITERATOR_H
#define CONEBUILDINGTYPEITERATOR_H

class COneBuildingTypeIterator {
public:
    // address=[0x1315a50]
    void  Init(int,int);

    // address=[0x1315a80]
    int  FirstBuilding(void);

    // address=[0x1315ab0]
    int  NextBuilding(void);

    // address=[0x1315b00]
    int  NextBuildingIfCurrentIsNotValid(void);

    // address=[0x1317250]
     COneBuildingTypeIterator(void);

};


#endif // CONEBUILDINGTYPEITERATOR_H
