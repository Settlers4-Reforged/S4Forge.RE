#if FALSE
#include "CHive.h"

// Definitions for class CHive

// address=[0x15488d0]
// Decompiled from CHive *__thiscall CHive::CHive(  CHive *this,  unsigned int _iX,  unsigned int _iY,  int _iDecoObjectType,  int _iId,  int _iPhases)
 CHive::CHive(int _iX, int _iY, int _iDecoObjectType, int _iId, int _iPhases) {
  
  IDecoObject::IDecoObject(this, _iX, _iY, _iDecoObjectType, _iId, _iPhases != 0);
  this->__vftable = (IAnimatedEntity_vtbl *)&CHive::_vftable_;
  if ( _iPhases && BBSupportDbgReport(2, "mapobjects\\decoobj\\hive.cpp", 70, "_iPhases == GROW1") == 1 )
    __debugbreak();
  this->m_uU6 = 406;
  this->m_uU1 = 1;
  this->m_iPhases = _iPhases;
  this->m_uU5 = 0;
  if ( CHive::IsFlowerInSurrounding(this) )
  {
    ++this->m_iPhases;
    this->m_iJobPart = CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_nType);
  }
  else
  {
    this->m_iJobPart = CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_nType) + 1;
  }
  this->m_uCycleFrames = CGfxManager::GetObjectFrameCount(g_pGfxManager, this->m_iJobPart);
  if ( !this->m_uCycleFrames && BBSupportDbgReport(2, "mapobjects\\decoobj\\hive.cpp", 98, "m_uCycleFrames") == 1 )
    __debugbreak();
  IAnimatedEntity::RegisterForLogicUpdate(this, 31);
  this->m_iFrame = 0;
  return this;
}


// address=[0x1548a60]
// Decompiled from CHive *__thiscall CHive::CHive(CHive *this, const struct CHive *a2, int a3, unsigned int a4, unsigned int a5)
 CHive::CHive(class CHive const & a2, int a3, int a4, int a5) {
  
  IDecoObject::IDecoObject(this, a2, a3, a4, a5);
  this->__vftable = (IAnimatedEntity_vtbl *)&CHive::_vftable_;
  this->m_uU5 = 0;
  this->m_iPhases = a2->m_iPhases;
  this->m_iJobPart = a2->m_iJobPart;
  this->m_uCycleFrames = a2->m_uCycleFrames;
  if ( !this->m_uCycleFrames && BBSupportDbgReport(2, "mapobjects\\decoobj\\hive.cpp", 135, "m_uCycleFrames") == 1 )
    __debugbreak();
  this->m_uU6 = a2->m_uU6;
  this->m_iFrame = a2->m_iFrame;
  this->m_uU1 = 1;
  return this;
}


// address=[0x1548b50]
// Decompiled from int __thiscall CHive::~CHive(CHive *this)
 CHive::~CHive(void) {
  
  this->__vftable = (IAnimatedEntity_vtbl *)&CHive::_vftable_;
  return IDecoObject::~IDecoObject(this);
}


