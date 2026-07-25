#include "CWarriorBehavior.h"

// Definitions for class CWarriorBehavior

// address=[0x1592e10]
// Decompiled from int __thiscall CWarriorBehavior::WarriorDestinationXY(CWarriorBehavior *this)
int  CWarriorBehavior::WarriorDestinationXY(void)const {
  
  return this->m_sWarriorBehaviorData.m_iDestinationXYOrId;
}


// address=[0x15ac3a0]
// Decompiled from CWarriorBehavior *__thiscall CWarriorBehavior::CWarriorBehavior(CWarriorBehavior *this)
 CWarriorBehavior::CWarriorBehavior(void) {
  
  this->__vftable = (CWarriorBehavior_vtbl *)&CWarriorBehavior::_vftable_;
  memset(&this->m_sWarriorBehaviorData, 0, sizeof(this->m_sWarriorBehaviorData));
  this->m_sWarriorBehaviorData.m_pProperties = (CWarriorProperties *)&s_sWarriorProperties;
  return this;
}


// address=[0x15ac3e0]
// Decompiled from void __thiscall CWarriorBehavior::WarriorInit(CWarriorBehavior *this, struct IMovingEntity *a2, int a3, int a4)
void  CWarriorBehavior::WarriorInit(class IMovingEntity & a2, int a3, int a4) {
  
  int v4; // eax
  unsigned int v5; // eax
  int v6; // [esp+4h] [ebp-18h]
  char v7; // [esp+Ch] [ebp-10h]
  int v8; // [esp+10h] [ebp-Ch]
  int v9; // [esp+14h] [ebp-8h]

  v9 = IEntity::WarriorType(a2);
  v6 = IEntity::Type(a2);
  if ( v9 == AI_WARRIOR_TYPE_FIGHTER_UNIQUE || v6 == SETTLER_SABOTEUR )
  {
    switch ( v6 )
    {
      case SETTLER_MEDIC_01:
      case SETTLER_MEDIC_02:
      case SETTLER_MEDIC_03:
        v9 = 15;
        break;
      case SETTLER_AXEWARRIOR_01:
      case SETTLER_AXEWARRIOR_02:
      case SETTLER_AXEWARRIOR_03:
        v9 = 16;
        break;
      case SETTLER_BLOWGUNWARRIOR_01:
      case SETTLER_BLOWGUNWARRIOR_02:
      case SETTLER_BLOWGUNWARRIOR_03:
        v9 = 17;
        break;
      case SETTLER_SABOTEUR:
        v9 = 19;
        break;
      case SETTLER_SHAMAN:
        v9 = 18;
        break;
      case SETTLER_BACKPACKCATAPULTIST_01:
      case SETTLER_BACKPACKCATAPULTIST_02:
      case SETTLER_BACKPACKCATAPULTIST_03:
        v9 = 20;
        break;
      default:
        if ( BBSupportDbgReportF(
               1,
               "MapObjects\\WarriorBehavior.cpp",
               630,
               "CWarriorBehavior::WarriorInit(): Unsupported settler type %i of warrior type FIGHTER_UNIQUE",
               v6) == 1 )
          __debugbreak();
        break;
    }
  }
  this->m_sWarriorBehaviorData.m_pProperties = &s_sWarriorProperties[v9];
  if ( (a4 & 0x700000) == 0 )
    a3 = -1;
  v4 = IEntity::OwnerId(a2);
  this->m_sWarriorBehaviorData.m_iDestinationXYOrId = a3;
  v5 = v4 | a4 & 0xFFFFFFF0;
  this->m_sWarriorBehaviorData.m_iFlags = v5;
  v7 = 0;
  v8 = v5 & 0x700000;
  if ( (v5 & 0x700000) > 0x500000 )
  {
    if ( v8 == 0x600000 )
    {
      v7 = 7;
    }
    else if ( v8 == 0x700000 )
    {
      this->m_sWarriorBehaviorData.m_uLastTargetId = a3;
      this->m_sWarriorBehaviorData.m_uU0 = 5;
      this->m_sWarriorBehaviorData.m_iU01 = 0;
      this->m_sWarriorBehaviorData.m_iNextFullUpdate = 0;
      this->m_sWarriorBehaviorData.m_iDestinationXYOrId = 0;
      return;
    }
  }
  else
  {
    switch ( v8 )
    {
      case 0x500000:
        v7 = 6;
        break;
      case 0x100000:
        v7 = 1;
        break;
      case 0x200000:
      case 0x300000:
        v7 = 4;
        break;
    }
  }
  this->m_sWarriorBehaviorData.m_uU0 = v7;
  this->m_sWarriorBehaviorData.m_iU01 = 0;
  this->m_sWarriorBehaviorData.m_uLastTargetId = 0;
  this->m_sWarriorBehaviorData.m_iNextFullUpdate = 0;
  CWarriorBehavior::WarriorInitWalk(this, a2, a3);
}


