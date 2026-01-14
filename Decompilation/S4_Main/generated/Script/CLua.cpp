#include "all_headers.h"

// Definitions for class CLua

// address=[0x131eb90]
// Decompiled from void *__thiscall CLua::ActivateScriptingEnvironment(CLua *this)
struct lua_State *  CLua::ActivateScriptingEnvironment(void) {
  
  lua_state = *(void **)this;
  return *(void **)this;
}


// address=[0x1601e20]
// Decompiled from int __thiscall CLua::BeginBlock(void **this)
void  CLua::BeginBlock(void) {
  
  lua_state = *this;
  return j__lua_beginblock(this);
}


// address=[0x1602150]
// Decompiled from int __thiscall CLua::CallFunction(void **this, unsigned int a2)
void  CLua::CallFunction(unsigned int) {
  
  lua_state = *this;
  if ( !j__lua_isfunction(a2)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\Lua.h",
         407,
         "lua_isfunction(_FuncObj)") == 1 )
  {
    __debugbreak();
  }
  return j__lua_callfunction(a2);
}


// address=[0x16021c0]
// Decompiled from int __thiscall CLua::CallFunction(void **this, char *Str)
void  CLua::CallFunction(char const *) {
  
  int result; // eax
  int v3; // [esp+4h] [ebp-4h]

  if ( Str )
  {
    lua_state = *this;
    v3 = j__lua_getglobal(Str);
    if ( j__lua_isfunction(v3) )
    {
      return j__lua_callfunction(v3);
    }
    else
    {
      if ( BBSupportDbgReportF(
             1,
             "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\Lua.h",
             429,
             "CLua::CallFunction(): Function \"%s\" not found [may be ignored]!",
             Str) == 1 )
        __debugbreak();
      return 0;
    }
  }
  else
  {
    result = BBSupportDbgReport(
               1,
               "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\Lua.h",
               434,
               "CLua::CallFunction(): Invalid function name [may be ignored]!");
    if ( result == 1 )
      __debugbreak();
  }
  return result;
}


// address=[0x1602280]
// Decompiled from bool __thiscall CLua::CheckParam(void **this, int a2)
bool  CLua::CheckParam(int) {
  
  lua_state = *this;
  return j__lua_lua2C(a2) != 0;
}


// address=[0x1602310]
// Decompiled from int __thiscall CLua::CreateTable(void **this, char *Str)
void  CLua::CreateTable(char const *) {
  
  int v2; // eax

  if ( !Str
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\Lua.h",
         444,
         "_pName != NULL") == 1 )
  {
    __debugbreak();
  }
  lua_state = *this;
  v2 = j__lua_createtable();
  j__lua_pushobject(v2);
  return j__lua_setglobal(Str);
}


// address=[0x1602380]
// Decompiled from int __thiscall CLua::EndBlock(void **this)
void  CLua::EndBlock(void) {
  
  lua_state = *this;
  return j__lua_endblock(this);
}


// address=[0x16023b0]
// Decompiled from int __thiscall CLua::GetCurrentLine(void **this, unsigned int a2)
int  CLua::GetCurrentLine(unsigned int) {
  
  lua_state = *this;
  return j__lua_currentline(a2);
}


// address=[0x16023e0]
// Decompiled from int __thiscall CLua::GetFuncInfo(void **this, unsigned int a2, char **a3, int *a4)
void  CLua::GetFuncInfo(unsigned int,char * *,int *) {
  
  lua_state = *this;
  return j__lua_funcinfo(a2, a3, a4);
}


// address=[0x1602420]
// Decompiled from int __thiscall CLua::GetGlobal(void **this, char *Str)
unsigned int  CLua::GetGlobal(char const *) {
  
  if ( !Str
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\Lua.h",
         614,
         "_pName != NULL") == 1 )
  {
    __debugbreak();
  }
  lua_state = *this;
  return j__lua_getglobal(Str);
}


