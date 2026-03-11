#include "CLua.h"

#include <cstdarg>

#include "lua/lua.h"
#include "lua/luadebug.h"
#include "lua/lualib.h"

#include "CBB/CBBSupport.h"
#include "../File/CFileEx.h"
#include "IScriptFile.h"

// Definitions for class CLua

// address=[0x131eb90]
// Decompiled from void *__thiscall CLua::ActivateScriptingEnvironment(CLua *this)
struct lua_State *CLua::ActivateScriptingEnvironment(void)
{
  ::lua_state = this->state;
  return lua_state;
}

// address=[0x1601e20]
// Decompiled from int __thiscall CLua::BeginBlock(void **this)
void CLua::BeginBlock(void)
{
  ::lua_state = this->state;
  lua_beginblock();
}

// address=[0x1602150]
// Decompiled from int __thiscall CLua::CallFunction(void **this, unsigned int a2)
void CLua::CallFunction(unsigned int a2)
{
  ::lua_state = this->state;
  if (!lua_isfunction(a2) && BBSupportDbgReport(
                                 2,
                                 "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\Lua.h",
                                 407,
                                 "lua_isfunction(_FuncObj)") == 1)
  {
    __debugbreak();
  }
  lua_callfunction(a2);
}

// address=[0x16021c0]
// Decompiled from int __thiscall CLua::CallFunction(void **this, char *Str)
void CLua::CallFunction(char const *Str)
{

  int result; // eax
  int v3;     // [esp+4h] [ebp-4h]

  if (Str)
  {
    ::lua_state = this->state;
    v3 = lua_getglobal((char *)Str);
    if (lua_isfunction(v3))
    {
      lua_callfunction(v3);
    }
    else
    {
      if (BBSupportDbgReportF(
              1,
              "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\Lua.h",
              429,
              "CLua::CallFunction(): Function \"%s\" not found [may be ignored]!",
              Str) == 1)
        __debugbreak();
    }
  }
  else
  {
    result = BBSupportDbgReport(
        1,
        "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\Lua.h",
        434,
        "CLua::CallFunction(): Invalid function name [may be ignored]!");
    if (result == 1)
      __debugbreak();
  }
}

// address=[0x1602280]
// Decompiled from bool __thiscall CLua::CheckParam(void **this, int a2)
bool CLua::CheckParam(int a2)
{
  ::lua_state = this->state;
  return lua_lua2C(a2) != 0;
}

// address=[0x1602310]
// Decompiled from int __thiscall CLua::CreateTable(void **this, char *Str)
void CLua::CreateTable(char const *Str)
{

  int v2; // eax

  if (!Str && BBSupportDbgReport(
                  2,
                  "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\Lua.h",
                  444,
                  "_pName != NULL") == 1)
  {
    __debugbreak();
  }
  ::lua_state = this->state;
  v2 = lua_createtable();
  lua_pushobject(v2);
  lua_setglobal((char *)Str);
}

// address=[0x1602380]
// Decompiled from int __thiscall CLua::EndBlock(void **this)
void CLua::EndBlock(void)
{

  ::lua_state = this->state;
  lua_endblock();
}

// address=[0x16023b0]
// Decompiled from int __thiscall CLua::GetCurrentLine(void **this, unsigned int a2)
int CLua::GetCurrentLine(unsigned int a2)
{

  ::lua_state = this->state;
  lua_currentline(a2);
}

// address=[0x16023e0]
// Decompiled from int __thiscall CLua::GetFuncInfo(void **this, unsigned int a2, char **a3, int *a4)
void CLua::GetFuncInfo(unsigned int a2, char **a3, int *a4)
{

  ::lua_state = this->state;
  lua_funcinfo(a2, a3, a4);
}

// address=[0x1602420]
// Decompiled from int __thiscall CLua::GetGlobal(void **this, char *Str)
unsigned int CLua::GetGlobal(char const *Str)
{

  if (!Str && BBSupportDbgReport(
                  2,
                  "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\Lua.h",
                  614,
                  "_pName != NULL") == 1)
  {
    __debugbreak();
  }
  ::lua_state = this->state;
  lua_getglobal((char *)Str);
}

