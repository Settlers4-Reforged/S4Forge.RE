#include "all_headers.h"

// Definitions for class CInputProcessor

// address=[0x1439c90]
// Decompiled from void *CInputProcessor::Selection()
static class std::vector<unsigned short,class std::allocator<unsigned short> > const & __cdecl CInputProcessor::Selection(void) {
  
  return &CInputProcessor::m_vSelection;
}


// address=[0x1454f10]
// Decompiled from CInputProcessor *__thiscall CInputProcessor::CInputProcessor(CInputProcessor *this)
 CInputProcessor::CInputProcessor(void) {
  
  IEventHandler::IEventHandler(this, 1500);
  *(_DWORD *)this = &CInputProcessor::_vftable_;
  *((_BYTE *)this + 52) = 0;
  std::vector<unsigned short>::vector<unsigned short>((char *)this + 84);
  memset(&CInputProcessor::m_sGfxObj, 0, 0x2E0u);
  CInputProcessor::FillHandlersArray(this);
  std::vector<unsigned short>::reserve(128);
  std::vector<unsigned short>::reserve(256);
  *((_DWORD *)this + 2) = 0;
  CInputProcessor::Reset(this);
  return this;
}


// address=[0x1454fd0]
// Decompiled from void __thiscall CInputProcessor::~CInputProcessor(CFsm **this)
 CInputProcessor::~CInputProcessor(void) {
  
  *this = (CFsm *)&CInputProcessor::_vftable_;
  if ( this[2] )
  {
    CFsm::`scalar deleting destructor'(this[2], 1u);
    this[2] = 0;
  }
  std::vector<unsigned short>::~vector<unsigned short>(this + 21);
  IEventHandler::~IEventHandler((IEventHandler *)this);
}


// address=[0x1455040]
// Decompiled from CFsm **__thiscall CInputProcessor::Reset(CFsm **this)
void  CInputProcessor::Reset(void) {
  
  CFsm **result; // eax

  if ( this[2] )
  {
    CFsm::`scalar deleting destructor'(this[2], 1u);
    this[2] = 0;
  }
  CInputProcessor::InitFSM((CInputProcessor *)this);
  std::vector<unsigned short>::clear();
  std::vector<unsigned short>::clear();
  this[19] = 0;
  this[25] = 0;
  *((_BYTE *)this + 106) = 0;
  this[6] = 0;
  result = this;
  this[7] = 0;
  return result;
}


// address=[0x14550e0]
// Decompiled from int __thiscall CInputProcessor::Process(CFsm **this)
void  CInputProcessor::Process(void) {
  
  int result; // eax
  _BYTE v3[4]; // [esp+10h] [ebp-30h] BYREF
  unsigned int v4; // [esp+14h] [ebp-2Ch]
  unsigned int v5; // [esp+18h] [ebp-28h]
  unsigned int v6; // [esp+1Ch] [ebp-24h]
  unsigned __int8 v7; // [esp+2Eh] [ebp-12h]
  int v8; // [esp+3Ch] [ebp-4h]

  if ( *((_BYTE *)this + 52) )
  {
    CInputProcessor::SelectAllVisible((CInputProcessor *)this);
  }
  else if ( *((_BYTE *)this + 106) )
  {
    CInputProcessor::BoxSelection((CInputProcessor *)this);
  }
  CInputProcessor::WorkOnBuildingSites((CInputProcessor *)this);
  while ( 1 )
  {
    result = CStateGame::IsMessage((CStateGame *)g_pGame);
    if ( !(_BYTE)result )
      return result;
    CStateGame::PopMessage((_DWORD **)g_pGame, (int)v3);
    v8 = 0;
    if ( v4 <= 0x1388 || v4 >= 0x13BD )
    {
      switch ( v4 )
      {
        case 0x1DDu:
          if ( (v5 & 0x14) != 0 )
            v4 = 426;
LABEL_19:
          CFsm::Control(this[2], v4, v3);
          v8 = -1;
          CEvn_Logic::~CEvn_Logic(v3);
          break;
        case 0x1DFu:
          v8 = -1;
          CEvn_Logic::~CEvn_Logic(v3);
          break;
        case 0x1E8u:
          INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, 0x13BBu, v5, v6, v7);
          v8 = -1;
          CEvn_Logic::~CEvn_Logic(v3);
          break;
        default:
          goto LABEL_19;
      }
    }
    else
    {
      (**(void (__thiscall ***)(void *, _BYTE *))g_pNetInputProcessor)(g_pNetInputProcessor, v3);
      v8 = -1;
      CEvn_Logic::~CEvn_Logic(v3);
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
void  CInputProcessor::DeSelectEntity(int) {
  
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
  _DWORD *v16; // [esp+58h] [ebp-14h]
  char v17; // [esp+5Fh] [ebp-Dh]
  int v18; // [esp+68h] [ebp-4h]

  if ( a2 > 0 )
  {
    v16 = (_DWORD *)CMapObjectMgr::EntityPtr(a2);
    if ( v16 )
    {
      IEntity::ClearFlagBits(v16, Selected);
      IEntity::ClearFlagBits(v16, (EntityFlag)0x400u);
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
// Decompiled from void __stdcall CInputProcessor::AddToSelection(int a1)
void  CInputProcessor::AddToSelection(int) {
  
  _DWORD *v1; // [esp+4h] [ebp-8h]
  __int16 v2; // [esp+Ah] [ebp-2h] BYREF

  if ( a1 > 0 && (unsigned int)std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) < 0x64 )
  {
    v1 = (_DWORD *)CMapObjectMgr::EntityPtr(a1);
    if ( v1 )
    {
      v2 = a1;
      std::vector<unsigned short>::push_back(&v2);
      CFsm::GenerateEvent(484, 0);
      if ( IEntity::FlagBits(v1, Selectable) )
        IEntity::SetFlagBits(v1, Selected);
      else
        IEntity::SetFlagBits(v1, (EntityFlag)0x400u);
    }
  }
}


// address=[0x14554d0]
// Decompiled from int __thiscall CInputProcessor::GetSelectionTypeOfCurrentSelection(CInputProcessor *this)
int  CInputProcessor::GetSelectionTypeOfCurrentSelection(void)const {
  
  unsigned __int16 *v1; // eax
  const struct IEntity *v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v4 = 0;
  if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    return v4;
  v1 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  v2 = (const struct IEntity *)CMapObjectMgr::EntityPtr(*v1);
  return CInputProcessor::GetEntitySelectionType(v2);
}


// address=[0x1455520]
// Decompiled from int __cdecl CInputProcessor::GetEntitySelectionType(int a1, int a2, int a3)
static int __cdecl CInputProcessor::GetEntitySelectionType(int,int,int) {
  
  int result; // eax

  if ( a1 == 8 )
    return 0x10000;
  switch ( a3 )
  {
    case 0:
      result = 0;
      break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      result = a3 + 196608;
      break;
    case 6:
      result = 196608;
      break;
    case 7:
      result = (a2 << 8) + 0x20000;
      break;
    case 8:
    case 9:
      result = 0x40000;
      break;
    case 10:
    case 11:
      result = 327680;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}


// address=[0x14555b0]
// Decompiled from int __cdecl CInputProcessor::GetEntitySelectionType(struct IEntity *a1)
static int __cdecl CInputProcessor::GetEntitySelectionType(class IEntity const *) {
  
  int v2; // [esp+0h] [ebp-Ch]
  int v3; // [esp+4h] [ebp-8h]
  int v4; // [esp+8h] [ebp-4h]

  if ( !a1 )
    return 0;
  v2 = IEntity::ObjType((unsigned __int8 *)a1);
  v3 = IEntity::Type((unsigned __int16 *)a1);
  v4 = IEntity::WarriorType();
  return CInputProcessor::GetEntitySelectionType(v2, v3, v4);
}


// address=[0x1455600]
// Decompiled from int __cdecl CInputProcessor::GetEntitySelectionType(int a1)
static int __cdecl CInputProcessor::GetEntitySelectionType(int) {
  
  const struct IEntity *v1; // eax

  if ( a1 <= 0 )
    return 0;
  v1 = (const struct IEntity *)CMapObjectMgr::EntityPtr(a1);
  return CInputProcessor::GetEntitySelectionType(v1);
}


// address=[0x146ad70]
// Decompiled from bool __thiscall CInputProcessor::IsChooseSecondPatrolPosState(CInputProcessor *this)
bool  CInputProcessor::IsChooseSecondPatrolPosState(void) {
  
  return *((_DWORD *)this + 20) == 9;
}


// address=[0x146adb0]
// Decompiled from bool __thiscall CInputProcessor::IsTryBuildState(CInputProcessor *this)
bool  CInputProcessor::IsTryBuildState(void) {
  
  return *((_DWORD *)this + 20) == 4 || *((_DWORD *)this + 20) == 5 || *((_DWORD *)this + 20) == 6;
}


// address=[0x146ae00]
// Decompiled from bool __thiscall CInputProcessor::IsWorkingAreaState(CInputProcessor *this)
bool  CInputProcessor::IsWorkingAreaState(void) {
  
  return *((_DWORD *)this + 20) == 3;
}


// address=[0x146ae40]
// Decompiled from bool __thiscall CInputProcessor::IsZoomAreaState(CInputProcessor *this)
bool  CInputProcessor::IsZoomAreaState(void) {
  
  return *((_DWORD *)this + 20) == 10;
}


// address=[0x14e4ac0]
// Decompiled from char __thiscall CInputProcessor::BoxSelectAllSettler(CInputProcessor *this)
bool  CInputProcessor::BoxSelectAllSettler(void)const {
  
  return *((_BYTE *)this + 52);
}


// address=[0x14e4bd0]
// Decompiled from int __thiscall CInputProcessor::StrictSelection(CInputProcessor *this)
int  CInputProcessor::StrictSelection(void)const {
  
  return *((_DWORD *)this + 25);
}


// address=[0x14eb4b0]
// Decompiled from bool __thiscall CInputProcessor::IsBoxSelection(CInputProcessor *this)
bool  CInputProcessor::IsBoxSelection(void)const {
  
  return *((_BYTE *)this + 106) || *((_BYTE *)this + 52);
}


// address=[0x3f1f6b4]
// [Decompilation failed for static class std::vector<unsigned short,class std::allocator<unsigned short> > CInputProcessor::m_vSelection]

// address=[0x1455640]
// Decompiled from int __thiscall CInputProcessor::InitFSM(CInputProcessor *this)
void  CInputProcessor::InitFSM(void) {
  
  CFsm *v2; // [esp+8h] [ebp-18h]
  CFsm *C; // [esp+Ch] [ebp-14h]

  if ( *((_DWORD *)this + 2) && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 254, "m_pFsm == 0") == 1 )
    __debugbreak();
  C = (CFsm *)operator new(0x1Cu);
  if ( C )
    v2 = CFsm::CFsm(C, this, 1500, 0);
  else
    v2 = 0;
  *((_DWORD *)this + 2) = v2;
  if ( !*((_DWORD *)this + 2) && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 259, "m_pFsm != 0") == 1 )
    __debugbreak();
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 401, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 480, 0);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 402, 17);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 1, 477, 28);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 1, 478, 27);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 1, 426, 29);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 1, 408, 12);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 1, 486, 13);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 1, 427, 14);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 1, 484, 3);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 482, 20);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 436, 56);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 428, 16);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 4, 437, 4);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 438, 15);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 429, 44);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 430, 45);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 431, 46);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 485, 47);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 1, 441, 48);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 441, 48);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 442, 49);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 481, 75);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 1, 472, 30);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 1, 473, 33);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 432, 50);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 433, 51);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 434, 52);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 445, 54);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 446, 53);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 435, 55);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 458, 65);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 0, 440, 74);
  CFsm::DefineTransition(*((CFsm **)this + 2), 0, 10, 487, 83);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 0, 401, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 477, 28);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 478, 27);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 426, 29);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 481, 75);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 480, 34);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 415, 40);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 423, 41);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 470, 32);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 472, 30);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 473, 33);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 471, 31);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 411, 35);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 412, 36);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 9, 414, 37);
  CFsm::DefineTransition(*((CFsm **)this + 2), 9, 1, 401, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 9, 1, 480, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 9, 0, 402, 17);
  CFsm::DefineTransition(*((CFsm **)this + 2), 9, 9, 477, 38);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 422, 39);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 435, 55);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 448, 81);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 0, 402, 17);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 4, 437, 4);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 3, 403, 6);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 404, 8);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 405, 9);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 406, 10);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 407, 11);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 408, 12);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 486, 13);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 427, 14);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 461, 68);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 462, 69);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 463, 70);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 464, 71);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 468, 72);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 469, 73);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 447, 82);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 7, 409, 21);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 465, 23);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 466, 24);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 467, 25);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 483, 26);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 443, 18);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 444, 19);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 8, 449, 57);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 450, 58);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 451, 59);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 452, 60);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 453, 61);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 455, 62);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 456, 63);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 457, 64);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 459, 66);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 460, 67);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 419, 76);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 421, 77);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 420, 78);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 417, 79);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 1, 418, 80);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 10, 487, 83);
  CFsm::DefineTransition(*((CFsm **)this + 2), 4, 0, 401, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 4, 0, 480, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 4, 0, 402, 17);
  CFsm::DefineTransition(*((CFsm **)this + 2), 4, 0, 428, 16);
  CFsm::DefineTransition(*((CFsm **)this + 2), 4, 1, 478, 27);
  CFsm::DefineTransition(*((CFsm **)this + 2), 4, 4, 437, 4);
  CFsm::DefineTransition(*((CFsm **)this + 2), 4, 4, 477, 5);
  CFsm::DefineTransition(*((CFsm **)this + 2), 4, 4, 438, 15);
  CFsm::DefineTransition(*((CFsm **)this + 2), 4, 0, 458, 65);
  CFsm::DefineTransition(*((CFsm **)this + 2), 4, 10, 487, 83);
  CFsm::DefineTransition(*((CFsm **)this + 2), 3, 1, 401, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 3, 1, 480, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 3, 0, 402, 17);
  CFsm::DefineTransition(*((CFsm **)this + 2), 3, 1, 478, 27);
  CFsm::DefineTransition(*((CFsm **)this + 2), 3, 3, 477, 7);
  CFsm::DefineTransition(*((CFsm **)this + 2), 3, 1, 408, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 3, 1, 404, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 3, 1, 403, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 3, 1, 406, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 3, 1, 449, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 3, 1, 450, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 3, 1, 451, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 3, 1, 452, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 3, 1, 453, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 3, 1, 455, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 3, 1, 456, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 3, 1, 457, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 3, 1, 459, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 3, 10, 487, 83);
  CFsm::DefineTransition(*((CFsm **)this + 2), 7, 1, 401, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 7, 1, 480, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 7, 0, 402, 17);
  CFsm::DefineTransition(*((CFsm **)this + 2), 7, 7, 477, 22);
  CFsm::DefineTransition(*((CFsm **)this + 2), 7, 10, 487, 83);
  CFsm::DefineTransition(*((CFsm **)this + 2), 1, 8, 474, 42);
  CFsm::DefineTransition(*((CFsm **)this + 2), 8, 8, 474, 42);
  CFsm::DefineTransition(*((CFsm **)this + 2), 8, 8, 480, 43);
  CFsm::DefineTransition(*((CFsm **)this + 2), 8, 0, 402, 17);
  CFsm::DefineTransition(*((CFsm **)this + 2), 8, 1, 477, 28);
  CFsm::DefineTransition(*((CFsm **)this + 2), 8, 0, 401, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 8, 1, 460, 1);
  CFsm::DefineTransition(*((CFsm **)this + 2), 8, 1, 478, 27);
  CFsm::DefineTransition(*((CFsm **)this + 2), 8, 8, 470, 32);
  CFsm::DefineTransition(*((CFsm **)this + 2), 8, 8, 472, 30);
  CFsm::DefineTransition(*((CFsm **)this + 2), 8, 8, 473, 33);
  CFsm::DefineTransition(*((CFsm **)this + 2), 8, 1, 411, 35);
  CFsm::DefineTransition(*((CFsm **)this + 2), 8, 1, 412, 36);
  CFsm::DefineTransition(*((CFsm **)this + 2), 8, 9, 414, 37);
  CFsm::DefineTransition(*((CFsm **)this + 2), 8, 1, 415, 40);
  CFsm::DefineTransition(*((CFsm **)this + 2), 8, 10, 487, 83);
  CFsm::DefineTransition(*((CFsm **)this + 2), 10, 1, 477, 84);
  return CFsm::DefineTransition(*((CFsm **)this + 2), 10, 1, 480, 1);
}


