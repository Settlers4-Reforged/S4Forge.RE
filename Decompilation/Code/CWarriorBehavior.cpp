#include "CWarriorBehavior.h"

// Definitions for class CWarriorBehavior

// address=[0x1592e10]
// Decompiled from int __thiscall CWarriorBehavior::WarriorDestinationXY(pairNode *this)

int  CWarriorBehavior::WarriorDestinationXY(void)const {
  
  return *((_DWORD *)this + 3);
}


// address=[0x15ac3a0]
// Decompiled from CWarriorBehavior *__thiscall CWarriorBehavior::CWarriorBehavior(CWarriorBehavior *this)

 CWarriorBehavior::CWarriorBehavior(void) {
  
  *(_DWORD *)this = &CWarriorBehavior::_vftable_;
  j__memset((char *)this + 4, 0, 0x14u);
  *((_DWORD *)this + 1) = &dword_4159C28;
  return this;
}


// address=[0x15ac3e0]
// Decompiled from void __thiscall CWarriorBehavior::WarriorInit(CWarriorBehavior *this, struct IMovingEntity *a2, int a3, int a4)

void  CWarriorBehavior::WarriorInit(class IMovingEntity &,int,int) {
  
  int v4; // eax
  unsigned int v5; // eax
  int v6; // [esp+4h] [ebp-18h]
  char v7; // [esp+Ch] [ebp-10h]
  int *v8; // [esp+10h] [ebp-Ch]
  int v9; // [esp+14h] [ebp-8h]

  v9 = IEntity::WarriorType();
  v6 = IEntity::Type((unsigned __int16 *)a2);
  if ( v9 == 4 || v6 == 46 )
  {
    switch ( v6 )
    {
      case '#':
      case '$':
      case '%':
        v9 = 15;
        break;
      case '&':
      case '\'':
      case '(':
        v9 = 16;
        break;
      case ')':
      case '*':
      case '+':
        v9 = 17;
        break;
      case '.':
        v9 = 19;
        break;
      case '6':
        v9 = 18;
        break;
      case '=':
      case '>':
      case '?':
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
  *((_DWORD *)this + 1) = &dword_4159C28[25 * v9];
  if ( ((unsigned int)&dword_6FC800[3584] & a4) == 0 )
    a3 = -1;
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  *((_DWORD *)this + 3) = a3;
  v5 = v4 | a4 & 0xFFFFFFF0;
  *((_DWORD *)this + 4) = v5;
  v7 = 0;
  v8 = (int *)((unsigned int)&dword_6FC800[3584] & v5);
  if ( (int)((unsigned int)&dword_6FC800[3584] & v5) > (int)&dword_420320[229176] )
  {
    if ( v8 == dword_600000 )
    {
      v7 = 7;
    }
    else if ( v8 == &dword_6FC800[3584] )
    {
      *((_WORD *)this + 5) = a3;
      *((_BYTE *)this + 8) = 5;
      *((_BYTE *)this + 9) = 0;
      *((_DWORD *)this + 5) = 0;
      *((_DWORD *)this + 3) = 0;
      return;
    }
  }
  else if ( v8 == &dword_420320[229176] )
  {
    v7 = 6;
  }
  else if ( v8 == dword_100000 )
  {
    v7 = 1;
  }
  else if ( v8 == dword_200000 || v8 == dword_300000 )
  {
    v7 = 4;
  }
  *((_BYTE *)this + 8) = v7;
  *((_BYTE *)this + 9) = 0;
  *((_WORD *)this + 5) = 0;
  *((_DWORD *)this + 5) = 0;
  CWarriorBehavior::WarriorInitWalk(this, a2, a3);
}


// address=[0x15ac600]
// Decompiled from void __thiscall CWarriorBehavior::WarriorLogicUpdate(
        CWarriorBehavior *this,
        struct IMovingEntity *a2,
        unsigned int a3,
        char a4)

void  CWarriorBehavior::WarriorLogicUpdate(class IMovingEntity &,unsigned int,int) {
  
  int v4; // esi
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // [esp+Ch] [ebp-50h]
  Y16X16 *v10; // [esp+14h] [ebp-48h]
  int v11; // [esp+18h] [ebp-44h]
  int v12; // [esp+24h] [ebp-38h] BYREF
  BOOL v13; // [esp+28h] [ebp-34h]
  BOOL v14; // [esp+2Ch] [ebp-30h]
  int v15; // [esp+30h] [ebp-2Ch]
  int v16; // [esp+34h] [ebp-28h]
  struct IEntity *v17; // [esp+38h] [ebp-24h]
  int v18; // [esp+3Ch] [ebp-20h]
  int inited; // [esp+40h] [ebp-1Ch]
  int v20; // [esp+44h] [ebp-18h]
  int v21; // [esp+48h] [ebp-14h]
  int v22; // [esp+4Ch] [ebp-10h]
  int *v23; // [esp+50h] [ebp-Ch]
  pairNode *v24; // [esp+54h] [ebp-8h]
  bool IsFullUpdate; // [esp+5Bh] [ebp-1h]

  v24 = this;
  v23 = (int *)*((unsigned __int8 *)this + 8);
  if ( (int)v23 > 4 )
  {
    if ( (int)v23 > 8 )
    {
      if ( v23 == &dword_6FC800[3584] )
        return;
    }
    else
    {
      if ( v23 == (int *)8 )
      {
LABEL_66:
        *((_BYTE *)v24 + 8) = 0;
        (*(void (__thiscall **)(pairNode *, struct IMovingEntity *))(*(_DWORD *)v24 + 16))(v24, a2);
        return;
      }
      if ( v23 == (int *)6 )
      {
        if ( CWarriorBehavior::WarriorIsFullUpdate(v24, a3) )
          goto LABEL_55;
        v16 = *((unsigned __int16 *)v24 + 5);
        if ( !v16 )
        {
          (*(void (__thiscall **)(pairNode *, struct IMovingEntity *))(*(_DWORD *)v24 + 4))(v24, a2);
          return;
        }
        if ( !CWarriorBehavior::WarriorCheckTargetAndDistance(v24, a2, v16) )
        {
LABEL_55:
          CWarriorBehavior::WarriorSetNextFullUpdate(v24, a3, 0x1Eu);
          if ( (**((unsigned __int8 (__thiscall ***)(pairNode *, struct IMovingEntity *))v24 + 1))(v24, a2)
            && (v15 = CWarriorBehavior::WarriorAttackCheck(v24, a2), v15 > 0) )
          {
            *((_WORD *)v24 + 5) = v15;
            CWarriorBehavior::WarriorAttackTarget(v24, a2, v15);
          }
          else
          {
            *((_WORD *)v24 + 5) = 0;
            (*(void (__thiscall **)(pairNode *, struct IMovingEntity *))(*(_DWORD *)v24 + 4))(v24, a2);
          }
        }
        else
        {
          CWarriorBehavior::WarriorAttackTarget(v24, a2, v16);
        }
        return;
      }
      if ( v23 == (int *)7 )
      {
        if ( (**((unsigned __int8 (__thiscall ***)(pairNode *, struct IMovingEntity *))v24 + 1))(v24, a2)
          && (v18 = CWarriorBehavior::WarriorAttackCheck(v24, a2), v18 > 0) )
        {
          *((_WORD *)v24 + 5) = v18;
          CWarriorBehavior::WarriorAttackTarget(v24, a2, v18);
        }
        else
        {
          v11 = CWarriorBehavior::WarriorDestinationId(v24);
          if ( v11 > 0
            && (v17 = CMapObjectMgr::Entity(v11), (((unsigned int)&loc_1FFFFFF + 1) & IEntity::Flags(v17)) != 0) )
          {
            v10 = (Y16X16 *)IEntity::PackedXY(v17);
            v9 = IEntity::WarriorType();
            v8 = IEntity::PackedXY(a2);
            if ( Y16X16::DistanceFast(v10, v8) <= *(_DWORD *)(*((_DWORD *)v24 + 1) + 24) + dword_4159C40[25 * v9] + 1 )
            {
              (*(void (__thiscall **)(pairNode *, struct IMovingEntity *))(*(_DWORD *)v24 + 8))(v24, a2);
            }
            else
            {
              CWarriorBehavior::WarriorPseudoInitWalk(v24, a2, v10);
              (*(void (__thiscall **)(pairNode *, struct IMovingEntity *))(*(_DWORD *)v24 + 4))(v24, a2);
            }
          }
          else
          {
            *((_DWORD *)v24 + 3) = -1;
            *((_BYTE *)v24 + 8) = 8;
          }
        }
        return;
      }
    }
LABEL_64:
    if ( BBSupportDbgReport(
           1,
           "MapObjects\\WarriorBehavior.cpp",
           1166,
           "CWarriorBehavior::WarriorLogicUpdate(): Invalid state!") == 1 )
      __debugbreak();
    goto LABEL_66;
  }
  if ( v23 == (int *)4 )
  {
    if ( ((*(int (__thiscall **)(pairNode *, struct IMovingEntity *))(*(_DWORD *)v24 + 4))(v24, a2) & 0x70) != 0 )
      *((_BYTE *)v24 + 8) = 8;
  }
  else
  {
    if ( (int)v23 > 1 )
      goto LABEL_64;
    IsFullUpdate = CWarriorBehavior::WarriorIsFullUpdate(v24, a3);
    if ( !IsFullUpdate )
    {
      v21 = *((unsigned __int16 *)v24 + 5);
      if ( v21 )
      {
        if ( (a4 & 0x10) != 0 )
        {
          *((_BYTE *)v24 + 9) &= ~2u;
        }
        else
        {
          if ( (*(unsigned __int8 (__thiscall **)(pairNode *, struct IMovingEntity *, int))(*((_DWORD *)v24 + 1) + 4))(
                 v24,
                 a2,
                 v21) )
          {
            *((_BYTE *)v24 + 9) &= ~2u;
            CWarriorBehavior::WarriorAttackTarget(v24, a2, v21);
            return;
          }
          IsFullUpdate = (*((_BYTE *)v24 + 9) & 2) == 0;
        }
      }
    }
    if ( IsFullUpdate )
    {
      *((_BYTE *)v24 + 9) &= ~2u;
      CWarriorBehavior::WarriorSetNextFullUpdate(v24, a3, 0x1Eu);
      if ( (**((unsigned __int8 (__thiscall ***)(pairNode *, struct IMovingEntity *))v24 + 1))(v24, a2) )
      {
        if ( (a4 & 0x10) == 0 )
        {
          v20 = CWarriorBehavior::WarriorAttackCheck(v24, a2);
          if ( v20 > 0 )
          {
            *((_WORD *)v24 + 5) = v20;
            CWarriorBehavior::WarriorAttackTarget(v24, a2, v20);
            return;
          }
          v22 = (*(int (__thiscall **)(pairNode *, struct IMovingEntity *, int *))(*((_DWORD *)v24 + 1) + 12))(
                  v24,
                  a2,
                  &v12);
          v14 = v22 == 0;
          v13 = *(_DWORD *)(*((_DWORD *)v24 + 1) + 28) > 1;
          if ( v13 && v14 )
            v22 = CWarriorBehavior::WarriorEvadeScan15a(v24, a2, &v12);
          if ( v22 > 0 )
          {
            *((_BYTE *)v24 + 9) |= 2u;
            *((_WORD *)v24 + 5) = v22;
            inited = CWarriorBehavior::WarriorPseudoInitWalk(v24, a2, v12);
            if ( inited <= 8 )
            {
              if ( inited <= 0 && BBSupportDbgReport(2, "MapObjects\\WarriorBehavior.cpp", 961, "iDistance > 0") == 1 )
                __debugbreak();
              CWarriorBehavior::WarriorSetNextFullUpdate(v24, a3, 4 * inited - 4);
            }
          }
        }
      }
    }
    if ( *((_WORD *)v24 + 5) != 0 && (*((_BYTE *)v24 + 9) & 2) == 0 )
    {
      *((_WORD *)v24 + 5) = 0;
      v4 = CWarriorBehavior::WarriorDestinationXY(v24);
      if ( v4 != CWarriorBehavior::WarriorWalkDestinationXY(v24, a2) )
      {
        v5 = CWarriorBehavior::WarriorDestinationXY(v24);
        CWarriorBehavior::WarriorInitWalk(v24, a2, v5);
      }
    }
    if ( ((*(int (__thiscall **)(pairNode *, struct IMovingEntity *))(*(_DWORD *)v24 + 4))(v24, a2) & 0x70) != 0
      && CWarriorBehavior::WarriorDestinationXY(v24) != -1 )
    {
      v6 = CWarriorBehavior::WarriorDestinationXY(v24);
      if ( v6 == CWarriorBehavior::WarriorWalkDestinationXY(v24, a2) )
      {
        *((_BYTE *)v24 + 8) = 8;
      }
      else
      {
        v7 = CWarriorBehavior::WarriorDestinationXY(v24);
        CWarriorBehavior::WarriorInitWalk(v24, a2, v7);
      }
    }
  }
}


// address=[0x15acbd0]
// Decompiled from void __thiscall CWarriorBehavior::WarriorVehicleLogicUpdate(
        CWarriorBehavior *this,
        struct IEntity *a2,
        unsigned int a3,
        char a4)

