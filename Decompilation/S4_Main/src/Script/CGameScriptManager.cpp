#include "CGameScriptManager.h"

#include "CBB/CBBSupport.h"

#include "CLua.h"
#include "CScriptEventRequests.h"
#include "CScriptManager.h"
#include "CStdScriptFile.h"

#include "Scripts/LuaExports.h"

#include "lua/lua.h"
#include "lua/luadebug.h"
#include "lua/lualib.h"

// Definitions for class CGameScriptManager

CGameScriptManager  s_ScriptMgr{};
CGameScriptManager *g_pScriptMgr = &s_ScriptMgr;

// address=[0x131ec80]
// Decompiled from CLua *__thiscall CGameScriptManager::GetScriptEnv(CGameScriptManager *this)
class CLua &CGameScriptManager::GetScriptEnv(void) {
  if(!this->m_pScriptEnv && BBSupportDbgReport(
       2,
       "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Script\\GameScriptManager.h",
       161,
       "m_pScriptEnv != 0") == 1) {
    __debugbreak();
  }
  return *this->m_pScriptEnv;
}

// address=[0x1439ca0]
// Decompiled from void __thiscall CGameScriptManager::SendGameEvent(CGameScriptManager *this, unsigned int a2, int a3)
void CGameScriptManager::SendGameEvent(int a2, int a3) {
  if(a2 >= 0x17 && BBSupportDbgReport(
       2,
       "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Script\\GameScriptManager.h",
       269,
       "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1) {
    __debugbreak();
  }
  if(this->m_aScriptEventRequests[a2].Size() > 0)
    this->SendGameEventCall(a2, a3);
}

// address=[0x1470c10]
// Decompiled from void __thiscall CGameScriptManager::SendGameEvent(  CGameScriptManager *this,  unsigned int a2,  int a3,  int a4,  int a5,  int a6)
void CGameScriptManager::SendGameEvent(int a2, int a3, int a4, int a5, int a6) {
  if(a2 >= 0x17 && BBSupportDbgReport(
       2,
       "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Script\\GameScriptManager.h",
       299,
       "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1) {
    __debugbreak();
  }
  if(this->m_aScriptEventRequests[a2].Size() > 0)
    this->SendGameEventCall(a2, a3, a4, a5, a6);
}

// address=[0x147e750]
// Decompiled from void __thiscall CGameScriptManager::SendGameEvent(CGameScriptManager *this, unsigned int a2)
void CGameScriptManager::SendGameEvent(int a2) {
  if(a2 >= 0x17 && BBSupportDbgReport(
       2,
       "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Script\\GameScriptManager.h",
       259,
       "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1) {
    __debugbreak();
  }
  if(this->m_aScriptEventRequests[a2].Size() > 0)
    this->SendGameEventCall(a2);
}

// address=[0x147e7c0]
// Decompiled from void __thiscall CGameScriptManager::SendGameEvent(CGameScriptManager *this, unsigned int a2, int a3, int a4)
void CGameScriptManager::SendGameEvent(int a2, int a3, int a4) {
  if(a2 >= 0x17 && BBSupportDbgReport(
       2,
       "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Script\\GameScriptManager.h",
       279,
       "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1) {
    __debugbreak();
  }
  if(this->m_aScriptEventRequests[a2].Size() > 0)
    this->SendGameEventCall(a2, a3, a4);
}

// address=[0x147e840]
// Decompiled from void __thiscall CGameScriptManager::SendGameEvent(CGameScriptManager *this, unsigned int a2, int a3, int a4, int a5)
void CGameScriptManager::SendGameEvent(int a2, int a3, int a4, int a5) {
  if(a2 >= 0x17 && BBSupportDbgReport(
       2,
       "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Script\\GameScriptManager.h",
       289,
       "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1) {
    __debugbreak();
  }
  if(this->m_aScriptEventRequests[a2].Size() > 0)
    this->SendGameEventCall(a2, a3, a4, a5);
}

// address=[0x14875a0]
// Decompiled from void __thiscall CGameScriptManager::SetVictoryConditionHook(CGameScriptManager *this, void (__cdecl *a2)())
void CGameScriptManager::SetVictoryConditionHook(void (__cdecl *a2)(void)) {
  this->m_pVictoryConditionHook = a2;
}

// address=[0x15feea0]
// Decompiled from CGameScriptManager *__thiscall CGameScriptManager::CGameScriptManager(CGameScriptManager *this)
CGameScriptManager::CGameScriptManager(void) : m_aScriptEventRequests{} {
  if(CGameScriptManager::m_pGameScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 234, "m_pGameScriptManager == 0") == 1) {
    __debugbreak();
  }
  this->m_pScriptEnv = 0;
  this->m_pScriptManager = 0;
  this->m_pMapScriptData = 0;
  this->m_uMapScriptSize = 0;
  this->m_uGameScriptState = 0;
  this->m_uStartOfGameState = 0;
  this->m_pVictoryConditionHook = 0;
  CGameScriptManager::m_pGameScriptManager = this;
  this->InitScriptEnvironmentAndManager();
}

// address=[0x15fef60]
// Decompiled from void __thiscall CGameScriptManager::~CGameScriptManager(CGameScriptManager *this)
CGameScriptManager::~CGameScriptManager(void) {
  if(!CGameScriptManager::m_pGameScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 263, "m_pGameScriptManager != 0") == 1) {
    __debugbreak();
  }
  this->Done();
  CGameScriptManager::m_pGameScriptManager = 0;
}

// address=[0x15fefe0]
// Decompiled from void __thiscall CGameScriptManager::Update(CGameScriptManager *this, unsigned int a2)
void CGameScriptManager::Update(unsigned int a2) {
  if(this->m_uStartOfGameState == 1) {
    this->SendGameEvent(1u);
    this->SendGameEvent(2u);
    this->m_uStartOfGameState = 3;
  } else if(this->m_uStartOfGameState == 2) {
    this->SendGameEvent(2u);
    this->m_uStartOfGameState = 3;
  } else if(this->m_uStartOfGameState != 3 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 594, "m_uStartOfGameState == 3") == 1) {
    __debugbreak();
  }
  this->SendGameEvent(4u);
  if(!(a2 % 5))
    this->SendGameEvent(5u);
  if((a2 & 7) == 0 && a2 > 0x8C) {
    if(!g_pGameData && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 606, "g_pGameData != 0") == 1)
      __debugbreak();
    if(!g_pGameData->IsGameWon()) {
      if(this->m_pVictoryConditionHook) {
        this->m_pVictoryConditionHook();
      } else if(this->m_aScriptEventRequests[3].Size()) {
        this->SendGameEvent(3u);
      } else {
        ScriptDefaultVictoryConditionCheck();
      }
    }
  }
}

// address=[0x15ff140]
// Decompiled from int __thiscall CGameScriptManager::NewGame(CGameScriptManager *this, void *Src, size_t Size)
void CGameScriptManager::NewGame(char const *Src, unsigned int Size) {
  if(this->m_uGameScriptState && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 450, "m_uGameScriptState == 0") == 1) {
    __debugbreak();
  }
  if(!this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 452, "m_pScriptEnv != 0") == 1)
    __debugbreak();
  if(!this->m_pScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 453, "m_pScriptManager != 0") == 1) {
    __debugbreak();
  }
  CGameScriptManager::LoadMapScript(Src, Size);
  this->UnrequestAllEvents();
  this->m_uGameScriptState = 1;
}

