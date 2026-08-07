#if FALSE
#include "CScriptManager.h"

// Definitions for class CScriptManager

// address=[0x1601e00]
// Decompiled from void __thiscall CScriptManager::AllowRegisterFunction(CScriptManager *this, byte a2)
void  CScriptManager::AllowRegisterFunction(bool a2) {
  
  this->m_bAllowRegister = a2;
}


// address=[0x1601e50]
// Decompiled from void __thiscall CScriptManager::Call(CScriptManager *this, unsigned int a2)
void  CScriptManager::Call(int a2) {
  
  int Ref; // eax

  if ( a2 >= this->m_iNumberOfRegisteredFunctions && BBSupportDbgReport(2, "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\ScriptManager.h", 50, "static_cast<unsigned int>(_iScriptFuncId) < static_cast<unsigned int>(m_iNumberOfRegisteredFunctions)") == 1 )
  {
    __debugbreak();
  }
  Ref = CLua::GetRef(this->m_pScriptEnv, this->m_pFunctionLock[a2]);
  CLua::CallFunction(this->m_pScriptEnv, Ref);
}


// address=[0x1601ec0]
// Decompiled from void __thiscall CScriptManager::Call(CScriptManager *this, unsigned int a2, int a3)
void  CScriptManager::Call(int a2, int a3) {
  
  int Ref; // [esp-4h] [ebp-8h]

  if ( a2 >= this->m_iNumberOfRegisteredFunctions && BBSupportDbgReport(2, "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\ScriptManager.h", 57, "static_cast<unsigned int>(_iScriptFuncId) < static_cast<unsigned int>(m_iNumberOfRegisteredFunctions)") == 1 )
  {
    __debugbreak();
  }
  CLua::PushInt(this->m_pScriptEnv, a3);
  Ref = CLua::GetRef(this->m_pScriptEnv, this->m_pFunctionLock[a2]);
  CLua::CallFunction(this->m_pScriptEnv, Ref);
}


// address=[0x1601f40]
// Decompiled from void __thiscall CScriptManager::Call(CScriptManager *this, unsigned int a2, int a3, int a4)
void  CScriptManager::Call(int a2, int a3, int a4) {
  
  int Ref; // eax

  if ( a2 >= this->m_iNumberOfRegisteredFunctions && BBSupportDbgReport(2, "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\ScriptManager.h", 65, "static_cast<unsigned int>(_iScriptFuncId) < static_cast<unsigned int>(m_iNumberOfRegisteredFunctions)") == 1 )
  {
    __debugbreak();
  }
  CLua::PushInt(this->m_pScriptEnv, a3);
  CLua::PushInt(this->m_pScriptEnv, a4);
  Ref = CLua::GetRef(this->m_pScriptEnv, this->m_pFunctionLock[a2]);
  CLua::CallFunction(this->m_pScriptEnv, Ref);
}


// address=[0x1601fe0]
// Decompiled from void __thiscall CScriptManager::Call(CScriptManager *this, unsigned int _iScriptFuncId, int a3, int a4, int a5)
void  CScriptManager::Call(int _iScriptFuncId, int a3, int a4, int a5) {
  
  int Ref; // eax

  if ( _iScriptFuncId >= this->m_iNumberOfRegisteredFunctions && BBSupportDbgReport(2, "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\ScriptManager.h", 74, "static_cast<unsigned int>(_iScriptFuncId) < static_cast<unsigned int>(m_iNumberOfRegisteredFunctions)") == 1 )
  {
    __debugbreak();
  }
  CLua::PushInt(this->m_pScriptEnv, a3);
  CLua::PushInt(this->m_pScriptEnv, a4);
  CLua::PushInt(this->m_pScriptEnv, a5);
  Ref = CLua::GetRef(this->m_pScriptEnv, this->m_pFunctionLock[_iScriptFuncId]);
  CLua::CallFunction(this->m_pScriptEnv, Ref);
}


// address=[0x1602090]
// Decompiled from int __thiscall CScriptManager::Call(CScriptManager *this, unsigned int _iScriptFuncId, int a3, int a4, int a5, int a6)
void  CScriptManager::Call(int _iScriptFuncId, int a3, int a4, int a5, int a6) {
  
  int Ref; // eax

  if ( _iScriptFuncId >= this->m_iNumberOfRegisteredFunctions && BBSupportDbgReport(2, "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\ScriptManager.h", 84, "static_cast<unsigned int>(_iScriptFuncId) < static_cast<unsigned int>(m_iNumberOfRegisteredFunctions)") == 1 )
  {
    __debugbreak();
  }
  CLua::PushInt(this->m_pScriptEnv, a3);
  CLua::PushInt(this->m_pScriptEnv, a4);
  CLua::PushInt(this->m_pScriptEnv, a5);
  CLua::PushInt(this->m_pScriptEnv, a6);
  Ref = CLua::GetRef(this->m_pScriptEnv, this->m_pFunctionLock[_iScriptFuncId]);
  return CLua::CallFunction(this->m_pScriptEnv, Ref);
}


