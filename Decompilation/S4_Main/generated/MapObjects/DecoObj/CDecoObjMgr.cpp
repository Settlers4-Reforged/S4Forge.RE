#if FALSE
#include "CDecoObjMgr.h"

// Definitions for class CDecoObjMgr

// address=[0x1326ec0]
// Decompiled from IEntity *__cdecl CDecoObjMgr::GetDecoObjPtr(int a1)
class IDecoObject * __cdecl CDecoObjMgr::GetDecoObjPtr(int a1) {
  
  IEntity *v3; // [esp+8h] [ebp-4h]

  v3 = CMapObjectMgr::EntityPtr(a1);
  if ( v3 && IEntity::ObjType(v3) == DECO_OBJ_2 )
    return v3;
  else
    return 0;
}


// address=[0x1486f90]
// Decompiled from int __thiscall CDecoObjMgr::GetXMLVersion(CDecoObjMgr *this)
int  CDecoObjMgr::GetXMLVersion(void)const {
  
  return this->m_iXmlVersion;
}


// address=[0x15423a0]
// Decompiled from uint __thiscall CDecoObjMgr::Alloc(CDecoObjMgr *this, uint a2)
void *  CDecoObjMgr::Alloc(unsigned int a2) {
  
  return MemoryAllocator::allocate(&this->m_cAllocator, a2);
}


// address=[0x1542400]
// Decompiled from void __thiscall CDecoObjMgr::Dealloc(CDecoObjMgr *this, uint *a2)
void  CDecoObjMgr::Dealloc(void * a2) {
  
  MemoryAllocator::deallocate(&this->m_cAllocator, a2);
}


// address=[0x1542430]
// Decompiled from int __thiscall CDecoObjMgr::GetTotalBuildingRings(CDecoObjMgr *this, int a2)
int  CDecoObjMgr::GetTotalBuildingRings(int a2) {
  
  return this->m_aBuildingRings[a2].m_uTotalRings;
}


// address=[0x1542490]
// Decompiled from CDecoObjMgr *__thiscall CDecoObjMgr::CDecoObjMgr(CDecoObjMgr *this)
 CDecoObjMgr::CDecoObjMgr(void) {
  
  std::vector *v6; // eax
  uint v7; // eax
  _BYTE v9[16]; // [esp+4h] [ebp-44h] BYREF
  void *v10; // [esp+14h] [ebp-34h]
  void *v11; // [esp+18h] [ebp-30h] MAPDST
  int v12; // [esp+1Ch] [ebp-2Ch] BYREF
  int v13; // [esp+20h] [ebp-28h] BYREF
  int v14; // [esp+24h] [ebp-24h] BYREF
  int v15; // [esp+28h] [ebp-20h] BYREF
  int v16; // [esp+2Ch] [ebp-1Ch] BYREF
  int v17; // [esp+30h] [ebp-18h] BYREF
  int v18; // [esp+34h] [ebp-14h] BYREF
  int v20; // [esp+44h] [ebp-4h]

  v18 = 84;
  v17 = 80;
  v16 = 72;
  v15 = 80;
  v14 = 80;
  v13 = 80;
  v12 = 80;
  v11 = CreateArgv<unsigned int>(v9, (int)&v12);
  v10 = v11;
  v20 = 0;
  v11 = TArgv<unsigned int,std::vector<unsigned int>>::operator()(v11, (int)&v13);
  v11 = TArgv<unsigned int,std::vector<unsigned int>>::operator()(v11, (int)&v14);
  v11 = TArgv<unsigned int,std::vector<unsigned int>>::operator()(v11, (int)&v15);
  v11 = TArgv<unsigned int,std::vector<unsigned int>>::operator()(v11, (int)&v16);
  v11 = TArgv<unsigned int,std::vector<unsigned int>>::operator()(v11, (int)&v17);
  v6 = (std::vector *)TArgv<unsigned int,std::vector<unsigned int>>::operator()(v11, (int)&v18);
  v7 = maxInVector(v6);
  MemoryAllocator::MemoryAllocator(&this->m_cAllocator, v7, 32u, 0);
  LOBYTE(v20) = 2;
  TArgv<unsigned int,std::vector<unsigned int>>::~TArgv<unsigned int,std::vector<unsigned int>>(v9);
  this->m_iXmlVersion = 0;
  this->m_bHasLoaded = 0;
  memset(this->m_aBuildingRings, 0, sizeof(this->m_aBuildingRings));
  CDecoObjMgr::Clear(this);
  return this;
}


// address=[0x15425c0]
// Decompiled from void __thiscall CDecoObjMgr::~CDecoObjMgr(CDecoObjMgr *this)
 CDecoObjMgr::~CDecoObjMgr(void) {
  
  MemoryAllocator::~MemoryAllocator(&this->m_cAllocator);
}


// address=[0x15425e0]
// Decompiled from void *__thiscall CDecoObjMgr::Clear(CDecoObjMgr *this)
void  CDecoObjMgr::Clear(void) {
  
  return memset(this->m_aObjects, 0, sizeof(this->m_aObjects));
}


// address=[0x1542610]
// Decompiled from void __thiscall CDecoObjMgr::LoadInfo(CDecoObjMgr *this)
void  CDecoObjMgr::LoadInfo(void) {
  
  if ( !this->m_bHasLoaded )
    CDecoObjMgr::ReadObjectInfos(this);
  this->m_bHasLoaded = 1;
}


// address=[0x1542640]
// Decompiled from char __thiscall CDecoObjMgr::IsAddDecoObjOk(  CDecoObjMgr *this,  unsigned int _iX,  unsigned int _iY,  T_OBJECT_TYPE _iDecoType,  bool a5,  int _iExtraBuildingRings)
bool  CDecoObjMgr::IsAddDecoObjOk(int _iX, int _iY, int _iDecoType, bool a5, int _iExtraBuildingRings) {
  
  int v7; // [esp+0h] [ebp-3Ch]
  int v8; // [esp+4h] [ebp-38h]
  int v9; // [esp+8h] [ebp-34h]
  int iTotalRings; // [esp+Ch] [ebp-30h] BYREF
  int v11; // [esp+10h] [ebp-2Ch]
  unsigned int v13; // [esp+18h] [ebp-24h]
  unsigned int v14; // [esp+1Ch] [ebp-20h]
  int v15; // [esp+20h] [ebp-1Ch]
  unsigned int v16; // [esp+24h] [ebp-18h]
  unsigned int v17; // [esp+28h] [ebp-14h]
  int iTotalBlockingOrRepellingRings; // [esp+2Ch] [ebp-10h] BYREF
  int j; // [esp+30h] [ebp-Ch]
  int i; // [esp+34h] [ebp-8h]
  BYTE v21; // [esp+3Bh] [ebp-1h] BYREF

  if ( (_iDecoType <= OBJECT_NO_OBJECT || _iDecoType >= OBJECT_MAX)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 358, "_iDecoType > 0 && _iDecoType < OBJECT_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( _iExtraBuildingRings < 0
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 359, "_iExtraBuildingRings >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( !CWorldManager::InWorld(_iX, _iY) )
    return 0;
  if ( CWorldManager::FlagBits(_iX, _iY, 0x7Bu) )
    return 0;
  if ( !a5 && CWorldManager::ObjectId(_iX, _iY) )
    return 0;
  CDecoObjMgr::GetDecoObjectFlagsInfo(this, _iDecoType, &v21, &iTotalBlockingOrRepellingRings, &iTotalRings);
  if ( v21 )
  {
    if ( iTotalBlockingOrRepellingRings != 1
      && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 418, "iTotalBlockingOrRepellingRings == 1") == 1 )
    {
      __debugbreak();
    }
  }
  else
  {
    v11 = CSpiralOffsets::First(iTotalBlockingOrRepellingRings);
    for ( i = 0; i < v11; ++i )
    {
      v16 = _iX + CSpiralOffsets::DeltaX(i);
      v17 = _iY + CSpiralOffsets::DeltaY(i);
      if ( !CWorldManager::InWorld(v16, v17) )
        return 0;
      v15 = CWorldManager::Index(v16, v17);
      if ( CWorldManager::MapObjectId(v15) )
        return 0;
      if ( CWorldManager::FlagBits(v15, 0x7Bu) )
        return 0;
    }
  }
  v9 = CSpiralOffsets::First(iTotalBlockingOrRepellingRings);
  v8 = CSpiralOffsets::First(_iExtraBuildingRings + iTotalRings);
  for ( j = v9; j < v8; ++j )
  {
    v13 = _iX + CSpiralOffsets::DeltaX(j);
    v14 = _iY + CSpiralOffsets::DeltaY(j);
    if ( !CWorldManager::InWorld(v13, v14) )
      return 0;
    v7 = CWorldManager::Index(v13, v14);
    if ( CWorldManager::FlagBits(v7, 0x7Bu) )
      return 0;
  }
  return 1;
}


// address=[0x15428b0]
// Decompiled from int __thiscall CDecoObjMgr::AddDecoObj(  CDecoObjMgr *this,  unsigned int _iX,  unsigned int _iY,  int _iDecoType,  int _iAmount,  int _iGrownState)
int  CDecoObjMgr::AddDecoObj(int _iX, int _iY, int _iDecoType, int _iAmount, enum CDecoObjMgr::TGROWN_STATE _iGrownState) {
  
  int v7; // [esp+4h] [ebp-8h]

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 464, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( (_iDecoType <= 0 || _iDecoType >= 291)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 465, "_iType>0 && _iType<OBJECT_MAX") == 1 )
  {
    __debugbreak();
  }
  v7 = CDecoObjMgr::Create(this, _iX, _iY, _iDecoType, _iAmount, _iGrownState, 0, 0);
  CDecoObjMgr::SetFlagsForObject(this, _iX, _iY, _iDecoType, 0);
  return v7;
}


// address=[0x1542970]
// Decompiled from int __thiscall CDecoObjMgr::AddReef(  CDecoObjMgr *this,  unsigned int _iX,  unsigned int _iY,  T_OBJECT_TYPE _iDecoType,  int _iAmount,  int _iGrownState)
int  CDecoObjMgr::AddReef(int _iX, int _iY, int _iDecoType, int _iAmount, enum CDecoObjMgr::TGROWN_STATE _iGrownState) {
  
  int v7; // [esp+0h] [ebp-14h]
  int v8; // [esp+4h] [ebp-10h]
  IEntity *DecoObjPtr; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 501, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( (_iDecoType <= OBJECT_NO_OBJECT || _iDecoType >= OBJECT_MAX)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 502, "_iType>0 && _iType<OBJECT_MAX") == 1 )
  {
    __debugbreak();
  }
  v7 = CDecoObjMgr::Create(this, _iX, _iY, _iDecoType, _iAmount, _iGrownState, 0, 0);
  v8 = CWorldManager::Index(_iX, _iY);
  v11 = CWorldManager::ObjectId(v8);
  if ( !v11 )
    return v7;
  DecoObjPtr = CDecoObjMgr::GetDecoObjPtr(v11);
  if ( !DecoObjPtr )
    return v7;
  if ( IEntity::Type(DecoObjPtr) == _iDecoType )
    CDecoObjMgr::SetFlagsForObject(this, _iX, _iY, _iDecoType, 1);
  else
    BBSupportTracePrintF(3, "Reef couldn't be set!");
  return v7;
}


// address=[0x1542a80]
// Decompiled from int __thiscall CDecoObjMgr::AddDecoObjWithoutFlags(  CDecoObjMgr *this,  unsigned int _iX,  unsigned int _iY,  T_OBJECT_TYPE _iType,  unsigned int _iAmount,  int _iGrownState)
int  CDecoObjMgr::AddDecoObjWithoutFlags(int _iX, int _iY, int _iType, int _iAmount, enum CDecoObjMgr::TGROWN_STATE _iGrownState) {
  
  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 553, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( (_iType <= OBJECT_NO_OBJECT || _iType >= OBJECT_MAX)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 554, "_iType>0 && _iType<OBJECT_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( _iAmount >= 0x10
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 557, "_iAmount>=0 && _iAmount<MAX_RESOURCE_AMOUNT") == 1 )
  {
    __debugbreak();
  }
  return CDecoObjMgr::Create(this, _iX, _iY, _iType, _iAmount, _iGrownState, 0, 0);
}


