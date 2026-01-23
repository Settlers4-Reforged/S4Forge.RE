#include "CInputProcessor.h"

// Definitions for class CInputProcessor

// address=[0x1439c90]
// Decompiled from void *CInputProcessor::Selection()
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
// Decompiled from void __thiscall CInputProcessor::~CInputProcessor(CFsm **this)
 CInputProcessor::~CInputProcessor(void) {
  
  *this = (CFsm *)&CInputProcessor::_vftable_;
  if ( this[2] )
  {
    delete this[2];
    this[2] = 0;
  }
  std::vector<unsigned short>::~vector<unsigned short>(this + 21);
  IEventHandler::~IEventHandler((IEventHandler *)this);
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
  std::vector<unsigned short>::clear();
  std::vector<unsigned short>::clear();
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
  while ( CStateGame::IsMessage((CStateGame *)g_pGame) )
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
            (INetworkEngine *)g_pNetworkEngine,
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
      (**(void (__thiscall ***)(void *, CEvn_Logic *))g_pNetInputProcessor)(g_pNetInputProcessor, &sGameMessage);
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
      std::vector<unsigned short>::push_back(&CInputProcessor::m_vSelection, (int)&v4);
      CFsm::GenerateEvent(this->m_pFSM, 484, 0);
      if ( IEntity::FlagBits(v3, EntityFlag_Selectable) )
        IEntity::SetFlagBits(v3, EntityFlag_Selected);
      else
        IEntity::SetFlagBits(v3, (EntityFlag)1024);
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
  
  const struct IEntity *v1; // eax

  if ( a1 <= 0 )
    return 0;
  v1 = (const struct IEntity *)CMapObjectMgr::EntityPtr(a1);
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
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x191u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x1E0u, 0);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x192u, 0x11u);
  CFsm::DefineTransition(this->m_pFSM, 0, 1u, 0x1DDu, 0x1Cu);
  CFsm::DefineTransition(this->m_pFSM, 0, 1u, 0x1DEu, 0x1Bu);
  CFsm::DefineTransition(this->m_pFSM, 0, 1u, 0x1AAu, 0x1Du);
  CFsm::DefineTransition(this->m_pFSM, 0, 1u, 0x198u, 0xCu);
  CFsm::DefineTransition(this->m_pFSM, 0, 1u, 0x1E6u, 0xDu);
  CFsm::DefineTransition(this->m_pFSM, 0, 1u, 0x1ABu, 0xEu);
  CFsm::DefineTransition(this->m_pFSM, 0, 1u, 0x1E4u, 3u);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x1E2u, 0x14u);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x1B4u, 0x38u);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x1ACu, 0x10u);
  CFsm::DefineTransition(this->m_pFSM, 0, 4u, 0x1B5u, 4u);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x1B6u, 0xFu);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x1ADu, 0x2Cu);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x1AEu, 0x2Du);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x1AFu, 0x2Eu);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x1E5u, 0x2Fu);
  CFsm::DefineTransition(this->m_pFSM, 0, 1u, 0x1B9u, 0x30u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1B9u, 0x30u);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x1BAu, 0x31u);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x1E1u, 0x4Bu);
  CFsm::DefineTransition(this->m_pFSM, 0, 1u, 0x1D8u, 0x1Eu);
  CFsm::DefineTransition(this->m_pFSM, 0, 1u, 0x1D9u, 0x21u);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x1B0u, 0x32u);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x1B1u, 0x33u);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x1B2u, 0x34u);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x1BDu, 0x36u);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x1BEu, 0x35u);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x1B3u, 0x37u);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x1CAu, 0x41u);
  CFsm::DefineTransition(this->m_pFSM, 0, 0, 0x1B8u, 0x4Au);
  CFsm::DefineTransition(this->m_pFSM, 0, 0xAu, 0x1E7u, 0x53u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 0, 0x191u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1DDu, 0x1Cu);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1DEu, 0x1Bu);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1AAu, 0x1Du);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1E1u, 0x4Bu);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1E0u, 0x22u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x19Fu, 0x28u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1A7u, 0x29u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1D6u, 0x20u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1D8u, 0x1Eu);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1D9u, 0x21u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1D7u, 0x1Fu);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x19Bu, 0x23u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x19Cu, 0x24u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 9u, 0x19Eu, 0x25u);
  CFsm::DefineTransition(this->m_pFSM, 9u, 1u, 0x191u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 9u, 1u, 0x1E0u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 9u, 0, 0x192u, 0x11u);
  CFsm::DefineTransition(this->m_pFSM, 9u, 9u, 0x1DDu, 0x26u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1A6u, 0x27u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1B3u, 0x37u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1C0u, 0x51u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 0, 0x192u, 0x11u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 4u, 0x1B5u, 4u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 3u, 0x193u, 6u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x194u, 8u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x195u, 9u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x196u, 0xAu);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x197u, 0xBu);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x198u, 0xCu);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1E6u, 0xDu);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1ABu, 0xEu);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1CDu, 0x44u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1CEu, 0x45u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1CFu, 0x46u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1D0u, 0x47u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1D4u, 0x48u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1D5u, 0x49u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1BFu, 0x52u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 7u, 0x199u, 0x15u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1D1u, 0x17u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1D2u, 0x18u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1D3u, 0x19u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1E3u, 0x1Au);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1BBu, 0x12u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1BCu, 0x13u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 8u, 0x1C1u, 0x39u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1C2u, 0x3Au);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1C3u, 0x3Bu);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1C4u, 0x3Cu);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1C5u, 0x3Du);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1C7u, 0x3Eu);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1C8u, 0x3Fu);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1C9u, 0x40u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1CBu, 0x42u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1CCu, 0x43u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1A3u, 0x4Cu);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1A5u, 0x4Du);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1A4u, 0x4Eu);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1A1u, 0x4Fu);
  CFsm::DefineTransition(this->m_pFSM, 1u, 1u, 0x1A2u, 0x50u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 0xAu, 0x1E7u, 0x53u);
  CFsm::DefineTransition(this->m_pFSM, 4u, 0, 0x191u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 4u, 0, 0x1E0u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 4u, 0, 0x192u, 0x11u);
  CFsm::DefineTransition(this->m_pFSM, 4u, 0, 0x1ACu, 0x10u);
  CFsm::DefineTransition(this->m_pFSM, 4u, 1u, 0x1DEu, 0x1Bu);
  CFsm::DefineTransition(this->m_pFSM, 4u, 4u, 0x1B5u, 4u);
  CFsm::DefineTransition(this->m_pFSM, 4u, 4u, 0x1DDu, 5u);
  CFsm::DefineTransition(this->m_pFSM, 4u, 4u, 0x1B6u, 0xFu);
  CFsm::DefineTransition(this->m_pFSM, 4u, 0, 0x1CAu, 0x41u);
  CFsm::DefineTransition(this->m_pFSM, 4u, 0xAu, 0x1E7u, 0x53u);
  CFsm::DefineTransition(this->m_pFSM, 3u, 1u, 0x191u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 3u, 1u, 0x1E0u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 3u, 0, 0x192u, 0x11u);
  CFsm::DefineTransition(this->m_pFSM, 3u, 1u, 0x1DEu, 0x1Bu);
  CFsm::DefineTransition(this->m_pFSM, 3u, 3u, 0x1DDu, 7u);
  CFsm::DefineTransition(this->m_pFSM, 3u, 1u, 0x198u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 3u, 1u, 0x194u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 3u, 1u, 0x193u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 3u, 1u, 0x196u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 3u, 1u, 0x1C1u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 3u, 1u, 0x1C2u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 3u, 1u, 0x1C3u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 3u, 1u, 0x1C4u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 3u, 1u, 0x1C5u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 3u, 1u, 0x1C7u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 3u, 1u, 0x1C8u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 3u, 1u, 0x1C9u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 3u, 1u, 0x1CBu, 1u);
  CFsm::DefineTransition(this->m_pFSM, 3u, 0xAu, 0x1E7u, 0x53u);
  CFsm::DefineTransition(this->m_pFSM, 7u, 1u, 0x191u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 7u, 1u, 0x1E0u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 7u, 0, 0x192u, 0x11u);
  CFsm::DefineTransition(this->m_pFSM, 7u, 7u, 0x1DDu, 0x16u);
  CFsm::DefineTransition(this->m_pFSM, 7u, 0xAu, 0x1E7u, 0x53u);
  CFsm::DefineTransition(this->m_pFSM, 1u, 8u, 0x1DAu, 0x2Au);
  CFsm::DefineTransition(this->m_pFSM, 8u, 8u, 0x1DAu, 0x2Au);
  CFsm::DefineTransition(this->m_pFSM, 8u, 8u, 0x1E0u, 0x2Bu);
  CFsm::DefineTransition(this->m_pFSM, 8u, 0, 0x192u, 0x11u);
  CFsm::DefineTransition(this->m_pFSM, 8u, 1u, 0x1DDu, 0x1Cu);
  CFsm::DefineTransition(this->m_pFSM, 8u, 0, 0x191u, 1u);
  CFsm::DefineTransition(this->m_pFSM, 8u, 1u, 0x1CCu, 1u);
  CFsm::DefineTransition(this->m_pFSM, 8u, 1u, 0x1DEu, 0x1Bu);
  CFsm::DefineTransition(this->m_pFSM, 8u, 8u, 0x1D6u, 0x20u);
  CFsm::DefineTransition(this->m_pFSM, 8u, 8u, 0x1D8u, 0x1Eu);
  CFsm::DefineTransition(this->m_pFSM, 8u, 8u, 0x1D9u, 0x21u);
  CFsm::DefineTransition(this->m_pFSM, 8u, 1u, 0x19Bu, 0x23u);
  CFsm::DefineTransition(this->m_pFSM, 8u, 1u, 0x19Cu, 0x24u);
  CFsm::DefineTransition(this->m_pFSM, 8u, 9u, 0x19Eu, 0x25u);
  CFsm::DefineTransition(this->m_pFSM, 8u, 1u, 0x19Fu, 0x28u);
  CFsm::DefineTransition(this->m_pFSM, 8u, 0xAu, 0x1E7u, 0x53u);
  CFsm::DefineTransition(this->m_pFSM, 0xAu, 1u, 0x1DDu, 0x54u);
  CFsm::DefineTransition(this->m_pFSM, 0xAu, 1u, 0x1E0u, 1u);
}


// address=[0x14563d0]
// Decompiled from void __thiscall CInputProcessor::FillHandlersArray(CInputProcessor *this)
void  CInputProcessor::FillHandlersArray(void) {
  
  *this->m_pHandlers = CInputProcessor::HandleInternalError;
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
  DWORD unk_10; // [esp-8h] [ebp-50h]
  uint packedXY; // [esp+4h] [ebp-44h]
  int x; // [esp+Ch] [ebp-3Ch]
  unsigned int y; // [esp+10h] [ebp-38h]
  CEvn_Logic v10; // [esp+18h] [ebp-30h] BYREF
  int v11; // [esp+44h] [ebp-4h]

  this->unk_1C = 0;
  x = LOWORD(a2->m_lParam);
  y = HIWORD(a2->m_lParam);
  unk_10 = this->m_iBuildBuildingType;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  if ( CBuildingMgr::CheckForBuild((CBuildingMgr *)g_cBuildingMgr, x, y, LocalPlayerId, unk_10, 0) <= 0 )
    return 1;
  packedXY = Y16X16::PackXYFast(x, y);
  cLocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CEvn_Logic::CEvn_Logic(&v10, 0x13A1u, this->m_iBuildBuildingType, packedXY, cLocalPlayerId, 0, 0);
  v11 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1603, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, &v10);
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
        IEntity::ObjType(v3) == 8) )
  {
    this->m_iViewState = 3;
    v5 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
    CBuildingMgr::ShowWorkingArea((CBuildingMgr *)g_cBuildingMgr, *v5);
    IGfxEngine::EnableIconLayer((IGfxEngine *)g_pGfxEngine, 1);
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
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, &v11);
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
      INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, &v6);
    CInputProcessor::Clear(this);
    CFsm::GenerateEvent(this->m_pFSM, 401, 0);
    v7 = -1;
    CEvn_Logic::~CEvn_Logic(&v6);
  }
  else
  {
    CInputProcessor::RequestDialog();
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
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, &v5);
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
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, &v5);
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
    std::vector<unsigned short>::push_back(&v12);
    CInputProcessor::RequestDialog();
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
    std::vector<unsigned short>::push_back(&CInputProcessor::m_vSelection, (int)&v12);
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
  
  CLogic::SwitchExtraInfoMenu(g_pLogic, *((_DWORD *)a2 + 2) == 1);
  CStatistic::FillExtraInfo((CStatistic *)&g_cStatistic);
  return 0;
}


