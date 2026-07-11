#if FALSE
#include "CInputProcessor.h"

// Definitions for class CInputProcessor

// address=[0x1439c90]
// Decompiled from std::vector *CInputProcessor::Selection()
class std::vector<unsigned short,class std::allocator<unsigned short> > const & __cdecl CInputProcessor::Selection(void) {
  
  return &CInputProcessor::m_vSelection;
}


// address=[0x1454f10]
// Decompiled from CInputProcessor *__thiscall CInputProcessor::CInputProcessor(CInputProcessor *this)
 CInputProcessor::CInputProcessor(void) {
  
  IEventHandler::IEventHandler(this, 1500);
  this->__vftable = (IEventHandler_vtbl *)&CInputProcessor::_vftable_;
  this->m_bBoxSelectAllSettler = 0;
  std::vector<unsigned short>::vector<unsigned short>(&this->m_pEntityCandidates);
  memset(&CInputProcessor::m_sGfxObj, 0, 0x2E0u);
  CInputProcessor::FillHandlersArray(this);
  std::vector<unsigned short>::reserve(&CInputProcessor::m_vSelection, 0x80u);
  std::vector<unsigned short>::reserve(&this->m_pEntityCandidates, 0x100u);
  this->m_pFSM = 0;
  CInputProcessor::Reset(this);
  return this;
}


// address=[0x1454fd0]
// Decompiled from void __thiscall CInputProcessor::~CInputProcessor(CInputProcessor *this)
 CInputProcessor::~CInputProcessor(void) {
  
  this->__vftable = (IEventHandler_vtbl *)&CInputProcessor::_vftable_;
  if ( this->m_pFSM )
  {
    delete this->m_pFSM;
    this->m_pFSM = 0;
  }
  std::vector<unsigned short>::~vector<unsigned short>(&this->m_pEntityCandidates);
  IEventHandler::~IEventHandler((void **)&this->__vftable);
}


// address=[0x1455040]
// Decompiled from void __thiscall CInputProcessor::Reset(CInputProcessor *this)
void  CInputProcessor::Reset(void) {
  
  if ( this->m_pFSM )
  {
    delete this->m_pFSM;
    this->m_pFSM = 0;
  }
  CInputProcessor::InitFSM(this);
  std::vector<unsigned short>::clear(&CInputProcessor::m_vSelection);
  std::vector<unsigned short>::clear(&this->m_pEntityCandidates);
  this->m_iSelectionType = 0;
  this->m_iSelectionStrict = 0;
  this->m_iSelectionMode = 0;
  this->unk_18 = 0;
  this->unk_1C = 0;
}


// address=[0x14550e0]
// Decompiled from void __thiscall CInputProcessor::Process(CInputProcessor *this)
void  CInputProcessor::Process(void) {
  
  CEvn_Logic sGameMessage; // [esp+10h] [ebp-30h] BYREF
  int v3; // [esp+3Ch] [ebp-4h]

  if ( this->m_bBoxSelectAllSettler )
  {
    CInputProcessor::SelectAllVisible(this);
  }
  else if ( this->m_iSelectionMode )
  {
    CInputProcessor::BoxSelection(this);
  }
  CInputProcessor::WorkOnBuildingSites(this);
  while ( CStateGame::IsMessage(g_pGame) )
  {
    CStateGame::PopMessage(g_pGame, &sGameMessage);
    v3 = 0;
    if ( sGameMessage.m_iEventId <= 0x1388u || sGameMessage.m_iEventId >= 0x13BDu )
    {
      switch ( sGameMessage.m_iEventId )
      {
        case 0x1DD:
          if ( (sGameMessage.m_wParam & 0x14) != 0 )
            sGameMessage.m_iEventId = 426;
LABEL_19:
          CFsm::Control(this->m_pFSM, sGameMessage.m_iEventId, &sGameMessage);
          v3 = -1;
          CEvn_Logic::~CEvn_Logic(&sGameMessage);
          break;
        case 0x1DF:
          v3 = -1;
          CEvn_Logic::~CEvn_Logic(&sGameMessage);
          break;
        case 0x1E8:
          INetworkEngine::SendNetMessage(
            g_pNetworkEngine,
            0x13BBu,
            sGameMessage.m_wParam,
            (char *)sGameMessage.m_lParam,
            sGameMessage.m_iOwner);
          v3 = -1;
          CEvn_Logic::~CEvn_Logic(&sGameMessage);
          break;
        default:
          goto LABEL_19;
      }
    }
    else
    {
      (**(void (__thiscall ***)(CNetInputProcessor *, CEvn_Logic *))g_pNetInputProcessor)(
        g_pNetInputProcessor,
        &sGameMessage);
      v3 = -1;
      CEvn_Logic::~CEvn_Logic(&sGameMessage);
    }
  }
}


// address=[0x1455280]
// Decompiled from void __thiscall CInputProcessor::DeSelectAllEx(CInputProcessor *this)
void  CInputProcessor::DeSelectAllEx(void) {
  
  if ( std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
  {
    CInputProcessor::DeSelectAll(this);
    CInputProcessor::CloseSidebarAndShowDefaultMenu(this);
  }
}


// address=[0x14552b0]
// Decompiled from void __thiscall CInputProcessor::DeSelectEntity(CInputProcessor *this, int a2)
void  CInputProcessor::DeSelectEntity(int a2) {
  
  _DWORD v2[4]; // [esp-Ch] [ebp-78h] BYREF
  _DWORD v3[3]; // [esp+4h] [ebp-68h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-5Ch] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-50h] BYREF
  _BYTE v6[12]; // [esp+28h] [ebp-44h] BYREF
  int v7; // [esp+34h] [ebp-38h]
  int v8; // [esp+38h] [ebp-34h]
  _DWORD *v9; // [esp+3Ch] [ebp-30h]
  int v10; // [esp+40h] [ebp-2Ch]
  std::_Iterator_base12 *v11; // [esp+44h] [ebp-28h]
  std::_Iterator_base12 *v12; // [esp+48h] [ebp-24h]
  int v13; // [esp+4Ch] [ebp-20h]
  int v14; // [esp+50h] [ebp-1Ch]
  IEntity *v16; // [esp+58h] [ebp-14h]
  char v17; // [esp+5Fh] [ebp-Dh]
  int v18; // [esp+68h] [ebp-4h]

  if ( a2 > 0 )
  {
    v16 = CMapObjectMgr::EntityPtr(a2);
    if ( v16 )
    {
      IEntity::ClearFlagBits(v16, EntityFlag_Selected);
      IEntity::ClearFlagBits(v16, (EntityFlag)1024);
    }
    if ( std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    {
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v6);
      v18 = 0;
      v14 = std::vector<unsigned short>::begin(v5);
      v13 = v14;
      LOBYTE(v18) = 1;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator=(v14);
      LOBYTE(v18) = 0;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v5);
      while ( 1 )
      {
        v12 = (std::_Iterator_base12 *)std::vector<unsigned short>::end(v4);
        v11 = v12;
        LOBYTE(v18) = 2;
        v17 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator!=(v12);
        LOBYTE(v18) = 0;
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v4);
        if ( !v17 )
          break;
        v10 = *(unsigned __int16 *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator*(v6);
        if ( v10 == a2 )
        {
          v9 = v2;
          v8 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>((struct std::_Iterator_base12 *)v6);
          v7 = std::vector<unsigned short>::erase(v3, v2[0], v2[1], v2[2]);
          std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v3);
          if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
          {
            CInputProcessor::Default(this, 0);
            CInputProcessor::Clear(this);
          }
          break;
        }
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator++(v6);
      }
      v18 = -1;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v6);
    }
  }
}


// address=[0x1455440]
// Decompiled from void __thiscall CInputProcessor::AddToSelection(CInputProcessor *this, int _iEntityId)
void  CInputProcessor::AddToSelection(int _iEntityId) {
  
  IEntity *v3; // [esp+4h] [ebp-8h]
  __int16 v4; // [esp+Ah] [ebp-2h] BYREF

  if ( _iEntityId > 0 && (unsigned int)std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) < 100 )
  {
    v3 = CMapObjectMgr::EntityPtr(_iEntityId);
    if ( v3 )
    {
      v4 = _iEntityId;
      std::vector<unsigned short>::push_back(&CInputProcessor::m_vSelection, &v4);
      CFsm::GenerateEvent(this->m_pFSM, 484, 0);
      if ( IEntity::FlagBits(v3, EntityFlag_Selectable) )
        IEntity::SetFlagBits(v3, EntityFlag_Selected);
      else
        IEntity::SetFlagBits(v3, (EntityFlag)0x400);
    }
  }
}


// address=[0x14554d0]
// Decompiled from int __thiscall CInputProcessor::GetSelectionTypeOfCurrentSelection(CInputProcessor *this)
int  CInputProcessor::GetSelectionTypeOfCurrentSelection(void)const {
  
  unsigned __int16 *v1; // eax
  struct IEntity *v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v4 = 0;
  if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    return v4;
  v1 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  v2 = CMapObjectMgr::EntityPtr(*v1);
  return CInputProcessor::GetEntitySelectionType(v2);
}


// address=[0x1455520]
// Decompiled from int __cdecl CInputProcessor::GetEntitySelectionType(int _iObjType, int _iType, int _iWarriorType)
int __cdecl CInputProcessor::GetEntitySelectionType(int _iObjType, int _iType, int _iWarriorType) {
  
  int result; // eax

  if ( _iObjType == 8 )
    return 0x10000;
  switch ( _iWarriorType )
  {
    case 0:
      result = 0;
      break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      result = _iWarriorType + 0x30000;
      break;
    case 6:
      result = 0x30000;
      break;
    case 7:
      result = (_iType << 8) + 0x20000;
      break;
    case 8:
    case 9:
      result = 0x40000;
      break;
    case 10:
    case 11:
      result = 0x50000;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}


// address=[0x14555b0]
// Decompiled from int __cdecl CInputProcessor::GetEntitySelectionType(struct IEntity *a1)
int __cdecl CInputProcessor::GetEntitySelectionType(class IEntity const * a1) {
  
  int objType; // [esp+0h] [ebp-Ch]
  int type; // [esp+4h] [ebp-8h]
  int warriorType; // [esp+8h] [ebp-4h]

  if ( !a1 )
    return 0;
  objType = IEntity::ObjType(a1);
  type = IEntity::Type(a1);
  warriorType = IEntity::WarriorType(a1);
  return CInputProcessor::GetEntitySelectionType(objType, type, warriorType);
}


// address=[0x1455600]
// Decompiled from int __cdecl CInputProcessor::GetEntitySelectionType(int a1)
int __cdecl CInputProcessor::GetEntitySelectionType(int a1) {
  
  struct IEntity *v1; // eax

  if ( a1 <= 0 )
    return 0;
  v1 = CMapObjectMgr::EntityPtr(a1);
  return CInputProcessor::GetEntitySelectionType(v1);
}


// address=[0x146ad70]
// Decompiled from bool __thiscall CInputProcessor::IsChooseSecondPatrolPosState(CInputProcessor *this)
bool  CInputProcessor::IsChooseSecondPatrolPosState(void) {
  
  return this->m_iViewState == 9;
}


// address=[0x146adb0]
// Decompiled from bool __thiscall CInputProcessor::IsTryBuildState(CInputProcessor *this)
bool  CInputProcessor::IsTryBuildState(void) {
  
  return this->m_iViewState == 4 || this->m_iViewState == 5 || this->m_iViewState == 6;
}


// address=[0x146ae00]
// Decompiled from bool __thiscall CInputProcessor::IsWorkingAreaState(CInputProcessor *this)
bool  CInputProcessor::IsWorkingAreaState(void) {
  
  return this->m_iViewState == 3;
}


// address=[0x146ae40]
// Decompiled from bool __thiscall CInputProcessor::IsZoomAreaState(CInputProcessor *this)
bool  CInputProcessor::IsZoomAreaState(void) {
  
  return this->m_iViewState == 10;
}


// address=[0x14e4ac0]
// Decompiled from BYTE __thiscall CInputProcessor::BoxSelectAllSettler(CInputProcessor *this)
bool  CInputProcessor::BoxSelectAllSettler(void)const {
  
  return this->m_bBoxSelectAllSettler;
}


// address=[0x14e4bd0]
// Decompiled from DWORD __thiscall CInputProcessor::StrictSelection(CInputProcessor *this)
int  CInputProcessor::StrictSelection(void)const {
  
  return this->m_iSelectionStrict;
}


// address=[0x14eb4b0]
// Decompiled from bool __thiscall CInputProcessor::IsBoxSelection(CInputProcessor *this)
bool  CInputProcessor::IsBoxSelection(void)const {
  
  return this->m_iSelectionMode || this->m_bBoxSelectAllSettler;
}


// address=[0x3f1f6b4]
// [Decompilation failed for static class std::vector<unsigned short,class std::allocator<unsigned short> > CInputProcessor::m_vSelection]

// address=[0x1455640]
// Decompiled from void __thiscall CInputProcessor::InitFSM(CInputProcessor *this)
void  CInputProcessor::InitFSM(void) {
  
  CFsm *v1; // [esp+8h] [ebp-18h]
  CFsm *C; // [esp+Ch] [ebp-14h]

  if ( this->m_pFSM && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 254, "m_pFsm == 0") == 1 )
    __debugbreak();
  C = (CFsm *)operator new(0x1Cu);
  if ( C )
    v1 = (CFsm *)CFsm::CFsm(C, this, 1500, 0);
  else
    v1 = 0;
  this->m_pFSM = v1;
  if ( !this->m_pFSM && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 259, "m_pFsm != 0") == 1 )
    __debugbreak();
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 401, Default);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 480, HandleInternalError);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 402, NewDialogClear);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, SELECT_STATE, 477, DotSelection);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, SELECT_STATE, 478, PrepareBoxSelection);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, SELECT_STATE, 426, SelectTypeInSurrounding);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, SELECT_STATE, 408, SelectNextBuilding);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, SELECT_STATE, 486, SelectBuilding);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, SELECT_STATE, 427, SelectNextVehicle);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, SELECT_STATE, 484, EmptyFunct);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 482, InitExtraMenu);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 436, InitEconomyGameMenu);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 428, BuildingAmount);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, TRY_BUILD_STATE, 437, TryBuild);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 438, MarkNextBuilding);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 429, InitSettlerAmount);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 430, InitFreeCarrier);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 431, InitSettlerProduction);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 485, InitSettlerSearch);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, SELECT_STATE, 441, SearchUnit);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 441, SearchUnit);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 442, UnitReservation);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 481, SpecialistProduction);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, SELECT_STATE, 472, SelectGroup);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, SELECT_STATE, 473, FocusGroup);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 432, InitGoodAmount);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 433, InitTransportPrio);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 434, InitGoodDistribution);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 445, GoodDeliveringChanged);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 446, TransportPrioChanged);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 435, ClearDialog|TransportPrioChanged);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 458, InitEyeCatcherSideBar);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, WAIT_STATE, 440, SwitchLocalGlobal);
  CFsm::DefineTransition(this->m_pFSM, WAIT_STATE, ZOOM_AREA_STATE, 487, ZoomAreaState);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, WAIT_STATE, 401, Default);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 477, DotSelection);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 478, PrepareBoxSelection);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 426, SelectTypeInSurrounding);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 481, SpecialistProduction);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 480, SendTo);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 415, InjuredOut);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 423, MorphToCarrier);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 470, DefineGroup);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 472, SelectGroup);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 473, FocusGroup);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 471, GroupToSelection);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 411, ForceGoto);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 412, StandGround);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SET_SECOND_PATROL_POS_STATE, 414, ChooseSecondPatrolPos);
  CFsm::DefineTransition(this->m_pFSM, SET_SECOND_PATROL_POS_STATE, SELECT_STATE, 401, Default);
  CFsm::DefineTransition(this->m_pFSM, SET_SECOND_PATROL_POS_STATE, SELECT_STATE, 480, Default);
  CFsm::DefineTransition(this->m_pFSM, SET_SECOND_PATROL_POS_STATE, WAIT_STATE, 402, NewDialogClear);
  CFsm::DefineTransition(
    this->m_pFSM,
    SET_SECOND_PATROL_POS_STATE,
    SET_SECOND_PATROL_POS_STATE,
    477,
    SelectSecondPatrolPos);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 422, GotoVehicleGroupMenu);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 435, ClearDialog|TransportPrioChanged);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 448, DestroyWarMachine);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, WAIT_STATE, 402, NewDialogClear);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, TRY_BUILD_STATE, 437, TryBuild);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SET_WORKINGAREA_STATE, 403, ShowWorkingArea);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 404, TryCrushBuilding);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 405, CrushBuilding);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 406, SwitchBuilding);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 407, PrioBuildingSite);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 408, SelectNextBuilding);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 486, SelectBuilding);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 427, SelectNextVehicle);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 461, UnitProduction);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 462, UrgentProduction);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 463, WeaponPercent);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 464, WeaponAutoproduction);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 468, StorageGoodSwitch);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 469, VehicleProduction);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 447, DestroyBuildupVehicle);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, CHOOSE_TRADE_DEST_STATE, 409, ChooseTradeDest);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 465, TransportGoods);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 466, TradeWith);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 467, TradeGoods);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 483, SetTradePlayerStatus);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 443, FillTower);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 444, EmptyTower);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, CHOOSE_SPELL_DEST_STATE, 449, InitMagicSideBar);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 450, InitGroupSideBar);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 451, InitAddSoldierSideBar);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 452, InitToolSideBar);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 453, InitWeaponSideBar);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 455, InitGoodsOutSideBar);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 456, InitTradeSideBar);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 457, InitStorageSideBar);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 459, InitAddVehicleSideBar);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 460, CloseSideBar);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 419, Morph2FoundationCart);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 421, CreateSettlement);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 420, Morph2Cart);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 417, VehicleUnload);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, SELECT_STATE, 418, CatapultLoad);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, ZOOM_AREA_STATE, 487, ZoomAreaState);
  CFsm::DefineTransition(this->m_pFSM, TRY_BUILD_STATE, WAIT_STATE, 401, Default);
  CFsm::DefineTransition(this->m_pFSM, TRY_BUILD_STATE, WAIT_STATE, 480, Default);
  CFsm::DefineTransition(this->m_pFSM, TRY_BUILD_STATE, WAIT_STATE, 402, NewDialogClear);
  CFsm::DefineTransition(this->m_pFSM, TRY_BUILD_STATE, WAIT_STATE, 428, BuildingAmount);
  CFsm::DefineTransition(this->m_pFSM, TRY_BUILD_STATE, SELECT_STATE, 478, PrepareBoxSelection);
  CFsm::DefineTransition(this->m_pFSM, TRY_BUILD_STATE, TRY_BUILD_STATE, 437, TryBuild);
  CFsm::DefineTransition(this->m_pFSM, TRY_BUILD_STATE, TRY_BUILD_STATE, 477, Build);
  CFsm::DefineTransition(this->m_pFSM, TRY_BUILD_STATE, TRY_BUILD_STATE, 438, MarkNextBuilding);
  CFsm::DefineTransition(this->m_pFSM, TRY_BUILD_STATE, WAIT_STATE, 458, InitEyeCatcherSideBar);
  CFsm::DefineTransition(this->m_pFSM, TRY_BUILD_STATE, ZOOM_AREA_STATE, 487, ZoomAreaState);
  CFsm::DefineTransition(this->m_pFSM, SET_WORKINGAREA_STATE, SELECT_STATE, 401, Default);
  CFsm::DefineTransition(this->m_pFSM, SET_WORKINGAREA_STATE, SELECT_STATE, 480, Default);
  CFsm::DefineTransition(this->m_pFSM, SET_WORKINGAREA_STATE, WAIT_STATE, 402, NewDialogClear);
  CFsm::DefineTransition(this->m_pFSM, SET_WORKINGAREA_STATE, SELECT_STATE, 478, PrepareBoxSelection);
  CFsm::DefineTransition(this->m_pFSM, SET_WORKINGAREA_STATE, SET_WORKINGAREA_STATE, 477, SetWorkingArea);
  CFsm::DefineTransition(this->m_pFSM, SET_WORKINGAREA_STATE, SELECT_STATE, 408, Default);
  CFsm::DefineTransition(this->m_pFSM, SET_WORKINGAREA_STATE, SELECT_STATE, 404, Default);
  CFsm::DefineTransition(this->m_pFSM, SET_WORKINGAREA_STATE, SELECT_STATE, 403, Default);
  CFsm::DefineTransition(this->m_pFSM, SET_WORKINGAREA_STATE, SELECT_STATE, 406, Default);
  CFsm::DefineTransition(this->m_pFSM, SET_WORKINGAREA_STATE, SELECT_STATE, 449, Default);
  CFsm::DefineTransition(this->m_pFSM, SET_WORKINGAREA_STATE, SELECT_STATE, 450, Default);
  CFsm::DefineTransition(this->m_pFSM, SET_WORKINGAREA_STATE, SELECT_STATE, 451, Default);
  CFsm::DefineTransition(this->m_pFSM, SET_WORKINGAREA_STATE, SELECT_STATE, 452, Default);
  CFsm::DefineTransition(this->m_pFSM, SET_WORKINGAREA_STATE, SELECT_STATE, 453, Default);
  CFsm::DefineTransition(this->m_pFSM, SET_WORKINGAREA_STATE, SELECT_STATE, 455, Default);
  CFsm::DefineTransition(this->m_pFSM, SET_WORKINGAREA_STATE, SELECT_STATE, 456, Default);
  CFsm::DefineTransition(this->m_pFSM, SET_WORKINGAREA_STATE, SELECT_STATE, 457, Default);
  CFsm::DefineTransition(this->m_pFSM, SET_WORKINGAREA_STATE, SELECT_STATE, 459, Default);
  CFsm::DefineTransition(this->m_pFSM, SET_WORKINGAREA_STATE, ZOOM_AREA_STATE, 487, ZoomAreaState);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_TRADE_DEST_STATE, SELECT_STATE, 401, Default);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_TRADE_DEST_STATE, SELECT_STATE, 480, Default);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_TRADE_DEST_STATE, WAIT_STATE, 402, NewDialogClear);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_TRADE_DEST_STATE, CHOOSE_TRADE_DEST_STATE, 477, SelectTradeDest);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_TRADE_DEST_STATE, ZOOM_AREA_STATE, 487, ZoomAreaState);
  CFsm::DefineTransition(this->m_pFSM, SELECT_STATE, CHOOSE_SPELL_DEST_STATE, 474, ChooseSpellDest);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_SPELL_DEST_STATE, CHOOSE_SPELL_DEST_STATE, 474, ChooseSpellDest);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_SPELL_DEST_STATE, CHOOSE_SPELL_DEST_STATE, 480, SelectSpellDest);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_SPELL_DEST_STATE, WAIT_STATE, 402, NewDialogClear);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_SPELL_DEST_STATE, SELECT_STATE, 477, DotSelection);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_SPELL_DEST_STATE, WAIT_STATE, 401, Default);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_SPELL_DEST_STATE, SELECT_STATE, 460, Default);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_SPELL_DEST_STATE, SELECT_STATE, 478, PrepareBoxSelection);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_SPELL_DEST_STATE, CHOOSE_SPELL_DEST_STATE, 470, DefineGroup);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_SPELL_DEST_STATE, CHOOSE_SPELL_DEST_STATE, 472, SelectGroup);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_SPELL_DEST_STATE, CHOOSE_SPELL_DEST_STATE, 473, FocusGroup);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_SPELL_DEST_STATE, SELECT_STATE, 411, ForceGoto);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_SPELL_DEST_STATE, SELECT_STATE, 412, StandGround);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_SPELL_DEST_STATE, SET_SECOND_PATROL_POS_STATE, 414, ChooseSecondPatrolPos);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_SPELL_DEST_STATE, SELECT_STATE, 415, InjuredOut);
  CFsm::DefineTransition(this->m_pFSM, CHOOSE_SPELL_DEST_STATE, ZOOM_AREA_STATE, 487, ZoomAreaState);
  CFsm::DefineTransition(this->m_pFSM, ZOOM_AREA_STATE, SELECT_STATE, 477, CamSelection);
  CFsm::DefineTransition(this->m_pFSM, ZOOM_AREA_STATE, SELECT_STATE, 480, Default);
}


