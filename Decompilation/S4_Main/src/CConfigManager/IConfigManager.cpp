#include "IConfigManager.h"

#include "CConfigManager.h"

// Definitions for class IConfigManager

// address=[0x2eef090]
// Decompiled from CConfigManager *IConfigManager::CreateConfigManger()
class IConfigManager *__cdecl IConfigManager::CreateConfigManger(void)
{
  return new CConfigManager();
}

// address=[0x2ef8840]
// Decompiled from IConfigManager *__thiscall IConfigManager::IConfigManager(IConfigManager *this)
IConfigManager::IConfigManager(void) = default;

// address=[0x2ef8cd0]
// Decompiled from IConfigManager *__thiscall IConfigManager::~IConfigManager(IConfigManager *this)
IConfigManager::~IConfigManager(void) = default;
