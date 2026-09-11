#include "CNetInputProcessor.h"

// Definitions for class CNetInputProcessor

// address=[0x1471110]
// Decompiled from void __thiscall CNetInputProcessor::Process(CNetInputProcessor *this, struct CEvn_Logic *a2)
void  CNetInputProcessor::Process(class CEvn_Logic & a2) {
  
  void **v2; // eax
  void **v3; // eax
  void **v4; // eax
  void **v5; // eax
  void **v6; // eax
  void **v7; // eax
  void **v8; // eax
  int v9; // eax
  void **v10; // eax
  void **v11; // eax
  void **v12; // eax
  int v13; // eax
  void **v14; // eax
  int v15; // [esp-10h] [ebp-2D4h]
  CEntityEvent v16; // [esp+4h] [ebp-2C0h] BYREF
  CEntityEvent v17; // [esp+1Ch] [ebp-2A8h] BYREF
  CEntityEvent v18; // [esp+34h] [ebp-290h] BYREF
  CNetInputProcessor *v19; // [esp+4Ch] [ebp-278h]
  void *v20; // [esp+50h] [ebp-274h]
  unsigned int v21; // [esp+5Ch] [ebp-268h]
  unsigned int v22; // [esp+60h] [ebp-264h]
  int; // [esp+64h] [ebp-260h]
  CEntityEvent *v24; // [esp+68h] [ebp-25Ch]
  CEntityEvent *v25; // [esp+6Ch] [ebp-258h]
  int v26; // [esp+70h] [ebp-254h]
  int v27; // [esp+74h] [ebp-250h]
  int v28; // [esp+78h] [ebp-24Ch]
  unsigned int v29; // [esp+7Ch] [ebp-248h]
  unsigned int v30; // [esp+80h] [ebp-244h]
  int v31; // [esp+84h] [ebp-240h]
  unsigned int v32; // [esp+88h] [ebp-23Ch]
  struct CBuilding *v33; // [esp+8Ch] [ebp-238h]
  int v34; // [esp+90h] [ebp-234h]
  unsigned int v35; // [esp+94h] [ebp-230h]
  int v36; // [esp+98h] [ebp-22Ch]
  unsigned int v37; // [esp+9Ch] [ebp-228h]
  unsigned int v38; // [esp+A0h] [ebp-224h]
  int v39; // [esp+A4h] [ebp-220h]
  unsigned int v40; // [esp+A8h] [ebp-21Ch]
  int v41; // [esp+ACh] [ebp-218h]
  struct CBuilding *v42; // [esp+B0h] [ebp-214h]
  int v43; // [esp+B4h] [ebp-210h]
  struct CBuilding *v44; // [esp+B8h] [ebp-20Ch]
  int v45; // [esp+BCh] [ebp-208h]
  unsigned int v46; // [esp+C0h] [ebp-204h]
  int v47; // [esp+C4h] [ebp-200h]
  int v48; // [esp+C8h] [ebp-1FCh]
  unsigned int v49; // [esp+CCh] [ebp-1F8h]
  int v50; // [esp+D0h] [ebp-1F4h]
  int v51; // [esp+D4h] [ebp-1F0h]
  int v52; // [esp+D8h] [ebp-1ECh]
  int v53; // [esp+E0h] [ebp-1E4h]
  int v54; // [esp+E4h] [ebp-1E0h]
  unsigned int v55; // [esp+ECh] [ebp-1D8h]
  unsigned int v56; // [esp+F0h] [ebp-1D4h]
  int v57; // [esp+F4h] [ebp-1D0h]
  unsigned int v58; // [esp+F8h] [ebp-1CCh]
  unsigned int v59; // [esp+FCh] [ebp-1C8h]
  int v60; // [esp+100h] [ebp-1C4h]
  unsigned int v61; // [esp+104h] [ebp-1C0h]
  int v62; // [esp+108h] [ebp-1BCh]
  int v63; // [esp+10Ch] [ebp-1B8h]
  int v64; // [esp+110h] [ebp-1B4h]
  void *v65; // [esp+114h] [ebp-1B0h]
  int v66; // [esp+118h] [ebp-1ACh]
  int v67; // [esp+11Ch] [ebp-1A8h]
  unsigned int v68; // [esp+120h] [ebp-1A4h]
  unsigned int v69; // [esp+124h] [ebp-1A0h]
  void *C; // [esp+128h] [ebp-19Ch]
  int v71; // [esp+12Ch] [ebp-198h]
  int v72; // [esp+130h] [ebp-194h]
  int v73; // [esp+134h] [ebp-190h]
  int v74; // [esp+148h] [ebp-17Ch]
  int v75; // [esp+14Ch] [ebp-178h]
  int v76; // [esp+150h] [ebp-174h]
  unsigned int v77; // [esp+154h] [ebp-170h]
  int v78; // [esp+158h] [ebp-16Ch]
  unsigned int v79; // [esp+15Ch] [ebp-168h]
  int v80; // [esp+160h] [ebp-164h]
  unsigned int v81; // [esp+164h] [ebp-160h]
  int v82; // [esp+168h] [ebp-15Ch]
  int v83; // [esp+16Ch] [ebp-158h]
  int v84; // [esp+170h] [ebp-154h]
  int LocalPlayerId; // [esp+17Ch] [ebp-148h]
  int v86; // [esp+180h] [ebp-144h]
  CDarkTempleRole *v87; // [esp+184h] [ebp-140h]
  CTradingBuildingRole *v88; // [esp+188h] [ebp-13Ch]
  struct CBuilding *v89; // [esp+18Ch] [ebp-138h]
  int v90; // [esp+190h] [ebp-134h]
  int v91; // [esp+194h] [ebp-130h]
  CEcoSector *v92; // [esp+198h] [ebp-12Ch]
  unsigned int v93; // [esp+19Ch] [ebp-128h]
  int v94; // [esp+1A0h] [ebp-124h]
  unsigned int v95; // [esp+1A4h] [ebp-120h]
  CStorageBuildingRole *v96; // [esp+1A8h] [ebp-11Ch]
  struct CBuilding *v97; // [esp+1ACh] [ebp-118h]
  int v98; // [esp+1B0h] [ebp-114h]
  CWorkshopBuildingRole *v99; // [esp+1B4h] [ebp-110h]
  struct CBuilding *v100; // [esp+1B8h] [ebp-10Ch]
  CEcoSector *v101; // [esp+1BCh] [ebp-108h]
  CEcoSector *v102; // [esp+1C0h] [ebp-104h]
  CBuilding *AliveBuildingPtrOfPlayer; // [esp+1C4h] [ebp-100h]
  int v104; // [esp+1C8h] [ebp-FCh]
  CWorkshopBuildingRole *v105; // [esp+1D0h] [ebp-F4h]
  int v106; // [esp+1D4h] [ebp-F0h]
  struct CEcoSector *v107; // [esp+1D8h] [ebp-ECh]
  CEcoSector *EcoSectorPtrOfPlayer; // [esp+1DCh] [ebp-E8h]
  int v109; // [esp+1E0h] [ebp-E4h]
  int v110; // [esp+1E4h] [ebp-E0h]
  struct CEcoSector *EcoSectorPtr; // [esp+1E8h] [ebp-DCh]
  int v112; // [esp+1ECh] [ebp-D8h]
  int v113; // [esp+1F0h] [ebp-D4h]
  int v114; // [esp+1F4h] [ebp-D0h]
  BYTE *v115; // [esp+1F8h] [ebp-CCh]
  CCart *v116; // [esp+1FCh] [ebp-C8h]
  CCart *v117; // [esp+200h] [ebp-C4h]
  CCart *ReadyCartPtr; // [esp+204h] [ebp-C0h]
  CCatapult *v119; // [esp+208h] [ebp-BCh]
  void **v120; // [esp+20Ch] [ebp-B8h]
  CTradingBuildingRole *v121; // [esp+210h] [ebp-B4h]
  struct CBuilding *v122; // [esp+214h] [ebp-B0h]
  CInternationalTrader **v123; // [esp+218h] [ebp-ACh]
  struct CBuilding *v124; // [esp+21Ch] [ebp-A8h]
  CTradingBuildingRole *v125; // [esp+220h] [ebp-A4h]
  struct CBuilding *v126; // [esp+224h] [ebp-A0h]
  CTradingBuildingRole *v127; // [esp+228h] [ebp-9Ch]
  int v128; // [esp+22Ch] [ebp-98h]
  struct CBuilding *AliveBuildingPtr; // [esp+230h] [ebp-94h]
  struct CBuilding *v130; // [esp+234h] [ebp-90h]
  CBuilding *v131; // [esp+23Ch] [ebp-88h]
  int v132; // [esp+240h] [ebp-84h]
  BYTE *v133; // [esp+244h] [ebp-80h]
  int v134; // [esp+248h] [ebp-7Ch]
  CEcoSector *BuildingEcoSectorPtr; // [esp+24Ch] [ebp-78h]
  struct CBuilding *v136; // [esp+250h] [ebp-74h]
  struct CBuilding *v137; // [esp+254h] [ebp-70h]
  BYTE *v138; // [esp+258h] [ebp-6Ch]
  struct CVehicle *ReadyVehiclePtr; // [esp+25Ch] [ebp-68h]
  int v140; // [esp+260h] [ebp-64h]
  struct CBuilding *v141; // [esp+264h] [ebp-60h]
  struct CBuilding *v142; // [esp+268h] [ebp-5Ch]
  int j; // [esp+26Ch] [ebp-58h]
  unsigned int i; // [esp+270h] [ebp-54h]
  int v145; // [esp+274h] [ebp-50h]
  unsigned __int16 *v146; // [esp+278h] [ebp-4Ch]
  void **VehiclePtr; // [esp+27Ch] [ebp-48h]
  CEcoSector *v148; // [esp+280h] [ebp-44h]
  struct CBuilding *v149; // [esp+284h] [ebp-40h]
  CPropertySet *ReadySettlerPtr; // [esp+288h] [ebp-3Ch]
  bool v151; // [esp+28Dh] [ebp-37h]
  int v152; // [esp+290h] [ebp-34h]
  _DWORD v153[8]; // [esp+294h] [ebp-30h] BYREF
  int v154; // [esp+2C0h] [ebp-4h]

  v19 = this;
  v132 = a2->m_iEventId;
  v152 = a2->m_iOwner;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  IMessageTracer::PushFormatedInts(g_pMsgTracer, "CNetInputProcessor::Process(): msg %i, owner %i, wparam 0x%08x, lparam 0x%08x", v132, v152, a2->m_wParam, a2->m_lParam);
  v145 = v132 - 5001;
  switch ( v132 )
  {
    case 5001:
      v52 = a2->m_wParam;
      v86 = a2->m_lParam;
      AliveBuildingPtrOfPlayer = (struct CBuilding *)CNetInputProcessor::GetAliveBuildingPtrOfPlayer(v52, v152);
      if ( AliveBuildingPtrOfPlayer != 0 )
      {
        CBuilding::SetWorkingAreaPackedXY(AliveBuildingPtrOfPlayer, v86);
        if ( v152 == LocalPlayerId )
        {
          CEvn_Logic::CEvn_Logic((CEvn_Logic *)v153, 0x193u, 0, 0, 0, 0, 0);
          v154 = 0;
          if ( g_pEvnEngine != 0 )
          {
            IEventEngine::SendAMessage(g_pEvnEngine, (struct CEvn_Event *)v153);
          }
          v154 = -1;
          CEvn_Logic::~CEvn_Logic(v153);
        }
      }
      break;
    case 5002:
      v131 = (struct CBuilding *)CNetInputProcessor::GetAliveBuildingPtrOfPlayer(a2->m_wParam, v152);
      if ( v131 != 0 )
      {
        CBuilding::CrushBuilding(v131);
      }
      break;
    case 5003:
      if ( (struct CBuilding *)CNetInputProcessor::GetAliveBuildingPtrOfPlayer(a2->m_wParam, v152) != 0 )
      {
        CBuilding::Switch();
      }
      break;
    case 5004:
      v84 = a2->m_wParam;
      v141 = (struct CBuilding *)CNetInputProcessor::GetAliveBuildingPtrOfPlayer(v84, v152);
      if ( v141 != 0 && (unsigned __int8)CBuilding::IsBuildUp(v141) == 0 )
      {
        v2 = (void **)CBuilding::Role(v141);
        v140 = j____RTDynamicCast(v2, 0, &IBuildingRole__RTTI_Type_Descriptor_, &CBuildingSiteRole__RTTI_Type_Descriptor_, 0);
        if ( v140 != 0 )
        {
          (*(void (__thiscall **)(int))(*(_DWORD *)v140 + 36))(v140);
        }
      }
      break;
    case 5005:
      v83 = a2->m_wParam;
      v128 = a2->m_lParam;
      v130 = (struct CBuilding *)CNetInputProcessor::GetAliveBuildingPtrOfPlayer(v83, v152);
      AliveBuildingPtr = (struct CBuilding *)CNetInputProcessor::GetAliveBuildingPtr(v128);
      if ( v130 != 0 && AliveBuildingPtr != 0 )
      {
        v3 = (void **)CBuilding::Role(v130);
        v127 = (CTradingBuildingRole *)j____RTDynamicCast(v3, 0, &IBuildingRole__RTTI_Type_Descriptor_, &CTradingBuildingRole__RTTI_Type_Descriptor_, 0);
        v4 = (void **)CBuilding::Role(AliveBuildingPtr);
        v82 = j____RTDynamicCast(v4, 0, &IBuildingRole__RTTI_Type_Descriptor_, &CTradingBuildingRole__RTTI_Type_Descriptor_, 0);
        if ( v127 != 0 && v82 != 0 )
        {
          CTradingBuildingRole::SetTradeTarget(v127, v128);
        }
      }
      break;
    case 5006:
      v81 = CNetInputProcessor::UnpackHiValue(a2->m_wParam);
      v79 = CNetInputProcessor::UnpackLoValue(a2->m_wParam);
      v80 = a2->m_lParam;
      v126 = (struct CBuilding *)CNetInputProcessor::GetAliveBuildingPtrOfPlayer(v81, v152);
      if ( v126 != 0 )
      {
        v5 = (void **)CBuilding::Role(v126);
        v125 = (CTradingBuildingRole *)j____RTDynamicCast(v5, 0, &IBuildingRole__RTTI_Type_Descriptor_, &CTradingBuildingRole__RTTI_Type_Descriptor_, 0);
        if ( v125 != 0 )
        {
          CTradingBuildingRole::TransportGood(v125, v79, v80);
        }
      }
      break;
    case 5007:
      v78 = a2->m_wParam;
      v77 = a2->m_lParam;
      v124 = (struct CBuilding *)CNetInputProcessor::GetAliveBuildingPtrOfPlayer(v78, v152);
      if ( v124 != 0 )
      {
        v6 = (void **)CBuilding::Role(v124);
        v123 = (CInternationalTrader **)j____RTDynamicCast(v6, 0, &IBuildingRole__RTTI_Type_Descriptor_, &CTradingBuildingRole__RTTI_Type_Descriptor_, 0);
        if ( v123 != 0 )
        {
          CTradingBuildingRole::TradeWith(v123, v77);
        }
      }
      break;
    case 5008:
      v76 = a2->m_wParam;
      v75 = a2->m_lParam;
      v122 = (struct CBuilding *)CNetInputProcessor::GetAliveBuildingPtrOfPlayer(v76, v152);
      if ( v122 != 0 )
      {
        v7 = (void **)CBuilding::Role(v122);
        v121 = (CTradingBuildingRole *)j____RTDynamicCast(v7, 0, &IBuildingRole__RTTI_Type_Descriptor_, &CTradingBuildingRole__RTTI_Type_Descriptor_, 0);
        if ( v121 != 0 )
        {
          CTradingBuildingRole::TradeGood(v121, v75);
        }
      }
      break;
    case 5009:
      v74 = a2->m_wParam;
      ReadyVehiclePtr = (struct CVehicle *)CNetInputProcessor::GetReadyVehiclePtr(v74);
      if ( ReadyVehiclePtr != 0 )
      {
        ((void (__thiscall *)(struct CVehicle *))ReadyVehiclePtr->Unload)(ReadyVehiclePtr);
      }
      break;
    case 5010:
      v120 = (void **)CNetInputProcessor::GetReadyVehiclePtr(a2->m_wParam);
      if ( v120 != 0 )
      {
        v119 = (CCatapult *)j____RTDynamicCast(v120, 0, &CVehicle__RTTI_Type_Descriptor_, &CCatapult__RTTI_Type_Descriptor_, 0);
        if ( v119 != 0 )
        {
          CCatapult::RequestAmmoDonkey(v119);
        }
      }
      break;
    case 5011:
      ReadyCartPtr = (struct CCart *)CNetInputProcessor::GetReadyCartPtr(a2->m_wParam);
      if ( ReadyCartPtr != 0 )
      {
        CCart::CreateSettlement(ReadyCartPtr);
      }
      break;
    case 5012:
      v117 = (struct CCart *)CNetInputProcessor::GetReadyCartPtr(a2->m_wParam);
      if ( v117 != 0 )
      {
        CCart::CreateFoundationCart(v117);
      }
      break;
    case 5013:
      v116 = (struct CCart *)CNetInputProcessor::GetReadyCartPtr(a2->m_wParam);
      if ( v116 != 0 )
      {
        CCart::CreateNormalCart(v116);
      }
      break;
    case 5014:
      if ( a2->m_iData == 0 && BBSupportDbgReport(2, "Logic\\NetInputProcessor.cpp", 621, "_rEvent.m_iData != 0") == 1 )
      {
        __debugbreak();
      }
      v71 = a2->m_iDataSize >> 1;
      v115 = a2->m_iData;
      v72 = Y16X16::UnpackXFast(a2->m_wParam);
      v73 = Y16X16::UnpackYFast(a2->m_wParam);
      ((void (__thiscall *)(CGroupMgr *, int, BYTE *, int, int, int))g_pGroupMgr->j_?SendGroupCommand@CGroupMgr@@UAEXHPBGHHH@Z)(g_pGroupMgr, v71, v115, v72, v73, a2->m_lParam);
      C = v115;
      operator delete[](v115);
      break;
    case 5015:
      if ( BBSupportDbgReportF(1, "Logic\\NetInputProcessor.cpp", 638, "CNetInputProcessor::Process(): Unsupported message %s!", "NET_LOGIC_MSG_FORCE_GOTO") == 1 )
      {
        __debugbreak();
      }
      break;
    case 5016:
      if ( BBSupportDbgReportF(1, "Logic\\NetInputProcessor.cpp", 645, "CNetInputProcessor::Process(): Unsupported message %s!", "NET_LOGIC_MSG_STAND_GROUND") == 1 )
      {
        __debugbreak();
      }
      break;
    case 5017:
      if ( BBSupportDbgReportF(1, "Logic\\NetInputProcessor.cpp", 652, "CNetInputProcessor::Process(): Unsupported message %s!", "NET_LOGIC_MSG_SET_WAYPOINT") == 1 )
      {
        __debugbreak();
      }
      break;
    case 5018:
      if ( BBSupportDbgReportF(1, "Logic\\NetInputProcessor.cpp", 659, "CNetInputProcessor::Process(): Unsupported message %s!", "NET_LOGIC_MSG_PATROL") == 1 )
      {
        __debugbreak();
      }
      break;
    case 5019:
      if ( BBSupportDbgReportF(1, "Logic\\NetInputProcessor.cpp", 666, "CNetInputProcessor::Process(): Unsupported message %s!", "NET_LOGIC_MSG_INJURED_OUT") == 1 )
      {
        __debugbreak();
      }
      break;
    case 5020:
      if ( BBSupportDbgReportF(1, "Logic\\NetInputProcessor.cpp", 673, "CNetInputProcessor::Process(): Unsupported message %s!", "NET_LOGIC_MSG_ESCORT") == 1 )
      {
        __debugbreak();
      }
      break;
    case 5021:
      v138 = a2->m_iData;
      v69 = a2->m_iDataSize;
      v68 = v69 >> 1;
      if ( v138 != 0 )
      {
        for ( i = 0;
              i < v68;
              ++i )
        {
          v67 = *(unsigned __int16 *)&v138[2 * i];
          ReadySettlerPtr = (CPropertySet *)CNetInputProcessor::GetReadySettlerPtr(v67);
          if ( ReadySettlerPtr != 0 && IEntity::OwnerId((IEntity *)ReadySettlerPtr) == v152 && IEntity::FlagBits((IEntity *)ReadySettlerPtr, ENTITY_FLAG_ON_BOARD) == 0 && ((int (__stdcall *)())IEntity::WarriorType)() == 7 )
          {
            v113 = IEntity::X(ReadySettlerPtr);
            v114 = IEntity::Y(ReadySettlerPtr);
            if ( CWorldManager::InWorld(v113, v114) )
            {
              v112 = CWorldManager::EcoSectorId(v113, v114);
              if ( v112 > 0 )
              {
                EcoSectorPtr = CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, v112);
                v110 = EcoSectorPtr != 0 ? CEcoSector::Owner(EcoSectorPtr) : 0;
                v66 = v110;
                if ( v110 == v152 )
                {
                  CSettler::ChangeType((CSettler *)ReadySettlerPtr, 1u, 1, 0);
                }
              }
            }
          }
        }
      }
      v65 = v138;
      operator delete[](v138);
      break;
    case 5022:
      if ( BBSupportDbgReportF(1, "Logic\\NetInputProcessor.cpp", 735, "CNetInputProcessor::Process(): Unsupported message %s!", "NET_LOGIC_MSG_ENTITY_TO_SELECTION") == 1 )
      {
        __debugbreak();
      }
      break;
    case 5023:
      if ( BBSupportDbgReportF(1, "Logic\\NetInputProcessor.cpp", 742, "CNetInputProcessor::Process(): Unsupported message %s!", "NET_LOGIC_MSG_SELECT_KIND") == 1 )
      {
        __debugbreak();
      }
      break;
    case 5024:
      if ( BBSupportDbgReportF(1, "Logic\\NetInputProcessor.cpp", 749, "CNetInputProcessor::Process(): Unsupported message %s!", "NET_LOGIC_MSG_SELECT_TYPE") == 1 )
      {
        __debugbreak();
      }
      break;
    case 5025:
      v64 = a2->m_wParam;
      v109 = a2->m_lParam;
      v62 = Y16X16::UnpackXFast(v109);
      v63 = Y16X16::UnpackYFast(v109);
      CBuildingMgr::CheckForBuild((CBuildingMgr *)g_cBuildingMgr, v62, v63, a2->m_iOwner, v64, 1);
      break;
    case 5026:
      if ( BBSupportDbgReportF(1, "Logic\\NetInputProcessor.cpp", 776, "CNetInputProcessor::Process(): Unsupported message %s!", "NET_LOGIC_MSG_SEARCH_UNIT") == 1 )
      {
        __debugbreak();
      }
      break;
    case 5027:
      v61 = CNetInputProcessor::UnpackHiValue(a2->m_wParam);
      v59 = CNetInputProcessor::UnpackLoValue(a2->m_wParam);
      v60 = a2->m_lParam;
      EcoSectorPtrOfPlayer = CNetInputProcessor::GetEcoSectorPtrOfPlayer(v61, v152);
      if ( EcoSectorPtrOfPlayer != 0 )
      {
        CEcoSector::ChangeMinMaxValues(EcoSectorPtrOfPlayer, v59, v60);
      }
      break;
    case 5028:
      v56 = CNetInputProcessor::UnpackLoValue(a2->m_wParam);
      v55 = CNetInputProcessor::UnpackHiValue(a2->m_wParam);
      v57 = CNetInputProcessor::UnpackSignedLoValue(a2->m_lParam);
      v58 = CNetInputProcessor::UnpackHiValue(a2->m_lParam);
      v107 = CNetInputProcessor::GetEcoSectorPtrOfPlayer(v58, v152);
      if ( v107 != 0 )
      {
        CEcoSector::ChangeBuildingSupplyPrio(v107, v55, v56, (unsigned __int8)v57);
      }
      break;
    case 5029:
      v54 = CNetInputProcessor::UnpackSignedLoValue(a2->m_wParam);
      v53 = CNetInputProcessor::UnpackHiValue(a2->m_wParam);
      v106 = a2->m_lParam;
      if ( CNetInputProcessor::GetEcoSectorPtrOfPlayer(v106, v152) != 0 )
      {
        CEcoSectorMgr::ChangeTransportPrio(v53, v54, v106);
      }
      break;
    case 5030:
      v33 = (struct CBuilding *)CNetInputProcessor::GetAliveBuildingPtrOfPlayer(a2->m_wParam, v152);
      v8 = (void **)CBuilding::Role(v33);
      v105 = (CWorkshopBuildingRole *)j____RTDynamicCast(v8, 0, &IBuildingRole__RTTI_Type_Descriptor_, &CWorkshopBuildingRole__RTTI_Type_Descriptor_, 0);
      if ( v105 != 0 )
      {
        CWorkshopBuildingRole::CancelCurrentProduction(v105);
      }
      break;
    case 5031:
      v51 = a2->m_wParam;
      v50 = a2->m_lParam;
      v137 = (struct CBuilding *)CNetInputProcessor::GetAliveBuildingPtrOfPlayer(v51, v152);
      if ( v137 != 0 && v50 == -1 )
      {
        CEntityEvent::CEntityEvent(&v18, 0x12u, 0, 0, 0, 0);
        v154 = 1;
        v137->j_?SetEvent@IAnimatedEntity@@UAEXABVCEntityEvent@@@Z((unsigned __int16 *)v137, (int)&v18);
        v154 = -1;
        CEntityEvent::~CEntityEvent(&v18);
      }
      break;
    case 5032:
      v47 = CNetInputProcessor::UnpackLoValue(a2->m_wParam);
      v49 = CNetInputProcessor::UnpackHiValue(a2->m_wParam);
      v48 = a2->m_lParam;
      v136 = (struct CBuilding *)CNetInputProcessor::GetAliveBuildingPtrOfPlayer(v49, v152);
      if ( v136 != 0 )
      {
        CEntityEvent::CEntityEvent(&v17, 0x13u, v47, v48, 0, 0);
        v154 = 2;
        v136->j_?SetEvent@IAnimatedEntity@@UAEXABVCEntityEvent@@@Z((unsigned __int16 *)v136, (int)&v17);
        v154 = -1;
        CEntityEvent::~CEntityEvent(&v17);
      }
      break;
    case 5033:
      v46 = CNetInputProcessor::UnpackHiValue(a2->m_wParam);
      v95 = CNetInputProcessor::UnpackLoValue(a2->m_wParam);
      v104 = a2->m_lParam;
      v149 = (struct CBuilding *)CNetInputProcessor::GetAliveBuildingPtrOfPlayer(v46, v152);
      if ( v149 != 0 && IEntity::FlagBits(v149, (EntityFlag)((char *)&loc_1FFFFFF + 1)) != 0 )
      {
        v9 = (int)CBuilding::Role(v149);
        if ( (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 112))(v9) == 4 )
        {
          BuildingEcoSectorPtr = (struct CEcoSector *)CNetInputProcessor::GetBuildingEcoSectorPtr(v149);
          if ( BuildingEcoSectorPtr != 0 )
          {
            if ( IEntity::Type(v149) == 21 )
            {
              CEcoSector::TakeToolOrder(BuildingEcoSectorPtr, v95, v104);
            }
            else if ( IEntity::Type(v149) == 22 )
            {
              CEcoSector::TakeWeaponOrder(BuildingEcoSectorPtr, v95, v104);
            }
          }
        }
      }
      break;
    case 5034:
      v45 = a2->m_wParam;
      v44 = (struct CBuilding *)CNetInputProcessor::GetAliveBuildingPtrOfPlayer(v45, v152);
      v148 = (struct CEcoSector *)CNetInputProcessor::GetBuildingEcoSectorPtr(v44);
      if ( v148 != 0 )
      {
        CEcoSector::SetWeaponPercentage(v148, a2->m_lParam);
        CEcoSector::SetProducedSwords(v148, 0);
        CEcoSector::SetProducedBows(v148, 0);
        CEcoSector::SetProducedArmors(v148, 0);
        CEcoSector::SetProducedSpecial(v148, 0);
      }
      break;
    case 5035:
      v43 = a2->m_wParam;
      v41 = a2->m_lParam;
      v42 = (struct CBuilding *)CNetInputProcessor::GetAliveBuildingPtrOfPlayer(v43, v152);
      v102 = (struct CEcoSector *)CNetInputProcessor::GetBuildingEcoSectorPtr(v42);
      if ( v102 != 0 )
      {
        CEcoSector::SetWeaponAutoProduction(v102, v41 != 1);
      }
      break;
    case 5036:
      if ( BBSupportDbgReportF(1, "Logic\\NetInputProcessor.cpp", 964, "CNetInputProcessor::Process(): Unsupported message %s!", "NET_LOGIC_MSG_STANDARD_PRODUCTION") == 1 )
      {
        __debugbreak();
      }
      break;
    case 5037:
      if ( BBSupportDbgReportF(1, "Logic\\NetInputProcessor.cpp", 971, "CNetInputProcessor::Process(): Unsupported message %s!", "NET_LOGIC_MSG_SET_GOOD_SWITCH") == 1 )
      {
        __debugbreak();
      }
      break;
    case 5038:
      if ( BBSupportDbgReportF(1, "Logic\\NetInputProcessor.cpp", 978, "CNetInputProcessor::Process(): Unsupported message %s!", "NET_LOGIC_MSG_SET_JOB_PERCENT") == 1 )
      {
        __debugbreak();
      }
      break;
    case 5039:
      v38 = CNetInputProcessor::UnpackLoValue(a2->m_wParam);
      v40 = CNetInputProcessor::UnpackHiValue(a2->m_wParam);
      v39 = a2->m_lParam;
      v101 = CNetInputProcessor::GetEcoSectorPtrOfPlayer(v40, v152);
      if ( v101 != 0 )
      {
        CEcoSector::ChangeSpecialistWish(v101, v38, v39);
      }
      break;
    case 5040:
      v35 = CNetInputProcessor::UnpackLoValue(a2->m_wParam);
      v37 = CNetInputProcessor::UnpackHiValue(a2->m_wParam);
      v36 = a2->m_lParam;
      v100 = (struct CBuilding *)CNetInputProcessor::GetAliveBuildingPtrOfPlayer(v37, v152);
      if ( v100 != 0 )
      {
        v10 = (void **)CBuilding::Role(v100);
        v99 = (CWorkshopBuildingRole *)j____RTDynamicCast(v10, 0, &IBuildingRole__RTTI_Type_Descriptor_, &CWorkshopBuildingRole__RTTI_Type_Descriptor_, 0);
        if ( v99 != 0 )
        {
          CWorkshopBuildingRole::TakeOrder(v99, v35, v36);
        }
      }
      break;
    case 5041:
      v133 = a2->m_iData;
      if ( v133 != 0 )
      {
        v98 = a2->m_wParam;
        v34 = a2->m_iDataSize >> 1;
        ((void (__thiscall *)(CGroupMgr *, int, int))g_pGroupMgr->j_?DetachAllEntitiesFromGroup@CGroupMgr@@UAEXHH@Z)(g_pGroupMgr, v152, v98);
        for ( j = 0;
              j < v34;
              ++j )
        {
          v134 = *(unsigned __int16 *)&v133[2 * j];
          if ( CNetInputProcessor::IsReadyEntityOfPlayer(v134, v152) )
          {
            ((void (__thiscall *)(CGroupMgr *, int))g_pGroupMgr->DetachEntityFromAllGroups)(g_pGroupMgr, v134);
            ((void (__thiscall *)(CGroupMgr *, int, int, int))g_pGroupMgr->j_?AttachEntity@CGroupMgr@@UAE_NHHH@Z)(g_pGroupMgr, v152, v98, v134);
          }
        }
        v20 = v133;
        operator delete[](v133);
      }
      break;
    case 5042:
      if ( BBSupportDbgReportF(1, "Logic\\NetInputProcessor.cpp", 1052, "CNetInputProcessor::Process(): Unsupported message %s!", "NET_LOGIC_MSG_GROUP_TO_SELECTION") == 1 )
      {
        __debugbreak();
      }
      break;
    case 5043:
      if ( BBSupportDbgReportF(1, "Logic\\NetInputProcessor.cpp", 1059, "CNetInputProcessor::Process(): Unsupported message %s!", "NET_LOGIC_MSG_SELECT_GROUP") == 1 )
      {
        __debugbreak();
      }
      break;
    case 5044:
      v30 = CNetInputProcessor::UnpackLoValue(a2->m_wParam);
      v32 = CNetInputProcessor::UnpackHiValue(a2->m_wParam);
      v31 = a2->m_lParam;
      v97 = (struct CBuilding *)CNetInputProcessor::GetAliveBuildingPtrOfPlayer(v32, v152);
      if ( v97 != 0 )
      {
        v11 = (void **)CBuilding::Role(v97);
        v96 = (CStorageBuildingRole *)j____RTDynamicCast(v11, 0, &IBuildingRole__RTTI_Type_Descriptor_, &CStorageBuildingRole__RTTI_Type_Descriptor_, 0);
        if ( v96 != 0 )
        {
          CStorageBuildingRole::SwitchGood(v96, v30, v31);
        }
      }
      break;
    case 5045:
      if ( BBSupportDbgReportF(1, "Logic\\NetInputProcessor.cpp", 1087, "CNetInputProcessor::Process(): Unsupported message %s!", "NET_LOGIC_MSG_SET_GOOD_PRIORITY") == 1 )
      {
        __debugbreak();
      }
      break;
    case 5046:
      if ( BBSupportDbgReportF(1, "Logic\\NetInputProcessor.cpp", 1094, "CNetInputProcessor::Process(): Unsupported message %s!", "NET_LOGIC_MSG_SET_TRADE") == 1 )
      {
        __debugbreak();
      }
      break;
    case 5047:
      v93 = CNetInputProcessor::UnpackLoValue(a2->m_wParam);
      v29 = CNetInputProcessor::UnpackHiValue(a2->m_wParam);
      v94 = a2->m_lParam;
      v142 = (struct CBuilding *)CNetInputProcessor::GetAliveBuildingPtrOfPlayer(v29, v152);
      if ( v142 != 0 )
      {
        if ( IEntity::Race(v142) == 3 )
        {
          v12 = (void **)CBuilding::Role(v142);
          v87 = (CDarkTempleRole *)j____RTDynamicCast(v12, 0, &IBuildingRole__RTTI_Type_Descriptor_, &CDarkTempleRole__RTTI_Type_Descriptor_, 0);
          if ( v87 != 0 )
          {
            CDarkTempleRole::TakeOrder(v87, v93, v94);
          }
        }
        else
        {
          v92 = (struct CEcoSector *)CNetInputProcessor::GetBuildingEcoSectorPtr(v142);
          if ( v92 != 0 )
          {
            ((void (__thiscall *)(CEcoSector *, unsigned int, int))CEcoSector::TakeSoldierOrder)(v92, v93, v94);
          }
        }
      }
      break;
    case 5048:
      v26 = CNetInputProcessor::UnpackLoValue(a2->m_wParam);
      v28 = CNetInputProcessor::UnpackHiValue(a2->m_wParam);
      v27 = a2->m_lParam;
      v146 = (unsigned __int16 *)CNetInputProcessor::GetReadySettlerPtr(v28);
      if ( v146 != 0 && IEntity::Type((IEntity *)v146) == 45 && IEntity::OwnerId((IEntity *)v146) == v152 )
      {
        v25 = CEntityEvent::CEntityEvent(&v16, 3u, v26, a2->m_iOwner, 0, v27);
        v24 = v25;
        v154 = 3;
        (*(void (__thiscall **)(unsigned __int16 *, CEntityEvent *))(*(_DWORD *)v146 + 80))(v146, v25);
        v154 = -1;
        CEntityEvent::~CEntityEvent(&v16);
      }
      break;
    case 5049:
      v90 = a2->m_wParam;
      VehiclePtr = (void **)CVehicleMgr::GetVehiclePtr(v90);
      if ( VehiclePtr != 0 && IEntity::FlagBits((IEntity *)VehiclePtr, (EntityFlag)&s_iMsgTracer2.m_aMessages[15456]) == 0 && IEntity::OwnerId((IEntity *)VehiclePtr) == v152 )
      {
         = j____RTDynamicCast(VehiclePtr, 0, &CVehicle__RTTI_Type_Descriptor_, &CWheeler__RTTI_Type_Descriptor_, 0);
        if (  != 0 )
        {
          v91 = (int)CLogic::Effects(g_pLogic);
          v15 = IEntity::Y(VehiclePtr);
          v13 = IEntity::X(VehiclePtr);
          (*(void (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v91 + 16))(v91, 62, 3, v13, v15, 0, 0, 0);
          CVehicleMgr::DeleteVehicle((CVehicleMgr *)&g_cVehicleMgr, v90);
        }
      }
      break;
    case 5050:
      v21 = CNetInputProcessor::UnpackLoValue(a2->m_wParam);
      v22 = CNetInputProcessor::UnpackHiValue(a2->m_wParam);
      v151 = a2->m_lParam != 0;
      v89 = (struct CBuilding *)CNetInputProcessor::GetAliveBuildingPtrOfPlayer(v22, v152);
      if ( v89 != 0 )
      {
        v14 = (void **)CBuilding::Role(v89);
        v88 = (CTradingBuildingRole *)j____RTDynamicCast(v14, 0, &IBuildingRole__RTTI_Type_Descriptor_, &CTradingBuildingRole__RTTI_Type_Descriptor_, 0);
        if ( v88 != 0 )
        {
          CTradingBuildingRole::ChangeTradeStatus(v88, v21, v151);
        }
      }
      break;
    case 5051:
      ((void (__thiscall *)(CHJBMgr *, _DWORD))g_pHJBMgr->j_?ProcessHJBRequest@CHJBMgr@@UAEXH@Z)(g_pHJBMgr, a2->m_iOwner);
      break;
    case 5052:
      ((void (__thiscall *)(CHJBMgr *, _DWORD, int))g_pHJBMgr->j_?ProcessHJBAcknowledgement@CHJBMgr@@UAEXHH@Z)(g_pHJBMgr, a2->m_iOwner, a2->m_wParam);
      break;
    default:
      if ( BBSupportDbgReportF(1, "Logic\\NetInputProcessor.cpp", 1228, "CNetInputProcessor::Process(): Unsupported message %i!", v132) == 1 )
      {
        __debugbreak();
      }
      break;
  }
}