// address=[0x1542b50]
// Decompiled from int __thiscall CDecoObjMgr::AddLoadedDecoObj(  CDecoObjMgr *this,  int _iX,  int _iY,  T_OBJECT_TYPE _iType,  unsigned int _iAmount,  int _iSlot,  char a7,  int _pInStream)
int  CDecoObjMgr::AddLoadedDecoObj(int _iX, int _iY, int _iType, int _iAmount, int _iSlot, bool a7, std::istream * _pInStream) {
  
  if ( (_iType <= OBJECT_NO_OBJECT || _iType >= OBJECT_MAX)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 584, "_iType>0 && _iType<OBJECT_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( _iAmount >= 0x10
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 589, "_iAmount>=0 && _iAmount<MAX_RESOURCE_AMOUNT") == 1 )
  {
    __debugbreak();
  }
  if ( a7 )
    return CDecoObjMgr::Create(this, _iX, _iY, _iType, _iAmount, 1, _iSlot, _pInStream);
  else
    return CDecoObjMgr::Create(this, _iX, _iY, _iType, _iAmount, 0, _iSlot, _pInStream);
}


// address=[0x1542c20]
// Decompiled from void __thiscall CDecoObjMgr::Delete(CDecoObjMgr *this, int _iEntityId)
void  CDecoObjMgr::Delete(int _iEntityId) {
  
  IDecoObject *DecoObjPtr; // eax
  unsigned int v3; // eax
  unsigned int v4; // [esp-Ch] [ebp-14h]
  int v5; // [esp-8h] [ebp-10h]
  IEntity *v7; // [esp+4h] [ebp-4h]

  if ( _iEntityId )
  {
    if ( !CDecoObjMgr::GetDecoObjPtr(_iEntityId)
      && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 610, "GetDecoObjPtr( _iEntityId ) != 0") == 1 )
    {
      __debugbreak();
    }
    DecoObjPtr = (IDecoObject *)CDecoObjMgr::GetDecoObjPtr(_iEntityId);
    if ( IDecoObject::IsStaticInstance(DecoObjPtr) )
    {
      if ( BBSupportDbgReport(
             2,
             "MapObjects\\DecoObj\\DecoObjMgr.cpp",
             611,
             "GetDecoObjPtr( _iEntityId )->IsStaticInstance() == false") == 1 )
        __debugbreak();
    }
    v7 = CMapObjectMgr::Entity(_iEntityId);
    v5 = IEntity::Type(v7);
    v4 = IEntity::Y(v7);
    v3 = IEntity::X(v7);
    CDecoObjMgr::ClearFlagsForObject(this, v3, v4, v5, 0);
    CMapObjectMgr::Destroy(g_pMapObjectMgr, _iEntityId);
  }
}


// address=[0x1542cf0]
// Decompiled from void __thiscall CDecoObjMgr::DeleteWithoutFlags(CDecoObjMgr *this, int _iEntityId)
void  CDecoObjMgr::DeleteWithoutFlags(int _iEntityId) {
  
  IDecoObject *pDecoObj; // [esp+8h] [ebp-4h]

  if ( _iEntityId )
  {
    pDecoObj = (IDecoObject *)CDecoObjMgr::GetDecoObjPtr(_iEntityId);
    if ( !pDecoObj && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 633, "pDecoObj != 0") == 1 )
      __debugbreak();
    if ( pDecoObj )
    {
      if ( IDecoObject::IsStaticInstance(pDecoObj) )
      {
        if ( BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 637, "pDecoObj->IsStaticInstance() == false") == 1 )
          __debugbreak();
      }
      CMapObjectMgr::Entity(_iEntityId);
      CMapObjectMgr::Destroy(g_pMapObjectMgr, _iEntityId);
    }
  }
}


// address=[0x1542da0]
// Decompiled from int __thiscall CDecoObjMgr::RemoveDecoObject(CDecoObjMgr *this, unsigned int _iX, unsigned int _iY, bool a4)
int  CDecoObjMgr::RemoveDecoObject(int _iX, int _iY, bool a4) {
  
  int v4; // eax
  int v7; // [esp+4h] [ebp-Ch]
  IEntity *DecoObjPtr; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 2194, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  v9 = CWorldManager::Index(_iX, _iY);
  v7 = CWorldManager::ObjectId(v9);
  if ( !v7 )
    return 0;
  DecoObjPtr = CDecoObjMgr::GetDecoObjPtr(v7);
  if ( !DecoObjPtr )
    return -1;
  if ( IDecoObject::IsStaticInstance((IDecoObject *)DecoObjPtr) )
  {
    CWorldManager::SetObjectId(v9, 0);
    v4 = IEntity::Type(DecoObjPtr);
    CDecoObjMgr::ClearFlagsForObject(this, _iX, _iY, v4, 0);
  }
  else if ( !a4 )
  {
    CDecoObjMgr::Delete(this, v7);
    if ( CWorldManager::ObjectId(v9) )
    {
      if ( BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 2215, "g_cWorld.ObjectId( iWorldIdx ) == 0") == 1 )
        __debugbreak();
    }
  }
  CWorldManager::SetResource(v9, 0, 0);
  return 1;
}


// address=[0x1542ed0]
// Decompiled from int __thiscall CDecoObjMgr::RemoveReef(CDecoObjMgr *this, unsigned int _iX, unsigned int _iY, bool a4)
int  CDecoObjMgr::RemoveReef(int _iX, int _iY, bool a4) {
  
  int v4; // eax
  int v7; // [esp+4h] [ebp-Ch]
  IEntity *DecoObjPtr; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 2241, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  v9 = CWorldManager::Index(_iX, _iY);
  v7 = CWorldManager::ObjectId(v9);
  if ( !v7 )
    return 0;
  DecoObjPtr = CDecoObjMgr::GetDecoObjPtr(v7);
  if ( !DecoObjPtr )
    return -1;
  if ( IDecoObject::IsStaticInstance((IDecoObject *)DecoObjPtr) )
  {
    CWorldManager::SetObjectId(v9, 0);
    v4 = IEntity::Type(DecoObjPtr);
    CDecoObjMgr::ClearFlagsForObject(this, _iX, _iY, v4, 1);
  }
  else if ( !a4 )
  {
    CDecoObjMgr::Delete(this, v7);
    if ( CWorldManager::ObjectId(v9) )
    {
      if ( BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 2261, "g_cWorld.ObjectId( iWorldIdx ) == 0") == 1 )
        __debugbreak();
    }
  }
  CWorldManager::SetResource(v9, 0, 0);
  return 1;
}


// address=[0x1543000]
// Decompiled from int __thiscall CDecoObjMgr::GetDecoObjectFlagsInfo(  CDecoObjMgr *this,  T_OBJECT_TYPE _iDecoType,  BYTE *a3,  int *_rTotalBlockingOrRepellingRing,  int *_rTotalRings)
void  CDecoObjMgr::GetDecoObjectFlagsInfo(int _iDecoType, bool & a3, int & _rTotalBlockingOrRepellingRing, int & _rTotalRings) {
  
  int result; // eax

  if ( (_iDecoType <= OBJECT_NO_OBJECT || _iDecoType >= OBJECT_MAX)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 680, "_iDecoType > 0 && _iDecoType < OBJECT_MAX") == 1 )
  {
    __debugbreak();
  }
  *a3 = this->m_aBuildingRings[_iDecoType].m_uUnknown;
  *_rTotalBlockingOrRepellingRing = this->m_aBuildingRings[_iDecoType].m_uTotalBlockingOrRepellingRings;
  result = this->m_aBuildingRings[_iDecoType].m_uTotalRings;
  *_rTotalRings = result;
  return result;
}


// address=[0x1543080]
// Decompiled from int __thiscall CDecoObjMgr::SetFlagsForObject(  CDecoObjMgr *this,  unsigned int a2,  unsigned int a3,  T_OBJECT_TYPE a4,  bool a5)
void  CDecoObjMgr::SetFlagsForObject(int a2, int a3, int a4, bool a5) {
  
  int result; // eax
  int v6; // [esp+0h] [ebp-48h]
  int v7; // [esp+4h] [ebp-44h]
  int v8; // [esp+8h] [ebp-40h] BYREF
  int v9; // [esp+Ch] [ebp-3Ch]
  CDecoObjMgr *v10; // [esp+10h] [ebp-38h]
  int v11; // [esp+14h] [ebp-34h]
  int v12; // [esp+18h] [ebp-30h]
  int v13; // [esp+1Ch] [ebp-2Ch]
  unsigned int v14; // [esp+20h] [ebp-28h]
  unsigned int v15; // [esp+24h] [ebp-24h]
  unsigned int v16; // [esp+28h] [ebp-20h]
  unsigned int v17; // [esp+2Ch] [ebp-1Ch]
  int v18; // [esp+30h] [ebp-18h] BYREF
  unsigned int v19; // [esp+34h] [ebp-14h]
  unsigned int v20; // [esp+38h] [ebp-10h]
  int i; // [esp+3Ch] [ebp-Ch]
  int j; // [esp+40h] [ebp-8h]
  BYTE v23; // [esp+47h] [ebp-1h] BYREF

  v10 = this;
  if ( !CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 738, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( (a4 <= OBJECT_NO_OBJECT || a4 >= OBJECT_MAX)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 739, "_iDecoType > 0 && _iDecoType < OBJECT_MAX") == 1 )
  {
    __debugbreak();
  }
  CDecoObjMgr::GetDecoObjectFlagsInfo(v10, a4, &v23, &v18, &v8);
  if ( v23 )
  {
    if ( v18 != 1
      && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 775, "iTotalBlockingOrRepellingRings == 1") == 1 )
    {
      __debugbreak();
    }
    if ( a5 )
      v12 = 58;
    else
      v12 = 123;
    if ( CWorldManager::FlagBits(a2, a3, v12)
      && BBSupportDbgReport(
           2,
           "MapObjects\\DecoObj\\DecoObjMgr.cpp",
           777,
           "g_cWorld.FlagBits( _iX, _iY, _bReefs?REEF_CHECK_FLAGS_MASK:DECO_OBJ_CHECK_FLAGS_MASK ) == 0") == 1 )
    {
      __debugbreak();
    }
    CWorldManager::SetFlagBits(a2, a3, 2);
    CWorldManager::SetFlagBits(a2, a3, 64);
  }
  else
  {
    v9 = CSpiralOffsets::First(v18);
    for ( i = 0; i < v9; ++i )
    {
      v19 = a2 + CSpiralOffsets::DeltaX(i);
      v20 = a3 + CSpiralOffsets::DeltaY(i);
      if ( !CWorldManager::InWorld(v19, v20)
        && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 760, "g_cWorld.InWorld( iWorkX, iWorkY )") == 1 )
      {
        __debugbreak();
      }
      if ( a5 )
        v13 = 58;
      else
        v13 = 123;
      if ( CWorldManager::FlagBits(v19, v20, v13)
        && BBSupportDbgReport(
             2,
             "MapObjects\\DecoObj\\DecoObjMgr.cpp",
             762,
             "g_cWorld.FlagBits( iWorkX, iWorkY, _bReefs?REEF_CHECK_FLAGS_MASK:DECO_OBJ_CHECK_FLAGS_MASK ) == 0") == 1 )
      {
        __debugbreak();
      }
      CWorldManager::SetBlockedPosition(v19, v20);
      CWorldManager::SetFlagBits(v19, v20, 64);
      if ( a5 )
        g_pTiling->SetBlockedWater(v19, v20);
    }
  }
  v7 = CSpiralOffsets::First(v18);
  v6 = CSpiralOffsets::First(v8);
  for ( j = v7; ; ++j )
  {
    result = j;
    if ( j >= v6 )
      break;
    v16 = a2 + CSpiralOffsets::DeltaX(j);
    v17 = a3 + CSpiralOffsets::DeltaY(j);
    if ( !CWorldManager::InWorld(v16, v17)
      && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 795, "g_cWorld.InWorld( iWorkX, iWorkY )") == 1 )
    {
      __debugbreak();
    }
    if ( a5 )
      v11 = 58;
    else
      v11 = 123;
    if ( CWorldManager::FlagBits(v16, v17, v11)
      && BBSupportDbgReport(
           2,
           "MapObjects\\DecoObj\\DecoObjMgr.cpp",
           796,
           "g_cWorld.FlagBits( iWorkX, iWorkY, _bReefs?REEF_CHECK_FLAGS_MASK:DECO_OBJ_CHECK_FLAGS_MASK ) == 0") == 1 )
    {
      __debugbreak();
    }
    CWorldManager::SetFlagBits(v16, v17, 64);
  }
  if ( a5 )
  {
    for ( j = 0; j < 100; ++j )
    {
      v14 = a2 + CSpiralOffsets::DeltaX(j);
      v15 = a3 + CSpiralOffsets::DeltaY(j);
      if ( !CWorldManager::InWorld(v14, v15)
        && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 808, "g_cWorld.InWorld( iWorkX, iWorkY )") == 1 )
      {
        __debugbreak();
      }
      if ( CWorldManager::FlagBits(v14, v15, 0x3Au)
        && BBSupportDbgReport(
             2,
             "MapObjects\\DecoObj\\DecoObjMgr.cpp",
             810,
             "g_cWorld.FlagBits( iWorkX, iWorkY, FLAG_REPELLING_LAND | FLAG_BUILDING | FLAG_DIG | FLAG_WORK ) == 0") == 1 )
      {
        __debugbreak();
      }
      g_pTiling->SetBlockedWater(v14, v15);
      result = j + 1;
    }
  }
  return result;
}


