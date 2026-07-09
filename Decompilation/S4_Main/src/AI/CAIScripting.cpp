#include "CAIScripting.h"

#include "CAIConfigIntEx.h"
#include "CAIPlayerScriptVars.h"
#include "CAIPlayersScriptVars.h"
#include "CAIRegions.h"
#include "CBB/CBBSupport.h"
#include "CConfigManager/CConfigManagerPtr.h"
#include "Debug/CPerformanceCounter.h"
#include "File/FilePaths.h"
#include "IAIEnvironment.h"
#include "LoadSave/CS4MemChunk.h"
#include "Logic/Events/CAIEvent.h"
#include "Script/CGameScriptManager.h"
#include "Script/CLua.h"
#include "lua/lua.h"

// Definitions for class CAIScripting

struct SLuaDefault {
    const char *m_spName;
    int m_iValue;
} s_vAILuaDefaults[] = {
    { "DIFFICULTY_LEVEL_EASY", 0 },
    { "DIFFICULTY_LEVEL_NORMAL", 1 },
    { "DIFFICULTY_LEVEL_HARD", 2 },
    { "ATTACK_MODE_DONT_ATTACK", 3 },
    { "ATTACK_MODE_DEFENSIVE", 4 },
    { "ATTACK_MODE_NORMAL", 5 },
    { "ATTACK_MODE_AGGRESSIVE", 6 },
    { "CMD_MOVE_HOME", 7 },
    { "CMD_MOVE_AND_STAY", 8 },
    { "CMD_MOVE_AND_VANISH", 9 },
    { "CMD_SUICIDE_MISSION", 10 },
    0
};

void AILuaGlobalFuncDebugTest();
void AILuaGlobalFuncDebugSaveCfgVars();
void AILuaGlobalFuncDefineRegion();
void AILuaGlobalFuncDeactivateAllPlayerAIs();

CLua::SFuncInfo s_AIDebugFunctions[] = {
    { "DbgTst", AILuaGlobalFuncDebugTest },
    { "DbgSaveCfgVars", AILuaGlobalFuncDebugSaveCfgVars },
    { "DefineRegion", AILuaGlobalFuncDefineRegion },
    { "DeactivateAllPlayerAIs", AILuaGlobalFuncDeactivateAllPlayerAIs },
    nullptr,
};

namespace Lua {
    void SetPlayerVar();
    void AttackNow();
    void DarkTribeUseShamans();
    void DarkTribeUseDarkGardeners();
    void DarkTribeDbgIgnoreFighters();
    void GuardRegion();
    void DbgPrt();
    void CastGratisSpell();
    void SetFlagBits();
    void ClearFlagBits();
    void NewSquad();
} // namespace Lua

// address=[0x03676700]
CLua::SFuncInfo s_AIFunctions[] = {
    { "SetPlayerVar", Lua::SetPlayerVar },
    { "AttackNow", Lua::AttackNow },
    { "DarkTribeUseShamans", Lua::DarkTribeUseShamans },
    { "DarkTribeUseDarkGardeners", Lua::DarkTribeUseDarkGardeners },
    { "DarkTribeDbgIgnoreFighters", Lua::DarkTribeDbgIgnoreFighters },
    { "GuardRegion", Lua::GuardRegion },
    { "DbgPrt", Lua::DbgPrt },
    { "CastGratisSpell", Lua::CastGratisSpell },
    { "SetFlagBits", Lua::SetFlagBits },
    { "ClearFlagBits", Lua::ClearFlagBits },
    { "NewSquad", Lua::NewSquad },
};

// address=[0x131d980]
// Decompiled from int __thiscall CAIScripting::Init(CAIScripting *this)
void CAIScripting::Init(void) {

    CAIScripting::InitPlayerScriptVarsDefaultValues();
    CLua &ScriptEnv = g_pScriptMgr->GetScriptEnv();
    ScriptEnv.ActivateScriptingEnvironment();
    lua_beginblock();

    BB_ASSERT(lua_isnil(lua_getglobal(const_cast<char *>("AI"))))
    int lua_gAITable = lua_createtable();
    lua_pushobject(lua_gAITable);
    lua_rawsetglobal(const_cast<char *>("AI"));
    for(SLuaDefault *i = s_vAILuaDefaults; i->m_spName; ++i) {
        lua_pushobject(lua_gAITable);
        lua_pushstring(const_cast<char *>(i->m_spName));
        lua_pushnumber((double)i->m_iValue);
        lua_rawsettable();
    }
    for(CLua::SFuncInfo *j = s_AIDebugFunctions; j->m_swpName; ++j) {
        lua_pushobject(lua_gAITable);
        lua_pushstring(const_cast<char *>(j->m_swpName));
        lua_pushcclosure(j->m_fpFunction, 0);
        lua_rawsettable();
    }
    for(CLua::SFuncInfo *k = s_AIFunctions; k->m_swpName; ++k) {
        lua_pushobject(lua_gAITable);
        lua_pushstring(const_cast<char *>(k->m_swpName));
        lua_pushcclosure(k->m_fpFunction, 0);
        lua_rawsettable();
    }
    return lua_endblock();
}

