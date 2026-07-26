#include "CCarrierRole.h"

// Definitions for class CCarrierRole

// address=[0x13fffa0]
// Decompiled from int __cdecl CCarrierRole::New(int a1)
class CPersistence * __cdecl CCarrierRole::New(std::istream & a1) {
  
  if ( operator new(0x38u) )
    return CCarrierRole::CCarrierRole(a1);
  else
    return 0;
}


// address=[0x1563a30]
// Decompiled from CWalkingNormal *__thiscall CCarrierRole::InitWalking(CCarrierRole *this, IEntity *a2)
class CWalking *  CCarrierRole::InitWalking(class CSettler * a2) {
  
  int v2; // eax
  CWalkingNormal *v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId(a2);
  v4 = CWalking::Create(1, v2);
  v4->InitB(v4, -1, 0);
  return v4;
}


// address=[0x1563a70]
// Decompiled from void __thiscall CCarrierRole::LogicUpdate(CCarrierRole *this, struct CSettler *a2)
void  CCarrierRole::LogicUpdate(class CSettler * a2) {
  
  char *v2; // eax
  char *v3; // eax
  unsigned int v4; // eax
  std::list *v5; // eax
  DWORD v6; // [esp-4h] [ebp-Ch]

  if ( this->m_iTask == 17 )
  {
    ISettlerRole::LogicUpdate(this, a2);
    if ( (this->m_uSettlerWalk & 8) != 0
      && IMovingEntity::GetJobPart(a2) != 48
      && IMovingEntity::GetJobPart(a2) != 49
      && ++this->m_uTicksSinceLastJob >= (int)this->m_uNextJobTick )
    {
      this->m_uTicksSinceLastJob = 0;
      v2 = CStateGame::Random16(g_pGame);
      this->m_uNextJobTick = CRandom16::Rand((CRandom16 *)v2) % 0x12C + 300;
      v3 = CStateGame::Random16(g_pGame);
      v6 = CRandom16::Rand((CRandom16 *)v3) % 3 + 154;
      v4 = IEntity::Race(a2);
      v5 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v4, v6);
      a2->NewToDoList(a2, (int)v5, v6);
    }
  }
  else
  {
    this->LogicUpdateJob(this, a2);
  }
}


// address=[0x1563b90]
// Decompiled from void __thiscall CCarrierRole::LogicUpdateJob(CCarrierRole *this, struct CSettler *pSettler)
void  CCarrierRole::LogicUpdateJob(class CSettler * pSettler) {
  
  int v2; // eax
  IEntity *v3; // eax
  IEntity *m_uHomeEntityId; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int m_uGood; // esi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  CPile *v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // [esp-Ch] [ebp-38h]
  int v26; // [esp-8h] [ebp-34h]
  int v27; // [esp-4h] [ebp-30h]
  int v28; // [esp-4h] [ebp-30h]
  CPile *v29; // [esp+4h] [ebp-28h]
  int v30; // [esp+8h] [ebp-24h]
  int a2; // [esp+Ch] [ebp-20h]
  int v32; // [esp+10h] [ebp-1Ch]
  CPile *pPile; // [esp+14h] [ebp-18h] MAPDST
  CVehicle *v35; // [esp+1Ch] [ebp-10h]

  switch ( this->m_iTask )
  {
    case 6:
      IMovingEntity::SetDistance(pSettler, 0);
      this->Go(this, pSettler);
      if ( !IEntity::FlagBits(pSettler, ENTITY_FLAG_Registered) && debug )
      {
        if ( DEBUG_FLAGS[dword_4152098] )
        {
          v2 = IEntity::ID(pSettler);
          BBSupportTracePrintF(0, "LogicUpdateJob - Go - not registered settler %u", v2);
        }
      }
      break;
    case 0x10:
      this->GetNextJob(this, pSettler);
      break;
    case 0x14:
      v30 = this->m_uCycleFrames / 2;
      this->m_iWalkspeed -= v30;
      if ( this->m_iWalkspeed < v30 )
      {
        if ( !CCarrierRole::NextSettlerType(this) )
          goto LABEL_91;
      }
      else
      {
        if ( !CCarrierRole::NextSettlerType(this) || !ISettlerRole::SourcePileId(this) )
          goto LABEL_91;
        v23 = ISettlerRole::SourcePileId(this);
        pPile = CPileMgr::GetPilePtr(v23);
        if ( !pPile && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 509, "pPile != 0") == 1 )
          __debugbreak();
        this->m_uGood = pPile->GetGoodType();
        if ( !this->m_uGood && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 511, "m_uGood > 0") == 1 )
          __debugbreak();
        v24 = IEntity::EntityId(pSettler);
        CPile::ChangeAmountAndDetach(pPile, v24);
        IAnimatedEntity::RegisterForLogicUpdate(pSettler, v30);
      }
      break;
    case 0x15:
      if ( !CCarrierRole::DestinationPileId(this) )
        goto LABEL_91;
      v32 = this->m_uCycleFrames / 2;
      this->m_iWalkspeed -= v32;
      if ( this->m_iWalkspeed < v32 )
      {
        if ( debug && DEBUG_FLAGS[g_iCarrierDebugSlot] )
        {
          v13 = IEntity::ID(pSettler);
          BBSupportTracePrintF(0, "Carier Nr %u put_good", v13);
        }
        this->SetFree(this, pSettler, -1);
        CCarrierRole::TryToGoHome(this, pSettler);
        if ( !IEntity::FlagBits(pSettler, ENTITY_FLAG_Registered) && debug && DEBUG_FLAGS[dword_4152098] )
        {
          v14 = IEntity::ID(pSettler);
          BBSupportTracePrintF(0, "LogicUpdateJob - PutGood ready - not registered settler %u", v14);
        }
      }
      else
      {
        v9 = CCarrierRole::DestinationPileId(this);
        pPile = CPileMgr::GetPilePtr(v9);
        if ( !pPile && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 392, "pPile != 0") == 1 )
          __debugbreak();
        if ( pPile )
        {
          m_uGood = this->m_uGood;
          if ( m_uGood != pPile->GetGoodType()
            && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 397, "m_uGood == pPile->GetGoodType()") == 1 )
          {
            __debugbreak();
          }
          v11 = IEntity::EntityId(pSettler);
          CPile::ChangeAmountAndDetach(pPile, v11);
        }
        this->m_uGood = 0;
        IAnimatedEntity::RegisterForLogicUpdate(pSettler, v32 - 1);
        if ( !IEntity::FlagBits(pSettler, ENTITY_FLAG_Registered) && debug && DEBUG_FLAGS[dword_4152098] )
        {
          v12 = IEntity::ID(pSettler);
          BBSupportTracePrintF(0, "LogicUpdateJob - PutGood - not registered settler %u", v12);
        }
      }
      break;
    case 0x16:
      a2 = this->m_uCycleFrames / 2;
      this->m_iWalkspeed -= a2;
      if ( this->m_iWalkspeed < a2 )
      {
        this->GetNextJob(this, pSettler);
        if ( !IEntity::FlagBits(pSettler, ENTITY_FLAG_Registered) && debug && DEBUG_FLAGS[dword_4152098] )
        {
          v22 = IEntity::ID(pSettler);
          BBSupportTracePrintF(0, "LogicUpdateJob - GetGood ready - not registered settler %u", v22);
        }
      }
      else
      {
        if ( !ISettlerRole::SourcePileId(this) )
          goto LABEL_91;
        v15 = ISettlerRole::SourcePileId(this);
        pPile = CPileMgr::GetPilePtr(v15);
        if ( !pPile && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 447, "pPile != 0") == 1 )
          __debugbreak();
        this->m_uGood = pPile->GetGoodType();
        if ( !this->m_uGood && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 449, "m_uGood > 0") == 1 )
          __debugbreak();
        if ( debug && DEBUG_FLAGS[g_iCarrierDebugSlot] )
        {
          v16 = ISettlerRole::SourcePileId(this);
          v29 = CPileMgr::operator[](v16);
          v17 = ISettlerRole::SourcePileId(this);
          v18 = CPileMgr::operator[](v17);
          v28 = CPile::AmountLeaving(v18);
          v26 = ((int (__stdcall *)())v29->Amount)();
          v25 = ISettlerRole::SourcePileId(this);
          v19 = IEntity::ID(pSettler);
          BBSupportTracePrintF(
            0,
            "Carrier LU GET_GOOD - Detach settler %u from srcpile %u amount before %u amountleaving before %u",
            v19,
            v25,
            v26,
            v28);
        }
        v20 = IEntity::EntityId(pSettler);
        CPile::ChangeAmountAndDetach(pPile, v20);
        IAnimatedEntity::RegisterForLogicUpdate(pSettler, a2);
        if ( !IEntity::FlagBits(pSettler, ENTITY_FLAG_Registered) && debug && DEBUG_FLAGS[dword_4152098] )
        {
          v21 = IEntity::ID(pSettler);
          BBSupportTracePrintF(0, "LogicUpdateJob - GetGood - not registered settler %u", v21);
        }
      }
      break;
    case 0x17:
      if ( ISettlerRole::HomeEntityId(this) )
      {
        v3 = CMapObjectMgr::EntityPtr(this->m_uHomeEntityId);
        if ( IEntity::ObjType(v3) != CATAPULT_OBJ )
        {
          m_uHomeEntityId = CMapObjectMgr::EntityPtr(this->m_uHomeEntityId);
          if ( IEntity::ObjType(m_uHomeEntityId) != SHIP_OBJ
            && BBSupportDbgReport(
                 2,
                 "MapObjects\\Settler\\CarrierRole.cpp",
                 345,
                 "(g_pMapObjectMgr->EntityPtr(m_uHomeEntityId))->ObjType() == CATAPULT_OBJ || (g_pMapObjectMgr->EntityPtr"
                 "(m_uHomeEntityId))->ObjType() == SHIP_OBJ") == 1 )
          {
            __debugbreak();
          }
        }
        if ( debug && DEBUG_FLAGS[g_iCarrierDebugSlot] )
        {
          v5 = IEntity::ID(pSettler);
          BBSupportTracePrintF(0, "Carrier nr %u load_good", v5);
        }
        if ( debug && DEBUG_FLAGS[g_iCarrierDebugSlot] )
        {
          v27 = this->m_uHomeEntityId;
          v6 = IEntity::ID(pSettler);
          BBSupportTracePrintF(0, "Carrier LU LOAD_GOOD - Detach settler %u from vehicle %u", v6, v27);
        }
        v35 = CVehicleMgr::operator[](this->m_uHomeEntityId);
        v35->GoodArrived(v35, this->m_uGood, 1);
        v7 = IEntity::ID(pSettler);
        v35->Detach(v35, v7);
        this->m_uGood = 0;
        this->SetFree(this, pSettler, -1);
        CCarrierRole::TryToGoHome(this, pSettler);
        if ( !IEntity::FlagBits(pSettler, ENTITY_FLAG_Registered) && debug && DEBUG_FLAGS[dword_4152098] )
        {
          v8 = IEntity::ID(pSettler);
          BBSupportTracePrintF(0, "LogicUpdateJob - LoadGood ready - not registered settler %u", v8);
        }
      }
      else
      {
LABEL_91:
        this->SetFree(this, pSettler, -1);
      }
      break;
    default:
      if ( debug && DEBUG_FLAGS[g_iCarrierDebugSlot] )
        BBSupportTracePrintF(0, "LogicUpdateJob Carrier - unknown task %u", this->m_iTask);
      break;
  }
}


