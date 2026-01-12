#include "CCarrierRole.h"

// Definitions for class CCarrierRole

// address=[0x13fffa0]
// Decompiled from int __cdecl CCarrierRole::New(int a1)
static class CPersistence * __cdecl CCarrierRole::New(std::istream &) {
  
  if ( operator new(0x38u) )
    return CCarrierRole::CCarrierRole(a1);
  else
    return 0;
}


// address=[0x1563a30]
// Decompiled from int __thiscall CCarrierRole::InitWalking(CCarrierRole *this, struct CSettler *a2)
class CWalking *  CCarrierRole::InitWalking(class CSettler *) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = CWalking::Create(1, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x1563a70]
// Decompiled from int __thiscall CCarrierRole::LogicUpdate(CCarrierRole *this, struct CSettler *a2)
void  CCarrierRole::LogicUpdate(class CSettler *) {
  
  int result; // eax
  CRandom16 *v3; // eax
  CRandom16 *v4; // eax
  int v5; // eax
  int v6; // eax
  unsigned int v7; // [esp-4h] [ebp-Ch]

  if ( *((_BYTE *)this + 4) != 17 )
    return (*(int (__thiscall **)(CCarrierRole *, struct CSettler *))(*(_DWORD *)this + 28))(this, a2);
  ISettlerRole::LogicUpdate(this, a2);
  result = (int)this;
  if ( (*((_BYTE *)this + 5) & 8) == 0 )
    return result;
  result = IMovingEntity::GetJobPart(a2);
  if ( result == 48 )
    return result;
  result = IMovingEntity::GetJobPart(a2);
  if ( result == 49 )
    return result;
  result = (unsigned __int16)++*((_WORD *)this + 26);
  if ( result < *((unsigned __int16 *)this + 27) )
    return result;
  *((_WORD *)this + 26) = 0;
  v3 = CStateGame::Random16((CStateGame *)g_pGame);
  *((_WORD *)this + 27) = CRandom16::Rand(v3) % 0x12C + 300;
  v4 = CStateGame::Random16((CStateGame *)g_pGame);
  v7 = CRandom16::Rand(v4) % 3 + 154;
  v5 = IEntity::Race(a2);
  v6 = CEntityToDoListMgr::SettlerJobList(v5, v7);
  return (*(int (__thiscall **)(struct CSettler *, int, unsigned int))(*(_DWORD *)a2 + 112))(a2, v6, v7);
}


// address=[0x1563b90]
// Decompiled from int __thiscall CCarrierRole::LogicUpdateJob(CCarrierRole *this, struct CSettler *a2)
void  CCarrierRole::LogicUpdateJob(class CSettler *) {
  
  int v2; // ecx
  int result; // eax
  int v4; // eax
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  unsigned __int8 *v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // [esp-Ch] [ebp-38h]
  int v29; // [esp-8h] [ebp-34h]
  int v30; // [esp-4h] [ebp-30h]
  int v31; // [esp-4h] [ebp-30h]
  unsigned __int8 *v32; // [esp+4h] [ebp-28h]
  int v33; // [esp+8h] [ebp-24h]
  int v34; // [esp+Ch] [ebp-20h]
  int v35; // [esp+10h] [ebp-1Ch]
  CPile *PilePtr; // [esp+14h] [ebp-18h]
  CPile *v37; // [esp+18h] [ebp-14h]
  int v38; // [esp+1Ch] [ebp-10h]
  CPile *v39; // [esp+24h] [ebp-8h]

  v2 = *((char *)this + 4);
  result = v2 - 6;
  switch ( v2 )
  {
    case 6:
      IMovingEntity::SetDistance(a2, 0);
      (*(void (__thiscall **)(CCarrierRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
      result = IEntity::FlagBits(a2, Registered);
      if ( !result && debug )
      {
        if ( DEBUG_FLAGS[dword_4152098] )
        {
          v4 = IEntity::ID();
          result = BBSupportTracePrintF(0, "LogicUpdateJob - Go - not registered settler %u", v4);
        }
      }
      break;
    case 16:
      result = (*(int (__thiscall **)(CCarrierRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
      break;
    case 20:
      v33 = *((unsigned __int8 *)this + 7) / 2;
      *((_BYTE *)this + 6) -= v33;
      if ( *((char *)this + 6) < v33 )
      {
        result = CCarrierRole::NextSettlerType(this);
        if ( !result )
          goto LABEL_91;
      }
      else
      {
        if ( !CCarrierRole::NextSettlerType(this) || !ISettlerRole::SourcePileId(this) )
          goto LABEL_91;
        v26 = ISettlerRole::SourcePileId(this);
        PilePtr = CPileMgr::GetPilePtr(v26);
        if ( !PilePtr && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 509, "pPile != 0") == 1 )
          __debugbreak();
        *((_BYTE *)this + 44) = (*(int (__thiscall **)(CPile *))(*(_DWORD *)PilePtr + 60))(PilePtr);
        if ( !*((_BYTE *)this + 44)
          && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 511, "m_uGood > 0") == 1 )
        {
          __debugbreak();
        }
        v27 = IEntity::EntityId((unsigned __int16 *)a2);
        CPile::ChangeAmountAndDetach(PilePtr, v27);
        result = IAnimatedEntity::RegisterForLogicUpdate(v33);
      }
      break;
    case 21:
      if ( !CCarrierRole::DestinationPileId(this) )
        goto LABEL_91;
      v35 = *((unsigned __int8 *)this + 7) / 2;
      *((_BYTE *)this + 6) -= v35;
      if ( *((char *)this + 6) < v35 )
      {
        if ( debug && DEBUG_FLAGS[dword_4152094] )
        {
          v15 = IEntity::ID();
          BBSupportTracePrintF(0, "Carier Nr %u put_good", v15);
        }
        (*(void (__thiscall **)(CCarrierRole *, struct CSettler *, int))(*(_DWORD *)this + 64))(this, a2, -1);
        CCarrierRole::TryToGoHome(this, a2);
        result = IEntity::FlagBits(a2, Registered);
        if ( !result && debug && DEBUG_FLAGS[dword_4152098] )
        {
          v16 = IEntity::ID();
          result = BBSupportTracePrintF(0, "LogicUpdateJob - PutGood ready - not registered settler %u", v16);
        }
      }
      else
      {
        v11 = CCarrierRole::DestinationPileId(this);
        v39 = CPileMgr::GetPilePtr(v11);
        if ( !v39 && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 392, "pPile != 0") == 1 )
          __debugbreak();
        if ( v39 )
        {
          v12 = *((unsigned __int8 *)this + 44);
          if ( v12 != (*(int (__thiscall **)(CPile *))(*(_DWORD *)v39 + 60))(v39)
            && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 397, "m_uGood == pPile->GetGoodType()") == 1 )
          {
            __debugbreak();
          }
          v13 = IEntity::EntityId((unsigned __int16 *)a2);
          CPile::ChangeAmountAndDetach(v39, v13);
        }
        *((_BYTE *)this + 44) = 0;
        IAnimatedEntity::RegisterForLogicUpdate(v35 - 1);
        result = IEntity::FlagBits(a2, Registered);
        if ( !result && debug && DEBUG_FLAGS[dword_4152098] )
        {
          v14 = IEntity::ID();
          result = BBSupportTracePrintF(0, "LogicUpdateJob - PutGood - not registered settler %u", v14);
        }
      }
      break;
    case 22:
      v34 = *((unsigned __int8 *)this + 7) / 2;
      *((_BYTE *)this + 6) -= v34;
      if ( *((char *)this + 6) < v34 )
      {
        (*(void (__thiscall **)(CCarrierRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
        result = IEntity::FlagBits(a2, Registered);
        if ( !result && debug && DEBUG_FLAGS[dword_4152098] )
        {
          v25 = IEntity::ID();
          result = BBSupportTracePrintF(0, "LogicUpdateJob - GetGood ready - not registered settler %u", v25);
        }
      }
      else
      {
        if ( !ISettlerRole::SourcePileId(this) )
          goto LABEL_91;
        v17 = ISettlerRole::SourcePileId(this);
        v37 = CPileMgr::GetPilePtr(v17);
        if ( !v37 && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 447, "pPile != 0") == 1 )
          __debugbreak();
        *((_BYTE *)this + 44) = (*(int (__thiscall **)(CPile *))(*(_DWORD *)v37 + 60))(v37);
        if ( !*((_BYTE *)this + 44)
          && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 449, "m_uGood > 0") == 1 )
        {
          __debugbreak();
        }
        if ( debug && DEBUG_FLAGS[dword_4152094] )
        {
          v18 = ISettlerRole::SourcePileId(this);
          v32 = CPileMgr::operator[](v18);
          v19 = ISettlerRole::SourcePileId(this);
          v20 = CPileMgr::operator[](v19);
          v21 = CPile::AmountLeaving((CPile *)v20);
          v29 = (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v32 + 40))(v32, v21);
          v28 = ISettlerRole::SourcePileId(this);
          v22 = IEntity::ID();
          BBSupportTracePrintF(
            0,
            "Carrier LU GET_GOOD - Detach settler %u from srcpile %u amount before %u amountleaving before %u",
            v22,
            v28,
            v29,
            v31);
        }
        v23 = IEntity::EntityId((unsigned __int16 *)a2);
        CPile::ChangeAmountAndDetach(v37, v23);
        IAnimatedEntity::RegisterForLogicUpdate(v34);
        result = IEntity::FlagBits(a2, Registered);
        if ( !result && debug && DEBUG_FLAGS[dword_4152098] )
        {
          v24 = IEntity::ID();
          result = BBSupportTracePrintF(0, "LogicUpdateJob - GetGood - not registered settler %u", v24);
        }
      }
      break;
    case 23:
      if ( ISettlerRole::HomeEntityId(this) )
      {
        v5 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 16));
        if ( IEntity::ObjType(v5) != 4 )
        {
          v6 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 16));
          if ( IEntity::ObjType(v6) != 2
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
        if ( debug && DEBUG_FLAGS[dword_4152094] )
        {
          v7 = IEntity::ID();
          BBSupportTracePrintF(0, "Carrier nr %u load_good", v7);
        }
        if ( debug && DEBUG_FLAGS[dword_4152094] )
        {
          v30 = *((unsigned __int16 *)this + 16);
          v8 = IEntity::ID();
          BBSupportTracePrintF(0, "Carrier LU LOAD_GOOD - Detach settler %u from vehicle %u", v8, v30);
        }
        v38 = CVehicleMgr::operator[](*((unsigned __int16 *)this + 16));
        (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)v38 + 132))(v38, *((unsigned __int8 *)this + 44), 1);
        v9 = IEntity::ID();
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v38 + 64))(v38, v9);
        *((_BYTE *)this + 44) = 0;
        (*(void (__thiscall **)(CCarrierRole *, struct CSettler *, int))(*(_DWORD *)this + 64))(this, a2, -1);
        CCarrierRole::TryToGoHome(this, a2);
        result = IEntity::FlagBits(a2, Registered);
        if ( !result && debug && DEBUG_FLAGS[dword_4152098] )
        {
          v10 = IEntity::ID();
          result = BBSupportTracePrintF(0, "LogicUpdateJob - LoadGood ready - not registered settler %u", v10);
        }
      }
      else
      {
LABEL_91:
        result = (*(int (__thiscall **)(CCarrierRole *, struct CSettler *, int))(*(_DWORD *)this + 64))(this, a2, -1);
      }
      break;
    default:
      if ( debug && DEBUG_FLAGS[dword_4152094] )
        result = BBSupportTracePrintF(0, "LogicUpdateJob Carrier - unknown task %u", *((char *)this + 4));
      break;
  }
  return result;
}