// address=[0x1602480]
// Decompiled from int __thiscall CLua::GetInt(CLua *this, int a2)
int CLua::GetInt(int a2)
{

  int v2; // eax

  ::lua_state = this->state;
  this->dbgCheckParam(a2);
  v2 = lua_lua2C(a2);
  return (int)lua_getnumber(v2);
}

// address=[0x16024e0]
// Decompiled from int __thiscall CLua::GetObjName(void **this, unsigned int a2, char **a3)
char *CLua::GetObjName(unsigned int a2, char **a3)
{
  ::lua_state = this->state;
  return lua_getobjname(a2, a3);
}

// address=[0x1602520]
// Decompiled from int __thiscall CLua::GetParam(CLua *this, int a2)
unsigned int CLua::GetParam(int a2)
{

  ::lua_state = this->state;
  this->dbgCheckParam(a2);
  return lua_lua2C(a2);
}

// address=[0x1602560]
// Decompiled from int __thiscall CLua::GetRef(void **this, int a2)
unsigned int CLua::GetRef(int a2)
{

  ::lua_state = this->state;
  return lua_getref(a2);
}

// address=[0x16025e0]
// Decompiled from int __thiscall CLua::GetStackedFunction(void **this, int a2)
unsigned int CLua::GetStackedFunction(int a2)
{

  ::lua_state = this->state;
  return lua_stackedfunction(a2);
}

// address=[0x1602610]
// Decompiled from int __thiscall CLua::GetString(CLua *this, int a2)
char *CLua::GetString(int a2)
{

  int v2; // eax

  ::lua_state = this->state;
  this->dbgCheckParam(a2);
  v2 = lua_lua2C(a2);
  return lua_getstring(v2);
}

// address=[0x1602660]
// Decompiled from bool __thiscall CLua::IsNil(void **this, char *Str)
bool CLua::IsNil(char const *Str)
{

  int v3; // [esp+0h] [ebp-Ch]

  ::lua_state = this->state;
  v3 = lua_getglobal((char *)Str);
  return lua_isnil(v3) != 0;
}

// address=[0x1602720]
// Decompiled from int __thiscall CLua::PushInt(void **this, int a2)
void CLua::PushInt(int a2)
{

  ::lua_state = this->state;
  lua_pushnumber((float)a2);
}

// address=[0x1602760]
// Decompiled from int __thiscall CLua::SetGlobal(void **this, char *Str)
void CLua::SetGlobal(char const *Str)
{

  if (!Str && BBSupportDbgReport(
                  2,
                  "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\Lua.h",
                  624,
                  "_pName != NULL") == 1)
  {
    __debugbreak();
  }
  ::lua_state = this->state;
  lua_setglobal((char *)Str);
}

// address=[0x16027c0]
// Decompiled from CLua *__thiscall CLua::CLua(CLua *this)
CLua::CLua(void)
{

  ::lua_state = 0;
  lua_open();
  lua_iolibopen();
  lua_strlibopen();
  lua_setdebug(1);
  this->state = ::lua_state;
}

// address=[0x1602800]
// Decompiled from int __thiscall CLua::~CLua(void **this)
CLua::~CLua(void)
{

  int result; // eax

  ::lua_state = this->state;
  lua_close();
  ::lua_state = 0;
}

