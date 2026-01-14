#include "all_headers.h"

// Definitions for class CDiggerRole

// address=[0x14004a0]
// Decompiled from int __cdecl CDiggerRole::New(int a1)
static class CPersistence * __cdecl CDiggerRole::New(std::istream &) {
  
  if ( operator new(0x30u) )
    return CDiggerRole::CDiggerRole(a1);
  else
    return 0;
}


// address=[0x1568910]
// Decompiled from int __thiscall CDiggerRole::InitWalking(CDiggerRole *this, struct CSettler *a2)
class CWalking *  CDiggerRole::InitWalking(class CSettler *) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = CWalking::Create(1, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x1568950]
// Decompiled from char __thiscall CDiggerRole::LogicUpdateJob(CDiggerRole *this, struct CSettler *a2)
void  CDiggerRole::LogicUpdateJob(class CSettler *) {
  
  char result; // al
  char v3; // [esp+0h] [ebp-8h]

  result = (char)this;
  v3 = *((_BYTE *)this + 4);
  if ( v3 == 6 )
  {
    IMovingEntity::SetDistance(a2, 0);
    return (*(int (__thiscall **)(CDiggerRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
  }
  else if ( v3 == 16 )
  {
    *((_BYTE *)this + 7) = *(_BYTE *)(IMovingEntity::GetActualTask(a2) + 8);
    result = CDiggerRole::CheckDig(this, a2);
    if ( result )
      return IAnimatedEntity::RegisterForLogicUpdate(*((unsigned __int8 *)this + 7));
  }
  return result;
}


// address=[0x15689d0]
// Decompiled from int __stdcall CDiggerRole::PostLoadInit(CPropertySet *a1)
void  CDiggerRole::PostLoadInit(class CSettler *) {
  
  return CWarMap::AddEntity(a1);
}


// address=[0x15689f0]
// Decompiled from char __thiscall CDiggerRole::SetFree(CDiggerRole *this, struct CSettler *a2, int a3)
bool  CDiggerRole::SetFree(class CSettler *,int) {
  
  int v3; // eax
  int v4; // eax
  int v6; // [esp-4h] [ebp-14h]
  CBuildingSiteRole *v7; // [esp+0h] [ebp-10h]
  _DWORD *v8; // [esp+4h] [ebp-Ch]
  int v9; // [esp+8h] [ebp-8h]

  if ( *((_WORD *)this + 16) )
  {
    if ( !IEntity::FlagBits(a2, Attached)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Settler\\DiggerRole.cpp",
           460,
           "_pSettler->FlagBits( ENTITY_FLAG_ATTACHED )") == 1 )
    {
      __debugbreak();
    }
    v8 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
    v9 = CBuilding::Role(v8);
    if ( !(*(int (__thiscall **)(int))(*(_DWORD *)v9 + 112))(v9) )
    {
      v7 = (CBuildingSiteRole *)CBuilding::Role(v8);
      v3 = IEntity::ID();
      CBuildingSiteRole::BuilderLeft(v7, v3);
    }
  }
  if ( debug && DEBUG_FLAGS[dword_41520A4] )
  {
    v6 = *((unsigned __int16 *)this + 16);
    v4 = IEntity::ID();
    BBSupportTracePrintF(0, "Digger nr %u - WorkIsDone at building %u", v4, v6);
  }
  *((_BYTE *)this + 46) = 0;
  return ISettlerRole::SetFree(this, a2, a3);
}


// address=[0x1568ae0]
// Decompiled from _DWORD *__thiscall CDiggerRole::CDiggerRole(char *this, int a2)
 CDiggerRole::CDiggerRole(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  ISettlerRole::ISettlerRole(this, a2);
  v6 = 0;
  *v5 = &CDiggerRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CDiggerRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned short>(a2, v5 + 11);
  operator^<unsigned char>(a2, (char *)v5 + 46);
  v6 = -1;
  return v5;
}


// address=[0x1568bb0]
// Decompiled from int __thiscall CDiggerRole::Store(struct CPersistence *this, struct std::ostream *a2)
void  CDiggerRole::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct CPersistence *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  ISettlerRole::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<unsigned short>((int)a2, (__int16 *)v4 + 22);
  return operator^<unsigned char>(a2, (int)v4 + 46);
}


// address=[0x1569d00]
// Decompiled from int __thiscall CDiggerRole::ClassID(CDiggerRole *this)
unsigned long  CDiggerRole::ClassID(void)const {
  
  return CDiggerRole::m_iClassID;
}


// address=[0x1569d20]
// Decompiled from int __thiscall CDiggerRole::GetSettlerRole(CDiggerRole *this)
int  CDiggerRole::GetSettlerRole(void)const {
  
  return 2;
}


// address=[0x1588500]
// Decompiled from int __cdecl CDiggerRole::Load(int a1)
static class CDiggerRole * __cdecl CDiggerRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CDiggerRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8beb0]
// [Decompilation failed for static unsigned long CDiggerRole::m_iClassID]