// address=[0x131db20]
// Decompiled from void __thiscall CAIScripting::Load(CAIScripting *this, struct IS4Chunk *a2)
void CAIScripting::Load(class IS4Chunk &a2) {

    ;
}

// address=[0x131db30]
// Decompiled from void __thiscall CAIScripting::Save(CAIScripting *this, struct IS4Chunk *a2)
void CAIScripting::Save(class IS4Chunk &a2) {

    ;
}

// address=[0x131db40]
// Decompiled from int __thiscall CAIScripting::Adler32(CAIScripting *this, unsigned int a2)
unsigned int CAIScripting::Adler32(unsigned int a2) {
    CPerformanceCounter v5 = CPerformanceCounter();
    v5.Start();

    CS4MemChunk v4 = CS4MemChunk();

    v4.InitSaveCalcSize();
    this->Save(v4);
    v4.InitSaveData(1);
    this->Save(v4);
    int v6 = v4.Adler32(a2);
    v4.Done();
    v5.Measure();
    BBSupportTracePrintF(0, "CAIScripting::Adler32(): %.3f ms", v5.TimeMs());

    return v6;
}

// address=[0x131e8c0]
// Decompiled from CAIScripting *__thiscall CAIScripting::CAIScripting(CAIScripting *this)
CAIScripting::CAIScripting(void) : IAIScripting() {}

// address=[0x0131CE10]
int __cdecl minmax(int _iValue, int _iMin, int _iMax) {
    if(_iValue < _iMin)
        return _iMin;
    if(_iValue > _iMax)
        return _iMax;
    else
        return _iValue;
}

// address=[0x131dc20]
// Decompiled from int __thiscall CAIScripting::InitPlayerScriptVarsDefaultValues(CAIScripting *this)
void CAIScripting::InitPlayerScriptVarsDefaultValues(void) {
    for(int i = 0; i < std::size(s_sDefaultScriptVars); ++i) {
        SPlayerScriptVar *pDefaultVar = &s_sDefaultScriptVars[i];
        if(pDefaultVar->m_pConfig) {
            auto &cConfig = *pDefaultVar->m_pConfig;
            s_iDefaultScriptVars[0][i] = 0;

            s_iDefaultScriptVars[1][i] = minmax(cConfig[0], pDefaultVar->m_iMin, pDefaultVar->m_iMax);
            s_iDefaultScriptVars[2][i] = minmax(cConfig[1], pDefaultVar->m_iMin, pDefaultVar->m_iMax);
            s_iDefaultScriptVars[3][i] = minmax(cConfig[2], pDefaultVar->m_iMin, pDefaultVar->m_iMax);
        } else {
            s_iDefaultScriptVars[0][i] = 0;
            s_iDefaultScriptVars[1][i] = 0;
            s_iDefaultScriptVars[2][i] = 0;
            s_iDefaultScriptVars[3][i] = 0;
        }
    }
}

// address=[0x0131D8C0]
void AILuaGlobalFuncDebugTest() {
    ;
}

// address=[0x0131D8D0]
void AILuaGlobalFuncDebugSaveCfgVars() {
    CConfigManagerPtr::GetInstance()->SaveSection("AI", (FilePaths::GetUserDirectoryPath() + L"Log\\AICfgVars.txt").c_str());
}

// address=[0x0131D050]
void AILuaGlobalFuncDefineRegion() {

    g_pScriptMgr->GetScriptEnv().ActivateScriptingEnvironment();
    int iRegionId = static_cast<int>(lua_getnumber(lua_lua2C(1)));
    int iX = static_cast<int>(lua_getnumber(lua_lua2C(2)));
    int iY = static_cast<int>(lua_getnumber(lua_lua2C(3)));
    int iRegion = static_cast<int>(lua_getnumber(lua_lua2C(4)));
    if(CAIRegions::IsValidRegionId(iRegionId) && IAIEnvironment::WorldInWorld(iX, iY) && iRegion > 0)
        g_cAIRegions.DefineRegion(iRegionId, iX, iY, iRegion);
}

// address=[0x0131D130]
void AILuaGlobalFuncDeactivateAllPlayerAIs() {
    if(!g_pAI)
        return;

    g_pAI->DeactivateAllPlayerAIs();
}

namespace Lua {
    // address=[0x0131CE50]
    int GetPlayerIdFromArgument1() {
        g_pScriptMgr->GetScriptEnv().ActivateScriptingEnvironment();
        return static_cast<int>(lua_getnumber(lua_lua2C(1)));
    }

