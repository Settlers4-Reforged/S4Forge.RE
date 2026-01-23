#ifndef CBARRACKSINFO_H
#define CBARRACKSINFO_H

#include "defines.h"

#include "CBuildingInfo.h"

class CBarracksInfo : public CBuildingInfo
{
public:
    // address=[0x1454470]
    CBarracksInfo(void);

    // address=[0x1454b10]
    virtual unsigned int Size(void) const;

private:
    struct Pair
    {
        BYTE m_mPileGoodType;
        BYTE m_cPileAmount;
    };

    // Type information members
public:
    Pair m_sPairs[6];
};

#endif // CBARRACKSINFO_H
