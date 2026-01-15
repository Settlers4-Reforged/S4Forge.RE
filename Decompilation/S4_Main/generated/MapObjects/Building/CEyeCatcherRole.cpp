#include "CEyeCatcherRole.h"

// Definitions for class CEyeCatcherRole

// address=[0x1400860]
// Decompiled from int __cdecl CEyeCatcherRole::New(int a1)
static class CPersistence * __cdecl CEyeCatcherRole::New(std::istream &) {
  
  if ( operator new(0x17Cu) )
    return CEyeCatcherRole::CEyeCatcherRole(a1);
  else
    return 0;
}


// address=[0x14fc970]
// Decompiled from CEyeCatcherRole *__thiscall CEyeCatcherRole::CEyeCatcherRole(CEyeCatcherRole *this)
 CEyeCatcherRole::CEyeCatcherRole(void) {
  
  IBuildingRole::IBuildingRole(this);
  *(_DWORD *)this = &CEyeCatcherRole::_vftable_;
  return this;
}


// address=[0x14fcbf0]
// Decompiled from int __thiscall CEyeCatcherRole::~CEyeCatcherRole(CEyeCatcherRole *this)
 CEyeCatcherRole::~CEyeCatcherRole(void) {
  
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x14fd0a0]
// Decompiled from int __thiscall CEyeCatcherRole::ClassID(CEyeCatcherRole *this)
unsigned long  CEyeCatcherRole::ClassID(void)const {
  
  return CEyeCatcherRole::m_iClassID;
}


// address=[0x14fd340]
// Decompiled from void *__thiscall CEyeCatcherRole::GetBuildingNeed(std::_Ref_count_base *this, const struct type_info *a2)
int  CEyeCatcherRole::GetBuildingNeed(int)const {
  
  return 0;
}


// address=[0x14fd480]
// Decompiled from int __thiscall CEyeCatcherRole::GetBuildingRole(CEyeCatcherRole *this)
int  CEyeCatcherRole::GetBuildingRole(void) {
  
  return 19;
}


// address=[0x14fd5e0]
// Decompiled from void *__thiscall CEyeCatcherRole::GetPileIdWithGood(std::_Ref_count_base *this, const struct type_info *a2)
int  CEyeCatcherRole::GetPileIdWithGood(int)const {
  
  return 0;
}


// address=[0x14fd6f0]
// Decompiled from void __thiscall CEyeCatcherRole::GoodArrive(CEyeCatcherRole *this, int a2)
void  CEyeCatcherRole::GoodArrive(int) {
  
  ;
}


// address=[0x14fd9b0]
// Decompiled from int __cdecl CEyeCatcherRole::Load(int a1)
static class CEyeCatcherRole * __cdecl CEyeCatcherRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CEyeCatcherRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x150a110]
// Decompiled from void __thiscall CEyeCatcherRole::LogicUpdate(CEyeCatcherRole *this, struct CBuilding *a2)
void  CEyeCatcherRole::LogicUpdate(class CBuilding *) {
  
  ;
}


// address=[0x150a120]
// Decompiled from CEyeCatcherRole *__thiscall CEyeCatcherRole::FillGfxInfo(  CEyeCatcherRole *this,  struct CBuilding *a2,  struct SGfxObjectInfo *a3)
void  CEyeCatcherRole::FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &) {
  
  int v3; // eax
  CEyeCatcherRole *result; // eax
  int v5; // [esp-Ch] [ebp-2E4h]
  _DWORD v7[180]; // [esp+4h] [ebp-2D4h] BYREF

  (*(void (__thiscall **)(CEyeCatcherRole *, struct CBuilding *))(*(_DWORD *)this + 16))(this, a2);
  v5 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::Race(a2);
  CGfxManager::GetBuildingGfxInfo((int)a3, v3, v5, 1, (int)this + 76);
  result = this;
  if ( !*((_BYTE *)this + 356) )
    return result;
  CGfxManager::GetEffectGfxInfo(
    (CGfxManager *)g_pGfxManager,
    (struct SGfxObjectInfo *)v7,
    *((unsigned __int8 *)this + 356),
    0,
    *((unsigned __int8 *)this + 359));
  *((_DWORD *)a3 + 26) = v7[0];
  *((_DWORD *)a3 + 27) = v7[1];
  *((_DWORD *)a3 + 28) = *((__int16 *)this + 180);
  result = 0;
  *((_DWORD *)a3 + 29) = *((__int16 *)this + 181);
  return result;
}


