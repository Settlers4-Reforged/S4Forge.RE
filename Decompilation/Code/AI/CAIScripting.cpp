#include "CAIScripting.h"

// Definitions for class CAIScripting

// address=[0x131d980]
// Decompiled from int __thiscall CAIScripting::Init(CAIScripting *this)

void  CAIScripting::Init(void) {
  
  int v1; // eax
  CLua *ScriptEnv; // [esp+8h] [ebp-14h]
  int v5; // [esp+10h] [ebp-Ch]
  char **i; // [esp+14h] [ebp-8h]
  char **j; // [esp+18h] [ebp-4h]
  char **k; // [esp+18h] [ebp-4h]

  CAIScripting::InitPlayerScriptVarsDefaultValues(this);
  ScriptEnv = CGameScriptManager::GetScriptEnv((CGameScriptManager *)g_pScriptMgr);
  CLua::ActivateScriptingEnvironment(ScriptEnv);
  j__lua_beginblock(ScriptEnv, this);
  v1 = j__lua_getglobal("AI");
  if ( !j__lua_isnil(v1) && BBSupportDbgReport(2, "AI\\AI_Script.cpp", 1163, "lua_isnil(lua_getglobal(\"AI\"))") == 1 )
    __debugbreak();
  v5 = j__lua_createtable();
  j__lua_pushobject(v5);
  j__lua_rawsetglobal("AI");
  for ( i = &off_3676548; *i; i += 2 )
  {
    j__lua_pushobject(v5);
    j__lua_pushstring(*i);
    j__lua_pushnumber(COERCE__INT64((double)(int)i[1]));
    j__lua_rawsettable();
  }
  for ( j = &off_3676698; *j; j += 2 )
  {
    j__lua_pushobject(v5);
    j__lua_pushstring(*j);
    j__lua_pushcclosure(j[1], 0);
    j__lua_rawsettable();
  }
  for ( k = &off_3676700; *k; k += 2 )
  {
    j__lua_pushobject(v5);
    j__lua_pushstring(*k);
    j__lua_pushcclosure(k[1], 0);
    j__lua_rawsettable();
  }
  return j__lua_endblock();
}


// address=[0x131db20]
// Decompiled from // Microsoft VisualC 14/net runtime
void __thiscall CAIScripting::Load(CAIScripting *this, struct IS4Chunk *a2)

void  CAIScripting::Load(class IS4Chunk &) {
  
  ;
}


// address=[0x131db30]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall CAIScripting::Save(CAIScripting *this, struct IS4Chunk *a2)

void  CAIScripting::Save(class IS4Chunk &) {
  
  ;
}


// address=[0x131db40]
// Decompiled from unsigned int __thiscall CAIScripting::Adler32(CAIScripting *this, unsigned int a2)

unsigned int  CAIScripting::Adler32(unsigned int) {
  
  double v2; // st7
  _BYTE v4[28]; // [esp+14h] [ebp-4Ch] BYREF
  _BYTE v5[24]; // [esp+30h] [ebp-30h] BYREF
  unsigned int v6; // [esp+48h] [ebp-18h]
  unsigned int v7; // [esp+4Ch] [ebp-14h]
  CAIScripting *v8; // [esp+50h] [ebp-10h]
  int v9; // [esp+5Ch] [ebp-4h]

  v8 = this;
  CPerformanceCounter::CPerformanceCounter((CPerformanceCounter *)v5);
  CPerformanceCounter::Start((CPerformanceCounter *)v5);
  CS4MemChunk::CS4MemChunk((CS4MemChunk *)v4);
  v9 = 0;
  CS4MemChunk::InitSaveCalcSize((CS4MemChunk *)v4);
  (*(void (__thiscall **)(CAIScripting *, _BYTE *))(*(_DWORD *)v8 + 8))(v8, v4);
  CS4MemChunk::InitSaveData((CS4MemChunk *)v4, 1);
  (*(void (__thiscall **)(CAIScripting *, _BYTE *))(*(_DWORD *)v8 + 8))(v8, v4);
  v7 = CS4MemChunk::Adler32((CS4MemChunk *)v4, a2);
  CS4MemChunk::Done((CS4MemChunk *)v4);
  CPerformanceCounter::Measure((CPerformanceCounter *)v5);
  v2 = CPerformanceCounter::TimeMs((CPerformanceCounter *)v5);
  BBSupportTracePrintF(0, "CAIScripting::Adler32(): %.3f ms", v2);
  v6 = v7;
  v9 = -1;
  CS4MemChunk::~CS4MemChunk((CS4MemChunk *)v4);
  return v6;
}


// address=[0x131e8c0]
// Decompiled from CAIScripting *__thiscall CAIScripting::CAIScripting(CAIScripting *this)

 CAIScripting::CAIScripting(void) {
  
  IAIScripting::IAIScripting(this);
  *(_DWORD *)this = &CAIScripting::_vftable_;
  return this;
}


// address=[0x131dc20]
// Decompiled from int __thiscall CAIScripting::InitPlayerScriptVarsDefaultValues(CAIScripting *this)

void  CAIScripting::InitPlayerScriptVarsDefaultValues(void) {
  
  int result; // eax
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  void *v5; // [esp-8h] [ebp-14h]
  void *v6; // [esp-8h] [ebp-14h]
  void *v7; // [esp-8h] [ebp-14h]
  void *v8; // [esp-4h] [ebp-10h]
  void *v9; // [esp-4h] [ebp-10h]
  void *v10; // [esp-4h] [ebp-10h]
  _UNKNOWN **v11; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  result = 0;
  for ( i = 0; i <= 22; ++i )
  {
    v11 = &off_3676210 + 3 * i;
    if ( *v11 )
    {
      dword_3ECC7C8[i] = 0;
      v8 = v11[2];
      v5 = v11[1];
      v2 = (_DWORD *)TStaticConfigIntArrayBase<3>::operator[](0);
      dword_3ECC7C8[i + 23] = sub_131CE10(*v2, v5, v8);
      v9 = v11[2];
      v6 = v11[1];
      v3 = (_DWORD *)TStaticConfigIntArrayBase<3>::operator[](1);
      dword_3ECC7C8[i + 46] = sub_131CE10(*v3, v6, v9);
      v10 = v11[2];
      v7 = v11[1];
      v4 = (_DWORD *)TStaticConfigIntArrayBase<3>::operator[](2);
      result = sub_131CE10(*v4, v7, v10);
      dword_3ECC7C8[i + 69] = result;
    }
    else
    {
      dword_3ECC7C8[i] = 0;
      dword_3ECC7C8[i + 23] = 0;
      dword_3ECC7C8[i + 46] = 0;
      result = 92;
      dword_3ECC7C8[i + 69] = 0;
    }
  }
  return result;
}


