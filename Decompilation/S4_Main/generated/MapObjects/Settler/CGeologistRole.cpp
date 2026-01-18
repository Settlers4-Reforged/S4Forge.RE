#include "CGeologistRole.h"

// Definitions for class CGeologistRole

// address=[0x1400cc0]
// Decompiled from int __cdecl CGeologistRole::New(int a1)
class CPersistence * __cdecl CGeologistRole::New(std::istream & a1) {
  
  if ( operator new(0x54u) )
    return CGeologistRole::CGeologistRole(a1);
  else
    return 0;
}


// address=[0x15720a0]
// Decompiled from int __thiscall CGeologistRole::InitWalking(CGeologistRole *this, struct CSettler *a2)
class CWalking *  CGeologistRole::InitWalking(class CSettler * a2) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = CWalking::Create(0, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x15720e0]
// Decompiled from int __thiscall CGeologistRole::LogicUpdateJob(CGeologistRole *this, struct CSettler *a2)
void  CGeologistRole::LogicUpdateJob(class CSettler * a2) {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-10h]
  int v4; // [esp+4h] [ebp-Ch]

  switch ( *((_BYTE *)this + 4) )
  {
    case 6:
      IMovingEntity::SetDistance(a2, 0);
      return (*(int (__thiscall **)(CGeologistRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
    case 0xD:
      if ( debug )
      {
        if ( DEBUG_FLAGS[dword_41520CC] )
          BBSupportTracePrint(0, "LogicUpdateJob RESOURCE_GATHERING");
      }
      goto LABEL_18;
    case 0x10:
      if ( debug && DEBUG_FLAGS[dword_41520CC] )
        BBSupportTracePrint(0, "LogicUpdateJob WORK");
      if ( *((_DWORD *)this + 6) )
      {
        CGeologistRole::SetSign(this, a2);
        v3 = Y16X16::UnpackXFast(*((_DWORD *)this + 6));
        v4 = Y16X16::UnpackYFast(*((_DWORD *)this + 6));
        CWorldManager::ClearFlagBits(v3, v4, 32);
        CWorldManager::ClearFlagBits(v3, v4 - 1, 32);
        *((_DWORD *)this + 6) = 0;
      }
      goto LABEL_18;
    case 0x1F:
      if ( debug && DEBUG_FLAGS[dword_41520CC] )
        BBSupportTracePrint(0, "LogicUpdateJob SEARCH");
LABEL_18:
      result = (*(int (__thiscall **)(CGeologistRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
      break;
    default:
      result = BBSupportTracePrintF(0, "Geogolist role wrong task in LogicUpdate");
      break;
  }
  return result;
}


// address=[0x15722a0]
// Decompiled from int __thiscall CGeologistRole::PostLoadInit(int this, CPropertySet *a2)
void  CGeologistRole::PostLoadInit(class CSettler * a2) {
  
  int result; // eax
  int v4; // [esp+0h] [ebp-4h]

  CWarMap::AddEntity(a2);
  if ( std::list<CEntityTask>::size((void *)(this + 48)) )
    IMovingEntity::SetToDoList(a2, this + 48);
  IMovingEntity::ResetToDoList(this);
  while ( 1 )
  {
    result = *(unsigned __int8 *)(v4 + 12);
    if ( !*(_BYTE *)(v4 + 12) )
      break;
    IMovingEntity::IncToDoListIter(a2);
    --*(_BYTE *)(v4 + 12);
  }
  *(_DWORD *)(v4 + 80) = 193;
  return result;
}


// address=[0x1572310]
// Decompiled from _DWORD *__thiscall CGeologistRole::CGeologistRole(_DWORD *this, int a2)
 CGeologistRole::CGeologistRole(std::istream & a2) {
  
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
  *v8 = &CGeologistRole::_vftable_;
  std::list<CEntityTask>::list<CEntityTask>(v8 + 12);
  LOBYTE(v9) = 1;
  operator^<unsigned int>(a2, &v5);
  v4[1] = v5;
  if ( v5 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CGeologistRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned int>(a2, v4);
  for ( i = 0; i < v4[0]; ++i )
  {
    v2 = CEntityTask::Load(a2);
    std::list<CEntityTask>::push_back(v2);
  }
  operator^<unsigned char>(a2, v8 + 3);
  operator^<int>(a2, (int)(v8 + 15));
  operator^<int>(a2, (int)(v8 + 16));
  operator^<int>(a2, (int)(v8 + 17));
  operator^<int>(a2, (int)(v8 + 18));
  operator^<int>(a2, (int)(v8 + 19));
  v9 = -1;
  return v8;
}


// address=[0x1572490]
// Decompiled from int __thiscall CGeologistRole::Store(int *this, struct std::ostream *a2)
void  CGeologistRole::Store(std::ostream & a2) {
  
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
  v19 = std::list<CEntityTask>::size(v21 + 12);
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
  if ( v2 >= std::list<CEntityTask>::size(v21 + 12) )
    LOBYTE(v25) = 0;
  operator^<unsigned char>(a2, (int)&v25);
  operator^<int>((int)a2, v21 + 15);
  operator^<int>((int)a2, v21 + 16);
  operator^<int>((int)a2, v21 + 17);
  operator^<int>((int)a2, v21 + 18);
  return operator^<int>((int)a2, v21 + 19);
}


// address=[0x15744d0]
// Decompiled from int __thiscall CGeologistRole::ClassID(CGeologistRole *this)
unsigned long  CGeologistRole::ClassID(void)const {
  
  return CGeologistRole::m_iClassID;
}


// address=[0x15744f0]
// Decompiled from int __thiscall CGeologistRole::GetSettlerRole(CGeologistRole *this)
int  CGeologistRole::GetSettlerRole(void)const {
  
  return 12;
}


// address=[0x1588680]
// Decompiled from int __cdecl CGeologistRole::Load(int a1)
class CGeologistRole * __cdecl CGeologistRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CGeologistRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bec8]
// [Decompilation failed for static unsigned long CGeologistRole::m_iClassID]

// address=[0x1572700]
// Decompiled from CGeologistRole *__thiscall CGeologistRole::CGeologistRole(CGeologistRole *this)
 CGeologistRole::CGeologistRole(void) {
  
  ISelectableSettlerRole::ISelectableSettlerRole(this);
  *(_DWORD *)this = &CGeologistRole::_vftable_;
  std::list<CEntityTask>::list<CEntityTask>((char *)this + 48);
  return this;
}


// address=[0x1572770]
// Decompiled from void __thiscall CGeologistRole::~CGeologistRole(CGeologistRole *this)
 CGeologistRole::~CGeologistRole(void) {
  
  int v1; // [esp+4h] [ebp-1Ch]
  int v2; // [esp+8h] [ebp-18h]
  CPropertySet *v3; // [esp+Ch] [ebp-14h]

  *(_DWORD *)this = &CGeologistRole::_vftable_;
  v3 = (CPropertySet *)CSettlerMgr::operator[](*((unsigned __int16 *)this + 9));
  if ( !IEntity::FlagBits(v3, EntityFlag_OnBoard) )
    CWarMap::RemoveEntity(v3);
  if ( *((_DWORD *)this + 6) )
  {
    v1 = Y16X16::UnpackXFast(*((_DWORD *)this + 6));
    v2 = Y16X16::UnpackYFast(*((_DWORD *)this + 6));
    CWorldManager::ClearFlagBits(v1, v2, 32);
    CWorldManager::ClearFlagBits(v1, v2 - 1, 32);
    *((_DWORD *)this + 6) = 0;
  }
  std::list<CEntityTask>::~list<CEntityTask>();
  ISelectableSettlerRole::~ISelectableSettlerRole(this);
}


// address=[0x1572860]
// Decompiled from int __thiscall CGeologistRole::GetNextJob(CGeologistRole *this, struct CSettler *a2)
void  CGeologistRole::GetNextJob(class CSettler * a2) {
  
  CGeologistRole *v3; // [esp+0h] [ebp-4h]

  v3 = this;
  IMovingEntity::IncToDoListIter(a2);
  if ( IMovingEntity::IsEndIter(a2) )
    IMovingEntity::ResetToDoList(v3);
  return (*(int (__thiscall **)(CGeologistRole *, struct CSettler *))(*(_DWORD *)v3 + 40))(v3, a2);
}


// address=[0x15728a0]
// Decompiled from void __thiscall CGeologistRole::TakeJob(int this, COleCmdUI *a2)
void  CGeologistRole::TakeJob(class CSettler * a2) {
  
  const struct CEntityTask *ActualTask; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // [esp-Ch] [ebp-20h]
  int v7; // [esp-Ch] [ebp-20h]
  int v8; // [esp+0h] [ebp-14h]
  int v9; // [esp+0h] [ebp-14h]
  int v10; // [esp+4h] [ebp-10h]
  int v11; // [esp+8h] [ebp-Ch]

  if ( !(unsigned __int8)ISelectableSettlerRole::TakeCommonJob(a2) )
  {
    ActualTask = (const struct CEntityTask *)IMovingEntity::GetActualTask(a2);
    ISettlerRole::InitCommonTaskValues((ISettlerRole *)this, a2, ActualTask);
    switch ( *(_BYTE *)(this + 4) )
    {
      case 7:
        if ( debug && DEBUG_FLAGS[dword_41520CC] )
          BBSupportTracePrint(0, "TakeJob GO");
        IAnimatedEntity::SetFrame(1);
        if ( *(__int16 *)(this + 14) > 0 || *(__int16 *)(this + 16) > 0 )
          ISettlerRole::NewDestination((ISettlerRole *)this, a2, *(__int16 *)(this + 14), *(__int16 *)(this + 16), 0);
        goto LABEL_27;
      case 0xA:
        if ( debug && DEBUG_FLAGS[dword_41520CC] )
          BBSupportTracePrint(0, "TakeJob GO");
        IAnimatedEntity::SetFrame(1);
        if ( *(__int16 *)(this + 14) > 0 || *(__int16 *)(this + 16) > 0 )
          ISettlerRole::NewDestination((ISettlerRole *)this, a2, *(__int16 *)(this + 14), *(__int16 *)(this + 16), 0);
LABEL_27:
        IMovingEntity::WalkToXY(a2, *(_DWORD *)(this + 24), 0);
        *(_BYTE *)(this + 4) = 6;
        IMovingEntity::SetDisplacementCosts(5);
        (*(void (__thiscall **)(int, COleCmdUI *))(*(_DWORD *)this + 16))(this, a2);
        return;
      case 0xD:
        if ( debug && DEBUG_FLAGS[dword_41520CC] )
          BBSupportTracePrint(0, "TakeJob SEARCH");
        if ( CGeologistRole::SearchPosition((CGeologistRole *)this, a2) )
        {
          (*(void (__thiscall **)(int, COleCmdUI *))(*(_DWORD *)this + 36))(this, a2);
        }
        else
        {
          *(_DWORD *)(this + 72) += 64;
          if ( (int)++*(_DWORD *)(this + 68) <= 56 )
          {
            IAnimatedEntity::SetFrame(0);
            IMovingEntity::ResetToDoList(v8);
            IMovingEntity::IncToDoListIter(a2);
            IMovingEntity::IncToDoListIter(a2);
            (*(void (__thiscall **)(int, COleCmdUI *))(*(_DWORD *)this + 36))(this, a2);
          }
          else
          {
            CGeologistRole::WorkIsDone((CGeologistRole *)this, a2);
          }
        }
        return;
      case 0x10:
        if ( debug && DEBUG_FLAGS[dword_41520CC] )
          BBSupportTracePrint(0, "TakeJob WORK");
        goto LABEL_12;
      case 0x11:
        IMovingEntity::SetDisplacementCosts(0);
        IAnimatedEntity::RegisterForLogicUpdate(1);
        return;
      case 0x18:
        v9 = CVehicleMgr::operator[](*(unsigned __int16 *)(this + 32));
        v5 = IEntity::ID();
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 128))(v9, v5);
        return;
      case 0x1F:
        if ( debug && DEBUG_FLAGS[dword_41520CC] )
          BBSupportTracePrint(0, "TakeJob SEARCH");
        if ( (int)++*(_DWORD *)(this + 76) > 5 )
          *(_DWORD *)(this + 76) = 0;
        v6 = IEntity::Y(a2);
        v3 = IEntity::X(a2);
        if ( CGeologistRole::CheckPosition((CGeologistRole *)this, v3, v6, 0, 1)
          && (v7 = IEntity::Y(a2) - 1,
              v4 = IEntity::X(a2),
              CGeologistRole::CheckPosition((CGeologistRole *)this, v4, v7, 1, 1)) )
        {
LABEL_12:
          IMovingEntity::SetDisplacementCosts(10);
          IAnimatedEntity::RegisterForLogicUpdate(*(char *)(this + 6));
        }
        else
        {
          if ( *(_DWORD *)(this + 24) )
          {
            v10 = Y16X16::UnpackXFast(*(_DWORD *)(this + 24));
            v11 = Y16X16::UnpackYFast(*(_DWORD *)(this + 24));
            CWorldManager::ClearFlagBits(v10, v11, 32);
            CWorldManager::ClearFlagBits(v10, v11 - 1, 32);
            *(_DWORD *)(this + 24) = 0;
          }
          IMovingEntity::IncToDoListIter(a2);
          (*(void (__thiscall **)(int, COleCmdUI *))(*(_DWORD *)this + 36))(this, a2);
        }
        break;
      default:
        BBSupportTracePrintF(0, "Geologist TakeJob wrong task");
        break;
    }
  }
}


// address=[0x1572d10]
// Decompiled from int __thiscall CGeologistRole::Init(int this, CPropertySet *a2)
void  CGeologistRole::Init(class CSettler * a2) {
  
  int result; // eax

  if ( IEntity::FlagBits(a2, 0x60)
    && BBSupportDbgReport(
         2,
         (int)"MapObjects\\Settler\\GeologistRole.cpp",
         239,
         (int)"!_pSettler->FlagBits( ENTITY_FLAG_ATTACHED | ENTITY_FLAG_OFFERED )") == 1 )
  {
    __debugbreak();
  }
  if ( *(_WORD *)(this + 32)
    && BBSupportDbgReport(2, (int)"MapObjects\\Settler\\GeologistRole.cpp", 240, (int)"!m_uHomeEntityId") == 1 )
  {
    __debugbreak();
  }
  *(_WORD *)(this + 18) = IEntity::ID();
  *(_DWORD *)(this + 24) = 0;
  IEntity::SetFlagBits(a2, 204800);
  CWarMap::AddEntity(a2);
  *(_DWORD *)(this + 60) = 0;
  *(_DWORD *)(this + 64) = 0;
  *(_DWORD *)(this + 24) = 0;
  *(_DWORD *)(this + 68) = 0;
  *(_DWORD *)(this + 72) = 0;
  result = this;
  *(_DWORD *)(this + 76) = 0;
  *(_DWORD *)(this + 80) = 193;
  return result;
}


// address=[0x1572df0]
// Decompiled from int __thiscall CGeologistRole::WorkIsDone(CGeologistRole *this, struct CSettler *a2)
void  CGeologistRole::WorkIsDone(class CSettler * a2) {
  
  *((_BYTE *)this + 4) = 17;
  return IAnimatedEntity::RegisterForLogicUpdate(1);
}


// address=[0x1572e10]
// Decompiled from char __thiscall CGeologistRole::ConvertEventIntoGoal(int this, CPropertySet *a2, const struct CEntityEvent *a3)
void  CGeologistRole::ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v23; // [esp-8h] [ebp-48h]
  int v24; // [esp-8h] [ebp-48h]
  int v25; // [esp-8h] [ebp-48h]
  int v26; // [esp-8h] [ebp-48h]
  int v27; // [esp-8h] [ebp-48h]
  int v28; // [esp-8h] [ebp-48h]
  int v29; // [esp-8h] [ebp-48h]
  int v30; // [esp-4h] [ebp-44h]
  int v31; // [esp-4h] [ebp-44h]
  int v32; // [esp-4h] [ebp-44h]
  int v33; // [esp-4h] [ebp-44h]
  int v34; // [esp-4h] [ebp-44h]
  int v35; // [esp-4h] [ebp-44h]
  int v36; // [esp-4h] [ebp-44h]
  int v37; // [esp+4h] [ebp-3Ch]
  int v38; // [esp+8h] [ebp-38h]
  int v39; // [esp+10h] [ebp-30h]
  int v40; // [esp+18h] [ebp-28h]
  int v41; // [esp+1Ch] [ebp-24h]
  int v42; // [esp+20h] [ebp-20h]
  int v43; // [esp+24h] [ebp-1Ch]
  int v44; // [esp+28h] [ebp-18h]
  int v45; // [esp+2Ch] [ebp-14h]
  int v46; // [esp+30h] [ebp-10h]
  _DWORD *v47; // [esp+38h] [ebp-8h]

  *(_DWORD *)(this + 80) = 193;
  switch ( *((_DWORD *)a3 + 1) )
  {
    case 7:
      v37 = *((_DWORD *)a3 + 3);
      IEntity::SetFlagBits(a2, EntityFlag_Selectable);
      IEntity::ClearFlagBits(a2, EntityFlag_OnBoard);
      v36 = IEntity::Type((unsigned __int16 *)a2);
      v28 = IEntity::Type((unsigned __int16 *)a2);
      v19 = IEntity::Race(a2);
      v20 = CEntityToDoListMgr::SettlerJobList(v19, v28);
      (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v20, v36);
      *(_BYTE *)(this + 4) = 27;
      v29 = IEntity::ID();
      v21 = IEntity::OwnerId((unsigned __int8 *)a2);
      LOBYTE(v3) = (*(int (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)g_pAI + 44))(g_pAI, 21, v21, v29, v37);
      break;
    case 0x11:
      LOBYTE(v3) = this;
      if ( *(_DWORD *)(this + 24) )
      {
        v44 = Y16X16::UnpackXFast(*(_DWORD *)(this + 24));
        v45 = Y16X16::UnpackYFast(*(_DWORD *)(this + 24));
        CWorldManager::ClearFlagBits(v44, v45, 32);
        CWorldManager::ClearFlagBits(v44, v45 - 1, 32);
        LOBYTE(v3) = this;
        *(_DWORD *)(this + 24) = 0;
      }
      if ( *((_DWORD *)a3 + 2) == 13 )
      {
        LOBYTE(v3) = ISelectableSettlerRole::ProcessGoToPosFerry((ISelectableSettlerRole *)this, a2, a3);
        if ( !(_BYTE)v3 )
        {
          v38 = *((_DWORD *)a3 + 3);
          v43 = *((_DWORD *)a3 + 4);
          v41 = Y16X16::UnpackXFast(v43);
          v42 = Y16X16::UnpackYFast(v43);
          if ( (v38 & 4) != 0 )
          {
            v46 = 178;
          }
          else
          {
            *(_DWORD *)(this + 72) = 0;
            *(_DWORD *)(this + 68) = 0;
            *(_DWORD *)(this + 60) = v41;
            *(_DWORD *)(this + 64) = v42;
            v46 = 177;
          }
          ISettlerRole::NewDestination((ISettlerRole *)this, a2, v41, v42, 0);
          v4 = IEntity::Race(a2);
          v5 = CEntityToDoListMgr::SettlerJobList(v4, v46);
          LOBYTE(v3) = (*(int (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v5, v46);
        }
      }
      break;
    case 0x18:
      v30 = IEntity::Type((unsigned __int16 *)a2);
      v6 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v6, v30);
      v47 = (_DWORD *)CVehicleMgr::operator[](*((_DWORD *)a3 + 3));
      v7 = IEntity::ID();
      v40 = (*(int (__thiscall **)(_DWORD *, int, int))(*v47 + 140))(v47, 1, v7);
      if ( v40 && IEntity::FlagBits(v47, (EntityFlag)&loc_3000000) )
      {
        ISettlerRole::NewDestination((ISettlerRole *)this, a2, v40, 0);
        v31 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v23 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v8 = IEntity::Race(a2);
        v9 = CEntityToDoListMgr::SettlerJobList(v8, v23);
        (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v9, v31);
        v10 = IEntity::OwnerId((unsigned __int8 *)a2);
        if ( v10 == CPlayerManager::GetLocalPlayerId() )
        {
          v11 = IEntity::ID();
          CInputProcessor::DeSelectEntity(&g_cInputProcessor, v11);
        }
        v12 = IEntity::ID();
        (*(void (__thiscall **)(_DWORD *, int))(*v47 + 164))(v47, v12);
        IEntity::ClearFlagBits(a2, EntityFlag_Selectable|EntityFlag_Selected);
        v13 = IEntity::ID();
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)g_pGroupMgr + 28))(g_pGroupMgr, v13);
        v32 = *(unsigned __int16 *)(this + 32);
        v24 = IEntity::ID();
        v14 = IEntity::OwnerId((unsigned __int8 *)a2);
        LOBYTE(v3) = (*(int (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)g_pAI + 44))(
                       g_pAI,
                       18,
                       v14,
                       v24,
                       v32);
      }
      else
      {
        IEntity::SetFlagBits(a2, EntityFlag_Selectable);
        v33 = IEntity::Type((unsigned __int16 *)a2);
        v25 = IEntity::Type((unsigned __int16 *)a2);
        v15 = IEntity::Race(a2);
        v16 = CEntityToDoListMgr::SettlerJobList(v15, v25);
        LOBYTE(v3) = (*(int (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v16, v33);
      }
      break;
    case 0x19:
      v39 = *((_DWORD *)a3 + 4);
      v34 = Y16X16::UnpackYFast(v39);
      v26 = Y16X16::UnpackXFast(v39);
      v17 = IEntity::ID();
      CSettlerMgr::SearchSpaceForSettler((CSettlerMgr *)g_cSettlerMgr, v17, v26, v34);
      CWarMap::AddEntity(a2);
      IEntity::SetFlagBits(a2, EntityFlag_Selectable|EntityFlag_Visible);
      IEntity::ClearFlagBits(a2, EntityFlag_OnBoard);
      *(_BYTE *)(this + 4) = 27;
      v35 = *(unsigned __int16 *)(this + 32);
      v27 = IEntity::ID();
      v18 = IEntity::OwnerId((unsigned __int8 *)a2);
      LOBYTE(v3) = (*(int (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)g_pAI + 44))(g_pAI, 21, v18, v27, v35);
      *(_WORD *)(this + 32) = 0;
      break;
    default:
      v3 = IEntity::FlagBits(a2, EntityFlag_Registered);
      if ( !v3 )
      {
        BBSupportTracePrintF(0, "ConvertEventIntoGoal GeologistRole - unknown event %u", *((_DWORD *)a3 + 1));
        LOBYTE(v3) = IAnimatedEntity::RegisterForLogicUpdate(1);
      }
      break;
  }
  return v3;
}


// address=[0x15732d0]
// Decompiled from char __thiscall CGeologistRole::SearchPosition(CGeologistRole *this, struct CSettler *a2)
bool  CGeologistRole::SearchPosition(class CSettler * a2) {
  
  int v3; // [esp+4h] [ebp-3Ch]
  int v4; // [esp+8h] [ebp-38h]
  unsigned int v5; // [esp+10h] [ebp-30h]
  int v6; // [esp+14h] [ebp-2Ch]
  int v7; // [esp+18h] [ebp-28h]
  int v8; // [esp+1Ch] [ebp-24h]
  int v9; // [esp+20h] [ebp-20h]
  unsigned int v10; // [esp+20h] [ebp-20h]
  int v11; // [esp+24h] [ebp-1Ch]
  int v12; // [esp+28h] [ebp-18h]
  int v13; // [esp+2Ch] [ebp-14h]
  int v14; // [esp+30h] [ebp-10h]
  int v15; // [esp+34h] [ebp-Ch]
  int i; // [esp+38h] [ebp-8h]

  v11 = -1;
  v8 = -1;
  v5 = -1;
  v7 = 0;
  v14 = IEntity::X(a2);
  v15 = IEntity::Y(a2);
  v6 = CWorldManager::SectorId(v14, v15);
  if ( CWorldManager::SectorId(v14, v15) != v6 )
    return 0;
  if ( CWorldManager::SectorId(v14, v15 - 1) != v6 )
    return 0;
  for ( i = *((_DWORD *)this + 18); i < *((_DWORD *)this + 18) + 64; ++i )
  {
    v13 = v14 + CSpiralOffsets::DeltaX(i);
    v12 = v15 + CSpiralOffsets::DeltaY(i);
    if ( CGeologistRole::CheckPosition(this, v13, v12, 0, 0) && CGeologistRole::CheckPosition(this, v13, v12 - 1, 1, 0) )
    {
      ++v7;
      v9 = CSpiralOffsets::PseudoDistanceSquareEx(v13 - *((_DWORD *)this + 15), v12 - *((_DWORD *)this + 16));
      v10 = v9 + 3 * CSpiralOffsets::PseudoDistanceSquareEx(v13 - v14, v12 - v15);
      if ( v10 < v5 )
      {
        v5 = v10;
        v11 = v13;
        v8 = v12;
      }
    }
    if ( v7 > 31 )
      break;
  }
  if ( v11 == -1 )
    return 0;
  if ( *((_DWORD *)this + 6) )
  {
    v3 = Y16X16::UnpackXFast(*((_DWORD *)this + 6));
    v4 = Y16X16::UnpackYFast(*((_DWORD *)this + 6));
    CWorldManager::ClearFlagBits(v3, v4, 32);
    CWorldManager::ClearFlagBits(v3, v4 - 1, 32);
    *((_DWORD *)this + 6) = 0;
  }
  CWorldManager::SetFlagBits(v11, v8, 32);
  CWorldManager::SetFlagBits(v11, v8 - 1, 32);
  *((_DWORD *)this + 6) = Y16X16::PackXYFast(v11, v8);
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 17) = 0;
  return 1;
}


// address=[0x1573530]
// Decompiled from char __thiscall CGeologistRole::CheckResource(CGeologistRole *this, _DWORD *a2)
bool  CGeologistRole::CheckResource(class CSettler * a2) {
  
  int v4; // [esp+4h] [ebp-8h]
  int v5; // [esp+8h] [ebp-4h]

  v4 = IEntity::X(a2);
  v5 = IEntity::Y(a2) - 1;
  if ( CWorldManager::FlagBits(v4, v5, 0x59u)
    || (CWorldManager::Ground(v4, v5) & 0xF0) != 0x20
    || CWorldManager::ObjectId(v4, v5)
    || CWorldManager::ObjectId(v4 - 1, v5)
    || CWorldManager::ObjectId(v4 + 1, v5)
    || CWorldManager::ObjectId(v4, v5 - 1)
    || CWorldManager::ObjectId(v4, v5 + 1)
    || CWorldManager::ObjectId(v4 - 1, v5 - 1)
    || CWorldManager::ObjectId(v4 + 1, v5 + 1) )
  {
    if ( debug && DEBUG_FLAGS[dword_41520CC] )
      BBSupportTracePrint(0, "CheckResource... NO");
    CGeologistRole::SearchPosition(this, (struct CSettler *)a2);
    return 0;
  }
  else
  {
    if ( !debug )
      return 1;
    if ( DEBUG_FLAGS[dword_41520CC] )
      BBSupportTracePrint(0, "CheckResource... YES");
    return 1;
  }
}


// address=[0x15736b0]
// Decompiled from char __thiscall CGeologistRole::SetSign(CGeologistRole *this, struct CSettler *a2)
void  CGeologistRole::SetSign(class CSettler * a2) {
  
  int v2; // eax
  int v3; // eax
  int LocalPlayerId; // eax
  int v5; // esi
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
  int v18; // [esp+8h] [ebp-48h]
  int v19; // [esp+Ch] [ebp-44h]
  int v20; // [esp+10h] [ebp-40h]
  int v21; // [esp+14h] [ebp-3Ch]
  int v22; // [esp+18h] [ebp-38h]
  unsigned __int8 *v23; // [esp+1Ch] [ebp-34h]
  int v24; // [esp+20h] [ebp-30h]
  int v25; // [esp+24h] [ebp-2Ch]
  int v26; // [esp+2Ch] [ebp-24h]
  int v27; // [esp+38h] [ebp-18h]
  int v28; // [esp+3Ch] [ebp-14h]
  int v29; // [esp+40h] [ebp-10h]
  int v30; // [esp+44h] [ebp-Ch]
  int v31; // [esp+48h] [ebp-8h]
  int v32; // [esp+4Ch] [ebp-4h]
  int v33; // [esp+4Ch] [ebp-4h]

  v2 = IEntity::WorldIdx();
  v24 = CWorldManager::X(v2);
  v3 = IEntity::WorldIdx();
  v25 = CWorldManager::Y(v3) - 1;
  v22 = CWorldManager::ResourceType(v24, v25);
  v32 = CWorldManager::ResourceAmount(v24, v25, v22);
  if ( v32 > 0 )
    --v32;
  v33 = v32 / 5;
  v29 = 193;
  if ( v33 >= 3 && BBSupportDbgReport(2, "MapObjects\\Settler\\GeologistRole.cpp", 1062, "iAmountClass < 3") == 1 )
    __debugbreak();
  switch ( v22 )
  {
    case 16:
      v29 = 194;
      v28 = v33 + 194;
      LOBYTE(LocalPlayerId) = CDecoObjMgr::AddDecoObj((CDecoObjMgr *)&g_cDecoObjMgr, v24, v25, v33 + 194, 0, 1);
      break;
    case 32:
      v29 = 200;
      v28 = v33 + 200;
      LOBYTE(LocalPlayerId) = CDecoObjMgr::AddDecoObj((CDecoObjMgr *)&g_cDecoObjMgr, v24, v25, v33 + 200, 0, 1);
      break;
    case 48:
      v29 = 197;
      v28 = v33 + 197;
      LOBYTE(LocalPlayerId) = CDecoObjMgr::AddDecoObj((CDecoObjMgr *)&g_cDecoObjMgr, v24, v25, v33 + 197, 0, 1);
      break;
    case 64:
      v29 = 206;
      v28 = v33 + 206;
      LOBYTE(LocalPlayerId) = CDecoObjMgr::AddDecoObj((CDecoObjMgr *)&g_cDecoObjMgr, v24, v25, v33 + 206, 0, 1);
      break;
    case 80:
      v29 = 203;
      v28 = v33 + 203;
      LOBYTE(LocalPlayerId) = CDecoObjMgr::AddDecoObj((CDecoObjMgr *)&g_cDecoObjMgr, v24, v25, v33 + 203, 0, 1);
      break;
    default:
      v28 = 193;
      LOBYTE(LocalPlayerId) = CDecoObjMgr::AddDecoObj((CDecoObjMgr *)&g_cDecoObjMgr, v24, v25, 193, 0, 1);
      break;
  }
  if ( v28 == 193 )
    return LocalPlayerId;
  v27 = 1;
  v26 = 0;
  v30 = IEntity::X(a2);
  v31 = IEntity::Y(a2);
  if ( v33 == 2 )
  {
    v21 = CLogic::Effects((DWORD *)g_pLogic);
    (*(void (__thiscall **)(int, _DWORD, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v21 + 16))(
      v21,
      0,
      38,
      v30,
      v31,
      0,
      0,
      0);
  }
  while ( (int)CSpiralOffsets::Radius(v27) < 4 )
  {
    v19 = v30 + CSpiralOffsets::DeltaX(v27);
    v20 = v31 + CSpiralOffsets::DeltaY(v27);
    if ( (unsigned __int8)CWorldManager::InWorld(v19, v20) )
    {
      v18 = CWorldManager::ObjectId(v19, v20);
      if ( v18 )
      {
        v23 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(v18);
        if ( IEntity::ObjType(v23) == 32
          && IEntity::Type((unsigned __int16 *)v23) >= v29
          && IEntity::Type((unsigned __int16 *)v23) <= v29 + 3 )
        {
          ++v26;
        }
      }
      ++v27;
    }
  }
  v5 = IEntity::OwnerId((unsigned __int8 *)a2);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  if ( v5 != LocalPlayerId )
    return LocalPlayerId;
  if ( v26 < 5 )
  {
    if ( v26 )
    {
      LOBYTE(LocalPlayerId) = (_BYTE)this;
      if ( v29 != *((_DWORD *)this + 20) )
      {
        *((_DWORD *)this + 20) = v29;
        LOBYTE(LocalPlayerId) = v29 + 62;
        switch ( v29 )
        {
          case 194:
            v11 = IEntity::OwnerId((unsigned __int8 *)a2);
            LOBYTE(LocalPlayerId) = CTextMsgHandler::AddWarningMsg(1919, v11, v30, v31);
            break;
          case 197:
            v13 = IEntity::OwnerId((unsigned __int8 *)a2);
            LOBYTE(LocalPlayerId) = CTextMsgHandler::AddWarningMsg(1920, v13, v30, v31);
            break;
          case 200:
            v12 = IEntity::OwnerId((unsigned __int8 *)a2);
            LOBYTE(LocalPlayerId) = CTextMsgHandler::AddWarningMsg(1921, v12, v30, v31);
            break;
          case 203:
            v15 = IEntity::OwnerId((unsigned __int8 *)a2);
            LOBYTE(LocalPlayerId) = CTextMsgHandler::AddWarningMsg(1922, v15, v30, v31);
            break;
          case 206:
            v14 = IEntity::OwnerId((unsigned __int8 *)a2);
            LOBYTE(LocalPlayerId) = CTextMsgHandler::AddWarningMsg(1923, v14, v30, v31);
            break;
          default:
            return LocalPlayerId;
        }
      }
    }
  }
  else
  {
    LOBYTE(LocalPlayerId) = v29 + 62;
    switch ( v29 )
    {
      case 194:
        v6 = IEntity::OwnerId((unsigned __int8 *)a2);
        LOBYTE(LocalPlayerId) = CTextMsgHandler::AddWarningMsg(1935, v6, v30, v31);
        break;
      case 197:
        v8 = IEntity::OwnerId((unsigned __int8 *)a2);
        LOBYTE(LocalPlayerId) = CTextMsgHandler::AddWarningMsg(1936, v8, v30, v31);
        break;
      case 200:
        v7 = IEntity::OwnerId((unsigned __int8 *)a2);
        LOBYTE(LocalPlayerId) = CTextMsgHandler::AddWarningMsg(1937, v7, v30, v31);
        break;
      case 203:
        v10 = IEntity::OwnerId((unsigned __int8 *)a2);
        LOBYTE(LocalPlayerId) = CTextMsgHandler::AddWarningMsg(1938, v10, v30, v31);
        break;
      case 206:
        v9 = IEntity::OwnerId((unsigned __int8 *)a2);
        LOBYTE(LocalPlayerId) = CTextMsgHandler::AddWarningMsg(1939, v9, v30, v31);
        break;
      default:
        return LocalPlayerId;
    }
  }
  return LocalPlayerId;
}


// address=[0x1573bc0]
// Decompiled from bool __thiscall CGeologistRole::CheckPosition(CGeologistRole *this, int a2, int a3, bool a4, bool a5)
bool  CGeologistRole::CheckPosition(int a2, int a3, bool a4, bool a5) {
  
  int v6; // [esp+8h] [ebp-8h]
  unsigned int v7; // [esp+Ch] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3) )
    return 0;
  v6 = CWorldManager::Index(a2, a3);
  if ( (CWorldManager::Ground(a2, a3) & 0xF0) != 0x20
    || CWorldManager::ObjectId(a2, a3)
    || CWorldManager::ObjectId(a2 - 1, a3)
    || CWorldManager::ObjectId(a2 + 1, a3)
    || CWorldManager::ObjectId(a2, a3 - 1)
    || CWorldManager::ObjectId(a2, a3 + 1)
    || CWorldManager::ObjectId(a2 - 1, a3 - 1)
    || CWorldManager::ObjectId(a2 + 1, a3 + 1) )
  {
    return 0;
  }
  v7 = 89;
  if ( a5 )
  {
    if ( !CWorldManager::FlagBits(v6, 0x20u) )
      return 0;
  }
  else
  {
    v7 = 121;
  }
  return !CWorldManager::FlagBits(v6, v7)
      && (!CWorldManager::MapObjectId(a2, a3) || a5)
      && CWorldManager::ObjectId(a2, a3) == 0;
}