void  CWarriorBehavior::WarriorVehicleLogicUpdate(class IMovingEntity &,unsigned int,int) {
  
  Y16X16 *v4; // eax
  int v5; // esi
  const struct CWarriorProperties *v6; // eax
  int v7; // [esp-4h] [ebp-6Ch]
  int v8; // [esp+8h] [ebp-60h] BYREF
  int v9; // [esp+Ch] [ebp-5Ch] BYREF
  BOOL v10; // [esp+10h] [ebp-58h]
  BOOL v11; // [esp+14h] [ebp-54h]
  unsigned int v12; // [esp+18h] [ebp-50h]
  unsigned int v13; // [esp+1Ch] [ebp-4Ch]
  int v14; // [esp+20h] [ebp-48h]
  int v15; // [esp+24h] [ebp-44h]
  int AttackWayPoint; // [esp+28h] [ebp-40h]
  bool v17; // [esp+2Fh] [ebp-39h]
  struct IEntity *v18; // [esp+30h] [ebp-38h]
  unsigned int v19; // [esp+34h] [ebp-34h]
  int v20; // [esp+38h] [ebp-30h]
  const struct IEntity *v21; // [esp+3Ch] [ebp-2Ch]
  int (__stdcall *v22)(int); // [esp+40h] [ebp-28h]
  int v24; // [esp+48h] [ebp-20h]
  bool IsFullUpdate; // [esp+4Eh] [ebp-1Ah]
  bool v26; // [esp+4Fh] [ebp-19h]
  CWarriorBehavior *v27; // [esp+50h] [ebp-18h]
  int v28; // [esp+54h] [ebp-14h] BYREF
  unsigned int v29; // [esp+58h] [ebp-10h]
  int v30; // [esp+5Ch] [ebp-Ch]

  v27 = this;
  v26 = (a4 & 3) == 0;
  v17 = v26;
  v15 = *((unsigned __int8 *)this + 8);
  switch ( v15 )
  {
    case 0:
    case 1:
    case 7:
      if ( *((_BYTE *)v27 + 8) )
      {
        if ( *((_BYTE *)v27 + 8) == 1 )
          v22 = (int (__stdcall *)(int))CWarriorBehavior::WarriorVehicleMoveWalkOneStep;
        else
          v22 = j_CWarriorBehavior::WarriorVehicleEscortWalkOneStep;
      }
      else
      {
        v22 = (int (__stdcall *)(int))CWarriorBehavior::WarriorVehicleIdleWalkOneStep;
      }
      if ( (a4 & 2) != 0 )
      {
        *((_WORD *)v27 + 5) = 0;
        ((void (__thiscall *)(CWarriorBehavior *, struct IEntity *))v22)(v27, a2);
        return;
      }
      IsFullUpdate = CWarriorBehavior::WarriorIsFullUpdate(v27, a3);
      v24 = *((unsigned __int16 *)v27 + 5);
      if ( v24 )
      {
        v21 = (const struct IEntity *)CMapObjectMgr::EntityPtr(v24);
        CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(v27, a2, &v8, &v9);
        if ( v21 && CWarriorBehavior::WarriorCheckTarget(v21, v8, v9) )
        {
          v7 = IEntity::PackedXY(v21);
          v4 = (Y16X16 *)IEntity::PackedXY(a2);
          v12 = Y16X16::DistanceFast(v4, v7);
          v5 = *((_DWORD *)v27 + 1);
          v19 = *(_DWORD *)(v5 + 4 * IEntity::WarriorType() + 40);
          v6 = CWarriorBehavior::WarriorProperties(v27);
          if ( v12 > *((_DWORD *)v6 + 8) )
            v14 = 0;
          else
            v14 = 10;
          v19 += v14;
        }
        else
        {
          v24 = 0;
          IsFullUpdate = 1;
        }
      }
      if ( (a4 & 1) != 0 )
      {
        if ( v24 )
          (*(void (__thiscall **)(CWarriorBehavior *, struct IEntity *))(*(_DWORD *)v27 + 8))(v27, a2);
        else
          ((void (__thiscall *)(CWarriorBehavior *, struct IEntity *))v22)(v27, a2);
        return;
      }
      if ( IsFullUpdate )
      {
        CWarriorBehavior::WarriorVehicleAttackScan31(
          v27,
          (struct IMovingEntity *)a2,
          (struct CWarriorBehavior::SWarriorScanResult *)&v28);
        v20 = v28;
        if ( v28 )
        {
          CWarriorBehavior::WarriorSetNextFullUpdate(v27, a3, 0x14u);
          v13 = v29;
          if ( v29 > 0xA )
          {
            if ( v24 )
            {
              v11 = v19 >= v13;
              v10 = v12 <= 2 * v30;
              if ( v10 && v11 )
                v20 = v24;
            }
            *((_WORD *)v27 + 5) = v20;
            CWarriorBehavior::WarriorVehicleAttackTarget(v27, (struct IMovingEntity *)a2, v20);
            return;
          }
        }
        else
        {
          CWarriorBehavior::WarriorSetNextFullUpdate(v27, a3, 0x28u);
        }
LABEL_36:
        *((_WORD *)v27 + 5) = 0;
        ((void (__thiscall *)(CWarriorBehavior *, struct IEntity *))v22)(v27, a2);
        return;
      }
      if ( !v24 || v19 <= 0xA )
        goto LABEL_36;
      if ( *((unsigned __int16 *)v27 + 5) != v24
        && BBSupportDbgReport(
             2,
             "MapObjects\\WarriorBehavior.cpp",
             1411,
             "m_sWarriorBehaviorData.m_uLastTargetId == uLastTargetId") == 1 )
      {
        __debugbreak();
      }
      CWarriorBehavior::WarriorVehicleAttackTarget(v27, (struct IMovingEntity *)a2, v24);
      return;
    case 4:
      CWarriorBehavior::WarriorVehicleMoveWalkOneStep(v27, (struct IMovingEntity *)a2);
      return;
    case 5:
      if ( !CMapObjectMgr::ValidUsedEntityId(*((unsigned __int16 *)v27 + 5)) )
        goto LABEL_39;
      v18 = CMapObjectMgr::Entity(*((unsigned __int16 *)v27 + 5));
      if ( !*((_DWORD *)v27 + 3) )
        *((_DWORD *)v27 + 3) = CWarriorBehavior::FindAttackWayPoint(v27, (struct IMovingEntity *)a2, v18);
      if ( *((int *)v27 + 3) > 0 )
      {
        *((_BYTE *)v27 + 9) |= 1u;
        CWarriorBehavior::WarriorInitWalk(v27, (struct IMovingEntity *)a2, *((_DWORD *)v27 + 3));
      }
      if ( !CWarriorBehavior::WarriorIsFullUpdate(v27, a3) )
        goto LABEL_51;
      if ( !CMapObjectMgr::ValidUsedEntityId(*((unsigned __int16 *)v27 + 5))
        || !IEntity::FlagBits(v18, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
      {
        goto LABEL_39;
      }
      AttackWayPoint = CWarriorBehavior::FindAttackWayPoint(v27, (struct IMovingEntity *)a2, v18);
      if ( AttackWayPoint && AttackWayPoint != *((_DWORD *)v27 + 3) )
      {
        *((_DWORD *)v27 + 3) = AttackWayPoint;
        *((_BYTE *)v27 + 9) |= 1u;
        CWarriorBehavior::WarriorInitWalk(v27, (struct IMovingEntity *)a2, *((_DWORD *)v27 + 3));
      }
LABEL_51:
      if ( *((int *)v27 + 3) > 0 && (a4 & 2) == 0 )
      {
        if ( CWarriorBehavior::IsTargetInAtackRange(v27, (const struct IMovingEntity *)a2, v18) )
        {
          if ( (a4 & 1) != 0 )
            (*(void (__thiscall **)(CWarriorBehavior *, struct IEntity *))(*(_DWORD *)v27 + 8))(v27, a2);
          else
            CWarriorBehavior::WarriorVehicleAttackTarget(
              v27,
              (struct IMovingEntity *)a2,
              *((unsigned __int16 *)v27 + 5));
        }
        else
        {
          CWarriorBehavior::WarriorVehicleMoveWalkOneStep(v27, (struct IMovingEntity *)a2);
        }
      }
      else
      {
LABEL_39:
        (*(void (__thiscall **)(CWarriorBehavior *, struct IEntity *))(*(_DWORD *)v27 + 16))(v27, a2);
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
      *((_BYTE *)v27 + 8) = 0;
      (*(void (__thiscall **)(CWarriorBehavior *, struct IEntity *))(*(_DWORD *)v27 + 16))(v27, a2);
      return;
  }
}


// address=[0x15ad0e0]
// Decompiled from bool __thiscall CWarriorBehavior::WarriorCheckTargetAndDistance(CWarriorBehavior *this, struct IEntity *a2, int a3)

bool  CWarriorBehavior::WarriorCheckTargetAndDistance(class IMovingEntity &,int) {
  
  int v4; // [esp+0h] [ebp-38h]
  int v5; // [esp+4h] [ebp-34h]
  int v6; // [esp+8h] [ebp-30h]
  int v7; // [esp+Ch] [ebp-2Ch]
  int v8; // [esp+10h] [ebp-28h]
  int v9; // [esp+14h] [ebp-24h] BYREF
  int v10; // [esp+18h] [ebp-20h] BYREF
  int v11; // [esp+24h] [ebp-14h]
  BOOL v12; // [esp+28h] [ebp-10h]
  int v13; // [esp+2Ch] [ebp-Ch]
  struct IEntity *v14; // [esp+30h] [ebp-8h]
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
  v11 = Grid::Distance((Grid *)(v6 - v5), v8 - v7);
  v4 = *(_DWORD *)(*((_DWORD *)v15 + 1) + 28);
  v13 = *(_DWORD *)(*((_DWORD *)v15 + 1) + 32);
  v12 = IEntity::ObjType((unsigned __int8 *)v14) == 4;
  return v11 <= v12 + v13 && v11 >= v4;
}


// address=[0x15ad1f0]
// Decompiled from bool __thiscall CWarriorBehavior::WarriorValidLastTargetMedic(CWarriorBehavior *this, struct IMovingEntity *a2, int a3)

bool  CWarriorBehavior::WarriorValidLastTargetMedic(class IMovingEntity &,int) {
  
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
// Decompiled from char __thiscall CWarriorBehavior::WarriorValidLastTargetAxeWarrior(
        CWarriorBehavior *this,
        struct IMovingEntity *a2,
        int a3)

bool  CWarriorBehavior::WarriorValidLastTargetAxeWarrior(class IMovingEntity &,int) {
  
  return 0;
}


// address=[0x15ad2b0]
// Decompiled from char __thiscall CWarriorBehavior::WarriorValidLastTargetSaboteur(
        CWarriorBehavior *this,
        struct IMovingEntity *a2,
        int a3)

bool  CWarriorBehavior::WarriorValidLastTargetSaboteur(class IMovingEntity &,int) {
  
  return 0;
}


// address=[0x15ad2c0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackCheck1(CWarriorBehavior *this, struct IEntity *a2)

int  CWarriorBehavior::WarriorAttackCheck1(class IMovingEntity &) {
  
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

int  CWarriorBehavior::WarriorAttackCheck15(class IMovingEntity &) {
  
  int v3; // eax
  int v4; // eax
  int v5; // [esp+4h] [ebp-40h] BYREF
  int v6; // [esp+8h] [ebp-3Ch] BYREF
  int v7; // [esp+Ch] [ebp-38h]
  int v8; // [esp+10h] [ebp-34h]
  int v9; // [esp+14h] [ebp-30h]
  int v10; // [esp+18h] [ebp-2Ch]
  int v11; // [esp+1Ch] [ebp-28h]
  int v12; // [esp+20h] [ebp-24h]
  int v13; // [esp+24h] [ebp-20h]
  int v14; // [esp+28h] [ebp-1Ch]
  int v15; // [esp+2Ch] [ebp-18h]
  int v16; // [esp+30h] [ebp-14h]
  int v17; // [esp+34h] [ebp-10h]
  CWarriorBehavior *v18; // [esp+38h] [ebp-Ch]
  int v19; // [esp+3Ch] [ebp-8h]
  int i; // [esp+40h] [ebp-4h]

  v18 = this;
  v19 = *(_DWORD *)(*((_DWORD *)this + 1) + 28);
  v16 = *(_DWORD *)(*((_DWORD *)this + 1) + 32);
  if ( v19 <= 0 )
    return -1;
  if ( v16 > 15 && BBSupportDbgReport(2, "MapObjects\\WarriorBehavior.cpp", 1779, "iRadiusLast <= 15") == 1 )
    __debugbreak();
  if ( v19 > v16 && BBSupportDbgReport(2, "MapObjects\\WarriorBehavior.cpp", 1780, "iRadiusFirst <= iRadiusLast") == 1 )
    __debugbreak();
  v8 = IEntity::X(a2);
  v7 = IEntity::Y(a2);
  CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(v18, a2, &v5, &v6);
  v9 = SurroundingHexPointsCount(v19 - 1);
  v14 = SurroundingHexPointsCount(v16);
  v10 = -1;
  v17 = 0;
  for ( i = v9; i < v14; ++i )
  {
    v3 = SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * i]);
    v12 = v8 + v3;
    v4 = SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * i]);
    v13 = v7 + v4;
    if ( (unsigned __int8)CWorldManager::InWorld(v12, v7 + v4) )
    {
      v15 = CWorldManager::MapObjectId(v12, v13);
      if ( CWarriorBehavior::WarriorCheckTarget(v15, v5, v6) )
      {
        CMapObjectMgr::Entity(v15);
        v11 = *(_DWORD *)(*((_DWORD *)v18 + 1) + 4 * IEntity::WarriorType() + 40);
        if ( v11 > v17 )
        {
          v10 = v15;
          v17 = v11;
          if ( v11 >= 8 )
            return v10;
          if ( v17 >= 4 && i + 200 < v14 )
            v14 = i + 200;
        }
      }
    }
  }
  return v10;
}


