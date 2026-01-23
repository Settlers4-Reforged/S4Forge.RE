#ifndef CBUILDINGSITEINFO_H
#define CBUILDINGSITEINFO_H

#include "defines.h"

#include "CBuildingInfo.h"

class CBuildingSiteInfo : public CBuildingInfo
{
public:
    // address=[0x1454500]
    CBuildingSiteInfo(void);

    // address=[0x1454b50]
    virtual unsigned int Size(void) const;

private:
    struct Ressource
    {
        BYTE m_cType;
        BYTE m_cAmount;
    };

    // Type information members
public:
    Ressource m_sRequiredRessources[3];
    Ressource m_sOtherRessources[3];
    BYTE m_unknown20;
    BYTE m_unknown21;
    BYTE m_unknown22;
    BYTE m_unknown23;

};

#endif // CBUILDINGSITEINFO_H
