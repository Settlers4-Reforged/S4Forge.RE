#include "GameExports.h"

#include "CBB/CBBSupport.h"

#include "../CGameScriptManager.h"
#include "Pathing/CAlliances.h"
#include "Pathing/CSpiralWalk.h"
#include "Pathing/CWaypoints.h"
#include "Pathing/CAStarTiling.h"
#include "World/helper.h"
#include "World/CWorldManager.h"

void GameArePlayerAreasConnected()
{
    int Path;           // [esp+20h] [ebp-A8h]
    int v3;             // [esp+24h] [ebp-A4h]
    int v4;             // [esp+28h] [ebp-A0h]
    int v5;             // [esp+2Ch] [ebp-9Ch]
    int v6;             // [esp+30h] [ebp-98h]
    int v7;             // [esp+34h] [ebp-94h]
    int v8;             // [esp+38h] [ebp-90h]
    BOOL v9;            // [esp+3Ch] [ebp-8Ch]
    BOOL v10;           // [esp+40h] [ebp-88h]
    int v11;            // [esp+44h] [ebp-84h]
    int v12;            // [esp+48h] [ebp-80h]
    int Int;            // [esp+4Ch] [ebp-7Ch]
    int iPlayerA;       // [esp+50h] [ebp-78h]
    int v15;            // [esp+54h] [ebp-74h] BYREF
    int v16;            // [esp+58h] [ebp-70h] BYREF
    int v17;            // [esp+5Ch] [ebp-6Ch] BYREF
    int v18;            // [esp+60h] [ebp-68h] BYREF
    char v20;           // [esp+68h] [ebp-60h]
    char IsBlockedLand; // [esp+69h] [ebp-5Fh]
    char v22;           // [esp+6Ah] [ebp-5Eh]
    char v23;           // [esp+6Bh] [ebp-5Dh]
    CWaypoints v24;      // [esp+6Ch] [ebp-5Ch] BYREF

    CLua &ScriptEnv = g_pScriptMgr->GetScriptEnv();
    iPlayerA = ScriptEnv.GetInt(1);
    Int = ScriptEnv.GetInt(4);
    v17 = ScriptEnv.GetInt(2);
    v18 = ScriptEnv.GetInt(3);
    v15 = ScriptEnv.GetInt(5);
    v16 = ScriptEnv.GetInt(6);
    v9 = 0;
    if (CAlliances::IsValidUsedPlayerId(iPlayerA))
    {
        if (CAlliances::IsValidUsedPlayerId(Int))
        {
            if (CWorldManager::InWorld(v17, v18))
            {
                if (CWorldManager::InWorld(v15, v16))
                {
                    v8 = CAlliances::AllianceId(iPlayerA);
                    v7 = CAlliances::AllianceId(Int);
                    if (v8 == v7)
                    {
                        v23 = 0;
                        v22 = 0;
                        CSpiralWalk v1 = CSpiralWalk(v17, v18, 15);
                        while (v1.NextXY(v17, v18))
                        {
                            v12 = CWorldManager::Index(v17, v18);
                            IsBlockedLand = CWorldManager::IsBlockedLand(v12);
                            v6 = CWorldManager::OwnerId(v12);
                            if (!IsBlockedLand && v6 == iPlayerA)
                            {
                                v23 = 1;
                                break;
                            }
                        }
                        if (v23)
                        {
                            CSpiralWalk v0 = CSpiralWalk(v15, v16, 15);
                            while (v0.NextXY(v15, v16))
                            {
                                v11 = CWorldManager::Index(v15, v16);
                                v20 = CWorldManager::IsBlockedLand(v11);
                                v5 = CWorldManager::OwnerId(v11);
                                if (!v20 && v5 == Int)
                                {
                                    v22 = 1;
                                    break;
                                }
                            }
                            if (v22)
                            {
                                v3 = Y16X16::PackXYFast(v17, v18);
                                v4 = Y16X16::PackXYFast(v15, v16);
                                Path = CAStarTiling::FindPath(v3, v4, v24, iPlayerA | 0x700);
                                v10 = Path == 1;
                                v9 = v10;
                            }
                            else
                            {
                                ScriptTracePrintF(2u, "%s Position %i not ok!", "SCRIPT: Game.ArePlayerAreasConnected():", 2);
                            }
                        }
                        else
                        {
                            ScriptTracePrintF(2u, "%s Position %i not ok!", "SCRIPT: Game.ArePlayerAreasConnected():", 1);
                        }
                    }
                    else
                    {
                        ScriptTracePrintF(
                            2u,
                            "%s Player %i and %i are not allied!",
                            "SCRIPT: Game.ArePlayerAreasConnected():",
                            iPlayerA,
                            Int);
                    }
                }
                else
                {
                    ScriptTracePrintF(
                        2u,
                        "%s Invalid second position (%i, %i)!",
                        "SCRIPT: Game.ArePlayerAreasConnected():",
                        v15,
                        v16);
                }
            }
            else
            {
                ScriptTracePrintF(
                    2u,
                    "%s Invalid first position (%i, %i)!",
                    "SCRIPT: Game.ArePlayerAreasConnected():",
                    v17,
                    v18);
            }
        }
        else
        {
            ScriptTracePrintF(2u, "%s Invalid second player id %i!", "SCRIPT: Game.ArePlayerAreasConnected():", Int);
        }
    }
    else
    {
        ScriptTracePrintF(2u, "%s Invalid first player id %i!", "SCRIPT: Game.ArePlayerAreasConnected():", iPlayerA);
    }
    ScriptEnv.PushInt(v9);
}