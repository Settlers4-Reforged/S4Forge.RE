#if FALSE
#include "CPlant.h"

// Definitions for class CPlant

// address=[0x14016c0]
// Decompiled from CPlant *__cdecl CPlant::New(int a1)
class CPersistence * __cdecl CPlant::New(std::istream & a1) {
  
  CPlant *v3; // [esp+Ch] [ebp-10h]

  v3 = (CPlant *)CPlant::operator new(0x50u);
  if ( v3 )
    return CPlant::CPlant(v3, a1);
  else
    return 0;
}


// address=[0x154a040]
// Decompiled from CPlant *__thiscall CPlant::CPlant(  CPlant *this,  unsigned int a2,  unsigned int a3,  T_OBJECT_TYPE a4,  int a5,  BYTE _iGoodType,  int a7)
 CPlant::CPlant(int a2, int a3, int a4, int a5, int _iGoodType, int a7) {
  
  IDecoObject::IDecoObject(this, a2, a3, a4, a5, a7 != 0);
  this->__vftable = (IAnimatedEntity_vtbl *)&CPlant::_vftable_;
  this->m_uU1 = 1;
  this->m_iPhases = a7;
  this->m_iGoodType = _iGoodType;
  this->m_uU5 = 0;
  this->m_iJobPart = this->m_iPhases + (unsigned __int16)CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_iType);
  this->m_uCycleFrames = CGfxManager::GetObjectFrameCount(g_pGfxManager, this->m_iJobPart);
  if ( !this->m_uCycleFrames && BBSupportDbgReport(2, "MapObjects\\DecoObj\\Plant.cpp", 89, "m_uCycleFrames") == 1 )
    __debugbreak();
  if ( IDecoObject::IsStaticInstance(this) )
  {
    this->m_iFrame = CStateGame::Rand(g_pGame) % this->m_uCycleFrames;
    IEntity::SetFlagBits(this, ENTITY_FLAG_Ready);
  }
  else
  {
    IAnimatedEntity::RegisterForLogicUpdate(this, 31);
  }
  return this;
}


// address=[0x154a1a0]
// Decompiled from CPlant *__thiscall CPlant::CPlant(CPlant *this, const struct CPlant *a2, int a3, int a4, int a5)
 CPlant::CPlant(class CPlant const & a2, int a3, int a4, int a5) {
  
  IDecoObject::IDecoObject(this, a2, a3, a4, a5);
  this->__vftable = (IAnimatedEntity_vtbl *)&CPlant::_vftable_;
  this->m_uU5 = 0;
  IEntity::SetFlagBits(this, ENTITY_FLAG_Ready);
  this->m_iPhases = 3;
  this->m_iJobPart = this->m_iPhases + (unsigned __int16)CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_iType);
  this->m_uCycleFrames = a2->m_uCycleFrames;
  if ( !this->m_uCycleFrames && BBSupportDbgReport(2, "MapObjects\\DecoObj\\Plant.cpp", 135, "m_uCycleFrames") == 1 )
    __debugbreak();
  this->m_iFrame = a2->m_iFrame;
  this->m_uU1 = 1;
  this->m_iGoodType = a2->m_iGoodType;
  return this;
}


// address=[0x154a2a0]
// Decompiled from void __thiscall CPlant::~CPlant(CPlant *this)
 CPlant::~CPlant(void) {
  
  *(_DWORD *)this = &CPlant::_vftable_;
  IDecoObject::~IDecoObject(this);
}