// address=[0x1564340]
// Decompiled from int __thiscall CCarrierRole::UpdateJob(CCarrierRole *this, struct CSettler *a2)
void  CCarrierRole::UpdateJob(class CSettler *) {
  
  int v2; // ecx
  int result; // eax
  char v4; // [esp+8h] [ebp-1Ch]
  int v5; // [esp+Ch] [ebp-18h]
  int v6; // [esp+10h] [ebp-14h]
  int v7; // [esp+14h] [ebp-10h]
  int v8; // [esp+18h] [ebp-Ch]

  v2 = *((char *)this + 4);
  result = v2 - 20;
  switch ( v2 )
  {
    case 20:
    case 22:
    case 23:
      v8 = *((unsigned __int8 *)this + 7);
      v7 = *((unsigned __int16 *)this + 4) + IAnimatedEntity::Frame(a2);
      if ( v7 >= v8 )
      {
        if ( v8 <= 0 )
          v4 = 0;
        else
          v4 = v8 - 1;
        LOBYTE(v7) = v4;
      }
      result = IAnimatedEntity::SetFrame(v7);
      break;
    case 21:
      v6 = IAnimatedEntity::Frame(a2);
      v5 = *((unsigned __int16 *)this + 4);
      if ( v6 <= v5 )
        result = IAnimatedEntity::SetFrame(0);
      else
        result = IAnimatedEntity::SetFrame(v6 - v5);
      break;
    default:
      return result;
  }
  return result;
}


// address=[0x1564420]
// Decompiled from int __stdcall CCarrierRole::PostLoadInit(CPropertySet *a1)
void  CCarrierRole::PostLoadInit(class CSettler *) {
  
  return CWarMap::AddEntity(a1);
}


// address=[0x1564440]
// Decompiled from __int16 __thiscall CCarrierRole::SetObserverTarget(_WORD *this, int a2, __int16 a3)
void  CCarrierRole::SetObserverTarget(enum T_OBSERVER_TARGET,int) {
  
  __int16 result; // ax

  result = a2;
  switch ( a2 )
  {
    case 0:
      result = a3;
      this[16] = a3;
      break;
    case 1:
      this[23] = a3;
      break;
    case 2:
      result = (__int16)this;
      this[10] = a3;
      break;
    case 3:
      result = a3;
      this[24] = a3;
      break;
    case 4:
      this[25] = a3;
      break;
    default:
      if ( BBSupportDbgReport(
             1,
             "MapObjects\\Settler\\CarrierRole.cpp",
             1642,
             "CCarrierRole::SetObserverTarget(): Invalid target type!") == 1 )
        __debugbreak();
      result = 0;
      break;
  }
  return result;
}


// address=[0x15644e0]
// Decompiled from int __thiscall CCarrierRole::GetObserverTarget(unsigned __int16 *this, int a2)
int  CCarrierRole::GetObserverTarget(enum T_OBSERVER_TARGET) {
  
  int result; // eax

  switch ( a2 )
  {
    case 0:
      result = this[16];
      break;
    case 1:
      result = this[23];
      break;
    case 2:
      result = this[10];
      break;
    case 3:
      result = this[24];
      break;
    case 4:
      result = this[25];
      break;
    default:
      result = 0;
      break;
  }
  return result;
}


// address=[0x1564550]
// Decompiled from unsigned __int8 *__thiscall CCarrierRole::UpdateCatapultPosition(CCarrierRole *this, int a2)
void  CCarrierRole::UpdateCatapultPosition(int) {
  
  unsigned __int8 *result; // eax
  struct CSettler *v4; // [esp+4h] [ebp-4h]

  result = CSettlerMgr::GetSettlerPtr(*((unsigned __int16 *)this + 9));
  v4 = (struct CSettler *)result;
  if ( !result )
  {
    result = (unsigned __int8 *)BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1748, "pSettler!=NULL");
    if ( result == (unsigned __int8 *)1 )
      __debugbreak();
  }
  if ( v4 )
    return (unsigned __int8 *)ISettlerRole::NewDestination(this, v4, a2, 0);
  return result;
}


