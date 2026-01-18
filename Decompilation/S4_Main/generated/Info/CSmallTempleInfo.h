#ifndef CSMALLTEMPLEINFO_H
#define CSMALLTEMPLEINFO_H

#include "defines.h"

class CSmallTempleInfo : public CBuildingInfo {
public:
    // address=[0x1454890]
     CSmallTempleInfo(void);

    // address=[0x1454db0]
    virtual unsigned int  Size(void)const;

};


#endif // CSMALLTEMPLEINFO_H
