#include "all_headers.h"

// Definitions for class CDecoObjMgr

// address=[0x1326ec0]
// Decompiled from unsigned __int8 *__cdecl CDecoObjMgr::GetDecoObjPtr(int a1)
static class IDecoObject * __cdecl CDecoObjMgr::GetDecoObjPtr(int) {
  
  unsigned __int8 *v3; // [esp+8h] [ebp-4h]

  v3 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(a1);
  if ( v3 && IEntity::ObjType(v3) == 32 )
    return v3;
  else
    return 0;
}


// address=[0x1486f90]
// Decompiled from int __thiscall CDecoObjMgr::GetXMLVersion(CDecoObjMgr *this)
int  CDecoObjMgr::GetXMLVersion(void)const {
  
  return *((_DWORD *)this + 6);
}


// address=[0x15423a0]
// Decompiled from unsigned int __thiscall CDecoObjMgr::Alloc(CDecoObjMgr *this, unsigned int a2)
void *  CDecoObjMgr::Alloc(unsigned int) {
  
  return MemoryAllocator::allocate((unsigned int *)this, a2);
}


// address=[0x1542400]
// Decompiled from void __thiscall CDecoObjMgr::Dealloc(CDecoObjMgr *this, void *a2)
void  CDecoObjMgr::Dealloc(void *) {
  
  MemoryAllocator::deallocate(this, a2);
}


// address=[0x1542430]
// Decompiled from int __thiscall CDecoObjMgr::GetTotalBuildingRings(CDecoObjMgr *this, int a2)
int  CDecoObjMgr::GetTotalBuildingRings(int) {
  
  return *((unsigned __int8 *)this + 8 * a2 + 38448);
}


// address=[0x1542490]
// Decompiled from CDecoObjMgr *__thiscall CDecoObjMgr::CDecoObjMgr(CDecoObjMgr *this)
 CDecoObjMgr::CDecoObjMgr(void) {
  
  int v1; // eax
  unsigned int v2; // eax
  _BYTE v4[16]; // [esp+4h] [ebp-44h] BYREF
  int v5; // [esp+14h] [ebp-34h]
  int v6; // [esp+18h] [ebp-30h]
  int v7; // [esp+1Ch] [ebp-2Ch] BYREF
  int v8; // [esp+20h] [ebp-28h] BYREF
  int v9; // [esp+24h] [ebp-24h] BYREF
  int v10; // [esp+28h] [ebp-20h] BYREF
  int v11; // [esp+2Ch] [ebp-1Ch] BYREF
  int v12; // [esp+30h] [ebp-18h] BYREF
  int v13; // [esp+34h] [ebp-14h] BYREF
  CDecoObjMgr *v14; // [esp+38h] [ebp-10h]
  int v15; // [esp+44h] [ebp-4h]

  v14 = this;
  v13 = 84;
  v12 = 80;
  v11 = 72;
  v10 = 80;
  v9 = 80;
  v8 = 80;
  v7 = 80;
  v6 = CreateArgv<unsigned int>(v4, &v7);
  v5 = v6;
  v15 = 0;
  TArgv<unsigned int,std::vector<unsigned int>>::operator()(&v8);
  TArgv<unsigned int,std::vector<unsigned int>>::operator()(&v9);
  TArgv<unsigned int,std::vector<unsigned int>>::operator()(&v10);
  TArgv<unsigned int,std::vector<unsigned int>>::operator()(&v11);
  TArgv<unsigned int,std::vector<unsigned int>>::operator()(&v12);
  v1 = TArgv<unsigned int,std::vector<unsigned int>>::operator()(&v13);
  v2 = sub_1546E30(v1);
  MemoryAllocator::MemoryAllocator(v14, v2, 0x20u, 0);
  LOBYTE(v15) = 2;
  TArgv<unsigned int,std::vector<unsigned int>>::~TArgv<unsigned int,std::vector<unsigned int>>(v4);
  *((_DWORD *)v14 + 6) = 0;
  *((_BYTE *)v14 + 28) = 0;
  memset((char *)v14 + 38444, 0, 0x918u);
  CDecoObjMgr::Clear(v14);
  return v14;
}


// address=[0x15425c0]
// Decompiled from void __thiscall CDecoObjMgr::~CDecoObjMgr(CDecoObjMgr *this)
 CDecoObjMgr::~CDecoObjMgr(void) {
  
  MemoryAllocator::~MemoryAllocator(this);
}


// address=[0x15425e0]
// Decompiled from void *__thiscall CDecoObjMgr::Clear(CDecoObjMgr *this)
void  CDecoObjMgr::Clear(void) {
  
  return memset((char *)this + 32, 0, 0x960Cu);
}


// address=[0x1542610]
// Decompiled from CDecoObjMgr *__thiscall CDecoObjMgr::LoadInfo(CDecoObjMgr *this)
void  CDecoObjMgr::LoadInfo(void) {
  
  CDecoObjMgr *result; // eax

  result = this;
  if ( !*((_BYTE *)this + 28) )
    CDecoObjMgr::ReadObjectInfos(this);
  *((_BYTE *)this + 28) = 1;
  return result;
}


// address=[0x1542640]
// Decompiled from char __thiscall CDecoObjMgr::IsAddDecoObjOk(CDecoObjMgr *this, int a2, int a3, int a4, bool a5, int a6)
bool  CDecoObjMgr::IsAddDecoObjOk(int,int,int,bool,int) {
  
  int v7; // [esp+0h] [ebp-3Ch]
  int v8; // [esp+4h] [ebp-38h]
  int v9; // [esp+8h] [ebp-34h]
  int v10; // [esp+Ch] [ebp-30h] BYREF
  int v11; // [esp+10h] [ebp-2Ch]
  CDecoObjMgr *v12; // [esp+14h] [ebp-28h]
  int v13; // [esp+18h] [ebp-24h]
  int v14; // [esp+1Ch] [ebp-20h]
  int v15; // [esp+20h] [ebp-1Ch]
  int v16; // [esp+24h] [ebp-18h]
  int v17; // [esp+28h] [ebp-14h]
  int v18; // [esp+2Ch] [ebp-10h] BYREF
  int j; // [esp+30h] [ebp-Ch]
  int i; // [esp+34h] [ebp-8h]
  bool v21; // [esp+3Bh] [ebp-1h] BYREF

  v12 = this;
  if ( (a4 <= 0 || a4 >= 291)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 358, "_iDecoType > 0 && _iDecoType < OBJECT_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a6 < 0 && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 359, "_iExtraBuildingRings >= 0") == 1 )
    __debugbreak();
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3) )
    return 0;
  if ( CWorldManager::FlagBits(a2, a3, 0x7Bu) )
    return 0;
  if ( !a5 && CWorldManager::ObjectId(a2, a3) )
    return 0;
  CDecoObjMgr::GetDecoObjectFlagsInfo(v12, a4, &v21, &v18, &v10);
  if ( v21 )
  {
    if ( v18 != 1
      && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 418, "iTotalBlockingOrRepellingRings == 1") == 1 )
    {
      __debugbreak();
    }
  }
  else
  {
    v11 = CSpiralOffsets::First(v18);
    for ( i = 0; i < v11; ++i )
    {
      v16 = a2 + CSpiralOffsets::DeltaX(i);
      v17 = a3 + CSpiralOffsets::DeltaY(i);
      if ( !(unsigned __int8)CWorldManager::InWorld(v16, v17) )
        return 0;
      v15 = CWorldManager::Index(v16, v17);
      if ( CWorldManager::MapObjectId(v15) )
        return 0;
      if ( CWorldManager::FlagBits(v15, 0x7Bu) )
        return 0;
    }
  }
  v9 = CSpiralOffsets::First(v18);
  v8 = CSpiralOffsets::First(a6 + v10);
  for ( j = v9; j < v8; ++j )
  {
    v13 = a2 + CSpiralOffsets::DeltaX(j);
    v14 = a3 + CSpiralOffsets::DeltaY(j);
    if ( !(unsigned __int8)CWorldManager::InWorld(v13, v14) )
      return 0;
    v7 = CWorldManager::Index(v13, v14);
    if ( CWorldManager::FlagBits(v7, 0x7Bu) )
      return 0;
  }
  return 1;
}


// address=[0x15428b0]
// Decompiled from int __thiscall CDecoObjMgr::AddDecoObj(CDecoObjMgr *this, int a2, int a3, int a4, int a5, int a6)
int  CDecoObjMgr::AddDecoObj(int,int,int,int,enum CDecoObjMgr::TGROWN_STATE) {
  
  int v7; // [esp+4h] [ebp-8h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 464, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( (a4 <= 0 || a4 >= 291)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 465, "_iType>0 && _iType<OBJECT_MAX") == 1 )
  {
    __debugbreak();
  }
  v7 = CDecoObjMgr::Create(a2, a3, a4, a5, a6, 0, 0);
  CDecoObjMgr::SetFlagsForObject(this, a2, a3, a4, 0);
  return v7;
}


// address=[0x1542970]
// Decompiled from int __thiscall CDecoObjMgr::AddReef(CDecoObjMgr *this, int a2, int a3, int a4, int a5, int a6)
int  CDecoObjMgr::AddReef(int,int,int,int,enum CDecoObjMgr::TGROWN_STATE) {
  
  int v7; // [esp+0h] [ebp-14h]
  int v8; // [esp+4h] [ebp-10h]
  unsigned __int16 *DecoObjPtr; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 501, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( (a4 <= 0 || a4 >= 291)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 502, "_iType>0 && _iType<OBJECT_MAX") == 1 )
  {
    __debugbreak();
  }
  v7 = CDecoObjMgr::Create(a2, a3, a4, a5, a6, 0, 0);
  v8 = CWorldManager::Index(a2, a3);
  v11 = CWorldManager::ObjectId(v8);
  if ( !v11 )
    return v7;
  DecoObjPtr = (unsigned __int16 *)CDecoObjMgr::GetDecoObjPtr(v11);
  if ( !DecoObjPtr )
    return v7;
  if ( IEntity::Type(DecoObjPtr) == a4 )
    CDecoObjMgr::SetFlagsForObject(this, a2, a3, a4, 1);
  else
    BBSupportTracePrintF(3, "Reef couldn't be set!");
  return v7;
}


