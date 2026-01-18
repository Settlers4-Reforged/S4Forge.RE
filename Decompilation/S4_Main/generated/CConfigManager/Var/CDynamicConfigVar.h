#ifndef CDYNAMICCONFIGVAR_H
#define CDYNAMICCONFIGVAR_H

#include "defines.h"

class CDynamicConfigVar : public CConfigVar {
public:
    // address=[0x2ef8cb0]
    virtual  ~CDynamicConfigVar(void);

protected:
    // address=[0x2ef8800]
     CDynamicConfigVar(enum T_CFGVAR_TYPE a2, int a3);

};


#endif // CDYNAMICCONFIGVAR_H
