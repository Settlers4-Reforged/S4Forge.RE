#include "CThiefRole.h"

// Definitions for class CThiefRole

// address=[0x14022a0]
// Decompiled from int __cdecl CThiefRole::New(int a1)
static class CPersistence * __cdecl CThiefRole::New(std::istream &) {
  
  if ( operator new(0x44u) )
    return CThiefRole::CThiefRole(a1);
  else
    return 0;
}


// address=[0x1588940]
// Decompiled from int __cdecl CThiefRole::Load(int a1)
static class CThiefRole * __cdecl CThiefRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CThiefRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x1592e30]
// Decompiled from int __thiscall CThiefRole::InitWalking(CThiefRole *this, struct CSettler *a2)
class CWalking *  CThiefRole::InitWalking(class CSettler *) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = CWalking::Create(0, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x1592e70]
// Decompiled from char __thiscall CThiefRole::LogicUpdateJob(CThiefRole *this, struct CSettler *a2)
void  CThiefRole::LogicUpdateJob(class CSettler *) {
  
  int v2; // eax
  char result; // al
  int v4; // eax
  unsigned __int8 *v5; // eax
  int v6; // eax
  unsigned __int8 *v7; // eax
  int v8; // [esp-Ch] [ebp-20h]
  unsigned int v9; // [esp-8h] [ebp-1Ch]
  int v10; // [esp-4h] [ebp-18h]
  int v11; // [esp+4h] [ebp-10h]
  int v12; // [esp+8h] [ebp-Ch]
  char v13; // [esp+Ch] [ebp-8h]

  v13 = *((_BYTE *)this + 4);
  if ( v13 == 6 )
  {
    IMovingEntity::SetDistance(a2, 0);
    (*(void (__thiscall **)(CThiefRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
    goto LABEL_17;
  }
  if ( v13 == 21 )
  {
    v12 = *((unsigned __int8 *)this + 7) / 2;
    *((_BYTE *)this + 6) -= v12;
    if ( *((char *)this + 6) >= v12 )
    {
      v9 = *((unsigned __int8 *)this + 64);
      v8 = IEntity::Y(a2);
      v2 = IEntity::X(a2);
      CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v2, v8, v9, 1u);
      IAnimatedEntity::RegisterForLogicUpdate(v12 - 1);
      *((_BYTE *)this + 64) = 0;
      goto LABEL_17;
    }
    goto LABEL_16;
  }
  if ( v13 != 22 )
  {
    CTrace::Print("Thief role wrong task in LogicUpdate");
    goto LABEL_17;
  }
  v11 = *((unsigned __int8 *)this + 7) / 2;
  *((_BYTE *)this + 6) -= v11;
  if ( *((char *)this + 6) < v11 )
  {
LABEL_16:
    (*(void (__thiscall **)(CThiefRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
    goto LABEL_17;
  }
  if ( !ISettlerRole::SourcePileId(this) )
    return (*(int (__thiscall **)(CThiefRole *, struct CSettler *, int))(*(_DWORD *)this + 64))(this, a2, -1);
  v4 = ISettlerRole::SourcePileId(this);
  v5 = CPileMgr::operator[](v4);
  *((_BYTE *)this + 64) = (*(int (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)v5 + 60))(v5, v5);
  if ( !*((_BYTE *)this + 64) && BBSupportDbgReport(2, "MapObjects\\Settler\\ThiefRole.cpp", 333, "m_uGood > 0") == 1 )
    __debugbreak();
  v10 = IEntity::ID();
  v6 = ISettlerRole::SourcePileId(this);
  v7 = CPileMgr::operator[](v6);
  CPile::ChangeAmountAndDetach((CPile *)v7, v10);
  IAnimatedEntity::RegisterForLogicUpdate(v11);
LABEL_17:
  result = *((_BYTE *)this + 64);
  *((_BYTE *)this + 11) = result;
  return result;
}


// address=[0x1593050]
// Decompiled from int __thiscall CThiefRole::LogicUpdate(CThiefRole *this, struct CSettler *a2)
void  CThiefRole::LogicUpdate(class CSettler *) {
  
  unsigned int TickCounter; // [esp+4h] [ebp-8h]

  TickCounter = CGameData::GetTickCounter(g_pGameData);
  if ( TickCounter >= *((_DWORD *)this + 15) )
    *((_DWORD *)this + 15) = ISelectableSettlerRole::ThiefCheckMasquerade(this, a2) + TickCounter;
  return ISettlerRole::LogicUpdate(this, a2);
}


// address=[0x15930a0]
// Decompiled from CThiefRole *__thiscall CThiefRole::UpdateJob(CThiefRole *this, struct CSettler *a2)
void  CThiefRole::UpdateJob(class CSettler *) {
  
  CThiefRole *result; // eax
  char v3; // [esp+8h] [ebp-1Ch]
  int v4; // [esp+Ch] [ebp-18h]
  int v5; // [esp+10h] [ebp-14h]
  char v6; // [esp+14h] [ebp-10h]
  int v7; // [esp+18h] [ebp-Ch]
  int v8; // [esp+1Ch] [ebp-8h]

  result = this;
  v6 = *((_BYTE *)this + 4);
  if ( v6 == 21 )
  {
    v5 = IAnimatedEntity::Frame(a2);
    v4 = *((unsigned __int16 *)this + 4);
    if ( v5 <= v4 )
      return (CThiefRole *)IAnimatedEntity::SetFrame(0);
    else
      return (CThiefRole *)IAnimatedEntity::SetFrame(v5 - v4);
  }
  else if ( v6 == 22 )
  {
    v8 = *((unsigned __int8 *)this + 7);
    v7 = *((unsigned __int16 *)this + 4) + IAnimatedEntity::Frame(a2);
    if ( v7 < v8 )
      return (CThiefRole *)IAnimatedEntity::SetFrame(v7);
    if ( v8 <= 0 )
      v3 = 0;
    else
      v3 = v8 - 1;
    LOBYTE(v7) = v3;
    return (CThiefRole *)IAnimatedEntity::SetFrame(v7);
  }
  return result;
}


// address=[0x1593160]
// Decompiled from int __thiscall CThiefRole::PostLoadInit(int this, CPropertySet *a2)
void  CThiefRole::PostLoadInit(class CSettler *) {
  
  int result; // eax
  int v4; // [esp+0h] [ebp-4h]

  CWarMap::AddEntity(a2);
  if ( std::list<CEntityTask>::size((void *)(this + 48)) )
    IMovingEntity::SetToDoList(a2, this + 48);
  IMovingEntity::ResetToDoList(this);
  while ( *(_BYTE *)(v4 + 12) )
  {
    IMovingEntity::IncToDoListIter(a2);
    --*(_BYTE *)(v4 + 12);
  }
  *(_DWORD *)(v4 + 60) = 0;
  result = v4;
  *(_BYTE *)(v4 + 11) = *(_BYTE *)(v4 + 64);
  return result;
}


// address=[0x15931e0]
// Decompiled from char __thiscall CThiefRole::SetFree(CThiefRole *this, struct CSettler *a2, int a3)
bool  CThiefRole::SetFree(class CSettler *,int) {
  
  int v3; // eax
  int v5; // [esp-Ch] [ebp-10h]
  unsigned int v6; // [esp-8h] [ebp-Ch]

  if ( *((_BYTE *)this + 64) )
  {
    v6 = *((unsigned __int8 *)this + 64);
    v5 = IEntity::Y(a2);
    v3 = IEntity::X(a2);
    CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v3, v5, v6, 1u);
    *((_BYTE *)this + 64) = 0;
  }
  ISettlerRole::SetFree(this, a2, -1);
  return 0;
}


// address=[0x1593240]
// Decompiled from _DWORD *__thiscall CThiefRole::CThiefRole(_DWORD *this, int a2)
 CThiefRole::CThiefRole(std::istream &) {
  
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
  *v8 = &CThiefRole::_vftable_;
  std::list<CEntityTask>::list<CEntityTask>(v8 + 12);
  LOBYTE(v9) = 1;
  operator^<unsigned int>(a2, &v5);
  v4[1] = v5;
  if ( v5 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CThiefRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, v8 + 16);
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


// address=[0x1593370]
// Decompiled from int __thiscall CThiefRole::Store(char *this, struct std::ostream *a2)
void  CThiefRole::Store(std::ostream &) {
  
  unsigned int v2; // esi
  _BYTE v4[12]; // [esp+8h] [ebp-78h] BYREF
  _BYTE v5[12]; // [esp+14h] [ebp-6Ch] BYREF
  _BYTE v6[12]; // [esp+20h] [ebp-60h] BYREF
  _BYTE v7[12]; // [esp+2Ch] [ebp-54h] BYREF
  _BYTE v8[12]; // [esp+38h] [ebp-48h] BYREF
  std::_Iterator_base12 *v9; // [esp+44h] [ebp-3Ch]
  std::_Iterator_base12 *ActualIter; // [esp+48h] [ebp-38h]
  char *v11; // [esp+4Ch] [ebp-34h]
  std::_Iterator_base12 *v12; // [esp+50h] [ebp-30h]
  std::_Iterator_base12 *v13; // [esp+54h] [ebp-2Ch]
  std::_Iterator_base12 *v14; // [esp+58h] [ebp-28h]
  std::_Iterator_base12 *v15; // [esp+5Ch] [ebp-24h]
  int v16; // [esp+60h] [ebp-20h] BYREF
  int v17; // [esp+64h] [ebp-1Ch] BYREF
  int v18; // [esp+68h] [ebp-18h]
  char *v19; // [esp+6Ch] [ebp-14h]
  char v20; // [esp+70h] [ebp-10h]
  char v21; // [esp+71h] [ebp-Fh]
  char v22; // [esp+72h] [ebp-Eh]
  int v23; // [esp+73h] [ebp-Dh] BYREF
  int v24; // [esp+7Ch] [ebp-4h]

  v19 = this;
  ISelectableSettlerRole::Store(a2);
  v16 = 1;
  operator^<unsigned int>(a2, &v16);
  operator^<unsigned char>(a2, (int)(v19 + 64));
  v17 = std::list<CEntityTask>::size(v19 + 48);
  operator^<unsigned int>(a2, &v17);
  std::list<CEntityTask>::begin(v8);
  v24 = 0;
  while ( 1 )
  {
    v15 = (std::_Iterator_base12 *)std::list<CEntityTask>::end(v6);
    v14 = v15;
    LOBYTE(v24) = 1;
    v22 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=(v15);
    LOBYTE(v24) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v6);
    if ( !v22 )
      break;
    v18 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator->(v8);
    (*(void (__thiscall **)(int, struct std::ostream *))(*(_DWORD *)v18 + 4))(v18, a2);
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v8);
  }
  v24 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v8);
  v11 = (char *)CSettlerMgr::operator[](*((unsigned __int16 *)v19 + 9));
  LOBYTE(v23) = 0;
  if ( v17 )
  {
    std::list<CEntityTask>::begin(v7);
    v24 = 2;
    while ( 1 )
    {
      v13 = (std::_Iterator_base12 *)std::list<CEntityTask>::end(v5);
      v12 = v13;
      LOBYTE(v24) = 3;
      v21 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=(v13);
      LOBYTE(v24) = 2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v5);
      if ( !v21 )
        break;
      ActualIter = (std::_Iterator_base12 *)IMovingEntity::GetActualIter(v11, (int)v4);
      v9 = ActualIter;
      LOBYTE(v24) = 4;
      v20 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator==(ActualIter);
      LOBYTE(v24) = 2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v4);
      if ( v20 )
        break;
      LOBYTE(v23) = v23 + 1;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v7);
    }
    v24 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v7);
  }
  v2 = (unsigned __int8)v23;
  if ( v2 >= std::list<CEntityTask>::size(v19 + 48) )
    LOBYTE(v23) = 0;
  return operator^<unsigned char>(a2, (int)&v23);
}