// address=[0x1542a80]
// Decompiled from int __stdcall CDecoObjMgr::AddDecoObjWithoutFlags(int a1, int a2, int a3, unsigned int a4, int a5)
int  CDecoObjMgr::AddDecoObjWithoutFlags(int,int,int,int,enum CDecoObjMgr::TGROWN_STATE) {
  
  if ( !(unsigned __int8)CWorldManager::InWorld(a1, a2)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 553, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 291)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 554, "_iType>0 && _iType<OBJECT_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a4 >= 0x10
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 557, "_iAmount>=0 && _iAmount<MAX_RESOURCE_AMOUNT") == 1 )
  {
    __debugbreak();
  }
  return CDecoObjMgr::Create(a1, a2, a3, a4, a5, 0, 0);
}


// address=[0x1542b50]
// Decompiled from int __stdcall CDecoObjMgr::AddLoadedDecoObj(int a1, int a2, int a3, unsigned int a4, int a5, char a6, int a7)
int  CDecoObjMgr::AddLoadedDecoObj(int,int,int,int,int,bool,std::istream *) {
  
  if ( (a3 <= 0 || a3 >= 291)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 584, "_iType>0 && _iType<OBJECT_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a4 >= 0x10
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 589, "_iAmount>=0 && _iAmount<MAX_RESOURCE_AMOUNT") == 1 )
  {
    __debugbreak();
  }
  if ( a6 )
    return CDecoObjMgr::Create(a1, a2, a3, a4, 1, a5, a7);
  else
    return CDecoObjMgr::Create(a1, a2, a3, a4, 0, a5, a7);
}


// address=[0x1542c20]
// Decompiled from void __thiscall CDecoObjMgr::Delete(CDecoObjMgr *this, int a2)
void  CDecoObjMgr::Delete(int) {
  
  IDecoObject *DecoObjPtr; // eax
  int v3; // eax
  int v4; // [esp-Ch] [ebp-14h]
  int v5; // [esp-8h] [ebp-10h]
  unsigned __int16 *v7; // [esp+4h] [ebp-4h]

  if ( a2 )
  {
    if ( !CDecoObjMgr::GetDecoObjPtr(a2)
      && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 610, "GetDecoObjPtr( _iEntityId ) != 0") == 1 )
    {
      __debugbreak();
    }
    DecoObjPtr = CDecoObjMgr::GetDecoObjPtr(a2);
    if ( IDecoObject::IsStaticInstance(DecoObjPtr)
      && BBSupportDbgReport(
           2,
           "MapObjects\\DecoObj\\DecoObjMgr.cpp",
           611,
           "GetDecoObjPtr( _iEntityId )->IsStaticInstance() == false") == 1 )
    {
      __debugbreak();
    }
    v7 = (unsigned __int16 *)CMapObjectMgr::Entity(a2);
    v5 = IEntity::Type(v7);
    v4 = IEntity::Y(v7);
    v3 = IEntity::X(v7);
    CDecoObjMgr::ClearFlagsForObject(this, v3, v4, v5, 0);
    CMapObjectMgr::Destroy(g_pMapObjectMgr, a2);
  }
}


// address=[0x1542cf0]
// Decompiled from void __thiscall CDecoObjMgr::DeleteWithoutFlags(CDecoObjMgr *this, int a2)
void  CDecoObjMgr::DeleteWithoutFlags(int) {
  
  IDecoObject *DecoObjPtr; // [esp+8h] [ebp-4h]

  if ( a2 )
  {
    DecoObjPtr = CDecoObjMgr::GetDecoObjPtr(a2);
    if ( !DecoObjPtr && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 633, "pDecoObj != 0") == 1 )
      __debugbreak();
    if ( DecoObjPtr )
    {
      if ( IDecoObject::IsStaticInstance(DecoObjPtr)
        && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 637, "pDecoObj->IsStaticInstance() == false") == 1 )
      {
        __debugbreak();
      }
      CMapObjectMgr::Entity(a2);
      CMapObjectMgr::Destroy(g_pMapObjectMgr, a2);
    }
  }
}


// address=[0x1542da0]
// Decompiled from int __thiscall CDecoObjMgr::RemoveDecoObject(CDecoObjMgr *this, int a2, int a3, bool a4)
int  CDecoObjMgr::RemoveDecoObject(int,int,bool) {
  
  int v4; // eax
  int v7; // [esp+4h] [ebp-Ch]
  unsigned __int16 *DecoObjPtr; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 2194, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  v9 = CWorldManager::Index(a2, a3);
  v7 = CWorldManager::ObjectId(v9);
  if ( !v7 )
    return 0;
  DecoObjPtr = (unsigned __int16 *)CDecoObjMgr::GetDecoObjPtr(v7);
  if ( !DecoObjPtr )
    return -1;
  if ( IDecoObject::IsStaticInstance((IDecoObject *)DecoObjPtr) )
  {
    CWorldManager::SetObjectId(v9, 0);
    v4 = IEntity::Type(DecoObjPtr);
    CDecoObjMgr::ClearFlagsForObject(this, a2, a3, v4, 0);
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
// Decompiled from int __thiscall CDecoObjMgr::RemoveReef(CDecoObjMgr *this, int a2, int a3, bool a4)
int  CDecoObjMgr::RemoveReef(int,int,bool) {
  
  int v4; // eax
  int v7; // [esp+4h] [ebp-Ch]
  unsigned __int16 *DecoObjPtr; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 2241, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  v9 = CWorldManager::Index(a2, a3);
  v7 = CWorldManager::ObjectId(v9);
  if ( !v7 )
    return 0;
  DecoObjPtr = (unsigned __int16 *)CDecoObjMgr::GetDecoObjPtr(v7);
  if ( !DecoObjPtr )
    return -1;
  if ( IDecoObject::IsStaticInstance((IDecoObject *)DecoObjPtr) )
  {
    CWorldManager::SetObjectId(v9, 0);
    v4 = IEntity::Type(DecoObjPtr);
    CDecoObjMgr::ClearFlagsForObject(this, a2, a3, v4, 1);
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
// Decompiled from int __thiscall CDecoObjMgr::GetDecoObjectFlagsInfo(CDecoObjMgr *this, int a2, bool *a3, int *a4, int *a5)
void  CDecoObjMgr::GetDecoObjectFlagsInfo(int,bool &,int &,int &) {
  
  int result; // eax

  if ( (a2 <= 0 || a2 >= 291)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 680, "_iDecoType > 0 && _iDecoType < OBJECT_MAX") == 1 )
  {
    __debugbreak();
  }
  *a3 = *((_BYTE *)this + 8 * a2 + 38444);
  *a4 = *((unsigned __int8 *)this + 8 * a2 + 38447);
  result = *((unsigned __int8 *)this + 8 * a2 + 38448);
  *a5 = result;
  return result;
}


// address=[0x1543080]
// Decompiled from int __thiscall CDecoObjMgr::SetFlagsForObject(CDecoObjMgr *this, int a2, int a3, int a4, bool a5)
void  CDecoObjMgr::SetFlagsForObject(int,int,int,bool) {
  
  int result; // eax
  int v6; // [esp+0h] [ebp-48h]
  int v7; // [esp+4h] [ebp-44h]
  int v8; // [esp+8h] [ebp-40h] BYREF
  int v9; // [esp+Ch] [ebp-3Ch]
  CDecoObjMgr *v10; // [esp+10h] [ebp-38h]
  int v11; // [esp+14h] [ebp-34h]
  int v12; // [esp+18h] [ebp-30h]
  int v13; // [esp+1Ch] [ebp-2Ch]
  int v14; // [esp+20h] [ebp-28h]
  int v15; // [esp+24h] [ebp-24h]
  int v16; // [esp+28h] [ebp-20h]
  int v17; // [esp+2Ch] [ebp-1Ch]
  int v18; // [esp+30h] [ebp-18h] BYREF
  int v19; // [esp+34h] [ebp-14h]
  int v20; // [esp+38h] [ebp-10h]
  int i; // [esp+3Ch] [ebp-Ch]
  int j; // [esp+40h] [ebp-8h]
  bool v23; // [esp+47h] [ebp-1h] BYREF

  v10 = this;
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 738, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( (a4 <= 0 || a4 >= 291)
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
      if ( !(unsigned __int8)CWorldManager::InWorld(v19, v20)
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
        (*(void (__thiscall **)(void *, int, int))(*(_DWORD *)g_pTiling + 16))(g_pTiling, v19, v20);
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
    if ( !(unsigned __int8)CWorldManager::InWorld(v16, v17)
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
      if ( !(unsigned __int8)CWorldManager::InWorld(v14, v15)
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
      (*(void (__thiscall **)(void *, int, int))(*(_DWORD *)g_pTiling + 16))(g_pTiling, v14, v15);
      result = j + 1;
    }
  }
  return result;
}


// address=[0x15434b0]
// Decompiled from int __thiscall CDecoObjMgr::ClearFlagsForObject(CDecoObjMgr *this, int a2, int a3, int a4, bool a5)
void  CDecoObjMgr::ClearFlagsForObject(int,int,int,bool) {
  
  int result; // eax
  int v6; // [esp+0h] [ebp-3Ch]
  int v7; // [esp+4h] [ebp-38h]
  int v8; // [esp+8h] [ebp-34h] BYREF
  int v9; // [esp+Ch] [ebp-30h]
  CDecoObjMgr *v10; // [esp+10h] [ebp-2Ch]
  int v11; // [esp+14h] [ebp-28h]
  int v12; // [esp+18h] [ebp-24h]
  int v13; // [esp+1Ch] [ebp-20h]
  int v14; // [esp+20h] [ebp-1Ch]
  int v15; // [esp+24h] [ebp-18h] BYREF
  int v16; // [esp+28h] [ebp-14h]
  int v17; // [esp+2Ch] [ebp-10h]
  int i; // [esp+30h] [ebp-Ch]
  int j; // [esp+34h] [ebp-8h]
  bool v20; // [esp+3Bh] [ebp-1h] BYREF

  v10 = this;
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 827, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( (a4 <= 0 || a4 >= 291)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 828, "_iDecoType > 0 && _iDecoType < OBJECT_MAX") == 1 )
  {
    __debugbreak();
  }
  CDecoObjMgr::GetDecoObjectFlagsInfo(v10, a4, &v20, &v15, &v8);
  if ( v20 )
  {
    if ( v15 != 1
      && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 863, "iTotalBlockingOrRepellingRings == 1") == 1 )
    {
      __debugbreak();
    }
    if ( !CWorldManager::FlagBits(a2, a3, 0x7Bu)
      && BBSupportDbgReport(
           2,
           "MapObjects\\DecoObj\\DecoObjMgr.cpp",
           865,
           "g_cWorld.FlagBits( _iX, _iY, DECO_OBJ_CHECK_FLAGS_MASK ) != 0") == 1 )
    {
      __debugbreak();
    }
    CWorldManager::ClearFlagBits(a2, a3, 2);
    CWorldManager::ClearFlagBits(a2, a3, 64);
  }
  else
  {
    v9 = CSpiralOffsets::First(v15);
    for ( i = 0; i < v9; ++i )
    {
      v16 = a2 + CSpiralOffsets::DeltaX(i);
      v17 = a3 + CSpiralOffsets::DeltaY(i);
      if ( !(unsigned __int8)CWorldManager::InWorld(v16, v17)
        && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 849, "g_cWorld.InWorld( iWorkX, iWorkY )") == 1 )
      {
        __debugbreak();
      }
      if ( !CWorldManager::FlagBits(v16, v17, 0x7Bu)
        && BBSupportDbgReport(
             2,
             "MapObjects\\DecoObj\\DecoObjMgr.cpp",
             850,
             "g_cWorld.FlagBits( iWorkX, iWorkY, DECO_OBJ_CHECK_FLAGS_MASK ) != 0") == 1 )
      {
        __debugbreak();
      }
      CWorldManager::ClearBlockedPosition(v16, v17);
      CWorldManager::ClearFlagBits(v16, v17, 64);
      if ( a5 )
        (*(void (__thiscall **)(void *, int, int))(*(_DWORD *)g_pTiling + 24))(g_pTiling, v16, v17);
    }
  }
  v7 = CSpiralOffsets::First(v15);
  v6 = CSpiralOffsets::First(v8);
  for ( j = v7; j < v6; ++j )
  {
    v13 = a2 + CSpiralOffsets::DeltaX(j);
    v14 = a3 + CSpiralOffsets::DeltaY(j);
    if ( !(unsigned __int8)CWorldManager::InWorld(v13, v14)
      && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 883, "g_cWorld.InWorld( iWorkX, iWorkY )") == 1 )
    {
      __debugbreak();
    }
    if ( !CWorldManager::FlagBits(v13, v14, 0x7Bu)
      && BBSupportDbgReport(
           2,
           "MapObjects\\DecoObj\\DecoObjMgr.cpp",
           884,
           "g_cWorld.FlagBits( iWorkX, iWorkY, DECO_OBJ_CHECK_FLAGS_MASK ) != 0") == 1 )
    {
      __debugbreak();
    }
    CWorldManager::ClearFlagBits(v13, v14, 64);
  }
  result = a5;
  if ( a5 )
  {
    for ( j = 0; j < 100; ++j )
    {
      v11 = a2 + CSpiralOffsets::DeltaX(j);
      v12 = a3 + CSpiralOffsets::DeltaY(j);
      if ( !(unsigned __int8)CWorldManager::InWorld(v11, v12)
        && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 896, "g_cWorld.InWorld( iWorkX, iWorkY )") == 1 )
      {
        __debugbreak();
      }
      if ( CWorldManager::FlagBits(v11, v12, 0x3Au)
        && BBSupportDbgReport(
             2,
             "MapObjects\\DecoObj\\DecoObjMgr.cpp",
             897,
             "g_cWorld.FlagBits( iWorkX, iWorkY, FLAG_REPELLING_LAND | FLAG_BUILDING | FLAG_DIG | FLAG_WORK ) == 0") == 1 )
      {
        __debugbreak();
      }
      result = (*(int (__thiscall **)(void *, int, int))(*(_DWORD *)g_pTiling + 24))(g_pTiling, v11, v12);
    }
  }
  return result;
}


