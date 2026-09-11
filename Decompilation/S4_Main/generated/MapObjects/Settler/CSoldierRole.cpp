#include "CSoldierRole.h"

// Definitions for class CSoldierRole

// address=[0x1401f80]
// Decompiled from int __cdecl CSoldierRole::New(int a1)
class CPersistence * __cdecl CSoldierRole::New(std::istream & a1) {
  
  if ( operator new(0x64u) != 0 )
  {
    return ((_DWORD (__stdcall *)(int))CSoldierRole::CSoldierRole)(a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x1588900]
// Decompiled from int __cdecl CSoldierRole::Load(struct std::istream *a1)
class CSoldierRole * __cdecl CSoldierRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)((void **(__cdecl *)(struct std::istream *, struct TypeDescriptor *))CPersistence::New)(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CSoldierRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x158e510]
// Decompiled from int __thiscall CSoldierRole::InitWalking(CSoldierRole *this, struct CSettler *a2)
class CWalking *  CSoldierRole::InitWalking(class CSettler * a2) {
  
  int v2; // eax

  v2 = IEntity::OwnerId(a2);
  return (int)CWalking::Create(0, v2);
}


// address=[0x158e540]
// Decompiled from void __thiscall CSoldierRole::LogicUpdateJob(CSoldierRole *this, struct CSettler *a2)
void  CSoldierRole::LogicUpdateJob(class CSettler * a2) {
  
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
  IEntity *v44; // [esp+8Ch] [ebp-2Ch]
  int v45; // [esp+90h] [ebp-28h] BYREF
  int v46; // [esp+94h] [ebp-24h]
  int v47; // [esp+98h] [ebp-20h]
  struct IEntity *v48; // [esp+9Ch] [ebp-1Ch]
  int v49; // [esp+A0h] [ebp-18h]
  int v50; // [esp+A4h] [ebp-14h]
  char; // [esp+AAh] [ebp-Eh]
  int v53; // [esp+ACh] [ebp-Ch]
  unsigned __int8 *v54; // [esp+B0h] [ebp-8h]
  CSoldierRole *v55; // [esp+B4h] [ebp-4h]

  v55 = this;
  if ( this->m_iTask == 16 )
  {
    v54 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(v55->m_uEntityId);
    if ( v54 != 0 )
    {
      if ( IEntity::FlagBits((IEntity *)v54, (EntityFlag)((char *)&loc_1FFFFFF + 1)) != 0 && IEntity::FlagBits((IEntity *)v54, ENTITY_FLAG_VulnerableMask) != 0 )
      {
        v53 = *(unsigned __int8 *)(v55->m_iU5 + 3);
        v43 = IEntity::OwnerId(a2);
        v2 = IEntity::PackedXY(a2);
        v3 = CWorldManager::Index(v2);
        v32 = ITiling::OwnerId(v3);
        v31 = CAlliances::AllianceId(v43);
        v30 = CAlliances::AllianceId(v32);
        if ( v31 == v30 )
        {
          v41 = CStatistic::DefenceStrength256(&g_cStatistic, v43);
        }
        else
        {
          v41 = CStatistic::OffenceStrength256(&g_cStatistic, v43);
        }
        v29 = v41;
        v53 = (v41 * v53 + 127) >> 8;
        v40 = v53 == 0;
        v53 += v40;
        if ( (IEntity::Flags(a2) & 0x100000) != 0 )
        {
          v53 += (v53 * CStaticConfigVarInt::operator int((CStaticConfigVarInt *)g_pMagicBloodlustDmgIncrease256) + 127) >> 8;
        }
        if ( (ISelectableSettlerRole::GetGroupFlagsEx(v55) & 0x800) != 0 )
        {
          v4 = IEntity::Race(a2);
          SquadLeaderBonus256 = CSettlerMgr::GetSquadLeaderBonus256(v4);
          v46 = SquadLeaderBonus256 * v53;
          if ( (unsigned __int8)CStateGame::Rand(g_pGame) < (unsigned int)(unsigned __int8)(SquadLeaderBonus256 * v53) )
          {
            v46 += 256;
          }
          v53 += v46 >> 8;
        }
        v5 = IEntity::OwnerId((IEntity *)v54);
        if ( v5 == CPlayerManager::GetLocalPlayerId() )
        {
          v15 = IEntity::Y(v54);
          v6 = IEntity::X(v54);
          CAttackMsgList::SendAttackMessage((CAttackMsgList *)&g_cAttackMsgList, v6, v15);
        }
        v38 = (Grid *)IEntity::X(v54);
        v39 = IEntity::Y(v54);
        v27 = ((int (__stdcall *)())IEntity::ID)();
        v7 = IEntity::OwnerId(a2);
        (*(void (__thiscall **)(unsigned __int8 *, int, int))(*(_DWORD *)v54 + 28))(v54, v53, v7);
        v47 = IEntity::Type(a2);
        if ( (unsigned int)(v47 - 61) <= 2 )
        {
          v18[0] = *(&s_sGoodConversionMap[4][12].m_iToGood + v47) * v53 / 100;
          v18[1] = *(&s_sGoodConversionMap[4][12].m_iToGood + v47) * v53 / 200;
          v45 = 0;
          CSettlerSpiralWalk::CSettlerSpiralWalk((CSettlerSpiralWalk *)v17, (int)v38, v39, 4);
          while ( CSettlerSpiralWalk::NextSettlerId((CSettlerSpiralWalk *)v17, &v45) )
          {
            if ( v45 == 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 525, "iNeighbourID != 0") == 1 )
            {
              __debugbreak();
            }
            if ( v45 != v27 )
            {
              v48 = CMapObjectMgr::EntityPtr(v45);
              if ( CWarriorBehavior::IsValidTarget(&v55->CWarriorBehavior, a2, v48) )
              {
                v16 = IEntity::Y(v48);
                v8 = IEntity::X(v48);
                v49 = (Grid::Distance((int)v38, v39, v8, v16) - 1) >> 1;
                v37 = v49 > 0;
                v49 = v37;
                v9 = IEntity::OwnerId(a2);
                v48->j_?Decrease@IEntity@@UAEXHH@Z(v48, v18[v49], v9);
              }
            }
          }
        }
        if ( (unsigned int)(v47 - 41) <= 2 && IEntity::FlagBits((IEntity *)v54, (EntityFlag)dword_800000) == 0 )
        {
          v26 = ((int (__stdcall *)())IEntity::WarriorType)();
          v36 = IEntity::Race(v54) == 3 ? 12 : 60;
          v25 = v36;
          if ( (v36 & (1 << v26)) != 0 )
          {
            v10 = CStateGame::Rand(g_pGame);
            if ( v10 < dword_41579C4[v47] )
            {
              v24 = (CStateGame::Rand(g_pGame) & 0xF) + 20;
              v35 = (int)CLogic::FutureEvents(g_pLogic);
              v11 = IEntity::EntityId((IEntity *)v54);
               = (*(int (__thiscall **)(int, int, int, int, _DWORD, int *))(*(_DWORD *)v35 + 12))(v35, 1, v24, v11, 0, dword_800000);
              if (  != 0 )
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
      v12 = IEntity::EntityId(a2);
      CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, v12, 3, (const char *)&stru_37BB350);
      CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, v55->m_uEntityId, 3, &stru_37BB350.cVal);
    }
    CSoldierRole::CheckToDoList();
  }
  else if ( v55->m_iTask == 34 )
  {
    v44 = CMapObjectMgr::EntityPtr(v55->m_uEntityId);
    if ( v44 != 0 && IEntity::FlagBits(v44, (EntityFlag)((char *)&loc_1FFFFFF + 1)) != 0 )
    {
      v22 = IEntity::Race(a2);
      v23 = IEntity::Type(a2);
      v50 = CSettlerMgr::GetSettlerInfo(v22, v23)->m_bMisc;
      if ( v50 <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 611, "iHealAmount > 0") == 1 )
      {
        __debugbreak();
      }
      v42 = IEntity::OwnerId(a2);
      v13 = IEntity::PackedXY(a2);
      v14 = CWorldManager::Index(v13);
      v21 = ITiling::OwnerId(v14);
      v20 = CAlliances::AllianceId(v42);
      v19 = CAlliances::AllianceId(v21);
      if ( v20 == v19 )
      {
        v34 = CStatistic::DefenceStrength256(&g_cStatistic, v42);
      }
      else
      {
        v34 = CStatistic::OffenceStrength256(&g_cStatistic, v42);
      }
      v18[2] = v34;
      v50 = (v34 * v50 + 127) >> 8;
      v33 = v50 == 0;
      v50 += v33;
      v44->Increase(v44, v50);
      if ( v55->m_iMaxNumberOfHealings != 0 )
      {
        --v55->m_iMaxNumberOfHealings;
      }
    }
    CSoldierRole::CheckToDoList();
  }
  if ( v55->m_iU3 != 0 )
  {
    v55->m_iU3 = 0;
    ((void (__thiscall *)(CSoldierRole *, struct CSettler *))v55->ISelectableSettlerRole::ISettlerRole::CPersistence::__vftable[2].j_?WarriorInit@CWarriorBehavior@@UAEXAAVIMovingEntity@@HH@Z)(v55, a2);
    if ( v55->m_iTask == 27 )
    {
      CSoldierRole::SoldierWarriorLogicUpdate(v55, a2);
    }
  }
  else
  {
    CSoldierRole::SoldierWarriorLogicUpdate(v55, a2);
    CSoldierRole::CheckToDoList();
  }
}


// address=[0x158ebc0]
// Decompiled from int __thiscall CSoldierRole::UpdateJob(CSoldierRole *this, struct CSettler *a2)
void  CSoldierRole::UpdateJob(class CSettler * a2) {
  
  int v2; // eax
  int v3; // eax

  switch ( this->m_iTask )
  {
    case 0x10:
    case 0x22:
      v2 = IAnimatedEntity::Frame(a2);
      ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)((this->m_uTick + v2) % this->m_uCycleFrames);
      break;
    case 0x18:
      return CSoldierRole::CheckToDoList();
    case 0x1B:
      if ( (this->m_uSettlerWalk & 8) != 0 )
      {
        a2->m_iFrame = 0;
      }
      else
      {
        v3 = IAnimatedEntity::Frame(a2);
        ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)((this->m_uTick + v3) % this->m_uCycleFrames);
        if ( a2->m_iFrame == 0 )
        {
          a2->m_iFrame = 1;
        }
        IMovingEntity::DecDistance(a2, (this->m_uTick << 8) / this->m_iWalkspeed);
      }
      break;
    default:
      CTrace::Print("SoldierRole - UpdateJob unknown task!");
      break;
  }
  return CSoldierRole::CheckToDoList();
}


