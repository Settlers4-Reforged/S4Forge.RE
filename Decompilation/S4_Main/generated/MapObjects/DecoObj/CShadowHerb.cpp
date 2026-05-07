#if FALSE
#include "CShadowHerb.h"

// Definitions for class CShadowHerb

// address=[0x1401c60]
// Decompiled from CShadowHerb *__cdecl CShadowHerb::New(struct std::istream *a1)
class CPersistence * __cdecl CShadowHerb::New(std::istream & a1) {
  
  CShadowHerb *v3; // [esp+Ch] [ebp-10h]

  v3 = (CShadowHerb *)CShadowHerb::operator new(0x50u);
  if ( v3 )
    return CShadowHerb::CShadowHerb(v3, a1);
  else
    return 0;
}


// address=[0x154abc0]
// Decompiled from CShadowHerb *__thiscall CShadowHerb::CShadowHerb(  CShadowHerb *this,  unsigned int a2,  unsigned int a3,  int a4,  int a5,  int a6)
 CShadowHerb::CShadowHerb(int a2, int a3, int a4, int a5, int a6) {
  
  IDecoObject::IDecoObject(this, a2, a3, a4, a5, 0);
  this->__vftable = (IAnimatedEntity_vtbl *)&CShadowHerb::_vftable_;
  this->m_wJobPart = CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_nType);
  this->m_uU1 = 1;
  this->m_iPhases = 0;
  this->m_uCycleFrames = CGfxManager::GetObjectFrameCount(g_pGfxManager, this->m_wJobPart);
  this->m_uU5 = 0;
  if ( !this->m_uCycleFrames
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\ShadowHerb.cpp", 77, "m_uCycleFrames > 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uCycleFrames >= 0x20u
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\ShadowHerb.cpp", 78, "m_uCycleFrames < 32") == 1 )
  {
    __debugbreak();
  }
  IAnimatedEntity::RegisterForLogicUpdate(this, this->m_uCycleFrames);
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

  switch ( this->m_iPhases )
  {
    case 0u:
      ++this->m_iPhases;
      this->m_cFrame = 0;
      this->m_wJobPart = this->m_iPhases
                       + (unsigned __int16)CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_nType);
      this->m_uCycleFrames = CGfxManager::GetObjectFrameCount(g_pGfxManager, this->m_wJobPart);
      IAnimatedEntity::RegisterForLogicUpdate(this, 1);
      break;
    case 1u:
      if ( ++this->m_cFrame < (int)this->m_uCycleFrames )
      {
        IAnimatedEntity::RegisterForLogicUpdate(this, 1);
      }
      else
      {
        ++this->m_iPhases;
        v4 = IEntity::Y(this);
        v1 = IEntity::X(this);
        IDarkTribe::ChangeSurroundingToDarkLand((IDarkTribe *)g_pDarkTribe, v1, v4);
        --this->m_cFrame;
        IAnimatedEntity::RegisterForLogicUpdate(this, 31);
      }
      break;
    case 2u:
      ++this->m_iPhases;
      this->m_cFrame = 0;
      this->m_wJobPart = CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_nType) + this->m_iPhases - 1;
      this->m_uCycleFrames = CGfxManager::GetObjectFrameCount(g_pGfxManager, this->m_wJobPart);
      v5 = IEntity::Y(this);
      v2 = IEntity::X(this);
      IDarkTribe::ChangeSurroundingToDarkLand((IDarkTribe *)g_pDarkTribe, v2, v5);
      IAnimatedEntity::RegisterForLogicUpdate(this, this->m_uCycleFrames);
      break;
    case 3u:
      v3 = IEntity::ID(this);
      CDecoObjMgr::Delete(&g_cDecoObjMgr, v3);
      break;
    default:
      return;
  }
}


// address=[0x154ae90]
// Decompiled from struct SGfxObjectInfo *__thiscall CShadowHerb::GetGfxInfos(CShadowHerb *this)
struct SGfxObjectInfo *  CShadowHerb::GetGfxInfos(void) {
  
  int TickCounter; // esi
  DWORD v2; // eax
  int v4; // [esp+4h] [ebp-8h]

