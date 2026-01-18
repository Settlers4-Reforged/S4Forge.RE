#ifndef CECOMANAGERTREE_H
#define CECOMANAGERTREE_H

#include "defines.h"

class CEcoManagerTree {
public:
    // address=[0x134bcd0]
     CEcoManagerTree(void);

    // address=[0x134bd00]
     ~CEcoManagerTree(void);

    // address=[0x134bda0]
    unsigned char  CreateBaseLeaf(enum BUILDING_TYPES a2, int a3, int a4, class std::vector<struct SPOSS_BUILD_PLACE,class std::allocator<struct SPOSS_BUILD_PLACE> > * a5);

    // address=[0x134bee0]
    bool  RemoveLeaf(int a2);

    // address=[0x134bf70]
    bool  RemoveLeaf(struct SBUILDINFODATA * a2);

    // address=[0x134c010]
    int  GetNrBaseLeaves(void);

    // address=[0x134c030]
    class CEcoManagerLeaf *  GetBaseLeaf(int a2);

    // address=[0x134c070]
    bool  UpdateBaseLeaf(int a2);

    // address=[0x134c0a0]
    int  GetNrValidOfAllBaseLeafes(enum IECONOMANAGERGRIDRESOLUTION a2);

    // address=[0x134c150]
    class CEcoManagerLeaf *  FindLeaf(enum IECONOMANAGERGRIDRESOLUTION a2, int a3, int a4);

    // address=[0x134c250]
    class CEcoManagerLeaf *  FindNearLeaf(enum IECONOMANAGERGRIDRESOLUTION a2, int a3, int a4, int a5);

private:
    // address=[0x134c2f0]
    class CEcoManagerLeaf *  GetBaseLeaf(int a2, int a3);

    // address=[0x134c360]
    bool  RemoveLeafRecursive(class CEcoManagerLeaf * a2, class CEcoManagerLeaf * a3);

};


#endif // CECOMANAGERTREE_H