// address=[0x15645c0]
// Decompiled from char *__thiscall CCarrierRole::CCarrierRole(char *this, int a2)
 CCarrierRole::CCarrierRole(std::istream &) {
  
  int v3; // [esp+4h] [ebp-1Ch] BYREF
  int pExceptionObject; // [esp+8h] [ebp-18h] BYREF
  int v5; // [esp+Ch] [ebp-14h]
  char *v6; // [esp+10h] [ebp-10h]
  int v7; // [esp+1Ch] [ebp-4h]

  v6 = this;
  ISettlerRole::ISettlerRole(this, a2);
  v7 = 0;
  *(_DWORD *)v6 = &CCarrierRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  v5 = v3;
  if ( v3 == 1 )
  {
    operator^<unsigned char>(a2, v6 + 44);
    operator^<unsigned char>(a2, v6 + 45);
    operator^<unsigned short>(a2, v6 + 20);
    operator^<unsigned short>(a2, v6 + 46);
  }
  else if ( v5 == 2 )
  {
    operator^<unsigned char>(a2, v6 + 44);
    operator^<unsigned char>(a2, v6 + 45);
    operator^<unsigned short>(a2, v6 + 20);
    operator^<unsigned short>(a2, v6 + 46);
    operator^<unsigned short>(a2, v6 + 48);
    operator^<unsigned short>(a2, v6 + 50);
  }
  else
  {
    if ( v5 != 3 )
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CCarrierRole");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    operator^<unsigned char>(a2, v6 + 44);
    operator^<unsigned char>(a2, v6 + 45);
    operator^<unsigned short>(a2, v6 + 20);
    operator^<unsigned short>(a2, v6 + 46);
    operator^<unsigned short>(a2, v6 + 48);
    operator^<unsigned short>(a2, v6 + 50);
    operator^<unsigned short>(a2, v6 + 52);
    operator^<unsigned short>(a2, v6 + 54);
  }
  return v6;
}


// address=[0x15647e0]
// Decompiled from int __thiscall CCarrierRole::Store(struct CPersistence *this, struct std::ostream *a2)
void  CCarrierRole::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  __int16 *v4; // [esp+4h] [ebp-4h]

  v4 = (__int16 *)this;
  ISettlerRole::Store(this, a2);
  v3 = 3;
  operator^<unsigned int>(a2, &v3);
  operator^<unsigned char>(a2, (int)(v4 + 22));
  operator^<unsigned char>(a2, (int)v4 + 45);
  operator^<unsigned short>((int)a2, v4 + 10);
  operator^<unsigned short>((int)a2, v4 + 23);
  operator^<unsigned short>((int)a2, v4 + 24);
  operator^<unsigned short>((int)a2, v4 + 25);
  operator^<unsigned short>((int)a2, v4 + 26);
  return operator^<unsigned short>((int)a2, v4 + 27);
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
// Decompiled from int __cdecl CCarrierRole::Load(int a1)
static class CCarrierRole * __cdecl CCarrierRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CCarrierRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bea8]
// [Decompilation failed for static unsigned long CCarrierRole::m_iClassID]

// address=[0x15648b0]
// Decompiled from int __thiscall CCarrierRole::GetNextSettlerType(CCarrierRole *this)
int  CCarrierRole::GetNextSettlerType(void) {
  
  return *((unsigned __int8 *)this + 45);
}


// address=[0x15648d0]
// Decompiled from char __thiscall CCarrierRole::SetNextSettlerType(CCarrierRole *this, char a2)
bool  CCarrierRole::SetNextSettlerType(int) {
  
  *((_BYTE *)this + 45) = a2;
  return 1;
}


// address=[0x15648f0]
// Decompiled from int __thiscall CCarrierRole::ChangeToNextType(CCarrierRole *this, struct CSettler *a2, char a3, char a4)
void  CCarrierRole::ChangeToNextType(class CSettler *,bool,bool) {
  
  int v4; // eax
  int v5; // eax
  int v7; // [esp-4h] [ebp-14h]
  int SettlerType; // [esp+0h] [ebp-10h]
  _WORD *v9; // [esp+4h] [ebp-Ch]
  int v10; // [esp+8h] [ebp-8h]

  if ( !CCarrierRole::NextSettlerType(this)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1724, "NextSettlerType() != 0") == 1 )
  {
    __debugbreak();
  }
  SettlerType = CCarrierRole::NextSettlerType(this);
  v7 = IEntity::Y(a2);
  v4 = IEntity::X(a2);
  v10 = CWorldManager::EcoSectorId(v4, v7);
  v9 = (_WORD *)CEcoSectorMgr::operator[](v10);
  v5 = IEntity::EntityId((unsigned __int16 *)a2);
  CEcoSector::ResetCarrierNextSettlerTypeAndDecrementOrder(v9, v5);
  if ( CCarrierRole::NextSettlerType(this)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1733, "NextSettlerType() == 0") == 1 )
  {
    __debugbreak();
  }
  *((_BYTE *)this + 45) = 0;
  return CSettler::ChangeType(a2, SettlerType, a3, a4);
}


// address=[0x15649c0]
// Decompiled from CCarrierRole *__thiscall CCarrierRole::CCarrierRole(CCarrierRole *this)
 CCarrierRole::CCarrierRole(void) {
  
  CRandom16 *v1; // eax

  ISettlerRole::ISettlerRole(this);
  *(_DWORD *)this = &CCarrierRole::_vftable_;
  *((_BYTE *)this + 44) = 0;
  *((_BYTE *)this + 45) = 0;
  *((_WORD *)this + 23) = 0;
  *((_WORD *)this + 24) = 0;
  *((_WORD *)this + 25) = 0;
  *((_WORD *)this + 26) = 0;
  v1 = CStateGame::Random16((CStateGame *)g_pGame);
  *((_WORD *)this + 27) = CRandom16::Rand(v1) % 0x12C + 300;
  return this;
}


// address=[0x1564a80]
// Decompiled from ISettlerRole *__thiscall CCarrierRole::~CCarrierRole(CCarrierRole *this)
 CCarrierRole::~CCarrierRole(void) {
  
  *(_DWORD *)this = &CCarrierRole::_vftable_;
  return ISettlerRole::~ISettlerRole(this);
}


// address=[0x1564aa0]
// Decompiled from int __thiscall CCarrierRole::GetNextJob(CCarrierRole *this, struct CSettler *a2)
void  CCarrierRole::GetNextJob(class CSettler *) {
  
  IMovingEntity::IncToDoListIter(a2);
  if ( IMovingEntity::IsEndIter(a2) )
    return (*(int (__thiscall **)(CCarrierRole *, struct CSettler *, int))(*(_DWORD *)this + 64))(this, a2, -1);
  else
    return (*(int (__thiscall **)(CCarrierRole *, struct CSettler *))(*(_DWORD *)this + 40))(this, a2);
}


