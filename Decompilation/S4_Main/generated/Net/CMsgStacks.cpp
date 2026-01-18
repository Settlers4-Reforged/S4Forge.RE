#include "CMsgStacks.h"

// Definitions for class CMsgStacks

// address=[0x15c4910]
// Decompiled from CMsgStacks *__thiscall CMsgStacks::AdvanceValidTick(CMsgStacks *this)
void  CMsgStacks::AdvanceValidTick(void) {
  
  CMsgStacks *result; // eax

  result = this;
  ++*((_DWORD *)this + 406);
  return result;
}


// address=[0x15c4940]
// Decompiled from CMsgStacks *__thiscall CMsgStacks::AdvanceVirtualTick(CMsgStacks *this)
void  CMsgStacks::AdvanceVirtualTick(void) {
  
  CMsgStacks *result; // eax

  result = this;
  ++*((_DWORD *)this + 405);
  return result;
}


// address=[0x15c4a20]
// Decompiled from int __thiscall CMsgStacks::GetLastMsgTime(CMsgStacks *this, unsigned int a2)
unsigned int  CMsgStacks::GetLastMsgTime(unsigned int a2) {
  
  return *(_DWORD *)(*((_DWORD *)this + a2 + 13) + 24);
}


// address=[0x15c4aa0]
// Decompiled from int __thiscall CMsgStacks::GetNumberOfStacks(pairNode *this)
int  CMsgStacks::GetNumberOfStacks(void) {
  
  return *((_DWORD *)this + 3);
}


// address=[0x15c4ca0]
// Decompiled from int __thiscall sub_19C4CA0(_DWORD *this)
int  CMsgStacks::GetValidTick(void) {
  
  return this[406];
}


// address=[0x15c4cc0]
// Decompiled from int __thiscall CMsgStacks::GetVirtualTick(CMsgStacks *this)
int  CMsgStacks::GetVirtualTick(void) {
  
  return *((_DWORD *)this + 405);
}


// address=[0x15c4ce0]
// Decompiled from int __thiscall CMsgStacks::Getdt(CMsgStacks *this)
int  CMsgStacks::Getdt(void) {
  
  return *((_DWORD *)this + 2);
}


// address=[0x15c4d60]
// Decompiled from bool __thiscall CMsgStacks::IsStackAI(CMsgStack **this, unsigned int a2)
bool  CMsgStacks::IsStackAI(unsigned int a2) {
  
  return CMsgStack::GetAI(this[a2 + 5]);
}


// address=[0x15c4e10]
// Decompiled from int __thiscall CMsgStacks::SetLastMsgTime(_DWORD *this, int a2, int a3, char a4)
void  CMsgStacks::SetLastMsgTime(unsigned int a2, unsigned int a3, bool a4) {
  
  int result; // eax
  int v5; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( a4 )
    v5 = this[3];
  else
    v5 = 2;
  result = v5;
  for ( i = 1; i < v5; ++i )
  {
    result = a2;
    *(_DWORD *)(this[8 * i + 5 + a2] + 24) = a3;
  }
  return result;
}


// address=[0x15cb660]
// Decompiled from char __thiscall CMsgStacks::TriggerTime(CMsgStack **this)
bool  CMsgStacks::TriggerTime(void) {
  
  CMsgStack *v2; // [esp+4h] [ebp-10h]
  int j; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]

  for ( i = 0; i < (int)this[4]; ++i )
  {
    if ( !CMsgStack::IsEmpty(this[i + 5])
      && BBSupportDbgReport(2, "Net\\MsgStacks.cpp", 205, "m_pMsgStacks[ 0 ][ j ]->IsEmpty()") == 1 )
    {
      __debugbreak();
    }
    v2 = this[i + 5];
    for ( j = 0; j < (int)this[3] - 1; ++j )
      *(&this[8 * j + 5] + i) = *(&this[8 * j + 13] + i);
    *(&this[8 * ((_DWORD)this[3] - 1) + 5] + i) = v2;
    CMsgStack::Invalidate(*(&this[8 * ((_DWORD)this[3] - 1) + 5] + i));
  }
  return 1;
}


