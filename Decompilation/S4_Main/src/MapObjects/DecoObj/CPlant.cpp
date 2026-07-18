#include "CPlant.h"

#include <iostream>

#include "CDecoObjMgr.h"
#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "CConfigManager/Var/CStaticConfigVarInt.h"
#include "Defines/Object.h"
#include "Main/CGameStateHandler.h"

// Definitions for class CPlant

// address=[0x14016c0]
// Decompiled from CPlant *__cdecl CPlant::New(int a1)
class CPersistence * __cdecl CPlant::New(std::istream &a1) {
  return new CPlant(a1);
}


// address=[0x154a040]
// Decompiled from CPlant *__thiscall CPlant::CPlant(  CPlant *this,  unsigned int a2,  unsigned int a3,  T_OBJECT_TYPE a4,  int a5,  BYTE _iGoodType,  int a7)
CPlant::CPlant(int a2, int a3, int a4, int a5, int _iGoodType, int _iStage) : IDecoObject(a2, a3, a4, a5, _iStage != 0) {
  this->m_uU1 = 1;
  this->m_uStage = _iStage;
  this->m_iGoodType = _iGoodType;
  this->m_uU5 = 0;
  this->m_iJobPart = this->m_uStage + (unsigned __int16) g_pGfxManager->GetObjectFirstJob(this->m_iType);
  this->m_uCycleFrames = g_pGfxManager->GetObjectFrameCount(this->m_iJobPart);
  BB_ASSERT(m_uCycleFrames)
  if(IDecoObject::IsStaticInstance()) {
    this->m_iFrame = g_pGame->Rand() % this->m_uCycleFrames;
    IEntity::SetFlagBits(ENTITY_FLAG_Ready);
  } else {
    IAnimatedEntity::RegisterForLogicUpdate(31);
  }
}


// address=[0x154a1a0]
// Decompiled from CPlant *__thiscall CPlant::CPlant(CPlant *this, const struct CPlant *a2, int a3, int a4, int a5)
CPlant::CPlant(class CPlant const &a2, int a3, int a4, int a5) : IDecoObject(a2, a3, a4, a5) {
  this->m_uU5 = 0;
  IEntity::SetFlagBits(ENTITY_FLAG_Ready);
  this->m_uStage = 3;
  this->m_iJobPart = this->m_uStage + (unsigned __int16) g_pGfxManager->GetObjectFirstJob(this->m_iType);
  this->m_uCycleFrames = a2.m_uCycleFrames;
  BB_ASSERT(m_uCycleFrames)
  this->m_iFrame = a2.m_iFrame;
  this->m_uU1 = 1;
  this->m_iGoodType = a2.m_iGoodType;
}


// address=[0x154a2a0]
// Decompiled from void __thiscall CPlant::~CPlant(CPlant *this)
CPlant::~CPlant(void) = default;


// address=[0x154a2c0]
// Decompiled from void __thiscall CPlant::LogicUpdate(CPlant *this)
void CPlant::LogicUpdate(void) {
  int          v2; // eax
  unsigned int m_cFrame; // esi

  switch(this->m_uStage) {
    case 0u:
    case 1u:
    case 2u:
      if(++this->m_uU5 >= 30
         && (this->m_uU5 = 0,
             ++this->m_uStage,
             this->m_iJobPart = this->m_uStage
                                + (unsigned __int16) g_pGfxManager->GetObjectFirstJob(this->m_iType),
             this->m_uStage == 3)) {
        IEntity::SetFlagBits(ENTITY_FLAG_Ready);
        g_cDecoObjMgr.ChangeToStaticInstance(X(), Y(), Type(), 0);
      } else {
        if(!IEntity::FlagBits((EntityFlag) 0x100000))
          goto LABEL_14;
        v2 = CStaticConfigVarInt::operator int(g_pMagicFasterCropsDecrease256);
        IAnimatedEntity::RegisterForLogicUpdate((31 * v2 + 127) >> 8);
      }
      break;
    case 4u:
    case 5u:
      if(++this->m_uU5 >= 30
         && (this->m_iType == OBJECT_WHEAT1
             || this->m_iType == OBJECT_WHEAT2
             || (this->m_uU5 = 0,
                 ++this->m_iFrame,
                 m_cFrame = this->m_iFrame,
                 m_cFrame >= g_pGfxManager->GetObjectFrameCount(this->m_iJobPart)))) {
        g_cDecoObjMgr.Delete(ID());
      } else {
      LABEL_14:
        IAnimatedEntity::RegisterForLogicUpdate(31);
      }
      break;
    default:
      return;
  }
}