// address=[0x15ad6a0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackCheckBowman(CWarriorBehavior *this, struct IEntity *a2)

int  CWarriorBehavior::WarriorAttackCheckBowman(class IMovingEntity &) {
  
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  void *v4; // eax
  int v6; // [esp+4h] [ebp-38h]
  int v7; // [esp+8h] [ebp-34h]
  int v8; // [esp+Ch] [ebp-30h]
  int v9; // [esp+10h] [ebp-2Ch]
  int v10; // [esp+14h] [ebp-28h]
  int v11; // [esp+18h] [ebp-24h]
  int v12; // [esp+1Ch] [ebp-20h]
  int v13; // [esp+20h] [ebp-1Ch]
  int v14; // [esp+24h] [ebp-18h]
  int v15; // [esp+28h] [ebp-14h]
  int v17; // [esp+30h] [ebp-Ch]
  int NearestEntity; // [esp+34h] [ebp-8h]
  int i; // [esp+38h] [ebp-4h]

  v17 = CWarriorBehavior::WarriorAttackCheck15(this, a2);
  v13 = IEntity::X(a2);
  v14 = IEntity::Y(a2);
  v15 = -1;
  v11 = *(_DWORD *)(*((_DWORD *)this + 1) + 32);
  v9 = IEntity::OwnerId((unsigned __int8 *)a2);
  v8 = CAlliances::PlayerBit(v9);
  for ( i = 1; i <= CPlayerManager::NumberOfPlayers(); ++i )
  {
    if ( CPlayerManager::Race(i) == 3 && (v8 & CAlliances::PlayerAllyBits(i)) == 0 )
    {
      NearestEntity = CFlyingMgr::GetNearestEntity((CFlyingMgr *)g_cFlyingMgr, i, 1, v13, v14, 0);
      if ( NearestEntity )
      {
        v2 = (_DWORD *)CFlyingMgr::operator[](NearestEntity);
        if ( (((unsigned int)&loc_1FFFFFF + 1) & IEntity::Flags(v2)) != 0 )
        {
          v3 = (_DWORD *)CFlyingMgr::operator[](NearestEntity);
          v6 = IEntity::X(v3);
          v4 = (void *)CFlyingMgr::operator[](NearestEntity);
          v7 = IEntity::Y(v4);
          v12 = Grid::Distance((Grid *)(v6 - v13), v7 - v14);
          if ( v12 < v11 )
          {
            v11 = v12;
            v15 = NearestEntity;
          }
        }
      }
    }
  }
  if ( v15 == -1 )
    return v17;
  v10 = 0;
  if ( v17 != -1 )
  {
    CMapObjectMgr::Entity(v17);
    v10 = *(_DWORD *)(*((_DWORD *)this + 1) + 4 * IEntity::WarriorType() + 40);
  }
  if ( v10 <= 3 )
    return v15;
  return v17;
}