// address=[0x14563d0]
// Decompiled from CInputProcessor *__thiscall CInputProcessor::FillHandlersArray(CInputProcessor *this)
void  CInputProcessor::FillHandlersArray(void) {
  
  CInputProcessor *result; // eax

  **((_DWORD **)this + 1) = CInputProcessor::HandleInternalError;
  *(_DWORD *)(*((_DWORD *)this + 1) + 4) = CInputProcessor::Default;
  *(_DWORD *)(*((_DWORD *)this + 1) + 68) = CInputProcessor::NewDialogClear;
  *(_DWORD *)(*((_DWORD *)this + 1) + 12) = CInputProcessor::EmptyFunct;
  *(_DWORD *)(*((_DWORD *)this + 1) + 16) = CInputProcessor::TryBuild;
  *(_DWORD *)(*((_DWORD *)this + 1) + 20) = CInputProcessor::Build;
  *(_DWORD *)(*((_DWORD *)this + 1) + 24) = j_CInputProcessor::ShowWorkingArea;
  *(_DWORD *)(*((_DWORD *)this + 1) + 28) = CInputProcessor::SetWorkingArea;
  *(_DWORD *)(*((_DWORD *)this + 1) + 32) = CInputProcessor::TryCrushBuilding;
  *(_DWORD *)(*((_DWORD *)this + 1) + 36) = CInputProcessor::CrushBuilding;
  *(_DWORD *)(*((_DWORD *)this + 1) + 40) = CInputProcessor::SwitchBuilding;
  *(_DWORD *)(*((_DWORD *)this + 1) + 44) = CInputProcessor::PrioBuildingSite;
  *(_DWORD *)(*((_DWORD *)this + 1) + 48) = CInputProcessor::SelectNextBuilding;
  *(_DWORD *)(*((_DWORD *)this + 1) + 52) = CInputProcessor::SelectBuilding;
  *(_DWORD *)(*((_DWORD *)this + 1) + 60) = CInputProcessor::MarkNextBuilding;
  *(_DWORD *)(*((_DWORD *)this + 1) + 56) = CInputProcessor::SelectNextVehicle;
  *(_DWORD *)(*((_DWORD *)this + 1) + 64) = CInputProcessor::BuildingAmount;
  *(_DWORD *)(*((_DWORD *)this + 1) + 72) = CInputProcessor::FillTower;
  *(_DWORD *)(*((_DWORD *)this + 1) + 76) = CInputProcessor::EmptyTower;
  *(_DWORD *)(*((_DWORD *)this + 1) + 84) = CInputProcessor::ChooseTradeDest;
  *(_DWORD *)(*((_DWORD *)this + 1) + 88) = CInputProcessor::SelectTradeDest;
  *(_DWORD *)(*((_DWORD *)this + 1) + 92) = CInputProcessor::TransportGoods;
  *(_DWORD *)(*((_DWORD *)this + 1) + 96) = CInputProcessor::TradeWith;
  *(_DWORD *)(*((_DWORD *)this + 1) + 100) = CInputProcessor::TradeGoods;
  *(_DWORD *)(*((_DWORD *)this + 1) + 104) = CInputProcessor::SetTradePlayerStatus;
  *(_DWORD *)(*((_DWORD *)this + 1) + 108) = CInputProcessor::PrepareBoxSelection;
  *(_DWORD *)(*((_DWORD *)this + 1) + 112) = CInputProcessor::DotSelection;
  *(_DWORD *)(*((_DWORD *)this + 1) + 116) = CInputProcessor::SelectTypeInSurrounding;
  *(_DWORD *)(*((_DWORD *)this + 1) + 120) = CInputProcessor::SelectGroup;
  *(_DWORD *)(*((_DWORD *)this + 1) + 124) = j_CInputProcessor::GroupToSelection;
  *(_DWORD *)(*((_DWORD *)this + 1) + 128) = CInputProcessor::DefineGroup;
  *(_DWORD *)(*((_DWORD *)this + 1) + 132) = CInputProcessor::FocusGroup;
  *(_DWORD *)(*((_DWORD *)this + 1) + 136) = CInputProcessor::SendTo;
  *(_DWORD *)(*((_DWORD *)this + 1) + 140) = CInputProcessor::ForceGoto;
  *(_DWORD *)(*((_DWORD *)this + 1) + 144) = j_CInputProcessor::StandGround;
  *(_DWORD *)(*((_DWORD *)this + 1) + 148) = CInputProcessor::ChooseSecondPatrolPos;
  *(_DWORD *)(*((_DWORD *)this + 1) + 152) = j_CInputProcessor::SelectSecondPatrolPos;
  *(_DWORD *)(*((_DWORD *)this + 1) + 160) = CInputProcessor::InjuredOut;
  *(_DWORD *)(*((_DWORD *)this + 1) + 164) = CInputProcessor::MorphToCarrier;
  *(_DWORD *)(*((_DWORD *)this + 1) + 80) = CInputProcessor::InitExtraMenu;
  *(_DWORD *)(*((_DWORD *)this + 1) + 224) = CInputProcessor::InitEconomyGameMenu;
  *(_DWORD *)(*((_DWORD *)this + 1) + 156) = CInputProcessor::GotoVehicleGroupMenu;
  *(_DWORD *)(*((_DWORD *)this + 1) + 192) = CInputProcessor::SearchUnit;
  *(_DWORD *)(*((_DWORD *)this + 1) + 196) = CInputProcessor::UnitReservation;
  *(_DWORD *)(*((_DWORD *)this + 1) + 168) = j_CInputProcessor::ChooseSpellDest;
  *(_DWORD *)(*((_DWORD *)this + 1) + 172) = CInputProcessor::SelectSpellDest;
  *(_DWORD *)(*((_DWORD *)this + 1) + 296) = CInputProcessor::SwitchLocalGlobal;
  *(_DWORD *)(*((_DWORD *)this + 1) + 176) = CInputProcessor::InitSettlerAmount;
  *(_DWORD *)(*((_DWORD *)this + 1) + 180) = CInputProcessor::InitFreeCarrier;
  *(_DWORD *)(*((_DWORD *)this + 1) + 184) = CInputProcessor::InitSettlerProduction;
  *(_DWORD *)(*((_DWORD *)this + 1) + 188) = CInputProcessor::InitSettlerSearch;
  *(_DWORD *)(*((_DWORD *)this + 1) + 200) = CInputProcessor::InitGoodAmount;
  *(_DWORD *)(*((_DWORD *)this + 1) + 204) = CInputProcessor::InitTransportPrio;
  *(_DWORD *)(*((_DWORD *)this + 1) + 208) = CInputProcessor::InitGoodDistribution;
  *(_DWORD *)(*((_DWORD *)this + 1) + 216) = CInputProcessor::GoodDeliveringChanged;
  *(_DWORD *)(*((_DWORD *)this + 1) + 212) = CInputProcessor::TransportPrioChanged;
  *(_DWORD *)(*((_DWORD *)this + 1) + 272) = CInputProcessor::UnitProduction;
  *(_DWORD *)(*((_DWORD *)this + 1) + 276) = CInputProcessor::UrgentProduction;
  *(_DWORD *)(*((_DWORD *)this + 1) + 280) = CInputProcessor::WeaponPercent;
  *(_DWORD *)(*((_DWORD *)this + 1) + 284) = CInputProcessor::WeaponAutoproduction;
  *(_DWORD *)(*((_DWORD *)this + 1) + 288) = CInputProcessor::StorageGoodSwitch;
  *(_DWORD *)(*((_DWORD *)this + 1) + 292) = CInputProcessor::VehicleProduction;
  *(_DWORD *)(*((_DWORD *)this + 1) + 328) = CInputProcessor::DestroyBuildupVehicle;
  *(_DWORD *)(*((_DWORD *)this + 1) + 300) = CInputProcessor::SpecialistProduction;
  *(_DWORD *)(*((_DWORD *)this + 1) + 228) = j_CInputProcessor::InitMagicSideBar;
  *(_DWORD *)(*((_DWORD *)this + 1) + 232) = CInputProcessor::InitGroupSideBar;
  *(_DWORD *)(*((_DWORD *)this + 1) + 236) = CInputProcessor::InitAddSoldierSideBar;
  *(_DWORD *)(*((_DWORD *)this + 1) + 240) = CInputProcessor::InitToolSideBar;
  *(_DWORD *)(*((_DWORD *)this + 1) + 244) = CInputProcessor::InitWeaponSideBar;
  *(_DWORD *)(*((_DWORD *)this + 1) + 248) = CInputProcessor::InitGoodsOutSideBar;
  *(_DWORD *)(*((_DWORD *)this + 1) + 252) = CInputProcessor::InitTradeSideBar;
  *(_DWORD *)(*((_DWORD *)this + 1) + 256) = CInputProcessor::InitStorageSideBar;
  *(_DWORD *)(*((_DWORD *)this + 1) + 260) = CInputProcessor::InitEyeCatcherSideBar;
  *(_DWORD *)(*((_DWORD *)this + 1) + 264) = CInputProcessor::InitAddVehicleSideBar;
  *(_DWORD *)(*((_DWORD *)this + 1) + 268) = j_CInputProcessor::CloseSideBar;
  *(_DWORD *)(*((_DWORD *)this + 1) + 304) = CInputProcessor::Morph2FoundationCart;
  *(_DWORD *)(*((_DWORD *)this + 1) + 308) = CInputProcessor::CreateSettlement;
  *(_DWORD *)(*((_DWORD *)this + 1) + 312) = CInputProcessor::Morph2Cart;
  *(_DWORD *)(*((_DWORD *)this + 1) + 316) = CInputProcessor::VehicleUnload;
  *(_DWORD *)(*((_DWORD *)this + 1) + 320) = CInputProcessor::CatapultLoad;
  *(_DWORD *)(*((_DWORD *)this + 1) + 324) = CInputProcessor::DestroyWarMachine;
  *(_DWORD *)(*((_DWORD *)this + 1) + 8) = CInputProcessor::ClearDialog;
  *(_DWORD *)(*((_DWORD *)this + 1) + 332) = CInputProcessor::ZoomAreaState;
  result = this;
  *(_DWORD *)(*((_DWORD *)this + 1) + 336) = CInputProcessor::CamSelection;
  return result;
}


// address=[0x1456ac0]
// Decompiled from char __thiscall CInputProcessor::HandleInternalError(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::HandleInternalError(class CEvn_Logic *) {
  
  OutputDebugStringA("Handle internal error in InputProcessor\n");
  return 0;
}


// address=[0x1456ae0]
// Decompiled from char __thiscall CInputProcessor::Default(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::Default(class CEvn_Logic *) {
  
  CEvn_Event v4; // [esp+Ch] [ebp-40h] BYREF
  CEvn_Event v5; // [esp+24h] [ebp-28h] BYREF
  int v6; // [esp+48h] [ebp-4h]

  CInputProcessor::TidyUp(this);
  *((_DWORD *)this + 7) = 0;
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
bool  CInputProcessor::NewDialogClear(class CEvn_Logic *) {
  
  CInputProcessor::DeSelectAll(this);
  CLogic::SetFillDialogInfos(g_pLogic, 0, 0, 0);
  CInputProcessor::Default(this, a2);
  return 0;
}


// address=[0x1456c50]
// Decompiled from char __thiscall CInputProcessor::ClearDialog(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::ClearDialog(class CEvn_Logic *) {
  
  CInputProcessor::Clear(this);
  return 0;
}