// address=[0x1457890]
// Decompiled from char __thiscall CInputProcessor::SelectNextVehicle(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SelectNextVehicle(class CEvn_Logic * a2) {
  
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

  if ( !a2 && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 878, "_pEvent!= NULL") == 1 )
    __debugbreak();
  if ( !a2 )
    return 0;
  VehiclePtr = 0;
  v7 = 0;
  m_lParam = a2->m_lParam;
  if ( !m_lParam )
  {
    if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection)
      && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 890, "m_vSelection.size() > 0") == 1 )
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
    VehiclePtr = CVehicleMgr::GetVehiclePtr(*v3);
    v7 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
    if ( !VehiclePtr && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 901, "pVehicle!=NULL") == 1 )
      __debugbreak();
    if ( !VehiclePtr )
      return 0;
    m_lParam = IEntity::Type(VehiclePtr);
  }
  CInputProcessor::DeSelectAll(this);
  CInputProcessor::Default(this, a2);
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
    std::vector<unsigned short>::push_back(&CInputProcessor::m_vSelection, (int)&v9);
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
  CBuildingMgr::FillBuildingAmount(sBuildingMenuInfo, 0, this->unk_69);
  CLogic::SetFillDialogInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, bool))CBuildingMgr::FillBuildingAmount,
    sBuildingMenuInfo,
    this->unk_69);
  return 0;
}


// address=[0x1457bf0]
// Decompiled from char __thiscall CInputProcessor::DestroyBuildupVehicle(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::DestroyBuildupVehicle(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  char LocalPlayerId; // al
  unsigned int v5; // [esp-8h] [ebp-48h]
  unsigned int v7; // [esp+8h] [ebp-38h]
  _BYTE v8[32]; // [esp+10h] [ebp-30h] BYREF
  int v9; // [esp+3Ch] [ebp-4h]

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
  v7 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v8, 0x13A6u, v7, 0, LocalPlayerId, v5, 0);
  v9 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 5360, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v8);
  CInputProcessor::Clear(this);
  v9 = -1;
  CEvn_Logic::~CEvn_Logic(v8);
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
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, &v6);
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
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, &v6);
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
        if ( IEntity::ObjType(mapObjectAtPos) == 8 )
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
              INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, &v19);
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
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, &v6);
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
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, &v6);
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
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, &v6);
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
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, &v5);
  v6 = -1;
  CEvn_Logic::~CEvn_Logic(&v5);
  return 1;
}


// address=[0x1458540]
// Decompiled from char __thiscall CInputProcessor::ChooseSpellDest(_DWORD *this, int a2)
bool  CInputProcessor::ChooseSpellDest(class CEvn_Logic * a2) {
  
  this[5] = *(_DWORD *)(a2 + 8);
  return 1;
}


// address=[0x1458560]
// Decompiled from char __thiscall CInputProcessor::SelectSpellDest(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SelectSpellDest(class CEvn_Logic * a2) {
  
  unsigned __int16 *v3; // eax
  int v4; // eax
  char LocalPlayerId; // al
  unsigned int v6; // [esp-8h] [ebp-64h]
  int v7; // [esp-4h] [ebp-60h]
  unsigned int v8; // [esp+4h] [ebp-58h]
  unsigned int v9; // [esp+8h] [ebp-54h]
  int v10; // [esp+Ch] [ebp-50h]
  int v11; // [esp+10h] [ebp-4Ch]
  unsigned int v12; // [esp+14h] [ebp-48h]
  unsigned int v14; // [esp+1Ch] [ebp-40h]
  int v15; // [esp+20h] [ebp-3Ch]
  unsigned int i; // [esp+24h] [ebp-38h]
  void **v17; // [esp+28h] [ebp-34h]
  _BYTE v18[32]; // [esp+2Ch] [ebp-30h] BYREF
  int v19; // [esp+58h] [ebp-4h]

  if ( (*((_DWORD *)a2 + 2) & 0x10) != 0 || *((_DWORD *)this + 5) == -1 )
  {
    CInputProcessor::SendTo(this, a2);
    return 1;
  }
  else
  {
    v10 = *((unsigned __int16 *)a2 + 6);
    v11 = (unsigned __int16)HIWORD(*((_DWORD *)a2 + 3));
    v15 = 0;
    v12 = -1;
    for ( i = 0; i < std::vector<unsigned short>::size(&CInputProcessor::m_vSelection); ++i )
    {
      v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, i);
      v17 = CMapObjectMgr::MovingEntity(*v3);
      if ( IEntity::ObjType((unsigned __int8 *)v17) == 1 && IEntity::Type((unsigned __int16 *)v17) == 45 )
      {
        v7 = v11 - IEntity::Y(v17);
        v4 = IEntity::X(v17);
        v14 = Grid::Distance((Grid *)(v10 - v4), v7);
        if ( v14 < v12 )
        {
          v12 = v14;
          v15 = IEntity::ID();
        }
      }
    }
    if ( !v15 && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 2357, "iPriestId != 0") == 1 )
      __debugbreak();
    if ( !v15 )
      return 1;
    v8 = ((unsigned __int16)v15 << 16) | *((unsigned __int16 *)this + 10);
    v9 = Y16X16::PackXYFast(v10, v11);
    LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
    CEvn_Logic::CEvn_Logic((CEvn_Logic *)v18, 0x13B8u, v8, v9, LocalPlayerId, v6, 0);
    v19 = 0;
    if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 2371, "g_pNetworkEngine != NULL") == 1 )
      __debugbreak();
    if ( g_pNetworkEngine )
      INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v18);
    v19 = -1;
    CEvn_Logic::~CEvn_Logic(v18);
    return 1;
  }
}


// address=[0x1458770]
// Decompiled from char __thiscall CInputProcessor::InitSettlerAmount(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitSettlerAmount(class CEvn_Logic * a2) {
  
  CSettlerMgr::FillSettlerAmount(&g_cSettlerStatisticInfo, 0, *((unsigned __int8 *)this + 105));
  CLogic::SetFillDialogInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, bool))CSettlerMgr::FillSettlerAmount,
    (struct CInfoExchange *)&g_cSettlerStatisticInfo,
    *((_BYTE *)this + 105));
  return 0;
}


// address=[0x14587c0]
// Decompiled from char __thiscall CInputProcessor::InitFreeCarrier(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitFreeCarrier(class CEvn_Logic * a2) {
  
  CSettlerMgr::FillFreeCarrier(&g_cFreeCarrierInfo, 0);
  CLogic::SetFillDialogInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, bool))CSettlerMgr::FillFreeCarrier,
    (struct CInfoExchange *)&g_cFreeCarrierInfo,
    *((_BYTE *)this + 105));
  return 0;
}


// address=[0x1458810]
// Decompiled from char __thiscall CInputProcessor::InitSettlerProduction(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitSettlerProduction(class CEvn_Logic * a2) {
  
  CSettlerMgr::FillSpecialistProduction(&g_cSettlerProductionInfo, 0);
  CLogic::SetFillDialogInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, bool))CSettlerMgr::FillSpecialistProduction,
    (struct CInfoExchange *)&g_cSettlerProductionInfo,
    *((_BYTE *)this + 105));
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
  
  CEcoSectorMgr::FillGoodAmount(&g_cGoodsStatisticInfo, 0, *((unsigned __int8 *)this + 105));
  CLogic::SetFillDialogInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, bool))CEcoSectorMgr::FillGoodAmount,
    (struct CInfoExchange *)&g_cGoodsStatisticInfo,
    *((_BYTE *)this + 105));
  return 0;
}


// address=[0x1458970]
// Decompiled from char __thiscall CInputProcessor::InitTransportPrio(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitTransportPrio(class CEvn_Logic * a2) {
  
  CEcoSectorMgr::FillTransportPrio((struct CInfoExchange *)&g_cTransportpriorityInfo, 0);
  CLogic::SetFillDialogInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, bool))CEcoSectorMgr::FillTransportPrio,
    (struct CInfoExchange *)&g_cTransportpriorityInfo,
    *((_BYTE *)this + 105));
  return 0;
}


// address=[0x14589c0]
// Decompiled from char __thiscall CInputProcessor::InitGoodDistribution(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitGoodDistribution(class CEvn_Logic * a2) {
  
  dword_3F1EE64 = *((_DWORD *)a2 + 2);
  CEcoSectorMgr::FillGoodDistribution((struct CInfoExchange *)&g_cGoodDistributionInfo);
  CLogic::SetFillDialogInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, bool))CEcoSectorMgr::FillGoodDistribution,
    (struct CInfoExchange *)&g_cGoodDistributionInfo,
    *((_BYTE *)this + 105));
  return 0;
}


// address=[0x1458a10]
// Decompiled from char __thiscall CInputProcessor::GoodDeliveringChanged(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::GoodDeliveringChanged(class CEvn_Logic * a2) {
  
  char LocalPlayerId; // al
  unsigned int v4; // [esp+10h] [ebp-B4h]
  unsigned int v5; // [esp+14h] [ebp-B0h]
  CEcoSector *v6; // [esp+24h] [ebp-A0h]
  int v7; // [esp+2Ch] [ebp-98h]
  int sum; // [esp+30h] [ebp-94h]
  int UserESInMiddleOfTheScreen; // [esp+34h] [ebp-90h]
  int v10; // [esp+38h] [ebp-8Ch]
  _DWORD *v11; // [esp+3Ch] [ebp-88h]
  int v12; // [esp+40h] [ebp-84h]
  _DWORD *v13; // [esp+44h] [ebp-80h]
  int v14; // [esp+48h] [ebp-7Ch]
  int i; // [esp+4Ch] [ebp-78h]
  int j; // [esp+4Ch] [ebp-78h]
  _BYTE v17[60]; // [esp+50h] [ebp-74h] BYREF
  int v18; // [esp+8Ch] [ebp-38h]
  _BYTE v19[32]; // [esp+94h] [ebp-30h] BYREF
  int v20; // [esp+C0h] [ebp-4h]

  v7 = dword_3F1EE64;
  UserESInMiddleOfTheScreen = CInputProcessor::GetUserESInMiddleOfTheScreen(this);
  sum = 0;
  if ( UserESInMiddleOfTheScreen )
  {
    v6 = (CEcoSector *)CEcoSectorMgr::operator[](UserESInMiddleOfTheScreen);
    CGoodDistributionInfo::CGoodDistributionInfo((CGoodDistributionInfo *)v17);
    v18 = v7;
    CEcoSector::FillGoodDistribution(v6, (struct CGoodDistributionInfo *)v17);
    v11 = operator new[](4 * dword_3F1EE30);
    v13 = operator new[](4 * dword_3F1EE30);
    v10 = 0;
    for ( i = 0; i < dword_3F1EE30; ++i )
    {
      v13[i] = dword_3F1EE3C[2 * i] - *(_DWORD *)&v17[8 * i + 20];
      v11[i] = v13[i] + *(_DWORD *)&v17[8 * i + 20];
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
      if ( ++v14 >= dword_3F1EE30 )
        v14 = 0;
    }
    for ( j = 0; j < dword_3F1EE30; ++j )
    {
      v4 = (unsigned __int16)dword_3F1EE38[2 * j] | ((unsigned __int16)v7 << 16);
      v5 = LOWORD(v13[j]) | ((unsigned __int16)UserESInMiddleOfTheScreen << 16);
      sum += v13[j] + *(_DWORD *)&v17[8 * j + 20];
      LocalPlayerId = CPlayerManager::GetLocalPlayerId();
      CEvn_Logic::CEvn_Logic((CEvn_Logic *)v19, 5028u, v4, v5, LocalPlayerId, 0, 0);
      v20 = 0;
      if ( !g_pNetworkEngine
        && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 2685, "g_pNetworkEngine != NULL") == 1 )
      {
        __debugbreak();
      }
      if ( g_pNetworkEngine )
        INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v19);
      v20 = -1;
      CEvn_Logic::~CEvn_Logic(v19);
    }
    operator delete[](v11);
    operator delete[](v13);
  }
  BBSupportTracePrintF(3, "sum = %d", sum);
  return 0;
}