// address=[0x1564340]
// Decompiled from void __thiscall CCarrierRole::UpdateJob(CCarrierRole *this, struct CSettler *a2)
void  CCarrierRole::UpdateJob(class CSettler * a2) {
  
  char v2; // [esp+8h] [ebp-1Ch]
  int m_uTick; // [esp+Ch] [ebp-18h]
  int v4; // [esp+10h] [ebp-14h]
  int v5; // [esp+14h] [ebp-10h]
  int uLoopFrame; // [esp+18h] [ebp-Ch]

  switch ( this->m_iTask )
  {
    case 0x14:
    case 0x16:
    case 0x17:
      uLoopFrame = this->m_uCycleFrames;
      v5 = this->m_uTick + IAnimatedEntity::Frame(a2);
      if ( v5 >= uLoopFrame )
      {
        if ( uLoopFrame <= 0 )
          v2 = 0;
        else
          v2 = uLoopFrame - 1;
        LOBYTE(v5) = v2;
      }
      IAnimatedEntity::SetFrame(a2, v5);
      break;
    case 0x15:
      v4 = IAnimatedEntity::Frame(a2);
      m_uTick = this->m_uTick;
      if ( v4 <= m_uTick )
        IAnimatedEntity::SetFrame(a2, 0);
      else
        IAnimatedEntity::SetFrame(a2, v4 - m_uTick);
      break;
    default:
      return;
  }
}


// address=[0x1564420]
// Decompiled from void __stdcall CCarrierRole::PostLoadInit(IEntity *a1)
void  CCarrierRole::PostLoadInit(class CSettler * a1) {
  
  CWarMap::AddEntity(a1);
}


// address=[0x1564440]
// Decompiled from void __thiscall CCarrierRole::SetObserverTarget(CCarrierRole *this, int a2, __int16 a3)
void  CCarrierRole::SetObserverTarget(enum T_OBSERVER_TARGET a2, int a3) {
  
  switch ( a2 )
  {
    case 0:
      this->m_uHomeEntityId = a3;
      break;
    case 1:
      this->m_iTarget1 = a3;
      break;
    case 2:
      this->m_uSourcePileId = a3;
      break;
    case 3:
      this->m_iSourcePile2 = a3;
      break;
    case 4:
      this->m_iSourcePile3 = a3;
      break;
    default:
      if ( BBSupportDbgReport(
             1,
             "MapObjects\\Settler\\CarrierRole.cpp",
             1642,
             "CCarrierRole::SetObserverTarget(): Invalid target type!") == 1 )
        __debugbreak();
      break;
  }
}


// address=[0x15644e0]
// Decompiled from int __thiscall CCarrierRole::GetObserverTarget(CCarrierRole *this, int a2)
int  CCarrierRole::GetObserverTarget(enum T_OBSERVER_TARGET a2) {
  
  int result; // eax

  switch ( a2 )
  {
    case 0:
      result = this->m_uHomeEntityId;
      break;
    case 1:
      result = this->m_iTarget1;
      break;
    case 2:
      result = this->m_uSourcePileId;
      break;
    case 3:
      result = this->m_iSourcePile2;
      break;
    case 4:
      result = this->m_iSourcePile3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}


// address=[0x1564550]
// Decompiled from void __thiscall CCarrierRole::UpdateCatapultPosition(CCarrierRole *this, DWORD a2)
void  CCarrierRole::UpdateCatapultPosition(int a2) {
  
  CSettler *pSettler; // [esp+4h] [ebp-4h]

  pSettler = CSettlerMgr::GetSettlerPtr(&g_cSettlerMgr, this->m_uAttachedSettlerId);
  if ( !pSettler && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1748, "pSettler!=NULL") == 1 )
    __debugbreak();
  if ( pSettler )
    ISettlerRole::NewDestination(this, pSettler, a2, 0);
}