// address=[0x15cb780]
// Decompiled from CMsgStacks *__thiscall CMsgStacks::CMsgStacks(CMsgStacks *this, int a2, int a3, int a4)
 CMsgStacks::CMsgStacks(int a2, int a3, int a4) {
  
  double v5; // [esp+0h] [ebp-14h]

  *(_DWORD *)this = &CMsgStacks::_vftable_;
  *((_DWORD *)this + 2) = a3;
  v5 = pow<int,int>(COMMUNICATION_TICK_VALUE, 2);
  *((_DWORD *)this + 3) = (int)((double)(2 * a3 + 1) + v5);
  if ( *((_DWORD *)this + 3) == 1 )
    ++*((_DWORD *)this + 3);
  *((_DWORD *)this + 4) = a2;
  if ( *((int *)this + 3) >= 50
    && BBSupportDbgReport(2, "Net\\MsgStacks.cpp", 35, "m_iNumberMsgStacks < MAX_NUMBER_MESSAGE_STACKS") == 1 )
  {
    __debugbreak();
  }
  *((_BYTE *)this + 4) = CMsgStacks::InitStacks(SLODWORD(v5), SHIDWORD(v5));
  *((_DWORD *)this + 405) = a4 + 1;
  *((_DWORD *)this + 406) = a4;
  return this;
}


// address=[0x15cb850]
// Decompiled from int __thiscall CMsgStacks::~CMsgStacks(CMsgStacks *this)
 CMsgStacks::~CMsgStacks(void) {
  
  int result; // eax
  void (__thiscall ***v2)(_DWORD, int); // [esp+8h] [ebp-10h]
  int j; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  *(_DWORD *)this = &CMsgStacks::_vftable_;
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= *((_DWORD *)this + 3) )
      break;
    for ( j = 0; j < *((_DWORD *)this + 4); ++j )
    {
      if ( *((_DWORD *)this + 8 * i + j + 5) )
      {
        v2 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this + 8 * i + j + 5);
        (**v2)(v2, 1);
        *((_DWORD *)this + 8 * i + j + 5) = 0;
      }
    }
  }
  return result;
}


// address=[0x15cb920]
// Decompiled from char __thiscall CMsgStacks::PushMsg(CMsgStacks *this, struct CNet_Event *a2)
bool  CMsgStacks::PushMsg(class CNet_Event & a2) {
  
  int v3; // [esp+4h] [ebp-10h]
  int v4; // [esp+8h] [ebp-Ch]
  int v5; // [esp+Ch] [ebp-8h]

  v4 = *((unsigned __int8 *)a2 + 30) - 1;
  if ( v4 >= *((_DWORD *)this + 4)
    && BBSupportDbgReport(2, "Net\\MsgStacks.cpp", 113, "PlayerNr < m_NumberPlayers") == 1 )
  {
    __debugbreak();
  }
  v3 = *((_DWORD *)a2 + 4);
  v5 = v3 - CMsgStacks::GetValidTick(this);
  if ( v5 >= 0 )
  {
    if ( v5 >= *((_DWORD *)this + 3)
      && BBSupportDbgReportF(2, "Net\\MsgStacks.cpp", 127, "MsgStacks.cpp: Future netmsg got !") == 1 )
    {
      __debugbreak();
    }
    CMsgStack::AddMsg(*((CMsgStack **)this + 8 * v5 + v4 + 5), a2);
    return 1;
  }
  else
  {
    CTrace::Print(
      "MsgStacks.cpp: Old msg discarded: index#%d, Tick %d, Msg# %d!",
      *((unsigned __int8 *)a2 + 30) - 1,
      *((_DWORD *)a2 + 4),
      *((unsigned __int8 *)a2 + 20));
    return 1;
  }
}


// address=[0x15cba00]
// Decompiled from CNet_Event *__thiscall CMsgStacks::PopMsg(_DWORD *this, CNet_Event *a2)
class CNet_Event  CMsgStacks::PopMsg(void a2) {
  
  int i; // [esp+8h] [ebp-28h]
  _BYTE v5[32]; // [esp+Ch] [ebp-24h] BYREF

  for ( i = 0; i < this[4]; ++i )
  {
    if ( !CMsgStack::IsEmpty((CMsgStack *)this[i + 5]) )
    {
      CMsgStack::GetMsg(this[i + 5], v5);
      v5[30] = i + 1;
      CNet_Event::CNet_Event((struct boost::exception_detail::clone_base *)v5);
      CNet_Event::~CNet_Event((CNet_Event *)v5);
      return a2;
    }
  }
  CNet_Event::CNet_Event(a2, 0, 0, 0, 0, 0, 0, 0);
  return a2;
}


// address=[0x15cbae0]
// Decompiled from char __thiscall CMsgStacks::AddNewPlayer(CMsgStacks *this)
bool  CMsgStacks::AddNewPlayer(void) {
  
  int v2; // [esp+8h] [ebp-1Ch]
  void *C; // [esp+Ch] [ebp-18h]
  int i; // [esp+10h] [ebp-14h]

  for ( i = 0; i < *((_DWORD *)this + 2); ++i )
  {
    C = operator new(0x1Cu);
    if ( C )
      v2 = CMsgStack::CMsgStack(C);
    else
      v2 = 0;
    *((_DWORD *)this + 8 * i + *((_DWORD *)this + 4) + 5) = v2;
  }
  ++*((_DWORD *)this + 4);
  return 1;
}


