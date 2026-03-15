#include "CAIEventQueue.h"

#include "../LoadSave/IS4Chunk.h"

#include "CBB/CBBSupport.h"

// Definitions for class CAIEventQueue

// address=[0x130a0d0]
// Decompiled from void __thiscall CAIEventQueue::~CAIEventQueue(CDHtmlElementEventSink *this)
CAIEventQueue::~CAIEventQueue(void) = default;


// address=[0x130a240]
// Decompiled from void __thiscall CAIEventQueue::Clear(CAIEventQueue *this)
void CAIEventQueue::Clear(void) {
  this->m_vEvents.clear();
  this->m_uReadCounter = 0;
}


// address=[0x130f720]
// Decompiled from CAIEventQueue *__thiscall CAIEventQueue::CAIEventQueue(CAIEventQueue *this)
CAIEventQueue::CAIEventQueue(void) : IAIEventQueue(), m_vEvents() {
  this->m_vEvents.reserve(8u);
  this->m_uReadCounter = 0;
}


// address=[0x130f7a0]
// Decompiled from char __thiscall CAIEventQueue::PeekAIEvent(CAIEventQueue *this, struct CAIEvent *a2, bool a3)
bool CAIEventQueue::PeekAIEvent(class CAIEvent &a2, bool _bClearOnEnd) {
  DWORD uSize = this->m_vEvents.size();
  if(this->m_uReadCounter >= uSize)
    return false;

  a2 = this->m_vEvents[this->m_uReadCounter];
  if(_bClearOnEnd && ++this->m_uReadCounter == uSize)
    this->Clear();
  return true;
}


// address=[0x130f830]
// Decompiled from CAIEvent *__thiscall CAIEventQueue::PeekAIEvent(CAIEventQueue *this, bool a2)
class CAIEvent const *CAIEventQueue::PeekAIEvent(bool _bIncrementReadCounter) {
  if(this->m_uReadCounter >= this->m_vEvents.size()) {
    if(this->m_uReadCounter)
      this->Clear();
    return nullptr;
  } else {
    CAIEvent *v3 = &this->m_vEvents[this->m_uReadCounter];
    if(_bIncrementReadCounter)
      ++this->m_uReadCounter;
    return v3;
  }
}


// address=[0x130f8a0]
// Decompiled from void __thiscall CAIEventQueue::Load(CAIEventQueue *this, struct IS4Chunk *a2)
void CAIEventQueue::Load(IS4Chunk &a2) {
  // eax
  int iNumberOfEvents; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]

  this->Clear();
  a2.LoadSignature(572187392);
  a2.LoadUnsigned32(16, 16);
  this->m_uReadCounter = a2.LoadUnsigned32();
  iNumberOfEvents = a2.LoadUnsigned32();
  CAIEvent v3{0, 0, 0, 0};
  for(i = 0; i < iNumberOfEvents; ++i) {
    a2.Load(&v3, 16);
    this->m_vEvents.push_back(v3);
  }

  if(this->m_vEvents.size() != iNumberOfEvents
     && BBSupportDbgReport(2, "AI\\AI_EventQueue.cpp", 119, "m_cAIEventVector.size() == iNumberOfEvents") == 1) {
    __debugbreak();
  }
  a2.LoadSignature(572187393);
}


// address=[0x130f9a0]
// Decompiled from void __thiscall CAIEventQueue::Save(CAIEventQueue *this, struct IS4Chunk *a2)
void CAIEventQueue::Save(class IS4Chunk &a2) {
  // [esp+0h] [ebp-Ch]
  // [esp+8h] [ebp-4h]

  a2.SaveSignature(572187392);
  a2.SaveUnsigned32(16);
  a2.SaveUnsigned32(this->m_uReadCounter);

  const size_t uSize = this->m_vEvents.size();
  a2.SaveUnsigned32(uSize);
  for(signed int i = 0; i < uSize; ++i) {
    const CAIEvent &pEvent = this->m_vEvents[i];
    a2.Save(&pEvent, 0x10u);
  }
  a2.SaveSignature(572187393);
}


// address=[0x1319880]
// Decompiled from void __thiscall CAIEventQueue::PostAIEvent(CAIEventQueue *this, int a2, int a3, int a4, int a5)
void CAIEventQueue::PostAIEvent(int _iType, int _iX, int _iY, int _iDark) {
  this->m_vEvents.push_back(CAIEvent(_iType, _iX, _iY, _iDark));
}