// address=[0x1602480]
// Decompiled from int __thiscall CLua::GetInt(CLua *this, int a2)
int  CLua::GetInt(int) {
  
  int v2; // eax

  lua_state = *(void **)this;
  CLua::dbgCheckParam(this, a2);
  v2 = j__lua_lua2C(a2);
  return (int)j__lua_getnumber(v2);
}


// address=[0x16024e0]
// Decompiled from int __thiscall CLua::GetObjName(void **this, unsigned int a2, char **a3)
char *  CLua::GetObjName(unsigned int,char * *) {
  
  lua_state = *this;
  return j__lua_getobjname(a2, a3);
}


// address=[0x1602520]
// Decompiled from int __thiscall CLua::GetParam(CLua *this, int a2)
unsigned int  CLua::GetParam(int) {
  
  lua_state = *(void **)this;
  CLua::dbgCheckParam(this, a2);
  return j__lua_lua2C(a2);
}


// address=[0x1602560]
// Decompiled from int __thiscall CLua::GetRef(void **this, int a2)
unsigned int  CLua::GetRef(int) {
  
  lua_state = *this;
  return j__lua_getref(a2);
}


// address=[0x16025e0]
// Decompiled from int __thiscall CLua::GetStackedFunction(void **this, int a2)
unsigned int  CLua::GetStackedFunction(int) {
  
  lua_state = *this;
  return j__lua_stackedfunction(a2);
}


// address=[0x1602610]
// Decompiled from int __thiscall CLua::GetString(CLua *this, int a2)
char *  CLua::GetString(int) {
  
  int v2; // eax

  lua_state = *(void **)this;
  CLua::dbgCheckParam(this, a2);
  v2 = j__lua_lua2C(a2);
  return j__lua_getstring(v2);
}


// address=[0x1602660]
// Decompiled from bool __thiscall CLua::IsNil(void **this, char *Str)
bool  CLua::IsNil(char const *) {
  
  int v3; // [esp+0h] [ebp-Ch]

  lua_state = *this;
  v3 = j__lua_getglobal(Str);
  return j__lua_isnil(v3) != 0;
}


// address=[0x1602720]
// Decompiled from int __thiscall CLua::PushInt(void **this, int a2)
void  CLua::PushInt(int) {
  
  lua_state = *this;
  return j__lua_pushnumber(COERCE__INT64((double)a2));
}


// address=[0x1602760]
// Decompiled from int __thiscall CLua::SetGlobal(void **this, char *Str)
void  CLua::SetGlobal(char const *) {
  
  if ( !Str
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\Lua.h",
         624,
         "_pName != NULL") == 1 )
  {
    __debugbreak();
  }
  lua_state = *this;
  return j__lua_setglobal(Str);
}


// address=[0x16027c0]
// Decompiled from CLua *__thiscall CLua::CLua(CLua *this)
 CLua::CLua(void) {
  
  lua_state = 0;
  j__lua_open();
  j__lua_iolibopen();
  j__lua_strlibopen();
  j__lua_setdebug(1);
  *(_DWORD *)this = lua_state;
  return this;
}


// address=[0x1602800]
// Decompiled from int __thiscall CLua::~CLua(void **this)
 CLua::~CLua(void) {
  
  int result; // eax

  lua_state = *this;
  result = j__lua_close(this);
  lua_state = 0;
  return result;
}


