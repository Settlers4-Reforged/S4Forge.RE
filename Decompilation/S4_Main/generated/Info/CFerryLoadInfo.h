#ifndef CFERRYLOADINFO_H
#define CFERRYLOADINFO_H

#include "defines.h"

class CFerryLoadInfo : public CInfoExchange {
public:
    // address=[0x14545c0]
     CFerryLoadInfo(void);

    // address=[0x1454bd0]
    virtual unsigned int  Size(void)const;

    // Type information members
public:
    DWORD[5] m_uCargpCount3;
    DWORD[5] m_uCargpCount2;
    DWORD[2] m_uCargpCount1;

};


#endif // CFERRYLOADINFO_H