// address=[0x15645c0]
// Decompiled from CCarrierRole *__thiscall CCarrierRole::CCarrierRole(CCarrierRole *this, struct std::istream *stream)
 CCarrierRole::CCarrierRole(std::istream & stream) {
  
  unsigned int fileFormatVersion; // [esp+4h] [ebp-1Ch] MAPDST BYREF
  int pExceptionObject; // [esp+8h] [ebp-18h] BYREF
  int v7; // [esp+1Ch] [ebp-4h]

  ISettlerRole::ISettlerRole(this, stream);
  v7 = 0;
  this->__vftable = (ISettlerRole_vtbl *)&CCarrierRole::_vftable_;
  operator^<unsigned int>(stream, &fileFormatVersion);
  switch ( fileFormatVersion )
  {
    case 1u:
      operator^<unsigned char>(stream, &this->m_uGood);
      operator^<unsigned char>(stream, &this->m_uNextSettlerType);
      operator^<unsigned short>(stream, &this->m_uSourcePileId);
      operator^<unsigned short>(stream, &this->m_iTarget1);
      break;
    case 2u:
      operator^<unsigned char>(stream, &this->m_uGood);
      operator^<unsigned char>(stream, &this->m_uNextSettlerType);
      operator^<unsigned short>(stream, &this->m_uSourcePileId);
      operator^<unsigned short>(stream, &this->m_iTarget1);
      operator^<unsigned short>(stream, &this->m_iSourcePile2);
      operator^<unsigned short>(stream, &this->m_iSourcePile3);
      break;
    case 3u:
      operator^<unsigned char>(stream, &this->m_uGood);
      operator^<unsigned char>(stream, &this->m_uNextSettlerType);
      operator^<unsigned short>(stream, &this->m_uSourcePileId);
      operator^<unsigned short>(stream, &this->m_iTarget1);
      operator^<unsigned short>(stream, &this->m_iSourcePile2);
      operator^<unsigned short>(stream, &this->m_iSourcePile3);
      operator^<unsigned short>(stream, &this->m_uTicksSinceLastJob);
      operator^<unsigned short>(stream, &this->m_uNextJobTick);
      break;
    default:
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CCarrierRole");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  return this;
}


// address=[0x15647e0]
// Decompiled from void __thiscall CCarrierRole::Store(CCarrierRole *this, struct std::ostream *a1)
void  CCarrierRole::Store(std::ostream & a1) {
  
  unsigned int v2; // [esp+0h] [ebp-8h] BYREF

  ISettlerRole::Store(this, a1);
  v2 = 3;
  operator^<unsigned int>(a1, &v2);
  operator^<unsigned char>(a1, &this->m_uGood);
  operator^<unsigned char>(a1, &this->m_uNextSettlerType);
  operator^<unsigned short>(a1, &this->m_uSourcePileId);
  operator^<unsigned short>(a1, &this->m_iTarget1);
  operator^<unsigned short>(a1, &this->m_iSourcePile2);
  operator^<unsigned short>(a1, &this->m_iSourcePile3);
  operator^<unsigned short>(a1, &this->m_uTicksSinceLastJob);
  operator^<unsigned short>(a1, &this->m_uNextJobTick);
}


// address=[0x1567060]
// Decompiled from int __thiscall CCarrierRole::ClassID(CCarrierRole *this)
unsigned long  CCarrierRole::ClassID(void)const {
  
  return CCarrierRole::m_iClassID;
}


// address=[0x15670c0]
// Decompiled from int __thiscall CCarrierRole::GetSettlerRole(CCarrierRole *this)
int  CCarrierRole::GetSettlerRole(void)const {
  
  return 1;
}


// address=[0x1588480]
// Decompiled from int __cdecl CCarrierRole::Load(struct std::istream *a1)
class CCarrierRole * __cdecl CCarrierRole::Load(std::istream & a1) {
  
  void **v1; // eax

  v1 = (void **)CPersistence::New(a1);
  return j____RTDynamicCast(v1, 0, &CPersistence__RTTI_Type_Descriptor_, &CCarrierRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bea8]
// [Decompilation failed for static unsigned long CCarrierRole::m_iClassID]

// address=[0x15648b0]
// Decompiled from int __thiscall CCarrierRole::GetNextSettlerType(CCarrierRole *this)
int  CCarrierRole::GetNextSettlerType(void) {
  
  return this->m_uNextSettlerType;
}


// address=[0x15648d0]
// Decompiled from void __thiscall CCarrierRole::SetNextSettlerType(CCarrierRole *this, unsigned __int8 a2)
bool  CCarrierRole::SetNextSettlerType(int a2) {
  
  this->m_uNextSettlerType = a2;
}


// address=[0x15648f0]
// Decompiled from void __thiscall CCarrierRole::ChangeToNextType(CCarrierRole *this, CSettler *a2, char a3, char a4)
void  CCarrierRole::ChangeToNextType(class CSettler * a2, bool a3, bool a4) {
  
  int v4; // eax
  int v5; // eax
  int v6; // [esp-4h] [ebp-14h]
  unsigned int SettlerType; // [esp+0h] [ebp-10h]
  struct CEcoSector *v8; // [esp+4h] [ebp-Ch]
  int v9; // [esp+8h] [ebp-8h]

  if ( !CCarrierRole::NextSettlerType(this)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1724, "NextSettlerType() != 0") == 1 )
  {
    __debugbreak();
  }
  SettlerType = CCarrierRole::NextSettlerType(this);
  v6 = IEntity::Y(a2);
  v4 = IEntity::X(a2);
  v9 = CWorldManager::EcoSectorId(v4, v6);
  v8 = CEcoSectorMgr::operator[](g_cESMgr, v9);
  v5 = IEntity::EntityId(a2);
  CEcoSector::ResetCarrierNextSettlerTypeAndDecrementOrder(v8, v5);
  if ( CCarrierRole::NextSettlerType(this)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1733, "NextSettlerType() == 0") == 1 )
  {
    __debugbreak();
  }
  this->m_uNextSettlerType = 0;
  CSettler::ChangeType(a2, SettlerType, a3, a4);
}


// address=[0x15649c0]
// Decompiled from CCarrierRole *__thiscall CCarrierRole::CCarrierRole(CCarrierRole *this)
 CCarrierRole::CCarrierRole(void) {
  
  char *v1; // eax

  ISettlerRole::ISettlerRole(this);
  this->__vftable = (ISettlerRole_vtbl *)&CCarrierRole::_vftable_;
  this->m_uGood = 0;
  this->m_uNextSettlerType = 0;
  this->m_iTarget1 = 0;
  this->m_iSourcePile2 = 0;
  this->m_iSourcePile3 = 0;
  this->m_uTicksSinceLastJob = 0;
  v1 = CStateGame::Random16(g_pGame);
  this->m_uNextJobTick = CRandom16::Rand((CRandom16 *)v1) % 0x12C + 300;
  return this;
}


// address=[0x1564a80]
// Decompiled from ISettlerRole *__thiscall CCarrierRole::~CCarrierRole(CCarrierRole *this)
 CCarrierRole::~CCarrierRole(void) {
  
  this->__vftable = (ISettlerRole_vtbl *)&CCarrierRole::_vftable_;
  return ISettlerRole::~ISettlerRole(this);
}


// address=[0x1564aa0]
// Decompiled from void __thiscall CCarrierRole::GetNextJob(CCarrierRole *this, struct CSettler *a2)
void  CCarrierRole::GetNextJob(class CSettler * a2) {
  
  IMovingEntity::IncToDoListIter(a2);
  if ( IMovingEntity::IsEndIter(a2) )
    this->SetFree(this, a2, -1);
  else
    this->TakeJob(this, a2);
}