// address=[0x1472fd0]
// Decompiled from CNetInputProcessor *__thiscall CNetInputProcessor::CNetInputProcessor(CNetInputProcessor *this)
 CNetInputProcessor::CNetInputProcessor(void) {
  
  INetInputProcessor::INetInputProcessor(this);
  *(_DWORD *)this = &CNetInputProcessor::_vftable_;
  return this;
}


// address=[0x1470e70]
// Decompiled from char *__cdecl CNetInputProcessor::DbgMsgName(int a1)
char * __cdecl CNetInputProcessor::DbgMsgName(int a1) {
  
  int i; // [esp+0h] [ebp-4h]

  for ( i = 0;
        word_3D897D0[2 * i] != -1 && word_3D897D0[2 * i] != a1;
        ++i )
  {
    ;
  }
  return (&off_3D897D4)[2 * i];
}


// address=[0x1470ec0]
// Decompiled from IEntity *__cdecl CNetInputProcessor::GetReadySettlerPtr(int a1)
class CSettler * __cdecl CNetInputProcessor::GetReadySettlerPtr(int a1) {
  
  IEntity *SettlerPtr; // [esp+0h] [ebp-4h]

  SettlerPtr = (IEntity *)((int (__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(a1);
  if ( SettlerPtr != 0 && IEntity::FlagBits(SettlerPtr, (EntityFlag)&loc_1C00000) != 0 )
  {
    return SettlerPtr;
  }
  else
  {
    return 0;
  }
}


// address=[0x1470f00]
// Decompiled from unsigned __int16 *__cdecl CNetInputProcessor::GetReadySettlerPtrOfType(int a1, int a2)
class CSettler * __cdecl CNetInputProcessor::GetReadySettlerPtrOfType(int a1, int a2) {
  
  unsigned __int16 *SettlerPtr; // [esp+0h] [ebp-4h]

  SettlerPtr = (unsigned __int16 *)((int (__stdcall *)(int))CSettlerMgr::GetSettlerPtr)(a1);
  if ( SettlerPtr != 0 && IEntity::FlagBits((IEntity *)SettlerPtr, ENTITY_FLAG_Ready) != 0 && IEntity::Type((IEntity *)SettlerPtr) == a2 )
  {
    return SettlerPtr;
  }
  else
  {
    return 0;
  }
}


// address=[0x1470f50]
// Decompiled from unsigned __int8 *__cdecl CNetInputProcessor::GetAliveBuildingPtr(int a1)
class CBuilding * __cdecl CNetInputProcessor::GetAliveBuildingPtr(int a1) {
  
  unsigned __int8 *BuildingPtr; // [esp+0h] [ebp-4h]

  BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a1);
  if ( BuildingPtr == 0 || IEntity::FlagBits((IEntity *)BuildingPtr, (EntityFlag)&s_iMsgTracer2.m_aMessages[15456]) != 0 )
  {
    return 0;
  }
  else
  {
    return BuildingPtr;
  }
}


// address=[0x1470f90]
// Decompiled from unsigned __int8 *__cdecl CNetInputProcessor::GetAliveBuildingPtrOfPlayer(int a1, int a2)
class CBuilding * __cdecl CNetInputProcessor::GetAliveBuildingPtrOfPlayer(int a1, int a2) {
  
  unsigned __int8 *BuildingPtr; // [esp+0h] [ebp-4h]

  BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a1);
  if ( BuildingPtr != 0 && IEntity::FlagBits((IEntity *)BuildingPtr, (EntityFlag)&s_iMsgTracer2.m_aMessages[15456]) == 0 && IEntity::OwnerId((IEntity *)BuildingPtr) == a2 )
  {
    return BuildingPtr;
  }
  else
  {
    return 0;
  }
}


// address=[0x1470fe0]
// Decompiled from struct CVehicle *__cdecl CNetInputProcessor::GetReadyVehiclePtr(int a1)
class CVehicle * __cdecl CNetInputProcessor::GetReadyVehiclePtr(int a1) {
  
