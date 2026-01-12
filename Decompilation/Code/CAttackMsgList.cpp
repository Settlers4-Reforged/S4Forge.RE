#include "CAttackMsgList.h"

// Definitions for class CAttackMsgList

// address=[0x140a800]
// Decompiled from char __thiscall CAttackMsgList::SendAttackMessage(CAttackMsgList *this, int a2, int a3)

void  CAttackMsgList::SendAttackMessage(int,int) {
  
  char result; // al
  int LocalPlayerId; // eax
  int TickCounter; // [esp+4h] [ebp-14h]
  CAttackMsgFilter *v7; // [esp+8h] [ebp-10h]
  int v8; // [esp+Ch] [ebp-Ch]
  int v9; // [esp+10h] [ebp-8h]
  char v10; // [esp+17h] [ebp-1h]

  v9 = 0;
  v8 = 15;
  v10 = 0;
  TickCounter = CStateGame::GetTickCounter(g_pGame);
  while ( 1 )
  {
    result = 0;
    if ( v9 >= 15 )
      break;
    v7 = (CAttackMsgList *)((char *)this + 16 * v9);
    if ( CAttackMsgFilter::IsActive(v7) )
    {
      if ( CAttackMsgFilter::IsOld(v7, TickCounter) )
      {
        CAttackMsgFilter::Deactivate(v7);
        if ( v8 == 15 )
          v8 = v9;
      }
      else
      {
        result = CAttackMsgFilter::IsInRadius((Grid **)v7, a2, a3);
        if ( result )
        {
          v10 = 1;
          break;
        }
      }
    }
    else if ( v8 == 15 )
    {
      v8 = v9;
    }
    ++v9;
  }
  if ( v10 )
    return result;
  if ( v8 == 15 )
  {
    return BBSupportTracePrintF(3, "AttackMsgList : Out of filters!!");
  }
  else
  {
    if ( !CAttackMsgFilter::Activate((CAttackMsgList *)((char *)this + 16 * v8), TickCounter, a2, a3) )
      BBSupportTracePrintF(3, "AttackMsgList : Tried to activate active filter!!");
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    return CTextMsgHandler::AddWarningMsg(2450, LocalPlayerId, a2, a3);
  }
  return result;
}


// address=[0x140a9c0]
// Decompiled from CAttackMsgList *__thiscall CAttackMsgList::CAttackMsgList(CAttackMsgList *this)

 CAttackMsgList::CAttackMsgList(void) {
  
  `eh vector constructor iterator'(
    this,
    0x10u,
    0xFu,
    CAttackMsgFilter::CAttackMsgFilter,
    CAttackMsgFilter::~CAttackMsgFilter);
  return this;
}


// address=[0x140aa00]
// Decompiled from void __thiscall CAttackMsgList::~CAttackMsgList(CAttackMsgList *this)

 CAttackMsgList::~CAttackMsgList(void) {
  
  `eh vector destructor iterator'(this, 0x10u, 0xFu, CAttackMsgFilter::~CAttackMsgFilter);
}


