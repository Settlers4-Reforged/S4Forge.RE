#if FALSE
#include "CMushroom.h"

// Definitions for class CMushroom

// address=[0x1549690]
// Decompiled from CMushroom *__thiscall CMushroom::CMushroom(CMushroom *this, unsigned int a2, unsigned int a3, int a4, int a5, int a6)
 CMushroom::CMushroom(int a2, int a3, int a4, int a5, int a6) {
  
  IDecoObject::IDecoObject(this, a2, a3, a4, a5, a6 != 0);
  this->__vftable = (IAnimatedEntity_vtbl *)&CMushroom::_vftable_;
  this->m_uU1 = 1;
  this->m_iPhases = a6;
  this->m_uU0 = 0;
  this->m_iJobPart = this->m_iPhases + (unsigned __int16)CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_iType);
  this->m_uCycleFrames = CGfxManager::GetObjectFrameCount(g_pGfxManager, this->m_iJobPart);
  if ( !this->m_uCycleFrames && BBSupportDbgReport(2, "MapObjects\\DecoObj\\Mushroom.cpp", 82, "m_uCycleFrames") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_iPhases )
  {
    this->m_iFrame = CStateGame::Rand(g_pGame) % this->m_uCycleFrames;
    IEntity::SetFlagBits(this, ENTITY_FLAG_Ready);
  }
  else
  {
    IAnimatedEntity::RegisterForLogicUpdate(this, 31);
    this->m_iFrame = 0;
  }
  return this;
}


// address=[0x15497e0]
// Decompiled from CMushroom *__thiscall CMushroom::CMushroom(CMushroom *this, const struct CMushroom *a2, int a3, unsigned int a4, unsigned int a5)
 CMushroom::CMushroom(class CMushroom const & a2, int a3, int a4, int a5) {
  
  IDecoObject::IDecoObject(this, a2, a3, a4, a5);
  this->__vftable = (IAnimatedEntity_vtbl *)&CMushroom::_vftable_;
  this->m_uU0 = 0;
  this->m_iPhases = 3;
  this->m_iJobPart = this->m_iPhases + (unsigned __int16)CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_iType);
  this->m_uCycleFrames = a2->m_uCycleFrames;
  if ( !this->m_uCycleFrames && BBSupportDbgReport(2, "MapObjects\\DecoObj\\Mushroom.cpp", 129, "m_uCycleFrames") == 1 )
  {
    __debugbreak();
  }
  this->m_iFrame = a2->m_iFrame;
  this->m_uU1 = 1;
  return this;
}


// address=[0x15498d0]
// Decompiled from int __thiscall CMushroom::~CMushroom(CMushroom *this)
 CMushroom::~CMushroom(void) {
  
  this->__vftable = (IAnimatedEntity_vtbl *)&CMushroom::_vftable_;
  return IDecoObject::~IDecoObject(this);
}


