#ifndef CECONOMYGAMEINFO_H
#define CECONOMYGAMEINFO_H

#include "defines.h"

class CEconomyGameInfo : public CInfoExchange {
public:
    // address=[0x1454530]
     CEconomyGameInfo(void);

    // address=[0x1454b70]
    virtual unsigned int  Size(void)const;

    // Type information members
public:
    CEconomyGameInfo::Stat[7] m_sStats;

};


#endif // CECONOMYGAMEINFO_H
