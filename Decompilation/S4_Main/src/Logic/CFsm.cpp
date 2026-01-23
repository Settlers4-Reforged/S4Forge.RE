#include "CFsm.h"

#include "./Events/IEventHandler.h"

// Definitions for class CFsm

// address=[0x1460490]
// Decompiled from DWORD __thiscall CFsm::CurrentState(CFsm *this)
int CFsm::CurrentState(void) const
{

  return this->m_iCurrentState;
}

// address=[0x2f05d80]
// Decompiled from CFsm *__thiscall CFsm::CFsm(CFsm *this, struct IEventHandler *a2, int a3, int a4)
CFsm::CFsm(class IEventHandler *a2, int a3, int a4)
{

  this->m_iSize = a3;
  this->m_pEventQueue = std::list<CFsm::SEvent *>();
  this->m_pEventHandler = a2;
  this->m_iCurrentState = a4;
  this->m_pTransitions = 0;
  this->m_pTransitions = new CFsm::Transition[this->m_iSize];
  memset(this->m_pTransitions, -1, 16 * this->m_iSize);
}

// address=[0x2f05e40]
// Decompiled from int __thiscall CFsm::~CFsm(void **this)
CFsm::~CFsm(void)
{

  if (this->m_pTransitions)
    delete[] this->m_pTransitions;
  // TODO: maybe we should this->m_pTransitions = 0....

  this->m_pEventQueue.~list();
}

// address=[0x2f05e80]
// Decompiled from int __thiscall CFsm::DefineTransition(CFsm *this, DWORD a2, DWORD a3, DWORD a4, DWORD a5)
int CFsm::DefineTransition(int a2, int a3, int a4, int a5)
{

  int v7; // [esp+4h] [ebp-4h]

  v7 = this->Hash(a2, a4);
  if (v7 == -1)
    return v7;
  this->m_pTransitions[v7].unk_0 = a2;
  this->m_pTransitions[v7].m_iState = a3;
  this->m_pTransitions[v7].unk_8 = a4;
  this->m_pTransitions[v7].m_iHandlerId = a5;
  return v7;
}

// address=[0x2f05f00]
// Decompiled from int __thiscall CFsm::Control(CFsm *this, int _iEventId, void *_pEvent)
int CFsm::Control(int _iEventId, void *_pEvent)
{

  int handlerResult;          // [esp+4h] [ebp-10h]
  int hash;        // [esp+8h] [ebp-Ch]
  CFsm::SEvent *i; // [esp+Ch] [ebp-8h]

  handlerResult = 0;
  this->InsertInQueue(_iEventId, _pEvent);
  i = this->m_pEventQueue.front();
  while (i)
  {
    hash = this->Hash(i->m_iId);
    if (hash < 0 || this->m_pTransitions[hash].m_iHandlerId == -1)
    {
      handlerResult = this->m_pEventHandler->m_pHandlers[0](
          this->m_pEventHandler,
          (struct CEvn_Logic *)i->m_iId);
    }
    else
    {
      handlerResult = this->m_pEventHandler->m_pHandlers[this->m_pTransitions[hash].m_iHandlerId](
          this->m_pEventHandler,
          (struct CEvn_Logic *)i->m_pPayload);
      this->m_iCurrentState = this->m_pTransitions[hash].m_iState;
    }
    
    this->m_pEventQueue.pop_front();
    delete i;
    if (this->m_pEventQueue.size())
      i = this->m_pEventQueue.front();
    else
      i = 0;
  }
  return handlerResult;
}

// address=[0x2f06060]
// Decompiled from void __thiscall CFsm::GenerateEvent(CFsm *this, int a1, void *a2)
void CFsm::GenerateEvent(int a2, void *a3)
{

  this->InsertInQueue(a2, a3);
}

// address=[0x2f06080]
// Decompiled from void __thiscall CFsm::InsertInQueue(CFsm *this, int a1, void *a2)
void CFsm::InsertInQueue(int a1, void *a2)
{

  CFsm::SEvent *sSEvent; // [esp+Ch] [ebp-4h] MAPDST BYREF

  sSEvent = new CFsm::SEvent();
  if (sSEvent)
  {
    sSEvent->m_iId = 0;
    sSEvent->m_pPayload = 0;
  }
  else
  {
    sSEvent = 0;
  }
  if (sSEvent)
  {
    sSEvent->m_iId = a1;
    sSEvent->m_pPayload = a2;
    this->m_pEventQueue.push_back(sSEvent);
  }
}

// address=[0x2f060f0]
// Decompiled from int __thiscall CFsm::Hash(CFsm *this, int a2, int a3)
int CFsm::Hash(int a2, int a3)
{

  int v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+8h] [ebp-4h]

  v5 = 0;
  v4 = (a2 + (a3 << 8)) % this->m_iSize;
  while (this->m_pTransitions[(v5 + v4) % this->m_iSize].m_iHandlerId != -1 && v5 < this->m_iSize)
    ++v5;
  if (v5 < this->m_iSize)
    return (v5 + v4) % this->m_iSize;
  else
    return -1;
}

// address=[0x2f06170]
// Decompiled from int __thiscall CFsm::Hash(CFsm *this, int a2)
int CFsm::Hash(int a2)
{

  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]

  v4 = 0;
  v3 = (signed int)(this->m_iCurrentState + (a2 << 8)) % this->m_iSize;
  while ((this->m_pTransitions[(v4 + v3) % this->m_iSize].unk_0 != this->m_iCurrentState || this->m_pTransitions[(v4 + v3) % this->m_iSize].unk_8 != a2) && v4 < this->m_iSize)
    ++v4;
  if (v4 < this->m_iSize)
    return (v4 + v3) % this->m_iSize;
  else
    return -1;
}
