#include "CFleeRole.h"

// Definitions for class CFleeRole

// address=[0x1400a40]
// Decompiled from int __cdecl CFleeRole::New(int a1)
class CPersistence * __cdecl CFleeRole::New(std::istream & a1) {
  
  if ( operator new(0x2Cu) )
    return CFleeRole::CFleeRole(a1);
  else
    return 0;
}


// address=[0x156d370]
// Decompiled from int __thiscall CFleeRole::InitWalking(CFleeRole *this, struct CSettler *a2)
class CWalking *  CFleeRole::InitWalking(class CSettler * a2) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = CWalking::Create(0, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x156d3b0]
// Decompiled from char __thiscall CFleeRole::LogicUpdate(CFleeRole *this, struct CSettler *a2)
void  CFleeRole::LogicUpdate(class CSettler * a2) {
  
  int v2; // eax
  int v3; // esi
  int v4; // esi
  int v5; // eax
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // eax
  char result; // al
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13[6]; // [esp-4h] [ebp-60h] BYREF
  int v14; // [esp+14h] [ebp-48h]
  int v15; // [esp+18h] [ebp-44h]
  CCarrierRole *SettlerRole; // [esp+1Ch] [ebp-40h]
  int v17; // [esp+20h] [ebp-3Ch]
  int v18; // [esp+24h] [ebp-38h]
  int v19; // [esp+28h] [ebp-34h]
  int v20; // [esp+2Ch] [ebp-30h]
  _BYTE v21[4]; // [esp+30h] [ebp-2Ch] BYREF
  int i; // [esp+34h] [ebp-28h]
  int v23; // [esp+38h] [ebp-24h]
  unsigned __int16 *v24; // [esp+3Ch] [ebp-20h]
  int v25; // [esp+40h] [ebp-1Ch] BYREF
  int v26; // [esp+44h] [ebp-18h] BYREF
  ISettlerRole *v27; // [esp+48h] [ebp-14h]
  char v28; // [esp+4Eh] [ebp-Eh]
  char NearestPlayerLand; // [esp+4Fh] [ebp-Dh]
  int v30; // [esp+58h] [ebp-4h]

  v27 = this;
  v13[0] = IEntity::Y(a2);
  v2 = IEntity::X(a2);
  v23 = CWorldManager::Index(v2, v13[0]);
  v3 = ITiling::OwnerId(v23);
  if ( v3 == IEntity::OwnerId((unsigned __int8 *)a2) )
  {
    v17 = ITiling::EcoSectorId(v23);
    v24 = (unsigned __int16 *)CEcoSectorMgr::operator[](v17);
    v4 = CEcoSector::Owner(v24);
    if ( v4 != IEntity::OwnerId((unsigned __int8 *)a2)
      && BBSupportDbgReport(2, "MapObjects\\Settler\\FleeRole.cpp", 166, "rEcoSector.Owner()==_pSettler->OwnerId()") == 1 )
    {
      __debugbreak();
    }
    v5 = IEntity::Type((unsigned __int16 *)a2);
    CEcoSector::ChangeNrOfSettler((CEcoSector *)v24, v5, 1);
    v13[0] = IEntity::Type((unsigned __int16 *)a2);
    v6 = IEntity::Race(a2);
    SettlerRole = CSettlerMgr::CreateSettlerRole((CSettlerMgr *)g_cSettlerMgr, v6, v13[0]);
    std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(SettlerRole);
    v30 = 0;
    (*(void (__thiscall **)(struct CSettler *))(*(_DWORD *)a2 + 104))(a2);
    v13[0] = v7;
    v13[4] = (int)v13;
    v13[3] = std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(v21);
    CSettler::NewRole(a2, v13[0]);
    if ( !IEntity::FlagBits(a2, EntityFlag_Offered) )
    {
      v13[0] = IEntity::EntityId((unsigned __int16 *)a2);
      v8 = IEntity::Type((unsigned __int16 *)a2);
      CEcoSector::SetSettlerOffer(v24, v8, v13[0]);
    }
    CSettler::TakeWaitList(a2);
    v30 = -1;
    return std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(v21);
  }
  else
  {
    *((_BYTE *)v27 + 5) = ISettlerRole::SettlerWalk(v27, a2);
    if ( (*((_BYTE *)v27 + 5) & 0x70) != 0 )
    {
      v25 = IEntity::X(a2);
      v26 = IEntity::Y(a2);
      NearestPlayerLand = 0;
      v28 = 0;
      if ( *((char *)v27 + 6) < 5 )
      {
        v10 = IEntity::OwnerId((unsigned __int8 *)a2);
        NearestPlayerLand = CScanner::FindNearestPlayerLand(v10, &v25, &v26);
        if ( !NearestPlayerLand )
        {
          v28 = 1;
          v19 = ITiling::SectorId(v23);
          if ( v19 <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\FleeRole.cpp", 215, "iSectorId > 0") == 1 )
            __debugbreak();
          v15 = IEntity::X(a2);
          v14 = IEntity::Y(a2);
          for ( i = 0; i < 64; ++i )
          {
            v20 = (unsigned __int8)(CStateGame::Rand(g_pGame) + 0x80);
            v25 = v15 + CSpiralOffsets::DeltaX(v20);
            v26 = v14 + CSpiralOffsets::DeltaY(v20);
            if ( (unsigned __int8)CWorldManager::InWorld(v25, v26) && CWorldManager::SectorId(v25, v26) == v19 )
            {
              NearestPlayerLand = 1;
              break;
            }
          }
        }
      }
      if ( NearestPlayerLand )
      {
        if ( v28 )
          v18 = 0x2000;
        else
          v18 = 0;
        v13[5] = v18;
        IAnimatedEntity::SetFrame(1);
        v11 = Y16X16::PackXYFast(v25, v26);
        IMovingEntity::WalkToXY(a2, v11, v18);
        IMovingEntity::SetDisplacementCosts(5);
        IAnimatedEntity::RegisterForLogicUpdate(1);
        result = *((_BYTE *)v27 + 6) + 1;
        *((_BYTE *)v27 + 6) = result;
      }
      else
      {
        v12 = IEntity::EntityId((unsigned __int16 *)a2);
        return CSettlerMgr::DeleteSettler((CSettlerMgr *)g_cSettlerMgr, v12);
      }
    }
    else if ( (*((_BYTE *)v27 + 5) & 8) != 0 )
    {
      return IAnimatedEntity::RegisterForLogicUpdate(1);
    }
    else
    {
      return IAnimatedEntity::RegisterForLogicUpdate(9);
    }
  }
  return result;
}


// address=[0x156d730]
// Decompiled from void __thiscall CFleeRole::UpdateJob(CFleeRole *this, struct CSettler *a2)
void  CFleeRole::UpdateJob(class CSettler *) {
  
  ;
}


// address=[0x156d740]
// Decompiled from int __stdcall CFleeRole::PostLoadInit(CPropertySet *a1)
void  CFleeRole::PostLoadInit(class CSettler * a1) {
  
  return CWarMap::AddEntity(a1);
}


// address=[0x156d760]
// Decompiled from char __thiscall CFleeRole::SetFree(CFleeRole *this, struct CSettler *a2, int a3)
bool  CFleeRole::SetFree(class CSettler * a2, int a3) {
  
  return 0;
}


// address=[0x156d770]
// Decompiled from char __thiscall CFleeRole::ESChanged(CFleeRole *this, struct CSettler *a2)
bool  CFleeRole::ESChanged(class CSettler * a2) {
  
  return 0;
}


// address=[0x156d780]
// Decompiled from char *__thiscall CFleeRole::CFleeRole(char *this, int a2)
 CFleeRole::CFleeRole(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  char *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  ISettlerRole::ISettlerRole(this, a2);
  v6 = 0;
  *(_DWORD *)v5 = &CFleeRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CFleeRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v6 = -1;
  return v5;
}


// address=[0x156d830]
// Decompiled from int __thiscall CFleeRole::Store(struct CPersistence *this, struct std::ostream *a2)
void  CFleeRole::Store(std::ostream & a2) {
  
  int v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[1] = (int)this;
  ISettlerRole::Store(this, a2);
  v3[0] = 1;
  return operator^<unsigned int>(a2, v3);
}


// address=[0x156dbc0]
// Decompiled from int __thiscall CFleeRole::ClassID(CFleeRole *this)
unsigned long  CFleeRole::ClassID(void)const {
  
  return CFleeRole::m_iClassID;
}


// address=[0x156dbe0]
// Decompiled from int __thiscall CFleeRole::GetSettlerRole(CFleeRole *this)
int  CFleeRole::GetSettlerRole(void)const {
  
  return 18;
}


// address=[0x156dc00]
// Decompiled from void __thiscall CFleeRole::LogicUpdateJob(CFleeRole *this, struct CSettler *a2)
void  CFleeRole::LogicUpdateJob(class CSettler *) {
  
  ;
}


// address=[0x15885c0]
// Decompiled from int __cdecl CFleeRole::Load(int a1)
class CFleeRole * __cdecl CFleeRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CFleeRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bebc]
// [Decompilation failed for static unsigned long CFleeRole::m_iClassID]

