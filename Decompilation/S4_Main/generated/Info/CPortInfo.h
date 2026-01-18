#ifndef CPORTINFO_H
#define CPORTINFO_H

#include "defines.h"

class CPortInfo : public CBuildingInfo {
public:
    // address=[0x14547a0]
     CPortInfo(void);

    // address=[0x1454d10]
    virtual unsigned int  Size(void)const;

};


#endif // CPORTINFO_H
