#include "all_headers.h"

// Definitions for class CShadowHerb

// address=[0x1401c60]
// Decompiled from int __cdecl CShadowHerb::New(int a1)
static class CPersistence * __cdecl CShadowHerb::New(std::istream &) {
  
  if ( CShadowHerb::operator new(0x50u) )
    return CShadowHerb::CShadowHerb(a1);
  else
    return 0;
}


// address=[0x154abc0]
// Decompiled from CShadowHerb *__thiscall CShadowHerb::CShadowHerb(CShadowHerb *this, int a2, int a3, int a4, int a5, int a6)
 CShadowHerb::CShadowHerb(int,int,int,int,int) {
  
  IDecoObject::IDecoObject(this, a2, a3, a4, a5, 0);
  *(_DWORD *)this = &CShadowHerb::_vftable_;
  *((_WORD *)this + 19) = CGfxManager::GetObjectFirstJob((CGfxManager *)g_pGfxManager, *((unsigned __int16 *)this + 6));
  *((_BYTE *)this + 72) = 1;
  *((_BYTE *)this + 73) = 0;
  *((_BYTE *)this + 74) = CGfxManager::GetObjectFrameCount(
                            (CGfxManager *)g_pGfxManager,
                            *((unsigned __int16 *)this + 19));
  *((_DWORD *)this + 19) = 0;
  if ( !*((_BYTE *)this + 74)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\ShadowHerb.cpp", 77, "m_uCycleFrames > 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((unsigned __int8 *)this + 74) >= 0x20u
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\ShadowHerb.cpp", 78, "m_uCycleFrames < 32") == 1 )
  {
    __debugbreak();
  }
  IAnimatedEntity::RegisterForLogicUpdate(*((unsigned __int8 *)this + 74));
  return this;
}


// address=[0x154ace0]
// Decompiled from void __thiscall CShadowHerb::LogicUpdate(CShadowHerb *this)
void  CShadowHerb::LogicUpdate(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // [esp-4h] [ebp-Ch]
  int v5; // [esp-4h] [ebp-Ch]

  switch ( *((_BYTE *)this + 73) )
  {
    case 0:
      ++*((_BYTE *)this + 73);
      *((_BYTE *)this + 36) = 0;
      *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73)
                            + (unsigned __int16)CGfxManager::GetObjectFirstJob(
                                                  (CGfxManager *)g_pGfxManager,
                                                  *((unsigned __int16 *)this + 6));
      *((_BYTE *)this + 74) = CGfxManager::GetObjectFrameCount(
                                (CGfxManager *)g_pGfxManager,
                                *((unsigned __int16 *)this + 19));
      IAnimatedEntity::RegisterForLogicUpdate(1);
      break;
    case 1:
      if ( (unsigned __int8)++*((_BYTE *)this + 36) < (int)*((unsigned __int8 *)this + 74) )
      {
        IAnimatedEntity::RegisterForLogicUpdate(1);
      }
      else
      {
        ++*((_BYTE *)this + 73);
        v4 = IEntity::Y(this);
        v1 = IEntity::X(this);
        IDarkTribe::ChangeSurroundingToDarkLand((IDarkTribe *)g_pDarkTribe, v1, v4);
        --*((_BYTE *)this + 36);
        IAnimatedEntity::RegisterForLogicUpdate(31);
      }
      break;
    case 2:
      ++*((_BYTE *)this + 73);
      *((_BYTE *)this + 36) = 0;
      *((_WORD *)this + 19) = CGfxManager::GetObjectFirstJob(
                                (CGfxManager *)g_pGfxManager,
                                *((unsigned __int16 *)this + 6))
                            + *((unsigned __int8 *)this + 73)
                            - 1;
      *((_BYTE *)this + 74) = CGfxManager::GetObjectFrameCount(
                                (CGfxManager *)g_pGfxManager,
                                *((unsigned __int16 *)this + 19));
      v5 = IEntity::Y(this);
      v2 = IEntity::X(this);
      IDarkTribe::ChangeSurroundingToDarkLand((IDarkTribe *)g_pDarkTribe, v2, v5);
      IAnimatedEntity::RegisterForLogicUpdate(*((unsigned __int8 *)this + 74));
      break;
    case 3:
      v3 = IEntity::ID();
      CDecoObjMgr::Delete((CDecoObjMgr *)&g_cDecoObjMgr, v3);
      break;
    default:
      return;
  }
}


