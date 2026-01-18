#ifndef IAIENVIRONMENT_H
#define IAIENVIRONMENT_H

#include "defines.h"

class IAIEnvironment {
public:
    // address=[0x12fd370]
    static unsigned int __cdecl MinutesToTicks(int a1);

    // address=[0x12fd4d0]
    static int __cdecl PackXYFast(int a1, int a2);

    // address=[0x12fd580]
    static unsigned int __cdecl Rand(void);

    // address=[0x12fd770]
    static unsigned int __cdecl TickCounter(void);

    // address=[0x12fd7c0]
    static int __cdecl UnpackXFast(int a1);

    // address=[0x12fd7d0]
    static int __cdecl UnpackYFast(int a1);

    // address=[0x12fd890]
    static bool __cdecl WorldInWorld(int a1, int a2);

    // address=[0x12fd910]
    static int __cdecl WorldIndex(int a1, int a2);

    // address=[0x12fd930]
    static int __cdecl WorldSectorId(int x, int y);

    // address=[0x1301140]
    static bool __cdecl AlliancesAllied(int a1, int a2);

    // address=[0x1301190]
    static bool __cdecl AlliancesIsValidUsedPlayerId(int a1);

    // address=[0x13011b0]
    static int __cdecl AlliancesPlayerAllyBits(int a1);

    // address=[0x13011d0]
    static int __cdecl AlliancesPlayerBit(int a1);

    // address=[0x13011f0]
    static int __cdecl ClipMax(int a1, int a2);

    // address=[0x1303a10]
    static bool __cdecl WorldInWorldPackedXY(int a1);

    // address=[0x1303c40]
    static int __cdecl AlliancesLastPlayerId(void);

    // address=[0x1306400]
    static int __cdecl AlliancesAllianceId(int a1);

    // address=[0x1306420]
    static int __cdecl AlliancesPlayerEnemyBits(int a1);

    // address=[0x1306440]
    static void __cdecl BuildingGetEnsignPosition(int a1, int & a2, int & a3);

    // address=[0x13065c0]
    static void __cdecl EntityGetPosition(int a1, int & a2, int & a3);

    // address=[0x1306a20]
    static void __cdecl UnpackXYFast(int a1, int & a2, int & a3);

    // address=[0x1306a50]
    static int __cdecl WorldEcoSectorIdPackedXY(int a1);

    // address=[0x1306a70]
    static int __cdecl WorldHeight(void);

    // address=[0x1306a80]
    static int __cdecl WorldIndexPackedXY(int a1);

    // address=[0x1306ac0]
    static bool __cdecl WorldIsScree(int a1, int a2);

    // address=[0x1306af0]
    static int __cdecl WorldWidth(void);

    // address=[0x13093c0]
    static int const * __cdecl AlliancesEnemyPlayerIds(int a1);

    // address=[0x1309420]
    static int __cdecl Clip(int a1, int a2, int a3);

    // address=[0x1309470]
    static int __cdecl ClipMin(int a1, int a2);

    // address=[0x1309560]
    static int __cdecl GridDistancePackedXY(int a1, int a2);

    // address=[0x130a4b0]
    static int __cdecl GlobalEcoAIFlags(void);

    // address=[0x130a4e0]
    static class CRandom16 * __cdecl RandomPtr(void);

    // address=[0x130add0]
    static int __cdecl GridDistance(int a1, int a2);

    // address=[0x130adf0]
    static int __cdecl WorldOwnerId(int a1);

    // address=[0x130ae10]
    static int __cdecl WorldSectorId(int a1);

    // address=[0x130ae30]
    static int __cdecl WorldCatapultSectorId(int a1);

    // address=[0x130ae50]
    static int __cdecl WorldEcoSectorId(int a1);

    // address=[0x130ae70]
    static bool __cdecl WorldIsBlockedLand(int a1);

    // address=[0x130ae90]
    static bool __cdecl WorldIsScree(int a1);

    // address=[0x130aec0]
    static int __cdecl EntityObjectType(int a1);

    // address=[0x130aee0]
    static int __cdecl EntityType(int a1);

    // address=[0x130af00]
    static int __cdecl EntityPackedPosition(int a1);

    // address=[0x130af20]
    static int __cdecl EntitySectorId(int a1);

    // address=[0x130af70]
    static int __cdecl EntityUniqueId(int a1);

    // address=[0x130afa0]
    static class CAIEntityInfo * __cdecl EntityGetEntityInfo(int a1, bool a2);

    // address=[0x130b0e0]
    static int __cdecl EntityFlags(int a1);

    // address=[0x130b100]
    static int __cdecl EntityOwnerId(int a1);

    // address=[0x130b120]
    static void __cdecl EntitySetFlagBits(int a1, int a2);

