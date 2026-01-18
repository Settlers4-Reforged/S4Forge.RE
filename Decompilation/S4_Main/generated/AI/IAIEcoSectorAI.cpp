#include "IAIEcoSectorAI.h"

// Definitions for class IAIEcoSectorAI

// address=[0x2f346f0]
// Decompiled from int IAIEcoSectorAI::InterfaceVersion()
int __cdecl IAIEcoSectorAI::InterfaceVersion(void) {
  
  return 2;
}


// address=[0x2f34700]
// Decompiled from CEcoSectorAI *__cdecl IAIEcoSectorAI::CreateEcoSectorAI(struct IAIEcoManager *a1)
class IAIEcoSectorAI * __cdecl IAIEcoSectorAI::CreateEcoSectorAI(class IAIEcoManager * a1) {
  
  int v2; // [esp+8h] [ebp-20h]
  CEcoSectorAI *C; // [esp+10h] [ebp-18h]
  struct IAISectorAI *v5; // [esp+14h] [ebp-14h]
  int v6; // [esp+18h] [ebp-10h]

  if ( !a1 && BBSupportDbgReport(2, "Source\\SiedAI.cpp", 2120, "_pEcoManager != 0") == 1 )
    __debugbreak();
  if ( (**(int (__thiscall ***)(struct IAIEcoManager *))a1)(a1) != 2
    && BBSupportDbgReport(
         2,
         "Source\\SiedAI.cpp",
         2121,
         "_pEcoManager->InterfaceVersion() == IAIEcoManager::INTERFACE_VERSION") == 1 )
  {
    __debugbreak();
  }
  v5 = (struct IAISectorAI *)(*(int (__thiscall **)(struct IAIEcoManager *))(*(_DWORD *)a1 + 332))(a1);
  if ( !v5 && BBSupportDbgReport(2, "Source\\SiedAI.cpp", 2125, "pSectorAI != 0") == 1 )
    __debugbreak();
  v6 = (*(int (__thiscall **)(struct IAIEcoManager *))(*(_DWORD *)a1 + 128))(a1);
  v2 = (*(int (__thiscall **)(struct IAIEcoManager *))(*(_DWORD *)a1 + 136))(a1);
  if ( !v6 && BBSupportDbgReport(2, "Source\\SiedAI.cpp", 2130, "iPlayerId != PLAYER_NO_PLAYER") == 1 )
    __debugbreak();
  C = (CEcoSectorAI *)operator new(0x24u);
  if ( C )
    return CEcoSectorAI::CEcoSectorAI(C, a1, v5, v6, v2);
  else
    return 0;
}


// address=[0x2f3b2e0]
// Decompiled from IAIEcoSectorAI *__thiscall IAIEcoSectorAI::IAIEcoSectorAI(IAIEcoSectorAI *this)
 IAIEcoSectorAI::IAIEcoSectorAI(void) {
  
  IAIUnknown::IAIUnknown(this);
  *(_DWORD *)this = IAIEcoSectorAI::_vftable_;
  return this;
}