// address=[0x1548b70]
// Decompiled from void __thiscall CHive::LogicUpdate(CHive *this)
void  CHive::LogicUpdate(void) {
  
  unsigned int m_cFrame; // esi
  int v2; // eax
  int v3; // [esp+8h] [ebp-8h]

  v3 = 1;
  if ( CHive::IsFlowerInSurrounding(this) )
    v3 = 3;
  switch ( this->m_iPhases )
  {
    case 0u:
      this->m_uU5 += v3;
      if ( this->m_uU5 >= 20 )
      {
        this->m_uU5 = 0;
        ++this->m_iPhases;
        this->m_iJobPart = CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_nType);
        this->m_uCycleFrames = CGfxManager::GetObjectFrameCount(g_pGfxManager, this->m_iJobPart);
      }
      goto LABEL_24;
    case 1u:
      this->m_uU5 += v3;
      if ( this->m_uU5 >= 20 )
      {
        this->m_uU5 = 0;
        ++this->m_iPhases;
      }
      goto LABEL_24;
    case 2u:
      this->m_uU5 += v3;
      if ( this->m_uU5 >= 20 )
      {
        this->m_uU5 = 0;
        ++this->m_iPhases;
        this->m_iFrame = 0;
        this->m_iJobPart = CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_nType) + 1;
        this->m_uCycleFrames = CGfxManager::GetObjectFrameCount(g_pGfxManager, this->m_iJobPart);
        IEntity::SetFlagBits(this, ENTITY_FLAG_Ready);
      }
      goto LABEL_24;
    case 3u:
      if ( --this->m_uU6 <= 0 )
      {
        IEntity::ClearFlagBits(this, ENTITY_FLAG_Ready);
        ++this->m_iPhases;
        this->m_iFrame = 0;
        this->m_iJobPart = CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_nType) + 2;
        this->m_uCycleFrames = CGfxManager::GetObjectFrameCount(g_pGfxManager, this->m_iJobPart);
        if ( !this->m_uCycleFrames && BBSupportDbgReport(2, "mapobjects\\decoobj\\hive.cpp", 334, "m_uCycleFrames") == 1 )
          __debugbreak();
      }
      goto LABEL_24;
    case 4u:
      if ( ++this->m_uU5 >= 20 )
      {
        this->m_uU5 = 0;
        ++this->m_iPhases;
        this->m_iFrame = 0;
        this->m_iJobPart = CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_nType) + 3;
        this->m_uCycleFrames = CGfxManager::GetObjectFrameCount(g_pGfxManager, this->m_iJobPart);
      }
      goto LABEL_24;
    case 5u:
      if ( ++this->m_uU5 < 20
        || (this->m_uU5 = 0,
            ++this->m_iFrame,
            m_cFrame = this->m_iFrame,
            m_cFrame < CGfxManager::GetObjectFrameCount(g_pGfxManager, this->m_iJobPart)) )
      {
LABEL_24:
        IAnimatedEntity::RegisterForLogicUpdate(this, 31);
      }
      else
      {
        v2 = IEntity::ID(this);
        CDecoObjMgr::Delete(&g_cDecoObjMgr, v2);
      }
      break;
    default:
      return;
  }
}


// address=[0x1548eb0]
// Decompiled from struct SGfxObjectInfo *__thiscall CHive::GetGfxInfos(CHive *this)
struct SGfxObjectInfo *  CHive::GetGfxInfos(void) {
  
  int TickCounter; // esi
  DWORD v2; // eax
  int v4; // [esp+4h] [ebp-8h]

  TickCounter = CStateGame::GetTickCounter(g_pGame);
  v4 = TickCounter - IAnimatedEntity::LastUpdateTick(this);
  v2 = CStateGame::GetTickCounter(g_pGame);
  IAnimatedEntity::SetLastUpdateTick(this, v2);
  if ( v4 )
    this->m_iFrame = (v4 + (unsigned int)this->m_iFrame) % this->m_uCycleFrames;
  CGfxManager::GetObjectGfxInfo(g_pGfxManager, &IEntity::m_sGfxInfo, this->m_iJobPart, this->m_iFrame, 1);
  MEMORY[0x40FE518] = 16;
  MEMORY[0x40FE51A] = IEntity::IsVisible(this);
  IEntity::m_sGfxInfo.m_uFlags = 0;
  return &IEntity::m_sGfxInfo;
}


// address=[0x1548f50]
// Decompiled from int __thiscall CHive::Decrease(CHive *this, int a2)
void  CHive::Decrease(int a2) {
  
  int result; // eax

  if ( IDecoObject::IsStaticInstance(this)
    && BBSupportDbgReport(2, "mapobjects\\decoobj\\hive.cpp", 387, "IsStaticInstance() == false") == 1 )
  {
    __debugbreak();
  }
  if ( CGameData::Rand(g_pGameData) <= 0x1000 )
    return IAnimatedEntity::RegisterForLogicUpdate(this, 31);
  IEntity::ClearFlagBits(this, ENTITY_FLAG_Ready);
  if ( CHive::IsFlowerInSurrounding(this) )
  {
    this->m_iPhases = 1;
    this->m_iFrame = 0;
    this->m_iJobPart = CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_nType);
  }
  else
  {
    this->m_iPhases = 0;
    this->m_iFrame = 0;
    this->m_iJobPart = CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_nType) + 1;
  }
  result = CGfxManager::GetObjectFrameCount(g_pGfxManager, this->m_iJobPart);
  this->m_uCycleFrames = result;
  return result;
}


