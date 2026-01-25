#ifndef CECONOMYGAMEINFO_H
#define CECONOMYGAMEINFO_H

#include "defines.h"
#include "CInfoExchange.h"

class CEconomyGameInfo : public CInfoExchange
{
public:
    // address=[0x1454530]
    CEconomyGameInfo(void);

    // address=[0x1454b70]
    virtual unsigned int Size(void) const;

private:
    struct CEconomyGameInfo::Stat
    {
        DWORD m_uEconomyGood;
        DWORD m_uWinGoodsAllies;
        DWORD m_uWinGoodsOther;
    };

    // Type information members
public:
    CEconomyGameInfo::Stat m_sStats[7];
};

#endif // CECONOMYGAMEINFO_H
