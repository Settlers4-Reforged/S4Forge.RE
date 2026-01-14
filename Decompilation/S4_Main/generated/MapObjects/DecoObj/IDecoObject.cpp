#include "all_headers.h"

// Definitions for class IDecoObject

// address=[0x151aae0]
// Decompiled from char __thiscall IDecoObject::IsStaticInstance(IDecoObject *this)
bool  IDecoObject::IsStaticInstance(void)const {
  
  return *((_BYTE *)this + 68);
}


// address=[0x15414c0]
// Decompiled from IDecoObject *__thiscall IDecoObject::IDecoObject(IDecoObject *this, int a2, int a3, int a4, int a5, bool a6)
 IDecoObject::IDecoObject(int,int,int,int,bool) {
  
  int v7; // [esp+4h] [ebp-1Ch]
  int v8; // [esp+8h] [ebp-18h]
  unsigned __int16 *DecoObjPtr; // [esp+Ch] [ebp-14h]

  IAnimatedEntity::IAnimatedEntity(this, a5);
  *(_DWORD *)this = &IDecoObject::_vftable_;
  *((_BYTE *)this + 68) = a6;
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 63, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( a4 <= 0 && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 64, "_iDecoObjectType > 0") == 1 )
    __debugbreak();
  if ( a4 >= 291 && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 65, "_iDecoObjectType < OBJECT_MAX") == 1 )
    __debugbreak();
  if ( a5 <= 0 && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 66, "_iId > 0") == 1 )
    __debugbreak();
  *((_BYTE *)this + 10) = 32;
  *((_WORD *)this + 6) = a4;
  *((_BYTE *)this + 36) = 0;
  IEntity::SetFlagBits(this, Visible);
  if ( a6 )
    IEntity::SetPosition((IEntity *)this, 0, 0);
  else
    IEntity::SetPosition((IEntity *)this, a2, a3);
  v8 = CWorldManager::ObjectId(a2, a3);
  if ( v8 )
  {
    DecoObjPtr = (unsigned __int16 *)CDecoObjMgr::GetDecoObjPtr(v8);
    if ( !DecoObjPtr && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 94, "pDbgDecoObject != 0") == 1 )
      __debugbreak();
    if ( DecoObjPtr )
    {
      v7 = IEntity::Type(DecoObjPtr);
      if ( IDecoObject::IsStaticInstance((IDecoObject *)DecoObjPtr) )
      {
        if ( v7 != IEntity::Type((unsigned __int16 *)this)
          && CDecoObjMgr::GetTotalBuildingRings((CDecoObjMgr *)&g_cDecoObjMgr, v7)
          && BBSupportDbgReport(
               2,
               "MapObjects\\DecoObj\\DecoObj.cpp",
               102,
               "iDbgType == Type() || ( g_cDecoObjMgr.GetTotalBuildingRings( iDbgType ) == 0 )") == 1 )
        {
          __debugbreak();
        }
      }
      else if ( BBSupportDbgReport(1, "MapObjects\\DecoObj\\DecoObj.cpp", 106, "Overwriting dynamic deco-object!") == 1 )
      {
        __debugbreak();
      }
    }
  }
  CWorldManager::SetObjectId(a2, a3, a5);
  return this;
}