// address=[0x1549060]
// Decompiled from int __thiscall CHive::Increase(CHive *this, int a2)
int  CHive::Increase(int a2) {
  
  return 1;
}


// address=[0x1549080]
// Decompiled from uint __cdecl CHive::operator new(uint a1)
void * __cdecl CHive::operator new(unsigned int a1) {
  
  return CDecoObjMgr::Alloc(&g_cDecoObjMgr, a1);
}


// address=[0x15490a0]
// Decompiled from void __cdecl CHive::operator delete(uint *a1)
void __cdecl CHive::operator delete(void * a1) {
  
  CDecoObjMgr::Dealloc(&g_cDecoObjMgr, a1);
}


// address=[0x15490e0]
// Decompiled from char __thiscall CHive::IsFlowerInSurrounding(CHive *this)
bool  CHive::IsFlowerInSurrounding(void) {
  
  int v1; // esi
  int v2; // esi
  int v4; // [esp+4h] [ebp-20h]
  int v5; // [esp+8h] [ebp-1Ch]
  IEntity *DecoObjPtr; // [esp+Ch] [ebp-18h]
  unsigned int v7; // [esp+10h] [ebp-14h]
  unsigned int v8; // [esp+14h] [ebp-10h]
  int v10; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  v10 = CSpiralOffsets::First(2);
  for ( i = v10; i < v10 + 80; ++i )
  {
    v1 = IEntity::X(this);
    v7 = CSpiralOffsets::DeltaX(i) + v1;
    v2 = IEntity::Y(this);
    v8 = CSpiralOffsets::DeltaY(i) + v2;
    if ( CWorldManager::InWorld(v7, v8) )
    {
      v5 = CWorldManager::ObjectId(v7, v8);
      DecoObjPtr = CDecoObjMgr::GetDecoObjPtr(v5);
      if ( DecoObjPtr )
      {
        v4 = IEntity::Type(DecoObjPtr);
        if ( CDecoObjMgr::IsFlower(&g_cDecoObjMgr, v4) )
          return 1;
      }
    }
  }
  return 0;
}


// address=[0x15491c0]
// Decompiled from CHive *__thiscall CHive::CHive(CHive *this, struct std::istream *a1)
 CHive::CHive(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  IDecoObject::IDecoObject(this, a1);
  v6 = 0;
  this->__vftable = (IAnimatedEntity_vtbl *)&CHive::_vftable_;
  operator^<unsigned int>(a1, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CHive");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<bool>(a1, &this->m_uU1);
  operator^<unsigned char>(a1, &this->m_iPhases);
  operator^<unsigned char>(a1, &this->m_uCycleFrames);
  operator^<int>(a1, &this->m_uU5);
  operator^<int>(a1, &this->m_uU6);
  v6 = -1;
  return this;
}


// address=[0x15492d0]
// Decompiled from void __thiscall CHive::Store(CHive *this, struct std::ostream *a1)
void  CHive::Store(std::ostream & a1) {
  
  int v2; // [esp+0h] [ebp-8h] BYREF

  IDecoObject::Store(this, a1);
  v2 = 1;
  operator^<unsigned int>(a1, &v2);
  operator^<bool>(a1, &this->m_uU1);
  operator^<unsigned char>(a1, &this->m_iPhases);
  operator^<unsigned char>(a1, &this->m_uCycleFrames);
  operator^<int>(a1, &this->m_uU5);
  operator^<int>(a1, &this->m_uU6);
}


// address=[0x1549670]
// Decompiled from int __thiscall CHive::ClassID(CHive *this)
unsigned long  CHive::ClassID(void)const {
  
  return CHive::m_iClassID;
}


// address=[0x3d8bb10]
// [Decompilation failed for static unsigned long CHive::m_iClassID]

#endif // Already implemented
