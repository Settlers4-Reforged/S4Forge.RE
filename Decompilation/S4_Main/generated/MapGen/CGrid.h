#ifndef CGRID_H
#define CGRID_H

#include "defines.h"

class CGrid {
public:
    // address=[0x2fc5520]
     CGrid(int a2);

    // address=[0x2fc5580]
     ~CGrid(void);

    // address=[0x2fc55b0]
    int  getElement(int a2, int a3);

    // address=[0x2fc55f0]
    void  setElement(int a2, int a3, int a4);

    // address=[0x2fc5630]
    int  getElement(int a2);

    // address=[0x2fc5660]
    void  setElement(int a2, int a3);

    // address=[0x2fc5670]
    int  getSize(void);

};


#endif // CGRID_H
