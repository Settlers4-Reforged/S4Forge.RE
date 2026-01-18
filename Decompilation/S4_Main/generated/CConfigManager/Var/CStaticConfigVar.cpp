#include "CStaticConfigVar.h"

// Definitions for class CStaticConfigVar

// address=[0x12fca40]
// Decompiled from CConfigVar *__thiscall CStaticConfigVar::~CStaticConfigVar(CStaticConfigVar *this)
 CStaticConfigVar::~CStaticConfigVar(void) {
  
  return CConfigVar::~CConfigVar(this);
}


// address=[0x2eeeea0]
// Decompiled from _BYTE *__thiscall CStaticConfigVar::CStaticConfigVar(_BYTE *this, int a2, int a3, char a4, char a5)
 CStaticConfigVar::CStaticConfigVar(char const * a2, char const * a3, enum T_CFGVAR_TYPE a4, int a5) {
  
  CConfigManager *Instance; // [esp+4h] [ebp-14h]

  CConfigVar::CConfigVar(this, 1, a4, a5);
  *(_DWORD *)this = &CStaticConfigVar::_vftable_;
  Instance = CConfigManagerPtr::GetInstance();
  ((void (__cdecl *)(int))Instance->j_?AddStaticConfigVar@CConfigManager@@UAEXPBD0AAVCConfigVar@@@Z)(a2);
  return this;
}


