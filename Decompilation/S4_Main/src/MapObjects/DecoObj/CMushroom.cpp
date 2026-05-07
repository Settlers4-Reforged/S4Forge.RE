#include "CMushroom.h"

#include <iostream>

#include "CDecoObjMgr.h"
#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "Main/CGameStateHandler.h"

// Definitions for class CMushroom

// address=[0x1549690]
// Decompiled from CMushroom *__thiscall CMushroom::CMushroom(CMushroom *this, unsigned int a2, unsigned int a3, int a4, int a5, int a6)
CMushroom::CMushroom(int a2, int a3, int a4, int a5, int a6) : IDecoObject(a2, a3, a4, a5, a6 != 0) {
  this->m_uU1 = 1;
  this->m_iPhases = a6;
  this->m_uU0 = 0;
  this->m_wJobPart = this->m_iPhases + (unsigned __int16) g_pGfxManager->GetObjectFirstJob(this->m_nType);
  this->m_uCycleFrames = g_pGfxManager->GetObjectFrameCount(this->m_wJobPart);
  BB_ASSERT(m_uCycleFrames)

  if(this->m_iPhases) {
    this->m_cFrame = g_pGame->Rand() % this->m_uCycleFrames;
    IEntity::SetFlagBits(EntityFlag_Ready);
  } else {
    IAnimatedEntity::RegisterForLogicUpdate(31);
    this->m_cFrame = 0;
  }
  return this;
}


// address=[0x15497e0]
// Decompiled from CMushroom *__thiscall CMushroom::CMushroom(  CMushroom *this,  const struct CMushroom *a2,  int a3,  unsigned int a4,  unsigned int a5)
CMushroom::CMushroom(class CMushroom const &a2, int a3, int a4, int a5) : IDecoObject(a2, a3, a4, a5) {
  this->m_uU0 = 0;
  this->m_iPhases = 3;
  this->m_wJobPart = this->m_iPhases + (unsigned __int16) g_pGfxManager->GetObjectFirstJob(this->m_nType);
  this->m_uCycleFrames = a2.m_uCycleFrames;
  BB_ASSERT(this->m_uCycleFrames)

  this->m_cFrame = a2.m_cFrame;
  this->m_uU1 = 1;
}


// address=[0x15498d0]
// Decompiled from int __thiscall CMushroom::~CMushroom(CMushroom *this)
CMushroom::~CMushroom(void) = default;


// address=[0x15498f0]
// Decompiled from void __thiscall CMushroom::LogicUpdate(CMushroom *this)
void CMushroom::LogicUpdate(void) {
  unsigned int v1; // eax
  unsigned int m_cFrame; // esi
  int          v3; // eax
  unsigned int v4; // [esp-Ch] [ebp-18h]


  switch(this->m_iPhases) {
    case 0u:
    case 1u:
    case 2u:
      if(++this->m_uU0 < 5)
        goto LABEL_10;
      this->m_uU0 = 0;
      ++this->m_iPhases;
      this->m_wJobPart = this->m_iPhases
                         + (unsigned __int16) g_pGfxManager->GetObjectFirstJob(this->m_nType);
      if(this->m_iPhases != 3)
        goto LABEL_10;

      g_cDecoObjMgr.ChangeToStaticInstance(X(), Y(), IEntity::Type(), 0);
      break;
    case 3u:
      ++this->m_uU0;
      this->m_uU0 = 0;
      IAnimatedEntity::RegisterForLogicUpdate(31);
      break;
    case 4u:
      if(++this->m_uU0 < 5
         || (this->m_uU0 = 0,
             ++this->m_cFrame,
             m_cFrame = this->m_cFrame,
             m_cFrame < g_pGfxManager->GetObjectFrameCount(this->m_wJobPart))) {
      LABEL_10:
        IAnimatedEntity::RegisterForLogicUpdate(this, 31);
      } else {
        v3 = IEntity::ID(this);
        CDecoObjMgr::Delete(&g_cDecoObjMgr, v3);
      }
      break;
    default:
      return;
  }
}


