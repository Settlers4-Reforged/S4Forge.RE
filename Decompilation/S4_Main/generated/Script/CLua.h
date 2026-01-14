#ifndef CLUA_H
#define CLUA_H

class CLua {
public:
    // address=[0x131eb90]
    struct lua_State *  ActivateScriptingEnvironment(void);

    // address=[0x1601e20]
    void  BeginBlock(void);

    // address=[0x1602150]
    void  CallFunction(unsigned int);

    // address=[0x16021c0]
    void  CallFunction(char const *);

    // address=[0x1602280]
    bool  CheckParam(int);

    // address=[0x1602310]
    void  CreateTable(char const *);

    // address=[0x1602380]
    void  EndBlock(void);

    // address=[0x16023b0]
    int  GetCurrentLine(unsigned int);

    // address=[0x16023e0]
    void  GetFuncInfo(unsigned int,char * *,int *);

    // address=[0x1602420]
    unsigned int  GetGlobal(char const *);

    // address=[0x1602480]
    int  GetInt(int);

    // address=[0x16024e0]
    char *  GetObjName(unsigned int,char * *);

    // address=[0x1602520]
    unsigned int  GetParam(int);

    // address=[0x1602560]
    unsigned int  GetRef(int);

    // address=[0x16025e0]
    unsigned int  GetStackedFunction(int);

    // address=[0x1602610]
    char *  GetString(int);

    // address=[0x1602660]
    bool  IsNil(char const *);

    // address=[0x1602720]
    void  PushInt(int);

    // address=[0x1602760]
    void  SetGlobal(char const *);

    // address=[0x16027c0]
     CLua(void);

    // address=[0x1602800]
     ~CLua(void);

    // address=[0x1602830]
    bool  ExecuteScript(wchar_t const *);

    // address=[0x1602a30]
    bool  ExecuteScript(class IScriptFile &);

    // address=[0x1602aa0]
    bool  ExecuteScript(void *,int,char *);

    // address=[0x1602ae0]
    bool  ExecuteString(char const *);

    // address=[0x1602b20]
    void  ExportFunction(void (__cdecl*)(void),char const *);

    // address=[0x1602b60]
    void  ExportTableFunction(char const *,void (__cdecl*)(void),char const *);

    // address=[0x1602c20]
    void  ExportFunctions(struct CLua::SFuncInfo *);

    // address=[0x1602c90]
    void  ExportTableFunctions(char const *,struct CLua::SFuncInfo *);

    // address=[0x1602d20]
    void  ExportTableVar(char const *,char const *,double);

    // address=[0x1602e30]
    void  ExportTableVars(char const *,struct CLua::SVarInfo *);

    // address=[0x1602ea0]
    void  ExportTableTypes(char const *,char const *,struct SConfigTypeString const *,unsigned int);

    // address=[0x1602f60]
    void  ExportGlobalVar(char const *,double);

    // address=[0x1602fa0]
    void __cdecl Push(enum EScriptType,...);

    // address=[0x1603120]
    void __cdecl Get(enum EScriptType,...);

    // address=[0x16032e0]
    bool  EqualObjects(unsigned int,unsigned int);

    // address=[0x1603340]
    void  DbgDumpTable(char const *);

    // address=[0x16038c0]
    double  GetDouble(int);

    // address=[0x160d9a0]
    float  GetFloat(int);

    // address=[0x160da30]
    void  GetString(int,std::string &);

    // address=[0x160db10]
    void  PushDouble(double);

    // address=[0x160e270]
    bool  IsFunction(unsigned int);

    // address=[0x160e2c0]
    int  Lock(unsigned int);

private:
    // address=[0x16033d0]
    void  dbgCheckParam(int);

    // address=[0x1603450]
    static void __cdecl scrDbgDumpTableEntry(void);

    // address=[0x16034b0]
    static void __cdecl scrIncTableEntryCount(void);

    // address=[0x16034d0]
    int  CountTableEntries(char const *);

    // address=[0x462b838]
    static int s_iTableEntryCount;

    // address=[0x462b83c]
    static class CLua * s_pLua;

};


#endif // CLUA_H