// address=[0x15ac600]
// Decompiled from void __thiscall CWarriorBehavior::WarriorLogicUpdate(  CWarriorBehavior *this,  struct IMovingEntity *a2,  unsigned int a3,  char a4)
void  CWarriorBehavior::WarriorLogicUpdate(class IMovingEntity & a2, unsigned int a3, int a4) {
  
  int v4; // esi
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // eax
  T_AI_WARRIOR_TYPE v9; // [esp+Ch] [ebp-50h]
  int v10; // [esp+14h] [ebp-48h]
  int v11; // [esp+18h] [ebp-44h]
  int v12; // [esp+24h] [ebp-38h] BYREF
  BOOL v13; // [esp+28h] [ebp-34h]
  BOOL v14; // [esp+2Ch] [ebp-30h]
  int v15; // [esp+30h] [ebp-2Ch]
  int m_uLastTargetId; // [esp+34h] [ebp-28h]
  IEntity *v17; // [esp+38h] [ebp-24h]
  int v18; // [esp+3Ch] [ebp-20h]
  int iDistance; // [esp+40h] [ebp-1Ch]
  int v20; // [esp+44h] [ebp-18h]
  int v21; // [esp+48h] [ebp-14h]
  int v22; // [esp+4Ch] [ebp-10h]
  int m_uU0; // [esp+50h] [ebp-Ch]
  bool IsFullUpdate; // [esp+5Bh] [ebp-1h]

  m_uU0 = this->m_sWarriorBehaviorData.m_uU0;
  if ( m_uU0 > 4 )
  {
    if ( m_uU0 <= 8 )
    {
      switch ( m_uU0 )
      {
        case 8:
LABEL_64:
          this->m_sWarriorBehaviorData.m_uU0 = 0;
          this->WarriorTaskFinished(this, a2);
          return;
        case 6:
          if ( CWarriorBehavior::WarriorIsFullUpdate(this, a3) )
            goto LABEL_54;
          m_uLastTargetId = this->m_sWarriorBehaviorData.m_uLastTargetId;
          if ( !m_uLastTargetId )
          {
            this->WarriorTaskWalkOneStep(this, a2);
            return;
          }
          if ( !CWarriorBehavior::WarriorCheckTargetAndDistance(this, a2, m_uLastTargetId) )
          {
LABEL_54:
            CWarriorBehavior::WarriorSetNextFullUpdate(this, a3, 0x1Eu);
            if ( this->m_sWarriorBehaviorData.m_pProperties->m_fpInfluenceCheck(this, a2)
              && (v15 = CWarriorBehavior::WarriorAttackCheck(this, a2), v15 > 0) )
            {
              this->m_sWarriorBehaviorData.m_uLastTargetId = v15;
              CWarriorBehavior::WarriorAttackTarget(this, a2, v15);
            }
            else
            {
              this->m_sWarriorBehaviorData.m_uLastTargetId = 0;
              this->WarriorTaskWalkOneStep(this, a2);
            }
          }
          else
          {
            CWarriorBehavior::WarriorAttackTarget(this, a2, m_uLastTargetId);
          }
          return;
        case 7:
          if ( this->m_sWarriorBehaviorData.m_pProperties->m_fpInfluenceCheck(this, a2)
            && (v18 = CWarriorBehavior::WarriorAttackCheck(this, a2), v18 > 0) )
          {
            this->m_sWarriorBehaviorData.m_uLastTargetId = v18;
            CWarriorBehavior::WarriorAttackTarget(this, a2, v18);
          }
          else
          {
            v11 = CWarriorBehavior::WarriorDestinationId((pairNode *)this);
            if ( v11 > 0
              && (v17 = CMapObjectMgr::Entity(v11), (((unsigned int)&loc_1FFFFFF + 1) & IEntity::Flags(v17)) != 0) )
            {
              v10 = IEntity::PackedXY(v17);
              v9 = IEntity::WarriorType(v17);
              v8 = IEntity::PackedXY(a2);
              if ( Y16X16::DistanceFast(v10, v8) <= this->m_sWarriorBehaviorData.m_pProperties->m_uU1
                                                  + s_sWarriorProperties[v9].m_uU1
                                                  + 1 )
              {
                this->WarriorTaskIdleWalk(this, a2);
              }
              else
              {
                CWarriorBehavior::WarriorPseudoInitWalk(this, a2, v10);
                this->WarriorTaskWalkOneStep(this, a2);
              }
            }
            else
            {
              this->m_sWarriorBehaviorData.m_iDestinationXYOrId = -1;
              this->m_sWarriorBehaviorData.m_uU0 = 8;
            }
          }
          return;
      }
    }
LABEL_62:
    if ( BBSupportDbgReport(
           1,
           "MapObjects\\WarriorBehavior.cpp",
           1166,
           "CWarriorBehavior::WarriorLogicUpdate(): Invalid state!") == 1 )
      __debugbreak();
    goto LABEL_64;
  }
  if ( m_uU0 == 4 )
  {
    if ( (this->WarriorTaskWalkOneStep(this, a2) & 0x70) != 0 )
      this->m_sWarriorBehaviorData.m_uU0 = 8;
  }
  else
  {
    if ( m_uU0 > 1 )
      goto LABEL_62;
    IsFullUpdate = CWarriorBehavior::WarriorIsFullUpdate(this, a3);
    if ( !IsFullUpdate )
    {
      v21 = this->m_sWarriorBehaviorData.m_uLastTargetId;
      if ( v21 )
      {
        if ( (a4 & 0x10) != 0 )
        {
          this->m_sWarriorBehaviorData.m_iU01 &= ~2u;
        }
        else
        {
          if ( this->m_sWarriorBehaviorData.m_pProperties->m_fpTargetAndDistanceCheck(this, a2, v21) )
          {
            this->m_sWarriorBehaviorData.m_iU01 &= ~2u;
            CWarriorBehavior::WarriorAttackTarget(this, a2, v21);
            return;
          }
          IsFullUpdate = (this->m_sWarriorBehaviorData.m_iU01 & 2) == 0;
        }
      }
    }
    if ( IsFullUpdate )
    {
      this->m_sWarriorBehaviorData.m_iU01 &= ~2u;
      CWarriorBehavior::WarriorSetNextFullUpdate(this, a3, 0x1Eu);
      if ( this->m_sWarriorBehaviorData.m_pProperties->m_fpInfluenceCheck(this, a2) )
      {
        if ( (a4 & 0x10) == 0 )
        {
          v20 = CWarriorBehavior::WarriorAttackCheck(this, a2);
          if ( v20 > 0 )
          {
            this->m_sWarriorBehaviorData.m_uLastTargetId = v20;
            CWarriorBehavior::WarriorAttackTarget(this, a2, v20);
            return;
          }
          v22 = this->m_sWarriorBehaviorData.m_pProperties->m_fpAttackScan(this, a2, &v12);
          v14 = v22 == 0;
          v13 = this->m_sWarriorBehaviorData.m_pProperties->m_iRadiusFirst > 1;
          if ( v13 && v14 )
            v22 = CWarriorBehavior::WarriorEvadeScan15a(this, a2, &v12);
          if ( v22 > 0 )
          {
            this->m_sWarriorBehaviorData.m_iU01 |= 2u;
            this->m_sWarriorBehaviorData.m_uLastTargetId = v22;
            iDistance = CWarriorBehavior::WarriorPseudoInitWalk(this, a2, v12);
            if ( iDistance <= 8 )
            {
              if ( iDistance <= 0 && BBSupportDbgReport(2, "MapObjects\\WarriorBehavior.cpp", 961, "iDistance > 0") == 1 )
                __debugbreak();
              CWarriorBehavior::WarriorSetNextFullUpdate(this, a3, 4 * iDistance - 4);
            }
          }
        }
      }
    }
    if ( this->m_sWarriorBehaviorData.m_uLastTargetId != 0 && (this->m_sWarriorBehaviorData.m_iU01 & 2) == 0 )
    {
      this->m_sWarriorBehaviorData.m_uLastTargetId = 0;
      v4 = CWarriorBehavior::WarriorDestinationXY((pairNode *)this);
      if ( v4 != CWarriorBehavior::WarriorWalkDestinationXY(this, a2) )
      {
        v5 = CWarriorBehavior::WarriorDestinationXY((pairNode *)this);
        CWarriorBehavior::WarriorInitWalk(this, a2, v5);
      }
    }
    if ( (this->WarriorTaskWalkOneStep(this, a2) & 0x70) != 0
      && CWarriorBehavior::WarriorDestinationXY((pairNode *)this) != -1 )
    {
      v6 = CWarriorBehavior::WarriorDestinationXY((pairNode *)this);
      if ( v6 == CWarriorBehavior::WarriorWalkDestinationXY(this, a2) )
      {
        this->m_sWarriorBehaviorData.m_uU0 = 8;
      }
      else
      {
        v7 = CWarriorBehavior::WarriorDestinationXY((pairNode *)this);
        CWarriorBehavior::WarriorInitWalk(this, a2, v7);
      }
    }
  }
}