// address=[0x15434b0]
// Decompiled from void __thiscall CDecoObjMgr::ClearFlagsForObject(  CDecoObjMgr *this,  unsigned int _iX,  unsigned int _iY,  int _iDecoType,  bool a5)
void  CDecoObjMgr::ClearFlagsForObject(int _iX, int _iY, int _iDecoType, bool a5) {
  
  int v5; // [esp+0h] [ebp-3Ch]
  int v6; // [esp+4h] [ebp-38h]
  int v7; // [esp+8h] [ebp-34h] BYREF
  int v8; // [esp+Ch] [ebp-30h]
  int iTotalBlockingOrRepellingRings; // [esp+24h] [ebp-18h] BYREF
  unsigned int iWorkX; // [esp+28h] [ebp-14h] MAPDST
  unsigned int iWorkY; // [esp+2Ch] [ebp-10h] MAPDST
  int i; // [esp+30h] [ebp-Ch]
  int j; // [esp+34h] [ebp-8h]
  bool v19; // [esp+3Bh] [ebp-1h] BYREF

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 827, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( (_iDecoType <= 0 || _iDecoType >= OBJECT_MAX)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 828, "_iDecoType > 0 && _iDecoType < OBJECT_MAX") == 1 )
  {
    __debugbreak();
  }
  CDecoObjMgr::GetDecoObjectFlagsInfo(this, _iDecoType, &v19, &iTotalBlockingOrRepellingRings, &v7);
  if ( v19 )
  {
    if ( iTotalBlockingOrRepellingRings != 1
      && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 863, "iTotalBlockingOrRepellingRings == 1") == 1 )
    {
      __debugbreak();
    }
    if ( !CWorldManager::FlagBits(_iX, _iY, 0x7Bu)
      && BBSupportDbgReport(
           2,
           "MapObjects\\DecoObj\\DecoObjMgr.cpp",
           865,
           "g_cWorld.FlagBits( _iX, _iY, DECO_OBJ_CHECK_FLAGS_MASK ) != 0") == 1 )
    {
      __debugbreak();
    }
    CWorldManager::ClearFlagBits(_iX, _iY, 2);
    CWorldManager::ClearFlagBits(_iX, _iY, 64);
  }
  else
  {
    v8 = CSpiralOffsets::First(iTotalBlockingOrRepellingRings);
    for ( i = 0; i < v8; ++i )
    {
      iWorkX = _iX + CSpiralOffsets::DeltaX(i);
      iWorkY = _iY + CSpiralOffsets::DeltaY(i);
      if ( !CWorldManager::InWorld(iWorkX, iWorkY)
        && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 849, "g_cWorld.InWorld( iWorkX, iWorkY )") == 1 )
      {
        __debugbreak();
      }
      if ( !CWorldManager::FlagBits(iWorkX, iWorkY, 0x7Bu)
        && BBSupportDbgReport(
             2,
             "MapObjects\\DecoObj\\DecoObjMgr.cpp",
             850,
             "g_cWorld.FlagBits( iWorkX, iWorkY, DECO_OBJ_CHECK_FLAGS_MASK ) != 0") == 1 )
      {
        __debugbreak();
      }
      CWorldManager::ClearBlockedPosition(iWorkX, iWorkY);
      CWorldManager::ClearFlagBits(iWorkX, iWorkY, 64);
      if ( a5 )
        g_pTiling->ClearBlockedWater(g_pTiling, iWorkX, iWorkY);
    }
  }
  v6 = CSpiralOffsets::First(iTotalBlockingOrRepellingRings);
  v5 = CSpiralOffsets::First(v7);
  for ( j = v6; j < v5; ++j )
  {
    iWorkX = _iX + CSpiralOffsets::DeltaX(j);
    iWorkY = _iY + CSpiralOffsets::DeltaY(j);
    if ( !CWorldManager::InWorld(iWorkX, iWorkY)
      && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 883, "g_cWorld.InWorld( iWorkX, iWorkY )") == 1 )
    {
      __debugbreak();
    }
    if ( !CWorldManager::FlagBits(iWorkX, iWorkY, 0x7Bu)
      && BBSupportDbgReport(
           2,
           "MapObjects\\DecoObj\\DecoObjMgr.cpp",
           884,
           "g_cWorld.FlagBits( iWorkX, iWorkY, DECO_OBJ_CHECK_FLAGS_MASK ) != 0") == 1 )
    {
      __debugbreak();
    }
    CWorldManager::ClearFlagBits(iWorkX, iWorkY, 64);
  }
  if ( a5 )
  {
    for ( j = 0; j < 100; ++j )
    {
      iWorkX = _iX + CSpiralOffsets::DeltaX(j);
      iWorkY = _iY + CSpiralOffsets::DeltaY(j);
      if ( !CWorldManager::InWorld(iWorkX, iWorkY)
        && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 896, "g_cWorld.InWorld( iWorkX, iWorkY )") == 1 )
      {
        __debugbreak();
      }
      if ( CWorldManager::FlagBits(iWorkX, iWorkY, 0x3Au)
        && BBSupportDbgReport(
             2,
             "MapObjects\\DecoObj\\DecoObjMgr.cpp",
             897,
             "g_cWorld.FlagBits( iWorkX, iWorkY, FLAG_REPELLING_LAND | FLAG_BUILDING | FLAG_DIG | FLAG_WORK ) == 0") == 1 )
      {
        __debugbreak();
      }
      g_pTiling->ClearBlockedWater(g_pTiling, iWorkX, iWorkY);
    }
  }
}


// address=[0x15438a0]
// Decompiled from T_OBJECT_TYPE __thiscall CDecoObjMgr::GetObjectType(CDecoObjMgr *this, int _iFarmerType, int _iRace, char _iGround)
int  CDecoObjMgr::GetObjectType(int _iFarmerType, int _iRace, int _iGround) {
  
  unsigned int v5; // [esp+4h] [ebp-18h]
  unsigned int v6; // [esp+8h] [ebp-14h]
  int v7; // [esp+Ch] [ebp-10h]
  char v8; // [esp+10h] [ebp-Ch]

  switch ( _iFarmerType )
  {
    case 0:
      return OBJECT_GRAPE;
    case 1:
      return OBJECT_AGAVE;
    case 2:
      if ( _iRace == 2 )
      {
        if ( (_iGround & 0xF0) == 0x40 )
          return (CGameData::Rand(g_pGameData) & 1) + 11;
        return (CGameData::Rand(g_pGameData) & 1) + 13;
      }
      else if ( _iRace == 4 )
      {
        if ( (_iGround & 0xF0) == 0x40 )
          return (CGameData::Rand(g_pGameData) & 1) + 11;
        v8 = CGameData::Rand(g_pGameData);
        if ( (v8 & 6) != 0 )
          v7 = 15;
        else
          v7 = 17;
        return v7 + (v8 & 1);
      }
      else
      {
        return (CGameData::Rand(g_pGameData) & 1) + 9;
      }
    case 3:
      v5 = CGameData::Rand(g_pGameData);
      if ( v5 >= CRandom16::PercentValue(0x32u) )
        return OBJECT_WHEAT2;
      else
        return OBJECT_WHEAT1;
    case 4:
      v6 = CGameData::Rand(g_pGameData);
      if ( v6 < CRandom16::PercentValue(0x1Eu) )
        return OBJECT_MUSHROOM_DARK1;
      if ( v6 >= CRandom16::PercentValue(0x46u) )
        return OBJECT_MUSHROOM_DARK3;
      return OBJECT_MUSHROOM_DARK2;
    case 5:
      return OBJECT_SHADOWHERB;
    case 6:
      return OBJECT_HIVE;
    case 7:
      return OBJECT_SUNFLOWER;
    default:
      return 0;
  }
}


// address=[0x1543a60]
// Decompiled from int __thiscall CDecoObjMgr::ChangeToStaticInstance(  CDecoObjMgr *this,  unsigned int _iX,  unsigned int _iY,  T_OBJECT_TYPE _iDecoType,  unsigned int a5)
void  CDecoObjMgr::ChangeToStaticInstance(int _iX, int _iY, int _iDecoType, int a5) {
  
  IDecoObject *DecoObjPtr; // eax
  IEntity *v6; // eax
  IEntity *pDecoObj; // [esp+4h] [ebp-8h]
  int iOldEntityId; // [esp+8h] [ebp-4h]

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1756, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  iOldEntityId = CWorldManager::ObjectId(_iX, _iY);
  pDecoObj = CDecoObjMgr::GetDecoObjPtr(iOldEntityId);
  if ( !iOldEntityId && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1762, "iOldEntityId != 0") == 1 )
    __debugbreak();
  if ( !pDecoObj && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1763, "pDecoObj != 0") == 1 )
    __debugbreak();
  if ( pDecoObj )
  {
    DecoObjPtr = (IDecoObject *)CDecoObjMgr::GetDecoObjPtr(iOldEntityId);
    if ( IDecoObject::IsStaticInstance(DecoObjPtr)
      && BBSupportDbgReport(
           2,
           "MapObjects\\DecoObj\\DecoObjMgr.cpp",
           1767,
           "GetDecoObjPtr( iOldEntityId )->IsStaticInstance() == false") == 1 )
    {
      __debugbreak();
    }
    v6 = CDecoObjMgr::GetDecoObjPtr(iOldEntityId);
    if ( IEntity::Type(v6) != _iDecoType
      && BBSupportDbgReport(
           2,
           "MapObjects\\DecoObj\\DecoObjMgr.cpp",
           1768,
           "GetDecoObjPtr( iOldEntityId )->Type() == _iDecoType") == 1 )
    {
      __debugbreak();
    }
  }
  CDecoObjMgr::DeleteWithoutFlags(this, iOldEntityId);
  if ( CWorldManager::ObjectId(_iX, _iY)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1774, "g_cWorld.ObjectId( _iX, _iY ) == 0") == 1 )
  {
    __debugbreak();
  }
  CDecoObjMgr::AddDecoObjWithoutFlags(this, _iX, _iY, _iDecoType, a5, 1);
  if ( !CWorldManager::ObjectId(_iX, _iY)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1779, "g_cWorld.ObjectId( _iX, _iY ) != 0") == 1 )
  {
    __debugbreak();
  }
  return 0;
}


