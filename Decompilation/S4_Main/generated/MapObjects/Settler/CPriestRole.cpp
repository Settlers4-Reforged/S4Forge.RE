#include "CPriestRole.h"

// Definitions for class CPriestRole

// address=[0x1401760]
// Decompiled from int __cdecl CPriestRole::New(int a1)
static class CPersistence * __cdecl CPriestRole::New(std::istream &) {
  
  if ( operator new(0x40u) )
    return CPriestRole::CPriestRole(a1);
  else
    return 0;
}


// address=[0x157b260]
// Decompiled from int __thiscall CPriestRole::InitWalking(CPriestRole *this, struct CSettler *a2)
class CWalking *  CPriestRole::InitWalking(class CSettler *) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = CWalking::Create(0, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x157b2a0]
// Decompiled from int __thiscall CPriestRole::LogicUpdateJob(CPriestRole *this, struct CSettler *a2)
void  CPriestRole::LogicUpdateJob(class CSettler *) {
  
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
      result = Grid::Distance((Grid *)(v4 - v5), v11);
      if ( result <= SpellRange )
        return (*(int (__thiscall **)(CPriestRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
    }
  }
  else if ( v14 == 16 )
  {
    v12 = IEntity::Type((unsigned __int16 *)a2);
    v9 = IEntity::Type((unsigned __int16 *)a2);
    v6 = IEntity::Race(a2);
    v7 = CEntityToDoListMgr::SettlerJobList(v6, v9);
    return (*(int (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v7, v12);
  }
  else
  {
    return BBSupportTracePrintF(0, "Priest role wrong task in LogicUpdate");
  }
  return result;
}


// address=[0x157b3c0]
// Decompiled from int __stdcall CPriestRole::PostLoadInit(CPropertySet *a1)
void  CPriestRole::PostLoadInit(class CSettler *) {
  
  return CWarMap::AddEntity(a1);
}


// address=[0x157b3e0]
// Decompiled from _DWORD *__thiscall CPriestRole::CPriestRole(_DWORD *this, int a2)
 CPriestRole::CPriestRole(std::istream &) {
  
  int v2; // eax
  unsigned int v4; // [esp+4h] [ebp-24h] BYREF
  int v5; // [esp+8h] [ebp-20h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-1Ch] BYREF
  int v7; // [esp+10h] [ebp-18h]
  unsigned int i; // [esp+14h] [ebp-14h]
  _DWORD *v9; // [esp+18h] [ebp-10h]
  int v10; // [esp+24h] [ebp-4h]

  v9 = this;
  ISelectableSettlerRole::ISelectableSettlerRole(a2);
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
    operator^<int>(a2, (int)(v9 + 15));
  }
  operator^<unsigned int>(a2, &v4);
  for ( i = 0; i < v4; ++i )
  {
    v2 = CEntityTask::Load(a2);
    std::list<CEntityTask>::push_back(v2);
  }
  v10 = -1;
  return v9;
}


// address=[0x157b500]
// Decompiled from int __thiscall CPriestRole::Store(int *this, struct std::ostream *a2)
void  CPriestRole::Store(std::ostream &) {
  
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
  ISelectableSettlerRole::Store(a2);
  v9 = 2;
  operator^<unsigned int>(a2, &v9);
  operator^<int>((int)a2, v11 + 15);
  v8 = std::list<CEntityTask>::size(v11 + 12);
  operator^<unsigned int>(a2, &v8);
  std::list<CEntityTask>::begin(v5);
  v13 = 0;
  while ( 1 )
  {
    v7 = (std::_Iterator_base12 *)std::list<CEntityTask>::end(v4);
    v6 = v7;
    LOBYTE(v13) = 1;
    v12 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=(v7);
    LOBYTE(v13) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v4);
    if ( !v12 )
      break;
    v10 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator->(v5, v3, v4[0]);
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
// Decompiled from int __cdecl CPriestRole::Load(int a1)
static class CPriestRole * __cdecl CPriestRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CPriestRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bef4]
// [Decompilation failed for static unsigned long CPriestRole::m_iClassID]

// address=[0x157b620]
// Decompiled from int __thiscall CPriestRole::GetKindOfSelection(CPriestRole *this, struct CSettler *a2)
int  CPriestRole::GetKindOfSelection(class CSettler *)const {
  
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
  if ( !IEntity::FlagBits(v2, OnBoard) )
    CWarMap::RemoveEntity(v2);
  if ( *((_WORD *)this + 16) )
  {
    VehiclePtr = CVehicleMgr::GetVehiclePtr(*((unsigned __int16 *)this + 16));
    if ( !VehiclePtr && BBSupportDbgReport(2, "MapObjects\\Settler\\PriestRole.cpp", 58, "pVehicle!=NULL") == 1 )
      __debugbreak();
    if ( VehiclePtr )
    {
      v1 = IEntity::ID();
      (*(void (__thiscall **)(struct CVehicle *, int))(*(_DWORD *)VehiclePtr + 124))(VehiclePtr, v1);
    }
  }
  std::list<CEntityTask>::~list<CEntityTask>();
  ISelectableSettlerRole::~ISelectableSettlerRole(this);
}


// address=[0x157b730]
// Decompiled from int __thiscall CPriestRole::GetNextJob(CPriestRole *this, struct CSettler *a2)
void  CPriestRole::GetNextJob(class CSettler *) {
  
  CPriestRole *v3; // [esp+0h] [ebp-4h]

  v3 = this;
  if ( !IMovingEntity::IsEndIter(a2) )
  {
    IMovingEntity::IncToDoListIter(a2);
    if ( !IMovingEntity::IsEndIter(a2) )
      return (*(int (__thiscall **)(CPriestRole *, struct CSettler *))(*(_DWORD *)v3 + 40))(v3, a2);
  }
  IMovingEntity::ResetToDoList(v3);
  *((_DWORD *)v3 + 15) = -1;
  return (*(int (__thiscall **)(CPriestRole *, struct CSettler *))(*(_DWORD *)v3 + 40))(v3, a2);
}


// address=[0x157b7a0]
// Decompiled from void __thiscall CPriestRole::TakeJob(int this, COleCmdUI *a2)
void  CPriestRole::TakeJob(class CSettler *) {
  
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
  int v14; // [esp-14h] [ebp-44h]
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
  int v25; // [esp+1Ch] [ebp-14h]
  char v27; // [esp+2Eh] [ebp-2h]
  bool v28; // [esp+2Fh] [ebp-1h]

  if ( !(unsigned __int8)ISelectableSettlerRole::TakeCommonJob(a2) )
  {
    ActualTask = (const struct CEntityTask *)IMovingEntity::GetActualTask(a2);
    ISettlerRole::InitCommonTaskValues((ISettlerRole *)this, a2, ActualTask);
    switch ( *(_BYTE *)(this + 4) )
    {
      case 7:
        IAnimatedEntity::SetFrame(1);
        if ( *(__int16 *)(this + 14) > 0 || *(__int16 *)(this + 16) > 0 )
          ISettlerRole::NewDestination((ISettlerRole *)this, a2, *(__int16 *)(this + 14), *(__int16 *)(this + 16), 0);
        IMovingEntity::WalkToXY(a2, *(_DWORD *)(this + 24), 0);
        *(_BYTE *)(this + 4) = 6;
        IMovingEntity::SetDisplacementCosts(5);
        (*(void (__thiscall **)(int, COleCmdUI *))(*(_DWORD *)this + 16))(this, a2);
        break;
      case 0xA:
        IAnimatedEntity::SetFrame(1);
        v22 = *(__int16 *)(this + 14) + Y16X16::UnpackXFast(*(_DWORD *)(this + 24));
        v23 = *(__int16 *)(this + 16) + Y16X16::UnpackYFast(*(_DWORD *)(this + 24));
        *(_DWORD *)(this + 24) = Y16X16::PackXYFast(v22, v23);
        IMovingEntity::WalkToXY(a2, *(_DWORD *)(this + 24), 0);
        *(_BYTE *)(this + 4) = 6;
        IMovingEntity::SetDisplacementCosts(5);
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
          if ( Grid::Distance((Grid *)(v10 - v11), v20) <= SpellRange )
          {
            (*(void (__thiscall **)(int, COleCmdUI *))(*(_DWORD *)this + 36))(this, a2);
            v27 = 0;
          }
        }
        if ( v27 )
        {
          IAnimatedEntity::EventQueueEmpty(a2);
          if ( v12 )
          {
            (*(void (__thiscall **)(int, COleCmdUI *))(*(_DWORD *)this + 16))(this, a2);
          }
          else
          {
            *(_BYTE *)(this + 5) = -120;
            IAnimatedEntity::RegisterForLogicUpdate(1);
          }
        }
        break;
      case 0xE:
        IAnimatedEntity::SetFrame(1);
        IMovingEntity::WalkToXY(a2, *(_DWORD *)(this + 28), 0);
        *(_BYTE *)(this + 4) = 6;
        IMovingEntity::SetDisplacementCosts(5);
        *(_DWORD *)(this + 60) = -1;
        (*(void (__thiscall **)(int, COleCmdUI *))(*(_DWORD *)this + 16))(this, a2);
        break;
      case 0x10:
        v28 = 0;
        if ( *(_DWORD *)(this + 60) < 8u )
        {
          v17 = IEntity::ID();
          v16 = Y16X16::UnpackYFast(*(_DWORD *)(this + 24));
          v15 = Y16X16::UnpackXFast(*(_DWORD *)(this + 24));
          v14 = *(_DWORD *)(this + 60);
          v4 = IEntity::OwnerId((unsigned __int8 *)a2);
          v28 = CMagic::CastSpell(v4, v14, v15, v16, 0x10000000, v17) > 0;
        }
        *(_DWORD *)(this + 60) = -1;
        if ( v28 )
        {
          IMovingEntity::SetDisplacementCosts(10);
          IAnimatedEntity::RegisterForLogicUpdate(*(unsigned __int8 *)(this + 7));
          v5 = Y16X16::UnpackYFast(*(_DWORD *)(this + 24));
          v18 = v5 - IEntity::Y(a2);
          v6 = Y16X16::UnpackXFast(*(_DWORD *)(this + 24));
          v7 = IEntity::X(a2);
          v24 = Grid::Direction((Grid *)(v6 - v7), v18);
          IMovingEntity::SetDirection(a2, v24);
        }
        else
        {
          CSettler::TakeWaitList(a2);
        }
        break;
      case 0x11:
        IMovingEntity::SetDisplacementCosts(0);
        v3 = (unsigned int)CGameData::Rand(g_pGameData);
        IAnimatedEntity::RegisterForLogicUpdate(v3 % 0x10 + 1);
        break;
      case 0x18:
        v25 = CVehicleMgr::operator[](*(unsigned __int16 *)(this + 32));
        v13 = IEntity::ID();
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v25 + 128))(v25, v13);
        *(_DWORD *)(this + 60) = -1;
        break;
      default:
        BBSupportTracePrintF(0, "PriestRole - TakeJob unknown task");
        break;
    }
  }
}