// address=[0x15acbd0]
// Decompiled from void __thiscall CWarriorBehavior::WarriorVehicleLogicUpdate(  CWarriorBehavior *this,  struct IMovingEntity *a2,  unsigned int a3,  char a4)
void  CWarriorBehavior::WarriorVehicleLogicUpdate(class IMovingEntity & a2, unsigned int a3, int a4) {
  
  int v4; // eax
  CWarriorProperties *m_pProperties; // esi
  CWarriorProperties *v6; // eax
  int v7; // [esp-4h] [ebp-6Ch]
  int v8; // [esp+8h] [ebp-60h] BYREF
  int v9; // [esp+Ch] [ebp-5Ch] BYREF
  BOOL v10; // [esp+10h] [ebp-58h]
  BOOL v11; // [esp+14h] [ebp-54h]
  unsigned int v12; // [esp+18h] [ebp-50h]
  unsigned int v13; // [esp+1Ch] [ebp-4Ch]
  int v14; // [esp+20h] [ebp-48h]
  int m_iU0; // [esp+24h] [ebp-44h]
  int AttackWayPoint; // [esp+28h] [ebp-40h]
  bool v17; // [esp+2Fh] [ebp-39h]
  IEntity *v18; // [esp+30h] [ebp-38h]
  unsigned int v19; // [esp+34h] [ebp-34h]
  int v20; // [esp+38h] [ebp-30h]
  IEntity *v21; // [esp+3Ch] [ebp-2Ch]
  void (__thiscall *v22)(CWarriorBehavior *, struct IMovingEntity *); // [esp+40h] [ebp-28h]
  int uLastTargetId; // [esp+48h] [ebp-20h]
  bool IsFullUpdate; // [esp+4Eh] [ebp-1Ah]
  bool v26; // [esp+4Fh] [ebp-19h]
  int v28; // [esp+54h] [ebp-14h] BYREF
  unsigned int v29; // [esp+58h] [ebp-10h]
  int v30; // [esp+5Ch] [ebp-Ch]

  v26 = (a4 & 3) == 0;
  v17 = v26;
  m_iU0 = (unsigned __int8)this->m_sWarriorBehaviorData.m_uU0;
  switch ( m_iU0 )
  {
    case 0:
    case 1:
    case 7:
      if ( this->m_sWarriorBehaviorData.m_uU0 )
      {
        if ( this->m_sWarriorBehaviorData.m_uU0 == 1 )
          v22 = CWarriorBehavior::WarriorVehicleMoveWalkOneStep;
        else
          v22 = j_CWarriorBehavior::WarriorVehicleEscortWalkOneStep;
      }
      else
      {
        v22 = CWarriorBehavior::WarriorVehicleIdleWalkOneStep;
      }
      if ( (a4 & 2) != 0 )
      {
        this->m_sWarriorBehaviorData.m_uLastTargetId = 0;
        v22(this, a2);
        return;
      }
      IsFullUpdate = CWarriorBehavior::WarriorIsFullUpdate(this, a3);
      uLastTargetId = this->m_sWarriorBehaviorData.m_uLastTargetId;
      if ( uLastTargetId )
      {
        v21 = CMapObjectMgr::EntityPtr(uLastTargetId);
        CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(this, a2, &v8, &v9);
        if ( v21 && CWarriorBehavior::WarriorCheckTarget(v21, v8, v9) )
        {
          v7 = IEntity::PackedXY(v21);
          v4 = IEntity::PackedXY(a2);
          v12 = Y16X16::DistanceFast(v4, v7);
          m_pProperties = this->m_sWarriorBehaviorData.m_pProperties;
          v19 = m_pProperties->m_iU3[IEntity::WarriorType(v21)];
          v6 = CWarriorBehavior::WarriorProperties(this);
          if ( v12 > v6->m_iRadiusLast )
            v14 = 0;
          else
            v14 = 10;
          v19 += v14;
        }
        else
        {
          uLastTargetId = 0;
          IsFullUpdate = 1;
        }
      }
      if ( (a4 & 1) != 0 )
      {
        if ( uLastTargetId )
          ((void (__thiscall *)(CWarriorBehavior *, struct IMovingEntity *))this->__vftable[1].WarriorInit)(this, a2);
        else
          v22(this, a2);
        return;
      }
      if ( IsFullUpdate )
      {
        CWarriorBehavior::WarriorVehicleAttackScan31(this, a2, (struct CWarriorBehavior::SWarriorScanResult *)&v28);
        v20 = v28;
        if ( v28 )
        {
          CWarriorBehavior::WarriorSetNextFullUpdate(this, a3, 0x14u);
          v13 = v29;
          if ( v29 > 0xA )
          {
            if ( uLastTargetId )
            {
              v11 = v19 >= v13;
              v10 = v12 <= 2 * v30;
              if ( v10 && v11 )
                v20 = uLastTargetId;
            }
            this->m_sWarriorBehaviorData.m_uLastTargetId = v20;
            CWarriorBehavior::WarriorVehicleAttackTarget(this, a2, v20);
            return;
          }
        }
        else
        {
          CWarriorBehavior::WarriorSetNextFullUpdate(this, a3, 0x28u);
        }
LABEL_36:
        this->m_sWarriorBehaviorData.m_uLastTargetId = 0;
        v22(this, a2);
        return;
      }
      if ( !uLastTargetId || v19 <= 0xA )
        goto LABEL_36;
      if ( this->m_sWarriorBehaviorData.m_uLastTargetId != uLastTargetId
        && BBSupportDbgReport(
             2,
             "MapObjects\\WarriorBehavior.cpp",
             1411,
             "m_sWarriorBehaviorData.m_uLastTargetId == uLastTargetId") == 1 )
      {
        __debugbreak();
      }
      CWarriorBehavior::WarriorVehicleAttackTarget(this, a2, uLastTargetId);
      return;
    case 4:
      CWarriorBehavior::WarriorVehicleMoveWalkOneStep(this, a2);
      return;
    case 5:
      if ( !CMapObjectMgr::ValidUsedEntityId(this->m_sWarriorBehaviorData.m_uLastTargetId) )
        goto LABEL_39;
      v18 = CMapObjectMgr::Entity(this->m_sWarriorBehaviorData.m_uLastTargetId);
      if ( !this->m_sWarriorBehaviorData.m_iDestinationXYOrId )
        this->m_sWarriorBehaviorData.m_iDestinationXYOrId = CWarriorBehavior::FindAttackWayPoint(this, a2, v18);
      if ( this->m_sWarriorBehaviorData.m_iDestinationXYOrId > 0 )
      {
        *(&this->m_sWarriorBehaviorData.m_uU0 + 1) |= 1u;
        CWarriorBehavior::WarriorInitWalk(this, a2, this->m_sWarriorBehaviorData.m_iDestinationXYOrId);
      }
      if ( !CWarriorBehavior::WarriorIsFullUpdate(this, a3) )
        goto LABEL_51;
      if ( !CMapObjectMgr::ValidUsedEntityId(this->m_sWarriorBehaviorData.m_uLastTargetId)
        || !IEntity::FlagBits(v18, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
      {
        goto LABEL_39;
      }
      AttackWayPoint = CWarriorBehavior::FindAttackWayPoint(this, a2, v18);
      if ( AttackWayPoint && AttackWayPoint != this->m_sWarriorBehaviorData.m_iDestinationXYOrId )
      {
        this->m_sWarriorBehaviorData.m_iDestinationXYOrId = AttackWayPoint;
        *(&this->m_sWarriorBehaviorData.m_uU0 + 1) |= 1u;
        CWarriorBehavior::WarriorInitWalk(this, a2, this->m_sWarriorBehaviorData.m_iDestinationXYOrId);
      }
LABEL_51:
      if ( this->m_sWarriorBehaviorData.m_iDestinationXYOrId > 0 && (a4 & 2) == 0 )
      {
        if ( CWarriorBehavior::IsTargetInAtackRange(this, a2, v18) )
        {
          if ( (a4 & 1) != 0 )
            ((void (__thiscall *)(CWarriorBehavior *, struct IMovingEntity *))this->__vftable[1].WarriorInit)(this, a2);
          else
            CWarriorBehavior::WarriorVehicleAttackTarget(this, a2, this->m_sWarriorBehaviorData.m_uLastTargetId);
        }
        else
        {
          CWarriorBehavior::WarriorVehicleMoveWalkOneStep(this, a2);
        }
      }
      else
      {
LABEL_39:
        ((void (__thiscall *)(CWarriorBehavior *, struct IMovingEntity *))this->__vftable[2].WarriorInit)(this, a2);
      }
      return;
    case 8:
      goto LABEL_61;
    default:
      if ( BBSupportDbgReport(
             1,
             "MapObjects\\WarriorBehavior.cpp",
             1523,
             "CWarriorBehavior::WarriorLogicUpdate(): Invalid state!") == 1 )
        __debugbreak();
LABEL_61:
      this->m_sWarriorBehaviorData.m_uU0 = 0;
      ((void (__thiscall *)(CWarriorBehavior *, struct IMovingEntity *))this->__vftable[2].WarriorInit)(this, a2);
      return;
  }
}


// address=[0x15ad0e0]
// Decompiled from bool __thiscall CWarriorBehavior::WarriorCheckTargetAndDistance(CWarriorBehavior *this, struct IEntity *a2, int a3)
bool  CWarriorBehavior::WarriorCheckTargetAndDistance(class IMovingEntity & a2, int a3) {
  
  int (__thiscall *m_fpAttackCheck)(CWarriorBehavior *, struct IEntity *); // [esp+0h] [ebp-38h]
  int v5; // [esp+4h] [ebp-34h]
  int v6; // [esp+8h] [ebp-30h]
  int v7; // [esp+Ch] [ebp-2Ch]
  int v8; // [esp+10h] [ebp-28h]
  int v9; // [esp+14h] [ebp-24h] BYREF
  int v10; // [esp+18h] [ebp-20h] BYREF
  int v11; // [esp+24h] [ebp-14h]
  BOOL v12; // [esp+28h] [ebp-10h]
  int (__thiscall *m_fpAttackScan)(CWarriorBehavior *, struct IEntity *, int *); // [esp+2Ch] [ebp-Ch]
  IEntity *v14; // [esp+30h] [ebp-8h]
  CWarriorBehavior *v15; // [esp+34h] [ebp-4h]

  v15 = this;
  CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(this, a2, &v9, &v10);
  if ( !CWarriorBehavior::WarriorCheckTarget(a3, v9, v10) )
    return 0;
  v5 = IEntity::X(a2);
  v7 = IEntity::Y(a2);
  v14 = CMapObjectMgr::Entity(a3);
  v6 = IEntity::X(v14);
  v8 = IEntity::Y(v14);
  v11 = Grid::Distance(v6 - v5, v8 - v7);
  m_fpAttackCheck = v15->m_sWarriorBehaviorData.m_pProperties[1].m_fpAttackCheck;
  m_fpAttackScan = v15->m_sWarriorBehaviorData.m_pProperties[1].m_fpAttackScan;
  v12 = IEntity::ObjType(v14) == CATAPULT_OBJ;
  return v11 <= (int)m_fpAttackScan + v12 && v11 >= (int)m_fpAttackCheck;
}


// address=[0x15ad1f0]
// Decompiled from bool __thiscall CWarriorBehavior::WarriorValidLastTargetMedic(CWarriorBehavior *this, struct IMovingEntity *a2, int a3)
bool  CWarriorBehavior::WarriorValidLastTargetMedic(class IMovingEntity & a2, int a3) {
  
  void **v3; // eax
  int v6; // [esp+4h] [ebp-14h]
  int v7; // [esp+Ch] [ebp-Ch]
  CSoldierRole *v9; // [esp+14h] [ebp-4h]

  v7 = IEntity::OwnerId((unsigned __int8 *)a2);
  v6 = CAlliances::PlayerAllyBits(v7);
  v3 = (void **)CSettler::Role(a2);
  v9 = (CSoldierRole *)j____RTDynamicCast(
                         v3,
                         0,
                         &ISettlerRole__RTTI_Type_Descriptor_,
                         &CSoldierRole__RTTI_Type_Descriptor_,
                         0);
  if ( !v9 || CSoldierRole::GetNumberOfHealings(v9) <= 0 )
    return 0;
  return (unsigned __int8)sub_15AEB60(v6, a3) || CWarriorBehavior::WarriorCheckTargetAndDistance(this, a2, a3);
}


// address=[0x15ad2a0]
// Decompiled from char __thiscall CWarriorBehavior::WarriorValidLastTargetAxeWarrior(  CWarriorBehavior *this,  struct IMovingEntity *a2,  int a3)
bool  CWarriorBehavior::WarriorValidLastTargetAxeWarrior(class IMovingEntity & a2, int a3) {
  
  return 0;
}


// address=[0x15ad2b0]
// Decompiled from char __thiscall CWarriorBehavior::WarriorValidLastTargetSaboteur(  CWarriorBehavior *this,  struct IMovingEntity *a2,  int a3)
bool  CWarriorBehavior::WarriorValidLastTargetSaboteur(class IMovingEntity & a2, int a3) {
  
  return 0;
}


// address=[0x15ad2c0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackCheck1(CWarriorBehavior *this, struct IEntity *a2)
int  CWarriorBehavior::WarriorAttackCheck1(class IMovingEntity & a2) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp+Ch] [ebp-3Ch]
  int v8; // [esp+10h] [ebp-38h]
  int v9; // [esp+14h] [ebp-34h]
  int v10; // [esp+18h] [ebp-30h] BYREF
  int v11; // [esp+1Ch] [ebp-2Ch] BYREF
  int v12; // [esp+20h] [ebp-28h]
  int v13; // [esp+24h] [ebp-24h]
  int v14; // [esp+28h] [ebp-20h]
  int v15; // [esp+2Ch] [ebp-1Ch]
  CWarriorBehavior *v16; // [esp+30h] [ebp-18h]
  unsigned __int16 *v17; // [esp+34h] [ebp-14h]
  int j; // [esp+38h] [ebp-10h]
  int v19; // [esp+3Ch] [ebp-Ch]
  int i; // [esp+40h] [ebp-8h]
  int v21; // [esp+44h] [ebp-4h]

  v16 = this;
  v7 = IEntity::X(a2);
  v8 = IEntity::Y(a2);
  if ( !CWorldManager::InInnerWorld1(v7, v8)
    && BBSupportDbgReport(2, "MapObjects\\WarriorBehavior.cpp", 1613, "g_cWorld.InInnerWorld1(iX, iY)") == 1 )
  {
    __debugbreak();
  }
  v12 = IEntity::WorldIdx();
  CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(v16, a2, &v10, &v11);
  v21 = -1;
  v14 = 0;
  for ( i = 1; i < 7; ++i )
  {
    v2 = CWorldManager::SurroundingHexPointRelIndex(i);
    v19 = CWorldManager::MapObjectId(v12 + v2);
    if ( v19 )
    {
      if ( v19 <= 6 )
      {
        v13 = v21 < 0;
        v21 -= v13;
      }
      else
      {
        v17 = (unsigned __int16 *)CMapObjectMgr::Entity(v19);
        v3 = IEntity::OwnerId((unsigned __int8 *)v17);
        v4 = CAlliances::PlayerBit(v3);
        if ( (v10 & v4) != 0 && CWarriorBehavior::WarriorTargetAllowableAndVulnerable(v17, v11) )
        {
          v15 = *(_DWORD *)(*((_DWORD *)v16 + 1) + 4 * IEntity::WarriorType() + 40);
          if ( v15 > v14 )
          {
            v21 = v19;
            v14 = v15;
          }
        }
      }
    }
  }
  if ( v21 != -2 )
    return v21;
  v21 = -1;
  for ( j = 7; j < 19; ++j )
  {
    v5 = CWorldManager::SurroundingHexPointRelIndex(j);
    v9 = CWorldManager::MapObjectId(v12 + v5);
    if ( CWarriorBehavior::WarriorCheckTarget(v9, v10, v11) )
      return v9;
  }
  return v21;
}