// address=[0x1594890]
// Decompiled from int __thiscall CThiefRole::ClassID(CThiefRole *this)
unsigned long  CThiefRole::ClassID(void)const {
  
  return CThiefRole::m_iClassID;
}


// address=[0x15948b0]
// Decompiled from int __thiscall CThiefRole::GetSettlerRole(CThiefRole *this)
int  CThiefRole::GetSettlerRole(void)const {
  
  return 19;
}


// address=[0x3d8bfa8]
// [Decompilation failed for static unsigned long CThiefRole::m_iClassID]

// address=[0x1593590]
// Decompiled from CThiefRole *__thiscall CThiefRole::CThiefRole(CThiefRole *this)
 CThiefRole::CThiefRole(void) {
  
  ISelectableSettlerRole::ISelectableSettlerRole(this);
  *(_DWORD *)this = &CThiefRole::_vftable_;
  std::list<CEntityTask>::list<CEntityTask>((char *)this + 48);
  *((_DWORD *)this + 15) = 0;
  *((_BYTE *)this + 64) = 0;
  return this;
}


// address=[0x1593610]
// Decompiled from void __thiscall CThiefRole::~CThiefRole(CThiefRole *this)
 CThiefRole::~CThiefRole(void) {
  
  *(_DWORD *)this = &CThiefRole::_vftable_;
  std::list<CEntityTask>::~list<CEntityTask>();
  ISelectableSettlerRole::~ISelectableSettlerRole(this);
}