// address=[0x1564af0]
// Decompiled from void __thiscall CCarrierRole::TakeJob(CCarrierRole *this, struct CSettler *pSettler)
void  CCarrierRole::TakeJob(class CSettler * pSettler) {
  
  CEntityTask *ActualTask; // eax
  DWORD v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  IEntity *v9; // eax
  int v10; // eax
  __int16 v11; // ax
  int v12; // eax
  int v13; // eax
  IEntity *v14; // eax
  __int16 v15; // ax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int m_uGood; // [esp-4h] [ebp-C8h]
  int SettlerType; // [esp-4h] [ebp-C8h]
  CEntityEvent v22; // [esp+4h] [ebp-C0h] BYREF
  CEntityEvent v23; // [esp+1Ch] [ebp-A8h] BYREF
  _BYTE v24[20]; // [esp+34h] [ebp-90h] BYREF
  struct CEntityEvent *v25; // [esp+48h] [ebp-7Ch]
  struct CEntityEvent *v26; // [esp+4Ch] [ebp-78h]
  int v27; // [esp+50h] [ebp-74h]
  int v28; // [esp+54h] [ebp-70h]
  int v29; // [esp+58h] [ebp-6Ch]
  int a1; // [esp+5Ch] [ebp-68h]
  IEntity *v31; // [esp+60h] [ebp-64h]
  int v33; // [esp+68h] [ebp-5Ch]
  int v34; // [esp+6Ch] [ebp-58h]
  struct CEntityEvent *v35; // [esp+70h] [ebp-54h]
  struct CEntityEvent *v36; // [esp+74h] [ebp-50h]
  int v37; // [esp+78h] [ebp-4Ch]
  int v38; // [esp+7Ch] [ebp-48h]
  int a2; // [esp+80h] [ebp-44h]
  int WorkingAreaPackedXY; // [esp+84h] [ebp-40h]
  int v41; // [esp+8Ch] [ebp-38h] MAPDST
  int v42; // [esp+90h] [ebp-34h]
  int v43; // [esp+94h] [ebp-30h]
  BOOL v44; // [esp+98h] [ebp-2Ch]
  int v45; // [esp+9Ch] [ebp-28h] BYREF
  int v46; // [esp+A0h] [ebp-24h] BYREF
  CBuilding *rBuilding; // [esp+A4h] [ebp-20h]
  bool v48; // [esp+ABh] [ebp-19h]
  int v49; // [esp+ACh] [ebp-18h]
  IEntity *pHomeEntity; // [esp+B0h] [ebp-14h]
  CCart *v51; // [esp+B0h] [ebp-14h] SPLIT
  int v53; // [esp+C0h] [ebp-4h]

  v44 = IEntity::FlagBits(pSettler, (EntityFlag)0x100000) != 0;
  v48 = v44;
  IEntity::ClearFlagBits(pSettler, (EntityFlag)0x100000);
  ActualTask = IMovingEntity::GetActualTask(pSettler);
  ISettlerRole::InitCommonTaskValues(this, pSettler, ActualTask);
  v49 = this->m_iTask - 10;
  switch ( v49 )
  {
    case 0:
    case 27:
      if ( this->m_uGood )
      {
        v15 = IAnimatedEntity::JobPart(pSettler);
        IAnimatedEntity::SetJobPart(pSettler, this->m_uGood + v15);
      }
      IAnimatedEntity::SetFrame(pSettler, 1u);
      v33 = this->m_iDestinationOffsetX + Y16X16::UnpackXFast(this->m_iDestinationPosition);
      v34 = this->m_iDestinationOffsetY + Y16X16::UnpackYFast(this->m_iDestinationPosition);
      this->m_iDestinationPosition = Y16X16::PackXYFast(v33, v34);
      if ( this->m_iTask == 37 )
        v41 = 0x2000;
      else
        v41 = 0;
      IMovingEntity::WalkToXY(pSettler, this->m_iDestinationPosition, v41);
      this->m_iTask = 6;
      IMovingEntity::SetDisplacementCosts(pSettler, 5);
      this->Go(this, pSettler);
      return;
    case 6:
      IMovingEntity::SetDisplacementCosts(pSettler, 10);
      IAnimatedEntity::SetFrame(pSettler, 0);
      IAnimatedEntity::RegisterForLogicUpdate(pSettler, this->m_iWalkspeed);
      return;
    case 7:
      IMovingEntity::SetDisplacementCosts(pSettler, 0);
      v3 = CStateGame::Rand(g_pGame);
      IAnimatedEntity::RegisterForLogicUpdate(pSettler, v3 % 4 + 1);
      return;
    case 8:
      if ( debug && DEBUG_FLAGS[g_iCarrierDebugSlot] )
      {
        v7 = IEntity::ID(pSettler);
        BBSupportTracePrintF(0, "Carier %u TakeJob go to source pile", v7);
      }
      if ( !ISettlerRole::SourcePileId(this) )
        goto LABEL_27;
      v8 = ISettlerRole::SourcePileId(this);
      v9 = CMapObjectMgr::EntityPtr(v8);
      v38 = IEntity::PackedXY(v9);
      this->m_iStartPosition = IEntity::PackedXY(pSettler);
      IMovingEntity::WalkToXY(pSettler, v38, 4096);
      this->m_iTask = 6;
      IMovingEntity::SetDisplacementCosts(pSettler, 5);
      this->Go(this, pSettler);
      return;
    case 9:
      if ( !CCarrierRole::DestinationPileId(this) )
        goto LABEL_27;
      v10 = CCarrierRole::DestinationPileId(this);
      if ( !CMapObjectMgr::EntityPtr(v10) )
        goto LABEL_27;
      v11 = IAnimatedEntity::JobPart(pSettler);
      IAnimatedEntity::SetJobPart(pSettler, this->m_uGood + v11);
      if ( debug && DEBUG_FLAGS[g_iCarrierDebugSlot] )
      {
        m_uGood = this->m_uGood;
        v12 = IEntity::ID(pSettler);
        BBSupportTracePrintF(0, "Carier %u TakeJob go to dest pile good %u", v12, m_uGood);
      }
      v13 = CCarrierRole::DestinationPileId(this);
      v14 = CMapObjectMgr::EntityPtr(v13);
      v37 = IEntity::PackedXY(v14);
      IMovingEntity::WalkToXY(pSettler, v37, 4096);
      this->m_iTask = 6;
      IMovingEntity::SetDisplacementCosts(pSettler, 5);
      this->Go(this, pSettler);
      return;
    case 10:
      goto LABEL_16;
    case 11:
      if ( debug && DEBUG_FLAGS[g_iCarrierDebugSlot] )
      {
        v4 = IEntity::ID(pSettler);
        BBSupportTracePrintF(0, "Carier %u TakeJob put_good", v4);
      }
      IMovingEntity::SetDisplacementCosts(pSettler, 10);
      if ( this->m_uCycleFrames )
        v43 = this->m_uCycleFrames - 1;
      else
        v43 = 0;
      a2 = v43;
      IAnimatedEntity::SetFrame(pSettler, v43);
      IAnimatedEntity::RegisterForLogicUpdate(pSettler, this->m_iWalkspeed / 2);
      return;
    case 12:
      if ( debug && DEBUG_FLAGS[g_iCarrierDebugSlot] )
      {
        v5 = IEntity::ID(pSettler);
        BBSupportTracePrintF(0, "Carier %u TakeJob get_good", v5);
      }
LABEL_16:
      IMovingEntity::SetDisplacementCosts(pSettler, 10);
      IAnimatedEntity::RegisterForLogicUpdate(pSettler, this->m_iWalkspeed / 2 - 1);
      return;
    case 13:
      if ( debug && DEBUG_FLAGS[g_iCarrierDebugSlot] )
      {
        v6 = IEntity::ID(pSettler);
        BBSupportTracePrintF(0, "Carier %u TakeJob load_good", v6);
      }
      IMovingEntity::SetDisplacementCosts(pSettler, 10);
      IAnimatedEntity::RegisterForLogicUpdate(pSettler, this->m_iWalkspeed);
      return;
    case 14:
      if ( !this->m_uHomeEntityId )
        return;
      IMovingEntity::SetDisplacementCosts(pSettler, 10);
      IEntity::ClearFlagBits(pSettler, ENTITY_FLAG_Visible);
      if ( !g_pMapObjectMgr
        && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 831, "g_pMapObjectMgr!= NULL") == 1 )
      {
        __debugbreak();
      }
      pHomeEntity = CMapObjectMgr::EntityPtr(this->m_uHomeEntityId);
      if ( !pHomeEntity && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 833, "pEntity!= NULL") == 1 )
        __debugbreak();
      if ( !pHomeEntity )
        return;
      if ( IEntity::ObjType(pHomeEntity) == BUILDING_OBJ )
      {
        if ( !j____RTDynamicCast(
                (void **)&pHomeEntity->__vftable,
                0,
                &IEntity__RTTI_Type_Descriptor_,
                &CBuilding__RTTI_Type_Descriptor_,
                0)
          && BBSupportDbgReport(
               2,
               "MapObjects\\Settler\\CarrierRole.cpp",
               838,
               "dynamic_cast<CBuilding*>(pEntity)!=NULL") == 1 )
        {
          __debugbreak();
        }
        v31 = pHomeEntity;
        v16 = IEntity::ID(pSettler);
        CBuilding::SettlerEnter((CBuilding *)pHomeEntity, v16);
      }
      if ( IEntity::ObjType(pHomeEntity) != CATAPULT_OBJ )
        return;
      if ( !j____RTDynamicCast(
              (void **)&pHomeEntity->__vftable,
              0,
              &IEntity__RTTI_Type_Descriptor_,
              &CCart__RTTI_Type_Descriptor_,
              0)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 844, "dynamic_cast<CCart*>(pEntity)!=NULL") == 1 )
      {
        __debugbreak();
      }
      v17 = IEntity::ID(pSettler);
      v51->EntityEnter(v51, v17);
      return;
    case 16:
      if ( !CCarrierRole::NextSettlerType(this) )
        goto LABEL_27;
      if ( ISettlerRole::HomeEntityId(this)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 746, "HomeEntityId() == 0") == 1 )
      {
        __debugbreak();
      }
      CCarrierRole::ChangeToNextType(this, pSettler, 1, 1);
      break;
    case 28:
      if ( !CCarrierRole::NextSettlerType(this)
        || !ISettlerRole::HomeEntityId(this)
        || !ISettlerRole::SourcePileId(this)
        || !CCarrierRole::SourcePileId2(this)
        || !CCarrierRole::SourcePileId3(this) )
      {
        goto LABEL_27;
      }
      a1 = ISettlerRole::HomeEntityId(this);
      v29 = IEntity::EntityId(pSettler);
      rBuilding = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, a1);
      rBuilding->Detach(rBuilding, v29);
      this->m_uAttachedSettlerId = IEntity::EntityId(pSettler);
      ISettlerRole::DetachFromPile(this, pSettler, 2, 1);
      ISettlerRole::DetachFromPile(this, pSettler, 3, 1);
      ISettlerRole::DetachFromPile(this, pSettler, 4, 1);
      SettlerType = CCarrierRole::NextSettlerType(this);
      v18 = IEntity::OwnerId(pSettler);
      CStatistic::AddProducedSettler(&g_cStatistic, v18, SettlerType);
      CCarrierRole::ChangeToNextType(this, pSettler, 1, 0);
      if ( IAnimatedEntity::EventQueueEmpty(pSettler) )
      {
        WorkingAreaPackedXY = CBuilding::GetWorkingAreaPackedXY(rBuilding);
        v45 = Y16X16::UnpackXFast(WorkingAreaPackedXY);
        v46 = Y16X16::UnpackYFast(WorkingAreaPackedXY);
        v19 = IEntity::WorldIdx(pSettler);
        v28 = ITiling::SectorId(v19);
        CSectorSpiralWalk::CSectorSpiralWalk((CSectorSpiralWalk *)v24, v45, v46, 15, v28);
        if ( CSectorSpiralWalk::NextXY((CSectorSpiralWalk *)v24, &v45, &v46) )
        {
          v27 = Y16X16::PackXYFast(v45, v46);
          v26 = CEntityEvent::CEntityEvent(&v22, 0x11u, 13, 0, v27, 0);
          v25 = v26;
          v53 = 1;
          pSettler->SetEvent(pSettler, v26);
          v53 = -1;
          CEntityEvent::~CEntityEvent(&v22);
        }
      }
      break;
    case 29:
      if ( CCarrierRole::NextSettlerType(this) && ISettlerRole::HomeEntityId(this) )
      {
        v42 = ISettlerRole::HomeEntityId(this);
        if ( !IEntity::FlagBits(pSettler, ENTITY_FLAG_ATTACHED)
          && BBSupportDbgReport(
               2,
               "MapObjects\\Settler\\CarrierRole.cpp",
               774,
               "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED) != 0") == 1 )
        {
          __debugbreak();
        }
        CCarrierRole::ChangeToNextType(this, pSettler, 1, 0);
        if ( !IEntity::FlagBits(pSettler, ENTITY_FLAG_ATTACHED)
          && BBSupportDbgReport(
               2,
               "MapObjects\\Settler\\CarrierRole.cpp",
               780,
               "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED) != 0") == 1 )
        {
          __debugbreak();
        }
        CSettler::SetBuilding(pSettler, v42);
        v36 = CEntityEvent::CEntityEvent(&v23, 1u, 0, v42, 0, 0);
        v35 = v36;
        v53 = 0;
        pSettler->SetEvent(pSettler, v36);
        v53 = -1;
        CEntityEvent::~CEntityEvent(&v23);
      }
      else
      {
LABEL_27:
        this->SetFree(this, pSettler, -1);
      }
      break;
    default:
      if ( debug && DEBUG_FLAGS[g_iCarrierDebugSlot] )
        BBSupportTracePrint(0, "Carrier TakeJob - unknown job");
      IAnimatedEntity::RegisterForLogicUpdate(pSettler, 3);
      break;
  }
}


