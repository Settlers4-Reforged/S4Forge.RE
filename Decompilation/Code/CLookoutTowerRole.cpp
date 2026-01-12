#include "CLookoutTowerRole.h"

// Definitions for class CLookoutTowerRole

// address=[0x1401080]
// Decompiled from int __cdecl CLookoutTowerRole::New(int a1)

static class CPersistence * __cdecl CLookoutTowerRole::New(std::istream &) {
  
  if ( operator new(0x180u) )
    return CLookoutTowerRole::CLookoutTowerRole(a1);
  else
    return 0;
}


// address=[0x14fca00]
// Decompiled from CLookoutTowerRole *__thiscall CLookoutTowerRole::CLookoutTowerRole(CLookoutTowerRole *this)

 CLookoutTowerRole::CLookoutTowerRole(void) {
  
  IBuildingRole::IBuildingRole(this);
  *(_DWORD *)this = &CLookoutTowerRole::_vftable_;
  return this;
}


// address=[0x14fcc50]
// Decompiled from int __thiscall CLookoutTowerRole::~CLookoutTowerRole(CLookoutTowerRole *this)

 CLookoutTowerRole::~CLookoutTowerRole(void) {
  
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x14fd100]
// Decompiled from int __thiscall CLookoutTowerRole::ClassID(CLookoutTowerRole *this)

unsigned long  CLookoutTowerRole::ClassID(void)const {
  
  return CLookoutTowerRole::m_iClassID;
}


// address=[0x14fd3a0]
// Decompiled from void *__thiscall CLookoutTowerRole::GetBuildingNeed(std::_Ref_count_base *this, const struct type_info *a2)

int  CLookoutTowerRole::GetBuildingNeed(int)const {
  
  return 0;
}


// address=[0x14fd4e0]
// Decompiled from int __thiscall CLookoutTowerRole::GetBuildingRole(CLookoutTowerRole *this)

int  CLookoutTowerRole::GetBuildingRole(void) {
  
  return 9;
}


// address=[0x14fd640]
// Decompiled from void *__thiscall CLookoutTowerRole::GetPileIdWithGood(std::_Ref_count_base *this, const struct type_info *a2)

int  CLookoutTowerRole::GetPileIdWithGood(int)const {
  
  return 0;
}


// address=[0x14fd720]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall CLookoutTowerRole::GoodArrive(CLookoutTowerRole *this, int a2)

void  CLookoutTowerRole::GoodArrive(int) {
  
  ;
}


// address=[0x14fda70]
// Decompiled from int __cdecl CLookoutTowerRole::Load(int a1)

static class CLookoutTowerRole * __cdecl CLookoutTowerRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CLookoutTowerRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x150c280]
// Decompiled from int __thiscall CLookoutTowerRole::LogicUpdate(CLookoutTowerRole *this, struct CBuilding *a2)

