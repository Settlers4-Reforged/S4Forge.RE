#include "CShamanRole.h"

// Definitions for class CShamanRole

// address=[0x130f0f0]
// Decompiled from bool __thiscall CShamanRole::IsManaPoolEmpty(CShamanRole *this)

bool  CShamanRole::IsManaPoolEmpty(void) {
  
  return *((_DWORD *)this + 27) <= 0;
}


// address=[0x1401d00]
// Decompiled from int __cdecl CShamanRole::New(int a1)

static class CPersistence * __cdecl CShamanRole::New(std::istream &) {
  
  if ( operator new(0x74u) )
    return CShamanRole::CShamanRole(a1);
  else
    return 0;
}


// address=[0x1588880]
// Decompiled from int __cdecl CShamanRole::Load(int a1)

static class CShamanRole * __cdecl CShamanRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CShamanRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x158be00]
// Decompiled from void __thiscall CShamanRole::LogicUpdateJob(CShamanRole *this, struct CSettler *a2)

void  CShamanRole::LogicUpdateJob(class CSettler *) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  unsigned int TickCounter; // eax
  int v8; // [esp-14h] [ebp-40h]
  int v9; // [esp-10h] [ebp-3Ch]
  int v10; // [esp-Ch] [ebp-38h]
  int v11; // [esp-8h] [ebp-34h]
  int v12; // [esp-4h] [ebp-30h]
  int v13; // [esp+4h] [ebp-28h]
  int v14; // [esp+Ch] [ebp-20h]
  int v15; // [esp+10h] [ebp-1Ch] BYREF
  int v16; // [esp+14h] [ebp-18h] BYREF
  int v17; // [esp+18h] [ebp-14h]
  int v18; // [esp+1Ch] [ebp-10h]
  struct CPile *PilePtr; // [esp+20h] [ebp-Ch]
  CShamanRole *v20; // [esp+24h] [ebp-8h]
  char v21; // [esp+2Bh] [ebp-1h]

  v20 = this;
  v21 = 1;
  if ( *((_DWORD *)this + 20) )
  {
    *((_DWORD *)v20 + 20) = 0;
    (*(void (__thiscall **)(CShamanRole *, struct CSettler *))(*(_DWORD *)v20 + 40))(v20, a2);
    if ( !IEntity::FlagBits(a2, Registered) )
      IAnimatedEntity::RegisterForLogicUpdate(1);
    return;
  }
  if ( *((int *)v20 + 27) <= 0 )
  {
    if ( *((_DWORD *)v20 + 25) && CShamanRole::CheckForManakopter(v20, a2) == 2 )
      return;
  }
  else
  {
    v15 = Y16X16::UnpackXFast(*((_DWORD *)v20 + 28));
    v16 = Y16X16::UnpackYFast(*((_DWORD *)v20 + 28));
    v18 = 0;
    if ( *((_DWORD *)v20 + 28) )
    {
      v17 = CWorldManager::ObjectId(v15, v16);
      if ( v17 )
      {
        PilePtr = CPileMgr::GetPilePtr(v17);
        if ( PilePtr )
        {
          if ( (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)PilePtr + 60))(PilePtr) == 7
            || (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)PilePtr + 60))(PilePtr) == 20 )
          {
            if ( (unsigned __int8)CPile::GoodAvailable(PilePtr) )
              v18 = 7;
          }
        }
      }
      if ( !v18
        && (*(int (__thiscall **)(void *, int *, int *, int))(*(_DWORD *)off_3D7A6A8 + 12))(off_3D7A6A8, &v15, &v16, 2) )
      {
        v18 = 2;
      }
    }
    v14 = 0;
    if ( v18 )
    {
      v12 = IEntity::ID();
      v10 = Y16X16::UnpackYFast(*((_DWORD *)v20 + 28));
      v9 = Y16X16::UnpackXFast(*((_DWORD *)v20 + 28));
      v8 = v18;
      v2 = IEntity::OwnerId((unsigned __int8 *)a2);
      v14 = CMagic::CastSpell(v2, v8, v9, v10, 268435457, v12);
    }
    else
    {
      v21 = 0;
    }
    if ( v14 > 0 )
    {
      if ( v18 == 2 )
      {
        v4 = CStaticConfigVarInt::operator int(&CShamanRole::s_iManaCostRot);
        *((_DWORD *)v20 + 27) -= v4;
      }
      else if ( v18 == 7 )
      {
        v3 = CStaticConfigVarInt::operator int(&CShamanRole::s_iManaCostTeleport);
        *((_DWORD *)v20 + 27) -= v3;
      }
      (*(void (__thiscall **)(char *, struct CSettler *))(*((_DWORD *)v20 + 12) + 16))((char *)v20 + 48, a2);
      *((_DWORD *)v20 + 28) = 0;
    }
  }
  v11 = IEntity::Y(a2);
  v5 = IEntity::X(a2);
  if ( CWorldManager::FlagBits(v5, v11, 4u) )
  {
    v6 = CStaticConfigVarInt::operator int(&CShamanRole::s_iShamanManaPool);
    *((_DWORD *)v20 + 27) = v6;
  }
  if ( v21 )
    v13 = 16;
  else
    v13 = 0;
  if ( (IEntity::Flags(a2) & 0x8000) == 0 )
  {
    TickCounter = CStateGame::GetTickCounter(g_pGame);
    CWarriorBehavior::WarriorLogicUpdate((CShamanRole *)((char *)v20 + 48), a2, TickCounter, v13);
  }
}