// address=[0x15ad840]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackCheckMedic(CWarriorBehavior *this, struct IEntity *a2)

int  CWarriorBehavior::WarriorAttackCheckMedic(class IMovingEntity &) {
  
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

int  CWarriorBehavior::WarriorAttackCheckAxeWarrior(class IMovingEntity &) {
  
  int v4; // [esp+4h] [ebp-4h]

  v4 = sub_15AEDC0(a2, 15, 2, 1, 0);
  if ( v4 <= 0 )
    return CWarriorBehavior::WarriorAttackCheck15(this, a2);
  else
    return v4;
}


// address=[0x15ad9c0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackCheckSaboteur(CWarriorBehavior *this, struct IMovingEntity *a2)

int  CWarriorBehavior::WarriorAttackCheckSaboteur(class IMovingEntity &) {
  
  int v4; // [esp+8h] [ebp-4h]

  v4 = sub_15AEDC0(a2, 15, 0, 0, 0);
  if ( v4 <= 0 )
    return -1;
  else
    return v4;
}


// address=[0x15ada00]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackScan15(CWarriorBehavior *this, struct IEntity *a2, int *a3)

int  CWarriorBehavior::WarriorAttackScan15(class IMovingEntity &,int *) {
  
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
  int v14; // [esp+20h] [ebp-14h]
  int v15; // [esp+24h] [ebp-10h]
  int v16; // [esp+28h] [ebp-Ch]
  CWarriorBehavior *v17; // [esp+2Ch] [ebp-8h]
  int i; // [esp+30h] [ebp-4h]

  v17 = this;
  v9 = IEntity::X(a2);
  v8 = IEntity::Y(a2);
  v12 = *(_DWORD *)(*((_DWORD *)v17 + 1) + 28) + 1;
  v14 = *(_DWORD *)(*((_DWORD *)v17 + 1) + 36);
  if ( v14 > 15 && BBSupportDbgReport(2, "MapObjects\\WarriorBehavior.cpp", 1987, (const char *)&dword_37C1324[1]) == 1 )
    __debugbreak();
  v11 = SurroundingHexPointsCount(v12 - 1);
  v10 = SurroundingHexPointsCount(v14);
  CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(v17, a2, &v6, &v7);
  for ( i = v11; ; ++i )
  {
    if ( i >= v10 )
      return 0;
    v3 = SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * i]);
    v15 = v9 + v3;
    v4 = SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * i]);
    v16 = v8 + v4;
    if ( (unsigned __int8)CWorldManager::InWorld(v15, v8 + v4) )
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