void  CLookoutTowerRole::LogicUpdate(class CBuilding *) {
  
  int v2; // eax
  _DWORD *v3; // eax
  int v4; // esi
  int v5; // eax
  int result; // eax
  int v7; // [esp-10h] [ebp-20h]
  int v8; // [esp-8h] [ebp-18h]
  int v9; // [esp-4h] [ebp-14h]
  int v10; // [esp-4h] [ebp-14h]
  IBuildingRole *v11; // [esp+4h] [ebp-Ch]
  char v12; // [esp+8h] [ebp-8h]

  if ( IEntity::FlagBits(a2, Selected) )
    (*(void (__thiscall **)(CLookoutTowerRole *, struct CBuilding *, int))(*(_DWORD *)this + 88))(this, a2, 1);
  v12 = *((_BYTE *)this + 4);
  if ( v12 == 1 )
  {
    result = (*(int (__thiscall **)(CLookoutTowerRole *, struct CBuilding *))(*(_DWORD *)this + 120))(this, a2);
    if ( !(_BYTE)result )
      return IAnimatedEntity::RegisterForLogicUpdate(31);
    *((_BYTE *)this + 4) = 3;
  }
  else
  {
    if ( v12 == 3 )
    {
      if ( !*((_BYTE *)this + 29) )
        return IAnimatedEntity::RegisterForLogicUpdate(31);
      v9 = IEntity::OwnerId((unsigned __int8 *)a2);
      v7 = IEntity::Y(a2);
      v2 = IEntity::X(a2);
      if ( CScanner::FindAnyEnemyFighter(v2, v7, 32, 60, v9) )
      {
        if ( !*((_BYTE *)this + 380) )
        {
          v3 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
          v11 = (IBuildingRole *)CBuilding::Role(v3);
          IBuildingRole::TakeJobTrigger(v11, 16);
          v4 = IEntity::OwnerId((unsigned __int8 *)a2);
          if ( v4 == CPlayerManager::GetLocalPlayerId() )
          {
            v10 = IEntity::Y(a2);
            v8 = IEntity::X(a2);
            v5 = IEntity::OwnerId((unsigned __int8 *)a2);
            CTextMsgHandler::AddWarningMsg(2450, v5, v8, v10);
          }
          *((_BYTE *)this + 380) = 1;
        }
      }
      else
      {
        *((_BYTE *)this + 380) = 0;
      }
      return IAnimatedEntity::RegisterForLogicUpdate(31);
    }
    if ( *((_BYTE *)this + 4) != 2
      && BBSupportDbgReport(2, "MapObjects\\Building\\LookoutTower.cpp", 227, "m_uState == WAIT_STATE") == 1 )
    {
      __debugbreak();
    }
    *((_BYTE *)this + 4) = 3;
    return IAnimatedEntity::RegisterForLogicUpdate(31);
  }
  return result;
}


// address=[0x150c410]
// Decompiled from IBuildingRole *__thiscall CLookoutTowerRole::FillGfxInfo(
        CLookoutTowerRole *this,
        struct CBuilding *a2,
        struct SGfxObjectInfo *a3)

void  CLookoutTowerRole::FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &) {
  
  int v3; // eax
  int v4; // eax
  int v6; // [esp-Ch] [ebp-10h]

  (*(void (__thiscall **)(CLookoutTowerRole *, struct CBuilding *))(*(_DWORD *)this + 16))(this, a2);
  v6 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::Race(a2);
  CGfxManager::GetBuildingGfxInfo((int)a3, v3, v6, 1, (int)this + 76);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  return IBuildingRole::MiniFlag(this, a3, v4);
}


// address=[0x150c470]
// Decompiled from int __thiscall CLookoutTowerRole::Init(CLookoutTowerRole *this, struct CBuilding *a2)

void  CLookoutTowerRole::Init(class CBuilding *) {
  
  int result; // eax

  IBuildingRole::InitCommon((int)a2);
  *((_BYTE *)this + 4) = 1;
  IAnimatedEntity::RegisterForLogicUpdate(2);
  *((_BYTE *)this + 380) = 0;
  result = IEntity::FlagBits(a2, Selected);
  if ( result )
    return (*(int (__thiscall **)(CLookoutTowerRole *, struct CBuilding *, _DWORD))(*(_DWORD *)this + 88))(this, a2, 0);
  return result;
}


// address=[0x150c4d0]
// Decompiled from int __thiscall CLookoutTowerRole::PostLoadInit(CLookoutTowerRole *this, struct CBuilding *a2)

void  CLookoutTowerRole::PostLoadInit(class CBuilding *) {
  
  int v2; // eax
  int result; // eax
  int v4; // [esp-4h] [ebp-8h]

  v4 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  result = CBuildingInfoMgr::GetBuildingInfo(v2, v4);
  *((_DWORD *)this + 94) = result;
  return result;
}


// address=[0x150c500]
// Decompiled from char __thiscall CLookoutTowerRole::SettlerEnter(CLookoutTowerRole *this, struct CBuilding *a2, int a3)

