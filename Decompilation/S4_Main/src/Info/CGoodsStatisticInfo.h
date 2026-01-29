#ifndef CGOODSSTATISTICINFO_H
#define CGOODSSTATISTICINFO_H

#include "defines.h"
#include "CInfoExchange.h"

class CGoodsStatisticInfo : public CInfoExchange
{
public:
    // address=[0x1454620]
    CGoodsStatisticInfo(void);

    // address=[0x1454c10]
    virtual unsigned int Size(void) const;

private:
    struct Statistic
    {
        DWORD m_uGoodId;
        DWORD m_uGoodCount;
    };

    // Type information members
public:
    bool m_bOverEcoSector;
    Statistic m_aStatistics[43];
};

#endif // CGOODSSTATISTICINFO_H
