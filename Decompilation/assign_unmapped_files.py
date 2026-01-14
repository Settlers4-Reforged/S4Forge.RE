#!/usr/bin/env python3
"""
Analyzes files in the generated folder (root level only) and assigns them to
folders in FOLDER_MAP or suggests new folders based on their names.
"""

import os
import re
from pathlib import Path
from collections import defaultdict

# Import FOLDER_MAP from class_creator
FOLDER_MAP = {
    "AI/": [
        "CAIAgent",
        "CAIAgentAttack",
        "CAIAgentEvaluation",
        "CAIAgentEvalDefence",
        "CAIAgentEvalOffence",
        "CAIAgentGardeners",
        "CAIAgentGeologists",
        "CAIAgentIntruderCombat",
        "CAIAgentGlobalSuicideMission",
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
        "CAINormalSectorAgent",
        "CAIConfigInt",
        "CAIConfigIntEx",
        "CAIChambers",
        "CAIDefenceGoals",
        "CAIEcoSectorAIEx",
        "CAIEnemySettlerInSectorIterator",
        "CAIEntityInfo",
        "CAIEntityInfoEx",
        "CAIEntityInfoTower",
        "CAIEventQueue",
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
        "CAIRegions",
        "CAIResourceMap",
        "CAIScheduler",
        "CAIScripting",
        "CAISectorAI",
        "CAITaskForce",
        "CAITaskForceEx",
        "CAITaskForceGroup",
        "CAITaskForcePriests",
        "CAITaskForcePriestsTrojan",
        "CAITaskForceShamans",
        "CAITaskForceSquad",
        "CAITaskForces",
        "CAIShaman",
        "CAIVWVector",
        "CAIWatchTower",
        "CAIWatchTowerEx",
        "CAIWatchTowers",
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
    ],

    "AI/DarkTribe/": [
        "CAIDarkTribe",
        "CAIDarkTribePlayerAI",
        "CAIDarkTribeSectorAI",
        "CAIDarkTribeSectorAgent",
        "CAIAgentDarkTribeAttack",
        "CAIAgentDarkTribeManakopters",
        "CAIAgentDarkTribeMushroomFarms",
        "CAIAgentDarkTribeRecruitment",
        "CAIAgentDarkTribeShamans",
        "CAIAgentDarkTribeDarkGardeners",
        "CAIAgentDarkTribeManakopterHalls",
        "CAIAgentDarkTribeSquadManager",
    ],

    "AI/Eco/": [
        "CEcoSectorAI",
    ],

    "Logic/": [
        "CBuildingSupplyPriority",
        "CDarkTribe",
        "CEcoSector",
        "CEcoSectorMgr",
        "CEffect",
        "CEffects",
        "CEndStatistic",
        "CFutureEvents",
        "CGoodTransportPriority",
        "CInfoExchange",
        "CInputProcessor",
        "CInternationalTrader",
        "CLogic",
        "CMagic",
        "CMagicSpell",
        "CNetInputProcessor",
        "CPlayerGameData",
        "CPlayerTradeInfo",
        "CStatistic",
        "CStatisticArchive",
        "CTransportMgr",
        "SPlayerStatistic",
    ],

    "MapObjects/Building/": [
        "CBarrackRole",
        "CBuilding",
        "CBuildingBits",
        "CBuildingInfoMgr",
        "CBuildingMgr",
        "CBuildingIteratorBase",
        "CBuildingManagerTask",
        "CBuildingSiteRole",
        "CBuildingFlagsWalk",
        "CDarkMushroomFarmRole",
        "CDarkTempleRole",
        "CFarmBuildingRole",
        "CGatherBuildingRole",
        "CLookoutTowerRole",
        "CMilitaryBuildingRole",
        "CMineRole",
        "CProductionBuildingRole",
        "CResidenceBuildingRole",
        "CSearchRoutines",
        "CSimpleBuildingRole",
        "CSmallTempleRole",
        "CStorageBuildingRole",
        "CTradingBuildingRole",
        "CWorkUpBuildingRole",
        "CWorkshopBuildingRole",
        "IBuildingRole",
    ],

    "Net/": [
        "CClientList",
        "CGameHost",
        "CLanLobby",
        "CMsgStacks",
        "CSimpleNet",
        "INetInputProcessor",
        "INetworkEngine",
        "ISimpleNet",
        "OnlineManager",
        "GameSessionHandler",
        "GameSessionDescriptor",
        "GameMessage",
        "PlayerMessage",
        "AIMessage",
    ],

    "Script/": [
        "IScriptFile",
        "CGameScriptManager",
        "CLua",
        "CScriptManager",
    ],

    "AI/EcoManager/": [
        "CEcoManager",
        "CEcoManagerLeaf",
        "CEcoManagerTree",
        "CEMD",
        "CEMLD",
        "CEMTD",
    ],

    "LoadSave/": [
        "CGameChunkGeneral",
        "CMapFile",
        "CS4MemChunk",
        "CSavedPlayer",
    ],

    "MapObjects/": [
        "CCart",
        "CEntityToDoListMgr",
        "CGroupDestinations",
        "IGroupMgr",
        "CGroupMgr",
        "CMapObjectMgr",
        "CObserverList",
        "CStdCargoCounter",
        "CStone",
        "CTree",
        "CVehicle",
        "IVehicleInfoMgr",
        "CVehicleInfoMgr",
        "CVehicleIterator",
        "CVehicleMgr",
        "CWarriorBehavior",
        "CWheeler",
        "IEntity",
        "IAnimatedEntity",
        "IMovingEntity",
        "CFlyingMgr",
        "CManakopter",
        "IS4Chunk",
        "IS4ChunkObject",
    ],

    "MapObjects/Animal/": [
        "CAnimal",
        "CAnimalEffect",
        "CAnimalMgr",
        "CPossibleDirs",
    ],

    "MapObjects/Catapult/": [
        "CCatapult",
    ],

    "MapObjects/DecoObj/": [
        "CDecoObjMgr",
        "CDecoObject",
        "CMushroom",
        "CPlant",
        "CHive",
        "CShadowHerb",
        "IDecoObject",
    ],
    
    "MapObjects/Pile/": [
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
        "CGeologistRole",
        "CHouseWorkerRole",
        "CHunterRole",
        "CMushroomFarmerRole",
        "CPioneerRole",
        "CPriestRole",
        "CSettler",
        "CSettlerMgr",
        "CShamanRole",
        "CSlaveRole",
        "CSoldierRole",
        "CThiefRole",
        "CTowerSoldier",
        "CHJBMgr",
        "CHJBRole",
        "ISettlerRole",
    ],

    "MapObjects/Ship/": [
        "CFerryShip",
        "CShip",
        "CTransportShip",
        "CWarShip",
    ],

    "Pathing/": [
        "CAStar64",
        "CAStarCallback",
        "CAStarTiling",
        "CAStar64Catapult",
        "CAStar64Normal",
        "CAStar64Ship",
        "CAStar64Worker",
        "CAlliances",
        "CAreaList",
        "CDebugGridTest",
        "CFogging",
        "CInfluMap",
        "CLinks",
        "CScanner",
        "CSectors",
        "CShipMap",
        "CSquare",
        "CSquareVisited",
        "CTilesAndLinks",
        "CTilesEx",
        "CTiling",
        "CTilingWorld",
        "CVWList",
        "CWalking",
        "CWalkingBase",
        "CWalkingCatapult",
        "CWalkingShip",
        "CWarMap",
        "CWarMapNode",
        "CWater",
        "CWaterFlags",
        "CDirCache",
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
        "ParsingException",
        "Node",
        "Pi",
        "Reference",
        "Text",
        "Value",
    ],

    "Compression/": [
        "LZBuffer",
        "LZHLCompressor",
        "LZHLDecompressor",
        "LZHLEncoder",
        "LZHLEncoderStat",
    ],

    "VideoEngine/": [
        "CBinkInterface",
        "IVideoEngine",
    ],

    "SoundEngine/": [
        "ISoundEngine",
        "IAudioEndpointVolumeCallback",
        "IAudioSessionEvents",
    ],

    "World/": [
        "CWorldManager",
        "S4",
    ],

    "Main/": [
        "CGameStateHandler",
        "CPlayerManager",
        "CSoundManager",
        "CStringEngineEx",
        "CTextMsgHandler",
        "CAddOn",
        "CExtraCD",
        "CGameRun",
        "CGameSettings",
        "CGameType",
        "IMapGeneratorHost",
        "CMapGeneratorHost",
    ],

    "Main/States/": [
        "CGuiGameState",
        "CStateGame",
        "CStateVideo",
        "CStateEcoStatistic",
        "CStateEndStatistic",
        "CStateLobbyLoadMP",
        "CStateMDBriefing",
        "CStateMDCampaigns",
        "CStateMDRandomMapParameters",
        "CStateMessageBox",
        "CStateVictoryScreen",
        "CStateAOBriefing",
        "CStateAOCampaigns",
        "CStateAOSplash",
        "CStateBriefing",
        "CStateCampaign3X3",
        "CStateCampaignDark",
        "CStateCredits",
        "CStateLoadGame",
        "CStateLoadType",
        "CStateLobbyConnect",
        "CStateLobbyGameSettings",
        "CStateLobbyMapSettings",
        "CStateLobbyMultiplayerType",
        "CStateLocalType",
        "CStateMD2Briefing",
        "CStateMD2Campaigns",
        "CStateMainMenu",
        "CStateTutorial",
        "CStateXMD3Briefing",
        "CStateXMD3Campaigns",
        "CStateAOCampaignBonus",
        "CStateAOCampaignMayan",
        "CStateAOCampaignRoman",
        "CStateAOCampaignsSettle",
        "CStateAOCampaignTrojan",
        "CStateAOCampaignViking",
        "CStateMDCampaignMayan",
        "CStateMDCampaignRoman",
        "CStateMDCampaignsEcoConflict",
        "CStateMDCampaignViking",
        "CStateSlideshow",
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
        "CAITaskForces",
        "CAITaskForceShamans",
        "CAITaskForceSquad",
    ],
    
    "CBB/": [
        "CBBException",
        "CBBFileException",
        "CBBMemoryException",
        "CBBObject",
        "CBBObjectTracer",
        "CBBSupportLogFile",
        "CBBSupportMemoryCleanup",
        "CBBSupportStructuredExceptionHandlerCleanup",
        "BBSupportLib",
        "CBBSStackTrace",
        "CBBSupportTraceFile",
        "CBBSupportTraceFilePtr",
        "IBBSupportTraceFile",
    ],

    "CConfigManager/": [
        "CConfigFile",
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
    ],

    "Debug/": [
        "CDebugFkt",
        "CDebugGridTest",
        "CDebugInfo",
    ],

    "Logic/Events/": [
        "CEvn_Event",
        "CEvn_HandleList",
        "CEvn_Logic",
        "CEvn_Window",
        "CNet_Event",
        "IEventEngine",
        "IEventHandler",
        "IEvn_Handle",
        "IFutureEvents",
        "CBuildingEvent",
        "CAIEvent",
    ],

    "File/": [
        "CFile",
        "CFileEx",
        "CFileLibrary",
        "CFileMgr",
        "IFileEx",
    ],

    "Info/": [
        "CBuildingInfo",
        "CBuildingInfoEx",
        "CBuildingSiteInfo",
        "CEconomyGameInfo",
    ],

    "Graphics/D3D/": [
        "CInterfaceD3D",
        "CSurface",
        "CSurfaceDescription",
        "CSurfaceV3",
        "CSurfaceV7",
        "IGfxEffects",
        "IGfxEngine",
    ]
}