// address=[0x1564af0]
// Decompiled from char __thiscall CCarrierRole::TakeJob(ISettlerRole *this, COleCmdUI *a2)
void  CCarrierRole::TakeJob(class CSettler *) {
  
  const struct CEntityTask *ActualTask; // eax
  unsigned int v3; // eax
  void **v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  __int16 v12; // ax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  __int16 v16; // ax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v22; // [esp-4h] [ebp-C8h]
  int SettlerType; // [esp-4h] [ebp-C8h]
  _BYTE v24[24]; // [esp+4h] [ebp-C0h] BYREF
  _BYTE v25[24]; // [esp+1Ch] [ebp-A8h] BYREF
  _BYTE v26[20]; // [esp+34h] [ebp-90h] BYREF
  CEntityEvent *v27; // [esp+48h] [ebp-7Ch]
  CEntityEvent *v28; // [esp+4Ch] [ebp-78h]
  int v29; // [esp+50h] [ebp-74h]
  int v30; // [esp+54h] [ebp-70h]
  int v31; // [esp+58h] [ebp-6Ch]
  int v32; // [esp+5Ch] [ebp-68h]
  void **v33; // [esp+60h] [ebp-64h]
  int v34; // [esp+64h] [ebp-60h]
  int v35; // [esp+68h] [ebp-5Ch]
  int v36; // [esp+6Ch] [ebp-58h]
  CEntityEvent *v37; // [esp+70h] [ebp-54h]
  CEntityEvent *v38; // [esp+74h] [ebp-50h]
  int v39; // [esp+78h] [ebp-4Ch]
  int v40; // [esp+7Ch] [ebp-48h]
  int v41; // [esp+80h] [ebp-44h]
  int WorkingAreaPackedXY; // [esp+84h] [ebp-40h]
  int v43; // [esp+8Ch] [ebp-38h]
  int v44; // [esp+90h] [ebp-34h]
  int v45; // [esp+94h] [ebp-30h]
  BOOL v46; // [esp+98h] [ebp-2Ch]
  int v47; // [esp+9Ch] [ebp-28h] BYREF
  int v48; // [esp+A0h] [ebp-24h] BYREF
  void *v49; // [esp+A4h] [ebp-20h]
  bool v50; // [esp+ABh] [ebp-19h]
  int v51; // [esp+ACh] [ebp-18h]
  void **v52; // [esp+B0h] [ebp-14h]
  ISettlerRole *v53; // [esp+B4h] [ebp-10h]
  int v54; // [esp+C0h] [ebp-4h]

  v53 = this;
  v46 = IEntity::FlagBits(a2, (EntityFlag)0x100000u) != 0;
  v50 = v46;
  IEntity::ClearFlagBits(a2, (EntityFlag)0x100000u);
  ActualTask = (const struct CEntityTask *)IMovingEntity::GetActualTask(a2);
  ISettlerRole::InitCommonTaskValues(v53, a2, ActualTask);
  v51 = *((char *)v53 + 4) - 10;
  switch ( v51 )
  {
    case 0:
    case 27:
      if ( *((_BYTE *)v53 + 44) )
      {
        v16 = IAnimatedEntity::JobPart(a2);
        IAnimatedEntity::SetJobPart(a2, *((unsigned __int8 *)v53 + 44) + v16);
      }
      IAnimatedEntity::SetFrame(1);
      v35 = *((__int16 *)v53 + 7) + Y16X16::UnpackXFast(*((_DWORD *)v53 + 6));
      v36 = *((__int16 *)v53 + 8) + Y16X16::UnpackYFast(*((_DWORD *)v53 + 6));
      *((_DWORD *)v53 + 6) = Y16X16::PackXYFast(v35, v36);
      if ( *((_BYTE *)v53 + 4) == 37 )
        v43 = 0x2000;
      else
        v43 = 0;
      v34 = v43;
      IMovingEntity::WalkToXY(a2, *((_DWORD *)v53 + 6), v43);
      *((_BYTE *)v53 + 4) = 6;
      IMovingEntity::SetDisplacementCosts(5);
      LOBYTE(v4) = (*(int (__thiscall **)(ISettlerRole *, COleCmdUI *))(*(_DWORD *)v53 + 16))(v53, a2);
      return (char)v4;
    case 6:
      IMovingEntity::SetDisplacementCosts(10);
      IAnimatedEntity::SetFrame(0);
      LOBYTE(v4) = IAnimatedEntity::RegisterForLogicUpdate(*((char *)v53 + 6));
      return (char)v4;
    case 7:
      IMovingEntity::SetDisplacementCosts(0);
      v3 = CStateGame::Rand(g_pGame);
      LOBYTE(v4) = IAnimatedEntity::RegisterForLogicUpdate(v3 % 4 + 1);
      return (char)v4;
    case 8:
      if ( debug && DEBUG_FLAGS[dword_4152094] )
      {
        v8 = IEntity::ID();
        BBSupportTracePrintF(0, "Carier %u TakeJob go to source pile", v8);
      }
      if ( !ISettlerRole::SourcePileId(v53) )
        goto LABEL_27;
      v9 = ISettlerRole::SourcePileId(v53);
      v10 = CMapObjectMgr::EntityPtr(v9);
      v40 = IEntity::PackedXY(v10);
      *((_DWORD *)v53 + 7) = IEntity::PackedXY(a2);
      IMovingEntity::WalkToXY(a2, v40, 4096);
      *((_BYTE *)v53 + 4) = 6;
      IMovingEntity::SetDisplacementCosts(5);
      LOBYTE(v4) = (*(int (__thiscall **)(ISettlerRole *, COleCmdUI *))(*(_DWORD *)v53 + 16))(v53, a2);
      return (char)v4;
    case 9:
      if ( !CCarrierRole::DestinationPileId(v53) )
        goto LABEL_27;
      v11 = CCarrierRole::DestinationPileId(v53);
      if ( !CMapObjectMgr::EntityPtr(v11) )
        goto LABEL_27;
      v12 = IAnimatedEntity::JobPart(a2);
      IAnimatedEntity::SetJobPart(a2, *((unsigned __int8 *)v53 + 44) + v12);
      if ( debug && DEBUG_FLAGS[dword_4152094] )
      {
        v22 = *((unsigned __int8 *)v53 + 44);
        v13 = IEntity::ID();
        BBSupportTracePrintF(0, "Carier %u TakeJob go to dest pile good %u", v13, v22);
      }
      v14 = CCarrierRole::DestinationPileId(v53);
      v15 = CMapObjectMgr::EntityPtr(v14);
      v39 = IEntity::PackedXY(v15);
      IMovingEntity::WalkToXY(a2, v39, 4096);
      *((_BYTE *)v53 + 4) = 6;
      IMovingEntity::SetDisplacementCosts(5);
      LOBYTE(v4) = (*(int (__thiscall **)(ISettlerRole *, COleCmdUI *))(*(_DWORD *)v53 + 16))(v53, a2);
      return (char)v4;
    case 10:
      goto LABEL_16;
    case 11:
      if ( debug && DEBUG_FLAGS[dword_4152094] )
      {
        v5 = IEntity::ID();
        BBSupportTracePrintF(0, "Carier %u TakeJob put_good", v5);
      }
      IMovingEntity::SetDisplacementCosts(10);
      if ( *((_BYTE *)v53 + 7) )
        v45 = *((unsigned __int8 *)v53 + 7) - 1;
      else
        v45 = 0;
      v41 = v45;
      IAnimatedEntity::SetFrame(v45);
      LOBYTE(v4) = IAnimatedEntity::RegisterForLogicUpdate(*((char *)v53 + 6) / 2);
      return (char)v4;
    case 12:
      if ( debug && DEBUG_FLAGS[dword_4152094] )
      {
        v6 = IEntity::ID();
        BBSupportTracePrintF(0, "Carier %u TakeJob get_good", v6);
      }
LABEL_16:
      IMovingEntity::SetDisplacementCosts(10);
      LOBYTE(v4) = IAnimatedEntity::RegisterForLogicUpdate(*((char *)v53 + 6) / 2 - 1);
      return (char)v4;
    case 13:
      if ( debug && DEBUG_FLAGS[dword_4152094] )
      {
        v7 = IEntity::ID();
        BBSupportTracePrintF(0, "Carier %u TakeJob load_good", v7);
      }
      IMovingEntity::SetDisplacementCosts(10);
      LOBYTE(v4) = IAnimatedEntity::RegisterForLogicUpdate(*((char *)v53 + 6));
      return (char)v4;
    case 14:
      LOBYTE(v4) = (_BYTE)v53;
      if ( !*((_WORD *)v53 + 16) )
        return (char)v4;
      IMovingEntity::SetDisplacementCosts(10);
      IEntity::ClearFlagBits(a2, Visible);
      if ( !g_pMapObjectMgr
        && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 831, "g_pMapObjectMgr!= NULL") == 1 )
      {
        __debugbreak();
      }
      v4 = (void **)CMapObjectMgr::EntityPtr(*((unsigned __int16 *)v53 + 16));
      v52 = v4;
      if ( !v4 )
      {
        v4 = (void **)BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 833, "pEntity!= NULL");
        if ( v4 == (void **)1 )
          __debugbreak();
      }
      if ( !v52 )
        return (char)v4;
      if ( IEntity::ObjType((unsigned __int8 *)v52) == 8 )
      {
        if ( !j____RTDynamicCast(v52, 0, &IEntity__RTTI_Type_Descriptor_, &CBuilding__RTTI_Type_Descriptor_, 0)
          && BBSupportDbgReport(
               2,
               "MapObjects\\Settler\\CarrierRole.cpp",
               838,
               "dynamic_cast<CBuilding*>(pEntity)!=NULL") == 1 )
        {
          __debugbreak();
        }
        v33 = v52;
        v17 = IEntity::ID();
        CBuilding::SettlerEnter((CBuilding *)v52, v17);
      }
      v4 = (void **)IEntity::ObjType((unsigned __int8 *)v52);
      if ( v4 != (void **)4 )
        return (char)v4;
      if ( !j____RTDynamicCast(v52, 0, &IEntity__RTTI_Type_Descriptor_, &CCart__RTTI_Type_Descriptor_, 0)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 844, "dynamic_cast<CCart*>(pEntity)!=NULL") == 1 )
      {
        __debugbreak();
      }
      v18 = IEntity::ID();
      LOBYTE(v4) = (*((int (__thiscall **)(void **, int))*v52 + 32))(v52, v18);
      return (char)v4;
    case 16:
      if ( !CCarrierRole::NextSettlerType(v53) )
        goto LABEL_27;
      if ( ISettlerRole::HomeEntityId(v53)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 746, "HomeEntityId() == 0") == 1 )
      {
        __debugbreak();
      }
      LOBYTE(v4) = CCarrierRole::ChangeToNextType(v53, a2, 1, 1);
      break;
    case 28:
      if ( !CCarrierRole::NextSettlerType(v53)
        || !ISettlerRole::HomeEntityId(v53)
        || !ISettlerRole::SourcePileId(v53)
        || !CCarrierRole::SourcePileId2(v53)
        || !CCarrierRole::SourcePileId3(v53) )
      {
        goto LABEL_27;
      }
      v32 = ISettlerRole::HomeEntityId(v53);
      v31 = IEntity::EntityId((unsigned __int16 *)a2);
      v49 = (void *)CBuildingMgr::operator[](v32);
      (*(void (__thiscall **)(void *, int))(*(_DWORD *)v49 + 64))(v49, v31);
      *((_WORD *)v53 + 9) = IEntity::EntityId((unsigned __int16 *)a2);
      ISettlerRole::DetachFromPile(v53, a2, 2, 1);
      ISettlerRole::DetachFromPile(v53, a2, 3, 1);
      ISettlerRole::DetachFromPile(v53, a2, 4, 1);
      SettlerType = CCarrierRole::NextSettlerType(v53);
      v19 = IEntity::OwnerId((unsigned __int8 *)a2);
      CStatistic::AddProducedSettler((CStatistic *)&g_cStatistic, v19, SettlerType);
      CCarrierRole::ChangeToNextType(v53, a2, 1, 0);
      IAnimatedEntity::EventQueueEmpty(a2);
      if ( (_BYTE)v4 )
      {
        WorkingAreaPackedXY = CBuilding::GetWorkingAreaPackedXY(v49);
        v47 = Y16X16::UnpackXFast(WorkingAreaPackedXY);
        v48 = Y16X16::UnpackYFast(WorkingAreaPackedXY);
        v20 = IEntity::WorldIdx();
        v30 = ITiling::SectorId(v20);
        CSectorSpiralWalk::CSectorSpiralWalk((CSectorSpiralWalk *)v26, v47, v48, 15, v30);
        LOBYTE(v4) = CSectorSpiralWalk::NextXY((CSectorSpiralWalk *)v26, &v47, &v48);
        if ( (_BYTE)v4 )
        {
          v29 = Y16X16::PackXYFast(v47, v48);
          v28 = CEntityEvent::CEntityEvent((CEntityEvent *)v24, 0x11u, 13, 0, v29, 0);
          v27 = v28;
          v54 = 1;
          (*(void (__thiscall **)(COleCmdUI *, CEntityEvent *))(*(_DWORD *)a2 + 80))(a2, v28);
          v54 = -1;
          LOBYTE(v4) = CEntityEvent::~CEntityEvent(v24);
        }
      }
      break;
    case 29:
      if ( CCarrierRole::NextSettlerType(v53) && ISettlerRole::HomeEntityId(v53) )
      {
        v44 = ISettlerRole::HomeEntityId(v53);
        if ( !IEntity::FlagBits(a2, Attached)
          && BBSupportDbgReport(
               2,
               "MapObjects\\Settler\\CarrierRole.cpp",
               774,
               "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED) != 0") == 1 )
        {
          __debugbreak();
        }
        CCarrierRole::ChangeToNextType(v53, a2, 1, 0);
        if ( !IEntity::FlagBits(a2, Attached)
          && BBSupportDbgReport(
               2,
               "MapObjects\\Settler\\CarrierRole.cpp",
               780,
               "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED) != 0") == 1 )
        {
          __debugbreak();
        }
        CSettler::SetBuilding(a2, v44);
        v38 = CEntityEvent::CEntityEvent((CEntityEvent *)v25, 1u, 0, v44, 0, 0);
        v37 = v38;
        v54 = 0;
        (*(void (__thiscall **)(COleCmdUI *, CEntityEvent *))(*(_DWORD *)a2 + 80))(a2, v38);
        v54 = -1;
        LOBYTE(v4) = CEntityEvent::~CEntityEvent(v25);
      }
      else
      {
LABEL_27:
        LOBYTE(v4) = (*(int (__thiscall **)(ISettlerRole *, COleCmdUI *, int))(*(_DWORD *)v53 + 64))(v53, a2, -1);
      }
      break;
    default:
      if ( debug && DEBUG_FLAGS[dword_4152094] )
        BBSupportTracePrint(0, "Carrier TakeJob - unknown job");
      LOBYTE(v4) = IAnimatedEntity::RegisterForLogicUpdate(3);
      break;
  }
  return (char)v4;
}