// address=[0x150a240]
// Decompiled from int __thiscall CEyeCatcherRole::Init(CEyeCatcherRole *this, struct CBuilding *a2)
void  CEyeCatcherRole::Init(class CBuilding *) {
  
  int result; // eax

  IBuildingRole::InitCommon((int)a2);
  result = IEntity::FlagBits(a2, Selected);
  if ( result )
    return (*(int (__thiscall **)(CEyeCatcherRole *, struct CBuilding *, _DWORD))(*(_DWORD *)this + 88))(this, a2, 0);
  return result;
}


// address=[0x150a280]
// Decompiled from int __thiscall CEyeCatcherRole::PostLoadInit(CEyeCatcherRole *this, struct CBuilding *a2)
void  CEyeCatcherRole::PostLoadInit(class CBuilding *) {
  
  int v2; // eax
  int result; // eax
  int v4; // [esp-4h] [ebp-8h]

  v4 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  result = CBuildingInfoMgr::GetBuildingInfo(v2, v4);
  *((_DWORD *)this + 94) = result;
  return result;
}


// address=[0x150a2b0]
// Decompiled from _DWORD *__thiscall CEyeCatcherRole::FillDialog(CEyeCatcherRole *this, struct CBuilding *a2, bool a3)
void  CEyeCatcherRole::FillDialog(class CBuilding *,bool) {
  
  int v3; // eax
  int v4; // eax
  int v6; // [esp-8h] [ebp-40h]
  int v7; // [esp-8h] [ebp-40h]
  unsigned int v8; // [esp+8h] [ebp-30h]
  CEvn_Event v9; // [esp+10h] [ebp-28h] BYREF
  int v10; // [esp+34h] [ebp-4h]

  dword_3F1E4B0 = 0;
  byte_3F1E4B5 = IEntity::Race(a2);
  byte_3F1E4B4 = IEntity::Type((unsigned __int16 *)a2);
  byte_3F1E4CB = 0;
  byte_3F1E4CC = IEntity::FlagBits(a2, (EntityFlag)0x1000u) != 0;
  byte_3F1E4B9 = 0;
  byte_3F1E4B6 = 0;
  byte_3F1E4BA = -1;
  v6 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E4BB = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, v6, 0);
  v7 = IEntity::Type((unsigned __int16 *)a2);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E4BC = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v4, v7, 1u);
  v8 = 604;
  if ( !a3 )
    v8 = 602;
  CEvn_Event::CEvn_Event(&v9, v8, 0, (unsigned int)&g_cBuildingInfo, 0);
  v10 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v9);
  v10 = -1;
  return CEvn_Event::~CEvn_Event(&v9);
}


// address=[0x150a400]
// Decompiled from char *__thiscall CEyeCatcherRole::CEyeCatcherRole(char *this, int a2)
 CEyeCatcherRole::CEyeCatcherRole(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  char *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IBuildingRole::IBuildingRole(this, a2);
  v6 = 0;
  *(_DWORD *)v5 = &CEyeCatcherRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CEyeCatcherRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v6 = -1;
  return v5;
}


// address=[0x150a4b0]
// Decompiled from int __thiscall CEyeCatcherRole::Store(struct IBuildingRole *this, struct std::ostream *a2)
void  CEyeCatcherRole::Store(std::ostream &) {
  
  int v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[1] = (int)this;
  IBuildingRole::Store(this, a2);
  v3[0] = 1;
  return operator^<unsigned int>(a2, v3);
}


// address=[0x3d8b12c]
// [Decompilation failed for static unsigned long CEyeCatcherRole::m_iClassID]

// address=[0x14fd1f0]
// Decompiled from void __thiscall CEyeCatcherRole::ConvertEventIntoGoal(  CEyeCatcherRole *this,  struct CBuilding *a2,  struct CEntityEvent *a3)
void  CEyeCatcherRole::ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *) {
  
  ;
}


// address=[0x14fd270]
// Decompiled from char __thiscall CEyeCatcherRole::CrushBuilding(CEyeCatcherRole *this)
bool  CEyeCatcherRole::CrushBuilding(void) {
  
  return 1;
}


// address=[0x14fde20]
// Decompiled from char __thiscall CEyeCatcherRole::TryCrushBuilding(CEyeCatcherRole *this)
bool  CEyeCatcherRole::TryCrushBuilding(void) {
  
  return 1;
}


