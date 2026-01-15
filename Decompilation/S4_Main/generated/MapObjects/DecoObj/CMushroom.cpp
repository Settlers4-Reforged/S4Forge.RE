#include "CMushroom.h"

// Definitions for class CMushroom

// address=[0x1549690]
// Decompiled from CMushroom *__thiscall CMushroom::CMushroom(CMushroom *this, int a2, int a3, int a4, int a5, int a6)
 CMushroom::CMushroom(int,int,int,int,int) {
  
  IDecoObject::IDecoObject(this, a2, a3, a4, a5, a6 != 0);
  *(_DWORD *)this = &CMushroom::_vftable_;
  *((_BYTE *)this + 72) = 1;
  *((_BYTE *)this + 73) = a6;
  *((_DWORD *)this + 19) = 0;
  *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73)
                        + (unsigned __int16)CGfxManager::GetObjectFirstJob(
                                              (CGfxManager *)g_pGfxManager,
                                              *((unsigned __int16 *)this + 6));
  *((_BYTE *)this + 74) = CGfxManager::GetObjectFrameCount(
                            (CGfxManager *)g_pGfxManager,
                            *((unsigned __int16 *)this + 19));
  if ( !*((_BYTE *)this + 74) && BBSupportDbgReport(2, "MapObjects\\DecoObj\\Mushroom.cpp", 82, "m_uCycleFrames") == 1 )
    __debugbreak();
  if ( *((_BYTE *)this + 73) )
  {
    *((_BYTE *)this + 36) = CStateGame::Rand(g_pGame) % (unsigned int)*((unsigned __int8 *)this + 74);
    IEntity::SetFlagBits(this, (EntityFlag)((char *)&loc_1FFFFFF + 1));
  }
  else
  {
    IAnimatedEntity::RegisterForLogicUpdate(31);
    *((_BYTE *)this + 36) = 0;
  }
  return this;
}


// address=[0x15497e0]
// Decompiled from CMushroom *__thiscall CMushroom::CMushroom(CMushroom *this, const struct CMushroom *a2, int a3, int a4, int a5)
 CMushroom::CMushroom(class CMushroom const &,int,int,int) {
  
  IDecoObject::IDecoObject(this, a2, a3, a4, a5);
  *(_DWORD *)this = &CMushroom::_vftable_;
  *((_DWORD *)this + 19) = 0;
  *((_BYTE *)this + 73) = 3;
  *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73)
                        + (unsigned __int16)CGfxManager::GetObjectFirstJob(
                                              (CGfxManager *)g_pGfxManager,
                                              *((unsigned __int16 *)this + 6));
  *((_BYTE *)this + 74) = *((_BYTE *)a2 + 74);
  if ( !*((_BYTE *)this + 74) && BBSupportDbgReport(2, "MapObjects\\DecoObj\\Mushroom.cpp", 129, "m_uCycleFrames") == 1 )
    __debugbreak();
  *((_BYTE *)this + 36) = *((_BYTE *)a2 + 36);
  *((_BYTE *)this + 72) = 1;
  return this;
}


// address=[0x15498d0]
// Decompiled from void __thiscall CMushroom::~CMushroom(CMushroom *this)
 CMushroom::~CMushroom(void) {
  
  *(_DWORD *)this = &CMushroom::_vftable_;
  IDecoObject::~IDecoObject(this);
}


// address=[0x15498f0]
// Decompiled from void __thiscall CMushroom::LogicUpdate(CMushroom *this)
void  CMushroom::LogicUpdate(void) {
  
  int v1; // eax
  unsigned int v2; // esi
  int v3; // eax
  int v4; // [esp-Ch] [ebp-18h]
  int v5; // [esp-8h] [ebp-14h]

  switch ( *((_BYTE *)this + 73) )
  {
    case 0:
    case 1:
    case 2:
      if ( (int)++*((_DWORD *)this + 19) < 5 )
        goto LABEL_10;
      *((_DWORD *)this + 19) = 0;
      ++*((_BYTE *)this + 73);
      *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73)
                            + (unsigned __int16)CGfxManager::GetObjectFirstJob(
                                                  (CGfxManager *)g_pGfxManager,
                                                  *((unsigned __int16 *)this + 6));
      if ( *((_BYTE *)this + 73) != 3 )
        goto LABEL_10;
      v5 = IEntity::Type((unsigned __int16 *)this);
      v4 = IEntity::Y(this);
      v1 = IEntity::X(this);
      CDecoObjMgr::ChangeToStaticInstance((CDecoObjMgr *)&g_cDecoObjMgr, v1, v4, v5, 0);
      break;
    case 3:
      ++*((_DWORD *)this + 19);
      *((_DWORD *)this + 19) = 0;
      IAnimatedEntity::RegisterForLogicUpdate(31);
      break;
    case 4:
      if ( (int)++*((_DWORD *)this + 19) < 5
        || (*((_DWORD *)this + 19) = 0,
            ++*((_BYTE *)this + 36),
            v2 = *((unsigned __int8 *)this + 36),
            v2 < CGfxManager::GetObjectFrameCount((CGfxManager *)g_pGfxManager, *((unsigned __int16 *)this + 19))) )
      {
LABEL_10:
        IAnimatedEntity::RegisterForLogicUpdate(31);
      }
      else
      {
        v3 = IEntity::ID();
        CDecoObjMgr::Delete((CDecoObjMgr *)&g_cDecoObjMgr, v3);
      }
      break;
    default:
      return;
  }
}


