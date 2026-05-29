#if FALSE
#include "IDecoObject.h"

// Definitions for class IDecoObject

// address=[0x151aae0]
// Decompiled from bool __thiscall IDecoObject::IsStaticInstance(IDecoObject *this)
bool  IDecoObject::IsStaticInstance(void)const {
  
  return this->m_bStaticInstance;
}


// address=[0x15414c0]
// Decompiled from IDecoObject *__thiscall IDecoObject::IDecoObject(  IDecoObject *this,  unsigned int _iX,  unsigned int _iY,  T_OBJECT_TYPE _iDecoObjectType,  int _iId,  bool a6)
 IDecoObject::IDecoObject(int _iX, int _iY, int _iDecoObjectType, int _iId, bool a6) {
  
  int iDbgType; // [esp+4h] [ebp-1Ch]
  int v8; // [esp+8h] [ebp-18h]
  IDecoObject *pDbgDecoObject; // [esp+Ch] [ebp-14h]

  IAnimatedEntity::IAnimatedEntity(this, _iId);
  this->__vftable = (IAnimatedEntity_vtbl *)&IDecoObject::_vftable_;
  this->m_bStaticInstance = a6;
  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 63, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( _iDecoObjectType <= OBJECT_NO_OBJECT
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 64, "_iDecoObjectType > 0") == 1 )
  {
    __debugbreak();
  }
  if ( _iDecoObjectType >= OBJECT_MAX
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 65, "_iDecoObjectType < OBJECT_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( _iId <= 0 && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 66, "_iId > 0") == 1 )
    __debugbreak();
  this->m_uObjType = LANDSCAPE_OBJ;
  this->m_nType = _iDecoObjectType;
  this->m_iFrame = 0;
  IEntity::SetFlagBits(this, EntityFlag_Visible);
  if ( a6 )
    IEntity::SetPosition(this, 0, 0);
  else
    IEntity::SetPosition(this, _iX, _iY);
  v8 = CWorldManager::ObjectId(_iX, _iY);
  if ( v8 )
  {
    pDbgDecoObject = (IDecoObject *)CDecoObjMgr::GetDecoObjPtr(v8);
    if ( !pDbgDecoObject && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 94, "pDbgDecoObject != 0") == 1 )
      __debugbreak();
    if ( pDbgDecoObject )
    {
      iDbgType = IEntity::Type(pDbgDecoObject);
      if ( IDecoObject::IsStaticInstance(pDbgDecoObject) )
      {
        if ( iDbgType != IEntity::Type(this)
          && CDecoObjMgr::GetTotalBuildingRings(&g_cDecoObjMgr, iDbgType)
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
  CWorldManager::SetObjectId(_iX, _iY, _iId);
  return this;
}


// address=[0x1541700]
// Decompiled from IDecoObject *__thiscall IDecoObject::IDecoObject(  IDecoObject *this,  const struct IDecoObject *_rStaticDecoObject,  int _iId,  unsigned int _iX,  unsigned int _iY)
 IDecoObject::IDecoObject(class IDecoObject const & _rStaticDecoObject, int _iId, int _iX, int _iY) {
  
  int v5; // esi

  IAnimatedEntity::IAnimatedEntity(this, _iId);
  this->__vftable = (IAnimatedEntity_vtbl *)&IDecoObject::_vftable_;
  this->m_bStaticInstance = 0;
  if ( _rStaticDecoObject->m_uObjType != LANDSCAPE_OBJ
    && BBSupportDbgReportF(
         2,
         "MapObjects\\DecoObj\\DecoObj.cpp",
         133,
         "%u == LANDSCAPE_OBJ",
         _rStaticDecoObject->m_uObjType) == 1 )
  {
    __debugbreak();
  }
  if ( !_rStaticDecoObject->m_bStaticInstance
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 134, "_rStaticDecoObject.m_bStaticInstance") == 1 )
  {
    __debugbreak();
  }
  if ( _iId <= 0 && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 135, "_iId > 0") == 1 )
    __debugbreak();
  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 136, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  this->m_uObjType = LANDSCAPE_OBJ;
  this->m_nType = _rStaticDecoObject->m_nType;
  this->m_iFrame = 0;
  IEntity::SetFlagBits(this, EntityFlag_Visible);
  if ( CWorldManager::ObjectId(_iX, _iY) )
  {
    v5 = CWorldManager::ObjectId(_iX, _iY);
    if ( v5 != IEntity::EntityId(&_rStaticDecoObject->IAnimatedEntity)
      && BBSupportDbgReport(
           2,
           "MapObjects\\DecoObj\\DecoObj.cpp",
           145,
           "( g_cWorld.ObjectId( _iX, _iY ) == 0 ) || ( g_cWorld.ObjectId( _iX, _iY ) == _rStaticDecoObject.EntityId() )") == 1 )
    {
      __debugbreak();
    }
  }
  IEntity::SetPosition(this, _iX, _iY);
  CWorldManager::SetObjectId(_iX, _iY, _iId);
  return this;
}


// address=[0x15418d0]
// Decompiled from int __thiscall IDecoObject::~IDecoObject(IDecoObject *this)
 IDecoObject::~IDecoObject(void) {
  
  unsigned int v1; // eax
  int v2; // eax
  int v3; // esi
  int v4; // eax
  unsigned int v6; // [esp-4h] [ebp-1Ch]

  this->__vftable = (IAnimatedEntity_vtbl *)&IDecoObject::_vftable_;
  if ( this->m_bStaticInstance )
    return IAnimatedEntity::~IAnimatedEntity(this);
  if ( !IEntity::X(this)
    && !IEntity::Y(this)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 164, "! ( ( X() == 0 ) && ( Y() == 0 ) )") == 1 )
  {
    __debugbreak();
  }
  v6 = IEntity::Y(this);
  v1 = IEntity::X(this);
  if ( !CWorldManager::InWorld(v1, v6)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 165, "g_cWorld.InWorld( X(), Y() )") == 1 )
  {
    __debugbreak();
  }
  v2 = IEntity::WorldIdx();
  v3 = CWorldManager::ObjectId(v2);
  if ( v3 != IEntity::EntityId(this)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObj.cpp", 166, "g_cWorld.ObjectId( WorldIdx() ) == EntityId()") == 1 )
  {
    __debugbreak();
  }
  v4 = IEntity::WorldIdx();
  CWorldManager::SetObjectId(v4, 0);
  return IAnimatedEntity::~IAnimatedEntity(this);
}