// address=[0x15438a0]
// Decompiled from unsigned int __thiscall CDecoObjMgr::GetObjectType(CDecoObjMgr *this, int a2, int a3, char a4)
int  CDecoObjMgr::GetObjectType(int,int,int) {
  
  const char *v5; // [esp+4h] [ebp-18h]
  const char *v6; // [esp+8h] [ebp-14h]
  int v7; // [esp+Ch] [ebp-10h]
  unsigned __int8 v8; // [esp+10h] [ebp-Ch]

  switch ( a2 )
  {
    case 0:
      return 162;
    case 1:
      return 211;
    case 2:
      if ( a3 == 2 )
      {
        if ( (a4 & 0xF0) == 0x40 )
          return ((unsigned int)CGameData::Rand(g_pGameData) & 1) + 11;
        return ((unsigned int)CGameData::Rand(g_pGameData) & 1) + 13;
      }
      else if ( a3 == 4 )
      {
        if ( (a4 & 0xF0) == 0x40 )
          return ((unsigned int)CGameData::Rand(g_pGameData) & 1) + 11;
        v8 = (unsigned __int8)CGameData::Rand(g_pGameData);
        if ( (v8 & 6) != 0 )
          v7 = 15;
        else
          v7 = 17;
        return v7 + (v8 & 1);
      }
      else
      {
        return ((unsigned int)CGameData::Rand(g_pGameData) & 1) + 9;
      }
    case 3:
      v5 = CGameData::Rand(g_pGameData);
      if ( (unsigned int)v5 >= CRandom16::PercentValue(0x32u) )
        return 210;
      else
        return 209;
    case 4:
      v6 = CGameData::Rand(g_pGameData);
      if ( (unsigned int)v6 < CRandom16::PercentValue(0x1Eu) )
        return 212;
      if ( (unsigned int)v6 >= CRandom16::PercentValue(0x46u) )
        return 214;
      return 213;
    case 5:
      return 216;
    case 6:
      return 217;
    case 7:
      return 255;
    default:
      return 0;
  }
}


// address=[0x1543a60]
// Decompiled from int __thiscall CDecoObjMgr::ChangeToStaticInstance(CDecoObjMgr *this, int a2, int a3, int a4, int a5)
void  CDecoObjMgr::ChangeToStaticInstance(int,int,int,int) {
  
  IDecoObject *v5; // eax
  unsigned __int16 *v6; // eax
  struct IDecoObject *DecoObjPtr; // [esp+4h] [ebp-8h]
  int v10; // [esp+8h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1756, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  v10 = CWorldManager::ObjectId(a2, a3);
  DecoObjPtr = CDecoObjMgr::GetDecoObjPtr(v10);
  if ( !v10 && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1762, "iOldEntityId != 0") == 1 )
    __debugbreak();
  if ( !DecoObjPtr && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1763, "pDecoObj != 0") == 1 )
    __debugbreak();
  if ( DecoObjPtr )
  {
    v5 = CDecoObjMgr::GetDecoObjPtr(v10);
    if ( IDecoObject::IsStaticInstance(v5)
      && BBSupportDbgReport(
           2,
           "MapObjects\\DecoObj\\DecoObjMgr.cpp",
           1767,
           "GetDecoObjPtr( iOldEntityId )->IsStaticInstance() == false") == 1 )
    {
      __debugbreak();
    }
    v6 = (unsigned __int16 *)CDecoObjMgr::GetDecoObjPtr(v10);
    if ( IEntity::Type(v6) != a4
      && BBSupportDbgReport(
           2,
           "MapObjects\\DecoObj\\DecoObjMgr.cpp",
           1768,
           "GetDecoObjPtr( iOldEntityId )->Type() == _iDecoType") == 1 )
    {
      __debugbreak();
    }
  }
  CDecoObjMgr::DeleteWithoutFlags(this, v10);
  if ( CWorldManager::ObjectId(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1774, "g_cWorld.ObjectId( _iX, _iY ) == 0") == 1 )
  {
    __debugbreak();
  }
  CDecoObjMgr::AddDecoObjWithoutFlags(this, a2, a3, a4, a5, 1);
  if ( !CWorldManager::ObjectId(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1779, "g_cWorld.ObjectId( _iX, _iY ) != 0") == 1 )
  {
    __debugbreak();
  }
  return 0;
}


// address=[0x1543c20]
// Decompiled from int __stdcall CDecoObjMgr::ConvertGreenToDark(int a1)
int  CDecoObjMgr::ConvertGreenToDark(int)const {
  
  return 23;
}


// address=[0x1543c40]
// Decompiled from int __stdcall CDecoObjMgr::ConvertDarkToGreen(int a1)
int  CDecoObjMgr::ConvertDarkToGreen(int)const {
  
  return 23;
}


// address=[0x1543c60]
// Decompiled from int __stdcall CDecoObjMgr::GetThisDecoObj(int a1, int a2, int a3, int *a4, int *a5)
int  CDecoObjMgr::GetThisDecoObj(int,int,int,int &,int &) {
  
  unsigned __int16 *DecoObjPtr; // eax
  int v7; // [esp+4h] [ebp-14h]
  int v8; // [esp+8h] [ebp-10h]
  int v9; // [esp+Ch] [ebp-Ch]
  int v10; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a1, a2)
    && BBSupportDbgReport(2, (int)"MapObjects\\DecoObj\\DecoObjMgr.cpp", 2287, (int)"g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( !CWorldManager::FlagBits(a1, a2, 64)
    && BBSupportDbgReport(
         2,
         (int)"MapObjects\\DecoObj\\DecoObjMgr.cpp",
         2288,
         (int)"g_cWorld.FlagBits( _iX, _iY, FLAG_DECO_OBJECT )") == 1 )
  {
    __debugbreak();
  }
  v7 = CSpiralOffsets::Last(a3);
  for ( i = 1; i < v7; ++i )
  {
    v9 = a1 + CSpiralOffsets::DeltaX(i);
    v8 = a2 + CSpiralOffsets::DeltaY(i);
    if ( CWorldManager::FlagBits(v9, v8, 64) )
    {
      v10 = CWorldManager::ObjectId(v9, v8);
      if ( v10 )
      {
        if ( !CDecoObjMgr::GetDecoObjPtr(v10)
          && BBSupportDbgReport(2, (int)"MapObjects\\DecoObj\\DecoObjMgr.cpp", 2301, (int)"GetDecoObjPtr( iObjectId )") == 1 )
        {
          __debugbreak();
        }
        DecoObjPtr = (unsigned __int16 *)CDecoObjMgr::GetDecoObjPtr(v10);
        if ( IEntity::Type(DecoObjPtr) != 216 )
        {
          *a4 = v9;
          *a5 = v8;
          return v10;
        }
      }
    }
  }
  return 0;
}


