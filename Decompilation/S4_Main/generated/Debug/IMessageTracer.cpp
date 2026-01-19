#if FALSE
#include "IMessageTracer.h"

// Definitions for class IMessageTracer

// address=[0x1301740]
// Decompiled from void __thiscall IMessageTracer::PushFormatedInts(IMessageTracer *this, const char *message, DWORD arg1)
void  IMessageTracer::PushFormatedInts(char const * message, int arg1) {
  
  IMessageTracer::STraceMsg *NextTraceMsg; // [esp+4h] [ebp-4h]

  NextTraceMsg = IMessageTracer::GetNextTraceMsg(this);
  if ( NextTraceMsg )
  {
    NextTraceMsg->message = message;
    NextTraceMsg->arg1 = arg1;
  }
}


// address=[0x1301780]
// Decompiled from void __thiscall IMessageTracer::PushFormatedInts(IMessageTracer *this, const char *message, DWORD arg1, int arg2)
void  IMessageTracer::PushFormatedInts(char const * message, int arg1, int arg2) {
  
  IMessageTracer::STraceMsg *NextTraceMsg; // [esp+4h] [ebp-4h]

  NextTraceMsg = IMessageTracer::GetNextTraceMsg(this);
  if ( NextTraceMsg )
  {
    NextTraceMsg->message = message;
    NextTraceMsg->arg1 = arg1;
    NextTraceMsg->arg2 = arg2;
  }
}


// address=[0x13017d0]
// Decompiled from void __thiscall IMessageTracer::PushStaticText(IMessageTracer *this, const char *message)
void  IMessageTracer::PushStaticText(char const * message) {
  
  IMessageTracer::STraceMsg *NextTraceMsg; // [esp+4h] [ebp-4h]

  NextTraceMsg = IMessageTracer::GetNextTraceMsg(this);
  if ( NextTraceMsg )
    NextTraceMsg->message = message;
}


// address=[0x1311dc0]
// Decompiled from void __thiscall IMessageTracer::PushFormatedInts(  IMessageTracer *this,  const char *message,  DWORD arg1,  DWORD arg2,  DWORD arg3)
void  IMessageTracer::PushFormatedInts(char const * message, int arg1, int arg2, int arg3) {
  
  IMessageTracer::STraceMsg *NextTraceMsg; // [esp+4h] [ebp-4h]

  NextTraceMsg = IMessageTracer::GetNextTraceMsg(this);
  if ( NextTraceMsg )
  {
    NextTraceMsg->message = message;
    NextTraceMsg->arg1 = arg1;
    NextTraceMsg->arg2 = arg2;
    NextTraceMsg->arg3 = arg3;
  }
}


// address=[0x1311e20]
// Decompiled from void __thiscall IMessageTracer::PushFormatedInts(  IMessageTracer *this,  const char *message,  int arg1,  int arg2,  int arg3,  DWORD arg4)
void  IMessageTracer::PushFormatedInts(char const * message, int arg1, int arg2, int arg3, int arg4) {
  
  IMessageTracer::STraceMsg *NextTraceMsg; // [esp+4h] [ebp-4h]

  NextTraceMsg = IMessageTracer::GetNextTraceMsg(this);
  if ( NextTraceMsg )
  {
    NextTraceMsg->message = message;
    NextTraceMsg->arg1 = arg1;
    NextTraceMsg->arg2 = arg2;
    NextTraceMsg->arg3 = arg3;
    NextTraceMsg->arg4 = arg4;
  }
}


// address=[0x1311e80]
// Decompiled from void __thiscall IMessageTracer::PushFormatedInts(  IMessageTracer *this,  const char *message,  DWORD arg,  DWORD arg2,  DWORD arg3,  DWORD arg4,  DWORD arg5)
void  IMessageTracer::PushFormatedInts(char const * message, int arg, int arg2, int arg3, int arg4, int arg5) {
  
  IMessageTracer::STraceMsg *NextTraceMsg; // [esp+4h] [ebp-4h]

  NextTraceMsg = IMessageTracer::GetNextTraceMsg(this);
  if ( NextTraceMsg )
  {
    NextTraceMsg->message = message;
    NextTraceMsg->arg1 = arg;
    NextTraceMsg->arg2 = arg2;
    NextTraceMsg->arg3 = arg3;
    NextTraceMsg->arg4 = arg4;
    NextTraceMsg->arg5 = arg5;
  }
}


