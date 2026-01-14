#include "all_headers.h"

// Definitions for class CSoldierRole

// address=[0x1401f80]
// Decompiled from int __cdecl CSoldierRole::New(int a1)
static class CPersistence * __cdecl CSoldierRole::New(std::istream &) {
  
  if ( operator new(0x64u) )
    return CSoldierRole::CSoldierRole(a1);
  else
    return 0;
}


// address=[0x1588900]
// Decompiled from int __cdecl CSoldierRole::Load(int a1)
static class CSoldierRole * __cdecl CSoldierRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CSoldierRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x158e510]
// Decompiled from int __thiscall CSoldierRole::InitWalking(CSoldierRole *this, struct CSettler *a2)
class CWalking *  CSoldierRole::InitWalking(class CSettler *) {
  
  int v2; // eax

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  return CWalking::Create(0, v2);
}


// address=[0x158e540]
// Decompiled from void __thiscall CSoldierRole::LogicUpdateJob(CSoldierRole *this, struct CSettler *a2)
void  CSoldierRole::LogicUpdateJob(class CSettler *) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  unsigned int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // [esp-4h] [ebp-BCh]
  int v16; // [esp-4h] [ebp-BCh]
  _BYTE v17[24]; // [esp+4h] [ebp-B4h] BYREF
  _DWORD v18[3]; // [esp+1Ch] [ebp-9Ch]
  int v19; // [esp+28h] [ebp-90h]
  int v20; // [esp+2Ch] [ebp-8Ch]
  int v21; // [esp+30h] [ebp-88h]
  int v22; // [esp+34h] [ebp-84h]
  int v23; // [esp+38h] [ebp-80h]
  int v24; // [esp+3Ch] [ebp-7Ch]
  int v25; // [esp+40h] [ebp-78h]
  int v26; // [esp+44h] [ebp-74h]
  int v27; // [esp+48h] [ebp-70h]
  int SquadLeaderBonus256; // [esp+4Ch] [ebp-6Ch]
  int v29; // [esp+50h] [ebp-68h]
  int v30; // [esp+54h] [ebp-64h]
  int v31; // [esp+58h] [ebp-60h]
  int v32; // [esp+5Ch] [ebp-5Ch]
  int v33; // [esp+60h] [ebp-58h]
  int v34; // [esp+64h] [ebp-54h]
  int v35; // [esp+68h] [ebp-50h]
  int v36; // [esp+6Ch] [ebp-4Ch]
  BOOL v37; // [esp+70h] [ebp-48h]
  Grid *v38; // [esp+74h] [ebp-44h]
  int v39; // [esp+78h] [ebp-40h]
  int v40; // [esp+7Ch] [ebp-3Ch]
  int v41; // [esp+80h] [ebp-38h]
  int v42; // [esp+84h] [ebp-34h]
  int v43; // [esp+88h] [ebp-30h]
  _DWORD *v44; // [esp+8Ch] [ebp-2Ch]
  int v45; // [esp+90h] [ebp-28h] BYREF
  int v46; // [esp+94h] [ebp-24h]
  int v47; // [esp+98h] [ebp-20h]
  struct IEntity *v48; // [esp+9Ch] [ebp-1Ch]
  int v49; // [esp+A0h] [ebp-18h]
  int v50; // [esp+A4h] [ebp-14h]
  int v53; // [esp+ACh] [ebp-Ch]
  unsigned __int8 *v54; // [esp+B0h] [ebp-8h]
  CSoldierRole *v55; // [esp+B4h] [ebp-4h]

  v55 = this;
  if ( *((_BYTE *)this + 4) == 16 )
  {
    v54 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(*((unsigned __int16 *)v55 + 17));
    if ( v54 )
    {
      if ( IEntity::FlagBits(v54, (EntityFlag)((char *)&loc_1FFFFFF + 1)) && IEntity::FlagBits(v54, VulnerableMask) )
      {
        v53 = *(unsigned __int8 *)(*((_DWORD *)v55 + 24) + 3);
        v43 = IEntity::OwnerId((unsigned __int8 *)a2);
        v2 = IEntity::PackedXY(a2);
        v3 = CWorldManager::Index(v2);
        v32 = ITiling::OwnerId(v3);
        v31 = CAlliances::AllianceId(v43);
        v30 = CAlliances::AllianceId(v32);
        if ( v31 == v30 )
          v41 = CStatistic::DefenceStrength256((CStatistic *)&g_cStatistic, v43);
        else
          v41 = CStatistic::OffenceStrength256((CStatistic *)&g_cStatistic, v43);
        v29 = v41;
        v53 = (v41 * v53 + 127) >> 8;
        v40 = v53 == 0;
        v53 += v40;
        if ( (IEntity::Flags(a2) & 0x100000) != 0 )
          v53 += (v53 * CStaticConfigVarInt::operator int(g_pMagicBloodlustDmgIncrease256) + 127) >> 8;
        if ( (ISelectableSettlerRole::GetGroupFlagsEx(v55) & 0x800) != 0 )
        {
          v4 = IEntity::Race(a2);
          SquadLeaderBonus256 = CSettlerMgr::GetSquadLeaderBonus256(v4);
          v46 = SquadLeaderBonus256 * v53;
          if ( (unsigned __int8)CStateGame::Rand(g_pGame) < (unsigned int)(unsigned __int8)(SquadLeaderBonus256 * v53) )
            v46 += 256;
          v53 += v46 >> 8;
        }
        v5 = IEntity::OwnerId(v54);
        if ( v5 == CPlayerManager::GetLocalPlayerId() )
        {
          v15 = IEntity::Y(v54);
          v6 = IEntity::X(v54);
          CAttackMsgList::SendAttackMessage((CAttackMsgList *)&g_cAttackMsgList, v6, v15);
        }
        v38 = (Grid *)IEntity::X(v54);
        v39 = IEntity::Y(v54);
        v27 = IEntity::ID();
        v7 = IEntity::OwnerId((unsigned __int8 *)a2);
        (*(void (__thiscall **)(unsigned __int8 *, int, int))(*(_DWORD *)v54 + 28))(v54, v53, v7);
        v47 = IEntity::Type((unsigned __int16 *)a2);
        if ( (unsigned int)(v47 - 61) <= 2 )
        {
          v18[0] = dword_3D8BE0C[v47] * v53 / 100;
          v18[1] = dword_3D8BE0C[v47] * v53 / 200;
          v45 = 0;
          CSettlerSpiralWalk::CSettlerSpiralWalk((CSettlerSpiralWalk *)v17, v38, v39, 4);
          while ( CSettlerSpiralWalk::NextSettlerId((CSettlerSpiralWalk *)v17, &v45) )
          {
            if ( !v45 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 525, "iNeighbourID != 0") == 1 )
              __debugbreak();
            if ( v45 != v27 )
            {
              v48 = (struct IEntity *)CMapObjectMgr::EntityPtr(v45);
              if ( CWarriorBehavior::IsValidTarget((CSoldierRole *)((char *)v55 + 48), a2, v48) )
              {
                v16 = IEntity::Y(v48);
                v8 = IEntity::X(v48);
                v49 = (Grid::Distance(v38, v39, v8, v16) - 1) >> 1;
                v37 = v49 > 0;
                v49 = v37;
                v9 = IEntity::OwnerId((unsigned __int8 *)a2);
                ((void (__thiscall *)(struct IEntity *, _DWORD, int))v48->MetaData)(v48, v18[v49], v9);
              }
            }
          }
        }
        if ( (unsigned int)(v47 - 41) <= 2 && !IEntity::FlagBits(v54, (EntityFlag)dword_800000) )
        {
          v26 = IEntity::WarriorType();
          v36 = IEntity::Race(v54) == 3 ? 12 : 60;
          v25 = v36;
          if ( (v36 & (1 << v26)) != 0 )
          {
            v10 = CStateGame::Rand(g_pGame);
            if ( v10 < dword_41579C4[v47] )
            {
              v24 = (CStateGame::Rand(g_pGame) & 0xF) + 20;
              v35 = CLogic::FutureEvents(g_pLogic);
              v11 = IEntity::EntityId((unsigned __int16 *)v54);
              if ( (*(unsigned __int8 (__thiscall **)(int, int, int, int, _DWORD, int *))(*(_DWORD *)v35 + 12))(
                     v35,
                     1,
                     v24,
                     v11,
                     0,
                     dword_800000) )
              {
                IEntity::SetFlagBits(v54, (EntityFlag)dword_800000);
              }
            }
          }
        }
      }
    }
    else
    {
      BBSupportTracePrintF(3, "### CSoldierRole::LogicUpdateJob(): pTarget == 0! ###");
      v12 = IEntity::EntityId((unsigned __int16 *)a2);
      CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, v12, 3, (struct tagVARIANT *)&stru_37BB350);
      CMapObjectMgr::DbgPrintEntity(
        g_pMapObjectMgr,
        *((unsigned __int16 *)v55 + 17),
        3,
        (struct tagVARIANT *)&stru_37BB350.decVal.Lo32);
    }
    CSoldierRole::CheckToDoList();
  }
  else if ( *((_BYTE *)v55 + 4) == 34 )
  {
    v44 = (_DWORD *)CMapObjectMgr::EntityPtr(*((unsigned __int16 *)v55 + 17));
    if ( v44 && IEntity::FlagBits(v44, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
    {
      v22 = IEntity::Race(a2);
      v23 = IEntity::Type((unsigned __int16 *)a2);
      v50 = *(unsigned __int8 *)(CSettlerMgr::GetSettlerInfo(v22, v23) + 7);
      if ( v50 <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 611, "iHealAmount > 0") == 1 )
        __debugbreak();
      v42 = IEntity::OwnerId((unsigned __int8 *)a2);
      v13 = IEntity::PackedXY(a2);
      v14 = CWorldManager::Index(v13);
      v21 = ITiling::OwnerId(v14);
      v20 = CAlliances::AllianceId(v42);
      v19 = CAlliances::AllianceId(v21);
      if ( v20 == v19 )
        v34 = CStatistic::DefenceStrength256((CStatistic *)&g_cStatistic, v42);
      else
        v34 = CStatistic::OffenceStrength256((CStatistic *)&g_cStatistic, v42);
      v18[2] = v34;
      v50 = (v34 * v50 + 127) >> 8;
      v33 = v50 == 0;
      v50 += v33;
      (*(void (__thiscall **)(_DWORD *, int))(*v44 + 24))(v44, v50);
      if ( *((_BYTE *)v55 + 73) )
        --*((_BYTE *)v55 + 73);
    }
    CSoldierRole::CheckToDoList();
  }
  if ( *((_DWORD *)v55 + 20) )
  {
    *((_DWORD *)v55 + 20) = 0;
    (*(void (__thiscall **)(CSoldierRole *, struct CSettler *))(*(_DWORD *)v55 + 40))(v55, a2);
    if ( *((_BYTE *)v55 + 4) == 27 )
      CSoldierRole::SoldierWarriorLogicUpdate(v55, a2);
  }
  else
  {
    CSoldierRole::SoldierWarriorLogicUpdate(v55, a2);
    CSoldierRole::CheckToDoList();
  }
}