// address=[0x1543c20]
// Decompiled from int __stdcall CDecoObjMgr::ConvertGreenToDark(int a1)
int  CDecoObjMgr::ConvertGreenToDark(int a1)const {
  
  return 23;
}


// address=[0x1543c40]
// Decompiled from int __stdcall CDecoObjMgr::ConvertDarkToGreen(int a1)
int  CDecoObjMgr::ConvertDarkToGreen(int a1)const {
  
  return 23;
}


// address=[0x1543c60]
// Decompiled from int __stdcall CDecoObjMgr::GetThisDecoObj(unsigned int _iX, unsigned int _iY, int _iRadius, int *_rX, int *_rY)
int  CDecoObjMgr::GetThisDecoObj(int _iX, int _iY, int _iRadius, int & _rX, int & _rY) {
  
  IEntity *DecoObjPtr; // eax
  int v7; // [esp+4h] [ebp-14h]
  int iY; // [esp+8h] [ebp-10h]
  int iX; // [esp+Ch] [ebp-Ch]
  int iObjectId; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 2287, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( !CWorldManager::FlagBits(_iX, _iY, 0x40u)
    && BBSupportDbgReport(
         2,
         "MapObjects\\DecoObj\\DecoObjMgr.cpp",
         2288,
         "g_cWorld.FlagBits( _iX, _iY, FLAG_DECO_OBJECT )") == 1 )
  {
    __debugbreak();
  }
  v7 = CSpiralOffsets::Last(_iRadius);
  for ( i = 1; i < v7; ++i )
  {
    iX = _iX + CSpiralOffsets::DeltaX(i);
    iY = _iY + CSpiralOffsets::DeltaY(i);
    if ( CWorldManager::FlagBits(iX, iY, 0x40u) )
    {
      iObjectId = CWorldManager::ObjectId(iX, iY);
      if ( iObjectId )
      {
        if ( !CDecoObjMgr::GetDecoObjPtr(iObjectId)
          && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 2301, "GetDecoObjPtr( iObjectId )") == 1 )
        {
          __debugbreak();
        }
        DecoObjPtr = CDecoObjMgr::GetDecoObjPtr(iObjectId);
        if ( IEntity::Type(DecoObjPtr) != OBJECT_SHADOWHERB )
        {
          *_rX = iX;
          *_rY = iY;
          return iObjectId;
        }
      }
    }
  }
  return 0;
}


// address=[0x1543dd0]
// Decompiled from bool __thiscall CDecoObjMgr::IsFlower(CDecoObjMgr *this, int _iDecoType)
bool  CDecoObjMgr::IsFlower(int _iDecoType) {
  
  return _iDecoType == OBJECT_FLOWER1
      || _iDecoType == OBJECT_FLOWER2
      || _iDecoType == OBJECT_FLOWER3
      || _iDecoType == OBJECT_FLOWER4
      || _iDecoType == OBJECT_FLOWER5;
}


// address=[0x1543e20]
// Decompiled from bool __thiscall CDecoObjMgr::IsGeologistSign(CDecoObjMgr *this, int a2)
bool  CDecoObjMgr::IsGeologistSign(int a2) {
  
  bool result; // al
  int v3; // [esp+4h] [ebp-8h]
  IEntity *v4; // [esp+8h] [ebp-4h]

  v3 = CWorldManager::ObjectId(a2);
  result = 0;
  if ( !v3 )
    return result;
  v4 = CMapObjectMgr::EntityPtr(v3);
  if ( IEntity::ObjType(v4) == DECO_OBJ_2
    && IEntity::Type(v4) >= OBJECT_SHIELD_EMPTY
    && IEntity::Type(v4) <= OBJECT_SHIELD_SULFUR3 )
  {
    return 1;
  }
  return result;
}


// address=[0x1543e90]
// Decompiled from void __thiscall CDecoObjMgr::Rod(CDecoObjMgr *this, int a2, bool a3)
void  CDecoObjMgr::Rod(int a2, bool a3) {
  
  IEntity *v3; // [esp+48h] [ebp-88h]
  CPlant *v4; // [esp+50h] [ebp-80h]
  IEntity *v5; // [esp+54h] [ebp-7Ch]
  CPlant *v6; // [esp+5Ch] [ebp-74h]
  IEntity *v7; // [esp+60h] [ebp-70h]
  CPlant *v8; // [esp+68h] [ebp-68h]
  IEntity *v9; // [esp+6Ch] [ebp-64h]
  CPlant *v10; // [esp+74h] [ebp-5Ch]
  IEntity *v11; // [esp+78h] [ebp-58h]
  CPlant *v12; // [esp+80h] [ebp-50h]
  int v13; // [esp+84h] [ebp-4Ch]
  int v14; // [esp+88h] [ebp-48h]
  int v15; // [esp+8Ch] [ebp-44h]
  int v16; // [esp+90h] [ebp-40h]
  int v17; // [esp+94h] [ebp-3Ch]
  int FreeSlot; // [esp+98h] [ebp-38h]
  IEntity *pEntity; // [esp+9Ch] [ebp-34h]
  int v21; // [esp+ACh] [ebp-24h]
  int v22; // [esp+B0h] [ebp-20h]
  int v23; // [esp+B4h] [ebp-1Ch]
  int v24; // [esp+C0h] [ebp-10h]

  v13 = CWorldManager::ObjectId(a2);
  if ( v13 )
  {
    pEntity = CMapObjectMgr::EntityPtr(v13);
    if ( IEntity::ObjType(pEntity) == DECO_OBJ_2 )
    {
      if ( !j____RTDynamicCast(
              (void **)&pEntity->__vftable,
              0,
              &IEntity__RTTI_Type_Descriptor_,
              &IDecoObject__RTTI_Type_Descriptor_,
              0)
        && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1850, "dynamic_cast<IDecoObject*>(pEntity)") == 1 )
      {
        __debugbreak();
      }
      if ( IDecoObject::IsStaticInstance((IDecoObject *)pEntity) )
      {
        v21 = IAnimatedEntity::JobPart(pEntity);
        v22 = CWorldManager::X(a2);
        v23 = CWorldManager::Y(a2);
        switch ( IEntity::Type(pEntity) )
        {
          case OBJECT_GRAPE:
            if ( v21 == OBJECT_GRAPE_CUT )
              goto LABEL_35;
            FreeSlot = CMapObjectMgr::GetFreeSlot();
            if ( FreeSlot != -1 )
            {
              v12 = (CPlant *)CPlant::operator new(0x50u);
              if ( v12 )
                CPlant::CPlant(v12, (const struct CPlant *)pEntity, FreeSlot, v22, v23);
              v11 = CMapObjectMgr::EntityPtr(FreeSlot);
              v11->Take(1);
            }
            break;
          case OBJECT_WHEAT1:
            if ( v21 == OBJECT_WHEAT1_ROT )
              goto LABEL_35;
            v17 = CMapObjectMgr::GetFreeSlot();
            if ( v17 != -1 )
            {
              v10 = (CPlant *)CPlant::operator new(0x50u);
              if ( v10 )
                CPlant::CPlant(v10, (const struct CPlant *)pEntity, v17, v22, v23);
              v9 = CMapObjectMgr::EntityPtr(v17);
              v9->Take(2);
            }
            break;
          case OBJECT_WHEAT2:
            if ( v21 == OBJECT_WHEAT2_ROT )
              goto LABEL_35;
            v16 = CMapObjectMgr::GetFreeSlot();
            if ( v16 != -1 )
            {
              v8 = (CPlant *)CPlant::operator new(0x50u);
              if ( v8 )
                CPlant::CPlant(v8, (const struct CPlant *)pEntity, v16, v22, v23);
              v7 = CMapObjectMgr::EntityPtr(v16);
              v7->Take(2);
            }
            break;
          case OBJECT_AGAVE:
            if ( v21 == OBJECT_AGAVE_ROT )
              goto LABEL_35;
            v15 = CMapObjectMgr::GetFreeSlot();
            if ( v15 != -1 )
            {
              v6 = (CPlant *)CPlant::operator new(0x50u);
              if ( v6 )
                CPlant::CPlant(v6, (const struct CPlant *)pEntity, v15, v22, v23);
              v5 = CMapObjectMgr::EntityPtr(v15);
              v5->Take(1);
            }
            break;
          case OBJECT_SUNFLOWER:
            if ( v21 == OBJECT_SUNFLOWER_ROT )
            {
LABEL_35:
              CDecoObjMgr::RemoveDecoObject(this, v22, v23, 0);
            }
            else
            {
              v14 = CMapObjectMgr::GetFreeSlot();
              if ( v14 != -1 )
              {
                v4 = (CPlant *)CPlant::operator new(0x50u);
                if ( v4 )
                  CPlant::CPlant(v4, (const struct CPlant *)pEntity, v14, v22, v23);
                v3 = CMapObjectMgr::EntityPtr(v14);
                v3->Take(2);
              }
            }
            break;
          default:
            return;
        }
      }
      else if ( a3 )
      {
        v24 = IAnimatedEntity::JobPart(pEntity);
        switch ( IEntity::Type(pEntity) )
        {
          case OBJECT_GRAPE:
            if ( v24 != OBJECT_GRAPE_GROWNUP )
              pEntity->Take(OBJECT_GRAPE_CUT - v24);
            break;
          case OBJECT_WHEAT1:
            if ( v24 != OBJECT_WHEAT1_GROWNUP )
              pEntity->Take(OBJECT_WHEAT1_ROT - v24);
            break;
          case OBJECT_WHEAT2:
            if ( v24 != OBJECT_WHEAT2_GROWNUP )
              pEntity->Take(OBJECT_WHEAT2_ROT - v24);
            break;
          case OBJECT_AGAVE:
            if ( v24 != OBJECT_AGAVE_GROWNUP )
              pEntity->Take(OBJECT_AGAVE_ROT - v24);
            break;
          case OBJECT_HIVE:
            if ( v24 != OBJECT_HIVE_FULL )
              pEntity->Take(OBJECT_HIVE_ROT2 - v24);
            break;
          case OBJECT_SUNFLOWER:
            if ( v24 != OBJECT_SUNFLOWER_GROWNUP )
              pEntity->Take(OBJECT_SUNFLOWER_ROT - v24);
            break;
          default:
            return;
        }
      }
    }
  }
}


