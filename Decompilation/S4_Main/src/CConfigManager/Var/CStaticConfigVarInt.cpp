#include "CStaticConfigVarInt.h"

// Definitions for class CStaticConfigVarInt

// address=[0x12fc830]
// Decompiled from CStaticConfigVarInt *__thiscall CStaticConfigVarInt::CStaticConfigVarInt(  CStaticConfigVarInt *this,  const char *a2,  const char *a3,  int a4)
CStaticConfigVarInt::CStaticConfigVarInt(char const *a2, char const *a3, int a4) : CStaticConfigVar(a2, a3, T_CFGVAR_TYPE_INT, 1), value(a4)
{
}

// address=[0x12fca60]
// Decompiled from void __thiscall CStaticConfigVarInt::~CStaticConfigVarInt(CStaticConfigVarInt *this)
CStaticConfigVarInt::~CStaticConfigVarInt(void) = default;

// address=[0x12fcc30]
// Decompiled from int __thiscall CStaticConfigVarInt::operator int(CStaticConfigVarInt *this)
CStaticConfigVarInt::operator int(void) const
{

  return this->value;
}

// address=[0x12fd180]
// Decompiled from double __thiscall CStaticConfigVarInt::GetFloatValue(CStaticConfigVarInt *this)
float CStaticConfigVarInt::GetFloatValue(void) const
{

  return (float)this->value;
}

// address=[0x12fd1d0]
// Decompiled from int __thiscall CStaticConfigVarInt::GetIntValue(CStaticConfigVarInt *this)
int CStaticConfigVarInt::GetIntValue(void) const
{

  return this->value;
}

// address=[0x12fd6d0]
// Decompiled from void __thiscall CStaticConfigVarInt::SetValue(CStaticConfigVarInt *this, int a2)
void CStaticConfigVarInt::SetValue(int a2)
{

  this->value = a2;
}

// address=[0x12fd6f0]
// Decompiled from void __thiscall CStaticConfigVarInt::SetValue(CStaticConfigVarInt *this, float a2)
void CStaticConfigVarInt::SetValue(float a2)
{

  this->value = (int)a2;
}

// address=[0x1355250]
// Decompiled from void __thiscall CStaticConfigVarInt::operator=(CStaticConfigVarInt *this, int a2)
class CStaticConfigVarInt &CStaticConfigVarInt::operator=(int a2)
{

  this->value = a2;
}