// address=[0x1602830]
// Decompiled from char __thiscall CLua::ExecuteScript(void **this, wchar_t *FileName)
bool  CLua::ExecuteScript(wchar_t const *) {
  
  int v3; // [esp+0h] [ebp-B4h] BYREF
  void *C; // [esp+10h] [ebp-A4h]
  void *v5; // [esp+14h] [ebp-A0h]
  void *v6; // [esp+18h] [ebp-9Ch]
  size_t v7; // [esp+1Ch] [ebp-98h]
  void **v8; // [esp+20h] [ebp-94h]
  BOOL v9; // [esp+24h] [ebp-90h]
  void *Buffer; // [esp+28h] [ebp-8Ch]
  size_t ElementCount; // [esp+2Ch] [ebp-88h]
  char v12; // [esp+32h] [ebp-82h]
  char v13; // [esp+33h] [ebp-81h]
  _DWORD v14[26]; // [esp+34h] [ebp-80h] BYREF
  _DWORD v15[3]; // [esp+9Ch] [ebp-18h] BYREF
  int v16; // [esp+B0h] [ebp-4h]

  v15[2] = &v3;
  v8 = this;
  if ( !FileName || !*FileName )
    return 0;
  v13 = 1;
  lua_state = *v8;
  ElementCount = 0;
  Buffer = 0;
  CFileEx::CFileEx((CFileEx *)v14, 1);
  v16 = 1;
  CFileEx::Open(v15, FileName, 6, 0, UNUSED_ARG(), UNUSED_ARG());
  v7 = CFileEx::Size(v14);
  ElementCount = v7;
  if ( v7 )
  {
    v6 = operator new[](ElementCount + 8);
    v5 = v6;
    Buffer = v6;
    CFileEx::Read(
      v15,
      v6,
      1,
      ElementCount,
      "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\FileEx.h",
      110);
  }
  v16 = 0;
  CFileEx::Close((CFileEx *)v15, UNUSED_ARG(), UNUSED_ARG());
  if ( Buffer )
  {
    if ( v13 )
    {
      v9 = j__lua_dobuffer(Buffer, ElementCount, 0) == 0;
      v13 = v9;
    }
    C = Buffer;
    operator delete[](Buffer);
  }
  v12 = v13;
  v16 = -1;
  CFileEx::~CFileEx(v14);
  return v12;
}


// address=[0x1602a30]
// Decompiled from bool __thiscall CLua::ExecuteScript(void **this, struct IScriptFile *a2)
bool  CLua::ExecuteScript(class IScriptFile &) {
  
  int v2; // eax
  int v4; // [esp-8h] [ebp-10h]

  lua_state = *this;
  if ( !(*(int (__thiscall **)(struct IScriptFile *, void **))(*(_DWORD *)a2 + 4))(a2, this) )
    return 0;
  v4 = (*(int (__thiscall **)(struct IScriptFile *))(*(_DWORD *)a2 + 8))(a2);
  v2 = (*(int (__thiscall **)(struct IScriptFile *))(*(_DWORD *)a2 + 4))(a2);
  return j__lua_dobuffer(v2, v4, 0) == 0;
}


// address=[0x1602aa0]
// Decompiled from bool __thiscall CLua::ExecuteScript(CLua *this, void *a2, int a3, char *a4)
bool  CLua::ExecuteScript(void *,int,char *) {
  
  return j__lua_dobuffer(a2, a3, a4) == 0;
}


// address=[0x1602ae0]
// Decompiled from bool __thiscall CLua::ExecuteString(void **this, char *Str)
bool  CLua::ExecuteString(char const *) {
  
  lua_state = *this;
  return j__lua_dostring(Str) == 0;
}


// address=[0x1602b20]
// Decompiled from int __thiscall CLua::ExportFunction(void **this, int a2, char *Str)
void  CLua::ExportFunction(void (__cdecl*)(void),char const *) {
  
  lua_state = *this;
  j__lua_pushcclosure(a2, 0);
  return j__lua_setglobal(Str);
}


// address=[0x1602b60]
// Decompiled from int __thiscall CLua::ExportTableFunction(void **this, char *a2, int a3, char *Str)
void  CLua::ExportTableFunction(char const *,void (__cdecl*)(void),char const *) {
  
  int v5; // [esp+0h] [ebp-8h]
  int v6; // [esp+4h] [ebp-4h]

  lua_state = *this;
  j__lua_beginblock(this);
  v6 = j__lua_getglobal(a2);
  if ( j__lua_isnil(v6) )
  {
    v6 = j__lua_createtable();
    j__lua_pushobject(v6);
    j__lua_setglobal(a2);
  }
  if ( !j__lua_istable(v6) && BBSupportDbgReport(2, "Script\\Lua.cpp", 253, "lua_istable(TableObj)") == 1 )
    __debugbreak();
  j__lua_pushobject(v6);
  j__lua_pushstring(Str);
  j__lua_pushcclosure(a3, 0);
  j__lua_settable();
  return j__lua_endblock(v5);
}