// address=[0x1602830]
// Decompiled from char __thiscall CLua::ExecuteScript(void **this, wchar_t *FileName)
bool CLua::ExecuteScript(wchar_t const *FileName)
{

  int v3;             // [esp+0h] [ebp-B4h] BYREF
  void *C;            // [esp+10h] [ebp-A4h]
  void *v5;           // [esp+14h] [ebp-A0h]
  void *v6;           // [esp+18h] [ebp-9Ch]
  size_t v7;          // [esp+1Ch] [ebp-98h]
  BOOL v9;            // [esp+24h] [ebp-90h]
  char *Buffer;       // [esp+28h] [ebp-8Ch]
  size_t uScriptSize; // [esp+2Ch] [ebp-88h]
  char v12;           // [esp+32h] [ebp-82h]
  char v13;           // [esp+33h] [ebp-81h]
  _DWORD v15[3];      // [esp+9Ch] [ebp-18h] BYREF
  int v16;            // [esp+B0h] [ebp-4h]

  if (!FileName || !*FileName)
    return 0;

  bool bSucceeded = true;

  ::lua_state = this->state;
  uScriptSize = 0;
  Buffer = 0;

  CFileEx v14{};
  v14.Open(FileName, CFile::CFile_BINARY | CFile::CFile_READ, 0, CFileLog);
  uScriptSize = v14.Size();
  if (uScriptSize)
  {
    Buffer = new char[uScriptSize + 8];
    v14.Read(
        Buffer,
        1,
        uScriptSize,
        CFileLog);
  }

  v14.Close(CFileLog);
  if (Buffer)
  {
    bSucceeded = lua_dobuffer(Buffer, uScriptSize, 0) == 0;
    delete[] Buffer;
  }

  return bSucceeded;
}

// address=[0x1602a30]
// Decompiled from bool __thiscall CLua::ExecuteScript(void **this, struct IScriptFile *a2)
bool CLua::ExecuteScript(class IScriptFile &_rScriptFile)
{
  const char *spFile; // eax
  int iSize;          // [esp-8h] [ebp-10h]

  ::lua_state = this->state;
  if (!_rScriptFile.GetScript())
    return 0;
  iSize = _rScriptFile.GetSize();
  spFile = _rScriptFile.GetScript();
  return lua_dobuffer((char *)spFile, iSize, 0) == 0;
}

// address=[0x1602aa0]
// Decompiled from bool __thiscall CLua::ExecuteScript(CLua *this, void *a2, int a3, char *a4)
bool CLua::ExecuteScript(void *a2, int a3, char *a4)
{
  return lua_dobuffer((char *)a2, a3, a4) == 0;
}

// address=[0x1602ae0]
// Decompiled from bool __thiscall CLua::ExecuteString(void **this, char *Str)
bool CLua::ExecuteString(char const *Str)
{
  ::lua_state = this->state;
  return lua_dostring((char *)Str) == 0;
}

// address=[0x1602b20]
// Decompiled from int __thiscall CLua::ExportFunction(void **this, int a2, char *Str)
void CLua::ExportFunction(void(__cdecl *a2)(void), char const *Str)
{
  ::lua_state = this->state;
  lua_pushcclosure(a2, 0);
  return lua_setglobal((char *)Str);
}

// address=[0x1602b60]
// Decompiled from int __thiscall CLua::ExportTableFunction(void **this, char *a2, int a3, char *Str)
void CLua::ExportTableFunction(char const *a2, void(__cdecl *a3)(void), char const *Str)
{
  int v5; // [esp+0h] [ebp-8h]
  int v6; // [esp+4h] [ebp-4h]

  ::lua_state = this->state;
  lua_beginblock();
  v6 = lua_getglobal((char *)a2);
  if (lua_isnil(v6))
  {
    v6 = lua_createtable();
    lua_pushobject(v6);
    lua_setglobal((char *)a2);
  }
  if (!lua_istable(v6) && BBSupportDbgReport(2, "Script\\Lua.cpp", 253, "lua_istable(TableObj)") == 1)
    __debugbreak();
  lua_pushobject(v6);
  lua_pushstring((char *)Str);
  lua_pushcclosure(a3, 0);
  lua_settable();
  return lua_endblock();
}

// address=[0x1602c20]
// Decompiled from int __stdcall CLua::ExportFunctions(int a1)
void CLua::ExportFunctions(CLua::SFuncInfo *a1)
{
  if (!a1 && BBSupportDbgReport(2, "Script\\Lua.cpp", 280, "_pFuncInfo != NULL") == 1)
    __debugbreak();
  while (a1->m_fpFunction && a1->m_swpName)
  {
    this->ExportFunction(a1->m_fpFunction, a1->m_swpName);
    ++a1;
  }
}