// address=[0x14563d0]
// Decompiled from void __thiscall CInputProcessor::FillHandlersArray(CInputProcessor *this)
void  CInputProcessor::FillHandlersArray(void) {
  
  *this->m_pHandlers = (char (__thiscall *)(IEventHandler *, void *))CInputProcessor::HandleInternalError;
  *((_DWORD *)this->m_pHandlers + 1) = CInputProcessor::Default;
  *((_DWORD *)this->m_pHandlers + 17) = CInputProcessor::NewDialogClear;
  *((_DWORD *)this->m_pHandlers + 3) = CInputProcessor::EmptyFunct;
  *((_DWORD *)this->m_pHandlers + 4) = CInputProcessor::TryBuild;
  *((_DWORD *)this->m_pHandlers + 5) = CInputProcessor::Build;
  *((_DWORD *)this->m_pHandlers + 6) = j_CInputProcessor::ShowWorkingArea;
  *((_DWORD *)this->m_pHandlers + 7) = CInputProcessor::SetWorkingArea;
  *((_DWORD *)this->m_pHandlers + 8) = CInputProcessor::TryCrushBuilding;
  *((_DWORD *)this->m_pHandlers + 9) = CInputProcessor::CrushBuilding;
  *((_DWORD *)this->m_pHandlers + 10) = CInputProcessor::SwitchBuilding;
  *((_DWORD *)this->m_pHandlers + 11) = CInputProcessor::PrioBuildingSite;
  *((_DWORD *)this->m_pHandlers + 12) = CInputProcessor::SelectNextBuilding;
  *((_DWORD *)this->m_pHandlers + 13) = CInputProcessor::SelectBuilding;
  *((_DWORD *)this->m_pHandlers + 15) = CInputProcessor::MarkNextBuilding;
  *((_DWORD *)this->m_pHandlers + 14) = CInputProcessor::SelectNextVehicle;
  *((_DWORD *)this->m_pHandlers + 16) = CInputProcessor::BuildingAmount;
  *((_DWORD *)this->m_pHandlers + 18) = CInputProcessor::FillTower;
  *((_DWORD *)this->m_pHandlers + 19) = CInputProcessor::EmptyTower;
  *((_DWORD *)this->m_pHandlers + 21) = CInputProcessor::ChooseTradeDest;
  *((_DWORD *)this->m_pHandlers + 22) = CInputProcessor::SelectTradeDest;
  *((_DWORD *)this->m_pHandlers + 23) = CInputProcessor::TransportGoods;
  *((_DWORD *)this->m_pHandlers + 24) = CInputProcessor::TradeWith;
  *((_DWORD *)this->m_pHandlers + 25) = CInputProcessor::TradeGoods;
  *((_DWORD *)this->m_pHandlers + 26) = CInputProcessor::SetTradePlayerStatus;
  *((_DWORD *)this->m_pHandlers + 27) = CInputProcessor::PrepareBoxSelection;
  *((_DWORD *)this->m_pHandlers + 28) = CInputProcessor::DotSelection;
  *((_DWORD *)this->m_pHandlers + 29) = CInputProcessor::SelectTypeInSurrounding;
  *((_DWORD *)this->m_pHandlers + 30) = CInputProcessor::SelectGroup;
  *((_DWORD *)this->m_pHandlers + 31) = j_CInputProcessor::GroupToSelection;
  *((_DWORD *)this->m_pHandlers + 32) = CInputProcessor::DefineGroup;
  *((_DWORD *)this->m_pHandlers + 33) = CInputProcessor::FocusGroup;
  *((_DWORD *)this->m_pHandlers + 34) = CInputProcessor::SendTo;
  *((_DWORD *)this->m_pHandlers + 35) = CInputProcessor::ForceGoto;
  *((_DWORD *)this->m_pHandlers + 36) = j_CInputProcessor::StandGround;
  *((_DWORD *)this->m_pHandlers + 37) = CInputProcessor::ChooseSecondPatrolPos;
  *((_DWORD *)this->m_pHandlers + 38) = j_CInputProcessor::SelectSecondPatrolPos;
  *((_DWORD *)this->m_pHandlers + 40) = CInputProcessor::InjuredOut;
  *((_DWORD *)this->m_pHandlers + 41) = CInputProcessor::MorphToCarrier;
  *((_DWORD *)this->m_pHandlers + 20) = CInputProcessor::InitExtraMenu;
  *((_DWORD *)this->m_pHandlers + 56) = CInputProcessor::InitEconomyGameMenu;
  *((_DWORD *)this->m_pHandlers + 39) = CInputProcessor::GotoVehicleGroupMenu;
  *((_DWORD *)this->m_pHandlers + 48) = CInputProcessor::SearchUnit;
  *((_DWORD *)this->m_pHandlers + 49) = CInputProcessor::UnitReservation;
  *((_DWORD *)this->m_pHandlers + 42) = j_CInputProcessor::ChooseSpellDest;
  *((_DWORD *)this->m_pHandlers + 43) = CInputProcessor::SelectSpellDest;
  *((_DWORD *)this->m_pHandlers + 74) = CInputProcessor::SwitchLocalGlobal;
  *((_DWORD *)this->m_pHandlers + 44) = CInputProcessor::InitSettlerAmount;
  *((_DWORD *)this->m_pHandlers + 45) = CInputProcessor::InitFreeCarrier;
  *((_DWORD *)this->m_pHandlers + 46) = CInputProcessor::InitSettlerProduction;
  *((_DWORD *)this->m_pHandlers + 47) = CInputProcessor::InitSettlerSearch;
  *((_DWORD *)this->m_pHandlers + 50) = CInputProcessor::InitGoodAmount;
  *((_DWORD *)this->m_pHandlers + 51) = CInputProcessor::InitTransportPrio;
  *((_DWORD *)this->m_pHandlers + 52) = CInputProcessor::InitGoodDistribution;
  *((_DWORD *)this->m_pHandlers + 54) = CInputProcessor::GoodDeliveringChanged;
  *((_DWORD *)this->m_pHandlers + 53) = CInputProcessor::TransportPrioChanged;
  *((_DWORD *)this->m_pHandlers + 68) = CInputProcessor::UnitProduction;
  *((_DWORD *)this->m_pHandlers + 69) = CInputProcessor::UrgentProduction;
  *((_DWORD *)this->m_pHandlers + 70) = CInputProcessor::WeaponPercent;
  *((_DWORD *)this->m_pHandlers + 71) = CInputProcessor::WeaponAutoproduction;
  *((_DWORD *)this->m_pHandlers + 72) = CInputProcessor::StorageGoodSwitch;
  *((_DWORD *)this->m_pHandlers + 73) = CInputProcessor::VehicleProduction;
  *((_DWORD *)this->m_pHandlers + 82) = CInputProcessor::DestroyBuildupVehicle;
  *((_DWORD *)this->m_pHandlers + 75) = CInputProcessor::SpecialistProduction;
  *((_DWORD *)this->m_pHandlers + 57) = j_CInputProcessor::InitMagicSideBar;
  *((_DWORD *)this->m_pHandlers + 58) = CInputProcessor::InitGroupSideBar;
  *((_DWORD *)this->m_pHandlers + 59) = CInputProcessor::InitAddSoldierSideBar;
  *((_DWORD *)this->m_pHandlers + 60) = CInputProcessor::InitToolSideBar;
  *((_DWORD *)this->m_pHandlers + 61) = CInputProcessor::InitWeaponSideBar;
  *((_DWORD *)this->m_pHandlers + 62) = CInputProcessor::InitGoodsOutSideBar;
  *((_DWORD *)this->m_pHandlers + 63) = CInputProcessor::InitTradeSideBar;
  *((_DWORD *)this->m_pHandlers + 64) = CInputProcessor::InitStorageSideBar;
  *((_DWORD *)this->m_pHandlers + 65) = CInputProcessor::InitEyeCatcherSideBar;
  *((_DWORD *)this->m_pHandlers + 66) = CInputProcessor::InitAddVehicleSideBar;
  *((_DWORD *)this->m_pHandlers + 67) = j_CInputProcessor::CloseSideBar;
  *((_DWORD *)this->m_pHandlers + 76) = CInputProcessor::Morph2FoundationCart;
  *((_DWORD *)this->m_pHandlers + 77) = CInputProcessor::CreateSettlement;
  *((_DWORD *)this->m_pHandlers + 78) = CInputProcessor::Morph2Cart;
  *((_DWORD *)this->m_pHandlers + 79) = CInputProcessor::VehicleUnload;
  *((_DWORD *)this->m_pHandlers + 80) = CInputProcessor::CatapultLoad;
  *((_DWORD *)this->m_pHandlers + 81) = CInputProcessor::DestroyWarMachine;
  *((_DWORD *)this->m_pHandlers + 2) = CInputProcessor::ClearDialog;
  *((_DWORD *)this->m_pHandlers + 83) = CInputProcessor::ZoomAreaState;
  *((_DWORD *)this->m_pHandlers + 84) = CInputProcessor::CamSelection;
}


// address=[0x1456ac0]
// Decompiled from char __thiscall CInputProcessor::HandleInternalError(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::HandleInternalError(class CEvn_Logic * a2) {
  
  OutputDebugStringA("Handle internal error in InputProcessor\n");
  return 0;
}


// address=[0x1456ae0]
// Decompiled from bool __thiscall CInputProcessor::Default(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::Default(class CEvn_Logic * a2) {
  
  CEvn_Event v4; // [esp+Ch] [ebp-40h] BYREF
  CEvn_Event v5; // [esp+24h] [ebp-28h] BYREF
  int v6; // [esp+48h] [ebp-4h]

  CInputProcessor::TidyUp(this);
  this->unk_1C = 0;
  CEvn_Event::CEvn_Event(&v4, 0x260u, 0, 0, 0);
  v6 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 4459, "g_pEvnEngine!= NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v4);
  CEvn_Event::CEvn_Event(&v5, 0x259u, 0, 0, 0);
  LOBYTE(v6) = 1;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 4470, "g_pEvnEngine!= NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v5);
  LOBYTE(v6) = 0;
  CEvn_Event::~CEvn_Event(&v5);
  v6 = -1;
  CEvn_Event::~CEvn_Event(&v4);
  return 0;
}


// address=[0x1456c10]
// Decompiled from char __thiscall CInputProcessor::NewDialogClear(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::NewDialogClear(class CEvn_Logic * a2) {
  
  CInputProcessor::DeSelectAll(this);
  CLogic::SetFillDialogInfos(g_pLogic, 0, 0, 0);
  CInputProcessor::Default(this, a2);
  return 0;
}


// address=[0x1456c50]
// Decompiled from char __thiscall CInputProcessor::ClearDialog(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::ClearDialog(class CEvn_Logic * a2) {
  
  CInputProcessor::Clear(this);
  return 0;
}


// address=[0x1456c70]
// Decompiled from char __thiscall CInputProcessor::TryBuild(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::TryBuild(class CEvn_Logic * a2) {
  
  int LocalPlayerId; // eax

  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  if ( !CPlayerManager::IsAlive(LocalPlayerId) )
    return 0;
  CInputProcessor::DeSelectAll(this);
  CWorldManager::ClearHelperObject();
  this->m_iViewState = 4;
  this->m_iBuildBuildingType = a2->m_lParam;
  IGfxEngine::EnableIconLayer(g_pGfxEngine, 1);
  IGfxEngine::SetCursorShape(g_pGfxEngine, 1, 3u);
  return 1;
}


// address=[0x1456ce0]
// Decompiled from char __thiscall CInputProcessor::Build(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::Build(class CEvn_Logic * a2) {
  
  int LocalPlayerId; // eax
  uchar cLocalPlayerId; // al
  DWORD iBuildBuildingType; // [esp-8h] [ebp-50h]
  uint packedXY; // [esp+4h] [ebp-44h]
  int x; // [esp+Ch] [ebp-3Ch]
  unsigned int y; // [esp+10h] [ebp-38h]
  CEvn_Logic v10; // [esp+18h] [ebp-30h] BYREF
  int v11; // [esp+44h] [ebp-4h]

  this->unk_1C = 0;
  x = LOWORD(a2->m_lParam);
  y = HIWORD(a2->m_lParam);
  iBuildBuildingType = this->m_iBuildBuildingType;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  if ( CBuildingMgr::CheckForBuild((CBuildingMgr *)g_cBuildingMgr, x, y, LocalPlayerId, iBuildBuildingType, 0) <= 0 )
    return 1;
  packedXY = Y16X16::PackXYFast(x, y);
  cLocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CEvn_Logic::CEvn_Logic(&v10, 0x13A1u, this->m_iBuildBuildingType, packedXY, cLocalPlayerId, 0, 0);
  v11 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1603, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v10);
  CInputProcessor::Default(this, a2);
  CFsm::GenerateEvent(this->m_pFSM, 401, 0);
  v11 = -1;
  CEvn_Logic::~CEvn_Logic(&v10);
  return 1;
}


// address=[0x1456e30]
// Decompiled from char __thiscall CInputProcessor::ShowWorkingArea(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::ShowWorkingArea(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  IEntity *v3; // eax
  unsigned __int16 *v5; // eax

  if ( std::vector<unsigned short>::size(&CInputProcessor::m_vSelection)
    && (v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0),
        v3 = CMapObjectMgr::EntityPtr(*v2),
        IEntity::ObjType(v3) == BUILDING_OBJ) )
  {
    this->m_iViewState = 3;
    v5 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
    CBuildingMgr::ShowWorkingArea((CBuildingMgr *)g_cBuildingMgr, *v5);
    IGfxEngine::EnableIconLayer(g_pGfxEngine, 1);
    return 1;
  }
  else
  {
    CInputProcessor::Default(this, a2);
    CFsm::GenerateEvent(this->m_pFSM, 401, 0);
    return 0;
  }
}


// address=[0x1456ed0]
// Decompiled from char __thiscall CInputProcessor::SetWorkingArea(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SetWorkingArea(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax
  uchar LocalPlayerId; // [esp-Ch] [ebp-54h]
  uint packedXY; // [esp+4h] [ebp-44h]
  int iX; // [esp+Ch] [ebp-3Ch] BYREF
  int iY; // [esp+10h] [ebp-38h] BYREF
  int m_lParam; // [esp+14h] [ebp-34h]
  CEvn_Logic v11; // [esp+18h] [ebp-30h] BYREF
  int v12; // [esp+44h] [ebp-4h]

  m_lParam = a2->m_lParam;
  iX = Y16X16::UnpackXFast(m_lParam);
  iY = Y16X16::UnpackYFast(m_lParam);
  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  if ( !CBuildingMgr::IsGoodWorkingAreaCenter((CBuildingMgr *)g_cBuildingMgr, *v2, &iX, &iY) )
    return 1;
  packedXY = Y16X16::PackXYFast(iX, iY);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic(&v11, 0x1389u, *v3, packedXY, LocalPlayerId, 0, 0);
  v12 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1742, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v11);
  CInputProcessor::Default(this, a2);
  CFsm::GenerateEvent(this->m_pFSM, 401, 0);
  v12 = -1;
  CEvn_Logic::~CEvn_Logic(&v11);
  return 1;
}


// address=[0x1457020]
// Decompiled from char __thiscall CInputProcessor::TryCrushBuilding(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::TryCrushBuilding(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  CBuilding *v3; // eax
  int v4; // esi
  unsigned __int16 *v5; // eax
  CBuilding *v6; // eax

  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  v3 = CBuildingMgr::operator[](*v2);
  v4 = IEntity::OwnerId((IEntity *)v3);
  if ( v4 != CPlayerManager::GetLocalPlayerId()
    && BBSupportDbgReport(
         2,
         "Logic\\InputProcessor.cpp",
         1624,
         "g_cBuildingMgr[ m_vSelection[ 0 ] ].OwnerId() == CPlayerManager::GetLocalPlayerId()") == 1 )
  {
    __debugbreak();
  }
  v5 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  v6 = CBuildingMgr::operator[](*v5);
  CBuilding::TryCrushBuilding((IEntity *)v6);
  return 1;
}


// address=[0x14570a0]
// Decompiled from char __thiscall CInputProcessor::CrushBuilding(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::CrushBuilding(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  uchar LocalPlayerId; // [esp-Ch] [ebp-44h]
  CEvn_Logic v6; // [esp+8h] [ebp-30h] BYREF
  int v7; // [esp+34h] [ebp-4h]

  if ( a2->m_wParam )
  {
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
    CEvn_Logic::CEvn_Logic(&v6, 0x138Au, *v2, 0, LocalPlayerId, 0, 0);
    v7 = 0;
    if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1654, "g_pNetworkEngine != NULL") == 1 )
      __debugbreak();
    if ( g_pNetworkEngine )
      INetworkEngine::SendNetMessage(g_pNetworkEngine, &v6);
    CInputProcessor::Clear(this);
    CFsm::GenerateEvent(this->m_pFSM, 401, 0);
    v7 = -1;
    CEvn_Logic::~CEvn_Logic(&v6);
  }
  else
  {
    CInputProcessor::RequestDialog(this);
  }
  return 1;
}


// address=[0x14571a0]
// Decompiled from char __thiscall CInputProcessor::SwitchBuilding(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SwitchBuilding(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  uchar LocalPlayerId; // [esp-Ch] [ebp-48h]
  CEvn_Logic v5; // [esp+Ch] [ebp-30h] BYREF
  int v6; // [esp+38h] [ebp-4h]

  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic(&v5, 0x138Bu, *v2, 0, LocalPlayerId, 0, 0);
  v6 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1683, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v5);
  v6 = -1;
  CEvn_Logic::~CEvn_Logic(&v5);
  return 1;
}


// address=[0x1457270]
// Decompiled from char __thiscall CInputProcessor::PrioBuildingSite(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::PrioBuildingSite(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  uchar LocalPlayerId; // [esp-Ch] [ebp-48h]
  CEvn_Logic v5; // [esp+Ch] [ebp-30h] BYREF
  int v6; // [esp+38h] [ebp-4h]

  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic(&v5, 0x138Cu, *v2, 0, LocalPlayerId, 0, 0);
  v6 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1707, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v5);
  v6 = -1;
  CEvn_Logic::~CEvn_Logic(&v5);
  return 1;
}


// address=[0x1457340]
// Decompiled from char __thiscall CInputProcessor::SelectNextBuilding(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SelectNextBuilding(class CEvn_Logic * a2) {
  
  unsigned __int16 *v3; // eax
  IEntity *v4; // eax
  int LocalPlayerId; // eax
  IEntity *v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // [esp-8h] [ebp-4Ch]
  IEntity *NextBuilding; // [esp+4h] [ebp-40h]
  IEntity *BuildingPtr; // [esp+8h] [ebp-3Ch]
  int m_lParam; // [esp+Ch] [ebp-38h]
  __int16 v12; // [esp+12h] [ebp-32h] BYREF
  int v13; // [esp+14h] [ebp-30h]
  CEvn_Event v15; // [esp+1Ch] [ebp-28h] BYREF
  int v16; // [esp+40h] [ebp-4h]

  m_lParam = a2->m_lParam;
  if ( !m_lParam )
  {
    if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection)
      && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 999, "m_vSelection.size() > 0") == 1 )
    {
      __debugbreak();
    }
    if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    {
      CInputProcessor::Default(this, a2);
      CFsm::GenerateEvent(this->m_pFSM, 401, 0);
      return 0;
    }
    v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
    v4 = CMapObjectMgr::EntityPtr(*v3);
    m_lParam = IEntity::Type(v4);
  }
  CInputProcessor::DeSelectAll(this);
  CInputProcessor::Default(this, a2);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  NextBuilding = (IEntity *)CBuildingMgr::GetNextBuilding((CBuildingMgr *)g_cBuildingMgr, LocalPlayerId, m_lParam);
  if ( NextBuilding )
  {
    v13 = IEntity::ID(NextBuilding);
    if ( !v13 )
      return 0;
    v12 = v13;
    std::vector<unsigned short>::push_back(&CInputProcessor::m_vSelection, &v12);
    CInputProcessor::RequestDialog(this);
    v6 = CMapObjectMgr::EntityPtr(v13);
    IEntity::SetFlagBits(v6, EntityFlag_Selected);
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v13);
    CBuilding::NotifySelected(BuildingPtr);
    v8 = IEntity::X(BuildingPtr);
    v7 = IEntity::Y(BuildingPtr);
    CEvn_Event::CEvn_Event(&v15, 0x13u, v7, v8, 0);
    v16 = 0;
    if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1047, "g_pEvnEngine != NULL") == 1 )
      __debugbreak();
    if ( g_pEvnEngine )
      IEventEngine::SendAMessage(g_pEvnEngine, &v15);
    v16 = -1;
    CEvn_Event::~CEvn_Event(&v15);
    return 0;
  }
  else
  {
    CFsm::GenerateEvent(this->m_pFSM, 401, 0);
    return 0;
  }
}


