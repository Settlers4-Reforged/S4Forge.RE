#include "CTree.h"

// Definitions for class CTree

// address=[0x14025c0]
// Decompiled from int __cdecl CTree::New(int a1)
class CPersistence * __cdecl CTree::New(std::istream & a1) {
  
  if ( (void *)CTree::operator new(0x50u) != 0 )
  {
    return ((_DWORD (__stdcall *)(int))CTree::CTree)(a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x15a2e10]
// Decompiled from CTree *__thiscall CTree::CTree(CTree *this, int a2, int a3, int a4, int a5, int a6)
 CTree::CTree(int a2, int a3, int a4, int a5, int a6) {
  
  IDecoObject::IDecoObject((IDecoObject *)this, a2, a3, a4, a5, a6 != 0);
  *(_DWORD *)this = &CTree::_vftable_;
  *((_BYTE *)this + 72) = 1;
  *((_BYTE *)this + 73) = a6;
  *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73) + (unsigned __int16)CGfxManager::GetObjectFirstJob(g_pGfxManager, *((unsigned __int16 *)this + 6));
  *((_BYTE *)this + 74) = CGfxManager::GetObjectFrameCount(g_pGfxManager, *((unsigned __int16 *)this + 19));
  if ( *((_BYTE *)this + 74) == 0 && BBSupportDbgReport(2, "MapObjects\\Tree.cpp", 69, "m_uCycleFrames") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)this + 19) = 0;
  if ( IDecoObject::IsStaticInstance((IDecoObject *)this) )
  {
    *((_BYTE *)this + 36) = CStateGame::Rand(g_pGame) % *((unsigned __int8 *)this + 74);
  }
  else
  {
    ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(31);
  }
  return this;
}


// address=[0x15a2f50]
// Decompiled from CTree *__thiscall CTree::CTree(CTree *this, const struct IDecoObject *a2, int a3, int a4, int a5)
 CTree::CTree(class CTree const & a2, int a3, int a4, int a5) {
  
  IDecoObject::IDecoObject((IDecoObject *)this, a2, a3, a4, a5);
  *(_DWORD *)this = &CTree::_vftable_;
  *((_DWORD *)this + 19) = 0;
  *((_BYTE *)this + 73) = 3;
  *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73) + (unsigned __int16)CGfxManager::GetObjectFirstJob(g_pGfxManager, *((unsigned __int16 *)this + 6));
  *((_BYTE *)this + 74) = BYTE2(a2[1].__vftable);
  if ( *((_BYTE *)this + 74) == 0 && BBSupportDbgReport(2, "MapObjects\\Tree.cpp", 104, "m_uCycleFrames") == 1 )
  {
    __debugbreak();
  }
  *((_BYTE *)this + 36) = a2->m_iFrame;
  *((_BYTE *)this + 72) = 1;
  return this;
}


