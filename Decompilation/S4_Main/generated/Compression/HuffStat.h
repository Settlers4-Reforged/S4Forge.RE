#ifndef HUFFSTAT_H
#define HUFFSTAT_H

#include "defines.h"

class HuffStat {
public:
    // address=[0x2f2a930]
     HuffStat(void);

    // address=[0x2f2a970]
     ~HuffStat(void);

protected:
    // address=[0x2f2a9a0]
    int  makeSortedTmp(struct HuffStatTmpStruct * a2);

};


#endif // HUFFSTAT_H
