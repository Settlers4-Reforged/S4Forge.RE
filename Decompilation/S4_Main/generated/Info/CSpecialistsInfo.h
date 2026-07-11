#ifndef CSPECIALISTSINFO_H
#define CSPECIALISTSINFO_H

#include "defines.h"

class CSpecialistsInfo : public CInfoExchange {
public:
    // address=[0x14548f0]
     CSpecialistsInfo(void);

    // address=[0x1454df0]
    virtual unsigned int  Size(void)const;

    // Type information members
public:
    CSpecialistsInfo::SSpecialist[5] m_vSpecialists;

};


#endif // CSPECIALISTSINFO_H