// address=[0x1543dd0]
// Decompiled from bool __thiscall CDecoObjMgr::IsFlower(CDecoObjMgr *this, int a2)
bool  CDecoObjMgr::IsFlower(int) {
  
  return a2 == 184 || a2 == 185 || a2 == 186 || a2 == 187 || a2 == 188;
}


// address=[0x1543e20]
// Decompiled from bool __thiscall CDecoObjMgr::IsGeologistSign(CDecoObjMgr *this, int a2)
bool  CDecoObjMgr::IsGeologistSign(int) {
  
  bool result; // al
  int v3; // [esp+4h] [ebp-8h]
  unsigned __int8 *v4; // [esp+8h] [ebp-4h]

  v3 = CWorldManager::ObjectId(a2);
  result = 0;
  if ( !v3 )
    return result;
  v4 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(v3);
  if ( IEntity::ObjType(v4) == 32
    && IEntity::Type((unsigned __int16 *)v4) >= 193
    && IEntity::Type((unsigned __int16 *)v4) <= 208 )
  {
    return 1;
  }
  return result;
}


// address=[0x1543e90]
// Decompiled from char __thiscall CDecoObjMgr::Rod(CDecoObjMgr *this, int a2, bool a3)
void  CDecoObjMgr::Rod(int,bool) {
  
  int FreeSlot; // eax
  int v4; // eax
  int v6; // [esp+48h] [ebp-88h]
  CPlant *v7; // [esp+50h] [ebp-80h]
  int v8; // [esp+54h] [ebp-7Ch]
  CPlant *v9; // [esp+5Ch] [ebp-74h]
  int v10; // [esp+60h] [ebp-70h]
  CPlant *v11; // [esp+68h] [ebp-68h]
  int v12; // [esp+6Ch] [ebp-64h]
  CPlant *v13; // [esp+74h] [ebp-5Ch]
  CPlant *v14; // [esp+80h] [ebp-50h]
  int v15; // [esp+88h] [ebp-48h]
  int v16; // [esp+8Ch] [ebp-44h]
  int v17; // [esp+90h] [ebp-40h]
  int v18; // [esp+94h] [ebp-3Ch]
  int v19; // [esp+98h] [ebp-38h]
  unsigned __int8 *v20; // [esp+9Ch] [ebp-34h]
  int v22; // [esp+ACh] [ebp-24h]
  int v23; // [esp+B0h] [ebp-20h]
  int v24; // [esp+B4h] [ebp-1Ch]
  int v25; // [esp+C0h] [ebp-10h]

  FreeSlot = CWorldManager::ObjectId(a2);
  if ( !FreeSlot )
    return FreeSlot;
  v20 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(FreeSlot);
  FreeSlot = IEntity::ObjType(v20);
  if ( FreeSlot != 32 )
    return FreeSlot;
  if ( !j____RTDynamicCast((void **)v20, 0, &IEntity__RTTI_Type_Descriptor_, &IDecoObject__RTTI_Type_Descriptor_, 0)
    && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1850, "dynamic_cast<IDecoObject*>(pEntity)") == 1 )
  {
    __debugbreak();
  }
  LOBYTE(FreeSlot) = IDecoObject::IsStaticInstance((IDecoObject *)v20);
  if ( (_BYTE)FreeSlot )
  {
    v22 = IAnimatedEntity::JobPart(v20);
    v23 = CWorldManager::X(a2);
    v24 = CWorldManager::Y(a2);
    FreeSlot = IEntity::Type((unsigned __int16 *)v20) - 162;
    switch ( FreeSlot )
    {
      case 0:
        if ( v22 == 386 )
          goto LABEL_35;
        FreeSlot = CMapObjectMgr::GetFreeSlot();
        v19 = FreeSlot;
        if ( FreeSlot != -1 )
        {
          v14 = (CPlant *)CPlant::operator new(0x50u);
          if ( v14 )
            CPlant::CPlant(v14, (const struct CPlant *)v20, v19, v23, v24);
          v4 = CMapObjectMgr::EntityPtr(v19);
          LOBYTE(FreeSlot) = (*(int (__thiscall **)(int, int))(*(_DWORD *)v4 + 36))(v4, 1);
        }
        break;
      case 47:
        if ( v22 == 438 )
          goto LABEL_35;
        FreeSlot = CMapObjectMgr::GetFreeSlot();
        v18 = FreeSlot;
        if ( FreeSlot != -1 )
        {
          v13 = (CPlant *)CPlant::operator new(0x50u);
          if ( v13 )
            CPlant::CPlant(v13, (const struct CPlant *)v20, v18, v23, v24);
          v12 = CMapObjectMgr::EntityPtr(v18);
          LOBYTE(FreeSlot) = (*(int (__thiscall **)(int, int))(*(_DWORD *)v12 + 36))(v12, 2);
        }
        break;
      case 48:
        if ( v22 == 444 )
          goto LABEL_35;
        FreeSlot = CMapObjectMgr::GetFreeSlot();
        v17 = FreeSlot;
        if ( FreeSlot != -1 )
        {
          v11 = (CPlant *)CPlant::operator new(0x50u);
          if ( v11 )
            CPlant::CPlant(v11, (const struct CPlant *)v20, v17, v23, v24);
          v10 = CMapObjectMgr::EntityPtr(v17);
          LOBYTE(FreeSlot) = (*(int (__thiscall **)(int, int))(*(_DWORD *)v10 + 36))(v10, 2);
        }
        break;
      case 49:
        if ( v22 == 449 )
          goto LABEL_35;
        FreeSlot = CMapObjectMgr::GetFreeSlot();
        v16 = FreeSlot;
        if ( FreeSlot != -1 )
        {
          v9 = (CPlant *)CPlant::operator new(0x50u);
          if ( v9 )
            CPlant::CPlant(v9, (const struct CPlant *)v20, v16, v23, v24);
          v8 = CMapObjectMgr::EntityPtr(v16);
          LOBYTE(FreeSlot) = (*(int (__thiscall **)(int, int))(*(_DWORD *)v8 + 36))(v8, 1);
        }
        break;
      case 93:
        if ( v22 == 516 )
        {
LABEL_35:
          LOBYTE(FreeSlot) = CDecoObjMgr::RemoveDecoObject(this, v23, v24, 0);
        }
        else
        {
          FreeSlot = CMapObjectMgr::GetFreeSlot();
          v15 = FreeSlot;
          if ( FreeSlot != -1 )
          {
            v7 = (CPlant *)CPlant::operator new(0x50u);
            if ( v7 )
              CPlant::CPlant(v7, (const struct CPlant *)v20, v15, v23, v24);
            v6 = CMapObjectMgr::EntityPtr(v15);
            LOBYTE(FreeSlot) = (*(int (__thiscall **)(int, int))(*(_DWORD *)v6 + 36))(v6, 2);
          }
        }
        break;
      default:
        return FreeSlot;
    }
  }
  else if ( a3 )
  {
    v25 = IAnimatedEntity::JobPart(v20);
    FreeSlot = IEntity::Type((unsigned __int16 *)v20);
    switch ( FreeSlot )
    {
      case 162:
        if ( v25 != 385 )
          LOBYTE(FreeSlot) = (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v20 + 36))(v20, 386 - v25);
        break;
      case 209:
        if ( v25 != 436 )
          LOBYTE(FreeSlot) = (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v20 + 36))(v20, 438 - v25);
        break;
      case 210:
        if ( v25 != 442 )
          LOBYTE(FreeSlot) = (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v20 + 36))(v20, 444 - v25);
        break;
      case 211:
        if ( v25 != 448 )
          LOBYTE(FreeSlot) = (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v20 + 36))(v20, 449 - v25);
        break;
      case 217:
        if ( v25 != 470 )
          LOBYTE(FreeSlot) = (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v20 + 36))(v20, 472 - v25);
        break;
      case 255:
        if ( v25 != 514 )
          LOBYTE(FreeSlot) = (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v20 + 36))(v20, 516 - v25);
        break;
      default:
        return FreeSlot;
    }
  }
  return FreeSlot;
}


