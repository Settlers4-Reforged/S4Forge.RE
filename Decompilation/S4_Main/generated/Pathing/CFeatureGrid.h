#ifndef CFEATUREGRID_H
#define CFEATUREGRID_H

#include "defines.h"

class CFeatureGrid {
public:
    // address=[0x2fc5180]
     ~CFeatureGrid(void);

    // address=[0x2fc6a40]
     CFeatureGrid(int a2);

    // address=[0x2fc6b90]
    void  initGrid(void);

    // address=[0x2fc7a70]
    bool  findNearestElement(int & a2, int & a3, int a4, bool a5);

};


#endif // CFEATUREGRID_H