// address=[0x1602c90]
// Decompiled from struct CLua::SFuncInfo *__thiscall CLua::ExportTableFunctions(CLua *this, const char *a2, struct CLua::SFuncInfo *a3)
void CLua::ExportTableFunctions(char const *a2, struct CLua::SFuncInfo *a3)
{
  if (!a2 && BBSupportDbgReport(2, "Script\\Lua.cpp", 303, "_pTableName != NULL") == 1)
    __debugbreak();
  if (!a3 && BBSupportDbgReport(2, "Script\\Lua.cpp", 304, "_pFuncInfo != NULL") == 1)
    __debugbreak();
  while (a3->m_fpFunction && a3->m_swpName)
  {
    CLua::ExportTableFunction(a2, a3->m_fpFunction, a3->m_swpName);
    ++a3;
  }
}

// address=[0x1602d20]
// Decompiled from int __thiscall CLua::ExportTableVar(void **this, char *a2, char *Str, __int64 a4)
void CLua::ExportTableVar(const char *_pTableName, const char *_pVarName, double _dVar)
{
  int TableObj; // [esp+Ch] [ebp-4h]

  if (!_pTableName && BBSupportDbgReport(2, "Script\\Lua.cpp", 323, "_pTableName != NULL") == 1)
    __debugbreak();
  if (!_pVarName && BBSupportDbgReport(2, "Script\\Lua.cpp", 324, "_pVarName != NULL") == 1)
    __debugbreak();
  lua_state = this->state;
  lua_beginblock();
  TableObj = lua_getglobal((char *)_pTableName);
  if (lua_isnil(TableObj))
  {
    TableObj = lua_createtable();
    lua_pushobject(TableObj);
    lua_setglobal((char *)_pTableName);
  }
  if (!lua_istable(TableObj) && BBSupportDbgReport(2, "Script\\Lua.cpp", 340, "lua_istable(TableObj)") == 1)
    __debugbreak();
  lua_pushobject(TableObj);
  lua_pushstring((char *)_pVarName);
  lua_pushnumber(_dVar);
  lua_settable();
  return lua_endblock();
}

// address=[0x1602e30]
// Decompiled from char *__thiscall CLua::ExportTableVars(CLua *this, char *a2, struct CLua::SVarInfo *a3)
void CLua::ExportTableVars(char const *_pTableName, struct CLua::SVarInfo *a3)
{
  if (!_pTableName && BBSupportDbgReport(2, "Script\\Lua.cpp", 359, "_pTableName != NULL") == 1)
    __debugbreak();
  while (a3->m_swpName)
  {
    CLua::ExportTableVar(_pTableName, (char *)a3->m_swpName, a3->m_dDefault);
    ++a3;
  }
}

// address=[0x1602ea0]
// Decompiled from int __stdcall CLua::ExportTableTypes(char *a1, char *Str, int *a3, unsigned int a4)
void CLua::ExportTableTypes(const char *_pTableName,
                            const char *_pDefinePrefix,
                            const struct SConfigTypeString *a4,
                            unsigned int _uCount)
{
  char *m_sName;            // [esp+10h] [ebp-Ch]
  unsigned int i;           // [esp+14h] [ebp-8h]
  signed int uPrefixLength; // [esp+18h] [ebp-4h]

  if (!_pTableName && BBSupportDbgReport(2, "Script\\Lua.cpp", 374, "_pTableName != 0") == 1)
    __debugbreak();
  uPrefixLength = 0;
  if (_pDefinePrefix)
    uPrefixLength = strlen(_pDefinePrefix);
  for (i = 0; i < _uCount; ++i)
  {
    m_sName = (char *)a4->m_sName;
    if ((int)strlen(m_sName) > uPrefixLength)
      CLua::ExportTableVar((char *)_pTableName, &m_sName[uPrefixLength], (double)a4->m_iNr);
    ++a4;
  }
}

// address=[0x1602f60]
// Decompiled from int __thiscall CLua::ExportGlobalVar(void **this, char *Str, __int64 a3)
void CLua::ExportGlobalVar(char const *Str, double a3)
{

  int result; // eax

  if (!Str)
    return;
  lua_state = this->state;
  lua_pushnumber(a3);
  lua_setglobal((char *)Str);
}

