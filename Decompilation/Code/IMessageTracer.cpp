#include "IMessageTracer.h"

// Definitions for class IMessageTracer

// address=[0x1301740]
// Decompiled from char *__thiscall IMessageTracer::PushFormatedInts(IMessageTracer *this, const char *a2, char *a3)

void  IMessageTracer::PushFormatedInts(char const *,int) {
  
  char *result; // eax
  char *v4; // [esp+4h] [ebp-4h]

  result = IMessageTracer::GetNextTraceMsg(this);
  v4 = result;
  if ( !result )
    return result;
  *(_DWORD *)result = a2;
  result = a3;
  *((_DWORD *)v4 + 1) = a3;
  return result;
}


// address=[0x1301780]
// Decompiled from char *__thiscall IMessageTracer::PushFormatedInts(IMessageTracer *this, const char *a2, char *a3, int a4)

void  IMessageTracer::PushFormatedInts(char const *,int,int) {
  
  char *result; // eax
  char *v5; // [esp+4h] [ebp-4h]

  result = IMessageTracer::GetNextTraceMsg(this);
  v5 = result;
  if ( !result )
    return result;
  *(_DWORD *)result = a2;
  result = a3;
  *((_DWORD *)v5 + 1) = a3;
  *((_DWORD *)v5 + 2) = a4;
  return result;
}


// address=[0x13017d0]
// Decompiled from char *__thiscall IMessageTracer::PushStaticText(IMessageTracer *this, const char *a2)

void  IMessageTracer::PushStaticText(char const *) {
  
  char *result; // eax

  result = IMessageTracer::GetNextTraceMsg(this);
  if ( result )
    *(_DWORD *)result = a2;
  return result;
}


// address=[0x1311dc0]
// Decompiled from char *__thiscall IMessageTracer::PushFormatedInts(IMessageTracer *this, const char *a2, int a3, int a4, int a5)

void  IMessageTracer::PushFormatedInts(char const *,int,int,int) {
  
  char *result; // eax

  result = IMessageTracer::GetNextTraceMsg(this);
  if ( !result )
    return result;
  *(_DWORD *)result = a2;
  *((_DWORD *)result + 1) = a3;
  *((_DWORD *)result + 2) = a4;
  *((_DWORD *)result + 3) = a5;
  return result;
}


// address=[0x1311e20]
// Decompiled from char *__thiscall IMessageTracer::PushFormatedInts(
        IMessageTracer *this,
        const char *a2,
        int a3,
        int a4,
        int a5,
        char *a6)

void  IMessageTracer::PushFormatedInts(char const *,int,int,int,int) {
  
  char *result; // eax
  char *v7; // [esp+4h] [ebp-4h]

  result = IMessageTracer::GetNextTraceMsg(this);
  v7 = result;
  if ( !result )
    return result;
  *(_DWORD *)result = a2;
  *((_DWORD *)result + 1) = a3;
  *((_DWORD *)result + 2) = a4;
  *((_DWORD *)result + 3) = a5;
  result = a6;
  *((_DWORD *)v7 + 4) = a6;
  return result;
}


// address=[0x1311e80]
// Decompiled from struct IMessageTracer::STraceMsg *__thiscall IMessageTracer::PushFormatedInts(
        IMessageTracer *this,
        const char *a2,
        int a3,
        int a4,
        int a5,
        struct IMessageTracer::STraceMsg *a6,
        int a7)

void  IMessageTracer::PushFormatedInts(char const *,int,int,int,int,int) {
  
  struct IMessageTracer::STraceMsg *result; // eax
  struct IMessageTracer::STraceMsg *v8; // [esp+4h] [ebp-4h]

  result = IMessageTracer::GetNextTraceMsg(this);
  v8 = result;
  if ( !result )
    return result;
  *(_DWORD *)result = a2;
  *((_DWORD *)result + 1) = a3;
  *((_DWORD *)result + 2) = a4;
  *((_DWORD *)result + 3) = a5;
  result = a6;
  *((_DWORD *)v8 + 4) = a6;
  *((_DWORD *)v8 + 5) = a7;
  return result;
}


// address=[0x1496d60]
// Decompiled from void *__thiscall IMessageTracer::Init(IMessageTracer *this)

void  IMessageTracer::Init(void) {
  
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0xFFFFFFFF;
  return j__memset((char *)this + 8, 0, 0x60000u);
}


// address=[0x1496da0]
// Decompiled from IMessageTracer *__thiscall IMessageTracer::Done(IMessageTracer *this)

