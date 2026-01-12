#include "CGameScriptManager.h"

// Definitions for class CGameScriptManager

// address=[0x131ec80]
// Decompiled from int __thiscall CGameScriptManager::GetScriptEnv(CGameScriptManager *this)

class CLua &  CGameScriptManager::GetScriptEnv(void) {
  
  if ( !*((_DWORD *)this + 3)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Script\\GameScriptManager.h",
         161,
         "m_pScriptEnv != 0") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 3);
}


// address=[0x1439ca0]
// Decompiled from void __thiscall CGameScriptManager::SendGameEvent(CGameScriptManager *this, unsigned int a2, int a3)

void  CGameScriptManager::SendGameEvent(int,int) {
  
  if ( a2 >= 0x17
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Script\\GameScriptManager.h",
         269,
         (const char *)&dword_36A8410[1]) == 1 )
  {
    __debugbreak();
  }
  if ( (int)CScriptEventRequests::Size((CGameScriptManager *)((char *)this + 68 * a2 + 28)) > 0 )
    CGameScriptManager::SendGameEventCall(this, a2, a3);
}


// address=[0x1470c10]
// Decompiled from void __thiscall CGameScriptManager::SendGameEvent(
        CGameScriptManager *this,
        unsigned int a2,
        int a3,
        int a4,
        int a5,
        int a6)

void  CGameScriptManager::SendGameEvent(int,int,int,int,int) {
  
  if ( a2 >= 0x17
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Script\\GameScriptManager.h",
         299,
         (const char *)&dword_36A8410[1]) == 1 )
  {
    __debugbreak();
  }
  if ( (int)CScriptEventRequests::Size((CGameScriptManager *)((char *)this + 68 * a2 + 28)) > 0 )
    CGameScriptManager::SendGameEventCall(this, a2, a3, a4, a5, a6);
}


// address=[0x147e750]
// Decompiled from void __thiscall CGameScriptManager::SendGameEvent(CGameScriptManager *this, unsigned int a2)

void  CGameScriptManager::SendGameEvent(int) {
  
  if ( a2 >= 0x17
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Script\\GameScriptManager.h",
         259,
         (const char *)&dword_36A8410[1]) == 1 )
  {
    __debugbreak();
  }
  if ( (int)CScriptEventRequests::Size((CGameScriptManager *)((char *)this + 68 * a2 + 28)) > 0 )
    CGameScriptManager::SendGameEventCall(this, a2);
}


// address=[0x147e7c0]
// Decompiled from void __thiscall CGameScriptManager::SendGameEvent(CGameScriptManager *this, unsigned int a2, int a3, int a4)

void  CGameScriptManager::SendGameEvent(int,int,int) {
  
  if ( a2 >= 0x17
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Script\\GameScriptManager.h",
         279,
         (const char *)&dword_36A8410[1]) == 1 )
  {
    __debugbreak();
  }
  if ( (int)CScriptEventRequests::Size((CGameScriptManager *)((char *)this + 68 * a2 + 28)) > 0 )
    CGameScriptManager::SendGameEventCall(this, a2, a3, a4);
}


// address=[0x147e840]
// Decompiled from void __thiscall CGameScriptManager::SendGameEvent(CGameScriptManager *this, unsigned int a2, int a3, int a4, int a5)

void  CGameScriptManager::SendGameEvent(int,int,int,int) {
  
  if ( a2 >= 0x17
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Script\\GameScriptManager.h",
         289,
         (const char *)&dword_36A8410[1]) == 1 )
  {
    __debugbreak();
  }
  if ( (int)CScriptEventRequests::Size((CGameScriptManager *)((char *)this + 68 * a2 + 28)) > 0 )
    CGameScriptManager::SendGameEventCall(this, a2, a3, a4, a5);
}


// address=[0x14875a0]
// Decompiled from CGameScriptManager *__thiscall CGameScriptManager::SetVictoryConditionHook(
        CGameScriptManager *this,
        void (__cdecl *a2)())

void  CGameScriptManager::SetVictoryConditionHook(void (__cdecl*)(void)) {
  
  CGameScriptManager *result; // eax

  result = this;
  *((_DWORD *)this + 398) = a2;
  return result;
}