def get_class_names_from_folder(folder_path):
    """Get all class names from .cpp files in the root of the folder."""
    class_names = set()
    
    for file in os.listdir(folder_path):
        if file.endswith('.cpp'):
            # Remove .cpp extension to get class name
            class_name = file[:-4]
            class_names.add(class_name)
    
    return sorted(class_names)


def get_all_mapped_classes():
    """Get set of all classes that are already in FOLDER_MAP."""
    mapped = set()
    for classes in FOLDER_MAP.values():
        mapped.update(classes)
    return mapped


def suggest_folder(class_name):
    """Suggest a folder for a class based on its name patterns."""
    
    # Patterns and their suggested folders
    patterns = [
        # AI patterns
        (r'^CAI', 'AI/'),
        (r'^IAI', 'AI/'),
        
        # Building patterns
        (r'Building|Role$', 'MapObjects/Building/'),
        (r'^CBarracks', 'MapObjects/Building/'),
        
        # Settler patterns
        (r'Settler|Role$', 'MapObjects/Settler/'),
        
        # Animal patterns
        (r'Animal', 'MapObjects/Animal/'),
        
        # Pile patterns
        (r'Pile', 'MapObjects/Pile/'),
        
        # Ship patterns
        (r'Ship', 'MapObjects/Ship/'),
        
        # DecoObj patterns
        (r'^CMushroom|^CPlant|^CHive', 'MapObjects/DecoObj/'),
        
        # Pathing patterns
        (r'^CAStar|^CWalking|^CWar|^CTiling|^CWater', 'Pathing/'),
        
        # Logic patterns
        (r'^CLogic|^CMagic|^CStatistic', 'Logic/'),
        
        # Event patterns
        (r'Event', 'Logic/Events/'),
        
        # State patterns
        (r'^CState', 'Main/States/'),
        
        # Net patterns
        (r'^CClient|^CGameHost|Message$', 'Net/'),
        
        # Script patterns
        (r'Script|^CLua', 'Script/'),
        
        # File patterns
        (r'^CFile', 'File/'),
        
        # Config patterns
        (r'^CConfig', 'CConfigManager/'),
        
        # XML patterns
        (r'^Document|^Element|^Parser|XML', 'Xml/'),
        
        # Compression
        (r'^LZ|Compressor|Decompressor', 'Compression/'),
        
        # Video
        (r'Video|^CBink', 'VideoEngine/'),
        
        # Sound
        (r'Sound|Audio', 'SoundEngine/'),
        
        # CBB
        (r'^CBB|BBSupport', 'CBB/'),
        
        # Info
        (r'Info$', 'Info/'),
        
        # UI/Sidebar
        (r'SideBar|^CAdd.*Info$', 'UI/'),
        
        # Task
        (r'Task', 'MapObjects/'),
        
        # Cargo/Transport
        (r'Cargo|Transport', 'MapObjects/'),
        
        # General MapObjects
        (r'^CEntity|^CGroup|^CVehicle|^CCart|^CStone|^CTree', 'MapObjects/'),
    ]
    
    for pattern, folder in patterns:
        if re.search(pattern, class_name):
            return folder
    
    # Default
    return 'Uncategorized/'


