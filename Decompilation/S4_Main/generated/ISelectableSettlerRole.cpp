#include "all_headers.h"

// Definitions for class ISelectableSettlerRole

// address=[0x157c980]
// Decompiled from char *__thiscall ISelectableSettlerRole::ISelectableSettlerRole(char *this, int a2)
 ISelectableSettlerRole::ISelectableSettlerRole(std::istream &) {
  
  ISettlerRole::ISettlerRole(this, a2);
  *(_DWORD *)this = &ISelectableSettlerRole::_vftable_;
  Serial::LoadVersion(a2);
  operator^<unsigned short>(a2, this + 44);
  return this;
}


// address=[0x157ca10]
// Decompiled from int __thiscall ISelectableSettlerRole::Store(__int16 *this, struct std::ostream *a2)
void  ISelectableSettlerRole::Store(std::ostream &) {
  
  ISettlerRole::Store((struct CPersistence *)this, a2);
  Serial::StoreVersion(a2, 1);
  return operator^<unsigned short>((int)a2, this + 22);
}


// address=[0x157ca50]
// Decompiled from int __thiscall ISelectableSettlerRole::GetGroupFlags(ISelectableSettlerRole *this)
int  ISelectableSettlerRole::GetGroupFlags(void)const {
  
  return *((unsigned __int16 *)this + 22);
}


// address=[0x157ca70]
// Decompiled from int __thiscall ISelectableSettlerRole::SetGroupFlags(ISelectableSettlerRole *this, unsigned int a2)
int  ISelectableSettlerRole::SetGroupFlags(int) {
  
  if ( a2 >= 0x10000
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SelectableSettlerRole.cpp",
         104,
         "(_iFlags >= 0) && (_iFlags <= 0xFFFF)") == 1 )
  {
    __debugbreak();
  }
  *((_WORD *)this + 22) = a2;
  return *((unsigned __int16 *)this + 22);
}


// address=[0x157cac0]
// Decompiled from int __thiscall ISelectableSettlerRole::SetGroupFlagBits(_WORD *this, unsigned int a2)
int  ISelectableSettlerRole::SetGroupFlagBits(int) {
  
  if ( a2 >= 0x10000
    && BBSupportDbgReport(
         2,
         (int)"MapObjects\\Settler\\SelectableSettlerRole.cpp",
         118,
         (int)"(_iFlagBits >= 0) && (_iFlagBits <= 0xFFFF)") == 1 )
  {
    __debugbreak();
  }
  this[22] |= a2;
  return (unsigned __int16)this[22];
}


// address=[0x157cb20]
// Decompiled from int __thiscall ISelectableSettlerRole::ClearGroupFlagBits(ISelectableSettlerRole *this, unsigned int a2)
int  ISelectableSettlerRole::ClearGroupFlagBits(int) {
  
  if ( a2 >= 0x10000
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SelectableSettlerRole.cpp",
         132,
         "(_iFlagBits >= 0) && (_iFlagBits <= 0xFFFF)") == 1 )
  {
    __debugbreak();
  }
  *((_WORD *)this + 22) &= ~(_WORD)a2;
  return *((unsigned __int16 *)this + 22);
}


// address=[0x1592df0]
// Decompiled from int __thiscall ISelectableSettlerRole::GetPrimaryGroupId(ISelectableSettlerRole *this)
int  ISelectableSettlerRole::GetPrimaryGroupId(void)const {
  
  return (*((_WORD *)this + 22) & 0xF000) >> 12;
}


// address=[0x157c930]
// Decompiled from ISelectableSettlerRole *__thiscall ISelectableSettlerRole::ISelectableSettlerRole(ISelectableSettlerRole *this)
 ISelectableSettlerRole::ISelectableSettlerRole(void) {
  
  ISettlerRole::ISettlerRole(this);
  *(_DWORD *)this = &ISelectableSettlerRole::_vftable_;
  *((_WORD *)this + 22) = 0;
  return this;
}


// address=[0x157c960]
// Decompiled from ISettlerRole *__thiscall ISelectableSettlerRole::~ISelectableSettlerRole(ISelectableSettlerRole *this)
 ISelectableSettlerRole::~ISelectableSettlerRole(void) {
  
  *(_DWORD *)this = &ISelectableSettlerRole::_vftable_;
  return ISettlerRole::~ISettlerRole(this);
}


