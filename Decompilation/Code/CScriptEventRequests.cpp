#include "CScriptEventRequests.h"

// Definitions for class CScriptEventRequests

// address=[0x1439f30]
// Decompiled from int __thiscall CScriptEventRequests::Size(CScriptEventRequests *this)
int  CScriptEventRequests::Size(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x15febd0]
// Decompiled from int __thiscall CScriptEventRequests::FindFunction(CScriptEventRequests *this, unsigned int a2)
int  CScriptEventRequests::FindFunction(int) {
  
  int v3; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  if ( a2 >= 0x40
    && BBSupportDbgReport(
         2,
         "Script\\GameScriptManager.cpp",
         93,
         "static_cast<unsigned int>(_iScriptFuncId) < CScriptManager::REGISTERED_FUNCTION_MAX") == 1 )
  {
    __debugbreak();
  }
  v3 = -1;
  for ( i = 0; i < *(_DWORD *)this; ++i )
  {
    if ( *((unsigned __int8 *)this + i + 4) == a2 )
      return i;
  }
  return v3;
}


// address=[0x15fec50]
// Decompiled from char *__thiscall CScriptEventRequests::AddFunction(CScriptEventRequests *this, unsigned int a2)
void  CScriptEventRequests::AddFunction(int) {
  
  char *result; // eax
  int v3; // [esp+0h] [ebp-10h]
  int v4; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  if ( a2 >= 0x40
    && BBSupportDbgReport(
         2,
         "Script\\GameScriptManager.cpp",
         119,
         "static_cast<unsigned int>(_iScriptFuncId) < CScriptManager::REGISTERED_FUNCTION_MAX") == 1 )
  {
    __debugbreak();
  }
  v4 = -1;
  v3 = *(_DWORD *)this;
  for ( i = 0; ; ++i )
  {
    if ( i >= v3 )
      goto LABEL_10;
    result = (char *)*((unsigned __int8 *)this + i + 4);
    if ( result == (char *)a2 )
      break;
    if ( *((unsigned __int8 *)this + i + 4) == 255 )
    {
      v4 = i;
LABEL_10:
      while ( i < v3 )
      {
        result = (char *)this + i;
        if ( *((unsigned __int8 *)this + i + 4) == a2 )
          return result;
        ++i;
      }
      if ( v4 < 0 )
        v4 = (*(_DWORD *)this)++;
      if ( *(_DWORD *)this >= 0x40u
        && BBSupportDbgReport(
             2,
             "Script\\GameScriptManager.cpp",
             155,
             "static_cast<unsigned int>(m_iSize) < CScriptManager::REGISTERED_FUNCTION_MAX") == 1 )
      {
        __debugbreak();
      }
      result = (char *)this + v4;
      *((_BYTE *)this + v4 + 4) = a2;
      return result;
    }
  }
  return result;
}


// address=[0x15fed50]
// Decompiled from CScriptEventRequests *__thiscall CScriptEventRequests::RemoveFunction(CScriptEventRequests *this, unsigned int a2)
void  CScriptEventRequests::RemoveFunction(int) {
  
  CScriptEventRequests *result; // eax
  int i; // [esp+8h] [ebp-4h]

  if ( a2 >= 0x40
    && BBSupportDbgReport(
         2,
         "Script\\GameScriptManager.cpp",
         167,
         "static_cast<unsigned int>(_iScriptFuncId) < CScriptManager::REGISTERED_FUNCTION_MAX") == 1 )
  {
    __debugbreak();
  }
  result = (CScriptEventRequests *)CScriptEventRequests::FindFunction(this, a2);
  if ( (int)result < 0 )
    return result;
  *((_BYTE *)this + (_DWORD)result + 4) = -1;
  for ( i = *(_DWORD *)this - 1; i > 0 && *((unsigned __int8 *)this + i + 4) == 255; --i )
    ;
  result = this;
  *(_DWORD *)this = i + 1;
  return result;
}


// address=[0x15fede0]
// Decompiled from int __thiscall CScriptEventRequests::Load(CScriptEventRequests *this, struct IS4Chunk *a2)
void  CScriptEventRequests::Load(class IS4Chunk &) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, void *))(*(_DWORD *)a2 + 12))(a2, &unk_4587050);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 64, 64);
  *(_DWORD *)this = (*(int (__thiscall **)(struct IS4Chunk *, _DWORD, int))(*(_DWORD *)a2 + 4))(a2, 0, 64);
  return (**(int (__thiscall ***)(struct IS4Chunk *, char *, int))a2)(a2, (char *)this + 4, 64);
}


// address=[0x15fee40]
// Decompiled from int __thiscall CScriptEventRequests::Save(CScriptEventRequests *this, struct IS4Chunk *a2)
void  CScriptEventRequests::Save(class IS4Chunk &) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, void *))(*(_DWORD *)a2 + 24))(a2, &unk_4587050);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 64);
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *(_DWORD *)this);
  return (*(int (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 4, 64);
}


// address=[0x1601cf0]
// Decompiled from CScriptEventRequests *__thiscall CScriptEventRequests::CScriptEventRequests(CScriptEventRequests *this)
 CScriptEventRequests::CScriptEventRequests(void) {
  
  CScriptEventRequests::Clear(this);
  return this;
}


// address=[0x1601d30]
// Decompiled from int __thiscall CScriptEventRequests::operator[](unsigned int *this, unsigned int a2)
int  CScriptEventRequests::operator[](int)const {
  
  if ( a2 >= *this
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\GameScriptManager.h",
         86,
         "static_cast<unsigned int>(_iIdx) < static_cast<unsigned int>(m_iSize)") == 1 )
  {
    __debugbreak();
  }
  return *((unsigned __int8 *)this + a2 + 4);
}


// address=[0x16022d0]
// Decompiled from void *__thiscall CScriptEventRequests::Clear(CScriptEventRequests *this)
void  CScriptEventRequests::Clear(void) {
  
  *(_DWORD *)this = 0;
  return j__memset((char *)this + 4, 255, 0x40u);
}