// address=[0x1602c20]
// Decompiled from int __stdcall CLua::ExportFunctions(int a1)
void  CLua::ExportFunctions(struct CLua::SFuncInfo *) {
  
  int result; // eax

  if ( !a1 && BBSupportDbgReport(2, "Script\\Lua.cpp", 280, "_pFuncInfo != NULL") == 1 )
    __debugbreak();
  result = 0;
  while ( *(_DWORD *)(a1 + 4) && *(_DWORD *)a1 )
  {
    result = CLua::ExportFunction(*(_DWORD *)(a1 + 4), *(char **)a1);
    a1 += 8;
  }
  return result;
}


// address=[0x1602c90]
// Decompiled from struct CLua::SFuncInfo *__thiscall CLua::ExportTableFunctions(CLua *this, const char *a2, struct CLua::SFuncInfo *a3)
void  CLua::ExportTableFunctions(char const *,struct CLua::SFuncInfo *) {
  
  struct CLua::SFuncInfo *result; // eax

  if ( !a2 && BBSupportDbgReport(2, "Script\\Lua.cpp", 303, "_pTableName != NULL") == 1 )
    __debugbreak();
  result = 0;
  if ( !a3 )
  {
    result = (struct CLua::SFuncInfo *)BBSupportDbgReport(2, "Script\\Lua.cpp", 304, "_pFuncInfo != NULL");
    if ( result == (struct CLua::SFuncInfo *)1 )
      __debugbreak();
  }
  while ( *((_DWORD *)a3 + 1) )
  {
    result = a3;
    if ( !*(_DWORD *)a3 )
      break;
    CLua::ExportTableFunction((int)a2, *((_DWORD *)a3 + 1), *(char **)a3);
    result = (struct CLua::SFuncInfo *)((char *)a3 + 8);
    a3 = (struct CLua::SFuncInfo *)((char *)a3 + 8);
  }
  return result;
}


// address=[0x1602d20]
// Decompiled from int __thiscall CLua::ExportTableVar(void **this, char *a2, char *Str, __int64 a4)
void  CLua::ExportTableVar(char const *,char const *,double) {
  
  int v6; // [esp+8h] [ebp-8h]
  int v7; // [esp+Ch] [ebp-4h]

  if ( !a2 && BBSupportDbgReport(2, "Script\\Lua.cpp", 323, "_pTableName != NULL") == 1 )
    __debugbreak();
  if ( !Str && BBSupportDbgReport(2, "Script\\Lua.cpp", 324, "_pVarName != NULL") == 1 )
    __debugbreak();
  lua_state = *this;
  j__lua_beginblock(this);
  v7 = j__lua_getglobal(a2);
  if ( j__lua_isnil(v7) )
  {
    v7 = j__lua_createtable();
    j__lua_pushobject(v7);
    j__lua_setglobal(a2);
  }
  if ( !j__lua_istable(v7) && BBSupportDbgReport(2, "Script\\Lua.cpp", 340, "lua_istable(TableObj)") == 1 )
    __debugbreak();
  j__lua_pushobject(v7);
  j__lua_pushstring(Str);
  j__lua_pushnumber(a4);
  j__lua_settable();
  return j__lua_endblock(v6);
}


// address=[0x1602e30]
// Decompiled from char *__thiscall CLua::ExportTableVars(CLua *this, char *a2, struct CLua::SVarInfo *a3)
void  CLua::ExportTableVars(char const *,struct CLua::SVarInfo *) {
  
  char *result; // eax

  if ( !a2 && BBSupportDbgReport(2, "Script\\Lua.cpp", 359, "_pTableName != NULL") == 1 )
    __debugbreak();
  result = 0;
  while ( *(_DWORD *)a3 )
  {
    CLua::ExportTableVar(a2, *(char **)a3, *((_QWORD *)a3 + 1));
    result = (char *)a3 + 16;
    a3 = (struct CLua::SVarInfo *)((char *)a3 + 16);
  }
  return result;
}