// address=[0x157cb80]
// Decompiled from char __thiscall ISelectableSettlerRole::TakeCommonJob(int this, COleCmdUI *a2)
bool  ISelectableSettlerRole::TakeCommonJob(class CSettler *) {
  
  char v2; // al
  int v4; // [esp+0h] [ebp-14h]
  const struct CEntityTask *ActualTask; // [esp+8h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-8h]

  ActualTask = (const struct CEntityTask *)IMovingEntity::GetActualTask(a2);
  if ( *((_BYTE *)ActualTask + 4) != 7 )
    return 0;
  v4 = IAnimatedEntity::JobPart(a2);
  v6 = IAnimatedEntity::Frame(a2);
  ISettlerRole::InitCommonTaskValues((ISettlerRole *)this, a2, ActualTask);
  if ( v4 == IAnimatedEntity::JobPart(a2) && v6 >= 1 && v6 < *(unsigned __int8 *)(this + 7) )
    IAnimatedEntity::SetFrame(v6);
  else
    IAnimatedEntity::SetFrame(1);
  IMovingEntity::WalkToXY(a2, *(_DWORD *)(this + 24), 0);
  IMovingEntity::SetDisplacementCosts(5);
  *(_BYTE *)(this + 4) = 6;
  IAnimatedEntity::EventQueueEmpty(a2);
  if ( v2 )
  {
    (*(void (__thiscall **)(int, COleCmdUI *))(*(_DWORD *)this + 16))(this, a2);
  }
  else
  {
    *(_BYTE *)(this + 5) = -120;
    IAnimatedEntity::RegisterForLogicUpdate(1);
  }
  return 1;
}


// address=[0x157cc70]
// Decompiled from int __thiscall ISelectableSettlerRole::Decrease(ISelectableSettlerRole *this, int a2)
int  ISelectableSettlerRole::Decrease(int) {
  
  int v3; // [esp+8h] [ebp-10h]
  _BYTE *v4; // [esp+Ch] [ebp-Ch]
  unsigned __int16 *v6; // [esp+14h] [ebp-4h]

  if ( a2 <= 0 )
    return 0;
  v6 = (unsigned __int16 *)CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 9));
  if ( !v6 )
    return a2;
  if ( (IEntity::UniqueId(v6) & 0x20000000) != 0 )
    return 0;
  if ( IEntity::FlagBits(v6, (EntityFlag)0x200000u) )
    a2 = (a2 * CStaticConfigVarInt::operator int(g_pMagicShieldDmgDecrease256)) >> 8;
  if ( IEntity::Race(v6) == 3 )
  {
    --a2;
  }
  else if ( IEntity::Type(v6) == 44 )
  {
    v4 = (_BYTE *)CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 9));
    if ( v4 )
      v3 = IEntity::Race(v4);
    else
      v3 = 0;
    a2 -= *(unsigned __int8 *)(CSettlerMgr::GetSettlerInfo(v3, 44) + 4);
  }
  if ( a2 <= 0 )
    return 1;
  return a2;
}


