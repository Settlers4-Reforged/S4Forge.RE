#ifndef CFREECARRIERINFO_H
#define CFREECARRIERINFO_H

#include "defines.h"
#include "CInfoExchange.h"

class CFreeCarrierInfo : public CInfoExchange
{
public:
    // address=[0x14545f0]
    CFreeCarrierInfo(void);

    // address=[0x1454bf0]
    virtual unsigned int Size(void) const;

    // Type information members
public:
    int m_uNrOfSettlers;
    int m_uNrOfCarriers;
    int m_uNrOfNonCarriers;
    int m_uNrOfDigger;
    int m_uNrOfFreeDigger;
    bool m_bHasShovels;
    int m_uNrOfShovels;
    int m_uNrOfBuilders;
    int m_uNrOfFreeBuilders;
    bool m_bHasHammers;
    int m_uNrOfHammers;
    char m_bLooksAtEcoSector;
};

#endif // CFREECARRIERINFO_H
