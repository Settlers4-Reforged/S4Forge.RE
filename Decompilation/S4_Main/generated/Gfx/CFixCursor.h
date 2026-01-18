#ifndef CFIXCURSOR_H
#define CFIXCURSOR_H

#include "defines.h"

class CFixCursor {
public:
    // address=[0x2f62430]
     CFixCursor(void);

    // address=[0x2f624a0]
    void  SetSurfacePtr(unsigned short a2, class CSurface * a3, unsigned short a4);

    // address=[0x2f626a0]
    void  SetFixCursor(int a2, int a3, bool a4);

    // address=[0x2f62800]
    long  Show(class CSurface * a2);

    // address=[0x2f699a0]
    bool  IsVisible(void);

};


#endif // CFIXCURSOR_H
