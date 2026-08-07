#if FALSE
#include "CMsgStacks.h"

// Definitions for class CMsgStacks

// address=[0x15c4910]
// Decompiled from void __thiscall CMsgStacks::AdvanceValidTick(CMsgStacks *this)
void  CMsgStacks::AdvanceValidTick(void) {
  
  ++this->m_iValidTick;
}


// address=[0x15c4940]
// Decompiled from void __thiscall CMsgStacks::AdvanceVirtualTick(CMsgStacks *this)
void  CMsgStacks::AdvanceVirtualTick(void) {
  
  ++this->m_iVirtualTick;
}


// address=[0x15c4a20]
// Decompiled from int __thiscall CMsgStacks::GetLastMsgTime(CMsgStacks *this, unsigned int a2)
unsigned int  CMsgStacks::GetLastMsgTime(unsigned int a2) {
  
  return this->m_vStacks[1][a2]->m_iChangeTime;
}


// address=[0x15c4aa0]
// Decompiled from int __thiscall CMsgStacks::GetNumberOfStacks(CMsgStacks *this)
int  CMsgStacks::GetNumberOfStacks(void) {
  
  return this->m_iNumberMsgStacks;
}


// address=[0x15c4ca0]
// Decompiled from int __thiscall CMsgStacks::GetValidTick(CMsgStacks *this)
int  CMsgStacks::GetValidTick(void) {
  
  return this->m_iValidTick;
}


// address=[0x15c4cc0]
// Decompiled from int __thiscall CMsgStacks::GetVirtualTick(CMsgStacks *this)
int  CMsgStacks::GetVirtualTick(void) {
  
  return this->m_iVirtualTick;
}


// address=[0x15c4ce0]
// Decompiled from int __thiscall CMsgStacks::Getdt(CMsgStacks *this)
int  CMsgStacks::Getdt(void) {
  
  return this->m_iDeltaTme;
}


// address=[0x15c4d60]
// Decompiled from bool __thiscall CMsgStacks::IsStackAI(CMsgStacks *this, unsigned int a2)
bool  CMsgStacks::IsStackAI(unsigned int a2) {
  
  return CMsgStack::GetAI(this->m_vStacks[0][a2]);
}


// address=[0x15c4e10]
// Decompiled from void __thiscall CMsgStacks::SetLastMsgTime(CMsgStacks *this, int a2, int a3, char a4)
void  CMsgStacks::SetLastMsgTime(unsigned int a2, unsigned int a3, bool a4) {
  
  int m_iNumberMsgStacks; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( a4 )
  {
    m_iNumberMsgStacks = this->m_iNumberMsgStacks;
  }
  else
  {
    m_iNumberMsgStacks = 2;
  }
  for ( i = 1;
        i < m_iNumberMsgStacks;
        ++i )
  {
    this->m_vStacks[i][a2]->m_iChangeTime = a3;
  }
}


// address=[0x15cb660]
// Decompiled from char __thiscall CMsgStacks::TriggerTime(CMsgStacks *this)
bool  CMsgStacks::TriggerTime(void) {
  
  CMsgStack *v2; // [esp+4h] [ebp-10h]
  int i; // [esp+8h] [ebp-Ch]
  int j; // [esp+Ch] [ebp-8h]

  for ( j = 0;
        j < this->m_iNumberPlayers;
        ++j )
  {
    if ( !CMsgStack::IsEmpty(this->m_vStacks[0][j]) && BBSupportDbgReport(2, "Net\\MsgStacks.cpp", 205, "m_pMsgStacks[ 0 ][ j ]->IsEmpty()") == 1 )
    {
      __debugbreak();
    }
    v2 = this->m_vStacks[0][j];
    for ( i = 0;
          i < this->m_iNumberMsgStacks - 1;
          ++i )
    {
      this->m_vStacks[i][j] = this->m_vStacks[i + 1][j];
    }
    this->m_vStacks[this->m_iNumberMsgStacks - 1][j] = v2;
    CMsgStack::Invalidate(this->m_vStacks[this->m_iNumberMsgStacks - 1][j]);
  }
  return 1;
}


