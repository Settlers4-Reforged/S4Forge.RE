#include "CGameRun.h"

// Definitions for class CGameRun

// address=[0x14821f0]
// Decompiled from char CGameRun::Init()

static bool __cdecl CGameRun::Init(void) {
  
  char IsMultiplayerGame; // al
  int v2; // eax
  signed __int8 LocalSlot; // al
  int MapObjectXMLVersion; // [esp+1Ch] [ebp-854h]
  int MapBuildingXMLVersion; // [esp+20h] [ebp-850h]
  CLogicRingBuffer *v6; // [esp+24h] [ebp-84Ch]
  CLogicRingBuffer *v7; // [esp+28h] [ebp-848h]
  CPaneContainer *v8; // [esp+2Ch] [ebp-844h]
  CLogic *v9; // [esp+30h] [ebp-840h]
  CGameScriptManager *v10; // [esp+34h] [ebp-83Ch]
  CGameScriptManager *v11; // [esp+38h] [ebp-838h]
  CFormView *v12; // [esp+3Ch] [ebp-834h]
  CMapObjectMgr *C; // [esp+40h] [ebp-830h]
  _DWORD *v14; // [esp+44h] [ebp-82Ch]
  _DWORD *v15; // [esp+48h] [ebp-828h]
  int v16; // [esp+4Ch] [ebp-824h]
  int XMLVersion; // [esp+50h] [ebp-820h]
  char v18; // [esp+5Fh] [ebp-811h]
  char Buffer[1024]; // [esp+60h] [ebp-810h] BYREF
  char v20[1024]; // [esp+460h] [ebp-410h] BYREF
  int v21; // [esp+86Ch] [ebp-4h]

  IMessageTracer::Init(g_pMsgTracer);
  IMessageTracer::Init(g_pMsgTracer2);
  IMessageTracer::PushStaticText(g_pMsgTracer, "==> CGameRun::Init()...");
  if ( CGameRun::m_bInitialized && BBSupportDbgReport(2, "main\\GameRun.cpp", 149, "!m_bInitialized") == 1 )
    __debugbreak();
  v15 = operator new(0x14DCu);
  v21 = 0;
  if ( v15 )
    v14 = CEntityToDoListMgr::CEntityToDoListMgr(v15);
  else
    v14 = 0;
  g_pEntityToDoListMgr = (int)v14;
  C = (CMapObjectMgr *)operator new(0x24u);
  v21 = 1;
  if ( C )
    v12 = CMapObjectMgr::CMapObjectMgr(C);
  else
    v12 = 0;
  g_pMapObjectMgr = v12;
  IsMultiplayerGame = CGameType::IsMultiplayerGame(g_pGameType);
  CSettlerMgr::LoadInfo(g_cSettlerMgr, IsMultiplayerGame);
  CBuildingMgr::LoadInfo((CBuildingMgr *)g_cBuildingMgr);
  CDecoObjMgr::LoadInfo((CDecoObjMgr *)&g_cDecoObjMgr);
  CVehicleMgr::LoadInfo((CVehicleMgr *)&g_cVehicleMgr);
  v11 = (CGameScriptManager *)operator new(0x63Cu);
  v21 = 2;
  if ( v11 )
    v10 = CGameScriptManager::CGameScriptManager(v11);
  else
    v10 = 0;
  v21 = -1;
  g_pScriptMgr = (int)v10;
  if ( CGameData::GetMode(g_pGameData) == 3 )
    CGameScriptManager::SetVictoryConditionHook(
      (CGameScriptManager *)g_pScriptMgr,
      ScriptEconomyModeVictoryConditionCheck);
  (*(void (__thiscall **)(void *))(*(_DWORD *)off_3D7A3D8 + 8))(off_3D7A3D8);
  v9 = (CLogic *)operator new(0x48u);
  v21 = 3;
  if ( v9 )
    v8 = CLogic::CLogic(v9);
  else
    v8 = 0;
  v21 = -1;
  g_pLogic = v8;
  (*(void (__thiscall **)(void *))(*(_DWORD *)g_pGroupMgr + 8))(g_pGroupMgr);
  CInputProcessor::Reset((CInputProcessor *)&g_cInputProcessor);
  v7 = (CLogicRingBuffer *)operator new(0x1Cu);
  v21 = 4;
  if ( v7 )
    v6 = CLogicRingBuffer::CLogicRingBuffer(v7, 1024);
  else
    v6 = 0;
  v21 = -1;
  *(_DWORD *)(g_pGame + 252) = v6;
  CGameRun::SetupPlayersAndAlliances();
  CStatistic::Init((CStatistic *)&g_cStatistic);
  CInternationalTrader::ReInit();
  CMagic::InitMagicData();
  g_iAutosavePrefix = 65;
  if ( *(_BYTE *)(g_pGameType + 696) )
  {
    if ( !CGameRun::LoadGame(g_pGameType + 704) )
      return 0;
    CGameRun::ActivateAIs();
  }
  else
  {
    XMLVersion = CBuildingInfoMgr::GetXMLVersion((CBuildingInfoMgr *)&g_cBuildingInfoMgr);
    v16 = CDecoObjMgr::GetXMLVersion((CDecoObjMgr *)&g_cDecoObjMgr);
    if ( XMLVersion <= 0 && BBSupportDbgReport(2, "main\\GameRun.cpp", 218, "iBuildingXMLVersion > 0") == 1 )
      __debugbreak();
    if ( v16 <= 0 && BBSupportDbgReport(2, "main\\GameRun.cpp", 219, "iObjectXMLVersion > 0") == 1 )
      __debugbreak();
    if ( g_pGameType )
      MapBuildingXMLVersion = CGameType::GetMapBuildingXMLVersion((CGameType *)g_pGameType);
    else
      MapBuildingXMLVersion = 0;
    if ( g_pGameType )
      MapObjectXMLVersion = CGameType::GetMapObjectXMLVersion((CGameType *)g_pGameType);
    else
      MapObjectXMLVersion = 0;
    if ( MapBuildingXMLVersion < 0
      && BBSupportDbgReport(2, "main\\GameRun.cpp", 224, "iMapBuildingXMLVersion >= 0") == 1 )
    {
      __debugbreak();
    }
    if ( MapObjectXMLVersion < 0 && BBSupportDbgReport(2, "main\\GameRun.cpp", 225, "iMapObjectXMLVersion >= 0") == 1 )
      __debugbreak();
    memset(Buffer, 0, sizeof(Buffer));
    memset(v20, 0, sizeof(v20));
    if ( MapBuildingXMLVersion && MapBuildingXMLVersion != 298 && MapBuildingXMLVersion != XMLVersion )
      j___snprintf(
        Buffer,
        0x400u,
        "Invalid version of building info! Version used for map is %i, should be %i (original) or %i (current).",
        MapBuildingXMLVersion,
        298,
        XMLVersion);
    if ( MapObjectXMLVersion && MapObjectXMLVersion != 355 && MapObjectXMLVersion != v16 && MapObjectXMLVersion != 1000 )
      j___snprintf(
        v20,
        0x400u,
        "Invalid version of object info! Version used for map is %i, should be %i (original) or %i (current).",
        MapObjectXMLVersion,
        355,
        v16);
    if ( Buffer[0] || v20[0] )
    {
      v2 = Buffer[0] && v20[0]
         ? BBSupportDbgReportF(1, "main\\GameRun.cpp", 263, "%s%s%s", Buffer, "\n", v20)
         : BBSupportDbgReportF(1, "main\\GameRun.cpp", 263, "%s%s%s", Buffer, (const char *)&unk_36BF687, v20);
      if ( v2 == 1 )
        __debugbreak();
    }
    v18 = CGameData::IsCampaign(g_pGameData) || CGameData::IsTutorial(g_pGameData);
    CGameRun::LoadEditorMap(g_pGameType + 28, v18);
    CLogic::PostLoadMap(g_pLogic, (struct CGameType *)g_pGameType);
    CEcoSectorMgr::CalculateInitialFreeBeds((CEcoSectorMgr *)g_cESMgr);
    CEcoSectorMgr::OrderDiggerAndBuilderAtStartUp((CEcoSectorMgr *)g_cESMgr);
    CStatistic::UpdateStartStatistic((CStatistic *)&g_cStatistic);
    CGameRun::ActivateAIs();
  }
  LocalSlot = CPlayerManager::GetLocalSlot();
  CGameType::SetLocalSlot((CGameType *)g_pGameType, LocalSlot);
  CGameScriptManager::StartScript((CGameScriptManager *)g_pScriptMgr);
  CAnimalMgr::Init((CAnimalMgr *)&g_cAnimalMgr);
  CGameRun::m_bInitialized = 1;
  return 1;
}


// address=[0x14828c0]
// Decompiled from char CGameRun::Run()