// address=[0x158c090]
// Decompiled from _DWORD *__thiscall CShamanRole::WarriorTaskAttack(_DWORD *this, struct CSettler *a2, int a3, int a4)

void  CShamanRole::WarriorTaskAttack(class IMovingEntity &,int,enum T_WARRIOR_ATTACK) {
  
  int v4; // eax
  int v5; // eax
  _DWORD *result; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // [esp-10h] [ebp-50h]
  int v12; // [esp-8h] [ebp-48h]
  int v13; // [esp-4h] [ebp-44h]
  int v14; // [esp-4h] [ebp-44h]
  _BYTE v15[12]; // [esp+4h] [ebp-3Ch] BYREF
  int UniqueId; // [esp+10h] [ebp-30h]
  int v17; // [esp+14h] [ebp-2Ch]
  int v18; // [esp+18h] [ebp-28h]
  int v19; // [esp+1Ch] [ebp-24h]
  int v20; // [esp+20h] [ebp-20h]
  int v21; // [esp+24h] [ebp-1Ch]
  struct CSettler *v22; // [esp+28h] [ebp-18h]
  _DWORD *v23; // [esp+2Ch] [ebp-14h]
  _DWORD *v24; // [esp+30h] [ebp-10h]
  int v25; // [esp+3Ch] [ebp-4h]

  v24 = this;
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\ShamanRole.cpp", 352, "_iTargetId > 0") == 1 )
    __debugbreak();
  if ( a3 > 0xFFFF && BBSupportDbgReport(2, "MapObjects\\Settler\\ShamanRole.cpp", 353, "_iTargetId <= 0xFFFF") == 1 )
    __debugbreak();
  if ( CMapObjectMgr::GetUniqueId(a3) <= 0
    && BBSupportDbgReport(2, "MapObjects\\Settler\\ShamanRole.cpp", 355, "g_pMapObjectMgr->GetUniqueId(_iTargetId) > 0") == 1 )
  {
    __debugbreak();
  }
  if ( (CMapObjectMgr::GetUniqueId(a3) & 0x20000000) != 0
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\ShamanRole.cpp",
         356,
         "( g_pMapObjectMgr->GetUniqueId(_iTargetId) & IEntity::UNIQUE_ID_DEAD_ENTITY_BIT ) == 0") == 1 )
  {
    __debugbreak();
  }
  v24[15] -= CStaticConfigVarInt::operator int(&CShamanRole::s_iManaCostEnslave);
  v22 = a2;
  v13 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](1);
  v4 = IEntity::Race(a2);
  v19 = CEntityToDoListMgr::SettlerJobList(v4, v13);
  v18 = std::list<CEntityTask>::begin(v15);
  v17 = v18;
  v25 = 0;
  v5 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator*(v18);
  v24[8] = v5;
  v25 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v15);
  if ( *(_WORD *)(v24[8] + 16)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\ShamanRole.cpp", 371, "m_pTempEntityTask->m_uEntityID == 0") == 1 )
  {
    __debugbreak();
  }
  *(_WORD *)(v24[8] + 16) = a3;
  (*(void (__thiscall **)(_DWORD *, struct CSettler *))(*(v24 - 12) + 40))(v24 - 12, v22);
  *(_WORD *)(v24[8] + 16) = 0;
  UniqueId = CMapObjectMgr::GetUniqueId(a3);
  if ( v24[13] && (result = (_DWORD *)CShamanRole::CheckForManakopter((CShamanRole *)(v24 - 12), v22)) != 0 )
    return result;
  result = (_DWORD *)CMapObjectMgr::EntityPtr(a3);
  v23 = result;
  if ( !result )
    return result;
  result = (_DWORD *)IEntity::FlagBits(v23, (EntityFlag)&unk_4000000);
  if ( result )
    return result;
  v21 = CLogic::FutureEvents(g_pLogic);
  v14 = UniqueId;
  v12 = a3 | (v24[13] << 16);
  v7 = IEntity::EntityId((unsigned __int16 *)a2);
  result = (_DWORD *)(*(int (__thiscall **)(int, int, int, int, int, int))(*(_DWORD *)v21 + 12))(
                       v21,
                       8,
                       5,
                       v7,
                       v12,
                       v14);
  if ( !v23 )
    return result;
  v20 = CLogic::Effects((DWORD *)g_pLogic);
  v8 = IEntity::PackedXY(v23);
  v11 = Y16X16::UnpackYFast(v8);
  v9 = IEntity::PackedXY(v23);
  v10 = Y16X16::UnpackXFast(v9);
  return (_DWORD *)(*(int (__thiscall **)(int, int, int, int, int, int, _DWORD, int))(*(_DWORD *)v20 + 16))(
                     v20,
                     76,
                     84,
                     v10,
                     v11,
                     5,
                     0,
                     1);
}