// address=[0x1602ea0]
// Decompiled from int __stdcall CLua::ExportTableTypes(char *a1, char *Str, int *a3, unsigned int a4)
void  CLua::ExportTableTypes(char const *,char const *,struct SConfigTypeString const *,unsigned int) {
  
  int result; // eax
  char *v5; // [esp+10h] [ebp-Ch]
  unsigned int i; // [esp+14h] [ebp-8h]
  int v7; // [esp+18h] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "Script\\Lua.cpp", 374, "_pTableName != 0") == 1 )
    __debugbreak();
  result = 0;
  v7 = 0;
  if ( Str )
  {
    result = j__strlen(Str);
    v7 = result;
  }
  for ( i = 0; i < a4; ++i )
  {
    v5 = (char *)a3[1];
    result = j__strlen(v5);
    if ( result > v7 )
      result = CLua::ExportTableVar(a1, &v5[v7], COERCE__INT64((double)*a3));
    a3 += 2;
  }
  return result;
}


// address=[0x1602f60]
// Decompiled from int __thiscall CLua::ExportGlobalVar(void **this, char *Str, __int64 a3)
void  CLua::ExportGlobalVar(char const *,double) {
  
  int result; // eax

  if ( !Str )
    return result;
  lua_state = *this;
  j__lua_pushnumber(a3);
  return j__lua_setglobal(Str);
}


// address=[0x1602fa0]
// Decompiled from int __cdecl CLua::Push(void **a1)
void __cdecl CLua::Push(enum EScriptType,...) {
  
  int result; // eax
  int v2; // [esp+10h] [ebp-20h]
  char v3; // [esp+14h] [ebp-1Ch] BYREF
  char *Str; // [esp+18h] [ebp-18h]
  int v5; // [esp+1Ch] [ebp-14h]
  float v6; // [esp+20h] [ebp-10h]
  int v7; // [esp+24h] [ebp-Ch]
  int v8; // [esp+28h] [ebp-8h]
  char *v9; // [esp+2Ch] [ebp-4h]

  lua_state = *a1;
  result = __vcrt_va_start_verify_argument_type<enum EScriptType>();
  v9 = &v3;
  while ( v2 != 6 )
  {
    v8 = v2;
    switch ( v2 )
    {
      case 0:
        v9 += 4;
        v7 = *((_DWORD *)v9 - 1);
        j__lua_pushnumber(COERCE__INT64((double)v7));
        break;
      case 1:
        v9 += 4;
        v6 = *((float *)v9 - 1);
        j__lua_pushnumber(COERCE__INT64(v6));
        break;
      case 2:
        v9 += 8;
        j__lua_pushnumber(*((_QWORD *)v9 - 1));
        break;
      case 3:
        v9 += 4;
        v5 = *((_DWORD *)v9 - 1);
        j__lua_pushusertag(v5, 0);
        break;
      case 4:
        v9 += 4;
        Str = (char *)*((_DWORD *)v9 - 1);
        j__lua_pushstring(Str);
        break;
      case 5:
        j__lua_pushnil();
        break;
      default:
        if ( BBSupportDbgReport(2, "Script\\Lua.cpp", 481, "false") == 1 )
          __debugbreak();
        break;
    }
    v9 += 4;
    result = *((_DWORD *)v9 - 1);
    v2 = result;
  }
  return result;
}


