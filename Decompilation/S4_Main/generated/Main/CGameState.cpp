#if FALSE
#include "CGameState.h"

// Definitions for class CGameState

// address=[0x13728e0]
// Decompiled from char __stdcall CGameState::OnEvent(int a1)
bool  CGameState::OnEvent(class CEvn_Event & a1) {
  
  return 0;
}


// address=[0x149d860]
// Decompiled from CGameState *__cdecl CGameState::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CGameState::DynamicCreateFunc(void * a1) {
  
  CGameState *v3; // [esp+Ch] [ebp-10h]

  v3 = (CGameState *)operator new(4u);
  if ( v3 )
  {
    return CGameState::CGameState(v3, a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x149d900]
// Decompiled from CGameState *__thiscall CGameState::CGameState(CGameState *this, void *a2)
 CGameState::CGameState(void * a2) {
  
  this->__vftable = (CGameState_vtbl *)&CGameState::_vftable_;
  return this;
}


// address=[0x149d920]
// Decompiled from CGameState *__thiscall CGameState::~CGameState(CGameState *this)
 CGameState::~CGameState(void) {
  
  CGameState *result; // eax

  result = this;
  this->__vftable = (CGameState_vtbl *)&CGameState::_vftable_;
  return result;
}


// address=[0x149d980]
// Decompiled from char __thiscall CGameState::CanProcessInvites(CGameState *this)
bool  CGameState::CanProcessInvites(void) {
  
  return 1;
}


// address=[0x149d990]
// Decompiled from char CGameState::Perform()
bool  CGameState::Perform(void) {
  
  if ( BBSupportDbgReport(2, "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\main\\states\\GameState.h", 54, "false") == 1 )
  {
    __debugbreak();
  }
  return 0;
}


// address=[0x149f3c0]
// Decompiled from CGameState *__thiscall CGameState::CGameState(CGameState *this)
 CGameState::CGameState(void) {
  
  this->__vftable = (CGameState_vtbl *)&CGameState::_vftable_;
  return this;
}


#endif // Already implemented