// address=[0x15ad4a0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackCheck15(CWarriorBehavior *this, struct IEntity *a2)
int  CWarriorBehavior::WarriorAttackCheck15(class IMovingEntity & a2) {
  
  int v3; // eax
  int v4; // eax
  IEntity *v5; // eax
  T_AI_WARRIOR_TYPE v6; // [esp+0h] [ebp-44h]
  int v7; // [esp+4h] [ebp-40h] BYREF
  int v8; // [esp+8h] [ebp-3Ch] BYREF
  int v9; // [esp+Ch] [ebp-38h]
  int v10; // [esp+10h] [ebp-34h]
  int v11; // [esp+14h] [ebp-30h]
  int v12; // [esp+18h] [ebp-2Ch]
  int v13; // [esp+1Ch] [ebp-28h]
  unsigned int v14; // [esp+20h] [ebp-24h]
  int v15; // [esp+24h] [ebp-20h]
  int v16; // [esp+28h] [ebp-1Ch]
  int v17; // [esp+2Ch] [ebp-18h]
  int iRadiusLast; // [esp+30h] [ebp-14h]
  int v19; // [esp+34h] [ebp-10h]
  int iRadiusFirst; // [esp+3Ch] [ebp-8h]
  int i; // [esp+40h] [ebp-4h]

  iRadiusFirst = this->m_sWarriorBehaviorData.m_pProperties->m_iRadiusFirst;
  iRadiusLast = this->m_sWarriorBehaviorData.m_pProperties->m_iRadiusLast;
  if ( iRadiusFirst <= 0 )
    return -1;
  if ( iRadiusLast > 15 && BBSupportDbgReport(2, "MapObjects\\WarriorBehavior.cpp", 1779, "iRadiusLast <= 15") == 1 )
    __debugbreak();
  if ( iRadiusFirst > iRadiusLast
    && BBSupportDbgReport(2, "MapObjects\\WarriorBehavior.cpp", 1780, "iRadiusFirst <= iRadiusLast") == 1 )
  {
    __debugbreak();
  }
  v10 = IEntity::X(a2);
  v9 = IEntity::Y(a2);
  CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(this, a2, &v7, &v8);
  v11 = SurroundingHexPointsCount(iRadiusFirst - 1);
  v16 = SurroundingHexPointsCount(iRadiusLast);
  v12 = -1;
  v19 = 0;
  for ( i = v11; i < v16; ++i )
  {
    v3 = SSurroundingPoint8::X(&g_sSurroundingHexPoints8[i]);
    v14 = v10 + v3;
    v4 = SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[i]);
    v15 = v9 + v4;
    if ( CWorldManager::InWorld(v14, v9 + v4) )
    {
      v17 = CWorldManager::MapObjectId(v14, v15);
      if ( CWarriorBehavior::WarriorCheckTarget(v17, v7, v8) )
      {
        v5 = CMapObjectMgr::Entity(v17);
        v6 = IEntity::WarriorType(v5);
        v13 = this->m_sWarriorBehaviorData.m_pProperties->m_iU3[v6];
        if ( v13 > v19 )
        {
          v12 = v17;
          v19 = v13;
          if ( v13 >= 8 )
            return v12;
          if ( v19 >= 4 && i + 200 < v16 )
            v16 = i + 200;
        }
      }
    }
  }
  return v12;
}


// address=[0x15ad6a0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackCheckBowman(CWarriorBehavior *this, struct IEntity *a2)
int  CWarriorBehavior::WarriorAttackCheckBowman(class IMovingEntity & a2) {
  
  IEntity *v2; // eax
  IEntity *v3; // eax
  IEntity *v4; // eax
  IEntity *v5; // eax
  int v7; // [esp+4h] [ebp-38h]
  int v8; // [esp+8h] [ebp-34h]
  int v9; // [esp+Ch] [ebp-30h]
  char v10; // [esp+10h] [ebp-2Ch]
  int v11; // [esp+14h] [ebp-28h]
  int m_iRadiusLast; // [esp+18h] [ebp-24h]
  int v13; // [esp+1Ch] [ebp-20h]
  int v14; // [esp+20h] [ebp-1Ch]
  int v15; // [esp+24h] [ebp-18h]
  int v16; // [esp+28h] [ebp-14h]
  int v18; // [esp+30h] [ebp-Ch]
  int NearestEntity; // [esp+34h] [ebp-8h]
  int i; // [esp+38h] [ebp-4h]

  v18 = CWarriorBehavior::WarriorAttackCheck15(this, a2);
  v14 = IEntity::X(a2);
  v15 = IEntity::Y(a2);
  v16 = -1;
  m_iRadiusLast = this->m_sWarriorBehaviorData.m_pProperties->m_iRadiusLast;
  v10 = IEntity::OwnerId(a2);
  v9 = CAlliances::PlayerBit(v10);
  for ( i = 1; i <= CPlayerManager::NumberOfPlayers(); ++i )
  {
    if ( CPlayerManager::Race(i) == 3 && (v9 & CAlliances::PlayerAllyBits(i)) == 0 )
    {
      NearestEntity = CFlyingMgr::GetNearestEntity((CFlyingMgr *)g_cFlyingMgr, i, 1, v14, v15, 0);
      if ( NearestEntity )
      {
        v2 = CFlyingMgr::operator[](NearestEntity);
        if ( (IEntity::Flags(v2) & 0x2000000) != 0 )
        {
          v3 = CFlyingMgr::operator[](NearestEntity);
          v7 = IEntity::X(v3);
          v4 = CFlyingMgr::operator[](NearestEntity);
          v8 = IEntity::Y(v4);
          v13 = Grid::Distance(v7 - v14, v8 - v15);
          if ( v13 < m_iRadiusLast )
          {
            m_iRadiusLast = v13;
            v16 = NearestEntity;
          }
        }
      }
    }
  }
  if ( v16 == -1 )
    return v18;
  v11 = 0;
  if ( v18 != -1 )
  {
    v5 = CMapObjectMgr::Entity(v18);
    v11 = this->m_sWarriorBehaviorData.m_pProperties->m_iU3[IEntity::WarriorType(v5)];
  }
  if ( v11 <= 3 )
    return v16;
  return v18;
}


// address=[0x15ad840]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackCheckMedic(CWarriorBehavior *this, struct IEntity *a2)
int  CWarriorBehavior::WarriorAttackCheckMedic(class IMovingEntity & a2) {
  
  void **v2; // eax
  int v3; // eax
  int v4; // esi
  int v7; // [esp+8h] [ebp-2Ch]
  int v8; // [esp+Ch] [ebp-28h]
  int v9; // [esp+10h] [ebp-24h]
  int v10; // [esp+18h] [ebp-1Ch]
  int v11; // [esp+1Ch] [ebp-18h]
  int v12; // [esp+20h] [ebp-14h]
  CSoldierRole *v13; // [esp+24h] [ebp-10h]
  int v14; // [esp+28h] [ebp-Ch]
  int i; // [esp+2Ch] [ebp-8h]
  unsigned __int8 *v16; // [esp+30h] [ebp-4h]

  v10 = IEntity::X(a2);
  v11 = IEntity::Y(a2);
  v12 = IEntity::OwnerId((unsigned __int8 *)a2);
  v7 = CAlliances::PlayerAllyBits(v12);
  v9 = CWorldManager::Index(v10, v11);
  v2 = (void **)CSettler::Role(a2);
  v13 = (CSoldierRole *)j____RTDynamicCast(
                          v2,
                          0,
                          &ISettlerRole__RTTI_Type_Descriptor_,
                          &CSoldierRole__RTTI_Type_Descriptor_,
                          0);
  if ( v13 && CSoldierRole::GetNumberOfHealings(v13) > 0 )
  {
    for ( i = 1; i < 19; ++i )
    {
      v8 = v9 + CWorldManager::SurroundingHexPointRelIndex(i);
      v14 = CWorldManager::MapObjectId(v8);
      if ( v14 > 0 )
      {
        v16 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(v14);
        if ( IEntity::ObjType(v16) == 1 )
        {
          v3 = IEntity::OwnerId(v16);
          if ( (v7 & CAlliances::PlayerBit(v3)) != 0 )
          {
            v4 = IEntity::Hitpoints((IEntity *)v16);
            if ( v4 < (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v16 + 44))(v16) )
              return v14;
          }
        }
      }
    }
  }
  return CWarriorBehavior::WarriorAttackCheck1(this, a2);
}