int  CWarriorBehavior::WarriorAttackScanBowman(class IMovingEntity &,int *) {
  
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

int  CWarriorBehavior::WarriorAttackScanMedic(class IMovingEntity &,int *) {
  
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

int  CWarriorBehavior::WarriorAttackScanAxeWarrior(class IMovingEntity &,int *) {
  
  int v5; // [esp+4h] [ebp-4h]

  v5 = sub_15AEDC0(a2, 21, 8, 1, a3);
  if ( v5 <= 0 )
    return CWarriorBehavior::WarriorAttackScan15(this, a2, a3);
  else
    return v5;
}


// address=[0x15adee0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackScanSaboteur(CWarriorBehavior *this, struct IMovingEntity *a2, int *a3)

int  CWarriorBehavior::WarriorAttackScanSaboteur(class IMovingEntity &,int *) {
  
  return sub_15AEDC0(a2, 21, -12, 0, a3);
}


// address=[0x15adf10]
// Decompiled from int __thiscall CWarriorBehavior::WarriorEvadeScan15a(CWarriorBehavior *this, struct IEntity *a2, int *a3)

int  CWarriorBehavior::WarriorEvadeScan15a(class IMovingEntity &,int *) {
  
  int v3; // eax
  int v4; // eax
  int v5; // esi
  _BYTE v7[20]; // [esp+4h] [ebp-54h] BYREF
  int v8; // [esp+18h] [ebp-40h] BYREF
  int v9; // [esp+1Ch] [ebp-3Ch] BYREF
  int v10; // [esp+20h] [ebp-38h]
  int v11; // [esp+24h] [ebp-34h] BYREF
  int v12; // [esp+28h] [ebp-30h] BYREF
  int v13; // [esp+2Ch] [ebp-2Ch]
  int v14; // [esp+30h] [ebp-28h]
  int v15; // [esp+34h] [ebp-24h]
  unsigned int v16; // [esp+38h] [ebp-20h]
  int v17; // [esp+3Ch] [ebp-1Ch]
  int v18; // [esp+40h] [ebp-18h]
  CWarriorBehavior *v19; // [esp+44h] [ebp-14h]
  int v20; // [esp+48h] [ebp-10h]
  int v21; // [esp+4Ch] [ebp-Ch]
  int v22; // [esp+50h] [ebp-8h]
  int i; // [esp+54h] [ebp-4h]

  v19 = this;
  v21 = IEntity::X(a2);
  v22 = IEntity::Y(a2);
  v20 = *(_DWORD *)(*((_DWORD *)v19 + 1) + 28) - 1;
  if ( v20 < 1 && BBSupportDbgReport(2, "MapObjects\\WarriorBehavior.cpp", 2128, "iScanRadiusLast >= 1") == 1 )
    __debugbreak();
  v14 = SurroundingHexPointsCount(0);
  v13 = SurroundingHexPointsCount(v20);
  CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(v19, a2, &v11, &v12);
  for ( i = v14; ; ++i )
  {
    if ( i >= v13 )
      return 0;
    v3 = SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * i]);
    v17 = v21 + v3;
    v4 = SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * i]);
    v18 = v22 + v4;
    if ( (unsigned __int8)CWorldManager::InWorld(v17, v22 + v4) )
    {
      v15 = CWorldManager::MapObjectId(v17, v18);
      if ( CWarriorBehavior::WarriorCheckTarget(v15, v11, v12) )
        break;
    }
  }
  v10 = CWorldManager::SectorId(v21, v22);
  v5 = (unsigned __int8)byte_37D8D93[4 * i];
  v16 = (v5 + CStateGame::Rand(g_pGame) % 3u + 2) % 6;
  CSectorSpiralWalk::CSectorSpiralWalk(
    (CSectorSpiralWalk *)v7,
    v21 + 6 * g_sNeighborPoints[2 * v16],
    v22 + 6 * dword_37D8C0C[2 * v16],
    4,
    v10);
  if ( !CSectorSpiralWalk::NextXY((CSectorSpiralWalk *)v7, &v8, &v9) )
    return 0;
  if ( a3 )
    *a3 = Y16X16::PackXYFast(v8, v9);
  return v15;
}


// address=[0x15ae0f0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorVehicleAttackScan31(
        CWarriorBehavior *this,
        struct IEntity *a2,
        struct CWarriorBehavior::SWarriorScanResult *a3)

