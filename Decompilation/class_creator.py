import ida_hexrays
import ida_bytes
import ida_typeinf
import idautils
import idc
import os
import re
from collections import defaultdict

# ------------------ CONFIG ------------------

IGNORE_KEYWORDS = [
    "call std::",
    "decl std::",
    "::TArgv",
    "std::SIMPL_NS",

    "Concurrency::details::",
    "Concurrency::Context",
    "Concurrency::context_",
    "Concurrency::critical_section",
    "Concurrency::event",
    "Concurrency::improper",
    "Concurrency::invalid",
    "Concurrency::task",
    "Concurrency::unsupported",
    "Concurrency::reader",
    "Concurrency::Scheduler",
    "Concurrency::scheduler",
    "Concurrency::default",
    "Concurrency::IVirtualProcessorRoot",
    "Concurrency::location",
    "Concurrency::message",
    "Concurrency::nested_",
    "Concurrency::missing_",
    "Concurrency::operation_",
    "Concurrency::DispatchState",
    "Concurrency::IScheduler",
    "Concurrency::ISchedulerProxy",
    "Concurrency::IThreadProxy",
    "Concurrency::ITopologyExecutionResource",
    "Concurrency::ITopologyNode",
    "Concurrency::IUMSCompletionList",
    "Concurrency::IUMSScheduler",
    "Concurrency::IUMSThreadProxy",
    "Concurrency::IUMSUnblockNotification",
    "Concurrency::IExecutionContext",
    "Concurrency::IExecutionResource",
    "bad_target",
    "UnDecorator",
    "Replicator",
    "type_info",

    "scoped_fp_state_reset",

    "FAProfiler",
    "FAReader",

    "ISampleGrabberCB",

    "__imp",
    "_png_",

    "eal_",
    "EalFileLibInitializer",
    "EalInputLibInitializer",
    "EalInterfaceInitializer",
    "EalJobLibInitializer",
    "EalLogLibInitializer",
    "EalMemLibInitializer",
    "EalNetLibInitializer",
    "SimplLockWrapper",
    "SimplLockWrapper",
    "SimplScopedLock",

    "FLDirListStruct",
    "FLFHandleStruct",
    "FLFileListStruct",
    "FLHeaderFileStruct",
    "FLHeaderStruct",
    "FLIntHandleStruct",
    "FLLibraryFileStruct",
    "FLMemDirStruct",
    "FLMemFileStruct",
    "FLPathListStruct",

    "environment_strings_traits",

    "storm::",
    "IMMNotificationClient",
    "IControlChangeNotify",
    "ubiservices",
    "CSetReportHook",
    "UPlay",
    "ATL",
    "_AIL",
    "__crt",
    "__acrt",
    "__scrt",
    "_atexit",
    "__ExceptionPtr",
    "_variant_t",
    "_HeapManager",
    "MemoryAllocator",
    "_LocaleUpdate",
    "_com_error",
    "_D3DTLVERTEX",
    "std::locale",
    "std::ios_base",
    "TNode",
    "stdext",
    "AllocCounter",
    "MemoryHeader",

    "::`vftable'",
    "RTTI ",
    "`string'",
    "Data_t",

    "vector constructor iterator",
    "scalar deleting destructor",
    "vector deleting destructor",
    "[thunk]"
]

REPLACEMENTS = {
    "__thiscall": "",
    "class std::basic_istream<char,struct std::char_traits<char> >": "std::istream",
    "class std::basic_ostream<char,struct std::char_traits<char> >": "std::ostream",
    "class std::basic_iostream<char,struct std::char_traits<char> >": "std::iostream",
    "class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >": "std::string",

    "class std::basic_istream<wchar_t,struct std::char_traits<wchar_t> >": "std::wistream",
    "class std::basic_ostream<wchar_t,struct std::char_traits<wchar_t> >": "std::wostream",
    "class std::basic_iostream<wchar_t,struct std::char_traits<wchar_t> >": "std::wiostream",
    "class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class std::allocator<wchar_t> >": "std::wstring",
}