// address=[0x154a2c0]
// Decompiled from void __thiscall CPlant::LogicUpdate(CPlant *this)
void  CPlant::LogicUpdate(void) {
  
  unsigned int v1; // eax
  int v2; // eax
  unsigned int m_cFrame; // esi
  int v4; // eax
  unsigned int v5; // [esp-Ch] [ebp-1Ch]
  T_OBJECT_TYPE v6; // [esp-8h] [ebp-18h]

  switch ( this->m_iPhases )
  {
    case 0u:
    case 1u:
    case 2u:
      if ( ++this->m_uU5 >= 30
        && (this->m_uU5 = 0,
            ++this->m_iPhases,
            this->m_iJobPart = this->m_iPhases
                             + (unsigned __int16)CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_iType),
            this->m_iPhases == 3) )
      {
        IEntity::SetFlagBits(this, ENTITY_FLAG_Ready);
        v6 = IEntity::Type(this);
        v5 = IEntity::Y(this);
        v1 = IEntity::X(this);
        CDecoObjMgr::ChangeToStaticInstance(&g_cDecoObjMgr, v1, v5, v6, 0);
      }
      else
      {
        if ( !IEntity::FlagBits(this, (EntityFlag)0x100000) )
          goto LABEL_14;
        v2 = CStaticConfigVarInt::operator int(g_pMagicFasterCropsDecrease256);
        IAnimatedEntity::RegisterForLogicUpdate(this, (31 * v2 + 127) >> 8);
      }
      break;
    case 4u:
    case 5u:
      if ( ++this->m_uU5 >= 30
        && (this->m_iType == OBJECT_WHEAT1
         || this->m_iType == OBJECT_WHEAT2
         || (this->m_uU5 = 0,
             ++this->m_iFrame,
             m_cFrame = this->m_iFrame,
             m_cFrame >= CGfxManager::GetObjectFrameCount(g_pGfxManager, this->m_iJobPart))) )
      {
        v4 = IEntity::ID(this);
        CDecoObjMgr::Delete(&g_cDecoObjMgr, v4);
      }
      else
      {
LABEL_14:
        IAnimatedEntity::RegisterForLogicUpdate(this, 31);
      }
      break;
    default:
      return;
  }
}


// address=[0x154a490]
// Decompiled from struct SGfxObjectInfo *__thiscall CPlant::GetGfxInfos(CPlant *this)
struct SGfxObjectInfo *  CPlant::GetGfxInfos(void) {
  
  int TickCounter; // esi
  DWORD v2; // eax
  int v4; // [esp+4h] [ebp-8h]

  TickCounter = CStateGame::GetTickCounter(g_pGame);
  v4 = TickCounter - IAnimatedEntity::LastUpdateTick(this);
  v2 = CStateGame::GetTickCounter(g_pGame);
  IAnimatedEntity::SetLastUpdateTick(this, v2);
  if ( v4 && this->m_iPhases < 4u )
    this->m_iFrame = (v4 + (unsigned int)this->m_iFrame) % this->m_uCycleFrames;
  CGfxManager::GetObjectGfxInfo(g_pGfxManager, &IEntity::m_sGfxInfo, this->m_iJobPart, this->m_iFrame, 1);
  MEMORY[0x40FE518] = 16;
  MEMORY[0x40FE51A] = IEntity::IsVisible(this);
  IEntity::m_sGfxInfo.m_uFlags = 0;
  return &IEntity::m_sGfxInfo;
}