void  CWarriorBehavior::WarriorVehicleAttackScan31(class IMovingEntity &,struct CWarriorBehavior::SWarriorScanResult &) {
  
  int v3; // eax
  struct CPtrList *v4; // eax
  int v5; // eax
  struct CPtrList *v6; // eax
  const struct CWarriorProperties *v7; // eax
  int result; // eax
  int v9; // [esp+0h] [ebp-184h]
  int v10; // [esp+4h] [ebp-180h]
  int v11; // [esp+8h] [ebp-17Ch]
  int v12; // [esp+Ch] [ebp-178h]
  int v13; // [esp+14h] [ebp-170h]
  int v14; // [esp+18h] [ebp-16Ch]
  int v15; // [esp+20h] [ebp-164h]
  int v16; // [esp+24h] [ebp-160h]
  int v17; // [esp+28h] [ebp-15Ch]
  int v18; // [esp+38h] [ebp-14Ch]
  int v19; // [esp+3Ch] [ebp-148h]
  int v20; // [esp+40h] [ebp-144h]
  int v21; // [esp+44h] [ebp-140h] BYREF
  int v22; // [esp+48h] [ebp-13Ch] BYREF
  char v23[4]; // [esp+4Ch] [ebp-138h] BYREF
  __int64 v24; // [esp+50h] [ebp-134h]
  int v25; // [esp+58h] [ebp-12Ch]
  int v26; // [esp+5Ch] [ebp-128h]
  int v27; // [esp+60h] [ebp-124h]
  int v28; // [esp+64h] [ebp-120h]
  int v29; // [esp+68h] [ebp-11Ch]
  int v30; // [esp+6Ch] [ebp-118h]
  int v31; // [esp+70h] [ebp-114h]
  int v32; // [esp+74h] [ebp-110h]
  int v33; // [esp+78h] [ebp-10Ch]
  int m; // [esp+7Ch] [ebp-108h]
  CPropertySet *v35; // [esp+80h] [ebp-104h]
  int j; // [esp+84h] [ebp-100h]
  CWarriorBehavior *v37; // [esp+88h] [ebp-FCh]
  int k; // [esp+8Ch] [ebp-F8h]
  CPropertySet *v39; // [esp+90h] [ebp-F4h]
  int v40; // [esp+94h] [ebp-F0h]
  int i; // [esp+98h] [ebp-ECh]
  int v42; // [esp+9Ch] [ebp-E8h]
  _BYTE v43[224]; // [esp+A0h] [ebp-E4h] BYREF

  v37 = this;
  CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(this, a2, &v21, &v22);
  v14 = *(_DWORD *)(*((_DWORD *)v37 + 1) + 32);
  v30 = IEntity::X(a2);
  v31 = IEntity::Y(a2);
  CVWList::CVWList((CVWList *)v43, v30, v31, 31);
  CTmpEntitiesRef::CTmpEntitiesRef((CTmpEntitiesRef *)v23);
  v28 = 0;
  v42 = 0;
  v32 = 0x4000;
  v27 = 0x4000;
  v9 = CVWList::Size((CVWList *)v43);
  for ( i = 0; i < v9; ++i )
  {
    v17 = *(_DWORD *)CVWList::operator[](i);
    v3 = CVWList::operator[](i);
    for ( j = CWarMap::FirstEntityIdVW(1, v17, *(_DWORD *)(v3 + 4)); j; j = CWarMapNode::Next(v4) )
    {
      v39 = (CPropertySet *)CTmpEntitiesRef::operator[](j);
      if ( CWarriorBehavior::WarriorCheckTarget((const struct IEntity *)v39, v21, v22) )
      {
        v15 = IEntity::X(v39);
        v16 = IEntity::Y(v39);
        v40 = Grid::Distance((Grid *)(v15 - v30), v16 - v31);
        v26 = *(_DWORD *)(*((_DWORD *)v37 + 1) + 4 * IEntity::WarriorType() + 40);
        if ( v26 >= 4 && v40 < v27 )
          v27 = v40;
        if ( v40 > v14 )
          v25 = 0;
        else
          v25 = 10;
        HIDWORD(v24) = v25 + v26 > v42;
        LODWORD(v24) = v40 < v32;
        if ( v24 )
        {
          v28 = j;
          v42 = v25 + v26;
          v32 = v40;
        }
      }
      v4 = IEntity::WarMapNode(v39);
    }
  }
  v19 = *((_DWORD *)CWarriorBehavior::WarriorProperties(v37) + 22);
  if ( v42 < v19 + 10 )
  {
    v29 = 0;
    v33 = 0x4000;
    v13 = CVWList::Size((CVWList *)v43);
    for ( k = 0; k < v13; ++k )
    {
      v12 = *(_DWORD *)CVWList::operator[](k);
      v5 = CVWList::operator[](k);
      for ( m = CWarMap::FirstEntityIdVW(2, v12, *(_DWORD *)(v5 + 4)); m; m = CWarMapNode::Next(v6) )
      {
        v35 = (CPropertySet *)CTmpEntitiesRef::operator[](m);
        if ( CWarriorBehavior::WarriorCheckTarget((const struct IEntity *)v35, v21, v22) )
        {
          v10 = IEntity::X(v35);
          v11 = IEntity::Y(v35);
          v20 = Grid::Distance((Grid *)(v10 - v30), v11 - v31);
          if ( v20 < v33 )
          {
            v29 = m;
            v33 = v20;
          }
        }
        v6 = IEntity::WarMapNode(v35);
      }
    }
    if ( v29 > 0 )
    {
      v7 = CWarriorBehavior::WarriorProperties(v37);
      v18 = v33 > *((_DWORD *)v7 + 8) ? 0 : 10;
      if ( v18 + v19 > v42 )
      {
        v28 = v29;
        v42 = v18 + v19;
        v32 = v33;
      }
    }
  }
  *(_DWORD *)a3 = v28;
  *((_DWORD *)a3 + 1) = v42;
  *((_DWORD *)a3 + 2) = v32;
  result = v27;
  *((_DWORD *)a3 + 3) = v27;
  return result;
}


// address=[0x15ae660]
// Decompiled from int __thiscall CWarriorBehavior::WarriorVehicleIdleWalkOneStep(CWarriorBehavior *this, struct IMovingEntity *a2)

void  CWarriorBehavior::WarriorVehicleIdleWalkOneStep(class IMovingEntity &) {
  
  return (*(int (__thiscall **)(CWarriorBehavior *, struct IMovingEntity *))(*(_DWORD *)this + 8))(this, a2);
}


// address=[0x15ae680]
// Decompiled from int __thiscall CWarriorBehavior::WarriorVehicleMoveWalkOneStep(CWarriorBehavior *this, struct IMovingEntity *a2)

void  CWarriorBehavior::WarriorVehicleMoveWalkOneStep(class IMovingEntity &) {
  
  int v2; // eax
  int result; // eax

  if ( (*((_BYTE *)this + 9) & 1) != 0 )
  {
    *((_BYTE *)this + 9) &= ~1u;
    v2 = CWarriorBehavior::WarriorDestinationXY(this);
    CWarriorBehavior::WarriorInitWalk(this, a2, v2);
  }
  result = (*(int (__thiscall **)(CWarriorBehavior *, struct IMovingEntity *))(*(_DWORD *)this + 4))(this, a2);
  if ( (result & 0x70) != 0 )
    *((_BYTE *)this + 8) = 8;
  return result;
}


