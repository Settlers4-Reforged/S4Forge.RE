#ifndef CGOODSSTATISTICINFO_H
#define CGOODSSTATISTICINFO_H

#include "defines.h"

class CGoodsStatisticInfo : public CInfoExchange {
public:
    // address=[0x1454620]
     CGoodsStatisticInfo(void);

    // address=[0x1454c10]
    virtual unsigned int  Size(void)const;

    // Type information members
public:
    bool m_bOverEcoSector;
    CGoodsStatisticInfo::Statistic[43] m_aStatistics;

};


#endif // CGOODSSTATISTICINFO_H