def analyze_unmapped_files(generated_folder):
    """Analyze files in generated folder and categorize them."""
    
    all_files = get_class_names_from_folder(generated_folder)
    mapped_classes = get_all_mapped_classes()
    
    unmapped = [cls for cls in all_files if cls not in mapped_classes]
    
    # Categorize unmapped files
    categorized = defaultdict(list)
    
    for cls in unmapped:
        suggested_folder = suggest_folder(cls)
        categorized[suggested_folder].append(cls)
    
    return {
        'total_files': len(all_files),
        'mapped_files': len(all_files) - len(unmapped),
        'unmapped_files': len(unmapped),
        'unmapped_list': unmapped,
        'categorized': dict(categorized)
    }


def print_results(results):
    """Print analysis results."""
    print("=" * 80)
    print("FILE MAPPING ANALYSIS")
    print("=" * 80)
    print(f"\nTotal files in generated/: {results['total_files']}")
    print(f"Already mapped in FOLDER_MAP: {results['mapped_files']}")
    print(f"Unmapped files: {results['unmapped_files']}")
    
    if results['unmapped_files'] == 0:
        print("\n✓ All files are already mapped!")
        return
    
    print("\n" + "=" * 80)
    print("SUGGESTED FOLDER ASSIGNMENTS:")
    print("=" * 80)
    
    for folder in sorted(results['categorized'].keys()):
        classes = sorted(results['categorized'][folder])
        print(f"\n{folder} ({len(classes)} files):")
        for cls in classes:
            print(f"    {cls}")
    
    print("\n" + "=" * 80)
    print("UPDATED FOLDER_MAP ENTRIES:")
    print("=" * 80)
    
    for folder in sorted(results['categorized'].keys()):
        classes = sorted(results['categorized'][folder])
        print(f'\n    "{folder}": [')
        for cls in classes:
            print(f'        "{cls}",')
        print("    ],")


