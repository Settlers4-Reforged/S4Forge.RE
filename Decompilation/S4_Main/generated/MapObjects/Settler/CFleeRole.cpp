#if FALSE
#include "CFleeRole.h"

// Definitions for class CFleeRole

// address=[0x1400a40]
// Decompiled from CFleeRole *__cdecl CFleeRole::New(int a1)
class CPersistence * __cdecl CFleeRole::New(std::istream & a1) {
  
  CFleeRole *C; // [esp+Ch] [ebp-10h]

  C = (CFleeRole *)operator new(0x2Cu);
  if ( C )
    return CFleeRole::CFleeRole(C, a1);
  else
    return 0;
}


// address=[0x156d370]
// Decompiled from CWalkingNormal *__thiscall CFleeRole::InitWalking(CFleeRole *this, IEntity *a2)
class CWalking *  CFleeRole::InitWalking(class CSettler * a2) {
  
  int v2; // eax
  CWalkingNormal *v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId(a2);
  v4 = CWalking::Create(0, v2);
  v4->InitB(v4, -1, 0);
  return v4;
}


// address=[0x156d3b0]
// Decompiled from void __thiscall CFleeRole::LogicUpdate(CFleeRole *this, CSettler *pSettler)
void  CFleeRole::LogicUpdate(class CSettler * pSettler) {
  
  int iX; // eax
  int v3; // esi
  int v4; // esi
  int v5; // eax
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int iY; // [esp-4h] [ebp-60h] BYREF
  auto_ptr_ISettlerRole *v13; // [esp+8h] [ebp-54h]
  int *p_iY; // [esp+Ch] [ebp-50h]
  int v15; // [esp+10h] [ebp-4Ch]
  int v16; // [esp+14h] [ebp-48h]
  int v17; // [esp+18h] [ebp-44h]
  ISettlerRole *SettlerRole; // [esp+1Ch] [ebp-40h]
  int v19; // [esp+20h] [ebp-3Ch]
  int v20; // [esp+24h] [ebp-38h]
  int iSectorId; // [esp+28h] [ebp-34h]
  int v22; // [esp+2Ch] [ebp-30h]
  auto_ptr_ISettlerRole a2; // [esp+30h] [ebp-2Ch] BYREF
  int i; // [esp+34h] [ebp-28h]
  int v25; // [esp+38h] [ebp-24h]
  unsigned __int16 *v26; // [esp+3Ch] [ebp-20h]
  int v27; // [esp+40h] [ebp-1Ch] BYREF
  int v28; // [esp+44h] [ebp-18h] BYREF
  char v30; // [esp+4Eh] [ebp-Eh]
  char NearestPlayerLand; // [esp+4Fh] [ebp-Dh]
  int v32; // [esp+58h] [ebp-4h]

  iY = IEntity::Y(pSettler);
  iX = IEntity::X(pSettler);
  v25 = CWorldManager::Index(iX, iY);
  v3 = ITiling::OwnerId(v25);
  if ( v3 == IEntity::OwnerId(pSettler) )
  {
    v19 = ITiling::EcoSectorId(v25);
    v26 = (unsigned __int16 *)CEcoSectorMgr::operator[](g_cESMgr, v19);
    v4 = CEcoSector::Owner(v26);
    if ( v4 != IEntity::OwnerId(pSettler)
      && BBSupportDbgReport(2, "MapObjects\\Settler\\FleeRole.cpp", 166, "rEcoSector.Owner()==_pSettler->OwnerId()") == 1 )
    {
      __debugbreak();
    }
    v5 = IEntity::Type(pSettler);
    CEcoSector::ChangeNrOfSettler((CEcoSector *)v26, v5, 1);
    iY = IEntity::Type(pSettler);
    v6 = IEntity::Race(pSettler);
    SettlerRole = CSettlerMgr::CreateSettlerRole(&g_cSettlerMgr, v6, iY);
    std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>(&a2, SettlerRole);
    v32 = 0;
    pSettler->ClearAllQueuedEvents(pSettler);
    iY = v7;
    p_iY = &iY;
    v13 = std::auto_ptr<ISettlerRole>::auto_ptr<ISettlerRole>((auto_ptr_ISettlerRole *)&iY, &a2);
    CSettler::NewRole(pSettler, (auto_ptr_ISettlerRole)iY);
    if ( !IEntity::FlagBits(pSettler, ENTITY_FLAG_Offered) )
    {
      iY = IEntity::EntityId(pSettler);
      v8 = IEntity::Type(pSettler);
      CEcoSector::SetSettlerOffer(v26, v8, iY);
    }
    CSettler::TakeWaitList(pSettler);
    v32 = -1;
    std::auto_ptr<ISettlerRole>::~auto_ptr<ISettlerRole>(&a2);
  }
  else
  {
    this->m_uSettlerWalk = ISettlerRole::SettlerWalk(this, pSettler);
    if ( (this->m_uSettlerWalk & 0x70) != 0 )
    {
      v27 = IEntity::X(pSettler);
      v28 = IEntity::Y(pSettler);
      NearestPlayerLand = 0;
      v30 = 0;
      if ( this->m_iWalkspeed < 5 )
      {
        v9 = IEntity::OwnerId(pSettler);
        NearestPlayerLand = CScanner::FindNearestPlayerLand(v9, &v27, &v28);
        if ( !NearestPlayerLand )
        {
          v30 = 1;
          iSectorId = ITiling::SectorId(v25);
          if ( iSectorId <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\FleeRole.cpp", 215, "iSectorId > 0") == 1 )
            __debugbreak();
          v17 = IEntity::X(pSettler);
          v16 = IEntity::Y(pSettler);
          for ( i = 0; i < 64; ++i )
          {
            v22 = (unsigned __int8)(CStateGame::Rand(g_pGame) + 0x80);
            v27 = v17 + CSpiralOffsets::DeltaX(v22);
            v28 = v16 + CSpiralOffsets::DeltaY(v22);
            if ( CWorldManager::InWorld(v27, v28) && CWorldManager::SectorId(v27, v28) == iSectorId )
            {
              NearestPlayerLand = 1;
              break;
            }
          }
        }
      }
      if ( NearestPlayerLand )
      {
        if ( v30 )
          v20 = 0x2000;
        else
          v20 = 0;
        v15 = v20;
        IAnimatedEntity::SetFrame(pSettler, 1u);
        v10 = Y16X16::PackXYFast(v27, v28);
        IMovingEntity::WalkToXY(pSettler, v10, v20);
        IMovingEntity::SetDisplacementCosts(pSettler, 5);
        IAnimatedEntity::RegisterForLogicUpdate(pSettler, 1);
        ++this->m_iWalkspeed;
      }
      else
      {
        v11 = IEntity::EntityId(pSettler);
        CSettlerMgr::DeleteSettler(&g_cSettlerMgr, v11);
      }
    }
    else if ( (this->m_uSettlerWalk & 8) != 0 )
    {
      IAnimatedEntity::RegisterForLogicUpdate(pSettler, 1);
    }
    else
    {
      IAnimatedEntity::RegisterForLogicUpdate(pSettler, 9);
    }
  }
}


// address=[0x156d730]
// Decompiled from void __thiscall CFleeRole::UpdateJob(CFleeRole *this, struct CSettler *a2)
void  CFleeRole::UpdateJob(class CSettler * a2) {
  
  ;
}


// address=[0x156d740]
// Decompiled from void __stdcall CFleeRole::PostLoadInit(IEntity *a1)
void  CFleeRole::PostLoadInit(class CSettler * a1) {
  
  CWarMap::AddEntity(a1);
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
// Decompiled from CFleeRole *__thiscall CFleeRole::CFleeRole(CFleeRole *this, struct std::istream *a2)
 CFleeRole::CFleeRole(std::istream & a2) {
  
  int fileFormatVersion; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  ISettlerRole::ISettlerRole(this, a2);
  v6 = 0;
  this->__vftable = (ISettlerRole_vtbl *)&CFleeRole::_vftable_;
  operator^<unsigned int>(a2, &fileFormatVersion);
  if ( fileFormatVersion != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CFleeRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v6 = -1;
  return this;
}


// address=[0x156d830]
// Decompiled from void __thiscall CFleeRole::Store(CFleeRole *this, struct std::ostream *a2)
void  CFleeRole::Store(std::ostream & a2) {
  
  int fileFormatVersion; // [esp+0h] [ebp-8h] BYREF

  ISettlerRole::Store(this, a2);
  fileFormatVersion = 1;
  operator^<unsigned int>(a2, &fileFormatVersion);
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
void  CFleeRole::LogicUpdateJob(class CSettler * a2) {
  
  ;
}


// address=[0x15885c0]
// Decompiled from int __cdecl CFleeRole::Load(struct std::istream *a1)
class CFleeRole * __cdecl CFleeRole::Load(std::istream & a1) {
  
  void **v1; // eax

  v1 = (void **)CPersistence::New(a1);
  return j____RTDynamicCast(v1, 0, &CPersistence__RTTI_Type_Descriptor_, &CFleeRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bebc]
// [Decompilation failed for static unsigned long CFleeRole::m_iClassID]

// address=[0x156d870]
// Decompiled from CFleeRole *__thiscall CFleeRole::CFleeRole(CFleeRole *this)
 CFleeRole::CFleeRole(void) {
  
  ISettlerRole::ISettlerRole(this);
  this->__vftable = (ISettlerRole_vtbl *)&CFleeRole::_vftable_;
  return this;
}


// address=[0x156d890]
// Decompiled from void __thiscall CFleeRole::~CFleeRole(_AFX_OLE_STATE *this)
 CFleeRole::~CFleeRole(void) {
  
  *(_DWORD *)this = &CFleeRole::_vftable_;
  ISettlerRole::~ISettlerRole(this);
}


// address=[0x156d8b0]
// Decompiled from void __thiscall CFleeRole::GetNextJob(CFleeRole *this, struct CSettler *a2)
void  CFleeRole::GetNextJob(class CSettler * a2) {
  
  this->TakeJob(this, a2);
}


// address=[0x156d8d0]
// Decompiled from void __thiscall CFleeRole::TakeJob(CFleeRole *this, IMovingEntity *a2)
void  CFleeRole::TakeJob(class CSettler * a2) {
  
  CEntityTask *pActualTask; // eax

  pActualTask = IMovingEntity::GetActualTask(a2);
  ISettlerRole::InitCommonTaskValues(this, a2, pActualTask);
  if ( this->m_iTask == 17 )
    IMovingEntity::SetDisplacementCosts(a2, 0);
}


// address=[0x156d910]
// Decompiled from void __thiscall CFleeRole::Init(ISettlerRole *this, IAnimatedEntity *a1)
void  CFleeRole::Init(class CSettler * a1) {
  
  if ( IEntity::FlagBits(a1, ENTITY_FLAG_Offered|ENTITY_FLAG_ATTACHED)
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
  CWarMap::AddEntity(a1);
  this->InitWalking(this, (CSettler *)a1);
  CSettler::TakeWaitList(a1);
  IAnimatedEntity::RegisterForLogicUpdate(a1, 1);
  this->m_iWalkspeed = 1;
}


// address=[0x156d9b0]
// Decompiled from void __thiscall CFleeRole::ConvertEventIntoGoal(CFleeRole *this, IAnimatedEntity *a2, struct CEntityEvent *a3)
void  CFleeRole::ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3) {
  
  if ( !IEntity::FlagBits(a2, ENTITY_FLAG_Registered) )
    IAnimatedEntity::RegisterForLogicUpdate(a2, 1);
}


#endif // Already implemented