// address=[0x1565510]
// Decompiled from _DWORD *__thiscall CCarrierRole::Init(int this, CPropertySet *a2)
void  CCarrierRole::Init(class CSettler *) {
  
  int v2; // eax
  _DWORD *result; // eax
  int v4; // esi
  int v5; // eax
  int v6; // [esp-4h] [ebp-14h]
  unsigned __int16 *v7; // [esp+4h] [ebp-Ch]

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 203, "_pSettler!=NULL") == 1 )
    __debugbreak();
  if ( IEntity::FlagBits(a2, Offered)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 204, "!_pSettler->FlagBits(ENTITY_FLAG_OFFERED)") == 1 )
  {
    __debugbreak();
  }
  if ( *(_WORD *)(this + 32)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 205, "!m_uHomeEntityId") == 1 )
  {
    __debugbreak();
  }
  *(_WORD *)(this + 18) = IEntity::ID();
  *(_BYTE *)(this + 44) = 0;
  *(_BYTE *)(this + 45) = 0;
  *(_WORD *)(this + 46) = 0;
  *(_WORD *)(this + 48) = 0;
  *(_WORD *)(this + 50) = 0;
  *(_WORD *)(this + 32) = 0;
  *(_WORD *)(this + 20) = 0;
  CWarMap::AddEntity(a2);
  IEntity::ClearFlagBits(a2, VulnerableMask|Selectable|Selected);
  v2 = IEntity::WorldIdx();
  result = (_DWORD *)CWorldManager::EcoSectorId(v2);
  if ( !result )
    return result;
  v7 = (unsigned __int16 *)CEcoSectorMgr::operator[]((int)result);
  v4 = CEcoSector::Owner(v7);
  result = (_DWORD *)IEntity::OwnerId((unsigned __int8 *)a2);
  if ( (_DWORD *)v4 != result )
    return result;
  v6 = IEntity::ID();
  v5 = IEntity::Type((unsigned __int16 *)a2);
  return CEcoSector::SetSettlerOffer(v7, v5, v6);
}


