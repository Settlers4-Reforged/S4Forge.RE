#ifndef CECOMANAGERTREE_H
#define CECOMANAGERTREE_H

class CEcoManagerTree {
public:
    // address=[0x134bcd0]
     CEcoManagerTree(void);

    // address=[0x134bd00]
     ~CEcoManagerTree(void);

    // address=[0x134bda0]
    unsigned char  CreateBaseLeaf(enum BUILDING_TYPES,int,int,class std::vector<struct SPOSS_BUILD_PLACE,class std::allocator<struct SPOSS_BUILD_PLACE> > *);

    // address=[0x134bee0]
    bool  RemoveLeaf(int);

    // address=[0x134bf70]
    bool  RemoveLeaf(struct SBUILDINFODATA *);

    // address=[0x134c010]
    int  GetNrBaseLeaves(void);

    // address=[0x134c030]
    class CEcoManagerLeaf *  GetBaseLeaf(int);

    // address=[0x134c070]
    bool  UpdateBaseLeaf(int);

    // address=[0x134c0a0]
    int  GetNrValidOfAllBaseLeafes(enum IECONOMANAGERGRIDRESOLUTION);

    // address=[0x134c150]
    class CEcoManagerLeaf *  FindLeaf(enum IECONOMANAGERGRIDRESOLUTION,int,int);

    // address=[0x134c250]
    class CEcoManagerLeaf *  FindNearLeaf(enum IECONOMANAGERGRIDRESOLUTION,int,int,int);

private:
    // address=[0x134c2f0]
    class CEcoManagerLeaf *  GetBaseLeaf(int,int);

    // address=[0x134c360]
    bool  RemoveLeafRecursive(class CEcoManagerLeaf *,class CEcoManagerLeaf *);

};


#endif // CECOMANAGERTREE_H
