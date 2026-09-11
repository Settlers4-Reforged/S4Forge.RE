#include "CPriestRole.h"

// Definitions for class CPriestRole

// address=[0x1401760]
// Decompiled from int __cdecl CPriestRole::New(int a1)
class CPersistence * __cdecl CPriestRole::New(std::istream & a1) {
  
  if ( operator new(0x40u) != 0 )
  {
    return ((_DWORD (__stdcall *)(int))CPriestRole::CPriestRole)(a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x157b260]
// Decompiled from int __thiscall CPriestRole::InitWalking(CPriestRole *this, struct CSettler *a2)
class CWalking *  CPriestRole::InitWalking(class CSettler * a2) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId(a2);
  v4 = (int)CWalking::Create(0, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x157b2a0]
// Decompiled from int __thiscall CPriestRole::LogicUpdateJob(CPriestRole *this, struct CSettler *a2)
void  CPriestRole::LogicUpdateJob(class CSettler * a2) {
  
  int v2; // eax
  int v3; // esi
  int v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int result; // eax
  int v9; // [esp-8h] [ebp-1Ch]
  int v10; // [esp-4h] [ebp-18h]
  int v11; // [esp-4h] [ebp-18h]
  int v12; // [esp-4h] [ebp-18h]
  int SpellRange; // [esp+4h] [ebp-10h]
  char v14; // [esp+Ch] [ebp-8h]

  v14 = *((_BYTE *)this + 4);
  if ( v14 == 6 )
  {
    IMovingEntity::SetDistance(a2, 0);
    result = (*(int (__thiscall **)(CPriestRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
    if ( *((_DWORD *)this + 15) != -1 )
    {
      v10 = *((_DWORD *)this + 15);
      v2 = IEntity::Race(a2);
      SpellRange = CMagic::MagicGetSpellRange(v2, v10);
      v3 = Y16X16::UnpackYFast(*((_DWORD *)this + 6));
      v11 = v3 - IEntity::Y(a2);
      v4 = Y16X16::UnpackXFast(*((_DWORD *)this + 6));
      v5 = IEntity::X(a2);
      result = Grid::Distance(v4 - v5, v11);
      if ( result <= SpellRange )
      {
        return (*(int (__thiscall **)(CPriestRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
      }
    }
  }
  else if ( v14 == 16 )
  {
    v12 = IEntity::Type(a2);
    v9 = IEntity::Type(a2);
    v6 = IEntity::Race(a2);
    v7 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v6, v9);
    return a2->NewToDoList(a2, v7, v12);
  }
  else
  {
    return BBSupportTracePrintF(0, "Priest role wrong task in LogicUpdate");
  }
  return result;
}


// address=[0x157b3c0]
// Decompiled from int __stdcall CPriestRole::PostLoadInit(IEntity *a1)
void  CPriestRole::PostLoadInit(class CSettler * a1) {
  
  return ((int (__cdecl *)(CPropertySet *))CWarMap::AddEntity)((CPropertySet *)a1);
}


// address=[0x157b3e0]
// Decompiled from _DWORD *__thiscall CPriestRole::CPriestRole(_DWORD *this, int a2)
 CPriestRole::CPriestRole(std::istream & a2) {
  
  struct CEntityTask *v2; // eax
  unsigned int v4; // [esp+4h] [ebp-24h] BYREF
  unsigned int v5; // [esp+8h] [ebp-20h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned int v7; // [esp+10h] [ebp-18h]
  unsigned int i; // [esp+14h] [ebp-14h]
  _DWORD *v9; // [esp+18h] [ebp-10h]
  int v10; // [esp+24h] [ebp-4h]

  v9 = this;
  ((void (__stdcall *)(int))ISelectableSettlerRole::ISelectableSettlerRole)(a2);
  v10 = 0;
  *v9 = &CPriestRole::_vftable_;
  std::list<CEntityTask>::list<CEntityTask>(v9 + 12);
  LOBYTE(v10) = 1;
  operator^<unsigned int>(a2, &v5);
  v9[15] = -1;
  v7 = v5;
  if ( v5 != 1 )
  {
    if ( v7 != 2 )
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CPriestRole");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    operator^<int>((struct std::istream *)a2, v9 + 15);
  }
  operator^<unsigned int>(a2, &v4);
  for ( i = 0;
        i < v4;
        ++i )
  {
    v2 = CEntityTask::Load((struct std::istream *)a2);
    std::list<CEntityTask>::push_back((int)v2);
  }
  v10 = -1;
  return v9;
}


// address=[0x157b500]
// Decompiled from int __thiscall CPriestRole::Store(int *this, struct std::ostream *a2)
void  CPriestRole::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-44h]
  _DWORD v4[3]; // [esp+4h] [ebp-40h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-34h] BYREF
  std::_Iterator_base12 *v6; // [esp+1Ch] [ebp-28h]
  std::_Iterator_base12 *v7; // [esp+20h] [ebp-24h]
  int v8; // [esp+24h] [ebp-20h] BYREF
  int v9; // [esp+28h] [ebp-1Ch] BYREF
  int v10; // [esp+2Ch] [ebp-18h]
  int *v11; // [esp+30h] [ebp-14h]
  char v12; // [esp+37h] [ebp-Dh]
  int v13; // [esp+40h] [ebp-4h]

  v11 = this;
  ((void (__stdcall *)(struct std::ostream *))ISelectableSettlerRole::Store)(a2);
  v9 = 2;
  operator^<unsigned int>(a2, (unsigned int *)&v9);
  operator^<int>(a2, v11 + 15);
  v8 = std::list<CEntityTask>::size(v11 + 12);
  operator^<unsigned int>(a2, (unsigned int *)&v8);
  ((void (__stdcall *)(_BYTE *))std::list<CEntityTask>::begin)(v5);
  v13 = 0;
  while ( 1 )
  {
    v7 = (std::_Iterator_base12 *)((std::_Iterator_base12 *(__stdcall *)(_DWORD *))std::list<CEntityTask>::end)(v4);
    v6 = v7;
    LOBYTE(v13) = 1;
    v12 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=(v7);
    LOBYTE(v13) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v4);
    if ( v12 == 0 )
    {
      break;
    }
    v10 = ((int (__thiscall *)(_BYTE *, int, _DWORD))std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator->)(v5, v3, v4[0]);
    (*(void (__thiscall **)(int, struct std::ostream *))(*(_DWORD *)v10 + 4))(v10, a2);
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v5);
  }
  v13 = -1;
  return std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v5);
}


// address=[0x157c450]
// Decompiled from int __thiscall CPriestRole::ClassID(CPriestRole *this)
unsigned long  CPriestRole::ClassID(void)const {
  
  return CPriestRole::m_iClassID;
}


// address=[0x157c470]
// Decompiled from int __thiscall CPriestRole::GetSettlerRole(CPriestRole *this)
int  CPriestRole::GetSettlerRole(void)const {
  
  return 9;
}


// address=[0x1588800]
// Decompiled from int __cdecl CPriestRole::Load(struct std::istream *a1)
class CPriestRole * __cdecl CPriestRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)((void **(__cdecl *)(struct std::istream *, struct TypeDescriptor *))CPersistence::New)(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CPriestRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bef4]
// [Decompilation failed for static unsigned long CPriestRole::m_iClassID]

// address=[0x157b620]
// Decompiled from int __thiscall CPriestRole::GetKindOfSelection(CPriestRole *this, struct CSettler *a2)
int  CPriestRole::GetKindOfSelection(class CSettler * a2)const {
  
  return 94;
}


// address=[0x157b640]
// Decompiled from void __thiscall CPriestRole::~CPriestRole(CPriestRole *this)
 CPriestRole::~CPriestRole(void) {
  
  int v1; // eax
  CPropertySet *v2; // [esp+4h] [ebp-18h]
  struct CVehicle *VehiclePtr; // [esp+8h] [ebp-14h]

  *(_DWORD *)this = &CPriestRole::_vftable_;
  v2 = (CPropertySet *)CSettlerMgr::operator[](*((unsigned __int16 *)this + 9));
  if ( IEntity::FlagBits((IEntity *)v2, ENTITY_FLAG_ON_BOARD) == 0 )
  {
    CWarMap::RemoveEntity((IEntity *)v2);
  }
  if ( *((_WORD *)this + 16) != 0 )
  {
    VehiclePtr = (struct CVehicle *)CVehicleMgr::GetVehiclePtr(*((unsigned __int16 *)this + 16));
    if ( VehiclePtr == 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\PriestRole.cpp", 58, "pVehicle!=NULL") == 1 )
    {
      __debugbreak();
    }
    if ( VehiclePtr != 0 )
    {
      v1 = ((int (__stdcall *)())IEntity::ID)();
      VehiclePtr->EntityOrderCanceled(VehiclePtr, v1);
    }
  }
  std::list<CEntityTask>::~list<CEntityTask>();
  ISelectableSettlerRole::~ISelectableSettlerRole((ISelectableSettlerRole *)this);
}


// address=[0x157b730]
// Decompiled from int __thiscall CPriestRole::GetNextJob(CPriestRole *this, struct CSettler *a2)
void  CPriestRole::GetNextJob(class CSettler * a2) {
  
  CPriestRole *v3; // [esp+0h] [ebp-4h]

  v3 = this;
  if ( IMovingEntity::IsEndIter(a2) || (IMovingEntity::IncToDoListIter(a2), IMovingEntity::IsEndIter(a2)) )
  {
    ((void (__cdecl *)(_DWORD))IMovingEntity::ResetToDoList)(v3);
    *((_DWORD *)v3 + 15) = -1;
  }
  return (*(int (__thiscall **)(CPriestRole *, struct CSettler *))(*(_DWORD *)v3 + 40))(v3, a2);
}


// address=[0x157b7a0]
// Decompiled from void __thiscall CPriestRole::TakeJob(int this, struct CSettler *a2)
void  CPriestRole::TakeJob(class CSettler * a2) {
  
  const struct CEntityTask *ActualTask; // eax
  unsigned int v3; // eax
  int v4; // eax
  int v5; // esi
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // esi
  int v10; // esi
  int v11; // eax
  char v12; // al
  int v13; // eax
  unsigned int v14; // [esp-14h] [ebp-44h]
  int v15; // [esp-10h] [ebp-40h]
  int v16; // [esp-Ch] [ebp-3Ch]
  int v17; // [esp-4h] [ebp-34h]
  int v18; // [esp-4h] [ebp-34h]
  int v19; // [esp-4h] [ebp-34h]
  int v20; // [esp-4h] [ebp-34h]
  int SpellRange; // [esp+4h] [ebp-2Ch]
  int v22; // [esp+Ch] [ebp-24h]
  int v23; // [esp+10h] [ebp-20h]
  int v24; // [esp+14h] [ebp-1Ch]
  CVehicle *v25; // [esp+1Ch] [ebp-14h]
  char v27; // [esp+2Eh] [ebp-2h]
  bool v28; // [esp+2Fh] [ebp-1h]

  if ( (unsigned __int8)((int (__stdcall *)(COleCmdUI *))ISelectableSettlerRole::TakeCommonJob)((COleCmdUI *)a2) == 0 )
  {
    ActualTask = IMovingEntity::GetActualTask(a2);
    ISettlerRole::InitCommonTaskValues((ISettlerRole *)this, a2, ActualTask);
    switch ( *(_BYTE *)(this + 4) )
    {
      case 7:
        ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)(1);
        if ( *(__int16 *)(this + 14) > 0 || *(__int16 *)(this + 16) > 0 )
        {
          ISettlerRole::NewDestination((ISettlerRole *)this, a2, *(__int16 *)(this + 14), *(__int16 *)(this + 16), 0);
        }
        IMovingEntity::WalkToXY(a2, *(_DWORD *)(this + 24), 0);
        *(_BYTE *)(this + 4) = 6;
        ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(5);
        (*(void (__thiscall **)(int, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
        break;
      case 0xA:
        ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)(1);
        v22 = *(__int16 *)(this + 14) + Y16X16::UnpackXFast(*(_DWORD *)(this + 24));
        v23 = *(__int16 *)(this + 16) + Y16X16::UnpackYFast(*(_DWORD *)(this + 24));
        *(_DWORD *)(this + 24) = Y16X16::PackXYFast(v22, v23);
        IMovingEntity::WalkToXY(a2, *(_DWORD *)(this + 24), 0);
        *(_BYTE *)(this + 4) = 6;
        ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(5);
        v27 = 1;
        if ( *(_DWORD *)(this + 60) != -1 )
        {
          v19 = *(_DWORD *)(this + 60);
          v8 = IEntity::Race(a2);
          SpellRange = CMagic::MagicGetSpellRange(v8, v19);
          v9 = Y16X16::UnpackYFast(*(_DWORD *)(this + 24));
          v20 = v9 - IEntity::Y(a2);
          v10 = Y16X16::UnpackXFast(*(_DWORD *)(this + 24));
          v11 = IEntity::X(a2);
          if ( Grid::Distance(v10 - v11, v20) <= SpellRange )
          {
            (*(void (__thiscall **)(int, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
            v27 = 0;
          }
        }
        if ( v27 != 0 )
        {
          IAnimatedEntity::EventQueueEmpty(a2);
          if ( v12 != 0 )
          {
            (*(void (__thiscall **)(int, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
          }
          else
          {
            *(_BYTE *)(this + 5) = -120;
            ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
          }
        }
        break;
      case 0xE:
        ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)(1);
        IMovingEntity::WalkToXY(a2, *(_DWORD *)(this + 28), 0);
        *(_BYTE *)(this + 4) = 6;
        ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(5);
        *(_DWORD *)(this + 60) = -1;
        (*(void (__thiscall **)(int, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
        break;
      case 0x10:
        v28 = 0;
        if ( *(_DWORD *)(this + 60) < 8u )
        {
          v17 = ((int (__stdcall *)())IEntity::ID)();
          v16 = Y16X16::UnpackYFast(*(_DWORD *)(this + 24));
          v15 = Y16X16::UnpackXFast(*(_DWORD *)(this + 24));
          v14 = *(_DWORD *)(this + 60);
          v4 = IEntity::OwnerId(a2);
          v28 = CMagic::CastSpell(v4, v14, v15, v16, 0x10000000u, v17) > 0;
        }
        *(_DWORD *)(this + 60) = -1;
        if ( v28 )
        {
          ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(10);
          ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(*(unsigned __int8 *)(this + 7));
          v5 = Y16X16::UnpackYFast(*(_DWORD *)(this + 24));
          v18 = v5 - IEntity::Y(a2);
          v6 = Y16X16::UnpackXFast(*(_DWORD *)(this + 24));
          v7 = IEntity::X(a2);
          v24 = Grid::Direction(v6 - v7, v18);
          IMovingEntity::SetDirection(a2, v24);
        }
        else
        {
          CSettler::TakeWaitList(a2);
        }
        break;
      case 0x11:
        ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(0);
        v3 = CGameData::Rand(g_pGameData);
        ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(v3 % 0x10 + 1);
        break;
      case 0x18:
        v25 = CVehicleMgr::operator[](*(unsigned __int16 *)(this + 32));
        v13 = ((int (__stdcall *)())IEntity::ID)();
        v25->EntityEnter(v25, v13);
        *(_DWORD *)(this + 60) = -1;
        break;
      default:
        BBSupportTracePrintF(0, "PriestRole - TakeJob unknown task");
        break;
    }
  }
}


// address=[0x157bbc0]
// Decompiled from int __thiscall CPriestRole::Init(int this, IEntity *a2)
void  CPriestRole::Init(class CSettler * a2) {
  
  int result; // eax

  *(_WORD *)(this + 18) = ((int (__stdcall *)())IEntity::ID)();
  IEntity::SetFlagBits(a2, ENTITY_FLAG_VulnerableMask|ENTITY_FLAG_Selectable);
  CWarMap::AddEntity(a2);
  result = this;
  *(_DWORD *)(this + 60) = -1;
  return result;
}


// address=[0x157bc00]
// Decompiled from int __thiscall CPriestRole::ConvertEventIntoGoal(int this, struct CSettler *a2, const struct CEntityEvent *a3)
void  CPriestRole::ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3) {
  
  int result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // [esp-8h] [ebp-40h]
  int v25; // [esp-8h] [ebp-40h]
  int v26; // [esp-8h] [ebp-40h]
  int v27; // [esp-8h] [ebp-40h]
  int v28; // [esp-8h] [ebp-40h]
  int v29; // [esp-8h] [ebp-40h]
  int v30; // [esp-8h] [ebp-40h]
  int v31; // [esp-4h] [ebp-3Ch]
  int v32; // [esp-4h] [ebp-3Ch]
  int v33; // [esp-4h] [ebp-3Ch]
  int v34; // [esp-4h] [ebp-3Ch]
  int v35; // [esp-4h] [ebp-3Ch]
  int v36; // [esp-4h] [ebp-3Ch]
  int v37; // [esp-4h] [ebp-3Ch]
  int v38; // [esp+8h] [ebp-30h]
  int v39; // [esp+Ch] [ebp-2Ch]
  int v40; // [esp+10h] [ebp-28h]
  int v41; // [esp+18h] [ebp-20h]
  int v42; // [esp+20h] [ebp-18h]
  int v43; // [esp+24h] [ebp-14h]
  CVehicle *v44; // [esp+2Ch] [ebp-Ch]
  unsigned __int8 v46; // [esp+37h] [ebp-1h]

  v46 = 1;
  switch ( a3->m_iEvent )
  {
    case 3:
      v46 = 0;
      if ( a3->m_iDataC < 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\PriestRole.cpp", 490, "_pEvent->m_iData2 >= 0") == 1 )
      {
        __debugbreak();
      }
      *(_DWORD *)(this + 60) = a3->m_iType;
      ISettlerRole::NewDestination((ISettlerRole *)this, a2, a3->m_iDataC, 0);
      v6 = IEntity::Race(a2);
      v7 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v6, 195);
      a2->NewToDoList(a2, v7, 195);
      goto LABEL_19;
    case 7:
      v38 = a3->m_iDataA;
      IEntity::SetFlagBits(a2, ENTITY_FLAG_Selectable);
      IEntity::ClearFlagBits(a2, ENTITY_FLAG_ON_BOARD);
      v37 = IEntity::Type(a2);
      v29 = IEntity::Type(a2);
      v21 = IEntity::Race(a2);
      v22 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v21, v29);
      a2->NewToDoList(a2, v22, v37);
      *(_BYTE *)(this + 4) = 27;
      v30 = ((int (__stdcall *)())IEntity::ID)();
      v23 = IEntity::OwnerId(a2);
      g_pAI->PostAIEvent(g_pAI, 21, v23, v30, v38);
      goto LABEL_19;
    case 0x11:
      if ( a3->m_iType != 13 )
      {
        goto LABEL_19;
      }
      result = ISelectableSettlerRole::ProcessGoToPosFerry((ISelectableSettlerRole *)this, a2, a3);
      if ( (_BYTE)result == 0 )
      {
        v43 = a3->m_iDataB;
        v39 = Y16X16::UnpackXFast(v43);
        v40 = Y16X16::UnpackYFast(v43);
        ISettlerRole::NewDestination((ISettlerRole *)this, a2, v39, v40, 0);
        v4 = IEntity::Race(a2);
        v5 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v4, 252);
        a2->NewToDoList(a2, v5, 252);
LABEL_19:
        result = v46;
        if ( v46 != 0 )
        {
          *(_DWORD *)(this + 60) = -1;
        }
      }
      return result;
    case 0x18:
      v31 = IEntity::Type(a2);
      v8 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v8, v31);
      v44 = CVehicleMgr::operator[](a3->m_iDataA);
      v9 = ((int (__stdcall *)())IEntity::ID)();
      v42 = v44->GetMeetingPointXY(v44, SETTLER_OBJ, v9);
      if ( v42 != 0 && IEntity::FlagBits(v44, (EntityFlag)&loc_3000000) != 0 )
      {
        ISettlerRole::NewDestination((ISettlerRole *)this, a2, v42, 0);
        v32 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(_DWORD))std::vector<unsigned short>::operator[])(0);
        v24 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(_DWORD))std::vector<unsigned short>::operator[])(0);
        v10 = IEntity::Race(a2);
        v11 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v10, v24);
        a2->NewToDoList(a2, v11, v32);
        v12 = IEntity::OwnerId(a2);
        if ( v12 == CPlayerManager::GetLocalPlayerId() )
        {
          v13 = ((int (__stdcall *)())IEntity::ID)();
          CInputProcessor::DeSelectEntity(&g_cInputProcessor, v13);
        }
        v14 = ((int (__stdcall *)())IEntity::ID)();
        v44->Attach(v44, v14);
        IEntity::ClearFlagBits(a2, ENTITY_FLAG_Selectable|ENTITY_FLAG_Selected);
        v15 = ((int (__stdcall *)())IEntity::ID)();
        ((void (__thiscall *)(CGroupMgr *, int))g_pGroupMgr->DetachEntityFromAllGroups)(g_pGroupMgr, v15);
        v33 = *(unsigned __int16 *)(this + 32);
        v25 = ((int (__stdcall *)())IEntity::ID)();
        v16 = IEntity::OwnerId(a2);
        g_pAI->PostAIEvent(g_pAI, 18, v16, v25, v33);
      }
      else
      {
        IEntity::SetFlagBits(a2, ENTITY_FLAG_Selectable);
        v34 = IEntity::Type(a2);
        v26 = IEntity::Type(a2);
        v17 = IEntity::Race(a2);
        v18 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v17, v26);
        a2->NewToDoList(a2, v18, v34);
      }
      goto LABEL_19;
    case 0x19:
      v41 = a3->m_iDataB;
      v35 = Y16X16::UnpackYFast(v41);
      v27 = Y16X16::UnpackXFast(v41);
      v19 = ((int (__stdcall *)())IEntity::ID)();
      CSettlerMgr::SearchSpaceForSettler(&g_cSettlerMgr, v19, v27, v35);
      CWarMap::AddEntity(a2);
      IEntity::SetFlagBits(a2, ENTITY_FLAG_Selectable|ENTITY_FLAG_Visible);
      IEntity::ClearFlagBits(a2, ENTITY_FLAG_ON_BOARD);
      *(_BYTE *)(this + 4) = 27;
      v36 = *(unsigned __int16 *)(this + 32);
      v28 = ((int (__stdcall *)())IEntity::ID)();
      v20 = IEntity::OwnerId(a2);
      g_pAI->PostAIEvent(g_pAI, 21, v20, v28, v36);
      *(_WORD *)(this + 32) = 0;
      goto LABEL_19;
    default:
      v46 = 0;
      IEntity::SetFlagBits(a2, (EntityFlag)0x80000000);
      goto LABEL_19;
  }
}


// address=[0x1587b00]
// Decompiled from CPriestRole *__thiscall CPriestRole::CPriestRole(CPriestRole *this)
 CPriestRole::CPriestRole(void) {
  
  ISelectableSettlerRole::ISelectableSettlerRole((ISelectableSettlerRole *)this);
  *(_DWORD *)this = &CPriestRole::_vftable_;
  std::list<CEntityTask>::list<CEntityTask>((char *)this + 48);
  return this;
}