// address=[0x154a540]
// Decompiled from int __thiscall CPlant::Take(CPlant *this, int _iAmount)
void  CPlant::Take(int _iAmount) {
  
  if ( IDecoObject::IsStaticInstance(this)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\Plant.cpp", 342, "! IsStaticInstance()") == 1 )
  {
    __debugbreak();
  }
  if ( (_iAmount + this->m_iPhases > 5
     || IEntity::Type(this) != OBJECT_WHEAT1
     && IEntity::Type(this) != OBJECT_WHEAT2
     && IEntity::Type(this) != OBJECT_SUNFLOWER)
    && (_iAmount + this->m_iPhases > 4
     || IEntity::Type(this) == OBJECT_WHEAT1
     || IEntity::Type(this) == OBJECT_WHEAT2
     || IEntity::Type(this) == OBJECT_SUNFLOWER)
    && BBSupportDbgReport(
         2,
         "MapObjects\\DecoObj\\Plant.cpp",
         352,
         "( m_uStage + _iAmount <= PLANT_STAGES_MAX + 1 && ( Type() == OBJECT_WHEAT1 || Type() == OBJECT_WHEAT2 || Type()"
         " == OBJECT_SUNFLOWER ) ) || ( m_uStage + _iAmount <= PLANT_STAGES_MAX && !( Type() == OBJECT_WHEAT1 || Type() ="
         "= OBJECT_WHEAT2 || Type() == OBJECT_SUNFLOWER ) )") == 1 )
  {
    __debugbreak();
  }
  IEntity::ClearFlagBits(this, ENTITY_FLAG_Ready);
  this->m_iPhases += _iAmount;
  this->m_iFrame = 0;
  this->m_iJobPart = this->m_iPhases + (unsigned __int16)CGfxManager::GetObjectFirstJob(g_pGfxManager, this->m_iType);
  this->m_uCycleFrames = CGfxManager::GetObjectFrameCount(g_pGfxManager, this->m_iJobPart);
  if ( !this->m_uCycleFrames && BBSupportDbgReport(2, "MapObjects\\DecoObj\\Plant.cpp", 362, "m_uCycleFrames") == 1 )
    __debugbreak();
  this->m_uU5 = 0;
  return IAnimatedEntity::RegisterForLogicUpdate(this, 31);
}


// address=[0x154a6c0]
// Decompiled from void __thiscall CPlant::Decrease(CPlant *this, int a2)
void  CPlant::Decrease(int a2) {
  
  ;
}


// address=[0x154a6d0]
// Decompiled from int __thiscall CPlant::Increase(CPlant *this, int a2)
int  CPlant::Increase(int a2) {
  
  return 1;
}


// address=[0x154a6f0]
// Decompiled from uint __cdecl CPlant::operator new(uint a1)
void * __cdecl CPlant::operator new(unsigned int a1) {
  
  return CDecoObjMgr::Alloc(&g_cDecoObjMgr, a1);
}


// address=[0x154a710]
// Decompiled from void __cdecl CPlant::operator delete(uint *a1)
void __cdecl CPlant::operator delete(void * a1) {
  
  CDecoObjMgr::Dealloc(&g_cDecoObjMgr, a1);
}


// address=[0x154a750]
// Decompiled from CPlant *__thiscall CPlant::CPlant(CPlant *this, struct std::istream *a1)
 CPlant::CPlant(std::istream & a2) {
  
  int fileFormatVersion; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  IDecoObject::IDecoObject(this, a1);
  v6 = 0;
  this->__vftable = (IAnimatedEntity_vtbl *)&CPlant::_vftable_;
  operator^<unsigned int>(a1, &fileFormatVersion);
  if ( fileFormatVersion != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CPlant");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<bool>(a1, &this->m_uU1);
  operator^<unsigned char>(a1, &this->m_iPhases);
  operator^<unsigned char>(a1, &this->m_uCycleFrames);
  operator^<unsigned char>(a1, &this->m_iGoodType);
  operator^<int>(a1, &this->m_uU5);
  v6 = -1;
  return this;
}


// address=[0x154a860]
// Decompiled from void __thiscall CPlant::Store(CPlant *this, struct std::ostream *a1)
void  CPlant::Store(std::ostream & a1) {
  
  int v2; // [esp+0h] [ebp-8h] BYREF

  IDecoObject::Store(this, a1);
  v2 = 1;
  operator^<unsigned int>(a1, &v2);
  operator^<bool>(a1, &this->m_uU1);
  operator^<unsigned char>(a1, &this->m_iPhases);
  operator^<unsigned char>(a1, &this->m_uCycleFrames);
  operator^<unsigned char>(a1, &this->m_iGoodType);
  operator^<int>(a1, &this->m_uU5);
}


// address=[0x154ab80]
// Decompiled from int __thiscall CPlant::ClassID(CPlant *this)
unsigned long  CPlant::ClassID(void)const {
  
  return CPlant::m_iClassID;
}


// address=[0x154aba0]
// Decompiled from int __thiscall CPlant::GetGoodType(CPlant *this)
int  CPlant::GetGoodType(void)const {
  
  return this->m_iGoodType;
}


// address=[0x3d8bb18]
// [Decompilation failed for static unsigned long CPlant::m_iClassID]

#endif // Already implemented