// address=[0x157bbc0]
// Decompiled from int __thiscall CPriestRole::Init(int this, CPropertySet *a2)
void  CPriestRole::Init(class CSettler *) {
  
  int result; // eax

  *(_WORD *)(this + 18) = IEntity::ID();
  IEntity::SetFlagBits(a2, VulnerableMask|Selectable);
  CWarMap::AddEntity(a2);
  result = this;
  *(_DWORD *)(this + 60) = -1;
  return result;
}


// address=[0x157bc00]
// Decompiled from int __thiscall CPriestRole::ConvertEventIntoGoal(int this, CPropertySet *a2, const struct CEntityEvent *a3)
void  CPriestRole::ConvertEventIntoGoal(class CSettler *,class CEntityEvent *) {
  
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
  _DWORD *v44; // [esp+2Ch] [ebp-Ch]
  unsigned __int8 v46; // [esp+37h] [ebp-1h]

  v46 = 1;
  switch ( *((_DWORD *)a3 + 1) )
  {
    case 3:
      v46 = 0;
      if ( *((int *)a3 + 5) < 0
        && BBSupportDbgReport(2, "MapObjects\\Settler\\PriestRole.cpp", 490, "_pEvent->m_iData2 >= 0") == 1 )
      {
        __debugbreak();
      }
      *(_DWORD *)(this + 60) = *((_DWORD *)a3 + 2);
      ISettlerRole::NewDestination((ISettlerRole *)this, a2, *((_DWORD *)a3 + 5), 0);
      v6 = IEntity::Race(a2);
      v7 = CEntityToDoListMgr::SettlerJobList(v6, 195);
      (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v7, 195);
      goto LABEL_19;
    case 7:
      v38 = *((_DWORD *)a3 + 3);
      IEntity::SetFlagBits(a2, Selectable);
      IEntity::ClearFlagBits(a2, OnBoard);
      v37 = IEntity::Type((unsigned __int16 *)a2);
      v29 = IEntity::Type((unsigned __int16 *)a2);
      v21 = IEntity::Race(a2);
      v22 = CEntityToDoListMgr::SettlerJobList(v21, v29);
      (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v22, v37);
      *(_BYTE *)(this + 4) = 27;
      v30 = IEntity::ID();
      v23 = IEntity::OwnerId((unsigned __int8 *)a2);
      (*(void (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(off_3D7A3D8, 21, v23, v30, v38);
      goto LABEL_19;
    case 0x11:
      if ( *((_DWORD *)a3 + 2) != 13 )
        goto LABEL_19;
      result = ISelectableSettlerRole::ProcessGoToPosFerry((ISelectableSettlerRole *)this, a2, a3);
      if ( (_BYTE)result )
        return result;
      v43 = *((_DWORD *)a3 + 4);
      v39 = Y16X16::UnpackXFast(v43);
      v40 = Y16X16::UnpackYFast(v43);
      ISettlerRole::NewDestination((ISettlerRole *)this, a2, v39, v40, 0);
      v4 = IEntity::Race(a2);
      v5 = CEntityToDoListMgr::SettlerJobList(v4, 252);
      (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v5, 252);
LABEL_19:
      result = v46;
      if ( v46 )
        *(_DWORD *)(this + 60) = -1;
      return result;
    case 0x18:
      v31 = IEntity::Type((unsigned __int16 *)a2);
      v8 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v8, v31);
      v44 = (_DWORD *)CVehicleMgr::operator[](*((_DWORD *)a3 + 3));
      v9 = IEntity::ID();
      v42 = (*(int (__thiscall **)(_DWORD *, int, int))(*v44 + 140))(v44, 1, v9);
      if ( v42 && IEntity::FlagBits(v44, (EntityFlag)&loc_3000000) )
      {
        ISettlerRole::NewDestination((ISettlerRole *)this, a2, v42, 0);
        v32 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v24 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v10 = IEntity::Race(a2);
        v11 = CEntityToDoListMgr::SettlerJobList(v10, v24);
        (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v11, v32);
        v12 = IEntity::OwnerId((unsigned __int8 *)a2);
        if ( v12 == CPlayerManager::GetLocalPlayerId() )
        {
          v13 = IEntity::ID();
          CInputProcessor::DeSelectEntity(&g_cInputProcessor, v13);
        }
        v14 = IEntity::ID();
        (*(void (__thiscall **)(_DWORD *, int))(*v44 + 164))(v44, v14);
        IEntity::ClearFlagBits(a2, Selectable|Selected);
        v15 = IEntity::ID();
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)g_pGroupMgr + 28))(g_pGroupMgr, v15);
        v33 = *(unsigned __int16 *)(this + 32);
        v25 = IEntity::ID();
        v16 = IEntity::OwnerId((unsigned __int8 *)a2);
        (*(void (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(
          off_3D7A3D8,
          18,
          v16,
          v25,
          v33);
      }
      else
      {
        IEntity::SetFlagBits(a2, Selectable);
        v34 = IEntity::Type((unsigned __int16 *)a2);
        v26 = IEntity::Type((unsigned __int16 *)a2);
        v17 = IEntity::Race(a2);
        v18 = CEntityToDoListMgr::SettlerJobList(v17, v26);
        (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v18, v34);
      }
      goto LABEL_19;
    case 0x19:
      v41 = *((_DWORD *)a3 + 4);
      v35 = Y16X16::UnpackYFast(v41);
      v27 = Y16X16::UnpackXFast(v41);
      v19 = IEntity::ID();
      CSettlerMgr::SearchSpaceForSettler((CSettlerMgr *)g_cSettlerMgr, v19, v27, v35);
      CWarMap::AddEntity(a2);
      IEntity::SetFlagBits(a2, Selectable|Visible);
      IEntity::ClearFlagBits(a2, OnBoard);
      *(_BYTE *)(this + 4) = 27;
      v36 = *(unsigned __int16 *)(this + 32);
      v28 = IEntity::ID();
      v20 = IEntity::OwnerId((unsigned __int8 *)a2);
      (*(void (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(off_3D7A3D8, 21, v20, v28, v36);
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
  
  ISelectableSettlerRole::ISelectableSettlerRole(this);
  *(_DWORD *)this = &CPriestRole::_vftable_;
  std::list<CEntityTask>::list<CEntityTask>((char *)this + 48);
  return this;
}


