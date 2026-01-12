#ifndef CGAMESCRIPTMANAGER_H
#define CGAMESCRIPTMANAGER_H

class CGameScriptManager : public IS4ChunkObject {
public:
    // address=[0x131ec80]
    class CLua &  GetScriptEnv(void);

    // address=[0x1439ca0]
    void  SendGameEvent(int,int);

    // address=[0x1470c10]
    void  SendGameEvent(int,int,int,int,int);

    // address=[0x147e750]
    void  SendGameEvent(int);

    // address=[0x147e7c0]
    void  SendGameEvent(int,int,int);

    // address=[0x147e840]
    void  SendGameEvent(int,int,int,int);

    // address=[0x14875a0]
    void  SetVictoryConditionHook(void (__cdecl*)(void));

    // address=[0x15feea0]
     CGameScriptManager(void);

    // address=[0x15fef60]
    virtual  ~CGameScriptManager(void);

    // address=[0x15fefe0]
    void  Update(unsigned int);

    // address=[0x15ff140]
    void  NewGame(char const *,unsigned int);

    // address=[0x15ff1f0]
    void  NewGameEx(char const *,unsigned int,wchar_t const *,bool);

    // address=[0x15ff6c0]
    virtual void  Load(class IS4Chunk &);

    // address=[0x15ff800]
    virtual void  Save(class IS4Chunk &);

    // address=[0x15ff890]
    void  StartScript(void);

    // address=[0x15ff960]
    void  CreateStartResources(int,int,int,int,int);

    // address=[0x15ffaf0]
    void  SetGlobal(char const *,int);

    // address=[0x16026c0]
    void  NewGame(class IScriptFile &);

    // address=[0x1602700]
    void  NewGame(void);

protected:
    // address=[0x15ffb30]
    bool  LoadMapScript(char const *,unsigned int);

    // address=[0x15ffc30]
    void  LoadState(class IS4Chunk &);

    // address=[0x15ffd30]
    void  SaveState(class IS4Chunk &);

    // address=[0x15ffe00]
    void  ExecuteScript(void);

    // address=[0x15ffe50]
    void  CallNewGame(void);

    // address=[0x15ffec0]
    void  CallRegisterFunctions(void);

    // address=[0x15fff50]
    void  InitScriptEnvironmentAndManager(void);

    // address=[0x1600110]
    void  UnrequestAllEvents(void);

    // address=[0x1600150]
    void  Done(void);

    // address=[0x1600230]
    void  SendGameEventCall(int);

    // address=[0x1600370]
    void  SendGameEventCall(int,int);

    // address=[0x16004b0]
    void  SendGameEventCall(int,int,int);

    // address=[0x16005f0]
    void  SendGameEventCall(int,int,int,int);

    // address=[0x1600730]
    void  SendGameEventCall(int,int,int,int,int);

    // address=[0x1600880]
    void  GetSaveVarValues(double *,int);

    // address=[0x1600970]
    void  SetSaveVarValues(double *,int);

    // address=[0x1600a60]
    void  RequestEvent(int,int);

    // address=[0x1600ab0]
    void  UnrequestEvent(int,int);

    // address=[0x1600b00]
    static void __cdecl LuaRequestEvent(void);

    // address=[0x1600bf0]
    static void __cdecl LuaRequestEvents(void);

    // address=[0x1600d20]
    static void __cdecl LuaUnrequestEvent(void);

    // address=[0x1600e10]
    static void __cdecl LuaUnrequestEvents(void);

    // address=[0x1600f40]
    static void __cdecl LuaErrorToTrace(void);

    // address=[0x1602590]
    class CScriptManager &  GetScriptManager(void);

private:
    // address=[0x462b824]
    static class CGameScriptManager * m_pGameScriptManager;

};


#endif // CGAMESCRIPTMANAGER_H
