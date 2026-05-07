#include "CHive.h"

#include <iostream>

#include "CDecoObjMgr.h"
#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "Main/CGameStateHandler.h"
#include "MapObjects/CSpiralOffsets.h"
#include "World/CWorldManager.h"

// Definitions for class CHive

// address=[0x15488d0]
// Decompiled from CHive *__thiscall CHive::CHive(  CHive *this,  unsigned int _iX,  unsigned int _iY,  int _iDecoObjectType,  int _iId,  int _iPhases)
CHive::CHive(int _iX, int _iY, int _iDecoObjectType, int _iId, int _iPhases) : IDecoObject(_iX, _iY, _iDecoObjectType, _iId, _iPhases != 0) {
  BB_ASSERT(_iPhases == CDecoObjMgr::GROW1)
  this->m_uU6 = 406;
  this->m_uU1 = 1;
  this->m_iPhases = _iPhases;
  this->m_uU5 = 0;
  if(this->IsFlowerInSurrounding()) {
    ++this->m_iPhases;
    this->m_wJobPart = g_pGfxManager->GetObjectFirstJob(this->m_nType);
  } else {
    this->m_wJobPart = g_pGfxManager->GetObjectFirstJob(this->m_nType) + 1;
  }
  this->m_uCycleFrames = g_pGfxManager->GetObjectFrameCount(this->m_wJobPart);
  BB_ASSERT(m_uCycleFrames)
  IAnimatedEntity::RegisterForLogicUpdate(31);
  this->m_cFrame = 0;
}


// address=[0x1548a60]
// Decompiled from CHive *__thiscall CHive::CHive(CHive *this, const struct CHive *a2, int a3, unsigned int a4, unsigned int a5)
CHive::CHive(class CHive const &_rTarget, int a3, int _iX, int _iY) : IDecoObject(_rTarget, a3, _iX, _iY) {
  this->m_uU5 = 0;
  this->m_iPhases = _rTarget.m_iPhases;
  this->m_wJobPart = _rTarget.m_wJobPart;
  this->m_uCycleFrames = _rTarget.m_uCycleFrames;
  BB_ASSERT(m_uCycleFrames)
  this->m_uU6 = _rTarget.m_uU6;
  this->m_cFrame = _rTarget.m_cFrame;
  this->m_uU1 = 1;
}

// address=[0x1548b50]
// Decompiled from int __thiscall CHive::~CHive(CHive *this)
CHive::~CHive(void) = default;


// address=[0x1548b70]
// Decompiled from void __thiscall CHive::LogicUpdate(CHive *this)
void CHive::LogicUpdate(void) {
  unsigned int m_cFrame; // esi
  int          v2; // eax
  // [esp+8h] [ebp-8h]

  int v3 = 1;
  if(this->IsFlowerInSurrounding())
    v3 = 3;
  switch(this->m_iPhases) {
    case 0u:
      this->m_uU5 += v3;
      if(this->m_uU5 >= 20) {
        this->m_uU5 = 0;
        ++this->m_iPhases;
        this->m_wJobPart = g_pGfxManager->GetObjectFirstJob(this->m_nType);
        this->m_uCycleFrames = g_pGfxManager->GetObjectFrameCount(this->m_wJobPart);
      }
      goto LABEL_24;
    case 1u:
      this->m_uU5 += v3;
      if(this->m_uU5 >= 20) {
        this->m_uU5 = 0;
        ++this->m_iPhases;
      }
      goto LABEL_24;
    case 2u:
      this->m_uU5 += v3;
      if(this->m_uU5 >= 20) {
        this->m_uU5 = 0;
        ++this->m_iPhases;
        this->m_cFrame = 0;
        this->m_wJobPart = g_pGfxManager->GetObjectFirstJob(this->m_nType) + 1;
        this->m_uCycleFrames = g_pGfxManager->GetObjectFrameCount(this->m_wJobPart);
        this->ClearFlagBits(EntityFlag_Ready);
      }
      goto LABEL_24;
    case 3u:
      if(--this->m_uU6 <= 0) {
        this->ClearFlagBits(EntityFlag_Ready);
        ++this->m_iPhases;
        this->m_cFrame = 0;
        this->m_wJobPart = CGfxManager::GetObjectFirstJob(this->m_nType) + 2;
        this->m_uCycleFrames = CGfxManager::GetObjectFrameCount(this->m_wJobPart);
        BB_ASSERT(m_uCycleFrames)
      }
      goto LABEL_24;
    case 4u:
      if(++this->m_uU5 >= 20) {
        this->m_uU5 = 0;
        ++this->m_iPhases;
        this->m_cFrame = 0;
        this->m_wJobPart = g_pGfxManager->GetObjectFirstJob(this->m_nType) + 3;
        this->m_uCycleFrames = g_pGfxManager->GetObjectFrameCount(this->m_wJobPart);
      }
      goto LABEL_24;
    case 5u:
      if(++this->m_uU5 < 20
         || (this->m_uU5 = 0,
             ++this->m_cFrame,
             m_cFrame = this->m_cFrame,
             m_cFrame < g_pGfxManager->GetObjectFrameCount(this->m_wJobPart))) {
      LABEL_24:
        IAnimatedEntity::RegisterForLogicUpdate(31);
      } else {
        g_cDecoObjMgr.Delete(IEntity::ID());
      }
      break;
    default:
      return;
  }
}


