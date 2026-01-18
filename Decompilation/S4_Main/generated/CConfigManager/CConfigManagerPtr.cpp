#include "CConfigManagerPtr.h"

// Definitions for class CConfigManagerPtr

// address=[0x2eef110]
// Decompiled from CConfigManager *CConfigManagerPtr::GetInstance()
class IConfigManager * __cdecl CConfigManagerPtr::GetInstance(void) {
  
  CConfigManager *v1; // [esp+8h] [ebp-14h]
  CConfigManager *C; // [esp+Ch] [ebp-10h]

  if ( CConfigManagerPtr::m_pConfigManager )
    return (CConfigManager *)CConfigManagerPtr::m_pConfigManager;
  if ( CConfigManagerPtr::m_bWasDeleted
    && BBSupportDbgReport(2, "Source\\ConfigManager\\ConfigManager.cpp", 1435, "!m_bWasDeleted") == 1 )
  {
    __debugbreak();
  }
  C = (CConfigManager *)operator new(0x1Cu, 1, "Source\\ConfigManager\\ConfigManager.cpp", 1437);
  if ( C )
    v1 = CConfigManager::CConfigManager(C);
  else
    v1 = 0;
  CConfigManagerPtr::m_pConfigManager = (int)v1;
  return v1;
}


// address=[0x2eef1e0]
// Decompiled from void CConfigManagerPtr::DeleteConfigManager()
void __cdecl CConfigManagerPtr::DeleteConfigManager(void) {
  
  if ( CConfigManagerPtr::m_pConfigManager )
  {
    if ( CConfigManagerPtr::m_bWasDeleted
      && BBSupportDbgReport(2, "Source\\ConfigManager\\ConfigManager.cpp", 1452, "!m_bWasDeleted") == 1 )
    {
      __debugbreak();
    }
    if ( CConfigManagerPtr::m_pConfigManager )
      (**(void (__thiscall ***)(int, int))CConfigManagerPtr::m_pConfigManager)(CConfigManagerPtr::m_pConfigManager, 1);
    CConfigManagerPtr::m_pConfigManager = 0;
  }
  CConfigManagerPtr::m_bWasDeleted = 1;
}


// address=[0x46851a4]
// [Decompilation failed for static class IConfigManager * CConfigManagerPtr::m_pConfigManager]

// address=[0x46851a8]
// [Decompilation failed for static bool CConfigManagerPtr::m_bWasDeleted]

