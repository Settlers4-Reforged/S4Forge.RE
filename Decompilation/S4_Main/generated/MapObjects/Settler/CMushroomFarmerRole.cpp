#include "CMushroomFarmerRole.h"

// Definitions for class CMushroomFarmerRole

// address=[0x14014e0]
// Decompiled from int __cdecl CMushroomFarmerRole::New(int a1)
class CPersistence * __cdecl CMushroomFarmerRole::New(std::istream & a1) {
  
  if ( operator new(0x30u) != 0 )
  {
    return ((_DWORD (__stdcall *)(int))CMushroomFarmerRole::CMushroomFarmerRole)(a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x15787f0]
// Decompiled from int __thiscall CMushroomFarmerRole::InitWalking(CMushroomFarmerRole *this, struct CSettler *a2)
class CWalking *  CMushroomFarmerRole::InitWalking(class CSettler * a2) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId(a2);
  v4 = (int)CWalking::Create(0, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x1578830]
// Decompiled from int __thiscall CMushroomFarmerRole::LogicUpdateJob(CMushroomFarmerRole *this, struct CSettler *a2)
void  CMushroomFarmerRole::LogicUpdateJob(class CSettler * a2) {
  
  int v2; // eax
  int v3; // esi
  int v4; // esi
  int v6; // [esp-4h] [ebp-30h]
  unsigned int v7; // [esp+4h] [ebp-28h]
  unsigned int v8; // [esp+8h] [ebp-24h]
  IEntity *v9; // [esp+Ch] [ebp-20h]
  int v10; // [esp+14h] [ebp-18h]
  CSettlerMgr::SSettlerInfos *SettlerInfo; // [esp+18h] [ebp-14h]
  int v12; // [esp+20h] [ebp-Ch]
  char v13; // [esp+24h] [ebp-8h]

  v13 = *((_BYTE *)this + 4);
  switch ( v13 )
  {
    case 6:
      IMovingEntity::SetDistance(a2, 0);
      return (*(int (__thiscall **)(CMushroomFarmerRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
    case 16:
      if ( *((char *)this + 6) <= (int)*((unsigned __int8 *)this + 7) )
      {
        v10 = *((char *)this + 6);
      }
      else
      {
        v10 = *((unsigned __int8 *)this + 7);
      }
      *((_BYTE *)this + 6) -= v10;
      if ( *((char *)this + 6) <= 0 )
      {
        if ( *((_WORD *)this + 17) != 0 )
        {
          v9 = CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 17));
          ((void (__thiscall *)(IEntity *, int))v9->Decrease)(v9, 1);
        }
        return (*(int (__thiscall **)(CMushroomFarmerRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
      }
      else
      {
        return IAnimatedEntity::RegisterForLogicUpdate(a2, v10);
      }
    case 25:
      if ( *((char *)this + 6) <= (int)*((unsigned __int8 *)this + 7) )
      {
        v12 = *((char *)this + 6);
      }
      else
      {
        v12 = *((unsigned __int8 *)this + 7);
      }
      *((_BYTE *)this + 6) -= v12;
      if ( *((char *)this + 6) <= 0 )
      {
        v6 = IEntity::Type(a2);
        v2 = IEntity::Race(a2);
        SettlerInfo = CSettlerMgr::GetSettlerInfo(v2, v6);
        v3 = IEntity::X(a2);
        v7 = v3 - std::vector<CSettlerMgr::SSearchInfos>::operator[](&SettlerInfo->m_vSearches, 1u)->m_iOffsetX;
        v4 = IEntity::Y(a2);
        v8 = v4 - std::vector<CSettlerMgr::SSearchInfos>::operator[](&SettlerInfo->m_vSearches, 1u)->m_iOffsetY;
        CDecoObjMgr::AddDecoObjWithoutFlags(&g_cDecoObjMgr, v7, v8, *((T_OBJECT_TYPE *)this + 11), 0, 0);
        *((_DWORD *)this + 11) = 0;
        return (*(int (__thiscall **)(CMushroomFarmerRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
      }
      else
      {
        return IAnimatedEntity::RegisterForLogicUpdate(a2, v12);
      }
    default:
      return a2->j_?DbgPrint@IEntity@@UAEXHPBD@Z((_DWORD *)a2, 0, "CMushroomFarmerRole::LogicUpdateJob(): Invalid Job");
  }
}


// address=[0x1578a30]
// Decompiled from int __thiscall CMushroomFarmerRole::UpdateJob(CMushroomFarmerRole *this, struct CSettler *a2)
void  CMushroomFarmerRole::UpdateJob(class CSettler * a2) {
  
  int v2; // eax
  char v3; // al
  char v4; // al
  int result; // eax
  char v6; // [esp+0h] [ebp-8h]

  v6 = *((_BYTE *)this + 4);
  switch ( v6 )
  {
    case 13:
      v2 = IAnimatedEntity::Frame(a2);
      return ((int (__stdcall *)(char))IAnimatedEntity::SetFrame)((*((unsigned __int16 *)this + 4) + v2) % *((unsigned __int8 *)this + 7));
    case 21:
      v3 = IAnimatedEntity::Frame(a2);
      ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)(v3 - *((_WORD *)this + 4));
      result = IAnimatedEntity::Frame(a2);
      if ( result < 0 )
      {
        return ((int (__stdcall *)(char))IAnimatedEntity::SetFrame)(0);
      }
      break;
    case 22:
      v4 = IAnimatedEntity::Frame(a2);
      ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)(*((_WORD *)this + 4) + v4);
      result = IAnimatedEntity::Frame(a2);
      if ( result >= *((unsigned __int8 *)this + 7) )
      {
        return ((int (__stdcall *)(char))IAnimatedEntity::SetFrame)(0);
      }
      break;
    default:
      return CTrace::Print("MushroomfarmerRole - Update unknown task");
  }
  return result;
}


// address=[0x1578b00]
// Decompiled from int __stdcall CMushroomFarmerRole::PostLoadInit(IEntity *a1)
void  CMushroomFarmerRole::PostLoadInit(class CSettler * a1) {
  
  return ((int (__cdecl *)(CPropertySet *))CWarMap::AddEntity)((CPropertySet *)a1);
}


// address=[0x1578b20]
// Decompiled from char __thiscall CMushroomFarmerRole::SetFree(ISettlerRole *this, struct CSettler *a2, int a3)
bool  CMushroomFarmerRole::SetFree(class CSettler * a2, int a3) {
  
  int v3; // eax
  int v4; // eax
  struct IEntity *v6; // [esp+0h] [ebp-8h]

  if ( ISettlerRole::HomeEntityId(this) != 0 )
  {
    v3 = ISettlerRole::HomeEntityId(this);
    v6 = CMapObjectMgr::Entity(v3);
    v4 = IEntity::EntityId(a2);
    ((void (__thiscall *)(struct IEntity *, int))v6->Detach)(v6, v4);
    if ( ISettlerRole::HomeEntityId(this) != 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\MushroomfarmerRole.cpp", 680, "HomeEntityId() == 0") == 1 )
    {
      __debugbreak();
    }
  }
  a2->ClearAllQueuedEvents(a2);
  return 0;
}


// address=[0x1578ba0]
// Decompiled from char __thiscall CMushroomFarmerRole::ESChanged(CMushroomFarmerRole *this, struct CSettler *a2)
bool  CMushroomFarmerRole::ESChanged(class CSettler * a2) {
  
  return 0;
}


// address=[0x1578bb0]
// Decompiled from char *__thiscall CMushroomFarmerRole::CMushroomFarmerRole(char *this, int a2)
 CMushroomFarmerRole::CMushroomFarmerRole(std::istream & a2) {
  
  unsigned int v3; // [esp+4h] [ebp-1Ch] BYREF
  int pExceptionObject; // [esp+8h] [ebp-18h] BYREF
  unsigned int v5; // [esp+Ch] [ebp-14h]
  char *v6; // [esp+10h] [ebp-10h]
  int v7; // [esp+1Ch] [ebp-4h]

  v6 = this;
  ISettlerRole::ISettlerRole((ISettlerRole *)this, (struct std::istream *)a2);
  v7 = 0;
  *(_DWORD *)v6 = &CMushroomFarmerRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  v5 = v3;
  if ( v3 == 1 )
  {
    *((_DWORD *)v6 + 11) = 0;
  }
  else
  {
    if ( v5 != 2 )
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CMushroomFarmerRole");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    operator^<unsigned int>(a2, (unsigned int *)v6 + 11);
  }
  return v6;
}


// address=[0x1578c80]
// Decompiled from int __thiscall CMushroomFarmerRole::Store(struct CPersistence *this, struct std::ostream *a2)
void  CMushroomFarmerRole::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct CPersistence *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  ISettlerRole::Store((ISettlerRole *)this, a2);
  v3 = 2;
  operator^<unsigned int>(a2, (unsigned int *)&v3);
  return operator^<unsigned int>(a2, (unsigned int *)&v4[11]);
}


// address=[0x1579690]
// Decompiled from int __thiscall CMushroomFarmerRole::ClassID(CMushroomFarmerRole *this)
unsigned long  CMushroomFarmerRole::ClassID(void)const {
  
  return CMushroomFarmerRole::m_iClassID;
}


// address=[0x15796b0]
// Decompiled from int __thiscall CMushroomFarmerRole::GetSettlerRole(CMushroomFarmerRole *this)
int  CMushroomFarmerRole::GetSettlerRole(void)const {
  
  return 15;
}


// address=[0x1588780]
// Decompiled from int __cdecl CMushroomFarmerRole::Load(struct std::istream *a1)
class CMushroomFarmerRole * __cdecl CMushroomFarmerRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)((void **(__cdecl *)(struct std::istream *, struct TypeDescriptor *))CPersistence::New)(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CMushroomFarmerRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8beec]
// [Decompilation failed for static unsigned long CMushroomFarmerRole::m_iClassID]

// address=[0x1578cd0]
// Decompiled from CMushroomFarmerRole *__thiscall CMushroomFarmerRole::CMushroomFarmerRole(CMushroomFarmerRole *this)
 CMushroomFarmerRole::CMushroomFarmerRole(void) {
  
  ISettlerRole::ISettlerRole((ISettlerRole *)this);
  *(_DWORD *)this = &CMushroomFarmerRole::_vftable_;
  *((_DWORD *)this + 11) = 0;
  return this;
}


// address=[0x1578d00]
// Decompiled from ISettlerRole *__thiscall CMushroomFarmerRole::~CMushroomFarmerRole(ISettlerRole *this)
 CMushroomFarmerRole::~CMushroomFarmerRole(void) {
  
  this->__vftable = (ISettlerRole_vtbl *)&CMushroomFarmerRole::_vftable_;
  return ISettlerRole::~ISettlerRole(this);
}


// address=[0x1578d20]
// Decompiled from int __thiscall CMushroomFarmerRole::GetNextJob(CMushroomFarmerRole *this, struct CSettler *a2)
void  CMushroomFarmerRole::GetNextJob(class CSettler * a2) {
  
  int result; // eax

  IMovingEntity::IncToDoListIter(a2);
  result = IMovingEntity::IsEndIter(a2);
  if ( (_BYTE)result == 0 )
  {
    return (*(int (__thiscall **)(CMushroomFarmerRole *, struct CSettler *))(*(_DWORD *)this + 40))(this, a2);
  }
  *((_BYTE *)this + 4) = 17;
  return result;
}


// address=[0x1578d60]
// Decompiled from void __thiscall CMushroomFarmerRole::TakeJob(ISettlerRole *this, struct CSettler *a2)
void  CMushroomFarmerRole::TakeJob(class CSettler * a2) {
  
  const struct CEntityTask *ActualTask; // eax
  unsigned int v3; // eax
  int v4; // eax
  CBuilding *v5; // eax
  int v6; // [esp-4h] [ebp-1Ch]
  int v7; // [esp+4h] [ebp-14h]
  int v8; // [esp+8h] [ebp-10h]
  int v9; // [esp+Ch] [ebp-Ch]

  ActualTask = IMovingEntity::GetActualTask(a2);
  ISettlerRole::InitCommonTaskValues(this, a2, ActualTask);
  switch ( this->m_iTask )
  {
    case 7:
    case 0xA:
    case 0x21:
      ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)(1);
      v7 = this->m_iDestinationOffsetX + Y16X16::UnpackXFast(this->m_iDestinationPosition);
      v8 = this->m_iDestinationOffsetY + Y16X16::UnpackYFast(this->m_iDestinationPosition);
      this->m_iDestinationPosition = Y16X16::PackXYFast(v7, v8);
      if ( this->m_iTask == 33 )
      {
        v9 = 0x2000;
      }
      else
      {
        v9 = 0;
      }
      IMovingEntity::WalkToXY(a2, this->m_iDestinationPosition, v9);
      this->m_iTask = 6;
      ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(5);
      this->Go(this, a2);
      break;
    case 0xD:
    case 0x10:
    case 0x19:
      ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(10);
      ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(this->m_uCycleFrames);
      break;
    case 0xE:
      ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)(1);
      IMovingEntity::WalkToXY(a2, this->m_iStartPosition, 0);
      this->m_iTask = 6;
      ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(5);
      this->Go(this, a2);
      break;
    case 0x11:
      ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(0);
      v3 = CStateGame::Rand(g_pGame);
      ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(v3 % 0x10 + 1);
      break;
    case 0x15:
      ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(10);
      ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)(this->m_uCycleFrames - 1);
      ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(this->m_iWalkspeed / 2);
      break;
    case 0x16:
      ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(10);
      ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(this->m_iWalkspeed / 2 - 1);
      break;
    case 0x18:
      if ( ISettlerRole::HomeEntityId(this) != 0 )
      {
        this->m_fOffsetX = 0.0;
        this->m_fOffsetY = 0.0;
        this->m_iDestinationPosition = 0;
        ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(10);
        v6 = ((int (__stdcall *)())IEntity::ID)();
        v4 = ISettlerRole::HomeEntityId(this);
        v5 = (CBuilding *)((CBuilding *(__stdcall *)(int))CBuildingMgr::operator[])(v4);
        CBuilding::SettlerEnter(v5, v6);
      }
      else if ( BBSupportDbgReportF(2, "MapObjects\\Settler\\MushroomfarmerRole.cpp", 474, " m_uHomeEntityId == 0 -> crushed?") == 1 )
      {
        __debugbreak();
      }
      break;
    default:
      CTrace::Print("MushroomFarmerRole - TakeJob unknown task");
      break;
  }
}


// address=[0x1579050]
// Decompiled from int __stdcall CMushroomFarmerRole::Init(IEntity *a1)
void  CMushroomFarmerRole::Init(class CSettler * a1) {
  
  return ((int (__cdecl *)(CPropertySet *))CWarMap::AddEntity)((CPropertySet *)a1);
}


// address=[0x1579070]
// Decompiled from _DWORD *__thiscall CMushroomFarmerRole::ConvertEventIntoGoal(ISettlerRole *this, struct CSettler *a2, struct CEntityEvent *a3)
void  CMushroomFarmerRole::ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3) {
  
  int v3; // eax
  _DWORD *result; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // [esp-8h] [ebp-28h]
  int v17; // [esp-8h] [ebp-28h]
  int v18; // [esp-8h] [ebp-28h]
  int v19; // [esp-4h] [ebp-24h]
  int v20; // [esp-4h] [ebp-24h]
  int v21; // [esp-4h] [ebp-24h]
  int v22; // [esp-4h] [ebp-24h]
  int v23; // [esp-4h] [ebp-24h]
  int v24; // [esp-4h] [ebp-24h]
  CMFCToolBarButton *v25; // [esp+0h] [ebp-20h]
  CMFCToolBarButton *v26; // [esp+4h] [ebp-1Ch]
  BOOL v27; // [esp+14h] [ebp-Ch]

  switch ( a3->m_iEvent )
  {
    case 1:
      if ( ISettlerRole::HomeEntityId(this) == 0 )
      {
        goto LABEL_2;
      }
      v19 = IEntity::Type(a2);
      v5 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v5, v19);
      v26 = (CMFCToolBarButton *)((CMFCToolBarButton *(__stdcall *)(int))CBuildingMgr::operator[])(a3->m_iDataA);
      v6 = CBuilding::DoorPackedXY((CBuilding *)v26);
      ISettlerRole::NewDestination(this, a2, v6, 0);
      v20 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(_DWORD))std::vector<unsigned short>::operator[])(0);
      v16 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(_DWORD))std::vector<unsigned short>::operator[])(0);
      v7 = IEntity::Race(a2);
      v8 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v7, v16);
      result = (_DWORD *)a2->NewToDoList(a2, v8, v20);
      break;
    case 2:
      if ( ISettlerRole::HomeEntityId(this) == 0 )
      {
        goto LABEL_2;
      }
      v21 = IEntity::Type(a2);
      v9 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v9, v21);
      v25 = (CMFCToolBarButton *)((CMFCToolBarButton *(__stdcall *)(int))CBuildingMgr::operator[])(a3->m_iDataA);
      v10 = CBuilding::DoorPackedXY((CBuilding *)v25);
      ISettlerRole::NewDestination(this, a2, v10, 0);
      v27 = a3->m_iDataB != 0;
      v22 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(BOOL))std::vector<unsigned short>::operator[])(v27);
      v17 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(BOOL))std::vector<unsigned short>::operator[])(v27);
      v11 = IEntity::Race(a2);
      v12 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v11, v17);
      result = (_DWORD *)a2->NewToDoList(a2, v12, v22);
      break;
    case 6:
      *((_DWORD *)this + 11) = a3->m_iDataB;
      v23 = IEntity::Type(a2);
      v13 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v13, v23);
      ISettlerRole::NewDestination(this, a2, a3->m_iDataC, 0);
      v24 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(int))std::vector<unsigned short>::operator[])(2);
      v18 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(int))std::vector<unsigned short>::operator[])(2);
      v14 = IEntity::Race(a2);
      v15 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v14, v18);
      result = (_DWORD *)a2->NewToDoList(a2, v15, v24);
      break;
    case 9:
LABEL_2:
      this->SetFree(this, a2, -1);
      v3 = ((int (__stdcall *)())IEntity::ID)();
      result = (_DWORD *)(*(int (__thiscall **)(void *, int, _DWORD))(*(_DWORD *)g_pDarkTribe + 4))(g_pDarkTribe, v3, 0);
      break;
    default:
      result = IEntity::SetFlagBits(a2, (EntityFlag)0x80000000);
      break;
  }
  return result;
}