// address=[0x158ebc0]
// Decompiled from int __thiscall CSoldierRole::UpdateJob(CSoldierRole *this, struct CSettler *a2)
void  CSoldierRole::UpdateJob(class CSettler *) {
  
  int v2; // eax
  int v3; // eax

  switch ( *((_BYTE *)this + 4) )
  {
    case 0x10:
    case 0x22:
      v2 = IAnimatedEntity::Frame(a2);
      IAnimatedEntity::SetFrame((*((unsigned __int16 *)this + 4) + v2) % *((unsigned __int8 *)this + 7));
      break;
    case 0x18:
      return CSoldierRole::CheckToDoList();
    case 0x1B:
      if ( (*((_BYTE *)this + 5) & 8) != 0 )
      {
        *((_BYTE *)a2 + 36) = 0;
      }
      else
      {
        v3 = IAnimatedEntity::Frame(a2);
        IAnimatedEntity::SetFrame((*((unsigned __int16 *)this + 4) + v3) % *((unsigned __int8 *)this + 7));
        if ( !*((_BYTE *)a2 + 36) )
          *((_BYTE *)a2 + 36) = 1;
        IMovingEntity::DecDistance(a2, (*((unsigned __int16 *)this + 4) << 8) / *((char *)this + 6));
      }
      break;
    default:
      CTrace::Print("SoldierRole - UpdateJob unknown task!");
      break;
  }
  return CSoldierRole::CheckToDoList();
}


// address=[0x158ed00]
// Decompiled from int __thiscall CSoldierRole::WarriorTaskWalkOneStep(CSoldierRole *this, struct IMovingEntity *a2)
int  CSoldierRole::WarriorTaskWalkOneStep(class IMovingEntity &) {
  
  int v4; // [esp+8h] [ebp-4h]

  v4 = CSettler::Walk(a2);
  CSoldierRole::EvaluateWalkAndRegister((CSoldierRole *)((char *)this - 48), a2, v4);
  return v4;
}


