#include "all_headers.h"

// Definitions for class CTree

// address=[0x14025c0]
// Decompiled from int __cdecl CTree::New(int a1)
static class CPersistence * __cdecl CTree::New(std::istream &) {
  
  if ( CTree::operator new(0x50u) )
    return CTree::CTree(a1);
  else
    return 0;
}


// address=[0x15a2e10]
// Decompiled from CTree *__thiscall CTree::CTree(CTree *this, int a2, int a3, int a4, int a5, int a6)
 CTree::CTree(int,int,int,int,int) {
  
  IDecoObject::IDecoObject(this, a2, a3, a4, a5, a6 != 0);
  *(_DWORD *)this = &CTree::_vftable_;
  *((_BYTE *)this + 72) = 1;
  *((_BYTE *)this + 73) = a6;
  *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73)
                        + (unsigned __int16)CGfxManager::GetObjectFirstJob(
                                              (CGfxManager *)g_pGfxManager,
                                              *((unsigned __int16 *)this + 6));
  *((_BYTE *)this + 74) = CGfxManager::GetObjectFrameCount(
                            (CGfxManager *)g_pGfxManager,
                            *((unsigned __int16 *)this + 19));
  if ( !*((_BYTE *)this + 74) && BBSupportDbgReport(2, "MapObjects\\Tree.cpp", 69, "m_uCycleFrames") == 1 )
    __debugbreak();
  *((_DWORD *)this + 19) = 0;
  if ( IDecoObject::IsStaticInstance(this) )
    *((_BYTE *)this + 36) = CStateGame::Rand(g_pGame) % (unsigned int)*((unsigned __int8 *)this + 74);
  else
    IAnimatedEntity::RegisterForLogicUpdate(31);
  return this;
}


// address=[0x15a2f50]
// Decompiled from CTree *__thiscall CTree::CTree(CTree *this, const struct CTree *a2, int a3, int a4, int a5)
 CTree::CTree(class CTree const &,int,int,int) {
  
  IDecoObject::IDecoObject(this, a2, a3, a4, a5);
  *(_DWORD *)this = &CTree::_vftable_;
  *((_DWORD *)this + 19) = 0;
  *((_BYTE *)this + 73) = 3;
  *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73)
                        + (unsigned __int16)CGfxManager::GetObjectFirstJob(
                                              (CGfxManager *)g_pGfxManager,
                                              *((unsigned __int16 *)this + 6));
  *((_BYTE *)this + 74) = *((_BYTE *)a2 + 74);
  if ( !*((_BYTE *)this + 74) && BBSupportDbgReport(2, "MapObjects\\Tree.cpp", 104, "m_uCycleFrames") == 1 )
    __debugbreak();
  *((_BYTE *)this + 36) = *((_BYTE *)a2 + 36);
  *((_BYTE *)this + 72) = 1;
  return this;
}