// address=[0x1549a60]
// Decompiled from void *__thiscall sub_1949A60(int this)
struct SGfxObjectInfo *  CMushroom::GetGfxInfos(void) {
  
  int v1; // esi
  int v2; // eax
  int v4; // [esp+4h] [ebp-8h]

  v1 = CStateGame::GetTickCounter(g_pGame);
  v4 = v1 - IAnimatedEntity::LastUpdateTick(this);
  v2 = CStateGame::GetTickCounter(g_pGame);
  IAnimatedEntity::SetLastUpdateTick((CMFCCaptionButton *)this, v2);
  if ( v4 )
    *(_BYTE *)(this + 36) = (v4 + (unsigned int)*(unsigned __int8 *)(this + 36)) % *(unsigned __int8 *)(this + 74);
  CGfxManager::GetObjectGfxInfo(
    &IEntity::m_sGfxInfo,
    *(unsigned __int16 *)(this + 38),
    *(unsigned __int8 *)(this + 36),
    1);
  byte_40FE518 = 16;
  byte_40FE51A = IEntity::IsVisible((void *)this);
  byte_40FE266 = 0;
  return &IEntity::m_sGfxInfo;
}


// address=[0x1549b00]
// Decompiled from int __thiscall CMushroom::Decrease(CMushroom *this, int a2)
void  CMushroom::Decrease(int) {
  
  if ( IDecoObject::IsStaticInstance(this)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\Mushroom.cpp", 335, "IsStaticInstance() == false") == 1 )
  {
    __debugbreak();
  }
  IEntity::ClearFlagBits(this, (EntityFlag)((char *)&loc_1FFFFFF + 1));
  ++*((_BYTE *)this + 73);
  *((_BYTE *)this + 36) = 0;
  *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73)
                        + (unsigned __int16)CGfxManager::GetObjectFirstJob(
                                              (CGfxManager *)g_pGfxManager,
                                              *((unsigned __int16 *)this + 6));
  *((_BYTE *)this + 74) = CGfxManager::GetObjectFrameCount(
                            (CGfxManager *)g_pGfxManager,
                            *((unsigned __int16 *)this + 19));
  if ( !*((_BYTE *)this + 74) && BBSupportDbgReport(2, "MapObjects\\DecoObj\\Mushroom.cpp", 345, "m_uCycleFrames") == 1 )
    __debugbreak();
  *((_DWORD *)this + 19) = 0;
  return IAnimatedEntity::RegisterForLogicUpdate(31);
}


// address=[0x1549be0]
// Decompiled from int __thiscall CMushroom::Increase(CMushroom *this, int a2)
int  CMushroom::Increase(int) {
  
  return 1;
}


// address=[0x1549c00]
// Decompiled from unsigned int __cdecl CMushroom::operator new(unsigned int a1)
static void * __cdecl CMushroom::operator new(unsigned int) {
  
  return CDecoObjMgr::Alloc((CDecoObjMgr *)&g_cDecoObjMgr, a1);
}


// address=[0x1549c20]
// Decompiled from void __cdecl CMushroom::operator delete(void *a1)
static void __cdecl CMushroom::operator delete(void *) {
  
  CDecoObjMgr::Dealloc((CDecoObjMgr *)&g_cDecoObjMgr, a1);
}


// address=[0x1549c60]
// Decompiled from _DWORD *__thiscall CMushroom::CMushroom(_DWORD *this, int a2)
 CMushroom::CMushroom(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IDecoObject::IDecoObject(a2);
  v6 = 0;
  *v5 = &CMushroom::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CMushroom");
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


// address=[0x1549d60]
// Decompiled from int __thiscall CMushroom::Store(int *this, struct std::ostream *a2)
void  CMushroom::Store(std::ostream &) {
  
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


// address=[0x154a020]
// Decompiled from int __thiscall CMushroom::ClassID(CMushroom *this)
unsigned long  CMushroom::ClassID(void)const {
  
  return CMushroom::m_iClassID;
}


// address=[0x3d8bb14]
// [Decompilation failed for static unsigned long CMushroom::m_iClassID]

