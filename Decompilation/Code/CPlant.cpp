#include "CPlant.h"

// Definitions for class CPlant

// address=[0x14016c0]
// Decompiled from int __cdecl CPlant::New(int a1)

static class CPersistence * __cdecl CPlant::New(std::istream &) {
  
  if ( CPlant::operator new(0x50u) )
    return CPlant::CPlant(a1);
  else
    return 0;
}


// address=[0x154a040]
// Decompiled from CPlant *__thiscall CPlant::CPlant(CPlant *this, int a2, int a3, int a4, int a5, char a6, int a7)

 CPlant::CPlant(int,int,int,int,int,int) {
  
  IDecoObject::IDecoObject(this, a2, a3, a4, a5, a7 != 0);
  *(_DWORD *)this = &CPlant::_vftable_;
  *((_BYTE *)this + 72) = 1;
  *((_BYTE *)this + 73) = a7;
  *((_BYTE *)this + 75) = a6;
  *((_DWORD *)this + 19) = 0;
  *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73)
                        + (unsigned __int16)CGfxManager::GetObjectFirstJob(
                                              (CGfxManager *)g_pGfxManager,
                                              *((unsigned __int16 *)this + 6));
  *((_BYTE *)this + 74) = CGfxManager::GetObjectFrameCount(
                            (CGfxManager *)g_pGfxManager,
                            *((unsigned __int16 *)this + 19));
  if ( !*((_BYTE *)this + 74) && BBSupportDbgReport(2, "MapObjects\\DecoObj\\Plant.cpp", 89, "m_uCycleFrames") == 1 )
    __debugbreak();
  if ( IDecoObject::IsStaticInstance(this) )
  {
    *((_BYTE *)this + 36) = CStateGame::Rand(g_pGame) % (unsigned int)*((unsigned __int8 *)this + 74);
    IEntity::SetFlagBits(this, (EntityFlag)((char *)&loc_1FFFFFF + 1));
  }
  else
  {
    IAnimatedEntity::RegisterForLogicUpdate(31);
  }
  return this;
}


// address=[0x154a1a0]
// Decompiled from CPlant *__thiscall CPlant::CPlant(CPlant *this, const struct CPlant *a2, int a3, int a4, int a5)

 CPlant::CPlant(class CPlant const &,int,int,int) {
  
  IDecoObject::IDecoObject(this, a2, a3, a4, a5);
  *(_DWORD *)this = &CPlant::_vftable_;
  *((_DWORD *)this + 19) = 0;
  IEntity::SetFlagBits(this, (EntityFlag)((char *)&loc_1FFFFFF + 1));
  *((_BYTE *)this + 73) = 3;
  *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73)
                        + (unsigned __int16)CGfxManager::GetObjectFirstJob(
                                              (CGfxManager *)g_pGfxManager,
                                              *((unsigned __int16 *)this + 6));
  *((_BYTE *)this + 74) = *((_BYTE *)a2 + 74);
  if ( !*((_BYTE *)this + 74) && BBSupportDbgReport(2, "MapObjects\\DecoObj\\Plant.cpp", 135, "m_uCycleFrames") == 1 )
    __debugbreak();
  *((_BYTE *)this + 36) = *((_BYTE *)a2 + 36);
  *((_BYTE *)this + 72) = 1;
  *((_BYTE *)this + 75) = *((_BYTE *)a2 + 75);
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
  
  int v1; // eax
  int v2; // eax
  unsigned int v3; // esi
  int v4; // eax
  int v5; // [esp-Ch] [ebp-1Ch]
  int v6; // [esp-8h] [ebp-18h]

  switch ( *((_BYTE *)this + 73) )
  {
    case 0:
    case 1:
    case 2:
      if ( (int)++*((_DWORD *)this + 19) >= 30
        && (*((_DWORD *)this + 19) = 0,
            ++*((_BYTE *)this + 73),
            *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73)
                                  + (unsigned __int16)CGfxManager::GetObjectFirstJob(
                                                        (CGfxManager *)g_pGfxManager,
                                                        *((unsigned __int16 *)this + 6)),
            *((_BYTE *)this + 73) == 3) )
      {
        IEntity::SetFlagBits(this, (EntityFlag)((char *)&loc_1FFFFFF + 1));
        v6 = IEntity::Type((unsigned __int16 *)this);
        v5 = IEntity::Y(this);
        v1 = IEntity::X(this);
        CDecoObjMgr::ChangeToStaticInstance((CDecoObjMgr *)&g_cDecoObjMgr, v1, v5, v6, 0);
      }
      else
      {
        if ( !IEntity::FlagBits(this, (EntityFlag)0x100000u) )
          goto LABEL_14;
        v2 = CStaticConfigVarInt::operator int(g_pMagicFasterCropsDecrease256);
        IAnimatedEntity::RegisterForLogicUpdate((31 * v2 + 127) >> 8);
      }
      break;
    case 4:
    case 5:
      if ( (int)++*((_DWORD *)this + 19) >= 30
        && (*((_WORD *)this + 6) == 209
         || *((_WORD *)this + 6) == 210
         || (*((_DWORD *)this + 19) = 0,
             ++*((_BYTE *)this + 36),
             v3 = *((unsigned __int8 *)this + 36),
             v3 >= CGfxManager::GetObjectFrameCount((CGfxManager *)g_pGfxManager, *((unsigned __int16 *)this + 19)))) )
      {
        v4 = IEntity::ID();
        CDecoObjMgr::Delete((CDecoObjMgr *)&g_cDecoObjMgr, v4);
      }
      else
      {
LABEL_14:
        IAnimatedEntity::RegisterForLogicUpdate(31);
      }
      break;
    default:
      return;
  }
}