// address=[0x1603120]
// Decompiled from int __cdecl CLua::Get(void **a1)
void __cdecl CLua::Get(enum EScriptType,...) {
  
  int result; // eax
  double v2; // st7
  double v3; // st7
  double v4; // st7
  int v5; // eax
  const char *v6; // eax
  int v7; // [esp+0h] [ebp-2Ch]
  char v8; // [esp+4h] [ebp-28h] BYREF
  char *Destination; // [esp+8h] [ebp-24h]
  _DWORD *v10; // [esp+Ch] [ebp-20h]
  double *v11; // [esp+10h] [ebp-1Ch]
  float *v12; // [esp+14h] [ebp-18h]
  _DWORD *v13; // [esp+18h] [ebp-14h]
  int v14; // [esp+1Ch] [ebp-10h]
  int v15; // [esp+20h] [ebp-Ch]
  int v16; // [esp+24h] [ebp-8h]
  char *v17; // [esp+28h] [ebp-4h]

  lua_state = *a1;
  v15 = 1;
  result = __vcrt_va_start_verify_argument_type<enum EScriptType>();
  v17 = &v8;
  while ( v7 != 6 )
  {
    v16 = j__lua_lua2C(v15);
    if ( !v16 && BBSupportDbgReport(2, "Script\\Lua.cpp", 514, "Param != LUA_NOOBJECT") == 1 )
      __debugbreak();
    v14 = v7;
    switch ( v7 )
    {
      case 0:
        v17 += 4;
        v13 = (_DWORD *)*((_DWORD *)v17 - 1);
        v2 = j__lua_getnumber(v16);
        *v13 = (int)v2;
        break;
      case 1:
        v17 += 4;
        v12 = (float *)*((_DWORD *)v17 - 1);
        v3 = j__lua_getnumber(v16);
        *v12 = v3;
        break;
      case 2:
        v17 += 4;
        v11 = (double *)*((_DWORD *)v17 - 1);
        v4 = j__lua_getnumber(v16);
        *v11 = v4;
        break;
      case 3:
        v17 += 4;
        v10 = (_DWORD *)*((_DWORD *)v17 - 1);
        v5 = j__lua_getuserdata(v16);
        *v10 = v5;
        break;
      case 4:
        v17 += 4;
        Destination = (char *)*((_DWORD *)v17 - 1);
        v6 = (const char *)j__lua_getstring(v16);
        j__strcpy_0(Destination, v6);
        break;
      case 5:
        break;
      default:
        if ( BBSupportDbgReport(2, "Script\\Lua.cpp", 562, "false") == 1 )
          __debugbreak();
        break;
    }
    v17 += 4;
    result = *((_DWORD *)v17 - 1);
    v7 = result;
    ++v15;
  }
  return result;
}


// address=[0x16032e0]
// Decompiled from bool __thiscall CLua::EqualObjects(void **this, unsigned int a2, unsigned int a3)
bool  CLua::EqualObjects(unsigned int,unsigned int) {
  
  int v3; // eax
  int v5; // [esp-4h] [ebp-Ch]

  lua_state = *this;
  v5 = j__luaA_Address(a3);
  v3 = j__luaA_Address(a2);
  return j__luaO_equalval(v3, v5) != 0;
}


// address=[0x1603340]
// Decompiled from int __thiscall CLua::DbgDumpTable(void **this, char *Str)
void  CLua::DbgDumpTable(char const *) {
  
  int v3; // [esp+0h] [ebp-8h]
  int v4; // [esp+0h] [ebp-8h]

  lua_state = *this;
  j__lua_beginblock(v3);
  v4 = j__lua_getglobal(Str);
  if ( j__lua_istable(v4) )
  {
    CLua::s_pLua = (int)this;
    j__lua_pushobject(v4);
    j__lua_pushcclosure(CLua::scrDbgDumpTableEntry, 0);
    CLua::CallFunction(this, "foreach");
    CLua::s_pLua = 0;
  }
  else
  {
    BBSupportTracePrintF(0, "CLua::DbgDumpTableDbg(): Invalid table!");
  }
  return j__lua_endblock(v4);
}


// address=[0x16038c0]
// Decompiled from void __thiscall CLua::GetDouble(CLua *this, int a2)
double  CLua::GetDouble(int) {
  
  int v2; // eax

  lua_state = *(void **)this;
  CLua::dbgCheckParam(this, a2);
  v2 = j__lua_lua2C(a2);
  j__lua_getnumber(v2);
}