// address=[0x1601260]
wchar_t *__cdecl GetFileNameFromPath(wchar_t *path) {
  int last_separator_index; // index of last '/' or '\'
  int current_index;        // iterator through string

  if(!path)
    return 0;

  current_index = 0;
  last_separator_index = 0;

  while(path[current_index]) {
    if(path[current_index] == '\\' || path[current_index] == '/')
      last_separator_index = current_index;

    ++current_index;
  }

  // slash is the last character: no filename
  if(last_separator_index >= current_index - 1)
    return 0;

  // return pointer to filename after last slash
  if(last_separator_index)
    return &path[last_separator_index + 1];

  // no slash found, whole string is filename
  return path;
}

// address=[0x15ff1f0]
// Decompiled from void __thiscall CGameScriptManager::NewGameEx(  CGameScriptManager *this,  _BYTE *Src,  size_t Size,  wchar_t *Source,  char a5)
void CGameScriptManager::NewGameEx(char const *Src, unsigned int Size, wchar_t const *Source, bool a5) {
  wchar_t *     v5;                // eax
  wchar_t *     v6;                // eax
  int           v7;                     // [esp+0h] [ebp-6BCh] BYREF
  void *        v10;                  // [esp+20h] [ebp-69Ch]
  std::wstring *v11;          // [esp+24h] [ebp-698h]
  void *        v12;                  // [esp+28h] [ebp-694h]
  std::wstring *v13;          // [esp+2Ch] [ebp-690h]
  wchar_t *     v14;               // [esp+30h] [ebp-68Ch]
  wchar_t *     spScriptPathSrc;   // [esp+34h] [ebp-688h]
  size_t        j;                   // [esp+3Ch] [ebp-680h]
  signed int    uFileNameLength; // [esp+40h] [ebp-67Ch]
  wchar_t *     spFileName;        // [esp+44h] [ebp-678h]
  _BYTE *       spTrimmedSrc;        // [esp+48h] [ebp-674h]
  char          bFoundScript;          // [esp+4Fh] [ebp-66Dh]
  size_t        i;                   // [esp+50h] [ebp-66Ch]
  std::wstring  v23;           // [esp+54h] [ebp-668h] BYREF
  std::wstring  v24;           // [esp+70h] [ebp-64Ch] BYREF
  std::wstring  v25;           // [esp+8Ch] [ebp-630h] BYREF
  wchar_t       Destination[512];   // [esp+A8h] [ebp-614h] BYREF
  wchar_t       sScriptPath[256];   // [esp+4A8h] [ebp-214h] BYREF
  int *         v28;                   // [esp+6ACh] [ebp-10h]
  int           v29;                    // [esp+6B8h] [ebp-4h]

  v28 = &v7;
  memset(sScriptPath, 0, sizeof(sScriptPath));
  wcscpy(sScriptPath, L"Script\\");
  if(Src && *Src && Size >= 2) {
    spTrimmedSrc = (unsigned char *) Src;

    // Trim whitespace from the end and start of the script data, then check if it starts and ends with '$' and if the length is less than 64. If so, copy it to sScriptPath.
    for(i = Size; i && spTrimmedSrc[i - 1] <= ' '; --i);
    while(i && *spTrimmedSrc <= ' ') {
      ++spTrimmedSrc;
      --i;
    }
    if(i > 2 && *spTrimmedSrc == '$' && spTrimmedSrc[i - 1] == '$') {
      ++spTrimmedSrc;
      i -= 2;
      if(i < 64 && spTrimmedSrc[i - 1] == '\\') {
        spScriptPathSrc = &sScriptPath[wcslen(sScriptPath)];
        for(j = 0; j < i; ++j)
          spScriptPathSrc[j] = (char) spTrimmedSrc[j];
      }
      Src = 0;
      Size = 0;
    }
  }

  if(!a5 && Src)
    goto LABEL_22;
  bFoundScript = 0;
  if(Source) {
    if(*Source) {
      if(wcslen(Source) < 0x400) {
        wcscpy(Destination, Source);
        spFileName = GetFileNameFromPath(Destination);
        if(spFileName) {
          uFileNameLength = wcslen(spFileName);
          if(uFileNameLength > 4 && (!wcsicmp(L".edm", &spFileName[uFileNameLength - 4]) || !wcsicmp(L".map", &spFileName[uFileNameLength - 4]))) {
            spFileName[uFileNameLength - 3] = 't';
            spFileName[uFileNameLength - 2] = 'x';
            spFileName[uFileNameLength - 1] = 't';
            std::wstring   swFullPath = (std::wstring(sScriptPath) + std::wstring(spFileName));
            CStdScriptFile v8 = CStdScriptFile(swFullPath.c_str());
            ScriptTracePrintF(1u, "SCRIPT: \"%s\" loaded.", swFullPath.c_str());
            bFoundScript = 1;
            this->NewGame(v8);
          }
        }
      }
    }
  }
  if(!bFoundScript) {
    if(Src) {
    LABEL_22:
      this->NewGame(Src, Size);
      return;
    }
    this->NewGame();
  }
}

