#include "all_headers.h"

// Definitions for class CDebugFkt

// address=[0x134f2a0]
// Decompiled from char __cdecl CDebugFkt::SetDebugFuncKey(char *String2, char a2)
static bool __cdecl CDebugFkt::SetDebugFuncKey(char const *,char) {
  
  int *i; // [esp+0h] [ebp-4h]

  if ( String2 && (!a2 || a2 >= 97 && a2 <= 122 || a2 >= 65 && a2 <= 90) )
  {
    for ( i = &dword_3D7A768; i[1]; i += 4 )
    {
      if ( !j___strnicmp((const char *)i[2], String2, 0x100u) )
      {
        *(_BYTE *)i = a2;
        return 1;
      }
    }
  }
  return 0;
}


// address=[0x134f330]
// Decompiled from int __cdecl CDebugFkt::SelectDebugFunc(char a1)
static int (__cdecl*__cdecl CDebugFkt::SelectDebugFunc(char))(int,int) {
  
  int v2; // [esp+4h] [ebp-410h]
  int *v3; // [esp+8h] [ebp-40Ch]
  int *v4; // [esp+Ch] [ebp-408h]
  char Str[1024]; // [esp+10h] [ebp-404h] BYREF

  v2 = -1;
  v4 = &dword_3D7A768;
  if ( a1 )
  {
    while ( v4[1] )
    {
      if ( *(char *)v4 == a1 )
      {
        v2 = ((char *)v4 - (char *)&dword_3D7A768) >> 4;
        break;
      }
      v4 += 4;
    }
  }
  if ( v2 < 0 )
  {
    dword_3D7A760 = -1;
    dword_3ECD9D0 = 0;
    v3 = &dword_3D7AA38;
    if ( a1 )
    {
      while ( v3[1] )
      {
        if ( *(char *)v3 == a1 )
        {
          CGameScriptManager::GetScriptEnv((CGameScriptManager *)g_pScriptMgr);
          CLua::ExecuteString((char *)v3[1]);
          return 0;
        }
        v3 += 2;
      }
    }
    return 0;
  }
  else
  {
    if ( dword_3D7A760 == v2 )
    {
      if ( dword_3ECD9D0 + 1 < v4[3] )
        ++dword_3ECD9D0;
      else
        dword_3ECD9D0 = 0;
    }
    else
    {
      dword_3D7A760 = v2;
      dword_3ECD9D0 = 0;
    }
    if ( v4[3] > 0 )
    {
      memset(Str, 0, sizeof(Str));
      j___snprintf(Str, 0x3FFu, "%s (%i)", (const char *)v4[2], dword_3ECD9D0);
      String::operator=(Str);
    }
    else
    {
      String::operator=((char *)v4[2]);
    }
    return v4[1];
  }
}


// address=[0x134f540]
// Decompiled from const char *CDebugFkt::DebugString()
static char * __cdecl CDebugFkt::DebugString(void) {
  
  return String::c_str((String *)&CDebugFkt::m_sInfo);
}


// address=[0x134f550]
// Decompiled from void *__cdecl CDebugFkt::SetDebugString(const struct String *a1)
static void __cdecl CDebugFkt::SetDebugString(class String const &) {
  
  return String::operator=(&CDebugFkt::m_sInfoText, (int)a1);
}


// address=[0x134f570]
// Decompiled from void __cdecl CDebugFkt::SetFrameCounter(  float a1,  float a2,  float a3,  float a4,  float a5,  float a6,  float a7,  unsigned int a8)
static void __cdecl CDebugFkt::SetFrameCounter(float,float,float,float,float,float,float,unsigned int) {
  
  int v8; // [esp+40h] [ebp-458h]
  int v9; // [esp+48h] [ebp-450h]
  _BYTE v10[28]; // [esp+50h] [ebp-448h] BYREF
  char v11[28]; // [esp+6Ch] [ebp-42Ch] BYREF
  char Buffer[1024]; // [esp+88h] [ebp-410h] BYREF
  int v13; // [esp+494h] [ebp-4h]

  j__sprintf(
    Buffer,
    " - FPS: %3.2f Total: %3.0f%% Logic: %3.0f%% AI: %3.0f%% Script: %3.0f%% Tiling: %3.0f%% Animals: %3.0f%% NetSent: %d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8);
  v9 = String::String(Buffer, -1);
  v13 = 0;
  String::operator=(&CDebugFkt::m_sFrame, v9);
  v13 = -1;
  String::~String((String *)v11);
  v8 = operator+(v10, &CDebugFkt::m_sInfoText, &CDebugFkt::m_sFrame);
  v13 = 1;
  String::operator=(&CDebugFkt::m_sInfo, v8);
  v13 = -1;
  String::~String((String *)v10);
}


// address=[0x3f4558c]
// [Decompilation failed for static class String CDebugFkt::m_sInfoText]

// address=[0x3f455a8]
// [Decompilation failed for static class String CDebugFkt::m_sFrame]

// address=[0x3f455c4]
// [Decompilation failed for static class String CDebugFkt::m_sInfo]

