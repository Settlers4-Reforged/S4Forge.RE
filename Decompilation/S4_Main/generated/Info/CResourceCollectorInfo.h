#ifndef CRESOURCECOLLECTORINFO_H
#define CRESOURCECOLLECTORINFO_H

#include "defines.h"

class CResourceCollectorInfo : public CBuildingInfo {
public:
    // address=[0x14547d0]
     CResourceCollectorInfo(void);

    // address=[0x1454d30]
    virtual unsigned int  Size(void)const;

    // Type information members
public:
    unsigned __int8 m_uGood;
    unsigned __int8 m_uAmount;

};


#endif // CRESOURCECOLLECTORINFO_H