  struct CVehicle *VehiclePtr; // [esp+0h] [ebp-4h]

  VehiclePtr = (struct CVehicle *)CVehicleMgr::GetVehiclePtr(a1);
  if ( VehiclePtr != 0 && IEntity::FlagBits(VehiclePtr, (EntityFlag)((char *)&loc_1FFFFFF + 1)) != 0 )
  {
    return VehiclePtr;
  }
  else
  {
    return 0;
  }
}


// address=[0x1471020]
// Decompiled from int __cdecl CNetInputProcessor::GetReadyCartPtr(int a1)
class CCart * __cdecl CNetInputProcessor::GetReadyCartPtr(int a1) {
  
  void **ReadyVehiclePtr; // [esp+4h] [ebp-4h]

  ReadyVehiclePtr = (void **)CNetInputProcessor::GetReadyVehiclePtr(a1);
  if ( ReadyVehiclePtr != 0 )
  {
    return j____RTDynamicCast(ReadyVehiclePtr, 0, &CVehicle__RTTI_Type_Descriptor_, &CCart__RTTI_Type_Descriptor_, 0);
  }
  else
  {
    return 0;
  }
}


// address=[0x1471070]
// Decompiled from struct CEcoSector *__cdecl CNetInputProcessor::GetEcoSectorPtrOfPlayer(int a1, int a2)
class CEcoSector * __cdecl CNetInputProcessor::GetEcoSectorPtrOfPlayer(int a1, int a2) {
  
