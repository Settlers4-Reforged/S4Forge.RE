#ifndef CMOUNTAINBLOB_H
#define CMOUNTAINBLOB_H

#include "defines.h"

class CMountainBlob : public CHeightBlob {
public:
    // address=[0x2fc9ac0]
     CMountainBlob(int a2, int a3, int a4, int a5, int a6, int a7, class CCheckLayer * a8);

protected:
    // address=[0x2fc9b00]
    virtual void  processFillPoint(int a2, int a3);

    // address=[0x2fc9c90]
    virtual void  processPoint(int a2, int a3);

};


#endif // CMOUNTAINBLOB_H
