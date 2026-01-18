#ifndef CDARKCONVERT_H
#define CDARKCONVERT_H

#include "defines.h"

class CDarkConvert {
public:
    // address=[0x15413d0]
    static int __cdecl GetGreenObject(int a1);

    // address=[0x1541430]
    static int __cdecl GetDarkObject(int a1);

private:
    // address=[0x3d8b890]
    static int (* m_aiConvTable)[2];

};


#endif // CDARKCONVERT_H