// address=[0x1458d90]
// Decompiled from char __thiscall CInputProcessor::TransportPrioChanged(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::TransportPrioChanged(class CEvn_Logic * a2) {
  
  char LocalPlayerId; // al
  unsigned int v4; // [esp-8h] [ebp-50h]
  unsigned int v5; // [esp+8h] [ebp-40h]
  unsigned int UserESInMiddleOfTheScreen; // [esp+14h] [ebp-34h]
  _BYTE v8[32]; // [esp+18h] [ebp-30h] BYREF
  int v9; // [esp+44h] [ebp-4h]

  if ( !a2 && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 2581, "_pEvent != NULL") == 1 )
    __debugbreak();
  if ( !a2 )
    return 0;
  UserESInMiddleOfTheScreen = CInputProcessor::GetUserESInMiddleOfTheScreen(this);
  if ( !UserESInMiddleOfTheScreen )
    return 0;
  CEcoSectorMgr::operator[](UserESInMiddleOfTheScreen);
  v5 = (*((unsigned __int16 *)a2 + 4) << 16) | *((unsigned __int16 *)a2 + 6);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v8, 0x13A5u, v5, UserESInMiddleOfTheScreen, LocalPlayerId, v4, 0);
  v9 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 2599, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v8);
  v9 = -1;
  CEvn_Logic::~CEvn_Logic(v8);
  return 0;
}


// address=[0x1458ec0]
// Decompiled from char __thiscall CInputProcessor::UnitProduction(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::UnitProduction(class CEvn_Logic * a2) {
  
  int v2; // esi
  char LocalPlayerId; // al
  unsigned int v5; // [esp-8h] [ebp-4Ch]
  unsigned int v6; // [esp+Ch] [ebp-38h]
  _BYTE v7[32]; // [esp+14h] [ebp-30h] BYREF
  int v8; // [esp+40h] [ebp-4h]

  v2 = *((unsigned __int16 *)a2 + 4);
  v6 = (*(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0) << 16) | v2;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v7, 0x13B7u, v6, *((_DWORD *)a2 + 3), LocalPlayerId, v5, 0);
  v8 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1516, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v7);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(v7);
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
  v5 = (*(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0) << 16) | m_wParam_low;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CEvn_Logic::CEvn_Logic(&v6, 0x13A9u, v5, a2->m_lParam, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1484, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, &v6);
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
  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic(&v6, 0x13AAu, *v2, m_wParam, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1428, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, &v6);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(&v6);
  return 0;
}


// address=[0x1459180]
// Decompiled from char __thiscall CInputProcessor::WeaponAutoproduction(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::WeaponAutoproduction(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  unsigned int v4; // [esp-10h] [ebp-4Ch]
  char LocalPlayerId; // [esp-Ch] [ebp-48h]
  unsigned int v6; // [esp-8h] [ebp-44h]
  _BYTE v7[32]; // [esp+Ch] [ebp-30h] BYREF
  int v8; // [esp+38h] [ebp-4h]

  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  v4 = *((_DWORD *)a2 + 3);
  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v7, 0x13ABu, *v2, v4, LocalPlayerId, v6, 0);
  v8 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1454, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v7);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(v7);
  return 0;
}


// address=[0x1459260]
// Decompiled from char __thiscall CInputProcessor::StorageGoodSwitch(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::StorageGoodSwitch(class CEvn_Logic * a2) {
  
  int v2; // esi
  char LocalPlayerId; // al
  unsigned int v5; // [esp-8h] [ebp-4Ch]
  unsigned int v6; // [esp+Ch] [ebp-38h]
  _BYTE v7[32]; // [esp+14h] [ebp-30h] BYREF
  int v8; // [esp+40h] [ebp-4h]

  v2 = *((unsigned __int16 *)a2 + 4);
  v6 = (*(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0) << 16) | v2;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v7, 0x13B4u, v6, *((_DWORD *)a2 + 3), LocalPlayerId, v5, 0);
  v8 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1404, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v7);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(v7);
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
  v5 = (*(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0) << 16) | m_wParam_low;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CEvn_Logic::CEvn_Logic(&v6, 0x13B0u, v5, a2->m_lParam, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1373, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, &v6);
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
    *((_BYTE *)this + 105));
  v5 = -1;
  CEvn_Event::~CEvn_Event(&v4);
  return 0;
}


// address=[0x1459540]
// Decompiled from char __thiscall CInputProcessor::SwitchLocalGlobal(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SwitchLocalGlobal(class CEvn_Logic * a2) {
  
  *((_BYTE *)this + 105) = *((_BYTE *)this + 105) == 0;
  CLogic::SetLocalGlobalSwitch(g_pLogic, *((_BYTE *)this + 105));
  return 0;
}


// address=[0x1459590]
// Decompiled from char __thiscall CInputProcessor::SpecialistProduction(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SpecialistProduction(class CEvn_Logic * a2) {
  
  char LocalPlayerId; // al
  unsigned int v4; // [esp-8h] [ebp-4Ch]
  unsigned int v5; // [esp+4h] [ebp-40h]
  int UserESInMiddleOfTheScreen; // [esp+Ch] [ebp-38h]
  _BYTE v7[32]; // [esp+14h] [ebp-30h] BYREF
  int v8; // [esp+40h] [ebp-4h]

  UserESInMiddleOfTheScreen = CInputProcessor::GetUserESInMiddleOfTheScreen(this);
  if ( !UserESInMiddleOfTheScreen )
    return 0;
  v5 = ((unsigned __int16)UserESInMiddleOfTheScreen << 16) | *((unsigned __int16 *)a2 + 4);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v7, 0x13AFu, v5, *((_DWORD *)a2 + 3), LocalPlayerId, v4, 0);
  v8 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1549, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v7);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(v7);
  return 0;
}


// address=[0x1459690]
// Decompiled from char __thiscall CInputProcessor::PrepareBoxSelection(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::PrepareBoxSelection(class CEvn_Logic * a2) {
  
  DWORD *xLeft; // eax
  DWORD *xRight; // eax
  DWORD *yTop; // eax
  DWORD *yBottom; // eax
  CEvn_Event *v7; // [esp+4h] [ebp-54h]
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
  CEvn_Event *v8; // [esp+4h] [ebp-68h]
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
        v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
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
      std::vector<unsigned short>::push_back(&CInputProcessor::m_vSelection, (int)&v15);
      if ( v22 )
      {
        IEntity::SetFlagBits(entity, (EntityFlag)1024);
      }
      else
      {
        IEntity::SetFlagBits(entity, EntityFlag_Selected);
        if ( IEntity::ObjType(entity) == 8 )    // == Building
        {
          CSoundManager::PlaySoundFX(g_pSoundManager, 7);
          v5 = std::vector<unsigned short>::size(&CInputProcessor::m_vSelection);
          v6 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, v5 - 1);
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
  __int64 packedXY; // [esp+0h] [ebp-14h]
  struct IEntity *v6; // [esp+8h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-8h]

  LODWORD(packedXY) = LOWORD(a2->m_lParam);
  HIDWORD(packedXY) = HIWORD(a2->m_lParam);
  CInputProcessor::DeSelectAll(this);
  if ( !this->unk_C )
  {
    v7 = CInputProcessor::SelectOne(this, packedXY);
    if ( v7 )
    {
      this->m_iSelectionType = CInputProcessor::GetEntitySelectionType(v7);
      this->m_iSelectionStrict = 2;
      v6 = CMapObjectMgr::Entity(v7);
      v4 = IEntity::Y(v6);
      v2 = IEntity::X(v6);
      dword_3F1F60C = CWorldManager::SectorId(v2, v4);
      dword_3F1F608 = a2->m_wParam & 0x10;
      CInputProcessor::SelectAllInSurrounding(this, packedXY, SHIDWORD(packedXY));
    }
  }
  CLogic::SetFillDialogInfos(g_pLogic, 0, 0, 0);
  CInputProcessor::RequestDialog(this);
  return 1;
}


// address=[0x1459c50]
// Decompiled from char __thiscall CInputProcessor::SelectGroup(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SelectGroup(class CEvn_Logic * a2) {
  
  int v3; // [esp+0h] [ebp-34h]
  int SelectionTypeOfCurrentSelection; // [esp+4h] [ebp-30h]
  int v5; // [esp+8h] [ebp-2Ch]
  int v6; // [esp+Ch] [ebp-28h]
  struct IEntity *v7; // [esp+10h] [ebp-24h]
  unsigned __int16 *v8; // [esp+14h] [ebp-20h]
  int v9; // [esp+18h] [ebp-1Ch]
  int LocalPlayerId; // [esp+20h] [ebp-14h]
  int i; // [esp+28h] [ebp-Ch]
  int v13; // [esp+2Ch] [ebp-8h]
  __int16 v14; // [esp+30h] [ebp-4h] BYREF
  bool v15; // [esp+33h] [ebp-1h]

  if ( !a2 && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3203, "_pEvent!=0") == 1 )
    __debugbreak();
  v13 = *((_DWORD *)a2 + 2);
  v5 = *((_DWORD *)a2 + 3);
  if ( v13 < 1 || v13 > 10 )
    return 0;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(v3);
  v9 = (*(int (__thiscall **)(void *, int, int))(*(_DWORD *)g_pGroupMgr + 12))(g_pGroupMgr, LocalPlayerId, v13);
  if ( v9 <= 0 )
    return 0;
  *((_DWORD *)this + 6) = v13;
  v8 = (unsigned __int16 *)(*(int (__thiscall **)(void *, int, int))(*(_DWORD *)g_pGroupMgr + 16))(
                             g_pGroupMgr,
                             LocalPlayerId,
                             v13);
  v15 = 1;
  if ( v5 )
  {
    SelectionTypeOfCurrentSelection = CInputProcessor::GetSelectionTypeOfCurrentSelection(this);
    v15 = SelectionTypeOfCurrentSelection != CInputProcessor::GetEntitySelectionType(*v8);
  }
  if ( v15 )
    CInputProcessor::DeSelectAll(this);
  for ( i = 0; i < v9 && (unsigned int)std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) < 0x64; ++i )
  {
    v6 = v8[i];
    v7 = CMapObjectMgr::Entity(v6);
    if ( IEntity::FlagBits(v7, EntityFlag_Selectable) )
    {
      IEntity::SetFlagBits(v7, EntityFlag_Selected);
      v14 = v6;
      std::vector<unsigned short>::push_back(&v14);
    }
  }
  CInputProcessor::RequestDialog();
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
    v4[i] = *(_WORD *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, i);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CEvn_Logic::CEvn_Logic(&v8, 0x13B1u, iGroupId, 0, LocalPlayerId, (uint)v4, (unsigned __int8)(2 * iSelectionSize));
  v9 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3131, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, &v8);
  v9 = -1;
  CEvn_Logic::~CEvn_Logic(&v8);
  return 0;
}