// address=[0x15feea0]
// Decompiled from CGameScriptManager *__thiscall CGameScriptManager::CGameScriptManager(CGameScriptManager *this)

 CGameScriptManager::CGameScriptManager(void) {
  
  IS4ChunkObject::IS4ChunkObject(this);
  *(_DWORD *)this = CGameScriptManager::_vftable_;
  `vector constructor iterator'(
    (char *)this + 28,
    0x44u,
    0x17u,
    (void *(__thiscall *)(void *))CScriptEventRequests::CScriptEventRequests);
  if ( CGameScriptManager::m_pGameScriptManager
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 234, "m_pGameScriptManager == 0") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 398) = 0;
  CGameScriptManager::m_pGameScriptManager = (int)this;
  CGameScriptManager::InitScriptEnvironmentAndManager(this);
  return this;
}


// address=[0x15fef60]
// Decompiled from void __thiscall CGameScriptManager::~CGameScriptManager(CGameScriptManager *this)

 CGameScriptManager::~CGameScriptManager(void) {
  
  *(_DWORD *)this = CGameScriptManager::_vftable_;
  if ( !CGameScriptManager::m_pGameScriptManager
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 263, "m_pGameScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  CGameScriptManager::Done(this);
  CGameScriptManager::m_pGameScriptManager = 0;
}


// address=[0x15fefe0]
// Decompiled from void __thiscall CGameScriptManager::Update(CGameScriptManager *this, unsigned int a2)

void  CGameScriptManager::Update(unsigned int) {
  
  if ( *((_DWORD *)this + 2) == 1 )
  {
    CGameScriptManager::SendGameEvent(this, 1u);
    CGameScriptManager::SendGameEvent(this, 2u);
    *((_DWORD *)this + 2) = 3;
  }
  else if ( *((_DWORD *)this + 2) == 2 )
  {
    CGameScriptManager::SendGameEvent(this, 2u);
    *((_DWORD *)this + 2) = 3;
  }
  else if ( *((_DWORD *)this + 2) != 3
         && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 594, "m_uStartOfGameState == 3") == 1 )
  {
    __debugbreak();
  }
  CGameScriptManager::SendGameEvent(this, 4u);
  if ( !(a2 % 5) )
    CGameScriptManager::SendGameEvent(this, 5u);
  if ( (a2 & 7) == 0 && a2 > 0x8C )
  {
    if ( !g_pGameData && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 606, "g_pGameData != 0") == 1 )
      __debugbreak();
    if ( !CGameData::IsGameWon(g_pGameData) )
    {
      if ( *((_DWORD *)this + 398) )
      {
        (*((void (**)(void))this + 398))();
      }
      else if ( CScriptEventRequests::Size((CGameScriptManager *)((char *)this + 232)) )
      {
        CGameScriptManager::SendGameEvent(this, 3u);
      }
      else
      {
        ScriptDefaultVictoryConditionCheck();
      }
    }
  }
}


// address=[0x15ff140]
// Decompiled from int __thiscall CGameScriptManager::NewGame(CGameScriptManager *this, void *Src, size_t Size)

void  CGameScriptManager::NewGame(char const *,unsigned int) {
  
  int result; // eax

  if ( *((_DWORD *)this + 1)
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 450, "m_uGameScriptState == 0") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 3) && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 452, "m_pScriptEnv != 0") == 1 )
    __debugbreak();
  if ( !*((_DWORD *)this + 4)
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 453, "m_pScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  CGameScriptManager::LoadMapScript(Src, Size);
  CGameScriptManager::UnrequestAllEvents(this);
  *((_DWORD *)this + 1) = 1;
  return result;
}


// address=[0x15ff1f0]
// Decompiled from void __thiscall CGameScriptManager::NewGameEx(
        CGameScriptManager *this,
        _BYTE *Src,
        unsigned int Size,
        wchar_t *Source,
        char a5)

void  CGameScriptManager::NewGameEx(char const *,unsigned int,wchar_t const *,bool) {
  
  wchar_t *v5; // eax
  const char *v6; // eax
  int v7; // [esp+0h] [ebp-6BCh] BYREF
  _BYTE v8[12]; // [esp+10h] [ebp-6ACh] BYREF
  int v9; // [esp+1Ch] [ebp-6A0h]
  int v10; // [esp+20h] [ebp-69Ch]
  int v11; // [esp+24h] [ebp-698h]
  int v12; // [esp+28h] [ebp-694h]
  int v13; // [esp+2Ch] [ebp-690h]
  wchar_t *v14; // [esp+30h] [ebp-68Ch]
  wchar_t *v15; // [esp+34h] [ebp-688h]
  CGameScriptManager *v16; // [esp+38h] [ebp-684h]
  unsigned int j; // [esp+3Ch] [ebp-680h]
  signed int v18; // [esp+40h] [ebp-67Ch]
  wchar_t *v19; // [esp+44h] [ebp-678h]
  _BYTE *v20; // [esp+48h] [ebp-674h]
  char v21; // [esp+4Fh] [ebp-66Dh]
  unsigned int i; // [esp+50h] [ebp-66Ch]
  _BYTE v23[28]; // [esp+54h] [ebp-668h] BYREF
  _BYTE v24[28]; // [esp+70h] [ebp-64Ch] BYREF
  _BYTE v25[28]; // [esp+8Ch] [ebp-630h] BYREF
  wchar_t Destination[512]; // [esp+A8h] [ebp-614h] BYREF
  wchar_t String[256]; // [esp+4A8h] [ebp-214h] BYREF
  int *v28; // [esp+6ACh] [ebp-10h]
  int v29; // [esp+6B8h] [ebp-4h]

  v28 = &v7;
  v16 = this;
  j__memset(String, 0, sizeof(String));
  j__wcscpy(String, L"Script\\");
  if ( Src && *Src && Size >= 2 )
  {
    v20 = Src;
    for ( i = Size; i && (unsigned __int8)v20[i - 1] <= 0x20u; --i )
      ;
    while ( i && (unsigned __int8)*v20 <= 0x20u )
    {
      ++v20;
      --i;
    }
    if ( i > 2 && *v20 == 36 && v20[i - 1] == 36 )
    {
      ++v20;
      i -= 2;
      if ( i < 0x40 && v20[i - 1] == 92 )
      {
        v15 = &String[j__wcslen(String)];
        for ( j = 0; j < i; ++j )
          v15[j] = (char)v20[j];
      }
      Src = 0;
      Size = 0;
    }
  }
  if ( !a5 && Src )
    goto LABEL_22;
  v21 = 0;
  if ( Source )
  {
    if ( *Source )
    {
      if ( j__wcslen(Source) < 0x400 )
      {
        j__wcscpy(Destination, Source);
        v19 = (wchar_t *)sub_1601260(Destination);
        if ( v19 )
        {
          v18 = j__wcslen(v19);
          if ( v18 > 4 && (!j___wcsicmp(L".edm", &v19[v18 - 4]) || !j___wcsicmp(L".map", &v19[v18 - 4])) )
          {
            v19[v18 - 3] = 116;
            v19[v18 - 2] = 120;
            v19[v18 - 1] = 116;
            v14 = v19;
            v13 = std::wstring::wstring(v23, v19);
            v11 = v13;
            v29 = 0;
            v12 = std::wstring::wstring(v24, String);
            v10 = v12;
            LOBYTE(v29) = 1;
            std::operator+<wchar_t>(v25, v12, v11);
            LOBYTE(v29) = 3;
            std::wstring::~wstring(v24);
            LOBYTE(v29) = 4;
            std::wstring::~wstring(v23);
            LOBYTE(v29) = 5;
            v5 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v25);
            v9 = CStdScriptFile::CStdScriptFile(v5);
            LOBYTE(v29) = 6;
            v6 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v25);
            ScriptTracePrintF(1u, "SCRIPT: \"%s\" loaded.", v6);
            v21 = 1;
            CGameScriptManager::NewGame(v16, (struct IScriptFile *)v8);
            LOBYTE(v29) = 5;
            CStdScriptFile::~CStdScriptFile((CStdScriptFile *)v8);
            v29 = -1;
            std::wstring::~wstring(v25);
          }
        }
      }
    }
  }
  if ( !v21 )
  {
    if ( Src )
    {
LABEL_22:
      CGameScriptManager::NewGame(Src, Size);
      return;
    }
    CGameScriptManager::NewGame(v16);
  }
}


// address=[0x15ff6c0]
// Decompiled from CGameScriptManager *__thiscall CGameScriptManager::Load(CGameScriptManager *this, struct IS4Chunk *a2)

void  CGameScriptManager::Load(class IS4Chunk &) {
  
  CGameScriptManager *result; // eax

  if ( *((_DWORD *)this + 1)
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 1200, "m_uGameScriptState == 0") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 3) && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 1202, "m_pScriptEnv != 0") == 1 )
    __debugbreak();
  if ( !*((_DWORD *)this + 4)
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 1203, "m_pScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 1093785866);
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  if ( *((_DWORD *)this + 6) )
  {
    *((_DWORD *)this + 5) = operator new[](*((_DWORD *)this + 6));
    (**(void (__thiscall ***)(struct IS4Chunk *, _DWORD, _DWORD))a2)(a2, *((_DWORD *)this + 5), *((_DWORD *)this + 6));
  }
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -254867929);
  CGameScriptManager::LoadState(this, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -999328080);
  result = this;
  *((_DWORD *)this + 1) = 2;
  return result;
}


// address=[0x15ff800]
// Decompiled from int __thiscall CGameScriptManager::Save(CGameScriptManager *this, struct IS4Chunk *a2)

void  CGameScriptManager::Save(class IS4Chunk &) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 1093785866);
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 6));
  if ( *((_DWORD *)this + 6) )
    (*(void (__thiscall **)(struct IS4Chunk *, _DWORD, _DWORD))(*(_DWORD *)a2 + 16))(
      a2,
      *((_DWORD *)this + 5),
      *((_DWORD *)this + 6));
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -254867929);
  CGameScriptManager::SaveState(this, a2);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -999328080);
}


// address=[0x15ff890]
// Decompiled from CGameScriptManager *__thiscall CGameScriptManager::StartScript(CGameScriptManager *this)

void  CGameScriptManager::StartScript(void) {
  
  CGameScriptManager *result; // eax

  if ( *((_DWORD *)this + 1) != 1
    && *((_DWORD *)this + 1) != 2
    && BBSupportDbgReport(
         2,
         "Script\\GameScriptManager.cpp",
         468,
         "(m_uGameScriptState == 1) || (m_uGameScriptState == 2)") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 3) && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 470, "m_pScriptEnv != 0") == 1 )
    __debugbreak();
  if ( !*((_DWORD *)this + 4)
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 471, "m_pScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)this + 5) )
  {
    CGameScriptManager::ExecuteScript(this);
    CGameScriptManager::CallRegisterFunctions(this);
    if ( *((_DWORD *)this + 1) == 1 )
      CGameScriptManager::CallNewGame(this);
  }
  *((_DWORD *)this + 2) = *((_DWORD *)this + 1);
  result = this;
  *((_DWORD *)this + 1) = 3;
  return result;
}


// address=[0x15ff960]
// Decompiled from int __thiscall CGameScriptManager::CreateStartResources(void ***this, int a2, int a3, int a4, int a5, int a6)

void  CGameScriptManager::CreateStartResources(int,int,int,int,int) {
  
  int result; // eax
  struct IScriptFile *v7; // [esp+18h] [ebp-24h]
  char *v8; // [esp+28h] [ebp-14h]

  if ( operator new(0xCu) )
    v7 = (struct IScriptFile *)CStdScriptFile::CStdScriptFile((wchar_t *)L"Script\\Internal\\StartResources.txt");
  else
    v7 = 0;
  v8 = 0;
  CLua::ExecuteScript(this[3], v7);
  CLua::PushInt(this[3], a3);
  CLua::PushInt(this[3], a4);
  CLua::PushInt(this[3], a5);
  CLua::PushInt(this[3], a6);
  switch ( a2 )
  {
    case 1:
      v8 = "CreateStartResourcesFew";
      break;
    case 2:
      v8 = "CreateStartResourcesMedium";
      break;
    case 3:
      v8 = "CreateStartResourcesMany";
      break;
    default:
      if ( !"GameScriptManager: Wrong amount of startresources!"
        && BBSupportDbgReport(
             2,
             "Script\\GameScriptManager.cpp",
             538,
             "\"GameScriptManager: Wrong amount of startresources!\"") == 1 )
      {
        __debugbreak();
      }
      break;
  }
  if ( v8 && !CLua::IsNil(this[3], v8) )
    CLua::CallFunction(this[3], v8);
  result = (int)v7;
  if ( v7 )
    return (**(int (__thiscall ***)(struct IScriptFile *, int))v7)(v7, 1);
  return result;
}


// address=[0x15ffaf0]
// Decompiled from int __thiscall CGameScriptManager::SetGlobal(CGameScriptManager *this, char *Str, int a3)

void  CGameScriptManager::SetGlobal(char const *,int) {
  
  void **ScriptEnv; // [esp+4h] [ebp-4h]

  ScriptEnv = (void **)CGameScriptManager::GetScriptEnv(this);
  CLua::PushInt(ScriptEnv, a3);
  return CLua::SetGlobal(Str);
}


// address=[0x16026c0]
// Decompiled from int __thiscall CGameScriptManager::NewGame(CGameScriptManager *this, struct IScriptFile *a2)

void  CGameScriptManager::NewGame(class IScriptFile &) {
  
  void *v2; // eax
  size_t v4; // [esp-4h] [ebp-8h]

  v4 = (*(int (__thiscall **)(struct IScriptFile *))(*(_DWORD *)a2 + 8))(a2);
  v2 = (void *)(*(int (__thiscall **)(struct IScriptFile *))(*(_DWORD *)a2 + 4))(a2);
  return CGameScriptManager::NewGame(v2, v4);
}


// address=[0x1602700]
// Decompiled from int __thiscall CGameScriptManager::NewGame(CGameScriptManager *this)

void  CGameScriptManager::NewGame(void) {
  
  return CGameScriptManager::NewGame(0, 0);
}


// address=[0x15ffb30]
// Decompiled from bool __thiscall CGameScriptManager::LoadMapScript(int this, void *Src, size_t Size)

bool  CGameScriptManager::LoadMapScript(char const *,unsigned int) {
  
  if ( *(_DWORD *)(this + 20)
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 362, "m_pMapScriptData == 0") == 1 )
  {
    __debugbreak();
  }
  if ( *(_DWORD *)(this + 24)
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 363, "m_uMapScriptSize == 0") == 1 )
  {
    __debugbreak();
  }
  if ( Src && Size )
  {
    *(_DWORD *)(this + 20) = operator new[](Size);
    *(_DWORD *)(this + 24) = Size;
    j__memcpy(*(void **)(this + 20), Src, Size);
    CLua::ExecuteScript(*(CLua **)(this + 12), *(void **)(this + 20), *(_DWORD *)(this + 24), 0);
  }
  else
  {
    *(_DWORD *)(this + 20) = 0;
    *(_DWORD *)(this + 24) = 0;
  }
  return *(_DWORD *)(this + 20) != 0;
}


// address=[0x15ffc30]
// Decompiled from int __thiscall CGameScriptManager::LoadState(CGameScriptManager *this, struct IS4Chunk *a2)

void  CGameScriptManager::LoadState(class IS4Chunk &) {
  
  int v3; // [esp+0h] [ebp-58h]
  int i; // [esp+8h] [ebp-50h]
  double v6[9]; // [esp+Ch] [ebp-4Ch] BYREF

  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -159512950);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 9, 9);
  (**(void (__thiscall ***)(struct IS4Chunk *, double *, int))a2)(a2, v6, 72);
  CGameScriptManager::SetSaveVarValues(this, v6, 9);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 2136404269);
  v3 = (*(int (__thiscall **)(struct IS4Chunk *, _DWORD, int))(*(_DWORD *)a2 + 4))(a2, 0, 23);
  for ( i = 0; i < v3; ++i )
    CScriptEventRequests::Load((CGameScriptManager *)((char *)this + 68 * i + 28), a2);
  while ( i < 23 )
    CScriptEventRequests::Clear((CGameScriptManager *)((char *)this + 68 * i++ + 28));
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1919979084);
}


// address=[0x15ffd30]
// Decompiled from int __thiscall CGameScriptManager::SaveState(CGameScriptManager *this, struct IS4Chunk *a2)

void  CGameScriptManager::SaveState(class IS4Chunk &) {
  
  int i; // [esp+4h] [ebp-50h]
  double v5[9]; // [esp+8h] [ebp-4Ch] BYREF

  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -159512950);
  CGameScriptManager::GetSaveVarValues(this, v5, 9);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 9);
  (*(void (__thiscall **)(struct IS4Chunk *, double *, int))(*(_DWORD *)a2 + 16))(a2, v5, 72);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 2136404269);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 23);
  for ( i = 0; i < 23; ++i )
    CScriptEventRequests::Save((CGameScriptManager *)((char *)this + 68 * i + 28), a2);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1919979084);
}


// address=[0x15ffe00]
// Decompiled from char __thiscall CGameScriptManager::ExecuteScript(CGameScriptManager *this)

void  CGameScriptManager::ExecuteScript(void) {
  
  char result; // al
  CLua *ScriptEnv; // [esp+0h] [ebp-8h]

  result = (char)this;
  if ( !*((_DWORD *)this + 5) )
    return result;
  if ( !*((_DWORD *)this + 6) )
    return result;
  ScriptEnv = CGameScriptManager::GetScriptEnv(this);
  return CLua::ExecuteScript(ScriptEnv, *((void **)this + 5), *((_DWORD *)this + 6), 0);
}


// address=[0x15ffe50]
// Decompiled from int __thiscall CGameScriptManager::CallNewGame(CGameScriptManager *this)

void  CGameScriptManager::CallNewGame(void) {
  
  void **ScriptEnv; // [esp+4h] [ebp-4h]

  ScriptEnv = (void **)CGameScriptManager::GetScriptEnv(this);
  if ( CLua::IsNil(ScriptEnv, "new_game") )
    return BBSupportTracePrintF(0, "SCRIPT: Warning: %s not found.", "new_game");
  ScriptTracePrintF(1u, "SCRIPT: Executing %s...", "new_game");
  return CLua::CallFunction(ScriptEnv, "new_game");
}


// address=[0x15ffec0]
// Decompiled from void __thiscall CGameScriptManager::CallRegisterFunctions(CGameScriptManager *this)

void  CGameScriptManager::CallRegisterFunctions(void) {
  
  CScriptManager *ScriptManager; // [esp+0h] [ebp-Ch]
  void **ScriptEnv; // [esp+4h] [ebp-8h]

  ScriptEnv = (void **)CGameScriptManager::GetScriptEnv(this);
  ScriptManager = CGameScriptManager::GetScriptManager(this);
  if ( CLua::IsNil(ScriptEnv, "register_functions") )
  {
    BBSupportTracePrintF(0, "SCRIPT: Warning: %s not found.", "register_functions");
  }
  else
  {
    ScriptTracePrintF(1u, "SCRIPT: Executing %s...", "register_functions");
    CScriptManager::AllowRegisterFunction(ScriptManager, 1);
    CLua::CallFunction(ScriptEnv, "register_functions");
    CScriptManager::AllowRegisterFunction(ScriptManager, 0);
  }
}


// address=[0x15fff50]
// Decompiled from void __thiscall CGameScriptManager::InitScriptEnvironmentAndManager(CGameScriptManager *this)

void  CGameScriptManager::InitScriptEnvironmentAndManager(void) {
  
  CScriptManager *v1; // [esp+Ch] [ebp-20h]
  CScriptManager *v2; // [esp+10h] [ebp-1Ch]
  CLua *v3; // [esp+14h] [ebp-18h]
  CLua *C; // [esp+18h] [ebp-14h]

  if ( *((_DWORD *)this + 3) && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 282, "m_pScriptEnv == 0") == 1 )
    __debugbreak();
  if ( *((_DWORD *)this + 4)
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 283, "m_pScriptManager == 0") == 1 )
  {
    __debugbreak();
  }
  C = (CLua *)operator new(4u);
  if ( C )
    v3 = CLua::CLua(C);
  else
    v3 = 0;
  *((_DWORD *)this + 3) = v3;
  v2 = (CScriptManager *)operator new(0x110u);
  if ( v2 )
    v1 = CScriptManager::CScriptManager(v2, *((struct CLua **)this + 3));
  else
    v1 = 0;
  *((_DWORD *)this + 4) = v1;
  CLua::ExportFunction((int)CGameScriptManager::LuaRequestEvent, "request_event");
  CLua::ExportFunction((int)CGameScriptManager::LuaRequestEvents, "request_events");
  CLua::ExportFunction((int)CGameScriptManager::LuaUnrequestEvent, "unrequest_event");
  CLua::ExportFunction((int)CGameScriptManager::LuaUnrequestEvents, "unrequest_events");
  CLua::ExportFunction((int)CGameScriptManager::LuaErrorToTrace, "_ERRORMESSAGE");
  CLua::CreateTable(off_3D8C0F8);
  ScriptExportVars(*((struct CLua **)this + 3));
  ScriptExportFunctions(*((struct CLua **)this + 3));
}


// address=[0x1600110]
// Decompiled from int __thiscall CGameScriptManager::UnrequestAllEvents(CGameScriptManager *this)

void  CGameScriptManager::UnrequestAllEvents(void) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 23; ++i )
  {
    CScriptEventRequests::Clear((CGameScriptManager *)((char *)this + 68 * i + 28));
    result = i + 1;
  }
  return result;
}


// address=[0x1600150]
// Decompiled from CGameScriptManager *__thiscall CGameScriptManager::Done(CGameScriptManager *this)

void  CGameScriptManager::Done(void) {
  
  CGameScriptManager *result; // eax
  CLua *v2; // [esp+14h] [ebp-Ch]
  void (__thiscall ***v3)(_DWORD, int); // [esp+18h] [ebp-8h]

  if ( *((_DWORD *)this + 4) )
  {
    v3 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this + 4);
    if ( v3 )
      (**v3)(v3, 1);
    *((_DWORD *)this + 4) = 0;
  }
  if ( *((_DWORD *)this + 3) )
  {
    v2 = (CLua *)*((_DWORD *)this + 3);
    if ( v2 )
      CLua::`scalar deleting destructor'(v2, 1u);
    *((_DWORD *)this + 3) = 0;
  }
  if ( *((_DWORD *)this + 5) )
  {
    operator delete[](*((void **)this + 5));
    *((_DWORD *)this + 5) = 0;
  }
  result = this;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 398) = 0;
  return result;
}