static bool __cdecl CGameRun::Run(void) {
  
  int TickCounter; // eax
  unsigned int v1; // eax
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int Seed; // [esp-8h] [ebp-18h]
  unsigned int NumberOfRandCalls; // [esp-4h] [ebp-14h]
  unsigned int v15; // [esp-4h] [ebp-14h]
  unsigned int v16; // [esp-4h] [ebp-14h]
  unsigned int v17; // [esp-4h] [ebp-14h]
  unsigned int v18; // [esp-4h] [ebp-14h]
  unsigned int v19; // [esp-4h] [ebp-14h]
  unsigned int v20; // [esp-4h] [ebp-14h]
  unsigned int v21; // [esp-4h] [ebp-14h]
  unsigned int v22; // [esp-4h] [ebp-14h]
  unsigned int v23; // [esp-4h] [ebp-14h]
  unsigned int v24; // [esp-4h] [ebp-14h]
  LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-10h] BYREF
  LARGE_INTEGER v26; // [esp+8h] [ebp-8h] BYREF

  NumberOfRandCalls = CRandom16::GetNumberOfRandCalls((CUserToolsManager *)((char *)g_pGameData + 44));
  Seed = CRandom16::GetSeed((CUserToolsManager *)((char *)g_pGameData + 44));
  TickCounter = CGameData::GetTickCounter(g_pGameData);
  IMessageTracer::PushFormatedInts(
    (IMessageTracer *)g_pMsgTracer,
    "==> GameRun::Run(): tick %u, seed 0x%08x, counter %u",
    TickCounter,
    Seed,
    NumberOfRandCalls);
  if ( !CGameRun::m_bInitialized && BBSupportDbgReport(2, "main\\GameRun.cpp", 491, "m_bInitialized") == 1 )
    __debugbreak();
  SetCamWndViewPosition();
  QueryPerformanceCounter(&PerformanceCount);
  v15 = CRandom16::GetNumberOfRandCalls((CUserToolsManager *)((char *)g_pGameData + 44));
  v1 = CRandom16::GetSeed((CUserToolsManager *)((char *)g_pGameData + 44));
  IMessageTracer::PushFormatedInts(
    (IMessageTracer *)g_pMsgTracer,
    "--> Logic::Update(): seed 0x%08x, counter %u",
    v1,
    v15);
  CLogic::LogicUpdate(g_pLogic);
  QueryPerformanceCounter(&v26);
  g_iLogicTicks = v26.LowPart - PerformanceCount.LowPart;
  QueryPerformanceCounter(&PerformanceCount);
  v16 = CRandom16::GetNumberOfRandCalls((CUserToolsManager *)((char *)g_pGameData + 44));
  v2 = CRandom16::GetSeed((CUserToolsManager *)((char *)g_pGameData + 44));
  IMessageTracer::PushFormatedInts((IMessageTracer *)g_pMsgTracer, "--> AI::Update(): seed 0x%08x, counter %u", v2, v16);
  (*(void (__thiscall **)(void *))(*(_DWORD *)off_3D7A3D8 + 24))(off_3D7A3D8);
  QueryPerformanceCounter(&v26);
  g_iAITicks = v26.LowPart - PerformanceCount.LowPart;
  QueryPerformanceCounter(&PerformanceCount);
  v17 = CRandom16::GetNumberOfRandCalls((CUserToolsManager *)((char *)g_pGameData + 44));
  v3 = CRandom16::GetSeed((CUserToolsManager *)((char *)g_pGameData + 44));
  IMessageTracer::PushFormatedInts(
    (IMessageTracer *)g_pMsgTracer,
    "--> Tiling::Update(): seed 0x%08x, counter %u",
    v3,
    v17);
  (*(void (__thiscall **)(void *))(*(_DWORD *)g_pTiling + 8))(g_pTiling);
  QueryPerformanceCounter(&v26);
  g_iTilingTicks = v26.LowPart - PerformanceCount.LowPart;
  QueryPerformanceCounter(&PerformanceCount);
  v18 = CRandom16::GetNumberOfRandCalls((CUserToolsManager *)((char *)g_pGameData + 44));
  v4 = CRandom16::GetSeed((CUserToolsManager *)((char *)g_pGameData + 44));
  IMessageTracer::PushFormatedInts(
    (IMessageTracer *)g_pMsgTracer,
    "--> Script::Update(): seed 0x%08x, counter %u",
    v4,
    v18);
  v5 = CGameData::GetTickCounter(g_pGameData);
  CGameScriptManager::Update((CGameScriptManager *)g_pScriptMgr, v5);
  QueryPerformanceCounter(&v26);
  g_iScriptingTicks = v26.LowPart - PerformanceCount.LowPart;
  QueryPerformanceCounter(&PerformanceCount);
  v19 = CRandom16::GetNumberOfRandCalls((CUserToolsManager *)((char *)g_pGameData + 44));
  v6 = CRandom16::GetSeed((CUserToolsManager *)((char *)g_pGameData + 44));
  IMessageTracer::PushFormatedInts(
    (IMessageTracer *)g_pMsgTracer,
    "--> Animal::Update(): seed 0x%08x, counter %u",
    v6,
    v19);
  CAnimalMgr::Update((CAnimalMgr *)&g_cAnimalMgr);
  QueryPerformanceCounter(&v26);
  g_iAnimalTicks = v26.LowPart - PerformanceCount.LowPart;
  v20 = CRandom16::GetNumberOfRandCalls((CUserToolsManager *)((char *)g_pGameData + 44));
  v7 = CRandom16::GetSeed((CUserToolsManager *)((char *)g_pGameData + 44));
  IMessageTracer::PushFormatedInts(
    (IMessageTracer *)g_pMsgTracer,
    "--> Sound::Update(): seed 0x%08x, counter %u",
    v7,
    v20);
  CSoundManager::Update((CSoundManager *)g_pSoundManager);
  v21 = CRandom16::GetNumberOfRandCalls((CUserToolsManager *)((char *)g_pGameData + 44));
  v8 = CRandom16::GetSeed((CUserToolsManager *)((char *)g_pGameData + 44));
  IMessageTracer::PushFormatedInts(
    (IMessageTracer *)g_pMsgTracer,
    "--> EcoSector::Update(): seed 0x%08x, counter %u",
    v8,
    v21);
  CEcoSectorMgr::Update((CEcoSectorMgr *)g_cESMgr);
  v22 = CRandom16::GetNumberOfRandCalls((CUserToolsManager *)((char *)g_pGameData + 44));
  v9 = CRandom16::GetSeed((CUserToolsManager *)((char *)g_pGameData + 44));
  IMessageTracer::PushFormatedInts(
    (IMessageTracer *)g_pMsgTracer,
    "--> Minimap::Update(): seed 0x%08x, counter %u",
    v9,
    v22);
  CMinimapHandler::UpdateAlliances();
  v23 = CRandom16::GetNumberOfRandCalls((CUserToolsManager *)((char *)g_pGameData + 44));
  v10 = CRandom16::GetSeed((CUserToolsManager *)((char *)g_pGameData + 44));
  IMessageTracer::PushFormatedInts(
    (IMessageTracer *)g_pMsgTracer,
    "--> Statistic::Update(): seed 0x%08x, counter %u",
    v10,
    v23);
  CStatistic::Update((CStatistic *)&g_cStatistic);
  CEcoSectorMgr::DBG_CheckEcoSectors((CEcoSectorMgr *)g_cESMgr);
  v24 = CRandom16::GetNumberOfRandCalls((CUserToolsManager *)((char *)g_pGameData + 44));
  v11 = CRandom16::GetSeed((CUserToolsManager *)((char *)g_pGameData + 44));
  IMessageTracer::PushFormatedInts(
    (IMessageTracer *)g_pMsgTracer,
    "--> End of CGameRun::Run(): seed 0x%08x, counter %u",
    v11,
    v24);
  return 1;
}


// address=[0x1482c40]
// Decompiled from char CGameRun::Exit()

static bool __cdecl CGameRun::Exit(void) {
  
  int v1; // [esp+0h] [ebp-3Ch]

  IMessageTracer::PushStaticText(g_pMsgTracer, "==> CGameRun::Exit()...");
  IMessageTracer::Done(g_pMsgTracer);
  IMessageTracer::Done(g_pMsgTracer2);
  (*(void (__thiscall **)(void *))(*(_DWORD *)g_pFogging + 12))(g_pFogging);
  IGfxEngine::SetObjectLayerAccess((IGfxEngine *)g_pGfxEngine, 0, 0, 0);
  (*(void (__thiscall **)(void *))(*(_DWORD *)off_3D7A3D8 + 20))(off_3D7A3D8);
  if ( g_pScriptMgr )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)g_pScriptMgr + 8))(g_pScriptMgr, 1);
    g_pScriptMgr = 0;
  }
  if ( g_pEntityToDoListMgr )
  {
    CEntityToDoListMgr::`scalar deleting destructor'((CEntityToDoListMgr *)g_pEntityToDoListMgr, 1u);
    g_pEntityToDoListMgr = 0;
  }
  if ( g_pMapObjectMgr )
  {
    CMapObjectMgr::`scalar deleting destructor'(g_pMapObjectMgr, 1u);
    g_pMapObjectMgr = 0;
  }
  CAnimalMgr::ShutDown((CAnimalMgr *)&g_cAnimalMgr);
  if ( g_pLogic )
  {
    (**(void (__thiscall ***)(CPaneContainer *, int))g_pLogic)(g_pLogic, 1);
    g_pLogic = 0;
  }
  if ( *(_DWORD *)(g_pGame + 252) )
  {
    v1 = (***(int (__thiscall ****)(_DWORD, int))(g_pGame + 252))(*(_DWORD *)(g_pGame + 252), 1);
    *(_DWORD *)(g_pGame + 252) = 0;
  }
  CPlayerManager::Done(v1);
  (*(void (__thiscall **)(void *))(*(_DWORD *)g_pTiling + 4))(g_pTiling);
  CWorldManager::Destruct();
  CGameRun::m_bInitialized = 0;
  return 1;
}