FOLDER_MAP =  {
    "AI/": [
        "CParam",
        "CParameterSet",
        "CAIAgent",
        "CAIAgentAttack",
        "CAIAgentEvalDefence",
        "CAIAgentEvalOffence",
        "CAIAgentEvaluation",
        "CAIAgentGardeners",
        "CAIAgentGeologists",
        "CAIAgentGlobalSuicideMission",
        "CAIAgentIntruderCombat",
        "CAIAgentMovingHome",
        "CAIAgentPioneers",
        "CAIAgentPlayerBase",
        "CAIAgentRecruitment",
        "CAIAgentSquads",
        "CAIAgentSuicideMissions",
        "CAIAgentTaskScheduler",
        "CAIAgentThieves",
        "CAIAgentTowerOccupation",
        "CAIAgentWarMachines",
        "CAIBuildingEnsignPositionIterator",
        "CAIChambers",
        "CAIConfigInt",
        "CAIConfigIntEx",
        "CAIDefenceGoals",
        "CAIEcoSectorAIEx",
        "CAIEcoSpecialBuildingInfos",
        "CAIEnemySettlerInSectorIterator",
        "CAIEntityInfo",
        "CAIEntityInfoEx",
        "CAIEntityInfoTower",
        "CAIEventQueue",
        "CAIGoal",
        "CAIGoalCache",
        "CAIMain",
        "CAINormalPlayerAI",
        "CAINormalSectorAI",
        "CAINormalSectorAgent",
        "CAIPlayerAI",
        "CAIPlayerEvaluation",
        "CAIPlayerEvaluations",
        "CAIPlayerScriptVars",
        "CAIPlayersScriptVars",
        "CAIRegion",
        "CAIRegions",
        "CAIResourceData",
        "CAIResourceEvalParams",
        "CAIResourceMap",
        "CAIScheduler",
        "CProductivityControll",
        "CAIScripting",
        "CAISectorAI",
        "CAIShaman",
        "CAITaskForce",
        "CAITaskForceEx",
        "CAITaskForceGroup",
        "CAITaskForcePriests",
        "CAITaskForcePriestsTrojan",
        "CAITaskForceShamans",
        "CAITaskForceSquad",
        "CAITaskForces",
        "CAIVWVector",
        "CAIWatchTower",
        "CAIWatchTowerEx",
        "CAIWatchTowers",
        "CAI_Ecosector_Grid_Iterator",
        "CSiedlerAI",
        "CQuickScan",
        "CTaskForceWarMachines",
        "IAIDarkTribeEcoAI",
        "IAIDifficultyLevels",
        "IAIEcoManager",
        "IAIEcoSectorAI",
        "IAIEnvironment",
        "IAIEventQueue",
        "IAIMain",
        "IAIScripting",
        "IAISectorAI",
        "IAIShaman",
        "IAIUnknown",
        "IAIWatchTowers",
        "IAI_Module",
        "CSolution",
        "CSolutionEdge",
        "CSolutionSet",
        "CSolutionTree",
    ],

    "AI/DarkTribe/": [
        "CAIAgentDarkTribeAttack",
        "CAIAgentDarkTribeDarkGardeners",
        "CAIAgentDarkTribeManakopterHalls",
        "CAIAgentDarkTribeManakopters",
        "CAIAgentDarkTribeMushroomFarms",
        "CAIAgentDarkTribeRecruitment",
        "CAIAgentDarkTribeShamans",
        "CAIAgentDarkTribeSquadManager",
        "CAIDarkTribe",
        "CAIDarkTribePlayerAI",
        "CAIDarkTribeSectorAI",
        "CAIDarkTribeSectorAgent",
    ],

    "AI/Eco/": [
        "CEcoSectorAI",
    ],

    "AI/EcoManager/": [
        "CEMD",
        "CEMLD",
        "CEMTD",
        "CEcoManager",
        "CEcoManagerLeaf",
        "CEcoManagerTree",
    ],

    "AI/TaskForce/": [
        "CAITaskForce",
        "CAITaskForceClassWalk",
        "CAITaskForceDarkGardeners",
        "CAITaskForceEx",
        "CAITaskForceGroup",
        "CAITaskForceManakopters",
        "CAITaskForcePriests",
        "CAITaskForcePriestsMaya",
        "CAITaskForcePriestsRoman",
        "CAITaskForcePriestsTrojan",
        "CAITaskForcePriestsViking",
        "CAITaskForceReservoir",
        "CAITaskForceShamans",
        "CAITaskForceSquad",
        "CAITaskForces",
    ],

    "CBB/": [
        "BBSupportLib",
        "CBBException",
        "CBBFileException",
        "CBBMemoryException",
        "CS4ErrorException",
        "CS4InvalidMapException",
        "CBBObject",
        "CBBObjectTracer",
        "CBBSStackTrace",
        "CBBSupportLogFile",
        "CBBSupportMemoryCleanup",
        "CBBSupportStructuredExceptionHandlerCleanup",
        "CBBSupportTraceFile",
        "CBBSupportTraceFilePtr",
        "IBBSupportTraceFile",
    ],

    "CConfigManager/": [
        "CConfigFile",
        "IConfigManager",
        "CConfigManager",
        "CConfigManagerPtr",
        "CConfigSection",
    ],

    "CConfigManager/Var/": [
        "CConfigVar",
        "CConfigVarFloat",
        "CConfigVarInt",
        "CConfigVarIntArray",
        "CConfigVarString",
        "CDynamicConfigVar",
        "CStaticConfigVar",
        "CStaticConfigVarInt",
    ],

    "Compression/": [
        "HuffStat",
        "LZBuffer",
        "LZHLCompressor",
        "LZHLDecoderStat",
        "LZHLDecompressor",
        "LZHLEncoder",
        "LZHLEncoderStat",
    ],

    "Debug/": [
        "CDebugFkt",
        "CDebugGridTest",
        "CDebugInfo",
        "CErrorMessageId",
        "IErrorMessages",
        "CErrorMessages",
        "CProfile",
        "CPerformanceCounter",
        "CTrace",
        "IMessageTracer",
    ],

    "File/": [
        "CFile",
        "CFileEx",
        "CFileLibrary",
        "CFileMgr",
        "IFSNode",
        "IFileEx",
    ],

    "Gfx/": [
        "CGfxManager",
        "CGrabber",
        "CFixCursor",
        "CBlitFX",
        "CColorGradient",
        "CDirCache",
    ],

    "Gfx/Compiler/": [
        "CRTComp",
        "IRTComp",
        "IA_ColorReduction",
        "IA_ColorReduction_Color",
        "IA_ColorReduction_Node",
    ],

    "Gfx/D3D/": [
        "CInterfaceD3D",
        "CCacheManager",
        "CCachePageManager",
        "CUploadCachePageManager",
        "CSurface",
        "CSurfaceDescription",
        "CSurfaceV3",
        "CSurfaceV7",
    ],

    "Gfx/Render/": [
        "SGfxRenderConfiguration",
        "IGfxEffects",
        "IEffects",
        "IGfxEngine",
    ],

    "Info/": [
        "CAddSoldierSideBarInfo",
        "CAddToolSideBarInfo",
        "CAddVehicleBarInfo",
        "CBuildingInfo",
        "CBuildingInfoEx",
        "CBuildingSiteInfo",
        "CChatInfo",
        "CEconomyGameInfo",
        "CExtendedMenuInfo",
        "CEyeCatcherBarInfo",
        "CFerryLoadInfo",
        "CFreeCarrierInfo",
        "CGoodDistributionInfo",
        "CGoodsStatisticInfo",
        "CGroupSideBarInfo",
        "CInstallationInfo",
        "CMagicSpellSideBarInfo",
        "CPlayerTradeInfo",
        "CPlayerInfo",
        "CPortGoodsOutBarInfo",
        "CPortGoodsTradeBarInfo",
        "CPortInfo",
        "CResourceCollectorInfo",
        "CResourceUpgradeInfo",
        "CSmallTempleInfo",
        "CSoldierInfo",
        "CSpecialistsInfo",
        "CStorageInfo",
        "CStorageSideBarInfo",
        "CTimeInfo",
        "CTransportpriorityInfo",
        "CVehicleInfo",
        "CVehicleLoadInfo",
        "CVehicleProductionInfo",
        "CWeaponSideBarInfo",
        "CSettlerProductionInfo",
        "CSettlerStatisticInfo",
        "CBarracksInfo",
        "CMilitaryBuildingInfo",
        "CTradeBuildingInfo",
        "SBuildingInfos",
        "IInstallationInfo",
        "SEnvironmentInfo",
        "SPlayerInfo",
        "SSettlerInfos",
    ],

    "LoadSave/": [
        "IS4Chunk",
        "IS4ChunkObject",
        "BB_SIV_ChunkHeader",
        "CGameChunkGeneral",
        "CUserLogoChunk",
        "CMapFile",
        "CMapCheck",
        "CS4MemChunk",
        "SSaveData",
        "SSaveEntry",
        "CSaveFile",
        "CSaveGameContext",
        "CSavedPlayer",
        "CPersistence",
        "CUnique",
        "CBlob",
        "CLandBlob",
        "CHeightBlob",
        "CMountainBlob",
        "CPreviewBlob",
        "CObjectBlob",
        "Error",
        "SerialError",
        "CRCTable",
    ],

    "Logic/EcoSector/": [
        "CEcoSector",
        "CEcoSectorMgr",
    ],

    "IO/": [
        "ICDDrive",
        "IClipboard",
        "CCDDrive",
        "CClipboard",
        "IRegistry",
        "CRegistry",
    ],

    "Logic/": [
        "CBuildingSupplyPriority",
        "CDarkTribe",
        "CEffect",
        "CEffects",
        "CEndStatistic",
        "CFutureEvents",
        "CGoodTransportPriority",
        "CInfoExchange",
        "CInfoExchangeEx",
        "CInfoExchangeInt",
        "CInputProcessor",
        "CInternationalTrader",
        "CTile",
        "CTileIdRef",
        "CTiles",
        "CReserveDatabase",
        "CReserveEntry",
        "CRandom16",
        "CRandom16Ex",
        "CRequire",
        "CSchedule",
        "IScheduleEntry",
        "ScheduleGroup",
        "CLogic",
        "CLogicRingBuffer",
        "CMagic",
        "CMagicSpell",
        "CNetInputProcessor",
        "CPlayerGameData",
        "CStatistic",
        "CStatisticArchive",
        "CTransportMgr",
        "CAttackMsgFilter",
        "CAttackMsgList",
        "SPlayerStatistic",
        "INotifyFilter",
    ],

    "Logic/Events/": [
        "CAIEvent",
        "CBuildingEvent",
        "CEntityEvent",
        "CEvn_Event",
        "CEvn_HandleList",
        "CEvn_Logic",
        "CEvn_Window",
        "CExpandationEvent",
        "CGameStateEventHandle",
        "CGuiEventHandler",
        "CInvokeEvent",
        "CMainProblemSolveEvent",
        "CNet_Event",
        "CScriptEventRequests",
        "CSubProblemSolveEvent",
        "CVC_EventHandle",
        "IEventEngine",
        "IEventHandler",
        "IEvn_Handle",
        "IFutureEvents",
    ],

    "Main/": [
        "CGameRun",
        "CGameSettings",
        "CGameState",
        "CGameData",
        "CGuiGameState",
        "CGameStateHandler",
        "CGameType",
        "CMapGeneratorHost",
        "CSoundManager",
        "CStringEngineEx",
        "CTextMsgHandler",
        "CS4DefineNames",
        "CDefineTranslator",
        "IMapGeneratorHost",
    ],

    "Main/Players/": [
        "CPlayerManager",
        "CPlayerData",
        "CPlayerIterator",
        "CPlayerMagicData",
        "CPlayerStatisticData",
    ],

    "Main/Addons/": [
        "CAddOn",
        "IExtraCD",
        "CExtraCD",
        "CMissionCD",
        "CMissionCD2",
        "CMissionCD3",
    ],

    "Main/States/": [
        "CStateAOBriefing",
        "CStateAOCampaignBonus",
        "CStateAOCampaignMayan",
        "CStateAOCampaignRoman",
        "CStateAOCampaignTrojan",
        "CStateAOCampaignViking",
        "CStateAOCampaigns",
        "CStateAOCampaignsSettle",
        "CStateAOSplash",
        "CStateBriefing",
        "CStateCampaign3X3",
        "CStateCampaignDark",
        "CStateCredits",
        "CStateEcoStatistic",
        "CStateEndStatistic",
        "CStateGame",
        "CStateLoadGame",
        "CStateLoadType",
        "CStateLobbyConnect",
        "CStateLobbyGameSettings",
        "CStateLobbyLoadMP",
        "CStateLobbyMapSettings",
        "CStateLobbyMultiplayerType",
        "CStateLocalType",
        "CStateMD2Briefing",
        "CStateMD2Campaigns",
        "CStateMDBriefing",
        "CStateMDCampaignMayan",
        "CStateMDCampaignRoman",
        "CStateMDCampaignViking",
        "CStateMDCampaigns",
        "CStateMDCampaignsEcoConflict",
        "CStateMDRandomMapParameters",
        "CStateMainMenu",
        "CStateMessageBox",
        "CStateSlideshow",
        "CStateTutorial",
        "CStateVictoryScreen",
        "CStateVideo",
        "CStateXMD3Briefing",
        "CStateXMD3Campaigns",
        "CGame_InitNetwork",
        "CLanLobbyConnect",
        "CLanLobbyGameSettings",
        "CLanLobbyMapSettings",
    ],

    "Main/UI/": [
        "IGuiEngine",
        "CToolTip",
        "CToolTipExt",
        "CSlideshow",
        "CScrollMultiline",
        "CStringEngine",
    ],

    "Main/UI/Menus/": [
        "SGFXINFO",
        "CGUIWrapper",
        "CGuiChatMsgList",
        "CGuiMsgList",
        "CMinimapHandler",
        "CProductionDataTab",
        "CProductionMakroData",
        "CProductionTab",
        "CTutorial",
    ],

    "MapObjects/": [
        "CEntityTask",
        "CEntityToDoListMgr",
        "CExpandationManagerTask",
        "CGroupDestinations",
        "SPoint",
        "CY6R1X6",
        "CSurroundingHexPointsIndices",
        "CSpiralOffsets",
        "CHeightAndTypeTable",
        "CFindEnemyFighters",
        "CCenter",
        "CG24Closed1Parent16",
        "CG24Closed1Parent7",
        "SSurroundingPoint8",
        "CHexIndices",
        "CGroupMgr",
        "CGroupWalking",
        "CRandomMaps",
        "IRandomMaps",
        "CMapObjectMgr",
        "CMaterialManagerTask",
        "CObserverList",
        "CPeopleManagerTask",
        "CResourceManagerTask",
        "CLandscapeColorProperties",
        "CLandscapeProperties",
        "IFilterEntry",
        "CFilter",
        "CFilterCustomer",
        "CFilterNearCustomer",
        "CFilterPlaceScoring",
        "CFilterResourceLandscape",
        "CResourceFilter",
        "CStdCargoCounter",
        "COwnerMap",
        "COwnerMapEx",
        "COwnerMapExEx",
        "CStone",
        "CTree",
        "IResourceManager",
        "IFogging",
        "IHJBMgr",
        "IMapCheck",
        "IAnimatedEntity",
        "IDarkTribe",
        "CDarkConvert",
        "ITiling",
        "IEntity",
        "IFlyingEntity",
        "IGroupMgr",
        "IMovingEntity",
    ],

    "MapObjects/Vehicle/": [
        "CCargo",
        "CCart",
        "CWheeler",
        "IVehicleInfoMgr",
        "CVehicle",
        "CVehicleInfoMgr",
        "CVehicleIterator",
        "CVehicleIteratorBase",
        "CVehicleMgr",
        "CFoundationCardCargo",
        "ICargoCounter",
    ],

    "MapObjects/Flying/": [
        "CFlyingMgr",
        "CManakopter",
    ],

    "MapObjects/Animal/": [
        "CAnimal",
        "CAnimalEffect",
        "CAnimalMgr",
        "CLandAnimal",
        "CPossibleDirs",
    ],

    "MapObjects/Building/": [
        "CAnimalRanchRole",
        "CBarrackRole",
        "CBigTempleRole",
        "CBuilding",
        "CBuildingBits",
        "CBuildingFlagsWalk",
        "CBuildingInfoMgr",
        "CBuildingIteratorBase",
        "CBuildingManagerTask",
        "CBuildingMgr",
        "CBuildingPlace",
        "CBuildingSiteRole",
        "CCastleRole",
        "CDarkMushroomFarmRole",
        "CDarkTempleRole",
        "CEyeCatcherRole",
        "CFarmBuildingRole",
        "CFindBuildings",
        "CFindEnemyBuildings",
        "CGatherBuildingRole",
        "CGenericBuildingIterator",
        "CLookoutTowerRole",
        "CManakopterHallRole",
        "CManyBuildingTypesIterator",
        "CMilitaryBuildingIterator",
        "CMilitaryBuildingRole",
        "CMineRole",
        "COneBuildingTypeIterator",
        "CProductionBuildingRole",
        "CResidenceBuildingRole",
        "CSaboteurRole",
        "CSearchRoutines",
        "CSimpleBuildingRole",
        "CSmallTempleRole",
        "CSquadLeaderRole",
        "CStorageBuildingRole",
        "CStoragePileRole",
        "CTradingBuildingRole",
        "CWorkUpBuildingRole",
        "CWorkshopBuildingRole",
        "IBuildingRole",
        "ISelectableSettlerRole",
        "SBuildingMenu",
    ],

    "MapObjects/Catapult/": [
        "CCatapult",
        "CRomanCatapult",
        "CTrojanCatapult",
        "CMayaCatapult",
        "CVikingCatapult",
    ],

    "MapObjects/DecoObj/": [
        "CDecoObjMgr",
        "CDecoObject",
        "CHive",
        "CMushroom",
        "CPlant",
        "CShadowHerb",
        "IDecoObject",
    ],

    "MapObjects/Pile/": [
        "CAnyWherePileRole",
        "CBuildingSitePileRole",
        "CDeliverPileRole",
        "CPile",
        "CPileMgr",
        "CPileObserverList",
        "CProductionPileRole",
        "CTradePileRole",
        "IPileRole",
    ],

    "MapObjects/Settler/": [
        "CBuilderRole",
        "CCarrierRole",
        "CDarkGardenerRole",
        "CDiggerRole",
        "CDonkeyRole",
        "CDoorRole",
        "CFleeRole",
        "CFreeWorkerRole",
        "CGardenerRole",
        "CGenericSettlerIterator",
        "CGeologistRole",
        "CHJBMgr",
        "CHJBRole",
        "CHouseWorkerRole",
        "CHunterRole",
        "CManySettlerTypesIterator",
        "CMushroomFarmerRole",
        "COneSettlerTypeIterator",
        "CPioneerRole",
        "CPriestRole",
        "CSettler",
        "CSettlerIteratorBase",
        "CSettlerMgr",
        "CSettlerSpiralWalk",
        "CSettlerStatus",
        "CWarriorBehavior",
        "CShamanRole",
        "CSlaveRole",
        "CSoldierRole",
        "CThiefRole",
        "CTowerSoldier",
        "ISettlerRole",
    ],

    "MapObjects/Ship/": [
        "CFerryShip",
        "CMayaWarShip",
        "CRomanWarShip",
        "CShip",
        "CShipList",
        "CTaskForceWarShips",
        "CTransportShip",
        "CTrojanWarShip",
        "CVikingWarShip",
        "CWarShip",
    ],

    "Net/": [
        "AIMessage",
        "CClient",
        "CClientList",
        "CGameHost",
        "CLanLobby",
        "CMsgStacks",
        "CSimpleNet",
        "GameMessage",
        "GameSessionDescriptor",
        "GameSessionHandler",
        "INetInputProcessor",
        "INetworkEngine",
        "ISimpleNet",
        "OnlineManager",
        "PlayerMessage",
        "StormManager",
        "StormSampleFramework",
    ],

    "Pathing/": [
        "CAStar64",
        "CAStar64Catapult",
        "CAStar64Normal",
        "CAStar64Ship",
        "CAStar64Worker",
        "CAStarCallback",
        "CAStarTiling",
        "CAlliances",
        "CAreaList",
        "CDebugGridTest",
        "CFogging",
        "CInfluMap",
        "CLinks",
        "CWaypoints",
        "CScanner",
        "CSectors",
        "CShipMap",
        "CSquare",
        "CSquareVisited",
        "CSectorSpiralWalk",
        "CSpiralWalk",
        "PathSplitResult",
        "CTilesAndLinks",
        "CTilesEx",
        "CTiling",
        "CTilingWorld",
        "CVWList",
        "CWalking",
        "CWalkingBase",
        "CWalkingCatapult",
        "CWalkingNormal",
        "CWalkingShip",
        "CWalkingWorker",
        "CWarMap",
        "CWarMapNode",
        "CWarriorEntitySpiralWalk",
        "CGrid",
        "CBasicGrid",
        "CFeatureGrid",
        "CMirrorBasicGrid",
        "CRiver",
        "CWater",
        "CWaterFlags",
        "CWaterFlagsEx",
    ],

    "Script/": [
        "CGameScriptManager",
        "CLua",
        "CScriptManager",
        "CStdScriptFile",
        "IScriptFile",
    ],

    "SoundEngine/": [
        "CSoundSystem",
        "IAudioEndpointVolumeCallback",
        "IAudioSessionEvents",
        "ISoundEngine",
        "SSoundCardData",
        "CVCClient",
        "CVCRecorder",
        "CVoiceChat",
        "CPlaylist",
    ],

    "Collections/": [
        "CDynList",
        "CDynListEntry",
        "CLink",
        "CLinkList",
        "CIntLinkList",
        "CMsgStack",
        "COpenListEntry16",
        "COpenListEntry24",
    ],

    "Uncategorized/": [
        "BadClassID",
        "CBriefingSettings",
        "CCheckLayer",
        "CClassNetGameIniBuffer",
        "CCommandQueue",
        "CCondition",
        "CConditionSet",
        "CDebitLevelManager",
        "CDestructionManager",
        "CDestructionPhase",
        "CDestructor",
        "CESGI",
        "CFsm",
        "CGenericVehicleIterator",
        "CGrpReserveEntry",
        "CHistorySolution",
        "CIntResSquare",
        "CManyVehicleTypesIterator",
        "CNeighborRelIndices",
        "CNotifyExceptMushroomfarmer",
        "COneVehicleTypeIterator",
        "COptimizeOptions",
        "CRefGrpEntry",
        "CTmpEntitiesRef",
        "Cryptor",
        "DName",
        "DNameNode",
        "DNameStatusNode",
        "SAIDTOCCUPIEDELEMENT",
        "SAIDTUD",
        "SAI_ECO_POSS_BUILD_PLACE",
        "SBUILDINFODATA",
        "SDetailStatisticItem",
        "SEntry",
        "SGameEntry",
        "SM_SIV_PaletteBlock",
        "SMapEntry",
        "SPlayerEntry",
        "SSquadValue",
        "SampleFrameworkApplication",
        "String",
        "SurfaceClipper",
        "T_GFX_MAP_ELEMENT",
        "_bstr_t",
        "charNode",
        "pDNameNode",
        "pairNode",
        "pcharNode",
        "std",
    ],

    "VideoEngine/": [
        "CBinkInterface",
        "IVideoEngine",
    ],

    "World/": [
        "CWorldManager",
        "S4",
    ],

    "Xml/": [
        "Document",
        "Element",
        "GenerateContext",
        "NodeContainer",
        "Parser",
    ],

    "Xml/Advanced/": [
        "AdvXMLParser",
        "Attribute",
        "Bookmark",
        "CData",
        "CharRef",
        "Comment",
        "ConstIteratorRef",
        "Dtd",
        "EntityRef",
        "Exception",
        "InvalidRefException",
        "Node",
        "ParsingException",
        "Pi",
        "Reference",
        "Text",
        "Value",
    ],

}