// address=[0x158c340]
// Decompiled from int __thiscall CShamanRole::ConvertEventIntoGoal(int *this, CPropertySet *a2, int a3)

void  CShamanRole::ConvertEventIntoGoal(class CSettler *,class CEntityEvent *) {
  
  int v3; // eax
  int v5; // [esp-8h] [ebp-18h]
  int v6; // [esp+4h] [ebp-Ch]
  _DWORD *v7; // [esp+8h] [ebp-8h]

  v6 = *(_DWORD *)(a3 + 4);
  if ( v6 == 3 )
  {
    this[28] = *(_DWORD *)(a3 + 12);
    v5 = Y16X16::UnpackYFast(this[28]);
    v3 = Y16X16::UnpackXFast(this[28]);
    CSoldierRole::NewDestinationEx((CSoldierRole *)this, a2, v3, v5, 4);
    return IAnimatedEntity::RegisterForLogicUpdate(1);
  }
  else
  {
    if ( v6 != 28 )
      return CSoldierRole::ConvertEventIntoGoal(a2, a3);
    this[25] = *(_DWORD *)(a3 + 12);
    v7 = (_DWORD *)CMapObjectMgr::EntityPtr(this[25]);
    if ( !v7 || IEntity::FlagBits(v7, (EntityFlag)&unk_4000000) )
    {
      this[25] = 0;
      this[26] = 0;
    }
    else
    {
      this[26] = IEntity::UniqueId(v7);
    }
    this[28] = 0;
    return CSoldierRole::ConvertEventIntoGoal(a2, a3);
  }
}