// address=[0x1482e30]
// Decompiled from char __cdecl CGameRun::LoadGame(int a1)

static bool __cdecl CGameRun::LoadGame(std::wstring &) {
  
  const char *v1; // eax
  int v3; // [esp+0h] [ebp-E98h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-E88h] BYREF
  struct CMapFile *v5; // [esp+1Ch] [ebp-E7Ch]
  void *v6; // [esp+20h] [ebp-E78h]
  int v7; // [esp+24h] [ebp-E74h]
  int v8; // [esp+28h] [ebp-E70h]
  int v9; // [esp+2Ch] [ebp-E6Ch]
  int v10; // [esp+30h] [ebp-E68h]
  int v11; // [esp+34h] [ebp-E64h]
  CInternationalTrader *v12; // [esp+38h] [ebp-E60h]
  CInternationalTrader *v13; // [esp+3Ch] [ebp-E5Ch]
  int v14; // [esp+40h] [ebp-E58h]
  int v15; // [esp+44h] [ebp-E54h]
  char v16; // [esp+4Bh] [ebp-E4Dh]
  _BYTE v17[2376]; // [esp+4Ch] [ebp-E4Ch] BYREF
  int v18; // [esp+994h] [ebp-504h]
  unsigned int v19; // [esp+99Ch] [ebp-4FCh]
  unsigned int v20; // [esp+9A0h] [ebp-4F8h]
  int v21; // [esp+9A4h] [ebp-4F4h]
  int v22; // [esp+9A8h] [ebp-4F0h]
  int v23; // [esp+9ACh] [ebp-4ECh]
  char v24; // [esp+9B0h] [ebp-4E8h]
  struct S4::CMapFile *v25; // [esp+9B4h] [ebp-4E4h] BYREF
  _BYTE v26[28]; // [esp+E4Ch] [ebp-4Ch] BYREF
  _BYTE v27[28]; // [esp+E68h] [ebp-30h] BYREF
  int *v28; // [esp+E88h] [ebp-10h]
  int v29; // [esp+E94h] [ebp-4h]

  v28 = &v3;
  std::wstring::wstring(a1);
  v29 = 0;
  (*(void (__thiscall **)(void *, _BYTE *))(*(_DWORD *)g_pRandomMaps + 52))(g_pRandomMaps, v27);
  LOBYTE(v29) = 1;
  CTrace::Print("CGame loadgame\n");
  BBSupportTracePrintF(1, "------------------------------------------------------------------");
  v1 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v27);
  BBSupportTracePrintF(1, "Start loading %s", v1);
  v6 = SaveFilePath::BuildSaveFilePath(v26, (int)v27);
  LOBYTE(v29) = 2;
  v5 = S4::CMapFile::CMapFile((CHandleMap *)&v25, 0);
  LOBYTE(v29) = 3;
  S4::CMapFile::Open((S4::CMapFile *)&v25, (int)v26, 1, 1);
  BBSupportTracePrintF(1, "\tOpen map file\t\tok");
  CWarMap::Init();
  CWorldManager::LoadMap((struct S4::CMapFile *)&v25, *(_DWORD *)(g_pGameType + 56));
  BBSupportTracePrintF(1, "\tLoad LoadMap\t\tok");
  CEcoSectorMgr::Load(g_cESMgr, (S4::CMapFile *)&v25);
  BBSupportTracePrintF(1, "\tLoad EsMgr\t\tok");
  CMapObjectMgr::Load(g_pMapObjectMgr, (struct S4::CMapFile *)&v25);
  BBSupportTracePrintF(1, "\tLoad MapObjectMgr\t\tok");
  CPileMgr::Load((CPileMgr *)&g_cPileMgr, (struct S4::CMapFile *)&v25);
  BBSupportTracePrintF(1, "\tLoad PileMgr\t\tok");
  CAnimalMgr::Load((CAnimalMgr *)&g_cAnimalMgr, (struct S4::CMapFile *)&v25);
  BBSupportTracePrintF(1, "\tLoad AnimalMgr\t\tok");
  CInternationalTrader::ReInit();
  LOBYTE(v29) = 4;
  v13 = CInternationalTrader::CInternationalTrader((CInternationalTrader *)v4);
  v12 = v13;
  LOBYTE(v29) = 5;
  S4::CMapFile::LoadChunkObject(&v25, 167, 0, v13, 0);
  LOBYTE(v29) = 4;
  CInternationalTrader::~CInternationalTrader((CInternationalTrader *)v4);
  BBSupportTracePrintF(1, "\tLoad GAME_CHUNK_InternationalTrader\t\tok");
  v29 = 3;
  CBuildingMgr::Load((CBuildingMgr *)g_cBuildingMgr, (struct S4::CMapFile *)&v25);
  BBSupportTracePrintF(1, "\tLoad BuildingMrg\t\tok");
  CSettlerMgr::Load((CSettlerMgr *)g_cSettlerMgr, (struct S4::CMapFile *)&v25);
  BBSupportTracePrintF(1, "\tLoad SettlerMgr\t\tok");
  CVehicleMgr::Load((CVehicleMgr *)&g_cVehicleMgr, (struct S4::CMapFile *)&v25);
  BBSupportTracePrintF(1, "\tLoad VehicleMgr\t\tok");
  CFlyingMgr::Load((CFlyingMgr *)g_cFlyingMgr, (struct S4::CMapFile *)&v25);
  BBSupportTracePrintF(1, "\tLoad FlyingMgr\t\tok");
  v11 = CLogic::FutureEvents(g_pLogic);
  S4::CMapFile::LoadChunkObject(&v25, 142, 0, v11, 1);
  BBSupportTracePrintF(1, "\tLoad FUTURE_EVENTS\t\tok");
  v10 = CLogic::Effects((DWORD *)g_pLogic);
  v15 = v10;
  if ( v10 )
    v14 = v15 + 4;
  else
    v14 = 0;
  S4::CMapFile::LoadChunkObject(&v25, 143, 0, v14, 1);
  BBSupportTracePrintF(1, "\tLoad GAME_CHUNK_EFFECTS\t\tok");
  CDecoObjMgr::Load((CDecoObjMgr *)&g_cDecoObjMgr, (struct S4::CMapFile *)&v25);
  BBSupportTracePrintF(1, "\tLoad DecoObjMgr\t\tok");
  S4::CMapFile::LoadChunkObject(&v25, 131, 0, g_pScriptMgr, 0);
  BBSupportTracePrintF(1, "\tLoad GAME_CHUNK_SCRIPT\t\tok");
  S4::CMapFile::LoadChunkObject(&v25, 140, 0, &g_cPlayerMgr, 0);
  BBSupportTracePrintF(1, "\tLoad GAME_CHUNK_PLAYER_GAMEDATA\t\tok");
  S4::CMapFile::LoadChunkObject(&v25, 133, 0, &g_cStatistic, 0);
  S4::CMapFile::LoadChunkObject(&v25, 137, 0, &g_cStatisticArchive, 0);
  BBSupportTracePrintF(1, "\tLoad GAME_CHUNK_STATISTIC\t\tok");
  if ( !g_pGroupMgr )
  {
    v9 = BBSupportDbgReport(2, "main\\GameRun.cpp", 894, "g_pGroupMgr!=NULL");
    if ( v9 == 1 )
      __debugbreak();
  }
  (*(void (__thiscall **)(void *))(*(_DWORD *)g_pGroupMgr + 8))(g_pGroupMgr);
  S4::CMapFile::LoadChunkObject(&v25, 134, 0, g_pGroupMgr, 0);
  BBSupportTracePrintF(1, "\tLoad GAME_CHUNK_GROUP\t\tok");
  if ( !g_pFogging )
  {
    v8 = BBSupportDbgReport(2, "main\\GameRun.cpp", 899, "g_pFogging!=NULL");
    if ( v8 == 1 )
      __debugbreak();
  }
  S4::CMapFile::LoadChunkObject(&v25, 135, 0, g_pFogging, 0);
  BBSupportTracePrintF(1, "\tLoad GAME_CHUNK_FOGMAP\t\tok");
  (*(void (__thiscall **)(void *))(*(_DWORD *)off_3D7A3D8 + 12))(off_3D7A3D8);
  S4::CMapFile::LoadChunkObject(&v25, 150, 0, off_3D7A3D8, 1);
  BBSupportTracePrintF(1, "\tLoad GAME_CHUNK_AI\t\tok");
  CGameChunkGeneral::CGameChunkGeneral(v17);
  S4::CMapFile::LoadChunkObject(&v25, 130, 0, v17, 0);
  if ( *(_DWORD *)(g_pGameType + 700) != v18 )
  {
    v7 = BBSupportDbgReport(
           2,
           "main\\GameRun.cpp",
           910,
           "g_pGameType->m_uiTickCounter == sGameChunkGeneral.m_uiTickCounter");
    if ( v7 == 1 )
      __debugbreak();
  }
  *(_DWORD *)(g_pGame + 76) = *(_DWORD *)(g_pGameType + 700);
  CRandom16Ex::Init((CRandom16Ex *)(g_pGame + 120), v19, v20);
  *(_BYTE *)(g_pGame + 117) = v24;
  if ( *(_BYTE *)(g_pGame + 117) )
  {
    *(_DWORD *)(g_pGame + 96) = v21;
    *(_DWORD *)(g_pGame + 100) = v22;
    *(_DWORD *)(g_pGame + 104) = v23;
    CStateGame::UpdateZoomFactor((CStateGame *)g_pGame);
  }
  S4::CMapFile::Close((S4::CMapFile *)&v25);
  UpdateReefBlockingBits();
  GuiDlgLoadSaveUpdateProgress(0);
  BBSupportTracePrintF(1, "All Done");
  BBSupportTracePrintF(1, "------------------------------------------------------------------");
  v16 = 1;
  LOBYTE(v29) = 2;
  S4::CMapFile::~CMapFile((CHandleMap *)&v25);
  LOBYTE(v29) = 1;
  std::wstring::~wstring(v26);
  v29 = -1;
  std::wstring::~wstring(v27);
  return v16;
}


