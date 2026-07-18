#if FALSE
#include "CDecoObject.h"

// Definitions for class CDecoObject

// address=[0x1400360]
// Decompiled from int __cdecl CDecoObject::New(int a1)
class CPersistence * __cdecl CDecoObject::New(std::istream & a1) {
  
  if ( CDecoObject::operator new(0x50u) )
    return CDecoObject::CDecoObject(a1);
  else
    return 0;
}


// address=[0x1541b70]
// Decompiled from CDecoObject *__thiscall CDecoObject::CDecoObject(  CDecoObject *this,  unsigned int a2,  unsigned int a3,  unsigned int a4,  int a5,  int a6,  int a7)
 CDecoObject::CDecoObject(int a2, int a3, int a4, int a5, int a6, int a7) {
  
  IDecoObject::IDecoObject(this, a2, a3, a4, a5, 1);
  this->__vftable = (IAnimatedEntity_vtbl *)&CDecoObject::_vftable_;
  this->m_iJobPart = CGfxManager::GetObjectFirstJob(g_pGfxManager, a4);
  if ( this->m_iJobPart >= 0x228u
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 264, "m_uJobPart<SIV_OBJECT_MAX") == 1 )
  {
    __debugbreak();
  }
  this->m_uU1 = 1;
  this->m_iPhases = a7 == 0;
  this->m_uCycleFrames = CGfxManager::GetObjectFrameCount(g_pGfxManager, this->m_iJobPart);
  this->m_iFrame = a6 % this->m_uCycleFrames;
  this->m_uTickCounter = CStateGame::GetTickCounter(g_pGame);
  return this;
}


// address=[0x1541c80]
// Decompiled from struct SGfxObjectInfo *__thiscall CDecoObject::GetGfxInfos(CDecoObject *this)
struct SGfxObjectInfo *  CDecoObject::GetGfxInfos(void) {
  
  unsigned int v2; // [esp+8h] [ebp-8h]

  v2 = (unsigned __int16)CStateGame::GetTickCounter(g_pGame) - this->m_uTickCounter;
  this->m_uTickCounter = CStateGame::GetTickCounter(g_pGame);
  if ( v2 && this->m_uCycleFrames > 1u )
  {
    if ( this->m_iPhases == 1 )
    {
      if ( this->m_uU1 )
      {
        this->m_iFrame = (v2 + this->m_iFrame) % this->m_uCycleFrames;
        if ( this->m_iFrame == this->m_uCycleFrames - 1 )
          this->m_uU1 = !this->m_uU1;
      }
      else
      {
        if ( v2 <= this->m_iFrame )
          this->m_iFrame -= v2;
        else
          this->m_iFrame = 0;
        if ( !this->m_iFrame )
          this->m_uU1 = !this->m_uU1;
      }
    }
    else
    {
      this->m_iFrame = (v2 + this->m_iFrame) % this->m_uCycleFrames;
    }
  }
  CGfxManager::GetObjectGfxInfo(g_pGfxManager, &IEntity::m_sGfxInfo, this->m_iJobPart, this->m_iFrame, 1);
  if ( this->m_iType == 123 )
    MEMORY[0x40FE518] = 16;
  else
    MEMORY[0x40FE518] = this->m_uObjType;
  MEMORY[0x40FE51A] = IEntity::IsVisible(this);
  IEntity::m_sGfxInfo.m_uFlags = 0;
  return &IEntity::m_sGfxInfo;
}


// address=[0x1541e20]
// Decompiled from unsigned int __cdecl CDecoObject::operator new(unsigned int a1)
void * __cdecl CDecoObject::operator new(unsigned int a1) {
  
  return CDecoObjMgr::Alloc((CDecoObjMgr *)&g_cDecoObjMgr, a1);
}


// address=[0x1541e40]
// Decompiled from void __cdecl CDecoObject::operator delete(void *a1)
void __cdecl CDecoObject::operator delete(void * a1) {
  
  CDecoObjMgr::Dealloc((CDecoObjMgr *)&g_cDecoObjMgr, a1);
}


// address=[0x1541e80]
// Decompiled from CDecoObject *__thiscall CDecoObject::CDecoObject(CDecoObject *this, struct std::istream *a2)
 CDecoObject::CDecoObject(std::istream & a2) {
  
  int fileFormatVersion; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  IDecoObject::IDecoObject(this, a2);
  v6 = 0;
  this->__vftable = (IAnimatedEntity_vtbl *)&CDecoObject::_vftable_;
  operator^<unsigned int>(a2, &fileFormatVersion);
  if ( fileFormatVersion != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CDecoObject");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<bool>(a2, &this->m_uU1);
  operator^<bool>(a2, &this->m_iPhases);
  operator^<unsigned char>(a2, &this->m_uCycleFrames);
  operator^<unsigned short>(a2, &this->m_uTickCounter);
  v6 = -1;
  return this;
}


// address=[0x1541f80]
// Decompiled from void __thiscall CDecoObject::Store(CDecoObject *this, struct std::ostream *a1)
void  CDecoObject::Store(std::ostream & a1) {
  
  int v2; // [esp+0h] [ebp-8h] BYREF

  IDecoObject::Store(this, a1);
  v2 = 1;
  operator^<unsigned int>(a1, &v2);
  operator^<bool>(a1, &this->m_uU1);
  operator^<bool>(a1, (bool *)&this->m_iPhases);
  operator^<unsigned char>(a1, &this->m_uCycleFrames);
  operator^<unsigned short>(a1, &this->m_uTickCounter);
}


// address=[0x15422d0]
// Decompiled from int __thiscall CDecoObject::~CDecoObject(CDecoObject *this)
 CDecoObject::~CDecoObject(void) {
  
  this->__vftable = (IAnimatedEntity_vtbl *)&CDecoObject::_vftable_;
  return IDecoObject::~IDecoObject(this);
}


// address=[0x15423c0]
// Decompiled from int __thiscall CDecoObject::Amount(CDecoObject *this)
int  CDecoObject::Amount(void)const {
  
  return 1;
}


// address=[0x15423e0]
// Decompiled from int __thiscall CDecoObject::ClassID(CDecoObject *this)
unsigned long  CDecoObject::ClassID(void)const {
  
  return CDecoObject::m_iClassID;
}


// address=[0x1542420]
// Decompiled from void __thiscall CDecoObject::Decrease(CDecoObject *this, int a2)
void  CDecoObject::Decrease(int a2) {
  
  ;
}


// address=[0x1542460]
// Decompiled from int __thiscall CDecoObject::Increase(CDecoObject *this, int a2)
int  CDecoObject::Increase(int a2) {
  
  return 1;
}


// address=[0x1542480]
// Decompiled from void __thiscall CDecoObject::LogicUpdate(CDecoObject *this)
void  CDecoObject::LogicUpdate(void) {
  
  ;
}


// address=[0x3d8bad0]
// [Decompilation failed for static unsigned long CDecoObject::m_iClassID]

#endif // Already implemented