// address=[0x15ad980]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackCheckAxeWarrior(CWarriorBehavior *this, struct IEntity *a2)
int  CWarriorBehavior::WarriorAttackCheckAxeWarrior(class IMovingEntity & a2) {
  
  int v4; // [esp+4h] [ebp-4h]

  v4 = sub_15AEDC0(a2, 15, 2, 1, 0);
  if ( v4 <= 0 )
    return CWarriorBehavior::WarriorAttackCheck15(this, a2);
  else
    return v4;
}


// address=[0x15ad9c0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackCheckSaboteur(CWarriorBehavior *this, struct IMovingEntity *a2)
int  CWarriorBehavior::WarriorAttackCheckSaboteur(class IMovingEntity & a2) {
  
  int v4; // [esp+8h] [ebp-4h]

  v4 = sub_15AEDC0(a2, 15, 0, 0, 0);
  if ( v4 <= 0 )
    return -1;
  else
    return v4;
}


// address=[0x15ada00]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackScan15(CWarriorBehavior *this, struct IEntity *a2, int *a3)
int  CWarriorBehavior::WarriorAttackScan15(class IMovingEntity & a2, int * a3) {
  
  int v3; // eax
  int v4; // eax
  int v6; // [esp+0h] [ebp-34h] BYREF
  int v7; // [esp+4h] [ebp-30h] BYREF
  int v8; // [esp+8h] [ebp-2Ch]
  int v9; // [esp+Ch] [ebp-28h]
  int v10; // [esp+10h] [ebp-24h]
  int v11; // [esp+14h] [ebp-20h]
  int v12; // [esp+18h] [ebp-1Ch]
  int v13; // [esp+1Ch] [ebp-18h]
  int iScanRadiusLast; // [esp+20h] [ebp-14h]
  unsigned int v15; // [esp+24h] [ebp-10h]
  int v16; // [esp+28h] [ebp-Ch]
  CWarriorBehavior *v17; // [esp+2Ch] [ebp-8h]
  int i; // [esp+30h] [ebp-4h]

  v17 = this;
  v9 = IEntity::X(a2);
  v8 = IEntity::Y(a2);
  v12 = v17->m_sWarriorBehaviorData.m_pProperties->m_iRadiusFirst + 1;
  iScanRadiusLast = v17->m_sWarriorBehaviorData.m_pProperties->m_iScanRadiusLast;
  if ( iScanRadiusLast > 15
    && BBSupportDbgReport(2, "MapObjects\\WarriorBehavior.cpp", 1987, "iScanRadiusLast <= 15") == 1 )
  {
    __debugbreak();
  }
  v11 = SurroundingHexPointsCount(v12 - 1);
  v10 = SurroundingHexPointsCount(iScanRadiusLast);
  CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(v17, a2, &v6, &v7);
  for ( i = v11; ; ++i )
  {
    if ( i >= v10 )
      return 0;
    v3 = SSurroundingPoint8::X(&g_sSurroundingHexPoints8[i]);
    v15 = v9 + v3;
    v4 = SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[i]);
    v16 = v8 + v4;
    if ( CWorldManager::InWorld(v15, v8 + v4) )
    {
      v13 = CWorldManager::MapObjectId(v15, v16);
      if ( CWarriorBehavior::WarriorCheckTarget(v13, v6, v7) )
        break;
    }
  }
  if ( a3 )
    *a3 = Y16X16::PackXYFast(v15, v16);
  return v13;
}


// address=[0x15adb50]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackScanBowman(CWarriorBehavior *this, struct IEntity *a2, int *a3)
int  CWarriorBehavior::WarriorAttackScanBowman(class IMovingEntity & a2, int * a3) {
  
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  void *v5; // eax
  int v7; // [esp+0h] [ebp-34h]
  int v8; // [esp+4h] [ebp-30h]
  int v9; // [esp+8h] [ebp-2Ch]
  int v10; // [esp+Ch] [ebp-28h]
  int v11; // [esp+10h] [ebp-24h]
  int v12; // [esp+14h] [ebp-20h]
  int v13; // [esp+18h] [ebp-1Ch]
  int v14; // [esp+1Ch] [ebp-18h]
  int v15; // [esp+20h] [ebp-14h]
  int v17; // [esp+28h] [ebp-Ch]
  int NearestEntity; // [esp+2Ch] [ebp-8h]
  int i; // [esp+30h] [ebp-4h]

  v9 = CWarriorBehavior::WarriorAttackScan15(this, a2, a3);
  v14 = IEntity::X(a2);
  v15 = IEntity::Y(a2);
  v17 = -1;
  v12 = *(_DWORD *)(*((_DWORD *)this + 1) + 36);
  v8 = IEntity::OwnerId((unsigned __int8 *)a2);
  v7 = CAlliances::PlayerBit(v8);
  for ( i = 1; i <= CPlayerManager::NumberOfPlayers(); ++i )
  {
    if ( CPlayerManager::Race(i) == 3 && (v7 & CAlliances::PlayerAllyBits(i)) == 0 )
    {
      NearestEntity = CFlyingMgr::GetNearestEntity((CFlyingMgr *)g_cFlyingMgr, i, 1, v14, v15, 0);
      if ( NearestEntity )
      {
        v3 = (_DWORD *)CFlyingMgr::operator[](NearestEntity);
        if ( (((unsigned int)&loc_1FFFFFF + 1) & IEntity::Flags(v3)) != 0 )
        {
          v4 = (_DWORD *)CFlyingMgr::operator[](NearestEntity);
          v10 = IEntity::X(v4);
          v5 = (void *)CFlyingMgr::operator[](NearestEntity);
          v11 = IEntity::Y(v5);
          v13 = Grid::Distance((Grid *)(v10 - v14), v11 - v15);
          if ( v13 < v12 )
          {
            v12 = v13;
            v17 = NearestEntity;
            *a3 = Y16X16::PackXYFast(v10, v11);
          }
        }
      }
    }
  }
  if ( v17 != -1 )
    return v17;
  return v9;
}


// address=[0x15adcd0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackScanMedic(CWarriorBehavior *this, struct IEntity *a2, int *a3)
int  CWarriorBehavior::WarriorAttackScanMedic(class IMovingEntity & a2, int * a3) {
  
  void **v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp+0h] [ebp-44h]
  int v8; // [esp+4h] [ebp-40h] BYREF
  int v9; // [esp+8h] [ebp-3Ch] BYREF
  int v10; // [esp+Ch] [ebp-38h]
  int v11; // [esp+10h] [ebp-34h]
  int v12; // [esp+14h] [ebp-30h]
  int v13; // [esp+18h] [ebp-2Ch]
  struct IEntity *v14; // [esp+1Ch] [ebp-28h]
  int v15; // [esp+20h] [ebp-24h]
  int v16; // [esp+24h] [ebp-20h]
  CSoldierRole *v17; // [esp+28h] [ebp-1Ch]
  int v18; // [esp+2Ch] [ebp-18h]
  int v19; // [esp+30h] [ebp-14h]
  int v20; // [esp+34h] [ebp-10h]
  CWarriorBehavior *v21; // [esp+38h] [ebp-Ch]
  int v22; // [esp+3Ch] [ebp-8h]
  int i; // [esp+40h] [ebp-4h]

  v21 = this;
  v11 = IEntity::X(a2);
  v10 = IEntity::Y(a2);
  v16 = IEntity::OwnerId((unsigned __int8 *)a2);
  v7 = CAlliances::PlayerAllyBits(v16);
  v15 = *(_DWORD *)(*((_DWORD *)v21 + 1) + 28) + 1;
  v18 = *(_DWORD *)(*((_DWORD *)v21 + 1) + 36);
  if ( v18 > 15 && BBSupportDbgReport(2, "MapObjects\\WarriorBehavior.cpp", 2036, "iScanRadiusLast <= 15") == 1 )
    __debugbreak();
  v13 = SurroundingHexPointsCount(v15 - 1);
  v12 = SurroundingHexPointsCount(v18);
  CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(v21, a2, &v8, &v9);
  v14 = a2;
  v3 = (void **)CSettler::Role(a2);
  v17 = (CSoldierRole *)j____RTDynamicCast(
                          v3,
                          0,
                          &ISettlerRole__RTTI_Type_Descriptor_,
                          &CSoldierRole__RTTI_Type_Descriptor_,
                          0);
  for ( i = v13; ; ++i )
  {
    if ( i >= v12 )
      return 0;
    v4 = SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * i]);
    v19 = v11 + v4;
    v5 = SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * i]);
    v20 = v10 + v5;
    if ( (unsigned __int8)CWorldManager::InWorld(v19, v10 + v5) )
    {
      v22 = CWorldManager::MapObjectId(v19, v20);
      if ( v22 > 0
        && (CWarriorBehavior::WarriorCheckTarget(v22, v8, v9)
         || v17 && CSoldierRole::GetNumberOfHealings(v17) > 0 && (unsigned __int8)sub_15AEB60(v7, v22)) )
      {
        break;
      }
    }
  }
  if ( a3 )
    *a3 = Y16X16::PackXYFast(v19, v20);
  return v22;
}