// address=[0x1602fa0]
// Decompiled from int __cdecl CLua::Push(void **a1)
void __cdecl CLua::Push(enum EScriptType a1, ...)
{
  lua_state = this->state;

  std::va_list args;
  va_start(args, a1);

  EScriptType type = va_arg(args, EScriptType);
  while (type != ESCRIPT_TYPE_END)
  {
    switch (type)
    {
    case ESCRIPT_TYPE_INT:
      lua_pushnumber((double)va_arg(args, int));
      break;
    case ESCRIPT_TYPE_FLOAT:
      lua_pushnumber((double)va_arg(args, float));
      break;
    case ESCRIPT_TYPE_DOUBLE:
      lua_pushnumber(va_arg(args, double));
      break;
    case ESCRIPT_TYPE_USERDATA:
      lua_pushusertag(va_arg(args, void *), 0);
      break;
    case ESCRIPT_TYPE_STRING:
      lua_pushstring((char *)va_arg(args, const char *));
      break;
    case ESCRIPT_TYPE_NIL:
      lua_pushnil();
      break;
    default:
      if (BBSupportDbgReport(2, "Script\\Lua.cpp", 481, "false") == 1)
        __debugbreak();
      break;
    }
  }

  va_end(args);
}

// address=[0x1603120]
// Decompiled from int __cdecl CLua::Get(void **a1)
void __cdecl CLua::Get(enum EScriptType a1, ...)
{
  ::lua_state = this->state;

  std::va_list args;
  va_start(args, a1);

  int index = 1;

  EScriptType type = va_arg(args, EScriptType);
  while (type != ESCRIPT_TYPE_END)
  {
    lua_Object Param = lua_lua2C(index);
    if (!Param && BBSupportDbgReport(2, "Script\\Lua.cpp", 514, "Param != LUA_NOOBJECT") == 1)
      __debugbreak();

    switch (type)
    {
    case ESCRIPT_TYPE_INT:
      *va_arg(args, int *) = (int)lua_getnumber(Param);
      break;
    case ESCRIPT_TYPE_FLOAT:
      *va_arg(args, float *) = (float)lua_getnumber(Param);
      break;
    case ESCRIPT_TYPE_DOUBLE:
      *va_arg(args, double *) = lua_getnumber(Param);
      break;
    case ESCRIPT_TYPE_USERDATA:
      *va_arg(args, void **) = lua_getuserdata(Param);
      break;
    case ESCRIPT_TYPE_STRING:
      char *value = lua_getstring(Param);
      strcpy(va_arg(args, char *), value);
      break;
    case ESCRIPT_TYPE_NIL:
      break;
    default:
      if (BBSupportDbgReport(2, "Script\\Lua.cpp", 562, "false") == 1)
        __debugbreak();
      break;
    }

    ++index;
  }

  va_end(args);
}

struct TObject *luaA_Address(lua_Object o);
int luaO_equalval(struct TObject *t1, struct TObject *t2);

// address=[0x16032e0]
// Decompiled from bool __thiscall CLua::EqualObjects(void **this, unsigned int a2, unsigned int a3)
bool CLua::EqualObjects(unsigned int a2, unsigned int a3)
{
  struct TObject *v3; // eax
  struct TObject *v5; // [esp-4h] [ebp-Ch]

  lua_state = this->state;
  v5 = luaA_Address(a3);
  v3 = luaA_Address(a2);
  return luaO_equalval(v3, v5) != 0;
}

// address=[0x1603340]
// Decompiled from int __thiscall CLua::DbgDumpTable(void **this, char *Str)
void CLua::DbgDumpTable(char const *Str)
{

  int v3; // [esp+0h] [ebp-8h]
  int v4; // [esp+0h] [ebp-8h]

  lua_state = this->state;
  lua_beginblock();
  v4 = lua_getglobal((char *)Str);
  if (lua_istable(v4))
  {
    CLua::s_pLua = this;
    lua_pushobject(v4);
    lua_pushcclosure(CLua::scrDbgDumpTableEntry, 0);
    this->CallFunction("foreach");
    CLua::s_pLua = 0;
  }
  else
  {
    BBSupportTracePrintF(0, "CLua::DbgDumpTableDbg(): Invalid table!");
  }

  lua_endblock();
}

