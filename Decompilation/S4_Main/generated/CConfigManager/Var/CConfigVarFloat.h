#ifndef CCONFIGVARFLOAT_H
#define CCONFIGVARFLOAT_H

#include "defines.h"

class CConfigVarFloat : public CDynamicConfigVar {
public:
    // address=[0x2efa030]
    virtual float  GetFloatValue(void)const;

    // address=[0x2efa0b0]
    virtual int  GetIntValue(void)const;

    // address=[0x2efa290]
    virtual void  SetValue(int a2);

    // address=[0x2efa2b0]
    virtual void  SetValue(float a2);

private:
    // address=[0x2ef86f0]
     CConfigVarFloat(float a2);

    // address=[0x2ef8c20]
    virtual  ~CConfigVarFloat(void);

};


#endif // CCONFIGVARFLOAT_H