// address=[0x1565660]
// Decompiled from CEcoSector *__thiscall CCarrierRole::ConvertEventIntoGoal(ISettlerRole *this, CPropertySet *a2, _DWORD *a3)
void  CCarrierRole::ConvertEventIntoGoal(class CSettler *,class CEntityEvent *) {
  
  CEcoSector *result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
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
  int v35; // esi
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // [esp-8h] [ebp-88h]
  int v44; // [esp-8h] [ebp-88h]
  int v45; // [esp-8h] [ebp-88h]
  int v46; // [esp-8h] [ebp-88h]
  int v47; // [esp-8h] [ebp-88h]
  int v48; // [esp-4h] [ebp-84h]
  int v49; // [esp-4h] [ebp-84h]
  int v50; // [esp-4h] [ebp-84h]
  int v51; // [esp-4h] [ebp-84h]
  int v52; // [esp-4h] [ebp-84h]
  int v53; // [esp-4h] [ebp-84h]
  int v54; // [esp-4h] [ebp-84h]
  int v55; // [esp-4h] [ebp-84h]
  int v56; // [esp-4h] [ebp-84h]
  int v57; // [esp-4h] [ebp-84h]
  int v58; // [esp-4h] [ebp-84h]
  _BYTE v59[24]; // [esp+8h] [ebp-78h] BYREF
  int v60; // [esp+20h] [ebp-60h]
  int v61; // [esp+24h] [ebp-5Ch]
  CMFCToolBarButton *v62; // [esp+28h] [ebp-58h]
  CMFCToolBarButton *v63; // [esp+2Ch] [ebp-54h]
  CEntityEvent *v64; // [esp+30h] [ebp-50h]
  CEntityEvent *v65; // [esp+34h] [ebp-4Ch]
  int v66; // [esp+38h] [ebp-48h]
  int v67; // [esp+3Ch] [ebp-44h]
  int SettlerInfo; // [esp+40h] [ebp-40h]
  int v69; // [esp+44h] [ebp-3Ch]
  int v70; // [esp+48h] [ebp-38h]
  int v71; // [esp+4Ch] [ebp-34h]
  int v72; // [esp+50h] [ebp-30h]
  signed int v73; // [esp+54h] [ebp-2Ch]
  int v74; // [esp+58h] [ebp-28h]
  CEcoSector *v75; // [esp+5Ch] [ebp-24h]
  int v76; // [esp+60h] [ebp-20h]
  _DWORD *v77; // [esp+64h] [ebp-1Ch]
  unsigned __int8 *v78; // [esp+68h] [ebp-18h]
  int v79; // [esp+6Ch] [ebp-14h]
  ISettlerRole *v80; // [esp+70h] [ebp-10h]
  int v81; // [esp+7Ch] [ebp-4h]

  v80 = this;
  v76 = a3[1] - 1;
  switch ( v76 )
  {
    case 0:
      if ( ISettlerRole::HomeEntityId(v80) != a3[3] )
        goto LABEL_87;
      v20 = ISettlerRole::HomeEntityId(v80);
      v62 = (CMFCToolBarButton *)CBuildingMgr::operator[](v20);
      v21 = CBuilding::DoorPackedXY(v62);
      ISettlerRole::NewDestination(v80, a2, v21, 0);
      CSettler::TakeAnimList(a2, 0);
      goto LABEL_111;
    case 6:
    case 8:
      if ( *((_WORD *)v80 + 16) && a3[1] == 7 )
        return (CEcoSector *)IAnimatedEntity::RegisterForLogicUpdate(1);
      v60 = a3[3];
      v66 = a3[4];
      (*(void (__thiscall **)(ISettlerRole *, CPropertySet *, int))(*(_DWORD *)v80 + 64))(v80, a2, v66);
      goto LABEL_111;
    case 9:
      if ( ISettlerRole::SourcePileId(v80)
        && ISettlerRole::SourcePileId(v80) != a3[4]
        && BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\CarrierRole.cpp",
             1236,
             "(SourcePileId() == 0) || (SourcePileId() == _pEvent->m_iData1)") == 1 )
      {
        __debugbreak();
      }
      if ( CCarrierRole::DestinationPileId(v80)
        && CCarrierRole::DestinationPileId(v80) != a3[5]
        && BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\CarrierRole.cpp",
             1237,
             "(DestinationPileId() == 0) || (DestinationPileId() == _pEvent->m_iData2)") == 1 )
      {
        __debugbreak();
      }
      if ( ISettlerRole::SourcePileId(v80) != a3[4] && CCarrierRole::DestinationPileId(v80) != a3[5] )
        goto LABEL_87;
      v4 = IEntity::Race(a2);
      v5 = CEntityToDoListMgr::SettlerJobList(v4, 152);
      (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v5, 152);
      goto LABEL_111;
    case 10:
      if ( debug && DEBUG_FLAGS[dword_4152094] )
      {
        v6 = IEntity::ID();
        BBSupportTracePrintF(0, "Carrier %u TRANSPORT_GOOD_TO_VEHICLE", v6);
      }
      v73 = a3[5];
      v72 = a3[4];
      if ( v73 <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1265, "iVehicleID>0") == 1 )
        __debugbreak();
      if ( v72 <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1266, "iPileID>0") == 1 )
        __debugbreak();
      if ( !g_pMapObjectMgr
        && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1267, "g_pMapObjectMgr!=NULL") == 1 )
      {
        __debugbreak();
      }
      if ( !CMapObjectMgr::ValidEntityId(v73)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\CarrierRole.cpp",
             1268,
             "g_pMapObjectMgr->ValidEntityId(iVehicleID)") == 1 )
      {
        __debugbreak();
      }
      v78 = CPileMgr::operator[](v72);
      v79 = CVehicleMgr::operator[](v73);
      if ( *((_WORD *)v80 + 16) )
      {
        if ( ISettlerRole::SourcePileId(v80) > 0 )
        {
          v48 = IEntity::ID();
          v8 = IEntity::ObjType((unsigned __int8 *)a2);
          v71 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)v79 + 140))(v79, v8, v48);
          if ( v71 )
          {
            ISettlerRole::NewDestination(v80, a2, v71, 0);
            v9 = IEntity::Race(a2);
            v10 = CEntityToDoListMgr::SettlerJobList(v9, 153);
            (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v10, 153);
            if ( debug && DEBUG_FLAGS[dword_4152094] )
            {
              v49 = ISettlerRole::SourcePileId(v80);
              v11 = IEntity::ID();
              BBSupportTracePrintF(
                0,
                "Carrier CONV TRANSPORT_GOOD_TO_VEHICLE - Attach settler %u to srcpile %u",
                v11,
                v49);
            }
            if ( debug && DEBUG_FLAGS[dword_4152094] )
            {
              v50 = CCarrierRole::DestinationPileId(v80);
              v12 = IEntity::ID();
              BBSupportTracePrintF(
                0,
                "Carrier CONV TRANSPORT_GOOD_TO_VEHICLE - Attach settler %u to vehicle %u",
                v12,
                v50);
            }
            v13 = (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v78 + 60))(v78, 1);
            (*(void (__thiscall **)(int, int))(*(_DWORD *)v79 + 120))(v79, v13);
          }
          else
          {
            if ( debug && DEBUG_FLAGS[dword_4152094] )
            {
              v14 = IEntity::ID();
              BBSupportTracePrintF(0, "WARNING: Carrier %u CONV TRANSPORT_GOOD_TO_VEHICLE cancled!", v14);
            }
            (*(void (__thiscall **)(ISettlerRole *, CPropertySet *, int))(*(_DWORD *)v80 + 64))(v80, a2, -1);
            v15 = (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v78 + 60))(v78, 1);
            (*(void (__thiscall **)(int, int))(*(_DWORD *)v79 + 136))(v79, v15);
          }
