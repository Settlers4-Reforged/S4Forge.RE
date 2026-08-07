#if FALSE
#include "CAIEventQueue.h"

// Definitions for class CAIEventQueue

// address=[0x130a0d0]
// Decompiled from void __thiscall CAIEventQueue::~CAIEventQueue(CDHtmlElementEventSink *this)
 CAIEventQueue::~CAIEventQueue(void) {
  
  std::vector<CAIEvent>::~vector<CAIEvent>(this);
}


// address=[0x130a240]
// Decompiled from void __thiscall CAIEventQueue::Clear(CAIEventQueue *this)
void  CAIEventQueue::Clear(void) {
  
  std::vector<CAIEvent>::clear(&this->m_vEvents);
  this->m_uReadCounter = 0;
}


// address=[0x130f720]
// Decompiled from CAIEventQueue *__thiscall CAIEventQueue::CAIEventQueue(CAIEventQueue *this)
 CAIEventQueue::CAIEventQueue(void) {
  
  IAIEventQueue::IAIEventQueue(this);
  this->__vftable = (IS4ChunkObject_vtbl *)CAIEventQueue::_vftable_;
  std::vector<CAIEvent>::vector<CAIEvent>(&this->m_vEvents);
  std::vector<CAIEvent>::reserve(&this->m_vEvents, 8u);
  this->m_uReadCounter = 0;
  return this;
}


// address=[0x130f7a0]
// Decompiled from char __thiscall CAIEventQueue::PeekAIEvent(CAIEventQueue *this, struct CAIEvent *a2, bool a3)
bool  CAIEventQueue::PeekAIEvent(class CAIEvent & a2, bool a3) {
  
  DWORD uSize; // [esp+0h] [ebp-8h]

  uSize = std::vector<CAIEvent>::size(&this->m_vEvents);
  if ( this->m_uReadCounter >= uSize )
  {
    return 0;
  }
  *a2 = *std::vector<CAIEvent>::operator[](&this->m_vEvents, this->m_uReadCounter);
  if ( a3 && ++this->m_uReadCounter == uSize )
  {
    CAIEventQueue::Clear(this);
  }
  return 1;
}


// address=[0x130f830]
// Decompiled from CAIEvent *__thiscall CAIEventQueue::PeekAIEvent(CAIEventQueue *this, bool a2)
class CAIEvent const *  CAIEventQueue::PeekAIEvent(bool a2) {
  
  CAIEvent *v3; // [esp+0h] [ebp-Ch]

  if ( this->m_uReadCounter >= std::vector<CAIEvent>::size(&this->m_vEvents) )
  {
    if ( this->m_uReadCounter )
    {
      CAIEventQueue::Clear(this);
    }
    return 0;
  }
  else
  {
    v3 = std::vector<CAIEvent>::operator[](&this->m_vEvents, this->m_uReadCounter);
    if ( a2 )
    {
      ++this->m_uReadCounter;
    }
    return v3;
  }
}


// address=[0x130f8a0]
// Decompiled from void __thiscall CAIEventQueue::Load(CAIEventQueue *this, struct IS4Chunk *a2)
void  CAIEventQueue::Load(class IS4Chunk & a2) {
  
  int v2; // eax
  CAIEvent v3; // [esp+0h] [ebp-1Ch] BYREF
  int iNumberOfEvents; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]

  CAIEventQueue::Clear(this);
  a2->LoadSignature(572187392);
  a2->LoadUnsigned32(16, 16);
  this->m_uReadCounter = a2->LoadUnsigned32_(a2);
  iNumberOfEvents = a2->LoadUnsigned32_(a2);
  CAIEvent::CAIEvent(&v3, 0, 0, 0, 0);
  for ( i = 0;
        i < iNumberOfEvents;
        ++i )
  {
    a2->Load(&v3, 16);
    std::vector<CAIEvent>::push_back(&v3);
  }
  v2 = std::vector<CAIEvent>::size(&this->m_vEvents);
  if ( v2 != iNumberOfEvents && BBSupportDbgReport(2, "AI\\AI_EventQueue.cpp", 119, "m_cAIEventVector.size() == iNumberOfEvents") == 1 )
  {
    __debugbreak();
  }
  a2->LoadSignature(572187393);
}


// address=[0x130f9a0]
// Decompiled from void __thiscall CAIEventQueue::Save(CAIEventQueue *this, struct IS4Chunk *a2)
void  CAIEventQueue::Save(class IS4Chunk & a2) {
  
  CAIEvent *pEvent; // eax
  int uSize; // [esp+0h] [ebp-Ch]
  signed int a1; // [esp+8h] [ebp-4h]

  a2->SaveSignature(572187392);
  a2->SaveUnsigned32(16);
  a2->SaveUnsigned32(this->m_uReadCounter);
  uSize = std::vector<CAIEvent>::size(&this->m_vEvents);
  a2->SaveUnsigned32(uSize);
  for ( a1 = 0;
        a1 < uSize;
        ++a1 )
  {
    pEvent = std::vector<CAIEvent>::operator[](&this->m_vEvents, a1);
    a2->Save(pEvent, 0x10u);
  }
  a2->SaveSignature(572187393);
}


// address=[0x1319880]
// Decompiled from void __thiscall CAIEventQueue::PostAIEvent(CAIEventQueue *this, int a2, int a3, int a4, int a5)
void  CAIEventQueue::PostAIEvent(int a2, int a3, int a4, int a5) {
  
  CAIEvent *v5; // eax
  CAIEvent v6; // [esp+0h] [ebp-14h] BYREF

  v5 = CAIEvent::CAIEvent(&v6, a2, a3, a4, a5);
  std::vector<CAIEvent>::push_back(&this->m_vEvents, v5);
}


#endif // Already implemented
