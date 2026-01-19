#ifndef CINFOEXCHANGE_H
#define CINFOEXCHANGE_H

#include "defines.h"

class CInfoExchange {
public:
    // address=[0x1454320]
    virtual void  Clear(void);

protected:
    // address=[0x1415220]
     CInfoExchange(void);

    // Type information members
public:
    DWORD[] m_iUnknown;

};


#endif // CINFOEXCHANGE_H
