#ifndef _CRCTABLE_H
#define _CRCTABLE_H

#include "defines.h"

namespace  {

class CRCTable {
public:
    // address=[0x13e4be0]
     cdm_crc::CRCGenerator<16,32773,0,0,1,1>CRCTable(void);

    // address=[0x13e56b0]
    unsigned long  cdm_crc::CRCGenerator<16,32773,0,0,1,1>operator[](int a2)const;

private:
    // address=[0x13e6470]
    unsigned long  cdm_crc::CRCGenerator<16,32773,0,0,1,1>CalcTableEntry(int a1);

};

} // namespace 

#endif // _CRCTABLE_H