// address=[0x1565510]
// Decompiled from void __thiscall CCarrierRole::Init(CCarrierRole *this, IEntity *_pSettler)
void  CCarrierRole::Init(class CSettler * _pSettler) {
  
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int v5; // [esp-4h] [ebp-14h]
  CEcoSector *v6; // [esp+4h] [ebp-Ch]
  int v7; // [esp+8h] [ebp-8h]

  if ( !_pSettler && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 203, "_pSettler!=NULL") == 1 )
    __debugbreak();
  if ( IEntity::FlagBits(_pSettler, ENTITY_FLAG_Offered)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 204, "!_pSettler->FlagBits(ENTITY_FLAG_OFFERED)") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uHomeEntityId
    && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 205, "!m_uHomeEntityId") == 1 )
  {
    __debugbreak();
  }
  this->m_uAttachedSettlerId = IEntity::ID(_pSettler);
  this->m_uGood = 0;
  this->m_uNextSettlerType = 0;
  this->m_iTarget1 = 0;
  this->m_iSourcePile2 = 0;
  this->m_iSourcePile3 = 0;
  this->m_uHomeEntityId = 0;
  this->m_uSourcePileId = 0;
  CWarMap::AddEntity(_pSettler);
  IEntity::ClearFlagBits(_pSettler, ENTITY_FLAG_VulnerableMask|ENTITY_FLAG_Selectable|ENTITY_FLAG_Selected);
  v2 = IEntity::WorldIdx(_pSettler);
  v7 = CWorldManager::EcoSectorId(v2);
  if ( v7 )
  {
    v6 = CEcoSectorMgr::operator[](g_cESMgr, v7);
    v3 = CEcoSector::Owner(v6);
    if ( v3 == IEntity::OwnerId(_pSettler) )
    {
      v5 = IEntity::ID(_pSettler);
      v4 = IEntity::Type(_pSettler);
      CEcoSector::SetSettlerOffer(v6, v4, v5);
    }
  }
}


