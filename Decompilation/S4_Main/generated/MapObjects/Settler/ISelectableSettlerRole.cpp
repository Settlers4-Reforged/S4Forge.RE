#if FALSE
#include "ISelectableSettlerRole.h"

// Definitions for class ISelectableSettlerRole

// address=[0x157c980]
// Decompiled from void __thiscall ISelectableSettlerRole::ISelectableSettlerRole(  ISelectableSettlerRole *this,  struct std::istream *_rStream)
 ISelectableSettlerRole::ISelectableSettlerRole(std::istream & _rStream) {
  
  ISettlerRole::ISettlerRole(this, _rStream);
  this->__vftable = (ISettlerRole_vtbl *)&ISelectableSettlerRole::_vftable_;
  Serial::LoadVersion(_rStream);
  operator^<unsigned short>(_rStream, &this->m_iGroupFlags);
}


// address=[0x157ca10]
// Decompiled from void __thiscall ISelectableSettlerRole::Store(ISelectableSettlerRole *this, struct std::ostream *_rStream)
void  ISelectableSettlerRole::Store(std::ostream & _rStream) {
  
  ISettlerRole::Store(this, _rStream);
  Serial::StoreVersion(_rStream, 1);
  operator^<unsigned short>(_rStream, &this->m_iGroupFlags);
}


// address=[0x157ca50]
// Decompiled from int __thiscall ISelectableSettlerRole::GetGroupFlags(ISelectableSettlerRole *this)
int  ISelectableSettlerRole::GetGroupFlags(void)const {
  
  return this->m_iGroupFlags;
}


// address=[0x157ca70]
// Decompiled from void __thiscall ISelectableSettlerRole::SetGroupFlags(ISelectableSettlerRole *this, unsigned int _iFlags)
int  ISelectableSettlerRole::SetGroupFlags(int _iFlags) {
  
  if ( _iFlags >= 0x10000
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SelectableSettlerRole.cpp",
         104,
         "(_iFlags >= 0) && (_iFlags <= 0xFFFF)") == 1 )
  {
    __debugbreak();
  }
  this->m_iGroupFlags = _iFlags;
}


// address=[0x157cac0]
// Decompiled from void __thiscall ISelectableSettlerRole::SetGroupFlagBits(ISelectableSettlerRole *this, unsigned int _iFlagBits)
int  ISelectableSettlerRole::SetGroupFlagBits(int _iFlagBits) {
  
  if ( _iFlagBits >= 0x10000
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SelectableSettlerRole.cpp",
         118,
         "(_iFlagBits >= 0) && (_iFlagBits <= 0xFFFF)") == 1 )
  {
    __debugbreak();
  }
  this->m_iGroupFlags |= _iFlagBits;
}


// address=[0x157cb20]
// Decompiled from void __thiscall ISelectableSettlerRole::ClearGroupFlagBits(ISelectableSettlerRole *this, unsigned int _iFlagBits)
int  ISelectableSettlerRole::ClearGroupFlagBits(int _iFlagBits) {
  
  if ( _iFlagBits >= 0x10000
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SelectableSettlerRole.cpp",
         132,
         "(_iFlagBits >= 0) && (_iFlagBits <= 0xFFFF)") == 1 )
  {
    __debugbreak();
  }
  this->m_iGroupFlags &= ~(_WORD)_iFlagBits;
}


// address=[0x1592df0]
// Decompiled from int __thiscall ISelectableSettlerRole::GetPrimaryGroupId(ISelectableSettlerRole *this)
int  ISelectableSettlerRole::GetPrimaryGroupId(void)const {
  
  return (this->m_iGroupFlags & 0xF000) >> 12;
}


// address=[0x157c930]
// Decompiled from ISelectableSettlerRole *__thiscall ISelectableSettlerRole::ISelectableSettlerRole(ISelectableSettlerRole *this)
 ISelectableSettlerRole::ISelectableSettlerRole(void) {
  
  ISettlerRole::ISettlerRole(this);
  this->__vftable = (ISettlerRole_vtbl *)&ISelectableSettlerRole::_vftable_;
  this->m_iGroupFlags = 0;
  return this;
}


