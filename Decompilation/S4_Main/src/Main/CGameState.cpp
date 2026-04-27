#include "CGameState.h"

#include "CBB/CBBSupport.h"

// Definitions for class CGameState

// address=[0x13728e0]
// Decompiled from char __stdcall CGameState::OnEvent(int a1)
bool CGameState::OnEvent(class CEvn_Event &a1) {
  return 0;
}


// address=[0x149d860]
// Decompiled from CGameState *__cdecl CGameState::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CGameState::DynamicCreateFunc(void *a1) {
  return new CGameState(a1);
}


// address=[0x149d900]
// Decompiled from CGameState *__thiscall CGameState::CGameState(CGameState *this, void *a2)
CGameState::CGameState(void *a2) {}


// address=[0x149d920]
// Decompiled from CGameState *__thiscall CGameState::~CGameState(CGameState *this)
CGameState::~CGameState(void) = default;


// address=[0x149d980]
// Decompiled from char __thiscall CGameState::CanProcessInvites(CGameState *this)
bool CGameState::CanProcessInvites(void) {
  return 1;
}


// address=[0x149d990]
// Decompiled from char CGameState::Perform()
bool CGameState::Perform(void) {
  BB_REPORT("Pure Virtual: CGameState::Perform()");
}


// address=[0x149f3c0]
// Decompiled from CGameState *__thiscall CGameState::CGameState(CGameState *this)
CGameState::CGameState(void) {}


