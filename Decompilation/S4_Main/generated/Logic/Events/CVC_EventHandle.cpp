#include "CVC_EventHandle.h"

// Definitions for class CVC_EventHandle

// address=[0x2fd4fb0]
// Decompiled from char __thiscall CVC_EventHandle::RegisterVC(CVC_EventHandle *this, struct CVoiceChat *a2)
void  CVC_EventHandle::RegisterVC(class CVoiceChat * a2) {
  
  *((_DWORD *)this + 1) = a2;
  return IEventEngine::RegisterHandle(g_pEvnEngine, this);
}


// address=[0x2fd4fe0]
// Decompiled from bool __thiscall CVC_EventHandle::UnregisterVC(CVC_EventHandle *this)
void  CVC_EventHandle::UnregisterVC(void) {
  
  return IEventEngine::UnRegisterHandle(g_pEvnEngine, this);
}


// address=[0x2fd5000]
// Decompiled from char __thiscall CVC_EventHandle::OnEvent(CVoiceChat **this, struct CEvn_Event *a2)
bool  CVC_EventHandle::OnEvent(class CEvn_Event & a2) {
  
  return CVoiceChat::OnEvent(this[1], a2);
}


// address=[0x2fd54d0]
// Decompiled from CVC_EventHandle *__thiscall CVC_EventHandle::CVC_EventHandle(CVC_EventHandle *this)
 CVC_EventHandle::CVC_EventHandle(void) {
  
  IEvn_Handle::IEvn_Handle(this);
  *(_DWORD *)this = &CVC_EventHandle::_vftable_;
  return this;
}


