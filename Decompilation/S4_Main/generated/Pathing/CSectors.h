#ifndef CSECTORS_H
#define CSECTORS_H

#include "defines.h"

class CSectors {
public:
    // address=[0x15e79a0]
    void  Init(void);

    // address=[0x15e7a20]
    int  NewSector(unsigned char a2);

    // address=[0x15e7ad0]
    void  DeleteSector(int a2);

    // address=[0x15e7b40]
    int  CountSectors(unsigned char a2)const;

    // address=[0x15f3ed0]
     CSectors(void);

    // address=[0x15f4620]
    void  IncSectorSize(int a2);

    // address=[0x15f5660]
    int  SectorSize(int a2)const;

};


#endif // CSECTORS_H