// address=[0x1565660]
// Decompiled from void __thiscall CCarrierRole::ConvertEventIntoGoal(CCarrierRole *this, CSettler *pSettler, struct CEntityEvent *pEvent)
void  CCarrierRole::ConvertEventIntoGoal(class CSettler * pSettler, class CEntityEvent * pEvent) {
  
  unsigned int v3; // eax
  std::list *v4; // eax
  int v5; // eax
  int v6; // eax
  T_SETTLER_OBJ_TYPE v7; // eax
  unsigned int v8; // eax
  std::list *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  std::list *v16; // eax
  int v17; // eax
  int v18; // eax
  DWORD v19; // eax
  unsigned int v20; // eax
  std::list *v21; // eax
  int v22; // eax
  T_SETTLER_OBJ_TYPE v23; // eax
  unsigned int v24; // eax
  std::list *v25; // eax
  int v26; // eax
  int v27; // eax
  unsigned int v28; // eax
  std::list *v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // esi
  int v34; // eax
  int v35; // eax
  unsigned int v36; // eax
  std::list *v37; // eax
  unsigned int v38; // eax
  std::list *v39; // eax
  int v40; // eax
  DWORD v41; // [esp-8h] [ebp-88h]
  unsigned int v42; // [esp-8h] [ebp-88h]
  int v43; // [esp-8h] [ebp-88h]
  unsigned int v44; // [esp-8h] [ebp-88h]
  unsigned int v45; // [esp-8h] [ebp-88h]
  int v46; // [esp-8h] [ebp-88h]
  int v47; // [esp-4h] [ebp-84h]
  int v48; // [esp-4h] [ebp-84h]
  int v49; // [esp-4h] [ebp-84h]
  int v50; // [esp-4h] [ebp-84h]
  int v51; // [esp-4h] [ebp-84h]
  int v52; // [esp-4h] [ebp-84h]
  int m_uHomeEntityId; // [esp-4h] [ebp-84h]
  int v54; // [esp-4h] [ebp-84h]
  unsigned int v55; // [esp-4h] [ebp-84h]
  int v56; // [esp-4h] [ebp-84h]
  int v57; // [esp-4h] [ebp-84h]
  CEntityEvent v58; // [esp+8h] [ebp-78h] BYREF
  int m_iDataA; // [esp+20h] [ebp-60h]
  int v60; // [esp+24h] [ebp-5Ch]
  CBuilding *v61; // [esp+28h] [ebp-58h]
  CBuilding *v62; // [esp+2Ch] [ebp-54h]
  struct CEntityEvent *v63; // [esp+30h] [ebp-50h]
  struct CEntityEvent *v64; // [esp+34h] [ebp-4Ch]
  int m_iDataB; // [esp+38h] [ebp-48h]
  int v66; // [esp+3Ch] [ebp-44h]
  CSettlerMgr::SSettlerInfos *SettlerInfo; // [esp+40h] [ebp-40h]
  DWORD v68; // [esp+44h] [ebp-3Ch]
  int v69; // [esp+48h] [ebp-38h]
  DWORD iMeetingPointXY; // [esp+4Ch] [ebp-34h]
  int iPileID; // [esp+50h] [ebp-30h]
  int iVehicleID; // [esp+54h] [ebp-2Ch]
  int v73; // [esp+58h] [ebp-28h]
  CEcoSector *pSector; // [esp+5Ch] [ebp-24h]
  int iEventId; // [esp+60h] [ebp-20h]
  CPile *rPile; // [esp+68h] [ebp-18h]
  CVehicle *rVehicle; // [esp+6Ch] [ebp-14h] MAPDST
  int v80; // [esp+7Ch] [ebp-4h]

  iEventId = pEvent->m_iEvent - 1;
  switch ( iEventId )
  {
    case 0:
      if ( ISettlerRole::HomeEntityId(this) != pEvent->m_iDataA )
        goto LABEL_87;
      v18 = ISettlerRole::HomeEntityId(this);
      v61 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, v18);
      v19 = CBuilding::DoorPackedXY(v61);
      ISettlerRole::NewDestination(this, pSettler, v19, 0);
      CSettler::TakeAnimList(pSettler, 0);
      goto LABEL_111;
    case 6:
    case 8:
      if ( this->m_uHomeEntityId && pEvent->m_iEvent == 7 )
      {
        IAnimatedEntity::RegisterForLogicUpdate(pSettler, 1);
        return;
      }
      m_iDataA = pEvent->m_iDataA;
      m_iDataB = pEvent->m_iDataB;
      this->SetFree(this, pSettler, m_iDataB);
      goto LABEL_111;
    case 9:
      if ( ISettlerRole::SourcePileId(this)
        && ISettlerRole::SourcePileId(this) != pEvent->m_iDataB
        && BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\CarrierRole.cpp",
             1236,
             "(SourcePileId() == 0) || (SourcePileId() == _pEvent->m_iData1)") == 1 )
      {
        __debugbreak();
      }
      if ( CCarrierRole::DestinationPileId(this)
        && CCarrierRole::DestinationPileId(this) != pEvent->m_iDataC
        && BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\CarrierRole.cpp",
             1237,
             "(DestinationPileId() == 0) || (DestinationPileId() == _pEvent->m_iData2)") == 1 )
      {
        __debugbreak();
      }
      if ( ISettlerRole::SourcePileId(this) != pEvent->m_iDataB
        && CCarrierRole::DestinationPileId(this) != pEvent->m_iDataC )
      {
        goto LABEL_87;
      }
      v3 = IEntity::Race(pSettler);
      v4 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v3, 0x98u);
      pSettler->NewToDoList(pSettler, (int)v4, 152);
      goto LABEL_111;
    case 10:
      if ( debug && DEBUG_FLAGS[g_iCarrierDebugSlot] )
      {
        v5 = IEntity::ID(pSettler);
        BBSupportTracePrintF(0, "Carrier %u TRANSPORT_GOOD_TO_VEHICLE", v5);
      }
      iVehicleID = pEvent->m_iDataC;
      iPileID = pEvent->m_iDataB;
      if ( iVehicleID <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1265, "iVehicleID>0") == 1 )
        __debugbreak();
      if ( iPileID <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1266, "iPileID>0") == 1 )
        __debugbreak();
      if ( !g_pMapObjectMgr
        && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1267, "g_pMapObjectMgr!=NULL") == 1 )
      {
        __debugbreak();
      }
      if ( !CMapObjectMgr::ValidEntityId(iVehicleID)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\CarrierRole.cpp",
             1268,
             "g_pMapObjectMgr->ValidEntityId(iVehicleID)") == 1 )
      {
        __debugbreak();
      }
      rPile = CPileMgr::operator[](iPileID);
      rVehicle = CVehicleMgr::operator[](iVehicleID);
      if ( this->m_uHomeEntityId )
      {
        if ( ISettlerRole::SourcePileId(this) > 0 )
        {
          v47 = IEntity::ID(pSettler);
          v7 = IEntity::ObjType(pSettler);
          iMeetingPointXY = rVehicle->GetMeetingPointXY(rVehicle, v7, v47);
          if ( iMeetingPointXY )
          {
            ISettlerRole::NewDestination(this, pSettler, iMeetingPointXY, 0);
            v8 = IEntity::Race(pSettler);
            v9 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v8, 0x99u);
            pSettler->NewToDoList(pSettler, (int)v9, 153);
            if ( debug && DEBUG_FLAGS[g_iCarrierDebugSlot] )
            {
              v48 = ISettlerRole::SourcePileId(this);
              v10 = IEntity::ID(pSettler);
              BBSupportTracePrintF(
                0,
                "Carrier CONV TRANSPORT_GOOD_TO_VEHICLE - Attach settler %u to srcpile %u",
                v10,
                v48);
            }
            if ( debug && DEBUG_FLAGS[g_iCarrierDebugSlot] )
            {
              v49 = CCarrierRole::DestinationPileId(this);
              v11 = IEntity::ID(pSettler);
              BBSupportTracePrintF(
                0,
                "Carrier CONV TRANSPORT_GOOD_TO_VEHICLE - Attach settler %u to vehicle %u",
                v11,
                v49);
            }
            v12 = rPile->GetGoodType();
            rVehicle->GoodIsComming(rVehicle, v12);
          }
          else
          {
            if ( debug && DEBUG_FLAGS[g_iCarrierDebugSlot] )
            {
              v13 = IEntity::ID(pSettler);
              BBSupportTracePrintF(0, "WARNING: Carrier %u CONV TRANSPORT_GOOD_TO_VEHICLE cancled!", v13);
            }
            this->SetFree(this, pSettler, -1);
            v14 = rPile->GetGoodType();
            rVehicle->SupplyCanceled(rVehicle, v14);
          }
LABEL_111:
          if ( !IEntity::FlagBits(pSettler, ENTITY_FLAG_Registered) && debug )
          {
            if ( DEBUG_FLAGS[dword_4152098] )
            {
              v40 = IEntity::ID(pSettler);
              BBSupportTracePrintF(0, "ConvertEvent- not registered settler %u", v40);
            }
          }
        }
        else
        {
          this->SetFree(this, pSettler, -1);
        }
      }
      else
      {
        this->SetFree(this, pSettler, -1);
        v6 = rPile->GetGoodType();
        rVehicle->SupplyCanceled(rVehicle, v6);
      }
      return;
    case 19:
      if ( !CCarrierRole::NextSettlerType(this) )
        goto LABEL_87;
      CCarrierRole::ChangeToNextType(this, pSettler, 1, 0);
      goto LABEL_111;
    case 20:
      if ( !CCarrierRole::NextSettlerType(this) || !ISettlerRole::SourcePileId(this) )
        goto LABEL_87;
      if ( ISettlerRole::HomeEntityId(this)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1338, "HomeEntityId() == 0") == 1 )
      {
        __debugbreak();
      }
      v15 = IEntity::Race(pSettler);
      v16 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v15, 0x97u);
      pSettler->NewToDoList(pSettler, (int)v16, 151);
      goto LABEL_111;
    case 21:
      if ( CCarrierRole::NextSettlerType(this) != pEvent->m_iDataA
        || ISettlerRole::HomeEntityId(this) != pEvent->m_iDataB )
      {
        goto LABEL_87;
      }
      v69 = ISettlerRole::HomeEntityId(this);
      if ( !IEntity::FlagBits(pSettler, ENTITY_FLAG_ATTACHED)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\CarrierRole.cpp",
             1366,
             "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED) != 0") == 1 )
      {
        __debugbreak();
      }
      CCarrierRole::ChangeToNextType(this, pSettler, 1, 0);
      if ( !IEntity::FlagBits(pSettler, ENTITY_FLAG_ATTACHED)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\CarrierRole.cpp",
             1372,
             "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED) != 0") == 1 )
      {
        __debugbreak();
      }
      CSettler::SetBuilding(pSettler, v69);
      v64 = CEntityEvent::CEntityEvent(&v58, 1u, 0, v69, 0, 0);
      v63 = v64;
      v80 = 0;
      pSettler->SetEvent(pSettler, v64);
      v80 = -1;
      CEntityEvent::~CEntityEvent(&v58);
      goto LABEL_111;
    case 22:
      if ( CCarrierRole::NextSettlerType(this) != pEvent->m_iDataA
        || ISettlerRole::SourcePileId(this) != pEvent->m_iDataB
        || ISettlerRole::HomeEntityId(this) != pEvent->m_iDataC )
      {
        goto LABEL_87;
      }
      v20 = IEntity::Race(pSettler);
      v21 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v20, 0xF0u);
      pSettler->NewToDoList(pSettler, (int)v21, 240);
      goto LABEL_111;
    case 23:
      v50 = IEntity::Type(pSettler);
      v22 = IEntity::Race(pSettler);
      SettlerInfo = CSettlerMgr::GetSettlerInfo(v22, v50);
      rVehicle = CVehicleMgr::operator[](pEvent->m_iDataA);
      v51 = IEntity::ID(pSettler);
      v23 = IEntity::ObjType(pSettler);
      v68 = rVehicle->GetMeetingPointXY(rVehicle, v23, v51);
      if ( v68 && IEntity::FlagBits(rVehicle, ENTITY_FLAG_AliveMask) )
      {
        ISettlerRole::NewDestination(this, pSettler, v68, 0);
        IEntity::SetFlagBits(pSettler, (EntityFlag)0x100000);
        v52 = *std::vector<unsigned short>::operator[](&SettlerInfo->g_vAnimLists, 0);
        v42 = *std::vector<unsigned short>::operator[](&SettlerInfo->g_vAnimLists, 0);
        v24 = IEntity::Race(pSettler);
        v25 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v24, v42);
        pSettler->NewToDoList(pSettler, (int)v25, v52);
        v26 = IEntity::ID(pSettler);
        rVehicle->Attach(rVehicle, v26);
        IEntity::ClearFlagBits(pSettler, ENTITY_FLAG_Selectable|ENTITY_FLAG_Selected);
        m_uHomeEntityId = this->m_uHomeEntityId;
        v43 = IEntity::ID(pSettler);
        v27 = IEntity::OwnerId(pSettler);
        g_pAI->PostAIEvent(g_pAI, 18, v27, v43, m_uHomeEntityId);
      }
      else
      {
        IEntity::SetFlagBits(pSettler, ENTITY_FLAG_Selectable);
        v54 = IEntity::Type(pSettler);
        v44 = IEntity::Type(pSettler);
        v28 = IEntity::Race(pSettler);
        v29 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v28, v44);
        pSettler->NewToDoList(pSettler, (int)v29, v54);
      }
      goto LABEL_111;
    case 24:
      v73 = pEvent->m_iDataB;
      v55 = Y16X16::UnpackYFast(v73);
      v45 = Y16X16::UnpackXFast(v73);
      v30 = IEntity::ID(pSettler);
      CSettlerMgr::SearchSpaceForSettler(&g_cSettlerMgr, v30, v45, v55);
      CWarMap::AddEntity(pSettler);
      IEntity::SetFlagBits(pSettler, ENTITY_FLAG_Visible);
      IEntity::ClearFlagBits(pSettler, ENTITY_FLAG_ON_BOARD);
      CSettler::TakeWaitList(pSettler);
      v56 = this->m_uHomeEntityId;
      v46 = IEntity::ID(pSettler);
      v31 = IEntity::OwnerId(pSettler);
      g_pAI->PostAIEvent(g_pAI, 21, v31, v46, v56);
      v32 = IEntity::WorldIdx(pSettler);
      v66 = CWorldManager::EcoSectorId(v32);
      if ( !v66 )
        goto LABEL_99;
      pSector = CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, v66);
      if ( !pSector && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1542, "pSector!= NULL") == 1 )
        __debugbreak();
      if ( !pSector )
        return;
      v33 = CEcoSector::Owner(pSector);
      if ( v33 == IEntity::OwnerId(pSettler) )
      {
        v34 = IEntity::ID(pSettler);
        CEcoSector::SetSettlerOfferIncDisplay(pSector, 1, v34);
      }
