#ifndef CAICONFIGINTEX_H
#define CAICONFIGINTEX_H

#include "defines.h"

class CAIConfigIntEx : public ?$TStaticConfigIntArray@$02 {
public:
    // address=[0x131e810]
     CAIConfigIntEx(char const * a2, int a3, int a4, int a5);

    // address=[0x131ea80]
    virtual  ~CAIConfigIntEx(void);

    // address=[0x131ecd0]
    char const *  Name(void)const;

    // Type information members
public:
    int[3] m_aData;
    const char * m_spName;

};


#endif // CAICONFIGINTEX_H