// address=[0x15ff6c0]
// Decompiled from void __thiscall CGameScriptManager::Load(CGameScriptManager *this, struct IS4Chunk *a2)
void CGameScriptManager::Load(class IS4Chunk &a2) {
  if(this->m_uGameScriptState && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 1200, "m_uGameScriptState == 0") == 1) {
    __debugbreak();
  }
  if(!this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 1202, "m_pScriptEnv != 0") == 1)
    __debugbreak();
  if(!this->m_pScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 1203, "m_pScriptManager != 0") == 1) {
    __debugbreak();
  }
  a2.LoadSignature(1093785866);
  this->m_pMapScriptData = 0;
  this->m_uMapScriptSize = a2.LoadUnsigned32();
  if(this->m_uMapScriptSize) {
    this->m_pMapScriptData = new char[this->m_uMapScriptSize];
    a2.Load(this->m_pMapScriptData, this->m_uMapScriptSize);
  }
  a2.LoadSignature(-254867929);
  this->LoadState(a2);
  a2.LoadSignature(-999328080);
  this->m_uGameScriptState = 2;
}

// address=[0x15ff800]
// Decompiled from void __thiscall CGameScriptManager::Save(CGameScriptManager *this, struct IS4Chunk *a2)
void CGameScriptManager::Save(class IS4Chunk &a2) {
  a2.SaveSignature(1093785866);
  a2.SaveUnsigned32(this->m_uMapScriptSize);
  if(this->m_uMapScriptSize)
    a2.Save(this->m_pMapScriptData, this->m_uMapScriptSize);
  a2.SaveSignature(-254867929);
  this->SaveState(a2);
  a2.SaveSignature(-999328080);
}

// address=[0x15ff890]
// Decompiled from CGameScriptManager *__thiscall CGameScriptManager::StartScript(CGameScriptManager *this)
void CGameScriptManager::StartScript(void) {
  if(this->m_uGameScriptState != 1 && this->m_uGameScriptState != 2 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 468, "(m_uGameScriptState == 1) || (m_uGameScriptState == 2)") == 1) {
    __debugbreak();
  }
  if(!this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 470, "m_pScriptEnv != 0") == 1)
    __debugbreak();
  if(!this->m_pScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 471, "m_pScriptManager != 0") == 1) {
    __debugbreak();
  }
  if(this->m_pMapScriptData) {
    this->ExecuteScript();
    this->CallRegisterFunctions();
    if(this->m_uGameScriptState == 1)
      this->CallNewGame();
  }
  this->m_uStartOfGameState = this->m_uGameScriptState;
  this->m_uGameScriptState = 3;
}

// address=[0x15ff960]
// Decompiled from void __thiscall CGameScriptManager::CreateStartResources(  CGameScriptManager *this,  int a2,  int _iStartX,  int _iStartY,  int a5,  int a6)
void CGameScriptManager::CreateStartResources(int a2, int _iStartX, int _iStartY, int a5, int a6) {
  char *v7; // [esp+28h] [ebp-14h]

  CStdScriptFile v6 = CStdScriptFile(L"Script\\Internal\\StartResources.txt");
  v7 = 0;
  this->m_pScriptEnv->ExecuteScript(v6);
  this->m_pScriptEnv->PushInt(_iStartX);
  this->m_pScriptEnv->PushInt(_iStartY);
  this->m_pScriptEnv->PushInt(a5);
  this->m_pScriptEnv->PushInt(a6);
  switch(a2) {
    case 1:
      v7 = "CreateStartResourcesFew";
      break;
    case 2:
      v7 = "CreateStartResourcesMedium";
      break;
    case 3:
      v7 = "CreateStartResourcesMany";
      break;
    default:
      if(!"GameScriptManager: Wrong amount of startresources!" && BBSupportDbgReport(
           2,
           "Script\\GameScriptManager.cpp",
           538,
           "\"GameScriptManager: Wrong amount of startresources!\"") == 1) {
        __debugbreak();
      }
      break;
  }
  if(v7 && !this->m_pScriptEnv->IsNil(v7))
    this->m_pScriptEnv->CallFunction(v7);
}


// address=[0x15ffaf0]
// Decompiled from int __thiscall CGameScriptManager::SetGlobal(CGameScriptManager *this, char *Str, int a3)
void CGameScriptManager::SetGlobal(char const *Str, int a3) {
  CLua ScriptEnv; // [esp+4h] [ebp-4h]
  ScriptEnv = this->GetScriptEnv();
  ScriptEnv.PushInt(a3);
  ScriptEnv.SetGlobal(Str);
}

