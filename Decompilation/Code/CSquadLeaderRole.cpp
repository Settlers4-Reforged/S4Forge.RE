#include "CSquadLeaderRole.h"

// Definitions for class CSquadLeaderRole

// address=[0x1402020]
// Decompiled from int __cdecl CSquadLeaderRole::New(int a1)
static class CPersistence * __cdecl CSquadLeaderRole::New(std::istream &) {
  
  if ( operator new(0x74u) )
    return CSquadLeaderRole::CSquadLeaderRole(a1);
  else
    return 0;
}


// address=[0x1575bb0]
// Decompiled from int __thiscall CSquadLeaderRole::ClassID(CSquadLeaderRole *this)
unsigned long  CSquadLeaderRole::ClassID(void)const {
  
  return CSquadLeaderRole::m_iClassID;
}


// address=[0x1575bf0]
// Decompiled from int __thiscall CSquadLeaderRole::GetSettlerRole(CSquadLeaderRole *this)
int  CSquadLeaderRole::GetSettlerRole(void)const {
  
  return 23;
}


// address=[0x1575c20]
// Decompiled from char __thiscall CSquadLeaderRole::IsHJB(CSquadLeaderRole *this)
bool  CSquadLeaderRole::IsHJB(void) {
  
  return 0;
}


// address=[0x1592380]
// Decompiled from _DWORD *__thiscall CSquadLeaderRole::Init(_DWORD *this, CPropertySet *a2)
void  CSquadLeaderRole::Init(class CSettler *) {
  
  _DWORD *result; // eax

  CSoldierRole::Init(a2);
  this[25] = 0;
  this[26] = 0;
  result = this;
  this[27] = 0;
  this[28] = -1;
  return result;
}


// address=[0x15923d0]
// Decompiled from struct CWarriorBehavior::SWarriorBehaviorData *__thiscall CSquadLeaderRole::LogicUpdateJob(  CSquadLeaderRole *this,  struct CSettler *a2)
void  CSquadLeaderRole::LogicUpdateJob(class CSettler *) {
  
  struct CWarriorBehavior::SWarriorBehaviorData *result; // eax

  CSoldierRole::LogicUpdateJob(this, a2);
  result = CWarriorBehavior::GetWarriorBehaviorData((CSquadLeaderRole *)((char *)this + 48));
  if ( !*((_BYTE *)result + 4) && *((int *)this + 28) > 0 )
    return result;
  result = (struct CWarriorBehavior::SWarriorBehaviorData *)IEntity::PackedXY(a2);
  *((_DWORD *)this + 28) = result;
  return result;
}


// address=[0x1592420]
// Decompiled from int __thiscall CSquadLeaderRole::WarriorInit(CSquadLeaderRole *this, struct IMovingEntity *a2, int a3, int a4)
void  CSquadLeaderRole::WarriorInit(class IMovingEntity &,int,int) {
  
  int result; // eax

  CWarriorBehavior::WarriorInit(this, a2, a3, a4);
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  result = IEntity::PackedXY(a2);
  *((_DWORD *)this + 16) = result;
  return result;
}


// address=[0x15929d0]
// Decompiled from _DWORD *__thiscall CSquadLeaderRole::CSquadLeaderRole(_DWORD *this, int a2)
 CSquadLeaderRole::CSquadLeaderRole(std::istream &) {
  
  int pExceptionObject; // [esp+8h] [ebp-14h] BYREF
  _DWORD *v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+18h] [ebp-4h]

  v4 = this;
  CSoldierRole::CSoldierRole(a2);
  v5 = 0;
  *v4 = &CSquadLeaderRole::_vftable_;
  v4[12] = &CSquadLeaderRole::`vftable';
  if ( Serial::LoadVersion(a2) != 2 )
  {
    BBSupportTracePrintF(3, "Unknown file format version for CSquadLeaderRole!");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned int>(a2, v4 + 25);
  operator^<int>(a2, (int)(v4 + 26));
  operator^<int>(a2, (int)(v4 + 27));
  v4[28] = -1;
  v5 = -1;
  return v4;
}


// address=[0x1592ac0]
// Decompiled from int __thiscall CSquadLeaderRole::Store(int *this, struct std::ostream *a2)
void  CSquadLeaderRole::Store(std::ostream &) {
  
  CSoldierRole::Store(a2);
  Serial::StoreVersion(a2, 2);
  operator^<unsigned int>(a2, this + 25);
  operator^<int>((int)a2, this + 26);
  return operator^<int>((int)a2, this + 27);
}


// address=[0x3d8bfa4]
// [Decompilation failed for static unsigned long CSquadLeaderRole::m_iClassID]

// address=[0x1575ab0]
// Decompiled from void __thiscall CSquadLeaderRole::~CSquadLeaderRole(CSquadLeaderRole *this)
 CSquadLeaderRole::~CSquadLeaderRole(void) {
  
  *(_DWORD *)this = &CSquadLeaderRole::_vftable_;
  *((_DWORD *)this + 12) = &CSquadLeaderRole::`vftable';
  CSoldierRole::~CSoldierRole(this);
}