// address=[0x1457550]
// Decompiled from char __thiscall CInputProcessor::SelectBuilding(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SelectBuilding(class CEvn_Logic * a2) {
  
  unsigned __int16 *v3; // eax
  IEntity *v4; // eax
  int LocalPlayerId; // eax
  IEntity *v6; // eax
  unsigned int y; // eax
  unsigned int x; // [esp-8h] [ebp-4Ch]
  IEntity *Building; // [esp+4h] [ebp-40h]
  IEntity *BuildingPtr; // [esp+8h] [ebp-3Ch]
  int m_lParam; // [esp+Ch] [ebp-38h]
  __int16 v12; // [esp+12h] [ebp-32h] BYREF
  int v13; // [esp+14h] [ebp-30h]
  CEvn_Event v15; // [esp+1Ch] [ebp-28h] BYREF
  int v16; // [esp+40h] [ebp-4h]

  m_lParam = a2->m_lParam;
  if ( !m_lParam )
  {
    if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection)
      && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1070, "m_vSelection.size() > 0") == 1 )
    {
      __debugbreak();
    }
    if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    {
      CInputProcessor::Default(this, a2);
      CFsm::GenerateEvent(this->m_pFSM, 401, 0);
      return 0;
    }
    v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
    v4 = CMapObjectMgr::EntityPtr(*v3);
    m_lParam = IEntity::Type(v4);
  }
  CInputProcessor::DeSelectAll(this);
  CInputProcessor::Default(this, a2);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  Building = (IEntity *)CBuildingMgr::GetBuilding((CBuildingMgr *)g_cBuildingMgr, LocalPlayerId, m_lParam);
  if ( Building )
  {
    v13 = IEntity::ID(Building);
    if ( !v13 )
      return 0;
    v12 = v13;
    std::vector<unsigned short>::push_back(&CInputProcessor::m_vSelection, &v12);
    CInputProcessor::RequestDialog(this);
    v6 = CMapObjectMgr::EntityPtr(v13);
    IEntity::SetFlagBits(v6, EntityFlag_Selected);
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v13);
    CBuilding::NotifySelected(BuildingPtr);
    x = IEntity::X(BuildingPtr);
    y = IEntity::Y(BuildingPtr);
    CEvn_Event::CEvn_Event(&v15, 0x13u, y, x, 0);
    v16 = 0;
    if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1118, "g_pEvnEngine != NULL") == 1 )
      __debugbreak();
    if ( g_pEvnEngine )
      IEventEngine::SendAMessage(g_pEvnEngine, &v15);
    v16 = -1;
    CEvn_Event::~CEvn_Event(&v15);
    return 0;
  }
  else
  {
    CFsm::GenerateEvent(this->m_pFSM, 401, 0);
    return 0;
  }
}


// address=[0x1457760]
// Decompiled from char __thiscall CInputProcessor::MarkNextBuilding(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::MarkNextBuilding(class CEvn_Logic * a2) {
  
  int LocalPlayerId; // eax
  unsigned int v3; // eax
  unsigned int v5; // [esp-8h] [ebp-40h]
  int _iBuildingType; // [esp-4h] [ebp-3Ch]
  CBuilding *NextBuilding; // [esp+Ch] [ebp-2Ch]
  CEvn_Event v8; // [esp+10h] [ebp-28h] BYREF
  int v9; // [esp+34h] [ebp-4h]

  _iBuildingType = a2->m_lParam;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  NextBuilding = CBuildingMgr::GetNextBuilding((CBuildingMgr *)g_cBuildingMgr, LocalPlayerId, _iBuildingType);
  if ( !NextBuilding )
    return 0;
  v5 = IEntity::X(NextBuilding);
  v3 = IEntity::Y(NextBuilding);
  CEvn_Event::CEvn_Event(&v8, 0x13u, v3, v5, 0);
  v9 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1148, "g_pEvnEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v8);
  v9 = -1;
  CEvn_Event::~CEvn_Event(&v8);
  return 0;
}


// address=[0x1457850]
// Decompiled from char __thiscall CInputProcessor::InitExtraMenu(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitExtraMenu(class CEvn_Logic * a2) {
  
  CLogic::SwitchExtraInfoMenu(g_pLogic, a2->m_wParam == 1);
  CStatistic::FillExtraInfo((CStatistic *)&g_cStatistic);
  return 0;
}


// address=[0x1457890]
// Decompiled from char __thiscall CInputProcessor::SelectNextVehicle(CInputProcessor *this, struct CEvn_Logic *_pEvent)
bool  CInputProcessor::SelectNextVehicle(class CEvn_Logic * _pEvent) {
  
  unsigned __int16 *v3; // eax
  int LocalPlayerId; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-8h] [ebp-4Ch]
  int v7; // [esp+4h] [ebp-40h]
  int m_lParam; // [esp+8h] [ebp-3Ch]
  __int16 v9; // [esp+Eh] [ebp-36h] BYREF
  int FirstVehicleId; // [esp+14h] [ebp-30h]
  IEntity *VehiclePtr; // [esp+18h] [ebp-2Ch]
  CEvn_Event v13; // [esp+1Ch] [ebp-28h] BYREF
  int v14; // [esp+40h] [ebp-4h]

  if ( !_pEvent && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 878, "_pEvent!= NULL") == 1 )
    __debugbreak();
  if ( !_pEvent )
    return 0;
  VehiclePtr = 0;
  v7 = 0;
  m_lParam = _pEvent->m_lParam;
  if ( !m_lParam )
  {
    if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection)
      && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 890, "m_vSelection.size() > 0") == 1 )
    {
      __debugbreak();
    }
    if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    {
      CInputProcessor::Default(this, _pEvent);
      CFsm::GenerateEvent(this->m_pFSM, 401, 0);
      return 0;
    }
    v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
    VehiclePtr = CVehicleMgr::GetVehiclePtr(*v3);
    v7 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
    if ( !VehiclePtr && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 901, "pVehicle!=NULL") == 1 )
      __debugbreak();
    if ( !VehiclePtr )
      return 0;
    m_lParam = IEntity::Type(VehiclePtr);
  }
  CInputProcessor::DeSelectAll(this);
  CInputProcessor::Default(this, _pEvent);
  if ( !VehiclePtr && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 914, "pVehicle!=NULL") == 1 )
    __debugbreak();
  if ( !VehiclePtr )
    return 0;
  FirstVehicleId = 0;
  do
  {
    FirstVehicleId = IAnimatedEntity::Next(VehiclePtr);
    if ( !FirstVehicleId )
    {
      LocalPlayerId = CPlayerManager::GetLocalPlayerId();
      FirstVehicleId = CVehicleMgr::GetFirstVehicleId((CVehicleMgr *)&g_cVehicleMgr, LocalPlayerId, m_lParam);
    }
    VehiclePtr = CVehicleMgr::GetVehiclePtr(FirstVehicleId);
  }
  while ( FirstVehicleId != v7 && IEntity::FlagBits(VehiclePtr, EntityFlag_OnBoard) );
  if ( FirstVehicleId && VehiclePtr )
  {
    v9 = FirstVehicleId;
    std::vector<unsigned short>::push_back(&CInputProcessor::m_vSelection, &v9);
    CInputProcessor::RequestDialog(this);
    if ( IEntity::FlagBits(VehiclePtr, (EntityFlag)0x4000) )
      IEntity::SetFlagBits(VehiclePtr, (EntityFlag)1024);
    else
      IEntity::SetFlagBits(VehiclePtr, EntityFlag_Selected);
    v6 = IEntity::X(VehiclePtr);
    v5 = IEntity::Y(VehiclePtr);
    CEvn_Event::CEvn_Event(&v13, 0x13u, v5, v6, 0);
    v14 = 0;
    if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 971, "g_pEvnEngine != NULL") == 1 )
      __debugbreak();
    if ( g_pEvnEngine )
      IEventEngine::SendAMessage(g_pEvnEngine, &v13);
    v14 = -1;
    CEvn_Event::~CEvn_Event(&v13);
  }
  else
  {
    CFsm::GenerateEvent(this->m_pFSM, 401, 0);
  }
  return 0;
}


// address=[0x1457b80]
// Decompiled from char __thiscall CInputProcessor::BuildingAmount(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::BuildingAmount(class CEvn_Logic * a2) {
  
  struct CInfoExchange *sBuildingMenuInfo; // [esp+0h] [ebp-Ch]
  int m_lParam; // [esp+8h] [ebp-4h]

  m_lParam = a2->m_lParam;
  if ( !m_lParam || *(_DWORD *)(m_lParam + 4) != 28 )
    return 0;
  sBuildingMenuInfo = (struct CInfoExchange *)a2->m_lParam;
  CBuildingMgr::FillBuildingAmount(sBuildingMenuInfo, 0, this->m_bIsLocal);
  CLogic::SetFillDialogInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, bool))CBuildingMgr::FillBuildingAmount,
    sBuildingMenuInfo,
    this->m_bIsLocal);
  return 0;
}


// address=[0x1457bf0]
// Decompiled from char __thiscall CInputProcessor::DestroyBuildupVehicle(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::DestroyBuildupVehicle(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  uchar LocalPlayerId; // al
  uint v6; // [esp+8h] [ebp-38h]
  CEvn_Logic v7; // [esp+10h] [ebp-30h] BYREF
  int v8; // [esp+3Ch] [ebp-4h]

  if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection)
    && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 5348, "m_vSelection.size()!=0") == 1 )
  {
    __debugbreak();
  }
  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  if ( !CMapObjectMgr::ValidEntityId(*v2)
    && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 5349, "g_pMapObjectMgr->ValidEntityId(m_vSelection[0])") == 1 )
  {
    __debugbreak();
  }
  v6 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CEvn_Logic::CEvn_Logic(&v7, 0x13A6u, v6, 0, LocalPlayerId, 0, 0);
  v8 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 5360, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v7);
  CInputProcessor::Clear(this);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(&v7);
  return 1;
}


// address=[0x1457d40]
// Decompiled from char __thiscall CInputProcessor::FillTower(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::FillTower(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  uint m_lParam; // [esp-10h] [ebp-4Ch]
  uchar LocalPlayerId; // [esp-Ch] [ebp-48h]
  CEvn_Logic v6; // [esp+Ch] [ebp-30h] BYREF
  int v7; // [esp+38h] [ebp-4h]

  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  m_lParam = a2->m_lParam;
  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic(&v6, 0x13A7u, *v2, m_lParam, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1772, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v6);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(&v6);
  return 1;
}


// address=[0x1457e20]
// Decompiled from char __thiscall CInputProcessor::EmptyTower(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::EmptyTower(class CEvn_Logic * a2) {
  
  int m_wParam_low; // esi
  uchar LocalPlayerId; // al
  uint v5; // [esp+Ch] [ebp-38h]
  CEvn_Logic v6; // [esp+14h] [ebp-30h] BYREF
  int v7; // [esp+40h] [ebp-4h]

  m_wParam_low = LOWORD(a2->m_wParam);
  v5 = (*(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0) << 16) | m_wParam_low;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CEvn_Logic::CEvn_Logic(&v6, 0x13A8u, v5, a2->m_lParam, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1802, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v6);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(&v6);
  return 1;
}


// address=[0x1457f10]
// Decompiled from char __thiscall CInputProcessor::ChooseTradeDest(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::ChooseTradeDest(class CEvn_Logic * a2) {
  
  this->m_iViewState = 7;
  this->m_iBuildBuildingType = a2->m_lParam;
  IGfxEngine::EnableIconLayer(g_pGfxEngine, 1);
  IGfxEngine::SetCursorShape(g_pGfxEngine, 1, 6u);
  return 1;
}


// address=[0x1457f60]
// Decompiled from char __thiscall CInputProcessor::SelectTradeDest(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SelectTradeDest(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  int v3; // eax
  unsigned __int16 *v4; // eax
  uint v6; // [esp-10h] [ebp-70h]
  uchar LocalPlayerId; // [esp-Ch] [ebp-6Ch]
  CTradingBuildingRole *v8; // [esp+4h] [ebp-5Ch]
  unsigned int y; // [esp+8h] [ebp-58h]
  int x; // [esp+Ch] [ebp-54h]
  int v11; // [esp+10h] [ebp-50h]
  IEntity *BuildingPtr; // [esp+18h] [ebp-48h]
  int mapObjectIdAtPos; // [esp+1Ch] [ebp-44h]
  unsigned int spiralX; // [esp+20h] [ebp-40h]
  unsigned int spiralY; // [esp+24h] [ebp-3Ch]
  IEntity *mapObjectAtPos; // [esp+28h] [ebp-38h]
  int i; // [esp+2Ch] [ebp-34h]
  CEvn_Logic v19; // [esp+30h] [ebp-30h] BYREF
  int v20; // [esp+5Ch] [ebp-4h]

  x = LOWORD(a2->m_lParam);
  y = HIWORD(a2->m_lParam);
  v11 = CSpiralOffsets::Last(5);
  for ( i = 0; i <= v11; ++i )
  {
    spiralX = x + CSpiralOffsets::DeltaX(i);
    spiralY = y + CSpiralOffsets::DeltaY(i);
    if ( CWorldManager::InWorld(spiralX, spiralY) )
    {
      mapObjectIdAtPos = CWorldManager::MapObjectId(spiralX, spiralY);
      if ( mapObjectIdAtPos )
      {
        mapObjectAtPos = CMapObjectMgr::EntityPtr(mapObjectIdAtPos);
        if ( IEntity::ObjType(mapObjectAtPos) == BUILDING_OBJ )
        {
          v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
          BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *v2);
          v8 = (CTradingBuildingRole *)CBuilding::Role(BuildingPtr);
          v3 = IEntity::ID(mapObjectAtPos);
          if ( CTradingBuildingRole::IsPossibleTradeTarget(v8, v3) )
          {
            LocalPlayerId = CPlayerManager::GetLocalPlayerId();
            v6 = IEntity::ID(mapObjectAtPos);
            v4 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
            CEvn_Logic::CEvn_Logic(&v19, 0x138Du, *v4, v6, LocalPlayerId, 0, 0);
            v20 = 0;
            if ( !g_pNetworkEngine
              && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1873, "g_pNetworkEngine != NULL") == 1 )
            {
              __debugbreak();
            }
            if ( g_pNetworkEngine )
              INetworkEngine::SendNetMessage(g_pNetworkEngine, &v19);
            CBuilding::NotifySelected(BuildingPtr);
            CInputProcessor::Default(this, a2);
            CFsm::GenerateEvent(this->m_pFSM, 401, 0);
            v20 = -1;
            CEvn_Logic::~CEvn_Logic(&v19);
          }
        }
      }
    }
  }
  return 1;
}


// address=[0x1458160]
// Decompiled from char __thiscall CInputProcessor::TransportGoods(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::TransportGoods(class CEvn_Logic * a2) {
  
  int m_wParam_low; // esi
  uchar LocalPlayerId; // al
  uint v5; // [esp+Ch] [ebp-38h]
  CEvn_Logic v6; // [esp+14h] [ebp-30h] BYREF
  int v7; // [esp+40h] [ebp-4h]

  m_wParam_low = LOWORD(a2->m_wParam);
  v5 = (*(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0) << 16) | m_wParam_low;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CEvn_Logic::CEvn_Logic(&v6, 0x138Eu, v5, a2->m_lParam, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1913, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v6);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(&v6);
  return 1;
}


// address=[0x1458250]
// Decompiled from char __thiscall CInputProcessor::TradeWith(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::TradeWith(class CEvn_Logic * a2) {
  
  int m_wParam_low; // esi
  uchar LocalPlayerId; // al
  uint v5; // [esp+Ch] [ebp-38h]
  CEvn_Logic v6; // [esp+14h] [ebp-30h] BYREF
  int v7; // [esp+40h] [ebp-4h]

  m_wParam_low = LOWORD(a2->m_wParam);
  v5 = (*(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0) << 16) | m_wParam_low;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CEvn_Logic::CEvn_Logic(&v6, 0x138Fu, v5, a2->m_lParam, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1943, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v6);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(&v6);
  return 1;
}


// address=[0x1458340]
// Decompiled from char __thiscall CInputProcessor::TradeGoods(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::TradeGoods(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  uint m_wParam; // [esp-10h] [ebp-4Ch]
  uchar LocalPlayerId; // [esp-Ch] [ebp-48h]
  CEvn_Logic v6; // [esp+Ch] [ebp-30h] BYREF
  int v7; // [esp+38h] [ebp-4h]

  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  m_wParam = a2->m_wParam;
  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic(&v6, 0x1390u, *v2, m_wParam, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1967, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v6);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(&v6);
  return 1;
}


// address=[0x1458420]
// Decompiled from char __thiscall CInputProcessor::SetTradePlayerStatus(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SetTradePlayerStatus(class CEvn_Logic * a2) {
  
  uchar LocalPlayerId; // al
  unsigned int v4; // [esp+8h] [ebp-38h]
  CEvn_Logic v5; // [esp+10h] [ebp-30h] BYREF
  int v6; // [esp+3Ch] [ebp-4h]

  v4 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  if ( !CMapObjectMgr::ValidEntityId(v4)
    && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1980, "g_pMapObjectMgr->ValidEntityId(iBuildingID)") == 1 )
  {
    __debugbreak();
  }
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CEvn_Logic::CEvn_Logic(
    &v5,
    0x13BAu,
    ((unsigned __int16)v4 << 16) | LOWORD(a2->m_wParam),
    a2->m_lParam,
    LocalPlayerId,
    0,
    0);
  v6 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1990, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v5);
  v6 = -1;
  CEvn_Logic::~CEvn_Logic(&v5);
  return 1;
}


// address=[0x1458540]
// Decompiled from char __thiscall CInputProcessor::ChooseSpellDest(CInputProcessor *this, CEvn_Logic *a2)
bool  CInputProcessor::ChooseSpellDest(class CEvn_Logic * a2) {
  
  this->m_iSpellDestination = a2->m_wParam;
  return 1;
}


// address=[0x1458560]
// Decompiled from char __thiscall CInputProcessor::SelectSpellDest(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SelectSpellDest(class CEvn_Logic * a2) {
  
  unsigned __int16 *v3; // eax
  int v4; // eax
  uchar LocalPlayerId; // al
  int v6; // [esp-4h] [ebp-60h]
  uint v7; // [esp+4h] [ebp-58h]
  uint v8; // [esp+8h] [ebp-54h]
  int m_lParam_low; // [esp+Ch] [ebp-50h]
  unsigned int m_lParam_high; // [esp+10h] [ebp-4Ch]
  unsigned int v11; // [esp+14h] [ebp-48h]
  unsigned int v13; // [esp+1Ch] [ebp-40h]
  int iPriestId; // [esp+20h] [ebp-3Ch]
  unsigned int i; // [esp+24h] [ebp-38h]
  IMovingEntity *v16; // [esp+28h] [ebp-34h]
  CEvn_Logic v17; // [esp+2Ch] [ebp-30h] BYREF
  int v18; // [esp+58h] [ebp-4h]

  if ( (a2->m_wParam & 0x10) != 0 || this->m_iSpellDestination == -1 )
  {
    CInputProcessor::SendTo(this, a2);
    return 1;
  }
  else
  {
    m_lParam_low = LOWORD(a2->m_lParam);
    m_lParam_high = HIWORD(a2->m_lParam);
    iPriestId = 0;
    v11 = -1;
    for ( i = 0; i < std::vector<unsigned short>::size(&CInputProcessor::m_vSelection); ++i )
    {
      v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, i);
      v16 = CMapObjectMgr::MovingEntity(*v3);
      if ( IEntity::ObjType(v16) == SETTLER_OBJ && IEntity::Type(v16) == 45 )
      {
        v6 = m_lParam_high - IEntity::Y(v16);
        v4 = IEntity::X(v16);
        v13 = Grid::Distance(m_lParam_low - v4, v6);
        if ( v13 < v11 )
        {
          v11 = v13;
          iPriestId = IEntity::ID(v16);
        }
      }
    }
    if ( !iPriestId && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 2357, "iPriestId != 0") == 1 )
      __debugbreak();
    if ( !iPriestId )
      return 1;
    v7 = ((unsigned __int16)iPriestId << 16) | LOWORD(this->m_iSpellDestination);
    v8 = Y16X16::PackXYFast(m_lParam_low, m_lParam_high);
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    CEvn_Logic::CEvn_Logic(&v17, 0x13B8u, v7, v8, LocalPlayerId, 0, 0);
    v18 = 0;
    if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 2371, "g_pNetworkEngine != NULL") == 1 )
      __debugbreak();
    if ( g_pNetworkEngine )
      INetworkEngine::SendNetMessage(g_pNetworkEngine, &v17);
    v18 = -1;
    CEvn_Logic::~CEvn_Logic(&v17);
    return 1;
  }
}


// address=[0x1458770]
// Decompiled from char __thiscall CInputProcessor::InitSettlerAmount(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitSettlerAmount(class CEvn_Logic * a2) {
  
  CSettlerMgr::FillSettlerAmount(&g_cSettlerStatisticInfo, 0, this->m_bIsLocal);
  CLogic::SetFillDialogInfos(g_pLogic, CSettlerMgr::FillSettlerAmount, &g_cSettlerStatisticInfo, this->m_bIsLocal);
  return 0;
}