  struct CEcoSector *EcoSectorPtr; // [esp+0h] [ebp-4h]

  if ( a1 <= 0 )
  {
    return 0;
  }
  EcoSectorPtr = CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, a1);
  if ( EcoSectorPtr != 0 && CEcoSector::Owner(EcoSectorPtr) == a2 )
  {
    return EcoSectorPtr;
  }
  else
  {
    return 0;
  }
}


// address=[0x14710b0]
// Decompiled from struct CEcoSector *__cdecl CNetInputProcessor::GetBuildingEcoSectorPtr(struct CBuilding *a1)
class CEcoSector * __cdecl CNetInputProcessor::GetBuildingEcoSectorPtr(class CBuilding * a1) {
  
  int v1; // eax
  int v4; // [esp+8h] [ebp-4h]

  if ( a1 == 0 )
  {
    return 0;
  }
  v1 = CBuilding::EnsignWorldIdx(a1);
  v4 = CWorldManager::EcoSectorId(v1);
  if ( v4 <= 0 )
  {
    return 0;
  }
  else
  {
    return CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, v4);
  }
}


// address=[0x1473020]
// Decompiled from bool __cdecl CNetInputProcessor::IsReadyEntityOfPlayer(int a1, int a2)
bool __cdecl CNetInputProcessor::IsReadyEntityOfPlayer(int a1, int a2) {
  
  unsigned __int8 *v4; // [esp+4h] [ebp-4h]

  v4 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(a1);
  return v4 != 0 && IEntity::FlagBits((IEntity *)v4, (EntityFlag)((char *)&loc_1FFFFFF + 1)) != 0 && IEntity::OwnerId((IEntity *)v4) == a2;
}


// address=[0x1473190]
// Decompiled from unsigned int __cdecl CNetInputProcessor::UnpackHiValue(unsigned int a1)
unsigned int __cdecl CNetInputProcessor::UnpackHiValue(unsigned int a1) {
  
  return HIWORD(a1);
}


// address=[0x14731a0]
// Decompiled from int __cdecl CNetInputProcessor::UnpackLoValue(unsigned __int16 a1)
unsigned int __cdecl CNetInputProcessor::UnpackLoValue(unsigned int a1) {
  
  return a1;
}


// address=[0x14731b0]
// Decompiled from int __cdecl CNetInputProcessor::UnpackSignedLoValue(__int16 a1)
int __cdecl CNetInputProcessor::UnpackSignedLoValue(unsigned int a1) {
  
  return a1;
}


