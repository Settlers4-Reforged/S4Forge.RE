#ifndef COBJECTBLOB_H
#define COBJECTBLOB_H

#include "defines.h"

class CObjectBlob : public CBlob {
public:
    // address=[0x2fca1a0]
     CObjectBlob(int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, class CCheckLayer * a12);

protected:
    // address=[0x2fca200]
    virtual void  processFillPoint(int a2, int a3);

};


#endif // COBJECTBLOB_H