// address=[0x1496d60]
// Decompiled from void *__thiscall IMessageTracer::Init(IMessageTracer *this)
void  IMessageTracer::Init(void) {
  
  this->m_iCurrentMessage = 0;
  this->m_iMaxMessage = 0xFFFFFFFF;
  return memset(this->m_aMessages, 0, sizeof(this->m_aMessages));
}


// address=[0x1496da0]
// Decompiled from void __thiscall IMessageTracer::Done(IMessageTracer *this)
void  IMessageTracer::Done(void) {
  
  if ( this->m_iCurrentMessage >= 0 )
  {
    this->m_iMaxMessage = this->m_iCurrentMessage;
    this->m_iCurrentMessage = -1;
  }
}


// address=[0x1496dd0]
// Decompiled from void __thiscall IMessageTracer::PrintMessages(IMessageTracer *this, int a2, unsigned int a3)
void  IMessageTracer::PrintMessages(unsigned int a2, unsigned int a3) {
  
  int v3; // [esp+0h] [ebp-430h]
  int v5; // [esp+8h] [ebp-428h]
  int m_iCurrentMessage; // [esp+14h] [ebp-41Ch] MAPDST
  int j; // [esp+18h] [ebp-418h]
  int i; // [esp+20h] [ebp-410h]
  IMessageTracer::STraceMsg *message; // [esp+28h] [ebp-408h]
  char buffer[1024]; // [esp+2Ch] [ebp-404h] BYREF

  if ( this->m_iMaxMessage < 0 )
    m_iCurrentMessage = this->m_iCurrentMessage;
  else
    m_iCurrentMessage = this->m_iMaxMessage;
  if ( m_iCurrentMessage >= 0 && this->m_aMessages[0].message )
  {
    memset(buffer, 0, sizeof(buffer));
    if ( this->m_aMessages[0x3FFF].message )
    {
      m_iCurrentMessage = 0x4000;
      v5 = 0;
    }
    else
    {
      m_iCurrentMessage = 0;
      v5 = 0;
      m_iCurrentMessage = 0;
    }
    for ( i = 0; i < 2; ++i )
    {
      v3 = *(&m_iCurrentMessage + i);
      for ( j = *(&m_iCurrentMessage + i); j < v3; ++j )
      {
        message = &this->m_aMessages[j];
        if ( message->message )
        {
          snprintf(
            buffer,
            0x3FFu,
            message->message,
            message->arg1,
            message->arg2,
            message->arg3,
            message->arg4,
            message->arg5);
          if ( buffer[0] )
            BBSupportTracePrint(a2, buffer);
        }
      }
    }
  }
}


// address=[0x14970f0]
// Decompiled from IMessageTracer *__thiscall IMessageTracer::IMessageTracer(IMessageTracer *this)
 IMessageTracer::IMessageTracer(void) {
  
  this->m_iCurrentMessage = -1;
  this->m_iMaxMessage = -1;
  return this;
}


// address=[0x1558d30]
// Decompiled from char __thiscall IMessageTracer::RemoveCurrentMsgIfEqual(IMessageTracer *this, const char *a2, const char *a3)
bool  IMessageTracer::RemoveCurrentMsgIfEqual(char const * a2, int a3) {
  
  int v4; // [esp+0h] [ebp-8h]

  if ( this->m_iCurrentMessage < 0 )
    return 0;
  v4 = ((unsigned __int16)this->m_iCurrentMessage - 1) & 0x3FFF;
  if ( (const char *)this->m_aMessages[v4].message != a2 || (const char *)this->m_aMessages[v4].arg1 != a3 )
    return 0;
  this->m_iCurrentMessage = v4;
  return 1;
}


// address=[0x1301410]
// Decompiled from IMessageTracer::STraceMsg *__thiscall IMessageTracer::GetNextTraceMsg(IMessageTracer *this)
struct IMessageTracer::STraceMsg *  IMessageTracer::GetNextTraceMsg(void) {
  
  IMessageTracer::STraceMsg *v2; // [esp+0h] [ebp-8h]

  v2 = 0;
  if ( this->m_iCurrentMessage < 0 )
    return v2;
  v2 = &this->m_aMessages[this->m_iCurrentMessage];
  this->m_iCurrentMessage = ((unsigned __int16)this->m_iCurrentMessage + 1) & 0x3FFF;
  return v2;
}


#endif // Already implemented