// address=[0x16026c0]
// Decompiled from int __thiscall CGameScriptManager::NewGame(CGameScriptManager *this, struct IScriptFile *a2)
void CGameScriptManager::NewGame(IScriptFile &a2) {
  CGameScriptManager::NewGame(a2.GetScript(), a2.GetSize());
}

// address=[0x1602700]
// Decompiled from int __thiscall CGameScriptManager::NewGame(CGameScriptManager *this)
void CGameScriptManager::NewGame(void) {
  CGameScriptManager::NewGame(0, 0);
}

// address=[0x15ffb30]
// Decompiled from bool __thiscall CGameScriptManager::LoadMapScript(CGameScriptManager *this, void *Src, size_t Size)
bool CGameScriptManager::LoadMapScript(char const *Src, unsigned int Size) {
  if(this->m_pMapScriptData && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 362, "m_pMapScriptData == 0") == 1) {
    __debugbreak();
  }
  if(this->m_uMapScriptSize && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 363, "m_uMapScriptSize == 0") == 1) {
    __debugbreak();
  }
  if(Src && Size) {
    this->m_pMapScriptData = new char[Size];
    this->m_uMapScriptSize = Size;
    memcpy((void *) this->m_pMapScriptData, Src, Size);
    this->m_pScriptEnv->ExecuteScript((void *) this->m_pMapScriptData, this->m_uMapScriptSize, 0);
  } else {
    this->m_pMapScriptData = 0;
    this->m_uMapScriptSize = 0;
  }
  return this->m_pMapScriptData != 0;
}

// address=[0x15ffc30]
// Decompiled from void __thiscall CGameScriptManager::LoadState(CGameScriptManager *this, struct IS4Chunk *a2)
void CGameScriptManager::LoadState(class IS4Chunk &a2) {
  signed int v2; // [esp+0h] [ebp-58h]
  int        i;         // [esp+8h] [ebp-50h]
  double     v5[9];  // [esp+Ch] [ebp-4Ch] BYREF

  a2.LoadSignature(-159512950);
  a2.LoadUnsigned32(9, 9);
  a2.Load(v5, 72);
  this->SetSaveVarValues(v5, 9);
  a2.LoadSignature(2136404269);
  v2 = a2.LoadUnsigned32(0, 23);
  for(i = 0; i < v2; ++i)
    this->m_aScriptEventRequests[i].Load(a2);
  while(i < 23)
    this->m_aScriptEventRequests[i++].Clear();
  a2.LoadSignature(-1919979084);
}

// address=[0x15ffd30]
// Decompiled from void __thiscall CGameScriptManager::SaveState(CGameScriptManager *this, struct IS4Chunk *a2)
void CGameScriptManager::SaveState(class IS4Chunk &a2) {
  int    i;        // [esp+4h] [ebp-50h]
  double v4[9]; // [esp+8h] [ebp-4Ch] BYREF

  a2.SaveSignature(-159512950);
  this->GetSaveVarValues(v4, 9);
  a2.SaveUnsigned32(9);
  a2.Save(v4, 0x48u);
  a2.SaveSignature(2136404269);
  a2.SaveUnsigned32(23);
  for(i = 0; i < 23; ++i)
    this->m_aScriptEventRequests[i].Save(a2);
  a2.SaveSignature(-1919979084);
}

// address=[0x15ffe00]
// Decompiled from void __thiscall CGameScriptManager::ExecuteScript(CGameScriptManager *this)
void CGameScriptManager::ExecuteScript(void) {
  CLua *ScriptEnv; // [esp+0h] [ebp-8h]

  if(this->m_pMapScriptData) {
    if(this->m_uMapScriptSize) {
      this->GetScriptEnv().ExecuteScript(this->m_pMapScriptData, this->m_uMapScriptSize, 0);
    }
  }
}

// address=[0x15ffe50]
// Decompiled from void __thiscall CGameScriptManager::CallNewGame(CGameScriptManager *this)
void CGameScriptManager::CallNewGame(void) {
  CLua &ScriptEnv = this->GetScriptEnv();
  if(ScriptEnv.IsNil("new_game")) {
    BBSupportTracePrintF(0, "SCRIPT: Warning: %s not found.", "new_game");
  } else {
    ScriptTracePrintF(1u, "SCRIPT: Executing %s...", "new_game");
    ScriptEnv.CallFunction("new_game");
  }
}

// address=[0x15ffec0]
// Decompiled from void __thiscall CGameScriptManager::CallRegisterFunctions(CGameScriptManager *this)
void CGameScriptManager::CallRegisterFunctions(void) {
  CLua &          ScriptEnv = this->GetScriptEnv();
  CScriptManager &ScriptManager = this->GetScriptManager();

  if(ScriptEnv.IsNil("register_functions")) {
    BBSupportTracePrintF(0, "SCRIPT: Warning: %s not found.", "register_functions");
  } else {
    ScriptTracePrintF(1u, "SCRIPT: Executing %s...", "register_functions");
    ScriptManager.AllowRegisterFunction(true);
    ScriptEnv.CallFunction("register_functions");
    ScriptManager.AllowRegisterFunction(false);
  }
}