// address=[0x14587c0]
// Decompiled from char __thiscall CInputProcessor::InitFreeCarrier(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitFreeCarrier(class CEvn_Logic * a2) {
  
  CSettlerMgr::FillFreeCarrier((void **)&g_cFreeCarrierInfo.__vftable, 0);
  CLogic::SetFillDialogInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, bool))CSettlerMgr::FillFreeCarrier,
    &g_cFreeCarrierInfo,
    this->m_bIsLocal);
  return 0;
}


// address=[0x1458810]
// Decompiled from char __thiscall CInputProcessor::InitSettlerProduction(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitSettlerProduction(class CEvn_Logic * a2) {
  
  CSettlerMgr::FillSpecialistProduction(&g_cSettlerProductionInfo, 0, this->m_bIsLocal);
  CLogic::SetFillDialogInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, bool))CSettlerMgr::FillSpecialistProduction,
    &g_cSettlerProductionInfo,
    this->m_bIsLocal);
  return 0;
}


// address=[0x1458860]
// Decompiled from char __thiscall CInputProcessor::InitSettlerSearch(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitSettlerSearch(class CEvn_Logic * a2) {
  
  CEvn_Event v3; // [esp+Ch] [ebp-28h] BYREF
  int v4; // [esp+30h] [ebp-4h]

  CEvn_Event::CEvn_Event(&v3, 0x278u, 0, 0, 0);
  v4 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1282, "g_pEvnEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v3);
  v4 = -1;
  CEvn_Event::~CEvn_Event(&v3);
  return 0;
}


// address=[0x1458920]
// Decompiled from char __thiscall CInputProcessor::InitGoodAmount(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitGoodAmount(class CEvn_Logic * a2) {
  
  CEcoSectorMgr::FillGoodAmount(&g_cGoodsStatisticInfo, 0, this->m_bIsLocal);
  CLogic::SetFillDialogInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, bool))CEcoSectorMgr::FillGoodAmount,
    &g_cGoodsStatisticInfo,
    this->m_bIsLocal);
  return 0;
}


// address=[0x1458970]
// Decompiled from char __thiscall CInputProcessor::InitTransportPrio(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitTransportPrio(class CEvn_Logic * a2) {
  
  CEcoSectorMgr::FillTransportPrio(&g_cTransportpriorityInfo, 0);
  CLogic::SetFillDialogInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, bool))CEcoSectorMgr::FillTransportPrio,
    &g_cTransportpriorityInfo,
    this->m_bIsLocal);
  return 0;
}


// address=[0x14589c0]
// Decompiled from char __thiscall CInputProcessor::InitGoodDistribution(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitGoodDistribution(class CEvn_Logic * a2) {
  
  g_cGoodDistributionInfo.m_uU5 = a2->m_wParam;
  CEcoSectorMgr::FillGoodDistribution(&g_cGoodDistributionInfo, 0, this->m_bIsLocal);
  CLogic::SetFillDialogInfos(g_pLogic, CEcoSectorMgr::FillGoodDistribution, &g_cGoodDistributionInfo, this->m_bIsLocal);
  return 0;
}


// address=[0x1458a10]
// Decompiled from char __thiscall CInputProcessor::GoodDeliveringChanged(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::GoodDeliveringChanged(class CEvn_Logic * a2) {
  
  uchar LocalPlayerId; // al
  uint v4; // [esp+10h] [ebp-B4h]
  uint v5; // [esp+14h] [ebp-B0h]
  CEcoSector *v6; // [esp+24h] [ebp-A0h]
  DWORD m_uU5; // [esp+2Ch] [ebp-98h]
  int sum; // [esp+30h] [ebp-94h]
  int UserESInMiddleOfTheScreen; // [esp+34h] [ebp-90h]
  int v10; // [esp+38h] [ebp-8Ch]
  _DWORD *v11; // [esp+3Ch] [ebp-88h]
  int v12; // [esp+40h] [ebp-84h]
  _DWORD *v13; // [esp+44h] [ebp-80h]
  int v14; // [esp+48h] [ebp-7Ch]
  int i; // [esp+4Ch] [ebp-78h]
  int j; // [esp+4Ch] [ebp-78h]
  CGoodDistributionInfo v17; // [esp+50h] [ebp-74h] BYREF
  CEvn_Logic v18; // [esp+94h] [ebp-30h] BYREF
  int v19; // [esp+C0h] [ebp-4h]

  m_uU5 = g_cGoodDistributionInfo.m_uU5;
  UserESInMiddleOfTheScreen = CInputProcessor::GetUserESInMiddleOfTheScreen(this);
  sum = 0;
  if ( UserESInMiddleOfTheScreen )
  {
    v6 = (CEcoSector *)CEcoSectorMgr::operator[](g_cESMgr, UserESInMiddleOfTheScreen);
    CGoodDistributionInfo::CGoodDistributionInfo(&v17);
    v17.m_uU5 = m_uU5;
    CEcoSector::FillGoodDistribution(v6, &v17);
    v11 = operator new[](4 * g_cGoodDistributionInfo.m_uSupplyBuildings);
    v13 = operator new[](4 * g_cGoodDistributionInfo.m_uSupplyBuildings);
    v10 = 0;
    for ( i = 0; i < g_cGoodDistributionInfo.m_uSupplyBuildings; ++i )
    {
      v13[i] = g_cGoodDistributionInfo.m_aSupplyPriorities[i].m_uPriority - v17.m_aSupplyPriorities[i].m_uPriority;
      v11[i] = v13[i] + v17.m_aSupplyPriorities[i].m_uPriority;
      v10 += v11[i];
    }
    v12 = 100 - v10;
    v14 = 0;
    while ( v12 )
    {
      if ( v11[v14] )
      {
        v13[v14] += sign(v12);
        v12 -= sign(v12);
      }
      if ( ++v14 >= g_cGoodDistributionInfo.m_uSupplyBuildings )
        v14 = 0;
    }
    for ( j = 0; j < g_cGoodDistributionInfo.m_uSupplyBuildings; ++j )
    {
      v4 = (unsigned __int16)g_cGoodDistributionInfo.m_aSupplyPriorities[j].m_uBuildingId | ((unsigned __int16)m_uU5 << 16);
      v5 = LOWORD(v13[j]) | ((unsigned __int16)UserESInMiddleOfTheScreen << 16);
      sum += v13[j] + v17.m_aSupplyPriorities[j].m_uPriority;
      LocalPlayerId = CPlayerManager::GetLocalPlayerId();
      CEvn_Logic::CEvn_Logic(&v18, 5028u, v4, v5, LocalPlayerId, 0, 0);
      v19 = 0;
      if ( !g_pNetworkEngine
        && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 2685, "g_pNetworkEngine != NULL") == 1 )
      {
        __debugbreak();
      }
      if ( g_pNetworkEngine )
        INetworkEngine::SendNetMessage(g_pNetworkEngine, &v18);
      v19 = -1;
      CEvn_Logic::~CEvn_Logic(&v18);
    }
    operator delete[](v11);
    operator delete[](v13);
  }
  BBSupportTracePrintF(3, "sum = %d", sum);
  return 0;
}


// address=[0x1458d90]
// Decompiled from char __thiscall CInputProcessor::TransportPrioChanged(CInputProcessor *this, struct CEvn_Logic *_pEvent)
bool  CInputProcessor::TransportPrioChanged(class CEvn_Logic * _pEvent) {
  
  uchar LocalPlayerId; // al
  uint v4; // [esp+8h] [ebp-40h]
  int UserESInMiddleOfTheScreen; // [esp+14h] [ebp-34h]
  CEvn_Logic v7; // [esp+18h] [ebp-30h] BYREF
  int v8; // [esp+44h] [ebp-4h]

  if ( !_pEvent && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 2581, "_pEvent != NULL") == 1 )
    __debugbreak();
  if ( !_pEvent )
    return 0;
  UserESInMiddleOfTheScreen = CInputProcessor::GetUserESInMiddleOfTheScreen(this);
  if ( !UserESInMiddleOfTheScreen )
    return 0;
  CEcoSectorMgr::operator[](g_cESMgr, UserESInMiddleOfTheScreen);
  v4 = (LOWORD(_pEvent->m_wParam) << 16) | LOWORD(_pEvent->m_lParam);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CEvn_Logic::CEvn_Logic(&v7, 0x13A5u, v4, UserESInMiddleOfTheScreen, LocalPlayerId, 0, 0);
  v8 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 2599, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v7);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(&v7);
  return 0;
}


// address=[0x1458ec0]
// Decompiled from char __thiscall CInputProcessor::UnitProduction(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::UnitProduction(class CEvn_Logic * a2) {
  
  int m_wParam_low; // esi
  uchar LocalPlayerId; // al
  uint v5; // [esp+Ch] [ebp-38h]
  CEvn_Logic v6; // [esp+14h] [ebp-30h] BYREF
  int v7; // [esp+40h] [ebp-4h]

  m_wParam_low = LOWORD(a2->m_wParam);
  v5 = (*std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0) << 16) | m_wParam_low;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CEvn_Logic::CEvn_Logic(&v6, 0x13B7u, v5, a2->m_lParam, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1516, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v6);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(&v6);
  return 0;
}


// address=[0x1458fb0]
// Decompiled from char __thiscall CInputProcessor::UrgentProduction(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::UrgentProduction(class CEvn_Logic * a2) {
  
  int m_wParam_low; // esi
  uchar LocalPlayerId; // al
  uint v5; // [esp+Ch] [ebp-38h]
  CEvn_Logic v6; // [esp+14h] [ebp-30h] BYREF
  int v7; // [esp+40h] [ebp-4h]

  m_wParam_low = LOWORD(a2->m_wParam);
  v5 = (*std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0) << 16) | m_wParam_low;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CEvn_Logic::CEvn_Logic(&v6, 0x13A9u, v5, a2->m_lParam, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1484, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v6);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(&v6);
  return 0;
}


// address=[0x14590a0]
// Decompiled from char __thiscall CInputProcessor::WeaponPercent(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::WeaponPercent(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  uint m_wParam; // [esp-10h] [ebp-4Ch]
  uchar LocalPlayerId; // [esp-Ch] [ebp-48h]
  CEvn_Logic v6; // [esp+Ch] [ebp-30h] BYREF
  int v7; // [esp+38h] [ebp-4h]

  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  m_wParam = a2->m_wParam;
  v2 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic(&v6, 0x13AAu, *v2, m_wParam, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1428, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v6);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(&v6);
  return 0;
}


// address=[0x1459180]
// Decompiled from char __thiscall CInputProcessor::WeaponAutoproduction(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::WeaponAutoproduction(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  uint m_lParam; // [esp-10h] [ebp-4Ch]
  uchar LocalPlayerId; // [esp-Ch] [ebp-48h]
  CEvn_Logic v6; // [esp+Ch] [ebp-30h] BYREF
  int v7; // [esp+38h] [ebp-4h]

  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  m_lParam = a2->m_lParam;
  v2 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic(&v6, 0x13ABu, *v2, m_lParam, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1454, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v6);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(&v6);
  return 0;
}


// address=[0x1459260]
// Decompiled from char __thiscall CInputProcessor::StorageGoodSwitch(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::StorageGoodSwitch(class CEvn_Logic * a2) {
  
  int m_wParam_low; // esi
  uchar LocalPlayerId; // al
  uint v5; // [esp+Ch] [ebp-38h]
  CEvn_Logic v6; // [esp+14h] [ebp-30h] BYREF
  int v7; // [esp+40h] [ebp-4h]

  m_wParam_low = LOWORD(a2->m_wParam);
  v5 = (*std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0) << 16) | m_wParam_low;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CEvn_Logic::CEvn_Logic(&v6, 0x13B4u, v5, a2->m_lParam, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1404, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v6);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(&v6);
  return 0;
}


// address=[0x1459350]
// Decompiled from char __thiscall CInputProcessor::VehicleProduction(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::VehicleProduction(class CEvn_Logic * a2) {
  
  int m_wParam_low; // esi
  uchar LocalPlayerId; // al
  uint v5; // [esp+Ch] [ebp-38h]
  CEvn_Logic v6; // [esp+14h] [ebp-30h] BYREF
  int v7; // [esp+40h] [ebp-4h]

  m_wParam_low = LOWORD(a2->m_wParam);
  v5 = (*std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0) << 16) | m_wParam_low;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CEvn_Logic::CEvn_Logic(&v6, 0x13B0u, v5, a2->m_lParam, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1373, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v6);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(&v6);
  return 0;
}


// address=[0x1459440]
// Decompiled from char __thiscall CInputProcessor::GotoVehicleGroupMenu(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::GotoVehicleGroupMenu(class CEvn_Logic * a2) {
  
  CEvn_Event v4; // [esp+Ch] [ebp-28h] BYREF
  int v5; // [esp+30h] [ebp-4h]

  CEvn_Event::CEvn_Event(&v4, 0x260u, 0, 0, 0);
  v5 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3578, "g_pEvnEngine!= NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v4);
  CLogic::SetFillDialogInfos(g_pLogic, 0, 0, 0);
  CVehicleMgr::FillVehicleGroupMenu((struct CInfoExchange *)&g_cVehicleInfo, 0);
  CLogic::SetFillDialogInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, bool))CVehicleMgr::FillVehicleGroupMenu,
    (struct CInfoExchange *)&g_cVehicleInfo,
    this->m_bIsLocal);
  v5 = -1;
  CEvn_Event::~CEvn_Event(&v4);
  return 0;
}


// address=[0x1459540]
// Decompiled from char __thiscall CInputProcessor::SwitchLocalGlobal(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SwitchLocalGlobal(class CEvn_Logic * a2) {
  
  this->m_bIsLocal = this->m_bIsLocal == 0;
  CLogic::SetLocalGlobalSwitch(g_pLogic, this->m_bIsLocal);
  return 0;
}


// address=[0x1459590]
// Decompiled from char __thiscall CInputProcessor::SpecialistProduction(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SpecialistProduction(class CEvn_Logic * a2) {
  
  uchar LocalPlayerId; // al
  uint v4; // [esp+4h] [ebp-40h]
  int UserESInMiddleOfTheScreen; // [esp+Ch] [ebp-38h]
  CEvn_Logic v6; // [esp+14h] [ebp-30h] BYREF
  int v7; // [esp+40h] [ebp-4h]

  UserESInMiddleOfTheScreen = CInputProcessor::GetUserESInMiddleOfTheScreen(this);
  if ( !UserESInMiddleOfTheScreen )
    return 0;
  v4 = ((unsigned __int16)UserESInMiddleOfTheScreen << 16) | LOWORD(a2->m_wParam);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CEvn_Logic::CEvn_Logic(&v6, 0x13AFu, v4, a2->m_lParam, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1549, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v6);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(&v6);
  return 0;
}


// address=[0x1459690]
// Decompiled from char __thiscall CInputProcessor::PrepareBoxSelection(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::PrepareBoxSelection(class CEvn_Logic * a2) {
  
  int *xLeft; // eax
  int *xRight; // eax
  int *yTop; // eax
  int *yBottom; // eax
  struct CEvn_Event *v7; // [esp+4h] [ebp-54h]
  DWORD SelectionTypeOfCurrentSelection; // [esp+Ch] [ebp-4Ch]
  int yStart; // [esp+10h] [ebp-48h] BYREF
  int yEnd; // [esp+14h] [ebp-44h] BYREF
  int xStart; // [esp+18h] [ebp-40h] BYREF
  int xEnd; // [esp+1Ch] [ebp-3Ch] BYREF
  int v13; // [esp+20h] [ebp-38h]
  int packedXY; // [esp+24h] [ebp-34h]
  bool v16; // [esp+2Bh] [ebp-2Dh] MAPDST
  CEvn_Event v18; // [esp+30h] [ebp-28h] BYREF
  int v19; // [esp+54h] [ebp-4h]

  CInputProcessor::TidyUp(this);
  v16 = a2->m_wParam < 0;
  packedXY = a2->m_lParam;
  v13 = a2->m_wParam & 0x7FFFFFFF;
  xStart = Y16X16::UnpackXFast(packedXY);
  yStart = Y16X16::UnpackYFast(packedXY);
  xEnd = Y16X16::UnpackXFast(v13);
  yEnd = Y16X16::UnpackYFast(v13);
  xLeft = BB::Min<int>(&xStart, &xEnd);
  this->m_iSelectionXStart = *xLeft;
  xRight = BB::Max<int>(&xStart, &xEnd);
  this->m_iSelectionXEnd = *xRight;
  yTop = BB::Min<int>(&yStart, &yEnd);
  this->m_iSelectionYStart = *yTop;
  yBottom = BB::Max<int>(&yStart, &yEnd);
  this->m_iSelectionYEnd = *yBottom;
  this->m_iSelectionMode = 1;
  this->m_iSelectionLocalPlayerId = CPlayerManager::GetLocalPlayerId();
  SelectionTypeOfCurrentSelection = CInputProcessor::GetSelectionTypeOfCurrentSelection(this);
  if ( v16 && SelectionTypeOfCurrentSelection )
  {
    this->m_iSelectionType = SelectionTypeOfCurrentSelection;
    this->m_iSelectionStrict = 1;
  }
  else
  {
    CInputProcessor::DeSelectAll(this);
    this->m_iSelectionType = 0;
    this->m_iSelectionStrict = 0;
  }
  if ( !g_pEvnEngine )
    return 1;
  v7 = CEvn_Event::CEvn_Event(&v18, 0x259u, 0, 0, 0);
  v19 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, v7);
  v19 = -1;
  CEvn_Event::~CEvn_Event(&v18);
  return 1;
}


// address=[0x1459860]
// Decompiled from char __thiscall CInputProcessor::DotSelection(CInputProcessor *this, CEvn_Logic *a2)
bool  CInputProcessor::DotSelection(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  struct IEntity *v3; // eax
  struct IEntity *v4; // eax
  int v5; // eax
  unsigned __int16 *v6; // eax
  struct CEvn_Event *v8; // [esp+4h] [ebp-68h]
  IEntity *BuildingPtr; // [esp+Ch] [ebp-60h]
  int v10; // [esp+10h] [ebp-5Ch]
  int x; // [esp+14h] [ebp-58h]
  int y; // [esp+18h] [ebp-54h]
  bool v13; // [esp+20h] [ebp-4Ch]
  IEntity *entity; // [esp+24h] [ebp-48h] MAPDST
  __int16 v15; // [esp+2Ah] [ebp-42h] BYREF
  int EntitySelectionType; // [esp+2Ch] [ebp-40h]
  int foundEntityId; // [esp+30h] [ebp-3Ch]
  char v21; // [esp+3Fh] [ebp-2Dh]
  bool v22; // [esp+40h] [ebp-2Ch] MAPDST
  bool appendToSelection; // [esp+41h] [ebp-2Bh] MAPDST
  char v25; // [esp+43h] [ebp-29h]
  CEvn_Event v26; // [esp+44h] [ebp-28h] BYREF
  int v27; // [esp+68h] [ebp-4h]

  x = Y16X16::UnpackXFast(a2->m_lParam);
  y = Y16X16::UnpackYFast(a2->m_lParam);
  appendToSelection = (a2->m_wParam & 8) != 0;
  foundEntityId = CInputProcessor::SelectOne(this, x, y);
  if ( foundEntityId <= 0 )
    entity = 0;
  else
    entity = CMapObjectMgr::EntityPtr(foundEntityId);
  if ( entity )
  {
    CLogic::SetFillDialogInfos(g_pLogic, 0, 0, 0);
    v22 = IEntity::FlagBits(entity, (EntityFlag)0x4000) != 0;
    v21 = 1;
    v25 = 1;
    if ( appendToSelection && !v22 )
    {
      EntitySelectionType = 0;
      if ( std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
      {
        v2 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
        v3 = CMapObjectMgr::EntityPtr(*v2);
        EntitySelectionType = CInputProcessor::GetEntitySelectionType(v3);
      }
      v4 = CMapObjectMgr::EntityPtr(foundEntityId);
      v10 = CInputProcessor::GetEntitySelectionType(v4);
      v13 = !EntitySelectionType || EntitySelectionType == 0x10000 || EntitySelectionType != v10;
      v25 = v13;
      if ( !v13 && IEntity::FlagBits(entity, EntityFlag_Selected) )
      {
        v21 = 0;
        CInputProcessor::DeSelectEntity(this, foundEntityId);
      }
    }
    if ( v25 )
      CInputProcessor::DeSelectAll(this);
    if ( v21 && (unsigned int)std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) < 0x64 )
    {
      v15 = foundEntityId;
      std::vector<unsigned short>::push_back(&CInputProcessor::m_vSelection, &v15);
      if ( v22 )
      {
        IEntity::SetFlagBits(entity, (EntityFlag)1024);
      }
      else
      {
        IEntity::SetFlagBits(entity, EntityFlag_Selected);
        if ( IEntity::ObjType(entity) == BUILDING_OBJ )// == Building
        {
          CSoundManager::PlaySoundFX(g_pSoundManager, 7);
          v5 = std::vector<unsigned short>::size(&CInputProcessor::m_vSelection);
          v6 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, v5 - 1);
          BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *v6);
          CBuilding::NotifySelected(BuildingPtr);
        }
      }
    }
    CInputProcessor::RequestDialog(this);
  }
  else if ( !appendToSelection )
  {
    CLogic::SetFillDialogInfos(g_pLogic, 0, 0, 0);
    CInputProcessor::DeSelectAll(this);
    CFsm::GenerateEvent(this->m_pFSM, 401, 0);
    if ( g_pEvnEngine )
    {
      v8 = CEvn_Event::CEvn_Event(&v26, 603u, 0, 0, 0);
      v27 = 0;
      IEventEngine::SendAMessage(g_pEvnEngine, v8);
      v27 = -1;
      CEvn_Event::~CEvn_Event(&v26);
    }
  }
  return 1;
}