// address=[0x15a3040]
// Decompiled from void __thiscall CTree::LogicUpdate(IEntity *this)
void  CTree::LogicUpdate(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // [esp-Ch] [ebp-18h]
  int v7; // [esp-Ch] [ebp-18h]
  int v8; // [esp-8h] [ebp-14h]
  int v9; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  switch ( *((_BYTE *)this + 73) )
  {
    case 0:
    case 1:
    case 2:
      if ( (int)++*((_DWORD *)this + 19) < 40 )
      {
        goto LABEL_17;
      }
      *((_DWORD *)this + 19) = 0;
      ++*((_BYTE *)this + 73);
      *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73) + (unsigned __int16)CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_iType);
      if ( *((_BYTE *)this + 73) != 3 )
      {
        goto LABEL_17;
      }
      v6 = IEntity::Y(this);
      v1 = IEntity::X(this);
      CWorldManager::SetResource(v1, v6, 112, 1);
      v8 = IEntity::Type(this);
      v7 = IEntity::Y(this);
      v2 = IEntity::X(this);
      CDecoObjMgr::ChangeToStaticInstance(&g_cDecoObjMgr, v2, v7, (T_OBJECT_TYPE)v8, 0);
      break;
    case 4:
      ++*((_BYTE *)this + 73);
      *((_DWORD *)this + 19) = 0;
      *((_BYTE *)this + 36) = 0;
      *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73) + (unsigned __int16)CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_iType);
      *((_BYTE *)this + 74) = CGfxManager::GetObjectFrameCount(g_pGfxManager, *((unsigned __int16 *)this + 19));
      v10 = IEntity::Y(this);
      v3 = IEntity::X(this);
      if ( g_pFogging->IsPositionVisible(g_pFogging, v3, v10) )
      {
        v9 = IEntity::Y(this);
        v4 = IEntity::X(this);
        CSoundManager::PlayEnvironmentSound(g_pSoundManager, 96, v4, v9, 0);
      }
      break;
    case 9:
      if ( (int)++*((_DWORD *)this + 19) >= 2 )
      {
        ++*((_BYTE *)this + 73);
        *((_DWORD *)this + 19) = 0;
        *((_BYTE *)this + 36) = 0;
        *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73) + (unsigned __int16)CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_iType);
        *((_BYTE *)this + 74) = 1;
        if ( *((_BYTE *)this + 74) == 0 && BBSupportDbgReport(2, "MapObjects\\Tree.cpp", 283, "m_uCycleFrames") == 1 )
        {
          __debugbreak();
        }
      }
      goto LABEL_17;
    case 0xA:
      if ( (int)++*((_DWORD *)this + 19) < 2 || (*((_DWORD *)this + 19) = 0, ++*((_BYTE *)this + 36), *((unsigned __int8 *)this + 36) <= CGfxManager::GetObjectFrameCount(g_pGfxManager, *((unsigned __int16 *)this + 19)) - 1) )
      {
LABEL_17:
        ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(31);
      }
      else
      {
        v5 = ((int (__stdcall *)())IEntity::ID)();
        CDecoObjMgr::Delete(&g_cDecoObjMgr, v5);
      }
      break;
    default:
      return;
  }
}


// address=[0x15a3310]
// Decompiled from SGfxObjectInfo *__thiscall sub_19A3310(int this)
struct SGfxObjectInfo *  CTree::GetGfxInfos(void) {
  
  int v1; // esi
  int v2; // eax
  int v4; // [esp+4h] [ebp-8h]

  v1 = CStateGame::GetTickCounter(g_pGame);
  v4 = v1 - IAnimatedEntity::LastUpdateTick((void *)this);
  v2 = CStateGame::GetTickCounter(g_pGame);
  IAnimatedEntity::SetLastUpdateTick((IAnimatedEntity *)this, v2);
  if ( v4 != 0 && *(_BYTE *)(this + 73) != 10 )
  {
    *(_BYTE *)(this + 36) = (v4 + (unsigned int)*(unsigned __int8 *)(this + 36)) % *(unsigned __int8 *)(this + 74);
  }
  ((void (__stdcall *)(SGfxObjectInfo *, _DWORD, _DWORD, int))CGfxManager::GetObjectGfxInfo)(&IEntity::m_sGfxInfo, *(unsigned __int16 *)(this + 38), *(unsigned __int8 *)(this + 36), 1);
  if ( *(_BYTE *)(this + 73) == 3 )
  {
    IEntity::m_sGfxInfo.m_uType = *(_BYTE *)(this + 10);
  }
  else
  {
    IEntity::m_sGfxInfo.m_uType = 16;
  }
  IEntity::m_sGfxInfo.m_bVisible = IEntity::IsVisible((_DWORD *)this);
  IEntity::m_sGfxInfo.m_uSelectionBlockIndex = 0;
  return &IEntity::m_sGfxInfo;
}


// address=[0x15a33e0]
// Decompiled from int __thiscall CTree::GetGoodType(CTree *this)
int  CTree::GetGoodType(void)const {
  
  return 22;
}