    int __cdecl GetArgument(int _iParamIdx) {
        BB_ASSERT(_iParamIdx >= 1)

        int pLuaArg = lua_lua2C(_iParamIdx);
        if(!lua_isnumber(pLuaArg))
            return -1;

        int iValue = static_cast<int>(lua_getnumber(pLuaArg));
        if(iValue < 0)
            return -2;

        return iValue;
    }
    bool __cdecl CheckNewParams(int _iArg, int _iMin, int _iMax, int &_rParam1, int &_rParam2, int &_rParam3) {
        int iArg1 = Lua::GetArgument(_iArg);
        int iArg2 = Lua::GetArgument(_iArg + 1);
        int iArg3 = Lua::GetArgument(_iArg + 2);
        if(iArg1 >= 0)
            iArg1 = minmax(iArg1, _iMin, _iMax);
        if(iArg2 >= 0)
            iArg2 = minmax(iArg2, _iMin, _iMax);
        if(iArg3 >= 0)
            iArg3 = minmax(iArg3, _iMin, _iMax);
        if(iArg1 >= 0) {
            if(iArg2 == -1)
                iArg2 = iArg1;
            if(iArg2 >= 0 && iArg3 == -1)
                iArg3 = iArg2;
        }
        _rParam1 = iArg1;
        _rParam2 = iArg2;
        _rParam3 = iArg3;
        return iArg3 >= 0 && iArg2 >= 0 && iArg1 >= 0;
    }

    // address=[0x131D2A0]
    void SetPlayerVar() {
        int iPlayerId = Lua::GetPlayerIdFromArgument1();
        if(iPlayerId && !IAIEnvironment::AlliancesIsValidUsedPlayerId(iPlayerId)) {
            ScriptTracePrintF(2u, "%s %s Invalid player id %i!", "SCRIPT:", "AI.SetPlayerVar():", iPlayerId);
            return;
        }

        char *spVarName = lua_getstring(lua_lua2C(2));
        if(!spVarName || !*spVarName) {
            ScriptTracePrintF(2u, "%s %s Invalid variable name!", "SCRIPT:", "AI.SetPlayerVar():");
            return;
        }

        T_AI_PLAYER_SCRIPT_VAR_INDEX iDefaultVarId = AI_PLAYER_SCRIPT_VAR_UNKNOWN;
        for(int i = 0; i <= AI_PLAYER_SCRIPT_VAR_LAST; ++i) {
            SPlayerScriptVar *v6 = &s_sDefaultScriptVars[i];
            if(v6->m_pConfig) {
                const char *spConfigName = v6->m_pConfig->Name();
                if(spConfigName) {
                    if(!stricmp(spVarName, spConfigName)) {
                        iDefaultVarId = static_cast<T_AI_PLAYER_SCRIPT_VAR_INDEX>(i);
                        break;
                    }
                }
            }
        }
        if(iDefaultVarId < 0) {
            ScriptTracePrintF(2u, "%s %s Variable \"%s\" not found!", "SCRIPT:", "AI.SetPlayerVar():", spVarName);
            return;
        }

        int iParam1; // [esp+Ch] [ebp-2Ch] BYREF
        int iParam2; // [esp+10h] [ebp-28h] BYREF
        int iParam3; // [esp+14h] [ebp-24h] BYREF

        if(!CheckNewParams(
               3,
               s_sDefaultScriptVars[iDefaultVarId].m_iMin,
               s_sDefaultScriptVars[iDefaultVarId].m_iMax,
               iParam1,
               iParam2,
               iParam3)) {
            ScriptTracePrintF(2u, "%s %s Invalid parameters!", "SCRIPT:", "AI.SetPlayerVar():");
            return;
        }

        if(iPlayerId) {
            g_cAIPlayersScriptVars.SetValue(
                iPlayerId,
                iDefaultVarId,
                iParam1,
                iParam2,
                iParam3);
        } else {
            for(int j = 1; j <= 8; ++j)
                g_cAIPlayersScriptVars.SetValue(
                    j,
                    iDefaultVarId,
                    iParam1,
                    iParam2,
                    iParam3);
        }
    }

    // address=[0x131D580]
    void AttackNow() {
        int iPlayerId = GetPlayerIdFromArgument1();
        if(g_pAI->IsPlayerAIActive(iPlayerId)) {
            int v2 = static_cast<int>(lua_getnumber(lua_lua2C(2)));
            int v3 = static_cast<int>(lua_getnumber(lua_lua2C(3)));
            g_pAI->PostAIEvent(27, iPlayerId, v2, v3);
        }
    }

    // address=[0x131D750]
    void DarkTribeUseShamans() {
        int iPlayerId = GetPlayerIdFromArgument1();
        if(g_pAI->IsPlayerAIActive(iPlayerId)) {
            bool v2 = static_cast<int>(lua_getnumber(lua_lua2C(2))) == 0;
            g_cAIPlayersScriptVars.SetOrClearFlagBits(iPlayerId, 0x20000000, v2);
        }
    }