// address=[0x1544590]
// Decompiled from void __thiscall CDecoObjMgr::Store(CDecoObjMgr *this, struct S4::CMapFile *a2)
void  CDecoObjMgr::Store(class S4::CMapFile &) {
  
  std::strstreambuf *v2; // eax
  void *v3; // eax
  int v4; // [esp+0h] [ebp-108h] BYREF
  _DWORD v5[42]; // [esp+10h] [ebp-F8h] BYREF
  unsigned int v6; // [esp+B8h] [ebp-50h]
  size_t Size; // [esp+BCh] [ebp-4Ch]
  void *Src; // [esp+C0h] [ebp-48h]
  int v9; // [esp+C4h] [ebp-44h]
  unsigned __int8 *v10; // [esp+C8h] [ebp-40h]
  int v11; // [esp+CCh] [ebp-3Ch]
  unsigned __int8 *v12; // [esp+D0h] [ebp-38h]
  int UsedId; // [esp+D4h] [ebp-34h]
  CDecoObjMgr *v14; // [esp+D8h] [ebp-30h]
  int v15; // [esp+DCh] [ebp-2Ch] BYREF
  int v16; // [esp+E0h] [ebp-28h]
  unsigned __int8 *v17; // [esp+E4h] [ebp-24h]
  int v18; // [esp+E8h] [ebp-20h] BYREF
  unsigned __int8 *v19; // [esp+ECh] [ebp-1Ch]
  bool v20; // [esp+F2h] [ebp-16h] BYREF
  bool IsStaticInstance; // [esp+F3h] [ebp-15h]
  int i; // [esp+F4h] [ebp-14h]
  int *v23; // [esp+F8h] [ebp-10h]
  int v24; // [esp+104h] [ebp-4h]

  v23 = &v4;
  v14 = this;
  std::ostrstream::ostrstream(0, 0x40000, 0, 2, 1);
  v24 = 0;
  v6 = std::ios_base::exceptions((char *)v5 + *(_DWORD *)(v5[0] + 4));
  std::ios_base::exceptions((std::ios_base *)((char *)v5 + *(_DWORD *)(v5[0] + 4)), 6);
  LOBYTE(v24) = 1;
  v15 = 1;
  operator^<unsigned int>((struct std::ostream *)v5, &v15);
  operator^<bool>((int)v5, (int)v14 + 28);
  v18 = 0;
  UsedId = CMapObjectMgr::LastUsedId();
  v16 = UsedId;
  for ( i = 0; i <= v16; ++i )
  {
    v12 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(i);
    v17 = v12;
    if ( v12 )
    {
      v11 = IEntity::ObjType(v17);
      if ( v11 == 32 )
        ++v18;
    }
  }
  operator^<unsigned int>((struct std::ostream *)v5, &v18);
  for ( i = 0; i <= v16; ++i )
  {
    v10 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(i);
    v19 = v10;
    if ( v10 )
    {
      v9 = IEntity::ObjType(v19);
      if ( v9 == 32 )
      {
        IsStaticInstance = IDecoObject::IsStaticInstance((IDecoObject *)v19);
        v20 = IsStaticInstance;
        operator^<bool>((int)v5, (int)&v20);
        (*(void (__thiscall **)(unsigned __int8 *, _DWORD *))(*(_DWORD *)v19 + 4))(v19, v5);
      }
    }
  }
  std::ostream::put(0);
  v24 = 0;
  std::ostrstream::freeze((std::ostrstream *)v5, 1);
  v2 = std::ostrstream::rdbuf((std::ostrstream *)v5);
  Size = std::strstreambuf::pcount(v2);
  std::ostrstream::str((CDaoIndexFieldInfo *)v5);
  Src = v3;
  S4::CMapFile::SaveChunk(164, 0, Size, v3, 0);
  std::ostrstream::freeze((std::ostrstream *)v5, 0);
  std::ios_base::exceptions((std::ios_base *)((char *)v5 + *(_DWORD *)(v5[0] + 4)), v6);
  v24 = -1;
  std::ostrstream::`vbase destructor'((std::ostrstream *)v5);
}


// address=[0x1544810]
// Decompiled from void __thiscall CDecoObjMgr::Load(CDecoObjMgr *this, struct S4::CMapFile *a2)
void  CDecoObjMgr::Load(class S4::CMapFile &) {
  
  int v2; // eax
  int v3; // eax
  int v4; // [esp-18h] [ebp-158h] BYREF
  int v5; // [esp-14h] [ebp-154h]
  unsigned int v6; // [esp-10h] [ebp-150h]
  int v7; // [esp-Ch] [ebp-14Ch]
  int v8; // [esp-8h] [ebp-148h]
  _DWORD *v9; // [esp-4h] [ebp-144h]
  _BYTE v10[24]; // [esp+4h] [ebp-13Ch] BYREF
  _DWORD v11[44]; // [esp+1Ch] [ebp-124h] BYREF
  _BYTE v12[4]; // [esp+CCh] [ebp-74h] BYREF
  _BYTE v13[4]; // [esp+D0h] [ebp-70h] BYREF
  unsigned int v14; // [esp+D4h] [ebp-6Ch]
  int v15; // [esp+D8h] [ebp-68h]
  _DWORD v16[2]; // [esp+DCh] [ebp-64h] BYREF
  int v17; // [esp+E4h] [ebp-5Ch] BYREF
  int v18; // [esp+E8h] [ebp-58h] BYREF
  int v19; // [esp+ECh] [ebp-54h] BYREF
  BOOL v20; // [esp+F0h] [ebp-50h]
  unsigned int v21; // [esp+F4h] [ebp-4Ch] BYREF
  int pExceptionObject; // [esp+F8h] [ebp-48h] BYREF
  char *Str; // [esp+FCh] [ebp-44h]
  CDecoObjMgr *v24; // [esp+100h] [ebp-40h]
  unsigned int i; // [esp+104h] [ebp-3Ch]
  unsigned __int16 v26; // [esp+108h] [ebp-38h] BYREF
  _WORD v27[3]; // [esp+10Ch] [ebp-34h] BYREF
  unsigned __int8 v28; // [esp+112h] [ebp-2Eh] BYREF
  unsigned __int8 v29; // [esp+113h] [ebp-2Dh] BYREF
  _BYTE v30[28]; // [esp+114h] [ebp-2Ch] BYREF
  int v31; // [esp+13Ch] [ebp-4h]

  v24 = this;
  BBSupportTracePrintF(0, "DecoObjMgr load");
  CDecoObjMgr::Clear(v24);
  v18 = 0;
  Str = (char *)S4::CMapFile::LoadChunk(a2, 0xA4u, 0, &v18, 0);
  if ( Str )
  {
    std::string::string(v30, Str);
    v31 = 0;
    std::istringstream::istringstream(v30, 1, 1);
    LOBYTE(v31) = 1;
    v14 = std::ios_base::exceptions((char *)v11 + *(_DWORD *)(v11[0] + 4));
    std::ios_base::exceptions((std::ios_base *)((char *)v11 + *(_DWORD *)(v11[0] + 4)), 6);
    operator^<unsigned int>(v11, &v17);
    v16[1] = v17;
    if ( v17 != 1 )
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CDecoObjMgr");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    operator^<bool>(v11, (char *)v24 + 28);
    v21 = 0;
    operator^<unsigned int>(v11, &v21);
    for ( i = 0; i < v21; ++i )
    {
      v29 = 0;
      operator^<bool>(v11, &v29);
      operator^<unsigned long>(v11, v13);
      v2 = std::istream::tellg(v10);
      v15 = std::fpos<_Mbstatet>::operator __int64(v2);
      operator^<unsigned int>(v11, v12);
      operator^<unsigned short>(v11, v27);
      operator^<unsigned short>(v11, &v26);
      operator^<int>((int)v11, (int)&v19);
      operator^<unsigned char>(v11, &v28);
      operator^<int>((int)v11, (int)v16);
      v20 = ((unsigned int)&dword_F29144[220079] & v16[0]) == 0;
      v11[43] = v20;
      v11[42] = &v4;
      std::fpos<_Mbstatet>::fpos<_Mbstatet>(v15, v15 >> 31);
      std::istream::seekg(v4, v5, v6, v7, v8, v9);
      v9 = v11;
      v8 = v29;
      v7 = v27[0];
      v6 = v28;
      v5 = v26;
      v4 = Y16X16::UnpackYFast(v19);
      v3 = Y16X16::UnpackXFast(v19);
      CDecoObjMgr::AddLoadedDecoObj(v3, v4, v5, v6, v7, v8, (int)v9);
    }
    std::ios_base::exceptions((std::ios_base *)((char *)v11 + *(_DWORD *)(v11[0] + 4)), v14);
    LOBYTE(v31) = 0;
    std::istringstream::`vbase destructor'(v11);
    v31 = -1;
    std::string::~string(v30);
  }
}