// address=[0x156d870]
// Decompiled from CFleeRole *__thiscall CFleeRole::CFleeRole(CFleeRole *this)
 CFleeRole::CFleeRole(void) {
  
  ISettlerRole::ISettlerRole((ISettlerRole *)this);
  *(_DWORD *)this = &CFleeRole::_vftable_;
  return this;
}


// address=[0x156d890]
// Decompiled from void __thiscall CFleeRole::~CFleeRole(_AFX_OLE_STATE *this)
 CFleeRole::~CFleeRole(void) {
  
  *(_DWORD *)this = &CFleeRole::_vftable_;
  ISettlerRole::~ISettlerRole(this);
}


// address=[0x156d8b0]
// Decompiled from int __thiscall CFleeRole::GetNextJob(CFleeRole *this, struct CSettler *a2)
void  CFleeRole::GetNextJob(class CSettler * a2) {
  
  return (*(int (__thiscall **)(CFleeRole *, struct CSettler *))(*(_DWORD *)this + 40))(this, a2);
}


// address=[0x156d8d0]
// Decompiled from void __thiscall CFleeRole::TakeJob(CFleeRole *this, struct CSettler *a2)
void  CFleeRole::TakeJob(class CSettler * a2) {
  
  const struct CEntityTask *ActualTask; // eax

  ActualTask = (const struct CEntityTask *)IMovingEntity::GetActualTask(a2);
  ISettlerRole::InitCommonTaskValues(this, a2, ActualTask);
  if ( *((_BYTE *)this + 4) == 17 )
    IMovingEntity::SetDisplacementCosts(0);
}