// address=[0x158ed00]
// Decompiled from int __thiscall CSoldierRole::WarriorTaskWalkOneStep(CSoldierRole *this, CSettler *a2)
int  CSoldierRole::WarriorTaskWalkOneStep(class IMovingEntity & a2) {
  
  int v4; // [esp+8h] [ebp-4h]

  v4 = CSettler::Walk(a2);
  CSoldierRole::EvaluateWalkAndRegister((CSoldierRole *)((char *)this - 48), a2, v4);
  return v4;
}


// address=[0x158ed40]
// Decompiled from int __thiscall CSoldierRole::WarriorTaskAttack(_DWORD *this, IEntity *a2, unsigned int a3, int a4)
void  CSoldierRole::WarriorTaskAttack(class IMovingEntity & a2, int a3, enum T_WARRIOR_ATTACK a4) {
  
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
  IEntity *v37; // [esp+1Ch] [ebp-3Ch]
  int v38; // [esp+20h] [ebp-38h]
  int v39; // [esp+24h] [ebp-34h]
  int v40; // [esp+28h] [ebp-30h]
  int v41; // [esp+2Ch] [ebp-2Ch]
  int v42; // [esp+30h] [ebp-28h]
  int v43; // [esp+34h] [ebp-24h]
  int v44; // [esp+38h] [ebp-20h]
  IEntity *v45; // [esp+3Ch] [ebp-1Ch]
  void *; // [esp+40h] [ebp-18h]
  int v47; // [esp+44h] [ebp-14h]
  _DWORD *v48; // [esp+48h] [ebp-10h]
  int v49; // [esp+54h] [ebp-4h]

  v48 = this;
  if ( CMapObjectMgr::GetUniqueId(a3) <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1650, "g_pMapObjectMgr->GetUniqueId(_iTargetId) > 0") == 1 )
  {
    __debugbreak();
  }
  if ( (CMapObjectMgr::GetUniqueId(a3) & 0x20000000) != 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1651, "( g_pMapObjectMgr->GetUniqueId(_iTargetId) & IEntity::UNIQUE_ID_DEAD_ENTITY_BIT ) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::FlagBits(a2, (EntityFlag)0x8000000) != 0 )
  {
    IEntity::ClearFlagBits(a2, (EntityFlag)0x8000000);
  }
  v45 = a2;
  v47 = 1;
  if ( a4 == 1 )
  {
    v37 = CMapObjectMgr::Entity(a3);
    v4 = IEntity::OwnerId(v37);
    v5 = CAlliances::AllianceId(v4);
    v6 = IEntity::OwnerId(a2);
    if ( v5 == CAlliances::AllianceId(v6) )
    {
      v47 = 2;
    }
  }
  v32 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(int))std::vector<unsigned short>::operator[])(v47);
  v7 = IEntity::Race(v45);
   = (void *)((void *(__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v7, v32);
  if (  == 0 )
  {
    v33 = IEntity::Race(a2);
    v8 = IEntity::Type(a2);
    if ( BBSupportDbgReportF(2, "MapObjects\\Settler\\SoldierRole.cpp", 1680, "CSoldierRole::WarriorTaskAttack(): No work list for settler type %i of race %i!", v8, v33) == 1 )
    {
      __debugbreak();
    }
  }
  v36 = ((int (__stdcall *)(_BYTE *))std::list<CEntityTask>::begin)(v34);
  v35 = v36;
  v49 = 0;
  v9 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator*(v36);
  v48[8] = v9;
  v49 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v34);
  if ( *(_WORD *)(v48[8] + 16) != 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1684, "m_pTempEntityTask->m_uEntityID == 0") == 1 )
  {
    __debugbreak();
  }
  *(_WORD *)(v48[8] + 16) = a3;
  (*(void (__thiscall **)(_DWORD *, IEntity *))(*(v48 - 12) + 40))(v48 - 12, v45);
  *(_WORD *)(v48[8] + 16) = 0;
  if ( ((int (__stdcall *)())IEntity::WarriorType)() == 3 )
  {
    if ( IEntity::Race(a2) == 3 )
    {
      v43 = (int)CLogic::Effects(g_pLogic);
      v13 = CMapObjectMgr::Entity(a3);
      v26 = IEntity::PackedXY(v13);
      v14 = IEntity::PackedXY(a2);
      return (*(int (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v43 + 24))(v43, 7, v14, v26, 15, 0, 0);
    }
    else
    {
      v44 = (int)CLogic::Effects(g_pLogic);
      v10 = CMapObjectMgr::Entity(a3);
      v25 = IEntity::PackedXY(v10);
      v11 = IEntity::PackedXY(a2);
      return (*(int (__thiscall **)(int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v44 + 24))(v44, 0, v11, v25, 15, 0, 0);
    }
  }
  else
  {
    result = ((int (__stdcall *)())IEntity::WarriorType)();
    if ( result == 4 )
    {
      if ( IEntity::Type(a2) < 41 || IEntity::Type(a2) > 43 )
      {
        if ( IEntity::Type(a2) == 61 )
        {
          v41 = (int)CLogic::Effects(g_pLogic);
          v17 = CMapObjectMgr::Entity(a3);
          v28 = IEntity::PackedXY(v17);
          v18 = IEntity::PackedXY(a2);
          return (*(int (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v41 + 24))(v41, 8, v18, v28, 15, 0, 0);
        }
        else if ( IEntity::Type(a2) == 62 )
        {
          v40 = (int)CLogic::Effects(g_pLogic);
          v19 = CMapObjectMgr::Entity(a3);
          v29 = IEntity::PackedXY(v19);
          v20 = IEntity::PackedXY(a2);
          (*(void (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v40 + 24))(v40, 8, v20, v29, 10, 0, 0);
          v39 = (int)CLogic::Effects(g_pLogic);
          v21 = CMapObjectMgr::Entity(a3);
          v30 = IEntity::PackedXY(v21);
          v22 = IEntity::PackedXY(a2);
          return (*(int (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v39 + 24))(v39, 8, v22, v30, 20, 0, 0);
        }
        else
        {
          result = IEntity::Type(a2);
          if ( result == 63 )
          {
            v38 = (int)CLogic::Effects(g_pLogic);
            v23 = CMapObjectMgr::Entity(a3);
            v31 = IEntity::PackedXY(v23);
            v24 = IEntity::PackedXY(a2);
            return (*(int (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v38 + 24))(v38, 9, v24, v31, 15, 0, 0);
          }
        }
      }
      else
      {
        v42 = (int)CLogic::Effects(g_pLogic);
        v15 = CMapObjectMgr::Entity(a3);
        v27 = IEntity::PackedXY(v15);
        v16 = IEntity::PackedXY(a2);
        return (*(int (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v42 + 24))(v42, 1, v16, v27, 15, 0, 0);
      }
    }
  }
  return result;
}


// address=[0x158f1a0]
// Decompiled from int __thiscall CSoldierRole::WarriorTaskFinished(CSoldierRole *this, struct IMovingEntity *a2)
void  CSoldierRole::WarriorTaskFinished(class IMovingEntity & a2) {
  
  ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
  ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(0);
  return (*(int (__thiscall **)(char *, struct IMovingEntity *))(*((_DWORD *)this - 12) + 36))((char *)this - 48, a2);
}


// address=[0x158f1e0]
// Decompiled from unsigned int __thiscall CSoldierRole::WarriorTaskIdleWalk(CSoldierRole *this, CSettler *a2)
int  CSoldierRole::WarriorTaskIdleWalk(class IMovingEntity & a2) {
  
  int v2; // eax
  int v5; // [esp+4h] [ebp-10h]
  unsigned int v6; // [esp+8h] [ebp-Ch]
  struct CWalking *v7; // [esp+Ch] [ebp-8h]

  ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(0);
  v7 = IMovingEntity::Walking(a2);
  v2 = IEntity::PackedXY(a2);
  v5 = v7->IdleWalk((CWalkingBase *)v7, (Y16X16 *)v2, 0);
  v6 = CSettler::WalkDir(a2, v5);
  CSoldierRole::EvaluateWalkAndRegister((CSoldierRole *)((char *)this - 48), a2, v6);
  return v6;
}


// address=[0x158f250]
// Decompiled from char __thiscall CSoldierRole::SetFree(CSoldierRole *this, struct CSettler *a2, int a3)
bool  CSoldierRole::SetFree(class CSettler * a2, int a3) {
  
  int v4; // [esp+0h] [ebp-10h]
  int v6; // [esp+8h] [ebp-8h]
  int v7; // [esp+Ch] [ebp-4h]

  v6 = ISettlerRole::HomeEntityId(this);
  v4 = IEntity::EntityId(a2);
  if ( v6 != 0 )
  {
    if ( IEntity::FlagBits(a2, ENTITY_FLAG_ATTACHED) == 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1903, "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED) != 0") == 1 )
    {
      __debugbreak();
    }
    v7 = (int)CMapObjectMgr::EntityPtr(v6);
    if ( v7 == 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1908, "pEntity != 0") == 1 )
    {
      __debugbreak();
    }
    if ( v7 != 0 )
    {
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 64))(v7, v4);
    }
    if ( ISettlerRole::HomeEntityId(this) != 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1915, "HomeEntityId() == 0") == 1 )
    {
      __debugbreak();
    }
    if ( IEntity::FlagBits(a2, ENTITY_FLAG_ATTACHED) != 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1917, "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED) == 0") == 1 )
    {
      __debugbreak();
    }
  }
  else if ( IEntity::FlagBits(a2, ENTITY_FLAG_ATTACHED) != 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1921, "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED) == 0") == 1 )
  {
    __debugbreak();
  }
  return 0;
}


