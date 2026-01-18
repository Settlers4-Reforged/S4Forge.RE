#ifndef CECOMANAGERLEAF_H
#define CECOMANAGERLEAF_H

#include "defines.h"

class CEcoManagerLeaf {
public:
    // address=[0x134b270]
     CEcoManagerLeaf(enum IECONOMANAGERGRIDRESOLUTION a2, enum BUILDING_TYPES a3, int a4, int a5);

    // address=[0x134b2c0]
     ~CEcoManagerLeaf(void);

    // address=[0x134b340]
    void  GetPosition(int & a2, int & a3);

    // address=[0x134b370]
    struct SBUILDINFODATA const *  GetBuildInfo(void);

    // address=[0x134b380]
    bool  Update(void);

    // address=[0x134b580]
    int  GetResourceAmount(int a2);

    // address=[0x134b5a0]
    int  GetUndergroundAmount(int a2);

    // address=[0x134b5c0]
    bool  AddPosition(int a2, int a3, class std::vector<struct SPOSS_BUILD_PLACE,class std::allocator<struct SPOSS_BUILD_PLACE> > * a4);

    // address=[0x134b820]
    int  GetNrChilds(void);

    // address=[0x134b830]
    int  GetNrValidChilds(void);

    // address=[0x134b890]
    int  GetNrValidOfAllSubChilds(void);

    // address=[0x134b8b0]
    class CEcoManagerLeaf *  GetChild(int a2);

    // address=[0x134b8e0]
    int  GetChild(int a2, int a3);

    // address=[0x134b950]
    bool  RemoveChild(int a2);

private:
    // address=[0x134b9c0]
    int  GetFreeChildPos(void);

};


#endif // CECOMANAGERLEAF_H