// address=[0x158c430]
// Decompiled from _DWORD *__thiscall CShamanRole::CShamanRole(_DWORD *this, int a2)

 CShamanRole::CShamanRole(std::istream &) {
  
  int v3; // [esp+4h] [ebp-1Ch] BYREF
  int pExceptionObject; // [esp+8h] [ebp-18h] BYREF
  int v5; // [esp+Ch] [ebp-14h]
  _DWORD *v6; // [esp+10h] [ebp-10h]
  int v7; // [esp+1Ch] [ebp-4h]

  v6 = this;
  CSoldierRole::CSoldierRole(a2);
  v7 = 0;
  *v6 = &CShamanRole::_vftable_;
  v6[12] = &CShamanRole::`vftable';
  operator^<unsigned int>(a2, &v3);
  v5 = v3;
  if ( v3 == 1 )
    return v6;
  if ( v5 == 2 )
  {
    operator^<unsigned int>(a2, v6 + 25);
    operator^<int>(a2, (int)(v6 + 27));
    operator^<int>(a2, (int)(v6 + 28));
  }
  else
  {
    if ( v5 != 3 )
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CShamanRole");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    operator^<unsigned int>(a2, v6 + 25);
    operator^<int>(a2, (int)(v6 + 27));
    operator^<int>(a2, (int)(v6 + 28));
    operator^<unsigned int>(a2, v6 + 26);
  }
  return v6;
}


// address=[0x158c580]
// Decompiled from int __thiscall CShamanRole::Store(int *this, struct std::ostream *a2)

void  CShamanRole::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  int *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  CSoldierRole::Store(a2);
  v3 = 3;
  operator^<unsigned int>(a2, &v3);
  operator^<unsigned int>(a2, v4 + 25);
  operator^<int>((int)a2, v4 + 27);
  operator^<int>((int)a2, v4 + 28);
  return operator^<unsigned int>(a2, v4 + 26);
}


// address=[0x158ca60]
// Decompiled from int __thiscall CShamanRole::ClassID(CShamanRole *this)

unsigned long  CShamanRole::ClassID(void)const {
  
  return CShamanRole::m_iClassID;
}


// address=[0x158ca80]
// Decompiled from int __thiscall CShamanRole::GetSettlerRole(CShamanRole *this)

int  CShamanRole::GetSettlerRole(void)const {
  
  return 16;
}


// address=[0x3d8bf98]
// [Decompilation failed for static unsigned long CShamanRole::m_iClassID]

// address=[0x158c600]
// Decompiled from CShamanRole *__thiscall CShamanRole::CShamanRole(CShamanRole *this)

 CShamanRole::CShamanRole(void) {
  
  CSoldierRole::CSoldierRole(this);
  *(_DWORD *)this = &CShamanRole::_vftable_;
  *((_DWORD *)this + 12) = &CShamanRole::`vftable';
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 27) = CStaticConfigVarInt::operator int(&CShamanRole::s_iShamanManaPool);
  *((_DWORD *)this + 28) = 0;
  return this;
}


// address=[0x158c690]
// Decompiled from int __thiscall CShamanRole::CheckForManakopter(CShamanRole *this, struct CSettler *a2)

int  CShamanRole::CheckForManakopter(class CSettler *) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp-4h] [ebp-18h]
  int v8; // [esp+4h] [ebp-10h]
  int v9; // [esp+8h] [ebp-Ch]
  struct CManakopter *ManakopterPtr; // [esp+Ch] [ebp-8h]

  ManakopterPtr = CFlyingMgr::GetManakopterPtr((CFlyingMgr *)g_cFlyingMgr, *((_DWORD *)this + 25));
  if ( ManakopterPtr && IEntity::UniqueId(ManakopterPtr) == *((_DWORD *)this + 26) )
    return 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 27) = -1;
  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v9 = (*(int (__thiscall **)(void *, int))(*(_DWORD *)g_pDarkTribe + 24))(g_pDarkTribe, v2);
  if ( v9 )
  {
    v3 = CBuilding::EnsignWorldIdx(v9);
    v8 = CWorldManager::SectorId(v3);
    v7 = IEntity::Y(a2);
    v4 = IEntity::X(a2);
    if ( v8 == CWorldManager::SectorId(v4, v7) )
      return 1;
  }
  v5 = IEntity::ID();
  CMapObjectMgr::Kill(v5, 0);
  return 2;
}


// address=[0x158c9f0]
// Decompiled from void __thiscall CShamanRole::~CShamanRole(CShamanRole *this)

 CShamanRole::~CShamanRole(void) {
  
  *(_DWORD *)this = &CShamanRole::_vftable_;
  *((_DWORD *)this + 12) = &CShamanRole::`vftable';
  CSoldierRole::~CSoldierRole(this);
}


// address=[0x4158c4c]
// [Decompilation failed for static class CAIConfigInt CShamanRole::s_iManaCostRot]

// address=[0x4158c58]
// [Decompilation failed for static class CAIConfigInt CShamanRole::s_iManaCostTeleport]

// address=[0x4158c64]
// [Decompilation failed for static class CAIConfigInt CShamanRole::s_iManaCostEnslave]

// address=[0x4158c70]
// [Decompilation failed for static class CAIConfigInt CShamanRole::s_iShamanManaPool]