// address=[0x157cd70]
// Decompiled from char __thiscall ISelectableSettlerRole::ProcessGoToPosFerry(  ISelectableSettlerRole *this,  struct CSettler *a2,  const struct CEntityEvent *a3)
bool  ISelectableSettlerRole::ProcessGoToPosFerry(class CSettler *,class CEntityEvent const *) {
  
  int v3; // esi
  int v4; // eax
  int v6; // eax
  void **v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // [esp+4h] [ebp-18h]
  int v11; // [esp+8h] [ebp-14h]
  unsigned __int8 *FerryShipAt; // [esp+10h] [ebp-Ch]
  int v14; // [esp+14h] [ebp-8h]
  int v15; // [esp+18h] [ebp-4h]

  v14 = *((_DWORD *)a3 + 5);
  if ( v14 <= 0 )
    return 0;
  v10 = Y16X16::UnpackXFast(v14);
  v11 = Y16X16::UnpackYFast(v14);
  FerryShipAt = (unsigned __int8 *)CVehicleMgr::GetFerryShipAt(v10, v11);
  if ( FerryShipAt )
  {
    v3 = IEntity::OwnerId(FerryShipAt);
    if ( v3 == IEntity::OwnerId((unsigned __int8 *)a2) )
    {
      v4 = IEntity::EntityId((unsigned __int16 *)a2);
      if ( !CFerryShip::Request((CPropertySheet *)FerryShipAt, v4) )
        return 1;
    }
  }
  if ( ISettlerRole::HomeEntityId(this) <= 0 )
    return 0;
  v6 = ISettlerRole::HomeEntityId(this);
  v7 = (void **)CMapObjectMgr::EntityPtr(v6);
  v15 = j____RTDynamicCast(v7, 0, &IEntity__RTTI_Type_Descriptor_, &CFerryShip__RTTI_Type_Descriptor_, 0);
  if ( !v15 )
    return 0;
  v8 = IEntity::EntityId((unsigned __int16 *)a2);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v15 + 124))(v15, v8);
  v9 = IEntity::EntityId((unsigned __int16 *)a2);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v15 + 64))(v15, v9);
  return 0;
}


// address=[0x157ce70]
// Decompiled from int __thiscall ISelectableSettlerRole::ThiefCheckMasquerade(ISelectableSettlerRole *this, struct CSettler *a2)
unsigned int  ISelectableSettlerRole::ThiefCheckMasquerade(class CSettler *) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v8; // [esp-10h] [ebp-28h]
  int v9; // [esp-10h] [ebp-28h]
  int v10; // [esp-4h] [ebp-1Ch]
  int v11; // [esp-4h] [ebp-1Ch]
  int v12; // [esp+0h] [ebp-18h]
  int v13; // [esp+4h] [ebp-14h]
  int v16; // [esp+10h] [ebp-8h]

  v2 = IEntity::PackedXY(a2);
  v13 = CWorldManager::Index(v2);
  v3 = CWorldManager::OwnerId(v13);
  v16 = CAlliances::AllianceId(v3);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  v12 = CAlliances::AllianceId(v4);
  if ( IEntity::FlagBits(a2, (EntityFlag)0x10000000u) )
  {
    v11 = IEntity::OwnerId((unsigned __int8 *)a2);
    v9 = IEntity::Y(a2);
    v6 = IEntity::X(a2);
    if ( CScanner::FindAnyEnemyFighter(v6, v9, 6, 60, v11) )
      ISelectableSettlerRole::ThiefExpose(this, (struct IEntity *)a2);
  }
  else if ( v16 == v12 || !v16 )
  {
    v10 = IEntity::OwnerId((unsigned __int8 *)a2);
    v8 = IEntity::Y(a2);
    v5 = IEntity::X(a2);
    if ( !CScanner::FindAnyEnemyFighter(v5, v8, 15, 60, v10) )
      ISelectableSettlerRole::ThiefDisguise(this, (struct IEntity *)a2);
  }
  if ( IEntity::FlagBits(a2, (EntityFlag)0x10000000u) )
    return 15;
  else
    return 45;
}


// address=[0x157cfa0]
// Decompiled from _DWORD *__thiscall ISelectableSettlerRole::ThiefExpose(ISelectableSettlerRole *this, struct IEntity *a2)
void  ISelectableSettlerRole::ThiefExpose(class IEntity *) {
  
  IEntity::ClearFlagBits(a2, (EntityFlag)0x10000000u);
  return IEntity::SetFlagBits(a2, VulnerableMask);
}


// address=[0x157cfd0]
// Decompiled from int __thiscall ISelectableSettlerRole::ThiefDisguise(ISelectableSettlerRole *this, struct IEntity *a2)
void  ISelectableSettlerRole::ThiefDisguise(class IEntity *) {
  
  IEntity::SetFlagBits(a2, (EntityFlag)0x10000000u);
  return IEntity::ClearFlagBits(a2, VulnerableMask);
}


// address=[0x15921c0]
// Decompiled from int __thiscall ISelectableSettlerRole::GetGroupFlagsEx(ISelectableSettlerRole *this)
int  ISelectableSettlerRole::GetGroupFlagsEx(void)const {
  
  return *((unsigned __int16 *)this + 22);
}


