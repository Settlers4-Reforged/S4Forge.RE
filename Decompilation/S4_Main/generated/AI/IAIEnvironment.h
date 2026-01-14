#ifndef IAIENVIRONMENT_H
#define IAIENVIRONMENT_H

class IAIEnvironment {
public:
    // address=[0x12fd370]
    static unsigned int __cdecl MinutesToTicks(int);

    // address=[0x12fd4d0]
    static int __cdecl PackXYFast(int,int);

    // address=[0x12fd580]
    static unsigned int __cdecl Rand(void);

    // address=[0x12fd770]
    static unsigned int __cdecl TickCounter(void);

    // address=[0x12fd7c0]
    static int __cdecl UnpackXFast(int);

    // address=[0x12fd7d0]
    static int __cdecl UnpackYFast(int);

    // address=[0x12fd890]
    static bool __cdecl WorldInWorld(int,int);

    // address=[0x12fd910]
    static int __cdecl WorldIndex(int,int);

    // address=[0x12fd930]
    static int __cdecl WorldSectorId(int,int);

    // address=[0x1301140]
    static bool __cdecl AlliancesAllied(int,int);

    // address=[0x1301190]
    static bool __cdecl AlliancesIsValidUsedPlayerId(int);

    // address=[0x13011b0]
    static int __cdecl AlliancesPlayerAllyBits(int);

    // address=[0x13011d0]
    static int __cdecl AlliancesPlayerBit(int);

    // address=[0x13011f0]
    static int __cdecl ClipMax(int,int);

    // address=[0x1303a10]
    static bool __cdecl WorldInWorldPackedXY(int);

    // address=[0x1303c40]
    static int __cdecl AlliancesLastPlayerId(void);

    // address=[0x1306400]
    static int __cdecl AlliancesAllianceId(int);

    // address=[0x1306420]
    static int __cdecl AlliancesPlayerEnemyBits(int);

    // address=[0x1306440]
    static void __cdecl BuildingGetEnsignPosition(int,int &,int &);

    // address=[0x13065c0]
    static void __cdecl EntityGetPosition(int,int &,int &);

    // address=[0x1306a20]
    static void __cdecl UnpackXYFast(int,int &,int &);

    // address=[0x1306a50]
    static int __cdecl WorldEcoSectorIdPackedXY(int);

    // address=[0x1306a70]
    static int __cdecl WorldHeight(void);

    // address=[0x1306a80]
    static int __cdecl WorldIndexPackedXY(int);

    // address=[0x1306ac0]
    static bool __cdecl WorldIsScree(int,int);

    // address=[0x1306af0]
    static int __cdecl WorldWidth(void);

    // address=[0x13093c0]
    static int const * __cdecl AlliancesEnemyPlayerIds(int);

    // address=[0x1309420]
    static int __cdecl Clip(int,int,int);

    // address=[0x1309470]
    static int __cdecl ClipMin(int,int);

    // address=[0x1309560]
    static int __cdecl GridDistancePackedXY(int,int);

    // address=[0x130a4b0]
    static int __cdecl GlobalEcoAIFlags(void);

    // address=[0x130a4e0]
    static class CRandom16 * __cdecl RandomPtr(void);

    // address=[0x130add0]
    static int __cdecl GridDistance(int,int);

    // address=[0x130adf0]
    static int __cdecl WorldOwnerId(int);

    // address=[0x130ae10]
    static int __cdecl WorldSectorId(int);

    // address=[0x130ae30]
    static int __cdecl WorldCatapultSectorId(int);

    // address=[0x130ae50]
    static int __cdecl WorldEcoSectorId(int);

    // address=[0x130ae70]
    static bool __cdecl WorldIsBlockedLand(int);

    // address=[0x130ae90]
    static bool __cdecl WorldIsScree(int);

    // address=[0x130aec0]
    static int __cdecl EntityObjectType(int);

    // address=[0x130aee0]
    static int __cdecl EntityType(int);

    // address=[0x130af00]
    static int __cdecl EntityPackedPosition(int);

    // address=[0x130af20]
    static int __cdecl EntitySectorId(int);

    // address=[0x130af70]
    static int __cdecl EntityUniqueId(int);

    // address=[0x130afa0]
    static class CAIEntityInfo * __cdecl EntityGetEntityInfo(int,bool);

