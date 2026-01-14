#ifndef CGENERICBUILDINGITERATOR_H
#define CGENERICBUILDINGITERATOR_H

class CGenericBuildingIterator {
public:
    // address=[0x1315ce0]
    bool  Init(int,int,int);

    // address=[0x1315d50]
    int  FirstBuilding(void);

    // address=[0x1315dd0]
    int  NextBuilding(void);

    // address=[0x1315ea0]
    int  NextBuildingIfCurrentIsNotValid(void);

    // address=[0x1315ee0]
    int  NextBuildingOrFirstIfCurrentIsEndOfList(void);

    // address=[0x1317190]
     CGenericBuildingIterator(void);

};


#endif // CGENERICBUILDINGITERATOR_H
