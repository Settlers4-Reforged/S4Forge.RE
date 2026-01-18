#ifndef CAIRESOURCEDATA_H
#define CAIRESOURCEDATA_H

#include "defines.h"

class CAIResourceData {
public:
    // address=[0x131c910]
    int  Flags1(void)const;

    // address=[0x131c930]
    int  Flags9(void)const;

    // address=[0x131c990]
    int  GroundInfo1(int a2)const;

    // address=[0x131c9e0]
    int  ResourceAmount1(int a2)const;

    // address=[0x131ca00]
    int  ResourceAmount9(int a2)const;

};


#endif // CAIRESOURCEDATA_H