// address=[0x15ade90]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackScanAxeWarrior(CWarriorBehavior *this, struct IEntity *a2, int *a3)
int  CWarriorBehavior::WarriorAttackScanAxeWarrior(class IMovingEntity & a2, int * a3) {
  
  int v5; // [esp+4h] [ebp-4h]

  v5 = sub_15AEDC0(a2, 21, 8, 1, a3);
  if ( v5 <= 0 )
    return CWarriorBehavior::WarriorAttackScan15(this, a2, a3);
  else
    return v5;
}


// address=[0x15adee0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackScanSaboteur(CWarriorBehavior *this, struct IMovingEntity *a2, int *a3)
int  CWarriorBehavior::WarriorAttackScanSaboteur(class IMovingEntity & a2, int * a3) {
  
  return sub_15AEDC0(a2, 21, -12, 0, a3);
}


// address=[0x15adf10]
// Decompiled from int __thiscall CWarriorBehavior::WarriorEvadeScan15a(CWarriorBehavior *this, struct IEntity *a2, int *a3)
int  CWarriorBehavior::WarriorEvadeScan15a(class IMovingEntity & a2, int * a3) {
  
  int v3; // eax
  int v4; // eax
  int uPadding; // esi
  _BYTE v7[20]; // [esp+4h] [ebp-54h] BYREF
  int v8; // [esp+18h] [ebp-40h] BYREF
  int v9; // [esp+1Ch] [ebp-3Ch] BYREF
  int v10; // [esp+20h] [ebp-38h]
  int v11; // [esp+24h] [ebp-34h] BYREF
  int v12; // [esp+28h] [ebp-30h] BYREF
  int v13; // [esp+2Ch] [ebp-2Ch]
  int v14; // [esp+30h] [ebp-28h]
  int v15; // [esp+34h] [ebp-24h]
  DWORD v16; // [esp+38h] [ebp-20h]
  unsigned int v17; // [esp+3Ch] [ebp-1Ch]
  int v18; // [esp+40h] [ebp-18h]
  int iScanRadiusLast; // [esp+48h] [ebp-10h]
  int v21; // [esp+4Ch] [ebp-Ch]
  int v22; // [esp+50h] [ebp-8h]
  int i; // [esp+54h] [ebp-4h]

  v21 = IEntity::X(a2);
  v22 = IEntity::Y(a2);
  iScanRadiusLast = this->m_sWarriorBehaviorData.m_pProperties->m_iRadiusFirst - 1;
  if ( iScanRadiusLast < 1
    && BBSupportDbgReport(2, "MapObjects\\WarriorBehavior.cpp", 2128, "iScanRadiusLast >= 1") == 1 )
  {
    __debugbreak();
  }
  v14 = SurroundingHexPointsCount(0);
  v13 = SurroundingHexPointsCount(iScanRadiusLast);
  CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(this, a2, &v11, &v12);
  for ( i = v14; ; ++i )
  {
    if ( i >= v13 )
      return 0;
    v3 = SSurroundingPoint8::X(&g_sSurroundingHexPoints8[i]);
    v17 = v21 + v3;
    v4 = SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[i]);
    v18 = v22 + v4;
    if ( CWorldManager::InWorld(v17, v22 + v4) )
    {
      v15 = CWorldManager::MapObjectId(v17, v18);
      if ( CWarriorBehavior::WarriorCheckTarget(v15, v11, v12) )
        break;
    }
  }
  v10 = CWorldManager::SectorId(v21, v22);
  uPadding = g_sSurroundingHexPoints8[i].m_uPadding;
  v16 = (uPadding + CStateGame::Rand(g_pGame) % 3 + 2) % 6;
  CSectorSpiralWalk::CSectorSpiralWalk(
    (CSectorSpiralWalk *)v7,
    v21 + 6 * g_sNeighborPoints[v16].x,
    v22 + 6 * g_sNeighborPoints[v16].y,
    4,
    v10);
  if ( !CSectorSpiralWalk::NextXY((CSectorSpiralWalk *)v7, &v8, &v9) )
    return 0;
  if ( a3 )
    *a3 = Y16X16::PackXYFast(v8, v9);
  return v15;
}


// address=[0x15ae0f0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorVehicleAttackScan31(  CWarriorBehavior *this,  struct IMovingEntity *a2,  struct CWarriorBehavior::SWarriorScanResult *a3)
void  CWarriorBehavior::WarriorVehicleAttackScan31(class IMovingEntity & a2, struct CWarriorBehavior::SWarriorScanResult & a3) {
  
  const struct CVWList::SVW *v3; // eax
  CWarMapNode *v4; // eax
  const struct CVWList::SVW *v5; // eax
  CWarMapNode *v6; // eax
  CWarriorProperties *v7; // eax
  int result; // eax
  int v9; // [esp+0h] [ebp-184h]
  int v10; // [esp+4h] [ebp-180h]
  int v11; // [esp+8h] [ebp-17Ch]
  int v12; // [esp+Ch] [ebp-178h]
  int v13; // [esp+14h] [ebp-170h]
  int m_iRadiusLast; // [esp+18h] [ebp-16Ch]
  T_AI_WARRIOR_TYPE v15; // [esp+1Ch] [ebp-168h]
  int v16; // [esp+20h] [ebp-164h]
  int v17; // [esp+24h] [ebp-160h]
  int m_iV; // [esp+28h] [ebp-15Ch]
  int v19; // [esp+38h] [ebp-14Ch]
  int v20; // [esp+3Ch] [ebp-148h]
  int v21; // [esp+40h] [ebp-144h]
  int v22; // [esp+44h] [ebp-140h] BYREF
  int v23; // [esp+48h] [ebp-13Ch] BYREF
  char v24[4]; // [esp+4Ch] [ebp-138h] BYREF
  __int64 v25; // [esp+50h] [ebp-134h]
  int v26; // [esp+58h] [ebp-12Ch]
  int v27; // [esp+5Ch] [ebp-128h]
  int v28; // [esp+60h] [ebp-124h]
  int v29; // [esp+64h] [ebp-120h]
  int v30; // [esp+68h] [ebp-11Ch]
  unsigned int v31; // [esp+6Ch] [ebp-118h]
  unsigned int v32; // [esp+70h] [ebp-114h]
  int v33; // [esp+74h] [ebp-110h]
  int v34; // [esp+78h] [ebp-10Ch]
  int m; // [esp+7Ch] [ebp-108h]
  IEntity *v36; // [esp+80h] [ebp-104h]
  int j; // [esp+84h] [ebp-100h]
  int k; // [esp+8Ch] [ebp-F8h]
  IEntity *v40; // [esp+90h] [ebp-F4h]
  int v41; // [esp+94h] [ebp-F0h]
  int i; // [esp+98h] [ebp-ECh]
  int v43; // [esp+9Ch] [ebp-E8h]
  CVWList v44; // [esp+A0h] [ebp-E4h] BYREF

  CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(this, a2, &v22, &v23);
  m_iRadiusLast = this->m_sWarriorBehaviorData.m_pProperties->m_iRadiusLast;
  v31 = IEntity::X(a2);
  v32 = IEntity::Y(a2);
  CVWList::CVWList(&v44, v31, v32, 0x1Fu);
  CTmpEntitiesRef::CTmpEntitiesRef((CTmpEntitiesRef *)v24);
  v29 = 0;
  v43 = 0;
  v33 = 0x4000;
  v28 = 0x4000;
  v9 = CVWList::Size(&v44);
  for ( i = 0; i < v9; ++i )
  {
    m_iV = CVWList::operator[](&v44, i)->m_iV;
    v3 = CVWList::operator[](&v44, i);
    for ( j = CWarMap::FirstEntityIdVW(1, m_iV, v3->m_iW); j; j = CWarMapNode::Next(v4) )
    {
      v40 = CTmpEntitiesRef::operator[](j);
      if ( CWarriorBehavior::WarriorCheckTarget(v40, v22, v23) )
      {
        v16 = IEntity::X(v40);
        v17 = IEntity::Y(v40);
        v41 = Grid::Distance(v16 - v31, v17 - v32);
        v15 = IEntity::WarriorType(v40);
        v27 = this->m_sWarriorBehaviorData.m_pProperties->m_iU3[v15];
        if ( v27 >= 4 && v41 < v28 )
          v28 = v41;
        if ( v41 > m_iRadiusLast )
          v26 = 0;
        else
          v26 = 10;
        HIDWORD(v25) = v26 + v27 > v43;
        LODWORD(v25) = v41 < v33;
        if ( v25 )
        {
          v29 = j;
          v43 = v26 + v27;
          v33 = v41;
        }
      }
      v4 = IEntity::WarMapNode(v40);
    }
  }
  v20 = CWarriorBehavior::WarriorProperties(this)->m_iU3[12];
  if ( v43 < v20 + 10 )
  {
    v30 = 0;
    v34 = 0x4000;
    v13 = CVWList::Size(&v44);
    for ( k = 0; k < v13; ++k )
    {
      v12 = CVWList::operator[](&v44, k)->m_iV;
      v5 = CVWList::operator[](&v44, k);
      for ( m = CWarMap::FirstEntityIdVW(2, v12, v5->m_iW); m; m = CWarMapNode::Next(v6) )
      {
        v36 = CTmpEntitiesRef::operator[](m);
        if ( CWarriorBehavior::WarriorCheckTarget(v36, v22, v23) )
        {
          v10 = IEntity::X(v36);
          v11 = IEntity::Y(v36);
          v21 = Grid::Distance(v10 - v31, v11 - v32);
          if ( v21 < v34 )
          {
            v30 = m;
            v34 = v21;
          }
        }
        v6 = IEntity::WarMapNode(v36);
      }
    }
    if ( v30 > 0 )
    {
      v7 = CWarriorBehavior::WarriorProperties(this);
      v19 = v34 > v7->m_iRadiusLast ? 0 : 10;
      if ( v19 + v20 > v43 )
      {
        v29 = v30;
        v43 = v19 + v20;
        v33 = v34;
      }
    }
  }
  *(_DWORD *)a3 = v29;
  *((_DWORD *)a3 + 1) = v43;
  *((_DWORD *)a3 + 2) = v33;
  result = v28;
  *((_DWORD *)a3 + 3) = v28;
  return result;
}


