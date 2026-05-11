#include "GameExports.h"

#include "CBB/CBBSupport.h"

#include "../CGameScriptManager.h"
#include "Pathing/CAlliances.h"
#include "Pathing/CSpiralWalk.h"
#include "Pathing/CWaypoints.h"
#include "Pathing/CAStarTiling.h"
#include "World/helper.h"
#include "World/CWorldManager.h"

#include "Defines/Translations.h"

DWORD __cdecl StringIdFromDefine(char *_spDefineName) {
    // [esp+8h] [ebp-4h]

    if(!_spDefineName || !*_spDefineName)
        return STRINGID_MAX;
    for(auto &[id, name]: s_TranslationDefines) {
        if(!strcmp(_spDefineName, name))
            return id;
    }
    return STRINGID_MAX;
}

// address=[0x1607DC0]
void GameArePlayerAreasConnected() {
    CLua &ScriptEnv = g_pScriptMgr->GetScriptEnv();

    int iPlayer1 = ScriptEnv.GetInt(1);
    int iPlayer2 = ScriptEnv.GetInt(4);
    int iXP1 = ScriptEnv.GetInt(2);
    int iYP1 = ScriptEnv.GetInt(3);
    int iXP2 = ScriptEnv.GetInt(5);
    int iYP2 = ScriptEnv.GetInt(6);

    if(!CAlliances::IsValidUsedPlayerId(iPlayer1))
        return ScriptTracePrintF(2u, "%s Invalid first player id %i!", "SCRIPT: Game.ArePlayerAreasConnected():", iPlayer1);
    if(!CAlliances::IsValidUsedPlayerId(iPlayer2))
        return ScriptTracePrintF(2u, "%s Invalid second player id %i!", "SCRIPT: Game.ArePlayerAreasConnected():", iPlayer2);

    if(!CWorldManager::InWorld(iXP1, iYP1))
        return ScriptTracePrintF(2u, "%s Invalid first position (%i, %i)!", "SCRIPT: Game.ArePlayerAreasConnected():", iXP1, iYP1);

    if(!CWorldManager::InWorld(iXP2, iYP2))
        return ScriptTracePrintF(2u, "%s Invalid second position (%i, %i)!", "SCRIPT: Game.ArePlayerAreasConnected():", iXP2, iYP2);

    if(CAlliances::AllianceId(iPlayer1) != CAlliances::AllianceId(iPlayer2))
        return ScriptTracePrintF(2u, "%s Player %i and %i are not allied!", "SCRIPT: Game.ArePlayerAreasConnected():", iPlayer1, iPlayer2);

    char        bValidPosition = 0;
    CSpiralWalk v1 = CSpiralWalk(iXP1, iYP1, 15);
    while(v1.NextXY(iXP1, iYP1)) {
        int  worldIndexP1 = CWorldManager::Index(iXP1, iYP1);
        bool bIsBlockedLand = CWorldManager::IsBlockedLand(worldIndexP1);
        if(!bIsBlockedLand && CWorldManager::OwnerId(worldIndexP1) == iPlayer1) {
            bValidPosition = 1;
            break;
        }
    }
    if(!bValidPosition)
        return ScriptTracePrintF(2u, "%s Position %i not ok!", "SCRIPT: Game.ArePlayerAreasConnected():", 1);

    bValidPosition = false;
    CSpiralWalk v0 = CSpiralWalk(iXP2, iYP2, 15);
    while(v0.NextXY(iXP2, iYP2)) {
        int  v11 = CWorldManager::Index(iXP2, iYP2);
        char v20 = CWorldManager::IsBlockedLand(v11);
        int  v5 = CWorldManager::OwnerId(v11);
        if(!v20 && v5 == iPlayer2) {
            bValidPosition = 1;
            break;
        }
    }
    if(!bValidPosition)
        return ScriptTracePrintF(2u, "%s Position %i not ok!", "SCRIPT: Game.ArePlayerAreasConnected():", 2);

    int posP1 = Y16X16::PackXYFast(iXP1, iYP1);
    int posP2 = Y16X16::PackXYFast(iXP2, iYP2);

    CWaypoints v24;

    int iFoundPath = CAStarTiling::FindPath(posP1, posP2, v24, iPlayer1 | 0x700);

    ScriptEnv.PushInt(iFoundPath == 1);
}

// address=[0x16097F0]
void GameDefaultGameEndCheck() {
    // [esp+0h] [ebp-Ch]
    // [esp+4h] [ebp-8h]

    CLua &ScriptEnv = g_pScriptMgr->GetScriptEnv();
    char *Str1 = ScriptEnv.GetString(1);
    char *String = ScriptEnv.GetString(2);
    GameEndCheck(Str1, String);
}
