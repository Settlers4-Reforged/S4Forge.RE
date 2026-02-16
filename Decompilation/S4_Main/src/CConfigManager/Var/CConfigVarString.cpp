#include "CConfigVarString.h"

// Definitions for class CConfigVarString

// address=[0x2efa0f0]
// Decompiled from int __thiscall CConfigVarString::GetStringValue(char *this, int a2)
std::string CConfigVarString::GetStringValue() const
{
  return this->value;
}

// address=[0x2efa310]
// Decompiled from void __thiscall CConfigVarString::SetValue(CConfigVarString *this, void *a1)
void CConfigVarString::SetValue(std::string const &a1)
{
  this->value = a1;
}

// address=[0x2efa340]
// Decompiled from void __thiscall CConfigVarString::SetValue(CConfigVarString *this, char *Str)
void CConfigVarString::SetValue(char const *Str)
{
  this->value = Str;
}

// address=[0x2ef8770]
// Decompiled from CConfigVarString *__thiscall CConfigVarString::CConfigVarString(CConfigVarString *this, int a2)
CConfigVarString::CConfigVarString(std::string const &a2) : CDynamicConfigVar(T_CFGVAR_TYPE_STRING, 1), value(a2)
{
}

// address=[0x2ef8c80]
// Decompiled from CConfigVar *__thiscall CConfigVarString::~CConfigVarString(CConfigVarString *this)
CConfigVarString::~CConfigVarString(void) = default;