// address=[0x1544b00]
// Decompiled from int __thiscall CDecoObjMgr::Create(_BYTE *this, int a2, int a3, unsigned int a4, int a5, int a6, int a7, int a8)
int  CDecoObjMgr::Create(int,int,int,int,enum CDecoObjMgr::TGROWN_STATE,int,std::istream *) {
  
  IDecoObject *DecoObjPtr; // eax
  int v9; // eax
  __int16 v10; // ax
  IDecoObject *v11; // eax
  IDecoObject *v12; // eax
  IDecoObject *v13; // eax
  int v14; // eax
  __int16 v15; // ax
  int v16; // eax
  IDecoObject *v17; // eax
  IDecoObject *v18; // eax
  __int16 v19; // ax
  IDecoObject *v20; // eax
  IDecoObject *v21; // eax
  unsigned int ObjectFirstJob; // [esp+60h] [ebp-128h]
  unsigned int v24; // [esp+68h] [ebp-120h]
  unsigned int v25; // [esp+70h] [ebp-118h]
  unsigned int v26; // [esp+7Ch] [ebp-10Ch]
  CDecoObject *v27; // [esp+8Ch] [ebp-FCh]
  CHive *v28; // [esp+9Ch] [ebp-ECh]
  CMushroom *v29; // [esp+ACh] [ebp-DCh]
  IDecoObject *v30; // [esp+B0h] [ebp-D8h]
  CMushroom *v31; // [esp+C4h] [ebp-C4h]
  CShadowHerb *v32; // [esp+D4h] [ebp-B4h]
  CPlant *v33; // [esp+E4h] [ebp-A4h]
  IDecoObject *v34; // [esp+E8h] [ebp-A0h]
  CPlant *v35; // [esp+FCh] [ebp-8Ch]
  IDecoObject *v36; // [esp+100h] [ebp-88h]
  CStone *v37; // [esp+114h] [ebp-74h]
  int v38; // [esp+118h] [ebp-70h]
  CStone *v39; // [esp+120h] [ebp-68h]
  CTree *v40; // [esp+130h] [ebp-58h]
  IDecoObject *v41; // [esp+134h] [ebp-54h]
  CTree *v42; // [esp+148h] [ebp-40h]
  unsigned int v43; // [esp+160h] [ebp-28h]
  int v44; // [esp+168h] [ebp-20h]
  int v45; // [esp+16Ch] [ebp-1Ch]
  char v46; // [esp+173h] [ebp-15h]
  int FreeSlot; // [esp+174h] [ebp-14h]

  if ( a7 )
    FreeSlot = a7;
  else
    FreeSlot = CMapObjectMgr::GetFreeSlot();
  switch ( a4 )
  {
    case 1u:
    case 2u:
    case 3u:
    case 4u:
    case 5u:
    case 6u:
    case 7u:
    case 8u:
    case 9u:
    case 0xAu:
    case 0xBu:
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
    case 0x10u:
    case 0x11u:
    case 0x12u:
    case 0x13u:
    case 0x14u:
    case 0x15u:
    case 0x16u:
      if ( a6 == 1 )
      {
        if ( !this[132 * a4 + 34] )
        {
          v26 = CGfxManager::GetObjectFirstJob((CGfxManager *)g_pGfxManager, a4) + 3;
          this[132 * a4 + 32] = CGfxManager::GetObjectFrameCount((CGfxManager *)g_pGfxManager, v26);
        }
        if ( this[132 * a4 + 34] >= this[132 * a4 + 32] )
        {
          if ( ++this[132 * a4 + 33] >= this[132 * a4 + 32] )
            this[132 * a4 + 33] = 0;
          if ( a8 )
          {
            if ( CTree::operator new(0x50u) )
              v41 = (IDecoObject *)CTree::CTree(a8);
            else
              v41 = 0;
            if ( IDecoObject::IsStaticInstance(v41) )
            {
              v9 = IEntity::ID();
              CMapObjectMgr::Destroy(g_pMapObjectMgr, v9);
              CWorldManager::SetObjectId(a2, a3, *(_DWORD *)&this[132 * a4 + 36 + 4 * (char)this[132 * a4 + 33]]);
            }
            else
            {
              v10 = IEntity::ID();
              CWorldManager::SetObjectId(a2, a3, v10);
            }
          }
          else
          {
            CWorldManager::SetObjectId(a2, a3, *(_DWORD *)&this[132 * a4 + 36 + 4 * (char)this[132 * a4 + 33]]);
          }
        }
        else
        {
          if ( a7 )
          {
            if ( !a8 && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1225, "_pInStream != 0") == 1 )
              __debugbreak();
            if ( CTree::operator new(0x50u) )
              CTree::CTree(a8);
          }
          else
          {
            v42 = (CTree *)CTree::operator new(0x50u);
            if ( v42 )
              CTree::CTree(v42, a2, a3, a4, FreeSlot, 3);
          }
          DecoObjPtr = CDecoObjMgr::GetDecoObjPtr(FreeSlot);
          if ( !IDecoObject::IsStaticInstance(DecoObjPtr)
            && BBSupportDbgReport(
                 2,
                 "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                 1228,
                 "GetDecoObjPtr( iGetId)->IsStaticInstance()") == 1 )
          {
            __debugbreak();
          }
          *(_DWORD *)&this[132 * a4 + 36 + 4 * (char)this[132 * a4 + 34]++] = FreeSlot;
        }
        CWorldManager::SetResource(a2, a3, 112, 1);
      }
      else
      {
        if ( a7 )
        {
          if ( !a8 && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1272, "_pInStream != 0") == 1 )
            __debugbreak();
          if ( CTree::operator new(0x50u) )
            CTree::CTree(a8);
        }
        else
        {
          v40 = (CTree *)CTree::operator new(0x50u);
          if ( v40 )
            CTree::CTree(v40, a2, a3, a4, FreeSlot, 0);
        }
        v11 = CDecoObjMgr::GetDecoObjPtr(FreeSlot);
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
    case 0x29u:
    case 0xFDu:
      v44 = a5 - 1;
      if ( a5 - 1 < 0 && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1397, "iIdx >= 0") == 1 )
        __debugbreak();
      if ( !this[132 * a4 + 34] )
        this[132 * a4 + 32] = 15;
      if ( *(_DWORD *)&this[132 * a4 + 36 + 4 * v44] )
      {
        if ( a8 )
        {
          if ( CStone::operator new(0x48u) )
            v36 = (IDecoObject *)CStone::CStone(a8);
          else
            v36 = 0;
          if ( IDecoObject::IsStaticInstance(v36) )
          {
            v14 = IEntity::ID();
            CMapObjectMgr::Destroy(g_pMapObjectMgr, v14);
            CWorldManager::SetObjectId(a2, a3, *(_DWORD *)&this[132 * a4 + 36 + 4 * v44]);
          }
          else
          {
            v15 = IEntity::ID();
            CWorldManager::SetObjectId(a2, a3, v15);
          }
        }
        else
        {
          CWorldManager::SetObjectId(a2, a3, *(_DWORD *)&this[132 * a4 + 36 + 4 * v44]);
        }
      }
      else
      {
        if ( a7 )
        {
          if ( !a8 && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1414, "_pInStream != 0") == 1 )
            __debugbreak();
          if ( CStone::operator new(0x48u) )
            CStone::CStone(a8);
        }
        else
        {
          v37 = (CStone *)CStone::operator new(0x48u);
          if ( v37 )
            CStone::CStone(v37, a2, a3, a4, a5, FreeSlot);
        }
        v13 = CDecoObjMgr::GetDecoObjPtr(FreeSlot);
        if ( IDecoObject::IsStaticInstance(v13) )
        {
          *(_DWORD *)&this[132 * a4 + 36 + 4 * v44] = FreeSlot;
          ++this[132 * a4 + 34];
        }
      }
      if ( a4 != 253 )
        CWorldManager::SetResource(a2, a3, 96, a5);
      break;
    case 0x7Cu:
    case 0x7Du:
    case 0x7Eu:
    case 0x7Fu:
    case 0x80u:
    case 0x81u:
    case 0x82u:
    case 0x83u:
    case 0x84u:
    case 0x85u:
    case 0x86u:
    case 0x87u:
    case 0x88u:
      v43 = a4 - 124;
      v38 = a4 - 124 + 1;
      if ( !this[5446] )
        this[5444] = 12;
      if ( *(_DWORD *)&this[4 * v43 + 5448] )
      {
        CWorldManager::SetObjectId(a2, a3, *(_DWORD *)&this[4 * v43 + 5448]);
      }
      else
      {
        if ( !a7 )
        {
          v39 = (CStone *)CStone::operator new(0x48u);
          if ( v39 )
            CStone::CStone(v39, a2, a3, 41, v38, FreeSlot);
        }
        v12 = CDecoObjMgr::GetDecoObjPtr(FreeSlot);
        if ( !IDecoObject::IsStaticInstance(v12)
          && BBSupportDbgReport(
               2,
               "MapObjects\\DecoObj\\DecoObjMgr.cpp",
               1315,
               "GetDecoObjPtr( iGetId)->IsStaticInstance()") == 1 )
        {
          __debugbreak();
        }
        *(_DWORD *)&this[4 * v43 + 5448] = FreeSlot;
        ++this[5446];
      }
      CWorldManager::SetResource(a2, a3, 96, v38);
      break;
    case 0xA2u:
    case 0xD1u:
    case 0xD2u:
    case 0xD3u:
    case 0xFFu:
      v45 = 0;
      switch ( a4 )
      {
        case 0xA2u:
          v45 = 37;
          break;
        case 0xD1u:
        case 0xD2u:
          v45 = 16;
          break;
        case 0xD3u:
          v45 = 1;
          break;
        case 0xFFu:
          v45 = 42;
          break;
        default:
          break;
      }
      if ( a6 == 1 )
      {
        if ( !this[132 * a4 + 34] )
        {
          v25 = CGfxManager::GetObjectFirstJob((CGfxManager *)g_pGfxManager, a4) + 3;
          this[132 * a4 + 32] = CGfxManager::GetObjectFrameCount((CGfxManager *)g_pGfxManager, v25);
        }
        if ( this[132 * a4 + 34] >= this[132 * a4 + 32] )
        {
          if ( ++this[132 * a4 + 33] >= this[132 * a4 + 32] )
            this[132 * a4 + 33] = 0;
          if ( !a8 )
            goto LABEL_211;
          if ( CPlant::operator new(0x50u) )
            v34 = (IDecoObject *)CPlant::CPlant(a8);
          else
            v34 = 0;
          if ( !IDecoObject::IsStaticInstance(v34) )
            goto LABEL_166;
          goto LABEL_116;
        }
        if ( a7 )
        {
          if ( !a8 && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1506, "_pInStream != 0") == 1 )
            __debugbreak();
          if ( CPlant::operator new(0x50u) )
            CPlant::CPlant(a8);
        }
        else
        {
          v35 = (CPlant *)CPlant::operator new(0x50u);
          if ( v35 )
            CPlant::CPlant(v35, a2, a3, a4, FreeSlot, v45, 3);
        }
        if ( *(_DWORD *)&this[132 * a4 + 36 + 4 * (char)this[132 * a4 + 34]]
          && BBSupportDbgReport(
               2,
               "MapObjects\\DecoObj\\DecoObjMgr.cpp",
               1509,
               "m_vInstanceId[_iDecoType].id[ m_vInstanceId[_iDecoType].count ] == 0") == 1 )
        {
          __debugbreak();
        }
        *(_DWORD *)&this[132 * a4 + 36 + 4 * (char)this[132 * a4 + 34]++] = FreeSlot;
      }
      else
      {
        if ( a8 )
        {
          if ( CPlant::operator new(0x50u) )
            CPlant::CPlant(a8);
        }
        else
        {
          if ( !FreeSlot && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1546, "iGetId != 0") == 1 )
            __debugbreak();
          v33 = (CPlant *)CPlant::operator new(0x50u);
          if ( v33 )
            CPlant::CPlant(v33, a2, a3, a4, FreeSlot, v45, 0);
        }
        v17 = CDecoObjMgr::GetDecoObjPtr(FreeSlot);
        if ( IDecoObject::IsStaticInstance(v17)
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
    case 0xD4u:
    case 0xD5u:
    case 0xD6u:
      if ( a6 == 1 )
      {
        if ( !this[132 * a4 + 34] )
        {
          v24 = CGfxManager::GetObjectFirstJob((CGfxManager *)g_pGfxManager, a4) + 3;
          this[132 * a4 + 32] = CGfxManager::GetObjectFrameCount((CGfxManager *)g_pGfxManager, v24);
        }
        if ( this[132 * a4 + 34] >= this[132 * a4 + 32] )
        {
          if ( ++this[132 * a4 + 33] >= this[132 * a4 + 32] )
            this[132 * a4 + 33] = 0;
          if ( !a8 )
            goto LABEL_211;
          if ( CMushroom::operator new(0x50u) )
            v30 = (IDecoObject *)CMushroom::CMushroom(a8);
          else
            v30 = 0;
          if ( IDecoObject::IsStaticInstance(v30) )
          {
LABEL_116:
            v16 = IEntity::ID();
            CMapObjectMgr::Destroy(g_pMapObjectMgr, v16);
            CWorldManager::SetObjectId(a2, a3, *(_DWORD *)&this[132 * a4 + 36 + 4 * (char)this[132 * a4 + 33]]);
          }
          else
          {
LABEL_166:
            v19 = IEntity::ID();
            CWorldManager::SetObjectId(a2, a3, v19);
          }
        }
        else
        {
          if ( a7 )
          {
            if ( !a8 && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1629, "_pInStream != 0") == 1 )
              __debugbreak();
            if ( CMushroom::operator new(0x50u) )
              CMushroom::CMushroom(a8);
          }
          else
          {
            v31 = (CMushroom *)CMushroom::operator new(0x50u);
            if ( v31 )
              CMushroom::CMushroom(v31, a2, a3, a4, FreeSlot, 3);
          }
          v18 = CDecoObjMgr::GetDecoObjPtr(FreeSlot);
          if ( !IDecoObject::IsStaticInstance(v18)
            && BBSupportDbgReport(
                 2,
                 "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                 1632,
                 "GetDecoObjPtr( iGetId)->IsStaticInstance()") == 1 )
          {
            __debugbreak();
          }
          *(_DWORD *)&this[132 * a4 + 36 + 4 * (char)this[132 * a4 + 34]++] = FreeSlot;
        }
      }
      else
      {
        if ( a8 )
        {
          if ( CMushroom::operator new(0x50u) )
            CMushroom::CMushroom(a8);
        }
        else
        {
          if ( !FreeSlot && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1667, "iGetId != 0") == 1 )
            __debugbreak();
          v29 = (CMushroom *)CMushroom::operator new(0x50u);
          if ( v29 )
            CMushroom::CMushroom(v29, a2, a3, a4, FreeSlot, 0);
        }
        v20 = CDecoObjMgr::GetDecoObjPtr(FreeSlot);
        if ( IDecoObject::IsStaticInstance(v20)
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
    case 0xD8u:
      if ( a7 )
      {
        if ( !a8 && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1600, "_pInStream != 0") == 1 )
          __debugbreak();
        if ( CShadowHerb::operator new(0x50u) )
          CShadowHerb::CShadowHerb(a8);
      }
      else
      {
        v32 = (CShadowHerb *)CShadowHerb::operator new(0x50u);
        if ( v32 )
          CShadowHerb::CShadowHerb(v32, a2, a3, a4, FreeSlot, 0);
      }
      break;
    case 0xD9u:
      if ( a7 )
      {
        if ( !a8 && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1688, "_pInStream != 0") == 1 )
          __debugbreak();
        if ( CHive::operator new(0x54u) )
          CHive::CHive(a8);
      }
      else
      {
        v28 = (CHive *)CHive::operator new(0x54u);
        if ( v28 )
          CHive::CHive(v28, a2, a3, a4, FreeSlot, 0);
      }
      break;
    default:
      if ( !this[132 * a4 + 34] )
      {
        ObjectFirstJob = CGfxManager::GetObjectFirstJob((CGfxManager *)g_pGfxManager, a4);
        this[132 * a4 + 32] = CGfxManager::GetObjectFrameCount((CGfxManager *)g_pGfxManager, ObjectFirstJob);
      }
      if ( this[132 * a4 + 34] >= this[132 * a4 + 32] )
      {
        if ( (char)this[132 * a4 + 33] >= (char)this[132 * a4 + 32] - 1 )
          this[132 * a4 + 33] = 0;
        if ( (char)this[132 * a4 + 32] <= 1 )
        {
LABEL_211:
          CWorldManager::SetObjectId(a2, a3, *(_DWORD *)&this[132 * a4 + 36 + 4 * (char)this[132 * a4 + 33]]);
        }
        else
        {
          v46 = this[132 * a4 + 33] + 1;
          this[132 * a4 + 33] = v46;
          CWorldManager::SetObjectId(a2, a3, *(_DWORD *)&this[132 * a4 + 36 + 4 * v46]);
        }
      }
      else
      {
        if ( a7 )
        {
          if ( !a8 && BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 1721, "_pInStream != 0") == 1 )
            __debugbreak();
          if ( CDecoObject::operator new(0x50u) )
            CDecoObject::CDecoObject(a8);
        }
        else
        {
          v27 = (CDecoObject *)CDecoObject::operator new(0x50u);
          if ( v27 )
            CDecoObject::CDecoObject(
              v27,
              a2,
              a3,
              a4,
              FreeSlot,
              (char)this[132 * a4 + 34],
              (unsigned __int8)this[8 * a4 + 38451]);
        }
        v21 = CDecoObjMgr::GetDecoObjPtr(FreeSlot);
        if ( !IDecoObject::IsStaticInstance(v21)
          && BBSupportDbgReport(
               2,
               "MapObjects\\DecoObj\\DecoObjMgr.cpp",
               1724,
               "GetDecoObjPtr( iGetId)->IsStaticInstance()") == 1 )
        {
          __debugbreak();
        }
        *(_DWORD *)&this[132 * a4 + 36 + 4 * (char)this[132 * a4 + 34]++] = FreeSlot;
      }
      break;
  }
  return FreeSlot;
}