// address=[0x1459fd0]
// Decompiled from char __thiscall CInputProcessor::FocusGroup(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::FocusGroup(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  unsigned __int8 *v3; // eax
  unsigned __int16 *v4; // eax
  int v5; // esi
  int v7; // [esp+0h] [ebp-4Ch]
  unsigned __int8 *v8; // [esp+10h] [ebp-3Ch]
  int v9; // [esp+14h] [ebp-38h]
  int v10; // [esp+18h] [ebp-34h]
  int v11; // [esp+1Ch] [ebp-30h]
  unsigned int i; // [esp+20h] [ebp-2Ch]
  CEvn_Event v13; // [esp+24h] [ebp-28h] BYREF
  int v14; // [esp+48h] [ebp-4h]

  if ( *((_DWORD *)a2 + 2) > 0xAu
    && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3149, "iGroupId >= 0 && iGroupId <= MAX_GROUPS") == 1 )
  {
    __debugbreak();
  }
  if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    return 0;
  v10 = 0;
  v9 = 0;
  v11 = 0;
  for ( i = 0; i < std::vector<unsigned short>::size(&CInputProcessor::m_vSelection); ++i )
  {
    v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, i);
    v3 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(*v2);
    if ( IEntity::ObjType(v3) != 8 )
    {
      v4 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, i);
      v8 = (unsigned __int8 *)CMapObjectMgr::MovingEntity(*v4);
      v5 = IEntity::OwnerId(v8);
      if ( v5 == CPlayerManager::GetLocalPlayerId(v7) )
      {
        v10 += IEntity::X(v8);
        v9 += IEntity::Y(v8);
        ++v11;
      }
    }
  }
  if ( !v11 )
    return 0;
  CEvn_Event::CEvn_Event(&v13, 0x13u, v9 / v11, v10 / v11, 0);
  v14 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3184, "g_pEvnEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v13);
  v14 = -1;
  CEvn_Event::~CEvn_Event(&v13);
  return 0;
}


// address=[0x145a1a0]
// Decompiled from char __thiscall CInputProcessor::SendTo(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SendTo(class CEvn_Logic * a2) {
  
  unsigned __int16 *v3; // eax
  unsigned __int8 *v4; // eax
  unsigned __int16 *v5; // eax
  _DWORD *v6; // eax
  int v7; // [esp+0h] [ebp-64h]
  char LocalPlayerId; // [esp+4h] [ebp-60h]
  unsigned int v9; // [esp+10h] [ebp-54h]
  _WORD *v10; // [esp+14h] [ebp-50h]
  int v12; // [esp+1Ch] [ebp-48h]
  int v13; // [esp+20h] [ebp-44h]
  int v14; // [esp+28h] [ebp-3Ch]
  signed int i; // [esp+2Ch] [ebp-38h]
  int v16; // [esp+30h] [ebp-34h]
  _BYTE v17[32]; // [esp+34h] [ebp-30h] BYREF
  int v18; // [esp+60h] [ebp-4h]

  LocalPlayerId = CPlayerManager::GetLocalPlayerId(v7);
  v14 = *((_DWORD *)a2 + 3);
  if ( (*((_DWORD *)a2 + 2) & 4) != 0 )
    v13 = 2;
  else
    v13 = 0;
  if ( (*((_DWORD *)a2 + 2) & 0x10) != 0 )
    v12 = 4;
  else
    v12 = 0;
  v9 = v12 | v13 | ((*((_DWORD *)a2 + 2) & 8) != 0);
  if ( v14 >= 0 )
  {
    if ( !v14 || !(unsigned __int8)CWorldManager::InWorldPackedXY(v14) )
      return 1;
  }
  else
  {
    v9 = 8;
  }
  v16 = std::vector<unsigned short>::size(&CInputProcessor::m_vSelection);
  if ( v16 <= 0 )
    return 1;
  v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  v4 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(*v3);
  if ( IEntity::ObjType(v4) == 8
    || (v5 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0),
        v6 = (_DWORD *)CMapObjectMgr::EntityPtr(*v5),
        IEntity::FlagBits(v6, (EntityFlag)0x4000u)) )
  {
    CInputProcessor::Clear(this);
    return 0;
  }
  if ( v16 > 100
    && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3352, "iSelectionSize <= MAX_SELECTED_ENTITIES") == 1 )
  {
    __debugbreak();
  }
  if ( v16 > 100 )
    v16 = 100;
  v10 = operator new[](2 * v16);
  for ( i = 0; i < v16; ++i )
    v10[i] = *(_WORD *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, i);
  if ( g_pNetworkEngine )
  {
    CEvn_Logic::CEvn_Logic((CEvn_Logic *)v17, 0x1396u, v14, v9, LocalPlayerId, (unsigned int)v10, 2 * v16);
    v18 = 0;
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v17);
    v18 = -1;
    CEvn_Logic::~CEvn_Logic(v17);
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
// Decompiled from bool __thiscall CInputProcessor::StandGround(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::StandGround(class CEvn_Logic * a2) {
  
  *((_DWORD *)a2 + 3) = -1;
  return CInputProcessor::SendTo(this, a2);
}


// address=[0x145a450]
// Decompiled from char __thiscall CInputProcessor::ChooseSecondPatrolPos(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::ChooseSecondPatrolPos(class CEvn_Logic * a2) {
  
  *((_DWORD *)this + 20) = 9;
  IGfxEngine::EnableIconLayer((IGfxEngine *)g_pGfxEngine, 1);
  return 1;
}


// address=[0x145a480]
// Decompiled from char __thiscall CInputProcessor::SelectSecondPatrolPos(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SelectSecondPatrolPos(class CEvn_Logic * a2) {
  
  *((_DWORD *)a2 + 2) = 0;
  *((_DWORD *)a2 + 2) |= 8u;
  CInputProcessor::SendTo(this, a2);
  CInputProcessor::Default(this, a2);
  CFsm::GenerateEvent(401, 0);
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
  CInputProcessor *v9; // [esp+30h] [ebp-4Ch]
  int v10; // [esp+34h] [ebp-48h]
  int v11; // [esp+38h] [ebp-44h]
  int v12; // [esp+3Ch] [ebp-40h]
  int v13; // [esp+40h] [ebp-3Ch]
  int SettlerInfo; // [esp+44h] [ebp-38h]
  int v15; // [esp+48h] [ebp-34h]
  int v16; // [esp+4Ch] [ebp-30h]
  int v17; // [esp+50h] [ebp-2Ch]
  std::_Iterator_base12 *v18; // [esp+54h] [ebp-28h]
  std::_Iterator_base12 *v19; // [esp+58h] [ebp-24h]
  int v20; // [esp+5Ch] [ebp-20h]
  BOOL v21; // [esp+60h] [ebp-1Ch]
  unsigned __int8 *SettlerPtr; // [esp+64h] [ebp-18h]
  char v23; // [esp+6Ah] [ebp-12h]
  char v24; // [esp+6Bh] [ebp-11h]
  char v25; // [esp+6Ch] [ebp-10h]
  bool v26; // [esp+6Dh] [ebp-Fh]
  char v27; // [esp+6Eh] [ebp-Eh]
  bool v28; // [esp+6Fh] [ebp-Dh]
  int v29; // [esp+78h] [ebp-4h]

  v9 = this;
  v20 = *((unsigned __int8 *)a2 + 30);
  v28 = *((_DWORD *)a2 + 2) != 0;
  v23 = v28;
  if ( v20 != CPlayerManager::GetLocalPlayerId(v3[3])
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
    SettlerPtr = CSettlerMgr::GetSettlerPtr(v17);
    if ( SettlerPtr )
    {
      v15 = IEntity::Race(SettlerPtr);
      v16 = IEntity::Type((unsigned __int16 *)SettlerPtr);
      SettlerInfo = CSettlerMgr::GetSettlerInfo(v15, v16);
      v13 = *(unsigned __int8 *)(SettlerInfo + 2);
      v12 = IEntity::Hitpoints((IEntity *)SettlerPtr);
      v27 = v12 < v13 >> 1;
      v24 = v27;
      v21 = v27 == v23;
      v26 = v27 == v23;
    }
    if ( v26 )
    {
      IEntity::ClearFlagBits(SettlerPtr, (EntityFlag)0x600u);
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
  
  char LocalPlayerId; // al
  unsigned int v4; // [esp-8h] [ebp-54h]
  _WORD *v5; // [esp+Ch] [ebp-40h]
  int v6; // [esp+10h] [ebp-3Ch]
  unsigned int i; // [esp+14h] [ebp-38h]
  _BYTE v8[32]; // [esp+1Ch] [ebp-30h] BYREF
  int v9; // [esp+48h] [ebp-4h]

  v6 = std::vector<unsigned short>::size(&CInputProcessor::m_vSelection);
  if ( v6 <= 0 )
    return 0;
  if ( v6 > 100
    && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3533, "iSelectionSize <= MAX_SELECTED_ENTITIES") == 1 )
  {
    __debugbreak();
  }
  v5 = operator new[](2 * v6);
  for ( i = 0; i < std::vector<unsigned short>::size(&CInputProcessor::m_vSelection); ++i )
    v5[i] = *(_WORD *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, i);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(v5);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v8, 0x139Du, 0, 0, LocalPlayerId, v4, (unsigned __int8)(2 * v6));
  v9 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3557, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v8);
  v9 = -1;
  CEvn_Logic::~CEvn_Logic(v8);
  return 1;
}


