#include "CPioneerRole.h"

// Definitions for class CPioneerRole

// address=[0x1401620]
// Decompiled from int __cdecl CPioneerRole::New(int a1)
class CPersistence * __cdecl CPioneerRole::New(std::istream & a1) {
  
  if ( operator new(0x4Cu) )
    return CPioneerRole::CPioneerRole(a1);
  else
    return 0;
}


// address=[0x15796d0]
// Decompiled from int __thiscall CPioneerRole::InitWalking(CPioneerRole *this, struct CSettler *a2)
class CWalking *  CPioneerRole::InitWalking(class CSettler * a2) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = CWalking::Create(0, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x1579710]
// Decompiled from int __thiscall CPioneerRole::LogicUpdateJob(CPioneerRole *this, struct CSettler *a2)
void  CPioneerRole::LogicUpdateJob(class CSettler * a2) {
  
  int v2; // ecx
  int result; // eax
  int v4; // [esp+0h] [ebp-8h]

  v2 = *((char *)this + 4);
  v4 = v2 - 6;
  switch ( v2 )
  {
    case 6:
      IMovingEntity::SetDistance(a2, 0);
      result = (*(int (__thiscall **)(CPioneerRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
      break;
    case 13:
      if ( debug )
      {
        if ( DEBUG_FLAGS[dword_4152134] )
          BBSupportTracePrint(0, "LogicUpdateJob RESOURCE_GATHERING");
      }
      IMovingEntity::ResetToDoList(v4);
      result = (*(int (__thiscall **)(CPioneerRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
      break;
    case 16:
      if ( debug && DEBUG_FLAGS[dword_4152134] )
        BBSupportTracePrint(0, "LogicUpdateJob WORK");
      CPioneerRole::TakeLand(this, a2);
      IMovingEntity::IncToDoListIter(a2);
      result = (*(int (__thiscall **)(CPioneerRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
      break;
    case 31:
      if ( debug && DEBUG_FLAGS[dword_4152134] )
        BBSupportTracePrint(0, "LogicUpdateJob SEARCH");
      result = (*(int (__thiscall **)(CPioneerRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
      break;
    default:
      result = BBSupportTracePrintF(0, "CPioneerRole::LogicUpdateJob(): Invalid task!");
      break;
  }
  return result;
}


// address=[0x1579880]
// Decompiled from int __thiscall CPioneerRole::PostLoadInit(int this, CPropertySet *a2)
void  CPioneerRole::PostLoadInit(class CSettler * a2) {
  
  int result; // eax
  int v4; // [esp+0h] [ebp-4h]

  CWarMap::AddEntity(a2);
  if ( std::list<CEntityTask>::size((void *)(this + 64)) )
    IMovingEntity::SetToDoList(a2, this + 64);
  IMovingEntity::ResetToDoList(this);
  while ( 1 )
  {
    result = *(unsigned __int8 *)(v4 + 12);
    if ( !*(_BYTE *)(v4 + 12) )
      break;
    IMovingEntity::IncToDoListIter(a2);
    --*(_BYTE *)(v4 + 12);
  }
  return result;
}


// address=[0x15798f0]
// Decompiled from _DWORD *__thiscall CPioneerRole::CPioneerRole(_DWORD *this, int a2)
 CPioneerRole::CPioneerRole(std::istream & a2) {
  
  int v2; // eax
  _DWORD v4[2]; // [esp+4h] [ebp-24h] BYREF
  int v5; // [esp+Ch] [ebp-1Ch] BYREF
  int pExceptionObject; // [esp+10h] [ebp-18h] BYREF
  unsigned int i; // [esp+14h] [ebp-14h]
  _DWORD *v8; // [esp+18h] [ebp-10h]
  int v9; // [esp+24h] [ebp-4h]

  v8 = this;
  ISelectableSettlerRole::ISelectableSettlerRole(a2);
  v9 = 0;
  *v8 = &CPioneerRole::_vftable_;
  std::list<CEntityTask>::list<CEntityTask>(v8 + 16);
  LOBYTE(v9) = 1;
  operator^<unsigned int>(a2, &v5);
  v4[1] = v5;
  if ( v5 != 1 )
  {
    BBSupportTracePrintF(3, "CPioneerRole::CPioneerRole(): Invalid save game version!");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<int>(a2, (int)(v8 + 12));
  operator^<int>(a2, (int)(v8 + 13));
  operator^<int>(a2, (int)(v8 + 14));
  operator^<int>(a2, (int)(v8 + 15));
  operator^<unsigned int>(a2, v4);
  for ( i = 0; i < v4[0]; ++i )
  {
    v2 = CEntityTask::Load(a2);
    std::list<CEntityTask>::push_back(v2);
  }
  operator^<unsigned char>(a2, v8 + 3);
  v9 = -1;
  return v8;
}


// address=[0x1579a50]
// Decompiled from int __thiscall CPioneerRole::Store(int *this, struct std::ostream *a2)
void  CPioneerRole::Store(std::ostream & a2) {
  
  unsigned int v2; // esi
  int v4; // [esp+0h] [ebp-80h]
  int v5; // [esp+4h] [ebp-7Ch]
  _BYTE v6[12]; // [esp+8h] [ebp-78h] BYREF
  _BYTE v7[12]; // [esp+14h] [ebp-6Ch] BYREF
  _BYTE v8[12]; // [esp+20h] [ebp-60h] BYREF
  _BYTE v9[12]; // [esp+2Ch] [ebp-54h] BYREF
  _BYTE v10[12]; // [esp+38h] [ebp-48h] BYREF
  std::_Iterator_base12 *v11; // [esp+44h] [ebp-3Ch]
  std::_Iterator_base12 *ActualIter; // [esp+48h] [ebp-38h]
  char *v13; // [esp+4Ch] [ebp-34h]
  std::_Iterator_base12 *v14; // [esp+50h] [ebp-30h]
  std::_Iterator_base12 *v15; // [esp+54h] [ebp-2Ch]
  std::_Iterator_base12 *v16; // [esp+58h] [ebp-28h]
  std::_Iterator_base12 *v17; // [esp+5Ch] [ebp-24h]
  int v18; // [esp+60h] [ebp-20h] BYREF
  int v19; // [esp+64h] [ebp-1Ch] BYREF
  int v20; // [esp+68h] [ebp-18h]
  int *v21; // [esp+6Ch] [ebp-14h]
  char v22; // [esp+70h] [ebp-10h]
  char v23; // [esp+71h] [ebp-Fh]
  char v24; // [esp+72h] [ebp-Eh]
  int v25; // [esp+73h] [ebp-Dh] BYREF
  int v26; // [esp+7Ch] [ebp-4h]

  v21 = this;
  ISelectableSettlerRole::Store(a2);
  v18 = 1;
  operator^<unsigned int>(a2, &v18);
  operator^<int>((int)a2, v21 + 12);
  operator^<int>((int)a2, v21 + 13);
  operator^<int>((int)a2, v21 + 14);
  operator^<int>((int)a2, v21 + 15);
  v19 = std::list<CEntityTask>::size(v21 + 16);
  operator^<unsigned int>(a2, &v19);
  std::list<CEntityTask>::begin(v10);
  v26 = 0;
  while ( 1 )
  {
    v17 = (std::_Iterator_base12 *)std::list<CEntityTask>::end(v8);
    v16 = v17;
    LOBYTE(v26) = 1;
    v24 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=(v17);
    LOBYTE(v26) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v8);
    if ( !v24 )
      break;
    v20 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator->(v10, v4, v5);
    (*(void (__thiscall **)(int, struct std::ostream *))(*(_DWORD *)v20 + 4))(v20, a2);
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v10);
  }
  v26 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v10);
  v13 = (char *)CSettlerMgr::operator[](*((unsigned __int16 *)v21 + 9));
  LOBYTE(v25) = 0;
  if ( v19 )
  {
    std::list<CEntityTask>::begin(v9);
    v26 = 2;
    while ( 1 )
    {
      v15 = (std::_Iterator_base12 *)std::list<CEntityTask>::end(v7);
      v14 = v15;
      LOBYTE(v26) = 3;
      v23 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=(v15);
      LOBYTE(v26) = 2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v7);
      if ( !v23 )
        break;
      ActualIter = (std::_Iterator_base12 *)IMovingEntity::GetActualIter(v13, (int)v6);
      v11 = ActualIter;
      LOBYTE(v26) = 4;
      v22 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator==(ActualIter);
      LOBYTE(v26) = 2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v6);
      if ( v22 )
        break;
      LOBYTE(v25) = v25 + 1;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v9);
    }
    v26 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v9);
  }
  v2 = (unsigned __int8)v25;
  if ( v2 >= std::list<CEntityTask>::size(v21 + 16) )
    LOBYTE(v25) = 0;
  return operator^<unsigned char>(a2, (int)&v25);
}


// address=[0x157b220]
// Decompiled from int __thiscall CPioneerRole::ClassID(CPioneerRole *this)
unsigned long  CPioneerRole::ClassID(void)const {
  
  return CPioneerRole::m_iClassID;
}


// address=[0x157b240]
// Decompiled from int __thiscall CPioneerRole::GetSettlerRole(CPioneerRole *this)
int  CPioneerRole::GetSettlerRole(void)const {
  
  return 11;
}


// address=[0x15887c0]
// Decompiled from int __cdecl CPioneerRole::Load(int a1)
class CPioneerRole * __cdecl CPioneerRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CPioneerRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bef0]
// [Decompilation failed for static unsigned long CPioneerRole::m_iClassID]

// address=[0x1579cb0]
// Decompiled from CPioneerRole *__thiscall CPioneerRole::CPioneerRole(CPioneerRole *this)
 CPioneerRole::CPioneerRole(void) {
  
  ISelectableSettlerRole::ISelectableSettlerRole(this);
  *(_DWORD *)this = &CPioneerRole::_vftable_;
  std::list<CEntityTask>::list<CEntityTask>((char *)this + 64);
  *((_DWORD *)this + 12) = -1;
  *((_DWORD *)this + 13) = -1;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 6) = 0;
  return this;
}


// address=[0x1579d50]
// Decompiled from void __thiscall CPioneerRole::~CPioneerRole(CPioneerRole *this)
 CPioneerRole::~CPioneerRole(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // [esp-8h] [ebp-24h]
  CPropertySet *v4; // [esp+4h] [ebp-18h]
  struct CVehicle *VehiclePtr; // [esp+8h] [ebp-14h]

  *(_DWORD *)this = &CPioneerRole::_vftable_;
  v4 = (CPropertySet *)CSettlerMgr::operator[](*((unsigned __int16 *)this + 9));
  if ( !IEntity::FlagBits(v4, EntityFlag_OnBoard) )
    CWarMap::RemoveEntity(v4);
  if ( *((_DWORD *)this + 6) )
  {
    v3 = Y16X16::UnpackYFast(*((_DWORD *)this + 6));
    v1 = Y16X16::UnpackXFast(*((_DWORD *)this + 6));
    CWorldManager::ClearFlagBits(v1, v3, 32);
  }
  if ( *((_WORD *)this + 16) )
  {
    VehiclePtr = CVehicleMgr::GetVehiclePtr(*((unsigned __int16 *)this + 16));
    if ( !VehiclePtr && BBSupportDbgReport(2, "MapObjects\\Settler\\PioneerRole.cpp", 100, "pVehicle!=NULL") == 1 )
      __debugbreak();
    if ( VehiclePtr )
    {
      v2 = IEntity::ID();
      (*(void (__thiscall **)(struct CVehicle *, int))(*(_DWORD *)VehiclePtr + 124))(VehiclePtr, v2);
    }
  }
  std::list<CEntityTask>::~list<CEntityTask>();
  ISelectableSettlerRole::~ISelectableSettlerRole(this);
}


// address=[0x1579e70]
// Decompiled from int __thiscall CPioneerRole::GetNextJob(CPioneerRole *this, struct CSettler *a2)
void  CPioneerRole::GetNextJob(class CSettler * a2) {
  
  CPioneerRole *v3; // [esp+0h] [ebp-4h]

  v3 = this;
  IMovingEntity::IncToDoListIter(a2);
  if ( IMovingEntity::IsEndIter(a2) )
    IMovingEntity::ResetToDoList(v3);
  return (*(int (__thiscall **)(CPioneerRole *, struct CSettler *))(*(_DWORD *)v3 + 40))(v3, a2);
}


// address=[0x1579eb0]
// Decompiled from void __thiscall CPioneerRole::TakeJob(ISettlerRole *this, COleCmdUI *a2)
void  CPioneerRole::TakeJob(class CSettler * a2) {
  
  const struct CEntityTask *ActualTask; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // [esp-Ch] [ebp-24h]
  int v7; // [esp-8h] [ebp-20h]
  int v8; // [esp+0h] [ebp-18h]
  bool v10; // [esp+17h] [ebp-1h]
  bool v11; // [esp+17h] [ebp-1h]

  v10 = IEntity::FlagBits(a2, (EntityFlag)0x100000u) != 0;
  IEntity::ClearFlagBits(a2, (EntityFlag)0x100000u);
  if ( !(unsigned __int8)ISelectableSettlerRole::TakeCommonJob(a2) )
  {
    ActualTask = (const struct CEntityTask *)IMovingEntity::GetActualTask(a2);
    ISettlerRole::InitCommonTaskValues(this, a2, ActualTask);
    switch ( *((_BYTE *)this + 4) )
    {
      case 7:
        if ( debug && DEBUG_FLAGS[dword_4152134] )
          BBSupportTracePrint(0, "TakeJob GO");
        IAnimatedEntity::SetFrame(1);
        if ( *((__int16 *)this + 7) > 0 || *((__int16 *)this + 8) > 0 )
          ISettlerRole::NewDestination(this, a2, *((__int16 *)this + 7), *((__int16 *)this + 8), 0);
        IMovingEntity::WalkToXY(a2, *((_DWORD *)this + 6), 0);
        *((_BYTE *)this + 4) = 6;
        IMovingEntity::SetDisplacementCosts(5);
        (*(void (__thiscall **)(ISettlerRole *, COleCmdUI *))(*(_DWORD *)this + 16))(this, a2);
        break;
      case 0xA:
      case 0x25:
        v11 = *((_BYTE *)this + 4) == 37 || v10;
        IAnimatedEntity::SetFrame(1);
        if ( v11 )
          IMovingEntity::WalkToXY(a2, *((_DWORD *)this + 6), 0x2000);
        else
          IMovingEntity::WalkToXY(a2, *((_DWORD *)this + 6), 0);
        *((_BYTE *)this + 4) = 6;
        IMovingEntity::SetDisplacementCosts(5);
        (*(void (__thiscall **)(ISettlerRole *, COleCmdUI *))(*(_DWORD *)this + 16))(this, a2);
        break;
      case 0xD:
        if ( debug && DEBUG_FLAGS[dword_4152134] )
          BBSupportTracePrint(0, "TakeJob WORK");
        if ( CPioneerRole::SearchPosition(this, a2) )
        {
          (*(void (__thiscall **)(ISettlerRole *, COleCmdUI *))(*(_DWORD *)this + 36))(this, a2);
        }
        else
        {
          *((_DWORD *)this + 15) += 32;
          if ( (int)++*((_DWORD *)this + 14) <= 28 )
            IAnimatedEntity::RegisterForLogicUpdate(1);
          else
            CPioneerRole::WorkIsDone(this, a2);
        }
        break;
      case 0x10:
        if ( debug && DEBUG_FLAGS[dword_4152134] )
          BBSupportTracePrint(0, "TakeJob WORK");
        goto LABEL_13;
      case 0x11:
        IMovingEntity::SetDisplacementCosts(0);
        IAnimatedEntity::RegisterForLogicUpdate(1);
        break;
      case 0x18:
        if ( !*((_WORD *)this + 16)
          && BBSupportDbgReport(2, "MapObjects\\Settler\\PioneerRole.cpp", 465, "m_uHomeEntityId") == 1 )
        {
          __debugbreak();
        }
        if ( *((_WORD *)this + 16) )
        {
          v8 = CVehicleMgr::operator[](*((unsigned __int16 *)this + 16));
          v5 = IEntity::ID();
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 128))(v8, v5);
          if ( !IEntity::FlagBits(a2, EntityFlag_OnBoard)
            && BBSupportDbgReport(
                 2,
                 "MapObjects\\Settler\\PioneerRole.cpp",
                 469,
                 "_pSettler->FlagBits(ENTITY_FLAG_ON_BOARD ) != 0") == 1 )
          {
            __debugbreak();
          }
        }
        break;
      case 0x1F:
        if ( debug && DEBUG_FLAGS[dword_4152134] )
          BBSupportTracePrint(0, "TakeJob SEARCH");
        v6 = IEntity::Y(a2);
        v3 = IEntity::X(a2);
        if ( CPioneerRole::CheckLand(this, v3, v6, a2, 0) )
        {
          if ( debug && DEBUG_FLAGS[dword_4152134] )
            BBSupportTracePrint(0, "TakeJob SEARCH doit");
LABEL_13:
          IMovingEntity::SetDisplacementCosts(10);
          IAnimatedEntity::RegisterForLogicUpdate(*((char *)this + 6));
        }
        else
        {
          if ( *((_DWORD *)this + 6) )
          {
            v7 = Y16X16::UnpackYFast(*((_DWORD *)this + 6));
            v4 = Y16X16::UnpackXFast(*((_DWORD *)this + 6));
            CWorldManager::ClearFlagBits(v4, v7, 0x20u);
            *((_DWORD *)this + 6) = 0;
          }
          IMovingEntity::IncToDoListIter(a2);
          (*(void (__thiscall **)(ISettlerRole *, COleCmdUI *))(*(_DWORD *)this + 36))(this, a2);
        }
        break;
      default:
        BBSupportTracePrintF(0, "CPioneerRole::TakeJob(): Invalid task!");
        break;
    }
  }
}


// address=[0x157a330]
// Decompiled from int __thiscall CPioneerRole::Init(_WORD *this, CPropertySet *a2)
void  CPioneerRole::Init(class CSettler * a2) {
  
  if ( IEntity::FlagBits(a2, EntityFlag_Attached)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\PioneerRole.cpp",
         244,
         "!_pSettler->FlagBits( ENTITY_FLAG_ATTACHED )") == 1 )
  {
    __debugbreak();
  }
  if ( this[16] && BBSupportDbgReport(2, "MapObjects\\Settler\\PioneerRole.cpp", 245, "!m_uHomeEntityId") == 1 )
    __debugbreak();
  this[9] = IEntity::ID();
  IEntity::SetFlagBits(a2, EntityFlag_VulnerableMask|EntityFlag_Selectable);
  return CWarMap::AddEntity(a2);
}


// address=[0x157a3c0]
// Decompiled from int __thiscall CPioneerRole::WorkIsDone(CPioneerRole *this, struct CSettler *a2)
void  CPioneerRole::WorkIsDone(class CSettler * a2) {
  
  int v2; // eax
  int v3; // eax
  int v5; // [esp-8h] [ebp-Ch]
  int v6; // [esp-4h] [ebp-8h]

  v6 = IEntity::Type((unsigned __int16 *)a2);
  v5 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  v3 = CEntityToDoListMgr::SettlerJobList(v2, v5);
  return (*(int (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v3, v6);
}


// address=[0x157a410]
// Decompiled from char __thiscall CPioneerRole::ConvertEventIntoGoal(int *this, CPropertySet *a2, const struct CEntityEvent *a3)
void  CPioneerRole::ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3) {
  
  int v3; // eax
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
  int v22; // [esp-8h] [ebp-48h]
  int v23; // [esp-8h] [ebp-48h]
  int v24; // [esp-8h] [ebp-48h]
  int v25; // [esp-8h] [ebp-48h]
  int v26; // [esp-8h] [ebp-48h]
  int v27; // [esp-8h] [ebp-48h]
  int v28; // [esp-8h] [ebp-48h]
  int v29; // [esp-4h] [ebp-44h]
  int v30; // [esp-4h] [ebp-44h]
  int v31; // [esp-4h] [ebp-44h]
  int v32; // [esp-4h] [ebp-44h]
  int v33; // [esp-4h] [ebp-44h]
  int v34; // [esp-4h] [ebp-44h]
  int v35; // [esp-4h] [ebp-44h]
  int v36; // [esp+8h] [ebp-38h]
  int v37; // [esp+10h] [ebp-30h]
  int v38; // [esp+14h] [ebp-2Ch]
  int v39; // [esp+18h] [ebp-28h]
  int v40; // [esp+20h] [ebp-20h]
  int v41; // [esp+24h] [ebp-1Ch]
  int v42; // [esp+28h] [ebp-18h]
  int v43; // [esp+2Ch] [ebp-14h]
  int v44; // [esp+30h] [ebp-10h]
  _DWORD *v45; // [esp+38h] [ebp-8h]

  v3 = *((_DWORD *)a3 + 1) - 7;
  switch ( *((_DWORD *)a3 + 1) )
  {
    case 7:
      v37 = *((_DWORD *)a3 + 3);
      IEntity::SetFlagBits(a2, EntityFlag_Selectable);
      IEntity::ClearFlagBits(a2, EntityFlag_OnBoard);
      CSettler::TakeWaitList(a2);
      v22 = IEntity::ID();
      v4 = IEntity::OwnerId((unsigned __int8 *)a2);
      LOBYTE(v3) = (*(int (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)g_pAI + 44))(g_pAI, 21, v4, v22, v37);
      break;
    case 9:
      v38 = *((_DWORD *)a3 + 4);
      IEntity::SetFlagBits(a2, EntityFlag_Selectable);
      LOBYTE(v3) = (*(int (__thiscall **)(int *, CPropertySet *, int))(*this + 64))(this, a2, v38);
      break;
    case 0x11:
      if ( this[6] )
      {
        v23 = Y16X16::UnpackYFast(this[6]);
        v5 = Y16X16::UnpackXFast(this[6]);
        CWorldManager::ClearFlagBits(v5, v23, 32);
        LOBYTE(v3) = (_BYTE)this;
        this[6] = 0;
      }
      if ( *((_DWORD *)a3 + 2) == 13 )
      {
        LOBYTE(v3) = ISelectableSettlerRole::ProcessGoToPosFerry((ISelectableSettlerRole *)this, a2, a3);
        if ( !(_BYTE)v3 )
        {
          v36 = *((_DWORD *)a3 + 3);
          v43 = *((_DWORD *)a3 + 4);
          v41 = Y16X16::UnpackXFast(v43);
          v42 = Y16X16::UnpackYFast(v43);
          if ( (v36 & 4) != 0 )
          {
            v44 = 193;
          }
          else
          {
            this[14] = 0;
            this[15] = 0;
            this[12] = v41;
            this[13] = v42;
            v44 = 192;
          }
          ISettlerRole::NewDestination((ISettlerRole *)this, a2, v41, v42, 0);
          v6 = IEntity::Race(a2);
          v7 = CEntityToDoListMgr::SettlerJobList(v6, v44);
          LOBYTE(v3) = (*(int (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v7, v44);
        }
      }
      break;
    case 0x18:
      v29 = IEntity::Type((unsigned __int16 *)a2);
      v8 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v8, v29);
      v45 = (_DWORD *)CVehicleMgr::operator[](*((_DWORD *)a3 + 3));
      v30 = IEntity::ID();
      v9 = IEntity::ObjType((unsigned __int8 *)a2);
      v40 = (*(int (__thiscall **)(_DWORD *, int, int))(*v45 + 140))(v45, v9, v30);
      if ( v40 && IEntity::FlagBits(v45, (EntityFlag)&loc_3000000) )
      {
        ISettlerRole::NewDestination((ISettlerRole *)this, a2, v40, 0);
        IEntity::SetFlagBits(a2, (EntityFlag)0x100000u);
        v31 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v24 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v10 = IEntity::Race(a2);
        v11 = CEntityToDoListMgr::SettlerJobList(v10, v24);
        (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v11, v31);
        v12 = IEntity::OwnerId((unsigned __int8 *)a2);
        if ( v12 == CPlayerManager::GetLocalPlayerId() )
        {
          v13 = IEntity::ID();
          CInputProcessor::DeSelectEntity(&g_cInputProcessor, v13);
        }
        v14 = IEntity::ID();
        (*(void (__thiscall **)(_DWORD *, int))(*v45 + 164))(v45, v14);
        IEntity::ClearFlagBits(a2, EntityFlag_Selectable|EntityFlag_Selected);
        v15 = IEntity::ID();
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)g_pGroupMgr + 28))(g_pGroupMgr, v15);
        v32 = *((unsigned __int16 *)this + 16);
        v25 = IEntity::ID();
        v16 = IEntity::OwnerId((unsigned __int8 *)a2);
        LOBYTE(v3) = (*(int (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)g_pAI + 44))(
                       g_pAI,
                       18,
                       v16,
                       v25,
                       v32);
      }
      else
      {
        IEntity::SetFlagBits(a2, EntityFlag_Selectable);
        v33 = IEntity::Type((unsigned __int16 *)a2);
        v26 = IEntity::Type((unsigned __int16 *)a2);
        v17 = IEntity::Race(a2);
        v18 = CEntityToDoListMgr::SettlerJobList(v17, v26);
        LOBYTE(v3) = (*(int (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v18, v33);
      }
      break;
    case 0x19:
      v39 = *((_DWORD *)a3 + 4);
      v34 = Y16X16::UnpackYFast(v39);
      v27 = Y16X16::UnpackXFast(v39);
      v19 = IEntity::ID();
      CSettlerMgr::SearchSpaceForSettler((CSettlerMgr *)g_cSettlerMgr, v19, v27, v34);
      CWarMap::AddEntity(a2);
      IEntity::SetFlagBits(a2, EntityFlag_Selectable|EntityFlag_Visible);
      IEntity::ClearFlagBits(a2, EntityFlag_OnBoard);
      CSettler::TakeWaitList(a2);
      v35 = *((unsigned __int16 *)this + 16);
      v28 = IEntity::ID();
      v20 = IEntity::OwnerId((unsigned __int8 *)a2);
      LOBYTE(v3) = (*(int (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)g_pAI + 44))(g_pAI, 21, v20, v28, v35);
      break;
    default:
      v3 = IEntity::FlagBits(a2, EntityFlag_Registered);
      if ( !v3 )
      {
        BBSupportTracePrintF(0, "CPioneerRole::ConvertEventIntoGoal(): Unknown event %u!", *((_DWORD *)a3 + 1));
        LOBYTE(v3) = IAnimatedEntity::RegisterForLogicUpdate(1);
      }
      break;
  }
  return v3;
}


// address=[0x157a8b0]
// Decompiled from char __thiscall CPioneerRole::SearchPosition(CPioneerRole *this, struct CSettler *a2)
bool  CPioneerRole::SearchPosition(class CSettler * a2) {
  
  int v2; // eax
  int v3; // esi
  int v4; // esi
  int v6; // eax
  int v7; // [esp-4h] [ebp-3Ch]
  int v8; // [esp-4h] [ebp-3Ch]
  int v9; // [esp+4h] [ebp-34h]
  int v10; // [esp+Ch] [ebp-2Ch]
  unsigned int v11; // [esp+14h] [ebp-24h]
  int v12; // [esp+18h] [ebp-20h]
  int v13; // [esp+1Ch] [ebp-1Ch]
  int v14; // [esp+20h] [ebp-18h]
  int v15; // [esp+24h] [ebp-14h]
  unsigned int v16; // [esp+24h] [ebp-14h]
  int i; // [esp+28h] [ebp-10h]
  int v18; // [esp+2Ch] [ebp-Ch]
  int v19; // [esp+30h] [ebp-8h]

  v14 = -1;
  v12 = -1;
  v11 = -1;
  v13 = 0;
  v7 = IEntity::Y(a2);
  v2 = IEntity::X(a2);
  v10 = CWorldManager::SectorId(v2, v7);
  for ( i = *((_DWORD *)this + 15); i < *((_DWORD *)this + 15) + 32; ++i )
  {
    v3 = IEntity::X(a2);
    v19 = CSpiralOffsets::DeltaX(i) + v3;
    v4 = IEntity::Y(a2);
    v18 = CSpiralOffsets::DeltaY(i) + v4;
    if ( !(unsigned __int8)CWorldManager::InWorld(v19, v18) )
      return 0;
    if ( CWorldManager::SectorId(v19, v18) == v10 && CPioneerRole::CheckLand(this, v19, v18, a2, 1) )
    {
      ++v13;
      v15 = CSpiralOffsets::PseudoDistanceSquareEx(v19 - *((_DWORD *)this + 12), v18 - *((_DWORD *)this + 13));
      v8 = v18 - IEntity::Y(a2);
      v6 = IEntity::X(a2);
      v16 = v15 + 3 * CSpiralOffsets::PseudoDistanceSquareEx(v19 - v6, v8);
      if ( v16 < v11 )
      {
        v11 = v16;
        v14 = v19;
        v12 = v18;
      }
    }
    if ( v13 > 16 )
      break;
  }
  if ( v14 == -1 )
    return 0;
  v9 = CWorldManager::Index(v14, v12);
  CWorldManager::SetFlagBits(v9, 0x20u);
  *((_DWORD *)this + 6) = Y16X16::PackXYFast(v14, v12);
  *((int *)this + 15) %= 6;
  *((_DWORD *)this + 14) = 0;
  return 1;
}


// address=[0x157aaa0]
// Decompiled from bool __thiscall CPioneerRole::CheckLand(CPioneerRole *this, int a2, int a3, struct CSettler *a4, bool a5)
bool  CPioneerRole::CheckLand(int a2, int a3, class CSettler * a4, bool a5) {
  
  int v5; // eax
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // [esp-4h] [ebp-20h]
  int v11; // [esp-4h] [ebp-20h]
  int v12; // [esp+8h] [ebp-14h]
  int v13; // [esp+Ch] [ebp-10h]
  int v14; // [esp+10h] [ebp-Ch]
  unsigned int v15; // [esp+14h] [ebp-8h]
  int v16; // [esp+18h] [ebp-4h]

  v15 = 153;
  if ( a5 )
    v15 = 185;
  v10 = IEntity::Y(a4);
  v5 = IEntity::X(a4);
  if ( !(unsigned __int8)CWorldManager::InWorld(v5, v10) )
    return 0;
  v11 = IEntity::Y(a4);
  v7 = IEntity::X(a4);
  v13 = CWorldManager::Index(v7, v11);
  v16 = CWorldManager::Index(a2, a3);
  v8 = CWorldManager::SectorId(v16);
  if ( v8 != CWorldManager::SectorId(v13) )
    return 0;
  if ( CWorldManager::FlagBits(v16, v15) )
    return 0;
  if ( CWorldManager::MapObjectId(a2, a3) && a5 )
    return 0;
  v14 = CWorldManager::OwnerId(v16);
  if ( !v14 )
    return 1;
  v12 = CAlliances::AllianceId(v14);
  v9 = IEntity::OwnerId((unsigned __int8 *)a4);
  return v12 != CAlliances::AllianceId(v9) && *(char *)(CWorldManager::GetLandscapePtr() + 4 * v16 + 3) < 0;
}


// address=[0x157abe0]
// Decompiled from int __thiscall CPioneerRole::TakeLand(CPioneerRole *this, struct CSettler *a2)
void  CPioneerRole::TakeLand(class CSettler * a2) {
  
  int v2; // esi
  int v3; // eax
  int v4; // eax
  int v6; // [esp+8h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  v6 = IEntity::X(a2);
  v7 = IEntity::Y(a2);
  v8 = CWorldManager::OwnerId(v6, v7);
  if ( v8 )
  {
    v2 = CAlliances::AllianceId(v8);
    v3 = IEntity::OwnerId((unsigned __int8 *)a2);
    if ( v2 == CAlliances::AllianceId(v3) )
      CPlayerManager::GetLocalPlayerId();
  }
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  CWorldManager::SetOwnerId(v6, v7, v4);
  return CWorldManager::ClearFlagBits(v6, v7, 32);
}