    // address=[0x130b140]
    static void __cdecl EntityClearFlagBits(int a1, int a2);

    // address=[0x130b160]
    static void __cdecl EntityGetEntityTypeAndPosition(int a1, int & a2, int & a3, int & a4);

    // address=[0x130b1d0]
    static enum T_AI_WARRIOR_TYPE __cdecl EntityWarriorType(int a1);

    // address=[0x130b230]
    static void __cdecl EntityGetWarriorTypeAndSectorId(int a1, enum T_AI_WARRIOR_TYPE & a2, int & a3);

    // address=[0x130b2d0]
    static void __cdecl EntityGetWarriorTypeAndPosition(int a1, enum T_AI_WARRIOR_TYPE & a2, int & a3, int & a4);

    // address=[0x130b340]
    static bool __cdecl EntityIsAlive(int a1);

    // address=[0x130b390]
    static bool __cdecl EntityIsReady(int a1);

    // address=[0x130b3e0]
    static bool __cdecl EntityIsAliveAndHasGivenUniqueId(int a1, int a2);

    // address=[0x130b450]
    static bool __cdecl EntityIsAliveAndOfGivenWarriorType(int a1, enum T_AI_WARRIOR_TYPE a2);

    // address=[0x130b4c0]
    static class CAIEntityInfoTower * __cdecl EntityGetEntityInfoTower(int a1);

    // address=[0x130b570]
    static void __cdecl EntitySendCastSpellCommand(int a1, int a2, int a3);

    // address=[0x130b630]
    static void __cdecl MovingEntitySendMoveCommand(int a1, int a2, int a3, bool a4);

    // address=[0x130b710]
    static bool __cdecl MovingEntityIsWaiting(int a1);

    // address=[0x130b750]
    static int __cdecl MovingEntityWalkingState(int a1);

    // address=[0x130b7b0]
    static void __cdecl EntityEnterManakopter(int a1, int a2);

    // address=[0x130b860]
    static void __cdecl EntityManakopterUnload(int a1);

    // address=[0x130b890]
    static void __cdecl EntityManakopterFlyTo(int a1, int a2, int a3);

    // address=[0x130b8c0]
    static bool __cdecl EntityIsManakopterMoving(int a1);

    // address=[0x130b920]
    static int __cdecl EntityFindNearestManakopter(int a1, int a2, int a3, bool a4);

    // address=[0x130b960]
    static bool __cdecl EntityIsShamanOutOfMana(int a1);

    // address=[0x130b9d0]
    static bool __cdecl EntitySendShamanWorkEvent(int a1, int a2);

    // address=[0x130ba90]
    static int __cdecl BuildingPackedEnsignPosition(int a1);

    // address=[0x130bac0]
    static int __cdecl BuildingGetNumberOfBuildings(int a1, int a2, int a3);

    // address=[0x130bae0]
    static int __cdecl BuildingGetNumberOfAllyBuildings(int a1, int a2, int a3);

    // address=[0x130bb50]
    static int __cdecl BuildingGetNumberOfEnemyBuildings(int a1, int a2, int a3);

    // address=[0x130bbc0]
    static int __cdecl BuildingGetFirstBuildingId(int a1, int a2);

    // address=[0x130bbe0]
    static bool __cdecl BuildingIsReadyAndInSector(int a1, int a2);

    // address=[0x130bc70]
    static bool __cdecl BuildingSearchNearestBuildingInSector(int a1, int a2, int a3, int a4, int a5, struct SAIBuildingSearchResult & a6);

    // address=[0x130bf10]
    static int __cdecl BuildingHasInhabitant(int a1);

    // address=[0x130bf60]
    static int __cdecl BuildingGetNextBuildingOfSameType(int a1);

    // address=[0x130bfa0]
    static int __cdecl BuildingGetEnsignSectorId(int a1);

    // address=[0x130bff0]
    static int __cdecl VehicleGetNumberOfVehicles(int a1, int a2, int a3);

    // address=[0x130c010]
    static int __cdecl VehicleGetNumberOfAllyVehicles(int a1, int a2, int a3);

    // address=[0x130c080]
    static int __cdecl VehicleGetNumberOfEnemyVehicles(int a1, int a2, int a3);

    // address=[0x130c0f0]
    static int __cdecl VehicleGetFirstReadyAndCheckedOutVehicleId(int a1, int a2);

    // address=[0x130c150]
    static int __cdecl VehicleGetNextReadyAndCheckedOutVehicleId(int a1);

    // address=[0x130c1d0]
    static void __cdecl VehicleSendQueuedVanishCommand(int a1);

    // address=[0x130c260]
    static int __cdecl SettlerGetNumberOfSettlers(int a1, int a2);

    // address=[0x130c280]
    static int __cdecl SettlerGetFirstReadyAndCheckedOutSettlerId(int a1, int a2);