  TickCounter = CStateGame::GetTickCounter(g_pGame);
  v4 = TickCounter - IAnimatedEntity::LastUpdateTick(this);
  v2 = CStateGame::GetTickCounter(g_pGame);
  IAnimatedEntity::SetLastUpdateTick(this, v2);
  if ( v4 && this->m_iPhases != 1 && this->m_iPhases != 2 )
    this->m_cFrame = (v4 + (unsigned int)this->m_cFrame) % this->m_uCycleFrames;
  CGfxManager::GetObjectGfxInfo(g_pGfxManager, &IEntity::m_sGfxInfo, this->m_wJobPart, this->m_cFrame, 1);
  byte_40FE518 = 16;
  byte_40FE51A = IEntity::IsVisible(this);
  IEntity::m_sGfxInfo.m_uFlags = 0;
  return &IEntity::m_sGfxInfo;
}


// address=[0x154af50]
// Decompiled from void __thiscall CShadowHerb::Decrease(CShadowHerb *this, int a2)
void  CShadowHerb::Decrease(int a2) {
  
  ;
}


// address=[0x154af60]
// Decompiled from int __thiscall CShadowHerb::Increase(CShadowHerb *this, int a2)
int  CShadowHerb::Increase(int a2) {
  
  return 1;
}


// address=[0x154af80]
// Decompiled from uint __cdecl CShadowHerb::operator new(uint a1)
void * __cdecl CShadowHerb::operator new(unsigned int a1) {
  
  return CDecoObjMgr::Alloc(&g_cDecoObjMgr, a1);
}


// address=[0x154afa0]
// Decompiled from void __cdecl CShadowHerb::operator delete(uint *a1)
void __cdecl CShadowHerb::operator delete(void * a1) {
  
  CDecoObjMgr::Dealloc(&g_cDecoObjMgr, a1);
}


// address=[0x154afe0]
// Decompiled from int __thiscall CShadowHerb::ConvertToDarkOrGreen(IEntity *this, bool a2)
int  CShadowHerb::ConvertToDarkOrGreen(bool a2) {
  
  return IEntity::Type(this);
}


// address=[0x154b000]
// Decompiled from CShadowHerb *__thiscall CShadowHerb::CShadowHerb(CShadowHerb *this, struct std::istream *a1)
 CShadowHerb::CShadowHerb(std::istream & a2) {
  
  int fileFormatVersion; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  IDecoObject::IDecoObject(this, a1);
  v6 = 0;
  this->__vftable = (IAnimatedEntity_vtbl *)&CShadowHerb::_vftable_;
  operator^<unsigned int>(a1, &fileFormatVersion);
  if ( fileFormatVersion != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CShadowHerb");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<bool>(a1, &this->m_uU1);
  operator^<unsigned char>(a1, &this->m_iPhases);
  operator^<unsigned char>(a1, &this->m_uCycleFrames);
  operator^<int>(a1, &this->m_uU5);
  v6 = -1;
  return this;
}


// address=[0x154b100]
// Decompiled from void __thiscall CShadowHerb::Store(CShadowHerb *this, struct std::ostream *a1)
void  CShadowHerb::Store(std::ostream & a1) {
  
  int v2; // [esp+0h] [ebp-8h] BYREF
  CShadowHerb *v3; // [esp+4h] [ebp-4h]

  v3 = this;
  IDecoObject::Store(this, a1);
  v2 = 1;
  operator^<unsigned int>(a1, &v2);
  operator^<bool>(a1, &v3->m_uU1);
  operator^<unsigned char>(a1, &v3->m_iPhases);
  operator^<unsigned char>(a1, &v3->m_uCycleFrames);
  operator^<int>(a1, &v3->m_uU5);
}


// address=[0x154b2f0]
// Decompiled from int __thiscall CShadowHerb::~CShadowHerb(CShadowHerb *this)
 CShadowHerb::~CShadowHerb(void) {
  
  this->__vftable = (IAnimatedEntity_vtbl *)&CShadowHerb::_vftable_;
  return IDecoObject::~IDecoObject(this);
}


// address=[0x154b3b0]
// Decompiled from int __thiscall CShadowHerb::ClassID(CShadowHerb *this)
unsigned long  CShadowHerb::ClassID(void)const {
  
  return CShadowHerb::m_iClassID;
}


// address=[0x3d8bb1c]
// [Decompilation failed for static unsigned long CShadowHerb::m_iClassID]

#endif // Already implemented
