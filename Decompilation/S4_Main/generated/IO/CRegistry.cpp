#include "all_headers.h"

// Definitions for class CRegistry

// address=[0x149aa80]
// Decompiled from char __stdcall CRegistry::ExistsHLMKey(LPCSTR lpSubKey)
bool  CRegistry::ExistsHLMKey(char const *) {
  
  HKEY phkResult; // [esp+4h] [ebp-8h] BYREF

  if ( !lpSubKey || !*lpSubKey )
    return 0;
  if ( RegOpenKeyExA(HKEY_LOCAL_MACHINE, lpSubKey, 0, 0x20019u, &phkResult) )
    return 0;
  RegCloseKey(phkResult);
  return 1;
}


// address=[0x149ab00]
// Decompiled from CRegistry *__thiscall CRegistry::CRegistry(CRegistry *this)
 CRegistry::CRegistry(void) {
  
  IRegistry::IRegistry(this);
  *(_DWORD *)this = &CRegistry::_vftable_;
  return this;
}