// address=[0x1456c70]
// Decompiled from char __thiscall CInputProcessor::TryBuild(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::TryBuild(class CEvn_Logic *) {
  
  int LocalPlayerId; // eax
  int v4; // [esp+0h] [ebp-4h]

  LocalPlayerId = CPlayerManager::GetLocalPlayerId(this);
  if ( !CPlayerManager::IsAlive(LocalPlayerId) )
    return 0;
  CInputProcessor::DeSelectAll(v4);
  CWorldManager::ClearHelperObject();
  *(_DWORD *)(v4 + 80) = 4;
  *(_DWORD *)(v4 + 16) = *((_DWORD *)a2 + 3);
  IGfxEngine::EnableIconLayer((IGfxEngine *)g_pGfxEngine, 1);
  IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 3);
  return 1;
}


// address=[0x1456ce0]
// Decompiled from char __thiscall CInputProcessor::Build(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::Build(class CEvn_Logic *) {
  
  int LocalPlayerId; // eax
  char v3; // al
  int v5; // [esp-8h] [ebp-50h]
  unsigned int v6; // [esp-8h] [ebp-50h]
  unsigned int v7; // [esp+4h] [ebp-44h]
  int v8; // [esp+Ch] [ebp-3Ch]
  int v9; // [esp+10h] [ebp-38h]
  _BYTE v11[32]; // [esp+18h] [ebp-30h] BYREF
  int v12; // [esp+44h] [ebp-4h]

  *((_DWORD *)this + 7) = 0;
  v8 = *((unsigned __int16 *)a2 + 6);
  v9 = (unsigned __int16)HIWORD(*((_DWORD *)a2 + 3));
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(*((_DWORD *)this + 4));
  if ( (int)CBuildingMgr::CheckForBuild((CBuildingMgr *)g_cBuildingMgr, v8, v9, LocalPlayerId, v5, 0) <= 0 )
    return 1;
  v7 = Y16X16::PackXYFast(v8, v9);
  v3 = CPlayerManager::GetLocalPlayerId(0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v11, 0x13A1u, *((_DWORD *)this + 4), v7, v3, v6, 0);
  v12 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1603, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v11);
  CInputProcessor::Default(this, a2);
  CFsm::GenerateEvent(401, 0);
  v12 = -1;
  CEvn_Logic::~CEvn_Logic(v11);
  return 1;
}


// address=[0x1456e30]
// Decompiled from char __thiscall CInputProcessor::ShowWorkingArea(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::ShowWorkingArea(class CEvn_Logic *) {
  
  unsigned __int16 *v2; // eax
  unsigned __int8 *v3; // eax
  unsigned __int16 *v5; // eax

  if ( std::vector<unsigned short>::size(&CInputProcessor::m_vSelection)
    && (v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0),
        v3 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(*v2),
        IEntity::ObjType(v3) == 8) )
  {
    *((_DWORD *)this + 20) = 3;
    v5 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
    CBuildingMgr::ShowWorkingArea((CBuildingMgr *)g_cBuildingMgr, *v5);
    IGfxEngine::EnableIconLayer((IGfxEngine *)g_pGfxEngine, 1);
    return 1;
  }
  else
  {
    CInputProcessor::Default(this, a2);
    CFsm::GenerateEvent(401, 0);
    return 0;
  }
}


// address=[0x1456ed0]
// Decompiled from char __thiscall CInputProcessor::SetWorkingArea(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SetWorkingArea(class CEvn_Logic *) {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax
  char LocalPlayerId; // [esp-Ch] [ebp-54h]
  unsigned int v6; // [esp-8h] [ebp-50h]
  unsigned int v7; // [esp+4h] [ebp-44h]
  int v9; // [esp+Ch] [ebp-3Ch] BYREF
  int v10; // [esp+10h] [ebp-38h] BYREF
  int v11; // [esp+14h] [ebp-34h]
  _BYTE v12[32]; // [esp+18h] [ebp-30h] BYREF
  int v13; // [esp+44h] [ebp-4h]

  v11 = *((_DWORD *)a2 + 3);
  v9 = Y16X16::UnpackXFast(v11);
  v10 = Y16X16::UnpackYFast(v11);
  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  if ( !CBuildingMgr::IsGoodWorkingAreaCenter((CBuildingMgr *)g_cBuildingMgr, *v2, &v9, &v10) )
    return 1;
  v7 = Y16X16::PackXYFast(v9, v10);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v12, 0x1389u, *v3, v7, LocalPlayerId, v6, 0);
  v13 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1742, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v12);
  CInputProcessor::Default(this, a2);
  CFsm::GenerateEvent(401, 0);
  v13 = -1;
  CEvn_Logic::~CEvn_Logic(v12);
  return 1;
}


// address=[0x1457020]
// Decompiled from char __thiscall CInputProcessor::TryCrushBuilding(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::TryCrushBuilding(class CEvn_Logic *) {
  
  unsigned __int16 *v2; // eax
  unsigned __int8 *v3; // eax
  int v4; // esi
  unsigned __int16 *v5; // eax
  CBuilding *v6; // eax
  int v8; // [esp+0h] [ebp-8h]

  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  v3 = (unsigned __int8 *)CBuildingMgr::operator[](*v2);
  v4 = IEntity::OwnerId(v3);
  if ( v4 != CPlayerManager::GetLocalPlayerId(v8)
    && BBSupportDbgReport(
         2,
         "Logic\\InputProcessor.cpp",
         1624,
         "g_cBuildingMgr[ m_vSelection[ 0 ] ].OwnerId() == CPlayerManager::GetLocalPlayerId()") == 1 )
  {
    __debugbreak();
  }
  v5 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  v6 = (CBuilding *)CBuildingMgr::operator[](*v5);
  CBuilding::TryCrushBuilding(v6);
  return 1;
}


// address=[0x14570a0]
// Decompiled from char __thiscall CInputProcessor::CrushBuilding(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::CrushBuilding(class CEvn_Logic *) {
  
  unsigned __int16 *v2; // eax
  char LocalPlayerId; // [esp-Ch] [ebp-44h]
  unsigned int v5; // [esp-8h] [ebp-40h]
  _BYTE v7[32]; // [esp+8h] [ebp-30h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  if ( *((_DWORD *)a2 + 2) )
  {
    LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
    v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
    CEvn_Logic::CEvn_Logic((CEvn_Logic *)v7, 0x138Au, *v2, 0, LocalPlayerId, v5, 0);
    v8 = 0;
    if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1654, "g_pNetworkEngine != NULL") == 1 )
      __debugbreak();
    if ( g_pNetworkEngine )
      INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v7);
    CInputProcessor::Clear(this);
    CFsm::GenerateEvent(401, 0);
    v8 = -1;
    CEvn_Logic::~CEvn_Logic(v7);
  }
  else
  {
    CInputProcessor::RequestDialog();
  }
  return 1;
}


// address=[0x14571a0]
// Decompiled from char __thiscall CInputProcessor::SwitchBuilding(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SwitchBuilding(class CEvn_Logic *) {
  
  unsigned __int16 *v2; // eax
  char LocalPlayerId; // [esp-Ch] [ebp-48h]
  unsigned int v5; // [esp-8h] [ebp-44h]
  _BYTE v6[32]; // [esp+Ch] [ebp-30h] BYREF
  int v7; // [esp+38h] [ebp-4h]

  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v6, 0x138Bu, *v2, 0, LocalPlayerId, v5, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1683, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v6);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(v6);
  return 1;
}


// address=[0x1457270]
// Decompiled from char __thiscall CInputProcessor::PrioBuildingSite(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::PrioBuildingSite(class CEvn_Logic *) {
  
  unsigned __int16 *v2; // eax
  char LocalPlayerId; // [esp-Ch] [ebp-48h]
  unsigned int v5; // [esp-8h] [ebp-44h]
  _BYTE v6[32]; // [esp+Ch] [ebp-30h] BYREF
  int v7; // [esp+38h] [ebp-4h]

  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v6, 0x138Cu, *v2, 0, LocalPlayerId, v5, 0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1707, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v6);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(v6);
  return 1;
}


// address=[0x1457340]
// Decompiled from char __thiscall CInputProcessor::SelectNextBuilding(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SelectNextBuilding(class CEvn_Logic *) {
  
  unsigned __int16 *v3; // eax
  unsigned __int16 *v4; // eax
  int LocalPlayerId; // eax
  _DWORD *v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // [esp-8h] [ebp-4Ch]
  int v9; // [esp-4h] [ebp-48h]
  unsigned __int8 *BuildingPtr; // [esp+8h] [ebp-3Ch]
  int v11; // [esp+Ch] [ebp-38h]
  __int16 v12; // [esp+12h] [ebp-32h] BYREF
  int v13; // [esp+14h] [ebp-30h]
  CInputProcessor *v14; // [esp+18h] [ebp-2Ch]
  CEvn_Event v15; // [esp+1Ch] [ebp-28h] BYREF
  int v16; // [esp+40h] [ebp-4h]

  v14 = this;
  v11 = *((_DWORD *)a2 + 3);
  if ( !v11 )
  {
    if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection)
      && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 999, "m_vSelection.size() > 0") == 1 )
    {
      __debugbreak();
    }
    if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    {
      CInputProcessor::Default(v14, a2);
      CFsm::GenerateEvent(401, 0);
      return 0;
    }
    v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
    v4 = (unsigned __int16 *)CMapObjectMgr::EntityPtr(*v3);
    v11 = IEntity::Type(v4);
  }
  CInputProcessor::DeSelectAll(v14);
  CInputProcessor::Default(v14, a2);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(v11);
  if ( CBuildingMgr::GetNextBuilding((CBuildingMgr *)g_cBuildingMgr, LocalPlayerId, v9) )
  {
    v13 = IEntity::ID();
    if ( !v13 )
      return 0;
    v12 = v13;
    std::vector<unsigned short>::push_back(&v12);
    CInputProcessor::RequestDialog();
    v6 = (_DWORD *)CMapObjectMgr::EntityPtr(v13);
    IEntity::SetFlagBits(v6, Selected);
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
    CFsm::GenerateEvent(401, 0);
    return 0;
  }
}


// address=[0x1457550]
// Decompiled from char __thiscall CInputProcessor::SelectBuilding(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SelectBuilding(class CEvn_Logic *) {
  
  unsigned __int16 *v3; // eax
  unsigned __int16 *v4; // eax
  int LocalPlayerId; // eax
  _DWORD *v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // [esp-8h] [ebp-4Ch]
  int v9; // [esp-4h] [ebp-48h]
  unsigned __int8 *BuildingPtr; // [esp+8h] [ebp-3Ch]
  int v11; // [esp+Ch] [ebp-38h]
  __int16 v12; // [esp+12h] [ebp-32h] BYREF
  int v13; // [esp+14h] [ebp-30h]
  CInputProcessor *v14; // [esp+18h] [ebp-2Ch]
  CEvn_Event v15; // [esp+1Ch] [ebp-28h] BYREF
  int v16; // [esp+40h] [ebp-4h]

  v14 = this;
  v11 = *((_DWORD *)a2 + 3);
  if ( !v11 )
  {
    if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection)
      && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1070, "m_vSelection.size() > 0") == 1 )
    {
      __debugbreak();
    }
    if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    {
      CInputProcessor::Default(v14, a2);
      CFsm::GenerateEvent(401, 0);
      return 0;
    }
    v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
    v4 = (unsigned __int16 *)CMapObjectMgr::EntityPtr(*v3);
    v11 = IEntity::Type(v4);
  }
  CInputProcessor::DeSelectAll(v14);
  CInputProcessor::Default(v14, a2);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(v11);
  if ( CBuildingMgr::GetBuilding((CBuildingMgr *)g_cBuildingMgr, LocalPlayerId, v9) )
  {
    v13 = IEntity::ID();
    if ( !v13 )
      return 0;
    v12 = v13;
    std::vector<unsigned short>::push_back(&v12);
    CInputProcessor::RequestDialog();
    v6 = (_DWORD *)CMapObjectMgr::EntityPtr(v13);
    IEntity::SetFlagBits(v6, Selected);
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v13);
    CBuilding::NotifySelected(BuildingPtr);
    v8 = IEntity::X(BuildingPtr);
    v7 = IEntity::Y(BuildingPtr);
    CEvn_Event::CEvn_Event(&v15, 0x13u, v7, v8, 0);
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
    CFsm::GenerateEvent(401, 0);
    return 0;
  }
}


// address=[0x1457760]
// Decompiled from char __thiscall CInputProcessor::MarkNextBuilding(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::MarkNextBuilding(class CEvn_Logic *) {
  
  int LocalPlayerId; // eax
  unsigned int v3; // eax
  unsigned int v5; // [esp-8h] [ebp-40h]
  int v6; // [esp-4h] [ebp-3Ch]
  _DWORD *NextBuilding; // [esp+Ch] [ebp-2Ch]
  CEvn_Event v8; // [esp+10h] [ebp-28h] BYREF
  int v9; // [esp+34h] [ebp-4h]

  LocalPlayerId = CPlayerManager::GetLocalPlayerId(*((_DWORD *)a2 + 3));
  NextBuilding = (_DWORD *)CBuildingMgr::GetNextBuilding((CBuildingMgr *)g_cBuildingMgr, LocalPlayerId, v6);
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
bool  CInputProcessor::InitExtraMenu(class CEvn_Logic *) {
  
  CLogic::SwitchExtraInfoMenu(g_pLogic, *((_DWORD *)a2 + 2) == 1);
  CStatistic::FillExtraInfo((CStatistic *)&g_cStatistic);
  return 0;
}