// address=[0x156d910]
// Decompiled from int __thiscall CFleeRole::Init(_BYTE *this, CPropertySet *a2)
void  CFleeRole::Init(class CSettler * a2) {
  
  int result; // eax

  if ( IEntity::FlagBits(a2, EntityFlag_Offered|EntityFlag_Attached)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\FleeRole.cpp",
         125,
         "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED | ENTITY_FLAG_OFFERED) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( ISettlerRole::HomeEntityId(this)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\FleeRole.cpp", 126, "HomeEntityId() == 0") == 1 )
  {
    __debugbreak();
  }
  CWarMap::AddEntity(a2);
  (*(void (__thiscall **)(_BYTE *, CPropertySet *))(*(_DWORD *)this + 20))(this, a2);
  CSettler::TakeWaitList(a2);
  result = IAnimatedEntity::RegisterForLogicUpdate(1);
  this[6] = 1;
  return result;
}


// address=[0x156d9b0]
// Decompiled from int __thiscall CFleeRole::ConvertEventIntoGoal(CFleeRole *this, struct CSettler *a2, struct CEntityEvent *a3)
void  CFleeRole::ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3) {
  
  int result; // eax

  result = IEntity::FlagBits(a2, EntityFlag_Registered);
  if ( !result )
    return IAnimatedEntity::RegisterForLogicUpdate(1);
  return result;
}


