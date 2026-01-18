#include "CScriptManager.h"

// Definitions for class CScriptManager

// address=[0x1601e00]
// Decompiled from CScriptManager *__thiscall CScriptManager::AllowRegisterFunction(CScriptManager *this, bool a2)
void  CScriptManager::AllowRegisterFunction(bool a2) {
  
  CScriptManager *result; // eax

  result = this;
  *((_BYTE *)this + 268) = a2;
  return result;
}


// address=[0x1601e50]
// Decompiled from int __thiscall CScriptManager::Call(CScriptManager *this, unsigned int a2)
void  CScriptManager::Call(int a2) {
  
  unsigned int Ref; // eax

  if ( a2 >= *((_DWORD *)this + 2)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\ScriptManager.h",
         50,
         "static_cast<unsigned int>(_iScriptFuncId) < static_cast<unsigned int>(m_iNumberOfRegisteredFunctions)") == 1 )
  {
    __debugbreak();
  }
  Ref = CLua::GetRef(*((void ***)this + 1), *((_DWORD *)this + a2 + 3));
  return CLua::CallFunction(*((void ***)this + 1), Ref);
}


// address=[0x1601ec0]
// Decompiled from int __thiscall CScriptManager::Call(CScriptManager *this, unsigned int a2, int a3)
void  CScriptManager::Call(int a2, int a3) {
  
  unsigned int Ref; // eax

  if ( a2 >= *((_DWORD *)this + 2)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\ScriptManager.h",
         57,
         "static_cast<unsigned int>(_iScriptFuncId) < static_cast<unsigned int>(m_iNumberOfRegisteredFunctions)") == 1 )
  {
    __debugbreak();
  }
  CLua::PushInt(*((void ***)this + 1), a3);
  Ref = CLua::GetRef(*((void ***)this + 1), *((_DWORD *)this + a2 + 3));
  return CLua::CallFunction(*((void ***)this + 1), Ref);
}


// address=[0x1601f40]
// Decompiled from int __thiscall CScriptManager::Call(CScriptManager *this, unsigned int a2, int a3, int a4)
void  CScriptManager::Call(int a2, int a3, int a4) {
  
  unsigned int Ref; // eax

  if ( a2 >= *((_DWORD *)this + 2)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\ScriptManager.h",
         65,
         "static_cast<unsigned int>(_iScriptFuncId) < static_cast<unsigned int>(m_iNumberOfRegisteredFunctions)") == 1 )
  {
    __debugbreak();
  }
  CLua::PushInt(*((void ***)this + 1), a3);
  CLua::PushInt(*((void ***)this + 1), a4);
  Ref = CLua::GetRef(*((void ***)this + 1), *((_DWORD *)this + a2 + 3));
  return CLua::CallFunction(*((void ***)this + 1), Ref);
}


// address=[0x1601fe0]
// Decompiled from int __thiscall CScriptManager::Call(CScriptManager *this, unsigned int a2, int a3, int a4, int a5)
void  CScriptManager::Call(int a2, int a3, int a4, int a5) {
  
  unsigned int Ref; // eax

  if ( a2 >= *((_DWORD *)this + 2)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\ScriptManager.h",
         74,
         "static_cast<unsigned int>(_iScriptFuncId) < static_cast<unsigned int>(m_iNumberOfRegisteredFunctions)") == 1 )
  {
    __debugbreak();
  }
  CLua::PushInt(*((void ***)this + 1), a3);
  CLua::PushInt(*((void ***)this + 1), a4);
  CLua::PushInt(*((void ***)this + 1), a5);
  Ref = CLua::GetRef(*((void ***)this + 1), *((_DWORD *)this + a2 + 3));
  return CLua::CallFunction(*((void ***)this + 1), Ref);
}


// address=[0x1602090]
// Decompiled from int __thiscall CScriptManager::Call(CScriptManager *this, unsigned int a2, int a3, int a4, int a5, int a6)
void  CScriptManager::Call(int a2, int a3, int a4, int a5, int a6) {
  
  unsigned int Ref; // eax

  if ( a2 >= *((_DWORD *)this + 2)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\ScriptManager.h",
         84,
         "static_cast<unsigned int>(_iScriptFuncId) < static_cast<unsigned int>(m_iNumberOfRegisteredFunctions)") == 1 )
  {
    __debugbreak();
  }
  CLua::PushInt(*((void ***)this + 1), a3);
  CLua::PushInt(*((void ***)this + 1), a4);
  CLua::PushInt(*((void ***)this + 1), a5);
  CLua::PushInt(*((void ***)this + 1), a6);
  Ref = CLua::GetRef(*((void ***)this + 1), *((_DWORD *)this + a2 + 3));
  return CLua::CallFunction(*((void ***)this + 1), Ref);
}