// address=[0x154a490]
// Decompiled from struct SGfxObjectInfo *__thiscall CPlant::GetGfxInfos(CPlant *this)
struct SGfxObjectInfo *CPlant::GetGfxInfos(void) {
  int TickCounter; // esi
  int v2; // eax
  int v4; // [esp+4h] [ebp-8h]

  TickCounter = g_pGame->GetTickCounter();
  v4 = TickCounter - IAnimatedEntity::LastUpdateTick();
  v2 = g_pGame->GetTickCounter();
  IAnimatedEntity::SetLastUpdateTick(v2);
  if(v4 && this->m_uStage < 4u)
    this->m_iFrame = (v4 + (unsigned int) this->m_iFrame) % this->m_uCycleFrames;
  g_pGfxManager->GetObjectGfxInfo(&IEntity::m_sGfxInfo, this->m_iJobPart, this->m_iFrame, 1);
  byte_40FE518 = 16;
  byte_40FE51A = IEntity::IsVisible();
  IEntity::m_sGfxInfo.m_uFlags = 0;
  return &IEntity::m_sGfxInfo;
}


// address=[0x154a540]
// Decompiled from int __thiscall CPlant::Take(CPlant *this, int _iAmount)
void CPlant::Take(int _iAmount) {
  BB_ASSERT(! IsStaticInstance())

  BB_ASSERT(( m_uStage + _iAmount <= PLANT_STAGES_MAX + 1 && ( Type() == OBJECT_WHEAT1 || Type() == OBJECT_WHEAT2 || Type() == OBJECT_SUNFLOWER ) ) || ( m_uStage + _iAmount <= PLANT_STAGES_MAX && !( Type() == OBJECT_WHEAT1 || Type() == OBJECT_WHEAT2 || Type() == OBJECT_SUNFLOWER ) ))
  IEntity::ClearFlagBits(ENTITY_FLAG_Ready);
  this->m_uStage += _iAmount;
  this->m_iFrame = 0;
  this->m_iJobPart = this->m_uStage + (unsigned __int16) g_pGfxManager->GetObjectFirstJob(this->m_iType);
  this->m_uCycleFrames = g_pGfxManager->GetObjectFrameCount(this->m_iJobPart);
  BB_ASSERT(m_uCycleFrames)
  this->m_uU5 = 0;
  IAnimatedEntity::RegisterForLogicUpdate(31);
}


// address=[0x154a6c0]
// Decompiled from void __thiscall CPlant::Decrease(CPlant *this, int a2)
void CPlant::Decrease(int a2) {
  ;
}


// address=[0x154a6d0]
// Decompiled from int __thiscall CPlant::Increase(CPlant *this, int a2)
int CPlant::Increase(int a2) {
  return 1;
}


// address=[0x154a6f0]
// Decompiled from uint __cdecl CPlant::operator new(uint a1)
void * __cdecl CPlant::operator new(unsigned int a1) {
  return g_cDecoObjMgr.Alloc(a1);
}


// address=[0x154a710]
// Decompiled from void __cdecl CPlant::operator delete(uint *a1)
void __cdecl CPlant::operator delete(void *a1) {
  g_cDecoObjMgr.Dealloc(a1);
}


// address=[0x154a750]
// Decompiled from CPlant *__thiscall CPlant::CPlant(CPlant *this, struct std::istream *a1)
CPlant::CPlant(std::istream &a1) : IDecoObject(a1) {
  int fileFormatVersion; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  a1 >> fileFormatVersion;
  if(fileFormatVersion != 1) {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CPlant");
    throw CS4InvalidMapException();
  }
  a1 >> this->m_uU1;
  a1 >> this->m_uStage;
  a1 >> this->m_uCycleFrames;
  a1 >> this->m_iGoodType;
  a1 >> this->m_uU5;
  v6 = -1;
}


// address=[0x154a860]
// Decompiled from void __thiscall CPlant::Store(CPlant *this, struct std::ostream *a1)
void CPlant::Store(std::ostream &a1) {
  int v2; // [esp+0h] [ebp-8h] BYREF

  IDecoObject::Store(a1);
  v2 = 1;
  a1 << v2;
  a1 << this->m_uU1;
  a1 << this->m_uStage;
  a1 << this->m_uCycleFrames;
  a1 << this->m_iGoodType;
  a1 << this->m_uU5;
}


// address=[0x154ab80]
// Decompiled from int __thiscall CPlant::ClassID(CPlant *this)
unsigned long CPlant::ClassID(void) const {
  return CPlant::m_iClassID;
}


// address=[0x154aba0]
// Decompiled from int __thiscall CPlant::GetGoodType(CPlant *this)
int CPlant::GetGoodType(void) const {
  return this->m_iGoodType;
}


// address=[0x3d8bb18]
// [Decompilation failed for static unsigned long CPlant::m_iClassID]