// address=[0x15fff50]
// Decompiled from struct CLua::SFuncInfo *__thiscall CGameScriptManager::InitScriptEnvironmentAndManager(CGameScriptManager *this)
void CGameScriptManager::InitScriptEnvironmentAndManager(void) {
  if(this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 282, "m_pScriptEnv == 0") == 1)
    __debugbreak();
  if(this->m_pScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 283, "m_pScriptManager == 0") == 1) {
    __debugbreak();
  }
  this->m_pScriptEnv = new CLua();
  this->m_pScriptManager = new CScriptManager(*this->m_pScriptEnv);

  this->m_pScriptEnv->ExportFunction(CGameScriptManager::LuaRequestEvent, "request_event");
  this->m_pScriptEnv->ExportFunction(CGameScriptManager::LuaRequestEvents, "request_events");
  this->m_pScriptEnv->ExportFunction(CGameScriptManager::LuaUnrequestEvent, "unrequest_event");
  this->m_pScriptEnv->ExportFunction(CGameScriptManager::LuaUnrequestEvents, "unrequest_events");
  this->m_pScriptEnv->ExportFunction(CGameScriptManager::LuaErrorToTrace, "_ERRORMESSAGE");
  this->m_pScriptEnv->CreateTable("Vars"); // NOTE: This is in the original binary a offset to the Vars entry... Don't know whats going on there
  ScriptExportVars(*this->m_pScriptEnv);
  ScriptExportFunctions(*this->m_pScriptEnv);
}

// address=[0x1600110]
// Decompiled from void __thiscall CGameScriptManager::UnrequestAllEvents(CGameScriptManager *this)
void CGameScriptManager::UnrequestAllEvents(void) {
  int i; // [esp+4h] [ebp-4h]

  for(i = 0; i < 23; ++i)
    this->m_aScriptEventRequests[i].Clear();
}

// address=[0x1600150]
// Decompiled from CGameScriptManager *__thiscall CGameScriptManager::Done(CGameScriptManager *this)
void CGameScriptManager::Done(void) {
  CGameScriptManager *result;       // eax
  CLua *              m_pScriptEnv;               // [esp+14h] [ebp-Ch]
  CScriptManager *    m_pScriptManager; // [esp+18h] [ebp-8h]

  delete this->m_pScriptManager;
  this->m_pScriptManager = 0;
  m_pScriptEnv = this->m_pScriptEnv;
  delete m_pScriptEnv;
  this->m_pScriptEnv = 0;
  delete[] this->m_pMapScriptData;
  this->m_pMapScriptData = 0;

  this->m_uMapScriptSize = 0;
  this->m_uGameScriptState = 0;
  this->m_pVictoryConditionHook = 0;
}

// address=[0x1600230]
// Decompiled from void __thiscall CGameScriptManager::SendGameEventCall(CGameScriptManager *this, unsigned int _iEventType)
void CGameScriptManager::SendGameEventCall(int _iEventType) {
  unsigned int v2; // [esp+4h] [ebp-14h]
  int          v3;          // [esp+8h] [ebp-10h]
  signed int   i;    // [esp+10h] [ebp-8h]

  if(_iEventType >= 0x17 && BBSupportDbgReport(
       2,
       "Script\\GameScriptManager.cpp",
       633,
       "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1) {
    __debugbreak();
  }
  if(!this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 635, "m_pScriptEnv != 0") == 1)
    __debugbreak();
  if(!this->m_pScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 636, "m_pScriptManager != 0") == 1) {
    __debugbreak();
  }
  if(this->m_uGameScriptState != 3 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 637, "m_uGameScriptState == 3") == 1) {
    __debugbreak();
  }
  CScriptEventRequests &v4 = this->m_aScriptEventRequests[_iEventType];
  this->m_pScriptEnv->BeginBlock();
  v3 = v4.Size();
  for(i = 0; i < v3; ++i) {
    if(v4[i] != 255) {
      v2 = v4[i];
      this->m_pScriptManager->Call(v2);
    }
  }
  this->m_pScriptEnv->EndBlock();
}

// address=[0x1600370]
// Decompiled from void __thiscall CGameScriptManager::SendGameEventCall(CGameScriptManager *this, unsigned int _iEventType, int a3)
void CGameScriptManager::SendGameEventCall(int _iEventType, int a3) {
  unsigned int v3; // [esp+4h] [ebp-14h]
  int          v4;          // [esp+8h] [ebp-10h]
  signed int   i;    // [esp+10h] [ebp-8h]

  if(_iEventType >= 0x17 && BBSupportDbgReport(
       2,
       "Script\\GameScriptManager.cpp",
       667,
       "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1) {
    __debugbreak();
  }
  if(!this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 669, "m_pScriptEnv != 0") == 1)
    __debugbreak();
  if(!this->m_pScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 670, "m_pScriptManager != 0") == 1) {
    __debugbreak();
  }
  if(this->m_uGameScriptState != 3 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 671, "m_uGameScriptState == 3") == 1) {
    __debugbreak();
  }
  CScriptEventRequests &v5 = this->m_aScriptEventRequests[_iEventType];
  this->m_pScriptEnv->BeginBlock();
  v4 = v5.Size();
  for(i = 0; i < v4; ++i) {
    if(v5[i] != 255) {
      v3 = v5[i];
      this->m_pScriptManager->Call(v3, a3);
    }
  }
  this->m_pScriptEnv->EndBlock();
}