// address=[0x158ed40]
// Decompiled from int __thiscall CSoldierRole::WarriorTaskAttack(_DWORD *this, _DWORD *a2, unsigned int a3, int a4)
void  CSoldierRole::WarriorTaskAttack(class IMovingEntity &,int,enum T_WARRIOR_ATTACK) {
  
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  struct IEntity *v10; // eax
  int v11; // eax
  int result; // eax
  struct IEntity *v13; // eax
  int v14; // eax
  struct IEntity *v15; // eax
  int v16; // eax
  struct IEntity *v17; // eax
  int v18; // eax
  struct IEntity *v19; // eax
  int v20; // eax
  struct IEntity *v21; // eax
  int v22; // eax
  struct IEntity *v23; // eax
  int v24; // eax
  int v25; // [esp-10h] [ebp-68h]
  int v26; // [esp-10h] [ebp-68h]
  int v27; // [esp-10h] [ebp-68h]
  int v28; // [esp-10h] [ebp-68h]
  int v29; // [esp-10h] [ebp-68h]
  int v30; // [esp-10h] [ebp-68h]
  int v31; // [esp-10h] [ebp-68h]
  int v32; // [esp-4h] [ebp-5Ch]
  int v33; // [esp-4h] [ebp-5Ch]
  _BYTE v34[12]; // [esp+8h] [ebp-50h] BYREF
  int v35; // [esp+14h] [ebp-44h]
  int v36; // [esp+18h] [ebp-40h]
  unsigned __int8 *v37; // [esp+1Ch] [ebp-3Ch]
  int v38; // [esp+20h] [ebp-38h]
  int v39; // [esp+24h] [ebp-34h]
  int v40; // [esp+28h] [ebp-30h]
  int v41; // [esp+2Ch] [ebp-2Ch]
  int v42; // [esp+30h] [ebp-28h]
  int v43; // [esp+34h] [ebp-24h]
  int v44; // [esp+38h] [ebp-20h]
  _BYTE *v45; // [esp+3Ch] [ebp-1Ch]
  int v47; // [esp+44h] [ebp-14h]
  _DWORD *v48; // [esp+48h] [ebp-10h]
  int v49; // [esp+54h] [ebp-4h]

  v48 = this;
  if ( CMapObjectMgr::GetUniqueId(a3) <= 0
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SoldierRole.cpp",
         1650,
         "g_pMapObjectMgr->GetUniqueId(_iTargetId) > 0") == 1 )
  {
    __debugbreak();
  }
  if ( (CMapObjectMgr::GetUniqueId(a3) & 0x20000000) != 0
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SoldierRole.cpp",
         1651,
         "( g_pMapObjectMgr->GetUniqueId(_iTargetId) & IEntity::UNIQUE_ID_DEAD_ENTITY_BIT ) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::FlagBits(a2, (EntityFlag)0x8000000u) )
    IEntity::ClearFlagBits(a2, (EntityFlag)0x8000000u);
  v45 = a2;
  v47 = 1;
  if ( a4 == 1 )
  {
    v37 = (unsigned __int8 *)CMapObjectMgr::Entity(a3);
    v4 = IEntity::OwnerId(v37);
    v5 = CAlliances::AllianceId(v4);
    v6 = IEntity::OwnerId((unsigned __int8 *)a2);
    if ( v5 == CAlliances::AllianceId(v6) )
      v47 = 2;
  }
  v32 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](v47);
  v7 = IEntity::Race(v45);
  if ( !CEntityToDoListMgr::SettlerJobList(v7, v32) )
  {
    v33 = IEntity::Race(a2);
    v8 = IEntity::Type((unsigned __int16 *)a2);
    if ( BBSupportDbgReportF(
           2,
           "MapObjects\\Settler\\SoldierRole.cpp",
           1680,
           "CSoldierRole::WarriorTaskAttack(): No work list for settler type %i of race %i!",
           v8,
           v33) == 1 )
      __debugbreak();
  }
  v36 = std::list<CEntityTask>::begin(v34);
  v35 = v36;
  v49 = 0;
  v9 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator*(v36);
  v48[8] = v9;
  v49 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v34);
  if ( *(_WORD *)(v48[8] + 16)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1684, "m_pTempEntityTask->m_uEntityID == 0") == 1 )
  {
    __debugbreak();
  }
  *(_WORD *)(v48[8] + 16) = a3;
  (*(void (__thiscall **)(_DWORD *, _BYTE *))(*(v48 - 12) + 40))(v48 - 12, v45);
  *(_WORD *)(v48[8] + 16) = 0;
  if ( IEntity::WarriorType() == 3 )
  {
    if ( IEntity::Race(a2) == 3 )
    {
      v43 = CLogic::Effects((DWORD *)g_pLogic);
      v13 = CMapObjectMgr::Entity(a3);
      v26 = IEntity::PackedXY(v13);
      v14 = IEntity::PackedXY(a2);
      return (*(int (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v43 + 24))(
               v43,
               7,
               v14,
               v26,
               15,
               0,
               0);
    }
    else
    {
      v44 = CLogic::Effects((DWORD *)g_pLogic);
      v10 = CMapObjectMgr::Entity(a3);
      v25 = IEntity::PackedXY(v10);
      v11 = IEntity::PackedXY(a2);
      return (*(int (__thiscall **)(int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v44 + 24))(
               v44,
               0,
               v11,
               v25,
               15,
               0,
               0);
    }
  }
  else
  {
    result = IEntity::WarriorType();
    if ( result == 4 )
    {
      if ( IEntity::Type((unsigned __int16 *)a2) < 41 || IEntity::Type((unsigned __int16 *)a2) > 43 )
      {
        if ( IEntity::Type((unsigned __int16 *)a2) == 61 )
        {
          v41 = CLogic::Effects((DWORD *)g_pLogic);
          v17 = CMapObjectMgr::Entity(a3);
          v28 = IEntity::PackedXY(v17);
          v18 = IEntity::PackedXY(a2);
          return (*(int (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v41 + 24))(
                   v41,
                   8,
                   v18,
                   v28,
                   15,
                   0,
                   0);
        }
        else if ( IEntity::Type((unsigned __int16 *)a2) == 62 )
        {
          v40 = CLogic::Effects((DWORD *)g_pLogic);
          v19 = CMapObjectMgr::Entity(a3);
          v29 = IEntity::PackedXY(v19);
          v20 = IEntity::PackedXY(a2);
          (*(void (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v40 + 24))(
            v40,
            8,
            v20,
            v29,
            10,
            0,
            0);
          v39 = CLogic::Effects((DWORD *)g_pLogic);
          v21 = CMapObjectMgr::Entity(a3);
          v30 = IEntity::PackedXY(v21);
          v22 = IEntity::PackedXY(a2);
          return (*(int (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v39 + 24))(
                   v39,
                   8,
                   v22,
                   v30,
                   20,
                   0,
                   0);
        }
        else
        {
          result = IEntity::Type((unsigned __int16 *)a2);
          if ( result == 63 )
          {
            v38 = CLogic::Effects((DWORD *)g_pLogic);
            v23 = CMapObjectMgr::Entity(a3);
            v31 = IEntity::PackedXY(v23);
            v24 = IEntity::PackedXY(a2);
            return (*(int (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v38 + 24))(
                     v38,
                     9,
                     v24,
                     v31,
                     15,
                     0,
                     0);
          }
        }
      }
      else
      {
        v42 = CLogic::Effects((DWORD *)g_pLogic);
        v15 = CMapObjectMgr::Entity(a3);
        v27 = IEntity::PackedXY(v15);
        v16 = IEntity::PackedXY(a2);
        return (*(int (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v42 + 24))(
                 v42,
                 1,
                 v16,
                 v27,
                 15,
                 0,
                 0);
      }
    }
  }
  return result;
}


// address=[0x158f1a0]
// Decompiled from int __thiscall CSoldierRole::WarriorTaskFinished(CSoldierRole *this, struct IMovingEntity *a2)
void  CSoldierRole::WarriorTaskFinished(class IMovingEntity &) {
  
  IAnimatedEntity::RegisterForLogicUpdate(1);
  IMovingEntity::SetDisplacementCosts(0);
  return (*(int (__thiscall **)(char *, struct IMovingEntity *))(*((_DWORD *)this - 12) + 36))((char *)this - 48, a2);
}


// address=[0x158f1e0]
// Decompiled from int __thiscall CSoldierRole::WarriorTaskIdleWalk(CSoldierRole *this, struct IMovingEntity *a2)
int  CSoldierRole::WarriorTaskIdleWalk(class IMovingEntity &) {
  
  int v2; // eax
  int v5; // [esp+4h] [ebp-10h]
  int v6; // [esp+8h] [ebp-Ch]
  struct CWalking *v7; // [esp+Ch] [ebp-8h]

  IMovingEntity::SetDisplacementCosts(0);
  v7 = IMovingEntity::Walking(a2);
  v2 = IEntity::PackedXY(a2);
  v5 = (*(int (__thiscall **)(struct CWalking *, int, _DWORD))(*(_DWORD *)v7 + 16))(v7, v2, 0);
  v6 = CSettler::WalkDir(a2, v5);
  CSoldierRole::EvaluateWalkAndRegister((CSoldierRole *)((char *)this - 48), a2, v6);
  return v6;
}


// address=[0x158f250]
// Decompiled from char __thiscall CSoldierRole::SetFree(CSoldierRole *this, struct CSettler *a2, int a3)
bool  CSoldierRole::SetFree(class CSettler *,int) {
  
  int v4; // [esp+0h] [ebp-10h]
  int v6; // [esp+8h] [ebp-8h]
  int v7; // [esp+Ch] [ebp-4h]

  v6 = ISettlerRole::HomeEntityId(this);
  v4 = IEntity::EntityId((unsigned __int16 *)a2);
  if ( v6 )
  {
    if ( !IEntity::FlagBits(a2, Attached)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Settler\\SoldierRole.cpp",
           1903,
           "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED) != 0") == 1 )
    {
      __debugbreak();
    }
    v7 = CMapObjectMgr::EntityPtr(v6);
    if ( !v7 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1908, "pEntity != 0") == 1 )
      __debugbreak();
    if ( v7 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 64))(v7, v4);
    if ( ISettlerRole::HomeEntityId(this)
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1915, "HomeEntityId() == 0") == 1 )
    {
      __debugbreak();
    }
    if ( IEntity::FlagBits(a2, Attached)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Settler\\SoldierRole.cpp",
           1917,
           "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED) == 0") == 1 )
    {
      __debugbreak();
    }
  }
  else if ( IEntity::FlagBits(a2, Attached)
         && BBSupportDbgReport(
              2,
              "MapObjects\\Settler\\SoldierRole.cpp",
              1921,
              "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED) == 0") == 1 )
  {
    __debugbreak();
  }
  return 0;
}


// address=[0x158f390]
// Decompiled from int __thiscall CSoldierRole::PostLoadInit(_DWORD *this, CPropertySet *a2)
void  CSoldierRole::PostLoadInit(class CSettler *) {
  
  int v2; // esi
  int v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  struct CWarriorBehavior::SWarriorBehaviorData *WarriorBehaviorData; // eax
  int v9; // [esp-4h] [ebp-3Ch]
  int v10; // [esp-4h] [ebp-3Ch]
  int v11; // [esp-4h] [ebp-3Ch]
  int v12; // [esp+0h] [ebp-38h]
  _BYTE v13[12]; // [esp+8h] [ebp-30h] BYREF
  int v14; // [esp+14h] [ebp-24h]
  int v15; // [esp+18h] [ebp-20h]
  int v16; // [esp+1Ch] [ebp-1Ch]
  int v17; // [esp+20h] [ebp-18h]
  int v18; // [esp+24h] [ebp-14h]
  _DWORD *v19; // [esp+28h] [ebp-10h]
  int v20; // [esp+34h] [ebp-4h]

  v19 = this;
  v18 = IEntity::PackedXY(a2);
  v17 = IEntity::WorldIdx();
  if ( v18 && (unsigned __int8)CWorldManager::InWorldPackedXY(v18) && !IEntity::FlagBits(a2, OnBoard) )
  {
    v2 = CWorldManager::MapObjectId(v17);
    if ( v2 != IEntity::EntityId((unsigned __int16 *)a2)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Settler\\SoldierRole.cpp",
           291,
           "g_cWorld.MapObjectId(iSettlerWorldIdx) == _pSettler->EntityId()") == 1 )
    {
      __debugbreak();
    }
    CWarMap::AddEntity(a2);
  }
  else if ( (unsigned __int8)CWorldManager::InWorldPackedXY(v18) )
  {
    v3 = CWorldManager::MapObjectId(v17);
    if ( v3 == IEntity::EntityId((unsigned __int16 *)a2)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Settler\\SoldierRole.cpp",
           297,
           "!g_cWorld.InWorldPackedXY(iSettlerPackedXY) || (g_cWorld.MapObjectId(iSettlerWorldIdx) != _pSettler->EntityId())") == 1 )
    {
      __debugbreak();
    }
  }
  v9 = IEntity::Type((unsigned __int16 *)a2);
  v4 = IEntity::Race(a2);
  v19[24] = CSettlerMgr::GetSettlerInfo(v4, v9);
  if ( std::list<CEntityTask>::size(v19 + 21) )
    IMovingEntity::SetToDoList(a2, (int)(v19 + 21));
  IMovingEntity::ResetToDoList(v12);
  while ( *((_BYTE *)v19 + 12) )
  {
    IMovingEntity::IncToDoListIter(a2);
    --*((_BYTE *)v19 + 12);
  }
  if ( *((_BYTE *)v19 + 72) )
  {
    v10 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](1);
    v5 = IEntity::Race(a2);
    v16 = CEntityToDoListMgr::SettlerJobList(v5, v10);
    v15 = std::list<CEntityTask>::begin(v13);
    v14 = v15;
    v20 = 0;
    v6 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator*(v15);
    v19[20] = v6;
    v20 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v13);
  }
  else
  {
    v19[20] = 0;
  }
  v11 = *((_DWORD *)CWarriorBehavior::GetWarriorBehaviorData((CWarriorBehavior *)(v19 + 12)) + 3);
  WarriorBehaviorData = CWarriorBehavior::GetWarriorBehaviorData((CWarriorBehavior *)(v19 + 12));
  (*(void (__thiscall **)(_DWORD *, CPropertySet *, _DWORD, int))v19[12])(
    v19 + 12,
    a2,
    *((_DWORD *)WarriorBehaviorData + 2),
    v11);
  return CSoldierRole::CheckToDoList();
}


// address=[0x158f5c0]
// Decompiled from void __thiscall CSoldierRole::CheckToDoList(CSoldierRole *this)
void  CSoldierRole::CheckToDoList(void) {
  
  _BYTE v1[12]; // [esp+4h] [ebp-4Ch] BYREF
  _BYTE v2[12]; // [esp+10h] [ebp-40h] BYREF
  _BYTE v3[12]; // [esp+1Ch] [ebp-34h] BYREF
  std::_Iterator_base12 *v4; // [esp+28h] [ebp-28h]
  std::_Iterator_base12 *ActualIter; // [esp+2Ch] [ebp-24h]
  char *v6; // [esp+30h] [ebp-20h]
  std::_Iterator_base12 *v7; // [esp+34h] [ebp-1Ch]
  std::_Iterator_base12 *v8; // [esp+38h] [ebp-18h]
  CSoldierRole *v9; // [esp+3Ch] [ebp-14h]
  char v10; // [esp+41h] [ebp-Fh]
  char v11; // [esp+42h] [ebp-Eh]
  char v12; // [esp+43h] [ebp-Dh]
  int v13; // [esp+4Ch] [ebp-4h]

  v9 = this;
  v12 = 0;
  v6 = (char *)CSettlerMgr::operator[](*((unsigned __int16 *)this + 9));
  std::list<CEntityTask>::begin(v3);
  v13 = 0;
  while ( 1 )
  {
    v8 = (std::_Iterator_base12 *)std::list<CEntityTask>::end(v2);
    v7 = v8;
    LOBYTE(v13) = 1;
    v11 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=(v8);
    LOBYTE(v13) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v2);
    if ( !v11 )
      break;
    ActualIter = (std::_Iterator_base12 *)IMovingEntity::GetActualIter(v6, (int)v1);
    v4 = ActualIter;
    LOBYTE(v13) = 2;
    v10 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator==(ActualIter);
    LOBYTE(v13) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v1);
    if ( v10 )
      v12 = 1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v3);
  }
  v13 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v3);
  if ( std::list<CEntityTask>::size((char *)v9 + 84) )
  {
    if ( v12 )
      OutputDebugStringA("CSoldierRole found\n");
    else
      OutputDebugStringA("CSoldierRole not found\n");
  }
}