// address=[0x145a860]
// Decompiled from char __thiscall CInputProcessor::SearchUnit(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SearchUnit(class CEvn_Logic * a2) {
  
  int LocalPlayerId; // eax
  unsigned __int16 *v4; // eax
  int v5; // eax
  int v6; // eax
  unsigned int v7; // eax
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
  unsigned int v30; // [esp-8h] [ebp-A0h]
  unsigned int v31; // [esp-8h] [ebp-A0h]
  int v32; // [esp-4h] [ebp-9Ch]
  int v33; // [esp-4h] [ebp-9Ch]
  int v34; // [esp+0h] [ebp-98h]
  int v35; // [esp+0h] [ebp-98h]
  CEvn_Event *v36; // [esp+8h] [ebp-90h]
  CEvn_Event *v37; // [esp+10h] [ebp-88h]
  _DWORD *v38; // [esp+24h] [ebp-74h]
  int v39; // [esp+28h] [ebp-70h] BYREF
  int v40; // [esp+2Ch] [ebp-6Ch] BYREF
  unsigned __int8 *v41; // [esp+30h] [ebp-68h]
  int v42; // [esp+34h] [ebp-64h]
  __int16 v43; // [esp+3Ah] [ebp-5Eh] BYREF
  int v44; // [esp+3Ch] [ebp-5Ch]
  unsigned __int8 *SettlerPtr; // [esp+40h] [ebp-58h]
  int FirstSettlerId; // [esp+44h] [ebp-54h]
  int v47; // [esp+48h] [ebp-50h]
  int v48; // [esp+4Ch] [ebp-4Ch]
  CInputProcessor *v49; // [esp+50h] [ebp-48h]
  char v50; // [esp+57h] [ebp-41h]
  CEvn_Event v51; // [esp+58h] [ebp-40h] BYREF
  CEvn_Event v52; // [esp+70h] [ebp-28h] BYREF
  int v53; // [esp+94h] [ebp-4h]

  v49 = this;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(v34);
  if ( !CPlayerManager::IsAlive(LocalPlayerId) )
    return 0;
  v48 = *((_DWORD *)a2 + 2);
  if ( (v48 <= 0 || v48 >= 67)
    && BBSupportDbgReport(
         2,
         "Logic\\InputProcessor.cpp",
         2834,
         "iSettlerType > SETTLER_NO_SETTLER && iSettlerType < SETTLER_MAX") == 1 )
  {
    __debugbreak();
  }
  v42 = *((_DWORD *)a2 + 3);
  if ( v42 )
  {
    if ( v42 == 1 )
    {
      CInputProcessor::DeSelectAll(v49);
      *((_BYTE *)v49 + 52) = 1;
      *((_BYTE *)v49 + 106) = 1;
      v8 = CSettlerMgr::SettlerWarriorType(v48);
      *((_DWORD *)v49 + 19) = CInputProcessor::GetEntitySelectionType(1, v48, v8);
      *((_DWORD *)v49 + 25) = 2;
      *((_DWORD *)v49 + 14) = CPlayerManager::GetLocalPlayerId(v35);
      *((_DWORD *)v49 + 15) = 1;
      *((_DWORD *)v49 + 17) = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
      *((_DWORD *)v49 + 16) = 1;
      *((_DWORD *)v49 + 18) = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine);
    }
    else if ( v42 == 2 )
    {
      CInputProcessor::DeSelectAll(v49);
      v39 = 0;
      v40 = 0;
      CStateGame::GetCenterWorldCoordinate((CStateGame *)g_pGame, &v39, &v40);
      v50 = 0;
      if ( (unsigned __int8)CWorldManager::InWorld(v39, v40) )
      {
        v47 = CWorldManager::SectorId(v39, v40);
        if ( v47 > 0 )
        {
          v44 = v48 - 29;
          switch ( v48 )
          {
            case 29:
              v18 = v50;
              v50 = CInputProcessor::SelectAtSector(v49, 29, v47) | v18;
              v19 = v50;
              v50 = CInputProcessor::SelectAtSector(v49, 30, v47) | v19;
              v20 = v50;
              v50 = CInputProcessor::SelectAtSector(v49, 31, v47) | v20;
              break;
            case 32:
              v21 = v50;
              v50 = CInputProcessor::SelectAtSector(v49, 32, v47) | v21;
              v22 = v50;
              v50 = CInputProcessor::SelectAtSector(v49, 33, v47) | v22;
              v23 = v50;
              v50 = CInputProcessor::SelectAtSector(v49, 34, v47) | v23;
              break;
            case 35:
              v15 = v50;
              v50 = CInputProcessor::SelectAtSector(v49, 35, v47) | v15;
              v16 = v50;
              v50 = CInputProcessor::SelectAtSector(v49, 36, v47) | v16;
              v17 = v50;
              v50 = CInputProcessor::SelectAtSector(v49, 37, v47) | v17;
              break;
            case 38:
              v9 = v50;
              v50 = CInputProcessor::SelectAtSector(v49, 38, v47) | v9;
              v10 = v50;
              v50 = CInputProcessor::SelectAtSector(v49, 39, v47) | v10;
              v11 = v50;
              v50 = CInputProcessor::SelectAtSector(v49, 40, v47) | v11;
              break;
            case 41:
              v12 = v50;
              v50 = CInputProcessor::SelectAtSector(v49, 41, v47) | v12;
              v13 = v50;
              v50 = CInputProcessor::SelectAtSector(v49, 42, v47) | v13;
              v14 = v50;
              v50 = CInputProcessor::SelectAtSector(v49, 43, v47) | v14;
              break;
            case 61:
              v24 = v50;
              v50 = CInputProcessor::SelectAtSector(v49, 61, v47) | v24;
              v25 = v50;
              v50 = CInputProcessor::SelectAtSector(v49, 62, v47) | v25;
              v26 = v50;
              v50 = CInputProcessor::SelectAtSector(v49, 63, v47) | v26;
              goto CInputProcessor__SearchUnit___def_185AC66;
            default:
CInputProcessor__SearchUnit___def_185AC66:
              v27 = v50;
              v50 = CInputProcessor::SelectAtSector(v49, v48, v47) | v27;
              break;
          }
        }
      }
      if ( v50 )
      {
        v28 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
        v38 = (_DWORD *)CMapObjectMgr::EntityPtr(*v28);
        v31 = IEntity::X(v38);
        v29 = IEntity::Y(v38);
        v36 = CEvn_Event::CEvn_Event(&v51, 0x13u, v29, v31, 0);
        v53 = 1;
        IEventEngine::SendAMessage(g_pEvnEngine, v36);
        v53 = -1;
        CEvn_Event::~CEvn_Event(&v51);
      }
      else
      {
        CInputProcessor::Default(v49, a2);
        CFsm::GenerateEvent(401, 0);
      }
    }
  }
  else
  {
    FirstSettlerId = 0;
    if ( std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) == 1 )
    {
      v4 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
      v41 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(*v4);
      if ( IEntity::ObjType(v41) == 1 && IEntity::Type((unsigned __int16 *)v41) == v48 )
        FirstSettlerId = IAnimatedEntity::Next(v41);
    }
    do
    {
      if ( !FirstSettlerId )
      {
        v5 = CPlayerManager::GetLocalPlayerId(v48);
        FirstSettlerId = CSettlerMgr::GetFirstSettlerId((CSettlerMgr *)g_cSettlerMgr, v5, v32);
      }
      if ( !FirstSettlerId
        && (v48 == 29
         || v48 == 30
         || v48 == 32
         || v48 == 33
         || v48 == 35
         || v48 == 36
         || v48 == 38
         || v48 == 39
         || v48 == 41
         || v48 == 42) )
      {
        ++v48;
      }
      if ( !FirstSettlerId )
      {
        v6 = CPlayerManager::GetLocalPlayerId(v48);
        FirstSettlerId = CSettlerMgr::GetFirstSettlerId((CSettlerMgr *)g_cSettlerMgr, v6, v33);
      }
    }
    while ( !FirstSettlerId
         && (v48 == 29
          || v48 == 30
          || v48 == 32
          || v48 == 33
          || v48 == 35
          || v48 == 36
          || v48 == 38
          || v48 == 39
          || v48 == 41
          || v48 == 42) );
    if ( FirstSettlerId > 0 )
    {
      CInputProcessor::DeSelectAll(v49);
      SettlerPtr = CSettlerMgr::GetSettlerPtr(FirstSettlerId);
      if ( !SettlerPtr && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 2908, "pSettler != NULL") == 1 )
        __debugbreak();
      if ( SettlerPtr )
      {
        IEntity::SetFlagBits(SettlerPtr, EntityFlag_Selected);
        v43 = FirstSettlerId;
        std::vector<unsigned short>::push_back(&v43);
        v30 = IEntity::X(SettlerPtr);
        v7 = IEntity::Y(SettlerPtr);
        v37 = CEvn_Event::CEvn_Event(&v52, 0x13u, v7, v30, 0);
        v53 = 0;
        IEventEngine::SendAMessage(g_pEvnEngine, v37);
        v53 = -1;
        CEvn_Event::~CEvn_Event(&v52);
        return 0;
      }
    }
    CInputProcessor::Default(v49, a2);
    CFsm::GenerateEvent(401, 0);
  }
  return 0;
}


// address=[0x145af70]
// Decompiled from char __thiscall CInputProcessor::UnitReservation(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::UnitReservation(class CEvn_Logic * a2) {
  
  char LocalPlayerId; // al
  unsigned int v4; // [esp-8h] [ebp-4Ch]
  unsigned int v5; // [esp+4h] [ebp-40h]
  int UserESInMiddleOfTheScreen; // [esp+Ch] [ebp-38h]
  _BYTE v7[32]; // [esp+14h] [ebp-30h] BYREF
  int v8; // [esp+40h] [ebp-4h]

  UserESInMiddleOfTheScreen = CInputProcessor::GetUserESInMiddleOfTheScreen(this);
  if ( !UserESInMiddleOfTheScreen )
    return 0;
  v5 = ((unsigned __int16)UserESInMiddleOfTheScreen << 16) | *((unsigned __int16 *)a2 + 4);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v7, 0x13A3u, v5, *((_DWORD *)a2 + 3), LocalPlayerId, v4, 0);
  v8 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 2767, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v7);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(v7);
  return 0;
}


// address=[0x145b070]
// Decompiled from char __thiscall CInputProcessor::InitEconomyGameMenu(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitEconomyGameMenu(class CEvn_Logic * a2) {
  
  CStatistic::FillEconomyGameMenu();
  CLogic::SetFillDialogInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, bool))CStatistic::FillEconomyGameMenu,
    (struct CInfoExchange *)&g_cEconomyGameInfo,
    1);
  return 1;
}


// address=[0x145b0b0]
// Decompiled from char __thiscall CInputProcessor::InitMagicSideBar(CInputProcessor *this, CEvn_Logic *a2)
bool  CInputProcessor::InitMagicSideBar(class CEvn_Logic * a2) {
  
  this->unk_14 = -1;
  IGroupMgr::FillMagicSideBar(&g_cMagicSpellSideBarInfo, 0, 0);
  CLogic::SetFillSideBarInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, int))IGroupMgr::FillMagicSideBar,
    (struct CInfoExchange *)&g_cMagicSpellSideBarInfo,
    0);
  return 0;
}


// address=[0x145b100]
// Decompiled from char __thiscall CInputProcessor::InitGroupSideBar(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitGroupSideBar(class CEvn_Logic * a2) {
  
  IGroupMgr::FillGroupSideBar((struct CInfoExchange *)&g_cGroupSideBarInfo, 0, 0);
  CLogic::SetFillSideBarInfos(g_pLogic, IGroupMgr::FillGroupSideBar, (struct CInfoExchange *)&g_cGroupSideBarInfo, 0);
  return 0;
}


// address=[0x145b140]
// Decompiled from char __thiscall CInputProcessor::InitAddSoldierSideBar(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitAddSoldierSideBar(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax

  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CBuildingMgr::FillAddSoldierSideBar((struct CInfoExchange *)&g_cAddSoldierSideBarInfo, 0, *v2);
  v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CLogic::SetFillSideBarInfos(
    g_pLogic,
    CBuildingMgr::FillAddSoldierSideBar,
    (struct CInfoExchange *)&g_cAddSoldierSideBarInfo,
    *v3);
  return 0;
}


// address=[0x145b1a0]
// Decompiled from char __thiscall CInputProcessor::InitToolSideBar(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitToolSideBar(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax

  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CBuildingMgr::FillToolSideBar((struct CInfoExchange *)&g_cAddToolSideBarInfo, 0, *v2);
  v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CLogic::SetFillSideBarInfos(
    g_pLogic,
    CBuildingMgr::FillToolSideBar,
    (struct CInfoExchange *)&g_cAddToolSideBarInfo,
    *v3);
  return 0;
}


// address=[0x145b200]
// Decompiled from char __thiscall CInputProcessor::InitWeaponSideBar(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitWeaponSideBar(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax

  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CBuildingMgr::FillWeaponSideBar((int)&g_cWeaponSideBarInfo, 0, *v2);
  v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CLogic::SetFillSideBarInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, int))CBuildingMgr::FillWeaponSideBar,
    (struct CInfoExchange *)&g_cWeaponSideBarInfo,
    *v3);
  return 0;
}


// address=[0x145b260]
// Decompiled from char __thiscall CInputProcessor::InitGoodsOutSideBar(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitGoodsOutSideBar(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax

  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CBuildingMgr::FillGoodsOutSideBar((struct CInfoExchange *)&g_cPortGoodsOutBarInfo, 0, *v2);
  v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CLogic::SetFillSideBarInfos(
    g_pLogic,
    CBuildingMgr::FillGoodsOutSideBar,
    (struct CInfoExchange *)&g_cPortGoodsOutBarInfo,
    *v3);
  return 0;
}


// address=[0x145b2c0]
// Decompiled from char __thiscall CInputProcessor::InitTradeSideBar(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitTradeSideBar(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax

  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CBuildingMgr::FillTradeSideBar((struct CInfoExchange *)&g_cPortTradeBarInfo, 0, *v2);
  v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CLogic::SetFillSideBarInfos(
    g_pLogic,
    CBuildingMgr::FillTradeSideBar,
    (struct CInfoExchange *)&g_cPortTradeBarInfo,
    *v3);
  return 0;
}