WORKING_DIR="K:/Projekte/Siedler4/S4Forge.RE/Decompilation/"

OUTPUT_DIR = WORKING_DIR + "S4_Main/generated/"
GLOBAL_HEADER = "globals.h"
AGGREGATE_HEADER = "all_headers.h"

ADDRESS_OFFSET = 0x40_0000


class RTTIParser:
    def __init__(self, class_name):
        self.class_name = class_name
        self.type_desc_ea = 0
        self.col_ea = 0
        self.direct_bases = []

    def find_type_descriptor(self):
        """Locate the type descriptor for the given class name"""
        self.type_desc_ea = idc.get_name_ea_simple(
            f"{self.class_name}::_vftable_")
        if self.type_desc_ea == idc.BADADDR:
            print(f"Type descriptor for {self.class_name} not found")
            return False
        print(f"Type descriptor found at 0x{self.type_desc_ea:X}")
        return True

    def find_col(self):
        """Locate Complete Object Locator (COL) referencing the vtable"""
        self.col_ea = ida_bytes.get_dword(
            self.type_desc_ea - 4)  # COL points to type descriptor + offset
        print(f"Complete Object Locator found at 0x{self.col_ea:X}")
        return True

    def parse_direct_bases(self):
        # COL → ClassHierarchyDescriptor pointer
        chd_ptr_ea = ida_bytes.get_dword(self.col_ea + 16)
        if not chd_ptr_ea:
            print("ClassHierarchyDescriptor pointer is null")
            return

        num_bases = ida_bytes.get_dword(chd_ptr_ea + 8)
        base_array_ptr = ida_bytes.get_dword(chd_ptr_ea + 12)
        print(
            f"ClassHierarchyDescriptor at 0x{chd_ptr_ea:X}: numBaseClasses={num_bases}, baseArrayPtr=0x{base_array_ptr:X}")

        i = 1
        while i < num_bases:
            bcd_ptr = ida_bytes.get_dword(base_array_ptr + i * 4)
            type_desc_ptr = ida_bytes.get_dword(bcd_ptr + 0)
            num_contained = ida_bytes.get_dword(bcd_ptr + 4) + 1

            name_addr = type_desc_ptr + 8
            name_bytes = idc.get_strlit_contents(name_addr)
            if name_bytes:
                name = name_bytes.decode('utf-8', errors='ignore')
                if name.startswith(".?AV"):
                    name = name[4:-2]  # demangle
            else:
                name = "<unknown>"

            print(
                f"BaseClassDescriptor[{i}] at 0x{bcd_ptr:X}: name='{name}', numContainedBases={num_contained}")
            self.direct_bases.append(name)

            # Skip over nested bases for direct bases only
            i += max(1, num_contained)

    def run(self):
        if not self.find_type_descriptor():
            print(f"Class '{self.class_name}' not found")
            return
        if not self.find_col():
            print(f"COL for '{self.class_name}' not found")
            return
        self.parse_direct_bases()
        print(f"Direct base classes of {self.class_name}: {self.direct_bases}")
        return self.direct_bases