// address=[0x15ae660]
// Decompiled from void __thiscall CWarriorBehavior::WarriorVehicleIdleWalkOneStep(CWarriorBehavior *this, struct IMovingEntity *a2)
void  CWarriorBehavior::WarriorVehicleIdleWalkOneStep(class IMovingEntity & a2) {
  
  this->WarriorTaskIdleWalk(this, a2);
}


// address=[0x15ae680]
// Decompiled from void __thiscall CWarriorBehavior::WarriorVehicleMoveWalkOneStep(CWarriorBehavior *this, struct IMovingEntity *a2)
void  CWarriorBehavior::WarriorVehicleMoveWalkOneStep(class IMovingEntity & a2) {
  
  int v2; // eax

  if ( (this->m_sWarriorBehaviorData.m_iU01 & 1) != 0 )
  {
    this->m_sWarriorBehaviorData.m_iU01 &= ~1u;
    v2 = CWarriorBehavior::WarriorDestinationXY(this);
    CWarriorBehavior::WarriorInitWalk(this, a2, v2);
  }
  if ( (this->WarriorTaskWalkOneStep(this, a2) & 0x70) != 0 )
    this->m_sWarriorBehaviorData.m_uU0 = 8;
}


// address=[0x15ae6f0]
// Decompiled from void __thiscall CWarriorBehavior::WarriorVehicleEscortWalkOneStep(CWarriorBehavior *this, struct IMovingEntity *a2)
void  CWarriorBehavior::WarriorVehicleEscortWalkOneStep(class IMovingEntity & a2) {
  
  int v2; // eax
  int v3; // [esp+8h] [ebp-10h]
  int v4; // [esp+Ch] [ebp-Ch]
  IEntity *v5; // [esp+10h] [ebp-8h]

  v4 = CWarriorBehavior::WarriorDestinationId((pairNode *)this);
  if ( v4 > 0 && (v5 = CMapObjectMgr::Entity(v4), (IEntity::Flags(v5) & ENTITY_FLAG_Ready) != 0) )
  {
    v3 = IEntity::PackedXY(v5);
    IEntity::WarriorType(v5);
    v2 = IEntity::PackedXY(a2);
    if ( Y16X16::DistanceFast(v3, v2) <= 9 )
    {
      this->WarriorTaskIdleWalk(this, a2);
    }
    else
    {
      CWarriorBehavior::WarriorPseudoInitWalk(this, a2, v3);
      this->WarriorTaskWalkOneStep(this, a2);
    }
  }
  else
  {
    this->WarriorTaskFinished(this, a2);
  }
}


// address=[0x15ae7b0]
// Decompiled from bool __thiscall CWarriorBehavior::IsValidTarget(CWarriorBehavior *this, struct IEntity *a2, struct IEntity *a3)
bool  CWarriorBehavior::IsValidTarget(class IMovingEntity const & a2, class IEntity const & a3) {
  
  int v4; // [esp+0h] [ebp-Ch] BYREF
  int v5; // [esp+4h] [ebp-8h] BYREF

  CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(this, a2, &v4, &v5);
  return CWarriorBehavior::WarriorCheckTarget(a3, v4, v5);
}


// address=[0x15ae7f0]
// Decompiled from BOOL __thiscall CWarriorBehavior::IsTargetInAtackRange(  CWarriorBehavior *this,  struct IMovingEntity *a2,  struct IEntity *a3)
bool  CWarriorBehavior::IsTargetInAtackRange(class IMovingEntity const & a2, class IEntity const & a3) {
  
  int m_iRadiusFirst; // [esp+0h] [ebp-2Ch]
  int v5; // [esp+4h] [ebp-28h]
  int v6; // [esp+8h] [ebp-24h]
  int v7; // [esp+Ch] [ebp-20h]
  int v8; // [esp+10h] [ebp-1Ch]
  int v9; // [esp+1Ch] [ebp-10h]
  int m_iRadiusLast; // [esp+28h] [ebp-4h]

  v5 = IEntity::X(a2);
  v7 = IEntity::Y(a2);
  v6 = IEntity::X(a3);
  v8 = IEntity::Y(a3);
  v9 = Grid::Distance(v6 - v5, v8 - v7);
  m_iRadiusFirst = CWarriorBehavior::WarriorProperties(this)->m_iRadiusFirst;
  m_iRadiusLast = CWarriorBehavior::WarriorProperties(this)->m_iRadiusLast;
  return v9 <= (IEntity::ObjType(a3) == CATAPULT_OBJ) + m_iRadiusLast && v9 >= m_iRadiusFirst;
}


// address=[0x15ae8c0]
// Decompiled from bool __thiscall CWarriorBehavior::WarriorCheckInflu1(CWarriorBehavior *this, IEntity *a2)
bool  CWarriorBehavior::WarriorCheckInflu1(class IMovingEntity & a2) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-8h]

  v4 = IEntity::X(a2);
  v5 = IEntity::Y(a2);
  v2 = IEntity::OwnerId(a2);
  v6 = CAlliances::AllianceId(v2);
  return CInfluMap::EnemyValueXY(v4, v5, v6) > 0;
}


// address=[0x15ae930]
// Decompiled from bool __thiscall CWarriorBehavior::WarriorCheckOwner9(CWarriorBehavior *this, struct IMovingEntity *a2)
bool  CWarriorBehavior::WarriorCheckOwner9(class IMovingEntity & a2) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-10h]
  Squares *v5; // [esp+8h] [ebp-Ch]
  Squares *v6; // [esp+Ch] [ebp-8h]

  v5 = (Squares *)IEntity::X(a2);
  v6 = (Squares *)IEntity::Y(a2);
  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = CAlliances::PlayerEnemyBits(v2);
  return (v4 & COwnerMap::OwnerBits9XY(v5, v6)) != 0;
}


// address=[0x15ae9a0]
// Decompiled from char __thiscall CWarriorBehavior::WarriorCheckMedic(CWarriorBehavior *this, struct IMovingEntity *a2)
bool  CWarriorBehavior::WarriorCheckMedic(class IMovingEntity & a2) {
  
  return 1;
}


// address=[0x15ae9b0]
// Decompiled from char __thiscall CWarriorBehavior::WarriorCheckSaboteur(CWarriorBehavior *this, struct IMovingEntity *a2)
bool  CWarriorBehavior::WarriorCheckSaboteur(class IMovingEntity & a2) {
  
  return 1;
}


// address=[0x15afe80]
// Decompiled from void __thiscall CWarriorBehavior::WarriorVehicleAttackTarget(CWarriorBehavior *this, struct IMovingEntity *a2, int a3)
void  CWarriorBehavior::WarriorVehicleAttackTarget(class IMovingEntity & a2, int a3) {
  
  this->m_sWarriorBehaviorData.m_iU01 |= 1u;
  CWarriorBehavior::WarriorAttackTarget(this, a2, a3);
}


// address=[0x153fdd0]
// Decompiled from CWarriorBehavior::SWarriorBehaviorData *__thiscall CWarriorBehavior::GetWarriorBehaviorData(CWarriorBehavior *this)
struct CWarriorBehavior::SWarriorBehaviorData &  CWarriorBehavior::GetWarriorBehaviorData(void) {
  
  return &this->m_sWarriorBehaviorData;
}


