#include "CAnimalRanchRole.h"

// Definitions for class CAnimalRanchRole

// address=[0x13ffa00]
// Decompiled from int __cdecl CAnimalRanchRole::New(int a1)
class CPersistence * __cdecl CAnimalRanchRole::New(std::istream & a1) {
  
  if ( operator new(0x194u) )
    return CAnimalRanchRole::CAnimalRanchRole(a1);
  else
    return 0;
}


// address=[0x14e5d70]
// Decompiled from char __thiscall CAnimalRanchRole::LogicUpdate(CAnimalRanchRole *this, struct CBuilding *a2)
void  CAnimalRanchRole::LogicUpdate(class CBuilding * a2) {
  
  unsigned int v2; // eax
  unsigned __int8 *v3; // eax
  const char *v4; // esi
  unsigned int v5; // eax
  int BuildingFirstJob; // eax
  unsigned int v7; // eax
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // eax
  const char *v10; // esi
  unsigned int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  unsigned int v16; // eax
  int v17; // edx
  int v19; // [esp-10h] [ebp-7Ch]
  int v20; // [esp-Ch] [ebp-78h]
  unsigned int v21; // [esp-4h] [ebp-70h]
  unsigned int v22; // [esp-4h] [ebp-70h]
  unsigned int v23; // [esp-4h] [ebp-70h]
  unsigned int v24; // [esp-4h] [ebp-70h]
  _BYTE v25[24]; // [esp+8h] [ebp-64h] BYREF
  _BYTE v26[24]; // [esp+20h] [ebp-4Ch] BYREF
  CEntityEvent *v27; // [esp+38h] [ebp-34h]
  CEntityEvent *v28; // [esp+3Ch] [ebp-30h]
  CEntityEvent *v29; // [esp+40h] [ebp-2Ch]
  CEntityEvent *v30; // [esp+44h] [ebp-28h]
  int v31; // [esp+48h] [ebp-24h]
  int v32; // [esp+4Ch] [ebp-20h]
  unsigned __int8 *v33; // [esp+50h] [ebp-1Ch]
  int v34; // [esp+54h] [ebp-18h]
  char v35; // [esp+58h] [ebp-14h]
  CWorkUpBuildingRole *v36; // [esp+5Ch] [ebp-10h]
  int v37; // [esp+68h] [ebp-4h]

  v36 = this;
  v2 = IEntity::FlagBits(a2, Selected);
  if ( v2 )
    LOBYTE(v2) = (*(int (__thiscall **)(CWorkUpBuildingRole *, struct CBuilding *, int))(*(_DWORD *)v36 + 88))(
                   v36,
                   a2,
                   1);
  v35 = *((_BYTE *)v36 + 4);
  switch ( v35 )
  {
    case 1:
      LOBYTE(v2) = (*(int (__thiscall **)(CWorkUpBuildingRole *, struct CBuilding *))(*(_DWORD *)v36 + 120))(v36, a2);
      if ( !(_BYTE)v2 )
      {
LABEL_35:
        LOBYTE(v2) = IAnimatedEntity::RegisterForLogicUpdate(31);
        return v2;
      }
      *((_BYTE *)v36 + 4) = 3;
      break;
    case 2:
      if ( *((unsigned __int8 *)v36 + 5) > (int)*(unsigned __int8 *)(*((_DWORD *)v36 + 94) + 480) )
      {
        *((_BYTE *)v36 + 5) = 0;
        *((_BYTE *)v36 + 4) = 3;
        LOBYTE(v2) = IAnimatedEntity::RegisterForLogicUpdate(1);
      }
      else
      {
        ++*((_BYTE *)v36 + 5);
        LOBYTE(v2) = IAnimatedEntity::RegisterForLogicUpdate(14);
      }
      break;
    case 3:
      if ( !*((_BYTE *)v36 + 29)
        || !IEntity::FlagBits(a2, (EntityFlag)0x1000u)
        || !CWorkUpBuildingRole::HaveMaterial(v36, a2) )
      {
        goto LABEL_35;
      }
      if ( !*(_BYTE *)std::vector<unsigned char>::operator[](0)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Building\\AnimalRanchRole.cpp",
             169,
             "m_pBuildingInfo->vAnimListId[0] != 0") == 1 )
      {
        __debugbreak();
      }
      v34 = IEntity::Type((unsigned __int16 *)a2);
      if ( v34 == 12 )
      {
        v33 = CPileMgr::operator[](*((unsigned __int16 *)v36 + 191));
        if ( (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v33 + 40))(v33) >= 8 )
          goto LABEL_35;
        if ( *((unsigned __int8 *)v36 + 400) >= 6u )
        {
          --*((_BYTE *)v36 + 400);
          v22 = IEntity::Type((unsigned __int16 *)a2);
          v7 = IEntity::Race(a2);
          *((_DWORD *)v36 + 19) = CGfxManager::GetBuildingFirstJob((CGfxManager *)g_pGfxManager, v7, v22)
                                + *((unsigned __int8 *)v36 + 400)
                                + 1;
          v8 = CPileMgr::operator[](*((unsigned __int16 *)v36 + 191));
          CPile::IncreaseUnforeseen((CPile *)v8, 1);
          LOBYTE(v2) = IAnimatedEntity::RegisterForLogicUpdate(31);
        }
        else
        {
          v32 = CSettlerMgr::operator[](*((unsigned __int16 *)v36 + 4));
          v3 = (unsigned __int8 *)std::vector<unsigned char>::operator[](0);
          v30 = CEntityEvent::CEntityEvent((CEntityEvent *)v26, 3u, 0, 0, *v3, 0);
          v29 = v30;
          v37 = 0;
          (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v32 + 80))(v32, v30);
          v37 = -1;
          CEntityEvent::~CEntityEvent(v26);
          v4 = CGameData::Rand(g_pGameData);
          if ( (unsigned int)v4 > CRandom16::PercentValue(0x17u) )
          {
            ++*((_BYTE *)v36 + 400);
            v21 = IEntity::Type((unsigned __int16 *)a2);
            v5 = IEntity::Race(a2);
            BuildingFirstJob = CGfxManager::GetBuildingFirstJob((CGfxManager *)g_pGfxManager, v5, v21);
            *((_DWORD *)v36 + 19) = BuildingFirstJob + *((unsigned __int8 *)v36 + 400) + 1;
            *((_BYTE *)v36 + 156) = 1;
            *((_BYTE *)v36 + 158) = 0;
          }
          LOBYTE(v2) = (*(int (__thiscall **)(CWorkUpBuildingRole *, struct CBuilding *, int))(*(_DWORD *)v36 + 72))(
                         v36,
                         a2,
                         1);
        }
      }
      else
      {
        if ( v34 != 13 )
          goto LABEL_35;
        v31 = CSettlerMgr::operator[](*((unsigned __int16 *)v36 + 4));
        v9 = (unsigned __int8 *)std::vector<unsigned char>::operator[](0);
        v28 = CEntityEvent::CEntityEvent((CEntityEvent *)v25, 3u, 0, 0, *v9, 0);
        v27 = v28;
        v37 = 1;
        (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v31 + 80))(v31, v28);
        v37 = -1;
        CEntityEvent::~CEntityEvent(v25);
        (*(void (__thiscall **)(CWorkUpBuildingRole *, struct CBuilding *, int))(*(_DWORD *)v36 + 72))(v36, a2, 1);
        v10 = CGameData::Rand(g_pGameData);
        v2 = CRandom16::PercentValue(0x19u);
        if ( (unsigned int)v10 < v2 )
        {
          if ( *((unsigned __int8 *)v36 + 400) >= 3u )
          {
            v12 = CBuilding::EnsignWorldIdx(a2);
            LOBYTE(v2) = CWorldManager::IsPositionFreeForSettler(v12);
            if ( (unsigned __int8)v2 == 1 )
            {
              --*((_BYTE *)v36 + 400);
              v20 = IEntity::OwnerId((unsigned __int8 *)a2);
              v13 = CBuilding::EnsignPackedXY(a2);
              v19 = Y16X16::UnpackYFast(v13);
              v14 = CBuilding::EnsignPackedXY(a2);
              v15 = Y16X16::UnpackXFast(v14);
              CSettlerMgr::AddSettler((CSettlerMgr *)g_cSettlerMgr, v15, v19, v20, 60, 0);
              v24 = IEntity::Type((unsigned __int16 *)a2);
              v16 = IEntity::Race(a2);
              v2 = CGfxManager::GetBuildingFirstJob((CGfxManager *)g_pGfxManager, v16, v24);
              v17 = v2 + *((unsigned __int8 *)v36 + 400) + 1;
              LOBYTE(v2) = (_BYTE)v36;
              *((_DWORD *)v36 + 19) = v17;
            }
          }
          else
          {
            ++*((_BYTE *)v36 + 400);
            v23 = IEntity::Type((unsigned __int16 *)a2);
            v11 = IEntity::Race(a2);
            v2 = CGfxManager::GetBuildingFirstJob((CGfxManager *)g_pGfxManager, v11, v23);
            *((_DWORD *)v36 + 19) = v2 + *((unsigned __int8 *)v36 + 400) + 1;
            *((_BYTE *)v36 + 156) = 1;
            LOBYTE(v2) = (_BYTE)v36;
            *((_BYTE *)v36 + 158) = 0;
          }
        }
      }
      break;
    default:
      return v2;
  }
  return v2;
}