// address=[0x1544590]
// Decompiled from void __thiscall CDecoObjMgr::Store(CDecoObjMgr *this, struct S4::CMapFile *a2)
void  CDecoObjMgr::Store(class S4::CMapFile & a2) {
  
  char *v2; // eax
  int v3; // [esp+0h] [ebp-108h] BYREF
  DWORD v4[42]; // [esp+10h] [ebp-F8h] BYREF
  unsigned int v5; // [esp+B8h] [ebp-50h]
  size_t Size; // [esp+BCh] [ebp-4Ch]
  void *Src; // [esp+C0h] [ebp-48h]
  T_SETTLER_OBJ_TYPE iObjectType; // [esp+C4h] [ebp-44h]
  IDecoObject *pEntity; // [esp+C8h] [ebp-40h] MAPDST
  T_SETTLER_OBJ_TYPE v10; // [esp+CCh] [ebp-3Ch]
  IEntity *v11; // [esp+D0h] [ebp-38h]
  int iLastId; // [esp+D4h] [ebp-34h] MAPDST
  int iVersion; // [esp+DCh] [ebp-2Ch] BYREF
  IEntity *v16; // [esp+E4h] [ebp-24h]
  int iDecoCount; // [esp+E8h] [ebp-20h] BYREF
  bool bIsStaticInstance; // [esp+F3h] [ebp-15h] MAPDST BYREF
  int i; // [esp+F4h] [ebp-14h]
  int *v22; // [esp+F8h] [ebp-10h]
  int v23; // [esp+104h] [ebp-4h]

  v22 = &v3;
  std::ostrstream::ostrstream(v4, 0, 0x40000LL, 2, 1);
  v23 = 0;
  v5 = std::ios_base::exceptions((char *)v4 + *(_DWORD *)(v4[0] + 4));
  std::ios_base::exceptions((std::ios_base *)((char *)v4 + *(_DWORD *)(v4[0] + 4)), 6);
  LOBYTE(v23) = 1;
  iVersion = 1;
  operator^<unsigned int>((struct std::ostream *)v4, &iVersion);
  operator^<bool>((struct std::ostream *)v4, &this->m_bHasLoaded);
  iDecoCount = 0;
  iLastId = CMapObjectMgr::LastUsedId();
  for ( i = 0; i <= iLastId; ++i )
  {
    v11 = CMapObjectMgr::EntityPtr(i);
    v16 = v11;
    if ( v11 )
    {
      v10 = IEntity::ObjType(v16);
      if ( v10 == DECO_OBJ_2 )
        ++iDecoCount;
    }
  }
  operator^<unsigned int>((struct std::ostream *)v4, &iDecoCount);
  for ( i = 0; i <= iLastId; ++i )
  {
    pEntity = (IDecoObject *)CMapObjectMgr::EntityPtr(i);
    if ( pEntity )
    {
      iObjectType = IEntity::ObjType(pEntity);
      if ( iObjectType == DECO_OBJ_2 )
      {
        bIsStaticInstance = IDecoObject::IsStaticInstance(pEntity);
        operator^<bool>((struct std::ostream *)v4, &bIsStaticInstance);
        ((void (__thiscall *)(IDecoObject *, DWORD *))pEntity->Store)(pEntity, v4);
      }
    }
  }
  std::ostream::put(0);
  v23 = 0;
  std::ostrstream::freeze((std::ostrstream *)v4, 1);
  v2 = std::ostrstream::rdbuf((std::ostrstream *)v4);
  Size = std::strstreambuf::pcount((std::strstreambuf *)v2);
  Src = std::ostrstream::str(v4);
  S4::CMapFile::SaveChunk(a2, 0xA4u, 0, Size, Src, 0);
  std::ostrstream::freeze((std::ostrstream *)v4, 0);
  std::ios_base::exceptions((std::ios_base *)((char *)v4 + *(_DWORD *)(v4[0] + 4)), v5);
  v23 = -1;
  std::ostrstream::`vbase destructor'((std::ostrstream *)v4);
}


// address=[0x1544810]
// Decompiled from void __thiscall CDecoObjMgr::Load(CDecoObjMgr *this, struct S4::CMapFile *a2)
void  CDecoObjMgr::Load(class S4::CMapFile & a2) {
  
  int v2; // eax
  int iX; // eax
  int iY; // [esp-18h] [ebp-158h] BYREF
  T_OBJECT_TYPE _iType; // [esp-14h] [ebp-154h]
  unsigned int _iHealth; // [esp-10h] [ebp-150h]
  int _iEntityId; // [esp-Ch] [ebp-14Ch]
  int _bIsStaticInstance; // [esp-8h] [ebp-148h]
  _DWORD *v9; // [esp-4h] [ebp-144h]
  _BYTE v10[24]; // [esp+4h] [ebp-13Ch] BYREF
  _DWORD stream[44]; // [esp+1Ch] [ebp-124h] BYREF
  unsigned int iIEntityVersion; // [esp+CCh] [ebp-74h] BYREF
  unsigned int uClassId; // [esp+D0h] [ebp-70h] BYREF
  unsigned int v14; // [esp+D4h] [ebp-6Ch]
  int v15; // [esp+D8h] [ebp-68h]
  int iObjType; // [esp+DCh] [ebp-64h] BYREF
  int v17; // [esp+E0h] [ebp-60h]
  int v18; // [esp+E4h] [ebp-5Ch] BYREF
  int a4; // [esp+E8h] [ebp-58h] BYREF
  int iPackedXY; // [esp+ECh] [ebp-54h] BYREF
  BOOL v21; // [esp+F0h] [ebp-50h]
  unsigned int iCount; // [esp+F4h] [ebp-4Ch] BYREF
  int pExceptionObject; // [esp+F8h] [ebp-48h] BYREF
  char *pData; // [esp+FCh] [ebp-44h]
  unsigned int i; // [esp+104h] [ebp-3Ch]
  unsigned __int16 iType; // [esp+108h] [ebp-38h] BYREF
  unsigned __int16 iEntityId; // [esp+10Ch] [ebp-34h] BYREF
  unsigned __int8 iHealth; // [esp+112h] [ebp-2Eh] BYREF
  unsigned __int8 bIsStaticInstance; // [esp+113h] [ebp-2Dh] BYREF
  std::string v31; // [esp+114h] [ebp-2Ch] BYREF
  int v32; // [esp+13Ch] [ebp-4h]

  BBSupportTracePrintF(0, "DecoObjMgr load");
  CDecoObjMgr::Clear(this);
  a4 = 0;
  pData = (char *)S4::CMapFile::LoadChunk(a2, MAP_CHUNK_SAVE_DECOOBJECTS, 0, &a4, 0);
  if ( pData )
  {
    std::string::string(&v31, pData);
    v32 = 0;
    std::istringstream::istringstream(&v31, 1, 1);
    LOBYTE(v32) = 1;
    v14 = std::ios_base::exceptions((char *)stream + *(_DWORD *)(stream[0] + 4));
    std::ios_base::exceptions((std::ios_base *)((char *)stream + *(_DWORD *)(stream[0] + 4)), 6);
    operator^<unsigned int>(stream, &v18);
    v17 = v18;
    if ( v18 != 1 )
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CDecoObjMgr");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    operator^<bool>(stream, &this->m_bHasLoaded);
    iCount = 0;
    operator^<unsigned int>(stream, &iCount);
    for ( i = 0; i < iCount; ++i )
    {
      bIsStaticInstance = 0;
      operator^<bool>(stream, &bIsStaticInstance);
      operator^<unsigned long>(stream, &uClassId);
      v2 = std::istream::tellg((int)v10);
      v15 = std::fpos<_Mbstatet>::operator __int64(v2);
      operator^<unsigned int>(stream, &iIEntityVersion);
      operator^<unsigned short>(stream, &iEntityId);
      operator^<unsigned short>(stream, &iType);
      operator^<int>((struct std::istream *)stream, &iPackedXY);
      operator^<unsigned char>(stream, &iHealth);
      operator^<int>((struct std::istream *)stream, &iObjType);
      v21 = (iObjType & 0x1000000) == 0;
      stream[43] = v21;
      stream[42] = &iY;
      std::fpos<_Mbstatet>::fpos<_Mbstatet>(&iY, v15, v15 >> 31);
      std::istream::seekg((char *)stream, iY, _iType, _iHealth, _iEntityId, _bIsStaticInstance, (int)v9);
      v9 = stream;
      _bIsStaticInstance = bIsStaticInstance;
      _iEntityId = iEntityId;
      _iHealth = iHealth;
      _iType = iType;
      iY = Y16X16::UnpackYFast(iPackedXY);
      iX = Y16X16::UnpackXFast(iPackedXY);
      CDecoObjMgr::AddLoadedDecoObj(this, iX, iY, _iType, _iHealth, _iEntityId, _bIsStaticInstance, (int)v9);
    }
    std::ios_base::exceptions((std::ios_base *)((char *)stream + *(_DWORD *)(stream[0] + 4)), v14);
    LOBYTE(v32) = 0;
    std::istringstream::`vbase destructor'(stream);
    v32 = -1;
    std::string::~string(&v31);
  }
}