// address=[0x145b320]
// Decompiled from char __thiscall CInputProcessor::InitStorageSideBar(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitStorageSideBar(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax

  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CBuildingMgr::FillStorageSideBar((struct CInfoExchange *)&g_cStorageSideBarInfo, 0, *v2);
  v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CLogic::SetFillSideBarInfos(
    g_pLogic,
    CBuildingMgr::FillStorageSideBar,
    (struct CInfoExchange *)&g_cStorageSideBarInfo,
    *v3);
  return 0;
}


// address=[0x145b380]
// Decompiled from char __thiscall CInputProcessor::InitEyeCatcherSideBar(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitEyeCatcherSideBar(class CEvn_Logic * a2) {
  
  CWorldManager::ClearHelperObject(this);
  CBuildingMgr::FillEyeCatcherSideBar((struct CInfoExchange *)&g_cEyeCatcherBarInfo, 0);
  CLogic::SetFillSideBarInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, int))CBuildingMgr::FillEyeCatcherSideBar,
    (struct CInfoExchange *)&g_cEyeCatcherBarInfo,
    0);
  return 0;
}


// address=[0x145b3c0]
// Decompiled from char __thiscall CInputProcessor::InitAddVehicleSideBar(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitAddVehicleSideBar(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax

  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CBuildingMgr::FillAddVehicleSideBar((struct CInfoExchange *)&g_cVehicleSideBarInfo, 0, *v2);
  v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CLogic::SetFillSideBarInfos(
    g_pLogic,
    CBuildingMgr::FillAddVehicleSideBar,
    (struct CInfoExchange *)&g_cVehicleSideBarInfo,
    *v3);
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
  char LocalPlayerId; // [esp-Ch] [ebp-48h]
  unsigned int v5; // [esp-8h] [ebp-44h]
  _BYTE v7[32]; // [esp+Ch] [ebp-30h] BYREF
  int v8; // [esp+38h] [ebp-4h]

  if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    return 0;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v7, 0x1394u, *v2, 0, LocalPlayerId, v5, 0);
  v8 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3699, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
  {
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v7);
    v8 = -1;
    CEvn_Logic::~CEvn_Logic(v7);
    return 1;
  }
  CInputProcessor::Clear(this);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(v7);
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
  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic(&v6, 0x1393u, *v2, 0, LocalPlayerId, 0, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3757, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, &v6);
  CInputProcessor::Clear(this);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(&v6);
  return 1;
}


// address=[0x145b630]
// Decompiled from char __thiscall CInputProcessor::Morph2Cart(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::Morph2Cart(class CEvn_Logic * a2) {
  
  unsigned __int16 *v2; // eax
  char LocalPlayerId; // [esp-Ch] [ebp-48h]
  unsigned int v5; // [esp-8h] [ebp-44h]
  _BYTE v7[32]; // [esp+Ch] [ebp-30h] BYREF
  int v8; // [esp+38h] [ebp-4h]

  if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    return 0;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v7, 0x1395u, *v2, 0, LocalPlayerId, v5, 0);
  v8 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3723, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
  {
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v7);
    v8 = -1;
    CEvn_Logic::~CEvn_Logic(v7);
    return 1;
  }
  CInputProcessor::DeSelectAll(this);
  CFsm::GenerateEvent(401, 0);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(v7);
  return 0;
}


// address=[0x145b740]
// Decompiled from char __thiscall CInputProcessor::VehicleUnload(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::VehicleUnload(class CEvn_Logic * a2) {
  
  char LocalPlayerId; // al
  unsigned int v4; // [esp-8h] [ebp-7Ch]
  _BYTE v5[12]; // [esp+4h] [ebp-70h] BYREF
  _BYTE v6[12]; // [esp+10h] [ebp-64h] BYREF
  CInputProcessor *v7; // [esp+1Ch] [ebp-58h]
  _BYTE v8[12]; // [esp+20h] [ebp-54h] BYREF
  unsigned int v9; // [esp+2Ch] [ebp-48h]
  std::_Iterator_base12 *v10; // [esp+30h] [ebp-44h]
  std::_Iterator_base12 *v11; // [esp+34h] [ebp-40h]
  int v12; // [esp+38h] [ebp-3Ch]
  int v13; // [esp+3Ch] [ebp-38h]
  char v14; // [esp+43h] [ebp-31h]
  _BYTE v15[32]; // [esp+44h] [ebp-30h] BYREF
  int v16; // [esp+70h] [ebp-4h]

  v7 = this;
  if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection)
    && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3777, "m_vSelection.size() > 0") == 1 )
  {
    __debugbreak();
  }
  if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    return 1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v8);
  v16 = 0;
  v13 = std::vector<unsigned short>::begin(v6);
  v12 = v13;
  LOBYTE(v16) = 1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator=(v13);
  LOBYTE(v16) = 0;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v6);
  while ( 1 )
  {
    v11 = (std::_Iterator_base12 *)std::vector<unsigned short>::end(v5);
    v10 = v11;
    LOBYTE(v16) = 2;
    v14 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator!=(v11);
    LOBYTE(v16) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v5);
    if ( !v14 )
      break;
    v9 = *(unsigned __int16 *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator*(v8);
    LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
    CEvn_Logic::CEvn_Logic((CEvn_Logic *)v15, 0x1391u, v9, 0, LocalPlayerId, v4, 0);
    LOBYTE(v16) = 3;
    if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3794, "g_pNetworkEngine != NULL") == 1 )
      __debugbreak();
    if ( g_pNetworkEngine )
      INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v15);
    LOBYTE(v16) = 0;
    CEvn_Logic::~CEvn_Logic(v15);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator++(v8);
  }
  v16 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v8);
  return 1;
}


// address=[0x145b8f0]
// Decompiled from char __thiscall CInputProcessor::CatapultLoad(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::CatapultLoad(class CEvn_Logic * a2) {
  
  char LocalPlayerId; // al
  unsigned int v4; // [esp-8h] [ebp-7Ch]
  _BYTE v5[12]; // [esp+4h] [ebp-70h] BYREF
  _BYTE v6[12]; // [esp+10h] [ebp-64h] BYREF
  CInputProcessor *v7; // [esp+1Ch] [ebp-58h]
  _BYTE v8[12]; // [esp+20h] [ebp-54h] BYREF
  unsigned int v9; // [esp+2Ch] [ebp-48h]
  std::_Iterator_base12 *v10; // [esp+30h] [ebp-44h]
  std::_Iterator_base12 *v11; // [esp+34h] [ebp-40h]
  int v12; // [esp+38h] [ebp-3Ch]
  int v13; // [esp+3Ch] [ebp-38h]
  char v14; // [esp+43h] [ebp-31h]
  _BYTE v15[32]; // [esp+44h] [ebp-30h] BYREF
  int v16; // [esp+70h] [ebp-4h]

  v7 = this;
  if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection)
    && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3806, "m_vSelection.size() > 0") == 1 )
  {
    __debugbreak();
  }
  if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    return 1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v8);
  v16 = 0;
  v13 = std::vector<unsigned short>::begin(v6);
  v12 = v13;
  LOBYTE(v16) = 1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator=(v13);
  LOBYTE(v16) = 0;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v6);
  while ( 1 )
  {
    v11 = (std::_Iterator_base12 *)std::vector<unsigned short>::end(v5);
    v10 = v11;
    LOBYTE(v16) = 2;
    v14 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator!=(v11);
    LOBYTE(v16) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v5);
    if ( !v14 )
      break;
    v9 = *(unsigned __int16 *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator*(v8);
    LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
    CEvn_Logic::CEvn_Logic((CEvn_Logic *)v15, 0x1392u, v9, 0, LocalPlayerId, v4, 0);
    LOBYTE(v16) = 3;
    if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3822, "g_pNetworkEngine != NULL") == 1 )
      __debugbreak();
    if ( g_pNetworkEngine )
      INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v15);
    LOBYTE(v16) = 0;
    CEvn_Logic::~CEvn_Logic(v15);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator++(v8);
  }
  v16 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v8);
  return 1;
}


// address=[0x145baa0]
// Decompiled from char __thiscall CInputProcessor::DestroyWarMachine(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::DestroyWarMachine(class CEvn_Logic * a2) {
  
  char LocalPlayerId; // al
  unsigned int v4; // [esp-8h] [ebp-48h]
  unsigned int v6; // [esp+8h] [ebp-38h]
  unsigned int i; // [esp+Ch] [ebp-34h]
  _BYTE v8[32]; // [esp+10h] [ebp-30h] BYREF
  int v9; // [esp+3Ch] [ebp-4h]

  for ( i = 0; i < std::vector<unsigned short>::size(&CInputProcessor::m_vSelection); ++i )
  {
    v6 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, i);
    LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
    CEvn_Logic::CEvn_Logic((CEvn_Logic *)v8, 0x13B9u, v6, 0, LocalPlayerId, v4, 0);
    v9 = 0;
    if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 5335, "g_pNetworkEngine != NULL") == 1 )
      __debugbreak();
    if ( g_pNetworkEngine )
      INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v8);
    v9 = -1;
    CEvn_Logic::~CEvn_Logic(v8);
  }
  CInputProcessor::Clear(this);
  return 1;
}


// address=[0x145bbb0]
// Decompiled from char __thiscall CInputProcessor::ZoomAreaState(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::ZoomAreaState(class CEvn_Logic * a2) {
  
  this->m_iViewState = 10;
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
          && (IEntity::ObjType(v16) == 1 || IEntity::ObjType(v16) == 2 || IEntity::ObjType(v16) == 4) )
        {
          v17 = v12;
          std::vector<unsigned short>::push_back(&v17);
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
    TheBestEntity = CInputProcessor::GetTheBestEntity(v6, __SPAIR64__(iY, iX));
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
  this->m_iViewState = 1;
  v18 = 1;
  v19 = -1;
  std::vector<unsigned short>::~vector<unsigned short>(v6);
  return v18;
}


