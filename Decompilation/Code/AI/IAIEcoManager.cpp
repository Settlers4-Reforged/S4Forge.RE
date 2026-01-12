#include "IAIEcoManager.h"

// Definitions for class IAIEcoManager

// address=[0x133ae70]
// Decompiled from CEcoManager *__cdecl IAIEcoManager::CreateEcoManager(int a1, struct IAISectorAI *a2, struct IAIEventQueue *a3)
static class IAIEcoManager * __cdecl IAIEcoManager::CreateEcoManager(int,class IAISectorAI *,class IAIEventQueue *) {
  
  CEcoManager *C; // [esp+Ch] [ebp-10h]

  C = (CEcoManager *)operator new(0x3FE60u);
  if ( C )
    return CEcoManager::CEcoManager(C, a1, a2, a3);
  else
    return 0;
}


// address=[0x1345700]
// Decompiled from IAIEcoManager *__thiscall IAIEcoManager::IAIEcoManager(IAIEcoManager *this)
 IAIEcoManager::IAIEcoManager(void) {
  
  *(_DWORD *)this = &IAIEcoManager::_vftable_;
  return this;
}


// address=[0x1345e20]
// Decompiled from IAIEcoManager *__thiscall IAIEcoManager::~IAIEcoManager(IAIEcoManager *this)
 IAIEcoManager::~IAIEcoManager(void) {
  
  IAIEcoManager *result; // eax

  result = this;
  *(_DWORD *)this = &IAIEcoManager::_vftable_;
  return result;
}