    // address=[0x130b0e0]
    static int __cdecl EntityFlags(int);

    // address=[0x130b100]
    static int __cdecl EntityOwnerId(int);

    // address=[0x130b120]
    static void __cdecl EntitySetFlagBits(int,int);

    // address=[0x130b140]
    static void __cdecl EntityClearFlagBits(int,int);

    // address=[0x130b160]
    static void __cdecl EntityGetEntityTypeAndPosition(int,int &,int &,int &);

    // address=[0x130b1d0]
    static enum T_AI_WARRIOR_TYPE __cdecl EntityWarriorType(int);

    // address=[0x130b230]
    static void __cdecl EntityGetWarriorTypeAndSectorId(int,enum T_AI_WARRIOR_TYPE &,int &);

    // address=[0x130b2d0]
    static void __cdecl EntityGetWarriorTypeAndPosition(int,enum T_AI_WARRIOR_TYPE &,int &,int &);

    // address=[0x130b340]
    static bool __cdecl EntityIsAlive(int);

    // address=[0x130b390]
    static bool __cdecl EntityIsReady(int);

    // address=[0x130b3e0]
    static bool __cdecl EntityIsAliveAndHasGivenUniqueId(int,int);

    // address=[0x130b450]
    static bool __cdecl EntityIsAliveAndOfGivenWarriorType(int,enum T_AI_WARRIOR_TYPE);

    // address=[0x130b4c0]
    static class CAIEntityInfoTower * __cdecl EntityGetEntityInfoTower(int);

    // address=[0x130b570]
    static void __cdecl EntitySendCastSpellCommand(int,int,int);

    // address=[0x130b630]
    static void __cdecl MovingEntitySendMoveCommand(int,int,int,bool);

    // address=[0x130b710]
    static bool __cdecl MovingEntityIsWaiting(int);

    // address=[0x130b750]
    static int __cdecl MovingEntityWalkingState(int);

    // address=[0x130b7b0]
    static void __cdecl EntityEnterManakopter(int,int);

    // address=[0x130b860]
    static void __cdecl EntityManakopterUnload(int);

    // address=[0x130b890]
    static void __cdecl EntityManakopterFlyTo(int,int,int);

    // address=[0x130b8c0]
    static bool __cdecl EntityIsManakopterMoving(int);

    // address=[0x130b920]
    static int __cdecl EntityFindNearestManakopter(int,int,int,bool);

    // address=[0x130b960]
    static bool __cdecl EntityIsShamanOutOfMana(int);

    // address=[0x130b9d0]
    static bool __cdecl EntitySendShamanWorkEvent(int,int);

    // address=[0x130ba90]
    static int __cdecl BuildingPackedEnsignPosition(int);

    // address=[0x130bac0]
    static int __cdecl BuildingGetNumberOfBuildings(int,int,int);

    // address=[0x130bae0]
    static int __cdecl BuildingGetNumberOfAllyBuildings(int,int,int);

    // address=[0x130bb50]
    static int __cdecl BuildingGetNumberOfEnemyBuildings(int,int,int);

    // address=[0x130bbc0]
    static int __cdecl BuildingGetFirstBuildingId(int,int);

    // address=[0x130bbe0]
    static bool __cdecl BuildingIsReadyAndInSector(int,int);

    // address=[0x130bc70]
    static bool __cdecl BuildingSearchNearestBuildingInSector(int,int,int,int,int,struct SAIBuildingSearchResult &);

    // address=[0x130bf10]
    static int __cdecl BuildingHasInhabitant(int);

    // address=[0x130bf60]
    static int __cdecl BuildingGetNextBuildingOfSameType(int);

    // address=[0x130bfa0]
    static int __cdecl BuildingGetEnsignSectorId(int);

    // address=[0x130bff0]
    static int __cdecl VehicleGetNumberOfVehicles(int,int,int);

    // address=[0x130c010]
    static int __cdecl VehicleGetNumberOfAllyVehicles(int,int,int);

    // address=[0x130c080]
    static int __cdecl VehicleGetNumberOfEnemyVehicles(int,int,int);

    // address=[0x130c0f0]
    static int __cdecl VehicleGetFirstReadyAndCheckedOutVehicleId(int,int);