// address=[0x158f390]
// Decompiled from int __thiscall CSoldierRole::PostLoadInit(CWarriorBehavior *this, IMovingEntity *a2)
void  CSoldierRole::PostLoadInit(class CSettler * a2) {
  
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
  void *v16; // [esp+1Ch] [ebp-1Ch]
  int v17; // [esp+20h] [ebp-18h]
  int v18; // [esp+24h] [ebp-14h]
  CWarriorBehavior *v19; // [esp+28h] [ebp-10h]
  int v20; // [esp+34h] [ebp-4h]

  v19 = this;
  v18 = IEntity::PackedXY(a2);
  v17 = ((int (__stdcall *)())IEntity::WorldIdx)();
  if ( v18 != 0 && CWorldManager::InWorldPackedXY(v18) && IEntity::FlagBits(a2, ENTITY_FLAG_ON_BOARD) == 0 )
  {
    v2 = CWorldManager::MapObjectId(v17);
    if ( v2 != IEntity::EntityId(a2) && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 291, "g_cWorld.MapObjectId(iSettlerWorldIdx) == _pSettler->EntityId()") == 1 )
    {
      __debugbreak();
    }
    CWarMap::AddEntity(a2);
  }
  else if ( CWorldManager::InWorldPackedXY(v18) )
  {
    v3 = CWorldManager::MapObjectId(v17);
    if ( v3 == IEntity::EntityId(a2) && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 297, "!g_cWorld.InWorldPackedXY(iSettlerPackedXY) || (g_cWorld.MapObjectId(iSettlerWorldIdx) != _pSettler->EntityId())") == 1 )
    {
      __debugbreak();
    }
  }
  v9 = IEntity::Type(a2);
  v4 = IEntity::Race(a2);
  v19[4].__vftable = (CWarriorBehavior_vtbl *)CSettlerMgr::GetSettlerInfo(v4, v9);
  if ( std::list<CEntityTask>::size(&v19[3].m_sWarriorBehaviorData.m_iDestinationXYOrId) != 0 )
  {
    IMovingEntity::SetToDoList(a2, (DWORD)&v19[3].m_sWarriorBehaviorData.m_iDestinationXYOrId);
  }
  ((void (__cdecl *)(_DWORD))IMovingEntity::ResetToDoList)(v12);
  while ( LOBYTE(v19->m_sWarriorBehaviorData.m_iDestinationXYOrId) != 0 )
  {
    IMovingEntity::IncToDoListIter(a2);
    --LOBYTE(v19->m_sWarriorBehaviorData.m_iDestinationXYOrId);
  }
  if ( LOBYTE(v19[3].__vftable) != 0 )
  {
    v10 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(int))std::vector<unsigned short>::operator[])(1);
    v5 = IEntity::Race(a2);
    v16 = (void *)((void *(__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v5, v10);
    v15 = ((int (__stdcall *)(_BYTE *))std::list<CEntityTask>::begin)(v13);
    v14 = v15;
    v20 = 0;
    v6 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator*(v15);
    *(_DWORD *)&v19[3].m_sWarriorBehaviorData.m_uState = v6;
    v20 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v13);
  }
  else
  {
    *(_DWORD *)&v19[3].m_sWarriorBehaviorData.m_uState = 0;
  }
  v11 = CWarriorBehavior::GetWarriorBehaviorData(v19 + 2)->m_iFlags;
  WarriorBehaviorData = CWarriorBehavior::GetWarriorBehaviorData(v19 + 2);
  ((void (__thiscall *)(CWarriorBehavior_vtbl **, IMovingEntity *, int, int))v19[2].WarriorInit)(&v19[2].__vftable, a2, WarriorBehaviorData->m_iDestinationXYOrId, v11);
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
  CSettler *v6; // [esp+30h] [ebp-20h]
  std::_Iterator_base12 *v7; // [esp+34h] [ebp-1Ch]
  std::_Iterator_base12 *v8; // [esp+38h] [ebp-18h]
  CSoldierRole *v9; // [esp+3Ch] [ebp-14h]
  char v10; // [esp+41h] [ebp-Fh]
  char v11; // [esp+42h] [ebp-Eh]
  char v12; // [esp+43h] [ebp-Dh]
  int v13; // [esp+4Ch] [ebp-4h]

  v9 = this;
  v12 = 0;
  v6 = CSettlerMgr::operator[](this->m_uAttachedSettlerId);
  ((void (__stdcall *)(_BYTE *))std::list<CEntityTask>::begin)(v3);
  v13 = 0;
  while ( 1 )
  {
    v8 = (std::_Iterator_base12 *)((std::_Iterator_base12 *(__stdcall *)(_BYTE *))std::list<CEntityTask>::end)(v2);
    v7 = v8;
    LOBYTE(v13) = 1;
    v11 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=(v8);
    LOBYTE(v13) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v2);
    if ( v11 == 0 )
    {
      break;
    }
    ActualIter = (std::_Iterator_base12 *)IMovingEntity::GetActualIter(v6, (int)v1);
    v4 = ActualIter;
    LOBYTE(v13) = 2;
    v10 = ((int (__stdcall *)(std::_Iterator_base12 *))std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator==)(ActualIter);
    LOBYTE(v13) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v1);
    if ( v10 != 0 )
    {
      v12 = 1;
    }
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v3);
  }
  v13 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v3);
  if ( std::list<CEntityTask>::size(&v9->m_vTasks) != 0 )
  {
    if ( v12 != 0 )
    {
      OutputDebugStringA("CSoldierRole found\n");
    }
    else
    {
      OutputDebugStringA("CSoldierRole not found\n");
    }
  }
}