// address=[0x1459b70]
// Decompiled from char __thiscall CInputProcessor::SelectTypeInSurrounding(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SelectTypeInSurrounding(class CEvn_Logic * a2) {
  
  int v2; // eax
  int v4; // [esp-4h] [ebp-18h]
  int x; // [esp+0h] [ebp-14h]
  unsigned int y; // [esp+4h] [ebp-10h]
  struct IEntity *v7; // [esp+8h] [ebp-Ch]
  int v8; // [esp+Ch] [ebp-8h]

  x = LOWORD(a2->m_lParam);
  y = HIWORD(a2->m_lParam);
  CInputProcessor::DeSelectAll(this);
  if ( !this->unk_C )
  {
    v8 = CInputProcessor::SelectOne(this, x, y);
    if ( v8 )
    {
      this->m_iSelectionType = CInputProcessor::GetEntitySelectionType(v8);
      this->m_iSelectionStrict = 2;
      v7 = CMapObjectMgr::Entity(v8);
      v4 = IEntity::Y(v7);
      v2 = IEntity::X(v7);
      dword_3F1F60C = CWorldManager::SectorId(v2, v4);
      dword_3F1F608 = a2->m_wParam & 0x10;
      CInputProcessor::SelectAllInSurrounding(this, x, y);
    }
  }
  CLogic::SetFillDialogInfos(g_pLogic, 0, 0, 0);
  CInputProcessor::RequestDialog(this);
  return 1;
}


// address=[0x1459c50]
// Decompiled from char __thiscall CInputProcessor::SelectGroup(CInputProcessor *this, struct CEvn_Logic *_pEvent)
bool  CInputProcessor::SelectGroup(class CEvn_Logic * _pEvent) {
  
  int SelectionTypeOfCurrentSelection; // [esp+4h] [ebp-30h]
  int m_lParam; // [esp+8h] [ebp-2Ch]
  int v5; // [esp+Ch] [ebp-28h]
  IEntity *v6; // [esp+10h] [ebp-24h]
  unsigned __int16 *v7; // [esp+14h] [ebp-20h]
  int v8; // [esp+18h] [ebp-1Ch]
  int LocalPlayerId; // [esp+20h] [ebp-14h]
  int i; // [esp+28h] [ebp-Ch]
  int m_wParam; // [esp+2Ch] [ebp-8h]
  __int16 v13; // [esp+30h] [ebp-4h] BYREF
  bool v14; // [esp+33h] [ebp-1h]

  if ( !_pEvent && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3203, "_pEvent!=0") == 1 )
    __debugbreak();
  m_wParam = _pEvent->m_wParam;
  m_lParam = _pEvent->m_lParam;
  if ( m_wParam < 1 || m_wParam > 10 )
    return 0;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  v8 = g_pGroupMgr->GetGroupSize(g_pGroupMgr, LocalPlayerId, m_wParam);
  if ( v8 <= 0 )
    return 0;
  this->unk_18 = m_wParam;
  v7 = g_pGroupMgr->GetGroupEntityIds(g_pGroupMgr, LocalPlayerId, m_wParam);
  v14 = 1;
  if ( m_lParam )
  {
    SelectionTypeOfCurrentSelection = CInputProcessor::GetSelectionTypeOfCurrentSelection(this);
    v14 = SelectionTypeOfCurrentSelection != CInputProcessor::GetEntitySelectionType(*v7);
  }
  if ( v14 )
    CInputProcessor::DeSelectAll(this);
  for ( i = 0; i < v8 && (unsigned int)std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) < 0x64; ++i )
  {
    v5 = v7[i];
    v6 = CMapObjectMgr::Entity(v5);
    if ( IEntity::FlagBits(v6, EntityFlag_Selectable) )
    {
      IEntity::SetFlagBits(v6, EntityFlag_Selected);
      v13 = v5;
      std::vector<unsigned short>::push_back(&CInputProcessor::m_vSelection, &v13);
    }
  }
  CInputProcessor::RequestDialog(this);
  return 0;
}


// address=[0x1459df0]
// Decompiled from char __stdcall CInputProcessor::GroupToSelection(int a1)
bool  CInputProcessor::GroupToSelection(class CEvn_Logic * a1) {
  
  return 0;
}


// address=[0x1459e00]
// Decompiled from char __thiscall CInputProcessor::DefineGroup(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::DefineGroup(class CEvn_Logic * a2) {
  
  uchar LocalPlayerId; // al
  _WORD *v4; // [esp+Ch] [ebp-44h]
  signed int iGroupId; // [esp+10h] [ebp-40h]
  signed int i; // [esp+14h] [ebp-3Ch]
  int iSelectionSize; // [esp+18h] [ebp-38h]
  CEvn_Logic v8; // [esp+20h] [ebp-30h] BYREF
  int v9; // [esp+4Ch] [ebp-4h]

  iGroupId = a2->m_wParam;
  if ( (iGroupId < 1 || iGroupId > 10)
    && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3088, "(iGroupId >= GROUP_FIRST) && (iGroupId <= GROUP_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( iGroupId < 1 || iGroupId > 10 )
    return 0;
  iSelectionSize = std::vector<unsigned short>::size(&CInputProcessor::m_vSelection);
  if ( iSelectionSize <= 0 )
    return 0;
  if ( iSelectionSize > 100
    && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3102, "iSelectionSize <= MAX_SELECTED_ENTITIES") == 1 )
  {
    __debugbreak();
  }
  if ( iSelectionSize > 100 )
    iSelectionSize = 100;
  v4 = operator new[](2 * iSelectionSize);
  for ( i = 0; i < iSelectionSize; ++i )
    v4[i] = *std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, i);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CEvn_Logic::CEvn_Logic(&v8, 0x13B1u, iGroupId, 0, LocalPlayerId, (uint)v4, (unsigned __int8)(2 * iSelectionSize));
  v9 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3131, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v8);
  v9 = -1;
  CEvn_Logic::~CEvn_Logic(&v8);
  return 0;
}


// address=[0x1459fd0]
// Decompiled from char __thiscall CInputProcessor::FocusGroup(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::FocusGroup(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  IEntity *v3; // eax
  unsigned __int16 *v4; // eax
  int v5; // esi
  IMovingEntity *v7; // [esp+10h] [ebp-3Ch]
  int v8; // [esp+14h] [ebp-38h]
  int v9; // [esp+18h] [ebp-34h]
  int v10; // [esp+1Ch] [ebp-30h]
  unsigned int i; // [esp+20h] [ebp-2Ch]
  CEvn_Event v12; // [esp+24h] [ebp-28h] BYREF
  int v13; // [esp+48h] [ebp-4h]

  if ( a2->m_wParam > 10u
    && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3149, "iGroupId >= 0 && iGroupId <= MAX_GROUPS") == 1 )
  {
    __debugbreak();
  }
  if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    return 0;
  v9 = 0;
  v8 = 0;
  v10 = 0;
  for ( i = 0; i < std::vector<unsigned short>::size(&CInputProcessor::m_vSelection); ++i )
  {
    v2 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, i);
    v3 = CMapObjectMgr::EntityPtr(*v2);
    if ( IEntity::ObjType(v3) != BUILDING_OBJ )
    {
      v4 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, i);
      v7 = CMapObjectMgr::MovingEntity(*v4);
      v5 = IEntity::OwnerId(v7);
      if ( v5 == CPlayerManager::GetLocalPlayerId() )
      {
        v9 += IEntity::X(v7);
        v8 += IEntity::Y(v7);
        ++v10;
      }
    }
  }
  if ( !v10 )
    return 0;
  CEvn_Event::CEvn_Event(&v12, 0x13u, v8 / v10, v9 / v10, 0);
  v13 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3184, "g_pEvnEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v12);
  v13 = -1;
  CEvn_Event::~CEvn_Event(&v12);
  return 0;
}


// address=[0x145a1a0]
// Decompiled from char __thiscall CInputProcessor::SendTo(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SendTo(class CEvn_Logic * a2) {
  
  unsigned __int16 *v3; // eax
  IEntity *v4; // eax
  unsigned __int16 *v5; // eax
  IEntity *v6; // eax
  uchar LocalPlayerId; // [esp+4h] [ebp-60h]
  uint v8; // [esp+10h] [ebp-54h]
  _WORD *v9; // [esp+14h] [ebp-50h]
  int v11; // [esp+1Ch] [ebp-48h]
  int v12; // [esp+20h] [ebp-44h]
  int m_lParam; // [esp+28h] [ebp-3Ch]
  signed int i; // [esp+2Ch] [ebp-38h]
  int iSelectionSize; // [esp+30h] [ebp-34h]
  CEvn_Logic v16; // [esp+34h] [ebp-30h] BYREF
  int v17; // [esp+60h] [ebp-4h]

  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  m_lParam = a2->m_lParam;
  if ( (a2->m_wParam & 4) != 0 )
    v12 = 2;
  else
    v12 = 0;
  if ( (a2->m_wParam & 0x10) != 0 )
    v11 = 4;
  else
    v11 = 0;
  v8 = v11 | v12 | ((a2->m_wParam & 8) != 0);
  if ( m_lParam >= 0 )
  {
    if ( !m_lParam || !CWorldManager::InWorldPackedXY(m_lParam) )
      return 1;
  }
  else
  {
    v8 = 8;
  }
  iSelectionSize = std::vector<unsigned short>::size(&CInputProcessor::m_vSelection);
  if ( iSelectionSize <= 0 )
    return 1;
  v3 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  v4 = CMapObjectMgr::EntityPtr(*v3);
  if ( IEntity::ObjType(v4) == BUILDING_OBJ
    || (v5 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0),
        v6 = CMapObjectMgr::EntityPtr(*v5),
        IEntity::FlagBits(v6, (EntityFlag)0x4000)) )
  {
    CInputProcessor::Clear(this);
    return 0;
  }
  if ( iSelectionSize > MAX_SELECTED_ENTITIES
    && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3352, "iSelectionSize <= MAX_SELECTED_ENTITIES") == 1 )
  {
    __debugbreak();
  }
  if ( iSelectionSize > MAX_SELECTED_ENTITIES )
    iSelectionSize = MAX_SELECTED_ENTITIES;
  v9 = operator new[](2 * iSelectionSize);
  for ( i = 0; i < iSelectionSize; ++i )
    v9[i] = *std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, i);
  if ( g_pNetworkEngine )
  {
    CEvn_Logic::CEvn_Logic(&v16, 0x1396u, m_lParam, v8, LocalPlayerId, (uint)v9, 2 * iSelectionSize);
    v17 = 0;
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v16);
    v17 = -1;
    CEvn_Logic::~CEvn_Logic(&v16);
  }
  CSoundManager::PlaySoundFX(g_pSoundManager, 10);
  return 1;
}


// address=[0x145a410]
// Decompiled from char __thiscall CInputProcessor::ForceGoto(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::ForceGoto(class CEvn_Logic * a2) {
  
  return 0;
}


// address=[0x145a420]
// Decompiled from char __thiscall CInputProcessor::StandGround(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::StandGround(class CEvn_Logic * a2) {
  
  a2->m_lParam = -1;
  return CInputProcessor::SendTo(this, a2);
}


// address=[0x145a450]
// Decompiled from char __thiscall CInputProcessor::ChooseSecondPatrolPos(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::ChooseSecondPatrolPos(class CEvn_Logic * a2) {
  
  this->m_iViewState = 9;
  IGfxEngine::EnableIconLayer(g_pGfxEngine, 1);
  return 1;
}


// address=[0x145a480]
// Decompiled from char __thiscall CInputProcessor::SelectSecondPatrolPos(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SelectSecondPatrolPos(class CEvn_Logic * a2) {
  
  a2->m_wParam = 0;
  a2->m_wParam |= 8u;
  CInputProcessor::SendTo(this, a2);
  CInputProcessor::Default(this, a2);
  CFsm::GenerateEvent(this->m_pFSM, 401, 0);
  return 1;
}


// address=[0x145a4e0]
// Decompiled from char __thiscall CInputProcessor::InjuredOut(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InjuredOut(class CEvn_Logic * a2) {
  
  _DWORD v3[4]; // [esp-Ch] [ebp-88h] BYREF
  _BYTE v4[12]; // [esp+4h] [ebp-78h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-6Ch] BYREF
  _BYTE v6[12]; // [esp+1Ch] [ebp-60h] BYREF
  int v7; // [esp+28h] [ebp-54h]
  _DWORD *v8; // [esp+2Ch] [ebp-50h]
  int v10; // [esp+34h] [ebp-48h]
  int v11; // [esp+38h] [ebp-44h]
  int iHitpoints; // [esp+3Ch] [ebp-40h]
  int iMaxHealth; // [esp+40h] [ebp-3Ch]
  CSettlerMgr::SSettlerInfos *SettlerInfo; // [esp+44h] [ebp-38h]
  int v15; // [esp+48h] [ebp-34h]
  int v16; // [esp+4Ch] [ebp-30h]
  int v17; // [esp+50h] [ebp-2Ch]
  std::_Iterator_base12 *v18; // [esp+54h] [ebp-28h]
  std::_Iterator_base12 *v19; // [esp+58h] [ebp-24h]
  int m_iOwner; // [esp+5Ch] [ebp-20h]
  BOOL v21; // [esp+60h] [ebp-1Ch]
  IEntity *SettlerPtr; // [esp+64h] [ebp-18h]
  char v25; // [esp+6Ch] [ebp-10h]
  bool v26; // [esp+6Dh] [ebp-Fh]
  bool iIsInjuredFlag; // [esp+6Eh] [ebp-Eh] MAPDST
  bool v28; // [esp+6Fh] [ebp-Dh] MAPDST
  int v29; // [esp+78h] [ebp-4h]

  m_iOwner = a2->m_iOwner;
  v28 = a2->m_wParam != 0;
  if ( m_iOwner != CPlayerManager::GetLocalPlayerId()
    || !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
  {
    return 0;
  }
  std::vector<unsigned short>::begin(v6);
  v29 = 0;
  while ( 1 )
  {
    v19 = (std::_Iterator_base12 *)std::vector<unsigned short>::end(v5);
    v18 = v19;
    LOBYTE(v29) = 1;
    v25 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator!=(v19);
    LOBYTE(v29) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v5);
    if ( !v25 )
      break;
    v26 = 0;
    v17 = *(unsigned __int16 *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator*(v6);
    SettlerPtr = CSettlerMgr::GetSettlerPtr((struct CSettlerMgr *)g_cSettlerMgr, v17);
    if ( SettlerPtr )
    {
      v15 = IEntity::Race(SettlerPtr);
      v16 = IEntity::Type(SettlerPtr);
      SettlerInfo = CSettlerMgr::GetSettlerInfo(v15, v16);
      iMaxHealth = SettlerInfo->m_iMaxLifePoints;
      iHitpoints = IEntity::Hitpoints(SettlerPtr);
      iIsInjuredFlag = iHitpoints < iMaxHealth >> 1;
      v21 = iIsInjuredFlag == v28;
      v26 = iIsInjuredFlag == v28;
    }
    if ( v26 )
    {
      IEntity::ClearFlagBits(SettlerPtr, (EntityFlag)0x600);
      v8 = v3;
      v7 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>((struct std::_Iterator_base12 *)v6);
      v11 = std::vector<unsigned short>::erase(v4, v3[0], v3[1], v3[2]);
      v10 = v11;
      LOBYTE(v29) = 2;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator=(v11);
      LOBYTE(v29) = 0;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v4);
    }
    else
    {
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator++(v6);
    }
  }
  v29 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v6);
  return 0;
}


// address=[0x145a6e0]
// Decompiled from char __thiscall CInputProcessor::MorphToCarrier(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::MorphToCarrier(class CEvn_Logic * a2) {
  
  uchar LocalPlayerId; // al
  _WORD *v4; // [esp+Ch] [ebp-40h]
  int v5; // [esp+10h] [ebp-3Ch]
  unsigned int i; // [esp+14h] [ebp-38h]
  CEvn_Logic v7; // [esp+1Ch] [ebp-30h] BYREF
  int v8; // [esp+48h] [ebp-4h]

  v5 = std::vector<unsigned short>::size(&CInputProcessor::m_vSelection);
  if ( v5 <= 0 )
    return 0;
  if ( v5 > MAX_SELECTED_ENTITIES
    && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3533, "iSelectionSize <= MAX_SELECTED_ENTITIES") == 1 )
  {
    __debugbreak();
  }
  v4 = operator new[](2 * v5);
  for ( i = 0; i < std::vector<unsigned short>::size(&CInputProcessor::m_vSelection); ++i )
    v4[i] = *std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, i);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CEvn_Logic::CEvn_Logic(&v7, 0x139Du, 0, 0, LocalPlayerId, (uint)v4, (unsigned __int8)(2 * v5));
  v8 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3557, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v7);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(&v7);
  return 1;
}


// address=[0x145a860]
// Decompiled from char __thiscall CInputProcessor::SearchUnit(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SearchUnit(class CEvn_Logic * a2) {
  
  int LocalPlayerId; // eax
  unsigned __int16 *v4; // eax
  int v5; // eax
  int v6; // eax
  unsigned int iY; // eax
  int v8; // eax
  char v9; // bl
  char v10; // bl
  char v11; // bl
  char v12; // bl
  char v13; // bl
  char v14; // bl
  char v15; // bl
  char v16; // bl
  char v17; // bl
  char v18; // bl
  char v19; // bl
  char v20; // bl
  char v21; // bl
  char v22; // bl
  char v23; // bl
  char v24; // bl
  char v25; // bl
  char v26; // bl
  char v27; // bl
  unsigned __int16 *v28; // eax
  unsigned int v29; // eax
  unsigned int iX; // [esp-8h] [ebp-A0h]
  unsigned int v31; // [esp-8h] [ebp-A0h]
  struct CEvn_Event *v32; // [esp+8h] [ebp-90h]
  struct CEvn_Event *v33; // [esp+10h] [ebp-88h]
  IEntity *v34; // [esp+24h] [ebp-74h]
  unsigned int v35; // [esp+28h] [ebp-70h] BYREF
  unsigned int v36; // [esp+2Ch] [ebp-6Ch] BYREF
  IEntity *v37; // [esp+30h] [ebp-68h]
  int m_lParam; // [esp+34h] [ebp-64h]
  __int16 v39; // [esp+3Ah] [ebp-5Eh] BYREF
  int v40; // [esp+3Ch] [ebp-5Ch]
  CSettler *pSettler; // [esp+40h] [ebp-58h]
  int FirstSettlerId; // [esp+44h] [ebp-54h]
  int v43; // [esp+48h] [ebp-50h]
  S4_SETTLER_ENUM iSettlerType; // [esp+4Ch] [ebp-4Ch]
  char v46; // [esp+57h] [ebp-41h]
  CEvn_Event v47; // [esp+58h] [ebp-40h] BYREF
  CEvn_Event v48; // [esp+70h] [ebp-28h] BYREF
  int v49; // [esp+94h] [ebp-4h]

  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  if ( !CPlayerManager::IsAlive(LocalPlayerId) )
    return 0;
  iSettlerType = a2->m_wParam;
  if ( (iSettlerType <= SETTLER_NO_SETTLER || iSettlerType >= SETTLER_MAX)
    && BBSupportDbgReport(
         2,
         "Logic\\InputProcessor.cpp",
         2834,
         "iSettlerType > SETTLER_NO_SETTLER && iSettlerType < SETTLER_MAX") == 1 )
  {
    __debugbreak();
  }
  m_lParam = a2->m_lParam;
  if ( m_lParam )
  {
    if ( m_lParam == 1 )
    {
      CInputProcessor::DeSelectAll(this);
      this->m_bBoxSelectAllSettler = 1;
      this->m_iSelectionMode = 1;
      v8 = CSettlerMgr::SettlerWarriorType(iSettlerType);
      this->m_iSelectionType = CInputProcessor::GetEntitySelectionType(1, iSettlerType, v8);
      this->m_iSelectionStrict = 2;
      this->m_iSelectionLocalPlayerId = CPlayerManager::GetLocalPlayerId();
      this->m_iSelectionXStart = 1;
      this->m_iSelectionXEnd = IGfxEngine::GetOutputWidth(g_pGfxEngine);
      this->m_iSelectionYStart = 1;
      this->m_iSelectionYEnd = IGfxEngine::GetOutputHeight(g_pGfxEngine);
    }
    else if ( m_lParam == 2 )
    {
      CInputProcessor::DeSelectAll(this);
      v35 = 0;
      v36 = 0;
      CStateGame::GetCenterWorldCoordinate(g_pGame, (int *)&v35, (int *)&v36);
      v46 = 0;
      if ( CWorldManager::InWorld(v35, v36) )
      {
        v43 = CWorldManager::SectorId(v35, v36);
        if ( v43 > 0 )
        {
          v40 = iSettlerType - 29;
          switch ( iSettlerType )
          {
            case SETTLER_SWORDSMAN_01:
              v18 = v46;
              v46 = CInputProcessor::SelectAtSector(this, 29, v43) | v18;
              v19 = v46;
              v46 = CInputProcessor::SelectAtSector(this, 30, v43) | v19;
              v20 = v46;
              v46 = CInputProcessor::SelectAtSector(this, 31, v43) | v20;
              break;
            case SETTLER_BOWMAN_01:
              v21 = v46;
              v46 = CInputProcessor::SelectAtSector(this, 32, v43) | v21;
              v22 = v46;
              v46 = CInputProcessor::SelectAtSector(this, 33, v43) | v22;
              v23 = v46;
              v46 = CInputProcessor::SelectAtSector(this, 34, v43) | v23;
              break;
            case SETTLER_MEDIC_01:
              v15 = v46;
              v46 = CInputProcessor::SelectAtSector(this, 35, v43) | v15;
              v16 = v46;
              v46 = CInputProcessor::SelectAtSector(this, 36, v43) | v16;
              v17 = v46;
              v46 = CInputProcessor::SelectAtSector(this, 37, v43) | v17;
              break;
            case SETTLER_AXEWARRIOR_01:
              v9 = v46;
              v46 = CInputProcessor::SelectAtSector(this, 38, v43) | v9;
              v10 = v46;
              v46 = CInputProcessor::SelectAtSector(this, 39, v43) | v10;
              v11 = v46;
              v46 = CInputProcessor::SelectAtSector(this, 40, v43) | v11;
              break;
            case SETTLER_BLOWGUNWARRIOR_01:
              v12 = v46;
              v46 = CInputProcessor::SelectAtSector(this, 41, v43) | v12;
              v13 = v46;
              v46 = CInputProcessor::SelectAtSector(this, 42, v43) | v13;
              v14 = v46;
              v46 = CInputProcessor::SelectAtSector(this, 43, v43) | v14;
              break;
            case SETTLER_BACKPACKCATAPULTIST_01:
              v24 = v46;
              v46 = CInputProcessor::SelectAtSector(this, 61, v43) | v24;
              v25 = v46;
              v46 = CInputProcessor::SelectAtSector(this, 62, v43) | v25;
              v26 = v46;
              v46 = CInputProcessor::SelectAtSector(this, 63, v43) | v26;
              goto CInputProcessor__SearchUnit___def_185AC66;
            default:
CInputProcessor__SearchUnit___def_185AC66:
              v27 = v46;
              v46 = CInputProcessor::SelectAtSector(this, iSettlerType, v43) | v27;
              break;
          }
        }
      }
      if ( v46 )
      {
        v28 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
        v34 = CMapObjectMgr::EntityPtr(*v28);
        v31 = IEntity::X(v34);
        v29 = IEntity::Y(v34);
        v32 = CEvn_Event::CEvn_Event(&v47, 0x13u, v29, v31, 0);
        v49 = 1;
        IEventEngine::SendAMessage(g_pEvnEngine, v32);
        v49 = -1;
        CEvn_Event::~CEvn_Event(&v47);
      }
      else
      {
        CInputProcessor::Default(this, a2);
        CFsm::GenerateEvent(this->m_pFSM, 401, 0);
      }
    }
  }
  else
  {
    FirstSettlerId = 0;
    if ( std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) == 1 )
    {
      v4 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
      v37 = CMapObjectMgr::EntityPtr(*v4);
      if ( IEntity::ObjType(v37) == SETTLER_OBJ && IEntity::Type(v37) == iSettlerType )
        FirstSettlerId = IAnimatedEntity::Next(v37);
    }
    do
    {
      if ( !FirstSettlerId )
      {
        v5 = CPlayerManager::GetLocalPlayerId();
        FirstSettlerId = CSettlerMgr::GetFirstSettlerId((CSettlerMgr *)g_cSettlerMgr, v5, iSettlerType);
      }
      if ( !FirstSettlerId
        && (iSettlerType == SETTLER_SWORDSMAN_01
         || iSettlerType == SETTLER_SWORDSMAN_02
         || iSettlerType == SETTLER_BOWMAN_01
         || iSettlerType == SETTLER_BOWMAN_02
         || iSettlerType == SETTLER_MEDIC_01
         || iSettlerType == SETTLER_MEDIC_02
         || iSettlerType == SETTLER_AXEWARRIOR_01
         || iSettlerType == SETTLER_AXEWARRIOR_02
         || iSettlerType == SETTLER_BLOWGUNWARRIOR_01
         || iSettlerType == SETTLER_BLOWGUNWARRIOR_02) )
      {
        ++iSettlerType;
      }
      if ( !FirstSettlerId )
      {
        v6 = CPlayerManager::GetLocalPlayerId();
        FirstSettlerId = CSettlerMgr::GetFirstSettlerId((CSettlerMgr *)g_cSettlerMgr, v6, iSettlerType);
      }
    }
    while ( !FirstSettlerId
         && (iSettlerType == SETTLER_SWORDSMAN_01
          || iSettlerType == SETTLER_SWORDSMAN_02
          || iSettlerType == SETTLER_BOWMAN_01
          || iSettlerType == SETTLER_BOWMAN_02
          || iSettlerType == SETTLER_MEDIC_01
          || iSettlerType == SETTLER_MEDIC_02
          || iSettlerType == SETTLER_AXEWARRIOR_01
          || iSettlerType == SETTLER_AXEWARRIOR_02
          || iSettlerType == SETTLER_BLOWGUNWARRIOR_01
          || iSettlerType == SETTLER_BLOWGUNWARRIOR_02) );
    if ( FirstSettlerId > 0 )
    {
      CInputProcessor::DeSelectAll(this);
      pSettler = CSettlerMgr::GetSettlerPtr((struct CSettlerMgr *)g_cSettlerMgr, FirstSettlerId);
      if ( !pSettler && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 2908, "pSettler != NULL") == 1 )
        __debugbreak();
      if ( pSettler )
      {
        IEntity::SetFlagBits(pSettler, EntityFlag_Selected);
        v39 = FirstSettlerId;
        std::vector<unsigned short>::push_back(&CInputProcessor::m_vSelection, &v39);
        iX = IEntity::X(pSettler);
        iY = IEntity::Y(pSettler);
        v33 = CEvn_Event::CEvn_Event(&v48, 0x13u, iY, iX, 0);
        v49 = 0;
        IEventEngine::SendAMessage(g_pEvnEngine, v33);
        v49 = -1;
        CEvn_Event::~CEvn_Event(&v48);
        return 0;
      }
    }
    CInputProcessor::Default(this, a2);
    CFsm::GenerateEvent(this->m_pFSM, 401, 0);
  }
  return 0;
}