    // address=[0x130c150]
    static int __cdecl VehicleGetNextReadyAndCheckedOutVehicleId(int);

    // address=[0x130c1d0]
    static void __cdecl VehicleSendQueuedVanishCommand(int);

    // address=[0x130c260]
    static int __cdecl SettlerGetNumberOfSettlers(int,int);

    // address=[0x130c280]
    static int __cdecl SettlerGetFirstReadyAndCheckedOutSettlerId(int,int);

    // address=[0x130c2e0]
    static int __cdecl SettlerGetNextReadyAndCheckedOutSettlerId(int);

    // address=[0x130c360]
    static int __cdecl MagicCurrentManaAmount(int);

    // address=[0x130c380]
    static void __cdecl MagicIncreaseMana(int,int);

    // address=[0x130c3a0]
    static void __cdecl MagicDecreaseMana(int,int);

    // address=[0x130c3c0]
    static int __cdecl PlayerRace(int);

    // address=[0x130c3e0]
    static bool __cdecl EcoSectorCheckId(int);

    // address=[0x130c410]
    static bool __cdecl EcoSectorCheckId(int,int);

    // address=[0x130c450]
    static int __cdecl EcoSectorGetUniqueId(int);

    // address=[0x130c490]
    static int __cdecl EcoSectorOwnerId(int);

    // address=[0x130c4d0]
    static int __cdecl EcoSectorNumberOfPossibleCarriers(int);

    // address=[0x130c510]
    static bool __cdecl EcoSectorGetPosition(int,int &,int &);

    // address=[0x130c580]
    static int __cdecl EcoSectorGetSectorId(int);

    // address=[0x130c5d0]
    static int __cdecl EcoSectorGetNextEcoSectorInSector(int,int);

    // address=[0x130c690]
    static void __cdecl EventSendDarkTribeProductionMsg(int,int,int,int);

    // address=[0x130c720]
    static void __cdecl EventSendSettlerProductionMsg(int,int,int,int);

    // address=[0x130c780]
    static int __cdecl GetNearestGreenBorderElement(int &,int &,int);

    // address=[0x130cab0]
    static int __cdecl GetNearestNoneBlockedPosition(int &,int &);

    // address=[0x130cb90]
    static bool __cdecl FindNearestSectorPosition(int &,int &,int,int);

    // address=[0x130cc10]
    static int __cdecl FindNearestCatapultSectorPosition(int,int,int,int);

    // address=[0x130cc90]
    static int __cdecl CalculateRoughlyDistanceToEnemyPosition(int,int,int);

    // address=[0x130cd90]
    static void __cdecl EvaluateOwnerMap(int,int,int,struct SAIEvalOwnerResults &);

    // address=[0x130d090]
    static void __cdecl EvaluateInfluenceMap(int,int,int,struct SAIEvalInfluResults &);

    // address=[0x130d190]
    static void __cdecl DbgTracePrintF(char const *,...);

    // address=[0x130d200]
    static void __cdecl DbgEnableAITrace(void);

    // address=[0x130d210]
    static void __cdecl DbgEnableAITraceEx(void);

    // address=[0x130d240]
    static void __cdecl DbgDisableAITrace(void);

    // address=[0x130e8c0]
    static int const * __cdecl AlliancesAllyPlayerIds(int);

    // address=[0x1314090]
    static void __cdecl SetGlobalEcoAIFlags(int);

    // address=[0x13172e0]
    static int __cdecl AlliancesAllPlayersBits(void);

    // address=[0x13172f0]
    static int __cdecl AlliancesLastAllianceId(void);

    // address=[0x1321d20]
    static int __cdecl WorldOwnerId(int,int);

    // address=[0x1326130]
    static int __cdecl EcoSectorGetFirstEcoSectorInSector(int);

    // address=[0x132edc0]
    static int __cdecl WorldCatapultSectorId(int,int);

    // address=[0x132edf0]
    static int __cdecl WorldCatapultSectorIdPackedXY(int);

    // address=[0x132ee10]
    static bool __cdecl WorldIsBlockedLand(int,int);

    // address=[0x132ee40]
    static bool __cdecl WorldIsBlockedLandPackedXY(int);

    // address=[0x132ee60]
    static int __cdecl WorldOwnerIdPackedXY(int);

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
