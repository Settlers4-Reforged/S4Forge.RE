#include "all_headers.h"

// Definitions for class CHive

// address=[0x15488d0]
// Decompiled from CHive *__thiscall CHive::CHive(CHive *this, int a2, int a3, int a4, int a5, int a6)
 CHive::CHive(int,int,int,int,int) {
  
  IDecoObject::IDecoObject(this, a2, a3, a4, a5, a6 != 0);
  *(_DWORD *)this = &CHive::_vftable_;
  if ( a6 && BBSupportDbgReport(2, "mapobjects\\decoobj\\hive.cpp", 70, "_iPhases == GROW1") == 1 )
    __debugbreak();
  *((_DWORD *)this + 20) = 406;
  *((_BYTE *)this + 72) = 1;
  *((_BYTE *)this + 73) = a6;
  *((_DWORD *)this + 19) = 0;
  if ( CHive::IsFlowerInSurrounding(this) )
  {
    ++*((_BYTE *)this + 73);
    *((_WORD *)this + 19) = CGfxManager::GetObjectFirstJob(
                              (CGfxManager *)g_pGfxManager,
                              *((unsigned __int16 *)this + 6));
  }
  else
  {
    *((_WORD *)this + 19) = CGfxManager::GetObjectFirstJob(
                              (CGfxManager *)g_pGfxManager,
                              *((unsigned __int16 *)this + 6))
                          + 1;
  }
  *((_BYTE *)this + 74) = CGfxManager::GetObjectFrameCount(
                            (CGfxManager *)g_pGfxManager,
                            *((unsigned __int16 *)this + 19));
  if ( !*((_BYTE *)this + 74) && BBSupportDbgReport(2, "mapobjects\\decoobj\\hive.cpp", 98, "m_uCycleFrames") == 1 )
    __debugbreak();
  IAnimatedEntity::RegisterForLogicUpdate(31);
  *((_BYTE *)this + 36) = 0;
  return this;
}


// address=[0x1548a60]
// Decompiled from CHive *__thiscall CHive::CHive(CHive *this, const struct CHive *a2, int a3, int a4, int a5)
 CHive::CHive(class CHive const &,int,int,int) {
  
  IDecoObject::IDecoObject(this, a2, a3, a4, a5);
  *(_DWORD *)this = &CHive::_vftable_;
  *((_DWORD *)this + 19) = 0;
  *((_BYTE *)this + 73) = *((_BYTE *)a2 + 73);
  *((_WORD *)this + 19) = *((_WORD *)a2 + 19);
  *((_BYTE *)this + 74) = *((_BYTE *)a2 + 74);
  if ( !*((_BYTE *)this + 74) && BBSupportDbgReport(2, "mapobjects\\decoobj\\hive.cpp", 135, "m_uCycleFrames") == 1 )
    __debugbreak();
  *((_DWORD *)this + 20) = *((_DWORD *)a2 + 20);
  *((_BYTE *)this + 36) = *((_BYTE *)a2 + 36);
  *((_BYTE *)this + 72) = 1;
  return this;
}


// address=[0x1548b50]
// Decompiled from void __thiscall CHive::~CHive(CHive *this)
 CHive::~CHive(void) {
  
  *(_DWORD *)this = &CHive::_vftable_;
  IDecoObject::~IDecoObject(this);
}