// address=[0x1593640]
// Decompiled from int __thiscall CThiefRole::GetNextJob(CThiefRole *this, struct CSettler *a2)
void  CThiefRole::GetNextJob(class CSettler *) {
  
  int result; // eax

  IMovingEntity::IncToDoListIter(a2);
  result = IMovingEntity::IsEndIter(a2);
  if ( !(_BYTE)result )
    return (*(int (__thiscall **)(CThiefRole *, struct CSettler *))(*(_DWORD *)this + 40))(this, a2);
  *((_BYTE *)this + 4) = 17;
  return result;
}


// address=[0x1593680]
// Decompiled from int __thiscall CThiefRole::TakeJob(int this, COleCmdUI *a2)
void  CThiefRole::TakeJob(class CSettler *) {
  
  int result; // eax
  const struct CEntityTask *ActualTask; // eax
  int v4; // eax
  int v5; // esi
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // [esp-4h] [ebp-30h]
  int v13; // [esp+4h] [ebp-28h]
  int v14; // [esp+Ch] [ebp-20h]
  int v15; // [esp+14h] [ebp-18h]
  int v16; // [esp+18h] [ebp-14h]
  int v17; // [esp+1Ch] [ebp-10h]
  struct IEntity *v18; // [esp+20h] [ebp-Ch]

  result = ISelectableSettlerRole::TakeCommonJob(a2);
  if ( (_BYTE)result )
    return result;
  v17 = IAnimatedEntity::JobPart(a2);
  v16 = IAnimatedEntity::Frame(a2);
  ActualTask = (const struct CEntityTask *)IMovingEntity::GetActualTask(a2);
  ISettlerRole::InitCommonTaskValues((ISettlerRole *)this, a2, ActualTask);
  if ( IAnimatedEntity::JobPart(a2) == 301 && *(_BYTE *)(this + 64) )
    IAnimatedEntity::SetJobPart(a2, 302);
  switch ( *(_BYTE *)(this + 4) )
  {
    case 7:
      if ( v17 == IAnimatedEntity::JobPart(a2) && v16 >= *(unsigned __int8 *)(this + 7) )
        IAnimatedEntity::SetFrame(1);
      else
        IAnimatedEntity::SetFrame(v16);
      v13 = *(__int16 *)(this + 14) + Y16X16::UnpackXFast(*(_DWORD *)(this + 24));
      v10 = Y16X16::UnpackYFast(*(_DWORD *)(this + 24));
      *(_DWORD *)(this + 24) = Y16X16::PackXYFast(v13, *(__int16 *)(this + 16) + v10);
      IMovingEntity::WalkToXY(a2, *(_DWORD *)(this + 24), 0);
      *(_BYTE *)(this + 4) = 6;
      IMovingEntity::SetDisplacementCosts(5);
      *(_BYTE *)(this + 5) = -120;
      result = IAnimatedEntity::RegisterForLogicUpdate(1);
      break;
    case 0xA:
      if ( IEntity::FlagBits(a2, Attached) )
      {
        IAnimatedEntity::SetFrame(1);
        if ( *(__int16 *)(this + 14) > 0 || *(__int16 *)(this + 16) > 0 )
          ISettlerRole::NewDestination((ISettlerRole *)this, a2, *(__int16 *)(this + 14), *(__int16 *)(this + 16), 0);
        IMovingEntity::WalkToXY(a2, *(_DWORD *)(this + 24), 0);
        *(_BYTE *)(this + 4) = 6;
        IMovingEntity::SetDisplacementCosts(5);
        result = (*(int (__thiscall **)(int, COleCmdUI *))(*(_DWORD *)this + 16))(this, a2);
      }
      else
      {
        if ( CThiefRole::CheckGoodInSurrounding((CThiefRole *)this, a2) )
        {
          if ( v17 != IAnimatedEntity::JobPart(a2) || IAnimatedEntity::Frame(a2) >= *(unsigned __int8 *)(this + 7) )
            IAnimatedEntity::SetFrame(1);
          v14 = *(__int16 *)(this + 14) + Y16X16::UnpackXFast(*(_DWORD *)(this + 24));
          v9 = Y16X16::UnpackYFast(*(_DWORD *)(this + 24));
          *(_DWORD *)(this + 24) = Y16X16::PackXYFast(v14, *(__int16 *)(this + 16) + v9);
          IMovingEntity::WalkToXY(a2, *(_DWORD *)(this + 24), 4096);
          *(_BYTE *)(this + 4) = 6;
          IMovingEntity::SetDisplacementCosts(5);
          *(_BYTE *)(this + 5) = -120;
        }
        else
        {
          *(_BYTE *)(this + 4) = 17;
        }
        result = IAnimatedEntity::RegisterForLogicUpdate(1);
      }
      break;
    case 0xE:
      IAnimatedEntity::SetFrame(1);
      IMovingEntity::WalkToXY(a2, *(_DWORD *)(this + 28), 0);
      *(_BYTE *)(this + 4) = 6;
      IMovingEntity::SetDisplacementCosts(5);
      result = (*(int (__thiscall **)(int, COleCmdUI *))(*(_DWORD *)this + 16))(this, a2);
      break;
    case 0x11:
      IMovingEntity::SetDisplacementCosts(0);
      result = IAnimatedEntity::RegisterForLogicUpdate(1);
      break;
    case 0x15:
      IMovingEntity::SetDisplacementCosts(10);
      IAnimatedEntity::SetFrame(*(_BYTE *)(this + 7) - 1);
      result = IAnimatedEntity::RegisterForLogicUpdate(*(char *)(this + 6) / 2);
      break;
    case 0x16:
      if ( ISettlerRole::SourcePileId(this) )
      {
        v4 = ISettlerRole::SourcePileId(this);
        v18 = CMapObjectMgr::Entity(v4);
        v5 = IEntity::Y(v18);
        v12 = v5 - IEntity::Y(a2);
        v6 = IEntity::X(v18);
        v7 = IEntity::X(a2);
        v8 = Grid::DirectionFast((Grid *)(v6 - v7), v12);
        IMovingEntity::SetDirection(a2, v8);
        IMovingEntity::SetDisplacementCosts(10);
        result = IAnimatedEntity::RegisterForLogicUpdate(*(char *)(this + 6) / 2 - 1);
      }
      else
      {
        result = (*(int (__thiscall **)(int, COleCmdUI *, int))(*(_DWORD *)this + 64))(this, a2, -1);
      }
      break;
    case 0x18:
      if ( !*(_WORD *)(this + 32)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\ThiefRole.cpp", 567, "m_uHomeEntityId") == 1 )
      {
        __debugbreak();
      }
      result = 0;
      if ( *(_WORD *)(this + 32) )
      {
        v15 = CVehicleMgr::operator[](*(unsigned __int16 *)(this + 32));
        v11 = IEntity::ID();
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v15 + 128))(v15, v11);
        if ( !IEntity::FlagBits(a2, OnBoard)
          && BBSupportDbgReport(
               2,
               "MapObjects\\Settler\\ThiefRole.cpp",
               571,
               "_pSettler->FlagBits(ENTITY_FLAG_ON_BOARD ) != 0") == 1 )
        {
          __debugbreak();
        }
        result = 0;
      }
      break;
    default:
      result = CTrace::Print("ThiefRole - TakeJob unknown task");
      break;
  }
  return result;
}