// address=[0x15cb780]
// Decompiled from CMsgStacks *__thiscall CMsgStacks::CMsgStacks(CMsgStacks *this, int _iPlayers, int _iDeltaTime, int a4)
 CMsgStacks::CMsgStacks(int _iPlayers, int _iDeltaTime, int a4) {
  
  this->__vftable = (CMsgStacks_vtbl *)&CMsgStacks::_vftable_;
  this->m_iDeltaTme = _iDeltaTime;
  this->m_iNumberMsgStacks = (int)((double)(2 * _iDeltaTime + 1) + pow<int,int>(COMMUNICATION_TICK_VALUE, 2));
  if ( this->m_iNumberMsgStacks == 1 )
  {
    ++this->m_iNumberMsgStacks;
  }
  this->m_iNumberPlayers = _iPlayers;
  if ( this->m_iNumberMsgStacks >= 50 && BBSupportDbgReport(2, "Net\\MsgStacks.cpp", 35, "m_iNumberMsgStacks < MAX_NUMBER_MESSAGE_STACKS") == 1 )
  {
    __debugbreak();
  }
  this->m_bInited = CMsgStacks::InitStacks(this);
  this->m_iVirtualTick = a4 + 1;
  this->m_iValidTick = a4;
  return this;
}


// address=[0x15cb850]
// Decompiled from int __thiscall CMsgStacks::~CMsgStacks(CMsgStacks *this)
 CMsgStacks::~CMsgStacks(void) {
  
  int result; // eax
  CMsgStack *v2; // [esp+8h] [ebp-10h]
  int j; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  this->__vftable = (CMsgStacks_vtbl *)&CMsgStacks::_vftable_;
  for ( i = 0;
        ;
        ++i )
  {
    result = i;
    if ( i >= this->m_iNumberMsgStacks )
    {
      break;
    }
    for ( j = 0;
          j < this->m_iNumberPlayers;
          ++j )
    {
      if ( this->m_vStacks[i][j] )
      {
        v2 = this->m_vStacks[i][j];
        (*(void (__thiscall **)(CMsgStack *, int))v2->__vftable)(v2, 1);
        this->m_vStacks[i][j] = 0;
      }
    }
  }
  return result;
}


// address=[0x15cb920]
// Decompiled from char __thiscall CMsgStacks::PushMsg(CMsgStacks *this, struct CNet_Event *a2)
bool  CMsgStacks::PushMsg(class CNet_Event & a2) {
  
  DWORD m_iTick; // [esp+4h] [ebp-10h]
  int PlayerNr; // [esp+8h] [ebp-Ch]
  int v5; // [esp+Ch] [ebp-8h]

  PlayerNr = a2->m_iOwner - 1;
  if ( PlayerNr >= this->m_iNumberPlayers && BBSupportDbgReport(2, "Net\\MsgStacks.cpp", 113, "PlayerNr < m_NumberPlayers") == 1 )
  {
    __debugbreak();
  }
  m_iTick = a2->m_iTick;
  v5 = m_iTick - CMsgStacks::GetValidTick(this);
  if ( v5 >= 0 )
  {
    if ( v5 >= this->m_iNumberMsgStacks && BBSupportDbgReportF(2, "Net\\MsgStacks.cpp", 127, "MsgStacks.cpp: Future netmsg got !") == 1 )
    {
      __debugbreak();
    }
    CMsgStack::AddMsg(this->m_vStacks[v5][PlayerNr], a2);
    return 1;
  }
  else
  {
    CTrace::Print("MsgStacks.cpp: Old msg discarded: index#%d, Tick %d, Msg# %d!", a2->m_iOwner - 1, a2->m_iTick, a2->m_iMsgNr);
    return 1;
  }
}


// address=[0x15cba00]
// Decompiled from CNet_Event *__thiscall CMsgStacks::PopMsg(CMsgStacks *this, CNet_Event *a2)
class CNet_Event  CMsgStacks::PopMsg(void a2) {
  
  int i; // [esp+8h] [ebp-28h]
  CNet_Event v5; // [esp+Ch] [ebp-24h] BYREF

  for ( i = 0;
        i < this->m_iNumberPlayers;
        ++i )
  {
    if ( !CMsgStack::IsEmpty(this->m_vStacks[0][i]) )
    {
      CMsgStack::GetMsg(this->m_vStacks[0][i], &v5);
      v5.m_iOwner = i + 1;
      CNet_Event::CNet_Event((struct boost::exception_detail::clone_base *)&v5);
      CNet_Event::~CNet_Event(&v5);
      return a2;
    }
  }
  CNet_Event::CNet_Event(a2, 0, 0, 0, 0, 0, 0, 0);
  return a2;
}