    // address=[0x131D6D0]
    void DarkTribeUseDarkGardeners() {
        int iPlayerId = GetPlayerIdFromArgument1();
        if(g_pAI->IsPlayerAIActive(iPlayerId)) {
            bool v2 = (int)lua_getnumber(lua_lua2C(2)) == 0;
            g_cAIPlayersScriptVars.SetOrClearFlagBits(iPlayerId, 0x10000000, v2);
        }
    }

    // address=[0x0131D7D0]
    void DarkTribeDbgIgnoreFighters() {
        // eax
        // [esp+4h] [ebp-8h]
        // [esp+Bh] [ebp-1h]

        int iPlayerId = GetPlayerIdFromArgument1();
        if(g_pAI->IsPlayerAIActive(iPlayerId)) {
            bool v2 = (int)lua_getnumber(lua_lua2C(2)) != 0;
            g_cAIPlayersScriptVars.SetOrClearFlagBits(iPlayerId, 0x40000000, v2);
        }
    }

    // address=[0x0131D850]
    void GuardRegion() {
        // eax
        // [esp+0h] [ebp-8h]
        // [esp+4h] [ebp-4h]

        int iPlayerId = GetPlayerIdFromArgument1();
        if(IAIEnvironment::AlliancesIsValidUsedPlayerId(iPlayerId)) {
            int v2 = (int)lua_getnumber(lua_lua2C(2));
            if(CAIRegions::IsValidRegionId(v2))
                g_cAIRegions.SetPlayerRegionFlagBits(iPlayerId, v2, 1);
        }
    }

    // address=[0x131D550]
    void DbgPrt() {
        int iPlayerId = GetPlayerIdFromArgument1();
        g_pAI->DbgPrint(iPlayerId, iPlayerId);
    }

    // address=[0x0131D4B0]
    void CastGratisSpell() {
        int iPlayerId = GetPlayerIdFromArgument1();
        if(g_pAI->IsPlayerAIActive(iPlayerId)) {
            int v3 = static_cast<int>(lua_getnumber(lua_lua2C(2)));
            unsigned int v4 = static_cast<int>(lua_getnumber(lua_lua2C(3)));
            unsigned int v5 = static_cast<int>(lua_getnumber(lua_lua2C(4)));
            CMagic::CastSpell(iPlayerId, v3, v4, v5, 1u, 0);
        }
    }

    // address=[0x0131D610]
    void SetFlagBits() {
        int iPlayerId = GetPlayerIdFromArgument1();
        if(g_pAI->IsPlayerAIActive(iPlayerId)) {
            int v1 = static_cast<int>(lua_getnumber(lua_lua2C(2)));
            g_cAIPlayersScriptVars.SetFlagBits(iPlayerId, v1);
        }
    }

    // address=[0x0131D670]
    void ClearFlagBits() {
        // eax
        // [esp+0h] [ebp-8h]
        // [esp+4h] [ebp-4h]

        int PlayerIdFromArgument1 = GetPlayerIdFromArgument1();
        if(g_pAI->IsPlayerAIActive(PlayerIdFromArgument1)) {
            int v1 = static_cast<int>(lua_getnumber(lua_lua2C(2)));
            g_cAIPlayersScriptVars.ClearFlagBits(PlayerIdFromArgument1, v1);
        }
    }

    // address=[0x131D150]
    void NewSquad() {
        int iPlayerId = GetPlayerIdFromArgument1();
        int v7 = static_cast<int>(lua_getnumber(lua_lua2C(2)));
        unsigned int v5 = static_cast<int>(lua_getnumber(lua_lua2C(3)));
        unsigned int v6 = static_cast<int>(lua_getnumber(lua_lua2C(4)));
        if(!IAIEnvironment::AlliancesIsValidUsedPlayerId(iPlayerId)) {
            ScriptTracePrintF(2u, "%s %s Invalid player id %i!", "SCRIPT:", "AI.NewSquad():", iPlayerId);
            return;
        }
        if(v7 != 7 && v7 != 8 && v7 != 13 && v7 != 9) {
            ScriptTracePrintF(2u, "%s %s Invalid command %i!", "SCRIPT:", "AI.NewSquad():", v7);
            return;
        }
        if((v7 == 8 || v7 == 13) && !IAIEnvironment::WorldInWorld(v5, v6)) {
            ScriptTracePrintF(2u, "%s %s Invalid target position (%i, %i)!", "SCRIPT:", "AI.NewSquad():", v5, v6);
            return;
        }

        unsigned int v3 = CAIEvent::Pack(v5, v6);
        g_pAI->PostAIEvent(28, iPlayerId, v7, v3);
    }
} // namespace Lua