// address=[0x15ae6f0]
// Decompiled from // public: void __thiscall CWarriorBehavior::WarriorVehicleEscortWalkOneStep(class IMovingEntity &)
int __thiscall CWarriorBehavior::WarriorVehicleEscortWalkOneStep(pairNode *this, struct IMovingEntity *a2)

void  CWarriorBehavior::WarriorVehicleEscortWalkOneStep(class IMovingEntity &) {
  
  int v2; // eax
  Y16X16 *v4; // [esp+8h] [ebp-10h]
  int v5; // [esp+Ch] [ebp-Ch]
  struct IEntity *v6; // [esp+10h] [ebp-8h]

  v5 = CWarriorBehavior::WarriorDestinationId(this);
  if ( v5 <= 0 )
    return (*(int (__thiscall **)(pairNode *, struct IMovingEntity *))(*(_DWORD *)this + 16))(this, a2);
  v6 = CMapObjectMgr::Entity(v5);
  if ( (((unsigned int)&loc_1FFFFFF + 1) & IEntity::Flags(v6)) == 0 )
    return (*(int (__thiscall **)(pairNode *, struct IMovingEntity *))(*(_DWORD *)this + 16))(this, a2);
  v4 = (Y16X16 *)IEntity::PackedXY(v6);
  IEntity::WarriorType();
  v2 = IEntity::PackedXY(a2);
  if ( (int)Y16X16::DistanceFast(v4, v2) <= 9 )
    return (*(int (__thiscall **)(pairNode *, struct IMovingEntity *))(*(_DWORD *)this + 8))(this, a2);
  CWarriorBehavior::WarriorPseudoInitWalk(this, a2, v4);
  return (*(int (__thiscall **)(pairNode *, struct IMovingEntity *))(*(_DWORD *)this + 4))(this, a2);
}


// address=[0x15ae7b0]
// Decompiled from bool __thiscall CWarriorBehavior::IsValidTarget(
        CWarriorBehavior *this,
        const struct IEntity *a2,
        const struct IEntity *a3)

bool  CWarriorBehavior::IsValidTarget(class IMovingEntity const &,class IEntity const &) {
  
  int v4; // [esp+0h] [ebp-Ch] BYREF
  int v5[2]; // [esp+4h] [ebp-8h] BYREF

  v5[1] = (int)this;
  CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(this, a2, &v4, v5);
  return CWarriorBehavior::WarriorCheckTarget(a3, v4, v5[0]);
}


// address=[0x15ae7f0]
// Decompiled from BOOL __thiscall CWarriorBehavior::IsTargetInAtackRange(
        CWarriorBehavior *this,
        const struct IMovingEntity *a2,
        struct IEntity *a3)

bool  CWarriorBehavior::IsTargetInAtackRange(class IMovingEntity const &,class IEntity const &) {
  
  int v4; // [esp+0h] [ebp-2Ch]
  int v5; // [esp+4h] [ebp-28h]
  int v6; // [esp+8h] [ebp-24h]
  int v7; // [esp+Ch] [ebp-20h]
  int v8; // [esp+10h] [ebp-1Ch]
  int v9; // [esp+1Ch] [ebp-10h]
  int v11; // [esp+28h] [ebp-4h]

  v5 = IEntity::X(a2);
  v7 = IEntity::Y(a2);
  v6 = IEntity::X(a3);
  v8 = IEntity::Y(a3);
  v9 = Grid::Distance((Grid *)(v6 - v5), v8 - v7);
  v4 = *((_DWORD *)CWarriorBehavior::WarriorProperties(this) + 7);
  v11 = *((_DWORD *)CWarriorBehavior::WarriorProperties(this) + 8);
  return v9 <= (IEntity::ObjType((unsigned __int8 *)a3) == 4) + v11 && v9 >= v4;
}


// address=[0x15ae8c0]
// Decompiled from bool __thiscall CWarriorBehavior::WarriorCheckInflu1(CWarriorBehavior *this, struct IMovingEntity *a2)

bool  CWarriorBehavior::WarriorCheckInflu1(class IMovingEntity &) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-8h]

  v4 = IEntity::X(a2);
  v5 = IEntity::Y(a2);
  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v6 = CAlliances::AllianceId(v2);
  return CInfluMap::EnemyValueXY(v4, v5, v6) > 0;
}


// address=[0x15ae930]
// Decompiled from bool __thiscall CWarriorBehavior::WarriorCheckOwner9(CWarriorBehavior *this, struct IMovingEntity *a2)

bool  CWarriorBehavior::WarriorCheckOwner9(class IMovingEntity &) {
  
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

bool  CWarriorBehavior::WarriorCheckMedic(class IMovingEntity &) {
  
  return 1;
}


// address=[0x15ae9b0]
// Decompiled from char __thiscall CWarriorBehavior::WarriorCheckSaboteur(CWarriorBehavior *this, struct IMovingEntity *a2)

bool  CWarriorBehavior::WarriorCheckSaboteur(class IMovingEntity &) {
  
  return 1;
}


// address=[0x15afe80]
// Decompiled from void __thiscall CWarriorBehavior::WarriorVehicleAttackTarget(CWarriorBehavior *this, struct IMovingEntity *a2, int a3)

void  CWarriorBehavior::WarriorVehicleAttackTarget(class IMovingEntity &,int) {
  
  *((_BYTE *)this + 9) |= 1u;
  CWarriorBehavior::WarriorAttackTarget(this, a2, a3);
}


// address=[0x153fdd0]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
char *__thiscall CWarriorBehavior::GetWarriorBehaviorData(CWarriorBehavior *this)

struct CWarriorBehavior::SWarriorBehaviorData &  CWarriorBehavior::GetWarriorBehaviorData(void) {
  
  return (char *)this + 4;
}


// address=[0x15ae9c0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorPseudoInitWalk(CWarriorBehavior *this, struct IMovingEntity *a2, int a3)

int  CWarriorBehavior::WarriorPseudoInitWalk(class IMovingEntity &,int) {
  
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
  v8 = Grid::Distance((Grid *)(v10 - v6), v11 - v7);
  if ( v12 < 0
    || v8 <= 4
    || (v5 = v11 - Y16X16::UnpackYFast(v12),
        v3 = Y16X16::UnpackXFast(v12),
        (int)Grid::Distance((Grid *)(v10 - v3), v5) > 2) )
  {
    CWarriorBehavior::WarriorInitWalk(this, a2, a3);
  }
  return v8;
}


// address=[0x15aea80]
// Decompiled from int __thiscall CWarriorBehavior::FindAttackWayPoint(
        CWarriorBehavior *this,
        struct IMovingEntity *a2,
        struct IEntity *a3)

int  CWarriorBehavior::FindAttackWayPoint(class IMovingEntity &,class IEntity &) {
  
  int v3; // esi
  int v4; // esi
  int v5; // eax
  int v7; // [esp+4h] [ebp-18h]
  int v8; // [esp+Ch] [ebp-10h]
  int v9; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]

  v7 = CSpiralOffsets::Last(*(_DWORD *)(*((_DWORD *)this + 1) + 32));
  for ( i = 0; i <= v7; ++i )
  {
    v3 = IEntity::X(a3);
    v8 = CSpiralOffsets::DeltaX(i) + v3;
    v4 = IEntity::Y(a3);
    v9 = CSpiralOffsets::DeltaY(i) + v4;
    if ( (unsigned __int8)CWorldManager::InWorld(v8, v9) )
    {
      v5 = IEntity::Type((unsigned __int16 *)a2);
      if ( CVehicleMgr::IsPositionFreeForVehicle((CVehicleMgr *)&g_cVehicleMgr, v8, v9, v5) )
        return Y16X16::PackXYFast(v8, v9);
    }
  }
  return 0;
}


