#include "CAIEventQueue.h"

// Definitions for class CAIEventQueue

// address=[0x130a0d0]
// Decompiled from void __thiscall CAIEventQueue::~CAIEventQueue(CDHtmlElementEventSink *this)

 CAIEventQueue::~CAIEventQueue(void) {
  
  std::vector<CAIEvent>::~vector<CAIEvent>(this);
}


// address=[0x130a240]
// Decompiled from int __thiscall CAIEventQueue::Clear(CAIEventQueue *this)

void  CAIEventQueue::Clear(void) {
  
  int result; // eax
  int v2; // [esp+0h] [ebp-4h]

  std::vector<CAIEvent>::clear(this);
  result = v2;
  *(_DWORD *)(v2 + 4) = 0;
  return result;
}


// address=[0x130f720]
// Decompiled from CAIEventQueue *__thiscall CAIEventQueue::CAIEventQueue(CAIEventQueue *this)

 CAIEventQueue::CAIEventQueue(void) {
  
  IAIEventQueue::IAIEventQueue(this);
  *(_DWORD *)this = CAIEventQueue::_vftable_;
  std::vector<CAIEvent>::vector<CAIEvent>();
  std::vector<CAIEvent>::reserve(8);
  *((_DWORD *)this + 1) = 0;
  return this;
}


// address=[0x130f7a0]
// Decompiled from char __thiscall CAIEventQueue::PeekAIEvent(CAIEventQueue *this, struct CAIEvent *a2, bool a3)

bool  CAIEventQueue::PeekAIEvent(class CAIEvent &,bool) {
  
  _DWORD *v3; // eax
  unsigned int v5; // [esp+0h] [ebp-8h]

  v5 = std::vector<CAIEvent>::size((char *)this + 8);
  if ( *((_DWORD *)this + 1) >= v5 )
    return 0;
  v3 = (_DWORD *)std::vector<CAIEvent>::operator[](*((_DWORD *)this + 1));
  *(_DWORD *)a2 = *v3;
  *((_DWORD *)a2 + 1) = v3[1];
  *((_DWORD *)a2 + 2) = v3[2];
  *((_DWORD *)a2 + 3) = v3[3];
  if ( a3 && ++*((_DWORD *)this + 1) == v5 )
    CAIEventQueue::Clear(this);
  return 1;
}


// address=[0x130f830]
// Decompiled from int __thiscall CAIEventQueue::PeekAIEvent(CAIEventQueue *this, bool a2)

class CAIEvent const *  CAIEventQueue::PeekAIEvent(bool) {
  
  int v3; // [esp+0h] [ebp-Ch]

  if ( *((_DWORD *)this + 1) >= (unsigned int)std::vector<CAIEvent>::size((char *)this + 8) )
  {
    if ( *((_DWORD *)this + 1) )
      CAIEventQueue::Clear(this);
    return 0;
  }
  else
  {
    v3 = std::vector<CAIEvent>::operator[](*((_DWORD *)this + 1));
    if ( a2 )
      ++*((_DWORD *)this + 1);
    return v3;
  }
}


// address=[0x130f8a0]
// Decompiled from int __thiscall CAIEventQueue::Load(CAIEventQueue *this, struct IS4Chunk *a2)

void  CAIEventQueue::Load(class IS4Chunk &) {
  
  int v2; // eax
  _BYTE v4[16]; // [esp+0h] [ebp-1Ch] BYREF
  int v5; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  CAIEventQueue *v7; // [esp+18h] [ebp-4h]

  v7 = this;
  CAIEventQueue::Clear(this);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 572187392);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 16, 16);
  *((_DWORD *)v7 + 1) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  v5 = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  CAIEvent::CAIEvent((CAIEvent *)v4, 0, 0, 0, 0);
  for ( i = 0; i < v5; ++i )
  {
    (**(void (__thiscall ***)(struct IS4Chunk *, _BYTE *, int))a2)(a2, v4, 16);
    std::vector<CAIEvent>::push_back(v4);
  }
  v2 = std::vector<CAIEvent>::size((char *)v7 + 8);
  if ( v2 != v5
    && BBSupportDbgReport(2, "AI\\AI_EventQueue.cpp", 119, "m_cAIEventVector.size() == iNumberOfEvents") == 1 )
  {
    __debugbreak();
  }
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 572187393);
}


// address=[0x130f9a0]
// Decompiled from int __thiscall CAIEventQueue::Save(CAIEventQueue *this, struct IS4Chunk *a2)

void  CAIEventQueue::Save(class IS4Chunk &) {
  
  int v2; // eax
  int v4; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 572187392);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 16);
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 1));
  v4 = std::vector<CAIEvent>::size((char *)this + 8);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, v4);
  for ( i = 0; i < v4; ++i )
  {
    v2 = std::vector<CAIEvent>::operator[](i);
    (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 16))(a2, v2, 16);
  }
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 572187393);
}


// address=[0x1319880]
// Decompiled from int __thiscall CAIEventQueue::PostAIEvent(CAIEventQueue *this, int a2, int a3, int a4, int a5)

void  CAIEventQueue::PostAIEvent(int,int,int,int) {
  
  CAIEvent *v5; // eax
  _BYTE v7[16]; // [esp+0h] [ebp-14h] BYREF
  CAIEventQueue *v8; // [esp+10h] [ebp-4h]

  v8 = this;
  v5 = CAIEvent::CAIEvent((CAIEvent *)v7, a2, a3, a4, a5);
  return std::vector<CAIEvent>::push_back(v5);
}


