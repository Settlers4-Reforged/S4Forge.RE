#include "all_headers.h"

// Definitions for class CFutureEvents

// address=[0x144fff0]
// Decompiled from CFutureEvents *__thiscall CFutureEvents::CFutureEvents(CFutureEvents *this)
 CFutureEvents::CFutureEvents(void) {
  
  IFutureEvents::IFutureEvents(this);
  CBBObject::CBBObject((CFutureEvents *)((char *)this + 4), (int)&dword_36AD194[1], 1);
  *(_DWORD *)this = CFutureEvents::_vftable_;
  *((_DWORD *)this + 1) = &CFutureEvents::`vftable';
  CFutureEvents::Init(this);
  return this;
}


// address=[0x1450070]
// Decompiled from CFutureEvents *__thiscall CFutureEvents::Release(CFutureEvents *this)
void  CFutureEvents::Release(void) {
  
  CFutureEvents *result; // eax

  result = this;
  if ( this )
    return (CFutureEvents *)(**((int (__thiscall ***)(char *, int))this + 1))((char *)this + 4, 1);
  return result;
}


// address=[0x14500b0]
// Decompiled from char __thiscall CFutureEvents::AddFutureEvent32(int this, int a2, int a3, int a4, int a5, int a6)
bool  CFutureEvents::AddFutureEvent32(enum T_FUTURE_EVENT,unsigned int,unsigned int,unsigned int,unsigned int) {
  
  unsigned int v7; // [esp+Ch] [ebp-18h]
  int UniqueId; // [esp+14h] [ebp-10h]
  int v9; // [esp+18h] [ebp-Ch]
  _BYTE *v11; // [esp+20h] [ebp-4h]

  if ( a2 <= 0 && BBSupportDbgReport(2, (int)"Logic\\FutureEvents.cpp", 303, (int)"_tType > FUTURE_EVENT_NONE") == 1 )
    __debugbreak();
  if ( a2 >= 10 && BBSupportDbgReport(2, (int)"Logic\\FutureEvents.cpp", 304, (int)"_tType < FUTURE_EVENT_MAX") == 1 )
    __debugbreak();
  if ( *(_BYTE *)(this + 20)
    && !a3
    && BBSupportDbgReport(2, (int)"Logic\\FutureEvents.cpp", 306, (int)"!m_bInExecute || (_uExecutionDelay > 0)") == 1 )
  {
    __debugbreak();
  }
  if ( a2 == 7
    && a4
    && BBSupportDbgReport(
         2,
         (int)"Logic\\FutureEvents.cpp",
         308,
         (int)"(_tType != FUTURE_EVENT_MOVING_ANIMAL_UPDATE) || (_uId == 0)") == 1 )
  {
    __debugbreak();
  }
  if ( a2 == 4
    && a4
    && BBSupportDbgReport(
         2,
         (int)"Logic\\FutureEvents.cpp",
         309,
         (int)"(_tType != FUTURE_EVENT_SPELL_TERAINCONVERSION) || (_uId == 0)") == 1 )
  {
    __debugbreak();
  }
  *(_DWORD *)(this + 24) = -1;
  if ( !a2 )
    return 0;
  v9 = *(unsigned __int16 *)(this + 74);
  if ( !*(_WORD *)(this + 74) )
    return 0;
  v7 = a3 + CStateGame::GetTickCounter(g_pGame);
  CFutureEvents::RemoveFutureEventFromList(v9);
  CFutureEvents::AddFutureEventToList(v7 % 0x20 + 2, v9);
  v11 = (_BYTE *)(this + 24 * v9 + 28);
  if ( *v11
    && BBSupportDbgReport(2, (int)"Logic\\FutureEvents.cpp", 337, (int)"rFutureEvent.m_uType == FUTURE_EVENT_NONE") == 1 )
  {
    __debugbreak();
  }
  if ( a4 )
    UniqueId = CMapObjectMgr::GetUniqueId(a4);
  else
    UniqueId = 0;
  *v11 = a2;
  *(_WORD *)(this + 24 * v9 + 30) = a4;
  *(_DWORD *)(this + 24 * v9 + 32) = UniqueId;
  *(_DWORD *)(this + 24 * v9 + 36) = v7;
  *(_DWORD *)(this + 24 * v9 + 40) = a5;
  *(_DWORD *)(this + 24 * v9 + 44) = a6;
  return 1;
}


// address=[0x14502b0]
// Decompiled from CFutureEvents *__thiscall CFutureEvents::Execute(CFutureEvents *this)
void  CFutureEvents::Execute(void) {
  
  CFutureEvents *result; // eax
  unsigned int v2; // [esp+0h] [ebp-28h]
  unsigned int v3; // [esp+Ch] [ebp-1Ch]
  unsigned int TickCounter; // [esp+10h] [ebp-18h]
  unsigned int i; // [esp+18h] [ebp-10h]
  struct CFutureEvents::SFutureEvent *v6; // [esp+1Ch] [ebp-Ch]
  char v8; // [esp+27h] [ebp-1h]

  if ( *((_BYTE *)this + 20) && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 362, "!m_bInExecute") == 1 )
    __debugbreak();
  *((_BYTE *)this + 20) = 1;
  *((_DWORD *)this + 6) = -1;
  TickCounter = CStateGame::GetTickCounter(g_pGame);
  for ( i = *((unsigned __int16 *)this + 12 * (TickCounter % 0x20) + 49); i; i = v2 )
  {
    v6 = (CFutureEvents *)((char *)this + 24 * i + 28);
    v8 = 0;
    if ( !*((_WORD *)this + 12 * i + 15)
      || CMapObjectMgr::GetUniqueId(*((unsigned __int16 *)this + 12 * i + 15)) == *((_DWORD *)this + 6 * i + 8) )
    {
      if ( *((_DWORD *)this + 6 * i + 9) <= TickCounter )
      {
        v3 = *(unsigned __int8 *)v6;
        if ( v3 >= 0xA )
        {
          if ( BBSupportDbgReport(1, "Logic\\FutureEvents.cpp", 414, "CFutureEvents::Execute(): Invalid type!") == 1 )
            __debugbreak();
        }
        else
        {
          CFutureEvents::m_pExecuteFunctions[v3](v6);
        }
        v8 = 1;
      }
    }
    else
    {
      v8 = 1;
    }
    v2 = *((unsigned __int16 *)this + 12 * i + 25);
    if ( v8 )
    {
      *(_BYTE *)v6 = 0;
      CFutureEvents::RemoveFutureEventFromList(this, i);
      CFutureEvents::AddFutureEventToList(this, 1u, i);
    }
  }
  result = this;
  *((_BYTE *)this + 20) = 0;
  return result;
}


// address=[0x1450410]
// Decompiled from int __thiscall CFutureEvents::Load(CFutureEvents *this, struct IS4Chunk *a2)
void  CFutureEvents::Load(class IS4Chunk &) {
  
  int result; // eax
  int pExceptionObject; // [esp+0h] [ebp-10h] BYREF
  unsigned int v4; // [esp+4h] [ebp-Ch]
  unsigned int v5; // [esp+8h] [ebp-8h]
  CFutureEvents *v6; // [esp+Ch] [ebp-4h]

  v6 = this;
  CFutureEvents::Init(this);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 1729263890);
  v5 = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  if ( v5 == -1 )
  {
    *((_DWORD *)v6 + 6) = -1;
    (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 393216, 393216);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v6 + 28, 393216);
  }
  else
  {
    if ( v5 > 0x3FDE )
    {
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    *((_DWORD *)v6 + 6) = v5;
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v6 + 76, 24 * (*((_DWORD *)v6 + 6) + 32));
    v4 = *((_DWORD *)v6 + 6) + 34;
    if ( v4 >= 0x4000 )
    {
      *((_WORD *)v6 + 37) = 0;
    }
    else
    {
      *((_WORD *)v6 + 37) = v4;
      *((_WORD *)v6 + 12 * v4 + 24) = 1;
    }
  }
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 1972384132);
  result = (*(int (__thiscall **)(CFutureEvents *, _DWORD))(*(_DWORD *)v6 + 20))(v6, 0);
  if ( !result )
    return result;
  result = BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 583, "DbgCheckData() == 0");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x1450590]
// Decompiled from int __thiscall CFutureEvents::Save(CFutureEvents *this, struct IS4Chunk *a2)
void  CFutureEvents::Save(class IS4Chunk &) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 1729263890);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, -1);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 393216);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 28, 393216);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 1972384132);
}


// address=[0x1450610]
// Decompiled from int __thiscall CFutureEvents::DbgCheckData(CFutureEvents *this, int a2)
unsigned int  CFutureEvents::DbgCheckData(int) {
  
  unsigned int jj; // [esp+10h] [ebp-4030h]
  unsigned int k; // [esp+14h] [ebp-402Ch]
  unsigned int n; // [esp+1Ch] [ebp-4024h]
  unsigned int m; // [esp+20h] [ebp-4020h]
  unsigned int ii; // [esp+24h] [ebp-401Ch]
  unsigned int i; // [esp+2Ch] [ebp-4014h]
  unsigned int j; // [esp+30h] [ebp-4010h]
  int v11; // [esp+38h] [ebp-4008h]
  _BYTE v12[16384]; // [esp+3Ch] [ebp-4004h] BYREF

  BBSupportTracePrintF(1, "CFutureEvents::DbgCheckData()...");
  v11 = 0;
  for ( i = 0; i < 0x22; ++i )
  {
    if ( *((_BYTE *)this + 24 * i + 28) )
    {
      BBSupportTracePrintF(1, "  Type for entry %u isn't FUTURE_EVENT_NONE!", i);
      ++v11;
    }
    if ( *((_WORD *)this + 12 * i + 24) )
    {
      BBSupportTracePrintF(1, "  PrevEvent for entry %u isn't 0!", i);
      ++v11;
    }
    if ( *((_WORD *)this + 12 * i + 25) )
    {
      if ( *((unsigned __int16 *)this + 12 * i + 25) >= 0x22u )
      {
        if ( *((unsigned __int16 *)this + 12 * i + 25) < 0x4000u )
        {
          if ( *((unsigned __int16 *)this + 12 * *((unsigned __int16 *)this + 12 * i + 25) + 24) != i )
          {
            BBSupportTracePrintF(1, "  Invalid NextEvent for entry %u!", i);
            ++v11;
          }
        }
        else
        {
          BBSupportTracePrintF(1, "  NextEvent for entry %u is >= FUTURE_EVENTS_MAX!", i);
          ++v11;
        }
      }
      else
      {
        BBSupportTracePrintF(1, "  NextEvent for entry %u is < FIRST_REAL_ID!", i);
        ++v11;
      }
    }
  }
  for ( j = 34; j < 0x4000; ++j )
  {
    if ( *((_WORD *)this + 12 * j + 24) )
    {
      if ( *((unsigned __int16 *)this + 12 * j + 24) >= 0x22u )
      {
        if ( *((unsigned __int16 *)this + 12 * j + 24) < 0x4000u )
        {
          if ( *((unsigned __int16 *)this + 12 * *((unsigned __int16 *)this + 12 * j + 24) + 25) != j )
          {
            BBSupportTracePrintF(1, "  Invalid PrevEvent for entry %u!", j);
            ++v11;
          }
        }
        else
        {
          BBSupportTracePrintF(1, "  PrevEvent for entry %u is >= FUTURE_EVENTS_MAX!", j);
          ++v11;
        }
      }
      else if ( *((_BYTE *)this + 24 * j + 28) )
      {
        if ( *((unsigned __int16 *)this + 12 * j + 24) < 2u || *((unsigned __int16 *)this + 12 * j + 24) >= 0x22u )
        {
          BBSupportTracePrintF(1, "  Used entry %u has invalid PrevEvent head value!", j);
          ++v11;
        }
      }
      else if ( !*((_WORD *)this + 12 * j + 24) || *((unsigned __int16 *)this + 12 * j + 24) >= 2u )
      {
        BBSupportTracePrintF(1, "  Free entry %u has invalid PrevEvent head value!", j);
        ++v11;
      }
    }
    if ( *((_WORD *)this + 12 * j + 25) )
    {
      if ( *((unsigned __int16 *)this + 12 * j + 25) >= 0x22u )
      {
        if ( *((unsigned __int16 *)this + 12 * j + 25) < 0x4000u )
        {
          if ( *((unsigned __int16 *)this + 12 * *((unsigned __int16 *)this + 12 * j + 25) + 24) != j )
          {
            BBSupportTracePrintF(1, "  Invalid NextEvent for entry %u!", j);
            ++v11;
          }
        }
        else
        {
          BBSupportTracePrintF(1, "  NextEvent for entry %u is >= FUTURE_EVENTS_MAX!", j);
          ++v11;
        }
      }
      else
      {
        BBSupportTracePrintF(1, "  NextEvent for entry %u is < FIRST_REAL_ID!", j);
        ++v11;
      }
    }
  }
  memset(v12, 0, sizeof(v12));
  for ( k = 1; k < 2; ++k )
  {
    for ( m = *((unsigned __int16 *)this + 12 * k + 25);
          m && m < 0x4000 && !v12[m];
          m = *((unsigned __int16 *)this + 12 * m + 25) )
    {
      v12[m] = 1;
      if ( *((_BYTE *)this + 24 * m + 28) )
      {
        BBSupportTracePrintF(1, "  Used entry %u is in free list %u!", m, k);
        ++v11;
      }
    }
  }
  for ( n = 0; n < 0x20; ++n )
  {
    for ( ii = *((unsigned __int16 *)this + 12 * n + 49);
          ii && ii < 0x4000 && !v12[ii];
          ii = *((unsigned __int16 *)this + 12 * ii + 25) )
    {
      v12[ii] = 1;
      if ( *((_BYTE *)this + 24 * ii + 28) )
      {
        if ( *((_DWORD *)this + 6 * ii + 9) % 0x20u != n )
        {
          BBSupportTracePrintF(
            1,
            "  Entry %u is in slot %u, but should be in slot %u!",
            ii,
            n,
            *((_DWORD *)this + 6 * ii + 9) % 0x20u);
          ++v11;
        }
      }
      else
      {
        BBSupportTracePrintF(1, "  Free entry %u is in slot %u!", ii, n);
        ++v11;
      }
    }
  }
  for ( jj = 34; jj < 0x4000; ++jj )
  {
    if ( !v12[jj] )
    {
      BBSupportTracePrintF(1, "  Entry %u isn't in any list!", jj);
      ++v11;
    }
  }
  if ( v11 )
    BBSupportTracePrintF(1, "  %u error(s) found.", v11);
  else
    BBSupportTracePrintF(1, "  No errors found.");
  return v11;
}


// address=[0x14529e0]
// Decompiled from void __thiscall CFutureEvents::~CFutureEvents(CDaoIndexFieldInfo *this)
 CFutureEvents::~CFutureEvents(void) {
  
  CBBObject::~CBBObject((CDaoIndexFieldInfo *)((char *)this + 4));
}


// address=[0x1450d00]
// Decompiled from int __thiscall CFutureEvents::Init(CFutureEvents *this)
void  CFutureEvents::Init(void) {
  
  int result; // eax
  unsigned int i; // [esp+0h] [ebp-8h]

  *((_DWORD *)this + 6) = -1;
  *((_BYTE *)this + 20) = 0;
  memset((char *)this + 28, 0, 0x60000u);
  *((_WORD *)this + 37) = 34;
  *((_WORD *)this + 432) = 1;
  *((_WORD *)this + 433) = 35;
  for ( i = 35; i < 0x3FFF; ++i )
  {
    *((_WORD *)this + 12 * i + 24) = i - 1;
    *((_WORD *)this + 12 * i + 25) = i + 1;
  }
  *((_WORD *)this + 196620) = 16382;
  result = (*(int (__thiscall **)(CFutureEvents *, _DWORD))(*(_DWORD *)this + 20))(this, 0);
  if ( !result )
    return result;
  result = BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 227, "DbgCheckData() == 0");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x1450e10]
// Decompiled from unsigned int __thiscall CFutureEvents::AddFutureEventToList(CFutureEvents *this, unsigned int a2, unsigned int a3)
void  CFutureEvents::AddFutureEventToList(unsigned int,unsigned int) {
  
  unsigned int result; // eax

  if ( !a2 && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 237, "_uListHeadId != 0") == 1 )
    __debugbreak();
  if ( a2 >= 0x22 && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 238, "_uListHeadId < FIRST_REAL_ID") == 1 )
    __debugbreak();
  if ( a3 < 0x22 && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 240, "_uFutureEventId >= FIRST_REAL_ID") == 1 )
    __debugbreak();
  if ( a3 >= 0x4000 && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 241, "_uFutureEventId < FUTURE_EVENTS_MAX") == 1 )
    __debugbreak();
  if ( *((_WORD *)this + 12 * a3 + 24)
    && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 245, "rFutureEvent.m_uPrevEvent == 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((_WORD *)this + 12 * a3 + 25)
    && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 246, "rFutureEvent.m_uNextEvent == 0") == 1 )
  {
    __debugbreak();
  }
  *((_WORD *)this + 12 * a3 + 24) = a2;
  result = 24 * a2;
  *((_WORD *)this + 12 * a3 + 25) = *((_WORD *)this + 12 * a2 + 25);
  LOWORD(result) = a3;
  *((_WORD *)this + 12 * a2 + 25) = a3;
  if ( !*((_WORD *)this + 12 * a3 + 25) )
    return result;
  result = (unsigned int)this;
  *((_WORD *)this + 12 * *((unsigned __int16 *)this + 12 * a3 + 25) + 24) = a3;
  return result;
}


// address=[0x1450f70]
// Decompiled from int __thiscall CFutureEvents::RemoveFutureEventFromList(CFutureEvents *this, unsigned int a2)
void  CFutureEvents::RemoveFutureEventFromList(unsigned int) {
  
  int result; // eax

  if ( a2 < 0x22 && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 266, "_uFutureEventId >= FIRST_REAL_ID") == 1 )
    __debugbreak();
  if ( a2 >= 0x4000 && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 267, "_uFutureEventId < FUTURE_EVENTS_MAX") == 1 )
    __debugbreak();
  if ( *((_WORD *)this + 12 * a2 + 24) )
  {
    if ( *((unsigned __int16 *)this + 12 * *((unsigned __int16 *)this + 12 * a2 + 24) + 25) != a2
      && BBSupportDbgReport(
           2,
           "Logic\\FutureEvents.cpp",
           273,
           "m_sFutureEvents[rFutureEvent.m_uPrevEvent].m_uNextEvent == _uFutureEventId") == 1 )
    {
      __debugbreak();
    }
    *((_WORD *)this + 12 * *((unsigned __int16 *)this + 12 * a2 + 24) + 25) = *((_WORD *)this + 12 * a2 + 25);
  }
  if ( *((_WORD *)this + 12 * a2 + 25) )
  {
    if ( *((unsigned __int16 *)this + 12 * *((unsigned __int16 *)this + 12 * a2 + 25) + 24) != a2
      && BBSupportDbgReport(
           2,
           "Logic\\FutureEvents.cpp",
           280,
           "m_sFutureEvents[rFutureEvent.m_uNextEvent].m_uPrevEvent == _uFutureEventId") == 1 )
    {
      __debugbreak();
    }
    *((_WORD *)this + 12 * *((unsigned __int16 *)this + 12 * a2 + 25) + 24) = *((_WORD *)this + 12 * a2 + 24);
  }
  *((_WORD *)this + 12 * a2 + 24) = 0;
  result = 0;
  *((_WORD *)this + 12 * a2 + 25) = 0;
  return result;
}


// address=[0x14510b0]
// Decompiled from int __thiscall CFutureEvents::Compactify(CFutureEvents *this)
unsigned int  CFutureEvents::Compactify(void) {
  
  _DWORD *v2; // edx
  unsigned int v3; // [esp+0h] [ebp-10h]
  unsigned int v4; // [esp+4h] [ebp-Ch]
  unsigned int i; // [esp+8h] [ebp-8h]

  if ( *((int *)this + 6) >= 0 )
    return *((_DWORD *)this + 6);
  if ( (*(int (__thiscall **)(CFutureEvents *, _DWORD))(*(_DWORD *)this + 20))(this, 0)
    && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 458, "DbgCheckData() == 0") == 1 )
  {
    __debugbreak();
  }
  v4 = 34;
  for ( i = 0x3FFF; i >= 0x22 && !*((_BYTE *)this + 24 * i + 28); --i )
    ;
  if ( i >= 0x22 )
  {
    do
    {
      while ( !*((_BYTE *)this + 24 * v4 + 28) )
      {
        while ( !*((_BYTE *)this + 24 * i + 28) )
        {
          if ( v4 >= --i )
          {
            *((_DWORD *)this + 6) = i - 33;
            if ( (*(int (__thiscall **)(CFutureEvents *, _DWORD))(*(_DWORD *)this + 20))(this, 0)
              && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 499, "DbgCheckData() == 0") == 1 )
            {
              __debugbreak();
            }
            if ( *((int *)this + 6) < 0
              && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 500, "m_iCompactifyNumberOfEvents >= 0") == 1 )
            {
              __debugbreak();
            }
            return *((_DWORD *)this + 6);
          }
        }
        if ( *((_BYTE *)this + 24 * v4 + 28)
          && BBSupportDbgReport(
               2,
               "Logic\\FutureEvents.cpp",
               506,
               "m_sFutureEvents[uFirstUnused].m_uType == FUTURE_EVENT_NONE") == 1 )
        {
          __debugbreak();
        }
        if ( !*((_BYTE *)this + 24 * i + 28)
          && BBSupportDbgReport(
               2,
               "Logic\\FutureEvents.cpp",
               507,
               "m_sFutureEvents[uLastUsed].m_uType != FUTURE_EVENT_NONE") == 1 )
        {
          __debugbreak();
        }
        if ( v4 >= i && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 509, "uFirstUnused < uLastUsed") == 1 )
          __debugbreak();
        CFutureEvents::RemoveFutureEventFromList(this, v4);
        CFutureEvents::RemoveFutureEventFromList(this, i);
        v3 = *((_DWORD *)this + 6 * i + 9) % 0x20u;
        v2 = (_DWORD *)((char *)this + 24 * v4 + 28);
        *v2 = *((_DWORD *)this + 6 * i + 7);
        v2[1] = *((_DWORD *)this + 6 * i + 8);
        v2[2] = *((_DWORD *)this + 6 * i + 9);
        v2[3] = *((_DWORD *)this + 6 * i + 10);
        v2[4] = *((_DWORD *)this + 6 * i + 11);
        v2[5] = *((_DWORD *)this + 6 * i + 12);
        memset((char *)this + 24 * i + 28, 0, 0x18u);
        CFutureEvents::AddFutureEventToList(this, 1u, i);
        CFutureEvents::AddFutureEventToList(this, v3 + 2, v4);
        --i;
      }
      ++v4;
    }
    while ( v4 < i );
    *((_DWORD *)this + 6) = i - 33;
    if ( (*(int (__thiscall **)(CFutureEvents *, _DWORD))(*(_DWORD *)this + 20))(this, 0)
      && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 484, "DbgCheckData() == 0") == 1 )
    {
      __debugbreak();
    }
    if ( *((int *)this + 6) < 0
      && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 485, "m_iCompactifyNumberOfEvents >= 0") == 1 )
    {
      __debugbreak();
    }
    return *((_DWORD *)this + 6);
  }
  else
  {
    *((_DWORD *)this + 6) = 0;
    if ( (*(int (__thiscall **)(CFutureEvents *, _DWORD))(*(_DWORD *)this + 20))(this, 0)
      && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 527, "DbgCheckData() == 0") == 1 )
    {
      __debugbreak();
    }
    if ( *((int *)this + 6) < 0
      && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 528, "m_iCompactifyNumberOfEvents >= 0") == 1 )
    {
      __debugbreak();
    }
    return *((_DWORD *)this + 6);
  }
}


// address=[0x1451430]
// Decompiled from void CFutureEvents::ExecuteNone()
static void __cdecl CFutureEvents::ExecuteNone(struct CFutureEvents::SFutureEvent &) {
  
  ;
}


// address=[0x1451440]
// Decompiled from int __cdecl CFutureEvents::ExecuteChangeEntityFlags(int a1)
static void __cdecl CFutureEvents::ExecuteChangeEntityFlags(struct CFutureEvents::SFutureEvent &) {
  
  int result; // eax
  _DWORD *v2; // [esp+4h] [ebp-4h]

  result = a1;
  if ( !*(_WORD *)(a1 + 2) )
    return result;
  v2 = (_DWORD *)CMapObjectMgr::Entity(*(unsigned __int16 *)(a1 + 2));
  result = IEntity::FlagBits(v2, AliveMask|0x1000);
  if ( !result )
    return result;
  IEntity::SetFlagBits(v2, *(EntityFlag *)(a1 + 12));
  return IEntity::ClearFlagBits(v2, *(EntityFlag *)(a1 + 16));
}


// address=[0x14514a0]
// Decompiled from _DWORD *__cdecl CFutureEvents::ExecuteDamageEntity(struct CFutureEvents::SFutureEvent *a1)
static void __cdecl CFutureEvents::ExecuteDamageEntity(struct CFutureEvents::SFutureEvent &) {
  
  _DWORD *result; // eax
  int v2; // [esp+0h] [ebp-10h]
  _DWORD *v3; // [esp+4h] [ebp-Ch]
  _DWORD *v4; // [esp+Ch] [ebp-4h]

  result = (_DWORD *)*((_DWORD *)a1 + 3);
  v3 = result;
  v2 = *((_DWORD *)a1 + 4);
  if ( !*((_WORD *)a1 + 1) )
    return result;
  if ( (int)result <= 0 )
    return result;
  result = (_DWORD *)CMapObjectMgr::EntityPtr(*((unsigned __int16 *)a1 + 1));
  v4 = result;
  if ( !result )
    return result;
  result = (_DWORD *)IEntity::FlagBits(result, (EntityFlag)&loc_3000000);
  if ( result )
    return (_DWORD *)(*(int (__thiscall **)(_DWORD *, _DWORD *, int))(*v4 + 28))(v4, v3, v2);
  return result;
}


// address=[0x1451510]
// Decompiled from void __cdecl CFutureEvents::ExecuteCastSpell(struct CFutureEvents::SFutureEvent *a1)
static void __cdecl CFutureEvents::ExecuteCastSpell(struct CFutureEvents::SFutureEvent &) {
  
  CMagic::ExecuteCastSpell(*((unsigned __int16 *)a1 + 1), *((_DWORD *)a1 + 3), *((_DWORD *)a1 + 4));
}


// address=[0x1451540]
// Decompiled from int __cdecl CFutureEvents::ExecuteSpellTerrainConversion(struct CFutureEvents::SFutureEvent *a1)
static void __cdecl CFutureEvents::ExecuteSpellTerrainConversion(struct CFutureEvents::SFutureEvent &) {
  
  int v1; // ecx
  int v2; // esi
  int v3; // edx
  int v4; // ecx
  int v5; // ecx
  int result; // eax
  unsigned int v7; // [esp+8h] [ebp-28h]
  int v8; // [esp+Ch] [ebp-24h]
  int v9; // [esp+10h] [ebp-20h]
  int v10; // [esp+14h] [ebp-1Ch]
  int v11; // [esp+18h] [ebp-18h]
  int v12; // [esp+1Ch] [ebp-14h]
  int v13; // [esp+20h] [ebp-10h]
  int v14; // [esp+24h] [ebp-Ch]
  int v15; // [esp+28h] [ebp-8h]
  int i; // [esp+2Ch] [ebp-4h]

  v2 = CWorldManager::Width(v1);
  if ( v2 != CWorldManager::Height(v4, v3)
    && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 1100, "g_cWorld.Width() == g_cWorld.Height()") == 1 )
  {
    __debugbreak();
  }
  v8 = CWorldManager::Width(v5) - 6;
  v12 = CFutureEvents::LoWord(*((_DWORD *)a1 + 3));
  v11 = CFutureEvents::HiWord(*((_DWORD *)a1 + 3));
  result = CWorldManager::InWorld(v12, v11);
  if ( !(_BYTE)result )
    return result;
  v13 = CFutureEvents::LoWord(*((_DWORD *)a1 + 4));
  v7 = CFutureEvents::HiWord(*((_DWORD *)a1 + 4));
  v10 = CSpiralOffsets::First(v13);
  result = CSpiralOffsets::Last(v13);
  v9 = result;
  for ( i = v10; i <= v9; ++i )
  {
    v14 = v12 + CSpiralOffsets::DeltaX(i);
    v15 = v11 + CSpiralOffsets::DeltaY(i);
    if ( Grid::InQuadrat((Grid *)(v14 - 3), v15 - 3, v8) )
    {
      CWorldManager::Index(v14, v15);
      sub_1451FA0(v14, v15, 3, v7);
    }
    result = i + 1;
  }
  return result;
}


// address=[0x14516a0]
// Decompiled from CBuilding *__cdecl CFutureEvents::ExecuteCrushBuilding(struct CFutureEvents::SFutureEvent *a1)
static void __cdecl CFutureEvents::ExecuteCrushBuilding(struct CFutureEvents::SFutureEvent &) {
  
  CBuilding *result; // eax

  result = a1;
  if ( !*((_WORD *)a1 + 1) )
    return result;
  result = (CBuilding *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)a1 + 1));
  if ( result )
    return (CBuilding *)CBuilding::CrushBuilding(result);
  return result;
}


// address=[0x14516e0]
// Decompiled from struct CVehicle *__cdecl CFutureEvents::ExecuteVehicleFire(struct CFutureEvents::SFutureEvent *a1)
static void __cdecl CFutureEvents::ExecuteVehicleFire(struct CFutureEvents::SFutureEvent &) {
  
  struct CVehicle *result; // eax
  CVehicle *v2; // [esp+Ch] [ebp-4h]

  result = CVehicleMgr::GetVehiclePtr(*((unsigned __int16 *)a1 + 1));
  v2 = result;
  if ( !result )
    return result;
  result = (struct CVehicle *)IEntity::FlagBits(result, (EntityFlag)((char *)&loc_1FFFFFF + 1));
  if ( result )
    return (struct CVehicle *)CVehicle::FireMissile(v2, *((_DWORD *)a1 + 3), *((_DWORD *)a1 + 4));
  return result;
}


// address=[0x1451740]
// Decompiled from void __cdecl CFutureEvents::ExecuteMovingAnimalUpdate(struct CFutureEvents::SFutureEvent *a1)
static void __cdecl CFutureEvents::ExecuteMovingAnimalUpdate(struct CFutureEvents::SFutureEvent &) {
  
  CAnimalMgr::UpdateMovingEffect(
    (CAnimalMgr *)&g_cAnimalMgr,
    (unsigned __int16)*((_DWORD *)a1 + 3),
    HIWORD(*((_DWORD *)a1 + 3)),
    (unsigned __int16)*((_DWORD *)a1 + 4),
    HIWORD(*((_DWORD *)a1 + 4)));
}


// address=[0x14517a0]
// Decompiled from char __cdecl CFutureEvents::ExecuteEnslaveSettler(struct CFutureEvents::SFutureEvent *a1)
static void __cdecl CFutureEvents::ExecuteEnslaveSettler(struct CFutureEvents::SFutureEvent &) {
  
  unsigned __int8 *SettlerPtr; // eax
  unsigned __int8 *v2; // eax
  _BYTE v4[24]; // [esp+4h] [ebp-5Ch] BYREF
  CEntityEvent *v5; // [esp+1Ch] [ebp-44h]
  CEntityEvent *v6; // [esp+20h] [ebp-40h]
  int v7; // [esp+24h] [ebp-3Ch]
  unsigned __int8 *v8; // [esp+28h] [ebp-38h]
  unsigned __int8 *v9; // [esp+2Ch] [ebp-34h]
  BOOL v10; // [esp+30h] [ebp-30h]
  unsigned __int8 *v11; // [esp+34h] [ebp-2Ch]
  int v12; // [esp+38h] [ebp-28h]
  int v13; // [esp+3Ch] [ebp-24h]
  int v14; // [esp+40h] [ebp-20h]
  int v15; // [esp+44h] [ebp-1Ch]
  unsigned __int8 *v16; // [esp+48h] [ebp-18h]
  unsigned __int8 *v17; // [esp+4Ch] [ebp-14h]
  bool v18; // [esp+53h] [ebp-Dh]
  int v19; // [esp+5Ch] [ebp-4h]

  v15 = (unsigned __int16)*((_DWORD *)a1 + 3);
  v12 = HIWORD(*((_DWORD *)a1 + 3));
  v8 = (unsigned __int8 *)*((_DWORD *)a1 + 4);
  SettlerPtr = CSettlerMgr::GetSettlerPtr(v15);
  v16 = SettlerPtr;
  if ( !SettlerPtr )
    return (char)SettlerPtr;
  SettlerPtr = (unsigned __int8 *)IEntity::UniqueId(v16);
  if ( SettlerPtr != v8 )
    return (char)SettlerPtr;
  v13 = IEntity::X(v16);
  v14 = IEntity::Y(v16);
  v10 = IEntity::FlagBits(v16, OnBoard|Visible) == 256 && CWorldManager::MapObjectId(v13, v14) == v15;
  LOBYTE(SettlerPtr) = v10;
  v18 = v10;
  v17 = 0;
  if ( v12 > 0 )
  {
    SettlerPtr = (unsigned __int8 *)CFlyingMgr::GetManakopterPtr((CFlyingMgr *)g_cFlyingMgr, v12);
    v17 = SettlerPtr;
    if ( !SettlerPtr || (SettlerPtr = (unsigned __int8 *)IEntity::FlagBits(v17, (EntityFlag)&unk_4000000)) != 0 )
    {
      v18 = 0;
      v17 = 0;
    }
  }
  if ( !v18 )
    return (char)SettlerPtr;
  IEntity::ClearFlagBits(v16, Visible);
  CSettlerMgr::DeleteSettler((CSettlerMgr *)g_cSettlerMgr, v15);
  if ( CWorldManager::MapObjectId(v13, v14)
    && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 1235, "g_cWorld.MapObjectId(iTargetX, iTargetY) == 0") == 1 )
  {
    __debugbreak();
  }
  v2 = (unsigned __int8 *)CSettlerMgr::operator[](*((unsigned __int16 *)a1 + 1));
  v7 = IEntity::OwnerId(v2);
  SettlerPtr = (unsigned __int8 *)CSettlerMgr::AddSettler((CSettlerMgr *)g_cSettlerMgr, v13, v14, v7, 55, 2);
  v9 = SettlerPtr;
  if ( !v17 )
    return (char)SettlerPtr;
  SettlerPtr = CSettlerMgr::GetSettlerPtr((int)v9);
  v11 = SettlerPtr;
  if ( !SettlerPtr )
    return (char)SettlerPtr;
  (*(void (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)v17 + 112))(v17, v9);
  v6 = CEntityEvent::CEntityEvent((CEntityEvent *)v4, 0x1Cu, 0, v12, 0, 0);
  v5 = v6;
  v19 = 0;
  (*(void (__thiscall **)(unsigned __int8 *, CEntityEvent *))(*(_DWORD *)v11 + 80))(v11, v6);
  v19 = -1;
  LOBYTE(SettlerPtr) = CEntityEvent::~CEntityEvent(v4);
  return (char)SettlerPtr;
}


// address=[0x14519c0]
// Decompiled from int __cdecl CFutureEvents::ExecuteFreeServant(struct CFutureEvents::SFutureEvent *a1)
static void __cdecl CFutureEvents::ExecuteFreeServant(struct CFutureEvents::SFutureEvent &) {
  
  int result; // eax
  unsigned __int8 *v2; // [esp+4h] [ebp-20h]
  int v3; // [esp+8h] [ebp-1Ch]
  int v4; // [esp+Ch] [ebp-18h]
  int v5; // [esp+10h] [ebp-14h]
  int v6; // [esp+14h] [ebp-10h]
  int v7; // [esp+18h] [ebp-Ch]
  unsigned __int8 *SettlerPtr; // [esp+1Ch] [ebp-8h]
  bool v9; // [esp+23h] [ebp-1h]

  v5 = *((unsigned __int16 *)a1 + 1);
  v4 = *((_DWORD *)a1 + 3);
  if ( v4 <= 0 && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 1286, "iPlayerId > 0") == 1 )
    __debugbreak();
  SettlerPtr = CSettlerMgr::GetSettlerPtr(v5);
  if ( SettlerPtr )
  {
    v6 = IEntity::X(SettlerPtr);
    v7 = IEntity::Y(SettlerPtr);
    v9 = IEntity::FlagBits(SettlerPtr, OnBoard|Visible) == 256 && CWorldManager::MapObjectId(v6, v7) == v5;
    if ( !v9 && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 1301, "bOk") == 1 )
      __debugbreak();
    result = 0;
    if ( v9 )
    {
      if ( IEntity::Type((unsigned __int16 *)SettlerPtr) != 55
        && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 1308, "pServant->Type() == SETTLER_SLAVED_SETTLER") == 1 )
      {
        __debugbreak();
      }
      IEntity::ClearFlagBits(SettlerPtr, Visible);
      CSettlerMgr::DeleteSettler((CSettlerMgr *)g_cSettlerMgr, v5);
      if ( CWorldManager::MapObjectId(v6, v7)
        && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 1313, "g_cWorld.MapObjectId(iServantX, iServantY) == 0") == 1 )
      {
        __debugbreak();
      }
      result = CSettlerMgr::AddSettler((CSettlerMgr *)g_cSettlerMgr, v6, v7, v4, 1, 0);
      v3 = result;
      if ( result > 0 )
      {
        result = CWorldManager::OwnerId(v6, v7);
        if ( result != v4 )
        {
          v2 = CSettlerMgr::GetSettlerPtr(v3);
          if ( !v2 && BBSupportDbgReport(2, "Logic\\FutureEvents.cpp", 1323, "pCarrier != 0") == 1 )
            __debugbreak();
          return CSettler::CheckFlee((CSettler *)v2, 0);
        }
      }
    }
  }
  else
  {
    result = BBSupportDbgReport(1, aLogicFutureeve_36, 1331, "CFutureEvents::ExecuteFreeServant(): Invalid entity id!");
    if ( result == 1 )
      __debugbreak();
  }
  return result;
}


// address=[0x1452a50]
// Decompiled from unsigned int __cdecl CFutureEvents::HiWord(unsigned int a1)
static unsigned int __cdecl CFutureEvents::HiWord(unsigned int) {
  
  return HIWORD(a1);
}


// address=[0x1452a60]
// Decompiled from int __cdecl CFutureEvents::LoWord(unsigned __int16 a1)
static unsigned int __cdecl CFutureEvents::LoWord(unsigned int) {
  
  return a1;
}


// address=[0x3d89530]
// [Decompilation failed for static void (__cdecl** CFutureEvents::m_pExecuteFunctions)(struct CFutureEvents::SFutureEvent &)]