LABEL_99:
      v57 = Y16X16::UnpackYFast(v73);
      v35 = Y16X16::UnpackXFast(v73);
      v60 = CWorldManager::OwnerId(v35, v57);
      if ( v60 != IEntity::OwnerId(pSettler) )
        CSettler::SetFree(pSettler);
      goto LABEL_111;
    case 25:
      if ( CCarrierRole::NextSettlerType(this)
        && ISettlerRole::HomeEntityId(this)
        && ISettlerRole::SourcePileId(this)
        && CCarrierRole::SourcePileId2(this)
        && CCarrierRole::SourcePileId3(this) )
      {
        v17 = ISettlerRole::HomeEntityId(this);
        v62 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, v17);
        v41 = CBuilding::DoorPackedXY(v62);
        ISettlerRole::NewDestination(this, pSettler, v41, 0);
        CSettler::TakeAnimList(pSettler, 3);
      }
      else
      {
LABEL_87:
        this->SetFree(this, pSettler, -1);
      }
      goto LABEL_111;
    case 26:
      if ( pEvent->m_iDataA )
      {
        v38 = IEntity::Race(pSettler);
        v39 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v38, 0xEEu);
        pSettler->NewToDoList(pSettler, (int)v39, 238);
      }
      else
      {
        v36 = IEntity::Race(pSettler);
        v37 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v36, 0xEFu);
        pSettler->NewToDoList(pSettler, (int)v37, 239);
      }
      goto LABEL_111;
    default:
      if ( !IEntity::FlagBits(pSettler, ENTITY_FLAG_Registered) )
      {
        if ( debug && DEBUG_FLAGS[g_iCarrierDebugSlot] )
          BBSupportTracePrintF(0, "ConvertEventIntoGoal CarrierRole - unknown event %u", pEvent->m_iEvent);
        IAnimatedEntity::RegisterForLogicUpdate(pSettler, 1);
      }
      goto LABEL_111;
  }
}


