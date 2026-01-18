#ifndef CMIRRORBASICGRID_H
#define CMIRRORBASICGRID_H

#include "defines.h"

class CMirrorBasicGrid : public CBasicGrid {
public:
    // address=[0x2fc5fb0]
     CMirrorBasicGrid(int a2, int a3);

    // address=[0x2fc5fe0]
    virtual void  initGrid(void);

protected:
    // address=[0x2fc6600]
    void  getMirrorBasisPoint(int & a2, int & a3, bool a4);

};


#endif // CMIRRORBASICGRID_H
