#ifndef CINFOEXCHANGE_H
#define CINFOEXCHANGE_H

#include "defines.h"

class CInfoExchange {
public:
    // address=[0x1454320]
    virtual void  Clear(void);

    virtual unsigned int Size(void) const = 0;

protected:
    // address=[0x1415220]
     CInfoExchange(void);

    // Type information members
public:
    uint32_t m_iUnknown;
};


#endif // CINFOEXCHANGE_H
