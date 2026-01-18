#ifndef CCONFIGVAR_H
#define CCONFIGVAR_H

#include "defines.h"

class CConfigVar {
public:
    // address=[0x12fd170]
    virtual float  GetFloatValue(void)const;

    // address=[0x12fd1a0]
    virtual int *  GetIntArray(void);

    // address=[0x12fd1b0]
    virtual int const *  GetIntArray(void)const;

    // address=[0x12fd1c0]
    virtual int  GetIntValue(void)const;

    // address=[0x12fd250]
    virtual std::string  GetStringValue(void a1)const;

    // address=[0x12fd690]
    virtual void  SetValue(std::string const & a1);

    // address=[0x12fd6a0]
    virtual void  SetValue(int a2);

    // address=[0x12fd6b0]
    virtual void  SetValue(float a2);

    // address=[0x12fd6c0]
    virtual void  SetValue(char const * a2);

    // address=[0x160db90]
    int  Size(void)const;

    // address=[0x160dbb0]
    int  Type(void)const;

    // address=[0x2efa370]
    bool  Static(void)const;

private:
    // address=[0x12fca20]
    virtual  ~CConfigVar(void);

    // address=[0x2ef86a0]
     CConfigVar(bool a2, enum T_CFGVAR_TYPE a3, int a4);

};


#endif // CCONFIGVAR_H