// address=[0x160deb0]
// Decompiled from CScriptManager *__thiscall CScriptManager::CScriptManager(CScriptManager *this, struct CLua *a2)
 CScriptManager::CScriptManager(class CLua & a2) {
  
  *(_DWORD *)this = &CScriptManager::_vftable_;
  if ( CScriptManager::m_pScriptManager
    && BBSupportDbgReport(2, "Script\\ScriptManager.cpp", 95, "m_pScriptManager == 0") == 1 )
  {
    __debugbreak();
  }
  CScriptManager::m_pScriptManager = (int)this;
  *((_DWORD *)this + 1) = a2;
  *((_DWORD *)this + 2) = 0;
  memset((char *)this + 12, 0, 0x100u);
  *((_BYTE *)this + 268) = 0;
  CLua::ExportFunction((int)CScriptManager::LuaRegisterFunction, (char *)&dword_381E474[1]);
  return this;
}


// address=[0x160df40]
// Decompiled from CScriptManager *__thiscall CScriptManager::~CScriptManager(CScriptManager *this)
 CScriptManager::~CScriptManager(void) {
  
  CScriptManager *result; // eax

  result = this;
  *(_DWORD *)this = &CScriptManager::_vftable_;
  CScriptManager::m_pScriptManager = 0;
  return result;
}


// address=[0x160df60]
// Decompiled from int __thiscall CScriptManager::FindFunc(CScriptManager *this, unsigned int a2)
int  CScriptManager::FindFunc(unsigned int a2) {
  
  unsigned int Ref; // eax
  int v4; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]

  if ( !*((_DWORD *)this + 1) && BBSupportDbgReport(2, "Script\\ScriptManager.cpp", 126, "m_pScriptEnv != 0") == 1 )
    __debugbreak();
  v4 = *((_DWORD *)this + 2);
  for ( i = 0; i < v4; ++i )
  {
    Ref = CLua::GetRef(*((void ***)this + 1), *((_DWORD *)this + i + 3));
    if ( CLua::EqualObjects(*((void ***)this + 1), a2, Ref) )
      return i;
  }
  return -1;
}


// address=[0x160dff0]
// Decompiled from int __thiscall CScriptManager::RegisterFunction(CScriptManager *this)
void  CScriptManager::RegisterFunction(void) {
  
  int result; // eax
  unsigned int Param; // [esp+4h] [ebp-8h]

  if ( !*((_DWORD *)this + 1) && BBSupportDbgReport(2, "Script\\ScriptManager.cpp", 148, "m_pScriptEnv != 0") == 1 )
    __debugbreak();
  Param = CLua::GetParam(*((CLua **)this + 1), 1);
  if ( *((_BYTE *)this + 268) )
  {
    if ( CLua::IsFunction(*((void ***)this + 1), Param) )
    {
      if ( CScriptManager::FindFunc(this, Param) == -1 )
      {
        if ( *((int *)this + 2) < 64 )
        {
          *((_DWORD *)this + *((_DWORD *)this + 2) + 3) = CLua::Lock(*((void ***)this + 1), Param);
          result = *((_DWORD *)this + 2) + 1;
          *((_DWORD *)this + 2) = result;
        }
        else
        {
          result = BBSupportDbgReport(
                     1,
                     "Script\\ScriptManager.cpp",
                     166,
                     "CScriptManager::RegisterFunction(): Too many registered functions!");
          if ( result == 1 )
            __debugbreak();
        }
      }
      else
      {
        result = BBSupportDbgReport(
                   1,
                   "Script\\ScriptManager.cpp",
                   162,
                   "CScriptManager::RegisterFunction(): Function already registered!");
        if ( result == 1 )
          __debugbreak();
      }
    }
    else
    {
      if ( BBSupportDbgReport(
             1,
             "Script\\ScriptManager.cpp",
             158,
             "CScriptManager::RegisterFunction(): Parameter not a function!") == 1 )
        __debugbreak();
      return 0;
    }
  }
  else
  {
    result = BBSupportDbgReportF(
               1,
               "Script\\ScriptManager.cpp",
               154,
               "CScriptManager::RegisterFunction(): Illegal call to %s (must only be used in register_functions)!",
               (const char *)&dword_381E474[1]);
    if ( result == 1 )
      __debugbreak();
  }
  return result;
}


// address=[0x160e140]
// Decompiled from int CScriptManager::LuaRegisterFunction()
void __cdecl CScriptManager::LuaRegisterFunction(void) {
  
  if ( CScriptManager::m_pScriptManager )
    return CScriptManager::RegisterFunction((CScriptManager *)CScriptManager::m_pScriptManager);
  if ( BBSupportDbgReport(
         1,
         "Script\\ScriptManager.cpp",
         191,
         "CScriptManager::LuaRegisterFunc(): m_pScriptManager == 0!") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x462b870]
// [Decompilation failed for static class CScriptManager * CScriptManager::m_pScriptManager]

