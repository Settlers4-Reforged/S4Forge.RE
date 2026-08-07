#if FALSE
#include "CAIScripting.h"

// Definitions for class CAIScripting

// address=[0x131d980]
// Decompiled from int __thiscall CAIScripting::Init(CAIScripting *this)
void  CAIScripting::Init(void) {
  
  int lua_gAI; // eax
  CLua *ScriptEnv; // [esp+8h] [ebp-14h]
  int lua_gAITable; // [esp+10h] [ebp-Ch]
  SLuaDefault *i; // [esp+14h] [ebp-8h]
  CLua::SFuncInfo *j; // [esp+18h] [ebp-4h]
  CLua::SFuncInfo *k; // [esp+18h] [ebp-4h]

  CAIScripting::InitPlayerScriptVarsDefaultValues(this);
  ScriptEnv = CGameScriptManager::GetScriptEnv(g_pScriptMgr);
  CLua::ActivateScriptingEnvironment(ScriptEnv);
  lua_beginblock();
  lua_gAI = lua_getglobal("AI");
  if ( !lua_isnil(lua_gAI) && BBSupportDbgReport(2, "AI\\AI_Script.cpp", 1163, "lua_isnil(lua_getglobal(\"AI\"))") == 1 )
  {
    __debugbreak();
  }
  lua_gAITable = lua_createtable();
  lua_pushobject(lua_gAITable);
  lua_rawsetglobal("AI");
  for ( i = &s_vAILuaDefaults;
        i->m_spName;
        ++i )
  {
    lua_pushobject(lua_gAITable);
    lua_pushstring(i->m_spName);
    lua_pushnumber((double)i->m_iValue);
    lua_rawsettable();
  }
  for ( j = &s_AIDebugFunctions;
        j->m_swpName;
        ++j )
  {
    lua_pushobject(lua_gAITable);
    lua_pushstring(j->m_swpName);
    lua_pushcclosure(j->m_fpFunction, 0);
    lua_rawsettable();
  }
  for ( k = &s_AIFunctions;
        k->m_swpName;
        ++k )
  {
    lua_pushobject(lua_gAITable);
    lua_pushstring(k->m_swpName);
    lua_pushcclosure(k->m_fpFunction, 0);
    lua_rawsettable();
  }
  return lua_endblock();
}


// address=[0x131db20]
// Decompiled from void __thiscall CAIScripting::Load(CAIScripting *this, struct IS4Chunk *a2)
void  CAIScripting::Load(class IS4Chunk & a2) {
  
  ;
}


// address=[0x131db30]
// Decompiled from void __thiscall CAIScripting::Save(CAIScripting *this, struct IS4Chunk *a2)
void  CAIScripting::Save(class IS4Chunk & a2) {
  
  ;
}


// address=[0x131db40]
// Decompiled from int __thiscall CAIScripting::Adler32(CAIScripting *this, unsigned int a2)
unsigned int  CAIScripting::Adler32(unsigned int a2) {
  
  double v2; // st7
  CS4MemChunk v4; // [esp+14h] [ebp-4Ch] BYREF
  CPerformanceCounter v5; // [esp+30h] [ebp-30h] BYREF
  int v6; // [esp+48h] [ebp-18h]
  int v7; // [esp+4Ch] [ebp-14h]
  int v9; // [esp+5Ch] [ebp-4h]

  CPerformanceCounter::CPerformanceCounter(&v5);
  CPerformanceCounter::Start(&v5);
  CS4MemChunk::CS4MemChunk(&v4);
  v9 = 0;
  CS4MemChunk::InitSaveCalcSize(&v4);
  this->Save(this, &v4);
  CS4MemChunk::InitSaveData(&v4, 1);
  this->Save(this, &v4);
  v7 = CS4MemChunk::Adler32(&v4, a2);
  CS4MemChunk::Done(&v4);
  CPerformanceCounter::Measure(&v5.sStartCounter);
  v2 = CPerformanceCounter::TimeMs(&v5);
  BBSupportTracePrintF(0, "CAIScripting::Adler32(): %.3f ms", v2);
  v6 = v7;
  v9 = -1;
  CS4MemChunk::~CS4MemChunk(&v4);
  return v6;
}


// address=[0x131e8c0]
// Decompiled from CAIScripting *__thiscall CAIScripting::CAIScripting(CAIScripting *this)
 CAIScripting::CAIScripting(void) {
  
  IAIScripting::IAIScripting((IAIScripting *)this);
  this->__vftable = (CAIScripting_vtbl *)&CAIScripting::_vftable_;
  return this;
}


// address=[0x131dc20]
// Decompiled from void __thiscall CAIScripting::InitPlayerScriptVarsDefaultValues(CAIScripting *this)
void  CAIScripting::InitPlayerScriptVarsDefaultValues(void) {
  
  int *v1; // eax
  int *v2; // eax
  int *v3; // eax
  int m_iMin; // [esp-8h] [ebp-14h]
  int v5; // [esp-8h] [ebp-14h]
  int v6; // [esp-8h] [ebp-14h]
  int m_iMax; // [esp-4h] [ebp-10h]
  int v8; // [esp-4h] [ebp-10h]
  int v9; // [esp-4h] [ebp-10h]
  SPlayerScriptVar *v10; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0;
        i <= 22;
        ++i )
  {
    v10 = &s_sDefaultScriptVars[i];
    if ( v10->m_pConfig )
    {
      s_iDefaultScriptVars[0][i] = 0;
      m_iMax = v10->m_iMax;
      m_iMin = v10->m_iMin;
      v1 = (int *)TStaticConfigIntArrayBase<3>::operator[](v10->m_pConfig, 0);
      s_iDefaultScriptVars[1][i] = minmax_0(*v1, m_iMin, m_iMax);
      v8 = v10->m_iMax;
      v5 = v10->m_iMin;
      v2 = (int *)TStaticConfigIntArrayBase<3>::operator[](v10->m_pConfig, 1);
      s_iDefaultScriptVars[2][i] = minmax_0(*v2, v5, v8);
      v9 = v10->m_iMax;
      v6 = v10->m_iMin;
      v3 = (int *)TStaticConfigIntArrayBase<3>::operator[](v10->m_pConfig, 2);
      s_iDefaultScriptVars[3][i] = minmax_0(*v3, v6, v9);
    }
    else
    {
      s_iDefaultScriptVars[0][i] = 0;
      s_iDefaultScriptVars[1][i] = 0;
      s_iDefaultScriptVars[2][i] = 0;
      s_iDefaultScriptVars[3][i] = 0;
    }
  }
}


#endif // Already implemented
