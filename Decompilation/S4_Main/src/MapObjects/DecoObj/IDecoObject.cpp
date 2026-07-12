#include "IDecoObject.h"

#include <iostream>

#include "CDecoObjMgr.h"
#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "Defines/Object.h"
#include "World/CWorldManager.h"

// Definitions for class IDecoObject

// address=[0x151aae0]
// Decompiled from bool __thiscall IDecoObject::IsStaticInstance(IDecoObject *this)
bool IDecoObject::IsStaticInstance(void) const {
  return this->m_bStaticInstance;
}


// address=[0x15414c0]
// Decompiled from IDecoObject *__thiscall IDecoObject::IDecoObject(  IDecoObject *this,  unsigned int _iX,  unsigned int _iY,  T_OBJECT_TYPE _iDecoObjectType,  int _iId,  bool a6)
IDecoObject::IDecoObject(int _iX, int _iY, int _iDecoObjectType, int _iId, bool a6) : IAnimatedEntity(_iId) {
  int          iDbgType; // [esp+4h] [ebp-1Ch]
  int          v8; // [esp+8h] [ebp-18h]
  IDecoObject *pDbgDecoObject; // [esp+Ch] [ebp-14h]

  this->m_bStaticInstance = a6;

  BB_ASSERT(g_cWorld.InWorld( _iX, _iY ))
  BB_ASSERT(_iDecoObjectType > 0)
  BB_ASSERT(_iDecoObjectType < OBJECT_MAX)
  BB_ASSERT(_iId > 0)

  this->m_objType = LANDSCAPE_OBJ;
  this->m_nType = _iDecoObjectType;
  this->m_iFrame = 0;
  IEntity::SetFlagBits(EntityFlag_Visible);
  if(a6)
    IEntity::SetPosition(0, 0);
  else
    IEntity::SetPosition(_iX, _iY);
  v8 = CWorldManager::ObjectId(_iX, _iY);
  if(v8) {
    pDbgDecoObject = CDecoObjMgr::GetDecoObjPtr(v8);
    BB_ASSERT("pDbgDecoObject != 0")

    if(pDbgDecoObject) {
      iDbgType = pDbgDecoObject->Type();
      if(pDbgDecoObject->IsStaticInstance()) {
        BB_ASSERT(iDbgType == Type() || ( g_cDecoObjMgr.GetTotalBuildingRings( iDbgType ) == 0 ))
      } else if(BBSupportDbgReport(1, "MapObjects\\DecoObj\\DecoObj.cpp", 106, "Overwriting dynamic deco-object!") == 1) {
        __debugbreak();
      }
    }
  }
  CWorldManager::SetObjectId(_iX, _iY, _iId);
}


// address=[0x1541700]
// Decompiled from IDecoObject *__thiscall IDecoObject::IDecoObject(  IDecoObject *this,  const struct IDecoObject *_rStaticDecoObject,  int _iId,  unsigned int _iX,  unsigned int _iY)
IDecoObject::IDecoObject(class IDecoObject const &_rStaticDecoObject, int _iId, int _iX, int _iY) : IAnimatedEntity(_iId) {
  int v5; // esi

  this->m_bStaticInstance = 0;
  BB_ASSERT(_rStaticDecoObject.m_objType == LANDSCAPE_OBJ)
  BB_ASSERT(_rStaticDecoObject.m_bStaticInstance)
  BB_ASSERT(_iId > 0)
  BB_ASSERT(g_cWorld.InWorld( _iX, _iY ))

  this->m_objType = LANDSCAPE_OBJ;
  this->m_nType = _rStaticDecoObject.m_nType;
  this->m_iFrame = 0;
  IEntity::SetFlagBits(EntityFlag_Visible);
  BB_ASSERT(( g_cWorld.ObjectId( _iX, _iY ) == 0 ) || ( g_cWorld.ObjectId( _iX, _iY ) == _rStaticDecoObject.EntityId() ))
  IEntity::SetPosition(_iX, _iY);
  CWorldManager::SetObjectId(_iX, _iY, _iId);
}


// address=[0x15418d0]
// Decompiled from int __thiscall IDecoObject::~IDecoObject(IDecoObject *this)
IDecoObject::~IDecoObject(void) {
  if(this->m_bStaticInstance)
    return;

  BB_ASSERT(! ( ( X() == 0 ) && ( Y() == 0 ) ))
  BB_ASSERT(g_cWorld.InWorld( X(), Y() ))
  BB_ASSERT(g_cWorld.ObjectId( WorldIdx() ) == EntityId())

  CWorldManager::SetObjectId(IEntity::WorldIdx(), 0);
  return;
}


// address=[0x1541a00]
// Decompiled from int __thiscall IDecoObject::ConvertToDarkOrGreen(IEntity *this, bool a2)
int IDecoObject::ConvertToDarkOrGreen(bool a2) {
  int DarkObject; // [esp+Ch] [ebp-8h]
  int v5; // [esp+10h] [ebp-4h]

  v5 = IEntity::Type();
  if(a2)
    DarkObject = CDarkConvert::GetDarkObject(v5);
  else
    DarkObject = CDarkConvert::GetGreenObject(v5);
  if(DarkObject)
    return DarkObject;
  else
    return v5;
}


// address=[0x1541a60]
// Decompiled from IDecoObject *__thiscall IDecoObject::IDecoObject(IDecoObject *this, struct std::istream *a2)
IDecoObject::IDecoObject(std::istream &a2) : IAnimatedEntity(a2) {
  int fileFormatVersion; // [esp+8h] [ebp-18h] BYREF
  a2 >> fileFormatVersion;
  if(fileFormatVersion != 1) {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for IDecoObject");
    throw CS4InvalidMapException();
  }
  a2 >> this->m_bStaticInstance;
}


// address=[0x1541b20]
// Decompiled from struct std::ostream *__thiscall IDecoObject::Store(const struct IDecoObject *this, struct std::ostream *a2)
void IDecoObject::Store(std::ostream &a2) {
  IAnimatedEntity::Store(a2);
  int fileFormatVersion = 1;
  a2 << fileFormatVersion;
  a2 << this->m_bStaticInstance;
}