def get_function_definition(ea):
    cfunc = ida_hexrays.decompile(ea)
    if(cfunc is not None):
        cfunc.refresh_func_ctext()
    pseudocode_text = str(cfunc)
    return pseudocode_text

def get_class_members(class_name: str):
    tif = ida_typeinf.tinfo_t()
    if not tif.get_named_type(class_name) or not tif.is_struct():
        return []

    udt = ida_typeinf.udt_type_data_t()
    if not tif.get_udt_details(udt):
        return []

    members = []
    for i in range(udt.size()):
        member = udt[i]
        member_name = member.name
        if member_name == "":
            continue # skip base classes

        if member_name.startswith("__"):
            continue # skip vtable and other compiler-generated members

        member_type = member.type
        type_str = member_type.dstr()
        members.append((type_str, member_name))

    return members

# --------------------------------------------
seen_destructors = set()


def is_deleting_destructor(symbol: str):
    return (
        "`scalar deleting destructor'" in symbol
        or "`vector deleting destructor'" in symbol
    )


def make_destructor_decl(class_name: str, is_virtual=True):
    return f"{'virtual ' if is_virtual else ''}~{class_name}();"


def should_ignore(symbol: str) -> bool:
    return any(keyword in symbol for keyword in IGNORE_KEYWORDS)