// address=[0x1541700]
// Decompiled from IDecoObject *__thiscall IDecoObject::IDecoObject(  IDecoObject *this,  const struct IDecoObject *a2,  int a3,  int a4,  int a5)
 IDecoObject::IDecoObject(class IDecoObject const &,int,int,int) {
  
  int v5; // esi

  IAnimatedEntity::IAnimatedEntity(this, a3);
  *(_DWORD *)this = &IDecoObject::_vftable_;
  *((_BYTE *)this + 68) = 0;
  if ( *((_BYTE *)a2 + 10) != 32
    && BBSupportDbgReportF(
         2,
         "MapObjects\\DecoObj\\DecoObj.cpp",
         133,
         "%u == LANDSCAPE_OBJ",
         *((unsigned __int8 *)a2 + 10)) == 1 )
  {
    __debugbreak();
  }
  if ( !*((_BYTE *)a2 + 68)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 134, "_rStaticDecoObject.m_bStaticInstance") == 1 )
  {
    __debugbreak();
  }
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 135, "_iId > 0") == 1 )
    __debugbreak();
  if ( !(unsigned __int8)CWorldManager::InWorld(a4, a5)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 136, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  *((_BYTE *)this + 10) = 32;
  *((_WORD *)this + 6) = *((_WORD *)a2 + 6);
  *((_BYTE *)this + 36) = 0;
  IEntity::SetFlagBits(this, Visible);
  if ( CWorldManager::ObjectId(a4, a5) )
  {
    v5 = CWorldManager::ObjectId(a4, a5);
    if ( v5 != IEntity::EntityId((unsigned __int16 *)a2)
      && BBSupportDbgReport(
           2,
           "MapObjects\\DecoObj\\DecoObj.cpp",
           145,
           "( g_cWorld.ObjectId( _iX, _iY ) == 0 ) || ( g_cWorld.ObjectId( _iX, _iY ) == _rStaticDecoObject.EntityId() )") == 1 )
    {
      __debugbreak();
    }
  }
  IEntity::SetPosition((IEntity *)this, a4, a5);
  CWorldManager::SetObjectId(a4, a5, a3);
  return this;
}


// address=[0x15418d0]
// Decompiled from void __thiscall IDecoObject::~IDecoObject(IDecoObject *this)
 IDecoObject::~IDecoObject(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int v5; // [esp-4h] [ebp-1Ch]

  *(_DWORD *)this = &IDecoObject::_vftable_;
  if ( !*((_BYTE *)this + 68) )
  {
    if ( !IEntity::X(this)
      && !IEntity::Y(this)
      && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 164, "! ( ( X() == 0 ) && ( Y() == 0 ) )") == 1 )
    {
      __debugbreak();
    }
    v5 = IEntity::Y(this);
    v1 = IEntity::X(this);
    if ( !(unsigned __int8)CWorldManager::InWorld(v1, v5)
      && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 165, "g_cWorld.InWorld( X(), Y() )") == 1 )
    {
      __debugbreak();
    }
    v2 = IEntity::WorldIdx();
    v3 = CWorldManager::ObjectId(v2);
    if ( v3 != IEntity::EntityId((unsigned __int16 *)this)
      && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 166, "g_cWorld.ObjectId( WorldIdx() ) == EntityId()") == 1 )
    {
      __debugbreak();
    }
    v4 = IEntity::WorldIdx();
    CWorldManager::SetObjectId(v4, 0);
  }
  IAnimatedEntity::~IAnimatedEntity(this);
}


// address=[0x1541a00]
// Decompiled from int __thiscall IDecoObject::ConvertToDarkOrGreen(IDecoObject *this, bool a2)
int  IDecoObject::ConvertToDarkOrGreen(bool) {
  
  int DarkObject; // [esp+Ch] [ebp-8h]
  int v5; // [esp+10h] [ebp-4h]

  v5 = IEntity::Type((unsigned __int16 *)this);
  if ( a2 )
    DarkObject = CDarkConvert::GetDarkObject(v5);
  else
    DarkObject = CDarkConvert::GetGreenObject(v5);
  if ( DarkObject )
    return DarkObject;
  else
    return v5;
}


// address=[0x1541a60]
// Decompiled from _DWORD *__thiscall IDecoObject::IDecoObject(_DWORD *this, int a2)
 IDecoObject::IDecoObject(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IAnimatedEntity::IAnimatedEntity(a2);
  v6 = 0;
  *v5 = &IDecoObject::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for IDecoObject");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<bool>(a2, v5 + 17);
  v6 = -1;
  return v5;
}


// address=[0x1541b20]
// Decompiled from int __thiscall IDecoObject::Store(void *this, struct std::ostream *a2)
void  IDecoObject::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  void *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  IAnimatedEntity::Store(a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  return operator^<bool>((int)a2, (int)v4 + 68);
}