// address=[0x1549a60]
// Decompiled from struct SGfxObjectInfo *__thiscall CMushroom::GetGfxInfos(CMushroom *this)
struct SGfxObjectInfo *CMushroom::GetGfxInfos(void) {
  int   TickCounter; // esi
  DWORD v2; // eax
  int   v4; // [esp+4h] [ebp-8h]

  TickCounter = g_pGame->GetTickCounter();
  v4 = TickCounter - IAnimatedEntity::LastUpdateTick();
  v2 = g_pGame->GetTickCounter();
  IAnimatedEntity::SetLastUpdateTick(v2);
  if(v4)
    this->m_cFrame = (v4 + (unsigned int) this->m_cFrame) % this->m_uCycleFrames;
  g_pGfxManager->GetObjectGfxInfo(&IEntity::m_sGfxInfo, this->m_wJobPart, this->m_cFrame, 1);
  byte_40FE518 = 16;
  byte_40FE51A = IEntity::IsVisible();
  IEntity::m_sGfxInfo.m_uFlags = 0;
  return &IEntity::m_sGfxInfo;
}


// address=[0x1549b00]
// Decompiled from int __thiscall CMushroom::Decrease(CMushroom *this, int a2)
void CMushroom::Decrease(int a2) {
  BB_ASSERT(IsStaticInstance() == false)
  IEntity::ClearFlagBits(EntityFlag_Ready);
  ++this->m_iPhases;
  this->m_cFrame = 0;
  this->m_wJobPart = this->m_iPhases + (unsigned __int16) g_pGfxManager->GetObjectFirstJob(this->m_nType);
  this->m_uCycleFrames = g_pGfxManager->GetObjectFrameCount(this->m_wJobPart);
  BB_ASSERT(this->m_uCycleFrames)
  this->m_uU0 = 0;
  IAnimatedEntity::RegisterForLogicUpdate(31);
}


// address=[0x1549be0]
// Decompiled from int __thiscall CMushroom::Increase(CMushroom *this, int a2)
int CMushroom::Increase(int a2) {
  return 1;
}


// address=[0x1549c00]
// Decompiled from uint __cdecl CMushroom::operator new(uint a1)
void * __cdecl CMushroom::operator new(unsigned int a1) {
  return g_cDecoObjMgr.Alloc(a1);
}


// address=[0x1549c20]
// Decompiled from void __cdecl CMushroom::operator delete(uint *a1)
void __cdecl CMushroom::operator delete(void *a1) {
  g_cDecoObjMgr.Dealloc(a1);
}


// address=[0x1549c60]
// Decompiled from CMushroom *__thiscall CMushroom::CMushroom(CMushroom *this, struct std::istream *a1)
CMushroom::CMushroom(std::istream &a1) : IDecoObject(a1) {
  int fileFormatVersion; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]


  a1 >> fileFormatVersion;
  if(fileFormatVersion != 1) {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CMushroom");
    pExceptionObject = 0;
    throw CS4InvalidMapException();
  }
  a1 >> this->m_uU1;
  a1 >> this->m_iPhases;
  a1 >> this->m_uCycleFrames;
  a1 >> this->m_uU0;
}


// address=[0x1549d60]
// Decompiled from void __thiscall CMushroom::Store(CMushroom *this, struct std::ostream *a1)
void CMushroom::Store(std::ostream &a1) {
  int v2; // [esp+0h] [ebp-8h] BYREF

  IDecoObject::Store(a1);
  v2 = 1;
  a1 << v2;
  a1 << this->m_uU1;
  a1 << this->m_iPhases;
  a1 << this->m_uCycleFrames;
  a1 << this->m_uU0;
}


// address=[0x154a020]
// Decompiled from int __thiscall CMushroom::ClassID(CMushroom *this)
unsigned long CMushroom::ClassID(void) const {
  return CMushroom::m_iClassID;
}


// address=[0x3d8bb14]
// [Decompilation failed for static unsigned long CMushroom::m_iClassID]