// address=[0x145be00]
// Decompiled from int __thiscall CInputProcessor::TraceStates(CFsm **this, int a2)
void  CInputProcessor::TraceStates(class CEvn_Logic const & a2) {
  
  int v2; // eax
  unsigned int v4; // [esp+4h] [ebp-4h]

  v4 = *(_DWORD *)(a2 + 4);
  if ( v4 >= 0x190 && *(_DWORD *)(a2 + 4) <= 0x1E9u )
    v4 = *(_DWORD *)(a2 + 4) - 400;
  v2 = CFsm::CurrentState(this[2]);
  return CTrace::Print("IP - process type: %s actState: %s", off_3D89628[v4], off_3D895F4[v2]);
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
        v1 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&this->m_pEntityCandidates, i);
        EntitySelectionType = CInputProcessor::GetEntitySelectionType(*v1);
        if ( (int)((unsigned int)&dword_F29144[203695] & EntitySelectionType) > (int)((unsigned int)&dword_F29144[203695] & this->m_iSelectionType) )
          this->m_iSelectionType = (unsigned int)&dword_F29144[220015] & EntitySelectionType;
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
        v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&this->m_pEntityCandidates, j);
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
    std::vector<unsigned short>::clear();
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
  _BYTE v7[16]; // [esp+8h] [ebp-6Ch] BYREF
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

  std::vector<unsigned short>::vector<unsigned short>(v7);
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
          std::vector<unsigned short>::push_back(v7, (int)&v27);
        }
      }
    }
  }
  TheBestEntity = CInputProcessor::GetTheBestEntity(v7, __SPAIR64__(y, x));
  if ( TheBestEntity )
  {
    v12 = TheBestEntity;
    v28 = -1;
    std::vector<unsigned short>::~vector<unsigned short>(v7);
    return v12;
  }
  v22 = CSpiralOffsets::Last(5);
  for ( i = 0; ; ++i )
  {
    if ( i > v22 )
    {
      v8 = 0;
      v28 = -1;
      std::vector<unsigned short>::~vector<unsigned short>(v7);
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
      if ( v6 == CPlayerManager::GetLocalPlayerId() && IEntity::ObjType(v14) == 8 )
      {
        v9 = v18;
        v28 = -1;
        std::vector<unsigned short>::~vector<unsigned short>(v7);
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
    && IEntity::ObjType(v25) != 8 )
  {
    goto LABEL_13;
  }
  if ( IEntity::ObjType(v25) == 1 && i > 1 )
  {
    v11 = 0;
    v28 = -1;
    std::vector<unsigned short>::~vector<unsigned short>(v7);
    return v11;
  }
  else
  {
    v10 = v21;
    v28 = -1;
    std::vector<unsigned short>::~vector<unsigned short>(v7);
    return v10;
  }
}


// address=[0x145c390]
// Decompiled from int __stdcall CInputProcessor::GetTheBestEntity(CInputProcessor *a1, int x, int y)
int  CInputProcessor::GetTheBestEntity(class std::vector<unsigned short,class std::allocator<unsigned short> > & a1, int x, int y) {
  
  unsigned int v3; // eax
  unsigned __int16 *v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned __int16 *v8; // eax
  int iEntityY; // eax
  __int64 v11; // [esp-10h] [ebp-88h]
  unsigned int v12; // [esp-8h] [ebp-80h]
  unsigned int JobPart; // [esp-4h] [ebp-7Ch]
  _BYTE v14[16]; // [esp+10h] [ebp-68h] BYREF
  int v15; // [esp+20h] [ebp-58h]
  int v16; // [esp+24h] [ebp-54h]
  int v17; // [esp+28h] [ebp-50h]
  int v18; // [esp+2Ch] [ebp-4Ch]
  int v19; // [esp+30h] [ebp-48h]
  int v20; // [esp+34h] [ebp-44h]
  int iPrevEntityY; // [esp+38h] [ebp-40h]
  IEntity *v22; // [esp+3Ch] [ebp-3Ch]
  int screenY; // [esp+40h] [ebp-38h] BYREF
  int screenX; // [esp+44h] [ebp-34h] BYREF
  int v25; // [esp+48h] [ebp-30h] BYREF
  int v26; // [esp+4Ch] [ebp-2Ch] BYREF
  IEntity *v27; // [esp+50h] [ebp-28h]
  unsigned int i; // [esp+54h] [ebp-24h]
  _DWORD v29[2]; // [esp+58h] [ebp-20h] BYREF
  int v30; // [esp+60h] [ebp-18h]
  int v31; // [esp+64h] [ebp-14h]
  int v32; // [esp+74h] [ebp-4h]

  std::vector<unsigned short>::vector<unsigned short>(v14);
  v32 = 0;
  IGfxEngine::GetScreenOffsetsByMapIndices(__SPAIR64__(y, x), &screenX, &screenY);
  for ( i = 0; ; ++i )
  {
    v3 = std::vector<unsigned short>::size(a1);
    if ( i >= v3 )
      break;
    v4 = (unsigned __int16 *)std::vector<unsigned short>::operator[](a1, i);
    v27 = CMapObjectMgr::MovingEntity(*v4);
    if ( IMovingEntity::GetJobPart((IMovingEntity *)v27) )
    {
      JobPart = IMovingEntity::GetJobPart((IMovingEntity *)v27);
      v12 = IEntity::Race(v27);
      v5 = IEntity::ObjType(v27);
      CGfxManager::GetBoundingBox(g_pGfxManager, (struct SGfxBoundingBox *)v29, v5, v12, JobPart);
      HIDWORD(v11) = IEntity::Y(v27);
      LODWORD(v11) = IEntity::X(v27);
      IGfxEngine::GetScreenOffsetsByMapIndices(v11, &v26, &v25);
      v19 = v26 - v30;
      v18 = v29[0] + v26 - v30;
      v17 = v25 - v31;
      v16 = v29[1] + v25 - v31;
      if ( v26 - v30 <= screenX && v18 >= screenX && v17 <= screenY && v16 >= screenY )
      {
        v6 = std::vector<unsigned short>::operator[](a1, i);
        std::vector<unsigned short>::push_back(v14, v6);
      }
    }
  }
  v20 = 0;
  iPrevEntityY = 0;
  for ( i = 0; ; ++i )
  {
    v7 = std::vector<unsigned short>::size(v14);
    if ( i >= v7 )
      break;
    v8 = (unsigned __int16 *)std::vector<unsigned short>::operator[](v14, i);
    v22 = CMapObjectMgr::EntityPtr(*v8);
    iEntityY = IEntity::Y(v22);
    if ( iEntityY > iPrevEntityY )
    {
      iPrevEntityY = IEntity::Y(v22);
      v20 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](v14, i);
    }
  }
  v15 = v20;
  v32 = -1;
  std::vector<unsigned short>::~vector<unsigned short>(v14);
  return v15;
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
            && (IEntity::FlagBits(v13, EntityFlag_Selectable) || IEntity::ObjType(v13) == 8)
            && CInputProcessor::GetEntitySelectionType(v13) == this->m_iSelectionType )
          {
            v5 = IEntity::Y(v13);
            v4 = IEntity::X(v13);
            if ( CWorldManager::SectorId(v4, v5) == dword_3F1F60C )
            {
              IEntity::SetFlagBits(v13, EntityFlag_Selected);
              v14 = IEntity::EntityId(v13);
              std::vector<unsigned short>::push_back(&v14);
              if ( IEntity::ObjType(v13) == 8
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
// Decompiled from char __stdcall CInputProcessor::SelectAtSector(int a1, int a2)
bool  CInputProcessor::SelectAtSector(enum SETTLER_TYPES a1, int a2) {
  
  int LocalPlayerId; // eax
  int v4; // eax
  int v5; // [esp-4h] [ebp-18h]
  int v6; // [esp-4h] [ebp-18h]
  int i; // [esp+8h] [ebp-Ch]
  unsigned __int8 *SettlerPtr; // [esp+Ch] [ebp-8h]
  __int16 v9; // [esp+10h] [ebp-4h] BYREF
  char v10; // [esp+13h] [ebp-1h]

  if ( (a1 <= 0 || a1 >= 67)
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
  v10 = 0;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(a1);
  for ( i = CSettlerMgr::GetFirstSettlerId((CSettlerMgr *)g_cSettlerMgr, LocalPlayerId, v5);
        i > 0;
        i = IAnimatedEntity::Next(SettlerPtr) )
  {
    SettlerPtr = CSettlerMgr::GetSettlerPtr(i);
    if ( !SettlerPtr && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 2799, "pSettler!=NULL") == 1 )
      __debugbreak();
    if ( SettlerPtr )
    {
      v6 = IEntity::Y(SettlerPtr);
      v4 = IEntity::X(SettlerPtr);
      if ( CWorldManager::SectorId(v4, v6) == a2 )
      {
        IEntity::SetFlagBits(SettlerPtr, EntityFlag_Selected);
        v9 = i;
        std::vector<unsigned short>::push_back(&v9);
        v10 = 1;
        if ( (unsigned int)std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) >= 0x64 )
          break;
      }
    }
  }
  return v10;
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
  CStateGame::GetCenterWorldCoordinate((CStateGame *)g_pGame, &screenCenterX, &screenCenterY);
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
  DWORD m_iViewState; // [esp+0h] [ebp-8h]

  m_iViewState = this->m_iViewState;
  switch ( m_iViewState )
  {
    case 4u:
      iBuildBuildingType = this->m_iBuildBuildingType;
      LocalPlayerId = CPlayerManager::GetLocalPlayerId();
      CInputProcessor::GetPossibleBuildingSites(this, LocalPlayerId, iBuildBuildingType, 1);
      this->m_iViewState = 5;
      return;
    case 5u:
      iBuildBuildingType = this->m_iBuildBuildingType;
      LocalPlayerId = CPlayerManager::GetLocalPlayerId();
      if ( CInputProcessor::GetPossibleBuildingSites(this, LocalPlayerId, iBuildBuildingType, 0) )
      {
        this->m_iViewState = 6;
        byte_3F1F79C = 1;
        g_iPossibleBuildingSitesUpdateCounter = 0;
      }
      goto LABEL_11;
    case 6u:
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
// Decompiled from char __thiscall CInputProcessor::GetPossibleBuildingSites(CInputProcessor *this, int a2, int a3, bool a4)
bool  CInputProcessor::GetPossibleBuildingSites(int a2, int a3, bool a4) {
  
  int v5; // [esp+0h] [ebp-48h]
  int OutputWidth; // [esp+Ch] [ebp-3Ch]
  int OutputHeight; // [esp+10h] [ebp-38h]
  char v8; // [esp+14h] [ebp-34h]
  signed int unk_2C; // [esp+18h] [ebp-30h]
  DWORD unk_24; // [esp+1Ch] [ebp-2Ch]
  signed int unk_30; // [esp+20h] [ebp-28h]
  int v12; // [esp+24h] [ebp-24h]
  DWORD unk_20; // [esp+28h] [ebp-20h]
  int v14; // [esp+2Ch] [ebp-1Ch]
  int HelperObject; // [esp+30h] [ebp-18h]
  int v16; // [esp+34h] [ebp-14h]
  Squares *i; // [esp+3Ch] [ebp-Ch]
  Squares *j; // [esp+40h] [ebp-8h]

  v16 = CWorldManager::Width() - 5;
  v8 = 10;
  if ( CBuildingMgr::IsMine(a3) )
    v8 = 74;
  if ( a4 )
  {
    this->unk_20 = 0;
    OutputWidth = IGfxEngine::GetOutputWidth(g_pGfxEngine);
    OutputHeight = IGfxEngine::GetOutputHeight(g_pGfxEngine);
    IGfxEngine::GetClosestMapPoint(g_pGfxEngine, 1, 1, (int *)&this->unk_24, (int *)&this->unk_28);
    IGfxEngine::GetClosestMapPoint(
      g_pGfxEngine,
      OutputWidth - 2,
      OutputHeight - 2,
      (int *)&this->unk_2C,
      (int *)&this->unk_30);
    sub_145DB10(&this->unk_24, (_DWORD *)4, v16);
    sub_145DB10(&this->unk_28, (_DWORD *)4, v16);
    sub_145DB10(&this->unk_2C, (_DWORD *)4, v16);
    sub_145DB10(&this->unk_30, (_DWORD *)4, v16);
  }
  else if ( (int)this->unk_20 >= 20 )
  {
    return 1;
  }
  if ( (int)this->unk_20 >= 4 )
  {
    unk_24 = 4;
    unk_20 = this->unk_20;
    unk_2C = v16;
    unk_30 = v16;
    v12 = 16;
  }
  else
  {
    unk_24 = this->unk_24;
    unk_20 = (((signed int)(this->unk_20 & 2) >> 1) | (2 * (this->unk_20 & 1)) | this->unk_20 & 0xFFFFFFFC)
           + this->unk_28;
    unk_2C = this->unk_2C;
    unk_30 = this->unk_30;
    v12 = 4;
  }
  v5 = COwnerMap::OwnerBit(a2);
  for ( i = (Squares *)unk_20; (int)i <= unk_30; i = (Squares *)((char *)i + v12) )
  {
    for ( j = (Squares *)unk_24; (int)j < unk_2C; j = (Squares *)((char *)j + 1) )
    {
      if ( (v5 & COwnerMap::OwnerBits1XY(j, i)) != 0 )
      {
        HelperObject = CWorldManager::GetHelperObject((int)j, (int)i);
        if ( (HelperObject < 10 || HelperObject > 17) && HelperObject != 74 )
        {
          v14 = CBuildingMgr::CheckForBuild((CBuildingMgr *)g_cBuildingMgr, (int)j, (int)i, a2, a3, 0);
          if ( v14 > 0 )
            CWorldManager::SetHelperObject((int)j, (int)i, v8 + v14 - 1);
        }
      }
      else
      {
        j = (Squares *)(((unsigned int)j + 16) & 0xFFFFFFF0);
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
  int v11; // [esp+20h] [ebp-Ch]
  Squares *j; // [esp+24h] [ebp-8h]

  v11 = CWorldManager::Width() - 5;
  v8 = 10;
  if ( CBuildingMgr::IsMine(_iBuildingType) )
    v8 = 74;
  if ( a4 )
  {
    this->unk_20 = 0;
    OutputWidth = IGfxEngine::GetOutputWidth(g_pGfxEngine);
    OutputHeight = IGfxEngine::GetOutputHeight(g_pGfxEngine);
    IGfxEngine::GetClosestMapPoint(g_pGfxEngine, 1, 1, (int *)&this->unk_24, (int *)&this->unk_28);
    IGfxEngine::GetClosestMapPoint(
      g_pGfxEngine,
      OutputWidth - 2,
      OutputHeight - 2,
      (int *)&this->unk_2C,
      (int *)&this->unk_30);
    sub_145DB10(&this->unk_24, (_DWORD *)4, v11);
    sub_145DB10(&this->unk_28, (_DWORD *)4, v11);
    sub_145DB10(&this->unk_2C, (_DWORD *)4, v11);
    sub_145DB10(&this->unk_30, (_DWORD *)4, v11);
    byte_3F1F7B0 = 1;
  }
  else if ( (int)this->unk_20 >= 4 )
  {
    return 1;
  }
  if ( byte_3F1F7B0 )
  {
    dword_3F1F7AC = (((signed int)(this->unk_20 & 2) >> 1) | (2 * (this->unk_20 & 1)) | this->unk_20 & 0xFFFFFFFC)
                  + this->unk_28;
    byte_3F1F7B0 = 0;
  }
  v5 = COwnerMap::OwnerBit(_iOwner);
  for ( i = 0; i < 2; ++i )
  {
    for ( j = (Squares *)this->unk_24; (int)j < (signed int)this->unk_2C; j = (Squares *)((char *)j + 1) )
    {
      if ( (v5 & COwnerMap::OwnerBits1XY(j, (Squares *)dword_3F1F7AC)) != 0 )
      {
        v9 = CBuildingMgr::CheckForBuild(
               (CBuildingMgr *)g_cBuildingMgr,
               (int)j,
               dword_3F1F7AC,
               _iOwner,
               _iBuildingType,
               0);
        if ( v9 <= 0 )
          CWorldManager::SetHelperObject((int)j, dword_3F1F7AC, 0);
        else
          CWorldManager::SetHelperObject((int)j, dword_3F1F7AC, v8 + v9 - 1);
      }
      else
      {
        j = (Squares *)(((unsigned int)j + 16) & 0xFFFFFFF0);
      }
    }
    dword_3F1F7AC += 4;
    if ( dword_3F1F7AC > (signed int)this->unk_30 )
    {
      ++this->unk_20;
      i = 10;
      byte_3F1F7B0 = 1;
    }
  }
  return 0;
}


// address=[0x145d060]
// Decompiled from int __thiscall CInputProcessor::ShowPossibleBuildingType(CInputProcessor *this)
void  CInputProcessor::ShowPossibleBuildingType(void) {
  
  int LocalPlayerId; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  DWORD m_iBuildBuildingType; // [esp-8h] [ebp-34h]
  DWORD v8; // [esp-8h] [ebp-34h]
  char v9; // [esp+4h] [ebp-28h]
  unsigned int v10; // [esp+8h] [ebp-24h]
  unsigned int v11; // [esp+Ch] [ebp-20h]
  signed int IconObjectByX; // [esp+10h] [ebp-1Ch]
  int v13; // [esp+14h] [ebp-18h]
  int v14; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]
  int v16; // [esp+1Ch] [ebp-10h]
  int v17; // [esp+1Ch] [ebp-10h]
  int iMouseHoverY; // [esp+24h] [ebp-8h] BYREF
  int iMouseHoverX; // [esp+28h] [ebp-4h] BYREF

  if ( !CWorldManager::InWorld(s_iPrevMouseHoverX, s_iPrevMouseHoverY) )
  {
    s_iPrevMouseHoverX = 0;
    s_iPrevMouseHoverY = 0;
  }
  v9 = 10;
  if ( CBuildingMgr::IsMine(this->m_iBuildBuildingType) )
    v9 = 74;
  if ( IGfxEngine::GetClosestMapPoint(g_pGfxEngine, (int)g_pGame[27], (int)g_pGame[28], &iMouseHoverX, &iMouseHoverY) < 0
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
    v13 = CBuildingMgr::CheckForBuild(
            (CBuildingMgr *)g_cBuildingMgr,
            iMouseHoverX,
            iMouseHoverY,
            LocalPlayerId,
            m_iBuildBuildingType,
            0);
    if ( v13 > 0 )
      CWorldManager::SetHelperObject(iMouseHoverX, iMouseHoverY, v9 + v13 - 1);
    else
      CWorldManager::SetHelperObject(iMouseHoverX, iMouseHoverY, 0);
    for ( i = 0; i < 6; ++i )
    {
      v10 = g_sNeighborPoints[2 * i] + iMouseHoverX;
      v11 = dword_37D8C0C[2 * i] + iMouseHoverY;
      if ( CWorldManager::InWorld(v10, v11) )
      {
        v8 = this->m_iBuildBuildingType;
        v2 = CPlayerManager::GetLocalPlayerId();
        v14 = CBuildingMgr::CheckForBuild((CBuildingMgr *)g_cBuildingMgr, v10, v11, v2, v8, 0);
        if ( v14 > 0 )
          CWorldManager::SetHelperObject(v10, v11, v9 + v14 - 1);
        else
          CWorldManager::SetHelperObject(v10, v11, 0);
      }
    }
  }
  CWorldManager::WorldSetNumberOfNextLine(iMouseHoverY);
  if ( (unsigned __int8)CWorldManager::WorldGetIconObjectByX(iMouseHoverX) )
  {
    IconObjectByX = (unsigned __int8)CWorldManager::WorldGetIconObjectByX(iMouseHoverX);
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
      CWorldManager::SetHelperObject(iMouseHoverX, iMouseHoverY, LOBYTE(this->unk_1C) - v9 + 18);
    }
    CInputProcessor::m_sGfxObj = 1;
    dword_3F1F32C = iMouseHoverX;
    dword_3F1F330 = iMouseHoverY;
    byte_3F1F604 = 1;
    v16 = this->m_iBuildBuildingType;
    if ( v16 == 31 || v16 == 32 )
    {
      if ( v16 == 31 )
        v17 = 58;
      else
        v17 = 52;
      v3 = CPlayerManager::GetLocalPlayerId();
      v16 = CBuildingMgr::CheckForBuildInWater((CBuildingMgr *)g_cBuildingMgr, iMouseHoverX, iMouseHoverY, v3, v17);
    }
    v4 = CPlayerManager::GetLocalPlayerId();
    v5 = CPlayerManager::Race(v4);
    CGfxManager::GetBuildingGfxInfo((int)&unk_3F1F334, v5, v16, 1, 0);
    return IGfxEngine::SetGfxObject(&CInputProcessor::m_sGfxObj);
  }
  else
  {
    byte_3F1F604 = 0;
    return IGfxEngine::SetGfxObject(&CInputProcessor::m_sGfxObj);
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
      v2 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, i);
      v3 = CMapObjectMgr::EntityPtr(v2);
      if ( v3 )
      {
        IEntity::ClearFlagBits(v3, EntityFlag_Selected);
        IEntity::ClearFlagBits(v3, (EntityFlag)1024);
        if ( IEntity::ObjType(v3) == 8 )
        {
          BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v2);
          CBuilding::NotifySelected(BuildingPtr);
        }
      }
    }
    std::vector<unsigned short>::clear();
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
  int v9; // [esp+14h] [ebp-44h]
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
    v1 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
    v2 = CMapObjectMgr::EntityPtr(*v1);
    switch ( IEntity::ObjType(v2) )
    {
      case 1:
        v4 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
        v12 = (CSettler *)CSettlerMgr::operator[](*v4);
        if ( IEntity::WarriorType(v12) == 7 )
        {
          CSettlerMgr::FillSpecialistMenu(&g_cSpecialistsInfo, 0);
          CLogic::SetFillDialogInfos(
            g_pLogic,
            (void (__cdecl *)(struct CInfoExchange *, bool, bool))CSettlerMgr::FillSpecialistMenu,
            (struct CInfoExchange *)&g_cSpecialistsInfo,
            this->unk_69);
        }
        else if ( IEntity::Type(v12) == 60 )
        {
          v9 = CSettler::Role(v12);
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v9 + 132))(v9, 0);
        }
        else
        {
          CSettlerMgr::FillSoldierMenu(&g_cSoldierInfo, 0);
          CLogic::SetFillDialogInfos(
            g_pLogic,
            (void (__cdecl *)(struct CInfoExchange *, bool, bool))CSettlerMgr::FillSoldierMenu,
            (struct CInfoExchange *)&g_cSoldierInfo,
            this->unk_69);
        }
        goto CInputProcessor__RequestDialog___def_185D591;
      case 2:
        v5 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
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
      case 4:
        v6 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
        v10 = CVehicleMgr::operator[](*v6);
        v8 = IEntity::Type(v10);
        if ( v8 == 4 )
        {
LABEL_25:
          CVehicleMgr::FillVehicleGroupMenu((struct CInfoExchange *)&g_cVehicleInfo, 0);
          CLogic::SetFillDialogInfos(
            g_pLogic,
            (void (__cdecl *)(struct CInfoExchange *, bool, bool))CVehicleMgr::FillVehicleGroupMenu,
            (struct CInfoExchange *)&g_cVehicleInfo,
            this->unk_69);
        }
        else if ( v8 == 5 )
        {
          ((void (__thiscall *)(IEntity *, _DWORD))v10->__vftable[1].DbgPrint)(v10, 0);
        }
        goto CInputProcessor__RequestDialog___def_185D591;
      case 8:
        v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
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
// Decompiled from int __thiscall CInputProcessor::TidyUp(CInputProcessor *this)
void  CInputProcessor::TidyUp(void) {
  
  int v2; // [esp+0h] [ebp-Ch]
  IEntity *BuildingPtr; // [esp+8h] [ebp-4h]

  this->m_iViewState = 0;
  if ( std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
  {
    v2 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v2);
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
  IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
  IGfxEngine::EnableIconLayer((IGfxEngine *)g_pGfxEngine, 0);
  CWorldManager::ClearHelperObject();
  byte_3F1F604 = 0;
  return IGfxEngine::SetGfxObject(&CInputProcessor::m_sGfxObj);
}


// address=[0x145da20]
// Decompiled from unsigned __int8 __thiscall CInputProcessor::CloseSidebarAndShowDefaultMenu(CInputProcessor *this)
void  CInputProcessor::CloseSidebarAndShowDefaultMenu(void) {
  
  unsigned __int8 result; // al
  CEvn_Event *v2; // [esp+4h] [ebp-34h]
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
// Decompiled from CInputProcessor *__thiscall CInputProcessor::SelectAllVisible(CInputProcessor *this)
void  CInputProcessor::SelectAllVisible(void) {
  
  CInputProcessor *result; // eax

  CInputProcessor::BoxSelection(this);
  result = this;
  *((_BYTE *)this + 52) = 0;
  return result;
}


// address=[0x14604b0]
// Decompiled from char __thiscall CInputProcessor::EmptyFunct(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::EmptyFunct(class CEvn_Logic * a2) {
  
  return 1;
}


// address=[0x14e4b00]
// Decompiled from int __thiscall CInputProcessor::GetSelectionType(CInputProcessor *this)
int  CInputProcessor::GetSelectionType(void)const {
  
  return *((_DWORD *)this + 19);
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