// address=[0x157c960]
// Decompiled from ISettlerRole *__thiscall ISelectableSettlerRole::~ISelectableSettlerRole(ISelectableSettlerRole *this)
 ISelectableSettlerRole::~ISelectableSettlerRole(void) {
  
  *(_DWORD *)this = &ISelectableSettlerRole::_vftable_;
  return ISettlerRole::~ISettlerRole(this);
}


// address=[0x157cb80]
// Decompiled from char __thiscall ISelectableSettlerRole::TakeCommonJob(ISettlerRole *this, struct CSettler *arg0)
bool  ISelectableSettlerRole::TakeCommonJob(class CSettler * arg0) {
  
  int v3; // [esp+0h] [ebp-14h]
  CEntityTask *ActualTask; // [esp+8h] [ebp-Ch]
  int a2; // [esp+Ch] [ebp-8h]

  ActualTask = IMovingEntity::GetActualTask(arg0);
  if ( ActualTask->m_iTask != 7 )
    return 0;
  v3 = IAnimatedEntity::JobPart(arg0);
  a2 = IAnimatedEntity::Frame(arg0);
  ISettlerRole::InitCommonTaskValues(this, arg0, ActualTask);
  if ( v3 == IAnimatedEntity::JobPart(arg0) && a2 >= 1 && a2 < this->m_uCycleFrames )
    IAnimatedEntity::SetFrame(arg0, a2);
  else
    IAnimatedEntity::SetFrame(arg0, 1u);
  IMovingEntity::WalkToXY(arg0, this->m_iDestinationPosition, 0);
  IMovingEntity::SetDisplacementCosts(arg0, 5);
  this->m_iTask = 6;
  if ( IAnimatedEntity::EventQueueEmpty(arg0) )
  {
    this->Go(this, arg0);
  }
  else
  {
    this->m_uSettlerWalk = -120;
    IAnimatedEntity::RegisterForLogicUpdate(arg0, 1);
  }
  return 1;
}


// address=[0x157cc70]
// Decompiled from int __thiscall ISelectableSettlerRole::Decrease(ISelectableSettlerRole *this, int a2)
int  ISelectableSettlerRole::Decrease(int a2) {
  
  int v3; // [esp+8h] [ebp-10h]
  IEntity *v4; // [esp+Ch] [ebp-Ch]
  IEntity *v6; // [esp+14h] [ebp-4h]

  if ( a2 <= 0 )
    return 0;
  v6 = CMapObjectMgr::EntityPtr(this->m_uAttachedSettlerId);
  if ( !v6 )
    return a2;
  if ( (IEntity::UniqueId(v6) & 0x20000000) != 0 )
    return 0;
  if ( IEntity::FlagBits(v6, (EntityFlag)0x200000) )
    a2 = (a2 * CStaticConfigVarInt::operator int((CStaticConfigVarInt *)g_pMagicShieldDmgDecrease256)) >> 8;
  if ( IEntity::Race(v6) == 3 )
  {
    --a2;
  }
  else if ( IEntity::Type(v6) == 44 )
  {
    v4 = CMapObjectMgr::EntityPtr(this->m_uAttachedSettlerId);
    if ( v4 )
      v3 = IEntity::Race(v4);
    else
      v3 = 0;
    a2 -= CSettlerMgr::GetSettlerInfo(v3, 44)->m_bArmor;
  }
  if ( a2 <= 0 )
    return 1;
  return a2;
}


// address=[0x157cd70]
// Decompiled from char __thiscall ISelectableSettlerRole::ProcessGoToPosFerry(  ISelectableSettlerRole *this,  CSettler *a2,  const struct CEntityEvent *a3)
bool  ISelectableSettlerRole::ProcessGoToPosFerry(class CSettler * a2, class CEntityEvent const * a3) {
  
  int v3; // esi
  int v4; // eax
  int v6; // eax
  IEntity *v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // [esp+4h] [ebp-18h]
  int v11; // [esp+8h] [ebp-14h]
  IEntity *FerryShipAt; // [esp+10h] [ebp-Ch]
  int m_iDataC; // [esp+14h] [ebp-8h]
  CFerryShip *pFerry; // [esp+18h] [ebp-4h]

  m_iDataC = a3->m_iDataC;
  if ( m_iDataC <= 0 )
    return 0;
  v10 = Y16X16::UnpackXFast(m_iDataC);
  v11 = Y16X16::UnpackYFast(m_iDataC);
  FerryShipAt = (IEntity *)CVehicleMgr::GetFerryShipAt(v10, v11);
  if ( FerryShipAt )
  {
    v3 = IEntity::OwnerId(FerryShipAt);
    if ( v3 == IEntity::OwnerId(a2) )
    {
      v4 = IEntity::EntityId(a2);
      if ( !CFerryShip::Request(FerryShipAt, v4) )
        return 1;
    }
  }
  if ( ISettlerRole::HomeEntityId(this) <= 0 )
    return 0;
  v6 = ISettlerRole::HomeEntityId(this);
  v7 = CMapObjectMgr::EntityPtr(v6);
  pFerry = (CFerryShip *)j____RTDynamicCast(
                           (void **)&v7->__vftable,
                           0,
                           &IEntity__RTTI_Type_Descriptor_,
                           &CFerryShip__RTTI_Type_Descriptor_,
                           0);
  if ( !pFerry )
    return 0;
  v8 = IEntity::EntityId(a2);
  pFerry->EntityOrderCanceled(pFerry, v8);
  v9 = IEntity::EntityId(a2);
  pFerry->Detach(pFerry, v9);
  return 0;
}