// address=[0x15a3040]
// Decompiled from void __thiscall CTree::LogicUpdate(CTree *this)
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
        goto LABEL_17;
      *((_DWORD *)this + 19) = 0;
      ++*((_BYTE *)this + 73);
      *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73)
                            + (unsigned __int16)CGfxManager::GetObjectFirstJob(
                                                  (CGfxManager *)g_pGfxManager,
                                                  *((unsigned __int16 *)this + 6));
      if ( *((_BYTE *)this + 73) != 3 )
        goto LABEL_17;
      v6 = IEntity::Y(this);
      v1 = IEntity::X(this);
      CWorldManager::SetResource(v1, v6, 112, 1);
      v8 = IEntity::Type((unsigned __int16 *)this);
      v7 = IEntity::Y(this);
      v2 = IEntity::X(this);
      CDecoObjMgr::ChangeToStaticInstance((CDecoObjMgr *)&g_cDecoObjMgr, v2, v7, v8, 0);
      break;
    case 4:
      ++*((_BYTE *)this + 73);
      *((_DWORD *)this + 19) = 0;
      *((_BYTE *)this + 36) = 0;
      *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73)
                            + (unsigned __int16)CGfxManager::GetObjectFirstJob(
                                                  (CGfxManager *)g_pGfxManager,
                                                  *((unsigned __int16 *)this + 6));
      *((_BYTE *)this + 74) = CGfxManager::GetObjectFrameCount(
                                (CGfxManager *)g_pGfxManager,
                                *((unsigned __int16 *)this + 19));
      v10 = IEntity::Y(this);
      v3 = IEntity::X(this);
      if ( (*(unsigned __int8 (__thiscall **)(void *, int, int))(*(_DWORD *)g_pFogging + 32))(g_pFogging, v3, v10) )
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
        *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73)
                              + (unsigned __int16)CGfxManager::GetObjectFirstJob(
                                                    (CGfxManager *)g_pGfxManager,
                                                    *((unsigned __int16 *)this + 6));
        *((_BYTE *)this + 74) = 1;
        if ( !*((_BYTE *)this + 74) && BBSupportDbgReport(2, "MapObjects\\Tree.cpp", 283, "m_uCycleFrames") == 1 )
          __debugbreak();
      }
      goto LABEL_17;
    case 0xA:
      if ( (int)++*((_DWORD *)this + 19) < 2
        || (*((_DWORD *)this + 19) = 0,
            ++*((_BYTE *)this + 36),
            *((unsigned __int8 *)this + 36) <= (int)(CGfxManager::GetObjectFrameCount(
                                                       (CGfxManager *)g_pGfxManager,
                                                       *((unsigned __int16 *)this + 19))
                                                   - 1)) )
      {
LABEL_17:
        IAnimatedEntity::RegisterForLogicUpdate(31);
      }
      else
      {
        v5 = IEntity::ID();
        CDecoObjMgr::Delete((CDecoObjMgr *)&g_cDecoObjMgr, v5);
      }
      break;
    default:
      return;
  }
}


// address=[0x15a3310]
// Decompiled from void *__thiscall sub_19A3310(int this)
struct SGfxObjectInfo *  CTree::GetGfxInfos(void) {
  
  int v1; // esi
  int v2; // eax
  int v4; // [esp+4h] [ebp-8h]

  v1 = CStateGame::GetTickCounter(g_pGame);
  v4 = v1 - IAnimatedEntity::LastUpdateTick(this);
  v2 = CStateGame::GetTickCounter(g_pGame);
  IAnimatedEntity::SetLastUpdateTick((CMFCCaptionButton *)this, v2);
  if ( v4 && *(_BYTE *)(this + 73) != 10 )
    *(_BYTE *)(this + 36) = (v4 + (unsigned int)*(unsigned __int8 *)(this + 36)) % *(unsigned __int8 *)(this + 74);
  CGfxManager::GetObjectGfxInfo(
    &IEntity::m_sGfxInfo,
    *(unsigned __int16 *)(this + 38),
    *(unsigned __int8 *)(this + 36),
    1);
  if ( *(_BYTE *)(this + 73) == 3 )
    byte_40FE518 = *(_BYTE *)(this + 10);
  else
    byte_40FE518 = 16;
  byte_40FE51A = IEntity::IsVisible((void *)this);
  byte_40FE266 = 0;
  return &IEntity::m_sGfxInfo;
}


// address=[0x15a33e0]
// Decompiled from int __thiscall CTree::GetGoodType(CTree *this)
int  CTree::GetGoodType(void)const {
  
  return 22;
}


