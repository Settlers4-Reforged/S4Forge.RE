#ifndef CSPECIALISTSINFO_H
#define CSPECIALISTSINFO_H

#include "Logic/CInfoExchange.h"
#include "defines.h"

class CSpecialistsInfo : public CInfoExchange {
  public:
    // address=[0x14548f0]
    CSpecialistsInfo(void);

    // address=[0x1454df0]
    virtual unsigned int Size(void) const;

    // Type information members
  public:
    struct {
        int m_iHitpoints;
        int m_iDamageTaken;
        int m_iCount;
    } m_vSpecialists[5];
};

#endif // CSPECIALISTSINFO_H
