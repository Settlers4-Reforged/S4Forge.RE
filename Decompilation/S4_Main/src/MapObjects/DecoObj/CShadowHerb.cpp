#include "CShadowHerb.h"

#include "iostream"

#include "CDecoObjMgr.h"
#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"

// Definitions for class CShadowHerb

// address=[0x1401c60]
// Decompiled from CShadowHerb *__cdecl CShadowHerb::New(struct std::istream *a1)
class CPersistence * __cdecl CShadowHerb::New(std::istream &a1) {
  return new CShadowHerb(a1);
}


// address=[0x154abc0]
// Decompiled from CShadowHerb *__thiscall CShadowHerb::CShadowHerb(  CShadowHerb *this,  unsigned int a2,  unsigned int a3,  int a4,  int a5,  int a6)
CShadowHerb::CShadowHerb(int a2, int a3, int a4, int a5, int a6) : IDecoObject(a2, a3, a4, a5, 0) {
  this->m_iJobPart = g_pGfxManager->GetObjectFirstJob(this->m_iType);
  this->m_uU1 = 1;
  this->m_iPhases = 0;
  this->m_uCycleFrames = g_pGfxManager->GetObjectFrameCount(this->m_iJobPart);
  this->m_uU5 = 0;
  BB_ASSERT(m_uCycleFrames > 0)
  BB_ASSERT(m_uCycleFrames < 21)
  IAnimatedEntity::RegisterForLogicUpdate(this->m_uCycleFrames);
}


// address=[0x154ace0]
// Decompiled from void __thiscall CShadowHerb::LogicUpdate(CShadowHerb *this)
void CShadowHerb::LogicUpdate(void) {
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // [esp-4h] [ebp-Ch]
  int v5; // [esp-4h] [ebp-Ch]

  switch(this->m_iPhases) {
    case 0u:
      ++this->m_iPhases;
      this->m_iFrame = 0;
      this->m_iJobPart = this->m_iPhases
                         + (unsigned __int16) g_pGfxManager->GetObjectFirstJob(this->m_iType);
      this->m_uCycleFrames = g_pGfxManager->GetObjectFrameCount(this->m_iJobPart);
      IAnimatedEntity::RegisterForLogicUpdate(1);
      break;
    case 1u:
      if(++this->m_iFrame < (int) this->m_uCycleFrames) {
        IAnimatedEntity::RegisterForLogicUpdate(1);
      } else {
        ++this->m_iPhases;
        g_pDarkTribe->ChangeSurroundingToDarkLand(X(), Y());
        --this->m_iFrame;
        IAnimatedEntity::RegisterForLogicUpdate(31);
      }
      break;
    case 2u:
      ++this->m_iPhases;
      this->m_iFrame = 0;
      this->m_iJobPart = g_pGfxManager->GetObjectFirstJob(this->m_iType) + this->m_iPhases - 1;
      this->m_uCycleFrames = g_pGfxManager->GetObjectFrameCount(this->m_iJobPart);

      g_pDarkTribe->ChangeSurroundingToDarkLand(v2, v5);
      IAnimatedEntity::RegisterForLogicUpdate(this->m_uCycleFrames);
      break;
    case 3u:
      g_cDecoObjMgr.Delete(ID());
      break;
    default:
      return;
  }
}


// address=[0x154ae90]
// Decompiled from struct SGfxObjectInfo *__thiscall CShadowHerb::GetGfxInfos(CShadowHerb *this)
struct SGfxObjectInfo *CShadowHerb::GetGfxInfos(void) {
  int   TickCounter; // esi
  DWORD v2; // eax
  int   v4; // [esp+4h] [ebp-8h]

  TickCounter = g_pGame->GetTickCounter();
  v4 = TickCounter - IAnimatedEntity::LastUpdateTick();
  v2 = g_pGame->GetTickCounter();
  IAnimatedEntity::SetLastUpdateTick(v2);
  if(v4 && this->m_iPhases != 1 && this->m_iPhases != 2)
    this->m_iFrame = (v4 + (unsigned int) this->m_iFrame) % this->m_uCycleFrames;
  g_pGfxManager->GetObjectGfxInfo(&IEntity::m_sGfxInfo, this->m_iJobPart, this->m_iFrame, 1);
  byte_40FE518 = 16;
  byte_40FE51A = IEntity::IsVisible();
  IEntity::m_sGfxInfo.m_uFlags = 0;
  return &IEntity::m_sGfxInfo;
}


// address=[0x154af50]
// Decompiled from void __thiscall CShadowHerb::Decrease(CShadowHerb * int a2)
void CShadowHerb::Decrease(int a2) {
  ;
}


// address=[0x154af60]
// Decompiled from int __thiscall CShadowHerb::Increase(CShadowHerb * int a2)
int CShadowHerb::Increase(int a2) {
  return 1;
}


// address=[0x154af80]
// Decompiled from uint __cdecl CShadowHerb::operator new(uint a1)
void * __cdecl CShadowHerb::operator new(unsigned int a1) {
  return g_cDecoObjMgr.Alloc(a1);
}


// address=[0x154afa0]
// Decompiled from void __cdecl CShadowHerb::operator delete(uint *a1)
void __cdecl CShadowHerb::operator delete(void *a1) {
  g_cDecoObjMgr.Dealloc(a1);
}


// address=[0x154afe0]
// Decompiled from int __thiscall CShadowHerb::ConvertToDarkOrGreen(IEntity * bool a2)
int CShadowHerb::ConvertToDarkOrGreen(bool a2) {
  return IEntity::Type();
}


// address=[0x154b000]
// Decompiled from CShadowHerb *__thiscall CShadowHerb::CShadowHerb(CShadowHerb * struct std::istream *a1)
CShadowHerb::CShadowHerb(std::istream &a2) : IDecoObject(a2) {
  int fileFormatVersion; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  v6 = 0;

  a2 >> fileFormatVersion;
  if(fileFormatVersion != 1) {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CShadowHerb");
    throw CS4InvalidMapException();
  }
  a2 >> this->m_uU1;
  a2 >> this->m_iPhases;
  a2 >> this->m_uCycleFrames;
  a2 >> this->m_uU5;
  v6 = -1;
}


// address=[0x154b100]
// Decompiled from void __thiscall CShadowHerb::Store(CShadowHerb * struct std::ostream *a1)
void CShadowHerb::Store(std::ostream &a1) {
  int          v2; // [esp+0h] [ebp-8h] BYREF
  CShadowHerb *v3; // [esp+4h] [ebp-4h]
  IDecoObject::Store(a1);
  v2 = 1;
  a1 << v2;
  a1 << this->m_uU1;
  a1 << this->m_iPhases;
  a1 << this->m_uCycleFrames;
  a1 << this->m_uU5;
}


// address=[0x154b2f0]
// Decompiled from int __thiscall CShadowHerb::~CShadowHerb(CShadowHerb *this)
CShadowHerb::~CShadowHerb(void) = default


// address=[0x154b3b0]
// Decompiled from int __thiscall CShadowHerb::ClassID(CShadowHerb *this)
unsigned long CShadowHerb::ClassID(void) const {
  return CShadowHerb::m_iClassID;
}


// address=[0x3d8bb1c]
// [Decompilation failed for static unsigned long CShadowHerb::m_iClassID]