// address=[0x1483510]
// Decompiled from char __cdecl CGameRun::SaveGame(_Cnd_internal_imp_t *a1)

static bool __cdecl CGameRun::SaveGame(std::wstring &) {
  
  const char *v1; // eax
  int v3; // [esp+0h] [ebp-504h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-4F4h] BYREF
  CInternationalTrader *v5; // [esp+1Ch] [ebp-4E8h]
  struct CMapFile *v6; // [esp+20h] [ebp-4E4h]
  char v7[4]; // [esp+24h] [ebp-4E0h] BYREF
  int v8; // [esp+28h] [ebp-4DCh]
  struct IS4ChunkObject *v9; // [esp+2Ch] [ebp-4D8h]
  struct IS4ChunkObject *v10; // [esp+30h] [ebp-4D4h]
  int v11; // [esp+34h] [ebp-4D0h]
  char v12; // [esp+3Ah] [ebp-4CAh]
  char v13; // [esp+3Bh] [ebp-4C9h]
  _BYTE v14[1176]; // [esp+3Ch] [ebp-4C8h] BYREF
  _BYTE v15[28]; // [esp+4D4h] [ebp-30h] BYREF
  int *v16; // [esp+4F4h] [ebp-10h]
  int v17; // [esp+500h] [ebp-4h]

  v16 = &v3;
  v1 = (const char *)std::wstring::c_str(a1);
  BBSupportTracePrintF(1, "Saving %s...", v1);
  v13 = 1;
  CGameRun::m_iSaveCounter = 0;
  CGameRun::m_iSaveTotal = 20;
  GuiDlgLoadSaveUpdateProgress(0);
  SaveFilePath::BuildSaveFilePath(v15, (int)a1);
  v17 = 1;
  v6 = S4::CMapFile::CMapFile((CHandleMap *)v14, 0);
  LOBYTE(v17) = 2;
  BBSupportTracePrintF(1, "Opening file...");
  FilePaths::EnsurePathExists(v15, v3);
  S4::CMapFile::Open((S4::CMapFile *)v14, (int)v15, 2, 1);
  CGameRun::SaveInfoAndUpdateGUI((struct S4::CMapFile *)v14, "GENERAL", 0);
  CGameRun::SaveGeneralInfo((struct S4::CMapFile *)v14);
  CGameRun::SaveInfoAndUpdateGUI((struct S4::CMapFile *)v14, "CURRENT", 0);
  CGameRun::SaveCurrentData((struct S4::CMapFile *)v14);
  CGameRun::SaveInfoAndUpdateGUI((struct S4::CMapFile *)v14, "WORLD", 0);
  CWorldManager::SaveMap((struct S4::CMapFile *)v14);
  v9 = (struct IS4ChunkObject *)CLogic::FutureEvents(g_pLogic);
  CGameRun::SaveChunkObject((struct S4::CMapFile *)v14, 0x8Eu, 0, v9, "FUTUREEVENTS", 0);
  v8 = CLogic::Effects((DWORD *)g_pLogic);
  v11 = v8;
  if ( v8 )
    v10 = (struct IS4ChunkObject *)(v11 + 4);
  else
    v10 = 0;
  CGameRun::SaveChunkObject((struct S4::CMapFile *)v14, 0x8Fu, 0, v10, "EFFECTS", 0);
  CGameRun::SaveChunkObject((struct S4::CMapFile *)v14, 0x96u, 0, (struct IS4ChunkObject *)off_3D7A3D8, "AI", 0);
  CGameRun::SaveInfoAndUpdateGUI((struct S4::CMapFile *)v14, "ES", 0);
  CEcoSectorMgr::Store((CEcoSectorMgr *)g_cESMgr, (struct S4::CMapFile *)v14);
  CGameRun::SaveInfoAndUpdateGUI((struct S4::CMapFile *)v14, "MAPOBJS", 0);
  CMapObjectMgr::Store(g_pMapObjectMgr, (struct S4::CMapFile *)v14);
  CGameRun::SaveInfoAndUpdateGUI((struct S4::CMapFile *)v14, "DECOOBJS", 0);
  CDecoObjMgr::Store((CDecoObjMgr *)&g_cDecoObjMgr, (struct S4::CMapFile *)v14);
  CGameRun::SaveInfoAndUpdateGUI((struct S4::CMapFile *)v14, "PILES", 0);
  CPileMgr::Store((CPileMgr *)&g_cPileMgr, (struct S4::CMapFile *)v14);
  CGameRun::SaveInfoAndUpdateGUI((struct S4::CMapFile *)v14, "BUILDINGS", 0);
  CBuildingMgr::Store((CBuildingMgr *)g_cBuildingMgr, (struct S4::CMapFile *)v14);
  CGameRun::SaveInfoAndUpdateGUI((struct S4::CMapFile *)v14, "SETTLERS", 0);
  CSettlerMgr::Store((CSettlerMgr *)g_cSettlerMgr, (struct S4::CMapFile *)v14);
  CGameRun::SaveInfoAndUpdateGUI((struct S4::CMapFile *)v14, "VEHICLES", 0);
  CVehicleMgr::Store((CVehicleMgr *)&g_cVehicleMgr, (struct S4::CMapFile *)v14);
  CGameRun::SaveInfoAndUpdateGUI((struct S4::CMapFile *)v14, "FLYINGENTITIES", 0);
  CFlyingMgr::Store((CFlyingMgr *)g_cFlyingMgr, (struct S4::CMapFile *)v14);
  CGameRun::SaveInfoAndUpdateGUI((struct S4::CMapFile *)v14, "ANIMALS", 0);
  CAnimalMgr::Store((CAnimalMgr *)&g_cAnimalMgr, (struct S4::CMapFile *)v14);
  CGameRun::SaveChunkObject((struct S4::CMapFile *)v14, 0x83u, 0, (struct IS4ChunkObject *)g_pScriptMgr, "SCRIPT", 0);
  CGameRun::SaveChunkObject((struct S4::CMapFile *)v14, 0x8Cu, 0, (struct IS4ChunkObject *)&g_cPlayerMgr, "PLAYERS", 0);
  CGameRun::SaveChunkObject(
    (struct S4::CMapFile *)v14,
    0x85u,
    0,
    (struct IS4ChunkObject *)&g_cStatistic,
    "STATISTIC1",
    0);
  CGameRun::SaveChunkObject(
    (struct S4::CMapFile *)v14,
    0x89u,
    0,
    (struct IS4ChunkObject *)&g_cStatisticArchive,
    "STATISTIC2",
    0);
  CGameRun::SaveChunkObject((struct S4::CMapFile *)v14, 0x86u, 0, (struct IS4ChunkObject *)g_pGroupMgr, "GROUPS", 0);
  v5 = CInternationalTrader::CInternationalTrader((CInternationalTrader *)v4);
  LOBYTE(v17) = 3;
  CGameRun::SaveChunkObject((struct S4::CMapFile *)v14, 0xA7u, 0, (struct IS4ChunkObject *)v4, "TRADERS", 0);
  CUserLogoChunk::CUserLogoChunk((CUserLogoChunk *)v7);
  CGameRun::SaveChunkObject((struct S4::CMapFile *)v14, 0x88u, 0, (struct IS4ChunkObject *)v7, "LOGO", 0);
  CGameRun::SaveChunkObject((struct S4::CMapFile *)v14, 0x87u, 0, (struct IS4ChunkObject *)g_pFogging, "FOG", 0);
  BBSupportTracePrintF(1, "Closing file...");
  S4::CMapFile::Close((S4::CMapFile *)v14);
  BBSupportTracePrintF(1, "All done.");
  LOBYTE(v17) = 2;
  CInternationalTrader::~CInternationalTrader((CInternationalTrader *)v4);
  LOBYTE(v17) = 1;
  S4::CMapFile::~CMapFile((CHandleMap *)v14);
  v17 = 0;
  if ( (unsigned __int8)CGameType::IsMultiplayerGame(g_pGameType) )
    INetworkEngine::OnEndSaving((INetworkEngine *)g_pNetworkEngine);
  GuiDlgLoadSaveUpdateProgress(0);
  v12 = v13;
  v17 = -1;
  std::wstring::~wstring(v15);
  return v12;
}


