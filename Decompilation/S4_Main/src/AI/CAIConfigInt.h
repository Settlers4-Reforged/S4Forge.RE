#ifndef CAICONFIGINT_H
#define CAICONFIGINT_H

#include "defines.h"
#include "CConfigManager/Var/CStaticConfigVarInt.h"

class CAIConfigInt : public CStaticConfigVarInt {
public:
    // address=[0x12fc7b0]
    CAIConfigInt(char const *_spVarName, int _iDefault);

    // address=[0x12fc9e0]
    virtual ~CAIConfigInt(void);
};


#endif // CAICONFIGINT_H
