#ifndef CINFOEXCHANGEEX_H
#define CINFOEXCHANGEEX_H

#include "defines.h"
#include "CInfoExchange.h"


class CInfoExchangeEx : public CInfoExchange {
public:
    // address=[0x1454680]
     CInfoExchangeEx(void);

    // address=[0x1454c50]
    virtual unsigned int  Size(void)const;

};

extern CInfoExchangeEx g_cInfoExchange;


#endif // CINFOEXCHANGEEX_H