LABEL_111:
          result = (CEcoSector *)IEntity::FlagBits(a2, Registered);
          if ( !result && debug )
          {
            if ( DEBUG_FLAGS[dword_4152098] )
            {
              v42 = IEntity::ID();
              return (CEcoSector *)BBSupportTracePrintF(0, "ConvertEvent- not registered settler %u", v42);
            }
          }
        }
        else
        {
          return (CEcoSector *)(*(int (__thiscall **)(ISettlerRole *, CPropertySet *, int))(*(_DWORD *)v80 + 64))(
                                 v80,
                                 a2,
                                 -1);
        }
      }
      else
      {
        (*(void (__thiscall **)(ISettlerRole *, CPropertySet *, int))(*(_DWORD *)v80 + 64))(v80, a2, -1);
        v7 = (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v78 + 60))(v78, 1);
        return (CEcoSector *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v79 + 136))(v79, v7);
      }
      return result;
    case 19:
      if ( !CCarrierRole::NextSettlerType(v80) )
        goto LABEL_87;
      CCarrierRole::ChangeToNextType(v80, a2, 1, 0);
      goto LABEL_111;
    case 20:
      if ( !CCarrierRole::NextSettlerType(v80) || !ISettlerRole::SourcePileId(v80) )
        goto LABEL_87;
      if ( ISettlerRole::HomeEntityId(v80)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1338, "HomeEntityId() == 0") == 1 )
      {
        __debugbreak();
      }
      v16 = IEntity::Race(a2);
      v17 = CEntityToDoListMgr::SettlerJobList(v16, 151);
      (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v17, 151);
      goto LABEL_111;
    case 21:
      if ( CCarrierRole::NextSettlerType(v80) != a3[3] || ISettlerRole::HomeEntityId(v80) != a3[4] )
        goto LABEL_87;
      v70 = ISettlerRole::HomeEntityId(v80);
      if ( !IEntity::FlagBits(a2, Attached)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\CarrierRole.cpp",
             1366,
             "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED) != 0") == 1 )
      {
        __debugbreak();
      }
      CCarrierRole::ChangeToNextType(v80, a2, 1, 0);
      if ( !IEntity::FlagBits(a2, Attached)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\CarrierRole.cpp",
             1372,
             "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED) != 0") == 1 )
      {
        __debugbreak();
      }
      CSettler::SetBuilding(a2, v70);
      v65 = CEntityEvent::CEntityEvent((CEntityEvent *)v59, 1u, 0, v70, 0, 0);
      v64 = v65;
      v81 = 0;
      (*(void (__thiscall **)(CPropertySet *, CEntityEvent *))(*(_DWORD *)a2 + 80))(a2, v65);
      v81 = -1;
      CEntityEvent::~CEntityEvent(v59);
      goto LABEL_111;
    case 22:
      if ( CCarrierRole::NextSettlerType(v80) != a3[3]
        || ISettlerRole::SourcePileId(v80) != a3[4]
        || ISettlerRole::HomeEntityId(v80) != a3[5] )
      {
        goto LABEL_87;
      }
      v22 = IEntity::Race(a2);
      v23 = CEntityToDoListMgr::SettlerJobList(v22, 240);
      (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v23, 240);
      goto LABEL_111;
    case 23:
      v51 = IEntity::Type((unsigned __int16 *)a2);
      v24 = IEntity::Race(a2);
      SettlerInfo = CSettlerMgr::GetSettlerInfo(v24, v51);
      v77 = (_DWORD *)CVehicleMgr::operator[](a3[3]);
      v52 = IEntity::ID();
      v25 = IEntity::ObjType((unsigned __int8 *)a2);
      v69 = (*(int (__thiscall **)(_DWORD *, int, int))(*v77 + 140))(v77, v25, v52);
      if ( v69 && IEntity::FlagBits(v77, (EntityFlag)&loc_3000000) )
      {
        ISettlerRole::NewDestination(v80, a2, v69, 0);
        IEntity::SetFlagBits(a2, (EntityFlag)0x100000u);
        v53 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v43 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v26 = IEntity::Race(a2);
        v27 = CEntityToDoListMgr::SettlerJobList(v26, v43);
        (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v27, v53);
        v28 = IEntity::ID();
        (*(void (__thiscall **)(_DWORD *, int))(*v77 + 164))(v77, v28);
        IEntity::ClearFlagBits(a2, Selectable|Selected);
        v54 = *((unsigned __int16 *)v80 + 16);
        v44 = IEntity::ID();
        v29 = IEntity::OwnerId((unsigned __int8 *)a2);
        (*(void (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(
          off_3D7A3D8,
          18,
          v29,
          v44,
          v54);
      }
      else
      {
        IEntity::SetFlagBits(a2, Selectable);
        v55 = IEntity::Type((unsigned __int16 *)a2);
        v45 = IEntity::Type((unsigned __int16 *)a2);
        v30 = IEntity::Race(a2);
        v31 = CEntityToDoListMgr::SettlerJobList(v30, v45);
        (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v31, v55);
      }
      goto LABEL_111;
    case 24:
      v74 = a3[4];
      v56 = Y16X16::UnpackYFast(v74);
      v46 = Y16X16::UnpackXFast(v74);
      v32 = IEntity::ID();
      CSettlerMgr::SearchSpaceForSettler((CSettlerMgr *)g_cSettlerMgr, v32, v46, v56);
      CWarMap::AddEntity(a2);
      IEntity::SetFlagBits(a2, Visible);
      IEntity::ClearFlagBits(a2, OnBoard);
      CSettler::TakeWaitList(a2);
      v57 = *((unsigned __int16 *)v80 + 16);
      v47 = IEntity::ID();
      v33 = IEntity::OwnerId((unsigned __int8 *)a2);
      (*(void (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(off_3D7A3D8, 21, v33, v47, v57);
      v34 = IEntity::WorldIdx();
      v67 = CWorldManager::EcoSectorId(v34);
      if ( !v67 )
        goto LABEL_99;
      result = CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, v67);
      v75 = result;
      if ( !result )
      {
        result = (CEcoSector *)BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1542, "pSector!= NULL");
        if ( result == (CEcoSector *)1 )
          __debugbreak();
      }
      if ( !v75 )
        return result;
      v35 = CEcoSector::Owner(v75);
      if ( v35 == IEntity::OwnerId((unsigned __int8 *)a2) )
      {
        v36 = IEntity::ID();
        CEcoSector::SetSettlerOfferIncDisplay(v75, 1, v36);
      }
LABEL_99:
      v58 = Y16X16::UnpackYFast(v74);
      v37 = Y16X16::UnpackXFast(v74);
      v61 = CWorldManager::OwnerId(v37, v58);
      if ( v61 != IEntity::OwnerId((unsigned __int8 *)a2) )
        CSettler::SetFree(a2);
      goto LABEL_111;
    case 25:
      if ( CCarrierRole::NextSettlerType(v80)
        && ISettlerRole::HomeEntityId(v80)
        && ISettlerRole::SourcePileId(v80)
        && CCarrierRole::SourcePileId2(v80)
        && CCarrierRole::SourcePileId3(v80) )
      {
        v18 = ISettlerRole::HomeEntityId(v80);
        v63 = (CMFCToolBarButton *)CBuildingMgr::operator[](v18);
        v19 = CBuilding::DoorPackedXY(v63);
        ISettlerRole::NewDestination(v80, a2, v19, 0);
        CSettler::TakeAnimList(a2, 3);
      }
      else
      {
LABEL_87:
        (*(void (__thiscall **)(ISettlerRole *, CPropertySet *, int))(*(_DWORD *)v80 + 64))(v80, a2, -1);
      }
      goto LABEL_111;
    case 26:
      if ( a3[3] )
      {
        v40 = IEntity::Race(a2);
        v41 = CEntityToDoListMgr::SettlerJobList(v40, 238);
        (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v41, 238);
      }
      else
      {
        v38 = IEntity::Race(a2);
        v39 = CEntityToDoListMgr::SettlerJobList(v38, 239);
        (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v39, 239);
      }
      goto LABEL_111;
    default:
      if ( !IEntity::FlagBits(a2, Registered) )
      {
        if ( debug && DEBUG_FLAGS[dword_4152094] )
          BBSupportTracePrintF(0, "ConvertEventIntoGoal CarrierRole - unknown event %u", a3[1]);
        IAnimatedEntity::RegisterForLogicUpdate(1);
      }
      goto LABEL_111;
  }
}


// address=[0x1566220]
// Decompiled from char __thiscall CCarrierRole::SetFree(CCarrierRole *this, struct CSettler *a2, int a3)
bool  CCarrierRole::SetFree(class CSettler *,int) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v8; // [esp-Ch] [ebp-2Ch]
  unsigned int v9; // [esp-8h] [ebp-28h]
  int v10; // [esp+4h] [ebp-1Ch]
  struct IEntity *v11; // [esp+8h] [ebp-18h]
  int v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+10h] [ebp-10h]
  CBuilding *v14; // [esp+14h] [ebp-Ch]
  CEcoSector *EcoSectorPtr; // [esp+18h] [ebp-8h]

  v13 = IEntity::EntityId((unsigned __int16 *)a2);
  v10 = IEntity::OwnerId((unsigned __int8 *)a2);
  CEcoSectorMgr::RemoveCarrierFromStrikeSettlers((CEcoSectorMgr *)g_cESMgr, v10, v13);
  if ( v13 <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 983, "iSettlerId > 0") == 1 )
    __debugbreak();
  if ( a3 > 0 )
  {
    v12 = a3;
  }
  else
  {
    v3 = IEntity::WorldIdx();
    v12 = CWorldManager::EcoSectorId(v3);
  }
  if ( *((_BYTE *)this + 44) )
  {
    v9 = *((unsigned __int8 *)this + 44);
    v8 = IEntity::Y(a2);
    v4 = IEntity::X(a2);
    CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v4, v8, v9, 1u);
    *((_BYTE *)this + 44) = 0;
  }
  if ( *((_BYTE *)this + 45) )
  {
    if ( IEntity::FlagBits(a2, Attached) )
    {
      if ( !*((_WORD *)this + 16)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1004, "m_uHomeEntityId > 0") == 1 )
      {
        __debugbreak();
      }
      v14 = (CBuilding *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
      v5 = IEntity::EntityId((unsigned __int16 *)a2);
      CBuilding::InhabitantFlee(v14, v5);
      if ( IEntity::FlagBits(a2, Attached) )
      {
        v6 = IEntity::EntityId((unsigned __int16 *)a2);
        (*(void (__thiscall **)(CBuilding *, int))(*(_DWORD *)v14 + 64))(v14, v6);
      }
      if ( *((_WORD *)this + 16)
        && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1015, "m_uHomeEntityId == 0") == 1 )
      {
        __debugbreak();
      }
      *((_WORD *)this + 16) = 0;
      if ( IEntity::FlagBits(a2, Attached)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Settler\\CarrierRole.cpp",
             1019,
             "_pSettler->FlagBits(ENTITY_FLAG_ATTACHED) == 0") == 1 )
      {
        __debugbreak();
      }
    }
    EcoSectorPtr = CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, v12);
    if ( !EcoSectorPtr && BBSupportDbgReport(2, "MapObjects\\Settler\\CarrierRole.cpp", 1026, "pES != 0") == 1 )
      __debugbreak();
    if ( EcoSectorPtr )
    {
      if ( *((_BYTE *)this + 45) == 2 || *((_BYTE *)this + 45) == 3 )
      {
        CEcoSector::ChangeMinMaxValues(EcoSectorPtr, *((unsigned __int8 *)this + 45), 1);
      }
      else if ( *((_BYTE *)this + 45) == 50 || *((_BYTE *)this + 45) == 47 || *((_BYTE *)this + 45) == 49 )
      {
        CEcoSector::ChangeSpecialistWish(EcoSectorPtr, *((unsigned __int8 *)this + 45), 1);
      }
    }
  }
  *((_BYTE *)this + 45) = 0;
  if ( !*((_WORD *)this + 16) )
    return ISettlerRole::SetFree(this, a2, a3);
  v11 = CMapObjectMgr::Entity(*((unsigned __int16 *)this + 16));
  ((void (__thiscall *)(struct IEntity *, int))v11->CPersistence[1].Relationships)(v11, v13);
  return ISettlerRole::SetFree(this, a2, a3);
}