// address=[0x154a490]
// Decompiled from void *__thiscall CPlant::GetGfxInfos(int this)

struct SGfxObjectInfo *  CPlant::GetGfxInfos(void) {
  
  int TickCounter; // esi
  int v2; // eax
  int v4; // [esp+4h] [ebp-8h]

  TickCounter = CStateGame::GetTickCounter(g_pGame);
  v4 = TickCounter - IAnimatedEntity::LastUpdateTick(this);
  v2 = CStateGame::GetTickCounter(g_pGame);
  IAnimatedEntity::SetLastUpdateTick((CMFCCaptionButton *)this, v2);
  if ( v4 && *(unsigned __int8 *)(this + 73) < 4u )
    *(_BYTE *)(this + 36) = (v4 + (unsigned int)*(unsigned __int8 *)(this + 36)) % *(unsigned __int8 *)(this + 74);
  CGfxManager::GetObjectGfxInfo(
    (int)&IEntity::m_sGfxInfo,
    *(unsigned __int16 *)(this + 38),
    *(unsigned __int8 *)(this + 36),
    1);
  byte_40FE518 = 16;
  byte_40FE51A = IEntity::IsVisible((_DWORD *)this);
  byte_40FE266 = 0;
  return &IEntity::m_sGfxInfo;
}


// address=[0x154a540]
// Decompiled from int __thiscall CPlant::Take(CPlant *this, int a2)

void  CPlant::Take(int) {
  
  if ( IDecoObject::IsStaticInstance(this)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\Plant.cpp", 342, "! IsStaticInstance()") == 1 )
  {
    __debugbreak();
  }
  if ( (a2 + *((unsigned __int8 *)this + 73) > 5
     || IEntity::Type((unsigned __int16 *)this) != 209
     && IEntity::Type((unsigned __int16 *)this) != 210
     && IEntity::Type((unsigned __int16 *)this) != 255)
    && (a2 + *((unsigned __int8 *)this + 73) > 4
     || IEntity::Type((unsigned __int16 *)this) == 209
     || IEntity::Type((unsigned __int16 *)this) == 210
     || IEntity::Type((unsigned __int16 *)this) == 255)
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
  IEntity::ClearFlagBits(this, (EntityFlag)((char *)&loc_1FFFFFF + 1));
  *((_BYTE *)this + 73) += a2;
  *((_BYTE *)this + 36) = 0;
  *((_WORD *)this + 19) = *((unsigned __int8 *)this + 73)
                        + (unsigned __int16)CGfxManager::GetObjectFirstJob(
                                              (CGfxManager *)g_pGfxManager,
                                              *((unsigned __int16 *)this + 6));
  *((_BYTE *)this + 74) = CGfxManager::GetObjectFrameCount(
                            (CGfxManager *)g_pGfxManager,
                            *((unsigned __int16 *)this + 19));
  if ( !*((_BYTE *)this + 74) && BBSupportDbgReport(2, "MapObjects\\DecoObj\\Plant.cpp", 362, "m_uCycleFrames") == 1 )
    __debugbreak();
  *((_DWORD *)this + 19) = 0;
  return IAnimatedEntity::RegisterForLogicUpdate(31);
}


// address=[0x154a6c0]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall CPlant::Decrease(CPlant *this, int a2)

void  CPlant::Decrease(int) {
  
  ;
}


// address=[0x154a6d0]
// Decompiled from // MFC 3.1-14.0 32bit
int __thiscall CPlant::Increase(CPlant *this, int a2)

int  CPlant::Increase(int) {
  
  return 1;
}


// address=[0x154a6f0]
// Decompiled from unsigned int __cdecl CPlant::operator new(unsigned int a1)

static void * __cdecl CPlant::operator new(unsigned int) {
  
  return CDecoObjMgr::Alloc((CDecoObjMgr *)&g_cDecoObjMgr, a1);
}


// address=[0x154a710]
// Decompiled from void __cdecl CPlant::operator delete(void *a1)

static void __cdecl CPlant::operator delete(void *) {
  
  CDecoObjMgr::Dealloc((CDecoObjMgr *)&g_cDecoObjMgr, a1);
}


// address=[0x154a750]
// Decompiled from char *__thiscall CPlant::CPlant(char *this, int a2)

 CPlant::CPlant(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  char *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IDecoObject::IDecoObject(a2);
  v6 = 0;
  *(_DWORD *)v5 = &CPlant::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CPlant");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<bool>(a2, v5 + 72);
  operator^<unsigned char>(a2, v5 + 73);
  operator^<unsigned char>(a2, v5 + 74);
  operator^<unsigned char>(a2, v5 + 75);
  operator^<int>(a2, (int)(v5 + 76));
  v6 = -1;
  return v5;
}


// address=[0x154a860]
// Decompiled from int __thiscall CPlant::Store(int *this, struct std::ostream *a2)

void  CPlant::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  int *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  IDecoObject::Store(a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<bool>((int)a2, (int)(v4 + 18));
  operator^<unsigned char>(a2, (int)v4 + 73);
  operator^<unsigned char>(a2, (int)v4 + 74);
  operator^<unsigned char>(a2, (int)v4 + 75);
  return operator^<int>((int)a2, v4 + 19);
}


// address=[0x154ab80]
// Decompiled from int __thiscall CPlant::ClassID(CPlant *this)

unsigned long  CPlant::ClassID(void)const {
  
  return CPlant::m_iClassID;
}


// address=[0x154aba0]
// Decompiled from int __thiscall CPlant::GetGoodType(CPlant *this)

int  CPlant::GetGoodType(void)const {
  
  return *((unsigned __int8 *)this + 75);
}


// address=[0x3d8bb18]
// [Decompilation failed for static unsigned long CPlant::m_iClassID]

