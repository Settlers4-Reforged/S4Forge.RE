#ifndef GAMESCRIPTS_H
#define GAMESCRIPTS_H

#include "../CLua.h"

extern void GameArePlayerAreasConnected();
extern void GameDefaultGameEndCheck();
extern void GameDefaultPlayerLostCheck();
extern void GameDefaultPlayersLostCheck();
extern void GameDisableLastNPlayersInStatistic();
extern void GameEnableLandExploredCheck();
extern void GameEnemyPlayersLost();
extern void GameFindAnyUnit();
extern void GameGetAmountOfTreesInArea();
extern void GameGetDifficulty();
extern void GameGetNumberOfSquaresWithDarkLand();
extern void GameGetOffenceFightingStrength();
extern void GameHasPlayerLost();
extern void GameIsAlmostAllLandExplored();
extern void GameIsAreaDarkLand();
extern void GameIsAreaGreen();
extern void GameIsAreaOwned();
extern void GameLocalPlayer();
extern void GameNumberOfPlayers();
extern void GamePlayerLost();
extern void GameRandom();
extern void GameRandom100();
extern void GameResetFogging();
extern void GameSetAlliesDontRevealFog();
extern void GameSetConfigVar();
extern void GameSetFightingStrength();
extern void GameShowClock();
extern void GameShowText();
extern void GameTime();
extern void GamePlayerRace();

static CLua::SFuncInfo sGameFunctions[30] = {
    CLua::SFuncInfo{"ArePlayerAreasConnected", GameArePlayerAreasConnected},
    CLua::SFuncInfo{"DefaultGameEndCheck", GameDefaultGameEndCheck},
    CLua::SFuncInfo{"DefaultPlayerLostCheck", GameDefaultPlayerLostCheck},
    CLua::SFuncInfo{"DefaultPlayersLostCheck", GameDefaultPlayersLostCheck},
    CLua::SFuncInfo{"DisableLastNPlayersInStatistic", GameDisableLastNPlayersInStatistic},
    CLua::SFuncInfo{"EnableLandExploredCheck", GameEnableLandExploredCheck},
    CLua::SFuncInfo{"EnemyPlayersLost", GameEnemyPlayersLost},
    CLua::SFuncInfo{"FindAnyUnit", GameFindAnyUnit},
    CLua::SFuncInfo{"GetAmountOfTreesInArea", GameGetAmountOfTreesInArea},
    CLua::SFuncInfo{"GetDifficulty", GameGetDifficulty},
    CLua::SFuncInfo{"GetNumberOfSquaresWithDarkLand", GameGetNumberOfSquaresWithDarkLand},
    CLua::SFuncInfo{"GetOffenceFightingStrength", GameGetOffenceFightingStrength},
    CLua::SFuncInfo{"HasPlayerLost", GameHasPlayerLost},
    CLua::SFuncInfo{"IsAlmostAllLandExplored", GameIsAlmostAllLandExplored},
    CLua::SFuncInfo{"IsAreaDarkLand", GameIsAreaDarkLand},
    CLua::SFuncInfo{"IsAreaGreen", GameIsAreaGreen},
    CLua::SFuncInfo{"IsAreaOwned", GameIsAreaOwned},
    CLua::SFuncInfo{"LocalPlayer", GameLocalPlayer},
    CLua::SFuncInfo{"NumberOfPlayers", GameNumberOfPlayers},
    CLua::SFuncInfo{"PlayerLost", GamePlayerLost},
    CLua::SFuncInfo{"Random", GameRandom},
    CLua::SFuncInfo{"Random100", GameRandom100},
    CLua::SFuncInfo{"ResetFogging", GameResetFogging},
    CLua::SFuncInfo{"SetAlliesDontRevealFog", GameSetAlliesDontRevealFog},
    CLua::SFuncInfo{"SetConfigVar", GameSetConfigVar},
    CLua::SFuncInfo{"SetFightingStrength", GameSetFightingStrength},
    CLua::SFuncInfo{"ShowClock", GameShowClock},
    CLua::SFuncInfo{"ShowText", GameShowText},
    CLua::SFuncInfo{"Time", GameTime},
    CLua::SFuncInfo{"PlayerRace", GamePlayerRace},
};

#endif // GAMESCRIPTS_H