// address=[0x1600230]
// Decompiled from int __thiscall CGameScriptManager::SendGameEventCall(CGameScriptManager *this, unsigned int a2)

void  CGameScriptManager::SendGameEventCall(int) {
  
  int v3; // [esp+4h] [ebp-14h]
  int v4; // [esp+8h] [ebp-10h]
  int i; // [esp+10h] [ebp-8h]

  if ( a2 >= 0x17
    && BBSupportDbgReport(
         2,
         "Script\\GameScriptManager.cpp",
         633,
         "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 3) && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 635, "m_pScriptEnv != 0") == 1 )
    __debugbreak();
  if ( !*((_DWORD *)this + 4)
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 636, "m_pScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)this + 1) != 3
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 637, "m_uGameScriptState == 3") == 1 )
  {
    __debugbreak();
  }
  CLua::BeginBlock(*((void ***)this + 3));
  v4 = CScriptEventRequests::Size((CGameScriptManager *)((char *)this + 68 * a2 + 28));
  for ( i = 0; i < v4; ++i )
  {
    if ( CScriptEventRequests::operator[](i) != 255 )
    {
      v3 = CScriptEventRequests::operator[](i);
      CScriptManager::Call(*((CScriptManager **)this + 4), v3);
    }
  }
  return CLua::EndBlock(*((void ***)this + 3));
}


// address=[0x1600370]
// Decompiled from int __thiscall CGameScriptManager::SendGameEventCall(CGameScriptManager *this, unsigned int a2, int a3)

void  CGameScriptManager::SendGameEventCall(int,int) {
  
  int v3; // eax
  int v5; // [esp+8h] [ebp-10h]
  int i; // [esp+10h] [ebp-8h]

  if ( a2 >= 0x17
    && BBSupportDbgReport(
         2,
         "Script\\GameScriptManager.cpp",
         667,
         "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 3) && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 669, "m_pScriptEnv != 0") == 1 )
    __debugbreak();
  if ( !*((_DWORD *)this + 4)
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 670, "m_pScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)this + 1) != 3
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 671, "m_uGameScriptState == 3") == 1 )
  {
    __debugbreak();
  }
  CLua::BeginBlock(*((void ***)this + 3));
  v5 = CScriptEventRequests::Size((CGameScriptManager *)((char *)this + 68 * a2 + 28));
  for ( i = 0; i < v5; ++i )
  {
    if ( CScriptEventRequests::operator[](i) != 255 )
    {
      v3 = CScriptEventRequests::operator[](i);
      CScriptManager::Call(*((CScriptManager **)this + 4), v3, a3);
    }
  }
  return CLua::EndBlock(*((void ***)this + 3));
}


// address=[0x16004b0]
// Decompiled from int __thiscall CGameScriptManager::SendGameEventCall(CGameScriptManager *this, unsigned int a2, int a3, int a4)

void  CGameScriptManager::SendGameEventCall(int,int,int) {
  
  int v5; // [esp+4h] [ebp-14h]
  int v6; // [esp+8h] [ebp-10h]
  int i; // [esp+10h] [ebp-8h]

  if ( a2 >= 0x17
    && BBSupportDbgReport(
         2,
         "Script\\GameScriptManager.cpp",
         701,
         "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 3) && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 703, "m_pScriptEnv != 0") == 1 )
    __debugbreak();
  if ( !*((_DWORD *)this + 4)
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 704, "m_pScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)this + 1) != 3
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 705, "m_uGameScriptState == 3") == 1 )
  {
    __debugbreak();
  }
  CLua::BeginBlock(*((void ***)this + 3));
  v6 = CScriptEventRequests::Size((CGameScriptManager *)((char *)this + 68 * a2 + 28));
  for ( i = 0; i < v6; ++i )
  {
    if ( CScriptEventRequests::operator[](i) != 255 )
    {
      v5 = CScriptEventRequests::operator[](i);
      CScriptManager::Call(*((CScriptManager **)this + 4), v5, a3, a4);
    }
  }
  return CLua::EndBlock(*((void ***)this + 3));
}


// address=[0x16005f0]
// Decompiled from int __thiscall CGameScriptManager::SendGameEventCall(CGameScriptManager *this, unsigned int a2, int a3, int a4, int a5)

void  CGameScriptManager::SendGameEventCall(int,int,int,int) {
  
  int v6; // [esp+4h] [ebp-14h]
  int v7; // [esp+8h] [ebp-10h]
  int i; // [esp+10h] [ebp-8h]

  if ( a2 >= 0x17
    && BBSupportDbgReport(
         2,
         "Script\\GameScriptManager.cpp",
         735,
         "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 3) && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 737, "m_pScriptEnv != 0") == 1 )
    __debugbreak();
  if ( !*((_DWORD *)this + 4)
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 738, "m_pScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)this + 1) != 3
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 739, "m_uGameScriptState == 3") == 1 )
  {
    __debugbreak();
  }
  CLua::BeginBlock(*((void ***)this + 3));
  v7 = CScriptEventRequests::Size((CGameScriptManager *)((char *)this + 68 * a2 + 28));
  for ( i = 0; i < v7; ++i )
  {
    if ( CScriptEventRequests::operator[](i) != 255 )
    {
      v6 = CScriptEventRequests::operator[](i);
      CScriptManager::Call(*((CScriptManager **)this + 4), v6, a3, a4, a5);
    }
  }
  return CLua::EndBlock(*((void ***)this + 3));
}


// address=[0x1600730]
// Decompiled from int __thiscall CGameScriptManager::SendGameEventCall(
        CGameScriptManager *this,
        unsigned int a2,
        int a3,
        int a4,
        int a5,
        int a6)

void  CGameScriptManager::SendGameEventCall(int,int,int,int,int) {
  
  int v6; // eax
  int v8; // [esp+8h] [ebp-10h]
  int i; // [esp+10h] [ebp-8h]

  if ( a2 >= 0x17
    && BBSupportDbgReport(
         2,
         "Script\\GameScriptManager.cpp",
         769,
         "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 3) && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 771, "m_pScriptEnv != 0") == 1 )
    __debugbreak();
  if ( !*((_DWORD *)this + 4)
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 772, "m_pScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)this + 1) != 3
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 773, "m_uGameScriptState == 3") == 1 )
  {
    __debugbreak();
  }
  CLua::BeginBlock(*((void ***)this + 3));
  v8 = CScriptEventRequests::Size((CGameScriptManager *)((char *)this + 68 * a2 + 28));
  for ( i = 0; i < v8; ++i )
  {
    if ( CScriptEventRequests::operator[](i) != 255 )
    {
      v6 = CScriptEventRequests::operator[](i);
      CScriptManager::Call(*((CScriptManager **)this + 4), v6, a3, a4, a5, a6);
    }
  }
  return CLua::EndBlock(*((void ***)this + 3));
}


// address=[0x1600880]
// Decompiled from double *__thiscall CGameScriptManager::GetSaveVarValues(CGameScriptManager *this, double *a2, unsigned int a3)

void  CGameScriptManager::GetSaveVarValues(double *,int) {
  
  double *result; // eax
  double v4; // st7
  int v5; // [esp+0h] [ebp-28h]
  double *v6; // [esp+4h] [ebp-24h]
  void **ScriptEnv; // [esp+8h] [ebp-20h]
  signed int i; // [esp+10h] [ebp-18h]
  char Str[6]; // [esp+14h] [ebp-14h] BYREF
  int v11; // [esp+1Ah] [ebp-Eh]
  int v12; // [esp+1Eh] [ebp-Ah]
  __int16 v13; // [esp+22h] [ebp-6h]

  if ( a3 >= 0xA && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 1075, "(iSize >= 0) && (iSize <= 9)") == 1 )
    __debugbreak();
  strcpy(Str, "Save?");
  v11 = 0;
  v12 = 0;
  v13 = 0;
  ScriptEnv = (void **)CGameScriptManager::GetScriptEnv(this);
  result = (double *)CLua::GetGlobal(ScriptEnv, "Vars");
  v6 = result;
  for ( i = 0; i < (int)a3; ++i )
  {
    Str[4] = i + 49;
    j__lua_pushobject(v6);
    j__lua_pushstring(Str);
    v5 = j__lua_rawgettable(v5);
    v4 = j__lua_getnumber(v5);
    result = a2;
    a2[i] = v4;
  }
  return result;
}


// address=[0x1600970]
// Decompiled from int __thiscall CGameScriptManager::SetSaveVarValues(CGameScriptManager *this, double *a2, unsigned int a3)

void  CGameScriptManager::SetSaveVarValues(double *,int) {
  
  int result; // eax
  int v4; // [esp+8h] [ebp-24h]
  void **ScriptEnv; // [esp+Ch] [ebp-20h]
  signed int i; // [esp+14h] [ebp-18h]
  char Str[6]; // [esp+18h] [ebp-14h] BYREF
  int v9; // [esp+1Eh] [ebp-Eh]
  int v10; // [esp+22h] [ebp-Ah]
  __int16 v11; // [esp+26h] [ebp-6h]

  if ( a3 >= 0xA && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 1103, "(iSize >= 0) && (iSize <= 9)") == 1 )
    __debugbreak();
  strcpy(Str, "Save?");
  v9 = 0;
  v10 = 0;
  v11 = 0;
  ScriptEnv = (void **)CGameScriptManager::GetScriptEnv(this);
  result = CLua::GetGlobal(ScriptEnv, "Vars");
  v4 = result;
  for ( i = 0; i < (int)a3; ++i )
  {
    Str[4] = i + 49;
    j__lua_pushobject(v4);
    j__lua_pushstring(Str);
    j__lua_pushnumber(*(_QWORD *)&a2[i]);
    result = j__lua_rawsettable();
  }
  return result;
}


// address=[0x1600a60]
// Decompiled from // protected: void __thiscall CGameScriptManager::RequestEvent(int,int)
void __thiscall CGameScriptManager::RequestEvent(char *this, int a2, unsigned int a3)

void  CGameScriptManager::RequestEvent(int,int) {
  
  if ( a3 >= 0x17
    && BBSupportDbgReport(
         2,
         "Script\\GameScriptManager.cpp",
         803,
         "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1 )
  {
    __debugbreak();
  }
  CScriptEventRequests::AddFunction((CScriptEventRequests *)&this[68 * a3 + 28], a2);
}


// address=[0x1600ab0]
// Decompiled from // protected: void __thiscall CGameScriptManager::UnrequestEvent(int,int)
void __thiscall CGameScriptManager::UnrequestEvent(char *this, int a2, unsigned int a3)

void  CGameScriptManager::UnrequestEvent(int,int) {
  
  if ( a3 >= 0x17
    && BBSupportDbgReport(
         2,
         "Script\\GameScriptManager.cpp",
         815,
         "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1 )
  {
    __debugbreak();
  }
  CScriptEventRequests::RemoveFunction((CScriptEventRequests *)&this[68 * a3 + 28], a2);
}


// address=[0x1600b00]
// Decompiled from void CGameScriptManager::LuaRequestEvent()

static void __cdecl CGameScriptManager::LuaRequestEvent(void) {
  
  CScriptManager *ScriptManager; // [esp+0h] [ebp-1Ch]
  unsigned int Param; // [esp+4h] [ebp-18h]
  int Func; // [esp+8h] [ebp-14h]
  __int64 v3; // [esp+Ch] [ebp-10h]
  CLua *ScriptEnv; // [esp+14h] [ebp-8h]
  int Int; // [esp+18h] [ebp-4h]

  if ( !CGameScriptManager::m_pGameScriptManager
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 827, "m_pGameScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  ScriptEnv = CGameScriptManager::GetScriptEnv((CGameScriptManager *)CGameScriptManager::m_pGameScriptManager);
  ScriptManager = CGameScriptManager::GetScriptManager((CGameScriptManager *)CGameScriptManager::m_pGameScriptManager);
  Param = CLua::GetParam(ScriptEnv, 1);
  Func = CScriptManager::FindFunc(ScriptManager, Param);
  if ( Func == -1 )
  {
    ScriptTracePrintF(2u, "SCRIPT: request_event: Parameter 1 is not a registered function!");
  }
  else
  {
    Int = CLua::GetInt(ScriptEnv, 2);
    HIDWORD(v3) = Int <= 0;
    LODWORD(v3) = Int >= 23;
    if ( v3 )
      ScriptTracePrintF(2u, "SCRIPT: request_event: Invalid event type %i!", Int);
    else
      CScriptEventRequests::AddFunction(
        (CScriptEventRequests *)(CGameScriptManager::m_pGameScriptManager + 68 * Int + 28),
        Func);
  }
}


// address=[0x1600bf0]
// Decompiled from void CGameScriptManager::LuaRequestEvents()

static void __cdecl CGameScriptManager::LuaRequestEvents(void) {
  
  CScriptManager *ScriptManager; // [esp+0h] [ebp-20h]
  unsigned int Param; // [esp+4h] [ebp-1Ch]
  int Func; // [esp+8h] [ebp-18h]
  __int64 v3; // [esp+Ch] [ebp-14h]
  CLua *ScriptEnv; // [esp+14h] [ebp-Ch]
  int Int; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  if ( !CGameScriptManager::m_pGameScriptManager
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 862, "m_pGameScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  ScriptEnv = CGameScriptManager::GetScriptEnv((CGameScriptManager *)CGameScriptManager::m_pGameScriptManager);
  ScriptManager = CGameScriptManager::GetScriptManager((CGameScriptManager *)CGameScriptManager::m_pGameScriptManager);
  Param = CLua::GetParam(ScriptEnv, 1);
  Func = CScriptManager::FindFunc(ScriptManager, Param);
  if ( Func == -1 )
  {
    ScriptTracePrintF(2u, "SCRIPT: request_events: Parameter 1 is not a registered function!");
  }
  else
  {
    for ( i = 2; CLua::CheckParam((void **)ScriptEnv, i); ++i )
    {
      Int = CLua::GetInt(ScriptEnv, i);
      HIDWORD(v3) = Int <= 0;
      LODWORD(v3) = Int >= 23;
      if ( v3 )
        ScriptTracePrintF(2u, "SCRIPT: request_events: Parameter %i is an invalid event type %i!", i, Int);
      else
        CScriptEventRequests::AddFunction(
          (CScriptEventRequests *)(CGameScriptManager::m_pGameScriptManager + 68 * Int + 28),
          Func);
    }
  }
}


// address=[0x1600d20]
// Decompiled from void CGameScriptManager::LuaUnrequestEvent()

static void __cdecl CGameScriptManager::LuaUnrequestEvent(void) {
  
  CScriptManager *ScriptManager; // [esp+0h] [ebp-1Ch]
  unsigned int Param; // [esp+4h] [ebp-18h]
  int Func; // [esp+8h] [ebp-14h]
  __int64 v3; // [esp+Ch] [ebp-10h]
  CLua *ScriptEnv; // [esp+14h] [ebp-8h]
  int Int; // [esp+18h] [ebp-4h]

  if ( !CGameScriptManager::m_pGameScriptManager
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 904, "m_pGameScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  ScriptEnv = CGameScriptManager::GetScriptEnv((CGameScriptManager *)CGameScriptManager::m_pGameScriptManager);
  ScriptManager = CGameScriptManager::GetScriptManager((CGameScriptManager *)CGameScriptManager::m_pGameScriptManager);
  Param = CLua::GetParam(ScriptEnv, 1);
  Func = CScriptManager::FindFunc(ScriptManager, Param);
  if ( Func == -1 )
  {
    ScriptTracePrintF(2u, "SCRIPT: unrequest_event: Parameter 1 is not a registered function!");
  }
  else
  {
    Int = CLua::GetInt(ScriptEnv, 2);
    HIDWORD(v3) = Int <= 0;
    LODWORD(v3) = Int >= 23;
    if ( v3 )
      ScriptTracePrintF(2u, "SCRIPT: unrequest_event: Invalid event type %i!", Int);
    else
      CScriptEventRequests::RemoveFunction(
        (CScriptEventRequests *)(CGameScriptManager::m_pGameScriptManager + 68 * Int + 28),
        Func);
  }
}


// address=[0x1600e10]
// Decompiled from void CGameScriptManager::LuaUnrequestEvents()

static void __cdecl CGameScriptManager::LuaUnrequestEvents(void) {
  
  CScriptManager *ScriptManager; // [esp+0h] [ebp-20h]
  unsigned int Param; // [esp+4h] [ebp-1Ch]
  int Func; // [esp+8h] [ebp-18h]
  __int64 v3; // [esp+Ch] [ebp-14h]
  CLua *ScriptEnv; // [esp+14h] [ebp-Ch]
  int Int; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  if ( !CGameScriptManager::m_pGameScriptManager
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 939, "m_pGameScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  ScriptEnv = CGameScriptManager::GetScriptEnv((CGameScriptManager *)CGameScriptManager::m_pGameScriptManager);
  ScriptManager = CGameScriptManager::GetScriptManager((CGameScriptManager *)CGameScriptManager::m_pGameScriptManager);
  Param = CLua::GetParam(ScriptEnv, 1);
  Func = CScriptManager::FindFunc(ScriptManager, Param);
  if ( Func == -1 )
  {
    ScriptTracePrintF(2u, "SCRIPT: unrequest_events: Parameter 1 is not a registered function!");
  }
  else
  {
    for ( i = 2; CLua::CheckParam((void **)ScriptEnv, i); ++i )
    {
      Int = CLua::GetInt(ScriptEnv, i);
      HIDWORD(v3) = Int <= 0;
      LODWORD(v3) = Int >= 23;
      if ( v3 )
        ScriptTracePrintF(2u, "SCRIPT: unrequest_events: Parameter %i is an invalid event type %i!", i, Int);
      else
        CScriptEventRequests::RemoveFunction(
          (CScriptEventRequests *)(CGameScriptManager::m_pGameScriptManager + 68 * Int + 28),
          Func);
    }
  }
}


// address=[0x1600f40]
// Decompiled from void CGameScriptManager::LuaErrorToTrace()

static void __cdecl CGameScriptManager::LuaErrorToTrace(void) {
  
  const char *v0; // eax
  int v1; // [esp+4h] [ebp-474h] BYREF
  int CurrentLine; // [esp+8h] [ebp-470h]
  char *Source; // [esp+Ch] [ebp-46Ch]
  char *v4; // [esp+10h] [ebp-468h] BYREF
  char *Str; // [esp+14h] [ebp-464h] BYREF
  int v6; // [esp+18h] [ebp-460h]
  unsigned int j; // [esp+1Ch] [ebp-45Ch]
  int i; // [esp+20h] [ebp-458h]
  void **ScriptEnv; // [esp+24h] [ebp-454h]
  char v10; // [esp+2Bh] [ebp-44Dh]
  _BYTE v11[28]; // [esp+2Ch] [ebp-44Ch] BYREF
  char Destination[1024]; // [esp+48h] [ebp-430h] BYREF
  char Buffer[32]; // [esp+448h] [ebp-30h] BYREF
  int v14; // [esp+474h] [ebp-4h]

  if ( !CGameScriptManager::m_pGameScriptManager
    && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 987, "m_pGameScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  ScriptEnv = (void **)CGameScriptManager::GetScriptEnv((CGameScriptManager *)CGameScriptManager::m_pGameScriptManager);
  Source = (char *)CLua::GetString((CLua *)ScriptEnv, 1);
  j__memset(Destination, 0, sizeof(Destination));
  j__strncpy(Destination, Source, 0x3FFu);
  for ( i = 0; Destination[i]; ++i )
  {
    if ( (unsigned __int8)Destination[i] < 0x20u )
      Destination[i] = 32;
  }
  ScriptTracePrintF(2u, "SCRIPT: Error: %s", Destination);
  std::string::string();
  v14 = 0;
  v6 = 1;
  for ( j = CLua::GetStackedFunction(ScriptEnv, 1); j; j = CLua::GetStackedFunction(ScriptEnv, v6) )
  {
    v10 = 0;
    CLua::GetFuncInfo(ScriptEnv, j, &Str, &v1);
    CLua::GetObjName(ScriptEnv, j, &v4);
    if ( Str && *Str )
    {
      std::string::operator+=(Str);
      v10 = 1;
    }
    if ( v4 && *v4 )
    {
      if ( v10 )
        std::string::operator+=(",");
      std::string::operator+=(v4);
      std::string::operator+=("()");
      v10 = 1;
    }
    CurrentLine = CLua::GetCurrentLine(ScriptEnv, j);
    if ( v10 )
      std::string::operator+=(",");
    j___snprintf(Buffer, 0x1Fu, "%u", CurrentLine);
    std::string::operator+=(Buffer);
    std::string::operator+=(" ");
    ++v6;
  }
  if ( std::string::length(v11) )
  {
    v0 = (const char *)std::string::c_str(v11);
    ScriptTracePrintF(2u, "SCRIPT: Callstack: %s", v0);
  }
  v14 = -1;
  std::string::~string(v11);
}


// address=[0x1602590]
// Decompiled from int __thiscall CGameScriptManager::GetScriptManager(CGameScriptManager *this)

class CScriptManager &  CGameScriptManager::GetScriptManager(void) {
  
  if ( !*((_DWORD *)this + 4)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\GameScriptManager.h",
         190,
         "m_pScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 4);
}


// address=[0x462b824]
// [Decompilation failed for static class CGameScriptManager * CGameScriptManager::m_pGameScriptManager]