def split_namespaces(qualified_name: str):
    """
    Splits Foo::Bar::Baz into (['Foo', 'Bar'], 'Baz')
    """
    parts = qualified_name.split("::")
    if len(parts) == 1:
        return [], parts[0]
    return parts[:-1], parts[-1]


def strip_qualified_name(declaration: str, namespaces, class_name: str) -> str:
    """
    Removes Namespace::Class:: from a method declaration
    """
    if namespaces:
        prefix = "::".join((*namespaces, class_name)) + "::"
    else:
        prefix = class_name + "::"

    return declaration.replace(prefix, "", 1)


def apply_replacements(text: str) -> str:
    for src, dst in REPLACEMENTS.items():
        text = text.replace(src, dst)
    return text


def parse_line(line: str):
    """
    Returns:
        None if line is invalid or ignored
        dict with keys:
            address, symbol, access, class, declaration
    """
    line = line.strip()
    if not line:
        return None

    # Expected format: ADDRESS<TAB>SYMBOL
    parts = line.split(None, 1)
    if len(parts) != 2:
        return None

    address, symbol = parts

    if should_ignore(symbol):
        return None

    # Check for access specifier
    access_match = re.match(r"(public|protected|private):\s*(.*)", symbol)
    if not access_match:
        # Global symbol
        return {
            "type": "global",
            "address": address,
            "symbol": apply_replacements(symbol),
        }

    access = access_match.group(1)
    remainder = apply_replacements(access_match.group(2))

    # Try to extract class name
    method_match = re.search(r"([\w:]+)::[^:]+\s*(?:\(|$)", remainder)
    if not method_match:
        # Fallback to global if class can't be determined
        return {
            "type": "global",
            "address": address,
            "symbol": symbol,
        }

    qualified_scope = method_match.group(1)
    namespaces, class_name = split_namespaces(qualified_scope)

    if is_deleting_destructor(remainder):
        key = (class_name, "destructor")
        if key in seen_destructors:
            return None

        seen_destructors.add(key)
        return {
            "type": "class",
            "address": address,
            "class": class_name,
            "namespaces": namespaces,
            "access": access,
            "declaration": f"virtual ~{class_name}();"
        }

    return {
        "type": "class",
        "address": address,
        "class": class_name,
        "namespaces": namespaces,
        "access": access,
        "declaration": remainder,
    }