// address=[0x160deb0]
// Decompiled from CScriptManager *__thiscall CScriptManager::CScriptManager(CScriptManager *this, struct CLua *a2)
 CScriptManager::CScriptManager(class CLua & a2) {
  
  this->vtable = &CScriptManager::_vftable_;
  if ( CScriptManager::m_pScriptManager && BBSupportDbgReport(2, "Script\\ScriptManager.cpp", 95, "m_pScriptManager == 0") == 1 )
  {
    __debugbreak();
  }
  CScriptManager::m_pScriptManager = this;      // Size 0x110
  this->m_pScriptEnv = a2;
  this->m_iNumberOfRegisteredFunctions = 0;
  memset(this->m_pFunctionLock, 0, sizeof(this->m_pFunctionLock));
  this->m_bAllowRegister = 0;
  CLua::ExportFunction(this->m_pScriptEnv, (void (__cdecl *)())CScriptManager::LuaRegisterFunction, "reg_func");
  return this;
}


// address=[0x160df40]
// Decompiled from CScriptManager *__thiscall CScriptManager::~CScriptManager(CScriptManager *this)
 CScriptManager::~CScriptManager(void) {
  
  CScriptManager *result; // eax

  result = this;
  this->vtable = &CScriptManager::_vftable_;
  CScriptManager::m_pScriptManager = 0;
  return result;
}


// address=[0x160df60]
// Decompiled from int __thiscall CScriptManager::FindFunc(CScriptManager *this, int a2)
int  CScriptManager::FindFunc(unsigned int a2) {
  
  int Ref; // eax
  int m_iNumberOfRegisteredFunctions; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]

  if ( !this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\ScriptManager.cpp", 126, "m_pScriptEnv != 0") == 1 )
  {
    __debugbreak();
  }
  m_iNumberOfRegisteredFunctions = this->m_iNumberOfRegisteredFunctions;
  for ( i = 0;
        i < m_iNumberOfRegisteredFunctions;
        ++i )
  {
    Ref = CLua::GetRef(this->m_pScriptEnv, this->m_pFunctionLock[i]);
    if ( CLua::EqualObjects(this->m_pScriptEnv, a2, Ref) )
    {
      return i;
    }
  }
  return -1;
}


// address=[0x160dff0]
// Decompiled from void __thiscall CScriptManager::RegisterFunction(CScriptManager *this)
void  CScriptManager::RegisterFunction(void) {
  
  int Param; // [esp+4h] [ebp-8h]

  if ( !this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\ScriptManager.cpp", 148, "m_pScriptEnv != 0") == 1 )
  {
    __debugbreak();
  }
  Param = CLua::GetParam(this->m_pScriptEnv, 1);
  if ( this->m_bAllowRegister )
  {
    if ( CLua::IsFunction(this->m_pScriptEnv, Param) )
    {
      if ( CScriptManager::FindFunc(this, Param) == -1 )
      {
        if ( this->m_iNumberOfRegisteredFunctions < 64 )
        {
          this->m_pFunctionLock[this->m_iNumberOfRegisteredFunctions++] = CLua::Lock(this->m_pScriptEnv, Param);
        }
        else if ( BBSupportDbgReport(1, "Script\\ScriptManager.cpp", 166, "CScriptManager::RegisterFunction(): Too many registered functions!") == 1 )
        {
          __debugbreak();
        }
      }
      else if ( BBSupportDbgReport(1, "Script\\ScriptManager.cpp", 162, "CScriptManager::RegisterFunction(): Function already registered!") == 1 )
      {
        __debugbreak();
      }
    }
    else if ( BBSupportDbgReport(1, "Script\\ScriptManager.cpp", 158, "CScriptManager::RegisterFunction(): Parameter not a function!") == 1 )
    {
      __debugbreak();
    }
  }
  else if ( BBSupportDbgReportF(1, "Script\\ScriptManager.cpp", 154, "CScriptManager::RegisterFunction(): Illegal call to %s (must only be used in register_functions)!", "reg_func") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x160e140]
// Decompiled from int CScriptManager::LuaRegisterFunction()
void __cdecl CScriptManager::LuaRegisterFunction(void) {
  
  if ( CScriptManager::m_pScriptManager )
  {
    return CScriptManager::RegisterFunction(CScriptManager::m_pScriptManager);
  }
  if ( BBSupportDbgReport(1, "Script\\ScriptManager.cpp", 191, "CScriptManager::LuaRegisterFunc(): m_pScriptManager == 0!") == 1 )
  {
    __debugbreak();
  }
  return 0;
}


// address=[0x462b870]
// [Decompilation failed for static class CScriptManager * CScriptManager::m_pScriptManager]

#endif // Already implemented
