#ifndef CINFOEXCHANGEINT_H
#define CINFOEXCHANGEINT_H

#include "defines.h"
#include "CInfoExchange.h"

class CInfoExchangeInt : public CInfoExchange {
public:
    // address=[0x14546b0]
     CInfoExchangeInt(void);

    // address=[0x1454c70]
    virtual unsigned int  Size(void)const;

    uint32_t m_uData;
};

extern CInfoExchangeInt g_cInfoExchangeInt;

#endif // CINFOEXCHANGEINT_H