// address=[0x15cbae0]
// Decompiled from char __thiscall CMsgStacks::AddNewPlayer(CMsgStacks *this)
bool  CMsgStacks::AddNewPlayer(void) {
  
  CMsgStack *v2; // [esp+8h] [ebp-1Ch]
  CMsgStack *C; // [esp+Ch] [ebp-18h]
  int i; // [esp+10h] [ebp-14h]

  for ( i = 0;
        i < this->m_iDeltaTme;
        ++i )
  {
    C = (CMsgStack *)operator new(0x1Cu);
    if ( C )
    {
      v2 = CMsgStack::CMsgStack(C);
    }
    else
    {
      v2 = 0;
    }
    this->m_vStacks[i][this->m_iNumberPlayers] = v2;
  }
  ++this->m_iNumberPlayers;
  return 1;
}


// address=[0x15cbba0]
// Decompiled from int __thiscall CMsgStacks::GetNumPlayers(CMsgStacks *this)
int  CMsgStacks::GetNumPlayers(void) {
  
  return this->m_iNumberPlayers;
}


// address=[0x15cbbc0]
// Decompiled from char __thiscall CMsgStacks::SetNumberOfClients(CMsgStacks *this, unsigned int a2)
bool  CMsgStacks::SetNumberOfClients(unsigned int a2) {
  
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = this->m_iNumberPlayers;
        i < a2;
        ++i )
  {
    CMsgStacks::AddNewPlayer(this);
  }
  return 1;
}


// address=[0x15cbc00]
// Decompiled from CMsgStack *__thiscall CMsgStacks::Get(CMsgStacks *this, unsigned int a2, unsigned __int8 a3)
class CMsgStack *  CMsgStacks::Get(unsigned int a2, unsigned char a3) {
  
  return this->m_vStacks[a2][a3];
}


// address=[0x15cbc30]
// Decompiled from char __thiscall CMsgStacks::IsEmpty(CMsgStacks *this, unsigned int a2)
bool  CMsgStacks::IsEmpty(unsigned int a2) {
  
  CMsgStack *v2; // eax
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0;
        i < this->m_iNumberPlayers;
        ++i )
  {
    v2 = CMsgStacks::Get(this, a2, i);
    if ( !(unsigned __int8)std::list<CNet_Event>::empty(&v2->this_list, v2) )
    {
      return 0;
    }
  }
  return 1;
}


// address=[0x15cbc90]
// Decompiled from CNet_Event *__thiscall CMsgStacks::GetMsgToSend(CMsgStacks *this, CNet_Event *a2)
class CNet_Event  CMsgStacks::GetMsgToSend(void a2) {
  
  CMsgStack *v2; // eax
  int v4; // [esp+0h] [ebp-34h]
  int i; // [esp+Ch] [ebp-28h]
  CNet_Event v7; // [esp+10h] [ebp-24h] BYREF

  for ( i = 0;
        i < this->m_iNumberPlayers;
        ++i )
  {
    v2 = CMsgStacks::Get(this, 0, i);
    if ( !(unsigned __int8)std::list<CNet_Event>::empty(&v2->this_list, v2) )
    {
      CMsgStack::GetMsg(v4, &v7);
      CNet_Event::CNet_Event((struct boost::exception_detail::clone_base *)&v7);
      CNet_Event::~CNet_Event(&v7);
      return a2;
    }
  }
  CNet_Event::CNet_Event(a2, 0, 0, 0, 0, 0, 0, 0);
  return a2;
}


// address=[0x15cbd50]
// Decompiled from void __thiscall CMsgStacks::SetNumberOfExpectedMsgs(CMsgStacks *this, int _iTick, unsigned __int8 _iPlayerID, unsigned __int8 _iCount)
void  CMsgStacks::SetNumberOfExpectedMsgs(unsigned int _iTick, unsigned char _iPlayerID, unsigned char _iCount) {
  
  int v4; // [esp+8h] [ebp-8h]

  if ( CMsgStacks::IsSizeAlreadySet(this, _iTick, _iPlayerID) && BBSupportDbgReport(2, "Net\\MsgStacks.cpp", 254, "!IsSizeAlreadySet( _iTick, _iPlayerID )") == 1 )
  {
    __debugbreak();
  }
  v4 = _iTick - CMsgStacks::GetValidTick(this);
  if ( v4 >= this->m_iNumberMsgStacks && BBSupportDbgReportF(2, "Net\\MsgStacks.cpp", 259, "MsgStacks:Future Netmsg got: Tick %d, Player %d size %d!", _iTick, _iPlayerID, _iCount) == 1 )
  {
    __debugbreak();
  }
  if ( v4 >= 1 )
  {
    CMsgStack::SetExpectedSize(this->m_vStacks[v4][_iPlayerID], _iCount);
  }
}