// address=[0x1546340]
// Decompiled from char *__thiscall CDecoObjMgr::ReadObjectInfos(CDecoObjMgr *this)
void  CDecoObjMgr::ReadObjectInfos(void) {
  
  char *result; // eax
  int v2; // eax
  const char *v3; // eax
  int v4; // eax
  int v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  _DWORD v10[4]; // [esp+0h] [ebp-480h] BYREF
  _BYTE v11[28]; // [esp+10h] [ebp-470h] BYREF
  _BYTE v12[16]; // [esp+2Ch] [ebp-454h] BYREF
  _BYTE v13[16]; // [esp+3Ch] [ebp-444h] BYREF
  _BYTE v14[16]; // [esp+5Ch] [ebp-424h] BYREF
  int v15; // [esp+6Ch] [ebp-414h]
  int v16; // [esp+70h] [ebp-410h]
  int v17; // [esp+74h] [ebp-40Ch]
  int v18; // [esp+78h] [ebp-408h]
  int Name; // [esp+7Ch] [ebp-404h]
  int v20; // [esp+80h] [ebp-400h]
  int v21; // [esp+84h] [ebp-3FCh]
  int v22; // [esp+88h] [ebp-3F8h]
  int v23; // [esp+8Ch] [ebp-3F4h]
  int v24; // [esp+90h] [ebp-3F0h]
  int v25; // [esp+94h] [ebp-3ECh]
  int Root; // [esp+98h] [ebp-3E8h]
  void *C; // [esp+9Ch] [ebp-3E4h]
  int v28; // [esp+A0h] [ebp-3E0h]
  int v29; // [esp+A4h] [ebp-3DCh]
  int v30; // [esp+A8h] [ebp-3D8h]
  int v31; // [esp+ACh] [ebp-3D4h]
  struct Document *v32; // [esp+B0h] [ebp-3D0h]
  int v33; // [esp+B4h] [ebp-3CCh]
  int v34; // [esp+B8h] [ebp-3C8h]
  const char *v35; // [esp+BCh] [ebp-3C4h]
  int v36; // [esp+C0h] [ebp-3C0h]
  const char *v37; // [esp+C4h] [ebp-3BCh]
  int v38; // [esp+C8h] [ebp-3B8h]
  const char *v39; // [esp+CCh] [ebp-3B4h]
  int v40; // [esp+D0h] [ebp-3B0h]
  const char *ObjectName; // [esp+D4h] [ebp-3ACh]
  void *v42; // [esp+D8h] [ebp-3A8h]
  int v43; // [esp+DCh] [ebp-3A4h]
  int v44; // [esp+E0h] [ebp-3A0h]
  void *v45; // [esp+E4h] [ebp-39Ch]
  int v46; // [esp+E8h] [ebp-398h]
  int v47; // [esp+ECh] [ebp-394h]
  void *v48; // [esp+F0h] [ebp-390h]
  int v49; // [esp+F4h] [ebp-38Ch]
  int v50; // [esp+F8h] [ebp-388h]
  void *v51; // [esp+FCh] [ebp-384h]
  int v52; // [esp+100h] [ebp-380h]
  int v53; // [esp+104h] [ebp-37Ch]
  const char *v54; // [esp+108h] [ebp-378h]
  int v55; // [esp+10Ch] [ebp-374h]
  CConfigManager *Instance; // [esp+110h] [ebp-370h]
  int v57; // [esp+114h] [ebp-36Ch]
  int v58; // [esp+118h] [ebp-368h]
  void *v59; // [esp+11Ch] [ebp-364h]
  _BYTE v60[16]; // [esp+120h] [ebp-360h] BYREF
  int v61; // [esp+130h] [ebp-350h]
  int v62; // [esp+134h] [ebp-34Ch] BYREF
  int v63; // [esp+138h] [ebp-348h]
  int v64; // [esp+13Ch] [ebp-344h]
  CConfigManager *v65; // [esp+140h] [ebp-340h]
  const char *v66; // [esp+144h] [ebp-33Ch]
  CDecoObjMgr *v67; // [esp+148h] [ebp-338h]
  _BYTE v68[4]; // [esp+14Ch] [ebp-334h] BYREF
  BOOL v69; // [esp+150h] [ebp-330h]
  int v70; // [esp+154h] [ebp-32Ch]
  int v71; // [esp+158h] [ebp-328h]
  int v72; // [esp+15Ch] [ebp-324h]
  int v73; // [esp+160h] [ebp-320h]
  int v74; // [esp+164h] [ebp-31Ch]
  BOOL v75; // [esp+168h] [ebp-318h]
  int v76; // [esp+16Ch] [ebp-314h]
  int v77; // [esp+170h] [ebp-310h]
  int v78; // [esp+174h] [ebp-30Ch]
  char *v79; // [esp+178h] [ebp-308h]
  int v80; // [esp+17Ch] [ebp-304h]
  int v81; // [esp+180h] [ebp-300h]
  bool v82; // [esp+184h] [ebp-2FCh]
  bool v83; // [esp+185h] [ebp-2FBh]
  int v86; // [esp+188h] [ebp-2F8h]
  int v87; // [esp+18Ch] [ebp-2F4h]
  bool v88; // [esp+192h] [ebp-2EEh]
  bool v89; // [esp+193h] [ebp-2EDh]
  _BYTE *v90; // [esp+194h] [ebp-2ECh]
  int v91; // [esp+198h] [ebp-2E8h]
  _BYTE v92[28]; // [esp+3C4h] [ebp-BCh] BYREF
  _BYTE v93[28]; // [esp+3E0h] [ebp-A0h] BYREF
  _BYTE v94[28]; // [esp+3FCh] [ebp-84h] BYREF
  _BYTE v95[28]; // [esp+418h] [ebp-68h] BYREF
  _BYTE v96[28]; // [esp+434h] [ebp-4Ch] BYREF
  _BYTE v97[28]; // [esp+450h] [ebp-30h] BYREF
  _DWORD *v98; // [esp+470h] [ebp-10h]
  int v99; // [esp+47Ch] [ebp-4h]

  v98 = v10;
  v67 = this;
  v62 = 0;
  result = AdvXMLParser::Parser::OpenXMLFile(aGamedataObject, &v62);
  v79 = result;
  if ( !result )
    return result;
  v99 = 0;
  v16 = AdvXMLParser::Parser::Parser(v11);
  LOBYTE(v99) = 1;
  v32 = AdvXMLParser::Parser::Parse((AdvXMLParser::Parser *)v11, v79, v62);
  std::auto_ptr<AdvXMLParser::Document>::auto_ptr<AdvXMLParser::Document>(v32);
  LOBYTE(v99) = 2;
  v2 = std::auto_ptr<AdvXMLParser::Document>::operator->(v10[0], v10[1]);
  Root = AdvXMLParser::Document::GetRoot(v2);
  v63 = Root;
  v24 = AdvXMLParser::NodeContainer::Begin(Root, v13);
  v23 = v24;
  LOBYTE(v99) = 3;
  v15 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v24);
  LOBYTE(v99) = 5;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v13);
  v22 = AdvXMLParser::NodeContainer::End(v63, v12);
  v21 = v22;
  LOBYTE(v99) = 6;
  v18 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v22);
  LOBYTE(v99) = 8;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v12);
  while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v14) )
  {
    v20 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v60);
    v80 = v20;
    Name = AdvXMLParser::Node::GetName(v20);
    if ( std::operator==<char>(Name, "ObjectXMLVersion") )
    {
      v59 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v80 + 8))(v80, v94);
      v3 = (const char *)std::string::c_str(v59);
      v4 = j__atoi(v3);
      *((_DWORD *)v67 + 6) = v4;
      std::string::~string(v94);
    }
    else
    {
      v58 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v60);
      v57 = AdvXMLParser::Element::operator[]("id");
      v64 = v57;
      v17 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v57 + 8))(v57, v97);
      LOBYTE(v99) = 9;
      Instance = CConfigManagerPtr::GetInstance();
      v65 = Instance;
      v5 = std::string::c_str(v97);
      v55 = ((int (__thiscall *)(CConfigManager *, int))v65->GetDefineValue)(v65, v5);
      v91 = v55;
      if ( v55 < 0 )
      {
        if ( std::string::c_str(v97) )
          v66 = (const char *)std::string::c_str(v97);
        else
          v66 = (const char *)&unk_379CF3A;
        v54 = v66;
        BBSupportTracePrintF(0, "### CDecoObjMgr::ReadObjectInfos(): Unknown object \"%s\"!", v66);
      }
      if ( v91 > 0 && v91 < 291 )
      {
        v90 = (char *)v67 + 8 * v91 + 38444;
        v53 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v60);
        v52 = AdvXMLParser::Element::operator()("blocking", 0);
        v61 = v52;
        v51 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v52 + 8))(v52, v95);
        v6 = (const char *)std::string::c_str(v51);
        v74 = j__atoi(v6);
        std::string::~string(v95);
        v50 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v60);
        v49 = AdvXMLParser::Element::operator()("building", 0);
        v78 = v49;
        v48 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v49 + 8))(v49, v92);
        v7 = (const char *)std::string::c_str(v48);
        v73 = j__atoi(v7);
        std::string::~string(v92);
        v47 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v60);
        v46 = AdvXMLParser::Element::operator()("repellent", 0);
        v77 = v46;
        v45 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v46 + 8))(v46, v93);
        v8 = (const char *)std::string::c_str(v45);
        v72 = j__atoi(v8);
        std::string::~string(v93);
        v44 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v60);
        v43 = AdvXMLParser::Element::operator()("pingPong", 0);
        v76 = v43;
        v42 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v43 + 8))(v43, v96);
        v9 = (const char *)std::string::c_str(v42);
        v71 = j__atoi(v9);
        std::string::~string(v96);
        v87 = v74;
        v86 = v73;
        v81 = v72;
        v70 = v71;
        v88 = v91 == 209 || v91 == 210 || v91 == 162 || v91 == 255 || v91 == 211;
        v83 = v88;
        v75 = v88;
        v81 = v75;
        v89 = v91 == 216;
        v82 = v91 == 216;
        if ( v91 == 216 )
          v86 = 1;
        if ( v87 != v74 )
        {
          ObjectName = CS4DefineNames::GetObjectName(v91);
          v40 = BBSupportDbgReportF(
                  2,
                  "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                  2136,
                  "Invalid blocking rings: %s (%i)",
                  ObjectName,
                  v91);
          if ( v40 == 1 )
            __debugbreak();
        }
        if ( v86 != v73 )
        {
          v39 = CS4DefineNames::GetObjectName(v91);
          v38 = BBSupportDbgReportF(
                  2,
                  "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                  2137,
                  "Invalid building rings: %s (%i)",
                  v39,
                  v91);
          if ( v38 == 1 )
            __debugbreak();
        }
        if ( v81 != v72 )
        {
          v37 = CS4DefineNames::GetObjectName(v91);
          v36 = BBSupportDbgReportF(
                  2,
                  "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                  2138,
                  "Invalid repelling rings: %s (%i)",
                  v37,
                  v91);
          if ( v36 == 1 )
            __debugbreak();
        }
        if ( v70 != v71 )
        {
          v35 = CS4DefineNames::GetObjectName(v91);
          v34 = BBSupportDbgReportF(
                  2,
                  "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                  2139,
                  "Invalid ping pong: %s (%i)",
                  v35,
                  v91);
          if ( v34 == 1 )
            __debugbreak();
        }
        if ( v87 < 0 )
        {
          v33 = BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 2141, "iTotalBlockingRings >= 0");
          if ( v33 == 1 )
            __debugbreak();
        }
        if ( v86 < 0 )
        {
          v25 = BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 2142, "iAdditionalBuildingRings >= 0");
          if ( v25 == 1 )
            __debugbreak();
        }
        if ( v81 < 0 )
        {
          v31 = BBSupportDbgReport(2, "MapObjects\\DecoObj\\DecoObjMgr.cpp", 2143, "iTotalRepellingRings >= 0");
          if ( v31 == 1 )
            __debugbreak();
        }
        if ( v86 + v87 )
        {
          if ( v86 < 1 )
          {
            v30 = BBSupportDbgReport(
                    2,
                    "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                    2145,
                    "( ( iTotalBlockingRings + iAdditionalBuildingRings ) == 0 ) || ( iAdditionalBuildingRings >= 1 )");
            if ( v30 == 1 )
              __debugbreak();
          }
        }
        if ( v91 >= 1 && v91 <= 22 && (v87 != 1 || v86 != 1) )
        {
          v29 = BBSupportDbgReport(
                  2,
                  "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                  2147,
                  "( iDecoObjectType < OBJECT_TREE01A ) || ( iDecoObjectType > OBJECT_TREE11B ) || ( ( iTotalBlockingRing"
                  "s == 1 ) && ( iAdditionalBuildingRings == 1 ) )");
          if ( v29 == 1 )
            __debugbreak();
        }
        if ( v91 >= 23 && v91 <= 40 && (v87 != 1 || v86 != 1) )
        {
          v28 = BBSupportDbgReport(
                  2,
                  "MapObjects\\DecoObj\\DecoObjMgr.cpp",
                  2148,
                  "( iDecoObjectType < OBJECT_DARKTREE01A ) || ( iDecoObjectType > OBJECT_DARKTREE09B ) || ( ( iTotalBloc"
                  "kingRings == 1 ) && ( iAdditionalBuildingRings == 1 ) )");
          if ( v28 == 1 )
            __debugbreak();
        }
        if ( v87 <= 0 && v81 > 0 )
        {
          *v90 = 1;
          v90[1] = 0;
          v90[2] = 1;
          v90[3] = 1;
          v90[4] = v86 + 1;
        }
        else
        {
          *v90 = 0;
          v90[1] = v87;
          v90[2] = 0;
          v90[3] = v87;
          v90[4] = v86 + v87;
        }
        v90[5] = 0;
        v90[6] = 0;
        v69 = v70 != 0;
        v90[7] = v69;
      }
      LOBYTE(v99) = 8;
      std::string::~string(v97);
    }
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v60);
  }
  LOBYTE(v99) = 5;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v14);
  LOBYTE(v99) = 2;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v60);
  LOBYTE(v99) = 1;
  std::auto_ptr<AdvXMLParser::Document>::~auto_ptr<AdvXMLParser::Document>(v68);
  LOBYTE(v99) = 0;
  AdvXMLParser::Parser::~Parser(v11);
  v99 = -1;
  C = v79;
  return (char *)operator delete[](v79);
}


