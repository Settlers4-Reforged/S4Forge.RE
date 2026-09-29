#ifndef T_GFX_MAP_ELEMENT_H
#define T_GFX_MAP_ELEMENT_H

#include "defines.h"

class T_GFX_MAP_ELEMENT {
public:
    // address=[0x151aa30]
    int  GetGradient(void);

    // address=[0x15db1b0]
    int  GetNewFogging(void);

    // address=[0x15db1d0]
    int  GetOldFogging(void);

    // address=[0x2f90e30]
    void  SetNewFogging(int a2);

    // Type information members
public:
    unsigned __int8 iHeight;
    unsigned __int8 iType;
    unsigned __int8 iShading;
    unsigned __int8 iFlags;

};


#endif // T_GFX_MAP_ELEMENT_H