// address=[0x15a33f0]
// Decompiled from CTree *__thiscall CTree::Decrease(IDecoObject *this, int a2)
void  CTree::Decrease(int a2) {
  
  int v2; // eax
  CTree *result; // eax

  if ( IDecoObject::IsStaticInstance(this) && BBSupportDbgReport(2, "MapObjects\\Tree.cpp", 323, "! IsStaticInstance()") == 1 )
  {
    __debugbreak();
  }
  if ( *((_BYTE *)this + 73) == 3 )
  {
    v2 = ((int (__stdcall *)())IEntity::WorldIdx)();
    CWorldManager::SetResource(v2, 0, 0);
  }
  ++*((_BYTE *)this + 73);
  this->m_iFrame = 0;
  this->m_iJobPart = *((unsigned __int8 *)this + 73) + (unsigned __int16)CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_iType);
  *((_BYTE *)this + 74) = CGfxManager::GetObjectFrameCount(g_pGfxManager, this->m_iJobPart);
  if ( *((_BYTE *)this + 74) == 0 && BBSupportDbgReport(2, "MapObjects\\Tree.cpp", 337, "m_uCycleFrames") == 1 )
  {
    __debugbreak();
  }
  if ( *((_BYTE *)this + 73) == 4 )
  {
    ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(*((unsigned __int8 *)this + 74) - 1);
  }
  result = (CTree *)this;
  if ( *((_BYTE *)this + 73) == 9 )
  {
    return (CTree *)((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(31);
  }
  return result;
}


// address=[0x15a3500]
// Decompiled from int __thiscall CTree::Increase(CTree *this, int a2)
int  CTree::Increase(int a2) {
  
  return 1;
}


// address=[0x15a3520]
// Decompiled from int __thiscall CTree::Take(CTree *this, int a2)
void  CTree::Take(int a2) {
  
  return (*(int (__thiscall **)(CTree *, int))(*(_DWORD *)this + 32))(this, 1);
}


// address=[0x15a3540]
// Decompiled from int __thiscall CTree::ConvertToDarkOrGreen(IDecoObject *this, bool a2)
int  CTree::ConvertToDarkOrGreen(bool a2) {
  
  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]

  v3 = IEntity::Type(this);
  v4 = IDecoObject::ConvertToDarkOrGreen(this, a2);
  if ( v4 != v3 && !IDecoObject::IsStaticInstance(this) )
  {
    if ( *((_BYTE *)this + 73) != 0 && *((_BYTE *)this + 73) == 1 )
    {
      if ( *((_BYTE *)this + 73) != 2 && *((_BYTE *)this + 73) != 3 )
      {
        return v3;
      }
    }
    else
    {
      return 0;
    }
  }
  return v4;
}


// address=[0x15a35d0]
// Decompiled from unsigned int __cdecl CTree::operator new(uint a1)
void * __cdecl CTree::operator new(unsigned int a1) {
  
  return CDecoObjMgr::Alloc(&g_cDecoObjMgr, a1);
}


// address=[0x15a35f0]
// Decompiled from void __cdecl CTree::operator delete(uint *a1)
void __cdecl CTree::operator delete(void * a1) {
  
  CDecoObjMgr::Dealloc(&g_cDecoObjMgr, a1);
}


// address=[0x15a3630]
// Decompiled from _DWORD *__thiscall CTree::CTree(_DWORD *this, int a2)
 CTree::CTree(std::istream & a2) {
  
  unsigned int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  ((void (__stdcall *)(int))IDecoObject::IDecoObject)(a2);
  v6 = 0;
  *v5 = &CTree::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CTree");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<bool>(a2, v5 + 18);
  operator^<unsigned char>(a2, (unsigned __int8 *)v5 + 73);
  operator^<unsigned char>(a2, (unsigned __int8 *)v5 + 74);
  operator^<int>((struct std::istream *)a2, v5 + 19);
  v6 = -1;
  return v5;
}


// address=[0x15a3730]
// Decompiled from int __thiscall CTree::Store(int *this, struct std::ostream *a2)
void  CTree::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  int *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  ((void (__stdcall *)(struct std::ostream *))IDecoObject::Store)(a2);
  v3 = 1;
  operator^<unsigned int>(a2, (unsigned int *)&v3);
  operator^<bool>(a2, (bool *)v4 + 72);
  operator^<unsigned char>(a2, (unsigned __int8 *)v4 + 73);
  operator^<unsigned char>(a2, (unsigned __int8 *)v4 + 74);
  return operator^<int>(a2, v4 + 19);
}


// address=[0x15a3a20]
// Decompiled from void __thiscall CTree::~CTree(IDecoObject *this)
 CTree::~CTree(void) {
  
  this->__vftable = (IAnimatedEntity_vtbl *)&CTree::_vftable_;
  IDecoObject::~IDecoObject(this);
}


// address=[0x15a3ab0]
// Decompiled from int __thiscall CTree::ClassID(CTree *this)
unsigned long  CTree::ClassID(void)const {
  
  return CTree::m_iClassID;
}


// address=[0x3d8c014]
// [Decompilation failed for static unsigned long CTree::m_iClassID]