// address=[0x1592470]
// Decompiled from int __thiscall CSquadLeaderRole::WarriorTaskWalkOneStep(CSquadLeaderRole *this, struct IMovingEntity *a2)
int  CSquadLeaderRole::WarriorTaskWalkOneStep(class IMovingEntity &) {
  
  Y16X16 *v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp-4h] [ebp-1Ch]
  int v8; // [esp+0h] [ebp-18h]
  int v9; // [esp+8h] [ebp-10h]
  int v10; // [esp+Ch] [ebp-Ch]
  struct CWalking *v11; // [esp+10h] [ebp-8h]

  v10 = CSoldierRole::WarriorTaskWalkOneStep(this, a2);
  if ( (v10 & 0x10) != 0
    && (int)ISelectableSettlerRole::GetPrimaryGroupId((CSquadLeaderRole *)((char *)this - 48)) > 0
    && IEntity::FlagBits(a2, Selectable) )
  {
    if ( *((int *)this + 16) <= 0 )
    {
      *((_DWORD *)this + 16) = IEntity::PackedXY(a2);
    }
    else
    {
      v7 = *((_DWORD *)this + 16);
      v2 = (Y16X16 *)IEntity::PackedXY(a2);
      if ( (int)Y16X16::DistanceFast(v2, v7) >= 3 )
      {
        v3 = IEntity::PackedXY(a2);
        v4 = CWorldManager::Index(v3);
        v9 = CWorldManager::SectorId(v4);
        v5 = CWorldManager::Index(*((_DWORD *)this + 16));
        if ( v9 == CWorldManager::SectorId(v5) )
        {
          v8 = *((_DWORD *)CWarriorBehavior::GetWarriorBehaviorData(this) + 3) & 0x1060 | 0x2000;
          v11 = IMovingEntity::Walking(a2);
          (*(void (__thiscall **)(struct CWalking *, _DWORD, int))(*(_DWORD *)v11 + 8))(v11, *((_DWORD *)this + 16), v8);
        }
        else
        {
          *((_DWORD *)this + 16) = IEntity::PackedXY(a2);
        }
      }
    }
  }
  CSquadLeaderRole::CommandGroupMembers((CSquadLeaderRole *)((char *)this - 48), a2);
  return v10;
}


// address=[0x15925a0]
// Decompiled from int __thiscall CSquadLeaderRole::WarriorTaskIdleWalk(CSquadLeaderRole *this, struct IMovingEntity *a2)
int  CSquadLeaderRole::WarriorTaskIdleWalk(class IMovingEntity &) {
  
  int v3; // [esp+0h] [ebp-8h]

  v3 = CSoldierRole::WarriorTaskIdleWalk(this, a2);
  CSquadLeaderRole::CommandGroupMembers((CSquadLeaderRole *)((char *)this - 48), a2);
  return v3;
}


// address=[0x15925d0]
// Decompiled from int __thiscall CSquadLeaderRole::WarriorTaskAttack(char *this, struct IMovingEntity *a2, int a3, int a4)
void  CSquadLeaderRole::WarriorTaskAttack(class IMovingEntity &,int,enum T_WARRIOR_ATTACK) {
  
  CSquadLeaderRole::CommandGroupMembers((CSquadLeaderRole *)(this - 48), a2);
  return CSoldierRole::WarriorTaskAttack(this, a2, a3, a4);
}


// address=[0x1592600]
// Decompiled from int __thiscall CSquadLeaderRole::WarriorTaskFinished(CSquadLeaderRole *this, struct IMovingEntity *a2)
void  CSquadLeaderRole::WarriorTaskFinished(class IMovingEntity &) {
  
  return CSoldierRole::WarriorTaskFinished(this, a2);
}


