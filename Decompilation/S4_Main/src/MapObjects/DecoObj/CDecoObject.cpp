#include "CDecoObject.h"

#include <iostream>

#include "CDecoObjMgr.h"
#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "Defines/Gfx.h"
#include "Main/CGameStateHandler.h"

// Definitions for class CDecoObject

// address=[0x1400360]
// Decompiled from int __cdecl CDecoObject::New(int a1)
class CPersistence * __cdecl CDecoObject::New(std::istream &a1) {
  return new CDecoObject(a1);
}


// address=[0x1541b70]
// Decompiled from CDecoObject *__thiscall CDecoObject::CDecoObject(  CDecoObject *this,  unsigned int a2,  unsigned int a3,  unsigned int a4,  int a5,  int a6,  int a7)
CDecoObject::CDecoObject(int a2, int a3, int a4, int a5, int a6, int a7) : IDecoObject(a2, a3, a4, a5, 1) {
  this->m_iJobPart = g_pGfxManager->GetObjectFirstJob(a4);
  BB_ASSERT(this->m_iJobPart<SIV_OBJECT_MAX);

  this->m_uU1 = 1;
  this->m_iPhases = a7 == 0;
  this->m_uCycleFrames = g_pGfxManager->GetObjectFrameCount(this->m_iJobPart);
  this->m_iFrame = a6 % this->m_uCycleFrames;
  this->m_uTickCounter = g_pGame->GetTickCounter();
}


// address=[0x1541c80]
// Decompiled from struct SGfxObjectInfo *__thiscall CDecoObject::GetGfxInfos(CDecoObject *this)
struct SGfxObjectInfo *CDecoObject::GetGfxInfos(void) {
  // [esp+8h] [ebp-8h]

  unsigned int v2 = (unsigned __int16) g_pGame->GetTickCounter() - this->m_uTickCounter;
  this->m_uTickCounter = g_pGame->GetTickCounter();
  if(v2 && this->m_uCycleFrames > 1u) {
    if(this->m_iPhases == 1) {
      if(this->m_uU1) {
        this->m_iFrame = (v2 + this->m_iFrame) % this->m_uCycleFrames;
        if(this->m_iFrame == this->m_uCycleFrames - 1)
          this->m_uU1 = !this->m_uU1;
      } else {
        if(v2 <= this->m_iFrame)
          this->m_iFrame -= v2;
        else
          this->m_iFrame = 0;
        if(!this->m_iFrame)
          this->m_uU1 = !this->m_uU1;
      }
    } else {
      this->m_iFrame = (v2 + this->m_iFrame) % this->m_uCycleFrames;
    }
  }
  g_pGfxManager->GetObjectGfxInfo(&IEntity::m_sGfxInfo, this->m_iJobPart, this->m_iFrame, 1);
  if(this->m_iType == 123)
    byte_40FE518 = 16; // TODO, probably part of m_sGfxInfo
  else
    byte_40FE518 = this->m_uObjType;
  byte_40FE51A = IEntity::IsVisible();
  IEntity::m_sGfxInfo.m_uFlags = 0;
  return &IEntity::m_sGfxInfo;
}


// address=[0x1541e20]
// Decompiled from unsigned int __cdecl CDecoObject::operator new(unsigned int a1)
void * __cdecl CDecoObject::operator new(unsigned int a1) {
  return g_cDecoObjMgr.Alloc(a1);
}


// address=[0x1541e40]
// Decompiled from void __cdecl CDecoObject::operator delete(void *a1)
void __cdecl CDecoObject::operator delete(void *a1) {
  g_cDecoObjMgr.Dealloc(a1);
}


// address=[0x1541e80]
// Decompiled from CDecoObject *__thiscall CDecoObject::CDecoObject(CDecoObject *this, struct std::istream *a2)
CDecoObject::CDecoObject(std::istream &a2) : IDecoObject(a2) {
  unsigned int fileFormatVersion; // [esp+8h] [ebp-18h] BYREF
  a2 >> fileFormatVersion;
  if(fileFormatVersion != 1) {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CDecoObject");
    throw CS4InvalidMapException();
  }
  a2 >> this->m_uU1;
  a2 >> this->m_uU1;
  a2 >> this->m_iPhases;
  a2 >> this->m_uCycleFrames;
  a2 >> this->m_uTickCounter;
}


// address=[0x1541f80]
// Decompiled from void __thiscall CDecoObject::Store(const struct IDecoObject *this, struct std::ostream *a1)
void CDecoObject::Store(std::ostream &a1) {
  IDecoObject::Store(a1);

  unsigned int fileFormatVersion = 1;
  a1 << fileFormatVersion;
  a1 << this->m_uU1;
  a1 << this->m_iPhases;
  a1 << this->m_uCycleFrames;
  a1 << this->m_uTickCounter;
}


// address=[0x15422d0]
// Decompiled from int __thiscall CDecoObject::~CDecoObject(CDecoObject *this)
CDecoObject::~CDecoObject(void) = default;


// address=[0x15423c0]
// Decompiled from int __thiscall CDecoObject::Amount(CDecoObject *this)
int CDecoObject::Amount(void) const {
  return 1;
}


// address=[0x15423e0]
// Decompiled from int __thiscall CDecoObject::ClassID(CDecoObject *this)
unsigned long CDecoObject::ClassID(void) const {
  return CDecoObject::m_iClassID;
}


// address=[0x1542420]
// Decompiled from void __thiscall CDecoObject::Decrease(CDecoObject *this, int a2)
void CDecoObject::Decrease(int a2) {
  ;
}


// address=[0x1542460]
// Decompiled from int __thiscall CDecoObject::Increase(CDecoObject *this, int a2)
int CDecoObject::Increase(int a2) {
  return 1;
}


// address=[0x1542480]
// Decompiled from void __thiscall CDecoObject::LogicUpdate(CDecoObject *this)
void CDecoObject::LogicUpdate(void) {
  ;
}


// address=[0x3d8bad0]
// [Decompilation failed for static unsigned long CDecoObject::m_iClassID]