// address=[0x158f700]
// Decompiled from char *__thiscall CSoldierRole::GetWarriorBehavior(CSoldierRole *this)
class CWarriorBehavior *  CSoldierRole::GetWarriorBehavior(void) {
  
  if ( this )
    return (char *)this + 48;
  else
    return 0;
}


// address=[0x158f730]
// Decompiled from int __thiscall CSoldierRole::GetKindOfSelection(CSoldierRole *this, struct CSettler *a2)
int  CSoldierRole::GetKindOfSelection(class CSettler *)const {
  
  int v3; // [esp+8h] [ebp-4h]

  switch ( IEntity::Type((unsigned __int16 *)a2) )
  {
    case 30:
    case 33:
    case 36:
    case 39:
    case 42:
    case 62:
      v3 = 92;
      break;
    case 31:
    case 34:
    case 37:
    case 40:
    case 43:
    case 63:
      v3 = 93;
      break;
    case 44:
      v3 = 95;
      break;
    case 45:
      v3 = 94;
      break;
    default:
      v3 = 1;
      break;
  }
  return v3;
}


// address=[0x158f7e0]
// Decompiled from _DWORD *__thiscall CSoldierRole::CSoldierRole(_DWORD *this, int a2)
 CSoldierRole::CSoldierRole(std::istream &) {
  
  struct CWarriorBehavior::SWarriorBehaviorData *WarriorBehaviorData; // eax
  struct CWarriorBehavior::SWarriorBehaviorData *v3; // eax
  char v4; // al
  struct CWarriorBehavior::SWarriorBehaviorData *v5; // eax
  struct CWarriorBehavior::SWarriorBehaviorData *v6; // eax
  int v8; // [esp+4h] [ebp-34h]
  unsigned int v9; // [esp+8h] [ebp-30h] BYREF
  int v10; // [esp+Ch] [ebp-2Ch]
  unsigned int v11; // [esp+10h] [ebp-28h] BYREF
  int v12; // [esp+14h] [ebp-24h] BYREF
  int pExceptionObject; // [esp+18h] [ebp-20h] BYREF
  int v14; // [esp+1Ch] [ebp-1Ch]
  unsigned int j; // [esp+20h] [ebp-18h]
  unsigned int i; // [esp+24h] [ebp-14h]
  _DWORD *v17; // [esp+28h] [ebp-10h]
  int v18; // [esp+34h] [ebp-4h]

  v17 = this;
  ISelectableSettlerRole::ISelectableSettlerRole(a2);
  v18 = 0;
  CWarriorBehavior::CWarriorBehavior((CWarriorBehavior *)(v17 + 12));
  *v17 = &CSoldierRole::_vftable_;
  v17[12] = &CSoldierRole::`vftable';
  std::list<CEntityTask>::list<CEntityTask>(v17 + 21);
  LOBYTE(v18) = 1;
  v17[20] = 0;
  operator^<unsigned int>(a2, &v12);
  v14 = v12;
  if ( v12 == 1 )
  {
    WarriorBehaviorData = CWarriorBehavior::GetWarriorBehaviorData((CWarriorBehavior *)(v17 + 12));
    operator^<int>(a2, (int)WarriorBehaviorData + 8);
    v3 = CWarriorBehavior::GetWarriorBehaviorData((CWarriorBehavior *)(v17 + 12));
    operator^<unsigned int>(a2, (char *)v3 + 12);
    operator^<unsigned int>(a2, &v11);
    for ( i = 0; i < v11; ++i )
    {
      v10 = CEntityTask::Load(a2);
      std::list<CEntityTask>::push_back(v10);
    }
    operator^<unsigned char>(a2, v17 + 3);
    operator^<unsigned char>(a2, v17 + 18);
    v4 = CStaticConfigVarInt::operator int(&CSoldierRole::s_iMaxNumberOfHealings);
    *((_BYTE *)v17 + 73) = v4;
    v17[19] = 0;
  }
  else
  {
    if ( v14 != 2 )
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CSoldierRole");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    v5 = CWarriorBehavior::GetWarriorBehaviorData((CWarriorBehavior *)(v17 + 12));
    operator^<int>(a2, (int)v5 + 8);
    v6 = CWarriorBehavior::GetWarriorBehaviorData((CWarriorBehavior *)(v17 + 12));
    operator^<unsigned int>(a2, (char *)v6 + 12);
    operator^<unsigned int>(a2, &v9);
    for ( j = 0; j < v9; ++j )
    {
      v8 = CEntityTask::Load(a2);
      std::list<CEntityTask>::push_back(v8);
    }
    operator^<unsigned char>(a2, v17 + 3);
    operator^<unsigned char>(a2, v17 + 18);
    operator^<unsigned char>(a2, (char *)v17 + 73);
    operator^<unsigned int>(a2, v17 + 19);
  }
  return v17;
}


// address=[0x158fa60]
// Decompiled from int __thiscall CSoldierRole::Store(int *this, struct std::ostream *a2)
void  CSoldierRole::Store(std::ostream &) {
  
  struct CWarriorBehavior::SWarriorBehaviorData *WarriorBehaviorData; // eax
  struct CWarriorBehavior::SWarriorBehaviorData *v3; // eax
  unsigned int v4; // esi
  int v6; // [esp+0h] [ebp-84h]
  int v7; // [esp+4h] [ebp-80h]
  _BYTE v8[12]; // [esp+8h] [ebp-7Ch] BYREF
  _BYTE v9[12]; // [esp+14h] [ebp-70h] BYREF
  _BYTE v10[12]; // [esp+20h] [ebp-64h] BYREF
  _BYTE v11[12]; // [esp+2Ch] [ebp-58h] BYREF
  _BYTE v12[12]; // [esp+38h] [ebp-4Ch] BYREF
  std::_Iterator_base12 *v13; // [esp+44h] [ebp-40h]
  std::_Iterator_base12 *ActualIter; // [esp+48h] [ebp-3Ch]
  char *v15; // [esp+4Ch] [ebp-38h]
  std::_Iterator_base12 *v16; // [esp+50h] [ebp-34h]
  std::_Iterator_base12 *v17; // [esp+54h] [ebp-30h]
  std::_Iterator_base12 *v18; // [esp+58h] [ebp-2Ch]
  std::_Iterator_base12 *v19; // [esp+5Ch] [ebp-28h]
  int v20; // [esp+60h] [ebp-24h] BYREF
  int v21; // [esp+64h] [ebp-20h] BYREF
  int v22; // [esp+68h] [ebp-1Ch]
  int *v23; // [esp+6Ch] [ebp-18h]
  char v24; // [esp+72h] [ebp-12h] BYREF
  char v25; // [esp+73h] [ebp-11h] BYREF
  char v26; // [esp+74h] [ebp-10h]
  char v27; // [esp+75h] [ebp-Fh]
  char v28; // [esp+76h] [ebp-Eh]
  int v29; // [esp+77h] [ebp-Dh] BYREF
  int v30; // [esp+80h] [ebp-4h]

  v23 = this;
  ISelectableSettlerRole::Store(a2);
  v20 = 2;
  operator^<unsigned int>(a2, &v20);
  WarriorBehaviorData = CWarriorBehavior::GetWarriorBehaviorData((CWarriorBehavior *)(v23 + 12));
  operator^<int>((int)a2, (int *)WarriorBehaviorData + 2);
  v3 = CWarriorBehavior::GetWarriorBehaviorData((CWarriorBehavior *)(v23 + 12));
  operator^<unsigned int>(a2, (int *)v3 + 3);
  LOBYTE(v29) = 0;
  v21 = std::list<CEntityTask>::size(v23 + 21);
  operator^<unsigned int>(a2, &v21);
  std::list<CEntityTask>::begin(v12);
  v30 = 0;
  while ( 1 )
  {
    v19 = (std::_Iterator_base12 *)std::list<CEntityTask>::end(v10);
    v18 = v19;
    LOBYTE(v30) = 1;
    v28 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=(v19);
    LOBYTE(v30) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v10);
    if ( !v28 )
      break;
    v22 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator->(v12, v6, v7);
    (*(void (__thiscall **)(int, struct std::ostream *))(*(_DWORD *)v22 + 4))(v22, a2);
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v12);
  }
  v30 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v12);
  v15 = (char *)CSettlerMgr::operator[](*((unsigned __int16 *)v23 + 9));
  if ( v21 )
  {
    std::list<CEntityTask>::begin(v11);
    v30 = 2;
    while ( 1 )
    {
      v17 = (std::_Iterator_base12 *)std::list<CEntityTask>::end(v9);
      v16 = v17;
      LOBYTE(v30) = 3;
      v27 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=(v17);
      LOBYTE(v30) = 2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v9);
      if ( !v27 )
        break;
      ActualIter = (std::_Iterator_base12 *)IMovingEntity::GetActualIter(v15, (int)v8);
      v13 = ActualIter;
      LOBYTE(v30) = 4;
      v26 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator==(ActualIter);
      LOBYTE(v30) = 2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v8);
      if ( v26 )
        break;
      LOBYTE(v29) = v29 + 1;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v11);
    }
    v30 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v11);
  }
  v4 = (unsigned __int8)v29;
  if ( v4 >= std::list<CEntityTask>::size(v23 + 21) )
    LOBYTE(v29) = 0;
  operator^<unsigned char>(a2, (int)&v29);
  if ( v23[20] )
  {
    v25 = 1;
    operator^<unsigned char>(a2, (int)&v25);
  }
  else
  {
    v24 = 0;
    operator^<unsigned char>(a2, (int)&v24);
  }
  operator^<unsigned char>(a2, (int)v23 + 73);
  operator^<unsigned int>(a2, v23 + 19);
  return CSoldierRole::CheckToDoList();
}


// address=[0x1592140]
// Decompiled from int __thiscall CSoldierRole::ClassID(CSoldierRole *this)
unsigned long  CSoldierRole::ClassID(void)const {
  
  return CSoldierRole::m_iClassID;
}


// address=[0x15921e0]
// Decompiled from int __thiscall CSoldierRole::GetSettlerRole(CSoldierRole *this)
int  CSoldierRole::GetSettlerRole(void)const {
  
  return 7;
}


// address=[0x15afa00]
// Decompiled from int __thiscall CSoldierRole::GetNumberOfHealings(CSoldierRole *this)
int  CSoldierRole::GetNumberOfHealings(void) {
  
  return *((unsigned __int8 *)this + 73);
}


// address=[0x3d8bfa0]
// [Decompilation failed for static unsigned long CSoldierRole::m_iClassID]

// address=[0x158fd10]
// Decompiled from CSoldierRole *__thiscall CSoldierRole::CSoldierRole(CSoldierRole *this)
 CSoldierRole::CSoldierRole(void) {
  
  ISelectableSettlerRole::ISelectableSettlerRole(this);
  CWarriorBehavior::CWarriorBehavior((CSoldierRole *)((char *)this + 48));
  *(_DWORD *)this = &CSoldierRole::_vftable_;
  *((_DWORD *)this + 12) = &CSoldierRole::`vftable';
  std::list<CEntityTask>::list<CEntityTask>((char *)this + 84);
  *((_BYTE *)this + 72) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_BYTE *)this + 73) = CStaticConfigVarInt::operator int(&CSoldierRole::s_iMaxNumberOfHealings);
  return this;
}