// address=[0x15cbba0]
// Decompiled from int __thiscall CMsgStacks::GetNumPlayers(CMsgStacks *this)
int  CMsgStacks::GetNumPlayers(void) {
  
  return *((_DWORD *)this + 4);
}


// address=[0x15cbbc0]
// Decompiled from char __thiscall CMsgStacks::SetNumberOfClients(CMsgStacks *this, unsigned int a2)
bool  CMsgStacks::SetNumberOfClients(unsigned int a2) {
  
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = *((_DWORD *)this + 4); i < a2; ++i )
    CMsgStacks::AddNewPlayer(this);
  return 1;
}


// address=[0x15cbc00]
// Decompiled from int __thiscall CMsgStacks::Get(CMsgStacks *this, unsigned int a2, unsigned __int8 a3)
class CMsgStack *  CMsgStacks::Get(unsigned int a2, unsigned char a3) {
  
  return *((_DWORD *)this + 8 * a2 + a3 + 5);
}


// address=[0x15cbc30]
// Decompiled from char __thiscall CMsgStacks::IsEmpty(CMsgStacks *this, unsigned int a2)
bool  CMsgStacks::IsEmpty(unsigned int a2) {
  
  int v2; // eax
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < *((_DWORD *)this + 4); ++i )
  {
    v2 = CMsgStacks::Get(this, a2, i);
    if ( !(unsigned __int8)std::list<CNet_Event>::empty(v2 + 4, v2) )
      return 0;
  }
  return 1;
}


// address=[0x15cbc90]
// Decompiled from CNet_Event *__thiscall CMsgStacks::GetMsgToSend(CMsgStacks *this, CNet_Event *a2)
class CNet_Event  CMsgStacks::GetMsgToSend(void a2) {
  
  int v2; // eax
  int v4; // [esp+0h] [ebp-34h]
  int i; // [esp+Ch] [ebp-28h]
  _BYTE v7[32]; // [esp+10h] [ebp-24h] BYREF

  for ( i = 0; i < *((_DWORD *)this + 4); ++i )
  {
    v2 = CMsgStacks::Get(this, 0, i);
    if ( !(unsigned __int8)std::list<CNet_Event>::empty(v2 + 4, v2) )
    {
      CMsgStack::GetMsg(v4, v7);
      CNet_Event::CNet_Event((struct boost::exception_detail::clone_base *)v7);
      CNet_Event::~CNet_Event((CNet_Event *)v7);
      return a2;
    }
  }
  CNet_Event::CNet_Event(a2, 0, 0, 0, 0, 0, 0, 0);
  return a2;
}


// address=[0x15cbd50]
// Decompiled from _DWORD *__thiscall CMsgStacks::SetNumberOfExpectedMsgs(_DWORD *this, int a2, char a3, unsigned __int8 a4)
void  CMsgStacks::SetNumberOfExpectedMsgs(unsigned int a2, unsigned char a3, unsigned char a4) {
  
  _DWORD *result; // eax
  int v5; // [esp+8h] [ebp-8h]

  if ( (unsigned __int8)CMsgStacks::IsSizeAlreadySet(a2, a3)
    && BBSupportDbgReport(2, (int)"Net\\MsgStacks.cpp", 254, (int)"!IsSizeAlreadySet( _iTick, _iPlayerID )") == 1 )
  {
    __debugbreak();
  }
  v5 = a2 - CMsgStacks::GetValidTick(this);
  result = this;
  if ( v5 >= this[3] )
  {
    result = (_DWORD *)BBSupportDbgReportF(
                         2,
                         "Net\\MsgStacks.cpp",
                         259,
                         "MsgStacks:Future Netmsg got: Tick %d, Player %d size %d!",
                         a2,
                         (unsigned __int8)a3,
                         a4);
    if ( result == (_DWORD *)1 )
      __debugbreak();
  }
  if ( v5 >= 1 )
    return (_DWORD *)CMsgStack::SetExpectedSize(a4);
  return result;
}


// address=[0x15cbe20]
// Decompiled from bool __thiscall CMsgStacks::IsSizeAlreadySet(_DWORD *this, int a2, unsigned __int8 a3)
bool  CMsgStacks::IsSizeAlreadySet(unsigned int a2, unsigned char a3) {
  
  int ValidTick; // [esp+0h] [ebp-14h]

  ValidTick = CMsgStacks::GetValidTick(this);
  return a2 - ValidTick < 1 || CMsgStack::GetExpectedSize(this[8 * (a2 - ValidTick) + 5 + a3], ValidTick) != -1;
}