// address=[0x1483ab0]
// Decompiled from char __cdecl CGameRun::LoadGeneralInfo(struct S4::CMapFile *a1, struct CGameChunkGeneral *a2)

static bool __cdecl CGameRun::LoadGeneralInfo(class S4::CMapFile &,class CGameChunkGeneral *) {
  
  bool v3; // [esp+4h] [ebp-28h]
  bool v4; // [esp+8h] [ebp-24h]
  bool v5; // [esp+Ch] [ebp-20h]
  bool v6; // [esp+10h] [ebp-1Ch]
  bool v7; // [esp+14h] [ebp-18h]
  unsigned int v8; // [esp+1Ch] [ebp-10h]
  char v9; // [esp+24h] [ebp-8h]
  unsigned __int8 v10; // [esp+25h] [ebp-7h]
  unsigned __int8 v11; // [esp+26h] [ebp-6h]
  unsigned __int8 v12; // [esp+27h] [ebp-5h]
  bool v13; // [esp+2Bh] [ebp-1h]

  if ( !a2 && BBSupportDbgReport(2, "main\\GameRun.cpp", 1241, "_pGeneralChunk!=NULL") == 1 )
    __debugbreak();
  if ( !a2 )
    return 0;
  S4::CMapFile::LoadChunkObject(a1, 130, 0, (int)a2, 0);
  v8 = (unsigned int)&dword_F29144[203695] & *((_DWORD *)a2 + 1);
  if ( (unsigned __int16)*((_DWORD *)a2 + 1) != 8 )
    return 0;
  if ( !v8 )
    return 1;
  v13 = 1;
  if ( g_pMissionCD )
    v12 = (*(int (__thiscall **)(int))(*(_DWORD *)g_pMissionCD + 4))(g_pMissionCD);
  else
    v12 = 0;
  if ( g_pAddOn )
    v11 = (*(int (__thiscall **)(int))(*(_DWORD *)g_pAddOn + 4))(g_pAddOn);
  else
    v11 = 0;
  if ( g_pMissionCD2 )
    v10 = (*(int (__thiscall **)(int))(*(_DWORD *)g_pMissionCD2 + 4))(g_pMissionCD2);
  else
    v10 = 0;
  if ( g_pMissionCD3 )
    v9 = (*(int (__thiscall **)(int))(*(_DWORD *)g_pMissionCD3 + 4))(g_pMissionCD3);
  else
    v9 = 0;
  if ( (v8 & 0x10000) != 0 )
    v13 = v12 != 0;
  if ( (v8 & 0xA0000) != 0 )
  {
    v7 = v13 && v11;
    v13 = v7;
  }
  if ( (v8 & 0x40000) != 0 )
  {
    v6 = v13 && (v11 || v10 || v9);
    v13 = v6;
  }
  if ( ((unsigned int)&dword_420320[229176] & v8) != 0 )
  {
    v5 = v13 && v10;
    v13 = v5;
  }
  if ( (v8 & 0x200000) != 0 )
  {
    v4 = v13 && (v10 || v9);
    v13 = v4;
  }
  if ( ((unsigned int)dword_800000 & v8) != 0 )
  {
    v3 = v13 && v9;
    v13 = v3;
  }
  if ( !v13 )
    BBSupportTracePrintF(0, "LoadGeneralInfo(): Failed. MCD: %i, AO: %i, MCD2: %i; Special: 0x%08x.", v12, v11, v10, v8);
  return v13;
}


// address=[0x1483d50]
// Decompiled from char __cdecl CGameRun::LoadGeneralInfo(wchar_t *String, struct CGameChunkGeneral *a2)

static bool __cdecl CGameRun::LoadGeneralInfo(wchar_t const *,class CGameChunkGeneral &) {
  
  _DWORD v3[5]; // [esp+0h] [ebp-4FCh] BYREF
  char v4; // [esp+15h] [ebp-4E7h]
  char GeneralInfo; // [esp+16h] [ebp-4E6h]
  char v6; // [esp+17h] [ebp-4E5h]
  _BYTE v7[1176]; // [esp+18h] [ebp-4E4h] BYREF
  _BYTE v8[28]; // [esp+4B0h] [ebp-4Ch] BYREF
  _BYTE v9[28]; // [esp+4CCh] [ebp-30h] BYREF
  _DWORD *v10; // [esp+4ECh] [ebp-10h]
  int v11; // [esp+4F8h] [ebp-4h]

  v10 = v3;
  if ( !String && BBSupportDbgReport(2, "main\\GameRun.cpp", 1314, "_pFileName!= NULL") == 1 )
    __debugbreak();
  if ( !String )
    return 0;
  std::wstring::wstring(v8, String);
  v11 = 0;
  SaveFilePath::BuildSaveFilePath(v9, (int)v8);
  LOBYTE(v11) = 2;
  std::wstring::~wstring(v8);
  S4::CMapFile::CMapFile((CHandleMap *)v7, 0);
  LOBYTE(v11) = 4;
  S4::CMapFile::Open((S4::CMapFile *)v7, (int)v9, 1, 0);
  GeneralInfo = CGameRun::LoadGeneralInfo((struct S4::CMapFile *)v7, a2);
  v6 = GeneralInfo;
  if ( !GeneralInfo )
  {
    v3[4] = String;
    BBSupportTracePrintF(0, "LoadGeneralInfo() failed for \"%s\"", (const char *)String);
  }
  S4::CMapFile::Close((S4::CMapFile *)v7);
  v4 = v6;
  LOBYTE(v11) = 2;
  S4::CMapFile::~CMapFile((CHandleMap *)v7);
  v11 = -1;
  std::wstring::~wstring(v9);
  return v4;
}


// address=[0x1483f20]
// Decompiled from int __cdecl CGameRun::FillGameType(int a1, int a2, int a3)