// address=[0x15498f0]
// Decompiled from void __thiscall CMushroom::LogicUpdate(CMushroom *this)
void  CMushroom::LogicUpdate(void) {
  
  unsigned int v1; // eax
  unsigned int m_cFrame; // esi
  int v3; // eax
  unsigned int v4; // [esp-Ch] [ebp-18h]
  T_OBJECT_TYPE v5; // [esp-8h] [ebp-14h]

  switch ( this->m_iPhases )
  {
    case 0u:
    case 1u:
    case 2u:
      if ( ++this->m_uU0 < 5 )
      {
        goto LABEL_10;
      }
      this->m_uU0 = 0;
      ++this->m_iPhases;
      this->m_iJobPart = this->m_iPhases + (unsigned __int16)CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_iType);
      if ( this->m_iPhases != 3 )
      {
        goto LABEL_10;
      }
      v5 = IEntity::Type(this);
      v4 = IEntity::Y(this);
      v1 = IEntity::X(this);
      CDecoObjMgr::ChangeToStaticInstance(&g_cDecoObjMgr, v1, v4, v5, 0);
      break;
    case 3u:
      ++this->m_uU0;
      this->m_uU0 = 0;
      IAnimatedEntity::RegisterForLogicUpdate(this, 31);
      break;
    case 4u:
      if ( ++this->m_uU0 < 5 || (this->m_uU0 = 0, ++this->m_iFrame, m_cFrame = this->m_iFrame, m_cFrame < CGfxManager::GetObjectFrameCount(g_pGfxManager, this->m_iJobPart)) )
      {
LABEL_10:
        IAnimatedEntity::RegisterForLogicUpdate(this, 31);
      }
      else
      {
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
struct SGfxObjectInfo *  CMushroom::GetGfxInfos(void) {
  
  int TickCounter; // esi
  DWORD v2; // eax
  int v4; // [esp+4h] [ebp-8h]

  TickCounter = CStateGame::GetTickCounter(g_pGame);
  v4 = TickCounter - IAnimatedEntity::LastUpdateTick(this);
  v2 = CStateGame::GetTickCounter(g_pGame);
  IAnimatedEntity::SetLastUpdateTick(this, v2);
  if ( v4 )
  {
    this->m_iFrame = (v4 + (unsigned int)this->m_iFrame) % this->m_uCycleFrames;
  }
  CGfxManager::GetObjectGfxInfo(g_pGfxManager, &IEntity::m_sGfxInfo, this->m_iJobPart, this->m_iFrame, 1);
  MEMORY[0x40FE518] = 16;
  MEMORY[0x40FE51A] = IEntity::IsVisible(this);
  IEntity::m_sGfxInfo.m_uFlags = 0;
  return &IEntity::m_sGfxInfo;
}


// address=[0x1549b00]
// Decompiled from int __thiscall CMushroom::Decrease(CMushroom *this, int a2)
void  CMushroom::Decrease(int a2) {
  
  if ( IDecoObject::IsStaticInstance(this) && BBSupportDbgReport(2, "MapObjects\\DecoObj\\Mushroom.cpp", 335, "IsStaticInstance() == false") == 1 )
  {
    __debugbreak();
  }
  IEntity::ClearFlagBits(this, ENTITY_FLAG_Ready);
  ++this->m_iPhases;
  this->m_iFrame = 0;
  this->m_iJobPart = this->m_iPhases + (unsigned __int16)CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_iType);
  this->m_uCycleFrames = CGfxManager::GetObjectFrameCount(g_pGfxManager, this->m_iJobPart);
  if ( !this->m_uCycleFrames && BBSupportDbgReport(2, "MapObjects\\DecoObj\\Mushroom.cpp", 345, "m_uCycleFrames") == 1 )
  {
    __debugbreak();
  }
  this->m_uU0 = 0;
  return IAnimatedEntity::RegisterForLogicUpdate(this, 31);
}


// address=[0x1549be0]
// Decompiled from int __thiscall CMushroom::Increase(CMushroom *this, int a2)
int  CMushroom::Increase(int a2) {
  
  return 1;
}


// address=[0x1549c00]
// Decompiled from uint __cdecl CMushroom::operator new(uint a1)
void * __cdecl CMushroom::operator new(unsigned int a1) {
  
  return CDecoObjMgr::Alloc(&g_cDecoObjMgr, a1);
}


// address=[0x1549c20]
// Decompiled from void __cdecl CMushroom::operator delete(uint *a1)
void __cdecl CMushroom::operator delete(void * a1) {
  
  CDecoObjMgr::Dealloc(&g_cDecoObjMgr, a1);
}


// address=[0x1549c60]
// Decompiled from CMushroom *__thiscall CMushroom::CMushroom(CMushroom *this, struct std::istream *a1)
 CMushroom::CMushroom(std::istream & a2) {
  
  int fileFormatVersion; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  IDecoObject::IDecoObject(this, a1);
  v6 = 0;
  this->__vftable = (IAnimatedEntity_vtbl *)&CMushroom::_vftable_;
  operator^<unsigned int>(a1, &fileFormatVersion);
  if ( fileFormatVersion != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CMushroom");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<bool>(a1, &this->m_uU1);
  operator^<unsigned char>(a1, &this->m_iPhases);
  operator^<unsigned char>(a1, &this->m_uCycleFrames);
  operator^<int>(a1, &this->m_uU0);
  v6 = -1;
  return this;
}


// address=[0x1549d60]
// Decompiled from void __thiscall CMushroom::Store(CMushroom *this, struct std::ostream *a1)
void  CMushroom::Store(std::ostream & a1) {
  
  int v2; // [esp+0h] [ebp-8h] BYREF

  IDecoObject::Store(this, a1);
  v2 = 1;
  operator^<unsigned int>(a1, &v2);
  operator^<bool>(a1, &this->m_uU1);
  operator^<unsigned char>(a1, &this->m_iPhases);
  operator^<unsigned char>(a1, &this->m_uCycleFrames);
  operator^<int>(a1, &this->m_uU0);
}


// address=[0x154a020]
// Decompiled from int __thiscall CMushroom::ClassID(CMushroom *this)
unsigned long  CMushroom::ClassID(void)const {
  
  return CMushroom::m_iClassID;
}


// address=[0x3d8bb14]
// [Decompilation failed for static unsigned long CMushroom::m_iClassID]

#endif // Already implemented
