#ifndef CAICONFIGINT_H
#define CAICONFIGINT_H

#include "defines.h"

class CAIConfigInt : public CStaticConfigVarInt {
public:
    // address=[0x12fc7b0]
     CAIConfigInt(char const * a2, int a3);

    // address=[0x12fc9e0]
    virtual  ~CAIConfigInt(void);

};


#endif // CAICONFIGINT_H