// address=[0x1592b50]
// Decompiled from CSquadLeaderRole *__thiscall CSquadLeaderRole::CSquadLeaderRole(CSquadLeaderRole *this)
 CSquadLeaderRole::CSquadLeaderRole(void) {
  
  CSoldierRole::CSoldierRole(this);
  *(_DWORD *)this = &CSquadLeaderRole::_vftable_;
  *((_DWORD *)this + 12) = &CSquadLeaderRole::`vftable';
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 27) = 0;
  return this;
}


// address=[0x1592620]
// Decompiled from int __thiscall CSquadLeaderRole::CommandGroupMembers(CSquadLeaderRole *this, struct IMovingEntity *a2)
void  CSquadLeaderRole::CommandGroupMembers(class IMovingEntity &) {
  
  int result; // eax
  int v3; // eax
  int v4; // eax
  double v5; // [esp+0h] [ebp-200h]
  int v6; // [esp+10h] [ebp-1F0h]
  int v7; // [esp+14h] [ebp-1ECh]
  int v8; // [esp+18h] [ebp-1E8h]
  int v9; // [esp+1Ch] [ebp-1E4h]
  unsigned int TickCounter; // [esp+20h] [ebp-1E0h]
  int NextDestination; // [esp+24h] [ebp-1DCh]
  int v12; // [esp+28h] [ebp-1D8h]
  Y16X16 *v13; // [esp+2Ch] [ebp-1D4h]
  int v14; // [esp+30h] [ebp-1D0h]
  int v15; // [esp+34h] [ebp-1CCh]
  struct CWalking *v16; // [esp+38h] [ebp-1C8h]
  int v17; // [esp+3Ch] [ebp-1C4h]
  unsigned __int8 *SettlerPtr; // [esp+40h] [ebp-1C0h]
  int v19; // [esp+44h] [ebp-1BCh]
  pairNode *v20; // [esp+48h] [ebp-1B8h]
  int i; // [esp+4Ch] [ebp-1B4h]
  int v22; // [esp+50h] [ebp-1B0h]
  int v23; // [esp+54h] [ebp-1ACh]
  bool v24; // [esp+5Ah] [ebp-1A6h]
  _BYTE v26[408]; // [esp+64h] [ebp-19Ch] BYREF

  TickCounter = CStateGame::GetTickCounter(g_pGame);
  result = (int)this;
  if ( TickCounter < *((_DWORD *)this + 25) )
    return result;
  v15 = IEntity::OwnerId((unsigned __int8 *)a2);
  result = ISelectableSettlerRole::GetPrimaryGroupId(this);
  v19 = result;
  if ( result <= 0 )
  {
    *((_DWORD *)this + 27) = 0;
  }
  else
  {
    result = (*(int (__thiscall **)(void *, int, int))(*(_DWORD *)g_pGroupMgr + 12))(g_pGroupMgr, v15, result);
    v22 = result;
    if ( result <= 1 )
    {
      *((_DWORD *)this + 27) = 0;
    }
    else
    {
      if ( (*((_DWORD *)CWarriorBehavior::GetWarriorBehaviorData((CSquadLeaderRole *)((char *)this + 48)) + 3) & 0x200000) != 0 )
        v17 = 0x200000;
      else
        v17 = 0x100000;
      v5 = sqrt<int>(v22);
      v12 = (int)(v5 * 0.75 + 3.0);
      v24 = *((_DWORD *)this + 27) <= 0;
      v16 = IMovingEntity::Walking(a2);
      v23 = (*(int (__thiscall **)(struct CWalking *, _DWORD, _DWORD))(*(_DWORD *)v16 + 32))(
              v16,
              LODWORD(v5),
              HIDWORD(v5));
      if ( v23 < 0 )
        v23 = IEntity::PackedXY(a2);
      v8 = Y16X16::UnpackXFast(v23);
      v9 = Y16X16::UnpackYFast(v23);
      v3 = IEntity::PackedXY(a2);
      CGroupDestinations::CGroupDestinations((CGroupDestinations *)v26, v8, v9, v22, 0, v3);
      v6 = IEntity::EntityId((unsigned __int16 *)a2);
      v7 = (*(int (__thiscall **)(void *, int, int))(*(_DWORD *)g_pGroupMgr + 16))(g_pGroupMgr, v15, v19);
      for ( i = 0; i < v22; ++i )
      {
        v14 = *(unsigned __int16 *)(v7 + 2 * i);
        if ( v14 != v6 )
        {
          SettlerPtr = CSettlerMgr::GetSettlerPtr(v14);
          v20 = (pairNode *)(*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)SettlerPtr + 120))(SettlerPtr);
          if ( v20 )
          {
            v13 = (Y16X16 *)CWarriorBehavior::WarriorDestinationXY(v20);
            NextDestination = CGroupDestinations::GetNextDestination(v26);
            if ( v24
              || (v4 = IEntity::PackedXY(a2), Y16X16::DistanceFast(v13, v4) > v12)
              && Y16X16::DistanceFast(v13, NextDestination) > v12 )
            {
              (**(void (__thiscall ***)(pairNode *, unsigned __int8 *, int, int))v20)(
                v20,
                SettlerPtr,
                NextDestination,
                v17);
            }
          }
        }
      }
      *((_DWORD *)this + 27) = v23;
      result = (int)this;
      *((_DWORD *)this + 25) = TickCounter + 45;
    }
  }
  return result;
}


// address=[0x1592b20]
// Decompiled from int __cdecl CSquadLeaderRole::Load_HACK_VERSION(int a1)
static class CSquadLeaderRole * __cdecl CSquadLeaderRole::Load_HACK_VERSION(std::istream &) {
  
  void **v1; // eax

  v1 = (void **)CPersistence::New_HACK_VERSION(a1);
  return j____RTDynamicCast(v1, 0, &CPersistence__RTTI_Type_Descriptor_, &CSquadLeaderRole__RTTI_Type_Descriptor_, 1);
}