// address=[0x16004b0]
// Decompiled from void __thiscall CGameScriptManager::SendGameEventCall(  CGameScriptManager *this,  unsigned int _iEventType,  int a3,  int a4)
void CGameScriptManager::SendGameEventCall(int _iEventType, int a3, int a4) {
  unsigned int v4; // [esp-Ch] [ebp-24h]
  int          v5;          // [esp+8h] [ebp-10h]
  signed int   i;    // [esp+10h] [ebp-8h]

  if(_iEventType >= 0x17 && BBSupportDbgReport(
       2,
       "Script\\GameScriptManager.cpp",
       701,
       "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1) {
    __debugbreak();
  }
  if(!this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 703, "m_pScriptEnv != 0") == 1)
    __debugbreak();
  if(!this->m_pScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 704, "m_pScriptManager != 0") == 1) {
    __debugbreak();
  }
  if(this->m_uGameScriptState != 3 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 705, "m_uGameScriptState == 3") == 1) {
    __debugbreak();
  }
  CScriptEventRequests &v6 = this->m_aScriptEventRequests[_iEventType];
  this->m_pScriptEnv->BeginBlock();
  v5 = v6.Size();
  for(i = 0; i < v5; ++i) {
    if(v6[i] != 255) {
      v4 = v6[i];
      this->m_pScriptManager->Call(v4, a3, a4);
    }
  }
  this->m_pScriptEnv->EndBlock();
}

// address=[0x16005f0]
// Decompiled from void __thiscall CGameScriptManager::SendGameEventCall(  CGameScriptManager *this,  unsigned int _iEventType,  int a3,  int a4,  int a5)
void CGameScriptManager::SendGameEventCall(int _iEventType, int a3, int a4, int a5) {
  unsigned int v5; // [esp+4h] [ebp-14h]
  int          v6;          // [esp+8h] [ebp-10h]
  signed int   i;    // [esp+10h] [ebp-8h]

  if(_iEventType >= 0x17 && BBSupportDbgReport(
       2,
       "Script\\GameScriptManager.cpp",
       735,
       "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1) {
    __debugbreak();
  }
  if(!this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 737, "m_pScriptEnv != 0") == 1)
    __debugbreak();
  if(!this->m_pScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 738, "m_pScriptManager != 0") == 1) {
    __debugbreak();
  }
  if(this->m_uGameScriptState != 3 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 739, "m_uGameScriptState == 3") == 1) {
    __debugbreak();
  }
  CScriptEventRequests &v7 = this->m_aScriptEventRequests[_iEventType];
  this->m_pScriptEnv->BeginBlock();
  v6 = v7.Size();
  for(i = 0; i < v6; ++i) {
    if(v7[i] != 255) {
      v5 = v7[i];
      this->m_pScriptManager->Call(v5, a3, a4, a5);
    }
  }
  this->m_pScriptEnv->EndBlock();
}

// address=[0x1600730]
// Decompiled from void __thiscall CGameScriptManager::SendGameEventCall(  CGameScriptManager *this,  unsigned int _iEventType,  int a3,  int a4,  int a5,  int a6)
void CGameScriptManager::SendGameEventCall(int _iEventType, int a3, int a4, int a5, int a6) {
  unsigned int v6; // [esp+4h] [ebp-14h]
  int          v7;          // [esp+8h] [ebp-10h]
  signed int   i;    // [esp+10h] [ebp-8h]

  if(_iEventType >= 0x17 && BBSupportDbgReport(
       2,
       "Script\\GameScriptManager.cpp",
       769,
       "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1) {
    __debugbreak();
  }
  if(!this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 771, "m_pScriptEnv != 0") == 1)
    __debugbreak();
  if(!this->m_pScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 772, "m_pScriptManager != 0") == 1) {
    __debugbreak();
  }
  if(this->m_uGameScriptState != 3 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 773, "m_uGameScriptState == 3") == 1) {
    __debugbreak();
  }
  CScriptEventRequests &v8 = this->m_aScriptEventRequests[_iEventType];
  this->m_pScriptEnv->BeginBlock();
  v7 = v8.Size();
  for(i = 0; i < v7; ++i) {
    if(v8[i] != 255) {
      v6 = v8[i];
      this->m_pScriptManager->Call(v6, a3, a4, a5, a6);
    }
  }
  this->m_pScriptEnv->EndBlock();
}

// address=[0x1600880]
// Decompiled from void __thiscall CGameScriptManager::GetSaveVarValues(CGameScriptManager *this, double *a2, signed int iSize)
void CGameScriptManager::GetSaveVarValues(double *a2, int iSize) {
  int        v3;           // [esp+0h] [ebp-28h]
  int        pVarsTable;   // [esp+4h] [ebp-24h]
  signed int i;     // [esp+10h] [ebp-18h]
  char       sVarName[6]; // [esp+14h] [ebp-14h] BYREF
  int        v9;           // [esp+1Ah] [ebp-Eh]
  int        v10;          // [esp+1Eh] [ebp-Ah]
  __int16    v11;      // [esp+22h] [ebp-6h]

  if((unsigned int) iSize >= 10 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 1075, "(iSize >= 0) && (iSize <= 9)") == 1) {
    __debugbreak();
  }
  strcpy(sVarName, "Save?");
  v9 = 0;
  v10 = 0;
  v11 = 0;
  CLua &ScriptEnv = this->GetScriptEnv();
  pVarsTable = ScriptEnv.GetGlobal("Vars");
  for(i = 0; i < iSize; ++i) {
    sVarName[4] = i + '1';
    lua_pushobject(pVarsTable);
    lua_pushstring(sVarName);
    v3 = lua_rawgettable();
    a2[i] = lua_getnumber(v3);
  }
}

