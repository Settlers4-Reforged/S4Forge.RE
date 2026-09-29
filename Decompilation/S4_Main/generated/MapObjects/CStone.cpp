#include "CStone.h"

// Definitions for class CStone

// address=[0x14020c0]
// Decompiled from CStone *__cdecl CStone::New(int a1)
class CPersistence * __cdecl CStone::New(std::istream & a1) {
  
  CStone *v3; // [esp+Ch] [ebp-10h]

  v3 = (CStone *)CStone::operator new(0x48u);
  if ( v3 != 0 )
  {
    return CStone::CStone(v3, a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x15a2750]
// Decompiled from CStone *__thiscall CStone::CStone(CStone *this, int a2, int a3, int a4, char a5, int a6)
 CStone::CStone(int a2, int a3, int a4, int a5, int a6) {
  
  IDecoObject::IDecoObject((IDecoObject *)this, a2, a3, a4, a6, 1);
  *(_DWORD *)this = &CStone::_vftable_;
  if ( a4 != 41 && a4 != 253 && BBSupportDbgReport(2, "MapObjects\\Stone.cpp", 62, "( _iStoneType == OBJECT_MINESET1 ) || ( _iStoneType == OBJECT_DARKMINESET1 )") == 1 )
  {
    __debugbreak();
  }
  *((_WORD *)this + 19) = CGfxManager::GetObjectFirstJob(g_pGfxManager, *((unsigned __int16 *)this + 6));
  *((_BYTE *)this + 33) = a5;
  return this;
}


// address=[0x15a2810]
// Decompiled from CStone *__thiscall CStone::CStone(CStone *this, const struct IDecoObject *a2, int a3, int a4, int a5)
 CStone::CStone(class CStone const & a2, int a3, int a4, int a5) {
  
  IDecoObject::IDecoObject((IDecoObject *)this, a2, a3, a4, a5);
  *(_DWORD *)this = &CStone::_vftable_;
  *((_WORD *)this + 19) = CGfxManager::GetObjectFirstJob(g_pGfxManager, *((unsigned __int16 *)this + 6));
  *((_BYTE *)this + 33) = a2->m_iLivePoints;
  return this;
}


// address=[0x15a28a0]
// Decompiled from void __thiscall CStone::~CStone(IDecoObject *this)
 CStone::~CStone(void) {
  
  int v1; // eax

  this->__vftable = (IAnimatedEntity_vtbl *)&CStone::_vftable_;
  if ( !IDecoObject::IsStaticInstance(this) )
  {
    v1 = ((int (__stdcall *)())IEntity::WorldIdx)();
    CWorldManager::SetResource(v1, 0, 0);
  }
  IDecoObject::~IDecoObject(this);
}


// address=[0x15a2910]
// Decompiled from void CStone::LogicUpdate()
void  CStone::LogicUpdate(void) {
  
  ;
}


// address=[0x15a2920]
// Decompiled from SGfxObjectInfo *__thiscall sub_19A2920(int this)
struct SGfxObjectInfo *  CStone::GetGfxInfos(void) {
  
  if ( *(_BYTE *)(this + 33) == 0 )
  {
    return 0;
  }
  ((void (__stdcall *)(SGfxObjectInfo *, _DWORD, _DWORD, _DWORD))CGfxManager::GetObjectGfxInfo)(&IEntity::m_sGfxInfo, *(unsigned __int16 *)(this + 38), 0, *(unsigned __int8 *)(this + 33));
  IEntity::m_sGfxInfo.m_uType = 16;
  IEntity::m_sGfxInfo.m_bVisible = IEntity::IsVisible((_DWORD *)this);
  IEntity::m_sGfxInfo.m_uSelectionBlockIndex = 0;
  return &IEntity::m_sGfxInfo;
}


// address=[0x15a2980]
// Decompiled from int __thiscall CStone::GetGoodType(CStone *this)
int  CStone::GetGoodType(void)const {
  
  return 32;
}


// address=[0x15a2990]
// Decompiled from void __thiscall CStone::Take(IDecoObject *this, int a2)
void  CStone::Take(int a2) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // [esp-Ch] [ebp-1Ch]
  int v7; // [esp-8h] [ebp-18h]
  int v8; // [esp-4h] [ebp-14h]
  unsigned int v9; // [esp-4h] [ebp-14h]
  int v10; // [esp+4h] [ebp-Ch]
  char v11; // [esp+8h] [ebp-8h]

  if ( IDecoObject::IsStaticInstance(this) && BBSupportDbgReport(2, "MapObjects\\Stone.cpp", 251, "! IsStaticInstance()") == 1 )
  {
    __debugbreak();
  }
  v2 = ((int (__stdcall *)())IEntity::WorldIdx)();
  v11 = CWorldManager::Resource(v2);
  v10 = v11 & 0xF0;
  if ( this->m_iLivePoints != (v11 & 0xF) && BBSupportDbgReport(2, "MapObjects\\Stone.cpp", 257, "m_uLivePoint == iResourceAmount") == 1 )
  {
    __debugbreak();
  }
  if ( v10 != 96 && BBSupportDbgReport(2, "MapObjects\\Stone.cpp", 258, "RESOURCE_STONE == iResourceType") == 1 )
  {
    __debugbreak();
  }
  if ( --this->m_iLivePoints != 0 )
  {
    v8 = this->m_iLivePoints;
    v3 = ((int (__stdcall *)())IEntity::WorldIdx)();
    CWorldManager::SetResource(v3, v10, v8);
    v9 = this->m_iLivePoints;
    v7 = IEntity::Type(this);
    v6 = IEntity::Y(this);
    v4 = IEntity::X(this);
    CDecoObjMgr::ChangeToStaticInstance(&g_cDecoObjMgr, v4, v6, (T_OBJECT_TYPE)v7, v9);
  }
  else
  {
    v5 = ((int (__stdcall *)())IEntity::ID)();
    CDecoObjMgr::Delete(&g_cDecoObjMgr, v5);
  }
}


// address=[0x15a2ad0]
// Decompiled from int __thiscall CStone::ConvertToDarkOrGreen(IEntity *this, bool a2)
int  CStone::ConvertToDarkOrGreen(bool a2) {
  
  return IEntity::Type(this);
}


// address=[0x15a2af0]
// Decompiled from unsigned int __cdecl CStone::operator new(uint a1)
void * __cdecl CStone::operator new(unsigned int a1) {
  
  return CDecoObjMgr::Alloc(&g_cDecoObjMgr, a1);
}


// address=[0x15a2b10]
// Decompiled from void __cdecl CStone::operator delete(uint *a1)
void __cdecl CStone::operator delete(void * a1) {
  
  CDecoObjMgr::Dealloc(&g_cDecoObjMgr, a1);
}


// address=[0x15a2b50]
// Decompiled from _DWORD *__thiscall CStone::CStone(_DWORD *this, int a2)
 CStone::CStone(std::istream & a2) {
  
  unsigned int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  ((void (__stdcall *)(int))IDecoObject::IDecoObject)(a2);
  v6 = 0;
  *v5 = &CStone::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CStone");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v6 = -1;
  return v5;
}


// address=[0x15a2c00]
// Decompiled from int __thiscall CStone::Store(void *this, struct std::ostream *a2)
void  CStone::Store(std::ostream & a2) {
  
  int v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[1] = (int)this;
  ((void (__stdcall *)(struct std::ostream *))IDecoObject::Store)(a2);
  v3[0] = 1;
  return operator^<unsigned int>(a2, (unsigned int *)v3);
}


// address=[0x15a2dd0]
// Decompiled from int __thiscall CStone::ClassID(CStone *this)
unsigned long  CStone::ClassID(void)const {
  
  return CStone::m_iClassID;
}


// address=[0x15a2df0]
// Decompiled from void __stdcall CStone::Decrease(int a1)
void  CStone::Decrease(int a1) {
  
  ;
}


// address=[0x15a2e00]
// Decompiled from void CStone::Update()
void  CStone::Update(void) {
  
  ;
}


// address=[0x3d8c010]
// [Decompilation failed for static unsigned long CStone::m_iClassID]