// address=[0x157ce70]
// Decompiled from int __thiscall ISelectableSettlerRole::ThiefCheckMasquerade(ISelectableSettlerRole *this, CSettler *_pSettler)
unsigned int  ISelectableSettlerRole::ThiefCheckMasquerade(class CSettler * _pSettler) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v8; // [esp-10h] [ebp-28h]
  unsigned int v9; // [esp-10h] [ebp-28h]
  int v10; // [esp-4h] [ebp-1Ch]
  int v11; // [esp-4h] [ebp-1Ch]
  int v12; // [esp+0h] [ebp-18h]
  int v13; // [esp+4h] [ebp-14h]
  int v16; // [esp+10h] [ebp-8h]

  v2 = IEntity::PackedXY(_pSettler);
  v13 = CWorldManager::Index(v2);
  v3 = CWorldManager::OwnerId(v13);
  v16 = CAlliances::AllianceId(v3);
  v4 = IEntity::OwnerId(_pSettler);
  v12 = CAlliances::AllianceId(v4);
  if ( IEntity::FlagBits(_pSettler, ENTITY_FLAG_Ownerless) )
  {
    v11 = IEntity::OwnerId(_pSettler);
    v9 = IEntity::Y(_pSettler);
    v6 = IEntity::X(_pSettler);
    if ( CScanner::FindAnyEnemyFighter(v6, v9, 6, 60, v11) )
      ISelectableSettlerRole::ThiefExpose(this, _pSettler);
  }
  else if ( v16 == v12 || !v16 )
  {
    v10 = IEntity::OwnerId(_pSettler);
    v8 = IEntity::Y(_pSettler);
    v5 = IEntity::X(_pSettler);
    if ( !CScanner::FindAnyEnemyFighter(v5, v8, 15, 60, v10) )
      ISelectableSettlerRole::ThiefDisguise(this, _pSettler);
  }
  if ( IEntity::FlagBits(_pSettler, ENTITY_FLAG_Ownerless) )
    return 15;
  else
    return 45;
}


// address=[0x157cfa0]
// Decompiled from void __thiscall ISelectableSettlerRole::ThiefExpose(ISelectableSettlerRole *this, struct IEntity *a2)
void  ISelectableSettlerRole::ThiefExpose(class IEntity * a2) {
  
  IEntity::ClearFlagBits(a2, ENTITY_FLAG_Ownerless);
  IEntity::SetFlagBits(a2, ENTITY_FLAG_VulnerableMask);
}


// address=[0x157cfd0]
// Decompiled from void __thiscall ISelectableSettlerRole::ThiefDisguise(ISelectableSettlerRole *this, struct IEntity *a2)
void  ISelectableSettlerRole::ThiefDisguise(class IEntity * a2) {
  
  IEntity::SetFlagBits(a2, ENTITY_FLAG_Ownerless);
  IEntity::ClearFlagBits(a2, ENTITY_FLAG_VulnerableMask);
}


// address=[0x15921c0]
// Decompiled from int __thiscall ISelectableSettlerRole::GetGroupFlagsEx(ISelectableSettlerRole *this)
int  ISelectableSettlerRole::GetGroupFlagsEx(void)const {
  
  return this->m_iGroupFlags;
}


#endif // Already implemented