bool  CLookoutTowerRole::SettlerEnter(class CBuilding *,int) {
  
  if ( *((_BYTE *)this + 29)
    && BBSupportDbgReport(2, "MapObjects\\Building\\LookoutTower.cpp", 143, "!m_bWorkerInHouse") == 1 )
  {
    __debugbreak();
  }
  *((_BYTE *)this + 29) = 1;
  *((_BYTE *)this + 4) = 3;
  IAnimatedEntity::RegisterForLogicUpdate(31);
  return 1;
}


// address=[0x150c560]
// Decompiled from _DWORD *__thiscall CLookoutTowerRole::FillDialog(CLookoutTowerRole *this, struct CBuilding *a2, bool a3)

void  CLookoutTowerRole::FillDialog(class CBuilding *,bool) {
  
  int v3; // eax
  int v4; // eax
  int v6; // [esp-8h] [ebp-3Ch]
  int v7; // [esp-8h] [ebp-3Ch]
  unsigned int v8; // [esp+4h] [ebp-30h]
  CEvn_Event v10; // [esp+Ch] [ebp-28h] BYREF
  int v11; // [esp+30h] [ebp-4h]

  dword_3F1E4B0 = 0;
  byte_3F1E4B5 = IEntity::Race(a2);
  byte_3F1E4B4 = IEntity::Type((unsigned __int16 *)a2);
  byte_3F1E4B7 = 0;
  byte_3F1E4B9 = 0;
  v6 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E4BB = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, v6, 0);
  v7 = IEntity::Type((unsigned __int16 *)a2);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E4BC = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v4, v7, 1u);
  byte_3F1E4B6 = *((_BYTE *)this + 29);
  if ( *((_BYTE *)this + 29) )
    byte_3F1E4BD = *(_BYTE *)(*((_DWORD *)this + 94) + 478);
  v8 = 604;
  if ( !a3 )
    v8 = 602;
  CEvn_Event::CEvn_Event(&v10, v8, 0, (unsigned int)&g_cBuildingInfo, 0);
  v11 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v10);
  v11 = -1;
  return CEvn_Event::~CEvn_Event(&v10);
}


// address=[0x150c6a0]
// Decompiled from char *__thiscall CLookoutTowerRole::CLookoutTowerRole(char *this, int a2)

 CLookoutTowerRole::CLookoutTowerRole(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  char *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IBuildingRole::IBuildingRole(this, a2);
  v6 = 0;
  *(_DWORD *)v5 = &CLookoutTowerRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CLookoutTowerRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<bool>(a2, v5 + 380);
  v6 = -1;
  return v5;
}


// address=[0x150c760]
// Decompiled from int __thiscall CLookoutTowerRole::Store(struct IBuildingRole *this, struct std::ostream *a2)

void  CLookoutTowerRole::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct IBuildingRole *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  IBuildingRole::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  return operator^<bool>((int)a2, (int)v4 + 380);
}


// address=[0x3d8b138]
// [Decompilation failed for static unsigned long CLookoutTowerRole::m_iClassID]

// address=[0x14fd220]
// Decompiled from void __thiscall CLookoutTowerRole::ConvertEventIntoGoal(
        CLookoutTowerRole *this,
        struct CBuilding *a2,
        struct CEntityEvent *a3)

void  CLookoutTowerRole::ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *) {
  
  ;
}


// address=[0x14fd290]
// Decompiled from char __thiscall CLookoutTowerRole::CrushBuilding(CLookoutTowerRole *this)

bool  CLookoutTowerRole::CrushBuilding(void) {
  
  return 1;
}


// address=[0x14fde50]
// Decompiled from char __thiscall CLookoutTowerRole::TryCrushBuilding(CLookoutTowerRole *this)

bool  CLookoutTowerRole::TryCrushBuilding(void) {
  
  return 1;
}


