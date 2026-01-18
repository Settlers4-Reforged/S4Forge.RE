#ifndef CLUA_H
#define CLUA_H

#include "defines.h"

class CLua {
public:
    // address=[0x131eb90]
    struct lua_State *  ActivateScriptingEnvironment(void);

    // address=[0x1601e20]
    void  BeginBlock(void);

    // address=[0x1602150]
    void  CallFunction(unsigned int a2);

    // address=[0x16021c0]
    void  CallFunction(char const * Str);

    // address=[0x1602280]
    bool  CheckParam(int a2);

    // address=[0x1602310]
    void  CreateTable(char const * Str);

    // address=[0x1602380]
    void  EndBlock(void);

    // address=[0x16023b0]
    int  GetCurrentLine(unsigned int a2);

    // address=[0x16023e0]
    void  GetFuncInfo(unsigned int a2, char * * a3, int * a4);

    // address=[0x1602420]
    unsigned int  GetGlobal(char const * Str);

    // address=[0x1602480]
    int  GetInt(int a2);

    // address=[0x16024e0]
    char *  GetObjName(unsigned int a2, char * * a3);

    // address=[0x1602520]
    unsigned int  GetParam(int a2);

    // address=[0x1602560]
    unsigned int  GetRef(int a2);

    // address=[0x16025e0]
    unsigned int  GetStackedFunction(int a2);

    // address=[0x1602610]
    char *  GetString(int a2);

    // address=[0x1602660]
    bool  IsNil(char const * Str);

    // address=[0x1602720]
    void  PushInt(int a2);

    // address=[0x1602760]
    void  SetGlobal(char const * Str);

    // address=[0x16027c0]
     CLua(void);

    // address=[0x1602800]
     ~CLua(void);

    // address=[0x1602830]
    bool  ExecuteScript(wchar_t const * FileName);

    // address=[0x1602a30]
    bool  ExecuteScript(class IScriptFile & a2);

    // address=[0x1602aa0]
    bool  ExecuteScript(void * a2, int a3, char * a4);

    // address=[0x1602ae0]
    bool  ExecuteString(char const * Str);

    // address=[0x1602b20]
    void  ExportFunction(void (__cdecl*)(void) a2, char const * Str);

    // address=[0x1602b60]
    void  ExportTableFunction(char const * a2, void (__cdecl*)(void) a3, char const * Str);

    // address=[0x1602c20]
    void  ExportFunctions(struct CLua::SFuncInfo * a1);

    // address=[0x1602c90]
    void  ExportTableFunctions(char const * a2, struct CLua::SFuncInfo * a3);

    // address=[0x1602d20]
    void  ExportTableVar(char const * a2, char const * Str, double a4);

    // address=[0x1602e30]
    void  ExportTableVars(char const * a2, struct CLua::SVarInfo * a3);

    // address=[0x1602ea0]
    void  ExportTableTypes(char const * a1, char const * Str, struct SConfigTypeString const * a3, unsigned int a4);

    // address=[0x1602f60]
    void  ExportGlobalVar(char const * Str, double a3);

    // address=[0x1602fa0]
    void __cdecl Push(enum EScriptType a1, ... a2);

    // address=[0x1603120]
    void __cdecl Get(enum EScriptType a1, ... a2);

    // address=[0x16032e0]
    bool  EqualObjects(unsigned int a2, unsigned int a3);

    // address=[0x1603340]
    void  DbgDumpTable(char const * Str);

    // address=[0x16038c0]
    double  GetDouble(int a2);

    // address=[0x160d9a0]
    float  GetFloat(int a2);

    // address=[0x160da30]
    void  GetString(int a2, std::string & a3);

    // address=[0x160db10]
    void  PushDouble(double a2);

    // address=[0x160e270]
    bool  IsFunction(unsigned int a2);

    // address=[0x160e2c0]
    int  Lock(unsigned int a2);

private:
    // address=[0x16033d0]
    void  dbgCheckParam(int a2);

    // address=[0x1603450]
    static void __cdecl scrDbgDumpTableEntry(void a1);

    // address=[0x16034b0]
    static void __cdecl scrIncTableEntryCount(void);

    // address=[0x16034d0]
    int  CountTableEntries(char const * Str);

    // address=[0x462b838]
    static int s_iTableEntryCount;

    // address=[0x462b83c]
    static class CLua * s_pLua;

};


#endif // CLUA_H