// address=[0x1548b70]
// Decompiled from void __thiscall CHive::LogicUpdate(CHive *this)
void  CHive::LogicUpdate(void) {
  
  unsigned int v1; // esi
  int v2; // eax
  int v3; // [esp+8h] [ebp-8h]

  v3 = 1;
  if ( CHive::IsFlowerInSurrounding(this) )
    v3 = 3;
  switch ( *((_BYTE *)this + 73) )
  {
    case 0:
      *((_DWORD *)this + 19) += v3;
      if ( *((int *)this + 19) >= 20 )
      {
        *((_DWORD *)this + 19) = 0;
        ++*((_BYTE *)this + 73);
        *((_WORD *)this + 19) = CGfxManager::GetObjectFirstJob(
                                  (CGfxManager *)g_pGfxManager,
                                  *((unsigned __int16 *)this + 6));
        *((_BYTE *)this + 74) = CGfxManager::GetObjectFrameCount(
                                  (CGfxManager *)g_pGfxManager,
                                  *((unsigned __int16 *)this + 19));
      }
      goto LABEL_24;
    case 1:
      *((_DWORD *)this + 19) += v3;
      if ( *((int *)this + 19) >= 20 )
      {
        *((_DWORD *)this + 19) = 0;
        ++*((_BYTE *)this + 73);
      }
      goto LABEL_24;
    case 2:
      *((_DWORD *)this + 19) += v3;
      if ( *((int *)this + 19) >= 20 )
      {
        *((_DWORD *)this + 19) = 0;
        ++*((_BYTE *)this + 73);
        *((_BYTE *)this + 36) = 0;
        *((_WORD *)this + 19) = CGfxManager::GetObjectFirstJob(
                                  (CGfxManager *)g_pGfxManager,
                                  *((unsigned __int16 *)this + 6))
                              + 1;
        *((_BYTE *)this + 74) = CGfxManager::GetObjectFrameCount(
                                  (CGfxManager *)g_pGfxManager,
                                  *((unsigned __int16 *)this + 19));
        IEntity::SetFlagBits(this, (EntityFlag)((char *)&loc_1FFFFFF + 1));
      }
      goto LABEL_24;
    case 3:
      if ( (int)--*((_DWORD *)this + 20) <= 0 )
      {
        IEntity::ClearFlagBits(this, (EntityFlag)((char *)&loc_1FFFFFF + 1));
        ++*((_BYTE *)this + 73);
        *((_BYTE *)this + 36) = 0;
        *((_WORD *)this + 19) = CGfxManager::GetObjectFirstJob(
                                  (CGfxManager *)g_pGfxManager,
                                  *((unsigned __int16 *)this + 6))
                              + 2;
        *((_BYTE *)this + 74) = CGfxManager::GetObjectFrameCount(
                                  (CGfxManager *)g_pGfxManager,
                                  *((unsigned __int16 *)this + 19));
        if ( !*((_BYTE *)this + 74)
          && BBSupportDbgReport(2, "mapobjects\\decoobj\\hive.cpp", 334, "m_uCycleFrames") == 1 )
        {
          __debugbreak();
        }
      }
      goto LABEL_24;
    case 4:
      if ( (int)++*((_DWORD *)this + 19) >= 20 )
      {
        *((_DWORD *)this + 19) = 0;
        ++*((_BYTE *)this + 73);
        *((_BYTE *)this + 36) = 0;
        *((_WORD *)this + 19) = CGfxManager::GetObjectFirstJob(
                                  (CGfxManager *)g_pGfxManager,
                                  *((unsigned __int16 *)this + 6))
                              + 3;
        *((_BYTE *)this + 74) = CGfxManager::GetObjectFrameCount(
                                  (CGfxManager *)g_pGfxManager,
                                  *((unsigned __int16 *)this + 19));
      }
      goto LABEL_24;
    case 5:
      if ( (int)++*((_DWORD *)this + 19) < 20
        || (*((_DWORD *)this + 19) = 0,
            ++*((_BYTE *)this + 36),
            v1 = *((unsigned __int8 *)this + 36),
            v1 < CGfxManager::GetObjectFrameCount((CGfxManager *)g_pGfxManager, *((unsigned __int16 *)this + 19))) )
      {
LABEL_24:
        IAnimatedEntity::RegisterForLogicUpdate(31);
      }
      else
      {
        v2 = IEntity::ID();
        CDecoObjMgr::Delete((CDecoObjMgr *)&g_cDecoObjMgr, v2);
      }
      break;
    default:
      return;
  }
}


// address=[0x1548eb0]
// Decompiled from void *__thiscall CHive::GetGfxInfos(CHive *this)
struct SGfxObjectInfo *  CHive::GetGfxInfos(void) {
  
  int TickCounter; // esi
  int v2; // eax
  int v4; // [esp+4h] [ebp-8h]

  TickCounter = CStateGame::GetTickCounter(g_pGame);
  v4 = TickCounter - IAnimatedEntity::LastUpdateTick(this);
  v2 = CStateGame::GetTickCounter(g_pGame);
  IAnimatedEntity::SetLastUpdateTick(this, v2);
  if ( v4 )
    *((_BYTE *)this + 36) = (v4 + (unsigned int)*((unsigned __int8 *)this + 36)) % *((unsigned __int8 *)this + 74);
  CGfxManager::GetObjectGfxInfo(
    (int)&IEntity::m_sGfxInfo,
    *((unsigned __int16 *)this + 19),
    *((unsigned __int8 *)this + 36),
    1);
  byte_40FE518 = 16;
  byte_40FE51A = IEntity::IsVisible(this);
  byte_40FE266 = 0;
  return &IEntity::m_sGfxInfo;
}