// address=[0x1544b00]
// Decompiled from int __thiscall CDecoObjMgr::Create(  CDecoObjMgr *this,  unsigned int _iX,  unsigned int _iY,  int _iDecoType,  int _iAmount,  int _iGrownState,  int _iSlot,  struct std::istream *_pInStream)
int  CDecoObjMgr::Create(int _iX, int _iY, int _iDecoType, int _iAmount, enum CDecoObjMgr::TGROWN_STATE _iGrownState, int _iSlot, std::istream * _pInStream) {
  
  IDecoObject *DecoObjPtr; // eax
  int v9; // eax
  __int16 v10; // ax
  IDecoObject *v11; // eax
  IDecoObject *v12; // eax
  IDecoObject *v13; // eax
  int v14; // eax
  __int16 v15; // ax
  int v16; // eax
  __int16 v17; // ax
  IDecoObject *v18; // eax
  IDecoObject *v19; // eax
  int v20; // eax
  __int16 v21; // ax
  IDecoObject *v22; // eax
  IDecoObject *v23; // eax
  int ObjectFirstJob; // [esp+60h] [ebp-128h]
  int v26; // [esp+68h] [ebp-120h]
  int v27; // [esp+70h] [ebp-118h]
  int v28; // [esp+7Ch] [ebp-10Ch]
  CDecoObject *v29; // [esp+84h] [ebp-104h]
  CDecoObject *v30; // [esp+8Ch] [ebp-FCh]
  CHive *v31; // [esp+94h] [ebp-F4h]
  CHive *v32; // [esp+9Ch] [ebp-ECh]
  CMushroom *v33; // [esp+A4h] [ebp-E4h]
  CMushroom *v34; // [esp+ACh] [ebp-DCh]
  CMushroom *v35; // [esp+B0h] [ebp-D8h]
  CMushroom *v36; // [esp+B4h] [ebp-D4h]
  CMushroom *v37; // [esp+BCh] [ebp-CCh]
  CMushroom *v38; // [esp+C4h] [ebp-C4h]
  CShadowHerb *v39; // [esp+CCh] [ebp-BCh]
  CShadowHerb *v40; // [esp+D4h] [ebp-B4h]
  CPlant *v41; // [esp+DCh] [ebp-ACh]
  CPlant *v42; // [esp+E4h] [ebp-A4h]
  CPlant *v43; // [esp+E8h] [ebp-A0h]
  CPlant *v44; // [esp+ECh] [ebp-9Ch]
  CPlant *v45; // [esp+F4h] [ebp-94h]
  CPlant *v46; // [esp+FCh] [ebp-8Ch]
  IDecoObject *v47; // [esp+100h] [ebp-88h]
  CStone *v48; // [esp+104h] [ebp-84h]
  CStone *v49; // [esp+10Ch] [ebp-7Ch]
  CStone *v50; // [esp+114h] [ebp-74h]
  __int32 iIdNext; // [esp+118h] [ebp-70h]
  CStone *v52; // [esp+120h] [ebp-68h]
  CTree *v53; // [esp+128h] [ebp-60h]
  CTree *v54; // [esp+130h] [ebp-58h]
  IDecoObject *v55; // [esp+134h] [ebp-54h]
  CTree *v56; // [esp+138h] [ebp-50h]
  CTree *v57; // [esp+140h] [ebp-48h]
  CTree *v58; // [esp+148h] [ebp-40h]
  __int32 iId0; // [esp+160h] [ebp-28h]
  int v60; // [esp+168h] [ebp-20h]
  BYTE iGoodType; // [esp+16Ch] [ebp-1Ch]
  char v62; // [esp+173h] [ebp-15h]
  int iGetId; // [esp+174h] [ebp-14h]

  if ( _iSlot )
    iGetId = _iSlot;
  else
    iGetId = CMapObjectMgr::GetFreeSlot();
  switch ( _iDecoType )
  {
    case OBJECT_TREE01A:
    case OBJECT_TREE01B:
    case OBJECT_TREE02A:
    case OBJECT_TREE02B:
    case OBJECT_TREE03A:
    case OBJECT_TREE03B:
    case OBJECT_TREE04A:
    case OBJECT_TREE04B:
    case OBJECT_TREE05A:
    case OBJECT_TREE05B:
    case OBJECT_TREE06A:
    case OBJECT_TREE06B:
    case OBJECT_TREE07A:
    case OBJECT_TREE07B:
    case OBJECT_TREE08A:
    case OBJECT_TREE08B:
    case OBJECT_TREE09A:
    case OBJECT_TREE09B:
    case OBJECT_TREE10A:
    case OBJECT_TREE10B:
    case OBJECT_TREE11A:
    case OBJECT_TREE11B:
      if ( _iGrownState == 1 )
      {
        if ( !this->m_aObjects[_iDecoType].m_uU2 )
        {
          v28 = CGfxManager::GetObjectFirstJob(g_pGfxManager, _iDecoType) + 3;
          this->m_aObjects[_iDecoType].m_uFrameCount = CGfxManager::GetObjectFrameCount(g_pGfxManager, v28);
        }
        if ( (char)this->m_aObjects[_iDecoType].m_uU2 >= (char)this->m_aObjects[_iDecoType].m_uFrameCount )
        {
          if ( ++this->m_aObjects[_iDecoType].m_uCurrentFrame >= this->m_aObjects[_iDecoType].m_uFrameCount )
            this->m_aObjects[_iDecoType].m_uCurrentFrame = 0;
          if ( _pInStream )
          {
            v56 = (CTree *)CTree::operator new(0x50u);
            if ( v56 )
              v55 = (IDecoObject *)CTree::CTree(v56, (int)_pInStream);
            else
              v55 = 0;
            if ( IDecoObject::IsStaticInstance(v55) )
            {
              v9 = IEntity::ID(v55);
              CMapObjectMgr::Destroy(g_pMapObjectMgr, v9);
              CWorldManager::SetObjectId(
                _iX,
                _iY,
                this->m_aObjects[_iDecoType].m_uFrameIds[this->m_aObjects[_iDecoType].m_uCurrentFrame]);
            }
            else
            {
              v10 = IEntity::ID(v55);
              CWorldManager::SetObjectId(_iX, _iY, v10);
            }
          }
          else
          {
            CWorldManager::SetObjectId(
              _iX,
              _iY,
              this->m_aObjects[_iDecoType].m_uFrameIds[this->m_aObjects[_iDecoType].m_uCurrentFrame]);
          }
        }
        else
        {
          if ( _iSlot )
          {
            if ( !_pInStream
              && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1225, "_pInStream != 0") == 1 )
            {
              __debugbreak();
            }
            v57 = (CTree *)CTree::operator new(0x50u);
            if ( v57 )
              CTree::CTree(v57, (int)_pInStream);
          }
          else
          {
            v58 = (CTree *)CTree::operator new(0x50u);
            if ( v58 )
              CTree::CTree(v58, _iX, _iY, _iDecoType, iGetId, 3);
          }
          DecoObjPtr = (IDecoObject *)CDecoObjMgr::GetDecoObjPtr(iGetId);
          if ( !IDecoObject::IsStaticInstance(DecoObjPtr)
            && BBSupportDbgReport(
                 2,
                 "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                 1228,
                 "GetDecoObjPtr( iGetId)->IsStaticInstance()") == 1 )
          {
            __debugbreak();
          }
          this->m_aObjects[_iDecoType].m_uFrameIds[(char)this->m_aObjects[_iDecoType].m_uU2++] = iGetId;
        }
        CWorldManager::SetResource(_iX, _iY, 112, 1);
      }
      else
      {
        if ( _iSlot )
        {
          if ( !_pInStream && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1272, "_pInStream != 0") == 1 )
            __debugbreak();
          v53 = (CTree *)CTree::operator new(0x50u);
          if ( v53 )
            CTree::CTree(v53, (int)_pInStream);
        }
        else
        {
          v54 = (CTree *)CTree::operator new(0x50u);
          if ( v54 )
            CTree::CTree(v54, _iX, _iY, _iDecoType, iGetId, 0);
        }
        v11 = (IDecoObject *)CDecoObjMgr::GetDecoObjPtr(iGetId);
        if ( IDecoObject::IsStaticInstance(v11)
          && BBSupportDbgReport(
               2,
               "MapObjects\\DecoObj\\DecoObjMgr.cpp",
               1275,
               "!GetDecoObjPtr( iGetId)->IsStaticInstance()") == 1 )
        {
          __debugbreak();
        }
      }
      break;
    case OBJECT_MINESET1:
    case OBJECT_DARKMINESET1:
      v60 = _iAmount - 1;
      if ( _iAmount - 1 < 0 && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1397, "iIdx >= 0") == 1 )
        __debugbreak();
      if ( !this->m_aObjects[_iDecoType].m_uU2 )
        this->m_aObjects[_iDecoType].m_uFrameCount = 15;
      if ( this->m_aObjects[_iDecoType].m_uFrameIds[v60] )
      {
        if ( _pInStream )
        {
          v48 = (CStone *)CStone::operator new(0x48u);
          if ( v48 )
            v47 = (IDecoObject *)CStone::CStone(v48, (int)_pInStream);
          else
            v47 = 0;
          if ( IDecoObject::IsStaticInstance(v47) )
          {
            v14 = IEntity::ID(v47);
            CMapObjectMgr::Destroy(g_pMapObjectMgr, v14);
            CWorldManager::SetObjectId(_iX, _iY, this->m_aObjects[_iDecoType].m_uFrameIds[v60]);
          }
          else
          {
            v15 = IEntity::ID(v47);
            CWorldManager::SetObjectId(_iX, _iY, v15);
          }
        }
        else
        {
          CWorldManager::SetObjectId(_iX, _iY, this->m_aObjects[_iDecoType].m_uFrameIds[v60]);
        }
      }
      else
      {
        if ( _iSlot )
        {
          if ( !_pInStream && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1414, "_pInStream != 0") == 1 )
            __debugbreak();
          v49 = (CStone *)CStone::operator new(0x48u);
          if ( v49 )
            CStone::CStone(v49, (int)_pInStream);
        }
        else
        {
          v50 = (CStone *)CStone::operator new(0x48u);
          if ( v50 )
            CStone::CStone(v50, _iX, _iY, _iDecoType, _iAmount, iGetId);
        }
        v13 = (IDecoObject *)CDecoObjMgr::GetDecoObjPtr(iGetId);
        if ( IDecoObject::IsStaticInstance(v13) )
        {
          this->m_aObjects[_iDecoType].m_uFrameIds[v60] = iGetId;
          ++this->m_aObjects[_iDecoType].m_uU2;
        }
      }
      if ( _iDecoType != OBJECT_DARKMINESET1 )
        CWorldManager::SetResource(_iX, _iY, OBJECT_STONEDARKISH4, _iAmount);
      break;
    case OBJECT_STONEMINE1_00:
    case OBJECT_STONEMINE1_01:
    case OBJECT_STONEMINE1_02:
    case OBJECT_STONEMINE1_03:
    case OBJECT_STONEMINE1_04:
    case OBJECT_STONEMINE1_05:
    case OBJECT_STONEMINE1_06:
    case OBJECT_STONEMINE1_07:
    case OBJECT_STONEMINE1_08:
    case OBJECT_STONEMINE1_09:
    case OBJECT_STONEMINE1_10:
    case OBJECT_STONEMINE1_11:
    case OBJECT_STONEMINE1_12:
      iId0 = _iDecoType - OBJECT_STONEMINE1_00;
      iIdNext = _iDecoType - OBJECT_STONEMINE1_00 + 1;
      if ( !this->m_aObjects[OBJECT_MINESET1].m_uU2 )
        this->m_aObjects[OBJECT_MINESET1].m_uFrameCount = 12;
      if ( this->m_aObjects[OBJECT_MINESET1].m_uFrameIds[iId0] )
      {
        CWorldManager::SetObjectId(_iX, _iY, this->m_aObjects[OBJECT_MINESET1].m_uFrameIds[iId0]);
      }
      else
      {
        if ( !_iSlot )
        {
          v52 = (CStone *)CStone::operator new(0x48u);
          if ( v52 )
            CStone::CStone(v52, _iX, _iY, OBJECT_MINESET1, iIdNext, iGetId);
        }
        v12 = (IDecoObject *)CDecoObjMgr::GetDecoObjPtr(iGetId);
        if ( !IDecoObject::IsStaticInstance(v12)
          && BBSupportDbgReport(
               2,
               "MapObjects\\DecoObj\\DecoObjMgr.cpp",
               1315,
               "GetDecoObjPtr( iGetId)->IsStaticInstance()") == 1 )
        {
          __debugbreak();
        }
        this->m_aObjects[OBJECT_MINESET1].m_uFrameIds[iId0] = iGetId;
        this->m_aObjects[OBJECT_MINESET1].m_uU2 = this->m_aObjects[41].m_uU2 + 1;
      }
      CWorldManager::SetResource(_iX, _iY, 96, iIdNext);
      break;
    case OBJECT_GRAPE:
    case OBJECT_WHEAT1:
    case OBJECT_WHEAT2:
    case OBJECT_AGAVE:
    case OBJECT_SUNFLOWER:
      iGoodType = 0;
      switch ( _iDecoType )
      {
        case OBJECT_GRAPE:
          iGoodType = GOOD_WINE;
          break;
        case OBJECT_WHEAT1:
        case OBJECT_WHEAT2:
          iGoodType = GOOD_GRAIN;
          break;
        case OBJECT_AGAVE:
          iGoodType = GOOD_AGAVE;
          break;
        case OBJECT_SUNFLOWER:
          iGoodType = GOOD_SUNFLOWER;
          break;
        default:
          break;
      }
      if ( _iGrownState == 1 )
      {
        if ( !this->m_aObjects[_iDecoType].m_uU2 )
        {
          v27 = CGfxManager::GetObjectFirstJob(g_pGfxManager, _iDecoType) + 3;
          this->m_aObjects[_iDecoType].m_uFrameCount = CGfxManager::GetObjectFrameCount(g_pGfxManager, v27);
        }
        if ( (char)this->m_aObjects[_iDecoType].m_uU2 >= (char)this->m_aObjects[_iDecoType].m_uFrameCount )
        {
          if ( ++this->m_aObjects[_iDecoType].m_uCurrentFrame >= this->m_aObjects[_iDecoType].m_uFrameCount )
            this->m_aObjects[_iDecoType].m_uCurrentFrame = 0;
          if ( !_pInStream )
            goto LABEL_212;
          v44 = (CPlant *)CPlant::operator new(0x50u);
          if ( v44 )
            v43 = CPlant::CPlant(v44, _pInStream);
          else
            v43 = 0;
          if ( IDecoObject::IsStaticInstance(v43) )
          {
            v16 = IEntity::ID(v43);
            CMapObjectMgr::Destroy(g_pMapObjectMgr, v16);
            CWorldManager::SetObjectId(
              _iX,
              _iY,
              this->m_aObjects[_iDecoType].m_uFrameIds[this->m_aObjects[_iDecoType].m_uCurrentFrame]);
          }
          else
          {
            v17 = IEntity::ID(v43);
            CWorldManager::SetObjectId(_iX, _iY, v17);
          }
        }
        else
        {
          if ( _iSlot )
          {
            if ( !_pInStream
              && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1506, "_pInStream != 0") == 1 )
            {
              __debugbreak();
            }
            v45 = (CPlant *)CPlant::operator new(0x50u);
            if ( v45 )
              CPlant::CPlant(v45, _pInStream);
          }
          else
          {
            v46 = (CPlant *)CPlant::operator new(0x50u);
            if ( v46 )
              CPlant::CPlant(v46, _iX, _iY, (T_OBJECT_TYPE)_iDecoType, iGetId, iGoodType, 3);
          }
          if ( this->m_aObjects[_iDecoType].m_uFrameIds[(char)this->m_aObjects[_iDecoType].m_uU2]
            && BBSupportDbgReport(
                 2,
                 "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                 1509,
                 "m_vInstanceId[_iDecoType].id[ m_vInstanceId[_iDecoType].count ] == 0") == 1 )
          {
            __debugbreak();
          }
          this->m_aObjects[_iDecoType].m_uFrameIds[(char)this->m_aObjects[_iDecoType].m_uU2++] = iGetId;
        }
      }
      else
      {
        if ( _pInStream )
        {
          v41 = (CPlant *)CPlant::operator new(0x50u);
          if ( v41 )
            CPlant::CPlant(v41, _pInStream);
        }
        else
        {
          if ( !iGetId && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1546, "iGetId != 0") == 1 )
            __debugbreak();
          v42 = (CPlant *)CPlant::operator new(0x50u);
          if ( v42 )
            CPlant::CPlant(v42, _iX, _iY, (T_OBJECT_TYPE)_iDecoType, iGetId, iGoodType, 0);
        }
        v18 = (IDecoObject *)CDecoObjMgr::GetDecoObjPtr(iGetId);
        if ( IDecoObject::IsStaticInstance(v18)
          && BBSupportDbgReport(
               2,
               "MapObjects\\DecoObj\\DecoObjMgr.cpp",
               1554,
               "!GetDecoObjPtr( iGetId)->IsStaticInstance()") == 1 )
        {
          __debugbreak();
        }
      }
      break;
    case OBJECT_MUSHROOM_DARK1:
    case OBJECT_MUSHROOM_DARK2:
    case OBJECT_MUSHROOM_DARK3:
      if ( _iGrownState == 1 )
      {
        if ( !this->m_aObjects[_iDecoType].m_uU2 )
        {
          v26 = CGfxManager::GetObjectFirstJob(g_pGfxManager, _iDecoType) + 3;
          this->m_aObjects[_iDecoType].m_uFrameCount = CGfxManager::GetObjectFrameCount(g_pGfxManager, v26);
        }
        if ( (char)this->m_aObjects[_iDecoType].m_uU2 >= (char)this->m_aObjects[_iDecoType].m_uFrameCount )
        {
          if ( ++this->m_aObjects[_iDecoType].m_uCurrentFrame >= this->m_aObjects[_iDecoType].m_uFrameCount )
            this->m_aObjects[_iDecoType].m_uCurrentFrame = 0;
          if ( !_pInStream )
            goto LABEL_212;
          v36 = (CMushroom *)CMushroom::operator new(0x50u);
          if ( v36 )
            v35 = CMushroom::CMushroom(v36, _pInStream);
          else
            v35 = 0;
          if ( IDecoObject::IsStaticInstance(v35) )
          {
            v20 = IEntity::ID(v35);
            CMapObjectMgr::Destroy(g_pMapObjectMgr, v20);
            CWorldManager::SetObjectId(
              _iX,
              _iY,
              this->m_aObjects[_iDecoType].m_uFrameIds[this->m_aObjects[_iDecoType].m_uCurrentFrame]);
          }
          else
          {
            v21 = IEntity::ID(v35);
            CWorldManager::SetObjectId(_iX, _iY, v21);
          }
        }
        else
        {
          if ( _iSlot )
          {
            if ( !_pInStream
              && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1629, "_pInStream != 0") == 1 )
            {
              __debugbreak();
            }
            v37 = (CMushroom *)CMushroom::operator new(0x50u);
            if ( v37 )
              CMushroom::CMushroom(v37, _pInStream);
          }
          else
          {
            v38 = (CMushroom *)CMushroom::operator new(0x50u);
            if ( v38 )
              CMushroom::CMushroom(v38, _iX, _iY, _iDecoType, iGetId, 3);
          }
          v19 = (IDecoObject *)CDecoObjMgr::GetDecoObjPtr(iGetId);
          if ( !IDecoObject::IsStaticInstance(v19)
            && BBSupportDbgReport(
                 2,
                 "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                 1632,
                 "GetDecoObjPtr( iGetId)->IsStaticInstance()") == 1 )
          {
            __debugbreak();
          }
          this->m_aObjects[_iDecoType].m_uFrameIds[(char)this->m_aObjects[_iDecoType].m_uU2++] = iGetId;
        }
      }
      else
      {
        if ( _pInStream )
        {
          v33 = (CMushroom *)CMushroom::operator new(0x50u);
          if ( v33 )
            CMushroom::CMushroom(v33, _pInStream);
        }
        else
        {
          if ( !iGetId && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1667, "iGetId != 0") == 1 )
            __debugbreak();
          v34 = (CMushroom *)CMushroom::operator new(0x50u);
          if ( v34 )
            CMushroom::CMushroom(v34, _iX, _iY, _iDecoType, iGetId, 0);
        }
        v22 = (IDecoObject *)CDecoObjMgr::GetDecoObjPtr(iGetId);
        if ( IDecoObject::IsStaticInstance(v22)
          && BBSupportDbgReport(
               2,
               "MapObjects\\DecoObj\\DecoObjMgr.cpp",
               1675,
               "!GetDecoObjPtr( iGetId)->IsStaticInstance()") == 1 )
        {
          __debugbreak();
        }
      }
      break;
    case OBJECT_SHADOWHERB:
      if ( _iSlot )
      {
        if ( !_pInStream && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1600, "_pInStream != 0") == 1 )
          __debugbreak();
        v39 = (CShadowHerb *)CShadowHerb::operator new(0x50u);
        if ( v39 )
          CShadowHerb::CShadowHerb(v39, _pInStream);
      }
      else
      {
        v40 = (CShadowHerb *)CShadowHerb::operator new(0x50u);
        if ( v40 )
          CShadowHerb::CShadowHerb(v40, _iX, _iY, _iDecoType, iGetId, 0);
      }
      break;
    case OBJECT_HIVE:
      if ( _iSlot )
      {
        if ( !_pInStream && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1688, "_pInStream != 0") == 1 )
          __debugbreak();
        v31 = (CHive *)CHive::operator new(0x54u);
        if ( v31 )
          CHive::CHive(v31, _pInStream);
      }
      else
      {
        v32 = (CHive *)CHive::operator new(0x54u);
        if ( v32 )
          CHive::CHive(v32, _iX, _iY, _iDecoType, iGetId, 0);
      }
      break;
    default:
      if ( !this->m_aObjects[_iDecoType].m_uU2 )
      {
        ObjectFirstJob = CGfxManager::GetObjectFirstJob(g_pGfxManager, _iDecoType);
        this->m_aObjects[_iDecoType].m_uFrameCount = CGfxManager::GetObjectFrameCount(g_pGfxManager, ObjectFirstJob);
      }
      if ( (char)this->m_aObjects[_iDecoType].m_uU2 >= (char)this->m_aObjects[_iDecoType].m_uFrameCount )
      {
        if ( this->m_aObjects[_iDecoType].m_uCurrentFrame >= (char)this->m_aObjects[_iDecoType].m_uFrameCount - 1 )
          this->m_aObjects[_iDecoType].m_uCurrentFrame = 0;
        if ( (char)this->m_aObjects[_iDecoType].m_uFrameCount <= 1 )
        {
LABEL_212:
          CWorldManager::SetObjectId(
            _iX,
            _iY,
            this->m_aObjects[_iDecoType].m_uFrameIds[this->m_aObjects[_iDecoType].m_uCurrentFrame]);
        }
        else
        {
          v62 = this->m_aObjects[_iDecoType].m_uCurrentFrame + 1;
          this->m_aObjects[_iDecoType].m_uCurrentFrame = v62;
          CWorldManager::SetObjectId(_iX, _iY, this->m_aObjects[_iDecoType].m_uFrameIds[v62]);
        }
      }
      else
      {
        if ( _iSlot )
        {
          if ( !_pInStream && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1721, "_pInStream != 0") == 1 )
            __debugbreak();
          v29 = (CDecoObject *)CDecoObject::operator new(0x50u);
          if ( v29 )
            CDecoObject::CDecoObject(v29, _pInStream);
        }
        else
        {
          v30 = (CDecoObject *)CDecoObject::operator new(0x50u);
          if ( v30 )
            CDecoObject::CDecoObject(
              v30,
              _iX,
              _iY,
              _iDecoType,
              iGetId,
              (char)this->m_aObjects[_iDecoType].m_uU2,
              this->m_aBuildingRings[_iDecoType].m_bHasPingPong);
        }
        v23 = (IDecoObject *)CDecoObjMgr::GetDecoObjPtr(iGetId);
        if ( !IDecoObject::IsStaticInstance(v23)
          && BBSupportDbgReport(
               2,
               "MapObjects\\DecoObj\\DecoObjMgr.cpp",
               1724,
               "GetDecoObjPtr( iGetId)->IsStaticInstance()") == 1 )
        {
          __debugbreak();
        }
        this->m_aObjects[_iDecoType].m_uFrameIds[(char)this->m_aObjects[_iDecoType].m_uU2++] = iGetId;
      }
      break;
  }
  return iGetId;
}


