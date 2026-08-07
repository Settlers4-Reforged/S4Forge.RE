#if FALSE
#include "CGameScriptManager.h"

// Definitions for class CGameScriptManager

// address=[0x131ec80]
// Decompiled from CLua *__thiscall CGameScriptManager::GetScriptEnv(CGameScriptManager *this)
class CLua &  CGameScriptManager::GetScriptEnv(void) {
  
  if ( !this->m_pScriptEnv && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Script\\GameScriptManager.h", 161, "m_pScriptEnv != 0") == 1 )
  {
    __debugbreak();
  }
  return this->m_pScriptEnv;
}


// address=[0x1439ca0]
// Decompiled from void __thiscall CGameScriptManager::SendGameEvent(CGameScriptManager *this, unsigned int a2, int a3)
void  CGameScriptManager::SendGameEvent(int a2, int a3) {
  
  if ( a2 >= 0x17 && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Script\\GameScriptManager.h", 269, "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( CScriptEventRequests::Size(&this->m_aScriptEventRequests[a2]) > 0 )
  {
    CGameScriptManager::SendGameEventCall(this, a2, a3);
  }
}


// address=[0x1470c10]
// Decompiled from void __thiscall CGameScriptManager::SendGameEvent(CGameScriptManager *this, unsigned int a2, int a3, int a4, int a5, int a6)
void  CGameScriptManager::SendGameEvent(int a2, int a3, int a4, int a5, int a6) {
  
  if ( a2 >= 0x17 && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Script\\GameScriptManager.h", 299, "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( CScriptEventRequests::Size(&this->m_aScriptEventRequests[a2]) > 0 )
  {
    CGameScriptManager::SendGameEventCall(this, a2, a3, a4, a5, a6);
  }
}


// address=[0x147e750]
// Decompiled from void __thiscall CGameScriptManager::SendGameEvent(CGameScriptManager *this, unsigned int a2)
void  CGameScriptManager::SendGameEvent(int a2) {
  
  if ( a2 >= 0x17 && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Script\\GameScriptManager.h", 259, (const char *)&unk_36A8410[1]) == 1 )
  {
    __debugbreak();
  }
  if ( CScriptEventRequests::Size(&this->m_aScriptEventRequests[a2]) > 0 )
  {
    CGameScriptManager::SendGameEventCall(this, a2);
  }
}


// address=[0x147e7c0]
// Decompiled from void __thiscall CGameScriptManager::SendGameEvent(CGameScriptManager *this, unsigned int a2, int a3, int a4)
void  CGameScriptManager::SendGameEvent(int a2, int a3, int a4) {
  
  if ( a2 >= 0x17 && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Script\\GameScriptManager.h", 279, (const char *)&unk_36A8410[1]) == 1 )
  {
    __debugbreak();
  }
  if ( CScriptEventRequests::Size(&this->m_aScriptEventRequests[a2]) > 0 )
  {
    CGameScriptManager::SendGameEventCall(this, a2, a3, a4);
  }
}


// address=[0x147e840]
// Decompiled from void __thiscall CGameScriptManager::SendGameEvent(CGameScriptManager *this, unsigned int a2, int a3, int a4, int a5)
void  CGameScriptManager::SendGameEvent(int a2, int a3, int a4, int a5) {
  
  if ( a2 >= 0x17 && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Script\\GameScriptManager.h", 289, (const char *)&unk_36A8410[1]) == 1 )
  {
    __debugbreak();
  }
  if ( CScriptEventRequests::Size(&this->m_aScriptEventRequests[a2]) > 0 )
  {
    CGameScriptManager::SendGameEventCall(this, a2, a3, a4, a5);
  }
}


// address=[0x14875a0]
// Decompiled from void __thiscall CGameScriptManager::SetVictoryConditionHook(CGameScriptManager *this, void (__cdecl *a2)())
void  CGameScriptManager::SetVictoryConditionHook(void (__cdecl*)(void) a2) {
  
  this->m_pVictoryConditionHook = a2;
}


// address=[0x15feea0]
// Decompiled from CGameScriptManager *__thiscall CGameScriptManager::CGameScriptManager(CGameScriptManager *this)
 CGameScriptManager::CGameScriptManager(void) {
  
  IS4ChunkObject::IS4ChunkObject(this);
  this->__vftable = (CGameScriptManager_vtbl *)&CGameScriptManager::_vftable_;
  _vec_ctor_no(this->m_aScriptEventRequests, 0x44u, 23u, (void *(__thiscall *)(void *))CScriptEventRequests::CScriptEventRequests);
  if ( CGameScriptManager::m_pGameScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 234, "m_pGameScriptManager == 0") == 1 )
  {
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
  CGameScriptManager::InitScriptEnvironmentAndManager(this);
  return this;
}


// address=[0x15fef60]
// Decompiled from void __thiscall CGameScriptManager::~CGameScriptManager(CGameScriptManager *this)
 CGameScriptManager::~CGameScriptManager(void) {
  
  this->__vftable = (CGameScriptManager_vtbl *)&CGameScriptManager::_vftable_;
  if ( !CGameScriptManager::m_pGameScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 263, "m_pGameScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  CGameScriptManager::Done(this);
  CGameScriptManager::m_pGameScriptManager = 0;
}


// address=[0x15fefe0]
// Decompiled from void __thiscall CGameScriptManager::Update(CGameScriptManager *this, unsigned int a2)
void  CGameScriptManager::Update(unsigned int a2) {
  
  if ( this->m_uStartOfGameState == 1 )
  {
    CGameScriptManager::SendGameEvent(this, 1u);
    CGameScriptManager::SendGameEvent(this, 2u);
    this->m_uStartOfGameState = 3;
  }
  else if ( this->m_uStartOfGameState == 2 )
  {
    CGameScriptManager::SendGameEvent(this, 2u);
    this->m_uStartOfGameState = 3;
  }
  else if ( this->m_uStartOfGameState != 3 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 594, "m_uStartOfGameState == 3") == 1 )
  {
    __debugbreak();
  }
  CGameScriptManager::SendGameEvent(this, 4u);
  if ( !(a2 % 5) )
  {
    CGameScriptManager::SendGameEvent(this, 5u);
  }
  if ( (a2 & 7) == 0 && a2 > 0x8C )
  {
    if ( !g_pGameData && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 606, "g_pGameData != 0") == 1 )
    {
      __debugbreak();
    }
    if ( !CGameData::IsGameWon(g_pGameData) )
    {
      if ( this->m_pVictoryConditionHook )
      {
        this->m_pVictoryConditionHook();
      }
      else if ( CScriptEventRequests::Size(&this->m_aScriptEventRequests[3]) )
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
void  CGameScriptManager::NewGame(char const * Src, unsigned int Size) {
  
  int result; // eax

  if ( this->m_uGameScriptState && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 450, "m_uGameScriptState == 0") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 452, "m_pScriptEnv != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 453, "m_pScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  CGameScriptManager::LoadMapScript(this, Src, Size);
  CGameScriptManager::UnrequestAllEvents(this);
  this->m_uGameScriptState = 1;
  return result;
}


// address=[0x15ff1f0]
// Decompiled from void __thiscall CGameScriptManager::NewGameEx(CGameScriptManager *this, const char *Src, size_t Size, wchar_t *Source, char a5)
void  CGameScriptManager::NewGameEx(char const * Src, unsigned int Size, wchar_t const * Source, bool a5) {
  
  wchar_t *v5; // eax
  wchar_t *v6; // eax
  int v7; // [esp+0h] [ebp-6BCh] BYREF
  CStdScriptFile v8; // [esp+10h] [ebp-6ACh] BYREF
  CStdScriptFile *v9; // [esp+1Ch] [ebp-6A0h]
  void *v10; // [esp+20h] [ebp-69Ch]
  std::wstring *v11; // [esp+24h] [ebp-698h]
  void *v12; // [esp+28h] [ebp-694h]
  std::wstring *v13; // [esp+2Ch] [ebp-690h]
  wchar_t *v14; // [esp+30h] [ebp-68Ch]
  wchar_t *v15; // [esp+34h] [ebp-688h]
  size_t j; // [esp+3Ch] [ebp-680h]
  signed int v18; // [esp+40h] [ebp-67Ch]
  wchar_t *FileName; // [esp+44h] [ebp-678h]
  unsigned __int8 *v20; // [esp+48h] [ebp-674h]
  char v21; // [esp+4Fh] [ebp-66Dh]
  size_t i; // [esp+50h] [ebp-66Ch]
  std::wstring v23; // [esp+54h] [ebp-668h] BYREF
  std::wstring v24; // [esp+70h] [ebp-64Ch] BYREF
  std::wstring v25; // [esp+8Ch] [ebp-630h] BYREF
  wchar_t Destination[512]; // [esp+A8h] [ebp-614h] BYREF
  wchar_t String[256]; // [esp+4A8h] [ebp-214h] BYREF
  int *v28; // [esp+6ACh] [ebp-10h]
  int v29; // [esp+6B8h] [ebp-4h]

  v28 = &v7;
  memset(String, 0, sizeof(String));
  wcscpy(String, L"Script\\");
  if ( Src && *Src && Size >= 2 )
  {
    v20 = (unsigned __int8 *)Src;
    for ( i = Size;
          i && v20[i - 1] <= (unsigned int)' ';
          --i )
    {
      ;
    }
    while ( i && *v20 <= (unsigned int)' ' )
    {
      ++v20;
      --i;
    }
    if ( i > 2 && *v20 == '$' && v20[i - 1] == '$' )
    {
      ++v20;
      i -= 2;
      if ( i < 64 && v20[i - 1] == '\\' )
      {
        v15 = &String[wcslen(String)];
        for ( j = 0;
              j < i;
              ++j )
        {
          v15[j] = (char)v20[j];
        }
      }
      Src = 0;
      Size = 0;
    }
  }
  if ( !a5 && Src )
  {
    goto LABEL_22;
  }
  v21 = 0;
  if ( Source )
  {
    if ( *Source )
    {
      if ( wcslen(Source) < 0x400 )
      {
        wcscpy(Destination, Source);
        FileName = GetFileNameFromPath(Destination);
        if ( FileName )
        {
          v18 = wcslen(FileName);
          if ( v18 > 4 && (!wcsicmp(L".edm", &FileName[v18 - 4]) || !wcsicmp(L".map", &FileName[v18 - 4])) )
          {
            FileName[v18 - 3] = 't';
            FileName[v18 - 2] = 'x';
            FileName[v18 - 1] = 't';
            v14 = FileName;
            v13 = (std::wstring *)std::wstring::wstring(&v23, FileName);
            v11 = v13;
            v29 = 0;
            v12 = (void *)std::wstring::wstring(&v24, String);
            v10 = v12;
            LOBYTE(v29) = 1;
            std::operator+<wchar_t>((int)&v25, v12, v11);
            LOBYTE(v29) = 3;
            std::wstring::~wstring(&v24);
            LOBYTE(v29) = 4;
            std::wstring::~wstring(&v23);
            LOBYTE(v29) = 5;
            v5 = std::wstring::c_str(&v25);
            v9 = CStdScriptFile::CStdScriptFile(&v8, v5);
            LOBYTE(v29) = 6;
            v6 = std::wstring::c_str(&v25);
            ScriptTracePrintF(1u, "SCRIPT: \"%s\" loaded.", (const char *)v6);
            v21 = 1;
            CGameScriptManager::NewGame(this, &v8);
            LOBYTE(v29) = 5;
            CStdScriptFile::~CStdScriptFile(&v8);
            v29 = -1;
            std::wstring::~wstring(&v25);
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
      CGameScriptManager::NewGame(this, (void *)Src, Size);
      return;
    }
    CGameScriptManager::NewGame(this);
  }
}


// address=[0x15ff6c0]
// Decompiled from void __thiscall CGameScriptManager::Load(CGameScriptManager *this, struct IS4Chunk *a2)
void  CGameScriptManager::Load(class IS4Chunk & a2) {
  
  if ( this->m_uGameScriptState && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 1200, "m_uGameScriptState == 0") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 1202, "m_pScriptEnv != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 1203, "m_pScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  a2->LoadSignature(1093785866);
  this->m_pMapScriptData = 0;
  this->m_uMapScriptSize = a2->LoadUnsigned32_(a2);
  if ( this->m_uMapScriptSize )
  {
    this->m_pMapScriptData = (int)operator new[](this->m_uMapScriptSize);
    a2->Load((void *)this->m_pMapScriptData, this->m_uMapScriptSize);
  }
  a2->LoadSignature(-254867929);
  CGameScriptManager::LoadState(this, a2);
  a2->LoadSignature(-999328080);
  this->m_uGameScriptState = 2;
}


// address=[0x15ff800]
// Decompiled from void __thiscall CGameScriptManager::Save(CGameScriptManager *this, struct IS4Chunk *a2)
void  CGameScriptManager::Save(class IS4Chunk & a2) {
  
  a2->SaveSignature(1093785866);
  a2->SaveUnsigned32(this->m_uMapScriptSize);
  if ( this->m_uMapScriptSize )
  {
    a2->Save((void *)this->m_pMapScriptData, this->m_uMapScriptSize);
  }
  a2->SaveSignature(-254867929);
  CGameScriptManager::SaveState(this, a2);
  a2->SaveSignature(-999328080);
}


// address=[0x15ff890]
// Decompiled from CGameScriptManager *__thiscall CGameScriptManager::StartScript(CGameScriptManager *this)
void  CGameScriptManager::StartScript(void) {
  
  CGameScriptManager *result; // eax

  if ( this->m_uGameScriptState != 1 && this->m_uGameScriptState != 2 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 468, "(m_uGameScriptState == 1) || (m_uGameScriptState == 2)") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 470, "m_pScriptEnv != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 471, "m_pScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_pMapScriptData )
  {
    CGameScriptManager::ExecuteScript(this);
    CGameScriptManager::CallRegisterFunctions(this);
    if ( this->m_uGameScriptState == 1 )
    {
      CGameScriptManager::CallNewGame(this);
    }
  }
  this->m_uStartOfGameState = this->m_uGameScriptState;
  result = this;
  this->m_uGameScriptState = 3;
  return result;
}


// address=[0x15ff960]
// Decompiled from void __thiscall CGameScriptManager::CreateStartResources(CGameScriptManager *this, int a2, int _iStartX, int _iStartY, int a5, int a6)
void  CGameScriptManager::CreateStartResources(int a2, int _iStartX, int _iStartY, int a5, int a6) {
  
  struct IScriptFile *v6; // [esp+18h] [ebp-24h]
  char *v7; // [esp+28h] [ebp-14h]

  if ( operator new(0xCu) )
  {
    v6 = (struct IScriptFile *)CStdScriptFile::CStdScriptFile((wchar_t *)L"Script\\Internal\\StartResources.txt");
  }
  else
  {
    v6 = 0;
  }
  v7 = 0;
  CLua::ExecuteScript(this->m_pScriptEnv, v6);
  CLua::PushInt(this->m_pScriptEnv, _iStartX);
  CLua::PushInt(this->m_pScriptEnv, _iStartY);
  CLua::PushInt(this->m_pScriptEnv, a5);
  CLua::PushInt(this->m_pScriptEnv, a6);
  switch ( a2 )
  {
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
      if ( !"GameScriptManager: Wrong amount of startresources!" && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 538, "\"GameScriptManager: Wrong amount of startresources!\"") == 1 )
      {
        __debugbreak();
      }
      break;
  }
  if ( v7 && !CLua::IsNil(this->m_pScriptEnv, v7) )
  {
    CLua::CallFunction(this->m_pScriptEnv, v7);
  }
  if ( v6 )
  {
    ((void (__thiscall *)(struct IScriptFile *, int))v6->dtor)(v6, 1);
  }
}


// address=[0x15ffaf0]
// Decompiled from int __thiscall CGameScriptManager::SetGlobal(CGameScriptManager *this, char *Str, int a3)
void  CGameScriptManager::SetGlobal(char const * Str, int a3) {
  
  CLua *ScriptEnv; // [esp+4h] [ebp-4h]

  ScriptEnv = CGameScriptManager::GetScriptEnv(this);
  CLua::PushInt(ScriptEnv, a3);
  return CLua::SetGlobal(Str);
}


// address=[0x16026c0]
// Decompiled from int __thiscall CGameScriptManager::NewGame(CGameScriptManager *this, struct IScriptFile *a2)
void  CGameScriptManager::NewGame(class IScriptFile & a2) {
  
  char *v2; // eax
  size_t v4; // [esp-4h] [ebp-8h]

  v4 = a2->GetSize(a2);
  v2 = (char *)a2->GetScript(a2);
  return CGameScriptManager::NewGame(v2, v4);
}


// address=[0x1602700]
// Decompiled from int __thiscall CGameScriptManager::NewGame(CGameScriptManager *this)
void  CGameScriptManager::NewGame(void) {
  
  return CGameScriptManager::NewGame(0, 0);
}


// address=[0x15ffb30]
// Decompiled from bool __thiscall CGameScriptManager::LoadMapScript(CGameScriptManager *this, void *Src, size_t Size)
bool  CGameScriptManager::LoadMapScript(char const * Src, unsigned int Size) {
  
  if ( this->m_pMapScriptData && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 362, "m_pMapScriptData == 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uMapScriptSize && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 363, "m_uMapScriptSize == 0") == 1 )
  {
    __debugbreak();
  }
  if ( Src && Size )
  {
    this->m_pMapScriptData = operator new[](Size);
    this->m_uMapScriptSize = Size;
    memcpy(this->m_pMapScriptData, Src, Size);
    CLua::ExecuteScript(this->m_pScriptEnv, this->m_pMapScriptData, this->m_uMapScriptSize, 0);
  }
  else
  {
    this->m_pMapScriptData = 0;
    this->m_uMapScriptSize = 0;
  }
  return this->m_pMapScriptData != 0;
}


// address=[0x15ffc30]
// Decompiled from void __thiscall CGameScriptManager::LoadState(CGameScriptManager *this, struct IS4Chunk *a2)
void  CGameScriptManager::LoadState(class IS4Chunk & a2) {
  
  signed int v2; // [esp+0h] [ebp-58h]
  int i; // [esp+8h] [ebp-50h]
  double v5[9]; // [esp+Ch] [ebp-4Ch] BYREF

  a2->LoadSignature(-159512950);
  a2->LoadUnsigned32(9, 9);
  a2->Load(v5, 72);
  CGameScriptManager::SetSaveVarValues(this, v5, 9);
  a2->LoadSignature(2136404269);
  v2 = a2->LoadUnsigned32(0, 23);
  for ( i = 0;
        i < v2;
        ++i )
  {
    CScriptEventRequests::Load(&this->m_aScriptEventRequests[i], a2);
  }
  while ( i < 23 )
  {
    CScriptEventRequests::Clear(&this->m_aScriptEventRequests[i++]);
  }
  a2->LoadSignature(-1919979084);
}


// address=[0x15ffd30]
// Decompiled from void __thiscall CGameScriptManager::SaveState(CGameScriptManager *this, struct IS4Chunk *a2)
void  CGameScriptManager::SaveState(class IS4Chunk & a2) {
  
  int i; // [esp+4h] [ebp-50h]
  double v4[9]; // [esp+8h] [ebp-4Ch] BYREF

  a2->SaveSignature(-159512950);
  CGameScriptManager::GetSaveVarValues(this, v4, 9);
  a2->SaveUnsigned32(9);
  a2->Save(v4, 0x48u);
  a2->SaveSignature(2136404269);
  a2->SaveUnsigned32(23);
  for ( i = 0;
        i < 23;
        ++i )
  {
    CScriptEventRequests::Save(&this->m_aScriptEventRequests[i], a2);
  }
  a2->SaveSignature(-1919979084);
}


// address=[0x15ffe00]
// Decompiled from void __thiscall CGameScriptManager::ExecuteScript(CGameScriptManager *this)
void  CGameScriptManager::ExecuteScript(void) {
  
  CLua *ScriptEnv; // [esp+0h] [ebp-8h]

  if ( this->m_pMapScriptData )
  {
    if ( this->m_uMapScriptSize )
    {
      ScriptEnv = CGameScriptManager::GetScriptEnv(this);
      CLua::ExecuteScript(ScriptEnv, this->m_pMapScriptData, this->m_uMapScriptSize, 0);
    }
  }
}


// address=[0x15ffe50]
// Decompiled from void __thiscall CGameScriptManager::CallNewGame(CGameScriptManager *this)
void  CGameScriptManager::CallNewGame(void) {
  
  CLua *ScriptEnv; // [esp+4h] [ebp-4h]

  ScriptEnv = CGameScriptManager::GetScriptEnv(this);
  if ( CLua::IsNil(ScriptEnv, "new_game") )
  {
    BBSupportTracePrintF(0, "SCRIPT: Warning: %s not found.", "new_game");
  }
  else
  {
    ScriptTracePrintF(1u, "SCRIPT: Executing %s...", "new_game");
    CLua::CallFunction(ScriptEnv, "new_game");
  }
}


// address=[0x15ffec0]
// Decompiled from void __thiscall CGameScriptManager::CallRegisterFunctions(CGameScriptManager *this)
void  CGameScriptManager::CallRegisterFunctions(void) {
  
  CScriptManager *ScriptManager; // [esp+0h] [ebp-Ch]
  CLua *ScriptEnv; // [esp+4h] [ebp-8h]

  ScriptEnv = CGameScriptManager::GetScriptEnv(this);
  ScriptManager = CGameScriptManager::GetScriptManager(this);
  if ( CLua::IsNil(ScriptEnv, "register_functions") )
  {
    BBSupportTracePrintF(0, "SCRIPT: Warning: %s not found.", "register_functions");
  }
  else
  {
    ScriptTracePrintF(1u, "SCRIPT: Executing %s...", "register_functions");
    CScriptManager::AllowRegisterFunction(ScriptManager, 1u);
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

  if ( this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 282, "m_pScriptEnv == 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_pScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 283, "m_pScriptManager == 0") == 1 )
  {
    __debugbreak();
  }
  C = (CLua *)operator new(4u);
  if ( C )
  {
    v3 = CLua::CLua(C);
  }
  else
  {
    v3 = 0;
  }
  this->m_pScriptEnv = v3;
  v2 = (CScriptManager *)operator new(0x110u);
  if ( v2 )
  {
    v1 = CScriptManager::CScriptManager(v2, this->m_pScriptEnv);
  }
  else
  {
    v1 = 0;
  }
  this->m_pScriptManager = v1;
  CLua::ExportFunction(this->m_pScriptEnv, CGameScriptManager::LuaRequestEvent, "request_event");
  CLua::ExportFunction(this->m_pScriptEnv, CGameScriptManager::LuaRequestEvents, "request_events");
  CLua::ExportFunction(this->m_pScriptEnv, CGameScriptManager::LuaUnrequestEvent, "unrequest_event");
  CLua::ExportFunction(this->m_pScriptEnv, CGameScriptManager::LuaUnrequestEvents, "unrequest_events");
  CLua::ExportFunction(this->m_pScriptEnv, CGameScriptManager::LuaErrorToTrace, "_ERRORMESSAGE");
  CLua::CreateTable(this->m_pScriptEnv, off_3D8C0F8);
  ScriptExportVars(this->m_pScriptEnv);
  ScriptExportFunctions(this->m_pScriptEnv);
}


// address=[0x1600110]
// Decompiled from void __thiscall CGameScriptManager::UnrequestAllEvents(CGameScriptManager *this)
void  CGameScriptManager::UnrequestAllEvents(void) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0;
        i < 23;
        ++i )
  {
    CScriptEventRequests::Clear(&this->m_aScriptEventRequests[i]);
  }
}


// address=[0x1600150]
// Decompiled from CGameScriptManager *__thiscall CGameScriptManager::Done(CGameScriptManager *this)
void  CGameScriptManager::Done(void) {
  
  CGameScriptManager *result; // eax
  CLua *m_pScriptEnv; // [esp+14h] [ebp-Ch]
  CScriptManager *m_pScriptManager; // [esp+18h] [ebp-8h]

  if ( this->m_pScriptManager )
  {
    m_pScriptManager = this->m_pScriptManager;
    if ( m_pScriptManager )
    {
      (*(void (__thiscall **)(CScriptManager *, int))m_pScriptManager->vtable)(m_pScriptManager, 1);// dtor
    }
    this->m_pScriptManager = 0;
  }
  if ( this->m_pScriptEnv )
  {
    m_pScriptEnv = this->m_pScriptEnv;
    if ( m_pScriptEnv )
    {
      delete m_pScriptEnv;
    }
    this->m_pScriptEnv = 0;
  }
  if ( this->m_pMapScriptData )
  {
    operator delete[](this->m_pMapScriptData);
    this->m_pMapScriptData = 0;
  }
  result = this;
  this->m_uMapScriptSize = 0;
  this->m_uGameScriptState = 0;
  this->m_pVictoryConditionHook = 0;
  return result;
}


// address=[0x1600230]
// Decompiled from void __thiscall CGameScriptManager::SendGameEventCall(CGameScriptManager *this, unsigned int _iEventType)
void  CGameScriptManager::SendGameEventCall(int _iEventType) {
  
  unsigned int v2; // [esp+4h] [ebp-14h]
  int v3; // [esp+8h] [ebp-10h]
  CScriptEventRequests *v4; // [esp+Ch] [ebp-Ch]
  signed int i; // [esp+10h] [ebp-8h]

  if ( _iEventType >= 0x17 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 633, "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 635, "m_pScriptEnv != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 636, "m_pScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uGameScriptState != 3 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 637, "m_uGameScriptState == 3") == 1 )
  {
    __debugbreak();
  }
  v4 = &this->m_aScriptEventRequests[_iEventType];
  CLua::BeginBlock(this->m_pScriptEnv);
  v3 = CScriptEventRequests::Size(v4);
  for ( i = 0;
        i < v3;
        ++i )
  {
    if ( CScriptEventRequests::operator[]((unsigned int *)v4, i) != 255 )
    {
      v2 = CScriptEventRequests::operator[]((unsigned int *)v4, i);
      CScriptManager::Call(this->m_pScriptManager, v2);
    }
  }
  CLua::EndBlock(this->m_pScriptEnv);
}


// address=[0x1600370]
// Decompiled from void __thiscall CGameScriptManager::SendGameEventCall(CGameScriptManager *this, unsigned int _iEventType, int a3)
void  CGameScriptManager::SendGameEventCall(int _iEventType, int a3) {
  
  unsigned int v3; // [esp+4h] [ebp-14h]
  int v4; // [esp+8h] [ebp-10h]
  CScriptEventRequests *v5; // [esp+Ch] [ebp-Ch]
  signed int i; // [esp+10h] [ebp-8h]

  if ( _iEventType >= 0x17 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 667, "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 669, "m_pScriptEnv != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 670, "m_pScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uGameScriptState != 3 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 671, "m_uGameScriptState == 3") == 1 )
  {
    __debugbreak();
  }
  v5 = &this->m_aScriptEventRequests[_iEventType];
  CLua::BeginBlock(this->m_pScriptEnv);
  v4 = CScriptEventRequests::Size(v5);
  for ( i = 0;
        i < v4;
        ++i )
  {
    if ( CScriptEventRequests::operator[]((unsigned int *)v5, i) != 255 )
    {
      v3 = CScriptEventRequests::operator[]((unsigned int *)v5, i);
      CScriptManager::Call(this->m_pScriptManager, v3, a3);
    }
  }
  CLua::EndBlock(this->m_pScriptEnv);
}


// address=[0x16004b0]
// Decompiled from void __thiscall CGameScriptManager::SendGameEventCall(CGameScriptManager *this, unsigned int _iEventType, int a3, int a4)
void  CGameScriptManager::SendGameEventCall(int _iEventType, int a3, int a4) {
  
  unsigned int v4; // [esp-Ch] [ebp-24h]
  int v5; // [esp+8h] [ebp-10h]
  CScriptEventRequests *v6; // [esp+Ch] [ebp-Ch]
  signed int i; // [esp+10h] [ebp-8h]

  if ( _iEventType >= 0x17 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 701, "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 703, "m_pScriptEnv != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 704, "m_pScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uGameScriptState != 3 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 705, "m_uGameScriptState == 3") == 1 )
  {
    __debugbreak();
  }
  v6 = &this->m_aScriptEventRequests[_iEventType];
  CLua::BeginBlock(this->m_pScriptEnv);
  v5 = CScriptEventRequests::Size(v6);
  for ( i = 0;
        i < v5;
        ++i )
  {
    if ( CScriptEventRequests::operator[]((unsigned int *)v6, i) != 255 )
    {
      v4 = CScriptEventRequests::operator[]((unsigned int *)v6, i);
      CScriptManager::Call(this->m_pScriptManager, v4, a3, a4);
    }
  }
  CLua::EndBlock(this->m_pScriptEnv);
}


// address=[0x16005f0]
// Decompiled from void __thiscall CGameScriptManager::SendGameEventCall(CGameScriptManager *this, unsigned int _iEventType, int a3, int a4, int a5)
void  CGameScriptManager::SendGameEventCall(int _iEventType, int a3, int a4, int a5) {
  
  unsigned int v5; // [esp+4h] [ebp-14h]
  int v6; // [esp+8h] [ebp-10h]
  CScriptEventRequests *v7; // [esp+Ch] [ebp-Ch]
  signed int i; // [esp+10h] [ebp-8h]

  if ( _iEventType >= 0x17 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 735, "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 737, "m_pScriptEnv != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 738, "m_pScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uGameScriptState != 3 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 739, "m_uGameScriptState == 3") == 1 )
  {
    __debugbreak();
  }
  v7 = &this->m_aScriptEventRequests[_iEventType];
  CLua::BeginBlock(this->m_pScriptEnv);
  v6 = CScriptEventRequests::Size(v7);
  for ( i = 0;
        i < v6;
        ++i )
  {
    if ( CScriptEventRequests::operator[]((unsigned int *)v7, i) != 255 )
    {
      v5 = CScriptEventRequests::operator[]((unsigned int *)v7, i);
      CScriptManager::Call(this->m_pScriptManager, v5, a3, a4, a5);
    }
  }
  CLua::EndBlock(this->m_pScriptEnv);
}


// address=[0x1600730]
// Decompiled from void __thiscall CGameScriptManager::SendGameEventCall(CGameScriptManager *this, unsigned int _iEventType, int a3, int a4, int a5, int a6)
void  CGameScriptManager::SendGameEventCall(int _iEventType, int a3, int a4, int a5, int a6) {
  
  unsigned int v6; // [esp+4h] [ebp-14h]
  int v7; // [esp+8h] [ebp-10h]
  CScriptEventRequests *v8; // [esp+Ch] [ebp-Ch]
  signed int i; // [esp+10h] [ebp-8h]

  if ( _iEventType >= 0x17 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 769, "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pScriptEnv && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 771, "m_pScriptEnv != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 772, "m_pScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uGameScriptState != 3 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 773, "m_uGameScriptState == 3") == 1 )
  {
    __debugbreak();
  }
  v8 = &this->m_aScriptEventRequests[_iEventType];
  CLua::BeginBlock(this->m_pScriptEnv);
  v7 = CScriptEventRequests::Size(v8);
  for ( i = 0;
        i < v7;
        ++i )
  {
    if ( CScriptEventRequests::operator[]((unsigned int *)v8, i) != 255 )
    {
      v6 = CScriptEventRequests::operator[]((unsigned int *)v8, i);
      CScriptManager::Call(this->m_pScriptManager, v6, a3, a4, a5, a6);
    }
  }
  CLua::EndBlock(this->m_pScriptEnv);
}


// address=[0x1600880]
// Decompiled from void __thiscall CGameScriptManager::GetSaveVarValues(CGameScriptManager *this, double *a2, signed int iSize)
void  CGameScriptManager::GetSaveVarValues(double * a2, int iSize) {
  
  int v3; // [esp+0h] [ebp-28h]
  int pVarsTable; // [esp+4h] [ebp-24h]
  CLua *ScriptEnv; // [esp+8h] [ebp-20h]
  signed int i; // [esp+10h] [ebp-18h]
  char sVarName[6]; // [esp+14h] [ebp-14h] BYREF
  int v9; // [esp+1Ah] [ebp-Eh]
  int v10; // [esp+1Eh] [ebp-Ah]
  __int16 v11; // [esp+22h] [ebp-6h]

  if ( (unsigned int)iSize >= 10 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 1075, "(iSize >= 0) && (iSize <= 9)") == 1 )
  {
    __debugbreak();
  }
  strcpy(sVarName, "Save?");
  v9 = 0;
  v10 = 0;
  v11 = 0;
  ScriptEnv = CGameScriptManager::GetScriptEnv(this);
  pVarsTable = CLua::GetGlobal(ScriptEnv, "Vars");
  for ( i = 0;
        i < iSize;
        ++i )
  {
    sVarName[4] = i + '1';
    lua_pushobject(pVarsTable);
    lua_pushstring(sVarName);
    v3 = j__lua_rawgettable();
    a2[i] = j__lua_getnumber(v3);
  }
}


// address=[0x1600970]
// Decompiled from void __thiscall CGameScriptManager::SetSaveVarValues(CGameScriptManager *this, double *a2, unsigned int iSize)
void  CGameScriptManager::SetSaveVarValues(double * a2, int iSize) {
  
  int pVarsTable; // [esp+8h] [ebp-24h]
  CLua *ScriptEnv; // [esp+Ch] [ebp-20h]
  signed int i; // [esp+14h] [ebp-18h]
  char sVarName[6]; // [esp+18h] [ebp-14h] BYREF
  int v8; // [esp+1Eh] [ebp-Eh]
  int v9; // [esp+22h] [ebp-Ah]
  __int16 v10; // [esp+26h] [ebp-6h]

  if ( iSize >= 0xA && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 1103, "(iSize >= 0) && (iSize <= 9)") == 1 )
  {
    __debugbreak();
  }
  strcpy(sVarName, "Save?");
  v8 = 0;
  v9 = 0;
  v10 = 0;
  ScriptEnv = CGameScriptManager::GetScriptEnv(this);
  pVarsTable = CLua::GetGlobal(ScriptEnv, "Vars");
  for ( i = 0;
        i < (int)iSize;
        ++i )
  {
    sVarName[4] = i + 49;
    lua_pushobject(pVarsTable);
    lua_pushstring(sVarName);
    lua_pushnumber(a2[i]);
    lua_rawsettable();
  }
}


// address=[0x1600a60]
// Decompiled from void __thiscall CGameScriptManager::RequestEvent(CGameScriptManager *this, char *a2, unsigned int _iEventType)
void  CGameScriptManager::RequestEvent(int a2, int _iEventType) {
  
  if ( _iEventType >= 0x17 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 803, "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1 )
  {
    __debugbreak();
  }
  CScriptEventRequests::AddFunction(&this->m_aScriptEventRequests[_iEventType], a2);
}


// address=[0x1600ab0]
// Decompiled from void __thiscall CGameScriptManager::UnrequestEvent(CGameScriptManager *this, unsigned int a2, unsigned int _iEventType)
void  CGameScriptManager::UnrequestEvent(int a2, int _iEventType) {
  
  if ( _iEventType >= 0x17 && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 815, "static_cast<unsigned int>(_iEventType) < SCRIPT_EVENTS_MAX") == 1 )
  {
    __debugbreak();
  }
  CScriptEventRequests::RemoveFunction(&this->m_aScriptEventRequests[_iEventType], a2);
}


// address=[0x1600b00]
// Decompiled from void CGameScriptManager::LuaRequestEvent()
void __cdecl CGameScriptManager::LuaRequestEvent(void) {
  
  CScriptManager *ScriptManager; // [esp+0h] [ebp-1Ch]
  unsigned int Param; // [esp+4h] [ebp-18h]
  char *Func; // [esp+8h] [ebp-14h]
  __int64 v3; // [esp+Ch] [ebp-10h]
  CLua *ScriptEnv; // [esp+14h] [ebp-8h]
  int iEventType; // [esp+18h] [ebp-4h]

  if ( !CGameScriptManager::m_pGameScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 827, "m_pGameScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  ScriptEnv = CGameScriptManager::GetScriptEnv(CGameScriptManager::m_pGameScriptManager);
  ScriptManager = CGameScriptManager::GetScriptManager(CGameScriptManager::m_pGameScriptManager);
  Param = CLua::GetParam(ScriptEnv, 1);
  Func = (char *)CScriptManager::FindFunc(ScriptManager, Param);
  if ( Func == (char *)-1 )
  {
    ScriptTracePrintF(2u, "SCRIPT: request_event: Parameter 1 is not a registered function!");
  }
  else
  {
    iEventType = CLua::GetInt(ScriptEnv, 2);
    HIDWORD(v3) = iEventType <= 0;
    LODWORD(v3) = iEventType >= 23;
    if ( v3 )
    {
      ScriptTracePrintF(2u, "SCRIPT: request_event: Invalid event type %i!", iEventType);
    }
    else
    {
      CScriptEventRequests::AddFunction(&CGameScriptManager::m_pGameScriptManager->m_aScriptEventRequests[iEventType], Func);
    }
  }
}


// address=[0x1600bf0]
// Decompiled from void CGameScriptManager::LuaRequestEvents()
void __cdecl CGameScriptManager::LuaRequestEvents(void) {
  
  CScriptManager *ScriptManager; // [esp+0h] [ebp-20h]
  unsigned int Param; // [esp+4h] [ebp-1Ch]
  char *Func; // [esp+8h] [ebp-18h]
  __int64 v3; // [esp+Ch] [ebp-14h]
  CLua *ScriptEnv; // [esp+14h] [ebp-Ch]
  int iEventType; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  if ( !CGameScriptManager::m_pGameScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 862, "m_pGameScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  ScriptEnv = CGameScriptManager::GetScriptEnv(CGameScriptManager::m_pGameScriptManager);
  ScriptManager = CGameScriptManager::GetScriptManager(CGameScriptManager::m_pGameScriptManager);
  Param = CLua::GetParam(ScriptEnv, 1);
  Func = (char *)CScriptManager::FindFunc(ScriptManager, Param);
  if ( Func == (char *)-1 )
  {
    ScriptTracePrintF(2u, "SCRIPT: request_events: Parameter 1 is not a registered function!");
  }
  else
  {
    for ( i = 2;
          CLua::CheckParam(ScriptEnv, i);
          ++i )
    {
      iEventType = CLua::GetInt(ScriptEnv, i);
      HIDWORD(v3) = iEventType <= 0;
      LODWORD(v3) = iEventType >= 23;
      if ( v3 )
      {
        ScriptTracePrintF(2u, "SCRIPT: request_events: Parameter %i is an invalid event type %i!", i, iEventType);
      }
      else
      {
        CScriptEventRequests::AddFunction(&CGameScriptManager::m_pGameScriptManager->m_aScriptEventRequests[iEventType], Func);
      }
    }
  }
}


// address=[0x1600d20]
// Decompiled from void CGameScriptManager::LuaUnrequestEvent()
void __cdecl CGameScriptManager::LuaUnrequestEvent(void) {
  
  CScriptManager *ScriptManager; // [esp+0h] [ebp-1Ch]
  unsigned int Param; // [esp+4h] [ebp-18h]
  unsigned int Func; // [esp+8h] [ebp-14h]
  __int64 v3; // [esp+Ch] [ebp-10h]
  CLua *ScriptEnv; // [esp+14h] [ebp-8h]
  int iEventType; // [esp+18h] [ebp-4h]

  if ( !CGameScriptManager::m_pGameScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 904, "m_pGameScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  ScriptEnv = CGameScriptManager::GetScriptEnv(CGameScriptManager::m_pGameScriptManager);
  ScriptManager = CGameScriptManager::GetScriptManager(CGameScriptManager::m_pGameScriptManager);
  Param = CLua::GetParam(ScriptEnv, 1);
  Func = CScriptManager::FindFunc(ScriptManager, Param);
  if ( Func == -1 )
  {
    ScriptTracePrintF(2u, "SCRIPT: unrequest_event: Parameter 1 is not a registered function!");
  }
  else
  {
    iEventType = CLua::GetInt(ScriptEnv, 2);
    HIDWORD(v3) = iEventType <= 0;
    LODWORD(v3) = iEventType >= 23;
    if ( v3 )
    {
      ScriptTracePrintF(2u, "SCRIPT: unrequest_event: Invalid event type %i!", iEventType);
    }
    else
    {
      CScriptEventRequests::RemoveFunction(&CGameScriptManager::m_pGameScriptManager->m_aScriptEventRequests[iEventType], Func);
    }
  }
}


// address=[0x1600e10]
// Decompiled from void CGameScriptManager::LuaUnrequestEvents()
void __cdecl CGameScriptManager::LuaUnrequestEvents(void) {
  
  CScriptManager *ScriptManager; // [esp+0h] [ebp-20h]
  unsigned int Param; // [esp+4h] [ebp-1Ch]
  unsigned int Func; // [esp+8h] [ebp-18h]
  __int64 v3; // [esp+Ch] [ebp-14h]
  CLua *ScriptEnv; // [esp+14h] [ebp-Ch]
  int iEventType; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  if ( !CGameScriptManager::m_pGameScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 939, "m_pGameScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  ScriptEnv = CGameScriptManager::GetScriptEnv(CGameScriptManager::m_pGameScriptManager);
  ScriptManager = CGameScriptManager::GetScriptManager(CGameScriptManager::m_pGameScriptManager);
  Param = CLua::GetParam(ScriptEnv, 1);
  Func = CScriptManager::FindFunc(ScriptManager, Param);
  if ( Func == -1 )
  {
    ScriptTracePrintF(2u, "SCRIPT: unrequest_events: Parameter 1 is not a registered function!");
  }
  else
  {
    for ( i = 2;
          CLua::CheckParam(ScriptEnv, i);
          ++i )
    {
      iEventType = CLua::GetInt(ScriptEnv, i);
      HIDWORD(v3) = iEventType <= 0;
      LODWORD(v3) = iEventType >= 23;
      if ( v3 )
      {
        ScriptTracePrintF(2u, "SCRIPT: unrequest_events: Parameter %i is an invalid event type %i!", i, iEventType);
      }
      else
      {
        CScriptEventRequests::RemoveFunction(&CGameScriptManager::m_pGameScriptManager->m_aScriptEventRequests[iEventType], Func);
      }
    }
  }
}


// address=[0x1600f40]
// Decompiled from void CGameScriptManager::LuaErrorToTrace()
void __cdecl CGameScriptManager::LuaErrorToTrace(void) {
  
  char *v0; // eax
  int v1; // [esp+4h] [ebp-474h] BYREF
  int CurrentLine; // [esp+8h] [ebp-470h]
  char *Source; // [esp+Ch] [ebp-46Ch]
  char *v4; // [esp+10h] [ebp-468h] BYREF
  char *Str; // [esp+14h] [ebp-464h] BYREF
  int v6; // [esp+18h] [ebp-460h]
  int j; // [esp+1Ch] [ebp-45Ch]
  int i; // [esp+20h] [ebp-458h]
  CLua *ScriptEnv; // [esp+24h] [ebp-454h]
  char v10; // [esp+2Bh] [ebp-44Dh]
  std::string v11; // [esp+2Ch] [ebp-44Ch] BYREF
  char Destination[1024]; // [esp+48h] [ebp-430h] BYREF
  char Buffer[32]; // [esp+448h] [ebp-30h] BYREF
  int v14; // [esp+474h] [ebp-4h]

  if ( !CGameScriptManager::m_pGameScriptManager && BBSupportDbgReport(2, "Script\\GameScriptManager.cpp", 987, "m_pGameScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  ScriptEnv = CGameScriptManager::GetScriptEnv(CGameScriptManager::m_pGameScriptManager);
  Source = CLua::GetString(ScriptEnv, 1);
  memset(Destination, 0, sizeof(Destination));
  j__strncpy(Destination, Source, 0x3FFu);
  for ( i = 0;
        Destination[i];
        ++i )
  {
    if ( (unsigned __int8)Destination[i] < 0x20u )
    {
      Destination[i] = 32;
    }
  }
  ScriptTracePrintF(2u, "SCRIPT: Error: %s", Destination);
  std::string::string(&v11);
  v14 = 0;
  v6 = 1;
  for ( j = CLua::GetStackedFunction(ScriptEnv, 1);
        j;
        j = CLua::GetStackedFunction(ScriptEnv, v6) )
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
      {
        std::string::operator+=(",");
      }
      std::string::operator+=(v4);
      std::string::operator+=("()");
      v10 = 1;
    }
    CurrentLine = CLua::GetCurrentLine((void **)&ScriptEnv->state, j);
    if ( v10 )
    {
      std::string::operator+=(",");
    }
    snprintf(Buffer, 0x1Fu, "%u", CurrentLine);
    std::string::operator+=(Buffer);
    std::string::operator+=(" ");
    ++v6;
  }
  if ( std::string::length(&v11) )
  {
    v0 = std::string::c_str(&v11);
    ScriptTracePrintF(2u, "SCRIPT: Callstack: %s", v0);
  }
  v14 = -1;
  std::string::~string(&v11);
}


// address=[0x1602590]
// Decompiled from CScriptManager *__thiscall CGameScriptManager::GetScriptManager(CGameScriptManager *this)
class CScriptManager &  CGameScriptManager::GetScriptManager(void) {
  
  if ( !this->m_pScriptManager && BBSupportDbgReport(2, "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\GameScriptManager.h", 190, "m_pScriptManager != 0") == 1 )
  {
    __debugbreak();
  }
  return this->m_pScriptManager;
}


// address=[0x462b824]
// [Decompilation failed for static class CGameScriptManager * CGameScriptManager::m_pGameScriptManager]

#endif // Already implemented
