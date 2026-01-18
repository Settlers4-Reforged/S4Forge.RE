#ifndef CBARRACKSINFO_H
#define CBARRACKSINFO_H

#include "defines.h"

class CBarracksInfo : public CBuildingInfo {
public:
    // address=[0x1454470]
     CBarracksInfo(void);

    // address=[0x1454b10]
    virtual unsigned int  Size(void)const;

};


#endif // CBARRACKSINFO_H