// address=[0x1546340]
// Decompiled from void __thiscall CDecoObjMgr::ReadObjectInfos(CDecoObjMgr *this)
void  CDecoObjMgr::ReadObjectInfos(void) {
  
  int v1; // eax
  char *v2; // eax
  int v3; // eax
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  _DWORD v9[4]; // [esp+0h] [ebp-480h] BYREF
  _BYTE v10[28]; // [esp+10h] [ebp-470h] BYREF
  _DWORD v11[4]; // [esp+2Ch] [ebp-454h] BYREF
  _BYTE v12[16]; // [esp+3Ch] [ebp-444h] BYREF
  int v13[8]; // [esp+5Ch] [ebp-424h] BYREF
  int Name; // [esp+7Ch] [ebp-404h]
  _DWORD *v16; // [esp+84h] [ebp-3FCh]
  _DWORD *v17; // [esp+88h] [ebp-3F8h]
  _DWORD *v18; // [esp+8Ch] [ebp-3F4h]
  _DWORD *v19; // [esp+90h] [ebp-3F0h]
  int iAssert; // [esp+94h] [ebp-3ECh] MAPDST
  void *Root; // [esp+98h] [ebp-3E8h]
  void *C; // [esp+9Ch] [ebp-3E4h]
  int v23; // [esp+A0h] [ebp-3E0h]
  int v25; // [esp+A8h] [ebp-3D8h]
  int v27; // [esp+B0h] [ebp-3D0h]
  const char *v30; // [esp+BCh] [ebp-3C4h]
  int v31; // [esp+C0h] [ebp-3C0h]
  const char *v32; // [esp+C4h] [ebp-3BCh]
  int v33; // [esp+C8h] [ebp-3B8h]
  const char *v34; // [esp+CCh] [ebp-3B4h]
  int v35; // [esp+D0h] [ebp-3B0h]
  const char *ObjectName; // [esp+D4h] [ebp-3ACh]
  std::string *v37; // [esp+D8h] [ebp-3A8h]
  AdvXMLParser::Element *v38; // [esp+DCh] [ebp-3A4h]
  AdvXMLParser::Element *v39; // [esp+E0h] [ebp-3A0h]
  std::string *v40; // [esp+E4h] [ebp-39Ch]
  AdvXMLParser::Element *v41; // [esp+E8h] [ebp-398h] MAPDST
  AdvXMLParser::Element *v42; // [esp+ECh] [ebp-394h]
  std::string *v43; // [esp+F0h] [ebp-390h]
  AdvXMLParser::Element *v44; // [esp+F4h] [ebp-38Ch]
  AdvXMLParser::Element *v45; // [esp+F8h] [ebp-388h]
  std::string *v46; // [esp+FCh] [ebp-384h]
  AdvXMLParser::Element *pBlockingNode; // [esp+100h] [ebp-380h]
  AdvXMLParser::Element *v48; // [esp+104h] [ebp-37Ch]
  char *v49; // [esp+108h] [ebp-378h]
  CConfigManager *pConfigManager; // [esp+110h] [ebp-370h] MAPDST
  const struct AdvXMLParser::Attribute *v52; // [esp+114h] [ebp-36Ch]
  AdvXMLParser::Element *v53; // [esp+118h] [ebp-368h]
  std::string *v54; // [esp+11Ch] [ebp-364h]
  _DWORD v55[5]; // [esp+120h] [ebp-360h] BYREF
  int v56; // [esp+134h] [ebp-34Ch] BYREF
  void *v57; // [esp+138h] [ebp-348h]
  const struct AdvXMLParser::Attribute *v58; // [esp+13Ch] [ebp-344h]
  char *v60; // [esp+144h] [ebp-33Ch]
  _BYTE v62[4]; // [esp+14Ch] [ebp-334h] BYREF
  BOOL v63; // [esp+150h] [ebp-330h]
  int iPingPongs; // [esp+158h] [ebp-328h] MAPDST
  int iRepellents; // [esp+15Ch] [ebp-324h]
  int iBuilding; // [esp+160h] [ebp-320h]
  int iBlocking; // [esp+164h] [ebp-31Ch]
  BOOL iIsResource; // [esp+168h] [ebp-318h]
  AdvXMLParser::Element *v70; // [esp+16Ch] [ebp-314h]
  AdvXMLParser::Element *v72; // [esp+174h] [ebp-30Ch]
  char *v73; // [esp+178h] [ebp-308h]
  AdvXMLParser::Element *v74; // [esp+17Ch] [ebp-304h] MAPDST
  int iTotalRepellingRings; // [esp+180h] [ebp-300h]
  bool v76; // [esp+184h] [ebp-2FCh]
  int iAdditionalBuildingRings; // [esp+188h] [ebp-2F8h]
  int iTotalBlockingRings; // [esp+18Ch] [ebp-2F4h]
  bool bIsResource; // [esp+192h] [ebp-2EEh] MAPDST
  bool v83; // [esp+193h] [ebp-2EDh]
  CDecoObjMgr::Ring *pRings; // [esp+194h] [ebp-2ECh]
  signed int iDecoObjectType; // [esp+198h] [ebp-2E8h] MAPDST
  _BYTE v86[28]; // [esp+3C4h] [ebp-BCh] BYREF
  _BYTE v87[28]; // [esp+3E0h] [ebp-A0h] BYREF
  _BYTE v88[28]; // [esp+3FCh] [ebp-84h] BYREF
  _BYTE v89[28]; // [esp+418h] [ebp-68h] BYREF
  _BYTE v90[28]; // [esp+434h] [ebp-4Ch] BYREF
  std::string v91; // [esp+450h] [ebp-30h] BYREF
  _DWORD *v92; // [esp+470h] [ebp-10h]
  int v93; // [esp+47Ch] [ebp-4h]

  v92 = v9;
  v56 = 0;
  v73 = (char *)AdvXMLParser::Parser::OpenXMLFile(aGamedataObject, &v56);
  if ( v73 )
  {
    v93 = 0;
    v13[5] = AdvXMLParser::Parser::Parser(v10);
    LOBYTE(v93) = 1;
    v27 = AdvXMLParser::Parser::Parse((AdvXMLParser::Parser *)v10, v73, v56);
    std::auto_ptr<AdvXMLParser::Document>::auto_ptr<AdvXMLParser::Document>(v27);
    LOBYTE(v93) = 2;
    v1 = std::auto_ptr<AdvXMLParser::Document>::operator->(v9[0]);
    Root = (void *)AdvXMLParser::Document::GetRoot(v1);
    v57 = Root;
    v19 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(Root, v12);
    v18 = v19;
    LOBYTE(v93) = 3;
    v13[4] = (int)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v55, v19);
    LOBYTE(v93) = 5;
    AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v12);
    v17 = AdvXMLParser::NodeContainer::End(v57, v11);
    v16 = v17;
    LOBYTE(v93) = 6;
    v13[7] = (int)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v13, v17);
    LOBYTE(v93) = 8;
    AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v11);
    while ( AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v55, (int)v13) )
    {
      v74 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v55);
      Name = AdvXMLParser::Node::GetName(v74);
      if ( std::operator==<char>(Name, "ObjectXMLVersion") )
      {
        v54 = v74->GetValue(v74);
        v2 = std::string::c_str(v54);
        v3 = j__atoi(v2);
        this->m_iXmlVersion = v3;
        std::string::~string(v88);
      }
      else
      {
        v53 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v55);
        v52 = AdvXMLParser::Element::operator[](v53, "id");
        v58 = v52;
        v13[6] = (*(int (__thiscall **)(const struct AdvXMLParser::Attribute *, std::string *))(*(_DWORD *)v52 + 8))(
                   v52,
                   &v91);
        LOBYTE(v93) = 9;
        pConfigManager = CConfigManagerPtr::GetInstance();
        v4 = std::string::c_str(&v91);
        iDecoObjectType = pConfigManager->GetDefineValue(pConfigManager, v4);
        if ( iDecoObjectType < 0 )
        {
          if ( std::string::c_str(&v91) )
            v60 = std::string::c_str(&v91);
          else
            v60 = (char *)&unk_379CF3A;
          v49 = v60;
          BBSupportTracePrintF(0, "### CDecoObjMgr::ReadObjectInfos(): Unknown object \"%s\"!", v60);
        }
        if ( iDecoObjectType > 0 && iDecoObjectType < OBJECT_MAX )
        {
          pRings = &this->m_aBuildingRings[iDecoObjectType];
          v48 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v55);
          pBlockingNode = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v48, "blocking", 0);
          v55[4] = pBlockingNode;
          v46 = pBlockingNode->GetValue(pBlockingNode);
          v5 = std::string::c_str(v46);
          iBlocking = j__atoi(v5);
          std::string::~string(v89);
          v45 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v55);
          v44 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v45, "building", 0);
          v72 = v44;
          v43 = v44->GetValue(v44);
          v6 = std::string::c_str(v43);
          iBuilding = j__atoi(v6);
          std::string::~string(v86);
          v42 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v55);
          v41 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v42, "repellent", 0);
          v40 = v41->GetValue(v41);
          v7 = std::string::c_str(v40);
          iRepellents = j__atoi(v7);
          std::string::~string(v87);
          v39 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*((char *)v55);
          v38 = (AdvXMLParser::Element *)AdvXMLParser::Element::operator()(v39, "pingPong", 0);
          v70 = v38;
          v37 = v38->GetValue(v38);
          v8 = std::string::c_str(v37);
          iPingPongs = j__atoi(v8);
          std::string::~string(v90);
          iTotalBlockingRings = iBlocking;
          iAdditionalBuildingRings = iBuilding;
          iTotalRepellingRings = iRepellents;
          bIsResource = iDecoObjectType == OBJECT_WHEAT1
                     || iDecoObjectType == OBJECT_WHEAT2
                     || iDecoObjectType == OBJECT_GRAPE
                     || iDecoObjectType == OBJECT_SUNFLOWER
                     || iDecoObjectType == OBJECT_AGAVE;
          iIsResource = bIsResource;
          iTotalRepellingRings = iIsResource;
          v83 = iDecoObjectType == OBJECT_SHADOWHERB;
          v76 = iDecoObjectType == OBJECT_SHADOWHERB;
          if ( iDecoObjectType == OBJECT_SHADOWHERB )
            iAdditionalBuildingRings = 1;
          if ( iTotalBlockingRings != iBlocking )
          {
            ObjectName = CS4DefineNames::GetObjectName(iDecoObjectType);
            v35 = BBSupportDbgReportF(
                    2,
                    "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                    2136,
                    "Invalid blocking rings: %s (%i)",
                    ObjectName,
                    iDecoObjectType);
            if ( v35 == 1 )
              __debugbreak();
          }
          if ( iAdditionalBuildingRings != iBuilding )
          {
            v34 = CS4DefineNames::GetObjectName(iDecoObjectType);
            v33 = BBSupportDbgReportF(
                    2,
                    "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                    2137,
                    "Invalid building rings: %s (%i)",
                    v34,
                    iDecoObjectType);
            if ( v33 == 1 )
              __debugbreak();
          }
          if ( iTotalRepellingRings != iRepellents )
          {
            v32 = CS4DefineNames::GetObjectName(iDecoObjectType);
            v31 = BBSupportDbgReportF(
                    2,
                    "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                    2138,
                    "Invalid repelling rings: %s (%i)",
                    v32,
                    iDecoObjectType);
            if ( v31 == 1 )
              __debugbreak();
          }
          if ( iPingPongs != iPingPongs )
          {
            v30 = CS4DefineNames::GetObjectName(iDecoObjectType);
            iAssert = BBSupportDbgReportF(
                        2,
                        "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                        2139,
                        "Invalid ping pong: %s (%i)",
                        v30,
                        iDecoObjectType);
            if ( iAssert == 1 )
              __debugbreak();
          }
          if ( iTotalBlockingRings < 0 )
          {
            iAssert = BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 2141, "iTotalBlockingRings >= 0");
            if ( iAssert == 1 )
              __debugbreak();
          }
          if ( iAdditionalBuildingRings < 0 )
          {
            iAssert = BBSupportDbgReport(
                        2,
                        "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                        2142,
                        "iAdditionalBuildingRings >= 0");
            if ( iAssert == 1 )
              __debugbreak();
          }
          if ( iTotalRepellingRings < 0 )
          {
            iAssert = BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 2143, "iTotalRepellingRings >= 0");
            if ( iAssert == 1 )
              __debugbreak();
          }
          if ( iAdditionalBuildingRings + iTotalBlockingRings )
          {
            if ( iAdditionalBuildingRings < 1 )
            {
              v25 = BBSupportDbgReport(
                      2,
                      "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                      2145,
                      "( ( iTotalBlockingRings + iAdditionalBuildingRings ) == 0 ) || ( iAdditionalBuildingRings >= 1 )");
              if ( v25 == 1 )
                __debugbreak();
            }
          }
          if ( iDecoObjectType >= OBJECT_TREE01A
            && iDecoObjectType <= OBJECT_TREE11B
            && (iTotalBlockingRings != 1 || iAdditionalBuildingRings != 1) )
          {
            iAssert = BBSupportDbgReport(
                        2,
                        "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                        2147,
                        "( iDecoObjectType < OBJECT_TREE01A ) || ( iDecoObjectType > OBJECT_TREE11B ) || ( ( iTotalBlocki"
                        "ngRings == 1 ) && ( iAdditionalBuildingRings == 1 ) )");
            if ( iAssert == 1 )
              __debugbreak();
          }
          if ( iDecoObjectType >= OBJECT_DARKTREE01A
            && iDecoObjectType <= OBJECT_DARKTREE09B
            && (iTotalBlockingRings != 1 || iAdditionalBuildingRings != 1) )
          {
            v23 = BBSupportDbgReport(
                    2,
                    "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                    2148,
                    "( iDecoObjectType < OBJECT_DARKTREE01A ) || ( iDecoObjectType > OBJECT_DARKTREE09B ) || ( ( iTotalBl"
                    "ockingRings == 1 ) && ( iAdditionalBuildingRings == 1 ) )");
            if ( v23 == 1 )
              __debugbreak();
          }
          if ( iTotalBlockingRings <= 0 && iTotalRepellingRings > 0 )
          {
            pRings->m_uUnknown = 1;
            pRings->m_uTotalBlockingRings = 0;
            pRings->m_uRepellingRings = 1;
            pRings->m_uTotalBlockingOrRepellingRings = 1;
            pRings->m_uTotalRings = iAdditionalBuildingRings + 1;
          }
          else
          {
            pRings->m_uUnknown = 0;
            pRings->m_uTotalBlockingRings = iTotalBlockingRings;
            pRings->m_uRepellingRings = 0;
            pRings->m_uTotalBlockingOrRepellingRings = iTotalBlockingRings;
            pRings->m_uTotalRings = iAdditionalBuildingRings + iTotalBlockingRings;
          }
          pRings->m_uU5 = 0;
          pRings->m_uU6 = 0;
          v63 = iPingPongs != 0;
          pRings->m_bHasPingPong = v63;
        }
        LOBYTE(v93) = 8;
        std::string::~string(&v91);
      }
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++((char *)v55);
    }
    LOBYTE(v93) = 5;
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v13);
    LOBYTE(v93) = 2;
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v55);
    LOBYTE(v93) = 1;
    std::auto_ptr<AdvXMLParser::Document>::~auto_ptr<AdvXMLParser::Document>(v62);
    LOBYTE(v93) = 0;
    AdvXMLParser::Parser::~Parser(v10);
    v93 = -1;
    C = v73;
    operator delete[](v73);
  }
}


#endif // Already implemented