static void __cdecl CGameRun::FillGameType(std::wstring &,class CGameType &,class CGameChunkGeneral &) {
  
  OnlineManager *Instance; // eax
  void *v4; // ecx
  int v5; // eax
  _DWORD v7[6]; // [esp+0h] [ebp-51Ch] BYREF
  int v8; // [esp+18h] [ebp-504h]
  int v9; // [esp+1Ch] [ebp-500h]
  BOOL v10; // [esp+20h] [ebp-4FCh]
  int LocalPeerId; // [esp+24h] [ebp-4F8h]
  char *v12; // [esp+28h] [ebp-4F4h]
  int v13; // [esp+2Ch] [ebp-4F0h]
  char v14; // [esp+30h] [ebp-4ECh]
  bool v15; // [esp+31h] [ebp-4EBh]
  bool v16; // [esp+32h] [ebp-4EAh]
  bool v17; // [esp+33h] [ebp-4E9h]
  unsigned int i; // [esp+34h] [ebp-4E8h]
  _BYTE v19[1176]; // [esp+38h] [ebp-4E4h] BYREF
  _BYTE v20[28]; // [esp+4D0h] [ebp-4Ch] BYREF
  _BYTE v21[28]; // [esp+4ECh] [ebp-30h] BYREF
  _DWORD *v22; // [esp+50Ch] [ebp-10h]
  int v23; // [esp+518h] [ebp-4h]

  v22 = v7;
  *(_DWORD *)(a2 + 1560) = *(_DWORD *)(a3 + 2384);
  *(_DWORD *)(a2 + 1564) = *(_DWORD *)(a3 + 2388);
  std::wstring::operator=(a1);
  v9 = std::wstring::wstring(v21, (wchar_t *)(a3 + 36));
  std::wstring::operator=(v9);
  std::wstring::~wstring(v21);
  if ( *(_DWORD *)(a3 + 644) >= 9u
    && BBSupportDbgReport(2, "main\\GameRun.cpp", 1348, "_rGeneralChunk.m_uiPlayerCount< PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  for ( i = 0; i < *(_DWORD *)(a3 + 644); ++i )
  {
    v8 = std::wstring::wstring(v20, (wchar_t *)(a3 + 84 * i + 652));
    v7[5] = v8;
    v23 = 0;
    CGameType::SetPlayerName(i, v8);
    v23 = -1;
    std::wstring::~wstring(v20);
    *(_DWORD *)(a2 + 4 * i + 116) = *(_DWORD *)(a3 + 84 * i + 648);
    if ( *(_DWORD *)(a3 + 84 * i + 648) == 1 )
      v12 = (char *)&dword_F29144[220110] + 3;
    else
      v12 = 0;
    *(_DWORD *)(a2 + 4 * i + 188) = v12;
    if ( *(_DWORD *)(a3 + 84 * i + 648) == 1 )
    {
      Instance = (OnlineManager *)OnlineManager::GetInstance();
      LocalPeerId = OnlineManager::GetLocalPeerId(Instance);
    }
    else
    {
      LocalPeerId = -1;
    }
    *(_DWORD *)(a2 + 4 * i + 224) = LocalPeerId;
    *(_DWORD *)(a2 + 4 * i + 260) = *(_DWORD *)(a3 + 84 * i + 720);
    *(_DWORD *)(a2 + 4 * i + 296) = *(_DWORD *)(a3 + 84 * i + 724);
    *(_DWORD *)(a2 + 4 * i + 332) = *(_DWORD *)(a3 + 84 * i + 716);
    v17 = *(_DWORD *)(a2 + 4 * i + 116) == 0;
    *(_BYTE *)(i + a2 + 440) = v17;
    *(_DWORD *)(a2 + 4 * i + 152) = *(unsigned __int8 *)(a3 + 84 * i + 728);
  }
  if ( *(_DWORD *)(a3 + 2360) != -1 )
  {
    *(_BYTE *)(a2 + 748) = 1;
    *(_DWORD *)(a2 + 752) = *(_DWORD *)(a3 + 2360);
  }
  *(_DWORD *)(a2 + 864) = *(unsigned __int8 *)(a3 + 2356);
  j__memcpy((void *)(a2 + 784), (const void *)(a3 + 2349), 7u);
  *(_DWORD *)(a2 + 692) = *(_DWORD *)(a3 + 16);
  *(_DWORD *)(a2 + 740) = *(_DWORD *)(a3 + 8);
  *(_DWORD *)(a2 + 744) = *(_DWORD *)(a3 + 12);
  std::wstring::operator=((void *)(a2 + 28), (wchar_t *)(a3 + 100));
  v10 = *(_DWORD *)(a3 + 16) != 2;
  *(_BYTE *)(a2 + 732) = v10;
  *(_DWORD *)(a2 + 700) = *(_DWORD *)(a3 + 2376);
  *(_DWORD *)(a2 + 660) = *(_DWORD *)(a3 + 2380);
  *(_DWORD *)(a2 + 56) = *(_DWORD *)(a3 + 32);
  CGameType::SetMultiPlayerGameID((CGameType *)a2, *(_DWORD *)(a3 + 1320));
  *(_DWORD *)(a2 + 68) = (char *)&dword_F29144[220110] + 3;
  *(_DWORD *)(a2 + 112) = *(_DWORD *)(a3 + 644);
  *(_DWORD *)(a2 + 852) = *(_DWORD *)(a3 + 640);
  v16 = (*(_DWORD *)(a3 + 4) & 0x200000) != 0;
  CGameType::SetMCD2TextureSet((CGameType *)a2, v16);
  v15 = (*(_DWORD *)(a3 + 4) & 0x100000) != 0;
  CGameType::SetBlueByteMCD2Map((CGameType *)a2, v15);
  v13 = 0;
  for ( i = 0; i < *(_DWORD *)(a2 + 112); ++i )
  {
    if ( *(_DWORD *)(a2 + 4 * i + 152) > v13 )
      v13 = *(_DWORD *)(a2 + 4 * i + 152);
  }
  *(_DWORD *)(a2 + 72) = v13 + 1;
  if ( !*(_DWORD *)(a2 + 864) )
  {
    if ( *(_DWORD *)(a2 + 72) == 1 )
      *(_DWORD *)(a2 + 864) = 5;
    else
      *(_DWORD *)(a2 + 864) = 1;
  }
  if ( *(char *)(a3 + 2364) == -1 )
    *(_BYTE *)(a3 + 2364) = 0;
  CGameType::SetClanGame((CGameType *)a2, *(_BYTE *)(a3 + 2372));
  CGameType::SetLocalSlot((CGameType *)a2, *(_BYTE *)(a3 + 2364));
  CGameType::SetHost((CGameType *)a2, *(_BYTE *)(a3 + 2365));
  CGameType::SetMPSavegameID((CGameType *)a2, *(_DWORD *)(a3 + 2368));
  v14 = 1;
  v23 = 1;
  v7[4] = S4::CMapFile::CMapFile((CHandleMap *)v19, 0);
  LOBYTE(v23) = 2;
  S4::CMapFile::Open((S4::CMapFile *)v19, a1, 1, 0);
  BBSupportTracePrintF(1, "\tOpen map file\t\tok");
  CPlayerManager::Init(v4);
  S4::CMapFile::LoadChunkObject(v19, 140, 0, (int)&g_cPlayerMgr, 0);
  BBSupportTracePrintF(1, "\tLoad GAME_CHUNK_PLAYER_GAMEDATA\t\tok");
  CPlayerManager::Lock();
  S4::CMapFile::Close((S4::CMapFile *)v19);
  BBSupportTracePrintF(1, "\tDone\t\tok");
  LOBYTE(v23) = 1;
  S4::CMapFile::~CMapFile((CHandleMap *)v19);
  v23 = -1;
  if ( v14 )
  {
    for ( i = 0; i < *(_DWORD *)(a2 + 112); ++i )
    {
      v5 = CPlayerManager::Race(i + 1);
      *(_DWORD *)(a2 + 4 * i + 404) = v5;
    }
  }
  return CPlayerManager::Done(v7[0]);
}


// address=[0x14845a0]
// Decompiled from char __thiscall CGameRun::SetupPlayersAndAlliances(void *this)

static void __cdecl CGameRun::SetupPlayersAndAlliances(void) {
  
  char v2; // [esp-20h] [ebp-5Ch] BYREF
  int v3; // [esp-1Ch] [ebp-58h]
  int v4; // [esp-18h] [ebp-54h]
  int v5; // [esp-14h] [ebp-50h]
  int v6; // [esp-10h] [ebp-4Ch]
  int v7; // [esp-Ch] [ebp-48h]
  int v8; // [esp-8h] [ebp-44h]
  int v9; // [esp-4h] [ebp-40h]
  void *PlayerName; // [esp+0h] [ebp-3Ch]
  char *v11; // [esp+4h] [ebp-38h]
  int v12; // [esp+8h] [ebp-34h]
  int v13; // [esp+Ch] [ebp-30h]
  signed int i; // [esp+10h] [ebp-2Ch]
  _DWORD v15[9]; // [esp+14h] [ebp-28h] BYREF

  CPlayerManager::Init(this);
  j__memset(v15, 0, sizeof(v15));
  v13 = 0;
  for ( i = 0; i < *(_DWORD *)(g_pGameType + 852); ++i )
  {
    if ( !*(_BYTE *)(i + g_pGameType + 440) )
    {
      v9 = *(_DWORD *)(g_pGameType + 4 * i + 116);
      v11 = &v2;
      PlayerName = CGameType::GetPlayerName((void *)g_pGameType, &v2, i);
      CPlayerManager::AddPlayer(
        *(_DWORD *)(g_pGameType + 4 * i + 404),
        *(_DWORD *)(g_pGameType + 4 * i + 260),
        *(_DWORD *)(g_pGameType + 4 * i + 296),
        *(_DWORD *)(g_pGameType + 4 * i + 332),
        *(_DWORD *)(g_pGameType + 4 * i + 188),
        *(_DWORD *)(g_pGameType + 4 * i + 224),
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9);
      v12 = *(_DWORD *)(g_pGameType + 4 * i + 152);
      if ( v12 > 8 )
        v12 = 0;
      if ( v12 > v13 )
        v13 = v12;
    }
  }
  CPlayerManager::Lock();
  CGameRun::GetUsedTeam(v13, v15);
  for ( i = 0; i <= v13; ++i )
  {
    if ( !v15[i] )
    {
      CGameRun::RemoveEmptyTeamSlot(i);
      CGameRun::GetUsedTeam(--v13, v15);
    }
  }
  CAlliances::Init();
  for ( i = 0; i < *(_DWORD *)(g_pGameType + 852); ++i )
  {
    if ( !*(_BYTE *)(i + g_pGameType + 440) )
      CAlliances::AddPlayer(i + 1, *(_DWORD *)(g_pGameType + 4 * i + 152) + 1);
  }
  return CAlliances::Lock();
}


// address=[0x14847b0]
// Decompiled from int __cdecl CGameRun::RemoveEmptyTeamSlot(int a1)

static void __cdecl CGameRun::RemoveEmptyTeamSlot(int) {
  
  int result; // eax
  int i; // [esp+0h] [ebp-4h]

  for ( i = 0; i < *(_DWORD *)(g_pGameType + 852); ++i )
  {
    if ( *(_DWORD *)(g_pGameType + 4 * i + 152) > a1 )
      --*(_DWORD *)(g_pGameType + 4 * i + 152);
    result = i + 1;
  }
  return result;
}


// address=[0x1484820]
// Decompiled from void *__cdecl CGameRun::GetUsedTeam(int a1, void *a2)

static void __cdecl CGameRun::GetUsedTeam(int,int *) {
  
  void *result; // eax
  int i; // [esp+4h] [ebp-4h]

  result = j__memset(a2, 0, 4 * a1 + 4);
  for ( i = 0; i < *(_DWORD *)(g_pGameType + 852); ++i )
  {
    *((_DWORD *)a2 + *(_DWORD *)(g_pGameType + 4 * i + 152)) = 1;
    result = (void *)(i + 1);
  }
  return result;
}


// address=[0x1484890]
// Decompiled from char __cdecl CGameRun::LoadGeneralEditorInfo(struct S4::CMapFile *a1)

static bool __cdecl CGameRun::LoadGeneralEditorInfo(class S4::CMapFile &) {
  
  int v2; // [esp+0h] [ebp-8h] BYREF
  void *v3; // [esp+4h] [ebp-4h]

  v3 = S4::CMapFile::LoadChunk(a1, 1u, 0, &v2, 0);
  if ( !v3 && BBSupportDbgReport(2, "main\\GameRun.cpp", 1609, "pGeneral != NULL") == 1 )
    __debugbreak();
  S4::CMapFile::CloseChunk(a1, 1u, 0);
  return 1;
}


// address=[0x14848f0]
// Decompiled from char __cdecl CGameRun::SaveGeneralInfo(struct S4::CMapFile *a1)

static bool __cdecl CGameRun::SaveGeneralInfo(class S4::CMapFile &) {
  
  const char *v1; // eax
  const wchar_t *v2; // eax
  const wchar_t *v3; // eax
  const char *v4; // eax
  _Cnd_internal_imp_t *RealPlayerName; // eax
  const wchar_t *v6; // eax
  void *DateTimeString; // [esp+0h] [ebp-998h]
  BOOL v9; // [esp+4h] [ebp-994h]
  int v10; // [esp+8h] [ebp-990h]
  int i; // [esp+Ch] [ebp-98Ch]
  signed int j; // [esp+Ch] [ebp-98Ch]
  _BYTE v13[4]; // [esp+10h] [ebp-988h] BYREF
  int v14; // [esp+14h] [ebp-984h]
  int v15; // [esp+18h] [ebp-980h]
  int v16; // [esp+1Ch] [ebp-97Ch]
  int v17; // [esp+20h] [ebp-978h]
  int v18; // [esp+24h] [ebp-974h]
  int v19; // [esp+28h] [ebp-970h]
  int v20; // [esp+2Ch] [ebp-96Ch]
  int v21; // [esp+30h] [ebp-968h]
  wchar_t v22[32]; // [esp+34h] [ebp-964h] BYREF
  wchar_t v23[256]; // [esp+74h] [ebp-924h] BYREF
  char Destination[28]; // [esp+274h] [ebp-724h] BYREF
  int v25; // [esp+290h] [ebp-708h]
  int PlayerId; // [esp+294h] [ebp-704h]
  _DWORD v28[168]; // [esp+29Ch] [ebp-6FCh] BYREF
  char v29[1025]; // [esp+53Ch] [ebp-45Ch] BYREF
  _BYTE v30[11]; // [esp+93Dh] [ebp-5Bh] BYREF
  unsigned int v31; // [esp+948h] [ebp-50h]
  char LocalSlot; // [esp+94Ch] [ebp-4Ch]
  char IsHost; // [esp+94Dh] [ebp-4Bh]
  char IsClanGame; // [esp+954h] [ebp-44h]
  int VirtualTick; // [esp+958h] [ebp-40h]
  int v36; // [esp+95Ch] [ebp-3Ch]
  int Seed; // [esp+960h] [ebp-38h]
  int NumberOfRandCalls; // [esp+964h] [ebp-34h]
  int v39; // [esp+968h] [ebp-30h]
  int v40; // [esp+96Ch] [ebp-2Ch]
  int v41; // [esp+970h] [ebp-28h]
  _BYTE v42[28]; // [esp+978h] [ebp-20h] BYREF

  CGameChunkGeneral::CGameChunkGeneral(v13);
  j__memset(Destination, 0, 0x1Au);
  v9 = CGameSettings::GetLanguage() == 1;
  DateTimeString = (void *)CTimeInfo::GetDateTimeString(v42, v9);
  v1 = (const char *)std::string::c_str(DateTimeString);
  j__strcpy_0(Destination, v1);
  std::string::~string(v42);
  v10 = 8;
  if ( CGameType::IsCampaignMap((CGameType *)g_pGameType) )
  {
    if ( *(int *)(g_pGameType + 740) < 5 || *(int *)(g_pGameType + 740) >= 11 )
    {
      if ( *(int *)(g_pGameType + 740) < 11 || *(int *)(g_pGameType + 740) >= 17 )
      {
        if ( *(int *)(g_pGameType + 740) < 17 || *(int *)(g_pGameType + 740) >= 21 )
        {
          if ( *(int *)(g_pGameType + 740) >= 21 && *(int *)(g_pGameType + 740) < 25 )
            v10 = (int)&dword_800000[2];
        }
        else
        {
          v10 = 4194312;
        }
      }
      else
      {
        v10 = 131080;
      }
    }
    else
    {
      v10 = 65544;
    }
  }
  for ( i = 1; i < CPlayerManager::LastPlayerId(); ++i )
  {
    if ( CPlayerManager::Race(i) == 4 )
    {
      v10 |= 0x40000u;
      break;
    }
  }
  if ( CGameType::IsBlueByteAddOnMap((CGameType *)g_pGameType) )
    v10 |= 0x80000u;
  if ( CGameType::IsBlueByteMCD2Map((CGameType *)g_pGameType) )
    v10 |= 0x100000u;
  if ( CGameType::IsMCD2TextureSet((CGameType *)g_pGameType) )
    v10 |= 0x200000u;
  BBSupportTracePrintF(0, "SaveGeneralInfo(): Special: 0x%08x.", (unsigned int)&dword_F29144[203695] & v10);
  v14 = v10;
  v18 = g_iApplicationVersionMajor;
  v19 = g_iApplicationVersionMinor;
  v20 = g_iApplicationVersionBuild;
  v21 = *((_DWORD *)g_pGameData + 2);
  VirtualTick = INetworkEngine::GetVirtualTick((CGameHost **)g_pNetworkEngine);
  if ( CGameData::IsGameWon(g_pGameData) )
    v31 = CGameData::TeamWon(g_pGameData);
  else
    v31 = -1;
  v28[167] = CGameType::GetMultiPlayerGameID(g_pGameType);
  v36 = *(_DWORD *)(g_pGameType + 660);
  j__memset(v23, 0, sizeof(v23));
  v2 = (const wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)(g_pGameType + 28));
  j__wcscpy(v23, v2);
  v17 = *(_DWORD *)(g_pGameType + 692);
  v15 = *(_DWORD *)(g_pGameType + 740);
  v16 = *(_DWORD *)(g_pGameType + 744);
  j__memset(v22, 0, sizeof(v22));
  v3 = (const wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)g_pGameType);
  j__wcscpy(v22, v3);
  v25 = *(_DWORD *)(g_pGameType + 112);
  j__memcpy(v30, (const void *)(g_pGameType + 784), 7u);
  v30[7] = *(_BYTE *)(g_pGameType + 864);
  v29[1024] = 7;
  PlayerId = CPlayerManager::LastPlayerId();
  v4 = (const char *)std::string::c_str(&unk_402C9B4);
  j__strcpy_0(v29, v4);
  for ( j = 0; j < 8; ++j )
  {
    v28[21 * j - 1] = *(_DWORD *)(g_pGameType + 4 * j + 116);
    j__memset(&v28[21 * j], 0, 0x40u);
    RealPlayerName = (_Cnd_internal_imp_t *)CGameType::GetRealPlayerName((void *)g_pGameType, j);
    v6 = (const wchar_t *)std::wstring::c_str(RealPlayerName);
    j__wcscpy((wchar_t *)&v28[21 * j], v6);
    v28[21 * j + 16] = *(_DWORD *)(g_pGameType + 4 * j + 332);
    v28[21 * j + 17] = *(_DWORD *)(g_pGameType + 4 * j + 260);
    v28[21 * j + 18] = *(_DWORD *)(g_pGameType + 4 * j + 296);
    LOBYTE(v28[21 * j + 19]) = *(_BYTE *)(g_pGameType + 4 * j + 152);
  }
  IsClanGame = CGameType::IsClanGame(g_pGameType);
  IsHost = CGameType::IsHost(g_pGameType);
  LocalSlot = CGameType::GetLocalSlot(g_pGameType);
  Seed = CRandom16::GetSeed((CUserToolsManager *)((char *)g_pGameData + 44));
  NumberOfRandCalls = CRandom16::GetNumberOfRandCalls((CUserToolsManager *)((char *)g_pGameData + 44));
  v39 = *((_DWORD *)g_pGameData + 5);
  v40 = *((_DWORD *)g_pGameData + 6);
  v41 = *((_DWORD *)g_pGameData + 7);
  CGameChunkGeneral::GenerateCRC((CGameChunkGeneral *)v13);
  S4::CMapFile::SaveChunkObject(a1, 130, 0, (struct IS4ChunkObject *)v13, 0);
  return 1;
}


