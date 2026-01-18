#ifndef CSTATICCONFIGVAR_H
#define CSTATICCONFIGVAR_H

#include "defines.h"

class CStaticConfigVar : public CConfigVar {
public:
    // address=[0x12fca40]
    virtual  ~CStaticConfigVar(void);

protected:
    // address=[0x2eeeea0]
     CStaticConfigVar(char const * a2, char const * a3, enum T_CFGVAR_TYPE a4, int a5);

};


#endif // CSTATICCONFIGVAR_H