// address=[0x160d9a0]
// Decompiled from double __thiscall CLua::GetFloat(CLua *this, int a2)
float  CLua::GetFloat(int) {
  
  int v2; // eax

  lua_state = *(void **)this;
  CLua::dbgCheckParam(this, a2);
  v2 = j__lua_lua2C(a2);
  return (float)j__lua_getnumber(v2);
}


// address=[0x160da30]
// Decompiled from char *__thiscall CLua::GetString(CLua *this, int a2, int a3)
void  CLua::GetString(int,std::string &) {
  
  int v3; // eax
  char *result; // eax

  lua_state = *(void **)this;
  CLua::dbgCheckParam(this, a2);
  v3 = j__lua_lua2C(a2);
  result = (char *)j__lua_getstring(v3);
  if ( result )
    return (char *)std::string::operator+=(result);
  return result;
}


// address=[0x160db10]
// Decompiled from int __thiscall CLua::PushDouble(void **this, __int64 a2)
void  CLua::PushDouble(double) {
  
  lua_state = *this;
  return j__lua_pushnumber(a2);
}


// address=[0x160e270]
// Decompiled from bool __thiscall CLua::IsFunction(void **this, unsigned int a2)
bool  CLua::IsFunction(unsigned int) {
  
  lua_state = *this;
  return j__lua_isfunction(a2) != 0;
}


// address=[0x160e2c0]
// Decompiled from int __thiscall CLua::Lock(void **this, unsigned int a2)
int  CLua::Lock(unsigned int) {
  
  lua_state = *this;
  j__lua_pushobject(a2);
  return j__lua_ref(1);
}


// address=[0x16033d0]
// Decompiled from int __thiscall CLua::dbgCheckParam(void **this, int a2)
void  CLua::dbgCheckParam(int) {
  
  int v2; // eax
  int result; // eax
  int v4; // [esp+4h] [ebp-Ch]

  lua_state = *this;
  v4 = j__lua_lua2C(a2);
  v2 = j__lua_stackedfunction(1);
  result = j__lua_currentline(v2);
  if ( v4 )
    return result;
  if ( result == -1 )
    return BBSupportTracePrintF(0, "ScriptErr: Missing parameter (no debuginfo available)");
  else
    return BBSupportTracePrintF(0, "ScriptErr: Missing parameter %d at line %d", a2, result);
  return result;
}


// address=[0x1603450]
// Decompiled from int __usercall CLua::scrDbgDumpTableEntry@<eax>(double a1@<st0>)
static void __cdecl CLua::scrDbgDumpTableEntry(void) {
  
  char *Str; // [esp+14h] [ebp-4h]

  Str = (char *)CLua::GetString((CLua *)CLua::s_pLua, 1);
  CLua::GetDouble((CLua *)CLua::s_pLua, 2);
  j__strlen(Str);
  return BBSupportTracePrintF(0, "%s %f", Str, a1);
}


// address=[0x16034b0]
// Decompiled from void __cdecl CLua::scrIncTableEntryCount()
static void __cdecl CLua::scrIncTableEntryCount(void) {
  
  ++CLua::s_iTableEntryCount;
}


// address=[0x16034d0]
// Decompiled from int __thiscall CLua::CountTableEntries(void **this, char *Str)
int  CLua::CountTableEntries(char const *) {
  
  void **v3; // [esp+0h] [ebp-8h]
  int v4; // [esp+4h] [ebp-4h]

  lua_state = *this;
  j__lua_beginblock(this);
  CLua::s_iTableEntryCount = 0;
  v4 = j__lua_getglobal(Str);
  if ( j__lua_istable(v4) )
  {
    j__lua_pushobject(v4);
    j__lua_pushcclosure(CLua::scrIncTableEntryCount, 0);
    CLua::CallFunction(v3, "foreach");
  }
  j__lua_endblock(v3);
  return CLua::s_iTableEntryCount;
}


// address=[0x462b838]
// [Decompilation failed for static int CLua::s_iTableEntryCount]

// address=[0x462b83c]
// [Decompilation failed for static class CLua * CLua::s_pLua]