// address=[0x1541a00]
// Decompiled from int __thiscall IDecoObject::ConvertToDarkOrGreen(IEntity *this, bool a2)
int  IDecoObject::ConvertToDarkOrGreen(bool a2) {
  
  int DarkObject; // [esp+Ch] [ebp-8h]
  int v5; // [esp+10h] [ebp-4h]

  v5 = IEntity::Type(this);
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
// Decompiled from IDecoObject *__thiscall IDecoObject::IDecoObject(IDecoObject *this, struct std::istream *a2)
 IDecoObject::IDecoObject(std::istream & a2) {
  
  int fileFormatVersion; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  IAnimatedEntity::IAnimatedEntity(this, a2);
  v6 = 0;
  this->__vftable = (IAnimatedEntity_vtbl *)&IDecoObject::_vftable_;
  operator^<unsigned int>(a2, &fileFormatVersion);
  if ( fileFormatVersion != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for IDecoObject");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<bool>(a2, &this->m_bStaticInstance);
  v6 = -1;
  return this;
}


// address=[0x1541b20]
// Decompiled from struct std::ostream *__thiscall IDecoObject::Store(const struct IDecoObject *this, struct std::ostream *a2)
void  IDecoObject::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF

  IAnimatedEntity::Store(&this->IAnimatedEntity, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  return operator^<bool>(a2, &this->m_bStaticInstance);
}


#endif // Already implemented
