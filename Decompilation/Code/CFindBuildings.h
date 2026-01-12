#ifndef CFINDBUILDINGS_H
#define CFINDBUILDINGS_H

class CFindBuildings {
public:
    // address=[0x1470890]
    class CBuilding *  BuildingPtr(void)const;

    // address=[0x15dec30]
     CFindBuildings(int,int,int);

    // address=[0x15deca0]
    bool  NextBuilding(void);

};


#endif // CFINDBUILDINGS_H