// address=[0x1566220]
// Decompiled from char __thiscall CCarrierRole::SetFree(CCarrierRole *this, CSettler *a2, int a3)
bool  CCarrierRole::SetFree(class CSettler * a2, int a3) {
  
  int v3; // eax
  unsigned int v4; // eax
  int v5; // eax
  int v6; // eax
  unsigned int v8; // [esp-Ch] [ebp-2Ch]
  unsigned int m_uGood; // [esp-8h] [ebp-28h]
  int v10; // [esp+4h] [ebp-1Ch]
  struct IEntity *v11; // [esp+8h] [ebp-18h]
  int v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+10h] [ebp-10h]
  CBuilding *v14; // [esp+14h] [ebp-Ch]
  CEcoSector *pES; // [esp+18h] [ebp-8h]

  v13 = IEntity::EntityId(a2);
  v10 = IEntity::OwnerId(a2);
  CEcoSectorMgr::RemoveCarrierFromStrikeSettlers((CEcoSectorMgr *)g_cESMgr, v10, v13);
  if ( v13 <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 983, "iSettlerId > 0") == 1 )
    __debugbreak();
  if ( a3 > 0 )
  {
    v12 = a3;
  }
  else
  {
    v3 = IEntity::WorldIdx(a2);
    v12 = CWorldManager::EcoSectorId(v3);
  }
  if ( this->m_uGood )
  {
    m_uGood = this->m_uGood;
    v8 = IEntity::Y(a2);
    v4 = IEntity::X(a2);
    CPileMgr::SearchSpaceForGoods(&g_cPileMgr, v4, v8, m_uGood, 1u);
    this->m_uGood = 0;
  }
  if ( this->m_uNextSettlerType )
  {
    if ( IEntity::FlagBits(a2, ENTITY_FLAG_ATTACHED) )
    {
      if ( !this->m_uHomeEntityId
        && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1004, "m_uHomeEntityId > 0") == 1 )
      {
        __debugbreak();
      }
      v14 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_uHomeEntityId);
      v5 = IEntity::EntityId(a2);
      CBuilding::InhabitantFlee(v14, v5);
      if ( IEntity::FlagBits(a2, ENTITY_FLAG_ATTACHED) )
      {
        v6 = IEntity::EntityId(a2);
        v14->Detach(v14, v6);
      }
      if ( this->m_uHomeEntityId
        && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1015, "m_uHomeEntityId == 0") == 1 )
      {
        __debugbreak();
      }
      this->m_uHomeEntityId = 0;
      if ( IEntity::FlagBits(a2, ENTITY_FLAG_ATTACHED)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\CarrierRole.cpp",
             1019,
             "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED) == 0") == 1 )
      {
        __debugbreak();
      }
    }
    pES = CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, v12);
    if ( !pES && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1026, "pES != 0") == 1 )
      __debugbreak();
    if ( pES )
    {
      if ( this->m_uNextSettlerType == 2 || this->m_uNextSettlerType == 3 )
      {
        CEcoSector::ChangeMinMaxValues(pES, this->m_uNextSettlerType, 1);
      }
      else if ( this->m_uNextSettlerType == 50 || this->m_uNextSettlerType == 47 || this->m_uNextSettlerType == 49 )
      {
        CEcoSector::ChangeSpecialistWish(pES, this->m_uNextSettlerType, 1);
      }
    }
  }
  this->m_uNextSettlerType = 0;
  if ( !this->m_uHomeEntityId )
    return ISettlerRole::SetFree(this, a2, a3);
  v11 = CMapObjectMgr::Entity(this->m_uHomeEntityId);
  v11->Detach(v13);
  return ISettlerRole::SetFree(this, a2, a3);
}


// address=[0x15664c0]
// Decompiled from void __thiscall CCarrierRole::TryToGoHome(CCarrierRole *this, struct CSettler *a2)
void  CCarrierRole::TryToGoHome(class CSettler * a2) {
  
  int iStartY; // eax
  int iWorldIdx; // eax
  int iES; // esi
  int iIdx; // eax
  int iStartX; // [esp-4h] [ebp-Ch]

  iStartX = Y16X16::UnpackYFast(this->m_iStartPosition);
  iStartY = Y16X16::UnpackXFast(this->m_iStartPosition);
  iWorldIdx = CWorldManager::Index(iStartY, iStartX);
  iES = CWorldManager::EcoSectorId(iWorldIdx);
  iIdx = IEntity::WorldIdx(a2);
  if ( iES == CWorldManager::EcoSectorId(iIdx) )
  {
    IAnimatedEntity::SetFrame(a2, 1u);
    IMovingEntity::WalkToXY(a2, this->m_iStartPosition, 0);
    this->m_iTask = 6;
    IMovingEntity::SetDisplacementCosts(a2, 5);
    this->Go(this, a2);
  }
}


// address=[0x1567080]
// Decompiled from int __thiscall CCarrierRole::DestinationPileId(CCarrierRole *this)
int  CCarrierRole::DestinationPileId(void)const {
  
  return this->m_iTarget1;
}


// address=[0x1567120]
// Decompiled from int __thiscall CCarrierRole::NextSettlerType(CCarrierRole *this)
int  CCarrierRole::NextSettlerType(void) {
  
  return this->m_uNextSettlerType;
}


// address=[0x1567160]
// Decompiled from int __thiscall CCarrierRole::SourcePileId2(CCarrierRole *this)
int  CCarrierRole::SourcePileId2(void)const {
  
  return this->m_iSourcePile2;
}


// address=[0x1567180]
// Decompiled from int __thiscall CCarrierRole::SourcePileId3(CCarrierRole *this)
int  CCarrierRole::SourcePileId3(void)const {
  
  return this->m_iSourcePile3;
}