def open_namespaces(f, namespaces):
    for ns in namespaces:
        f.write(f"namespace {ns} {{\n")
    if namespaces:
        f.write("\n")


def close_namespaces(f, namespaces):
    for ns in reversed(namespaces):
        f.write(f"}} // namespace {ns}\n")


def write_globals(globals_list, generated_headers):
    if not globals_list:
        return

    path = os.path.join(OUTPUT_DIR, GLOBAL_HEADER)
    generated_headers.add(GLOBAL_HEADER)
    guard = "GLOBALS_H"

    with open(path, "w", encoding="utf-8") as f:
        f.write(f"#ifndef {guard}\n#define {guard}\n\n")

        globals_by_ns = defaultdict(list)

        for entry in globals_list:
            match = re.match(r"([\w:]+)::", entry["symbol"])
            namespaces = split_namespaces(match.group(1))[0] if match else []
            globals_by_ns[tuple(namespaces)].append(entry)

        for namespaces, entries in globals_by_ns.items():
            open_namespaces(f, namespaces)

            for entry in entries:
                f.write(
                    f"// address=[{hex(int(entry['address'], 16) - ADDRESS_OFFSET)}]\n")
                f.write(f"{entry['symbol']};\n\n")

            close_namespaces(f, namespaces)
            if namespaces:
                f.write("\n")

        f.write(f"#endif // {guard}\n")


