#include "IConfigManager.h"

// Definitions for class IConfigManager

// address=[0x2eef090]
// Decompiled from CConfigManager *IConfigManager::CreateConfigManger()
static class IConfigManager * __cdecl IConfigManager::CreateConfigManger(void) {
  
  CConfigManager *C; // [esp+Ch] [ebp-10h]

  C = (CConfigManager *)operator new(0x1Cu, 1, "Source\\ConfigManager\\ConfigManager.cpp", 1407);
  if ( C )
    return CConfigManager::CConfigManager(C);
  else
    return 0;
}


// address=[0x2ef8840]
// Decompiled from IConfigManager *__thiscall IConfigManager::IConfigManager(IConfigManager *this)
 IConfigManager::IConfigManager(void) {
  
  *(_DWORD *)this = &IConfigManager::_vftable_;
  return this;
}


// address=[0x2ef8cd0]
// Decompiled from IConfigManager *__thiscall IConfigManager::~IConfigManager(IConfigManager *this)
 IConfigManager::~IConfigManager(void) {
  
  IConfigManager *result; // eax

  result = this;
  *(_DWORD *)this = &IConfigManager::_vftable_;
  return result;
}