// address=[0x145af70]
// Decompiled from char __thiscall CInputProcessor::UnitReservation(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::UnitReservation(class CEvn_Logic * a2) {
  
  uchar LocalPlayerId; // al
  uint v4; // [esp+4h] [ebp-40h]
  int UserESInMiddleOfTheScreen; // [esp+Ch] [ebp-38h]
  CEvn_Logic v6; // [esp+14h] [ebp-30h] BYREF
  int v7; // [esp+40h] [ebp-4h]

  UserESInMiddleOfTheScreen = CInputProcessor::GetUserESInMiddleOfTheScreen(this);
  if ( !UserESInMiddleOfTheScreen )
    return 0;
  v4 = ((unsigned __int16)UserESInMiddleOfTheScreen << 16) | LOWORD(a2->m_wParam);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CEvn_Logic::CEvn_Logic(&v6, 0x13A3u, v4, a2->m_lParam, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 2767, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v6);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(&v6);
  return 0;
}


// address=[0x145b070]
// Decompiled from char __thiscall CInputProcessor::InitEconomyGameMenu(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitEconomyGameMenu(class CEvn_Logic * a2) {
  
  CStatistic::FillEconomyGameMenu(&g_cEconomyGameInfo, 0, 1);
  CLogic::SetFillDialogInfos(g_pLogic, CStatistic::FillEconomyGameMenu, &g_cEconomyGameInfo, 1);
  return 1;
}


// address=[0x145b0b0]
// Decompiled from char __thiscall CInputProcessor::InitMagicSideBar(CInputProcessor *this, CEvn_Logic *a2)
bool  CInputProcessor::InitMagicSideBar(class CEvn_Logic * a2) {
  
  this->m_iSpellDestination = -1;
  IGroupMgr::FillMagicSideBar(&g_cMagicSpellSideBarInfo, 0, 0);
  CLogic::SetFillSideBarInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, int))IGroupMgr::FillMagicSideBar,
    &g_cMagicSpellSideBarInfo,
    0);
  return 0;
}


// address=[0x145b100]
// Decompiled from char __thiscall CInputProcessor::InitGroupSideBar(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitGroupSideBar(class CEvn_Logic * a2) {
  
  IGroupMgr::FillGroupSideBar(&unk_3F1E75C, 0, 0);
  CLogic::SetFillSideBarInfos(g_pLogic, IGroupMgr::FillGroupSideBar, &unk_3F1E75C, 0);
  return 0;
}


// address=[0x145b140]
// Decompiled from char __thiscall CInputProcessor::InitAddSoldierSideBar(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitAddSoldierSideBar(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax

  v2 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CBuildingMgr::FillAddSoldierSideBar(&g_cAddSoldierSideBarInfo, 0, *v2);
  v3 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CLogic::SetFillSideBarInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, int))CBuildingMgr::FillAddSoldierSideBar,
    &g_cAddSoldierSideBarInfo,
    *v3);
  return 0;
}


// address=[0x145b1a0]
// Decompiled from char __thiscall CInputProcessor::InitToolSideBar(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitToolSideBar(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax

  v2 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CBuildingMgr::FillToolSideBar(&g_cAddToolSideBarInfo, 0, *v2);
  v3 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CLogic::SetFillSideBarInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, int))CBuildingMgr::FillToolSideBar,
    &g_cAddToolSideBarInfo,
    *v3);
  return 0;
}


// address=[0x145b200]
// Decompiled from char __thiscall CInputProcessor::InitWeaponSideBar(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitWeaponSideBar(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax

  v2 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CBuildingMgr::FillWeaponSideBar((int)&g_cWeaponSideBarInfo, 0, *v2);
  v3 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CLogic::SetFillSideBarInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, int))CBuildingMgr::FillWeaponSideBar,
    &g_cWeaponSideBarInfo,
    *v3);
  return 0;
}


// address=[0x145b260]
// Decompiled from char __thiscall CInputProcessor::InitGoodsOutSideBar(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitGoodsOutSideBar(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax

  v2 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CBuildingMgr::FillGoodsOutSideBar(&g_cPortGoodsOutBarInfo, 0, *v2);
  v3 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CLogic::SetFillSideBarInfos(g_pLogic, CBuildingMgr::FillGoodsOutSideBar, &g_cPortGoodsOutBarInfo, *v3);
  return 0;
}


// address=[0x145b2c0]
// Decompiled from char __thiscall CInputProcessor::InitTradeSideBar(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitTradeSideBar(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax

  v2 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CBuildingMgr::FillTradeSideBar(&g_cPortTradeBarInfo, 0, *v2);
  v3 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CLogic::SetFillSideBarInfos(g_pLogic, CBuildingMgr::FillTradeSideBar, &g_cPortTradeBarInfo, *v3);
  return 0;
}


// address=[0x145b320]
// Decompiled from char __thiscall CInputProcessor::InitStorageSideBar(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitStorageSideBar(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax

  v2 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CBuildingMgr::FillStorageSideBar(&g_cStorageSideBarInfo, 0, *v2);
  v3 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CLogic::SetFillSideBarInfos(g_pLogic, CBuildingMgr::FillStorageSideBar, &g_cStorageSideBarInfo, *v3);
  return 0;
}


// address=[0x145b380]
// Decompiled from char __thiscall CInputProcessor::InitEyeCatcherSideBar(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitEyeCatcherSideBar(class CEvn_Logic * a2) {
  
  CWorldManager::ClearHelperObject();
  CBuildingMgr::FillEyeCatcherSideBar(&g_cEyeCatcherBarInfo, 0);
  CLogic::SetFillSideBarInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, int))CBuildingMgr::FillEyeCatcherSideBar,
    &g_cEyeCatcherBarInfo,
    0);
  return 0;
}


// address=[0x145b3c0]
// Decompiled from char __thiscall CInputProcessor::InitAddVehicleSideBar(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitAddVehicleSideBar(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax

  v2 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CBuildingMgr::FillAddVehicleSideBar(&g_cVehicleSideBarInfo, 0, *v2);
  v3 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CLogic::SetFillSideBarInfos(g_pLogic, CBuildingMgr::FillAddVehicleSideBar, &g_cVehicleSideBarInfo, *v3);
  return 0;
}


// address=[0x145b420]
// Decompiled from char __stdcall CInputProcessor::CloseSideBar(int a1)
bool  CInputProcessor::CloseSideBar(class CEvn_Logic * a1) {
  
  CLogic::SetFillSideBarInfos(g_pLogic, 0, 0, 0);
  return 0;
}


// address=[0x145b440]
// Decompiled from char __thiscall CInputProcessor::Morph2FoundationCart(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::Morph2FoundationCart(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  uchar LocalPlayerId; // [esp-Ch] [ebp-48h]
  CEvn_Logic v6; // [esp+Ch] [ebp-30h] BYREF
  int v7; // [esp+38h] [ebp-4h]

  if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    return 0;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  v2 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic(&v6, 0x1394u, *v2, 0, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3699, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
  {
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v6);
    v7 = -1;
    CEvn_Logic::~CEvn_Logic(&v6);
    return 1;
  }
  CInputProcessor::Clear(this);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(&v6);
  return 0;
}


// address=[0x145b540]
// Decompiled from char __thiscall CInputProcessor::CreateSettlement(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::CreateSettlement(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  uchar LocalPlayerId; // [esp-Ch] [ebp-44h]
  CEvn_Logic v6; // [esp+8h] [ebp-30h] BYREF
  int v7; // [esp+34h] [ebp-4h]

  if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    return 1;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  v2 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic(&v6, 0x1393u, *v2, 0, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3757, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v6);
  CInputProcessor::Clear(this);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(&v6);
  return 1;
}


// address=[0x145b630]
// Decompiled from char __thiscall CInputProcessor::Morph2Cart(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::Morph2Cart(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  uchar LocalPlayerId; // [esp-Ch] [ebp-48h]
  CEvn_Logic v6; // [esp+Ch] [ebp-30h] BYREF
  int v7; // [esp+38h] [ebp-4h]

  if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    return 0;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  v2 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic(&v6, 0x1395u, *v2, 0, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3723, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
  {
    INetworkEngine::SendNetMessage(g_pNetworkEngine, &v6);
    v7 = -1;
    CEvn_Logic::~CEvn_Logic(&v6);
    return 1;
  }
  CInputProcessor::DeSelectAll(this);
  CFsm::GenerateEvent(this->m_pFSM, 401, 0);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(&v6);
  return 0;
}


// address=[0x145b740]
// Decompiled from char __thiscall CInputProcessor::VehicleUnload(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::VehicleUnload(class CEvn_Logic * a2) {
  
  uchar LocalPlayerId; // al
  _BYTE v4[12]; // [esp+4h] [ebp-70h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-64h] BYREF
  _BYTE v7[12]; // [esp+20h] [ebp-54h] BYREF
  uint v8; // [esp+2Ch] [ebp-48h]
  std::_Iterator_base12 *v9; // [esp+30h] [ebp-44h]
  std::_Iterator_base12 *v10; // [esp+34h] [ebp-40h]
  int v11; // [esp+38h] [ebp-3Ch]
  int v12; // [esp+3Ch] [ebp-38h]
  char v13; // [esp+43h] [ebp-31h]
  CEvn_Logic v14; // [esp+44h] [ebp-30h] BYREF
  int v15; // [esp+70h] [ebp-4h]

  if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection)
    && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3777, "m_vSelection.size() > 0") == 1 )
  {
    __debugbreak();
  }
  if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    return 1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v7);
  v15 = 0;
  v12 = std::vector<unsigned short>::begin(v5);
  v11 = v12;
  LOBYTE(v15) = 1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator=(v12);
  LOBYTE(v15) = 0;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v5);
  while ( 1 )
  {
    v10 = (std::_Iterator_base12 *)std::vector<unsigned short>::end(v4);
    v9 = v10;
    LOBYTE(v15) = 2;
    v13 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator!=(v10);
    LOBYTE(v15) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v4);
    if ( !v13 )
      break;
    v8 = *(unsigned __int16 *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator*(v7);
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    CEvn_Logic::CEvn_Logic(&v14, 0x1391u, v8, 0, LocalPlayerId, 0, 0);
    LOBYTE(v15) = 3;
    if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3794, "g_pNetworkEngine != NULL") == 1 )
      __debugbreak();
    if ( g_pNetworkEngine )
      INetworkEngine::SendNetMessage(g_pNetworkEngine, &v14);
    LOBYTE(v15) = 0;
    CEvn_Logic::~CEvn_Logic(&v14);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator++(v7);
  }
  v15 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v7);
  return 1;
}


// address=[0x145b8f0]
// Decompiled from char __thiscall CInputProcessor::CatapultLoad(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::CatapultLoad(class CEvn_Logic * a2) {
  
  uchar LocalPlayerId; // al
  _BYTE v4[12]; // [esp+4h] [ebp-70h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-64h] BYREF
  _BYTE v7[12]; // [esp+20h] [ebp-54h] BYREF
  uint v8; // [esp+2Ch] [ebp-48h]
  std::_Iterator_base12 *v9; // [esp+30h] [ebp-44h]
  std::_Iterator_base12 *v10; // [esp+34h] [ebp-40h]
  int v11; // [esp+38h] [ebp-3Ch]
  int v12; // [esp+3Ch] [ebp-38h]
  char v13; // [esp+43h] [ebp-31h]
  CEvn_Logic v14; // [esp+44h] [ebp-30h] BYREF
  int v15; // [esp+70h] [ebp-4h]

  if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection)
    && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3806, "m_vSelection.size() > 0") == 1 )
  {
    __debugbreak();
  }
  if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    return 1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v7);
  v15 = 0;
  v12 = std::vector<unsigned short>::begin(v5);
  v11 = v12;
  LOBYTE(v15) = 1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator=(v12);
  LOBYTE(v15) = 0;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v5);
  while ( 1 )
  {
    v10 = (std::_Iterator_base12 *)std::vector<unsigned short>::end(v4);
    v9 = v10;
    LOBYTE(v15) = 2;
    v13 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator!=(v10);
    LOBYTE(v15) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v4);
    if ( !v13 )
      break;
    v8 = *(unsigned __int16 *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator*(v7);
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    CEvn_Logic::CEvn_Logic(&v14, 0x1392u, v8, 0, LocalPlayerId, 0, 0);
    LOBYTE(v15) = 3;
    if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3822, "g_pNetworkEngine != NULL") == 1 )
      __debugbreak();
    if ( g_pNetworkEngine )
      INetworkEngine::SendNetMessage(g_pNetworkEngine, &v14);
    LOBYTE(v15) = 0;
    CEvn_Logic::~CEvn_Logic(&v14);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator++(v7);
  }
  v15 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v7);
  return 1;
}


// address=[0x145baa0]
// Decompiled from char __thiscall CInputProcessor::DestroyWarMachine(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::DestroyWarMachine(class CEvn_Logic * a2) {
  
  uchar LocalPlayerId; // al
  uint v5; // [esp+8h] [ebp-38h]
  unsigned int i; // [esp+Ch] [ebp-34h]
  CEvn_Logic v7; // [esp+10h] [ebp-30h] BYREF
  int v8; // [esp+3Ch] [ebp-4h]

  for ( i = 0; i < std::vector<unsigned short>::size(&CInputProcessor::m_vSelection); ++i )
  {
    v5 = *std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, i);
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    CEvn_Logic::CEvn_Logic(&v7, 0x13B9u, v5, 0, LocalPlayerId, 0, 0);
    v8 = 0;
    if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 5335, "g_pNetworkEngine != NULL") == 1 )
      __debugbreak();
    if ( g_pNetworkEngine )
      INetworkEngine::SendNetMessage(g_pNetworkEngine, &v7);
    v8 = -1;
    CEvn_Logic::~CEvn_Logic(&v7);
  }
  CInputProcessor::Clear(this);
  return 1;
}


// address=[0x145bbb0]
// Decompiled from char __thiscall CInputProcessor::ZoomAreaState(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::ZoomAreaState(class CEvn_Logic * a2) {
  
  this->m_iViewState = ZOOM_AREA_STATE;
  return 1;
}


// address=[0x145bbd0]
// Decompiled from char __thiscall CInputProcessor::CamSelection(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::CamSelection(class CEvn_Logic * a2) {
  
  int v2; // eax
  int v3; // eax
  int v4; // esi
  _BYTE v6[16]; // [esp+8h] [ebp-48h] BYREF
  int TheBestEntity; // [esp+18h] [ebp-38h]
  int v8; // [esp+1Ch] [ebp-34h]
  int iY; // [esp+24h] [ebp-2Ch]
  int iX; // [esp+28h] [ebp-28h]
  int v12; // [esp+2Ch] [ebp-24h]
  int v13; // [esp+30h] [ebp-20h]
  int v14; // [esp+34h] [ebp-1Ch]
  int i; // [esp+38h] [ebp-18h]
  IEntity *v16; // [esp+3Ch] [ebp-14h]
  __int16 v17; // [esp+40h] [ebp-10h] BYREF
  char v18; // [esp+43h] [ebp-Dh]
  int v19; // [esp+4Ch] [ebp-4h]

  iX = Y16X16::UnpackXFast(a2->m_lParam);
  iY = Y16X16::UnpackYFast(a2->m_lParam);
  std::vector<unsigned short>::vector<unsigned short>(v6);
  v19 = 0;
  v8 = CSpiralOffsets::Last(2);
  v16 = 0;
  v14 = 0;
  v13 = 0;
  for ( i = 0; i <= v8; ++i )
  {
    v2 = CSpiralOffsets::DeltaX(i);
    v14 = iX + v2;
    v3 = CSpiralOffsets::DeltaY(i);
    v13 = iY + v3;
    if ( CWorldManager::InWorld(v14, iY + v3) )
    {
      v12 = CWorldManager::MapObjectId(v14, v13);
      if ( v12 )
      {
        v16 = CMapObjectMgr::EntityPtr(v12);
        if ( IEntity::ObjType(v16) == 128
          || (v4 = IEntity::OwnerId(v16), v4 == CPlayerManager::GetLocalPlayerId())
          && (IEntity::ObjType(v16) == SETTLER_OBJ
           || IEntity::ObjType(v16) == SHIP_OBJ
           || IEntity::ObjType(v16) == CATAPULT_OBJ) )
        {
          v17 = v12;
          std::vector<unsigned short>::push_back(v6, &v17);
        }
        else
        {
          v16 = 0;
        }
      }
      else
      {
        g_iCamWndX = v14;
        g_iCamWndY = v13;
      }
    }
  }
  if ( !(unsigned __int8)std::vector<unsigned short>::empty(v6) )
  {
    TheBestEntity = CInputProcessor::GetTheBestEntity((CInputProcessor *)v6, iX, iY);
    v16 = CMapObjectMgr::EntityPtr(TheBestEntity);
  }
  if ( v16 )
  {
    g_uCamWndEntityId = IEntity::EntityId(v16);
    g_iCamWndUniqueId = IEntity::UniqueId(v16);
  }
  else
  {
    g_uCamWndEntityId = 0;
    g_iCamWndUniqueId = 0;
    g_iCamWndX = iX;
    g_iCamWndY = iY;
  }
  this->m_iViewState = SELECT_STATE;
  v18 = 1;
  v19 = -1;
  std::vector<unsigned short>::~vector<unsigned short>(v6);
  return v18;
}