def export_updated_folder_map(results, output_file):
    """Export complete FOLDER_MAP with new entries."""
    
    # Merge with existing FOLDER_MAP
    updated_map = dict(FOLDER_MAP)
    
    for folder, classes in results['categorized'].items():
        if folder in updated_map:
            # Add to existing folder
            updated_map[folder] = sorted(set(updated_map[folder] + classes))
        else:
            # New folder
            updated_map[folder] = sorted(classes)
    
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write("# Updated FOLDER_MAP with unmapped files\n\n")
        f.write("FOLDER_MAP = {\n")
        
        for folder in sorted(updated_map.keys()):
            classes = sorted(updated_map[folder])
            f.write(f'    "{folder}": [\n')
            for cls in classes:
                f.write(f'        "{cls}",\n')
            f.write("    ],\n\n")
        
        f.write("}\n")
    
    print(f"\n\nUpdated FOLDER_MAP exported to: {output_file}")


if __name__ == "__main__":
    import argparse
    
    parser = argparse.ArgumentParser(
        description='Analyze unmapped files in generated folder'
    )
    parser.add_argument(
        'folder',
        type=str,
        nargs='?',
        default='S4_Main/generated',
        help='Path to generated folder (default: S4_Main/generated)'
    )
    parser.add_argument(
        '--export',
        type=str,
        help='Export updated FOLDER_MAP to file'
    )
    
    args = parser.parse_args()
    
    folder_path = Path(args.folder).resolve()
    
    if not folder_path.exists():
        print(f"Error: Folder '{folder_path}' does not exist", file=sys.stderr)
        exit(1)
    
    results = analyze_unmapped_files(folder_path)
    print_results(results)
    
    if args.export:
        export_updated_folder_map(results, args.export)