// address=[0x15afa60]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackCheck(CWarriorBehavior *this, struct IMovingEntity *a2)

int  CWarriorBehavior::WarriorAttackCheck(class IMovingEntity &) {
  
  return (*(int (__thiscall **)(CWarriorBehavior *, struct IMovingEntity *))(*((_DWORD *)this + 1) + 8))(this, a2);
}


// address=[0x15afa90]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackTarget(CWarriorBehavior *this, struct IMovingEntity *a2, int a3)

void  CWarriorBehavior::WarriorAttackTarget(class IMovingEntity &,int) {
  
  return (*(int (__thiscall **)(CWarriorBehavior *, struct IMovingEntity *, int, _DWORD))(*(_DWORD *)this + 12))(
           this,
           a2,
           a3,
           *(_DWORD *)(*((_DWORD *)this + 1) + 16));
}


// address=[0x15afad0]
// Decompiled from bool __cdecl CWarriorBehavior::WarriorCheckTarget(struct IEntity *a1, int a2, int a3)

static bool __cdecl CWarriorBehavior::WarriorCheckTarget(class IEntity const &,int,int) {
  
  int v3; // eax

  v3 = IEntity::OwnerId((unsigned __int8 *)a1);
  return (a2 & CAlliances::PlayerBit(v3)) != 0
      && CWarriorBehavior::WarriorTargetAllowableAndVulnerable((unsigned __int16 *)a1, a3);
}


// address=[0x15afb20]
// Decompiled from bool __cdecl CWarriorBehavior::WarriorCheckTarget(int a1, int a2, int a3)

static bool __cdecl CWarriorBehavior::WarriorCheckTarget(int,int,int) {
  
  const struct IEntity *v4; // [esp+0h] [ebp-8h]

  if ( !a1 )
    return 0;
  v4 = CMapObjectMgr::Entity(a1);
  return CWarriorBehavior::WarriorCheckTarget(v4, a2, a3);
}


// address=[0x15afb70]
// Decompiled from int __thiscall CWarriorBehavior::WarriorDestinationId(pairNode *this)

int  CWarriorBehavior::WarriorDestinationId(void)const {
  
  return *((_DWORD *)this + 3);
}


// address=[0x15afb90]
// Decompiled from int *__thiscall CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(
        CWarriorBehavior *this,
        struct IEntity *a2,
        int *a3,
        int *a4)

void  CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(class IEntity const &,int &,int &) {
  
  int v4; // eax
  int *result; // eax

  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  *a3 = CAlliances::PlayerEnemyBits(v4);
  *a4 = *(_DWORD *)(*((_DWORD *)this + 1) + 20);
  result = a4;
  if ( (((unsigned int)&loc_1FFFFFF + 1) & *a4) != 0 )
    return result;
  result = (int *)BBSupportDbgReport(2, "MapObjects\\WarriorBehavior.cpp", 447, "(_rScanMask & ENTITY_FLAG_READY) != 0");
  if ( result == (int *)1 )
    __debugbreak();
  return result;
}


// address=[0x15afc10]
// Decompiled from int __thiscall CWarriorBehavior::WarriorInitWalk(CWarriorBehavior *this, struct IMovingEntity *a2, int a3)

void  CWarriorBehavior::WarriorInitWalk(class IMovingEntity &,int) {
  
  int v4; // [esp+0h] [ebp-Ch]
  struct CWalking *v5; // [esp+8h] [ebp-4h]

  v4 = *((_DWORD *)this + 4) & 0x1060 | 0x2000;
  v5 = IMovingEntity::Walking(a2);
  return (*(int (__thiscall **)(struct CWalking *, int, int))(*(_DWORD *)v5 + 8))(v5, a3, v4);
}


// address=[0x15afc70]
// Decompiled from bool __thiscall CWarriorBehavior::WarriorIsFullUpdate(CWarriorBehavior *this, unsigned int a2)

bool  CWarriorBehavior::WarriorIsFullUpdate(unsigned int)const {
  
  return a2 >= *((_DWORD *)this + 5);
}


// address=[0x15afcb0]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
int __thiscall CWarriorBehavior::WarriorProperties(CWarriorBehavior *this)

class CWarriorProperties const &  CWarriorBehavior::WarriorProperties(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x15afcd0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorSetNextFullUpdate(CWarriorBehavior *this, unsigned int a2, unsigned int a3)

void  CWarriorBehavior::WarriorSetNextFullUpdate(unsigned int,unsigned int) {
  
  int result; // eax

  result = a3 + a2;
  *((_DWORD *)this + 5) = a3 + a2;
  return result;
}


// address=[0x15afcf0]
// Decompiled from bool __cdecl CWarriorBehavior::WarriorTargetAllowableAndVulnerable(unsigned __int16 *a1, int a2)

static bool __cdecl CWarriorBehavior::WarriorTargetAllowableAndVulnerable(class IEntity const &,int) {
  
  int v3; // [esp+4h] [ebp-18h]
  unsigned int v4; // [esp+8h] [ebp-14h]
  BOOL v5; // [esp+10h] [ebp-Ch]
  bool v6; // [esp+1Bh] [ebp-1h]

  v6 = 0;
  if ( IEntity::Type(a1) == 1 && IEntity::ObjType((unsigned __int8 *)a1) == 64 )
    return ((unsigned int)&loc_1C00000 & IEntity::Flags(a1)) != 0;
  v4 = (unsigned int)byte_1C30100 ^ (unsigned int)byte_1C30100 & IEntity::Flags(a1);
  v3 = 1 << IEntity::WarriorType();
  if ( (IEntity::WarriorType() || IEntity::ObjType((unsigned __int8 *)a1) == 1) && (IEntity::Flags(a1) & 0x8000000) == 0 )
    v6 = (a2 & (v3 | v4)) == 0;
  if ( !v6 )
    return v6;
  if ( IEntity::FlagBits(a1, 0x2000000) )
  {
    v5 = IEntity::FlagBits(a1, 0x30000) != 0;
    if ( (IEntity::WarriorType() == 0) != v5 )
      return v6;
  }
  if ( BBSupportDbgReport(
         2,
         (int)"MapObjects\\WarriorBehavior.cpp",
         496,
         (int)"!bResult || ((_rTarget.FlagBits(ENTITY_FLAG_READY) != 0) && ((_rTarget.FlagBits(ENTITY_FLAG_VULNERABLE_MAS"
              "K) != 0) ^ (_rTarget.WarriorType() == WARRIOR_TYPE_NONE)))") == 1 )
    __debugbreak();
  return v6;
}


// address=[0x15afec0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorWalkDestinationXY(CWarriorBehavior *this, struct IMovingEntity *a2)

int  CWarriorBehavior::WarriorWalkDestinationXY(class IMovingEntity &) {
  
  struct CWalking *v2; // eax

  v2 = IMovingEntity::Walking(a2);
  return (*(int (__thiscall **)(struct CWalking *, CWarriorBehavior *, struct CWalking *))(*(_DWORD *)v2 + 44))(
           v2,
           this,
           v2);
}