// address=[0x15cbe20]
// Decompiled from bool __thiscall CMsgStacks::IsSizeAlreadySet(CMsgStacks *this, int a2, unsigned __int8 a3)
bool  CMsgStacks::IsSizeAlreadySet(unsigned int a2, unsigned char a3) {
  
  int ValidTick; // [esp+0h] [ebp-14h]

  ValidTick = CMsgStacks::GetValidTick(this);
  return a2 - ValidTick < 1 || CMsgStack::GetExpectedSize(this->m_vStacks[a2 - ValidTick][a3], ValidTick) != -1;
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
  for ( i = 0;
        i < this->m_iNumberPlayers;
        ++i )
  {
    if ( !CMsgStack::GetAI(this->m_vStacks[0][i]) && !CMsgStack::IsValid(this->m_vStacks[v5][i]) )
    {
      v8 = 0;
      *a3 |= 1 << i;
      if ( 71 * this->m_iDeltaTme + CMsgStacks::GetLastMsgTime(this, i) < Time )
      {
        *a3 |= 1 << i;
      }
    }
  }
  return v8;
}


// address=[0x15cbf80]
// Decompiled from void __thiscall CMsgStacks::SetStackAI(CMsgStacks *this, unsigned int a2, bool a3)
void  CMsgStacks::SetStackAI(unsigned int a2, bool a3) {
  
  int i; // [esp+4h] [ebp-4h]

  if ( a2 >= this->m_iNumberPlayers && BBSupportDbgReport(2, "Net\\MsgStacks.cpp", 349, "_iId < m_NumberPlayers") == 1 )
  {
    __debugbreak();
  }
  for ( i = 0;
        i < this->m_iNumberMsgStacks;
        ++i )
  {
    CMsgStack::SetAI(this->m_vStacks[i][a2], a3);
  }
}


// address=[0x15cc000]
// Decompiled from char __thiscall CMsgStacks::IsInStack(CMsgStacks *this, struct CNet_Event *a2)
bool  CMsgStacks::IsInStack(class CNet_Event & a2) {
  
  DWORD m_iTick; // [esp+4h] [ebp-10h]
  int iPlayer; // [esp+8h] [ebp-Ch]
  int v5; // [esp+Ch] [ebp-8h]

  iPlayer = a2->m_iOwner - 1;
  if ( iPlayer >= this->m_iNumberPlayers && BBSupportDbgReport(2, "Net\\MsgStacks.cpp", 148, "iPlayer < m_NumberPlayers") == 1 )
  {
    __debugbreak();
  }
  m_iTick = a2->m_iTick;
  v5 = m_iTick - CMsgStacks::GetValidTick(this);
  if ( v5 >= 0 && v5 <= this->m_iNumberMsgStacks )
  {
    return CMsgStack::IsInStack(this->m_vStacks[v5][iPlayer], a2->m_iMsgNr);
  }
  else
  {
    return 0;
  }
}


// address=[0x15cc0a0]
// Decompiled from void __thiscall CMsgStacks::ClearAndValidate(CMsgStacks *this, int a2)
void  CMsgStacks::ClearAndValidate(int a2) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0;
        i < this->m_iNumberMsgStacks;
        ++i )
  {
    CMsgStack::ClearAndValidate(this->m_vStacks[i][a2]);
  }
}


// address=[0x15cc0f0]
// Decompiled from void __thiscall CMsgStacks::OnEndSaving(CMsgStacks *this, int a2, int a3)
void  CMsgStacks::OnEndSaving(int a2, int a3) {
  
  DWORD Time; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0;
        i < a2;
        ++i )
  {
    Time = timeGetTime();
    CMsgStacks::SetLastMsgTime(i, a3 + Time, 1);
  }
}


// address=[0x15cc140]
// Decompiled from bool __thiscall CMsgStacks::InitStacks(CMsgStacks *this)
bool  CMsgStacks::InitStacks(void) {
  
  CMsgStack *v2; // [esp+10h] [ebp-20h]
  CMsgStack *C; // [esp+14h] [ebp-1Ch]
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]

  for ( i = 0;
        i < this->m_iNumberMsgStacks;
        ++i )
  {
    for ( j = 0;
          j < this->m_iNumberPlayers;
          ++j )
    {
      C = (CMsgStack *)operator new(0x1Cu);
      if ( C )
      {
        v2 = CMsgStack::CMsgStack(C);
      }
      else
      {
        v2 = 0;
      }
      this->m_vStacks[i][j] = v2;
    }
  }                                             // m_vStacks != 0
  return this != (CMsgStacks *)0xFFFFFFEC;
}


#endif // Already implemented