// address=[0x1548eb0]
// Decompiled from struct SGfxObjectInfo *__thiscall CHive::GetGfxInfos(CHive *this)
struct SGfxObjectInfo *CHive::GetGfxInfos(void) {
  // esi
  // eax
  // [esp+4h] [ebp-8h]

  int TickCounter = g_pGame->GetTickCounter();
  int v4 = TickCounter - this->LastUpdateTick();
  int v2 = g_pGame->GetTickCounter();
  this->SetLastUpdateTick(v2);
  if(v4)
    this->m_cFrame = (v4 + (unsigned int) this->m_cFrame) % this->m_uCycleFrames;
  g_pGfxManager->GetObjectGfxInfo(&IEntity::m_sGfxInfo, this->m_wJobPart, this->m_cFrame, 1);
  byte_40FE518 = 16;
  byte_40FE51A = this->IsVisible();
  IEntity::m_sGfxInfo.m_uFlags = 0;
  return &IEntity::m_sGfxInfo;
}


// address=[0x1548f50]
// Decompiled from int __thiscall CHive::Decrease(CHive *this, int a2)
void CHive::Decrease(int a2) {
  BB_ASSERT(IsStaticInstance() == false)

  if(g_pGameData->Rand() <= 0x1000) {
    IAnimatedEntity::RegisterForLogicUpdate(31);
    return;
  }
  IEntity::ClearFlagBits(EntityFlag_Ready);
  if(CHive::IsFlowerInSurrounding()) {
    this->m_iPhases = 1;
    this->m_cFrame = 0;
    this->m_wJobPart = g_pGfxManager->GetObjectFirstJob(this->m_nType);
  } else {
    this->m_iPhases = 0;
    this->m_cFrame = 0;
    this->m_wJobPart = g_pGfxManager->GetObjectFirstJob(this->m_nType) + 1;
  }
  this->m_uCycleFrames = g_pGfxManager->GetObjectFrameCount(this->m_wJobPart);
}


// address=[0x1549060]
// Decompiled from int __thiscall CHive::Increase(CHive *this, int a2)
int CHive::Increase(int a2) {
  return 1;
}


// address=[0x1549080]
// Decompiled from uint __cdecl CHive::operator new(uint a1)
void * __cdecl CHive::operator new(unsigned int a1) {
  return g_cDecoObjMgr.Alloc(a1);
}


// address=[0x15490a0]
// Decompiled from void __cdecl CHive::operator delete(uint *a1)
void __cdecl CHive::operator delete(void *a1) {
  g_cDecoObjMgr.Dealloc(a1);
}


// address=[0x15490e0]
// Decompiled from char __thiscall CHive::IsFlowerInSurrounding(CHive *this)
bool CHive::IsFlowerInSurrounding(void) {
  int v10 = CSpiralOffsets::First(2);
  for(int i = v10; i < v10 + 80; ++i) {
    unsigned int v7 = CSpiralOffsets::DeltaX(i) + IEntity::X();
    unsigned int v8 = CSpiralOffsets::DeltaY(i) + IEntity::Y();
    if(CWorldManager::InWorld(v7, v8)) {
      int      v5 = CWorldManager::ObjectId(v7, v8);
      IEntity *pTarget = CDecoObjMgr::GetDecoObjPtr(v5);
      if(pTarget) {
        if(g_cDecoObjMgr.IsFlower(pTarget->Type()))
          return 1;
      }
    }
  }
  return 0;
}


// address=[0x15491c0]
// Decompiled from CHive *__thiscall CHive::CHive(CHive *this, struct std::istream *a1)
CHive::CHive(std::istream &_rStream) : IDecoObject(_rStream) {
  int fileFormatVersion; // [esp+8h] [ebp-18h] BYREF
  _rStream >> fileFormatVersion;
  if(fileFormatVersion != 1) {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CHive");
    throw CS4InvalidMapException();
  }
  _rStream >> this->m_uU1;
  _rStream >> this->m_iPhases;
  _rStream >> this->m_uCycleFrames;
  _rStream >> this->m_uU5;
  _rStream >> this->m_uU6;
}


// address=[0x15492d0]
// Decompiled from void __thiscall CHive::Store(CHive *this, struct std::ostream *a1)
void CHive::Store(std::ostream &a1) {
  // [esp+0h] [ebp-8h] BYREF

  IDecoObject::Store(a1);
  unsigned int v2 = 1;
  a1 << v2;
  a1 << this->m_uU1;
  a1 << this->m_iPhases;
  a1 << this->m_uCycleFrames;
  a1 << this->m_uU5;
  a1 << this->m_uU6;
}


// address=[0x1549670]
// Decompiled from int __thiscall CHive::ClassID(CHive *this)
unsigned long CHive::ClassID(void) const {
  return CHive::m_iClassID;
}


// address=[0x3d8bb10]
// [Decompilation failed for static unsigned long CHive::m_iClassID]

