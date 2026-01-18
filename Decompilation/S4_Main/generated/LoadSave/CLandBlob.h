#ifndef CLANDBLOB_H
#define CLANDBLOB_H

#include "defines.h"

class CLandBlob : public CBlob {
public:
    // address=[0x2fc9de0]
     CLandBlob(int a2, int a3, int a4, int a5, bool a6, int a7, int a8, int a9, class CCheckLayer * a10);

protected:
    // address=[0x2fc9eb0]
    virtual void  processPoint(int a2, int a3);

    // address=[0x2fc9f50]
    virtual void  processFillPoint(int a2, int a3);

};


#endif // CLANDBLOB_H
