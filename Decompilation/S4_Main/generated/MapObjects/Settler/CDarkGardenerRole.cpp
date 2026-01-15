#include "CDarkGardenerRole.h"

// Definitions for class CDarkGardenerRole

// address=[0x1400180]
// Decompiled from int __cdecl CDarkGardenerRole::New(int a1)
static class CPersistence * __cdecl CDarkGardenerRole::New(std::istream &) {
  
  if ( operator new(0x50u) )
    return CDarkGardenerRole::CDarkGardenerRole(a1);
  else
    return 0;
}


// address=[0x15671c0]
// Decompiled from int __thiscall CDarkGardenerRole::InitWalking(CDarkGardenerRole *this, struct CSettler *a2)
class CWalking *  CDarkGardenerRole::InitWalking(class CSettler *) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = CWalking::Create(0, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x1567200]
// Decompiled from int __thiscall CDarkGardenerRole::LogicUpdateJob(CDarkGardenerRole *this, struct CSettler *a2)
void  CDarkGardenerRole::LogicUpdateJob(class CSettler *) {
  
  int v2; // eax
  int v3; // eax
  int v5; // [esp-4h] [ebp-Ch]
  int v6; // [esp-4h] [ebp-Ch]
  char v7; // [esp+0h] [ebp-8h]

  v7 = *((_BYTE *)this + 4);
  switch ( v7 )
  {
    case 6:
      IMovingEntity::SetDistance(a2, 0);
      return (*(int (__thiscall **)(CDarkGardenerRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
    case 16:
      if ( debug && DEBUG_FLAGS[dword_41520A0] )
        BBSupportTracePrint(0, "LogicUpdateJob WORK");
      if ( *((_DWORD *)this + 16) == -1
        || !CDecoObjMgr::IsAddDecoObjOk(
              (CDecoObjMgr *)&g_cDecoObjMgr,
              *((_DWORD *)this + 16),
              *((_DWORD *)this + 17),
              216,
              0,
              0) )
      {
        v6 = IEntity::Y(a2);
        v3 = IEntity::X(a2);
        IDarkTribe::ChangePositionToDarkLand((IDarkTribe *)g_pDarkTribe, v3, v6);
      }
      else
      {
        CDecoObjMgr::AddDecoObj(
          (CDecoObjMgr *)&g_cDecoObjMgr,
          *((_DWORD *)this + 16),
          *((_DWORD *)this + 17),
          216,
          1,
          1);
        v5 = IEntity::Y(a2);
        v2 = IEntity::X(a2);
        IDarkTribe::ChangePositionToDarkLand((IDarkTribe *)g_pDarkTribe, v2, v5);
        *((_DWORD *)this + 16) = -1;
        *((_DWORD *)this + 17) = -1;
      }
      return (*(int (__thiscall **)(CDarkGardenerRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
    case 31:
      return (*(int (__thiscall **)(CDarkGardenerRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
    default:
      return CTrace::Print("DarkGardenerRole.cpp: Wrong Task %d for logic update", *((char *)this + 4));
  }
}


// address=[0x1567360]
// Decompiled from int __thiscall CDarkGardenerRole::PostLoadInit(int this, CPropertySet *a2)
void  CDarkGardenerRole::PostLoadInit(class CSettler *) {
  
  int result; // eax
  int v4; // [esp+0h] [ebp-4h]

  CWarMap::AddEntity(a2);
  if ( std::list<CEntityTask>::size((void *)(this + 44)) )
    IMovingEntity::SetToDoList(a2, this + 44);
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


// address=[0x15673d0]
// Decompiled from char *__thiscall CDarkGardenerRole::CDarkGardenerRole(char *this, int a2)
 CDarkGardenerRole::CDarkGardenerRole(std::istream &) {
  
  int v2; // eax
  _DWORD v4[2]; // [esp+4h] [ebp-24h] BYREF
  int v5; // [esp+Ch] [ebp-1Ch] BYREF
  int pExceptionObject; // [esp+10h] [ebp-18h] BYREF
  unsigned int i; // [esp+14h] [ebp-14h]
  char *v8; // [esp+18h] [ebp-10h]
  int v9; // [esp+24h] [ebp-4h]

  v8 = this;
  ISettlerRole::ISettlerRole(this, a2);
  v9 = 0;
  *(_DWORD *)v8 = &CDarkGardenerRole::_vftable_;
  std::list<CEntityTask>::list<CEntityTask>(v8 + 44);
  LOBYTE(v9) = 1;
  operator^<unsigned int>(a2, &v5);
  v4[1] = v5;
  if ( v5 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CDarkGardenerRole");
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
  operator^<unsigned char>(a2, v8 + 12);
  operator^<int>(a2, (int)(v8 + 56));
  operator^<int>(a2, (int)(v8 + 60));
  operator^<int>(a2, (int)(v8 + 64));
  operator^<int>(a2, (int)(v8 + 68));
  operator^<int>(a2, (int)(v8 + 72));
  operator^<int>(a2, (int)(v8 + 76));
  v9 = -1;
  return v8;
}


// address=[0x1567560]
// Decompiled from int __thiscall CDarkGardenerRole::Store(struct CPersistence *this, struct std::ostream *a2)
void  CDarkGardenerRole::Store(std::ostream &) {
  
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
  struct CPersistence *v21; // [esp+6Ch] [ebp-14h]
  char v22; // [esp+70h] [ebp-10h]
  char v23; // [esp+71h] [ebp-Fh]
  char v24; // [esp+72h] [ebp-Eh]
  int v25; // [esp+73h] [ebp-Dh] BYREF
  int v26; // [esp+7Ch] [ebp-4h]

  v21 = this;
  if ( !*((_WORD *)this + 9)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\DarkGardenerRole.cpp", 111, "m_uSettlerId>0") == 1 )
  {
    __debugbreak();
  }
  if ( !CMapObjectMgr::ValidEntityId(*((unsigned __int16 *)v21 + 9))
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\DarkGardenerRole.cpp",
         112,
         "CMapObjectMgr::ValidEntityId(m_uSettlerId)") == 1 )
  {
    __debugbreak();
  }
  ISettlerRole::Store(v21, a2);
  v18 = 1;
  operator^<unsigned int>(a2, &v18);
  v19 = std::list<CEntityTask>::size((char *)v21 + 44);
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
  if ( v2 >= std::list<CEntityTask>::size((char *)v21 + 44) )
    LOBYTE(v25) = 0;
  operator^<unsigned char>(a2, (int)&v25);
  operator^<int>((int)a2, (int *)v21 + 14);
  operator^<int>((int)a2, (int *)v21 + 15);
  operator^<int>((int)a2, (int *)v21 + 16);
  operator^<int>((int)a2, (int *)v21 + 17);
  operator^<int>((int)a2, (int *)v21 + 18);
  return operator^<int>((int)a2, (int *)v21 + 19);
}


// address=[0x15686e0]
// Decompiled from int __thiscall CDarkGardenerRole::ClassID(CDarkGardenerRole *this)
unsigned long  CDarkGardenerRole::ClassID(void)const {
  
  return CDarkGardenerRole::m_iClassID;
}


// address=[0x15687d0]
// Decompiled from int __thiscall CDarkGardenerRole::GetSettlerRole(CDarkGardenerRole *this)
int  CDarkGardenerRole::GetSettlerRole(void)const {
  
  return 14;
}


// address=[0x15687f0]
// Decompiled from bool __cdecl CDarkGardenerRole::IsLandChangeable(char a1)
static bool __cdecl CDarkGardenerRole::IsLandChangeable(int) {
  
  return (a1 & 0xF0) != 32;
}


// address=[0x15884c0]
// Decompiled from int __cdecl CDarkGardenerRole::Load(int a1)
static class CDarkGardenerRole * __cdecl CDarkGardenerRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CDarkGardenerRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8beac]
// [Decompilation failed for static unsigned long CDarkGardenerRole::m_iClassID]

// address=[0x1567840]
// Decompiled from ISettlerRole *__thiscall CDarkGardenerRole::~CDarkGardenerRole(CDarkGardenerRole *this)
 CDarkGardenerRole::~CDarkGardenerRole(void) {
  
  *(_DWORD *)this = &CDarkGardenerRole::_vftable_;
  if ( *((_DWORD *)this + 16) != -1 )
    CWorldManager::ClearFlagBits(*((_DWORD *)this + 16), *((_DWORD *)this + 17), 32);
  std::list<CEntityTask>::~list<CEntityTask>();
  return ISettlerRole::~ISettlerRole(this);
}


// address=[0x15678c0]
// Decompiled from int __thiscall CDarkGardenerRole::GetNextJob(CDarkGardenerRole *this, struct CSettler *a2)
void  CDarkGardenerRole::GetNextJob(class CSettler *) {
  
  CDarkGardenerRole *v3; // [esp+0h] [ebp-4h]

  v3 = this;
  IMovingEntity::IncToDoListIter(a2);
  if ( IMovingEntity::IsEndIter(a2) )
    IMovingEntity::ResetToDoList(v3);
  return (*(int (__thiscall **)(CDarkGardenerRole *, struct CSettler *))(*(_DWORD *)v3 + 40))(v3, a2);
}


// address=[0x1567900]
// Decompiled from void __thiscall CDarkGardenerRole::TakeJob(CDarkGardenerRole *this, struct CSettler *a2)
void  CDarkGardenerRole::TakeJob(class CSettler *) {
  
  const struct CEntityTask *ActualTask; // eax
  unsigned int v3; // eax
  int v4; // esi
  int v5; // esi
  int v6; // eax
  Y16X16 *v7; // eax
  int v8; // [esp-8h] [ebp-2Ch]
  int v9; // [esp-4h] [ebp-28h]
  int v10; // [esp+4h] [ebp-20h]
  int v11; // [esp+8h] [ebp-1Ch]
  int v12; // [esp+Ch] [ebp-18h]
  int v13; // [esp+10h] [ebp-14h]
  int v14; // [esp+14h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-8h]

  ActualTask = (const struct CEntityTask *)IMovingEntity::GetActualTask(a2);
  ISettlerRole::InitCommonTaskValues(this, a2, ActualTask);
  switch ( *((_BYTE *)this + 4) )
  {
    case 7:
      if ( debug && DEBUG_FLAGS[dword_41520A0] )
        BBSupportTracePrint(0, "TakeJob GO_TO_POS");
      IAnimatedEntity::SetFrame(1);
      if ( *((__int16 *)this + 7) > 0 || *((__int16 *)this + 8) > 0 )
        ISettlerRole::NewDestination(this, a2, *((__int16 *)this + 7), *((__int16 *)this + 8), 0);
      v10 = *((__int16 *)this + 7) + Y16X16::UnpackXFast(*((_DWORD *)this + 6));
      v11 = *((__int16 *)this + 8) + Y16X16::UnpackYFast(*((_DWORD *)this + 6));
      *((_DWORD *)this + 6) = Y16X16::PackXYFast(v10, v11);
      IMovingEntity::WalkToXY(a2, *((_DWORD *)this + 6), 0);
      *((_BYTE *)this + 4) = 6;
      IMovingEntity::SetDisplacementCosts(5);
      (*(void (__thiscall **)(CDarkGardenerRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
      break;
    case 0x10:
      if ( debug && DEBUG_FLAGS[dword_41520A0] )
        BBSupportTracePrint(0, "TakeJob WORK");
      if ( *((_DWORD *)this + 16) != -1 )
        CWorldManager::ClearFlagBits(*((_DWORD *)this + 16), *((_DWORD *)this + 17), 32);
      *((_DWORD *)this + 16) = -1;
      *((_DWORD *)this + 17) = -1;
      for ( i = 1; ; ++i )
      {
        if ( i >= 7 )
          goto LABEL_15;
        v4 = IEntity::X(a2);
        v13 = CSpiralOffsets::DeltaX(i) + v4;
        v5 = IEntity::Y(a2);
        v14 = CSpiralOffsets::DeltaY(i) + v5;
        if ( CDarkGardenerRole::CheckPosition(this, v13, v14, 0) )
        {
          if ( CDecoObjMgr::IsAddDecoObjOk((CDecoObjMgr *)&g_cDecoObjMgr, v13, v14, 216, 0, 0) )
            break;
        }
      }
      *((_DWORD *)this + 16) = v13;
      *((_DWORD *)this + 17) = v14;
      v9 = Y16X16::PackXYFast(v13, v14);
      v8 = IEntity::Y(a2);
      v6 = IEntity::X(a2);
      v7 = (Y16X16 *)Y16X16::PackXYFast(v6, v8);
      v12 = Y16X16::DirectionFast(v7, v9);
      IMovingEntity::SetDirection(a2, v12);
      IMovingEntity::SetDisplacementCosts(10);
      IAnimatedEntity::RegisterForLogicUpdate(*((char *)this + 6));
      break;
    case 0x11:
      IMovingEntity::SetDisplacementCosts(0);
      v3 = CStateGame::Rand(g_pGame);
      IAnimatedEntity::RegisterForLogicUpdate(v3 % 0x10 + 1);
      break;
    case 0x1F:
      if ( CDarkGardenerRole::SearchPosition(this, a2) )
      {
LABEL_15:
        IAnimatedEntity::RegisterForLogicUpdate(1);
      }
      else
      {
        *((_DWORD *)this + 19) += 64;
        if ( (int)++*((_DWORD *)this + 18) <= 56 )
        {
          IAnimatedEntity::SetFrame(0);
          (*(void (__thiscall **)(CDarkGardenerRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
        }
        else
        {
          CDarkGardenerRole::WorkIsDone(this, a2);
        }
      }
      break;
    default:
      CTrace::Print("DarkGardenerRole - TakeJob unknown task");
      break;
  }
}


// address=[0x1567c90]
// Decompiled from int __thiscall CDarkGardenerRole::Init(int this, CPropertySet *a2)
void  CDarkGardenerRole::Init(class CSettler *) {
  
  int result; // eax

  CWarMap::AddEntity(a2);
  IEntity::SetFlagBits(a2, VulnerableMask|Selectable);
  *(_DWORD *)(this + 64) = -1;
  *(_DWORD *)(this + 68) = -1;
  *(_DWORD *)(this + 56) = 0;
  *(_DWORD *)(this + 60) = 0;
  *(_DWORD *)(this + 72) = 0;
  *(_DWORD *)(this + 76) = 0;
  *(_WORD *)(this + 34) = 0;
  result = IEntity::ID();
  *(_WORD *)(this + 18) = result;
  return result;
}


// address=[0x1567d10]
// Decompiled from int __thiscall CDarkGardenerRole::ConvertEventIntoGoal(  CDarkGardenerRole *this,  struct CSettler *a2,  struct CEntityEvent *a3)
void  CDarkGardenerRole::ConvertEventIntoGoal(class CSettler *,class CEntityEvent *) {
  
  int v3; // eax
  int v4; // eax
  int result; // eax
  int v6; // [esp+0h] [ebp-20h]
  int v7; // [esp+4h] [ebp-1Ch]
  int v8; // [esp+Ch] [ebp-14h]
  int v9; // [esp+10h] [ebp-10h]
  int v10; // [esp+14h] [ebp-Ch]
  int v11; // [esp+18h] [ebp-8h]

  v8 = *((_DWORD *)a3 + 1);
  if ( v8 == 13 )
  {
    CTrace::Print("CDarkGardenerRole - NewDestinationEx called from ConvertEventIntoGoal-GO_TO_POS");
    return (*(int (__thiscall **)(CDarkGardenerRole *, struct CSettler *, char *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
             this,
             a2,
             (char *)this + 44,
             *((_DWORD *)a3 + 4),
             *((_DWORD *)a3 + 5),
             *((_DWORD *)a3 + 3));
  }
  else if ( v8 == 17 )
  {
    if ( *((_DWORD *)this + 16) != -1 )
    {
      CWorldManager::ClearFlagBits(*((_DWORD *)this + 16), *((_DWORD *)this + 17), 32);
      *((_DWORD *)this + 16) = -1;
      *((_DWORD *)this + 17) = -1;
    }
    result = *((_DWORD *)a3 + 2);
    if ( result == 13 )
    {
      v9 = *((_DWORD *)a3 + 3);
      v11 = *((_DWORD *)a3 + 4);
      v7 = Y16X16::UnpackXFast(v11);
      v6 = Y16X16::UnpackYFast(v11);
      if ( (v9 & 2) != 0 || (v9 & 1) != 0 )
      {
        return CTrace::Print("CGardenerRole - Either COMMAND_FLAG_QUEUE or COMMAND_FLAG_PATROUILLE got...!");
      }
      else
      {
        if ( (v9 & 4) != 0 )
        {
          v10 = 241;
          ISettlerRole::NewDestination(this, a2, v11, 0);
        }
        else
        {
          v10 = 160;
          ISettlerRole::NewDestination(this, a2, v11, 0);
          *((_DWORD *)this + 14) = v7;
          *((_DWORD *)this + 15) = v6;
          *((_DWORD *)this + 19) = 0;
          *((_DWORD *)this + 18) = 0;
        }
        v3 = IEntity::Race(a2);
        v4 = CEntityToDoListMgr::SettlerJobList(v3, v10);
        return (*(int (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v4, v10);
      }
    }
  }
  else
  {
    result = IEntity::FlagBits(a2, Registered);
    if ( !result )
    {
      CTrace::Print("ConvertEventIntoGoal DarkGardenerRole - unknown event %u", *((_DWORD *)a3 + 1));
      return IAnimatedEntity::RegisterForLogicUpdate(1);
    }
  }
  return result;
}


// address=[0x1567ee0]
// Decompiled from int __thiscall CDarkGardenerRole::WorkIsDone(CDarkGardenerRole *this, struct CSettler *a2)
void  CDarkGardenerRole::WorkIsDone(class CSettler *) {
  
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


// address=[0x1567f30]
// Decompiled from bool __thiscall CDarkGardenerRole::CheckPosition(CDarkGardenerRole *this, int a2, int a3, bool a4)
bool  CDarkGardenerRole::CheckPosition(int,int,bool) {
  
  char v5; // al
  int v6; // [esp+4h] [ebp-8h]
  unsigned int v7; // [esp+8h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3) )
    return 0;
  v6 = CWorldManager::Index(a2, a3);
  v7 = 31;
  if ( a4 )
  {
    if ( !CWorldManager::FlagBits(v6, 0x20u) )
      return 0;
  }
  else
  {
    v7 = 63;
  }
  if ( CWorldManager::FlagBits(v6, v7) )
    return 0;
  if ( CWorldManager::MapObjectId(a2, a3) && !a4 )
    return 0;
  if ( CWorldManager::ObjectId(a2, a3) )
    return 0;
  v5 = CWorldManager::Ground(a2, a3);
  return CDarkGardenerRole::IsLandChangeable(v5);
}


// address=[0x1568020]
// Decompiled from char __thiscall CDarkGardenerRole::SearchPosition(CDarkGardenerRole *this, struct CSettler *a2)
bool  CDarkGardenerRole::SearchPosition(class CSettler *) {
  
  int v2; // eax
  int v3; // esi
  int v4; // esi
  int v5; // eax
  int v7; // [esp-4h] [ebp-38h]
  int v8; // [esp-4h] [ebp-38h]
  int v9; // [esp+8h] [ebp-2Ch]
  unsigned int v10; // [esp+10h] [ebp-24h]
  int v11; // [esp+14h] [ebp-20h]
  int v12; // [esp+18h] [ebp-1Ch]
  int v13; // [esp+1Ch] [ebp-18h]
  unsigned int v14; // [esp+1Ch] [ebp-18h]
  int v15; // [esp+20h] [ebp-14h]
  int i; // [esp+24h] [ebp-10h]
  int v17; // [esp+28h] [ebp-Ch]
  int v18; // [esp+2Ch] [ebp-8h]

  v15 = -1;
  v12 = -1;
  v10 = -1;
  v11 = 0;
  v7 = IEntity::Y(a2);
  v2 = IEntity::X(a2);
  v9 = CWorldManager::SectorId(v2, v7);
  for ( i = *((_DWORD *)this + 19); i < *((_DWORD *)this + 19) + 64; ++i )
  {
    v3 = IEntity::X(a2);
    v18 = CSpiralOffsets::DeltaX(i) + v3;
    v4 = IEntity::Y(a2);
    v17 = CSpiralOffsets::DeltaY(i) + v4;
    if ( (unsigned __int8)CWorldManager::InWorld(v18, v17) )
    {
      if ( CWorldManager::SectorId(v18, v17) == v9 && CDarkGardenerRole::CheckPosition(this, v18, v17, 0) )
      {
        ++v11;
        v13 = CSpiralOffsets::PseudoDistanceSquareEx(v18 - *((_DWORD *)this + 14), v17 - *((_DWORD *)this + 15));
        v8 = v17 - IEntity::Y(a2);
        v5 = IEntity::X(a2);
        v14 = CSpiralOffsets::PseudoDistanceSquareEx(v18 - v5, v8) + 4 * v13;
        if ( v14 < v10 )
        {
          v10 = v14;
          v15 = v18;
          v12 = v17;
        }
      }
      if ( v11 > 31 )
        break;
    }
  }
  if ( v15 == -1 )
    return 0;
  if ( *((_DWORD *)this + 16) != -1 )
    CWorldManager::ClearFlagBits(*((_DWORD *)this + 16), *((_DWORD *)this + 17), 32);
  CWorldManager::SetFlagBits(v15, v12, 32);
  *((_DWORD *)this + 16) = v15;
  *((_DWORD *)this + 17) = v12;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 18) = 0;
  ISettlerRole::NewDestination(this, a2, v15, v12, 0);
  return 1;
}


// address=[0x15879d0]
// Decompiled from CDarkGardenerRole *__thiscall CDarkGardenerRole::CDarkGardenerRole(CDarkGardenerRole *this)
 CDarkGardenerRole::CDarkGardenerRole(void) {
  
  ISettlerRole::ISettlerRole(this);
  *(_DWORD *)this = &CDarkGardenerRole::_vftable_;
  std::list<CEntityTask>::list<CEntityTask>((char *)this + 44);
  return this;
}