    // address=[0x130c2e0]
    static int __cdecl SettlerGetNextReadyAndCheckedOutSettlerId(int a1);

    // address=[0x130c360]
    static int __cdecl MagicCurrentManaAmount(int a1);

    // address=[0x130c380]
    static void __cdecl MagicIncreaseMana(int a1, int a2);

    // address=[0x130c3a0]
    static void __cdecl MagicDecreaseMana(int a1, int a2);

    // address=[0x130c3c0]
    static int __cdecl PlayerRace(int a1);

    // address=[0x130c3e0]
    static bool __cdecl EcoSectorCheckId(int a1);

    // address=[0x130c410]
    static bool __cdecl EcoSectorCheckId(int a1, int a2);

    // address=[0x130c450]
    static int __cdecl EcoSectorGetUniqueId(int a1);

    // address=[0x130c490]
    static int __cdecl EcoSectorOwnerId(int a1);

    // address=[0x130c4d0]
    static int __cdecl EcoSectorNumberOfPossibleCarriers(int a1);

    // address=[0x130c510]
    static bool __cdecl EcoSectorGetPosition(int a1, int & a2, int & a3);

    // address=[0x130c580]
    static int __cdecl EcoSectorGetSectorId(int a1);

    // address=[0x130c5d0]
    static int __cdecl EcoSectorGetNextEcoSectorInSector(int a1, int a2);

    // address=[0x130c690]
    static void __cdecl EventSendDarkTribeProductionMsg(int a1, int a2, int a3, int a4);

    // address=[0x130c720]
    static void __cdecl EventSendSettlerProductionMsg(int a1, int a2, int a3, int a4);

    // address=[0x130c780]
    static int __cdecl GetNearestGreenBorderElement(int & a1, int & a2, int a3);

    // address=[0x130cab0]
    static int __cdecl GetNearestNoneBlockedPosition(int & a1, int & a2);

    // address=[0x130cb90]
    static bool __cdecl FindNearestSectorPosition(int & a1, int & a2, int a3, int a4);

    // address=[0x130cc10]
    static int __cdecl FindNearestCatapultSectorPosition(int a1, int a2, int a3, int a4);

    // address=[0x130cc90]
    static int __cdecl CalculateRoughlyDistanceToEnemyPosition(int a1, int a2, int a3);

    // address=[0x130cd90]
    static void __cdecl EvaluateOwnerMap(int a1, int a2, int a3, struct SAIEvalOwnerResults & a4);

    // address=[0x130d090]
    static void __cdecl EvaluateInfluenceMap(int a1, int a2, int a3, struct SAIEvalInfluResults & a4);

    // address=[0x130d190]
    static void __cdecl DbgTracePrintF(char const * Format, ... a2);

    // address=[0x130d200]
    static void __cdecl DbgEnableAITrace(void);

    // address=[0x130d210]
    static void __cdecl DbgEnableAITraceEx(void);

    // address=[0x130d240]
    static void __cdecl DbgDisableAITrace(void);

    // address=[0x130e8c0]
    static int const * __cdecl AlliancesAllyPlayerIds(int a1);

    // address=[0x1314090]
    static void __cdecl SetGlobalEcoAIFlags(int a1);

    // address=[0x13172e0]
    static int __cdecl AlliancesAllPlayersBits(void);

    // address=[0x13172f0]
    static int __cdecl AlliancesLastAllianceId(void);

    // address=[0x1321d20]
    static int __cdecl WorldOwnerId(int a1, int a2);

    // address=[0x1326130]
    static int __cdecl EcoSectorGetFirstEcoSectorInSector(int a1);

    // address=[0x132edc0]
    static int __cdecl WorldCatapultSectorId(int a1, int a2);

    // address=[0x132edf0]
    static int __cdecl WorldCatapultSectorIdPackedXY(int a1);

    // address=[0x132ee10]
    static bool __cdecl WorldIsBlockedLand(int a1, int a2);

    // address=[0x132ee40]
    static bool __cdecl WorldIsBlockedLandPackedXY(int a1);

    // address=[0x132ee60]
    static int __cdecl WorldOwnerIdPackedXY(int a1);

protected:
    // address=[0x130d250]
    static void __cdecl Init(void);

    // address=[0x130d340]
    static void __cdecl Done(void);

    // address=[0x130d370]
    static void __cdecl UpdateTickCounter(void);

private:
    // address=[0x3e95184]
    static class CRandom16 * m_pRandom;

    // address=[0x3e95188]
    static unsigned int m_uTickCounter;

    // address=[0x3e9518c]
    static int m_iWorldWidthHeigth;

    // address=[0x3e95190]
    static int m_iGlobalEcoAIFlags;

};


#endif // IAIENVIRONMENT_H