// address=[0x15a33f0]
// Decompiled from CTree *__thiscall CTree::Decrease(CTree *this, int a2)
void  CTree::Decrease(int) {
  
  int v2; // eax
  CTree *result; // eax

  if ( IDecoObject::IsStaticInstance(this)
    && BBSupportDbgReport(2, "MapObjects\\Tree.cpp", 323, "! IsStaticInstance()") == 1 )
  {
    __debugbreak();
  }
  if ( *((_BYTE *)this + 73) == 3 )
  {
    v2 = IEntity::WorldIdx();
    CWorldManager::SetResource(v2, 0, 0);
  }
  ++*((_BYTE *)this + 73);
  *((_BYTE *)this + 36) = 0;
  *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73)
                        + (unsigned __int16)CGfxManager::GetObjectFirstJob(
                                              (CGfxManager *)g_pGfxManager,
                                              *((unsigned __int16 *)this + 6));
  *((_BYTE *)this + 74) = CGfxManager::GetObjectFrameCount(
                            (CGfxManager *)g_pGfxManager,
                            *((unsigned __int16 *)this + 19));
  if ( !*((_BYTE *)this + 74) && BBSupportDbgReport(2, "MapObjects\\Tree.cpp", 337, "m_uCycleFrames") == 1 )
    __debugbreak();
  if ( *((_BYTE *)this + 73) == 4 )
    IAnimatedEntity::RegisterForLogicUpdate(*((unsigned __int8 *)this + 74) - 1);
  result = this;
  if ( *((_BYTE *)this + 73) == 9 )
    return (CTree *)IAnimatedEntity::RegisterForLogicUpdate(31);
  return result;
}


// address=[0x15a3500]
// Decompiled from int __thiscall CTree::Increase(CTree *this, int a2)
int  CTree::Increase(int) {
  
  return 1;
}


// address=[0x15a3520]
// Decompiled from int __thiscall CTree::Take(CTree *this, int a2)
void  CTree::Take(int) {
  
  return (*(int (__thiscall **)(CTree *, int))(*(_DWORD *)this + 32))(this, 1);
}


// address=[0x15a3540]
// Decompiled from int __thiscall CTree::ConvertToDarkOrGreen(CTree *this, bool a2)
int  CTree::ConvertToDarkOrGreen(bool) {
  
  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]

  v3 = IEntity::Type((unsigned __int16 *)this);
  v4 = IDecoObject::ConvertToDarkOrGreen(this, a2);
  if ( v4 == v3 || IDecoObject::IsStaticInstance(this) )
    return v4;
  if ( *((_BYTE *)this + 73) && *((_BYTE *)this + 73) == 1 )
  {
    if ( *((_BYTE *)this + 73) != 2 && *((_BYTE *)this + 73) != 3 )
      return v3;
  }
  else
  {
    return 0;
  }
  return v4;
}


// address=[0x15a35d0]
// Decompiled from unsigned int __cdecl CTree::operator new(unsigned int a1)
static void * __cdecl CTree::operator new(unsigned int) {
  
  return CDecoObjMgr::Alloc((CDecoObjMgr *)&g_cDecoObjMgr, a1);
}


// address=[0x15a35f0]
// Decompiled from void __cdecl CTree::operator delete(void *a1)
static void __cdecl CTree::operator delete(void *) {
  
  CDecoObjMgr::Dealloc((CDecoObjMgr *)&g_cDecoObjMgr, a1);
}


// address=[0x15a3630]
// Decompiled from _DWORD *__thiscall CTree::CTree(_DWORD *this, int a2)
 CTree::CTree(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IDecoObject::IDecoObject(a2);
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
  operator^<unsigned char>(a2, (char *)v5 + 73);
  operator^<unsigned char>(a2, (char *)v5 + 74);
  operator^<int>(a2, (int)(v5 + 19));
  v6 = -1;
  return v5;
}


// address=[0x15a3730]
// Decompiled from int __thiscall CTree::Store(int *this, struct std::ostream *a2)
void  CTree::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  int *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  IDecoObject::Store(a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<bool>((int)a2, (int)(v4 + 18));
  operator^<unsigned char>(a2, (int)v4 + 73);
  operator^<unsigned char>(a2, (int)v4 + 74);
  return operator^<int>((int)a2, v4 + 19);
}


// address=[0x15a3a20]
// Decompiled from void __thiscall CTree::~CTree(CTree *this)
 CTree::~CTree(void) {
  
  *(_DWORD *)this = &CTree::_vftable_;
  IDecoObject::~IDecoObject(this);
}


// address=[0x15a3ab0]
// Decompiled from int __thiscall CTree::ClassID(CTree *this)
unsigned long  CTree::ClassID(void)const {
  
  return CTree::m_iClassID;
}


// address=[0x3d8c014]
// [Decompilation failed for static unsigned long CTree::m_iClassID]

