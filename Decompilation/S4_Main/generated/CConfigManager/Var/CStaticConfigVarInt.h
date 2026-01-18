#ifndef CSTATICCONFIGVARINT_H
#define CSTATICCONFIGVARINT_H

#include "defines.h"

class CStaticConfigVarInt : public CStaticConfigVar {
public:
    // address=[0x12fc830]
     CStaticConfigVarInt(char const * a2, char const * a3, int a4);

    // address=[0x12fca60]
    virtual  ~CStaticConfigVarInt(void);

    // address=[0x12fcc30]
     operator int(void)const;

    // address=[0x12fd180]
    virtual float  GetFloatValue(void)const;

    // address=[0x12fd1d0]
    virtual int  GetIntValue(void)const;

    // address=[0x12fd6d0]
    virtual void  SetValue(int a2);

    // address=[0x12fd6f0]
    virtual void  SetValue(float a2);

    // address=[0x1355250]
    class CStaticConfigVarInt &  operator=(int a2);

};


#endif // CSTATICCONFIGVARINT_H
