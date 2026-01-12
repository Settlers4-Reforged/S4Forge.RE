#ifndef CFEATUREGRID_H
#define CFEATUREGRID_H

class CFeatureGrid {
public:
    // address=[0x2fc5180]
     ~CFeatureGrid(void);

    // address=[0x2fc6a40]
     CFeatureGrid(int);

    // address=[0x2fc6b90]
    void  initGrid(void);

    // address=[0x2fc7a70]
    bool  findNearestElement(int &,int &,int,bool);

};


#endif // CFEATUREGRID_H