// address=[0x1568c10]
// Decompiled from CDiggerRole *__thiscall CDiggerRole::CDiggerRole(CDiggerRole *this)
 CDiggerRole::CDiggerRole(void) {
  
  ISettlerRole::ISettlerRole((ISettlerRole *)this);
  *(_DWORD *)this = &CDiggerRole::_vftable_;
  *((_WORD *)this + 22) = 0;
  *((_BYTE *)this + 46) = 0;
  return this;
}


// address=[0x1568c40]
// Decompiled from void __thiscall CDiggerRole::~CDiggerRole(CDiggerRole *this)
 CDiggerRole::~CDiggerRole(void) {
  
  *(_DWORD *)this = &CDiggerRole::_vftable_;
  ISettlerRole::~ISettlerRole(this);
}


// address=[0x1568c60]
// Decompiled from int __thiscall CDiggerRole::GetNextJob(CDiggerRole *this, struct CSettler *a2)
void  CDiggerRole::GetNextJob(class CSettler *) {
  
  CDiggerRole *v3; // [esp+0h] [ebp-4h]

  v3 = this;
  IMovingEntity::IncToDoListIter(a2);
  if ( IMovingEntity::IsEndIter(a2) )
    IMovingEntity::ResetToDoList(v3);
  return (*(int (__thiscall **)(CDiggerRole *, struct CSettler *))(*(_DWORD *)v3 + 40))(v3, a2);
}