// address=[0x14e62d0]
// Decompiled from unsigned int __thiscall CAnimalRanchRole::Init(CAnimalRanchRole *this, struct CBuilding *a2)
void  CAnimalRanchRole::Init(class CBuilding * a2) {
  
  unsigned int v2; // eax
  int v3; // eax
  int v4; // eax
  unsigned int v6; // [esp-4h] [ebp-8h]

  CWorkUpBuildingRole::Init(this, a2);
  *((_BYTE *)this + 400) = 0;
  ++*((_BYTE *)this + 400);
  v6 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  *((_DWORD *)this + 19) = CGfxManager::GetBuildingFirstJob((CGfxManager *)g_pGfxManager, v2, v6)
                         + *((unsigned __int8 *)this + 400)
                         + 1;
  *((_BYTE *)this + 156) = 1;
  *((_BYTE *)this + 158) = 0;
  v3 = CBuilding::EnsignWorldIdx(a2);
  CWorldManager::SetMoveCostsBits(v3, 7);
  v4 = CBuilding::EnsignWorldIdx(a2);
  return CWorldManager::SetFlagBits(v4, 2u);
}


// address=[0x14e6390]
// Decompiled from void __thiscall CAnimalRanchRole::PostLoadInit(CAnimalRanchRole *this, struct CBuilding *a2)
void  CAnimalRanchRole::PostLoadInit(class CBuilding * a2) {
  
  CWorkUpBuildingRole::PostLoadInit(this, a2);
}


