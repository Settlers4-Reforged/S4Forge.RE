#include "all_headers.h"

// Definitions for class CCastleRole

// address=[0x14000e0]
// Decompiled from int __cdecl CCastleRole::New(int a1)
static class CPersistence * __cdecl CCastleRole::New(std::istream &) {
  
  if ( operator new(0x1C0u) )
    return CCastleRole::CCastleRole(a1);
  else
    return 0;
}


// address=[0x14fc910]
// Decompiled from CCastleRole *__thiscall CCastleRole::CCastleRole(CCastleRole *this)
 CCastleRole::CCastleRole(void) {
  
  CMilitaryBuildingRole::CMilitaryBuildingRole(this);
  *(_DWORD *)this = &CCastleRole::_vftable_;
  return this;
}


// address=[0x14fcbb0]
// Decompiled from void __thiscall CCastleRole::~CCastleRole(CCastleRole *this)
 CCastleRole::~CCastleRole(void) {
  
  CMilitaryBuildingRole::~CMilitaryBuildingRole(this);
}


// address=[0x14fd060]
// Decompiled from int __thiscall CCastleRole::ClassID(CCastleRole *this)
unsigned long  CCastleRole::ClassID(void)const {
  
  return CCastleRole::m_iClassID;
}


// address=[0x14fd440]
// Decompiled from int __thiscall CCastleRole::GetBuildingRole(CCastleRole *this)
int  CCastleRole::GetBuildingRole(void) {
  
  return 15;
}


// address=[0x14fd8f0]
// Decompiled from int __cdecl CCastleRole::Load(int a1)
static class CCastleRole * __cdecl CCastleRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CCastleRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x1506870]
// Decompiled from int __stdcall CCastleRole::FillGfxInfo(unsigned __int16 *a1, int *a2)
void  CCastleRole::FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &) {
  
  int v2; // eax
  int result; // eax
  int v4; // [esp-Ch] [ebp-18h]
  int v5; // [esp+0h] [ebp-Ch]

  dword_40F21B8[0] = 173;
  v4 = IEntity::Type(a1);
  v2 = IEntity::Race(a1);
  CGfxManager::GetBuildingGfxInfo((int)a2, v2, v4, 1, (int)dword_40F21B8);
  v5 = a2[8];
  CMilitaryBuildingRole::FillGfxInfo((int)a1, (int)a2);
  result = v5;
  *a2 = v5;
  return result;
}


// address=[0x15068f0]
// Decompiled from int __thiscall CCastleRole::Init(CCastleRole *this, struct CBuilding *a2)
void  CCastleRole::Init(class CBuilding *) {
  
  int result; // eax

  CMilitaryBuildingRole::Init(this, a2);
  *((_BYTE *)this + 441) = 100;
  *((_BYTE *)this + 443) = 100;
  *((_BYTE *)this + 445) = 100;
  result = 6;
  *((_BYTE *)this + 447) = 100;
  return result;
}


// address=[0x1506960]
// Decompiled from int __thiscall CCastleRole::PostLoadInit(CCastleRole *this, struct CBuilding *a2)
void  CCastleRole::PostLoadInit(class CBuilding *) {
  
  int v2; // eax
  int result; // eax
  int v4; // [esp-4h] [ebp-8h]

  v4 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  result = CBuildingInfoMgr::GetBuildingInfo(v2, v4);
  *((_DWORD *)this + 94) = result;
  return result;
}


// address=[0x1506990]
// Decompiled from int __thiscall CCastleRole::Decrease(CCastleRole *this, int a2)
int  CCastleRole::Decrease(int) {
  
  return CMilitaryBuildingRole::Decrease(this, a2);
}


// address=[0x15069b0]
// Decompiled from _DWORD *__thiscall CCastleRole::CCastleRole(_DWORD *this, int a2)
 CCastleRole::CCastleRole(std::istream &) {
  
  CMilitaryBuildingRole::CMilitaryBuildingRole(a2);
  *this = &CCastleRole::_vftable_;
  return this;
}


// address=[0x15069e0]
// Decompiled from int __stdcall CCastleRole::Store(struct std::ostream *a1)
void  CCastleRole::Store(std::ostream &) {
  
  return CMilitaryBuildingRole::Store(a1);
}


// address=[0x3d8b120]
// [Decompilation failed for static unsigned long CCastleRole::m_iClassID]