// address=[0x145be00]
// Decompiled from int __thiscall CInputProcessor::TraceStates(CInputProcessor *this, const CEvn_Logic *a2)
void  CInputProcessor::TraceStates(class CEvn_Logic const & a2) {
  
  T_INPUT_STATE v2; // eax
  unsigned int m_iEventId; // [esp+4h] [ebp-4h]

  m_iEventId = a2->m_iEventId;
  if ( m_iEventId >= 0x190 && a2->m_iEventId <= 0x1E9u )
    m_iEventId = a2->m_iEventId - 400;
  v2 = CFsm::CurrentState(this->m_pFSM);
  return CTrace::Print("IP - process type: %s actState: %s", off_3D89628[m_iEventId], off_3D895F4[v2]);
}


// address=[0x145be70]
// Decompiled from void __thiscall CInputProcessor::BoxSelection(CInputProcessor *this)
void  CInputProcessor::BoxSelection(void) {
  
  unsigned __int16 *v1; // eax
  unsigned __int16 *v2; // eax
  DWORD v3; // [esp+4h] [ebp-30h]
  int EntitySelectionType; // [esp+18h] [ebp-1Ch]
  int v5; // [esp+1Ch] [ebp-18h]
  IEntity *v6; // [esp+20h] [ebp-14h]
  signed int j; // [esp+24h] [ebp-10h]
  signed int i; // [esp+28h] [ebp-Ch]
  __int16 v10; // [esp+32h] [ebp-2h] BYREF

  if ( CGameData::IsLastFrameRendered(g_pGameData) )
  {
    v5 = std::vector<unsigned short>::size(&this->m_pEntityCandidates);
    std::vector<unsigned short>::size(&CInputProcessor::m_vSelection);
    if ( !this->m_iSelectionType )
    {
      for ( i = 0; i < v5; ++i )
      {
        v1 = std::vector<unsigned short>::operator[](&this->m_pEntityCandidates, i);
        EntitySelectionType = CInputProcessor::GetEntitySelectionType(*v1);
        if ( (EntitySelectionType & 0xFF0000) > (signed int)(this->m_iSelectionType & 0xFF0000) )
          this->m_iSelectionType = EntitySelectionType & 0xFFFF00;
      }
    }
    if ( (int)this->m_iSelectionType > 0 )
    {
      if ( this->m_iSelectionType == 0x10000 && std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
        v5 = 0;
      for ( j = 0; j < v5; ++j )
      {
        if ( (unsigned int)std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) >= 0x64 )
          break;
        v3 = this->m_iSelectionType & 0xFFFF00;
        v2 = std::vector<unsigned short>::operator[](&this->m_pEntityCandidates, j);
        v6 = CMapObjectMgr::EntityPtr(*v2);
        if ( (CInputProcessor::GetEntitySelectionType(v6) & 0xFFFF00) == v3
          && !IEntity::FlagBits(v6, EntityFlag_Selected) )
        {
          IEntity::SetFlagBits(v6, EntityFlag_Selected);
          v10 = IEntity::EntityId(v6);
          std::vector<unsigned short>::push_back(&v10);
          if ( this->m_iSelectionType == 0x10000 )
            break;
        }
      }
    }
    if ( !this->m_bBoxSelectAllSettler )
    {
      if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
        CInputProcessor::Clear(this);
      CInputProcessor::RequestDialog(this);
    }
    std::vector<unsigned short>::clear(&this->m_pEntityCandidates);
    this->m_bBoxSelectAllSettler = 0;
    this->m_iSelectionMode = 0;
    this->m_iSelectionType = 0;
    this->m_iSelectionStrict = 0;
  }
}


// address=[0x145c080]
// Decompiled from int __thiscall CInputProcessor::SelectOne(CInputProcessor *this, int x, int y)
int  CInputProcessor::SelectOne(int x, int y) {
  
  int v3; // esi
  int v5; // esi
  int v6; // esi
  int v7; // [esp+8h] [ebp-6Ch] BYREF
  int v8; // [esp+18h] [ebp-5Ch]
  int v9; // [esp+1Ch] [ebp-58h]
  int v10; // [esp+20h] [ebp-54h]
  int v11; // [esp+24h] [ebp-50h]
  int v12; // [esp+28h] [ebp-4Ch]
  IEntity *v14; // [esp+30h] [ebp-44h]
  int TheBestEntity; // [esp+34h] [ebp-40h]
  int v16; // [esp+38h] [ebp-3Ch]
  int v17; // [esp+3Ch] [ebp-38h]
  int v18; // [esp+40h] [ebp-34h]
  int v19; // [esp+44h] [ebp-30h]
  int v20; // [esp+48h] [ebp-2Ch]
  int v21; // [esp+4Ch] [ebp-28h]
  int v22; // [esp+50h] [ebp-24h]
  int v23; // [esp+54h] [ebp-20h]
  IEntity *v24; // [esp+58h] [ebp-1Ch]
  IEntity *v25; // [esp+5Ch] [ebp-18h]
  int i; // [esp+60h] [ebp-14h]
  __int16 v27; // [esp+66h] [ebp-Eh] BYREF
  int v28; // [esp+70h] [ebp-4h]

  std::vector<unsigned short>::vector<unsigned short>(&v7);
  v28 = 0;
  v22 = CSpiralOffsets::Last(2);
  for ( i = 0; i <= v22; ++i )
  {
    v16 = x + CSpiralOffsets::DeltaX(i);
    v17 = y + CSpiralOffsets::DeltaY(i);
    if ( CWorldManager::InWorld(v16, v17) )
    {
      v23 = CWorldManager::MapObjectId(v16, v17);
      if ( v23 )
      {
        v24 = CMapObjectMgr::EntityPtr(v23);
        v3 = IEntity::OwnerId(v24);
        if ( v3 == CPlayerManager::GetLocalPlayerId()
          && (IEntity::FlagBits(v24, EntityFlag_Selectable) || IEntity::FlagBits(v24, (EntityFlag)0x4000)) )
        {
          v27 = v23;
          std::vector<unsigned short>::push_back(&v7, &v27);
        }
      }
    }
  }
  TheBestEntity = CInputProcessor::GetTheBestEntity((CInputProcessor *)&v7, x, y);
  if ( TheBestEntity )
  {
    v12 = TheBestEntity;
    v28 = -1;
    std::vector<unsigned short>::~vector<unsigned short>(&v7);
    return v12;
  }
  v22 = CSpiralOffsets::Last(5);
  for ( i = 0; ; ++i )
  {
    if ( i > v22 )
    {
      v8 = 0;
      v28 = -1;
      std::vector<unsigned short>::~vector<unsigned short>(&v7);
      return v8;
    }
    v19 = x + CSpiralOffsets::DeltaX(i);
    v20 = y + CSpiralOffsets::DeltaY(i);
    if ( CWorldManager::InWorld(v19, v20) )
      break;
LABEL_13:
    ;
  }
  v21 = CWorldManager::MapObjectId(v19, v20);
  if ( !v21 )
  {
    v18 = CWorldManager::ObjectId(v19, v20);
    if ( v18 )
    {
      v14 = CMapObjectMgr::EntityPtr(v18);
      v6 = IEntity::OwnerId(v14);
      if ( v6 == CPlayerManager::GetLocalPlayerId() && IEntity::ObjType(v14) == BUILDING_OBJ )
      {
        v9 = v18;
        v28 = -1;
        std::vector<unsigned short>::~vector<unsigned short>(&v7);
        return v9;
      }
    }
    goto LABEL_13;
  }
  v25 = CMapObjectMgr::EntityPtr(v21);
  v5 = IEntity::OwnerId(v25);
  if ( v5 != CPlayerManager::GetLocalPlayerId()
    || !IEntity::FlagBits(v25, EntityFlag_Selectable)
    && !IEntity::FlagBits(v25, (EntityFlag)0x4000)
    && IEntity::ObjType(v25) != BUILDING_OBJ )
  {
    goto LABEL_13;
  }
  if ( IEntity::ObjType(v25) == SETTLER_OBJ && i > 1 )
  {
    v11 = 0;
    v28 = -1;
    std::vector<unsigned short>::~vector<unsigned short>(&v7);
    return v11;
  }
  else
  {
    v10 = v21;
    v28 = -1;
    std::vector<unsigned short>::~vector<unsigned short>(&v7);
    return v10;
  }
}


// address=[0x145c390]
// Decompiled from int __stdcall CInputProcessor::GetTheBestEntity(CInputProcessor *a1, int x, int y)
int  CInputProcessor::GetTheBestEntity(class std::vector<unsigned short,class std::allocator<unsigned short> > & a1, int x, int y) {
  
  unsigned int v3; // eax
  unsigned __int16 *v4; // eax
  T_SETTLER_OBJ_TYPE v5; // eax
  int v6; // eax
  __int16 *v7; // eax
  unsigned int v8; // eax
  unsigned __int16 *iEntityId; // eax
  int iEntityY; // eax
  int v12; // [esp-Ch] [ebp-84h]
  unsigned int v13; // [esp-8h] [ebp-80h]
  unsigned int JobPart; // [esp-4h] [ebp-7Ch]
  _BYTE v15[16]; // [esp+10h] [ebp-68h] BYREF
  int v16; // [esp+20h] [ebp-58h]
  int v17; // [esp+24h] [ebp-54h]
  int v18; // [esp+28h] [ebp-50h]
  int v19; // [esp+2Ch] [ebp-4Ch]
  int v20; // [esp+30h] [ebp-48h]
  int v21; // [esp+34h] [ebp-44h]
  int iPrevEntityY; // [esp+38h] [ebp-40h]
  IEntity *pEntity; // [esp+3Ch] [ebp-3Ch]
  int screenY; // [esp+40h] [ebp-38h] BYREF
  int screenX; // [esp+44h] [ebp-34h] BYREF
  int v26; // [esp+48h] [ebp-30h] BYREF
  int v27; // [esp+4Ch] [ebp-2Ch] BYREF
  IEntity *v28; // [esp+50h] [ebp-28h]
  unsigned int i; // [esp+54h] [ebp-24h]
  _DWORD v30[2]; // [esp+58h] [ebp-20h] BYREF
  int v31; // [esp+60h] [ebp-18h]
  int v32; // [esp+64h] [ebp-14h]
  int v33; // [esp+74h] [ebp-4h]

  std::vector<unsigned short>::vector<unsigned short>(v15);
  v33 = 0;
  IGfxEngine::GetScreenOffsetsByMapIndices(x, y, &screenX, &screenY);
  for ( i = 0; ; ++i )
  {
    v3 = std::vector<unsigned short>::size(a1);
    if ( i >= v3 )
      break;
    v4 = std::vector<unsigned short>::operator[](a1, i);
    v28 = CMapObjectMgr::MovingEntity(*v4);
    if ( IMovingEntity::GetJobPart((IMovingEntity *)v28) )
    {
      JobPart = IMovingEntity::GetJobPart((IMovingEntity *)v28);
      v13 = IEntity::Race(v28);
      v5 = IEntity::ObjType(v28);
      CGfxManager::GetBoundingBox(g_pGfxManager, (struct SGfxBoundingBox *)v30, v5, v13, JobPart);
      v12 = IEntity::Y(v28);
      v6 = IEntity::X(v28);
      IGfxEngine::GetScreenOffsetsByMapIndices(v6, v12, &v27, &v26);
      v20 = v27 - v31;
      v19 = v30[0] + v27 - v31;
      v18 = v26 - v32;
      v17 = v30[1] + v26 - v32;
      if ( v27 - v31 <= screenX && v19 >= screenX && v18 <= screenY && v17 >= screenY )
      {
        v7 = (__int16 *)std::vector<unsigned short>::operator[](a1, i);
        std::vector<unsigned short>::push_back(v15, v7);
      }
    }
  }
  v21 = 0;
  iPrevEntityY = 0;
  for ( i = 0; ; ++i )
  {
    v8 = std::vector<unsigned short>::size(v15);
    if ( i >= v8 )
      break;
    iEntityId = std::vector<unsigned short>::operator[](v15, i);
    pEntity = CMapObjectMgr::EntityPtr(*iEntityId);
    iEntityY = IEntity::Y(pEntity);
    if ( iEntityY > iPrevEntityY )
    {
      iPrevEntityY = IEntity::Y(pEntity);
      v21 = *std::vector<unsigned short>::operator[](v15, i);
    }
  }
  v16 = v21;
  v33 = -1;
  std::vector<unsigned short>::~vector<unsigned short>(v15);
  return v16;
}