// address=[0x16038c0]
// Decompiled from void __thiscall CLua::GetDouble(CLua *this, int a2)
double CLua::GetDouble(int a2)
{

  int v2; // eax

  lua_state = this->state;
  this->dbgCheckParam(a2);
  v2 = lua_lua2C(a2);
  lua_getnumber(v2);
}

// address=[0x160d9a0]
// Decompiled from double __thiscall CLua::GetFloat(CLua *this, int a2)
float CLua::GetFloat(int a2)
{

  int v2; // eax

  lua_state = this->state;
  this->dbgCheckParam(a2);
  v2 = lua_lua2C(a2);
  return (float)lua_getnumber(v2);
}

// address=[0x160da30]
// Decompiled from char *__thiscall CLua::GetString(CLua *this, int a2, int a3)
void CLua::GetString(int a2, std::string &a3)
{

  int v3;       // eax
  char *result; // eax

  lua_state = this->state;
  this->dbgCheckParam(a2);
  v3 = lua_lua2C(a2);
  result = (char *)lua_getstring(v3);
  if (result)
    a3 += result;
}

// address=[0x160db10]
// Decompiled from int __thiscall CLua::PushDouble(void **this, __int64 a2)
void CLua::PushDouble(double a2)
{

  lua_state = this->state;
  return lua_pushnumber(a2);
}

// address=[0x160e270]
// Decompiled from bool __thiscall CLua::IsFunction(void **this, unsigned int a2)
bool CLua::IsFunction(unsigned int a2)
{

  lua_state = this->state;
  return lua_isfunction(a2) != 0;
}

// address=[0x160e2c0]
// Decompiled from int __thiscall CLua::Lock(void **this, unsigned int a2)
int CLua::Lock(unsigned int a2)
{

  lua_state = this->state;
  lua_pushobject(a2);
  return lua_ref(1);
}

// address=[0x16033d0]
// Decompiled from int __thiscall CLua::dbgCheckParam(void **this, int a2)
void CLua::dbgCheckParam(int a2)
{

  int v2;     // eax
  int result; // eax
  int v4;     // [esp+4h] [ebp-Ch]

  lua_state = this->state;
  v4 = lua_lua2C(a2);
  v2 = lua_stackedfunction(1);
  result = lua_currentline(v2);
  if (v4)
    return;

  if (result == -1)
    BBSupportTracePrintF(0, "ScriptErr: Missing parameter (no debuginfo available)");
  else
    BBSupportTracePrintF(0, "ScriptErr: Missing parameter %d at line %d", a2, result);
}

// address=[0x1603450]
// Decompiled from int __usercall CLua::scrDbgDumpTableEntry@<eax>(double a1@<st0>)
void __cdecl CLua::scrDbgDumpTableEntry(void)
{
  char *Str; // [esp+14h] [ebp-4h]
  Str = (char *)s_pLua->CLua::GetString(1);
  s_pLua->GetDouble(2);
  strlen(Str);
  return BBSupportTracePrintF(0, "%s %f", Str);
}

// address=[0x16034b0]
// Decompiled from void __cdecl CLua::scrIncTableEntryCount()
void __cdecl CLua::scrIncTableEntryCount(void)
{
  ++CLua::s_iTableEntryCount;
}

// address=[0x16034d0]
// Decompiled from int __thiscall CLua::CountTableEntries(void **this, char *Str)
int CLua::CountTableEntries(char const *Str)
{

  void **v3; // [esp+0h] [ebp-8h]
  int v4;    // [esp+4h] [ebp-4h]

  lua_state = this->state;
  lua_beginblock();
  CLua::s_iTableEntryCount = 0;
  v4 = lua_getglobal((char*)Str);
  if (lua_istable(v4))
  {
    lua_pushobject(v4);
    lua_pushcclosure(CLua::scrIncTableEntryCount, 0);
    this->CallFunction("foreach");
  }
  lua_endblock();
  return CLua::s_iTableEntryCount;
}

// address=[0x462b838]
// [Decompilation failed for static int CLua::s_iTableEntryCount]

// address=[0x462b83c]
// [Decompilation failed for static class CLua * CLua::s_pLua]