// address=[0x154ae90]
// Decompiled from void *__thiscall CShadowHerb::GetGfxInfos(CShadowHerb *this)
struct SGfxObjectInfo *  CShadowHerb::GetGfxInfos(void) {
  
  int TickCounter; // esi
  int v2; // eax
  int v4; // [esp+4h] [ebp-8h]

  TickCounter = CStateGame::GetTickCounter(g_pGame);
  v4 = TickCounter - IAnimatedEntity::LastUpdateTick(this);
  v2 = CStateGame::GetTickCounter(g_pGame);
  IAnimatedEntity::SetLastUpdateTick(this, v2);
  if ( v4 && *((_BYTE *)this + 73) != 1 && *((_BYTE *)this + 73) != 2 )
    *((_BYTE *)this + 36) = (v4 + (unsigned int)*((unsigned __int8 *)this + 36)) % *((unsigned __int8 *)this + 74);
  CGfxManager::GetObjectGfxInfo(
    (int)&IEntity::m_sGfxInfo,
    *((unsigned __int16 *)this + 19),
    *((unsigned __int8 *)this + 36),
    1);
  byte_40FE518 = 16;
  byte_40FE51A = IEntity::IsVisible(this);
  byte_40FE266 = 0;
  return &IEntity::m_sGfxInfo;
}


// address=[0x154af50]
// Decompiled from void __thiscall CShadowHerb::Decrease(CShadowHerb *this, int a2)
void  CShadowHerb::Decrease(int) {
  
  ;
}


// address=[0x154af60]
// Decompiled from int __thiscall CShadowHerb::Increase(CShadowHerb *this, int a2)
int  CShadowHerb::Increase(int) {
  
  return 1;
}


// address=[0x154af80]
// Decompiled from unsigned int __cdecl CShadowHerb::operator new(unsigned int a1)
static void * __cdecl CShadowHerb::operator new(unsigned int) {
  
  return CDecoObjMgr::Alloc((CDecoObjMgr *)&g_cDecoObjMgr, a1);
}


// address=[0x154afa0]
// Decompiled from void __cdecl CShadowHerb::operator delete(void *a1)
static void __cdecl CShadowHerb::operator delete(void *) {
  
  CDecoObjMgr::Dealloc((CDecoObjMgr *)&g_cDecoObjMgr, a1);
}


// address=[0x154afe0]
// Decompiled from int __thiscall CShadowHerb::ConvertToDarkOrGreen(CShadowHerb *this, bool a2)
int  CShadowHerb::ConvertToDarkOrGreen(bool) {
  
  return IEntity::Type((unsigned __int16 *)this);
}


// address=[0x154b000]
// Decompiled from _DWORD *__thiscall CShadowHerb::CShadowHerb(_DWORD *this, int a2)
 CShadowHerb::CShadowHerb(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IDecoObject::IDecoObject(a2);
  v6 = 0;
  *v5 = &CShadowHerb::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CShadowHerb");
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


// address=[0x154b100]
// Decompiled from int __thiscall CShadowHerb::Store(int *this, struct std::ostream *a2)
void  CShadowHerb::Store(std::ostream &) {
  
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


// address=[0x154b2f0]
// Decompiled from void __thiscall CShadowHerb::~CShadowHerb(CShadowHerb *this)
 CShadowHerb::~CShadowHerb(void) {
  
  *(_DWORD *)this = &CShadowHerb::_vftable_;
  IDecoObject::~IDecoObject(this);
}


// address=[0x154b3b0]
// Decompiled from int __thiscall CShadowHerb::ClassID(CShadowHerb *this)
unsigned long  CShadowHerb::ClassID(void)const {
  
  return CShadowHerb::m_iClassID;
}


// address=[0x3d8bb1c]
// [Decompilation failed for static unsigned long CShadowHerb::m_iClassID]

