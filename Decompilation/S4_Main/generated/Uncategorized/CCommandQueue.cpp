#include "CCommandQueue.h"

// Definitions for class CCommandQueue

// address=[0x153fec0]
// Decompiled from struct CEntityEvent *__thiscall CCommandQueue::CheckCommand(CCommandQueue *this, struct CEntityEvent *a2)
void  CCommandQueue::CheckCommand(class CEntityEvent *) {
  
  struct CEntityEvent *result; // eax
  int v3; // [esp+0h] [ebp-8h]

  result = a2;
  v3 = *((_DWORD *)a2 + 1);
  if ( v3 == 16 )
    return (struct CEntityEvent *)CCommandQueue::Push(this, a2);
  if ( v3 != 17 )
    return result;
  result = (struct CEntityEvent *)std::deque<CEntityEvent>::size(this);
  if ( result )
    return (struct CEntityEvent *)std::deque<CEntityEvent>::clear(17, this);
  return result;
}


// address=[0x153ff10]
// Decompiled from unsigned int __thiscall CCommandQueue::Push(CCommandQueue *this, struct CEntityEvent *a2)
void  CCommandQueue::Push(class CEntityEvent *) {
  
  unsigned int result; // eax

  result = std::deque<CEntityEvent>::size(this);
  if ( result < 0x10 )
    return std::deque<CEntityEvent>::push_back(a2);
  return result;
}


// address=[0x153ff40]
// Decompiled from CEntityEvent *__thiscall CCommandQueue::Pop(void *this, CEntityEvent *a2)
class CEntityEvent  CCommandQueue::Pop(void) {
  
  _BYTE v3[24]; // [esp+4h] [ebp-30h] BYREF
  void *v4; // [esp+1Ch] [ebp-18h]
  int v5; // [esp+20h] [ebp-14h]
  int v6; // [esp+24h] [ebp-10h]
  int v7; // [esp+30h] [ebp-4h]

  v4 = this;
  v5 = 0;
  if ( std::deque<CEntityEvent>::size(this) )
  {
    v6 = std::deque<CEntityEvent>::front();
    CEntityEvent::CEntityEvent(
      (CEntityEvent *)v3,
      *(_BYTE *)(v6 + 8),
      0,
      *(_DWORD *)(v6 + 12),
      *(_DWORD *)(v6 + 16),
      *(_DWORD *)(v6 + 20));
    v7 = 0;
    std::deque<CEntityEvent>::pop_front(v4);
    CEntityEvent::CEntityEvent((struct boost::exception_detail::clone_base *)v3);
    v5 |= 1u;
    v7 = -1;
    CEntityEvent::~CEntityEvent(v3);
  }
  else
  {
    CEntityEvent::CEntityEvent(a2, 0, 0, 0, 0, 0);
    v5 |= 1u;
  }
  return a2;
}


