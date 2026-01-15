#include "CMushroomFarmerRole.h"

// Definitions for class CMushroomFarmerRole

// address=[0x14014e0]
// Decompiled from int __cdecl CMushroomFarmerRole::New(int a1)
static class CPersistence * __cdecl CMushroomFarmerRole::New(std::istream &) {
  
  if ( operator new(0x30u) )
    return CMushroomFarmerRole::CMushroomFarmerRole(a1);
  else
    return 0;
}


// address=[0x15787f0]
// Decompiled from int __thiscall CMushroomFarmerRole::InitWalking(CMushroomFarmerRole *this, struct CSettler *a2)
class CWalking *  CMushroomFarmerRole::InitWalking(class CSettler *) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = CWalking::Create(0, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x1578830]
// Decompiled from int __thiscall CMushroomFarmerRole::LogicUpdateJob(CMushroomFarmerRole *this, struct CSettler *a2)
void  CMushroomFarmerRole::LogicUpdateJob(class CSettler *) {
  
  int v2; // eax
  int v3; // esi
  int v4; // esi
  int v6; // [esp-4h] [ebp-30h]
  int v7; // [esp+4h] [ebp-28h]
  int v8; // [esp+8h] [ebp-24h]
  int v9; // [esp+Ch] [ebp-20h]
  int v10; // [esp+14h] [ebp-18h]
  int v11; // [esp+20h] [ebp-Ch]
  char v12; // [esp+24h] [ebp-8h]

  v12 = *((_BYTE *)this + 4);
  switch ( v12 )
  {
    case 6:
      IMovingEntity::SetDistance(a2, 0);
      return (*(int (__thiscall **)(CMushroomFarmerRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
    case 16:
      if ( *((char *)this + 6) <= (int)*((unsigned __int8 *)this + 7) )
        v10 = *((char *)this + 6);
      else
        v10 = *((unsigned __int8 *)this + 7);
      *((_BYTE *)this + 6) -= v10;
      if ( *((char *)this + 6) <= 0 )
      {
        if ( !*((_WORD *)this + 17) )
          return (*(int (__thiscall **)(CMushroomFarmerRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
        v9 = CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 17));
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 32))(v9, 1);
        return (*(int (__thiscall **)(CMushroomFarmerRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
      }
      else
      {
        return IAnimatedEntity::RegisterForLogicUpdate(v10);
      }
    case 25:
      if ( *((char *)this + 6) <= (int)*((unsigned __int8 *)this + 7) )
        v11 = *((char *)this + 6);
      else
        v11 = *((unsigned __int8 *)this + 7);
      *((_BYTE *)this + 6) -= v11;
      if ( *((char *)this + 6) <= 0 )
      {
        v6 = IEntity::Type((unsigned __int16 *)a2);
        v2 = IEntity::Race(a2);
        CSettlerMgr::GetSettlerInfo(v2, v6);
        v3 = IEntity::X(a2);
        v7 = v3 - *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](1) + 5);
        v4 = IEntity::Y(a2);
        v8 = v4 - *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](1) + 6);
        CDecoObjMgr::AddDecoObjWithoutFlags(&g_cDecoObjMgr, v7, v8, *((_DWORD *)this + 11), 0, 0);
        *((_DWORD *)this + 11) = 0;
        return (*(int (__thiscall **)(CMushroomFarmerRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
      }
      else
      {
        return IAnimatedEntity::RegisterForLogicUpdate(v11);
      }
    default:
      return (*(int (__thiscall **)(struct CSettler *, _DWORD, const char *))(*(_DWORD *)a2 + 48))(
               a2,
               0,
               "CMushroomFarmerRole::LogicUpdateJob(): Invalid Job");
  }
}


// address=[0x1578a30]
// Decompiled from int __thiscall CMushroomFarmerRole::UpdateJob(CMushroomFarmerRole *this, struct CSettler *a2)
void  CMushroomFarmerRole::UpdateJob(class CSettler *) {
  
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
      return IAnimatedEntity::SetFrame((*((unsigned __int16 *)this + 4) + v2) % *((unsigned __int8 *)this + 7));
    case 21:
      v3 = IAnimatedEntity::Frame(a2);
      IAnimatedEntity::SetFrame(v3 - *((_WORD *)this + 4));
      result = IAnimatedEntity::Frame(a2);
      if ( result < 0 )
        return IAnimatedEntity::SetFrame(0);
      break;
    case 22:
      v4 = IAnimatedEntity::Frame(a2);
      IAnimatedEntity::SetFrame(*((_WORD *)this + 4) + v4);
      result = IAnimatedEntity::Frame(a2);
      if ( result >= *((unsigned __int8 *)this + 7) )
        return IAnimatedEntity::SetFrame(0);
      break;
    default:
      return CTrace::Print("MushroomfarmerRole - Update unknown task");
  }
  return result;
}


// address=[0x1578b00]
// Decompiled from int __stdcall CMushroomFarmerRole::PostLoadInit(CPropertySet *a1)
void  CMushroomFarmerRole::PostLoadInit(class CSettler *) {
  
  return CWarMap::AddEntity(a1);
}


// address=[0x1578b20]
// Decompiled from char __thiscall CMushroomFarmerRole::SetFree(CMushroomFarmerRole *this, struct CSettler *a2, int a3)
bool  CMushroomFarmerRole::SetFree(class CSettler *,int) {
  
  int v3; // eax
  int v4; // eax
  struct IEntity *v6; // [esp+0h] [ebp-8h]

  if ( ISettlerRole::HomeEntityId(this) )
  {
    v3 = ISettlerRole::HomeEntityId(this);
    v6 = CMapObjectMgr::Entity(v3);
    v4 = IEntity::EntityId((unsigned __int16 *)a2);
    ((void (__thiscall *)(struct IEntity *, int))v6->CPersistence[1].Relationships)(v6, v4);
    if ( ISettlerRole::HomeEntityId(this) )
    {
      if ( BBSupportDbgReport(2, "MapObjects\\Settler\\MushroomfarmerRole.cpp", 680, "HomeEntityId() == 0") == 1 )
        __debugbreak();
    }
  }
  (*(void (__thiscall **)(struct CSettler *))(*(_DWORD *)a2 + 104))(a2);
  return 0;
}


// address=[0x1578ba0]
// Decompiled from char __thiscall CMushroomFarmerRole::ESChanged(CMushroomFarmerRole *this, struct CSettler *a2)
bool  CMushroomFarmerRole::ESChanged(class CSettler *) {
  
  return 0;
}


// address=[0x1578bb0]
// Decompiled from char *__thiscall CMushroomFarmerRole::CMushroomFarmerRole(char *this, int a2)
 CMushroomFarmerRole::CMushroomFarmerRole(std::istream &) {
  
  int v3; // [esp+4h] [ebp-1Ch] BYREF
  int pExceptionObject; // [esp+8h] [ebp-18h] BYREF
  int v5; // [esp+Ch] [ebp-14h]
  char *v6; // [esp+10h] [ebp-10h]
  int v7; // [esp+1Ch] [ebp-4h]

  v6 = this;
  ISettlerRole::ISettlerRole(this, a2);
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
    operator^<unsigned int>(a2, v6 + 44);
  }
  return v6;
}


// address=[0x1578c80]
// Decompiled from int __thiscall CMushroomFarmerRole::Store(struct CPersistence *this, struct std::ostream *a2)
void  CMushroomFarmerRole::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct CPersistence *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  ISettlerRole::Store(this, a2);
  v3 = 2;
  operator^<unsigned int>(a2, &v3);
  return operator^<unsigned int>(a2, (int *)v4 + 11);
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
// Decompiled from int __cdecl CMushroomFarmerRole::Load(int a1)
static class CMushroomFarmerRole * __cdecl CMushroomFarmerRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CMushroomFarmerRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8beec]
// [Decompilation failed for static unsigned long CMushroomFarmerRole::m_iClassID]

// address=[0x1578cd0]
// Decompiled from CMushroomFarmerRole *__thiscall CMushroomFarmerRole::CMushroomFarmerRole(CMushroomFarmerRole *this)
 CMushroomFarmerRole::CMushroomFarmerRole(void) {
  
  ISettlerRole::ISettlerRole(this);
  *(_DWORD *)this = &CMushroomFarmerRole::_vftable_;
  *((_DWORD *)this + 11) = 0;
  return this;
}


// address=[0x1578d00]
// Decompiled from ISettlerRole *__thiscall CMushroomFarmerRole::~CMushroomFarmerRole(CMushroomFarmerRole *this)
 CMushroomFarmerRole::~CMushroomFarmerRole(void) {
  
  *(_DWORD *)this = &CMushroomFarmerRole::_vftable_;
  return ISettlerRole::~ISettlerRole(this);
}


// address=[0x1578d20]
// Decompiled from int __thiscall CMushroomFarmerRole::GetNextJob(CMushroomFarmerRole *this, struct CSettler *a2)
void  CMushroomFarmerRole::GetNextJob(class CSettler *) {
  
  int result; // eax

  IMovingEntity::IncToDoListIter(a2);
  result = IMovingEntity::IsEndIter(a2);
  if ( !(_BYTE)result )
    return (*(int (__thiscall **)(CMushroomFarmerRole *, struct CSettler *))(*(_DWORD *)this + 40))(this, a2);
  *((_BYTE *)this + 4) = 17;
  return result;
}


// address=[0x1578d60]
// Decompiled from void __thiscall CMushroomFarmerRole::TakeJob(CMushroomFarmerRole *this, struct CSettler *a2)
void  CMushroomFarmerRole::TakeJob(class CSettler *) {
  
  const struct CEntityTask *ActualTask; // eax
  unsigned int v3; // eax
  int v4; // eax
  CBuilding *v5; // eax
  int v6; // [esp-4h] [ebp-1Ch]
  int v7; // [esp+4h] [ebp-14h]
  int v8; // [esp+8h] [ebp-10h]
  int v9; // [esp+Ch] [ebp-Ch]

  ActualTask = (const struct CEntityTask *)IMovingEntity::GetActualTask(a2);
  ISettlerRole::InitCommonTaskValues(this, a2, ActualTask);
  switch ( *((_BYTE *)this + 4) )
  {
    case 7:
    case 0xA:
    case 0x21:
      IAnimatedEntity::SetFrame(1);
      v7 = *((__int16 *)this + 7) + Y16X16::UnpackXFast(*((_DWORD *)this + 6));
      v8 = *((__int16 *)this + 8) + Y16X16::UnpackYFast(*((_DWORD *)this + 6));
      *((_DWORD *)this + 6) = Y16X16::PackXYFast(v7, v8);
      if ( *((_BYTE *)this + 4) == 33 )
        v9 = 0x2000;
      else
        v9 = 0;
      IMovingEntity::WalkToXY(a2, *((_DWORD *)this + 6), v9);
      *((_BYTE *)this + 4) = 6;
      IMovingEntity::SetDisplacementCosts(5);
      (*(void (__thiscall **)(CMushroomFarmerRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
      break;
    case 0xD:
    case 0x10:
    case 0x19:
      IMovingEntity::SetDisplacementCosts(10);
      IAnimatedEntity::RegisterForLogicUpdate(*((unsigned __int8 *)this + 7));
      break;
    case 0xE:
      IAnimatedEntity::SetFrame(1);
      IMovingEntity::WalkToXY(a2, *((_DWORD *)this + 7), 0);
      *((_BYTE *)this + 4) = 6;
      IMovingEntity::SetDisplacementCosts(5);
      (*(void (__thiscall **)(CMushroomFarmerRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
      break;
    case 0x11:
      IMovingEntity::SetDisplacementCosts(0);
      v3 = CStateGame::Rand(g_pGame);
      IAnimatedEntity::RegisterForLogicUpdate(v3 % 0x10 + 1);
      break;
    case 0x15:
      IMovingEntity::SetDisplacementCosts(10);
      IAnimatedEntity::SetFrame(*((_BYTE *)this + 7) - 1);
      IAnimatedEntity::RegisterForLogicUpdate(*((char *)this + 6) / 2);
      break;
    case 0x16:
      IMovingEntity::SetDisplacementCosts(10);
      IAnimatedEntity::RegisterForLogicUpdate(*((char *)this + 6) / 2 - 1);
      break;
    case 0x18:
      if ( ISettlerRole::HomeEntityId(this) )
      {
        *((_DWORD *)this + 9) = 0;
        *((_DWORD *)this + 10) = 0;
        *((_DWORD *)this + 6) = 0;
        IMovingEntity::SetDisplacementCosts(10);
        v6 = IEntity::ID();
        v4 = ISettlerRole::HomeEntityId(this);
        v5 = (CBuilding *)CBuildingMgr::operator[](v4);
        CBuilding::SettlerEnter(v5, v6);
      }
      else if ( BBSupportDbgReportF(
                  2,
                  "MapObjects\\Settler\\MushroomfarmerRole.cpp",
                  474,
                  " m_uHomeEntityId == 0 -> crushed?") == 1 )
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
// Decompiled from int __stdcall CMushroomFarmerRole::Init(CPropertySet *a1)
void  CMushroomFarmerRole::Init(class CSettler *) {
  
  return CWarMap::AddEntity(a1);
}


// address=[0x1579070]
// Decompiled from _DWORD *__thiscall CMushroomFarmerRole::ConvertEventIntoGoal(  CMushroomFarmerRole *this,  struct CSettler *a2,  struct CEntityEvent *a3)
void  CMushroomFarmerRole::ConvertEventIntoGoal(class CSettler *,class CEntityEvent *) {
  
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

  switch ( *((_DWORD *)a3 + 1) )
  {
    case 1:
      if ( !ISettlerRole::HomeEntityId(this) )
        goto LABEL_2;
      v19 = IEntity::Type((unsigned __int16 *)a2);
      v5 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v5, v19);
      v26 = (CMFCToolBarButton *)CBuildingMgr::operator[](*((_DWORD *)a3 + 3));
      v6 = CBuilding::DoorPackedXY(v26);
      ISettlerRole::NewDestination(this, a2, v6, 0);
      v20 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
      v16 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
      v7 = IEntity::Race(a2);
      v8 = CEntityToDoListMgr::SettlerJobList(v7, v16);
      result = (_DWORD *)(*(int (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v8, v20);
      break;
    case 2:
      if ( !ISettlerRole::HomeEntityId(this) )
        goto LABEL_2;
      v21 = IEntity::Type((unsigned __int16 *)a2);
      v9 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v9, v21);
      v25 = (CMFCToolBarButton *)CBuildingMgr::operator[](*((_DWORD *)a3 + 3));
      v10 = CBuilding::DoorPackedXY(v25);
      ISettlerRole::NewDestination(this, a2, v10, 0);
      v27 = *((_DWORD *)a3 + 4) != 0;
      v22 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](v27);
      v17 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](v27);
      v11 = IEntity::Race(a2);
      v12 = CEntityToDoListMgr::SettlerJobList(v11, v17);
      result = (_DWORD *)(*(int (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v12, v22);
      break;
    case 6:
      *((_DWORD *)this + 11) = *((_DWORD *)a3 + 4);
      v23 = IEntity::Type((unsigned __int16 *)a2);
      v13 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v13, v23);
      ISettlerRole::NewDestination(this, a2, *((_DWORD *)a3 + 5), 0);
      v24 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](2);
      v18 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](2);
      v14 = IEntity::Race(a2);
      v15 = CEntityToDoListMgr::SettlerJobList(v14, v18);
      result = (_DWORD *)(*(int (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v15, v24);
      break;
    case 9:
LABEL_2:
      (*(void (__thiscall **)(CMushroomFarmerRole *, struct CSettler *, int))(*(_DWORD *)this + 64))(this, a2, -1);
      v3 = IEntity::ID();
      result = (_DWORD *)(*(int (__thiscall **)(void *, int, _DWORD))(*(_DWORD *)g_pDarkTribe + 4))(g_pDarkTribe, v3, 0);
      break;
    default:
      result = IEntity::SetFlagBits(a2, (EntityFlag)0x80000000);
      break;
  }
  return result;
}


