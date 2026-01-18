#ifndef CBASICGRID_H
#define CBASICGRID_H

#include "defines.h"

class CBasicGrid : public CGrid {
public:
    // address=[0x2fc5160]
     ~CBasicGrid(void);

    // address=[0x2fc56e0]
     CBasicGrid(int a2, int a3);

    // address=[0x2fc5720]
    virtual void  initGrid(void);

};


#endif // CBASICGRID_H