void  IMessageTracer::Done(void) {
  
  IMessageTracer *result; // eax

  result = this;
  if ( *(int *)this < 0 )
    return result;
  result = *(IMessageTracer **)this;
  *((_DWORD *)this + 1) = *(_DWORD *)this;
  *(_DWORD *)this = -1;
  return result;
}


// address=[0x1496dd0]
// Decompiled from int __thiscall IMessageTracer::PrintMessages(IMessageTracer *this, int a2, unsigned int a3)

void  IMessageTracer::PrintMessages(unsigned int,unsigned int) {
  
  int result; // eax
  int v4; // [esp+0h] [ebp-430h]
  int v5; // [esp+4h] [ebp-42Ch]
  int v6; // [esp+8h] [ebp-428h]
  int v7; // [esp+Ch] [ebp-424h]
  int v8; // [esp+10h] [ebp-420h]
  int v9; // [esp+14h] [ebp-41Ch]
  int j; // [esp+18h] [ebp-418h]
  int v11; // [esp+1Ch] [ebp-414h]
  int i; // [esp+20h] [ebp-410h]
  IMessageTracer *v13; // [esp+24h] [ebp-40Ch]
  int v14; // [esp+28h] [ebp-408h]
  char Source[1024]; // [esp+2Ch] [ebp-404h] BYREF

  v13 = this;
  result = (int)this;
  if ( *((int *)this + 1) < 0 )
  {
    result = (int)v13;
    v9 = *(_DWORD *)v13;
  }
  else
  {
    v9 = *((_DWORD *)v13 + 1);
  }
  v11 = v9;
  if ( v9 < 0 )
    return result;
  result = 24;
  if ( !*((_DWORD *)v13 + 2) )
    return result;
  j__memset(Source, 0, sizeof(Source));
  if ( *((_DWORD *)v13 + 98300) )
  {
    v5 = v11;
    v7 = 0x4000;
    result = 4;
    v6 = 0;
    v8 = v11;
  }
  else
  {
    v5 = 0;
    v7 = v11;
    v6 = 0;
    result = 4;
    v8 = 0;
  }
  for ( i = 0; i < 2; ++i )
  {
    result = *(&v7 + i);
    v4 = result;
    for ( j = *(&v5 + i); j < v4; ++j )
    {
      v14 = (int)v13 + 24 * j + 8;
      if ( *(_DWORD *)v14 )
      {
        j___snprintf(
          Source,
          0x3FFu,
          *(const char *const *)v14,
          *(_DWORD *)(v14 + 4),
          *(_DWORD *)(v14 + 8),
          *(_DWORD *)(v14 + 12),
          *(_DWORD *)(v14 + 16),
          *(_DWORD *)(v14 + 20));
        if ( Source[0] )
          BBSupportTracePrint(a2, Source);
      }
      result = j + 1;
    }
  }
  return result;
}


// address=[0x14970f0]
// Decompiled from IMessageTracer *__thiscall IMessageTracer::IMessageTracer(IMessageTracer *this)

 IMessageTracer::IMessageTracer(void) {
  
  *(_DWORD *)this = -1;
  *((_DWORD *)this + 1) = -1;
  return this;
}


// address=[0x1558d30]
// Decompiled from char __thiscall IMessageTracer::RemoveCurrentMsgIfEqual(const char **this, const char *a2, const char *a3)

bool  IMessageTracer::RemoveCurrentMsgIfEqual(char const *,int) {
  
  int v4; // [esp+0h] [ebp-8h]

  if ( (int)*this < 0 )
    return 0;
  v4 = ((unsigned __int16)*this - 1) & 0x3FFF;
  if ( this[6 * v4 + 2] != a2 || this[6 * v4 + 3] != a3 )
    return 0;
  *this = (const char *)v4;
  return 1;
}


// address=[0x1301410]
// Decompiled from char *__thiscall IMessageTracer::GetNextTraceMsg(IMessageTracer *this)

struct IMessageTracer::STraceMsg *  IMessageTracer::GetNextTraceMsg(void) {
  
  char *v2; // [esp+0h] [ebp-8h]

  v2 = 0;
  if ( *(int *)this < 0 )
    return v2;
  v2 = (char *)this + 24 * *(_DWORD *)this + 8;
  *(_DWORD *)this = ((unsigned __int16)*(_DWORD *)this + 1) & 0x3FFF;
  return v2;
}


