#ifndef CLINK_H
#define CLINK_H

#include "defines.h"

class CLink {
public:
    // address=[0x15e7010]
    bool  IsHeader(void)const;

    // address=[0x15e74d0]
    bool  Unused(void)const;

    // address=[0x15e7550]
    bool  Used(void)const;

    // address=[0x15f5360]
    bool  PrevLinkIsLastOne(void)const;

    // Type information members
public:
    WORD m_uData;

};


#endif // CLINK_H
