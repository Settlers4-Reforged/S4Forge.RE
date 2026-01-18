#ifndef CPREVIEWBLOB_H
#define CPREVIEWBLOB_H

#include "defines.h"

class CPreviewBlob : public CBlob {
public:
    // address=[0x2fcca60]
     CPreviewBlob(int a2, int a3, int a4, int a5, int a6, int a7, int a8, class CCheckLayer * a9);

protected:
    // address=[0x2fccb20]
    virtual void  processFillPoint(int a2, int a3);

};


#endif // CPREVIEWBLOB_H