// address=[0x1484e90]
// Decompiled from char CGameRun::RandomMap()

static bool __cdecl CGameRun::RandomMap(void) {
  
  _BYTE v1[1176]; // [esp+8h] [ebp-4A8h] BYREF
  int v2; // [esp+4ACh] [ebp-4h]

  S4::CMapFile::CMapFile((CHandleMap *)v1, 0);
  v2 = 0;
  S4::CMapFile::Close((S4::CMapFile *)v1);
  S4::CMapFile::Virtualize((S4::CMapFile *)v1);
  CWorldManager::LoadMap((struct S4::CMapFile *)v1, *(_DWORD *)(g_pGame + 84));
  S4::CMapFile::Close((S4::CMapFile *)v1);
  v2 = -1;
  S4::CMapFile::~CMapFile((CHandleMap *)v1);
  return 1;
}


// address=[0x1484f50]
// Decompiled from char __cdecl CGameRun::LoadEditorMap(int a1, char a2)

static bool __cdecl CGameRun::LoadEditorMap(std::wstring &,bool) {
  
  char *v2; // eax
  wchar_t *v3; // eax
  struct CMapFile *v5; // [esp+10h] [ebp-28h]
  CHandleMap *v6; // [esp+14h] [ebp-24h]
  char *Str; // [esp+1Ch] [ebp-1Ch]
  int v8; // [esp+20h] [ebp-18h] BYREF
  struct S4::CMapFile *v9; // [esp+24h] [ebp-14h]
  char v10; // [esp+2Bh] [ebp-Dh]
  int v11; // [esp+34h] [ebp-4h]

  v10 = 0;
  v9 = 0;
  if ( (*(unsigned __int8 (__thiscall **)(void *, int, _DWORD))(*(_DWORD *)g_pRandomMaps + 32))(g_pRandomMaps, a1, 0) )
  {
    v9 = (struct S4::CMapFile *)(*(int (__thiscall **)(void *))(*(_DWORD *)g_pRandomMaps + 12))(g_pRandomMaps);
  }
  else
  {
    v6 = (CHandleMap *)operator new(0x498u);
    v11 = 0;
    if ( v6 )
      v5 = S4::CMapFile::CMapFile(v6, 0);
    else
      v5 = 0;
    v11 = -1;
    v9 = v5;
    v10 = 1;
    S4::CMapFile::Open(v5, a1, 1, 1);
  }
  CGameRun::LoadGeneralEditorInfo(v9);
  v2 = CStateGame::GameData((CStateGame *)g_pGame);
  CWorldManager::LoadGfxData(v9, 0xDu, *((_DWORD *)v2 + 2));
  CWarMap::Init();
  CBuildingMgr::LoadBuildingData((CBuildingMgr *)g_cBuildingMgr, v9, 8u);
  CSettlerMgr::LoadSettlerData((CSettlerMgr *)g_cSettlerMgr, v9, 7u);
  CPileMgr::LoadPileData((CPileMgr *)&g_cPileMgr, v9, 9);
  v8 = 0;
  Str = (char *)S4::CMapFile::LoadChunk(v9, 0x10u, 0, &v8, 0);
  if ( Str )
  {
    v8 = j__strlen(Str);
    if ( v8 < 4 )
    {
      v8 = 0;
      Str = 0;
    }
  }
  else
  {
    v8 = 0;
  }
  v3 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)(g_pGameType + 28));
  CGameScriptManager::NewGameEx((int)Str, v8, v3, a2);
  S4::CMapFile::CloseChunk(v9, 0x10u, 0);
  if ( v10 && v9 )
    (**(void (__thiscall ***)(struct S4::CMapFile *, int))v9)(v9, 1);
  (*(void (__thiscall **)(void *))(*(_DWORD *)off_3D7A3D8 + 12))(off_3D7A3D8);
  if ( CGameType::IsCampaignMap((CGameType *)g_pGameType) && *(int *)(g_pGameType + 740) < 11 )
    IAIEnvironment::SetGlobalEcoAIFlags(0);
  else
    IAIEnvironment::SetGlobalEcoAIFlags((struct CFrameWnd *)0x10);
  return 1;
}


