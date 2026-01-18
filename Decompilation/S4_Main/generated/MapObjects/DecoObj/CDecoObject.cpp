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
// Decompiled from CDecoObject *__thiscall CDecoObject::CDecoObject(  CDecoObject *this,  int a2,  int a3,  unsigned int a4,  int a5,  int a6,  int a7)
 CDecoObject::CDecoObject(int a2, int a3, int a4, int a5, int a6, int a7) {
  
  IDecoObject::IDecoObject(this, a2, a3, a4, a5, 1);
  *(_DWORD *)this = &CDecoObject::_vftable_;
  *((_WORD *)this + 19) = CGfxManager::GetObjectFirstJob((CGfxManager *)g_pGfxManager, a4);
  if ( *((unsigned __int16 *)this + 19) >= 0x228u
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 264, "m_uJobPart<SIV_OBJECT_MAX") == 1 )
  {
    __debugbreak();
  }
  *((_BYTE *)this + 72) = 1;
  *((_BYTE *)this + 73) = a7 == 0;
  *((_BYTE *)this + 74) = CGfxManager::GetObjectFrameCount(
                            (CGfxManager *)g_pGfxManager,
                            *((unsigned __int16 *)this + 19));
  *((_BYTE *)this + 36) = a6 % *((unsigned __int8 *)this + 74);
  *((_WORD *)this + 38) = CStateGame::GetTickCounter(g_pGame);
  return this;
}


// address=[0x1541c80]
// Decompiled from void *__thiscall sub_1941C80(int this)
struct SGfxObjectInfo *  CDecoObject::GetGfxInfos(void) {
  
  unsigned int v2; // [esp+8h] [ebp-8h]

  v2 = (unsigned __int16)CStateGame::GetTickCounter(g_pGame) - *(unsigned __int16 *)(this + 76);
  *(_WORD *)(this + 76) = CStateGame::GetTickCounter(g_pGame);
  if ( v2 && *(unsigned __int8 *)(this + 74) > 1u )
  {
    if ( *(_BYTE *)(this + 73) == 1 )
    {
      if ( *(_BYTE *)(this + 72) )
      {
        *(_BYTE *)(this + 36) = (v2 + *(unsigned __int8 *)(this + 36)) % *(unsigned __int8 *)(this + 74);
        if ( *(unsigned __int8 *)(this + 36) == *(unsigned __int8 *)(this + 74) - 1 )
          *(_BYTE *)(this + 72) = *(_BYTE *)(this + 72) == 0;
      }
      else
      {
        if ( v2 <= *(unsigned __int8 *)(this + 36) )
          *(_BYTE *)(this + 36) -= v2;
        else
          *(_BYTE *)(this + 36) = 0;
        if ( !*(_BYTE *)(this + 36) )
          *(_BYTE *)(this + 72) = *(_BYTE *)(this + 72) == 0;
      }
    }
    else
    {
      *(_BYTE *)(this + 36) = (v2 + *(unsigned __int8 *)(this + 36)) % *(unsigned __int8 *)(this + 74);
    }
  }
  CGfxManager::GetObjectGfxInfo(
    &IEntity::m_sGfxInfo,
    *(unsigned __int16 *)(this + 38),
    *(unsigned __int8 *)(this + 36),
    1);
  if ( *(_WORD *)(this + 12) == 123 )
    byte_40FE518 = 16;
  else
    byte_40FE518 = *(_BYTE *)(this + 10);
  byte_40FE51A = IEntity::IsVisible((void *)this);
  byte_40FE266 = 0;
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
// Decompiled from _DWORD *__thiscall CDecoObject::CDecoObject(_DWORD *this, int a2)
 CDecoObject::CDecoObject(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IDecoObject::IDecoObject(a2);
  v6 = 0;
  *v5 = &CDecoObject::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CDecoObject");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<bool>(a2, v5 + 18);
  operator^<bool>(a2, (char *)v5 + 73);
  operator^<unsigned char>(a2, (char *)v5 + 74);
  operator^<unsigned short>(a2, v5 + 19);
  v6 = -1;
  return v5;
}


// address=[0x1541f80]
// Decompiled from int __thiscall CDecoObject::Store(__int16 *this, struct std::ostream *a2)
void  CDecoObject::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  __int16 *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  IDecoObject::Store(a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<bool>((int)a2, (int)(v4 + 36));
  operator^<bool>((int)a2, (int)v4 + 73);
  operator^<unsigned char>(a2, (int)(v4 + 37));
  return operator^<unsigned short>((int)a2, v4 + 38);
}


// address=[0x15422d0]
// Decompiled from void __thiscall CDecoObject::~CDecoObject(CDecoObject *this)
 CDecoObject::~CDecoObject(void) {
  
  *(_DWORD *)this = &CDecoObject::_vftable_;
  IDecoObject::~IDecoObject(this);
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

