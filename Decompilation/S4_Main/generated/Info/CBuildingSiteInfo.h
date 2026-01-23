#ifndef CBUILDINGSITEINFO_H
#define CBUILDINGSITEINFO_H

#include "defines.h"

class CBuildingSiteInfo : public CBuildingInfo {
public:
    // address=[0x1454500]
     CBuildingSiteInfo(void);

    // address=[0x1454b50]
    virtual unsigned int  Size(void)const;

    // Type information members
public:
    CBuildingSiteInfo::Ressource[3] m_sRequiredRessources;
    CBuildingSiteInfo::Ressource[3] m_sOtherRessources;
    BYTE m_unknown20;
    BYTE m_unknown21;
    BYTE m_unknown22;
    BYTE m_unknown23;

};


#endif // CBUILDINGSITEINFO_H