// address=[0x1593b40]
// Decompiled from int __thiscall CThiefRole::Init(int this, CPropertySet *a2)
void  CThiefRole::Init(class CSettler *) {
  
  int result; // eax

  if ( IEntity::FlagBits(a2, Offered|Attached)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\ThiefRole.cpp",
         203,
         "!_pSettler->FlagBits( ENTITY_FLAG_ATTACHED | ENTITY_FLAG_OFFERED )") == 1 )
  {
    __debugbreak();
  }
  if ( *(_WORD *)(this + 32)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\ThiefRole.cpp", 204, "!m_uHomeEntityId") == 1 )
  {
    __debugbreak();
  }
  *(_WORD *)(this + 18) = IEntity::ID();
  IEntity::SetFlagBits(a2, VulnerableMask|Selectable);
  CWarMap::AddEntity(a2);
  *(_DWORD *)(this + 60) = 0;
  *(_BYTE *)(this + 64) = 0;
  *(_BYTE *)(this + 11) = *(_BYTE *)(this + 64);
  result = IEntity::PackedXY(a2);
  *(_DWORD *)(this + 28) = result;
  return result;
}


// address=[0x1593c00]
// Decompiled from char __thiscall CThiefRole::CheckGoodInSurrounding(CThiefRole *this, struct CSettler *a2)
bool  CThiefRole::CheckGoodInSurrounding(class CSettler *) {
  
  int v2; // eax
  Grid *v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp-10h] [ebp-38h]
  int v8; // [esp-Ch] [ebp-34h]
  int v9; // [esp-8h] [ebp-30h]
  int v11; // [esp+4h] [ebp-24h]
  int v12; // [esp+8h] [ebp-20h]
  int v13; // [esp+Ch] [ebp-1Ch]
  int v14; // [esp+10h] [ebp-18h]
  int v15; // [esp+14h] [ebp-14h]
  int v16; // [esp+18h] [ebp-10h]
  int v17; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  struct CPile *PilePtr; // [esp+24h] [ebp-4h]

  v14 = IEntity::X(a2);
  v13 = IEntity::Y(a2);
  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v12 = CAlliances::AllianceId(v2);
  for ( i = 0; i < 80; ++i )
  {
    v16 = v14 + CSpiralOffsets::DeltaX(i);
    v17 = v13 + CSpiralOffsets::DeltaY(i);
    if ( (unsigned __int8)CWorldManager::InWorld(v16, v17) )
    {
      v15 = CWorldManager::OwnerId(v16, v17);
      if ( v15 == IEntity::OwnerId((unsigned __int8 *)a2) || CAlliances::AllianceId(v15) != v12 )
      {
        v11 = CWorldManager::ObjectId(v16, v17);
        PilePtr = CPileMgr::GetPilePtr(v11);
        if ( PilePtr )
        {
          if ( (v15 != IEntity::OwnerId((unsigned __int8 *)a2) || CPile::GetRoleType(PilePtr) == 3)
            && !IEntity::FlagBits(PilePtr, (EntityFlag)0x10u) )
          {
            v9 = IEntity::Y(a2);
            v8 = IEntity::X(a2);
            v7 = IEntity::Y(PilePtr);
            v3 = (Grid *)IEntity::X(PilePtr);
            v4 = Grid::Distance(v3, v7, v8, v9);
            if ( (unsigned __int8)CPile::ForceAmountLeaving(PilePtr, v4, 1) )
            {
              v5 = IEntity::ID();
              CPile::AttachAndIncAmountLeaving((unsigned __int16 *)PilePtr, v5, 1, 2);
              *((_DWORD *)this + 6) = Y16X16::PackXYFast(v16, v17);
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}


// address=[0x1593da0]
// Decompiled from bool __thiscall CThiefRole::IsAllyOwner(CThiefRole *this, struct CSettler *a2, int a3)
bool  CThiefRole::IsAllyOwner(class CSettler *,int) {
  
  int v3; // eax
  int v4; // eax
  int v6; // [esp-4h] [ebp-14h]
  int v7; // [esp+4h] [ebp-Ch]

  v3 = IEntity::OwnerId((unsigned __int8 *)a2);
  v7 = CAlliances::AllianceId(v3);
  v6 = Y16X16::UnpackYFast(a3);
  v4 = Y16X16::UnpackXFast(a3);
  return CWorldManager::OwnerId(v4, v6) == v7;
}


// address=[0x1593e10]
// Decompiled from char __thiscall CThiefRole::ConvertEventIntoGoal(int this, CPropertySet *a2, const struct CEntityEvent *a3)
void  CThiefRole::ConvertEventIntoGoal(class CSettler *,class CEntityEvent *) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // esi
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v23; // [esp-Ch] [ebp-44h]
  unsigned int v24; // [esp-8h] [ebp-40h]
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
  int v38; // [esp+Ch] [ebp-2Ch]
  unsigned int v39; // [esp+14h] [ebp-24h]
  int v40; // [esp+18h] [ebp-20h]
  int v41; // [esp+20h] [ebp-18h]
  int v42; // [esp+24h] [ebp-14h]
  _DWORD *v43; // [esp+2Ch] [ebp-Ch]
  int v44; // [esp+30h] [ebp-8h]

  switch ( *((_DWORD *)a3 + 1) )
  {
    case 7:
      v39 = *((_DWORD *)a3 + 3);
      if ( !CMapObjectMgr::ValidEntityId(v39)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\ThiefRole.cpp", 828, "g_pMapObjectMgr->ValidEntityId(iEntityID)") == 1 )
      {
        __debugbreak();
      }
      IEntity::SetFlagBits(a2, Selectable);
      IEntity::ClearFlagBits(a2, OnBoard);
      CSettler::TakeWaitList(a2);
      v30 = IEntity::ID();
      v21 = IEntity::OwnerId((unsigned __int8 *)a2);
      LOBYTE(v3) = (*(int (__thiscall **)(void *, int, int, int, unsigned int))(*(_DWORD *)off_3D7A3D8 + 44))(
                     off_3D7A3D8,
                     21,
                     v21,
                     v30,
                     v39);
      break;
    case 9:
      LOBYTE(v3) = IAnimatedEntity::RegisterForLogicUpdate(1);
      break;
    case 0x11:
      v3 = *((_DWORD *)a3 + 2);
      if ( v3 == 13 )
      {
        if ( ISettlerRole::SourcePileId(this) )
          (*(void (__thiscall **)(int, CPropertySet *, int))(*(_DWORD *)this + 64))(this, a2, -1);
        LOBYTE(v3) = ISelectableSettlerRole::ProcessGoToPosFerry((ISelectableSettlerRole *)this, a2, a3);
        if ( !(_BYTE)v3 )
        {
          v38 = *((_DWORD *)a3 + 3);
          v42 = *((_DWORD *)a3 + 4);
          Y16X16::UnpackXFast(v42);
          Y16X16::UnpackYFast(v42);
          v4 = IEntity::PackedXY(a2);
          if ( CThiefRole::IsAllyOwner((CThiefRole *)this, a2, v4) || !*(_DWORD *)(this + 28) )
            *(_DWORD *)(this + 28) = IEntity::PackedXY(a2);
          v44 = 225;
          if ( (v38 & 4) != 0 )
          {
            *(_DWORD *)(this + 24) = v42;
            if ( *(_BYTE *)(this + 64) )
              v44 = 227;
            else
              v44 = 228;
          }
          else
          {
            *(_DWORD *)(this + 24) = v42;
            if ( CThiefRole::IsAllyOwner((CThiefRole *)this, a2, *(_DWORD *)(this + 24)) )
            {
              if ( *(_BYTE *)(this + 64) )
                v44 = 226;
            }
            else if ( *(_BYTE *)(this + 64) )
            {
              v24 = *(unsigned __int8 *)(this + 64);
              v23 = IEntity::Y(a2);
              v5 = IEntity::X(a2);
              CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v5, v23, v24, 1u);
              *(_BYTE *)(this + 64) = 0;
            }
          }
          v6 = IEntity::Race(a2);
          v7 = CEntityToDoListMgr::SettlerJobList(v6, v44);
          LOBYTE(v3) = (*(int (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v7, v44);
        }
      }
      break;
    case 0x18:
      v31 = IEntity::Type((unsigned __int16 *)a2);
      v8 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v8, v31);
      v43 = (_DWORD *)CVehicleMgr::operator[](*((_DWORD *)a3 + 3));
      v32 = IEntity::ID();
      v9 = IEntity::ObjType((unsigned __int8 *)a2);
      v41 = (*(int (__thiscall **)(_DWORD *, int, int))(*v43 + 140))(v43, v9, v32);
      if ( v41 && IEntity::FlagBits(v43, (EntityFlag)&loc_3000000) )
      {
        ISettlerRole::NewDestination((ISettlerRole *)this, a2, v41, 0);
        v10 = IEntity::ID();
        (*(void (__thiscall **)(_DWORD *, int))(*v43 + 164))(v43, v10);
        IEntity::ClearFlagBits(a2, Selectable|Selected);
        v11 = IEntity::ID();
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)g_pGroupMgr + 28))(g_pGroupMgr, v11);
        v33 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v25 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v12 = IEntity::Race(a2);
        v13 = CEntityToDoListMgr::SettlerJobList(v12, v25);
        (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v13, v33);
        v14 = IEntity::OwnerId((unsigned __int8 *)a2);
        if ( v14 == CPlayerManager::GetLocalPlayerId() )
        {
          v15 = IEntity::ID();
          CInputProcessor::DeSelectEntity(&g_cInputProcessor, v15);
        }
        v34 = *(unsigned __int16 *)(this + 32);
        v26 = IEntity::ID();
        v16 = IEntity::OwnerId((unsigned __int8 *)a2);
        LOBYTE(v3) = (*(int (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(
                       off_3D7A3D8,
                       18,
                       v16,
                       v26,
                       v34);
      }
      else
      {
        IEntity::SetFlagBits(a2, Selectable);
        v35 = IEntity::Type((unsigned __int16 *)a2);
        v27 = IEntity::Type((unsigned __int16 *)a2);
        v17 = IEntity::Race(a2);
        v18 = CEntityToDoListMgr::SettlerJobList(v17, v27);
        LOBYTE(v3) = (*(int (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v18, v35);
      }
      break;
    case 0x19:
      v40 = *((_DWORD *)a3 + 4);
      v36 = Y16X16::UnpackYFast(v40);
      v28 = Y16X16::UnpackXFast(v40);
      v19 = IEntity::ID();
      CSettlerMgr::SearchSpaceForSettler((CSettlerMgr *)g_cSettlerMgr, v19, v28, v36);
      CWarMap::AddEntity(a2);
      IEntity::SetFlagBits(a2, Selectable|Visible);
      IEntity::ClearFlagBits(a2, OnBoard);
      CSettler::TakeWaitList(a2);
      v37 = *(unsigned __int16 *)(this + 32);
      v29 = IEntity::ID();
      v20 = IEntity::OwnerId((unsigned __int8 *)a2);
      LOBYTE(v3) = (*(int (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(
                     off_3D7A3D8,
                     21,
                     v20,
                     v29,
                     v37);
      break;
    default:
      v3 = IEntity::FlagBits(a2, Registered);
      if ( !v3 )
      {
        CTrace::Print("ConvertEventIntoGoal ThiefRole - unknown event %u", *((_DWORD *)a3 + 1));
        LOBYTE(v3) = IAnimatedEntity::RegisterForLogicUpdate(1);
      }
      break;
  }
  return v3;
}