def write_class_headers(classes, generated_headers):
    for (namespaces, class_name), members in classes.items():
        rel_path, abs_path = create_class_file_paths(class_name)
        rel_path += ".h"
        abs_path += ".h"

        generated_headers.add(rel_path.replace("\\", "/"))

        guard = "_".join(list(namespaces) + [class_name]).upper() + "_H"

        rtti_parser = RTTIParser(class_name)
        direct_bases = rtti_parser.run()

        with open(abs_path, "w", encoding="utf-8") as f:
            f.write(f"#ifndef {guard}\n#define {guard}\n\n")

            open_namespaces(f, namespaces)

            f.write(f"class {class_name}")

            if direct_bases:
                f.write(" : ")
                base_list = []
                for base in direct_bases:
                    base_list.append(f"public {base}")
                f.write(", ".join(base_list))

            f.write(f" {{\n")

            for access in ("public", "protected", "private"):
                if members[access]:
                    f.write(f"{access}:\n")
                    for entry in members[access]:
                        f.write(
                            f"    // address=[{hex(int(entry['address'], 16) - ADDRESS_OFFSET)}]\n")
                        clean_decl = strip_qualified_name(
                            entry["declaration"],
                            namespaces,
                            class_name
                        )

                        f.write(f"    {clean_decl};\n\n")

            type_members = get_class_members(class_name)
            if type_members:
                f.write("    // Type information members\n")
                f.write("private:\n")
                for type_str, member_name in type_members:
                    f.write(f"    {type_str} {member_name};\n")
                f.write("\n")

            f.write("};\n\n")

            close_namespaces(f, namespaces)

            f.write(f"\n#endif // {guard}\n")


