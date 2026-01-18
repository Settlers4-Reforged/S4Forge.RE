#ifndef CBLOB_H
#define CBLOB_H

#include "defines.h"

class CBlob {
public:
    // address=[0x2fc88f0]
     CBlob(void);

    // address=[0x2fc8910]
     CBlob(int a2, int a3, int a4, int a5, int a6, int a7, int a8, class CCheckLayer * a9);

    // address=[0x2fc8be0]
    void  drawBlob(void);

protected:
    // address=[0x2fc9100]
    virtual void  fillBlob(int a2, int a3);

    // address=[0x2fc9490]
    int  getNextDirection(int a2, int a3);

    // address=[0x2fc95d0]
    virtual void  processPoint(int a2, int a3);

};


#endif // CBLOB_H