// address=[0x158f700]
// Decompiled from char *__thiscall CSoldierRole::GetWarriorBehavior(CSoldierRole *this)
class CWarriorBehavior *  CSoldierRole::GetWarriorBehavior(void) {
  
  if ( this )
  {
    return (char *)this + 48;
  }
  else
  {
    return 0;
  }
}


// address=[0x158f730]
// Decompiled from int __thiscall CSoldierRole::GetKindOfSelection(CSoldierRole *this, struct CSettler *a2)
int  CSoldierRole::GetKindOfSelection(class CSettler * a2)const {
  
  int v3; // [esp+8h] [ebp-4h]

  switch ( IEntity::Type(a2) )
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
 CSoldierRole::CSoldierRole(std::istream & a2) {
  
  struct CWarriorBehavior::SWarriorBehaviorData *WarriorBehaviorData; // eax
  struct CWarriorBehavior::SWarriorBehaviorData *v3; // eax
  char v4; // al
  struct CWarriorBehavior::SWarriorBehaviorData *v5; // eax
  struct CWarriorBehavior::SWarriorBehaviorData *v6; // eax
  struct CEntityTask *v8; // [esp+4h] [ebp-34h]
  unsigned int v9; // [esp+8h] [ebp-30h] BYREF
  struct CEntityTask *v10; // [esp+Ch] [ebp-2Ch]
  unsigned int v11; // [esp+10h] [ebp-28h] BYREF
  unsigned int v12; // [esp+14h] [ebp-24h] BYREF
  int pExceptionObject; // [esp+18h] [ebp-20h] BYREF
  unsigned int v14; // [esp+1Ch] [ebp-1Ch]
  unsigned int j; // [esp+20h] [ebp-18h]
  unsigned int i; // [esp+24h] [ebp-14h]
  _DWORD *v17; // [esp+28h] [ebp-10h]
  int v18; // [esp+34h] [ebp-4h]

  v17 = this;
  ((void (__stdcall *)(int))ISelectableSettlerRole::ISelectableSettlerRole)(a2);
  v18 = 0;
  CWarriorBehavior::CWarriorBehavior((CWarriorBehavior *)v17 + 2);
  *v17 = &CSoldierRole::_vftable_;
  v17[12] = &CSoldierRole::`vftable';
  std::list<CEntityTask>::list<CEntityTask>(v17 + 21);
  LOBYTE(v18) = 1;
  v17[20] = 0;
  operator^<unsigned int>(a2, &v12);
  v14 = v12;
  if ( v12 == 1 )
  {
    WarriorBehaviorData = CWarriorBehavior::GetWarriorBehaviorData((CWarriorBehavior *)v17 + 2);
    operator^<int>((struct std::istream *)a2, &WarriorBehaviorData->m_iDestinationXYOrId);
    v3 = CWarriorBehavior::GetWarriorBehaviorData((CWarriorBehavior *)v17 + 2);
    operator^<unsigned int>(a2, (unsigned int *)&v3->m_iFlags);
    operator^<unsigned int>(a2, &v11);
    for ( i = 0;
          i < v11;
          ++i )
    {
      v10 = CEntityTask::Load((struct std::istream *)a2);
      std::list<CEntityTask>::push_back((int)v10);
    }
    operator^<unsigned char>(a2, (unsigned __int8 *)v17 + 12);
    operator^<unsigned char>(a2, (unsigned __int8 *)v17 + 72);
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
    v5 = CWarriorBehavior::GetWarriorBehaviorData((CWarriorBehavior *)v17 + 2);
    operator^<int>((struct std::istream *)a2, &v5->m_iDestinationXYOrId);
    v6 = CWarriorBehavior::GetWarriorBehaviorData((CWarriorBehavior *)v17 + 2);
    operator^<unsigned int>(a2, (unsigned int *)&v6->m_iFlags);
    operator^<unsigned int>(a2, &v9);
    for ( j = 0;
          j < v9;
          ++j )
    {
      v8 = CEntityTask::Load((struct std::istream *)a2);
      std::list<CEntityTask>::push_back((int)v8);
    }
    operator^<unsigned char>(a2, (unsigned __int8 *)v17 + 12);
    operator^<unsigned char>(a2, (unsigned __int8 *)v17 + 72);
    operator^<unsigned char>(a2, (unsigned __int8 *)v17 + 73);
    operator^<unsigned int>(a2, v17 + 19);
  }
  return v17;
}


// address=[0x158fa60]
// Decompiled from int __thiscall CSoldierRole::Store(int *this, struct std::ostream *a2)
void  CSoldierRole::Store(std::ostream & a2) {
  
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
  CSettler *v15; // [esp+4Ch] [ebp-38h]
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
  ((void (__stdcall *)(struct std::ostream *))ISelectableSettlerRole::Store)(a2);
  v20 = 2;
  operator^<unsigned int>(a2, (unsigned int *)&v20);
  WarriorBehaviorData = CWarriorBehavior::GetWarriorBehaviorData((CWarriorBehavior *)v23 + 2);
  operator^<int>(a2, &WarriorBehaviorData->m_iDestinationXYOrId);
  v3 = CWarriorBehavior::GetWarriorBehaviorData((CWarriorBehavior *)v23 + 2);
  operator^<unsigned int>(a2, (unsigned int *)&v3->m_iFlags);
  LOBYTE(v29) = 0;
  v21 = std::list<CEntityTask>::size(v23 + 21);
  operator^<unsigned int>(a2, (unsigned int *)&v21);
  ((void (__stdcall *)(_BYTE *))std::list<CEntityTask>::begin)(v12);
  v30 = 0;
  while ( 1 )
  {
    v19 = (std::_Iterator_base12 *)((std::_Iterator_base12 *(__stdcall *)(_BYTE *))std::list<CEntityTask>::end)(v10);
    v18 = v19;
    LOBYTE(v30) = 1;
    v28 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=(v19);
    LOBYTE(v30) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v10);
    if ( v28 == 0 )
    {
      break;
    }
    v22 = ((int (__thiscall *)(_BYTE *, int, int))std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator->)(v12, v6, v7);
    (*(void (__thiscall **)(int, struct std::ostream *))(*(_DWORD *)v22 + 4))(v22, a2);
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v12);
  }
  v30 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v12);
  v15 = CSettlerMgr::operator[](*((unsigned __int16 *)v23 + 9));
  if ( v21 != 0 )
  {
    ((void (__stdcall *)(_BYTE *))std::list<CEntityTask>::begin)(v11);
    v30 = 2;
    while ( 1 )
    {
      v17 = (std::_Iterator_base12 *)((std::_Iterator_base12 *(__stdcall *)(_BYTE *))std::list<CEntityTask>::end)(v9);
      v16 = v17;
      LOBYTE(v30) = 3;
      v27 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=(v17);
      LOBYTE(v30) = 2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v9);
      if ( v27 == 0 )
      {
        break;
      }
      ActualIter = (std::_Iterator_base12 *)IMovingEntity::GetActualIter(v15, (int)v8);
      v13 = ActualIter;
      LOBYTE(v30) = 4;
      v26 = ((int (__stdcall *)(std::_Iterator_base12 *))std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator==)(ActualIter);
      LOBYTE(v30) = 2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v8);
      if ( v26 != 0 )
      {
        break;
      }
      LOBYTE(v29) = v29 + 1;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v11);
    }
    v30 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v11);
  }
  v4 = (unsigned __int8)v29;
  if ( v4 >= std::list<CEntityTask>::size(v23 + 21) )
  {
    LOBYTE(v29) = 0;
  }
  operator^<unsigned char>(a2, (unsigned __int8 *)&v29);
  if ( v23[20] != 0 )
  {
    v25 = 1;
    operator^<unsigned char>(a2, (unsigned __int8 *)&v25);
  }
  else
  {
    v24 = 0;
    operator^<unsigned char>(a2, (unsigned __int8 *)&v24);
  }
  operator^<unsigned char>(a2, (unsigned __int8 *)v23 + 73);
  operator^<unsigned int>(a2, (unsigned int *)v23 + 19);
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
  CWarriorBehavior::CWarriorBehavior(&this->CWarriorBehavior);
  this->ISelectableSettlerRole::ISettlerRole::CPersistence::__vftable = (CSoldierRole_vtbl *)&CSoldierRole::_vftable_;
  this->CWarriorBehavior::__vftable = (CWarriorBehavior_vtbl *)&CSoldierRole::`vftable';
  std::list<CEntityTask>::list<CEntityTask>(&this->m_vTasks);
  this->m_iU0 = 0;
  this->m_iU3 = 0;
  this->m_iU5 = 0;
  this->m_iU2 = 0;
  this->m_iMaxNumberOfHealings = CStaticConfigVarInt::operator int(&CSoldierRole::s_iMaxNumberOfHealings);
  return this;
}


// address=[0x158fdc0]
// Decompiled from void __thiscall CSoldierRole::~CSoldierRole(CSoldierRole *this)
 CSoldierRole::~CSoldierRole(void) {
  
  this->ISelectableSettlerRole::ISettlerRole::CPersistence::__vftable = (CSoldierRole_vtbl *)&CSoldierRole::_vftable_;
  this->CWarriorBehavior::__vftable = (CWarriorBehavior_vtbl *)&CSoldierRole::`vftable';
  if ( this->m_iU3 != 0 )
  {
    this->m_iU3 = 0;
  }
  std::list<CEntityTask>::~list<CEntityTask>();
  ISelectableSettlerRole::~ISelectableSettlerRole(this);
}


// address=[0x158fe10]
// Decompiled from int __thiscall CSoldierRole::SoldierMagicIdleWalk(CSoldierRole *this, struct CSettler *a2)
void  CSoldierRole::SoldierMagicIdleWalk(class CSettler * a2) {
  
  int v2; // eax
  unsigned int v4; // [esp+0h] [ebp-1Ch]
  int v5; // [esp+4h] [ebp-18h]
  struct CWalking *v6; // [esp+Ch] [ebp-10h]
  int v7; // [esp+10h] [ebp-Ch]
  int v8; // [esp+14h] [ebp-8h]

  v8 = IEntity::Flags(a2);
  if ( ((unsigned int)dword_800000 & v8) != 0 )
  {
    ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(10);
    this->m_uSettlerWalk = 8;
    ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(8);
  }
  else
  {
    ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(0);
    if ( (v8 & 0x400000) != 0 )
    {
      v7 = 0x10000000;
    }
    else
    {
      v7 = 0;
    }
    v6 = IMovingEntity::Walking(a2);
    v2 = IEntity::PackedXY(a2);
    v5 = v6->IdleWalk((CWalkingBase *)v6, (Y16X16 *)v2, v7);
    v4 = CSettler::WalkDir(a2, v5);
    CSoldierRole::EvaluateWalkAndRegister(this, a2, v4);
  }
  return CSoldierRole::CheckToDoList();
}


// address=[0x158fed0]
// Decompiled from int __thiscall CSoldierRole::GetNextJob(CSoldierRole *this, void **a2)
void  CSoldierRole::GetNextJob(class CSettler * a2) {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-40h]
  _BYTE v4[12]; // [esp+4h] [ebp-3Ch] BYREF
  int v5; // [esp+10h] [ebp-30h]
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
  result = (unsigned __int8)IMovingEntity::GetActualTask((IMovingEntity *)a2)->m_iTask;
  if ( result == 17 )
  {
    if ( v13->m_iU3 != 0 )
    {
      v13->m_iU3 = 0;
      return ((int (__thiscall *)(CSoldierRole *, void **))v13->ISelectableSettlerRole::ISettlerRole::CPersistence::__vftable[2].j_?WarriorInit@CWarriorBehavior@@UAEXAAVIMovingEntity@@HH@Z)(v13, a2);
    }
  }
  else
  {
    v5 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator->(a2 + 22)->m_iX;
    v6 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator->(a2 + 22)->m_iY;
    IMovingEntity::IncToDoListIter(a2);
    ActualTask = (int)IMovingEntity::GetActualTask((IMovingEntity *)a2);
    if ( *(_BYTE *)(ActualTask + 4) == 17 && (*(_WORD *)(ActualTask + 10) & 1) != 0 && (unsigned int)std::list<CEntityTask>::size(a2[21]) > 2 )
    {
      v10 = ((int (__stdcall *)(_BYTE *))std::list<CEntityTask>::begin)(v4);
      v9 = v10;
      v14 = 0;
      v11 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator*(v10);
      v14 = -1;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v4);
      v7 = *(__int16 *)(v11 + 10);
      v8 = *(__int16 *)(v11 + 12);
      if ( Grid::Distance(v5, v6, v7, v8) > 3 )
      {
        ((void (__cdecl *)(_DWORD))IMovingEntity::ResetToDoList)(v3);
      }
    }
    v13->m_iU3 = 0;
    return ((int (__thiscall *)(CSoldierRole *, void **))v13->ISelectableSettlerRole::ISettlerRole::CPersistence::__vftable[2].j_?WarriorInit@CWarriorBehavior@@UAEXAAVIMovingEntity@@HH@Z)(v13, a2);
  }
  return result;
}


// address=[0x1590040]
// Decompiled from int __thiscall CSoldierRole::TakeJob(ISettlerRole *this, struct CSettler *a2)
void  CSoldierRole::TakeJob(class CSettler * a2) {
  
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
  CVehicle *v23; // [esp+Ch] [ebp-1BCh]
  unsigned __int8 *v24; // [esp+10h] [ebp-1B8h]
  int NextDestination; // [esp+14h] [ebp-1B4h]
  int v26; // [esp+18h] [ebp-1B0h]
  int *v27; // [esp+20h] [ebp-1A8h]
  char v29[408]; // [esp+2Ch] [ebp-19Ch] BYREF

  v22 = IAnimatedEntity::JobPart(a2);
  v26 = IAnimatedEntity::Frame(a2);
  if ( *((_DWORD *)this + 20) != 0 )
  {
    ISettlerRole::InitCommonTaskValues(this, a2, *((const struct CEntityTask **)this + 20));
  }
  else
  {
    v2 = (const struct CEntityTask *)std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator*(&a2->m_cCurrentToDoItemIter);
    ISettlerRole::InitCommonTaskValues(this, a2, v2);
  }
  switch ( this->m_iTask )
  {
    case 7:
    case 8:
    case 9:
      if ( this->m_iTask == 9 )
      {
        v27 = &dword_420320[229176];
      }
      else if ( this->m_iTask == 8 )
      {
        v27 = dword_200000;
      }
      else
      {
        v27 = dword_100000;
      }
      this->m_iTask = 27;
      ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(5);
      if ( v22 == IAnimatedEntity::JobPart(a2) && v26 >= 1 && v26 < this->m_uCycleFrames )
      {
        ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)(v26);
      }
      else
      {
        ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)(1);
      }
      this->m_uSettlerWalk = 0x80;
      v5 = IEntity::PackedXY(a2);
      CGroupDestinations::CGroupDestinations((CGroupDestinations *)v29, this->m_iDestinationOffsetX, this->m_iDestinationOffsetY, 1, 1, v5);
      NextDestination = CGroupDestinations::GetNextDestination((CGroupDestinations *)v29);
      this->m_iDestinationOffsetX = Y16X16::UnpackXFast(NextDestination);
      this->m_iDestinationOffsetY = Y16X16::UnpackYFast(NextDestination);
      v6 = Y16X16::PackXYFast(this->m_iDestinationOffsetX, this->m_iDestinationOffsetY);
      (**((void (__thiscall ***)(char *, struct CSettler *, int, int *))this + 12))((char *)this + 48, a2, v6, v27);
      result = CSoldierRole::CheckToDoList();
      break;
    case 0xA:
      this->m_iTask = 6;
      this->m_iTask = 27;
      ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(5);
      ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
      a2->m_iFrame = 1;
      this->m_uSettlerWalk = 1;
      v17 = IEntity::Type(a2);
      v4 = IEntity::Race(a2);
      if ( CGfxManager::GetSettlerFirstJob(v4, v17) != a2->m_iJobPart )
      {
        this->m_uSettlerWalk = 1;
      }
      goto LABEL_8;
    case 0x10:
    case 0x22:
      if ( this->m_uEntityId == 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1048, "m_uEntityId > 0") == 1 )
      {
        __debugbreak();
      }
      if ( this->m_iWalkspeed <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1049, "m_iJobCounter > 0") == 1 )
      {
        __debugbreak();
      }
      ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(10);
      ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(this->m_iWalkspeed);
      v14 = CMapObjectMgr::Entity(this->m_uEntityId);
      v21 = IEntity::PackedXY(v14);
      v15 = (Y16X16 *)IEntity::PackedXY(a2);
      v16 = Y16X16::DirectionFast((int)v15, v21);
      IMovingEntity::SetDirection(a2, v16);
      result = CSoldierRole::CheckToDoList();
      break;
    case 0x11:
      this->m_iTask = 27;
      ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(0);
      ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
      (**((void (__thiscall ***)(char *, struct CSettler *, int, _DWORD))this + 12))((char *)this + 48, a2, -1, 0);
      result = CSoldierRole::CheckToDoList();
      break;
    case 0x18:
      ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(10);
      v18 = ((int (__stdcall *)())IEntity::ID)();
      LastLogicUpdateTick = IAnimatedEntity::GetLastLogicUpdateTick(a2);
      CMapObjectMgr::UnRegisterFromLogicUpdate(g_pMapObjectMgr, LastLogicUpdateTick, v18);
      CWarMap::RemoveEntity(a2);
      v8 = ((int (__stdcall *)())IEntity::WorldIdx)();
      v9 = CWorldManager::SettlerId(v8);
      if ( v9 != ((int (__stdcall *)())IEntity::ID)() && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1006, "g_cWorld.SettlerId(_pSettler->WorldIdx()) == _pSettler->ID()") == 1 )
      {
        __debugbreak();
      }
      v10 = ((int (__stdcall *)())IEntity::WorldIdx)();
      CWorldManager::SetSettlerId(v10, 0);
      if ( IEntity::FlagBits(a2, ENTITY_FLAG_Selectable) != 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1013, "_pSettler->FlagBits( ENTITY_FLAG_SELECTABLE ) == 0") == 1 )
      {
        __debugbreak();
      }
      IEntity::SetFlagBits(a2, ENTITY_FLAG_ON_BOARD);
      v24 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(this->m_uHomeEntityId);
      if ( v24 != 0 )
      {
        switch ( IEntity::ObjType((IEntity *)v24) )
        {
          case SHIP_OBJ:
          case CATAPULT_OBJ:
            v23 = CVehicleMgr::operator[](this->m_uHomeEntityId);
            v12 = ((int (__stdcall *)())IEntity::ID)();
            v23->EntityEnter(v23, v12);
            break;
          case BUILDING_OBJ:
            v19 = ((int (__stdcall *)())IEntity::ID)();
            v11 = (CBuilding *)((CBuilding *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(this->m_uHomeEntityId);
            CBuilding::SettlerEnter(v11, v19);
            break;
          case DECO_OBJ:
            v20 = ((int (__stdcall *)())IEntity::ID)();
            ManakopterPtr = (struct CManakopter *)CFlyingMgr::GetManakopterPtr((CFlyingMgr *)g_cFlyingMgr, this->m_uHomeEntityId);
            CManakopter::SettlerEnter(ManakopterPtr, v20);
            break;
          default:
            break;
        }
      }
      else
      {
        this->SetFree(this, a2, -1);
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
// Decompiled from CSettlerMgr::SSettlerInfos *__thiscall CSoldierRole::Init(int this, IEntity *a1)
void  CSoldierRole::Init(class CSettler * a2) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  CSettlerMgr::SSettlerInfos *result; // eax
  int v6; // [esp-4h] [ebp-10h]
  int v7; // [esp-4h] [ebp-10h]
  EntityFlag v8; // [esp+4h] [ebp-8h]

  v6 = IEntity::Type(a1);
  v2 = IEntity::Race(a1);
  CSettlerMgr::GetSettlerInfo(v2, v6);
  *(_WORD *)(this + 18) = IEntity::EntityId(a1);
  *(_DWORD *)(this + 80) = 0;
  IEntity::SetFlagBits(a1, ENTITY_FLAG_VulnerableMask|ENTITY_FLAG_Selectable);
  v3 = IEntity::Type(a1);
  v8 = CSettlerMgr::SettlerWarriorType(v3);
  IEntity::SetFlagBits(a1, v8);
  CWarMap::AddEntity(a1);
  (**(void (__thiscall ***)(int, IEntity *, int, _DWORD))(this + 48))(this + 48, a1, -1, 0);
  v7 = IEntity::Type(a1);
  v4 = IEntity::Race(a1);
  result = CSettlerMgr::GetSettlerInfo(v4, v7);
  *(_DWORD *)(this + 96) = result;
  *(_BYTE *)(this + 4) = 27;
  return result;
}


// address=[0x1590740]
// Decompiled from void __thiscall CSoldierRole::ConvertEventIntoGoal(int this, struct CSettler *a2, const struct CEntityEvent *a3)
void  CSoldierRole::ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3) {
  
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
  CBuilding *v14; // eax
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
  CVehicle *v71; // [esp+5Ch] [ebp-10h]
  int v72; // [esp+60h] [ebp-Ch]
  int i; // [esp+64h] [ebp-8h]

  switch ( a3->m_iEvent )
  {
    case 1:
      if ( ISettlerRole::HomeEntityId((ISettlerRole *)this) != 0 )
      {
        v17 = ISettlerRole::HomeEntityId((ISettlerRole *)this);
        CSoldierRole::ComeToWork((CSoldierRole *)this, a2, v17);
      }
      else
      {
        (*(void (__thiscall **)(int, struct CSettler *, int))(*(_DWORD *)this + 64))(this, a2, -1);
      }
      break;
    case 7:
    case 9:
      if ( IEntity::FlagBits(a2, ENTITY_FLAG_Selectable) == 0 )
      {
        IEntity::SetFlagBits(a2, ENTITY_FLAG_Selectable);
        CSettler::TakeWaitList(a2);
        (**(void (__thiscall ***)(int, struct CSettler *, int, _DWORD))(this + 48))(this + 48, a2, -1, 0);
        *(_BYTE *)(this + 4) = 27;
        v44 = a3->m_iDataA;
        v35 = IEntity::EntityId(a2);
        v3 = IEntity::OwnerId(a2);
        g_pAI->PostAIEvent(g_pAI, 21, v3, v35, v44);
      }
      break;
    case 0x11:
      if ( IEntity::FlagBits(a2, ENTITY_FLAG_Selectable) == 0 )
      {
        goto LABEL_12;
      }
      if ( a3->m_iType == 13 && !ISelectableSettlerRole::ProcessGoToPosFerry((ISelectableSettlerRole *)this, a2, a3) )
      {
        v55 = a3->m_iDataA;
        v58 = a3->m_iDataB;
        v66 = a3->m_iDataC;
        v65 = Y16X16::UnpackXFast(v66);
        v64 = Y16X16::UnpackYFast(v66);
        if ( v66 <= 0 )
        {
          goto LABEL_33;
        }
        if ( ISettlerRole::HomeEntityId((ISettlerRole *)this) != 0 )
        {
          goto LABEL_33;
        }
        if ( IEntity::FlagBits(a2, ENTITY_FLAG_Selectable) == 0 )
        {
          goto LABEL_33;
        }
        if ( CWorldManager::FlagBits(v65, v64, 1u) == 0 )
        {
          goto LABEL_33;
        }
        v7 = CWorldManager::OwnerId(v65, v64);
        if ( v7 != IEntity::OwnerId(a2) )
        {
          goto LABEL_33;
        }
        v57 = CSpiralOffsets::Last(5);
        v72 = 0;
        for ( i = 0;
              i <= v57;
              ++i )
        {
          v59 = v65 + CSpiralOffsets::DeltaX(i);
          v60 = v64 + CSpiralOffsets::DeltaY(i);
          if ( CWorldManager::InWorld(v59, v60) )
          {
            v63 = CWorldManager::MapObjectId(v59, v60);
            if ( v63 != 0 )
            {
              BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v63);
              if ( BuildingPtr != 0 && ((int (__stdcall *)())IEntity::WarriorType)() == 12 )
              {
                v8 = IEntity::OwnerId((IEntity *)BuildingPtr);
                if ( v8 == IEntity::OwnerId(a2) )
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
        if ( v72 != 0 && (v14 = (CBuilding *)((CBuilding *(__stdcall *)(int))CBuildingMgr::operator[])(v72), v56 = (CMilitaryBuildingRole *)CBuilding::Role(v14), v15 = IEntity::Type(a2), v16 = CSettlerMgr::SettlerWarriorType(v15), CMilitaryBuildingRole::HaveFreeSlots(v56, v16) != 0) )
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
      v47 = IEntity::Type(a2);
      v18 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v18, v47);
      v71 = CVehicleMgr::operator[](a3->m_iDataA);
      v19 = ((int (__stdcall *)())IEntity::ID)();
      v62 = v71->GetMeetingPointXY(v71, SETTLER_OBJ, v19);
      if ( v62 != 0 && IEntity::FlagBits(v71, (EntityFlag)&loc_3000000) != 0 )
      {
        v38 = Y16X16::UnpackYFast(v62);
        v20 = Y16X16::UnpackXFast(v62);
        CSoldierRole::NewDestinationEx((CSoldierRole *)this, a2, v20, v38, 0);
        v48 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(_DWORD))std::vector<unsigned short>::operator[])(0);
        v39 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(_DWORD))std::vector<unsigned short>::operator[])(0);
        v21 = IEntity::Race(a2);
        v22 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v21, v39);
        a2->NewToDoList(a2, v22, v48);
        v23 = IEntity::OwnerId(a2);
        if ( v23 == CPlayerManager::GetLocalPlayerId() )
        {
          v24 = ((int (__stdcall *)())IEntity::ID)();
          CInputProcessor::DeSelectEntity(&g_cInputProcessor, v24);
        }
        v25 = ((int (__stdcall *)())IEntity::ID)();
        v71->Attach(v71, v25);
        IEntity::ClearFlagBits(a2, ENTITY_FLAG_Selectable|ENTITY_FLAG_Selected);
        v26 = ((int (__stdcall *)())IEntity::ID)();
        ((void (__thiscall *)(CGroupMgr *, int))g_pGroupMgr->DetachEntityFromAllGroups)(g_pGroupMgr, v26);
        v49 = *(unsigned __int16 *)(this + 32);
        v40 = ((int (__stdcall *)())IEntity::ID)();
        v27 = IEntity::OwnerId(a2);
        g_pAI->PostAIEvent(g_pAI, 18, v27, v40, v49);
      }
      else
      {
        IEntity::SetFlagBits(a2, ENTITY_FLAG_Selectable);
        v50 = IEntity::Type(a2);
        v41 = IEntity::Type(a2);
        v28 = IEntity::Race(a2);
        v29 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v28, v41);
        a2->NewToDoList(a2, v29, v50);
      }
      break;
    case 0x19:
      v61 = a3->m_iDataB;
      v45 = Y16X16::UnpackYFast(v61);
      v36 = Y16X16::UnpackXFast(v61);
      v4 = ((int (__stdcall *)())IEntity::ID)();
      CSettlerMgr::SearchSpaceForSettler(&g_cSettlerMgr, v4, v36, v45);
      CWarMap::AddEntity(a2);
      IEntity::SetFlagBits(a2, ENTITY_FLAG_Selectable|ENTITY_FLAG_Visible);
      IEntity::ClearFlagBits(a2, ENTITY_FLAG_ON_BOARD);
      (**(void (__thiscall ***)(int, struct CSettler *, int, _DWORD))(this + 48))(this + 48, a2, -1, 0);
      *(_BYTE *)(this + 4) = 27;
      if ( IEntity::Race(a2) != 3 )
      {
        v46 = *(unsigned __int16 *)(this + 32);
        v37 = ((int (__stdcall *)())IEntity::ID)();
        v5 = IEntity::OwnerId(a2);
        g_pAI->PostAIEvent(g_pAI, 21, v5, v37, v46);
      }
      if ( IEntity::FlagBits(a2, ENTITY_FLAG_ATTACHED) != 0 )
      {
        ManakopterPtr = (struct CManakopter *)CFlyingMgr::GetManakopterPtr((CFlyingMgr *)g_cFlyingMgr, *(unsigned __int16 *)(this + 32));
        if ( ManakopterPtr != 0 )
        {
          v6 = ((int (__stdcall *)())IEntity::ID)();
          (*(void (__thiscall **)(struct CManakopter *, int))(*(_DWORD *)ManakopterPtr + 64))(ManakopterPtr, v6);
        }
      }
      break;
    case 0x1C:
      v51 = IEntity::Type(a2);
      v30 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v30, v51);
      v70 = (struct CManakopter *)CFlyingMgr::GetManakopterPtr((CFlyingMgr *)g_cFlyingMgr, a3->m_iDataA);
      if ( v70 != 0 && IEntity::FlagBits((IEntity *)v70, (EntityFlag)&s_iMsgTracer2.m_aMessages[15456]) == 0 )
      {
        v68 = IEntity::PackedXY((IEntity *)v70);
        if ( v68 != 0 )
        {
          v42 = Y16X16::UnpackYFast(v68);
          v31 = Y16X16::UnpackXFast(v68);
          CSoldierRole::NewDestinationEx((CSoldierRole *)this, a2, v31, v42, 0);
          (**(void (__thiscall ***)(int, struct CSettler *, int, int))(this + 48))(this + 48, a2, v68, 0x200000);
          v52 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(_DWORD))std::vector<unsigned short>::operator[])(0);
          v43 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(_DWORD))std::vector<unsigned short>::operator[])(0);
          v32 = IEntity::Race(a2);
          v33 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v32, v43);
          a2->NewToDoList(a2, v33, v52);
          IEntity::ClearFlagBits(a2, ENTITY_FLAG_Selectable|ENTITY_FLAG_Selected);
          v34 = ((int (__stdcall *)())IEntity::ID)();
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
      if ( BBSupportDbgReportF(1, "MapObjects\\Settler\\SoldierRole.cpp", 1453, "CSoldierRole::ConvertEventIntoGoal(): Invalid event %i!", a3->m_iEvent) == 1 )
      {
        __debugbreak();
      }
      if ( IEntity::FlagBits(a2, ENTITY_FLAG_Registered) == 0 )
      {
        CTrace::Print("ConvertEventIntoGoal SoldierRole - unknown event %u", a3->m_iEvent);
        ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
      }
      break;
  }
}


// address=[0x1590f40]
// Decompiled from int __thiscall CSoldierRole::ComeToWork(CSoldierRole *this, struct CSettler *a2, int a3)
void  CSoldierRole::ComeToWork(class CSettler * a2, int a3) {
  
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

  if ( a2 == 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1559, "_pSettler != 0") == 1 )
  {
    __debugbreak();
  }
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1560, "_iBuildingId > 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uHomeEntityId != a3 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1562, "m_uHomeEntityId == _iBuildingId") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::FlagBits(a2, ENTITY_FLAG_ATTACHED) == 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1563, "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED) != 0") == 1 )
  {
    __debugbreak();
  }
  v12 = (CMFCToolBarButton *)((CMFCToolBarButton *(__stdcall *)(int))CBuildingMgr::operator[])(a3);
  if ( IEntity::FlagBits((IEntity *)v12, (EntityFlag)&loc_3000000) == 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 1567, "rBuilding.FlagBits(ENTITY_FLAG_ALIVE_MASK) != 0") == 1 )
  {
    __debugbreak();
  }
  v3 = CBuilding::DoorPackedXY((CBuilding *)v12);
  ((void (__thiscall *)(CWarriorBehavior *, struct CSettler *, int, int))this->WarriorInit)(&this->CWarriorBehavior, a2, v3, 0x200000);
  CSoldierRole::CheckToDoList();
  v10 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(_DWORD))std::vector<unsigned short>::operator[])(0);
  v8 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(_DWORD))std::vector<unsigned short>::operator[])(0);
  v4 = IEntity::Race(a2);
  v5 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v4, v8);
  a2->NewToDoList(a2, v5, v10);
  IEntity::ClearFlagBits(a2, ENTITY_FLAG_Selectable|ENTITY_FLAG_Selected);
  result = IEntity::Type((IEntity *)v12);
  if ( result != 24 )
  {
    v11 = this->m_uHomeEntityId;
    v9 = ((int (__stdcall *)())IEntity::ID)();
    v7 = IEntity::OwnerId(a2);
    return g_pAI->PostAIEvent(g_pAI, 18, v7, v9, v11);
  }
  return result;
}


// address=[0x1591100]
// Decompiled from char __thiscall CSoldierRole::NewDestinationEx(CSoldierRole *this, CSettler *a2, int a3, int a4, __int16 a5)
bool  CSoldierRole::NewDestinationEx(class CSettler * a2, int a3, int a4, int a5) {
  
  int v5; // eax
  unsigned int v6; // eax
  __int16 v7; // ax
  CEntityTask *v8; // eax
  CEntityTask *v9; // eax
  CEntityTask *v10; // eax
  __int16 v12; // [esp-28h] [ebp-A4h]
  int v13; // [esp-4h] [ebp-80h]
  CEntityTask v14; // [esp+0h] [ebp-7Ch] BYREF
  CEntityTask v15; // [esp+18h] [ebp-64h] BYREF
  CEntityTask v16; // [esp+30h] [ebp-4Ch] BYREF
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
    if ( Grid::Distance(a3 - v21, a4 - v22) < 3 )
    {
      a5 &= ~1u;
    }
  }
  v23 = std::list<CEntityTask>::size(&v32->m_vTasks);
  if ( v23 <= 0 )
  {
    v31 = 1;
  }
  else
  {
    v20 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator*(&a2->m_cCurrentToDoItemIter);
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
      {
        std::list<CEntityTask>::pop_back();
      }
    }
    else
    {
      ((void (__cdecl *)())std::list<CEntityTask>::clear)();
      v31 = 1;
    }
  }
  v13 = IEntity::Type(a2);
  v5 = IEntity::Race(a2);
  SettlerFirstJob = CGfxManager::GetSettlerFirstJob(v5, v13);
  v6 = IEntity::Race(a2);
  SettlerJobFrameCount = CGfxManager::GetSettlerJobFrameCount(g_pGfxManager, v6, SettlerFirstJob, 2u);
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
    if ( std::list<CEntityTask>::size(&v32->m_vTasks) != 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 796, "m_vTasks.size() == 0") == 1 )
    {
      __debugbreak();
    }
    v12 = IEntity::Y(a2);
    v7 = IEntity::X(a2);
    v8 = CEntityTask::CEntityTask(&v16, (unsigned __int8)v26, (unsigned __int16)SettlerFirstJob, v7, v12, -1, (char)SettlerJobFrameCount, -1, 1, 1, 0, 0, 0, 0);
    ((void (__stdcall *)(int))std::list<CEntityTask>::push_back)((int)v8);
  }
  v9 = CEntityTask::CEntityTask(&v15, (unsigned __int8)v26, (unsigned __int16)SettlerFirstJob, (__int16)a3, (__int16)a4, -1, (char)SettlerJobFrameCount, -1, 1, 1, 0, 0, 0, 0);
  ((void (__stdcall *)(int))std::list<CEntityTask>::push_back)((int)v9);
  v10 = CEntityTask::CEntityTask(&v14, 0x11, (unsigned __int16)SettlerFirstJob, a5, 0, -1, (char)SettlerJobFrameCount, -1, 1, 1, 0, 0, 0, 0);
  ((void (__stdcall *)(int))std::list<CEntityTask>::push_back)((int)v10);
  IMovingEntity::SetToDoList(a2, (DWORD)&v32->m_vTasks);
  if ( (unsigned int)std::list<CEntityTask>::size(&v32->m_vTasks) < 2 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 850, "m_vTasks.size() >= 2") == 1 )
  {
    __debugbreak();
  }
  CSoldierRole::CheckToDoList();
  if ( v31 != 0 )
  {
    if ( std::list<CEntityTask>::size(&v32->m_vTasks) != 2 && std::list<CEntityTask>::size(&v32->m_vTasks) != 3 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 856, "(m_vTasks.size() == 2) || ((m_vTasks.size() == 3))") == 1 )
    {
      __debugbreak();
    }
    IMovingEntity::ResetToDoList(a2);
    v32->m_iU3 = 0;
    ((void (__thiscall *)(CSoldierRole *, CSettler *))v32->ISelectableSettlerRole::ISettlerRole::CPersistence::__vftable[2].j_?WarriorInit@CWarriorBehavior@@UAEXAAVIMovingEntity@@HH@Z)(v32, a2);
    CSoldierRole::CheckToDoList();
    return 1;
  }
  else
  {
    if ( (unsigned int)std::list<CEntityTask>::size(&v32->m_vTasks) <= 2 && BBSupportDbgReport(2, "MapObjects\\Settler\\SoldierRole.cpp", 870, "m_vTasks.size() > 2") == 1 )
    {
      __debugbreak();
    }
    return 0;
  }
}


// address=[0x1591450]
// Decompiled from int __thiscall CSoldierRole::EvaluateWalkAndRegister(CSoldierRole *this, struct IMovingEntity *a2, BYTE a3)
void  CSoldierRole::EvaluateWalkAndRegister(class IMovingEntity & a2, int a3) {
  
  this->m_uSettlerWalk = a3;
  if ( (a3 & 0xFu) >= 6 )
  {
    ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
  }
  else
  {
    this->m_iWalkspeed = 9;
    if ( ((int (__stdcall *)())IEntity::WarriorType)() == 2 )
    {
      this->m_iWalkspeed = 7;
    }
    ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(this->m_iWalkspeed);
    IMovingEntity::SetDistance(a2, 255);
  }
  if ( (a3 & 0x10) != 0 )
  {
    return ((int (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(0);
  }
  else
  {
    return ((int (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(5);
  }
}


// address=[0x1592280]
// Decompiled from int __thiscall CSoldierRole::SoldierWarriorLogicUpdate(CSoldierRole *this, struct CSettler *a2)
void  CSoldierRole::SoldierWarriorLogicUpdate(class CSettler * a2) {
  
  unsigned int TickCounter; // esi
  int v3; // esi
  unsigned int v4; // eax
  int v6; // [esp+8h] [ebp-8h]

  v6 = IEntity::Type(a2);
  if ( v6 >= 35 && v6 <= 37 )
  {
    TickCounter = CGameData::GetTickCounter(g_pGameData);
    if ( TickCounter >= this->m_iU2 + CStaticConfigVarInt::operator int(&CSoldierRole::s_iTicksToRegeneration) )
    {
      this->m_iU2 = CGameData::GetTickCounter(g_pGameData);
      v3 = (unsigned __int8)this->m_iMaxNumberOfHealings;
      if ( v3 < CStaticConfigVarInt::operator int(&CSoldierRole::s_iMaxNumberOfHealings) )
      {
        ++this->m_iMaxNumberOfHealings;
      }
    }
  }
  if ( ((unsigned int)&byte_C00000 & IEntity::Flags(a2)) != 0 )
  {
    CSoldierRole::SoldierMagicIdleWalk(this, a2);
  }
  else
  {
    v4 = CGameData::GetTickCounter(g_pGameData);
    CWarriorBehavior::WarriorLogicUpdate(&this->CWarriorBehavior, a2, v4, 0);
  }
  return CSoldierRole::CheckToDoList();
}


// address=[0x4158c98]
// [Decompilation failed for static class CStaticConfigVarInt CSoldierRole::s_iMaxNumberOfHealings]

// address=[0x4158ca4]
// [Decompilation failed for static class CStaticConfigVarInt CSoldierRole::s_iTicksToRegeneration]