// address=[0x1600970]
// Decompiled from void __thiscall CGameScriptManager::SetSaveVarValues(CGameScriptManager *this, double *a2, unsigned int iSize)
void CGameScriptManager::SetSaveVarValues(double *a2, int iSize) {
  int        pVarsTable;   // [esp+8h] [ebp-24h]
  signed int i;     // [esp+14h] [ebp-18h]
  char       sVarName[6]; // [esp+18h] [ebp-14h] BYREF
  int        v8;           // [esp+1Eh] [ebp-Eh]
  int        v9;           // [esp+22h] [ebp-Ah]
  __int16    v10;      // [esp+26h] [ebp-6h]

  if(iSize >= 0xA && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 1103, "(iSize >= 0) && (iSize <= 9)") == 1)
    __debugbreak();
  strcpy(sVarName, "Save?");
  v8 = 0;
  v9 = 0;
  v10 = 0;
  CLua &ScriptEnv = this->GetScriptEnv();
  pVarsTable = ScriptEnv.GetGlobal("Vars");
  for(i = 0; i < iSize; ++i) {
    sVarName[4] = i + 49;
    lua_pushobject(pVarsTable);
    lua_pushstring(sVarName);
    lua_pushnumber(a2[i]);
    lua_rawsettable();
  }
}

// address=[0x1600a60]
// Decompiled from void __thiscall CGameScriptManager::RequestEvent(CGameScriptManager *this, char *a2, unsigned int _iEventType)
void CGameScriptManager::RequestEvent(int a2, int _iEventType) {
  if(_iEventType >= 0x17 && BBSupportDbgReport(
       2,
       "Script\\GameScriptManager.cpp",
       803,
       "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1) {
    __debugbreak();
  }
  this->m_aScriptEventRequests[_iEventType].AddFunction(a2);
}

// address=[0x1600ab0]
// Decompiled from void __thiscall CGameScriptManager::UnrequestEvent(CGameScriptManager *this, unsigned int a2, unsigned int _iEventType)
void CGameScriptManager::UnrequestEvent(int a2, int _iEventType) {
  if(_iEventType >= 0x17 && BBSupportDbgReport(
       2,
       "Script\\GameScriptManager.cpp",
       815,
       "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1) {
    __debugbreak();
  }
  this->m_aScriptEventRequests[_iEventType].RemoveFunction(a2);
}

// address=[0x1600b00]
// Decompiled from void CGameScriptManager::LuaRequestEvent()
void __cdecl CGameScriptManager::LuaRequestEvent(void) {
  unsigned int Param; // [esp+4h] [ebp-18h]
  int          Func;           // [esp+8h] [ebp-14h]
  int          iEventType;     // [esp+18h] [ebp-4h]

  if(!CGameScriptManager::m_pGameScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 827, "m_pGameScriptManager != 0") == 1) {
    __debugbreak();
  }
  CLua &          ScriptEnv = CGameScriptManager::m_pGameScriptManager->GetScriptEnv();
  CScriptManager &ScriptManager = CGameScriptManager::m_pGameScriptManager->GetScriptManager();
  Param = ScriptEnv.GetParam(1);
  Func = ScriptManager.FindFunc(Param);
  if(Func == -1) {
    ScriptTracePrintF(2u, "SCRIPT: request_event: Parameter 1 is not a registered function!");
  } else {
    iEventType = ScriptEnv.GetInt(2);
    if(iEventType <= 0 || iEventType >= 23)
      ScriptTracePrintF(2u, "SCRIPT: request_event: Invalid event type %i!", iEventType);
    else
      CGameScriptManager::m_pGameScriptManager->m_aScriptEventRequests[iEventType].AddFunction(
        Func);
  }
}

// address=[0x1600bf0]
// Decompiled from void CGameScriptManager::LuaRequestEvents()
void __cdecl CGameScriptManager::LuaRequestEvents(void) {
  unsigned int Param; // [esp+4h] [ebp-1Ch]
  int          Func;           // [esp+8h] [ebp-18h]
  int          iEventType;     // [esp+18h] [ebp-8h]
  int          i;              // [esp+1Ch] [ebp-4h]

  if(!CGameScriptManager::m_pGameScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 862, "m_pGameScriptManager != 0") == 1) {
    __debugbreak();
  }
  CLua &          ScriptEnv = CGameScriptManager::m_pGameScriptManager->GetScriptEnv();
  CScriptManager &ScriptManager = CGameScriptManager::m_pGameScriptManager->GetScriptManager();
  Param = ScriptEnv.GetParam(1);
  Func = ScriptManager.FindFunc(Param);
  if(Func == -1) {
    ScriptTracePrintF(2u, "SCRIPT: request_events: Parameter 1 is not a registered function!");
  } else {
    for(i = 2; ScriptEnv.CheckParam(i); ++i) {
      iEventType = ScriptEnv.GetInt(i);

      if(iEventType <= 0 || iEventType >= 23)
        ScriptTracePrintF(2u, "SCRIPT: request_events: Parameter %i is an invalid event type %i!", i, iEventType);
      else
        CGameScriptManager::m_pGameScriptManager->m_aScriptEventRequests[iEventType].AddFunction(
          Func);
    }
  }
}

// address=[0x1600d20]
// Decompiled from void CGameScriptManager::LuaUnrequestEvent()
void __cdecl CGameScriptManager::LuaUnrequestEvent(void) {
  unsigned int Param; // [esp+4h] [ebp-18h]
  unsigned int Func;  // [esp+8h] [ebp-14h]
  int          iEventType;     // [esp+18h] [ebp-4h]

  if(!CGameScriptManager::m_pGameScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 904, "m_pGameScriptManager != 0") == 1) {
    __debugbreak();
  }
  CLua &          ScriptEnv = CGameScriptManager::m_pGameScriptManager->GetScriptEnv();
  CScriptManager &ScriptManager = CGameScriptManager::m_pGameScriptManager->GetScriptManager();
  Param = ScriptEnv.GetParam(1);
  Func = ScriptManager.FindFunc(Param);
  if(Func == -1) {
    ScriptTracePrintF(2u, "SCRIPT: unrequest_event: Parameter 1 is not a registered function!");
  } else {
    iEventType = ScriptEnv.GetInt(2);
    if(iEventType <= 0 || iEventType >= 23)
      ScriptTracePrintF(2u, "SCRIPT: unrequest_event: Invalid event type %i!", iEventType);
    else
      CGameScriptManager::m_pGameScriptManager->m_aScriptEventRequests[iEventType].RemoveFunction(
        Func);
  }
}

