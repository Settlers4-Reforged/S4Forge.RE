#ifndef CCONFIGVAR_H
#define CCONFIGVAR_H

#include "defines.h"

enum T_CFGVAR_TYPE : __int8
{
    T_CFGVAR_TYPE_INT = 0x1,
    T_CFGVAR_TYPE_INT_ARRAY = 0x2,
    T_CFGVAR_TYPE_FLOAT = 0x3,
    T_CFGVAR_TYPE_STRING = 0x4,
};

class CConfigVar
{
public:
    // address=[0x12fd170]
    virtual float GetFloatValue(void) const;

    // address=[0x12fd1a0]
    virtual int *GetIntArray(void);

    // address=[0x12fd1b0]
    virtual int const *GetIntArray(void) const;

    // address=[0x12fd1c0]
    virtual int GetIntValue(void) const;

    // address=[0x12fd250]
    virtual std::string GetStringValue(void) const;

    // address=[0x12fd690]
    virtual void SetValue(std::string const &a1);

    // address=[0x12fd6a0]
    virtual void SetValue(int a2);

    // address=[0x12fd6b0]
    virtual void SetValue(float a2);

    // address=[0x12fd6c0]
    virtual void SetValue(char const *a2);

    // address=[0x160db90]
    int Size(void) const;

    // address=[0x160dbb0]
    int Type(void) const;

    // address=[0x2efa370]
    bool Static(void) const;

protected:
    // address=[0x12fca20]
    virtual ~CConfigVar(void);

    // address=[0x2ef86a0]
    CConfigVar(bool _bIsStatic, enum T_CFGVAR_TYPE _eType, int _iSize);

    // Type information members
public:
    bool m_bIsStatic;
    T_CFGVAR_TYPE m_cType;
    char m_cSize;
    char m_cU7;
};

#endif // CCONFIGVAR_H
