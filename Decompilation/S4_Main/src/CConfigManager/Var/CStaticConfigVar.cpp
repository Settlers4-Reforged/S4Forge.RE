#include "CStaticConfigVar.h"

#include "CConfigManager/CConfigManagerPtr.h"

// Definitions for class CStaticConfigVar

// address=[0x12fca40]
// Decompiled from CConfigVar *__thiscall CStaticConfigVar::~CStaticConfigVar(CStaticConfigVar *this)
CStaticConfigVar::~CStaticConfigVar(void) = default;

// address=[0x2eeeea0]
// Decompiled from CStaticConfigVar *__thiscall CStaticConfigVar::CStaticConfigVar(  CStaticConfigVar *this,  int a2,  int arg4,  CONFIGVAR_TYPE a3,  bool a4)
CStaticConfigVar::CStaticConfigVar(char const *a2, char const *, T_CFGVAR_TYPE a4, int a5) : CConfigVar(true, a4, a5)
{
  CConfigManagerPtr::GetInstance()->AddStaticConfigVar(a2);
}