// address=[0x145c590]
// Decompiled from int __thiscall CInputProcessor::SelectAllInSurrounding(CInputProcessor *this, int a2, int a3)
int  CInputProcessor::SelectAllInSurrounding(int a2, int a3) {
  
  int v4; // eax
  int v5; // [esp-4h] [ebp-38h]
  int LocalPlayerId; // [esp+Ch] [ebp-28h]
  int v8; // [esp+18h] [ebp-1Ch]
  unsigned int v9; // [esp+1Ch] [ebp-18h]
  unsigned int v10; // [esp+20h] [ebp-14h]
  int v11; // [esp+24h] [ebp-10h]
  int i; // [esp+28h] [ebp-Ch]
  IEntity *v13; // [esp+2Ch] [ebp-8h]
  __int16 v14; // [esp+32h] [ebp-2h] BYREF

  if ( (unsigned int)std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) >= 0x64 )
    return 0;
  if ( this->m_iSelectionType == 0x10000 && std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    return 0;
  if ( dword_3F1F60C <= 0 )
    return 0;
  if ( dword_3F1F608 )
    v11 = 19823;
  else
    v11 = 3000;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  for ( i = 0; i < v11; ++i )
  {
    v9 = a2 + CSpiralOffsets::DeltaX(i);
    v10 = a3 + CSpiralOffsets::DeltaY(i);
    if ( CWorldManager::InWorld(v9, v10) )
    {
      v8 = CWorldManager::MapObjectId(v9, v10);
      if ( v8 > 0 )
      {
        v13 = CMapObjectMgr::EntityPtr(v8);
        if ( v13 )
        {
          if ( IEntity::OwnerId(v13) == LocalPlayerId
            && IEntity::FlagBits(v13, (EntityFlag)&loc_3000000)
            && (IEntity::FlagBits(v13, EntityFlag_Selectable) || IEntity::ObjType(v13) == BUILDING_OBJ)
            && CInputProcessor::GetEntitySelectionType(v13) == this->m_iSelectionType )
          {
            v5 = IEntity::Y(v13);
            v4 = IEntity::X(v13);
            if ( CWorldManager::SectorId(v4, v5) == dword_3F1F60C )
            {
              IEntity::SetFlagBits(v13, EntityFlag_Selected);
              v14 = IEntity::EntityId(v13);
              std::vector<unsigned short>::push_back(&v14);
              if ( IEntity::ObjType(v13) == BUILDING_OBJ
                || (unsigned int)std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) >= 0x64 )
              {
                break;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}


// address=[0x145c790]
// Decompiled from char __stdcall CInputProcessor::SelectAtSector(S4_SETTLER_ENUM _SettlerType, int a2)
bool  CInputProcessor::SelectAtSector(enum SETTLER_TYPES _SettlerType, int a2) {
  
  int LocalPlayerId; // eax
  int v4; // eax
  int v5; // [esp-4h] [ebp-18h]
  int i; // [esp+8h] [ebp-Ch]
  CSettler *SettlerPtr; // [esp+Ch] [ebp-8h]
  __int16 v8; // [esp+10h] [ebp-4h] BYREF
  char v9; // [esp+13h] [ebp-1h]

  if ( (_SettlerType <= SETTLER_NO_SETTLER || _SettlerType >= SETTLER_MAX)
    && BBSupportDbgReport(
         2,
         "Logic\\InputProcessor.cpp",
         2779,
         "_SettlerType>SETTLER_NO_SETTLER && _SettlerType<SETTLER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a2 <= 0 && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 2780, "_iSectorID > 0") == 1 )
    __debugbreak();
  if ( (unsigned int)std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) >= 0x64 )
    return 0;
  v9 = 0;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  for ( i = CSettlerMgr::GetFirstSettlerId((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, _SettlerType);
        i > 0;
        i = IAnimatedEntity::Next(SettlerPtr) )
  {
    SettlerPtr = CSettlerMgr::GetSettlerPtr((struct CSettlerMgr *)g_cSettlerMgr, i);
    if ( !SettlerPtr && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 2799, "pSettler!=NULL") == 1 )
      __debugbreak();
    if ( SettlerPtr )
    {
      v5 = IEntity::Y(SettlerPtr);
      v4 = IEntity::X(SettlerPtr);
      if ( CWorldManager::SectorId(v4, v5) == a2 )
      {
        IEntity::SetFlagBits(SettlerPtr, EntityFlag_Selected);
        v8 = i;
        std::vector<unsigned short>::push_back(&CInputProcessor::m_vSelection, &v8);
        v9 = 1;
        if ( (unsigned int)std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) >= 0x64 )
          break;
      }
    }
  }
  return v9;
}


// address=[0x145c8e0]
// Decompiled from int __thiscall CInputProcessor::GetUserESInMiddleOfTheScreen(CInputProcessor *this)
int  CInputProcessor::GetUserESInMiddleOfTheScreen(void) {
  
  int spiralOffsetX; // eax
  int spiralOffsetY; // eax
  int centerEcoSector; // eax
  int centerEcoSectorOwner; // esi
  int screenCenterY; // [esp+Ch] [ebp-18h] BYREF
  int screenCenterX; // [esp+10h] [ebp-14h] BYREF
  unsigned int x; // [esp+14h] [ebp-10h]
  int y; // [esp+18h] [ebp-Ch]
  int centerEcoSectorId; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  centerEcoSectorId = 0;
  screenCenterX = 0;
  screenCenterY = 0;
  CStateGame::GetCenterWorldCoordinate(g_pGame, &screenCenterX, &screenCenterY);
  x = 0;
  y = 0;
  for ( i = 0; i < 100; ++i )
  {
    spiralOffsetX = CSpiralOffsets::DeltaX(i);
    x = screenCenterX + spiralOffsetX;
    spiralOffsetY = CSpiralOffsets::DeltaY(i);
    y = screenCenterY + spiralOffsetY;
    if ( CWorldManager::InWorld(x, screenCenterY + spiralOffsetY) )
    {
      centerEcoSectorId = CWorldManager::EcoSectorId(x, y);
      if ( centerEcoSectorId )
      {
        centerEcoSector = CEcoSectorMgr::operator[](g_cESMgr, centerEcoSectorId);
        centerEcoSectorOwner = CEcoSector::Owner(centerEcoSector);
        if ( centerEcoSectorOwner == CPlayerManager::GetLocalPlayerId() )
          return centerEcoSectorId;
      }
      else
      {
        centerEcoSectorId = 0;
      }
    }
  }
  return centerEcoSectorId;
}


// address=[0x145c9d0]
// Decompiled from void __thiscall CInputProcessor::RemoveActiveSettler(CInputProcessor *this, int a2, int a3)
void  CInputProcessor::RemoveActiveSettler(int a2, int a3) {
  
  ;
}


// address=[0x145c9e0]
// Decompiled from int __stdcall CInputProcessor::ActivateSpecialist(int a1, int _iArea)
void  CInputProcessor::ActivateSpecialist(int a1, int _iArea) {
  
  if ( (_iArea < 1 || _iArea > 3)
    && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3030, "_iArea>=1 && _iArea<=3") == 1 )
  {
    __debugbreak();
  }
  return 0;
}


// address=[0x145ca50]
// Decompiled from void __thiscall CInputProcessor::WorkOnBuildingSites(CInputProcessor *this)
void  CInputProcessor::WorkOnBuildingSites(void) {
  
  int LocalPlayerId; // eax MAPDST
  DWORD iBuildBuildingType; // [esp-8h] [ebp-10h] MAPDST
  int v7; // [esp-4h] [ebp-Ch]
  T_INPUT_STATE iViewState; // [esp+0h] [ebp-8h]

  iViewState = this->m_iViewState;
  switch ( iViewState )
  {
    case TRY_BUILD_STATE:
      iBuildBuildingType = this->m_iBuildBuildingType;
      LocalPlayerId = CPlayerManager::GetLocalPlayerId();
      CInputProcessor::GetPossibleBuildingSites(this, LocalPlayerId, iBuildBuildingType, 1);
      this->m_iViewState = TRY_BUILD_STATE_EX;
      return;
    case TRY_BUILD_STATE_EX:
      iBuildBuildingType = this->m_iBuildBuildingType;
      LocalPlayerId = CPlayerManager::GetLocalPlayerId();
      if ( CInputProcessor::GetPossibleBuildingSites(this, LocalPlayerId, iBuildBuildingType, 0) )
      {
        this->m_iViewState = TRY_BUILD_STATE_SEARCH;
        byte_3F1F79C = 1;
        g_iPossibleBuildingSitesUpdateCounter = 0;
      }
      goto LABEL_11;
    case TRY_BUILD_STATE_SEARCH:
      if ( ++g_iPossibleBuildingSitesUpdateCounter > 5 )
      {
        v7 = (unsigned __int8)byte_3F1F79C;
        iBuildBuildingType = this->m_iBuildBuildingType;
        LocalPlayerId = CPlayerManager::GetLocalPlayerId();
        byte_3F1F79C = CInputProcessor::UpdateScreenPossibleBuildingSites(this, LocalPlayerId, iBuildBuildingType, v7);
        g_iPossibleBuildingSitesUpdateCounter = 0;
      }
LABEL_11:
      CInputProcessor::ShowPossibleBuildingType(this);
      break;
  }
}


// address=[0x145cb30]
// Decompiled from char __thiscall CInputProcessor::GetPossibleBuildingSites(CInputProcessor *this, int a2, int arg4, bool a4)
bool  CInputProcessor::GetPossibleBuildingSites(int a2, int a3, bool a4) {
  
  int v5; // [esp+0h] [ebp-48h]
  int OutputWidth; // [esp+Ch] [ebp-3Ch]
  int OutputHeight; // [esp+10h] [ebp-38h]
  char v8; // [esp+14h] [ebp-34h]
  int m_iScreenMapEndX; // [esp+18h] [ebp-30h]
  int m_iScreenMapStartX; // [esp+1Ch] [ebp-2Ch]
  int m_iScreenMapEndY; // [esp+20h] [ebp-28h]
  int v12; // [esp+24h] [ebp-24h]
  DWORD unk_20; // [esp+28h] [ebp-20h]
  int v14; // [esp+2Ch] [ebp-1Ch]
  int HelperObject; // [esp+30h] [ebp-18h]
  int a3; // [esp+34h] [ebp-14h]
  int i; // [esp+3Ch] [ebp-Ch]
  signed int j; // [esp+40h] [ebp-8h]

  a3 = CWorldManager::Width() - 5;
  v8 = 10;
  if ( CBuildingMgr::IsMine(arg4) )
    v8 = 74;
  if ( a4 )
  {
    this->unk_20 = 0;
    OutputWidth = IGfxEngine::GetOutputWidth(g_pGfxEngine);
    OutputHeight = IGfxEngine::GetOutputHeight(g_pGfxEngine);
    IGfxEngine::GetClosestMapPoint(g_pGfxEngine, 1, 1, &this->m_iScreenMapStartX, &this->m_iScreenMapStartY);
    IGfxEngine::GetClosestMapPoint(
      g_pGfxEngine,
      OutputWidth - 2,
      OutputHeight - 2,
      &this->m_iScreenMapEndX,
      &this->m_iScreenMapEndY);
    minmax(&this->m_iScreenMapStartX, 4, a3);
    minmax(&this->m_iScreenMapStartY, 4, a3);
    minmax(&this->m_iScreenMapEndX, 4, a3);
    minmax(&this->m_iScreenMapEndY, 4, a3);
  }
  else if ( (int)this->unk_20 >= 20 )
  {
    return 1;
  }
  if ( (int)this->unk_20 >= 4 )
  {
    m_iScreenMapStartX = 4;
    unk_20 = this->unk_20;
    m_iScreenMapEndX = a3;
    m_iScreenMapEndY = a3;
    v12 = 16;
  }
  else
  {
    m_iScreenMapStartX = this->m_iScreenMapStartX;
    unk_20 = (((signed int)(this->unk_20 & 2) >> 1) | (2 * (this->unk_20 & 1)) | this->unk_20 & 0xFFFFFFFC)
           + this->m_iScreenMapStartY;
    m_iScreenMapEndX = this->m_iScreenMapEndX;
    m_iScreenMapEndY = this->m_iScreenMapEndY;
    v12 = 4;
  }
  v5 = COwnerMap::OwnerBit(a2);
  for ( i = unk_20; i <= m_iScreenMapEndY; i += v12 )
  {
    for ( j = m_iScreenMapStartX; j < m_iScreenMapEndX; ++j )
    {
      if ( (v5 & COwnerMap::OwnerBits1XY(j, i)) != 0 )
      {
        HelperObject = CWorldManager::GetHelperObject(j, i);
        if ( (HelperObject < 10 || HelperObject > 17) && HelperObject != 74 )
        {
          v14 = CBuildingMgr::CheckForBuild((CBuildingMgr *)g_cBuildingMgr, j, i, a2, arg4, 0);
          if ( v14 > 0 )
            CWorldManager::SetHelperObject(j, i, v8 + v14 - 1);
        }
      }
      else
      {
        j = (j + 16) & 0xFFFFFFF0;
      }
    }
  }
  ++this->unk_20;
  return 0;
}


// address=[0x145cdd0]
// Decompiled from char __thiscall CInputProcessor::UpdateScreenPossibleBuildingSites(  CInputProcessor *this,  int _iOwner,  int _iBuildingType,  int a4)
bool  CInputProcessor::UpdateScreenPossibleBuildingSites(int _iOwner, int _iBuildingType, int a4) {
  
  int v5; // [esp+0h] [ebp-2Ch]
  int OutputWidth; // [esp+8h] [ebp-24h]
  int OutputHeight; // [esp+Ch] [ebp-20h]
  char v8; // [esp+10h] [ebp-1Ch]
  int v9; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]
  int a3; // [esp+20h] [ebp-Ch]
  int j; // [esp+24h] [ebp-8h]

  a3 = CWorldManager::Width() - 5;
  v8 = 10;
  if ( CBuildingMgr::IsMine(_iBuildingType) )
    v8 = 74;
  if ( a4 )
  {
    this->unk_20 = 0;
    OutputWidth = IGfxEngine::GetOutputWidth(g_pGfxEngine);
    OutputHeight = IGfxEngine::GetOutputHeight(g_pGfxEngine);
    IGfxEngine::GetClosestMapPoint(g_pGfxEngine, 1, 1, &this->m_iScreenMapStartX, &this->m_iScreenMapStartY);
    IGfxEngine::GetClosestMapPoint(
      g_pGfxEngine,
      OutputWidth - 2,
      OutputHeight - 2,
      &this->m_iScreenMapEndX,
      &this->m_iScreenMapEndY);
    minmax(&this->m_iScreenMapStartX, 4, a3);
    minmax(&this->m_iScreenMapStartY, 4, a3);
    minmax(&this->m_iScreenMapEndX, 4, a3);
    minmax(&this->m_iScreenMapEndY, 4, a3);
    byte_3F1F7B0 = 1;
  }
  else if ( (int)this->unk_20 >= 4 )
  {
    return 1;
  }
  if ( byte_3F1F7B0 )
  {
    dword_3F1F7AC = (((signed int)(this->unk_20 & 2) >> 1) | (2 * (this->unk_20 & 1)) | this->unk_20 & 0xFFFFFFFC)
                  + this->m_iScreenMapStartY;
    byte_3F1F7B0 = 0;
  }
  v5 = COwnerMap::OwnerBit(_iOwner);
  for ( i = 0; i < 2; ++i )
  {
    for ( j = this->m_iScreenMapStartX; j < this->m_iScreenMapEndX; ++j )
    {
      if ( (v5 & COwnerMap::OwnerBits1XY(j, dword_3F1F7AC)) != 0 )
      {
        v9 = CBuildingMgr::CheckForBuild((CBuildingMgr *)g_cBuildingMgr, j, dword_3F1F7AC, _iOwner, _iBuildingType, 0);
        if ( v9 <= 0 )
          CWorldManager::SetHelperObject(j, dword_3F1F7AC, 0);
        else
          CWorldManager::SetHelperObject(j, dword_3F1F7AC, v8 + v9 - 1);
      }
      else
      {
        j = (j + 16) & 0xFFFFFFF0;
      }
    }
    dword_3F1F7AC += 4;
    if ( dword_3F1F7AC > this->m_iScreenMapEndY )
    {
      ++this->unk_20;
      i = 10;
      byte_3F1F7B0 = 1;
    }
  }
  return 0;
}


// address=[0x145d060]
// Decompiled from void __thiscall CInputProcessor::ShowPossibleBuildingType(CInputProcessor *this)
void  CInputProcessor::ShowPossibleBuildingType(void) {
  
  int LocalPlayerId; // eax
  int iPlayerId; // eax
  int v3; // eax
  int v4; // eax
  DWORD v5; // eax
  DWORD m_iBuildBuildingType; // [esp-8h] [ebp-34h]
  DWORD iBuildingType; // [esp-8h] [ebp-34h]
  char v8; // [esp+4h] [ebp-28h]
  unsigned int v9; // [esp+8h] [ebp-24h]
  unsigned int v10; // [esp+Ch] [ebp-20h]
  signed int IconObjectByX; // [esp+10h] [ebp-1Ch]
  int v12; // [esp+14h] [ebp-18h]
  int v13; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]
  unsigned int v15; // [esp+1Ch] [ebp-10h]
  int v16; // [esp+1Ch] [ebp-10h]
  int iMouseHoverY; // [esp+24h] [ebp-8h] BYREF
  int iMouseHoverX; // [esp+28h] [ebp-4h] BYREF

  if ( !CWorldManager::InWorld(s_iPrevMouseHoverX, s_iPrevMouseHoverY) )
  {
    s_iPrevMouseHoverX = 0;
    s_iPrevMouseHoverY = 0;
  }
  v8 = 10;
  if ( CBuildingMgr::IsMine(this->m_iBuildBuildingType) )
    v8 = 74;
  if ( (IGfxEngine::GetClosestMapPoint(
          g_pGfxEngine,
          g_pGame->m_sGameData.m_iScreenMouseX,
          g_pGame->m_sGameData.m_iScreenMouseY,
          &iMouseHoverX,
          &iMouseHoverY) & 0x80000000) != 0
    || !CWorldManager::InWorld(iMouseHoverX, iMouseHoverY) )
  {
    iMouseHoverX = 0;
    iMouseHoverY = 0;
  }
  if ( s_iPrevMouseHoverX != iMouseHoverX || s_iPrevMouseHoverY != iMouseHoverY )
  {
    if ( this->unk_1C )
    {
      CWorldManager::SetHelperObject(s_iPrevMouseHoverX, s_iPrevMouseHoverY, this->unk_1C);
      this->unk_1C = 0;
    }
    m_iBuildBuildingType = this->m_iBuildBuildingType;
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    v12 = CBuildingMgr::CheckForBuild(
            (CBuildingMgr *)g_cBuildingMgr,
            iMouseHoverX,
            iMouseHoverY,
            LocalPlayerId,
            m_iBuildBuildingType,
            0);
    if ( v12 > 0 )
      CWorldManager::SetHelperObject(iMouseHoverX, iMouseHoverY, v8 + v12 - 1);
    else
      CWorldManager::SetHelperObject(iMouseHoverX, iMouseHoverY, 0);
    for ( i = 0; i < 6; ++i )
    {
      v9 = g_sNeighborPoints[i].x + iMouseHoverX;
      v10 = g_sNeighborPoints[i].y + iMouseHoverY;
      if ( CWorldManager::InWorld(v9, v10) )
      {
        iBuildingType = this->m_iBuildBuildingType;
        iPlayerId = CPlayerManager::GetLocalPlayerId();
        v13 = CBuildingMgr::CheckForBuild((CBuildingMgr *)g_cBuildingMgr, v9, v10, iPlayerId, iBuildingType, 0);
        if ( v13 > 0 )
          CWorldManager::SetHelperObject(v9, v10, v8 + v13 - 1);
        else
          CWorldManager::SetHelperObject(v9, v10, 0);
      }
    }
  }
  CWorldManager::WorldSetNumberOfNextLine(iMouseHoverY);
  if ( CWorldManager::WorldGetIconObjectByX(iMouseHoverX) )
  {
    IconObjectByX = CWorldManager::WorldGetIconObjectByX(iMouseHoverX);
    if ( (unsigned int)IconObjectByX < 0xA || IconObjectByX > 17 )
    {
      if ( IconObjectByX == 74 )
      {
        this->unk_1C = 74;
        s_iPrevMouseHoverX = iMouseHoverX;
        s_iPrevMouseHoverY = iMouseHoverY;
        CWorldManager::SetHelperObject(iMouseHoverX, iMouseHoverY, 75);
      }
    }
    else
    {
      this->unk_1C = IconObjectByX;
      s_iPrevMouseHoverX = iMouseHoverX;
      s_iPrevMouseHoverY = iMouseHoverY;
      CWorldManager::SetHelperObject(iMouseHoverX, iMouseHoverY, LOBYTE(this->unk_1C) - v8 + 18);
    }
    CInputProcessor::m_sGfxObj.m_iUnknown = 1;
    CInputProcessor::m_sGfxObj.m_iX = iMouseHoverX;
    CInputProcessor::m_sGfxObj.m_iY = iMouseHoverY;
    byte_3F1F604 = 1;
    v15 = this->m_iBuildBuildingType;
    if ( v15 == 31 || v15 == 32 )
    {
      if ( v15 == 31 )
        v16 = 58;
      else
        v16 = 52;
      v3 = CPlayerManager::GetLocalPlayerId();
      v15 = CBuildingMgr::CheckForBuildInWater((CBuildingMgr *)g_cBuildingMgr, iMouseHoverX, iMouseHoverY, v3, v16);
    }
    v4 = CPlayerManager::GetLocalPlayerId();
    v5 = CPlayerManager::Race(v4);
    CGfxManager::GetBuildingGfxInfo(g_pGfxManager, &CInputProcessor::m_sGfxObj.m_iInfo, v5, v15, 1, 0);
    IGfxEngine::SetGfxObject(&CInputProcessor::m_sGfxObj);
  }
  else
  {
    byte_3F1F604 = 0;
    IGfxEngine::SetGfxObject(&CInputProcessor::m_sGfxObj);
  }
}


// address=[0x145d3f0]
// Decompiled from void __thiscall CInputProcessor::DeSelectAll(CInputProcessor *this)
void  CInputProcessor::DeSelectAll(void) {
  
  IEntity *BuildingPtr; // [esp+4h] [ebp-10h]
  int v2; // [esp+8h] [ebp-Ch]
  IEntity *v3; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]

  if ( std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
  {
    for ( i = 0; i < std::vector<unsigned short>::size(&CInputProcessor::m_vSelection); ++i )
    {
      v2 = *std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, i);
      v3 = CMapObjectMgr::EntityPtr(v2);
      if ( v3 )
      {
        IEntity::ClearFlagBits(v3, EntityFlag_Selected);
        IEntity::ClearFlagBits(v3, (EntityFlag)1024);
        if ( IEntity::ObjType(v3) == BUILDING_OBJ )
        {
          BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v2);
          CBuilding::NotifySelected(BuildingPtr);
        }
      }
    }
    std::vector<unsigned short>::clear(&CInputProcessor::m_vSelection);
  }
}


// address=[0x145d4b0]
// Decompiled from void __thiscall CInputProcessor::RequestDialog(CInputProcessor *this)
void  CInputProcessor::RequestDialog(void) {
  
  unsigned __int16 *v1; // eax
  IEntity *v2; // eax
  unsigned __int16 *v3; // eax
  unsigned __int16 *v4; // eax
  unsigned __int16 *v5; // eax
  unsigned __int16 *v6; // eax
  CBuilding *v7; // [esp+Ch] [ebp-4Ch]
  int v8; // [esp+10h] [ebp-48h]
  ISettlerRole *v9; // [esp+14h] [ebp-44h]
  IEntity *v10; // [esp+18h] [ebp-40h]
  int v11; // [esp+1Ch] [ebp-3Ch]
  CSettler *v12; // [esp+20h] [ebp-38h]
  IEntity *v13; // [esp+28h] [ebp-30h]
  CEvn_Event v15; // [esp+30h] [ebp-28h] BYREF
  int v16; // [esp+54h] [ebp-4h]

  if ( std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
  {
    CEvn_Event::CEvn_Event(&v15, 0x260u, 0, 0, 0);
    v16 = 0;
    if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 5151, "g_pEvnEngine!= NULL") == 1 )
      __debugbreak();
    if ( g_pEvnEngine )
      IEventEngine::SendAMessage(g_pEvnEngine, &v15);
    CLogic::SetFillDialogInfos(g_pLogic, 0, 0, 0);
    v1 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
    v2 = CMapObjectMgr::EntityPtr(*v1);
    switch ( IEntity::ObjType(v2) )
    {
      case SETTLER_OBJ:
        v4 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
        v12 = CSettlerMgr::operator[](*v4);
        if ( IEntity::WarriorType(v12) == AI_WARRIOR_TYPE_MISC_UNIT )
        {
          CSettlerMgr::FillSpecialistMenu(&g_cSpecialistsInfo, 0, this->m_bIsLocal);
          CLogic::SetFillDialogInfos(g_pLogic, CSettlerMgr::FillSpecialistMenu, &g_cSpecialistsInfo, this->m_bIsLocal);
        }
        else if ( IEntity::Type(v12) == 60 )
        {
          v9 = CSettler::Role(v12);
          ((void (__thiscall *)(ISettlerRole *, _DWORD))v9->__vftable[1].ClassID)(v9, 0);
        }
        else
        {
          CSettlerMgr::FillSoldierMenu(&g_cSoldierInfo, 0, this->m_bIsLocal);
          CLogic::SetFillDialogInfos(g_pLogic, CSettlerMgr::FillSoldierMenu, &g_cSoldierInfo, this->m_bIsLocal);
        }
        goto CInputProcessor__RequestDialog___def_185D591;
      case SHIP_OBJ:
        v5 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
        v13 = CVehicleMgr::operator[](*v5);
        v11 = IEntity::Type(v13);
        switch ( v11 )
        {
          case 1:
            goto LABEL_25;
          case 2:
            if ( (unsigned int)std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) > 1 )
              goto LABEL_25;
            break;
          case 3:
            break;
          default:
            goto CInputProcessor__RequestDialog___def_185D591;
        }
        ((void (__thiscall *)(IEntity *, _DWORD))v13->__vftable[1].DbgPrint)(v13, 0);
CInputProcessor__RequestDialog___def_185D591:
        v16 = -1;
        CEvn_Event::~CEvn_Event(&v15);
        return;
      case CATAPULT_OBJ:
        v6 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
        v10 = CVehicleMgr::operator[](*v6);
        v8 = IEntity::Type(v10);
        if ( v8 == 4 )
        {
LABEL_25:
          CVehicleMgr::FillVehicleGroupMenu(&g_cVehicleInfo, 0);
          CLogic::SetFillDialogInfos(
            g_pLogic,
            (void (__cdecl *)(struct CInfoExchange *, bool, bool))CVehicleMgr::FillVehicleGroupMenu,
            &g_cVehicleInfo,
            this->m_bIsLocal);
        }
        else if ( v8 == 5 )
        {
          ((void (__thiscall *)(IEntity *, _DWORD))v10->__vftable[1].DbgPrint)(v10, 0);
        }
        goto CInputProcessor__RequestDialog___def_185D591;
      case BUILDING_OBJ:
        v3 = std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
        v7 = CBuildingMgr::operator[](*v3);
        if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 5169, "g_pEvnEngine!= NULL") == 1 )
          __debugbreak();
        if ( g_pEvnEngine )
          CBuilding::FillDialog(v7);
        goto CInputProcessor__RequestDialog___def_185D591;
      default:
        goto CInputProcessor__RequestDialog___def_185D591;
    }
  }
}


// address=[0x145d880]
// Decompiled from char __thiscall CInputProcessor::Clear(CInputProcessor *this)
bool  CInputProcessor::Clear(void) {
  
  CEvn_Event v3; // [esp+Ch] [ebp-28h] BYREF
  int v4; // [esp+30h] [ebp-4h]

  CInputProcessor::TidyUp(this);
  CInputProcessor::DeSelectAll(this);
  CEvn_Event::CEvn_Event(&v3, 0x25Bu, 0, 0, 0);
  v4 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 4533, "g_pEvnEngine!= NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v3);
  v4 = -1;
  CEvn_Event::~CEvn_Event(&v3);
  return 0;
}


// address=[0x145d950]
// Decompiled from void __thiscall CInputProcessor::TidyUp(CInputProcessor *this)
void  CInputProcessor::TidyUp(void) {
  
  int v1; // [esp+0h] [ebp-Ch]
  IEntity *BuildingPtr; // [esp+8h] [ebp-4h]

  this->m_iViewState = WAIT_STATE;
  if ( std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
  {
    v1 = *std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v1);
    if ( BuildingPtr )
    {
      if ( !IEntity::FlagBits(BuildingPtr, EntityFlag_Selected)
        && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 4498, "pBuilding->FlagBits(ENTITY_FLAG_SELECTED) != 0") == 1 )
      {
        __debugbreak();
      }
      CBuilding::FillDialog(BuildingPtr);
    }
  }
  CLogic::SetFillSideBarInfos(g_pLogic, 0, 0, 0);
  IGfxEngine::SetCursorShape(g_pGfxEngine, 1, 0);
  IGfxEngine::EnableIconLayer(g_pGfxEngine, 0);
  CWorldManager::ClearHelperObject();
  byte_3F1F604 = 0;
  IGfxEngine::SetGfxObject(&CInputProcessor::m_sGfxObj);
}


// address=[0x145da20]
// Decompiled from unsigned __int8 __thiscall CInputProcessor::CloseSidebarAndShowDefaultMenu(CInputProcessor *this)
void  CInputProcessor::CloseSidebarAndShowDefaultMenu(void) {
  
  unsigned __int8 result; // al
  struct CEvn_Event *v2; // [esp+4h] [ebp-34h]
  CEvn_Event v4; // [esp+10h] [ebp-28h] BYREF
  int v5; // [esp+34h] [ebp-4h]

  CInputProcessor::TidyUp(this);
  result = CInputProcessor::Default(this, 0);
  if ( !g_pEvnEngine )
    return result;
  v2 = CEvn_Event::CEvn_Event(&v4, 0x25Bu, 0, 0, 0);
  v5 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, v2);
  v5 = -1;
  return (unsigned __int8)CEvn_Event::~CEvn_Event(&v4);
}


// address=[0x145dad0]
// Decompiled from void __thiscall CInputProcessor::SelectAllVisible(CInputProcessor *this)
void  CInputProcessor::SelectAllVisible(void) {
  
  CInputProcessor::BoxSelection(this);
  this->m_bBoxSelectAllSettler = 0;
}


// address=[0x14604b0]
// Decompiled from char __thiscall CInputProcessor::EmptyFunct(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::EmptyFunct(class CEvn_Logic * a2) {
  
  return 1;
}


// address=[0x14e4b00]
// Decompiled from DWORD __thiscall CInputProcessor::GetSelectionType(CInputProcessor *this)
int  CInputProcessor::GetSelectionType(void)const {
  
  return this->m_iSelectionType;
}


// address=[0x14e4b60]
// Decompiled from _DWORD *__thiscall CInputProcessor::NewCandidate(CInputProcessor *this, __int16 a2)
void  CInputProcessor::NewCandidate(int a2) {
  
  return std::vector<unsigned short>::push_back(&this->m_pEntityCandidates, &a2);
}


// address=[0x14e4bb0]
// Decompiled from void __thiscall CInputProcessor::SetSelectionType(CInputProcessor *this, DWORD a2)
void  CInputProcessor::SetSelectionType(int a2) {
  
  this->m_iSelectionType = a2;
}


// address=[0x3f1f328]
// [Decompilation failed for static struct SGfxObject CInputProcessor::m_sGfxObj]

#endif // Already implemented
