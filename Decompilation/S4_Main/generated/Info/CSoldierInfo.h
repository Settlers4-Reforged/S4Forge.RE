#ifndef CSOLDIERINFO_H
#define CSOLDIERINFO_H

#include "defines.h"

class CSoldierInfo : public CInfoExchange {
public:
    // address=[0x14548c0]
     CSoldierInfo(void);

    // address=[0x1454dd0]
    virtual unsigned int  Size(void)const;

};


#endif // CSOLDIERINFO_H