// address=[0x158fdc0]
// Decompiled from void __thiscall CSoldierRole::~CSoldierRole(CSoldierRole *this)
 CSoldierRole::~CSoldierRole(void) {
  
  *(_DWORD *)this = &CSoldierRole::_vftable_;
  *((_DWORD *)this + 12) = &CSoldierRole::`vftable';
  if ( *((_DWORD *)this + 20) )
    *((_DWORD *)this + 20) = 0;
  std::list<CEntityTask>::~list<CEntityTask>();
  ISelectableSettlerRole::~ISelectableSettlerRole(this);
}


// address=[0x158fe10]
// Decompiled from int __thiscall CSoldierRole::SoldierMagicIdleWalk(CSoldierRole *this, struct CSettler *a2)
void  CSoldierRole::SoldierMagicIdleWalk(class CSettler *) {
  
  int v2; // eax
  int v4; // [esp+0h] [ebp-1Ch]
  int v5; // [esp+4h] [ebp-18h]
  struct CWalking *v6; // [esp+Ch] [ebp-10h]
  int v7; // [esp+10h] [ebp-Ch]
  int v8; // [esp+14h] [ebp-8h]

  v8 = IEntity::Flags(a2);
  if ( ((unsigned int)dword_800000 & v8) != 0 )
  {
    IMovingEntity::SetDisplacementCosts(10);
    *((_BYTE *)this + 5) = 8;
    IAnimatedEntity::RegisterForLogicUpdate(8);
  }
  else
  {
    IMovingEntity::SetDisplacementCosts(0);
    if ( (v8 & 0x400000) != 0 )
      v7 = 0x10000000;
    else
      v7 = 0;
    v6 = IMovingEntity::Walking(a2);
    v2 = IEntity::PackedXY(a2);
    v5 = (*(int (__thiscall **)(struct CWalking *, int, int))(*(_DWORD *)v6 + 16))(v6, v2, v7);
    v4 = CSettler::WalkDir(a2, v5);
    CSoldierRole::EvaluateWalkAndRegister(this, a2, v4);
  }
  return CSoldierRole::CheckToDoList();
}


// address=[0x158fed0]
// Decompiled from int __thiscall CSoldierRole::GetNextJob(CSoldierRole *this, void **a2)
void  CSoldierRole::GetNextJob(class CSettler *) {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-40h]
  _BYTE v4[12]; // [esp+4h] [ebp-3Ch] BYREF
  Grid *v5; // [esp+10h] [ebp-30h]
  int v6; // [esp+14h] [ebp-2Ch]
  int v7; // [esp+18h] [ebp-28h]
  int v8; // [esp+1Ch] [ebp-24h]
  int v9; // [esp+20h] [ebp-20h]
  int v10; // [esp+24h] [ebp-1Ch]
  int v11; // [esp+28h] [ebp-18h]
  int ActualTask; // [esp+2Ch] [ebp-14h]
  CSoldierRole *v13; // [esp+30h] [ebp-10h]
  int v14; // [esp+3Ch] [ebp-4h]

  v13 = this;
  result = *(unsigned __int8 *)(IMovingEntity::GetActualTask(a2) + 4);
  if ( result == 17 )
  {
    if ( *((_DWORD *)v13 + 20) )
    {
      *((_DWORD *)v13 + 20) = 0;
      return (*(int (__thiscall **)(CSoldierRole *, void **))(*(_DWORD *)v13 + 40))(v13, a2);
    }
  }
  else
  {
    v5 = (Grid *)*(__int16 *)(std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator->(a2 + 22)
                            + 10);
    v6 = *(__int16 *)(std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator->(a2 + 22) + 12);
    IMovingEntity::IncToDoListIter(a2);
    ActualTask = IMovingEntity::GetActualTask(a2);
    if ( *(_BYTE *)(ActualTask + 4) == 17
      && (*(_WORD *)(ActualTask + 10) & 1) != 0
      && (unsigned int)std::list<CEntityTask>::size(a2[21]) > 2 )
    {
      v10 = std::list<CEntityTask>::begin(v4);
      v9 = v10;
      v14 = 0;
      v11 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator*(v10);
      v14 = -1;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v4);
      v7 = *(__int16 *)(v11 + 10);
      v8 = *(__int16 *)(v11 + 12);
      if ( (int)Grid::Distance(v5, v6, v7, v8) > 3 )
        IMovingEntity::ResetToDoList(v3);
    }
    *((_DWORD *)v13 + 20) = 0;
    return (*(int (__thiscall **)(CSoldierRole *, void **))(*(_DWORD *)v13 + 40))(v13, a2);
  }
  return result;
}


// address=[0x1590040]
// Decompiled from int __thiscall CSoldierRole::TakeJob(ISettlerRole *this, CPaneContainer *a2)
void  CSoldierRole::TakeJob(class CSettler *) {
  
  const struct CEntityTask *v2; // eax
  int result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int LastLogicUpdateTick; // eax
  int v8; // eax
  int v9; // esi
  int v10; // eax
  CBuilding *v11; // eax
  int v12; // eax
  CManakopter *ManakopterPtr; // eax
  struct IEntity *v14; // eax
  Y16X16 *v15; // eax
  int v16; // eax
  int v17; // [esp-4h] [ebp-1CCh]
  int v18; // [esp-4h] [ebp-1CCh]
  int v19; // [esp-4h] [ebp-1CCh]
  int v20; // [esp-4h] [ebp-1CCh]
  int v21; // [esp-4h] [ebp-1CCh]
  int v22; // [esp+4h] [ebp-1C4h]
  int v23; // [esp+Ch] [ebp-1BCh]
  unsigned __int8 *v24; // [esp+10h] [ebp-1B8h]
  int NextDestination; // [esp+14h] [ebp-1B4h]
  int v26; // [esp+18h] [ebp-1B0h]
  int *v27; // [esp+20h] [ebp-1A8h]
  char v29[408]; // [esp+2Ch] [ebp-19Ch] BYREF

  v22 = IAnimatedEntity::JobPart(a2);
  v26 = IAnimatedEntity::Frame(a2);
  if ( *((_DWORD *)this + 20) )
  {
    ISettlerRole::InitCommonTaskValues(this, a2, *((const struct CEntityTask **)this + 20));
  }
  else
  {
    v2 = (const struct CEntityTask *)std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator*((char *)a2 + 88);
    ISettlerRole::InitCommonTaskValues(this, a2, v2);
  }
  switch ( *((_BYTE *)this + 4) )
  {
    case 7:
    case 8:
    case 9:
      if ( *((_BYTE *)this + 4) == 9 )
      {
        v27 = &dword_420320[229176];
      }
      else if ( *((_BYTE *)this + 4) == 8 )
      {
        v27 = dword_200000;
      }
      else
      {
        v27 = dword_100000;
      }
      *((_BYTE *)this + 4) = 27;
      IMovingEntity::SetDisplacementCosts(5);
      if ( v22 == IAnimatedEntity::JobPart(a2) && v26 >= 1 && v26 < *((unsigned __int8 *)this + 7) )
        IAnimatedEntity::SetFrame(v26);
      else
        IAnimatedEntity::SetFrame(1);
      *((_BYTE *)this + 5) = 0x80;
      v5 = IEntity::PackedXY(a2);
      CGroupDestinations::CGroupDestinations(
        (CGroupDestinations *)v29,
        *((__int16 *)this + 7),
        *((__int16 *)this + 8),
        1,
        1,
        v5);
      NextDestination = CGroupDestinations::GetNextDestination(v29);
      *((_WORD *)this + 7) = Y16X16::UnpackXFast(NextDestination);
      *((_WORD *)this + 8) = Y16X16::UnpackYFast(NextDestination);
      v6 = Y16X16::PackXYFast(*((__int16 *)this + 7), *((__int16 *)this + 8));
      (**((void (__thiscall ***)(_DWORD *, CPaneContainer *, int, int *))this + 12))((_DWORD *)this + 12, a2, v6, v27);
      result = CSoldierRole::CheckToDoList();
      break;
    case 0xA:
      *((_BYTE *)this + 4) = 6;
      *((_BYTE *)this + 4) = 27;
      IMovingEntity::SetDisplacementCosts(5);
      IAnimatedEntity::RegisterForLogicUpdate(1);
      *((_BYTE *)a2 + 36) = 1;
      *((_BYTE *)this + 5) = 1;
      v17 = IEntity::Type((unsigned __int16 *)a2);
      v4 = IEntity::Race(a2);
      if ( CGfxManager::GetSettlerFirstJob(v4, v17) != *((unsigned __int16 *)a2 + 19) )
        *((_BYTE *)this + 5) = 1;
      goto LABEL_8;
    case 0x10:
    case 0x22:
      if ( !*((_WORD *)this + 17)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1048, "m_uEntityId > 0") == 1 )
      {
        __debugbreak();
      }
      if ( *((char *)this + 6) <= 0
        && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1049, "m_iJobCounter > 0") == 1 )
      {
        __debugbreak();
      }
      IMovingEntity::SetDisplacementCosts(10);
      IAnimatedEntity::RegisterForLogicUpdate(*((char *)this + 6));
      v14 = CMapObjectMgr::Entity(*((unsigned __int16 *)this + 17));
      v21 = IEntity::PackedXY(v14);
      v15 = (Y16X16 *)IEntity::PackedXY(a2);
      v16 = Y16X16::DirectionFast(v15, v21);
      IMovingEntity::SetDirection(a2, v16);
      result = CSoldierRole::CheckToDoList();
      break;
    case 0x11:
      *((_BYTE *)this + 4) = 27;
      IMovingEntity::SetDisplacementCosts(0);
      IAnimatedEntity::RegisterForLogicUpdate(1);
      (**((void (__thiscall ***)(_DWORD *, CPaneContainer *, int, _DWORD))this + 12))((_DWORD *)this + 12, a2, -1, 0);
      result = CSoldierRole::CheckToDoList();
      break;
    case 0x18:
      IMovingEntity::SetDisplacementCosts(10);
      v18 = IEntity::ID();
      LastLogicUpdateTick = IAnimatedEntity::GetLastLogicUpdateTick(a2);
      CMapObjectMgr::UnRegisterFromLogicUpdate(g_pMapObjectMgr, LastLogicUpdateTick, v18);
      CWarMap::RemoveEntity(a2);
      v8 = IEntity::WorldIdx();
      v9 = CWorldManager::SettlerId(v8);
      if ( v9 != IEntity::ID()
        && BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\SoldierRole.cpp",
             1006,
             "g_cWorld.SettlerId(_pSettler->WorldIdx()) == _pSettler->ID()") == 1 )
      {
        __debugbreak();
      }
      v10 = IEntity::WorldIdx();
      CWorldManager::SetSettlerId(v10, 0);
      if ( IEntity::FlagBits(a2, Selectable)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\SoldierRole.cpp",
             1013,
             "_pSettler->FlagBits( ENTITY_FLAG_SELECTABLE ) == 0") == 1 )
      {
        __debugbreak();
      }
      IEntity::SetFlagBits(a2, OnBoard);
      v24 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 16));
      if ( v24 )
      {
        switch ( IEntity::ObjType(v24) )
        {
          case 2:
          case 4:
            v23 = CVehicleMgr::operator[](*((unsigned __int16 *)this + 16));
            v12 = IEntity::ID();
            (*(void (__thiscall **)(int, int))(*(_DWORD *)v23 + 128))(v23, v12);
            break;
          case 8:
            v19 = IEntity::ID();
            v11 = (CBuilding *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
            CBuilding::SettlerEnter(v11, v19);
            break;
          case 64:
            v20 = IEntity::ID();
            ManakopterPtr = CFlyingMgr::GetManakopterPtr((CFlyingMgr *)g_cFlyingMgr, *((unsigned __int16 *)this + 16));
            CManakopter::SettlerEnter(ManakopterPtr, v20);
            break;
          default:
            break;
        }
      }
      else
      {
        (*(void (__thiscall **)(ISettlerRole *, CPaneContainer *, int))(*(_DWORD *)this + 64))(this, a2, -1);
      }
LABEL_8:
      result = CSoldierRole::CheckToDoList();
      break;
    default:
      result = CTrace::Print("SoldierJob - TakeJob unknown task");
      break;
  }
  return result;
}


// address=[0x1590680]
// Decompiled from int __thiscall CSoldierRole::Init(int this, CPropertySet *a2)
void  CSoldierRole::Init(class CSettler *) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int result; // eax
  int v6; // [esp-4h] [ebp-10h]
  int v7; // [esp-4h] [ebp-10h]
  EntityFlag v8; // [esp+4h] [ebp-8h]

  v6 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  CSettlerMgr::GetSettlerInfo(v2, v6);
  *(_WORD *)(this + 18) = IEntity::EntityId((unsigned __int16 *)a2);
  *(_DWORD *)(this + 80) = 0;
  IEntity::SetFlagBits(a2, VulnerableMask|Selectable);
  v3 = IEntity::Type((unsigned __int16 *)a2);
  v8 = CSettlerMgr::SettlerWarriorType(v3);
  IEntity::SetFlagBits(a2, v8);
  CWarMap::AddEntity(a2);
  (**(void (__thiscall ***)(int, CPropertySet *, int, _DWORD))(this + 48))(this + 48, a2, -1, 0);
  v7 = IEntity::Type((unsigned __int16 *)a2);
  v4 = IEntity::Race(a2);
  result = CSettlerMgr::GetSettlerInfo(v4, v7);
  *(_DWORD *)(this + 96) = result;
  *(_BYTE *)(this + 4) = 27;
  return result;
}


// address=[0x1590740]
// Decompiled from void __thiscall CSoldierRole::ConvertEventIntoGoal(int this, CPropertySet *a2, const struct CEntityEvent *a3)
void  CSoldierRole::ConvertEventIntoGoal(class CSettler *,class CEntityEvent *) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // esi
  int v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // esi
  int v12; // eax
  int v13; // eax
  _DWORD *v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // esi
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // [esp-8h] [ebp-74h]
  int v36; // [esp-8h] [ebp-74h]
  int v37; // [esp-8h] [ebp-74h]
  int v38; // [esp-8h] [ebp-74h]
  int v39; // [esp-8h] [ebp-74h]
  int v40; // [esp-8h] [ebp-74h]
  int v41; // [esp-8h] [ebp-74h]
  int v42; // [esp-8h] [ebp-74h]
  int v43; // [esp-8h] [ebp-74h]
  int v44; // [esp-4h] [ebp-70h]
  int v45; // [esp-4h] [ebp-70h]
  int v46; // [esp-4h] [ebp-70h]
  int v47; // [esp-4h] [ebp-70h]
  int v48; // [esp-4h] [ebp-70h]
  int v49; // [esp-4h] [ebp-70h]
  int v50; // [esp-4h] [ebp-70h]
  int v51; // [esp-4h] [ebp-70h]
  int v52; // [esp-4h] [ebp-70h]
  int v53; // [esp+4h] [ebp-68h]
  int v54; // [esp+8h] [ebp-64h]
  int v55; // [esp+Ch] [ebp-60h]
  CMilitaryBuildingRole *v56; // [esp+10h] [ebp-5Ch]
  int v57; // [esp+14h] [ebp-58h]
  int v58; // [esp+24h] [ebp-48h]
  int v59; // [esp+28h] [ebp-44h]
  int v60; // [esp+2Ch] [ebp-40h]
  int v61; // [esp+30h] [ebp-3Ch]
  int v62; // [esp+34h] [ebp-38h]
  int v63; // [esp+38h] [ebp-34h]
  int v64; // [esp+3Ch] [ebp-30h]
  int v65; // [esp+40h] [ebp-2Ch]
  int v66; // [esp+44h] [ebp-28h]
  struct CManakopter *ManakopterPtr; // [esp+48h] [ebp-24h]
  int v68; // [esp+4Ch] [ebp-20h]
  unsigned __int8 *BuildingPtr; // [esp+50h] [ebp-1Ch]
  struct CManakopter *v70; // [esp+58h] [ebp-14h]
  _DWORD *v71; // [esp+5Ch] [ebp-10h]
  int v72; // [esp+60h] [ebp-Ch]
  int i; // [esp+64h] [ebp-8h]

  switch ( *((_DWORD *)a3 + 1) )
  {
    case 1:
      if ( ISettlerRole::HomeEntityId(this) )
      {
        v17 = ISettlerRole::HomeEntityId(this);
        CSoldierRole::ComeToWork((CSoldierRole *)this, a2, v17);
      }
      else
      {
        (*(void (__thiscall **)(int, CPropertySet *, int))(*(_DWORD *)this + 64))(this, a2, -1);
      }
      break;
    case 7:
    case 9:
      if ( !IEntity::FlagBits(a2, Selectable) )
      {
        IEntity::SetFlagBits(a2, Selectable);
        CSettler::TakeWaitList(a2);
        (**(void (__thiscall ***)(int, CPropertySet *, int, _DWORD))(this + 48))(this + 48, a2, -1, 0);
        *(_BYTE *)(this + 4) = 27;
        v44 = *((_DWORD *)a3 + 3);
        v35 = IEntity::EntityId((unsigned __int16 *)a2);
        v3 = IEntity::OwnerId((unsigned __int8 *)a2);
        (*(void (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(
          off_3D7A3D8,
          21,
          v3,
          v35,
          v44);
      }
      break;
    case 0x11:
      if ( !IEntity::FlagBits(a2, Selectable) )
        goto LABEL_12;
      if ( *((_DWORD *)a3 + 2) == 13
        && !ISelectableSettlerRole::ProcessGoToPosFerry((ISelectableSettlerRole *)this, a2, a3) )
      {
        v55 = *((_DWORD *)a3 + 3);
        v58 = *((_DWORD *)a3 + 4);
        v66 = *((_DWORD *)a3 + 5);
        v65 = Y16X16::UnpackXFast(v66);
        v64 = Y16X16::UnpackYFast(v66);
        if ( v66 <= 0 )
          goto LABEL_33;
        if ( ISettlerRole::HomeEntityId(this) )
          goto LABEL_33;
        if ( !IEntity::FlagBits(a2, Selectable) )
          goto LABEL_33;
        if ( !CWorldManager::FlagBits(v65, v64, 1u) )
          goto LABEL_33;
        v7 = CWorldManager::OwnerId(v65, v64);
        if ( v7 != IEntity::OwnerId((unsigned __int8 *)a2) )
          goto LABEL_33;
        v57 = CSpiralOffsets::Last(5);
        v72 = 0;
        for ( i = 0; i <= v57; ++i )
        {
          v59 = v65 + CSpiralOffsets::DeltaX(i);
          v60 = v64 + CSpiralOffsets::DeltaY(i);
          if ( (unsigned __int8)CWorldManager::InWorld(v59, v60) )
          {
            v63 = CWorldManager::MapObjectId(v59, v60);
            if ( v63 )
            {
              BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v63);
              if ( BuildingPtr )
              {
                if ( IEntity::WarriorType() == 12 )
                {
                  v8 = IEntity::OwnerId(BuildingPtr);
                  if ( v8 == IEntity::OwnerId((unsigned __int8 *)a2) )
                  {
                    v9 = CBuilding::EnsignPackedXY(BuildingPtr);
                    v10 = CWorldManager::Index(v9);
                    v11 = ITiling::SectorId(v10);
                    v12 = IEntity::PackedXY(a2);
                    v13 = CWorldManager::Index(v12);
                    if ( v11 == ITiling::SectorId(v13) )
                    {
                      v72 = v63;
                      break;
                    }
                  }
                }
              }
            }
          }
        }
        if ( v72
          && (v14 = (_DWORD *)CBuildingMgr::operator[](v72),
              v56 = (CMilitaryBuildingRole *)CBuilding::Role(v14),
              v15 = IEntity::Type((unsigned __int16 *)a2),
              v16 = CSettlerMgr::SettlerWarriorType(v15),
              CMilitaryBuildingRole::HaveFreeSlots(v56, v16)) )
        {
          CSettler::AttachToBuilding(a2, v72);
          CSoldierRole::ComeToWork((CSoldierRole *)this, a2, v72);
        }
        else
        {
LABEL_33:
          v53 = Y16X16::UnpackXFast(v58);
          v54 = Y16X16::UnpackYFast(v58);
          CSoldierRole::NewDestinationEx((CSoldierRole *)this, a2, v53, v54, v55);
          IEntity::SetFlagBits(a2, (EntityFlag)0x80000000);
        }
      }
      break;
    case 0x18:
      v47 = IEntity::Type((unsigned __int16 *)a2);
      v18 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v18, v47);
      v71 = (_DWORD *)CVehicleMgr::operator[](*((_DWORD *)a3 + 3));
      v19 = IEntity::ID();
      v62 = (*(int (__thiscall **)(_DWORD *, int, int))(*v71 + 140))(v71, 1, v19);
      if ( v62 && IEntity::FlagBits(v71, (EntityFlag)&loc_3000000) )
      {
        v38 = Y16X16::UnpackYFast(v62);
        v20 = Y16X16::UnpackXFast(v62);
        CSoldierRole::NewDestinationEx((CSoldierRole *)this, a2, v20, v38, 0);
        v48 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v39 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v21 = IEntity::Race(a2);
        v22 = CEntityToDoListMgr::SettlerJobList(v21, v39);
        (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v22, v48);
        v23 = IEntity::OwnerId((unsigned __int8 *)a2);
        if ( v23 == CPlayerManager::GetLocalPlayerId() )
        {
          v24 = IEntity::ID();
          CInputProcessor::DeSelectEntity(&g_cInputProcessor, v24);
        }
        v25 = IEntity::ID();
        (*(void (__thiscall **)(_DWORD *, int))(*v71 + 164))(v71, v25);
        IEntity::ClearFlagBits(a2, Selectable|Selected);
        v26 = IEntity::ID();
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)g_pGroupMgr + 28))(g_pGroupMgr, v26);
        v49 = *(unsigned __int16 *)(this + 32);
        v40 = IEntity::ID();
        v27 = IEntity::OwnerId((unsigned __int8 *)a2);
        (*(void (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(
          off_3D7A3D8,
          18,
          v27,
          v40,
          v49);
      }
      else
      {
        IEntity::SetFlagBits(a2, Selectable);
        v50 = IEntity::Type((unsigned __int16 *)a2);
        v41 = IEntity::Type((unsigned __int16 *)a2);
        v28 = IEntity::Race(a2);
        v29 = CEntityToDoListMgr::SettlerJobList(v28, v41);
        (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v29, v50);
      }
      break;
    case 0x19:
      v61 = *((_DWORD *)a3 + 4);
      v45 = Y16X16::UnpackYFast(v61);
      v36 = Y16X16::UnpackXFast(v61);
      v4 = IEntity::ID();
      CSettlerMgr::SearchSpaceForSettler((CSettlerMgr *)g_cSettlerMgr, v4, v36, v45);
      CWarMap::AddEntity(a2);
      IEntity::SetFlagBits(a2, Selectable|Visible);
      IEntity::ClearFlagBits(a2, OnBoard);
      (**(void (__thiscall ***)(int, CPropertySet *, int, _DWORD))(this + 48))(this + 48, a2, -1, 0);
      *(_BYTE *)(this + 4) = 27;
      if ( IEntity::Race(a2) != 3 )
      {
        v46 = *(unsigned __int16 *)(this + 32);
        v37 = IEntity::ID();
        v5 = IEntity::OwnerId((unsigned __int8 *)a2);
        (*(void (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(
          off_3D7A3D8,
          21,
          v5,
          v37,
          v46);
      }
      if ( IEntity::FlagBits(a2, Attached) )
      {
        ManakopterPtr = CFlyingMgr::GetManakopterPtr((CFlyingMgr *)g_cFlyingMgr, *(unsigned __int16 *)(this + 32));
        if ( ManakopterPtr )
        {
          v6 = IEntity::ID();
          (*(void (__thiscall **)(struct CManakopter *, int))(*(_DWORD *)ManakopterPtr + 64))(ManakopterPtr, v6);
        }
      }
      break;
    case 0x1C:
      v51 = IEntity::Type((unsigned __int16 *)a2);
      v30 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v30, v51);
      v70 = CFlyingMgr::GetManakopterPtr((CFlyingMgr *)g_cFlyingMgr, *((_DWORD *)a3 + 3));
      if ( v70 && !IEntity::FlagBits(v70, (EntityFlag)&unk_4000000) )
      {
        v68 = IEntity::PackedXY(v70);
        if ( v68 )
        {
          v42 = Y16X16::UnpackYFast(v68);
          v31 = Y16X16::UnpackXFast(v68);
          CSoldierRole::NewDestinationEx((CSoldierRole *)this, a2, v31, v42, 0);
          (**(void (__thiscall ***)(int, CPropertySet *, int, int))(this + 48))(this + 48, a2, v68, 0x200000);
          v52 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
          v43 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
          v32 = IEntity::Race(a2);
          v33 = CEntityToDoListMgr::SettlerJobList(v32, v43);
          (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v33, v52);
          IEntity::ClearFlagBits(a2, Selectable|Selected);
          v34 = IEntity::ID();
          (*(void (__thiscall **)(struct CManakopter *, int))(*(_DWORD *)v70 + 112))(v70, v34);
        }
      }
      else
      {
LABEL_12:
        IEntity::SetFlagBits(a2, (EntityFlag)0x80000000);
      }
      break;
    default:
      if ( BBSupportDbgReportF(
             1,
             "MapObjects\\Settler\\SoldierRole.cpp",
             1453,
             "CSoldierRole::ConvertEventIntoGoal(): Invalid event %i!",
             *((_DWORD *)a3 + 1)) == 1 )
        __debugbreak();
      if ( !IEntity::FlagBits(a2, Registered) )
      {
        CTrace::Print("ConvertEventIntoGoal SoldierRole - unknown event %u", *((_DWORD *)a3 + 1));
        IAnimatedEntity::RegisterForLogicUpdate(1);
      }
      break;
  }
}


// address=[0x1590f40]
// Decompiled from int __thiscall CSoldierRole::ComeToWork(CSoldierRole *this, struct CSettler *a2, int a3)
void  CSoldierRole::ComeToWork(class CSettler *,int) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int result; // eax
  int v7; // eax
  int v8; // [esp-8h] [ebp-10h]
  int v9; // [esp-8h] [ebp-10h]
  int v10; // [esp-4h] [ebp-Ch]
  int v11; // [esp-4h] [ebp-Ch]
  CMFCToolBarButton *v12; // [esp+0h] [ebp-8h]

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1559, "_pSettler != 0") == 1 )
    __debugbreak();
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1560, "_iBuildingId > 0") == 1 )
    __debugbreak();
  if ( *((unsigned __int16 *)this + 16) != a3
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1562, "m_uHomeEntityId == _iBuildingId") == 1 )
  {
    __debugbreak();
  }
  if ( !IEntity::FlagBits(a2, Attached)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SoldierRole.cpp",
         1563,
         "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED) != 0") == 1 )
  {
    __debugbreak();
  }
  v12 = (CMFCToolBarButton *)CBuildingMgr::operator[](a3);
  if ( !IEntity::FlagBits(v12, (EntityFlag)&loc_3000000)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\SoldierRole.cpp",
         1567,
         "rBuilding.FlagBits(ENTITY_FLAG_ALIVE_MASK) != 0") == 1 )
  {
    __debugbreak();
  }
  v3 = CBuilding::DoorPackedXY(v12);
  (**((void (__thiscall ***)(char *, struct CSettler *, int, int))this + 12))((char *)this + 48, a2, v3, 0x200000);
  CSoldierRole::CheckToDoList();
  v10 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
  v8 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
  v4 = IEntity::Race(a2);
  v5 = CEntityToDoListMgr::SettlerJobList(v4, v8);
  (*(void (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v5, v10);
  IEntity::ClearFlagBits(a2, Selectable|Selected);
  result = IEntity::Type((unsigned __int16 *)v12);
  if ( result == 24 )
    return result;
  v11 = *((unsigned __int16 *)this + 16);
  v9 = IEntity::ID();
  v7 = IEntity::OwnerId((unsigned __int8 *)a2);
  return (*(int (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(off_3D7A3D8, 18, v7, v9, v11);
}


// address=[0x1591100]
// Decompiled from char __thiscall CSoldierRole::NewDestinationEx(CSoldierRole *this, struct CSettler *a2, int a3, int a4, __int16 a5)
bool  CSoldierRole::NewDestinationEx(class CSettler *,int,int,int) {
  
  int v5; // eax
  unsigned int v6; // eax
  __int16 v7; // ax
  CEntityTask *v8; // eax
  CEntityTask *v9; // eax
  CEntityTask *v10; // eax
  __int16 v12; // [esp-28h] [ebp-A4h]
  int v13; // [esp-4h] [ebp-80h]
  _DWORD v14[6]; // [esp+0h] [ebp-7Ch] BYREF
  _BYTE v15[24]; // [esp+18h] [ebp-64h] BYREF
  _BYTE v16[24]; // [esp+30h] [ebp-4Ch] BYREF
  int v17; // [esp+48h] [ebp-34h]
  int v18; // [esp+4Ch] [ebp-30h]
  int v19; // [esp+50h] [ebp-2Ch]
  int v20; // [esp+54h] [ebp-28h]
  int v21; // [esp+58h] [ebp-24h]
  int v22; // [esp+5Ch] [ebp-20h]
  int v23; // [esp+60h] [ebp-1Ch]
  unsigned int SettlerJobFrameCount; // [esp+64h] [ebp-18h]
  int SettlerFirstJob; // [esp+68h] [ebp-14h]
  int v26; // [esp+6Ch] [ebp-10h]
  bool v27; // [esp+73h] [ebp-9h]
  bool v28; // [esp+74h] [ebp-8h]
  bool v29; // [esp+75h] [ebp-7h]
  bool v30; // [esp+76h] [ebp-6h]
  char v31; // [esp+77h] [ebp-5h]
  CSoldierRole *v32; // [esp+78h] [ebp-4h]

  v32 = this;
  v31 = 0;
  if ( (a5 & 1) != 0 )
  {
    a5 &= ~2u;
    v21 = IEntity::X(a2);
    v22 = IEntity::Y(a2);
    if ( (int)Grid::Distance((Grid *)(a3 - v21), a4 - v22) < 3 )
      a5 &= ~1u;
  }
  v23 = std::list<CEntityTask>::size((char *)v32 + 84);
  if ( v23 <= 0 )
  {
    v31 = 1;
  }
  else
  {
    v20 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator*((char *)a2 + 88);
    v30 = (a5 & 2) != 0;
    v28 = v30;
    v19 = *(unsigned __int8 *)(v20 + 4);
    v29 = v19 == 17;
    v27 = v19 == 17;
    if ( (a5 & 2) != 0 && !v27 && v23 > 1 )
    {
      v18 = std::list<CEntityTask>::back();
      v17 = *(unsigned __int8 *)(v18 + 4);
      if ( v17 == 17 )
        std::list<CEntityTask>::pop_back();
    }
    else
    {
      std::list<CEntityTask>::clear();
      v31 = 1;
    }
  }
  v13 = IEntity::Type((unsigned __int16 *)a2);
  v5 = IEntity::Race(a2);
  SettlerFirstJob = CGfxManager::GetSettlerFirstJob(v5, v13);
  v6 = IEntity::Race(a2);
  SettlerJobFrameCount = CGfxManager::GetSettlerJobFrameCount((CGfxManager *)g_pGfxManager, v6, SettlerFirstJob, 2u);
  if ( (a5 & 8) != 0 )
  {
    v26 = 9;
  }
  else if ( (a5 & 4) != 0 )
  {
    v26 = 8;
  }
  else
  {
    v26 = 7;
  }
  if ( (a5 & 1) != 0 )
  {
    if ( std::list<CEntityTask>::size((char *)v32 + 84)
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 796, "m_vTasks.size() == 0") == 1 )
    {
      __debugbreak();
    }
    v12 = IEntity::Y(a2);
    v7 = IEntity::X(a2);
    v8 = CEntityTask::CEntityTask(
           (CEntityTask *)v16,
           v26,
           SettlerFirstJob,
           v7,
           v12,
           -1,
           SettlerJobFrameCount,
           -1,
           1,
           1,
           0,
           0,
           0,
           0);
    std::list<CEntityTask>::push_back(v8);
  }
  v9 = CEntityTask::CEntityTask(
         (CEntityTask *)v15,
         v26,
         SettlerFirstJob,
         a3,
         a4,
         -1,
         SettlerJobFrameCount,
         -1,
         1,
         1,
         0,
         0,
         0,
         0);
  std::list<CEntityTask>::push_back(v9);
  v10 = CEntityTask::CEntityTask(
          (CEntityTask *)v14,
          17,
          SettlerFirstJob,
          a5,
          0,
          -1,
          SettlerJobFrameCount,
          -1,
          1,
          1,
          0,
          0,
          0,
          0);
  std::list<CEntityTask>::push_back(v10);
  IMovingEntity::SetToDoList(a2, (int)v32 + 84);
  if ( (unsigned int)std::list<CEntityTask>::size((char *)v32 + 84) < 2
    && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 850, "m_vTasks.size() >= 2") == 1 )
  {
    __debugbreak();
  }
  CSoldierRole::CheckToDoList();
  if ( v31 )
  {
    if ( std::list<CEntityTask>::size((char *)v32 + 84) != 2
      && std::list<CEntityTask>::size((char *)v32 + 84) != 3
      && BBSupportDbgReport(
           2,
           "MapObjects\\Settler\\SoldierRole.cpp",
           856,
           "(m_vTasks.size() == 2) || ((m_vTasks.size() == 3))") == 1 )
    {
      __debugbreak();
    }
    IMovingEntity::ResetToDoList(v14[0]);
    *((_DWORD *)v32 + 20) = 0;
    (*(void (__thiscall **)(CSoldierRole *, struct CSettler *))(*(_DWORD *)v32 + 40))(v32, a2);
    CSoldierRole::CheckToDoList();
    return 1;
  }
  else
  {
    if ( (unsigned int)std::list<CEntityTask>::size((char *)v32 + 84) <= 2
      && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 870, "m_vTasks.size() > 2") == 1 )
    {
      __debugbreak();
    }
    return 0;
  }
}


// address=[0x1591450]
// Decompiled from int __thiscall CSoldierRole::EvaluateWalkAndRegister(CSoldierRole *this, struct IMovingEntity *a2, char a3)
void  CSoldierRole::EvaluateWalkAndRegister(class IMovingEntity &,int) {
  
  *((_BYTE *)this + 5) = a3;
  if ( (a3 & 0xFu) >= 6 )
  {
    IAnimatedEntity::RegisterForLogicUpdate(1);
  }
  else
  {
    *((_BYTE *)this + 6) = 9;
    if ( IEntity::WarriorType() == 2 )
      *((_BYTE *)this + 6) = 7;
    IAnimatedEntity::RegisterForLogicUpdate(*((char *)this + 6));
    IMovingEntity::SetDistance(a2, 255);
  }
  if ( (a3 & 0x10) != 0 )
    return IMovingEntity::SetDisplacementCosts(0);
  else
    return IMovingEntity::SetDisplacementCosts(5);
}


// address=[0x1592280]
// Decompiled from int __thiscall CSoldierRole::SoldierWarriorLogicUpdate(CSoldierRole *this, struct CSettler *a2)
void  CSoldierRole::SoldierWarriorLogicUpdate(class CSettler *) {
  
  unsigned int TickCounter; // esi
  int v3; // esi
  unsigned int v4; // eax
  int v6; // [esp+8h] [ebp-8h]

  v6 = IEntity::Type((unsigned __int16 *)a2);
  if ( v6 >= 35 && v6 <= 37 )
  {
    TickCounter = CGameData::GetTickCounter(g_pGameData);
    if ( TickCounter >= *((_DWORD *)this + 19)
                      + CStaticConfigVarInt::operator int(&CSoldierRole::s_iTicksToRegeneration) )
    {
      *((_DWORD *)this + 19) = CGameData::GetTickCounter(g_pGameData);
      v3 = *((unsigned __int8 *)this + 73);
      if ( v3 < CStaticConfigVarInt::operator int(&CSoldierRole::s_iMaxNumberOfHealings) )
        ++*((_BYTE *)this + 73);
    }
  }
  if ( ((unsigned int)&byte_C00000 & IEntity::Flags(a2)) != 0 )
  {
    CSoldierRole::SoldierMagicIdleWalk(this, a2);
  }
  else
  {
    v4 = CGameData::GetTickCounter(g_pGameData);
    CWarriorBehavior::WarriorLogicUpdate((CSoldierRole *)((char *)this + 48), a2, v4, 0);
  }
  return CSoldierRole::CheckToDoList();
}


// address=[0x4158c98]
// [Decompilation failed for static class CStaticConfigVarInt CSoldierRole::s_iMaxNumberOfHealings]

// address=[0x4158ca4]
// [Decompilation failed for static class CStaticConfigVarInt CSoldierRole::s_iTicksToRegeneration]

