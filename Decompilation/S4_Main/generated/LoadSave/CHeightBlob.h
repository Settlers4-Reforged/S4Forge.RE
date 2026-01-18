#ifndef CHEIGHTBLOB_H
#define CHEIGHTBLOB_H

#include "defines.h"

class CHeightBlob : public CBlob {
public:
    // address=[0x2fccbb0]
     CHeightBlob(int a2, int a3, int a4, int a5, int a6, int a7, class CCheckLayer * a8);

protected:
    // address=[0x2fccce0]
    virtual void  fillBlob(int a2, int a3);

    // address=[0x2fcd100]
    virtual void  processFillPoint(int a2, int a3);

};


#endif // CHEIGHTBLOB_H