// address=[0x1485180]
// Decompiled from int CGameRun::ActivateAIs()

static void __cdecl CGameRun::ActivateAIs(void) {
  
  int result; // eax
  int v1; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  result = CPlayerManager::LastPlayerId();
  v1 = result;
  for ( i = 1; i <= v1; ++i )
  {
    if ( CPlayerManager::IsAI(i) )
    {
      (*(void (__thiscall **)(void *, int))(*(_DWORD *)off_3D7A3D8 + 28))(off_3D7A3D8, i);
      if ( CPlayerManager::GetPlayerControl(i) == 2 )
        IAIDifficultyLevels::SetDifficultyLevel(i, 1u);
      else
        IAIDifficultyLevels::SetDifficultyLevel(i, 2u);
    }
    result = i + 1;
  }
  return result;
}


// address=[0x1485210]
// Decompiled from char __cdecl CGameRun::SaveCurrentData(struct S4::CMapFile *a1)

static bool __cdecl CGameRun::SaveCurrentData(class S4::CMapFile &) {
  
  int v2; // [esp+4h] [ebp-4h]

  v2 = *(_DWORD *)(g_pGame + 252);
  if ( v2 )
    S4::CMapFile::SaveChunkObject(a1, 132, 0, (struct IS4ChunkObject *)(v2 + 24), 0);
  else
    S4::CMapFile::SaveChunkObject(a1, 132, 0, 0, 0);
  return 1;
}


// address=[0x1485260]
// Decompiled from void __cdecl CGameRun::SaveInfoAndUpdateGUI(struct S4::CMapFile *a1, const char *a2, const char *a3)

static void __cdecl CGameRun::SaveInfoAndUpdateGUI(class S4::CMapFile &,char const *,char const *) {
  
  if ( !a3 )
    a3 = a2;
  if ( a2 )
    BBSupportTracePrintF(1, "%s", a2);
  if ( a3 )
    S4::CMapFile::SaveDbgInfoChunk(a1, a3);
  if ( CGameRun::m_iSaveTotal < 1 )
    CGameRun::m_iSaveTotal = 1;
  if ( ++CGameRun::m_iSaveCounter >= 0 )
  {
    if ( CGameRun::m_iSaveCounter > CGameRun::m_iSaveTotal )
      CGameRun::m_iSaveCounter = CGameRun::m_iSaveTotal;
  }
  else
  {
    CGameRun::m_iSaveCounter = 0;
  }
  GuiDlgLoadSaveUpdateProgress(100 * CGameRun::m_iSaveCounter / CGameRun::m_iSaveTotal);
}


// address=[0x1485300]
// Decompiled from void __cdecl CGameRun::SaveChunkObject(
        struct S4::CMapFile *a1,
        __int16 a2,
        __int16 a3,
        struct IS4ChunkObject *a4,
        const char *a5,
        const char *a6)

static void __cdecl CGameRun::SaveChunkObject(class S4::CMapFile &,unsigned short,unsigned short,class IS4ChunkObject &,char const *,char const *) {
  
  CGameRun::SaveInfoAndUpdateGUI(a1, a5, a6);
  S4::CMapFile::SaveChunkObject(a1, a2, a3, a4, 0);
}


// address=[0x3d89b28]
// [Decompilation failed for static int CGameRun::m_iSaveTotal]

// address=[0x3f450b8]
// [Decompilation failed for static bool CGameRun::m_bInitialized]

// address=[0x3f450bc]
// [Decompilation failed for static int CGameRun::m_iSaveCounter]