// address=[0x1568ca0]
// Decompiled from int __thiscall CDiggerRole::TakeJob(CDiggerRole *this, struct CSettler *a2)
void  CDiggerRole::TakeJob(class CSettler *) {
  
  const struct CEntityTask *ActualTask; // eax
  int result; // eax
  CBuilding *v4; // eax
  int v5; // eax
  int v6; // eax
  _DWORD *v7; // eax
  int v8; // [esp-4h] [ebp-2Ch]
  int v9; // [esp+0h] [ebp-28h]
  int v10; // [esp+8h] [ebp-20h]
  int v11; // [esp+Ch] [ebp-1Ch]
  int v12; // [esp+14h] [ebp-14h]
  int v13; // [esp+18h] [ebp-10h]
  int v14; // [esp+20h] [ebp-8h]
  int v15; // [esp+20h] [ebp-8h]

  ActualTask = (const struct CEntityTask *)IMovingEntity::GetActualTask(a2);
  ISettlerRole::InitCommonTaskValues(this, a2, ActualTask);
  result = *((char *)this + 4) - 7;
  switch ( *((_BYTE *)this + 4) )
  {
    case 7:
    case 0xA:
      IAnimatedEntity::SetFrame(1);
      IMovingEntity::WalkToXY(a2, *((_DWORD *)this + 6), 0);
      *((_BYTE *)this + 4) = 6;
      IMovingEntity::SetDisplacementCosts(5);
      result = (*(int (__thiscall **)(CDiggerRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
      break;
    case 0x10:
      *((_BYTE *)this + 46) = 1;
      v7 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
      v10 = CBuilding::Role(v7);
      CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
      v14 = IEntity::WorldIdx();
      v12 = CWorldManager::X(v14);
      v11 = CWorldManager::Y(v14);
      v15 = IEntity::WorldIdx();
      v13 = CWorldManager::X(v15);
      v9 = CWorldManager::Y(v15) - v11 + 15;
      *((_WORD *)this + 22) = (unsigned __int8)byte_409F9AD[30750 * IEntity::OwnerId((unsigned __int8 *)a2)
                                                          + 481
                                                          + 1025 * *(_DWORD *)(v10 + 384)
                                                          + 32 * (v13 - v12)
                                                          + v9];
      result = CDiggerRole::CheckDig(this, a2);
      if ( (_BYTE)result )
      {
        IMovingEntity::SetDisplacementCosts(10);
        result = IAnimatedEntity::RegisterForLogicUpdate(*((char *)this + 6));
      }
      break;
    case 0x11:
      IMovingEntity::SetDisplacementCosts(0);
      result = IAnimatedEntity::RegisterForLogicUpdate(1);
      break;
    case 0x18:
      IMovingEntity::SetDisplacementCosts(10);
      v8 = IEntity::ID();
      v4 = (CBuilding *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
      CBuilding::SettlerEnter(v4, v8);
      v5 = IEntity::Race(a2);
      v6 = CEntityToDoListMgr::SettlerJobList(v5, 161);
      result = (*(int (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v6, 161);
      break;
    default:
      return result;
  }
  return result;
}


// address=[0x1568ee0]
// Decompiled from int __thiscall CDiggerRole::Init(int this, CPropertySet *a2)
void  CDiggerRole::Init(class CSettler *) {
  
  int result; // eax

  if ( IEntity::FlagBits(a2, Attached)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\DiggerRole.cpp", 138, "!_pSettler->FlagBits( ENTITY_FLAG_ATTACHED )") == 1 )
  {
    __debugbreak();
  }
  if ( *(_WORD *)(this + 32)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\DiggerRole.cpp", 139, "!m_uHomeEntityId") == 1 )
  {
    __debugbreak();
  }
  CWarMap::AddEntity(a2);
  result = this;
  *(_WORD *)(this + 32) = 0;
  *(_BYTE *)(this + 46) = 0;
  return result;
}


// address=[0x1568f70]
// Decompiled from int __thiscall CDiggerRole::ConvertEventIntoGoal(CDiggerRole *this, struct CSettler *a2, struct CEntityEvent *a3)
void  CDiggerRole::ConvertEventIntoGoal(class CSettler *,class CEntityEvent *) {
  
  int v3; // eax
  int result; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // [esp-4h] [ebp-10h]
  int v11; // [esp-4h] [ebp-10h]
  int v12; // [esp-4h] [ebp-10h]
  _DWORD *v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+4h] [ebp-8h]

  v14 = *((_DWORD *)a3 + 1);
  if ( v14 == 1 )
  {
    *((_BYTE *)this + 46) = 0;
    v13 = (_DWORD *)CBuildingMgr::operator[](*((_DWORD *)a3 + 3));
    result = IEntity::FlagBits(v13, (EntityFlag)0x1000u);
    if ( result )
    {
      if ( debug && DEBUG_FLAGS[dword_41520A4] )
      {
        v11 = *((_DWORD *)a3 + 3);
        v5 = IEntity::ID();
        BBSupportTracePrintF(0, "Digger %u was orderd to buildingsite %u", v5, v11);
      }
      v6 = IEntity::PackedXY(v13);
      ISettlerRole::NewDestination(this, a2, v6, 0);
      v7 = IEntity::Race(a2);
      v8 = CEntityToDoListMgr::SettlerJobList(v7, 68);
      result = (*(int (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v8, 68);
      if ( debug && DEBUG_FLAGS[dword_41520A4] )
      {
        v12 = *((unsigned __int16 *)this + 16);
        v9 = IEntity::ID();
        return BBSupportTracePrintF(0, "Digger CONV COME_TO_WORK - Attach settler %u to building %u", v9, v12);
      }
    }
  }
  else if ( v14 == 7 || v14 == 9 )
  {
    if ( !debug )
      return (*(int (__thiscall **)(CDiggerRole *, struct CSettler *, _DWORD))(*(_DWORD *)this + 64))(
               this,
               a2,
               *((_DWORD *)a3 + 5));
    if ( !DEBUG_FLAGS[dword_41520A4] )
      return (*(int (__thiscall **)(CDiggerRole *, struct CSettler *, _DWORD))(*(_DWORD *)this + 64))(
               this,
               a2,
               *((_DWORD *)a3 + 5));
    v10 = *((unsigned __int16 *)this + 16);
    v3 = IEntity::ID();
    BBSupportTracePrintF(0, "Digger %u cancel order of building %u", v3, v10);
    return (*(int (__thiscall **)(CDiggerRole *, struct CSettler *, _DWORD))(*(_DWORD *)this + 64))(
             this,
             a2,
             *((_DWORD *)a3 + 5));
  }
  else
  {
    result = IEntity::FlagBits(a2, Registered);
    if ( !result )
    {
      if ( debug && DEBUG_FLAGS[dword_41520A4] )
        BBSupportTracePrintF(0, "ConvertEventIntoGoal DiggerRole - unknown event %u", *((_DWORD *)a3 + 1));
      return IAnimatedEntity::RegisterForLogicUpdate(1);
    }
  }
  return result;
}


// address=[0x1569130]
// Decompiled from int __thiscall CDiggerRole::SearchDig(CDiggerRole *this, struct CSettler *a2)
void  CDiggerRole::SearchDig(class CSettler *) {
  
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  void *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v9; // [esp-4h] [ebp-38h]
  int v10; // [esp+0h] [ebp-34h]
  int v11; // [esp+4h] [ebp-30h]
  int v12; // [esp+8h] [ebp-2Ch]
  int v13; // [esp+Ch] [ebp-28h]
  int v14; // [esp+10h] [ebp-24h]
  int v15; // [esp+14h] [ebp-20h]
  unsigned int v16; // [esp+18h] [ebp-1Ch]
  signed int v17; // [esp+1Ch] [ebp-18h]
  int v18; // [esp+24h] [ebp-10h]
  int v20; // [esp+2Ch] [ebp-8h]
  int v21; // [esp+30h] [ebp-4h]

  v17 = (unsigned int)(31 * (_DWORD)CGameData::Rand(g_pGameData)) >> 16;
  v16 = (unsigned int)(31 * (_DWORD)CGameData::Rand(g_pGameData)) >> 16;
  v13 = 0;
  v12 = 0;
  v20 = 0;
  v21 = 0;
  v2 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
  v15 = CBuilding::Role(v2);
  v3 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
  v11 = IEntity::X(v3);
  v4 = (void *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
  v10 = IEntity::Y(v4);
  do
  {
    ++v13;
    v17 += 13;
    if ( v17 >= 31 )
    {
      v17 -= 31;
      if ( (int)++v16 >= 31 )
        v16 = 0;
    }
    v5 = IEntity::OwnerId((unsigned __int8 *)a2);
    v14 = (unsigned __int8)byte_409F9AD[30750 * v5 + 1 + 1025 * *(_DWORD *)(v15 + 384) + 32 * v17 + v16];
    if ( byte_409F9AD[30750 * v5 + 1 + 1025 * *(_DWORD *)(v15 + 384) + 32 * v17 + v16] )
    {
      v20 = v17 + v11 - 15;
      v21 = v16 + v10 - 15;
      v18 = CWorldManager::GroundHeight(v20, v21);
      if ( v14 != v18 && !CWorldManager::FlagBits(v20, v21, 0x20u) )
      {
        if ( v14 >= v18 )
        {
          if ( CWorldManager::GroundHeight(v17 + v11 - 16, v16 + v10 - 16) != v18 - 5
            && CWorldManager::GroundHeight(v20, v16 + v10 - 16) != v18 - 5
            && CWorldManager::GroundHeight(v20, v21 + 1) != v18 - 7
            && CWorldManager::GroundHeight(v20 + 1, v21 + 1) != v18 - 7 )
          {
            v12 = 1;
          }
        }
        else if ( CWorldManager::GroundHeight(v17 + v11 - 16, v16 + v10 - 16) != v18 + 7
               && CWorldManager::GroundHeight(v20, v16 + v10 - 16) != v18 + 7
               && CWorldManager::GroundHeight(v20, v21 + 1) != v18 + 5
               && CWorldManager::GroundHeight(v20 + 1, v21 + 1) != v18 + 5 )
        {
          v12 = 1;
        }
      }
    }
  }
  while ( !v12 && v13 <= 961 );
  if ( v13 <= 961 )
  {
    CWorldManager::SetFlagBits(v20, v21, 32);
    if ( CWorldManager::FlagBits(v20, v21, 1u) )
      BBSupportTracePrintF(0, "Digger trouble %u %u", *((unsigned __int16 *)this + 16), *(_DWORD *)(v15 + 384));
    ISettlerRole::NewDestination(this, a2, v20, v21, 0);
    *((_WORD *)this + 22) = (unsigned __int8)byte_409F9AD[30750 * IEntity::OwnerId((unsigned __int8 *)a2)
                                                        + 1
                                                        + 1025 * *(_DWORD *)(v15 + 384)
                                                        + 32 * v17
                                                        + v16];
    return (*(int (__thiscall **)(CDiggerRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
  }
  else
  {
    if ( debug && DEBUG_FLAGS[dword_41520A4] )
    {
      v9 = *((unsigned __int16 *)this + 16);
      v6 = IEntity::ID();
      BBSupportTracePrintF(0, "Digger done %u at building %u", v6, v9);
    }
    if ( *(_BYTE *)(v15 + 397) != 1 )
      return (*(int (__thiscall **)(CDiggerRole *, struct CSettler *, int))(*(_DWORD *)this + 64))(this, a2, -1);
    if ( debug )
    {
      if ( DEBUG_FLAGS[dword_41520A4] )
        BBSupportTracePrintF(0, "Building digging is done %u", *((unsigned __int16 *)this + 16));
    }
    v7 = IEntity::OwnerId((unsigned __int8 *)a2);
    CBuildingSiteRole::DiggingIsReady((CBuildingSiteRole *)v15, v7);
    return (*(int (__thiscall **)(CDiggerRole *, struct CSettler *, int))(*(_DWORD *)this + 64))(this, a2, -1);
  }
}


// address=[0x1569540]
// Decompiled from char __thiscall CDiggerRole::CheckDig(CDiggerRole *this, struct CSettler *a2)
bool  CDiggerRole::CheckDig(class CSettler *) {
  
  _DWORD *v2; // eax
  _DWORD *v4; // eax
  void *v5; // eax
  int v6; // [esp+4h] [ebp-20h]
  int v7; // [esp+8h] [ebp-1Ch]
  int v8; // [esp+Ch] [ebp-18h]
  int v9; // [esp+10h] [ebp-14h]
  int v11; // [esp+18h] [ebp-Ch]
  int v12; // [esp+1Ch] [ebp-8h]
  int v13; // [esp+20h] [ebp-4h]

  v12 = IEntity::X(a2);
  v13 = IEntity::Y(a2);
  v11 = CWorldManager::GroundHeight(v12, v13);
  v8 = *((unsigned __int16 *)this + 22);
  v2 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
  v9 = CBuilding::Role(v2);
  if ( v11 == v8 || !v8 )
  {
    v4 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
    v7 = v12 + 15 - IEntity::X(v4);
    v5 = (void *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
    v6 = v13 + 15 - IEntity::Y(v5);
    byte_409F9AD[30750 * IEntity::OwnerId((unsigned __int8 *)a2) + 1 + 1025 * *(_DWORD *)(v9 + 384) + 32 * v7 + v6] = 0;
    CWorldManager::ClearFlagBits(v12, v13, 16);
    CWorldManager::ClearFlagBits(v12, v13, 32);
    CDiggerRole::SearchDig(this, a2);
    return 0;
  }
  if ( v11 > v8 )
  {
    if ( CWorldManager::GroundHeight(v12 - 1, v13 - 1) != v11 + 7
      && CWorldManager::GroundHeight(v12, v13 - 1) != v11 + 7
      && CWorldManager::GroundHeight(v12, v13 + 1) != v11 + 5
      && CWorldManager::GroundHeight(v12 + 1, v13 + 1) != v11 + 5 )
    {
      CWorldManager::DecreaseGroundHeight(v12, v13);
      IGfxEngine::UpdateWorldPosition((IGfxEngine *)g_pGfxEngine, v12, v13);
      --*(_DWORD *)(v9 + 392);
      if ( !IGfxEngine::CanChangeGround((IGfxEngine *)g_pGfxEngine, v12, v13, 28) )
        return 1;
      CWorldManager::SetGround(v12, v13, 28);
      IGfxEngine::UpdateWorldPosition((IGfxEngine *)g_pGfxEngine, v12, v13);
      return 1;
    }
    goto LABEL_19;
  }
  if ( CWorldManager::GroundHeight(v12 - 1, v13 - 1) == v11 - 5
    || CWorldManager::GroundHeight(v12, v13 - 1) == v11 - 5
    || CWorldManager::GroundHeight(v12, v13 + 1) == v11 - 7
    || CWorldManager::GroundHeight(v12 + 1, v13 + 1) == v11 - 7 )
  {
LABEL_19:
    CWorldManager::ClearFlagBits(v12, v13, 32);
    CDiggerRole::SearchDig(this, a2);
    return 0;
  }
  CWorldManager::IncreaseGroundHeight(v12, v13);
  IGfxEngine::UpdateWorldPosition((IGfxEngine *)g_pGfxEngine, v12, v13);
  --*(_DWORD *)(v9 + 392);
  if ( !IGfxEngine::CanChangeGround((IGfxEngine *)g_pGfxEngine, v12, v13, 28) )
    return 1;
  CWorldManager::SetGround(v12, v13, 28);
  IGfxEngine::UpdateWorldPosition((IGfxEngine *)g_pGfxEngine, v12, v13);
  return 1;
}


