#include "../lib/catch_amalgamated.hpp"
#define IMPORT_MA 1
#include "MapAccess.S4.h"
#include "MapAccess/MapAccess.h"

TEST_CASE("Recompiled is same as original", "[MapAccess]") {
    auto sOrigLib = LoadOriginalLibrary();

    REQUIRE(sOrigLib->_GetMapAccessInterfaceVersion() == GetMapAccessInterfaceVersion());

    SECTION("MA_OpenMapFile and basic infos") {
        auto swPath = MA_TEST_FIXTURE_DIR L"/maps/Aeneas.map";

        int iCrcOrig = 0;
        int iErrorOrig = 0;
        sOrigLib->_OpenMapFile((unsigned short *)(swPath), &iCrcOrig, &iErrorOrig, false);

        REQUIRE(iErrorOrig == 0);

        int iCrc = 0;
        int iError = 0;
        MA_OpenMapFile(const_cast<wchar_t *>(swPath), &iCrc, &iError, false);

        REQUIRE(iError == 0);
        REQUIRE(iCrc == iCrcOrig);

        int iWidthHeightOrig = 0;
        int iGameTypeOrig = 0;
        int iMapFlagsOrig = 0;
        int iStartResourcesOrig = 0;
        int iIsEmptyMapOrig = 0;
        sOrigLib->_GetMapData(&iWidthHeightOrig, &iGameTypeOrig, &iMapFlagsOrig, &iStartResourcesOrig, &iIsEmptyMapOrig);

        int iWidthHeight = 0;
        int iGameType = 0;
        int iMapFlags = 0;
        int iStartResources = 0;
        int iIsEmptyMap = 0;
        MA_GetMapData(&iWidthHeight, &iGameType, &iMapFlags, &iStartResources, &iIsEmptyMap);

        CHECK(iWidthHeightOrig == iWidthHeight);
        CHECK(iStartResourcesOrig == iStartResources);
        CHECK(iMapFlagsOrig == iMapFlags);
        CHECK(iGameTypeOrig == iGameType);
        CHECK(iIsEmptyMapOrig == iIsEmptyMap);

        int iPlayerRaceOrig = 0;
        int iPlayerXOrig = 0;
        int iPlayerYOrig = 0;
        unsigned short *pPlayerNameOrig = 0;
        unsigned short *pSetupNameOrig = 0;
        int iPlayerControlOrig = 0;
        int iHasTeamOrig = 0;
        int iPlayerTeamOrig = 0;
        sOrigLib->_GetPlayerData(1, 0, &iPlayerRaceOrig, &iPlayerXOrig, &iPlayerYOrig, &pPlayerNameOrig, &pSetupNameOrig, &iPlayerControlOrig, &iHasTeamOrig, &iPlayerTeamOrig);

        wchar_t *swpPlayerNameOrig = (wchar_t *)pPlayerNameOrig;
        wchar_t *swpSetupNameOrig = (wchar_t *)pSetupNameOrig;

        int iPlayerRace = 0;
        int iPlayerX = 0;
        int iPlayerY = 0;
        wchar_t *swpPlayerName = 0;
        wchar_t *swpSetupName = 0;
        int iPlayerControl = 0;
        int iHasTeam = 0;
        int iPlayerTeam = 0;
        MA_GetPlayerData(1, 0, &iPlayerRace, &iPlayerX, &iPlayerY, &swpPlayerName, &swpSetupName, &iPlayerControl, &iHasTeam, &iPlayerTeam);

        CHECK(iPlayerRaceOrig == iPlayerRace);
        CHECK(iPlayerXOrig == iPlayerX);
        CHECK(iPlayerYOrig == iPlayerY);
        CHECK(iPlayerControlOrig == iPlayerControl);
        CHECK(iHasTeamOrig == iHasTeam);
        CHECK(iPlayerTeamOrig == iPlayerTeam);
    }
}