// address=[0x1457890]
// Decompiled from char __thiscall CInputProcessor::SelectNextVehicle(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SelectNextVehicle(class CEvn_Logic *) {
  
  unsigned __int16 *v3; // eax
  int LocalPlayerId; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-8h] [ebp-4Ch]
  int v7; // [esp-4h] [ebp-48h]
  int v8; // [esp+4h] [ebp-40h]
  int v9; // [esp+8h] [ebp-3Ch]
  __int16 v10; // [esp+Eh] [ebp-36h] BYREF
  CInputProcessor *v11; // [esp+10h] [ebp-34h]
  int FirstVehicleId; // [esp+14h] [ebp-30h]
  struct CVehicle *VehiclePtr; // [esp+18h] [ebp-2Ch]
  CEvn_Event v14; // [esp+1Ch] [ebp-28h] BYREF
  int v15; // [esp+40h] [ebp-4h]

  v11 = this;
  if ( !a2 && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 878, "_pEvent!= NULL") == 1 )
    __debugbreak();
  if ( !a2 )
    return 0;
  VehiclePtr = 0;
  v8 = 0;
  v9 = *((_DWORD *)a2 + 3);
  if ( !v9 )
  {
    if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection)
      && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 890, "m_vSelection.size() > 0") == 1 )
    {
      __debugbreak();
    }
    if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    {
      CInputProcessor::Default(v11, a2);
      CFsm::GenerateEvent(401, 0);
      return 0;
    }
    v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
    VehiclePtr = CVehicleMgr::GetVehiclePtr(*v3);
    v8 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
    if ( !VehiclePtr && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 901, "pVehicle!=NULL") == 1 )
      __debugbreak();
    if ( !VehiclePtr )
      return 0;
    v9 = IEntity::Type((unsigned __int16 *)VehiclePtr);
  }
  CInputProcessor::DeSelectAll(v11);
  CInputProcessor::Default(v11, a2);
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
      LocalPlayerId = CPlayerManager::GetLocalPlayerId(v9);
      FirstVehicleId = CVehicleMgr::GetFirstVehicleId((CVehicleMgr *)&g_cVehicleMgr, LocalPlayerId, v7);
    }
    VehiclePtr = CVehicleMgr::GetVehiclePtr(FirstVehicleId);
  }
  while ( FirstVehicleId != v8 && IEntity::FlagBits(VehiclePtr, OnBoard) );
  if ( FirstVehicleId && VehiclePtr )
  {
    v10 = FirstVehicleId;
    std::vector<unsigned short>::push_back(&v10);
    CInputProcessor::RequestDialog();
    if ( IEntity::FlagBits(VehiclePtr, (EntityFlag)0x4000u) )
      IEntity::SetFlagBits(VehiclePtr, (EntityFlag)0x400u);
    else
      IEntity::SetFlagBits(VehiclePtr, Selected);
    v6 = IEntity::X(VehiclePtr);
    v5 = IEntity::Y(VehiclePtr);
    CEvn_Event::CEvn_Event(&v14, 0x13u, v5, v6, 0);
    v15 = 0;
    if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 971, "g_pEvnEngine != NULL") == 1 )
      __debugbreak();
    if ( g_pEvnEngine )
      IEventEngine::SendAMessage(g_pEvnEngine, &v14);
    v15 = -1;
    CEvn_Event::~CEvn_Event(&v14);
  }
  else
  {
    CFsm::GenerateEvent(401, 0);
  }
  return 0;
}


// address=[0x1457b80]
// Decompiled from char __thiscall CInputProcessor::BuildingAmount(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::BuildingAmount(class CEvn_Logic *) {
  
  void **v3; // [esp+0h] [ebp-Ch]
  int v5; // [esp+8h] [ebp-4h]

  v5 = *((_DWORD *)a2 + 3);
  if ( !v5 || *(_DWORD *)(v5 + 4) != 28 )
    return 0;
  v3 = (void **)*((_DWORD *)a2 + 3);
  CBuildingMgr::FillBuildingAmount(v3, 0, *((unsigned __int8 *)this + 105));
  CLogic::SetFillDialogInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, bool))CBuildingMgr::FillBuildingAmount,
    (struct CInfoExchange *)v3,
    *((_BYTE *)this + 105));
  return 0;
}


// address=[0x1457bf0]
// Decompiled from char __thiscall CInputProcessor::DestroyBuildupVehicle(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::DestroyBuildupVehicle(class CEvn_Logic *) {
  
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
bool  CInputProcessor::FillTower(class CEvn_Logic *) {
  
  unsigned __int16 *v2; // eax
  unsigned int v4; // [esp-10h] [ebp-4Ch]
  char LocalPlayerId; // [esp-Ch] [ebp-48h]
  unsigned int v6; // [esp-8h] [ebp-44h]
  _BYTE v7[32]; // [esp+Ch] [ebp-30h] BYREF
  int v8; // [esp+38h] [ebp-4h]

  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  v4 = *((_DWORD *)a2 + 3);
  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v7, 0x13A7u, *v2, v4, LocalPlayerId, v6, 0);
  v8 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1772, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v7);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(v7);
  return 1;
}


// address=[0x1457e20]
// Decompiled from char __thiscall CInputProcessor::EmptyTower(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::EmptyTower(class CEvn_Logic *) {
  
  int v2; // esi
  char LocalPlayerId; // al
  unsigned int v5; // [esp-8h] [ebp-4Ch]
  unsigned int v6; // [esp+Ch] [ebp-38h]
  _BYTE v7[32]; // [esp+14h] [ebp-30h] BYREF
  int v8; // [esp+40h] [ebp-4h]

  v2 = *((unsigned __int16 *)a2 + 4);
  v6 = (*(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0) << 16) | v2;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v7, 0x13A8u, v6, *((_DWORD *)a2 + 3), LocalPlayerId, v5, 0);
  v8 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1802, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v7);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(v7);
  return 1;
}


// address=[0x1457f10]
// Decompiled from char __thiscall CInputProcessor::ChooseTradeDest(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::ChooseTradeDest(class CEvn_Logic *) {
  
  *((_DWORD *)this + 20) = 7;
  *((_DWORD *)this + 4) = *((_DWORD *)a2 + 3);
  IGfxEngine::EnableIconLayer((IGfxEngine *)g_pGfxEngine, 1);
  IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 6);
  return 1;
}


// address=[0x1457f60]
// Decompiled from char __thiscall CInputProcessor::SelectTradeDest(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SelectTradeDest(class CEvn_Logic *) {
  
  unsigned __int16 *v2; // eax
  int v3; // eax
  unsigned __int16 *v4; // eax
  unsigned int v6; // [esp-10h] [ebp-70h]
  char LocalPlayerId; // [esp-Ch] [ebp-6Ch]
  unsigned int v8; // [esp-8h] [ebp-68h]
  CTradingBuildingRole *v9; // [esp+4h] [ebp-5Ch]
  int v10; // [esp+8h] [ebp-58h]
  int v11; // [esp+Ch] [ebp-54h]
  int v12; // [esp+10h] [ebp-50h]
  unsigned __int8 *BuildingPtr; // [esp+18h] [ebp-48h]
  int v15; // [esp+1Ch] [ebp-44h]
  int v16; // [esp+20h] [ebp-40h]
  int v17; // [esp+24h] [ebp-3Ch]
  unsigned __int8 *v18; // [esp+28h] [ebp-38h]
  int i; // [esp+2Ch] [ebp-34h]
  _BYTE v20[32]; // [esp+30h] [ebp-30h] BYREF
  int v21; // [esp+5Ch] [ebp-4h]

  v11 = *((unsigned __int16 *)a2 + 6);
  v10 = (unsigned __int16)HIWORD(*((_DWORD *)a2 + 3));
  v12 = CSpiralOffsets::Last(5);
  for ( i = 0; i <= v12; ++i )
  {
    v16 = v11 + CSpiralOffsets::DeltaX(i);
    v17 = v10 + CSpiralOffsets::DeltaY(i);
    if ( (unsigned __int8)CWorldManager::InWorld(v16, v17) )
    {
      v15 = CWorldManager::MapObjectId(v16, v17);
      if ( v15 )
      {
        v18 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(v15);
        if ( IEntity::ObjType(v18) == 8 )
        {
          v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
          BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *v2);
          v9 = (CTradingBuildingRole *)CBuilding::Role(BuildingPtr);
          v3 = IEntity::ID();
          if ( CTradingBuildingRole::IsPossibleTradeTarget(v9, v3) )
          {
            LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
            v6 = IEntity::ID();
            v4 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
            CEvn_Logic::CEvn_Logic((CEvn_Logic *)v20, 0x138Du, *v4, v6, LocalPlayerId, v8, 0);
            v21 = 0;
            if ( !g_pNetworkEngine
              && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1873, "g_pNetworkEngine != NULL") == 1 )
            {
              __debugbreak();
            }
            if ( g_pNetworkEngine )
              INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v20);
            CBuilding::NotifySelected(BuildingPtr);
            CInputProcessor::Default(this, a2);
            CFsm::GenerateEvent(401, 0);
            v21 = -1;
            CEvn_Logic::~CEvn_Logic(v20);
          }
        }
      }
    }
  }
  return 1;
}


// address=[0x1458160]
// Decompiled from char __thiscall CInputProcessor::TransportGoods(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::TransportGoods(class CEvn_Logic *) {
  
  int v2; // esi
  char LocalPlayerId; // al
  unsigned int v5; // [esp-8h] [ebp-4Ch]
  unsigned int v6; // [esp+Ch] [ebp-38h]
  _BYTE v7[32]; // [esp+14h] [ebp-30h] BYREF
  int v8; // [esp+40h] [ebp-4h]

  v2 = *((unsigned __int16 *)a2 + 4);
  v6 = (*(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0) << 16) | v2;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v7, 0x138Eu, v6, *((_DWORD *)a2 + 3), LocalPlayerId, v5, 0);
  v8 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1913, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v7);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(v7);
  return 1;
}


// address=[0x1458250]
// Decompiled from char __thiscall CInputProcessor::TradeWith(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::TradeWith(class CEvn_Logic *) {
  
  int v2; // esi
  char LocalPlayerId; // al
  unsigned int v5; // [esp-8h] [ebp-4Ch]
  unsigned int v6; // [esp+Ch] [ebp-38h]
  _BYTE v7[32]; // [esp+14h] [ebp-30h] BYREF
  int v8; // [esp+40h] [ebp-4h]

  v2 = *((unsigned __int16 *)a2 + 4);
  v6 = (*(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0) << 16) | v2;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v7, 0x138Fu, v6, *((_DWORD *)a2 + 3), LocalPlayerId, v5, 0);
  v8 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1943, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v7);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(v7);
  return 1;
}


// address=[0x1458340]
// Decompiled from char __thiscall CInputProcessor::TradeGoods(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::TradeGoods(class CEvn_Logic *) {
  
  unsigned __int16 *v2; // eax
  unsigned int v4; // [esp-10h] [ebp-4Ch]
  char LocalPlayerId; // [esp-Ch] [ebp-48h]
  unsigned int v6; // [esp-8h] [ebp-44h]
  _BYTE v7[32]; // [esp+Ch] [ebp-30h] BYREF
  int v8; // [esp+38h] [ebp-4h]

  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  v4 = *((_DWORD *)a2 + 2);
  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v7, 0x1390u, *v2, v4, LocalPlayerId, v6, 0);
  v8 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1967, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v7);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(v7);
  return 1;
}


// address=[0x1458420]
// Decompiled from char __thiscall CInputProcessor::SetTradePlayerStatus(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SetTradePlayerStatus(class CEvn_Logic *) {
  
  char LocalPlayerId; // al
  unsigned int v4; // [esp-8h] [ebp-48h]
  unsigned int v5; // [esp+8h] [ebp-38h]
  _BYTE v6[32]; // [esp+10h] [ebp-30h] BYREF
  int v7; // [esp+3Ch] [ebp-4h]

  v5 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  if ( !CMapObjectMgr::ValidEntityId(v5)
    && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1980, "g_pMapObjectMgr->ValidEntityId(iBuildingID)") == 1 )
  {
    __debugbreak();
  }
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  CEvn_Logic::CEvn_Logic(
    (CEvn_Logic *)v6,
    0x13BAu,
    ((unsigned __int16)v5 << 16) | *((unsigned __int16 *)a2 + 4),
    *((_DWORD *)a2 + 3),
    LocalPlayerId,
    v4,
    0);
  v7 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1990, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v6);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(v6);
  return 1;
}


// address=[0x1458540]
// Decompiled from char __thiscall CInputProcessor::ChooseSpellDest(_DWORD *this, int a2)
bool  CInputProcessor::ChooseSpellDest(class CEvn_Logic *) {
  
  this[5] = *(_DWORD *)(a2 + 8);
  return 1;
}