// address=[0x15cbe90]
// Decompiled from char __thiscall CMsgStacks::IsMsgStackValid(CMsgStacks *this, unsigned int a2, unsigned int *a3)
bool  CMsgStacks::IsMsgStackValid(unsigned int a2, unsigned int & a3) {
  
  DWORD Time; // [esp+0h] [ebp-1Ch]
  int v5; // [esp+4h] [ebp-18h]
  signed int i; // [esp+14h] [ebp-8h]
  char v8; // [esp+1Bh] [ebp-1h]

  v5 = a2 - CMsgStacks::GetValidTick(this);
  Time = timeGetTime();
  v8 = 1;
  for ( i = 0; i < *((_DWORD *)this + 4); ++i )
  {
    if ( !CMsgStack::GetAI(*((CMsgStack **)this + i + 5)) && !CMsgStack::IsValid(*((CMsgStack **)this + 8 * v5 + i + 5)) )
    {
      v8 = 0;
      *a3 |= 1 << i;
      if ( 71 * *((_DWORD *)this + 2) + CMsgStacks::GetLastMsgTime(this, i) < Time )
        *a3 |= 1 << i;
    }
  }
  return v8;
}


// address=[0x15cbf80]
// Decompiled from int __thiscall sub_19CBF80(_DWORD *this, unsigned int a2, char a3)
void  CMsgStacks::SetStackAI(unsigned int a2, bool a3) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  result = (int)this;
  if ( a2 >= this[4] )
  {
    result = BBSupportDbgReport(2, (int)"Net\\MsgStacks.cpp", 349, (int)"_iId < m_NumberPlayers");
    if ( result == 1 )
      __debugbreak();
  }
  for ( i = 0; i < this[3]; ++i )
  {
    CMsgStack::SetAI(a3);
    result = i + 1;
  }
  return result;
}


// address=[0x15cc000]
// Decompiled from bool __thiscall CMsgStacks::IsInStack(CMsgStacks *this, struct CNet_Event *a2)
bool  CMsgStacks::IsInStack(class CNet_Event & a2) {
  
  int v3; // [esp+4h] [ebp-10h]
  int v4; // [esp+8h] [ebp-Ch]
  int v5; // [esp+Ch] [ebp-8h]

  v4 = *((unsigned __int8 *)a2 + 30) - 1;
  if ( v4 >= *((_DWORD *)this + 4) && BBSupportDbgReport(2, "Net\\MsgStacks.cpp", 148, "iPlayer < m_NumberPlayers") == 1 )
    __debugbreak();
  v3 = *((_DWORD *)a2 + 4);
  v5 = v3 - CMsgStacks::GetValidTick(this);
  return v5 >= 0
      && v5 <= *((_DWORD *)this + 3)
      && CMsgStack::IsInStack(*((CMsgStack **)this + 8 * v5 + v4 + 5), *((_BYTE *)a2 + 20));
}


// address=[0x15cc0a0]
// Decompiled from int __thiscall CMsgStacks::ClearAndValidate(CMsgStack **this, int a2)
void  CMsgStacks::ClearAndValidate(int a2) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < (int)this[3]; ++i )
  {
    CMsgStack::ClearAndValidate(*(&this[8 * i + 5] + a2));
    result = i + 1;
  }
  return result;
}


// address=[0x15cc0f0]
// Decompiled from void __thiscall CMsgStacks::OnEndSaving(CMsgStacks *this, int a2, int a3)
void  CMsgStacks::OnEndSaving(int a2, int a3) {
  
  DWORD Time; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < a2; ++i )
  {
    Time = timeGetTime();
    CMsgStacks::SetLastMsgTime(i, a3 + Time, 1);
  }
}


// address=[0x15cc140]
// Decompiled from bool __thiscall CMsgStacks::InitStacks(_DWORD *this)
bool  CMsgStacks::InitStacks(void) {
  
  int v2; // [esp+10h] [ebp-20h]
  void *C; // [esp+14h] [ebp-1Ch]
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]

  for ( i = 0; i < this[3]; ++i )
  {
    for ( j = 0; j < this[4]; ++j )
    {
      C = operator new(0x1Cu);
      if ( C )
        v2 = CMsgStack::CMsgStack(C);
      else
        v2 = 0;
      this[8 * i + 5 + j] = v2;
    }
  }
  return this != (_DWORD *)-20;
}