// address=[0x14e63b0]
// Decompiled from _DWORD *__thiscall CAnimalRanchRole::CAnimalRanchRole(_DWORD *this, int a2)
 CAnimalRanchRole::CAnimalRanchRole(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  CWorkUpBuildingRole::CWorkUpBuildingRole(a2);
  v6 = 0;
  *v5 = &CAnimalRanchRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CAnimalRanchRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, v5 + 100);
  v6 = -1;
  return v5;
}


// address=[0x14e6470]
// Decompiled from int __thiscall CAnimalRanchRole::Store(void *this, struct std::ostream *a2)
void  CAnimalRanchRole::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  void *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  CWorkUpBuildingRole::Store(a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  return operator^<unsigned char>(a2, (int)v4 + 400);
}


// address=[0x14e6690]
// Decompiled from void __thiscall CAnimalRanchRole::~CAnimalRanchRole(CAnimalRanchRole *this)
 CAnimalRanchRole::~CAnimalRanchRole(void) {
  
  CWorkUpBuildingRole::~CWorkUpBuildingRole(this);
}


// address=[0x14e6780]
// Decompiled from int __thiscall CAnimalRanchRole::ClassID(CAnimalRanchRole *this)
unsigned long  CAnimalRanchRole::ClassID(void)const {
  
  return CAnimalRanchRole::m_iClassID;
}


// address=[0x14e67b0]
// Decompiled from int __thiscall CAnimalRanchRole::GetBuildingRole(CAnimalRanchRole *this)
int  CAnimalRanchRole::GetBuildingRole(void) {
  
  return 3;
}


// address=[0x14fc8a0]
// Decompiled from CAnimalRanchRole *__thiscall CAnimalRanchRole::CAnimalRanchRole(CAnimalRanchRole *this)
 CAnimalRanchRole::CAnimalRanchRole(void) {
  
  CWorkUpBuildingRole::CWorkUpBuildingRole(this);
  *(_DWORD *)this = &CAnimalRanchRole::_vftable_;
  return this;
}


// address=[0x14fd7f0]
// Decompiled from int __cdecl CAnimalRanchRole::Load(int a1)
class CAnimalRanchRole * __cdecl CAnimalRanchRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CAnimalRanchRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8a964]
// [Decompilation failed for static unsigned long CAnimalRanchRole::m_iClassID]