// address=[0x1600e10]
// Decompiled from void CGameScriptManager::LuaUnrequestEvents()
void __cdecl CGameScriptManager::LuaUnrequestEvents(void) {
  unsigned int Param; // [esp+4h] [ebp-1Ch]
  unsigned int Func;  // [esp+8h] [ebp-18h]
  int          iEventType;     // [esp+18h] [ebp-8h]
  int          i;              // [esp+1Ch] [ebp-4h]

  if(!CGameScriptManager::m_pGameScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 939, "m_pGameScriptManager != 0") == 1) {
    __debugbreak();
  }
  CLua &          ScriptEnv = CGameScriptManager::m_pGameScriptManager->GetScriptEnv();
  CScriptManager &ScriptManager = CGameScriptManager::m_pGameScriptManager->GetScriptManager();
  Param = ScriptEnv.GetParam(1);
  Func = ScriptManager.FindFunc(Param);
  if(Func == -1) {
    ScriptTracePrintF(2u, "SCRIPT: unrequest_events: Parameter 1 is not a registered function!");
  } else {
    for(i = 2; ScriptEnv.CheckParam(i); ++i) {
      iEventType = ScriptEnv.GetInt(i);

      if(iEventType <= 0 || iEventType >= 23)
        ScriptTracePrintF(2u, "SCRIPT: unrequest_events: Parameter %i is an invalid event type %i!", i, iEventType);
      else
        CGameScriptManager::m_pGameScriptManager->m_aScriptEventRequests[iEventType].RemoveFunction(
          Func);
    }
  }
}

// address=[0x1600f40]
// Decompiled from void CGameScriptManager::LuaErrorToTrace()
void __cdecl CGameScriptManager::LuaErrorToTrace(void) {
  char *v0;               // eax
  int   v1;                 // [esp+4h] [ebp-474h] BYREF
  int   CurrentLine;        // [esp+8h] [ebp-470h]
  char *Source;           // [esp+Ch] [ebp-46Ch]
  char *spObjName;               // [esp+10h] [ebp-468h] BYREF
  char *spFunctionName;              // [esp+14h] [ebp-464h] BYREF
  int   iStackDepth;        // [esp+18h] [ebp-460h]
  int   j;                  // [esp+1Ch] [ebp-45Ch]
  int   i;                  // [esp+20h] [ebp-458h]
  char  bHasFunctionInfo;  // [esp+2Bh] [ebp-44Dh]
  char  Destination[1024]; // [esp+48h] [ebp-430h] BYREF
  char  Buffer[32];        // [esp+448h] [ebp-30h] BYREF
  int   v14;                // [esp+474h] [ebp-4h]

  if(!CGameScriptManager::m_pGameScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 987, "m_pGameScriptManager != 0") == 1) {
    __debugbreak();
  }
  CLua &ScriptEnv = CGameScriptManager::m_pGameScriptManager->GetScriptEnv();
  Source = ScriptEnv.GetString(1);
  memset(Destination, 0, sizeof(Destination));
  strncpy(Destination, Source, 0x3FFu);

  for(i = 0; Destination[i]; ++i) {
    if((unsigned char) Destination[i] < ' ')
      Destination[i] = 32;
  }
  ScriptTracePrintF(2u, "SCRIPT: Error: %s", Destination);
  std::string sTrace = std::string();

  iStackDepth = 1;
  for(j = ScriptEnv.GetStackedFunction(1); j; j = ScriptEnv.GetStackedFunction(iStackDepth)) {
    bHasFunctionInfo = 0;
    ScriptEnv.GetFuncInfo(j, &spFunctionName, &v1);
    ScriptEnv.GetObjName(j, &spObjName);
    if(spFunctionName && *spFunctionName) {
      sTrace += spFunctionName;
      bHasFunctionInfo = 1;
    }
    if(spObjName && *spObjName) {
      if(bHasFunctionInfo)
        sTrace += ",";
      sTrace += spObjName;
      sTrace += "()";
      bHasFunctionInfo = 1;
    }
    CurrentLine = ScriptEnv.GetCurrentLine(j);
    if(bHasFunctionInfo)
      sTrace += ",";
    snprintf(Buffer, 0x1Fu, "%u", CurrentLine);
    sTrace += Buffer;
    sTrace += " ";
    ++iStackDepth;
  }

  if(sTrace.length()) {
    ScriptTracePrintF(2u, "SCRIPT: Callstack: %s", sTrace.c_str());
  }
}

// address=[0x1602590]
// Decompiled from CScriptManager *__thiscall CGameScriptManager::GetScriptManager(CGameScriptManager *this)
class CScriptManager &CGameScriptManager::GetScriptManager(void) {
  if(!this->m_pScriptManager && BBSupportDbgReport(
       2,
       "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\GameScriptManager.h",
       190,
       "m_pScriptManager != 0") == 1) {
    __debugbreak();
  }
  return *this->m_pScriptManager;
}

// address=[0x462b824]
// [Decompilation failed for static class CGameScriptManager * CGameScriptManager::m_pGameScriptManager]