// address=[0x15664c0]
// Decompiled from int __thiscall CCarrierRole::TryToGoHome(CCarrierRole *this, struct CSettler *a2)
void  CCarrierRole::TryToGoHome(class CSettler *) {
  
  int v2; // eax
  int v3; // eax
  int v4; // esi
  int v5; // eax
  int result; // eax
  int v7; // [esp-4h] [ebp-Ch]

  v7 = Y16X16::UnpackYFast(*((_DWORD *)this + 7));
  v2 = Y16X16::UnpackXFast(*((_DWORD *)this + 7));
  v3 = CWorldManager::Index(v2, v7);
  v4 = CWorldManager::EcoSectorId(v3);
  v5 = IEntity::WorldIdx();
  result = CWorldManager::EcoSectorId(v5);
  if ( v4 != result )
    return result;
  IAnimatedEntity::SetFrame(1);
  IMovingEntity::WalkToXY(a2, *((_DWORD *)this + 7), 0);
  *((_BYTE *)this + 4) = 6;
  IMovingEntity::SetDisplacementCosts(5);
  return (*(int (__thiscall **)(CCarrierRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
}


// address=[0x1567080]
// Decompiled from int __thiscall CCarrierRole::DestinationPileId(CCarrierRole *this)
int  CCarrierRole::DestinationPileId(void)const {
  
  return *((unsigned __int16 *)this + 23);
}


// address=[0x1567120]
// Decompiled from int __thiscall CCarrierRole::NextSettlerType(CCarrierRole *this)
int  CCarrierRole::NextSettlerType(void) {
  
  return *((unsigned __int8 *)this + 45);
}


// address=[0x1567160]
// Decompiled from int __thiscall CCarrierRole::SourcePileId2(CCarrierRole *this)
int  CCarrierRole::SourcePileId2(void)const {
  
  return *((unsigned __int16 *)this + 24);
}


// address=[0x1567180]
// Decompiled from int __thiscall CCarrierRole::SourcePileId3(CCarrierRole *this)
int  CCarrierRole::SourcePileId3(void)const {
  
  return *((unsigned __int16 *)this + 25);
}