// address=[0x15ae9c0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorPseudoInitWalk(CWarriorBehavior *this, struct IMovingEntity *a2, int a3)
int  CWarriorBehavior::WarriorPseudoInitWalk(class IMovingEntity & a2, int a3) {
  
  int v3; // eax
  int v5; // [esp-4h] [ebp-20h]
  int v6; // [esp+0h] [ebp-1Ch]
  int v7; // [esp+4h] [ebp-18h]
  int v8; // [esp+8h] [ebp-14h]
  int v10; // [esp+10h] [ebp-Ch]
  int v11; // [esp+14h] [ebp-8h]
  int v12; // [esp+18h] [ebp-4h]

  v6 = IEntity::X(a2);
  v7 = IEntity::Y(a2);
  v12 = CWarriorBehavior::WarriorWalkDestinationXY(this, a2);
  v10 = Y16X16::UnpackXFast(a3);
  v11 = Y16X16::UnpackYFast(a3);
  v8 = Grid::Distance(v10 - v6, v11 - v7);
  if ( v12 < 0
    || v8 <= 4
    || (v5 = v11 - Y16X16::UnpackYFast(v12), v3 = Y16X16::UnpackXFast(v12), Grid::Distance(v10 - v3, v5) > 2) )
  {
    CWarriorBehavior::WarriorInitWalk(this, a2, a3);
  }
  return v8;
}


// address=[0x15aea80]
// Decompiled from int __thiscall CWarriorBehavior::FindAttackWayPoint(CWarriorBehavior *this, IEntity *a2, struct IEntity *a3)
int  CWarriorBehavior::FindAttackWayPoint(class IMovingEntity & a2, class IEntity & a3) {
  
  int v3; // esi
  int v4; // esi
  int v5; // eax
  int v7; // [esp+4h] [ebp-18h]
  unsigned int v8; // [esp+Ch] [ebp-10h]
  unsigned int v9; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]

  v7 = CSpiralOffsets::Last(this->m_sWarriorBehaviorData.m_pProperties->m_iRadiusLast);
  for ( i = 0; i <= v7; ++i )
  {
    v3 = IEntity::X(a3);
    v8 = CSpiralOffsets::DeltaX(i) + v3;
    v4 = IEntity::Y(a3);
    v9 = CSpiralOffsets::DeltaY(i) + v4;
    if ( CWorldManager::InWorld(v8, v9) )
    {
      v5 = IEntity::Type(a2);
      if ( CVehicleMgr::IsPositionFreeForVehicle((CVehicleMgr *)&g_cVehicleMgr, v8, v9, v5) )
        return Y16X16::PackXYFast(v8, v9);
    }
  }
  return 0;
}


// address=[0x15afa60]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackCheck(CWarriorBehavior *this, struct IMovingEntity *a2)
int  CWarriorBehavior::WarriorAttackCheck(class IMovingEntity & a2) {
  
  return this->m_sWarriorBehaviorData.m_pProperties->m_fpAttackCheck(this, a2);
}


// address=[0x15afa90]
// Decompiled from void __thiscall CWarriorBehavior::WarriorAttackTarget(CWarriorBehavior *this, struct IMovingEntity *a2, int a3)
void  CWarriorBehavior::WarriorAttackTarget(class IMovingEntity & a2, int a3) {
  
  this->WarriorTaskAttack(this, a2, a3, this->m_sWarriorBehaviorData.m_pProperties->m_iType);
}


// address=[0x15afad0]
// Decompiled from bool __cdecl CWarriorBehavior::WarriorCheckTarget(struct IEntity *a1, int a2, int a3)
bool __cdecl CWarriorBehavior::WarriorCheckTarget(class IEntity const & a1, int a2, int a3) {
  
  char v3; // al

  v3 = IEntity::OwnerId(a1);
  return (a2 & CAlliances::PlayerBit(v3)) != 0
      && CWarriorBehavior::WarriorTargetAllowableAndVulnerable((unsigned __int16 *)a1, a3);
}


// address=[0x15afb20]
// Decompiled from bool __cdecl CWarriorBehavior::WarriorCheckTarget(int a1, int a2, int a3)
bool __cdecl CWarriorBehavior::WarriorCheckTarget(int a1, int a2, int a3) {
  
  struct IEntity *v4; // [esp+0h] [ebp-8h]

  if ( !a1 )
    return 0;
  v4 = CMapObjectMgr::Entity(a1);
  return CWarriorBehavior::WarriorCheckTarget(v4, a2, a3);
}


// address=[0x15afb70]
// Decompiled from int __thiscall CWarriorBehavior::WarriorDestinationId(CWarriorBehavior *this)
int  CWarriorBehavior::WarriorDestinationId(void)const {
  
  return this->m_sWarriorBehaviorData.m_iDestinationXYOrId;
}


// address=[0x15afb90]
// Decompiled from void __thiscall CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(  CWarriorBehavior *this,  struct IEntity *a2,  int *_rBits,  int *_rScanMask)
void  CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(class IEntity const & a2, int & _rBits, int & _rScanMask) {
  
  int v4; // eax

  v4 = IEntity::OwnerId(a2);
  *_rBits = CAlliances::PlayerEnemyBits(v4);
  *_rScanMask = this->m_sWarriorBehaviorData.m_pProperties->m_uScanMask;
  if ( (*_rScanMask & 0x2000000) == 0
    && BBSupportDbgReport(2, "MapObjects\\WarriorBehavior.cpp", 447, "(_rScanMask & ENTITY_FLAG_READY) != 0") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x15afc10]
// Decompiled from void __thiscall CWarriorBehavior::WarriorInitWalk(CWarriorBehavior *this, struct IMovingEntity *a2, int a3)
void  CWarriorBehavior::WarriorInitWalk(class IMovingEntity & a2, int a3) {
  
  int v3; // [esp+0h] [ebp-Ch]
  struct CWalking *v4; // [esp+8h] [ebp-4h]

  v3 = this->m_sWarriorBehaviorData.m_iFlags & 0x1060 | 0x2000;
  v4 = IMovingEntity::Walking(a2);
  v4->InitB((CWalkingBase *)v4, a3, v3);
}


// address=[0x15afc70]
// Decompiled from bool __thiscall CWarriorBehavior::WarriorIsFullUpdate(CWarriorBehavior *this, unsigned int a2)
bool  CWarriorBehavior::WarriorIsFullUpdate(unsigned int a2)const {
  
  return a2 >= this->m_sWarriorBehaviorData.m_iNextFullUpdate;
}


// address=[0x15afcb0]
// Decompiled from CWarriorProperties *__thiscall CWarriorBehavior::WarriorProperties(CWarriorBehavior *this)
class CWarriorProperties const &  CWarriorBehavior::WarriorProperties(void)const {
  
  return this->m_sWarriorBehaviorData.m_pProperties;
}


// address=[0x15afcd0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorSetNextFullUpdate(CWarriorBehavior *this, unsigned int a2, unsigned int a3)
void  CWarriorBehavior::WarriorSetNextFullUpdate(unsigned int a2, unsigned int a3) {
  
  int result; // eax

  result = a3 + a2;
  *((_DWORD *)this + 5) = a3 + a2;
  return result;
}


// address=[0x15afcf0]
// Decompiled from bool __cdecl CWarriorBehavior::WarriorTargetAllowableAndVulnerable(IEntity *a1, int a2)
bool __cdecl CWarriorBehavior::WarriorTargetAllowableAndVulnerable(class IEntity const & a1, int a2) {
  
  int v3; // [esp+4h] [ebp-18h]
  int v4; // [esp+8h] [ebp-14h]
  BOOL v5; // [esp+10h] [ebp-Ch]
  bool v6; // [esp+1Bh] [ebp-1h]

  v6 = 0;
  if ( IEntity::Type(a1) == 1 && IEntity::ObjType(a1) == DECO_OBJ )
    return (IEntity::Flags(a1) & 0x2000000) != 0;
  v4 = IEntity::Flags(a1) & 0x2030100 ^ 0x2030100;
  v3 = 1 << IEntity::WarriorType(a1);
  if ( (IEntity::WarriorType(a1) || IEntity::ObjType(a1) == SETTLER_OBJ) && (IEntity::Flags(a1) & 0x8000000) == 0 )
    v6 = (a2 & (v3 | v4)) == 0;
  if ( !v6 )
    return v6;
  if ( IEntity::FlagBits(a1, ENTITY_FLAG_Ready) )
  {
    v5 = IEntity::FlagBits(a1, ENTITY_FLAG_VulnerableMask) != 0;
    if ( (IEntity::WarriorType(a1) == AI_WARRIOR_TYPE_NONE) != v5 )
      return v6;
  }
  if ( BBSupportDbgReport(
         2,
         "MapObjects\\WarriorBehavior.cpp",
         496,
         "!bResult || ((_rTarget.FlagBits(ENTITY_FLAG_READY) != 0) && ((_rTarget.FlagBits(ENTITY_FLAG_VULNERABLE_MASK) !="
         " 0) ^ (_rTarget.WarriorType() == WARRIOR_TYPE_NONE)))") == 1 )
    __debugbreak();
  return v6;
}


// address=[0x15afec0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorWalkDestinationXY(CWarriorBehavior *this, struct IMovingEntity *a2)
int  CWarriorBehavior::WarriorWalkDestinationXY(class IMovingEntity & a2) {
  
  struct CWalking *v2; // eax

  v2 = IMovingEntity::Walking(a2);
  return (*(int (__thiscall **)(struct CWalking *, CWarriorBehavior *, struct CWalking *))(*(_DWORD *)v2 + 44))(
           v2,
           this,
           v2);
}