// address=[0x1458560]
// Decompiled from char __thiscall CInputProcessor::SelectSpellDest(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SelectSpellDest(class CEvn_Logic *) {
  
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
bool  CInputProcessor::InitSettlerAmount(class CEvn_Logic *) {
  
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
bool  CInputProcessor::InitFreeCarrier(class CEvn_Logic *) {
  
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
bool  CInputProcessor::InitSettlerProduction(class CEvn_Logic *) {
  
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
bool  CInputProcessor::InitSettlerSearch(class CEvn_Logic *) {
  
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
bool  CInputProcessor::InitGoodAmount(class CEvn_Logic *) {
  
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
bool  CInputProcessor::InitTransportPrio(class CEvn_Logic *) {
  
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
bool  CInputProcessor::InitGoodDistribution(class CEvn_Logic *) {
  
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
bool  CInputProcessor::GoodDeliveringChanged(class CEvn_Logic *) {
  
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
bool  CInputProcessor::TransportPrioChanged(class CEvn_Logic *) {
  
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
bool  CInputProcessor::UnitProduction(class CEvn_Logic *) {
  
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
bool  CInputProcessor::UrgentProduction(class CEvn_Logic *) {
  
  int v2; // esi
  char LocalPlayerId; // al
  unsigned int v5; // [esp-8h] [ebp-4Ch]
  unsigned int v6; // [esp+Ch] [ebp-38h]
  _BYTE v7[32]; // [esp+14h] [ebp-30h] BYREF
  int v8; // [esp+40h] [ebp-4h]

  v2 = *((unsigned __int16 *)a2 + 4);
  v6 = (*(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0) << 16) | v2;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v7, 0x13A9u, v6, *((_DWORD *)a2 + 3), LocalPlayerId, v5, 0);
  v8 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1484, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v7);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(v7);
  return 0;
}


// address=[0x14590a0]
// Decompiled from char __thiscall CInputProcessor::WeaponPercent(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::WeaponPercent(class CEvn_Logic *) {
  
  unsigned __int16 *v2; // eax
  unsigned int v4; // [esp-10h] [ebp-4Ch]
  char LocalPlayerId; // [esp-Ch] [ebp-48h]
  unsigned int v6; // [esp-8h] [ebp-44h]
  _BYTE v7[32]; // [esp+Ch] [ebp-30h] BYREF
  int v8; // [esp+38h] [ebp-4h]

  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  v4 = *((_DWORD *)a2 + 2);
  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v7, 0x13AAu, *v2, v4, LocalPlayerId, v6, 0);
  v8 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1428, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v7);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(v7);
  return 0;
}


// address=[0x1459180]
// Decompiled from char __thiscall CInputProcessor::WeaponAutoproduction(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::WeaponAutoproduction(class CEvn_Logic *) {
  
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
bool  CInputProcessor::StorageGoodSwitch(class CEvn_Logic *) {
  
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
bool  CInputProcessor::VehicleProduction(class CEvn_Logic *) {
  
  int v2; // esi
  char LocalPlayerId; // al
  unsigned int v5; // [esp-8h] [ebp-4Ch]
  unsigned int v6; // [esp+Ch] [ebp-38h]
  _BYTE v7[32]; // [esp+14h] [ebp-30h] BYREF
  int v8; // [esp+40h] [ebp-4h]

  v2 = *((unsigned __int16 *)a2 + 4);
  v6 = (*(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0) << 16) | v2;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v7, 0x13B0u, v6, *((_DWORD *)a2 + 3), LocalPlayerId, v5, 0);
  v8 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 1373, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v7);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(v7);
  return 0;
}


// address=[0x1459440]
// Decompiled from char __thiscall CInputProcessor::GotoVehicleGroupMenu(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::GotoVehicleGroupMenu(class CEvn_Logic *) {
  
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
bool  CInputProcessor::SwitchLocalGlobal(class CEvn_Logic *) {
  
  *((_BYTE *)this + 105) = *((_BYTE *)this + 105) == 0;
  CLogic::SetLocalGlobalSwitch(g_pLogic, *((_BYTE *)this + 105));
  return 0;
}


// address=[0x1459590]
// Decompiled from char __thiscall CInputProcessor::SpecialistProduction(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SpecialistProduction(class CEvn_Logic *) {
  
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
bool  CInputProcessor::PrepareBoxSelection(class CEvn_Logic *) {
  
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  int LocalPlayerId; // eax
  int v8; // [esp+0h] [ebp-58h]
  CEvn_Event *v9; // [esp+4h] [ebp-54h]
  int SelectionTypeOfCurrentSelection; // [esp+Ch] [ebp-4Ch]
  int v11; // [esp+10h] [ebp-48h] BYREF
  int v12; // [esp+14h] [ebp-44h] BYREF
  int v13; // [esp+18h] [ebp-40h] BYREF
  int v14; // [esp+1Ch] [ebp-3Ch] BYREF
  int v15; // [esp+20h] [ebp-38h]
  int v16; // [esp+24h] [ebp-34h]
  bool v17; // [esp+2Ah] [ebp-2Eh]
  bool v18; // [esp+2Bh] [ebp-2Dh]
  _DWORD *v19; // [esp+2Ch] [ebp-2Ch]
  CEvn_Event v20; // [esp+30h] [ebp-28h] BYREF
  int v21; // [esp+54h] [ebp-4h]

  v19 = this;
  CInputProcessor::TidyUp(this);
  v18 = *((int *)a2 + 2) < 0;
  v17 = v18;
  v16 = *((_DWORD *)a2 + 3);
  v15 = *((_DWORD *)a2 + 2) & 0x7FFFFFFF;
  v13 = Y16X16::UnpackXFast(v16);
  v11 = Y16X16::UnpackYFast(v16);
  v14 = Y16X16::UnpackXFast(v15);
  v12 = Y16X16::UnpackYFast(v15);
  v2 = (_DWORD *)BB::Min<int>(&v13, &v14);
  v19[15] = *v2;
  v3 = (_DWORD *)BB::Max<int>(&v13, &v14);
  v19[17] = *v3;
  v4 = (_DWORD *)BB::Min<int>(&v11, &v12);
  v19[16] = *v4;
  v5 = (_DWORD *)BB::Max<int>(&v11, &v12);
  v19[18] = *v5;
  *((_BYTE *)v19 + 106) = 1;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(v8);
  v19[14] = LocalPlayerId;
  SelectionTypeOfCurrentSelection = CInputProcessor::GetSelectionTypeOfCurrentSelection((CInputProcessor *)v19);
  if ( v17 && SelectionTypeOfCurrentSelection )
  {
    v19[19] = SelectionTypeOfCurrentSelection;
    v19[25] = 1;
  }
  else
  {
    CInputProcessor::DeSelectAll(v19);
    v19[19] = 0;
    v19[25] = 0;
  }
  if ( !g_pEvnEngine )
    return 1;
  v9 = CEvn_Event::CEvn_Event(&v20, 0x259u, 0, 0, 0);
  v21 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, v9);
  v21 = -1;
  CEvn_Event::~CEvn_Event(&v20);
  return 1;
}


// address=[0x1459860]
// Decompiled from char __thiscall CInputProcessor::DotSelection(void *this, CEvn_Event *a2)
bool  CInputProcessor::DotSelection(class CEvn_Logic *) {
  
  unsigned __int16 *v2; // eax
  const struct IEntity *v3; // eax
  const struct IEntity *v4; // eax
  int v5; // eax
  unsigned __int16 *v6; // eax
  CEvn_Event *v8; // [esp+4h] [ebp-68h]
  struct CBuilding *BuildingPtr; // [esp+Ch] [ebp-60h]
  int v10; // [esp+10h] [ebp-5Ch]
  int x; // [esp+14h] [ebp-58h]
  int y; // [esp+18h] [ebp-54h]
  bool v13; // [esp+20h] [ebp-4Ch]
  unsigned __int8 *entity; // [esp+24h] [ebp-48h] MAPDST
  __int16 v15; // [esp+2Ah] [ebp-42h] BYREF
  int EntitySelectionType; // [esp+2Ch] [ebp-40h]
  int foundEntityId; // [esp+30h] [ebp-3Ch]
  char v21; // [esp+3Fh] [ebp-2Dh]
  bool v22; // [esp+40h] [ebp-2Ch] MAPDST
  bool appendToSelection; // [esp+41h] [ebp-2Bh] MAPDST
  char v25; // [esp+43h] [ebp-29h]
  CEvn_Event v26; // [esp+44h] [ebp-28h] BYREF
  int v27; // [esp+68h] [ebp-4h]

  x = Y16X16::UnpackXFast(a2->lparam);
  y = Y16X16::UnpackYFast(a2->lparam);
  appendToSelection = (a2->wparam & 8) != 0;
  foundEntityId = CInputProcessor::SelectOne(this, x, y);
  if ( foundEntityId <= 0 )
    entity = 0;
  else
    entity = (unsigned __int8 *)CMapObjectMgr::EntityPtr(foundEntityId);
  if ( entity )
  {
    CLogic::SetFillDialogInfos(g_pLogic, 0, 0, 0);
    v22 = IEntity::FlagBits(entity, (EntityFlag)0x4000u) != 0;
    v21 = 1;
    v25 = 1;
    if ( appendToSelection && !v22 )
    {
      EntitySelectionType = 0;
      if ( std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
      {
        v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
        v3 = (const struct IEntity *)CMapObjectMgr::EntityPtr(*v2);
        EntitySelectionType = CInputProcessor::GetEntitySelectionType(v3);
      }
      v4 = (const struct IEntity *)CMapObjectMgr::EntityPtr(foundEntityId);
      v10 = CInputProcessor::GetEntitySelectionType(v4);
      v13 = !EntitySelectionType || EntitySelectionType == 0x10000 || EntitySelectionType != v10;
      v25 = v13;
      if ( !v13 && IEntity::FlagBits(entity, Selected) )
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
      std::vector<unsigned short>::push_back(&v15);
      if ( v22 )
      {
        IEntity::SetFlagBits(entity, (EntityFlag)0x400u);
      }
      else
      {
        IEntity::SetFlagBits(entity, Selected);
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
    CInputProcessor::RequestDialog();
  }
  else if ( !appendToSelection )
  {
    CLogic::SetFillDialogInfos(g_pLogic, 0, 0, 0);
    CInputProcessor::DeSelectAll(this);
    CFsm::GenerateEvent(401, 0);
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
bool  CInputProcessor::SelectTypeInSurrounding(class CEvn_Logic *) {
  
  int v2; // eax
  int v4; // [esp-4h] [ebp-18h]
  int v5; // [esp+0h] [ebp-14h]
  int v6; // [esp+4h] [ebp-10h]
  struct IEntity *v7; // [esp+8h] [ebp-Ch]
  int v8; // [esp+Ch] [ebp-8h]

  v5 = *((unsigned __int16 *)a2 + 6);
  v6 = (unsigned __int16)HIWORD(*((_DWORD *)a2 + 3));
  CInputProcessor::DeSelectAll(this);
  if ( !*((_DWORD *)this + 3) )
  {
    v8 = CInputProcessor::SelectOne(this, v5, v6);
    if ( v8 )
    {
      *((_DWORD *)this + 19) = CInputProcessor::GetEntitySelectionType(v8);
      *((_DWORD *)this + 25) = 2;
      v7 = CMapObjectMgr::Entity(v8);
      v4 = IEntity::Y(v7);
      v2 = IEntity::X(v7);
      dword_3F1F60C = CWorldManager::SectorId(v2, v4);
      dword_3F1F608 = *((_DWORD *)a2 + 2) & 0x10;
      CInputProcessor::SelectAllInSurrounding(this, v5, v6);
    }
  }
  CLogic::SetFillDialogInfos(g_pLogic, 0, 0, 0);
  CInputProcessor::RequestDialog();
  return 1;
}


// address=[0x1459c50]
// Decompiled from char __thiscall CInputProcessor::SelectGroup(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SelectGroup(class CEvn_Logic *) {
  
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
    if ( IEntity::FlagBits(v7, Selectable) )
    {
      IEntity::SetFlagBits(v7, Selected);
      v14 = v6;
      std::vector<unsigned short>::push_back(&v14);
    }
  }
  CInputProcessor::RequestDialog();
  return 0;
}


// address=[0x1459df0]
// Decompiled from char __stdcall CInputProcessor::GroupToSelection(int a1)
bool  CInputProcessor::GroupToSelection(class CEvn_Logic *) {
  
  return 0;
}


// address=[0x1459e00]
// Decompiled from char __thiscall CInputProcessor::DefineGroup(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::DefineGroup(class CEvn_Logic *) {
  
  char LocalPlayerId; // al
  unsigned int v4; // [esp-8h] [ebp-58h]
  _WORD *v5; // [esp+Ch] [ebp-44h]
  signed int v6; // [esp+10h] [ebp-40h]
  signed int i; // [esp+14h] [ebp-3Ch]
  int v8; // [esp+18h] [ebp-38h]
  _BYTE v9[32]; // [esp+20h] [ebp-30h] BYREF
  int v10; // [esp+4Ch] [ebp-4h]

  v6 = *((_DWORD *)a2 + 2);
  if ( (v6 < 1 || v6 > 10)
    && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3088, "(iGroupId >= GROUP_FIRST) && (iGroupId <= GROUP_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( v6 < 1 || v6 > 10 )
    return 0;
  v8 = std::vector<unsigned short>::size(&CInputProcessor::m_vSelection);
  if ( v8 <= 0 )
    return 0;
  if ( v8 > 100
    && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3102, "iSelectionSize <= MAX_SELECTED_ENTITIES") == 1 )
  {
    __debugbreak();
  }
  if ( v8 > 100 )
    v8 = 100;
  v5 = operator new[](2 * v8);
  for ( i = 0; i < v8; ++i )
    v5[i] = *(_WORD *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, i);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(v5);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v9, 0x13B1u, v6, 0, LocalPlayerId, v4, (unsigned __int8)(2 * v8));
  v10 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3131, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v9);
  v10 = -1;
  CEvn_Logic::~CEvn_Logic(v9);
  return 0;
}


// address=[0x1459fd0]
// Decompiled from char __thiscall CInputProcessor::FocusGroup(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::FocusGroup(class CEvn_Logic *) {
  
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
bool  CInputProcessor::SendTo(class CEvn_Logic *) {
  
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
bool  CInputProcessor::ForceGoto(class CEvn_Logic *) {
  
  return 0;
}


// address=[0x145a420]
// Decompiled from bool __thiscall CInputProcessor::StandGround(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::StandGround(class CEvn_Logic *) {
  
  *((_DWORD *)a2 + 3) = -1;
  return CInputProcessor::SendTo(this, a2);
}


// address=[0x145a450]
// Decompiled from char __thiscall CInputProcessor::ChooseSecondPatrolPos(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::ChooseSecondPatrolPos(class CEvn_Logic *) {
  
  *((_DWORD *)this + 20) = 9;
  IGfxEngine::EnableIconLayer((IGfxEngine *)g_pGfxEngine, 1);
  return 1;
}


// address=[0x145a480]
// Decompiled from char __thiscall CInputProcessor::SelectSecondPatrolPos(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::SelectSecondPatrolPos(class CEvn_Logic *) {
  
  *((_DWORD *)a2 + 2) = 0;
  *((_DWORD *)a2 + 2) |= 8u;
  CInputProcessor::SendTo(this, a2);
  CInputProcessor::Default(this, a2);
  CFsm::GenerateEvent(401, 0);
  return 1;
}


// address=[0x145a4e0]
// Decompiled from char __thiscall CInputProcessor::InjuredOut(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InjuredOut(class CEvn_Logic *) {
  
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
bool  CInputProcessor::MorphToCarrier(class CEvn_Logic *) {
  
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
bool  CInputProcessor::SearchUnit(class CEvn_Logic *) {
  
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
        IEntity::SetFlagBits(SettlerPtr, Selected);
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
bool  CInputProcessor::UnitReservation(class CEvn_Logic *) {
  
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
bool  CInputProcessor::InitEconomyGameMenu(class CEvn_Logic *) {
  
  CStatistic::FillEconomyGameMenu();
  CLogic::SetFillDialogInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, bool))CStatistic::FillEconomyGameMenu,
    (struct CInfoExchange *)&g_cEconomyGameInfo,
    1);
  return 1;
}


// address=[0x145b0b0]
// Decompiled from char __thiscall CInputProcessor::InitMagicSideBar(_DWORD *this, int a2)
bool  CInputProcessor::InitMagicSideBar(class CEvn_Logic *) {
  
  this[5] = -1;
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
bool  CInputProcessor::InitGroupSideBar(class CEvn_Logic *) {
  
  IGroupMgr::FillGroupSideBar(&g_cGroupSideBarInfo, 0, 0);
  CLogic::SetFillSideBarInfos(
    g_pLogic,
    (void (__cdecl *)(struct CInfoExchange *, bool, int))IGroupMgr::FillGroupSideBar,
    (struct CInfoExchange *)&g_cGroupSideBarInfo,
    0);
  return 0;
}


// address=[0x145b140]
// Decompiled from char __thiscall CInputProcessor::InitAddSoldierSideBar(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::InitAddSoldierSideBar(class CEvn_Logic *) {
  
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
bool  CInputProcessor::InitToolSideBar(class CEvn_Logic *) {
  
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
bool  CInputProcessor::InitWeaponSideBar(class CEvn_Logic *) {
  
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
bool  CInputProcessor::InitGoodsOutSideBar(class CEvn_Logic *) {
  
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
bool  CInputProcessor::InitTradeSideBar(class CEvn_Logic *) {
  
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
bool  CInputProcessor::InitStorageSideBar(class CEvn_Logic *) {
  
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
bool  CInputProcessor::InitEyeCatcherSideBar(class CEvn_Logic *) {
  
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
bool  CInputProcessor::InitAddVehicleSideBar(class CEvn_Logic *) {
  
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
bool  CInputProcessor::CloseSideBar(class CEvn_Logic *) {
  
  CLogic::SetFillSideBarInfos(g_pLogic, 0, 0, 0);
  return 0;
}


// address=[0x145b440]
// Decompiled from char __thiscall CInputProcessor::Morph2FoundationCart(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::Morph2FoundationCart(class CEvn_Logic *) {
  
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
bool  CInputProcessor::CreateSettlement(class CEvn_Logic *) {
  
  unsigned __int16 *v2; // eax
  char LocalPlayerId; // [esp-Ch] [ebp-44h]
  unsigned int v5; // [esp-8h] [ebp-40h]
  _BYTE v7[32]; // [esp+8h] [ebp-30h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    return 1;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(0);
  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v7, 0x1393u, *v2, 0, LocalPlayerId, v5, 0);
  v8 = 0;
  if ( !g_pNetworkEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3757, "g_pNetworkEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pNetworkEngine )
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v7);
  CInputProcessor::Clear(this);
  v8 = -1;
  CEvn_Logic::~CEvn_Logic(v7);
  return 1;
}


// address=[0x145b630]
// Decompiled from char __thiscall CInputProcessor::Morph2Cart(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::Morph2Cart(class CEvn_Logic *) {
  
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
bool  CInputProcessor::VehicleUnload(class CEvn_Logic *) {
  
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
bool  CInputProcessor::CatapultLoad(class CEvn_Logic *) {
  
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
bool  CInputProcessor::DestroyWarMachine(class CEvn_Logic *) {
  
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
bool  CInputProcessor::ZoomAreaState(class CEvn_Logic *) {
  
  *((_DWORD *)this + 20) = 10;
  return 1;
}


// address=[0x145bbd0]
// Decompiled from char __thiscall CInputProcessor::CamSelection(CInputProcessor *this, struct CEvn_Logic *a2)
bool  CInputProcessor::CamSelection(class CEvn_Logic *) {
  
  int v2; // eax
  int v3; // eax
  int v4; // esi
  int v6; // [esp+0h] [ebp-50h]
  _BYTE v7[16]; // [esp+8h] [ebp-48h] BYREF
  int TheBestEntity; // [esp+18h] [ebp-38h]
  int v9; // [esp+1Ch] [ebp-34h]
  CInputProcessor *v10; // [esp+20h] [ebp-30h]
  int v11; // [esp+24h] [ebp-2Ch]
  int v12; // [esp+28h] [ebp-28h]
  int v13; // [esp+2Ch] [ebp-24h]
  int v14; // [esp+30h] [ebp-20h]
  int v15; // [esp+34h] [ebp-1Ch]
  int i; // [esp+38h] [ebp-18h]
  unsigned __int8 *v17; // [esp+3Ch] [ebp-14h]
  __int16 v18; // [esp+40h] [ebp-10h] BYREF
  char v19; // [esp+43h] [ebp-Dh]
  int v20; // [esp+4Ch] [ebp-4h]

  v10 = this;
  v12 = Y16X16::UnpackXFast(*((_DWORD *)a2 + 3));
  v11 = Y16X16::UnpackYFast(*((_DWORD *)a2 + 3));
  std::vector<unsigned short>::vector<unsigned short>(v7);
  v20 = 0;
  v9 = CSpiralOffsets::Last(2);
  v17 = 0;
  v15 = 0;
  v14 = 0;
  for ( i = 0; i <= v9; ++i )
  {
    v2 = CSpiralOffsets::DeltaX(i);
    v15 = v12 + v2;
    v3 = CSpiralOffsets::DeltaY(i);
    v14 = v11 + v3;
    if ( (unsigned __int8)CWorldManager::InWorld(v15, v11 + v3) )
    {
      v13 = CWorldManager::MapObjectId(v15, v14);
      if ( v13 )
      {
        v17 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(v13);
        if ( IEntity::ObjType(v17) == 128
          || (v4 = IEntity::OwnerId(v17), v4 == CPlayerManager::GetLocalPlayerId(v6))
          && (IEntity::ObjType(v17) == 1 || IEntity::ObjType(v17) == 2 || IEntity::ObjType(v17) == 4) )
        {
          v18 = v13;
          std::vector<unsigned short>::push_back(&v18);
        }
        else
        {
          v17 = 0;
        }
      }
      else
      {
        g_iCamWndX = v15;
        g_iCamWndY = v14;
      }
    }
  }
  if ( !(unsigned __int8)std::vector<unsigned short>::empty(v7) )
  {
    TheBestEntity = CInputProcessor::GetTheBestEntity(v7, v12, v11);
    v17 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(TheBestEntity);
  }
  if ( v17 )
  {
    g_uCamWndEntityId = IEntity::EntityId((unsigned __int16 *)v17);
    g_iCamWndUniqueId = IEntity::UniqueId(v17);
  }
  else
  {
    g_uCamWndEntityId = 0;
    g_iCamWndUniqueId = 0;
    g_iCamWndX = v12;
    g_iCamWndY = v11;
  }
  *((_DWORD *)v10 + 20) = 1;
  v19 = 1;
  v20 = -1;
  std::vector<unsigned short>::~vector<unsigned short>(v7);
  return v19;
}


// address=[0x145be00]
// Decompiled from int __thiscall CInputProcessor::TraceStates(CFsm **this, int a2)
void  CInputProcessor::TraceStates(class CEvn_Logic const &) {
  
  int v2; // eax
  unsigned int v4; // [esp+4h] [ebp-4h]

  v4 = *(_DWORD *)(a2 + 4);
  if ( v4 >= 0x190 && *(_DWORD *)(a2 + 4) <= 0x1E9u )
    v4 = *(_DWORD *)(a2 + 4) - 400;
  v2 = CFsm::CurrentState(this[2]);
  return CTrace::Print("IP - process type: %s actState: %s", off_3D89628[v4], off_3D895F4[v2]);
}


// address=[0x145be70]
// Decompiled from CInputProcessor *__thiscall CInputProcessor::BoxSelection(CInputProcessor *this)
void  CInputProcessor::BoxSelection(void) {
  
  CInputProcessor *result; // eax
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax
  unsigned int v4; // [esp+4h] [ebp-30h]
  int EntitySelectionType; // [esp+18h] [ebp-1Ch]
  int v6; // [esp+1Ch] [ebp-18h]
  struct IEntity *v7; // [esp+20h] [ebp-14h]
  signed int j; // [esp+24h] [ebp-10h]
  signed int i; // [esp+28h] [ebp-Ch]
  __int16 v11; // [esp+32h] [ebp-2h] BYREF

  result = (CInputProcessor *)(unsigned __int8)CGameData::IsLastFrameRendered(g_pGameData);
  if ( !(_BYTE)result )
    return result;
  v6 = std::vector<unsigned short>::size((char *)this + 84);
  std::vector<unsigned short>::size(&CInputProcessor::m_vSelection);
  if ( !*((_DWORD *)this + 19) )
  {
    for ( i = 0; i < v6; ++i )
    {
      v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 84, i);
      EntitySelectionType = CInputProcessor::GetEntitySelectionType(*v2);
      if ( (int)((unsigned int)&dword_F29144[203695] & EntitySelectionType) > (int)((unsigned int)&dword_F29144[203695] & *((_DWORD *)this + 19)) )
        *((_DWORD *)this + 19) = (unsigned int)&dword_F29144[220015] & EntitySelectionType;
    }
  }
  if ( *((int *)this + 19) > 0 )
  {
    if ( *((_DWORD *)this + 19) == 0x10000 && std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
      v6 = 0;
    for ( j = 0; j < v6; ++j )
    {
      if ( (unsigned int)std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) >= 0x64 )
        break;
      v4 = (unsigned int)&dword_F29144[220015] & *((_DWORD *)this + 19);
      v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 84, j);
      v7 = (struct IEntity *)CMapObjectMgr::EntityPtr(*v3);
      if ( ((unsigned int)&dword_F29144[220015] & CInputProcessor::GetEntitySelectionType(v7)) == v4
        && !IEntity::FlagBits(v7, Selected) )
      {
        IEntity::SetFlagBits(v7, Selected);
        v11 = IEntity::EntityId((unsigned __int16 *)v7);
        std::vector<unsigned short>::push_back(&v11);
        if ( *((_DWORD *)this + 19) == 0x10000 )
          break;
      }
    }
  }
  if ( !*((_BYTE *)this + 52) )
  {
    if ( !std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
      CInputProcessor::Clear(this);
    CInputProcessor::RequestDialog();
  }
  std::vector<unsigned short>::clear();
  *((_BYTE *)this + 52) = 0;
  *((_BYTE *)this + 106) = 0;
  *((_DWORD *)this + 19) = 0;
  result = this;
  *((_DWORD *)this + 25) = 0;
  return result;
}


// address=[0x145c080]
// Decompiled from int __thiscall CInputProcessor::SelectOne(void *this, int x, int y)
int  CInputProcessor::SelectOne(int,int) {
  
  int v3; // esi
  int v5; // esi
  int v6; // esi
  _BYTE v7[16]; // [esp+8h] [ebp-6Ch] BYREF
  int v8; // [esp+18h] [ebp-5Ch]
  int v9; // [esp+1Ch] [ebp-58h]
  int v10; // [esp+20h] [ebp-54h]
  int v11; // [esp+24h] [ebp-50h]
  int v12; // [esp+28h] [ebp-4Ch]
  void *v13; // [esp+2Ch] [ebp-48h]
  unsigned __int8 *v14; // [esp+30h] [ebp-44h]
  int TheBestEntity; // [esp+34h] [ebp-40h]
  int v16; // [esp+38h] [ebp-3Ch]
  int v17; // [esp+3Ch] [ebp-38h]
  int v18; // [esp+40h] [ebp-34h]
  int v19; // [esp+44h] [ebp-30h]
  int v20; // [esp+48h] [ebp-2Ch]
  int v21; // [esp+4Ch] [ebp-28h]
  int v22; // [esp+50h] [ebp-24h]
  int v23; // [esp+54h] [ebp-20h]
  unsigned __int8 *v24; // [esp+58h] [ebp-1Ch]
  unsigned __int8 *v25; // [esp+5Ch] [ebp-18h]
  int i; // [esp+60h] [ebp-14h]
  __int16 v27; // [esp+66h] [ebp-Eh] BYREF
  int v28; // [esp+70h] [ebp-4h]

  v13 = this;
  std::vector<unsigned short>::vector<unsigned short>(v7);
  v28 = 0;
  v22 = CSpiralOffsets::Last(2);
  for ( i = 0; i <= v22; ++i )
  {
    v16 = x + CSpiralOffsets::DeltaX(i);
    v17 = y + CSpiralOffsets::DeltaY(i);
    if ( (unsigned __int8)CWorldManager::InWorld(v16, v17) )
    {
      v23 = CWorldManager::MapObjectId(v16, v17);
      if ( v23 )
      {
        v24 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(v23);
        v3 = IEntity::OwnerId(v24);
        if ( v3 == CPlayerManager::GetLocalPlayerId()
          && (IEntity::FlagBits(v24, Selectable) || IEntity::FlagBits(v24, (EntityFlag)0x4000u)) )
        {
          v27 = v23;
          std::vector<unsigned short>::push_back(&v27);
        }
      }
    }
  }
  TheBestEntity = CInputProcessor::GetTheBestEntity(v7, x, y);
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
    if ( (unsigned __int8)CWorldManager::InWorld(v19, v20) )
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
      v14 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(v18);
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
  v25 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(v21);
  v5 = IEntity::OwnerId(v25);
  if ( v5 != CPlayerManager::GetLocalPlayerId()
    || !IEntity::FlagBits(v25, Selectable) && !IEntity::FlagBits(v25, (EntityFlag)0x4000u) && IEntity::ObjType(v25) != 8 )
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
// Decompiled from int __stdcall CInputProcessor::GetTheBestEntity(void *a1, int a2, int a3)
int  CInputProcessor::GetTheBestEntity(class std::vector<unsigned short,class std::allocator<unsigned short> > &,int,int) {
  
  unsigned int v3; // eax
  unsigned __int16 *v4; // eax
  unsigned int v5; // eax
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned __int16 *v9; // eax
  int v10; // eax
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
  int v22; // [esp+38h] [ebp-40h]
  void *v23; // [esp+3Ch] [ebp-3Ch]
  int v24; // [esp+40h] [ebp-38h] BYREF
  int v25; // [esp+44h] [ebp-34h] BYREF
  int v26; // [esp+48h] [ebp-30h] BYREF
  int v27; // [esp+4Ch] [ebp-2Ch] BYREF
  void **v28; // [esp+50h] [ebp-28h]
  unsigned int i; // [esp+54h] [ebp-24h]
  _DWORD v30[2]; // [esp+58h] [ebp-20h] BYREF
  int v31; // [esp+60h] [ebp-18h]
  int v32; // [esp+64h] [ebp-14h]
  int v33; // [esp+74h] [ebp-4h]

  std::vector<unsigned short>::vector<unsigned short>(v15);
  v33 = 0;
  IGfxEngine::GetScreenOffsetsByMapIndices(a2, a3, &v25, &v24);
  for ( i = 0; ; ++i )
  {
    v3 = std::vector<unsigned short>::size(a1);
    if ( i >= v3 )
      break;
    v4 = (unsigned __int16 *)std::vector<unsigned short>::operator[](a1, i);
    v28 = CMapObjectMgr::MovingEntity(*v4);
    if ( IMovingEntity::GetJobPart((IMovingEntity *)v28) )
    {
      JobPart = IMovingEntity::GetJobPart((IMovingEntity *)v28);
      v13 = IEntity::Race(v28);
      v5 = IEntity::ObjType((unsigned __int8 *)v28);
      CGfxManager::GetBoundingBox((CGfxManager *)g_pGfxManager, (struct SGfxBoundingBox *)v30, v5, v13, JobPart);
      v12 = IEntity::Y(v28);
      v6 = IEntity::X(v28);
      IGfxEngine::GetScreenOffsetsByMapIndices(v6, v12, &v27, &v26);
      v20 = v27 - v31;
      v19 = v30[0] + v27 - v31;
      v18 = v26 - v32;
      v17 = v30[1] + v26 - v32;
      if ( v27 - v31 <= v25 && v19 >= v25 && v18 <= v24 && v17 >= v24 )
      {
        v7 = std::vector<unsigned short>::operator[](a1, i);
        std::vector<unsigned short>::push_back(v7);
      }
    }
  }
  v21 = 0;
  v22 = 0;
  for ( i = 0; ; ++i )
  {
    v8 = std::vector<unsigned short>::size(v15);
    if ( i >= v8 )
      break;
    v9 = (unsigned __int16 *)std::vector<unsigned short>::operator[](v15, i);
    v23 = (void *)CMapObjectMgr::EntityPtr(*v9);
    v10 = IEntity::Y(v23);
    if ( v10 > v22 )
    {
      v22 = IEntity::Y(v23);
      v21 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](v15, i);
    }
  }
  v16 = v21;
  v33 = -1;
  std::vector<unsigned short>::~vector<unsigned short>(v15);
  return v16;
}


// address=[0x145c590]
// Decompiled from int __thiscall CInputProcessor::SelectAllInSurrounding(CInputProcessor *this, int a2, int a3)
int  CInputProcessor::SelectAllInSurrounding(int,int) {
  
  int v4; // eax
  int v5; // [esp-4h] [ebp-38h]
  int LocalPlayerId; // [esp+Ch] [ebp-28h]
  int v8; // [esp+18h] [ebp-1Ch]
  int v9; // [esp+1Ch] [ebp-18h]
  int v10; // [esp+20h] [ebp-14h]
  int v11; // [esp+24h] [ebp-10h]
  int i; // [esp+28h] [ebp-Ch]
  struct IEntity *v13; // [esp+2Ch] [ebp-8h]
  __int16 v14; // [esp+32h] [ebp-2h] BYREF

  if ( (unsigned int)std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) >= 0x64 )
    return 0;
  if ( *((_DWORD *)this + 19) == 0x10000 && std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
    return 0;
  if ( dword_3F1F60C <= 0 )
    return 0;
  if ( dword_3F1F608 )
    v11 = 19823;
  else
    v11 = 3000;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(19823);
  for ( i = 0; i < v11; ++i )
  {
    v9 = a2 + CSpiralOffsets::DeltaX(i);
    v10 = a3 + CSpiralOffsets::DeltaY(i);
    if ( (unsigned __int8)CWorldManager::InWorld(v9, v10) )
    {
      v8 = CWorldManager::MapObjectId(v9, v10);
      if ( v8 > 0 )
      {
        v13 = (struct IEntity *)CMapObjectMgr::EntityPtr(v8);
        if ( v13 )
        {
          if ( IEntity::OwnerId((unsigned __int8 *)v13) == LocalPlayerId
            && IEntity::FlagBits(v13, (EntityFlag)&loc_3000000)
            && (IEntity::FlagBits(v13, Selectable) || IEntity::ObjType((unsigned __int8 *)v13) == 8)
            && CInputProcessor::GetEntitySelectionType(v13) == *((_DWORD *)this + 19) )
          {
            v5 = IEntity::Y(v13);
            v4 = IEntity::X(v13);
            if ( CWorldManager::SectorId(v4, v5) == dword_3F1F60C )
            {
              IEntity::SetFlagBits(v13, Selected);
              v14 = IEntity::EntityId((unsigned __int16 *)v13);
              std::vector<unsigned short>::push_back(&v14);
              if ( IEntity::ObjType((unsigned __int8 *)v13) == 8
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
bool  CInputProcessor::SelectAtSector(enum SETTLER_TYPES,int) {
  
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
        IEntity::SetFlagBits(SettlerPtr, Selected);
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
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // esi
  int v6; // [esp+0h] [ebp-24h]
  int v7; // [esp+Ch] [ebp-18h] BYREF
  int v8; // [esp+10h] [ebp-14h] BYREF
  int v9; // [esp+14h] [ebp-10h]
  int v10; // [esp+18h] [ebp-Ch]
  int v11; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  v11 = 0;
  v8 = 0;
  v7 = 0;
  CStateGame::GetCenterWorldCoordinate((CStateGame *)g_pGame, &v8, &v7);
  v9 = 0;
  v10 = 0;
  for ( i = 0; i < 100; ++i )
  {
    v1 = CSpiralOffsets::DeltaX(i);
    v9 = v8 + v1;
    v2 = CSpiralOffsets::DeltaY(i);
    v10 = v7 + v2;
    if ( (unsigned __int8)CWorldManager::InWorld(v9, v7 + v2) )
    {
      v11 = CWorldManager::EcoSectorId(v9, v10);
      if ( v11 )
      {
        v3 = CEcoSectorMgr::operator[](v11);
        v4 = CEcoSector::Owner(v3);
        if ( v4 == CPlayerManager::GetLocalPlayerId(v6) )
          return v11;
      }
      else
      {
        v11 = 0;
      }
    }
  }
  return v11;
}


// address=[0x145c9d0]
// Decompiled from void __thiscall CInputProcessor::RemoveActiveSettler(CInputProcessor *this, int a2, int a3)
void  CInputProcessor::RemoveActiveSettler(int,int) {
  
  ;
}


// address=[0x145c9e0]
// Decompiled from int __stdcall CInputProcessor::ActivateSpecialist(int a1, int a2)
void  CInputProcessor::ActivateSpecialist(int,int) {
  
  if ( (a2 < 1 || a2 > 3) && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 3030, "_iArea>=1 && _iArea<=3") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x145ca50]
// Decompiled from void __thiscall CInputProcessor::WorkOnBuildingSites(CInputProcessor *this)
void  CInputProcessor::WorkOnBuildingSites(void) {
  
  int LocalPlayerId; // eax
  int v2; // eax
  int v3; // eax
  int v4; // [esp-8h] [ebp-10h]
  int v5; // [esp-8h] [ebp-10h]
  int v6; // [esp-8h] [ebp-10h]
  int v7; // [esp-4h] [ebp-Ch]
  int v8; // [esp+0h] [ebp-8h]

  v8 = *((_DWORD *)this + 20);
  switch ( v8 )
  {
    case 4:
      LocalPlayerId = CPlayerManager::GetLocalPlayerId(*((_DWORD *)this + 4));
      CInputProcessor::GetPossibleBuildingSites(this, LocalPlayerId, v4, 1);
      *((_DWORD *)this + 20) = 5;
      return;
    case 5:
      v2 = CPlayerManager::GetLocalPlayerId(*((_DWORD *)this + 4));
      if ( CInputProcessor::GetPossibleBuildingSites(this, v2, v5, 0) )
      {
        *((_DWORD *)this + 20) = 6;
        byte_3F1F79C = 1;
        dword_3F1F7A0 = 0;
      }
      goto LABEL_11;
    case 6:
      if ( ++dword_3F1F7A0 > 5 )
      {
        v7 = (unsigned __int8)byte_3F1F79C;
        v3 = CPlayerManager::GetLocalPlayerId(*((_DWORD *)this + 4));
        byte_3F1F79C = CInputProcessor::UpdateScreenPossibleBuildingSites(this, v3, v6, v7);
        dword_3F1F7A0 = 0;
      }
LABEL_11:
      CInputProcessor::ShowPossibleBuildingType(this);
      break;
  }
}


// address=[0x145cb30]
// Decompiled from char __thiscall CInputProcessor::GetPossibleBuildingSites(CInputProcessor *this, int a2, int a3, bool a4)
bool  CInputProcessor::GetPossibleBuildingSites(int,int,bool) {
  
  int v5; // [esp+0h] [ebp-48h]
  int OutputWidth; // [esp+Ch] [ebp-3Ch]
  int OutputHeight; // [esp+10h] [ebp-38h]
  char v8; // [esp+14h] [ebp-34h]
  int v9; // [esp+18h] [ebp-30h]
  int v10; // [esp+1Ch] [ebp-2Ch]
  int v11; // [esp+20h] [ebp-28h]
  int v12; // [esp+24h] [ebp-24h]
  unsigned int v13; // [esp+28h] [ebp-20h]
  int v14; // [esp+2Ch] [ebp-1Ch]
  int HelperObject; // [esp+30h] [ebp-18h]
  int v16; // [esp+34h] [ebp-14h]
  Squares *i; // [esp+3Ch] [ebp-Ch]
  Squares *j; // [esp+40h] [ebp-8h]

  v16 = CWorldManager::Width(this) - 5;
  v8 = 10;
  if ( (unsigned __int8)CBuildingMgr::IsMine(a3) )
    v8 = 74;
  if ( a4 )
  {
    *((_DWORD *)this + 8) = 0;
    OutputWidth = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
    OutputHeight = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine);
    IGfxEngine::GetClosestMapPoint((IGfxEngine *)g_pGfxEngine, 1, 1, (int *)this + 9, (int *)this + 10);
    IGfxEngine::GetClosestMapPoint(
      (IGfxEngine *)g_pGfxEngine,
      OutputWidth - 2,
      OutputHeight - 2,
      (int *)this + 11,
      (int *)this + 12);
    sub_145DB10((char *)this + 36, 4, v16);
    sub_145DB10((char *)this + 40, 4, v16);
    sub_145DB10((char *)this + 44, 4, v16);
    sub_145DB10((char *)this + 48, 4, v16);
  }
  else if ( *((int *)this + 8) >= 20 )
  {
    return 1;
  }
  if ( *((int *)this + 8) >= 4 )
  {
    v10 = 4;
    v13 = *((_DWORD *)this + 8);
    v9 = v16;
    v11 = v16;
    v12 = 16;
  }
  else
  {
    v10 = *((_DWORD *)this + 9);
    v13 = (((*((_DWORD *)this + 8) & 2) >> 1) | (2 * (*((_DWORD *)this + 8) & 1)) | *((_DWORD *)this + 8) & 0xFFFFFFFC)
        + *((_DWORD *)this + 10);
    v9 = *((_DWORD *)this + 11);
    v11 = *((_DWORD *)this + 12);
    v12 = 4;
  }
  v5 = COwnerMap::OwnerBit(a2);
  for ( i = (Squares *)v13; (int)i <= v11; i = (Squares *)((char *)i + v12) )
  {
    for ( j = (Squares *)v10; (int)j < v9; j = (Squares *)((char *)j + 1) )
    {
      if ( (v5 & COwnerMap::OwnerBits1XY(j, i)) != 0 )
      {
        HelperObject = CWorldManager::GetHelperObject((int)j, (int)i);
        if ( (HelperObject < 10 || HelperObject > 17) && HelperObject != 74 )
        {
          v14 = CBuildingMgr::CheckForBuild((CBuildingMgr *)g_cBuildingMgr, j, i, a2, a3, 0);
          if ( v14 > 0 )
            CWorldManager::SetHelperObject(j, i, v8 + v14 - 1);
        }
      }
      else
      {
        j = (Squares *)(((unsigned int)j + 16) & 0xFFFFFFF0);
      }
    }
  }
  ++*((_DWORD *)this + 8);
  return 0;
}


// address=[0x145cdd0]
// Decompiled from char __thiscall CInputProcessor::UpdateScreenPossibleBuildingSites(CInputProcessor *this, int a2, int a3, int a4)
bool  CInputProcessor::UpdateScreenPossibleBuildingSites(int,int,int) {
  
  int v5; // [esp+0h] [ebp-2Ch]
  int OutputWidth; // [esp+8h] [ebp-24h]
  int OutputHeight; // [esp+Ch] [ebp-20h]
  char v8; // [esp+10h] [ebp-1Ch]
  int v9; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]
  int v11; // [esp+20h] [ebp-Ch]
  Squares *j; // [esp+24h] [ebp-8h]

  v11 = CWorldManager::Width(this) - 5;
  v8 = 10;
  if ( (unsigned __int8)CBuildingMgr::IsMine(a3) )
    v8 = 74;
  if ( a4 )
  {
    *((_DWORD *)this + 8) = 0;
    OutputWidth = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
    OutputHeight = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine);
    IGfxEngine::GetClosestMapPoint((IGfxEngine *)g_pGfxEngine, 1, 1, (int *)this + 9, (int *)this + 10);
    IGfxEngine::GetClosestMapPoint(
      (IGfxEngine *)g_pGfxEngine,
      OutputWidth - 2,
      OutputHeight - 2,
      (int *)this + 11,
      (int *)this + 12);
    sub_145DB10((char *)this + 36, 4, v11);
    sub_145DB10((char *)this + 40, 4, v11);
    sub_145DB10((char *)this + 44, 4, v11);
    sub_145DB10((char *)this + 48, 4, v11);
    byte_3F1F7B0 = 1;
  }
  else if ( *((int *)this + 8) >= 4 )
  {
    return 1;
  }
  if ( byte_3F1F7B0 )
  {
    dword_3F1F7AC = (((*((_DWORD *)this + 8) & 2) >> 1) | (2 * (*((_DWORD *)this + 8) & 1)) | *((_DWORD *)this + 8) & 0xFFFFFFFC)
                  + *((_DWORD *)this + 10);
    byte_3F1F7B0 = 0;
  }
  v5 = COwnerMap::OwnerBit(a2);
  for ( i = 0; i < 2; ++i )
  {
    for ( j = (Squares *)*((_DWORD *)this + 9); (int)j < *((_DWORD *)this + 11); j = (Squares *)((char *)j + 1) )
    {
      if ( (v5 & COwnerMap::OwnerBits1XY(j, (Squares *)dword_3F1F7AC)) != 0 )
      {
        v9 = CBuildingMgr::CheckForBuild((CBuildingMgr *)g_cBuildingMgr, j, dword_3F1F7AC, a2, a3, 0);
        if ( v9 <= 0 )
          CWorldManager::SetHelperObject(j, dword_3F1F7AC, 0);
        else
          CWorldManager::SetHelperObject(j, dword_3F1F7AC, v8 + v9 - 1);
      }
      else
      {
        j = (Squares *)(((unsigned int)j + 16) & 0xFFFFFFF0);
      }
    }
    dword_3F1F7AC += 4;
    if ( dword_3F1F7AC > *((_DWORD *)this + 12) )
    {
      ++*((_DWORD *)this + 8);
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
  int v7; // [esp-Ch] [ebp-38h]
  int v8; // [esp-8h] [ebp-34h]
  int v9; // [esp-8h] [ebp-34h]
  int v10; // [esp-4h] [ebp-30h]
  char v11; // [esp+4h] [ebp-28h]
  int v12; // [esp+8h] [ebp-24h]
  int v13; // [esp+Ch] [ebp-20h]
  int IconObjectByX; // [esp+10h] [ebp-1Ch]
  int v15; // [esp+14h] [ebp-18h]
  int v16; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]
  int v18; // [esp+1Ch] [ebp-10h]
  int v20; // [esp+24h] [ebp-8h] BYREF
  int v21; // [esp+28h] [ebp-4h] BYREF

  if ( !(unsigned __int8)CWorldManager::InWorld(dword_3F1F7A4, dword_3F1F7A8) )
  {
    dword_3F1F7A4 = 0;
    dword_3F1F7A8 = 0;
  }
  v11 = 10;
  if ( (unsigned __int8)CBuildingMgr::IsMine(*((_DWORD *)this + 4)) )
    v11 = 74;
  if ( (int)IGfxEngine::GetClosestMapPoint(
              (IGfxEngine *)g_pGfxEngine,
              *(_DWORD *)(g_pGame + 108),
              *(_DWORD *)(g_pGame + 112),
              &v21,
              &v20) < 0
    || !(unsigned __int8)CWorldManager::InWorld(v21, v20) )
  {
    v21 = 0;
    v20 = 0;
  }
  if ( dword_3F1F7A4 != v21 || dword_3F1F7A8 != v20 )
  {
    if ( *((_DWORD *)this + 7) )
    {
      CWorldManager::SetHelperObject(dword_3F1F7A4, dword_3F1F7A8, *((_DWORD *)this + 7));
      *((_DWORD *)this + 7) = 0;
    }
    LocalPlayerId = CPlayerManager::GetLocalPlayerId(*((_DWORD *)this + 4));
    v15 = CBuildingMgr::CheckForBuild((CBuildingMgr *)g_cBuildingMgr, v21, v20, LocalPlayerId, v8, 0);
    if ( v15 > 0 )
      CWorldManager::SetHelperObject(v21, v20, v11 + v15 - 1);
    else
      CWorldManager::SetHelperObject(v21, v20, 0);
    for ( i = 0; i < 6; ++i )
    {
      v12 = g_sNeighborPoints[2 * i] + v21;
      v13 = dword_37D8C0C[2 * i] + v20;
      if ( (unsigned __int8)CWorldManager::InWorld(v12, v13) )
      {
        v2 = CPlayerManager::GetLocalPlayerId(*((_DWORD *)this + 4));
        v16 = CBuildingMgr::CheckForBuild((CBuildingMgr *)g_cBuildingMgr, v12, v13, v2, v9, 0);
        if ( v16 > 0 )
          CWorldManager::SetHelperObject(v12, v13, v11 + v16 - 1);
        else
          CWorldManager::SetHelperObject(v12, v13, 0);
      }
    }
  }
  CWorldManager::WorldSetNumberOfNextLine(v20);
  if ( (unsigned __int8)CWorldManager::WorldGetIconObjectByX(v21) )
  {
    IconObjectByX = (unsigned __int8)CWorldManager::WorldGetIconObjectByX(v21);
    if ( (unsigned int)IconObjectByX < 0xA || IconObjectByX > 17 )
    {
      if ( IconObjectByX == 74 )
      {
        *((_DWORD *)this + 7) = 74;
        dword_3F1F7A4 = v21;
        dword_3F1F7A8 = v20;
        CWorldManager::SetHelperObject(v21, v20, 75);
      }
    }
    else
    {
      *((_DWORD *)this + 7) = IconObjectByX;
      dword_3F1F7A4 = v21;
      dword_3F1F7A8 = v20;
      CWorldManager::SetHelperObject(v21, v20, *((_BYTE *)this + 28) - v11 + 18);
    }
    CInputProcessor::m_sGfxObj = 1;
    dword_3F1F32C = v21;
    dword_3F1F330 = v20;
    byte_3F1F604 = 1;
    v18 = *((_DWORD *)this + 4);
    if ( v18 == 31 || v18 == 32 )
    {
      if ( v18 == 31 )
        v3 = CPlayerManager::GetLocalPlayerId(58);
      else
        v3 = CPlayerManager::GetLocalPlayerId(52);
      v18 = CBuildingMgr::CheckForBuildInWater((CBuildingMgr *)g_cBuildingMgr, v21, v20, v3, v10);
    }
    v4 = CPlayerManager::GetLocalPlayerId(v18);
    v5 = CPlayerManager::Race(v4);
    CGfxManager::GetBuildingGfxInfo((int)&unk_3F1F334, v5, v7, 1, 0);
    return IGfxEngine::SetGfxObject(&CInputProcessor::m_sGfxObj);
  }
  else
  {
    byte_3F1F604 = 0;
    return IGfxEngine::SetGfxObject(&CInputProcessor::m_sGfxObj);
  }
}


// address=[0x145d3f0]
// Decompiled from int __thiscall CInputProcessor::DeSelectAll(CInputProcessor *this)
void  CInputProcessor::DeSelectAll(void) {
  
  int result; // eax
  unsigned __int8 *BuildingPtr; // [esp+4h] [ebp-10h]
  int v3; // [esp+8h] [ebp-Ch]
  unsigned __int8 *v4; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]

  result = std::vector<unsigned short>::size(&CInputProcessor::m_vSelection);
  if ( !result )
    return result;
  for ( i = 0; i < std::vector<unsigned short>::size(&CInputProcessor::m_vSelection); ++i )
  {
    v3 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, i);
    v4 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(v3);
    if ( v4 )
    {
      IEntity::ClearFlagBits(v4, Selected);
      IEntity::ClearFlagBits(v4, (EntityFlag)0x400u);
      if ( IEntity::ObjType(v4) == 8 )
      {
        BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v3);
        CBuilding::NotifySelected(BuildingPtr);
      }
    }
  }
  return std::vector<unsigned short>::clear();
}


// address=[0x145d4b0]
// Decompiled from _DWORD *__thiscall CInputProcessor::RequestDialog(CInputProcessor *this)
void  CInputProcessor::RequestDialog(void) {
  
  _DWORD *result; // eax
  unsigned __int16 *v2; // eax
  unsigned __int8 *v3; // eax
  unsigned __int16 *v4; // eax
  unsigned __int16 *v5; // eax
  unsigned __int16 *v6; // eax
  unsigned __int16 *v7; // eax
  int v8; // [esp+Ch] [ebp-4Ch]
  int v9; // [esp+10h] [ebp-48h]
  int v10; // [esp+14h] [ebp-44h]
  unsigned __int16 *v11; // [esp+18h] [ebp-40h]
  int v12; // [esp+1Ch] [ebp-3Ch]
  unsigned __int16 *v13; // [esp+20h] [ebp-38h]
  unsigned __int16 *v14; // [esp+28h] [ebp-30h]
  CEvn_Event v16; // [esp+30h] [ebp-28h] BYREF
  int v17; // [esp+54h] [ebp-4h]

  result = (_DWORD *)std::vector<unsigned short>::size(&CInputProcessor::m_vSelection);
  if ( !result )
    return result;
  CEvn_Event::CEvn_Event(&v16, 0x260u, 0, 0, 0);
  v17 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 5151, "g_pEvnEngine!= NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v16);
  CLogic::SetFillDialogInfos(g_pLogic, 0, 0, 0);
  v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
  v3 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(*v2);
  switch ( IEntity::ObjType(v3) )
  {
    case 1:
      v5 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
      v13 = (unsigned __int16 *)CSettlerMgr::operator[](*v5);
      if ( IEntity::WarriorType() == 7 )
      {
        CSettlerMgr::FillSpecialistMenu(&g_cSpecialistsInfo, 0);
        CLogic::SetFillDialogInfos(
          g_pLogic,
          (void (__cdecl *)(struct CInfoExchange *, bool, bool))CSettlerMgr::FillSpecialistMenu,
          (struct CInfoExchange *)&g_cSpecialistsInfo,
          *((_BYTE *)this + 105));
      }
      else if ( IEntity::Type(v13) == 60 )
      {
        v10 = CSettler::Role(v13);
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v10 + 132))(v10, 0);
      }
      else
      {
        CSettlerMgr::FillSoldierMenu(&g_cSoldierInfo, 0);
        CLogic::SetFillDialogInfos(
          g_pLogic,
          (void (__cdecl *)(struct CInfoExchange *, bool, bool))CSettlerMgr::FillSoldierMenu,
          (struct CInfoExchange *)&g_cSoldierInfo,
          *((_BYTE *)this + 105));
      }
      goto CInputProcessor__RequestDialog___def_185D591;
    case 2:
      v6 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
      v14 = (unsigned __int16 *)CVehicleMgr::operator[](*v6);
      v12 = IEntity::Type(v14);
      switch ( v12 )
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
      (*(void (__thiscall **)(unsigned __int16 *, _DWORD))(*(_DWORD *)v14 + 148))(v14, 0);
CInputProcessor__RequestDialog___def_185D591:
      v17 = -1;
      return CEvn_Event::~CEvn_Event(&v16);
    case 4:
      v7 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
      v11 = (unsigned __int16 *)CVehicleMgr::operator[](*v7);
      v9 = IEntity::Type(v11);
      if ( v9 == 4 )
      {
LABEL_25:
        CVehicleMgr::FillVehicleGroupMenu((struct CInfoExchange *)&g_cVehicleInfo, 0);
        CLogic::SetFillDialogInfos(
          g_pLogic,
          (void (__cdecl *)(struct CInfoExchange *, bool, bool))CVehicleMgr::FillVehicleGroupMenu,
          (struct CInfoExchange *)&g_cVehicleInfo,
          *((_BYTE *)this + 105));
      }
      else if ( v9 == 5 )
      {
        (*(void (__thiscall **)(unsigned __int16 *, _DWORD))(*(_DWORD *)v11 + 148))(v11, 0);
      }
      goto CInputProcessor__RequestDialog___def_185D591;
    case 8:
      v4 = (unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
      v8 = CBuildingMgr::operator[](*v4);
      if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\InputProcessor.cpp", 5169, "g_pEvnEngine!= NULL") == 1 )
        __debugbreak();
      if ( g_pEvnEngine )
        CBuilding::FillDialog(v8);
      goto CInputProcessor__RequestDialog___def_185D591;
    default:
      goto CInputProcessor__RequestDialog___def_185D591;
  }
  return result;
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
// Decompiled from int __thiscall CInputProcessor::TidyUp(_DWORD *this)
void  CInputProcessor::TidyUp(void) {
  
  int v2; // [esp+0h] [ebp-Ch]
  unsigned __int8 *BuildingPtr; // [esp+8h] [ebp-4h]

  this[20] = 0;
  if ( std::vector<unsigned short>::size(&CInputProcessor::m_vSelection) )
  {
    v2 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](&CInputProcessor::m_vSelection, 0);
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v2);
    if ( BuildingPtr )
    {
      if ( !IEntity::FlagBits(BuildingPtr, Selected)
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
  CWorldManager::ClearHelperObject(v2);
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
bool  CInputProcessor::EmptyFunct(class CEvn_Logic *) {
  
  return 1;
}


// address=[0x14e4b00]
// Decompiled from int __thiscall CInputProcessor::GetSelectionType(CInputProcessor *this)
int  CInputProcessor::GetSelectionType(void)const {
  
  return *((_DWORD *)this + 19);
}


// address=[0x14e4b60]
// Decompiled from int __thiscall CInputProcessor::NewCandidate(CInputProcessor *this, __int16 a2)
void  CInputProcessor::NewCandidate(int) {
  
  __int16 v3; // [esp+6h] [ebp-2h] BYREF

  v3 = a2;
  return std::vector<unsigned short>::push_back(&v3);
}


// address=[0x14e4bb0]
// Decompiled from CInputProcessor *__thiscall CInputProcessor::SetSelectionType(CInputProcessor *this, int a2)
void  CInputProcessor::SetSelectionType(int) {
  
  CInputProcessor *result; // eax

  result = this;
  *((_DWORD *)this + 19) = a2;
  return result;
}


// address=[0x3f1f328]
// [Decompilation failed for static struct SGfxObject CInputProcessor::m_sGfxObj]