def create_class_file_paths(class_name):
    for folder, files in FOLDER_MAP.items():
        if class_name in files:
            dir_path = folder
            os.makedirs(os.path.join(OUTPUT_DIR, dir_path), exist_ok=True)
            break
    else:
        dir_path = ""  # os.path.join(*namespaces) if namespaces else ""
        os.makedirs(os.path.join(OUTPUT_DIR, dir_path), exist_ok=True)

    rel_path = os.path.join(dir_path, f"{class_name}")
    abs_path = os.path.join(OUTPUT_DIR, rel_path)
    return rel_path, abs_path

def strip_for_decompilation(method_name: str) -> str:
    """Strips unnecessary parts from method name for decompilation"""
    # Remove virtual specifier
    method_name = method_name.replace("virtual ", "")
    
    return method_name

def strip_destructor(func: str) -> str:
    """Strips unnecessary parts from destructor for decompilation"""
    
    # Destructors look like this in MSVC decompilation:
    # ClassName::`scalar deleting destructor'(pointer) for ClassName, with optional other params
    # We want to convert it to:
    # delete pointer;
    # There is also vector deleting destructor, which is similar.
    # It will be converted to delete[] pointer;

    # The func can contain multiple destructors

    pattern = re.compile(r"(\w+)::`(scalar|vector) deleting destructor'\(([^,]+).+\)")
    def replacer(match):
        # class_name = match.group(1)
        delete_type = match.group(2)
        pointer = match.group(3).strip()

        if delete_type == "scalar":
            return f"delete {pointer}"
        else:
            return f"delete[] {pointer}"
    
    return pattern.sub(replacer, func)

def write_class_definitions(classes):
    for (namespaces, class_name), members in classes.items():

        rel_path, abs_path = create_class_file_paths(class_name)
        rel_path += ".cpp"
        abs_path += ".cpp"

        with open(abs_path, "w", encoding="utf-8") as f:
            f.write(f"#include \"{class_name}.h\"\n\n")

            f.write(f"// Definitions for class {class_name}\n\n")

            for access in ("public", "protected", "private"):
                if not members[access]:
                    continue

                for entry in members[access]:
                    f.write(
                        f"// address=[{hex(int(entry['address'], 16) - ADDRESS_OFFSET)}]\n")
                
                    func = get_function_definition(int(entry['address'], 16) - ADDRESS_OFFSET)
                    
                    if func == "None":
                        f.write(f"// [Decompilation failed for {entry['declaration']}]\n\n")
                        continue
                        
                    [func_name, func_without_declaration] = func.split("{", 1)
                    func = strip_for_decompilation(entry["declaration"]) + " {\n  " + func_without_declaration

                    commented_func_name = func_name.split("\n")
                    commented_func_name = [line.strip() for line in commented_func_name if line.strip() != '' and not line.strip().startswith("//")]
                    func_name = "\n ".join(commented_func_name)

                    func_name = func_name.strip().replace("\n", " ")
                    f.write(f"// Decompiled from {func_name}\n")
                    
                    func = strip_destructor(func)
                    f.write(f"{func}\n\n")


def write_aggregate_header(generated_headers):
    path = os.path.join(OUTPUT_DIR, AGGREGATE_HEADER)
    guard = "ALL_HEADERS_H"

    with open(path, "w", encoding="utf-8") as f:
        f.write(f"#ifndef {guard}\n#define {guard}\n\n")

        for header in sorted(generated_headers):
            f.write(f'#include "{header}"\n')

        f.write(f"\n#endif // {guard}\n")

def write_default_header():
    path = os.path.join(OUTPUT_DIR, DEFINES_HEADER)
    guard = "DEFINES_H"

    with open(path, "w", encoding="utf-8") as f:
        f.write(f"#ifndef {guard}\n#define {guard}\n\n")
        f.write("// Auto-generated header file\n")

        f.write("// Default includes for standard types\n\n")

        f.write("#include <string>\n")
        f.write("#include <vector>\n")
        f.write("#include <list>\n")
        f.write("#include <map>\n")

        f.write("// Default includes for IDA types\n\n")

        f.write("typedef unsigned char BYTE;\n")
        f.write("typedef unsigned char _BYTE;\n\n")
        
        f.write("typedef unsigned short WORD;\n")
        f.write("typedef unsigned short _WORD;\n\n")

        f.write("typedef unsigned int DWORD;\n")
        f.write("typedef unsigned int _DWORD;\n\n")

        f.write("typedef unsigned long long QWORD;\n\n")

        f.write(f"#endif // {guard}\n")

def main(input_file):
    os.makedirs(OUTPUT_DIR, exist_ok=True)

    globals_list = []
    classes = defaultdict(lambda: defaultdict(list))
    generated_headers = set()

    with open(input_file, "r", encoding="utf-8") as f:
        for line in f:
            parsed = parse_line(line)
            if not parsed:
                continue

            if parsed["type"] == "global":
                globals_list.append(parsed)
            else:
                key = (tuple(parsed["namespaces"]), parsed["class"])
                classes[key][parsed["access"]].append(parsed)

    write_globals(globals_list, generated_headers)
    write_default_header()
    write_class_headers(classes, generated_headers)
    write_aggregate_header(generated_headers)
    write_class_definitions(classes)
    
main(WORKING_DIR + "syms.txt")