// address=[0x1548f50]
// Decompiled from int __thiscall CHive::Decrease(CHive *this, int a2)
void  CHive::Decrease(int) {
  
  int result; // eax

  if ( IDecoObject::IsStaticInstance(this)
    && BBSupportDbgReport(2, "mapobjects\\decoobj\\hive.cpp", 387, "IsStaticInstance() == false") == 1 )
  {
    __debugbreak();
  }
  if ( (unsigned int)CGameData::Rand(g_pGameData) <= 0x1000 )
    return IAnimatedEntity::RegisterForLogicUpdate(31);
  IEntity::ClearFlagBits(this, (EntityFlag)((char *)&loc_1FFFFFF + 1));
  if ( CHive::IsFlowerInSurrounding(this) )
  {
    *((_BYTE *)this + 73) = 1;
    *((_BYTE *)this + 36) = 0;
    *((_WORD *)this + 19) = CGfxManager::GetObjectFirstJob(
                              (CGfxManager *)g_pGfxManager,
                              *((unsigned __int16 *)this + 6));
  }
  else
  {
    *((_BYTE *)this + 73) = 0;
    *((_BYTE *)this + 36) = 0;
    *((_WORD *)this + 19) = CGfxManager::GetObjectFirstJob(
                              (CGfxManager *)g_pGfxManager,
                              *((unsigned __int16 *)this + 6))
                          + 1;
  }
  result = CGfxManager::GetObjectFrameCount((CGfxManager *)g_pGfxManager, *((unsigned __int16 *)this + 19));
  *((_BYTE *)this + 74) = result;
  return result;
}


// address=[0x1549060]
// Decompiled from int __thiscall CHive::Increase(CHive *this, int a2)
int  CHive::Increase(int) {
  
  return 1;
}


// address=[0x1549080]
// Decompiled from unsigned int __cdecl CHive::operator new(unsigned int a1)
static void * __cdecl CHive::operator new(unsigned int) {
  
  return CDecoObjMgr::Alloc((CDecoObjMgr *)&g_cDecoObjMgr, a1);
}


// address=[0x15490a0]
// Decompiled from void __cdecl CHive::operator delete(void *a1)
static void __cdecl CHive::operator delete(void *) {
  
  CDecoObjMgr::Dealloc((CDecoObjMgr *)&g_cDecoObjMgr, a1);
}


// address=[0x15490e0]
// Decompiled from char __thiscall CHive::IsFlowerInSurrounding(CHive *this)
bool  CHive::IsFlowerInSurrounding(void) {
  
  int v1; // esi
  int v2; // esi
  int v4; // [esp+4h] [ebp-20h]
  int v5; // [esp+8h] [ebp-1Ch]
  unsigned __int16 *DecoObjPtr; // [esp+Ch] [ebp-18h]
  int v7; // [esp+10h] [ebp-14h]
  int v8; // [esp+14h] [ebp-10h]
  int v10; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  v10 = CSpiralOffsets::First(2);
  for ( i = v10; i < v10 + 80; ++i )
  {
    v1 = IEntity::X(this);
    v7 = CSpiralOffsets::DeltaX(i) + v1;
    v2 = IEntity::Y(this);
    v8 = CSpiralOffsets::DeltaY(i) + v2;
    if ( (unsigned __int8)CWorldManager::InWorld(v7, v8) )
    {
      v5 = CWorldManager::ObjectId(v7, v8);
      DecoObjPtr = (unsigned __int16 *)CDecoObjMgr::GetDecoObjPtr(v5);
      if ( DecoObjPtr )
      {
        v4 = IEntity::Type(DecoObjPtr);
        if ( CDecoObjMgr::IsFlower((CDecoObjMgr *)&g_cDecoObjMgr, v4) )
          return 1;
      }
    }
  }
  return 0;
}


// address=[0x15491c0]
// Decompiled from _DWORD *__thiscall CHive::CHive(_DWORD *this, int a2)
 CHive::CHive(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IDecoObject::IDecoObject(a2);
  v6 = 0;
  *v5 = &CHive::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CHive");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<bool>(a2, v5 + 18);
  operator^<unsigned char>(a2, (char *)v5 + 73);
  operator^<unsigned char>(a2, (char *)v5 + 74);
  operator^<int>(a2, (int)(v5 + 19));
  operator^<int>(a2, (int)(v5 + 20));
  v6 = -1;
  return v5;
}


// address=[0x15492d0]
// Decompiled from int __thiscall CHive::Store(int *this, struct std::ostream *a2)
void  CHive::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  int *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  IDecoObject::Store(a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<bool>((int)a2, (int)(v4 + 18));
  operator^<unsigned char>(a2, (int)v4 + 73);
  operator^<unsigned char>(a2, (int)v4 + 74);
  operator^<int>((int)a2, v4 + 19);
  return operator^<int>((int)a2, v4 + 20);
}


// address=[0x1549670]
// Decompiled from int __thiscall CHive::ClassID(CHive *this)
unsigned long  CHive::ClassID(void)const {
  
  return CHive::m_iClassID;
}


// address=[0x3d8bb10]
// [Decompilation failed for static unsigned long CHive::m_iClassID]

